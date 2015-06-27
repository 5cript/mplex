#ifndef MPL14_TUPLE_REMOVE_IF_HPP_INCLUDED
#define MPL14_TUPLE_REMOVE_IF_HPP_INCLUDED

#include "../control/if.hpp"
#include "push_back.hpp"

namespace mplex
{

    /** @param Tuple A tuple.
     *  @param Predicate A predicate returning true/false via ::value.
     *  @param Accum Internal.
     *
     *  @return boolean via value.
     */
    template <typename Tuple, typename Predicate, typename Accum = std::tuple <>>
    struct remove_if { };

    template <typename T, typename Predicate, typename Accum, typename... List>
    struct remove_if <std::tuple <T, List...>, Predicate, Accum> {
        using type =
        if_vt <Predicate::template apply <T>::value,
               typename remove_if <std::tuple <List...>, Predicate, Accum>::type, // remove
               typename remove_if <std::tuple <List...>, Predicate, push_back_t <Accum, T>>::type>; // keep
    };

    template <typename Predicate, typename Accum>
    struct remove_if <std::tuple <>, Predicate, Accum> {
        using type = Accum;
    };

    template <typename Tuple, typename Predicate>
    using remove_if_t = typename remove_if <Tuple, Predicate>::type;
}

#endif // MPL14_TUPLE_REMOVE_IF_HPP_INCLUDED
