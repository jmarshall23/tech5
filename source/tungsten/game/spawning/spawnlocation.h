#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\spawning\spawnlocation.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15103; PDB kind: struct.
const struct __declspec(align(4)) splineLocation_t
{
  idEntityPtr<idSplinePath> splinePath;
  float lengthOnSpline;
  float controlPointLength;
  float controlPointPCT;
  int controlPointIndex;
  idVec3 controlPointOrigin;
  idVec3 controlPointOriginNext;
  bool initialized;
  bool dirty;
};

// IDA Local Type ordinal 15572; PDB kind: class.
class idSpawnLocation
{
public:
  idVec3 pos;
  idAngles facing;
  float valueModifier;
  idSpawnNode *sourceNode;
  int locationID;
  float sortValue;
};
