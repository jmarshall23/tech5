#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\aievents\aieventsphere.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 21474; PDB kind: class.
class idAIEventSphere : public idAIEvent
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21475.
  virtual idTypeInfo *GetType();
  virtual ~idAIEventSphere();
  virtual void Clear();
  virtual idAIEvent::aiEventUpdateResult_t InternalUpdate(const int);
  virtual idAIEvent::aiEventUpdateResult_t InternalUpdateAttached(const int);
  virtual bool InternalIsTouching(const idEntity *, const int);
  virtual void InternalDrawDebug(const int, const int, const int);
  virtual float InternalGetIntensity(const idEntity *);
  virtual const idColor *GetColor();

};
