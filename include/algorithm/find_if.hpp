#ifndef MPLEX_ALGORITHM_FIND_IF_HPP_INCLUDED
#define MPLEX_ALGORITHM_FIND_IF_HPP_INCLUDED

#include <tuple>

namespace mplex {
    template <typename Tuple, typename Predicate, typename Pos = int_ <0>, bool abort = false >
    struct find_if { };

    template <typename Predicate, typename Pos, typename T, typename... List>
    struct find_if <std::tuple<T, List...>, Predicate, Pos, false> {
        constexpr static const bool found = Predicate::template apply <T>::value;

        constexpr static const int value = find_if <std::tuple <List...>, Predicate, int_ <Pos::value + 1>, found>::value;
        using type = int_ <value>;
    };

    template <typename Tuple, typename Predicate, typename Pos>
    struct find_if <Tuple, Predicate, Pos, true> {
        constexpr static const int value = Pos::value - 1;
        using type = int_ <value>;
    };

    template <typename Predicate, typename Pos>
    struct find_if <std::tuple <>, Predicate, Pos, false> {
        constexpr static const int value = -1;
        using type = int_ <value>;
    };

    template <typename Tuple, typename Predicate>
    using find_if_t = typename find_if <Tuple, Predicate>::type;
}

#endif // MPLEX_TUPLE_FIND_IF_HPP_INCLUDED
