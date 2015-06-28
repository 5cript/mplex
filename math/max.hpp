#ifndef MPL14_MATH_MAX_HPP_INCLUDED
#define MPL14_MATH_MAX_HPP_INCLUDED

#include "../fundamental/integral.hpp"
#include "../control/if.hpp"

namespace mplex {
    template <typename Lhs, typename Rhs>
    struct max {
        using type = if_vt <(Lhs::value>Rhs::value), Lhs, Rhs>;
        using value = type::value;
    };
}

#endif // MPL14_MATH_MAX_HPP_INCLUDED
