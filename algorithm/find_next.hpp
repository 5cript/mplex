#ifndef MPLEX_ALGORITHM_FIND_NEXT_HPP_INCLUDED
#define MPLEX_ALGORITHM_FIND_NEXT_HPP_INCLUDED

#include "find.hpp"
#include "../tuple/erase.hpp"
#include "../fundamental/is_same.hpp"

namespace mplex {
    template <typename Tuple, typename What, typename LastMatch, typename ComparisonPredicate = is_same>
    struct find_next {
        using type = find_t <erase_t <Tuple, unsigned_<0>, LastMatch>, What, ComparisonPredicate>;
    };

    template <typename Tuple, typename What, typename LastMatch, typename ComparisonPredicate = is_same>
    using find_next_t = typename find_next <Tuple, What, LastMatch, ComparisonPredicate>::type;
}

#endif // FIND_NEXT_HPP_INCLUDED
