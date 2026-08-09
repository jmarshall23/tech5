#include "gamelib/aas2/aas2callback_avoidlocation.h"

#include <cmath>

idAAS2Callback_AvoidLocation::idAAS2Callback_AvoidLocation()
    : avoidLocation(0.0f, 0.0f, 0.0f)
    , avoidDist(0.0f)
    , obstacles(nullptr)
    , numObstacles(0) {
}

idAAS2Callback_AvoidLocation::~idAAS2Callback_AvoidLocation() {
    obstacles = nullptr;
}

bool idAAS2Callback_AvoidLocation::PathValid(const idAAS2 *,
        const idVec3 *start, const idVec3 *end) {
    if (obstacles == nullptr || numObstacles <= 0
            || start == nullptr || end == nullptr) {
        return true;
    }
    for (int index = 0; index < numObstacles; ++index) {
        if (obstacles[index].expAbsBounds.LineIntersection(*start, *end)) {
            return false;
        }
    }
    return true;
}

int idAAS2Callback_AvoidLocation::AdditionalTravelTimeForPath(
        const idAAS2 *, const idVec3 *start, const idVec3 *end) {
    if (avoidDist <= 0.0f || start == nullptr || end == nullptr) {
        return 0;
    }

    const idVec3 segment = *end - *start;
    const float segmentLengthSqr = segment.LengthSqr();
    idVec3 closest = *end;
    if (segmentLengthSqr > 1.0e-30f) {
        const float inverseLength = 1.0f / std::sqrt(segmentLengthSqr);
        const idVec3 direction = segment * inverseLength;
        const idVec3 projected = *start
            + direction * ((avoidLocation - *start).Dot(direction));

        const bool outside =
            (projected.x > start->x + 0.1f && projected.x > end->x + 0.1f)
            || (projected.x < start->x - 0.1f && projected.x < end->x - 0.1f)
            || (projected.y > start->y + 0.1f && projected.y > end->y + 0.1f)
            || (projected.y < start->y - 0.1f && projected.y < end->y - 0.1f)
            || (projected.z > start->z + 0.1f && projected.z > end->z + 0.1f)
            || (projected.z < start->z - 0.1f && projected.z < end->z - 0.1f);
        if (!outside) {
            closest = projected;
        }
    }

    const float distance = (avoidLocation - closest).Length();
    return distance < avoidDist
        ? static_cast<int>((avoidDist - distance) * 10.0f)
        : 0;
}
