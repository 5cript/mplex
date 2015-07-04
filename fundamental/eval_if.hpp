#ifndef MPL14_FUNDAMENTAL_EVAL_IF_HPP_INCLUDED
#define MPL14_FUNDAMENTAL_EVAL_IF_HPP_INCLUDED

#include "integral.hpp"

namespace mplex {

    template <typename Condition, typename Fallback, typename Function, typename... Parameters>
    struct eval_if_default
    {
        using type = Fallback; // TODO: think about something more meaningfull here
    };

    template <typename Fallback, typename Function, typename... Parameters>
    struct eval_if_default <true_, Fallback, Function, Parameters...>
    {
        using type = typename Function::template apply <Parameters...>::type;
    };

    template <typename Condition, typename Function, typename... Parameters>
    struct eval_if
    {
        using type = void; // TODO: think about something more meaningfull here
    };

    template <typename Function, typename... Parameters>
    struct eval_if <true_, Function, Parameters...>
    {
        using type = typename Function::template apply <Parameters...>::type;
    };

    template <typename Condition, typename Function, typename... Parameters>
    using eval_if_t = typename eval_if <Condition, Function, Parameters...>::type;

    template <typename Condition, typename Fallback, typename Function, typename... Parameters>
    using eval_if_default_t = typename eval_if_default <Condition, Fallback, Function, Parameters...>::type;
}

#endif // MPL14_FUNDAMENTAL_EVAL_IF_HPP_INCLUDED
