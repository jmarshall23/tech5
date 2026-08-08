
// ========================================================================
// ??0idBotBehaviorRoam@@QAA@XZ
// EA  : 0x82B38648
// RVA : 0x00B38648
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_roam.cpp
// ========================================================================

idBotBehaviorRoam *__fastcall idBotBehaviorRoam::idBotBehaviorRoam(idBotBehaviorRoam *this)
{
  idBehaviorAction::idBehaviorAction(this);
  this->moveStuck = false;
  this->__vftable = (idBotBehaviorRoam_vtbl *)&idBotBehaviorRoam::`vftable';
  idCurve_BSpline<idAngles>::SetOrder((idAnimator_DragJoints *)this, web: (idAnimator_AnimWeb *)0x80);
  return this;
}


// ========================================================================
// __unwind$488240
// EA  : 0x82B386A8
// RVA : 0x00B386A8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_roam.cpp
// ========================================================================

void _unwind_488240()
{
  int v0; // r12

  idBehaviorAction::~idBehaviorAction(this: *(idBehaviorAction **)(v0 - 112 + 132));
}


// ========================================================================
// ?MoveGoal_Reached_CallBack@idBotBehaviorRoam@@UAAXPAVidBot@@H@Z
// EA  : 0x82B386D0
// RVA : 0x00B386D0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_roam.cpp
// ========================================================================

void __fastcall idBotBehaviorRoam::MoveGoal_Reached_CallBack(idBotBehaviorRoam *this, idBot *bot, const int curTime)
{
  idBotGoal::Bot_ResetGoal(this: &bot->goalTask);
}


// ========================================================================
// ?GetPriority@idBotBehaviorRoam@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA  : 0x82B38740
// RVA : 0x00B38740
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_roam.cpp
// ========================================================================

behaviorPriority_t __fastcall idBotBehaviorRoam::GetPriority(idBotBehaviorRoam *this, idBot *bot, const int curTime)
{
  behaviorPriority_t result; // r3

  if ( idBehaviorState::CheckStateFlag(this, flag: 1) && this->moveStuck )
  {
    idBotGoal::Bot_ResetGoal(this: &bot->goalTask);
    return BEHAVIOR_PRIORITY_NULL;
  }
  if ( bot->goalTask.goalType.flags != 128 )
    return BEHAVIOR_PRIORITY_NULL;
  result = BEHAVIOR_PRIORITY_NORMAL;
  if ( ((LODWORD(bot->goalTask.goalPosition.z)
       | LODWORD(bot->goalTask.goalPosition.y)
       | LODWORD(bot->goalTask.goalPosition.x))
      & 0x7FFFFFFF) == 0 )
    return BEHAVIOR_PRIORITY_NULL;
  return result;
}


// ========================================================================
// ?Enter@idBotBehaviorRoam@@UAAXPAVidBot@@H@Z
// EA  : 0x82B387E0
// RVA : 0x00B387E0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_roam.cpp
// ========================================================================

void __fastcall idBotBehaviorRoam::Enter(idBotBehaviorRoam *this, idBot *bot, const int curTime)
{
  idBotMoveState *moveState; // r3
  idBotMoveCommand v6; // [sp+50h] [-90h] BYREF

  idBotMoveCommand::idBotMoveCommand(this: &v6, userName: "MoveToRoamGoal", callBackState: this);
  idBotMoveCommand::SetMoveGoalPosition(this: &v6, goalPos: &bot->goalTask.goalPosition);
  moveState = bot->moveState;
  v6.moveStance = MOVE_STANCE_RUN;
  v6.moveTolerance = 32.0;
  idBotMoveState::StartMoveToGoal(this: moveState, moveCmd: &v6);
  bot->moveState->idleStance = MOVE_STANCE_RUN;
  this->moveStuck = false;
  idBotMoveCommand::~idBotMoveCommand(this: &v6);
}


// ========================================================================
// __unwind$488375
// EA  : 0x82B38858
// RVA : 0x00B38858
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_roam.cpp
// ========================================================================

void _unwind_488375()
{
  int v0; // r12

  idBotMoveCommand::~idBotMoveCommand(this: (idBotMoveCommand *)(v0 - 224 + 80));
}

