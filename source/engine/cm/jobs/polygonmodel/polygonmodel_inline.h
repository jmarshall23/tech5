#pragma once

#include "cm/collisiontypes.h"

#include <cmath>

inline int CM_BoundsPlaneSide(const idVec4& boundsMin,
    const idVec4& boundsMax, const idPlane& plane) {
    const idVec3 center(
        (boundsMin.x + boundsMax.x) * 0.5f,
        (boundsMin.y + boundsMax.y) * 0.5f,
        (boundsMin.z + boundsMax.z) * 0.5f);
    const idVec3 extents(
        boundsMax.x - center.x,
        boundsMax.y - center.y,
        boundsMax.z - center.z);
    const float radius = std::fabs(extents.x * plane.a)
        + std::fabs(extents.y * plane.b)
        + std::fabs(extents.z * plane.c);
    const float distance = plane.Distance(center);
    if (distance - radius > 0.1f) {
        return 0;
    }
    if (distance + radius < -0.1f) {
        return 1;
    }
    return 3;
}

inline bool CM_BoundsShortPlaneCull(const idBoundsShort& bounds,
    const idPlane& plane, const float compareDistance) {
    const idBounds expanded = bounds.ToBounds();
    const idVec3 center = (expanded[0] + expanded[1]) * 0.5f;
    const idVec3 extents = expanded[1] - center;
    const float radius = std::fabs(extents.x * plane.a)
        + std::fabs(extents.y * plane.b)
        + std::fabs(extents.z * plane.c);
    return std::fabs(plane.Distance(center)) > radius + compareDistance;
}
