#pragma once

#include "surface.h"

class idSurface_Polytope : public idSurface {
public:
    idSurface_Polytope() = default;
    ~idSurface_Polytope() = default;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idSurface_Polytope) == 64,
    "Recovered idSurface_Polytope ABI changed");
#endif
