#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\fsm\aifsmmanager.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15762; PDB kind: class.
class idFSMManager : public idEventReceiver
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15769.
  virtual idTypeInfo *GetType();
  virtual ~idFSMManager();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual idFiniteStateMachine *AllocFSM(const idTypeInfo *, const idFiniteStateMachineParams *);
  virtual const idFiniteStateMachine *FindFSM(const idTypeInfo *);
  virtual const idFiniteStateMachine *FindFSM_2(const char *);
  virtual idFiniteStateMachine *FindFSM_3(const idTypeInfo *);
  virtual idFiniteStateMachine *FindFSM_4(const char *);
  virtual void FreeFSM(const idTypeInfo *);
  virtual void FreeFSM_2(const char *);

  idEntityPtr<idEntity> owner;
};

// IDA Local Type ordinal 16754; PDB kind: class.
class __unaligned __declspec(align(4)) idAIFSMManager : public idFSMManager
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16997.
  virtual idTypeInfo *GetType();
  virtual ~idAIFSMManager();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual idFiniteStateMachine *AllocFSM(const idTypeInfo *, const idFiniteStateMachineParams *);
  virtual const idFiniteStateMachine *FindFSM(const idTypeInfo *);
  virtual const idFiniteStateMachine *FindFSM_2(const char *);
  virtual idFiniteStateMachine *FindFSM_3(const idTypeInfo *);
  virtual idFiniteStateMachine *FindFSM_4(const char *);
  virtual void FreeFSM(const idTypeInfo *);
  virtual void FreeFSM_2(const char *);
  virtual const idFiniteStateMachine *GetControllingFSM();
  virtual idFiniteStateMachine *GetControllingFSM_2();

  idList<idAIFSM *,92> fsms;
  idAlertCycleFSM alertCycle;
  idRelaxedFSM relaxed;
  idCombatFSM combat;
  idSearchFSM search;
  idAvoidFSM avoid;
  idTakeCoverFSM takeCover;
  idOpenCombatFSM openCombat;
  idMeleeFSM melee;
  idAdvanceFSM advance;
  idInCoverFSM inCover;
  idBackStandFSM backStand;
  idCombatScenePointFSM combatScenePointFSM;
  idSearchScenePointFSM searchScenePointFSM;
  idRoamScenePointFSM roamScenePointFSM;
  idFollowFriendlyFSM followFriendly;
  idPlayerInteractFSM playerInteract;
  idIdleTrackFriendlyFSM idleTrackFriendly;
};

// IDA Local Type ordinal 21278; PDB kind: class.
class idFSMManager::idFSMStack
{
public:
  idList<idTypeInfo const *,5> fsms;
  idList<idTypeInfo const *,5> states;
};
