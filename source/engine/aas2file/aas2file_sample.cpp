#include "aas2file/aas2file.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <limits>
#include <memory>
#include <vector>

namespace {

int AbsoluteEdge(const int edgeNum) {
    return edgeNum < 0 ? -edgeNum : edgeNum;
}

bool ValidArea(const idAAS2File& file, const int areaNum) {
    return areaNum > 0 && areaNum < file.areas.Num();
}

bool ValidEdge(const idAAS2File& file, const int edgeNum) {
    const int number = AbsoluteEdge(edgeNum);
    return number >= 0 && number < file.edges.Num();
}

idBounds EmptyBounds() {
    idBounds result;
    const float maximum = (std::numeric_limits<float>::max)();
    result[0].Set(maximum, maximum, maximum);
    result[1].Set(-maximum, -maximum, -maximum);
    return result;
}

void Include(idBounds& bounds, const idVec3& point) {
    for (int axis = 0; axis < 3; ++axis) {
        bounds[0][axis] = (std::min)(bounds[0][axis], point[axis]);
        bounds[1][axis] = (std::max)(bounds[1][axis], point[axis]);
    }
}

bool Intersects(const idBounds& left, const idBounds& right) {
    for (int axis = 0; axis < 3; ++axis) {
        if (left[1][axis] < right[0][axis]
            || left[0][axis] > right[1][axis]) return false;
    }
    return true;
}

bool AreaMatches(const aas2Area_t& area, const int requiredAreaFlags,
        const int excludedTravelFlags) {
    return (area.flags & requiredAreaFlags) != 0
        && (area.travelFlags & excludedTravelFlags) == 0;
}

void CollectBoundsAreas(const idAAS2File& file, const int nodeNum,
        const idBounds& bounds, std::vector<int>& result,
        const int maximum) {
    if (static_cast<int>(result.size()) >= maximum || nodeNum == 0) return;
    if (nodeNum < 0) {
        const int areaNum = -nodeNum;
        if (areaNum > 0
            && std::find(result.begin(), result.end(), areaNum) == result.end()) {
            result.push_back(areaNum);
        }
        return;
    }
    if (nodeNum >= file.nodes.Num()) return;
    const aas2Node_t& node = file.nodes[nodeNum];
    if (static_cast<int>(node.planeNum) >= file.planes.Num()) return;
    const int side = bounds.PlaneSide(file.planes[node.planeNum], 0.1f);
    if (side == 3) {
        CollectBoundsAreas(file, node.children[0], bounds, result, maximum);
        CollectBoundsAreas(file, node.children[1], bounds, result, maximum);
    } else {
        CollectBoundsAreas(file, node.children[side], bounds, result, maximum);
    }
}

void MarkBoundsAreas(const idAAS2File& file, const int nodeNum,
        const idBounds& bounds, bool* touched) {
    if (nodeNum == 0) return;
    if (nodeNum < 0) {
        touched[-nodeNum] = true;
        return;
    }
    if (nodeNum >= file.nodes.Num()) return;
    const aas2Node_t& node = file.nodes[nodeNum];
    if (static_cast<int>(node.planeNum) >= file.planes.Num()) return;
    const int side = bounds.PlaneSide(file.planes[node.planeNum], 0.1f);
    if (side == 3) {
        MarkBoundsAreas(file, node.children[0], bounds, touched);
        MarkBoundsAreas(file, node.children[1], bounds, touched);
    } else {
        MarkBoundsAreas(file, node.children[side], bounds, touched);
    }
}

struct TraceStackEntry {
    idVec3 start;
    idVec3 end;
    int planeNum;
    int nodeNum;
};

struct HeightTraceStackEntry {
    idVec3 start;
    idVec3 end;
    int planeNum;
    int nodeNum;
};

float SegmentFraction(const idVec3& start, const idVec3& end,
        const idVec3& point, const bool ignoreZ = false) {
    idVec3 delta = end - start;
    idVec3 traveled = point - start;
    if (ignoreZ) {
        delta.z = 0.0f;
        traveled.z = 0.0f;
    }
    const float lengthSquared = delta.LengthSqr();
    if (lengthSquared <= 1.0e-20f) return 0.0f;
    return (std::max)(0.0f, (std::min)(1.0f,
        traveled.Dot(delta) / lengthSquared));
}

void BuildFloorTracePlanes(const idVec3& floorNormal,
        const idVec3& start, const idVec3& end,
        idPlane& pathPlane, idPlane& nearPlane) {
    idVec3 pathNormal = floorNormal.Cross(end - start);
    pathNormal.NormalizeFast();
    idVec3 nearNormal = pathNormal.Cross(floorNormal);
    nearNormal.NormalizeFast();
    pathPlane = idPlane(pathNormal, pathNormal.Dot(start));
    nearPlane = idPlane(nearNormal, nearNormal.Dot(start));
}

bool SameVector(const idVec3& first, const idVec3& second) {
    return first.x == second.x && first.y == second.y
        && first.z == second.z;
}

} // namespace

idVec3 idAAS2File::AreaCenter(const int areaNum) const {
    idVec3 center(0.0f, 0.0f, 0.0f);
    if (!ValidArea(*this, areaNum)) return center;
    const aas2Area_t& area = areas[areaNum];
    int count = 0;
    for (int index = 0; index < area.numEdges; ++index) {
        const int edgeListIndex = area.firstEdge + index;
        if (edgeListIndex < 0 || edgeListIndex >= edgeIndex.Num()) continue;
        const int orientedEdge = edgeIndex[edgeListIndex];
        if (!ValidEdge(*this, orientedEdge)) continue;
        const aas2Edge_t& edge = edges[AbsoluteEdge(orientedEdge)];
        if (edge.vertexNum[0] < 0 || edge.vertexNum[0] >= vertices.Num()
            || edge.vertexNum[1] < 0 || edge.vertexNum[1] >= vertices.Num()) {
            continue;
        }
        center = center + (vertices[edge.vertexNum[0]]
            + vertices[edge.vertexNum[1]]) * 0.5f;
        ++count;
    }
    if (count > 0) center = center * (1.0f / static_cast<float>(count));
    return center;
}

idBounds idAAS2File::EdgeBounds(const int edgeNum) const {
    idBounds bounds = EmptyBounds();
    if (!ValidEdge(*this, edgeNum)) return bounds;
    const aas2Edge_t& edge = edges[AbsoluteEdge(edgeNum)];
    for (int endpoint = 0; endpoint < 2; ++endpoint) {
        if (edge.vertexNum[endpoint] >= 0
            && edge.vertexNum[endpoint] < vertices.Num()) {
            Include(bounds, vertices[edge.vertexNum[endpoint]]);
        }
    }
    return bounds;
}

idBounds idAAS2File::AreaBounds(const int areaNum) const {
    idBounds bounds = EmptyBounds();
    if (!ValidArea(*this, areaNum)) return bounds;
    const aas2Area_t& area = areas[areaNum];
    for (int index = 0; index < area.numEdges; ++index) {
        const int listIndex = area.firstEdge + index;
        if (listIndex < 0 || listIndex >= edgeIndex.Num()) continue;
        const idBounds edgeBounds = EdgeBounds(edgeIndex[listIndex]);
        Include(bounds, edgeBounds[0]);
        Include(bounds, edgeBounds[1]);
    }
    return bounds;
}

int idAAS2File::PointAreaNum(const int tree, const idVec3& origin) const {
    if (tree < 0 || tree >= trees.Num()) return 0;
    int nodeNum = trees[tree].headNode;
    int guard = 0;
    while (nodeNum > 0 && guard++ <= nodes.Num()) {
        if (nodeNum >= nodes.Num()) return 0;
        const aas2Node_t& node = nodes[nodeNum];
        if (static_cast<int>(node.planeNum) >= planes.Num()) return 0;
        nodeNum = node.children[planes[node.planeNum].Distance(origin) <= 0.0f];
    }
    return nodeNum < 0 ? -nodeNum : 0;
}

int idAAS2File::BoundsAreaNums(const int tree, const idBounds& bounds,
        int* const outputAreas, const int maxAreas) const {
    if (tree < 0 || tree >= trees.Num() || outputAreas == nullptr
        || maxAreas <= 0) return 0;
    std::vector<int> found;
    found.reserve((std::min)(maxAreas, 128));
    CollectBoundsAreas(*this, trees[tree].headNode, bounds, found, maxAreas);
    for (int index = 0; index < static_cast<int>(found.size()); ++index) {
        outputAreas[index] = found[index];
    }
    return static_cast<int>(found.size());
}

void idAAS2File::FlagBoundsAreas(const int tree, const idBounds& bounds,
        bool* const areasTouched) const {
    if (tree < 0 || tree >= trees.Num() || areasTouched == nullptr) return;
    MarkBoundsAreas(*this, trees[tree].headNode, bounds, areasTouched);
}

int idAAS2File::BoundsReachableAreaNum(const int tree,
        const idBounds& bounds, const std::uint16_t areaFlags,
        const int excludeTravelFlags) const {
    int found[256] = {};
    const int count = BoundsAreaNums(tree, bounds, found, 256);
    for (int index = 0; index < count; ++index) {
        const int areaNum = found[index];
        if (ValidArea(*this, areaNum)
            && AreaMatches(areas[areaNum], areaFlags, excludeTravelFlags)) {
            return areaNum;
        }
    }
    return 0;
}

bool idAAS2File::TraceHeight(const int tree, aas2TraceHeight_t& trace,
        const idVec3& start, const idVec3& end) const {
    if (tree < 0 || tree >= trees.Num()) return false;
    trace.numPoints = 0;
    std::vector<HeightTraceStackEntry> stack;
    stack.reserve(128);
    stack.push_back({ start, end, 0, trees[tree].headNode });
    while (!stack.empty()) {
        const HeightTraceStackEntry entry = stack.back();
        stack.pop_back();
        if (entry.nodeNum <= 0) continue;
        if (entry.nodeNum >= nodes.Num()) return false;
        const aas2Node_t& node = nodes[entry.nodeNum];
        if ((node.flags & 2u) != 0) {
            if (trace.points != nullptr && trace.numPoints < trace.maxPoints) {
                trace.points[trace.numPoints] = entry.start;
                trace.points[trace.numPoints].z = static_cast<float>(
                    static_cast<int>(node.flags >> 2) - 0x20000000);
                ++trace.numPoints;
            }
            continue;
        }
        if (static_cast<int>(node.planeNum) >= planes.Num()) return false;
        const idPlane& plane = planes[node.planeNum];
        const float firstDistance = plane.Distance(entry.start);
        const float secondDistance = plane.Distance(entry.end);
        if (firstDistance >= -0.1f && secondDistance >= -0.1f) {
            stack.push_back({ entry.start, entry.end, entry.planeNum,
                node.children[0] });
            continue;
        }
        if (firstDistance < 0.1f && secondDistance < 0.1f) {
            stack.push_back({ entry.start, entry.end, entry.planeNum,
                node.children[1] });
            continue;
        }

        float fraction = (firstDistance >= 0.0f
            ? firstDistance - 0.125f : firstDistance + 0.125f)
            / (firstDistance - secondDistance);
        fraction = (std::max)(0.001f, (std::min)(0.999f, fraction));
        const idVec3 middle = entry.start
            + (entry.end - entry.start) * fraction;
        const int firstSide = firstDistance < 0.0f ? 1 : 0;
        if (stack.size() + 2 > 128) return false;
        stack.push_back({ middle, entry.end,
            static_cast<int>(node.planeNum), node.children[1 - firstSide] });
        stack.push_back({ entry.start, middle, entry.planeNum,
            node.children[firstSide] });
    }
    return true;
}

bool idAAS2File::GetFloorEdgeSplitPoints(floorEdgeSplitPoint_t& nearest,
        floorEdgeSplitPoint_t& furthest, const int areaNum,
        const idPlane& pathPlane, const idPlane& nearPlane) const {
    nearest.point.Zero(); nearest.dist = 1.0e30f; nearest.edgeNum = 0;
    furthest.point.Zero(); furthest.dist = -1.0e30f; furthest.edgeNum = 0;
    if (!ValidArea(*this, areaNum)) return false;
    const aas2Area_t& area = areas[areaNum];
    int splits = 0;
    for (int index = 0; index < area.numEdges; ++index) {
        const int listIndex = area.firstEdge + index;
        if (listIndex < 0 || listIndex >= edgeIndex.Num()) continue;
        const int orientedEdge = edgeIndex[listIndex];
        if (!ValidEdge(*this, orientedEdge)) continue;
        const aas2Edge_t& edge = edges[AbsoluteEdge(orientedEdge)];
        const idVec3& first = vertices[edge.vertexNum[0]];
        const idVec3& second = vertices[edge.vertexNum[1]];
        const float firstSide = pathPlane.Distance(first);
        const float secondSide = pathPlane.Distance(second);
        if ((firstSide < 0.0f && secondSide < 0.0f)
            || (firstSide > 0.0f && secondSide > 0.0f)) continue;
        float fraction = 0.0f;
        if (std::fabs(firstSide - secondSide) > 1.0e-20f) {
            fraction = firstSide / (firstSide - secondSide);
        }
        fraction = (std::max)(0.0f, (std::min)(1.0f, fraction));
        const idVec3 split = first + (second - first) * fraction;
        const float distance = nearPlane.Distance(split);
        if (distance < nearest.dist) {
            nearest.point = split;
            nearest.dist = distance;
            nearest.edgeNum = orientedEdge;
        }
        if (distance > furthest.dist) {
            furthest.point = split;
            furthest.dist = distance;
            furthest.edgeNum = orientedEdge;
        }
        ++splits;
    }
    return splits != 0;
}

bool idAAS2File::Trace(const int tree, aas2Trace_t& trace,
        const idVec3& start, const idVec3& end) const {
    if (tree < 0 || tree >= trees.Num()) return false;
    trace.numAreas = 0;
    trace.lastAreaNum = 0;
    trace.blockingAreaNum = 0;
    std::vector<TraceStackEntry> stack;
    stack.reserve(128);
    stack.push_back({ start, end, 0, trees[tree].headNode });
    const idVec3 traceDirection = end - start;
    const float traceLength = traceDirection.Length();
    while (!stack.empty()) {
        const TraceStackEntry entry = stack.back();
        stack.pop_back();
        if (entry.nodeNum < 0) {
            const int areaNum = -entry.nodeNum;
            if (!ValidArea(*this, areaNum)) continue;
            const aas2Area_t& area = areas[areaNum];
            const bool areaBlocked = (area.flags & trace.flags) != 0
                || (area.travelFlags & trace.travelFlags) != 0;
            if (areaBlocked) {
                trace.fraction = trace.lastAreaNum != 0 && traceLength > 0.0f
                    ? (entry.start - start).Length() / traceLength : 0.0f;
                trace.endpos = entry.start;
                trace.planeNum = entry.planeNum;
                trace.blockingAreaNum = areaNum;
                if (entry.planeNum >= 0 && entry.planeNum < planes.Num()
                    && traceDirection.Dot(planes[entry.planeNum].Normal()) > 0.0f) {
                    trace.planeNum ^= 1;
                }
                return true;
            }
            trace.lastAreaNum = areaNum;
            if (trace.numAreas < trace.maxAreas) {
                if (trace.areas != nullptr) trace.areas[trace.numAreas] = areaNum;
                if (trace.points != nullptr) trace.points[trace.numAreas] = entry.start;
                ++trace.numAreas;
            }
            continue;
        }
        if (entry.nodeNum == 0) {
            trace.fraction = trace.lastAreaNum != 0 && traceLength > 0.0f
                ? (entry.start - start).Length() / traceLength : 0.0f;
            trace.endpos = entry.start;
            trace.planeNum = entry.planeNum;
            trace.blockingAreaNum = 0;
            if (entry.planeNum >= 0 && entry.planeNum < planes.Num()
                && traceDirection.Dot(planes[entry.planeNum].Normal()) > 0.0f) {
                trace.planeNum ^= 1;
            }
            if (trace.lastAreaNum != 0 || trace.getOutOfSolid == 0) return true;
            continue;
        }
        if (entry.nodeNum >= nodes.Num()) return false;
        const aas2Node_t& node = nodes[entry.nodeNum];
        if (static_cast<int>(node.planeNum) >= planes.Num()) return false;
        const idPlane& plane = planes[node.planeNum];
        const float firstDistance = plane.Distance(entry.start);
        const float secondDistance = plane.Distance(entry.end);
        if (firstDistance >= -0.1f && secondDistance >= -0.1f) {
            stack.push_back({ entry.start, entry.end, entry.planeNum,
                node.children[0] });
            continue;
        }
        if (firstDistance < 0.1f && secondDistance < 0.1f) {
            stack.push_back({ entry.start, entry.end, entry.planeNum,
                node.children[1] });
            continue;
        }

        float fraction = (firstDistance >= 0.0f
            ? firstDistance - 0.125f : firstDistance + 0.125f)
            / (firstDistance - secondDistance);
        fraction = (std::max)(0.001f, (std::min)(0.999f, fraction));
        const idVec3 middle = entry.start
            + (entry.end - entry.start) * fraction;
        const int firstSide = firstDistance < 0.0f ? 1 : 0;
        if (stack.size() + 2 > 128) return false;
        stack.push_back({ middle, entry.end, static_cast<int>(node.planeNum),
            node.children[1 - firstSide] });
        stack.push_back({ entry.start, middle, entry.planeNum,
            node.children[firstSide] });
    }
    trace.fraction = trace.lastAreaNum != 0 ? 1.0f : 0.0f;
    trace.endpos = trace.lastAreaNum != 0 ? end : start;
    trace.planeNum = 0;
    return false;
}

int idAAS2File::GetObstaclePVSWallEdges(const int areaNum,
        const int edgeFlags, int* const outputEdges, const int maxEdges) const {
    if (!ValidArea(*this, areaNum) || outputEdges == nullptr || maxEdges <= 0) {
        return 0;
    }
    std::vector<int> collected;
    collected.reserve(maxEdges);
    auto appendAreaEdges = [&](const int visibleArea) {
        if (!ValidArea(*this, visibleArea)) return;
        const aas2Area_t& area = areas[visibleArea];
        for (int index = 0; index < area.numEdges
                && static_cast<int>(collected.size()) < maxEdges; ++index) {
            const int listIndex = area.firstEdge + index;
            if (listIndex < 0 || listIndex >= edgeIndex.Num()) continue;
            const int edgeNum = edgeIndex[listIndex];
            if (!ValidEdge(*this, edgeNum)
                || (edges[AbsoluteEdge(edgeNum)].flags & edgeFlags) == 0) continue;
            collected.push_back(edgeNum);
        }
    };

    std::uint32_t offset = areas[areaNum].obstaclePVSOffset;
    int visibleArea = 0;
    while (offset < static_cast<std::uint32_t>(obstaclePVS.Num())
            && visibleArea < areas.Num()
            && static_cast<int>(collected.size()) < maxEdges) {
        const std::uint8_t encoded = obstaclePVS[offset++];
        if ((encoded & 0x80u) != 0) {
            int skip = encoded & 0x3Fu;
            if ((encoded & 0x40u) != 0
                && offset < static_cast<std::uint32_t>(obstaclePVS.Num())) {
                skip |= obstaclePVS[offset++] << 6;
            }
            visibleArea += skip + 1;
            continue;
        }
        for (int bit = 0; bit < 7 && visibleArea < areas.Num(); ++bit) {
            if ((encoded & (1u << bit)) != 0) appendAreaEdges(visibleArea);
            ++visibleArea;
        }
    }

    if (collected.empty()) return 0;
    if (static_cast<int>(collected.size()) >= maxEdges) {
        for (int index = 0; index < maxEdges; ++index) {
            outputEdges[index] = collected[index];
        }
        return maxEdges;
    }

    auto startVertex = [&](const int edgeNum) {
        const aas2Edge_t& edge = edges[AbsoluteEdge(edgeNum)];
        return edge.vertexNum[edgeNum < 0 ? 1 : 0];
    };
    auto endVertex = [&](const int edgeNum) {
        const aas2Edge_t& edge = edges[AbsoluteEdge(edgeNum)];
        return edge.vertexNum[edgeNum < 0 ? 0 : 1];
    };
    std::vector<std::vector<int>> chains;
    chains.reserve(collected.size());
    for (const int edgeNum : collected) chains.push_back({ edgeNum });
    for (std::size_t first = 0; first < chains.size(); ++first) {
        bool joined = true;
        while (joined) {
            joined = false;
            for (std::size_t second = first + 1; second < chains.size(); ++second) {
                if (endVertex(chains[first].back())
                        == startVertex(chains[second].front())) {
                    chains[first].insert(chains[first].end(),
                        chains[second].begin(), chains[second].end());
                } else if (endVertex(chains[second].back())
                        == startVertex(chains[first].front())) {
                    chains[first].insert(chains[first].begin(),
                        chains[second].begin(), chains[second].end());
                } else {
                    continue;
                }
                chains.erase(chains.begin() + second);
                joined = true;
                break;
            }
        }
    }
    int outputCount = 0;
    for (const std::vector<int>& chain : chains) {
        for (const int edgeNum : chain) outputEdges[outputCount++] = edgeNum;
    }
    return static_cast<int>(collected.size());
}

void idAAS2File::ClipGridToAreas(const idVec3& startOrigin,
        const int startAreaNum, const int travelFlags,
        const unsigned int cellSize, const int dimension,
        std::uint8_t* const reachable) const {
    if (reachable == nullptr || dimension <= 0 || cellSize == 0) return;
    const int cellCount = dimension * dimension;
    std::memset(reachable, 0, static_cast<std::size_t>(cellCount));
    if (!ValidArea(*this, startAreaNum)) return;

    const idIndex<int, invalidAASTree_t> treeIndex = GetTreeForArea(startAreaNum);
    const int treeNum = treeIndex.Get();
    if (treeNum < 0 || treeNum >= trees.Num()) return;
    const float half = 0.5f * static_cast<float>(cellSize * dimension);
    idBounds searchBounds;
    const idVec3 extents(half, half, half);
    searchBounds[0] = startOrigin - extents;
    searchBounds[1] = startOrigin + extents;
    std::unique_ptr<bool[]> areasTouched(new bool[areas.Num()]());
    FlagBoundsAreas(treeNum, searchBounds, areasTouched.get());

    std::vector<int> queue;
    queue.push_back(startAreaNum);
    areasTouched[startAreaNum] = false;
    for (std::size_t cursor = 0; cursor < queue.size() && queue.size() < 256; ++cursor) {
        const aas2Area_t& area = areas[queue[cursor]];
        int reachIndex = area.reach.Get();
        int guard = 0;
        while (reachIndex >= 0 && reachIndex < reachabilities.Num()
                && guard++ < reachabilities.Num()) {
            const aas2Reachability_t& reachability = reachabilities[reachIndex];
            const int target = reachability.toAreaNum;
            if (ValidArea(*this, target) && areasTouched[target]
                && (reachability.travelFlags & travelFlags) != 0
                && (reachability.travelFlags & ~travelFlags) == 0
                && (areas[target].travelFlags & travelFlags) != 0
                && (areas[target].travelFlags & ~travelFlags) == 0) {
                areasTouched[target] = false;
                queue.push_back(target);
            }
            reachIndex = reachability.next.Get();
        }
    }

    const idVec3& floorNormal = trees[treeNum].floorNormal;
    for (const int areaNum : queue) {
        const aas2Area_t& area = areas[areaNum];
        for (int y = 0; y < dimension; ++y) {
            for (int x = 0; x < dimension; ++x) {
                const idVec3 point(
                    startOrigin.x - half + (x + 0.5f) * cellSize,
                    startOrigin.y - half + (y + 0.5f) * cellSize,
                    startOrigin.z);
                bool inside = true;
                bool testedEdge = false;
                for (int edgeOffset = 0; edgeOffset < area.numEdges;
                        ++edgeOffset) {
                    const int listIndex = area.firstEdge + edgeOffset;
                    if (listIndex < 0 || listIndex >= edgeIndex.Num()) continue;
                    const int orientedEdge = edgeIndex[listIndex];
                    if (!ValidEdge(*this, orientedEdge)) continue;
                    const aas2Edge_t& edge = edges[AbsoluteEdge(orientedEdge)];
                    if ((edge.flags & AAS_EDGE_VERTICAL) != 0) continue;
                    const int firstIndex = orientedEdge < 0
                        ? edge.vertexNum[1] : edge.vertexNum[0];
                    const int secondIndex = orientedEdge < 0
                        ? edge.vertexNum[0] : edge.vertexNum[1];
                    if (firstIndex < 0 || firstIndex >= vertices.Num()
                        || secondIndex < 0 || secondIndex >= vertices.Num()) {
                        continue;
                    }
                    const idVec3& first = vertices[firstIndex];
                    idVec3 inward = (vertices[secondIndex] - first).Cross(floorNormal);
                    if (inward.NormalizeFast() == 0.0f) continue;
                    testedEdge = true;
                    if ((point - first).Dot(inward) < 0.0f) {
                        inside = false;
                        break;
                    }
                }
                if (inside && testedEdge) reachable[y * dimension + x] = 0xFF;
            }
        }
    }
}

float idAAS2File::GetFloorDistance(const int areaNum,
        const idPlane& floorPlane, const idVec3& point, const float bboxHeight,
        const float maxEdgeDist) const {
    if (!ValidArea(*this, areaNum)) return 1.0e30f;
    const idIndex<int, invalidAASTree_t> treeIndex = GetTreeForArea(areaNum);
    const idVec3* const floorNormal = GetFloorNormalForTree(treeIndex);
    if (floorNormal == nullptr) return 1.0e30f;
    const float denominator = floorNormal->Dot(floorPlane.Normal());
    if (std::fabs(denominator) <= 1.0e-20f) return 1.0e30f;
    float floorDistance = std::fabs(floorPlane.Distance(point)) / denominator;
    if (floorDistance < bboxHeight) return floorDistance;

    float nearestEdgeSquared = 1.0e30f;
    idVec3 nearestDelta(0.0f, 0.0f, 0.0f);
    const aas2Area_t& area = areas[areaNum];
    for (int index = 0; index < area.numEdges; ++index) {
        const int listIndex = area.firstEdge + index;
        if (listIndex < 0 || listIndex >= edgeIndex.Num()) continue;
        const int edgeNum = AbsoluteEdge(edgeIndex[listIndex]);
        if (edgeNum < 0 || edgeNum >= edges.Num()) continue;
        const aas2Edge_t& edge = edges[edgeNum];
        if (edge.vertexNum[0] < 0 || edge.vertexNum[0] >= vertices.Num()
            || edge.vertexNum[1] < 0 || edge.vertexNum[1] >= vertices.Num()) {
            continue;
        }
        const idVec3& first = vertices[edge.vertexNum[0]];
        const idVec3& second = vertices[edge.vertexNum[1]];
        const idVec3 segment = second - first;
        const float lengthSquared = segment.LengthSqr();
        if (lengthSquared < 0.1f) continue;
        float fraction = (point - first).Dot(segment) / lengthSquared;
        fraction = (std::max)(0.0f, (std::min)(1.0f, fraction));
        const idVec3 delta = point - (first + segment * fraction);
        const float distanceSquared = delta.LengthSqr();
        if (distanceSquared < nearestEdgeSquared) {
            nearestEdgeSquared = distanceSquared;
            nearestDelta = delta;
        }
    }
    if (nearestEdgeSquared < maxEdgeDist * maxEdgeDist) {
        const float edgeFloorDistance = std::fabs(floorNormal->Dot(nearestDelta));
        if (edgeFloorDistance < floorDistance) floorDistance = edgeFloorDistance;
    }
    return floorDistance;
}

void idAAS2File::PointBestReachableAreaNum(const int tree,
        const idVec3& origin, bestReachableArea_t& bestArea) const {
    if (tree < 0 || tree >= trees.Num()) return;
    int floorPlaneNum = -1;
    int nodeNum = trees[tree].headNode;
    while (nodeNum >= 0) {
        if (nodeNum == 0 || nodeNum >= nodes.Num()) return;
        const aas2Node_t& node = nodes[nodeNum];
        if (static_cast<int>(node.planeNum) >= planes.Num()) return;
        if (planes[node.planeNum].Distance(origin) <= 0.0f) {
            nodeNum = node.children[1];
        } else {
            nodeNum = node.children[0];
            if ((node.flags & 1u) != 0) {
                floorPlaneNum = static_cast<int>(node.planeNum);
            }
        }
    }
    const int areaNum = -nodeNum;
    if (!ValidArea(*this, areaNum) || floorPlaneNum < 0
        || !AreaMatches(areas[areaNum], bestArea.areaFlags,
            bestArea.excludeTravelFlags)) {
        return;
    }
    bestArea.pointAreaFloorDist = GetFloorDistance(areaNum,
        planes[floorPlaneNum], origin, bestArea.bboxHeight,
        bestArea.maxEdgeDist);
    bestArea.pointAreaNum = areaNum;
}

void idAAS2File::BoundsBestReachableAreaNum(const int tree,
        const idBounds& bounds, const idVec3& origin,
        bestReachableArea_t& bestArea) const {
    if (tree < 0 || tree >= trees.Num()) return;
    int floorPlaneNum = -1;
    std::vector<int> stack;
    int nodeNum = trees[tree].headNode;
    for (;;) {
        while (nodeNum > 0) {
            if (nodeNum >= nodes.Num()) return;
            const aas2Node_t& node = nodes[nodeNum];
            if (static_cast<int>(node.planeNum) >= planes.Num()) return;
            const int side = bounds.PlaneSide(planes[node.planeNum], 0.1f);
            if ((node.flags & 1u) != 0 && side != 1) {
                floorPlaneNum = static_cast<int>(node.planeNum);
            }
            if (side == 3) {
                stack.push_back(node.children[1]);
                nodeNum = node.children[0];
            } else {
                nodeNum = node.children[side];
            }
        }
        const int areaNum = -nodeNum;
        if (nodeNum < 0 && ValidArea(*this, areaNum) && floorPlaneNum >= 0
            && AreaMatches(areas[areaNum], bestArea.areaFlags,
                bestArea.excludeTravelFlags)) {
            const float floorDistance = GetFloorDistance(areaNum,
                planes[floorPlaneNum], origin, bestArea.bboxHeight,
                bestArea.maxEdgeDist);
            if (floorDistance < bestArea.pointAreaFloorDist
                    - bestArea.bboxHeight
                && floorDistance < bestArea.boundsAreaFloorDist) {
                bestArea.boundsAreaFloorDist = floorDistance;
                bestArea.boundsAreaNum = areaNum;
            }
        }
        if (stack.empty()) break;
        nodeNum = stack.back();
        stack.pop_back();
    }
}

int idAAS2File::PointReachableAreaNum(
        const idIndex<int, invalidAASTree_t> tree, const idVec3& origin,
        const int areaFlags, const int excludeTravelFlags) const {
    const int treeNum = tree.Get();
    if (treeNum < 0 || treeNum >= trees.Num()) return 0;

    bestReachableArea_t bestArea{};
    bestArea.bboxHeight = settings.boundingBox[1].z
        - settings.boundingBox[0].z;
    bestArea.maxEdgeDist = (std::min)(settings.boundingBox[1].x,
        settings.boundingBox[1].y) * 0.25f * 6.0f;
    bestArea.areaFlags = areaFlags;
    bestArea.excludeTravelFlags = excludeTravelFlags;
    bestArea.pointAreaFloorDist = 1.0e30f;
    bestArea.boundsAreaFloorDist = 1.0e30f;
    PointBestReachableAreaNum(treeNum, origin, bestArea);

    const float expansion = (std::min)(settings.boundingBox[1].x,
        settings.boundingBox[1].y) * 0.25f;
    idBounds search;
    search[0].Set(origin.x - expansion, origin.y - expansion, origin.z);
    search[1].Set(origin.x + expansion, origin.y + expansion, origin.z);
    for (int pass = 0; pass < 4; ++pass) {
        BoundsBestReachableAreaNum(treeNum, search, origin, bestArea);
        if (bestArea.boundsAreaNum != 0
            && bestArea.boundsAreaFloorDist < bestArea.bboxHeight * 2.0f) {
            break;
        }
        search[0] = search[0] - idVec3(expansion, expansion, expansion);
        search[1] = search[1] + idVec3(expansion, expansion, expansion);
    }
    return bestArea.boundsAreaNum != 0
        ? bestArea.boundsAreaNum : bestArea.pointAreaNum;
}

bool idAAS2File::PushPointIntoAreaNum(const int areaNum, idVec3& point) const {
    if (!ValidArea(*this, areaNum)) return false;
    const idIndex<int, invalidAASTree_t> treeIndex = GetTreeForArea(areaNum);
    const idVec3* floorNormal = GetFloorNormalForTree(treeIndex);
    if (floorNormal == nullptr) return false;
    const aas2Area_t& area = areas[areaNum];
    bool pushed = false;
    bool liesOnEdge = false;
    idVec3 nearestVertex = point;
    float nearestDistance = (std::numeric_limits<float>::max)();
    for (int index = 0; index < area.numEdges; ++index) {
        const int listIndex = area.firstEdge + index;
        if (listIndex < 0 || listIndex >= edgeIndex.Num()) continue;
        const int orientedEdge = edgeIndex[listIndex];
        if (!ValidEdge(*this, orientedEdge)) continue;
        const aas2Edge_t& edge = edges[AbsoluteEdge(orientedEdge)];
        if ((edge.flags & AAS_EDGE_VERTICAL) != 0) continue;
        const int firstIndex = orientedEdge < 0 ? edge.vertexNum[1] : edge.vertexNum[0];
        const int secondIndex = orientedEdge < 0 ? edge.vertexNum[0] : edge.vertexNum[1];
        const idVec3& first = vertices[firstIndex];
        const idVec3& second = vertices[secondIndex];
        const idVec3 edgeDirection = second - first;
        idVec3 inward = edgeDirection.Cross(*floorNormal);
        if (inward.NormalizeFast() == 0.0f) continue;
        const float distance = (point - first).Dot(inward);
        if (distance < 0.0f) {
            point = point - inward * distance;
            pushed = true;
        }
        const float firstDistance = (point - first).LengthSqr();
        if (firstDistance < nearestDistance) {
            nearestDistance = firstDistance;
            nearestVertex = first;
        }
        const float along = (point - first).Dot(edgeDirection);
        if (std::fabs(distance) < 0.1f && along >= 0.0f
            && along <= edgeDirection.LengthSqr()) liesOnEdge = true;
    }
    if (pushed && !liesOnEdge) point = nearestVertex;
    return pushed;
}

bool idAAS2File::TraceFloor(aas2TraceFloor_t& trace,
        const idVec3& start, const int startAreaNum, const idVec3& end,
        int endAreaNum, const int travelFlags,
        const bool allowFloorNormalChange,
        const bool ignoreGravityDirectionDistance,
        const bool ignoreSameArea) const {
    trace.fraction = 0.0f;
    trace.endpos = start;
    trace.lastAreaNum = startAreaNum;
    trace.firstEdge = { 0, 0, start };
    trace.lastEdge = { 0, 0, start };
    trace.numAreas = 0;
    trace.numReachIndices = 0;
    if (!ValidArea(*this, startAreaNum)) return false;

    const idVec3* initialFloorNormal = GetFloorNormalForArea(startAreaNum);
    if (initialFloorNormal == nullptr) return false;
    idVec3 floorNormal = *initialFloorNormal;
    idPlane pathPlane;
    idPlane nearPlane;
    BuildFloorTracePlanes(floorNormal, start, end, pathPlane, nearPlane);
    const idPlane endPlane(nearPlane.Normal(), nearPlane.Normal().Dot(end));
    if (endAreaNum == 0) endAreaNum = PointAreaNum(0, end);

    floorEdgeSplitPoint_t nearest;
    floorEdgeSplitPoint_t furthest;
    if (!GetFloorEdgeSplitPoints(nearest, furthest, startAreaNum,
            pathPlane, nearPlane)) {
        nearest = { start, 0.0f, 0 };
        furthest = nearest;
    }

    // The recovered routine uses the file's mutable flood flags as scratch
    // storage, then clears them before returning.  Keeping the identical
    // visited set locally preserves const behavior on the PC port.
    std::vector<std::uint8_t> visited(static_cast<std::size_t>(areas.Num()), 0);
    std::vector<int> visitedOrder;
    visitedOrder.reserve(256);
    int currentAreaNum = startAreaNum;

    for (;;) {
        if (trace.areas != nullptr && trace.numAreas < trace.maxAreas) {
            trace.areas[trace.numAreas++] = currentAreaNum;
        }
        visited[currentAreaNum] = 1;
        visitedOrder.push_back(currentAreaNum);

        if ((currentAreaNum == endAreaNum
                || endPlane.Distance(furthest.point) > 0.1f)
                && ignoreSameArea) {
            trace.endpos = end;
            trace.fraction = 1.0f;
            break;
        }

        trace.lastAreaNum = currentAreaNum;
        trace.endpos = furthest.point;
        trace.lastEdge.edgeNum = furthest.edgeNum;
        trace.lastEdge.edgePoint = furthest.point;
        nearPlane.SetDist(nearPlane.Normal().Dot(trace.endpos));

        const std::size_t visitedBase = visitedOrder.size();
        int acceptedReachIndex = -1;
        int reachIndex = areas[currentAreaNum].reach.Get();
        int guard = 0;
        while (reachIndex >= 0 && reachIndex < reachabilities.Num()
                && guard++ < reachabilities.Num()) {
            const aas2Reachability_t& reachability = reachabilities[reachIndex];
            const int targetAreaNum = reachability.toAreaNum;
            const std::uint32_t reachTravelFlags = reachability.travelFlags;
            const bool validTravel = (reachTravelFlags & travelFlags) != 0
                && (reachTravelFlags & ~static_cast<std::uint32_t>(travelFlags)) == 0;
            const bool validTarget = ValidArea(*this, targetAreaNum)
                && (areas[targetAreaNum].travelFlags & travelFlags) != 0
                && (areas[targetAreaNum].travelFlags
                    & ~static_cast<std::uint32_t>(travelFlags)) == 0
                && visited[targetAreaNum] == 0;
            if (!validTravel || !validTarget) {
                reachIndex = reachability.next.Get();
                continue;
            }

            // This append intentionally precedes the geometric tests: the
            // original records every otherwise eligible reachability it tries.
            if (trace.reachIndices != nullptr
                    && trace.numReachIndices < trace.maxReachIndices) {
                trace.reachIndices[trace.numReachIndices++] =
                    idIndex<short, invalidReachability_t>(
                        static_cast<short>(reachIndex));
            }
            visited[targetAreaNum] = 1;
            visitedOrder.push_back(targetAreaNum);

            const idVec3* targetFloorNormal =
                GetFloorNormalForArea(targetAreaNum);
            if (targetFloorNormal == nullptr) {
                reachIndex = reachability.next.Get();
                continue;
            }

            bool accepted = false;
            bool changedFloorNormal = false;
            idPlane candidatePathPlane = pathPlane;
            idPlane candidateNearPlane = nearPlane;
            if (allowFloorNormalChange
                    && !SameVector(*targetFloorNormal, floorNormal)) {
                BuildFloorTracePlanes(*targetFloorNormal, start, end,
                    candidatePathPlane, candidateNearPlane);
                candidateNearPlane.SetDist(
                    candidateNearPlane.Normal().Dot(trace.endpos));
                GetFloorEdgeSplitPoints(nearest, furthest, targetAreaNum,
                    candidatePathPlane, candidateNearPlane);
                accepted = nearest.dist < 1.0e30f && furthest.dist >= 0.1f;
                changedFloorNormal = accepted;
            } else {
                GetFloorEdgeSplitPoints(nearest, furthest, targetAreaNum,
                    pathPlane, nearPlane);
                if (nearest.dist < 1.0e30f && furthest.dist >= -0.1f) {
                    const bool fly =
                        (reachTravelFlags & AAS_TFL_FLY) != 0;
                    idVec3 delta = trace.endpos - nearest.point;
                    if (fly && std::fabs(furthest.dist)
                            < std::fabs(nearest.dist)) {
                        delta = trace.endpos - furthest.point;
                    }
                    const float gravityDistance = delta.Dot(floorNormal);
                    const idVec3 gravityDelta =
                        floorNormal * gravityDistance;
                    const idVec3 horizontalDelta = delta - gravityDelta;
                    accepted = (fly || gravityDelta.LengthSqr()
                            <= settings.maxStepHeight * settings.maxStepHeight)
                        && (fly || horizontalDelta.LengthSqr()
                            <= 0.040000003f);
                }
            }

            if (accepted) {
                acceptedReachIndex = reachIndex;
                currentAreaNum = targetAreaNum;
                if (changedFloorNormal) {
                    floorNormal = *targetFloorNormal;
                    pathPlane = candidatePathPlane;
                    nearPlane = candidateNearPlane;
                }
                break;
            }
            reachIndex = reachability.next.Get();
        }

        if (acceptedReachIndex < 0) break;
        for (std::size_t index = visitedBase; index < visitedOrder.size(); ++index) {
            visited[visitedOrder[index]] = 0;
        }
        visitedOrder.resize(visitedBase);
        if (trace.firstEdge.edgeNum == 0) {
            trace.firstEdge.toAreaNum = currentAreaNum;
            trace.firstEdge.edgeNum = nearest.edgeNum;
            trace.firstEdge.edgePoint = nearest.point;
        }
    }

    if (trace.fraction != 1.0f) {
        const idVec3 total = end - start;
        const float totalDistanceSquared = total.LengthSqr();
        if (std::fabs(totalDistanceSquared) <=
                (std::numeric_limits<float>::min)()) {
            trace.fraction = 0.0f;
        } else {
            idVec3 traveled = trace.endpos - start;
            if (ignoreGravityDirectionDistance) traveled.z = 0.0f;
            trace.fraction = std::sqrt(
                traveled.LengthSqr() / totalDistanceSquared);
        }
    }
    trace.lastEdge.toAreaNum = currentAreaNum;
    return true;
}
