#ifndef TYPE_PRINT_HPP_INCLUDED
#define TYPE_PRINT_HPP_INCLUDED

#include "../config.hpp"
#include "../string/string.hpp"
#include "../fundamental/for_each_exec.hpp"
#include <iostream>

#if defined(CLANG) || defined(GCC)
#include <typeinfo>
#include <cxxabi.h>

namespace mplex {
    template <typename T, unsigned bufferSize = 1 << 16>
    static std::ostream& stream_demangled(std::ostream &stream)
    {
        char buffer[bufferSize];
        int status = 0;
        std::size_t bufSizeCpy = bufferSize;
        abi::__cxa_demangle(typeid(T).name(), buffer, &bufSizeCpy, &status);
        stream << buffer;
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
}


#endif // TYPE_PRINT_HPP_INCLUDED
