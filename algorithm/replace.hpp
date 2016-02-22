#ifndef MPLEX_ALGORITHM_REPLACE_HPP_INCLUDED
#define MPLEX_ALGORITHM_REPLACE_HPP_INCLUDED

#include "../tuple/push_back.hpp"

namespace mplex {
    template <typename Tuple, typename Predicate>
    struct replace_each
    { };

    template <typename Predicate, typename T, typename... List>
    struct replace_each <std::tuple <T, List...>, Predicate> {
        using repl = typename Predicate::template apply <T>::type;

        using type = push_back_t <typename replace_each <std::tuple <List...>, Predicate>::type, repl>;
    };

    template <typename Predicate>
    struct replace_each <std::tuple <>, Predicate> {
        using type = std::tuple <>;
    };

    template <typename Tuple, typename Predicate>
    using replace_each_t = typename replace_each <Tuple, Predicate>::type;
}

#endif // REPLACE_HPP_INCLUDED
