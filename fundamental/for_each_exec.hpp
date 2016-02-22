#ifndef FOR_EACH_EXEC_H_INCLUDED
#define FOR_EACH_EXEC_H_INCLUDED

#include <tuple>
#include <utility>

namespace mplex {
    template <typename Tuple, typename Functor>
    struct for_each {};

    template <typename Functor, typename T, typename... List>
    struct for_each <std::tuple <T, List...>, Functor> {
        template <typename... Params>
        inline static void execute(Params&&... list) {
            Functor::template apply <T>::execute(list...);
            for_each <std::tuple <List...>, Functor>::template execute<Params...>(std::forward <Params>(list)...);
        }
    };

    template <typename Functor>
    struct for_each <std::tuple<>, Functor> {
        template <typename... Params>
        inline static void execute(Params&&...) { }
    };
}

#endif // FOR_EACH_EXEC_H_INCLUDED
