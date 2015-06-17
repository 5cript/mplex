#ifndef CHAR_HPP_INCLUDED
#define CHAR_HPP_INCLUDED

#include "../integral.hpp"

namespace mplex {
    template <char C>
    struct char_ : public integral<char, C> {};
}

#endif // CHAR_HPP_INCLUDED
