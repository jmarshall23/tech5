
// ========================================================================
// ??4idBotMoveCommand@@QAAAAV0@ABV0@@Z
// EA  : 0x82B427C8
// RVA : 0x00B427C8
// PDB : w:\tech5\tungsten\game\bot\bot_movecmd.h
// ========================================================================

idBotMoveCommand *__fastcall idBotMoveCommand::operator=(idBotMoveCommand *this, const idBotMoveCommand *src)
{
  this->moveUserName = src->moveUserName;
  this->moveStopAtPoint = src->moveStopAtPoint;
  this->moveAreaNum = src->moveAreaNum;
  this->moveFlags.flags = src->moveFlags.flags;
  this->moveStance = src->moveStance;
  this->moveGoalType = src->moveGoalType;
  this->moveEntityType = src->moveEntityType;
  this->moveTolerance = src->moveTolerance;
  this->moveGoalPosition = src->moveGoalPosition;
  this->moveDestination.z = 0.0;
  this->moveDestination.y = 0.0;
  this->moveDestination.x = 0.0;
  this->moveGoalEntity.spawnId.value = src->moveGoalEntity.spawnId.value;
  this->moveCallBackState = src->moveCallBackState;
  this->moveSubGoal.active = src->moveSubGoal.active;
  this->moveSubGoal.point = src->moveSubGoal.point;
  this->moveSubGoal.radius = src->moveSubGoal.radius;
  return this;
}

