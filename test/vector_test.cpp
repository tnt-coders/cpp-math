#include <catch2/catch_template_test_macros.hpp>
#include <tnt/math/comparison.hpp>
#include <tnt/math/vector.hpp>
#include <vector>

using namespace tnt;

TEMPLATE_TEST_CASE("linspace", "[linspace]", double, float)
{
    std::vector<TestType> expected;

    for (size_t n = 0; n <= 100; ++n)
    {
        expected.push_back(n * static_cast<TestType>(0.01));
    }

    const auto actual = math::linspace<TestType>(0, 1, 101);

    REQUIRE(actual.size() == expected.size());

    for (size_t n = 0; n < expected.size(); ++n)
    {
        CHECK(math::near(actual[n], expected[n]));
    }
}
