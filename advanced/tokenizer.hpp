#ifndef MPL14_ADVANCED_TOKENIZER_HPP_INCLUDED
#define MPL14_ADVANCED_TOKENIZER_HPP_INCLUDED

#include "type_mapper.hpp"

#include "../string/string.hpp"
#include "../string/split.hpp"
#include "../string/remove_if.hpp"
#include "../string/inline_string.hpp"
#include "../string/compare.hpp"

#include "../functional/bind.hpp"

#include "../fundamental/eval_if.hpp"
#include "../fundamental/integral.hpp"

#include "../control/switch.hpp"
#include "../control/if.hpp"

#include "../algorithm/find.hpp"
#include "../algorithm/find_next.hpp"

#include "../tuple/apply.hpp"
#include "../tuple/copy.hpp"

#include "../math/min.hpp"

#include "lexer.hpp"
#include "type_mapper.hpp"
#include "token_classification.hpp"

namespace mplex {
    template <typename String, typename SwitchBase, typename CaseSensitive = true_>
    struct tokenize {
        //using sbase = typename apply_t <Keywords, internal::make_keyword_table>::type;

        using type = map_types_t <make_lexemes_t <String>, SwitchBase, CaseSensitive>;
    };

    template <typename String, typename SwitchBase, typename CaseSensitive = true_>
    using tokenize_t = typename tokenize <String, SwitchBase, CaseSensitive>::type;

//################################################################################################

    struct SQL_Tokenization {
        using operator_tokens = std::tuple <
            SHORT_STRING("ALL"),
            SHORT_STRING("AND"),
            SHORT_STRING("ANY"),
            SHORT_STRING("BETWEEN"),
            SHORT_STRING("EXISTS"),
            SHORT_STRING("IN"),
            SHORT_STRING("LIKE"),
            SHORT_STRING("NOT"),
            SHORT_STRING("OR"),
            SHORT_STRING("IS NULL"),
            SHORT_STRING("UNIQUE"),

            SHORT_STRING("="),
            SHORT_STRING("!="),
            SHORT_STRING("<>"),
            SHORT_STRING(">"),
            SHORT_STRING("<"),
            SHORT_STRING(">="),
            SHORT_STRING("<="),
            SHORT_STRING("!<"),
            SHORT_STRING("!>"),

            SHORT_STRING("+"),
            SHORT_STRING("-"),
            SHORT_STRING("*"),
            SHORT_STRING("/"),
            SHORT_STRING("%")
        >;
        using operator_predicate = is_iequal;
    };

    namespace internal {

        template <typename Tuple, typename TokenizationOptions = SQL_Tokenization>
        struct tokenize_advanced_impl
        { };

        template <typename TokenizationOptions, typename T, typename... List>
        struct tokenize_advanced_impl <std::tuple <T, List...>, TokenizationOptions> {
            using Tuple = std::tuple <T, List...>;

        };
    }

    template <typename String, typename KeywordSwitchBase, typename CaseSensitivite = true_>
    struct tokenize_advanced {

    };
}

#endif // MPL14_ADVANCED_TOKENIZER_HPP_INCLUDED
