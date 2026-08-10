#pragma once

#include "aievent.h"
#include "../../../../shared/idlib/containers/array.h"

class idAIEventWedge : public idAIEvent {
public:
    enum wedgePlane_t : int {
        WEDGEPLANE_TOP = 0,
        WEDGEPLANE_BOTTOM = 1,
        WEDGEPLANE_LEFT = 2,
        WEDGEPLANE_RIGHT = 3,
        WEDGEPLANE_MAX = 4
    };

    idAIEventWedge();
    ~idAIEventWedge() override = default;

    aiEventUpdateResult_t InternalUpdateAttached(int currentTime) override;
    bool InternalIsTouching(
        const idEntity* entity, int currentTime) override;
    void InternalDrawDebug(int level, int currentTime, int duration) override;
    void Cache(int currentTime) const;

    idVec3 dir;
    float radius;
    mutable int lastRefresh;
    mutable idMat3 axis;
    mutable idArray<idPlane, 4> planes;
};

bool Tungsten_GetAIEventEntityBounds(
    const idEntity* entity, idBounds& bounds);
void Tungsten_DebugAIEventWedgeLine(
    const idVec3& start, const idVec3& end, int duration);
void Tungsten_DebugAIEventWedgeArrow(
    const idVec3& start, const idVec3& end, int kind);

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAIEventWedge) == 172,
    "Recovered wedge AI-event ABI changed");
#endif
