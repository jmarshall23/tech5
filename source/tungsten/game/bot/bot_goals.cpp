#include "bot_goals.h"

namespace {
idBotGoalServices* g_goalServices = nullptr;
constexpr int INVALID_ENTITY_SPAWN_ID = 0x1FFF;

int EntitySpawnId(const idEntity* const entity) {
    return entity != nullptr && g_goalServices != nullptr
        ? g_goalServices->GetEntitySpawnId(entity)
        : INVALID_ENTITY_SPAWN_ID;
}
} // namespace

void Tungsten_SetBotGoalServices(idBotGoalServices* const services) {
    g_goalServices = services;
}

// Retail symbol: ?SupportsGoalType@idBotGoal@@QBA_NH@Z
// EA: 0x82B41230, RVA: 0x00B41230
bool idBotGoal::SupportsGoalType(const int goal) const {
    return goalType.flags == 1U
        || (goalType.flags & static_cast<unsigned int>(goal)) != 0U;
}

// Retail symbol: ?Bot_SetGoalEnemy@idBotGoal@@QAA_NPBVidEntity@@@Z
// EA: 0x82B41258, RVA: 0x00B41258
bool idBotGoal::Bot_SetGoalEnemy(const idEntity* const newEnemy) {
    if (goalEnemyLocked) {
        return false;
    }
    goalEnemy.SetSpawnId(EntitySpawnId(newEnemy));
    return true;
}

// Retail symbol: ?GoalManager_InitEntityGoal@idBotGoal@@IAAXHPBVidEntity@@MM_N@Z
// EA: 0x82B412B0, RVA: 0x00B412B0
void idBotGoal::GoalManager_InitEntityGoal(const int goalFlags,
        const idEntity* const newGoalEntity, const float newGoalRadius,
        const float newCombatMaxRange, const bool clearEnemy) {
    goalType.flags = static_cast<unsigned int>(goalFlags);
    goalEntity.SetSpawnId(EntitySpawnId(newGoalEntity));
    goalRadius = newGoalRadius;
    goalPosition.Zero();
    goalCombatSettings.combatMaxRange = newCombatMaxRange;
    if (clearEnemy) {
        goalEnemy.Invalidate();
        goalEnemyLocked = false;
    }
}

// Retail symbol: ?GoalManager_InitPosGoal@idBotGoal@@IAAXHABVidVec3@@MM_N@Z
// EA: 0x82B41328, RVA: 0x00B41328
void idBotGoal::GoalManager_InitPosGoal(const int goalFlags,
        const idVec3& newGoalPos, const float newGoalRadius,
        const float newCombatMaxRange, const bool clearEnemy) {
    goalType.flags = static_cast<unsigned int>(goalFlags);
    goalEntity.Invalidate();
    goalRadius = newGoalRadius;
    goalPosition = newGoalPos;
    goalCombatSettings.combatMaxRange = newCombatMaxRange;
    if (clearEnemy) {
        goalEnemy.Invalidate();
        goalEnemyLocked = false;
    }
}

// Retail symbol: ?Bot_ResetGoal@idBotGoal@@QAAXXZ
// EA: 0x82B41370, RVA: 0x00B41370
void idBotGoal::Bot_ResetGoal() {
    goalEnemyLocked = false;
    goalCombatSettings.combatMaxRange = 2048.0f;
    goalType.flags = 0x80000000U;
    goalEnemy.Invalidate();
    goalEntity.Invalidate();
    goalRadius = 512.0f;
    goalPosition.Zero();
}

// Retail symbol: ??0idBotGoal@@QAA@XZ
// EA: 0x82B413C8, RVA: 0x00B413C8
idBotGoal::idBotGoal()
    : goalEnemyLocked(false), goalCombatSettings{ 2048.0f },
      goalEnemyTargetRecordIndex(-1), goalType(), goalEnemy(), goalEntity(),
      goalRadius(512.0f), goalPosition(0.0f, 0.0f, 0.0f) {
    goalType.flags = 0x80000000U;
}
