#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\fsm\fsm_roam_scenepoints.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 16948; PDB kind: class.
class __unaligned __declspec(align(4)) idRoamScenePoint_StayAt : public idAIState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 34042.
  virtual idTypeInfo *GetType();
  virtual ~idRoamScenePoint_StayAt();
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

// IDA Local Type ordinal 16951; PDB kind: class.
class __unaligned __declspec(align(4)) idRoamScenePointFSM : public idAIFSM
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16952.
  virtual idTypeInfo *GetType();
  virtual ~idRoamScenePointFSM();
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

  idRoamScenePoint_Idle stateRoamSPIdle;
  idRoamScenePoint_Find stateRoamSPFind;
  idRoamScenePoint_MoveTo stateRoamSPMoveTo;
  idRoamScenePoint_StayAt stateRoamSPStayAt;
  idRoamScenePoint_SharedWaitForAnimation stateRoamSPSharedWaitForAnimation;
  idRoamScenePoint_SharedFinished stateRoamSPSharedFinished;
  int stayTime;
  int lookTime;
};
