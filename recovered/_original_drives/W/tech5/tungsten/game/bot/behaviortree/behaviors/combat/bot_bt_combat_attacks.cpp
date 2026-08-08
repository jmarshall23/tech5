
// ========================================================================
// ??0idBotBehaviorCombat_RunAndAttackEnemy@@QAA@XZ
// EA  : 0x82B38880
// RVA : 0x00B38880
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

idBotBehaviorCombat_RunAndAttackEnemy *__fastcall idBotBehaviorCombat_RunAndAttackEnemy::idBotBehaviorCombat_RunAndAttackEnemy(
        idBotBehaviorCombat_RunAndAttackEnemy *this)
{
  idBehaviorAction::idBehaviorAction(this);
  this->isDodging = false;
  this->__vftable = (idBotBehaviorCombat_RunAndAttackEnemy_vtbl *)&idBotBehaviorCombat_RunAndAttackEnemy::`vftable';
  this->leftyStrafer = false;
  this->lastJumpTime = 0;
  this->lastDodgeTime = 0;
  return this;
}


// ========================================================================
// ?MoveSubGoal_Errored_CallBack@idBotBehaviorCombat_RunAndAttackEnemy@@UAAXPAVidBot@@HW4botMoveStatus_t@@@Z
// EA  : 0x82B388D0
// RVA : 0x00B388D0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

void __fastcall idBotBehaviorCombat_RunAndAttackEnemy::MoveSubGoal_Errored_CallBack(
        idBotBehaviorCombat_RunAndAttackEnemy *this,
        idBot *bot,
        int curTime)
{
  this->lastDodgeTime = curTime;
  this->isDodging = false;
}


// ========================================================================
// ??0idBotBehaviorCombat_CircleStafeEnemy@@QAA@XZ
// EA  : 0x82B388E0
// RVA : 0x00B388E0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

idBotBehaviorCombat_CircleStafeEnemy *__fastcall idBotBehaviorCombat_CircleStafeEnemy::idBotBehaviorCombat_CircleStafeEnemy(
        idBotBehaviorCombat_CircleStafeEnemy *this)
{
  idBehaviorAction::idBehaviorAction(this);
  this->leftyStrafer = false;
  this->__vftable = (idBotBehaviorCombat_CircleStafeEnemy_vtbl *)&idBotBehaviorCombat_CircleStafeEnemy::`vftable';
  this->behaviorFinishTime = 0;
  return this;
}


// ========================================================================
// ??0idBotBehaviorCombat_SideStrafeEnemy@@QAA@XZ
// EA  : 0x82B38928
// RVA : 0x00B38928
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

idBotBehaviorCombat_SideStrafeEnemy *__fastcall idBotBehaviorCombat_SideStrafeEnemy::idBotBehaviorCombat_SideStrafeEnemy(
        idBotBehaviorCombat_SideStrafeEnemy *this)
{
  idBehaviorAction::idBehaviorAction(this);
  this->jumped = false;
  this->__vftable = (idBotBehaviorCombat_SideStrafeEnemy_vtbl *)&idBotBehaviorCombat_SideStrafeEnemy::`vftable';
  this->leftyStrafer = false;
  this->shouldJump = false;
  this->behaviorFinishTime = 0;
  return this;
}


// ========================================================================
// ??0idBotBehaviorCombat_QuickSideToSideStrafeEnemy@@QAA@XZ
// EA  : 0x82B38978
// RVA : 0x00B38978
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

idBotBehaviorCombat_QuickSideToSideStrafeEnemy *__fastcall idBotBehaviorCombat_QuickSideToSideStrafeEnemy::idBotBehaviorCombat_QuickSideToSideStrafeEnemy(
        idBotBehaviorCombat_QuickSideToSideStrafeEnemy *this)
{
  idBehaviorAction::idBehaviorAction(this);
  this->leftyStrafer = false;
  this->__vftable = (idBotBehaviorCombat_QuickSideToSideStrafeEnemy_vtbl *)&idBotBehaviorCombat_QuickSideToSideStrafeEnemy::`vftable';
  this->behaviorTime = 0;
  this->strafeDirDuration = 0;
  return this;
}


// ========================================================================
// ??0idBotBehaviorCombat_StandGroundAttackEnemy@@QAA@XZ
// EA  : 0x82B389C8
// RVA : 0x00B389C8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

idBotBehaviorCombat_StandGroundAttackEnemy *__fastcall idBotBehaviorCombat_StandGroundAttackEnemy::idBotBehaviorCombat_StandGroundAttackEnemy(
        idBotBehaviorCombat_StandGroundAttackEnemy *this)
{
  idBehaviorAction::idBehaviorAction(this);
  this->backingAway = false;
  this->__vftable = (idBotBehaviorCombat_StandGroundAttackEnemy_vtbl *)&idBotBehaviorCombat_StandGroundAttackEnemy::`vftable';
  this->behaviorTime = 0;
  return this;
}


// ========================================================================
// ??0idBotBehaviorCombat_GrenadeAttackEnemy@@QAA@XZ
// EA  : 0x82B38A10
// RVA : 0x00B38A10
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

idBotBehaviorCombat_GrenadeAttackEnemy *__fastcall idBotBehaviorCombat_GrenadeAttackEnemy::idBotBehaviorCombat_GrenadeAttackEnemy(
        idBotBehaviorCombat_GrenadeAttackEnemy *this)
{
  idBehaviorAction::idBehaviorAction(this);
  this->__vftable = (idBotBehaviorCombat_GrenadeAttackEnemy_vtbl *)&idBotBehaviorCombat_GrenadeAttackEnemy::`vftable';
  return this;
}


// ========================================================================
// ?MoveSubGoal_Errored_CallBack@idBotBehaviorCombat_RandomJumpAttackEnemy@@UAAXPAVidBot@@HW4botMoveStatus_t@@@Z
// EA  : 0x82B38A50
// RVA : 0x00B38A50
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

void __fastcall idBotBehaviorCombat_RandomJumpAttackEnemy::MoveSubGoal_Errored_CallBack(
        idBotBehaviorCombat_RandomJumpAttackEnemy *this,
        idBot *bot,
        const int curTime,
        const botMoveStatus_t moveStatusCode)
{
  this->behaviorTime = 0;
}


// ========================================================================
// ?MoveSubGoal_Started_CallBack@idBotBehaviorCombat_RandomJumpAttackEnemy@@UAAXPAVidBot@@H@Z
// EA  : 0x82B38A60
// RVA : 0x00B38A60
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

void __fastcall idBotBehaviorCombat_RandomJumpAttackEnemy::MoveSubGoal_Started_CallBack(
        idBotBehaviorCombat_RandomJumpAttackEnemy *this,
        idBot *bot,
        const int curTime)
{
  this->isMoving = true;
  this->hasJumped = false;
}


// ========================================================================
// ?MoveSubGoal_Reached_CallBack@idBotBehaviorCombat_RandomJumpAttackEnemy@@UAAXPAVidBot@@H@Z
// EA  : 0x82B38A78
// RVA : 0x00B38A78
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

void __fastcall idBotBehaviorCombat_RandomJumpAttackEnemy::MoveSubGoal_Reached_CallBack(
        idBotBehaviorCombat_RandomJumpAttackEnemy *this,
        idBot *bot,
        const int curTime)
{
  this->isMoving = false;
  this->hasJumped = false;
}


// ========================================================================
// ??0idBotBehaviorCombat_CrouchAttackEnemy@@QAA@XZ
// EA  : 0x82B38A88
// RVA : 0x00B38A88
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

idBotBehaviorCombat_CrouchAttackEnemy *__fastcall idBotBehaviorCombat_CrouchAttackEnemy::idBotBehaviorCombat_CrouchAttackEnemy(
        idBotBehaviorCombat_CrouchAttackEnemy *this)
{
  idBehaviorAction::idBehaviorAction(this);
  this->backingAway = false;
  this->__vftable = (idBotBehaviorCombat_CrouchAttackEnemy_vtbl *)&idBotBehaviorCombat_CrouchAttackEnemy::`vftable';
  this->behaviorTime = 0;
  return this;
}


// ========================================================================
// ?MoveSubGoal_Reached_CallBack@idBotBehaviorCombat_CrouchAttackEnemy@@UAAXPAVidBot@@H@Z
// EA  : 0x82B38AD0
// RVA : 0x00B38AD0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

void __fastcall idBotBehaviorCombat_CrouchAttackEnemy::MoveSubGoal_Reached_CallBack(
        idBotBehaviorCombat_CrouchAttackEnemy *this,
        idBot *bot,
        const int curTime)
{
  this->backingAway = false;
}


// ========================================================================
// ??0idBotBehaviorCombat_MeleeAttackEnemy@@QAA@XZ
// EA  : 0x82B38AE0
// RVA : 0x00B38AE0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

idBotBehaviorCombat_MeleeAttackEnemy *__fastcall idBotBehaviorCombat_MeleeAttackEnemy::idBotBehaviorCombat_MeleeAttackEnemy(
        idBotBehaviorCombat_MeleeAttackEnemy *this)
{
  idBehaviorAction::idBehaviorAction(this);
  this->moveBlocked = false;
  this->__vftable = (idBotBehaviorCombat_MeleeAttackEnemy_vtbl *)&idBotBehaviorCombat_MeleeAttackEnemy::`vftable';
  return this;
}


// ========================================================================
// ?MoveSubGoal_Started_CallBack@idBotBehaviorCombat_StandGroundAttackEnemy@@UAAXPAVidBot@@H@Z
// EA  : 0x82B38B28
// RVA : 0x00B38B28
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

void __fastcall idBotBehaviorCombat_StandGroundAttackEnemy::MoveSubGoal_Started_CallBack(
        idBotBehaviorRoam *this,
        idBot *bot,
        const int curTime,
        const botMoveStatus_t moveStatusCode)
{
  this->moveStuck = true;
}


// ========================================================================
// ?GetPriority@idBotBehaviorCombat_RunAndAttackEnemy@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA  : 0x82B38BA0
// RVA : 0x00B38BA0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

behaviorPriority_t __fastcall idBotBehaviorCombat_RunAndAttackEnemy::GetPriority(
        idBotBehaviorCombat_RunAndAttackEnemy *this,
        idBot *bot,
        const int curTime)
{
  idBotTargetRecord *RecordForIndex; // r3
  double distToTarget; // fp0
  behaviorPriority_t result; // r3

  RecordForIndex = idBotWorldState::GetRecordForIndex(
                     this: bot->worldState,
                     index: bot->goalTask.goalEnemyTargetRecordIndex);
  distToTarget = RecordForIndex->volatileData.distToTarget;
  if ( distToTarget < 512.0 && (RecordForIndex->volatileData.targetFlags.flags & 0x20) != 0 )
    return BEHAVIOR_PRIORITY_NULL;
  result = BEHAVIOR_PRIORITY_NULL;
  if ( distToTarget > 64.0 )
    return BEHAVIOR_PRIORITY_NORMAL;
  return result;
}


// ========================================================================
// ?Think@idBotBehaviorCombat_RunAndAttackEnemy@@UAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA  : 0x82B38C20
// RVA : 0x00B38C20
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

int __fastcall idBotBehaviorCombat_RunAndAttackEnemy::Think(
        idBotBehaviorCombat_RunAndAttackEnemy *this,
        idBot *bot,
        const int curTime)
{
  idBotWorldState::GetRecordForIndex(this: bot->worldState, index: bot->goalTask.goalEnemyTargetRecordIndex);
  return 1;
}


// ========================================================================
// ?GetPriority@idBotBehaviorCombat_CircleStafeEnemy@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA  : 0x82B38C98
// RVA : 0x00B38C98
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

int __fastcall idBotBehaviorCombat_CircleStafeEnemy::GetPriority(
        idBotBehaviorCombat_CircleStafeEnemy *this,
        idBot *bot,
        int curTime)
{
  double distToTarget; // fp0
  int v7; // r30
  unsigned int v8; // r3
  unsigned int v9; // r8
  idVec3 *v10; // r5

  if ( idBehaviorState::CheckStateFlag(this, flag: 1) && this->behaviorFinishTime < curTime )
    return 0;
  distToTarget = idBotWorldState::GetRecordForIndex(
                   this: bot->worldState,
                   index: bot->goalTask.goalEnemyTargetRecordIndex)->volatileData.distToTarget;
  if ( distToTarget < 64.0 || distToTarget > 386.0 )
    return 0;
  if ( !idBehaviorState::CheckStateFlag(this, flag: 1) )
  {
    v7 = 0;
    v8 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v8;
    v9 = (v8 >> 10) & 0x7FFF;
    v10 = (idVec3 *)(100 * (v9 / 0x64));
    this->leftyStrafer = ((v9 % 0x64 <= 0x32) + 1) & 1;
    while ( !idBotMoveState::CanMoveInDir(
               this: bot->moveState,
               moveDirection: (const botRelativeMoveDirection_t)(((_cntlzw(this->leftyStrafer) & 0x20) != 0) + 1),
               moveUnits: 96.0,
               endPoint: v10) )
    {
      ++v7;
      this->leftyStrafer = (_cntlzw(this->leftyStrafer) & 0x20) != 0;
      if ( v7 >= 2 )
        return 0;
    }
  }
  return 2;
}


// ========================================================================
// ?Think@idBotBehaviorCombat_CircleStafeEnemy@@UAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA  : 0x82B38DE8
// RVA : 0x00B38DE8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

int __fastcall idBotBehaviorCombat_CircleStafeEnemy::Think(
        idBotBehaviorCombat_CircleStafeEnemy *this,
        idBot *bot,
        idVec3 *curTime)
{
  bool v4; // r5
  idVec3 v6[2]; // [sp+50h] [-30h] BYREF

  if ( !idBotMoveState::CanMoveInDir(
          this: bot->moveState,
          moveDirection: (const botRelativeMoveDirection_t)(((_cntlzw(this->leftyStrafer) & 0x20) != 0) + 1),
          moveUnits: 48.0,
          endPoint: curTime) )
    return 0;
  idBotMoveState::MoveToGoalCmd_SetMoveSubGoal(this: bot->moveState, point: v6, radius: 16.0, stopAtPoint: v4);
  return 1;
}


// ========================================================================
// ?GetPriority@idBotBehaviorCombat_SideStrafeEnemy@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA  : 0x82B38E70
// RVA : 0x00B38E70
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

int __fastcall idBotBehaviorCombat_SideStrafeEnemy::GetPriority(
        idBotBehaviorCombat_SideStrafeEnemy *this,
        idBot *bot,
        const int curTime)
{
  double distToTarget; // fp0
  int v8; // r30
  unsigned int v9; // r3
  unsigned int v10; // r8
  idVec3 *v11; // r5

  if ( idBehaviorState::CheckStateFlag(this, flag: 1) )
    return __CFADD__(this->behaviorFinishTime - curTime, curTime ^ 0x80000000) ? 0 : 2;
  distToTarget = idBotWorldState::GetRecordForIndex(
                   this: bot->worldState,
                   index: bot->goalTask.goalEnemyTargetRecordIndex)->volatileData.distToTarget;
  if ( distToTarget < 192.0 || distToTarget > 768.0 )
    return 0;
  v8 = 0;
  v9 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v9;
  v10 = (v9 >> 10) & 0x7FFF;
  v11 = (idVec3 *)(100 * (v10 / 0x64));
  this->leftyStrafer = ((v10 % 0x64 <= 0x32) + 1) & 1;
  while ( !idBotMoveState::CanMoveInDir(
             this: bot->moveState,
             moveDirection: (const botRelativeMoveDirection_t)(((_cntlzw(this->leftyStrafer) & 0x20) != 0) + 1),
             moveUnits: 96.0,
             endPoint: v11) )
  {
    ++v8;
    this->leftyStrafer = (_cntlzw(this->leftyStrafer) & 0x20) != 0;
    if ( v8 >= 2 )
      return 0;
  }
  return 2;
}


// ========================================================================
// ?Think@idBotBehaviorCombat_SideStrafeEnemy@@UAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA  : 0x82B38FC0
// RVA : 0x00B38FC0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

int __fastcall idBotBehaviorCombat_SideStrafeEnemy::Think(
        idBotBehaviorCombat_SideStrafeEnemy *this,
        idBot *bot,
        const int curTime)
{
  unsigned int v5; // r5
  bool leftyStrafer; // r11
  int v7; // r29
  unsigned int v8; // r31
  const idVec3 *v10; // r4
  unsigned int v11; // r3
  char v12; // [sp+50h] [-50h] BYREF
  char v13; // [sp+60h] [-40h] BYREF

  if ( idBotWorldState::GetRecordForIndex(this: bot->worldState, index: bot->goalTask.goalEnemyTargetRecordIndex)->volatileData.distToTarget > 128.0 )
  {
    if ( this->shouldJump && !this->jumped )
    {
      v11 = 1664525 * clientGame->random.seed + 1013904223;
      clientGame->random.seed = v11;
      v5 = ((v11 >> 10) & 0x7FFF) % 0x64;
      if ( v5 < 0xF )
      {
        idGuiListBox::DidActionRow(this: (idGuiListBox *)bot->moveState, actionRow: 1);
        this->jumped = true;
      }
    }
    if ( !idBotMoveState::CanMoveInDir(
            this: bot->moveState,
            moveDirection: (const botRelativeMoveDirection_t)(((_cntlzw(this->leftyStrafer) & 0x20) != 0) + 1),
            moveUnits: 48.0,
            endPoint: (idVec3 *)v5) )
      return 0;
    v10 = (const idVec3 *)&v13;
  }
  else
  {
    leftyStrafer = this->leftyStrafer;
    v7 = 0;
    while ( 1 )
    {
      v8 = leftyStrafer;
      if ( idBotMoveState::CanMoveInDir(
             this: bot->moveState,
             moveDirection: (const botRelativeMoveDirection_t)(((_cntlzw(leftyStrafer) & 0x20) != 0) + 5),
             moveUnits: 64.0,
             endPoint: (idVec3 *)v5) )
      {
        break;
      }
      ++v7;
      leftyStrafer = (_cntlzw(v8) & 0x20) != 0;
      if ( v7 >= 2 )
        return 0;
    }
    v10 = (const idVec3 *)&v12;
  }
  idBotMoveState::MoveToGoalCmd_SetMoveSubGoal(this: bot->moveState, point: v10, radius: 16.0, stopAtPoint: v5);
  return 1;
}


// ========================================================================
// ?GetPriority@idBotBehaviorCombat_QuickSideToSideStrafeEnemy@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA  : 0x82B39120
// RVA : 0x00B39120
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

int __fastcall idBotBehaviorCombat_QuickSideToSideStrafeEnemy::GetPriority(
        idBotBehaviorCombat_QuickSideToSideStrafeEnemy *this,
        idBot *bot,
        int curTime)
{
  double distToTarget; // fp0
  int v7; // r30
  unsigned int v8; // r3
  unsigned int v9; // r8
  idVec3 *v10; // r5

  if ( idBehaviorState::CheckStateFlag(this, flag: 1) && this->behaviorTime < curTime )
    return 0;
  distToTarget = idBotWorldState::GetRecordForIndex(
                   this: bot->worldState,
                   index: bot->goalTask.goalEnemyTargetRecordIndex)->volatileData.distToTarget;
  if ( distToTarget < 192.0 || distToTarget > 768.0 )
    return 0;
  if ( !idBehaviorState::CheckStateFlag(this, flag: 1) )
  {
    v7 = 0;
    v8 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v8;
    v9 = (v8 >> 10) & 0x7FFF;
    v10 = (idVec3 *)(100 * (v9 / 0x64));
    this->leftyStrafer = ((v9 % 0x64 <= 0x32) + 1) & 1;
    while ( !idBotMoveState::CanMoveInDir(
               this: bot->moveState,
               moveDirection: (const botRelativeMoveDirection_t)(((_cntlzw(this->leftyStrafer) & 0x20) != 0) + 1),
               moveUnits: 144.0,
               endPoint: v10) )
    {
      ++v7;
      this->leftyStrafer = (_cntlzw(this->leftyStrafer) & 0x20) != 0;
      if ( v7 >= 2 )
        return 0;
    }
  }
  return 2;
}


// ========================================================================
// ?Think@idBotBehaviorCombat_QuickSideToSideStrafeEnemy@@UAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA  : 0x82B39270
// RVA : 0x00B39270
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

int __fastcall idBotBehaviorCombat_QuickSideToSideStrafeEnemy::Think(
        idBotBehaviorCombat_QuickSideToSideStrafeEnemy *this,
        idBot *bot,
        int curTime)
{
  idVec3 *v6; // r5
  bool v7; // r5
  const idVec3 *v8; // r4
  BOOL v9; // r9
  char v11; // [sp+50h] [-60h] BYREF
  idVec3 v12; // [sp+60h] [-50h] BYREF
  char v13; // [sp+70h] [-40h] BYREF

  if ( idBotWorldState::GetRecordForIndex(this: bot->worldState, index: bot->goalTask.goalEnemyTargetRecordIndex)->volatileData.distToTarget > 256.0 )
  {
    if ( this->strafeDirDuration < curTime )
    {
      v9 = (_cntlzw(this->leftyStrafer) & 0x20) != 0;
      this->leftyStrafer = v9;
      if ( idBotMoveState::CanMoveInDir(
             this: bot->moveState,
             moveDirection: (const botRelativeMoveDirection_t)(((_cntlzw(v9) & 0x20) != 0) + 1),
             moveUnits: 48.0,
             endPoint: v6) )
      {
        this->strafeDirDuration = curTime + 700;
        idBotMoveState::MoveToGoalCmd_SetMoveSubGoal(
          this: bot->moveState,
          point: &v12,
          radius: 16.0,
          stopAtPoint: (const bool)v6);
        return 1;
      }
    }
    if ( idBotMoveState::CanMoveInDir(
           this: bot->moveState,
           moveDirection: (const botRelativeMoveDirection_t)(((_cntlzw(this->leftyStrafer) & 0x20) != 0) + 1),
           moveUnits: 48.0,
           endPoint: v6) )
    {
      v8 = (const idVec3 *)&v13;
      goto LABEL_9;
    }
  }
  else if ( idBotMoveState::CanMoveInDir(
              this: bot->moveState,
              moveDirection: (const botRelativeMoveDirection_t)(((_cntlzw(this->leftyStrafer) & 0x20) != 0) + 5),
              moveUnits: 64.0,
              endPoint: v6) )
  {
    v8 = (const idVec3 *)&v11;
LABEL_9:
    idBotMoveState::MoveToGoalCmd_SetMoveSubGoal(this: bot->moveState, point: v8, radius: 16.0, stopAtPoint: v7);
    return 1;
  }
  return 0;
}


// ========================================================================
// ?GetPriority@idBotBehaviorCombat_StandGroundAttackEnemy@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA  : 0x82B393A8
// RVA : 0x00B393A8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

behaviorPriority_t __fastcall idBotBehaviorCombat_StandGroundAttackEnemy::GetPriority(
        idBotBehaviorCombat_StandGroundAttackEnemy *this,
        idBot *bot,
        int curTime)
{
  behaviorPriority_t result; // r3
  double distToTarget; // fp13

  if ( idBehaviorState::CheckStateFlag(this, flag: 1) && this->behaviorTime < curTime )
    return BEHAVIOR_PRIORITY_NULL;
  distToTarget = idBotWorldState::GetRecordForIndex(
                   this: bot->worldState,
                   index: bot->goalTask.goalEnemyTargetRecordIndex)->volatileData.distToTarget;
  result = BEHAVIOR_PRIORITY_NULL;
  if ( distToTarget <= 768.0 )
    return BEHAVIOR_PRIORITY_NORMAL;
  return result;
}


// ========================================================================
// ??0idBotBehaviorCombat_RandomJumpAttackEnemy@@QAA@XZ
// EA  : 0x82B39420
// RVA : 0x00B39420
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

idBotBehaviorCombat_RandomJumpAttackEnemy *__fastcall idBotBehaviorCombat_RandomJumpAttackEnemy::idBotBehaviorCombat_RandomJumpAttackEnemy(
        idBotBehaviorCombat_RandomJumpAttackEnemy *this)
{
  idBehaviorAction::idBehaviorAction(this);
  this->hasJumped = false;
  this->__vftable = (idBotBehaviorCombat_RandomJumpAttackEnemy_vtbl *)&idBotBehaviorCombat_RandomJumpAttackEnemy::`vftable';
  this->isMoving = false;
  this->jumpDir = BOT_MOVE_MAX;
  this->behaviorTime = 0;
  this->stateUseCooldownTime = 3500;
  return this;
}


// ========================================================================
// ?GetPriority@idBotBehaviorCombat_CrouchAttackEnemy@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA  : 0x82B394E0
// RVA : 0x00B394E0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

int __fastcall idBotBehaviorCombat_CrouchAttackEnemy::GetPriority(
        idBotBehaviorCombat_CrouchAttackEnemy *this,
        idBot *bot,
        int curTime)
{
  idBotTargetRecord *RecordForIndex; // r29

  RecordForIndex = idBotWorldState::GetRecordForIndex(
                     this: bot->worldState,
                     index: bot->goalTask.goalEnemyTargetRecordIndex);
  if ( idBehaviorState::CheckStateFlag(this, flag: 1) )
  {
    if ( this->behaviorTime < curTime || RecordForIndex->volatileData.distToTarget < 128.0 )
      return 0;
  }
  else if ( RecordForIndex->volatileData.distToTarget < 386.0 )
  {
    return 0;
  }
  return ((unsigned int)RecordForIndex->volatileData.targetFlags.flags >> 4) & 2;
}


// ========================================================================
// ?Think@idBotBehaviorCombat_StandGroundAttackEnemy@@UAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA  : 0x82B39580
// RVA : 0x00B39580
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

int __fastcall idBotBehaviorCombat_StandGroundAttackEnemy::Think(
        idBotBehaviorCombat_CrouchAttackEnemy *this,
        idBot *bot,
        const int curTime)
{
  idVec3 *v4; // r5
  botRelativeMoveDirection_t v5; // r4
  signed int v6; // r31
  char v7; // r11
  idVec3 v9[4]; // [sp+50h] [-30h] BYREF

  if ( !this->backingAway
    && idBotWorldState::GetRecordForIndex(this: bot->worldState, index: bot->goalTask.goalEnemyTargetRecordIndex)->volatileData.distToTarget < 386.0 )
  {
    v5 = BOT_MOVE_SOUTH;
    v6 = 0;
    while ( !idBotMoveState::CanMoveInDir(this: bot->moveState, moveDirection: v5, moveUnits: 64.0, endPoint: v4) )
    {
      v7 = _cntlzw(v6++);
      v5 = ((v7 & 0x20) != 0) + 5;
      if ( v6 >= 3 )
        return 0;
    }
    idBotMoveState::MoveToGoalCmd_SetMoveSubGoal(
      this: bot->moveState,
      point: v9,
      radius: 16.0,
      stopAtPoint: (const bool)v4);
  }
  return 1;
}


// ========================================================================
// ?GetPriority@idBotBehaviorCombat_MeleeAttackEnemy@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA  : 0x82B39628
// RVA : 0x00B39628
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

behaviorPriority_t __fastcall idBotBehaviorCombat_MeleeAttackEnemy::GetPriority(
        idBotBehaviorCombat_MeleeAttackEnemy *this,
        idBot *bot,
        const int curTime)
{
  behaviorPriority_t result; // r3

  if ( !idBehaviorState::CheckStateFlag(this, flag: 1) )
    return BEHAVIOR_PRIORITY_NORMAL;
  result = BEHAVIOR_PRIORITY_NULL;
  if ( !this->moveBlocked )
    return BEHAVIOR_PRIORITY_NORMAL;
  return result;
}


// ========================================================================
// ?Enter@idBotBehaviorCombat_RunAndAttackEnemy@@UAAXPAVidBot@@H@Z
// EA  : 0x82B39680
// RVA : 0x00B39680
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

void __fastcall idBotBehaviorCombat_RunAndAttackEnemy::Enter(
        idBotBehaviorCombat_RunAndAttackEnemy *this,
        idBot *bot,
        const int curTime)
{
  unsigned int v5; // r4
  int value; // r6
  idEntity *v7; // r3
  idEntity *v8; // r28
  idBotMoveState *moveState; // r3
  idBotMoveCommand v10; // [sp+60h] [-90h] BYREF

  this->isDodging = false;
  v5 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v5;
  this->lastJumpTime = 0;
  this->lastDodgeTime = 0;
  this->leftyStrafer = ((((v5 >> 10) & 0x7FFF) % 0x64 <= 0x32) + 1) & 1;
  bot->moveState->idleStance = MOVE_STANCE_RUN;
  value = bot->goalTask.goalEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v8 = idEntity::CastTo(c: v7);
  }
  else
  {
    v8 = nullptr;
  }
  idBotMoveCommand::idBotMoveCommand(this: &v10, userName: "RunAndAttackEnemy", callBackState: this);
  idBotMoveCommand::SetMoveGoalEntity(this: &v10, goalEnt: v8, entityType: MOVE_ENTITY_TYPE_ENEMY);
  v10.moveStance = MOVE_STANCE_RUN;
  moveState = bot->moveState;
  v10.moveTolerance = 64.0;
  idBotMoveState::StartMoveToGoal(this: moveState, moveCmd: &v10);
  idBotMoveCommand::~idBotMoveCommand(this: &v10);
}


// ========================================================================
// __unwind$490435
// EA  : 0x82B397C0
// RVA : 0x00B397C0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

void _unwind_490435()
{
  int v0; // r12

  idBotMoveCommand::~idBotMoveCommand(this: (idBotMoveCommand *)(v0 - 240 + 96));
}


// ========================================================================
// ?Enter@idBotBehaviorCombat_CircleStafeEnemy@@UAAXPAVidBot@@H@Z
// EA  : 0x82B397F0
// RVA : 0x00B397F0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

void __fastcall idBotBehaviorCombat_CircleStafeEnemy::Enter(
        idBotBehaviorCombat_CircleStafeEnemy *this,
        idBot *bot,
        const int curTime)
{
  int value; // r9
  idEntity *v6; // r3
  idEntity *v7; // r29
  idBotMoveState *moveState; // r3
  idBotMoveCommand v9; // [sp+60h] [-90h] BYREF

  this->behaviorFinishTime = curTime + 3500;
  value = bot->goalTask.goalEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v7 = idEntity::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  idBotMoveCommand::idBotMoveCommand(this: &v9, userName: "CircleStrafeEnemy", callBackState: this);
  idBotMoveCommand::SetMoveGoalEntity(this: &v9, goalEnt: v7, entityType: MOVE_ENTITY_TYPE_ENEMY);
  moveState = bot->moveState;
  v9.moveStance = MOVE_STANCE_RUN;
  v9.moveTolerance = 1.0e30;
  idBotMoveState::StartMoveToGoal(this: moveState, moveCmd: &v9);
  bot->moveState->idleStance = MOVE_STANCE_RUN;
  idBotMoveCommand::~idBotMoveCommand(this: &v9);
}


// ========================================================================
// __unwind$490535
// EA  : 0x82B398C0
// RVA : 0x00B398C0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

void _unwind_490535()
{
  int v0; // r12

  idBotMoveCommand::~idBotMoveCommand(this: (idBotMoveCommand *)(v0 - 240 + 96));
}


// ========================================================================
// ?Enter@idBotBehaviorCombat_SideStrafeEnemy@@UAAXPAVidBot@@H@Z
// EA  : 0x82B398F0
// RVA : 0x00B398F0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

void __fastcall idBotBehaviorCombat_SideStrafeEnemy::Enter(
        idBotBehaviorCombat_SideStrafeEnemy *this,
        idBot *bot,
        const int curTime)
{
  idEntity *v3; // r28
  unsigned int v6; // r7
  int value; // r9
  idEntity *v8; // r3
  idBotMoveState *moveState; // r3
  idBotMoveCommand v10; // [sp+60h] [-90h] BYREF

  v3 = nullptr;
  this->behaviorFinishTime = curTime + 3000;
  this->jumped = false;
  v6 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v6;
  this->shouldJump = ((v6 >> 10) & 0x7FFF) % 0x64 <= 0xF;
  value = bot->goalTask.goalEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v8 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v8 != nullptr )
      v3 = idEntity::CastTo(c: v8);
  }
  idBotMoveCommand::idBotMoveCommand(this: &v10, userName: "SideStrafeEnemy", callBackState: this);
  idBotMoveCommand::SetMoveGoalEntity(this: &v10, goalEnt: v3, entityType: MOVE_ENTITY_TYPE_ENEMY);
  moveState = bot->moveState;
  v10.moveStance = MOVE_STANCE_RUN;
  v10.moveTolerance = 1.0e30;
  idBotMoveState::StartMoveToGoal(this: moveState, moveCmd: &v10);
  bot->moveState->idleStance = MOVE_STANCE_RUN;
  idBotMoveCommand::~idBotMoveCommand(this: &v10);
}


// ========================================================================
// __unwind$490624
// EA  : 0x82B39A24
// RVA : 0x00B39A24
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

void _unwind_490624()
{
  int v0; // r12

  idBotMoveCommand::~idBotMoveCommand(this: (idBotMoveCommand *)(v0 - 240 + 96));
}


// ========================================================================
// ?Enter@idBotBehaviorCombat_QuickSideToSideStrafeEnemy@@UAAXPAVidBot@@H@Z
// EA  : 0x82B39A58
// RVA : 0x00B39A58
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

void __fastcall idBotBehaviorCombat_QuickSideToSideStrafeEnemy::Enter(
        idBotBehaviorCombat_QuickSideToSideStrafeEnemy *this,
        idBot *bot,
        const int curTime)
{
  int value; // r7
  idEntity *v6; // r3
  idEntity *v7; // r28
  idBotMoveState *moveState; // r3
  idBotMoveCommand v9; // [sp+60h] [-90h] BYREF

  this->behaviorTime = curTime + 5500;
  this->strafeDirDuration = curTime + 700;
  value = bot->goalTask.goalEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v7 = idEntity::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  idBotMoveCommand::idBotMoveCommand(this: &v9, userName: "QuickSideToSideStrafeEnemy", callBackState: this);
  idBotMoveCommand::SetMoveGoalEntity(this: &v9, goalEnt: v7, entityType: MOVE_ENTITY_TYPE_ENEMY);
  moveState = bot->moveState;
  v9.moveStance = MOVE_STANCE_RUN;
  v9.moveTolerance = 1.0e30;
  idBotMoveState::StartMoveToGoal(this: moveState, moveCmd: &v9);
  bot->moveState->idleStance = MOVE_STANCE_RUN;
  idBotMoveCommand::~idBotMoveCommand(this: &v9);
}


// ========================================================================
// __unwind$490724
// EA  : 0x82B39B30
// RVA : 0x00B39B30
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

void _unwind_490724()
{
  int v0; // r12

  idBotMoveCommand::~idBotMoveCommand(this: (idBotMoveCommand *)(v0 - 240 + 96));
}


// ========================================================================
// ?Enter@idBotBehaviorCombat_StandGroundAttackEnemy@@UAAXPAVidBot@@H@Z
// EA  : 0x82B39B60
// RVA : 0x00B39B60
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

void __fastcall idBotBehaviorCombat_StandGroundAttackEnemy::Enter(
        idBotBehaviorCombat_StandGroundAttackEnemy *this,
        idBot *bot,
        const int curTime)
{
  idEntity *v3; // r28
  int value; // r8
  idEntity *v7; // r3
  idBotMoveState *moveState; // r3
  idBotMoveCommand v9; // [sp+60h] [-90h] BYREF

  v3 = nullptr;
  this->behaviorTime = curTime + 700;
  this->backingAway = false;
  value = bot->goalTask.goalEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v7 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v7 != nullptr )
      v3 = idEntity::CastTo(c: v7);
  }
  idBotMoveCommand::idBotMoveCommand(this: &v9, userName: "StandGroundAttackEnemy", callBackState: this);
  idBotMoveCommand::SetMoveGoalEntity(this: &v9, goalEnt: v3, entityType: MOVE_ENTITY_TYPE_ENEMY);
  moveState = bot->moveState;
  v9.moveStance = MOVE_STANCE_RUN;
  v9.moveTolerance = 1.0e30;
  idBotMoveState::StartMoveToGoal(this: moveState, moveCmd: &v9);
  bot->moveState->idleStance = MOVE_STANCE_RUN;
  idBotMoveCommand::~idBotMoveCommand(this: &v9);
}


// ========================================================================
// __unwind$490811
// EA  : 0x82B39C30
// RVA : 0x00B39C30
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

void _unwind_490811()
{
  int v0; // r12

  idBotMoveCommand::~idBotMoveCommand(this: (idBotMoveCommand *)(v0 - 240 + 96));
}


// ========================================================================
// ?Enter@idBotBehaviorCombat_RandomJumpAttackEnemy@@UAAXPAVidBot@@H@Z
// EA  : 0x82B39C60
// RVA : 0x00B39C60
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

void __fastcall idBotBehaviorCombat_RandomJumpAttackEnemy::Enter(
        idBotBehaviorCombat_RandomJumpAttackEnemy *this,
        idBot *bot,
        const int curTime)
{
  idEntity *v3; // r28
  int value; // r8
  idEntity *v7; // r3
  idBotMoveState *moveState; // r3
  idBotMoveCommand v9; // [sp+60h] [-90h] BYREF

  v3 = nullptr;
  this->behaviorTime = curTime + 5500;
  this->isMoving = false;
  this->hasJumped = false;
  value = bot->goalTask.goalEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v7 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v7 != nullptr )
      v3 = idEntity::CastTo(c: v7);
  }
  idBotMoveCommand::idBotMoveCommand(this: &v9, userName: "RandomJumpAttackEnemy", callBackState: this);
  idBotMoveCommand::SetMoveGoalEntity(this: &v9, goalEnt: v3, entityType: MOVE_ENTITY_TYPE_ENEMY);
  moveState = bot->moveState;
  v9.moveStance = MOVE_STANCE_RUN;
  v9.moveTolerance = 1.0e30;
  idBotMoveState::StartMoveToGoal(this: moveState, moveCmd: &v9);
  bot->moveState->idleStance = MOVE_STANCE_RUN;
  idBotMoveCommand::~idBotMoveCommand(this: &v9);
}


// ========================================================================
// __unwind$490898_1
// EA  : 0x82B39D34
// RVA : 0x00B39D34
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

void _unwind_490898_1()
{
  int v0; // r12

  idBotMoveCommand::~idBotMoveCommand(this: (idBotMoveCommand *)(v0 - 240 + 96));
}


// ========================================================================
// ?Enter@idBotBehaviorCombat_CrouchAttackEnemy@@UAAXPAVidBot@@H@Z
// EA  : 0x82B39D68
// RVA : 0x00B39D68
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

void __fastcall idBotBehaviorCombat_CrouchAttackEnemy::Enter(
        idBotBehaviorCombat_CrouchAttackEnemy *this,
        idBot *bot,
        const int curTime)
{
  idEntity *v3; // r28
  int value; // r8
  idEntity *v7; // r3
  idBotMoveState *moveState; // r3
  idBotMoveCommand v9; // [sp+60h] [-90h] BYREF

  v3 = nullptr;
  this->behaviorTime = curTime + 5000;
  this->backingAway = false;
  value = bot->goalTask.goalEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v7 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v7 != nullptr )
      v3 = idEntity::CastTo(c: v7);
  }
  idBotMoveCommand::idBotMoveCommand(this: &v9, userName: "CrouchAttackEnemy", callBackState: this);
  idBotMoveCommand::SetMoveGoalEntity(this: &v9, goalEnt: v3, entityType: MOVE_ENTITY_TYPE_ENEMY);
  moveState = bot->moveState;
  v9.moveStance = MOVE_STANCE_CROUCH;
  v9.moveTolerance = 1.0e30;
  idBotMoveState::StartMoveToGoal(this: moveState, moveCmd: &v9);
  bot->moveState->idleStance = MOVE_STANCE_CROUCH;
  idBotMoveCommand::~idBotMoveCommand(this: &v9);
}


// ========================================================================
// __unwind$490985
// EA  : 0x82B39E38
// RVA : 0x00B39E38
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

void _unwind_490985()
{
  int v0; // r12

  idBotMoveCommand::~idBotMoveCommand(this: (idBotMoveCommand *)(v0 - 240 + 96));
}


// ========================================================================
// ?Enter@idBotBehaviorCombat_MeleeAttackEnemy@@UAAXPAVidBot@@H@Z
// EA  : 0x82B39E68
// RVA : 0x00B39E68
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

void __fastcall idBotBehaviorCombat_MeleeAttackEnemy::Enter(
        idBotBehaviorCombat_MeleeAttackEnemy *this,
        idBot *bot,
        const int curTime)
{
  idEntity *v3; // r29
  int value; // r8
  idEntity *v7; // r3
  idBotMoveState *moveState; // r3
  idBotMoveCommand v9; // [sp+60h] [-90h] BYREF

  v3 = nullptr;
  this->moveBlocked = false;
  bot->moveState->idleStance = MOVE_STANCE_RUN;
  value = bot->goalTask.goalEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v7 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v7 != nullptr )
      v3 = idEntity::CastTo(c: v7);
  }
  idBotMoveCommand::idBotMoveCommand(this: &v9, userName: "MeleeAttackEnemy", callBackState: this);
  idBotMoveCommand::SetMoveGoalEntity(this: &v9, goalEnt: v3, entityType: MOVE_ENTITY_TYPE_ENEMY);
  v9.moveStance = MOVE_STANCE_RUN;
  moveState = bot->moveState;
  v9.moveTolerance = 16.0;
  idBotMoveState::StartMoveToGoal(this: moveState, moveCmd: &v9);
  idBotMoveCommand::~idBotMoveCommand(this: &v9);
}


// ========================================================================
// __unwind$491072
// EA  : 0x82B39F30
// RVA : 0x00B39F30
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

void _unwind_491072()
{
  int v0; // r12

  idBotMoveCommand::~idBotMoveCommand(this: (idBotMoveCommand *)(v0 - 240 + 96));
}


// ========================================================================
// ?GetPriority@idBotBehaviorCombat_RandomJumpAttackEnemy@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA  : 0x82B39F60
// RVA : 0x00B39F60
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

int __fastcall idBotBehaviorCombat_RandomJumpAttackEnemy::GetPriority(
        idBotBehaviorCombat_RandomJumpAttackEnemy *this,
        idBot *bot,
        int curTime)
{
  idBotTargetRecord *RecordForIndex; // r30
  double distToTarget; // fp0
  bool v8; // r30
  bool v9; // r29
  int v10; // r11
  encounterGroupRole_t v11; // r11
  int v12; // r5
  encounterGroupRole_t v13; // r11
  signed int num; // r30
  encounterGroupRole_t *list; // r27
  int v16; // r29
  unsigned int seed; // r10
  unsigned int v18; // r7
  int v19; // r6
  idBotMoveState *moveState; // r3
  botRelativeMoveDirection_t *v21; // r28
  int v23; // [sp+50h] [-80h] BYREF
  encounterGroupRole_t v24[3]; // [sp+54h] [-7Ch] BYREF
  idList<enum encounterGroupRole_t,5> v25[7]; // [sp+60h] [-70h] BYREF

  if ( idBehaviorState::CheckStateFlag(this, flag: 1) && this->behaviorTime < curTime )
    return 0;
  RecordForIndex = idBotWorldState::GetRecordForIndex(
                     this: bot->worldState,
                     index: bot->goalTask.goalEnemyTargetRecordIndex);
  if ( RecordForIndex->volatileData.distToTarget > 768.0 )
    return 0;
  if ( !idBehaviorState::CheckStateFlag(this, flag: 1) )
  {
    if ( this->lastStateRunTime + 3500 > curTime )
      return 0;
    distToTarget = RecordForIndex->volatileData.distToTarget;
    v8 = distToTarget < 256.0;
    v9 = distToTarget > 512.0;
    idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: (idList<idDeclVehicleUpgrade const *,5> *)v25);
    if ( v25[0].size < 3 )
      idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)v25, newsize: 3);
    v23 = 2;
    if ( v8 )
    {
      v10 = 6;
    }
    else
    {
      if ( !v9 )
        goto LABEL_13;
      v10 = 4;
    }
    v23 = v10;
LABEL_13:
    v24[0] = ROLE_DEFEND;
    if ( v8 )
    {
      v11 = ROLE_FORMATION;
    }
    else
    {
      if ( !v9 )
        goto LABEL_18;
      v11 = ROLE_FLANK;
    }
    v24[0] = v11;
LABEL_18:
    idList<idAnimWebBlendTree *,5>::Append(this: v25, obj: (const encounterGroupRole_t *)&v23);
    idList<idAnimWebBlendTree *,5>::Append(this: v25, obj: v24);
    if ( v8 )
    {
      v13 = ROLE_NONE;
    }
    else
    {
      if ( !v9 )
      {
LABEL_23:
        num = v25[0].num;
        if ( v25[0].num > 0 )
        {
          list = v25[0].list;
          while ( 1 )
          {
            if ( num != 0 )
            {
              seed = clientGame->random.seed;
              __twllei(num, 0);
              v18 = 1664525 * seed + 1013904223;
              clientGame->random.seed = v18;
              v19 = (v18 >> 10) & 0x7FFF;
              v12 = v19 / num;
              v16 = v19 % num;
              __twlgei(num & ~(__ROL4__(v19, 1) - 1), 0xFFFFFFFF);
            }
            else
            {
              v16 = 0;
            }
            moveState = bot->moveState;
            v21 = (botRelativeMoveDirection_t *)&list[v16];
            v24[0] = (encounterGroupRole_t)v21;
            if ( idBotMoveState::CanMoveInDir(
                   this: moveState,
                   moveDirection: *v21,
                   moveUnits: 144.0,
                   endPoint: (idVec3 *)v12) )
            {
              break;
            }
            if ( v16 >= 0 && v16 < num )
            {
              v25[0].num = --num;
              if ( v16 != num )
                *v21 = (botRelativeMoveDirection_t)list[num];
            }
            if ( num <= 0 )
              goto LABEL_34;
          }
          this->jumpDir = *v21;
          idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v25);
          return 2;
        }
LABEL_34:
        idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v25);
        return 0;
      }
      v13 = ROLE_CHARGE;
    }
    v24[0] = v13;
    idList<idAnimWebBlendTree *,5>::Append(this: v25, obj: v24);
    goto LABEL_23;
  }
  return 2;
}


// ========================================================================
// __unwind$491195
// EA  : 0x82B3A1D8
// RVA : 0x00B3A1D8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

void _unwind_491195()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 208 + 96));
}


// ========================================================================
// ?Think@idBotBehaviorCombat_RandomJumpAttackEnemy@@UAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA  : 0x82B3A208
// RVA : 0x00B3A208
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

int __fastcall idBotBehaviorCombat_RandomJumpAttackEnemy::Think(
        idBotBehaviorCombat_RandomJumpAttackEnemy *this,
        idBot *bot,
        idVec3 *curTime)
{
  unsigned int v5; // r4
  botRelativeMoveDirection_t jumpDir; // r4
  bool v8; // r5
  double distToTarget; // fp0
  bool v10; // r30
  bool v11; // r29
  int v12; // r11
  int v13; // r5
  signed int num; // r30
  encounterGroupRole_t *list; // r27
  int v16; // r29
  unsigned int seed; // r10
  unsigned int v18; // r7
  int v19; // r6
  idBotMoveState *moveState; // r3
  int v21; // [sp+50h] [-A0h] BYREF
  int v22; // [sp+54h] [-9Ch] BYREF
  idVec3 v23; // [sp+58h] [-98h] BYREF
  idVec3 v24[2]; // [sp+68h] [-88h] BYREF
  idList<enum encounterGroupRole_t,5> v25[7]; // [sp+80h] [-70h] BYREF

  if ( this->isMoving )
  {
    if ( !this->hasJumped )
    {
      v5 = 1664525 * clientGame->random.seed + 1013904223;
      clientGame->random.seed = v5;
      if ( ((v5 >> 10) & 0x7FFF) % 0x64 < 0x23 )
      {
        idGuiListBox::DidActionRow(this: (idGuiListBox *)bot->moveState, actionRow: 1);
        this->hasJumped = true;
      }
    }
    return 1;
  }
  jumpDir = this->jumpDir;
  if ( jumpDir != BOT_MOVE_MAX
    && idBotMoveState::CanMoveInDir(this: bot->moveState, moveDirection: jumpDir, moveUnits: 80.0, endPoint: curTime) )
  {
    idBotMoveState::MoveToGoalCmd_SetMoveSubGoal(this: bot->moveState, point: &v23, radius: 16.0, stopAtPoint: v8);
    this->jumpDir = BOT_MOVE_MAX;
    return 1;
  }
  distToTarget = idBotWorldState::GetRecordForIndex(
                   this: bot->worldState,
                   index: bot->goalTask.goalEnemyTargetRecordIndex)->volatileData.distToTarget;
  v10 = distToTarget < 256.0;
  v11 = distToTarget > 512.0;
  memset(v25, 0, 14);
  v25[0].memTag = 5;
  v25[0].listStatic = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v25);
  if ( v25[0].size < 3 )
    idList<idNavSpline *,5>::Resize(this: (idList<idSpawnArea::GeneratedPosition *,5> *)v25, newsize: 3);
  v21 = 2;
  if ( v10 )
  {
    v12 = 6;
  }
  else
  {
    if ( !v11 )
      goto LABEL_16;
    v12 = 4;
  }
  v21 = v12;
LABEL_16:
  v22 = 1;
  if ( v10 )
  {
    v22 = 5;
  }
  else if ( v11 )
  {
    v22 = 3;
  }
  idList<idAnimWebBlendTree *,5>::Append(this: v25, obj: (const encounterGroupRole_t *)&v21);
  idList<idAnimWebBlendTree *,5>::Append(this: v25, obj: (const encounterGroupRole_t *)&v22);
  if ( v10 )
  {
    v22 = 0;
  }
  else
  {
    if ( !v11 )
      goto LABEL_25;
    v22 = 7;
  }
  idList<idAnimWebBlendTree *,5>::Append(this: v25, obj: (const encounterGroupRole_t *)&v22);
LABEL_25:
  num = v25[0].num;
  if ( v25[0].num <= 0 )
  {
LABEL_36:
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v25);
    return 0;
  }
  else
  {
    list = v25[0].list;
    while ( 1 )
    {
      if ( num != 0 )
      {
        seed = clientGame->random.seed;
        __twllei(num, 0);
        v18 = 1664525 * seed + 1013904223;
        clientGame->random.seed = v18;
        v19 = (v18 >> 10) & 0x7FFF;
        v13 = v19 / num;
        v16 = v19 % num;
        __twlgei(num & ~(__ROL4__(v19, 1) - 1), 0xFFFFFFFF);
      }
      else
      {
        v16 = 0;
      }
      moveState = bot->moveState;
      v22 = (int)&list[v16];
      if ( idBotMoveState::CanMoveInDir(
             this: moveState,
             moveDirection: *(const botRelativeMoveDirection_t *)v22,
             moveUnits: 80.0,
             endPoint: (idVec3 *)v13) )
      {
        break;
      }
      if ( v16 >= 0 && v16 < num )
      {
        v25[0].num = --num;
        if ( v16 != num )
          list[v16] = list[num];
      }
      if ( num <= 0 )
        goto LABEL_36;
    }
    idBotMoveState::MoveToGoalCmd_SetMoveSubGoal(this: bot->moveState, point: v24, radius: 16.0, stopAtPoint: v13);
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v25);
    return 1;
  }
}


// ========================================================================
// __unwind$491298
// EA  : 0x82B3A520
// RVA : 0x00B3A520
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\combat\bot_bt_combat_attacks.cpp
// ========================================================================

void _unwind_491298()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 240 + 128));
}

