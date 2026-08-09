#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\superscript\lib\trace.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 13671; PDB kind: class.
class idTraceOpts
{
public:
  float radius;
  bool skipInvisible;
  bool skipTranslucent;
  bool skipDynamic;
  bool twoSided;
  idRenderModel *skipModel;
};

// IDA Local Type ordinal 13983; PDB kind: class.
class ssTrace
{
public:
  ssVector startPos;
  ssVector endPos;
  ssVector rayDir;
  int contentMask;
  ssEntity ignoreEnt;
  float length;
  int clipQueryId;
  bool resolved;
  ssEntity hitEnt;
  ssVector hitPos;
  ssVector hitNormal;
  float hitFraction;
  float hitLength;
};

// IDA Local Type ordinal 14167; PDB kind: struct.
struct trace_t
{
  float fraction;
  idVec3 endpos;
  idMat3 endAxis;
  contactInfo_t c;
};

// IDA Local Type ordinal 23748; PDB kind: class.
class idTraceWork
{
public:
  cm_trmVertex_t verts[32];
  cm_trmEdge_t edges[32];
  cm_trmPolygon_t polys[16];
  idVec4 vertexPosition[32];
  idVec4 vertexEndPosition[32];
  idPluecker vertexPluecker[32];
  idPluecker edgePluecker[32];
  idPluecker edgeZAxisPluecker[32];
  idVec4 edgeNormal[32];
  unsigned __int8 vertIsUsed[32];
  unsigned __int8 edgeIsUsed[32];
  unsigned __int8 polyIsUsed[16];
  unsigned int numVerts;
  unsigned int numEdges;
  unsigned int numPolys;
  int contents;
  idVec4 start;
  idVec4 end;
  idVec4 dir;
  idVec4 negDir;
  idMat3x4 trmTransform;
  idVec4 trmBoundsMin;
  idVec4 trmBoundsMax;
  idVec4 trmExtents;
  idVec4 traceBoundsMin;
  idVec4 traceBoundsMax;
  idBoundsShort traceBoundsShort;
  int pad;
  idPlane heartPlane1;
  idPlane heartPlane2;
  float maxDistFromHeartPlane1;
  float maxDistFromHeartPlane2;
  float fraction;
  int subModelNum;
  float angle;
  float negAngle;
  float maxTan;
  float initialTan;
  idVec4 origin;
  idVec4 axis;
  idMat3x4 ZAxisTransform;
  idMat3x4 endTransform;
  float contactDepth;
  traceType_t traceType;
  bool isConvex;
  bool quickExit;
  cm_sideCache_t polygonSideCache;
  cm_sideCache_t polygonEdgeSideCache[20];
  cm_sideCache_t polygonVertexSideCache[20];
  idPluecker polygonEdgePlueckerCache[16];
  idPluecker polygonVertexPlueckerCache[16];
  unsigned __int8 subModelDataForBounds[768];
  idModelCheckCounts modelCheckCounts;
  cm_subModelPtrs_t subModelPtrs;
  trace_t *traceResult;
  contactsResult_t *contactsResult;
  clipResult_t *clipResult;
  trace_t tempTraceResult;
  int profile[5];
};
