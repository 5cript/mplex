#ifndef CHAR_TRAITS_HPP_INCLUDED
#define CHAR_TRAITS_HPP_INCLUDED

#include "char.hpp"

namespace mplex { namespace char_traits {
    template <typename Char>
    struct is_whitespace {
        constexpr static const bool value = false;
    };

    #define IS_WHITESPACE_SPECIALIZE(CHAR) \
    template <> \
    struct is_whitespace <char_<CHAR>> { \
        constexpr static const bool value = true; \
    }

    IS_WHITESPACE_SPECIALIZE(' ');
    IS_WHITESPACE_SPECIALIZE('\n');
    IS_WHITESPACE_SPECIALIZE('\r');
    IS_WHITESPACE_SPECIALIZE('\t');

    #undef IS_WHITESPACE_SPECIALIZE
}
}

#endif // CHAR_TRAITS_HPP_INCLUDED
