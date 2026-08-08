
// ========================================================================
// ?InternalWork@idVS_Wait@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B1D6B8
// RVA : 0x00B1D6B8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.cpp
// ========================================================================

void __fastcall idVS_Wait::InternalWork(idVS_Wait *this, idFiniteStateMachine *baseFSM, int curTime)
{
  if ( this->waitTime <= ((int (__fastcall *)(idGameLocal *, int, int))gameLocal->GetGameMs)(
                           a1: gameLocal,
                           a2: 1,
                           a3: curTime) )
    ((void (__fastcall *)(idFiniteStateMachine *, idState *, _DWORD, _DWORD))baseFSM->__vftable[1].GetType)(
      a1: baseFSM,
      a2: this->waitNextState,
      a3: 0,
      a4: 0);
}


// ========================================================================
// ?AppendDefaultTransitions@idVehicleBaseFSM@@UAAXPAVidState@@@Z
// EA  : 0x82B1D738
// RVA : 0x00B1D738
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.cpp
// ========================================================================

void __fastcall idVehicleBaseFSM::AppendDefaultTransitions(idVehicleBaseFSM *this, idState *state)
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


// ========================================================================
// ?SetState@idVehicleBaseFSM@@UAAXABUtransResult_t@idStateData@@H_N@Z
// EA  : 0x82B1D790
// RVA : 0x00B1D790
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.cpp
// ========================================================================

// attributes: thunk
void __fastcall idVehicleBaseFSM::SetState(
        idVehicleBaseFSM *this,
        const idStateData::transResult_t *result,
        int curTime,
        const bool forcingStack)
{
  idFiniteStateMachine::SetState(this, result, curTime, forcingStack);
}


// ========================================================================
// ?SetState@idVehicleBaseFSM@@UAAXABVidTypeInfo@@H_N@Z
// EA  : 0x82B1D798
// RVA : 0x00B1D798
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.cpp
// ========================================================================

void __fastcall idVehicleBaseFSM::SetState(
        idVehicleBaseFSM *this,
        const idTypeInfo *stateType,
        int delayTime,
        BOOL stacked)
{
  idVehicleBaseFSM_vtbl *v4; // r31
  idState *State; // r3

  v4 = this->__vftable;
  State = idFiniteStateMachine::FindState(this, stateType);
  v4->SetState_2(this, a2: State, a3: delayTime, a4: stacked);
}


// ========================================================================
// ?AddState@idVehicleBaseFSM@@UAAXPAVidState@@@Z
// EA  : 0x82B1D7E0
// RVA : 0x00B1D7E0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.cpp
// ========================================================================

void __fastcall idVehicleBaseFSM::AddState(
        idVehicleBaseFSM *this,
        idVehicleState *state,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  idVehicleFSM *v10; // r31
  idVehicleState *v11; // r30
  idVehicleAI *Owner; // r3
  int v13; // [sp+8h] [-68h]
  int v14; // [sp+Ch] [-64h]
  int v15; // [sp+10h] [-60h]
  int v16; // [sp+14h] [-5Ch]
  int v17; // [sp+18h] [-58h]
  idState *v18; // [sp+1Ch] [-54h]

  idFiniteStateMachine::AddState(
    this,
    state,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9: v13,
    a10: v14,
    a11: v15,
    a12: v16,
    a13: v17,
    a14: v18);
  v10 = idVehicleFSM::CastTo(c: (idVehicleFSM *)this);
  v11 = idVehicleState::CastTo(c: state);
  if ( v11 != nullptr && v10 != nullptr )
  {
    Owner = (idVehicleAI *)idFiniteStateMachine::GetOwner(this: v10);
    v11->ai = idVehicleAI::CastTo(c: Owner);
  }
}


// ========================================================================
// ?AllocFSM@idVehicleFSMManager@@UAAPAVidFiniteStateMachine@@ABVidTypeInfo@@ABVidFiniteStateMachineParams@@@Z
// EA  : 0x82B1D850
// RVA : 0x00B1D850
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.cpp
// ========================================================================

idFiniteStateMachine *__fastcall idVehicleFSMManager::AllocFSM(
        idAIActionManager *this,
        const idTypeInfo *type,
        const idFiniteStateMachineParams *params)
{
  return ((idFiniteStateMachine *(__fastcall *)(idAIActionManager *, const idTypeInfo *, const idFiniteStateMachineParams *))this->FindFSM_3)(
           a1: this,
           a2: type,
           a3: params);
}


// ========================================================================
// ?InitStates@idVehicleBaseFSM@@UAAXABVidFiniteStateMachineParams@@@Z
// EA  : 0x82B1D860
// RVA : 0x00B1D860
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.cpp
// ========================================================================

void __fastcall idVehicleBaseFSM::InitStates(idVehicleBaseFSM *this, const idFiniteStateMachineParams *params)
{
  idPhysics_StaticMulti::UpdateTime((bfx::BinaryReplayLogOut *)this);
  this->AddState(this, a2: gameLocal->errorState);
  this->AddState(this, a2: gameLocal->doneState);
  this->AddState(this, a2: &this->s_Idle);
  this->AddState(this, a2: &this->s_Wait);
  idFiniteStateMachine::SetDefaultState(this, state: &this->s_Idle);
}


// ========================================================================
// ?GetErrorState@idVehicleBaseFSM@@UBAPAVidState@@XZ
// EA  : 0x82B1D920
// RVA : 0x00B1D920
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.cpp
// ========================================================================

idAIStateError *__fastcall idVehicleBaseFSM::GetErrorState(idAIFSM *this)
{
  return gameLocal->errorState;
}


// ========================================================================
// ?PopState@idVehicleBaseFSM@@QAAX_N@Z
// EA  : 0x82B1D940
// RVA : 0x00B1D940
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.cpp
// ========================================================================

void __fastcall idVehicleBaseFSM::PopState(idVehicleBaseFSM *this, bool setPoppedState)
{
  int num; // r9
  int v5; // r10
  idVehicleState *v6; // r29
  int v7; // r9
  int v8; // r9
  idVehicleState *State; // r3
  idStr v10[2]; // [sp+60h] [-50h] BYREF

  v10[0].len = 0;
  v10[0].allocedAndFlag = 20;
  v10[0].data = v10[0].baseBuffer;
  v10[0].baseBuffer[0] = 0;
  num = this->stateStack.num;
  if ( num != 0 )
  {
    v5 = this->stateStack.num - 1;
    v6 = this->stateStack.list[num - 1];
    if ( v5 >= 0 )
    {
      v7 = this->stateStack.num;
      if ( v5 < v7 )
      {
        v8 = v7 - 1;
        this->stateStack.num = v8;
        if ( v5 != v8 )
          this->stateStack.list[v5] = this->stateStack.list[v8];
      }
    }
  }
  else
  {
    State = (idVehicleState *)idFiniteStateMachine::FindState(this, stateType: &idVS_Idle::Type);
    v6 = idVehicleState::CastTo(c: State);
  }
  if ( setPoppedState )
    this->SetState_2(this, a2: v6, a3: 0, a4: true);
  v6->stacked = false;
  idStr::FreeData(this: v10);
}


// ========================================================================
// __unwind$488277
// EA  : 0x82B1DA34
// RVA : 0x00B1DA34
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.cpp
// ========================================================================

void _unwind_488277()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 176 + 96));
}


// ========================================================================
// ?FindFSM@idVehicleFSMManager@@UBAPBVidFiniteStateMachine@@PBD@Z
// EA  : 0x82B1DA60
// RVA : 0x00B1DA60
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.cpp
// ========================================================================

idAIFSM *__fastcall idVehicleFSMManager::FindFSM(idAIFSMManager *this, const char *name)
{
  int v4; // r29
  int i; // r31

  v4 = 0;
  if ( this->fsms.num <= 0 )
    return nullptr;
  for ( i = 0; idStr::Icmp(s1: this->fsms.list[i]->name.str, s2: name) != 0; ++i )
  {
    if ( ++v4 >= this->fsms.num )
      return nullptr;
  }
  return this->fsms.list[v4];
}


// ========================================================================
// ?FindFSM@idAIFSMManager@@UBAPBVidFiniteStateMachine@@ABVidTypeInfo@@@Z
// EA  : 0x82B1DAD8
// RVA : 0x00B1DAD8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.cpp
// ========================================================================

idAIFSM *__fastcall idAIFSMManager::FindFSM(idAIFSMManager *this, const idTypeInfo *type)
{
  int v4; // r29
  int i; // r31
  int v6; // r11
  char v7; // r11
  bool v8; // zf

  v4 = 0;
  if ( this->fsms.num <= 0 )
    return nullptr;
  for ( i = 0; ; ++i )
  {
    v6 = *(_DWORD *)((int)this->fsms.list[i]->GetType(this: this->fsms.list[i]) + 36);
    if ( v6 < type->typeNum || (v8 = v6 <= type->lastChild, v7 = 1, !v8) )
      v7 = 0;
    if ( v7 != 0 )
      break;
    if ( ++v4 >= this->fsms.num )
      return nullptr;
  }
  return this->fsms.list[v4];
}


// ========================================================================
// ?SetState@idVehicleBaseFSM@@UAAXPAVidState@@H_N@Z
// EA  : 0x82B1DB80
// RVA : 0x00B1DB80
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.cpp
// ========================================================================

void __fastcall idVehicleBaseFSM::SetState(idVehicleBaseFSM *this, idState *state, int delayTime, bool stacked)
{
  idState *v5; // r30
  const idTypeInfo *v8; // r3
  int v9; // r29
  idState *v10; // r3
  const char *Classname; // r3
  int v12; // r3
  int v13; // r3

  v5 = state;
  if ( state != nullptr && state != this->curState )
  {
    v8 = (const idTypeInfo *)state->GetType(this: state);
    if ( idFiniteStateMachine::FindState(this, stateType: v8) != nullptr )
    {
      if ( !stacked )
        idList<idThread *,58>::Clear(this: &this->stateStack);
      if ( delayTime != 0 )
      {
        v12 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
        this->s_Wait.waitNextState = v5;
        this->s_Wait.waitTime = v12 + delayTime;
        v5 = idFiniteStateMachine::FindState(this, stateType: &idVS_Wait::Type);
      }
      else
      {
        this->s_Wait.waitTime = 0;
      }
      v13 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      idFiniteStateMachine::SetCurrentState(this, newState: v5, fromTransType: nullptr, transCode: 0, curTime: v13);
    }
    else
    {
      v9 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      v10 = idFiniteStateMachine::FindState(this, stateType: &idVS_Idle::Type);
      idFiniteStateMachine::SetCurrentState(this, newState: v10, fromTransType: nullptr, transCode: 0, curTime: v9);
      Classname = idClass::GetClassname(this: v5);
      idLib::Warning(fmt: "VehicleFSM can't find state %s", Classname);
    }
  }
}


// ========================================================================
// ??0idVehicleFSMManager@@QAA@XZ
// EA  : 0x82B1DCE8
// RVA : 0x00B1DCE8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.cpp
// ========================================================================

idVehicleFSMManager *__fastcall idVehicleFSMManager::idVehicleFSMManager(idVehicleFSMManager *this)
{
  idEventReceiver::idEventReceiver(this);
  this->owner.spawnId.value = 0x1FFF;
  this->__vftable = (idVehicleFSMManager_vtbl *)&idVehicleFSMManager::`vftable';
  this->fsms.list = nullptr;
  this->fsms.granularity = 0;
  this->fsms.memTag = 5;
  this->fsms.listStatic = 0;
  this->fsms.size = 0;
  this->fsms.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->fsms);
  return this;
}


// ========================================================================
// __unwind$488896
// EA  : 0x82B1DD6C
// RVA : 0x00B1DD6C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.cpp
// ========================================================================

void _unwind_488896()
{
  int v0; // r12

  idFSMManager::~idFSMManager(this: *(idFSMManager **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idVehicleFSMManager@@UAA@XZ
// EA  : 0x82B1DDA0
// RVA : 0x00B1DDA0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.cpp
// ========================================================================

void __fastcall idVehicleFSMManager::~idVehicleFSMManager(idVehicleFSMManager *this)
{
  this->__vftable = (idVehicleFSMManager_vtbl *)&idVehicleFSMManager::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->fsms);
  this->__vftable = (idVehicleFSMManager_vtbl *)&idFSMManager::`vftable';
  idEventReceiver::~idEventReceiver(this);
}


// ========================================================================
// __unwind$488950_0
// EA  : 0x82B1DE00
// RVA : 0x00B1DE00
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.cpp
// ========================================================================

void _unwind_488950_0()
{
  int v0; // r12

  idFSMManager::~idFSMManager(this: *(idFSMManager **)(v0 - 112 + 132));
}


// ========================================================================
// ??1idVehicleFSM@@UAA@XZ
// EA  : 0x82B1DE28
// RVA : 0x00B1DE28
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.cpp
// ========================================================================

void __fastcall idVehicleFSM::~idVehicleFSM(idVehicleFSM *this)
{
  this->__vftable = (idVehicleFSM_vtbl *)&idVehicleFSM::`vftable';
  idVehicleBaseFSM::~idVehicleBaseFSM(this);
}


// ========================================================================
// ?Init@idVehicleFSMManager@@QAAXPAVidEntity@@@Z
// EA  : 0x82B1DE98
// RVA : 0x00B1DE98
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.cpp
// ========================================================================

void __fastcall idVehicleFSMManager::Init(idVehicleFSMManager *this, idEntity *owner)
{
  if ( owner != nullptr )
    this->owner.spawnId.value = (gameLocal->spawnIds.ptr[owner->entityNumber] << 13) | owner->entityNumber;
  else
    this->owner.spawnId.value = 0x1FFF;
}


// ========================================================================
// ?PushState@idVehicleBaseFSM@@QAAXABVidTypeInfo@@H@Z
// EA  : 0x82B1E028
// RVA : 0x00B1E028
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.cpp
// ========================================================================

void __fastcall idVehicleBaseFSM::PushState(idVehicleBaseFSM *this, const idTypeInfo *stateType, int delayTime)
{
  idVehicleState *v6; // r30
  idVehicleState *v7; // [sp+50h] [-30h] BYREF

  v6 = idVehicleState::CastTo(c: (idVehicleState *)this->curState);
  v7 = v6;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->stateStack,
    obj: (const encounterGroupRole_t *)&v7);
  v6->stacked = true;
  this->SetState_3(this, a2: stateType, a3: delayTime, a4: true);
}


// ========================================================================
// ??0idVehicleFSM@@QAA@XZ
// EA  : 0x82B1E090
// RVA : 0x00B1E090
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.cpp
// ========================================================================

idVehicleFSM *__fastcall idVehicleFSM::idVehicleFSM(idVehicleFSM *this)
{
  idVehicleBaseFSM::idVehicleBaseFSM(this, name: "FSM_Vehicle");
  this->__vftable = (idVehicleFSM_vtbl *)&idVehicleFSM::`vftable';
  return this;
}


// ========================================================================
// ?AddFSM@idVehicleFSMManager@@QAAXPAVidVehicleFSM@@PBD@Z
// EA  : 0x82B1E140
// RVA : 0x00B1E140
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.cpp
// ========================================================================

void __fastcall idVehicleFSMManager::AddFSM(
        idVehicleFSMManager *this,
        idVehicleFSM *fsm,
        const char *name,
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
        idVehicleFSM *a14)
{
  idFiniteStateMachineParams v16; // [sp+50h] [-30h] BYREF

  a14 = fsm;
  v16.manager = this;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->fsms,
    obj: (const encounterGroupRole_t *)&a14);
  idFiniteStateMachine::Init(this: fsm, params: &v16);
  if ( name != nullptr )
    idAtomicString::Set(this: &fsm->name, str_: name);
}

