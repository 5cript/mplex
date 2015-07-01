#ifndef MPL14_FUNCTIONAL_FUNCTOR_HPP_INCLUDED
#define MPL14_FUNCTIONAL_FUNCTOR_HPP_INCLUDED

/**
 *  A functor is defined as class that containing an apply template
 *
 *  functors generally are called like:   func::template apply <PARAMS...>::type
 */

namespace mplex {
    /*
    struct _level_1 {
        template <typename T>
        apply {
            using type = T;
        };
    };

    struct _level_2 {
        template <typename T, typename U>
        apply {
            using type = _binder<T, U>;
        };
    };

    struct _level_many {
        template <typename... T>
        apply {
            using type = _many_binder<T...>;
        };
    };
    */
}

#endif // MPL14_FUNCTIONAL_FUNCTOR_HPP_INCLUDED
