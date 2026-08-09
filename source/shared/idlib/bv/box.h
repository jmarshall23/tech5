#pragma once

#include "bounds.h"

#include <cmath>

class idBox {
public:
    idVec3 center;
    idVec3 extents;
    idMat3 axis;

    idBox() : center(0.0f, 0.0f, 0.0f), extents(0.0f, 0.0f, 0.0f), axis(1.0f) {}

    explicit idBox(const idBounds& bounds) : axis(1.0f) {
        SetFromBounds(bounds);
    }

    idBox(const idBounds& bounds, const idVec3& origin, const idMat3& newAxis)
        : axis(newAxis) {
        SetFromBounds(bounds);
        const idVec3 localCenter = center;
        center.Set(
            origin.x + newAxis[0].x * localCenter.x
                + newAxis[1].x * localCenter.y + newAxis[2].x * localCenter.z,
            origin.y + newAxis[0].y * localCenter.x
                + newAxis[1].y * localCenter.y + newAxis[2].y * localCenter.z,
            origin.z + newAxis[0].z * localCenter.x
                + newAxis[1].z * localCenter.y + newAxis[2].z * localCenter.z);
    }

    bool ContainsPoint(const idVec3& point) const {
        const idVec3 relative = point - center;
        return std::fabs(axis[0].Dot(relative)) <= extents.x
            && std::fabs(axis[1].Dot(relative)) <= extents.y
            && std::fabs(axis[2].Dot(relative)) <= extents.z;
    }

    void AxisProjection(const idMat3& projectionAxis, idBounds& bounds) const {
        for (int index = 0; index < 3; ++index) {
            const float projectedCenter = projectionAxis[index].Dot(center);
            const float projectedRadius =
                std::fabs(projectionAxis[index].Dot(axis[0])) * extents.x
                + std::fabs(projectionAxis[index].Dot(axis[1])) * extents.y
                + std::fabs(projectionAxis[index].Dot(axis[2])) * extents.z;
            bounds[0][index] = projectedCenter - projectedRadius;
            bounds[1][index] = projectedCenter + projectedRadius;
        }
    }

private:
    void SetFromBounds(const idBounds& bounds) {
        center = (bounds[0] + bounds[1]) * 0.5f;
        extents = bounds[1] - center;
    }
};

struct box {
    int c0min;
    int c0max;
    int c1min;
    int c1max;
    int c2min;
    int c2max;
    int volume;
    int colorcount;
};

static_assert(sizeof(idBox) == 60, "Recovered idBox ABI changed");
