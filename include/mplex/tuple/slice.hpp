#pragma once

namespace mplex
{
    namespace internal
    {
        template <typename TupleT, unsigned Offset, typename Sequence>
        struct slice_impl
        {};

        template <typename TupleT, unsigned Offset, unsigned... I>
        struct slice_impl <TupleT, Offset, std::integer_sequence <unsigned, I...> >
        {
            using type = std::tuple <typename std::tuple_element <I + Offset, TupleT>::type...>;
        };
    }

    template <typename TupleT, typename Amount>
    struct slice_front
    {
        using type = typename internal::slice_impl <TupleT, 0, std::make_integer_sequence <unsigned, Amount::value> >::type;
    };

    template <typename TupleT, typename Amount>
    struct slice_back
    {
        using type = typename internal::slice_impl <TupleT, std::tuple_size <TupleT>::value - Amount::value, std::make_integer_sequence <unsigned, Amount::value> >::type;
    };

    template <typename TupleT, typename Amount>
    using slice_back_t = typename slice_back <TupleT, Amount>::type;

    template <typename TupleT, typename Amount>
    using slice_front_t = typename slice_front <TupleT, Amount>::type;
}
