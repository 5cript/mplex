#ifndef MPLEX_ALGORITHM_TRANSFORM_HPP_INCLUDED
#define MPLEX_ALGORITHM_TRANSFORM_HPP_INCLUDED

#include <tuple>

namespace mplex
{

    /** @param Tuple A tuple.
     *  @param Predicate A transformation predicate.
     *
     *  @return std::tuple<Predicate<TupleElements>::type...>
     */
    template <typename Tuple, typename Predicate>
    struct transform
    { };

    template <typename Predicate, typename... List>
    struct transform <std::tuple < List...>, Predicate> {
        using type = std::tuple <typename Predicate::template apply <List>::type...>;
    };

    template <typename Tuple, typename Predicate>
    using transform_t = typename transform <Tuple, Predicate>::type;
}

#endif // MPLEX_TUPLE_TRANSFORM_HPP_INCLUDED
