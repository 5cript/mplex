#ifndef MPLEX_ALGORITHM_REPLACE_IF_HPP_INCLUDED
#define MPLEX_ALGORITHM_REPLACE_IF_HPP_INCLUDED

#include "../tuple/push_back.hpp"
#include "../fundamental/identity.hpp"

#include <tuple>

namespace mplex {

    /**
     *  @param Tuple std::tuple<...>
     *  @param IfPredicate Accesses IfPredicate.apply<T>.value
     *  @param ReplacePredicate Accesses ReplacePredicate.apply<T>.type
     */
    template <typename Tuple, typename IfPredicate, typename ReplacePredicate>
    struct replace_if
    { };

    template <typename IfPredicate, typename ReplacePredicate, typename T, typename... List>
    struct replace_if <std::tuple <T, List...>, IfPredicate, ReplacePredicate>
    {
        using repl = typename if_vt <IfPredicate::template apply <T>::value,
                                     typename ReplacePredicate::template apply <T>,
                                     identity <T> >::type;

        using type = push_back_t <typename replace_if <std::tuple <List...>, IfPredicate, ReplacePredicate>::type, repl>;
    };

    template <typename IfPredicate, typename ReplacePredicate>
    struct replace_if <std::tuple <>, IfPredicate, ReplacePredicate> {
        using type = std::tuple <>;
    };

    template <typename Tuple, typename IfPredicate, typename ReplacePredicate>
    using replace_if_t = typename replace_if <Tuple, IfPredicate, ReplacePredicate>::type;
}

#endif // MPL14_TUPLE_REPLACE_IF_HPP_INCLUDED
