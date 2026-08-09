#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\aievents\aieventsound.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 21476; PDB kind: class.
class idAIEventSound : public idAIEventSphere
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21477.
  virtual idTypeInfo *GetType();
  virtual ~idAIEventSound();
  virtual void Clear();
  virtual idAIEvent::aiEventUpdateResult_t InternalUpdate(const int);
  virtual idAIEvent::aiEventUpdateResult_t InternalUpdateAttached(const int);
  virtual bool InternalIsTouching(const idEntity *, const int);
  virtual void InternalDrawDebug(const int, const int, const int);
  virtual float InternalGetIntensity(const idEntity *);
  virtual const idColor *GetColor();

};
