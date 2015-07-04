#ifndef MPL14_FUNCTIONAL_BIND_HPP_INCLUDED
#define MPL14_FUNCTIONAL_BIND_HPP_INCLUDED

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

    template <typename Function, typename... Parameters>
    struct functor_bind {
        template <typename... List>
        using apply = typename Function::template apply <Parameters..., List...>;
    };

    template <typename Function, typename... Parameters>
    struct functor_bind_all {
        using apply = typename Function::template apply <Parameters...>;
    };
}

#endif // MPL14_FUNCTIONAL_BIND_HPP_INCLUDED
