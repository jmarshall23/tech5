#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\fsm\aifsm.h
// Recovered logical types: 6
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2338; PDB kind: unknown.
enum idAIFSMLite::InternalUpdate::__l2::<unnamed_tag> : __int32
{
  MaxStateChanges = 0x4,
};

// IDA Local Type ordinal 16755; PDB kind: class.
class idAIFSM : public idFiniteStateMachine
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16756.
  virtual idTypeInfo *GetType();
  virtual ~idAIFSM();
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

};

// IDA Local Type ordinal 16837; PDB kind: class.
class __unaligned __declspec(align(4)) idAvoidFSM : public idAIFSM
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16838.
  virtual idTypeInfo *GetType();
  virtual ~idAvoidFSM();
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

  idAvoid_Default stateDefault;
  idAvoid_Dive stateDive;
  idAvoid_RunAway stateRunAway;
  idAvoid_MoveToCover stateMoveToCover;
  idAvoid_WaitInCover stateWaitInCover;
  idAvoid_MoveToGrenade stateMoveToGrenade;
  idAvoid_KickGrenade stateKickGrenade;
  idAvoid_Cower stateCower;
};

// IDA Local Type ordinal 17142; PDB kind: class.
class __declspec(align(4)) idAIFSMLite : public idEventReceiver
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17145.
  virtual idTypeInfo *GetType();
  virtual ~idAIFSMLite();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual void PrintDebugInfo(idGuiListBox *);
  virtual int GetNumStates();
  virtual idAIStateLite *GetState(const int);
  virtual int GetDefaultStateId();
  virtual void InternalInit();
  virtual void InternalUpdate();

  idAI2 *ai;
  idAIStateLite *defaultState;
  idAIStateLite *currentState;
  int stateStartTime;
  bool currentlyUpdating;
};

// IDA Local Type ordinal 20459; PDB kind: class.
class idAIFSM::idAIFSMParams : public idFiniteStateMachineParams
{
public:
};

// IDA Local Type ordinal 21403; PDB kind: struct.
struct idAIFSMLite::InternalUpdate::__l2::changeHistory_t
{
  idAIStateLite *state;
  int workCode;
};
