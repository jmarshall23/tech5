
// ========================================================================
// ??0idAIFSMManager@@QAA@XZ
// EA  : 0x82AB1820
// RVA : 0x00AB1820
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

idAIFSMManager *__fastcall idAIFSMManager::idAIFSMManager(idAIFSMManager *this)
{
  idEventReceiver::idEventReceiver(this);
  this->owner.spawnId.value = 0x1FFF;
  this->__vftable = (idAIFSMManager_vtbl *)&idAIFSMManager::`vftable';
  this->fsms.list = nullptr;
  this->fsms.granularity = 0;
  this->fsms.memTag = 92;
  this->fsms.listStatic = 0;
  this->fsms.size = 0;
  this->fsms.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->fsms);
  idAlertCycleFSM::idAlertCycleFSM(this: &this->alertCycle);
  idRelaxedFSM::idRelaxedFSM(this: &this->relaxed);
  idCombatFSM::idCombatFSM(this: &this->combat);
  idSearchFSM::idSearchFSM(this: &this->search);
  idAvoidFSM::idAvoidFSM(this: &this->avoid);
  idTakeCoverFSM::idTakeCoverFSM(this: &this->takeCover);
  idOpenCombatFSM::idOpenCombatFSM(this: &this->openCombat);
  idMeleeFSM::idMeleeFSM(this: &this->melee);
  idAdvanceFSM::idAdvanceFSM(this: &this->advance);
  idInCoverFSM::idInCoverFSM(this: &this->inCover);
  idBackStandFSM::idBackStandFSM(this: &this->backStand);
  idCombatScenePointFSM::idCombatScenePointFSM(this: &this->combatScenePointFSM);
  idSearchScenePointFSM::idSearchScenePointFSM(this: &this->searchScenePointFSM);
  idRoamScenePointFSM::idRoamScenePointFSM(this: &this->roamScenePointFSM);
  idFollowFriendlyFSM::idFollowFriendlyFSM(this: &this->followFriendly);
  idPlayerInteractFSM::idPlayerInteractFSM(this: &this->playerInteract);
  idIdleTrackFriendlyFSM::idIdleTrackFriendlyFSM(this: &this->idleTrackFriendly);
  return this;
}


// ========================================================================
// __unwind$488294
// EA  : 0x82AB192C
// RVA : 0x00AB192C
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488294()
{
  int v0; // r12

  idFSMManager::~idFSMManager(this: *(idFSMManager **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$488295
// EA  : 0x82AB1954
// RVA : 0x00AB1954
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488295()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 16));
}


// ========================================================================
// __unwind$488296
// EA  : 0x82AB1980
// RVA : 0x00AB1980
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488296()
{
  int v0; // r12

  idAlertCycleFSM::~idAlertCycleFSM(this: (idAlertCycleFSM *)(*(_DWORD *)(v0 - 112 + 132) + 32));
}


// ========================================================================
// __unwind$488297
// EA  : 0x82AB19AC
// RVA : 0x00AB19AC
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488297()
{
  int v0; // r12

  idRelaxedFSM::~idRelaxedFSM(this: (idRelaxedFSM *)(*(_DWORD *)(v0 - 112 + 132) + 728));
}


// ========================================================================
// __unwind$488298
// EA  : 0x82AB19D8
// RVA : 0x00AB19D8
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488298()
{
  int v0; // r12

  idCombatFSM::~idCombatFSM(this: (idCombatFSM *)(*(_DWORD *)(v0 - 112 + 132) + 1184));
}


// ========================================================================
// __unwind$488299
// EA  : 0x82AB1A04
// RVA : 0x00AB1A04
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488299()
{
  int v0; // r12

  idSearchFSM::~idSearchFSM(this: (idSearchFSM *)(*(_DWORD *)(v0 - 112 + 132) + 1916));
}


// ========================================================================
// __unwind$488300
// EA  : 0x82AB1A30
// RVA : 0x00AB1A30
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488300()
{
  int v0; // r12

  idAvoidFSM::~idAvoidFSM(this: (idAvoidFSM *)(*(_DWORD *)(v0 - 112 + 132) + 2220));
}


// ========================================================================
// __unwind$488301
// EA  : 0x82AB1A5C
// RVA : 0x00AB1A5C
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488301()
{
  int v0; // r12

  idTakeCoverFSM::~idTakeCoverFSM(this: (idTakeCoverFSM *)(*(_DWORD *)(v0 - 112 + 132) + 2552));
}


// ========================================================================
// __unwind$488302
// EA  : 0x82AB1A88
// RVA : 0x00AB1A88
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488302()
{
  int v0; // r12

  idOpenCombatFSM::~idOpenCombatFSM(this: (idOpenCombatFSM *)(*(_DWORD *)(v0 - 112 + 132) + 2828));
}


// ========================================================================
// __unwind$488303
// EA  : 0x82AB1AB4
// RVA : 0x00AB1AB4
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488303()
{
  int v0; // r12

  idMeleeFSM::~idMeleeFSM(this: (idMeleeFSM *)(*(_DWORD *)(v0 - 112 + 132) + 3692));
}


// ========================================================================
// __unwind$488304
// EA  : 0x82AB1AE0
// RVA : 0x00AB1AE0
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488304()
{
  int v0; // r12

  idAdvanceFSM::~idAdvanceFSM(this: (idAdvanceFSM *)(*(_DWORD *)(v0 - 112 + 132) + 3884));
}


// ========================================================================
// __unwind$488305
// EA  : 0x82AB1B0C
// RVA : 0x00AB1B0C
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488305()
{
  int v0; // r12

  idInCoverFSM::~idInCoverFSM(this: (idInCoverFSM *)(*(_DWORD *)(v0 - 112 + 132) + 4356));
}


// ========================================================================
// __unwind$488306
// EA  : 0x82AB1B38
// RVA : 0x00AB1B38
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488306()
{
  int v0; // r12

  idBackStandFSM::~idBackStandFSM(this: (idBackStandFSM *)(*(_DWORD *)(v0 - 112 + 132) + 4884));
}


// ========================================================================
// __unwind$488307
// EA  : 0x82AB1B64
// RVA : 0x00AB1B64
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488307()
{
  int v0; // r12

  idCombatScenePointFSM::~idCombatScenePointFSM(this: (idCombatScenePointFSM *)(*(_DWORD *)(v0 - 112 + 132) + 5188));
}


// ========================================================================
// __unwind$488308
// EA  : 0x82AB1B90
// RVA : 0x00AB1B90
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488308()
{
  int v0; // r12

  idSearchScenePointFSM::~idSearchScenePointFSM(this: (idSearchScenePointFSM *)(*(_DWORD *)(v0 - 112 + 132) + 5732));
}


// ========================================================================
// __unwind$488309
// EA  : 0x82AB1BBC
// RVA : 0x00AB1BBC
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488309()
{
  int v0; // r12

  idRoamScenePointFSM::~idRoamScenePointFSM(this: (idRoamScenePointFSM *)(*(_DWORD *)(v0 - 112 + 132) + 5960));
}


// ========================================================================
// __unwind$488310
// EA  : 0x82AB1BE8
// RVA : 0x00AB1BE8
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488310()
{
  int v0; // r12

  idFollowFriendlyFSM::~idFollowFriendlyFSM(this: (idFollowFriendlyFSM *)(*(_DWORD *)(v0 - 112 + 132) + 6244));
}


// ========================================================================
// __unwind$488311
// EA  : 0x82AB1C14
// RVA : 0x00AB1C14
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488311()
{
  int v0; // r12

  idPlayerInteractFSM::~idPlayerInteractFSM(this: (idPlayerInteractFSM *)(*(_DWORD *)(v0 - 112 + 132) + 6576));
}


// ========================================================================
// ??1idAIFSMManager@@UAA@XZ
// EA  : 0x82AB1C48
// RVA : 0x00AB1C48
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void __fastcall idAIFSMManager::~idAIFSMManager(idAIFSMManager *this)
{
  this->__vftable = (idAIFSMManager_vtbl *)&idAIFSMManager::`vftable';
  idIdleTrackFriendlyFSM::~idIdleTrackFriendlyFSM(this: &this->idleTrackFriendly);
  idPlayerInteractFSM::~idPlayerInteractFSM(this: &this->playerInteract);
  idFollowFriendlyFSM::~idFollowFriendlyFSM(this: &this->followFriendly);
  idRoamScenePointFSM::~idRoamScenePointFSM(this: &this->roamScenePointFSM);
  idSearchScenePointFSM::~idSearchScenePointFSM(this: &this->searchScenePointFSM);
  idCombatScenePointFSM::~idCombatScenePointFSM(this: &this->combatScenePointFSM);
  idBackStandFSM::~idBackStandFSM(this: &this->backStand);
  idInCoverFSM::~idInCoverFSM(this: &this->inCover);
  idAdvanceFSM::~idAdvanceFSM(this: &this->advance);
  idMeleeFSM::~idMeleeFSM(this: &this->melee);
  idOpenCombatFSM::~idOpenCombatFSM(this: &this->openCombat);
  idTakeCoverFSM::~idTakeCoverFSM(this: &this->takeCover);
  idAvoidFSM::~idAvoidFSM(this: &this->avoid);
  idSearchFSM::~idSearchFSM(this: &this->search);
  idCombatFSM::~idCombatFSM(this: &this->combat);
  idRelaxedFSM::~idRelaxedFSM(this: &this->relaxed);
  idAlertCycleFSM::~idAlertCycleFSM(this: &this->alertCycle);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->fsms);
  this->__vftable = (idAIFSMManager_vtbl *)&idFSMManager::`vftable';
  idEventReceiver::~idEventReceiver(this);
}


// ========================================================================
// __unwind$488454
// EA  : 0x82AB1D30
// RVA : 0x00AB1D30
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488454()
{
  int v0; // r12

  idFSMManager::~idFSMManager(this: *(idFSMManager **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$488455
// EA  : 0x82AB1D58
// RVA : 0x00AB1D58
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488455()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 16));
}


// ========================================================================
// __unwind$488456
// EA  : 0x82AB1D84
// RVA : 0x00AB1D84
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488456()
{
  int v0; // r12

  idAlertCycleFSM::~idAlertCycleFSM(this: (idAlertCycleFSM *)(*(_DWORD *)(v0 - 112 + 132) + 32));
}


// ========================================================================
// __unwind$488457
// EA  : 0x82AB1DB0
// RVA : 0x00AB1DB0
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488457()
{
  int v0; // r12

  idRelaxedFSM::~idRelaxedFSM(this: (idRelaxedFSM *)(*(_DWORD *)(v0 - 112 + 132) + 728));
}


// ========================================================================
// __unwind$488458
// EA  : 0x82AB1DDC
// RVA : 0x00AB1DDC
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488458()
{
  int v0; // r12

  idCombatFSM::~idCombatFSM(this: (idCombatFSM *)(*(_DWORD *)(v0 - 112 + 132) + 1184));
}


// ========================================================================
// __unwind$488459
// EA  : 0x82AB1E08
// RVA : 0x00AB1E08
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488459()
{
  int v0; // r12

  idSearchFSM::~idSearchFSM(this: (idSearchFSM *)(*(_DWORD *)(v0 - 112 + 132) + 1916));
}


// ========================================================================
// __unwind$488460
// EA  : 0x82AB1E34
// RVA : 0x00AB1E34
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488460()
{
  int v0; // r12

  idAvoidFSM::~idAvoidFSM(this: (idAvoidFSM *)(*(_DWORD *)(v0 - 112 + 132) + 2220));
}


// ========================================================================
// __unwind$488461
// EA  : 0x82AB1E60
// RVA : 0x00AB1E60
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488461()
{
  int v0; // r12

  idTakeCoverFSM::~idTakeCoverFSM(this: (idTakeCoverFSM *)(*(_DWORD *)(v0 - 112 + 132) + 2552));
}


// ========================================================================
// __unwind$488462
// EA  : 0x82AB1E8C
// RVA : 0x00AB1E8C
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488462()
{
  int v0; // r12

  idOpenCombatFSM::~idOpenCombatFSM(this: (idOpenCombatFSM *)(*(_DWORD *)(v0 - 112 + 132) + 2828));
}


// ========================================================================
// __unwind$488463
// EA  : 0x82AB1EB8
// RVA : 0x00AB1EB8
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488463()
{
  int v0; // r12

  idMeleeFSM::~idMeleeFSM(this: (idMeleeFSM *)(*(_DWORD *)(v0 - 112 + 132) + 3692));
}


// ========================================================================
// __unwind$488464
// EA  : 0x82AB1EE4
// RVA : 0x00AB1EE4
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488464()
{
  int v0; // r12

  idAdvanceFSM::~idAdvanceFSM(this: (idAdvanceFSM *)(*(_DWORD *)(v0 - 112 + 132) + 3884));
}


// ========================================================================
// __unwind$488465
// EA  : 0x82AB1F10
// RVA : 0x00AB1F10
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488465()
{
  int v0; // r12

  idInCoverFSM::~idInCoverFSM(this: (idInCoverFSM *)(*(_DWORD *)(v0 - 112 + 132) + 4356));
}


// ========================================================================
// __unwind$488466
// EA  : 0x82AB1F3C
// RVA : 0x00AB1F3C
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488466()
{
  int v0; // r12

  idBackStandFSM::~idBackStandFSM(this: (idBackStandFSM *)(*(_DWORD *)(v0 - 112 + 132) + 4884));
}


// ========================================================================
// __unwind$488467
// EA  : 0x82AB1F68
// RVA : 0x00AB1F68
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488467()
{
  int v0; // r12

  idCombatScenePointFSM::~idCombatScenePointFSM(this: (idCombatScenePointFSM *)(*(_DWORD *)(v0 - 112 + 132) + 5188));
}


// ========================================================================
// __unwind$488468
// EA  : 0x82AB1F94
// RVA : 0x00AB1F94
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488468()
{
  int v0; // r12

  idSearchScenePointFSM::~idSearchScenePointFSM(this: (idSearchScenePointFSM *)(*(_DWORD *)(v0 - 112 + 132) + 5732));
}


// ========================================================================
// __unwind$488469
// EA  : 0x82AB1FC0
// RVA : 0x00AB1FC0
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488469()
{
  int v0; // r12

  idRoamScenePointFSM::~idRoamScenePointFSM(this: (idRoamScenePointFSM *)(*(_DWORD *)(v0 - 112 + 132) + 5960));
}


// ========================================================================
// __unwind$488470
// EA  : 0x82AB1FEC
// RVA : 0x00AB1FEC
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488470()
{
  int v0; // r12

  idFollowFriendlyFSM::~idFollowFriendlyFSM(this: (idFollowFriendlyFSM *)(*(_DWORD *)(v0 - 112 + 132) + 6244));
}


// ========================================================================
// __unwind$488471
// EA  : 0x82AB2018
// RVA : 0x00AB2018
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void _unwind_488471()
{
  int v0; // r12

  idPlayerInteractFSM::~idPlayerInteractFSM(this: (idPlayerInteractFSM *)(*(_DWORD *)(v0 - 112 + 132) + 6576));
}


// ========================================================================
// ?Init@idAIFSMManager@@QAAXPAVidEntity@@@Z
// EA  : 0x82AB20A8
// RVA : 0x00AB20A8
// PDB : w:\tech5\tungsten\game\ai\fsm\aifsmmanager.cpp
// ========================================================================

void __fastcall idAIFSMManager::Init(idAIFSMManager *this, idEntity *owner)
{
  void *p_alertCycle; // [sp+50h] [-70h] BYREF
  idFiniteStateMachineParams v4; // [sp+54h] [-6Ch] BYREF
  idFiniteStateMachineParams v5; // [sp+58h] [-68h] BYREF
  idFiniteStateMachineParams v6; // [sp+5Ch] [-64h] BYREF
  idFiniteStateMachineParams v7; // [sp+60h] [-60h] BYREF
  idFiniteStateMachineParams v8; // [sp+64h] [-5Ch] BYREF
  idFiniteStateMachineParams v9; // [sp+68h] [-58h] BYREF
  idFiniteStateMachineParams v10; // [sp+6Ch] [-54h] BYREF
  idFiniteStateMachineParams v11; // [sp+70h] [-50h] BYREF
  idFiniteStateMachineParams v12; // [sp+74h] [-4Ch] BYREF
  idFiniteStateMachineParams v13; // [sp+78h] [-48h] BYREF
  idFiniteStateMachineParams v14; // [sp+7Ch] [-44h] BYREF
  idFiniteStateMachineParams v15; // [sp+80h] [-40h] BYREF
  idFiniteStateMachineParams v16; // [sp+84h] [-3Ch] BYREF
  idFiniteStateMachineParams v17; // [sp+88h] [-38h] BYREF
  idFiniteStateMachineParams v18; // [sp+8Ch] [-34h] BYREF
  idFiniteStateMachineParams v19; // [sp+90h] [-30h] BYREF
  idFiniteStateMachineParams v20; // [sp+94h] [-2Ch] BYREF

  if ( owner != nullptr )
    this->owner.spawnId.value = (gameLocal->spawnIds.ptr[owner->entityNumber] << 13) | owner->entityNumber;
  else
    this->owner.spawnId.value = 0x1FFF;
  p_alertCycle = &this->alertCycle;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->fsms,
    obj: (const encounterGroupRole_t *)&p_alertCycle);
  v4.manager = this;
  idFiniteStateMachine::Init(this: &this->alertCycle, params: &v4);
  p_alertCycle = &this->relaxed;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->fsms,
    obj: (const encounterGroupRole_t *)&p_alertCycle);
  v5.manager = this;
  idFiniteStateMachine::Init(this: &this->relaxed, params: &v5);
  p_alertCycle = &this->combat;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->fsms,
    obj: (const encounterGroupRole_t *)&p_alertCycle);
  v6.manager = this;
  idFiniteStateMachine::Init(this: &this->combat, params: &v6);
  p_alertCycle = &this->search;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->fsms,
    obj: (const encounterGroupRole_t *)&p_alertCycle);
  v7.manager = this;
  idFiniteStateMachine::Init(this: &this->search, params: &v7);
  p_alertCycle = &this->avoid;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->fsms,
    obj: (const encounterGroupRole_t *)&p_alertCycle);
  v8.manager = this;
  idFiniteStateMachine::Init(this: &this->avoid, params: &v8);
  p_alertCycle = &this->backStand;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->fsms,
    obj: (const encounterGroupRole_t *)&p_alertCycle);
  v9.manager = this;
  idFiniteStateMachine::Init(this: &this->backStand, params: &v9);
  p_alertCycle = &this->takeCover;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->fsms,
    obj: (const encounterGroupRole_t *)&p_alertCycle);
  v10.manager = this;
  idFiniteStateMachine::Init(this: &this->takeCover, params: &v10);
  p_alertCycle = &this->openCombat;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->fsms,
    obj: (const encounterGroupRole_t *)&p_alertCycle);
  v11.manager = this;
  idFiniteStateMachine::Init(this: &this->openCombat, params: &v11);
  p_alertCycle = &this->melee;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->fsms,
    obj: (const encounterGroupRole_t *)&p_alertCycle);
  v12.manager = this;
  idFiniteStateMachine::Init(this: &this->melee, params: &v12);
  p_alertCycle = &this->advance;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->fsms,
    obj: (const encounterGroupRole_t *)&p_alertCycle);
  v13.manager = this;
  idFiniteStateMachine::Init(this: &this->advance, params: &v13);
  p_alertCycle = &this->inCover;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->fsms,
    obj: (const encounterGroupRole_t *)&p_alertCycle);
  v14.manager = this;
  idFiniteStateMachine::Init(this: &this->inCover, params: &v14);
  p_alertCycle = &this->followFriendly;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->fsms,
    obj: (const encounterGroupRole_t *)&p_alertCycle);
  v15.manager = this;
  idFiniteStateMachine::Init(this: &this->followFriendly, params: &v15);
  p_alertCycle = &this->playerInteract;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->fsms,
    obj: (const encounterGroupRole_t *)&p_alertCycle);
  v16.manager = this;
  idFiniteStateMachine::Init(this: &this->playerInteract, params: &v16);
  p_alertCycle = &this->idleTrackFriendly;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->fsms,
    obj: (const encounterGroupRole_t *)&p_alertCycle);
  v17.manager = this;
  idFiniteStateMachine::Init(this: &this->idleTrackFriendly, params: &v17);
  p_alertCycle = &this->combatScenePointFSM;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->fsms,
    obj: (const encounterGroupRole_t *)&p_alertCycle);
  v18.manager = this;
  idFiniteStateMachine::Init(this: &this->combatScenePointFSM, params: &v18);
  p_alertCycle = &this->searchScenePointFSM;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->fsms,
    obj: (const encounterGroupRole_t *)&p_alertCycle);
  v19.manager = this;
  idFiniteStateMachine::Init(this: &this->searchScenePointFSM, params: &v19);
  p_alertCycle = &this->roamScenePointFSM;
  idList<idAnimWebBlendTree *,5>::Append(
    this: (idList<enum encounterGroupRole_t,5> *)&this->fsms,
    obj: (const encounterGroupRole_t *)&p_alertCycle);
  v20.manager = this;
  idFiniteStateMachine::Init(this: &this->roamScenePointFSM, params: &v20);
}

