#pragma once

#include "gamelib/aas2/obstacleavoidance.h"
#include "gamelib/aas2/obstacleavoidancecore.h"
#include "idlib/containers/list.h"

class idParallelJobList;
class CellSpursJob128;
struct obstacleParms_t;
struct obstacleBox_t;
struct obstacleVertex_t;
struct obstacleEdge_t;
struct obstacleCorner_t;
struct obstacleTrace_t;

struct idObstacleBuffers {
    idObstacleAvoidance* user;
    CellSpursJob128* job;
    obstacleParms_t* parms;
    obstacleRoute_t* route;
    obstacleBox_t* obstacles;
    obstacleVertex_t* vertices;
    obstacleEdge_t* edges;
    obstacleCorner_t* corners;
    obstacleTrace_t* traces;
    float* traceFractions;
    obstaclePath_t* path;
    int numObstacles;
    int numVertices;
    int numEdges;
    int numCorners;
    int numTraces;
    int frameCount;
};

class idObstacleAvoidanceManager {
public:
    virtual ~idObstacleAvoidanceManager() = default;
    virtual void Init(idParallelJobList* jobList) = 0;
    virtual void Shutdown() = 0;
    virtual void AllocObstacleBuffers(idObstacleAvoidance* avoidance) = 0;
    virtual void FreeObstacleBuffers(idObstacleAvoidance* avoidance) = 0;
    virtual void FrameFreeObstacleBuffers() = 0;
    virtual idParallelJobList* GetJobList() = 0;
};

class idObstacleAvoidanceManagerLocal : public idObstacleAvoidanceManager {
public:
    idObstacleAvoidanceManagerLocal();
    ~idObstacleAvoidanceManagerLocal() override;

    void Init(idParallelJobList* jobList_) override;
    void Shutdown() override;
    void AllocObstacleBuffers(idObstacleAvoidance* avoidance) override;
    void FreeObstacleBuffers(idObstacleAvoidance* avoidance) override;
    void FrameFreeObstacleBuffers() override;
    idParallelJobList* GetJobList() override { return jobList; }

    idParallelJobList* jobList;
    idList<idObstacleBuffers*, 5> usedBuffers;
    idList<idObstacleBuffers*, 5> freeBuffers;
    idList<idObstacleBuffers*, 5> toBeFreedBuffers;
};

extern idObstacleAvoidanceManagerLocal obstacleAvoidanceManagerLocal;

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idObstacleBuffers) == 68,
    "Recovered idObstacleBuffers ABI changed");
static_assert(sizeof(idObstacleAvoidanceManagerLocal) == 56,
    "Recovered obstacle-avoidance manager ABI changed");
#endif
