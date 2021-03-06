#ifndef MPLEX_STRING_CHAR_HPP_INCLUDED
#define MPLEX_STRING_CHAR_HPP_INCLUDED

#include "../control/if.hpp"
#include "../fundamental/integral.hpp"
#include "../config.hpp"

namespace mplex
{
    MPLEX_DECLARE_INTEGRAL(char);
    MPLEX_DECLARE_INTEGRAL_N(unsigned char, unsigned_char);

    MPLEX_DECLARE_INTEGRAL(wchar_t);

#ifdef UTF_CHAR
    MPLEX_DECLARE_INTEGRAL(char16_t);
    MPLEX_DECLARE_INTEGRAL(char32_t);
#endif

    struct to_upper {
        template <typename Char>
        struct apply {
            using type =
            if_vt <Char::value >= 'a' && Char::value <= 'z',
                   char_<(char)((int)Char::value - (int)'a' + (int)'A')>,
                   char_<Char::value>>;
        };
    };

    struct to_lower {
        template <typename Char>
        struct apply {
            using type =
            if_vt <Char::value >= 'A' && Char::value <= 'Z',
                   char_<(char)((int)Char::value - (int)'A' + (int)'a')>,
                   char_<Char::value>>;
        };
    };
}

#endif // MPLEX_STRING_CHAR_HPP_INCLUDED
