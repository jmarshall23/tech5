#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\aievents\aieventwedge.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2367; PDB kind: unknown.
enum idAIEventWedge::<unnamed_tag> : __int32
{
  WEDGEPLANE_TOP = 0x0,
  WEDGEPLANE_BOTTOM = 0x1,
  WEDGEPLANE_LEFT = 0x2,
  WEDGEPLANE_RIGHT = 0x3,
  WEDGEPLANE_MAX = 0x4,
};

// IDA Local Type ordinal 21472; PDB kind: class.
class idAIEventWedge : public idAIEvent
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21473.
  virtual idTypeInfo *GetType();
  virtual ~idAIEventWedge();
  virtual void Clear();
  virtual idAIEvent::aiEventUpdateResult_t InternalUpdate(const int);
  virtual idAIEvent::aiEventUpdateResult_t InternalUpdateAttached(const int);
  virtual bool InternalIsTouching(const idEntity *, const int);
  virtual void InternalDrawDebug(const int, const int, const int);
  virtual float InternalGetIntensity(const idEntity *);

  idVec3 dir;
  float radius;
  int lastRefresh;
  idMat3 axis;
  idArray<idPlane,4> planes;
};
