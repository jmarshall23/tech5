#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\cover\formationcover.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 17255; PDB kind: class.
class idFormationCoverMgr : public idDynamicCoverMgr
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17256.
  virtual idTypeInfo *GetType();
  virtual ~idFormationCoverMgr();
  virtual int NumCoverPoints(const idAAS2 *);
  virtual aas2Cover_t *GetCoverPoint(const idAAS2 *, const int);
  virtual const aas2Cover_t *GetCoverPoint_2(const idAAS2 *, const int);
  virtual const idEntity *GetReserver(const idAAS2 *, const int);
  virtual void Reserve(const idAAS2 *, const int, const idEntity *);
  virtual void Unreserve(const idAAS2 *, const int);
  virtual int GetUsableTime(const idAAS2 *, const int);
  virtual void SetUsableTime(const idAAS2 *, const int, const int);
  virtual idDynamicCover *AllocCover(const idAAS2 *);
  virtual void FreeCover(idDynamicCover *);

};

// IDA Local Type ordinal 21376; PDB kind: class.
class idFormationCover : public idDynamicCover
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21377.
  virtual idTypeInfo *GetType();
  virtual ~idFormationCover();
  virtual void UpdateUsable(const idEntity *, const idAAS2 *, const int);
  virtual void InternalUpdateCurrent(const idEntity *, const idAAS2 *, const int);
  virtual void InternalUpdateUsable(const idEntity *, const idAAS2 *, const int);
  virtual int InternalAppendUsableCover(const idEntity *, const idAAS2 *, idList<idAICover,5> *);
  virtual void MarkAllUnusable();
  virtual void MarkAllUsable();

};
