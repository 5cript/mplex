#ifndef LINEAR_CONGRUENTIAL_ENGINE_HPP_INCLUDED
#define LINEAR_CONGRUENTIAL_ENGINE_HPP_INCLUDED

#include "../time/time.hpp"

namespace mplex { namespace random {

    struct lcg_params {
        constexpr static long long m = 2147483647; // 2'147'483'647
        constexpr static long long a = 48271;
        constexpr static long long c = 0;
    };

    template <long long previous>
    struct linear_congruential_engine {
        constexpr static long long value = (lcg_params::a * previous + lcg_params::c) % lcg_params::m;

        struct next {
            constexpr static long long value = linear_congruential_engine<value>::value;
            using type = linear_congruential_engine<value>;
        };
    };

    struct make_time_seed {
        constexpr static long long value = time::hour * 60 * 60 + time::hour * 60 + time::second + date::day * 60 * 60 * 24;
    };
}
}

#endif // LINEAR_CONGRUENTIAL_ENGINE_HPP_INCLUDED
