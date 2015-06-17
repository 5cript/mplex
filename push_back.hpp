#ifndef PUSH_BACK_HPP_INCLUDED
#define PUSH_BACK_HPP_INCLUDED

#include <tuple>
#include "apply.hpp"

namespace mplex
{
    template <typename TupleT, typename ElemT>
    struct push_back {
    };

    template <typename ElemT, typename ... List>
    struct push_back <std::tuple<List...>, ElemT> {
        using type = std::tuple<List..., ElemT>;
    };

    template <typename TupleT, typename ElemT>
    using push_back_t = typename push_back<TupleT, ElemT>::type;
}

#endif // PUSH_BACK_HPP_INCLUDED
