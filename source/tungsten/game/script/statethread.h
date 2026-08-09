#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\script\statethread.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 17640; PDB kind: class.
class idStateThread : public idThread
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17641.
  virtual idTypeInfo *GetType();
  virtual ~idStateThread();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);

  idEntityPtr<idEntity> entity;
  const function_t *state;
  const function_t *idealState;
};
