#ifndef MPLEX_ADVANCED_TOKEN_CLASSIFICATION_HPP_INCLUDED
#define MPLEX_ADVANCED_TOKEN_CLASSIFICATION_HPP_INCLUDED

#include "../string/classification.hpp"

namespace mplex
{
    namespace integral_token_predicates
    {
        namespace internal {
            template <typename Predicate>
            struct expects {
                using type = Predicate;
            };
        }

        template <typename Tuple, typename InternalState = void>
        struct is_int_tok { };

        template <typename T, typename... List>
        struct is_int_tok <std::tuple <T, List...>, void> {
            // begin
            constexpr static const bool value = is_int_tok <std::tuple <T, List...>, internal::expects <is_digit> >::value;
        };
    }

    namespace internal
    {
//#############################################################################################################################
//#  next_is_operator_token
//#############################################################################################################################
        struct next_is_operator_token {
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

//#############################################################################################################################
//#  next_is_numeric_token
//#############################################################################################################################

        struct integral_token_options {
            using predicates = void; //std::tuple <dec, hex1, hex2, oct1, bin, dec>
        };

        struct next_is_integral {
            template <typename Tuple, typename OperatorTokens, typename MatchingPredicates>
            struct apply {};
        };

        template <typename OperatorTokens, typename AllowedTypes, typename T, typename... List>
        struct next_is_integral::apply <std::tuple <T, List...>, OperatorTokens, AllowedTypes> {

        };
    }
}

#endif // MPLEX_ADVANCED_TOKEN_CLASSIFICATION_HPP_INCLUDED
