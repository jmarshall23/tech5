#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\cover\aicovermanager.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 17233; PDB kind: class.
class __declspec(align(4)) idAICoverManager
{
public:
  idList<idAICover,5> knownCover;
  int lastUpdateTime;
  int lastTravelFlags;
  idVec3 lastUpdatePos;
  bool forceUpdate;
};
