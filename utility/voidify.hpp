#ifndef VOID_HPP_INCLUDED
#define VOID_HPP_INCLUDED

#include "../fundamental/null_type.hpp"

namespace mplex {
    template <typename...>
    struct voidifiy {
        using type = null_t;
    };
}

#endif // VOID_HPP_INCLUDED
