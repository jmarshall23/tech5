#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\zipline\jobs\ziplinegen.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 18807; PDB kind: struct.
struct zipLineGenParms_t
{
  const idNonUniformBSpline<idVec3> *controlSpline;
  int splineTessellationDistance;
  int splineMaxSubdivisions;
  int cableSubdivisions;
  float cableDiameter;
  const sweptPoint_t *sweptPoints;
  float time;
  float fractionBeforeLerp;
  bool downDirection;
  int maxVertices;
  int maxIndices;
  idDrawVert *vertices;
  unsigned __int16 *indices;
  int *numVertices;
  int *numIndices;
};
