#ifndef MPLEX_ALGORITHM_COUNT_HPP_INCLUDED
#define MPLEX_ALGORITHM_COUNT_HPP_INCLUDED

#include "../fundamental/integral.hpp"
#include "../control/if.hpp"

#include <tuple>

namespace mplex
{
    template <typename Tuple, typename Predicate>
    struct count
    { };

    template <typename T, typename... List, typename Predicate>
    struct count <std::tuple <T, List...>, Predicate> {
        constexpr static const unsigned value = count <std::tuple <List...>, Predicate>::value +
                                                if_t <typename Predicate::template apply <T>::type, int_<1>, int_<0>>::value;
        using type = unsigned_ <value>;
    };

    template <typename Predicate>
    struct count <std::tuple <>, Predicate> {
        constexpr static const unsigned value = 0;
        using type = unsigned_ <0>;
    };

    template <typename Tuple, typename Predicate>
    using count_t = typename count <Tuple, Predicate>::type;
}

#endif // COUNT_HPP_INCLUDED
