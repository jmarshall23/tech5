#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\detail\jobs\detailgather.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 23370; PDB kind: struct.
struct detailGather_t
{
  __int16 frustumVerts[3][8];
  int maxDetailHeight;
  const float *mvpMatrix;
  unsigned __int16 *detailIndices;
  unsigned int maxDetailIndices;
  unsigned int numDetailIndices;
  unsigned int vertCount;
  unsigned int indexCount;
};
