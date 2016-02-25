#ifndef CONFIG_HPP_INCLUDED
#define CONFIG_HPP_INCLUDED

#define UTF_CHAR

#ifdef __clang__
#   define CLANG
#elif defined(__ICC)
#   define INTEL
#   warning "This library is most likely not supported by this compiler"
#elif defined(__GNUC__)
#   define GCC
#elif defined(_MSC_VER)
#   define VCPP
#   error "This library is not supported by the microsoft compiler"
#else
#   error "Unknown compiler"
#endif

#ifdef USE_BOOST
#define HAS_BOOST_STRING_ALGORITHM
#endif

#endif // CONFIG_HPP_INCLUDED
