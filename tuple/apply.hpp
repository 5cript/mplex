#ifndef APPLY_HPP_INCLUDED
#define APPLY_HPP_INCLUDED

#include "back.hpp"
#include "front.hpp"
#include "pop_back.hpp"
#include "pop_front.hpp"

// Can be used to apply tuples as parameters to variadic templates.
namespace mplex {

    /** @param Tuple A tuple.
     *  @param Final A variadic template receiving the elements of "Tuple" as parameters.
     *  @param AccumList Internal.
     *
     *  @return basically Final<TupleElements...>.
     */
    template <typename Tuple, template <typename...> class Final, typename ... AccumList>
    struct apply {
        using type = typename
        apply <pop_front_t<Tuple>, Final, AccumList..., front_t<Tuple>>::type;
    };

    template <template <typename...> class Final, typename ... AccumList>
    struct apply <std::tuple<>, Final, AccumList...> {
        using type = Final <AccumList...>;
    };

    template <typename Tuple, template <typename...> class Final, typename ... AccumList>
    using apply_t = typename apply<Tuple, Final, AccumList...>::type;

    // APPLY_REVERSE
    template <typename Tuple, template <typename...> class Final, typename ... AccumList>
    struct apply_reverse {
        using type = typename
        apply_reverse <pop_back_t<Tuple>, Final, back_t<Tuple>, AccumList...>::type;
    };

    template <template <typename...> class Final, typename ... AccumList>
    struct apply_reverse <std::tuple<>, Final, AccumList...> {
        using type = Final <AccumList...>;
    };

    template <typename Tuple, template <typename...> class Final, typename ... AccumList>
    using apply_reverse_t = typename apply_reverse<Tuple, Final, AccumList...>::type;
}

#endif // APPLY_HPP_INCLUDED
