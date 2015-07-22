#ifndef MPL14_STRING_FIND_HPP_INCLUDED
#define MPL14_STRING_FIND_HPP_INCLUDED

#include "string.hpp"
#include "compare.hpp"
#include "../algorithm/find.hpp"
#include "../tuple/apply.hpp"

namespace mplex { namespace string_algorithm {

    template <typename String, typename WhatString, typename ComparisonPredicate = mplex::is_iequal>
    struct find : adapt <String, mplex::find, typename WhatString::type, ComparisonPredicate>
    { };

    template <typename String, typename WhatString, typename ComparisonPredicate = mplex::is_iequal>
    using find_t = typename find <String, WhatString, ComparisonPredicate>::type;
}
}

#endif // FIND_HPP_INCLUDED
