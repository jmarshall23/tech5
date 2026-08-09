#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\rendermodelsurface.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13425; PDB kind: class.
class idRenderModelSurface
{
public:
  const idMaterial *material;
  int materialNum;
  unsigned __int64 extraGLState;
  idTriangles *geometry;
  bool geometryIsReference;
  unsigned __int8 referenceMask;
  int binaryModelId;
  idJointBuffer *joints;
  idVertexBuffer *morphMap;
  idVertexBuffer *stMap;
  idVec4 skinOffsets;
};
