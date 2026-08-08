
// ========================================================================
// ?Reset@idAnimFSMHumanoid@@UAAXXZ
// EA  : 0x82A7ED08
// RVA : 0x00A7ED08
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_humanoid.cpp
// ========================================================================

// attributes: thunk
void __fastcall idAnimFSMHumanoid::Reset(idAnimFSMHumanoid *this)
{
  idAnimFSM::Reset(this);
}


// ========================================================================
// ?PrintDebugInfo@idAnimFSMHumanoid@@UAAXAAVidGuiListBox@@@Z
// EA  : 0x82A7ED10
// RVA : 0x00A7ED10
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_humanoid.cpp
// ========================================================================

// attributes: thunk
void __fastcall idAnimFSMHumanoid::PrintDebugInfo(idAnimFSMHumanoid *this, idGuiListBox *info)
{
  idAnimFSM::PrintDebugInfo(this, info);
}


// ========================================================================
// ?GetState@idAnimFSMHumanoid@@MAAPAVidAIStateLite@@H@Z
// EA  : 0x82A7ED18
// RVA : 0x00A7ED18
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_humanoid.cpp
// ========================================================================

idAnimStateIdleGround *__fastcall idAnimFSMHumanoid::GetState(idAnimFSMHumanoid *this, unsigned int stateIndex)
{
  if ( stateIndex == 0 )
    return &this->stateIdle;
  if ( stateIndex == 1 )
    return (idAnimStateIdleGround *)&this->stateMove;
  if ( stateIndex < 3 )
    return (idAnimStateIdleGround *)&this->stateDead;
  return nullptr;
}


// ========================================================================
// ??1idAnimFSMHumanoid@@UAA@XZ
// EA  : 0x82A7EED0
// RVA : 0x00A7EED0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_humanoid.cpp
// ========================================================================

void __fastcall idAnimFSMHumanoid::~idAnimFSMHumanoid(idAnimFSMHumanoid *this)
{
  this->idAnimFSM_AAS::idAnimFSM::idAnimBaseFSM::idAIFSMLite::idEventReceiver::idClass::__vftable = (idAnimFSMHumanoid_vtbl *)&idAnimFSMHumanoid::`vftable'{for `idAIFSMLite'};
  this->idAnimFSM_AAS::idAnimFSM::idAnimBaseFSM::idAIMoveInterface::__vftable = (idAIMoveInterface_vtbl *)&idAnimFSMHumanoid::`vftable'{for `idAIMoveInterface'};
  this->stateDead.__vftable = (idAnimStateDead_vtbl *)&idAIStateLite::`vftable';
  idEventReceiver::~idEventReceiver(this: &this->stateDead);
  idAnimStateMoveGround::~idAnimStateMoveGround(this: &this->stateMove);
  this->stateIdle.__vftable = (idAnimStateIdleGround_vtbl *)&idAIStateLite::`vftable';
  idEventReceiver::~idEventReceiver(this: &this->stateIdle);
  idAnimFSM_AAS::~idAnimFSM_AAS(this);
}


// ========================================================================
// __unwind$487404
// EA  : 0x82A7EF38
// RVA : 0x00A7EF38
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_humanoid.cpp
// ========================================================================

void _unwind_487404()
{
  int v0; // r12

  idAnimFSM_AAS::~idAnimFSM_AAS(this: *(idAnimFSM_AAS **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$487405
// EA  : 0x82A7EF60
// RVA : 0x00A7EF60
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_humanoid.cpp
// ========================================================================

void _unwind_487405()
{
  int v0; // r12

  idAnimStateDead::~idAnimStateDead(this: (idAIStateLite *)(*(_DWORD *)(v0 - 112 + 132) + 20968));
}


// ========================================================================
// __unwind$487406
// EA  : 0x82A7EF8C
// RVA : 0x00A7EF8C
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_humanoid.cpp
// ========================================================================

void _unwind_487406()
{
  int v0; // r12

  idAnimStateMoveGround::~idAnimStateMoveGround(this: (idAnimStateMoveGround *)(*(_DWORD *)(v0 - 112 + 132) + 20984));
}


// ========================================================================
// ??0idAnimFSMHumanoid@@QAA@XZ
// EA  : 0x82A7EFC0
// RVA : 0x00A7EFC0
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_humanoid.cpp
// ========================================================================

idAnimFSMHumanoid *__fastcall idAnimFSMHumanoid::idAnimFSMHumanoid(idAnimFSMHumanoid *this)
{
  idAnimFSM_AAS::idAnimFSM_AAS(this);
  this->idAnimFSM_AAS::idAnimFSM::idAnimBaseFSM::idAIFSMLite::idEventReceiver::idClass::__vftable = (idAnimFSMHumanoid_vtbl *)&idAnimFSMHumanoid::`vftable'{for `idAIFSMLite'};
  this->idAnimFSM_AAS::idAnimFSM::idAnimBaseFSM::idAIMoveInterface::__vftable = (idAIMoveInterface_vtbl *)&idAnimFSMHumanoid::`vftable'{for `idAIMoveInterface'};
  idAnimStateIdleGround::idAnimStateIdleGround(this: &this->stateIdle);
  idAnimStateMoveGround::idAnimStateMoveGround(this: &this->stateMove);
  idAnimStateDead::idAnimStateDead(this: &this->stateDead);
  idAnimFSM::Reset(this);
  return this;
}


// ========================================================================
// __unwind$487501
// EA  : 0x82A7F038
// RVA : 0x00A7F038
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_humanoid.cpp
// ========================================================================

void _unwind_487501()
{
  int v0; // r12

  idAnimFSM_AAS::~idAnimFSM_AAS(this: *(idAnimFSM_AAS **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$487502
// EA  : 0x82A7F060
// RVA : 0x00A7F060
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_humanoid.cpp
// ========================================================================

void _unwind_487502()
{
  int v0; // r12

  idAnimStateDead::~idAnimStateDead(this: (idAIStateLite *)(*(_DWORD *)(v0 - 112 + 132) + 20968));
}


// ========================================================================
// __unwind$487503
// EA  : 0x82A7F08C
// RVA : 0x00A7F08C
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_humanoid.cpp
// ========================================================================

void _unwind_487503()
{
  int v0; // r12

  idAnimStateMoveGround::~idAnimStateMoveGround(this: (idAnimStateMoveGround *)(*(_DWORD *)(v0 - 112 + 132) + 20984));
}


// ========================================================================
// __unwind$487504
// EA  : 0x82A7F0B8
// RVA : 0x00A7F0B8
// PDB : w:\tech5\tungsten\game\ai\animfsm\animfsm_humanoid.cpp
// ========================================================================

void _unwind_487504()
{
  int v0; // r12

  idAnimStateDead::~idAnimStateDead(this: (idAIStateLite *)(*(_DWORD *)(v0 - 112 + 132) + 21168));
}

