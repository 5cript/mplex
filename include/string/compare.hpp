#ifndef MPLEX_STRING_COMPARE_HPP_INCLUDED
#define MPLEX_STRING_COMPARE_HPP_INCLUDED

#include "char.hpp"
#include "string.hpp"

#include "../tuple/pop_front.hpp"
#include "../tuple/front.hpp"

#include "../fundamental/eval_if.hpp"
#include "../fundamental/integral.hpp"

#include <type_traits>

namespace mplex {
    struct is_equal {
        template <typename CharT, typename CharU>
        struct apply {
            constexpr static const bool value = CharT::value == CharU::value;
            using type = bool_ <value>;
        };
    };

    struct is_iequal {
        template <typename CharT, typename CharU>
        struct apply {
            constexpr static const bool value = to_lower::template apply <CharT>::type::value == to_lower::template apply <CharU>::type::value;
            using type = bool_ <value>;
        };
    };

    struct is_less {
        template <typename CharT, typename CharU>
        struct apply {
            constexpr static const bool value = CharT::value < CharU::value;
            using type = bool_ <value>;
        };
    };

    struct is_iless {
        template <typename CharT, typename CharU>
        struct apply {
            constexpr static const bool value = to_lower::template apply <CharT>::type::value < to_lower::template apply <CharU>::type::value;
            using type = bool_ <value>;
        };
    };

    struct is_not_greater {
        template <typename CharT, typename CharU>
        struct apply {
            constexpr static const bool value = !(CharT::value > CharU::value);
            using type = bool_ <value>;
        };
    };

    struct is_not_igreater {
        template <typename CharT, typename CharU>
        struct apply {
            constexpr static const bool value = !(to_lower::template apply <CharT>::type::value > to_lower::template apply <CharU>::type::value);
            using type = bool_ <value>;
        };
    };

    namespace internal {
        template <typename StringT, typename StringU, typename Predicate>
        struct streq {
            using lhsFront = eval_if_default_t <bool_ <!StringT::empty::value>, char_<'.'>, front_a, typename StringT::type>;
            using rhsFront = eval_if_default_t <bool_ <!StringT::empty::value>, char_<'.'>, front_a, typename StringU::type>;

            using step = typename Predicate::template apply <lhsFront, rhsFront>::type;

            constexpr static const bool value =
                step::value && streq <typename StringT::pop_front_t, typename StringU::pop_front_t, Predicate>::value;
        };

        template <typename Predicate>
        struct streq <mplex::string<>, mplex::string<>, Predicate> {
            constexpr static const bool value = true;
        };

        template <typename String, typename Predicate>
        struct streq <String, mplex::string<>, Predicate> {
            constexpr static const bool value = false;
        };

        template <typename String, typename Predicate>
        struct streq <mplex::string<>, String, Predicate> {
            constexpr static const bool value = false;
        };
    }

    template <typename Predicate>
    struct equals {
        template <typename StringT, typename StringU>
        struct apply {
            constexpr static const bool value = internal::streq <StringT, StringU, Predicate>::value;
            using type = bool_ <value>;
        };
    };
}

#endif // COMPARE_HPP_INCLUDED
