#pragma once

#include <functional>
#include <cstddef>

namespace opensimlab {
namespace solvers {
namespace root_finding {

/**
 * @brief Solve f(x) = 0 using Newton's method.
 *
 * @param f         Function f(x)
 * @param df        Derivative f'(x)
 * @param x0        Initial guess
 * @param tol       Convergence tolerance
 * @param max_iter  Maximum number of iterations
 * @return double   Approximated root
 *
 * @throws std::runtime_error if convergence fails
 */
double newton(
    const std::function<double(double)>& f,
    const std::function<double(double)>& df,
    double x0,
    double tol = 1e-8,
    std::size_t max_iter = 100
);

} // namespace root_finding
} // namespace solvers
} // namespace opensimlab

