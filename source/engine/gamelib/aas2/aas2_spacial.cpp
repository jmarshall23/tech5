#include "gamelib/aas2/aas2_local.h"

#include "idlib/lib_print.h"

#include <vector>

namespace {

bool BoundsIntersect(const idBounds& first, const idBounds& second) {
    for (int axis = 0; axis < 3; ++axis) {
        if (first[1][axis] < second[0][axis]
            || first[0][axis] > second[1][axis]) return false;
    }
    return true;
}

float DistanceSqr(const idVec3& first, const idVec3& second) {
    const idVec3 delta = first - second;
    return delta.x * delta.x + delta.y * delta.y + delta.z * delta.z;
}

} // namespace

int idAAS2Local::GetNumCoverPoints() const {
    return file != nullptr ? file->cover.Num() : 0;
}

const aas2Cover_t* idAAS2Local::GetCoverPoint(const int index) const {
    return file != nullptr && index >= 0 && index < file->cover.Num()
        ? &file->cover[index] : nullptr;
}

int idAAS2Local::GetNumAreaCoverPoints(const int areaNum) const {
    return file != nullptr && areaNum > 0 && areaNum < file->areas.Num()
        ? file->areas[areaNum].numCover : 0;
}

int idAAS2Local::GetAreaCoverPoints(const int areaNum, int* const points,
        const int maxPoints, int* const numPoints) const {
    if (numPoints != nullptr) *numPoints = 0;
    if (file == nullptr || areaNum <= 0 || areaNum >= file->areas.Num()
        || points == nullptr || numPoints == nullptr) return 0;
    const aas2Area_t& area = file->areas[areaNum];
    for (int index = 0; index < area.numCover; ++index) {
        if (*numPoints >= maxPoints) {
            idLibPrint::Warning(
                "idAAS2Local::GetAreaCoverPoints - search list overflowed.");
            break;
        }
        points[(*numPoints)++] = file->areaCoverIndex[area.firstCover + index];
    }
    return *numPoints;
}

void idAAS2Local::FindCoverPoints_Internal(const int startAreaNum,
        const idVec3& origin, const idBounds& bounds,
        const float maxDistSqr, const int requiredFlags,
        const int excludeFlags, const int travelFlags,
        int* const coverPoints, const int maxCover,
        int& numCover) const {
    if (file == nullptr || startAreaNum <= 0
        || startAreaNum >= file->areas.Num()) return;
    std::vector<std::uint8_t> visited(
        static_cast<std::size_t>(file->areas.Num()), 0);
    int queue[1280] = {};
    int first = 0;
    int last = 1;
    queue[0] = startAreaNum;
    visited[startAreaNum] = 1;
    while (first < last) {
        if (last >= 1280) return;
        const int areaNum = queue[first++];
        const aas2Area_t& area = file->areas[areaNum];
        for (int index = 0; index < area.numCover; ++index) {
            const int coverIndex =
                file->areaCoverIndex[area.firstCover + index];
            if (coverIndex < 0 || coverIndex >= file->cover.Num()) continue;
            const aas2Cover_t& coverPoint = file->cover[coverIndex];
            if ((requiredFlags != 0
                    && (coverPoint.flags & requiredFlags) == 0)
                || (coverPoint.flags & excludeFlags) != 0
                || DistanceSqr(coverPoint.origin, origin) >= maxDistSqr) {
                continue;
            }
            if (numCover >= maxCover) {
                idLibPrint::Warning(
                    "idAAS2Local::FindCoverPoints_Internal - search list overflowed.");
                return;
            }
            coverPoints[numCover++] = coverIndex;
        }
        for (idIndex<short, invalidReachability_t> reachIndex = area.reach;
                reachIndex.IsValid();) {
            const int index = reachIndex.Get();
            if (index < 0 || index >= file->reachabilities.Num()) break;
            const aas2Reachability_t& reach = file->reachabilities[index];
            const int nextArea = reach.toAreaNum;
            if (nextArea > 0 && nextArea < file->areas.Num()
                && visited[nextArea] == 0
                && (reach.travelFlags & travelFlags) != 0) {
                idBounds areaBounds;
                if (nextArea < file->areaBounds.Num()) {
                    areaBounds[0].Set(
                        float(file->areaBounds[nextArea].min[0]),
                        float(file->areaBounds[nextArea].min[1]),
                        float(file->areaBounds[nextArea].min[2]));
                    areaBounds[1].Set(
                        float(file->areaBounds[nextArea].max[0]),
                        float(file->areaBounds[nextArea].max[1]),
                        float(file->areaBounds[nextArea].max[2]));
                } else {
                    areaBounds = file->AreaBounds(nextArea);
                }
                if (BoundsIntersect(bounds, areaBounds) && last < 1280) {
                    visited[nextArea] = 1;
                    queue[last++] = nextArea;
                }
            }
            reachIndex = reach.next;
        }
    }
}

int idAAS2Local::FindCoverPoints(const int areaNum, const idVec3& origin,
        const float radius, const int requiredFlags, const int excludeFlags,
        const int travelFlags, int* const points, const int maxPoints,
        int* const numPoints) const {
    if (numPoints != nullptr) *numPoints = 0;
    if (areaNum <= 0 || points == nullptr || numPoints == nullptr
        || maxPoints <= 0) return 0;
    const idVec3 extent(radius, radius, radius);
    idBounds bounds;
    bounds[0] = origin - extent;
    bounds[1] = origin + extent;
    FindCoverPoints_Internal(areaNum, origin, bounds, radius * radius,
        requiredFlags, excludeFlags, travelFlags, points, maxPoints,
        *numPoints);
    return *numPoints;
}

int idAAS2Local::GetNumChokePoints() const {
    return file != nullptr ? file->chokePoints.Num() : 0;
}

const aas2ChokePoint_t* idAAS2Local::GetChokePoint(const int index) const {
    return file != nullptr && index >= 0 && index < file->chokePoints.Num()
        ? &file->chokePoints[index] : nullptr;
}

int idAAS2Local::GetNumHintNodes() const {
    return file != nullptr ? file->hintNodes.Num() : 0;
}

const aas2HintNode_t* idAAS2Local::GetHintNode(const int index) const {
    return file != nullptr && index >= 0 && index < file->hintNodes.Num()
        ? &file->hintNodes[index] : nullptr;
}
