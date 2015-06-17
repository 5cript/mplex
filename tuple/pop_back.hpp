#ifndef POP_BACK_HPP_INCLUDED
#define POP_BACK_HPP_INCLUDED

#include "concat.hpp"
#include <tuple>

namespace mplex
{
    template <typename TupleT>
    struct pop_back {
    };

    template <>
    struct pop_back <std::tuple<>> {
        using type = std::tuple<>;
    };

    template <typename T>
    struct pop_back <std::tuple<T>> {
        using type = std::tuple<>;
    };

    template <typename T, typename ... List>
    struct pop_back<std::tuple<T, List...>>
    {
        using type = concat_t<std::tuple<T>, typename pop_back<std::tuple<List...>>::type>;
    };

    template <typename TupleT>
    using pop_back_t = typename pop_back<TupleT>::type;
}

#endif // POP_BACK_HPP_INCLUDED
