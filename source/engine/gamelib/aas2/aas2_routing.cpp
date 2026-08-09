#include "gamelib/aas2/aas2_local.h"

#include "idlib/lib_print.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

namespace {

constexpr int ROUTE_INFINITY = 0x3FFFFFFF;

bool ReachAllowed(const aas2Reachability_t& reach, const int travelFlags) {
    return (reach.travelFlags & AAS_TFL_INVALID) == 0
        && (reach.travelFlags & travelFlags) != 0;
}

} // namespace

idAASRoutingCache::idAASRoutingCache(const int cacheSize)
    : type(0), size((std::max)(0, cacheSize)), cluster(0), areaNum(0),
      travelFlags(0), next(nullptr), prev(nullptr), time_next(nullptr),
      time_prev(nullptr), startTravelTime(0), reachabilities(nullptr),
      travelTimes(nullptr) {
    if (size > 0) {
        reachabilities = new std::uint8_t[size]();
        travelTimes = new std::uint16_t[size]();
    }
}

idAASRoutingCache::~idAASRoutingCache() {
    delete[] reachabilities;
    delete[] travelTimes;
}

void idAAS2Local::RoutingStats() const {
    idLibPrint::Printf("%6d kB routing cache\n", totalCacheMemory >> 10);
}

void idAAS2Local::UnlinkCache(idAASRoutingCache* const cache) {
    if (cache == nullptr) return;
    if (cache->time_next != nullptr) cache->time_next->time_prev = cache->time_prev;
    else cacheListEnd = cache->time_prev;
    if (cache->time_prev != nullptr) cache->time_prev->time_next = cache->time_next;
    else cacheListStart = cache->time_next;
    cache->time_next = nullptr;
    cache->time_prev = nullptr;
}

void idAAS2Local::LinkCache(idAASRoutingCache* const cache) {
    if (cache == nullptr) return;
    if (cache->time_next != nullptr || cache->time_prev != nullptr
        || cacheListStart == cache) UnlinkCache(cache);
    cache->time_prev = cacheListEnd;
    cache->time_next = nullptr;
    if (cacheListEnd != nullptr) cacheListEnd->time_next = cache;
    else cacheListStart = cache;
    cacheListEnd = cache;
}

int idAAS2Local::CalcTravelTime(const idVec3& start, const idVec3& end,
        const int travelFlags) const {
    const idVec3 delta = end - start;
    const float distance = std::sqrt(delta.x * delta.x + delta.y * delta.y
        + delta.z * delta.z);
    const float multiplier = (travelFlags & AAS_TFL_WATER) != 0
        ? waterSpeedMultiplier : groundSpeedMultiplier;
    return (std::max)(1, static_cast<int>(multiplier * distance));
}

int idAAS2Local::AreaTravelTime(const int areaNum, const idVec3& start,
        const idVec3& end) const {
    return file != nullptr && areaNum > 0 && areaNum < file->areas.Num()
        ? CalcTravelTime(start, end, file->areas[areaNum].travelFlags) : 0;
}

void idAAS2Local::CalculateAreaTravelTimes() {
    delete[] areaTravelTimes;
    areaTravelTimes = nullptr;
    numAreaTravelTimes = 0;
    if (file == nullptr) return;
    for (int areaNum = 1; areaNum < file->areas.Num(); ++areaNum) {
        const aas2Area_t& area = file->areas[areaNum];
        int count = 0;
        for (idIndex<short, invalidReachability_t> index = area.reach;
                index.IsValid();) {
            const int reachNum = index.Get();
            if (reachNum < 0 || reachNum >= file->reachabilities.Num()) break;
            ++count;
            index = file->reachabilities[reachNum].next;
        }
        numAreaTravelTimes += count * count;
    }
    if (numAreaTravelTimes > 0) {
        areaTravelTimes = new std::uint16_t[numAreaTravelTimes]();
    }
}

void idAAS2Local::SetupRoutingCache() {
    if (file == nullptr) return;
    areaCacheIndexSize = 0;
    const int clusterCount = file->clusters.Num();
    areaCacheIndex = clusterCount > 0
        ? new idAASRoutingCache**[clusterCount]() : nullptr;
    for (int cluster = 0; cluster < clusterCount; ++cluster) {
        const int count = (std::max)(0,
            file->clusters[cluster].numReachableAreas);
        areaCacheIndexSize += count;
        areaCacheIndex[cluster] = count > 0
            ? new idAASRoutingCache*[count]() : nullptr;
    }
    portalCacheIndexSize = file->areas.Num();
    portalCacheIndex = portalCacheIndexSize > 0
        ? new idAASRoutingCache*[portalCacheIndexSize]() : nullptr;
    areaUpdate = file->areas.Num() > 0
        ? new idRoutingUpdate[file->areas.Num()]() : nullptr;
    portalUpdate = file->portals.Num() >= 0
        ? new idRoutingUpdate[file->portals.Num() + 1]() : nullptr;
    goalAreaTravelTimes = file->areas.Num() > 0
        ? new std::uint16_t[file->areas.Num()]() : nullptr;
    cacheListStart = nullptr;
    cacheListEnd = nullptr;
    totalCacheMemory = 0;
}

void idAAS2Local::DeleteClusterCache(const int clusterNum) {
    if (file == nullptr || areaCacheIndex == nullptr || clusterNum < 0
        || clusterNum >= file->clusters.Num()) return;
    const int count = file->clusters[clusterNum].numReachableAreas;
    for (int slot = 0; slot < count; ++slot) {
        idAASRoutingCache* cache = areaCacheIndex[clusterNum][slot];
        areaCacheIndex[clusterNum][slot] = nullptr;
        while (cache != nullptr) {
            idAASRoutingCache* const nextCache = cache->next;
            UnlinkCache(cache);
            totalCacheMemory -= sizeof(*cache) + 3 * cache->size;
            delete cache;
            cache = nextCache;
        }
    }
}

void idAAS2Local::DeletePortalCache() {
    if (portalCacheIndex == nullptr) return;
    for (int slot = 0; slot < portalCacheIndexSize; ++slot) {
        idAASRoutingCache* cache = portalCacheIndex[slot];
        portalCacheIndex[slot] = nullptr;
        while (cache != nullptr) {
            idAASRoutingCache* const nextCache = cache->next;
            UnlinkCache(cache);
            totalCacheMemory -= sizeof(*cache) + 3 * cache->size;
            delete cache;
            cache = nextCache;
        }
    }
}

void idAAS2Local::ShutdownRoutingCache() {
    if (areaCacheIndex != nullptr && file != nullptr) {
        for (int cluster = 0; cluster < file->clusters.Num(); ++cluster) {
            DeleteClusterCache(cluster);
            delete[] areaCacheIndex[cluster];
        }
    }
    DeletePortalCache();
    delete[] areaCacheIndex;
    delete[] portalCacheIndex;
    delete[] areaUpdate;
    delete[] portalUpdate;
    delete[] goalAreaTravelTimes;
    areaCacheIndex = nullptr;
    portalCacheIndex = nullptr;
    areaUpdate = nullptr;
    portalUpdate = nullptr;
    goalAreaTravelTimes = nullptr;
    areaCacheIndexSize = 0;
    portalCacheIndexSize = 0;
    cacheListStart = nullptr;
    cacheListEnd = nullptr;
    totalCacheMemory = 0;
}

void idAAS2Local::SetupRouting() {
    if (file == nullptr) return;
    groundSpeedMultiplier = file->settings.groundSpeed != 0.0f
        ? 100.0f / file->settings.groundSpeed : 1.0f;
    waterSpeedMultiplier = file->settings.waterSpeed != 0.0f
        ? 100.0f / file->settings.waterSpeed : 1.0f;
    CalculateAreaTravelTimes();
    SetupRoutingCache();
}

void idAAS2Local::ShutdownRouting() {
    delete[] areaTravelTimes;
    areaTravelTimes = nullptr;
    numAreaTravelTimes = 0;
    ShutdownRoutingCache();
}

void idAAS2Local::RemoveRoutingCacheUsingArea(const int) {
    if (file == nullptr) return;
    for (int cluster = 0; cluster < file->clusters.Num(); ++cluster) {
        DeleteClusterCache(cluster);
    }
    DeletePortalCache();
}

bool idAAS2Local::ChangeAreaTravelFlags_r(int nodeNum,
        const idBounds& bounds, const int areaFlags,
        const int travelFlags, const bool set) {
    bool changed = false;
    if (file == nullptr || nodeNum == 0) return false;
    if (nodeNum < 0) {
        const int areaNum = -nodeNum;
        if (areaNum <= 0 || areaNum >= file->areas.Num()) return false;
        aas2Area_t& area = file->areas[areaNum];
        if ((area.flags & areaFlags) == 0) return false;
        const std::uint32_t oldFlags = area.travelFlags;
        area.travelFlags = set ? oldFlags | travelFlags
            : oldFlags & ~std::uint32_t(travelFlags);
        if (area.travelFlags != oldFlags) {
            RemoveRoutingCacheUsingArea(areaNum);
            changed = true;
        }
        return changed;
    }
    if (nodeNum >= file->nodes.Num()) return false;
    const aas2Node_t& node = file->nodes[nodeNum];
    if (node.planeNum >= static_cast<std::uint32_t>(file->planes.Num())) {
        return false;
    }
    const int side = bounds.PlaneSide(file->planes[node.planeNum], 0.1f);
    if (side != 1) changed |= ChangeAreaTravelFlags_r(node.children[0],
        bounds, areaFlags, travelFlags, set);
    if (side != 0) changed |= ChangeAreaTravelFlags_r(node.children[1],
        bounds, areaFlags, travelFlags, set);
    return changed;
}

bool idAAS2Local::ChangeAreaTravelFlags(const idBounds& bounds,
        const int areaFlags, const int travelFlags, const bool set) {
    if (file == nullptr || file->trees.Num() == 0) return false;
    idBounds expanded;
    expanded[0] = bounds[0] - file->settings.boundingBox[1];
    expanded[1] = bounds[1] - file->settings.boundingBox[0];
    return ChangeAreaTravelFlags_r(file->trees[0].headNode, expanded,
        areaFlags, travelFlags, set);
}

bool idAAS2Local::ChangeReachabilityTravelFlags(const char* const nameValue,
        const int travelFlags, const bool set) {
    if (file == nullptr) return false;
    const idIndex<short, invalidReachability_t> index =
        file->FindReachabilityByName(nameValue);
    return index.IsValid()
        && ChangeReachabilityTravelFlags(index, travelFlags, set);
}

bool idAAS2Local::ChangeReachabilityTravelFlags(
        const idIndex<short, invalidReachability_t> index,
        const int travelFlags, const bool set) {
    const int reachNum = index.Get();
    if (file == nullptr || reachNum < 0
        || reachNum >= file->reachabilities.Num()) return false;
    aas2Reachability_t& reach = file->reachabilities[reachNum];
    reach.travelFlags = set ? reach.travelFlags | travelFlags
        : reach.travelFlags & ~std::uint32_t(travelFlags);
    RemoveRoutingCacheUsingArea(reach.fromAreaNum);
    RemoveRoutingCacheUsingArea(reach.toAreaNum);
    return true;
}

idIndex<short, invalidReachability_t> idAAS2Local::GetAreaReachability(
        const int areaNum, int reachabilityNum) const {
    if (file == nullptr || areaNum <= 0 || areaNum >= file->areas.Num()) {
        return idIndex<short, invalidReachability_t>();
    }
    idIndex<short, invalidReachability_t> index = file->areas[areaNum].reach;
    while (index.IsValid() && reachabilityNum-- > 0) {
        const int value = index.Get();
        if (value < 0 || value >= file->reachabilities.Num()) {
            return idIndex<short, invalidReachability_t>();
        }
        index = file->reachabilities[value].next;
    }
    return index;
}

int idAAS2Local::ClusterAreaNum(const int clusterNum,
        const int areaNum) const {
    if (file == nullptr || areaNum <= 0 || areaNum >= file->areas.Num()) {
        return 0;
    }
    const aas2Area_t& area = file->areas[areaNum];
    if (area.cluster > 0) return area.clusterAreaNum;
    const int portalNum = -area.cluster;
    if (portalNum <= 0 || portalNum >= file->portals.Num()) return 0;
    const aas2Portal_t& portal = file->portals[portalNum];
    return portal.clusterAreaNum[clusterNum != portal.clusters[0] ? 1 : 0];
}

bool idAAS2Local::RouteToGoalArea(const int startAreaNum,
        const idVec3& startOrigin, const int goalAreaNum,
        const idVec3& goalOrigin, const int travelFlags,
        int& travelTime,
        idIndex<short, invalidReachability_t>& reachability) {
    travelTime = 0;
    reachability.Invalidate();
    if (file == nullptr || startAreaNum <= 0 || goalAreaNum <= 0
        || startAreaNum >= file->areas.Num()
        || goalAreaNum >= file->areas.Num()) return false;
    if (startAreaNum == goalAreaNum) {
        travelTime = AreaTravelTime(startAreaNum, startOrigin, goalOrigin);
        return true;
    }

    using queueValue_t = std::pair<int, int>;
    std::priority_queue<queueValue_t, std::vector<queueValue_t>,
        std::greater<queueValue_t>> queue;
    std::vector<int> costs(static_cast<std::size_t>(file->areas.Num()),
        ROUTE_INFINITY);
    std::vector<idIndex<short, invalidReachability_t>> firstReach(
        static_cast<std::size_t>(file->areas.Num()));
    costs[startAreaNum] = 0;
    queue.push(queueValue_t(0, startAreaNum));
    while (!queue.empty()) {
        const int cost = queue.top().first;
        const int areaNum = queue.top().second;
        queue.pop();
        if (cost != costs[areaNum]) continue;
        if (areaNum == goalAreaNum) break;
        const aas2Area_t& area = file->areas[areaNum];
        for (idIndex<short, invalidReachability_t> index = area.reach;
                index.IsValid();) {
            const int reachNum = index.Get();
            if (reachNum < 0 || reachNum >= file->reachabilities.Num()) break;
            const aas2Reachability_t& reach = file->reachabilities[reachNum];
            const idIndex<short, invalidReachability_t> next = reach.next;
            if (ReachAllowed(reach, travelFlags)
                && reach.toAreaNum > 0
                && reach.toAreaNum < file->areas.Num()) {
                const idVec3 from = reach.Start();
                const idVec3 to = reach.End();
                int stepCost = reach.travelTime;
                stepCost += AreaTravelTime(areaNum,
                    areaNum == startAreaNum ? startOrigin : from, from);
                stepCost += AreaTravelTime(reach.toAreaNum, from, to);
                const int nextCost = cost + (std::max)(1, stepCost);
                if (nextCost < costs[reach.toAreaNum]) {
                    costs[reach.toAreaNum] = nextCost;
                    firstReach[reach.toAreaNum] = areaNum == startAreaNum
                        ? index : firstReach[areaNum];
                    queue.push(queueValue_t(nextCost, reach.toAreaNum));
                }
            }
            index = next;
        }
    }
    if (costs[goalAreaNum] == ROUTE_INFINITY) return false;
    travelTime = costs[goalAreaNum]
        + AreaTravelTime(goalAreaNum, AreaCenter(goalAreaNum), goalOrigin);
    reachability = firstReach[goalAreaNum];
    return true;
}

int idAAS2Local::TravelTimeToGoalArea(const int startAreaNum,
        const idVec3& startOrigin, const int goalAreaNum,
        const idVec3& goalOrigin, const int travelFlags,
        const idAAS2TravelSpeeds*) {
    int time = 0;
    idIndex<short, invalidReachability_t> reachability;
    return RouteToGoalArea(startAreaNum, startOrigin, goalAreaNum,
        goalOrigin, travelFlags, time, reachability) ? time : 0;
}

bool idAAS2Local::FindNearestGoal(idAAS2Goal& goal,
        const int startAreaNum, const idVec3& startOrigin,
        const int travelFlags, idAAS2Callback& callback) {
    if (file == nullptr || startAreaNum <= 0
        || startAreaNum >= file->areas.Num()) return false;
    using queueValue_t = std::pair<int, int>;
    std::priority_queue<queueValue_t, std::vector<queueValue_t>,
        std::greater<queueValue_t>> queue;
    std::vector<int> costs(static_cast<std::size_t>(file->areas.Num()),
        ROUTE_INFINITY);
    costs[startAreaNum] = 0;
    queue.push(queueValue_t(0, startAreaNum));
    while (!queue.empty()) {
        const int cost = queue.top().first;
        const int areaNum = queue.top().second;
        queue.pop();
        if (cost != costs[areaNum]) continue;
        const idVec3 center = AreaCenter(areaNum);
        if (callback.AreaIsGoal(this, areaNum, &center)) {
            goal.areaNum = areaNum;
            goal.origin = center;
            return true;
        }
        const aas2Area_t& area = file->areas[areaNum];
        for (idIndex<short, invalidReachability_t> index = area.reach;
                index.IsValid();) {
            const int reachNum = index.Get();
            if (reachNum < 0 || reachNum >= file->reachabilities.Num()) break;
            const aas2Reachability_t& reach = file->reachabilities[reachNum];
            const idIndex<short, invalidReachability_t> next = reach.next;
            const idVec3 from = reach.Start();
            const idVec3 to = reach.End();
            if (ReachAllowed(reach, travelFlags)
                && callback.PathValid(this, &from, &to)) {
                const int extra = callback.AdditionalTravelTimeForPath(
                    this, &from, &to);
                const int nextCost = cost + reach.travelTime
                    + AreaTravelTime(areaNum, center, from) + extra;
                if (reach.toAreaNum > 0
                    && reach.toAreaNum < file->areas.Num()
                    && nextCost < costs[reach.toAreaNum]) {
                    costs[reach.toAreaNum] = nextCost;
                    queue.push(queueValue_t(nextCost, reach.toAreaNum));
                }
            }
            index = next;
        }
    }
    return false;
}

bool idAAS2Local::NearestPointReachable(
        const idIndex<int, invalidAASTree_t> tree, const idVec3& origin,
        const int areaNum, const idVec3& destination,
        const idBounds& searchBounds, const int travelFlags,
        idAAS2NearestReachable& nearest) const {
    std::memset(&nearest, 0, sizeof(nearest));
    if (file == nullptr || areaNum <= 0) return false;
    idBounds destinationBounds(searchBounds);
    destinationBounds[0] = destinationBounds[0] + destination;
    destinationBounds[1] = destinationBounds[1] + destination;
    int candidates[256] = {};
    const int count = file->BoundsAreaNums(tree.Get(), destinationBounds,
        candidates, 256);
    float nearestDistance = (std::numeric_limits<float>::max)();
    int quickestTime = ROUTE_INFINITY;
    bool found = false;
    for (int index = 0; index < count; ++index) {
        const int candidate = candidates[index];
        if (candidate <= 0 || candidate >= file->areas.Num()) continue;
        idVec3 point = destination;
        file->PushPointIntoAreaNum(candidate, point);
        const idVec3 delta = point - destination;
        const float distance = delta.x * delta.x + delta.y * delta.y
            + delta.z * delta.z;
        int time = 0;
        idIndex<short, invalidReachability_t> first;
        if (!const_cast<idAAS2Local*>(this)->RouteToGoalArea(areaNum,
                origin, candidate, point, travelFlags, time, first)) continue;
        if (distance < nearestDistance) {
            nearestDistance = distance;
            nearest.nearestDestArea = candidate;
            nearest.nearestDestPos = point;
            nearest.nearestTravelTime = time;
        }
        if (time < quickestTime) {
            quickestTime = time;
            nearest.quickestDestArea = candidate;
            nearest.quickestDestPos = point;
            nearest.quickestTravelTime = time;
        }
        found = true;
    }
    return found;
}

void idAAS2Local::DeleteOldestCache() {
    idAASRoutingCache* const cache = cacheListStart;
    if (cache == nullptr) return;
    if (cache->type == 0 && areaCacheIndex != nullptr
        && cache->cluster >= 0 && cache->cluster < file->clusters.Num()) {
        const int slot = ClusterAreaNum(cache->cluster, cache->areaNum);
        idAASRoutingCache** link = &areaCacheIndex[cache->cluster][slot];
        while (*link != nullptr && *link != cache) link = &(*link)->next;
        if (*link == cache) *link = cache->next;
    } else if (portalCacheIndex != nullptr && cache->areaNum >= 0
        && cache->areaNum < portalCacheIndexSize) {
        idAASRoutingCache** link = &portalCacheIndex[cache->areaNum];
        while (*link != nullptr && *link != cache) link = &(*link)->next;
        if (*link == cache) *link = cache->next;
    }
    UnlinkCache(cache);
    totalCacheMemory -= sizeof(*cache) + 3 * cache->size;
    delete cache;
}

void idAAS2Local::UpdateAreaRoutingCache(idAASRoutingCache* const cache) {
    if (cache == nullptr || file == nullptr) return;
    for (int area = 0; area < cache->size; ++area) {
        const int sourceArea = area + 1;
        if (sourceArea >= file->areas.Num()) break;
        int time = 0;
        idIndex<short, invalidReachability_t> first;
        if (RouteToGoalArea(sourceArea, AreaCenter(sourceArea),
                cache->areaNum, AreaCenter(cache->areaNum),
                cache->travelFlags, time, first)) {
            cache->travelTimes[area] = static_cast<std::uint16_t>(
                (std::min)(time, 65535));
            int ordinal = 0;
            for (idIndex<short, invalidReachability_t> index =
                    file->areas[sourceArea].reach; index.IsValid();
                    ++ordinal) {
                if (index == first) break;
                index = file->reachabilities[index.Get()].next;
            }
            cache->reachabilities[area] = static_cast<std::uint8_t>(ordinal);
        }
    }
}

idAASRoutingCache* idAAS2Local::GetAreaRoutingCache(const int clusterNum,
        const int areaNum, const int travelFlags) {
    if (file == nullptr || areaCacheIndex == nullptr || clusterNum < 0
        || clusterNum >= file->clusters.Num()) return nullptr;
    const int slot = ClusterAreaNum(clusterNum, areaNum);
    if (slot < 0 || slot >= file->clusters[clusterNum].numReachableAreas) {
        return nullptr;
    }
    idAASRoutingCache** link = &areaCacheIndex[clusterNum][slot];
    while (*link != nullptr && (*link)->travelFlags != travelFlags) {
        link = &(*link)->next;
    }
    if (*link == nullptr) {
        idAASRoutingCache* const cache =
            new idAASRoutingCache(file->areas.Num() - 1);
        cache->type = 0;
        cache->cluster = clusterNum;
        cache->areaNum = areaNum;
        cache->travelFlags = travelFlags;
        *link = cache;
        totalCacheMemory += sizeof(*cache) + 3 * cache->size;
        UpdateAreaRoutingCache(cache);
    }
    LinkCache(*link);
    return *link;
}

void idAAS2Local::UpdatePortalRoutingCache(idAASRoutingCache* const cache) {
    UpdateAreaRoutingCache(cache);
}

idAASRoutingCache* idAAS2Local::GetPortalRoutingCache(const int clusterNum,
        const int areaNum, const int travelFlags) {
    if (file == nullptr || portalCacheIndex == nullptr || areaNum < 0
        || areaNum >= portalCacheIndexSize) return nullptr;
    idAASRoutingCache** link = &portalCacheIndex[areaNum];
    while (*link != nullptr && (*link)->travelFlags != travelFlags) {
        link = &(*link)->next;
    }
    if (*link == nullptr) {
        idAASRoutingCache* const cache =
            new idAASRoutingCache(file->areas.Num() - 1);
        cache->type = 1;
        cache->cluster = clusterNum;
        cache->areaNum = areaNum;
        cache->travelFlags = travelFlags;
        *link = cache;
        totalCacheMemory += sizeof(*cache) + 3 * cache->size;
        UpdatePortalRoutingCache(cache);
    }
    LinkCache(*link);
    return *link;
}

bool idAAS2Local::GetClusterRoute(const int startAreaNum,
        const idVec3& startOrigin, const int, const int goalAreaNum,
        const int travelFlags, int& travelTime,
        idIndex<short, invalidReachability_t>& bestReachability) {
    return RouteToGoalArea(startAreaNum, startOrigin, goalAreaNum,
        AreaCenter(goalAreaNum), travelFlags, travelTime, bestReachability);
}
