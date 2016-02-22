#ifndef MPLEX_STRING_ALGORITHM_ADAPTER_HPP_INCLUDED
#define MPLEX_STRING_ALGORITHM_ADAPTER_HPP_INCLUDED

#include "string.hpp"
#include "../tuple/apply.hpp"

namespace mplex {

    template <typename String, template <typename, typename...> class TupleAlgorithm, typename... AdditionalParameters>
    struct adapt {
        using type = apply_t <TupleAlgorithm <typename String::type, AdditionalParameters...>, mplex::translate>;
    };

    template <typename String, template <typename, typename...> class TupleAlgorithm, typename... AdditionalParameters>
    struct adapt_list {

        template <typename... Tuples>
        using list_apply = std::tuple <apply_t <Tuples, mplex::translate>...>;

        using type = apply_t <TupleAlgorithm <typename String::type, AdditionalParameters...>, list_apply>;
    };
}

#endif // MPLEX_STRING_ALGORITHM_ADAPTER_HPP_INCLUDED
