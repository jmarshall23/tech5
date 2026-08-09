#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\aas2\aas2callback_findareaoutofrange.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 23526; PDB kind: class.
class idAAS2Callback_FindAreaOutOfRange : public idAAS2Callback_AvoidLocation
{
public:
  // Recovered virtual interface; IDA vtable ordinal 23527.
  virtual ~idAAS2Callback_FindAreaOutOfRange();
  virtual bool PathValid(const idAAS2 *, const idVec3 *, const idVec3 *);
  virtual int AdditionalTravelTimeForPath(const idAAS2 *, const idVec3 *, const idVec3 *);
  virtual bool AreaIsGoal(const idAAS2 *, int, const idVec3 *);

  idClip *clip;
  idVec3 targetPos;
  float maxDistSqr;
};
