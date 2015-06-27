#ifndef MPL14_TUPLE_SPLIT_HPP_INCLUDED
#define MPL14_TUPLE_SPLIT_HPP_INCLUDED

#include "pop_front.hpp"
#include "push_back.hpp"
#include "../control/if.hpp"

#include <tuple>
#include <type_traits>

namespace mplex
{

    /** @param Tuple A tuple.
     *  @param Sepearator A type that is matched via std::is_same used as splitter token.
     *  @param Accum1 Internal.
     *  @param Accum2 Internal.
     *
     *  @return A new tuple.
     */
    template <typename Tuple, typename Predicate, typename Accum1 = std::tuple <>, typename Accum2 = std::tuple <>, bool abort = false>
    struct split { };

    template <typename T, typename Predicate, typename Accum1, typename Accum2, typename... List>
    struct split <std::tuple <T, List...>, Predicate, Accum1, Accum2, false> {
        constexpr static const bool do_split = Predicate::template apply <T>::value;

        using type = if_t <!do_split,
                typename split <std::tuple <List...>, Predicate, push_back_t <Accum1, T>, Accum2, do_split>::type, // do "nothing" and push T to accum
                typename split <std::tuple <List...>, Predicate, std::tuple <>, push_back_t <Accum2, Accum1>, !do_split>::type>;
    };

    template <typename Predicate, typename Accum1, typename Accum2>
    struct split <std::tuple <>, Predicate, Accum1, Accum2, false> {
        using type = push_back_t <Accum2, Accum1>;
    };

    template <typename Tuple, typename Predicate, typename Accum1, typename Accum2>
    struct split <Tuple, Predicate, Accum1, Accum2, true> {
        using type = std::tuple<>;
    };

    template <typename Tuple, typename Predicate>
    using split_t = typename split <Tuple, Predicate>::type;

    // if cur = Seperator
}

#endif // MPL14_TUPLE_SPLIT_HPP_INCLUDED
