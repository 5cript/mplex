#ifndef MPL14_RANDOM_UNIFORM_INT_DISTRIBUTION_HPP_INCLUDED
#define MPL14_RANDOM_UNIFORM_INT_DISTRIBUTION_HPP_INCLUDED

// this is not really uniform! See modulo bias.

namespace mplex { namespace random {

    template <typename Rand, typename Max, typename Min>
    struct uniform_int_distribution {
        constexpr static const T value = (Rand::value % (Max::value - Min::value + 1) + Min::value);
    };
}
}

#endif // MPL14_RANDOM_UNIFORM_INT_DISTRIBUTION_HPP_INCLUDED
