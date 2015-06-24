#ifndef MPL14_STRING_FIND_HPP
#define MPL14_STRING_FIND_HPP

#include "string.hpp"
#include "char.hpp"
#include "../integral.hpp"

#include <type_traits>

namespace mplex { namespace string_algorithm
{
    template <typename String, typename Char, typename String::size_type Position = 0, bool AtEnd = false>
    struct find_char_impl {
        constexpr static const bool found = String::template at <Position>::type::value == Char::value;

        using type =
        if_t <found,
              integral <typename String::size_type, Position>,
              typename find_char_impl <String, Char, Position + 1, String::size == Position + 1 || found>::type >;
    };

    template <typename String, typename Char, typename String::size_type Position>
    struct find_char_impl <String, Char, Position, true> {
        using type = integral <typename String::size_type, String::npos>;
    };

    template <typename String, typename Char, typename String::size_type StartingPosition = 0>
    struct find_char {
        using type = typename find_char_impl <String, Char, StartingPosition, !(StartingPosition < String::size)>::type;
    };

    template <typename String, typename Char, typename String::size_type StartingPosition = 0>
    using find_char_t = typename find_char <String, Char, StartingPosition>::type;

}
}

#endif //MPL14_STRING_FIND_HPP
