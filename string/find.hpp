//
// Created by Tim on 21.06.2015.
//

#ifndef MPL14_FIND_HPP
#define MPL14_FIND_HPP

#include "string.hpp"
#include "char.hpp"
#include "../integral.hpp"
#include "../traits/type_traits.hpp"

namespace mplex
{
    template <typename String, typename Char, String::size_type Position = 0, bool AtEnd = false>
    struct find_char_impl
    {
        using type =
        if_t <std::is_same <typename String::template at <Position>::type, Char>::value,
                integral <typename String::size_type, Position>,
                find_char_impl <String, Char, Position + 1, String::size == Position + 1> >;
    };

    template <typename String, typename Char, String::size_type Position>
    struct find_char_impl <String, Char, Position, true>
    {
        using type = integral <typename String::size_type, String::npos>;
    };

    template <typename String, typename Char, String::size_type StartingPosition>
    struct find_char
    {
        using type = find_char <String, Char, StartingPosition, StartingPosition < String::size>::type;
    };

    template <typename String, typename Char, String::size_type StartingPosition>
    using find_char_t = typename find_char <String, Char, StartingPosition>::type;

}

#endif //MPL14_FIND_HPP
