#pragma once

#include "idlib/math/vector.h"

#include <cassert>
#include <cmath>

class idPolar3 {
public:
    float radius;
    float theta;
    float phi;

    idPolar3() = default;
    idPolar3(const float newRadius, const float newTheta, const float newPhi) {
        Set(newRadius, newTheta, newPhi);
    }

    void Set(const float newRadius, const float newTheta, const float newPhi) {
        assert(newRadius >= 0.0f);
        radius = newRadius;
        theta = newTheta;
        phi = newPhi;
    }

    float operator[](const int index) const {
        assert(index >= 0 && index < 3);
        return (&radius)[index];
    }
    float& operator[](const int index) {
        assert(index >= 0 && index < 3);
        return (&radius)[index];
    }
    idPolar3 operator-() const { return idPolar3(radius, -theta, -phi); }

    idVec3 ToVec3() const {
        const float cosPhi = std::cos(phi);
        return idVec3(cosPhi * radius * std::cos(theta),
            cosPhi * radius * std::sin(theta), radius * std::sin(phi));
    }
};

static_assert(sizeof(idPolar3) == 12, "Recovered idPolar3 ABI changed");

