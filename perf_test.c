#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/syscall.h>
#include <linux/perf_event.h>
#include <fcntl.h>
#include <errno.h>

#define LOG_FILE "perf_results.csv"

// Wrapper for perf_event_open syscall
static int perf_event_open(struct perf_event_attr *hw_event, pid_t pid, int cpu, int group_fd, unsigned long flags) {
    return syscall(__NR_perf_event_open, hw_event, pid, cpu, group_fd, flags);
}

// Function to determine event type (raw or hardware)
int get_perf_event_type(const char *event) {
    if (strncmp(event, "cycles", 6) == 0) return PERF_TYPE_HARDWARE;
    if (strncmp(event, "instructions", 12) == 0) return PERF_TYPE_HARDWARE;
    return PERF_TYPE_RAW;
}

// Function to parse raw event codes (e.g., "r10b0" -> 0x10b0)
long parse_raw_event(const char *event) {
    return strtol(event + 1, NULL, 16);
}

// Function to run perf test
void run_perf_test(const char *method, int vm_threads, int memory_gb, int duration, char **events, int event_count, FILE *log_file) {
    struct perf_event_attr pe[event_count];
    int fds[event_count];
    long long event_counts[event_count];

    for (int i = 0; i < event_count; i++) {
        memset(&pe[i], 0, sizeof(struct perf_event_attr));
        pe[i].size = sizeof(struct perf_event_attr);
        pe[i].disabled = 1;
        pe[i].exclude_kernel = 0;
        pe[i].exclude_hv = 1;
        pe[i].type = get_perf_event_type(events[i]);

        if (pe[i].type == PERF_TYPE_RAW) {
            pe[i].config = parse_raw_event(events[i]);
        } else {
            if (strncmp(events[i], "cycles", 6) == 0) pe[i].config = PERF_COUNT_HW_CPU_CYCLES;
            if (strncmp(events[i], "instructions", 12) == 0) pe[i].config = PERF_COUNT_HW_INSTRUCTIONS;
        }

        fds[i] = perf_event_open(&pe[i], -1, 0, -1, 0);  // Monitor all CPUs
        if (fds[i] == -1) {
            perror("Error opening perf event");
            exit(EXIT_FAILURE);
        }
    }

    // Reset and enable counters
    for (int i = 0; i < event_count; i++) {
        ioctl(fds[i], PERF_EVENT_IOC_RESET, 0);
        ioctl(fds[i], PERF_EVENT_IOC_ENABLE, 0);
    }

    // Run workload (stress-ng)
    char command[256];
    snprintf(command, sizeof(command), "stress-ng --vm %d --vm-bytes %dG --vm-method %s --timeout %d", vm_threads, memory_gb, method, duration);

    int ret = system(command);
    if (ret == -1) {
        perror("Error executing system command");
        exit(EXIT_FAILURE);
    } else if (WIFEXITED(ret) && WEXITSTATUS(ret) != 0) {
        fprintf(stderr, "Command failed with exit status %d\n", WEXITSTATUS(ret));
        exit(EXIT_FAILURE);
    }

    // Disable counters and read values
    for (int i = 0; i < event_count; i++) {
        ioctl(fds[i], PERF_EVENT_IOC_DISABLE, 0);
        if (read(fds[i], &event_counts[i], sizeof(long long)) != sizeof(long long)) {
            perror("Error reading event counter");
            exit(EXIT_FAILURE);
        }
        close(fds[i]);
    }

    // Print results to screen
    printf("\nTest Completed: %s (%d threads, %dGB, %ds)\n", method, vm_threads, memory_gb, duration);
    printf("Event Counts:\n");
    for (int i = 0; i < event_count; i++) {
        printf("  %-16s : %lld\n", events[i], event_counts[i]);
    }
    printf("-------------------------------------------------\n");

    // Log results in CSV format
    fprintf(log_file, "%s,%d,%d,%d", method, vm_threads, memory_gb, duration);
    for (int i = 0; i < event_count; i++) {
        fprintf(log_file, ",%lld", event_counts[i]);
    }
    fprintf(log_file, "\n");
    fflush(log_file);
}

// Function to parse command-line arguments
void parse_args(int argc, char *argv[], int *vm_threads, int *memory_gb, int *duration, char ***vm_methods, int *vm_method_count, char ***events, int *event_count) {
    int opt;
    *event_count = 0;
    *vm_method_count = 0;
    *events = NULL;
    *vm_methods = NULL;

    while ((opt = getopt(argc, argv, "v:m:d:e:w:")) != -1) {
        switch (opt) {
            case 'v':
                *vm_threads = atoi(optarg);
                break;
            case 'm':
                *memory_gb = atoi(optarg);
                break;
            case 'd':
                *duration = atoi(optarg);
                break;
            case 'e':
                *events = realloc(*events, (*event_count + 1) * sizeof(char *));
                (*events)[*event_count] = strdup(optarg);
                (*event_count)++;
                break;
            case 'w':
                *vm_methods = realloc(*vm_methods, (*vm_method_count + 1) * sizeof(char *));
                (*vm_methods)[*vm_method_count] = strdup(optarg);
                (*vm_method_count)++;
                break;
            default:
                fprintf(stderr, "Usage: %s [-v VM_THREADS] [-m MEMORY_GB] [-d DURATION] [-w VM_METHOD] [-e EVENT_CODE] ...\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    int vm_threads = 16;
    int memory_gb = 8;
    int duration = 10;
    char **events;
    int event_count = 0;
    char **vm_methods;
    int vm_method_count = 0;

    parse_args(argc, argv, &vm_threads, &memory_gb, &duration, &vm_methods, &vm_method_count, &events, &event_count);

    if (event_count == 0) {
        fprintf(stderr, "Error: At least one event (-e EVENT_CODE) must be specified.\n");
        return EXIT_FAILURE;
    }
    if (vm_method_count == 0) {
        fprintf(stderr, "Error: At least one memory method (-w VM_METHOD) must be specified.\n");
        return EXIT_FAILURE;
    }

    FILE *log_file = fopen(LOG_FILE, "w");
    if (!log_file) {
        perror("Error opening log file");
        return EXIT_FAILURE;
    }

    fprintf(log_file, "Method,VM_Threads,Memory_GB,Duration");
    for (int i = 0; i < event_count; i++) {
        fprintf(log_file, ",%s", events[i]);
    }
    fprintf(log_file, "\n");

    for (int i = 0; i < vm_method_count; i++) {
        run_perf_test(vm_methods[i], vm_threads, memory_gb, duration, events, event_count, log_file);
    }

    fclose(log_file);
    printf("\nTests completed! Results saved in %s\n", LOG_FILE);

    return 0;
}
