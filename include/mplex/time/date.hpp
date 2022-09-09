#ifndef MPLEX_TIME_DATE_HPP_INCLUDED
#define MPLEX_TIME_DATE_HPP_INCLUDED

#include "../string/string.hpp"

namespace mplex
{
    namespace internal
    {
        constexpr unsigned get_date_char(unsigned index, bool sub) {
            return __DATE__[index] - (int) sub * '0';
        }
    }

    struct date
    {
        constexpr static unsigned year = internal::get_date_char(7, true) * 1000 +
                                         internal::get_date_char(8, true) * 100 +
                                         internal::get_date_char(9, true) * 10 +
                                         internal::get_date_char(10, true) * 1;

        constexpr static unsigned day = internal::get_date_char(4, true) * 10 +
                                        internal::get_date_char(5, true);

        using month = string <internal::get_date_char(0, false),
                internal::get_date_char(1, false),
                internal::get_date_char(2, false)>;
    };
}

#endif // MPLEX_TIME_DATE_HPP_INCLUDED
