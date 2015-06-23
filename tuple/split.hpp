#ifndef SPLIT_HPP_INCLUDED
#define SPLIT_HPP_INCLUDED

#include "pop_front.hpp"
#include "push_back.hpp"
#include "../traits/type_traits.hpp" // std::is_same
#include "../control/if.hpp"

#include <tuple>

namespace mplex
{

    /** @param Tuple A tuple.
     *  @param Sepearator A type that is matched via std::is_same used as splitter token.
     *  @param Accum1 Internal.
     *  @param Accum2 Internal.
     *
     *  @return A new tuple.
     */
    template <typename Tuple, typename Seperator, typename Accum1 = std::tuple <>, typename Accum2 = std::tuple <>>
    struct split { };

    template <typename T, typename Seperator, typename Accum1, typename Accum2, typename ... List>
    struct split <std::tuple <T, List...>, Seperator, Accum1, Accum2> {

        using type = if_t <!std::is_same <T, Seperator>::value,
                typename split <std::tuple <List...>, Seperator, push_back_t <Accum1, T>, Accum2>::type, // do "nothing" and push T to accum
                typename split <std::tuple <List...>, Seperator, std::tuple <>, push_back_t <Accum2, Accum1>>::type>;
    };

    template <typename Seperator, typename Accum1, typename Accum2>
    struct split <std::tuple <>, Seperator, Accum1, Accum2> {
        using type = push_back_t <Accum2, Accum1>;
    };

    template <typename Tuple, typename Seperator>
    using split_t = typename split <Tuple, Seperator>::type;

    // if cur = Seperator
}

#endif // SPLIT_HPP_INCLUDED
