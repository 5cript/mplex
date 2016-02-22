#ifndef MPLEX_TUPLE_PUSH_BACK_HPP_INCLUDED
#define MPLEX_TUPLE_PUSH_BACK_HPP_INCLUDED

#include <tuple>
#include "apply.hpp"

namespace mplex
{
    /** @param Tuple A tuple.
     *  @param Elem An arbitrary type.
     *
     *  @return The same tuple with one element ("Elem") more at the end.
     */
    template <typename Tuple, typename Elem>
    struct push_back
    { };

    template <typename Elem, typename... List>
    struct push_back <std::tuple <List...>, Elem> {
        using type = std::tuple <List..., Elem>;
    };

    template <typename Tuple, typename Elem>
    using push_back_t = typename push_back <Tuple, Elem>::type;
}

#endif // MPLEX_TUPLE_PUSH_BACK_HPP_INCLUDED
