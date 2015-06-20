#ifndef BACK_HPP_INCLUDED
#define BACK_HPP_INCLUDED

#include <tuple>

namespace mplex
{
    /** @param Tuple A tuple.
     *
     *  @return The last element.
     */
    template <typename TupleT>
    struct back {
        using type = typename std::tuple_element <std::tuple_size<TupleT>::value - 1, TupleT>::type;
    };

    template <>
    struct back <std::tuple<>> {
        // invalid request
    };

    template <typename TupleT>
    using back_t = typename back<TupleT>::type;
}

#endif // BACK_HPP_INCLUDED
