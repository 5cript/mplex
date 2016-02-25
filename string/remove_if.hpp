#ifndef MPLEX_STRING_REMOVE_IF_HPP_INCLUDED
#define MPLEX_STRING_REMOVE_IF_HPP_INCLUDED

#include "string.hpp"
#include "algorithm_adapter.hpp"
#include "../algorithm/remove_if.hpp"

namespace mplex { namespace string_algorithm {
    template <typename String, typename Predicate>
    struct remove_if : adapt <String, mplex::remove_if, Predicate>
    { };

    template <typename String, typename Predicate>
    using remove_if_t = typename remove_if <String, Predicate>::type;
}
}

#endif // MPLEX_STRING_REMOVE_IF_HPP_INCLUDED
