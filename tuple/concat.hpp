#ifndef CONCAT_HPP_INCLUDED
#define CONCAT_HPP_INCLUDED

#include <tuple>

namespace mplex
{
    /** @param Tuple A tuple.
     *  @param Tuple A tuple.
     *
     *  @return A concatenation of both tuples
     */
    template <typename, typename>
    struct concat
    {
    };

    template <typename ... Ts, typename ... Us>
    struct concat <std::tuple <Ts...>, std::tuple <Us...>>
    {
        using type = std::tuple <Ts..., Us...>;
    };

    template <typename T, typename U>
    using concat_t = typename concat <T, U>::type;
}

#endif // CONCAT_HPP_INCLUDED
