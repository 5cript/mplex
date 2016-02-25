#ifndef MPLEX_ALGORITHM_FLATTEN_HPP_INCLUDED
#define MPLEX_ALGORITHM_FLATTEN_HPP_INCLUDED

// fundamental
#include "../fundamental/eval_if.hpp"

// control
#include "../control/if.hpp"

// tuple
#include "../tuple/is_tuple.hpp"
#include "../tuple/concat.hpp"
#include "../tuple/apply.hpp"

// algorithm
#include "merge.hpp"

// functional
#include "../functional/lift.hpp"

namespace mplex
{
    /**
     *  Flattens a tuple, but not deep.
     *
     *  std::tuple<int, float, std::tuple <char, long>, double>
     *  becomes std::tuple<int, float, char, long, double>
     *
     */
    template <typename Tuple>
    struct flatten;

    namespace internal {
        struct flatten_impl;

        struct flatten_impl {
            template <typename Head, typename... Tail>
            struct apply
            {
                using _is_tuple = typename is_tuple::template apply <Head>::type;
                using _is_not_tuple = bool_ <!_is_tuple::value>;

                using type = lazy_if_t <_is_tuple,
                                        then_ <lift<concat>, Head, eval_if_default_t <_is_tuple, std::tuple<>, flatten_impl, Tail...>>,
                                        else_ <lift<push_front>, eval_if_default_t <_is_not_tuple, std::tuple<>, flatten_impl, Tail...>, Head>>;
            };

        };

        template <typename Head>
        struct flatten_impl::apply <Head> {
            using type = if_t <typename is_tuple::template apply <Head>::type,
                               Head, std::tuple <Head>>;
        };
    }

    template <typename Tuple>
    struct flatten {
        using type = typename apply_t <Tuple, internal::flatten_impl::template apply>::type;
    };

    template <typename Tuple>
    using flatten_t = typename flatten <Tuple>::type;
}

#endif // MPLEX_ALGORITHM_FLATTEN_HPP_INCLUDED
