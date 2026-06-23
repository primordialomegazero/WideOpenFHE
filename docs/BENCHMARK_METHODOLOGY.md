# Benchmark Methodology — WideOpenFHE

## Hardware Specifications

| Component | Specification |
|-----------|--------------|
| CPU | AMD Ryzen 5 2600 (3.40 GHz, 6 cores) |
| RAM | 16GB DDR4 |
| OS | Ubuntu 22.04 (WSL2 on Windows) |
| Compiler | GCC 11.4.0 (-O3 optimization) |
| OpenFHE | v1.5.1 |

## Measurement Methodology

### Sustained TPS (30-Second Benchmark)
- **Threads:** 6 worker threads (one per core)
- **Operation:** Encrypt → Refresh → Decrypt cycle
- **Measurement:** Atomic counters, sampled every 100ms
- **Duration:** 30 seconds continuous

### Burst TPS (Rapid Fire Test)
- **Threads:** Single-threaded
- **Operation:** 1000 rapid encrypt-refresh-decrypt cycles
- **Measurement:** High-resolution clock (std::chrono)
- **Bursts:** 10 bursts, averaged

### Enc/Dec Chain Test
- **Threads:** Single-threaded
- **Operation:** 8 encrypt + 10 homomorphic operations
- **Measurement:** Per-operation timing

## What We Measure

| Metric | Definition |
|--------|-----------|
| **Refresh TPS** | Number of noise refresh operations per second |
| **Operation TPS** | Total FHE operations (encrypt+refresh+decrypt) per second |
| **Noise Stability** | Final noise level after convergence (target: 40 bits) |
| **Lyapunov λ** | Exponential convergence rate (target: 0.4812) |

## Reproducibility

All benchmarks are automated. To reproduce:
```bash
git clone https://github.com/primordialomegazero/WideOpenFHE.git
cd WideOpenFHE
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release && make
./test_benchmark_30s   # Sustained TPS
./test_rapid_burst      # Burst TPS
./test_encrypt_decrypt_chain  # Chain verification
```
