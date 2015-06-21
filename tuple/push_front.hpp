#ifndef PUSH_FRONT_HPP_INCLUDED
#define PUSH_FRONT_HPP_INCLUDED

#include <tuple>

namespace mplex
{
    /** @param Tuple A tuple.
     *  @param Elem An arbitrary type.
     *
     *  @return The same tuple with one element ("Elem") more in the front.
     */
    template <typename Tuple, typename Elem>
    struct push_front
    {
    };

    template <typename Elem, typename ... List>
    struct push_front <std::tuple <List...>, Elem>
    {
        using type = std::tuple <Elem, List...>;
    };

    template <typename Tuple, typename Elem>
    using push_front_t = typename push_front <Tuple, Elem>::type;
}

#endif // PUSH_FRONT_HPP_INCLUDED
