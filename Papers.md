<script src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/datatables/1.10.21/js/jquery.dataTables.min.js"></script>
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/datatables/1.10.21/css/jquery.dataTables.min.css">

<table id="sortableTable" class="display">
    <thead>
        <tr>
<th>Title</th><th>Authors</th><th>Year</th><th>Summary</th><th>Tags</th>
        </tr>
    </thead>
    <tbody>
<tr><td>Panopticon: A Complete In-DRAM Rowhammer Mitigation</td><td>Tanj Bennett, Stefan Saroiu, Alec Wolman, and Lucian Cojocar</td><td>2020</td><td>Panopticon proposes a novel in-DRAM approach to mitigate Rowhammer attacks without requiring hardware modifications beyond DRAM. It introduces a new DRAM mat design to track row activations and leverages ALERTn signals to refresh potential victim rows. This method overcomes cost and performance barriers of previous mitigation schemes, providing an efficient and practical solution for DDR4 systems.</td><td>
- Rowhammer
- DRAM
- Security
- Mitigation
- Memory Protection</td></tr>
<tr><td>ANVIL: Software-Based Protection Against Next-Generation Rowhammer Attacks</td><td>Zelalem Birhanu Aweke, Salessawi Ferede Yitbarek, Rui Qiao, Reetuparna Das, Matthew Hicks, Yossi Oren, and Todd Austin</td><td>2016</td><td>ANVIL is a software-based defense against advanced Rowhammer attacks. It detects aggressive DRAM row accesses using hardware performance counters and selectively refreshes victim rows. The system effectively mitigates all known Rowhammer exploits with minimal performance impact, demonstrating a robust, cost-effective solution for securing existing and future DRAM systems.</td><td>
- Rowhammer
- DRAM
- Security
- Software Defense
- Memory Protection</td></tr>
<tr><td>Towards Application-Specific Address Mapping for Emerging Memory Devices</td><td>Shashank Adavally, and Krishna Kavi</td><td>2020</td><td>This paper explores application-specific address mapping techniques to optimize performance in high-bandwidth memory (HBM) systems. By analyzing address bit toggling and entropy, the authors propose a probabilistic entropy-based mapping strategy, which improves parallelism and reduces conflicts, leading to up to 25% performance gains over traditional mapping approaches.</td><td>
- HBM
- Address Mapping
- DRAM
- Memory Optimization
- Parallelism</td></tr>
<tr><td>CAn’t Touch This: Practical and Generic Software-only Defenses Against Rowhammer Attacks</td><td>Ferdinand Brasser, Lucas Davi, David Gens, Christopher Liebchen, and Ahmad-Reza Sadeghi</td><td>2016</td><td>This paper presents two software-based defenses against Rowhammer attacks: B-CATT, which blacklists vulnerable memory regions at boot, and G-CATT, which isolates memory used by different system entities. The authors demonstrate that these techniques can effectively prevent real-world Rowhammer exploits without requiring hardware changes.</td><td>
- Rowhammer
- DRAM
- Memory Protection
- Software Defense
- Security</td></tr>
<tr><td>SCONE: Secure Linux Containers with Intel SGX</td><td>Sergei Arnautov, Bohdan Trach, Franz Gregor, Thomas Knauth, Andre Martin, Christian Priebe, Joshua Lind, Divya Muthukumaran, Dan O’Keeffe, Mark L Stillwell, David Goltzsche, David Eyers, Rüdiger Kapitza, Peter Pietzuch, and Christof Fetzer</td><td>2016</td><td>SCONE is a secure container runtime leveraging Intel SGX to protect containerized applications from OS and hypervisor attacks. It introduces a secure C standard library to ensure encrypted I/O and supports asynchronous system calls to minimize performance overhead. SCONE provides confidentiality and integrity guarantees with minimal changes to existing applications.</td><td>
- Intel SGX
- Secure Containers
- Virtualization
- Security
- Confidential Computing</td></tr>
<tr><td>Intel TDX Demystified: A Top-Down Approach</td><td>Pau-Chen Cheng, Wojciech Ozga, Enriquillo Valdez, Salman Ahmed, Zhongshu Gu, Hani Jamjoom, Hubertus Franke, and James Bottomley</td><td>2024</td><td>This paper provides a comprehensive analysis of Intel Trust Domain Extensions (TDX), a security feature in Intel's 4th Generation Xeon Scalable Processors. It describes TDX's capabilities in enabling confidential computing by isolating virtual machines with encrypted memory and integrity protection. The authors take a top-down approach to explain the architecture and its applications in cloud security.</td><td>
- Intel TDX
- Confidential Computing
- Secure Virtualization
- Hardware Security</td></tr>
<tr><td>HammerScope: Observing DRAM Power Consumption Using Rowhammer</td><td>Yaakov Cohen, Kevin Sam Tharayil, Arie Haenel, Daniel Genkin, Angelos D. Keromytis, Yossi Oren, and Yuval Yarom</td><td>2022</td><td>HammerScope explores the correlation between Rowhammer-induced bit flips and memory power consumption. The paper introduces a novel attack that uses Rowhammer to measure DRAM power fluctuations, enabling side-channel leaks such as breaking KASLR, performing Spectre-based covert channels, and fingerprinting websites.</td><td>
- Rowhammer
- DRAM Power Analysis
- Side-Channel Attacks
- Spectre
- Memory Security</td></tr>
<tr><td>Exploiting Correcting Codes: On the Effectiveness of ECC Memory Against Rowhammer Attacks</td><td>Lucian Cojocar, Kaveh Razavi, Cristiano Giuffrida, and Herbert Bos</td><td>2019</td><td>This paper investigates the effectiveness of ECC (Error-Correcting Code) memory against Rowhammer attacks. The authors introduce ECCploit, an attack that exploits vulnerabilities in ECC mechanisms, demonstrating that ECC memory is not a complete defense against Rowhammer. The findings challenge the assumption that ECC-based protections are sufficient.</td><td>
- Rowhammer
- ECC Memory
- Memory Protection
- DRAM Security</td></tr>
<tr><td>Are We Susceptible to Rowhammer? An End-to-End Methodology for Cloud Providers</td><td>Lucian Cojocar, Jeremie Kim, Minesh Patel, Lillian Tsai, Stefan Saroiu, Alec Wolman, and Onur Mutlu</td><td>2020</td><td>This paper presents a systematic methodology for cloud providers to evaluate the susceptibility of their DRAM modules to Rowhammer attacks. It introduces a new instruction sequence for efficient hammering and reverse engineers DDR4 row adjacency mappings. The study finds that prior work underestimated DRAM vulnerability in cloud settings.</td><td>
- Rowhammer
- Cloud Security
- DRAM Vulnerability
- Memory Testing</td></tr>
<tr><td>mFIT: A Bump-in-the-Wire Tool for Plug-and-Play Analysis of Rowhammer Susceptibility Factors</td><td>Lucian Cojocar, Kevin Loughlin, Stefan Saroiu, Baris Kasikci, and Alec Wolman</td><td>2021</td><td>mFIT is a low-cost tool designed to analyze Rowhammer susceptibility in DDR4 DRAM modules. It operates as a bump-in-the-wire device between a memory controller and DRAM, allowing for precise reverse engineering of Rowhammer vulnerability factors. The tool provides new insights into DRAM row addressing and memory scrambling.</td><td>
- Rowhammer
- Memory Testing
- DRAM Analysis
- Security Research</td></tr>
<tr><td>SMASH: Synchronized Many-sided Rowhammer Attacks from JavaScript</td><td>Finn de Ridder, Pietro Frigo, Emanuele Vannacci, Herbert Bos, Cristiano Giuffrida, and Kaveh Razavi</td><td>2021</td><td>SMASH introduces a novel JavaScript-based Rowhammer attack that bypasses modern DDR4 mitigations like Target Row Refresh (TRR). The attack enables Rowhammer exploits directly from the browser, demonstrating the feasibility of JavaScript-based memory corruption attacks on modern hardware.</td><td>
- Rowhammer
- JavaScript Attacks
- DDR4
- TRR Bypass
- Web Security</td></tr>
<tr><td>Copy-on-Flip: Hardening ECC Memory Against Rowhammer Attacks</td><td>Andrea Di Dio, Koen Koning, Herbert Bos, and Cristiano Giuffrida</td><td>2023</td><td>This paper proposes Copy-on-Flip (CoF), a software-based Rowhammer mitigation for ECC memory. CoF detects ECC errors and proactively migrates memory pages before attackers can fully exploit bit flips. The system offers a low-overhead approach to securing ECC memory against sophisticated Rowhammer attacks.</td><td>
- Rowhammer
- ECC Memory
- Memory Protection
- Security Mitigation</td></tr>
<tr><td>RHAT: Efficient RowHammer-Aware Test for Modern DRAM Modules</td><td>Mohammad Farmani, Mark Tehranipoor, and Fahim Rahman</td><td>2021</td><td>RHAT is an efficient Rowhammer-aware testing framework designed to detect Rowhammer vulnerabilities in modern DRAM modules. It introduces a non-invasive method for reverse engineering DRAM address mappings and improves test efficiency by focusing on memory cell correlation analysis.</td><td>
- Rowhammer
- DRAM Testing
- Memory Security
- Vulnerability Assessment</td></tr>
<tr><td>Exploiting Hardware Vulnerabilities to Attack Embedded System Devices: A Survey of Potent Microarchitectural Attacks</td><td>Apostolos P. Fournaris, Lidia Pocero Fraile, and Odysseas Koufopavlou</td><td>2017</td><td>This paper surveys various hardware-based attacks on embedded systems, focusing on microarchitectural vulnerabilities like cache side-channels and Rowhammer. It discusses countermeasures and the evolving threat landscape for embedded and critical infrastructure systems.</td><td>
- Rowhammer
- Microarchitectural Attacks
- Embedded Security
- Side-Channel Attacks</td></tr>
<tr><td>Implementing Rowhammer Memory Corruption in the gem5 Simulator</td><td>Loïc France, Florent Bruguier, Maria Mushtaq, David Novo, and Pascal Benoit</td><td>2021</td><td>This paper extends the gem5 simulator to model Rowhammer-induced bit flips. The implementation allows researchers to evaluate Rowhammer mitigation techniques in simulated hardware environments, enabling more effective countermeasure development for modern computing systems.</td><td>
- Rowhammer
- Memory Corruption
- gem5 Simulator
- Hardware Security</td></tr>
<tr><td>When Good Protections Go Bad: Exploiting Anti-DoS Measures to Accelerate Rowhammer Attacks</td><td>Misiker Tadesse Aga, Zelalem Birhanu Aweke, and Todd Austin</td><td>2017</td><td>This paper demonstrates how modern security protections against Rowhammer, such as doubling DRAM refresh rates, restricting virtual memory access, and disabling cache-flush operations, can be circumvented. The authors introduce an attack leveraging Intel’s Cache Allocation Technology (CAT) to reduce cache associativity, thereby accelerating Rowhammer attacks even in fully protected systems.</td><td>
- Rowhammer
- DRAM
- Cache Allocation
- Security Bypass
- Intel CAT</td></tr>
<tr><td>Memory-Aware Denial-of-Service Attacks on Shared Cache in Multicore Real-Time Systems</td><td>Michael Bechtel, and Heechul Yun</td><td>2022</td><td>This paper introduces a novel memory-aware Denial-of-Service (DoS) attack on shared caches in multicore real-time systems. By leveraging memory address mapping and huge pages, the authors show that an attacker can induce significant execution slowdowns for critical tasks, even in partitioned cache environments.</td><td>
- Denial-of-Service
- Cache Attacks
- Multicore Systems
- Real-Time Computing</td></tr>
<tr><td>Curious Case of Rowhammer: Flipping Secret Exponent Bits Using Timing Analysis</td><td>Sarani Bhattacharya, and Debdeep Mukhopadhyay</td><td>2016</td><td>This paper demonstrates how Rowhammer can be combined with timing analysis attacks to induce bit flips in cryptographic keys stored in memory. By exploiting a Prime+Probe cache attack and row-buffer collisions, the authors successfully corrupt bits in RSA keys, compromising encryption security.</td><td>
- Rowhammer
- Cryptanalysis
- Fault Injection
- Timing Attacks
- RSA</td></tr>
<tr><td>Dedup Est Machina: Memory Deduplication as an Advanced Exploitation Vector</td><td>Erik Bosman, Kaveh Razavi, Herbert Bos, and Cristiano Giuffrida</td><td>2016</td><td>This paper explores how memory deduplication can be exploited as a side-channel attack. The authors demonstrate how deduplication can be combined with Rowhammer to bypass memory protections and achieve arbitrary read/write access in Microsoft Edge, even without traditional software vulnerabilities.</td><td>
- Rowhammer
- Memory Deduplication
- Side-Channel Attacks
- Browser Exploits</td></tr>
<tr><td>OpenSSL Bellcore’s Protection Helps Fault Attack</td><td>Sebastien Carre, Matthieu Desjardins, Adrien Facon, and Sylvain Guilley</td><td>2018</td><td>This paper analyzes the security of OpenSSL’s RSA implementation against fault attacks. The authors demonstrate that Bellcore’s countermeasures can ironically facilitate fault attacks by exposing new fault locations in cryptographic computations. The findings highlight the importance of designing robust protections against Rowhammer and other hardware-based attacks.</td><td>
- Rowhammer
- Cryptanalysis
- Fault Injection
- OpenSSL
- RSA</td></tr>
<tr><td>Grand Pwning Unit: Accelerating Microarchitectural Attacks with the GPU</td><td>Pietro Frigo, Cristiano Giuffrida, Herbert Bos, and Kaveh Razavi</td><td>2018</td><td>This paper explores the security implications of integrated GPUs in mobile processors. The authors demonstrate how GPUs can be used to accelerate microarchitectural attacks, including Rowhammer, from JavaScript. They reverse-engineer the GPU cache architecture to develop a more efficient Rowhammer attack that bypasses modern mitigations, allowing browser-based exploits on mobile devices in under two minutes.</td><td>
- Rowhammer
- GPU Attacks
- Side-Channel Attacks
- Mobile Security
- JavaScript</td></tr>
<tr><td>TRRespass: Exploiting the Many Sides of Target Row Refresh</td><td>Pietro Frigo, Emanuele Vannacci, Hasan Hassan, Victor van der Veen, Onur Mutlu, Cristiano Giuffrida, Herbert Bos, and Kaveh Razavi</td><td>2020</td><td>TRRespass analyzes the effectiveness of in-DRAM Target Row Refresh (TRR) mechanisms against Rowhammer. The authors develop a novel fuzzing methodology to bypass TRR and induce Rowhammer bit flips on modern DDR4 modules. Their results show that 13 out of 42 tested modules remain vulnerable, challenging claims of Rowhammer immunity.</td><td>
- Rowhammer
- DRAM
- TRR Bypass
- Memory Security
- DDR4 Vulnerability</td></tr>
<tr><td>DReAM: Dynamic Re-arrangement of Address Mapping to Improve the Performance of DRAMs</td><td>Mohsen Ghasempour, Aamer Jaleel, Jim D. Garside, and Mikel Luján</td><td>2016</td><td>DReAM introduces a dynamic address mapping scheme that optimizes DRAM performance by detecting workload-specific access patterns at runtime. The proposed method reduces page conflicts and enhances memory bandwidth efficiency, achieving up to 28% performance gains over static mappings.</td><td>
- DRAM
- Address Mapping
- Memory Optimization
- Performance Enhancement</td></tr>
<tr><td>DRAM Row-Hammer Attack Reduction Using Dummy Cells</td><td>Hector Gomez, Andres Amaya, and Elkim Roa</td><td>2016</td><td>This paper presents a low-cost hardware mitigation for Rowhammer using dummy memory cells. These additional cells have higher leakage currents and serve as early indicators of Rowhammer activity. The proposed method introduces minimal hardware overhead while significantly reducing the risk of bit flips.</td><td>
- Rowhammer
- DRAM Mitigation
- Hardware Security
- Memory Protection</td></tr>
<tr><td>HammerSim: A Tool to Model Rowhammer</td><td>Kaustav Goswami, Ayaz Akram, Hari Venugopalan, and Jason Lowe-Power</td><td>2023</td><td>HammerSim is a simulation tool integrated with gem5 to model Rowhammer attacks at the system level. It captures Rowhammer-induced bit flips more accurately than existing models, enabling better security evaluations and mitigation strategies for future DRAM technologies.</td><td>
- Rowhammer
- Simulation
- Memory Security
- gem5
- DRAM Testing</td></tr>
<tr><td>Rowhammer Attacks: An Extended Walkthrough Guide</td><td>Daniel Gruss</td><td>2017</td><td>This paper provides a comprehensive guide to Rowhammer attacks, detailing the underlying mechanisms, attack techniques, and mitigation strategies. It includes hands-on tools for researchers to experiment with Rowhammer on real hardware and in simulated environments.</td><td>
- Rowhammer
- Memory Corruption
- Security Guide
- Attack Techniques</td></tr>
<tr><td>Uncovering In-DRAM RowHammer Protection Mechanisms: A New Methodology, Custom RowHammer Patterns, and Implications</td><td>Hasan Hassan, Yahya Can Tuğrul, Jeremie S. Kim, Victor van der Veen, Kaveh Razavi, and Onur Mutlu</td><td>2022</td><td>This paper introduces U-TRR, an experimental methodology to analyze the effectiveness of in-DRAM Rowhammer mitigation mechanisms. The authors use custom Rowhammer patterns to bypass proprietary TRR defenses, revealing vulnerabilities in 45 tested DRAM modules.</td><td>
- Rowhammer
- DRAM Security
- TRR Analysis
- Memory Protection</td></tr>
<tr><td>WhistleBlower: A System-level Empirical Study on RowHammer</td><td>Wei He, Zhi Zhang, Yueqiang Cheng, Wenhao Wang, Wei Song, Yansong Gao, Qifei Zhang, Kang Li, Dongxi Liu, and Surya Nepal</td><td>2023</td><td>WhistleBlower performs an empirical study on Rowhammer vulnerabilities in 292 DRAM chips. It examines the impact of DRAM configurations, software-level optimizations, and real-world conditions on Rowhammer susceptibility. The findings highlight inconsistencies between prior FPGA-based studies and real-world DRAM behavior.</td><td>
- Rowhammer
- DRAM Testing
- Empirical Study
- Security Research</td></tr>
<tr><td>Reverse-Engineering Bank Addressing Functions on AMD CPUs</td><td>Martin Heckel, and Florian Adamsky</td><td>2023</td><td>This paper presents a new approach to reverse-engineering DRAM bank addressing functions on AMD CPUs. By uncovering previously undocumented addressing mechanisms, the authors provide insights for Rowhammer research and performance optimization in AMD-based systems.</td><td>
- Rowhammer
- AMD CPUs
- DRAM Addressing
- Reverse Engineering</td></tr>
<tr><td>Reliable Reverse Engineering of Intel DRAM Addressing Using Performance Counters</td><td>Christian Helm, Soramichi Akiyama, and Kenjiro Taura</td><td>2020</td><td>This paper introduces an automatic method to reverse-engineer Intel DRAM addressing functions using CPU performance counters. The methodology enables researchers to identify row and bank mappings reliably, aiding in Rowhammer analysis and memory performance optimizations.</td><td>
- Rowhammer
- Intel DRAM
- Address Mapping
- Reverse Engineering</td></tr>
<tr><td>Adaptive Linear Address Map for Bank Interleaving in DRAMs</td><td>Jae Young Hur, Sang Woo Rhim, Beom Hak Lee, and Wooyoung Jang</td><td>2019</td><td>This paper introduces an adaptive bank-interleaved address mapping scheme to enhance DRAM performance. The proposed technique dynamically reconfigures memory access patterns based on workload requirements, reducing bank conflicts and improving memory utilization for applications such as image processing.</td><td>
- DRAM
- Address Mapping
- Bank Interleaving
- Memory Optimization</td></tr>
<tr><td>MASCAT: Stopping Microarchitectural Attacks Before Execution</td><td>Gorka Irazoqui, Thomas Eisenbarth, and Berk Sunar</td><td>2017</td><td>MASCAT is a static code analysis tool designed to detect microarchitectural attacks, including Rowhammer, before execution. The tool scans applications for suspicious memory access patterns and helps prevent attacks at the software distribution level, making it useful for app stores and cloud platforms.</td><td>
- Rowhammer
- Microarchitectural Attacks
- Static Analysis
- Security</td></tr>
<tr><td>Reliably Achieving and Efficiently Preventing Rowhammer Attacks</td><td>Niccolò Izzo</td><td>2017</td><td>This thesis presents a comprehensive study on Rowhammer, detailing both attack mechanisms and mitigation strategies. The author proposes software and hardware countermeasures, including a random row index permutation at DRAM initialization to reduce attack feasibility.</td><td>
- Rowhammer
- DRAM Security
- Memory Protection
- Mitigation</td></tr>
<tr><td>The Performance and Power Impact of Using Multiple DRAM Address Mapping Schemes in Multicore Processors</td><td>Rami Jadaa</td><td>2011</td><td>This study investigates the performance and power consumption implications of different DRAM address mapping schemes in multicore processors. It proposes a dynamic mapping scheme that achieves up to 2x bandwidth efficiency and 30% power savings compared to static mappings.</td><td>
- DRAM
- Address Mapping
- Multicore Processors
- Power Efficiency</td></tr>
<tr><td>SGX-Bomb: Locking Down the Processor via Rowhammer Attack</td><td>Yeongjin Jang, Jaehyuk Lee, Sangho Lee, and Taesoo Kim</td><td>2017</td><td>SGX-Bomb is a Rowhammer-based attack that targets Intel SGX enclaves, causing processor integrity failures that force system reboots. The attack demonstrates a severe denial-of-service (DoS) vulnerability in public cloud environments where SGX enclaves are used for secure computations.</td><td>
- Rowhammer
- Intel SGX
- DoS Attack
- Cloud Security</td></tr>
<tr><td>BLACKSMITH: Scalable Rowhammering in the Frequency Domain</td><td>Patrick Jattke, Victor van der Veen, Pietro Frigo, Stijn Gunter, and Kaveh Razavi</td><td>2022</td><td>BLACKSMITH introduces a new class of non-uniform Rowhammer patterns that bypass Target Row Refresh (TRR) mitigations in DDR4 and LPDDR4X memory. The attack achieves a 2.6x higher success rate than previous techniques, demonstrating the persistent vulnerability of modern DRAM.</td><td>
- Rowhammer
- TRR Bypass
- DRAM Security
- DDR4
- Memory Corruption</td></tr>
<tr><td>ZenHammer: Rowhammer Attacks on AMD Zen-based Platforms</td><td>Patrick Jattke, Max Wipfli, Flavien Solt, Michele Marazzi, Matej Bölcskei, and Kaveh Razavi</td><td>2023</td><td>ZenHammer is the first successful Rowhammer attack on AMD Zen-based CPUs. The authors reverse-engineer DRAM addressing functions and synchronize with refresh commands to bypass in-DRAM mitigations, demonstrating Rowhammer bit flips on DDR4 and DDR5 devices.</td><td>
- Rowhammer
- AMD Zen
- DRAM Security
- DDR5
- Memory Attacks</td></tr>
<tr><td>CSI:Rowhammer – Cryptographic Security and Integrity against Rowhammer</td><td>Jonas Juffinger, Lukas Lamster, Andreas Kogler, Maria Eichlseder, Moritz Lipp, and Daniel Gruss</td><td>2023</td><td>CSI:Rowhammer introduces a novel cryptographic integrity verification method for DRAM. By using a message authentication code (MAC)-based approach, it ensures data integrity and mitigates Rowhammer attacks more effectively than traditional ECC memory.</td><td>
- Rowhammer
- Cryptographic Security
- ECC Memory
- DRAM Protection</td></tr>
<tr><td>Work-in-Progress: DRAM-MaUT – DRAM Address Mapping Unveiling Tool for ARM Devices</td><td>Anandpreet Kaur, Pravin Srivastav, and Bibhas Ghoshal</td><td>2022</td><td>DRAM-MaUT is a reverse-engineering tool for analyzing DRAM address mappings on ARM-based devices. It provides insights into DRAM geometry, enabling more effective Rowhammer attacks and security research on embedded platforms.</td><td>
- Rowhammer
- DRAM Address Mapping
- ARM Security
- Reverse Engineering</td></tr>
<tr><td>Flipping Bits in Memory Without Accessing Them: An Experimental Study of DRAM Disturbance Errors</td><td>Yoongu Kim, Ross Daly, Jeremie Kim, Chris Fallin, Ji Hye Lee, Donghyuk Lee, Chris Wilkerson, Konrad Lai, and Onur Mutlu</td><td>2014</td><td>This foundational study provides the first extensive experimental analysis of Rowhammer, demonstrating how repeated activations of DRAM rows can induce bit flips in adjacent memory cells. The work laid the groundwork for future Rowhammer research and mitigation strategies.</td><td>
- Rowhammer
- DRAM Disturbance
- Memory Corruption
- Security Research</td></tr>
<tr><td>Architectural Support for Mitigating Row Hammering in DRAM Memories</td><td>Dae-Hyun Kim, Prashant J. Nair, and Moinuddin K. Qureshi</td><td>2015</td><td>This paper introduces two architectural solutions to mitigate Rowhammer: Counter-Based Row Activation (CRA) and Probabilistic Row Activation (PRA). CRA utilizes counters for each row to track activations, issuing dummy refreshes when thresholds are exceeded. PRA reduces storage overhead by randomly refreshing neighboring rows, offering effective Rowhammer protection with minimal performance impact.</td><td>
- Rowhammer
- DRAM
- Counter-Based Protection
- Probabilistic Protection
- Hardware Security</td></tr>
<tr><td>RowHammer: Reliability Analysis and Security Implications</td><td>Yoongu Kim, Ross Daly, Jeremie Kim, Chris Fallin, Ji Hye Lee, Donghyuk Lee, Chris Wilkerson, Konrad Lai, and Onur Mutlu</td><td>2016</td><td>This study explores the reliability and security implications of Rowhammer in modern DRAM. The authors test 129 DRAM modules, revealing that Rowhammer errors affect most recent devices. They propose system-level mitigation techniques and highlight the urgency for effective countermeasures as DRAM technology scales.</td><td>
- Rowhammer
- DRAM Reliability
- Security
- Memory Protection
- Fault Analysis</td></tr>
<tr><td>An Effective DRAM Address Remapping for Mitigating Rowhammer Errors</td><td>Moonsoo Kim, Jungwoo Choi, Hyun Kim, and Hyuk-Jae Lee</td><td>2019</td><td>This paper presents a DRAM address remapping scheme to disperse Rowhammer errors across multiple rows, reducing the concentration of bit flips. The proposed method significantly lowers uncorrectable errors while maintaining low hardware costs, enhancing DRAM resilience to Rowhammer attacks.</td><td>
- Rowhammer
- DRAM
- Address Remapping
- Error Mitigation
- Hardware Security</td></tr>
<tr><td>Revisiting RowHammer: An Experimental Analysis of Modern DRAM Devices and Mitigation Techniques</td><td>Jeremie S. Kim, Minesh Patel, A. Giray Yağlıkçı, Hasan Hassan, Roknoddin Azizi, Lois Orosa, and Onur Mutlu</td><td>2020</td><td>This experimental study evaluates the susceptibility of 1580 DRAM chips to Rowhammer. The findings indicate increased vulnerability in modern DRAM with reduced feature sizes, highlighting the need for improved mitigation strategies as existing solutions struggle with performance overheads.</td><td>
- Rowhammer
- DRAM Vulnerability
- Experimental Analysis
- Memory Protection
- Security</td></tr>
<tr><td>HammerFilter: Robust Protection and Low Hardware Overhead Method for RowHammer</td><td>Kwangrae Kim, Jeonghyun Woo, Junsu Kim, and Ki-Seok Chung</td><td>2021</td><td>HammerFilter is a low-cost, hardware-based solution to counter Rowhammer attacks. It employs a modified counting bloom filter to track aggressor rows, effectively preventing bit flips without significant area overhead. The technique outperforms existing probabilistic methods, offering robust security.</td><td>
- Rowhammer
- Hardware Protection
- Bloom Filter
- Memory Security
- DRAM</td></tr>
<tr><td>Mithril: Cooperative Row Hammer Protection on Commodity DRAM Leveraging Managed Refresh</td><td>Michael Jaemin Kim, Jaehyun Park, Yeonhong Park, Wanju Doh, Namhoon Kim, Tae Jun Ham, Jae W. Lee, and Jung Ho Ahn</td><td>2021</td><td>Mithril leverages the new Refresh Management (RFM) command in DDR5/LPDDR5 to offer cooperative Rowhammer protection between DRAM and memory controllers. The technique minimizes performance and energy overheads while ensuring deterministic protection.</td><td>
- Rowhammer
- DDR5
- Managed Refresh
- Memory Controller
- DRAM Security</td></tr>
<tr><td>Half-Double: Hammering From the Next Row Over</td><td>Andreas Kogler, Jonas Juffinger, Salman Qazi, Yoongu Kim, Moritz Lipp, Nicolas Boichat, Eric Shiu, Mattias Nissler, and Daniel Gruss</td><td>2022</td><td>Half-Double expands the reach of Rowhammer by inducing bit flips beyond immediate neighboring rows. This novel attack, validated on Chromebooks with ECC and TRR protection, bypasses existing mitigations, emphasizing the need for updated defenses.</td><td>
- Rowhammer
- Half-Double
- Memory Security
- ECC
- TRR</td></tr>
<tr><td>ZebRAM: Comprehensive and Compatible Software Protection Against Rowhammer Attacks</td><td>Radhesh Krishnan Konoth, Marco Oliverio, Andrei Tatar, Dennis Andriesse, Herbert Bos, Cristiano Giuffrida, and Kaveh Razavi</td><td>2018</td><td>ZebRAM isolates DRAM rows with guard rows to prevent all Rowhammer-induced bit flips. It uses virtualization extensions for transparent data placement, offering robust protection without hardware changes.</td><td>
- Rowhammer
- Software Protection
- DRAM Security
- Virtualization
- Memory Isolation</td></tr>
<tr><td>RAMBleed: Reading Bits in Memory Without Accessing Them</td><td>Andrew Kwong, Daniel Genkin, Daniel Gruss, and Yuval Yarom</td><td>2020</td><td>RAMBleed exploits Rowhammer as a read side channel, revealing confidential data without direct access. The attack successfully extracts RSA keys from OpenSSH, bypassing ECC protection, demonstrating Rowhammer's threat to confidentiality.</td><td>
- Rowhammer
- RAMBleed
- Side-Channel Attack
- ECC
- Confidentiality</td></tr>
<tr><td>TWiCe: Time Window Counter Based Row Refresh to Prevent Row-Hammering</td><td>Eojin Lee, Sukhan Lee, G. Edward Suh, and Jung Ho Ahn</td><td>2018</td><td>TWiCe mitigates Rowhammer using time-windowed counters to track row activations and trigger refreshes. The method achieves deterministic protection with minimal hardware overhead, enhancing DRAM reliability.</td><td>
- Rowhammer
- Counter-Based Protection
- DRAM
- Memory Refresh
- Reliability</td></tr>
<tr><td>TWiCe: Preventing Row-hammering by Exploiting Time Window Counters</td><td>Eojin Lee, Ingab Kang, Sukhan Lee, G. Edward Suh, and Jung Ho Ahn</td><td>2019</td><td>TWiCe introduces a counter-based Rowhammer mitigation technique that leverages time-windowed counters to track row activations. By selectively refreshing victim rows only when necessary, TWiCe provides strong Rowhammer protection with minimal performance and area overheads, ensuring efficient memory security.</td><td>
- Rowhammer
- DRAM Protection
- Counter-Based Refresh
- Memory Security</td></tr>
<tr><td>Self-Adaptive Address Mapping Mechanism for Access Pattern Awareness on DRAM</td><td>Chundian Li, Mingzhe Zhang, Zhiwei Xu, and Xianhe Sun</td><td>2019</td><td>This paper proposes a self-adaptive address mapping mechanism that dynamically adjusts data layout on DRAM based on access patterns. The technique enhances spatial locality and bank-level parallelism, improving memory performance in scientific computing and AI workloads.</td><td>
- DRAM
- Address Mapping
- Memory Optimization
- Adaptive Mechanisms</td></tr>
<tr><td>Securing Monolithic Kernels using Compartmentalization</td><td>Soo Yee Lim, Sidhartha Agrawal, Xueyuan Han, David Eyers, Dan O’Keeffe, and Thomas Pasquier</td><td>2024</td><td>This paper explores compartmentalization techniques for securing monolithic OS kernels. By defining security domains and enforcing strong isolation, the proposed techniques prevent kernel-wide compromises caused by vulnerabilities in individual components.</td><td>
- Operating System Security
- Kernel Compartmentalization
- Software Isolation</td></tr>
<tr><td>Nethammer: Inducing Rowhammer Faults through Network Requests</td><td>Moritz Lipp, Misiker Tadesse Aga, Michael Schwarz, Daniel Gruss, Clémentine Maurice, Lukas Raab, and Lukas Lamster</td><td>2018</td><td>Nethammer presents the first truly remote Rowhammer attack, demonstrating that Rowhammer bit flips can be induced via network requests without local code execution. The attack bypasses traditional mitigations, proving a significant security risk for networked systems.</td><td>
- Rowhammer
- Remote Attacks
- Network Security
- DRAM Exploits</td></tr>
<tr><td>An Experimental Study of Data Retention Behavior in Modern DRAM Devices: Implications for Retention Time Profiling Mechanisms</td><td>Jamie Liu, Ben Jaiyen, Yoongu Kim, Chris Wilkerson, and Onur Mutlu</td><td>2018</td><td>This study examines the variability of DRAM retention times across different memory cells. It identifies key factors affecting retention behavior, including data pattern dependence and variable retention time, with implications for memory refresh optimizations and security vulnerabilities.</td><td>
- DRAM
- Retention Time
- Memory Reliability
- Security Implications</td></tr>
<tr><td>Get Out of the Valley: Power-Efficient Address Mapping for GPUs</td><td>Yuxi Liu, Xia Zhao, Magnus Jahre, Zhenlin Wang, Xiaolin Wang, Yingwei Luo, and Lieven Eeckhout</td><td>2018</td><td>This paper introduces a novel GPU memory address mapping technique that maximizes memory parallelism while minimizing power consumption. The proposed entropy-based mapping improves GPU performance by 1.31x and enhances power efficiency by 1.25x.</td><td>
- GPU
- Address Mapping
- Power Efficiency
- Memory Optimization</td></tr>
<tr><td>Stop! Hammer Time: Rethinking Our Approach to Rowhammer Mitigations</td><td>Kevin Loughlin, Stefan Saroiu, Alec Wolman, and Baris Kasikci</td><td>2021</td><td>This paper critiques the black-box approach of DRAM vendors in addressing Rowhammer and advocates for system-level mitigations. The authors propose novel CPU memory controller-based solutions to supplement in-DRAM protections, providing stronger security guarantees.</td><td>
- Rowhammer
- DRAM Mitigation
- Memory Security
- CPU-Based Protection</td></tr>
<tr><td>MOESI-prime: Preventing Coherence-Induced Hammering in Commodity Workloads</td><td>Kevin Loughlin, Stefan Saroiu, Alec Wolman, Yatin A. Manerkar, and Baris Kasikci</td><td>2022</td><td>MOESI-prime identifies and mitigates a new form of Rowhammer, coherence-induced hammering, which arises in modern cache-coherent NUMA architectures. The authors propose an enhanced coherence protocol that eliminates unnecessary DRAM accesses, preventing bit flips while maintaining system performance.</td><td>
- Rowhammer
- NUMA
- Cache Coherence
- DRAM Security</td></tr>
<tr><td>Siloz: Leveraging DRAM Isolation Domains to Prevent Inter-VM Rowhammer</td><td>Kevin Loughlin, Jonah Rosenblum, Stefan Saroiu, Alec Wolman, Dimitrios Skarlatos, and Baris Kasikci</td><td>2023</td><td>Siloz introduces a hypervisor-based solution to prevent inter-VM Rowhammer attacks in cloud environments. By isolating virtual machines within DRAM subarray groups, the system ensures strong memory security without performance degradation.</td><td>
- Rowhammer
- DRAM Isolation
- Cloud Security
- Hypervisor-Based Protection</td></tr>
<tr><td>ProTRR: Principled yet Optimal In-DRAM Target Row Refresh</td><td>Michele Marazzi, Patrick Jattke, Flavien Solt, and Kaveh Razavi</td><td>2022</td><td>ProTRR presents a mathematically optimal in-DRAM Rowhammer mitigation technique. By leveraging frequent item counting algorithms, it efficiently tracks and refreshes vulnerable DRAM rows, providing robust protection with minimal performance and energy overhead.</td><td>
- Rowhammer
- DRAM Security
- Target Row Refresh
- Memory Protection</td></tr>
<tr><td>RowHammer: A Retrospective</td><td>Onur Mutlu, and Jeremie S. Kim</td><td>2020</td><td>This paper provides a retrospective analysis of RowHammer, detailing its discovery, exploitation, and the various mitigation techniques developed over the years. The authors discuss the fundamental reasons behind the RowHammer phenomenon and emphasize the need for a principled approach to memory reliability and security.</td><td>
- Rowhammer
- DRAM Security
- Memory Reliability
- Vulnerability Analysis</td></tr>
<tr><td>Fundamentally Understanding and Solving RowHammer</td><td>Onur Mutlu, Ataberk Olgun, and A. Giray Yağlıkcı</td><td>2023</td><td>This paper explores the fundamental mechanisms behind RowHammer, highlighting how modern DRAM scaling exacerbates the problem. The authors propose future research directions, including system-memory co-design approaches and hardware-software collaboration to mitigate the issue in a scalable manner.</td><td>
- Rowhammer
- DRAM
- Technology Scaling
- System Memory Co-Design</td></tr>
<tr><td>Exploring the Horizon: A Comprehensive Survey of Rowhammer</td><td>Amir Naseredini</td><td>2023</td><td>This comprehensive survey categorizes Rowhammer-related research into attack variants, defense strategies, and emerging mitigation techniques. The author presents an extensive review of past and present studies, offering insights into future research directions for Rowhammer.</td><td>
- Rowhammer
- Survey
- Security
- DRAM Attacks
- Mitigations</td></tr>
<tr><td>ALARM: Active Learning of Rowhammer Mitigations</td><td>Amir Naseredini, Martin Berger, Matteo Sammartino, and Shale Xiong</td><td>2022</td><td>ALARM introduces an active learning-based methodology to infer Rowhammer mitigation parameters used in modern DRAMs. By leveraging machine learning techniques, the paper demonstrates an automated way to assess the effectiveness of hardware defenses.</td><td>
- Rowhammer
- Active Learning
- DRAM Security
- Target Row Refresh</td></tr>
<tr><td>Secure Page Fusion with VUsion</td><td>Marco Oliverio, Herbert Bos, Kaveh Razavi, and Cristiano Giuffrida</td><td>2017</td><td>This paper presents VUsion, a secure page fusion system that prevents memory-based attacks, including Rowhammer. It mitigates timing side-channel attacks and prevents predictable memory reuse patterns, making it an effective security measure in virtualized environments.</td><td>
- Rowhammer
- Memory Security
- Page Fusion
- Virtualization</td></tr>
<tr><td>Graphene: Strong yet Lightweight Row Hammer Protection</td><td>Yeonhong Park, Woosuk Kwon, Jung Ho Ahn, Eojin Lee, Jae W. Lee, and Tae Jun Ham</td><td>2020</td><td>Graphene proposes a counter-based Rowhammer prevention mechanism that leverages a space-efficient algorithm to track row activations. It ensures low energy and performance overhead while providing strong Rowhammer protection.</td><td>
- Rowhammer
- DRAM Security
- Low-Cost Mitigation
- Counter-Based Protection</td></tr>
<tr><td>HexPADS: A Platform to Detect “Stealth” Attacks</td><td>Mathias Payer</td><td>2016</td><td>HexPADS is a host-based intrusion detection system that leverages hardware performance counters to detect stealth attacks such as Rowhammer, side-channel attacks, and covert channels. It monitors process-level performance metrics to detect anomalies with minimal overhead.</td><td>
- Rowhammer
- Intrusion Detection
- Side-Channel Attacks
- Security Monitoring</td></tr>
<tr><td>DRAMA: Exploiting DRAM Addressing for Cross-CPU Attacks</td><td>Peter Pessl, Daniel Gruss, Clémentine Maurice, Michael Schwarz, and Stefan Mangard</td><td>2016</td><td>DRAMA presents a novel class of DRAM-based attacks that exploit undocumented address mappings to enable cross-CPU attacks. The study demonstrates how attackers can leverage DRAM row buffers for covert channels and Rowhammer exploits.</td><td>
- Rowhammer
- DRAM Addressing
- Cross-CPU Attacks
- Security Exploits</td></tr>
<tr><td>Attacking Deterministic Signature Schemes using Fault Attacks</td><td>Damian Poddebniak, Juraj Somorovsky, Sebastian Schinzel, Manfred Lochter, and Paul Rösler</td><td>2017</td><td>This paper investigates how deterministic digital signature schemes can be compromised using fault attacks, including Rowhammer. The authors demonstrate a practical attack on EdDSA, showing how an attacker can extract cryptographic private keys using induced bit flips.</td><td>
- Rowhammer
- Fault Injection
- Cryptographic Security
- Digital Signatures</td></tr>
<tr><td>Introducing Half-Double: New Hammering Technique for DRAM Rowhammer Bug</td><td>Salman Qazi, Yoongu Kim, Nicolas Boichat, Eric Shiu, and Mattias Nissler</td><td>2021</td><td>Half-Double is a new Rowhammer technique that extends the attack range beyond immediate neighboring rows, demonstrating bit flips two rows away from the aggressor. The findings indicate that Rowhammer remains an unsolved security issue as DRAM technology advances.</td><td>
- Rowhammer
- Half-Double
- DRAM Security
- Emerging Attacks</td></tr>
<tr><td>A New Approach for Rowhammer Attacks</td><td>Rui Qiao, and Mark Seaborn</td><td>2016</td><td>This paper introduces a novel Rowhammer attack method that does not rely on the x86 CLFLUSH instruction. Instead, it uses non-temporal store instructions, making it more difficult to detect and mitigate. Additionally, it identifies libc functions such as memset and memcpy as potential Rowhammer primitives, allowing attacks via benign-looking code. The paper also explores the possibility of remote Rowhammer attacks, posing new security threats.</td><td>
- Rowhammer
- Non-Temporal Instructions
- Memory Corruption
- Security Exploit</td></tr>
<tr><td>MOAT: Securely Mitigating Rowhammer with Per-Row Activation Counters</td><td>Moinuddin Qureshi, and Salman Qazi</td><td>2024</td><td>MOAT proposes a robust Rowhammer mitigation approach leveraging Per-Row Activation Counting (PRAC) and ALERT-Back-Off (ABO). The paper highlights flaws in prior mitigation techniques, including Panopticon, and introduces a secure design with two thresholds: ETH for mitigation and ATH for triggering ABO. MOAT significantly enhances in-DRAM Rowhammer defense while maintaining low performance overhead.</td><td>
- Rowhammer
- Per-Row Activation Counting
- Memory Security
- DRAM Protection</td></tr>
<tr><td>Hydra: Enabling Low-Overhead Mitigation of Row-Hammer at Ultra-Low Thresholds via Hybrid Tracking</td><td>Moinuddin Qureshi, Aditya Rohan, Gururaj Saileshwar, and Prashant J. Nair</td><td>2022</td><td>Hydra introduces a hybrid Rowhammer tracking approach that combines SRAM-based and DRAM-based tracking to provide scalable mitigation with low overhead. The method effectively mitigates Rowhammer even at ultra-low thresholds, ensuring robust protection while maintaining system performance.</td><td>
- Rowhammer
- Hybrid Tracking
- Low Overhead
- DRAM Security</td></tr>
<tr><td>DeepSteal: Advanced Model Extractions Leveraging Efficient Weight Stealing in Memories</td><td>Adnan Siraj Rakin, Md Hafizul Islam Chowdhury, Fan Yao, and Deliang Fan</td><td>2021</td><td>DeepSteal introduces a model extraction attack using Rowhammer-based memory fault techniques (HammerLeak). The attack allows adversaries to steal partial deep learning model weights efficiently, reducing attack costs and enhancing adversarial capabilities against DNNs. The authors propose countermeasures against this emerging threat.</td><td>
- Rowhammer
- Model Extraction
- AI Security
- Memory Faults</td></tr>
<tr><td>Flip Feng Shui: Hammering a Needle in the Software Stack</td><td>Kaveh Razavi, Ben Gras, Erik Bosman, Bart Preneel, Cristiano Giuffrida, and Herbert Bos</td><td>2016</td><td>Flip Feng Shui (FFS) is an advanced Rowhammer-based exploitation technique that allows attackers to flip specific bits in targeted physical memory locations. By leveraging memory deduplication, an attacker can precisely modify cryptographic keys and authentication data, demonstrating a powerful attack vector against cloud-hosted virtual machines.</td><td>
- Rowhammer
- Memory Deduplication
- Cloud Security
- Cryptographic Attacks</td></tr>
<tr><td>Randomized Row-Swap: Mitigating Row Hammer by Breaking Spatial Correlation between Aggressor and Victim Rows</td><td>Gururaj Saileshwar, Bolin Wang, Moinuddin Qureshi, and Prashant J. Nair</td><td>2022</td><td>Randomized Row-Swap (RRS) proposes a novel Rowhammer mitigation strategy by periodically swapping frequently accessed rows with randomly selected rows. This technique breaks the spatial correlation between aggressor and victim rows, preventing bit flips even in the presence of sophisticated Rowhammer patterns like Half-Double.</td><td>
- Rowhammer
- Randomized Mitigation
- Memory Protection
- Half-Double Defense</td></tr>
<tr><td>AQUA: Scalable Rowhammer Mitigation by Quarantining Aggressor Rows at Runtime</td><td>Anish Saxena, Gururaj Saileshwar, Prashant J. Nair, and Moinuddin Qureshi</td><td>2022</td><td>AQUA introduces a scalable Rowhammer mitigation approach that quarantines aggressor rows in a dedicated memory region. By dynamically isolating these rows, AQUA ensures robust protection against bit flips with negligible performance overhead.</td><td>
- Rowhammer
- Memory Isolation
- DRAM Security
- Mitigation Strategy</td></tr>
<tr><td>PT-Guard: Integrity-Protected Page Tables to Defend Against Breakthrough Rowhammer Attacks</td><td>Anish Saxena, Gururaj Saileshwar, Jonas Juffinger, Andreas Kogler, Daniel Gruss, and Moinuddin Qureshi</td><td>2023</td><td>PT-Guard protects page tables from Rowhammer attacks by embedding Message Authentication Codes (MACs) directly within unused bits of Page Table Entries (PTEs). This mechanism detects and corrects bit flips with minimal hardware overhead, preventing privilege escalation via Rowhammer exploits.</td><td>
- Rowhammer
- Page Table Protection
- Memory Integrity
- Hardware Security</td></tr>
<tr><td>DeepSteal: Advanced Model Extractions Leveraging Efficient Weight Stealing in Memories</td><td>Adnan Siraj Rakin, Md Hafizul Islam Chowdhury, Fan Yao, and Deliang Fan</td><td>2022</td><td>DeepSteal introduces an advanced model extraction attack using a memory side-channel attack based on Rowhammer. The proposed 'HammerLeak' method enables fast and efficient stealing of DNN model weights. It is the first attack framework to successfully extract DNN weights remotely, posing significant security risks for cloud-hosted AI models.</td><td>
- Rowhammer
- Model Extraction
- AI Security
- Memory Side-Channel</td></tr>
<tr><td>The Price of Secrecy: How Hiding Internal DRAM Topologies Hurts Rowhammer Defenses</td><td>Stefan Saroiu, Alec Wolman, and Lucian Cojocar</td><td>2022</td><td>This paper critiques DRAM vendors' decision to keep DRAM topologies secret, arguing that it hinders effective Rowhammer mitigations. The study demonstrates that lack of internal structure knowledge prevents efficient memory controller-based defenses, leaving systems vulnerable to evolving Rowhammer attacks.</td><td>
- Rowhammer
- DRAM Security
- Memory Controller
- Hardware Security</td></tr>
<tr><td>Intrinsic Rowhammer PUFs: Leveraging the Rowhammer Effect for Improved Security</td><td>André Schaller, Wenjie Xiong, Nikolaos Anagnostopoulos, Muhammad Umair Saleem, Sebastian Gabmeyer, Stefan Katzenbeisser, and Jakub Szefer</td><td>2017</td><td>This paper introduces the Rowhammer PUF, a novel Physically Unclonable Function (PUF) that utilizes Rowhammer-induced bit flips for device identification and authentication. Unlike traditional PUFs, it operates on commodity DRAM without requiring custom hardware.</td><td>
- Rowhammer
- PUF
- Device Identification
- Memory Security</td></tr>
<tr><td>Project Zero: Exploiting the DRAM Rowhammer Bug to Gain Kernel Privileges</td><td>Mark Seaborn, and Thomas Dullien</td><td>2015</td><td>This research by Google's Project Zero team presents one of the first practical Rowhammer-based privilege escalation attacks. The authors demonstrate how bit flips can be used to manipulate page table entries, gaining arbitrary memory access and escalating privileges on vulnerable systems.</td><td>
- Rowhammer
- Privilege Escalation
- Kernel Exploit
- Memory Corruption</td></tr>
<tr><td>Counter-Based Tree Structure for Row Hammering Mitigation in DRAM</td><td>Seyed Mohammad Seyedzadeh, Alex K. Jones, and Rami Melhem</td><td>2017</td><td>This paper proposes the Counter-Based Tree (CBT) structure for mitigating Rowhammer attacks. Unlike conventional per-row counters, CBT dynamically assigns counters to frequently accessed 'hot' rows, reducing refresh overhead while providing precise protection.</td><td>
- Rowhammer
- DRAM Mitigation
- Counter-Based Protection
- Memory Reliability</td></tr>
<tr><td>Making DRAM Stronger Against Row Hammering</td><td>Mungyu Son, Hyunsun Park, Junwhan Ahn, and Sungjoo Yoo</td><td>2017</td><td>This paper introduces PRoHIT, a probabilistically managed table stored on DRAM that tracks victim row candidates and selectively refreshes them to mitigate Rowhammer. The approach significantly outperforms PARA in reducing Rowhammer-induced bit flips.</td><td>
- Rowhammer
- DRAM Protection
- PRoHIT
- Probabilistic Refresh</td></tr>
<tr><td>Micro-Pages: Increasing DRAM Efficiency with Locality-Aware Data Placement</td><td>Kshitij Sudan, Niladrish Chatterjee, David Nellans, Manu Awasthi, Rajeev Balasubramonian, and Al Davis</td><td>N/A</td><td>This paper presents Micro-Pages, an optimization technique that improves DRAM row-buffer utilization by co-locating frequently accessed memory chunks. The approach reduces power consumption and improves performance in multi-core processors.</td><td>
- DRAM Optimization
- Memory Management
- Row Buffer Utilization
- Energy Efficiency</td></tr>
<tr><td>Defeating Software Mitigations Against Rowhammer: A Surgical Precision Hammer</td><td>Andrei Tatar, Cristiano Giuffrida, Herbert Bos, and Kaveh Razavi</td><td>2018</td><td>This paper demonstrates that software-based Rowhammer mitigations can be bypassed due to nonlinear memory address mappings. Using RAMSES, a new memory analysis framework, the authors show that attackers can still induce bit flips despite existing defenses.</td><td>
- Rowhammer
- Software Mitigation Bypass
- DRAM Addressing
- RAMSES</td></tr>
<tr><td>Throwhammer: Rowhammer Attacks Over the Network and Defenses</td><td>Andrei Tatar, Radhesh Krishnan Konoth, Elias Athanasopoulos, Cristiano Giuffrida, Herbert Bos, and Kaveh Razavi</td><td>2018</td><td>Throwhammer presents the first fully remote Rowhammer attack, demonstrating that bit flips can be triggered via RDMA-enabled network interfaces. The paper discusses potential defenses by isolating DMA buffers to prevent corruption of critical data.</td><td>
- Rowhammer
- Remote Attacks
- RDMA
- Network Security</td></tr>
<tr><td>SpecHammer: Combining Spectre and Rowhammer for New Speculative Attacks</td><td>Youssef Tobah, Andrew Kwong, Ingab Kang, Daniel Genkin, and Kang G. Shin</td><td>2022</td><td>SpecHammer introduces a new attack combining Spectre and Rowhammer, allowing attackers to manipulate speculative execution paths using Rowhammer-induced bit flips. The attack expands Spectre’s attack surface, making previously inaccessible gadgets exploitable.</td><td>
- Rowhammer
- Spectre
- Speculative Execution
- Side-Channel Attacks</td></tr>
<tr><td>Drammer: Deterministic Rowhammer Attacks on Mobile Platforms</td><td>Victor van der Veen, Yanick Fratantonio, Martina Lindorfer, Daniel Gruss, Clémentine Maurice, Giovanni Vigna, Herbert Bos, Kaveh Razavi, and Cristiano Giuffrida</td><td>2016</td><td>Drammer demonstrates that deterministic Rowhammer attacks are possible on mobile platforms, particularly Android devices. Unlike previous approaches relying on probabilistic bit flips or special memory features, Drammer exploits predictable memory reuse patterns to deterministically place security-critical data in vulnerable DRAM regions. The attack successfully escalates privileges to root on ARM-based smartphones without requiring software vulnerabilities.</td><td>
- Rowhammer
- Mobile Security
- ARM
- Android Exploit</td></tr>
<tr><td>GuardION: Practical Mitigation of DMA-Based Rowhammer Attacks on ARM</td><td>Victor van der Veen, Martina Lindorfer, Yanick Fratantonio, Harikrishnan Padmanabha Pillai, Giovanni Vigna, Christopher Kruegel, Herbert Bos, and Kaveh Razavi</td><td>2018</td><td>GuardION proposes a defense against DMA-based Rowhammer attacks on mobile ARM devices by isolating DMA buffers with guard rows. The authors present new Rowhammer-based exploits against Android, demonstrating that existing software defenses are ineffective. GuardION effectively prevents DMA-based Rowhammer attacks with negligible performance overhead.</td><td>
- Rowhammer
- Mobile Security
- DMA Isolation
- Android</td></tr>
<tr><td>Rapid Detection of RowHammer Attacks using Dynamic Skewed Hash Tree</td><td>Saru Vig, Siew-Kei Lam, Sarani Bhattacharya, and Debdeep Mukhopadhyay</td><td>2018</td><td>This paper introduces a fast and efficient Rowhammer detection technique that uses a combination of sliding window protocol and a dynamic integrity tree. The method enables rapid identification of frequently accessed DRAM rows while maintaining minimal hardware overhead. It is designed to detect Rowhammer-induced bit flips before they become exploitable.</td><td>
- Rowhammer
- DRAM Security
- Bit-Flip Detection
- Hardware Security</td></tr>
<tr><td>Principled Microarchitectural Isolation on Cloud CPUs</td><td>Stavros Volos, Cédric Fournet, Jana Hofmann, Boris Köpf, and Oleksii Oleksenko</td><td>2024</td><td>Marghera introduces an advanced approach for isolating microarchitectural resources in cloud environments, preventing cross-VM side-channel attacks. The system enforces resource partitioning at the CPU level and ensures that caches, memory, and coherence directories are securely allocated to virtual machines. It demonstrates near-zero performance impact while eliminating leakage pathways.</td><td>
- Cloud Security
- Microarchitecture
- Side-Channel Mitigation
- Virtualization</td></tr>
<tr><td>On DRAM Rowhammer and the Physics of Insecurity</td><td>Andrew J. Walker, Sungkwon Lee, and Dafna Beery</td><td>2021</td><td>This paper provides an in-depth analysis of the physical mechanisms behind Rowhammer attacks, including electron injection, capacitive crosstalk, and subthreshold leakage in DRAM. The authors evaluate different mitigation strategies and discuss the challenges posed by continued DRAM scaling. The study highlights the limitations of current defenses and suggests new directions for hardware-based mitigations.</td><td>
- Rowhammer
- DRAM Physics
- Hardware Security
- Memory Reliability</td></tr>
<tr><td>Detect DRAM Disturbance Error by Using Disturbance Bin Counters</td><td>Yicheng Wang, Yang Liu, Peiyun Wu, and Zhao Zhang</td><td>2019</td><td>This paper proposes Disturbance Bin Counters (DBC), a lightweight hardware mechanism that efficiently detects and prevents Rowhammer attacks. DBC tracks memory accesses to identify rows experiencing high activation counts and proactively refreshes affected regions. The approach is designed to minimize hardware overhead while guaranteeing protection against Rowhammer.</td><td>
- Rowhammer
- DRAM Security
- Memory Controller
- Bit-Flip Detection</td></tr>
<tr><td>DRAMDig: A Knowledge-assisted Tool to Uncover DRAM Address Mapping</td><td>Minghua Wang, Zhi Zhang, Yueqiang Cheng, and Surya Nepal</td><td>2020</td><td>DRAMDig is a reverse-engineering tool designed to uncover DRAM address mappings on Intel platforms. It significantly improves upon prior techniques by leveraging domain knowledge, allowing for deterministic and efficient DRAM mapping recovery. The tool enhances the effectiveness of double-sided Rowhammer attacks and is useful for evaluating DRAM security risks.</td><td>
- Rowhammer
- Address Mapping
- Reverse Engineering
- Intel DRAM</td></tr>
<tr><td>Scalable and Secure Row-Swap: Efficient and Safe Row Hammer Mitigation in Memory Systems</td><td>Jeonghyun Woo, Gururaj Saileshwar, and Prashant J. Nair</td><td>2022</td><td>This paper critiques existing Rowhammer defenses, particularly Randomized Row-Swap (RRS), and proposes Secure Row-Swap (SRS) as a countermeasure. SRS prevents Rowhammer attacks by avoiding additional row activations during swap operations. It incorporates attack detection mechanisms to identify future exploit patterns while reducing memory overhead.</td><td>
- Rowhammer
- DRAM Mitigation
- Secure Row-Swap
- Memory Security</td></tr>
<tr><td>Protecting Page Tables from RowHammer Attacks using Monotonic Pointers in DRAM True-Cells</td><td>Xin-Chuan Wu, Timothy Sherwood, Frederic T. Chong, and Yanjing Li</td><td>2019</td><td>This paper introduces a novel memory allocation strategy that leverages DRAM true-cells and anti-cells to mitigate Rowhammer-based privilege escalation attacks. By placing page tables in controlled memory regions, it prevents Rowhammer-induced bit flips from altering system-critical structures.</td><td>
- Rowhammer
- Page Table Protection
- Memory Security
- Privilege Escalation</td></tr>
<tr><td>One Bit Flips, One Cloud Flops: Cross-VM Row Hammer Attacks and Privilege Escalation</td><td>Yuan Xiao, Xiaokuan Zhang, Yinqian Zhang, and Radu Teodorescu</td><td>2016</td><td>This paper explores Rowhammer attacks in a cloud computing context, demonstrating cross-VM privilege escalation via bit flips. The authors develop an algorithm to recover DRAM address mappings and execute high-fidelity double-sided Rowhammer attacks. The study highlights serious security risks in multi-tenant virtualized environments.</td><td>
- Rowhammer
- Cloud Security
- Cross-VM Attack
- Virtualization Exploit</td></tr>
<tr><td>BlockHammer: Preventing RowHammer at Low Cost by Blacklisting Rapidly-Accessed DRAM Rows</td><td>A. Giray Yağlıkçı, Minesh Patel, Jeremie S. Kim, Roknoddin Azizi, Ataberk Olgun, Lois Orosa, Hasan Hassan, Jisung Park, Konstantinos Kanellopoulos, Taha Shahroodi, Saugata Ghose, and Onur Mutlu</td><td>2022</td><td>BlockHammer introduces a low-cost and effective RowHammer mitigation technique that prevents all RowHammer bit-flips without requiring modifications to DRAM internals. Using Bloom filters, it tracks row activation rates and dynamically throttles accesses to prevent RowHammer-unsafe activation frequencies. The method is scalable and efficient, providing strong security without the overheads of alternative mitigation mechanisms.</td><td>
- Rowhammer
- DRAM Security
- Memory Protection
- Bloom Filters</td></tr>
<tr><td>HiRA: Hidden Row Activation for Reducing Refresh Latency of Off-the-Shelf DRAM Chips</td><td>A. Giray Yağlıkçı, Ataberk Olgun, Minesh Patel, Haocong Luo, Hasan Hassan, Lois Orosa, Oğuz Ergin, and Onur Mutlu</td><td>2022</td><td>HiRA (Hidden Row Activation) is a new DRAM refresh optimization technique that reduces refresh latency by allowing two rows to be activated simultaneously when connected to different charge restoration circuitry. It achieves this without requiring modifications to existing DRAM chips. HiRA significantly improves system performance by reducing the impact of periodic and preventive refreshes, especially for high-density DRAM chips.</td><td>
- DRAM Optimization
- Rowhammer Mitigation
- Memory Performance
- Refresh Efficiency</td></tr>
<tr><td>DeepHammer: Depleting the Intelligence of Deep Neural Networks through Targeted Chain of Bit Flips</td><td>Fan Yao, Adnan Siraj Rakin, and Deliang Fan</td><td>2020</td><td>DeepHammer is a novel RowHammer-based attack targeting deep neural networks (DNNs). It uses bit flips in quantized DNN model weights to degrade prediction accuracy significantly. The attack is demonstrated on 12 DNN architectures across multiple datasets, showing its effectiveness in real-world AI security scenarios.</td><td>
- Rowhammer
- AI Security
- Deep Learning
- Model Corruption</td></tr>
<tr><td>Triggering Rowhammer Hardware Faults on ARM: A Revisit</td><td>Zhenkai Zhang, Zihao Zhan, Daniel Balasubramanian, Xenofon Koutsoukos, and Gabor Karsai</td><td>2018</td><td>This paper revisits Rowhammer attacks on ARM platforms, analyzing the feasibility of porting x86-based attack strategies. It introduces new approaches leveraging ARMv8-A cache maintenance instructions and proposes a previously unknown instruction for triggering Rowhammer faults on ARM-based devices.</td><td>
- Rowhammer
- ARM Security
- Hardware Faults
- Microarchitectural Attacks</td></tr>
<tr><td>TeleHammer: A Formal Model of Implicit Rowhammer</td><td>Zhi Zhang, Yueqiang Cheng, Dongxi Liu, Surya Nepal, and Zhi Wang</td><td>2020</td><td>TeleHammer introduces a new paradigm of RowHammer attacks that do not require explicit access to hammer rows. Instead, attackers exploit implicit DRAM accesses caused by inherent hardware and software features. The study formalizes TeleHammer’s attack model and demonstrates a practical instance, PThammer, that crosses privilege boundaries to trigger bit flips.</td><td>
- Rowhammer
- Implicit Attacks
- Privilege Escalation
- DRAM Security</td></tr>
<tr><td>GhostKnight: Breaching Data Integrity via Speculative Execution</td><td>Zhi Zhang, Yueqiang Cheng, and Surya Nepal</td><td>2022</td><td>GhostKnight is the first attack that leverages speculative execution to breach data integrity instead of just confidentiality. It triggers speculative DRAM accesses to induce permanent bit flips, allowing attackers to modify protected memory regions. The attack has severe implications for system security, as it bypasses traditional speculative execution defenses.</td><td>
- Speculative Execution
- Rowhammer
- Data Integrity
- Microarchitectural Attacks</td></tr>
<tr><td>Software-Defined Address Mapping: A Case on 3D Memory</td><td>Jialiang Zhang, Michael Swift, and Jing (Jane) Li</td><td>2022</td><td>This paper proposes Software-Defined Address Mapping (SDAM), a new approach for optimizing memory access in 3D-stacked memory systems. It enables user programs to directly control memory address mappings, improving bandwidth utilization and reducing contention in high-performance computing scenarios.</td><td>
- 3D Memory
- Address Mapping
- High-Performance Computing
- Memory Optimization</td></tr>
<tr><td>Implicit Hammer: Cross-Privilege-Boundary Rowhammer Through Implicit Accesses</td><td>Zhi Zhang, Wei He, Yueqiang Cheng, Wenhao Wang, Yansong Gao, Dongxi Liu, Kang Li, Surya Nepal, Anmin Fu, and Yi Zou</td><td>2023</td><td>Implicit Hammer introduces a novel attack technique that bypasses traditional RowHammer defenses by triggering bit flips through indirect accesses. The study demonstrates how attackers can induce bit flips across privilege boundaries, making existing software-based defenses ineffective.</td><td>
- Rowhammer
- Cross-Privilege Attacks
- DRAM Security
- Hardware Exploits</td></tr>

    </tbody>
</table>

<script>
    $(document).ready(function() {
        $('#sortableTable').DataTable();
    });
</script>
