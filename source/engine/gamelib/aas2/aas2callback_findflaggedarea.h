#pragma once

#include "gamelib/aas2/aas2callback_avoidlocation.h"

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\aas2\aas2callback_findflaggedarea.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 23524; PDB kind: class.
class idAAS2Callback_FindFlaggedArea : public idAAS2Callback_AvoidLocation
{
public:
  idAAS2Callback_FindFlaggedArea(int areaFlag, bool set);

  // Recovered virtual interface; IDA vtable ordinal 23525.
  ~idAAS2Callback_FindFlaggedArea() override;
  bool AreaIsGoal(const idAAS2 *, int, const idVec3 *) override;

  int areaFlag;
  int test;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idAAS2Callback_FindFlaggedArea) == 36,
    "Recovered idAAS2Callback_FindFlaggedArea ABI changed");
#endif
