
// ========================================================================
// ?SupportsGoalType@idBotGoal@@QBA_NH@Z
// EA  : 0x82B41230
// RVA : 0x00B41230
// PDB : w:\tech5\tungsten\game\bot\bot_goals.cpp
// ========================================================================

BOOL __fastcall idBotGoal::SupportsGoalType(idBotGoal *this, const int goal)
{
  int flags; // r11

  flags = this->goalType.flags;
  return flags == 1 || (flags & goal) != 0;
}


// ========================================================================
// ?Bot_SetGoalEnemy@idBotGoal@@QAA_NPBVidEntity@@@Z
// EA  : 0x82B41258
// RVA : 0x00B41258
// PDB : w:\tech5\tungsten\game\bot\bot_goals.cpp
// ========================================================================

int __fastcall idBotGoal::Bot_SetGoalEnemy(idBotGoal *this, const idEntity *newEnemy)
{
  if ( this->goalEnemyLocked )
    return 0;
  if ( newEnemy != nullptr )
    this->goalEnemy.spawnId.value = (gameLocal->spawnIds.ptr[newEnemy->entityNumber] << 13) | newEnemy->entityNumber;
  else
    this->goalEnemy.spawnId.value = 0x1FFF;
  return 1;
}


// ========================================================================
// ?GoalManager_InitEntityGoal@idBotGoal@@IAAXHPBVidEntity@@MM_N@Z
// EA  : 0x82B412B0
// RVA : 0x00B412B0
// PDB : w:\tech5\tungsten\game\bot\bot_goals.cpp
// ========================================================================

void __fastcall idBotGoal::GoalManager_InitEntityGoal(
        idBotGoal *this,
        int goalFlags,
        const idEntity *newGoalEntity,
        double newGoalRadius,
        double combatMaxRange,
        const bool clearEnemy,
        int a7,
        char a8)
{
  this->goalType.flags = goalFlags;
  if ( newGoalEntity != nullptr )
    this->goalEntity.spawnId.value = (gameLocal->spawnIds.ptr[newGoalEntity->entityNumber] << 13)
                                   | newGoalEntity->entityNumber;
  else
    this->goalEntity.spawnId.value = 0x1FFF;
  this->goalRadius = newGoalRadius;
  this->goalPosition.z = 0.0;
  this->goalPosition.y = 0.0;
  this->goalPosition.x = 0.0;
  this->goalCombatSettings.combatMaxRange = combatMaxRange;
  if ( a8 != 0 )
  {
    this->goalEnemy.spawnId.value = 0x1FFF;
    this->goalEnemyLocked = false;
  }
}


// ========================================================================
// ?GoalManager_InitPosGoal@idBotGoal@@IAAXHABVidVec3@@MM_N@Z
// EA  : 0x82B41328
// RVA : 0x00B41328
// PDB : w:\tech5\tungsten\game\bot\bot_goals.cpp
// ========================================================================

void __fastcall idBotGoal::GoalManager_InitPosGoal(
        idBotGoal *this,
        int goalFlags,
        const idVec3 *newGoalPos,
        double newGoalRadius,
        double combatMaxRange,
        const bool clearEnemy,
        int a7,
        char a8)
{
  this->goalType.flags = goalFlags;
  this->goalEntity.spawnId.value = 0x1FFF;
  this->goalRadius = newGoalRadius;
  this->goalPosition = *newGoalPos;
  this->goalCombatSettings.combatMaxRange = combatMaxRange;
  if ( a8 != 0 )
  {
    this->goalEnemy.spawnId.value = 0x1FFF;
    this->goalEnemyLocked = false;
  }
}


// ========================================================================
// ?Bot_ResetGoal@idBotGoal@@QAAXXZ
// EA  : 0x82B41370
// RVA : 0x00B41370
// PDB : w:\tech5\tungsten\game\bot\bot_goals.cpp
// ========================================================================

void __fastcall idBotGoal::Bot_ResetGoal(idBotGoal *this)
{
  this->goalEnemyLocked = false;
  this->goalCombatSettings.combatMaxRange = 2048.0;
  this->goalType.flags = 0x80000000;
  this->goalEnemy.spawnId.value = 0x1FFF;
  this->goalEntity.spawnId.value = 0x1FFF;
  this->goalRadius = 512.0;
  this->goalPosition = vec3_origin;
}


// ========================================================================
// ??0idBotGoal@@QAA@XZ
// EA  : 0x82B413C8
// RVA : 0x00B413C8
// PDB : w:\tech5\tungsten\game\bot\bot_goals.cpp
// ========================================================================

idBotGoal *__fastcall idBotGoal::idBotGoal(idBotGoal *this)
{
  this->goalType.flags = 0;
  this->goalEnemy.spawnId.value = 0x1FFF;
  this->goalEntity.spawnId.value = 0x1FFF;
  this->goalEnemyLocked = false;
  this->goalCombatSettings.combatMaxRange = 2048.0;
  this->goalType.flags = 0x80000000;
  this->goalEnemy.spawnId.value = 0x1FFF;
  this->goalEntity.spawnId.value = 0x1FFF;
  this->goalRadius = 512.0;
  this->goalPosition = vec3_origin;
  return this;
}

