#ifndef MPLEX_ALGORITHM_MERGE_HPP_INCLUDED
#define MPLEX_ALGORITHM_MERGE_HPP_INCLUDED

#include "../tuple/push_front.hpp"

#include <tuple>

namespace mplex
{
    template <typename TupleA, typename TupleB, template <typename, typename> class Wrapper>
    struct merge
    { };

    template <typename TA, typename... TailA, typename TB, typename... TailB, template <typename, typename> class Wrapper>
    struct merge <std::tuple <TA, TailA...>, std::tuple <TB, TailB...>, Wrapper>
    {
        using type = push_front_t <typename merge <std::tuple <TailA...>, std::tuple <TailB...>, Wrapper>::type,
                                   Wrapper <TA, TB> >;
    };

    template <template <typename, typename> class Wrapper>
    struct merge <std::tuple<>, std::tuple<>, Wrapper>
    {
        using type = std::tuple <>;
    };

    template <typename TupleA, typename TupleB, template <typename, typename> class Wrapper>
    using merge_t = typename merge <TupleA, TupleB, Wrapper>::type;
}

#endif // MPLEX_ALGORITHM_MERGE_HPP_INCLUDED
