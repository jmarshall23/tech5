#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\guis\devicecontext.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14938; PDB kind: class.
class __declspec(align(16)) idDeviceContext
{
public:
  idRenderModelGui *gui;
  const idMaterial *whiteMaterial;
  const idFont *activeFont;
  __declspec(align(8)) idDrawVert stretchPicVerts[32];
  unsigned __int16 stretchPicIndices[90];
  idVec2 uiScale;
  idVec2 uiOffset;
  idMat3 axis;
  idVec3 origin;
  bool identityMatrix;
};
