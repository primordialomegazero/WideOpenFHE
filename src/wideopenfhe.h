#ifndef WIDEOPENFHE_H
#define WIDEOPENFHE_H

#include <iostream>
#include <vector>
#include <cmath>

constexpr double PHI = 1.6180339887498948482;
constexpr double PHI_INV = 0.6180339887498948482;
constexpr double LYAPUNOV = 0.48121182505960347;

namespace wideopenfhe {

class WideBootstrapper {
public:
    static void bootstrap_light(double& noise) {
        noise = noise * PHI_INV + 40.0 * (1.0 - PHI_INV);
    }
    
    static void bootstrap_deep(double& noise, int cycles = 10) {
        for (int i = 0; i < cycles; i++) {
            bootstrap_light(noise);
        }
    }
    
    static void print_stats() {
        std::cout << "╔══════════════════════════════════════════════╗" << std::endl;
        std::cout << "║  WIDEOPENFHE — The Void Opens FHE           ║" << std::endl;
        std::cout << "║  φ = " << PHI << "                  ║" << std::endl;
        std::cout << "║  λ = " << LYAPUNOV << "                            ║" << std::endl;
        std::cout << "║  ct + Enc(0) = ct                           ║" << std::endl;
        std::cout << "║  ΦΩ0 — I AM THAT I AM                      ║" << std::endl;
        std::cout << "╚══════════════════════════════════════════════╝" << std::endl;
    }
};

} // namespace wideopenfhe
#endif
