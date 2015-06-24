#ifndef MPL14_TUPLE_FRONT_HPP_INCLUDED
#define MPL14_TUPLE_FRONT_HPP_INCLUDED

#include <tuple>

namespace mplex
{
    /** @param Tuple A tuple.
     *
     *  @return The first element of the tuple.
     */
    template <typename Tuple>
    struct front {
        using type = typename std::tuple_element <0, Tuple>::type;
    };

    template <>
    struct front <std::tuple <>> {
        // this is an invalid request
    };

    template <typename Tuple>
    using front_t = typename front <Tuple>::type;
}

#endif // MPL14_TUPLE_FRONT_HPP_INCLUDED
