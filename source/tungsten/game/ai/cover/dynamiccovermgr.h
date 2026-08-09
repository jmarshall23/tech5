#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\cover\dynamiccovermgr.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14720; PDB kind: class.
class idDynamicCoverMgr : public idClass
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14728.
  virtual idTypeInfo *GetType();
  virtual ~idDynamicCoverMgr();
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

  bool isInitializedFlag;
  idList<idDynamicCover *,5> list;
};
