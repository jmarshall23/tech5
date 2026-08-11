#pragma once

#include "../entities/entityptr.h"
#include "../../../shared/idlib/containers/bitflag.h"
#include "../../../shared/idlib/math/vector.h"

class idEntity;

class idBotGoalServices {
public:
    virtual ~idBotGoalServices() = default;
    virtual int GetEntitySpawnId(const idEntity* entity) const = 0;
};

void Tungsten_SetBotGoalServices(idBotGoalServices* services);

class idBotGoal {
public:
    struct goalCombatSettings_t {
        float combatMaxRange;
    };

    idBotGoal();

    bool SupportsGoalType(int goal) const;
    bool Bot_SetGoalEnemy(const idEntity* newEnemy);
    void GoalManager_InitEntityGoal(int goalFlags,
        const idEntity* newGoalEntity, float newGoalRadius,
        float combatMaxRange, bool clearEnemy);
    void GoalManager_InitPosGoal(int goalFlags, const idVec3& newGoalPos,
        float newGoalRadius, float combatMaxRange, bool clearEnemy);
    void Bot_ResetGoal();

    bool goalEnemyLocked = false;
    goalCombatSettings_t goalCombatSettings = { 0.0f };
    int goalEnemyTargetRecordIndex = -1;
    idBitFlag32 goalType;
    idEntityPtr<idEntity> goalEnemy;
    idEntityPtr<idEntity> goalEntity;
    float goalRadius = 0.0f;
    idVec3 goalPosition;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idBotGoal) == 40,
    "Recovered bot goal ABI changed");
#endif
