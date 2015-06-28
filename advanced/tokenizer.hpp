#ifndef MPL14_ADVANCED_TOKENIZER_HPP_INCLUDED
#define MPL14_ADVANCED_TOKENIZER_HPP_INCLUDED

#include "type_mapper.hpp"

#include "../string/string.hpp"
#include "../fundamental/bind.hpp"
#include "../string/split.hpp"
#include "../string/remove_if.hpp"
#include "../control/switch.hpp"
#include "../tuple/apply.hpp"
#include "lexer.hpp"
#include "type_mapper.hpp"

namespace mplex {
    template <typename String, typename SwitchBase, typename CaseSensitive = true_>
    struct tokenize {
        //using sbase = typename apply_t <Keywords, internal::make_keyword_table>::type;

        using type = map_types_t <make_lexemes_t <String>, SwitchBase, CaseSensitive>;
    };

    template <typename String, typename SwitchBase, typename CaseSensitive = true_>
    using tokenize_t = typename tokenize <String, SwitchBase, CaseSensitive>::type;
}

#endif // MPL14_ADVANCED_TOKENIZER_HPP_INCLUDED
