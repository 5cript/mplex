#ifndef MPLEX_MATH_FACTORIAL_HPP_INCLUDED
#define MPLEX_MATH_FACTORIAL_HPP_INCLUDED

namespace mplex {
    constexpr long long factorial (long long index) {
        return (index != 1LL && index != 0LL) ? factorial(index - 1LL) * index : 1LL;
    }
}

#endif // MPLEX_MATH_FACTORIAL_HPP_INCLUDED
