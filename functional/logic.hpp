#ifndef MPLEX_FUNCTIONAL_LOGIC_HPP_INCLUDED
#define MPLEX_FUNCTIONAL_LOGIC_HPP_INCLUDED

namespace mplex {
    namespace logic_operators {
        struct and_ {
            template <typename Lhs, typename Rhs>
            struct apply {
                using type = bool_ <Lhs::type::value && Rhs::type::value>;
            };
        };

        struct or_ {
            template <typename Lhs, typename Rhs>
            struct apply {
                using type = bool_ <Lhs::type::value || Rhs::type::value>;
            };
        };

        struct eq_ {
            template <typename Lhs, typename Rhs>
            struct apply {
                using type = bool_ <Lhs::type::value == Rhs::type::value>;
            };
        };

        struct neq_ {
            template <typename Lhs, typename Rhs>
            struct apply {
                using type = bool_ <Lhs::type::value != Rhs::type::value>;
            };
        };

        struct gt_ {
            template <typename Lhs, typename Rhs>
            struct apply {
                using type = bool_ <(Lhs::type::value > Rhs::type::value)>;
            };
        };

        struct lt_ {
            template <typename Lhs, typename Rhs>
            struct apply {
                using type = bool_ <(Lhs::type::value < Rhs::type::value)>;
            };
        };

        struct gte_ {
            template <typename Lhs, typename Rhs>
            struct apply {
                using type = bool_ <(Lhs::type::value >= Rhs::type::value)>;
            };
        };

        struct lte_ {
            template <typename Lhs, typename Rhs>
            struct apply {
                using type = bool_ <(Lhs::type::value <= Rhs::type::value)>;
            };
        };

        struct not_ {
            template <typename Lhs>
            struct apply {
                using type = bool_ <!Lhs::type::value>;
            };
        };
    }
}

#endif // MPLEX_FUNCTIONAL_LOGIC_HPP_INCLUDED
