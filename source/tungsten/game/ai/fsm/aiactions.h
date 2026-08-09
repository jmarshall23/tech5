#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\fsm\aiactions.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 17106; PDB kind: class.
class idAIActionsQueue : public idEventReceiver
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17107.
  virtual idTypeInfo *GetType();
  virtual ~idAIActionsQueue();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);

  idList<idEventDef const *,92> actionEvents;
  idList<idEventArgs,92> actionArgs;
};

// IDA Local Type ordinal 22360; PDB kind: class.
class idAIActionStatement
{
public:
  const idEventDef *eventDef;
  idEventArgs args;
};
