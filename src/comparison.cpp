#include "comparison.hpp"

#include <catch2/catch_approx.hpp>

namespace tnt::math
{

bool near(const double a, const double b, const double scale)
{
    return a == Catch::Approx(b).scale(scale);
}

}  // namespace tnt::math
