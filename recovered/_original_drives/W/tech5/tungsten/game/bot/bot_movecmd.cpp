
// ========================================================================
// ??1idBotMoveCommand@@UAA@XZ
// EA  : 0x82B41430
// RVA : 0x00B41430
// PDB : w:\tech5\tungsten\game\bot\bot_movecmd.cpp
// ========================================================================

void __fastcall idBotMoveCommand::~idBotMoveCommand(idBotMoveCommand *this)
{
  this->__vftable = (idBotMoveCommand_vtbl *)&idBotMoveCommand::`vftable';
}


// ========================================================================
// ?GetMoveGoalType@idBotMoveCommand@@QBA?AW4botMoveGoalType_t@@XZ
// EA  : 0x82B41440
// RVA : 0x00B41440
// PDB : w:\tech5\tungsten\game\bot\bot_movecmd.cpp
// ========================================================================

botMoveGoalType_t __fastcall idBotMoveCommand::GetMoveGoalType(idBotMoveCommand *this)
{
  if ( this->moveSubGoal.active )
    return MOVE_GOAL_TYPE_POSITION;
  else
    return this->moveGoalType;
}


// ========================================================================
// ?GetMoveStopAtPoint@idBotMoveCommand@@QBA_NXZ
// EA  : 0x82B41460
// RVA : 0x00B41460
// PDB : w:\tech5\tungsten\game\bot\bot_movecmd.cpp
// ========================================================================

BOOL __fastcall idBotMoveCommand::GetMoveStopAtPoint(idBotMoveCommand *this)
{
  if ( this->moveSubGoal.active )
    return this->moveSubGoal.stopAtPoint;
  else
    return this->moveStopAtPoint;
}


// ========================================================================
// ?ReachedMoveGoalCallBack@idBotMoveCommand@@QAAXPAVidBot@@H@Z
// EA  : 0x82B41480
// RVA : 0x00B41480
// PDB : w:\tech5\tungsten\game\bot\bot_movecmd.cpp
// ========================================================================

void __fastcall idBotMoveCommand::ReachedMoveGoalCallBack(idBotMoveCommand *this, idBot *bot, const int curTime)
{
  idBehaviorAction *moveCallBackState; // r11

  moveCallBackState = this->moveCallBackState;
  if ( moveCallBackState != nullptr )
    ((void (*)(void))moveCallBackState->MoveGoal_Reached_CallBack)();
}


// ========================================================================
// ?ErroredMoveGoalCallBack@idBotMoveCommand@@QAAXPAVidBot@@HW4botMoveStatus_t@@@Z
// EA  : 0x82B414A8
// RVA : 0x00B414A8
// PDB : w:\tech5\tungsten\game\bot\bot_movecmd.cpp
// ========================================================================

void __fastcall idBotMoveCommand::ErroredMoveGoalCallBack(
        idBotMoveCommand *this,
        idBot *bot,
        int curTime,
        botMoveStatus_t moveStatusCode)
{
  if ( this->moveCallBackState != nullptr )
  {
    if ( this->moveSubGoal.active )
      ((void (__fastcall *)(idBehaviorAction *))this->moveCallBackState->MoveSubGoal_Errored_CallBack)(a1: this->moveCallBackState);
    this->moveCallBackState->MoveGoal_Errored_CallBack(
      this: this->moveCallBackState,
      a2: bot,
      a3: curTime,
      a4: moveStatusCode);
  }
}


// ========================================================================
// ?StartedMoveGoalCallBack@idBotMoveCommand@@QAAXPAVidBot@@H@Z
// EA  : 0x82B41518
// RVA : 0x00B41518
// PDB : w:\tech5\tungsten\game\bot\bot_movecmd.cpp
// ========================================================================

void __fastcall idBotMoveCommand::StartedMoveGoalCallBack(idBotMoveCommand *this, idBot *bot, int curTime)
{
  if ( this->moveCallBackState != nullptr && !this->moveSubGoal.active )
    this->moveCallBackState->MoveGoal_Started_CallBack(this: this->moveCallBackState, a2: bot, a3: curTime);
}


// ========================================================================
// ?SetMoveGoalPosition@idBotMoveCommand@@QAAXABVidVec3@@@Z
// EA  : 0x82B415A0
// RVA : 0x00B415A0
// PDB : w:\tech5\tungsten\game\bot\bot_movecmd.cpp
// ========================================================================

void __fastcall idBotMoveCommand::SetMoveGoalPosition(idBotMoveCommand *this, const idVec3 *goalPos)
{
  this->moveGoalType = MOVE_GOAL_TYPE_POSITION;
  this->moveGoalPosition = *goalPos;
}


// ========================================================================
// ?SetMoveSubGoal@idBotMoveCommand@@QAAXABVidVec3@@M_N@Z
// EA  : 0x82B415C8
// RVA : 0x00B415C8
// PDB : w:\tech5\tungsten\game\bot\bot_movecmd.cpp
// ========================================================================

void __fastcall idBotMoveCommand::SetMoveSubGoal(
        idBotMoveCommand *this,
        const idVec3 *point,
        double radius,
        const bool stopAtPoint,
        bool a5)
{
  this->moveSubGoal.active = true;
  this->moveSubGoal.firstRun = true;
  this->moveSubGoal.point = *point;
  this->moveSubGoal.stopAtPoint = a5;
  this->moveSubGoal.radius = radius;
}


// ========================================================================
// ?SetMoveGoalEntity@idBotMoveCommand@@QAAXPBVidEntity@@W4botMoveEntityType_t@@@Z
// EA  : 0x82B415F8
// RVA : 0x00B415F8
// PDB : w:\tech5\tungsten\game\bot\bot_movecmd.cpp
// ========================================================================

void __fastcall idBotMoveCommand::SetMoveGoalEntity(
        idBotMoveCommand *this,
        const idEntity *goalEnt,
        botMoveEntityType_t entityType)
{
  this->moveGoalType = MOVE_GOAL_TYPE_ENTITY;
  if ( goalEnt != nullptr )
    this->moveGoalEntity.spawnId.value = (gameLocal->spawnIds.ptr[goalEnt->entityNumber] << 13) | goalEnt->entityNumber;
  else
    this->moveGoalEntity.spawnId.value = 0x1FFF;
  this->moveEntityType = entityType;
}


// ========================================================================
// ?UpdateMoveEntity@idBotMoveCommand@@QAAXPBVidBot@@@Z
// EA  : 0x82B41648
// RVA : 0x00B41648
// PDB : w:\tech5\tungsten\game\bot\bot_movecmd.cpp
// ========================================================================

void __fastcall idBotMoveCommand::UpdateMoveEntity(idBotMoveCommand *this, const idBot *bot)
{
  botMoveEntityType_t moveEntityType; // r11
  idGameLocal *v4; // r11
  idEntity *v5; // r3
  idEntity *v6; // r3

  moveEntityType = this->moveEntityType;
  if ( moveEntityType == MOVE_ENTITY_TYPE_ENEMY )
  {
    v4 = gameLocal;
    if ( gameLocal->spawnIds.ptr[bot->goalTask.goalEnemy.spawnId.value & 0x1FFF] == bot->goalTask.goalEnemy.spawnId.value >> 13 )
    {
      v5 = gameLocal->entities.ptr[bot->goalTask.goalEnemy.spawnId.value & 0x1FFF];
      if ( v5 != nullptr )
      {
LABEL_5:
        v6 = idEntity::CastTo(c: v5);
        v4 = gameLocal;
        goto LABEL_9;
      }
    }
  }
  else
  {
    if ( moveEntityType != MOVE_ENTITY_TYPE_GOAL_ENTITY )
      return;
    v4 = gameLocal;
    if ( gameLocal->spawnIds.ptr[bot->goalTask.goalEntity.spawnId.value & 0x1FFF] == bot->goalTask.goalEntity.spawnId.value >> 13 )
    {
      v5 = gameLocal->entities.ptr[bot->goalTask.goalEntity.spawnId.value & 0x1FFF];
      if ( v5 != nullptr )
        goto LABEL_5;
    }
  }
  v6 = nullptr;
LABEL_9:
  if ( v6 != nullptr )
    this->moveGoalEntity.spawnId.value = (v4->spawnIds.ptr[v6->entityNumber] << 13) | v6->entityNumber;
  else
    this->moveGoalEntity.spawnId.value = 0x1FFF;
}


// ========================================================================
// ??0idBotMoveCommand@@QAA@PBDPAVidBehaviorAction@@@Z
// EA  : 0x82B41750
// RVA : 0x00B41750
// PDB : w:\tech5\tungsten\game\bot\bot_movecmd.cpp
// ========================================================================

idBotMoveCommand *__fastcall idBotMoveCommand::idBotMoveCommand(
        idBotMoveCommand *this,
        const char *userName,
        idBehaviorAction *callBackState)
{
  this->__vftable = (idBotMoveCommand_vtbl *)&idBotMoveCommand::`vftable';
  this->moveFlags.flags = 0;
  this->moveGoalEntity.spawnId.value = 0x1FFF;
  this->moveSubGoal.radius = 0.0;
  *(_WORD *)&this->moveSubGoal.active = 1;
  this->moveSubGoal.firstRun = true;
  this->moveSubGoal.point = vec3_origin;
  this->moveTolerance = 0.0;
  this->moveUserName = nullptr;
  this->moveStopAtPoint = true;
  this->moveAreaNum = 0;
  this->moveFlags.flags = 0;
  this->moveStance = MOVE_STANCE_NONE;
  this->moveGoalType = MOVE_GOAL_TYPE_NONE;
  this->moveGoalPosition.z = 0.0;
  this->moveGoalPosition.y = 0.0;
  this->moveGoalPosition.x = 0.0;
  this->moveDestination.z = 0.0;
  this->moveDestination.y = 0.0;
  this->moveDestination.x = 0.0;
  this->moveGoalEntity.spawnId.value = 0x1FFF;
  this->moveCallBackState = nullptr;
  this->moveDestinationTolerance = 0.0;
  this->moveSubGoal.radius = 0.0;
  *(_WORD *)&this->moveSubGoal.active = 1;
  this->moveSubGoal.firstRun = true;
  this->moveSubGoal.point = vec3_origin;
  this->moveUserName = userName;
  this->moveCallBackState = callBackState;
  return this;
}


// ========================================================================
// ?UpdateMoveDestination@idBotMoveCommand@@QAA?AW4updateMoveDestCode_t@@PBVidAAS2@@PAVidBot@@@Z
// EA  : 0x82B41838
// RVA : 0x00B41838
// PDB : w:\tech5\tungsten\game\bot\bot_movecmd.cpp
// ========================================================================

int __fastcall idBotMoveCommand::UpdateMoveDestination(idBotMoveCommand *this, idBounds *aas, idBot *bot)
{
  unsigned __int64 v7; // r6
  const char *v8; // r7
  int v9; // r4
  idBehaviorAction *moveCallBackState; // r11
  int GameMs; // r3
  int v12; // r3
  botMoveGoalType_t moveGoalType; // r11
  idVec3 *p_moveDestination; // r28
  int moveAreaNum; // r4
  idEntity *v16; // r3
  idPhysics *Physics; // r3
  float *v18; // r3
  idActor *v19; // r3
  idActor *v20; // r3
  idActor *v21; // r27
  int AreaNum; // r3
  const idVec3 *LastValidAASOrigin; // r3
  idPLogScope v24; // [sp+58h] [-68h] BYREF
  _BYTE v25[96]; // [sp+60h] [-60h] BYREF

  if ( aas == nullptr )
    return 2;
  RD_EventBegin(name: "UpdateMoveDestination");
  LODWORD(v7) = "UpdateMoveDestination";
  HIDWORD(v7) = 2048;
  idPLogScope::idPLogScope(this: &v24, pl: &pLog, gMask: v7, label: v8);
  this->moveAreaNum = 0;
  (*(void (__fastcall **)(_BYTE *, idBounds *))(LODWORD(aas->b[0].x) + 24))(a1: v25, a2: aas);
  if ( this->moveSubGoal.active )
  {
    this->moveDestination.x = this->moveSubGoal.point.x;
    this->moveDestination.y = this->moveSubGoal.point.y;
    this->moveDestination.z = this->moveSubGoal.point.z;
    this->moveDestinationTolerance = this->moveSubGoal.radius;
    v9 = (*(int (__fastcall **)(idBounds *, _DWORD, idVec3 *, _BYTE *, int, int))(LODWORD(aas->b[0].x) + 32))(
           a1: aas,
           a2: 0,
           a3: &this->moveDestination,
           a4: v25,
           a5: 2,
           a6: 1);
    this->moveAreaNum = v9;
    if ( v9 == 0 )
      goto LABEL_27;
    (*(void (__fastcall **)(idBounds *, int, idVec3 *))(LODWORD(aas->b[0].x) + 48))(
      a1: aas,
      a2: v9,
      a3: &this->moveDestination);
    if ( !idBotMoveState::MoveToGoalCmd_IsReached(this: bot->moveState) )
    {
      if ( this->moveSubGoal.firstRun )
      {
        moveCallBackState = this->moveCallBackState;
        this->moveSubGoal.firstRun = false;
        if ( moveCallBackState != nullptr )
        {
          GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
          this->moveCallBackState->MoveSubGoal_Started_CallBack(this: this->moveCallBackState, a2: bot, a3: GameMs);
        }
      }
      goto LABEL_29;
    }
    if ( this->moveCallBackState != nullptr )
    {
      v12 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      this->moveCallBackState->MoveSubGoal_Reached_CallBack(this: this->moveCallBackState, a2: bot, a3: v12);
    }
    this->moveSubGoal.active = false;
    this->moveSubGoal.firstRun = false;
  }
  moveGoalType = this->moveGoalType;
  if ( moveGoalType == MOVE_GOAL_TYPE_ENTITY )
  {
    idBotMoveCommand::UpdateMoveEntity(this, bot);
    if ( gameLocal->spawnIds.ptr[this->moveGoalEntity.spawnId.value & 0x1FFF] != this->moveGoalEntity.spawnId.value >> 13 )
      goto LABEL_16;
    v16 = idEntityPtr<idEntity const>::operator->(this: (idEntityPtr<idEntity> *)&this->moveGoalEntity);
    Physics = idEntity::GetPhysics(this: v16);
    v18 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    p_moveDestination = &this->moveDestination;
    this->moveDestination.x = *v18;
    this->moveDestination.y = v18[1];
    this->moveDestination.z = v18[2];
    this->moveDestinationTolerance = this->moveTolerance;
    v19 = (idActor *)idEntityPtr<idEntity const>::operator->(this: (idEntityPtr<idEntity> *)&this->moveGoalEntity);
    v20 = idActor::CastTo(c: v19);
    v21 = v20;
    if ( v20 != nullptr )
    {
      AreaNum = idActor::GetAreaNum(this: v20, (const idAAS2 *)aas);
      this->moveAreaNum = AreaNum;
      if ( AreaNum == 0 && (this->moveFlags.flags & 8) == 0 )
      {
        this->moveAreaNum = idActor::GetLastValidAreaNum(this: v21, (const idAAS2 *)aas);
        LastValidAASOrigin = idActor::GetLastValidAASOrigin(this: v21, (const idAAS2 *)aas);
        p_moveDestination->x = LastValidAASOrigin->x;
        this->moveDestination.y = LastValidAASOrigin->y;
        this->moveDestination.z = LastValidAASOrigin->z;
      }
      moveAreaNum = this->moveAreaNum;
      if ( moveAreaNum == 0 )
        goto LABEL_27;
    }
    else
    {
      moveAreaNum = (*(int (__fastcall **)(idBounds *, _DWORD, idVec3 *, _BYTE *, int, int))(LODWORD(aas->b[0].x) + 32))(
                      a1: aas,
                      a2: 0,
                      a3: &this->moveDestination,
                      a4: v25,
                      a5: 2,
                      a6: 1);
      this->moveAreaNum = moveAreaNum;
      if ( moveAreaNum == 0 )
        goto LABEL_27;
    }
LABEL_28:
    (*(void (__fastcall **)(idBounds *, int, idVec3 *))(LODWORD(aas->b[0].x) + 48))(
      a1: aas,
      a2: moveAreaNum,
      a3: p_moveDestination);
    goto LABEL_29;
  }
  if ( moveGoalType == MOVE_GOAL_TYPE_POSITION )
  {
    this->moveDestination.x = bot->goalTask.goalPosition.x;
    p_moveDestination = &this->moveDestination;
    this->moveDestination.y = bot->goalTask.goalPosition.y;
    this->moveDestination.z = bot->goalTask.goalPosition.z;
    this->moveDestinationTolerance = this->moveTolerance;
    if ( ((LODWORD(this->moveDestination.z) | LODWORD(this->moveDestination.y) | LODWORD(this->moveDestination.x))
        & 0x7FFFFFFF) == 0 )
    {
LABEL_16:
      idPLogScope::~idPLogScope(this: &v24);
      RD_EventEnd();
      return 1;
    }
    moveAreaNum = (*(int (__fastcall **)(idBounds *, _DWORD, idVec3 *, _BYTE *, int, int))(LODWORD(aas->b[0].x) + 32))(
                    a1: aas,
                    a2: 0,
                    a3: &this->moveDestination,
                    a4: v25,
                    a5: 2,
                    a6: 1);
    this->moveAreaNum = moveAreaNum;
    if ( moveAreaNum == 0 )
    {
LABEL_27:
      idPLogScope::~idPLogScope(this: &v24);
      RD_EventEnd();
      return 3;
    }
    goto LABEL_28;
  }
LABEL_29:
  idPLogScope::~idPLogScope(this: &v24);
  RD_EventEnd();
  return 0;
}


// ========================================================================
// __unwind$489421
// EA  : 0x82B41C68
// RVA : 0x00B41C68
// PDB : w:\tech5\tungsten\game\bot\bot_movecmd.cpp
// ========================================================================

void _unwind_489421()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 192 + 120));
}


// ========================================================================
// __unwind$489422
// EA  : 0x82B41C90
// RVA : 0x00B41C90
// PDB : w:\tech5\tungsten\game\bot\bot_movecmd.cpp
// ========================================================================

void _unwind_489422()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 192 + 88));
}

