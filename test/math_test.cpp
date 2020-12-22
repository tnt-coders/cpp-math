#include <catch2/catch_template_test_macros.hpp>
#include <catch2/catch_test_macros.hpp>
#include <tnt/math/comparison.hpp>
#include <tnt/math/math.hpp>

using namespace tnt;

TEST_CASE("mod - integral", "[mod]")
{
    CHECK(math::mod(10, 5) == 0);
    CHECK(math::mod(11, 5) == 1);
    CHECK(math::mod(12, 5) == 2);
    CHECK(math::mod(13, 5) == 3);
    CHECK(math::mod(14, 5) == 4);
    CHECK(math::mod(10, -5) == 0);
    CHECK(math::mod(11, -5) == -4);
    CHECK(math::mod(12, -5) == -3);
    CHECK(math::mod(13, -5) == -2);
    CHECK(math::mod(14, -5) == -1);
    CHECK(math::mod(-10, 5) == 0);
    CHECK(math::mod(-11, 5) == 4);
    CHECK(math::mod(-12, 5) == 3);
    CHECK(math::mod(-13, 5) == 2);
    CHECK(math::mod(-14, 5) == 1);
    CHECK(math::mod(-10, -5) == 0);
    CHECK(math::mod(-11, -5) == -1);
    CHECK(math::mod(-12, -5) == -2);
    CHECK(math::mod(-13, -5) == -3);
    CHECK(math::mod(-14, -5) == -4);
}

TEMPLATE_TEST_CASE("mod - floating point", "[mod]", double, float)
{
    CHECK(math::near(math::mod<TestType>(10, 5), 0));
    CHECK(math::near(math::mod<TestType>(11, 5), 1));
    CHECK(math::near(math::mod<TestType>(12, 5), 2));
    CHECK(math::near(math::mod<TestType>(13, 5), 3));
    CHECK(math::near(math::mod<TestType>(14, 5), 4));
    CHECK(math::near(math::mod<TestType>(10, -5), 0));
    CHECK(math::near(math::mod<TestType>(11, -5), -4));
    CHECK(math::near(math::mod<TestType>(12, -5), -3));
    CHECK(math::near(math::mod<TestType>(13, -5), -2));
    CHECK(math::near(math::mod<TestType>(14, -5), -1));
    CHECK(math::near(math::mod<TestType>(-10, 5), 0));
    CHECK(math::near(math::mod<TestType>(-11, 5), 4));
    CHECK(math::near(math::mod<TestType>(-12, 5), 3));
    CHECK(math::near(math::mod<TestType>(-13, 5), 2));
    CHECK(math::near(math::mod<TestType>(-14, 5), 1));
    CHECK(math::near(math::mod<TestType>(-10, -5), 0));
    CHECK(math::near(math::mod<TestType>(-11, -5), -1));
    CHECK(math::near(math::mod<TestType>(-12, -5), -2));
    CHECK(math::near(math::mod<TestType>(-13, -5), -3));
    CHECK(math::near(math::mod<TestType>(-14, -5), -4));
}
