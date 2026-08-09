#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\cuttable\earcliptriangulate.h
// Recovered logical types: 6
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 19982; PDB kind: unknown.
union idEarClipTriangulate::Vertex_t::<unnamed_type_prevShared>
{
  __int16 convex;
  __int16 reflex;
  __int16 value;
};

// IDA Local Type ordinal 19983; PDB kind: unknown.
union idEarClipTriangulate::Vertex_t::<unnamed_type_nextShared>
{
  __int16 convex;
  __int16 reflex;
  __int16 value;
};

// IDA Local Type ordinal 19984; PDB kind: struct.
struct idEarClipTriangulate::Vertex_t
{
  __int16 index;
  __int16 prevVertex;
  __int16 nextVertex;
  __int16 prevEar;
  __int16 nextEar;
  idEarClipTriangulate::Vertex_t::<unnamed_type_prevShared> prevShared;
  idEarClipTriangulate::Vertex_t::<unnamed_type_nextShared> nextShared;
  __int16 __free : 14;
  __int16 isEar : 1;
  __int16 isConvex : 1;
};

// IDA Local Type ordinal 19987; PDB kind: struct.
struct __declspec(align(4)) idEarClipTriangulate::Contour_t
{
  idList<short,5> indices;
  float valueMax;
  __int16 indexMax;
};

// IDA Local Type ordinal 19989; PDB kind: class.
class idEarClipTriangulate::IndexMap
{
public:
  idHashIndex hashIndex;
  idList<short,5> indices;
};

// IDA Local Type ordinal 19990; PDB kind: class.
class idEarClipTriangulate
{
public:
  idList<idVec2,5> positions;
  idList<idEarClipTriangulate::Vertex_t,5> vertices;
  idList<idEarClipTriangulate::Contour_t *,5> contours;
  idList<short,5> indices;
  idList<short,5> triangles;
  idEarClipTriangulate::IndexMap indexMap;
  int headConvex;
  int tailConvex;
  int headReflex;
  int tailReflex;
  int headEar;
  int tailEar;
  int maxIndex;
};
