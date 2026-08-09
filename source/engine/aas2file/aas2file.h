#pragma once

#include "aas2file/aastraversalchaindata.h"
#include "framework/resource.h"
#include "idlib/bv/bounds.h"
#include "idlib/containers/list.h"
#include "idlib/math/plane.h"
#include "idlib/text/str.h"

#include <cstdint>

class idFile;
class idLexer;
template<class resourceType> class idTypedResourceList;

enum aas2TravelFlag_t : int {
    AAS_TFL_INVALID = 0x1,
    AAS_TFL_INVALID_TEAM1 = 0x2,
    AAS_TFL_INVALID_TEAM2 = 0x4,
    AAS_TFL_AIR = 0x8,
    AAS_TFL_WATER = 0x10,
    AAS_TFL_WALK = 0x20,
    AAS_TFL_WALKOFFLEDGE = 0x40,
    AAS_TFL_WALKOFFBARRIER = 0x80,
    AAS_TFL_BARRIERJUMP = 0x100,
    AAS_TFL_JUMP = 0x200,
    AAS_TFL_LADDER = 0x400,
    AAS_TFL_SWIM = 0x800,
    AAS_TFL_TELEPORT = 0x1000,
    AAS_TFL_ELEVATOR = 0x2000,
    AAS_TFL_CROUCH = 0x4000,
    AAS_TFL_LEAP = 0x8000,
    AAS_TFL_TRAVERSAL_CLASS_A = 0x10000,
    AAS_TFL_TRAVERSAL_CLASS_B = 0x20000,
    AAS_TFL_TRAVERSAL_CLASS_C = 0x40000,
    AAS_TFL_TRAVERSAL_EVASION = 0x80000,
    AAS_TFL_CLIMB = 0x100000,
    AAS_TFL_FLY = 0x200000,
    AAS_TFL_TRAVERSAL_EMERGENCY = 0x400000,
    AAS_TFL_TRAVERSAL_CLASS_D = 0x800000,
    AAS_TFL_TRAVERSAL_CLASS_E = 0x1000000,
    AAS_TFL_TRAVERSAL_COMBAT = 0x2000000,
    AAS_TFL_BLOCK_PLAYER = 0x4000000,
    AAS_TFL_MELEE = 0x8000000,
    AAS_TFL_MAX = 0x8000001,
    AAS_TFL_VALID_TEAM1 = static_cast<int>(0xFFFFFFFCu),
    AAS_TFL_VALID_TEAM2 = static_cast<int>(0xFFFFFFFAu),
    AAS_TFL_VALID_BOTH_TEAMS = static_cast<int>(0xFFFFFFFEu),
    AAS_TFL_VALID_WALK_TEAM1 = 0x3C,
    AAS_TFL_VALID_WALK_TEAM2 = 0x3A,
    AAS_TFL_VALID_WALK_BOTH_TEAMS = 0x3E,
    AAS_TFL_TRAVERSAL_ANY_CLASS = 0x1870000
};

enum aas2AreaFlag_t : int {
    AAS_AREA_LEDGE = 0x1,
    AAS_AREA_REACHABLE_WALK = 0x2,
    AAS_AREA_OUTSIDE = 0x4,
    AAS_AREA_HIGH_CEILING = 0x8,
    AAS_AREA_NOPUSH = 0x10,
    AAS_AREA_CONTENTS_SOLID = 0x100,
    AAS_AREA_CONTENTS_WATER = 0x200,
    AAS_AREA_CONTENTS_CLUSTERPORTAL = 0x400,
    AAS_AREA_CONTENTS_OBSTACLE = 0x800,
    AAS_AREA_FAKE = 0x1000,
    AAS_AREA_CONTENTS_FLY = 0x2000,
    AAS_AREA_FLOOD_VISITED = 0x8000,
    AAS_AREA_MAX = 0x8001
};

enum aas2EdgeFlag_t : int {
    AAS_EDGE_WALL = 0x1,
    AAS_EDGE_LEDGE = 0x2,
    AAS_EDGE_WALL_CORNER = 0x4,
    AAS_EDGE_LEDGE_CORNER = 0x8,
    AAS_EDGE_STEP_TOP = 0x10,
    AAS_EDGE_STEP_BOTTOM = 0x20,
    AAS_EDGE_VERTICAL = 0x40,
    AAS_EDGE_WATER = 0x80,
    AAS_EDGE_LADDER = 0x100,
    AAS_EDGE_STEP_SIDE = 0x200,
    AAS_EDGE_WALL_CORNER_V0 = 0x400,
    AAS_EDGE_WALL_CORNER_V1 = 0x800,
    AAS_EDGE_FAKE = 0x1000,
    AAS_EDGE_MAX = 0x1001
};

enum aas2CoverFlag_t : int {
    AAS_COVERFLAG_CROUCH = 0x1,
    AAS_COVERFLAG_LEANLEFT = 0x2,
    AAS_COVERFLAG_LEANRIGHT = 0x4,
    AAS_COVERFLAG_STEPLEFT = 0x8,
    AAS_COVERFLAG_STEPRIGHT = 0x10,
    AAS_COVERFLAG_FIREOVER = 0x20,
    AAS_COVERFLAG_FIRELEANLEFT = 0x40,
    AAS_COVERFLAG_FIRELEANRIGHT = 0x80,
    AAS_COVERFLAG_FIRESTEPLEFT = 0x100,
    AAS_COVERFLAG_FIRESTEPRIGHT = 0x200,
    AAS_COVERFLAG_EXPOSED = 0x400,
    AAS_COVERFLAG_EXPLICIT = 0x800,
    AAS_COVERFLAG_FORCE = 0x1000,
    AAS_COVERFLAG_INVALID = 0x2000,
    AAS_COVERFLAG_TRANSITION_APPROACH_FORWARD = 0x4000,
    AAS_COVERFLAG_TRANSITION_APPROACH_LEFT = 0x8000,
    AAS_COVERFLAG_TRANSITION_APPROACH_TURN_AROUND_LEFT = 0x10000,
    AAS_COVERFLAG_TRANSITION_APPROACH_WRAP_AROUND_LEFT = 0x20000,
    AAS_COVERFLAG_TRANSITION_APPROACH_RIGHT = 0x40000,
    AAS_COVERFLAG_TRANSITION_APPROACH_TURN_AROUND_RIGHT = 0x80000,
    AAS_COVERFLAG_TRANSITION_APPROACH_WRAP_AROUND_RIGHT = 0x100000,
    AAS_COVERFLAG_TRANSITION_APPROACH_JUMPOVER = 0x200000,
    AAS_COVERFLAG_AVOID = 0x400000,
    AAS_COVERFLAG_TRANSITION_ALL = 0x3FC000
};

class idAAS2Settings {
public:
    enum type_t : int { AAS_PLAYER = 0, AAS_MONSTER = 1, AAS_VEHICLE = 2, AAS_MAX = 3 };
    enum aasPrimitiveMode_t : int {
        AAS_PRIMITIVE_MODE_DEFAULT = 0,
        AAS_PRIMITIVE_MODE_NEVER = 1,
        AAS_PRIMITIVE_MODE_ALWAYS = 2
    };

    idAAS2Settings();
    bool ParseInt(idLexer& source, int& value);
    bool ParseFloat(idLexer& source, float& value);
    bool ParseVector(idLexer& source, idVec3& vector);
    bool ParseBounds(idLexer& source, idBounds& bounds);
    bool ValidForBounds(const idBounds& bounds) const;
    bool ReadFromFile(idLexer& source);
    bool WriteToFileBinary(idFile& file) const;
    bool ReadFromFileBinary(idFile& file);

    type_t type;
    idStr fileExtensionAAS;
    idStr groupName;
    idStr explicitGroupName;
    idBounds boundingBox;
    int primitiveModeBrush;
    int primitiveModePatch;
    int primitiveModeModel;
    idVec3 gravityDir;
    float gravityValue;
    float maxStepHeight;
    float maxBarrierHeight;
    float maxWaterJumpHeight;
    float maxFallHeight;
    float minFloorCos;
    float minHighCeiling;
    float groundSpeed;
    float waterSpeed;
    float ladderSpeed;
    float wallCornerEdgeRadius;
    float ledgeCornerEdgeRadius;
    float obstaclePVSRadius;
    float wallCornerReachabilityBackoff;
    float highQualityReachabilityBackoff;
    float minCrouchingCoverHeight;
    float minStandingCoverHeight;
    float crouchingFireHeight;
    float standingFireHeight;
    float minWallWidth;
    float maxWallWidth;
    float minDoorWidth;
    float maxDoorWidth;
    float coverCornerDistance;
    float coverWallDistance;
    float chokePointWidth;
    int tt_barrierJump;
    int tt_waterJump;
    int tt_startWalkOffLedge;
    int tt_startLadderClimb;
};

struct aas2Edge_t { int vertexNum[2]; int flags; };
struct aas2Node_t { std::uint32_t planeNum; std::uint32_t flags; int children[2]; };
struct aas2Portal_t {
    std::uint16_t areaNum;
    std::int16_t clusters[2];
    std::uint16_t clusterAreaNum[2];
    std::uint16_t maxAreaTravelTime;
};
struct aas2Cluster_t { int numAreas; int numReachableAreas; int numPortals; int firstPortal; };
struct aas2Name_t { char name[128]; int index; };
struct aas2AnimName_t { char name[128]; };
struct aas2DependencyName_t { char name[128]; };
struct aas2InteractionEntityName_t { char name[128]; };
struct aas2TraversalEntityName_t { char name[128]; };
struct aas2AreaBounds_t { std::int16_t min[3]; std::int16_t max[3]; };

struct aas2Reachability_t {
    std::uint32_t travelFlags;
    std::uint16_t travelTime;
    std::uint16_t fromAreaNum;
    std::uint16_t toAreaNum;
    std::uint16_t padding;
    std::int16_t start[3];
    std::int16_t end[3];
    std::uint32_t areaTTOfsAndNumber;
    idIndex<short, invalidReachability_t> next;
    idIndex<short, invalidReachability_t> rev_next;

    idVec3 Start() const { return idVec3(float(start[0]), float(start[1]), float(start[2])); }
    idVec3 End() const { return idVec3(float(end[0]), float(end[1]), float(end[2])); }
};

struct aas2Area_t {
    std::uint32_t travelFlags;
    std::uint16_t flags;
    std::int16_t numEdges;
    int firstEdge;
    std::int16_t cluster;
    std::uint16_t clusterAreaNum;
    std::uint32_t obstaclePVSOffset;
    idIndex<short, invalidReachability_t> reach;
    idIndex<short, invalidReachability_t> rev_reach;
    std::uint16_t firstChokePoint;
    std::int16_t numChokePoints;
    std::uint16_t firstCover;
    std::uint16_t numCover;
    std::uint16_t firstTraversal;
    std::uint16_t numTraversals;
    std::uint16_t firstHintNode;
    std::uint16_t numHintNodes;

    aas2Area_t();
};

struct aas2Cover_t {
    idVec3 origin;
    idVec3 dir;
    std::int16_t areaNum;
    std::int16_t flags;
    int numTouching;
    int firstTouching;
    float durationSec;
    float minRange;
    float maxRange;
    int reservedBy;
    int usableTime;

    aas2Cover_t();
};

struct aas2ChokePoint_t { idVec3 points[2]; std::uint16_t rooms[2]; };

struct aas2HintNode_t {
    enum hintNodeType_t : int {
        HINT_NODE_TYPE_SEARCH_AUTO = 0,
        HINT_NODE_TYPE_SEARCH_ANIMATION = 1,
        HINT_NODE_TYPE_GRENADE = 2
    };

    idVec3 origin;
    std::int16_t areaNum;
    std::int16_t radius;
    std::uint8_t hintType;
    std::uint8_t orientation;
    std::uint8_t dirFlags;
    std::uint8_t grouping;
    int hintData;

    aas2HintNode_t();
    void GetOrientationVector(idVec3& direction) const;
};

struct aas2Trace_t {
    int flags;
    int travelFlags;
    int maxAreas;
    int getOutOfSolid;
    float fraction;
    idVec3 endpos;
    int planeNum;
    int lastAreaNum;
    int blockingAreaNum;
    int numAreas;
    int* areas;
    idVec3* points;
};
struct aas2TraceHeight_t { int maxPoints; int numPoints; idVec3* points; };
struct aas2EdgeCrossed_t { int toAreaNum; int edgeNum; idVec3 edgePoint; };
struct aas2TraceFloor_t {
    float fraction;
    idVec3 endpos;
    int lastAreaNum;
    aas2EdgeCrossed_t firstEdge;
    aas2EdgeCrossed_t lastEdge;
    int maxAreas;
    int numAreas;
    int maxReachIndices;
    int numReachIndices;
    int* areas;
    idIndex<short, invalidReachability_t>* reachIndices;
};

class idAAS2File : public idResource {
public:
    struct bspTree_t { idVec3 floorNormal; int headNode; int firstArea; int lastArea; };
    struct bestReachableArea_t {
        float bboxHeight;
        float maxEdgeDist;
        int areaFlags;
        int excludeTravelFlags;
        int pointAreaNum;
        float pointAreaFloorDist;
        int boundsAreaNum;
        float boundsAreaFloorDist;
    };
    struct floorEdgeSplitPoint_t { idVec3 point; float dist; int edgeNum; };

    idAAS2File();
    ~idAAS2File() override;
    void LoadResource() override;
    bool ReloadIfStale() override;
    idResourceList* GetResourceList() override;

    void Clear();
    void MakeDefault();
    unsigned int MemorySize() const;
    bool LoadBinary(const char* fileName, const char* binaryFileName,
        std::uint32_t mapFileCRC, std::uint32_t sourceTimestamp);
    bool WriteBinary(const char* fileName, const char* binaryFileName,
        std::uint32_t mapFileCRC, std::uint32_t sourceTimestamp);

    bool GetAASAnim(idIndex<short, invalidAASAnimIndex_t> index,
        const aas2AnimName_t** value) const;
    idIndex<short, invalidAASAnimIndex_t> GetAASAnimIndexByName(const char* name) const;
    bool GetAASDependency(idIndex<short, invalidAASDependencyIndex_t> index,
        const aas2DependencyName_t** value) const;
    idIndex<short, invalidAASDependencyIndex_t> GetAASDependencyIndexByName(const char* name) const;
    bool GetAASInteractionEntity(idIndex<short, invalidAASInteractionEntIndex_t> index,
        const aas2InteractionEntityName_t** value) const;
    idIndex<short, invalidAASInteractionEntIndex_t> GetAASInteractionEntityIndexByName(const char* name) const;
    bool GetAASTraversalNameIndex(idIndex<short, invalidAASTraversalNameIndex_t> index,
        const aas2TraversalEntityName_t** value) const;
    idIndex<short, invalidAASTraversalNameIndex_t> GetAASTraversalNameIndexByName(const char* name) const;
    int GetAASTraversalIndexByNameIndex(idIndex<short, invalidAASTraversalNameIndex_t> index) const;
    bool SetTraversalFlag(int index, int flags);
    bool ClearTraversalFlag(int index, int flags);
    bool GetAASTraversalAreas(int index, int& startArea, int& goalArea) const;
    idIndex<short, invalidReachability_t> FindReachabilityByName(const char* name) const;
    int GetTraversalsForReachability(idIndex<short, invalidReachability_t> reachIndex,
        idList<int, 5>& traversals) const;
    int GetTraversalsForInteractableEntity(idIndex<short, invalidAASInteractionEntIndex_t> index,
        idList<int, 5>& traversals) const;

    void FlagNoPushAreas();
    void ResetCover();
    idIndex<int, invalidAASTree_t> GetTreeForFloorNormal(const idVec3& normal) const;
    idIndex<int, invalidAASTree_t> GetTreeForArea(int areaNum) const;
    int GetNumAreasInTree(idIndex<int, invalidAASTree_t> treeNum) const;
    const idVec3* GetFloorNormalForArea(int areaNum) const;
    const idVec3* GetFloorNormalForTree(idIndex<int, invalidAASTree_t> treeNum) const;

    idVec3 AreaCenter(int areaNum) const;
    idBounds EdgeBounds(int edgeNum) const;
    idBounds AreaBounds(int areaNum) const;
    int PointAreaNum(int tree, const idVec3& origin) const;
    int BoundsAreaNums(int tree, const idBounds& bounds, int* outputAreas,
        int maxAreas) const;
    void FlagBoundsAreas(int tree, const idBounds& bounds,
        bool* areasTouched) const;
    int BoundsReachableAreaNum(int tree, const idBounds& bounds,
        std::uint16_t areaFlags, int excludeTravelFlags) const;
    bool TraceHeight(int tree, aas2TraceHeight_t& trace,
        const idVec3& start, const idVec3& end) const;
    bool GetFloorEdgeSplitPoints(floorEdgeSplitPoint_t& nearest,
        floorEdgeSplitPoint_t& furthest, int areaNum,
        const idPlane& pathPlane, const idPlane& nearPlane) const;
    int MaxTreeDepth(int tree) const;
    bool Trace(int tree, aas2Trace_t& trace, const idVec3& start,
        const idVec3& end) const;
    int GetObstaclePVSWallEdges(int areaNum, int edgeFlags, int* outputEdges,
        int maxEdges) const;
    void ClipGridToAreas(const idVec3& startOrigin, int startAreaNum,
        int travelFlags, unsigned int cellSize, int dimension,
        std::uint8_t* reachable) const;
    float GetFloorDistance(int areaNum, const idPlane& floorPlane,
        const idVec3& point, float bboxHeight, float maxEdgeDist) const;
    int PointReachableAreaNum(idIndex<int, invalidAASTree_t> tree,
        const idVec3& origin, int areaFlags, int excludeTravelFlags) const;
    bool PushPointIntoAreaNum(int areaNum, idVec3& point) const;
    bool TraceFloor(aas2TraceFloor_t& trace, const idVec3& start,
        int startAreaNum, const idVec3& end, int endAreaNum, int travelFlags,
        bool allowFloorNormalChange, bool ignoreGravityDirectionDistance,
        bool ignoreSameArea) const;

    void FloodAddVisitedArea(int areaNum);
    void FloodClearVisitedAreas(int offset);

    static idTypedResourceList<idAAS2File> resourceList;

    std::uint32_t crc;
    std::uint32_t timestamp;
    idList<int, 37> visitedAreas;
    idAAS2Settings settings;
    int major;
    int minor;
    int firstFakeVertex;
    int firstFakeEdge;
    int firstFakeEdgeIndex;
    int firstFakeArea;
    idList<bspTree_t, 37> trees;
    idList<idPlane, 37> planes;
    idList<idVec3, 37> vertices;
    idList<aas2Edge_t, 37> edges;
    idList<int, 37> edgeIndex;
    idList<aas2Reachability_t, 37> reachabilities;
    idList<aas2Area_t, 37> areas;
    idList<aas2Node_t, 37> nodes;
    idList<aas2Portal_t, 37> portals;
    idList<int, 37> portalIndex;
    idList<aas2Cluster_t, 37> clusters;
    idList<std::uint8_t, 37> obstaclePVS;
    idList<aas2Name_t, 37> reachabilityNames;
    idList<aas2AnimName_t, 37> animNames;
    idList<aas2DependencyName_t, 37> dependencyNames;
    idList<aas2InteractionEntityName_t, 37> interactionEntityNames;
    idList<aas2TraversalEntityName_t, 37> traversalEntityNames;
    idList<aas2Cover_t, 37> cover;
    idList<int, 37> areaCoverIndex;
    idList<int, 37> touchingCoverIndex;
    idList<aas2ChokePoint_t, 37> chokePoints;
    idList<aas2Traversal_t, 37> traversalPoints;
    idList<aas2HintNode_t, 37> hintNodes;
    idList<aas2AreaBounds_t, 37> areaBounds;

private:
    bool LoadText(const char* fileName, std::uint32_t sourceTimestamp);
    bool ParseIndex(idLexer& source, idList<int, 37>& indexes);
    bool ParseNames(idLexer& source, idList<aas2Name_t, 37>& names);
    template<typename nameType>
    bool ParseInteractionEntityNames(idLexer& source,
        idList<nameType, 37>& names);
    bool ParseVertices(idLexer& source);
    bool ParseEdges(idLexer& source);
    bool ParseNodes(idLexer& source);
    bool ParsePortals(idLexer& source);
    bool ParseClusters(idLexer& source);
    bool ParseObstaclePVS(idLexer& source);
    bool ParsePlanes(idLexer& source);
    bool ParseReachabilities(idLexer& source);
    bool ParseAreas(idLexer& source);
    bool ParseCover(idLexer& source);
    bool ParseTraversalPoints(idLexer& source);
    bool ParseHintNodes(idLexer& source);
    bool ParseTrees(idLexer& source);
    void CalculateAreaBounds();
    void BuildReachabilityChains();
    void PointBestReachableAreaNum(int tree, const idVec3& origin,
        bestReachableArea_t& bestArea) const;
    void BoundsBestReachableAreaNum(int tree, const idBounds& bounds,
        const idVec3& origin, bestReachableArea_t& bestArea) const;
    void MaxTreeDepth_r(int nodeNum, int depth, int& maxDepth) const;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idAAS2Settings) == 268,
    "Recovered idAAS2Settings ABI changed");
static_assert(sizeof(aas2Edge_t) == 12, "Recovered aas2Edge_t ABI changed");
static_assert(sizeof(aas2Node_t) == 16, "Recovered aas2Node_t ABI changed");
static_assert(sizeof(aas2Portal_t) == 12, "Recovered aas2Portal_t ABI changed");
static_assert(sizeof(aas2Reachability_t) == 32,
    "Recovered aas2Reachability_t ABI changed");
static_assert(sizeof(aas2Area_t) == 40, "Recovered aas2Area_t ABI changed");
static_assert(sizeof(aas2Cover_t) == 56, "Recovered aas2Cover_t ABI changed");
static_assert(sizeof(aas2ChokePoint_t) == 28,
    "Recovered aas2ChokePoint_t ABI changed");
static_assert(sizeof(aas2HintNode_t) == 24,
    "Recovered aas2HintNode_t ABI changed");
static_assert(sizeof(aas2Trace_t) == 56, "Recovered aas2Trace_t ABI changed");
static_assert(sizeof(aas2TraceFloor_t) == 84,
    "Recovered aas2TraceFloor_t ABI changed");
static_assert(sizeof(idAAS2File) == 736, "Recovered idAAS2File ABI changed");
#endif
