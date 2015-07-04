#ifndef MAKE_TUPLE_HPP_INCLUDED
#define MAKE_TUPLE_HPP_INCLUDED

#include "../fundamental/integral.hpp"
#include "../fundamental/null_type.hpp"
#include "concat.hpp"

namespace mplex {
    namespace generators {
        template <unsigned I>
        struct nulls {
            using type = null_t;
        };

        template <unsigned I>
        struct indices {
            using type = unsigned_ <I>;
        };
    }

    namespace internal {
        template <template <unsigned> class Generator, typename Index, typename Length>
        struct make_tuple_impl {
            using type = concat_t <std::tuple <typename Generator <Length::value - Index::value>::type>,
                                   typename make_tuple_impl <Generator, unsigned_ <Index::value - 1>, Length>::type >;
        };

        template <template <unsigned> class Generator, typename Length>
        struct make_tuple_impl <Generator, unsigned_ <0>, Length> {
            using type = std::tuple <>;
        };
    }

    template <template <unsigned> class Generator = generators::indices>
    struct make_tuple {
        template <typename Length>
        struct apply {
            using type = typename internal::make_tuple_impl <Generator, Length, Length>::type;
        };
    };
}

#endif // MAKE_TUPLE_HPP_INCLUDED
