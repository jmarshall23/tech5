#include "gamelib/aas2/deferredviscache.h"

#include "cm/collisionmodelmanager.h"
#include "gamelib/aas2/aas2.h"
#include "idlib/lib_print.h"

#include <algorithm>
#include <cmath>
#include <cstring>

namespace {

constexpr int QUERY_POOL_SIZE = 5120;
constexpr int HASH_SIZE = 4096;
constexpr int CLIP_QUERY_COUNT = 256;
constexpr int MAX_SUBMITS_PER_FRAME = 128;
constexpr int MAX_LRU_ENTRIES = 4096;

int HashQuery(const std::int16_t start[3], const std::int16_t end[3]) {
    return (start[0] + start[1] + start[2]
        + end[0] + end[1] + end[2]) & (HASH_SIZE - 1);
}

std::int16_t Quantize(const float value) {
    const int integer = static_cast<int>(value);
    return static_cast<std::int16_t>((std::max)(-32768,
        (std::min)(32767, integer)));
}

bool SameQuery(const idDeferredVisQuery& query,
        const std::uint16_t start[3], const std::uint16_t end[3]) {
    for (int axis = 0; axis < 3; ++axis) {
        if (static_cast<std::uint16_t>(query.start[axis]) != start[axis]
            || static_cast<std::uint16_t>(query.end[axis]) != end[axis])
            return false;
    }
    return true;
}

} // namespace

idDeferredVisCache::idDeferredVisCache()
    : hashTable(), clipQueries(), curClipQueryIdx(0),
      leastRecentlyUsedList{nullptr, nullptr, 0},
      priorityList{nullptr, nullptr, 0}, clip(nullptr), queryList(nullptr),
      queryPool(new idDeferredVisQuery[QUERY_POOL_SIZE]), expiredIndex(0),
      numFrames(0), numCreatedThisFrame(0), numBumped(0),
      numQueriesIssued(0), totalQueriesIssued(0), numPurged(0),
      numExpired(0), numCacheHits(0), totalCacheHits(0),
      maxCreatedInAFrame(0), recentNumFrames(0), recentTotalCacheHits(0),
      recentTotalQueriesIssued(0), recentCacheHitRatio(0.0f),
      recentAvgHitRatio(0.0f), initialized(false), alreadyWarned(false) {
    hashTable.SetNum(HASH_SIZE);
    for (int index = 0; index < HASH_SIZE; ++index)
        hashTable[index] = nullptr;
    clipQueries.SetNum(CLIP_QUERY_COUNT);
    for (int index = 0; index < CLIP_QUERY_COUNT; ++index)
        clipQueries[index].index = 0;
    for (int index = 0; index < QUERY_POOL_SIZE; ++index) {
        idDeferredVisQuery& query = queryPool[index];
        std::memset(&query, 0, sizeof(query));
        query.frameCounter = -1;
        query.next = index + 1 < QUERY_POOL_SIZE
            ? &queryPool[index + 1] : nullptr;
    }
    queryList = queryPool;
}

idDeferredVisCache::~idDeferredVisCache() {
    Shutdown();
    delete[] queryPool;
    queryPool = nullptr;
    queryList = nullptr;
}

idDeferredVisQuery* idDeferredVisCache::AllocNode() {
    if (queryList == nullptr) return nullptr;
    idDeferredVisQuery* const node = queryList;
    queryList = node->next;
    node->nextInHash = nullptr;
    node->prev = nullptr;
    node->next = nullptr;
    node->frameCounter = -1;
    node->queryIdx = 0;
    node->state = VIS_INVALID;
    node->pad = 0;
    return node;
}

void idDeferredVisCache::FreeLinkedList(deferredVisList_t& list) {
    idDeferredVisQuery* node = list.headNode;
    while (node != nullptr) {
        idDeferredVisQuery* const next = node->next;
        node->state = VIS_INVALID;
        node->frameCounter = -1;
        node->prev = nullptr;
        node->next = queryList;
        queryList = node;
        node = next;
    }
    list.headNode = nullptr;
    list.tailNode = nullptr;
    list.numElements = 0;
}

void idDeferredVisCache::RemoveNoDelete(deferredVisList_t& list,
        idDeferredVisQuery* const node) {
    if (node == nullptr) return;
    if (node->prev != nullptr) node->prev->next = node->next;
    else if (list.headNode == node) list.headNode = node->next;
    if (node->next != nullptr) node->next->prev = node->prev;
    else if (list.tailNode == node) list.tailNode = node->prev;
    node->prev = nullptr;
    node->next = nullptr;
    if (list.numElements > 0) --list.numElements;
}

void idDeferredVisCache::AddToFront(deferredVisList_t& list,
        idDeferredVisQuery* const node) {
    node->prev = nullptr;
    node->next = list.headNode;
    if (list.headNode != nullptr) list.headNode->prev = node;
    else list.tailNode = node;
    list.headNode = node;
    ++list.numElements;
}

void idDeferredVisCache::RemoveFromHash(idDeferredVisQuery* const node) {
    if (node == nullptr || hashTable.IsEmpty()) return;
    const int bucket = HashQuery(node->start, node->end);
    idDeferredVisQuery** link = &hashTable[bucket];
    while (*link != nullptr && *link != node)
        link = &(*link)->nextInHash;
    if (*link == node) *link = node->nextInHash;
    node->nextInHash = nullptr;
}

void idDeferredVisCache::FreeNode(idDeferredVisQuery* const node) {
    if (node == nullptr) return;
    RemoveFromHash(node);
    node->state = VIS_INVALID;
    node->frameCounter = -1;
    node->prev = nullptr;
    node->next = queryList;
    queryList = node;
}

void idDeferredVisCache::Init(idClip* const inClip) {
    clip = inClip;
    initialized = true;
}

void idDeferredVisCache::Shutdown() {
    clip = nullptr;
    if (queryPool == nullptr) return;
    FreeLinkedList(leastRecentlyUsedList);
    FreeLinkedList(priorityList);
    for (int index = 0; index < HASH_SIZE; ++index)
        hashTable[index] = nullptr;
    queryList = nullptr;
    for (int index = QUERY_POOL_SIZE - 1; index >= 0; --index) {
        queryPool[index].state = VIS_INVALID;
        queryPool[index].frameCounter = -1;
        queryPool[index].nextInHash = nullptr;
        queryPool[index].prev = nullptr;
        queryPool[index].next = queryList;
        queryList = &queryPool[index];
    }
    initialized = false;
    expiredIndex = 0;
    numFrames = 0;
    numCreatedThisFrame = 0;
    numBumped = 0;
    numQueriesIssued = 0;
    totalQueriesIssued = 0;
    totalCacheHits = 0;
}

std::uint8_t idDeferredVisCache::GetVisQuery(
        const std::uint16_t start[3], const std::uint16_t end[3],
        const int flags) {
    if (!initialized || start == nullptr || end == nullptr) return VIS_INVALID;
    std::int16_t signedStart[3];
    std::int16_t signedEnd[3];
    for (int axis = 0; axis < 3; ++axis) {
        signedStart[axis] = static_cast<std::int16_t>(start[axis]);
        signedEnd[axis] = static_cast<std::int16_t>(end[axis]);
    }
    const int bucket = HashQuery(signedStart, signedEnd);
    for (idDeferredVisQuery* node = hashTable[bucket]; node != nullptr;
         node = node->nextInHash) {
        if (!SameQuery(*node, start, end)) continue;
        if (node->state >= VIS_BLOCKED) {
            ++numCacheHits;
            ++totalCacheHits;
            if (leastRecentlyUsedList.headNode != node) {
                RemoveNoDelete(leastRecentlyUsedList, node);
                AddToFront(leastRecentlyUsedList, node);
            }
        }
        if (node->frameCounter == 1 && (flags & 2) != 0) {
            node->frameCounter = 0;
            ++numBumped;
        }
        return node->state;
    }
    idDeferredVisQuery* const node = AllocNode();
    if (node == nullptr) {
        if (!alreadyWarned) {
            idLibPrint::Warning(
                "idDeferredVisCache::GetVisQuery ran out of query nodes");
            alreadyWarned = true;
        }
        return VIS_INVALID;
    }
    ++numCreatedThisFrame;
    for (int axis = 0; axis < 3; ++axis) {
        node->start[axis] = signedStart[axis];
        node->end[axis] = signedEnd[axis];
    }
    node->state = VIS_PENDING;
    node->nextInHash = hashTable[bucket];
    hashTable[bucket] = node;
    AddToFront(priorityList, node);
    return VIS_PENDING;
}

void idDeferredVisCache::UpdateCollisionQueries() {
    if (!initialized || clip == nullptr) return;
    maxCreatedInAFrame = (std::max)(maxCreatedInAFrame,
        numCreatedThisFrame);
    numPurged = 0;
    numExpired = 0;
    numCreatedThisFrame = 0;
    numBumped = 0;
    numCacheHits = 0;
    idDeferredVisQuery* node = priorityList.headNode;
    while (node != nullptr) {
        idDeferredVisQuery* const next = node->next;
        if (node->state == VIS_SUBMITTED) {
            trace_t trace{};
            trace.fraction = 1.0f;
            idCollisionQuery query{};
            query.offset = clipQueries[node->queryIdx].index;
            collisionModelManager.GetContentsResult(&trace, query, false);
            node->state = trace.fraction >= 1.0f ? VIS_CLEAR : VIS_BLOCKED;
            node->frameCounter = trace.c.entityNum == 8190 ? 30 : 18;
            RemoveNoDelete(priorityList, node);
            AddToFront(leastRecentlyUsedList, node);
        }
        node = next;
    }
}

void idDeferredVisCache::SubmitCollisionQueries() {
    if (!initialized || clip == nullptr) return;
    int submitted = 0;
    for (idDeferredVisQuery* node = priorityList.headNode;
         node != nullptr && submitted < MAX_SUBMITS_PER_FRAME;
         node = node->next) {
        if (node->state != VIS_PENDING) continue;
        const idVec3 start(static_cast<float>(node->start[0]),
            static_cast<float>(node->start[1]),
            static_cast<float>(node->start[2]));
        const idVec3 end(static_cast<float>(node->end[0]),
            static_cast<float>(node->end[1]),
            static_cast<float>(node->end[2]));
        clipQueries[curClipQueryIdx] = clip->Translation(nullptr, start, end,
            nullptr, idMat3(1.0f), 1, -1, false,
            "idDeferredVisCache");
        node->queryIdx = static_cast<std::uint8_t>(curClipQueryIdx);
        curClipQueryIdx = (curClipQueryIdx + 1) & 255;
        node->state = VIS_SUBMITTED;
        ++submitted;
    }
    numQueriesIssued = submitted;
    totalQueriesIssued += submitted;
    while (leastRecentlyUsedList.numElements > MAX_LRU_ENTRIES) {
        idDeferredVisQuery* const expired = leastRecentlyUsedList.tailNode;
        RemoveNoDelete(leastRecentlyUsedList, expired);
        FreeNode(expired);
        ++numPurged;
    }
    const int endIndex = (std::min)(QUERY_POOL_SIZE, expiredIndex + 512);
    for (int index = expiredIndex; index < endIndex; ++index) {
        idDeferredVisQuery* const candidate = &queryPool[index];
        if (candidate->frameCounter < 0) continue;
        if (--candidate->frameCounter <= 0) {
            RemoveNoDelete(leastRecentlyUsedList, candidate);
            FreeNode(candidate);
            ++numExpired;
        }
    }
    expiredIndex = endIndex < QUERY_POOL_SIZE ? endIndex : 0;
    alreadyWarned = false;
    ++numFrames;
}

void idDeferredVisCache::PrintDebugInfo() const {
    idLibPrint::Printf("Deferred vis: queries %d, cache hits %d, "
        "priority %d, LRU %d\n", totalQueriesIssued, totalCacheHits,
        priorityList.numElements, leastRecentlyUsedList.numElements);
}

idDeferredVisGrid::idDeferredVisGrid() : cells{}, xyz{} {
}

void idDeferredVisGrid::Init(const idVec3& entityPos) {
    xyz[0] = static_cast<std::int16_t>(Quantize(entityPos.x) + 32);
    Update(entityPos, nullptr, -1, 0);
}

void idDeferredVisGrid::Update(const idVec3& entityPos,
        const idAAS2* const aas, const int areaNum,
        const int travelFlags) {
    const std::int16_t newX = static_cast<std::int16_t>(
        (Quantize(entityPos.x) + 31) & ~31);
    const std::int16_t newY = static_cast<std::int16_t>(
        (Quantize(entityPos.y) + 31) & ~31);
    const std::int16_t newZ = Quantize(entityPos.z);
    if (newX == xyz[0] && newY == xyz[1] && newZ == xyz[2]) return;
    xyz[0] = newX;
    xyz[1] = newY;
    xyz[2] = newZ;
    std::memset(cells, 1, sizeof(cells));
    if (aas != nullptr) {
        std::uint8_t reachable[64];
        std::memset(reachable, 1, sizeof(reachable));
        aas->ClipGridToAreas(idVec3(static_cast<float>(xyz[0]),
            static_cast<float>(xyz[1]), static_cast<float>(xyz[2])),
            areaNum, travelFlags, 32, 8, reachable);
        for (int index = 0; index < 64; ++index)
            if (reachable[index] == 0) cells[index] = 0;
    }
}

float idDeferredVisGrid::GetGridVisibility(const idVec3& worldPoint,
        idDeferredVisCache& cache, const float* const staggerZ,
        const int flags, idColor*, idColor*) {
    std::uint16_t start[3] = {
        static_cast<std::uint16_t>(Quantize(worldPoint.x)),
        static_cast<std::uint16_t>(Quantize(worldPoint.y)),
        static_cast<std::uint16_t>(Quantize(
            staggerZ != nullptr ? *staggerZ : worldPoint.z))
    };
    int resolved = 0;
    int visible = 0;
    for (int index = 0; index < 64; ++index) {
        if (cells[index] == 0) continue;
        const int x = index & 7;
        const int y = index >> 3;
        std::uint16_t end[3] = {
            static_cast<std::uint16_t>(static_cast<std::int16_t>(
                xyz[0] - 128 + x * 32)),
            static_cast<std::uint16_t>(static_cast<std::int16_t>(
                xyz[1] - 128 + y * 32)),
            static_cast<std::uint16_t>(xyz[2])
        };
        const std::uint8_t state = cache.GetVisQuery(start, end, flags);
        if (state == idDeferredVisCache::VIS_CLEAR) {
            ++visible;
            ++resolved;
        } else if (state == idDeferredVisCache::VIS_BLOCKED) {
            ++resolved;
        }
    }
    return resolved > 0 ? static_cast<float>(visible) / resolved : 0.0f;
}

void idDeferredVisGrid::DebugDrawGrid() const {
}
