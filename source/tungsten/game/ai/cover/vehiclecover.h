#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\cover\vehiclecover.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1289; PDB kind: enum.
enum vehicleDriver_t : __int32
{
  VEHICLE_DRIVER_ATV = 0x0,
  VEHICLE_DRIVER_CAR = 0x1,
  VEHICLE_DRIVER_MAX = 0x2,
};

// IDA Local Type ordinal 14729; PDB kind: class.
class idVehicleCoverMgr : public idDynamicCoverMgr
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14730.
  virtual idTypeInfo *GetType();
  virtual ~idVehicleCoverMgr();
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

// IDA Local Type ordinal 21374; PDB kind: class.
class idVehicleCover : public idDynamicCover
{
public:
  // Recovered virtual interface; IDA vtable ordinal 21375.
  virtual idTypeInfo *GetType();
  virtual ~idVehicleCover();
  virtual void UpdateUsable(const idEntity *, const idAAS2 *, const int);
  virtual void InternalUpdateCurrent(const idEntity *, const idAAS2 *, const int);
  virtual void InternalUpdateUsable(const idEntity *, const idAAS2 *, const int);
  virtual int InternalAppendUsableCover(const idEntity *, const idAAS2 *, idList<idAICover,5> *);
  virtual void MarkAllUnusable();
  virtual void MarkAllUsable();

};
