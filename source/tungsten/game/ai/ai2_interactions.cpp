#include "ai2_interactions.h"

#include <cmath>

namespace {

bool SphereContains(const idVec3& origin, const float radius,
        const idVec3& point) {
    return (point - origin).LengthSqr() < radius * radius;
}

bool SphereIntersectsSegment(const idVec3& origin, const float radius,
        const idVec3& start, const idVec3& end) {
    const idVec3 fromCenter = start - origin;
    const idVec3 direction = end - start;
    const float projection = -fromCenter.Dot(direction);
    if (projection <= 0.0f) {
        return fromCenter.LengthSqr() < radius * radius;
    }
    const float directionLengthSqr = direction.LengthSqr();
    if (projection >= directionLengthSqr) {
        return (end - origin).LengthSqr() < radius * radius;
    }
    const idVec3 closest = fromCenter
        + direction * (projection / directionLengthSqr);
    return closest.LengthSqr() < radius * radius;
}

} // namespace

// Retail symbol:
// ?GetCurrentPlayerInteractionTempInfoState@idAI2@@QBA?AW4playerInteractionState_t@@XZ
// EA: 0x82A37E38, RVA: 0x00A37E38
playerInteractionState_t
idAI2::GetCurrentPlayerInteractionTempInfoState() const {
    return Tungsten_GetAI2TempInteractionState(*this);
}

// Retail symbol:
// ?SetCurrentPlayerInteractionTempInfoState@idAI2@@QAAXW4playerInteractionState_t@@@Z
// EA: 0x82A37E48, RVA: 0x00A37E48
void idAI2::SetCurrentPlayerInteractionTempInfoState(
        const playerInteractionState_t newState) {
    Tungsten_SetAI2TempInteractionState(*this, newState);
}

// Retail symbol: ?GetBoundsExpansionForDir@@YAMABVidBounds@@ABVidVec3@@@Z
// EA: 0x82A37EA8, RVA: 0x00A37EA8
float GetBoundsExpansionForDir(const idBounds& bounds,
        const idVec3& direction) {
    const float minimumDot = bounds[0].Dot(direction);
    return minimumDot <= 0.0f
        ? std::fabs(bounds[1].Dot(direction))
        : std::fabs(minimumDot);
}

// Retail symbol: ?GetCurrentPlayerInteraction@idAI2@@QBAPBVaiPlayerInteraction_t@@XZ
// EA: 0x82A37F08, RVA: 0x00A37F08
const aiPlayerInteraction_t* idAI2::GetCurrentPlayerInteraction() const {
    const int index = Tungsten_GetAI2CurrentInteractionIndex(*this);
    return index >= 0 ? Tungsten_GetAI2Interaction(*this, index) : nullptr;
}

// Retail symbol: ?SetCurrentPlayerInteraction@idAI2@@QAAXPBVaiPlayerInteraction_t@@@Z
// EA: 0x82A37F30, RVA: 0x00A37F30
void idAI2::SetCurrentPlayerInteraction(
        const aiPlayerInteraction_t* const interaction) {
    Tungsten_SetAI2CurrentInteractionIndex(*this,
        interaction != nullptr
            ? Tungsten_GetAI2InteractionIndex(*this, *interaction) : -1);
}

// Retail symbol: ?CanIdleTrackFriendlyTarget@idAI2@@QBA_NPBVidEntity@@@Z
// EA: 0x82A37FA0, RVA: 0x00A37FA0
bool idAI2::CanIdleTrackFriendlyTarget(
        const idEntity* const friendlyTarget) const {
    if (friendlyTarget == nullptr) {
        return false;
    }
    idIdleTrackFriendlyRuntime runtime{};
    if (!Tungsten_GetIdleTrackFriendlyRuntime(
            *this, *friendlyTarget, runtime)
        || runtime.maximumDistance < 0.0f
        || (runtime.playerMustLeave && !runtime.playerHasLeft)
        || !runtime.hasWorldState || !runtime.targetVisible) {
        return false;
    }
    return (runtime.targetAimPoint - runtime.aiEyePoint).LengthSqr()
        <= runtime.maximumDistance * runtime.maximumDistance;
}

// Retail symbol: ?PlayerApproachingInteraction@idAI2@@QAA_NPAVidPlayer@@@Z
// EA: 0x82A380C0, RVA: 0x00A380C0
bool idAI2::PlayerApproachingInteraction(idPlayer* const player) {
    if (player == nullptr) {
        return false;
    }
    idPlayerApproachRuntime runtime{};
    if (!Tungsten_GetPlayerApproachRuntime(*this, *player, runtime)
        || runtime.playerInterfaceBlocked || runtime.playerStateBlocked
        || runtime.actionScriptBlocked
        || !runtime.hasInteractionDeclaration) {
        return false;
    }

    if (!SphereContains(runtime.aiOrigin, runtime.approachRadius,
            runtime.playerOrigin)) {
        if (!SphereContains(runtime.aiOrigin, runtime.departureRadius,
                runtime.playerOrigin)) {
            return false;
        }
        idVec3 direction = runtime.playerVelocity;
        if (direction.NormalizeFast() < 0.01f) {
            return false;
        }
        const float expandedRadius = runtime.approachRadius
            + GetBoundsExpansionForDir(runtime.playerBounds, direction);
        const idVec3 projectedPosition = runtime.playerOrigin
            + runtime.playerVelocity * runtime.lookAheadTime;
        if (!SphereIntersectsSegment(runtime.aiOrigin, expandedRadius,
                runtime.playerOrigin, projectedPosition)) {
            return false;
        }
    }

    int interactionIndex =
        Tungsten_GetAI2CurrentInteractionIndex(*this);
    if (interactionIndex >= 0) {
        const aiPlayerInteraction_t* const current =
            Tungsten_GetAI2Interaction(*this, interactionIndex);
        if (current != nullptr
            && Tungsten_AI2InteractionHasExpired(
                *this, *current, *player)) {
            Tungsten_AI2PlayerInteractionDone(*this, true);
            interactionIndex = -1;
        }
    }
    if (interactionIndex < 0) {
        SetCurrentPlayerInteraction(
            Tungsten_FindAI2PlayerInteraction(*this, *player, true));
        interactionIndex = Tungsten_GetAI2CurrentInteractionIndex(*this);
    }

    const aiPlayerInteraction_t* const interaction = interactionIndex >= 0
        ? Tungsten_GetAI2Interaction(*this, interactionIndex) : nullptr;
    if (interaction == nullptr) {
        return false;
    }
    if (Tungsten_AI2InteractionActivatesWhenVisible(*interaction)
        && runtime.activationVisibilityEnabled
        && (!runtime.hasPlayerWorldState || !runtime.playerVisible)) {
        return false;
    }
    Tungsten_SetAI2InteractionEntity(*this, *player);
    return true;
}
