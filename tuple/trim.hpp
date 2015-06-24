#ifndef TUPLE_TRIM_HPP_INCLUDED
#define TUPLE_TRIM_HPP_INCLUDED

#include <tuple>
#include "pop_back.hpp"

namespace mplex {
    template <typename Tuple, template <typename> class Predicate, bool Abort = false>
    struct trim_left
    { };

    template <template <typename> class Predicate, typename T, typename ... List>
    struct trim_left <std::tuple <T, List...>, Predicate, false> {
        using type = if_t <Predicate <T>::value,
                           typename trim_left <std::tuple<List...>, Predicate, !Predicate<T>::value>::type,
                           std::tuple <T, List...>>;
    };

    template <template <typename> class Predicate>
    struct trim_left <std::tuple <>, Predicate, false> {
        using type = std::tuple <>;
    };

    template <typename Tuple, template <typename> class Predicate>
    struct trim_left <Tuple, Predicate, true> {
        using type = Tuple;
    };

    template <typename Tuple, template <typename> class Predicate>
    using trim_left_t = typename trim_left <Tuple, Predicate>::type;


    template <typename Tuple, template <typename> class Predicate, bool Abort = false>
    struct trim_right {
        // Abort == false
        using type = if_t <Predicate<typename std::tuple_element <std::tuple_size <Tuple>::value - 1, Tuple>::type>::value,
                           typename trim_right <pop_back_t<Tuple>, Predicate>::type,
                           Tuple>;
    };

    template <typename Tuple, template <typename> class Predicate>
    struct trim_right <Tuple, Predicate, true> {
        using type = Tuple;
    };

    template <template <typename> class Predicate>
    struct trim_right <std::tuple <>, Predicate, false> {
        using type = std::tuple <>;
    };

    template <typename Tuple, template <typename> class Predicate>
    using trim_right_t = typename trim_right <Tuple, Predicate>::type;

    template <typename Tuple, template <typename> class Predicate>
    struct trim {
        using type = trim_right_t <trim_left_t <Tuple, Predicate>, Predicate>;
    };

    template <typename Tuple, template <typename> class Predicate>
    using trim_t = typename trim <Tuple, Predicate>::type;
}

#endif // TRIM_HPP_INCLUDED
