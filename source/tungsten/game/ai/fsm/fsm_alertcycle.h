#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\fsm\fsm_alertcycle.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1026; PDB kind: enum.
enum alertCycle_t : __int32
{
  ALERTCYCLE_RELAXED = 0x1,
  ALERTCYCLE_SEARCH = 0x2,
  ALERTCYCLE_COMBAT = 0x3,
  ALERTCYCLE_PAIN = 0x4,
  ALERTCYCLE_DYING = 0x5,
  ALERTCYCLE_DEAD = 0x6,
  ALERTCYCLE_ANIMATE = 0x7,
  ALERTCYCLE_AVOID = 0x8,
  ALERTCYCLE_CONTROLLED = 0x9,
  ALERTCYCLE_ERROR = 0xA,
  ALERTCYCLE_MAX = 0xB,
};

// IDA Local Type ordinal 16771; PDB kind: class.
class __unaligned __declspec(align(4)) idAlertCycle_Pain : public idAIState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 33851.
  virtual idTypeInfo *GetType();
  virtual ~idAlertCycle_Pain();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual void Save(const idFiniteStateMachine *, idFile_String *, const char *);
  virtual void InternalInitState(const idFiniteStateMachine *);
  virtual bool InternalCanUse(idFiniteStateMachine *, const int);
  virtual void InternalEnterState(idFiniteStateMachine *, const int);
  virtual void InternalExitState(idFiniteStateMachine *, const int);
  virtual void InternalWork(idFiniteStateMachine *, const int);
  virtual void InternalReenterState(idFiniteStateMachine *, const int, const int);
  virtual bool InternalIsStateWaiting(idFiniteStateMachine *, const int);
  virtual void InternalGetDebugString(idStr *);
  virtual bool AIState_CanUse(idAI2 *, idAIFSM *, const int);
  virtual void AIState_EnterState(idAI2 *, idAIFSM *, const int);
  virtual void AIState_ExitState(idAI2 *, idAIFSM *, const int);
  virtual void AIState_Work(idAI2 *, idAIFSM *, const int);
  virtual void AIState_ReenterState(idAI2 *, idAIFSM *, const int, const int);
  virtual bool AIState_IsWaiting(idAI2 *, idAIFSM *, const int);

};

// IDA Local Type ordinal 16780; PDB kind: class.
class idAlertCycleFSM : public idAIFSM
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16781.
  virtual idTypeInfo *GetType();
  virtual ~idAlertCycleFSM();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual bool CanUse(idFiniteStateMachine *, const int);
  virtual idState *GetErrorState();
  virtual idState *GetDoneState();
  virtual void Save(idFile_String *, const char *);
  virtual void Restart(idFiniteStateMachine *, const int);
  virtual void AddState(idState *);
  virtual int GetUpdateInterval();
  virtual void InitStates(const idFiniteStateMachineParams *);
  virtual void AppendDefaultTransitions(idState *);
  virtual void SetNextState(const idStateData::transResult_t *, const int);
  virtual void SetState(const idStateData::transResult_t *, const int, const bool);

  __unaligned __declspec(align(1)) idAlertCycle_Default stateDefault;
  idAlertCycle_ExecuteDoomscript stateExecuteDoomscript;
  __unaligned __declspec(align(1)) idAlertCycle_ExecuteCodeMoveAction stateExecuteCodeMoveAction;
  idAlertCycle_ActionScript stateActionScript;
  __unaligned __declspec(align(1)) idAlertCycle_DropFromShip stateDropFromShip;
  idAlertCycle_PerformDropLanding statePerformDropLanding;
  __unaligned __declspec(align(1)) idAlertCycle_Relaxed stateRelaxed;
  idAlertCycle_Combat stateCombat;
  __unaligned __declspec(align(1)) idAlertCycle_CombatScenePoint stateCombatSP;
  idAlertCycle_SearchScenePoint stateSearchSP;
  __unaligned __declspec(align(1)) idAlertCycle_RoamScenePoint stateRoamSP;
  idAlertCycle_Search stateSearch;
  __unaligned __declspec(align(1)) idAlertCycle_Pain statePain;
  idAlertCycle_Dying stateDying;
  __unaligned __declspec(align(1)) idAlertCycle_Dead stateDead;
  idAlertCycle_Avoid stateAvoid;
  __unaligned __declspec(align(1)) idAlertCycle_Melee stateMelee;
  idAlertCycle_WatchPossessedGuy stateWatchPossession;
  __unaligned __declspec(align(1)) idAlertCycle_UnhandledError stateUnhandledError;
  idAlertCycle_Passified statePassified;
  __unaligned __declspec(align(1)) idAlertCycle_OnElevator stateOnElevator;
};
