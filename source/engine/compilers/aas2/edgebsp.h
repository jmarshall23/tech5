#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\compilers\aas2\edgebsp.h
// Recovered logical types: 7
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 23857; PDB kind: class.
class idEdgeBSPNode
{
public:
  idBSPSurfacePlane plane;
  idEdgeBSPNode *parent;
  idEdgeBSPNode *children[2];
  idBSPSurface *surface;
  idBounds cullBounds;
  int areaNum;
  int floorColor;
  idList<int,37> edges;
  edgeBSPNodeType_t type;
  int flags;
  float height;
  int nodeNum;
};

// IDA Local Type ordinal 23869; PDB kind: class.
class idEdgeBSPEdge
{
public:
  int flags;
  int verts[2];
  idEdgeBSPNode *nodes[2];
};

// IDA Local Type ordinal 23871; PDB kind: class.
class idEdgeBSP
{
public:
  idBounds bounds;
  idVec3 normal;
  int edgeFlag;
  int walkableTriangleFlag;
  int ignoreTriangleFlag;
  int stepSideTriangleFlag;
  float minFloorThickness;
  float minCornerFloorSurfaceArea;
  float minHighCeiling;
  idEdgeBSPNode *root;
  idList<idEdgeBSPNode *,5> nodeList;
  int numThreads;
  idList<int,5> threadSilEdges;
  idList<int,5> threadSilVerts;
  struct idSysWorkerThreadGroup<idFindSplitterThread> *findSplitter;
  int numSplits;
  int numStitchedEdges;
  int numMergedColinearEdges;
  int numCollapsedFloors;
  int numPairwiseMergedFloors;
  int numThreeTwoMergedFloors;
  int numPairwiseAfterThreeTwoMergedFloors;
  int numPrunedNodes;
  idVectorSet<idVec3,3> vertices;
  idList<int,5> vertexFlags;
  idList<idEdgeBSPEdge,5> edges;
  idList<int,5> firstVertexEdges;
  idList<int,5> firstVertexEdgeChain;
  idList<int,5> secondVertexEdges;
  idList<int,5> secondVertexEdgeChain;
};

// IDA Local Type ordinal 23877; PDB kind: struct.
struct idEdgeBSP::idEdgeBSPFloor
{
  int index;
  float area;
  float min;
  float max;
  bool isOutside;
  bool hasHighCeiling;
  idList<int,5> triangles;
  idList<int,5> edges;
  idBSPSurface *surface;
};

// IDA Local Type ordinal 23878; PDB kind: struct.
struct __declspec(align(4)) idEdgeBSP::idEdgeBSPFloorEdge
{
  int verts[2];
  int edgeNum;
  idEdgeBSP::idEdgeBSPFloorEdge *next;
  bool isVertical;
};

// IDA Local Type ordinal 23879; PDB kind: struct.
struct __declspec(align(4)) idEdgeBSP::idEdgeBSPFloorEdgeSequence
{
  idEdgeBSP::idEdgeBSPFloorEdge *firstEdge;
  idEdgeBSP::idEdgeBSPFloorEdge *lastEdge;
  int numEdges;
  bool isClosed;
};

// IDA Local Type ordinal 23882; PDB kind: struct.
struct idEdgeBSP::idEdgeBSPFloorEdgeWindings
{
  idList<idEdgeBSP::idEdgeBSPFloorEdgeSequence,5> sequences;
  idBlockAlloc<idEdgeBSP::idEdgeBSPFloorEdge,128,12> floorEdges;
  idList<int,5> sharedEdges;
};
