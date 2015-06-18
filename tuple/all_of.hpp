#ifndef ALL_OF_HPP_INCLUDED
#define ALL_OF_HPP_INCLUDED

#include <tuple>

namespace mplex {
    template <typename Tuple, template <typename> class Predicate, bool abort = false>
    struct all_of { };

    template <template <typename> class Predicate, typename T, typename ... List>
    struct all_of <std::tuple <T, List...>, Predicate, false> {
        enum {
            value = Predicate<T>::value * all_of<std::tuple<List...>, Predicate, !Predicate<T>::value>::value
        };
    };

    template <template <typename> class Predicate, typename T, typename ... List>
    struct all_of <std::tuple <T, List...>, Predicate, true> {
        enum {
            value = 0
        };
    };

    template <template <typename> class Predicate, bool abort>
    struct all_of <std::tuple <>, Predicate, abort> {
        enum {
            value = 1
        };
    };
}

#endif // ALL_OF_HPP_INCLUDED
