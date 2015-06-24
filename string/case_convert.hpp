#ifndef MPL14_STRING_CASE_CONVERT_HPP_INCLUDED
#define MPL14_STRING_CASE_CONVERT_HPP_INCLUDED

#include "classification.hpp"
#include "../tuple/transform.hpp"
#include "algorithm_adapter.hpp"

namespace mplex { namespace string_algorithm {

    template <typename String>
    struct to_upper : adapt <String, transform_t, mplex::to_upper>
    { };

    template <typename String>
    struct to_lower : adapt <String, transform_t, mplex::to_lower>
    { };

    template <typename String>
    using to_upper_t = typename to_upper <String>::type;

    template <typename String>
    using to_lower_t = typename to_lower <String>::type;

} // mplex
} // string_algorithm

#endif // MPL14_STRING_CASE_CONVERT_HPP_INCLUDED
