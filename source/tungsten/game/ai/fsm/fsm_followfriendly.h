#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\fsm\fsm_followfriendly.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 16961; PDB kind: class.
class __unaligned __declspec(align(4)) idFollowFriendlyFSM : public idAIFSM
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16962.
  virtual idTypeInfo *GetType();
  virtual ~idFollowFriendlyFSM();
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

  idFollowFriendly_Default stateDefault;
  idFollowFriendly_ReachedTarget stateReachedTarget;
  idFollowFriendly_PathBlocked statePathBlocked;
  idFollowFriendly_MoveToTarget stateMoveToTarget;
  idFollowFriendly_BackAway stateBackAway;
  idFollowFriendly_BackAwayWait stateBackAwayWait;
  idFollowFriendly_BackAwayBlocked stateBackAwayBlocked;
  idFollowFriendly_ChaseProjectile stateChaseProjectile;
};
