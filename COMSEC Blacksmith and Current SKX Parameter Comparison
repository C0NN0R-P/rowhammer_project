# COMSEC Blacksmith and Current SKX Parameter Comparison

`N/A` means the option does not exist in that version.  
`Internal` means that the value exists in the code but is not exposed as a command-line option.

## Runtime and Pattern Options

| Parameter | Original COMSEC default | Current SKX default | Description |
|---|---:|---:|---|
| `--runtime-limit` | `120` seconds | `120` seconds | Maximum duration of pattern generation and hammering. |
| `--acts-per-ref` | Automatic measurement | Automatic measurement | Number of access slots estimated to fit inside one tREFI interval. |
| Slow-event threshold | `1000` cycles | `600` cycles | Threshold used when identifying slow accesses during the Blacksmith tREFI measurement. |
| JIT synchronization threshold | `1000` cycles | `1000` cycles | Threshold used by the generated hammer loop when looking for a refresh-related slow access. |
| `--hammer-acts` | N/A; internal target of `5,000,000` | Not overridden; effective target is `5,000,000` | Minimum number of hammer slots executed at each physical pattern location. A positive value overrides the target. |
| `--min-sync-acts` | N/A | `0`, disabled | Optional lower limit for synchronization activity. It is a diagnostic check and is not part of original Blacksmith. |
| `--min-pattern-refresh-intervals` | N/A | `0`, disabled | Rejects patterns shorter than the requested number of tREFI intervals. |
| `--min-pair-slots-per-refresh-window` | N/A | `10,000` | Rejects patterns where an aggressor pair receives fewer than this many access slots over a 64 ms refresh window. |
| `--probes` | `3` | `3` in Blacksmith mode; `1` in deterministic mode | Number of independently generated address mappings attempted for each temporal pattern. |
| `--dram-locations` | `3`, internal | `3` in Blacksmith mode; `1` in deterministic mode | Number of physical placements tested for each address mapping. |
| `--pattern-count` | N/A; runtime controlled | `1` in deterministic mode; `0`, runtime controlled, in Blacksmith mode | Limits the number of generated patterns. Zero means generation continues until the runtime limit. |
| `--pattern-acts` | N/A | `1024` | Size of the small deterministic verification pattern. |
| `--blacksmith-patterns` | Always uses randomized generation | Off | Enables the original randomized Blacksmith pattern generator. |
| `--double-sided-test` | N/A | On | Selects one small deterministic double-sided verification pattern. |
| `--generate-patterns` | Off | Off | Generates patterns for later use. |
| `--replay-patterns` | No file | No file | Loads and replays previously saved patterns. |
| `--load-json` | No file | No file | Loads pattern or configuration data from JSON. |
| `--fuzzing` | `true` | `true` | Enables randomized Blacksmith pattern generation. |
| `--sync` | `true` | `true` | Enables synchronization with detected refresh activity. |
| `--sweeping` | `false` | `false` | Enables the alternative sweeping execution mode. |

## Memory and Address Mapping Options

| Parameter | Original COMSEC default | Current SKX default | Description |
|---|---:|---:|---|
| `--mem-size-mb` | N/A; fixed at `1024 MiB` | `1024 MiB` | Size of the HugeTLB-backed memory allocation. |
| `--hugepage-size` | N/A; fixed at `1G` | `1G` | HugeTLB page size. The current program also supports `2M`. |
| `--dimm-id` | Required | `any` | Optional decoded-address filter. No filter is applied unless it is supplied. |
| `--rank-id` | N/A | `0` | Restricts generated addresses to the selected decoded rank. |
| `--ranks` | Required | Unknown or unchecked | Declared number of ranks. The current SKX program does not require it. |
| `--allow-nonzero-pattern-cols` | N/A | `false` | Allows generated hammer addresses to use columns other than column zero. |
| `--victim-row-window` | N/A | `1` in deterministic mode; `5` in Blacksmith mode | Number of neighbouring rows required on each side of a target row. |
| `--allow-partial-row-coverage` | N/A | `false` | Allows hammering when only part of the required victim-row window can be mapped. |
| `--row-coverage-attempts` | N/A | `32` | Number of pattern-placement attempts made while looking for a complete row window. |
| `--max-per-bank` | N/A | `0`, automatic sparse limit | Limits how many sampled addresses are retained for each compact bank key. |
| `--fast-pool` | N/A | `false` | Enables the faster and less exhaustive address-pool construction path. |
| `--validate-patterns` | N/A | `false` | Validates all generated pattern addresses before hammering. |
| `--require-bank-timing` | N/A | `false` | Requires the independent same-bank row-conflict timing check to pass. |
| `--pattern-access-details` | N/A | `false` | Prints the physical rows and activation-slot distribution of each pattern. |
| Normal reverse-map samples | N/A | `4` per observed bank key | Tests a sample of physical-to-DRAM-to-physical round trips. |
| Strict reverse-map samples | N/A | `16` general and `16` column-zero samples per bank key | Performs additional reverse-mapping checks in validation and diagnostic modes. |

## Diagnostic and Scan Options

| Parameter | Original COMSEC default | Current SKX default | Description |
|---|---:|---:|---|
| `--measure-acts-per-ref-only` | N/A | `false` | Measures the tREFI-related values, prints the results and exits. |
| `--hammer-diagnostic` | N/A | `false` | Runs one readable pattern, records timing, addresses and EDAC information, then exits. |
| `--decode-pa` | N/A | Not set | Decodes one supplied physical address into its DRAM geometry. |
| `--print-skx-bit-layout` | N/A | `false` | Prints which physical-address bits contribute to each DRAM field. |
| `--mce-log-interval` | N/A | `0`, disabled | Periodically adds new EDAC or MCE kernel messages to the output log. |
| `--scan-bank-rows-only` | N/A | `false` | Scans the requested row range in one selected bank key and then exits. |
| `--scan-bank-key-id` | N/A | `-1`, automatic | Chooses the compact bank key used by the single-bank scan. |
| `--scan-bank-row-count` | N/A | `8192` | Number of row numbers checked by the single-bank scan. |
| `--scan-bank-row-start` | N/A | Automatic | First absolute DRAM row checked by the scan. |
| `--scan-bank-row-end` | N/A | Derived from the start and count | Last absolute DRAM row checked by the scan. |
| `--scan-bank-all-page-cols` | N/A | `false` | Checks all page-column candidates rather than only column zero. |
| `--scan-bank-print-candidates` | N/A | `false` | Prints every reverse-mapping candidate, including candidates that decode to another bank key. |
| `--scan-all-banks-only` | N/A | `false` | Scans every observed bank key instead of running Blacksmith. |
| `--scan-all-bank-window-rows` | N/A | `8192` | Size of each row range used in the all-bank summaries. |
| `--scan-all-bank-print-addresses` | N/A | `false` | Prints each successfully resolved column-zero VA and PA. |
| `--scan-all-bank-reverse-check-addresses` | N/A | `false` | Decodes every printed address again and confirms that it matches the requested geometry. |
| `--allow-partial-bank-row-scan` | N/A | `false` | Allows a scan to finish successfully when some requested rows cannot be mapped. |

## Internal Pattern-Generation Parameters

| Parameter | Original COMSEC default | Current SKX default | Description |
|---|---:|---:|---|
| Pattern length | Randomly `1`, `2`, `4`, `8` or `16` tREFI | Same | Duration of one temporal pattern period. |
| Slots per pattern period | `acts_per_tREFI × pattern length` | Same | Exact number of access positions in one repetition of the pattern. |
| Number of aggressors | Randomly `8–96` | Same | Number of aggressor entries available to the temporal generator. |
| Sidedness | Randomly `1` or `2` | Same | Chooses one-sided or two-sided pattern structures. |
| Sidedness weighting | `20%` one-sided and `80%` two-sided | Same | Makes two-sided patterns more likely. |
| Amplitude | `1` to `acts_per_tREFI / 2` | Same | Controls how frequently an aggressor occurs within one period. |
| Base period | Random even divisor, minimum `4` | Same | Small repeating unit used to construct the complete temporal pattern. |
| Aggressor intra-distance | `2` rows | Same | Separation between rows inside an aggressor pair. |
| Aggressor inter-distance | Randomly `1–24` rows | Same | Separation between different aggressor groups. |
| Sequential aggressors | Randomly enabled or disabled | Same | Chooses whether aggressor row numbers are allocated sequentially. |
| Synchronize every tREFI | `false` | `false` | Synchronization occurs after the complete pattern period rather than after every individual tREFI. |
| Synchronization aggressors | `2` | `2` | Number of addresses used by the refresh synchronization detector. |
| Start delay | Randomly `10–128` tREFI | Same | Random delay before hammering starts, approximately `78–998 microseconds`. |
| Flush policy | Earliest possible | Same | Flushes an address as soon as the generated schedule permits. |
| Fence policy | Latest possible | Same | Delays memory fences until they are required by the schedule. |
| Maximum relative row number | `8192` | `8192` | Size of the row-number range used by pattern generation. The current mapper places it inside a validated absolute row window. |

## Legacy Compile-Time Constants

| Constant | Original COMSEC value | Current SKX value | Description |
|---|---:|---:|---|
| `HAMMER_ROUNDS` | `1,000,000` | `1,000,000` | Used by TraditionalHammerer experiments. It is not the randomized Blacksmith JIT hammer target. |
| `DRAMA_ROUNDS` | `1000` | `1000` | Number of measurements averaged by the legacy DRAM timing analyser. |
| `CACHELINE_SIZE` | `64` bytes | `64` bytes | Assumed CPU cache-line size. |
| `THRESH` | `495` cycles | `495` cycles | Legacy row-conflict timing threshold. |
| `MAX_ROWS` | `30` | `30` | Legacy TraditionalHammerer row limit. |
| `NUM_TARGETS` | `10` | `10` | Legacy analyser target count. It is not the number of SKX bank keys. |
| `NUM_BANKS` | `16` | `16` | Legacy bank-count constant. The current SKX mapper uses full decoded bank keys instead. |
| `MEM_SIZE` macro | `1 GiB` | `16 MiB`, legacy only | The current normal allocation uses `--mem-size-mb`, whose default is `1024 MiB`, rather than this macro. |
