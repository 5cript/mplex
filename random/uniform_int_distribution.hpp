#ifndef MPL14_RANDOM_UNIFORM_INT_DISTRIBUTION_HPP_INCLUDED
#define MPL14_RANDOM_UNIFORM_INT_DISTRIBUTION_HPP_INCLUDED

// this is not really uniform! See modulo bias.

namespace mplex { namespace random {

    template <typename T, T Rand, T Max, T Min>
    struct uniform_int_distribution {
        constexpr static const T value = (Rand % (Max - Min + 1) + Min);
    };
}
}

#endif // MPL14_RANDOM_UNIFORM_INT_DISTRIBUTION_HPP_INCLUDED
