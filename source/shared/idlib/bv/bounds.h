#pragma once

#include "../math/plane.h"
#include "../math/vector.h"

#include <cmath>

// Recovered two-vector bounds layout used by the geometry reconstruction.
class idBounds {
public:
    idVec3 b[2];

    const idVec3& operator[](const int index) const {
        return b[index];
    }

    idVec3& operator[](const int index) {
        return b[index];
    }

    // Recovered from shared/idlib/bv/bounds.cpp. This scalar PC spelling is
    // the center/extents form of the original VMX implementation.
    void FromTransformedBounds(const idBounds& bounds,
        const idVec3& origin, const idMat3& axis) {
        const idVec3 center = (bounds[0] + bounds[1]) * 0.5f;
        const idVec3 extents = bounds[1] - center;
        const idVec3 transformedCenter = origin + idVec3(
            axis[0].x * center.x + axis[1].x * center.y + axis[2].x * center.z,
            axis[0].y * center.x + axis[1].y * center.y + axis[2].y * center.z,
            axis[0].z * center.x + axis[1].z * center.y + axis[2].z * center.z);
        const idVec3 transformedExtents(
            std::fabs(axis[0].x * extents.x) +
                std::fabs(axis[1].x * extents.y) +
                std::fabs(axis[2].x * extents.z),
            std::fabs(axis[0].y * extents.x) +
                std::fabs(axis[1].y * extents.y) +
                std::fabs(axis[2].y * extents.z),
            std::fabs(axis[0].z * extents.x) +
                std::fabs(axis[1].z * extents.y) +
                std::fabs(axis[2].z * extents.z));
        b[0] = transformedCenter - transformedExtents;
        b[1] = transformedCenter + transformedExtents;
    }

    // Recovered from shared/idlib/bv/bounds.cpp. Return values match the
    // original plane-side convention: 0 front, 1 back, 3 crossing.
    int PlaneSide(const idPlane& plane, const float epsilon = 0.0f) const {
        const idVec3 center = (b[0] + b[1]) * 0.5f;
        const idVec3 extents = b[1] - center;
        const float radius = std::fabs(extents.x * plane.a)
            + std::fabs(extents.y * plane.b)
            + std::fabs(extents.z * plane.c);
        const float distance = plane.Distance(center);
        if (distance - radius > epsilon) {
            return 0;
        }
        if (distance + radius < -epsilon) {
            return 1;
        }
        return 3;
    }

    // Recovered from shared/idlib/bv/bounds.cpp. This is the separating-axis
    // segment/AABB test used by GameLib obstacle routing.
    bool LineIntersection(const idVec3& start, const idVec3& end) const {
        const idVec3 lineDir = (end - start) * 0.5f;
        const idVec3 lineCenter = start + lineDir;
        const idVec3 boundsCenter = (b[0] + b[1]) * 0.5f;
        const idVec3 extents = b[1] - boundsCenter;
        const idVec3 dirAbs(
            std::fabs(lineDir.x), std::fabs(lineDir.y),
            std::fabs(lineDir.z)
        );
        const idVec3 centerDelta = lineCenter - boundsCenter;

        if (std::fabs(centerDelta.x) > extents.x + dirAbs.x
                || std::fabs(centerDelta.y) > extents.y + dirAbs.y
                || std::fabs(centerDelta.z) > extents.z + dirAbs.z) {
            return false;
        }
        if (std::fabs(centerDelta.z * lineDir.y
                - centerDelta.y * lineDir.z)
                > extents.y * dirAbs.z + extents.z * dirAbs.y) {
            return false;
        }
        if (std::fabs(lineDir.z * centerDelta.x
                - centerDelta.z * lineDir.x)
                > extents.z * dirAbs.x + extents.x * dirAbs.z) {
            return false;
        }
        return std::fabs(centerDelta.y * lineDir.x
                - lineDir.y * centerDelta.x)
            <= extents.y * dirAbs.x + extents.x * dirAbs.y;
    }

    bool RayIntersection(const idVec3& start, const idVec3& direction,
        float& scale) const {
        float minimum = -1.0e30f;
        float maximum = 1.0e30f;
        for (int axis = 0; axis < 3; ++axis) {
            if (std::fabs(direction[axis]) < 1.0e-20f) {
                if (start[axis] < b[0][axis] || start[axis] > b[1][axis]) {
                    return false;
                }
                continue;
            }
            const float inverseDirection = 1.0f / direction[axis];
            float first = (b[0][axis] - start[axis]) * inverseDirection;
            float second = (b[1][axis] - start[axis]) * inverseDirection;
            if (first > second) {
                const float swap = first;
                first = second;
                second = swap;
            }
            if (first > minimum) minimum = first;
            if (second < maximum) maximum = second;
            if (minimum > maximum) return false;
        }
        scale = minimum;
        return true;
    }

    bool SphereIntersection(const idVec3& origin, const float radius) const {
        float distanceSquared = 0.0f;
        for (int axis = 0; axis < 3; ++axis) {
            float delta = 0.0f;
            if (origin[axis] < b[0][axis]) {
                delta = b[0][axis] - origin[axis];
            } else if (origin[axis] > b[1][axis]) {
                delta = origin[axis] - b[1][axis];
            }
            distanceSquared += delta * delta;
        }
        return distanceSquared < radius * radius;
    }
};

static_assert(sizeof(idBounds) == 24, "Recovered idBounds layout changed");
