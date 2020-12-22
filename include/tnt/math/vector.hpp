#pragma once

#include <algorithm>
#include <vector>

namespace tnt::math
{

/*!
\brief Generates a linearly spaced vector

This function was inspired by the MATLAB linspace function. When given a begin/end value and a
number of data points to generate, the linspace function returns a vector of the specified size
filled with data that is evenly spaced between the begin and end value.

**For Example:**
\code{.cpp}
std::vector<double> data = linspace<double>(0, 1, 101);
\endcode

The code above will produce a vector containing 101 evenly spaced data points between 0 and 1... 0,
0.01, 0.02, ..., 0.98, 0.99, 1

\param[in] begin First value in the result vector
\param[in] end Last value in the result vector
\param[in] count Number of elements desired in the result vector
\return Vector containing "count" data points evenly spaced between the "begin" and "end" values.
*/
template <typename T>
std::vector<T> linspace(T begin, T end, size_t count)
{
    struct Generator
    {
        Generator(T begin, T step)
            : m_next(begin)
            , m_step(step)
        {}

        T operator()()
        {
            T current = m_next;
            m_next += m_step;
            return current;
        }

    private:
        T m_next;
        T m_step;
    };

    T step = (end - begin) / static_cast<T>(count - 1);

    std::vector<T> result(count);
    std::generate(result.begin(), result.end(), Generator(begin, step));

    return result;
}

}  // namespace tnt::math
