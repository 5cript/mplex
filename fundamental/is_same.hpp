#ifndef IS_SAME_HPP_INCLUDED
#define IS_SAME_HPP_INCLUDED

#include <type_traits>
#include "integral.hpp"

namespace mplex {
    struct is_same {
        template <typename T, typename U>
        struct apply {
            using type = bool_ <std::is_same<T, U>::value>;
        };
    };
}

#endif // IS_SAME_HPP_INCLUDED
