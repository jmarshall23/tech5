#include "models/cuttable/cuttergraph.h"

#include "idlib/filesystem/file.h"
#include "models/cuttable/cuttercontour.h"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace {

constexpr std::uint32_t CUTTER_GRAPH_MAGIC = 0x48504743u; // CGPH
constexpr std::uint32_t CUTTER_GRAPH_VERSION = 1;

std::int64_t Cross(const idVec2i& a, const idVec2i& b,
        const idVec2i& point) {
    return (static_cast<std::int64_t>(b.x) - a.x) *
            (static_cast<std::int64_t>(point.y) - a.y) -
        (static_cast<std::int64_t>(b.y) - a.y) *
            (static_cast<std::int64_t>(point.x) - a.x);
}

bool PointOnSegment(const idVec2i& point, const idVec2i& a,
        const idVec2i& b) {
    if (Cross(a, b, point) != 0) return false;
    return point.x >= std::min(a.x, b.x) &&
        point.x <= std::max(a.x, b.x) &&
        point.y >= std::min(a.y, b.y) &&
        point.y <= std::max(a.y, b.y);
}

bool SegmentIntersection(const idVec2i& a, const idVec2i& b,
        const idVec2i& c, const idVec2i& d, idVec2i& result,
        double* fraction = nullptr) {
    const double abX = static_cast<double>(b.x) - a.x;
    const double abY = static_cast<double>(b.y) - a.y;
    const double cdX = static_cast<double>(d.x) - c.x;
    const double cdY = static_cast<double>(d.y) - c.y;
    const double denominator = abX * cdY - abY * cdX;
    if (std::fabs(denominator) < 1.0e-10) {
        const idVec2i candidates[4] = {a, b, c, d};
        for (const idVec2i& candidate : candidates) {
            if (PointOnSegment(candidate, a, b) &&
                    PointOnSegment(candidate, c, d)) {
                result = candidate;
                if (fraction != nullptr) {
                    const double lengthSqr = abX * abX + abY * abY;
                    *fraction = lengthSqr > 0.0
                        ? ((candidate.x - a.x) * abX +
                            (candidate.y - a.y) * abY) / lengthSqr
                        : 0.0;
                }
                return true;
            }
        }
        return false;
    }
    const double acX = static_cast<double>(c.x) - a.x;
    const double acY = static_cast<double>(c.y) - a.y;
    const double t = (acX * cdY - acY * cdX) / denominator;
    const double u = (acX * abY - acY * abX) / denominator;
    if (t < -1.0e-8 || t > 1.0 + 1.0e-8 ||
            u < -1.0e-8 || u > 1.0 + 1.0e-8) {
        return false;
    }
    result.Set(static_cast<int>(std::floor(a.x + t * abX + 0.5)),
        static_cast<int>(std::floor(a.y + t * abY + 0.5)));
    if (fraction != nullptr) *fraction = std::max(0.0, std::min(1.0, t));
    return true;
}

bool ContoursIntersect(const Contour* first, const Contour* second) {
    if (first == nullptr || second == nullptr ||
            !first->bound.IntersectBounds(second->bound)) {
        return false;
    }
    for (const ContourEdge_t* edgeA = first->edges; edgeA != nullptr;
            edgeA = edgeA->next) {
        for (const ContourNode_t* nodeA = edgeA->node;
                nodeA != nullptr && nodeA->next != nullptr;
                nodeA = nodeA->next) {
            for (const ContourEdge_t* edgeB = second->edges; edgeB != nullptr;
                    edgeB = edgeB->next) {
                for (const ContourNode_t* nodeB = edgeB->node;
                        nodeB != nullptr && nodeB->next != nullptr;
                        nodeB = nodeB->next) {
                    idVec2i intersection;
                    if (SegmentIntersection(nodeA->pos, nodeA->next->pos,
                            nodeB->pos, nodeB->next->pos, intersection)) {
                        return true;
                    }
                }
            }
        }
    }
    const ContourNode_t* firstNode = first->edges != nullptr
        ? first->edges->node : nullptr;
    const ContourNode_t* secondNode = second->edges != nullptr
        ? second->edges->node : nullptr;
    return (firstNode != nullptr && second->ContainsPoint(firstNode->pos)) ||
        (secondNode != nullptr && first->ContainsPoint(secondNode->pos));
}

std::vector<idVec2i> FlattenContour(const Contour* contour) {
    std::vector<idVec2i> result;
    for (const ContourEdge_t* edge = contour != nullptr ? contour->edges
            : nullptr; edge != nullptr; edge = edge->next) {
        for (const ContourNode_t* node = edge->node; node != nullptr;
                node = node->next) {
            if (result.empty() || result.back() != node->pos) {
                result.push_back(node->pos);
            }
        }
    }
    if (result.size() > 1 && result.front() == result.back()) {
        result.pop_back();
    }
    return result;
}

template<typename Type>
bool ReadValue(idFile* file, Type& value) {
    return file != nullptr && file->Read(&value, sizeof(value)) ==
        sizeof(value);
}

template<typename Type>
bool WriteValue(idFile* file, const Type& value) {
    return file != nullptr && file->Write(&value, sizeof(value)) ==
        sizeof(value);
}

bool ReadBytes(idFile* file, void* data, unsigned int bytes) {
    return bytes == 0 || (file != nullptr && file->Read(data, bytes) == bytes);
}

bool WriteBytes(idFile* file, const void* data, unsigned int bytes) {
    return bytes == 0 || (file != nullptr && file->Write(data, bytes) == bytes);
}

idVec3 MakePerpendicular(const idVec3& normal) {
    idVec3 basis = std::fabs(normal.z) > 0.7071067f
        ? idVec3(1.0f, 0.0f, 0.0f) : idVec3(0.0f, 0.0f, 1.0f);
    idVec3 result = basis.Cross(normal);
    if (result.NormalizeFast() == 0.0f) result.Set(1.0f, 0.0f, 0.0f);
    return result;
}

} // namespace

idCutterGraphManager::IDHeap::IDHeap()
    : isStatic(0), index(0), numBits(0) {
}

void idCutterGraphManager::IDHeap::Create(int requestedBits) {
    const int byteCount = ((std::max)(0, requestedBits) + 7) / 8 + 1;
    buffer.SetNum(byteCount);
    if (byteCount > 0) std::memset(buffer.Ptr(), 0, byteCount);
    index = 0;
    numBits = byteCount * 8;
}

int idCutterGraphManager::IDHeap::Alloc() {
    if (buffer.Num() == 0) return -1;
    const int firstByte = std::min<int>(index, buffer.Num() - 1);
    for (int pass = 0; pass < 2; ++pass) {
        const int begin = pass == 0 ? firstByte : 0;
        const int end = pass == 0 ? buffer.Num() : firstByte;
        for (int byteIndex = begin; byteIndex < end; ++byteIndex) {
            if (buffer[byteIndex] == 0xFFu) continue;
            for (int bit = 0; bit < 8; ++bit) {
                const unsigned char mask = static_cast<unsigned char>(1u << bit);
                if ((buffer[byteIndex] & mask) != 0) continue;
                const int id = byteIndex * 8 + bit;
                if (id >= numBits) return -1;
                buffer[byteIndex] |= mask;
                index = static_cast<std::uint32_t>(byteIndex);
                return id;
            }
        }
    }
    return -1;
}

void idCutterGraphManager::IDHeap::Free(int id) {
    if (id < 0 || id >= numBits || id / 8 >= buffer.Num()) return;
    buffer[id / 8] &= static_cast<unsigned char>(~(1u << (id & 7)));
    index = static_cast<std::uint32_t>(std::min<int>(index, id / 8));
}

void idCutterGraphManager::IDHeap::Write(idFile* file) const {
    const int count = buffer.Num();
    WriteValue(file, count);
    WriteBytes(file, buffer.Ptr(), static_cast<unsigned int>(count));
    const int savedIndex = static_cast<int>(index);
    const int savedStatic = static_cast<int>(isStatic);
    WriteValue(file, savedIndex);
    WriteValue(file, savedStatic);
    WriteValue(file, numBits);
}

void idCutterGraphManager::IDHeap::Read(idFile* file) {
    int count = 0;
    int savedIndex = 0;
    int savedStatic = 0;
    if (!ReadValue(file, count) || count < 0 || count > (1 << 20) ||
            !buffer.SetNum(count) ||
            !ReadBytes(file, buffer.Ptr(), static_cast<unsigned int>(count)) ||
            !ReadValue(file, savedIndex) || !ReadValue(file, savedStatic) ||
            !ReadValue(file, numBits)) {
        buffer.Clear();
        index = 0;
        isStatic = 0;
        numBits = 0;
        return;
    }
    index = static_cast<std::uint32_t>(std::max(0, savedIndex));
    isStatic = savedStatic != 0;
}

idCutterGraphManager::Graph::Graph()
    : lastNode(nullptr), prevNode(nullptr), contoursOuter(nullptr),
      contoursInner(nullptr), inverse(1.0f), orientation(1.0f),
      position(0.0f, 0.0f, 0.0f), normal(0.0f, 0.0f, 1.0f),
      left(1.0f, 0.0f, 0.0f), down(0.0f, -1.0f, 0.0f) {
}

void idCutterGraphManager::Graph::Acquire() {
    nodes.PreAllocate(1024);
    edges.PreAllocate(1024);
    links.PreAllocate(1024);
}

void idCutterGraphManager::Graph::AddNode(Node_t* node) {
    if (node == nullptr) return;
    if (node->id >= static_cast<std::uint32_t>(idheap.numBits)) {
        const int id = idheap.Alloc();
        node->id = id >= 0 ? static_cast<std::uint32_t>(id) : 0;
    }
    nodeHandle_t handle = {node};
    nodes.Append(handle);
}

void idCutterGraphManager::Graph::RemoveEdge(Edge_t* edge) {
    for (int index = 0; index < edges.Num(); ++index) {
        if (edges[index].data == edge) {
            edges.RemoveIndexFast(index);
            return;
        }
    }
}

void idCutterGraphManager::Graph::RemoveLink(Link_t* link) {
    for (int index = 0; index < links.Num(); ++index) {
        if (links[index].data == link) {
            links.RemoveIndexFast(index);
            return;
        }
    }
}

int idCutterGraphManager::Graph::FindNodeIndex(const idVec2i& pos,
        int threshold) const {
    const std::int64_t limit = static_cast<std::int64_t>(threshold) * threshold;
    for (int index = 0; index < nodes.Num(); ++index) {
        const Node_t* node = nodes[index].data;
        const std::int64_t dx = static_cast<std::int64_t>(node->pos.x) - pos.x;
        const std::int64_t dy = static_cast<std::int64_t>(node->pos.y) - pos.y;
        if (dx * dx + dy * dy <= limit) return index;
    }
    return -1;
}

int idCutterGraphManager::Graph::FindClosestNode(Edge_t* edge,
        const idVec2i& pos, int threshold) const {
    if (edge == nullptr) return -1;
    const std::int64_t limit = static_cast<std::int64_t>(threshold) * threshold;
    Node_t* candidates[2] = {edge->node1, edge->node2};
    int best = -1;
    std::int64_t bestDistance = limit + 1;
    for (Node_t* candidate : candidates) {
        const std::int64_t dx = static_cast<std::int64_t>(candidate->pos.x) - pos.x;
        const std::int64_t dy = static_cast<std::int64_t>(candidate->pos.y) - pos.y;
        const std::int64_t distance = dx * dx + dy * dy;
        if (distance <= limit && distance < bestDistance) {
            bestDistance = distance;
            best = FindNodeIndex(candidate->pos, 0);
        }
    }
    return best;
}

idCutterGraphManager::Edge_t* idCutterGraphManager::Graph::FindSplitEdge(
        const Node_t* source, const idVec2i& pos,
        idVec2i& intersection) const {
    Edge_t* best = nullptr;
    double bestFraction = 2.0;
    if (source == nullptr) return nullptr;
    for (int index = 0; index < edges.Num(); ++index) {
        Edge_t* edge = edges[index].data;
        if (edge->node1 == source || edge->node2 == source) continue;
        double fraction = 0.0;
        idVec2i hit;
        if (SegmentIntersection(source->pos, pos, edge->node1->pos,
                edge->node2->pos, hit, &fraction) && fraction < bestFraction) {
            bestFraction = fraction;
            intersection = hit;
            best = edge;
        }
    }
    return best;
}

idVec2i idCutterGraphManager::Graph::Local3DToLocal2D(
        const idVec3& localPoint) const {
    return idVec2i(static_cast<int>(std::floor(left.Dot(localPoint) + 0.5f)),
        static_cast<int>(std::floor(down.Dot(localPoint) + 0.5f)));
}

idVec2i idCutterGraphManager::Graph::GetLocal2D(const idVec3& point) const {
    return Local3DToLocal2D(inverse * (point - position));
}

idVec3 idCutterGraphManager::Graph::GetPosition3D(
        const idVec2i& point2d) const {
    const idVec3 local = left * static_cast<float>(point2d.x) +
        down * static_cast<float>(point2d.y);
    return position + orientation * local;
}

void idCutterGraphManager::Graph::SetPosition(const idVec3& newPosition,
        const idMat3& newOrientation) {
    position = newPosition;
    orientation = newOrientation;
    inverse = orientation;
    if (!inverse.InverseSelf()) inverse = idMat3(1.0f);
}

void idCutterGraphManager::Graph::BuildGraphTree(
        graphTree_t& tree) const {
    tree.positions.Clear();
    tree.branches.Clear();
    tree.endpoints.Clear();
    tree.intersections.Clear();
    std::unordered_set<const Edge_t*> visited;

    auto degree = [](const Node_t* node) {
        int count = 0;
        for (const Link_t* link = node != nullptr ? node->link : nullptr;
                link != nullptr; link = link->next) {
            if (link->edge != nullptr && link->edge->allocated) ++count;
        }
        return count;
    };
    auto appendBranch = [&](const Node_t* start, const Edge_t* startEdge) {
        if (start == nullptr || startEdge == nullptr ||
                visited.find(startEdge) != visited.end()) return;
        graphBranch_t branch = {tree.positions.Num(), 0};
        const Node_t* current = start;
        const Edge_t* edge = startEdge;
        tree.positions.Append(left * static_cast<float>(current->pos.x) +
            down * static_cast<float>(current->pos.y));
        ++branch.num;
        for (;;) {
            visited.insert(edge);
            const Node_t* next = edge->node1 == current
                ? edge->node2 : edge->node1;
            tree.positions.Append(left * static_cast<float>(next->pos.x) +
                down * static_cast<float>(next->pos.y));
            ++branch.num;
            if (next == start || degree(next) != 2) break;
            const Edge_t* following = nullptr;
            for (const Link_t* link = next->link; link != nullptr;
                    link = link->next) {
                if (link->edge != edge && link->edge->allocated) {
                    following = link->edge;
                    break;
                }
            }
            if (following == nullptr || visited.find(following) != visited.end())
                break;
            current = next;
            edge = following;
        }
        if (branch.num > 1) tree.branches.Append(branch);
    };

    for (int index = 0; index < nodes.Num(); ++index) {
        const Node_t* node = nodes[index].data;
        const int count = degree(node);
        const idVec3 local = left * static_cast<float>(node->pos.x) +
            down * static_cast<float>(node->pos.y);
        if (count == 1) tree.endpoints.Append(local);
        else if (count > 2) tree.intersections.Append(local);
        if (count == 2) continue;
        for (const Link_t* link = node->link; link != nullptr;
                link = link->next) {
            appendBranch(node, link->edge);
        }
    }
    for (int index = 0; index < edges.Num(); ++index) {
        appendBranch(edges[index].data->node1, edges[index].data);
    }
}

bool idCutterGraphManager::Graph::PathFind(
        idList<idVec2i, 5>& points) const {
    if (prevNode == nullptr || lastNode == nullptr) return false;
    std::queue<Node_t*> open;
    std::unordered_map<Node_t*, Node_t*> parent;
    open.push(prevNode);
    parent[prevNode] = nullptr;
    while (!open.empty() && parent.find(lastNode) == parent.end()) {
        Node_t* current = open.front();
        open.pop();
        for (Link_t* link = current->link; link != nullptr; link = link->next) {
            if (link->edge == nullptr || !link->edge->allocated ||
                    link->invalid != 0 || parent.find(link->node) != parent.end())
                continue;
            parent[link->node] = current;
            open.push(link->node);
        }
    }
    if (parent.find(lastNode) == parent.end()) return false;
    std::vector<idVec2i> reversePath;
    for (Node_t* node = lastNode; node != nullptr; node = parent[node]) {
        reversePath.push_back(node->pos);
    }
    for (auto it = reversePath.rbegin(); it != reversePath.rend(); ++it)
        points.Append(*it);
    return true;
}

void idCutterGraphManager::Graph::DebugDraw(idRenderWorld*, int) const {
    // Renderer debug primitives are supplied by the renderer recovery layer.
}

idCutterGraphManager::idCutterGraphManager()
    : contourManager(new ContourManager), graph(nullptr) {
    linksPool.PreAllocate(NUM_POOLLINKS);
    nodesPool.PreAllocate(NUM_POOLNODES);
    edgesPool.PreAllocate(NUM_POOLNODES);
    linksPoolBlock.PreAllocate(4);
    nodesPoolBlock.PreAllocate(4);
    edgesPoolBlock.PreAllocate(4);
}

idCutterGraphManager::~idCutterGraphManager() {
    for (int index = 0; index < graphs.Num(); ++index) FreeGraph(index);
    delete contourManager;
    contourManager = nullptr;
    for (int index = 0; index < linksPoolBlock.Num(); ++index)
        delete[] linksPoolBlock[index];
    for (int index = 0; index < nodesPoolBlock.Num(); ++index)
        delete[] nodesPoolBlock[index];
    for (int index = 0; index < edgesPoolBlock.Num(); ++index)
        delete[] edgesPoolBlock[index];
}

Contour* idCutterGraphManager::CreateContour(
        const idList<idVec2i, 5>& points) {
    return contourManager->Create(points);
}

void idCutterGraphManager::MergeContours(Contour* contour) {
    contourManager->Merge(contour);
}

void idCutterGraphManager::FreeContour(Contour* contour) {
    contourManager->Free(contour);
}

void idCutterGraphManager::PreAcquire() {
    if (graph != nullptr) graph->lastNode = nullptr;
}

void idCutterGraphManager::PreAllocatePools() {
    if (linksPool.Num() == 0) {
        Link_t* block = new Link_t[NUM_POOLLINKS];
        linksPoolBlock.Append(block);
        for (int index = 0; index < NUM_POOLLINKS; ++index)
            linksPool.Append(&block[index]);
    }
    if (nodesPool.Num() == 0) {
        Node_t* block = new Node_t[NUM_POOLNODES];
        nodesPoolBlock.Append(block);
        for (int index = 0; index < NUM_POOLNODES; ++index)
            nodesPool.Append(&block[index]);
    }
    if (edgesPool.Num() == 0) {
        Edge_t* block = new Edge_t[NUM_POOLNODES];
        edgesPoolBlock.Append(block);
        for (int index = 0; index < NUM_POOLNODES; ++index)
            edgesPool.Append(&block[index]);
    }
}

idCutterGraphManager::Link_t* idCutterGraphManager::AllocateLink() {
    if (linksPool.Num() == 0) PreAllocatePools();
    Link_t* link = linksPool[linksPool.Num() - 1];
    linksPool.RemoveIndexFast(linksPool.Num() - 1);
    std::memset(link, 0, sizeof(*link));
    link->allocated = 1;
    return link;
}

idCutterGraphManager::Node_t* idCutterGraphManager::AllocateNode() {
    if (nodesPool.Num() == 0) PreAllocatePools();
    Node_t* node = nodesPool[nodesPool.Num() - 1];
    nodesPool.RemoveIndexFast(nodesPool.Num() - 1);
    std::memset(node, 0, sizeof(*node));
    node->allocated = 1;
    return node;
}

idCutterGraphManager::Edge_t* idCutterGraphManager::AllocateEdge() {
    if (edgesPool.Num() == 0) PreAllocatePools();
    Edge_t* edge = edgesPool[edgesPool.Num() - 1];
    edgesPool.RemoveIndexFast(edgesPool.Num() - 1);
    std::memset(edge, 0, sizeof(*edge));
    edge->allocated = 1;
    return edge;
}

void idCutterGraphManager::FreeLink(Link_t* link) {
    if (link == nullptr || !link->allocated) return;
    link->allocated = 0;
    link->next = nullptr;
    linksPool.Append(link);
}

void idCutterGraphManager::FreeNode(Node_t* node) {
    if (node == nullptr || !node->allocated) return;
    if (graph != nullptr) graph->idheap.Free(static_cast<int>(node->id));
    node->allocated = 0;
    node->next = nullptr;
    node->link = nullptr;
    nodesPool.Append(node);
}

void idCutterGraphManager::FreeEdge(Edge_t* edge) {
    if (edge == nullptr || !edge->allocated) return;
    edge->allocated = 0;
    edge->next = nullptr;
    edgesPool.Append(edge);
}

void idCutterGraphManager::AddInvalidNode(Node_t* node) {
    if (node == nullptr) return;
    for (int index = 0; index < invalidNodes.Num(); ++index) {
        if (invalidNodes[index] == node) return;
    }
    invalidNodes.Append(node);
}

void idCutterGraphManager::ProcessLinks(Contour* contour, Node_t* node) {
    if (contour == nullptr || node == nullptr) return;
    int linkCount = 0;
    for (Link_t* link = node->link; link != nullptr; link = link->next)
        ++linkCount;
    if (linkCount < 3) return;

    for (Link_t* link = node->link; link != nullptr; link = link->next) {
        if (link->node == nullptr) continue;
        const idVec2i midpoint(
            (node->pos.x + link->node->pos.x) / 2,
            (node->pos.y + link->node->pos.y) / 2);
        if (!PointInPolygon(midpoint, contour->edges)) continue;

        bool followsBoundary = false;
        for (ContourEdge_t* edge = contour->edges;
                edge != nullptr && !followsBoundary; edge = edge->next) {
            for (ContourNode_t* point = edge->node;
                    point != nullptr && point->next != nullptr;
                    point = point->next) {
                if (PointOnSegment(node->pos, point->pos,
                            point->next->pos) &&
                        PointOnSegment(link->node->pos, point->pos,
                            point->next->pos)) {
                    followsBoundary = true;
                    break;
                }
            }
        }
        if (followsBoundary) {
            link->invalid = 2;
        } else {
            link->invalid |= 1;
            AddInvalidNode(node);
        }
    }
}

idCutterGraphManager::Node_t* idCutterGraphManager::GenerateNode(
        const idVec3&, const idVec2i& pos, int threshold) {
    if (graph == nullptr) return nullptr;
    const int found = graph->FindNodeIndex(pos, threshold);
    if (found >= 0) return graph->nodes[found].data;
    Node_t* node = AllocateNode();
    node->pos = pos;
    const int id = graph->idheap.Alloc();
    node->id = id >= 0 ? static_cast<std::uint32_t>(id) : 0;
    nodeHandle_t handle = {node};
    graph->nodes.Append(handle);
    return node;
}

void idCutterGraphManager::AddLink(Node_t* source, Node_t* destination,
        Edge_t* edge) {
    Link_t* first = AllocateLink();
    first->edge = edge;
    first->node = destination;
    first->next = source->link;
    source->link = first;
    Link_t* second = AllocateLink();
    second->edge = edge;
    second->node = source;
    second->next = destination->link;
    destination->link = second;
    graph->links.Append(linkHandle_t{first});
    graph->links.Append(linkHandle_t{second});
}

void idCutterGraphManager::RemoveLink(Node_t* source,
        Node_t* destination) {
    Node_t* nodes[2] = {source, destination};
    Node_t* targets[2] = {destination, source};
    for (int side = 0; side < 2; ++side) {
        Link_t** cursor = &nodes[side]->link;
        while (*cursor != nullptr && (*cursor)->node != targets[side])
            cursor = &(*cursor)->next;
        if (*cursor == nullptr) continue;
        Link_t* removed = *cursor;
        *cursor = removed->next;
        graph->RemoveLink(removed);
        FreeLink(removed);
    }
}

idCutterGraphManager::Edge_t* idCutterGraphManager::Connect(
        Node_t* source, Node_t* destination, Contour* contour,
        ContourEdge_t* contourEdge) {
    if (source == nullptr || destination == nullptr || source == destination)
        return nullptr;
    for (Link_t* link = source->link; link != nullptr; link = link->next) {
        if (link->node == destination) {
            if (contour != nullptr) link->edge->contour = contour;
            if (contourEdge != nullptr) link->edge->contourEdge = contourEdge;
            return link->edge;
        }
    }
    Edge_t* edge = AllocateEdge();
    edge->node1 = source;
    edge->node2 = destination;
    edge->contour = contour;
    edge->contourEdge = contourEdge;
    graph->edges.Append(edgeHandle_t{edge});
    AddLink(source, destination, edge);
    return edge;
}

void idCutterGraphManager::Disconnect(Edge_t* edge) {
    if (graph == nullptr || edge == nullptr || !edge->allocated) return;
    Node_t* first = edge->node1;
    Node_t* second = edge->node2;
    graph->RemoveEdge(edge);
    RemoveLink(first, second);
    FreeEdge(edge);
}

int idCutterGraphManager::AllocateGraph(const idStr& name,
        const idVec3& position, const idMat3& orientation,
        const idVec3& graphNormal, const idList<idVec3, 5>& points) {
    Graph* created = new Graph;
    created->SetPosition(position, orientation);
    created->normal = graphNormal;
    if (created->normal.NormalizeFast() == 0.0f)
        created->normal.Set(0.0f, 0.0f, 1.0f);
    created->left = MakePerpendicular(created->normal);
    created->down = created->normal.Cross(created->left);
    created->down.NormalizeFast();
    created->name = name;
    created->idheap.Create(1024);
    idList<idVec2i, 5> localPoints;
    for (int index = 0; index < points.Num(); ++index)
        localPoints.Append(created->Local3DToLocal2D(points[index]));
    created->contoursOuter = contourManager->Create(localPoints);
    if (created->contoursOuter == nullptr) {
        delete created;
        return -1;
    }
    graph_t handle = {created};
    for (int index = 0; index < graphs.Num(); ++index) {
        if (graphs[index].graph == nullptr) {
            graphs[index] = handle;
            return index;
        }
    }
    return graphs.Append(handle);
}

void idCutterGraphManager::Acquire(int id) {
    if (!IsGraphValid(id)) return;
    if (graph == graphs[id].graph) return;
    ReleaseGraph();
    graph = graphs[id].graph;
    graph->lastNode = nullptr;
    graph->prevNode = nullptr;
    graph->Acquire();
}

void idCutterGraphManager::ReleaseGraph(int) {
    graph = nullptr;
}

bool idCutterGraphManager::IsGraphValid(int id) const {
    return id >= 0 && id < graphs.Num() && graphs[id].graph != nullptr;
}

void idCutterGraphManager::FreeGraph(int id) {
    if (!IsGraphValid(id)) return;
    Graph* doomed = graphs[id].graph;
    if (graph == doomed) graph = nullptr;
    Graph* previousGraph = graph;
    graph = doomed;
    for (int index = 0; index < doomed->links.Num(); ++index)
        FreeLink(doomed->links[index].data);
    for (int index = 0; index < doomed->edges.Num(); ++index)
        FreeEdge(doomed->edges[index].data);
    for (int index = 0; index < doomed->nodes.Num(); ++index)
        FreeNode(doomed->nodes[index].data);
    graph = previousGraph;
    contourManager->Free(doomed->contoursOuter);
    contourManager->Free(doomed->contoursInner);
    delete doomed;
    graphs[id].graph = nullptr;
}

void idCutterGraphManager::SetPosition(int id, const idVec3& position,
        const idMat3& orientation) {
    if (IsGraphValid(id)) graphs[id].graph->SetPosition(position, orientation);
}

idVec2i idCutterGraphManager::GetLocal2D(const idVec3& point) const {
    return graph != nullptr ? graph->GetLocal2D(point) : idVec2i(0, 0);
}

idVec3 idCutterGraphManager::GetLocal3D(const idVec2& point2d) const {
    if (graph == nullptr) return idVec3(0.0f, 0.0f, 0.0f);
    return graph->left * point2d.x + graph->down * point2d.y;
}

void idCutterGraphManager::GetNormalVectors(int id, idVec3& normal_,
        idVec3& left_, idVec3& up_) const {
    if (!IsGraphValid(id)) {
        normal_.Zero(); left_.Zero(); up_.Zero(); return;
    }
    const Graph* selected = graphs[id].graph;
    normal_ = selected->normal;
    left_ = selected->left;
    up_ = -selected->down;
}

Contour* idCutterGraphManager::GetOuterContour(int id) const {
    return IsGraphValid(id) ? graphs[id].graph->contoursOuter : nullptr;
}

Contour* idCutterGraphManager::GetInnerContour(int id) const {
    return IsGraphValid(id) ? graphs[id].graph->contoursInner : nullptr;
}

void idCutterGraphManager::DebugDraw(int id, idRenderWorld* renderWorld,
        int lifeTime) const {
    if (IsGraphValid(id)) graphs[id].graph->DebugDraw(renderWorld, lifeTime);
}

bool idCutterGraphManager::PointInPolygon(const idVec2i& pos,
        const ContourEdge_t* edge) const {
    bool inside = false;
    for (; edge != nullptr; edge = edge->next) {
        for (const ContourNode_t* node = edge->node;
                node != nullptr && node->next != nullptr; node = node->next) {
            if (PointOnSegment(pos, node->pos, node->next->pos)) return true;
            const idVec2i& a = node->pos;
            const idVec2i& b = node->next->pos;
            if ((a.y > pos.y) == (b.y > pos.y)) continue;
            const double crossing = a.x + static_cast<double>(pos.y - a.y) *
                (b.x - a.x) / static_cast<double>(b.y - a.y);
            if (crossing > pos.x) inside = !inside;
        }
    }
    return inside;
}

bool idCutterGraphManager::BuildEdge(const idVec2i& destination) {
    if (graph == nullptr) return false;
    Node_t* destinationNode = GenerateNode(graph->GetPosition3D(destination),
        destination, 0);
    if (destinationNode == nullptr) return false;
    if (graph->lastNode == nullptr) {
        graph->lastNode = destinationNode;
        graph->prevNode = nullptr;
        return true;
    }
    Node_t* source = graph->lastNode;
    if (source == destinationNode) return false;

    struct Crossing { double fraction; Node_t* node; };
    std::vector<Crossing> crossings;
    crossings.push_back({0.0, source});
    crossings.push_back({1.0, destinationNode});

    const std::vector<edgeHandle_t> edgeSnapshot(graph->edges.Ptr(),
        graph->edges.Ptr() + graph->edges.Num());
    for (const edgeHandle_t& handle : edgeSnapshot) {
        Edge_t* edge = handle.data;
        if (edge == nullptr || !edge->allocated) continue;
        idVec2i hit;
        double fraction = 0.0;
        if (!SegmentIntersection(source->pos, destination,
                edge->node1->pos, edge->node2->pos, hit, &fraction)) continue;
        Node_t* crossing = GenerateNode(graph->GetPosition3D(hit), hit, 0);
        crossings.push_back({fraction, crossing});
        if (crossing != edge->node1 && crossing != edge->node2) {
            Node_t* first = edge->node1;
            Node_t* second = edge->node2;
            Contour* contour = edge->contour;
            ContourEdge_t* contourEdge = edge->contourEdge;
            Disconnect(edge);
            Connect(first, crossing, contour, contourEdge);
            Connect(crossing, second, contour, contourEdge);
            if (contourEdge != nullptr)
                contourManager->SplitEdge(contourEdge, first->pos,
                    second->pos, hit);
        }
    }

    for (Contour* contour = graph->contoursOuter; contour != nullptr;
            contour = contour->next) {
        for (ContourEdge_t* edge = contour->edges; edge != nullptr;
                edge = edge->next) {
            for (ContourNode_t* node = edge->node;
                    node != nullptr && node->next != nullptr;
                    node = node->next) {
                idVec2i hit;
                double fraction = 0.0;
                if (SegmentIntersection(source->pos, destination, node->pos,
                        node->next->pos, hit, &fraction)) {
                    crossings.push_back({fraction,
                        GenerateNode(graph->GetPosition3D(hit), hit, 0)});
                }
            }
        }
    }
    for (Contour* contour = graph->contoursInner; contour != nullptr;
            contour = contour->next) {
        for (ContourEdge_t* edge = contour->edges; edge != nullptr;
                edge = edge->next) {
            for (ContourNode_t* node = edge->node;
                    node != nullptr && node->next != nullptr;
                    node = node->next) {
                idVec2i hit;
                double fraction = 0.0;
                if (SegmentIntersection(source->pos, destination, node->pos,
                        node->next->pos, hit, &fraction)) {
                    crossings.push_back({fraction,
                        GenerateNode(graph->GetPosition3D(hit), hit, 0)});
                }
            }
        }
    }
    std::sort(crossings.begin(), crossings.end(),
        [](const Crossing& a, const Crossing& b) {
            return a.fraction < b.fraction;
        });
    crossings.erase(std::unique(crossings.begin(), crossings.end(),
        [](const Crossing& a, const Crossing& b) { return a.node == b.node; }),
        crossings.end());

    bool connected = false;
    for (std::size_t index = 0; index + 1 < crossings.size(); ++index) {
        Node_t* first = crossings[index].node;
        Node_t* second = crossings[index + 1].node;
        const idVec2i midpoint((first->pos.x + second->pos.x) / 2,
            (first->pos.y + second->pos.y) / 2);
        if (graph->contoursOuter != nullptr &&
                !graph->contoursOuter->ContainsPoint(midpoint)) continue;
        bool insideHole = false;
        for (Contour* hole = graph->contoursInner; hole != nullptr;
                hole = hole->next) {
            if (hole->ContainsPoint(midpoint) &&
                    hole->FindEdge(first->pos, second->pos) == nullptr) {
                insideHole = true;
                break;
            }
        }
        if (insideHole) continue;
        Contour* owner = nullptr;
        ContourEdge_t* ownerEdge = nullptr;
        for (Contour* candidate = graph->contoursInner; candidate != nullptr;
                candidate = candidate->next) {
            ownerEdge = candidate->FindEdge(first->pos, second->pos);
            if (ownerEdge != nullptr) { owner = candidate; break; }
        }
        if (ownerEdge == nullptr && graph->contoursOuter != nullptr) {
            ownerEdge = graph->contoursOuter->FindEdge(first->pos,
                second->pos);
            if (ownerEdge != nullptr) owner = graph->contoursOuter;
        }
        connected |= Connect(first, second, owner, ownerEdge) != nullptr;
    }
    graph->prevNode = source;
    graph->lastNode = destinationNode;
    return connected;
}

bool idCutterGraphManager::PathFind(idList<idVec2i, 5>& points) const {
    return graph != nullptr && graph->PathFind(points);
}

void idCutterGraphManager::BuildGraphTree(int id,
        graphTree_t& tree) const {
    if (IsGraphValid(id)) graphs[id].graph->BuildGraphTree(tree);
}

Contour* idCutterGraphManager::IntersectContours(Contour* contour) {
    if (graph == nullptr || contour == nullptr) return nullptr;
    Contour* removed = nullptr;
    Contour** cursor = &graph->contoursInner;
    while (*cursor != nullptr) {
        Contour* candidate = *cursor;
        if (!ContoursIntersect(contour, candidate)) {
            cursor = &candidate->next;
            continue;
        }
        *cursor = candidate->next;
        candidate->next = removed;
        removed = candidate;
    }
    return removed;
}

bool idCutterGraphManager::AddContour(Contour* contours,
        Contour* mergedContours) {
    if (graph == nullptr) return false;
    if (mergedContours != nullptr) contourManager->Merge(mergedContours);
    Contour* last = nullptr;
    for (Contour* contour = contours; contour != nullptr;) {
        Contour* followingContour = contour->next;
        for (ContourEdge_t* edge = contour->edges; edge != nullptr;
                edge = edge->next) {
            for (ContourNode_t* node = edge->node;
                    node != nullptr && node->next != nullptr;
                    node = node->next) {
                Node_t* first = GenerateNode(graph->GetPosition3D(node->pos),
                    node->pos, 2);
                Node_t* second = GenerateNode(
                    graph->GetPosition3D(node->next->pos), node->next->pos, 2);
                Connect(first, second, contour, edge);
            }
        }
        contour->next = graph->contoursInner;
        graph->contoursInner = contour;
        last = contour;
        contour = followingContour;
    }

    invalidNodes.Clear();
    for (int nodeIndex = graph->nodes.Num() - 1; nodeIndex >= 0;
            --nodeIndex) {
        Node_t* node = graph->nodes[nodeIndex].data;
        for (Link_t* link = node->link; link != nullptr; link = link->next)
            link->invalid = 0;

        bool removeNode = false;
        for (Contour* contour = graph->contoursInner;
                contour != nullptr; contour = contour->next) {
            if (!PointInPolygon(node->pos, contour->edges)) continue;
            bool onBoundary = false;
            for (ContourEdge_t* edge = contour->edges;
                    edge != nullptr && !onBoundary; edge = edge->next) {
                for (ContourNode_t* point = edge->node;
                        point != nullptr && point->next != nullptr;
                        point = point->next) {
                    if (PointOnSegment(node->pos, point->pos,
                            point->next->pos)) {
                        onBoundary = true;
                        break;
                    }
                }
            }
            if (onBoundary) continue;
            removeNode = true;
            break;
        }

        if (removeNode) {
            while (node->link != nullptr) Disconnect(node->link->edge);
            if (graph->lastNode == node) graph->lastNode = nullptr;
            if (graph->prevNode == node) graph->prevNode = nullptr;
            graph->nodes.RemoveIndexFast(nodeIndex);
            FreeNode(node);
            continue;
        }
        for (Contour* contour = graph->contoursInner;
                contour != nullptr; contour = contour->next)
            ProcessLinks(contour, node);
    }

    for (int invalidIndex = 0; invalidIndex < invalidNodes.Num();
            ++invalidIndex) {
        Node_t* node = invalidNodes[invalidIndex];
        for (Link_t* link = node->link; link != nullptr;) {
            Link_t* next = link->next;
            if ((link->invalid & 3) == 1) Disconnect(link->edge);
            link = next;
        }
    }

    std::vector<Edge_t*> remove;
    for (int index = 0; index < graph->edges.Num(); ++index) {
        Edge_t* edge = graph->edges[index].data;
        if (edge->contour != nullptr) continue;
        const idVec2i midpoint((edge->node1->pos.x + edge->node2->pos.x) / 2,
            (edge->node1->pos.y + edge->node2->pos.y) / 2);
        for (Contour* contour = contours != nullptr ? contours : last;
                contour != nullptr; contour = contour->next) {
            if (contour->ContainsPoint(midpoint)) {
                remove.push_back(edge);
                break;
            }
        }
    }
    for (Edge_t* edge : remove) Disconnect(edge);
    return true;
}

void idCutterGraphManager::ApplyGraph(Graph* newGraph) {
    graphs.Append(graph_t{newGraph});
}

void idCutterGraphManager::Write(idCutterGraphManager* manager,
        idFile* file, int graphHandle) {
    if (manager == nullptr || file == nullptr ||
            !manager->IsGraphValid(graphHandle)) return;
    Graph* selected = manager->graphs[graphHandle].graph;
    WriteValue(file, CUTTER_GRAPH_MAGIC);
    WriteValue(file, CUTTER_GRAPH_VERSION);
    const int nameLength = selected->name.Length();
    WriteValue(file, nameLength);
    WriteBytes(file, selected->name.c_str(), nameLength);
    WriteValue(file, selected->position);
    WriteValue(file, selected->orientation);
    WriteValue(file, selected->normal);
    WriteValue(file, selected->left);
    WriteValue(file, selected->down);
    selected->idheap.Write(file);

    const int nodeCount = selected->nodes.Num();
    WriteValue(file, nodeCount);
    for (int index = 0; index < nodeCount; ++index) {
        WriteValue(file, selected->nodes[index].data->pos);
        const std::uint32_t id = selected->nodes[index].data->id;
        WriteValue(file, id);
    }
    const int edgeCount = selected->edges.Num();
    WriteValue(file, edgeCount);
    for (int index = 0; index < edgeCount; ++index) {
        Edge_t* edge = selected->edges[index].data;
        int first = -1;
        int second = -1;
        for (int nodeIndex = 0; nodeIndex < nodeCount; ++nodeIndex) {
            if (selected->nodes[nodeIndex].data == edge->node1) first = nodeIndex;
            if (selected->nodes[nodeIndex].data == edge->node2) second = nodeIndex;
        }
        WriteValue(file, first);
        WriteValue(file, second);
    }
    auto writeContours = [&](Contour* contours) {
        int count = 0;
        for (Contour* current = contours; current != nullptr;
                current = current->next) ++count;
        WriteValue(file, count);
        for (Contour* current = contours; current != nullptr;
                current = current->next) {
            const std::vector<idVec2i> points = FlattenContour(current);
            const int pointCount = static_cast<int>(points.size());
            WriteValue(file, pointCount);
            WriteBytes(file, points.data(), pointCount * sizeof(idVec2i));
        }
    };
    writeContours(selected->contoursOuter);
    writeContours(selected->contoursInner);
}

void idCutterGraphManager::Read(idCutterGraphManager* manager,
        idFile* file) {
    if (manager == nullptr || file == nullptr) return;
    std::uint32_t magic = 0;
    std::uint32_t version = 0;
    int nameLength = 0;
    if (!ReadValue(file, magic) || !ReadValue(file, version) ||
            magic != CUTTER_GRAPH_MAGIC || version != CUTTER_GRAPH_VERSION ||
            !ReadValue(file, nameLength) || nameLength < 0 ||
            nameLength > (1 << 20)) return;
    std::vector<char> name(static_cast<std::size_t>(nameLength) + 1, '\0');
    if (!ReadBytes(file, name.data(), static_cast<unsigned int>(nameLength)))
        return;
    Graph* loaded = new Graph;
    loaded->name = name.data();
    if (!ReadValue(file, loaded->position) ||
            !ReadValue(file, loaded->orientation) ||
            !ReadValue(file, loaded->normal) ||
            !ReadValue(file, loaded->left) ||
            !ReadValue(file, loaded->down)) {
        delete loaded;
        return;
    }
    loaded->inverse = loaded->orientation;
    if (!loaded->inverse.InverseSelf()) loaded->inverse = idMat3(1.0f);
    loaded->idheap.Read(file);
    manager->PreAllocatePools();
    Graph* previous = manager->graph;
    manager->graph = loaded;
    int nodeCount = 0;
    if (!ReadValue(file, nodeCount) || nodeCount < 0 || nodeCount > (1 << 20)) {
        manager->graph = previous;
        delete loaded;
        return;
    }
    for (int index = 0; index < nodeCount; ++index) {
        idVec2i pos;
        std::uint32_t id = 0;
        if (!ReadValue(file, pos) || !ReadValue(file, id)) break;
        Node_t* node = manager->AllocateNode();
        node->pos = pos;
        node->id = id;
        loaded->nodes.Append(nodeHandle_t{node});
    }
    int edgeCount = 0;
    if (ReadValue(file, edgeCount) && edgeCount >= 0 &&
            edgeCount <= (1 << 20)) {
        for (int index = 0; index < edgeCount; ++index) {
            int first = -1;
            int second = -1;
            if (!ReadValue(file, first) || !ReadValue(file, second)) break;
            if (first >= 0 && first < loaded->nodes.Num() && second >= 0 &&
                    second < loaded->nodes.Num()) {
                manager->Connect(loaded->nodes[first].data,
                    loaded->nodes[second].data, nullptr);
            }
        }
    }
    auto readContours = [&](Contour*& contours) {
        int count = 0;
        if (!ReadValue(file, count) || count < 0 || count > (1 << 20)) return;
        Contour** tail = &contours;
        for (int contourIndex = 0; contourIndex < count; ++contourIndex) {
            int pointCount = 0;
            if (!ReadValue(file, pointCount) || pointCount < 0 ||
                    pointCount > (1 << 20)) return;
            idList<idVec2i, 5> points;
            points.SetNum(pointCount);
            if (!ReadBytes(file, points.Ptr(),
                    pointCount * sizeof(idVec2i))) return;
            Contour* contour = manager->contourManager->Create(points);
            if (contour != nullptr) {
                *tail = contour;
                tail = &contour->next;
            }
        }
    };
    readContours(loaded->contoursOuter);
    readContours(loaded->contoursInner);
    manager->graph = previous;
    manager->ApplyGraph(loaded);
}
