#pragma once

#include "even.hpp"
#include "../control/if.hpp"
#include "../fundamental/integral.hpp"
#include "../fundamental/identity.hpp"

namespace mplex
{
    struct pow
    {
        template <
            typename Base,
            typename Exp
        >
        struct apply
        {
            using type = long_long_ <
                pow::template apply <Base, long_long_<Exp::value / 2>>::type::value *
                pow::template apply <Base, long_long_<Exp::value / 2>>::type::value *
                std::conditional_t <is_even_t <Exp>::value, long_long_<1>, Base>::value
            >;
            constexpr static auto value = type::value;
        };

        template <typename Base>
        struct apply <Base, long_long_<3>>
        {
            constexpr static auto value = Base::value * Base::value * Base::value;
            using type = long_long_<value>;
        };
        template <typename Base>
        struct apply <Base, long_long_<2>>
        {
            constexpr static auto value = Base::value * Base::value;
            using type = long_long_<value>;
        };
        template <typename Base>
        struct apply <Base, long_long_<1>>
        {
            using type = Base;
            constexpr static auto value = type::value;
        };
        template <typename Base>
        struct apply <Base, long_long_<0>>
        {
            using type = long_long_<1>;
            constexpr static auto value = 1;
        };
    };

    template <typename Base, typename Exp>
    using pow_t = typename pow::template apply <Base, Exp>::type;

    template <long long Base, long long Exp>
    using pow_vt = typename pow::template apply <long_long_ <Base>, long_long_ <Exp>>::type;
}
