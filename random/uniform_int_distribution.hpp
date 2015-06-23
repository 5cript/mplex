#ifndef UNIFORM_INT_DISTRIBUTION_HPP_INCLUDED
#define UNIFORM_INT_DISTRIBUTION_HPP_INCLUDED

// this is not really uniform! See modulo bias.

namespace mplex { namespace random {

    template <typename T, T Rand, T Max, T Min>
    struct uniform_int_distribution {
        constexpr static const T value = (Rand % (Max - Min + 1) + Min);
    };
}
}

#endif // UNIFORM_INT_DISTRIBUTION_HPP_INCLUDED
