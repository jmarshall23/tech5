#pragma once

#include "gamelib/aas2/aas2.h"
#include "gamelib/aas2/obstacleavoidance.h"
#include "idlib/blockalloc_base.h"
#include "idlib/text/str.h"

class idRenderWorld;
struct idObstacleBuffers;

class idAASRoutingCache {
public:
    explicit idAASRoutingCache(int cacheSize);
    ~idAASRoutingCache();

    int type;
    int size;
    int cluster;
    int areaNum;
    int travelFlags;
    idAASRoutingCache* next;
    idAASRoutingCache* prev;
    idAASRoutingCache* time_next;
    idAASRoutingCache* time_prev;
    std::uint16_t startTravelTime;
    std::uint8_t* reachabilities;
    std::uint16_t* travelTimes;
};

struct idRoutingUpdate {
    int cluster;
    int areaNum;
    std::uint16_t tmpTravelTime;
    std::uint16_t* areaTravelTimes;
    idVec3 start;
    idRoutingUpdate* next;
    idRoutingUpdate* prev;
    bool isInList;
};

class idAASClipLink {
public:
    idAASClipLink* prevArea;
    idAASClipLink* nextArea;
    idAASClipLink* prevClip;
    idAASClipLink* nextClip;
    idClipModel* clipModel;
    int areaNum;
};

class idAAS2Local final : public idAAS2 {
public:
    idAAS2Local();
    ~idAAS2Local() override;

    bool IsDefault() const override { return defaulted; }
    bool Init(const char* mapName, unsigned int mapFileCRC) override;
    void Shutdown();
    void Stats() const override;
    void Test(const idVec3& origin, const idVec3& destination,
        const idMat3& axis, int areaNum, int travelFlags, int contentMask,
        int debugMode, int treeNum, idClip* clip, usercmd_t* command,
        idAngles& viewAngles) override;
    const idAAS2Settings* GetSettings() const override;
    idBounds DefaultSearchBounds() const override;
    int PointAreaNum(idIndex<int, invalidAASTree_t> tree,
        const idVec3& origin) const override;
    int PointReachableAreaNum(idIndex<int, invalidAASTree_t> tree,
        const idVec3& origin, const idBounds& searchBounds, int areaFlags,
        int excludeTravelFlags) const override;
    int BoundsReachableAreaNum(idIndex<int, invalidAASTree_t> tree,
        const idBounds& bounds, int areaFlags,
        int excludeTravelFlags) const override;
    int BoundsReachableAreaNum(idIndex<int, invalidAASTree_t> tree,
        const idVec3& origin, const idBounds& bounds, int areaFlags,
        int excludeTravelFlags) const override;
    bool NearestPointReachable(idIndex<int, invalidAASTree_t> tree,
        const idVec3& origin, int areaNum, const idVec3& destination,
        const idBounds& searchBounds, int travelFlags,
        idAAS2NearestReachable& nearest) const override;
    void PushPointIntoAreaNum(int areaNum, idVec3& origin) const override;
    idVec3 AreaCenter(int areaNum) const override;
    bool Trace(idIndex<int, invalidAASTree_t> tree, aas2Trace_t& trace,
        const idVec3& start, const idVec3& end) const override;
    bool TraceHeight(idIndex<int, invalidAASTree_t> tree,
        aas2TraceHeight_t& trace, const idVec3& start,
        const idVec3& end) const override;
    bool TraceFloor(aas2TraceFloor_t& trace, const idVec3& start,
        int startAreaNum, const idVec3& end, int travelFlags,
        bool allowFloorNormalChange, bool ignoreGravityDirectionDistance,
        bool ignoreSameArea) const override;
    void GetEdgeVertexNumbers(int edgeNum, int verts[2]) const override;
    void GetEdge(int edgeNum, idVec3& start, idVec3& end) const override;
    int GetEdgeFlags(int edgeNum) const override;
    int GetAreaFlags(int areaNum) const override;
    bool ChangeAreaTravelFlags(const idBounds& bounds, int treeNum,
        int travelFlags, bool set) override;
    bool ChangeReachabilityTravelFlags(const char* name,
        int travelFlags, bool set) override;
    bool ChangeReachabilityTravelFlags(
        idIndex<short, invalidReachability_t> reachability,
        int travelFlags, bool set) override;
    int TravelTimeToGoalArea(int areaNum, const idVec3& origin,
        int goalAreaNum, const idVec3& goalOrigin, int travelFlags,
        const idAAS2TravelSpeeds* speeds) override;
    bool RouteToGoalArea(int areaNum, const idVec3& origin,
        int goalAreaNum, const idVec3& goalOrigin, int travelFlags,
        int& travelTime,
        idIndex<short, invalidReachability_t>& reachability) override;
    bool FindNearestGoal(idAAS2Goal& goal, int areaNum,
        const idVec3& origin, int travelFlags,
        idAAS2Callback& callback) override;
    bool WalkPathToGoal(idAAS2Path& path, int areaNum,
        const idVec3& origin, int goalAreaNum, const idVec3& goalOrigin,
        int travelFlags, int obstacleFlags) override;
    bool ExtendHopPathToGoal(idAAS2Path& path, int areaNum,
        const idVec3& origin, int goalAreaNum, const idVec3& goalOrigin,
        int travelFlags, int obstacleFlags,
        const idAAS2HopPathParms& parms) override;
    void ShowWalkPath(int areaNum, const idVec3& origin, int goalAreaNum,
        const idVec3& goalOrigin, int travelFlags, int obstacleFlags,
        int contentMask, int debugFlags, int treeNum) const override;
    void ShowHopPath(int areaNum, const idVec3& origin, int goalAreaNum,
        const idVec3& goalOrigin, int travelFlags, int obstacleFlags,
        const idAAS2HopPathParms& parms) const override;
    void ShowOptimizedWalkPath(int areaNum, const idVec3& origin,
        int goalAreaNum, const idVec3& goalOrigin, int travelFlags,
        int obstacleFlags) const;
    void DrawEdge(int edgeNum, bool arrow, bool text,
        bool highlight) const override;
    void DrawReachability(idIndex<short, invalidReachability_t> reachability,
        const aas2Reachability_t& reach, const char* label) const override;
    void DrawArea(int areaNum, bool showNumbers, bool showEdges,
        bool showReachabilities, bool showFloor, bool showBounds,
        bool highlight) const override;
    float GetGroundSpeedMultiplier() const override {
        return groundSpeedMultiplier;
    }
    bool GetOptimizedWalkPath(int areaNum, const idVec3& origin,
        int goalAreaNum, const idVec3& goalOrigin, int travelFlags,
        int obstacleFlags, idList<idVec3, 5>& points) override;
    int GetNumAreas() const override;
    const idPlane* GetPlane(int index) const override;
    const aas2Area_t* GetArea(int areaNum) const override;
    const aas2Reachability_t* GetReachability(
        idIndex<short, invalidReachability_t> reachability) const override;
    bool GetPath(const idVec3& origin, const idVec3& goalOrigin,
        int areaNum, int goalAreaNum, int travelFlags,
        idAAS2PathPoint* points, int maxPoints, int& numPoints) override;
    void ClipGridToAreas(const idVec3& startOrigin, int startAreaNum,
        int travelFlags, unsigned int cellSize, int dimension,
        std::uint8_t* reachable) const override;
    int GetInvalidTravelFlags() const override { return AAS_TFL_INVALID; }
    int GetTraversalsForReachability(
        idIndex<short, invalidReachability_t> reachability,
        idList<int, 5>& traversals) const override;
    int GetTraversalsForInteractableEntity(
        idIndex<short, invalidAASInteractionEntIndex_t> entity,
        idList<int, 5>& traversals) const override;
    int FindBestTraversalForReachability(
        idIndex<short, invalidReachability_t> reachability,
        const idVec3& origin, const idVec3& goalOrigin,
        idVec3& traversalStart, idVec3& traversalEnd,
        idIndex<short, invalidAASDependencyIndex_t>& dependency,
        int travelFlags, bool allowDisabled) const override;
    const aas2Traversal_t* GetTraversal(int traversalNum) const override;
    bool GetAASAnim(idIndex<short, invalidAASAnimIndex_t> index,
        const aas2AnimName_t** name) const override;
    idIndex<short, invalidAASAnimIndex_t> GetAASAnimIndexByName(
        const char* name) const override;
    bool GetAASDependency(idIndex<short, invalidAASDependencyIndex_t> index,
        const aas2DependencyName_t** name) const override;
    idIndex<short, invalidAASDependencyIndex_t>
        GetAASDependencyIndexByName(const char* name) const override;
    bool GetAASInteractionEntity(
        idIndex<short, invalidAASInteractionEntIndex_t> index,
        const aas2InteractionEntityName_t** name) const override;
    idIndex<short, invalidAASInteractionEntIndex_t>
        GetAASInteractionEntityIndexByName(const char* name) const override;
    bool GetAASTraversalNameIndex(
        idIndex<short, invalidAASTraversalNameIndex_t> index,
        const aas2TraversalEntityName_t** name) const override;
    idIndex<short, invalidAASTraversalNameIndex_t>
        GetAASTraversalNameIndexByName(const char* name) const override;
    int GetAASTraversalIndexByNameIndex(
        idIndex<short, invalidAASTraversalNameIndex_t> index) const override;
    bool SetTraversalFlag(int index, int flags) override;
    bool ClearTraversalFlag(int index, int flags) override;
    const std::uint8_t* GetObstaclePVS(int areaNum) override;
    int GetObstaclePVSWallEdges(int areaNum, int edgeFlags,
        int* outputEdges, int maxEdges) const override;
    int GetObstaclePVSClipModels(int areaNum, idClipModel** models,
        int maxModels) override;
    void GetObstaclePVSObstacles(int areaNum, int obstacleFlags,
        obstacleVertex_t* vertices, int* numVertices,
        obstacleEdge_t* edges, int* numEdges, idClipModel** models,
        int* numModels, obstacleRoute_t* route) override;
    void FreeClipLinks() override;
    idAASClipLink* LinkClipModel(idClipModel* model) override;
    idAASClipLink* UnLinkClipModel(idAASClipLink* link) override;
    int GetNumCoverPoints() const override;
    const aas2Cover_t* GetCoverPoint(int index) const override;
    int GetNumAreaCoverPoints(int areaNum) const override;
    int GetAreaCoverPoints(int areaNum, int* points, int maxPoints,
        int* flags) const override;
    int FindCoverPoints(int areaNum, const idVec3& origin, float radius,
        int coverFlags, int excludeFlags, int maxPoints, int* points,
        int team, int* areaFlags) const override;
    int GetNumChokePoints() const override;
    const aas2ChokePoint_t* GetChokePoint(int index) const override;
    int GetNumHintNodes() const override;
    const aas2HintNode_t* GetHintNode(int index) const override;
    bool GetAreaCells(int areaNum, int subdivisionSize, int* xCells,
        int* yCells) const override;
    bool WorldPosToCellPos(int areaNum, int subdivisionSize,
        const idVec3& worldPos, int* xCell, int* yCell) const override;
    bool CellPosToWorldPos(int areaNum, int subdivisionSize, int xCell,
        int yCell, idVec3& worldPos, bool center) const override;
    void DrawCoverPoint(const aas2Cover_t& cover, int index) const override;
    int GetNumTrees() const override;
    idIndex<int, invalidAASTree_t> GetTree(int index) const override;
    idIndex<int, invalidAASTree_t> GetTreeForFloorNormal(
        const idVec3& floorNormal) const override;
    const idVec3* GetFloorNormalForArea(int areaNum) const override;
    const idVec3* GetFloorNormalForTree(
        idIndex<int, invalidAASTree_t> tree) const override;
    int GetNumAreasInTree(
        idIndex<int, invalidAASTree_t> tree) const override;

    void SetupRouting();
    void ShutdownRouting();
    void RoutingStats() const;
    void RemoveRoutingCacheUsingArea(int areaNum);
    void LinkCache(idAASRoutingCache* cache);
    void UnlinkCache(idAASRoutingCache* cache);
    int CalcTravelTime(const idVec3& start, const idVec3& end,
        int travelFlags) const;
    int AreaTravelTime(int areaNum, const idVec3& start,
        const idVec3& end) const;
    void CalculateAreaTravelTimes();
    void SetupRoutingCache();
    void DeleteClusterCache(int clusterNum);
    void DeletePortalCache();
    void ShutdownRoutingCache();
    bool ChangeAreaTravelFlags_r(int nodeNum, const idBounds& bounds,
        int areaFlags, int travelFlags, bool set);
    idIndex<short, invalidReachability_t> GetAreaReachability(
        int areaNum, int reachabilityNum) const;
    int ClusterAreaNum(int clusterNum, int areaNum) const;
    void DeleteOldestCache();
    void UpdateAreaRoutingCache(idAASRoutingCache* cache);
    idAASRoutingCache* GetAreaRoutingCache(int clusterNum, int areaNum,
        int travelFlags);
    void UpdatePortalRoutingCache(idAASRoutingCache* cache);
    idAASRoutingCache* GetPortalRoutingCache(int clusterNum, int areaNum,
        int travelFlags);
    bool GetClusterRoute(int startAreaNum, const idVec3& startOrigin,
        int startClusterNum, int goalAreaNum, int travelFlags,
        int& travelTime,
        idIndex<short, invalidReachability_t>& bestReachability);
    bool HopPathIsValid(int startAreaNum, const idVec3& startOrigin,
        int goalAreaNum, const idVec3& goalOrigin,
        const idAAS2HopPathParms& parms) const;
    bool WalkPathIsValid(int startAreaNum, const idVec3& startOrigin,
        int goalAreaNum, const idVec3& goalOrigin, int travelFlags,
        int& endAreaNum, aas2EdgeCrossed_t& firstEdge) const;
    void SubSampleWalkPath(int startAreaNum, const idVec3& startOrigin,
        int pathAreaNum, const idVec3& pathStart, const idVec3& pathEnd,
        int travelFlags, idVec3& endPos, int& endAreaNum,
        aas2EdgeCrossed_t& firstEdge) const;
    void SetupObstaclePVS();
    void ShutdownObstaclePVS();
    void DecompressObstaclePVS(int areaNum, std::uint8_t* pvs,
        int pvsSize) const;
    void GetObstaclePVSObstaclesInternal(int areaNum, int edgeFlags,
        obstacleVertex_t* vertices, int& numVertices,
        obstacleEdge_t* edges, int& numEdges, idClipModel** models,
        int& numModels, obstacleRoute_t* route) const;
    void FindCoverPoints_Internal(int startAreaNum, const idVec3& origin,
        const idBounds& bounds, float maxDistSqr, int requiredFlags,
        int excludeFlags, int travelFlags, int* coverPoints, int maxCover,
        int& numCover) const;

    idAAS2File* file;
    idStr name;
    bool defaulted;
    idAASRoutingCache*** areaCacheIndex;
    int areaCacheIndexSize;
    idAASRoutingCache** portalCacheIndex;
    int portalCacheIndexSize;
    idRoutingUpdate* areaUpdate;
    idRoutingUpdate* portalUpdate;
    std::uint16_t* goalAreaTravelTimes;
    std::uint16_t* areaTravelTimes;
    int numAreaTravelTimes;
    idAASRoutingCache* cacheListStart;
    idAASRoutingCache* cacheListEnd;
    int totalCacheMemory;
    float groundSpeedMultiplier;
    float waterSpeedMultiplier;
    int numObstaclePVSBytes;
    std::uint8_t* obstaclePVS;
    int obstaclePVSAreaNum;
    idAASClipLink** areaClipModels;
    idBlockAlloc<idAASClipLink, 128, 37> clipModelLinkAllocator;
    idObstacleAvoidance obstacleAvoidance;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idAASClipLink) == 24,
    "Recovered idAASClipLink ABI changed");
static_assert(sizeof(idAAS2Local) == 172,
    "Recovered idAAS2Local ABI changed");
#endif
