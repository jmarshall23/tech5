#pragma once

#include "idlib/math/vector.h"

#include <cassert>
#include <cmath>

class idPlane {
public:
    float a;
    float b;
    float c;
    float d;

    idPlane() = default;
    idPlane(const float newA, const float newB, const float newC, const float newD)
        : a(newA), b(newB), c(newC), d(newD) {}
    idPlane(const idVec3& normal, const float distance)
        : a(normal.x), b(normal.y), c(normal.z), d(-distance) {}

    float operator[](const int index) const {
        assert(index >= 0 && index < 4); return (&a)[index];
    }
    float& operator[](const int index) {
        assert(index >= 0 && index < 4); return (&a)[index];
    }
    idPlane operator-() const { return idPlane(-a, -b, -c, -d); }
    idVec3& Normal() { return *reinterpret_cast<idVec3*>(&a); }
    const idVec3& Normal() const { return *reinterpret_cast<const idVec3*>(&a); }
    float Dist() const { return -d; }
    void SetDist(const float distance) { d = -distance; }
    float Distance(const idVec3& point) const {
        return a * point.x + b * point.y + c * point.z + d;
    }
    bool Compare(const idPlane& other, const float normalEpsilon,
            const float distanceEpsilon) const {
        return std::fabs(a - other.a) <= normalEpsilon
            && std::fabs(b - other.b) <= normalEpsilon
            && std::fabs(c - other.c) <= normalEpsilon
            && std::fabs(d - other.d) <= distanceEpsilon;
    }
    int GetDimension() const { return 4; }
    const float* ToFloatPtr() const { return &a; }
    float* ToFloatPtr() { return &a; }
};

static_assert(sizeof(idPlane) == 16, "Recovered idPlane ABI changed");

