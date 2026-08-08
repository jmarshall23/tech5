#pragma once

#include "../math/vector.h"

// tungsten.exe.h type 13101.
class idBounds2D {
public:
    idVec2 bounds[2];

    bool AddPoint(const idVec2& point);
    bool ContainsPoint(const idVec2& point) const;
    bool IntersectBounds(const idBounds2D& other) const;

    const idVec2& operator[](const int index) const {
        return bounds[index];
    }

    idVec2& operator[](const int index) {
        return bounds[index];
    }
};

static_assert(sizeof(idBounds2D) == 16, "Recovered idBounds2D layout changed");
