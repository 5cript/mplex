#ifndef MPLEX_STRING_STRING_HPP_INCLUDED
#define MPLEX_STRING_STRING_HPP_INCLUDED

#include "char.hpp"
#include "../tuple/apply.hpp"
#include "../control/if.hpp"

#include "../tuple/front.hpp"
#include "../tuple/back.hpp"
#include "../tuple/pop_front.hpp"
#include "../tuple/pop_back.hpp"
#include "../tuple/push_back.hpp"
#include "../tuple/push_front.hpp"

#include <type_traits>
#include <tuple>
#include <iosfwd>

namespace mplex
{
    template <char ... List>
    struct string;

    template <typename... CharArray>
    struct __string {
        using type = string <CharArray::value...>;
    };

    template <typename... CharArray>
    using translate = typename __string <CharArray...>::type;

    template <char ... List>
    struct string
    {
        using size_type = std::make_signed <std::size_t>::type;

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

        template <typename Char>
        struct push_front {
            using type = apply_t <push_front_t <type, Char>, translate>;
        };
        template <typename Char> using push_front_t = typename push_front <Char>::type;

        template <typename Char>
        struct push_back {
            using type = apply_t <push_back_t <type, Char>, translate>;
        };
        template <typename Char> using push_back_t = typename push_back <Char>::type;

        struct pop_front {
            using type = apply_t <pop_front_t <type>, translate>;
        };
        using pop_front_t = typename pop_front::type;

        struct pop_back {
            using type = apply_t <pop_back_t <type>, translate>;
        };
        using pop_back_t = typename pop_back::type;

        struct front {
            using type = front_t <type>;
        };
        using front_t = typename front::type;

        struct back {
            using type = back_t <type>;
        };
        using back_t = typename back::type;

        using empty = bool_ <size == 0>;

        constexpr static const size_type npos = -1;
    };
    template <char ... List>
    constexpr const char string <List...>::c_str[];

    template <typename GlueString>
    struct print_string {
        using return_type = std::ostream&;

        template <typename String>
        struct apply {
            inline static std::ostream& execute(std::ostream& stream) {
                stream << String::c_str << GlueString::c_str;
                return stream;
            }
        };
    };

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
            mplex::if_vt <counter == size_ - 1, \
                        T <data_[indexList]...>, \
                        _makeString <counter+1, T, indexList..., counter>>::type;\
        }; \
    \
        struct makeString { \
            using type = _makeString<0, mplex::string>::type; \
        }; \
    }; \
    using NAME = mplex::apply_t<StringHolder_ ## NAME::makeString::type, mplex::translate>


} // mplex

#endif // MPLEX_STRING_STRING_HPP_INCLUDED
