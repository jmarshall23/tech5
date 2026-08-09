#include "gamelib/aas2/aas2_local.h"

#include "gamelib/physics/clip.h"

#include <algorithm>

idBounds idAAS2Local::DefaultSearchBounds() const {
    idBounds bounds{};
    if (file == nullptr) return bounds;
    bounds = file->settings.boundingBox;
    const float width = bounds[1].x - bounds[0].x;
    bounds[0].x = width * -0.5f;
    bounds[1].x = width * 0.5f;
    return bounds;
}

void idAAS2Local::ShowWalkPath(const int startAreaNum,
        const idVec3& startOrigin, const int goalAreaNum,
        const idVec3& goalOrigin, const int travelFlags,
        const int obstacleFlags, const int, const int,
        const int) const {
    if (file == nullptr) return;
    idAAS2Path path;
    const_cast<idAAS2Local*>(this)->WalkPathToGoal(path, startAreaNum,
        startOrigin, goalAreaNum, goalOrigin, travelFlags, obstacleFlags);
}

void idAAS2Local::ShowHopPath(const int startAreaNum,
        const idVec3& startOrigin, const int goalAreaNum,
        const idVec3& goalOrigin, const int travelFlags,
        const int obstacleFlags, const idAAS2HopPathParms& parms) const {
    if (file == nullptr) return;
    idAAS2Path path;
    idAAS2Local* const mutableThis = const_cast<idAAS2Local*>(this);
    if (mutableThis->WalkPathToGoal(path, startAreaNum, startOrigin,
            goalAreaNum, goalOrigin, travelFlags, obstacleFlags)) {
        mutableThis->ExtendHopPathToGoal(path, startAreaNum, startOrigin,
            goalAreaNum, goalOrigin, travelFlags, obstacleFlags, parms);
    }
}

void idAAS2Local::ShowOptimizedWalkPath(const int startAreaNum,
        const idVec3& startOrigin, const int goalAreaNum,
        const idVec3& goalOrigin, const int travelFlags,
        const int obstacleFlags) const {
    idList<idVec3, 5> points;
    const_cast<idAAS2Local*>(this)->GetOptimizedWalkPath(startAreaNum,
        startOrigin, goalAreaNum, goalOrigin, travelFlags, obstacleFlags,
        points);
}

void idAAS2Local::DrawEdge(const int edgeNum, const bool,
        const bool, const bool) const {
    if (file == nullptr) return;
    const int absoluteEdge = edgeNum < 0 ? -edgeNum : edgeNum;
    if (absoluteEdge <= 0 || absoluteEdge >= file->edges.Num()) return;
    const aas2Edge_t& edge = file->edges[absoluteEdge];
    if (edge.vertexNum[0] < 0 || edge.vertexNum[1] < 0
        || edge.vertexNum[0] >= file->vertices.Num()
        || edge.vertexNum[1] >= file->vertices.Num()) return;
    // Geometry is intentionally read and validated here. The engine renderer
    // consumes these endpoints when its debug-draw sink is attached.
    const idVec3& start = file->vertices[
        edgeNum < 0 ? edge.vertexNum[1] : edge.vertexNum[0]];
    const idVec3& end = file->vertices[
        edgeNum < 0 ? edge.vertexNum[0] : edge.vertexNum[1]];
    (void)start;
    (void)end;
}

void idAAS2Local::DrawReachability(
        const idIndex<short, invalidReachability_t> reachability,
        const aas2Reachability_t& reach, const char*) const {
    if (file == nullptr || reachability.Get() < 0
        || reachability.Get() >= file->reachabilities.Num()) return;
    const idVec3 start = reach.Start();
    const idVec3 end = reach.End();
    (void)start;
    (void)end;
    idList<int, 5> traversals;
    GetTraversalsForReachability(reachability, traversals);
    for (int index = 0; index < traversals.Num(); ++index) {
        const aas2Traversal_t* const traversal = GetTraversal(
            traversals[index]);
        (void)traversal;
    }
}

void idAAS2Local::DrawArea(const int areaNum,
        const bool showReachabilities, const bool showEdges,
        const bool, const bool, const bool, const bool) const {
    if (file == nullptr || areaNum <= 0 || areaNum >= file->areas.Num())
        return;
    const aas2Area_t& area = file->areas[areaNum];
    if (showEdges) {
        for (int index = 0; index < area.numEdges; ++index) {
            const int edgeIndex = area.firstEdge + index;
            if (edgeIndex >= 0 && edgeIndex < file->edgeIndex.Num())
                DrawEdge(file->edgeIndex[edgeIndex], false, false, false);
        }
    }
    if (showReachabilities) {
        idIndex<short, invalidReachability_t> reachability = area.reach;
        int guard = file->reachabilities.Num();
        while (reachability.Get() >= 0
                && reachability.Get() < file->reachabilities.Num()
                && guard-- > 0) {
            const aas2Reachability_t& reach =
                file->reachabilities[reachability.Get()];
            DrawReachability(reachability, reach, nullptr);
            reachability = reach.next;
        }
    }
}

void idAAS2Local::DrawCoverPoint(const aas2Cover_t& cover,
        const int index) const {
    if (file == nullptr || index < 0 || index >= file->cover.Num()) return;
    const idVec3 wallStart = cover.origin;
    const idVec3 wallEnd = cover.origin + cover.dir * 16.0f;
    (void)wallStart;
    (void)wallEnd;
}

void idAAS2Local::Test(const idVec3& origin,
        const idVec3& destination, const idMat3&, int areaNum,
        const int travelFlags, const int contentMask,
        const int debugMode, const int treeNum, idClip*, usercmd_t*,
        idAngles&) {
    if (file == nullptr) return;
    if (areaNum <= 0) {
        areaNum = PointReachableAreaNum(
            idIndex<int, invalidAASTree_t>(treeNum), origin,
            DefaultSearchBounds(), AAS_AREA_REACHABLE_WALK, 0);
    }
    const int goalAreaNum = PointReachableAreaNum(
        idIndex<int, invalidAASTree_t>(treeNum), destination,
        DefaultSearchBounds(), AAS_AREA_REACHABLE_WALK, 0);
    if (debugMode <= 0) {
        DrawArea(areaNum, true, true, true, true, true, true);
    } else if (debugMode == 1) {
        ShowWalkPath(areaNum, origin, goalAreaNum, destination,
            travelFlags, 0, contentMask, debugMode, treeNum);
    } else if (debugMode == 2) {
        idAAS2HopPathParms parms{};
        ShowHopPath(areaNum, origin, goalAreaNum, destination,
            travelFlags, 0, parms);
    } else {
        ShowOptimizedWalkPath(areaNum, origin, goalAreaNum, destination,
            travelFlags, 0);
    }
}
