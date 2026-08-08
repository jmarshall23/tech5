#include "idlib/geometry/geometry.h"

#include <algorithm>
#include <cmath>
#include <limits>

namespace {

constexpr float kSmallestNormal = std::numeric_limits<float>::min();
constexpr float kParallelEpsilonSqr = 0.0001f;

float ClampUnit(const float value) {
    return std::max(0.0f, std::min(1.0f, value));
}

float Cross2D(const idVec2& left, const idVec2& right) {
    return left.x * right.y - left.y * right.x;
}

idVec2 Subtract2D(const idVec2& left, const idVec2& right) {
    return idVec2(left.x - right.x, left.y - right.y);
}

idVec3 NormalizeSafely(const idVec3& vector) {
    const float lengthSqr = vector.LengthSqr();
    if (lengthSqr < kSmallestNormal) {
        return idVec3(0.0f, 0.0f, 0.0f);
    }
    return vector * (1.0f / std::sqrt(lengthSqr));
}

} // namespace

float idGeometry::PositionOnLineSegment(
    const idVec3& point,
    const idVec3& start,
    const idVec3& end
) {
    const idVec3 segment = end - start;
    const float lengthSqr = segment.LengthSqr();
    if (lengthSqr < kSmallestNormal) {
        return 0.0f;
    }
    return (point - start).Dot(segment) / lengthSqr;
}

bool idGeometry::ClosestPointOnLineSegment(
    const idVec3& point,
    const idVec3& start,
    const idVec3& end,
    idVec3& closest
) {
    const idVec3 segment = end - start;
    const float lengthSqr = segment.LengthSqr();
    if (lengthSqr < kSmallestNormal) {
        closest = start;
        return false;
    }

    const float position = (point - start).Dot(segment) / lengthSqr;
    if (position < 0.0f) {
        closest = start;
        return false;
    }
    if (position > 1.0f) {
        closest = end;
        return false;
    }

    closest = start + segment * position;
    return true;
}

void idGeometry::ClosestPointOnLine(
    const idVec3& point,
    const idVec3& start,
    const idVec3& dir,
    idVec3& closest
) {
    closest = start + dir * (point - start).Dot(dir);
}

idVec3 idGeometry::TriangleNormal(
    const idVec3& a,
    const idVec3& b,
    const idVec3& c
) {
    // The recovered winding is intentionally (c-a) x (b-a), opposite the
    // common formulation. Renderer-facing callers depend on that sign.
    return NormalizeSafely((c - a).Cross(b - a));
}

bool idGeometry::IntersectRayWithLineSegment2D(
    const idVec2& rayStart,
    const idVec2& rayDir,
    const idVec2& segStart,
    const idVec2& segEnd,
    float& dist
) {
    const idVec2 segment = Subtract2D(segEnd, segStart);
    const idVec2 offset = Subtract2D(segStart, rayStart);
    const float denominator = Cross2D(rayDir, segment);

    if (denominator * denominator > kParallelEpsilonSqr) {
        const float inverseDenominator = 1.0f / denominator;
        const float segmentPosition = -Cross2D(rayDir, offset)
            * inverseDenominator;
        if (segmentPosition < 0.0f || segmentPosition > 1.0f) {
            return false;
        }

        const float rayPosition = Cross2D(offset, segment)
            * inverseDenominator;
        if (rayPosition < 0.0f) {
            return false;
        }
        dist = rayPosition;
        return true;
    }

    if (Cross2D(rayDir, offset) * Cross2D(rayDir, offset)
        > kParallelEpsilonSqr) {
        return false;
    }

    // The PPC output is difficult to read in this collinear branch. This is
    // the equivalent geometric result: the nearest forward overlap measured
    // in ray parameter units. Keep it isolated for later binary trace checks.
    const float rayLengthSqr = rayDir.x * rayDir.x + rayDir.y * rayDir.y;
    if (rayLengthSqr < kSmallestNormal) {
        return false;
    }
    const idVec2 endOffset = Subtract2D(segEnd, rayStart);
    const float startPosition = (offset.x * rayDir.x + offset.y * rayDir.y)
        / rayLengthSqr;
    const float endPosition = (endOffset.x * rayDir.x + endOffset.y * rayDir.y)
        / rayLengthSqr;
    const float nearPosition = std::min(startPosition, endPosition);
    const float farPosition = std::max(startPosition, endPosition);
    if (farPosition < 0.0f) {
        return false;
    }
    dist = std::max(0.0f, nearPosition);
    return true;
}

float idGeometry::SquarePointLineSegmentDistance(
    const idVec3& point,
    const idVec3& start,
    const idVec3& end
) {
    const idVec3 segment = end - start;
    const float lengthSqr = segment.LengthSqr();
    if (lengthSqr < 0.01f) {
        return (point - start).LengthSqr();
    }

    const float position = ClampUnit((point - start).Dot(segment) / lengthSqr);
    return (point - (start + segment * position)).LengthSqr();
}

void idGeometry::SegmentSegmentClosestPoints(
    const idVec3& start1,
    const idVec3& end1,
    const idVec3& start2,
    const idVec3& end2,
    idVec3& out1,
    idVec3& out2,
    float& t1,
    float& t2,
    const bool clampTValues
) {
    const idVec3 direction1 = end1 - start1;
    const idVec3 direction2 = end2 - start2;
    const idVec3 offset = start1 - start2;
    const float length1Sqr = direction1.LengthSqr();
    const float length2Sqr = direction2.LengthSqr();
    const float directionsDot = direction1.Dot(direction2);
    const float offsetDot1 = direction1.Dot(offset);
    const float offsetDot2 = direction2.Dot(offset);
    const float denominator = length1Sqr * length2Sqr
        - directionsDot * directionsDot;

    if (length1Sqr < kSmallestNormal
        || length2Sqr < kSmallestNormal
        || denominator < kSmallestNormal) {
        out1 = start1;
        out2 = start2;
        t1 = 1.0f;
        t2 = 1.0f;
        return;
    }

    t1 = (directionsDot * offsetDot2 - offsetDot1 * length2Sqr)
        / denominator;
    if (clampTValues) {
        t1 = ClampUnit(t1);
    }

    t2 = (t1 * directionsDot + offsetDot2) / length2Sqr;
    if (clampTValues) {
        t2 = ClampUnit(t2);
    }

    out1 = start1 + direction1 * t1;
    out2 = start2 + direction2 * t2;
}

idVec3 idGeometry::FindNearestPerpendicular(
    const idVec3& input,
    const idVec3& up,
    const idVec3& hint
) {
    idVec3 perpendicular = input.Cross(up);
    if (perpendicular.Dot(hint) < 0.0f) {
        perpendicular = -perpendicular;
    }
    return NormalizeSafely(perpendicular);
}

float idGeometry::AreaOfTriangle(
    const idVec3& a,
    const idVec3& b,
    const idVec3& c
) {
    return 0.5f * (b - a).Cross(c - a).Length();
}
