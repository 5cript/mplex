#ifndef STRCAT_HPP_INCLUDED
#define STRCAT_HPP_INCLUDED

#include "string.hpp"
#include "../tuple/concat.hpp"

namespace mplex {
    template <typename StringT, typename StringU>
    struct strcat {
        using type = apply_t<concat_t<typename StringT::type, typename StringU::type>, mplex::translate>;
    };

    template <typename StringT, typename StringU>
    using strcat_t = typename strcat<StringT, StringU>::type;
}

#endif // STRCAT_HPP_INCLUDED
