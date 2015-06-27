#ifndef MPL14_CONTROL_SWITCH_HPP_INCLUDED
#define MPL14_CONTROL_SWITCH_HPP_INCLUDED

#include "../fundamental/is_same.hpp"
#include "../tuple/find.hpp"


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

        struct switch_match_finder {
            template <typename T>
            struct apply {
                constexpr static const bool value = T::template apply <T>::value;
            };
        };
    }

    template <typename T>
    struct default_ {
        using type = T;
    };

    template <typename T, typename U>
    struct case_ {
        template <typename V>
        struct apply {
            constexpr static const bool value = is_same::template apply <T, V>::value;
            using type = U;
        };
    };

    template <typename T, typename Default, typename... Cases>
    struct switch_ {
        using cases = std::tuple <Cases...>;

        using pos = find_if_t <cases, internal::switch_match_finder>;

        using type = if_vt <pos::value != -1,
                            std::tuple_element <pos::value, cases>::type,
                            Default::type>;

        using is_default = pos::value == -1;
    };

    template <typename T, typename Default, typename... Cases>
    using switch_t = typename switch_ <T, Default, Cases...>::type;

}

#endif // MPL14_CONTROL_SWITCH_HPP_INCLUDED
