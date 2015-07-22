#ifndef MPLEX_ALGORITHM_ONE_OF_HPP_INCLUDED
#define MPLEX_ALGORITHM_ONE_OF_HPP_INCLUDED

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
    struct one_of { };

    template <typename Predicate, typename T, typename... List>
    struct one_of <std::tuple <T, List...>, Predicate, false> {
        constexpr static const bool value = Predicate::template apply <T>::value
                                            | one_of <std::tuple <List...>, Predicate, Predicate::template apply <T>::value>::value;
    };

    template <typename TupleT, typename Predicate>
    struct one_of <TupleT, Predicate, true /* abort */> {
        constexpr static const bool value = true;
    };

    template <typename Predicate>
    struct one_of <std::tuple <>, Predicate, false> {
        constexpr static const bool value = false;
    };
}

#endif // MPL14_TUPLE_ONE_OF_HPP_INCLUDED
