#ifndef MPL14_FUNDAMENTAL_BIND_HPP_INCLUDED
#define MPL14_FUNDAMENTAL_BIND_HPP_INCLUDED

// mostly useless due to template<> using = ...
// can be used at block scope though.

namespace mplex {
    template <template <typename...> class Expression, typename... Parameters>
    struct bind_all {
        using type = Expression<Parameters...>;
    };

    template <template <typename...> class Expression, typename... Parameters>
    struct bind {
        template <typename... List>
        using apply = Expression <Parameters..., List...>;
    };
}

#endif // MPL14_FUNDAMENTAL_BIND_HPP_INCLUDED
