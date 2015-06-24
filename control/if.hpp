#ifndef MPL14_CONTROL_IF_HPP_INCLUDED
#define MPL14_CONTROL_IF_HPP_INCLUDED

namespace mplex
{
    template <bool Condition,
              typename TrueT,
              typename FalseT>
    struct if_ {
        using type = TrueT;
    };

    template <typename TrueT,
              typename FalseT>
    struct if_ <false, TrueT, FalseT> {
        using type = FalseT;
    };

    template <bool Condition, typename TrueT, typename FalseT>
    using if_t = typename if_ <Condition, TrueT, FalseT>::type;
}

#endif // MPL14_CONTROL_IF_HPP_INCLUDED
