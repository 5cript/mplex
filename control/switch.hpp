#ifndef MPL14_CONTROL_SWITCH_HPP_INCLUDED
#define MPL14_CONTROL_SWITCH_HPP_INCLUDED

#include "../fundamental/is_same.hpp"
#include "../tuple/find.hpp"
#include "../fundamental/eval_if.hpp"
#include "../tuple/tuple_element.hpp"
#include "if.hpp"
#include "../string/compare.hpp"

/*  Use example:

    switch_ <STRING("SOME"),
             default_ <DefaultType>,
             case_ <STRING("SOME"), SomeType>,
             case_ <STRING("OTHER"), OtherType>,
            >::type;
*/

namespace mplex {

    namespace internal {
        struct switch_no_match_ {};

        template <typename T, typename CaseSensitive>
        struct switch_match_finder {
            template <typename U>
            struct apply {
                using predicate = if_t <CaseSensitive, is_equal, is_iequal>;

                constexpr static const bool value = equals<predicate>::template apply <T, typename U::lhs>::value;
            };
        };
    }

    template <typename T>
    struct default_ {
        using type = T;
    };

    template <typename T, typename U>
    struct case_ {
        using lhs = T;
        using rhs = U;
        using type = rhs;

        template <typename V>
        struct apply {
            constexpr static const bool value = is_same::template apply <T, V>::value;
            using type = U;
        };
    };

    template <typename Default, typename... Cases>
    struct switch_base {
        using cases = std::tuple <Cases...>;
        using default_ = Default;

        template <typename T, typename CaseSensitive = true_>
        struct apply {
            using __pos = find_if_t <cases, internal::switch_match_finder <T, CaseSensitive>>;

            using type = typename lazy_if_vt <__pos::value != -1,
                                              then_ <tuple_element, __pos, cases>,
                                              else_ <Default>>::type;

            constexpr static const bool is_default = __pos::value == -1;
        };
    };

    template <typename T, typename Default, typename... Cases>
    struct switch_ {
        using sbase = switch_base<Default, Cases...>;
        using __sbase_ex = typename sbase::template apply <T>;

        using type = typename __sbase_ex::type;
        constexpr static const bool is_default = __sbase_ex::is_default;
    };

    template <typename T, typename Default, typename... Cases>
    using switch_t = typename switch_ <T, Default, Cases...>::type;

}

#endif // MPL14_CONTROL_SWITCH_HPP_INCLUDED
