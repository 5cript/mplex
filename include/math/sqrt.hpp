#ifndef SQRT_HPP_INCLUDED
#define SQRT_HPP_INCLUDED

#define CAST(X) static_cast <T> (X)
namespace mplex {
    template <typename T>
    constexpr T sqrt (T of, T x = CAST(1), int rbi = 15) {
        return (rbi == 1) ? x : sqrt(of, x - (x * x - of) / (2 * x), rbi - 1);
    }
}
#undef CAST

#endif // SQRT_HPP_INCLUDED
