#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\models\cuttable\cutterclip.h
// Recovered logical types: 16
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 2768; PDB kind: unknown.
enum idCutterClip::<unnamed_tag> : __int32
{
  EDGESIDE_LEFT = 0x0,
  EDGESIDE_RIGHT = 0x1,
};

// IDA Local Type ordinal 2769; PDB kind: enum.
enum idCutterClip::horizontalDirection_t : __int32
{
  HORIZONTALDIRECTION_NONE = 0x0,
  HORIZONTALDIRECTION_LEFTTORIGHT = 0x1,
  HORIZONTALDIRECTION_RIGHTTOLEFT = 0x2,
};

// IDA Local Type ordinal 2770; PDB kind: enum.
enum idCutterClip::intersectProtects_t : __int32
{
  INTERSECTPROTECTS_NONE = 0x0,
  INTERSECTPROTECTS_LEFT = 0x1,
  INTERSECTPROTECTS_RIGHT = 0x2,
  INTERSECTPROTECTS_BOTH = 0x3,
};

// IDA Local Type ordinal 2771; PDB kind: enum.
enum idCutterClip::addEdge_t : __int32
{
  ADDEDGE_NONE = 0x0,
  ADDEDGE_LEFT = 0x1,
  ADDEDGE_RIGHT = 0x2,
  ADDEDGE_BOTH = 0x3,
};

// IDA Local Type ordinal 2772; PDB kind: enum.
enum idCutterClip::memPool_t : __int32
{
  NUM_POOLSCANBEAMS = 0x100,
  NUM_POOLLOCALMINIMAS = 0x100,
  NUM_POOLEDGES = 0x400,
  NUM_POOLPOLYGONS = 0x20,
  NUM_POOLPOLYGONPOINTS = 0x400,
  NUM_POOLINTERSECTPOINTS = 0x80,
  NUM_POOLJOINRECORDS = 0x80,
  NUM_POOLHORIZONTALJOINRECORDS = 0x80,
  NUM_POOLNESTEDPOLYGONS = 0x20,
  NUM_POOLCONTOURS = 0x20,
  NUM_POOLCONTOUREDGES = 0x400,
  NUM_POOLCONTOURNODES = 0x400,
};

// IDA Local Type ordinal 17335; PDB kind: struct.
struct idCutterClip::Edge_t
{
  idCutterClip::Edge_t *prev;
  idCutterClip::Edge_t *next;
  idCutterClip::Edge_t *prevLML;
  idCutterClip::Edge_t *nextLML;
  idCutterClip::Edge_t *prevAEL;
  idCutterClip::Edge_t *nextAEL;
  idCutterClip::Edge_t *prevSEL;
  idCutterClip::Edge_t *nextSEL;
  idVec2i top;
  idVec2i bottom;
  idVec2i current;
  float deltaX;
  int tmpX;
  __int16 windingCount;
  __int16 windingCount2;
  __int16 outIndex;
  __int16 windingDelta;
  unsigned __int16 : 1;
  unsigned __int16 __free : 12;
  unsigned __int16 horizontal : 1;
  unsigned __int16 polyType : 1;
  unsigned __int16 side : 1;
  int ID;
};

// IDA Local Type ordinal 17336; PDB kind: struct.
struct idCutterClip::Scanbeam_t
{
  idCutterClip::Scanbeam_t *next;
  int y;
};

// IDA Local Type ordinal 17337; PDB kind: struct.
struct __declspec(align(4)) idCutterClip::Polygon_t
{
  idCutterClip::Polygon_t *next;
  idCutterClip::Polygon_t *firstLeft;
  idCutterClip::Polygon_t *appendLink;
  idCutterClip::PolygonPoint_t *points;
  idCutterClip::PolygonPoint_t *bottomPoint;
  idCutterClip::Edge_t *bottomEdge1;
  idCutterClip::Edge_t *bottomEdge2;
  int index;
  bool connected;
  bool hole;
};

// IDA Local Type ordinal 17338; PDB kind: struct.
struct idCutterClip::PolygonPoint_t
{
  idCutterClip::PolygonPoint_t *next;
  idCutterClip::PolygonPoint_t *prev;
  idVec2i pos;
  int index;
};

// IDA Local Type ordinal 17339; PDB kind: struct.
struct idCutterClip::NestedPolygon_t
{
  idCutterClip::NestedPolygon_t *next;
  idCutterClip::Polygon_t *outer;
  idCutterClip::Polygon_t *inner;
};

// IDA Local Type ordinal 17340; PDB kind: struct.
struct idCutterClip::LocalMinima_t
{
  idCutterClip::LocalMinima_t *next;
  idCutterClip::Edge_t *leftBound;
  idCutterClip::Edge_t *rightBound;
  int y;
};

// IDA Local Type ordinal 17341; PDB kind: struct.
struct idCutterClip::IntersectNode_t
{
  idCutterClip::IntersectNode_t *next;
  idCutterClip::Edge_t *edge1;
  idCutterClip::Edge_t *edge2;
  idVec2i pos;
};

// IDA Local Type ordinal 17342; PDB kind: struct.
struct idCutterClip::JoinRecord_t
{
  idCutterClip::JoinRecord_t *next;
  idVec2i point1a;
  idVec2i point1b;
  idVec2i point2a;
  idVec2i point2b;
  __int16 polyIndex1;
  __int16 polyIndex2;
};

// IDA Local Type ordinal 17343; PDB kind: struct.
struct __declspec(align(4)) idCutterClip::HorizontalJoinRecord_t
{
  idCutterClip::HorizontalJoinRecord_t *next;
  idCutterClip::Edge_t *edge;
  __int16 savedIndex;
};

// IDA Local Type ordinal 17351; PDB kind: class.
class __declspec(align(4)) idCutterClip
{
public:
  int memoryPeek;
  int memoryCurrent;
  int numEdges;
  int maxEdges;
  int numLocalMinima;
  int maxLocalMinima;
  int numScanbeams;
  int maxScanbeams;
  int numPolygons;
  int maxPolygons;
  int numPolygonPoints;
  int maxPolygonPoints;
  int numNestedPolygons;
  int maxNestedPolygons;
  int numJoinRecords;
  int maxJoinRecords;
  int numHorizontalJoinRecords;
  int maxHorizontalJoinRecords;
  int numIntersectNode;
  int maxIntersectNode;
  idCutterClip::Edge_t *edgesPool;
  idCutterClip::Scanbeam_t *scanbeamsPool;
  idCutterClip::Polygon_t *polygonsPool;
  idCutterClip::PolygonPoint_t *polygonPointsPool;
  idCutterClip::NestedPolygon_t *nestedPolygonsPool;
  idCutterClip::LocalMinima_t *localMinimasPool;
  idCutterClip::IntersectNode_t *intersectNodesPool;
  idCutterClip::JoinRecord_t *joinRecordsPool;
  idCutterClip::HorizontalJoinRecord_t *horizontalJoinRecordsPool;
  idCutterClip::LocalMinima_t *currentLocalMinima;
  idCutterClip::LocalMinima_t *localMinimaList;
  idCutterClip::Scanbeam_t *scanbeams;
  idCutterClip::Edge_t *activeEdges;
  idCutterClip::Edge_t *sortedEdges;
  idCutterClip::IntersectNode_t *intersectNodes;
  idCutterClip::NestedPolygon_t *currentNestedPolygon;
  idCutterClip::Polygon_t *currentInnerPolygon;
  idList<idCutterClip::Edge_t *,5> edges;
  idList<idCutterClip::PolygonPoint_t *,5> polygonPoints;
  idList<idCutterClip::Polygon_t *,5> polygons;
  idList<idCutterClip::NestedPolygon_t *,5> nestedPolygons;
  idList<idCutterClip::JoinRecord_t *,5> joins;
  idList<idCutterClip::HorizontalJoinRecord_t *,5> horizontalJoins;
  idList<void *,5> poolAllocations;
  fillType_t fillTypeSubject;
  fillType_t fillTypeClip;
  clipMode_t clipMode;
  unsigned __int8 : 7;
  __int8 running : 1;
};

// IDA Local Type ordinal 22052; PDB kind: class.
class idCutterClip::idSort_Polygons : public idSort_Quick<idCutterClip::Polygon_t *,idCutterClip::idSort_Polygons>
{
public:
  // Recovered virtual interface; IDA vtable ordinal 22053.
  virtual ~idSort_Polygons();
  virtual void Sort(idCutterClip::Polygon_t **, unsigned int);

};
