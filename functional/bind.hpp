#ifndef MPLEX_FUNCTIONAL_BIND_HPP_INCLUDED
#define MPLEX_FUNCTIONAL_BIND_HPP_INCLUDED

#include "placeholder.hpp"

#include "../fundamental/identity.hpp"

#include "../control/if.hpp"

#include "../tuple/tuple_element.hpp"
#include "../tuple/push_back.hpp"
#include "../tuple/push_front.hpp"
#include "../tuple/make_tuple.hpp"
#include "../tuple/apply.hpp"

#include "../algorithm/merge.hpp"
#include "../algorithm/count.hpp"

namespace mplex {
    template <template <typename...> class Expression, typename... Parameters>
    struct bind_left {
        template <typename... List>
        using apply = Expression <Parameters..., List...>;
    };

    template <template <typename...> class Expression, typename... Parameters>
    struct bind_right {
        template <typename... List>
        using apply = Expression <List..., Parameters...>;
    };

    template <template <typename...> class Expression, typename... Parameters>
    struct bind_all {
        using type = Expression<Parameters...>;
    };

    template <typename Function, typename... Parameters>
    struct functor_bind_left {
        template <typename... List>
        using apply = typename Function::template apply <Parameters..., List...>;
    };

    template <typename Function, typename... Parameters>
    struct functor_bind_right {
        template <typename... List>
        using apply = typename Function::template apply <List..., Parameters...>;
    };

    template <typename Function, typename... Parameters>
    struct functor_bind_all {
        using apply = typename Function::template apply <Parameters...>;
    };


    namespace internal {
        template <typename T, typename Index>
        struct param_wrap
        {
            using type = T;
            using index = Index;
        };

        template <typename... Parameters>
        struct placeholder_index_generator {
            template <unsigned I>
            struct apply {
                using type =
                lazy_if_t <typename is_placeholder::template apply <typename std::tuple_element <I, std::tuple <Parameters...> >::type>::type,
                           then_<tuple_element, int_<I>, std::tuple <Parameters...> >,
                           else_<identity_functor, int_ <0> > >;
            };
        };

        struct param_wrap_was_placeholder {
            template <typename T>
            struct apply {
                using type = typename is_placeholder::template apply <typename T::type>::type;
            };
        };
    }

    template <typename Functor, typename... ParameterWraps>
    struct bind_impl
    {
        template <typename... InnerParameters>
        struct apply
        {
            using _temp = std::tuple <InnerParameters...>;

            static_assert (sizeof...(InnerParameters) == count_t <std::tuple <ParameterWraps...>, internal::param_wrap_was_placeholder>::value, "Wrong amount of parameters provided");

            using type = typename Functor::template apply <typename
                lazy_if <typename is_placeholder::template apply <typename ParameterWraps::type>::type,
                    then_ <tuple_element, int_<ParameterWraps::index::value - 1>, _temp>,
                    // then_ <identity_functor, typename ParameterWraps::type>,
                    else_ <identity_functor, typename ParameterWraps::type >
                >::type...
            >::type;
        };
    };

    template <typename Functor, typename... Parameters>
    struct bind
    {
        using merged = push_front_t <merge_t <std::tuple <Parameters...>,
                                              typename make_tuple <internal::placeholder_index_generator <Parameters...>>::template
                                                  apply <int_ <sizeof...(Parameters)> >::type, internal::param_wrap>,
                                     Functor>;

        template <typename... InnerParameters>
        using apply = typename mplex::apply_t <merged, bind_impl>::template apply <InnerParameters...>;
    };
}

#endif // MPLEX_FUNCTIONAL_BIND_HPP_INCLUDED
