## DRAM and Memory Latency Metrics

### DRAM-Specific Metrics:

1. **Metric Name**: `numa_reads_addressed_to_local_dram`
   - **Description**: Memory read misses from the last level cache (LLC) addressed to local DRAM as a percentage of total memory read accesses.
   - **Unit**: Percentage.
   - **Category**: NUMA.

2. **Metric Name**: `numa_reads_addressed_to_remote_dram`
   - **Description**: Memory reads missing the LLC addressed to remote DRAM as a percentage of total memory read accesses.
   - **Unit**: Percentage.
   - **Category**: NUMA.

3. **Metric Name**: `llc_demand_data_read_miss_to_dram_latency`
   - **Description**: Average latency of a last level cache (LLC) demand data read miss addressed to DRAM.
   - **Unit**: Nanoseconds.
   - **Category**: Latency.
---

### Memory Latency Metrics:

4. **Metric Name**: `llc_demand_data_read_miss_latency`
   - **Description**: Average latency of an LLC demand data read miss in nanoseconds.
   - **Unit**: Nanoseconds.
   - **Category**: Latency.

5. **Metric Name**: `llc_demand_data_read_miss_latency_for_local_requests`
   - **Description**: Average latency of LLC demand data read misses addressed to local memory in nanoseconds.
   - **Unit**: Nanoseconds.
   - **Category**: Latency.

6. **Metric Name**: `llc_demand_data_read_miss_latency_for_remote_requests`
   - **Description**: Average latency of LLC demand data read misses addressed to remote memory in nanoseconds.
   - **Unit**: Nanoseconds.
   - **Category**: Latency.

7. **Metric Name**: `llc_demand_data_read_miss_to_pmem_latency`
   - **Description**: Average latency of LLC demand data read misses addressed to persistent memory (PMEM).
   - **Unit**: Nanoseconds.
   - **Category**: Latency.

