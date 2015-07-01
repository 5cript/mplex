#ifndef MPL14_FUNCTIONAL_BITWISE_HPP_INCLUDED
#define MPL14_FUNCTIONAL_BITWISE_HPP_INCLUDED

#include "../fundamental/integral.hpp"

#include <type_traits>

namespace mplex {
    namespace bitwise_operators {
        template <typename integral_t = unsigned int>
        struct or_ {
            template <typename Lhs, typename Rhs>
            struct apply {
                using type = integral <std::make_unsigned <integral_t>::type, Lhs::type::value | Rhs::type::value>;
            };
        };

        template <typename integral_t = unsigned int>
        struct and_ {
            template <typename Lhs, typename Rhs>
            struct apply {
                using type = integral <std::make_unsigned <integral_t>::type, Lhs::type::value & Rhs::type::value>;
            };
        };

        template <typename integral_t = unsigned int>
        struct xor_ {
            template <typename Lhs, typename Rhs>
            struct apply {
                using type = integral <std::make_unsigned <integral_t>::type, Lhs::type::value ^ Rhs::type::value>;
            };
        };

        template <typename integral_t = unsigned int>
        struct lshift_ {
            template <typename Lhs, typename Rhs>
            struct apply {
                using type = integral <std::make_unsigned <integral_t>::type, Lhs::type::value << Rhs::type::value>;
            };
        };

        template <typename integral_t = unsigned int>
        struct rshift_ {
            template <typename Lhs, typename Rhs>
            struct apply {
                using type = integral <std::make_unsigned <integral_t>::type, Lhs::type::value >> Rhs::type::value>;
            };
        };
    }
}

#endif // MPL14_FUNCTIONAL_BITWISE_HPP_INCLUDED
