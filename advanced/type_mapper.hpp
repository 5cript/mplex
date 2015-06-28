#ifndef MPL14_ADVANCED_TOKEN_MAPPER_HPP_INCLUDED
#define MPL14_ADVANCED_TOKEN_MAPPER_HPP_INCLUDED

#include "../control/if.hpp"
#include "../fundamental/is_same.hpp"
#include "../tuple/push_front.hpp"

#include <tuple>

namespace mplex {
    template <typename Tuple, typename SwitchBase, typename CaseSensitive>
    struct map_types
    { };

    template <typename SwitchBase, typename CaseSensitive, typename T, typename... List>
    struct map_types <std::tuple <T, List...>, SwitchBase, CaseSensitive> {
        using type =
        push_front_t <typename map_types <std::tuple <List...>, SwitchBase, CaseSensitive>::type,
                      typename SwitchBase::template apply <T, CaseSensitive>::type::template apply <T>::type >;
    };

    template <typename SwitchBase, typename CaseSensitive>
    struct map_types <std::tuple <>, SwitchBase, CaseSensitive> {
        using type = std::tuple <>;
    };

    template <typename Tuple, typename SwitchBase, typename CaseSensitive>
    using map_types_t = typename map_types <Tuple, SwitchBase, CaseSensitive>::type;
}

#endif // MPL14_ADVANCED_TOKEN_MAPPER_HPP_INCLUDED
