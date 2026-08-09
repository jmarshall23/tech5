#include "models/cuttable/cuttercontour.h"

#include <algorithm>
#include <cstdint>
#include <limits>
#include <vector>

namespace {

std::int64_t Cross(const idVec2i& a, const idVec2i& b,
        const idVec2i& point) {
    return (static_cast<std::int64_t>(b.x) - a.x) *
            (static_cast<std::int64_t>(point.y) - a.y) -
        (static_cast<std::int64_t>(b.y) - a.y) *
            (static_cast<std::int64_t>(point.x) - a.x);
}

bool PointBetween(const idVec2i& point, const idVec2i& a,
        const idVec2i& b) {
    if (Cross(a, b, point) != 0) return false;
    return point.x >= std::min(a.x, b.x) &&
        point.x <= std::max(a.x, b.x) &&
        point.y >= std::min(a.y, b.y) &&
        point.y <= std::max(a.y, b.y);
}

bool EdgesOverlap(const ContourEdge_t* first,
        const ContourEdge_t* second) {
    if (first == nullptr || second == nullptr || first->node == nullptr ||
            first->node->next == nullptr || second->node == nullptr ||
            second->node->next == nullptr) {
        return false;
    }
    const idVec2i& a = first->node->pos;
    const idVec2i& b = first->node->next->pos;
    const idVec2i& c = second->node->pos;
    const idVec2i& d = second->node->next->pos;
    if (Cross(a, b, c) != 0 || Cross(a, b, d) != 0) return false;
    return PointBetween(a, c, d) || PointBetween(b, c, d) ||
        PointBetween(c, a, b) || PointBetween(d, a, b);
}

std::vector<idVec2i> EdgePoints(const ContourEdge_t* edge) {
    std::vector<idVec2i> points;
    for (const ContourNode_t* node = edge != nullptr ? edge->node : nullptr;
            node != nullptr; node = node->next) {
        points.push_back(node->pos);
    }
    return points;
}

bool HasPoint(const ContourEdge_t* edge, const idVec2i& point) {
    for (const ContourNode_t* node = edge != nullptr ? edge->node : nullptr;
            node != nullptr; node = node->next) {
        if (node->pos == point) return true;
    }
    return false;
}

} // namespace

ContourManager::ContourManager()
    : contoursPool(nullptr), edgesPool(nullptr), nodesPool(nullptr) {
}

ContourManager::~ContourManager() {
    while (contoursPool != nullptr) {
        Contour* next = contoursPool->next;
        delete contoursPool;
        contoursPool = next;
    }
    while (edgesPool != nullptr) {
        ContourEdge_t* next = edgesPool->next;
        delete edgesPool;
        edgesPool = next;
    }
    while (nodesPool != nullptr) {
        ContourNode_t* next = nodesPool->next;
        delete nodesPool;
        nodesPool = next;
    }
}

Contour* ContourManager::AllocContour() {
    Contour* contour = contoursPool;
    if (contour != nullptr) {
        contoursPool = contour->next;
    } else {
        contour = new Contour;
    }
    contour->next = nullptr;
    contour->edges = nullptr;
    contour->bound[0].Zero();
    contour->bound[1].Zero();
    contour->numEdges = 0;
    return contour;
}

ContourEdge_t* ContourManager::AllocEdge() {
    ContourEdge_t* edge = edgesPool;
    if (edge != nullptr) {
        edgesPool = edge->next;
    } else {
        edge = new ContourEdge_t;
    }
    edge->next = nullptr;
    edge->node = nullptr;
    return edge;
}

ContourNode_t* ContourManager::AllocNode() {
    ContourNode_t* node = nodesPool;
    if (node != nullptr) {
        nodesPool = node->next;
    } else {
        node = new ContourNode_t;
    }
    node->next = nullptr;
    node->pos.Zero();
    return node;
}

void ContourManager::Free(Contour* contour) {
    while (contour != nullptr) {
        Contour* nextContour = contour->next;
        for (ContourEdge_t* edge = contour->edges; edge != nullptr;) {
            ContourEdge_t* nextEdge = edge->next;
            for (ContourNode_t* node = edge->node; node != nullptr;) {
                ContourNode_t* nextNode = node->next;
                node->next = nodesPool;
                nodesPool = node;
                node = nextNode;
            }
            edge->node = nullptr;
            edge->next = edgesPool;
            edgesPool = edge;
            edge = nextEdge;
        }
        contour->edges = nullptr;
        contour->next = contoursPool;
        contoursPool = contour;
        contour = nextContour;
    }
}

Contour* ContourManager::Create(const idList<idVec2i, 5>& input) {
    std::vector<idVec2i> points;
    points.reserve(input.Num());
    for (int index = 0; index < input.Num(); ++index) {
        if (points.empty() || points.back() != input[index]) {
            points.push_back(input[index]);
        }
    }
    if (points.size() > 1 && points.front() == points.back()) {
        points.pop_back();
    }

    bool changed = true;
    while (changed && points.size() >= 3) {
        changed = false;
        for (std::size_t index = 0; index < points.size(); ++index) {
            const idVec2i& previous = points[(index + points.size() - 1) %
                points.size()];
            const idVec2i& current = points[index];
            const idVec2i& following = points[(index + 1) % points.size()];
            if (Contour::SlopesEqual(previous, current, following) &&
                    PointBetween(current, previous, following)) {
                points.erase(points.begin() + index);
                changed = true;
                break;
            }
        }
    }
    if (points.size() < 3) return nullptr;

    Contour* contour = AllocContour();
    ContourEdge_t** edgeTail = &contour->edges;
    int minX = std::numeric_limits<int>::max();
    int minY = std::numeric_limits<int>::max();
    int maxX = std::numeric_limits<int>::min();
    int maxY = std::numeric_limits<int>::min();
    for (std::size_t index = 0; index < points.size(); ++index) {
        const idVec2i& start = points[index];
        const idVec2i& end = points[(index + 1) % points.size()];
        minX = std::min(minX, start.x);
        minY = std::min(minY, start.y);
        maxX = std::max(maxX, start.x);
        maxY = std::max(maxY, start.y);

        ContourEdge_t* edge = AllocEdge();
        ContourNode_t* first = AllocNode();
        ContourNode_t* second = AllocNode();
        first->pos = start;
        second->pos = end;
        first->next = second;
        edge->node = first;
        *edgeTail = edge;
        edgeTail = &edge->next;
        ++contour->numEdges;
    }
    contour->bound[0].Set(static_cast<float>(minX - 1),
        static_cast<float>(minY - 1));
    contour->bound[1].Set(static_cast<float>(maxX + 1),
        static_cast<float>(maxY + 1));
    return contour;
}

void ContourManager::SplitEdge(ContourEdge_t* edge, const idVec2i& v0,
        const idVec2i& v1, const idVec2i& pos) {
    if (edge == nullptr || pos == v0 || pos == v1) return;
    for (ContourNode_t* node = edge->node; node != nullptr &&
            node->next != nullptr; node = node->next) {
        if (!((node->pos == v0 && node->next->pos == v1) ||
                (node->pos == v1 && node->next->pos == v0))) {
            continue;
        }
        if (!PointBetween(pos, node->pos, node->next->pos)) return;
        ContourNode_t* inserted = AllocNode();
        inserted->pos = pos;
        inserted->next = node->next;
        node->next = inserted;
        return;
    }
}

void ContourManager::Merge(Contour* contours) {
    // Matching collinear contour edges must contain identical subdivision
    // points before the graph builder links them.  Propagate every point on an
    // overlapping edge to the other edge; iteration handles multiple partial
    // overlaps on the same line.
    bool changed = true;
    while (changed) {
        changed = false;
        for (Contour* firstContour = contours; firstContour != nullptr;
                firstContour = firstContour->next) {
            for (ContourEdge_t* first = firstContour->edges; first != nullptr;
                    first = first->next) {
                for (Contour* secondContour = firstContour;
                        secondContour != nullptr;
                        secondContour = secondContour->next) {
                    ContourEdge_t* secondStart = secondContour == firstContour
                        ? first->next : secondContour->edges;
                    for (ContourEdge_t* second = secondStart; second != nullptr;
                            second = second->next) {
                        if (!EdgesOverlap(first, second)) continue;
                        const std::vector<idVec2i> firstPoints =
                            EdgePoints(first);
                        const std::vector<idVec2i> secondPoints =
                            EdgePoints(second);

                        for (const idVec2i& point : secondPoints) {
                            if (HasPoint(first, point)) continue;
                            for (ContourNode_t* node = first->node;
                                    node != nullptr && node->next != nullptr;
                                    node = node->next) {
                                if (!PointBetween(point, node->pos,
                                        node->next->pos)) continue;
                                const idVec2i start = node->pos;
                                const idVec2i end = node->next->pos;
                                SplitEdge(first, start, end, point);
                                changed = true;
                                break;
                            }
                        }
                        for (const idVec2i& point : firstPoints) {
                            if (HasPoint(second, point)) continue;
                            for (ContourNode_t* node = second->node;
                                    node != nullptr && node->next != nullptr;
                                    node = node->next) {
                                if (!PointBetween(point, node->pos,
                                        node->next->pos)) continue;
                                const idVec2i start = node->pos;
                                const idVec2i end = node->next->pos;
                                SplitEdge(second, start, end, point);
                                changed = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}
