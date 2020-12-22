#pragma once

#include <cmath>

namespace tnt::math
{

/*!
\brief Gets the remainder of the operation dividend/divisor

The C++ modulus "%" operator does not mean the same thing as it does in mathematics. This function
provides the expected modulus functionality.

This function results in undefined behavior if the provided divisor is 0.

\param[in] dividend Dividend used to calculate the modulus
\param[in] divisor Divisor used to calculate the modulus
\return The modulus of the dividend and divisor
*/
template <typename T>
T mod(T dividend, T divisor)
{
    return dividend - divisor * static_cast<T>(std::floor(static_cast<double>(dividend) / divisor));
}

}  // namespace tnt::math
