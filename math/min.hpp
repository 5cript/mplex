#ifndef MPL14_MATH_MIN_HPP_INCLUDED
#define MPL14_MATH_MIN_HPP_INCLUDED

#include "../fundamental/integral.hpp"

namespace mplex {
    template <typename Lhs, typename Rhs>
    struct min {
        using type = if_vt <(Lhs::value<Rhs::value), Lhs, Rhs>;
    };
}

#endif // MPL14_MATH_MIN_HPP_INCLUDED
