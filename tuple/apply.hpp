#ifndef APPLY_HPP_INCLUDED
#define APPLY_HPP_INCLUDED

#include "back.hpp"
#include "front.hpp"
#include "pop_back.hpp"
#include "pop_front.hpp"

// Can be used to apply tuples as parameters to variadic templates.
namespace mplex {

    // APPLY
    template <typename TupleT, template <typename...> class FinalT, typename ... AccumList>
    struct apply {
        using type = typename
        apply <pop_front_t<TupleT>, FinalT, AccumList..., front_t<TupleT>>::type;
    };

    template <template <typename...> class FinalT, typename ... AccumList>
    struct apply <std::tuple<>, FinalT, AccumList...> {
        using type = FinalT <AccumList...>;
    };

    template <typename TupleT, template <typename...> class FinalT, typename ... AccumList>
    using apply_t = typename apply<TupleT, FinalT, AccumList...>::type;

    // APPLY_REVERSE
    template <typename TupleT, template <typename...> class FinalT, typename ... AccumList>
    struct apply_reverse {
        using type = typename
        apply_reverse <pop_back_t<TupleT>, FinalT, back_t<TupleT>, AccumList...>::type;
    };

    template <template <typename...> class FinalT, typename ... AccumList>
    struct apply_reverse <std::tuple<>, FinalT, AccumList...> {
        using type = FinalT <AccumList...>;
    };

    template <typename TupleT, template <typename...> class FinalT, typename ... AccumList>
    using apply_reverse_t = typename apply_reverse<TupleT, FinalT, AccumList...>::type;
}

#endif // APPLY_HPP_INCLUDED
