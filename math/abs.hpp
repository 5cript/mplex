#ifndef ABS_HPP_INCLUDED
#define ABS_HPP_INCLUDED

namespace mplex {
    template <typename T>
    constexpr abs (T x) { return x < static_cast <T> (0) ? -x : x; }
}

#endif // ABS_HPP_INCLUDED
