#ifndef MPLEX_TUPLE_POP_FRONT_HPP_INCLUDED
#define MPLEX_TUPLE_POP_FRONT_HPP_INCLUDED

namespace mplex
{
    /** @param Tuple A tuple.
     *
     *  @return The same tuple with one less element at the front
     */
    template <typename T>
    struct pop_front {
    };

    template <typename T, typename... List>
    struct pop_front <std::tuple < T, List...>> {
        using type = std::tuple <List...>;
    };

    template <>
    struct pop_front <std::tuple <>> {
        using type = std::tuple <>;
    };

    template <typename TupleT>
    using pop_front_t = typename pop_front <TupleT>::type;
}

#endif // MPLEX_TUPLE_POP_FRONT_HPP_INCLUDED
