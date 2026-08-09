#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\foliage\jobs\foliagegather.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 23352; PDB kind: struct.
struct foliageGather_t
{
  __int16 frustumVerts[3][8];
  const float *mvpMatrix;
  idVec3 viewDir;
  idVec3 viewOrg;
  foliageIndex_t *foliageIndices;
  unsigned int numFoliageIndices;
  unsigned int maxFoliageIndices;
  __int16 *influenceSphereIndices;
  unsigned int numInfluenceSphereIndices;
  unsigned int maxInfluenceSphereIndices;
  const influenceSphere_t *influenceSpheres;
  unsigned int influenceSphereStackSize;
  int influenceSphereStack[256];
  float foliageStartFadeDist;
  float foliageSmallFadeDistMax;
};
