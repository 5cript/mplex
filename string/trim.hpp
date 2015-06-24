#ifndef MPL14_STRING_TRIM_HPP_INCLUDED
#define MPL14_STRING_TRIM_HPP_INCLUDED

#include "string.hpp"
#include "../tuple/trim.hpp"
#include "classification.hpp"
#include "algorithm_adapter.hpp"

namespace mplex { namespace string_algorithm
{
    template <typename String, template <typename> class Predicate = is_space>
    struct trim_left : adapt <String, mplex::trim_left_t, Predicate>
    { };

    template <typename String, template <typename> class Predicate = is_space>
    struct trim_right : adapt <String, mplex::trim_right_t, Predicate>
    { };

    template <typename String, template <typename> class Predicate = is_space>
    struct trim : adapt <String, mplex::trim_t, Predicate>
    { };

    template <typename String, template <typename> class Predicate = is_space>
    using trim_left_t = typename trim_left <String, Predicate>::type;

    template <typename String, template <typename> class Predicate = is_space>
    using trim_right_t = typename trim_right <String, Predicate>::type;

    template <typename String, template <typename> class Predicate = is_space>
    using trim_t = typename string_algorithm::trim <String, Predicate>::type;
}
}

#endif // MPL14_STRING_HPP_INCLUDED
