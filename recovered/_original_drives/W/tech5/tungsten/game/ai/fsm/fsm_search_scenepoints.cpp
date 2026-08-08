
// ========================================================================
// ?InternalInitState@idSearchScenePoint_Find@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AF1E58
// RVA : 0x00AF1E58
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

void __fastcall idSearchScenePoint_Find::InternalInitState(
        idSearchScenePoint_Find *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &SearchScenePoint_Shall_LookAtScenePoint::Type,
    nextStateType: &idSearchScenePoint_Find::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &SearchScenePoint_Shall_MoveToScenePoint::Type,
    nextStateType: &idSearchScenePoint_MoveTo::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &SearchScenePoint_Shall_FindScenePoint::Type,
    nextStateType: &idSearchScenePoint_Find::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &SearchScenePoint_Shall_MoveToPos::Type,
    nextStateType: &idSearchScenePoint_MoveToPos::Type);
}


// ========================================================================
// ?InternalInitState@idSearchScenePoint_MoveTo@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AF1EE0
// RVA : 0x00AF1EE0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

void __fastcall idSearchScenePoint_MoveTo::InternalInitState(
        idSearchScenePoint_MoveTo *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &SearchScenePoint_Shall_LookAtScenePoint::Type,
    nextStateType: &idSearchScenePoint_MoveTo::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &SearchScenePoint_Shall_StayAtScenePoint::Type,
    nextStateType: &idSearchScenePoint_StayAt::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &SearchScenePoint_Shall_FindScenePoint::Type,
    nextStateType: &idSearchScenePoint_Find::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &SearchScenePoint_Shall_MoveToPos::Type,
    nextStateType: &idSearchScenePoint_MoveToPos::Type);
}


// ========================================================================
// ?InternalInitState@idSearchScenePoint_MoveToPos@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AF1F80
// RVA : 0x00AF1F80
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

void __fastcall idSearchScenePoint_MoveToPos::InternalInitState(
        idSearchScenePoint_MoveToPos *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &SearchScenePoint_Shall_LookAtScenePoint::Type,
    nextStateType: &idSearchScenePoint_StayAt::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &SearchScenePoint_Shall_FindScenePoint::Type,
    nextStateType: &idSearchScenePoint_Find::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &SearchScenePoint_Shall_MoveToPos::Type,
    nextStateType: &idSearchScenePoint_MoveToPos::Type);
}


// ========================================================================
// ?InitStates@idSearchScenePointFSM@@UAAXABVidFiniteStateMachineParams@@@Z
// EA  : 0x82AF2000
// RVA : 0x00AF2000
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

void __fastcall idSearchScenePointFSM::InitStates(
        idSearchScenePointFSM *this,
        const idFiniteStateMachineParams *params)
{
  idAIFSM::InitStates(this, params);
  this->AddState(this, a2: &this->stateSearchSPFind);
  this->AddState(this, a2: &this->stateSearchSPMoveTo);
  this->AddState(this, a2: &this->stateSearchSPStayAt);
  this->AddState(this, a2: &this->stateSearchSPMoveToPos);
}


// ========================================================================
// ?Evaluate@SearchScenePoint_Shall_MoveToScenePoint@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AF2090
// RVA : 0x00AF2090
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

int __fastcall SearchScenePoint_Shall_MoveToScenePoint::Evaluate(
        SearchScenePoint_Shall_MoveToScenePoint *this,
        idAI2 *ai,
        idSearchScenePointFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idSearchScenePointFSM *v6; // r28
  idScenePoint **p_curScenePoint; // r29
  idScenePoint_Search *v8; // r3
  idScenePoint *v9; // r31
  float y; // r8
  float z; // r7
  int v12; // r6
  _DWORD v14[16]; // [sp+50h] [-40h] BYREF

  p_curScenePoint = &ai->aiVolatile.memory.curScenePoint;
  v6 = idSearchScenePointFSM::CastTo(c: parentFSM);
  v8 = idScenePoint_Search::CastTo(c: (idScenePoint_Search *)ai->aiVolatile.memory.curScenePoint);
  v9 = v8;
  if ( v8 != nullptr && v6->stayTime == -1 )
  {
    y = ai->aiVolatile.memory.currentEnemySuspectedPos.pos.y;
    z = ai->aiVolatile.memory.currentEnemySuspectedPos.pos.z;
    v12 = *(_DWORD *)&ai->aiVolatile.memory.currentEnemySuspectedPos.bValid;
    v14[0] = LODWORD(ai->aiVolatile.memory.currentEnemySuspectedPos.pos.x);
    *(float *)&v14[1] = y;
    *(float *)&v14[2] = z;
    v14[3] = v12;
    if ( HIBYTE(v12) != 0 && v8->IsInArc_2(this: v8, a2: (const idVec3 *)v14) )
      return 456;
    idAIMemory::UpdateScenePointHistory(this: &ai->aiVolatile.memory, scenePoint: v9);
    idScenePoint::ReleaseScenePoint(this: v9, user: ai);
    *p_curScenePoint = nullptr;
  }
  return 0;
}


// ========================================================================
// ?Evaluate@SearchScenePoint_Shall_MoveToPos@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AF2170
// RVA : 0x00AF2170
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

int __fastcall SearchScenePoint_Shall_MoveToPos::Evaluate(
        SearchScenePoint_Shall_MoveToPos *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idScenePoint *curScenePoint; // r11
  char v7; // r11
  bool v8; // zf
  int v9; // r3
  idStr v11[2]; // [sp+50h] [-50h] BYREF

  curScenePoint = ai->aiVolatile.memory.curScenePoint;
  if ( curScenePoint == nullptr || (v8 = curScenePoint->type == (ROAM|LOOK), v7 = 1, !v8) )
    v7 = 0;
  if ( v7 == 0 )
  {
    v9 = ai->aiVolatile.physics.moveState.GetMoveStatus(this: &ai->aiVolatile.physics.moveState);
    if ( v9 == 0 )
      return 456;
    if ( v9 != 1 )
    {
      v11[0].len = 0;
      v11[0].baseBuffer[0] = 0;
      v11[0].allocedAndFlag = 20;
      v11[0].data = v11[0].baseBuffer;
      idAI2::GetIdleStateName(this: ai, name: v11);
      idAI2::ChangeAnimState(
        this: ai,
        web: AIANIMWEB_BODY,
        subWeb: ai->aiVolatile.animation.subWeb,
        stateName: v11[0].data,
        interruptPath: INTR_PATH_YES,
        interruptBlend: INTR_BLEND_NO,
        subWebIndex: nullptr,
        stateIndex: nullptr);
      idAIMoveState::Stop(this: &ai->aiVolatile.physics.moveState, newStatus: 0);
      idStr::FreeData(this: v11);
    }
  }
  return 0;
}


// ========================================================================
// __unwind$488241
// EA  : 0x82AF225C
// RVA : 0x00AF225C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

void _unwind_488241()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}


// ========================================================================
// ?AIState_EnterState@idSearchScenePoint_Find@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AF2288
// RVA : 0x00AF2288
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

void __fastcall idSearchScenePoint_Find::AIState_EnterState(
        idSearchScenePoint_Find *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idScenePoint *BestScenePoint; // r3

  BestScenePoint = GetBestScenePoint(
                     ai,
                     minRange: ai->aiEditable.actionSettings.search.searchMinRange,
                     maxRange: ai->aiEditable.actionSettings.search.searchMaxRange,
                     _focus: (const idAIPos *)ai,
                     spType: (scenePointType_t)fsm,
                     lookFlags: (scenePointLookFlags_t)&ai->aiVolatile.memory.currentEnemySuspectedPos);
  if ( BestScenePoint != nullptr )
    ai->aiVolatile.memory.curScenePoint = BestScenePoint;
  else
    idState::SetEnterFailed(this, failed: true);
}


// ========================================================================
// ?AIState_ReenterState@idSearchScenePoint_Find@@UAAXPAVidAI2@@PAVidAIFSM@@HH@Z
// EA  : 0x82AF2300
// RVA : 0x00AF2300
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

void __fastcall idSearchScenePoint_Find::AIState_ReenterState(
        idSearchScenePoint_Find *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int transCode,
        const int curTime)
{
  idScenePoint **p_curScenePoint; // r31
  idScenePoint *BestScenePoint; // r3

  p_curScenePoint = &ai->aiVolatile.memory.curScenePoint;
  if ( ai->aiVolatile.memory.curScenePoint == nullptr )
  {
    BestScenePoint = GetBestScenePoint(
                       ai,
                       minRange: ai->aiEditable.actionSettings.search.searchMinRange,
                       maxRange: ai->aiEditable.actionSettings.search.searchMaxRange,
                       _focus: (const idAIPos *)ai,
                       spType: (scenePointType_t)fsm,
                       lookFlags: (scenePointLookFlags_t)&ai->aiVolatile.memory.currentEnemySuspectedPos);
    if ( BestScenePoint != nullptr )
      *p_curScenePoint = BestScenePoint;
    else
      idState::SetEnterFailed(this, failed: true);
  }
}


// ========================================================================
// ?AIState_EnterState@idSearchScenePoint_MoveTo@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AF2380
// RVA : 0x00AF2380
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

void __fastcall idSearchScenePoint_MoveTo::AIState_EnterState(
        idSearchScenePoint_MoveTo *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  idScenePoint **p_curScenePoint; // r27
  idScenePoint_Search *v8; // r3
  idScenePoint *v9; // r30
  float y; // r8
  float z; // r7
  int v12; // r6
  void (__fastcall *SetWalkState)(struct idAI2 *, const walkState_t); // r7
  double duration; // fp0
  double radius; // fp13
  idEventArg *v16; // r30
  idEventArg *v17; // r31
  const idEventArg *v18; // [sp+8h] [-2A8h]
  const idEventArg *v19; // [sp+Ch] [-2A4h]
  const idEventArg *v20; // [sp+10h] [-2A0h]
  _BYTE v21[20]; // [sp+70h] [-240h] BYREF
  _BYTE v22[20]; // [sp+90h] [-220h] BYREF
  _BYTE v23[20]; // [sp+B0h] [-200h] BYREF
  _BYTE v24[20]; // [sp+D0h] [-1E0h] BYREF
  _BYTE v25[20]; // [sp+F0h] [-1C0h] BYREF
  _BYTE v26[20]; // [sp+110h] [-1A0h] BYREF
  float v27[5]; // [sp+130h] [-180h] BYREF
  idVec3 v28; // [sp+150h] [-160h] BYREF
  int v29; // [sp+15Ch] [-154h]
  float v30[5]; // [sp+160h] [-150h] BYREF
  _DWORD v31[5]; // [sp+180h] [-130h] BYREF
  _DWORD v32[5]; // [sp+1A0h] [-110h] BYREF
  int v33; // [sp+1C0h] [-F0h]
  int v34; // [sp+1C4h] [-ECh]
  const idEventArg *v35; // [sp+1C8h] [-E8h]
  const idEventArg *v36; // [sp+1CCh] [-E4h]
  _DWORD v37[5]; // [sp+1E0h] [-D0h] BYREF
  idEventArg v38; // [sp+200h] [-B0h] BYREF
  idEventArg v39; // [sp+220h] [-90h] BYREF
  idEventReceiver v40[9]; // [sp+240h] [-70h] BYREF

  p_curScenePoint = &ai->aiVolatile.memory.curScenePoint;
  v8 = idScenePoint_Search::CastTo(c: (idScenePoint_Search *)ai->aiVolatile.memory.curScenePoint);
  v9 = v8;
  y = ai->aiVolatile.memory.currentEnemySuspectedPos.pos.y;
  z = ai->aiVolatile.memory.currentEnemySuspectedPos.pos.z;
  v12 = *(_DWORD *)&ai->aiVolatile.memory.currentEnemySuspectedPos.bValid;
  v28.x = ai->aiVolatile.memory.currentEnemySuspectedPos.pos.x;
  v28.y = y;
  v28.z = z;
  v29 = v12;
  if ( v8 != nullptr && HIBYTE(v29) != 0 && v8->IsInArc_2(this: v8, a2: &v28) )
  {
    SetWalkState = ai->SetWalkState;
    ai->aiVolatile.animation.subWeb = AISUBWEB_COMBAT;
    SetWalkState(this: ai, a2: WALKSTATE_WALKING);
    idAI2::SetEnableHeadTracking(this: ai, enable: true);
    idAI2::EndActionScript(this: ai);
    LODWORD(fsm[1].value.v[2]) = this;
    duration = v9->duration;
    HIBYTE(v37[0]) = 105;
    v37[1] = 0;
    HIBYTE(v27[0]) = 118;
    v27[1] = vec3_origin.x;
    v27[2] = vec3_origin.y;
    v27[3] = vec3_origin.z;
    radius = v9->radius;
    HIBYTE(v32[0]) = 105;
    HIBYTE(v30[0]) = 102;
    v32[1] = (_cntlzw(duration == 0.0) & 0x20) != 0;
    v30[1] = (float)radius * (float)0.5;
    HIBYTE(v31[0]) = 105;
    HIBYTE(v33) = 105;
    v34 = 35;
    v31[1] = v32[1] + 1;
    v16 = idEventArg::idEventArg(this: &v38, data: v9);
    v17 = idEventArg::idEventArg(this: &v39, data: ai);
    memcpy(Dst: v26, Src: v37, Size: sizeof(v26));
    memcpy(Dst: v25, Src: v27, Size: sizeof(v25));
    memcpy(Dst: v24, Src: v32, Size: sizeof(v24));
    memcpy(Dst: v23, Src: v30, Size: sizeof(v23));
    memcpy(Dst: v22, Src: v31, Size: sizeof(v22));
    memcpy(Dst: v21, Src: v16, Size: sizeof(v21));
    idEventReceiver::ProcessEvent(
      this: v40,
      result: fsm,
      ev: *(const idEventDef **)&v17->type,
      arg1: (const idEventArg *)LODWORD(v17->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v17->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(v33, 32),
      arg4: v35,
      arg5: v36,
      arg6: v18,
      arg7: v19,
      arg8: v20);
  }
  else
  {
    idState::SetEnterFailed(this, failed: true);
    if ( v9 != nullptr )
    {
      idAIMemory::UpdateScenePointHistory(this: &ai->aiVolatile.memory, scenePoint: v9);
      idScenePoint::ReleaseScenePoint(this: v9, user: ai);
      *p_curScenePoint = nullptr;
    }
  }
}


// ========================================================================
// ?AIState_ExitState@idSearchScenePoint_StayAt@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AF2618
// RVA : 0x00AF2618
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

void __fastcall idSearchScenePoint_StayAt::AIState_ExitState(
        idSearchScenePoint_StayAt *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  idScenePoint **p_curScenePoint; // r30
  idScenePoint_Search *curScenePoint; // r3
  idScenePoint_Search *v10; // r3
  idScenePoint *v11; // r29
  posture_t (__fastcall *GetPosture)(struct idAI2 *); // r7
  idEventArg *v13; // r3
  idEventArg v14; // [sp+50h] [-70h] BYREF
  idEventReceiver v15[6]; // [sp+70h] [-50h] BYREF

  p_curScenePoint = &ai->aiVolatile.memory.curScenePoint;
  curScenePoint = (idScenePoint_Search *)ai->aiVolatile.memory.curScenePoint;
  if ( curScenePoint != nullptr )
  {
    v10 = idScenePoint_Search::CastTo(c: curScenePoint);
    v11 = v10;
    if ( v10 != nullptr )
    {
      idAIMemory::UpdateScenePointHistory(this: &ai->aiVolatile.memory, scenePoint: v10);
      idScenePoint::ReleaseScenePoint(this: v11, user: ai);
      *p_curScenePoint = nullptr;
    }
  }
  GetPosture = ai->GetPosture;
  ai->aiVolatile.animation.subWeb = AISUBWEB_COMBAT;
  if ( GetPosture(this: ai) == POSTURE_CROUCHED )
  {
    v13 = idEventArg::idEventArg(this: &v14, data: ai);
    idEventReceiver::ProcessEvent(
      this: v15,
      result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
      ev: *(const idEventDef **)&v13->type,
      arg1: (const idEventArg *)LODWORD(v13->value.v[1]));
    idAIState::StartQueuedActions(this, ai, parentFSM: fsm, curTime);
  }
  idAI2::SetEnableHeadTracking(this: ai, enable: true);
  idAI2::ClearAimFocus(this: ai);
  idAI2::ClearLookFocus(this: ai);
}


// ========================================================================
// ??0idSearchScenePointFSM@@QAA@XZ
// EA  : 0x82AF2720
// RVA : 0x00AF2720
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

idSearchScenePointFSM *__fastcall idSearchScenePointFSM::idSearchScenePointFSM(idSearchScenePointFSM *this)
{
  idFiniteStateMachine::idFiniteStateMachine(this, name: "FSM_SearchScenePoint");
  this->__vftable = (idSearchScenePointFSM_vtbl *)&idSearchScenePointFSM::`vftable';
  idState::idState(
    this: &this->stateSearchSPFind,
    stateType: &idSearchScenePoint_Find::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateSearchSPFind.__vftable = (idSearchScenePoint_Find_vtbl *)&idSearchScenePoint_Find::`vftable';
  idState::idState(
    this: &this->stateSearchSPMoveTo,
    stateType: &idSearchScenePoint_MoveTo::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateSearchSPMoveTo.__vftable = (idSearchScenePoint_MoveTo_vtbl *)&idSearchScenePoint_MoveTo::`vftable';
  idState::idState(
    this: &this->stateSearchSPStayAt,
    stateType: &idSearchScenePoint_StayAt::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateSearchSPStayAt.__vftable = (idSearchScenePoint_StayAt_vtbl *)&idSearchScenePoint_StayAt::`vftable';
  idState::idState(
    this: &this->stateSearchSPMoveToPos,
    stateType: &idSearchScenePoint_MoveToPos::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateSearchSPMoveToPos.__vftable = (idSearchScenePoint_MoveToPos_vtbl *)&idSearchScenePoint_MoveToPos::`vftable';
  idFiniteStateMachine::SetDefaultState(this, state: &this->stateSearchSPFind);
  this->stayTime = -1;
  this->lookTime = -1;
  return this;
}


// ========================================================================
// __unwind$488768_0
// EA  : 0x82AF280C
// RVA : 0x00AF280C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

void _unwind_488768_0()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$488769_0
// EA  : 0x82AF2834
// RVA : 0x00AF2834
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

void _unwind_488769_0()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 108));
}


// ========================================================================
// __unwind$488770_0
// EA  : 0x82AF2860
// RVA : 0x00AF2860
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

void _unwind_488770_0()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 136));
}


// ========================================================================
// __unwind$488771_0
// EA  : 0x82AF288C
// RVA : 0x00AF288C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

void _unwind_488771_0()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 164));
}


// ========================================================================
// __unwind$488772
// EA  : 0x82AF28B8
// RVA : 0x00AF28B8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

void _unwind_488772()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 192));
}


// ========================================================================
// ??1idSearchScenePointFSM@@UAA@XZ
// EA  : 0x82AF28F0
// RVA : 0x00AF28F0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

void __fastcall idSearchScenePointFSM::~idSearchScenePointFSM(idSearchScenePointFSM *this)
{
  this->__vftable = (idSearchScenePointFSM_vtbl *)&idSearchScenePointFSM::`vftable';
  idState::~idState(this: &this->stateSearchSPMoveToPos);
  idState::~idState(this: &this->stateSearchSPStayAt);
  idState::~idState(this: &this->stateSearchSPMoveTo);
  idState::~idState(this: &this->stateSearchSPFind);
  idFiniteStateMachine::~idFiniteStateMachine(this);
}


// ========================================================================
// __unwind$488857
// EA  : 0x82AF295C
// RVA : 0x00AF295C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

void _unwind_488857()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$488858
// EA  : 0x82AF2984
// RVA : 0x00AF2984
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

void _unwind_488858()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 108));
}


// ========================================================================
// __unwind$488859
// EA  : 0x82AF29B0
// RVA : 0x00AF29B0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

void _unwind_488859()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 136));
}


// ========================================================================
// __unwind$488860
// EA  : 0x82AF29DC
// RVA : 0x00AF29DC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

void _unwind_488860()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 164));
}


// ========================================================================
// ?CanUse@idSearchScenePointFSM@@UBA_NPAVidFiniteStateMachine@@H@Z
// EA  : 0x82AF2A08
// RVA : 0x00AF2A08
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

BOOL __fastcall idSearchScenePointFSM::CanUse(
        idSearchScenePointFSM *this,
        idFiniteStateMachine *fsm,
        const int curTime)
{
  idAI2 *Owner; // r3
  idAI2 *v5; // r31
  const aiSenseState_t *EnemySenseState; // r3
  int lastConfirmedStimTime; // r11
  int v8; // r11
  BOOL result; // r3

  Owner = (idAI2 *)idFiniteStateMachine::GetOwner(this: fsm);
  v5 = Owner;
  result = false;
  if ( Owner->aiEditable.perception.combatTimeoutInterval >= 0.0 )
  {
    EnemySenseState = idAI2::GetEnemySenseState(this: Owner, senseType: AISENSE_MAX);
    if ( EnemySenseState != nullptr )
    {
      lastConfirmedStimTime = EnemySenseState->lastConfirmedStimTime;
      if ( lastConfirmedStimTime > 0 )
      {
        v8 = curTime - lastConfirmedStimTime;
        if ( v8 > (int)(float)(v5->aiEditable.perception.combatTimeoutInterval * (float)1000.0)
          && (v5->aiEditable.perception.searchTimeoutInterval < 0.0
           || v8 <= (int)(float)((float)(v5->aiEditable.perception.searchTimeoutInterval
                                       + v5->aiEditable.perception.combatTimeoutInterval)
                               * (float)1000.0)) )
        {
          return true;
        }
      }
    }
  }
  return result;
}


// ========================================================================
// ?Evaluate@SearchScenePoint_Shall_FindScenePoint@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AF2AD8
// RVA : 0x00AF2AD8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall SearchScenePoint_Shall_FindScenePoint::Evaluate(
        SearchScenePoint_Shall_FindScenePoint *this,
        idAI2 *ai,
        idSearchScenePointFSM *parentFSM,
        idAIState *state,
        int curTime)
{
  idScenePoint **p_curScenePoint; // r24
  idScenePoint_Search *v9; // r30
  int v10; // r31
  bool v11; // r25
  idSearchScenePointFSM *v12; // r3
  idSearchScenePointFSM *v13; // r26
  bool v14; // r3
  int stayTime; // r11
  int v16; // r11
  idAIMemory *p_memory; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  int lastScenePointSearchTime; // r11
  char v20; // r11
  bool v21; // zf

  if ( !ai->aiEditable.actionSettings.search.usesSearchScenePoints )
    return 0;
  p_curScenePoint = &ai->aiVolatile.memory.curScenePoint;
  v9 = idScenePoint_Search::CastTo(c: (idScenePoint_Search *)ai->aiVolatile.memory.curScenePoint);
  if ( v9 != nullptr )
  {
    v11 = false;
    v12 = idSearchScenePointFSM::CastTo(c: parentFSM);
    v10 = 1;
    v13 = v12;
    if ( (v9->scriptFlags & 1) != 0 )
    {
      v14 = IsScriptScenePointValid(ai, scriptScenePoint: v9);
      v11 = (_cntlzw(v14) & 0x20) != 0;
      LOBYTE(v10) = v9->type == (ROAM|LOOK) && v14;
      if ( (_BYTE)v10 != 0 && v13 != nullptr && v9->duration >= 0.0 )
      {
        stayTime = v13->stayTime;
        if ( stayTime >= 0 )
          LOBYTE(v10) = __CFADD__(stayTime - curTime, curTime ^ 0x80000000) ? 0 : v10;
      }
      if ( (_BYTE)v10 != 0 )
        LOBYTE(v10) = (*(_BYTE *)&v9->flags & 8) == 0 ? 0 : v10;
      if ( (_BYTE)v10 != 0
        && (unsigned __int8)idAIMemory::HasOverrideScriptScenePointOfType(
                              this: &ai->aiVolatile.memory,
                              spType: ROAM|LOOK) != 0 )
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
        v10 = (unsigned __int8)idAIMemory::HasOverrideScriptScenePointOfType(
                                 this: &ai->aiVolatile.memory,
                                 spType: ROAM|LOOK) != 0
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
  if ( (unsigned __int8)idAIMemory::HasOverrideScriptScenePointOfType(this: &ai->aiVolatile.memory, spType: ROAM|LOOK) != 0 )
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
// ?Evaluate@SearchScenePoint_Shall_StayAtScenePoint@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AF2DC0
// RVA : 0x00AF2DC0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

int __fastcall SearchScenePoint_Shall_StayAtScenePoint::Evaluate(
        SearchScenePoint_Shall_StayAtScenePoint *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  idScenePoint **p_curScenePoint; // r26
  idScenePoint_Search *v8; // r29
  int v9; // r27
  float y; // r6
  float z; // r5
  int v12; // r4
  idScenePoint *v14; // r28
  char *data; // r4
  const char *v16; // r5
  idStr *v17; // r3
  _DWORD v18[4]; // [sp+60h] [-A0h] BYREF
  idStr v19; // [sp+70h] [-90h] BYREF
  idStr v20[3]; // [sp+90h] [-70h] BYREF

  p_curScenePoint = &ai->aiVolatile.memory.curScenePoint;
  v8 = idScenePoint_Search::CastTo(c: (idScenePoint_Search *)ai->aiVolatile.memory.curScenePoint);
  if ( v8 == nullptr )
    return 0;
  v9 = ai->aiVolatile.physics.moveState.GetMoveStatus(this: &ai->aiVolatile.physics.moveState);
  y = ai->aiVolatile.memory.currentEnemySuspectedPos.pos.y;
  z = ai->aiVolatile.memory.currentEnemySuspectedPos.pos.z;
  v12 = *(_DWORD *)&ai->aiVolatile.memory.currentEnemySuspectedPos.bValid;
  v18[0] = LODWORD(ai->aiVolatile.memory.currentEnemySuspectedPos.pos.x);
  *(float *)&v18[1] = y;
  *(float *)&v18[2] = z;
  v18[3] = v12;
  if ( HIBYTE(v12) != 0 && v8->IsInArc_2(this: v8, a2: (const idVec3 *)v18) )
  {
    if ( v9 == 0 )
      return 456;
    if ( v9 != 1 )
    {
      v14 = *p_curScenePoint;
      if ( *p_curScenePoint != nullptr )
      {
        data = v14->name.data;
        v16 = aiMoveStatusNames[v9];
        if ( (v14->scriptFlags & 1) != 0 )
          idLib::Warning(fmt: "SCRIPT SCENEPOINT: %s is unreachable! Status: %s Should not happen. Ever! ", data, v16);
        else
          idLib::Warning(fmt: "SCENEPOINT: %s is unreachable! Status: %s ", data, v16);
        v14->currentUser = nullptr;
        v14->requestTime = curTime - (int)(float)((float)1000.0 * (float)-10.0);
        *p_curScenePoint = nullptr;
      }
      v19.len = 0;
      v19.baseBuffer[0] = 0;
      v19.allocedAndFlag = 20;
      v19.data = v19.baseBuffer;
      idAI2::GetIdleStateName(this: ai, name: &v19);
      idAI2::ChangeAnimState(
        this: ai,
        web: AIANIMWEB_BODY,
        subWeb: ai->aiVolatile.animation.subWeb,
        stateName: v19.data,
        interruptPath: INTR_PATH_YES,
        interruptBlend: INTR_BLEND_NO,
        subWebIndex: nullptr,
        stateIndex: nullptr);
      idAIMoveState::Stop(this: &ai->aiVolatile.physics.moveState, newStatus: 0);
      v17 = &v19;
      goto LABEL_15;
    }
  }
  else
  {
    idAIMemory::UpdateScenePointHistory(this: &ai->aiVolatile.memory, scenePoint: v8);
    idScenePoint::ReleaseScenePoint(this: v8, user: ai);
    *p_curScenePoint = nullptr;
    if ( v9 != 1 )
    {
      v20[0].len = 0;
      v20[0].baseBuffer[0] = 0;
      v20[0].allocedAndFlag = 20;
      v20[0].data = v20[0].baseBuffer;
      idAI2::GetIdleStateName(this: ai, name: v20);
      idAI2::ChangeAnimState(
        this: ai,
        web: AIANIMWEB_BODY,
        subWeb: ai->aiVolatile.animation.subWeb,
        stateName: v20[0].data,
        interruptPath: INTR_PATH_YES,
        interruptBlend: INTR_BLEND_NO,
        subWebIndex: nullptr,
        stateIndex: nullptr);
      idAIMoveState::Stop(this: &ai->aiVolatile.physics.moveState, newStatus: 0);
      v17 = v20;
LABEL_15:
      idStr::FreeData(this: v17);
    }
  }
  return 0;
}


// ========================================================================
// __unwind$489242
// EA  : 0x82AF3000
// RVA : 0x00AF3000
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

void _unwind_489242()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 112));
}


// ========================================================================
// __unwind$489241
// EA  : 0x82AF3028
// RVA : 0x00AF3028
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

void _unwind_489241()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 256 + 144));
}


// ========================================================================
// ?Evaluate@SearchScenePoint_Shall_LookAtScenePoint@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AF3050
// RVA : 0x00AF3050
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall SearchScenePoint_Shall_LookAtScenePoint::Evaluate(
        SearchScenePoint_Shall_LookAtScenePoint *this,
        idAI2 *ai,
        idSearchScenePointFSM *parentFSM,
        idAIState *state,
        int curTime)
{
  idScenePoint **p_curLookScenePoint; // r25
  idScenePoint_Look *v9; // r3
  idScenePoint *v10; // r30
  int v11; // r31
  idSearchScenePointFSM *v12; // r3
  idSearchScenePointFSM *v13; // r27
  int lookTime; // r11
  idPhysics *v15; // r3
  int v16; // r3
  int lastLookScenePointSearchTime; // r11
  char v19; // r11
  bool v20; // zf
  idPhysics *Physics; // r3
  __int64 v22; // r4
  double lookMaxRange; // fp2
  double lookMinRange; // fp1
  idScenePoint *BestScenePoint; // r3
  idScenePoint *v26; // r31
  idSearchScenePointFSM *v27; // r3
  double v28; // fp12
  float v29[3]; // [sp+60h] [-50h] BYREF
  char v30; // [sp+6Ch] [-44h]

  if ( !ai->aiEditable.actionSettings.look.usesLookScenePoints )
    return 0;
  p_curLookScenePoint = &ai->aiVolatile.memory.curLookScenePoint;
  v9 = idScenePoint_Look::CastTo(c: (idScenePoint_Look *)ai->aiVolatile.memory.curLookScenePoint);
  v10 = v9;
  if ( v9 == nullptr )
  {
    if ( ai->aiVolatile.memory.scenePointVolumes.num > 0 )
    {
      lastLookScenePointSearchTime = ai->aiVolatile.memory.lastLookScenePointSearchTime;
      if ( lastLookScenePointSearchTime == 0 || (v20 = curTime <= lastLookScenePointSearchTime + 2000, v19 = 0, !v20) )
        v19 = 1;
      if ( v19 != 0 )
      {
        Physics = idEntity::GetPhysics(this: ai);
        v22 = ((__int64 (__fastcall *)(idPhysics *, _DWORD))Physics->GetOrigin)(a1: Physics, a2: 0);
        v29[0] = *(float *)HIDWORD(v22);
        lookMaxRange = ai->aiEditable.actionSettings.look.lookMaxRange;
        lookMinRange = ai->aiEditable.actionSettings.look.lookMinRange;
        v29[1] = *(float *)(HIDWORD(v22) + 4);
        v29[2] = *(float *)(HIDWORD(v22) + 8);
        v30 = 1;
        BestScenePoint = GetBestScenePoint(
                           ai,
                           minRange: lookMinRange,
                           maxRange: lookMaxRange,
                           _focus: (const idAIPos *)v22,
                           spType: ROAM,
                           lookFlags: (scenePointLookFlags_t)v29);
        v26 = BestScenePoint;
        if ( BestScenePoint != nullptr )
        {
          *p_curLookScenePoint = BestScenePoint;
          v27 = idSearchScenePointFSM::CastTo(c: parentFSM);
          v28 = (float)(v26->duration * (float)1000.0);
          if ( (int)v28 >= 0 )
            v27->lookTime = (int)v28 + curTime;
          idAI2::SetLookFocusEntity(this: ai, ent: v26, keepFocusInView: true, aimPoint: AIMPOINT_ORIGIN, timeout: -1);
        }
      }
    }
    return 0;
  }
  v11 = v9->type == LOOK;
  if ( v11 != 0 )
    v11 = (*(_BYTE *)&v9->flags & 8) == 0 ? 0 : v11;
  if ( (_BYTE)v11 != 0 )
    v11 = (v9->lookFlags & 2) == 0 ? 0 : v11;
  v12 = idSearchScenePointFSM::CastTo(c: parentFSM);
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
// ?AIState_EnterState@idSearchScenePoint_StayAt@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AF3348
// RVA : 0x00AF3348
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

void __fastcall idSearchScenePoint_StayAt::AIState_EnterState(
        idSearchScenePoint_StayAt *this,
        idAI2 *ai,
        idSearchScenePointFSM *fsm,
        int curTime)
{
  idScenePoint_Search *v8; // r30
  idSearchScenePointFSM *v9; // r28
  int v10; // r11
  idPhysics *Physics; // r3
  float *v12; // r29
  const idVec3 *v13; // r3
  double v14; // fp6
  double v15; // fp5
  double v16; // fp13
  double x; // fp3
  double y; // fp2
  int v19; // [sp+54h] [-5Ch]
  idVec3 v20; // [sp+58h] [-58h] BYREF
  char v21; // [sp+68h] [-48h] BYREF

  v8 = idScenePoint_Search::CastTo(c: (idScenePoint_Search *)ai->aiVolatile.memory.curScenePoint);
  if ( v8 != nullptr )
  {
    v9 = idSearchScenePointFSM::CastTo(c: fsm);
    if ( v9->stayTime == -1 )
    {
      idScenePoint::ActivateScenePoint(this: v8, user: ai, curTime);
      v19 = (int)(float)(v8->duration * 1000.0);
      v10 = v19 + curTime;
      if ( v19 < 0 )
        v10 = 666;
      v9->stayTime = v10;
    }
    if ( v8->duration != 0.0 && ai->aiVolatile.memory.curLookScenePoint == nullptr )
    {
      idAI2::SetEnableHeadTracking(this: ai, enable: true);
      idAI2::ClearAimFocus(this: ai);
      idAI2::ClearLookFocus(this: ai);
      Physics = idEntity::GetPhysics(this: ai);
      v12 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v13 = ai->GetEyeOffset(this: &v21, result: ai);
      v14 = (float)(v13->z + v12[2]);
      v15 = (float)(v13->y + v12[1]);
      v16 = (float)(v13->x + *v12);
      v20.x = v13->x + *v12;
      v20.z = v14;
      v20.y = v15;
      x = v8->arcDir.x;
      y = v8->arcDir.y;
      v20.z = (float)(v8->arcDir.z * (float)100.0) + (float)v14;
      v20.y = (float)((float)y * (float)100.0) + (float)v15;
      v20.x = (float)((float)x * (float)100.0) + (float)v16;
      idAI2::SetIdealLookFocusPoint(this: ai, point: &v20, timeout: (int)1000.0, focusType: AIFOCUS_LOOK_AROUND);
    }
  }
  else
  {
    idState::SetEnterFailed(this, failed: true);
  }
}


// ========================================================================
// ?AIState_EnterState@idSearchScenePoint_MoveToPos@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AF3570
// RVA : 0x00AF3570
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

void __fastcall idSearchScenePoint_MoveToPos::AIState_EnterState(
        idSearchScenePoint_MoveToPos *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  int value; // r8
  idEntity *v9; // r3
  idEntity *v10; // r29
  void (__fastcall *SetWalkState)(struct idAI2 *, const walkState_t); // r7
  idEventArg *v12; // r3
  idEventArg *v13; // r19
  idEventArg *v14; // r18
  const idEventArg *v15; // [sp+8h] [-2B8h]
  const idEventArg *v16; // [sp+Ch] [-2B4h]
  const idEventArg *v17; // [sp+10h] [-2B0h]
  _BYTE v18[20]; // [sp+70h] [-250h] BYREF
  _BYTE v19[20]; // [sp+90h] [-230h] BYREF
  _BYTE v20[20]; // [sp+B0h] [-210h] BYREF
  _BYTE v21[20]; // [sp+D0h] [-1F0h] BYREF
  _BYTE v22[20]; // [sp+F0h] [-1D0h] BYREF
  _BYTE v23[20]; // [sp+110h] [-1B0h] BYREF
  float v24[5]; // [sp+130h] [-190h] BYREF
  idEventReceiver v25[2]; // [sp+150h] [-170h] BYREF
  idEventArg v26; // [sp+170h] [-150h] BYREF
  _DWORD v27[5]; // [sp+190h] [-130h] BYREF
  _DWORD v28[5]; // [sp+1B0h] [-110h] BYREF
  float v29[5]; // [sp+1D0h] [-F0h] BYREF
  idEventArg v30; // [sp+1F0h] [-D0h] BYREF
  idEventArg v31; // [sp+210h] [-B0h] BYREF
  idEventReceiver v32[12]; // [sp+230h] [-90h] BYREF

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v9 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v9 != nullptr )
    {
      v10 = idEntity::CastTo(c: v9);
      if ( v10 != nullptr )
      {
        SetWalkState = ai->SetWalkState;
        ai->aiVolatile.animation.subWeb = AISUBWEB_COMBAT;
        SetWalkState(this: ai, a2: WALKSTATE_WALKING);
        if ( ai->GetPosture(this: ai) == POSTURE_CROUCHED )
        {
          v12 = idEventArg::idEventArg(this: &v26, data: ai);
          idEventReceiver::ProcessEvent(
            this: v25,
            result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
            ev: *(const idEventDef **)&v12->type,
            arg1: (const idEventArg *)LODWORD(v12->value.v[1]));
        }
        v29[1] = ai->aiEditable.actionSettings.close.closeMinRange;
        HIBYTE(v28[0]) = 105;
        HIBYTE(v27[0]) = 105;
        v24[1] = vec3_origin.x;
        v24[2] = vec3_origin.y;
        v28[1] = 0;
        v24[3] = vec3_origin.z;
        HIBYTE(v24[0]) = 118;
        v27[1] = 0;
        HIBYTE(v29[0]) = 102;
        HIBYTE(v25[0].__vftable) = 105;
        v25[0].listenerList = (idList<idEventReceiver *,5> *)2;
        v26.type = 105;
        v26.value.i = 0;
        v13 = idEventArg::idEventArg(this: &v30, data: v10);
        v14 = idEventArg::idEventArg(this: &v31, data: ai);
        memcpy(Dst: v23, Src: v28, Size: sizeof(v23));
        memcpy(Dst: v22, Src: v24, Size: sizeof(v22));
        memcpy(Dst: v21, Src: v27, Size: sizeof(v21));
        memcpy(Dst: v20, Src: v29, Size: sizeof(v20));
        memcpy(Dst: v19, Src: v25, Size: sizeof(v19));
        memcpy(Dst: v18, Src: v13, Size: sizeof(v18));
        idEventReceiver::ProcessEvent(
          this: v32,
          result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
          ev: *(const idEventDef **)&v14->type,
          arg1: (const idEventArg *)LODWORD(v14->value.v[1]),
          arg2: (const idEventArg *)LODWORD(v14->value.v[2]),
          arg3: (const idEventArg *)__ROL4__(*(_DWORD *)&v26.type, 32),
          arg4: (const idEventArg *)LODWORD(v26.value.v[1]),
          arg5: (const idEventArg *)LODWORD(v26.value.v[2]),
          arg6: v15,
          arg7: v16,
          arg8: v17);
        idAIState::StartQueuedActions(this, ai, parentFSM: fsm, curTime);
        idAI2::SetAimFocusEntity(this: ai, ent: v10, keepFocusInView: false, aimPoint: AIMPOINT_BEST, timeout: -1);
        idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_FIREWHENREADY);
      }
    }
  }
}


// ========================================================================
// ?AIState_ReenterState@idSearchScenePoint_MoveToPos@@UAAXPAVidAI2@@PAVidAIFSM@@HH@Z
// EA  : 0x82AF37E0
// RVA : 0x00AF37E0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

void __fastcall idSearchScenePoint_MoveToPos::AIState_ReenterState(
        idSearchScenePoint_MoveToPos *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int transCode,
        int curTime)
{
  int value; // r8
  idEntity *v10; // r3
  idEntity *v11; // r29
  void (__fastcall *SetWalkState)(struct idAI2 *, const walkState_t); // r7
  idEventArg *v13; // r3
  idEventArg *v14; // r19
  idEventArg *v15; // r18
  const idEventArg *v16; // [sp+8h] [-2B8h]
  const idEventArg *v17; // [sp+Ch] [-2B4h]
  const idEventArg *v18; // [sp+10h] [-2B0h]
  _BYTE v19[20]; // [sp+70h] [-250h] BYREF
  _BYTE v20[20]; // [sp+90h] [-230h] BYREF
  _BYTE v21[20]; // [sp+B0h] [-210h] BYREF
  _BYTE v22[20]; // [sp+D0h] [-1F0h] BYREF
  _BYTE v23[20]; // [sp+F0h] [-1D0h] BYREF
  _BYTE v24[20]; // [sp+110h] [-1B0h] BYREF
  float v25[5]; // [sp+130h] [-190h] BYREF
  idEventReceiver v26[2]; // [sp+150h] [-170h] BYREF
  idEventArg v27; // [sp+170h] [-150h] BYREF
  _DWORD v28[5]; // [sp+190h] [-130h] BYREF
  _DWORD v29[5]; // [sp+1B0h] [-110h] BYREF
  float v30[5]; // [sp+1D0h] [-F0h] BYREF
  idEventArg v31; // [sp+1F0h] [-D0h] BYREF
  idEventArg v32; // [sp+210h] [-B0h] BYREF
  idEventReceiver v33[12]; // [sp+230h] [-90h] BYREF

  if ( ai->aiVolatile.physics.moveState.GetMoveStatus(this: &ai->aiVolatile.physics.moveState) != 1 )
  {
    value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v10 = gameLocal->entities.ptr[value & 0x1FFF];
      if ( v10 != nullptr )
      {
        v11 = idEntity::CastTo(c: v10);
        if ( v11 != nullptr )
        {
          SetWalkState = ai->SetWalkState;
          ai->aiVolatile.animation.subWeb = AISUBWEB_COMBAT;
          SetWalkState(this: ai, a2: WALKSTATE_WALKING);
          if ( ai->GetPosture(this: ai) == POSTURE_CROUCHED )
          {
            v13 = idEventArg::idEventArg(this: &v27, data: ai);
            idEventReceiver::ProcessEvent(
              this: v26,
              result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
              ev: *(const idEventDef **)&v13->type,
              arg1: (const idEventArg *)LODWORD(v13->value.v[1]));
          }
          v30[1] = ai->aiEditable.actionSettings.close.closeMinRange;
          HIBYTE(v29[0]) = 105;
          HIBYTE(v28[0]) = 105;
          v25[1] = vec3_origin.x;
          v25[2] = vec3_origin.y;
          v29[1] = 0;
          v25[3] = vec3_origin.z;
          HIBYTE(v25[0]) = 118;
          v28[1] = 0;
          HIBYTE(v30[0]) = 102;
          HIBYTE(v26[0].__vftable) = 105;
          v26[0].listenerList = (idList<idEventReceiver *,5> *)2;
          v27.type = 105;
          v27.value.i = 0;
          v14 = idEventArg::idEventArg(this: &v31, data: v11);
          v15 = idEventArg::idEventArg(this: &v32, data: ai);
          memcpy(Dst: v24, Src: v29, Size: sizeof(v24));
          memcpy(Dst: v23, Src: v25, Size: sizeof(v23));
          memcpy(Dst: v22, Src: v28, Size: sizeof(v22));
          memcpy(Dst: v21, Src: v30, Size: sizeof(v21));
          memcpy(Dst: v20, Src: v26, Size: sizeof(v20));
          memcpy(Dst: v19, Src: v14, Size: sizeof(v19));
          idEventReceiver::ProcessEvent(
            this: v33,
            result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
            ev: *(const idEventDef **)&v15->type,
            arg1: (const idEventArg *)LODWORD(v15->value.v[1]),
            arg2: (const idEventArg *)LODWORD(v15->value.v[2]),
            arg3: (const idEventArg *)__ROL4__(*(_DWORD *)&v27.type, 32),
            arg4: (const idEventArg *)LODWORD(v27.value.v[1]),
            arg5: (const idEventArg *)LODWORD(v27.value.v[2]),
            arg6: v16,
            arg7: v17,
            arg8: v18);
          idAIState::StartQueuedActions(this, ai, parentFSM: fsm, curTime);
          idAI2::SetAimFocusEntity(this: ai, ent: v11, keepFocusInView: false, aimPoint: AIMPOINT_BEST, timeout: -1);
          idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_FIREWHENREADY);
        }
      }
    }
  }
}


// ========================================================================
// ?AIState_Work@idSearchScenePoint_MoveToPos@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AF3A70
// RVA : 0x00AF3A70
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

void __fastcall idSearchScenePoint_MoveToPos::AIState_Work(
        idSearchScenePoint_MoveToPos *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  int value; // r8
  idEntity *v6; // r3
  idEntity *v7; // r3
  bool v8; // r29
  idPhysics *Physics; // r3
  const idVec3 *v10; // r3
  idStr v11[2]; // [sp+50h] [-50h] BYREF

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v6 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v6 != nullptr )
    {
      v7 = idEntity::CastTo(c: v6);
      if ( v7 != nullptr )
      {
        v8 = false;
        Physics = idEntity::GetPhysics(this: v7);
        v10 = Physics->GetOrigin(this: Physics, a2: 0);
        if ( idEntity::GetDistanceSqrTo(this: ai, pos: v10) <= (double)(float)(ai->aiEditable.actionSettings.close.closeMinRange
                                                                             * ai->aiEditable.actionSettings.close.closeMinRange) )
          v8 = ai->aiVolatile.physics.moveState.GetMoveStatus(this: &ai->aiVolatile.physics.moveState) != 0;
        if ( v8 )
        {
          v11[0].len = 0;
          v11[0].baseBuffer[0] = 0;
          v11[0].allocedAndFlag = 20;
          v11[0].data = v11[0].baseBuffer;
          idAI2::GetIdleStateName(this: ai, name: v11);
          idAI2::ChangeAnimState(
            this: ai,
            web: AIANIMWEB_BODY,
            subWeb: ai->aiVolatile.animation.subWeb,
            stateName: v11[0].data,
            interruptPath: INTR_PATH_YES,
            interruptBlend: INTR_BLEND_NO,
            subWebIndex: nullptr,
            stateIndex: nullptr);
          idAIMoveState::Stop(this: &ai->aiVolatile.physics.moveState, newStatus: 0);
          idStr::FreeData(this: v11);
        }
      }
    }
  }
}


// ========================================================================
// __unwind$490125
// EA  : 0x82AF3BA8
// RVA : 0x00AF3BA8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.cpp
// ========================================================================

void _unwind_490125()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 160 + 80));
}

