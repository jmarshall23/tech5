#include "aieventwedge.h"

#include <cmath>

namespace {

idMat3 DirectionToAxis(const idVec3& direction) {
    idMat3 result;
    result[0] = direction;
    const float horizontalSqr = direction.x * direction.x
        + direction.y * direction.y;
    if (horizontalSqr == 0.0f) {
        result[1].Set(1.0f, 0.0f, 0.0f);
        result[2].Set(0.0f, direction.z > 0.0f ? 1.0f : -1.0f, 0.0f);
        return result;
    }

    const float inverseHorizontal = 1.0f / std::sqrt(horizontalSqr);
    result[1].Set(-direction.y * inverseHorizontal,
        direction.x * inverseHorizontal, 0.0f);
    result[2].Set(-direction.x * direction.z * inverseHorizontal,
        -direction.y * direction.z * inverseHorizontal,
        horizontalSqr * inverseHorizontal);
    result[2].NormalizeFast();
    return result;
}

idVec3 RotateAroundAxis(const idVec3& vector,
        const idVec3& rotationAxis, const float degrees) {
    constexpr float DEG_TO_RAD = 0.01745329251994329577f;
    const float radians = degrees * DEG_TO_RAD;
    const float cosine = std::cos(radians);
    const float sine = std::sin(radians);
    return vector * cosine
        + rotationAxis.Cross(vector) * sine
        + rotationAxis * (rotationAxis.Dot(vector) * (1.0f - cosine));
}

void SetPlaneThroughPoint(idPlane& plane,
        idVec3 normal, const idVec3& point) {
    normal.NormalizeFast();
    plane.a = normal.x;
    plane.b = normal.y;
    plane.c = normal.z;
    plane.d = -normal.Dot(point);
}

float BoundsProjectionWidth(
        const idBounds& bounds, const idVec3& direction) {
    const idVec3 extents = (bounds[1] - bounds[0]) * 0.5f;
    return 2.0f * (std::fabs(direction.x) * extents.x
        + std::fabs(direction.y) * extents.y
        + std::fabs(direction.z) * extents.z);
}

idVec3 WedgeEdgeDirection(const idVec3& up,
        const idPlane& sidePlane, const idVec3& forward) {
    idVec3 edge = up.Cross(sidePlane.Normal());
    edge.NormalizeFast();
    if (edge.Dot(forward) < 0.0f) {
        edge = -edge;
    }
    return edge;
}

} // namespace

idAIEventWedge::idAIEventWedge()
    : dir(0.0f, 0.0f, 0.0f)
    , radius(0.0f)
    , lastRefresh(-1)
    , axis(0.0f)
    , planes{} {
}

idAIEvent::aiEventUpdateResult_t
idAIEventWedge::InternalUpdateAttached(const int currentTime) {
    lastRefresh = -1;
    return idAIEvent::InternalUpdateAttached(currentTime);
}

void idAIEventWedge::Cache(const int currentTime) const {
    if (lastRefresh >= currentTime || dir.LengthSqr() < 1.0f) {
        return;
    }

    axis = DirectionToAxis(dir);
    const idVec3& up = axis[2];
    const float halfArc = eventDecl != nullptr
        ? eventDecl->arcWidthDegrees * 0.5f : 0.0f;
    const idVec3 leftEdge = RotateAroundAxis(dir, up, halfArc);
    const idVec3 rightEdge = RotateAroundAxis(dir, up, -halfArc);

    SetPlaneThroughPoint(planes[WEDGEPLANE_LEFT],
        leftEdge.Cross(up), origin);
    SetPlaneThroughPoint(planes[WEDGEPLANE_RIGHT],
        up.Cross(rightEdge), origin);

    const float heightMax = eventDecl != nullptr
        ? eventDecl->heightMax : 0.0f;
    const float heightMin = eventDecl != nullptr
        ? eventDecl->heightMin : 0.0f;
    SetPlaneThroughPoint(planes[WEDGEPLANE_TOP],
        -up, origin + up * heightMax);
    SetPlaneThroughPoint(planes[WEDGEPLANE_BOTTOM],
        up, origin - up * heightMin);
    lastRefresh = currentTime;
}

bool idAIEventWedge::InternalIsTouching(
        const idEntity* const entity, const int currentTime) {
    if (radius == 0.0f) {
        return false;
    }

    idBounds entityBounds;
    idVec3 entityOrigin;
    if (!Tungsten_GetAIEventEntityBounds(entity, entityBounds)
            || !Tungsten_GetAIEventEntityWorldOrigin(entity, entityOrigin)) {
        return false;
    }

    idVec3 direction = entityOrigin - origin;
    const float distance = direction.NormalizeFast();
    if (distance < 1.0f) {
        return false;
    }

    float nearestDistance = distance
        - BoundsProjectionWidth(entityBounds, direction);
    if (nearestDistance < 0.0f) {
        nearestDistance = 0.0f;
    } else if (nearestDistance > distance) {
        nearestDistance = distance;
    }
    if (nearestDistance > radius) {
        return false;
    }

    Cache(currentTime);
    for (int index = 0; index < WEDGEPLANE_MAX; ++index) {
        if (entityBounds.PlaneSide(planes[index], 0.1f) == 1) {
            return false;
        }
    }
    return true;
}

void idAIEventWedge::InternalDrawDebug(
        const int, const int currentTime, const int) {
    Cache(currentTime);
    if (dir.LengthSqr() < 1.0f) {
        return;
    }

    const idVec3& up = axis[2];
    const float heightMin = eventDecl != nullptr
        ? eventDecl->heightMin : 0.0f;
    const float heightMax = eventDecl != nullptr
        ? eventDecl->heightMax : 0.0f;
    const idVec3 bottomOrigin = origin - up * heightMin;
    const idVec3 topOrigin = origin + up * heightMax;
    const idVec3 leftDirection = WedgeEdgeDirection(
        up, planes[WEDGEPLANE_LEFT], dir);
    const idVec3 rightDirection = WedgeEdgeDirection(
        up, planes[WEDGEPLANE_RIGHT], dir);
    const idVec3 leftBottom = bottomOrigin + leftDirection * radius;
    const idVec3 leftTop = topOrigin + leftDirection * radius;
    const idVec3 rightBottom = bottomOrigin + rightDirection * radius;
    const idVec3 rightTop = topOrigin + rightDirection * radius;
    const int frameDuration = Tungsten_GetAIEventGameMillisecondsPerFrame();

    Tungsten_DebugAIEventWedgeLine(bottomOrigin, leftBottom, frameDuration);
    Tungsten_DebugAIEventWedgeLine(topOrigin, leftTop, frameDuration);
    Tungsten_DebugAIEventWedgeLine(bottomOrigin, rightBottom, frameDuration);
    Tungsten_DebugAIEventWedgeLine(topOrigin, rightTop, frameDuration);
    Tungsten_DebugAIEventWedgeLine(bottomOrigin, topOrigin, frameDuration);
    Tungsten_DebugAIEventWedgeLine(rightBottom, rightTop, frameDuration);
    Tungsten_DebugAIEventWedgeLine(leftBottom, leftTop, frameDuration);

    const idVec3 rightCenter = (rightBottom + rightTop) * 0.5f;
    const idVec3 leftCenter = (leftBottom + leftTop) * 0.5f;
    Tungsten_DebugAIEventWedgeArrow(rightCenter,
        rightCenter + planes[WEDGEPLANE_RIGHT].Normal() * 32.0f, 0);
    Tungsten_DebugAIEventWedgeArrow(leftCenter,
        leftCenter + planes[WEDGEPLANE_LEFT].Normal() * 32.0f, 1);
    Tungsten_DebugAIEventWedgeArrow(
        origin, origin + dir * radius, 2);
}
