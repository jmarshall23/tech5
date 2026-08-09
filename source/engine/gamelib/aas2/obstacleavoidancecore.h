#pragma once

#include "idlib/containers/queue.h"
#include "idlib/bv/bounds.h"
#include "idlib/math/mat3x4.h"
#include "idlib/math/plane.h"
#include "idlib/math/vector.h"

#include <cstdint>
#include <cstddef>

struct obstacleVertex_t { idVec3 position; };
struct obstacleEdge_t {
    int flags;
    std::int16_t verts[2];
    int vertNums[2];
};
struct obstacleBox_t {
    idMat3 axis;
    idVec3 center;
    idVec3 extents;
    int id;
    bool soft;
    std::uint8_t pad[15];
};
struct obstacleCorner_t { idVec3 corner; float radius; };
struct obstacleTrace_t { idVec2 start; idVec2 end; };

struct obstacleRoute_t {
    struct routeArea_t {
        int areaNum;
        idVec3 start;
        idVec3 end;
    };

    int numAreas;
    int pad[2];
    idVec3 endAlignDir;
    float endTurnRadius;
    routeArea_t areas[11];

    // Materialized in the authoritative obstacleavoidancecore.h dump.
    obstacleRoute_t()
        : numAreas(0), pad{0, 0}, endAlignDir(), endTurnRadius(0.0f),
          areas{} {
        Clear();
    }

    void Clear() {
        numAreas = 0;
        endAlignDir.Zero();
        endTurnRadius = 0.0f;
        for (routeArea_t& area : areas) {
            area.areaNum = 0;
            area.start.Zero();
            area.end.Zero();
        }
    }
};

struct obstaclePath_t {
    struct radar_t {
        idVec3 direction;
        int obstacle;
    };

    idVec3 seekPos[31];
    int numSeekPos;
    idPlane seekPosPlane;
    idVec3 firstObstaclePosition;
    int firstObstacle;
    idVec3 startPosOutsideObstacles;
    int startPosObstacle;
    idVec3 seekPosOutsideObstacles;
    int seekPosObstacle;
    float targetDist;
    float pathLength;
    idVec4 nextCorner;
    float nextCornerAngle;
    idVec3 wallCorners[2];
    radar_t radar[7];
    bool useRadarForward;
    idVec3 radarForward;
    bool hasValidPath;
    bool startPosValid;
    bool seekPosValid;
    bool done;

    // Materialized in the authoritative obstacleavoidancecore.h dump.
    obstaclePath_t()
        : seekPos{}, numSeekPos(0), seekPosPlane(0, 0, 0, 0),
          firstObstaclePosition(), firstObstacle(-1),
          startPosOutsideObstacles(), startPosObstacle(-1),
          seekPosOutsideObstacles(), seekPosObstacle(-1), targetDist(0.0f),
          pathLength(0.0f), nextCorner(), nextCornerAngle(0.0f),
          wallCorners{}, radar{}, useRadarForward(false), radarForward(),
          hasValidPath(false), startPosValid(false), seekPosValid(false),
          done(false) {
    }
};

class idObstacleAvoidanceCore {
public:
    enum avoidColor_t : int {
        COLOR_INVALID = 0,
        COLOR_WHITE = 1,
        COLOR_GRAY = 2,
        COLOR_RED = 3,
        COLOR_BLUE = 4,
        COLOR_GREEN = 5,
        COLOR_YELLOW = 6,
        COLOR_ORANGE = 7,
        COLOR_PURPLE = 8,
        COLOR_CYAN = 9,
        COLOR_MAGENTA = 10
    };

    struct pathNode_t {
        int dir;
        idVec2 pos;
        idVec2 delta;
        float targetDistSqr;
        int obstacle;
        int edgeNum;
        int numNodes;
        pathNode_t* parent;
        pathNode_t* children[2];
        idQueueNode<pathNode_t> queueNode;
    };

    struct bspNode_t {
        int axis;
        float dist;
        std::int16_t children[2];
        std::int16_t indexOffset;
        std::int16_t numIndices;
    };

    struct expandedObstacle_t {
        idVec2 bounds[2];
        idVec2* winding;
        int numPoints;
        int id;
        bool soft;
        std::uint8_t pad[3];
    };

    // This is the layout of the recovered function-local terminator type.
    struct setupExpandedObstaclesTerminator_t {
        float distSqr;
        std::int16_t lastEdgeIndex;
        std::int16_t firstEdgeIndex;
    };

    idObstacleAvoidanceCore();
    ~idObstacleAvoidanceCore();

    static int BoxParallelProjectionSilhouetteVerts(const idMat3& axis,
        const idVec3& center, const idVec3& extents,
        const idVec3& projectionDir, idVec3* silhouette);
    static void GetCirclePoints(const idVec2& center, float radius,
        idVec2* circlePoints);
    static idVec3 Plane2DFromPoints(const idVec2& start,
        const idVec2& end, bool normalize);
    static idVec3 Plane2DFromVecs(const idVec2& start,
        const idVec2& direction, bool normalize);
    static bool PointInsideWinding(const idVec2* winding, int numPoints,
        const idVec2& point, float epsilon = 0.0f);
    static void ExpandWinding(const idVec2* winding, int numPoints,
        float distance, idVec2* expanded);
    static void GetWindingBounds(const idVec2* winding, int numPoints,
        idVec2 bounds[2]);
    static bool WindingRayIntersection(const idVec2* winding, int numPoints,
        const idVec2& start, const idVec2& direction, float& firstScale,
        float& secondScale, int edgeNums[2]);
    void AddDebugLine(avoidColor_t color, const idVec2& start,
        const idVec2& end);
    void AddDebugInt(avoidColor_t color, const idVec2& position, int value);
    void FindPathAroundObstacles(obstaclePath_t& path,
        struct avoidDebugLine_t* debugLines, int maxDebugLines,
        struct avoidDebugText_t* debugText, int maxDebugText,
        std::uint8_t* temp, int tempSize, const idBounds& bbox,
        const idVec3& gravity, const idVec3& lastDir,
        const idVec4& lastCorner, float obstacleRadius,
        float frameMoveDist, float cornerCircleRadius, int flags,
        const obstacleRoute_t& route, const obstacleBox_t* obstacles,
        int numObstacles, const obstacleVertex_t* vertices, int numVertices,
        const obstacleEdge_t* edges, int numEdges,
        const obstacleCorner_t* corners, int numCorners,
        const obstacleTrace_t* traces, int numTraces,
        float* traceFractions);

    bspNode_t* bspNodes;
    int numBspNodes;
    std::int16_t* obstacleIndices;
    expandedObstacle_t* expandedObstacles;
    int maxExpandedObstacles;
    int numExpandedObstacles;
    idVec2* windingPoints;
    int maxWindingPoints;
    int numWindingPoints;
    std::uint8_t* tempMemory;
    int tempMemorySize;
    std::uint8_t* tempMemoryStart;
    std::uint8_t* tempMemoryEnd;
    pathNode_t* pathNodes;
    int maxPathNodes;
    int numPathNodes;
    avoidDebugLine_t* debugLines;
    int maxDebugLines;
    int numDebugLines;
    avoidDebugText_t* debugText;
    int maxDebugText;
    int numDebugText;
    bool inputTransformValid;
    idMat3x4 inputTransform;
    int flags;
};

struct avoidDebugLine_t {
    idObstacleAvoidanceCore::avoidColor_t color;
    idVec3 start;
    idVec3 end;
};

struct avoidDebugText_t {
    char text[32];
    idVec3 pos;
    idObstacleAvoidanceCore::avoidColor_t color;
};

struct obstacleTraceSet_t {
    obstacleTrace_t traces[256];
    float traceFractions[256];
    int traceNumbers[256];
    int numTraces;
    int prevTraceNumbers[256];
    int prevNumTraces;
};

struct obstacleParms_t {
    idBounds bbox;
    idVec3 gravity;
    idVec3 lastDir;
    idVec4 lastCorner;
    float obstacleRadius;
    float frameMoveDist;
    float cornerCircleRadius;
    int flags;
    int numObstacles;
    int numVertices;
    int numEdges;
    int numCorners;
    int numTraces;
    int maxDebugLines;
    int maxDebugText;
    const obstacleRoute_t* route;
    const obstacleBox_t* obstacles;
    const obstacleVertex_t* vertices;
    const obstacleEdge_t* edges;
    const obstacleCorner_t* corners;
    const obstacleTrace_t* traces;
    float* traceFractions;
    obstaclePath_t* path;
    avoidDebugLine_t* debugLines;
    avoidDebugText_t* debugText;
    std::uint8_t pad[12];
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(obstacleRoute_t::routeArea_t) == 28,
    "Recovered obstacle route area ABI changed");
static_assert(sizeof(obstacleRoute_t) == 336,
    "Recovered obstacleRoute_t ABI changed");
static_assert(sizeof(obstaclePath_t::radar_t) == 16,
    "Recovered obstacle radar ABI changed");
static_assert(sizeof(obstaclePath_t) == 624,
    "Recovered obstaclePath_t ABI changed");
static_assert(sizeof(idObstacleAvoidanceCore::pathNode_t) == 52,
    "Recovered obstacle path node ABI changed");
static_assert(sizeof(idObstacleAvoidanceCore::bspNode_t) == 16,
    "Recovered obstacle BSP node ABI changed");
static_assert(sizeof(idObstacleAvoidanceCore::expandedObstacle_t) == 32,
    "Recovered expanded obstacle ABI changed");
static_assert(sizeof(obstacleVertex_t) == 12,
    "Recovered obstacle vertex ABI changed");
static_assert(sizeof(obstacleEdge_t) == 16,
    "Recovered obstacle edge ABI changed");
static_assert(sizeof(obstacleBox_t) == 80,
    "Recovered obstacle box ABI changed");
static_assert(sizeof(obstacleCorner_t) == 16,
    "Recovered obstacle corner ABI changed");
static_assert(sizeof(obstacleTrace_t) == 16,
    "Recovered obstacle trace ABI changed");
static_assert(sizeof(avoidDebugLine_t) == 28,
    "Recovered obstacle debug-line ABI changed");
static_assert(sizeof(avoidDebugText_t) == 48,
    "Recovered obstacle debug-text ABI changed");
#endif
