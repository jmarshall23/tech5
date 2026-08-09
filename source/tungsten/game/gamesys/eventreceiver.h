#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\gamesys\eventreceiver.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14183; PDB kind: class.
class idEventReceiver : public idClass
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14185.
  virtual idTypeInfo *GetType();
  virtual ~idEventReceiver();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);

  idList<idEventReceiver *,5> *listenerList;
  idList<idEventReceiver *,5> *listeningToList;
};
