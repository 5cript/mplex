#ifndef MPLEX_ALGORITHM_FIND_HPP_INCLUDED
#define MPLEX_ALGORITHM_FIND_HPP_INCLUDED

#include "../control/if.hpp"
#include "../fundamental/integral.hpp"
#include "../fundamental/is_same.hpp"

#include <type_traits>

namespace mplex {
    template <typename Tuple, typename What, typename ComparisonPredicate = is_same,
              typename Where = int_<-1>, typename Pos = int_<0>, typename SWPos = int_<0>>
    struct find
    { };

    template <typename What, typename ComparisonPredicate, typename Where, typename Pos, typename SWPos,
              typename T, typename... List>
    struct find <std::tuple<T, List...>, What, ComparisonPredicate, Where, Pos, SWPos> {

        static_assert (std::tuple_size <What>::value != 0, "The search string must not be empty");

        constexpr static const bool char_match = ComparisonPredicate::template apply <T, typename std::tuple_element <SWPos::value, What>::type >::value;

        // where is the match
        using next_where = if_vt <char_match,
                                  if_vt <Where::value == -1,
                                         Pos,
                                         Where>,
                                  int_<-1>>;

        // next index in the search word
        using next_sw = if_vt <char_match,
                               int_<SWPos::value + 1>,
                               int_<0>>;

        // next tuple to be inspected [short circuited]
        using next_tuple = if_vt <SWPos::value == std::tuple_size <What>::value - 1,
                                  std::tuple<>,
                                  std::tuple<List...>> ;

        using type = typename find <next_tuple, What, ComparisonPredicate, next_where, int_<Pos::value + 1>, next_sw>::type;
    };

    template <typename What, typename ComparisonPredicate,
              typename Where, typename Pos, typename SWPos>
    struct find <std::tuple <>, What, ComparisonPredicate, Where, Pos, SWPos>
    {
        static_assert (std::tuple_size <What>::value != 0, "The search string must not be empty");

        using type = struct this_type {
            constexpr static const bool found = SWPos::value == std::tuple_size <What>::value;
            constexpr static const int where = if_vt <found, Where, int_<-1>>::value;
            using where_t = int_<where>;
            constexpr static const int value = where;
        };
    };

    template <typename Tuple, typename What, typename ComparisonPredicate = is_same>
    using find_t = typename find <Tuple, What, ComparisonPredicate>::type;
}

#endif // FIND_HPP_INCLUDED
