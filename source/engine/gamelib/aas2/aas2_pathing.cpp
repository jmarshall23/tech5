#include "gamelib/aas2/aas2_local.h"

#include <algorithm>
#include <cmath>
#include <limits>

namespace {

float LengthSqr(const idVec3& value) {
    return value.x * value.x + value.y * value.y + value.z * value.z;
}

bool TraversalClassAllowed(const aas2Traversal_t& traversal,
        const int travelFlags) {
    const std::uint32_t flags = traversal.flags;
    return ((flags & 0x02000000u) != 0
            && (travelFlags & AAS_TFL_TRAVERSAL_CLASS_A) != 0)
        || ((flags & 0x04000000u) != 0
            && (travelFlags & AAS_TFL_TRAVERSAL_CLASS_B) != 0)
        || ((flags & 0x08000000u) != 0
            && (travelFlags & AAS_TFL_TRAVERSAL_CLASS_C) != 0)
        || ((flags & 0x10000000u) != 0
            && (travelFlags & AAS_TFL_TRAVERSAL_CLASS_D) != 0)
        || ((flags & 0x20000000u) != 0
            && (travelFlags & AAS_TFL_TRAVERSAL_CLASS_E) != 0);
}

int PathTypeForTravelFlags(const std::uint32_t flags) {
    if ((flags & AAS_TFL_WALKOFFLEDGE) != 0) return 1;
    if ((flags & AAS_TFL_BARRIERJUMP) != 0) return 2;
    if ((flags & AAS_TFL_LADDER) != 0) return 5;
    if ((flags & AAS_TFL_ELEVATOR) != 0) return 8;
    if ((flags & AAS_TFL_TELEPORT) != 0) return 9;
    return 0;
}

} // namespace

int idAAS2Local::GetTraversalsForReachability(
        const idIndex<short, invalidReachability_t> reachability,
        idList<int, 5>& traversals) const {
    return file != nullptr
        ? file->GetTraversalsForReachability(reachability, traversals) : 0;
}

int idAAS2Local::GetTraversalsForInteractableEntity(
        const idIndex<short, invalidAASInteractionEntIndex_t> entity,
        idList<int, 5>& traversals) const {
    return file != nullptr
        ? file->GetTraversalsForInteractableEntity(entity, traversals) : 0;
}

bool idAAS2Local::HopPathIsValid(const int startAreaNum,
        const idVec3& startOrigin, const int goalAreaNum,
        const idVec3& goalOrigin, const idAAS2HopPathParms& parms) const {
    if (file == nullptr || startAreaNum <= 0 || goalAreaNum <= 0
        || startAreaNum >= file->areas.Num()
        || goalAreaNum >= file->areas.Num()
        || (file->areas[goalAreaNum].flags & AAS_AREA_OUTSIDE) == 0) {
        return false;
    }
    const idVec3* const normal = file->GetFloorNormalForArea(startAreaNum);
    if (normal == nullptr) return false;
    const idVec3 delta = goalOrigin - startOrigin;
    const float vertical = delta.x * normal->x + delta.y * normal->y
        + delta.z * normal->z;
    const idVec3 planar = delta - *normal * vertical;
    if (LengthSqr(planar) > parms.maxDistance * parms.maxDistance) {
        return false;
    }
    idVec3 points[512];
    aas2TraceHeight_t trace{512, 0, points};
    file->TraceHeight(file->GetTreeForArea(startAreaNum).Get(), trace,
        startOrigin, goalOrigin);
    if (trace.numPoints >= 512) return false;
    for (int index = 1; index < trace.numPoints; ++index) {
        const idVec3 pointDelta = points[index] - startOrigin;
        const float pointVertical = pointDelta.x * normal->x
            + pointDelta.y * normal->y + pointDelta.z * normal->z;
        const idVec3 pointPlanar = pointDelta - *normal * pointVertical;
        float maximumHeight = std::sqrt(LengthSqr(pointPlanar))
            * parms.maxSlope;
        maximumHeight = (std::max)(parms.minHeight,
            (std::min)(parms.maxHeight, maximumHeight));
        if (pointVertical > maximumHeight) return false;
    }
    return true;
}

bool idAAS2Local::ExtendHopPathToGoal(idAAS2Path& path,
        const int startAreaNum, const idVec3& startOrigin,
        const int goalAreaNum, const idVec3& goalOrigin,
        const int travelFlags, const int obstacleFlags,
        const idAAS2HopPathParms& parms) {
    if (file == nullptr) return false;
    if (path.moveGoal.x == goalOrigin.x && path.moveGoal.y == goalOrigin.y
        && path.moveGoal.z == goalOrigin.z) {
        return HopPathIsValid(startAreaNum, startOrigin,
            path.moveAreaNum, path.moveGoal, parms);
    }
    if (HopPathIsValid(startAreaNum, startOrigin, goalAreaNum,
            goalOrigin, parms)) {
        path = idAAS2Path();
        path.type = 0;
        path.moveGoal = goalOrigin;
        path.moveAreaNum = goalAreaNum;
        path.obstacleGoal = goalOrigin;
        path.obstacleAreaNum = goalAreaNum;
        path.travelTime = AreaTravelTime(startAreaNum,
            startOrigin, goalOrigin);
        path.pathMaxHeight = (std::max)(0.0f,
            goalOrigin.z - startOrigin.z);
        path.obstacleRoute.numAreas = 1;
        path.obstacleRoute.areas[0].areaNum = startAreaNum;
        path.obstacleRoute.areas[0].start = startOrigin;
        path.obstacleRoute.areas[0].end = goalOrigin;
        return true;
    }
    if (!WalkPathToGoal(path, startAreaNum, startOrigin, goalAreaNum,
            goalOrigin, travelFlags, obstacleFlags)) return false;
    return HopPathIsValid(startAreaNum, startOrigin, path.moveAreaNum,
        path.moveGoal, parms);
}

bool idAAS2Local::GetPath(const idVec3& origin,
        const idVec3& goalOrigin, const int areaNum,
        const int goalAreaNum, const int travelFlags,
        idAAS2PathPoint* const points, const int maxPoints,
        int& numPoints) {
    numPoints = 0;
    if (file == nullptr || points == nullptr || maxPoints <= 0
        || areaNum <= 0 || goalAreaNum <= 0) return false;
    points[0].areaNum = areaNum;
    points[0].origin = origin;
    points[0].nextReachIndex.Invalidate();
    points[0].travelTime = 0;
    numPoints = 1;
    int currentArea = areaNum;
    idVec3 currentOrigin = origin;
    int cumulativeTime = 0;
    while (currentArea != goalAreaNum && numPoints < maxPoints) {
        int routeTime = 0;
        idIndex<short, invalidReachability_t> reachIndex;
        if (!RouteToGoalArea(currentArea, currentOrigin, goalAreaNum,
                goalOrigin, travelFlags, routeTime, reachIndex)
            || !reachIndex.IsValid()) break;
        const int reachNum = reachIndex.Get();
        if (reachNum < 0 || reachNum >= file->reachabilities.Num()) break;
        const aas2Reachability_t& reach = file->reachabilities[reachNum];
        points[numPoints - 1].nextReachIndex = reachIndex;
        cumulativeTime += reach.travelTime
            + AreaTravelTime(currentArea, currentOrigin, reach.Start());
        points[numPoints].areaNum = reach.toAreaNum;
        points[numPoints].origin = reach.End();
        points[numPoints].nextReachIndex.Invalidate();
        points[numPoints].travelTime = cumulativeTime;
        currentArea = reach.toAreaNum;
        currentOrigin = reach.End();
        ++numPoints;
    }
    if (currentArea != goalAreaNum) return false;
    if (numPoints < maxPoints) {
        points[numPoints].areaNum = goalAreaNum;
        points[numPoints].origin = goalOrigin;
        points[numPoints].nextReachIndex.Invalidate();
        points[numPoints].travelTime = cumulativeTime
            + AreaTravelTime(goalAreaNum, currentOrigin, goalOrigin);
        ++numPoints;
    } else {
        points[numPoints - 1].origin = goalOrigin;
    }
    return true;
}

bool idAAS2Local::WalkPathIsValid(const int startAreaNum,
        const idVec3& startOrigin, const int goalAreaNum,
        const idVec3& goalOrigin, const int travelFlags,
        int& endAreaNum, aas2EdgeCrossed_t& firstEdge) const {
    int areas[128] = {};
    idIndex<short, invalidReachability_t> reachIndices[128];
    aas2TraceFloor_t trace{};
    trace.maxAreas = 128;
    trace.areas = areas;
    trace.maxReachIndices = 128;
    trace.reachIndices = reachIndices;
    if (!TraceFloor(trace, startOrigin, startAreaNum, goalOrigin,
            travelFlags, true, false, true)) {
        endAreaNum = trace.lastAreaNum;
        firstEdge = trace.firstEdge;
        return false;
    }
    endAreaNum = trace.lastAreaNum;
    firstEdge = trace.firstEdge;
    return trace.lastAreaNum == goalAreaNum;
}

void idAAS2Local::SubSampleWalkPath(const int startAreaNum,
        const idVec3& startOrigin, const int pathAreaNum,
        const idVec3& pathStart, const idVec3& pathEnd,
        const int travelFlags, idVec3& endPos, int& endAreaNum,
        aas2EdgeCrossed_t& firstEdge) const {
    endPos = pathStart;
    endAreaNum = pathAreaNum;
    firstEdge = aas2EdgeCrossed_t{};
    const idVec3 delta = pathEnd - pathStart;
    float validFraction = 0.0f;
    for (int sample = 1; sample <= 8; ++sample) {
        const float fraction = float(sample) / 8.0f;
        const idVec3 candidate = pathStart + delta * fraction;
        int candidateArea = pathAreaNum;
        aas2EdgeCrossed_t candidateEdge{};
        if (!WalkPathIsValid(startAreaNum, startOrigin, pathAreaNum,
                candidate, travelFlags, candidateArea, candidateEdge)) break;
        validFraction = fraction;
        endPos = candidate;
        endAreaNum = candidateArea;
        if (firstEdge.edgeNum == 0 && candidateEdge.edgeNum != 0) {
            firstEdge = candidateEdge;
        }
    }
    if (validFraction == 0.0f) endPos = pathStart;
}

bool idAAS2Local::GetOptimizedWalkPath(const int startAreaNum,
        const idVec3& startOrigin, const int goalAreaNum,
        const idVec3& goalOrigin, const int travelFlags,
        const int, idList<idVec3, 5>& path) {
    path.Clear();
    idAAS2PathPoint rawPath[256];
    int count = 0;
    if (!GetPath(startOrigin, goalOrigin, startAreaNum, goalAreaNum,
            travelFlags, rawPath, 256, count)) return false;
    int anchor = 0;
    path.Append(rawPath[0].origin);
    while (anchor < count - 1) {
        int farthest = anchor + 1;
        for (int candidate = count - 1; candidate > anchor + 1;
                --candidate) {
            int endArea = rawPath[anchor].areaNum;
            aas2EdgeCrossed_t edge{};
            if (WalkPathIsValid(rawPath[anchor].areaNum,
                    rawPath[anchor].origin, rawPath[candidate].areaNum,
                    rawPath[candidate].origin, travelFlags, endArea, edge)) {
                farthest = candidate;
                break;
            }
        }
        path.Append(rawPath[farthest].origin);
        anchor = farthest;
    }
    return true;
}

bool idAAS2Local::WalkPathToGoal(idAAS2Path& path,
        const int startAreaNum, const idVec3& startOrigin,
        const int goalAreaNum, const idVec3& goalOrigin,
        const int travelFlags, const int) {
    path = idAAS2Path();
    path.type = 0;
    path.moveGoal = startOrigin;
    path.moveAreaNum = startAreaNum;
    path.obstacleGoal = startOrigin;
    path.obstacleAreaNum = startAreaNum;
    path.obstacleRoute.numAreas = 1;
    path.obstacleRoute.areas[0].areaNum = startAreaNum;
    path.obstacleRoute.areas[0].start = startOrigin;
    path.obstacleRoute.areas[0].end = startOrigin;
    if (file == nullptr) return false;
    if (startAreaNum == goalAreaNum) {
        path.moveGoal = goalOrigin;
        path.obstacleGoal = goalOrigin;
        path.travelTime = AreaTravelTime(startAreaNum,
            startOrigin, goalOrigin);
        path.obstacleRoute.areas[0].end = goalOrigin;
        path.pathMaxHeight = (std::max)(0.0f,
            goalOrigin.z - startOrigin.z);
        return true;
    }
    int routeTime = 0;
    idIndex<short, invalidReachability_t> reachIndex;
    if (!RouteToGoalArea(startAreaNum, startOrigin, goalAreaNum,
            goalOrigin, travelFlags, routeTime, reachIndex)
        || !reachIndex.IsValid()) return false;
    const aas2Reachability_t* const reach = GetReachability(reachIndex);
    if (reach == nullptr) return false;
    path.reachIndex = reachIndex;
    path.type = PathTypeForTravelFlags(reach->travelFlags);
    path.moveGoal = reach->Start();
    path.moveAreaNum = startAreaNum;
    path.obstacleGoal = path.moveGoal;
    path.obstacleAreaNum = startAreaNum;
    path.travelTime = routeTime;
    path.obstacleRoute.areas[0].end = path.moveGoal;
    path.pathMaxHeight = (std::max)(0.0f,
        path.moveGoal.z - startOrigin.z);

    idVec3 traversalStart;
    idVec3 traversalEnd;
    idIndex<short, invalidAASDependencyIndex_t> dependency;
    const int traversal = FindBestTraversalForReachability(reachIndex,
        startOrigin, goalOrigin, traversalStart, traversalEnd, dependency,
        travelFlags, false);
    if (traversal >= 0) {
        path.type = 9;
        path.traversalIndex = traversal;
        path.traversalStart = traversalStart;
        path.traversalEnd = traversalEnd;
        path.dependencyIndex = dependency;
        path.moveGoal = traversalStart;
    }
    return true;
}

int idAAS2Local::FindBestTraversalForReachability(
        const idIndex<short, invalidReachability_t> reachability,
        const idVec3& currentPoint, const idVec3& goalPoint,
        idVec3& traversalStart, idVec3& traversalEnd,
        idIndex<short, invalidAASDependencyIndex_t>& dependency,
        const int travelFlags, const bool useClosestPointOnFail) const {
    idList<int, 5> traversals;
    const int count = GetTraversalsForReachability(reachability, traversals);
    traversalStart.Zero();
    traversalEnd.Zero();
    dependency.Invalidate();
    int bestIndex = -1;
    float bestDistance = (std::numeric_limits<float>::max)();
    for (int index = 0; index < count; ++index) {
        const int traversalIndex = traversals[index];
        const aas2Traversal_t* const traversal = GetTraversal(traversalIndex);
        if (traversal == nullptr) continue;
        const bool enabled = (traversal->flags & 1u) != 0;
        if ((!enabled && !useClosestPointOnFail)
            || !TraversalClassAllowed(*traversal, travelFlags)) continue;
        const float distance = LengthSqr(traversal->startPoint - currentPoint)
            + LengthSqr(traversal->endPoint - goalPoint);
        if (distance < bestDistance) {
            bestDistance = distance;
            bestIndex = traversalIndex;
            traversalStart = traversal->startPoint;
            traversalEnd = traversal->endPoint;
            dependency = traversal->dependencyIndex;
        }
    }
    return bestIndex;
}
