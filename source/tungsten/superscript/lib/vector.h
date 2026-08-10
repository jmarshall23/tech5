#pragma once

#include "../../../shared/idlib/containers/array.h"

// SuperScript exposes a compact three-component vector at its ABI boundary.
// The unrelated six-float vector_t typedef is retained from the PDB types.
struct ssVector {
    float x;
    float y;
    float z;
};

using vector_t = idArray<float, 6>;

static_assert(sizeof(ssVector) == 12, "Recovered ssVector layout changed");
