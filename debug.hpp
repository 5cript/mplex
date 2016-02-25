#ifndef DEBUG_HPP_INCLUDED
#define DEBUG_HPP_INCLUDED

#include <iostream>
#include <tuple>

/*
#include <boost/mpl/vector.hpp>
#include <boost/mpl/vector_c.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/arithmetic.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/accumulate.hpp>
#include <boost/mpl/inserter.hpp>
#include <boost/mpl/distance.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/copy.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/sort.hpp>
#include <boost/mpl/map.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/range_c.hpp>
#include <boost/mpl/bitwise.hpp>
#include <boost/mpl/count.hpp>
#include <boost/mpl/count_if.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/insert_range.hpp>
*/
#include <typeinfo>
#include <cxxabi.h>

template <typename T, unsigned bufferSize = 1 << 16>
static std::ostream& streamDemangled(std::ostream &stream)
{
    char buffer[bufferSize];
    int status = 0;
    std::size_t bufSizeCpy = bufferSize;
    abi::__cxa_demangle(typeid(T).name(), buffer, &bufSizeCpy, &status);
    stream << buffer;
    return stream;
}

template <typename Sequence, unsigned ReverseCounter>
struct PrintSequence
{
    static void print(char const *glue)
    {
        streamDemangled <typename std::tuple_element <PrintSequence <Sequence, 1>::size_ - ReverseCounter, Sequence >::type> (std::cout);
        std::cout << glue;

        PrintSequence <Sequence, ReverseCounter - 1>::print(glue);
    }
};

template <typename Sequence>
struct PrintSequence <Sequence, 1>
{
    enum
    {
        size_ = std::tuple_size <Sequence>::value
    };

    static void print(char const *glue)
    {
        streamDemangled <typename std::tuple_element <size_ - 1, Sequence >::type> (std::cout);
        std::cout << glue;
    }
};

template <typename Sequence, unsigned ReverseCounter, typename CastT = unsigned>
struct PrintNumberSequence
{
    static std::ostream& print(char const *glue)
    {
        using vtype = typename std::tuple_element <PrintNumberSequence <Sequence, 1>::size_ - ReverseCounter, Sequence>::type;
        std::cout << static_cast <CastT> (vtype::value) << glue;

        return PrintNumberSequence <Sequence, ReverseCounter - 1, CastT>::print(glue);
    }
};

template <typename Sequence, typename CastT>
struct PrintNumberSequence <Sequence, 1, CastT>
{
    enum
    {
        size_ = std::tuple_size <Sequence>::value
    };

    static std::ostream& print(char const *)
    {
        std::cout << static_cast <CastT> (std::tuple_element <size_ - 1, Sequence>::type::value);
        return std::cout;
    }
};


template <typename Sequence, typename CastT>
struct PrintNumberSequence <Sequence, 0, CastT>
{
    enum
    {
        size_ = 0
    };

    static std::ostream& print(char const*)
    {
        return std::cout;
    }
};

#define PRINT_NUMBERS_1(SEQUENCE, GLUE) \
PrintNumberSequence<SEQUENCE, std::tuple_size<SEQUENCE>::value>::print(GLUE)

#define PRINT_NUMBERS_2(SEQUENCE, GLUE, CONVERT) \
PrintNumberSequence<SEQUENCE, std::tuple_size<SEQUENCE>::value, CONVERT>::print(GLUE)

#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define PRINT_NUMBERS(...) GET_MACRO(__VA_ARGS__, PRINT_NUMBERS_2, PRINT_NUMBERS_1)(__VA_ARGS__)

#define PRINT_TYPES(SEQUENCE, GLUE) \
PrintSequence<SEQUENCE, std::tuple_size<SEQUENCE>::value>::print(GLUE);

#define PRINT_SINGLE(TYPE) \
streamDemangled<TYPE>(std::cout)

#define STREAM_SINGLE(TYPE, STREAM) \
streamDemangled<TYPE>(STREAM)

#endif // DEBUG_HPP_INCLUDED
