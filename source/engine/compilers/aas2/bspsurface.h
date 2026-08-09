#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\compilers\aas2\bspsurface.h
// Recovered logical types: 10
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 3262; PDB kind: unknown.
enum idBSPSurface::<unnamed_tag> : __int32
{
  ON_EDGE_NOT = 0x0,
  ON_EDGE_ON_LINE = 0x1,
  ON_EDGE_ON_EDGE = 0x2,
  ON_EDGE_ON_START = 0x4,
  ON_EDGE_ON_END = 0x8,
};

// IDA Local Type ordinal 23856; PDB kind: class.
class idBSPSurfacePlane
{
public:
  long double a;
  long double b;
  long double c;
  long double d;
};

// IDA Local Type ordinal 23858; PDB kind: class.
class idBSPSurfaceVert
{
public:
  idVec3 xyz;
  int flags;
};

// IDA Local Type ordinal 23860; PDB kind: class.
class idBSPSurfaceEdge
{
public:
  int verts[2];
  int tris[2];
  int numTris;
  int flags;
};

// IDA Local Type ordinal 23862; PDB kind: class.
class idBSPSurfaceTriInfo
{
public:
  int flags;
  int planeNum;
};

// IDA Local Type ordinal 23865; PDB kind: class.
class __declspec(align(4)) idBSPSurface
{
public:
  idList<idBSPSurfaceVert,5> verts;
  idList<int,5> indexes;
  idList<idBSPSurfaceEdge,5> edges;
  idList<int,5> edgeIndexes;
  idList<int,5> vertexEdges;
  idList<int,5> vertexEdgeChain;
  idList<idBSPSurfaceTriInfo,5> triangleInfo;
  idList<idBSPSurfacePlane,5> trianglePlanes;
  struct idBSPSurfaceTracer *tracer;
  idBounds bounds;
  bool hasTriInfo;
  bool boundsValid;
};

// IDA Local Type ordinal 23873; PDB kind: struct.
struct idBSPSurface::triangleIntersection_t
{
  idVec3 point;
  float dist;
};

// IDA Local Type ordinal 23874; PDB kind: struct.
struct idBSPSurface::vertexRemap_t
{
  int vertexNum;
  idBSPSurface::vertexRemap_t *next;
};

// IDA Local Type ordinal 23875; PDB kind: struct.
struct idBSPSurface::edgeRemap_t
{
  int e0;
  int e1;
};

// IDA Local Type ordinal 23876; PDB kind: struct.
struct idBSPSurface::step_t
{
  int topEdgeNum;
  int bottomEdgeNum;
};
