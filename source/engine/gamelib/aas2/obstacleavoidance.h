#pragma once

#include "idlib/math/vector.h"
#include "idlib/bv/bounds.h"
#include "idlib/math/matrix.h"
#include "gamelib/aas2/obstacleavoidancecore.h"

struct idObstacleBuffers;
class idBox;
class idSpawnId;

enum vaiObstacleAvoidance_t : int {
    OAT_INIT = -1,
    OAT_GENERAL = 0,
    OAT_NONE = 1
};

enum obstacleAvoidanceFlags_t : int {
    OAFLAG_ASSUME_VALID_AAS_PATH = 0x001,
    OAFLAG_MOVE_AROUND_SEEK_POS_OBSTACLES = 0x002,
    OAFLAG_CIRCLE_CORNERS = 0x004,
    OAFLAG_UPDATE_RADAR = 0x008,
    OAFLAG_REPLACE_EXISTING_QUERY = 0x010,
    OAFLAG_SHOW_PATH_TREE = 0x020,
    OAFLAG_DEBUG = 0x040,
    OAFLAG_DEBUG_BREAK = 0x080,
    OAFLAG_USE_LINE_INTERSECTION_EPSILON = 0x100,
    OAFLAG_SINGLE_PUSH = 0x200,
    OAFLAG_IGNORE_AIS = 0x400
};

class idObstacleAvoidance {
public:
    idObstacleAvoidance();
    ~idObstacleAvoidance();
    void AllocBuffers();
    obstacleVertex_t* GetVertexArray();
    int GetMaxVertices() const;
    void SetNumVertices(int num);
    obstacleEdge_t* GetEdgeArray();
    int GetMaxEdges() const;
    void SetNumEdges(int num);
    void AddObstacle(const idBox& box, idSpawnId id, bool soft);
    void AddObstacle(const idBounds& bounds, const idVec3& origin,
        const idMat3& axis, idSpawnId id, bool soft);
    void Restart(const idVec3& start, const idVec3& goal);
    void ProjectTopDown(idVec3& point, const idVec3& startPos,
        float scale) const;
    void DrawBox(const idVec3& startPos, float radius) const;
    bool SaveQuery(const char* fileName) const;
    bool FindPathAroundObstacles(obstaclePath_t& path, int time,
        int gameMsPerFrame, const idBounds& bbox, const idVec3& gravity,
        float obstacleRadius, float frameMoveDist, float cornerCircleRadius,
        int flags, const obstacleRoute_t& route,
        obstacleTraceSet_t* traceSet);
    bool TestQuery(const char* fileName);

    idObstacleBuffers* buffers;
    idVec3 lastDir;
    idVec4 lastCorner;
    int lastUpdateTime;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idObstacleAvoidance) == 36,
    "Recovered idObstacleAvoidance ABI changed");
#endif
