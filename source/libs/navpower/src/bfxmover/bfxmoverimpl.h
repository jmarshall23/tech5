#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 18228; PDB kind: class.
class idNpMoverImpl
{
public:
  idNavigationSpace moverSpace;
  bfx::Mover *mover;
};

// IDA Local Type ordinal 18230; PDB kind: struct.
struct __declspec(align(2)) idNpMoverImpl::idGotoParms
{
  float stopDistAllowed;
  float stopDistDesired;
  idVec3 orientAtGoalDir;
  bool orientAtGoalEnabled;
  bool stopAtGoal;
  bool pushThroughCrowd;
};
