#ifndef MPLEX_TUPLE_TUPLE_TRIM_HPP_INCLUDED
#define MPLEX_TUPLE_TUPLE_TRIM_HPP_INCLUDED

#include <tuple>
#include "pop_back.hpp"

namespace mplex {
    template <typename Tuple, typename Predicate, bool Abort = false>
    struct trim_left
    { };

    template <typename Predicate, typename T, typename... List>
    struct trim_left <std::tuple <T, List...>, Predicate, false> {
        using type = if_vt <Predicate::template apply <T>::value,
                            typename trim_left <std::tuple<List...>, Predicate, !Predicate::template apply<T>::value>::type,
                            std::tuple <T, List...>>;
    };

    template <typename Predicate>
    struct trim_left <std::tuple <>, Predicate, false> {
        using type = std::tuple <>;
    };

    template <typename Tuple, typename Predicate>
    struct trim_left <Tuple, Predicate, true> {
        using type = Tuple;
    };

    template <typename Tuple, typename Predicate>
    using trim_left_t = typename trim_left <Tuple, Predicate>::type;


    template <typename Tuple, typename Predicate, bool Abort = false>
    struct trim_right {
        // Abort == false
        using type = if_vt <Predicate::template apply <typename std::tuple_element <std::tuple_size <Tuple>::value - 1, Tuple>::type>::value,
                            typename trim_right <pop_back_t<Tuple>, Predicate>::type,
                            Tuple>;
    };

    template <typename Tuple, typename Predicate>
    struct trim_right <Tuple, Predicate, true> {
        using type = Tuple;
    };

    template <typename Predicate>
    struct trim_right <std::tuple <>, Predicate, false> {
        using type = std::tuple <>;
    };

    template <typename Tuple, typename Predicate>
    using trim_right_t = typename trim_right <Tuple, Predicate>::type;

    template <typename Tuple, typename Predicate>
    struct trim {
        using type = trim_right_t <trim_left_t <Tuple, Predicate>, Predicate>;
    };

    template <typename Tuple, typename Predicate>
    using trim_t = typename trim <Tuple, Predicate>::type;
}

#endif // MPLEX_TUPLE_TRIM_HPP_INCLUDED
