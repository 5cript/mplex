#ifndef MPL14_STRING_ERASE_HPP_INCLUDED
#define MPL14_STRING_ERASE_HPP_INCLUDED

#include "string.hpp"
#include "../tuple/apply.hpp"
#include "../tuple/erase.hpp"

namespace mplex { namespace string_algorithm
{
    template <typename String, typename Begin, typename End>
    struct erase {
        using type = apply_t <mplex::erase_t <typename String::type, Begin, End>, mplex::translate>;
    };

    template <typename String, typename Begin, typename End>
    using erase_t = typename erase <String, Begin, End>::type;

    template <typename String, unsigned Begin, unsigned End>
    using erase_vt = typename erase <String, unsigned_<Begin>, unsigned_<End>>::type;
}
}

#endif // MPL14_STRING_ERASE_HPP_INCLUDED
