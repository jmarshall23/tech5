#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\aaspositionmgr.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15015; PDB kind: class.
class idAASPosition
{
public:
  bool valid;
  unsigned __int16 areaNum;
  idVec3 origin;
  idVec3 validOrigin;
  const idAAS2 *aas;
};

// IDA Local Type ordinal 15016; PDB kind: class.
class idAASPositionMgr
{
public:
  idAASPosition aasPosition[2];
  int lastUpdateFrame[2];
  int numAASPositions;
};
