
// ========================================================================
// ?ExitChildStates@idFiniteStateMachine@@QAAXPAV1@H@Z
// EA  : 0x82AB2860
// RVA : 0x00AB2860
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

void __fastcall idFiniteStateMachine::ExitChildStates(
        idFiniteStateMachine *this,
        idFiniteStateMachine *parentFSM,
        int curTime)
{
  XGRAPHICS::IRInst *curState; // r3
  idFiniteStateMachine *FullPath; // r3

  curState = (XGRAPHICS::IRInst *)this->curState;
  if ( curState != nullptr )
  {
    this->lastTransitionCode = 2;
    FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: curState);
    if ( FullPath != nullptr )
      idFiniteStateMachine::ExitChildStates(this: FullPath, parentFSM: this, curTime);
    idState::ExitState(this: this->curState, fsm: this, curTime);
  }
}


// ========================================================================
// ?SetNextState@idFiniteStateMachine@@UAAXABUtransResult_t@idStateData@@H@Z
// EA  : 0x82AB28D0
// RVA : 0x00AB28D0
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

void __fastcall idFiniteStateMachine::SetNextState(
        idFiniteStateMachine *this,
        const idStateData::transResult_t *result,
        int curTime)
{
  this->SetState(this, a2: result, a3: curTime, a4: false);
}


// ========================================================================
// ?ForceUpdate@idFiniteStateMachine@@QAAXXZ
// EA  : 0x82AB28E8
// RVA : 0x00AB28E8
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

void __fastcall idFiniteStateMachine::ForceUpdate(idFiniteStateMachine *this)
{
  this->nextUpdateTime = -1;
}


// ========================================================================
// ?GetStatus@idFiniteStateMachine@@QBA?AW4fsmStatus_t@1@XZ
// EA  : 0x82AB28F8
// RVA : 0x00AB28F8
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

int __fastcall idFiniteStateMachine::GetStatus(idFiniteStateMachine *this)
{
  if ( this->curState == this->GetErrorState(this) )
    return 2;
  else
    return this->GetDoneState(this) != this->curState;
}


// ========================================================================
// ?SetError@idFiniteStateMachine@@QAAXPBVidTypeInfo@@H@Z
// EA  : 0x82AB2978
// RVA : 0x00AB2978
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

void __fastcall idFiniteStateMachine::SetError(idFiniteStateMachine *this, const idTypeInfo *transType, int transCode)
{
  idFSMCallback *callback; // r11
  idFSMCallback_vtbl *v7; // r28
  idTypeInfo *v8; // r3
  idState *curState; // r11

  callback = this->callback;
  if ( callback != nullptr )
  {
    v7 = callback->__vftable;
    v8 = this->curState->GetType(this: this->curState);
    v7->OnError(this: this->callback, a2: this, a3: v8, a4: transType, a5: transCode);
  }
  curState = this->curState;
  this->errorStateTransType = transType;
  this->errorTransCode = transCode;
  this->errorState = curState;
}


// ========================================================================
// ?HadError@idFiniteStateMachine@@QBA_NXZ
// EA  : 0x82AB29F0
// RVA : 0x00AB29F0
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

int __fastcall idFiniteStateMachine::HadError(idFiniteStateMachine *this)
{
  idFiniteStateMachine *i; // r31
  XGRAPHICS::IRInst *curState; // r30

  for ( i = this;
        i->errorTransCode <= 0;
        i = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: (XGRAPHICS::IRInst *)i->curState) )
  {
    curState = (XGRAPHICS::IRInst *)i->curState;
    if ( curState == (XGRAPHICS::IRInst *)i->GetErrorState(this: i) )
      break;
    if ( curState == nullptr || idFile_SaveGamePipelined::GetFullPath(this: curState) == 0 )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?IsInterruptible@idFiniteStateMachine@@QBA_NXZ
// EA  : 0x82AB2A90
// RVA : 0x00AB2A90
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

BOOL __fastcall idFiniteStateMachine::IsInterruptible(idFiniteStateMachine *this)
{
  return idState::IsInterruptible(this: this->curState);
}


// ========================================================================
// ?SetDefaultState@idFiniteStateMachine@@IAAXPBVidState@@@Z
// EA  : 0x82AB2A98
// RVA : 0x00AB2A98
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

void __fastcall idFiniteStateMachine::SetDefaultState(idFiniteStateMachine *this, idState *state)
{
  this->defaultStateType = (const idTypeInfo *)state->GetType(this: state);
}


// ========================================================================
// ?Init@idFiniteStateMachine@@QAAXABVidFiniteStateMachineParams@@@Z
// EA  : 0x82AB2AD8
// RVA : 0x00AB2AD8
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

void __fastcall idFiniteStateMachine::Init(idFiniteStateMachine *this, const idFiniteStateMachineParams *params)
{
  idFiniteStateMachine_vtbl *v3; // r10
  int v4; // r29
  int v5; // r30

  v3 = this->__vftable;
  this->manager = params->manager;
  ((void (*)(void))v3->InitStates)();
  v4 = 0;
  if ( this->states.num > 0 )
  {
    v5 = 0;
    do
    {
      idState::InitState(this: this->states.list[v5], fsm: this);
      this->AppendDefaultTransitions(this, a2: this->states.list[v5]);
      idState::Condense(this: this->states.list[v5]);
      ++v4;
      ++v5;
    }
    while ( v4 < this->states.num );
  }
  this->curState = this->GetDoneState(this);
}


// ========================================================================
// ?FindState@idFiniteStateMachine@@QBAPAVidState@@PBD@Z
// EA  : 0x82AB2B80
// RVA : 0x00AB2B80
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

idState *__fastcall idFiniteStateMachine::FindState(idFiniteStateMachine *this, const char *name)
{
  int v4; // r29
  int i; // r31
  const char *Classname; // r3

  v4 = 0;
  if ( this->states.num <= 0 )
    return nullptr;
  for ( i = 0; ; ++i )
  {
    Classname = idClass::GetClassname(this: this->states.list[i]);
    if ( idStr::Icmp(s1: Classname, s2: name) == 0 )
      break;
    if ( ++v4 >= this->states.num )
      return nullptr;
  }
  return this->states.list[v4];
}


// ========================================================================
// ?FindState@idFiniteStateMachine@@QBAPAVidState@@ABVidTypeInfo@@@Z
// EA  : 0x82AB2BF8
// RVA : 0x00AB2BF8
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

idState *__fastcall idFiniteStateMachine::FindState(idFiniteStateMachine *this, const idTypeInfo *stateType)
{
  int v4; // r29
  int i; // r31

  v4 = 0;
  if ( this->states.num <= 0 )
    return nullptr;
  for ( i = 0; this->states.list[i]->GetType(this: this->states.list[i]) != stateType; ++i )
  {
    if ( ++v4 >= this->states.num )
      return nullptr;
  }
  return this->states.list[v4];
}


// ========================================================================
// ?InternalRespondsTo@idFiniteStateMachine@@MBA_NABVidEventDef@@@Z
// EA  : 0x82AB2C78
// RVA : 0x00AB2C78
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

int __fastcall idFiniteStateMachine::InternalRespondsTo(idFiniteStateMachine *this, const idEventDef *event)
{
  idState *curState; // r11
  int result; // r3
  int FullPath; // r3
  bool v7; // zf

  if ( event->type != EVENT_FSMEVENT )
    return 0;
  curState = this->curState;
  if ( curState == nullptr )
    return 0;
  if ( ((unsigned __int8 (*)(void))curState->RespondsTo)() != 0 )
    return 1;
  FullPath = idFile_SaveGamePipelined::GetFullPath(this: (XGRAPHICS::IRInst *)this->curState);
  if ( FullPath == 0 )
    return 0;
  v7 = (*(unsigned __int8 (__fastcall **)(int, const idEventDef *))(*(_DWORD *)FullPath + 12))(a1: FullPath, a2: event) != 0;
  result = 1;
  if ( !v7 )
    return 0;
  return result;
}


// ========================================================================
// ?IsChildFSMActive@idFiniteStateMachine@@QBA_NABVidTypeInfo@@@Z
// EA  : 0x82AB2D28
// RVA : 0x00AB2D28
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

int __fastcall idFiniteStateMachine::IsChildFSMActive(idFiniteStateMachine *this, const idTypeInfo *type)
{
  idClass *FullPath; // r3
  idFiniteStateMachine *v4; // r31

  if ( this->curState != nullptr )
  {
    do
    {
      FullPath = (idClass *)idFile_SaveGamePipelined::GetFullPath(this: (XGRAPHICS::IRInst *)this->curState);
      v4 = (idFiniteStateMachine *)FullPath;
      if ( FullPath == nullptr )
        break;
      if ( (unsigned __int8)idClass::IsType(this: FullPath, superclass: type) != 0 )
        return 1;
      this = v4;
    }
    while ( v4->curState != nullptr );
  }
  return 0;
}


// ========================================================================
// ?SetState@idFiniteStateMachine@@UAAXABUtransResult_t@idStateData@@H_N@Z
// EA  : 0x82AB2DB0
// RVA : 0x00AB2DB0
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

void __fastcall idFiniteStateMachine::SetState(
        idFiniteStateMachine *this,
        const idStateData::transResult_t *result,
        int curTime,
        const bool forcingStack)
{
  idState *v8; // r3
  idState *curState; // r3
  idState *State; // r29

  this->lastTransitionTime = curTime;
  this->lastTransType = result->transitionType;
  this->lastTransitionCode = result->transCode;
  if ( result->transitionType != nullptr && result->nextStateType == this->curState->GetType(this: this->curState) )
  {
    idState::ReenterState(this: this->curState, fsm: this, transCode: result->transCode, curTime);
    this->prevState = this->curState;
    this->nextUpdateTime = curTime + 1;
  }
  else
  {
    v8 = this->GetErrorState(this);
    if ( result->nextStateType != (const idTypeInfo *)v8->GetType(this: v8) )
    {
      this->errorState = nullptr;
      this->errorStateTransType = nullptr;
      this->errorTransCode = 0;
    }
    curState = this->curState;
    if ( curState != nullptr )
    {
      idState::ExitState(this: curState, fsm: this, curTime);
      this->prevState = this->curState;
    }
    this->stateFrame = 0;
    State = idFiniteStateMachine::FindState(this, stateType: result->nextStateType);
    if ( State == nullptr )
      idLib::Error(fmt: "Unable to find FSM state '%s' for FSM '%s'", result->nextStateType->classname, this->name.str);
    idState::EnterState(this: State, fsm: this, curTime);
    if ( !forcingStack && idInventoryItem::GetCount(this: (XGRAPHICS::IRInst *)State) != 0 )
      idState::StartChildFSM(this: State, parentFSM: this, transCode: result->transCode, curTime);
    this->curState = State;
    this->nextUpdateTime = curTime + 1;
  }
}


// ========================================================================
// ?SetCurrentState@idFiniteStateMachine@@QAAXPAVidState@@PBVidTypeInfo@@HH@Z
// EA  : 0x82AB2F28
// RVA : 0x00AB2F28
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

void __fastcall idFiniteStateMachine::SetCurrentState(
        idFiniteStateMachine *this,
        idState *newState,
        const idTypeInfo *fromTransType,
        int transCode,
        int curTime)
{
  idState_vtbl *v5; // r10
  const idTypeInfo *v10; // [sp+50h] [-40h] BYREF
  int v11; // [sp+54h] [-3Ch]
  int v12; // [sp+58h] [-38h]

  v5 = newState->__vftable;
  v10 = nullptr;
  v11 = 0;
  v12 = 0;
  v11 = (int)v5->GetType(this: newState);
  v10 = fromTransType;
  v12 = transCode;
  this->SetState(this, a2: (const idStateData::transResult_t *)&v10, a3: curTime, a4: false);
}


// ========================================================================
// ?TransitionState@idFiniteStateMachine@@AAAXABUtransResult_t@idStateData@@H@Z
// EA  : 0x82AB2FA0
// RVA : 0x00AB2FA0
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

void __fastcall idFiniteStateMachine::TransitionState(
        idFiniteStateMachine *this,
        const idStateData::transResult_t *result,
        int curTime)
{
  int transCode; // r27
  const idTypeInfo *transitionType; // r26
  const idTypeInfo *nextStateType; // r25
  idFSMCallback_vtbl *v9; // r29
  idTypeInfo *v10; // r3
  idState *v11; // r3

  if ( this->callback != nullptr )
  {
    transCode = result->transCode;
    transitionType = result->transitionType;
    nextStateType = result->nextStateType;
    v9 = this->callback->__vftable;
    v10 = this->curState->GetType(this: this->curState);
    v9->OnTransition(this: this->callback, a2: this, a3: v10, a4: nextStateType, a5: transitionType, a6: transCode);
  }
  v11 = this->GetErrorState(this);
  if ( result->nextStateType == (const idTypeInfo *)v11->GetType(this: v11) )
    idFiniteStateMachine::SetError(this, transType: result->transitionType, transCode: result->transCode);
  this->SetNextState(this, a2: result, a3: curTime);
}


// ========================================================================
// ?InternalCallEvent@idFiniteStateMachine@@MAA?AVidEventArg@@ABVidEventDef@@PBV2@@Z
// EA  : 0x82AB3140
// RVA : 0x00AB3140
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

idFiniteStateMachine *__fastcall idFiniteStateMachine::InternalCallEvent(
        idFiniteStateMachine *this,
        idFiniteStateMachine *result,
        const idEventDef *event,
        const idEventArg *args)
{
  eventType_t type; // r5
  const char *EnumName; // r3
  XGRAPHICS::IRInst *curState; // r3
  int FullPath; // r3
  idEventArg *v13; // r28
  int v14; // r28
  idFiniteStateMachine_vtbl **v15; // r11
  idFiniteStateMachine *v16; // r10
  int i; // ctr
  idStateData::transResult_t v18; // [sp+50h] [-60h] BYREF
  char v19; // [sp+5Ch] [-54h] BYREF
  idEventReceiver v20; // [sp+60h] [-50h] BYREF

  type = event->type;
  if ( type != EVENT_FSMEVENT )
  {
    EnumName = idTypeInfoTools::GetEnumName(
                 this: typeInfoTools,
                 enumTypeName: "eventType_t",
                 enumValue: type,
                 defaultValue: "<unknown>");
    idLib::Warning(fmt: "idFiniteStateMachine::InternalCallEvent() doesn't handle %s event type.", EnumName);
LABEL_3:
    this->listenerList = nullptr;
    HIBYTE(this->__vftable) = 0;
    return this;
  }
  curState = (XGRAPHICS::IRInst *)result->curState;
  if ( curState == nullptr )
    goto LABEL_3;
  FullPath = idFile_SaveGamePipelined::GetFullPath(this: curState);
  v13 = (idEventArg *)FullPath;
  if ( FullPath != 0
    && (*(unsigned __int8 (__fastcall **)(int, const idEventDef *))(*(_DWORD *)FullPath + 12))(a1: FullPath, a2: event) != 0 )
  {
    idEventReceiver::ProcessEventArgPtr(this, result: v13, ev: event, args);
    return this;
  }
  else
  {
    if ( !result->curState->RespondsTo(this: result->curState, a2: event) )
      goto LABEL_3;
    idEventReceiver::ProcessEventArgPtr(this: &v20, result: (idEventArg *)result->curState, ev: event, args);
    v18.transitionType = nullptr;
    v18.nextStateType = nullptr;
    result->lastFSMEventTransCode = (int)v20.listenerList;
    v18.transCode = 0;
    v14 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    if ( idState::EvaluateFSMEventTransitions(this: result->curState, fsm: result, curTime: v14, result: &v18) )
      idFiniteStateMachine::TransitionState(this: result, result: &v18, curTime: v14);
    result->lastFSMEventTransCode = 0;
    v15 = (idFiniteStateMachine_vtbl **)&v19;
    v16 = (idFiniteStateMachine *)((char *)this - 4);
    for ( i = 5; i != 0; --i )
    {
      ++v15;
      v16 = (idFiniteStateMachine *)((char *)v16 + 4);
      v16->__vftable = *v15;
    }
    return this;
  }
}


// ========================================================================
// ?SetFSMStack@idFSMManager@@QAA_NABVidFSMStack@1@@Z
// EA  : 0x82AB32D8
// RVA : 0x00AB32D8
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

int __fastcall idFSMManager::SetFSMStack(idFSMManager *this, const idFSMManager::idFSMStack *stack)
{
  idFiniteStateMachine *v4; // r28
  idState *State; // r27
  int v6; // r29
  int i; // r30
  idFiniteStateMachine *v8; // r3
  idFiniteStateMachine *v9; // r31
  const idTypeInfo *v10; // r28
  int GameMs; // r3
  _DWORD v13[28]; // [sp+50h] [-70h] BYREF

  v4 = nullptr;
  State = nullptr;
  v6 = 0;
  if ( stack->fsms.num <= 0 )
    return 1;
  for ( i = 0; ; ++i )
  {
    v8 = this->FindFSM_3(this, a2: stack->fsms.list[i]);
    v9 = v8;
    if ( v8 == nullptr )
      break;
    if ( v4 != nullptr && State != nullptr )
      idState::SetChildFSM(this: State, parentFSM: v4, childFSM_: v8);
    v10 = stack->states.list[i];
    State = idFiniteStateMachine::FindState(this: v9, stateType: v10);
    if ( State == nullptr )
      break;
    v13[1] = v10;
    v13[0] = 0;
    v13[2] = 5;
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    v9->SetState(this: v9, a2: (const idStateData::transResult_t *)v13, a3: GameMs, a4: true);
    ++v6;
    v4 = v9;
    if ( v6 >= stack->fsms.num )
      return 1;
  }
  return 0;
}


// ========================================================================
// ??0idFiniteStateMachine@@QAA@PBD@Z
// EA  : 0x82AB34A8
// RVA : 0x00AB34A8
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

idFiniteStateMachine *__fastcall idFiniteStateMachine::idFiniteStateMachine(
        idFiniteStateMachine *this,
        const char *name)
{
  idEventReceiver::idEventReceiver(this);
  this->manager = nullptr;
  this->__vftable = (idFiniteStateMachine_vtbl *)&idFiniteStateMachine::`vftable';
  this->states.list = nullptr;
  this->states.granularity = 0;
  this->states.memTag = 5;
  this->states.listStatic = 0;
  this->states.size = 0;
  this->states.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->states);
  this->actionCallerState = nullptr;
  idAtomicString::Set(this: &this->name, str_: name);
  this->curState = nullptr;
  this->errorState = nullptr;
  this->errorStateTransType = nullptr;
  this->errorTransCode = 0;
  this->defaultStateType = nullptr;
  this->lastTransitionCode = 0;
  this->lastTransType = nullptr;
  this->prevState = nullptr;
  this->lastWorkTransCode = 0;
  this->lastTransitionTime = -1;
  this->lastUpdateTime = -1;
  this->nextUpdateTime = -1;
  this->stateFrame = 0;
  this->callback = nullptr;
  this->eventId = -1;
  this->eventData = nullptr;
  this->lastFSMEventTransCode = 0;
  return this;
}


// ========================================================================
// __unwind$489362
// EA  : 0x82AB3564
// RVA : 0x00AB3564
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

void _unwind_489362()
{
  int v0; // r12

  idEventReceiver::~idEventReceiver(this: *(idEventReceiver **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$489363
// EA  : 0x82AB358C
// RVA : 0x00AB358C
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

void _unwind_489363()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 16));
}


// ========================================================================
// ??1idFiniteStateMachine@@UAA@XZ
// EA  : 0x82AB35C0
// RVA : 0x00AB35C0
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

void __fastcall idFiniteStateMachine::~idFiniteStateMachine(idFiniteStateMachine *this)
{
  this->__vftable = (idFiniteStateMachine_vtbl *)&idFiniteStateMachine::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->states);
  idEventReceiver::~idEventReceiver(this);
}


// ========================================================================
// __unwind$489398
// EA  : 0x82AB3614
// RVA : 0x00AB3614
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

void _unwind_489398()
{
  int v0; // r12

  idEventReceiver::~idEventReceiver(this: *(idEventReceiver **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetOwner@idFiniteStateMachine@@QBAPAVidEntity@@XZ
// EA  : 0x82AB3640
// RVA : 0x00AB3640
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

idEntity *__fastcall idFiniteStateMachine::GetOwner(idFiniteStateMachine *this)
{
  int value; // r9
  idEntity *v2; // r3

  value = this->manager->owner.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idEntity::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?Save@idFiniteStateMachine@@UBAXAAVidFile_String@@PBD@Z
// EA  : 0x82AB3698
// RVA : 0x00AB3698
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

void __fastcall idFiniteStateMachine::Save(
        idFiniteStateMachine *this,
        idFile_String *file,
        __int64 indent,
        __int64 a4,
        __int64 a5)
{
  const char *v7; // r26
  va *v8; // r3
  __int64 v9; // r10
  __int64 v10; // r6
  __int64 v11; // r8
  va *v12; // r3
  __int64 v13; // r10
  __int64 v14; // r6
  __int64 v15; // r8
  int v16; // r28
  int v17; // r27
  va *v18; // r3
  unsigned int i; // r5
  __int64 v20; // r10
  __int64 v21; // r6
  __int64 v22; // r8
  va *v23; // r3
  unsigned int j; // r5
  int v25; // [sp+8h] [-10A8h]
  int v26; // [sp+8h] [-10A8h]
  int v27; // [sp+8h] [-10A8h]
  int v28; // [sp+8h] [-10A8h]
  int v29; // [sp+Ch] [-10A4h]
  int v30; // [sp+Ch] [-10A4h]
  int v31; // [sp+Ch] [-10A4h]
  int v32; // [sp+Ch] [-10A4h]
  int v33; // [sp+10h] [-10A0h]
  int v34; // [sp+10h] [-10A0h]
  int v35; // [sp+10h] [-10A0h]
  int v36; // [sp+10h] [-10A0h]
  int v37; // [sp+14h] [-109Ch]
  int v38; // [sp+14h] [-109Ch]
  int v39; // [sp+14h] [-109Ch]
  int v40; // [sp+14h] [-109Ch]
  int v41; // [sp+18h] [-1098h]
  int v42; // [sp+18h] [-1098h]
  int v43; // [sp+18h] [-1098h]
  int v44; // [sp+18h] [-1098h]
  int v45; // [sp+1Ch] [-1094h]
  int v46; // [sp+1Ch] [-1094h]
  int v47; // [sp+1Ch] [-1094h]
  int v48; // [sp+1Ch] [-1094h]
  idStr v49; // [sp+50h] [-1060h] BYREF
  va v50; // [sp+70h] [-1040h] BYREF

  LODWORD(indent) = this->name.str;
  v7 = (const char *)HIDWORD(indent);
  v8 = va::va(
         this: &v50,
         fmt: "%sfsm \"%s\" {\n",
         a3: indent,
         a4,
         a5,
         a6: v25,
         a7: v29,
         a8: v33,
         a9: v37,
         a10: v41,
         a11: v45);
  idFile_String::operator+=(this: file, str: v8->buffer);
  LODWORD(v9) = "1 - formation cover, such as behind regime shield units";
  HIDWORD(v10) = v7;
  LODWORD(v10) = this->states.num;
  v12 = va::va(
          this: &v50,
          fmt: "%s\tstates %d {\n",
          a3: v10,
          a4: v11,
          a5: v9,
          a6: v26,
          a7: v30,
          a8: v34,
          a9: v38,
          a10: v42,
          a11: v46);
  idFile_String::operator+=(this: file, str: v12->buffer);
  idStr::idStr(this: &v49, text: v7);
  idStr::Append(this: &v49, text: "\t\t");
  LODWORD(v15) = this->states.num;
  v16 = 0;
  if ( (int)v15 > 0 )
  {
    v17 = 0;
    do
    {
      this->states.list[v17]->Save(this: this->states.list[v17], a2: this, a3: file, a4: v49.data);
      LODWORD(v15) = this->states.num;
      ++v16;
      ++v17;
    }
    while ( v16 < (int)v15 );
  }
  HIDWORD(v14) = v7;
  v18 = va::va(
          this: &v50,
          fmt: "%s\t}\n",
          a3: v14,
          a4: v15,
          a5: v13,
          a6: v27,
          a7: v31,
          a8: v35,
          a9: v39,
          a10: v43,
          a11: v47);
  for ( i = 0; v18->buffer[i] != 0; ++i )
    ;
  file->Write(this: file, a2: v18, a3: i);
  HIDWORD(v20) = byte_821B0000;
  HIDWORD(v21) = v7;
  v23 = va::va(
          this: &v50,
          fmt: "%s}\n",
          a3: v21,
          a4: v22,
          a5: v20,
          a6: v28,
          a7: v32,
          a8: v36,
          a9: v40,
          a10: v44,
          a11: v48);
  for ( j = 0; v23->buffer[j] != 0; ++j )
    ;
  file->Write(this: file, a2: v23, a3: j);
  idStr::FreeData(this: &v49);
}


// ========================================================================
// __unwind$489474
// EA  : 0x82AB380C
// RVA : 0x00AB380C
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

void _unwind_489474()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 4272 + 80));
}


// ========================================================================
// ?AddState@idFiniteStateMachine@@UAAXPAVidState@@@Z
// EA  : 0x82AB3958
// RVA : 0x00AB3958
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

void __fastcall idFiniteStateMachine::AddState(
        idFiniteStateMachine *this,
        idState *state,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        idState *a14)
{
  idState_vtbl *v14; // r11
  const idTypeInfo *v16; // r3

  v14 = state->__vftable;
  a14 = state;
  v16 = v14->GetType(this: state);
  if ( idFiniteStateMachine::FindState(this, stateType: v16) == nullptr )
    idList<idAnimWebBlendTree *,5>::Append(
      this: (idList<enum encounterGroupRole_t,5> *)&this->states,
      obj: (const encounterGroupRole_t *)&a14);
}


// ========================================================================
// ?Add@idFSMStack@idFSMManager@@QAAXPBVidTypeInfo@@0@Z
// EA  : 0x82AB39B8
// RVA : 0x00AB39B8
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

void __fastcall idFSMManager::idFSMStack::Add(
        idFSMManager::idFSMStack *this,
        const idTypeInfo *fsmType,
        const idTypeInfo *stateType,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        const idTypeInfo *a14,
        int a15,
        const idTypeInfo *a16)
{
  a14 = fsmType;
  a16 = stateType;
  idList<idAnimWebBlendTree *,5>::Append(
    (idList<enum encounterGroupRole_t,5> *)this,
    obj: (const encounterGroupRole_t *)&a14);
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->states,
    obj: (const encounterGroupRole_t *)&a16);
}


// ========================================================================
// ?PostEvent@idFiniteStateMachine@@QAA_NHPBVidAIEvent@@H@Z
// EA  : 0x82AB3AD8
// RVA : 0x00AB3AD8
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

BOOL __fastcall idFiniteStateMachine::PostEvent(
        idFiniteStateMachine *this,
        int _eventId,
        const idAIEvent *_eventData,
        int curTime)
{
  unsigned __int64 v8; // r6
  const char *v9; // r7
  XGRAPHICS::IRInst *curState; // r3
  BOOL v11; // r26
  idFiniteStateMachine *FullPath; // r3
  idPLogScope v14; // [sp+50h] [-60h] BYREF
  idStateData::transResult_t v15[7]; // [sp+58h] [-58h] BYREF

  RD_EventBegin(name: "idFiniteStateMachine::PostEvent()");
  LODWORD(v8) = "idFiniteStateMachine::PostEvent()";
  HIDWORD(v8) = 6;
  idPLogScope::idPLogScope(this: &v14, pl: &pLog, gMask: v8, label: v9);
  curState = (XGRAPHICS::IRInst *)this->curState;
  v11 = false;
  if ( curState != nullptr )
  {
    FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: curState);
    if ( FullPath != nullptr )
      v11 = idFiniteStateMachine::PostEvent(this: FullPath, _eventId, _eventData, curTime);
    if ( !v11 )
    {
      this->eventId = _eventId;
      this->eventData = _eventData;
      memset((void *)v15, 0, 12);
      if ( idState::EvaluateEventTransitions(this: this->curState, fsm: this, curTime, result: v15) )
      {
        idFiniteStateMachine::TransitionState(this, result: v15, curTime);
        v11 = true;
      }
    }
  }
  this->eventData = nullptr;
  this->eventId = -1;
  idPLogScope::~idPLogScope(this: &v14);
  RD_EventEnd();
  return v11;
}


// ========================================================================
// __unwind$489678
// EA  : 0x82AB3BD0
// RVA : 0x00AB3BD0
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

void _unwind_489678()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 176 + 100));
}


// ========================================================================
// __unwind$489679
// EA  : 0x82AB3BF8
// RVA : 0x00AB3BF8
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

void _unwind_489679()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 176 + 80));
}


// ========================================================================
// ?Update@idFiniteStateMachine@@QAAXHPAV?$idList@UtransitionInfo_t@idState@@$04@@@Z
// EA  : 0x82AB3C28
// RVA : 0x00AB3C28
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

void __fastcall idFiniteStateMachine::Update(
        idFiniteStateMachine *this,
        int curTime,
        idList<idState::transitionInfo_t,5> *info)
{
  unsigned __int64 v6; // r6
  const char *v7; // r7
  int v8; // r19
  idState *curState; // r3
  int num; // r22
  int v11; // r11
  int size; // r10
  idState::transitionInfo_t *v13; // r29
  char v14; // r26
  bool v15; // r28
  idFiniteStateMachine *FullPath; // r3
  idState *v17; // r23
  idFiniteStateMachine *v18; // r29
  idState *v19; // r27
  unsigned int v20; // r11
  BOOL v21; // r27
  int transCode; // r28
  bool v23; // zf
  int stateFrame; // r11
  idState *v25; // r3
  idState *v26; // r3
  const char *Classname; // r3
  int v28; // r11
  idState::transitionInfo_t *v29; // r29
  const char *v30; // r3
  idPLogScope v31; // [sp+58h] [-98h] BYREF
  idStateData::transResult_t v32[12]; // [sp+60h] [-90h] BYREF

  RD_EventBegin(name: this->name.str);
  LODWORD(v6) = this->name.str;
  HIDWORD(v6) = 6;
  idPLogScope::idPLogScope(this: &v31, pl: &pLog, gMask: v6, label: v7);
  v8 = 0;
  while ( 1 )
  {
    curState = this->curState;
    if ( (curState->stateData->flags & 4) != 0 && idState::IsStateWaiting(this: curState, fsm: this, curTime) )
      break;
    num = -1;
    if ( info != nullptr )
    {
      num = info->num;
      idList<idState::transitionInfo_t,5>::PreAllocateWithGranularity(this: info, newSize: num + 1);
      v11 = info->num;
      size = info->size;
      if ( v11 >= size )
      {
        v13 = &info->list[size - 1];
      }
      else
      {
        v13 = &info->list[v11];
        info->num = v11 + 1;
      }
      v13->fsm = this;
      v13->prevState = this->curState;
      v13->prevChildFSM = (const idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: (XGRAPHICS::IRInst *)this->curState);
      v13->prevTransitionCode = this->lastTransitionCode;
    }
    v14 = 0;
    v15 = curTime >= this->nextUpdateTime;
    FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: (XGRAPHICS::IRInst *)this->curState);
    v17 = this->curState;
    v18 = FullPath;
    if ( FullPath != nullptr )
    {
      if ( FullPath->curState != FullPath->GetErrorState(this: FullPath)
        && v18->curState != v18->GetDoneState(this: v18) )
      {
        idFiniteStateMachine::Update(this: v18, curTime, info);
      }
      v19 = v18->curState;
      if ( v19 == v18->GetErrorState(this: v18) )
      {
        v20 = 2;
      }
      else
      {
        v19 = v18->curState;
        v20 = v18->GetDoneState(this: v18) != v19;
      }
      if ( v20 == 0 )
        goto LABEL_19;
      if ( v20 != 1 )
      {
        if ( v20 >= 3 )
          goto LABEL_20;
LABEL_19:
        v14 = 1;
        this->nextUpdateTime = -1;
        v15 = true;
        goto LABEL_20;
      }
      if ( !idState::IsInterruptible(this: v19) )
        v15 = false;
    }
LABEL_20:
    v21 = v15;
    v23 = !v15;
    transCode = 0;
    if ( !v23 )
    {
      stateFrame = this->stateFrame;
      this->lastWorkTransCode = 0;
      v25 = this->curState;
      this->stateFrame = stateFrame + 1;
      idState::Work(this: v25, fsm: this, curTime);
      memset((void *)v32, 0, 12);
      if ( idState::EvaluateTransitions(this: this->curState, fsm: this, curTime, result: v32) )
        idFiniteStateMachine::TransitionState(this, result: v32, curTime);
      transCode = v32[0].transCode;
      if ( this->lastWorkTransCode != 0 && v32[0].transCode == 0 )
      {
        v26 = this->curState;
        if ( (v26->stateData->flags & 8) != 0 )
        {
          Classname = idClass::GetClassname(this: v26);
          idLib::Warning(
            fmt: "FSM '%s', state '%s' returned a work transcode but no transition exists. REQUIRESWORKTRANS",
            this->name.str,
            Classname);
        }
      }
      this->lastWorkTransCode = 0;
      if ( transCode == 0 || (this->curState->stateData->flags & 2) == 0 )
      {
        v28 = this->GetUpdateInterval(this);
        if ( v28 < 1 )
          v28 = 1;
        this->lastUpdateTime = curTime;
        this->nextUpdateTime = v28 + curTime;
      }
    }
    if ( v14 != 0 )
      idState::SetChildFSM(this: v17, parentFSM: this, childFSM_: nullptr);
    if ( num >= 0 && info != nullptr )
    {
      v29 = &info->list[num];
      v29->curState = this->curState;
      v29->curChildFSM = (const idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: (XGRAPHICS::IRInst *)this->curState);
      v29->transitionCode = transCode;
    }
    if ( !v21 || (++v8, curTime < this->nextUpdateTime) )
    {
      if ( v8 < 5 )
        break;
LABEL_45:
      v30 = idClass::GetClassname(this: this->curState);
      idLib::Warning(
        fmt: "idFiniteStateMachine::Update - Possible infinite loop in FSM '%s', state '%s'",
        this->name.str,
        v30);
      break;
    }
    if ( v8 >= 5 )
      goto LABEL_45;
  }
  idPLogScope::~idPLogScope(this: &v31);
  RD_EventEnd();
}


// ========================================================================
// __unwind$489714
// EA  : 0x82AB4000
// RVA : 0x00AB4000
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

void _unwind_489714()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 240 + 108));
}


// ========================================================================
// __unwind$489715
// EA  : 0x82AB4028
// RVA : 0x00AB4028
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

void _unwind_489715()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 240 + 88));
}


// ========================================================================
// ?Update@idFiniteStateMachine@@QAAX_NHPAV?$idList@UtransitionInfo_t@idState@@$04@@@Z
// EA  : 0x82AB4058
// RVA : 0x00AB4058
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

void __fastcall idFiniteStateMachine::Update(
        idFiniteStateMachine *this,
        bool evaluate,
        int curTime,
        idList<idState::transitionInfo_t,5> *info)
{
  unsigned __int64 v8; // r6
  const char *v9; // r7
  int v10; // r17
  idState *curState; // r3
  int num; // r22
  int v13; // r11
  int size; // r10
  idState::transitionInfo_t *v15; // r29
  bool v16; // r27
  char v17; // r26
  idFiniteStateMachine *FullPath; // r3
  idState *v19; // r24
  idFiniteStateMachine *v20; // r29
  idState *v21; // r28
  unsigned int v22; // r11
  int transCode; // r28
  int stateFrame; // r11
  idState *v25; // r3
  idState *v26; // r3
  const char *Classname; // r3
  int v28; // r11
  idState::transitionInfo_t *v29; // r29
  const char *v30; // r3
  idPLogScope v31; // [sp+58h] [-A8h] BYREF
  idStateData::transResult_t v32[13]; // [sp+60h] [-A0h] BYREF

  RD_EventBegin(name: this->name.str);
  LODWORD(v8) = this->name.str;
  HIDWORD(v8) = 6;
  idPLogScope::idPLogScope(this: &v31, pl: &pLog, gMask: v8, label: v9);
  v10 = 0;
  while ( 1 )
  {
    curState = this->curState;
    if ( (curState->stateData->flags & 4) != 0 && idState::IsStateWaiting(this: curState, fsm: this, curTime) )
      break;
    num = -1;
    if ( info != nullptr )
    {
      num = info->num;
      idList<idState::transitionInfo_t,5>::PreAllocateWithGranularity(this: info, newSize: num + 1);
      v13 = info->num;
      size = info->size;
      if ( v13 >= size )
      {
        v15 = &info->list[size - 1];
      }
      else
      {
        v15 = &info->list[v13];
        info->num = v13 + 1;
      }
      v15->fsm = this;
      v15->prevState = this->curState;
      v15->prevChildFSM = (const idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: (XGRAPHICS::IRInst *)this->curState);
      v15->prevTransitionCode = this->lastTransitionCode;
    }
    v16 = evaluate;
    if ( ai_oldFSMUpdate.valueInteger != 0 )
      v16 = curTime >= this->nextUpdateTime;
    v17 = 0;
    FullPath = (idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: (XGRAPHICS::IRInst *)this->curState);
    v19 = this->curState;
    v20 = FullPath;
    if ( FullPath != nullptr )
    {
      if ( FullPath->curState != FullPath->GetErrorState(this: FullPath)
        && v20->curState != v20->GetDoneState(this: v20)
        && v20->manager == this->manager )
      {
        idFiniteStateMachine::Update(this: v20, evaluate, curTime, info);
      }
      v21 = v20->curState;
      if ( v21 == v20->GetErrorState(this: v20) )
      {
        v22 = 2;
      }
      else
      {
        v21 = v20->curState;
        v22 = v20->GetDoneState(this: v20) != v21;
      }
      if ( v22 == 0 )
        goto LABEL_22;
      if ( v22 != 1 )
      {
        if ( v22 >= 3 )
          goto LABEL_23;
LABEL_22:
        v17 = 1;
        this->nextUpdateTime = -1;
        v16 = true;
        goto LABEL_23;
      }
      if ( !idState::IsInterruptible(this: v21) )
        v16 = false;
    }
LABEL_23:
    transCode = 0;
    if ( v16 )
    {
      stateFrame = this->stateFrame;
      this->lastWorkTransCode = 0;
      v25 = this->curState;
      this->stateFrame = stateFrame + 1;
      idState::Work(this: v25, fsm: this, curTime);
      memset((void *)v32, 0, 12);
      if ( idState::EvaluateTransitions(this: this->curState, fsm: this, curTime, result: v32) )
        idFiniteStateMachine::TransitionState(this, result: v32, curTime);
      transCode = v32[0].transCode;
      if ( this->lastWorkTransCode != 0 && v32[0].transCode == 0 )
      {
        v26 = this->curState;
        if ( (v26->stateData->flags & 8) != 0 )
        {
          Classname = idClass::GetClassname(this: v26);
          idLib::Warning(
            fmt: "FSM '%s', state '%s' returned a work transcode but no transition exists. REQUIRESWORKTRANS",
            this->name.str,
            Classname);
        }
      }
      this->lastWorkTransCode = 0;
      if ( transCode == 0 || (this->curState->stateData->flags & 2) == 0 )
      {
        v28 = this->GetUpdateInterval(this);
        if ( v28 < 1 )
          v28 = 1;
        this->lastUpdateTime = curTime;
        this->nextUpdateTime = v28 + curTime;
      }
    }
    if ( v17 != 0 )
      idState::SetChildFSM(this: v19, parentFSM: this, childFSM_: nullptr);
    if ( num >= 0 && info != nullptr )
    {
      v29 = &info->list[num];
      v29->curState = this->curState;
      v29->curChildFSM = (const idFiniteStateMachine *)idFile_SaveGamePipelined::GetFullPath(this: (XGRAPHICS::IRInst *)this->curState);
      v29->transitionCode = transCode;
    }
    if ( !v16 || (++v10, curTime < this->nextUpdateTime) )
    {
      if ( v10 < 5 )
        break;
LABEL_48:
      v30 = idClass::GetClassname(this: this->curState);
      idLib::Warning(
        fmt: "idFiniteStateMachine::Update - Possible infinite loop in FSM '%s', state '%s'",
        this->name.str,
        v30);
      break;
    }
    if ( v10 >= 5 )
      goto LABEL_48;
  }
  idPLogScope::~idPLogScope(this: &v31);
  RD_EventEnd();
}


// ========================================================================
// __unwind$489874
// EA  : 0x82AB4460
// RVA : 0x00AB4460
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

void _unwind_489874()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 256 + 108));
}


// ========================================================================
// __unwind$489875
// EA  : 0x82AB4488
// RVA : 0x00AB4488
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

void _unwind_489875()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 256 + 88));
}


// ========================================================================
// ?Restart@idFiniteStateMachine@@QAAXH@Z
// EA  : 0x82AB44B0
// RVA : 0x00AB44B0
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

void __fastcall idFiniteStateMachine::Restart(idFiniteStateMachine *this, int curTime)
{
  idFSMCallback *callback; // r11
  idFSMCallback_vtbl *v5; // r29
  idTypeInfo *v6; // r3
  const idTypeInfo *defaultStateType; // r10
  idFiniteStateMachine_vtbl *v8; // r8
  _DWORD v9[12]; // [sp+50h] [-30h] BYREF

  callback = this->callback;
  if ( callback != nullptr )
  {
    v5 = callback->__vftable;
    v6 = this->curState->GetType(this: this->curState);
    v5->OnRestart(this: this->callback, a2: this, a3: v6);
  }
  defaultStateType = this->defaultStateType;
  v8 = this->__vftable;
  this->errorState = nullptr;
  this->errorStateTransType = nullptr;
  this->errorTransCode = 0;
  v9[1] = defaultStateType;
  v9[0] = 0;
  v9[2] = 1;
  v8->SetState(this, a2: (const idStateData::transResult_t *)v9, a3: curTime, a4: false);
  this->nextUpdateTime = curTime;
  idFiniteStateMachine::Update(this, evaluate: true, curTime, info: nullptr);
}


// ========================================================================
// ?Restart@idFiniteStateMachine@@UAAXPAV1@H@Z
// EA  : 0x82AB4568
// RVA : 0x00AB4568
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

void __fastcall idFiniteStateMachine::Restart(idFiniteStateMachine *this, idFiniteStateMachine *parentFSM, int curTime)
{
  idFSMCallback *callback; // r11
  idFSMCallback_vtbl *v6; // r29
  idTypeInfo *v7; // r3
  const idTypeInfo *defaultStateType; // r10
  idFiniteStateMachine_vtbl *v9; // r8
  _DWORD v10[12]; // [sp+50h] [-30h] BYREF

  callback = this->callback;
  if ( callback != nullptr )
  {
    v6 = callback->__vftable;
    v7 = this->curState->GetType(this: this->curState);
    v6->OnRestart(this: this->callback, a2: this, a3: v7);
  }
  defaultStateType = this->defaultStateType;
  v9 = this->__vftable;
  this->errorState = nullptr;
  this->errorStateTransType = nullptr;
  this->errorTransCode = 0;
  v10[1] = defaultStateType;
  v10[0] = 0;
  v10[2] = 2;
  v9->SetState(this, a2: (const idStateData::transResult_t *)v10, a3: curTime, a4: false);
  this->nextUpdateTime = curTime;
  idFiniteStateMachine::Update(this, evaluate: true, curTime, info: nullptr);
}


// ========================================================================
// `dynamic initializer for 'ai_oldFSMUpdate''
// EA  : 0x833694A8
// RVA : 0x013694A8
// PDB : w:\tech5\tungsten\game\ai\fsm\finitestatemachine.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__ai_oldFSMUpdate__()
{
  idCVar::idCVar(
    this: &ai_oldFSMUpdate,
    name: "ai_oldFSMUpdate",
    value: "0",
    flags: 1,
    description: "1 = use old fsm update policy",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__ai_oldFSMUpdate__);
}

