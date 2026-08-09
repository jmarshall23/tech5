#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\aas2\aas2callback_findflaggedarea.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 23524; PDB kind: class.
class idAAS2Callback_FindFlaggedArea : public idAAS2Callback_AvoidLocation
{
public:
  // Recovered virtual interface; IDA vtable ordinal 23525.
  virtual ~idAAS2Callback_FindFlaggedArea();
  virtual bool PathValid(const idAAS2 *, const idVec3 *, const idVec3 *);
  virtual int AdditionalTravelTimeForPath(const idAAS2 *, const idVec3 *, const idVec3 *);
  virtual bool AreaIsGoal(const idAAS2 *, int, const idVec3 *);

  int areaFlag;
  int test;
};
