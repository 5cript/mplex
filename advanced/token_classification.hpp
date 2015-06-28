#ifndef MPL14_ADVANCED_TOKEN_CLASSIFICATION_HPP_INCLUDED
#define MPL14_ADVANCED_TOKEN_CLASSIFICATION_HPP_INCLUDED

namespace mplex {
    namespace embedded_language {
        template <typename T>
        struct operator_ {
            using type = T;
        };

        template <typename T>
        struct identifier {
            using type = T;
        };

        template <typename T>
        struct number {
            using type = T;
        };
    }
}

#endif // MPL14_ADVANCED_TOKEN_CLASSIFICATION_HPP_INCLUDED
