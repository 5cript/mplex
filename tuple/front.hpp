#ifndef FRONT_HPP_INCLUDED
#define FRONT_HPP_INCLUDED

#include <tuple>

namespace mplex
{
    template <typename TupleT>
    struct front {
        using type = typename std::tuple_element<0, TupleT>::type;
    };

    template <>
    struct front <std::tuple<>> {
        // this is an invalid request
    };

    template <typename TupleT>
    using front_t = typename front<TupleT>::type;
}

#endif // FRONT_HPP_INCLUDED
