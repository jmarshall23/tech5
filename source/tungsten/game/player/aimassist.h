#pragma once

#include "aimassistdata.h"
#include "../clientgame/presentable/presentableptr.h"
#include "../../../engine/gamelib/class.h"
#include "../../../shared/idlib/math/vector.h"

#include <cstdint>

class idPresentableAnimatedEntity;
class idPresentablePlayer;

#ifndef ID_CLIP_QUERY_DEFINED
#define ID_CLIP_QUERY_DEFINED
struct idClipQuery {
    std::uint64_t index;
};
#endif

class idAimAssist : public idClass {
public:
    idAimAssist();
    idTypeInfo* GetType() override;
    ~idAimAssist() override;

    void Init(idPresentablePlayer* player);

    idPresentablePtr<idPresentablePlayer> player;
    idAngles angleCorrection;
    float frictionScalar;
    float desiredFrictionScalar;
    float weaponTraceDistance;
    bool lastZoomSnap;
    bool allowZoomSnap;
    bool zoomSnapThisFrame;
    idVec3 zoomSnapAimPoint;
    idPresentablePtr<idPresentableAnimatedEntity> thisFrameEntity;
    idPresentablePtr<idPresentableAnimatedEntity> lastFrameEntity;
    idVec3 thisFrameHitLoc;
    idVec3 lastFrameHitLoc;
    std::int16_t savedAngle[3];
    std::int16_t currentAngle[3];
    std::int16_t savedYaw;
    std::int16_t savedPitch;
    std::int16_t currentYaw;
    std::int16_t currentPitch;
    idClipQuery deferredAimPoint;
    idClipQuery deferredHeadPoint;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAimAssist) == 120,
    "Recovered runtime aim-assist ABI changed");
#endif
