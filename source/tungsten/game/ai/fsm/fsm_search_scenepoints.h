#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\fsm\fsm_search_scenepoints.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 16939; PDB kind: class.
class __unaligned __declspec(align(4)) idSearchScenePoint_Find : public idAIState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 34043.
  virtual idTypeInfo *GetType();
  virtual ~idSearchScenePoint_Find();
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

// IDA Local Type ordinal 16940; PDB kind: class.
class __unaligned __declspec(align(4)) idSearchScenePoint_MoveTo : public idAIState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 34045.
  virtual idTypeInfo *GetType();
  virtual ~idSearchScenePoint_MoveTo();
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

// IDA Local Type ordinal 16941; PDB kind: class.
class __unaligned __declspec(align(4)) idSearchScenePoint_StayAt : public idAIState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 34046.
  virtual idTypeInfo *GetType();
  virtual ~idSearchScenePoint_StayAt();
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

// IDA Local Type ordinal 16943; PDB kind: class.
class __unaligned __declspec(align(4)) idSearchScenePointFSM : public idAIFSM
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16944.
  virtual idTypeInfo *GetType();
  virtual ~idSearchScenePointFSM();
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

  idSearchScenePoint_Find stateSearchSPFind;
  idSearchScenePoint_MoveTo stateSearchSPMoveTo;
  idSearchScenePoint_StayAt stateSearchSPStayAt;
  idSearchScenePoint_MoveToPos stateSearchSPMoveToPos;
  int stayTime;
  int lookTime;
};
