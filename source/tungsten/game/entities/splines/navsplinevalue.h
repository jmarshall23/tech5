#pragma once

#include "../../../../shared/idlib/containers/list.h"
#include "../../../../shared/idlib/math/vector.h"

class idNavSpline;

// Position along the centre line of a navigation spline, with a signed
// lateral displacement.  The three-word layout is used pervasively by the
// vehicle-AI save state and must remain ABI-stable.
class idNavSplinePosition {
public:
    idVec3 GetSplineWorldPos() const;
    void GetWorldPositionAndForward(idVec3& pos, idVec3& forward) const;
    idVec3 GetForward() const;
    idVec3 GetRight() const;
    void GetVectors(idVec3& forward, idVec3& right) const;
    idVec3 GetWorldPos() const;
    void Validate(idNavSpline* nextSpline, idNavSpline* prevSpline);
    void Validate(const idVec3& velocity);
    void MoveDelta(float delta, const idVec3& velocity);
    bool IsOnDeadendPath() const;

    idNavSpline* navSpline;
    float distance;
    float rightDistance;
};

struct navSplinePath_t {
    struct path_t {
        idNavSpline* navSpline;
        float dir;
    };

    navSplinePath_t();
    bool IsSingleSpline();

    float startDistance;
    float endDistance;
    float distance;
    float rightDelta;
    idList<path_t, 5> path;
};

static_assert(sizeof(idNavSplinePosition) == 12,
    "Recovered navigation-spline position ABI changed");

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(navSplinePath_t::path_t) == 8,
    "Recovered navigation-spline path entry ABI changed");
static_assert(sizeof(navSplinePath_t) == 32,
    "Recovered navigation-spline path ABI changed");
#endif
