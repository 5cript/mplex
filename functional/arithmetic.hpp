#ifndef MPL14_FUNCTIONAL_ARITHMETIC_HPP_INCLUDED
#define MPL14_FUNCTIONAL_ARITHMETIC_HPP_INCLUDED

namespace mplex {
    namespace aritmetic_operators {
        template <typename integral_t = int>
        struct add_ {
            template <typename Lhs, typename Rhs>
            struct apply {
                using type = integral <integral_t, Lhs::type::value + Rhs::type::value>;
            };
        };

        template <typename integral_t = int>
        struct sub_ {
            template <typename Lhs, typename Rhs>
            struct apply {
                using type = integral <integral_t, Lhs::type::value - Rhs::type::value>;
            };
        };

        template <typename integral_t = int>
        struct mul_ {
            template <typename Lhs, typename Rhs>
            struct apply {
                using type = integral <integral_t, Lhs::type::value * Rhs::type::value>;
            };
        };

        template <typename integral_t = int>
        struct div_ {
            template <typename Lhs, typename Rhs>
            struct apply {
                using type = integral <integral_t, Lhs::type::value / Rhs::type::value>;
            };
        };

        template <typename integral_t = int>
        struct inverse_ {
            template <typename Lhs>
            struct apply {
                using type = integral <integral_t, -Lhs::type::value>;
            };
        };

        template <typename integral_t = int>
        struct mod_ {
            template <typename Lhs, typename Rhs>
            struct apply {
                using type = integral <integral_t, Lhs::type::value % Rhs::type::value>;
            };
        };

        template <typename integral_t = int>
        struct inc_ {
            template <typename Lhs>
            struct apply {
                using type = integral <integral_t, Lhs::type::value+1>;
            };
        };

        template <typename integral_t = int>
        struct dec_ {
            template <typename Lhs>
            struct apply {
                using type = integral <integral_t, Lhs::type::value-1>;
            };
        };
    }
}

#endif // MPL14_FUNCTIONAL_ARITHMETIC_HPP_INCLUDED
