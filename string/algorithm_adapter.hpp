#ifndef MPL14_STRING_ALGORITHM_ADAPTER_HPP_INCLUDED
#define MPL14_STRING_ALGORITHM_ADAPTER_HPP_INCLUDED

#include "string.hpp"
#include "../tuple/apply.hpp"

namespace mplex {

    template <typename String, template <typename, typename...> class TupleAlgorithm, typename... AdditionalParameters>
    struct adapt {
        using type = apply_t <TupleAlgorithm <typename String::type, AdditionalParameters...>, mplex::translate>;
    };
}

#endif // MPL14_STRING_ALGORITHM_ADAPTER_HPP_INCLUDED
