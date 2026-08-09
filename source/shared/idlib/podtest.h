#pragma once

#include <type_traits>

// Tungsten's debug types show an empty checker class with an internal union
// containing T.  Preserve the empty runtime layout and expose the result as a
// compile-time constant for recovered container checks.
template<typename type>
class idPodTest {
public:
    template<typename unionType>
    struct withUnion_t {
        union {
            unionType t;
        } funion;
    };

    enum {
        value = std::is_trivially_copyable<type>::value
    };
};

