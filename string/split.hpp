#ifndef SPLIT_HPP_INCLUDED
#define SPLIT_HPP_INCLUDED

#include "string.hpp"
#include "algorithm_adapter.hpp"
#include "../tuple/split.hpp"

namespace mplex { namespace string_algorithm {
    template <typename String, typename Predicate>
    struct split : adapt_list <String, mplex::split_t, Predicate> {};

    template <typename String, typename Predicate>
    using split_t = typename split <String, Predicate>::type;
}
}

#endif // SPLIT_HPP_INCLUDED
