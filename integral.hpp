#ifndef INTEGRAL_HPP_INCLUDED
#define INTEGRAL_HPP_INCLUDED

namespace mplex {
    template <typename T, T Value>
    struct integral {
        constexpr const static T value = Value;
    };
}

#endif // INTEGRAL_HPP_INCLUDED
