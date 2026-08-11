#pragma once

#include "../../entities/entityptr.h"
#include "../../../../shared/idlib/containers/staticlist.h"
#include "../../../../shared/idlib/math/vector.h"

#include <cstdint>

class idEntity;

#ifndef ID_CLIP_QUERY_DEFINED
#define ID_CLIP_QUERY_DEFINED
struct idClipQuery {
    std::uint64_t index;
};
#endif

enum queueTraceResults_t : int {
    QUEUE_TRACE_FULL = 0,
    QUEUE_TRACE_SKIPPED = 1,
    QUEUE_TRACE_SUBMITTED = 2
};

class idBotTraceManagerServices {
public:
    virtual ~idBotTraceManagerServices() = default;
    virtual int GetEntitySpawnId(const idEntity* entity) const = 0;
    virtual const idEntity* ResolveEntitySpawnId(int spawnId) const = 0;
    virtual bool IsPlayer(const idEntity& entity) const = 0;
    virtual int GetEntityNumber(const idEntity& entity) const = 0;
    virtual idVec3 GetEyePosition(const idEntity& entity) const = 0;
    virtual idClipQuery SubmitVisibilityTrace(const idVec3& start,
        const idVec3& end, int clipMask, const char* userName) = 0;
    virtual bool IsTraceComplete(const idClipQuery& query) const = 0;
    virtual float GetTraceFraction(const idClipQuery& query) = 0;
    virtual bool IsDebugEnabled() const = 0;
    virtual void DebugDrawEntity(const idEntity& entity,
        int lastUpdateTime, int currentTime) = 0;
    virtual void DebugDrawPerception(const idEntity& source,
        const idEntity& target, bool visible, int lastUpdateTime,
        int currentTime) = 0;
};

void Tungsten_SetBotTraceManagerServices(
    idBotTraceManagerServices* services);

class idBotTraceManager {
public:
    struct perceptionData_t {
        int lastSeenTime;
        int lastUpdateTime;
    };

    struct entityData_t {
        int lastUpdateTime;
        idEntityPtr<const idEntity> ent;
    };

    struct traceWorkData_t {
        int srcIndex;
        int targetIndex;
        idClipQuery clipQuery;
    };

    idBotTraceManager();
    ~idBotTraceManager();

    void AddEntity(const idEntity* entity);
    void RemoveEntity(const idEntity* entity);
    void Update(int currentTime);
    bool IsVisible(const idEntity* entity, const idEntity* otherEntity,
        int timeDelta) const;

    int GetTrackedIndex(const idEntity* entity) const {
        return GetIndexForEntity(entity);
    }
    int GetNumActiveTraces() const { return numActiveTraces; }
    int GetPlayerUpdateCount() const { return playerUpdateIndexes.Num(); }
    const perceptionData_t& GetPerceptionData(int source,
            int target) const {
        return perceptionTable[source][target];
    }
    const entityData_t& GetEntityData(int index) const {
        return entityData[index];
    }

private:
    queueTraceResults_t QueueVisTrace(unsigned int sourceIndex,
        unsigned int targetIndex);
    void DebugDraw(int currentTime);
    int GetIndexForEntity(const idEntity* entity) const;

    int curEntDataIndex;
    int curTraceIndex;
    int numActiveTraces;
    perceptionData_t perceptionTable[6][32];
    entityData_t entityData[32];
    traceWorkData_t traceWorkData[8];
    idStaticList<int, 6> playerUpdateIndexes;
};
