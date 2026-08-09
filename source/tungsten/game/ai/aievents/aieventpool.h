#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\aievents\aieventpool.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2301; PDB kind: enum.
enum animEventBool_t : __int32
{
  B_FALSE = 0x0,
  B_TRUE = 0x1,
};

// IDA Local Type ordinal 16532; PDB kind: class.
class idAIEventPool : public idClass
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16533.
  virtual idTypeInfo *GetType();
  virtual ~idAIEventPool();

  int initialPoolSize;
  const idTypeInfo *eventType;
  idList<idAIEvent *,5> freeEvents;
};

// IDA Local Type ordinal 17639; PDB kind: class.
class eventBool
{
public:
  bool value;
};
