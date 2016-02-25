#ifndef MPLEX_TUPLE_TUPLE_ELEMENT_HPP_INCLUDED
#define MPLEX_TUPLE_TUPLE_ELEMENT_HPP_INCLUDED

#include <tuple>

namespace mplex {
    struct tuple_element {
        template <typename Index, typename Tuple>
        struct apply {
            using type = typename std::tuple_element <Index::value, Tuple>::type;
        };
    };

}

#endif // MPLEX_TUPLE_TUPLE_ELEMENT_HPP_INCLUDED
