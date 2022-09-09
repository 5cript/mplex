#pragma once

#include "../fundamental/integral.hpp"

namespace mplex
{
    struct is_even
    {
        template <typename Value>
        struct apply
        {
            using type = bool_<Value::value % 2 == 0>;
            constexpr static auto value = type::value;
        };
    };

    template <typename Value>
    using is_even_t = typename is_even::template apply <Value>::type;
}
