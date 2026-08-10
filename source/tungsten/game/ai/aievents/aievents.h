#pragma once

#include "aieventtrace.h"
#include "aieventwedge.h"

class idAIEvent_Vehicle : public idAIEventWedge {
public:
    idAIEvent_Vehicle();
    ~idAIEvent_Vehicle() override = default;

    aiEventUpdateResult_t InternalUpdateAttached(int currentTime) override;
};

class idAIEvent_PlayerAim : public idAIEventTrace {
public:
    idAIEvent_PlayerAim();
    ~idAIEvent_PlayerAim() override = default;

    float GetDistance() const override;
    aiEventUpdateResult_t InternalUpdateAttached(int currentTime) override;
};

float Tungsten_GetAIEventPlayerAimDistance();
bool Tungsten_GetAIEventPlayerWeaponRange(
    int playerSpawnId, float& weaponRange);
bool Tungsten_GetAIEventPlayerView(int playerSpawnId,
    idVec3& viewOrigin, idVec3& viewForward);
bool Tungsten_GetAIEventVehicleState(int vehicleSpawnId,
    int& effectiveDriverSpawnId, idVec3& linearVelocity);
void Tungsten_DebugAIEventVehicleSpeed(float speed, float radius);

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAIEvent_Vehicle) == 172,
    "Recovered vehicle AI-event ABI changed");
static_assert(sizeof(idAIEvent_PlayerAim) == 208,
    "Recovered player-aim AI-event ABI changed");
#endif
