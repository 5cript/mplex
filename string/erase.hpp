#ifndef MPL14_STRING_ERASE_HPP_INCLUDED
#define MPL14_STRING_ERASE_HPP_INCLUDED

#include "string.hpp"
#include "../tuple/apply.hpp"
#include "../tuple/erase.hpp"
#include "algorithm_adapter.hpp"

namespace mplex { namespace string_algorithm
{
    template <typename String, typename Begin, typename End>
    struct erase : adapt <String, mplex::erase_t, Begin, End>
    { };

    template <typename String, typename Begin, typename End>
    using erase_t = typename erase <String, Begin, End>::type;

    template <typename String, unsigned Begin, unsigned End>
    using erase_vt = typename erase <String, unsigned_<Begin>, unsigned_<End>>::type;
}
}

#endif // MPL14_STRING_ERASE_HPP_INCLUDED
