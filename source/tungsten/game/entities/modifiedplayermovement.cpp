#include "game/entities/modifiedplayermovement.h"

namespace {
idModifiedPlayerMovementServices defaultModifiedMovementServices;
idModifiedPlayerMovementServices* modifiedMovementServices =
    &defaultModifiedMovementServices;
} // namespace

void idModifiedPlayerMovementServices::BaseThink(
        idModifiedPlayerMovement& modifier) {
    modifier.idAnimatedSimple::Think();
}

void idModifiedPlayerMovementServices::BaseHide(
        idModifiedPlayerMovement& modifier, const bool stopEffects) {
    modifier.idAnimatedSimple::Hide(stopEffects);
}

idPlayer* idModifiedPlayerMovementServices::ResolvePlayer(int) const {
    return nullptr;
}

int idModifiedPlayerMovementServices::GetPrimaryPlayerSpawnId() const {
    return 0x1FFF;
}

void idModifiedPlayerMovementServices::GetModifierAxis(
        const idModifiedPlayerMovement&, idMat3& outAxis) const {
    outAxis = idMat3(1.0f);
}

void idModifiedPlayerMovementServices::PreparePlayerMovement(idPlayer&) {}
void idModifiedPlayerMovementServices::ApplyPlayerMovement(idPlayer&,
        const idVec3&, float, float) {}
void idModifiedPlayerMovementServices::ResetPlayerMovement(idPlayer&) {}
void idModifiedPlayerMovementServices::QueueRemove(
        idModifiedPlayerMovement&) {}

void Tungsten_SetModifiedPlayerMovementServices(
        idModifiedPlayerMovementServices* const services) {
    modifiedMovementServices = services == nullptr
        ? &defaultModifiedMovementServices : services;
}

idModifiedPlayerMovementServices&
        Tungsten_ModifiedPlayerMovementServices() {
    return *modifiedMovementServices;
}

// Retail: 0x82C7C518 ??0idModifiedPlayerMovement@@QAA@XZ
idModifiedPlayerMovement::idModifiedPlayerMovement()
    : idAnimatedSimple(), strengthModifier(1.0f), maxSpeedDiff(1.0f),
      baseAngle(90.0f), useFixedDirection(false), playerEntity() {
}

idPlayer* idModifiedPlayerMovement::ResolvePlayer() const {
    return Tungsten_ModifiedPlayerMovementServices().ResolvePlayer(
        playerEntity.GetSpawnId());
}

void idModifiedPlayerMovement::ResetPlayer() {
    idPlayer* const player = ResolvePlayer();
    if (player != nullptr) {
        Tungsten_ModifiedPlayerMovementServices().ResetPlayerMovement(
            *player);
    }
    playerEntity.Invalidate();
}

// Retail: 0x82C7C5E0 ?Think@idModifiedPlayerMovement@@UAAXXZ
void idModifiedPlayerMovement::Think() {
    idModifiedPlayerMovementServices& services =
        Tungsten_ModifiedPlayerMovementServices();
    services.BaseThink(*this);

    idPlayer* const player = ResolvePlayer();
    if (player == nullptr) return;

    idMat3 modifierAxis(1.0f);
    services.GetModifierAxis(*this, modifierAxis);
    services.PreparePlayerMovement(*player);
    const idVec3 acceleration(
        -modifierAxis[2].x * strengthModifier,
        -modifierAxis[2].y * strengthModifier,
        0.0f);
    services.ApplyPlayerMovement(*player, acceleration,
        maxSpeedDiff, baseAngle);
}

// Retail: 0x82C7C780 ?Hide@idModifiedPlayerMovement@@UAAXXZ
void idModifiedPlayerMovement::Hide() {
    Tungsten_ModifiedPlayerMovementServices().BaseHide(*this, false);
    ResetPlayer();
}

// Retail: 0x82C7C878 ?Hide@idModifiedPlayerMovement@@UAAX_N@Z
void idModifiedPlayerMovement::Hide(const bool stopEffects) {
    Tungsten_ModifiedPlayerMovementServices().BaseHide(
        *this, stopEffects);
    ResetPlayer();
}

// Retail: 0x82C7C970 ?OnActivate@idModifiedPlayerMovement@@MAAXPAVidEntity@@@Z
void idModifiedPlayerMovement::OnActivate(idEntity*) {
    idModifiedPlayerMovementServices& services =
        Tungsten_ModifiedPlayerMovementServices();
    if (ResolvePlayer() != nullptr) {
        ResetPlayer();
        return;
    }

    playerEntity.SetSpawnId(services.GetPrimaryPlayerSpawnId());
    idPlayer* const player = ResolvePlayer();
    if (player == nullptr || !useFixedDirection) return;

    idMat3 modifierAxis(1.0f);
    services.GetModifierAxis(*this, modifierAxis);
    const idVec3 acceleration = modifierAxis[0] * strengthModifier;
    services.ApplyPlayerMovement(*player, acceleration,
        maxSpeedDiff, baseAngle);
}

// Retail: 0x82C7CB48 ?Event_Remove@idModifiedPlayerMovement@@AAA?AVeventVoid@@XZ
void idModifiedPlayerMovement::Event_Remove() {
    ResetPlayer();
    Tungsten_ModifiedPlayerMovementServices().QueueRemove(*this);
}
