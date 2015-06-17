#ifndef STRING_HPP_INCLUDED
#define STRING_HPP_INCLUDED

#include "char.hpp"

#include <tuple>
#include "../tuple/apply.hpp"

namespace mplex {
    template <char ... List>
    struct string {
        using type = std::tuple<char_<List>...>;
        enum {
            size = sizeof...(List)
        };

        template <std::size_t N>
        struct at {
            using type = typename std::tuple_element<N, type>::type;
            constexpr static const char value = std::tuple_element<N, type>::type::value;
        };

        template <std::size_t N>
        using at_t = typename at<N>::type;

        constexpr static const char c_str[] = {
            List..., '\0'
        };
    };
    template <char ... List>
    constexpr const char string<List...>::c_str[];

    template <typename ... CharArray>
    struct __string {
        using type = string<CharArray::value...>;
    };

    template <typename ... CharArray>
    using translate = typename __string<CharArray...>::type;

/*
    template <typename ... CharArray>
    struct compile_string_impl_ {
        constexpr static const char value[] = {
            CharArray::value..., '\0'
        };
    };
    template <typename ... CharArray>
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

#endif // STRING_HPP_INCLUDED