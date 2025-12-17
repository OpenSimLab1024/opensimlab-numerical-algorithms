#include "opensimlab/solvers/root_finding/newton.hpp"
#include <iostream>
#include <cmath>

int main() {
    // calculate sqrt(2)
    auto f = [](double x) {return x * x - 2.0; };
    auto df = [](double x) {return 2.0 * x; };

    try {
        double root = opensimlab::solvers::root_finding::newton(f, df, 1.0);
        std::cout << "Root sqrt(2) = " << root << "\n";
        std::cout << "Check: f(root) = " << f(root) << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
