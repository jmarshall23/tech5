#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\entities\splines\navsplinepathmgr.h
// Recovered logical types: 4
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 15647; PDB kind: class.
class idNavSplinePathMgr
{
public:
  // Recovered virtual interface; IDA vtable ordinal 15659.
  virtual ~idNavSplinePathMgr();
  virtual void Update();
  virtual void SpecialSetup();
  virtual idNavSplinePosition *GetClosestPathPosition(idNavSplinePosition *result, idVec3, idNavSpline *, float, float, idVec3, bool);
  virtual float GetNextRecalcTime();

  __declspec(align(8)) int nextRecalcTime;
  float updatetime;
  idTimer navSplineTrackerTimer;
  int navSplineTrackerCount;
  idTimer navSplineClosestPosTimer;
  int navSplineClosestPosCount;
  idTimer navSplineClosestPosSectionTimer;
  int navSplineClosestPosSectionCount;
  idNavSplinePathMgr::navSplineFloodBits_t *floodBits;
  int floodBitSize;
  idNavPathPosTrackerPool trackerPool;
  idStaticList<idHandle<short,enum invalidTrackerHandle_t,-1>,256> usedTrackers;
  idHashIndex trackerHash;
  idStaticList<idNavSpline,200> navSplineList;
  idList<idNavSpline,5> navSplineList_BuildGame;
  navSplinePath_t splinePath;
  int cleanupIndex;
  idEntityPtr<idNavSplinePath> tempNavSplinePath;
  idNavSpline tempNavSpline;
  navSplineType_t navSplineType;
  idStr tempNavSplinePathName;
  idTimer navSplinePathTimer;
  int navSplinePathCount;
  int navSplinePathCount2;
  idNavSplineGraph splineGraph;
  idNavPathPosTracker *debugTracker;
  idAngles freeAngles;
  idAngles currentViewAngles;
  idAngles lastCarAngles;
  int wildSpinTime;
  float viewAnglesDeltaPerc;
  int lastDrawTime;
  bool isStaticPathPos;
  idList<cachedSegList_t,5> segListTable;
};

// IDA Local Type ordinal 15660; PDB kind: struct.
struct idNavSplinePathMgr::navSplineFloodBits_t
{
  unsigned __int32 : 29;
  __int32 queued : 2;
  __int32 traversed : 1;
};

// IDA Local Type ordinal 16555; PDB kind: class.
class idQuestNavSplinePathMgr : public idNavSplinePathMgr
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16556.
  virtual ~idQuestNavSplinePathMgr();
  virtual void Update();
  virtual void SpecialSetup();
  virtual idNavSplinePosition *GetClosestPathPosition(idNavSplinePosition *result, idVec3, idNavSpline *, float, float, idVec3, bool);
  virtual float GetNextRecalcTime();

  float splineDistanceToJob;
  float totalDistanceToJob;
};

// IDA Local Type ordinal 19464; PDB kind: struct.
struct idNavSplinePathMgr::posInfo_t
{
  idVec3 pos;
  float widthSqr;
};
