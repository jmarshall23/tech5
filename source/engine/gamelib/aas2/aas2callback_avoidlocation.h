#pragma once

#include "gamelib/aas2/aas2.h"
#include "idlib/bv/bounds.h"

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\aas2\aas2callback_avoidlocation.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 23521; PDB kind: struct. The PDB mapped this type to
// tungsten/game/ai/aasobstacle.h; it is declared here to keep the recovered
// GameLib callback boundary self-contained.
struct idAAS2Obstacle
{
  idBounds absBounds;
  idBounds expAbsBounds;
};

// IDA Local Type ordinal 23522; PDB kind: class.
class idAAS2Callback_AvoidLocation : public idAAS2Callback
{
public:
  idAAS2Callback_AvoidLocation();

  // Recovered virtual interface; IDA vtable ordinal 23523.
  ~idAAS2Callback_AvoidLocation() override;
  bool PathValid(const idAAS2 *, const idVec3 *, const idVec3 *) override;
  int AdditionalTravelTimeForPath(const idAAS2 *, const idVec3 *, const idVec3 *) override;

  idVec3 avoidLocation;
  float avoidDist;
  const idAAS2Obstacle *obstacles;
  int numObstacles;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAAS2Obstacle) == 48,
    "Recovered idAAS2Obstacle ABI changed");
static_assert(sizeof(idAAS2Callback_AvoidLocation) == 28,
    "Recovered idAAS2Callback_AvoidLocation ABI changed");
#endif
