#ifndef TRANSFORM_HPP_INCLUDED
#define TRANSFORM_HPP_INCLUDED

namespace mplex {
    template <template <typename> class Target, template <typename> class Wrap, typename ... List>
    struct transform {
        using type = Target<typename Wrap<List>::type...>;
    };

    template <template <typename> class Target, template <typename> class Wrap, typename ... List>
    using transform_t = typename transform<Target, Wrap, List...>::type;
}

#endif // TRANSFORM_HPP_INCLUDED
