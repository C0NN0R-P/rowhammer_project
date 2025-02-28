#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/perf_event.h>
#include <asm/unistd.h>
#include <errno.h>

#define EVENT_CODE 0xb0
#define NUM_UMASKS 20
#define CPU_TO_MEASURE 0
#define MEASURE_TIME 5

// Function to open a perf event
static int open_perf_event(uint64_t config, int cpu) {
	struct perf_event_attr pe;
	memset(&pe, 0, sizeof(struct perf_event_attr));
	
	pe.type = 0xd;
	pe.size = sizeof(struct perf_event_attr);
	pe.config = config;
	pe.disabled = 1;
	pe.exclude_kernel = 0;
	pe.exclude_hv = 0;
	pe.read_format = PERF_FORMAT_TOTAL_TIME_ENABLED | PERF_FORMAT_TOTAL_TIME_RUNNING;
	
	int fd = syscall(__NR_perf_event_open, &pe, -1, cpu, -1, 0);
	if (fd == -1) {
		fprintf(stderr, "Error opening perf event for config 0x%llx: %s\n", (long long)config, strerr(errno));
	}
	return fd;
}

// Function to read perf counter values
static int read_counter(int fd, uint64_t *values) {
	if (read(fd, values, sizeof(uint64_t) * 3) != sizeof(uint64_t) * 3) {
		perror("Error reading perf counter");
		return -1;
	}
	return 0;
}

int main() {
	uint64_t umasks[NUM_UMASKS] = {
		0x10, 0x11, 0x12, 0x13, 0x14, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f
	};
	
	int fds[NUM_UMASKS];
	uint64_t values[NUM_UMASKS][3]; // [raw count, time enabled, time running]
	
	// Open perf events for each umask
	for (int i = 0; i < NUM_UMASKS; i++) {
		uint64_t config = (umasks[i] << 8) | EVENT_CODE;
		
		fds[i] = open_perf_event(config, CPU_TO_MEASURE);
		if (fds[i] == -1) {
			fprintf(stderr, "Failed to open perf event for umask 0x%llx\n", (long long)umasks[i]);
			return EXIT_FAILURE;
		}
	}
	
	// Enable all counters
	for (int i = 0; i < NUM_UMASKS; i++) {
		ioctl(fds[i], PERF_EVENT_IOC_RESET, 0);
		ioctl(fds[i], PERF_EVENT_IOC_ENABLE, 0);
	}
	
	// Sleep for measurement period
	sleep(MEASURE_TIME);
	
	// Disable all counters
	for (int i = 0; i < NUM_UMASKS; i++) {
		ioctl(fds[i], PERF_EVENT_IOC_DISABLE, 0);
	}
	
	// Read and print counter results
	for (int i = 0; i < NUM_UMASKS; i++) {
		if (read_counter(fds[i], values[i]) == -1) {
			fprintf(stderr, "Error reading counter for umask 0x%llx\n", (long long)umasks[i]);
			continue;
		}
		
		uint64_t raw_count = values[i][0];
		uint64_t time_enabled = values[i][1];
		uint64_t time_running = values[i][2];
		
		printf("\nUmasks=0x%llx => config=0x%llx", (long long)umasks[i], (long long)((umasks[i] << 8) | EVENT_CODE));
		printf("  Raw Count: %llu\n", (long long unsigned)raw_count);
		printf("  Time Enabled (ns): %llu\n", (long long unsigned)time_enabled);
		printf("  Time Running (ns): %llu\n", (long long unsigned)time_running);
	}
	
	// Close all file descriptors
	for (int i = 0; i < NUM_UMASKS; i++) {
		close(fds[i]);
	}
	
	return EXIT_SUCCESS;
}
