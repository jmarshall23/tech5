#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\cover\dynamiccover.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14721; PDB kind: class.
class idDynamicCover : public idClass
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14726.
  virtual idTypeInfo *GetType();
  virtual ~idDynamicCover();
  virtual void UpdateUsable(const idEntity *, const idAAS2 *, const int);
  virtual void InternalUpdateCurrent(const idEntity *, const idAAS2 *, const int);
  virtual void InternalUpdateUsable(const idEntity *, const idAAS2 *, const int);
  virtual int InternalAppendUsableCover(const idEntity *, const idAAS2 *, idList<idAICover,5> *);
  virtual void MarkAllUnusable();
  virtual void MarkAllUsable();

  int numCover;
  bool updated;
  idList<idDynamicCover::coverInfo_t,5> coverInfo;
};

// IDA Local Type ordinal 14724; PDB kind: struct.
struct idDynamicCover::coverInfo_t
{
  aas2Cover_t cover;
  idClipQuery contentsQuery;
  idClipQuery translationQuery;
};

// IDA Local Type ordinal 21379; PDB kind: struct.
struct idDynamicCover::GetPropNameForAAS::__l2::aasProperties_t
{
  const char *propName;
  idBounds bounds;
};
