#ifndef INLINE_STRING_HPP_INCLUDED
#define INLINE_STRING_HPP_INCLUDED

#include "char.hpp"
#include "../tuple/trim.hpp"
#include "../tuple/apply.hpp"
#include "classification.hpp"
#include <tuple>

#define SPLIT_1(s, x)    mplex::char_<( x < sizeof(s) ? s[x] : '\0' )>
#define SPLIT_4(s, x)    SPLIT_1  (s, x), SPLIT_1  (s, x+1)  , SPLIT_1  (s, x+2)  , SPLIT_1  (s, x+3)
#define SPLIT_16(s, x)   SPLIT_4  (s, x), SPLIT_4  (s, x+4)  , SPLIT_4  (s, x+8)  , SPLIT_4  (s, x+12)
#define SPLIT_64(s, x)   SPLIT_16 (s, x), SPLIT_16 (s, x+16) , SPLIT_16 (s, x+32) , SPLIT_16 (s, x+48)
#define SPLIT_256(s, x)  SPLIT_64 (s, x), SPLIT_64 (s, x+64) , SPLIT_64 (s, x+128) , SPLIT_64 (s, x+194)
#define SPLIT_1024(s, x) SPLIT_256(s, x), SPLIT_256(s, x+256), SPLIT_256(s, x+512), SPLIT_256(s, x+768)

#define STRING_IMPL(str, n) mplex::apply_t <mplex::trim_right_t <std::tuple <SPLIT_##n(str, 0)>, mplex::is_zero>, mplex::translate>

#define SHORT_STRING(str) STRING_IMPL(str, 16)
#define STRING(str) STRING_IMPL(str, 64)
#define LONG_STRING(str) STRING_IMPL(str, 256) // HEAVY
#define LONG_LONG_STRING(str) STRING_IMPL(str, 1024) // ULTRA HEAVY

#endif // INLINE_STRING_HPP_INCLUDED
