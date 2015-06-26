#ifndef COPY_H_INCLUDED
#define COPY_H_INCLUDED

#include "push_back.hpp"

#include <tuple>

namespace mplex {
    template <typename Tuple, unsigned From, unsigned To>
    struct copy { };

    template <unsigned From, unsigned To, typename T, typename ... List>
    struct copy <std::tuple <T, List...>, From, To> {

        static_assert (To <= std::tuple_size <std::tuple<T, List...>>::value, "Out of range");
        static_assert (From < To, "Range is malformed. end >= begin");

        using type = typename copy <std::tuple <List...>, From-1, To>::type;
    };

    template <unsigned To, typename T, typename ... List>
    struct copy <std::tuple <T, List...>, 0, To> {

        static_assert (To <= std::tuple_size <std::tuple<T, List...>>::value, "Out of range");

        using type = push_back_t <typename copy <std::tuple <T, List...>, 0, To-1>::type, T>;
    };

    template <typename Tuple>
    struct copy <Tuple, 0, 0> {
        using type = std::tuple<>;
    };

    template <typename Tuple, unsigned From, unsigned To>
    using copy_t = typename copy <Tuple, From, To>::type;
}

#endif // COPY_H_INCLUDED
