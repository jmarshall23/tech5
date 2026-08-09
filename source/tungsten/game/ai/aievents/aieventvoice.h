#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\aievents\aieventvoice.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 21478; PDB kind: class.
class idAIEventVoice : public idAIEventSound
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21479.
  virtual idTypeInfo *GetType();
  virtual ~idAIEventVoice();
  virtual void Clear();
  virtual idAIEvent::aiEventUpdateResult_t InternalUpdate(const int);
  virtual idAIEvent::aiEventUpdateResult_t InternalUpdateAttached(const int);
  virtual bool InternalIsTouching(const idEntity *, const int);
  virtual void InternalDrawDebug(const int, const int, const int);
  virtual float InternalGetIntensity(const idEntity *);
  virtual const idColor *GetColor();

};

// IDA Local Type ordinal 21486; PDB kind: class.
class idAIEvent_Vehicle : public idAIEventWedge
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21487.
  virtual idTypeInfo *GetType();
  virtual ~idAIEvent_Vehicle();
  virtual void Clear();
  virtual idAIEvent::aiEventUpdateResult_t InternalUpdate(const int);
  virtual idAIEvent::aiEventUpdateResult_t InternalUpdateAttached(const int);
  virtual bool InternalIsTouching(const idEntity *, const int);
  virtual void InternalDrawDebug(const int, const int, const int);
  virtual float InternalGetIntensity(const idEntity *);

};
