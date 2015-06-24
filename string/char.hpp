#ifndef MPL14_STRING_CHAR_HPP_INCLUDED
#define MPL14_STRING_CHAR_HPP_INCLUDED

#include "../integral.hpp"

namespace mplex
{
    DECLARE_INTEGRAL(char);
    DECLARE_INTEGRAL_N(unsigned char, unsigned_char);

    DECLARE_INTEGRAL(wchar_t);

#ifdef UTF_CHAR
    DECLARE_INTEGRAL(char16_t)
    DECLARE_INTEGRAL(char32_t)
#endif

    template <typename Char>
    struct to_upper {
        using type =
        if_t <Char::value >= 'a' && Char::value <= 'z',
              char_<(char)((int)Char::value - (int)'a' + (int)'A')>,
              char_<Char::value>>;
    };

    template <typename Char>
    struct to_lower {
        using type =
        if_t <Char::value >= 'A' && Char::value <= 'Z',
              char_<(char)((int)Char::value - (int)'A' + (int)'a')>,
              char_<Char::value>>;
    };
}

#endif // MPL14_STRING_CHAR_HPP_INCLUDED
