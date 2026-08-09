#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\fsm\aistate.h
// Recovered logical types: 7
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2316; PDB kind: unknown.
enum idAIStateLite::<unnamed_tag> : __int32
{
  SF_PHYSICS_CONTROL = 0x1,
  SF_IGNORE_DELTA_CORRECTION = 0x2,
  SF_DELTA_MOVE_ONLY = 0x4,
  SF_CLIPDELTA_TO_VOLUMES = 0x8,
  SF_FLYING = 0x10,
};

// IDA Local Type ordinal 16684; PDB kind: class.
class idVOChainState
{
public:
  voChainState_t state;
  idList<enum voChainState_t,5> responses;
};

// IDA Local Type ordinal 16703; PDB kind: struct.
struct aiPState_t
{
  __int16 atRest;
  bool onGround;
  char pad;
  idVec3 localOrigin;
  idVec3 worldOrigin;
  idVec3 velocity;
  idVec3 pushVelocity;
};

// IDA Local Type ordinal 16758; PDB kind: class.
class idAIState : public idState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17262.
  virtual idTypeInfo *GetType();
  virtual ~idAIState();
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

// IDA Local Type ordinal 17143; PDB kind: class.
class idAIStateLite : public idEventReceiver
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17144.
  virtual idTypeInfo *GetType();
  virtual ~idAIStateLite();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual int GetStateFlags();
  virtual void PrintDebugInfo(idGuiListBox *);
  virtual void InternalEnter(idAI2 *, idAIFSMLite *);
  virtual void InternalReEnter(idAI2 *, idAIFSMLite *);
  virtual void InternalExit(idAI2 *, idAIFSMLite *);
  virtual int InternalWork(idAI2 *, idAIFSMLite *);

  int subState;
};

// IDA Local Type ordinal 17264; PDB kind: class.
class idAIStateError : public idAIAction
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17265.
  virtual idTypeInfo *GetType();
  virtual ~idAIStateError();
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
  virtual const idEventDef *GetActionEventDef();
  virtual int GetActionFlags();
  virtual void AIAction_EnterState(idAI2 *, idAIFSM *, const int);
  virtual void AIAction_ExitState(idAI2 *, idAIFSM *, const int);
  virtual void AIAction_Work(idAI2 *, idAIFSM *, const int);
  virtual void AIAction_ReenterState(idAI2 *, idAIFSM *, const int);
  virtual bool AIAction_IsWaiting(idAI2 *, idAIFSM *, const int);

};

// IDA Local Type ordinal 17266; PDB kind: class.
class idAIStateDone : public idAIAction
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17267.
  virtual idTypeInfo *GetType();
  virtual ~idAIStateDone();
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
  virtual const idEventDef *GetActionEventDef();
  virtual int GetActionFlags();
  virtual void AIAction_EnterState(idAI2 *, idAIFSM *, const int);
  virtual void AIAction_ExitState(idAI2 *, idAIFSM *, const int);
  virtual void AIAction_Work(idAI2 *, idAIFSM *, const int);
  virtual void AIAction_ReenterState(idAI2 *, idAIFSM *, const int);
  virtual bool AIAction_IsWaiting(idAI2 *, idAIFSM *, const int);

};
