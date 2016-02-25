#ifndef MPLEX_FUNCTIONAL_LIFT_HPP_INCLUDED
#define MPLEX_FUNCTIONAL_LIFT_HPP_INCLUDED

namespace mplex
{
    template <template <typename...> class T>
    struct lift {
        template <typename... Params>
        struct apply
            : public T <Params...>
        {
        };
    };
}

#endif // MPLEX_FUNCTIONAL_LIFT_HPP_INCLUDED
