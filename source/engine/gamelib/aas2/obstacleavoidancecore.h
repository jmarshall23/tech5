#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\aas2\obstacleavoidancecore.h
// Recovered logical types: 6
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2805; PDB kind: enum.
enum idObstacleAvoidanceCore::avoidColor_t : __int32
{
  COLOR_INVALID = 0x0,
  COLOR_WHITE = 0x1,
  COLOR_GRAY = 0x2,
  COLOR_RED = 0x3,
  COLOR_BLUE = 0x4,
  COLOR_GREEN = 0x5,
  COLOR_YELLOW = 0x6,
  COLOR_ORANGE = 0x7,
  COLOR_PURPLE = 0x8,
  COLOR_CYAN = 0x9,
  COLOR_MAGENTA = 0xA,
};

// IDA Local Type ordinal 22035; PDB kind: struct.
struct idObstacleAvoidanceCore::pathNode_t
{
  int dir;
  idVec2 pos;
  idVec2 delta;
  float targetDistSqr;
  int obstacle;
  int edgeNum;
  int numNodes;
  idObstacleAvoidanceCore::pathNode_t *parent;
  idObstacleAvoidanceCore::pathNode_t *children[2];
  idQueueNode<idObstacleAvoidanceCore::pathNode_t> queueNode;
};

// IDA Local Type ordinal 22437; PDB kind: struct.
struct idObstacleAvoidanceCore::bspNode_t
{
  int axis;
  float dist;
  __int16 children[2];
  __int16 indexOffset;
  __int16 numIndices;
};

// IDA Local Type ordinal 22438; PDB kind: struct.
struct idObstacleAvoidanceCore::expandedObstacle_t
{
  idVec2 bounds[2];
  idVec2 *winding;
  int numPoints;
  int id;
  bool soft;
  unsigned __int8 pad[3];
};

// IDA Local Type ordinal 22439; PDB kind: class.
class idObstacleAvoidanceCore
{
public:
  idObstacleAvoidanceCore::bspNode_t *bspNodes;
  int numBspNodes;
  __int16 *obstacleIndices;
  idObstacleAvoidanceCore::expandedObstacle_t *expandedObstacles;
  int maxExpandedObstacles;
  int numExpandedObstacles;
  idVec2 *windingPoints;
  int maxWindingPoints;
  int numWindingPoints;
  unsigned __int8 *tempMemory;
  int tempMemorySize;
  unsigned __int8 *tempMemoryStart;
  unsigned __int8 *tempMemoryEnd;
  idObstacleAvoidanceCore::pathNode_t *pathNodes;
  int maxPathNodes;
  int numPathNodes;
  avoidDebugLine_t *debugLines;
  int maxDebugLines;
  int numDebugLines;
  avoidDebugText_t *debugText;
  int maxDebugText;
  int numDebugText;
  bool inputTransformValid;
  idMat3x4 inputTransform;
  int flags;
};

// IDA Local Type ordinal 23501; PDB kind: struct.
struct idObstacleAvoidanceCore::SetupExpandedObstacles::__l87::terminator_t
{
  float distSqr;
  __int16 lastEdgeIndex;
  __int16 firstEdgeIndex;
};
