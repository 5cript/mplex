#ifndef MPL14_ADVANCED_LEXER_HPP_INCLUDED
#define MPL14_ADVANCED_LEXER_HPP_INCLUDED

#include "../tuple/remove_if.hpp"

namespace mplex {
    template <typename String>
    struct make_lexemes {
        using is_empty_ = mplex::bind <std::is_same, std::tuple<>>;
        using type = remove_if_t <string_algorithm::split_t <String, is_space>, is_empty_>;
    };

    template <typename String>
    using make_lexemes_t = typename make_lexemes <String>::type;
}

#endif // MPL14_ADVANCED_LEXER_HPP_INCLUDED
