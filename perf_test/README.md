# Performance Event Profiler (`perf_test`)

##  Overview
`perf_test` is a **Linux performance profiling tool** that uses `perf_event_open` to measure hardware performance counters while executing memory-intensive workloads using `stress-ng`. This has been tested on a Linux machine running Intel's Cascade Lake processor.

###  Features:
- **Collects performance events (e.g., cycles, instructions, custom raw events)**
- **Supports multiple memory access patterns (`read64`, `write64`, etc.)**
- **Runs different stress-test methods sequentially**
- **Logs results to both screen and a CSV file (`perf_results.csv`)**
- **Automatically installs `stress-ng` if missing**

---

## **Installation & Compilation**
### **1. Clone & Enter the Directory**
```sh
git clone https://github.com/C0NN0R-P/rowhammer-project.git
cd rowhammer_project
cd perf_test
```
### **2. Compile with `make`**
```sh
make
```
 **What this does:**
- **Compiles `perf_test.c`** into an executable (`perf_test`).
- **Checks if `stress-ng` is installed** and installs it if missing.

### **3. Run the Program**
```sh
sudo ./perf_test -e r10b0 -e cycles -e instructions -w read64 -w write64
```
 **Explanation:**
- `-e r10b0` → Collect raw event `r10b0`
- `-e cycles` → Collect CPU cycle counts
- `-e instructions` → Collect executed instructions
- `-w read64` → Perform read memory operations
- `-w write64` → Perform write memory operations

---

## **Flags & Definitions**
This program supports several flags that allow customization of profiling settings.

| Flag | Description | Default | Example Usage |
|------|------------|---------|--------------|
| `-e EVENT` | **Specifies a performance event to monitor.** Multiple `-e` flags can be used. Supported events include `cycles`, `instructions`, `cache-misses`, or raw events like `r10b0`. | **Required** | `-e r10b0 -e cycles -e instructions` |
| `-w METHOD` | **Specifies the memory operation method for `stress-ng`** (e.g., `read64`, `write64`, `incdec`, `swap`). Multiple `-w` flags can be used to run different memory stress patterns sequentially. | **Required** | `-w read64 -w write64 -w swap` |
| `-v THREADS` | **Sets the number of virtual memory worker threads (`--vm`).** Increasing threads increases parallel stress-testing. | `16` | `-v 32` |
| `-m MEMORY_GB` | **Sets the memory size per thread (`--vm-bytes`).** Each thread will allocate and work with this amount of memory. | `8GB` | `-m 16` |
| `-d SECONDS` | **Specifies the duration for which each test runs (`--timeout`).** Longer durations allow for more event collection. | `10s` | `-d 20` |

---

## **Interpreting the Results**
After execution, results will be stored in `perf_results.csv` and displayed on the screen.

### **Example CSV Output (`perf_results.csv`)**
```
Method,VM_Threads,Memory_GB,Duration,r10b0,cycles,instructions
read64,16,8,10,5326876,10214567,23512789
write64,16,8,10,3905174,8942821,19876532
```

### **Example Terminal Output**
```
Test Completed: read64 (16 threads, 8GB, 10s)
Event Counts:
  r10b0            : 5,326,876
  cycles           : 10,214,567
  instructions     : 23,512,789
-------------------------------------------------

Test Completed: write64 (16 threads, 8GB, 10s)
Event Counts:
  r10b0            : 3,905,174
  cycles           : 8,942,821
  instructions     : 19,876,532
-------------------------------------------------
```

---

## **Additional Commands**
### ** Get Available `stress-ng` Memory Methods**
```sh
stress-ng --vm-method help
```
Lists all available **memory access patterns**.
