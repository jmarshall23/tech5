#pragma once

#include "idlib/math/vector.h"

#include <cassert>

class idWinding2D {
public:
    static constexpr int MAX_POINTS = 32;
    int numPoints;
    idVec2 p[MAX_POINTS];
    idVec2 st[MAX_POINTS];

    idWinding2D() : numPoints(0) {}
    void Clear() { numPoints = 0; }
    int GetNumPoints() const { return numPoints; }
    bool AddPoint(const idVec2& point, const idVec2& texCoord = idVec2()) {
        if (numPoints >= MAX_POINTS) return false;
        p[numPoints] = point;
        st[numPoints] = texCoord;
        ++numPoints;
        return true;
    }
    idVec2& operator[](const int index) {
        assert(index >= 0 && index < numPoints); return p[index];
    }
    const idVec2& operator[](const int index) const {
        assert(index >= 0 && index < numPoints); return p[index];
    }
};

static_assert(sizeof(idWinding2D) == 516, "Recovered idWinding2D ABI changed");

