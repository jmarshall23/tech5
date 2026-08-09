#pragma once

#include "gamelib/physics/clip.h"
#include "idlib/containers/list.h"
#include "idlib/math/vector.h"

#include <cstdint>

class idAAS2;
class idColor;

struct idDeferredVisQuery {
    idDeferredVisQuery* nextInHash;
    idDeferredVisQuery* prev;
    idDeferredVisQuery* next;
    std::int16_t start[3];
    std::int16_t end[3];
    std::int16_t frameCounter;
    std::uint8_t queryIdx;
    std::uint8_t state;
    int pad;
};

struct deferredVisList_t {
    idDeferredVisQuery* headNode;
    idDeferredVisQuery* tailNode;
    int numElements;
};

class idDeferredVisCache {
public:
    enum queryState_t : std::uint8_t {
        VIS_INVALID = 0,
        VIS_PENDING = 1,
        VIS_SUBMITTED = 2,
        VIS_BLOCKED = 3,
        VIS_CLEAR = 4
    };

    idDeferredVisCache();
    ~idDeferredVisCache();
    void Init(idClip* inClip);
    void Shutdown();
    void UpdateCollisionQueries();
    void SubmitCollisionQueries();
    std::uint8_t GetVisQuery(const std::uint16_t start[3],
        const std::uint16_t end[3], int flags);
    void PrintDebugInfo() const;

    idList<idDeferredVisQuery*, 106> hashTable;
    idList<idClipQuery, 106> clipQueries;
    int curClipQueryIdx;
    deferredVisList_t leastRecentlyUsedList;
    deferredVisList_t priorityList;
    idClip* clip;
    idDeferredVisQuery* queryList;
    idDeferredVisQuery* queryPool;
    int expiredIndex;
    int numFrames;
    int numCreatedThisFrame;
    int numBumped;
    int numQueriesIssued;
    int totalQueriesIssued;
    int numPurged;
    int numExpired;
    int numCacheHits;
    int totalCacheHits;
    int maxCreatedInAFrame;
    int recentNumFrames;
    int recentTotalCacheHits;
    int recentTotalQueriesIssued;
    float recentCacheHitRatio;
    float recentAvgHitRatio;
    bool initialized;
    bool alreadyWarned;

private:
    idDeferredVisQuery* AllocNode();
    void FreeLinkedList(deferredVisList_t& list);
    void RemoveNoDelete(deferredVisList_t& list,
        idDeferredVisQuery* node);
    void AddToFront(deferredVisList_t& list,
        idDeferredVisQuery* node);
    void RemoveFromHash(idDeferredVisQuery* node);
    void FreeNode(idDeferredVisQuery* node);
};

class idDeferredVisGrid {
public:
    idDeferredVisGrid();
    void Init(const idVec3& entityPos);
    void Update(const idVec3& entityPos, const idAAS2* aas,
        int areaNum, int travelFlags);
    float GetGridVisibility(const idVec3& worldPoint,
        idDeferredVisCache& cache, const float* staggerZ,
        int flags, idColor* missDebugColor = nullptr,
        idColor* hitDebugColor = nullptr);
    void DebugDrawGrid() const;

    std::uint8_t cells[64];
    std::int16_t xyz[3];
};

static_assert(sizeof(idDeferredVisGrid) == 70,
    "Recovered deferred visibility grid ABI changed");
#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idDeferredVisQuery) == 32,
    "Recovered deferred visibility query ABI changed");
static_assert(sizeof(deferredVisList_t) == 12,
    "Recovered deferred visibility list ABI changed");
static_assert(sizeof(idDeferredVisCache) == 140,
    "Recovered deferred visibility cache ABI changed");
#endif
