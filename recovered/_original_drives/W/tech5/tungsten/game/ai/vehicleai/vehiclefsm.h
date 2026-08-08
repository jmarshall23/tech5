
// ========================================================================
// ??0idVehicleState@@QAA@ABVidTypeInfo@@@Z
// EA  : 0x824E3790
// RVA : 0x004E3790
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.h
// ========================================================================

idVehicleState *__fastcall idVehicleState::idVehicleState(idVehicleState *this, const idTypeInfo *stateType)
{
  idState::idState(this, stateType, childFSMType: nullptr, flags: 0);
  this->__vftable = (idVehicleState_vtbl *)&idVehicleState::`vftable';
  this->stacked = false;
  this->debugName.data = this->debugName.baseBuffer;
  this->debugName.len = 0;
  this->debugName.allocedAndFlag = 20;
  this->debugName.baseBuffer[0] = 0;
  this->debugInfo.allocedAndFlag = 20;
  this->debugInfo.data = this->debugInfo.baseBuffer;
  this->debugInfo.len = 0;
  this->debugInfo.baseBuffer[0] = 0;
  this->ai = nullptr;
  return this;
}


// ========================================================================
// ??0idVehicleBaseFSM@@QAA@XZ
// EA  : 0x824FD240
// RVA : 0x004FD240
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.h
// ========================================================================

idVehicleBaseFSM *__fastcall idVehicleBaseFSM::idVehicleBaseFSM(idVehicleBaseFSM *this)
{
  idFiniteStateMachine::idFiniteStateMachine(this, name: &byte_8200D768);
  this->__vftable = (idVehicleBaseFSM_vtbl *)&idVehicleBaseFSM::`vftable';
  this->stateStack.granularity = 1;
  this->stateStack.num = 0;
  this->stateStack.size = 4;
  this->stateStack.list = this->stateStack.staticList;
  this->stateStack.memTag = 5;
  this->stateStack.listStatic = 1;
  idVehicleState::idVehicleState(this: &this->s_Idle, stateType: &idVS_Idle::Type);
  this->s_Idle.__vftable = (idVS_Idle_vtbl *)&idVS_Idle::`vftable';
  idVehicleState::idVehicleState(this: &this->s_Wait, stateType: &idVS_Wait::Type);
  this->s_Wait.waitTime = 0;
  this->s_Wait.waitNextState = nullptr;
  this->s_Wait.__vftable = (idVS_Wait_vtbl *)&idVS_Wait::`vftable';
  this->dataState = nullptr;
  memset(Dst: this->stateStack.list, Val: 0, Size: 4 * this->stateStack.size);
  return this;
}


// ========================================================================
// __unwind$587040
// EA  : 0x824FD30C
// RVA : 0x004FD30C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.h
// ========================================================================

void _unwind_587040()
{
  int v0; // r12

  idFiniteStateMachine::~idFiniteStateMachine(this: *(idFiniteStateMachine **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$587041
// EA  : 0x824FD334
// RVA : 0x004FD334
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.h
// ========================================================================

void _unwind_587041()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 108));
}


// ========================================================================
// __unwind$587042
// EA  : 0x824FD360
// RVA : 0x004FD360
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.h
// ========================================================================

void _unwind_587042()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 128 + 148) + 144));
}


// ========================================================================
// ?GetDebugName@idVehicleState@@QBA?BVidStr@@XZ
// EA  : 0x82B0B090
// RVA : 0x00B0B090
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.h
// ========================================================================

idVehicleState *__fastcall idVehicleState::GetDebugName(idVehicleState *this, const idStr *result)
{
  idStr::idStr((idStr *)this, text: result + 1);
  return this;
}


// ========================================================================
// ?GetDebugInfo@idVehicleState@@QBA?BVidStr@@XZ
// EA  : 0x82B0B0C8
// RVA : 0x00B0B0C8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.h
// ========================================================================

idVehicleState *__fastcall idVehicleState::GetDebugInfo(idVehicleState *this, const idStr *result)
{
  idStr::idStr((idStr *)this, text: result + 2);
  return this;
}


// ========================================================================
// ??0idVehicleBaseFSM@@QAA@PBD@Z
// EA  : 0x82B1DEE0
// RVA : 0x00B1DEE0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.h
// ========================================================================

idVehicleBaseFSM *__fastcall idVehicleBaseFSM::idVehicleBaseFSM(idVehicleBaseFSM *this, const char *name)
{
  idFiniteStateMachine::idFiniteStateMachine(this, name);
  this->__vftable = (idVehicleBaseFSM_vtbl *)&idVehicleBaseFSM::`vftable';
  this->stateStack.granularity = 1;
  this->stateStack.num = 0;
  this->stateStack.size = 4;
  this->stateStack.list = this->stateStack.staticList;
  this->stateStack.memTag = 5;
  this->stateStack.listStatic = 1;
  idVehicleState::idVehicleState(this: &this->s_Idle, stateType: &idVS_Idle::Type);
  this->s_Idle.__vftable = (idVS_Idle_vtbl *)&idVS_Idle::`vftable';
  idVehicleState::idVehicleState(this: &this->s_Wait, stateType: &idVS_Wait::Type);
  this->s_Wait.waitTime = 0;
  this->s_Wait.waitNextState = nullptr;
  this->s_Wait.__vftable = (idVS_Wait_vtbl *)&idVS_Wait::`vftable';
  this->dataState = nullptr;
  memset(Dst: this->stateStack.list, Val: 0, Size: 4 * this->stateStack.size);
  return this;
}


// ========================================================================
// __unwind$489238
// EA  : 0x82B1DFA4
// RVA : 0x00B1DFA4
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.h
// ========================================================================

void _unwind_489238()
{
  int v0; // r12

  idFiniteStateMachine::~idFiniteStateMachine(this: *(idFiniteStateMachine **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$489239
// EA  : 0x82B1DFCC
// RVA : 0x00B1DFCC
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.h
// ========================================================================

void _unwind_489239()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 128 + 148) + 108));
}


// ========================================================================
// __unwind$489240
// EA  : 0x82B1DFF8
// RVA : 0x00B1DFF8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclefsm.h
// ========================================================================

void _unwind_489240()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 128 + 148) + 144));
}

