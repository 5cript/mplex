#ifndef ONE_OF_HPP_INCLUDED
#define ONE_OF_HPP_INCLUDED

namespace mplex {

    /** @param Tuple A tuple.
     *  @param Predicate A predicate returning true/false via ::value.
     *  @param Abort Internal.
     *
     *  @return boolean via value.
     */
    template <typename Tuple, template <typename> class Predicate, bool Abort = false>
    struct one_of { };

    template <template <typename> class Predicate, typename T, typename ... List>
    struct one_of <std::tuple <T, List...>, Predicate, false> {
        constexpr static const bool value = Predicate<T>::value
                                          | one_of<std::tuple<List...>, Predicate, Predicate<T>::value>::value;
    };

    template <typename TupleT, template <typename> class Predicate>
    struct one_of <TupleT, Predicate, true /* abort */> {
        constexpr static const bool value = true;
    };

    template <template <typename> class Predicate>
    struct one_of <std::tuple<>, Predicate, false> {
        constexpr static const bool value = false;
    };
}

#endif // ONE_OF_HPP_INCLUDED
