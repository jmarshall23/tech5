#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\renderer\development\manifold.h
// Recovered logical types: 9
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 3033; PDB kind: enum.
enum idManifold::occluders_t : __int32
{
  OCCLUDERS_NONE = 0x0,
  OCCLUDERS_ALL = 0x1,
  OCCLUDERS_SIGNIFICANT = 0x2,
  OCCLUDERS_OMNI_SIGNIFICANT = 0x3,
  OCCLUDERS_DETAIL = 0x4,
  OCCLUDERS_PIPE = 0x5,
};

// IDA Local Type ordinal 3034; PDB kind: enum.
enum idManifold::color_t : __int32
{
  COLOR_NONE = 0x0,
  COLOR_ISLANDS = 0x1,
  COLOR_NODES = 0x2,
};

// IDA Local Type ordinal 3035; PDB kind: unknown.
typedef idBSPSurface::<unnamed_tag> idManifold::<unnamed_tag>;

// IDA Local Type ordinal 22836; PDB kind: struct.
struct manifoldEdge_t
{
  manifoldVertex_t *verts[2];
  manifoldEdgeTriangle_t *tris[2];
  manifoldEdge_t *split[2];
  int numTris;
  int flags;
};

// IDA Local Type ordinal 22837; PDB kind: struct.
struct manifoldHint_t
{
  int planeType;
  float planeDist;
  idWinding *winding;
};

// IDA Local Type ordinal 22842; PDB kind: struct.
struct manifoldNode_t
{
  int planeType;
  float planeDist;
  idBounds bounds;
  idList<manifoldHint_t,5> hints;
  idList<manifoldTriangle_t *,5> triangles;
  idHashIndex triangleHash;
  idList<manifoldIsland_t *,5> islands;
  manifoldNode_t *children[2];
};

// IDA Local Type ordinal 22845; PDB kind: struct.
struct idManifold::tree_t
{
  manifoldNode_t *root;
  idManifold::occluders_t splitOccluders;
  int trianglesPerNode;
  float planarEpsilon;
  float colinearEpsilon;
  float flipEpsilon;
  float convexEpsilon;
  float textureSpaceEpsilon;
  int doneTriangles;
  int donePercent;
};

// IDA Local Type ordinal 22864; PDB kind: class.
class idManifold
{
public:
  idList<manifoldVertex_t *,5> vertices;
  idList<manifoldEdge_t *,5> edges;
  idList<manifoldTriangle_t *,5> triangles;
  idList<manifoldIsland_t *,5> islands;
  idHashIndex vertexHash;
  idHashIndex edgeHash;
  idHashIndex triangleHash;
  idList<manifoldEdge_t *,5> splitEdges;
  idManifold::tree_t tree;
  idList<idStr,5> binaryModelNames;
  idList<bool,5> binaryModelState;
  idBlockAlloc<manifoldVertex_t,1024,12> manifoldVertexAllocator;
  idBlockAlloc<manifoldEdgeTriangle_t,1024,12> manifoldEdgeTriangleAllocator;
  idBlockAlloc<manifoldEdge_t,1024,12> manifoldEdgeAllocator;
  idBlockAlloc<manifoldTriangle_t,1024,12> manifoldTriangleAllocator;
  idBlockAlloc<manifoldIsland_t,128,12> manifoldIslandAllocator;
  idBlockAlloc<manifoldNode_t,1024,12> manifoldNodeAllocator;
};

// IDA Local Type ordinal 22865; PDB kind: struct.
struct idManifold::tjunction_t
{
  manifoldEdge_t *edge;
  manifoldVertex_t *vertex;
};
