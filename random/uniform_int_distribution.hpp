#ifndef MPLEX_RANDOM_UNIFORM_INT_DISTRIBUTION_HPP_INCLUDED
#define MPLEX_RANDOM_UNIFORM_INT_DISTRIBUTION_HPP_INCLUDED

// this is not really uniform - See modulo bias.

namespace mplex { namespace random {

    template <typename Rand, typename Max, typename Min>
    struct uniform_int_distribution {
        constexpr static const typename Rand::value_type value = (Rand::value % (Max::value - Min::value + 1) + Min::value);
    };
}
}

#endif // MPLEX_RANDOM_UNIFORM_INT_DISTRIBUTION_HPP_INCLUDED
