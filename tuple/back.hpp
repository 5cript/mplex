#ifndef MPLEX_TUPLE_BACK_HPP_INCLUDED
#define MPLEX_TUPLE_BACK_HPP_INCLUDED

#include <tuple>

namespace mplex
{
    /** @param Tuple A tuple.
     *
     *  @return The last element.
     */
    template <typename Tuple>
    struct back {
        static_assert (std::tuple_size <Tuple>::value > 0, "Tuple must not be empty");

        using type = typename std::tuple_element <std::tuple_size <Tuple>::value - 1, Tuple>::type;
    };

    struct back_a {
        template <typename Tuple>
        struct apply {
            using type = typename back <Tuple>::type;
        };
    };

    template <typename Tuple>
    using back_t = typename back <Tuple>::type;
}

#endif // MPLEX_TUPLE_BACK_HPP_INCLUDED
