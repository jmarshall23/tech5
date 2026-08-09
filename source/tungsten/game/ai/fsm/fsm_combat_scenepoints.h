#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\fsm\fsm_combat_scenepoints.h
// Recovered logical types: 9
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 16922; PDB kind: class.
class __unaligned __declspec(align(4)) idCombatScenePoint_Find : public idAIState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 33882.
  virtual idTypeInfo *GetType();
  virtual ~idCombatScenePoint_Find();
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

// IDA Local Type ordinal 16923; PDB kind: class.
class __unaligned __declspec(align(4)) idCombatScenePoint_MoveTo : public idAIState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 33885.
  virtual idTypeInfo *GetType();
  virtual ~idCombatScenePoint_MoveTo();
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

// IDA Local Type ordinal 16924; PDB kind: class.
class __unaligned __declspec(align(4)) idCombatScenePoint_StayAt : public idAIState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 33889.
  virtual idTypeInfo *GetType();
  virtual ~idCombatScenePoint_StayAt();
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

// IDA Local Type ordinal 16929; PDB kind: class.
class __unaligned __declspec(align(4)) idCombatScenePoint_Close : public idAIState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 33879.
  virtual idTypeInfo *GetType();
  virtual ~idCombatScenePoint_Close();
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

// IDA Local Type ordinal 16930; PDB kind: class.
class __unaligned __declspec(align(4)) idCombatScenePoint_Idle : public idAIState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 33883.
  virtual idTypeInfo *GetType();
  virtual ~idCombatScenePoint_Idle();
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

// IDA Local Type ordinal 16932; PDB kind: class.
class __unaligned __declspec(align(4)) idCombatScenePoint_Reload : public idAIState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 33886.
  virtual idTypeInfo *GetType();
  virtual ~idCombatScenePoint_Reload();
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

// IDA Local Type ordinal 16933; PDB kind: class.
class __unaligned __declspec(align(4)) idCombatScenePoint_Melee : public idAIState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 33884.
  virtual idTypeInfo *GetType();
  virtual ~idCombatScenePoint_Melee();
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

// IDA Local Type ordinal 16934; PDB kind: class.
class __unaligned __declspec(align(4)) idCombatScenePoint_Dodge : public idAIState
{
public:
  // Recovered virtual interface; IDA vtable ordinal 33880.
  virtual idTypeInfo *GetType();
  virtual ~idCombatScenePoint_Dodge();
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

// IDA Local Type ordinal 16937; PDB kind: class.
class __declspec(align(4)) idCombatScenePointFSM : public idAIFSM
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16938.
  virtual idTypeInfo *GetType();
  virtual ~idCombatScenePointFSM();
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

  __unaligned __declspec(align(1)) idCombatScenePoint_Find stateCombatSPFind;
  idCombatScenePoint_MoveTo stateCombatSPMoveTo;
  __unaligned __declspec(align(1)) idCombatScenePoint_StayAt stateCombatSPStayAt;
  idCombatScenePoint_EnterScenePoint stateCombatSPEnter;
  __unaligned __declspec(align(1)) idCombatScenePoint_TacticalAttack stateCombatSPTacticalAttack;
  __unaligned __declspec(align(1)) idCombatScenePoint_TacticalCover stateCombatSPTacticalCover;
  __unaligned __declspec(align(1)) idCombatScenePoint_UseTurret stateCombatSPUseTurret;
  idCombatScenePoint_Close stateCombatSPClose;
  __unaligned __declspec(align(1)) idCombatScenePoint_Idle stateCombatSPIdle;
  idCombatScenePoint_ApplyRestriction stateCombatSPApplyRestriction;
  __unaligned __declspec(align(1)) idCombatScenePoint_Reload stateCombatSPReload;
  idCombatScenePoint_Melee stateCombatSPMelee;
  __unaligned __declspec(align(1)) idCombatScenePoint_Dodge stateCombatSPDodge;
  idCombatScenePoint_SharedWaitForAnimation stateCombatSPSharedWaitForAnimation;
  __unaligned __declspec(align(1)) idCombatScenePoint_SharedFinished stateCombatSPSharedFinished;
  int stayTime;
  bool enterValid;
};
