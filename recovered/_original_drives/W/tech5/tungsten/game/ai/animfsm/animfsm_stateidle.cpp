
// ========================================================================
// ?Enter@idAnimStateIdleGround@@UAAXPAVidAI2@@PAVidAnimBaseFSM@@@Z
// EA  : 0x82A7F198
// RVA : 0x00A7F198
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_stateidle.cpp
// ========================================================================

void __fastcall idAnimStateIdleGround::Enter(idAnimStateIdleGround *this, idAI2 *ai, idAnimBaseFSM *fsm)
{
  idAnimBaseFSM::ClearDestination(this: fsm);
  idAIStateLite::SetSubState(this, newSubState: 0);
}


// ========================================================================
// ??0idAnimStateIdleGround@@QAA@XZ
// EA  : 0x82A7F1E0
// RVA : 0x00A7F1E0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_stateidle.cpp
// ========================================================================

idAnimStateIdleGround *__fastcall idAnimStateIdleGround::idAnimStateIdleGround(idAnimStateIdleGround *this)
{
  idAIStateLite::idAIStateLite(this);
  this->__vftable = (idAnimStateIdleGround_vtbl *)&idAnimStateIdleGround::`vftable';
  idAIStateLite::SetSubState(this, newSubState: 0);
  return this;
}


// ========================================================================
// __unwind$487937
// EA  : 0x82A7F238
// RVA : 0x00A7F238
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_stateidle.cpp
// ========================================================================

void _unwind_487937()
{
  int v0; // r12

  idAnimStateDead::~idAnimStateDead(this: *(idAIStateLite **)(v0 - 112 + 132));
}


// ========================================================================
// ?Exit@idAnimStateIdleGround@@UAAXPAVidAI2@@PAVidAnimBaseFSM@@@Z
// EA  : 0x82A7F260
// RVA : 0x00A7F260
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_stateidle.cpp
// ========================================================================

void __fastcall idAnimStateIdleGround::Exit(idAnimStateIdleGround *this, idAI2 *ai, idAnimBaseFSM *fsm)
{
  fsm->stompMoveOrientationAxis = true;
}


// ========================================================================
// ?CheckForStationaryTurn@idAnimStateIdleGround@@IAA_NPAVidAI2@@PAVidAnimBaseFSM@@@Z
// EA  : 0x82A7F2E0
// RVA : 0x00A7F2E0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_stateidle.cpp
// ========================================================================

int __fastcall idAnimStateIdleGround::CheckForStationaryTurn(
        idAnimStateIdleGround *this,
        idAI2 *ai,
        idAnimBaseFSM *fsm)
{
  aiIdleTurn_t idleTurnType; // r10
  const idDeclAIBehavior *decl; // r11
  aiIdleTurn_t num; // r9
  const idDeclAITurnParms **list; // r9
  const idDeclAITurnParms *v9; // r29
  idAI2::idAIVolatile::idAIFocusInfo *p_focus; // r24
  double maxAngle; // fp0
  double value; // fp27
  idPhysics *Physics; // r3
  float *v14; // r3
  double z; // fp11
  double y; // fp9
  double x; // fp8
  float v18; // r10
  double v19; // fp7
  float v20; // r9
  double v21; // fp6
  double v22; // fp5
  double v23; // fp30
  double v24; // fp29
  double v25; // fp9
  double v26; // fp28
  long double v27; // fp2
  long double v28; // fp2
  double v29; // fp27
  const idMat3 *v30; // r3
  __int64 v31; // r9
  idMD6AnimData *animData; // r11
  int numFrames; // r26
  signed int frameRate; // r29
  int v35; // r3
  int v36; // r11
  int v37; // r26
  idEntity *Neutral; // r3
  idPhysics *v39; // r29
  __int64 v40; // r11
  __int64 v41; // r8
  double v42; // fp26
  float *v43; // r3
  double v44; // fp8
  double v45; // fp7
  double v46; // fp6
  double v47; // fp11
  double v48; // fp10
  const idMat3 *v49; // r3
  idPhysics *v50; // r3
  const idVec3 *v51; // r3
  const idMat3 *v52; // r3
  idMat3 v54; // [sp+50h] [-1F0h] BYREF
  float v55; // [sp+74h] [-1CCh]
  float v56; // [sp+78h] [-1C8h]
  int v57; // [sp+80h] [-1C0h] BYREF
  idVec3 v58[4]; // [sp+90h] [-1B0h] BYREF
  idAnimWebTransitions::transitionQueryResult_t v59; // [sp+C0h] [-180h] BYREF
  idAIMoveCmd v60; // [sp+110h] [-130h] BYREF

  if ( (fsm->overrideMoveFlags & 0x2000) == 0 )
    return 0;
  idleTurnType = fsm->idleTurnType;
  if ( idleTurnType < AIIDLETURN_RELAXED )
    return 0;
  decl = ai->aiEditable.behaviors.decl;
  num = decl->turnParms.num;
  LODWORD(v54.mat[1].y) = decl;
  if ( idleTurnType >= num )
    return 0;
  list = decl->turnParms.list;
  LODWORD(v54.mat[1].y) = decl;
  v9 = list[idleTurnType];
  if ( v9 == nullptr
    || !v9->turnToFocus
    || !v9->allowTurns
    || ai->aiEditable.movement.suppressBodyRotation
    || !ai->aiVolatile.focus.enableBodyRotation
    || ai->GetPosture(this: ai) == POSTURE_CROUCHED && !v9->allowCrouchedTurns )
  {
    return 0;
  }
  if ( ai->GetPosture(this: ai) == POSTURE_SITTING && !v9->allowSittingTurns )
    return 0;
  p_focus = (idAI2::idAIVolatile::idAIFocusInfo *)&ai->aiVolatile.focus.foci.ptr[1];
  if ( (unsigned __int8)idFocusInfo::HasFocus(this: ai->aiVolatile.focus.foci.ptr) != 0 )
    p_focus = &ai->aiVolatile.focus;
  if ( (unsigned __int8)idFocusInfo::HasFocus(this: p_focus->foci.ptr) == 0 )
    return 0;
  maxAngle = v9->maxAngle;
  value = p_focus->foci.ptr[0].aimTracker.maxYaw.value;
  LODWORD(v54.mat[1].y) = &p_focus->foci.ptr[0].aimTracker;
  if ( maxAngle >= 0.0 )
    value = maxAngle;
  ai->GetEyePos(this: ai, a2: (idVec3 *)&v54.mat[2].z);
  Physics = idEntity::GetPhysics(this: ai);
  v14 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  z = fsm->orientBody.axis.mat[2].z;
  LODWORD(v54.mat[1].y) = &p_focus->foci.ptr[0].idealFocusPoint;
  y = fsm->orientBody.axis.mat[2].y;
  x = fsm->orientBody.axis.mat[2].x;
  v18 = *v14;
  v19 = p_focus->foci.ptr[0].idealFocusPoint.z;
  v20 = v14[2];
  v21 = p_focus->foci.ptr[0].idealFocusPoint.y;
  v22 = p_focus->foci.ptr[0].idealFocusPoint.x;
  v54.mat[1].z = v14[1];
  v23 = v54.mat[1].z;
  v54.mat[1].y = v18;
  v24 = v18;
  v54.mat[2].x = v20;
  v54.mat[0].y = (float)v21 - v54.mat[1].z;
  v54.mat[0].x = (float)v22 - v18;
  v25 = (float)((float)((float)x * (float)(v54.mat[2].z - v18))
              + (float)((float)((float)y * (float)(v55 - v54.mat[1].z)) + (float)((float)z * (float)(v56 - v20))));
  v26 = (float)(v20 + (float)v25);
  v54.mat[0].z = (float)v19 - (float)(v20 + (float)v25);
  idVec3::ProjectOntoPlane(this: v54.mat, normal: &fsm->orientBody.axis.mat[2], overBounce: 1.0);
  idVec3::NormalizeFast(this: v54.mat);
  *(double *)&v27 = value;
  v28 = cos(x: v27);
  v29 = (float)*(double *)&v28;
  if ( (float)((float)(fsm->orientBody.axis.mat[0].y * v54.mat[0].y)
             + (float)((float)(v54.mat[0].x * fsm->orientBody.axis.mat[0].x)
                     + (float)(fsm->orientBody.axis.mat[0].z * v54.mat[0].z))) >= v29 )
    return 0;
  if ( ai->aiVolatile.animation.animWebAnimator.ptr[0].runIndexType == ANIMWEBAI_RUNINDEXTYPE_DUCK )
    return 0;
  idAnimWebTransitions::transitionQueryResult_t::transitionQueryResult_t(this: &v59);
  v30 = idVec3::ToMat3(this: v58, result: &v54);
  if ( idAnimBaseFSM::CheckForStationaryTurnTransition(this: fsm, desiredAxis: v30, transInfo: &v59) != 2 )
    return 0;
  if ( v9->predictTurns && idAIMemory::GetNeutral(this: p_focus->foci.ptr) != nullptr && v59.anim != nullptr )
  {
    animData = v59.anim->animData;
    numFrames = 0;
    if ( animData != nullptr )
    {
      numFrames = animData->numFrames;
      frameRate = animData->frameRate;
    }
    else
    {
      frameRate = 30;
    }
    v35 = gameLocal->GetGameMsPerRealSec(this: gameLocal);
    v36 = __ROL4__(v35 * numFrames, 1);
    v37 = v35 * numFrames / frameRate;
    __twllei(frameRate, 0);
    __twlgei(frameRate & ~(v36 - 1), 0xFFFFFFFF);
    Neutral = (idEntity *)idAIMemory::GetNeutral(this: p_focus->foci.ptr);
    v39 = idEntity::GetPhysics(this: Neutral);
    if ( v39 != nullptr )
    {
      LODWORD(v40) = v37;
      *(_QWORD *)&v54.mat[1].y = v40;
      LODWORD(v41) = gameLocal->GetGameMsPerRealSec(this: gameLocal);
      HIDWORD(v41) = v39->__vftable;
      v42 = (float)((float)*(__int64 *)&v54.mat[1].y / (float)v41);
      *(_QWORD *)&v54.mat[1].y = v41;
      v43 = (float *)(*(int (__fastcall **)(int *, idPhysics *, _DWORD))(HIDWORD(v41) + 88))(a1: &v57, a2: v39, a3: 0);
      v44 = p_focus->foci.ptr[0].idealFocusPoint.z;
      v45 = p_focus->foci.ptr[0].idealFocusPoint.y;
      v46 = p_focus->foci.ptr[0].idealFocusPoint.x;
      LODWORD(v54.mat[1].y) = &p_focus->foci.ptr[0].idealFocusPoint;
      v47 = (float)((float)v44 + (float)(v43[2] * (float)v42));
      v48 = (float)((float)v45 + (float)(v43[1] * (float)v42));
      v54.mat[0].x = (float)((float)v46 + (float)((float)v42 * *v43)) - (float)v24;
      v54.mat[0].z = (float)v47 - (float)v26;
      v54.mat[0].y = (float)v48 - (float)v23;
      idVec3::ProjectOntoPlane(this: v54.mat, normal: &fsm->orientBody.axis.mat[2], overBounce: 1.0);
      idVec3::NormalizeFast(this: v54.mat);
      if ( (float)((float)(fsm->orientBody.axis.mat[0].y * v54.mat[0].y)
                 + (float)((float)(v54.mat[0].x * fsm->orientBody.axis.mat[0].x)
                         + (float)(fsm->orientBody.axis.mat[0].z * v54.mat[0].z))) >= v29 )
        return 0;
      v49 = idVec3::ToMat3(this: v58, result: &v54);
      if ( idAnimBaseFSM::CheckForStationaryTurnTransition(this: fsm, desiredAxis: v49, transInfo: &v59) != 2 )
        return 0;
    }
  }
  LODWORD(v31) = v59.selectionIndex;
  *(_QWORD *)&v54.mat[1].y = v31;
  fsm->animBlendVars.animStepSelect.value = (float)v31;
  idAIMoveCmd::idAIMoveCmd(
    this: &v60,
    user: "w:\\tech5\\tungsten\\game\\ai\\animfsm\\AnimFSM_StateIdle.cpp(267) : CheckForStationaryTurn");
  v50 = idEntity::GetPhysics(this: ai);
  v51 = v50->GetOrigin(this: v50, a2: 0);
  idAIMoveCmd::SetDest(this: &v60, dest: v51, entType: DEST_ENT_NONE);
  idAIMoveCmd::SetArriveAction(this: (D3DXShader::CTokenize *)&v60, enable: 2);
  v52 = idVec3::ToMat3(this: v58, result: &v54);
  idAIMoveCmd::SetArriveOrientation(this: &v60, orient: AIARRIVAL_ORIENT_ALIGN, axis: v52);
  idAnimBaseFSM::SetDestination(this: fsm, cmd: &v60);
  idAIMoveCmd::~idAIMoveCmd(this: &v60);
  return 1;
}


// ========================================================================
// __unwind$488230
// EA  : 0x82A7F818
// RVA : 0x00A7F818
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_stateidle.cpp
// ========================================================================

void _unwind_488230()
{
  int v0; // r12

  idAIMoveCmd::~idAIMoveCmd(this: (idAIMoveCmd *)(v0 - 576 + 272));
}


// ========================================================================
// ?Work@idAnimStateIdleGround@@UAAHPAVidAI2@@PAVidAnimBaseFSM@@@Z
// EA  : 0x82A7F848
// RVA : 0x00A7F848
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_stateidle.cpp
// ========================================================================

int __fastcall idAnimStateIdleGround::Work(idAnimStateIdleGround *this, idAI2 *ai, idAnimBaseFSM *fsm)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  bool IsMoveDone; // r3
  char v9; // r11
  idAIAnimWebState_Idle *v11; // r3
  idAnimWebState *v12; // r11
  int *v13; // r10
  idAtomicString *p_debugState; // r11
  int i; // ctr
  idAIAnimWebState_Target *v16; // r3
  idAnimWebState *v17; // r11
  int *v18; // r10
  idAtomicString *v19; // r11
  int j; // ctr
  int *v21; // r10
  float *p_destAnimUpdateDistanceMinSqr; // r11
  int k; // ctr
  idAnimWebCmdCtx *v24; // r3
  idAnimWebCmd *v25; // r3
  idAnimWebCmd *v26; // r3
  int flags; // r9
  idPLogScope v28; // [sp+50h] [-180h] BYREF
  int v29; // [sp+5Ch] [-174h] BYREF
  idAnimWebState v30; // [sp+60h] [-170h] BYREF
  int v31; // [sp+7Ch] [-154h] BYREF
  idAnimWebState v32; // [sp+80h] [-150h] BYREF
  idAIAnimWebState_Target v33; // [sp+A0h] [-130h] BYREF
  idAIAnimWebState_Idle v34; // [sp+C0h] [-110h] BYREF
  idAnimWebCmd v35; // [sp+E0h] [-F0h] BYREF

  RD_EventBegin(name: "idAnimStateIdleGround::Work");
  LODWORD(v6) = "idAnimStateIdleGround::Work";
  HIDWORD(v6) = 6;
  idPLogScope::idPLogScope(this: &v28, pl: &pLog, gMask: v6, label: v7);
  if ( fsm->currentMove.destType == MOVE_NONE
    || (IsMoveDone = idAI2::IsMoveDone(this: ai, checkAlignment: false), v9 = 1, IsMoveDone) )
  {
    v9 = 0;
  }
  if ( v9 != 0 )
  {
    idPLogScope::~idPLogScope(this: &v28);
    RD_EventEnd();
    return 5;
  }
  else
  {
    if ( fsm->enableIdlePump && (unsigned __int8)idAnimStateIdleGround::CheckForStationaryTurn(this, ai, fsm) == 0 )
    {
      v11 = idAIAnimWebState_Idle::idAIAnimWebState_Idle(
              this: &v34,
              ai,
              subweb: AISUBWEB_MAX,
              posture: POSTURE_MAX,
              useWeaponSlot: EQUIP_MAX);
      v12 = &v11->idAnimWebState;
      if ( v11 == nullptr )
        v12 = nullptr;
      v13 = &v29;
      p_debugState = &v12[-1].debugState;
      for ( i = 5; i != 0; --i )
      {
        ++p_debugState;
        *++v13 = (int)p_debugState->str;
      }
      v34.__vftable = (idAIAnimWebState_Idle_vtbl *)&idAIAnimWebState::`vftable';
      v16 = idAIAnimWebState_Target::idAIAnimWebState_Target(this: &v33, ai);
      v17 = &v16->idAnimWebState;
      if ( v16 == nullptr )
        v17 = nullptr;
      v18 = &v31;
      v19 = &v17[-1].debugState;
      for ( j = 5; j != 0; --j )
      {
        ++v19;
        *++v18 = (int)v19->str;
      }
      v33.__vftable = (idAIAnimWebState_Target_vtbl *)&idAIAnimWebState::`vftable';
      if ( idAnimWebState::Verify(this: &fsm->currentMove.destAnim, errorMsg: nullptr) )
      {
        v21 = &v29;
        p_destAnimUpdateDistanceMinSqr = &fsm->currentMove.destAnimUpdateDistanceMinSqr;
        for ( k = 5; k != 0; --k )
          *++v21 = *(_DWORD *)++p_destAnimUpdateDistanceMinSqr;
      }
      if ( idAnimWebState::operator!=(this: &v30, other: &v32) )
      {
        v24 = ai->GetAnimWebCmdCtx(this: ai);
        idAnimWebCmd::idAnimWebCmd(
          this: &v35,
          _owner: v24,
          userName: "w:\\tech5\\tungsten\\game\\ai\\animfsm\\AnimFSM_StateIdle.cpp(86) : toIdle");
        v35.flags |= 0x200u;
        v25 = idAnimWebCmd::ChangeState(this: &v35, _dst: &v30);
        v25->groups = 1;
        v25->intrBlend = INTR_BLEND_MULTI;
        v25->intrPath = INTR_PATH_YES;
        v26 = idAnimWebCmd::ViaSubweb(this: v25, subweb: "transitions");
        flags = v26->flags;
        v26->forceFallbackPathSize = -1;
        v26->groupFilter = -1;
        v26->flags = flags | 0x40;
        idAnimWebCmd::Commit(
          this: v26,
          handle: &fsm->animWaitHandle,
          priority: AWCMD_PRIORITY_HIGH,
          ev: AWCMD_EVENT_NONE);
      }
    }
    idPLogScope::~idPLogScope(this: &v28);
    RD_EventEnd();
    return 1;
  }
}


// ========================================================================
// __unwind$488564
// EA  : 0x82A7FA90
// RVA : 0x00A7FA90
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_stateidle.cpp
// ========================================================================

void _unwind_488564()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 464 + 396));
}


// ========================================================================
// __unwind$488565
// EA  : 0x82A7FAB8
// RVA : 0x00A7FAB8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_stateidle.cpp
// ========================================================================

void _unwind_488565()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 464 + 80));
}

