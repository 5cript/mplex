#ifndef MPLEX_TUPLE_APPLY_HPP_INCLUDED
#define MPLEX_TUPLE_APPLY_HPP_INCLUDED

#include "back.hpp"
#include "front.hpp"
#include "pop_back.hpp"
#include "pop_front.hpp"

// Can be used to apply tuples as parameters to variadic templates.
namespace mplex
{

    /** @param Tuple A tuple.
     *  @param Function A variadic template receiving the elements of "Tuple" as parameters.
     *
     *  @return basically Function<TupleElements...>.
     */
    template <typename Tuple, template <typename...> class Function>
    struct apply {    };

    template <template <typename...> class Function, typename... List>
    struct apply <std::tuple <List...>, Function> {
        using type = Function <List...>;
    };

    template <typename Tuple, template <typename...> class Function>
    using apply_t = typename apply <Tuple, Function>::type;

    // APPLY_REVERSE
    template <typename Tuple, template <typename...> class Function, typename... AccumList>
    struct apply_reverse {
        using type = typename
        apply_reverse <pop_back_t <Tuple>, Function, back_t <Tuple>, AccumList...>::type;
    };

    template <template <typename...> class Function, typename... AccumList>
    struct apply_reverse <std::tuple <>, Function, AccumList...> {
        using type = Function <AccumList...>;
    };

    template <typename Tuple, template <typename...> class Function, typename... AccumList>
    using apply_reverse_t = typename apply_reverse <Tuple, Function, AccumList...>::type;
}

#endif // MPLEX_TUPLE_APPLY_HPP_INCLUDED
