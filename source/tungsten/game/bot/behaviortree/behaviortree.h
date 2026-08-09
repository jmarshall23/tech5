#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\bot\behaviortree\behaviortree.h
// Recovered logical types: 5
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14949; PDB kind: class.
class idBehaviorTree : public idBehaviorParallel
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14950.
  virtual idTypeInfo *GetType();
  virtual ~idBehaviorTree();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual void Init(idBot *, const int);
  virtual behaviorPriority_t GetPriority(idBot *, const int);
  virtual void Enter(idBot *, const int);
  virtual void Exit(idBot *, const int);
  virtual behaviorStatus_t Think(idBot *, const int);
  virtual void ProcessEvent(idBot *, const int, const idBehaviorStateEvent *);
  virtual void DebugRenderGui(const idBot *, idGuiListBox *, int);
  virtual void GetDebugString(idStr *);
  virtual idBehaviorState *CheckForDuplicateState(const idBehaviorState **);
  virtual idBehaviorState *FindState(const idTypeInfo *);
  virtual int GetStateIndex(const idBehaviorState *);
  virtual bool IsInterruptable();
  virtual void InternalInit(idBot *, const int);
  virtual void InternalEnter(idBot *, const int);
  virtual void InternalExit(idBot *, const int);
  virtual behaviorStatus_t InternalThink(idBot *, const int);
  virtual void InternalProcessEvent(idBot *, const int, const idBehaviorStateEvent *);
  virtual behaviorPriority_t InternalGetPriority(idBot *, const int);
  virtual int GetStateIndex_2(const idBehaviorState *);

  int numFramesWithNoActiveChildren;
};

// IDA Local Type ordinal 14951; PDB kind: class.
class idBotBehaviorTree : public idBehaviorTree
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14952.
  virtual idTypeInfo *GetType();
  virtual ~idBotBehaviorTree();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual void Init(idBot *, const int);
  virtual behaviorPriority_t GetPriority(idBot *, const int);
  virtual void Enter(idBot *, const int);
  virtual void Exit(idBot *, const int);
  virtual behaviorStatus_t Think(idBot *, const int);
  virtual void ProcessEvent(idBot *, const int, const idBehaviorStateEvent *);
  virtual void DebugRenderGui(const idBot *, idGuiListBox *, int);
  virtual void GetDebugString(idStr *);
  virtual idBehaviorState *CheckForDuplicateState(const idBehaviorState **);
  virtual idBehaviorState *FindState(const idTypeInfo *);
  virtual int GetStateIndex(const idBehaviorState *);
  virtual bool IsInterruptable();
  virtual void InternalInit(idBot *, const int);
  virtual void InternalEnter(idBot *, const int);
  virtual void InternalExit(idBot *, const int);
  virtual behaviorStatus_t InternalThink(idBot *, const int);
  virtual void InternalProcessEvent(idBot *, const int, const idBehaviorStateEvent *);
  virtual behaviorPriority_t InternalGetPriority(idBot *, const int);
  virtual int GetStateIndex_2(const idBehaviorState *);

};

// IDA Local Type ordinal 20359; PDB kind: class.
class idBotBehaviorTreeDebugGui : public idGuiPage
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20360.
  virtual ~idBotBehaviorTreeDebugGui();
  virtual bool IsEnabled();
  virtual void SetIsActive(const bool);
  virtual void Update();
  virtual void SetupChildRowLink(const int, const idStr *);
  virtual void InternalRender(idDeviceContext *, const float, const float);
  virtual void InternalRender_2(idEntity *, idDeviceContext *);
  virtual bool InternalHandleEvent(const sysEvent_t *);

};

// IDA Local Type ordinal 20384; PDB kind: class.
class idBotBehaviorReact : public idBehaviorSelectorLooping
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20385.
  virtual idTypeInfo *GetType();
  virtual ~idBotBehaviorReact();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual void Init(idBot *, const int);
  virtual behaviorPriority_t GetPriority(idBot *, const int);
  virtual void Enter(idBot *, const int);
  virtual void Exit(idBot *, const int);
  virtual behaviorStatus_t Think(idBot *, const int);
  virtual void ProcessEvent(idBot *, const int, const idBehaviorStateEvent *);
  virtual void DebugRenderGui(const idBot *, idGuiListBox *, int);
  virtual void GetDebugString(idStr *);
  virtual idBehaviorState *CheckForDuplicateState(const idBehaviorState **);
  virtual idBehaviorState *FindState(const idTypeInfo *);
  virtual int GetStateIndex(const idBehaviorState *);
  virtual bool IsInterruptable();
  virtual void InternalInit(idBot *, const int);
  virtual void InternalEnter(idBot *, const int);
  virtual void InternalExit(idBot *, const int);
  virtual behaviorStatus_t InternalThink(idBot *, const int);
  virtual void InternalProcessEvent(idBot *, const int, const idBehaviorStateEvent *);
  virtual behaviorPriority_t InternalGetPriority(idBot *, const int);
  virtual int GetStateIndex_2(const idBehaviorState *);

};

// IDA Local Type ordinal 22046; PDB kind: class.
class idBehaviorTemp : public idBehaviorAction
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22047.
  virtual idTypeInfo *GetType();
  virtual ~idBehaviorTemp();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);
  virtual void Init(idBot *, const int);
  virtual behaviorPriority_t GetPriority(idBot *, const int);
  virtual void Enter(idBot *, const int);
  virtual void Exit(idBot *, const int);
  virtual behaviorStatus_t Think(idBot *, const int);
  virtual void ProcessEvent(idBot *, const int, const idBehaviorStateEvent *);
  virtual void DebugRenderGui(const idBot *, idGuiListBox *, int);
  virtual void GetDebugString(idStr *);
  virtual idBehaviorState *CheckForDuplicateState(const idBehaviorState **);
  virtual idBehaviorState *FindState(const idTypeInfo *);
  virtual int GetStateIndex(const idBehaviorState *);
  virtual bool IsInterruptable();
  virtual void InternalInit(idBot *, const int);
  virtual void InternalEnter(idBot *, const int);
  virtual void InternalExit(idBot *, const int);
  virtual behaviorStatus_t InternalThink(idBot *, const int);
  virtual void InternalProcessEvent(idBot *, const int, const idBehaviorStateEvent *);
  virtual behaviorPriority_t InternalGetPriority(idBot *, const int);
  virtual void MoveGoal_Started_CallBack(idBot *, const int);
  virtual void MoveGoal_Reached_CallBack(idBot *, const int);
  virtual void MoveGoal_Errored_CallBack(idBot *, const int, const botMoveStatus_t);
  virtual void MoveSubGoal_Started_CallBack(idBot *, const int);
  virtual void MoveSubGoal_Reached_CallBack(idBot *, const int);
  virtual void MoveSubGoal_Errored_CallBack(idBot *, const int, const botMoveStatus_t);

};
