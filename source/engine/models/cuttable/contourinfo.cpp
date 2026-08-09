#include "models/cuttable/contourinfo.h"

#include <cstdint>

namespace {

bool PointOnSegment(const idVec2i& point, const idVec2i& start,
        const idVec2i& end) {
    const std::int64_t dx = static_cast<std::int64_t>(end.x) - start.x;
    const std::int64_t dy = static_cast<std::int64_t>(end.y) - start.y;
    const std::int64_t px = static_cast<std::int64_t>(point.x) - start.x;
    const std::int64_t py = static_cast<std::int64_t>(point.y) - start.y;
    if (dx * py != dy * px) return false;
    const std::int64_t projection = px * dx + py * dy;
    return projection >= 0 && projection <= dx * dx + dy * dy;
}

bool ChainContainsPair(const ContourNode_t* node, const idVec2i& first,
        const idVec2i& second) {
    for (; node != nullptr; node = node->next) {
        if (node->pos != first) continue;
        for (const ContourNode_t* following = node->next;
                following != nullptr; following = following->next) {
            if (following->pos == second) return true;
        }
        return false;
    }
    return false;
}

} // namespace

bool Contour::SlopesEqual(const idVec2i& v1, const idVec2i& v2,
        const idVec2i& v3, const idVec2i& v4) {
    const std::int64_t dx1 = static_cast<std::int64_t>(v2.x) - v1.x;
    const std::int64_t dy1 = static_cast<std::int64_t>(v2.y) - v1.y;
    const std::int64_t dx2 = static_cast<std::int64_t>(v4.x) - v3.x;
    const std::int64_t dy2 = static_cast<std::int64_t>(v4.y) - v3.y;
    return dx1 * dy2 == dy1 * dx2;
}

bool Contour::SlopesEqual(const idVec2i& v1, const idVec2i& v2,
        const idVec2i& v3) {
    return SlopesEqual(v1, v2, v2, v3);
}

ContourEdge_t* Contour::FindEdge(const idVec2i& v0, const idVec2i& v1) {
    for (Contour* contour = this; contour != nullptr; contour = contour->next) {
        const idVec2 point0(static_cast<float>(v0.x), static_cast<float>(v0.y));
        const idVec2 point1(static_cast<float>(v1.x), static_cast<float>(v1.y));
        if (!contour->bound.ContainsPoint(point0) &&
                !contour->bound.ContainsPoint(point1)) {
            continue;
        }
        for (ContourEdge_t* edge = contour->edges; edge != nullptr;
                edge = edge->next) {
            if (ChainContainsPair(edge->node, v0, v1) ||
                    ChainContainsPair(edge->node, v1, v0)) {
                return edge;
            }
        }
    }
    return nullptr;
}

ContourNode_t* Contour::FindNode(ContourEdge_t* const edge,
        const idVec2i& v0, const idVec2i& v1) {
    if (edge == nullptr) return nullptr;
    for (ContourNode_t* node = edge->node; node != nullptr; node = node->next) {
        if (node->pos == v0) return node;
        if (node->pos != v1) continue;

        ContourNode_t* reversed = nullptr;
        ContourNode_t* current = edge->node;
        while (current != nullptr) {
            ContourNode_t* following = current->next;
            current->next = reversed;
            reversed = current;
            current = following;
        }
        edge->node = reversed;
        for (node = edge->node; node != nullptr; node = node->next) {
            if (node->pos == v0) return node;
        }
        return nullptr;
    }
    return nullptr;
}

bool Contour::ContainsPoint(const idVec2i& pos) const {
    bool inside = false;
    for (const ContourEdge_t* edge = edges; edge != nullptr; edge = edge->next) {
        const ContourNode_t* node = edge->node;
        if (node == nullptr) continue;
        for (const ContourNode_t* following = node->next; following != nullptr;
                node = following, following = following->next) {
            const idVec2i& start = node->pos;
            const idVec2i& end = following->pos;
            if (PointOnSegment(pos, start, end)) return true;

            const bool crosses = (start.y < pos.y && end.y >= pos.y) ||
                (end.y < pos.y && start.y >= pos.y);
            if (!crosses) continue;
            const double intersection = static_cast<double>(start.x) +
                static_cast<double>(pos.y - start.y) *
                static_cast<double>(end.x - start.x) /
                static_cast<double>(end.y - start.y);
            if (intersection < static_cast<double>(pos.x)) inside = !inside;
        }
    }
    return inside;
}
