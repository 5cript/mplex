#ifndef HEAD_HPP_INCLUDED
#define HEAD_HPP_INCLUDED

namespace mplex {
    struct head {
        template <typename T, typename ...>
        struct apply {
            using type = T;
        };
    };
}

#endif // HEAD_HPP_INCLUDED
