#pragma once

#include "idlib/typesafenumber.h"
#include "idlib/math/vector.h"

enum SphereUnique_t : int;
typedef idTypesafeNumber<float, SphereUnique_t> sphere_t;

class idSphere {
public:
    idVec3 origin;
    float radius;

    idSphere() = default;
    idSphere(const idVec3& newOrigin, const float newRadius)
        : origin(newOrigin), radius(newRadius) {}
    void Clear() { origin.Zero(); radius = -1.0f; }
    void Zero() { origin.Zero(); radius = 0.0f; }
    bool IsCleared() const { return radius < 0.0f; }
    void SetOrigin(const idVec3& newOrigin) { origin = newOrigin; }
    void SetRadius(const float newRadius) { radius = newRadius; }
    const idVec3& GetOrigin() const { return origin; }
    float GetRadius() const { return radius; }
    bool ContainsPoint(const idVec3& point) const {
        return (point - origin).LengthSqr() < radius * radius;
    }
    bool LineIntersection(const idVec3& start, const idVec3& end) const;
};

static_assert(sizeof(idSphere) == 16, "Recovered idSphere ABI changed");
static_assert(sizeof(sphere_t) == 4, "Recovered sphere_t ABI changed");
