#pragma once

#include "gamelib/animstack/animator_synced.h"

#include <algorithm>
#include <cmath>

template<int dimension>
class idAnimator_TurretNxN;

template<>
class alignas(4) idAnimator_TurretNxN<3> : public idAnimator_Synced {
public:
    struct triangle_t {
        unsigned char vertex1;
        unsigned char vertex2;
        unsigned char vertex3;
    };

    struct blendgrid_t {
        idVec3 vertexLocations[9];
        triangle_t blendTriangles[8];

        blendgrid_t() {
            int vertex = 0;
            for (int row = 0; row < 3; ++row) {
                for (int column = 0; column < 3; ++column) {
                    vertexLocations[vertex++].Set(
                        static_cast<float>(column - 1),
                        static_cast<float>(1 - row), 1.0f);
                }
            }
            const triangle_t recovered[8] = {
                {0, 1, 3}, {1, 3, 4}, {1, 2, 4}, {2, 4, 5},
                {3, 4, 6}, {4, 6, 7}, {4, 5, 7}, {5, 7, 8}
            };
            for (int index = 0; index < 8; ++index)
                blendTriangles[index] = recovered[index];
        }
    };

    idAnimator_TurretNxN() : lastBlendTriangle(0), vertexAliasHandles{} {}
    ~idAnimator_TurretNxN() override = default;

    void SetParameters(idGameTimeManager* timeManager, idAnimStack* stack,
            const idAnimAliasHandle* handles, const bool additive) {
        idAnimatorParms_Base parameters;
        parameters.animStack = stack;
        parameters.name = "ta";
        parameters.originBlend = 0;
        parameters.alpha = 1.0f;
        parameters.weightGroup = MD6_WEIGHTGROUP_ALL;
        parameters.filterGroup = MD6_WEIGHTGROUP_ALL;
        parameters.blendOp = additive ? 4 : 0;
        Init(timeManager, parameters);
        if (handles != nullptr)
            for (int index = 0; index < 9; ++index)
                vertexAliasHandles[index] = handles[index];
    }

    void Update(const idVec3& point, const int currentTime,
            idTreeAnimator* animator) {
        lastBlendTriangle = FindContainingBlendTriangle(point);
        idVec3 weights;
        FindWeights(lastBlendTriangle, point, weights);
        const triangle_t& triangle =
            Grid().blendTriangles[lastBlendTriangle];
        const idAnimAliasHandle handles[3] = {
            vertexAliasHandles[triangle.vertex1],
            vertexAliasHandles[triangle.vertex2],
            vertexAliasHandles[triangle.vertex3]
        };
        const float values[3] = {weights.x, weights.y, weights.z};
        SetAnimHandlesAndWeights(animator, currentTime, handles, 3,
            values, 3);
    }

    int lastBlendTriangle;
    idAnimAliasHandle vertexAliasHandles[9];

private:
    static const blendgrid_t& Grid() {
        static const blendgrid_t grid;
        return grid;
    }

    bool IsInBlendTriangle(const idVec3& point,
            const int triangleIndex) const {
        const triangle_t& triangle = Grid().blendTriangles[triangleIndex];
        const idVec3& a = Grid().vertexLocations[triangle.vertex1];
        const idVec3& b = Grid().vertexLocations[triangle.vertex2];
        const idVec3& c = Grid().vertexLocations[triangle.vertex3];
        const float ab = (point.y - a.y) * (b.x - a.x) -
            (point.x - a.x) * (b.y - a.y);
        const float bc = (point.y - b.y) * (c.x - b.x) -
            (point.x - b.x) * (c.y - b.y);
        const float ca = (point.y - c.y) * (a.x - c.x) -
            (point.x - c.x) * (a.y - c.y);
        return (ab >= 0.0f && bc >= 0.0f && ca >= 0.0f) ||
            (ab <= 0.0f && bc <= 0.0f && ca <= 0.0f);
    }

    int FindContainingBlendTriangle(const idVec3& point) const {
        if (lastBlendTriangle >= 0 && lastBlendTriangle < 8 &&
                IsInBlendTriangle(point, lastBlendTriangle))
            return lastBlendTriangle;
        for (int index = 0; index < 8; ++index)
            if (IsInBlendTriangle(point, index)) return index;
        return 0;
    }

    void FindWeights(const int triangleIndex, const idVec3& point,
            idVec3& weights) const {
        const triangle_t& triangle = Grid().blendTriangles[triangleIndex];
        const idVec3& a = Grid().vertexLocations[triangle.vertex1];
        const idVec3& b = Grid().vertexLocations[triangle.vertex2];
        const idVec3& c = Grid().vertexLocations[triangle.vertex3];
        const float denominator = (b.y - c.y) * (a.x - c.x) +
            (c.x - b.x) * (a.y - c.y);
        if (std::fabs(denominator) <= 1.0e-6f) {
            weights.Set(1.0f, 0.0f, 0.0f);
            return;
        }
        weights.x = ((b.y - c.y) * (point.x - c.x) +
            (c.x - b.x) * (point.y - c.y)) / denominator;
        weights.y = ((c.y - a.y) * (point.x - c.x) +
            (a.x - c.x) * (point.y - c.y)) / denominator;
        weights.z = 1.0f - weights.x - weights.y;
    }
};

using idAnimator_Turret = idAnimator_TurretNxN<3>;
using idAnimator_Turret3x3 = idAnimator_TurretNxN<3>;

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAnimator_Turret::triangle_t) == 3,
    "Recovered turret triangle ABI changed");
static_assert(sizeof(idAnimator_Turret::blendgrid_t) == 132,
    "Recovered turret blend-grid ABI changed");
static_assert(sizeof(idAnimator_Turret) == 312,
    "Recovered turret animator ABI changed");
#endif
