#pragma once

#include "../math/vector.h"

// Minimal tungsten ABI facade used while the BFG idBounds implementation is
// still the baseline for the larger geometry subsystem.
class idBounds {
public:
    idVec3 b[2];

    const idVec3& operator[](const int index) const {
        return b[index];
    }

    idVec3& operator[](const int index) {
        return b[index];
    }
};

static_assert(sizeof(idBounds) == 24, "Recovered idBounds layout changed");
