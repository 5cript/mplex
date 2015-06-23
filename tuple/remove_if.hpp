#ifndef REMOVE_IF_HPP_INCLUDED
#define REMOVE_IF_HPP_INCLUDED

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
    template <typename Tuple, template <typename T> class Predicate, typename Accum = std::tuple <>>
    struct remove_if { };

    template <typename T, template <typename T> class Predicate, typename Accum, typename ... List>
    struct remove_if <std::tuple <T, List...>, Predicate, Accum> {
        using type =
        if_t <Predicate <T>::value,
              typename remove_if <std::tuple <List...>, Predicate, Accum>::type, // remove
              typename remove_if <std::tuple <List...>, Predicate, push_back_t <Accum, T>>::type>; // keep
    };

    template <template <typename T> class Predicate, typename Accum>
    struct remove_if <std::tuple <>, Predicate, Accum> {
        using type = Accum;
    };

    template <typename Tuple, template <typename T> class Predicate>
    using remove_if_t = typename remove_if <Tuple, Predicate>::type;
}

#endif // REMOVE_IF_HPP_INCLUDED
