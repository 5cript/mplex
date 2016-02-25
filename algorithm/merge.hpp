#ifndef MPLEX_ALGORITHM_MERGE_HPP_INCLUDED
#define MPLEX_ALGORITHM_MERGE_HPP_INCLUDED

#include "../tuple/push_front.hpp"

#include <tuple>

namespace mplex
{
    /**
     *  Combines two tuples using a wrapper.
     *
     *  merge <std::tuple <short, long, long long>,
     *         std::tuple <float, double, long double>,
     *         std::pair>
     *
     *  will produce
     *
     *  tuple <pair <short, float>, pair <long, double>, pair <long long, long double>>
     */
    template <typename TupleA, typename TupleB, template <typename, typename> class Wrapper>
    struct merge
    { };

    template <typename... ListA, typename... ListB, template <typename, typename> class Wrapper>
    struct merge <std::tuple<ListA...>, std::tuple<ListB...>, Wrapper>
    {
        using type = std::tuple <Wrapper <ListA, ListB>...>;
    };

    template <typename TupleA, typename TupleB, template <typename, typename> class Wrapper>
    using merge_t = typename merge <TupleA, TupleB, Wrapper>::type;
}

#endif // MPLEX_ALGORITHM_MERGE_HPP_INCLUDED
