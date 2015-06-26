#ifndef MPL14_STRING_COMPARE_HPP_INCLUDED
#define MPL14_STRING_COMPARE_HPP_INCLUDED

#include "char.hpp"

namespace mplex {
    template <typename CharT, typename CharU>
    struct is_equal {
        constexpr static const bool value = CharT::value == CharU::value;
    };


    template <typename CharT, typename CharU>
    struct is_iequal {
        constexpr static const bool value = to_lower<CharT>::type::value == to_lower<CharU>::type::value;
    };


    template <typename CharT, typename CharU>
    struct is_less {
        constexpr static const bool value = CharT::value < CharU::value;
    };

    template <typename CharT, typename CharU>
    struct is_iless {
        constexpr static const bool value = to_lower<CharT>::type::value < to_lower<CharU>::type::value;
    };


    template <typename CharT, typename CharU>
    struct is_not_greater {
        constexpr static const bool value = !(CharT::value > CharU::value);
    };

    template <typename CharT, typename CharU>
    struct is_not_igreater {
        constexpr static const bool value = !(to_lower<CharT>::type::value > to_lower<CharU>::type::value);
    };
}

#endif // COMPARE_HPP_INCLUDED
