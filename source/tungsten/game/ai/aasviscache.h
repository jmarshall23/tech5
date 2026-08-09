#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\ai\aasviscache.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 17271; PDB kind: class.
class idAASVisArea
{
public:
  int areaNum;
  int xcells;
  int ycells;
  float visRatio;
  idBitArray cellVis;
};

// IDA Local Type ordinal 17275; PDB kind: class.
class idAASVisCache
{
public:
  const idAAS2 *aas;
  float eyeHeight;
  int subDivisionSize;
  idList<idAASVisPoint *,93> visPoints;
};
