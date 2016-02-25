#ifndef MPLEX_ADVANCED_LEXER_HPP_INCLUDED
#define MPLEX_ADVANCED_LEXER_HPP_INCLUDED

#include "../algorithm/remove_if.hpp"

namespace mplex {
    template <typename String>
    struct make_lexemes {
        using is_empty_ = mplex::bind_left <std::is_same, std::tuple<>>;
        using type = remove_if_t <string_algorithm::split_t <String, is_space>, is_empty_>;
    };

    template <typename String>
    using make_lexemes_t = typename make_lexemes <String>::type;
}

#endif // MPLEX_ADVANCED_LEXER_HPP_INCLUDED
