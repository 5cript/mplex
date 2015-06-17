#ifndef PUSH_FRONT_HPP_INCLUDED
#define PUSH_FRONT_HPP_INCLUDED

#include <tuple>

namespace mplex
{
    template <typename TupleT, typename ElemT>
    struct push_front {
    };

    template <typename ElemT, typename ... List>
    struct push_front <std::tuple<List...>, ElemT> {
        using type = std::tuple<ElemT, List...>;
    };

    template <typename TupleT, typename ElemT>
    using push_front_t = typename push_front<TupleT, ElemT>::type;
}

#endif // PUSH_FRONT_HPP_INCLUDED
