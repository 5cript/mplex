#ifndef MPL14_STRING_COMPARE_HPP_INCLUDED
#define MPL14_STRING_COMPARE_HPP_INCLUDED

#include "char.hpp"

namespace mplex {
    struct is_equal {
        template <typename CharT, typename CharU>
        struct apply {
            constexpr static const bool value = CharT::value == CharU::value;
        };
    };

    struct is_iequal {
        template <typename CharT, typename CharU>
        struct apply {
            constexpr static const bool value = to_lower::template apply <CharT>::type::value == to_lower::template apply <CharU>::type::value;
        };
    };

    struct is_less {
        template <typename CharT, typename CharU>
        struct apply {
            constexpr static const bool value = CharT::value < CharU::value;
        };
    };

    struct is_iless {
        template <typename CharT, typename CharU>
        struct apply {
            constexpr static const bool value = to_lower::template apply <CharT>::type::value < to_lower::template apply <CharU>::type::value;
        };
    };

    struct is_not_greater {
        template <typename CharT, typename CharU>
        struct apply {
            constexpr static const bool value = !(CharT::value > CharU::value);
        };
    };

    struct is_not_igreater {
        template <typename CharT, typename CharU>
        struct apply {
            constexpr static const bool value = !(to_lower::template apply <CharT>::type::value > to_lower::template apply <CharU>::type::value);
        };
    };
}

#endif // COMPARE_HPP_INCLUDED
