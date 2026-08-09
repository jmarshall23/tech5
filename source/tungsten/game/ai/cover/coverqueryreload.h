#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\cover\coverqueryreload.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 16900; PDB kind: class.
class __unaligned __declspec(align(4)) idInCover_Reload : public idAIState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 33940.
  virtual idTypeInfo *GetType();
  virtual ~idInCover_Reload();
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

// IDA Local Type ordinal 20714; PDB kind: class.
class idCoverQueryReload : public idCoverQuery
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20715.
  virtual ~idCoverQueryReload();
  virtual void InternalPreScore();
  virtual void InternalSetupTarget(const idCoverQuery::coverTarget_t *);
  virtual float InternalScoreCover(const idCoverQuery::coverCache_t *);

};
