#ifndef MPL14_STRING_CHAR_TRAITS_HPP_INCLUDED
#define MPL14_STRING_CHAR_TRAITS_HPP_INCLUDED

#include "char.hpp"
#include "../control/if.hpp"
#include "../integral.hpp"

namespace mplex {
    template <typename Char>
    struct is_space {
        constexpr static const bool value = false;
    };

    #define SPECIALIZE(WHAT, CHAR) \
    template <> \
    struct WHAT <char_<CHAR>> { \
        constexpr static const bool value = true; \
    }

    SPECIALIZE(is_space, ' ');
    SPECIALIZE(is_space, '\n');
    SPECIALIZE(is_space, '\r');
    SPECIALIZE(is_space, '\t');
    SPECIALIZE(is_space, '\v');
    SPECIALIZE(is_space, '\f');

    #undef is_space_SPECIALIZE

    template <typename Char>
    struct is_upper {
        constexpr static const bool value = Char::value >= 'A' && Char::value <= 'Z';
    };

    template <typename Char>
    struct is_lower {
        constexpr static const bool value = Char::value >= 'a' && Char::value <= 'z';
    };

    template <typename Char>
    struct is_cntrl {
        constexpr static const bool value = Char::value >= 0 && Char::value < 32;
    };

    template <typename Char>
    struct is_blank {
        constexpr static const bool value = false;
    };
    SPECIALIZE(is_blank, ' ');
    SPECIALIZE(is_blank, '\t');

    template <typename Char>
    struct is_alpha {
        constexpr static const bool value = is_upper <Char>::value || is_lower <Char>::value;
    };

    template <typename Char>
    struct is_digit {
        constexpr static const bool value = Char::value >= '0' && Char::value <= '9';
    };

    template <typename Char>
    struct is_xdigit {
        constexpr static const bool value =     is_digit<Char>::value
                                            ||  (Char::value >= 'A' && Char::value <= 'f')
                                            ||  (Char::value >= 'a' && Char::value <= 'z');
    };

    template <typename Char>
    struct is_alnum {
        constexpr static const bool value =     is_digit<Char>::value
                                            ||  is_alpha<Char>::value;
    };

    template <typename Char>
    struct is_punct {
        constexpr static const bool value =     Char::value >= '!' && Char::value <= '/' // 0x21 - 0x2F
                                            ||  Char::value >= ':' && Char::value <= '@' // 0x3A - 0x40
                                            ||  Char::value >= '[' && Char::value <= '`' // 0x5B - 0x60
                                            ||  Char::value >= '{' && Char::value <= '~'; // 0x7B - 0x7E
    };

    template <typename Char>
    struct is_graph {
        constexpr static const bool value = Char::value >= 0x21 && Char::value <= 0x7E;
    };

    template <typename Char>
    struct is_print {
        constexpr static const bool value = Char::value >= 0x20 && Char::value <= 0x7E;
    };
}

#endif // MPL14_STRING_CHAR_TRAITS_HPP_INCLUDED
