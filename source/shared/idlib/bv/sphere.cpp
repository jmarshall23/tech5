#include "sphere.h"

bool idSphere::LineIntersection(const idVec3& start, const idVec3& end) const {
    const idVec3 fromCenter = start - origin;
    const idVec3 direction = end - start;
    const float projection = -fromCenter.Dot(direction);
    if (projection <= 0.0f) return fromCenter.LengthSqr() < radius * radius;

    const float directionLengthSqr = direction.LengthSqr();
    if (projection >= directionLengthSqr) {
        const idVec3 endFromCenter = end - origin;
        return endFromCenter.LengthSqr() < radius * radius;
    }

    const idVec3 closest = fromCenter
        + direction * (projection / directionLengthSqr);
    return closest.LengthSqr() < radius * radius;
}
