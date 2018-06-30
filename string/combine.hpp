#pragma once

#include "string.hpp"
#include "strcat.hpp"

namespace mplex { namespace string_algorithm
{
    /**
     *  Basically:
     *
     *      combine_strings <a, b, c, ..., z> =
     *      stream << a << b << c << ... << z;
     */
    template <typename T, typename U, typename... Strings>
    struct combine_strings {
        using type = typename combine_strings <typename strcat <T, U>::type, Strings...>::type;
    };

    template <typename T, typename U>
    struct combine_strings <T, U> {
        using type = typename strcat <T, U>::type;
    };
}
}
