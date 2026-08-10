#include "models/cuttable/earcliptriangulate.h"

#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>

namespace {

float Cross(const idVec2& a, const idVec2& b, const idVec2& c) {
    return (b.x - a.x) * (c.y - a.y) -
        (b.y - a.y) * (c.x - a.x);
}

bool SamePoint(const idVec2& a, const idVec2& b) {
    return a.x == b.x && a.y == b.y;
}

float SignedArea(const std::vector<std::int16_t>& polygon,
        const idList<idVec2, 5>& positions) {
    double area = 0.0;
    for (std::size_t index = 0; index < polygon.size(); ++index) {
        const idVec2& current = positions[polygon[index]];
        const idVec2& next = positions[polygon[(index + 1) % polygon.size()]];
        area += static_cast<double>(current.x) * next.y -
            static_cast<double>(current.y) * next.x;
    }
    return static_cast<float>(area * 0.5);
}

bool PointInTriangle(const idVec2& point, const idVec2& a,
        const idVec2& b, const idVec2& c) {
    constexpr float epsilon = 1.0e-6f;
    const float ab = Cross(a, b, point);
    const float bc = Cross(b, c, point);
    const float ca = Cross(c, a, point);
    return ab >= -epsilon && bc >= -epsilon && ca >= -epsilon;
}

bool OnSegment(const idVec2& a, const idVec2& b, const idVec2& point) {
    constexpr float epsilon = 1.0e-6f;
    return std::fabs(Cross(a, b, point)) <= epsilon &&
        point.x >= (std::min)(a.x, b.x) - epsilon &&
        point.x <= (std::max)(a.x, b.x) + epsilon &&
        point.y >= (std::min)(a.y, b.y) - epsilon &&
        point.y <= (std::max)(a.y, b.y) + epsilon;
}

int Orientation(const idVec2& a, const idVec2& b, const idVec2& c) {
    constexpr float epsilon = 1.0e-6f;
    const float value = Cross(a, b, c);
    return value > epsilon ? 1 : value < -epsilon ? -1 : 0;
}

bool SegmentsIntersect(const idVec2& a, const idVec2& b,
        const idVec2& c, const idVec2& d) {
    const int abc = Orientation(a, b, c);
    const int abd = Orientation(a, b, d);
    const int cda = Orientation(c, d, a);
    const int cdb = Orientation(c, d, b);
    if (abc != abd && cda != cdb) {
        return true;
    }
    return (abc == 0 && OnSegment(a, b, c)) ||
        (abd == 0 && OnSegment(a, b, d)) ||
        (cda == 0 && OnSegment(c, d, a)) ||
        (cdb == 0 && OnSegment(c, d, b));
}

bool BridgeIsVisible(std::int16_t holeVertex, std::int16_t polygonVertex,
        const std::vector<std::int16_t>& polygon,
        const std::vector<std::int16_t>& hole,
        const idList<idVec2, 5>& positions) {
    const idVec2& a = positions[holeVertex];
    const idVec2& b = positions[polygonVertex];

    auto crossesEdges = [&](const std::vector<std::int16_t>& loop) {
        for (std::size_t index = 0; index < loop.size(); ++index) {
            const std::int16_t first = loop[index];
            const std::int16_t second = loop[(index + 1) % loop.size()];
            if (first == holeVertex || second == holeVertex ||
                    first == polygonVertex || second == polygonVertex) {
                continue;
            }
            if (SegmentsIntersect(a, b, positions[first], positions[second])) {
                return true;
            }
        }
        return false;
    };

    return !crossesEdges(polygon) && !crossesEdges(hole);
}

} // namespace

idEarClipTriangulate::idEarClipTriangulate()
    : positions(), vertices(), contours(), indices(), triangles(), indexMap()
    , headConvex(-1), tailConvex(-1), headReflex(-1), tailReflex(-1)
    , headEar(-1), tailEar(-1), maxIndex(-1) {
}

idEarClipTriangulate::~idEarClipTriangulate() {
    ClearContours();
}

void idEarClipTriangulate::ClearContours() {
    for (int index = 0; index < contours.Num(); ++index) {
        delete contours[index];
    }
    contours.Clear();
}

bool idEarClipTriangulate::IsClockwise(
        const idList<idVec2, 5>& points) {
    double area = 0.0;
    for (int index = 0; index < points.Num(); ++index) {
        const idVec2& current = points[index];
        const idVec2& next = points[(index + 1) % points.Num()];
        area += static_cast<double>(current.x) * next.y -
            static_cast<double>(current.y) * next.x;
    }
    return area < 0.0;
}

void idEarClipTriangulate::SetContour(const idList<idVec2, 5>& points,
        const bool outer) {
    if (points.Num() < 3) {
        return;
    }

    Contour_t* contour = new Contour_t();
    contour->indices.PreAllocate(points.Num());
    const bool reverse = outer ? IsClockwise(points) : !IsClockwise(points);
    contour->valueMax = -std::numeric_limits<float>::max();

    for (int outputIndex = 0; outputIndex < points.Num(); ++outputIndex) {
        const int sourceIndex = reverse
            ? points.Num() - 1 - outputIndex
            : outputIndex;
        const int positionIndex = positions.Append(points[sourceIndex]);
        if (positionIndex < 0 || positionIndex > 32767) {
            delete contour;
            return;
        }
        const int contourIndex = contour->indices.Append(
            static_cast<std::int16_t>(positionIndex));
        if (points[sourceIndex].x > contour->valueMax) {
            contour->valueMax = points[sourceIndex].x;
            contour->indexMax = static_cast<std::int16_t>(contourIndex);
        }
    }
    contours.Append(contour);
    maxIndex = positions.Num() - 1;
}

void idEarClipTriangulate::SetOuterFromPoints(
        const idList<idVec2, 5>& points) {
    ClearContours();
    positions.Clear();
    vertices.Clear();
    indices.Clear();
    triangles.Clear();
    maxIndex = -1;
    SetContour(points, true);
}

void idEarClipTriangulate::SetOuterFromPoints(
        const idList<idVec2i, 5>& points) {
    idList<idVec2, 5> converted;
    converted.PreAllocate(points.Num());
    for (int index = 0; index < points.Num(); ++index) {
        converted.Append(idVec2(static_cast<float>(points[index].x),
            static_cast<float>(points[index].y)));
    }
    SetOuterFromPoints(converted);
}

void idEarClipTriangulate::AddInnerFromPoints(
        const idList<idVec2, 5>& points) {
    SetContour(points, false);
}

void idEarClipTriangulate::AddInnerFromPoints(
        const idList<idVec2i, 5>& points) {
    idList<idVec2, 5> converted;
    converted.PreAllocate(points.Num());
    for (int index = 0; index < points.Num(); ++index) {
        converted.Append(idVec2(static_cast<float>(points[index].x),
            static_cast<float>(points[index].y)));
    }
    AddInnerFromPoints(converted);
}

namespace {

void PointsFromContour(const Contour* contour, idList<idVec2, 5>& points) {
    if (contour == nullptr) {
        return;
    }
    for (const ContourEdge_t* edge = contour->edges; edge != nullptr;
         edge = edge->next) {
        for (const ContourNode_t* node = edge->node; node != nullptr;
             node = node->next) {
            const idVec2 point(static_cast<float>(node->pos.x),
                static_cast<float>(node->pos.y));
            if (points.Num() == 0 || !SamePoint(points[points.Num() - 1], point)) {
                points.Append(point);
            }
        }
    }
    if (points.Num() > 1 && SamePoint(points[0], points[points.Num() - 1])) {
        points.SetNum(points.Num() - 1);
    }
}

} // namespace

void idEarClipTriangulate::SetOuterFromContour(const Contour* contour) {
    idList<idVec2, 5> points;
    PointsFromContour(contour, points);
    SetOuterFromPoints(points);
}

void idEarClipTriangulate::AddInnerFromContour(const Contour* contour) {
    idList<idVec2, 5> points;
    PointsFromContour(contour, points);
    AddInnerFromPoints(points);
}

void idEarClipTriangulate::CombineContours(const Contour_t* contour,
        const idList<std::int16_t, 5>& source,
        idList<std::int16_t, 5>& destination) {
    if (contour == nullptr || contour->indices.Num() < 3 || source.Num() < 3) {
        return;
    }

    std::vector<std::int16_t> polygon(source.Ptr(),
        source.Ptr() + source.Num());
    std::vector<std::int16_t> hole(contour->indices.Ptr(),
        contour->indices.Ptr() + contour->indices.Num());
    int holeOffset = contour->indexMax;
    if (holeOffset < 0 || holeOffset >= static_cast<int>(hole.size())) {
        holeOffset = 0;
    }
    const std::int16_t holeVertex = hole[holeOffset];

    int polygonOffset = -1;
    float bestDistance = std::numeric_limits<float>::max();
    for (int candidate = 0; candidate < static_cast<int>(polygon.size());
         ++candidate) {
        const idVec2& a = positions[holeVertex];
        const idVec2& b = positions[polygon[candidate]];
        const float dx = b.x - a.x;
        const float dy = b.y - a.y;
        const float distance = dx * dx + dy * dy;
        if (distance >= bestDistance || !BridgeIsVisible(holeVertex,
                polygon[candidate], polygon, hole, positions)) {
            continue;
        }
        bestDistance = distance;
        polygonOffset = candidate;
    }
    if (polygonOffset < 0) {
        polygonOffset = 0;
    }

    destination.Clear();
    destination.PreAllocate(source.Num() + contour->indices.Num() + 2);
    for (int index = 0; index <= polygonOffset; ++index) {
        destination.Append(polygon[index]);
    }
    for (int index = 0; index < static_cast<int>(hole.size()); ++index) {
        destination.Append(hole[(holeOffset + index) % hole.size()]);
    }
    destination.Append(holeVertex);
    destination.Append(polygon[polygonOffset]);
    for (int index = polygonOffset + 1;
         index < static_cast<int>(polygon.size()); ++index) {
        destination.Append(polygon[index]);
    }
}

void idEarClipTriangulate::CreateSimplePolygon() {
    indices.Clear();
    if (contours.Num() == 0 || contours[0] == nullptr) {
        return;
    }
    indices = contours[0]->indices;
    for (int contourIndex = 1; contourIndex < contours.Num(); ++contourIndex) {
        idList<std::int16_t, 5> combined;
        CombineContours(contours[contourIndex], indices, combined);
        if (combined.Num() > 0) {
            indices = combined;
        }
    }
}

void idEarClipTriangulate::Process() {
    triangles.Clear();
    std::vector<std::int16_t> polygon;
    polygon.reserve(indices.Num());
    for (int index = 0; index < indices.Num(); ++index) {
        if (!polygon.empty() && SamePoint(positions[polygon.back()],
                positions[indices[index]])) {
            continue;
        }
        polygon.push_back(indices[index]);
    }
    if (polygon.size() > 1 && SamePoint(positions[polygon.front()],
            positions[polygon.back()])) {
        polygon.pop_back();
    }
    if (polygon.size() < 3) {
        return;
    }
    if (SignedArea(polygon, positions) < 0.0f) {
        std::reverse(polygon.begin(), polygon.end());
    }

    int stalledPasses = 0;
    while (polygon.size() > 3 && stalledPasses < 2) {
        bool clipped = false;
        for (std::size_t index = 0; index < polygon.size(); ++index) {
            const std::size_t previous =
                (index + polygon.size() - 1) % polygon.size();
            const std::size_t next = (index + 1) % polygon.size();
            const idVec2& a = positions[polygon[previous]];
            const idVec2& b = positions[polygon[index]];
            const idVec2& c = positions[polygon[next]];
            const float area = Cross(a, b, c);

            if (area <= 1.0e-7f) {
                if (std::fabs(area) <= 1.0e-7f) {
                    polygon.erase(polygon.begin() + index);
                    clipped = true;
                    break;
                }
                continue;
            }

            bool containsPoint = false;
            for (std::size_t test = 0; test < polygon.size(); ++test) {
                if (test == previous || test == index || test == next) {
                    continue;
                }
                const idVec2& point = positions[polygon[test]];
                if (SamePoint(point, a) || SamePoint(point, b) ||
                        SamePoint(point, c)) {
                    continue;
                }
                if (PointInTriangle(point, a, b, c)) {
                    containsPoint = true;
                    break;
                }
            }
            if (containsPoint) {
                continue;
            }

            triangles.Append(polygon[previous]);
            triangles.Append(polygon[index]);
            triangles.Append(polygon[next]);
            polygon.erase(polygon.begin() + index);
            clipped = true;
            break;
        }

        if (clipped) {
            stalledPasses = 0;
        } else {
            ++stalledPasses;
            if (polygon.size() > 3) {
                polygon.erase(polygon.begin() + 1);
            }
        }
    }

    if (polygon.size() == 3 &&
            Cross(positions[polygon[0]], positions[polygon[1]],
                positions[polygon[2]]) > 1.0e-7f) {
        triangles.Append(polygon[0]);
        triangles.Append(polygon[1]);
        triangles.Append(polygon[2]);
    }
}

void idEarClipTriangulate::Triangulate() {
    RemoveZeroAreas();
    CreateSimplePolygon();
    CreateVertices();
    Process();
    RemapIndices();
}

void idEarClipTriangulate::BuildGeometry(const idVec3&,
        idList<idVec2, 5>& outputPositions,
        idList<std::uint16_t, 5>& outputIndices) const {
    outputPositions.PreAllocate(outputPositions.Num() + positions.Num());
    const int baseVertex = outputPositions.Num();
    for (int index = 0; index < positions.Num(); ++index) {
        outputPositions.Append(positions[index]);
    }
    outputIndices.PreAllocate(outputIndices.Num() + triangles.Num());
    for (int index = 0; index < triangles.Num(); ++index) {
        outputIndices.Append(static_cast<std::uint16_t>(
            baseVertex + triangles[index]));
    }
}

void idEarClipTriangulate::RemoveZeroAreas() {
    for (int contourIndex = 0; contourIndex < contours.Num(); ++contourIndex) {
        Contour_t* contour = contours[contourIndex];
        if (contour == nullptr) {
            continue;
        }
        int index = 0;
        while (contour->indices.Num() >= 3 &&
                index < contour->indices.Num()) {
            const int previous = (index + contour->indices.Num() - 1) %
                contour->indices.Num();
            const int next = (index + 1) % contour->indices.Num();
            if (std::fabs(Cross(positions[contour->indices[previous]],
                    positions[contour->indices[index]],
                    positions[contour->indices[next]])) <= 1.0e-7f) {
                contour->indices.RemoveIndex(index);
            } else {
                ++index;
            }
        }
    }
}

void idEarClipTriangulate::CreateVertices() {
    vertices.Clear();
    vertices.SetNum(indices.Num());
    headConvex = tailConvex = -1;
    headReflex = tailReflex = -1;
    headEar = tailEar = -1;
    for (int index = 0; index < indices.Num(); ++index) {
        Vertex_t& vertex = vertices[index];
        vertex = {};
        vertex.index = indices[index];
        vertex.prevVertex = static_cast<std::int16_t>(
            (index + indices.Num() - 1) % indices.Num());
        vertex.nextVertex = static_cast<std::int16_t>(
            (index + 1) % indices.Num());
        vertex.prevEar = vertex.nextEar = -1;
        vertex.prevShared.value = vertex.nextShared.value = -1;
        vertex.isConvex = Cross(positions[indices[vertex.prevVertex]],
            positions[indices[index]], positions[indices[vertex.nextVertex]]) >= 0.0f;
        int& head = vertex.isConvex ? headConvex : headReflex;
        int& tail = vertex.isConvex ? tailConvex : tailReflex;
        if (head == -1) {
            head = index;
        } else {
            vertices[tail].nextShared.value = static_cast<std::int16_t>(index);
            vertex.prevShared.value = static_cast<std::int16_t>(tail);
        }
        tail = index;
    }
}

void idEarClipTriangulate::RemapIndices() {
    maxIndex = positions.Num() - 1;
}

void idEarClipTriangulate::RemoveReflex(const int index) {
    if (index < 0 || index >= vertices.Num()) return;
    Vertex_t& vertex = vertices[index];
    const int previous = vertex.prevShared.reflex;
    const int next = vertex.nextShared.reflex;

    if (previous != -1 && previous < vertices.Num()) {
        vertices[previous].nextShared.reflex = static_cast<std::int16_t>(next);
    } else if (headReflex == index) {
        headReflex = next;
    }
    if (next != -1 && next < vertices.Num()) {
        vertices[next].prevShared.reflex = static_cast<std::int16_t>(previous);
    } else if (tailReflex == index) {
        tailReflex = previous;
    }
    vertex.prevShared.reflex = -1;
    vertex.nextShared.reflex = -1;
}

bool idEarClipTriangulate::UpdateEar(const int vertexIndex) {
    if (vertexIndex < 0 || vertexIndex >= vertices.Num()) return false;
    Vertex_t& vertex = vertices[vertexIndex];
    if (!vertex.isConvex) {
        vertex.isEar = 0;
        return false;
    }

    vertex.isEar = 1;
    if (headReflex == -1) return true;

    const int previousVertex = vertex.prevVertex;
    const int nextVertex = vertex.nextVertex;
    if (previousVertex < 0 || previousVertex >= vertices.Num() ||
            nextVertex < 0 || nextVertex >= vertices.Num()) {
        vertex.isEar = 0;
        return false;
    }
    const idVec2& previous = positions[vertices[previousVertex].index];
    const idVec2& current = positions[vertex.index];
    const idVec2& next = positions[vertices[nextVertex].index];
    constexpr float epsilon = 1.1920929e-7f;

    for (int reflex = headReflex; reflex != -1;) {
        if (reflex < 0 || reflex >= vertices.Num()) break;
        const Vertex_t& reflexVertex = vertices[reflex];
        const int following = reflexVertex.nextShared.reflex;
        if (reflex != previousVertex && reflex != vertexIndex &&
                reflex != nextVertex) {
            const idVec2& point = positions[reflexVertex.index];
            const auto samePoint = [&](const idVec2& other) {
                return std::fabs(point.x - other.x) <= epsilon &&
                    std::fabs(point.y - other.y) <= epsilon;
            };
            if (!samePoint(previous) && !samePoint(current) &&
                    !samePoint(next) &&
                    TriangleQuery(point, previous, current, next) <= 0) {
                vertex.isEar = 0;
                return false;
            }
        }
        reflex = following;
    }
    return true;
}

int idEarClipTriangulate::LineTest(const idVec2& point, const idVec2& v0,
        const idVec2& v1) {
    // The recovered helper returns the opposite sign of the conventional
    // cross product: positive is to the right of the directed edge.
    const float value = (v1.y - v0.y) * (point.x - v0.x) -
        (point.y - v0.y) * (v1.x - v0.x);
    return value > 0.0f ? 1 : value < 0.0f ? -1 : 0;
}

int idEarClipTriangulate::TriangleQuery(const idVec2& point,
        const idVec2& v0, const idVec2& v1, const idVec2& v2) const {
    const int side0 = LineTest(point, v0, v1);
    const int side1 = LineTest(point, v1, v2);
    const int side2 = LineTest(point, v2, v0);
    if (side0 > 0 || side1 > 0 || side2 > 0) return 1;
    if (side0 == 0 || side1 == 0 || side2 == 0) return 0;
    return -1;
}
