
// ========================================================================
// ??1idBotMoveState@@UAA@XZ
// EA  : 0x82B41CC8
// RVA : 0x00B41CC8
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

void __fastcall idBotMoveState::~idBotMoveState(idBotMoveState *this)
{
  this->__vftable = (idBotMoveState_vtbl *)&idBotMoveState::`vftable';
  this->pathInfo.aas = nullptr;
  this->owner = nullptr;
  obstacleAvoidanceManager->FreeObstacleBuffers(this: obstacleAvoidanceManager, a2: &this->pathInfo.obstacleAvoidance);
  idObstacleAvoidance::~idObstacleAvoidance(this: &this->pathInfo.obstacleAvoidance);
  idBotMoveCommand::~idBotMoveCommand(this: &this->currentMoveCmd);
}


// ========================================================================
// __unwind$489062
// EA  : 0x82B41D48
// RVA : 0x00B41D48
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

void _unwind_489062()
{
  int v0; // r12

  idBotMoveCommand::~idBotMoveCommand(this: (idBotMoveCommand *)(*(_DWORD *)(v0 - 112 + 132) + 8));
}


// ========================================================================
// __unwind$489063
// EA  : 0x82B41D74
// RVA : 0x00B41D74
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

void _unwind_489063()
{
  int v0; // r12

  idBotMoveState::botPathInfo_t::~botPathInfo_t(this: (idBotMoveState::botPathInfo_t *)(*(_DWORD *)(v0 - 112 + 132) + 120));
}


// ========================================================================
// ?MoveToGoalCmd_SetMoveSubGoal@idBotMoveState@@QAAXABVidVec3@@M_N@Z
// EA  : 0x82B41DA0
// RVA : 0x00B41DA0
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

void __fastcall idBotMoveState::MoveToGoalCmd_SetMoveSubGoal(
        idBotMoveState *this,
        const idVec3 *point,
        double radius,
        bool stopAtPoint,
        bool a5)
{
  idBotMoveCommand::SetMoveSubGoal(this: &this->currentMoveCmd, point, radius, stopAtPoint, a5);
}


// ========================================================================
// ?ReachedPosition@idBotMoveState@@QBA_NABVidVec3@@M@Z
// EA  : 0x82B41E08
// RVA : 0x00B41E08
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

int __fastcall idBotMoveState::ReachedPosition(idBotMoveState *this, const idVec3 *point, double tolerance)
{
  idPhysics *Physics; // r3
  float *v6; // r3
  double v7; // fp11
  double v8; // fp7
  double v10; // fp5
  double v12; // fp3
  double v13; // fp12
  double v14; // fp11
  int result; // r3
  double v16; // fp12

  Physics = idEntity::GetPhysics(this: this->owner->owner);
  v6 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v7 = (float)(point->y - v6[1]);
  v8 = (float)((float)((float)(point->x - *v6) * (float)(point->x - *v6)) + (float)((float)v7 * (float)v7));
  _FP6 = (float)((float)((float)((float)(point->x - *v6) * (float)(point->x - *v6)) + (float)((float)v7 * (float)v7))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  v10 = (float)((float)((float)((float)(point->x - *v6) * (float)(point->x - *v6)) + (float)((float)v7 * (float)v7))
              * (float)0.5);
  __asm { fsel      f4, f6, f7, f13 }
  v12 = __frsqrte(_FP4);
  v13 = (float)((float)-(float)((float)((float)((float)v12
                                              * (float)((float)((float)((float)(point->x - *v6) * (float)(point->x - *v6))
                                                              + (float)((float)v7 * (float)v7))
                                                      * (float)0.5))
                                      * (float)v12)
                              - (float)1.5)
              * (float)v12);
  v14 = (float)((float)((float)-(float)((float)((float)((float)v12
                                                      * (float)((float)((float)((float)(point->x - *v6)
                                                                              * (float)(point->x - *v6))
                                                                      + (float)((float)v7 * (float)v7))
                                                              * (float)0.5))
                                              * (float)v12)
                                      - (float)1.5)
                      * (float)v12)
              * (float)((float)((float)((float)(point->x - *v6) * (float)(point->x - *v6))
                              + (float)((float)v7 * (float)v7))
                      * (float)0.5));
  if ( (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v14 * (float)v13)
                                                                             - (float)1.5)
                                                             * (float)v13)
                                                     * (float)v10)
                                             * (float)((float)-(float)((float)((float)v14 * (float)v13) - (float)1.5)
                                                     * (float)v13))
                                     - (float)1.5)
                     * (float)((float)-(float)((float)((float)v14 * (float)v13) - (float)1.5) * (float)v13))
             * (float)v8) > tolerance )
    return 0;
  v16 = (float)(point->z - v6[2]);
  result = 1;
  if ( __fabs(v16) > pm_normalheight.valueFloat )
    return 0;
  return result;
}


// ========================================================================
// ?ReachedEntity@idBotMoveState@@QBA_NPBVidEntity@@ABVidVec3@@M@Z
// EA  : 0x82B41F08
// RVA : 0x00B41F08
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

int __fastcall idBotMoveState::ReachedEntity(
        idBotMoveState *this,
        idEntity *entity,
        const idVec3 *entityOrg,
        double tolerance)
{
  double v5; // fp31
  idPhysics *Physics; // r3
  idBounds *v9; // r3
  double InternalRadiusXY; // fp30
  idPhysics *v11; // r3
  idBounds *v12; // r3

  v5 = tolerance;
  if ( entity != nullptr )
  {
    Physics = idEntity::GetPhysics(this: this->owner->owner);
    v9 = (idBounds *)Physics->GetBounds(this: Physics, a2: -1);
    InternalRadiusXY = idBounds::GetInternalRadiusXY(this: v9);
    v11 = idEntity::GetPhysics(this: entity);
    v12 = (idBounds *)v11->GetBounds(this: v11, a2: -1);
    tolerance = (float)((float)(idBounds::GetInternalRadiusXY(this: v12) + (float)InternalRadiusXY) + (float)v5);
  }
  return idBotMoveState::ReachedPosition(this, point: entityOrg, tolerance);
}


// ========================================================================
// ?CanMoveInDir@idBotMoveState@@QBA_NW4botRelativeMoveDirection_t@@MPAVidVec3@@@Z
// EA  : 0x82B41FA8
// RVA : 0x00B41FA8
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

int __fastcall idBotMoveState::CanMoveInDir(
        idBotMoveState *this,
        unsigned int moveDirection,
        double moveUnits,
        idVec3 *endPoint,
        float *a5)
{
  const idAAS2 *aas; // r4
  const idVec3 *AASOrigin; // r29
  float *v12; // r11
  float v13; // r9
  float v14; // r8
  double v15; // fp10
  double v16; // fp9
  double v17; // fp7
  double v18; // fp6
  unsigned __int8 v19; // r31
  idPresentable *presentable; // r3
  float *v21; // r3
  float *v22; // r11
  float y; // r9
  float z; // r8
  double v25; // fp9
  double v26; // fp4
  double v27; // fp11
  double v28; // fp7
  double v29; // fp5
  double v30; // fp3
  double v31; // fp6
  double v32; // fp5
  double v33; // fp5
  double v34; // fp3
  double v35; // fp8
  double v36; // fp7
  double v37; // fp1
  double v38; // fp13
  double v39; // fp3
  double v40; // fp0
  int AreaNum; // r3
  const idAAS2 *v42; // r11
  double v43; // fp13
  double v44; // fp12
  float x; // [sp+60h] [-B0h] BYREF
  float v46; // [sp+64h] [-ACh]
  float v47; // [sp+68h] [-A8h]
  idVec3 v48; // [sp+70h] [-A0h] BYREF
  float v49; // [sp+80h] [-90h] BYREF
  float v50; // [sp+84h] [-8Ch]
  float v51; // [sp+88h] [-88h]
  float v52; // [sp+8Ch] [-84h]
  int v53; // [sp+90h] [-80h]
  int v54; // [sp+94h] [-7Ch]
  int v55; // [sp+98h] [-78h]
  float v56; // [sp+9Ch] [-74h]
  float v57; // [sp+A0h] [-70h]
  float v58; // [sp+A4h] [-6Ch]
  int v59; // [sp+A8h] [-68h]
  int v60; // [sp+ACh] [-64h]
  float v61; // [sp+B0h] [-60h]
  float v62; // [sp+B4h] [-5Ch]
  float v63; // [sp+B8h] [-58h]
  int v64; // [sp+BCh] [-54h]
  int v65; // [sp+C0h] [-50h]
  int v66; // [sp+C4h] [-4Ch]
  int v67; // [sp+C8h] [-48h]
  int v68; // [sp+CCh] [-44h]
  int v69; // [sp+D0h] [-40h]

  aas = this->pathInfo.aas;
  if ( aas == nullptr )
    return 0;
  AASOrigin = idActor::GetAASOrigin(this: this->owner->owner, aas);
  if ( !this->pathInfo.radarValid || moveDirection == 7 || moveUnits > 256.0 )
  {
    v19 = 0;
    presentable = this->owner->owner->presentable;
    if ( presentable != nullptr )
      v21 = (float *)presentable->GetPlayerInterface_2(this: presentable);
    else
      v21 = nullptr;
    v22 = v21 + 33;
    y = AASOrigin->y;
    z = AASOrigin->z;
    x = AASOrigin->x;
    v46 = y;
    v47 = z;
    if ( moveDirection <= 7 )
    {
      if ( moveDirection != 0 )
      {
        switch ( moveDirection )
        {
          case 1u:
            v37 = (float)((float)-moveUnits * (float)(v21[38] * (float)-1.0));
            v38 = (float)((float)((float)-moveUnits * (float)(v21[37] * (float)-1.0)) + v46);
            x = (float)((float)-moveUnits * (float)(v21[36] * (float)-1.0)) + x;
            v46 = v38;
            v47 = (float)v37 + v47;
            break;
          case 2u:
            v29 = (float)(v21[38] * (float)-moveUnits);
            v30 = (float)((float)(v21[37] * (float)-moveUnits) + v46);
            x = (float)((float)-moveUnits * v21[36]) + x;
            v46 = v30;
            v47 = (float)v29 + v47;
            break;
          case 3u:
            v39 = (float)((float)-moveUnits * (float)((float)(v21[35] * (float)-1.0) + (float)(v21[38] * (float)-1.0)));
            v40 = (float)((float)((float)-moveUnits
                                * (float)((float)(v21[34] * (float)-1.0) + (float)(v21[37] * (float)-1.0)))
                        + v46);
            x = (float)((float)-moveUnits * (float)((float)(v21[33] * (float)-1.0) + (float)(v21[36] * (float)-1.0)))
              + x;
            v46 = v40;
            v47 = (float)v39 + v47;
            break;
          case 4u:
            v27 = (float)((float)(v21[34] + (float)(v21[37] * (float)-1.0)) * (float)moveUnits);
            v28 = (float)((float)((float)(v21[35] + (float)(v21[38] * (float)-1.0)) * (float)moveUnits) + v47);
            x = (float)((float)(v21[33] + (float)(v21[36] * (float)-1.0)) * (float)moveUnits) + x;
            v47 = v28;
            v46 = (float)v27 + v46;
            break;
          case 5u:
            v35 = (float)((float)-moveUnits * (float)(v21[35] + (float)(v21[38] * (float)-1.0)));
            v36 = (float)((float)((float)-moveUnits * (float)((float)(v21[36] * (float)-1.0) + v21[33])) + x);
            v46 = (float)((float)-moveUnits * (float)(v21[34] + (float)(v21[37] * (float)-1.0))) + v46;
            x = v36;
            v47 = (float)v35 + v47;
            break;
          case 6u:
            v31 = (float)((float)((float)(v21[35] * (float)-1.0) + (float)(v21[38] * (float)-1.0)) * (float)moveUnits);
            v32 = (float)((float)((float)((float)(v21[33] * (float)-1.0) + (float)(v21[36] * (float)-1.0))
                                * (float)moveUnits)
                        + x);
            v46 = (float)((float)((float)(v21[34] * (float)-1.0) + (float)(v21[37] * (float)-1.0)) * (float)moveUnits)
                + v46;
            x = v32;
            v47 = (float)v31 + v47;
            break;
          default:
            v25 = (float)(v21[35] * (float)moveUnits);
            v26 = (float)(v46 + (float)(v21[34] * (float)moveUnits));
            x = (float)(*v22 * (float)moveUnits) + x;
            v46 = v26;
            v47 = v47 + (float)v25;
            break;
        }
      }
      else
      {
        v33 = (float)(v21[35] * (float)-moveUnits);
        v34 = (float)((float)(v21[34] * (float)-moveUnits) + v46);
        x = (float)((float)-moveUnits * *v22) + x;
        v46 = v34;
        v47 = (float)v33 + v47;
      }
    }
    AreaNum = idActor::GetAreaNum(this: this->owner->owner, aas: this->pathInfo.aas);
    v42 = this->pathInfo.aas;
    v54 = 0;
    v53 = 0;
    v55 = 0;
    v59 = 0;
    v60 = 0;
    v49 = 0.0;
    v64 = 0;
    v50 = 0.0;
    v65 = 0;
    v51 = 0.0;
    v66 = 0;
    v52 = 0.0;
    v67 = 0;
    v56 = 0.0;
    v68 = 0;
    v57 = 0.0;
    v69 = 0;
    v58 = 0.0;
    v61 = 0.0;
    v62 = 0.0;
    v63 = 0.0;
    ((void (__fastcall *)(const idAAS2 *, float *, const idVec3 *, int, float *, int, _DWORD, _DWORD))v42->TraceFloor)(
      a1: v42,
      a2: &v49,
      a3: AASOrigin,
      a4: AreaNum,
      a5: &x,
      a6: 40,
      a7: 0,
      a8: 0);
    if ( a5 != nullptr )
    {
      v43 = v51;
      v44 = v52;
      *a5 = v50;
      a5[1] = v43;
      a5[2] = v44;
    }
    if ( v49 >= 1.0 )
      return 1;
    return v19;
  }
  else
  {
    v12 = (float *)((char *)this + 16 * moveDirection);
    v13 = v12[268];
    v14 = v12[269];
    v48.x = v12[267];
    v48.y = v13;
    v48.z = v14;
    if ( idVec3::NormalizeFast(this: &v48) < moveUnits )
      return 0;
    if ( a5 != nullptr )
    {
      v15 = (float)(v48.y * (float)moveUnits);
      v16 = (float)(v48.z * (float)moveUnits);
      v17 = AASOrigin->y;
      v18 = AASOrigin->z;
      *a5 = AASOrigin->x + (float)(v48.x * (float)moveUnits);
      a5[1] = (float)v17 + (float)v15;
      a5[2] = (float)v18 + (float)v16;
    }
    return 1;
  }
}


// ========================================================================
// ?MoveToGoalCmd_SetStance@idBotMoveState@@QAAXW4botMoveStance_t@@@Z
// EA  : 0x82B424F0
// RVA : 0x00B424F0
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

idGuiListBox *__fastcall idBotMoveState::MoveToGoalCmd_SetStance(idGuiListBox *this, int maxRows)
{
  this->maxRowsToDisplay = maxRows;
  return this;
}


// ========================================================================
// ?MoveToGoalCmd_SetTolerance@idBotMoveState@@QAAXM@Z
// EA  : 0x82B424F8
// RVA : 0x00B424F8
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

void __fastcall idBotMoveState::MoveToGoalCmd_SetTolerance(idBotMoveState *this, double tolerance)
{
  this->currentMoveCmd.moveTolerance = tolerance;
}


// ========================================================================
// ?DidActionRow@idGuiListBox@@QAAAAV1@H@Z
// EA  : 0x82B42500
// RVA : 0x00B42500
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

idGuiListBox *__fastcall idGuiListBox::DidActionRow(idGuiListBox *this, int actionRow)
{
  this->didActionRow = actionRow;
  return this;
}


// ========================================================================
// ?UpdateMoveState_Normal@idBotMoveState@@AAAXXZ
// EA  : 0x82B42508
// RVA : 0x00B42508
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

void __fastcall idBotMoveState::UpdateMoveState_Normal(idBotMoveState *this)
{
  int flags; // r10
  idBot *owner; // r9
  idPresentable *presentable; // r3
  int v5; // r3
  float x; // r9
  float y; // r7
  idVec3 v8; // [sp+50h] [-20h] BYREF

  flags = this->currentMoveCmd.moveFlags.flags;
  owner = this->owner;
  this->currentMoveStance = this->currentMoveCmd.moveStance;
  this->currentMoveFlags.flags = flags;
  presentable = owner->owner->presentable;
  if ( presentable != nullptr )
    v5 = (int)presentable->GetPlayerInterface_2(this: presentable);
  else
    v5 = 0;
  x = this->pathInfo.nextMovePoint.x;
  y = this->pathInfo.nextMovePoint.y;
  v8.z = this->pathInfo.nextMovePoint.z;
  v8.x = x;
  v8.y = y;
  if ( (float)(v8.z - *(float *)(v5 + 46540)) < 100.0 )
    v8.z = *(float *)(v5 + 46540);
  idBotAimState::AddAimRequestPosition(
    this: this->owner->aimState,
    pos: &v8,
    priority: AIM_PRIORITY_LOOK_AT_MOVE_POINT,
    userName: "MoveState_Normal",
    aimTimeInSeconds: -1.0);
}


// ========================================================================
// ?UpdateDebugInfo@idBotMoveState@@AAAXXZ
// EA  : 0x82B425D0
// RVA : 0x00B425D0
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

void __fastcall idBotMoveState::UpdateDebugInfo(idBotMoveState *this)
{
  idRenderWorld *v2; // r3
  idBot *owner; // r8
  idRenderWorld *v4; // r31
  idPresentable *presentable; // r3
  float *v6; // r3
  double v7; // fp12
  double v8; // fp11
  float v9[6]; // [sp+60h] [-30h] BYREF

  if ( this->pathInfo.aas == nullptr )
  {
    v2 = gameLocal->GetRenderWorld(this: gameLocal);
    owner = this->owner;
    v4 = v2;
    presentable = owner->owner->presentable;
    if ( presentable != nullptr )
      v6 = (float *)presentable->GetPlayerInterface_2(this: presentable);
    else
      v6 = nullptr;
    v7 = v6[11634];
    v8 = (float)(v6[11635] + (float)16.0);
    v9[0] = v6[11633];
    v9[1] = v7;
    v9[2] = v8;
    ((void (__fastcall *)(idRenderWorld *, const char *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))v4->DebugText)(
      a1: v4,
      a2: "NO AAS",
      a3: v9,
      a4: v4->DebugText,
      a5: &idColor::colorRed,
      a6: 1,
      a7: 0,
      a8: 0,
      a9: 0.5);
  }
}


// ========================================================================
// ?UpdateIdleCmds@idBotMoveState@@AAAXAAVusercmd_t@@@Z
// EA  : 0x82B426C8
// RVA : 0x00B426C8
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

void __fastcall idBotMoveState::UpdateIdleCmds(idBotMoveState *this, usercmd_t *cmd)
{
  int flags; // r11

  if ( this->idleStance == MOVE_STANCE_CROUCH )
  {
    cmd->upmove = -127;
  }
  else if ( idActor::IsCrouching(this: this->owner->owner) )
  {
    cmd->upmove = 127;
  }
  flags = this->currentMoveFlags.flags;
  if ( (flags & 1) != 0 )
  {
    if ( bot_allowJumping.valueInteger != 0 )
      cmd->upmove = 127;
    this->currentMoveFlags.flags &= ~1u;
  }
  else if ( (flags & 2) != 0 )
  {
    if ( bot_allowJumping.valueInteger != 0 )
      cmd->upmove = 127;
    cmd->rightmove = 127;
    this->currentMoveFlags.flags &= ~2u;
  }
  else if ( (flags & 4) != 0 )
  {
    if ( bot_allowJumping.valueInteger != 0 )
      cmd->upmove = 127;
    cmd->rightmove = -127;
    this->currentMoveFlags.flags &= ~4u;
  }
}


// ========================================================================
// ??0idBotMoveState@@QAA@XZ
// EA  : 0x82B428F8
// RVA : 0x00B428F8
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

idBotMoveState *__fastcall idBotMoveState::idBotMoveState(idBotMoveState *this)
{
  const idAAS2 *v2; // r3

  this->owner = nullptr;
  this->__vftable = (idBotMoveState_vtbl *)&idBotMoveState::`vftable';
  idBotMoveCommand::idBotMoveCommand(this: &this->currentMoveCmd, userName: "Default", callBackState: nullptr);
  this->currentMoveFlags.flags = 0;
  this->idleStance = MOVE_STANCE_RUN;
  this->currentMoveStance = MOVE_STANCE_RUN;
  this->currentMoveStatus = MOVE_STATUS_NONE;
  this->currentMoveState = MOVE_STATE_NONE;
  idBotMoveState::botPathInfo_t::botPathInfo_t(this: &this->pathInfo);
  this->currentMoveFlags.flags = 0;
  v2 = idGameLocal::AASForType(this: gameLocal, type: AAS_MONSTER32);
  this->pathInfo.aas = v2;
  if ( bot_alwaysLoad.valueInteger != 0 && v2 == nullptr )
    this->pathInfo.aas = idGameLocal::AASForType(this: gameLocal, type: AAS_MONSTER48);
  return this;
}


// ========================================================================
// __unwind$490950_1
// EA  : 0x82B429B8
// RVA : 0x00B429B8
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

void _unwind_490950_1()
{
  int v0; // r12

  idBotMoveCommand::~idBotMoveCommand(this: (idBotMoveCommand *)(*(_DWORD *)(v0 - 128 + 148) + 8));
}


// ========================================================================
// __unwind$490951_1
// EA  : 0x82B429E4
// RVA : 0x00B429E4
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

void _unwind_490951_1()
{
  int v0; // r12

  idBotMoveState::botPathInfo_t::~botPathInfo_t(this: (idBotMoveState::botPathInfo_t *)(*(_DWORD *)(v0 - 128 + 148) + 120));
}


// ========================================================================
// ?StartMoveToGoal@idBotMoveState@@QAAXAAVidBotMoveCommand@@@Z
// EA  : 0x82B42A10
// RVA : 0x00B42A10
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

void __fastcall idBotMoveState::StartMoveToGoal(idBotMoveState *this, idBotMoveCommand *moveCmd)
{
  this->currentMoveStatus = MOVE_STATUS_PENDING;
  idBotMoveCommand::operator=(this: &this->currentMoveCmd, src: moveCmd);
}


// ========================================================================
// ?UpdateBotGUI@idBotMoveState@@QBAXAAVidGuiListBox@@@Z
// EA  : 0x82B42A28
// RVA : 0x00B42A28
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

void __fastcall idBotMoveState::UpdateBotGUI(idBotMoveState *this, idGuiListBox *infoList)
{
  int AreaNum; // r28
  idGuiListBox *v5; // r3
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r6
  idGuiListBox *v9; // r3
  __int64 v10; // r10
  __int64 v11; // r6
  __int64 v12; // r8
  int moveAreaNum; // r28
  idGuiListBox *v14; // r3
  __int64 v15; // r8
  __int64 v16; // r10
  __int64 v17; // r6
  idGuiListBox *v18; // r3
  __int64 v19; // r6
  __int64 v20; // r10
  __int64 v21; // r8
  const char *v22; // r27
  idGuiListBox *v23; // r3
  __int64 v24; // r8
  __int64 v25; // r10
  __int64 v26; // r6
  idGuiListBox *v27; // r3
  __int64 v28; // r6
  __int64 v29; // r10
  __int64 v30; // r8
  idTypeInfoTools *v31; // r3
  const enumTypeInfo_t *EnumInfo; // r3
  const enumValueInfo_t *values; // r9
  int v34; // r10
  const enumValueInfo_t *v35; // r11
  char *data; // r27
  idGuiListBox *v37; // r3
  __int64 v38; // r10
  __int64 v39; // r8
  __int64 v40; // r6
  idGuiListBox *v41; // r3
  __int64 v42; // r6
  __int64 v43; // r10
  __int64 v44; // r8
  const char *moveUserName; // r30
  idGuiListBox *v46; // r3
  __int64 v47; // r10
  __int64 v48; // r8
  __int64 v49; // r6
  idGuiListBox *v50; // r3
  __int64 v51; // r6
  __int64 v52; // r10
  __int64 v53; // r8
  idStr v54[2]; // [sp+50h] [-50h] BYREF

  AreaNum = idActor::GetAreaNum(this: this->owner->owner, aas: this->pathInfo.aas);
  v5 = idGuiListBox::Row(this: infoList);
  LODWORD(v6) = &off_822B0000;
  v9 = idGuiListBox::Printf(this: v5, fmt: "AreaNum: ", a3: v8, a4: v7, a5: v6);
  HIDWORD(v10) = 0x82000000;
  HIDWORD(v11) = AreaNum;
  idGuiListBox::Printf(this: v9, fmt: "%d", a3: v11, a4: v12, a5: v10);
  moveAreaNum = this->currentMoveCmd.moveAreaNum;
  v14 = idGuiListBox::Row(this: infoList);
  LODWORD(v15) = &off_822B0000;
  v18 = idGuiListBox::Printf(this: v14, fmt: "Move Goal AreaNum: ", a3: v17, a4: v15, a5: v16);
  HIDWORD(v19) = moveAreaNum;
  idGuiListBox::Printf(this: v18, fmt: "%d", a3: v19, a4: v21, a5: v20);
  v22 = idVec3::ToString(this: (idAngles *)&this->currentMoveCmd.moveDestination, precision: 1);
  v23 = idGuiListBox::Row(this: infoList);
  HIDWORD(v24) = &off_822B0000;
  v27 = idGuiListBox::Printf(this: v23, fmt: "Move Goal Pos: ", a3: v26, a4: v24, a5: v25);
  HIDWORD(v28) = v22;
  idGuiListBox::Printf(this: v27, fmt: "%s", a3: v28, a4: v30, a5: v29);
  idStr::idStr(this: v54, text: "<Unknown>");
  v31 = (idTypeInfoTools *)gameLocal->GetTypeInfoTools(this: gameLocal);
  EnumInfo = idTypeInfoTools::FindEnumInfo(this: v31, typeName: "botMoveStatus_t");
  if ( EnumInfo != nullptr )
  {
    values = EnumInfo->values;
    v34 = 0;
    if ( values->name != nullptr )
    {
      v35 = EnumInfo->values;
      while ( v35->value != this->currentMoveStatus )
      {
        v35 = &values[++v34];
        if ( v35->name == nullptr )
          goto LABEL_8;
      }
      idStr::operator=(this: v54, text: v35->name);
    }
  }
LABEL_8:
  data = v54[0].data;
  v37 = idGuiListBox::Row(this: infoList);
  v41 = idGuiListBox::Printf(this: v37, fmt: "Move Status: ", a3: v40, a4: v39, a5: v38);
  HIDWORD(v42) = data;
  idGuiListBox::Printf(this: v41, fmt: "%s", a3: v42, a4: v44, a5: v43);
  moveUserName = this->currentMoveCmd.moveUserName;
  v46 = idGuiListBox::Row(this: infoList);
  LODWORD(v47) = &off_822B0000;
  v50 = idGuiListBox::Printf(this: v46, fmt: "Move User: ", a3: v49, a4: v48, a5: v47);
  HIDWORD(v51) = moveUserName;
  idGuiListBox::Printf(this: v50, fmt: "%s", a3: v51, a4: v53, a5: v52);
  idStr::FreeData(this: v54);
}


// ========================================================================
// __unwind$491052
// EA  : 0x82B42BBC
// RVA : 0x00B42BBC
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

void _unwind_491052()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?ReachedMoveGoal@idBotMoveState@@ABA_NXZ
// EA  : 0x82B42BE8
// RVA : 0x00B42BE8
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

int __fastcall idBotMoveState::ReachedMoveGoal(idBotMoveState *this)
{
  int value; // r10
  double moveDestinationTolerance; // fp31
  idEntity *v5; // r3
  idEntity *v6; // r3

  if ( bot_freezeMovement.valueInteger == 2 )
    return 1;
  if ( idBotMoveCommand::GetMoveGoalType(this: &this->currentMoveCmd) == MOVE_GOAL_TYPE_ENTITY )
  {
    value = this->currentMoveCmd.moveGoalEntity.spawnId.value;
    moveDestinationTolerance = this->currentMoveCmd.moveDestinationTolerance;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v5 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v6 = idEntity::CastTo(c: v5);
      return idBotMoveState::ReachedEntity(
               this,
               entity: v6,
               entityOrg: &this->currentMoveCmd.moveDestination,
               tolerance: moveDestinationTolerance);
    }
    else
    {
      return idBotMoveState::ReachedEntity(
               this,
               entity: nullptr,
               entityOrg: &this->currentMoveCmd.moveDestination,
               tolerance: this->currentMoveCmd.moveDestinationTolerance);
    }
  }
  else if ( idBotMoveCommand::GetMoveGoalType(this: &this->currentMoveCmd) == MOVE_GOAL_TYPE_POSITION )
  {
    return idBotMoveState::ReachedPosition(
             this,
             point: &this->currentMoveCmd.moveDestination,
             tolerance: this->currentMoveCmd.moveDestinationTolerance);
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?MoveToGoalCmd_IsReached@idBotMoveState@@QBA_NXZ
// EA  : 0x82B42CF0
// RVA : 0x00B42CF0
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

// attributes: thunk
int __fastcall idBotMoveState::MoveToGoalCmd_IsReached(idBotMoveState *this)
{
  return idBotMoveState::ReachedMoveGoal(this);
}


// ========================================================================
// ?UpdateObstacleAvoidance@idBotMoveState@@AAA_NH@Z
// EA  : 0x82B42D00
// RVA : 0x00B42D00
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

int __fastcall idBotMoveState::UpdateObstacleAvoidance(idBotMoveState *this, int startAreaNum)
{
  unsigned __int64 v5; // r6
  const char *v6; // r7
  obstacleVertex_t *VertexArray; // r28
  obstacleEdge_t *EdgeArray; // r26
  int MaxEdges; // r3
  const idAAS2 *aas; // r11
  idPhysics *Physics; // r23
  float *v12; // r3
  double v13; // fp31
  double v14; // fp30
  double v15; // fp29
  float *v16; // r3
  double v17; // fp5
  double v18; // fp4
  double v19; // fp30
  double v20; // fp3
  double v21; // fp29
  double v22; // fp31
  const idAAS2Settings *v23; // r3
  idEntityPtr<idEntity> *p_goalEntity; // r9
  idGameLocal *v25; // r11
  double v26; // fp30
  idEntity *v27; // r3
  idEntity *v28; // r3
  idEntity *v29; // r20
  idEntityPtr<idEntity> *p_goalEnemy; // r9
  idEntity *v31; // r3
  idEntity *v32; // r3
  idEntity *v33; // r21
  int v34; // r22
  _BYTE *v35; // r24
  int v36; // r28
  int v37; // r10
  const idEntity *v38; // r29
  idPlayer *v39; // r3
  idPlayer *v40; // r26
  float *v41; // r3
  double v42; // fp13
  double v43; // fp12
  const idSpawnId **SpawnId; // r3
  int GameMs; // r29
  int GameMsPerFrame; // r28
  idPhysics *v47; // r3
  const idBounds *v48; // r26
  idVec3 *p_gravityDir; // r25
  idPresentable *presentable; // r3
  float *v51; // r3
  BOOL PathAroundObstacles; // r28
  idPLog *pLog; // r29
  idPLog::logEntry_t *v54; // r30
  int v55; // r3
  __int64 totalTicks; // r11
  __int64 v57; // r9
  obstacleTraceSet_t *v58; // [sp+8h] [-1128h]
  int v59; // [sp+Ch] [-1124h]
  int v60; // [sp+10h] [-1120h]
  int v61; // [sp+14h] [-111Ch]
  int v62; // [sp+18h] [-1118h]
  int v63; // [sp+1Ch] [-1114h]
  int v64; // [sp+20h] [-1110h]
  int v65; // [sp+24h] [-110Ch]
  int v66; // [sp+28h] [-1108h]
  int v67; // [sp+2Ch] [-1104h]
  int v68; // [sp+30h] [-1100h]
  int v69; // [sp+34h] [-10FCh]
  int v70; // [sp+38h] [-10F8h]
  int v71; // [sp+3Ch] [-10F4h]
  int v72; // [sp+40h] [-10F0h]
  int v73; // [sp+44h] [-10ECh]
  int v74; // [sp+48h] [-10E8h]
  int v75; // [sp+4Ch] [-10E4h]
  int v76; // [sp+50h] [-10E0h]
  int v77; // [sp+58h] [-10D8h]
  int v78; // [sp+60h] [-10D0h]
  int v79; // [sp+68h] [-10C8h]
  idEntityPtr<idEntity> *v80; // [sp+70h] [-10C0h] BYREF
  int v81; // [sp+74h] [-10BCh] BYREF
  idVec3 *p_radarForward; // [sp+78h] [-10B8h] BYREF
  int v83; // [sp+7Ch] [-10B4h] BYREF
  int MaxVertices; // [sp+80h] [-10B0h] BYREF
  float v85; // [sp+84h] [-10ACh] BYREF
  idPLogScope v86; // [sp+88h] [-10A8h] BYREF
  idVec3 v87; // [sp+90h] [-10A0h] BYREF
  _BYTE v88[144]; // [sp+A0h] [-1090h] BYREF

  if ( bot_useObstacleAvoidance.valueInteger == 0 )
    return 1;
  RD_EventBegin(name: "Update_ObstacleAvoidance");
  LODWORD(v5) = "Update_ObstacleAvoidance";
  HIDWORD(v5) = 3072;
  idPLogScope::idPLogScope(this: &v86, pl: &::pLog, gMask: v5, label: v6);
  idObstacleAvoidance::AllocBuffers(this: &this->pathInfo.obstacleAvoidance);
  v81 = 1024;
  VertexArray = idObstacleAvoidance::GetVertexArray(this: &this->pathInfo.obstacleAvoidance);
  EdgeArray = idObstacleAvoidance::GetEdgeArray(this: &this->pathInfo.obstacleAvoidance);
  MaxVertices = idObstacleAvoidance::GetMaxVertices(this: &this->pathInfo.obstacleAvoidance);
  MaxEdges = idObstacleAvoidance::GetMaxEdges(this: &this->pathInfo.obstacleAvoidance);
  aas = this->pathInfo.aas;
  v83 = MaxEdges;
  ((void (__fastcall *)(const idAAS2 *, const int, int, obstacleVertex_t *, int *, obstacleEdge_t *, int *, _BYTE *))aas->GetObstaclePVSObstacles)(
    a1: aas,
    a2: startAreaNum,
    a3: 515,
    a4: VertexArray,
    a5: &MaxVertices,
    a6: EdgeArray,
    a7: &v83,
    a8: v88);
  idObstacleAvoidance::SetNumVertices(this: &this->pathInfo.obstacleAvoidance, num: MaxVertices);
  idObstacleAvoidance::SetNumEdges(this: &this->pathInfo.obstacleAvoidance, num: v83);
  Physics = idEntity::GetPhysics(this: this->owner->owner);
  v12 = (float *)Physics->GetGravityNormal(this: Physics);
  v13 = -v12[2];
  v14 = -v12[1];
  v15 = -*v12;
  v16 = (float *)Physics->GetAbsBounds(this: Physics, a2: -1);
  v17 = __fabs((float)((float)(v16[5] - (float)((float)(v16[2] + v16[5]) * (float)0.5)) * (float)v13));
  v18 = __fabs((float)((float)(v16[4] - (float)((float)(v16[1] + v16[4]) * (float)0.5)) * (float)v14));
  v19 = (float)((float)((float)((float)(v16[2] + v16[5]) * (float)0.5) * (float)v13)
              + (float)((float)((float)((float)(v16[3] + *v16) * (float)0.5) * (float)v15)
                      + (float)((float)((float)(v16[1] + v16[4]) * (float)0.5) * (float)v14)));
  v20 = __fabs((float)((float)(v16[3] - (float)((float)(v16[3] + *v16) * (float)0.5)) * (float)v15));
  v21 = (float)((float)((float)v17 + (float)v18) + (float)v20);
  v22 = (float)((float)((float)((float)v17 + (float)v18) + (float)v20) + (float)v19);
  v23 = this->pathInfo.aas->GetSettings(this: this->pathInfo.aas);
  p_goalEntity = &this->owner->goalTask.goalEntity;
  v25 = gameLocal;
  v26 = (float)(v23->maxStepHeight + (float)((float)v19 - (float)v21));
  v80 = p_goalEntity;
  if ( gameLocal->spawnIds.ptr[p_goalEntity->spawnId.value & 0x1FFF] == p_goalEntity->spawnId.value >> 13
    && (v27 = gameLocal->entities.ptr[p_goalEntity->spawnId.value & 0x1FFF]) != nullptr )
  {
    v28 = idEntity::CastTo(c: v27);
    v25 = gameLocal;
    v29 = v28;
  }
  else
  {
    v29 = nullptr;
  }
  p_goalEnemy = &this->owner->goalTask.goalEnemy;
  v80 = p_goalEnemy;
  if ( v25->spawnIds.ptr[p_goalEnemy->spawnId.value & 0x1FFF] == p_goalEnemy->spawnId.value >> 13
    && (v31 = v25->entities.ptr[p_goalEnemy->spawnId.value & 0x1FFF]) != nullptr )
  {
    v32 = idEntity::CastTo(c: v31);
    v25 = gameLocal;
    v33 = v32;
  }
  else
  {
    v33 = nullptr;
  }
  v34 = 0;
  v35 = v88;
  do
  {
    v36 = *(_DWORD *)v35;
    v37 = *(_DWORD *)(*(_DWORD *)v35 + 12) + 21563;
    v38 = *((const idEntity **)&v25->__vftable + v37);
    if ( v38 != nullptr && v38 != v29 && v38 != v33 )
    {
      v39 = idPlayer::CastTo(c: *((idPlayer **)&v25->__vftable + v37));
      v40 = v39;
      if ( v39 != nullptr && v39 != this->owner->owner && !v39->IsDead(this: v39) && !idPlayer::GetNoclip(this: v40) )
      {
        v41 = (float *)Physics->GetGravityNormal(this: Physics);
        v42 = v41[1];
        v43 = -v41[2];
        v87.x = -*v41;
        v87.z = v43;
        v87.y = -v42;
        idBounds::AxisProjection(this: (idBounds *)(v36 + 104), dir: &v87, min: (float *)&v80, max: &v85);
        if ( v85 >= v26 && *(float *)&v80 <= v22 )
        {
          SpawnId = (const idSpawnId **)idGameLocal::GetSpawnId(
                                          this: (idGameLocal *)&p_radarForward,
                                          result: (idSpawnId *)gameLocal,
                                          ent: v38);
          idObstacleAvoidance::AddObstacle(
            this: &this->pathInfo.obstacleAvoidance,
            bounds: (const idBounds *)(v36 + 80),
            origin: (const idVec3 *)(v36 + 32),
            axis: (const idMat3 *)(v36 + 44),
            id: *SpawnId,
            soft: v38->clipModelInfo.softObstacle);
        }
      }
      v25 = gameLocal;
    }
    ++v34;
    v35 += 4;
  }
  while ( v34 < v81 );
  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  GameMsPerFrame = idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  v47 = idEntity::GetPhysics(this: this->owner->owner);
  v48 = v47->GetBounds(this: v47, a2: -1);
  p_gravityDir = &this->pathInfo.aas->GetSettings(this: this->pathInfo.aas)->gravityDir;
  presentable = this->owner->owner->presentable;
  if ( presentable != nullptr )
    v51 = (float *)presentable->GetPlayerInterface_2(this: presentable);
  else
    v51 = nullptr;
  this->pathInfo.obstacleAvoidanceInfo.useRadarForward = true;
  this->pathInfo.obstacleAvoidanceInfo.radarForward.x = v51[33];
  this->pathInfo.obstacleAvoidanceInfo.radarForward.y = v51[34];
  this->pathInfo.obstacleAvoidanceInfo.radarForward.z = v51[35];
  p_radarForward = &this->pathInfo.obstacleAvoidanceInfo.radarForward;
  PathAroundObstacles = idObstacleAvoidance::FindPathAroundObstacles(
                          this: &this->pathInfo.obstacleAvoidance,
                          path: &this->pathInfo.obstacleAvoidanceInfo,
                          time: GameMs,
                          gameMsPerFrame: GameMsPerFrame,
                          bbox: v48,
                          gravity: p_gravityDir,
                          obstacleRadius: 1024.0,
                          frameMoveDist: 16.0,
                          cornerCircleRadius: 24.0,
                          flags: 284,
                          route: nullptr,
                          traceSet: v58,
                          a13: v59,
                          a14: v60,
                          a15: v61,
                          a16: v62,
                          a17: v63,
                          a18: v64,
                          a19: v65,
                          a20: v66,
                          a21: v67,
                          a22: v68,
                          a23: v69,
                          a24: v70,
                          a25: v71,
                          a26: v72,
                          a27: v73,
                          a28: v74,
                          a29: v75,
                          a30: v76,
                          a31: (int)&v81,
                          a32: v77,
                          a33: 284,
                          a34: v78,
                          a35: &this->pathInfo.path.obstacleRoute,
                          a36: v79,
                          a37: nullptr);
  if ( v86.logIndex >= 0 )
  {
    pLog = v86.pLog;
    v54 = &v86.pLog->logEntries.list[v86.logIndex];
    v55 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v54->totalTicks;
    HIDWORD(totalTicks) = v54->parent;
    LODWORD(v57) = v55 - totalTicks;
    v54->totalTicks = v57;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
  return PathAroundObstacles;
}


// ========================================================================
// __unwind$491241
// EA  : 0x82B43264
// RVA : 0x00B43264
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

void _unwind_491241()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 4400 + 4256));
}


// ========================================================================
// __unwind$491242
// EA  : 0x82B4328C
// RVA : 0x00B4328C
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

void _unwind_491242()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 4400 + 136));
}


// ========================================================================
// ?UpdateAASRadar@idBotMoveState@@AAAXXZ
// EA  : 0x82B432B8
// RVA : 0x00B432B8
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

void __fastcall idBotMoveState::UpdateAASRadar(idBotMoveState *this)
{
  int AreaNum; // r29
  idPhysics *Physics; // r3
  float *v4; // r30
  idPresentable *presentable; // r3
  float *v6; // r11
  double v7; // fp9
  double v8; // fp8
  double v9; // fp5

  AreaNum = idActor::GetAreaNum(this: this->owner->owner, aas: this->pathInfo.aas);
  if ( AreaNum == 0 )
    AreaNum = idActor::GetLastValidAreaNum(this: this->owner->owner, aas: this->pathInfo.aas);
  Physics = idEntity::GetPhysics(this: this->owner->owner);
  v4 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  presentable = this->owner->owner->presentable;
  if ( presentable != nullptr )
    v6 = (float *)presentable->GetPlayerInterface_2(this: presentable);
  else
    v6 = nullptr;
  this->pathInfo.path.obstacleRoute.areas[0].start.x = *v4;
  this->pathInfo.path.obstacleRoute.areas[0].start.y = v4[1];
  this->pathInfo.path.obstacleRoute.areas[0].start.z = v4[2];
  v7 = v4[1];
  v8 = v6[34];
  v9 = (float)(v4[2] + v6[35]);
  this->pathInfo.path.obstacleRoute.areas[0].end.x = *v4 + v6[33];
  this->pathInfo.path.obstacleRoute.areas[0].end.y = (float)v7 + (float)v8;
  this->pathInfo.path.obstacleRoute.areas[0].end.z = v9;
  this->pathInfo.path.obstacleRoute.numAreas = 1;
  this->pathInfo.obstacleAvoidanceInfo.useRadarForward = true;
  this->pathInfo.obstacleAvoidanceInfo.radarForward.x = v6[33];
  this->pathInfo.obstacleAvoidanceInfo.radarForward.y = v6[34];
  this->pathInfo.obstacleAvoidanceInfo.radarForward.z = v6[35];
  this->pathInfo.radarValid = idBotMoveState::UpdateObstacleAvoidance(this, startAreaNum: AreaNum);
}


// ========================================================================
// ?UpdateMoveCmds@idBotMoveState@@QAAXAAVusercmd_t@@@Z
// EA  : 0x82B433E0
// RVA : 0x00B433E0
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

void __fastcall idBotMoveState::UpdateMoveCmds(idBotMoveState *this, usercmd_t *cmd)
{
  unsigned __int64 v4; // r6
  const char *v5; // r7
  botMoveStatus_t currentMoveStatus; // r11
  bool IsCrouching; // r3
  int flags; // r11
  unsigned int v9; // r10
  idPhysics *Physics; // r3
  float *v11; // r28
  idPhysics *v12; // r3
  const idVec3 *v13; // r29
  idPresentable *presentable; // r3
  const idAngles *v15; // r4
  bool MoveStopAtPoint; // r27
  double x; // fp11
  double y; // fp10
  double v19; // fp7
  double v20; // fp6
  double v21; // fp31
  double v22; // fp10
  double v23; // fp1
  double z; // fp12
  double v25; // fp11
  double v26; // fp10
  char y_low; // r11
  double v28; // fp8
  double v29; // fp7
  double v30; // fp6
  char v31; // r11
  idPLogScope v32; // [sp+50h] [-90h] BYREF
  idVec3 v33; // [sp+58h] [-88h] BYREF
  idVec3 v34; // [sp+68h] [-78h] BYREF
  idVec3 v35; // [sp+78h] [-68h] BYREF
  idAngles v36[2]; // [sp+88h] [-58h] BYREF

  RD_EventBegin(name: "Update_MoveCmds");
  LODWORD(v4) = "Update_MoveCmds";
  HIDWORD(v4) = 1024;
  idPLogScope::idPLogScope(this: &v32, pl: &pLog, gMask: v4, label: v5);
  if ( this->currentMoveCmd.moveGoalType <= MOVE_GOAL_TYPE_NONE )
    goto _M492003;
  currentMoveStatus = this->currentMoveStatus;
  if ( currentMoveStatus >= MOVE_STATUS_START_ERROR_CODES )
    goto _M492003;
  if ( currentMoveStatus == MOVE_STATUS_DONE )
  {
    idBotMoveState::UpdateIdleCmds(this, cmd);
    idPLogScope::~idPLogScope(this: &v32);
    goto LABEL_47;
  }
  if ( bot_freezeMovement.valueInteger > 0 )
  {
_M492003:
    idPLogScope::~idPLogScope(this: &v32);
    goto LABEL_47;
  }
  IsCrouching = idActor::IsCrouching(this: this->owner->owner);
  if ( (unsigned int)(this->currentMoveStance - 1) <= 3 )
  {
    if ( this->currentMoveStance == MOVE_STANCE_WALK || this->currentMoveStance == MOVE_STANCE_RUN )
    {
      if ( IsCrouching )
        cmd->upmove = 127;
    }
    else if ( this->currentMoveStance == MOVE_STANCE_CROUCH )
    {
      cmd->upmove = -127;
    }
    else
    {
      if ( IsCrouching )
        cmd->upmove = 127;
      cmd->buttons |= 0x10u;
    }
  }
  flags = this->currentMoveFlags.flags;
  if ( (flags & 1) != 0 )
  {
    if ( bot_allowJumping.valueInteger != 0 )
      cmd->upmove = 127;
    v9 = this->currentMoveFlags.flags & 0xFFFFFFFE;
LABEL_28:
    this->currentMoveFlags.flags = v9;
    goto LABEL_29;
  }
  if ( (flags & 2) != 0 )
  {
    if ( bot_allowJumping.valueInteger != 0 )
      cmd->upmove = 127;
    cmd->rightmove = 127;
    v9 = this->currentMoveFlags.flags & 0xFFFFFFFD;
    goto LABEL_28;
  }
  if ( (flags & 4) != 0 )
  {
    if ( bot_allowJumping.valueInteger != 0 )
      cmd->upmove = 127;
    cmd->rightmove = -127;
    v9 = this->currentMoveFlags.flags & 0xFFFFFFFB;
    goto LABEL_28;
  }
LABEL_29:
  Physics = idEntity::GetPhysics(this: this->owner->owner);
  v11 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v12 = idEntity::GetPhysics(this: this->owner->owner);
  v13 = v12->GetGravityNormal(this: v12);
  presentable = this->owner->owner->presentable;
  if ( presentable != nullptr )
    v15 = (const idAngles *)presentable->GetPlayerInterface_2(this: presentable);
  else
    v15 = nullptr;
  idPresentablePlayer::GetViewAngles(this: (idPresentablePlayer *)v36, result: v15, includeWeaponKick: true);
  MoveStopAtPoint = idBotMoveCommand::GetMoveStopAtPoint(this: &this->currentMoveCmd);
  idAngles::ToVectors(this: v36, forward: &v34, right: nullptr, up: nullptr);
  x = v13->x;
  y = v13->y;
  v19 = (float)(v13->y * v34.x);
  v20 = (float)(v13->z * v34.y);
  v21 = 1.0;
  v35.y = (float)(v13->z * v34.x) - (float)(v13->x * v34.z);
  v35.z = (float)((float)x * v34.y) - (float)v19;
  v35.x = (float)((float)y * v34.z) - (float)v20;
  idVec3::ProjectOntoPlane(this: &v34, normal: v13, overBounce: 1.0);
  idVec3::ProjectOntoPlane(this: &v35, normal: v13, overBounce: 1.0);
  v22 = (float)(this->pathInfo.nextMovePoint.y - v11[1]);
  v33.x = this->pathInfo.nextMovePoint.x - *v11;
  v33.z = 0.0;
  v33.y = v22;
  v23 = idVec3::NormalizeFast(this: &v33);
  if ( this->pathInfo.nextMovePointIsGoal && MoveStopAtPoint && v23 < 64.0 )
    v21 = 0.5;
  z = v33.z;
  v25 = v33.x;
  v26 = v33.y;
  LODWORD(v33.y) = (int)(float)((float)((float)((float)(v33.y * v34.y)
                                              + (float)((float)(v33.x * v34.x) + (float)(v33.z * v34.z)))
                                      * (float)((float)v21 * (float)128.0))
                              + (float)128.0);
  if ( v33.y >= 0.0 )
  {
    if ( SLODWORD(v33.y) <= 255 )
      y_low = LOBYTE(v33.y);
    else
      y_low = -1;
  }
  else
  {
    y_low = 0;
  }
  v28 = (float)((float)v26 * v35.y);
  v29 = v35.z;
  v30 = v35.x;
  cmd->forwardmove = y_low + 0x80;
  LODWORD(v33.y) = (int)(float)((float)((float)((float)((float)v25 * (float)v30)
                                              + (float)((float)((float)z * (float)v29) + (float)v28))
                                      * (float)((float)v21 * (float)128.0))
                              + (float)128.0);
  v31 = LOBYTE(v33.y);
  if ( v33.y >= 0.0 )
  {
    if ( SLODWORD(v33.y) > 255 )
      v31 = -1;
  }
  else
  {
    v31 = 0;
  }
  cmd->rightmove = v31 + 0x80;
  idPLogScope::~idPLogScope(this: &v32);
LABEL_47:
  RD_EventEnd();
}


// ========================================================================
// __unwind$491769
// EA  : 0x82B437D4
// RVA : 0x00B437D4
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

void _unwind_491769()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 224 + 148));
}


// ========================================================================
// __unwind$491770
// EA  : 0x82B437FC
// RVA : 0x00B437FC
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

void _unwind_491770()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 224 + 80));
}


// ========================================================================
// ?PathToGoal@idBotMoveState@@AAA_NXZ
// EA  : 0x82B43830
// RVA : 0x00B43830
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

int __fastcall idBotMoveState::PathToGoal(idBotMoveState *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  int moveAreaNum; // r26
  botMoveStatus_t currentMoveStatus; // r11
  int GameMs; // r3
  int AreaNum; // r27
  botMoveStatus_t v8; // r11
  int v9; // r3
  idPlayer *owner; // r3
  BOOL v11; // r29
  const idVec3 *AASOrigin; // r3
  float x; // r8
  float y; // r11
  float z; // r9
  float v16; // r7
  float v17; // r6
  unsigned __int64 v18; // r6
  const char *v19; // r7
  BOOL v20; // r25
  idPhysics *Physics; // r3
  const idVec3 *v22; // r3
  botMoveStatus_t v23; // r11
  int v24; // r3
  char updated; // r3
  idVec3 *p_moveGoal; // r29
  float *p_x; // r11
  bool v28; // r11
  botMoveStatus_t v30; // r11
  int v31; // r3
  idPLogScope v32; // [sp+68h] [-88h] BYREF
  idPLogScope v33; // [sp+70h] [-80h] BYREF
  float v34; // [sp+78h] [-78h] BYREF
  float v35; // [sp+7Ch] [-74h]
  float v36; // [sp+80h] [-70h]
  float v37; // [sp+88h] [-68h] BYREF
  float v38; // [sp+8Ch] [-64h]
  float v39; // [sp+90h] [-60h]

  if ( this->pathInfo.aas == nullptr )
    return 0;
  RD_EventBegin(name: "PathToGoal");
  LODWORD(v2) = "PathToGoal";
  HIDWORD(v2) = 3072;
  idPLogScope::idPLogScope(this: &v32, pl: &pLog, gMask: v2, label: v3);
  moveAreaNum = this->currentMoveCmd.moveAreaNum;
  if ( moveAreaNum == 0 )
  {
    currentMoveStatus = this->currentMoveStatus;
    this->currentMoveStatus = MOVE_STATUS_GOAL_OFF_MESH;
    if ( currentMoveStatus != MOVE_STATUS_GOAL_OFF_MESH )
    {
      GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idBotMoveCommand::ErroredMoveGoalCallBack(
        this: &this->currentMoveCmd,
        bot: this->owner,
        curTime: GameMs,
        moveStatusCode: this->currentMoveStatus);
    }
LABEL_5:
    idPLogScope::~idPLogScope(this: &v32);
LABEL_31:
    RD_EventEnd();
    return 0;
  }
  AreaNum = idActor::GetAreaNum(this: this->owner->owner, aas: this->pathInfo.aas);
  if ( AreaNum == 0 )
  {
    AreaNum = idActor::GetLastValidAreaNum(this: this->owner->owner, aas: this->pathInfo.aas);
    if ( AreaNum == 0 )
    {
      v8 = this->currentMoveStatus;
      this->currentMoveStatus = MOVE_STATUS_OWNER_OFF_MESH;
      if ( v8 != MOVE_STATUS_OWNER_OFF_MESH )
      {
        v9 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        idBotMoveCommand::ErroredMoveGoalCallBack(
          this: &this->currentMoveCmd,
          bot: this->owner,
          curTime: v9,
          moveStatusCode: this->currentMoveStatus);
      }
      goto LABEL_5;
    }
  }
  owner = this->owner->owner;
  v11 = (_cntlzw(owner->entityNumber - bot_showPath.valueInteger) & 0x20) != 0;
  AASOrigin = idActor::GetAASOrigin(this: owner, aas: this->pathInfo.aas);
  x = AASOrigin->x;
  y = this->currentMoveCmd.moveDestination.y;
  z = this->currentMoveCmd.moveDestination.z;
  v16 = AASOrigin->y;
  v17 = AASOrigin->z;
  v34 = this->currentMoveCmd.moveDestination.x;
  v35 = y;
  v36 = z;
  v37 = x;
  v38 = v16;
  v39 = v17;
  RD_EventBegin(name: "WalkPathToGoal");
  LODWORD(v18) = "WalkPathToGoal";
  HIDWORD(v18) = 3072;
  idPLogScope::idPLogScope(this: &v33, pl: &pLog, gMask: v18, label: v19);
  this->pathInfo.hasPath = this->pathInfo.aas->WalkPathToGoal(
                             this: (idAAS2 *)this->pathInfo.aas,
                             a2: &this->pathInfo.path,
                             a3: AreaNum,
                             a4: (const idVec3 *)&v37,
                             a5: moveAreaNum,
                             a6: (const idVec3 *)&v34,
                             a7: 254,
                             a8: 62);
  idPLogScope::End(this: &v33, totalTicks: nullptr);
  v20 = v11;
  if ( v11 )
  {
    this->pathInfo.aas->DrawArea(
      this: (idAAS2 *)this->pathInfo.aas,
      a2: AreaNum,
      a3: true,
      a4: true,
      a5: false,
      a6: false,
      a7: true,
      a8: true);
    clientGame->renderWorld->DebugPoint(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorGreen,
      a3: (const idVec3 *)&v37,
      a4: 0,
      a5: false);
    Physics = idEntity::GetPhysics(this: this->owner->owner);
    v22 = Physics->GetOrigin(this: Physics, a2: 0);
    clientGame->renderWorld->DebugPoint(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorBlue,
      a3: v22,
      a4: 0,
      a5: false);
    if ( !this->pathInfo.hasPath )
    {
      ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))clientGame->renderWorld->DebugArrow)(
        a1: clientGame->renderWorld,
        a2: &idColor::colorRed,
        a3: &v37,
        a4: &v34,
        a5: 16.0);
      clientGame->renderWorld->DebugPoint(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorRed,
        a3: (const idVec3 *)&v34,
        a4: 1000,
        a5: false);
    }
  }
  if ( !this->pathInfo.hasPath )
  {
    v23 = this->currentMoveStatus;
    this->currentMoveStatus = MOVE_STATUS_GOAL_UNREACHABLE;
    if ( v23 != MOVE_STATUS_GOAL_UNREACHABLE )
    {
      v24 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idBotMoveCommand::ErroredMoveGoalCallBack(
        this: &this->currentMoveCmd,
        bot: this->owner,
        curTime: v24,
        moveStatusCode: this->currentMoveStatus);
    }
LABEL_30:
    idPLogScope::~idPLogScope(this: &v33);
    RD_EventEnd();
    idPLogScope::~idPLogScope(this: &v32);
    goto LABEL_31;
  }
  if ( v11 )
  {
    idGameTimeManager::GetGameMsPerFrame(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    ((void (__fastcall *)(const idAAS2 *, int, float *, int, float *, int, int, int))this->pathInfo.aas->ShowWalkPath)(
      a1: this->pathInfo.aas,
      a2: AreaNum,
      a3: &v37,
      a4: moveAreaNum,
      a5: &v34,
      a6: 254,
      a7: 62,
      a8: this->owner->owner->entityNumber);
    clientGame->renderWorld->DebugPoint(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorCyan,
      a3: (const idVec3 *)&v34,
      a4: 1000,
      a5: false);
  }
  updated = idBotMoveState::UpdateObstacleAvoidance(this, startAreaNum: AreaNum);
  this->pathInfo.hasClearPath = updated;
  this->pathInfo.radarValid = updated;
  if ( updated == 0 )
  {
    v30 = this->currentMoveStatus;
    this->currentMoveStatus = MOVE_STATUS_NO_CLEAR_PATH;
    if ( v30 != MOVE_STATUS_NO_CLEAR_PATH )
    {
      v31 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
      idBotMoveCommand::ErroredMoveGoalCallBack(
        this: &this->currentMoveCmd,
        bot: this->owner,
        curTime: v31,
        moveStatusCode: this->currentMoveStatus);
    }
    goto LABEL_30;
  }
  p_moveGoal = &this->pathInfo.path.moveGoal;
  p_x = &this->pathInfo.obstacleAvoidanceInfo.seekPos[(float)((float)((float)(this->pathInfo.obstacleAvoidanceInfo.seekPosPlane.a
                                                                            * v37)
                                                                    + (float)((float)(this->pathInfo.obstacleAvoidanceInfo.seekPosPlane.b
                                                                                    * v38)
                                                                            + (float)(this->pathInfo.obstacleAvoidanceInfo.seekPosPlane.c
                                                                                    * v39)))
                                                            + this->pathInfo.obstacleAvoidanceInfo.seekPosPlane.d) > -0.0099999998].x;
  this->pathInfo.path.moveGoal.x = *p_x;
  this->pathInfo.path.moveGoal.y = p_x[1];
  this->pathInfo.path.moveGoal.z = p_x[2];
  if ( v20 )
    clientGame->renderWorld->DebugPoint(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorRed,
      a3: &this->pathInfo.path.moveGoal,
      a4: 0,
      a5: false);
  this->pathInfo.nextMovePoint.x = p_moveGoal->x;
  this->pathInfo.nextMovePoint.y = this->pathInfo.path.moveGoal.y;
  this->pathInfo.nextMovePoint.z = this->pathInfo.path.moveGoal.z;
  v28 = __fabs((float)(p_moveGoal->x - v34)) <= 0.1
     && __fabs((float)(this->pathInfo.path.moveGoal.y - v35)) <= 0.1
     && __fabs((float)(this->pathInfo.path.moveGoal.z - v36)) <= 0.1;
  this->pathInfo.nextMovePointIsGoal = v28;
  idPLogScope::~idPLogScope(this: &v33);
  RD_EventEnd();
  idPLogScope::~idPLogScope(this: &v32);
  RD_EventEnd();
  return 1;
}


// ========================================================================
// __unwind$492031
// EA  : 0x82B43E18
// RVA : 0x00B43E18
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

void _unwind_492031()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 240 + 148));
}


// ========================================================================
// __unwind$492032
// EA  : 0x82B43E40
// RVA : 0x00B43E40
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

void _unwind_492032()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 240 + 104));
}


// ========================================================================
// __unwind$492033
// EA  : 0x82B43E68
// RVA : 0x00B43E68
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

void _unwind_492033()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 240 + 149));
}


// ========================================================================
// __unwind$492034
// EA  : 0x82B43E90
// RVA : 0x00B43E90
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

void _unwind_492034()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 240 + 112));
}


// ========================================================================
// ?Update@idBotMoveState@@QAAXXZ
// EA  : 0x82B43EB8
// RVA : 0x00B43EB8
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

void __fastcall idBotMoveState::Update(idBotMoveState *this)
{
  botMoveStatus_t currentMoveStatus; // r11
  int GameMs; // r3
  botMoveStatus_t v4; // r11
  int v5; // r3
  botMoveStatus_t v6; // r11
  int v7; // r3

  idBotMoveState::UpdateDebugInfo(this);
  if ( this->currentMoveCmd.moveGoalType > MOVE_GOAL_TYPE_NONE )
  {
    if ( idBotMoveCommand::UpdateMoveDestination(
           this: &this->currentMoveCmd,
           aas: (idBounds *)this->pathInfo.aas,
           bot: this->owner) != 0 )
    {
      currentMoveStatus = this->currentMoveStatus;
      this->currentMoveStatus = MOVE_STATUS_INVALID_GOAL;
      if ( currentMoveStatus != MOVE_STATUS_INVALID_GOAL )
      {
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        idBotMoveCommand::ErroredMoveGoalCallBack(
          this: &this->currentMoveCmd,
          bot: this->owner,
          curTime: GameMs,
          moveStatusCode: this->currentMoveStatus);
      }
    }
    else if ( (unsigned __int8)idBotMoveState::ReachedMoveGoal(this) != 0 )
    {
      v4 = this->currentMoveStatus;
      this->currentMoveStatus = MOVE_STATUS_DONE;
      if ( v4 != MOVE_STATUS_DONE )
      {
        v5 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        idBotMoveCommand::ReachedMoveGoalCallBack(this: &this->currentMoveCmd, bot: this->owner, curTime: v5);
      }
      idBotMoveState::UpdateAASRadar(this);
    }
    else if ( (unsigned __int8)idBotMoveState::PathToGoal(this) != 0 )
    {
      if ( this->currentMoveState != MOVE_STATE_NORMAL )
        this->currentMoveState = MOVE_STATE_NORMAL;
      if ( this->currentMoveState == MOVE_STATE_NORMAL )
        idBotMoveState::UpdateMoveState_Normal(this);
      v6 = this->currentMoveStatus;
      this->currentMoveStatus = MOVE_STATUS_MOVING;
      if ( v6 != MOVE_STATUS_MOVING )
      {
        v7 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        idBotMoveCommand::StartedMoveGoalCallBack(this: &this->currentMoveCmd, bot: this->owner, curTime: v7);
      }
      if ( bot_showMoveUser.valueInteger == this->owner->owner->entityNumber )
        idLib::Printf(fmt: "Current Move User Is: %s\n", this->currentMoveCmd.moveUserName);
    }
  }
}


// ========================================================================
// `dynamic initializer for 'bot_freezeMovement''
// EA  : 0x8336CCB8
// RVA : 0x0136CCB8
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__bot_freezeMovement__()
{
  idCVar::idCVar(
    this: &bot_freezeMovement,
    name: "bot_freezeMovement",
    value: "0",
    flags: 2,
    description: "1 = Freeze the bot in place. 2 = Same as 1, but bot always considers itself as having reached its goal",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__bot_freezeMovement__);
}


// ========================================================================
// `dynamic initializer for 'bot_allowJumping''
// EA  : 0x8336CD10
// RVA : 0x0136CD10
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__bot_allowJumping__()
{
  idCVar::idCVar(
    this: &bot_allowJumping,
    name: "bot_allowJumping",
    value: "0",
    flags: 1,
    description: "1 = Bots can jump when moving. 0 = bots can never jump. Useful for testing.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__bot_allowJumping__);
}


// ========================================================================
// `dynamic initializer for 'bot_showPath''
// EA  : 0x8336CD68
// RVA : 0x0136CD68
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__bot_showPath__()
{
  idCVar::idCVar(
    this: &bot_showPath,
    name: "bot_showPath",
    value: "-1",
    flags: 2,
    description: "Set to the client number of the bot that you want to show paths.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__bot_showPath__);
}


// ========================================================================
// `dynamic initializer for 'bot_showMoveUser''
// EA  : 0x8336CDC0
// RVA : 0x0136CDC0
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__bot_showMoveUser__()
{
  idCVar::idCVar(
    this: &bot_showMoveUser,
    name: "bot_showMoveUser",
    value: "-1",
    flags: 2,
    description: "Set to the client number of the bot that you want to show move users",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__bot_showMoveUser__);
}


// ========================================================================
// `dynamic initializer for 'bot_useObstacleAvoidance''
// EA  : 0x8336CE18
// RVA : 0x0136CE18
// PDB : w:\tech5\tungsten\game\bot\bot_movestate.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__bot_useObstacleAvoidance__()
{
  idCVar::idCVar(
    this: &bot_useObstacleAvoidance,
    name: "bot_useObstacleAvoidance",
    value: "1",
    flags: 1,
    description: "1 = use obstacle avoidance. 0 = use pathfinder only. Used to debug obstacle avoidance issues.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__bot_useObstacleAvoidance__);
}

