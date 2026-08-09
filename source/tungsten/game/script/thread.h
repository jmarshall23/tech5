#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\script\thread.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1145; PDB kind: enum.
enum idThread::entityTypeFlags_t : __int32
{
  ENTITYTYPE_NONE = 0x0,
  ENTITYTYPE_MISC = 0x1,
  ENTITYTYPE_LIVINGAI = 0x2,
  ENTITYTYPE_DEADAI = 0x4,
  ENTITYTYPE_TURRET = 0x8,
};

// IDA Local Type ordinal 15104; PDB kind: class.
class idThread : public idEventReceiver
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15109.
  virtual idTypeInfo *GetType();
  virtual ~idThread();
  virtual idEventArg *CallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool RespondsTo(const idEventDef *);
  virtual idEventArg *InternalCallEvent(idEventArg *result, const idEventDef *, const idEventArg *);
  virtual bool InternalRespondsTo(const idEventDef *);

  idThread *waitingForThread;
  int waitingFor;
  int waitingUntil;
  int waitingForEventId;
  int waitingForFlags;
  bool waitingForFSM;
  idHandle<int,enum invalidThreadHandle_t,0> threadHandle;
  idStr threadName;
  int lastExecuteTime;
  int creationTime;
  bool manualControl;
  idInterpreter interpreter;
  idEntityPtr<idEntity> threadEntity;
};
