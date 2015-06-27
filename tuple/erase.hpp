#ifndef MPL14_TUPLE_ERASE_HPP_INCLUDED
#define MPL14_TUPLE_ERASE_HPP_INCLUDED

#include "concat.hpp"
#include "copy.hpp"
#include "pop_front.hpp"

#include <tuple>

namespace mplex {
    template <typename Tuple, typename Begin, typename End>
    struct erase
    {
        static_assert (End::value <= std::tuple_size <Tuple>::value, "Out of range");
        static_assert (Begin::value < End::value, "Range is malformed. end >= begin");

        using type = concat_t <copy_t <Tuple, unsigned_<0u>, Begin>, typename erase<typename erase <Tuple, unsigned_<0>, Begin>::type, unsigned_<0>, unsigned_ <End::value - Begin::value>>::type>;
    };

    template <typename Tuple, typename End>
    struct erase <Tuple, unsigned_<0>, End>
    {
        using type = typename erase <pop_front_t <Tuple>, unsigned_<0>, unsigned_ <End::value - 1>>::type;
    };

    template <typename Tuple>
    struct erase <Tuple, unsigned_<0>, unsigned_<0>>
    {
        using type = Tuple;
    };

    template <typename Tuple, typename Begin, typename End>
    using erase_t = typename erase <Tuple, Begin, End>::type;

    template <typename Tuple, unsigned Begin, unsigned End>

    using erase_vt = typename erase <Tuple, unsigned_<Begin>, unsigned_<End>>::type;
}

#endif // MPL14_TUPLE_ERASE_HPP_INCLUDED
