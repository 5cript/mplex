#ifndef MPLEX_RANDOM_LINEAR_CONGRUENTIAL_ENGINE_HPP_INCLUDED
#define MPLEX_RANDOM_LINEAR_CONGRUENTIAL_ENGINE_HPP_INCLUDED

#include "../time/time.hpp"
#include "../time/date.hpp"

namespace mplex
{
    namespace random
    {
        struct lcg_params {
            constexpr static long long m = 2147483647; // 2'147'483'647
            constexpr static long long a = 48271;
            constexpr static long long c = 0;
        };

        template <typename previous>
        struct linear_congruential_engine {
            constexpr static long long value = (lcg_params::a * previous::value + lcg_params::c) % lcg_params::m;

            struct next : public linear_congruential_engine <long_long_<value>>
            { };
        };

        struct make_time_seed {
            constexpr static long long value =
                time::hour * 60 * 60 + time::hour * 60 + time::second + date::day * 60 * 60 * 24;
        };
    }
}

#endif // MPLEX_RANDOM_LINEAR_CONGRUENTIAL_ENGINE_HPP_INCLUDED
