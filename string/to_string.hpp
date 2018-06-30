#pragma once

#include "string.hpp"
#include "../math/log10.hpp"
#include "../math/pow.hpp"
#include "../tuple/apply.hpp"

#include <utility>

namespace mplex
{
    namespace internal
    {
        template <typename Sequence, typename SequenceSize, typename Value>
        struct to_string_impl{};

        template <typename Value, typename SequenceSize, typename T, T... Is>
        struct to_string_impl <std::integer_sequence <T, Is...>, SequenceSize, Value>
        {
            using digits = std::integer_sequence <
                char,
                ('0' + (
                    Value::value / pow_vt<10, (SequenceSize::value - (Is + 1))>::value -
                    10 * (Value::value / pow_vt<10, (SequenceSize::value - (Is))>::value)
                ))...
            >;
        };
    }

    template <
        typename Value
    >
    struct to_string
    {
        using str_size = typename log10::template apply<Value>::type;

        using type = typename apply_values <
            char,
            typename internal::to_string_impl <std::make_index_sequence <str_size::value>, str_size, Value>::digits,
            string
        >::type;
    };
}
