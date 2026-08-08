
// ========================================================================
// ?Evaluate@SEARCH_MoveToPoint@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEF130
// RVA : 0x00AEF130
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

int __fastcall SEARCH_MoveToPoint::Evaluate(
        SEARCH_MoveToPoint *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return 252;
}


// ========================================================================
// ?InternalInitState@idSearch_Default@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AEF138
// RVA : 0x00AEF138
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void __fastcall idSearch_Default::InternalInitState(idSearch_Default *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &SEARCH_GiveUp::Type, nextStateType: &idSearch_GiveUp::Type);
  idState::AddStateTransition(this, fsm, transType: &SEARCH_Intro::Type, nextStateType: &idSearch_Intro::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &SEARCH_MoveToPoint::Type,
    nextStateType: &idSearch_MoveToPoint::Type);
}


// ========================================================================
// ?InternalInitState@idSearch_Intro@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AEF1B8
// RVA : 0x00AEF1B8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void __fastcall idSearch_Intro::InternalInitState(idSearch_Intro *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &SEARCH_IntroFinished::Type,
    nextStateType: &idSearch_MoveToPoint::Type);
}


// ========================================================================
// ?InternalInitState@idSearch_MoveToPoint@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AEF1D0
// RVA : 0x00AEF1D0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void __fastcall idSearch_MoveToPoint::InternalInitState(idSearch_MoveToPoint *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &SEARCH_GiveUp::Type, nextStateType: &idSearch_GiveUp::Type);
  idState::AddStateTransition(this, fsm, transType: &SEARCH_NewStimulus::Type, nextStateType: &idSearch_Default::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &SEARCH_ReachedSearchAction::Type,
    nextStateType: &idSearch_PerformAction::Type);
  idState::AddStateTransition(this, fsm, transType: &SEARCH_ReachedPoint::Type, nextStateType: &idSearch_Wait::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &SEARCH_MoveFailed::Type,
    nextStateType: &idSearch_Unreachable::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &SEARCH_MoveToPointDone::Type,
    nextStateType: &idSearch_Unreachable::Type);
}


// ========================================================================
// ?Evaluate@SEARCH_ShouldWait@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEF290
// RVA : 0x00AEF290
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

int __fastcall SEARCH_ShouldWait::Evaluate(
        SEARCH_ShouldWait *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return 260;
}


// ========================================================================
// ?InternalInitState@idSearch_Unreachable@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AEF298
// RVA : 0x00AEF298
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void __fastcall idSearch_Unreachable::InternalInitState(idSearch_Unreachable *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &SEARCH_Retry::Type, nextStateType: &idSearch_MoveToPoint::Type);
  idState::AddStateTransition(this, fsm, transType: &SEARCH_GiveUp::Type, nextStateType: &idSearch_GiveUp::Type);
  idState::AddStateTransition(this, fsm, transType: &SEARCH_NewStimulus::Type, nextStateType: &idSearch_Default::Type);
  idState::AddStateTransition(this, fsm, transType: &SEARCH_ShouldWait::Type, nextStateType: &idSearch_Wait::Type);
}


// ========================================================================
// ?InternalInitState@idSearch_Wait@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AEF338
// RVA : 0x00AEF338
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void __fastcall idSearch_Wait::InternalInitState(idSearch_Wait *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &SEARCH_GiveUp::Type, nextStateType: &idSearch_GiveUp::Type);
  idState::AddStateTransition(this, fsm, transType: &SEARCH_NewStimulus::Type, nextStateType: &idSearch_Default::Type);
  idState::AddStateTransition(
    this,
    fsm,
    transType: &SEARCH_PerformAction::Type,
    nextStateType: &idSearch_PerformAction::Type);
  idState::AddStateTransition(this, fsm, transType: &SEARCH_WaitDone::Type, nextStateType: &idSearch_Default::Type);
}


// ========================================================================
// ?InternalInitState@idSearch_PerformAction@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AEF3C0
// RVA : 0x00AEF3C0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void __fastcall idSearch_PerformAction::InternalInitState(
        idSearch_PerformAction *this,
        const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(
    this,
    fsm,
    transType: &SEARCH_PerformActionFinished::Type,
    nextStateType: &idSearch_Default::Type);
}


// ========================================================================
// ?InternalInitState@idSearch_GiveUp@@UAAXPBVidFiniteStateMachine@@@Z
// EA  : 0x82AEF3D8
// RVA : 0x00AEF3D8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void __fastcall idSearch_GiveUp::InternalInitState(idSearch_GiveUp *this, const idFiniteStateMachine *fsm)
{
  idState::AddStateTransition(this, fsm, transType: &SEARCH_GiveUpFinished::Type, nextStateType: &idAIStateDone::Type);
}


// ========================================================================
// ?AIState_EnterState@idSearch_Default@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AEF3F0
// RVA : 0x00AEF3F0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void __fastcall idSearch_Default::AIState_EnterState(
        idSearch_Default *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idAI2::ClearAimFocus(this: ai);
  idAI2::ClearLookFocus(this: ai);
  *((_BYTE *)&ai->aiVolatile + 49704) |= 1u;
}


// ========================================================================
// ?Evaluate@SEARCH_MoveToPointDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEF440
// RVA : 0x00AEF440
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall SEARCH_MoveToPointDone::Evaluate(
        SEARCH_MoveToPointDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idFiniteStateMachine *FullPath; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v7; // zf

  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  if ( FullPath == nullptr )
    return TRANSCODE_ADVANCE_SURROUND_ENEMY_DONE;
  v7 = idFiniteStateMachine::GetStatus(this: FullPath) != 0;
  result = 0;
  if ( !v7 )
    return TRANSCODE_ADVANCE_SURROUND_ENEMY_DONE;
  return result;
}


// ========================================================================
// ?Evaluate@COMBAT_MoveFailed@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEF488
// RVA : 0x00AEF488
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

int __fastcall COMBAT_MoveFailed::Evaluate(
        ADVANCE_MoveFailed *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idFiniteStateMachine *FullPath; // r3
  idFiniteStateMachine *v7; // r31
  int errorTransCode; // r11
  idAIMoveState *MoveInterface; // r3

  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  v7 = FullPath;
  if ( FullPath != nullptr && (unsigned __int8)idFiniteStateMachine::HadError(this: FullPath) != 0 )
  {
    errorTransCode = v7->errorTransCode;
    if ( errorTransCode == 9 || errorTransCode == 10 || errorTransCode == 19 || errorTransCode == 20 )
      return 9;
  }
  MoveInterface = idAI2::GetMoveInterface(this: ai);
  return __CFADD__(MoveInterface->GetMoveStatus(this: MoveInterface) - 2, -2147483646) ? 0 : 9;
}


// ========================================================================
// ?Evaluate@SEARCH_ReachedSearchAction@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEF540
// RVA : 0x00AEF540
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall SEARCH_ReachedSearchAction::Evaluate(
        SEARCH_ReachedSearchAction *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idFiniteStateMachine *FullPath; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v7; // zf

  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  if ( FullPath == nullptr )
    return TRANSCODE_SEARCH_PERFORM_ACTION;
  v7 = idFiniteStateMachine::GetStatus(this: FullPath) != 0;
  result = 0;
  if ( !v7 )
    return TRANSCODE_SEARCH_PERFORM_ACTION;
  return result;
}


// ========================================================================
// ?Evaluate@SEARCH_ReachedPoint@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEF588
// RVA : 0x00AEF588
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall SEARCH_ReachedPoint::Evaluate(
        SEARCH_ReachedPoint *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idFiniteStateMachine *FullPath; // r3
  idAIStateTransition::aiTransCode_t result; // r3
  bool v7; // zf

  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  if ( FullPath == nullptr )
    return TRANSCODE_SEARCH_REACHED_POINT;
  v7 = idFiniteStateMachine::GetStatus(this: FullPath) != 0;
  result = 0;
  if ( !v7 )
    return TRANSCODE_SEARCH_REACHED_POINT;
  return result;
}


// ========================================================================
// ?Evaluate@SEARCH_Retry@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEF5D0
// RVA : 0x00AEF5D0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall SEARCH_Retry::Evaluate(
        SEARCH_Retry *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int *p_movementFailedTime; // r31
  idAIMoveState *MoveInterface; // r3
  int v9; // [sp+50h] [-20h] BYREF

  p_movementFailedTime = &ai->aiVolatile.memory.movementFailedTime;
  if ( ai->aiVolatile.memory.movementFailedTime < 0 )
    return 0;
  MoveInterface = idAI2::GetMoveInterface(this: ai);
  v9 = 5000;
  if ( MoveInterface->RecentlyFailedMove(
         this: MoveInterface,
         a2: AIMOVEREASON_SEARCH_MOVE_TO_POINT,
         a3: (const idTypesafeNumber<int,enum gameTimeUnique_t> *)&v9) )
  {
    return 0;
  }
  else
  {
    return ((__PAIR64__((unsigned int)(curTime - *p_movementFailedTime) >> 31, 500)
           - (unsigned int)(curTime - *p_movementFailedTime)) >> 32)
         & 0x103;
  }
}


// ========================================================================
// ?Evaluate@SEARCH_WaitDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEF678
// RVA : 0x00AEF678
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall SEARCH_WaitDone::Evaluate(
        SEARCH_WaitDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  unsigned int v5; // r9

  v5 = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
     - parentFSM->lastTransitionTime;
  return ((__PAIR64__(v5 >> 31, 2000) - v5) >> 32) & 0x105;
}


// ========================================================================
// ?AIState_EnterState@idSearch_Wait@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AEF6E0
// RVA : 0x00AEF6E0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void __fastcall idSearch_Wait::AIState_EnterState(idSearch_Wait *this, idAI2 *ai, idAIFSM *fsm, int curTime)
{
  idEventArg *v8; // r3
  idEventArg v9; // [sp+90h] [-70h] BYREF
  idEventReceiver v10[6]; // [sp+B0h] [-50h] BYREF

  v8 = idEventArg::idEventArg(this: &v9, data: ai);
  idEventReceiver::ProcessEvent(
    this: v10,
    result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
    ev: *(const idEventDef **)&v8->type,
    arg1: (const idEventArg *)LODWORD(v8->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v8->value.v[2]));
  idAIState::StartQueuedActions(this, ai, parentFSM: fsm, curTime);
}


// ========================================================================
// ?Evaluate@SEARCH_PerformActionFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEF770
// RVA : 0x00AEF770
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall SEARCH_PerformActionFinished::Evaluate(
        SEARCH_PerformActionFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idFiniteStateMachine *FullPath; // r3
  idFiniteStateMachine *v6; // r31
  idAIStateTransition::aiTransCode_t result; // r3
  bool v8; // zf

  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  v6 = FullPath;
  if ( FullPath == nullptr )
    return TRANSCODE_SEARCH_PERFORM_ACTION_FINISHED;
  if ( (unsigned __int8)idFiniteStateMachine::HadError(this: FullPath) != 0 )
    return TRANSCODE_SEARCH_PERFORM_ACTION_FINISHED;
  v8 = idFiniteStateMachine::GetStatus(this: v6) != 0;
  result = 0;
  if ( !v8 )
    return TRANSCODE_SEARCH_PERFORM_ACTION_FINISHED;
  return result;
}


// ========================================================================
// ?Evaluate@SEARCH_GiveUpFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEF7D8
// RVA : 0x00AEF7D8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall SEARCH_GiveUpFinished::Evaluate(
        SEARCH_GiveUpFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idFiniteStateMachine *FullPath; // r3
  idFiniteStateMachine *v6; // r31
  idAIStateTransition::aiTransCode_t result; // r3
  bool v8; // zf

  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  v6 = FullPath;
  if ( FullPath == nullptr )
    return TRANSCODE_SEARCH_GIVE_UP_FINISHED;
  if ( (unsigned __int8)idFiniteStateMachine::HadError(this: FullPath) != 0 )
    return TRANSCODE_SEARCH_GIVE_UP_FINISHED;
  v8 = idFiniteStateMachine::GetStatus(this: v6) != 0;
  result = 0;
  if ( !v8 )
    return TRANSCODE_SEARCH_GIVE_UP_FINISHED;
  return result;
}


// ========================================================================
// ?AIState_EnterState@idSearch_GiveUp@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AEF840
// RVA : 0x00AEF840
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void __fastcall idSearch_GiveUp::AIState_EnterState(
        idSearch_GiveUp *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  idEventArg *v7; // r3
  idEventArg v8; // [sp+90h] [-60h] BYREF
  idEventReceiver v9[5]; // [sp+B0h] [-40h] BYREF

  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  v7 = idEventArg::idEventArg(this: &v8, data: ai);
  idEventReceiver::ProcessEvent(
    this: v9,
    result: fsm,
    ev: *(const idEventDef **)&v7->type,
    arg1: (const idEventArg *)LODWORD(v7->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v7->value.v[2]));
}


// ========================================================================
// ??0idSearchFSM@@QAA@XZ
// EA  : 0x82AEF8D0
// RVA : 0x00AEF8D0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

idSearchFSM *__fastcall idSearchFSM::idSearchFSM(idSearchFSM *this)
{
  idFiniteStateMachine::idFiniteStateMachine(this, name: "FSM_search");
  this->__vftable = (idSearchFSM_vtbl *)&idSearchFSM::`vftable';
  idState::idState(this: &this->stateDefault, stateType: &idSearch_Default::Type, childFSMType: nullptr, flags: 0);
  this->stateDefault.__vftable = (idSearch_Default_vtbl *)&idSearch_Default::`vftable';
  idState::idState(this: &this->stateIntro, stateType: &idSearch_Intro::Type, childFSMType: nullptr, flags: 0);
  this->stateIntro.__vftable = (idSearch_Intro_vtbl *)&idSearch_Intro::`vftable';
  idState::idState(
    this: &this->stateMoveToPoint,
    stateType: &idSearch_MoveToPoint::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateMoveToPoint.__vftable = (idSearch_MoveToPoint_vtbl *)&idSearch_MoveToPoint::`vftable';
  idState::idState(
    this: &this->stateUnreachable,
    stateType: &idSearch_Unreachable::Type,
    childFSMType: nullptr,
    flags: 0);
  this->stateUnreachable.__vftable = (idSearch_Unreachable_vtbl *)&idSearch_Unreachable::`vftable';
  idState::idState(this: &this->stateWait, stateType: &idSearch_Wait::Type, childFSMType: nullptr, flags: 0);
  this->stateWait.__vftable = (idSearch_Wait_vtbl *)&idSearch_Wait::`vftable';
  idState::idState(
    this: &this->statePerformAction,
    stateType: &idSearch_PerformAction::Type,
    childFSMType: nullptr,
    flags: 0);
  this->statePerformAction.__vftable = (idSearch_PerformAction_vtbl *)&idSearch_PerformAction::`vftable';
  idState::idState(this: &this->stateGiveUp, stateType: &idSearch_GiveUp::Type, childFSMType: nullptr, flags: 0);
  this->stateGiveUp.__vftable = (idSearch_GiveUp_vtbl *)&idSearch_GiveUp::`vftable';
  idFiniteStateMachine::SetDefaultState(this, state: &this->stateDefault);
  return this;
}


// ========================================================================
// __unwind$489645
// EA  : 0x82AEFA1C
// RVA : 0x00AEFA1C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void _unwind_489645()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$489646
// EA  : 0x82AEFA44
// RVA : 0x00AEFA44
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void _unwind_489646()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 108));
}


// ========================================================================
// __unwind$489647
// EA  : 0x82AEFA70
// RVA : 0x00AEFA70
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void _unwind_489647()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 136));
}


// ========================================================================
// __unwind$489648
// EA  : 0x82AEFA9C
// RVA : 0x00AEFA9C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void _unwind_489648()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 164));
}


// ========================================================================
// __unwind$489649
// EA  : 0x82AEFAC8
// RVA : 0x00AEFAC8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void _unwind_489649()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 192));
}


// ========================================================================
// __unwind$489650
// EA  : 0x82AEFAF4
// RVA : 0x00AEFAF4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void _unwind_489650()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 220));
}


// ========================================================================
// __unwind$489651
// EA  : 0x82AEFB20
// RVA : 0x00AEFB20
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void _unwind_489651()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 248));
}


// ========================================================================
// __unwind$489652
// EA  : 0x82AEFB4C
// RVA : 0x00AEFB4C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void _unwind_489652()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 128 + 148) + 276));
}


// ========================================================================
// ??1idSearchFSM@@UAA@XZ
// EA  : 0x82AEFB80
// RVA : 0x00AEFB80
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void __fastcall idSearchFSM::~idSearchFSM(idSearchFSM *this)
{
  this->__vftable = (idSearchFSM_vtbl *)&idSearchFSM::`vftable';
  idState::~idState(this: &this->stateGiveUp);
  idState::~idState(this: &this->statePerformAction);
  idState::~idState(this: &this->stateWait);
  idState::~idState(this: &this->stateUnreachable);
  idState::~idState(this: &this->stateMoveToPoint);
  idState::~idState(this: &this->stateIntro);
  idState::~idState(this: &this->stateDefault);
  idFiniteStateMachine::~idFiniteStateMachine(this);
}


// ========================================================================
// __unwind$489786
// EA  : 0x82AEFC04
// RVA : 0x00AEFC04
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void _unwind_489786()
{
  int v0; // r12

  idAIFSM::~idAIFSM(this: *(idAIFSM **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$489787
// EA  : 0x82AEFC2C
// RVA : 0x00AEFC2C
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void _unwind_489787()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 108));
}


// ========================================================================
// __unwind$489788
// EA  : 0x82AEFC58
// RVA : 0x00AEFC58
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void _unwind_489788()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 136));
}


// ========================================================================
// __unwind$489789
// EA  : 0x82AEFC84
// RVA : 0x00AEFC84
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void _unwind_489789()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 164));
}


// ========================================================================
// __unwind$489790
// EA  : 0x82AEFCB0
// RVA : 0x00AEFCB0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void _unwind_489790()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 192));
}


// ========================================================================
// __unwind$489791
// EA  : 0x82AEFCDC
// RVA : 0x00AEFCDC
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void _unwind_489791()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 220));
}


// ========================================================================
// __unwind$489792
// EA  : 0x82AEFD08
// RVA : 0x00AEFD08
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void _unwind_489792()
{
  int v0; // r12

  idAlertCycle_Pain::~idAlertCycle_Pain(this: (idCombat_MoveToPlugAnim *)(*(_DWORD *)(v0 - 112 + 132) + 248));
}


// ========================================================================
// ?Evaluate@SEARCH_IntroFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEFD38
// RVA : 0x00AEFD38
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall SEARCH_IntroFinished::Evaluate(
        SEARCH_IntroFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        XGRAPHICS::IRInst *state,
        const int curTime)
{
  idFiniteStateMachine *FullPath; // r3
  idFiniteStateMachine *v7; // r31
  idAI2::idAIVolatile::idAIAnimationInfo *p_animation; // r11
  unsigned int value; // r10
  char v10; // r11
  bool v11; // zf
  idAIStateTransition::aiTransCode_t result; // r3

  FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: state);
  p_animation = &ai->aiVolatile.animation;
  value = (unsigned __int16)ai->aiVolatile.animation.animWebAnimator.ptr[0].curEdgeNodeIndex.value;
  v7 = FullPath;
  if ( value >= 0x8000
    || (v11 = (unsigned __int16)p_animation->animWebAnimator.ptr[0].curEdgeIndex < 0x8000u, v10 = 1, !v11) )
  {
    v10 = 0;
  }
  if ( v10 != 0 )
    return 0;
  if ( FullPath == nullptr )
    return TRANSCODE_SEARCH_INTRO_FINISHED;
  if ( (unsigned __int8)idFiniteStateMachine::HadError(this: FullPath) != 0 )
    return TRANSCODE_SEARCH_INTRO_FINISHED;
  v11 = idFiniteStateMachine::GetStatus(this: v7) != 0;
  result = 0;
  if ( !v11 )
    return TRANSCODE_SEARCH_INTRO_FINISHED;
  return result;
}


// ========================================================================
// ?Evaluate@SEARCH_NewStimulus@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEFE50
// RVA : 0x00AEFE50
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall SEARCH_NewStimulus::Evaluate(
        SEARCH_NewStimulus *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v7; // r3
  idEntity *v8; // r4
  idAIEntityState *v9; // r3

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v7 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v7 != nullptr )
    {
      v8 = idEntity::CastTo(c: v7);
      if ( v8 != nullptr )
      {
        v9 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v8);
        if ( v9 != nullptr && v9->curAwareness == 2 )
          aiSenseState_t::GetConfirmedPhysicalSafe(this: v9->senses.ptr[v9->lastSense]);
      }
    }
  }
  return 0;
}


// ========================================================================
// ?Evaluate@SEARCH_GiveUp@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AEFF40
// RVA : 0x00AEFF40
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

int __fastcall SEARCH_GiveUp::Evaluate(
        SEARCH_GiveUp *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v7; // r3
  idEntity *v8; // r4
  idAIEntityState *v10; // r3

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && (v8 = idEntity::CastTo(c: v7)) != nullptr
    && (v10 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v8)) != nullptr )
  {
    return v10->curAwareness != 1 ? 0 : 0xFA;
  }
  else
  {
    return 250;
  }
}


// ========================================================================
// ?Evaluate@SEARCH_Intro@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AF0000
// RVA : 0x00AF0000
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

int __fastcall SEARCH_Intro::Evaluate(
        SEARCH_Intro *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  int value; // r8
  idEntity *v7; // r3
  idEntity *v8; // r4
  idAIEntityState *v10; // r3

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && (v8 = idEntity::CastTo(c: v7)) != nullptr
    && (v10 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v8)) != nullptr )
  {
    return (*((_BYTE *)v10 + 541) & 0x40) == 0 ? 0 : 0xFB;
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?AIState_EnterState@idSearch_Intro@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AF00C8
// RVA : 0x00AF00C8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void __fastcall idSearch_Intro::AIState_EnterState(idSearch_Intro *this, idAI2 *ai, idEventArg *fsm, const int curTime)
{
  int value; // r8
  idEntity *v8; // r3
  idEntity *v9; // r4
  idAIEntityState *v10; // r3
  idAIEntityState *v11; // r29
  int v12; // r8
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  float y; // r9
  float z; // r8
  idPhysics *Physics; // r3
  idEventArg *v17; // r3
  idPhysics *v18; // r3
  aiSenseState_t *v19; // r29
  float *v20; // r25
  const aiPhysicalState_t *v21; // r3
  double v22; // fp9
  double v23; // fp7
  idDeclAnimWeb *decl; // r29
  char *StateName; // r25
  char *SubWebName; // r3
  char *data; // r10
  idEventArg *v28; // r26
  _BYTE v29[20]; // [sp+70h] [-170h] BYREF
  _BYTE v30[20]; // [sp+90h] [-150h] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> v31; // [sp+B0h] [-130h] BYREF
  idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> v32; // [sp+B2h] [-12Eh] BYREF
  idVec3 v33; // [sp+B8h] [-128h] BYREF
  idVec3 v34; // [sp+C8h] [-118h] BYREF
  idStr v35; // [sp+E0h] [-100h] BYREF
  idEventReceiver v36[2]; // [sp+100h] [-E0h] BYREF
  idEventArg v37; // [sp+120h] [-C0h] BYREF
  _DWORD v38[5]; // [sp+140h] [-A0h] BYREF
  idEventReceiver v39[2]; // [sp+160h] [-80h] BYREF
  idEventArg v40[4]; // [sp+180h] [-60h] BYREF

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v8 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v9 = idEntity::CastTo(c: v8);
  }
  else
  {
    v9 = nullptr;
  }
  v10 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v9);
  v11 = v10;
  if ( v10 != nullptr )
  {
    v12 = v10->lastSense + 128;
    *((_BYTE *)v10 + 541) &= ~0x40u;
    aiSenseState_t::GetConfirmedPhysicalSafe(this: *((aiSenseState_t **)&v10->__vftable + v12));
    ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v11->senses.ptr[v11->lastSense]);
    y = ConfirmedPhysicalSafe->origin.y;
    z = ConfirmedPhysicalSafe->origin.z;
    v34.x = ConfirmedPhysicalSafe->origin.x;
    v34.y = y;
    v34.z = z;
    idAI2::SetExplicitAimFocusPoint(
      this: ai,
      point: &v34,
      keepFocusInView: true,
      timeout: -1,
      focusType: AIFOCUS_LAST_SENSED_POS);
    if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) != 0 )
      idAnimBaseFSM::ClearDestination(this: &ai->aiVolatile.animation.animFSM);
    else
      idAIMoveState::Stop(this: &ai->aiVolatile.physics.moveState, newStatus: 0);
    idAIFireControl::SetFireMode(this: ai->aiVolatile.fireControl, owner: ai, mode: FIREMODE_HOLDFIRE);
    if ( ai->aiVolatile.fsms.previousAlertCycle == ALERTCYCLE_RELAXED
      && (idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX)->senseFlags & 1) != 0
      && (idAI2::GetEnemySenseState(this: ai, senseType: AISENSE_MAX)->senseFlags & 8) == 0 )
    {
      Physics = idEntity::GetPhysics(this: ai);
      Physics->GetOrigin(this: Physics, a2: 0);
    }
    if ( ai->GetEquippedWeapon(this: ai) != nullptr )
    {
      v31.value = -1;
      v32.value = -1;
      v18 = idEntity::GetPhysics(this: ai);
      v19 = v11->senses.ptr[v11->lastSense];
      v20 = (float *)v18->GetOrigin(this: v18, a2: 0);
      v21 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v19);
      v22 = (float)(v21->origin.z - v20[2]);
      v23 = (float)(v21->origin.y - v20[1]);
      v33.x = v21->origin.x - *v20;
      v33.z = v22;
      v33.y = v23;
      idVec3::NormalizeFast(this: &v33);
      idAnimWebAI::CalcToSearchTurn(this: ai->aiVolatile.animation.animWebAnimator.ptr, desiredDir: &v33);
      idAI2::FindAnimWebAndStateIndices(
        this: ai,
        web: AIANIMWEB_BODY,
        subWeb: 3,
        stateName: "idle",
        changeWeapon: false,
        newWeapon: nullptr,
        subWebIndex: &v31,
        stateIndex: &v32);
      idAI2::ChangeAnimState(
        this: ai,
        web: AIANIMWEB_BODY,
        subWebIndex: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v31.value,
        stateIndex: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v32.value,
        interruptPath: INTR_PATH_YES,
        interruptBlend: INTR_BLEND_NO);
      v35.len = 0;
      v35.allocedAndFlag = 20;
      v35.data = v35.baseBuffer;
      v35.baseBuffer[0] = 0;
      decl = ai->aiVolatile.animation.animWebAnimator.ptr[0].decl;
      StateName = (char *)idDeclAnimWeb::GetStateName(
                            this: decl,
                            index: (const idIndex<short,enum idDeclAnimWeb::invalidStateIndex_t> *)(unsigned __int16)v32.value);
      SubWebName = (char *)idDeclAnimWeb::GetSubWebName(
                             this: decl,
                             index: (const idIndex<short,enum idDeclAnimWeb::invalidSubWebIndex_t> *)(unsigned __int16)v31.value);
      idAnimWebPath::SetPath(
        this: (idAnimWebPath *)&v35,
        webName: nullptr,
        subWebName: SubWebName,
        stateName: StateName);
      idAI2::EndActionScript(this: ai);
      data = v35.data;
      LODWORD(fsm[1].value.v[2]) = this;
      v36[0].listenerList = nullptr;
      HIBYTE(v38[0]) = 105;
      v38[1] = 1;
      HIBYTE(v36[0].__vftable) = 105;
      v37.type = 49;
      v37.value.i = (int)data;
      v28 = idEventArg::idEventArg(this: v40, data: ai);
      memcpy(Dst: v30, Src: v38, Size: sizeof(v30));
      memcpy(Dst: v29, Src: v36, Size: sizeof(v29));
      idEventReceiver::ProcessEvent(
        this: v39,
        result: fsm,
        ev: *(const idEventDef **)&v28->type,
        arg1: (const idEventArg *)LODWORD(v28->value.v[1]),
        arg2: (const idEventArg *)LODWORD(v28->value.v[2]),
        arg3: (const idEventArg *)__ROL4__(*(_DWORD *)&v37.type, 32),
        arg4: (const idEventArg *)LODWORD(v37.value.v[1]));
      idStr::FreeData(this: &v35);
    }
    else
    {
      idAI2::EndActionScript(this: ai);
      LODWORD(fsm[1].value.v[2]) = this;
      v17 = idEventArg::idEventArg(this: &v37, data: ai);
      idEventReceiver::ProcessEvent(
        this: v36,
        result: fsm,
        ev: *(const idEventDef **)&v17->type,
        arg1: (const idEventArg *)LODWORD(v17->value.v[1]));
    }
  }
  else
  {
    idState::SetEnterFailed(this, failed: true);
  }
}


// ========================================================================
// __unwind$490911
// EA  : 0x82AF04B4
// RVA : 0x00AF04B4
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void _unwind_490911()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 480 + 224));
}


// ========================================================================
// ?AIState_EnterState@idSearch_MoveToPoint@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AF04E8
// RVA : 0x00AF04E8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void __fastcall idSearch_MoveToPoint::AIState_EnterState(
        idSearch_MoveToPoint *this,
        idAI2 *ai,
        idAIFSM *fsm,
        int curTime)
{
  idSearch_MoveToPoint *v5; // r19
  int value; // r8
  idEntity *v7; // r3
  idEntity *v8; // r27
  const idAAS2 *v9; // r3
  idAAS2 *v10; // r21
  idAIEntityState *v11; // r30
  idPhysics *Physics; // r3
  float *v13; // r25
  overrideAnim_t *p_searchAction; // r20
  aiSenseState_t *v15; // r30
  const aiPhysicalState_t *ConfirmedPhysicalSafe; // r3
  idAIMemory::aiSearchToStimulusMode *p_searchToStimulusMode; // r28
  float y; // r10
  float z; // r9
  idAIMemory::aiSearchToStimulusMode searchToStimulusMode; // r7
  idCVar *v21; // r11
  double v22; // fp25
  idEncounterGroup *EncounterGroup; // r23
  idPhysics *v24; // r3
  const idVec3 *v25; // r28
  const aiPhysicalState_t *v26; // r3
  idPhysics *v27; // r3
  const idVec3 *v28; // r28
  const aiPhysicalState_t *v29; // r3
  idPhysics *v30; // r3
  idVec3 *v31; // r3
  idAIGameState *p_aiGameState; // r30
  const idSpawnId *v33; // r27
  const idAILogic *v34; // r3
  const idSpawnId *v35; // r8
  int currentSearchHintIndex; // r30
  int v37; // r28
  int v38; // r18
  __int128 v39; // r5
  double v40; // fp12
  double v41; // fp6
  double v42; // fp3
  double v43; // fp28
  int v44; // r16
  int v45; // r17
  int v46; // r24
  int *p_hintNodeIndex; // r28
  int v48; // r3
  int v49; // r30
  double v50; // fp8
  double v51; // fp5
  double v52; // fp2
  double v54; // fp12
  double v56; // fp9
  double v57; // fp5
  double v58; // fp31
  idPhysics *v59; // r3
  idRenderWorld_vtbl *v60; // r28
  int v61; // r3
  __int64 v62; // r6
  __int64 v63; // r10
  __int64 v64; // r8
  va *v65; // r3
  idPhysics *v66; // r3
  idRenderWorld_vtbl *v67; // r28
  int v68; // r3
  __int64 v69; // r6
  __int64 v70; // r10
  __int64 v71; // r8
  va *v72; // r3
  aas2HintNode_t *v73; // r30
  __int64 v74; // r8
  int v75; // r6
  int v76; // r5
  int hintData; // r11
  double v78; // fp1
  double v79; // fp11
  double v80; // fp31
  double v81; // fp8
  double v82; // fp5
  int v83; // r28
  char v84; // r11
  __int64 v85; // r9
  idPhysics *v86; // r3
  idRenderWorld_vtbl *v87; // r30
  int v88; // r3
  idAAS2 v89; // r26
  int v90; // r3
  int v91; // r3
  idEventArg *v92; // r3
  double x; // fp0
  double v94; // fp13
  int v95; // r7
  double v96; // fp12
  double v97; // fp10
  double v98; // fp9
  idEventArg *v99; // r27
  const idEventArg *v100; // [sp+8h] [-1388h]
  const idEventArg *v101; // [sp+Ch] [-1384h]
  int v102; // [sp+10h] [-1380h]
  int v103; // [sp+14h] [-137Ch]
  int v104; // [sp+18h] [-1378h]
  int v105; // [sp+1Ch] [-1374h]
  _BYTE v106[20]; // [sp+70h] [-1320h] BYREF
  _BYTE v107[20]; // [sp+90h] [-1300h] BYREF
  _BYTE v108[20]; // [sp+B0h] [-12E0h] BYREF
  _BYTE v109[20]; // [sp+D0h] [-12C0h] BYREF
  _BYTE v110[20]; // [sp+F0h] [-12A0h] BYREF
  unsigned __int8 v111; // [sp+110h] [-1280h]
  idVec3 eyePos; // [sp+118h] [-1278h] BYREF
  __int64 v113; // [sp+128h] [-1268h] BYREF
  idSpawnId v114; // [sp+130h] [-1260h] BYREF
  idCVar *v115; // [sp+134h] [-125Ch]
  idVec3 v116; // [sp+138h] [-1258h] BYREF
  idVec3 v117; // [sp+148h] [-1248h] BYREF
  idVec3 v118; // [sp+158h] [-1238h] BYREF
  idAngles v119; // [sp+168h] [-1228h] BYREF
  idList<int,5> v120; // [sp+180h] [-1210h] BYREF
  float v121[5]; // [sp+190h] [-1200h] BYREF
  idList<int,5> v122; // [sp+1B0h] [-11E0h] BYREF
  float v123[5]; // [sp+1C0h] [-11D0h] BYREF
  idEventArg v124; // [sp+1E0h] [-11B0h] BYREF
  idEventReceiver v125[2]; // [sp+200h] [-1190h] BYREF
  idColor v126; // [sp+220h] [-1170h] BYREF
  idColor v127; // [sp+230h] [-1160h] BYREF
  _DWORD v128[5]; // [sp+240h] [-1150h] BYREF
  float v129[5]; // [sp+260h] [-1130h] BYREF
  idAILogic v130; // [sp+280h] [-1110h] BYREF
  idEventArg v131; // [sp+2A0h] [-10F0h] BYREF
  va v132; // [sp+2C0h] [-10D0h] BYREF

  v5 = this;
  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v7 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v8 = idEntity::CastTo(c: v7);
  }
  else
  {
    v8 = nullptr;
  }
  v9 = ai->GetAAS(this: ai);
  v10 = (idAAS2 *)v9;
  if ( v8 == nullptr )
    goto LABEL_60;
  if ( v9 == nullptr )
    goto LABEL_60;
  v11 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v8);
  if ( v11 == nullptr )
    goto LABEL_60;
  Physics = idEntity::GetPhysics(this: ai);
  v13 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  p_searchAction = &ai->aiVolatile.memory.searchAction;
  v114.value = (int)&ai->aiVolatile.memory.searchAction;
  ai->aiVolatile.memory.searchAction = ANIMOVERRIDE_NONE;
  v15 = v11->senses.ptr[v11->lastSense];
  ConfirmedPhysicalSafe = aiSenseState_t::GetConfirmedPhysicalSafe(this: v15);
  p_searchToStimulusMode = &ai->aiVolatile.memory.searchToStimulusMode;
  y = ConfirmedPhysicalSafe->origin.y;
  z = ConfirmedPhysicalSafe->origin.z;
  v117.x = ConfirmedPhysicalSafe->origin.x;
  searchToStimulusMode = ai->aiVolatile.memory.searchToStimulusMode;
  v117.y = y;
  v117.z = z;
  eyePos.x = v117.x;
  eyePos.y = y;
  eyePos.z = z;
  if ( searchToStimulusMode == AISEARCH_TO_STIMULUS_EYES )
    eyePos = aiSenseState_t::GetConfirmedPhysicalSafe(this: v15)->eyePos;
  idAI2::ClearAimFocus(this: ai);
  v111 = 0;
  v21 = &ai_debugSearch;
  v116.x = 1.0;
  v116.y = 0.0;
  v115 = &ai_debugSearch;
  v116.z = 0.0;
  v22 = 0.1;
  if ( (float)((float)((float)(v117.z - v13[2]) * (float)(v117.z - v13[2]))
             + (float)((float)((float)(v117.x - *v13) * (float)(v117.x - *v13))
                     + (float)((float)(v117.y - v13[1]) * (float)(v117.y - v13[1])))) < 0.0 )
    goto _M491618;
  EncounterGroup = idAI2::GetEncounterGroup(this: ai);
  if ( EncounterGroup == nullptr )
  {
LABEL_60:
    idState::SetEnterFailed(this: v5, failed: true);
    return;
  }
  idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: (idList<idDeclVehicleUpgrade const *,5> *)&v120);
  idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: (idList<idDeclVehicleUpgrade const *,5> *)&v122);
  if ( *p_searchToStimulusMode != AISEARCH_TO_STIMULUS_NONE )
  {
    *p_searchToStimulusMode = AISEARCH_TO_STIMULUS_NONE;
    v22 = 64.0;
  }
  else if ( EncounterGroup->searchPointList.num != 0 )
  {
    currentSearchHintIndex = ai->aiVolatile.memory.currentSearchHintIndex;
    v37 = (int)v10->GetHintNode(this: v10, a2: currentSearchHintIndex);
    v38 = 0;
    if ( currentSearchHintIndex == 0
      || (*(_QWORD *)((char *)&v39 + 4) = ((__int64 (__fastcall *)(idAAS2 *, int))v10->GetHintNode)(
                                            a1: v10,
                                            a2: currentSearchHintIndex),
          v40 = (float)(*(float *)(v37 + 4) - v13[1]),
          v38 = *(unsigned __int8 *)(DWORD1(v39) + 19),
          v41 = (float)(*(float *)(v37 + 8) - v13[2]),
          LODWORD(v39) = *(__int16 *)(v37 + 14) * *(__int16 *)(v37 + 14),
          v42 = (float)((float)((float)v41 * (float)v41)
                      + (float)((float)((float)(*(float *)v37 - *v13) * (float)(*(float *)v37 - *v13))
                              + (float)((float)v40 * (float)v40))),
          v113 = v39,
          v42 < (float)((float)(__int64)v39 * (float)1.1)) )
    {
      v43 = 0.0;
      v44 = -1;
      v45 = 0;
      if ( EncounterGroup->searchPointList.num > 0 )
      {
        v46 = 0;
        do
        {
          p_hintNodeIndex = &EncounterGroup->searchPointList.list[v46].hintNodeIndex;
          v48 = (int)v10->GetHintNode(this: v10, a2: *p_hintNodeIndex);
          v49 = v48;
          v50 = (float)(*(float *)(v48 + 4) - v13[1]);
          v51 = (float)(*(float *)(v48 + 8) - v13[2]);
          v52 = (float)((float)((float)v51 * (float)v51)
                      + (float)((float)((float)(*(float *)v48 - *v13) * (float)(*(float *)v48 - *v13))
                              + (float)((float)v50 * (float)v50)));
          _FP1 = (float)((float)((float)((float)v51 * (float)v51)
                               + (float)((float)((float)(*(float *)v48 - *v13) * (float)(*(float *)v48 - *v13))
                                       + (float)((float)v50 * (float)v50)))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          v54 = (float)((float)((float)((float)v51 * (float)v51)
                              + (float)((float)((float)(*(float *)v48 - *v13) * (float)(*(float *)v48 - *v13))
                                      + (float)((float)v50 * (float)v50)))
                      * (float)0.5);
          __asm { fsel      f11, f1, f2, f0 }
          v56 = __frsqrte(_FP11);
          v57 = (float)((float)-(float)((float)((float)((float)v56
                                                      * (float)((float)((float)((float)v51 * (float)v51)
                                                                      + (float)((float)((float)(*(float *)v48 - *v13)
                                                                                      * (float)(*(float *)v48 - *v13))
                                                                              + (float)((float)v50 * (float)v50)))
                                                              * (float)0.5))
                                              * (float)v56)
                                      - (float)1.5)
                      * (float)v56);
          v58 = (float)(*((float *)p_hintNodeIndex + 1)
                      + (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v57 * (float)v54) * (float)v57)
                                                                                              - (float)1.5)
                                                                              * (float)v57)
                                                                      * (float)v54)
                                                              * (float)((float)-(float)((float)((float)((float)v57 * (float)v54)
                                                                                              * (float)v57)
                                                                                      - (float)1.5)
                                                                      * (float)v57))
                                                      - (float)1.5)
                                      * (float)((float)-(float)((float)((float)((float)v57 * (float)v54) * (float)v57)
                                                              - (float)1.5)
                                              * (float)v57))
                              * (float)v52));
          if ( *(unsigned __int8 *)(v48 + 19) == v38 )
          {
            if ( EncounterGroup->searchPointList.list[v46].visited )
            {
              if ( v115->valueInteger != 0 && idAI2::GetDebugLevel() > 0 )
              {
                v126 = idColor::colorDkGrey;
                v59 = idEntity::GetPhysics(this: ai);
                v60 = clientGame->renderWorld->__vftable;
                v61 = (int)v59->GetOrigin(this: v59, a2: 0);
                ((void (__fastcall *)(idRenderWorld *, idColor *, int, int, double))v60->DebugArrow)(
                  a1: clientGame->renderWorld,
                  a2: &v126,
                  a3: v61,
                  a4: v49,
                  a5: 2.0);
                LODWORD(v62) = LODWORD(v58);
                HIDWORD(v62) = *(unsigned __int8 *)(v49 + 19);
                v65 = va::va(
                        this: &v132,
                        fmt: "%d:%.0f",
                        a3: v62,
                        a4: v64,
                        a5: v63,
                        a6: (int)v100,
                        a7: (int)v101,
                        a8: v102,
                        a9: v103,
                        a10: v104,
                        a11: v105,
                        v58);
                ((void (__fastcall *)(idRenderWorld *, va *, int, idRenderWorld_vtbl *, idColor *, int, int, _DWORD, double))clientGame->renderWorld->DebugText)(
                  a1: clientGame->renderWorld,
                  a2: v65,
                  a3: v49,
                  a4: clientGame->renderWorld->__vftable,
                  a5: &v126,
                  a6: 1,
                  a7: 2000,
                  a8: 0,
                  a9: 0.5);
              }
            }
            else
            {
              if ( v44 == -1 || v58 < v43 )
              {
                eyePos.x = *(float *)v48;
                v44 = v45;
                v43 = v58;
                eyePos.y = *(float *)(v48 + 4);
                eyePos.z = *(float *)(v48 + 8);
                ai->aiVolatile.memory.currentSearchHintIndex = *p_hintNodeIndex;
              }
              if ( v115->valueInteger != 0 && idAI2::GetDebugLevel() > 0 )
              {
                v127 = idColor::colorLtGrey;
                v66 = idEntity::GetPhysics(this: ai);
                v67 = clientGame->renderWorld->__vftable;
                v68 = (int)v66->GetOrigin(this: v66, a2: 0);
                ((void (__fastcall *)(idRenderWorld *, idColor *, int, int, double))v67->DebugArrow)(
                  a1: clientGame->renderWorld,
                  a2: &v127,
                  a3: v68,
                  a4: v49,
                  a5: 2.0);
                LODWORD(v69) = LODWORD(v58);
                HIDWORD(v69) = *(unsigned __int8 *)(v49 + 19);
                v72 = va::va(
                        this: &v132,
                        fmt: "%d:%.0f",
                        a3: v69,
                        a4: v71,
                        a5: v70,
                        a6: (int)v100,
                        a7: (int)v101,
                        a8: v102,
                        a9: v103,
                        a10: v104,
                        a11: v105,
                        v58);
                ((void (__fastcall *)(idRenderWorld *, va *, int, idRenderWorld_vtbl *, idColor *, int, int, _DWORD, double))clientGame->renderWorld->DebugText)(
                  a1: clientGame->renderWorld,
                  a2: v72,
                  a3: v49,
                  a4: clientGame->renderWorld->__vftable,
                  a5: &v127,
                  a6: 1,
                  a7: 2000,
                  a8: 0,
                  a9: 0.5);
              }
            }
          }
          ++v45;
          ++v46;
        }
        while ( v45 < EncounterGroup->searchPointList.num );
        if ( v44 != -1 )
        {
          if ( idEncounterGroup::NumUnsearchedSearchPointsForGroup(this: EncounterGroup, aas: v10, grouping: v38) == 1 )
            idEncounterGroup::SetSearchPointGroupUnvisited(this: EncounterGroup, aas: v10, grouping: v38);
          EncounterGroup->searchPointList.list[v44].visited = true;
        }
        v5 = this;
        p_searchAction = (overrideAnim_t *)v114.value;
      }
    }
  }
  else
  {
    v24 = idEntity::GetPhysics(this: v8);
    v25 = v24->GetOrigin(this: v24, a2: 0);
    v26 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v15);
    idEncounterGroup::ScoreSearchPoints(
      this: EncounterGroup,
      aas: v10,
      senseOrigin: &v117,
      senseVelocity: &v26->velocity,
      trueOrigin: v25,
      searchHintGroupings: (idList<enum encounterGroupRole_t,5> *)&v122,
      numPerGroup: (idList<idVehicleState *,5> *)&v120);
    v27 = idEntity::GetPhysics(this: v8);
    v28 = v27->GetOrigin(this: v27, a2: 0);
    v29 = aiSenseState_t::GetConfirmedPhysicalSafe(this: v15);
    idEncounterGroup::AssignInitialSearchPoints(
      this: EncounterGroup,
      aas: v10,
      senseOrigin: &v117,
      senseVelocity: &v29->velocity,
      trueOrigin: v28,
      searchHintGroupings: &v122,
      numPerGrouping: &v120);
    if ( EncounterGroup->searchPointList.num == 0 )
    {
      v30 = idEntity::GetPhysics(this: v8);
      v31 = (idVec3 *)v30->GetOrigin(this: v30, a2: 0);
      p_aiGameState = &gameLocal->aiGameState;
      eyePos = *v31;
      v22 = 64.0;
      idSpawnId::idSpawnId(this: &v114, ent: v8);
      v33 = idSpawnId::idSpawnId(this: (idSpawnId *)&v113, ent: v8);
      v34 = idAILogic::idAILogic(this: &v130, ai);
      idAIWorldState::AddEntityState(
        this: &ai->aiVolatile.world.worldState,
        gameState: p_aiGameState,
        owner: v34,
        entId: v33,
        stimulusType: AISTIMULUS_GROUP_SUSPECTED,
        stimulusAmount: 1.0,
        sourceId: v35);
    }
  }
  HIDWORD(v113) = ai->aiVolatile.memory.currentSearchHintIndex;
  if ( HIDWORD(v113) == 0 )
  {
    hintData = 14;
    goto LABEL_52;
  }
  v73 = (aas2HintNode_t *)((int (__fastcall *)(idAAS2 *))v10->GetHintNode)(a1: v10);
  v111 = 1;
  aas2HintNode_t::GetOrientationVector(this: v73, dir: &v116, a3: v76, a4: v75, a5: v74);
  eyePos = v73->origin;
  if ( v73->hintType == 1 )
  {
    hintData = v73->hintData;
LABEL_52:
    *p_searchAction = hintData;
    goto LABEL_53;
  }
  if ( v73->hintType == 0 )
  {
    v78 = idVec3::ToYaw(this: &v116);
    v79 = (float)(v73->origin.z - v13[2]);
    v80 = v78;
    v81 = (float)(v73->origin.y - v13[1]);
    v118.x = v73->origin.x - *v13;
    v118.z = v79;
    v118.y = v81;
    v82 = (float)((float)v78 - idVec3::ToYaw(this: &v118));
    v119.pitch = 0.0;
    v119.roll = 0.0;
    v83 = 2 * (4 - ((int)v82 + ((int)v82 < 0 ? 0x168 : 0) + 45) / 90);
    v113 = (unsigned int)v83 | 0x5A00000000LL;
    v119.yaw = (float)((float)v113 * (float)45.0) + (float)v80;
    idAngles::ToVectors(this: &v119, forward: &v116, right: nullptr, up: nullptr);
    v84 = (v73->dirFlags >> (8 - v83)) | (v73->dirFlags << v83);
    HIDWORD(v85) = (((v73->dirFlags >> (8 - v83)) | (unsigned __int8)(v73->dirFlags << v83)) & 0xC) == 4;
    if ( (v84 & 0x83) == 0x83 )
    {
      *p_searchAction = ANIMOVERRIDE_SEARCH_LOOK_AROUND;
LABEL_50:
      LODWORD(v85) = v73->radius;
      v113 = v85;
      v22 = (float)v85;
      goto LABEL_53;
    }
    if ( (v84 & 0x60) == 0x40 )
    {
      if ( (((v73->dirFlags >> (8 - v83)) | (unsigned __int8)(v73->dirFlags << v83)) & 0xC) == 4 )
      {
        *p_searchAction = ANIMOVERRIDE_SEARCH_LOOK_BOTH;
        goto LABEL_50;
      }
      if ( (v84 & 0x60) == 0x40 )
      {
        *p_searchAction = ANIMOVERRIDE_SEARCH_LOOK_LEFT;
        goto LABEL_50;
      }
    }
    *p_searchAction = (((v73->dirFlags >> (8 - v83)) | (unsigned __int8)(v73->dirFlags << v83)) & 0xC) != 4
                    ? ANIMOVERRIDE_NONE
                    : ANIMOVERRIDE_SEARCH_LOOK_RIGHT;
    goto LABEL_50;
  }
LABEL_53:
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v122);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v120);
  v21 = v115;
_M491618:
  if ( v21->valueInteger != 0 && idAI2::GetDebugLevel() > 0 )
  {
    clientGame->renderWorld->DebugPoint(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)&idColor::colorPurple,
      a3: &eyePos,
      a4: 2000,
      a5: false);
    v86 = idEntity::GetPhysics(this: ai);
    v87 = clientGame->renderWorld->__vftable;
    v88 = (int)v86->GetOrigin(this: v86, a2: 0);
    ((void (__fastcall *)(idRenderWorld *, idColor *, int, idVec3 *, double))v87->DebugArrow)(
      a1: clientGame->renderWorld,
      a2: &idColor::colorPurple,
      a3: v88,
      a4: &eyePos,
      a5: 2.0);
  }
  v89.__vftable = v10->__vftable;
  v90 = (int)v10->DefaultSearchBounds(this: (idAAS2 *)&v130, result: (idBounds *)v10);
  v91 = v89.PointReachableAreaNum(this: v10, a2: nullptr, a3: &eyePos, a4: (const idBounds *)v90, a5: 2, a6: 1);
  v10->PushPointIntoAreaNum(this: v10, a2: v91, a3: &eyePos);
  ai->SetWalkState(this: ai, a2: WALKSTATE_WALKING);
  if ( idActor::IsCrouching(this: ai) )
  {
    v92 = idEventArg::idEventArg(this: &v124, data: ai);
    idEventReceiver::ProcessEvent(
      this: v125,
      result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
      ev: *(const idEventDef **)&v92->type,
      arg1: (const idEventArg *)LODWORD(v92->value.v[1]));
  }
  x = eyePos.x;
  v94 = eyePos.y;
  v95 = v111;
  v96 = eyePos.z;
  v97 = v116.y;
  v98 = v116.z;
  v121[1] = v116.x;
  ai->aiVolatile.memory.cachedDestination.x = eyePos.x;
  ai->aiVolatile.memory.cachedDestination.y = v94;
  ai->aiVolatile.memory.cachedDestination.z = v96;
  v121[2] = v97;
  v121[3] = v98;
  HIBYTE(v121[0]) = 118;
  v129[1] = v22;
  v123[1] = x;
  HIBYTE(v128[0]) = 105;
  v123[2] = v94;
  v123[3] = v96;
  v128[1] = v95;
  HIBYTE(v129[0]) = 102;
  HIBYTE(v125[0].__vftable) = 105;
  v125[0].listenerList = (idList<idEventReceiver *,5> *)2;
  HIBYTE(v123[0]) = 118;
  v124.type = 105;
  v124.value.i = 29;
  v99 = idEventArg::idEventArg(this: &v131, data: ai);
  memcpy(Dst: v110, Src: v121, Size: sizeof(v110));
  memcpy(Dst: v109, Src: v128, Size: sizeof(v109));
  memcpy(Dst: v108, Src: v129, Size: sizeof(v108));
  memcpy(Dst: v107, Src: v125, Size: sizeof(v107));
  memcpy(Dst: v106, Src: v123, Size: sizeof(v106));
  idEventReceiver::ProcessEvent(
    this: (idEventReceiver *)&v130,
    result: (idEventArg *)&ai->aiVolatile.fsms.actionManager.legsFSM.actionsQueue,
    ev: *(const idEventDef **)&v99->type,
    arg1: (const idEventArg *)LODWORD(v99->value.v[1]),
    arg2: (const idEventArg *)LODWORD(v99->value.v[2]),
    arg3: (const idEventArg *)__ROL4__(*(_DWORD *)&v124.type, 32),
    arg4: (const idEventArg *)LODWORD(v124.value.v[1]),
    arg5: (const idEventArg *)LODWORD(v124.value.v[2]),
    arg6: v100,
    arg7: v101);
  idAIState::StartQueuedActions(this: v5, ai, parentFSM: fsm, curTime);
}


// ========================================================================
// __unwind$491180
// EA  : 0x82AF1180
// RVA : 0x00AF1180
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void _unwind_491180()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 5008 + 384));
}


// ========================================================================
// __unwind$491181
// EA  : 0x82AF11A8
// RVA : 0x00AF11A8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void _unwind_491181()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 5008 + 432));
}


// ========================================================================
// ?SearchChatterHelper@@YAXPAVidAI2@@H@Z
// EA  : 0x82AF11D0
// RVA : 0x00AF11D0
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void __fastcall SearchChatterHelper(idAI2 *ai, const int curTime)
{
  idCombatStage *CurrentCombatStage; // r3
  char v4; // r11

  if ( idAI2::GetCurrentCombatStage(this: ai) == nullptr
    || (CurrentCombatStage = idAI2::GetCurrentCombatStage(this: ai),
        v4 = 0,
        (*((_BYTE *)CurrentCombatStage + 92) & 0x40) != 0) )
  {
    v4 = 1;
  }
  if ( v4 != 0 )
    idAI2::GetAlertCycleFSM(this: ai);
}


// ========================================================================
// ?AIState_EnterState@idSearch_Unreachable@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AF1238
// RVA : 0x00AF1238
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void __fastcall idSearch_Unreachable::AIState_EnterState(
        idSearch_Unreachable *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  int value; // r8
  idEntity *v8; // r3
  idEntity *v9; // r30
  const idAAS2 *v10; // r3
  idAIEntityState *v11; // r3
  aiSenseState_t *v12; // r30
  idEventArg *v13; // r3
  idEventArg v14; // [sp+90h] [-60h] BYREF
  idEventReceiver v15[5]; // [sp+B0h] [-40h] BYREF

  value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v8 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v9 = idEntity::CastTo(c: v8);
  }
  else
  {
    v9 = nullptr;
  }
  v10 = ai->GetAAS(this: ai);
  if ( v9 != nullptr
    && v10 != nullptr
    && (v11 = idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v9)) != nullptr )
  {
    v12 = v11->senses.ptr[v11->lastSense];
    idAI2::EndActionScript(this: ai);
    LODWORD(fsm[1].value.v[2]) = this;
    aiSenseState_t::GetConfirmedPhysicalSafe(this: v12);
    v13 = idEventArg::idEventArg(this: &v14, data: ai);
    idEventReceiver::ProcessEvent(
      this: v15,
      result: fsm,
      ev: *(const idEventDef **)&v13->type,
      arg1: (const idEventArg *)LODWORD(v13->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v13->value.v[2]));
  }
  else
  {
    idState::SetEnterFailed(this, failed: true);
  }
}


// ========================================================================
// ?AIState_ExitState@idSearch_Unreachable@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AF1390
// RVA : 0x00AF1390
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void __fastcall idSearch_Unreachable::AIState_ExitState(
        idSearch_Unreachable *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  int value; // r8
  idEntity *v6; // r3
  idEntity *v7; // r4

  if ( fsm->lastTransitionCode == 255 )
  {
    value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v6 = gameLocal->entities.ptr[value & 0x1FFF];
      if ( v6 != nullptr )
      {
        v7 = idEntity::CastTo(c: v6);
        if ( v7 != nullptr )
          idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v7);
      }
    }
  }
}


// ========================================================================
// ?AIState_Work@idSearch_Wait@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AF1420
// RVA : 0x00AF1420
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void __fastcall idSearch_Wait::AIState_Work(idSearch_Wait *this, idAI2 *ai, idAIFSM *fsm, int curTime)
{
  if ( idAI2::GetCurrentCombatStage(this: ai) != nullptr )
    SearchChatterHelper(ai, curTime);
}


// ========================================================================
// ?AIState_ExitState@idSearch_Wait@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AF1470
// RVA : 0x00AF1470
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void __fastcall idSearch_Wait::AIState_ExitState(idSearch_Wait *this, idAI2 *ai, idAIFSM *fsm, const int curTime)
{
  unsigned int v5; // r3
  int value; // r8
  idEntity *v7; // r3
  idEntity *v8; // r4

  v5 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v5;
  if ( ((v5 >> 10) & 0x7FFF) % 0x64 < 0x64 && fsm->lastTransitionCode == 255 )
  {
    value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v7 = gameLocal->entities.ptr[value & 0x1FFF];
      if ( v7 != nullptr )
      {
        v8 = idEntity::CastTo(c: v7);
        if ( v8 != nullptr )
          idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v8);
      }
    }
  }
}


// ========================================================================
// ?AIState_EnterState@idSearch_PerformAction@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AF1558
// RVA : 0x00AF1558
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void __fastcall idSearch_PerformAction::AIState_EnterState(
        idSearch_PerformAction *this,
        idAI2 *ai,
        idEventArg *fsm,
        const int curTime)
{
  int value; // r10
  idEntity *v8; // r3
  idInfoLookTarget *v9; // r3
  overrideAnim_t searchAction; // r30
  idEventArg *v11; // r28
  idEventArg *v12; // r3
  _BYTE v13[20]; // [sp+70h] [-C0h] BYREF
  _DWORD v14[5]; // [sp+90h] [-A0h] BYREF
  int v15; // [sp+B0h] [-80h]
  int v16; // [sp+B4h] [-7Ch]
  idEventArg v17; // [sp+D0h] [-60h] BYREF
  idEventArg v18[3]; // [sp+F0h] [-40h] BYREF

  value = ai->aiVolatile.focus.foci.ptr[0].focusEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v8 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v9 = (idInfoLookTarget *)idEntity::CastTo(c: v8);
  }
  else
  {
    v9 = nullptr;
  }
  if ( idInfoLookTarget::CastTo(c: v9) != nullptr )
    idAI2::ClearAimFocus(this: ai);
  searchAction = ai->aiVolatile.memory.searchAction;
  ai->aiVolatile.memory.searchAction = ANIMOVERRIDE_NONE;
  idAI2::EndActionScript(this: ai);
  LODWORD(fsm[1].value.v[2]) = this;
  if ( searchAction != ANIMOVERRIDE_NONE )
  {
    v16 = searchAction;
    HIBYTE(v15) = 105;
    v12 = idEventArg::idEventArg(this: v18, data: ai);
    idEventReceiver::ProcessEvent(
      this: (idEventReceiver *)&v17,
      result: fsm,
      ev: *(const idEventDef **)&v12->type,
      arg1: (const idEventArg *)LODWORD(v12->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v12->value.v[2]));
  }
  else
  {
    HIBYTE(v14[0]) = 105;
    v14[1] = 1;
    HIBYTE(v15) = 105;
    v16 = 500;
    v11 = idEventArg::idEventArg(this: &v17, data: ai);
    memcpy(Dst: v13, Src: v14, Size: sizeof(v13));
    idEventReceiver::ProcessEvent(
      this: (idEventReceiver *)v18,
      result: fsm,
      ev: *(const idEventDef **)&v11->type,
      arg1: (const idEventArg *)LODWORD(v11->value.v[1]),
      arg2: (const idEventArg *)LODWORD(v11->value.v[2]),
      arg3: (const idEventArg *)__ROL4__(v15, 32));
  }
}


// ========================================================================
// ?CanUse@idSearchFSM@@UBA_NPAVidFiniteStateMachine@@H@Z
// EA  : 0x82AF16D8
// RVA : 0x00AF16D8
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

int __fastcall idSearchFSM::CanUse(idSearchFSM *this, idFiniteStateMachine *fsm, const int curTime)
{
  idEntity *Owner; // r3
  idEntity *v4; // r31
  int bindMaster; // r8
  idEntity *v7; // r3
  idEntity *v8; // r4
  idAIEntityState *v9; // r30
  idEncounterGroup *EncounterGroup; // r3

  Owner = idFiniteStateMachine::GetOwner(this: fsm);
  v4 = Owner;
  if ( (*(_BYTE *)(*(_DWORD *)Owner[14].renderModelInfo.editorModel.baseBuffer + 85) & 1) != 0
    && BYTE2(Owner[13].numPVSAreas) == 0
    && (bindMaster = (int)Owner[72].bindInfo.bindMaster, gameLocal->spawnIds.ptr[bindMaster & 0x1FFF] == bindMaster >> 13)
    && (v7 = gameLocal->entities.ptr[bindMaster & 0x1FFF]) != nullptr
    && (v8 = idEntity::CastTo(c: v7)) != nullptr
    && (v9 = idAIWorldState::StateForEntity(this: (idAIWorldState *)&v4[17].dormancy.endForceTime, ent: v8)) != nullptr
    && (idAI2::GetEncounterGroup(this: (idAI2 *)v4) == nullptr
     || (EncounterGroup = idAI2::GetEncounterGroup(this: (idAI2 *)v4),
         !idEncounterGroup::GetShouldAmbush(this: EncounterGroup)))
    && idAIMemory::GetUsedProp(this: (idAIMemory *)((char *)&v4[72].bindInfo + 112)) == nullptr
    && ((v4[70].dormancy.lastTimeInPlayerPVS & 0x1000) != 0 || v9->curAwareness == 2) )
  {
    return BYTE2(v4[73].__vftable);
  }
  else
  {
    return 0;
  }
}


// ========================================================================
// ?AIState_ExitState@idAlertCycle_Melee@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AF1810
// RVA : 0x00AF1810
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void __fastcall idAlertCycle_Melee::AIState_ExitState(idAction_Dodge *this, idAI2 *ai, idAIFSM *fsm, const int curTime)
{
  if ( (unsigned __int8)idLobbyBackend360::StartArbitration(pexcept: (_exception *)ai) == 0 )
  {
    idAI2::GetDefaultMovementMode(this: ai);
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)&ai->aiVolatile.physics.moveState);
  }
}


// ========================================================================
// ?AIState_Work@idSearch_MoveToPoint@@UAAXPAVidAI2@@PAVidAIFSM@@H@Z
// EA  : 0x82AF1868
// RVA : 0x00AF1868
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void __fastcall idSearch_MoveToPoint::AIState_Work(
        idSearch_MoveToPoint *this,
        idAI2 *ai,
        idAIFSM *fsm,
        const int curTime)
{
  idCombatStage *CurrentCombatStage; // r3
  char v7; // r11
  unsigned int v8; // r3
  int value; // r8
  idEntity *v10; // r3
  idEntity *v11; // r4
  idPhysics *Physics; // r3
  const idVec3 *v13; // r22
  int v14; // r9
  idEntity *v15; // r3
  idInfoLookTarget *v16; // r3
  idInfoLookTarget *v17; // r3
  double v18; // fp10
  double v19; // fp8
  idAIOrientation *BodyOrientation; // r3
  double v21; // fp10
  idGameLocal *v22; // r11
  int v23; // r24
  int v24; // r26
  int v25; // r9
  idInfoLookTargetGroup *v26; // r3
  idInfoLookTargetGroup *v27; // r3
  idInfoLookTargetGroup *v28; // r29
  float x; // r11
  int v30; // r28
  int v31; // r30
  int v32; // r9
  idEntity *v33; // r3
  idInfoLookTarget *v34; // r3
  idInfoLookTarget *v35; // r28
  int v36; // r27
  double v37; // fp25
  int v38; // r29
  idInfoLookTarget *v39; // r30
  double v40; // fp11
  double v41; // fp8
  double v42; // fp5
  double v45; // fp9
  double v46; // fp10
  double v47; // fp9
  double v48; // fp31
  double v49; // fp29
  double v50; // fp28
  double v51; // fp27
  idAIOrientation *v52; // r3
  double v53; // fp8
  idVec3 v54; // [sp+50h] [-160h] BYREF
  float v55[4]; // [sp+60h] [-150h] BYREF
  float v56[4]; // [sp+70h] [-140h] BYREF
  idList<idVoiceEvent const *,5> v57; // [sp+80h] [-130h] BYREF
  int v58; // [sp+90h] [-120h] BYREF

  if ( idAI2::GetCurrentCombatStage(this: ai) == nullptr
    || (CurrentCombatStage = idAI2::GetCurrentCombatStage(this: ai),
        v7 = 0,
        (*((_BYTE *)CurrentCombatStage + 92) & 0x40) != 0) )
  {
    v7 = 1;
  }
  if ( v7 != 0 )
    idAI2::GetAlertCycleFSM(this: ai);
  v8 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v8;
  if ( ((v8 >> 10) & 0x7FFF) % 0x64 < 0x64 && fsm->lastTransitionCode == 255 )
  {
    value = ai->aiVolatile.memory.currentEnemy.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v10 = gameLocal->entities.ptr[value & 0x1FFF];
      if ( v10 != nullptr )
      {
        v11 = idEntity::CastTo(c: v10);
        if ( v11 != nullptr )
          idAIWorldState::StateForEntity(this: &ai->aiVolatile.world.worldState, ent: v11);
      }
    }
  }
  Physics = idEntity::GetPhysics(this: ai);
  v13 = Physics->GetOrigin(this: Physics, a2: 0);
  if ( (unsigned __int8)idFocusInfo::HasFocus(this: ai->aiVolatile.focus.foci.ptr) != 0 )
  {
    v14 = ai->aiVolatile.focus.foci.ptr[0].focusEntity.spawnId.value;
    LODWORD(v54.x) = &ai->aiVolatile.focus.foci.ptr[0].focusEntity;
    if ( gameLocal->spawnIds.ptr[v14 & 0x1FFF] == v14 >> 13 && (v15 = gameLocal->entities.ptr[v14 & 0x1FFF]) != nullptr )
      v16 = (idInfoLookTarget *)idEntity::CastTo(c: v15);
    else
      v16 = nullptr;
    v17 = idInfoLookTarget::CastTo(c: v16);
    if ( v17 != nullptr )
    {
      v17->GetAimPoint(this: v17, a2: ai->aiVolatile.focus.foci.ptr[0].aimPoint, a3: (idVec3 *)v55);
      v18 = (float)(v55[2] - v13->z);
      v19 = (float)(v55[1] - v13->y);
      v54.x = v55[0] - v13->x;
      v54.z = v18;
      v54.y = v19;
      idVec3::NormalizeFast(this: &v54);
      BodyOrientation = idAI2::GetBodyOrientation(this: ai);
      v21 = (float)((float)(v54.x * BodyOrientation->axis.mat[0].x)
                  + (float)((float)(BodyOrientation->axis.mat[0].z * v54.z)
                          + (float)(BodyOrientation->axis.mat[0].y * v54.y)));
      LODWORD(v54.x) = &BodyOrientation->axis;
      if ( v21 < ai_lookTargetDropThreshold.valueFloat )
        idAI2::ClearAimFocus(this: ai);
    }
  }
  if ( (unsigned __int8)idFocusInfo::HasFocus(this: ai->aiVolatile.focus.foci.ptr) == 0 )
  {
    v57.granularity = 1;
    v57.listStatic = 1;
    v57.memTag = 5;
    v57.size = 32;
    v57.num = 0;
    v57.list = (const idVoiceEvent **)&v58;
    v22 = gameLocal;
    v23 = 0;
    if ( gameLocal->lookTargetGroups.num > 0 )
    {
      v24 = 0;
      do
      {
        if ( v57.num >= v57.size )
          break;
        v25 = v22->lookTargetGroups.list[v24].spawnId.value;
        if ( v22->spawnIds.ptr[v25 & 0x1FFF] == v25 >> 13 )
        {
          v26 = (idInfoLookTargetGroup *)v22->entities.ptr[v25 & 0x1FFF];
          if ( v26 != nullptr )
          {
            v27 = idInfoLookTargetGroup::CastTo(c: v26);
            v28 = v27;
            if ( v27 != nullptr && idInfoLookTargetGroup::IsInside(this: v27, pos: v13) )
            {
              v30 = 0;
              LODWORD(v54.x) = v28->targets.num;
              x = v54.x;
              if ( SLODWORD(v54.x) > 0 )
              {
                v31 = 0;
                do
                {
                  if ( v57.num >= v57.size )
                    break;
                  v54.x = x;
                  if ( v30 < SLODWORD(x)
                    && (v32 = v28->targets.list[v31].spawnId.value, gameLocal->spawnIds.ptr[v32 & 0x1FFF] == v32 >> 13)
                    && (v33 = gameLocal->entities.ptr[v32 & 0x1FFF]) != nullptr )
                  {
                    v34 = (idInfoLookTarget *)idEntity::CastTo(c: v33);
                  }
                  else
                  {
                    v34 = nullptr;
                  }
                  LODWORD(v54.x) = idInfoLookTarget::CastTo(c: v34);
                  if ( LODWORD(v54.x) != 0 )
                    idList<idDeclMD6 const *,5>::AddUnique(this: &v57, obj: (const idVoiceEvent *const *)&v54);
                  ++v30;
                  ++v31;
                  LODWORD(v54.x) = v28->targets.num;
                  x = v54.x;
                }
                while ( v30 < SLODWORD(v54.x) );
              }
            }
            v22 = gameLocal;
          }
        }
        ++v23;
        ++v24;
      }
      while ( v23 < v22->lookTargetGroups.num );
    }
    v35 = nullptr;
    v36 = 0;
    v37 = 3.4028235e38;
    if ( v57.num > 0 )
    {
      v38 = 0;
      do
      {
        v39 = (idInfoLookTarget *)v57.list[v38];
        if ( idInfoLookTarget::CanLook(this: v39, looker: ai) )
        {
          v39->GetAimPoint(this: v39, a2: AIMPOINT_BEST, a3: (idVec3 *)v56);
          v40 = (float)(v56[1] - v13->y);
          v41 = (float)(v56[0] - v13->x);
          v42 = (float)(v56[2] - v13->z);
          _FP13 = (float)((float)((float)((float)(v56[2] - v13->z) * (float)(v56[2] - v13->z))
                                + (float)((float)((float)(v56[0] - v13->x) * (float)(v56[0] - v13->x))
                                        + (float)((float)(v56[1] - v13->y) * (float)(v56[1] - v13->y))))
                        - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f10, f13, f1, f0 }
          v45 = __frsqrte(_FP10);
          v46 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v45
                                                                                              * (float)((float)((float)((float)v42 * (float)v42) + (float)((float)((float)v41 * (float)v41) + (float)((float)v40 * (float)v40))) * (float)0.5))
                                                                                      * (float)v45)
                                                                              - (float)1.5)
                                                              * (float)v45)
                                                      * (float)((float)((float)((float)v42 * (float)v42)
                                                                      + (float)((float)((float)v41 * (float)v41)
                                                                              + (float)((float)v40 * (float)v40)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v45
                                                                                      * (float)((float)((float)((float)v42 * (float)v42) + (float)((float)((float)v41 * (float)v41) + (float)((float)v40 * (float)v40)))
                                                                                              * (float)0.5))
                                                                              * (float)v45)
                                                                      - (float)1.5)
                                                      * (float)v45))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v45
                                                              * (float)((float)((float)((float)v42 * (float)v42)
                                                                              + (float)((float)((float)v41 * (float)v41)
                                                                                      + (float)((float)v40 * (float)v40)))
                                                                      * (float)0.5))
                                                      * (float)v45)
                                              - (float)1.5)
                              * (float)v45));
          v47 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v45 * (float)((float)((float)((float)v42 * (float)v42) + (float)((float)((float)v41 * (float)v41) + (float)((float)v40 * (float)v40))) * (float)0.5))
                                                                                              * (float)v45)
                                                                                      - (float)1.5)
                                                                      * (float)v45)
                                                              * (float)((float)((float)((float)v42 * (float)v42)
                                                                              + (float)((float)((float)v41 * (float)v41)
                                                                                      + (float)((float)v40 * (float)v40)))
                                                                      * (float)0.5))
                                                      * (float)((float)-(float)((float)((float)((float)v45
                                                                                              * (float)((float)((float)((float)v42 * (float)v42) + (float)((float)((float)v41 * (float)v41) + (float)((float)v40 * (float)v40))) * (float)0.5))
                                                                                      * (float)v45)
                                                                              - (float)1.5)
                                                              * (float)v45))
                                              - (float)1.5)
                              * (float)((float)-(float)((float)((float)((float)v45
                                                                      * (float)((float)((float)((float)v42 * (float)v42)
                                                                                      + (float)((float)((float)v41 * (float)v41)
                                                                                              + (float)((float)v40 * (float)v40)))
                                                                              * (float)0.5))
                                                              * (float)v45)
                                                      - (float)1.5)
                                      * (float)v45))
                      * (float)((float)((float)((float)v42 * (float)v42)
                                      + (float)((float)((float)v41 * (float)v41) + (float)((float)v40 * (float)v40)))
                              * (float)0.5));
          v48 = (float)((float)((float)-(float)((float)((float)v47 * (float)v46) - (float)1.5) * (float)v46)
                      * (float)((float)((float)(v56[2] - v13->z) * (float)(v56[2] - v13->z))
                              + (float)((float)((float)(v56[0] - v13->x) * (float)(v56[0] - v13->x))
                                      + (float)((float)(v56[1] - v13->y) * (float)(v56[1] - v13->y)))));
          v49 = (float)((float)(v56[0] - v13->x)
                      * (float)((float)-(float)((float)((float)v47 * (float)v46) - (float)1.5) * (float)v46));
          v50 = (float)((float)(v56[1] - v13->y)
                      * (float)((float)-(float)((float)((float)v47 * (float)v46) - (float)1.5) * (float)v46));
          v51 = (float)((float)(v56[2] - v13->z)
                      * (float)((float)-(float)((float)((float)v47 * (float)v46) - (float)1.5) * (float)v46));
          if ( v48 < v39->maxDist )
          {
            v52 = idAI2::GetBodyOrientation(this: ai);
            v53 = (float)((float)(v52->axis.mat[0].x * (float)v49)
                        + (float)((float)(v52->axis.mat[0].z * (float)v51) + (float)(v52->axis.mat[0].y * (float)v50)));
            LODWORD(v54.x) = &v52->axis;
            if ( v53 > ai_lookTargetThreshold.valueFloat && v48 < v37 )
            {
              v35 = v39;
              v37 = v48;
            }
          }
        }
        ++v36;
        ++v38;
      }
      while ( v36 < v57.num );
      if ( v35 != nullptr )
      {
        LODWORD(v54.y) = (int)(float)(v35->lookTime * (float)1000.0);
        idAI2::SetAimFocusEntity(
          this: ai,
          ent: v35,
          keepFocusInView: false,
          aimPoint: AIMPOINT_BEST,
          timeout: SLODWORD(v54.y));
        idInfoLookTarget::SetLooking(this: v35, looker: ai);
      }
    }
    if ( (v57.listStatic == 0 || v57.listStatic == 2) && v57.list != nullptr )
      idMem::Free(this: &mem, ptr: v57.list, align: ALIGN_16);
  }
}


// ========================================================================
// __unwind$492172
// EA  : 0x82AF1E30
// RVA : 0x00AF1E30
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void _unwind_492172()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 432 + 128));
}


// ========================================================================
// `dynamic initializer for 'ai_lookTargetDropThreshold''
// EA  : 0x83369710
// RVA : 0x01369710
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_lookTargetDropThreshold__()
{
  idCVar::idCVar(
    this: &ai_lookTargetDropThreshold,
    name: "ai_lookTargetDropThreshold",
    value: "idMath::Cos( 75.0f )",
    flags: 0,
    description: "dot product of angle where searching AI will stop looking at a look target",
    valueMin: -1.0,
    valueMax: 1.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"Could not find AI state, idVS_ds_Car_Chase! ",
    a9: (int)"Could not find AI state, idVS_ds_Car_Chase! ",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_lookTargetDropThreshold__);
}


// ========================================================================
// `dynamic initializer for 'ai_lookTargetThreshold''
// EA  : 0x83369778
// RVA : 0x01369778
// PDB : w:\tech5\tungsten\game\ai\fsm\fsm_search.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_lookTargetThreshold__()
{
  idCVar::idCVar(
    this: &ai_lookTargetThreshold,
    name: "ai_lookTargetThreshold",
    value: "idMath::Cos( 60.0f )",
    flags: 0,
    description: "dot product of angle where searching AI will start looking at a look target",
    valueMin: -1.0,
    valueMax: 1.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"Could not find AI state, idVS_ds_Car_Chase! ",
    a9: (int)"Could not find AI state, idVS_ds_Car_Chase! ",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_lookTargetThreshold__);
}

