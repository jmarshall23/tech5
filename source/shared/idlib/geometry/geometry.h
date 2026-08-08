#pragma once

#include "../math/vector.h"

class idGeometry {
public:
    static float PositionOnLineSegment(
        const idVec3& point,
        const idVec3& start,
        const idVec3& end
    );

    static bool ClosestPointOnLineSegment(
        const idVec3& point,
        const idVec3& start,
        const idVec3& end,
        idVec3& closest
    );

    static void ClosestPointOnLine(
        const idVec3& point,
        const idVec3& start,
        const idVec3& dir,
        idVec3& closest
    );

    static idVec3 TriangleNormal(
        const idVec3& a,
        const idVec3& b,
        const idVec3& c
    );

    static bool IntersectRayWithLineSegment2D(
        const idVec2& rayStart,
        const idVec2& rayDir,
        const idVec2& segStart,
        const idVec2& segEnd,
        float& dist
    );

    static float SquarePointLineSegmentDistance(
        const idVec3& point,
        const idVec3& start,
        const idVec3& end
    );

    static void SegmentSegmentClosestPoints(
        const idVec3& start1,
        const idVec3& end1,
        const idVec3& start2,
        const idVec3& end2,
        idVec3& out1,
        idVec3& out2,
        float& t1,
        float& t2,
        bool clampTValues
    );

    static idVec3 FindNearestPerpendicular(
        const idVec3& input,
        const idVec3& up,
        const idVec3& hint
    );

    static float AreaOfTriangle(
        const idVec3& a,
        const idVec3& b,
        const idVec3& c
    );
};
