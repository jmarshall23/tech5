#pragma once

#include "idlib/math/vector.h"

#include <cstddef>
#include <cstdint>

using influenceSphereIndex_t = std::int16_t;

struct influenceSphere_t {
    idVec3 center;
    float innerRadius;
    float outerRadius;
    float angle;
};

struct alignas(16) visibleInfluenceSpheres_t {
    static constexpr int MAX_SPHERES = 256;

    int numSpheres;
    int padding[3];
    influenceSphere_t spheres[MAX_SPHERES];
};

static_assert(sizeof(influenceSphere_t) == 24,
    "Recovered influence-sphere ABI changed");
static_assert(offsetof(visibleInfluenceSpheres_t, spheres) == 16,
    "Recovered visible influence-sphere alignment changed");
