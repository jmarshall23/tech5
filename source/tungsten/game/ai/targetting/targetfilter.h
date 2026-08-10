#pragma once

#include "../../entities/entityptr.h"
#include "targetinfo.h"

class idBotTargetRecord;
class idEntity;

enum aiAwareness_t : int {
    AIAWARE_UNAWARE = 0,
    AIAWARE_LOST = 1,
    AIAWARE_SUSPECTED = 2,
    AIAWARE_CONFIRMED = 3,
    AIAWARE_MAX = 4
};

class idBotTargetFilter {
public:
    virtual ~idBotTargetFilter() = default;
    virtual const char* GetDebugName();
    virtual void PreCheckTargets(int playerIndex);
    virtual void CheckTarget(int playerIndex, idBotTargetRecord* record);
    virtual void SortTargets();
    virtual void Reset();

    int bestTargetIndex;
    idEntityPtr<idEntity> bestTarget;
};

class idTargetFilter {
public:
    virtual ~idTargetFilter() = default;
    virtual bool InternalFilter(
        const idEntity* owner, const idTargetInfo* target) const = 0;

    bool Filter(const idEntity* owner, const idTargetInfo& target) const;

    aiAwareness_t minAwareness;
};

class idAvoidTargetFilter : public idTargetFilter {
public:
    explicit idAvoidTargetFilter(aiAwareness_t minimumAwareness);
    ~idAvoidTargetFilter() override = default;
    bool InternalFilter(
        const idEntity* owner, const idTargetInfo* target) const override;
};

bool Tungsten_IsDeadAIEntityState(const idAIEntityState* entityState);
bool Tungsten_IsDyingAIEntityState(const idAIEntityState* entityState);
bool Tungsten_IsActorAIEntityState(const idAIEntityState* entityState);
int Tungsten_GetAIEntityType(const idAIEntityState* entityState);
int Tungsten_GetDyingAIAlertAgeMilliseconds(
    const idAIEntityState* entityState);
int Tungsten_GetAIAwareness(const idAIEntityState* entityState);
const idEntity* Tungsten_GetAIEntity(const idAIEntityState* entityState);
bool Tungsten_IsSpectatingPlayerEntity(const idEntity* entity);
bool Tungsten_IsDeadTurretEntity(const idEntity* entity);
bool Tungsten_IsDeadVehicleMountedTurretEntity(const idEntity* entity);
bool Tungsten_IsHiddenFakeEnemyEntity(const idEntity* entity);
const idEntity* Tungsten_GetCaptureTheFlagTurretOwner(
    const idEntity* owner);
const idEntity* Tungsten_GetVehicleDriver(const idEntity* entity);

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idTargetFilter) == 8,
    "Recovered target-filter ABI changed");
#endif
