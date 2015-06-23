#ifndef TIME_HPP_INCLUDED
#define TIME_HPP_INCLUDED

namespace mplex
{
    namespace internal
    {
        constexpr unsigned get_time_char(unsigned index) {
            return __TIME__[index] - '0';
        }
    }

    struct time
    {
        constexpr static unsigned hour = internal::get_time_char(0) * 10 + internal::get_time_char(1);
        constexpr static unsigned minute = internal::get_time_char(3) * 10 + internal::get_time_char(4);
        constexpr static unsigned second = internal::get_time_char(6) * 10 + internal::get_time_char(7);
    };
}

#endif // TIME_HPP_INCLUDED
