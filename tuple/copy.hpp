#ifndef MPL14_TUPLE_COPY_H_INCLUDED
#define MPL14_TUPLE_COPY_H_INCLUDED

#include "push_back.hpp"
#include "push_front.hpp"
#include "pop_front.hpp"

#include <tuple>

#include "../fundamental/integral.hpp"

namespace mplex {
    template <typename Tuple, typename Begin, typename End, bool ambiguity_kill = false>
    struct copy { };

    template <typename Begin, typename End, typename T, typename... List>
    struct copy <std::tuple <T, List...>, Begin, End, false> {

        static_assert (End::value <= 1 + sizeof...(List), "Out of range (End ist too large)");
        static_assert (Begin::value < End::value, "Range is malformed. end >= begin");

        using type = typename copy <std::tuple <List...>, unsigned_<Begin::value - 1>, unsigned_<End::value - 1>>::type;
    };

    template <typename End, typename T, typename... List>
    struct copy <std::tuple <T, List...>, unsigned_<0u>, End, false> {

        using Tuple = std::tuple <List...>;

        static_assert (End::value <= 1 + sizeof...(List), "Out of range (End ist Endo large)");

        using type = push_front_t <typename copy <Tuple, unsigned_<0u>, unsigned_<End::value - 1>, End::value == 1>::type,
                                   T>;
    };

    template <typename... List>
    struct copy <std::tuple<List...>, unsigned_<0u>, unsigned_<0u>, true> {

        using type = std::tuple<>;
    };

    template <typename Tuple, typename Begin, typename End>
    using copy_t = typename copy <Tuple, Begin, End>::type;

    template <typename Tuple, unsigned Begin, unsigned End>
    using copy_vt = typename copy <Tuple, unsigned_<Begin>, unsigned_<End>>::type;
}

#endif // MPL14_TUPLE_COPY_H_INCLUDED
