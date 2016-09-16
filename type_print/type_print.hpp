#ifndef TYPE_PRINT_HPP_INCLUDED
#define TYPE_PRINT_HPP_INCLUDED

#include "../config.hpp"
#include "../string/string.hpp"
#include "../string/inline_string.hpp"
#include "../fundamental/for_each_exec.hpp"

#ifdef HAS_BOOST_STRING_ALGORITHM
#include <boost/algorithm/string/replace.hpp>
#endif

#include <iostream>
#include <sstream>

#if defined(CLANG) || defined(GCC)
#include <typeinfo>

#ifndef __BORLANDC__
#	include <cxxabi.h>
#endif

namespace mplex {
    template <typename T, unsigned bufferSize = 1 << 16>
    static std::ostream& stream_demangled(std::ostream &stream)
	{
#ifndef __BORLANDC__
		char buffer[bufferSize];
		int status = 0;
		std::size_t bufSizeCpy = bufferSize;
		abi::__cxa_demangle(typeid(T).name(), buffer, &bufSizeCpy, &status);
		stream << buffer;
#else
		stream << typeid(T).name();
#endif
		return stream;
    }
}
#else
namespace mplex {
    template <typename T, unsigned bufferSize = 1 << 16>
    static std::ostream& stream_demangled(std::ostream &stream)
    {
        stream << typeid(T).name();
        return stream;
    }
}
#endif

namespace mplex {
    namespace internal {
        template <typename Sequence, unsigned ReverseCounter>
        struct print_sequence {
            static inline void print(std::ostream& stream, char const* glue)
            {
                stream_demangled <typename std::tuple_element <print_sequence <Sequence, 1>::size_ - ReverseCounter, Sequence >::type> (stream);
                stream << glue;

                print_sequence <Sequence, ReverseCounter - 1>::print(stream, glue);
            }
        };

        template <typename Sequence>
        struct print_sequence <Sequence, 1> {
            enum {
                size_ = std::tuple_size <Sequence>::value
            };

            static inline void print(std::ostream& stream, char const *glue)
            {
                stream_demangled <typename std::tuple_element <size_ - 1, Sequence >::type> (stream);
                stream << glue;
            }
        };

        template <typename Glue>
        struct print_tuple_impl {
            template <typename Tuple>
            struct apply {
                static inline void execute(std::ostream& stream) {
                    print_sequence <Tuple, std::tuple_size <Tuple>::value>::print(stream, Glue::c_str);
                }
            };
        };
    }

    template <typename StringList, typename Glue = SHORT_STRING(" ")>
    inline std::ostream& print_string_list(std::ostream& stream = std::cout) {
        for_each <StringList, print_string<Glue> >::execute(stream);
        return stream;
    }

    template <typename T>
    inline std::ostream& print_single(std::ostream& stream = std::cout) {
        stream_demangled<T>(stream);
        return stream;
    }

    template <typename Tuple, typename Glue = SHORT_STRING(", ")>
    inline std::ostream& print_tuple(std::ostream& stream = std::cout) {
        internal::print_tuple_impl <Glue>::template apply <Tuple>::execute(stream);
        return stream;
    }

    // WARNING! THIS MAKE THE OUTPUT LESS CORRECT, BUT MORE READABLE
    #ifdef HAS_BOOST_STRING_ALGORITHM
    inline std::string declutter_mplex_type_name (std::string const& typenom) {
        std::string result = typenom;

        auto replace = [&](std::string const& what, std::string const& with) {
            boost::ireplace_all (result, what, with);
        };

        replace ("std::integral_constant<int, ", "int_<");
        replace ("std::integral_constant<long, ", "long_<");
        replace ("std::integral_constant<short, ", "short_<");
        replace ("std::integral_constant<unsigned, ", "unsigned_<");
        replace ("std::integral_constant<unsigned int, ", "unsigned_<");
        replace ("std::integral_constant<long long, ", "long_long_<");
        replace ("std::integral_constant<unsigned long long, ", "unsigned_long_long_<");
        replace ("std::integral_constant<char, ", "char_<");
        replace ("std::integral_constant<unsigned char, ", "unsigned_char_<");
        replace ("std::integral_constant<bool, ", "bool_<");

        // placeholders
        replace ("mplex::placeholders::_<1u>", "_1");
        replace ("mplex::placeholders::_<2u>", "_2");
        replace ("mplex::placeholders::_<3u>", "_3");
        replace ("mplex::placeholders::_<4u>", "_4");
        replace ("mplex::placeholders::_<5u>", "_5");
        replace ("mplex::placeholders::_<6u>", "_6");
        replace ("mplex::placeholders::_<7u>", "_7");
        replace ("mplex::placeholders::_<8u>", "_8");
        replace ("mplex::placeholders::_<9u>", "_9");
        replace ("mplex::placeholders::_<10u>", "_10");
        replace ("mplex::placeholders::_<11u>", "_11");
        replace ("mplex::placeholders::_<12u>", "_12");
        replace ("mplex::placeholders::_<13u>", "_13");
        replace ("mplex::placeholders::_<14u>", "_14");
        replace ("mplex::placeholders::_<15u>", "_15");
        replace ("mplex::placeholders::_<16u>", "_16");
        replace ("mplex::placeholders::_<17u>", "_17");
        replace ("mplex::placeholders::_<18u>", "_18");
        replace ("mplex::placeholders::_<19u>", "_19");
        replace ("mplex::placeholders::_<20u>", "_20");

        replace (" >", ">");

        replace ("mplex::", "");


        replace ("mplex::internal", "intern");
        replace ("std::tuple", "tuple");

        for (int i = 0x20 /* space */; i != 127; ++i)
        {
            std::string c;
            c.push_back((char)i);
            replace(std::string("(char)") + std::to_string(i), std::string("'") + c + "'");
        }

        return result;
    }

    template <typename T>
    inline std::ostream& print_single_decluttered (std::ostream& stream = std::cout) {
        std::stringstream sstr;
        stream_demangled<T>(sstr);
        stream << declutter_mplex_type_name(sstr.str());
        return stream;
    }

    #endif
}


#endif // TYPE_PRINT_HPP_INCLUDED
