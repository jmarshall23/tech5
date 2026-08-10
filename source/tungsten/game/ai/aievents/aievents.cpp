#include "aievents.h"

#include <algorithm>

idAIEvent_Vehicle::idAIEvent_Vehicle() = default;

idAIEvent_PlayerAim::idAIEvent_PlayerAim() = default;

float idAIEvent_PlayerAim::GetDistance() const {
    const float playerAimDistance = Tungsten_GetAIEventPlayerAimDistance();
    float weaponRange;
    if (!Tungsten_GetAIEventPlayerWeaponRange(
            originator.GetSpawnId(), weaponRange)) {
        return playerAimDistance;
    }
    return (std::min)(playerAimDistance, weaponRange);
}

idAIEvent::aiEventUpdateResult_t
idAIEvent_PlayerAim::InternalUpdateAttached(const int) {
    return Tungsten_GetAIEventPlayerView(
        originator.GetSpawnId(), origin, dir)
        ? AIUPDATE_OK : AIUPDATE_REMOVE;
}

idAIEvent::aiEventUpdateResult_t
idAIEvent_Vehicle::InternalUpdateAttached(const int currentTime) {
    int effectiveDriverSpawnId;
    idVec3 velocity;
    if (!Tungsten_GetAIEventVehicleState(originator.GetSpawnId(),
            effectiveDriverSpawnId, velocity)) {
        return AIUPDATE_REMOVE;
    }

    instigator.SetSpawnId(effectiveDriverSpawnId);
    dir = velocity;
    const float speed = dir.NormalizeFast();
    const float lookAheadTime = eventDecl != nullptr
        ? eventDecl->lookAheadTime : 0.0f;
    radius = (std::max)(0.0f,
        (std::min)(lookAheadTime * speed, 4096.0f));
    Tungsten_DebugAIEventVehicleSpeed(speed, radius);
    return idAIEventWedge::InternalUpdateAttached(currentTime);
}
