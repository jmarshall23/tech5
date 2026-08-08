
// ========================================================================
// ??0idBotBehaviorEscort@@QAA@XZ
// EA  : 0x82B37C38
// RVA : 0x00B37C38
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_escort.cpp
// ========================================================================

idBotBehaviorEscort *__fastcall idBotBehaviorEscort::idBotBehaviorEscort(idBotBehaviorEscort *this)
{
  idBehaviorAction::idBehaviorAction(this);
  this->reachedMate = false;
  this->__vftable = (idBotBehaviorEscort_vtbl *)&idBotBehaviorEscort::`vftable';
  this->currentMoveTolerance = 128.0;
  this->timeReachedMate = 0;
  this->timeInMatesCrossHair = 0;
  this->timeMateHasBeenCrouched = 0;
  idCurve_BSpline<idAngles>::SetOrder((idAnimator_DragJoints *)this, web: (idAnimator_AnimWeb *)4);
  return this;
}


// ========================================================================
// __unwind$488432
// EA  : 0x82B37CB0
// RVA : 0x00B37CB0
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_escort.cpp
// ========================================================================

void _unwind_488432()
{
  int v0; // r12

  idBehaviorAction::~idBehaviorAction(this: *(idBehaviorAction **)(v0 - 112 + 132));
}


// ========================================================================
// ?MoveGoal_Reached_CallBack@idBotBehaviorEscort@@UAAXPAVidBot@@H@Z
// EA  : 0x82B37CD8
// RVA : 0x00B37CD8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_escort.cpp
// ========================================================================

void __fastcall idBotBehaviorEscort::MoveGoal_Reached_CallBack(idBotBehaviorEscort *this, idBot *bot, int curTime)
{
  if ( this->reachedMate )
  {
    this->avoidingMate = false;
  }
  else
  {
    this->timeReachedMate = curTime;
    this->reachedMate = true;
    this->avoidingMate = false;
    this->currentMoveTolerance = 386.0;
  }
}


// ========================================================================
// ?MoveSubGoal_Reached_CallBack@idBotBehaviorEscort@@UAAXPAVidBot@@H@Z
// EA  : 0x82B37D18
// RVA : 0x00B37D18
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_escort.cpp
// ========================================================================

void __fastcall idBotBehaviorEscort::MoveSubGoal_Reached_CallBack(idBotBehaviorEscort *this, idBot *bot, int curTime)
{
  this->MoveGoal_Reached_CallBack(this, a2: bot, a3: curTime);
}


// ========================================================================
// ?MoveSubGoal_Errored_CallBack@idBotBehaviorEscort@@UAAXPAVidBot@@HW4botMoveStatus_t@@@Z
// EA  : 0x82B37D28
// RVA : 0x00B37D28
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_escort.cpp
// ========================================================================

void __fastcall idBotBehaviorEscort::MoveSubGoal_Errored_CallBack(
        idBotBehaviorEscort *this,
        idBot *bot,
        const int curTime,
        const botMoveStatus_t moveStatusCode)
{
  this->avoidingMate = false;
}


// ========================================================================
// ?MoveGoal_Started_CallBack@idBotBehaviorEscort@@UAAXPAVidBot@@H@Z
// EA  : 0x82B37D38
// RVA : 0x00B37D38
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_escort.cpp
// ========================================================================

void __fastcall idBotBehaviorEscort::MoveGoal_Started_CallBack(
        idBotBehaviorEscort *this,
        idBot *bot,
        const int curTime)
{
  this->reachedMate = false;
  this->timeReachedMate = 0;
  this->avoidingMate = false;
  this->currentMoveTolerance = 128.0;
}


// ========================================================================
// ?MoveSubGoal_Started_CallBack@idBotBehaviorEscort@@UAAXPAVidBot@@H@Z
// EA  : 0x82B37D58
// RVA : 0x00B37D58
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_escort.cpp
// ========================================================================

void __fastcall idBotBehaviorEscort::MoveSubGoal_Started_CallBack(
        idBotBehaviorEscort *this,
        idBot *bot,
        const int curTime)
{
  this->reachedMate = false;
  this->timeReachedMate = 0;
  this->avoidingMate = true;
  this->timeInMatesCrossHair = 0;
}


// ========================================================================
// ?GetPriority@idBotBehaviorEscort@@UAA?AW4behaviorPriority_t@@PAVidBot@@H@Z
// EA  : 0x82B37D78
// RVA : 0x00B37D78
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_escort.cpp
// ========================================================================

behaviorPriority_t __fastcall idBotBehaviorEscort::GetPriority(
        idBotBehaviorEscort *this,
        idBot *bot,
        const int curTime)
{
  int value; // r10
  idEntity *v4; // r3
  behaviorPriority_t result; // r3
  bool v6; // zf

  if ( bot->goalTask.goalType.flags != 4 )
    return BEHAVIOR_PRIORITY_NULL;
  value = bot->goalTask.goalEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return BEHAVIOR_PRIORITY_NULL;
  v4 = gameLocal->entities.ptr[value & 0x1FFF];
  if ( v4 == nullptr )
    return BEHAVIOR_PRIORITY_NULL;
  v6 = idEntity::CastTo(c: v4) != nullptr;
  result = BEHAVIOR_PRIORITY_NORMAL;
  if ( !v6 )
    return BEHAVIOR_PRIORITY_NULL;
  return result;
}


// ========================================================================
// ?Enter@idBotBehaviorEscort@@UAAXPAVidBot@@H@Z
// EA  : 0x82B37DF8
// RVA : 0x00B37DF8
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_escort.cpp
// ========================================================================

void __fastcall idBotBehaviorEscort::Enter(idBotBehaviorEscort *this, idBot *bot, const int curTime)
{
  int value; // r8
  idEntity *v5; // r3
  idEntity *v6; // r4
  idBotMoveCommand v7; // [sp+60h] [-90h] BYREF

  this->reachedMate = false;
  this->timeReachedMate = 0;
  this->currentMoveTolerance = 128.0;
  this->timeMateHasBeenCrouched = 0;
  this->timeInMatesCrossHair = 0;
  this->avoidingMate = false;
  bot->moveState->idleStance = MOVE_STANCE_RUN;
  idBotMoveCommand::idBotMoveCommand(this: &v7, userName: "Escort Teammate", callBackState: this);
  value = bot->goalTask.goalEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v5 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v5 != nullptr )
      v6 = idEntity::CastTo(c: v5);
    else
      v6 = nullptr;
  }
  else
  {
    v6 = nullptr;
  }
  idBotMoveCommand::SetMoveGoalEntity(this: &v7, goalEnt: v6, entityType: MOVE_ENTITY_TYPE_GOAL_ENTITY);
  v7.moveTolerance = 128.0;
  v7.moveStance = MOVE_STANCE_RUN;
  idBotMoveState::StartMoveToGoal(this: bot->moveState, moveCmd: &v7);
  idBotMoveCommand::~idBotMoveCommand(this: &v7);
}


// ========================================================================
// __unwind$488790_0
// EA  : 0x82B37EE4
// RVA : 0x00B37EE4
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_escort.cpp
// ========================================================================

void _unwind_488790_0()
{
  int v0; // r12

  idBotMoveCommand::~idBotMoveCommand(this: (idBotMoveCommand *)(v0 - 240 + 96));
}


// ========================================================================
// ?Update_ReachedTeammateBehavior@idBotBehaviorEscort@@QAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA  : 0x82B37F10
// RVA : 0x00B37F10
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_escort.cpp
// ========================================================================

int __fastcall idBotBehaviorEscort::Update_ReachedTeammateBehavior(idBotBehaviorEscort *this, idBot *bot, int curTime)
{
  int value; // r10
  idEntity *v7; // r3
  idPlayer *v8; // r24
  idBotTargetRecord *RecordForEntity; // r3
  double distToTarget; // fp31
  BOOL v11; // r31
  idPhysics *Physics; // r3
  idVec3 *v13; // r5
  bool v14; // r5
  idPlayer *v15; // r30
  idPhysics *v16; // r3
  int v17; // r3
  char *v18; // r10
  _DWORD *v19; // r11
  int i; // ctr
  idPresentable *presentable; // r3
  int v22; // r3
  idPresentable *v23; // r11
  float *v24; // r31
  int v25; // r3
  double v26; // fp8
  double v27; // fp6
  double v28; // fp9
  double v29; // fp5
  idPresentable *v30; // r3
  int v31; // r3
  bool IsPressedForPlayer; // r3
  idPresentable *v33; // r11
  bool v34; // r30
  int v35; // r3
  idVec3 *v36; // r5
  bool v37; // r3
  bool v38; // r5
  int v39; // r9
  idEntity *v40; // r3
  idEntity *v41; // r4
  idVec3 v43; // [sp+50h] [-B0h] BYREF
  idVec3 v44; // [sp+60h] [-A0h] BYREF
  idVec3 v45; // [sp+70h] [-90h] BYREF
  char v46; // [sp+7Ch] [-84h] BYREF
  idBounds v47; // [sp+80h] [-80h] BYREF

  value = bot->goalTask.goalEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v8 = (idPlayer *)idEntity::CastTo(c: v7);
  }
  else
  {
    v8 = nullptr;
  }
  RecordForEntity = idBotWorldState::GetRecordForEntity(this: bot->worldState, entity: v8);
  distToTarget = RecordForEntity->volatileData.distToTarget;
  v11 = (RecordForEntity->volatileData.targetFlags.flags & 0x80) != 0;
  Physics = idEntity::GetPhysics(this: v8);
  Physics->GetOrigin(this: Physics, a2: 0);
  bot->moveState->idleStance = MOVE_STANCE_RUN;
  if ( v11 )
  {
    if ( this->timeMateHasBeenCrouched == 0 )
      this->timeMateHasBeenCrouched = curTime;
    if ( this->timeMateHasBeenCrouched + 900 < curTime )
      bot->moveState->idleStance = MOVE_STANCE_CROUCH;
  }
  else
  {
    this->timeMateHasBeenCrouched = 0;
  }
  if ( distToTarget > 64.0 )
  {
    v15 = idPlayer::CastTo(c: v8);
    if ( v15 != nullptr )
    {
      v16 = idEntity::GetPhysics(this: bot->owner);
      v17 = (int)v16->GetAbsBounds(this: v16, a2: -1);
      v18 = &v46;
      v19 = (_DWORD *)(v17 - 4);
      for ( i = 6; i != 0; --i )
      {
        ++v19;
        v18 += 4;
        *(_DWORD *)v18 = *v19;
      }
      v47.b[0].x = v47.b[0].x - (float)16.0;
      v47.b[0].y = v47.b[0].y - (float)16.0;
      v47.b[0].z = v47.b[0].z - (float)16.0;
      v47.b[1].x = v47.b[1].x + (float)16.0;
      v47.b[1].y = v47.b[1].y + (float)16.0;
      v47.b[1].z = v47.b[1].z + (float)16.0;
      presentable = v15->presentable;
      if ( presentable != nullptr )
        v22 = (int)presentable->GetPlayerInterface_2(this: presentable);
      else
        v22 = 0;
      v23 = v15->presentable;
      v24 = (float *)(v22 + 46544);
      if ( v23 != nullptr )
        v25 = (int)v23->GetPlayerInterface_2(this: v15->presentable);
      else
        v25 = 0;
      v26 = (float)(v24[2] * (float)8192.0);
      v27 = (float)(*v24 * (float)8192.0);
      v28 = *(float *)(v25 + 46540);
      v29 = *(float *)(v25 + 46532);
      v43.y = *(float *)(v25 + 46536) + (float)(v24[1] * (float)8192.0);
      v43.z = (float)v28 + (float)v26;
      v43.x = (float)v29 + (float)v27;
      if ( idBounds::LineIntersection(this: &v47, start: (const idVec3 *)(v25 + 46532), end: &v43) )
      {
        if ( this->timeInMatesCrossHair == 0 )
          this->timeInMatesCrossHair = curTime;
        v30 = v15->presentable;
        if ( v30 != nullptr )
          v31 = (int)v30->GetPlayerInterface_2(this: v30);
        else
          v31 = 0;
        IsPressedForPlayer = idUCmdTracker::IsPressedForPlayer(this: (idUCmdTracker *)(v31 + 45960), mask: 1);
        v33 = v15->presentable;
        v34 = IsPressedForPlayer;
        if ( v33 != nullptr )
          v35 = (int)v33->GetPlayerInterface_2(this: v33);
        else
          v35 = 0;
        v37 = idUCmdTracker::IsPressedForPlayer(this: (idUCmdTracker *)(v35 + 45960), mask: 8);
        if ( (this->timeInMatesCrossHair + 1200 < curTime || v34 || v37)
          && idBotUtils::FindAvoidEntityPoint(
               bot,
               ent: v8,
               moveDist: 64.0,
               point: v36,
               anchorPoint: &v45,
               anchorRadius: this->currentMoveTolerance) )
        {
          idBotMoveState::MoveToGoalCmd_SetMoveSubGoal(this: bot->moveState, point: &v45, radius: 8.0, stopAtPoint: v38);
        }
      }
      else
      {
        this->timeInMatesCrossHair = 0;
      }
    }
  }
  else if ( idBotUtils::FindAvoidEntityPoint(
              bot,
              ent: v8,
              moveDist: 48.0,
              point: v13,
              anchorPoint: &v44,
              anchorRadius: 0.0) )
  {
    idBotMoveState::MoveToGoalCmd_SetMoveSubGoal(this: bot->moveState, point: &v44, radius: 8.0, stopAtPoint: v14);
  }
  v39 = bot->goalTask.goalEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v39 & 0x1FFF] == v39 >> 13
    && (v40 = gameLocal->entities.ptr[v39 & 0x1FFF]) != nullptr
    && (v41 = idEntity::CastTo(c: v40)) != nullptr )
  {
    idBotAimState::AddAimRequestEntity(
      this: bot->aimState,
      entity: v41,
      priority: AIM_PRIORITY_BEHAVIOR_DRIVEN,
      userName: "Escort_IDLE_LookAtEnemy",
      aimPoint: AIMPOINT_BEST,
      aimTimeInSeconds: -1.0);
    idBotWeaponState::AddWeaponRequest(
      this: bot->weaponState,
      priority: WEAPON_PRIORITY_BEHAVIOR_DRIVEN,
      weapSlot: WEAPON_SLOT_PRIMARY,
      userName: "Escort_IDLE_GunForEnemy",
      fireMode: WEAPON_FIRE_MODE_WHEN_READY);
    return 1;
  }
  else
  {
    if ( this->timeReachedMate + 2500 > curTime )
      idBotAimState::AddAimRequestEntity(
        this: bot->aimState,
        entity: v8,
        priority: AIM_PRIORITY_BEHAVIOR_DRIVEN,
        userName: "Escort_IDLE_LookAtMate",
        aimPoint: AIMPOINT_HEAD,
        aimTimeInSeconds: -1.0);
    return 1;
  }
}


// ========================================================================
// ?Update_MovingToTeammateBehavior@idBotBehaviorEscort@@QAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA  : 0x82B38370
// RVA : 0x00B38370
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_escort.cpp
// ========================================================================

int __fastcall idBotBehaviorEscort::Update_MovingToTeammateBehavior(
        idBotBehaviorEscort *this,
        idBot *bot,
        const int curTime)
{
  int value; // r10
  idEntity *v6; // r3
  idEntity *v7; // r4
  idBotTargetRecord *RecordForEntity; // r3
  char v9; // r29
  double distToTarget; // fp31
  bool v11; // r30
  int v12; // r4
  int v13; // r9
  idGameLocal *v14; // r11
  idEntity *v15; // r3
  idEntity *v16; // r4
  int v18; // r9
  idEntity *v19; // r3
  idEntity *v20; // r4

  value = bot->goalTask.goalEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v7 = idEntity::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  RecordForEntity = idBotWorldState::GetRecordForEntity(this: bot->worldState, entity: v7);
  v9 = 0;
  distToTarget = RecordForEntity->volatileData.distToTarget;
  v11 = (RecordForEntity->volatileData.targetFlags.flags & 0x80) != 0;
  idBotMoveState::MoveToGoalCmd_SetStance(this: (idGuiListBox *)bot->moveState, maxRows: 3);
  if ( distToTarget > 768.0 )
  {
    v12 = 4;
    v9 = 1;
LABEL_10:
    idBotMoveState::MoveToGoalCmd_SetStance(this: (idGuiListBox *)bot->moveState, maxRows: v12);
    goto LABEL_11;
  }
  if ( distToTarget < 512.0 && v11 )
  {
    v12 = 1;
    bot->moveState->idleStance = MOVE_STANCE_CROUCH;
    goto LABEL_10;
  }
LABEL_11:
  v13 = bot->goalTask.goalEnemy.spawnId.value;
  v14 = gameLocal;
  if ( gameLocal->spawnIds.ptr[v13 & 0x1FFF] == v13 >> 13 )
  {
    v15 = gameLocal->entities.ptr[v13 & 0x1FFF];
    if ( v15 != nullptr )
    {
      v16 = idEntity::CastTo(c: v15);
      if ( v16 != nullptr && v9 == 0 )
      {
        idBotAimState::AddAimRequestEntity(
          this: bot->aimState,
          entity: v16,
          priority: AIM_PRIORITY_BEHAVIOR_DRIVEN,
          userName: "Escort_MOVING_LookAtEnemy",
          aimPoint: AIMPOINT_BEST,
          aimTimeInSeconds: -1.0);
        idBotWeaponState::AddWeaponRequest(
          this: bot->weaponState,
          priority: WEAPON_PRIORITY_BEHAVIOR_DRIVEN,
          weapSlot: WEAPON_SLOT_PRIMARY,
          userName: "Escort_MOVING_GunForEnemy",
          fireMode: WEAPON_FIRE_MODE_WHEN_READY);
        return 1;
      }
      v14 = gameLocal;
    }
  }
  if ( this->avoidingMate )
  {
    v18 = bot->goalTask.goalEntity.spawnId.value;
    if ( v14->spawnIds.ptr[v18 & 0x1FFF] == v18 >> 13 && (v19 = v14->entities.ptr[v18 & 0x1FFF]) != nullptr )
      v20 = idEntity::CastTo(c: v19);
    else
      v20 = nullptr;
    idBotAimState::AddAimRequestEntity(
      this: bot->aimState,
      entity: v20,
      priority: AIM_PRIORITY_BEHAVIOR_DRIVEN,
      userName: "Escort_MOVING_LookAtMate",
      aimPoint: AIMPOINT_HEAD,
      aimTimeInSeconds: -1.0);
  }
  return 1;
}


// ========================================================================
// ?Think@idBotBehaviorEscort@@UAA?AW4behaviorStatus_t@@PAVidBot@@H@Z
// EA  : 0x82B38570
// RVA : 0x00B38570
// PDB : w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_escort.cpp
// ========================================================================

int __fastcall idBotBehaviorEscort::Think(idBotBehaviorEscort *this, idBot *bot, int curTime)
{
  int value; // r10
  idEntity *v7; // r3
  idEntity *v8; // r3
  int updated; // r3
  int v10; // r30

  value = bot->goalTask.goalEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && (v8 = idEntity::CastTo(c: v7)) != nullptr
    && !v8->IsDead(this: v8) )
  {
    if ( this->reachedMate )
      updated = idBotBehaviorEscort::Update_ReachedTeammateBehavior(this, bot, curTime);
    else
      updated = idBotBehaviorEscort::Update_MovingToTeammateBehavior(this, bot, curTime);
    v10 = updated;
    idBotMoveState::MoveToGoalCmd_SetTolerance(this: bot->moveState, tolerance: this->currentMoveTolerance);
    return v10;
  }
  else
  {
    idBotGoal::Bot_ResetGoal(this: &bot->goalTask);
    return 0;
  }
}

