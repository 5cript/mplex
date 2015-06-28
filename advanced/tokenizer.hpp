#ifndef MPL14_ADVANCED_TOKENIZER_HPP_INCLUDED
#define MPL14_ADVANCED_TOKENIZER_HPP_INCLUDED

#include "type_mapper.hpp"

#include "../string/string.hpp"
#include "../string/split.hpp"
#include "../string/remove_if.hpp"
#include "../string/inline_string.hpp"
#include "../string/compare.hpp"

#include "../fundamental/bind.hpp"
#include "../fundamental/eval_if.hpp"
#include "../fundamental/integral.hpp"

#include "../control/switch.hpp"
#include "../control/if.hpp"

#include "../tuple/apply.hpp"
#include "../tuple/find.hpp"
#include "../tuple/find_next.hpp"
#include "../tuple/copy.hpp"

#include "../math/min.hpp"

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
        struct next_is_operator_token
        {
            template <typename Tuple, typename OperatorTokens, typename ComparisonPredicate>
            struct apply {};
        };

        template <typename Tuple, typename ComparisonPredicate, typename T, typename... List>
        struct next_is_operator_token::apply <Tuple, std::tuple <T, List...>, ComparisonPredicate> {
            using slice = typename copy <Tuple, int_ <0>, min <int_ <T::size>, std::tuple_size <Tuple>>>::type;
            using slice_str = apply_t <slice, translate>;

            using equal = typename equals<ComparisonPredicate>::template apply <T, slice_str>::type;

            using type =
            lazy_if_t <equal,
                       then_ <bool_ <true>>,
                       else_ <next_is_operator_token, Tuple, std::tuple <List...>, ComparisonPredicate>
            >;

            constexpr static const bool value = type::value;
        };

        template <typename Tuple, typename ComparisonPredicate>
        struct next_is_operator_token::apply <Tuple, std::tuple <>, ComparisonPredicate> {
            using type = bool_ <false>;
            constexpr static const bool value = type::value;
        };

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
