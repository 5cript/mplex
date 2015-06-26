#ifndef ERASE_HPP_INCLUDED
#define ERASE_HPP_INCLUDED

#include "concat.hpp"
#include "copy.hpp"

#include <tuple>

namespace mplex {
    template <typename Tuple, unsigned From, unsigned To>
    struct erase
    {
        static_assert (To <= std::tuple_size <Tuple>::value, "Out of range");
        static_assert (From < To, "Range is malformed. end >= begin");

        using type = concat_t <copy_t <Tuple, 0, From>, typename erase<typename erase <Tuple, 0, From>::type, 0, To>::type>;
    };

    template <unsigned To, typename T, typename ... List>
    struct erase <std::tuple <T, List...>, 0, To>
    {
        using type = typename erase <std::tuple <List...>, 0, To - 1>::type;
    };

    template <typename Tuple>
    struct erase <Tuple, 0, 0>
    {
        using type = Tuple;
    };

    template <typename Tuple, unsigned From, unsigned To>
    using erase_t = typename erase <Tuple, From, To>::type;
}

#endif // ERASE_HPP_INCLUDED
