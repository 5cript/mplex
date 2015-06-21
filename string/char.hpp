#ifndef CHAR_HPP_INCLUDED
#define CHAR_HPP_INCLUDED

#include "../integral.hpp"

namespace mplex
{
    DECLARE_INTEGRAL(char);
    DECLARE_INTEGRAL_N(unsigned
                               char, unsigned_char);

    DECLARE_INTEGRAL(wchar_t);

#ifdef UTF_CHAR
    DECLARE_INTEGRAL(char16_t)
    DECLARE_INTEGRAL(char32_t)
#endif
}

#endif // CHAR_HPP_INCLUDED
