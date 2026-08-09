#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\cuttable\cuttergraph.h
// Recovered logical types: 14
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2616; PDB kind: unknown.
enum idCutterGraphManager::<unnamed_tag> : __int32
{
  NUM_POOLNODES = 0x400,
  NUM_POOLLINKS = 0x400,
};

// IDA Local Type ordinal 15906; PDB kind: class.
class idCutterGraphManager
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15907.
  virtual ~idCutterGraphManager();

  idList<idCutterGraphManager::savedContour_t,5> savedContours;
  idList<idCutterGraphManager::savedPathPos_t,5> savedNodes;
  idList<idCutterGraphManager::Node_t *,5> invalidNodes;
  idList<idCutterGraphManager::graph_t,5> graphs;
  idList<idCutterGraphManager::Link_t *,5> linksPoolBlock;
  idList<idCutterGraphManager::Node_t *,5> nodesPoolBlock;
  idList<idCutterGraphManager::Edge_t *,5> edgesPoolBlock;
  idList<idCutterGraphManager::Link_t *,5> linksPool;
  idList<idCutterGraphManager::Node_t *,5> nodesPool;
  idList<idCutterGraphManager::Edge_t *,5> edgesPool;
  ContourManager *contourManager;
  idCutterGraphManager::Graph *graph;
};

// IDA Local Type ordinal 15908; PDB kind: struct.
struct idCutterGraphManager::savedContour_t
{
  idList<idVec3,5> contourPoints;
  idColor color;
  idStr text;
};

// IDA Local Type ordinal 15910; PDB kind: struct.
struct idCutterGraphManager::savedPathPos_t
{
  idVec3 pos;
  idVec2 localPos;
  idColor color;
};

// IDA Local Type ordinal 15912; PDB kind: struct.
struct idCutterGraphManager::Node_t
{
  idCutterGraphManager::Node_t *next;
  idCutterGraphManager::Link_t *link;
  idVec2i pos;
  __int32 allocated : 1;
  __int32 id : 31;
};

// IDA Local Type ordinal 15913; PDB kind: struct.
struct idCutterGraphManager::Link_t
{
  idCutterGraphManager::Link_t *next;
  idCutterGraphManager::Edge_t *edge;
  idCutterGraphManager::Node_t *node;
  unsigned __int32 : 31;
  __int32 allocated : 1;
  int invalid;
};

// IDA Local Type ordinal 15914; PDB kind: struct.
struct idCutterGraphManager::Edge_t
{
  idCutterGraphManager::Edge_t *next;
  idCutterGraphManager::Node_t *node1;
  idCutterGraphManager::Node_t *node2;
  Contour *contour;
  ContourEdge_t *contourEdge;
  unsigned __int32 : 30;
  __int32 allocated : 1;
  __int32 visited : 1;
};

// IDA Local Type ordinal 15919; PDB kind: struct.
struct idCutterGraphManager::nodeHandle_t
{
  idCutterGraphManager::Node_t *data;
};

// IDA Local Type ordinal 15921; PDB kind: struct.
struct idCutterGraphManager::edgeHandle_t
{
  idCutterGraphManager::Edge_t *data;
};

// IDA Local Type ordinal 15923; PDB kind: struct.
struct idCutterGraphManager::linkHandle_t
{
  idCutterGraphManager::Link_t *data;
};

// IDA Local Type ordinal 15925; PDB kind: class.
class idCutterGraphManager::IDHeap
{
public:
  idList<unsigned char,5> buffer;
  unsigned __int32 isStatic : 1;
  unsigned __int32 index : 31;
  int numBits;
};

// IDA Local Type ordinal 15926; PDB kind: class.
class idCutterGraphManager::Graph
{
public:
  idCutterGraphManager::Node_t *lastNode;
  idCutterGraphManager::Node_t *prevNode;
  idList<idCutterGraphManager::nodeHandle_t,5> nodes;
  idList<idCutterGraphManager::edgeHandle_t,5> edges;
  idList<idCutterGraphManager::linkHandle_t,5> links;
  Contour *contoursOuter;
  Contour *contoursInner;
  idCutterGraphManager::IDHeap idheap;
  idStr name;
  idMat3 inverse;
  idMat3 orientation;
  idVec3 position;
  idVec3 normal;
  idVec3 left;
  idVec3 down;
};

// IDA Local Type ordinal 15927; PDB kind: struct.
struct idCutterGraphManager::graph_t
{
  idCutterGraphManager::Graph *graph;
};

// IDA Local Type ordinal 18655; PDB kind: class.
class idCutterGraphState
{
public:
  idCutterGraphManager *manager;
  idList<int,5> graphHandles;
};
