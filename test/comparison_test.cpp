#include <catch2/catch_test_macros.hpp>
#include <tnt/math/comparison.hpp>

using namespace tnt;

TEST_CASE("near", "[near]")
{
    constexpr auto a = 0.15 + 0.15;
    constexpr auto b = 0.1 + 0.2;
    constexpr auto c = a - b;

    CHECK(math::near(a, b));
    CHECK(math::near(c, 0));
}
