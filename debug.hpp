#ifndef DEBUG_HPP_INCLUDED
#define DEBUG_HPP_INCLUDED

#include <iostream>

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
#include <typeinfo>
#include <cxxabi.h>

namespace mpl = boost::mpl;

template <typename T, unsigned bufferSize = 1 << 16>
static void streamDemangled(std::ostream &stream)
{
    char buffer[bufferSize];
    int status = 0;
    std::size_t bufSizeCpy = bufferSize;
    abi::__cxa_demangle(typeid(T).name(), buffer, &bufSizeCpy, &status);
    stream << buffer;
}

template <typename Sequence, unsigned ReverseCounter>
struct PrintSequence
{
    static void print(char const *glue)
    {
        streamDemangled <typename mpl::at <Sequence,
                mpl::int_ < PrintSequence <Sequence, 1>::size_ - ReverseCounter> >::type > (std::cout);
        std::cout << glue;

        PrintSequence <Sequence, ReverseCounter - 1>::print(glue);
    }
};

template <typename Sequence>
struct PrintSequence <Sequence, 1>
{
    enum
    {
        size_ = mpl::size <Sequence>::value
    };

    static void print(char const *glue)
    {
        streamDemangled <typename mpl::at <Sequence, mpl::int_ < size_ - 1> >::type > (std::cout);
        std::cout << glue;
    }
};

template <typename Sequence, unsigned ReverseCounter, typename CastT = unsigned>
struct PrintNumberSequence
{
    static void print(char const *glue)
    {
        using vtype = typename mpl::at_c <Sequence, PrintNumberSequence <Sequence, 1>::size_ - ReverseCounter>::type;
        std::cout << static_cast <CastT> (vtype::value) << glue;

        PrintNumberSequence <Sequence, ReverseCounter - 1, CastT>::print(glue);
    }
};

template <typename Sequence, typename CastT>
struct PrintNumberSequence <Sequence, 1, CastT>
{
    enum
    {
        size_ = mpl::size <Sequence>::value
    };

    static void print(char const *)
    {
        std::cout << static_cast <CastT> (mpl::at_c <Sequence, size_ - 1>::type::value);
    }
};

#define PRINT_NUMBERS_1(SEQUENCE, GLUE) \
PrintNumberSequence<SEQUENCE, mpl::size<SEQUENCE>::value>::print(GLUE)

#define PRINT_NUMBERS_2(SEQUENCE, GLUE, CONVERT) \
PrintNumberSequence<SEQUENCE, std::tuple_size<SEQUENCE>::value, CONVERT>::print(GLUE)

// this macro overloading technique originally taken from "stackoverflow"
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define PRINT_NUMBERS(...) GET_MACRO(__VA_ARGS__, PRINT_NUMBERS_2, PRINT_NUMBERS_1)(__VA_ARGS__)

#define PRINT_TYPES(SEQUENCE, GLUE) \
PrintSequence<SEQUENCE, mpl::size<SEQUENCE>::value>::print(GLUE);

#define PRINT_SINGLE(TYPE) \
streamDemangled<TYPE>(std::cout)

#define STREAM_SINGLE(TYPE, STREAM) \
streamDemangled<TYPE>(STREAM)

#endif // DEBUG_HPP_INCLUDED
