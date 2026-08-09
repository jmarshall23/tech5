#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\triangles.h
// Recovered logical types: 1
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13337; PDB kind: class.
class idTriangles
{
public:
  idBounds bounds;
  bool generateNormals;
  int numIndexes;
  int numVerts;
  int detailOffset;
  bool allowGpuHosting;
  idVertexScaleAndBias vsb;
  unsigned int cpuVertexMask;
  idDrawVert *verts;
  unsigned __int16 *indexes;
  unsigned int vertexMask;
  idVertexBuffer vertexBuffer;
  idIndexBuffer indexBuffer;
};
