#ifndef MPLEX_STRING_STRCAT_HPP_INCLUDED
#define MPLEX_STRING_STRCAT_HPP_INCLUDED

#include "string.hpp"
#include "../tuple/concat.hpp"
#include "algorithm_adapter.hpp"

namespace mplex { namespace string_algorithm
{
    template <typename StringT, typename StringU>
    struct strcat : adapt <StringT, mplex::concat_t, typename StringU::type>
    { };

    template <typename StringT, typename StringU>
    using strcat_t = typename strcat <StringT, StringU>::type;
}
}

#endif // MPLEX_STRING_STRCAT_HPP_INCLUDED
