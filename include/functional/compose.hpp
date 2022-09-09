#ifndef MPLEX_FUNCTIONAL_COMPOSE_HPP_INCLUDED
#define MPLEX_FUNCTIONAL_COMPOSE_HPP_INCLUDED

// functional
#include "bind.hpp"
#include "placeholder.hpp"
#include "lift.hpp"

// fundamental
#include "../fundamental/integral.hpp"
#include "../fundamental/head.hpp"
#include "../fundamental/tail.hpp"

// tuple
#include "../tuple/push_front.hpp"
#include "../tuple/push_back.hpp"
#include "../tuple/apply.hpp"

// algorithm
#include "../algorithm/merge.hpp"
#include "../algorithm/flatten.hpp"
#include "../algorithm/transform.hpp"

// control
#include "../control/if.hpp"

// utility
#include "../utility/static_warning.hpp"

#include <tuple>

namespace mplex {
    template <typename Functor, typename... Parameters>
    struct compose;

    namespace internal {
        struct START_TAG {};
        struct END_TAG {};

        template <typename T>
        struct is_compound_expression {
            using type = false_;
            constexpr static const bool value = type::value;
        };

        template <typename... List>
        struct is_compound_expression <compose <List...>> {
            using type = true_;
            constexpr static const bool value = type::value;
        };

        struct flatten_compose;

        template <typename T>
        struct compound_functor {
            using type = typename T::functor;
        };

        template <typename T>
        struct compound_parameters {
            using type = typename T::parameters;
        };

        template <typename Head, typename... Tail>
        struct unwind_parameters;


        struct unwind_push_recurse {
            template <typename ToPush, typename... Tail>
            struct apply {
                using type = push_front_t <typename unwind_parameters <Tail...>::type, ToPush>;
            };
        };

        template <typename Head, typename... Tail>
        struct unwind_parameters {
            using _is_compound = typename is_compound_expression <Head>::type;

            using type = lazy_if_t <_is_compound,
                                    then_ <lift <concat>, eval_if_default_t <_is_compound, std::tuple <>, flatten_compose, Head>,
                                                          eval_if_default_t <_is_compound, std::tuple <>, lift <unwind_parameters>, Tail...> >,
                                    else_ <unwind_push_recurse, Head, Tail...> >;
        };

        template <typename Head>
        struct unwind_parameters <Head> {
            using _is_compound = is_compound_expression <Head>;

            using type = lazy_if_t <typename _is_compound::type,
                                    then_ <flatten_compose, Head>,
                                    else_ <identity_functor, std::tuple <Head>> >;
        };

        struct flatten_compose {
            template <typename T>
            struct apply {
                using type = flatten_t <std::tuple <typename T::functor, typename mplex::apply_t <typename T::parameters, unwind_parameters>::type, END_TAG>>;
            };
        };
    }

    template <typename Functor, typename... Parameters>
    struct compose {
        using functor = Functor;
        using parameters = std::tuple <Parameters...>;
    };

    template <typename... OldStack>
    struct composition {
        template <typename... Parameters>
        struct apply {
        };
    };

    /*
    if_ <is_placeholder <List>,
         Parameters,
         List>...*/

    template <typename T>
    struct compile_composition {
        using type = apply_t <typename internal::flatten_compose::template apply <T>::type, composition>;
    };
}

#endif // MPLEX_FUNCTIONAL_COMPOSE_HPP_INCLUDED
