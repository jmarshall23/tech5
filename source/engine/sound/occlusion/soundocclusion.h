#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\sound\occlusion\soundocclusion.h
// Recovered logical types: 2
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13727; PDB kind: struct.
struct soundOcclusionResult_t
{
  idVec3 virtualSoundOrigin;
  float occludedDistance;
  idVec3 *pathPoints;
  int numPathPoints;
  int maxPathPoints;
  int valid;
};

// IDA Local Type ordinal 13728; PDB kind: struct.
struct soundOcclusionParms_t
{
  soundOcclusionResult_t result;
  flatSoundBSP_t flatBSP;
  int *listenerRoute;
  int numAreas;
  float *doors;
  int numDoors;
  int listenerAreaNum;
  idVec3 listenerOrigin;
  int soundAreaNum;
  idVec3 soundOrigin;
  float maxDistance;
};
