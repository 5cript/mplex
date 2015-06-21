#ifndef ELEMENT_SWAP_HPP_INCLUDED
#define ELEMENT_SWAP_HPP_INCLUDED

#include "../control/if.hpp"
#include "../integral.hpp"
#include "push_front.hpp"

#include <tuple>

namespace mplex
{
    template <typename Tuple, unsigned First, unsigned Second, typename Clone = Tuple, unsigned Index = 0>
    struct element_swap
    { };

    template <typename Tuple, unsigned First, unsigned Second, unsigned Index, typename T, typename ... ReducedList>
    struct element_swap <Tuple, First, Second, std::tuple<T, ReducedList...>, Index>
    {
        static_assert (First < std::tuple_size <Tuple>::value, "Index out of bounds");
        static_assert (Second < std::tuple_size <Tuple>::value, "Index out of bounds");

        using single = if_t <Index == First,
                             integral <unsigned, Second>,
                             if_t <Index == Second,
                                   integral <unsigned, First>,
                                   integral <unsigned, Index>
                                   >
                            >;

        using type = push_front_t <typename element_swap<Tuple, First, Second, std::tuple<ReducedList...>, Index + 1>::type,
                                   typename std::tuple_element <single::value, Tuple>::type>;
    };

    template <typename Tuple, unsigned First, unsigned Second, unsigned Index>
    struct element_swap <Tuple, First, Second, std::tuple<>, Index>
    {
        using type = std::tuple <>;
    };

    template <typename Tuple, unsigned First, unsigned Second>
    using element_swap_t = typename element_swap<Tuple, First, Second>::type;
}

#endif // ELEMENT_SWAP_HPP_INCLUDED
