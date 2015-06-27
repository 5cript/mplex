#ifndef MPL14_STRING_STRING_HPP_INCLUDED
#define MPL14_STRING_STRING_HPP_INCLUDED

#include "char.hpp"
#include "../tuple/apply.hpp"
#include "../control/if.hpp"

#include <type_traits>
#include <tuple>

namespace mplex
{
    template <char ... List>
    struct string
    {
        using size_type = std::make_signed_t <std::size_t>;

        using type = std::tuple <char_ <List>...>;

        constexpr static const size_type size = sizeof...(List);

        template <std::size_t N>
        struct at {
            static_assert(N < size, "Index out of bounds");

            using type = typename std::tuple_element <N, type>::type;
            constexpr static const char value = std::tuple_element <N, type>::type::value;
        };

        template <std::size_t N>
        using at_t = typename at <N>::type;

        constexpr static const char c_str[] = {
                List..., '\0'
        };

        constexpr static const size_type npos = -1;
    };
    template <char ... List>
    constexpr const char string <List...>::c_str[];

    template <typename... CharArray>
    struct __string {
        using type = string <CharArray::value...>;
    };

    template <typename... CharArray>
    using translate = typename __string <CharArray...>::type;

/*
    template <typename... CharArray>
    struct compile_string_impl_ {
        constexpr static const char value[] = {
            CharArray::value..., '\0'
        };
    };
    template <typename... CharArray>
    constexpr const char compile_string_impl_<CharArray...>::value[];

    template <typename StringT>
    struct compile_string {
        constexpr static const char* const value = apply<typename StringT::type, compile_string_impl_>::type::value;
    };
*/

#define MAKE_STRING(NAME, CONTENT) \
    class StringHolder_ ## NAME \
    { \
    private: \
        constexpr static const char* const data_ = CONTENT; \
        constexpr static const std::size_t size_ = sizeof(CONTENT); \
    public: \
        template <std::size_t counter, template <char ...> class T, std::size_t ... indexList> \
        struct _makeString { \
            using type = typename \
            mplex::if_ <counter == size_ - 1, \
                        T <data_[indexList]...>, \
                        _makeString <counter+1, T, indexList..., counter>>::type::type;\
        }; \
    \
        struct makeString { \
            using type = _makeString<0, mplex::string>::type; \
        }; \
    }; \
    using NAME = mplex::apply_t<StringHolder_ ## NAME::makeString::type, mplex::translate>


} // mplex

#endif // MPL14_STRING_STRING_HPP_INCLUDED
