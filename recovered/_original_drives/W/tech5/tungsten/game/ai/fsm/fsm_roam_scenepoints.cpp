
// ========================================================================
// ?InternalInitState@idRoamScenePoint_Idle@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AED8F0
// RVA : 0x00AED8F0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

void __fastcall idRoamScenePoint_Idle::InternalInitState(idRoamScenePoint_Idle *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RoamScenePoint_Shall_LookAtScenePoint::Type,
    nextStateType: &idRoamScenePoint_Idle::Type);
}


// ========================================================================
// ?InternalInitState@idRoamScenePoint_Find@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AED908
// RVA : 0x00AED908
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

void __fastcall idRoamScenePoint_Find::InternalInitState(idRoamScenePoint_Find *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RoamScenePoint_Shall_LookAtScenePoint::Type,
    nextStateType: &idRoamScenePoint_Find::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RoamScenePoint_Shall_MoveToScenePoint::Type,
    nextStateType: &idRoamScenePoint_MoveTo::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RoamScenePoint_Shall_Idle::Type,
    nextStateType: &idRoamScenePoint_Idle::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RoamScenePoint_Shall_FindScenePoint::Type,
    nextStateType: &idRoamScenePoint_Find::Type);
}


// ========================================================================
// ?InternalInitState@idRoamScenePoint_MoveTo@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AED990
// RVA : 0x00AED990
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

void __fastcall idRoamScenePoint_MoveTo::InternalInitState(
        idRoamScenePoint_MoveTo *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RoamScenePoint_Shall_LookAtScenePoint::Type,
    nextStateType: &idRoamScenePoint_MoveTo::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RoamScenePoint_Shall_StayAtScenePoint::Type,
    nextStateType: &idRoamScenePoint_StayAt::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RoamScenePoint_Shall_FindScenePoint::Type,
    nextStateType: &idRoamScenePoint_Find::Type);
}


// ========================================================================
// ?InternalInitState@idRoamScenePoint_StayAt@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AEDA10
// RVA : 0x00AEDA10
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

void __fastcall idRoamScenePoint_StayAt::InternalInitState(
        idRoamScenePoint_StayAt *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RoamScenePoint_Shall_LookAtScenePoint::Type,
    nextStateType: &idRoamScenePoint_StayAt::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RoamScenePoint_Shall_FindScenePoint::Type,
    nextStateType: &idRoamScenePoint_Find::Type);
}


// ========================================================================
// ?InternalInitState@idRoamScenePoint_SharedWaitForAnimation@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AEDA78
// RVA : 0x00AEDA78
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

void __fastcall idRoamScenePoint_SharedWaitForAnimation::InternalInitState(
        idRoamScenePoint_SharedWaitForAnimation *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RoamScenePoint_Shared_Finished::Type,
    nextStateType: &idRoamScenePoint_SharedFinished::Type);
}


// ========================================================================
// ?InternalInitState@idRoamScenePoint_SharedFinished@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AEDA90
// RVA : 0x00AEDA90
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

void __fastcall idRoamScenePoint_SharedFinished::InternalInitState(
        idRoamScenePoint_SharedFinished *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &RoamScenePoint_Shall_Idle::Type,
    nextStateType: &idRoamScenePoint_Idle::Type);
}


// ========================================================================
// ?InitStates@idRoamScenePointFSM@@UAAXABVidFiniteStateMachineParams@@@Z
// EA  : 0x82AEDAA8
// RVA : 0x00AEDAA8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

void __fastcall idRoamScenePointFSM::InitStates(idRoamScenePointFSM *this, const idFiniteStateMachineParams *params)
{
  idAIFSM::InitStates(this, params);
  this->AddState(this, a2: &this->stateRoamSPIdle);
  this->AddState(this, a2: &this->stateRoamSPFind);
  this->AddState(this, a2: &this->stateRoamSPMoveTo);
  this->AddState(this, a2: &this->stateRoamSPStayAt);
  this->AddState(this, a2: &this->stateRoamSPSharedFinished);
  this->AddState(this, a2: &this->stateRoamSPSharedWaitForAnimation);
}


// ========================================================================
// ?Evaluate@RoamScenePoint_Shall_Idle@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEDB68
// RVA : 0x00AEDB68
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

int __fastcall RoamScenePoint_Shall_Idle::Evaluate(
        RoamScenePoint_Shall_Idle *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return ai->aiEditable.actionSettings.roam.usesRoamScenePoints ? 0 : 0x1C8;
}


// ========================================================================
// ?Evaluate@RoamScenePoint_Shall_MoveToScenePoint@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEDB80
// RVA : 0x00AEDB80
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall RoamScenePoint_Shall_MoveToScenePoint::Evaluate(
        RoamScenePoint_Shall_MoveToScenePoint *this,
        idAI2 *ai,
        idRoamScenePointFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idRoamScenePointFSM *v6; // r3
  idScenePoint *curScenePoint; // r11
  char v8; // r11
  bool v9; // zf
  int stayTime; // r11
  idAIStateTransition::aiTransCode_t result; // r3

  v6 = idRoamScenePointFSM::CastTo(c: parentFSM);
  curScenePoint = ai->aiVolatile.memory.curScenePoint;
  if ( curScenePoint == nullptr || (v9 = curScenePoint->type == ROAM, v8 = 1, !v9) )
    v8 = 0;
  if ( v8 == 0 )
    return 0;
  stayTime = v6->stayTime;
  result = TRANSCODE_MAX;
  if ( stayTime != -1 )
    return 0;
  return result;
}


// ========================================================================
// ?AIState_EnterState@idRoamScenePoint_Find@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AEDC00
// RVA : 0x00AEDC00
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

void __fastcall idRoamScenePoint_Find::AIState_EnterState(
        idRoamScenePoint_Find *this,
        idAI2 *ai,
        idRoamScenePointFSM *fsm,
        const int curTime)
{
  idPlayer *Player; // r3
  idPhysics *Physics; // r3
  __int64 v9; // r4
  double roamMaxRange; // fp2
  double roamMinRange; // fp1
  idScenePoint *BestScenePoint; // r29
  idRoamScenePointFSM *v13; // r3
  float v14[4]; // [sp+50h] [-60h] BYREF
  idStr v15[2]; // [sp+60h] [-50h] BYREF

  Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
  if ( Player == nullptr )
    goto LABEL_3;
  Physics = idEntity::GetPhysics(this: Player);
  v9 = ((__int64 (__fastcall *)(idPhysics *, _DWORD))Physics->GetOrigin)(a1: Physics, a2: 0);
  v14[0] = *(float *)HIDWORD(v9);
  roamMaxRange = ai->aiEditable.actionSettings.roam.roamMaxRange;
  roamMinRange = ai->aiEditable.actionSettings.roam.roamMinRange;
  v14[1] = *(float *)(HIDWORD(v9) + 4);
  v14[2] = *(float *)(HIDWORD(v9) + 8);
  HIBYTE(v14[3]) = 1;
  BestScenePoint = GetBestScenePoint(
                     ai,
                     minRange: roamMinRange,
                     maxRange: roamMaxRange,
                     _focus: (const idAIPos *)v9,
                     spType: ROAM,
                     lookFlags: (scenePointLookFlags_t)v14);
  if ( BestScenePoint != nullptr )
  {
    v13 = idRoamScenePointFSM::CastTo(c: fsm);
    if ( v13 != nullptr )
      v13->stayTime = -1;
    ai->aiVolatile.memory.curScenePoint = BestScenePoint;
  }
  else
  {
LABEL_3:
    idState::SetEnterFailed(this, failed: true);
    v15[0].len = 0;
    v15[0].allocedAndFlag = 20;
    v15[0].data = v15[0].baseBuffer;
    v15[0].baseBuffer[0] = 0;
    idAI2::GetIdleStateName(this: ai, name: v15);
    idAI2::ChangeAnimState(
      this: ai,
      web: AIANIMWEB_BODY,
      subWeb: ai->aiVolatile.animation.subWeb,
      stateName: v15[0].data,
      interruptPath: INTR_PATH_YES,
      interruptBlend: INTR_BLEND_NO,
      subWebIndex: nullptr,
      stateIndex: nullptr);
    idStr::FreeData(this: v15);
  }
}


// ========================================================================
// __unwind$488207
// EA  : 0x82AEDD30
// RVA : 0x00AEDD30
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

void _unwind_488207()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?AIState_ReenterState@idRoamScenePoint_Find@@UAAXPAVidAI2@@PAVidAIFSM@@HH@Z
// EA  : 0x82AEDD60
// RVA : 0x00AEDD60
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

void __fastcall idRoamScenePoint_Find::AIState_ReenterState(
        idRoamScenePoint_Find *this,
        idAI2 *ai,
        idRoamScenePointFSM *fsm,
        const int transCode,
        const int curTime)
{
  idScenePoint *curScenePoint; // r11
  char v9; // r11
  bool v10; // zf
  idPlayer *Player; // r3
  idPhysics *Physics; // r3
  __int64 v13; // r4
  double roamMaxRange; // fp2
  double roamMinRange; // fp1
  idScenePoint *BestScenePoint; // r29
  idRoamScenePointFSM *v17; // r3
  float v18[4]; // [sp+50h] [-70h] BYREF
  idStr v19[3]; // [sp+60h] [-60h] BYREF

  curScenePoint = ai->aiVolatile.memory.curScenePoint;
  if ( curScenePoint == nullptr || (v10 = curScenePoint->type == ROAM, v9 = 1, !v10) )
    v9 = 0;
  if ( v9 == 0 )
  {
    Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
    if ( Player == nullptr )
      goto LABEL_7;
    Physics = idEntity::GetPhysics(this: Player);
    v13 = ((__int64 (__fastcall *)(idPhysics *, _DWORD))Physics->GetOrigin)(a1: Physics, a2: 0);
    v18[0] = *(float *)HIDWORD(v13);
    roamMaxRange = ai->aiEditable.actionSettings.roam.roamMaxRange;
    roamMinRange = ai->aiEditable.actionSettings.roam.roamMinRange;
    v18[1] = *(float *)(HIDWORD(v13) + 4);
    v18[2] = *(float *)(HIDWORD(v13) + 8);
    HIBYTE(v18[3]) = 1;
    BestScenePoint = GetBestScenePoint(
                       ai,
                       minRange: roamMinRange,
                       maxRange: roamMaxRange,
                       _focus: (const idAIPos *)v13,
                       spType: ROAM,
                       lookFlags: (scenePointLookFlags_t)v18);
    if ( BestScenePoint != nullptr )
    {
      v17 = idRoamScenePointFSM::CastTo(c: fsm);
      if ( v17 != nullptr )
        v17->stayTime = -1;
      ai->aiVolatile.memory.curScenePoint = BestScenePoint;
    }
    else
    {
LABEL_7:
      idState::SetEnterFailed(this, failed: true);
      v19[0].len = 0;
      v19[0].allocedAndFlag = 20;
      v19[0].data = v19[0].baseBuffer;
      v19[0].baseBuffer[0] = 0;
      idAI2::GetIdleStateName(this: ai, name: v19);
      idAI2::ChangeAnimState(
        this: ai,
        web: AIANIMWEB_BODY,
        subWeb: ai->aiVolatile.animation.subWeb,
        stateName: v19[0].data,
        interruptPath: INTR_PATH_YES,
        interruptBlend: INTR_BLEND_NO,
        subWebIndex: nullptr,
        stateIndex: nullptr);
      idStr::FreeData(this: v19);
    }
  }
}


// ========================================================================
// __unwind$488303_0
// EA  : 0x82AEDEC4
// RVA : 0x00AEDEC4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

void _unwind_488303_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// ?AIState_EnterState@idRoamScenePoint_MoveTo@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AEDEF0
// RVA : 0x00AEDEF0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

void __fastcall idRoamScenePoint_MoveTo::AIState_EnterState(
        idRoamScenePoint_MoveTo *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  idScenePoint_Roam *v7; // r3
  idScenePoint_Roam *v8; // r29
  scenePointScriptFlags_t scriptFlags; // r11
  idAI2 *v10; // r3
  void (__fastcall *SetWalkState)(struct idAI2 *, const walkState_t); // ctr
  int v12; // r4
  double duration; // fp0
  double radius; // fp13
  idEventArg *v15; // r29
  idEventArg *v16; // r31
  const idEventArg *v17; // [sp+8h] [-298h]
  const idEventArg *v18; // [sp+Ch] [-294h]
  const idEventArg *v19; // [sp+10h] [-290h]
  _BYTE v20[20]; // [sp+70h] [-230h] BYREF
  _BYTE v21[20]; // [sp+90h] [-210h] BYREF
  _BYTE v22[20]; // [sp+B0h] [-1F0h] BYREF
  _BYTE v23[20]; // [sp+D0h] [-1D0h] BYREF
  _BYTE v24[20]; // [sp+F0h] [-1B0h] BYREF
  _BYTE v25[20]; // [sp+110h] [-190h] BYREF
  float v26[5]; // [sp+130h] [-170h] BYREF
  int v27; // [sp+150h] [-150h]
  int v28; // [sp+154h] [-14Ch]
  const idEventArg *v29; // [sp+158h] [-148h]
  const idEventArg *v30; // [sp+15Ch] [-144h]
  _DWORD v31[5]; // [sp+170h] [-130h] BYREF
  _DWORD v32[5]; // [sp+190h] [-110h] BYREF
  _DWORD v33[5]; // [sp+1B0h] [-F0h] BYREF
  float v34[5]; // [sp+1D0h] [-D0h] BYREF
  idEventArg v35; // [sp+1F0h] [-B0h] BYREF
  idEventArg v36; // [sp+210h] [-90h] BYREF
  idEventReceiver v37[9]; // [sp+230h] [-70h] BYREF

  v7 = idScenePoint_Roam::CastTo(c: (idScenePoint_Roam *)ai->aiVolatile.memory.curScenePoint);
  v8 = v7;
  if ( v7 == nullptr )
  {
    idState::SetEnterFailed(this, failed: true);
    return;
  }
  ai->aiVolatile.animation.subWeb = AISUBWEB_RELAXED;
  scriptFlags = v7->scriptFlags;
  if ( (scriptFlags & 1) == 0 )
  {
    v10 = ai;
    SetWalkState = ai->SetWalkState;
    goto LABEL_7;
  }
  v10 = ai;
  SetWalkState = ai->SetWalkState;
  if ( (scriptFlags & 2) == 0 )
  {
LABEL_7:
    v12 = 1;
    goto LABEL_8;
  }
  v12 = 2;
LABEL_8:
  SetWalkState(this: v10, a2: (const walkState_t)v12);
  idAI2::SetEnableHeadTracking(this: ai, enable: true);
  idAI2::ClearAimFocus(this: ai);
  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  duration = v8->duration;
  HIBYTE(v33[0]) = 105;
  v33[1] = 1;
  HIBYTE(v26[0]) = 118;
  v26[1] = vec3_origin.x;
  v26[2] = vec3_origin.y;
  v26[3] = vec3_origin.z;
  radius = v8->radius;
  HIBYTE(v32[0]) = 105;
  HIBYTE(v34[0]) = 102;
  v32[1] = (_cntlzw(duration == 0.0) & 0x20) != 0;
  v34[1] = (float)radius * (float)0.25;
  HIBYTE(v31[0]) = 105;
  HIBYTE(v27) = 105;
  v28 = 35;
  v31[1] = v32[1] + 1;
  v15 = idEventArg::idEventArg(this: &v35, data: v8);
  v16 = idEventArg::idEventArg(this: &v36, data: ai);
  memcpy(Dst: v25, Src: v33, Size: sizeof(v25));
  memcpy(Dst: v24, Src: v26, Size: sizeof(v24));
  memcpy(Dst: v23, Src: v32, Size: sizeof(v23));
  memcpy(Dst: v22, Src: v34, Size: sizeof(v22));
  memcpy(Dst: v21, Src: v31, Size: sizeof(v21));
  memcpy(Dst: v20, Src: v15, Size: sizeof(v20));
  idEventReceiver::ProcessEvent(
    this: v37,
    result: fsm,
    ev: *(const idEventDef **)&v16->type,
    arg1: (const idEventArg *)LODWORD(v16->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v16->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(v27, 32),
    arg4: v29,
    arg5: v30,
    arg6: v17,
    arg7: v18,
    arg8: v19);
}


// ========================================================================
// ?AIState_ExitState@idRoamScenePoint_MoveTo@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AEE148
// RVA : 0x00AEE148
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

void __fastcall idRoamScenePoint_MoveTo::AIState_ExitState(
        idRoamScenePoint_MoveTo *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idScenePoint *curScenePoint; // r11
  idStr v6; // [sp+50h] [-40h] BYREF

  curScenePoint = ai->aiVolatile.memory.curScenePoint;
  if ( curScenePoint == nullptr || curScenePoint->duration != 0.0 )
  {
    v6.len = 0;
    v6.baseBuffer[0] = 0;
    v6.allocedAndFlag = 20;
    v6.data = v6.baseBuffer;
    idAI2::GetIdleStateName(this: ai, name: &v6);
    idAI2::ChangeAnimState(
      this: ai,
      web: AIANIMWEB_BODY,
      subWeb: ai->aiVolatile.animation.subWeb,
      stateName: v6.data,
      interruptPath: INTR_PATH_YES,
      interruptBlend: INTR_BLEND_NO,
      subWebIndex: nullptr,
      stateIndex: nullptr);
    idAIMoveState::Stop(this: &ai->aiVolatile.physics.moveState, newStatus: 0);
    idStr::FreeData(this: &v6);
  }
}


// ========================================================================
// __unwind$488572
// EA  : 0x82AEE220
// RVA : 0x00AEE220
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

void _unwind_488572()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 144 + 80));
}


// ========================================================================
// ??0idRoamScenePointFSM@@QAA@XZ
// EA  : 0x82AEE250
// RVA : 0x00AEE250
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

idRoamScenePointFSM *__fastcall idRoamScenePointFSM::idRoamScenePointFSM(idRoamScenePointFSM *this)
{
  idFiniteStateMachine::idFiniteStateMachine(this, name: "FSM_roamScenePoint");
  this->__vftable = (idRoamScenePointFSM_vtbl *)&idRoamScenePointFSM::`vftable';
  idState::idState(
    this: &this->stateRoamSPIdle,
    stateType: &idRoamScenePoint_Idle::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateRoamSPIdle.__vftable = (idRoamScenePoint_Idle_vtbl *)&idRoamScenePoint_Idle::`vftable';
  idState::idState(
    this: &this->stateRoamSPFind,
    stateType: &idRoamScenePoint_Find::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateRoamSPFind.__vftable = (idRoamScenePoint_Find_vtbl *)&idRoamScenePoint_Find::`vftable';
  idState::idState(
    this: &this->stateRoamSPMoveTo,
    stateType: &idRoamScenePoint_MoveTo::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateRoamSPMoveTo.__vftable = (idRoamScenePoint_MoveTo_vtbl *)&idRoamScenePoint_MoveTo::`vftable';
  idState::idState(
    this: &this->stateRoamSPStayAt,
    stateType: &idRoamScenePoint_StayAt::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateRoamSPStayAt.__vftable = (idRoamScenePoint_StayAt_vtbl *)&idRoamScenePoint_StayAt::`vftable';
  idState::idState(
    this: &this->stateRoamSPSharedWaitForAnimation,
    stateType: &idRoamScenePoint_SharedWaitForAnimation::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateRoamSPSharedWaitForAnimation.__vftable = (idRoamScenePoint_SharedWaitForAnimation_vtbl *)&idRoamScenePoint_SharedWaitForAnimation::`vftable';
  idState::idState(
    this: &this->stateRoamSPSharedFinished,
    stateType: &idRoamScenePoint_SharedFinished::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateRoamSPSharedFinished.__vftable = (idRoamScenePoint_SharedFinished_vtbl *)&idRoamScenePoint_SharedFinished::`vftable';
  idFiniteStateMachine::SetDefaultState(this, state: &this->stateRoamSPFind);
  this->stayTime = -1;
  this->lookTime = -1;
  return this;
}


// ========================================================================
// __unwind$488643
// EA  : 0x82AEE384
// RVA : 0x00AEE384
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

void _unwind_488643()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$488644
// EA  : 0x82AEE3AC
// RVA : 0x00AEE3AC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

void _unwind_488644()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 108));
}


// ========================================================================
// __unwind$488645
// EA  : 0x82AEE3D8
// RVA : 0x00AEE3D8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

void _unwind_488645()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 136));
}


// ========================================================================
// __unwind$488646
// EA  : 0x82AEE404
// RVA : 0x00AEE404
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

void _unwind_488646()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 164));
}


// ========================================================================
// __unwind$488647
// EA  : 0x82AEE430
// RVA : 0x00AEE430
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

void _unwind_488647()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 192));
}


// ========================================================================
// __unwind$488648
// EA  : 0x82AEE45C
// RVA : 0x00AEE45C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

void _unwind_488648()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 220));
}


// ========================================================================
// __unwind$488649
// EA  : 0x82AEE488
// RVA : 0x00AEE488
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

void _unwind_488649()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 248));
}


// ========================================================================
// ??1idRoamScenePointFSM@@UAA@XZ
// EA  : 0x82AEE4C0
// RVA : 0x00AEE4C0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

void __fastcall idRoamScenePointFSM::~idRoamScenePointFSM(idRoamScenePointFSM *this)
{
  this->__vftable = (idRoamScenePointFSM_vtbl *)&idRoamScenePointFSM::`vftable';
  idState::~idState(this: &this->stateRoamSPSharedFinished);
  idState::~idState(this: &this->stateRoamSPSharedWaitForAnimation);
  idState::~idState(this: &this->stateRoamSPStayAt);
  idState::~idState(this: &this->stateRoamSPMoveTo);
  idState::~idState(this: &this->stateRoamSPFind);
  idState::~idState(this: &this->stateRoamSPIdle);
  idFiniteStateMachine::~idFiniteStateMachine(this);
}


// ========================================================================
// __unwind$488766
// EA  : 0x82AEE53C
// RVA : 0x00AEE53C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

void _unwind_488766()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$488767
// EA  : 0x82AEE564
// RVA : 0x00AEE564
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

void _unwind_488767()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 108));
}


// ========================================================================
// __unwind$488768
// EA  : 0x82AEE590
// RVA : 0x00AEE590
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

void _unwind_488768()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 136));
}


// ========================================================================
// __unwind$488769
// EA  : 0x82AEE5BC
// RVA : 0x00AEE5BC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

void _unwind_488769()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 164));
}


// ========================================================================
// __unwind$488770
// EA  : 0x82AEE5E8
// RVA : 0x00AEE5E8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

void _unwind_488770()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 192));
}


// ========================================================================
// __unwind$488771
// EA  : 0x82AEE614
// RVA : 0x00AEE614
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

void _unwind_488771()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 220));
}


// ========================================================================
// ?Evaluate@RoamScenePoint_Shall_FindScenePoint@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEE640
// RVA : 0x00AEE640
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall RoamScenePoint_Shall_FindScenePoint::Evaluate(
        RoamScenePoint_Shall_FindScenePoint *this,
        idAI2 *ai,
        idRoamScenePointFSM *parentFSM,
        idAIState *state,
        int curTime)
{
  idScenePoint **p_curScenePoint; // r24
  idScenePoint_Roam *v9; // r30
  int v10; // r31
  bool v11; // r25
  idRoamScenePointFSM *v12; // r3
  idRoamScenePointFSM *v13; // r26
  bool v14; // r3
  int stayTime; // r11
  int v16; // r11
  idAIMemory *p_memory; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  int lastScenePointSearchTime; // r11
  char v20; // r11
  bool v21; // zf

  if ( !ai->aiEditable.actionSettings.roam.usesRoamScenePoints )
    return 0;
  p_curScenePoint = &ai->aiVolatile.memory.curScenePoint;
  v9 = idScenePoint_Roam::CastTo(c: (idScenePoint_Roam *)ai->aiVolatile.memory.curScenePoint);
  if ( v9 != nullptr )
  {
    v11 = false;
    v12 = idRoamScenePointFSM::CastTo(c: parentFSM);
    v10 = 1;
    v13 = v12;
    if ( (v9->scriptFlags & 1) != 0 )
    {
      v14 = IsScriptScenePointValid(ai, scriptScenePoint: v9);
      v11 = (_cntlzw(v14) & 0x20) != 0;
      LOBYTE(v10) = v9->type == ROAM && v14;
      if ( (_BYTE)v10 != 0 && v13 != nullptr && v9->duration >= 0.0 )
      {
        stayTime = v13->stayTime;
        if ( stayTime >= 0 )
          LOBYTE(v10) = __CFADD__(stayTime - curTime, curTime ^ 0x80000000) ? 0 : v10;
      }
      if ( (_BYTE)v10 != 0 )
        LOBYTE(v10) = (*(_BYTE *)&v9->flags & 8) == 0 ? 0 : v10;
      if ( (_BYTE)v10 != 0
        && (unsigned __int8)idAIMemory::HasOverrideScriptScenePointOfType(this: &ai->aiVolatile.memory, spType: ROAM) != 0 )
      {
        LOBYTE(v10) = 0;
      }
    }
    else
    {
      if ( v12 != nullptr && v9->duration >= 0.0 )
      {
        v16 = v12->stayTime;
        if ( v16 >= 0 )
          v10 = !__CFADD__(v16 - curTime, curTime ^ 0x80000000);
      }
      if ( (_BYTE)v10 != 0 )
        v10 = (*(_BYTE *)&v9->flags & 8) == 0 ? 0 : v10;
      if ( (_BYTE)v10 != 0 )
        v10 = (unsigned __int8)idAIMemory::CheckIfDirtyScenePoint(this: &ai->aiVolatile.memory, dirtyScenePoint: v9) != 0
            ? 0
            : v10;
      if ( (_BYTE)v10 != 0 )
        v10 = !idScenePoint::RequestScenePoint(this: v9, user: ai, curTime) ? 0 : v10;
      if ( (_BYTE)v10 != 0 )
        v10 = (unsigned __int8)idAIMemory::HasOverrideScriptScenePointOfType(this: &ai->aiVolatile.memory, spType: ROAM) != 0
            ? 0
            : v10;
    }
    if ( (_BYTE)v10 == 0 )
    {
      if ( v13 != nullptr )
        v13->stayTime = -1;
      p_memory = &ai->aiVolatile.memory;
      if ( v11 )
        idAIMemory::ClearScenePointHistory(this: p_memory);
      else
        idAIMemory::UpdateScenePointHistory(this: p_memory, scenePoint: v9);
      idScenePoint::ReleaseScenePoint(this: v9, user: ai);
      *p_curScenePoint = nullptr;
      return TRANSCODE_MAX;
    }
    return 0;
  }
  if ( (unsigned __int8)idAIMemory::HasOverrideScriptScenePointOfType(this: &ai->aiVolatile.memory, spType: ROAM) != 0 )
    return TRANSCODE_MAX;
  if ( ai->aiVolatile.memory.scenePointVolumes.num <= 0 )
    return 0;
  lastScenePointSearchTime = ai->aiVolatile.memory.lastScenePointSearchTime;
  if ( lastScenePointSearchTime == 0 || (v21 = curTime <= lastScenePointSearchTime + 2000, v20 = 0, !v21) )
    v20 = 1;
  result = TRANSCODE_MAX;
  if ( v20 == 0 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@RoamScenePoint_Shall_StayAtScenePoint@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEE928
// RVA : 0x00AEE928
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

int __fastcall RoamScenePoint_Shall_StayAtScenePoint::Evaluate(
        RoamScenePoint_Shall_StayAtScenePoint *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idScenePoint *curScenePoint; // r11
  char v8; // r11
  bool v9; // zf
  int v10; // r3
  idScenePoint *v12; // r30
  char *data; // r4
  const char *v14; // r5
  idStr v15[3]; // [sp+60h] [-60h] BYREF

  curScenePoint = ai->aiVolatile.memory.curScenePoint;
  if ( curScenePoint == nullptr || (v9 = curScenePoint->type == ROAM, v8 = 1, !v9) )
    v8 = 0;
  if ( v8 != 0 )
  {
    v10 = ai->aiVolatile.physics.moveState.GetMoveStatus(this: &ai->aiVolatile.physics.moveState);
    if ( v10 == 0 )
      return 456;
    if ( v10 != 1 )
    {
      v12 = ai->aiVolatile.memory.curScenePoint;
      if ( v12 != nullptr )
      {
        data = v12->name.data;
        v14 = aiMoveStatusNames[v10];
        if ( (v12->scriptFlags & 1) != 0 )
          idLib::Warning(fmt: "SCRIPT SCENEPOINT: %s is unreachable! Status: %s Should not happen. Ever! ", data, v14);
        else
          idLib::Warning(fmt: "SCENEPOINT: %s is unreachable. Disabling it for 10 secs. Status: %s ", data, v14);
        v12->currentUser = nullptr;
        v12->requestTime = curTime - (int)(float)((float)1000.0 * (float)-10.0);
        ai->aiVolatile.memory.curScenePoint = nullptr;
      }
      v15[0].len = 0;
      v15[0].baseBuffer[0] = 0;
      v15[0].allocedAndFlag = 20;
      v15[0].data = v15[0].baseBuffer;
      idAI2::GetIdleStateName(this: ai, name: v15);
      idAI2::ChangeAnimState(
        this: ai,
        web: AIANIMWEB_BODY,
        subWeb: ai->aiVolatile.animation.subWeb,
        stateName: v15[0].data,
        interruptPath: INTR_PATH_YES,
        interruptBlend: INTR_BLEND_NO,
        subWebIndex: nullptr,
        stateIndex: nullptr);
      idAIMoveState::Stop(this: &ai->aiVolatile.physics.moveState, newStatus: 0);
      idStr::FreeData(this: v15);
    }
  }
  return 0;
}


// ========================================================================
// __unwind$489170
// EA  : 0x82AEEA98
// RVA : 0x00AEEA98
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

void _unwind_489170()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 192 + 96));
}


// ========================================================================
// ?Evaluate@RoamScenePoint_Shall_LookAtScenePoint@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEEAC0
// RVA : 0x00AEEAC0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall RoamScenePoint_Shall_LookAtScenePoint::Evaluate(
        RoamScenePoint_Shall_LookAtScenePoint *this,
        idAI2 *ai,
        idRoamScenePointFSM *parentFSM,
        idAIState *state,
        int curTime)
{
  idScenePoint **p_curLookScenePoint; // r25
  idScenePoint_Look *v9; // r3
  idScenePoint *v10; // r30
  int v11; // r31
  idRoamScenePointFSM *v12; // r3
  idRoamScenePointFSM *v13; // r27
  int lookTime; // r11
  idPhysics *v15; // r3
  int v16; // r3
  int lastLookScenePointSearchTime; // r11
  char v19; // r11
  bool v20; // zf
  idScenePoint *curScenePoint; // r11
  int v22; // r10
  char v23; // r11
  idPhysics *v24; // r3
  __int64 v25; // r4
  double lookMaxRange; // fp2
  double lookMinRange; // fp1
  idScenePoint *BestScenePoint; // r3
  idScenePoint *v29; // r31
  idRoamScenePointFSM *v30; // r3
  int v31; // r11
  idScenePoint_Roam *v32; // r3
  idScenePoint_Look *NextScenePoint; // r3
  idScenePoint_Look *v34; // r3
  idPhysics *Physics; // r3
  int v36; // r3
  float v37[3]; // [sp+60h] [-50h] BYREF
  char v38; // [sp+6Ch] [-44h]

  if ( !ai->aiEditable.actionSettings.look.usesLookScenePoints )
    return 0;
  p_curLookScenePoint = &ai->aiVolatile.memory.curLookScenePoint;
  v9 = idScenePoint_Look::CastTo(c: (idScenePoint_Look *)ai->aiVolatile.memory.curLookScenePoint);
  v10 = v9;
  if ( v9 == nullptr )
  {
    lastLookScenePointSearchTime = ai->aiVolatile.memory.lastLookScenePointSearchTime;
    if ( lastLookScenePointSearchTime == 0 || (v20 = curTime <= lastLookScenePointSearchTime + 2000, v19 = 0, !v20) )
      v19 = 1;
    if ( v19 == 0 )
      return 0;
    if ( ai->aiVolatile.memory.scenePointVolumes.num <= 0 )
      goto LABEL_34;
    curScenePoint = ai->aiVolatile.memory.curScenePoint;
    if ( curScenePoint == nullptr
      || (*(_BYTE *)&curScenePoint->flags & 8) == 0
      || (v22 = curScenePoint->scriptFlags & 1, v23 = 1, v22 == 0) )
    {
      v23 = 0;
    }
    if ( v23 != 0 )
    {
LABEL_34:
      v32 = idScenePoint_Roam::CastTo(c: (idScenePoint_Roam *)ai->aiVolatile.memory.curScenePoint);
      if ( v32 != nullptr && (v32->scriptFlags & 1) != 0 )
      {
        NextScenePoint = (idScenePoint_Look *)idScenePoint::GetNextScenePoint(this: v32, spTypeRequired: LOOK);
        v34 = idScenePoint_Look::CastTo(c: NextScenePoint);
        v29 = v34;
        if ( v34 != nullptr && (v34->scriptFlags & 1) != 0 && (v34->lookFlags & 1) != 0 )
        {
          Physics = idEntity::GetPhysics(this: ai);
          v36 = (int)Physics->GetOrigin(this: Physics, a2: 0);
          if ( v29->IsInArc_2(this: v29, a2: (const idVec3 *)v36) )
          {
            *p_curLookScenePoint = v29;
            idScenePoint::ActivateScenePoint(this: v29, user: ai, curTime);
            v30 = idRoamScenePointFSM::CastTo(c: parentFSM);
            v31 = (int)(float)(v29->duration * (float)1000.0);
            goto LABEL_41;
          }
        }
      }
    }
    else
    {
      v24 = idEntity::GetPhysics(this: ai);
      v25 = ((__int64 (__fastcall *)(idPhysics *, _DWORD))v24->GetOrigin)(a1: v24, a2: 0);
      v37[0] = *(float *)HIDWORD(v25);
      lookMaxRange = ai->aiEditable.actionSettings.look.lookMaxRange;
      lookMinRange = ai->aiEditable.actionSettings.look.lookMinRange;
      v37[1] = *(float *)(HIDWORD(v25) + 4);
      v37[2] = *(float *)(HIDWORD(v25) + 8);
      v38 = 1;
      BestScenePoint = GetBestScenePoint(
                         ai,
                         minRange: lookMinRange,
                         maxRange: lookMaxRange,
                         _focus: (const idAIPos *)v25,
                         spType: ROAM,
                         lookFlags: (scenePointLookFlags_t)v37);
      v29 = BestScenePoint;
      if ( BestScenePoint != nullptr )
      {
        *p_curLookScenePoint = BestScenePoint;
        idScenePoint::ActivateScenePoint(this: BestScenePoint, user: ai, curTime);
        v30 = idRoamScenePointFSM::CastTo(c: parentFSM);
        v31 = (int)(float)(v29->duration * (float)1000.0);
LABEL_41:
        if ( v31 >= 0 )
          v30->lookTime = v31 + curTime;
        idAI2::SetLookFocusEntity(this: ai, ent: v29, keepFocusInView: false, aimPoint: AIMPOINT_ORIGIN, timeout: -1);
      }
    }
    return 0;
  }
  v11 = v9->type == LOOK;
  if ( v11 != 0 )
    v11 = (*(_BYTE *)&v9->flags & 8) == 0 ? 0 : v11;
  if ( (_BYTE)v11 != 0 )
    v11 = (v9->lookFlags & 1) == 0 ? 0 : v11;
  v12 = idRoamScenePointFSM::CastTo(c: parentFSM);
  v13 = v12;
  if ( (_BYTE)v11 != 0 && v12 != nullptr && v10->duration >= 0.0 )
  {
    lookTime = v12->lookTime;
    if ( lookTime >= 0 )
      v11 = __CFADD__(lookTime - curTime, curTime ^ 0x80000000) ? 0 : v11;
  }
  if ( (_BYTE)v11 != 0 )
    v11 = (unsigned __int8)idAIMemory::CheckIfDirtyLookScenePoint(
                             this: &ai->aiVolatile.memory,
                             dirtyLookScenePoint: v10) != 0
        ? 0
        : v11;
  if ( (_BYTE)v11 != 0 )
    v11 = !idScenePoint::RequestScenePoint(this: v10, user: ai, curTime) ? 0 : v11;
  if ( (_BYTE)v11 != 0 )
  {
    v15 = idEntity::GetPhysics(this: ai);
    v16 = (int)v15->GetOrigin(this: v15, a2: 0);
    v11 = !v10->IsInArc_2(this: v10, a2: (const idVec3 *)v16) ? 0 : v11;
  }
  if ( (_BYTE)v11 != 0 )
    return 0;
  if ( v13 != nullptr )
    v13->lookTime = -1;
  idAI2::ClearLookFocus(this: ai);
  idAIMemory::UpdateLookScenePointHistory(this: &ai->aiVolatile.memory, scenePoint: v10);
  idScenePoint::ReleaseScenePoint(this: v10, user: ai);
  *p_curLookScenePoint = nullptr;
  return 0;
}


// ========================================================================
// ?AIState_EnterState@idRoamScenePoint_StayAt@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AEEEE0
// RVA : 0x00AEEEE0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

void __fastcall idRoamScenePoint_StayAt::AIState_EnterState(
        idRoamScenePoint_StayAt *this,
        idAI2 *ai,
        idRoamScenePointFSM *fsm,
        int curTime)
{
  idScenePoint_Roam *v8; // r31
  idRoamScenePointFSM *v9; // r28
  int v10; // r11
  int v11; // [sp+54h] [-3Ch]

  v8 = idScenePoint_Roam::CastTo(c: (idScenePoint_Roam *)ai->aiVolatile.memory.curScenePoint);
  if ( v8 != nullptr )
  {
    v9 = idRoamScenePointFSM::CastTo(c: fsm);
    if ( v9->stayTime == -1 )
    {
      idScenePoint::ActivateScenePoint(this: v8, user: ai, curTime);
      v11 = (int)(float)(v8->duration * (float)1000.0);
      v10 = v11 + curTime;
      if ( v11 < 0 )
        v10 = 666;
      v9->stayTime = v10;
    }
    if ( v8->scenePointAnimation.len != 0
      && idAI2::PlayAnimWebPath(this: ai, animPath: &v8->scenePointAnimation, forceTransition: false) != 1 )
    {
      idLib::Warning(
        fmt: "ScenePoint %s's animation set was not activatable by AI (no AnimWeb support?) %s",
        v8->name.data,
        ai->name.data);
    }
  }
  else
  {
    idState::SetEnterFailed(this, failed: true);
  }
}


// ========================================================================
// ?CanUse@idRoamScenePointFSM@@UBA_NPAVidFiniteStateMachine@@H@Z
// EA  : 0x82AEF028
// RVA : 0x00AEF028
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.cpp
// ========================================================================

BOOL __fastcall idRoamScenePointFSM::CanUse(idRoamScenePointFSM *this, idFiniteStateMachine *fsm, const int curTime)
{
  idEntity *Owner; // r3
  idAI2 *v4; // r30
  idScenePoint *curScenePoint; // r11
  char v7; // r10
  char v8; // r11
  bool v9; // zf

  Owner = idFiniteStateMachine::GetOwner(this: fsm);
  v4 = (idAI2 *)Owner;
  if ( Owner[13].bindInfo.bindToJoint.baseBuffer[12] == 0 )
    return false;
  if ( (unsigned __int8)idAIMemory::HasOverrideScriptScenePointOfType(
                          this: (idAIMemory *)((char *)&Owner[72].bindInfo + 112),
                          spType: ROAM) != 0 )
    return true;
  curScenePoint = v4->aiVolatile.memory.curScenePoint;
  if ( curScenePoint == nullptr
    || (*(_BYTE *)&curScenePoint->flags & 8) == 0
    || (v7 = 1, (curScenePoint->scriptFlags & 1) == 0) )
  {
    v7 = 0;
  }
  if ( v7 != 0 )
  {
    if ( curScenePoint == nullptr || (v9 = curScenePoint->type == ROAM, v8 = 1, !v9) )
      v8 = 0;
    if ( v8 != 0 )
      return true;
  }
  if ( (unsigned __int8)idAIEditable::idAIActionSettings::HasSquadLeader(this: &v4->aiEditable.actionSettings) != 0 )
    return false;
  return (_cntlzw(idAI2::AwareOfEnemy(this: v4)) & 0x20) != 0;
}

