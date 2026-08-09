#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\entities\splines\navspline.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1522; PDB kind: enum.
enum navSplineType_t : __int32
{
  NAV_SPLINE_TYPE_DEFAULT = 0x0,
  NAV_SPLINE_TYPE_VEHICLE_AI = 0x1,
  NAV_SPLINE_TYPE_QUEST = 0x2,
};

// IDA Local Type ordinal 15650; PDB kind: class.
class idNavSpline
{
public:
  idNavSplinePath *splinePath;
  idCurve_Spline<idVec3> *curve;
  float width;
  float length;
  bool traversed;
  bool isTempSpline;
  idList<navSplineConnection_t,5> next;
  idList<navSplineConnection_t,5> prev;
  idList<idEntityPtr<idEntity>,5> entityList;
  navSplinePathNode_t *startNode;
  navSplinePathNode_t *endNode;
  idNavSpline *bestNext;
  idNavSpline *bestPrev;
  idBounds bounds;
  int drawtime;
};

// IDA Local Type ordinal 15654; PDB kind: struct.
struct navSplineLink_t
{
  navSplinePathNode_t *node;
  float nodeDistance;
  idNavSpline *navSpline;
  float splineDistance;
};

// IDA Local Type ordinal 19467; PDB kind: struct.
struct navSplineTrav_t
{
  idNavSplinePosition pathPos;
  float traversalDist;
  int dir;
};
