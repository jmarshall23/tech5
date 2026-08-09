#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\sound\occlusion\flatsoundbsp.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13706; PDB kind: struct.
struct flatSoundBSP_t
{
  idPlane *planes;
  idVec3 *vertices;
  int *vertIndex;
  sbspFace_t *faces;
  int *faceIndex;
  sbspArea_t *areas;
  sbspNode_t *nodes;
  int numPlanes;
  int numVertices;
  int numVertIndex;
  int numFaces;
  int numFaceIndex;
  int numAreas;
  int numNodes;
};
