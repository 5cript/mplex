#ifndef MPLEX_TUPLE_FRONT_HPP_INCLUDED
#define MPLEX_TUPLE_FRONT_HPP_INCLUDED

#include <tuple>

namespace mplex
{
    /** @param Tuple A tuple.
     *
     *  @return The first element of the tuple.
     */
    template <typename Tuple>
    struct front {
        static_assert (std::tuple_size <Tuple>::value > 0, "Tuple must not be empty");

        using type = typename std::tuple_element <0, Tuple>::type;
    };

    struct front_a {
        template <typename Tuple>
        struct apply {
            using type = typename front <Tuple>::type;
        };
    };

    template <typename Tuple>
    using front_t = typename front <Tuple>::type;
}

#endif // MPLEX_TUPLE_FRONT_HPP_INCLUDED
