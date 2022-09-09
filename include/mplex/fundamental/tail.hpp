#ifndef TAIL_HPP_INCLUDED
#define TAIL_HPP_INCLUDED

#include <tuple>

namespace mplex {
    struct tail {
        template <typename, typename... Tail>
        struct apply {
            using type = std::tuple <Tail...>;
        };
    };
}

#endif // TAIL_HPP_INCLUDED
