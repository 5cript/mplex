#ifndef MPLEX_TUPLE_IS_TUPLE_HPP_INCLUDED
#define MPLEX_TUPLE_IS_TUPLE_HPP_INCLUDED

// fundamental
#include "../fundamental/integral.hpp"

#include <tuple>

namespace mplex
{
    /**
     *  Functor returning true if T is tuple
     */
    struct is_tuple;

    namespace internal {
        template <typename T>
        struct is_tuple_impl {
            constexpr static const bool value = false;
        };

        template <typename... List>
        struct is_tuple_impl <std::tuple <List...> > {
            constexpr static const bool value = true;
        };
    }

    struct is_tuple {
        template <typename T>
        struct apply {
            using type = bool_<internal::is_tuple_impl<T>::value>;
            constexpr static const bool value = type::value;
        };
    };
}

#endif // MPLEX_TUPLE_IS_TUPLE_HPP_INCLUDED
