#ifndef MPLEX_ALGORITHM_ALL_OF_HPP_INCLUDED
#define MPLEX_ALGORITHM_ALL_OF_HPP_INCLUDED

#include "../fundamental/integral.hpp"
#include <tuple>

namespace mplex
{

    /** @param Tuple A tuple.
     *  @param Predicate A predicate returning true/false via ::value.
     *  @param Abort Internal.
     *
     *  @return boolean via value.
     */
    template <typename Tuple, typename Predicate, bool Abort = false>
    struct all_of { };

    template <typename Predicate, typename T, typename... List>
    struct all_of <std::tuple <T, List...>, Predicate, false> {
        enum {
            value = Predicate::template apply <T>::value * all_of <std::tuple <List...>, Predicate, !Predicate::template apply <T>::value>::value
        };
    };

    template <typename Predicate, typename T, typename... List>
    struct all_of <std::tuple <T, List...>, Predicate, true> {
        enum {
            value = 0
        };
    };

    template <typename Predicate, bool Abort>
    struct all_of <std::tuple <>, Predicate, Abort> {
        enum {
            value = 1
        };
    };

    template <typename Tuple, typename Predicate>
    using all_of_t = typename all_of <Tuple, Predicate>::type;
}

#endif // MPLEX_TUPLE_ALL_OF_HPP_INCLUDED
