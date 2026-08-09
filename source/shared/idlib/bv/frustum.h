#pragma once

#include "../math/vector.h"

class idFrustum {
public:
    idFrustum()
        : origin(0.0f, 0.0f, 0.0f), axis(1.0f), dNear(0.0f), dFar(0.0f),
          dLeft(0.0f), dUp(0.0f), invFar(0.0f) {
    }

    idFrustum(const idVec3& newOrigin, const idMat3& newAxis,
        const float nearDistance, const float farDistance,
        const float farLeft, const float farUp)
        : origin(newOrigin), axis(newAxis), dNear(nearDistance),
          dFar(farDistance), dLeft(farLeft), dUp(farUp),
          invFar(farDistance != 0.0f ? 1.0f / farDistance : 0.0f) {
    }

    void ToPoints(idVec3 points[8]) const;

    // Public in the recovered PDB declaration (ordinal 13098).
    idVec3 origin;
    idMat3 axis;
    float dNear;
    float dFar;
    float dLeft;
    float dUp;
    float invFar;
};

static_assert(sizeof(idFrustum) == 68, "Recovered idFrustum ABI changed");
