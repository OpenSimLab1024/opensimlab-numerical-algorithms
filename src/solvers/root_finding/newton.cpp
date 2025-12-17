#include "opensimlab/solvers/root_finding/newton.hpp"

#include <cmath>
#include <stdexcept>

namespace opensimlab {
namespace solvers {
namespace root_finding {

double newton(
    const std::function<double(double)>& f,
    const std::function<double(double)>& df,
    double x0,
    double tol,
    std::size_t max_iter
) {
    double x = x0;

    for (std::size_t iter = 0; iter < max_iter; ++iter) {
        double fx = f(x);
        double dfx = df(x);

        if (std::abs(dfx) < 1e-14) {
            throw std::runtime_error("Newton method failed: derivative is too small.");
        }

        double x_new = x - fx / dfx;

        if (std::abs(x_new - x) < tol) {
            return x_new;
        }

        x = x_new;
    }

    throw std::runtime_error("Newton method did not converge within max_iter.");
}

} // namespace root_finding
} // namespace solvers
} // namespace opensimlab
