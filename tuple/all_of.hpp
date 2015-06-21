#ifndef ALL_OF_HPP_INCLUDED
#define ALL_OF_HPP_INCLUDED

#include <tuple>
#include "../integral.hpp"

namespace mplex
{

    /** @param Tuple A tuple.
     *  @param Predicate A predicate returning true/false via ::value.
     *  @param Abort Internal.
     *
     *  @return boolean via value.
     */
    template <typename Tuple, template <typename> class Predicate, bool Abort = false>
    struct all_of { };

    template <template <typename> class Predicate, typename T, typename ... List>
    struct all_of <std::tuple <T, List...>, Predicate, false>
    {
        enum
        {
            value = Predicate <T>::value * all_of <std::tuple <List...>, Predicate, !Predicate <T>::value>::value
        };
    };

    template <template <typename> class Predicate, typename T, typename ... List>
    struct all_of <std::tuple <T, List...>, Predicate, true>
    {
        enum
        {
            value = 0
        };
    };

    template <template <typename> class Predicate, bool Abort>
    struct all_of <std::tuple <>, Predicate, Abort>
    {
        enum
        {
            value = 1
        };
    };

    template <typename Tuple, template <typename> class Predicate>
    using all_of_t = typename all_of <Tuple, Predicate>::type;
}

#endif // ALL_OF_HPP_INCLUDED
