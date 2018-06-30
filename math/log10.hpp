#pragma once

#include <mplex/control/if.hpp>
#include <mplex/fundamental/integral.hpp>
#include <mplex/fundamental/identity.hpp>

namespace mplex
{
    /**
     *  Does not have decimal places
     */
    struct log10
    {
        template <
            typename Constant,
            typename Counter = long_long_<1>
        >
        struct apply
        {
            using integral_type = typename Constant::value_type;

            static constexpr bool stop = Constant::value < 10;
            static constexpr integral_type value = lazy_if_vt <
                !stop,
                then_ <log10, std::integral_constant<integral_type, Constant::value / 10>, std::integral_constant<integral_type, Counter::value + 1>>,
                else_ <identity_functor, Counter>
            >::value;

            using type = std::integral_constant <integral_type, value>;
            //using type = bool_<stop>;
        };
    };
}
