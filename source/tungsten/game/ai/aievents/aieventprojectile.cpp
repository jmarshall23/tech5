#include "aieventprojectile.h"

#include <algorithm>

idAIEventProjectile::idAIEventProjectile() = default;

idAIEvent::aiEventUpdateResult_t
idAIEventProjectile::InternalUpdateAttached(const int) {
    if (!Tungsten_GetAIEventEntityOrigin(
            originator.GetSpawnId(), origin)) {
        return AIUPDATE_REMOVE;
    }

    if (!Tungsten_GetAIEventEntityLinearVelocity(
            originator.GetSpawnId(), dir)) {
        dir.Zero();
    }
    dir.NormalizeFast();
    return AIUPDATE_OK;
}

float idAIEventProjectile::GetDistance() const {
    idVec3 velocity;
    if (!Tungsten_GetAIEventEntityLinearVelocity(
            originator.GetSpawnId(), velocity)) {
        return 0.0f;
    }

    const float lookAheadTime = eventDecl != nullptr
        ? eventDecl->lookAheadTime : 0.0f;
    const float distance = lookAheadTime * velocity.Length();
    return (std::max)(0.0f, (std::min)(distance, 4096.0f));
}
