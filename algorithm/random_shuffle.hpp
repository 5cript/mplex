#ifndef MPLEX_ALGORITHM_RANDOM_SHUFFLE_HPP_INCLUDED
#define MPLEX_ALGORITHM_RANDOM_SHUFFLE_HPP_INCLUDED

#include "../random/linear_congruential_engine.hpp"
#include "../random/uniform_int_distribution.hpp"
#include "../control/if.hpp"
#include "../tuple/element_swap.hpp"

#include <tuple>

/**
 *  for i = size-1; i != 1; --1
 *      j = random(0, i)
 *      swap(a[j], a[i])
 */

/*
namespace mplex
{
    template <typename Tuple, typename RandomEngine, typename Result = std::tuple<>>
    struct random_shuffle { };

    template <typename RandomEngine, typename Result, typename T, typename... List>
    struct random_shuffle <std::tuple<T, List...>, RandomEngine, Result>
    {
        enum {
            rand = random::uniform_int_distribution <long long, RandomEngine::value, 0, sizeof...(List)-1>::value
        };

        using type =
        typename random_shuffle <std::tuple <List...>,
                                 typename RandomEngine::next,
                                 element_swap_t <std::tuple <T, List...>, rand, sizeof...(List)-1>>::type;
    };

    template <typename RandomEngine, typename Result>
    struct random_shuffle <std::tuple<>, RandomEngine, Result>
    {
        using type = Result;
    };

    template <typename Tuple, typename RandomEngine>
    using random_shuffle_t = typename random_shuffle <Tuple, RandomEngine>::type;
}
*/

#endif // MPL14_TUPLE_RANDOM_SHUFFLE_HPP_INCLUDED
