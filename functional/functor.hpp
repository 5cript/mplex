#ifndef MPLEX_FUNCTIONAL_FUNCTOR_HPP_INCLUDED
#define MPLEX_FUNCTIONAL_FUNCTOR_HPP_INCLUDED

#include "../tuple/apply.hpp"
#include "../tuple/make_tuple.hpp"
#include "../tuple/push_front.hpp"

/**
 *  A functor is defined as class that containing an apply template
 *
 *  functors generally are called like:   func::template apply <PARAMS...>::type
 */

namespace mplex {
    namespace internal {
        template <typename T, typename... List>
        struct has_arity_impl {
            typedef char yes[1];
            typedef char no[2];

            template <typename C>
            static yes& test(typename C::template apply<List...>*);

            template <typename>
            static no& test(...);

            using type = bool_ <sizeof(test<T>(nullptr)) == sizeof(yes)>;
            constexpr static const bool value = type::value;
        };
    }

    template <typename T, typename Arity>
    struct has_arity {
        using temp_tuple = push_front_t <typename make_tuple <generators::nulls>::template apply <Arity>::type, T>;
        using type = bool_ <apply_t <temp_tuple, internal::has_arity_impl>::value>;
        constexpr static const bool value = type::value;
    };

    template <typename T, unsigned Arity>
    using has_arity_v = typename has_arity <T, unsigned_ <Arity> >::type;
}

#endif // MPLEX_FUNCTIONAL_FUNCTOR_HPP_INCLUDED
