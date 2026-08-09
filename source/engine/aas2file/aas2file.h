#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\aas2file\aas2file.h
// Recovered logical types: 5
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 21931; PDB kind: struct.
struct idAAS2File::bspTree_t
{
  idVec3 floorNormal;
  int headNode;
  int firstArea;
  int lastArea;
};

// IDA Local Type ordinal 22000; PDB kind: class.
class idAAS2File : public idResource
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22001.
  virtual ~idAAS2File();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();

  unsigned int crc;
  unsigned int timestamp;
  idList<int,37> visitedAreas;
  idAAS2Settings settings;
  int major;
  int minor;
  int firstFakeVertex;
  int firstFakeEdge;
  int firstFakeEdgeIndex;
  int firstFakeArea;
  idList<idAAS2File::bspTree_t,37> trees;
  idList<idPlane,37> planes;
  idList<idVec3,37> vertices;
  idList<aas2Edge_t,37> edges;
  idList<int,37> edgeIndex;
  idList<aas2Reachability_t,37> reachabilities;
  idList<aas2Area_t,37> areas;
  idList<aas2Node_t,37> nodes;
  idList<aas2Portal_t,37> portals;
  idList<int,37> portalIndex;
  idList<aas2Cluster_t,37> clusters;
  idList<unsigned char,37> obstaclePVS;
  idList<aas2Name_t,37> reachabilityNames;
  idList<aas2AnimName_t,37> animNames;
  idList<aas2DependencyName_t,37> dependencyNames;
  idList<aas2InteractionEntityName_t,37> interactionEntityNames;
  idList<aas2TraversalEntityName_t,37> traversalEntityNames;
  idList<aas2Cover_t,37> cover;
  idList<int,37> areaCoverIndex;
  idList<int,37> touchingCoverIndex;
  idList<aas2ChokePoint_t,37> chokePoints;
  idList<aas2Traversal_t,37> traversalPoints;
  idList<aas2HintNode_t,37> hintNodes;
  idList<aas2AreaBounds_t,37> areaBounds;
};

// IDA Local Type ordinal 22021; PDB kind: struct.
struct idAAS2File::bestReachableArea_t
{
  float bboxHeight;
  float maxEdgeDist;
  int areaFlags;
  int excludeTravelFlags;
  int pointAreaNum;
  float pointAreaFloorDist;
  int boundsAreaNum;
  float boundsAreaFloorDist;
};

// IDA Local Type ordinal 22022; PDB kind: struct.
struct idAAS2File::floorEdgeSplitPoint_t
{
  idVec3 point;
  float dist;
  int edgeNum;
};

// IDA Local Type ordinal 23832; PDB kind: struct.
struct idAAS2File::GetObstaclePVSWallEdges::__l25::wallEdge_t
{
  int edgeNum;
  int verts[2];
  idAAS2File::GetObstaclePVSWallEdges::__l25::wallEdge_t *next;
};
