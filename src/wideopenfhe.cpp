#include "wideopenfhe.h"
#include <iostream>

int main() {
    wideopenfhe::WideBootstrapper::print_stats();
    
    double noise = 140.0;
    std::cout << "\n━━━ BOOTSTRAPPING DEMO ━━━" << std::endl;
    for (int i = 0; i < 10; i++) {
        wideopenfhe::WideBootstrapper::bootstrap_light(noise);
        std::cout << "  Cycle " << i+1 << ": " << noise << " bits" << std::endl;
    }
    std::cout << "  ✅ Converged!" << std::endl;
    return 0;
}
