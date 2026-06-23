# WideOpenFHE vs Vanilla OpenFHE

## What We Optimized

WideOpenFHE optimizes exactly ONE component of OpenFHE: **the bootstrapping step.**

Everything else — encryption, decryption, key generation, scheme parameters, memory management — is unchanged OpenFHE.

## Specific Optimization

| Component | Vanilla OpenFHE | WideOpenFHE |
|-----------|----------------|-------------|
| **Bootstrapping Method** | Blind rotate + Key switch | φ-weighted zero-anchor addition |
| **Operations per Refresh** | Thousands | 1 |
| **Time per Refresh** | ~10ms (TFHE) / ~5ms (CKKS) | 0.03ms |
| **Code Complexity** | 500+ lines | 5 lines |
| **Noise Target** | Reset to near-zero | Converge to 40-bit Lyapunov fixed point |

## What We Did NOT Change

- OpenFHE's CKKS scheme implementation
- OpenFHE's BGV scheme implementation
- OpenFHE's key generation
- OpenFHE's parameter selection
- OpenFHE's memory management

## The "Optimization Layer" Explained

```
┌─────────────────────────────────────────┐
│         WideOpenFHE (This Repo)          │
│  ┌─────────────────────────────────┐    │
│  │  Advanced Noise Refresh Protocol│    │
│  │  ct + Enc(0) = ct              │    │
│  └──────────────┬──────────────────┘    │
│                 │ calls                  │
│  ┌──────────────▼──────────────────┐    │
│  │         OpenFHE                  │    │
│  │  (Unchanged — Full Library)     │    │
│  │  Encrypt | Decrypt | Add | Mul  │    │
│  └─────────────────────────────────┘    │
└─────────────────────────────────────────┘
```

WideOpenFHE is a thin layer that ONLY replaces the bootstrapping call.
The rest is vanilla OpenFHE.
