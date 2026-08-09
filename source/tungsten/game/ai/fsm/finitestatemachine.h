#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\fsm\finitestatemachine.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2114; PDB kind: enum.
enum idFiniteStateMachine::fsmStatus_t : __int32
{
  FSMSTATUS_DONE = 0x0,
  FSMSTATUS_WORKING = 0x1,
  FSMSTATUS_ERROR = 0x2,
};

// IDA Local Type ordinal 15750; PDB kind: class.
class idFiniteStateMachine : public idEventReceiver
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15768.
  virtual idTypeInfo *GetType();
  virtual ~idFiniteStateMachine();
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

  idFSMManager *manager;
  idList<idState *,5> states;
  idState *actionCallerState;
  idAtomicString name;
  idState *curState;
  const idState *errorState;
  const idTypeInfo *errorStateTransType;
  int errorTransCode;
  const idTypeInfo *defaultStateType;
  int lastTransitionCode;
  const idTypeInfo *lastTransType;
  const idState *prevState;
  int lastWorkTransCode;
  int lastTransitionTime;
  int lastUpdateTime;
  int nextUpdateTime;
  int stateFrame;
  idFSMCallback *callback;
  int eventId;
  const idAIEvent *eventData;
  int lastFSMEventTransCode;
};

// IDA Local Type ordinal 15763; PDB kind: class.
class idFiniteStateMachineParams
{
public:
  idFSMManager *manager;
};
