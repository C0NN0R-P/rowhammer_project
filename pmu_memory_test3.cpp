#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/perf_event.h>
#include <asm/unistd.h>
#include <emmintrin.h>  // For _mm_lfence()
#include <stdint.h>

// Setup the performance counter
int setupMeasure(int cpuid)
{
    static int fd = -1;  // Reuse file descriptor

    struct perf_event_attr pe;
    memset(&pe, 0, sizeof(struct perf_event_attr));

    // Use a known valid event type (try instructions instead of cache misses)
    pe.type = 0xd;
    pe.size = sizeof(struct perf_event_attr);
    pe.config = 0x10b0;  // Change to track executed instructions

    pe.read_format = PERF_FORMAT_TOTAL_TIME_ENABLED | PERF_FORMAT_TOTAL_TIME_RUNNING;
    pe.disabled = 1;
    pe.exclude_kernel = 0;
    pe.exclude_hv = 0;

    if (fd == -1) {
        fd = syscall(__NR_perf_event_open, &pe, -1, cpuid, -1, 0);
        
        std::cout << "DEBUG: perf_event_open() returned fd = " << fd << std::endl;

        if (fd == -1) {
            std::cerr << "ERROR: perf_event_open failed: " << strerror(errno) 
                      << " (errno: " << errno << ")" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    return fd;
}

// Start the performance counter
void startMeasure(int fd, long long &initialCount)
{
    if (fd == -1) {
        std::cerr << "ERROR: Invalid file descriptor (fd = -1), skipping measurement" << std::endl;
        return;
    }

    _mm_mfence();  // Ensure memory operations are completed
    ioctl(fd, PERF_EVENT_IOC_DISABLE, 0);  // Disable counter before reading

    long long tempCount = 0;
    ssize_t bytesRead = read(fd, &tempCount, sizeof(long long));

    std::cout << "DEBUG: read() returned " << bytesRead << " bytes, tempCount = " << tempCount << std::endl;

    if (bytesRead <= 0) {
        std::cerr << "ERROR: read() failed to retrieve counter value! Ensure the event type is correct." << std::endl;
    }

    initialCount = tempCount;
    std::cout << "DEBUG: Stored Initial Count = " << initialCount << std::endl;

    ioctl(fd, PERF_EVENT_IOC_ENABLE, 0);
}

// Stop the performance counter and get the result
long long stopMeasure(int fd, long long initialCount)
{
    if (fd == -1) {
        std::cerr << "ERROR: Invalid file descriptor (fd = -1), skipping measurement" << std::endl;
        return -1;
    }

    long long finalCount;
    _mm_mfence();
    ioctl(fd, PERF_EVENT_IOC_DISABLE, 0);

    ssize_t bytesRead = read(fd, &finalCount, sizeof(long long));

    if (bytesRead <= 0) {
        std::cerr << "ERROR: read() failed to retrieve final counter value!" << std::endl;
        return -1;
    }

    long long eventDifference = finalCount - initialCount;

    if (eventDifference < 0) {
        std::cerr << "WARNING: Negative event difference detected! Resetting to 0." << std::endl;
        eventDifference = 0;
    }

    std::cout << "DEBUG: Final Count = " << finalCount 
              << ", Event Difference = " << eventDifference << std::endl;

    return eventDifference;
}

// Perform memory accesses
void access(void* addr, int numAccess)
{
    volatile uint64_t *p = (volatile uint64_t *) addr;

    for (int i = 0; i < numAccess; i++)
    {
        *p;  // Perform actual memory access (load)
        _mm_lfence();
    }
}

int main()
{
    int cpuid = 0;  // CPU core to measure
    void* adr = malloc(64);  // Allocate memory for access()
    
    if (!adr) {
        std::cerr << "Memory allocation failed!" << std::endl;
        return -1;
    }

    long long initialCount = 0;
    auto fd = setupMeasure(cpuid);

    // TEST: Run once WITHOUT memory accesses
    std::cout << "\nTEST 0 - No memory accesses" << std::endl;
    startMeasure(fd, initialCount);
    long long count = stopMeasure(fd, initialCount);
    std::cout << "Final event count without memory accesses → " << count << " recorded\n";

    // Run tests with increasing memory accesses
    for (int testNum = 1; testNum <= 5; testNum++) {
        int numAccess = testNum * 1000;  // Increase memory accesses each time
        std::cout << "\nTEST " << testNum << " - numAccess = " << numAccess << std::endl;

        startMeasure(fd, initialCount);

        access(adr, numAccess);  // Perform the memory accesses

        long long count = stopMeasure(fd, initialCount);

        std::cout << "Final event count for numAccess = " << numAccess 
                  << " → " << count << " accesses recorded\n";
    }

    free(adr);  // Free allocated memory
    return 0;
}
