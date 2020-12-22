#pragma once

namespace tnt::math
{

/*!
\brief Determines whether two floating point numbers are approximately equal

Floating point numbers cannot be directly compared using "==" because they cannot be stored in
computer systems with infinite precision. Because of this, slight rounding errors will result in
comparisons of two floating point numbers that should be considered equal to fail.

This function takes two floating point numbers and compares them to see if they are close enough to
be considered equal.

For comparisons near zero the "scale" value is used to determine the order of magnitude of the data.
A default scale of "1" is assumed, but if you are dealing with large numbers tests around zero may
fail. To fix this, set the scale value to the same order of magnitude as the data being compared.

For example, if the data you are processing is in the millions (on the order of magnitude of 10^6),
then set scale value to std::pow(10, 6).

\code{.cpp}
constexpr auto a = 0.15 + 0.15;
constexpr auto b = 0.1 + 0.2;

if (a == b)
{
    // Code will most likely not get here
    // Due to slight rounding errors "a" will most likely not be exactly equal to "b"
}

if (near(a, b))
{
    // Code will get here
    std::cout << "a is approximately equal to b" << std::endl;
}
\endcode

\param[in] a First floating point value to compare
\param[in] b Second floating point value to compare
\param[in] scale Scale to use when comparing values near zero (see above)
*/
bool near(const double a, const double b, const double scale = 1);

}  // namespace tnt::math
