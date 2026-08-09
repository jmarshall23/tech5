#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\aiorientation.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2279; PDB kind: enum.
enum aiArrivalOrientation_t : __int32
{
  AIARRIVAL_ORIENT_NONE = 0x0,
  AIARRIVAL_ORIENT_ALIGN = 0x1,
};

// IDA Local Type ordinal 3067; PDB kind: enum.
enum hdpOrientation_t : __int32
{
  O_NONE = 0x0,
  O_FLIPV = 0x1,
  O_FLIPH = 0x2,
  O_FLIPVH = 0x3,
  O_RCW = 0x4,
  O_RCW_FLIPV = 0x5,
  O_RCW_FLIPH = 0x6,
  O_RCW_FLIPVH = 0x7,
  O_MAX = 0x8,
};

// IDA Local Type ordinal 16712; PDB kind: class.
class idAIOrientation
{
public:
  idVec3 idealDir;
  idMat3 axis;
  float lastTurnDelta;
  float lastTurnRate;
  float tolerance;
  unsigned __int8 currentTurnDir;
  unsigned __int8 previousTurnDir;
  float turnVelocity;
};
