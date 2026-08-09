#pragma once

#include "idlib/math/vector.h"

// Exact member order recovered as IDA local type 13212.
class idCylinder {
public:
    idVec3 origin;
    float halfHeight;
    float radius;
};

static_assert(sizeof(idCylinder) == 20, "Recovered idCylinder ABI changed");

