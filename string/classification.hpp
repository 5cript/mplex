#ifndef MPLEX_STRING_CHAR_TRAITS_HPP_INCLUDED
#define MPLEX_STRING_CHAR_TRAITS_HPP_INCLUDED

#include "char.hpp"
#include "../control/if.hpp"
#include "../fundamental/integral.hpp"

namespace mplex {
    struct is_space {
        template <typename Char>
        struct apply {
            constexpr static const bool value = false;
            using type = bool_ <value>;
        };
    };

    #define SPECIALIZE(WHAT, CHAR) \
    template <> \
    struct WHAT::apply <char_<CHAR>> { \
        constexpr static const bool value = true; \
    }

    SPECIALIZE(is_space, ' ');
    SPECIALIZE(is_space, '\n');
    SPECIALIZE(is_space, '\r');
    SPECIALIZE(is_space, '\t');
    SPECIALIZE(is_space, '\v');
    SPECIALIZE(is_space, '\f');

    #undef is_space_SPECIALIZE

    struct is_upper {
        template <typename Char>
        struct apply {
            constexpr static const bool value = Char::value >= 'A' && Char::value <= 'Z';
            using type = bool_ <value>;
        };
    };

    struct is_lower {
        template <typename Char>
        struct apply {
            constexpr static const bool value = Char::value >= 'a' && Char::value <= 'z';
            using type = bool_ <value>;
        };
    };

    struct is_cntrl {
        template <typename Char>
        struct apply {
            constexpr static const bool value = Char::value >= 0 && Char::value < 32;
            using type = bool_ <value>;
        };
    };

    struct is_blank {
        template <typename Char>
        struct apply {
            constexpr static const bool value = false;
            using type = bool_ <value>;
        };
    };
    SPECIALIZE(is_blank, ' ');
    SPECIALIZE(is_blank, '\t');

    struct is_alpha {
        template <typename Char>
        struct apply {
            constexpr static const bool value = is_upper::template apply <Char>::value || is_lower::template apply <Char>::value;
            using type = bool_ <value>;
        };
    };

    struct is_digit {
        template <typename Char>
        struct apply {
            constexpr static const bool value = Char::value >= '0' && Char::value <= '9';
            using type = bool_ <value>;
        };
    };

    struct is_xdigit {
        template <typename Char>
        struct apply {
            constexpr static const bool value =     is_digit::template apply <Char>::value
                                                ||  (Char::value >= 'A' && Char::value <= 'f')
                                                ||  (Char::value >= 'a' && Char::value <= 'z');
            using type = bool_ <value>;
        };
    };

    struct is_alnum {
        template <typename Char>
        struct apply {
            constexpr static const bool value =     is_digit::template apply <Char>::value
                                                ||  is_alpha::template apply <Char>::value;
            using type = bool_ <value>;
        };
    };

    struct is_punct {
        template <typename Char>
        struct apply {
            constexpr static const bool value =     (Char::value >= '!' && Char::value <= '/') // 0x21 - 0x2F
                                                ||  (Char::value >= ':' && Char::value <= '@') // 0x3A - 0x40
                                                ||  (Char::value >= '[' && Char::value <= '`') // 0x5B - 0x60
                                                ||  (Char::value >= '{' && Char::value <= '~'); // 0x7B - 0x7E
            using type = bool_ <value>;
        };
    };

    struct is_graph {
        template <typename Char>
        struct apply {
            constexpr static const bool value = Char::value >= 0x21 && Char::value <= 0x7E;
            using type = bool_ <value>;
        };
    };

    struct is_print {
        template <typename Char>
        struct apply {
            constexpr static const bool value = Char::value >= 0x20 && Char::value <= 0x7E;
            using type = bool_ <value>;
        };
    };

    struct is_zero {
        template <typename Char>
        struct apply {
            constexpr static const bool value = Char::value == 0;
            using type = bool_ <value>;
        };
    };

    #undef SPECIALIZE
}

#endif // MPLEX_STRING_CHAR_TRAITS_HPP_INCLUDED
