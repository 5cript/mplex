#ifndef MPL14_ADVANCED_TOKENIZER_HPP_INCLUDED
#define MPL14_ADVANCED_TOKENIZER_HPP_INCLUDED

#include "../string/string.hpp"
#include "../fundamental/bind.hpp"
#include "../string/split.hpp"
#include "../string/remove_if.hpp"

namespace mplex {
    template <typename String>
    struct tokenize {
        using is_empty_ = mplex::bind <std::is_same, std::tuple<>>;
        using type = remove_if_t <string_algorithm::split_t <String, is_space>, is_empty_>;
    };
}

#endif // MPL14_ADVANCED_TOKENIZER_HPP_INCLUDED
