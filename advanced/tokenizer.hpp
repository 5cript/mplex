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
    namespace embedded_language {
        template <typename T>
        struct unclassified_token {
            using type = T;
        };

        template <typename T>
        struct keyword {
            using id = T;
        };
    }

    namespace internal {
        struct make_unclassified_token {
            template <typename T>
            struct apply {
                using type = embedded_language::unclassified_token <T>;
            };
        };

        struct make_keyword {
            template <typename T>
            struct apply {
                using type = embedded_language::keyword<T>;
            };
        };

        template <typename... Keywords>
        struct make_keyword_table {
            using type = switch_base <default_ <make_unclassified_token>,
                                      case_ <Keywords, make_keyword>...>;
        };
    }

    template <typename String, typename Keywords, typename CaseSensitive = true_>
    struct tokenize {
        using sbase = typename apply_t <Keywords, internal::make_keyword_table>::type;

        using type = map_types_t <make_lexemes_t <String>, sbase, CaseSensitive>;
    };

    template <typename String, typename Keywords, typename CaseSensitive = true_>
    using tokenize_t = typename tokenize <String, Keywords, CaseSensitive>::type;
}

#endif // MPL14_ADVANCED_TOKENIZER_HPP_INCLUDED
