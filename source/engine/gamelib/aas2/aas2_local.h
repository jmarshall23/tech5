#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\engine\gamelib\aas2\aas2_local.h
// Recovered logical types: 3
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 3176; PDB kind: unknown.
enum idAAS2Local::NearestPointReachable::__l2::<unnamed_tag> : __int32
{
  MaxAreas = 0x20,
};

// IDA Local Type ordinal 14089; PDB kind: struct.
struct idAAS2Goal
{
  int areaNum;
  idVec3 origin;
};

// IDA Local Type ordinal 23504; PDB kind: class.
class idAAS2Local : public idAAS2
{
public:
  // Recovered virtual interface; IDA vtable ordinal 23510.
  virtual ~idAAS2Local();
  virtual bool IsDefault();
  virtual bool Init(const char *, unsigned int);
  virtual void Stats();
  virtual void Test(const idVec3 *, const idVec3 *, const idMat3 *, int, int, int, int, const int, idClip *, usercmd_t *, idAngles *);
  virtual const idAAS2Settings *GetSettings();
  virtual idBounds *DefaultSearchBounds(idBounds *result);
  virtual int PointAreaNum(idIndex<int,enum invalidAASTree_t>, const idVec3 *);
  virtual int PointReachableAreaNum(idIndex<int,enum invalidAASTree_t>, const idVec3 *, const idBounds *, const int, const int);
  virtual int BoundsReachableAreaNum(idIndex<int,enum invalidAASTree_t>, const idBounds *, const int, const int);
  virtual int BoundsReachableAreaNum_2(idIndex<int,enum invalidAASTree_t>, const idVec3 *, const idBounds *, const int, const int);
  virtual bool NearestPointReachable(idIndex<int,enum invalidAASTree_t>, const idVec3 *, const int, const idVec3 *, const idBounds *, const int, idAAS2NearestReachable *);
  virtual void PushPointIntoAreaNum(int, idVec3 *);
  virtual idVec3 *AreaCenter(idVec3 *result, int);
  virtual bool Trace(idIndex<int,enum invalidAASTree_t>, aas2Trace_t *, const idVec3 *, const idVec3 *);
  virtual bool TraceHeight(idIndex<int,enum invalidAASTree_t>, aas2TraceHeight_t *, const idVec3 *, const idVec3 *);
  virtual bool TraceFloor(aas2TraceFloor_t *, const idVec3 *, int, const idVec3 *, int, bool, bool, bool);
  virtual void GetEdgeVertexNumbers(int, int *);
  virtual void GetEdge(int, idVec3 *, idVec3 *);
  virtual int GetEdgeFlags(int);
  virtual int GetAreaFlags(int);
  virtual bool ChangeAreaTravelFlags(const idBounds *, const int, int, bool);
  virtual bool ChangeReachabilityTravelFlags(const char *, int, bool);
  virtual bool ChangeReachabilityTravelFlags_2(idIndex<short,enum invalidReachability_t>, int, bool);
  virtual int TravelTimeToGoalArea(int, const idVec3 *, int, const idVec3 *, int, const idAAS2TravelSpeeds *);
  virtual bool RouteToGoalArea(int, const idVec3 *, int, const idVec3 *, int, int *, idIndex<short,enum invalidReachability_t> *);
  virtual bool FindNearestGoal(idAAS2Goal *, int, const idVec3 *, int, idAAS2Callback *);
  virtual bool WalkPathToGoal(idAAS2Path *, int, const idVec3 *, int, const idVec3 *, const int, const int);
  virtual bool ExtendHopPathToGoal(idAAS2Path *, int, const idVec3 *, int, const idVec3 *, int, int, const idAAS2HopPathParms *);
  virtual void ShowWalkPath(const int, const idVec3 *, const int, const idVec3 *, const int, const int, const int, const int, const int);
  virtual void ShowHopPath(int, const idVec3 *, int, const idVec3 *, int, int, const idAAS2HopPathParms *);
  virtual void DrawEdge(const int, const bool, const bool, const bool);
  virtual void DrawReachability(const idIndex<short,enum invalidReachability_t>, const aas2Reachability_t *, const char *);
  virtual void DrawArea(const int, const bool, const bool, const bool, const bool, const bool, const bool);
  virtual float GetGroundSpeedMultiplier();
  virtual bool GetOptimizedWalkPath(int, const idVec3 *, int, const idVec3 *, int, int, idList<idVec3,5> *);
  virtual int GetNumAreas();
  virtual const idPlane *GetPlane(const int);
  virtual const aas2Area_t *GetArea(const int);
  virtual const aas2Reachability_t *GetReachability(const idIndex<short,enum invalidReachability_t>);
  virtual bool GetPath(const idVec3 *, const idVec3 *, const int, const int, const int, idAAS2PathPoint *, const int, int *);
  virtual void ClipGridToAreas(const idVec3 *, int, int, int, int, unsigned __int8 *);
  virtual int GetInvalidTravelFlags();
  virtual int GetTraversalsForReachability(const idIndex<short,enum invalidReachability_t>, idList<int,5> *);
  virtual int GetTraversalsForInteractableEntity(const idIndex<short,enum invalidAASInteractionEntIndex_t>, idList<int,5> *);
  virtual int FindBestTraversalForReachability(const idIndex<short,enum invalidReachability_t>, const idVec3 *, const idVec3 *, idVec3 *, idVec3 *, idIndex<short,enum invalidAASDependencyIndex_t> *, const int, bool);
  virtual const aas2Traversal_t *GetTraversal(const int);
  virtual bool GetAASAnim(const idIndex<short,enum invalidAASAnimIndex_t>, const aas2AnimName_t **);
  virtual idIndex<short,enum invalidAASAnimIndex_t> *GetAASAnimIndexByName(idIndex<short,enum invalidAASAnimIndex_t> *result, const char *);
  virtual bool GetAASDependency(const idIndex<short,enum invalidAASDependencyIndex_t>, const aas2DependencyName_t **);
  virtual idIndex<short,enum invalidAASDependencyIndex_t> *GetAASDependencyIndexByName(idIndex<short,enum invalidAASDependencyIndex_t> *result, const char *);
  virtual bool GetAASInteractionEntity(const idIndex<short,enum invalidAASInteractionEntIndex_t>, const aas2InteractionEntityName_t **);
  virtual idIndex<short,enum invalidAASInteractionEntIndex_t> *GetAASInteractionEntityIndexByName(idIndex<short,enum invalidAASInteractionEntIndex_t> *result, const char *);
  virtual bool GetAASTraversalNameIndex(const idIndex<short,enum invalidAASTraversalNameIndex_t>, const aas2TraversalEntityName_t **);
  virtual idIndex<short,enum invalidAASTraversalNameIndex_t> *GetAASTraversalNameIndexByName(idIndex<short,enum invalidAASTraversalNameIndex_t> *result, const char *);
  virtual int GetAASTraversalIndexByNameIndex(const idIndex<short,enum invalidAASTraversalNameIndex_t>);
  virtual bool SetTraversalFlag(int, int);
  virtual bool ClearTraversalFlag(int, int);
  virtual const unsigned __int8 *GetObstaclePVS(int);
  virtual int GetObstaclePVSWallEdges(int, int, int *, int);
  virtual int GetObstaclePVSClipModels(int, idClipModel **, int);
  virtual void GetObstaclePVSObstacles(const int, const int, obstacleVertex_t *, int *, obstacleEdge_t *, int *, idClipModel **, int *, obstacleRoute_t *);
  virtual void FreeClipLinks();
  virtual idAASClipLink *LinkClipModel(idClipModel *);
  virtual idAASClipLink *UnLinkClipModel(idAASClipLink *);
  virtual int GetNumCoverPoints();
  virtual const aas2Cover_t *GetCoverPoint(const int);
  virtual int GetNumAreaCoverPoints(const int);
  virtual int GetAreaCoverPoints(const int, int *, const int, int *);
  virtual int FindCoverPoints(const int, const idVec3 *, const float, const int, const int, const int, int *, const int, int *);
  virtual int GetNumChokePoints();
  virtual const aas2ChokePoint_t *GetChokePoint(const int);
  virtual int GetNumHintNodes();
  virtual const aas2HintNode_t *GetHintNode(const int);
  virtual bool GetAreaCells(const int, const int, int *, int *);
  virtual bool WorldPosToCellPos(const int, const int, const idVec3 *, int *, int *);
  virtual bool CellPosToWorldPos(const int, const int, const int, const int, idVec3 *, const bool);
  virtual void DrawCoverPoint(const aas2Cover_t *, const int);
  virtual int GetNumTrees();
  virtual idIndex<int,enum invalidAASTree_t> *GetTree(idIndex<int,enum invalidAASTree_t> *result, int);
  virtual idIndex<int,enum invalidAASTree_t> *GetTreeForFloorNormal(idIndex<int,enum invalidAASTree_t> *result, const idVec3 *);
  virtual const idVec3 *GetFloorNormalForArea(int);
  virtual const idVec3 *GetFloorNormalForTree(idIndex<int,enum invalidAASTree_t>);
  virtual int GetNumAreasInTree(idIndex<int,enum invalidAASTree_t>);
  virtual void Shutdown();
  virtual void ShowOptimizedWalkPath(int, const idVec3 *, int, const idVec3 *, int, int);

  idAAS2File *file;
  idStr name;
  bool defaulted;
  idAASRoutingCache ***areaCacheIndex;
  int areaCacheIndexSize;
  idAASRoutingCache **portalCacheIndex;
  int portalCacheIndexSize;
  idRoutingUpdate *areaUpdate;
  idRoutingUpdate *portalUpdate;
  unsigned __int16 *goalAreaTravelTimes;
  unsigned __int16 *areaTravelTimes;
  int numAreaTravelTimes;
  idAASRoutingCache *cacheListStart;
  idAASRoutingCache *cacheListEnd;
  int totalCacheMemory;
  float groundSpeedMultiplier;
  float waterSpeedMultiplier;
  int numObstaclePVSBytes;
  unsigned __int8 *obstaclePVS;
  int obstaclePVSAreaNum;
  idAASClipLink **areaClipModels;
  idBlockAlloc<idAASClipLink,128,37> clipModelLinkAllocator;
  idObstacleAvoidance obstacleAvoidance;
};
