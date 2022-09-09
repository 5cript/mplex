#ifndef MPLEX_FUNCTIONAL_PLACEHOLDER_HPP_INCLUDED
#define MPLEX_FUNCTIONAL_PLACEHOLDER_HPP_INCLUDED

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

    struct is_placeholder {
        template <typename T>
        struct apply {
            constexpr static const unsigned value = 0;
            using type = unsigned_<value>;
        };
    };

    template <unsigned V>
    struct is_placeholder::apply <placeholders::_<V> > {
        constexpr static const unsigned value = V;
        using type = unsigned_<value>;
    };
}

#endif // MPLEX_FUNCTIONAL_PLACEHOLDER_HPP_INCLUDED
