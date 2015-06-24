#ifndef MPL14_TUPLE_TRANSFORM_HPP_INCLUDED
#define MPL14_TUPLE_TRANSFORM_HPP_INCLUDED

namespace mplex
{

    /** @param Tuple A tuple.
     *  @param Transformer A transformation predicate.
     *
     *  @return std::tuple<Transformer<TupleElements>::type...>
     */
    template <typename Tuple, template <typename> class Transformer>
    struct transform
    { };

    template <template <typename> class Transformer, typename ... List>
    struct transform <std::tuple < List...>, Transformer> {
        using type = std::tuple <typename Transformer <List>::type...>;
    };

    template <typename Tuple, template <typename> class Transformer>
    using transform_t = typename transform <Tuple, Transformer>::type;
}

#endif // MPL14_TUPLE_TRANSFORM_HPP_INCLUDED
