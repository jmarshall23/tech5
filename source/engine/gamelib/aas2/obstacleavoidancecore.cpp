#include "gamelib/aas2/obstacleavoidancecore.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <limits>
#include <vector>

namespace {

float Cross2(const idVec2& first, const idVec2& second) {
    return first.x * second.y - first.y * second.x;
}

idVec2 Sub2(const idVec2& first, const idVec2& second) {
    return idVec2(first.x - second.x, first.y - second.y);
}

float Dot2(const idVec2& first, const idVec2& second) {
    return first.x * second.x + first.y * second.y;
}

float Length2(const idVec2& value) {
    return std::sqrt(Dot2(value, value));
}

idVec2 Normalize2(const idVec2& value) {
    const float length = Length2(value);
    return length > 1.0e-6f
        ? idVec2(value.x / length, value.y / length) : idVec2(0.0f, 0.0f);
}

float SegmentPointDistanceSqr(const idVec2& start, const idVec2& end,
        const idVec2& point) {
    const idVec2 delta = Sub2(end, start);
    const float lengthSqr = Dot2(delta, delta);
    float fraction = lengthSqr > 0.0f
        ? Dot2(Sub2(point, start), delta) / lengthSqr : 0.0f;
    fraction = (std::max)(0.0f, (std::min)(1.0f, fraction));
    const idVec2 closest(start.x + delta.x * fraction,
        start.y + delta.y * fraction);
    return Dot2(Sub2(point, closest), Sub2(point, closest));
}

bool SegmentIntersection(const idVec2& a, const idVec2& b,
        const idVec2& c, const idVec2& d) {
    const idVec2 r = Sub2(b, a);
    const idVec2 s = Sub2(d, c);
    const float denominator = Cross2(r, s);
    if (std::fabs(denominator) < 1.0e-6f) return false;
    const idVec2 delta = Sub2(c, a);
    const float t = Cross2(delta, s) / denominator;
    const float u = Cross2(delta, r) / denominator;
    return t >= 0.0f && t <= 1.0f && u >= 0.0f && u <= 1.0f;
}

} // namespace

idObstacleAvoidanceCore::idObstacleAvoidanceCore()
    : bspNodes(nullptr), numBspNodes(0), obstacleIndices(nullptr),
      expandedObstacles(nullptr), maxExpandedObstacles(0),
      numExpandedObstacles(0), windingPoints(nullptr), maxWindingPoints(0),
      numWindingPoints(0), tempMemory(nullptr), tempMemorySize(0),
      tempMemoryStart(nullptr), tempMemoryEnd(nullptr), pathNodes(nullptr),
      maxPathNodes(0), numPathNodes(0), debugLines(nullptr),
      maxDebugLines(0), numDebugLines(0), debugText(nullptr),
      maxDebugText(0), numDebugText(0), inputTransformValid(false),
      inputTransform(), flags(0) {
}

idObstacleAvoidanceCore::~idObstacleAvoidanceCore() = default;

void idObstacleAvoidanceCore::AddDebugLine(const avoidColor_t color,
        const idVec2& start, const idVec2& end) {
    if (debugLines == nullptr || numDebugLines >= maxDebugLines - 1) return;
    avoidDebugLine_t& line = debugLines[numDebugLines++];
    line.color = color;
    line.start.Set(start.x, start.y, 0.0f);
    line.end.Set(end.x, end.y, 0.0f);
}

void idObstacleAvoidanceCore::AddDebugInt(const avoidColor_t color,
        const idVec2& position, const int value) {
    if (debugText == nullptr || numDebugText >= maxDebugText - 1) return;
    avoidDebugText_t& text = debugText[numDebugText++];
    std::snprintf(text.text, sizeof(text.text), "%d", value);
    text.pos.Set(position.x, position.y, 0.0f);
    text.color = color;
}

int idObstacleAvoidanceCore::BoxParallelProjectionSilhouetteVerts(
        const idMat3& axis, const idVec3& center, const idVec3& extents,
        const idVec3& projectionDir, idVec3* const silhouette) {
    if (silhouette == nullptr) return 0;
    idVec3 corners[8];
    int count = 0;
    for (int x = -1; x <= 1; x += 2) {
        for (int y = -1; y <= 1; y += 2) {
            for (int z = -1; z <= 1; z += 2) {
                corners[count++] = center + axis[0] * (extents.x * x)
                    + axis[1] * (extents.y * y)
                    + axis[2] * (extents.z * z);
            }
        }
    }
    int output = 0;
    for (int index = 0; index < 8 && output < 6; ++index) {
        const float facing = (corners[index] - center).Dot(projectionDir);
        if (facing <= 0.0f) silhouette[output++] = corners[index];
    }
    return output;
}

void idObstacleAvoidanceCore::GetCirclePoints(const idVec2& center,
        const float radius, idVec2* const points) {
    if (points == nullptr) return;
    constexpr float diagonal = 0.70710678118f;
    const idVec2 directions[8] = {
        idVec2(1, 0), idVec2(diagonal, diagonal), idVec2(0, 1),
        idVec2(-diagonal, diagonal), idVec2(-1, 0),
        idVec2(-diagonal, -diagonal), idVec2(0, -1),
        idVec2(diagonal, -diagonal)
    };
    for (int index = 0; index < 8; ++index) {
        points[index].Set(center.x + directions[index].x * radius,
            center.y + directions[index].y * radius);
    }
}

idVec3 idObstacleAvoidanceCore::Plane2DFromPoints(const idVec2& start,
        const idVec2& end, const bool normalize) {
    return Plane2DFromVecs(start, Sub2(end, start), normalize);
}

idVec3 idObstacleAvoidanceCore::Plane2DFromVecs(const idVec2& start,
        const idVec2& direction, const bool normalize) {
    idVec2 normal(-direction.y, direction.x);
    if (normalize) normal = Normalize2(normal);
    return idVec3(normal.x, normal.y,
        -(normal.x * start.x + normal.y * start.y));
}

bool idObstacleAvoidanceCore::PointInsideWinding(const idVec2* const winding,
        const int numPoints, const idVec2& point, const float epsilon) {
    if (winding == nullptr || numPoints <= 0) return true;
    float sign = 0.0f;
    for (int index = 0; index < numPoints; ++index) {
        const float side = Cross2(Sub2(winding[(index + 1) % numPoints],
            winding[index]), Sub2(point, winding[index]));
        if (std::fabs(side) <= epsilon) continue;
        if (sign == 0.0f) sign = side;
        else if ((sign < 0.0f) != (side < 0.0f)) return false;
    }
    return true;
}

void idObstacleAvoidanceCore::ExpandWinding(const idVec2* const winding,
        const int numPoints, const float distance, idVec2* const expanded) {
    if (winding == nullptr || expanded == nullptr || numPoints <= 0) return;
    for (int index = 0; index < numPoints; ++index) {
        const idVec2 previous = winding[(index + numPoints - 1) % numPoints];
        const idVec2 current = winding[index];
        const idVec2 next = winding[(index + 1) % numPoints];
        const idVec2 first = Normalize2(idVec2(
            -(current.y - previous.y), current.x - previous.x));
        const idVec2 second = Normalize2(idVec2(
            -(next.y - current.y), next.x - current.x));
        idVec2 direction = Normalize2(idVec2(first.x + second.x,
            first.y + second.y));
        const float denominator = (std::max)(0.1f,
            std::fabs(Dot2(direction, first)));
        expanded[index].Set(current.x + direction.x * distance / denominator,
            current.y + direction.y * distance / denominator);
    }
}

void idObstacleAvoidanceCore::GetWindingBounds(
        const idVec2* const winding, const int numPoints,
        idVec2 bounds[2]) {
    const float maximum = (std::numeric_limits<float>::max)();
    bounds[0].Set(maximum, maximum);
    bounds[1].Set(-maximum, -maximum);
    for (int index = 0; index < numPoints; ++index) {
        bounds[0].x = (std::min)(bounds[0].x, winding[index].x);
        bounds[0].y = (std::min)(bounds[0].y, winding[index].y);
        bounds[1].x = (std::max)(bounds[1].x, winding[index].x);
        bounds[1].y = (std::max)(bounds[1].y, winding[index].y);
    }
}

bool idObstacleAvoidanceCore::WindingRayIntersection(
        const idVec2* const winding, const int numPoints,
        const idVec2& start, const idVec2& direction, float& firstScale,
        float& secondScale, int edgeNums[2]) {
    firstScale = (std::numeric_limits<float>::max)();
    secondScale = -(std::numeric_limits<float>::max)();
    int intersections = 0;
    for (int index = 0; index < numPoints; ++index) {
        const idVec2 edgeStart = winding[index];
        const idVec2 edge = Sub2(winding[(index + 1) % numPoints], edgeStart);
        const float denominator = Cross2(direction, edge);
        if (std::fabs(denominator) < 1.0e-6f) continue;
        const idVec2 delta = Sub2(edgeStart, start);
        const float scale = Cross2(delta, edge) / denominator;
        const float edgeScale = Cross2(delta, direction) / denominator;
        if (edgeScale < 0.0f || edgeScale > 1.0f) continue;
        if (scale < firstScale) {
            firstScale = scale;
            if (edgeNums != nullptr) edgeNums[0] = index;
        }
        if (scale > secondScale) {
            secondScale = scale;
            if (edgeNums != nullptr) edgeNums[1] = index;
        }
        ++intersections;
    }
    return intersections >= 2;
}

void idObstacleAvoidanceCore::FindPathAroundObstacles(obstaclePath_t& path,
        avoidDebugLine_t* const outputDebugLines, const int outputMaxDebugLines,
        avoidDebugText_t* const outputDebugText, const int outputMaxDebugText,
        std::uint8_t* const temp, const int tempSize, const idBounds&,
        const idVec3&, const idVec3& lastDir, const idVec4& lastCorner,
        const float obstacleRadius, const float frameMoveDist,
        const float, const int queryFlags, const obstacleRoute_t& route,
        const obstacleBox_t* const obstacles, const int numObstacles,
        const obstacleVertex_t* const vertices, const int numVertices,
        const obstacleEdge_t* const edges, const int numEdges,
        const obstacleCorner_t*, const int, const obstacleTrace_t*,
        const int, float*) {
    debugLines = outputDebugLines;
    maxDebugLines = outputMaxDebugLines;
    numDebugLines = 0;
    debugText = outputDebugText;
    maxDebugText = outputMaxDebugText;
    numDebugText = 0;
    tempMemory = temp;
    tempMemorySize = tempSize;
    flags = queryFlags;

    const idVec3 start3 = route.numAreas > 0
        ? route.areas[0].start : path.startPosOutsideObstacles;
    const idVec3 goal3 = route.numAreas > 0
        ? route.areas[route.numAreas - 1].end : path.seekPos[0];
    const idVec2 start(start3.x, start3.y);
    const idVec2 goal(goal3.x, goal3.y);
    path.numSeekPos = 0;
    path.firstObstacle = -1;
    path.firstObstaclePosition.Zero();
    path.startPosOutsideObstacles = start3;
    path.seekPosOutsideObstacles = goal3;
    path.startPosObstacle = -1;
    path.seekPosObstacle = -1;
    path.targetDist = Length2(Sub2(goal, start));
    path.pathLength = path.targetDist;
    path.hasValidPath = true;
    path.startPosValid = true;
    path.seekPosValid = true;

    int blocking = -1;
    float blockingRadius = 0.0f;
    for (int index = 0; index < numObstacles; ++index) {
        const obstacleBox_t& obstacle = obstacles[index];
        if (obstacle.soft && (queryFlags & 0x200) == 0) continue;
        const float radius = std::sqrt(obstacle.extents.x * obstacle.extents.x
            + obstacle.extents.y * obstacle.extents.y) + obstacleRadius;
        if (SegmentPointDistanceSqr(start, goal,
                idVec2(obstacle.center.x, obstacle.center.y))
            < radius * radius) {
            blocking = index;
            blockingRadius = radius;
            break;
        }
    }
    if (blocking < 0) {
        for (int index = 0; index < numEdges; ++index) {
            const int first = edges[index].vertNums[0];
            const int second = edges[index].vertNums[1];
            if (first < 0 || second < 0 || first >= numVertices
                || second >= numVertices) continue;
            const idVec2 edgeStart(vertices[first].position.x,
                vertices[first].position.y);
            const idVec2 edgeEnd(vertices[second].position.x,
                vertices[second].position.y);
            if (SegmentIntersection(start, goal, edgeStart, edgeEnd)) {
                blocking = numObstacles + index;
                break;
            }
        }
    }

    if (blocking >= 0 && blocking < numObstacles) {
        const obstacleBox_t& obstacle = obstacles[blocking];
        const idVec2 center(obstacle.center.x, obstacle.center.y);
        idVec2 direction = Normalize2(Sub2(goal, start));
        idVec2 perpendicular(-direction.y, direction.x);
        const idVec2 candidates[2] = {
            idVec2(center.x + perpendicular.x * blockingRadius,
                center.y + perpendicular.y * blockingRadius),
            idVec2(center.x - perpendicular.x * blockingRadius,
                center.y - perpendicular.y * blockingRadius)
        };
        const float firstLength = Length2(Sub2(candidates[0], start))
            + Length2(Sub2(goal, candidates[0]));
        const float secondLength = Length2(Sub2(candidates[1], start))
            + Length2(Sub2(goal, candidates[1]));
        const idVec2 corner = firstLength <= secondLength
            ? candidates[0] : candidates[1];
        path.seekPos[0].Set(corner.x, corner.y, start3.z);
        path.seekPos[1] = goal3;
        path.numSeekPos = 2;
        path.firstObstacle = obstacle.id;
        path.firstObstaclePosition = obstacle.center;
        path.pathLength = (std::min)(firstLength, secondLength);
        path.nextCorner.Set(corner.x, corner.y, start3.z,
            static_cast<float>(obstacle.id));
        AddDebugLine(COLOR_RED, start, corner);
        AddDebugLine(COLOR_GREEN, corner, goal);
    } else if (blocking >= numObstacles) {
        path.hasValidPath = false;
        path.seekPos[0] = start3;
        path.numSeekPos = 1;
    } else {
        path.seekPos[0] = goal3;
        path.numSeekPos = 1;
        path.nextCorner.Set(goal3.x, goal3.y, goal3.z, -1.0f);
        AddDebugLine(COLOR_GREEN, start, goal);
    }
    path.done = true;
    path.useRadarForward = Length2(idVec2(lastDir.x, lastDir.y)) > 0.0f;
    path.radarForward = lastDir;
    if (lastCorner.w >= 0.0f && path.firstObstacle < 0) {
        path.nextCorner = lastCorner;
    }
    if (frameMoveDist > 0.0f && path.numSeekPos > 0) {
        const idVec2 move = Sub2(idVec2(path.seekPos[0].x,
            path.seekPos[0].y), start);
        const float moveLength = Length2(move);
        if (moveLength > frameMoveDist) {
            const float scale = frameMoveDist / moveLength;
            path.seekPos[0].x = start.x + move.x * scale;
            path.seekPos[0].y = start.y + move.y * scale;
        }
    }
}
