#ifndef MPL14_FUNCTIONAL_COMPOSE_HPP_INCLUDED
#define MPL14_FUNCTIONAL_COMPOSE_HPP_INCLUDED

#include "placeholder.hpp"

#include "../fundamental/integral.hpp"

#include "../control/if.hpp"
#include "../control/bind.hpp"

#include <tuple>

namespace mplex {
    template <typename T>
    struct is_compound_expression;

    template <typename Functor, typename... Params>
    struct compose_impl {
        using type = Functor;
        using params = std::tuple <Params>;

        template <typename... Parameters>
        struct apply {
            using type = Functor <
                lazy_if_t <is_compound_expression<Parameters>::type,
                           then_ <
                >
        };
    };


    struct is_compound_expression {
        template <typename T>
        struct apply {
            constexpr static const bool value = false;
            using type = bool_<false>;
        };
    }

    template <typename... List>
    struct is_compound_expression::apply <compose <List...> > {
        constexpr static const bool value = true;
        using type = bool_<true>;
    };
}

#endif // MPL14_FUNCTIONAL_COMPOSE_HPP_INCLUDED
