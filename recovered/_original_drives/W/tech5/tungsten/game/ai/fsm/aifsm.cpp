
// ========================================================================
// ?Evaluate@Shared_UnhandledError@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB1080
// RVA : 0x00AB1080
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsm.cpp
// ========================================================================

idAIStateTransition::aiTransCode_t __fastcall Shared_UnhandledError::Evaluate(
        Shared_UnhandledError *this,
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
    return 0;
  v7 = idFiniteStateMachine::HadError(this: FullPath);
  result = 3;
  if ( !v7 )
    return 0;
  return result;
}


// ========================================================================
// ?Evaluate@idStateTransition_StateError@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB10C8
// RVA : 0x00AB10C8
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsm.cpp
// ========================================================================

int __fastcall idStateTransition_StateError::Evaluate(
        idStateTransition_StateError *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !idFiniteStateMachine::HadError(this: parentFSM) ? 0 : 4;
}


// ========================================================================
// ?GetAI@idAIFSM@@QBAPAVidAI2@@XZ
// EA  : 0x82AB1100
// RVA : 0x00AB1100
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsm.cpp
// ========================================================================

// attributes: thunk
idAI2 *__fastcall idAIFSM::GetAI(idAIFSM *this)
{
  return (idAI2 *)idFiniteStateMachine::GetOwner(this);
}


// ========================================================================
// ?AppendDefaultTransitions@idAIFSM@@UAAXPAVidState@@@Z
// EA  : 0x82AB1108
// RVA : 0x00AB1108
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsm.cpp
// ========================================================================

void __fastcall idAIFSM::AppendDefaultTransitions(idAIFSM *this, idState *state)
{
  if ( state != this->GetErrorState(this) && state != this->GetDoneState(this) )
  {
    idState::AddStateTransition(
      this: state,
      fsm: this,
      transType: &idStateTransition_UnhandledChildError::Type,
      nextStateType: &idAIStateError::Type);
    idState::AddStateTransition(
      this: state,
      fsm: this,
      transType: &idStateTransition_StateError::Type,
      nextStateType: &idAIStateError::Type);
  }
}


// ========================================================================
// ?Evaluate@Shared_CanUse@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB1190
// RVA : 0x00AB1190
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsm.cpp
// ========================================================================

int __fastcall Shared_CanUse::Evaluate(
        Shared_CanUse *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return 452;
}


// ========================================================================
// ?Evaluate@Shared_DefaultUse@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB1198
// RVA : 0x00AB1198
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsm.cpp
// ========================================================================

int __fastcall Shared_DefaultUse::Evaluate(
        Shared_DefaultUse *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return 451;
}


// ========================================================================
// ?Evaluate@Shared_ChildFinished@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB11A0
// RVA : 0x00AB11A0
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsm.cpp
// ========================================================================

int __fastcall Shared_ChildFinished::Evaluate(
        Shared_ChildFinished *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !idState::IsChildDone(this: state) ? 0 : 0x1C4;
}


// ========================================================================
// ?Evaluate@Shared_MoveDone@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB11D8
// RVA : 0x00AB11D8
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsm.cpp
// ========================================================================

int __fastcall Shared_MoveDone::Evaluate(
        Shared_MoveDone *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return !idAI2::IsMoveDone(this: ai, checkAlignment: false) ? 0 : 0x1C4;
}


// ========================================================================
// ?InitStates@idAIFSM@@UAAXABVidFiniteStateMachineParams@@@Z
// EA  : 0x82AB1218
// RVA : 0x00AB1218
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsm.cpp
// ========================================================================

void __fastcall idAIFSM::InitStates(idAIFSM *this, const idFiniteStateMachineParams *params)
{
  idPhysics_StaticMulti::UpdateTime((bfx::BinaryReplayLogOut *)this);
  this->AddState(this, a2: gameLocal->errorState);
  this->AddState(this, a2: gameLocal->doneState);
}


// ========================================================================
// ?GetDoneState@idVehicleBaseFSM@@UBAPAVidState@@XZ
// EA  : 0x82AB1298
// RVA : 0x00AB1298
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsm.cpp
// ========================================================================

idAIStateDone *__fastcall idVehicleBaseFSM::GetDoneState(idAIFSM *this)
{
  return gameLocal->doneState;
}


// ========================================================================
// ?InternalCallEvent@idAIFSM@@MAA?AVidEventArg@@ABVidEventDef@@PBV2@@Z
// EA  : 0x82AB12B0
// RVA : 0x00AB12B0
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsm.cpp
// ========================================================================

idAIFSM *__fastcall idAIFSM::InternalCallEvent(
        idAIFSM *this,
        idFiniteStateMachine *result,
        const idEventDef *event,
        const idEventArg *args)
{
  idAIActionManager *p_clipModelName; // r30
  idFiniteStateMachine *p_legsFSM; // r29
  int FullPath; // r3
  idFiniteStateMachine *v11; // r30
  int GameMs; // r3
  idAIFSM_vtbl **v13; // r11
  idAIFSM *v14; // r10
  int i; // ctr
  char v17; // [sp+4Ch] [-54h] BYREF
  idEventReceiver v18[6]; // [sp+50h] [-50h] BYREF

  if ( event->type == EVENT_ACTION )
  {
    p_clipModelName = (idAIActionManager *)&idFiniteStateMachine::GetOwner(this: result)[36].clipModelInfo.clipModelName;
    if ( idAIActionManager::GetActionStateForEvent(this: p_clipModelName, event) != nullptr )
    {
      p_clipModelName->actionEventTransCode = 7;
      idEventReceiver::ProcessEventArgPtr(this: v18, result: (idEventArg *)p_clipModelName, ev: event, args);
      p_legsFSM = &p_clipModelName->legsFSM;
      FullPath = idFile_SaveGamePipelined::GetFullPath(this: (XGRAPHICS::IRInst *)result->actionCallerState);
      v11 = (idFiniteStateMachine *)FullPath;
      if ( FullPath != 0 && (idFiniteStateMachine *)FullPath != p_legsFSM )
      {
        GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
        idFiniteStateMachine::ExitChildStates(this: v11, parentFSM: result, curTime: GameMs);
      }
      idState::SetChildFSM(this: result->actionCallerState, parentFSM: result, childFSM_: p_legsFSM);
      v13 = (idAIFSM_vtbl **)&v17;
      result->actionCallerState = nullptr;
      v14 = (idAIFSM *)((char *)this - 4);
      for ( i = 5; i != 0; --i )
      {
        ++v13;
        v14 = (idAIFSM *)((char *)v14 + 4);
        v14->__vftable = *v13;
      }
      return this;
    }
    else
    {
      result->actionCallerState = nullptr;
      HIBYTE(this->__vftable) = 0;
      this->listenerList = nullptr;
      return this;
    }
  }
  else
  {
    idFiniteStateMachine::InternalCallEvent(this, (idEventArg *)result, event, args);
    return this;
  }
}


// ========================================================================
// ?InternalRespondsTo@idAIFSM@@MBA_NABVidEventDef@@@Z
// EA  : 0x82AB13E0
// RVA : 0x00AB13E0
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsm.cpp
// ========================================================================

BOOL __fastcall idAIFSM::InternalRespondsTo(idAIFSM *this, const idEventDef *event)
{
  idEntity *Owner; // r3

  if ( event->type != EVENT_ACTION )
    return idFiniteStateMachine::InternalRespondsTo(this, event);
  if ( this->actionCallerState == nullptr )
    return false;
  Owner = idFiniteStateMachine::GetOwner(this);
  return idAIActionManager::GetActionStateForEvent(
           this: (idAIActionManager *)&Owner[36].clipModelInfo.clipModelName,
           event) != nullptr;
}


// ========================================================================
// ?Evaluate@Shared_WorkTransCode@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB1470
// RVA : 0x00AB1470
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsm.cpp
// ========================================================================

int __fastcall Shared_WorkTransCode::Evaluate(
        Shared_WorkTransCode *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return parentFSM->lastWorkTransCode;
}


// ========================================================================
// ?Evaluate@Shared_FSMEventTransCode@@UBA?AW4aiTransCode_t@idAIStateTransition@@PAVidAI2@@PAVidAIFSM@@PAVidAIState@@H@Z
// EA  : 0x82AB1478
// RVA : 0x00AB1478
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsm.cpp
// ========================================================================

int __fastcall Shared_FSMEventTransCode::Evaluate(
        Shared_FSMEventTransCode *this,
        idAI2 *ai,
        idAIFSM *parentFSM,
        idAIState *state,
        const int curTime)
{
  return parentFSM->lastFSMEventTransCode;
}

