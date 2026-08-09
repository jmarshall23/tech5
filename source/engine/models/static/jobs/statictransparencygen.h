#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\static\jobs\statictransparencygen.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14744; PDB kind: struct.
struct staticTransparencyGenParms_t
{
  const idDrawVert *inputVerts;
  int numInputVerts;
  float fadeStartDist;
  float fadeMaxDist;
  idVec3 origin;
  idMat3 axis;
  idVec3 viewOrg;
  idVec3 viewDir;
  idVec4 transSortScaleBias;
  approximateLighting_t lighting;
  idTransparencyVert *verts;
  float *quadDepth;
  int *quadsUsed;
};
