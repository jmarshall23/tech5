#include "models/cuttable/cutterclip.h"

#include "models/cuttable/contourinfo.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <limits>
#include <map>
#include <set>
#include <utility>
#include <vector>

namespace {

struct DPoint {
    double x;
    double y;
};

struct ArrangementSegment {
    DPoint a;
    DPoint b;
    polygonType_t type;
    std::vector<double> split;
};

struct PointKey {
    int x;
    int y;

    bool operator<(const PointKey& other) const {
        return x != other.x ? x < other.x : y < other.y;
    }
    bool operator==(const PointKey& other) const {
        return x == other.x && y == other.y;
    }
};

struct DirectedKey {
    PointKey a;
    PointKey b;

    bool operator<(const DirectedKey& other) const {
        if (a < other.a) return true;
        if (other.a < a) return false;
        return b < other.b;
    }
};

double Cross(const DPoint& a, const DPoint& b, const DPoint& point) {
    return (b.x - a.x) * (point.y - a.y) -
        (b.y - a.y) * (point.x - a.x);
}

std::int64_t Cross(const idVec2i& a, const idVec2i& b,
        const idVec2i& point) {
    return (static_cast<std::int64_t>(b.x) - a.x) *
            (static_cast<std::int64_t>(point.y) - a.y) -
        (static_cast<std::int64_t>(b.y) - a.y) *
            (static_cast<std::int64_t>(point.x) - a.x);
}

bool PointOnSegment(const idVec2i& point, const idVec2i& a,
        const idVec2i& b) {
    return Cross(a, b, point) == 0 &&
        point.x >= std::min(a.x, b.x) && point.x <= std::max(a.x, b.x) &&
        point.y >= std::min(a.y, b.y) && point.y <= std::max(a.y, b.y);
}

double Parameter(const ArrangementSegment& segment, const DPoint& point) {
    const double dx = segment.b.x - segment.a.x;
    const double dy = segment.b.y - segment.a.y;
    return std::fabs(dx) >= std::fabs(dy)
        ? (std::fabs(dx) > 1.0e-12 ? (point.x - segment.a.x) / dx : 0.0)
        : (std::fabs(dy) > 1.0e-12 ? (point.y - segment.a.y) / dy : 0.0);
}

bool OnSegment(const DPoint& point, const ArrangementSegment& segment) {
    return std::fabs(Cross(segment.a, segment.b, point)) < 1.0e-8 &&
        point.x >= std::min(segment.a.x, segment.b.x) - 1.0e-8 &&
        point.x <= std::max(segment.a.x, segment.b.x) + 1.0e-8 &&
        point.y >= std::min(segment.a.y, segment.b.y) - 1.0e-8 &&
        point.y <= std::max(segment.a.y, segment.b.y) + 1.0e-8;
}

void AddSplit(ArrangementSegment& segment, double fraction) {
    if (fraction >= -1.0e-8 && fraction <= 1.0 + 1.0e-8)
        segment.split.push_back(std::max(0.0, std::min(1.0, fraction)));
}

void SplitAtIntersections(ArrangementSegment& first,
        ArrangementSegment& second) {
    const double firstX = first.b.x - first.a.x;
    const double firstY = first.b.y - first.a.y;
    const double secondX = second.b.x - second.a.x;
    const double secondY = second.b.y - second.a.y;
    const double denominator = firstX * secondY - firstY * secondX;
    if (std::fabs(denominator) < 1.0e-10) {
        if (std::fabs(Cross(first.a, first.b, second.a)) >= 1.0e-8)
            return;
        const DPoint points[4] = {first.a, first.b, second.a, second.b};
        if (OnSegment(points[2], first)) AddSplit(first, Parameter(first, points[2]));
        if (OnSegment(points[3], first)) AddSplit(first, Parameter(first, points[3]));
        if (OnSegment(points[0], second)) AddSplit(second, Parameter(second, points[0]));
        if (OnSegment(points[1], second)) AddSplit(second, Parameter(second, points[1]));
        return;
    }
    const double acX = second.a.x - first.a.x;
    const double acY = second.a.y - first.a.y;
    const double t = (acX * secondY - acY * secondX) / denominator;
    const double u = (acX * firstY - acY * firstX) / denominator;
    if (t >= -1.0e-8 && t <= 1.0 + 1.0e-8 &&
            u >= -1.0e-8 && u <= 1.0 + 1.0e-8) {
        AddSplit(first, t);
        AddSplit(second, u);
    }
}

bool BooleanValue(clipMode_t mode, bool subject, bool clip) {
    switch (mode) {
        case CLIPMODE_INTERSECT: return subject && clip;
        case CLIPMODE_UNION: return subject || clip;
        case CLIPMODE_DIFFERENCE: return subject && !clip;
        case CLIPMODE_XOR: return subject != clip;
        default: return false;
    }
}

PointKey RoundPoint(const DPoint& point) {
    return {static_cast<int>(std::floor(point.x + 0.5)),
        static_cast<int>(std::floor(point.y + 0.5))};
}

double PolygonArea(const idCutterClip::PolygonPoint_t* points) {
    if (points == nullptr) return 0.0;
    double area = 0.0;
    const idCutterClip::PolygonPoint_t* point = points;
    do {
        area += static_cast<double>(point->pos.x) * point->next->pos.y -
            static_cast<double>(point->next->pos.x) * point->pos.y;
        point = point->next;
    } while (point != points);
    return area * 0.5;
}

template<typename Type>
Type* AllocateRecord(idList<void*, 5>& allocations, int& current,
        int& peak, int& count, int& maximum) {
    void* memory = ::operator new(sizeof(Type));
    allocations.Append(memory);
    std::memset(memory, 0, sizeof(Type));
    current += sizeof(Type);
    peak = std::max(peak, current);
    ++count;
    maximum = std::max(maximum, count);
    return static_cast<Type*>(memory);
}

} // namespace

idCutterClip::idCutterClip()
    : memoryPeek(0), memoryCurrent(0), numEdges(0), maxEdges(0),
      numLocalMinima(0), maxLocalMinima(0), numScanbeams(0),
      maxScanbeams(0), numPolygons(0), maxPolygons(0),
      numPolygonPoints(0), maxPolygonPoints(0), numNestedPolygons(0),
      maxNestedPolygons(0), numJoinRecords(0), maxJoinRecords(0),
      numHorizontalJoinRecords(0), maxHorizontalJoinRecords(0),
      numIntersectNode(0), maxIntersectNode(0), edgesPool(nullptr),
      scanbeamsPool(nullptr), polygonsPool(nullptr),
      polygonPointsPool(nullptr), nestedPolygonsPool(nullptr),
      localMinimasPool(nullptr), intersectNodesPool(nullptr),
      joinRecordsPool(nullptr), horizontalJoinRecordsPool(nullptr),
      currentLocalMinima(nullptr), localMinimaList(nullptr),
      scanbeams(nullptr), activeEdges(nullptr), sortedEdges(nullptr),
      intersectNodes(nullptr), currentNestedPolygon(nullptr),
      currentInnerPolygon(nullptr), fillTypeSubject(FILLTYPE_EVEN_ODD),
      fillTypeClip(FILLTYPE_EVEN_ODD), clipMode(CLIPMODE_INTERSECT),
      reserved(0), running(0) {
}

idCutterClip::~idCutterClip() {
    for (int index = 0; index < poolAllocations.Num(); ++index)
        ::operator delete(poolAllocations[index]);
}

void idCutterClip::PreAllocate() {
    edges.PreAllocate(NUM_POOLEDGES);
    polygonPoints.PreAllocate(NUM_POOLPOLYGONPOINTS);
    polygons.PreAllocate(NUM_POOLPOLYGONS);
    nestedPolygons.PreAllocate(NUM_POOLNESTEDPOLYGONS);
    joins.PreAllocate(NUM_POOLJOINRECORDS);
    horizontalJoins.PreAllocate(NUM_POOLHORIZONTALJOINRECORDS);
}

void idCutterClip::Prepare() {
    ClearNestedPolygons();
    ClearPolygons();
    ClearPolygonPoints();
    ClearHorizontalJoinRecords();
    ClearJoinRecords();
    currentLocalMinima = localMinimaList;
    activeEdges = nullptr;
    sortedEdges = nullptr;
    currentNestedPolygon = nullptr;
    currentInnerPolygon = nullptr;
    running = 0;
}

idCutterClip::Edge_t* idCutterClip::AllocEdge() {
    Edge_t* result = edgesPool;
    if (result != nullptr) {
        edgesPool = result->next;
        std::memset(result, 0, sizeof(*result));
        ++numEdges;
    } else {
        result = AllocateRecord<Edge_t>(poolAllocations, memoryCurrent,
            memoryPeek, numEdges, maxEdges);
    }
    result->outIndex = -1;
    return result;
}

idCutterClip::LocalMinima_t* idCutterClip::AllocLocalMinima() {
    LocalMinima_t* result = localMinimasPool;
    if (result != nullptr) {
        localMinimasPool = result->next;
        std::memset(result, 0, sizeof(*result));
        ++numLocalMinima;
        return result;
    }
    return AllocateRecord<LocalMinima_t>(poolAllocations, memoryCurrent,
        memoryPeek, numLocalMinima, maxLocalMinima);
}

idCutterClip::Scanbeam_t* idCutterClip::AllocScanbeam() {
    Scanbeam_t* result = scanbeamsPool;
    if (result != nullptr) {
        scanbeamsPool = result->next;
        std::memset(result, 0, sizeof(*result));
        ++numScanbeams;
        return result;
    }
    return AllocateRecord<Scanbeam_t>(poolAllocations, memoryCurrent,
        memoryPeek, numScanbeams, maxScanbeams);
}

idCutterClip::Polygon_t* idCutterClip::AllocPolygon() {
    Polygon_t* result = polygonsPool;
    if (result != nullptr) {
        polygonsPool = result->next;
        std::memset(result, 0, sizeof(*result));
        ++numPolygons;
    } else {
        result = AllocateRecord<Polygon_t>(poolAllocations, memoryCurrent,
            memoryPeek, numPolygons, maxPolygons);
    }
    result->index = polygons.Num();
    polygons.Append(result);
    return result;
}

idCutterClip::PolygonPoint_t* idCutterClip::AllocPolygonPoint() {
    PolygonPoint_t* result = polygonPointsPool;
    if (result != nullptr) {
        polygonPointsPool = result->next;
        std::memset(result, 0, sizeof(*result));
        ++numPolygonPoints;
    } else {
        result = AllocateRecord<PolygonPoint_t>(poolAllocations,
            memoryCurrent, memoryPeek, numPolygonPoints,
            maxPolygonPoints);
    }
    result->index = polygonPoints.Num();
    polygonPoints.Append(result);
    return result;
}

idCutterClip::NestedPolygon_t* idCutterClip::AllocNestedPolygon() {
    NestedPolygon_t* result = nestedPolygonsPool;
    if (result != nullptr) {
        nestedPolygonsPool = result->next;
        std::memset(result, 0, sizeof(*result));
        ++numNestedPolygons;
    } else {
        result = AllocateRecord<NestedPolygon_t>(poolAllocations,
            memoryCurrent, memoryPeek, numNestedPolygons,
            maxNestedPolygons);
    }
    nestedPolygons.Append(result);
    return result;
}

idCutterClip::JoinRecord_t* idCutterClip::AllocJoinRecord() {
    JoinRecord_t* result = joinRecordsPool;
    if (result != nullptr) {
        joinRecordsPool = result->next;
        std::memset(result, 0, sizeof(*result));
        ++numJoinRecords;
    } else {
        result = AllocateRecord<JoinRecord_t>(poolAllocations,
            memoryCurrent, memoryPeek, numJoinRecords, maxJoinRecords);
    }
    joins.Append(result);
    return result;
}

idCutterClip::HorizontalJoinRecord_t*
idCutterClip::AllocHorizontalJoinRecord() {
    HorizontalJoinRecord_t* result = horizontalJoinRecordsPool;
    if (result != nullptr) {
        horizontalJoinRecordsPool = result->next;
        std::memset(result, 0, sizeof(*result));
        ++numHorizontalJoinRecords;
    } else {
        result = AllocateRecord<HorizontalJoinRecord_t>(poolAllocations,
            memoryCurrent, memoryPeek, numHorizontalJoinRecords,
            maxHorizontalJoinRecords);
    }
    horizontalJoins.Append(result);
    return result;
}

idCutterClip::IntersectNode_t* idCutterClip::AllocIntersectNode() {
    IntersectNode_t* result = intersectNodesPool;
    if (result != nullptr) {
        intersectNodesPool = result->next;
        std::memset(result, 0, sizeof(*result));
        ++numIntersectNode;
        return result;
    }
    return AllocateRecord<IntersectNode_t>(poolAllocations, memoryCurrent,
        memoryPeek, numIntersectNode, maxIntersectNode);
}

void idCutterClip::ClearPolygonPoints() {
    for (int index = 0; index < polygonPoints.Num(); ++index) {
        PolygonPoint_t* point = polygonPoints[index];
        point->next = polygonPointsPool;
        polygonPointsPool = point;
    }
    numPolygonPoints = 0;
    polygonPoints.Clear();
}

void idCutterClip::ClearPolygons() {
    for (int index = 0; index < polygons.Num(); ++index) {
        Polygon_t* polygon = polygons[index];
        polygon->points = nullptr;
        polygon->next = polygonsPool;
        polygonsPool = polygon;
    }
    numPolygons = 0;
    polygons.Clear();
}

void idCutterClip::ClearNestedPolygons() {
    for (int index = 0; index < nestedPolygons.Num(); ++index) {
        NestedPolygon_t* nested = nestedPolygons[index];
        nested->next = nestedPolygonsPool;
        nestedPolygonsPool = nested;
    }
    numNestedPolygons = 0;
    nestedPolygons.Clear();
}

void idCutterClip::ClearJoinRecords() {
    for (int index = 0; index < joins.Num(); ++index) {
        joins[index]->next = joinRecordsPool;
        joinRecordsPool = joins[index];
    }
    numJoinRecords = 0;
    joins.Clear();
}

void idCutterClip::ClearHorizontalJoinRecords() {
    for (int index = 0; index < horizontalJoins.Num(); ++index) {
        horizontalJoins[index]->next = horizontalJoinRecordsPool;
        horizontalJoinRecordsPool = horizontalJoins[index];
    }
    numHorizontalJoinRecords = 0;
    horizontalJoins.Clear();
}

void idCutterClip::AddContour(const Contour* contours,
        polygonType_t type) {
    for (const Contour* contour = contours; contour != nullptr;
            contour = contour->next) {
        std::vector<idVec2i> points;
        for (const ContourEdge_t* contourEdge = contour->edges;
                contourEdge != nullptr; contourEdge = contourEdge->next) {
            for (const ContourNode_t* node = contourEdge->node;
                    node != nullptr; node = node->next) {
                if (points.empty() || points.back() != node->pos)
                    points.push_back(node->pos);
            }
        }
        if (points.size() > 1 && points.front() == points.back())
            points.pop_back();
        if (points.size() < 3) continue;
        const int firstIndex = edges.Num();
        for (std::size_t index = 0; index < points.size(); ++index) {
            Edge_t* edge = AllocEdge();
            edge->bottom = points[index];
            edge->top = points[(index + 1) % points.size()];
            edge->current = edge->bottom;
            edge->polyType = type == POLYTYPE_SUBJECT ? 1 : 0;
            edge->horizontal = edge->bottom.y == edge->top.y;
            edge->windingDelta = edge->top.y >= edge->bottom.y ? 1 : -1;
            edge->deltaX = edge->top.y != edge->bottom.y
                ? static_cast<float>(edge->top.x - edge->bottom.x) /
                    static_cast<float>(edge->top.y - edge->bottom.y)
                : -1.0e30f;
            edge->ID = edges.Num();
            edges.Append(edge);
        }
        const int count = static_cast<int>(points.size());
        for (int index = 0; index < count; ++index) {
            Edge_t* edge = edges[firstIndex + index];
            edge->prev = edges[firstIndex + (index + count - 1) % count];
            edge->next = edges[firstIndex + (index + 1) % count];
            AddScanbeam(edge->bottom.y);
            AddScanbeam(edge->top.y);
        }
    }
}

bool idCutterClip::Clip(clipMode_t requestedMode,
        fillType_t fillType) {
    clipMode = requestedMode;
    fillTypeSubject = fillType;
    fillTypeClip = fillType;
    Prepare();
    running = 1;

    std::vector<ArrangementSegment> segments;
    segments.reserve(edges.Num());
    for (int index = 0; index < edges.Num(); ++index) {
        const Edge_t* edge = edges[index];
        if (edge->bottom == edge->top) continue;
        ArrangementSegment segment;
        segment.a = {static_cast<double>(edge->bottom.x),
            static_cast<double>(edge->bottom.y)};
        segment.b = {static_cast<double>(edge->top.x),
            static_cast<double>(edge->top.y)};
        segment.type = edge->polyType != 0
            ? POLYTYPE_SUBJECT : POLYTYPE_CLIP;
        segment.split = {0.0, 1.0};
        segments.push_back(segment);
    }
    for (std::size_t first = 0; first < segments.size(); ++first) {
        for (std::size_t second = first + 1; second < segments.size();
                ++second) {
            SplitAtIntersections(segments[first], segments[second]);
        }
    }

    auto inside = [&](const DPoint& point, polygonType_t type) {
        int winding = 0;
        for (const ArrangementSegment& edge : segments) {
            if (edge.type != type) continue;
            if (edge.a.y <= point.y) {
                if (edge.b.y > point.y && Cross(edge.a, edge.b, point) > 0.0)
                    ++winding;
            } else if (edge.b.y <= point.y &&
                    Cross(edge.a, edge.b, point) < 0.0) {
                --winding;
            }
        }
        return fillType == FILLTYPE_EVEN_ODD
            ? (std::abs(winding) & 1) != 0 : winding != 0;
    };

    std::map<DirectedKey, bool> boundary;
    for (ArrangementSegment& segment : segments) {
        std::sort(segment.split.begin(), segment.split.end());
        segment.split.erase(std::unique(segment.split.begin(),
            segment.split.end(), [](double a, double b) {
                return std::fabs(a - b) < 1.0e-9;
            }), segment.split.end());
        for (std::size_t index = 0; index + 1 < segment.split.size();
                ++index) {
            const double t0 = segment.split[index];
            const double t1 = segment.split[index + 1];
            if (t1 - t0 < 1.0e-9) continue;
            DPoint a = {segment.a.x + (segment.b.x - segment.a.x) * t0,
                segment.a.y + (segment.b.y - segment.a.y) * t0};
            DPoint b = {segment.a.x + (segment.b.x - segment.a.x) * t1,
                segment.a.y + (segment.b.y - segment.a.y) * t1};
            const double dx = b.x - a.x;
            const double dy = b.y - a.y;
            const double length = std::sqrt(dx * dx + dy * dy);
            if (length < 1.0e-9) continue;
            const double offset = std::min(0.25, length * 0.125);
            const DPoint middle = {(a.x + b.x) * 0.5,
                (a.y + b.y) * 0.5};
            const DPoint leftSample = {middle.x - dy / length * offset,
                middle.y + dx / length * offset};
            const DPoint rightSample = {middle.x + dy / length * offset,
                middle.y - dx / length * offset};
            const bool left = BooleanValue(requestedMode,
                inside(leftSample, POLYTYPE_SUBJECT),
                inside(leftSample, POLYTYPE_CLIP));
            const bool right = BooleanValue(requestedMode,
                inside(rightSample, POLYTYPE_SUBJECT),
                inside(rightSample, POLYTYPE_CLIP));
            if (left == right) continue;
            PointKey first = RoundPoint(left ? a : b);
            PointKey second = RoundPoint(left ? b : a);
            if (first == second) continue;
            const DirectedKey key = {first, second};
            const DirectedKey reverse = {second, first};
            auto reverseFound = boundary.find(reverse);
            if (reverseFound != boundary.end()) boundary.erase(reverseFound);
            else boundary[key] = true;
        }
    }

    std::vector<DirectedKey> outputEdges;
    outputEdges.reserve(boundary.size());
    for (const auto& entry : boundary) outputEdges.push_back(entry.first);
    std::map<PointKey, std::vector<int>> outgoing;
    for (int index = 0; index < static_cast<int>(outputEdges.size()); ++index)
        outgoing[outputEdges[index].a].push_back(index);
    std::vector<bool> used(outputEdges.size(), false);

    for (int firstEdge = 0; firstEdge < static_cast<int>(outputEdges.size());
            ++firstEdge) {
        if (used[firstEdge]) continue;
        std::vector<PointKey> loop;
        int edgeIndex = firstEdge;
        PointKey start = outputEdges[edgeIndex].a;
        PointKey previous = start;
        PointKey current = outputEdges[edgeIndex].b;
        used[edgeIndex] = true;
        loop.push_back(start);
        loop.push_back(current);
        while (!(current == start) && loop.size() <= outputEdges.size() + 1) {
            auto found = outgoing.find(current);
            if (found == outgoing.end()) break;
            int chosen = -1;
            double chosenAngle = std::numeric_limits<double>::max();
            const double incomingX = current.x - previous.x;
            const double incomingY = current.y - previous.y;
            for (int candidate : found->second) {
                if (used[candidate]) continue;
                const PointKey& next = outputEdges[candidate].b;
                const double nextX = next.x - current.x;
                const double nextY = next.y - current.y;
                double angle = std::atan2(incomingX * nextY -
                    incomingY * nextX, incomingX * nextX +
                    incomingY * nextY);
                if (angle <= 1.0e-10) angle += 6.283185307179586;
                if (angle < chosenAngle) {
                    chosenAngle = angle;
                    chosen = candidate;
                }
            }
            if (chosen < 0) break;
            used[chosen] = true;
            previous = current;
            current = outputEdges[chosen].b;
            loop.push_back(current);
        }
        if (loop.size() < 4 || !(loop.back() == start)) continue;
        loop.pop_back();
        bool simplified = true;
        while (simplified && loop.size() >= 3) {
            simplified = false;
            for (std::size_t index = 0; index < loop.size(); ++index) {
                const PointKey& a = loop[(index + loop.size() - 1) % loop.size()];
                const PointKey& b = loop[index];
                const PointKey& c = loop[(index + 1) % loop.size()];
                if (static_cast<std::int64_t>(b.x - a.x) * (c.y - b.y) ==
                        static_cast<std::int64_t>(b.y - a.y) * (c.x - b.x)) {
                    loop.erase(loop.begin() + index);
                    simplified = true;
                    break;
                }
            }
        }
        if (loop.size() < 3) continue;
        double area = 0.0;
        for (std::size_t index = 0; index < loop.size(); ++index) {
            const PointKey& a = loop[index];
            const PointKey& b = loop[(index + 1) % loop.size()];
            area += static_cast<double>(a.x) * b.y -
                static_cast<double>(b.x) * a.y;
        }
        if (std::fabs(area) < 1.0) continue;
        Polygon_t* polygon = AllocPolygon();
        polygon->hole = area < 0.0;
        polygon->connected = true;
        PolygonPoint_t* previousPoint = nullptr;
        for (const PointKey& point : loop) {
            PolygonPoint_t* output = AllocPolygonPoint();
            output->pos.Set(point.x, point.y);
            if (polygon->points == nullptr) polygon->points = output;
            if (previousPoint != nullptr) {
                previousPoint->next = output;
                output->prev = previousPoint;
            }
            previousPoint = output;
        }
        previousPoint->next = polygon->points;
        polygon->points->prev = previousPoint;
        polygon->bottomPoint = FindBottom(polygon->points);
    }
    BuildResult();
    running = 0;
    return true;
}

void idCutterClip::BuildResult() {
    ClearNestedPolygons();
    std::vector<Polygon_t*> outers;
    std::vector<Polygon_t*> holes;
    for (int index = 0; index < polygons.Num(); ++index) {
        Polygon_t* polygon = polygons[index];
        polygon->next = nullptr;
        polygon->firstLeft = nullptr;
        if (polygon->points == nullptr) continue;
        (polygon->hole ? holes : outers).push_back(polygon);
    }
    for (Polygon_t* outer : outers) {
        NestedPolygon_t* nested = AllocNestedPolygon();
        nested->outer = outer;
    }
    for (Polygon_t* hole : holes) {
        NestedPolygon_t* best = nullptr;
        double bestArea = std::numeric_limits<double>::max();
        for (int index = 0; index < nestedPolygons.Num(); ++index) {
            NestedPolygon_t* nested = nestedPolygons[index];
            if (!PointInPolygon(hole->points->pos,
                    nested->outer->points)) continue;
            const double area = std::fabs(PolygonArea(nested->outer->points));
            if (area < bestArea) { bestArea = area; best = nested; }
        }
        if (best == nullptr) {
            hole->hole = false;
            NestedPolygon_t* nested = AllocNestedPolygon();
            nested->outer = hole;
            continue;
        }
        hole->firstLeft = best->outer;
        hole->next = best->inner;
        best->inner = hole;
    }
}

int idCutterClip::GetNumPolygons() const {
    return nestedPolygons.Num();
}

int idCutterClip::GetConnectedPolygons() const {
    return polygons.Num();
}

void idCutterClip::GetPolygon(const Polygon_t* polygon,
        idList<idVec2i, 5>& list) {
    list.Clear();
    if (polygon == nullptr || polygon->points == nullptr) return;
    const PolygonPoint_t* point = polygon->points;
    do {
        list.Append(point->pos);
        point = point->next;
    } while (point != polygon->points);
}

void idCutterClip::GetPolygon(int id, idList<idVec2i, 5>& list) {
    list.Clear();
    if (id < 0 || id >= nestedPolygons.Num()) {
        currentNestedPolygon = nullptr;
        currentInnerPolygon = nullptr;
        return;
    }
    currentNestedPolygon = nestedPolygons[id];
    GetPolygon(currentNestedPolygon->outer, list);
    currentInnerPolygon = currentNestedPolygon->inner;
}

void idCutterClip::GetInnerPolygon(idList<idVec2i, 5>& list) {
    list.Clear();
    if (currentInnerPolygon == nullptr) return;
    GetPolygon(currentInnerPolygon, list);
    currentInnerPolygon = currentInnerPolygon->next;
}

void idCutterClip::GetConnectedPolygon(int index,
        idList<idVec2i, 5>& list) const {
    list.Clear();
    if (index >= 0 && index < polygons.Num() && polygons[index]->connected)
        GetPolygon(polygons[index], list);
}

int idCutterClip::idSort_Polygons::Compare(const Polygon_t* a,
        const Polygon_t* b) const {
    if (a == b) return 0;
    if (a == nullptr || a->points == nullptr)
        return b == nullptr || b->points == nullptr ? 0 : 1;
    if (b == nullptr || b->points == nullptr) return -1;
    const int aIndex = a->hole && a->firstLeft != nullptr
        ? a->firstLeft->index : a->index;
    const int bIndex = b->hole && b->firstLeft != nullptr
        ? b->firstLeft->index : b->index;
    if (aIndex != bIndex) return aIndex - bIndex;
    return a->hole == b->hole ? 0 : (a->hole ? 1 : -1);
}

idCutterClip::PolygonPoint_t* idCutterClip::FindBottom(
        PolygonPoint_t* point) {
    if (point == nullptr) return nullptr;
    PolygonPoint_t* best = point;
    for (PolygonPoint_t* current = point->next; current != point;
            current = current->next) {
        if (current->pos.y > best->pos.y ||
                (current->pos.y == best->pos.y &&
                    current->pos.x < best->pos.x)) best = current;
    }
    return best;
}

bool idCutterClip::IsClockwise(const PolygonPoint_t* points) {
    return PolygonArea(points) < 0.0;
}

bool idCutterClip::PointInPolygon(const idVec2i& pos,
        const PolygonPoint_t* points) {
    if (points == nullptr) return false;
    bool inside = false;
    const PolygonPoint_t* point = points;
    do {
        const idVec2i& a = point->pos;
        const idVec2i& b = point->next->pos;
        if (PointOnSegment(pos, a, b)) return true;
        if ((a.y > pos.y) != (b.y > pos.y)) {
            const double x = a.x + static_cast<double>(pos.y - a.y) *
                (b.x - a.x) / static_cast<double>(b.y - a.y);
            if (x > pos.x) inside = !inside;
        }
        point = point->next;
    } while (point != points);
    return inside;
}

bool idCutterClip::IsPolygonPoint(const idVec2i& pos,
        const PolygonPoint_t* point) {
    if (point == nullptr) return false;
    const PolygonPoint_t* current = point;
    do {
        if (current->pos == pos) return true;
        current = current->next;
    } while (current != point);
    return false;
}

int idCutterClip::CalculateTopX(const Edge_t* edge, int y) {
    if (edge == nullptr) return 0;
    if (edge->top.y == edge->bottom.y) return edge->top.x;
    return static_cast<int>(std::floor(edge->bottom.x +
        static_cast<double>(y - edge->bottom.y) *
        (edge->top.x - edge->bottom.x) /
        static_cast<double>(edge->top.y - edge->bottom.y) + 0.5));
}

bool idCutterClip::SlopesEqual(Edge_t* first, Edge_t* second) {
    return first != nullptr && second != nullptr &&
        Cross(first->bottom, first->top, second->top) == 0;
}

bool idCutterClip::IsSegmentOverlapping(const idVec2i& p1a,
        const idVec2i& p1b, const idVec2i& p2a, const idVec2i& p2b,
        idVec2i& overlap1, idVec2i& overlap2) {
    if (Cross(p1a, p1b, p2a) != 0 || Cross(p1a, p1b, p2b) != 0)
        return false;
    std::vector<idVec2i> points;
    const idVec2i candidates[4] = {p1a, p1b, p2a, p2b};
    for (const idVec2i& point : candidates) {
        if (PointOnSegment(point, p1a, p1b) &&
                PointOnSegment(point, p2a, p2b) &&
                std::find(points.begin(), points.end(), point) == points.end())
            points.push_back(point);
    }
    if (points.size() < 2) return false;
    std::sort(points.begin(), points.end(), [&](const idVec2i& a,
            const idVec2i& b) {
        return std::abs(p1b.x - p1a.x) >= std::abs(p1b.y - p1a.y)
            ? a.x < b.x : a.y < b.y;
    });
    overlap1 = points.front();
    overlap2 = points.back();
    return overlap1 != overlap2;
}

bool idCutterClip::EdgeEdgeIntersection(Edge_t* first, Edge_t* second,
        idVec2i& pos) {
    if (first == nullptr || second == nullptr) return false;
    ArrangementSegment a = {{static_cast<double>(first->bottom.x),
        static_cast<double>(first->bottom.y)},
        {static_cast<double>(first->top.x), static_cast<double>(first->top.y)},
        POLYTYPE_SUBJECT, {0.0, 1.0}};
    ArrangementSegment b = {{static_cast<double>(second->bottom.x),
        static_cast<double>(second->bottom.y)},
        {static_cast<double>(second->top.x), static_cast<double>(second->top.y)},
        POLYTYPE_CLIP, {0.0, 1.0}};
    SplitAtIntersections(a, b);
    if (a.split.size() <= 2) return false;
    std::sort(a.split.begin(), a.split.end());
    const double t = a.split[1];
    pos.Set(static_cast<int>(std::floor(a.a.x + (a.b.x - a.a.x) * t + 0.5)),
        static_cast<int>(std::floor(a.a.y + (a.b.y - a.a.y) * t + 0.5)));
    return true;
}

bool idCutterClip::FindSegment(PolygonPoint_t*& point,
        idVec2i& p1, idVec2i& p2) {
    if (point == nullptr) return false;
    PolygonPoint_t* start = point;
    do {
        if (IsSegmentOverlapping(point->pos, point->next->pos,
                p1, p2, p1, p2)) return true;
        point = point->next;
    } while (point != start);
    return false;
}

void idCutterClip::SwapEdgeInAEL(Edge_t* first, Edge_t* second) {
    if (first == nullptr || second == nullptr || first == second) return;
    if (first->nextAEL != second) {
        if (second->nextAEL == first) { SwapEdgeInAEL(second, first); return; }
        return;
    }
    Edge_t* before = first->prevAEL;
    Edge_t* after = second->nextAEL;
    if (before != nullptr) before->nextAEL = second; else activeEdges = second;
    second->prevAEL = before;
    second->nextAEL = first;
    first->prevAEL = second;
    first->nextAEL = after;
    if (after != nullptr) after->prevAEL = first;
}

void idCutterClip::SwapEdgeInSEL(Edge_t* first, Edge_t* second) {
    if (first == nullptr || second == nullptr || first == second) return;
    if (first->nextSEL != second) {
        if (second->nextSEL == first) { SwapEdgeInSEL(second, first); return; }
        return;
    }
    Edge_t* before = first->prevSEL;
    Edge_t* after = second->nextSEL;
    if (before != nullptr) before->nextSEL = second; else sortedEdges = second;
    second->prevSEL = before;
    second->nextSEL = first;
    first->prevSEL = second;
    first->nextSEL = after;
    if (after != nullptr) after->prevSEL = first;
}

void idCutterClip::AddEdgeToAEL(Edge_t* edge) {
    if (edge == nullptr) return;
    Edge_t** cursor = &activeEdges;
    Edge_t* previous = nullptr;
    while (*cursor != nullptr && (*cursor)->current.x <= edge->current.x) {
        previous = *cursor;
        cursor = &(*cursor)->nextAEL;
    }
    edge->prevAEL = previous;
    edge->nextAEL = *cursor;
    if (*cursor != nullptr) (*cursor)->prevAEL = edge;
    *cursor = edge;
}

void idCutterClip::RemoveEdgeFromAEL(Edge_t* edge) {
    if (edge == nullptr) return;
    if (edge->prevAEL != nullptr) edge->prevAEL->nextAEL = edge->nextAEL;
    else if (activeEdges == edge) activeEdges = edge->nextAEL;
    if (edge->nextAEL != nullptr) edge->nextAEL->prevAEL = edge->prevAEL;
    edge->prevAEL = edge->nextAEL = nullptr;
}

bool idCutterClip::IsTopHorizontal(int x) const {
    for (const Edge_t* edge = sortedEdges; edge != nullptr;
            edge = edge->nextSEL)
        if (edge->horizontal && edge->top.x == x) return true;
    return false;
}

bool idCutterClip::FixupIntersections() {
    if (intersectNodes == nullptr || intersectNodes->next == nullptr)
        return true;

    // Preserve the current AEL ordering in the secondary list.  Intersection
    // records must be processed in an order where their two edges are
    // adjacent; every accepted record then swaps those edges for the next
    // record, just as the recovered scan-line implementation does.
    sortedEdges = activeEdges;
    Edge_t* previous = nullptr;
    for (Edge_t* edge = activeEdges; edge != nullptr;
            edge = edge->nextAEL) {
        edge->prevSEL = previous;
        edge->nextSEL = edge->nextAEL;
        previous = edge;
    }

    for (IntersectNode_t* node = intersectNodes; node != nullptr;
            node = node->next) {
        const auto adjacent = [](const IntersectNode_t* candidate) {
            return candidate != nullptr && candidate->edge1 != nullptr &&
                candidate->edge2 != nullptr &&
                (candidate->edge1->nextSEL == candidate->edge2 ||
                    candidate->edge1->prevSEL == candidate->edge2);
        };

        if (!adjacent(node)) {
            IntersectNode_t* replacement = node->next;
            while (replacement != nullptr && !adjacent(replacement))
                replacement = replacement->next;
            if (replacement == nullptr) return false;
            std::swap(node->edge1, replacement->edge1);
            std::swap(node->edge2, replacement->edge2);
            std::swap(node->pos, replacement->pos);
        }
        SwapEdgeInSEL(node->edge1, node->edge2);
    }
    return true;
}

void idCutterClip::FixHoleLinkage_r(Polygon_t* polygon) {
    if (polygon == nullptr || !polygon->hole) return;
    while (polygon->firstLeft != nullptr && polygon->firstLeft->hole)
        polygon->firstLeft = polygon->firstLeft->firstLeft;
    if (polygon->firstLeft == nullptr) polygon->hole = false;
}

bool idCutterClip::IsContributing(clipMode_t mode, Edge_t* edge) {
    if (edge == nullptr) return false;
    const bool ownInside = std::abs(edge->windingCount) == 1;
    const bool otherInside = std::abs(edge->windingCount2) != 0;
    return edge->polyType != 0
        ? BooleanValue(mode, ownInside, otherInside) !=
            BooleanValue(mode, !ownInside, otherInside)
        : BooleanValue(mode, otherInside, ownInside) !=
            BooleanValue(mode, otherInside, !ownInside);
}

void idCutterClip::SetHoleState(const Edge_t* edge, Polygon_t* polygon) {
    if (polygon == nullptr) return;
    int crossings = 0;
    for (const Edge_t* current = edge != nullptr ? edge->prevAEL : nullptr;
            current != nullptr; current = current->prevAEL)
        if (current->outIndex >= 0) ++crossings;
    polygon->hole = (crossings & 1) != 0;
}

const idCutterClip::Polygon_t* idCutterClip::FindBottomPolygon(
        const Polygon_t* first, const Polygon_t* second) {
    if (first == nullptr) return second;
    if (second == nullptr) return first;
    if (first->bottomPoint == nullptr) return second;
    if (second->bottomPoint == nullptr) return first;
    const idVec2i& a = first->bottomPoint->pos;
    const idVec2i& b = second->bottomPoint->pos;
    return a.y > b.y || (a.y == b.y && a.x < b.x) ? first : second;
}

void idCutterClip::AppendPolygon(Edge_t* edge1, Edge_t* edge2) {
    if (edge1 == nullptr || edge2 == nullptr || edge1->outIndex < 0 ||
            edge2->outIndex < 0 || edge1->outIndex == edge2->outIndex) return;
    Polygon_t* first = polygons[edge1->outIndex];
    Polygon_t* second = polygons[edge2->outIndex];
    first->appendLink = second;
    edge2->outIndex = edge1->outIndex;
}

void idCutterClip::SetWindingCount(Edge_t* edge) {
    if (edge == nullptr) return;
    edge->windingCount = edge->windingDelta;
    edge->windingCount2 = 0;
    for (Edge_t* previous = edge->prevAEL; previous != nullptr;
            previous = previous->prevAEL) {
        if (previous->polyType == edge->polyType)
            edge->windingCount += previous->windingDelta;
        else edge->windingCount2 += previous->windingDelta;
    }
}

void idCutterClip::FixupPolygon(Polygon_t* polygon) {
    if (polygon == nullptr || polygon->points == nullptr) return;
    PolygonPoint_t* point = polygon->points;
    int safety = 0;
    do {
        PolygonPoint_t* next = point->next;
        if (next == point || next->next == point) {
            polygon->points = nullptr;
            return;
        }
        if (point->pos == next->pos ||
                Cross(point->prev->pos, point->pos, next->pos) == 0) {
            point->prev->next = next;
            next->prev = point->prev;
            if (polygon->points == point) polygon->points = next;
            point = next;
        } else point = next;
    } while (point != polygon->points && ++safety < polygonPoints.Num() + 1);
    polygon->bottomPoint = FindBottom(polygon->points);
}

idCutterClip::Edge_t* idCutterClip::AddBoundToLML(Edge_t* edge) {
    if (edge == nullptr) return nullptr;
    Edge_t* current = edge;
    while (current->next != edge && current->next->bottom.y ==
            current->top.y) {
        current->nextLML = current->next;
        current->next->prevLML = current;
        current = current->next;
    }
    return current;
}

void idCutterClip::AddScanbeam(int y) {
    Scanbeam_t** cursor = &scanbeams;
    while (*cursor != nullptr && (*cursor)->y > y) cursor = &(*cursor)->next;
    if (*cursor != nullptr && (*cursor)->y == y) return;
    Scanbeam_t* added = AllocScanbeam();
    added->y = y;
    added->next = *cursor;
    *cursor = added;
}

void idCutterClip::AddJoinRecord(Edge_t* first, Edge_t* second,
        std::int16_t firstIndex, std::int16_t secondIndex) {
    JoinRecord_t* record = AllocJoinRecord();
    record->polyIndex1 = firstIndex >= 0 ? firstIndex
        : (first != nullptr ? first->outIndex : -1);
    record->polyIndex2 = secondIndex >= 0 ? secondIndex
        : (second != nullptr ? second->outIndex : -1);
    if (first != nullptr) { record->point1a = first->bottom;
        record->point1b = first->top; }
    if (second != nullptr) { record->point2a = second->bottom;
        record->point2b = second->top; }
}

void idCutterClip::AddIntersectNode(Edge_t* first, Edge_t* second,
        const idVec2i& pos) {
    IntersectNode_t* node = AllocIntersectNode();
    node->edge1 = first;
    node->edge2 = second;
    node->pos = pos;
    IntersectNode_t** cursor = &intersectNodes;
    while (*cursor != nullptr && ((*cursor)->pos.y > pos.y ||
            ((*cursor)->pos.y == pos.y && (*cursor)->pos.x < pos.x)))
        cursor = &(*cursor)->next;
    node->next = *cursor;
    *cursor = node;
}

idCutterClip::PolygonPoint_t* idCutterClip::AddPolygonPoint(
        Polygon_t* polygon, PolygonPoint_t* before, PolygonPoint_t* after,
        const idVec2i& pos) {
    if (polygon == nullptr) return nullptr;
    PolygonPoint_t* point = AllocPolygonPoint();
    point->pos = pos;
    if (polygon->points == nullptr) {
        point->next = point->prev = point;
        polygon->points = point;
    } else {
        if (before == nullptr) before = polygon->points->prev;
        if (after == nullptr) after = before->next;
        point->prev = before;
        point->next = after;
        before->next = point;
        after->prev = point;
    }
    polygon->bottomPoint = FindBottom(polygon->points);
    return point;
}

idCutterClip::PolygonPoint_t* idCutterClip::AddPolygonPoint(
        Edge_t* edge1, Edge_t* edge2, const idVec2i& pos) {
    Edge_t* edge = edge1 != nullptr ? edge1 : edge2;
    if (edge == nullptr) return nullptr;
    Polygon_t* polygon = nullptr;
    if (edge->outIndex >= 0 && edge->outIndex < polygons.Num())
        polygon = polygons[edge->outIndex];
    else {
        polygon = AllocPolygon();
        edge->outIndex = static_cast<std::int16_t>(polygon->index);
        if (edge2 != nullptr) edge2->outIndex = edge->outIndex;
    }
    return AddPolygonPoint(polygon, nullptr, nullptr, pos);
}

void idCutterClip::AddLocalMinPolygon(Edge_t* first, Edge_t* second,
        const idVec2i& pos) {
    AddPolygonPoint(first, second, pos);
}

void idCutterClip::AddLocalMaxPolygon(Edge_t* first, Edge_t* second,
        const idVec2i& pos) {
    AddPolygonPoint(first, second, pos);
    AppendPolygon(first, second);
}

void idCutterClip::IntersectEdges(Edge_t* first, Edge_t* second,
        const idVec2i& pos, intersectProtects_t) {
    if (IsContributing(clipMode, first)) AddPolygonPoint(first, nullptr, pos);
    if (IsContributing(clipMode, second)) AddPolygonPoint(second, nullptr, pos);
    SwapEdgeInAEL(first, second);
}

void idCutterClip::Reset() {
    Prepare();
    currentLocalMinima = localMinimaList;
    for (int index = 0; index < edges.Num(); ++index) {
        Edge_t* edge = edges[index];
        edge->current = edge->bottom;
        edge->outIndex = -1;
        edge->prevAEL = edge->nextAEL = nullptr;
        edge->prevSEL = edge->nextSEL = nullptr;
    }
}

idCutterClip::Edge_t* idCutterClip::UpdateEdgeInAEL(Edge_t* edge) {
    if (edge == nullptr || edge->nextLML == nullptr) return edge;
    Edge_t* replacement = edge->nextLML;
    replacement->prevAEL = edge->prevAEL;
    replacement->nextAEL = edge->nextAEL;
    if (replacement->prevAEL != nullptr)
        replacement->prevAEL->nextAEL = replacement;
    else activeEdges = replacement;
    if (replacement->nextAEL != nullptr)
        replacement->nextAEL->prevAEL = replacement;
    return replacement;
}

void idCutterClip::ProcessIntersectList() {
    while (intersectNodes != nullptr) {
        IntersectNode_t* node = intersectNodes;
        intersectNodes = node->next;
        IntersectEdges(node->edge1, node->edge2, node->pos,
            INTERSECTPROTECTS_NONE);
        node->next = intersectNodesPool;
        intersectNodesPool = node;
        --numIntersectNode;
    }
}

void idCutterClip::BuildIntersectList(int yBottom, int yTop) {
    for (Edge_t* first = activeEdges; first != nullptr;
            first = first->nextAEL) {
        for (Edge_t* second = first->nextAEL; second != nullptr;
                second = second->nextAEL) {
            idVec2i pos;
            if (EdgeEdgeIntersection(first, second, pos) &&
                    pos.y >= std::min(yBottom, yTop) &&
                    pos.y <= std::max(yBottom, yTop))
                AddIntersectNode(first, second, pos);
        }
    }
}

void idCutterClip::DoMaxima(Edge_t* edge, Edge_t* maximaPair,
        int y) {
    if (edge == nullptr) return;
    const idVec2i pos(CalculateTopX(edge, y), y);
    if (maximaPair != nullptr) AddLocalMaxPolygon(edge, maximaPair, pos);
    RemoveEdgeFromAEL(edge);
    if (maximaPair != nullptr) RemoveEdgeFromAEL(maximaPair);
}

void idCutterClip::AddLocalMinimaToAEL(int yBottom) {
    while (currentLocalMinima != nullptr &&
            currentLocalMinima->y == yBottom) {
        if (currentLocalMinima->leftBound != nullptr)
            AddEdgeToAEL(currentLocalMinima->leftBound);
        if (currentLocalMinima->rightBound != nullptr)
            AddEdgeToAEL(currentLocalMinima->rightBound);
        currentLocalMinima = currentLocalMinima->next;
    }
}

void idCutterClip::ProcessHorizontal(Edge_t* edge) {
    if (edge == nullptr) return;
    edge->current = edge->top;
}

void idCutterClip::JoinEdges() {
    for (int index = 0; index < polygons.Num(); ++index)
        FixupPolygon(polygons[index]);
}

void idCutterClip::ProcessHorizontals() {
    for (Edge_t* edge = activeEdges; edge != nullptr; edge = edge->nextAEL)
        if (edge->horizontal) ProcessHorizontal(edge);
}

void idCutterClip::ProcessEdgesAtTopOfScanbeam(int y) {
    for (Edge_t* edge = activeEdges; edge != nullptr; edge = edge->nextAEL) {
        edge->current.x = CalculateTopX(edge, y);
        edge->current.y = y;
    }
}
