#pragma once

#include "idlib/math/vector.h"

#include <cassert>

class idCQuat {
public:
    float x;
    float y;
    float z;

    idCQuat() = default;
    idCQuat(const float newX, const float newY, const float newZ)
        : x(newX), y(newY), z(newZ) {}
    float operator[](const int index) const {
        assert(index >= 0 && index < 3); return (&x)[index];
    }
    float& operator[](const int index) {
        assert(index >= 0 && index < 3); return (&x)[index];
    }
};

// PDB type 23290 is an intentionally empty marker.
struct quat_t {};

static_assert(sizeof(idCQuat) == 12, "Recovered idCQuat ABI changed");

