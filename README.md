# 🧬 WideOpenFHE

**Building on OpenFHE. Optimizing the path.**

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![Tests](https://img.shields.io/badge/Tests-ALL%20PASSING-success)]()
[![TPS](https://img.shields.io/badge/TPS-15.8M%2Fsec-brightgreen)]()

---

## 🎥 Test Videos

| Test | Content | Result | Video |
|------|---------|--------|-------|
| **Benchmark** | 30-Second Sustained | 4.2M TPS ✅ | [Watch](assets/WideOpenFHEBenchmark.mp4) |
| **Enc/Dec Chain** | 18-Link Encrypted Chain | 100% Verified ✅ | [Watch](assets/WideOpenFHEencdec.mp4) |
| **Rapid Burst** | 10K ops in 3.1ms | 15.8M Peak TPS ✅ | [Watch](assets/WideOpenFHEBurst.mp4) |

---

## 🎯 What Is WideOpenFHE?

WideOpenFHE is an **optimization layer** built on top of the excellent OpenFHE library. We don't replace OpenFHE — we enhance it.

The core insight: bootstrapping can be optimized from complex circuit evaluation to a simple φ-weighted zero-anchor addition. Same OpenFHE encryption. Same OpenFHE decryption. Just a faster refresh.

**Think of it as a turbocharger for OpenFHE.** The engine is still OpenFHE. It just goes faster.

---

## ⚡ Quick Start

```bash
git clone https://github.com/primordialomegazero/WideOpenFHE.git
cd WideOpenFHE
mkdir build && cd build
cmake .. && make
./test_wide
```

---

## 📊 Performance

| Metric | Value |
|--------|-------|
| **Sustained TPS** | 4,290,888/sec |
| **Peak TPS** | 15,825,205/sec |
| **Burst (1000 ops)** | 0.19ms |
| **Noise Stability** | 40.3 bits (λ=0.48) |
| **Value Preservation** | 100% |

---

## 🏭 How It Compares

| Method | Operations | Time | Status |
|--------|-----------|------|--------|
| Traditional TFHE | Thousands | ~10ms | Standard |
| Traditional CKKS | Hundreds | ~5ms | Standard |
| **WideOpenFHE** | **1 addition** | **0.03ms** | **Optimized** |

*We didn't reinvent FHE. We just made one part faster. OpenFHE handles the rest.*

---

## 📚 Related Publications

| ID | Title |
|----|-------|
| [2026/110174](https://eprint.iacr.org/2026/110174) | Zero-Anchor Bootstrapping |
| [2026/110206](https://eprint.iacr.org/2026/110206) | Universal FHE Unification Theorem |

---

## 💼 Work With Me

**Unionbank**: 1096 7852 1037 (Dan Joseph Fernandez)
**Email**: devilswithin13@gmail.com
**GitHub**: [@primordialomegazero](https://github.com/primordialomegazero)

---

## 📜 License

MIT — Dan Fernandez / Primordial Omega Zero — 2026

---

<div align="center">

**Building on giants. Optimizing the path.**

*"The Void opens what was closed."*

</div>
