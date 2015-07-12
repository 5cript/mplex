#ifndef MPL14_FUNCTIONAL_COMPOSE_HPP_INCLUDED
#define MPL14_FUNCTIONAL_COMPOSE_HPP_INCLUDED

#include <tuple>

namespace mplex {
    namespace placeholders {
        template <unsigned V>
        struct _ {
            constexpr static const unsigned value = V;
        };

        #define PLACEHOLDER_SHORT_HAND(NUM) \
        using _ ## NUM = _<NUM>

        PLACEHOLDER_SHORT_HAND(1);
        PLACEHOLDER_SHORT_HAND(2);
        PLACEHOLDER_SHORT_HAND(3);
        PLACEHOLDER_SHORT_HAND(4);
        PLACEHOLDER_SHORT_HAND(5);
        PLACEHOLDER_SHORT_HAND(6);
        PLACEHOLDER_SHORT_HAND(7);
        PLACEHOLDER_SHORT_HAND(8);
        PLACEHOLDER_SHORT_HAND(9);
        PLACEHOLDER_SHORT_HAND(10);
        PLACEHOLDER_SHORT_HAND(11);
        PLACEHOLDER_SHORT_HAND(12);
        PLACEHOLDER_SHORT_HAND(13);
        PLACEHOLDER_SHORT_HAND(14);
        PLACEHOLDER_SHORT_HAND(15);
        PLACEHOLDER_SHORT_HAND(16);
        PLACEHOLDER_SHORT_HAND(17);
        PLACEHOLDER_SHORT_HAND(18);
        PLACEHOLDER_SHORT_HAND(19);
        PLACEHOLDER_SHORT_HAND(20);
    }

    /*
    using Add = make_delegate <add, _1, _2>;
    */

    template <typename Functor, typename... Parameters>
    struct make_delegate
    {
        template <typename... InnerParameters>
        struct apply
        {
            using _temp = std::tuple <InnerParameters...>;
            static_assert (sizeof...(InnerParameters) == sizeof...(Parameters), "Incorrect amount of arguments given.");
            using type = typename Functor::template apply <typename std::tuple_element <Parameters::value, _temp>::type...>::type;
        };
    };
}

#endif // MPL14_FUNCTIONAL_COMPOSE_HPP_INCLUDED
