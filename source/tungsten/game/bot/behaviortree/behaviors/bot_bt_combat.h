#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\bot\behaviortree\behaviors\bot_bt_combat.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 20378; PDB kind: class.
class idBotBehaviorCombat : public idBehaviorSelectorLooping
{
public:
  // Recovered virtual interface; IDA vtable ordinal 20379.
  virtual idTypeInfo *GetType();
  virtual ~idBotBehaviorCombat();
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
