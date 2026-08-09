#pragma once

#include "aas2file/aas2file.h"
#include "gamelib/aas2/obstacleavoidancecore.h"
#include "idlib/bv/bounds.h"
#include "idlib/callback.h"
#include "idlib/containers/list.h"
#include "idlib/index.h"
#include "idlib/math/angles.h"
#include "idlib/math/plane.h"

#include <cstdint>

class idClip;
class idClipModel;
class idAASClipLink;
struct usercmd_t;
struct obstacleVertex_t;
struct obstacleEdge_t;

struct idAAS2NearestReachable {
    int nearestDestArea;
    idVec3 nearestDestPos;
    int nearestTravelTime;
    int quickestDestArea;
    idVec3 quickestDestPos;
    int quickestTravelTime;
};

struct idAAS2TravelSpeeds {
    float defaultSpeed;
    float swimSpeed;
    float flySpeed;
    float crouchSpeed;
};

struct idAAS2Goal {
    int areaNum;
    idVec3 origin;
};

struct idAAS2HopPathParms {
    float maxDistance;
    float maxHeight;
    float minHeight;
    float maxSlope;
};

struct idAAS2PathPoint {
    int areaNum;
    idVec3 origin;
    idIndex<short, invalidReachability_t> nextReachIndex;
    int travelTime;
};

struct idAAS2Path {
    int type;
    idVec3 moveGoal;
    int moveAreaNum;
    aas2EdgeCrossed_t firstEdge;
    idIndex<short, invalidReachability_t> reachIndex;
    int travelTime;
    int traversalIndex;
    idVec3 traversalStart;
    idVec3 traversalEnd;
    idIndex<short, invalidAASDependencyIndex_t> dependencyIndex;
    idVec3 obstacleGoal;
    int obstacleAreaNum;
    float pathMaxHeight;
    obstacleRoute_t obstacleRoute;

    idAAS2Path()
        : type(10), moveGoal(), moveAreaNum(0), firstEdge{}, reachIndex(),
          travelTime(-1), traversalIndex(-1), traversalStart(), traversalEnd(),
          dependencyIndex(), obstacleGoal(), obstacleAreaNum(0),
          pathMaxHeight(0.0f), obstacleRoute() {
    }
};

class idAAS2 {
public:
    virtual ~idAAS2();

    static idAAS2* Alloc();

    virtual bool IsDefault() const = 0;
    virtual bool Init(const char* mapName, unsigned int mapFileCRC) = 0;
    virtual void Stats() const = 0;
    virtual void Test(const idVec3& origin, const idVec3& destination,
        const idMat3& axis, int areaNum, int travelFlags, int contentMask,
        int debugMode, int treeNum, idClip* clip, usercmd_t* command,
        idAngles& viewAngles) = 0;
    virtual const idAAS2Settings* GetSettings() const = 0;
    virtual idBounds DefaultSearchBounds() const = 0;
    virtual int PointAreaNum(idIndex<int, invalidAASTree_t> tree,
        const idVec3& origin) const = 0;
    virtual int PointReachableAreaNum(idIndex<int, invalidAASTree_t> tree,
        const idVec3& origin, const idBounds& searchBounds, int areaFlags,
        int excludeTravelFlags) const = 0;
    virtual int BoundsReachableAreaNum(idIndex<int, invalidAASTree_t> tree,
        const idBounds& bounds, int areaFlags, int excludeTravelFlags) const = 0;
    virtual int BoundsReachableAreaNum(idIndex<int, invalidAASTree_t> tree,
        const idVec3& origin, const idBounds& bounds, int areaFlags,
        int excludeTravelFlags) const = 0;
    virtual bool NearestPointReachable(idIndex<int, invalidAASTree_t> tree,
        const idVec3& origin, int areaNum, const idVec3& destination,
        const idBounds& searchBounds, int travelFlags,
        idAAS2NearestReachable& nearest) const = 0;
    virtual void PushPointIntoAreaNum(int areaNum, idVec3& origin) const = 0;
    virtual idVec3 AreaCenter(int areaNum) const = 0;
    virtual bool Trace(idIndex<int, invalidAASTree_t> tree, aas2Trace_t& trace,
        const idVec3& start, const idVec3& end) const = 0;
    virtual bool TraceHeight(idIndex<int, invalidAASTree_t> tree,
        aas2TraceHeight_t& trace, const idVec3& start,
        const idVec3& end) const = 0;
    virtual bool TraceFloor(aas2TraceFloor_t& trace, const idVec3& start,
        int startAreaNum, const idVec3& end, int travelFlags,
        bool allowFloorNormalChange, bool ignoreGravityDirectionDistance,
        bool ignoreSameArea) const = 0;
    virtual void GetEdgeVertexNumbers(int edgeNum, int verts[2]) const = 0;
    virtual void GetEdge(int edgeNum, idVec3& start, idVec3& end) const = 0;
    virtual int GetEdgeFlags(int edgeNum) const = 0;
    virtual int GetAreaFlags(int areaNum) const = 0;
    virtual bool ChangeAreaTravelFlags(const idBounds& bounds, int treeNum,
        int travelFlags, bool set) = 0;
    virtual bool ChangeReachabilityTravelFlags(const char* name,
        int travelFlags, bool set) = 0;
    virtual bool ChangeReachabilityTravelFlags(
        idIndex<short, invalidReachability_t> reachability,
        int travelFlags, bool set) = 0;
    virtual int TravelTimeToGoalArea(int areaNum, const idVec3& origin,
        int goalAreaNum, const idVec3& goalOrigin, int travelFlags,
        const idAAS2TravelSpeeds* speeds = nullptr) = 0;
    virtual bool RouteToGoalArea(int areaNum, const idVec3& origin,
        int goalAreaNum, const idVec3& goalOrigin, int travelFlags,
        int& travelTime,
        idIndex<short, invalidReachability_t>& reachability) = 0;
    virtual bool FindNearestGoal(idAAS2Goal& goal, int areaNum,
        const idVec3& origin, int travelFlags, idAAS2Callback& callback) = 0;
    virtual bool WalkPathToGoal(idAAS2Path& path, int areaNum,
        const idVec3& origin, int goalAreaNum, const idVec3& goalOrigin,
        int travelFlags, int obstacleFlags) = 0;
    virtual bool ExtendHopPathToGoal(idAAS2Path& path, int areaNum,
        const idVec3& origin, int goalAreaNum, const idVec3& goalOrigin,
        int travelFlags, int obstacleFlags,
        const idAAS2HopPathParms& parms) = 0;
    virtual void ShowWalkPath(int areaNum, const idVec3& origin,
        int goalAreaNum, const idVec3& goalOrigin, int travelFlags,
        int obstacleFlags, int contentMask, int debugFlags,
        int treeNum) const = 0;
    virtual void ShowHopPath(int areaNum, const idVec3& origin,
        int goalAreaNum, const idVec3& goalOrigin, int travelFlags,
        int obstacleFlags, const idAAS2HopPathParms& parms) const = 0;
    virtual void DrawEdge(int edgeNum, bool arrow, bool text,
        bool highlight) const = 0;
    virtual void DrawReachability(
        idIndex<short, invalidReachability_t> reachability,
        const aas2Reachability_t& reach, const char* label) const = 0;
    virtual void DrawArea(int areaNum, bool showNumbers, bool showEdges,
        bool showReachabilities, bool showFloor, bool showBounds,
        bool highlight) const = 0;
    virtual float GetGroundSpeedMultiplier() const = 0;
    virtual bool GetOptimizedWalkPath(int areaNum, const idVec3& origin,
        int goalAreaNum, const idVec3& goalOrigin, int travelFlags,
        int obstacleFlags, idList<idVec3, 5>& points) = 0;
    virtual int GetNumAreas() const = 0;
    virtual const idPlane* GetPlane(int index) const = 0;
    virtual const aas2Area_t* GetArea(int areaNum) const = 0;
    virtual const aas2Reachability_t* GetReachability(
        idIndex<short, invalidReachability_t> reachability) const = 0;
    virtual bool GetPath(const idVec3& origin, const idVec3& goalOrigin,
        int areaNum, int goalAreaNum, int travelFlags,
        idAAS2PathPoint* points, int maxPoints, int& numPoints) = 0;
    virtual void ClipGridToAreas(const idVec3& startOrigin, int startAreaNum,
        int travelFlags, unsigned int cellSize, int dimension,
        std::uint8_t* reachable) const = 0;
    virtual int GetInvalidTravelFlags() const = 0;
    virtual int GetTraversalsForReachability(
        idIndex<short, invalidReachability_t> reachability,
        idList<int, 5>& traversals) const = 0;
    virtual int GetTraversalsForInteractableEntity(
        idIndex<short, invalidAASInteractionEntIndex_t> entity,
        idList<int, 5>& traversals) const = 0;
    virtual int FindBestTraversalForReachability(
        idIndex<short, invalidReachability_t> reachability,
        const idVec3& origin, const idVec3& goalOrigin,
        idVec3& traversalStart, idVec3& traversalEnd,
        idIndex<short, invalidAASDependencyIndex_t>& dependency,
        int travelFlags, bool allowDisabled) const = 0;
    virtual const aas2Traversal_t* GetTraversal(int traversalNum) const = 0;
    virtual bool GetAASAnim(idIndex<short, invalidAASAnimIndex_t> index,
        const aas2AnimName_t** name) const = 0;
    virtual idIndex<short, invalidAASAnimIndex_t> GetAASAnimIndexByName(
        const char* name) const = 0;
    virtual bool GetAASDependency(
        idIndex<short, invalidAASDependencyIndex_t> index,
        const aas2DependencyName_t** name) const = 0;
    virtual idIndex<short, invalidAASDependencyIndex_t>
        GetAASDependencyIndexByName(const char* name) const = 0;
    virtual bool GetAASInteractionEntity(
        idIndex<short, invalidAASInteractionEntIndex_t> index,
        const aas2InteractionEntityName_t** name) const = 0;
    virtual idIndex<short, invalidAASInteractionEntIndex_t>
        GetAASInteractionEntityIndexByName(const char* name) const = 0;
    virtual bool GetAASTraversalNameIndex(
        idIndex<short, invalidAASTraversalNameIndex_t> index,
        const aas2TraversalEntityName_t** name) const = 0;
    virtual idIndex<short, invalidAASTraversalNameIndex_t>
        GetAASTraversalNameIndexByName(const char* name) const = 0;
    virtual int GetAASTraversalIndexByNameIndex(
        idIndex<short, invalidAASTraversalNameIndex_t> index) const = 0;
    virtual bool SetTraversalFlag(int index, int flags) = 0;
    virtual bool ClearTraversalFlag(int index, int flags) = 0;
    virtual const std::uint8_t* GetObstaclePVS(int areaNum) = 0;
    virtual int GetObstaclePVSWallEdges(int areaNum, int edgeFlags,
        int* outputEdges, int maxEdges) const = 0;
    virtual int GetObstaclePVSClipModels(int areaNum,
        idClipModel** models, int maxModels) = 0;
    virtual void GetObstaclePVSObstacles(int areaNum, int obstacleFlags,
        obstacleVertex_t* vertices, int* numVertices,
        obstacleEdge_t* edges, int* numEdges, idClipModel** models,
        int* numModels, obstacleRoute_t* route) = 0;
    virtual void FreeClipLinks() = 0;
    virtual idAASClipLink* LinkClipModel(idClipModel* model) = 0;
    virtual idAASClipLink* UnLinkClipModel(idAASClipLink* link) = 0;
    virtual int GetNumCoverPoints() const = 0;
    virtual const aas2Cover_t* GetCoverPoint(int index) const = 0;
    virtual int GetNumAreaCoverPoints(int areaNum) const = 0;
    virtual int GetAreaCoverPoints(int areaNum, int* points, int maxPoints,
        int* flags) const = 0;
    virtual int FindCoverPoints(int areaNum, const idVec3& origin,
        float radius, int coverFlags, int excludeFlags, int maxPoints,
        int* points, int team, int* areaFlags) const = 0;
    virtual int GetNumChokePoints() const = 0;
    virtual const aas2ChokePoint_t* GetChokePoint(int index) const = 0;
    virtual int GetNumHintNodes() const = 0;
    virtual const aas2HintNode_t* GetHintNode(int index) const = 0;
    virtual bool GetAreaCells(int areaNum, int subdivisionSize,
        int* xCells, int* yCells) const = 0;
    virtual bool WorldPosToCellPos(int areaNum, int subdivisionSize,
        const idVec3& worldPos, int* xCell, int* yCell) const = 0;
    virtual bool CellPosToWorldPos(int areaNum, int subdivisionSize,
        int xCell, int yCell, idVec3& worldPos, bool center) const = 0;
    virtual void DrawCoverPoint(const aas2Cover_t& cover, int index) const = 0;
    virtual int GetNumTrees() const = 0;
    virtual idIndex<int, invalidAASTree_t> GetTree(int index) const = 0;
    virtual idIndex<int, invalidAASTree_t> GetTreeForFloorNormal(
        const idVec3& floorNormal) const = 0;
    virtual const idVec3* GetFloorNormalForArea(int areaNum) const = 0;
    virtual const idVec3* GetFloorNormalForTree(
        idIndex<int, invalidAASTree_t> tree) const = 0;
    virtual int GetNumAreasInTree(
        idIndex<int, invalidAASTree_t> tree) const = 0;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idAAS2NearestReachable) == 40,
    "Recovered idAAS2NearestReachable ABI changed");
static_assert(sizeof(idAAS2TravelSpeeds) == 16,
    "Recovered idAAS2TravelSpeeds ABI changed");
static_assert(sizeof(idAAS2Goal) == 16,
    "Recovered idAAS2Goal ABI changed");
static_assert(sizeof(idAAS2PathPoint) == 24,
    "Recovered idAAS2PathPoint ABI changed");
static_assert(sizeof(idAAS2HopPathParms) == 16,
    "Recovered idAAS2HopPathParms ABI changed");
static_assert(sizeof(idAAS2Path) == 436,
    "Recovered idAAS2Path ABI changed");
#endif
