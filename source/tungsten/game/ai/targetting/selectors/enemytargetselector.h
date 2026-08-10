#pragma once

#include "../targetselector_core.h"

struct idEnemyTargetSelectorSettings {
    float rangeMax = 0.0f;
    float rangeWeight = 0.0f;
    float angleWeight = 0.0f;
    float relationWeight = 0.0f;
    float groupWeight = 0.0f;
    float currentWeight = 0.0f;
    float damagerWeight = 0.0f;
    float spottedWeight = 0.0f;
    float spottedMax = 0.0f;
    float playerWeight = 0.0f;
    float aiWeight = 0.0f;
    float fakeWeight = 0.0f;
    float vehicleWeight = 0.0f;
    float aggroWeight = 0.0f;
};

// Values gathered from entity RTTI, AI memory, encounter groups, senses, and
// editable targeting settings. The recovered selector owns all decisions and
// arithmetic performed with these values.
struct idEnemyTargetSelectorRuntime {
    bool ownerIsAI = false;
    bool ownerInCombat = false;
    bool targetEntityExists = false;
    bool targetEntityDead = false;
    bool targetStateDead = false;
    bool targetIsActor = false;
    bool targetIsPlayer = false;
    bool targetIsAI = false;
    bool targetIsVehicleOrRobot = false;
    bool targetIsCurrentEnemy = false;
    bool targetIsEncounterGroupEnemy = false;
    bool targetRecentlyDamagedOwner = false;
    bool ownerHasFakeEnemy = false;
    bool targetIsOwnerFakeEnemy = false;
    bool ownerFakeEnemyVisible = false;
    bool targetIsFakeEnemyEntity = false;
    bool targetIsMemoryOriginator = false;
    bool targetVisible = false;
    bool hasConfirmedStimulus = false;
    int millisecondsSinceConfirmedStimulus = 0;
    int currentAwareness = 0;
    float ownerFakeEnemyWeight = 0.0f;
    float scriptedAggro = 0.0f;
    idEnemyTargetSelectorSettings settings;
};

struct idEnemyTargetSelectorComponents {
    float range = 0.0f;
    float angle = 0.0f;
    float relationship = 0.0f;
    float group = 0.0f;
    float current = 0.0f;
    float damager = 0.0f;
    float spotted = 0.0f;
    float player = 0.0f;
    float ai = 0.0f;
    float fake = 0.0f;
    float vehicle = 0.0f;
    float aggro = 0.0f;
};

class idEnemyTargetSelector : public idTargetSelector {
public:
    ~idEnemyTargetSelector() override = default;
    float GetWeight(
        const idEntity* owner, const idTargetInfo* target) const override;
};

void Tungsten_GetEnemyTargetSelectorRuntime(const idEntity& owner,
    const idAIEntityState& entityState,
    idEnemyTargetSelectorRuntime& runtime);
bool Tungsten_DebugEnemyTargetSelectorEnabled();
void Tungsten_DebugEnemyTargetSelectorWeight(const idEntity& owner,
    const idTargetInfo& targetInfo,
    const idEnemyTargetSelectorRuntime& runtime,
    const idEnemyTargetSelectorComponents& components, float weight);
