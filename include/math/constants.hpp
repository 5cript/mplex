#ifndef MPLEX_MATH_CONSTANTS_HPP_INCLUDED
#define MPLEX_MATH_CONSTANTS_HPP_INCLUDED

#include "sqrt.hpp"
#include "factorial.hpp"

#define CAST(X) static_cast <T> (X)
namespace mplex {
    namespace internal {

        template <typename T>
        constexpr T euler_constant_estimator(int rbi = 20) {
            return (rbi == 1) ? CAST (1) :
                euler_constant_estimator <T> (rbi - 1) +
                CAST (rbi % 2 ? CAST (1LL) : CAST (-1LL)) /
                CAST (factorial(CAST (rbi-1)))
            ;
        }

        template <typename T>
        constexpr T sqrt_2_estimator(T previous, int rbi = 20) {
            return (rbi == 1) ? previous : sqrt_2_estimator((previous + (CAST(2) / previous))/CAST(2), rbi-1);
        }
    }

    constexpr long double e = 1.L / internal::euler_constant_estimator <long double> ();
    constexpr long double sqrt_2 = internal::sqrt_2_estimator <long double> (1.);

    namespace internal {
        template <typename T>
        constexpr T pi_estimator(T a = CAST(1), T b = CAST(1) / CAST(sqrt_2), T t = CAST(1)/CAST(4), T p = CAST(1), int rbi = 5) {
            return (rbi == 1) ? ((((a+b)/ CAST(2)) + sqrt(a*b)) * (((a+b)/ CAST(2)) + sqrt(a*b))) / (4 * (t - p * ( (a - (a + b) / CAST(2)) * (a - (a + b) / CAST(2)) )))
                : pi_estimator(/* a */ (a+b)/ CAST(2),
                               /* b */ sqrt(a*b),
                               /* t */ t - p * ( (a - (a + b) / CAST(2)) * (a - (a + b) / CAST(2)) ),
                               /* p */ CAST(2) * p,
                               rbi - 1)
            ;
        }
    }

    constexpr long double pi = internal::pi_estimator <long double>();
}
#undef CAST

#endif // MPLEX_MATH_CONSTANTS_HPP_INCLUDED
