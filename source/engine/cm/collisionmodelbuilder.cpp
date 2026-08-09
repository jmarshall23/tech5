#include "cm/collisionmodelbuilder.h"

#include "cm/collisiongrid.h"
#include "cm/collisionmodel.h"
#include "cm/jobs/polygonmodel/polygonmodel.h"
#include "cm/jobs/polygonmodel/polygonmodeldata.h"
#include "idlib/geometry/tracemodel.h"
#include "idlib/containers/hashindex.h"
#include "idlib/lib_print.h"
#include "idlib/sys/sys_alloc.h"
#include "idlib/text/lexer.h"

#include <algorithm>
#include <cctype>
#include <cfloat>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <functional>
#include <malloc.h>
#include <string>
#include <vector>

namespace {

struct cm_procNode_t {
    idPlane plane;
    int children[2];
};

struct idBuildData {
    int numProcNodes = 0;
    cm_procNode_t* procNodes = nullptr;
    cm_windingList_t* cm_windingList = nullptr;
    cm_windingList_t* cm_outList = nullptr;
    cm_windingList_t* cm_tmpList = nullptr;
    idHashIndex* cm_vertexHash = nullptr;
    idHashIndex* cm_edgeHash = nullptr;
    idBounds cm_modelBounds;
    int cm_vertexShift = 1;
};

idBuildData buildData;

int Align(const int value, const int alignment) {
    return (value + alignment - 1) & ~(alignment - 1);
}

void* AllocBuildMemory(const std::size_t size, const bool clear = false) {
    return mem.AllocWithLocation(
        "engine/cm/collisionmodelbuilder.cpp : TAG_COLLISION",
        static_cast<unsigned int>(size), TAG_COLLISION, clear, ALIGN_16,
        HEAP_DEFAULTHEAP);
}

template<class Type>
Type* GrowBuildArray(Type* const oldArray, const int oldCount,
    const int newCapacity) {
    Type* const array = static_cast<Type*>(AllocBuildMemory(
        sizeof(Type) * static_cast<std::size_t>(newCapacity)));
    if (array == nullptr) {
        return nullptr;
    }
    if (oldArray != nullptr && oldCount > 0) {
        std::memcpy(array, oldArray,
            sizeof(Type) * static_cast<std::size_t>(oldCount));
    }
    mem.Free(oldArray, ALIGN_16);
    return array;
}

void AddBounds(idBounds& destination, const idBounds& source) {
    for (int axis = 0; axis < 3; ++axis) {
        destination[0][axis] = (std::min)(
            destination[0][axis], source[0][axis]);
        destination[1][axis] = (std::max)(
            destination[1][axis], source[1][axis]);
    }
}

bool BoundsOverlap(const idBounds& first, const idBounds& second,
    const float epsilon = 0.0f) {
    for (int axis = 0; axis < 3; ++axis) {
        if (first[0][axis] > second[1][axis] + epsilon
            || first[1][axis] < second[0][axis] - epsilon) {
            return false;
        }
    }
    return true;
}

int DirectedEdgeStart(const cm_buildModel_t* const model,
    const int edgeReference) {
    const cm_buildEdge_t& edge = model->edges[std::abs(edgeReference)];
    return edge.vertexNum[edgeReference < 0 ? 1 : 0];
}

int DirectedEdgeEnd(const cm_buildModel_t* const model,
    const int edgeReference) {
    const cm_buildEdge_t& edge = model->edges[std::abs(edgeReference)];
    return edge.vertexNum[edgeReference < 0 ? 0 : 1];
}

void CopyPolygonFields(cm_buildPolygon_t& destination,
    const cm_buildPolygon_t& source) {
    destination.plane = source.plane;
    destination.bounds = source.bounds;
    destination.contents = source.contents;
    destination.material = source.material;
    destination.primitiveNum = source.primitiveNum;
    destination.checkCount = 0;
}

class ProcTokenScanner {
public:
    ProcTokenScanner(const char* const begin, const char* const end)
        : current(begin), end(end) {
    }

    bool Read(std::string& token) {
        SkipWhitespace();
        token.clear();
        if (current == nullptr || current >= end) {
            return false;
        }
        const char first = *current;
        if (first == '{' || first == '}' || first == '('
            || first == ')' || first == '[' || first == ']') {
            token.push_back(*current++);
            return true;
        }
        if (first == '"') {
            ++current;
            while (current < end && *current != '"') {
                token.push_back(*current++);
            }
            if (current < end) {
                ++current;
            }
            return true;
        }
        while (current < end && !std::isspace(
                   static_cast<unsigned char>(*current))
               && std::strchr("{}()[]", *current) == nullptr) {
            token.push_back(*current++);
        }
        return !token.empty();
    }

    bool Expect(const char* const expected) {
        std::string token;
        return Read(token) && token == expected;
    }

    bool ReadInt(int& value) {
        std::string token;
        if (!Read(token)) {
            return false;
        }
        char* endPointer = nullptr;
        const long parsed = std::strtol(token.c_str(), &endPointer, 10);
        if (endPointer == token.c_str() || *endPointer != '\0') {
            return false;
        }
        value = static_cast<int>(parsed);
        return true;
    }

    bool ReadFloat(float& value) {
        std::string token;
        if (!Read(token)) {
            return false;
        }
        char* endPointer = nullptr;
        value = std::strtof(token.c_str(), &endPointer);
        return endPointer != token.c_str() && *endPointer == '\0';
    }

    bool SkipBracedSection() {
        if (!Expect("{")) {
            return false;
        }
        int depth = 1;
        std::string token;
        while (depth > 0 && Read(token)) {
            if (token == "{") {
                ++depth;
            } else if (token == "}") {
                --depth;
            }
        }
        return depth == 0;
    }

    const char* Position() const {
        return current;
    }

private:
    void SkipWhitespace() {
        while (current != nullptr && current < end) {
            if (std::isspace(static_cast<unsigned char>(*current))) {
                ++current;
                continue;
            }
            if (end - current >= 2 && current[0] == '/'
                && current[1] == '/') {
                current += 2;
                while (current < end && *current != '\n') {
                    ++current;
                }
                continue;
            }
            if (end - current >= 2 && current[0] == '/'
                && current[1] == '*') {
                current += 2;
                while (end - current >= 2
                       && !(current[0] == '*' && current[1] == '/')) {
                    ++current;
                }
                if (end - current >= 2) {
                    current += 2;
                }
                continue;
            }
            break;
        }
    }

    const char* current;
    const char* end;
};

bool ParseProcNodesFromScanner(ProcTokenScanner& scanner) {
    if (!scanner.Expect("{")) {
        return false;
    }
    int numNodes = 0;
    if (!scanner.ReadInt(numNodes) || numNodes < 0
        || numNodes > 0x1000000) {
        return false;
    }
    cm_procNode_t* nodes = nullptr;
    if (numNodes > 0) {
        nodes = static_cast<cm_procNode_t*>(AllocBuildMemory(
            sizeof(cm_procNode_t) * static_cast<std::size_t>(numNodes),
            true));
        if (nodes == nullptr) {
            return false;
        }
    }
    for (int index = 0; index < numNodes; ++index) {
        if (!scanner.Expect("(")
            || !scanner.ReadFloat(nodes[index].plane.a)
            || !scanner.ReadFloat(nodes[index].plane.b)
            || !scanner.ReadFloat(nodes[index].plane.c)
            || !scanner.ReadFloat(nodes[index].plane.d)
            || !scanner.Expect(")")
            || !scanner.ReadInt(nodes[index].children[0])
            || !scanner.ReadInt(nodes[index].children[1])) {
            mem.Free(nodes, ALIGN_16);
            return false;
        }
    }
    if (!scanner.Expect("}")) {
        mem.Free(nodes, ALIGN_16);
        return false;
    }
    mem.Free(buildData.procNodes, ALIGN_16);
    buildData.procNodes = nodes;
    buildData.numProcNodes = numNodes;
    return true;
}

} // namespace

int CM_R_CountChildren(cm_buildNode_t* const node) {
    if (node == nullptr || node->planeType == -1) {
        return 0;
    }
    return CM_R_CountChildren(node->children[1])
        + CM_R_CountChildren(node->children[0]) + 2;
}

void CM_R_TestOptimisation(cm_buildNode_t* node,
    int& numSavedPolygonIndices, int& numSavedPolytopeIndices) {
    while (node != nullptr && node->planeType != -1) {
        int numPolygons = 0;
        int numPolytopes = 0;
        for (cm_buildPolygonRef_t* reference = node->polygons;
             reference != nullptr; reference = reference->next) {
            ++numPolygons;
        }
        for (cm_buildPolytopeRef_t* reference = node->polytopes;
             reference != nullptr; reference = reference->next) {
            ++numPolytopes;
        }
        if (numPolygons != 0 || numPolytopes != 0) {
            const int savedCopies =
                CM_R_CountChildren(node->children[1])
                + CM_R_CountChildren(node->children[0]) + 1;
            numSavedPolygonIndices += savedCopies * numPolygons;
            numSavedPolytopeIndices += savedCopies * numPolytopes;
        }
        CM_R_TestOptimisation(node->children[0],
            numSavedPolygonIndices, numSavedPolytopeIndices);
        node = node->children[1];
    }
}

bool CM_R_InsideAllChildren(cm_buildNode_t* const node,
    const idBounds& bounds) {
    if (node == nullptr || node->planeType == -1) {
        return true;
    }
    const int axis = node->planeType;
    if (bounds[0][axis] >= node->planeDist
        || bounds[1][axis] <= node->planeDist) {
        return false;
    }
    return CM_R_InsideAllChildren(node->children[0], bounds)
        && CM_R_InsideAllChildren(node->children[1], bounds);
}

cm_buildNode_t* idCollisionModelBuilder::AllocNode(
    cm_buildModel_t* const model, int blockSize) {
    if (model == nullptr) {
        return nullptr;
    }
    blockSize = (std::max)(1, blockSize);
    if (model->nodeBlocks == nullptr
        || model->nodeBlocks->nextNode == nullptr) {
        const std::size_t allocationSize = sizeof(cm_buildNodeBlock_t)
            + sizeof(cm_buildNode_t) * static_cast<std::size_t>(blockSize);
        cm_buildNodeBlock_t* const block =
            static_cast<cm_buildNodeBlock_t*>(
                AllocBuildMemory(allocationSize, true));
        if (block == nullptr) {
            return nullptr;
        }
        block->size = static_cast<int>(allocationSize);
        block->nextNode = reinterpret_cast<cm_buildNode_t*>(block + 1);
        block->next = model->nodeBlocks;
        model->nodeBlocks = block;
        for (int index = 0; index + 1 < blockSize; ++index) {
            block->nextNode[index].parent = &block->nextNode[index + 1];
        }
        block->nextNode[blockSize - 1].parent = nullptr;
    }
    cm_buildNode_t* const node = model->nodeBlocks->nextNode;
    model->nodeBlocks->nextNode = node->parent;
    std::memset(node, 0, sizeof(*node));
    node->planeType = -1;
    ++model->numNodes;
    return node;
}

cm_buildPolygonRef_t* idCollisionModelBuilder::AllocPolygonReference(
    cm_buildModel_t* const model, int blockSize) {
    if (model == nullptr) {
        return nullptr;
    }
    blockSize = (std::max)(1, blockSize);
    if (model->polygonRefBlocks == nullptr
        || model->polygonRefBlocks->nextRef == nullptr) {
        const std::size_t allocationSize =
            sizeof(cm_buildPolygonRefBlock_t)
            + sizeof(cm_buildPolygonRef_t)
                * static_cast<std::size_t>(blockSize);
        cm_buildPolygonRefBlock_t* const block =
            static_cast<cm_buildPolygonRefBlock_t*>(
                AllocBuildMemory(allocationSize, true));
        if (block == nullptr) {
            return nullptr;
        }
        block->size = static_cast<int>(allocationSize);
        block->nextRef = reinterpret_cast<cm_buildPolygonRef_t*>(block + 1);
        block->next = model->polygonRefBlocks;
        model->polygonRefBlocks = block;
        for (int index = 0; index + 1 < blockSize; ++index) {
            block->nextRef[index].next = &block->nextRef[index + 1];
        }
        block->nextRef[blockSize - 1].next = nullptr;
    }
    cm_buildPolygonRef_t* const reference =
        model->polygonRefBlocks->nextRef;
    model->polygonRefBlocks->nextRef = reference->next;
    reference->next = nullptr;
    return reference;
}

cm_buildPolytopeRef_t* idCollisionModelBuilder::AllocPolytopeReference(
    cm_buildModel_t* const model, int blockSize) {
    if (model == nullptr) {
        return nullptr;
    }
    blockSize = (std::max)(1, blockSize);
    if (model->polytopeRefBlocks == nullptr
        || model->polytopeRefBlocks->nextRef == nullptr) {
        const std::size_t allocationSize =
            sizeof(cm_buildPolytopeRefBlock_t)
            + sizeof(cm_buildPolytopeRef_t)
                * static_cast<std::size_t>(blockSize);
        cm_buildPolytopeRefBlock_t* const block =
            static_cast<cm_buildPolytopeRefBlock_t*>(
                AllocBuildMemory(allocationSize, true));
        if (block == nullptr) {
            return nullptr;
        }
        block->size = static_cast<int>(allocationSize);
        block->nextRef = reinterpret_cast<cm_buildPolytopeRef_t*>(block + 1);
        block->next = model->polytopeRefBlocks;
        model->polytopeRefBlocks = block;
        for (int index = 0; index + 1 < blockSize; ++index) {
            block->nextRef[index].next = &block->nextRef[index + 1];
        }
        block->nextRef[blockSize - 1].next = nullptr;
    }
    cm_buildPolytopeRef_t* const reference =
        model->polytopeRefBlocks->nextRef;
    model->polytopeRefBlocks->nextRef = reference->next;
    reference->next = nullptr;
    return reference;
}

cm_buildPolygon_t* idCollisionModelBuilder::AllocPolygon(
    cm_buildModel_t* const model, const int numEdges) {
    if (model == nullptr || numEdges < 0) {
        return nullptr;
    }
    if (model->numPolygons + 1 > model->maxPolygons) {
        const int capacity = model->maxPolygons + 1024;
        cm_buildPolygon_t* const array = GrowBuildArray(
            model->polygons, model->numPolygons, capacity);
        if (array == nullptr) {
            return nullptr;
        }
        model->polygons = array;
        model->maxPolygons = capacity;
    }
    if (model->numPolygonEdges + numEdges > model->maxPolygonEdges) {
        int capacity = model->maxPolygonEdges;
        do {
            capacity += 1024;
        } while (capacity < model->numPolygonEdges + numEdges);
        int* const array = GrowBuildArray(model->polygonEdges,
            model->numPolygonEdges, capacity);
        if (array == nullptr) {
            return nullptr;
        }
        model->polygonEdges = array;
        model->maxPolygonEdges = capacity;
    }
    cm_buildPolygon_t* const polygon =
        &model->polygons[model->numPolygons++];
    std::memset(polygon, 0, sizeof(*polygon));
    polygon->numEdges = numEdges;
    polygon->firstEdge = model->numPolygonEdges;
    model->numPolygonEdges += numEdges;
    return polygon;
}

cm_buildPolytope_t* idCollisionModelBuilder::AllocPolytope(
    cm_buildModel_t* const model, const int numPlanes) {
    if (model == nullptr || numPlanes < 0) {
        return nullptr;
    }
    if (model->numPolytopes + 1 > model->maxPolytopes) {
        int growth = model->maxPolytopes > 256
            ? 256 : model->maxPolytopes;
        if (growth == 0) {
            growth = 4;
        }
        const int capacity = model->maxPolytopes + growth;
        cm_buildPolytope_t* const array = GrowBuildArray(
            model->polytopes, model->numPolytopes, capacity);
        if (array == nullptr) {
            return nullptr;
        }
        model->polytopes = array;
        model->maxPolytopes = capacity;
    }
    if (model->numPolytopePlanes + numPlanes
        > model->maxPolytopePlanes) {
        int growth = model->maxPolytopePlanes > 256
            ? 256 : model->maxPolytopePlanes;
        if (growth == 0) {
            growth = 8;
        }
        int capacity = model->maxPolytopePlanes;
        do {
            capacity += growth;
            growth = (std::min)(growth * 2, 256);
        } while (capacity < model->numPolytopePlanes + numPlanes);
        idPlane* const array = GrowBuildArray(model->polytopePlanes,
            model->numPolytopePlanes, capacity);
        if (array == nullptr) {
            return nullptr;
        }
        model->polytopePlanes = array;
        model->maxPolytopePlanes = capacity;
    }
    cm_buildPolytope_t* const polytope =
        &model->polytopes[model->numPolytopes++];
    std::memset(polytope, 0, sizeof(*polytope));
    polytope->numPlanes = numPlanes;
    polytope->firstPlane = model->numPolytopePlanes;
    model->numPolytopePlanes += numPlanes;
    return polytope;
}

void idCollisionModelBuilder::AddPolygonToNode(cm_buildModel_t* const model,
    cm_buildNode_t* const node, cm_buildPolygon_t* const polygon) {
    if (model == nullptr || node == nullptr || polygon == nullptr) {
        return;
    }
    const int blockSize = model->numPolygonRefs < 8 ? 8 : 256;
    cm_buildPolygonRef_t* const reference =
        AllocPolygonReference(model, blockSize);
    if (reference != nullptr) {
        reference->polygonNum = static_cast<int>(polygon - model->polygons);
        reference->next = node->polygons;
        node->polygons = reference;
        ++model->numPolygonRefs;
    }
}

void idCollisionModelBuilder::AddPolytopeToNode(
    cm_buildModel_t* const model, cm_buildNode_t* const node,
    cm_buildPolytope_t* const polytope) {
    if (model == nullptr || node == nullptr || polytope == nullptr) {
        return;
    }
    const int blockSize = model->numPolytopeRefs < 8 ? 8 : 256;
    cm_buildPolytopeRef_t* const reference =
        AllocPolytopeReference(model, blockSize);
    if (reference != nullptr) {
        reference->polytopeNum = static_cast<int>(polytope - model->polytopes);
        reference->next = node->polytopes;
        node->polytopes = reference;
        ++model->numPolytopeRefs;
    }
}

void idCollisionModelBuilder::GetPrimitiveCounts(
    const cm_buildNode_t* const node, int& polygonCount,
    int& polytopeCount) {
    polygonCount = 0;
    polytopeCount = 0;
    if (node == nullptr) {
        return;
    }
    for (const cm_buildPolygonRef_t* reference = node->polygons;
         reference != nullptr; reference = reference->next) {
        ++polygonCount;
    }
    for (const cm_buildPolytopeRef_t* reference = node->polytopes;
         reference != nullptr; reference = reference->next) {
        ++polytopeCount;
    }
}

int idCollisionModelBuilder::GetNodeContents(
    const cm_buildModel_t* const model, const cm_buildNode_t* node) {
    if (model == nullptr || node == nullptr) {
        return 0;
    }
    int contents = 0;
    while (node != nullptr) {
        for (const cm_buildPolygonRef_t* reference = node->polygons;
             reference != nullptr; reference = reference->next) {
            contents |= model->polygons[reference->polygonNum].contents;
        }
        for (const cm_buildPolytopeRef_t* reference = node->polytopes;
             reference != nullptr; reference = reference->next) {
            contents |= model->polytopes[reference->polytopeNum].contents;
        }
        if (node->planeType == -1) {
            break;
        }
        contents |= GetNodeContents(model, node->children[1]);
        node = node->children[0];
    }
    return contents;
}

void idCollisionModelBuilder::FindSubModels_r(
    const cm_buildModel_t*, cm_buildNode_t* buildNode,
    int& numModelTreeNodes, int& numSubModels) {
    while (buildNode != nullptr) {
        if (buildNode->stats.canCreateSubModel) {
            ++numSubModels;
            return;
        }
        ++numModelTreeNodes;
        if (buildNode->planeType == -1) {
            return;
        }
        FindSubModels_r(nullptr, buildNode->children[0],
            numModelTreeNodes, numSubModels);
        buildNode = buildNode->children[1];
    }
}

void idCollisionModelBuilder::FreeModelMemory(cm_buildModel_t* const model) {
    if (model == nullptr) {
        return;
    }
    while (model->polygonRefBlocks != nullptr) {
        cm_buildPolygonRefBlock_t* const block = model->polygonRefBlocks;
        model->polygonRefBlocks = block->next;
        mem.Free(block, ALIGN_16);
    }
    while (model->polytopeRefBlocks != nullptr) {
        cm_buildPolytopeRefBlock_t* const block = model->polytopeRefBlocks;
        model->polytopeRefBlocks = block->next;
        mem.Free(block, ALIGN_16);
    }
    while (model->nodeBlocks != nullptr) {
        cm_buildNodeBlock_t* const block = model->nodeBlocks;
        model->nodeBlocks = block->next;
        mem.Free(block, ALIGN_16);
    }
    mem.Free(model->polygonEdges, ALIGN_16);
    mem.Free(model->polygons, ALIGN_16);
    mem.Free(model->polytopePlanes, ALIGN_16);
    mem.Free(model->polytopes, ALIGN_16);
    mem.Free(model->edges, ALIGN_16);
    mem.Free(model->vertices, ALIGN_16);
    model->maxVertices = model->numVertices = 0;
    model->vertices = nullptr;
    model->maxEdges = model->numEdges = 0;
    model->edges = nullptr;
    model->maxPolygonEdges = model->numPolygonEdges = 0;
    model->polygonEdges = nullptr;
    model->maxPolygons = model->numPolygons = 0;
    model->polygons = nullptr;
    model->maxPolytopePlanes = model->numPolytopePlanes = 0;
    model->polytopePlanes = nullptr;
    model->maxPolytopes = model->numPolytopes = 0;
    model->polytopes = nullptr;
    model->numNodes = 0;
    model->node = nullptr;
    model->nodeBlocks = nullptr;
    model->polygonRefBlocks = nullptr;
    model->polytopeRefBlocks = nullptr;
    model->checkCount = 0;
    model->isWorldModel = false;
    model->numPolytopeRefs = model->numPolygonRefs = 0;
    model->numInternalEdges = model->numSharpEdges = 0;
    model->numRemovedPolys = model->numMergedPolys = 0;
}

void idCollisionModelBuilder::RemovePolygon(cm_buildModel_t* const model,
    cm_buildNode_t* node, const int polygonNum) {
    if (model == nullptr || node == nullptr || polygonNum < 0
        || polygonNum >= model->numPolygons) {
        return;
    }
    while (node != nullptr) {
        cm_buildPolygonRef_t* previous = nullptr;
        cm_buildPolygonRef_t* reference = node->polygons;
        while (reference != nullptr) {
            cm_buildPolygonRef_t* const next = reference->next;
            if (reference->polygonNum == polygonNum) {
                if (previous != nullptr) {
                    previous->next = next;
                } else {
                    node->polygons = next;
                }
                --model->numPolygonRefs;
            } else {
                previous = reference;
            }
            reference = next;
        }
        if (node->planeType == -1) {
            return;
        }
        const cm_buildPolygon_t& polygon = model->polygons[polygonNum];
        const int axis = node->planeType;
        if (polygon.bounds[0][axis] <= node->planeDist) {
            if (polygon.bounds[1][axis] >= node->planeDist) {
                RemovePolygon(model, node->children[1], polygonNum);
                node = node->children[0];
            } else {
                node = node->children[1];
            }
        } else {
            node = node->children[0];
        }
    }
}

bool idCollisionModelBuilder::PointInsidePolygon(
    cm_buildModel_t* const model, cm_buildPolygon_t* const polygon,
    const idVec3& point) {
    if (model == nullptr || polygon == nullptr) {
        return false;
    }
    const idVec3 normal(polygon->plane.a, polygon->plane.b,
        polygon->plane.c);
    for (int edgeIndex = 0; edgeIndex < polygon->numEdges; ++edgeIndex) {
        const int reference =
            model->polygonEdges[polygon->firstEdge + edgeIndex];
        const cm_buildEdge_t& edge = model->edges[std::abs(reference)];
        const int startVertex = reference < 0
            ? edge.vertexNum[1] : edge.vertexNum[0];
        const int endVertex = reference < 0
            ? edge.vertexNum[0] : edge.vertexNum[1];
        const idVec3& start = model->vertices[startVertex].p;
        const idVec3& end = model->vertices[endVertex].p;
        const idVec3 delta = end - start;
        const idVec3 relative = point - start;
        const float side =
            (normal.x * delta.z - normal.z * delta.x) * relative.y
            + (normal.z * delta.y - normal.y * delta.z) * relative.x
            + (normal.y * delta.x - normal.x * delta.y) * relative.z;
        if (side > 0.1f) {
            return false;
        }
    }
    return true;
}

bool idCollisionModelBuilder::SplitterDividesPrimitives(
    cm_buildModel_t* const model, const cm_buildNode_t* node,
    const int planeType, const float planeDist) {
    if (model == nullptr || node == nullptr || planeType < 0
        || planeType >= 3) {
        return false;
    }
    bool front = false;
    bool back = false;
    while (node != nullptr) {
        for (const cm_buildPolygonRef_t* reference = node->polygons;
             reference != nullptr; reference = reference->next) {
            const idBounds& bounds =
                model->polygons[reference->polygonNum].bounds;
            if (bounds[0][planeType] < planeDist) {
                if (bounds[1][planeType] <= planeDist) {
                    back = true;
                }
            } else {
                front = true;
            }
        }
        for (const cm_buildPolytopeRef_t* reference = node->polytopes;
             reference != nullptr; reference = reference->next) {
            const idBounds& bounds =
                model->polytopes[reference->polytopeNum].bounds;
            if (bounds[0][planeType] < planeDist) {
                if (bounds[1][planeType] <= planeDist) {
                    back = true;
                }
            } else {
                front = true;
            }
        }
        if (front && back) {
            return true;
        }
        node = node->parent;
    }
    return false;
}

void idCollisionModelBuilder::GetNodeBounds_r(
    const cm_buildModel_t* const model, const cm_buildNode_t* node,
    idBounds& bounds) {
    if (model == nullptr || node == nullptr) {
        return;
    }
    while (node != nullptr) {
        for (const cm_buildPolygonRef_t* reference = node->polygons;
             reference != nullptr; reference = reference->next) {
            AddBounds(bounds,
                model->polygons[reference->polygonNum].bounds);
        }
        for (const cm_buildPolytopeRef_t* reference = node->polytopes;
             reference != nullptr; reference = reference->next) {
            AddBounds(bounds,
                model->polytopes[reference->polytopeNum].bounds);
        }
        if (node->planeType == -1) {
            return;
        }
        GetNodeBounds_r(model, node->children[1], bounds);
        node = node->children[0];
    }
}

void idCollisionModelBuilder::GetNodeBounds(
    const cm_buildModel_t* const model, const cm_buildNode_t* const node,
    idBounds& bounds) {
    bounds[0].Set(1.0e30f, 1.0e30f, 1.0e30f);
    bounds[1].Set(-1.0e30f, -1.0e30f, -1.0e30f);
    GetNodeBounds_r(model, node, bounds);
    if (bounds[0].x > bounds[1].x) {
        bounds[0].Zero();
        bounds[1].Zero();
    }
}

void idCollisionModelBuilder::GetStatsFromNode(
    const cm_buildModel_t* const buildModel,
    const cm_buildNode_t* const buildNode, cm_buildNodeStats_t& stats) {
    if (buildModel == nullptr || buildNode == nullptr) {
        return;
    }
    cm_buildModel_t* const writable = const_cast<cm_buildModel_t*>(
        buildModel);
    for (const cm_buildPolygonRef_t* reference = buildNode->polygons;
         reference != nullptr; reference = reference->next) {
        ++stats.numPrimitiveIndices;
        cm_buildPolygon_t& polygon =
            writable->polygons[reference->polygonNum];
        if (polygon.checkCount == writable->checkCount) {
            continue;
        }
        polygon.checkCount = writable->checkCount;
        ++stats.numPolygons;
        stats.numPolygonEdges += polygon.numEdges;
        stats.lastNumPolygonEdges = polygon.numEdges;
        for (int index = 0; index < polygon.numEdges; ++index) {
            cm_buildEdge_t& edge = writable->edges[std::abs(
                writable->polygonEdges[polygon.firstEdge + index])];
            if (edge.checkCount == writable->checkCount) {
                continue;
            }
            edge.checkCount = writable->checkCount;
            ++stats.numEdges;
            for (int endpoint = 0; endpoint < 2; ++endpoint) {
                cm_buildVertex_t& vertex =
                    writable->vertices[edge.vertexNum[endpoint]];
                if (vertex.checkCount != writable->checkCount) {
                    vertex.checkCount = writable->checkCount;
                    ++stats.numVertices;
                }
            }
        }
        cm_buildMaterial_t& material =
            writable->materials[polygon.material];
        if (material.checkCount != writable->checkCount) {
            material.checkCount = writable->checkCount;
            ++stats.numMaterials;
        }
    }
    for (const cm_buildPolytopeRef_t* reference = buildNode->polytopes;
         reference != nullptr; reference = reference->next) {
        ++stats.numPrimitiveIndices;
        cm_buildPolytope_t& polytope =
            writable->polytopes[reference->polytopeNum];
        if (polytope.checkCount == writable->checkCount) {
            continue;
        }
        polytope.checkCount = writable->checkCount;
        ++stats.numPolytopes;
        stats.numPolytopePlanes += polytope.numPlanes;
        cm_buildMaterial_t& material =
            writable->materials[polytope.material];
        if (material.checkCount != writable->checkCount) {
            material.checkCount = writable->checkCount;
            ++stats.numMaterials;
        }
    }
}

void idCollisionModelBuilder::CreateStatsForSubTree_r(
    const cm_buildModel_t* const buildModel,
    const cm_buildNode_t* buildNode, cm_buildNodeStats_t& stats) {
    while (buildNode != nullptr) {
        ++stats.numNodes;
        GetStatsFromNode(buildModel, buildNode, stats);
        if (buildNode->planeType == -1) {
            return;
        }
        CreateStatsForSubTree_r(buildModel, buildNode->children[0], stats);
        buildNode = buildNode->children[1];
    }
}

bool idCollisionModelBuilder::TestBoundsRange(const char* const modelName,
    const idBounds& bounds) {
    for (int axis = 0; axis < 3; ++axis) {
        if (bounds[0][axis] < -32768.0f
            || bounds[1][axis] > 32767.0f) {
            idLibPrint::Warning(
                "model '%s' [%1.0f, %1.0f, %1.0f] - "
                "[%1.0f, %1.0f, %1.0f] out of range",
                modelName != nullptr ? modelName : "<unnamed>",
                bounds[0].x, bounds[0].y, bounds[0].z,
                bounds[1].x, bounds[1].y, bounds[1].z);
            return true;
        }
    }
    return false;
}

void idCollisionModelBuilder::ParseProcNodes(idLexer* const source) {
    if (source == nullptr || source->script_p == nullptr
        || source->end_p == nullptr || source->script_p > source->end_p) {
        idLibPrint::Warning("ParseProcNodes: invalid lexer source");
        return;
    }
    ProcTokenScanner scanner(source->script_p, source->end_p);
    if (!ParseProcNodesFromScanner(scanner)) {
        idLibPrint::Warning("ParseProcNodes: malformed proc node block");
        return;
    }
    source->script_p = scanner.Position();
}

void idCollisionModelBuilder::LoadProcBSP(const char* const name) {
    mem.Free(buildData.procNodes, ALIGN_16);
    buildData.procNodes = nullptr;
    buildData.numProcNodes = 0;
    if (name == nullptr || *name == '\0') {
        return;
    }
    std::string fileName(name);
    const std::size_t slash = fileName.find_last_of("/\\");
    const std::size_t dot = fileName.find_last_of('.');
    if (dot == std::string::npos
        || (slash != std::string::npos && dot < slash)) {
        fileName += ".proc";
    } else {
        fileName.replace(dot, std::string::npos, ".proc");
    }
    std::ifstream input(fileName, std::ios::binary);
    if (!input) {
        idLibPrint::Warning(
            "idCollisionModelBuilder::LoadProcBSP: couldn't load %s",
            fileName.c_str());
        return;
    }
    std::string text((std::istreambuf_iterator<char>(input)),
        std::istreambuf_iterator<char>());
    ProcTokenScanner scanner(text.data(), text.data() + text.size());
    std::string token;
    if (!scanner.Read(token)
        || (token != "mapProcFile006" && token != "mapProcFile005")) {
        idLibPrint::Warning(
            "idCollisionModelBuilder::LoadProcBSP: bad proc file id");
        return;
    }
    while (scanner.Read(token)) {
        if (token == "nodes") {
            if (!ParseProcNodesFromScanner(scanner)) {
                idLibPrint::Warning(
                    "idCollisionModelBuilder::LoadProcBSP: malformed nodes");
            }
            return;
        }
        if (token == "model" || token == "shadowModel"
            || token == "interAreaPortals" || token == "areas") {
            if (!scanner.SkipBracedSection()) {
                break;
            }
        }
    }
    idLibPrint::Warning(
        "idCollisionModelBuilder::LoadProcBSP: nodes section not found");
}

void idCollisionModelBuilder::SetupHash() {
    if (buildData.cm_vertexHash == nullptr) {
        buildData.cm_vertexHash = new idHashIndex(4096, 1024,
            TAG_COLLISION);
    }
    if (buildData.cm_edgeHash == nullptr) {
        buildData.cm_edgeHash = new idHashIndex(0x4000, 1024,
            TAG_COLLISION);
    }
    if (buildData.cm_windingList == nullptr) {
        buildData.cm_windingList = new cm_windingList_t{};
    }
    if (buildData.cm_outList == nullptr) {
        buildData.cm_outList = new cm_windingList_t{};
    }
    if (buildData.cm_tmpList == nullptr) {
        buildData.cm_tmpList = new cm_windingList_t{};
    }
}

void idCollisionModelBuilder::ClearHash(const idBounds& bounds) {
    SetupHash();
    buildData.cm_vertexHash->Clear();
    buildData.cm_edgeHash->Clear();
    buildData.cm_modelBounds = bounds;
    const float maximumExtent = (std::max)(bounds[1].x - bounds[0].x,
        (std::max)(bounds[1].y - bounds[0].y,
            bounds[1].z - bounds[0].z));
    const int target = static_cast<int>(maximumExtent * (1.0f / 64.0f));
    int shift = 1;
    int power = 2;
    while (power < target) {
        power <<= 1;
        ++shift;
    }
    buildData.cm_vertexShift = shift;
}

void idCollisionModelBuilder::ShutdownHash() {
    delete buildData.cm_vertexHash;
    buildData.cm_vertexHash = nullptr;
    delete buildData.cm_edgeHash;
    buildData.cm_edgeHash = nullptr;
    delete buildData.cm_tmpList;
    buildData.cm_tmpList = nullptr;
    delete buildData.cm_outList;
    buildData.cm_outList = nullptr;
    delete buildData.cm_windingList;
    buildData.cm_windingList = nullptr;
    mem.Free(buildData.procNodes, ALIGN_16);
    buildData.procNodes = nullptr;
    buildData.numProcNodes = 0;
}

bool idCollisionModelBuilder::GetVertex(cm_buildModel_t* const model,
    const idVec3& inputVertex, int& vertexNum) {
    if (model == nullptr) {
        vertexNum = -1;
        return false;
    }
    if (buildData.cm_vertexHash == nullptr) {
        SetupHash();
    }
    idVec3 vertex = inputVertex;
    for (int axis = 0; axis < 3; ++axis) {
        const float rounded = std::floor(vertex[axis] + 0.5f);
        if (std::fabs(vertex[axis] - rounded) < 0.01f) {
            vertex[axis] = rounded;
        }
    }
    const int x = static_cast<int>(
        vertex.x - buildData.cm_modelBounds[0].x + 0.5f);
    const int y = static_cast<int>(
        vertex.y - buildData.cm_modelBounds[0].y + 0.5f);
    const int z = static_cast<int>(
        vertex.z - buildData.cm_modelBounds[0].z + 0.5f);
    const int key = ((((y + 2) >> 2) << 6)
        + ((z + 2) >> 2) + ((x + 2) >> 2)) & 0xFFF;
    for (int index = buildData.cm_vertexHash->First(key);
         index >= 0; index = buildData.cm_vertexHash->Next(index)) {
        const idVec3& existing = model->vertices[index].p;
        if (std::fabs(vertex.x - existing.x) < 0.1f
            && std::fabs(vertex.y - existing.y) < 0.1f
            && std::fabs(vertex.z - existing.z) < 0.1f) {
            vertexNum = index;
            return true;
        }
    }
    if (model->numVertices >= model->maxVertices) {
        const int capacity = static_cast<int>(
            model->maxVertices * 1.5f + 1.0f);
        cm_buildVertex_t* const array = GrowBuildArray(model->vertices,
            model->numVertices, capacity);
        if (array == nullptr) {
            vertexNum = -1;
            return false;
        }
        model->vertices = array;
        model->maxVertices = capacity;
        buildData.cm_vertexHash->ResizeIndex(capacity);
    }
    vertexNum = model->numVertices;
    cm_buildVertex_t& destination = model->vertices[model->numVertices++];
    std::memset(&destination, 0, sizeof(destination));
    destination.p = vertex;
    buildData.cm_vertexHash->Add(key, vertexNum);
    return false;
}

bool idCollisionModelBuilder::GetEdge(cm_buildModel_t* const model,
    const idVec3& vertex1, const idVec3& vertex2, int& edgeNum,
    int vertex1Num) {
    if (model == nullptr) {
        edgeNum = 0;
        return false;
    }
    if (buildData.cm_edgeHash == nullptr) {
        SetupHash();
    }
    if (model->numEdges == 0) {
        model->numEdges = 1;
    }
    bool firstExisted = true;
    if (vertex1Num == -1) {
        firstExisted = GetVertex(model, vertex1, vertex1Num);
    }
    int vertex2Num = -1;
    const bool secondExisted = GetVertex(model, vertex2, vertex2Num);
    if (vertex1Num == vertex2Num) {
        edgeNum = 0;
        return true;
    }
    const int key = (vertex1Num + vertex2Num)
        & buildData.cm_edgeHash->hashMask;
    if (firstExisted && secondExisted) {
        for (int index = buildData.cm_edgeHash->First(key);
             index >= 0; index = buildData.cm_edgeHash->Next(index)) {
            cm_buildEdge_t& edge = model->edges[index];
            if (edge.numUsers == 1 && edge.vertexNum[0] == vertex2Num
                && edge.vertexNum[1] == vertex1Num) {
                edgeNum = -index;
                ++edge.numUsers;
                return true;
            }
        }
    }
    if (model->numEdges >= model->maxEdges) {
        const int capacity = (std::max)(model->numEdges + 1,
            static_cast<int>(model->maxEdges * 1.5f + 1.0f));
        cm_buildEdge_t* const array = GrowBuildArray(model->edges,
            model->numEdges, capacity);
        if (array == nullptr) {
            edgeNum = 0;
            return false;
        }
        model->edges = array;
        model->maxEdges = capacity;
        buildData.cm_edgeHash->ResizeIndex(capacity);
    }
    edgeNum = model->numEdges;
    cm_buildEdge_t& edge = model->edges[model->numEdges++];
    std::memset(&edge, 0, sizeof(edge));
    edge.vertexNum[0] = vertex1Num;
    edge.vertexNum[1] = vertex2Num;
    edge.numUsers = 1;
    buildData.cm_edgeHash->Add(key, edgeNum);
    return false;
}

cm_buildModel_t* idCollisionModelBuilder::AllocBuildModel() {
    cm_buildModel_t* const model = new cm_buildModel_t{};
    model->isWorldModel = false;
    model->checkCount = 0;
    model->maxVertices = model->numVertices = 0;
    model->vertices = nullptr;
    model->maxEdges = model->numEdges = 0;
    model->edges = nullptr;
    model->maxPolygonEdges = model->numPolygonEdges = 0;
    model->polygonEdges = nullptr;
    model->maxPolygons = model->numPolygons = 0;
    model->polygons = nullptr;
    model->maxPolytopePlanes = model->numPolytopePlanes = 0;
    model->polytopePlanes = nullptr;
    model->maxPolytopes = model->numPolytopes = 0;
    model->polytopes = nullptr;
    model->numNodes = 0;
    model->node = nullptr;
    model->nodeBlocks = nullptr;
    model->polygonRefBlocks = nullptr;
    model->polytopeRefBlocks = nullptr;
    model->numPolytopeRefs = model->numPolygonRefs = 0;
    model->numInternalEdges = model->numSharpEdges = 0;
    model->numRemovedPolys = model->numMergedPolys = 0;
    return model;
}

int idCollisionModelBuilder::FindMaterial(cm_buildModel_t* const model,
    const int contentFlags, const int surfaceFlags,
    const int surfaceType) {
    if (model == nullptr) {
        return -1;
    }
    for (int index = 0; index < model->materials.Num(); ++index) {
        const cm_buildMaterial_t& material = model->materials[index];
        if (material.contentFlags == contentFlags
            && material.surfaceFlags == surfaceFlags
            && material.surfaceType == surfaceType) {
            return index;
        }
    }
    cm_buildMaterial_t material{};
    material.contentFlags = contentFlags;
    material.surfaceFlags = surfaceFlags;
    material.surfaceType = surfaceType;
    return model->materials.Append(material);
}

bool idCollisionModelBuilder::IsStaticRenderModel(
    const char* const fileName) {
    if (fileName == nullptr) {
        return false;
    }
    const char* extension = std::strrchr(fileName, '.');
    if (extension == nullptr) {
        return false;
    }
    ++extension;
    return _stricmp(extension, "ase") == 0
        || _stricmp(extension, "lwo") == 0
        || _stricmp(extension, "obj") == 0
        || _stricmp(extension, "model") == 0
        || _stricmp(extension, "bmodel") == 0;
}

void idCollisionModelBuilder::FilterPolygonIntoTree_r(
    cm_buildModel_t* const model, cm_buildNode_t* node,
    cm_buildPolygonRef_t* const reference,
    cm_buildPolygon_t* const polygon) {
    if (model == nullptr || node == nullptr || polygon == nullptr) {
        return;
    }
    while (node->planeType != -1) {
        if (CM_R_InsideAllChildren(node, polygon->bounds)) {
            break;
        }
        const int axis = node->planeType;
        if (polygon->bounds[0][axis] >= node->planeDist) {
            node = node->children[0];
        } else if (polygon->bounds[1][axis] <= node->planeDist) {
            node = node->children[1];
        } else {
            FilterPolygonIntoTree_r(model, node->children[1], nullptr,
                polygon);
            node = node->children[0];
        }
        if (node == nullptr) {
            return;
        }
    }
    if (reference != nullptr) {
        reference->next = node->polygons;
        node->polygons = reference;
    } else {
        AddPolygonToNode(model, node, polygon);
    }
}

void idCollisionModelBuilder::FilterPolytopeIntoTree_r(
    cm_buildModel_t* const model, cm_buildNode_t* node,
    cm_buildPolytopeRef_t* const reference,
    cm_buildPolytope_t* const polytope) {
    if (model == nullptr || node == nullptr || polytope == nullptr) {
        return;
    }
    while (node->planeType != -1) {
        if (CM_R_InsideAllChildren(node, polytope->bounds)) {
            break;
        }
        const int axis = node->planeType;
        if (polytope->bounds[0][axis] >= node->planeDist) {
            node = node->children[0];
        } else if (polytope->bounds[1][axis] <= node->planeDist) {
            node = node->children[1];
        } else {
            FilterPolytopeIntoTree_r(model, node->children[1], nullptr,
                polytope);
            node = node->children[0];
        }
        if (node == nullptr) {
            return;
        }
    }
    if (reference != nullptr) {
        reference->next = node->polytopes;
        node->polytopes = reference;
    } else {
        AddPolytopeToNode(model, node, polytope);
    }
}

bool idCollisionModelBuilder::FindSplitter(cm_buildModel_t* const model,
    const cm_buildNode_t* const node, const idBounds& bounds,
    int& planeType, float& planeDist) {
    if (model == nullptr || node == nullptr) {
        return false;
    }
    int polygonCount = 0;
    int polytopeCount = 0;
    GetPrimitiveCounts(node, polygonCount, polytopeCount);
    if (polygonCount <= 4 && polytopeCount <= 4) {
        return false;
    }

    int axes[3] = {0, 1, 2};
    std::sort(axes, axes + 3, [&bounds](const int left, const int right) {
        return bounds[1][left] - bounds[0][left]
            > bounds[1][right] - bounds[0][right];
    });
    const bool dense = polygonCount >= 32 || polytopeCount >= 32;
    float bestBalance = FLT_MAX;
    bool found = false;
    for (const int axis : axes) {
        const float extent = bounds[1][axis] - bounds[0][axis];
        if (!dense && extent < 128.0f) {
            continue;
        }
        for (const cm_buildNode_t* source = node; source != nullptr;
             source = source->parent) {
            for (const cm_buildPolytopeRef_t* reference = source->polytopes;
                 reference != nullptr; reference = reference->next) {
                const idBounds& primitiveBounds =
                    model->polytopes[reference->polytopeNum].bounds;
                for (int side = 0; side < 2; ++side) {
                    const float candidate = primitiveBounds[side][axis];
                    const float balance = std::fabs(
                        (bounds[1][axis] - candidate)
                        - (candidate - bounds[0][axis]));
                    if (candidate > bounds[0][axis]
                        && candidate < bounds[1][axis]
                        && balance < bestBalance
                        && SplitterDividesPrimitives(model, node, axis,
                            candidate)) {
                        planeType = axis;
                        planeDist = candidate;
                        bestBalance = balance;
                        found = true;
                    }
                }
            }
            for (const cm_buildPolygonRef_t* reference = source->polygons;
                 reference != nullptr; reference = reference->next) {
                const idBounds& primitiveBounds =
                    model->polygons[reference->polygonNum].bounds;
                for (int side = 0; side < 2; ++side) {
                    const float candidate = primitiveBounds[side][axis];
                    const float balance = std::fabs(
                        (bounds[1][axis] - candidate)
                        - (candidate - bounds[0][axis]));
                    if (candidate > bounds[0][axis]
                        && candidate < bounds[1][axis]
                        && balance < bestBalance
                        && SplitterDividesPrimitives(model, node, axis,
                            candidate)) {
                        planeType = axis;
                        planeDist = candidate;
                        bestBalance = balance;
                        found = true;
                    }
                }
            }
        }
        if (found && (dense
            || (planeDist - bounds[0][axis] >= 32.0f
                && bounds[1][axis] - planeDist >= 32.0f))) {
            return true;
        }
    }
    return false;
}

cm_buildNode_t* idCollisionModelBuilder::CreateAxialBSPTree_r(
    cm_buildModel_t* const model, cm_buildNode_t* const node) {
    if (model == nullptr || node == nullptr) {
        return node;
    }
    int planeType = -1;
    float planeDist = 0.0f;
    if (!FindSplitter(model, node, node->bounds, planeType, planeDist)) {
        int polygonCount = 0;
        int polytopeCount = 0;
        GetPrimitiveCounts(node, polygonCount, polytopeCount);
        if (polygonCount > 255) {
            idLibPrint::Warning("node has %d polygons", polygonCount);
        }
        if (polytopeCount > 255) {
            idLibPrint::Warning("node has %d polytopes", polytopeCount);
        }
        node->planeType = -1;
        return node;
    }

    cm_buildNode_t* const front = AllocNode(model, 256);
    cm_buildNode_t* const back = AllocNode(model, 256);
    if (front == nullptr || back == nullptr) {
        node->planeType = -1;
        return node;
    }
    front->parent = node;
    back->parent = node;
    front->bounds = node->bounds;
    back->bounds = node->bounds;
    front->bounds[0][planeType] = planeDist;
    back->bounds[1][planeType] = planeDist;
    node->planeType = planeType;
    node->planeDist = planeDist;
    node->children[0] = front;
    node->children[1] = back;

    cm_buildPolygonRef_t* polygonReference = node->polygons;
    node->polygons = nullptr;
    while (polygonReference != nullptr) {
        cm_buildPolygonRef_t* const next = polygonReference->next;
        polygonReference->next = nullptr;
        FilterPolygonIntoTree_r(model, node, polygonReference,
            &model->polygons[polygonReference->polygonNum]);
        polygonReference = next;
    }
    cm_buildPolytopeRef_t* polytopeReference = node->polytopes;
    node->polytopes = nullptr;
    while (polytopeReference != nullptr) {
        cm_buildPolytopeRef_t* const next = polytopeReference->next;
        polytopeReference->next = nullptr;
        FilterPolytopeIntoTree_r(model, node, polytopeReference,
            &model->polytopes[polytopeReference->polytopeNum]);
        polytopeReference = next;
    }
    CreateAxialBSPTree_r(model, front);
    CreateAxialBSPTree_r(model, back);
    return node;
}

cm_buildNode_t* idCollisionModelBuilder::CreateAxialBSPTree(
    cm_buildModel_t* const model) {
    if (model == nullptr) {
        return nullptr;
    }
    while (model->polygonRefBlocks != nullptr) {
        cm_buildPolygonRefBlock_t* const block = model->polygonRefBlocks;
        model->polygonRefBlocks = block->next;
        mem.Free(block, ALIGN_16);
    }
    while (model->polytopeRefBlocks != nullptr) {
        cm_buildPolytopeRefBlock_t* const block = model->polytopeRefBlocks;
        model->polytopeRefBlocks = block->next;
        mem.Free(block, ALIGN_16);
    }
    while (model->nodeBlocks != nullptr) {
        cm_buildNodeBlock_t* const block = model->nodeBlocks;
        model->nodeBlocks = block->next;
        mem.Free(block, ALIGN_16);
    }
    model->numNodes = 0;
    model->numPolygonRefs = 0;
    model->numPolytopeRefs = 0;
    model->node = AllocNode(model, 256);
    if (model->node == nullptr) {
        return nullptr;
    }
    model->node->bounds[0].Set(1.0e30f, 1.0e30f, 1.0e30f);
    model->node->bounds[1].Set(-1.0e30f, -1.0e30f, -1.0e30f);
    for (int index = 0; index < model->numPolygons; ++index) {
        if (model->polygons[index].numEdges != 0) {
            AddBounds(model->node->bounds, model->polygons[index].bounds);
            FilterPolygonIntoTree_r(model, model->node, nullptr,
                &model->polygons[index]);
        }
    }
    for (int index = 0; index < model->numPolytopes; ++index) {
        if (model->polytopes[index].numPlanes != 0) {
            AddBounds(model->node->bounds, model->polytopes[index].bounds);
            FilterPolytopeIntoTree_r(model, model->node, nullptr,
                &model->polytopes[index]);
        }
    }
    if (model->node->bounds[0].x > model->node->bounds[1].x) {
        model->node->bounds[0].Zero();
        model->node->bounds[1].Zero();
    }
    model->node = CreateAxialBSPTree_r(model, model->node);
    int savedPolygons = 0;
    int savedPolytopes = 0;
    CM_R_TestOptimisation(model->node, savedPolygons, savedPolytopes);
    return model->node;
}

void idCollisionModelBuilder::CreatePolygon(cm_buildModel_t* const model,
    idFixedWinding* const winding, const idPlane& plane,
    const idMaterial* const material, const int primitiveNum) {
    if (model == nullptr || winding == nullptr
        || winding->GetNumPoints() < 3) {
        return;
    }
    std::vector<int> edgeNumbers;
    edgeNumbers.reserve(static_cast<std::size_t>(winding->GetNumPoints()));
    int previousVertex = -1;
    for (int pointIndex = 0; pointIndex < winding->GetNumPoints();
         ++pointIndex) {
        const int nextIndex = (pointIndex + 1) % winding->GetNumPoints();
        int edgeNumber = 0;
        GetEdge(model,
            idVec3((*winding)[pointIndex].x, (*winding)[pointIndex].y,
                (*winding)[pointIndex].z),
            idVec3((*winding)[nextIndex].x, (*winding)[nextIndex].y,
                (*winding)[nextIndex].z), edgeNumber, previousVertex);
        if (edgeNumber == 0) {
            continue;
        }
        bool duplicate = false;
        for (const int existing : edgeNumbers) {
            duplicate |= std::abs(existing) == std::abs(edgeNumber);
        }
        if (duplicate) {
            return;
        }
        edgeNumbers.push_back(edgeNumber);
        const cm_buildEdge_t& edge = model->edges[std::abs(edgeNumber)];
        previousVertex = edge.vertexNum[edgeNumber >= 0 ? 1 : 0];
    }
    if (edgeNumbers.size() < 3) {
        return;
    }
    cm_buildPolygon_t* const polygon = AllocPolygon(model,
        static_cast<int>(edgeNumbers.size()));
    if (polygon == nullptr) {
        return;
    }
    winding->GetBounds(polygon->bounds);
    cm_materialBuildInfo_t materialInfo{};
    CM_GetMaterialBuildInfo(material, materialInfo);
    polygon->contents = materialInfo.contents;
    polygon->material = FindMaterial(model, materialInfo.contents,
        materialInfo.surfaceFlags, materialInfo.surfaceType);
    polygon->plane = plane;
    polygon->primitiveNum = std::abs(primitiveNum);
    polygon->checkCount = 0;
    for (int index = 0; index < polygon->numEdges; ++index) {
        model->polygonEdges[polygon->firstEdge + index] =
            edgeNumbers[static_cast<std::size_t>(index)];
    }
    if (model->node == nullptr) {
        model->node = AllocNode(model, 8);
        model->node->bounds = polygon->bounds;
    }
    FilterPolygonIntoTree_r(model, model->node, nullptr, polygon);
}

void idCollisionModelBuilder::PolygonFromWinding(
    cm_buildModel_t* const model, idFixedWinding* const winding,
    const idPlane& plane, const idMaterial* const material,
    const int primitiveNum) {
    if (model == nullptr || winding == nullptr) {
        return;
    }
    if (winding->IsHuge(131072.0f)) {
        idLibPrint::Warning(
            "PolygonFromWinding: model %s primitive %d is degenerate",
            model->name.c_str(), std::abs(primitiveNum));
        return;
    }
    CreatePolygon(model, winding, plane, material, primitiveNum);
}

void idCollisionModelBuilder::AddBuildNodePrimitivesToSubModelNode(
    const cm_buildModel_t* const buildModel, cm_buildNode_t* const buildNode,
    cm_subModelPtrs_t& subModelPtrs, cm_subModelData_t& counts,
    cm_node_t& node) {
    if (buildModel == nullptr || buildNode == nullptr) {
        return;
    }
    cm_buildModel_t* const writable = const_cast<cm_buildModel_t*>(
        buildModel);
    const auto packMaterial = [&](cm_buildMaterial_t& source) {
        if (source.checkCount == writable->checkCount) {
            return;
        }
        source.checkCount = writable->checkCount;
        source.index = counts.numMaterials;
        cm_material_t& destination =
            subModelPtrs.materials[counts.numMaterials++];
        destination.contentFlags = source.contentFlags;
        destination.surfaceFlags = source.surfaceFlags;
        destination.surfaceType = source.surfaceType;
        destination.surfaceColor[0] = 0xFF;
        destination.surfaceColor[1] = 0xFF;
        destination.surfaceColor[2] = 0xFF;
        destination.pad = 0;
    };

    for (cm_buildPolygonRef_t* reference = buildNode->polygons;
         reference != nullptr; reference = reference->next) {
        cm_buildPolygon_t& source =
            writable->polygons[reference->polygonNum];
        if (source.checkCount != writable->checkCount) {
            source.checkCount = writable->checkCount;
            cm_buildMaterial_t& sourceMaterial =
                writable->materials[source.material];
            packMaterial(sourceMaterial);
            source.index = counts.numPolygons;
            cm_polygon_t& destination =
                subModelPtrs.polygons[counts.numPolygons++];
            destination.bounds.SetBounds(source.bounds);
            destination.material = static_cast<std::uint8_t>(
                sourceMaterial.index);
            destination.firstEdge = static_cast<std::uint16_t>(
                counts.numPolygonEdges);
            destination.numEdges = static_cast<std::uint8_t>(
                source.numEdges);
            for (int polygonEdge = 0; polygonEdge < source.numEdges;
                 ++polygonEdge) {
                const int sourceReference = writable->polygonEdges[
                    source.firstEdge + polygonEdge];
                cm_buildEdge_t& sourceEdge =
                    writable->edges[std::abs(sourceReference)];
                if (sourceEdge.checkCount != writable->checkCount) {
                    sourceEdge.checkCount = writable->checkCount;
                    for (int endpoint = 0; endpoint < 2; ++endpoint) {
                        cm_buildVertex_t& sourceVertex =
                            writable->vertices[
                                sourceEdge.vertexNum[endpoint]];
                        if (sourceVertex.checkCount
                            != writable->checkCount) {
                            sourceVertex.checkCount = writable->checkCount;
                            sourceVertex.index = counts.numVertices;
                            cm_vertex_t& destinationVertex =
                                subModelPtrs.vertices[
                                    counts.numVertices++];
                            destinationVertex.p = sourceVertex.p;
                            destinationVertex.st[0] = sourceVertex.st[0];
                            destinationVertex.st[1] = sourceVertex.st[1];
                        }
                    }
                    sourceEdge.index = counts.numEdges;
                    cm_edge_t& destinationEdge =
                        subModelPtrs.edges[counts.numEdges++];
                    destinationEdge.vertexNum[0] =
                        static_cast<std::uint16_t>(writable->vertices[
                            sourceEdge.vertexNum[0]].index);
                    destinationEdge.vertexNum[1] =
                        static_cast<std::uint16_t>(writable->vertices[
                            sourceEdge.vertexNum[1]].index);
                }
                std::uint16_t packedReference =
                    static_cast<std::uint16_t>(sourceEdge.index);
                if (sourceReference <= 0) {
                    packedReference |= 0x8000u;
                }
                if (sourceEdge.internal != 0) {
                    packedReference |= 0x4000u;
                }
                subModelPtrs.polygonEdges[counts.numPolygonEdges++] =
                    packedReference;
            }
        }
        for (int index = node.numPolytopes; index > 0; --index) {
            subModelPtrs.primitiveIndices[node.firstPrimitive
                + node.numPolygons + index] =
                subModelPtrs.primitiveIndices[node.firstPrimitive
                    + node.numPolygons + index - 1];
        }
        subModelPtrs.primitiveIndices[node.firstPrimitive
            + node.numPolygons++] = static_cast<std::uint16_t>(source.index);
        ++counts.numPrimitiveIndices;
    }

    for (cm_buildPolytopeRef_t* reference = buildNode->polytopes;
         reference != nullptr; reference = reference->next) {
        cm_buildPolytope_t& source =
            writable->polytopes[reference->polytopeNum];
        if (source.checkCount != writable->checkCount) {
            source.checkCount = writable->checkCount;
            cm_buildMaterial_t& sourceMaterial =
                writable->materials[source.material];
            packMaterial(sourceMaterial);
            source.index = counts.numPolytopes;
            cm_polytope_t& destination =
                subModelPtrs.polytopes[counts.numPolytopes++];
            destination.bounds.SetBounds(source.bounds);
            destination.material = static_cast<std::uint8_t>(
                sourceMaterial.index);
            destination.firstPlane = static_cast<std::uint16_t>(
                counts.numPolytopePlanes);
            destination.numPlanes = static_cast<std::uint8_t>(
                source.numPlanes);
            for (int plane = 0; plane < source.numPlanes; ++plane) {
                subModelPtrs.polytopePlanes[
                    counts.numPolytopePlanes++] =
                    writable->polytopePlanes[source.firstPlane + plane];
            }
        }
        subModelPtrs.primitiveIndices[node.firstPrimitive
            + node.numPolygons + node.numPolytopes++] =
            static_cast<std::uint16_t>(source.index);
        ++counts.numPrimitiveIndices;
    }
}

void idCollisionModelBuilder::CreateSingleSubModel_r(
    const cm_buildModel_t* const buildModel, cm_buildNode_t* buildNode,
    cm_subModelPtrs_t& subModelPtrs, cm_subModelData_t& counts,
    cm_node_t* parent) {
    while (buildNode != nullptr) {
        const int nodeIndex = counts.numNodes++;
        cm_node_t& node = subModelPtrs.nodes[nodeIndex];
        node.planeType = buildNode->planeType;
        node.planeDist = buildNode->planeDist;
        node.children[0] = node.children[1] = 0;
        node.firstPrimitive = static_cast<std::uint16_t>(
            counts.numPrimitiveIndices);
        node.numPolygons = 0;
        node.numPolytopes = 0;
        if (parent != nullptr && buildNode->parent != nullptr) {
            const int side = buildNode == buildNode->parent->children[1]
                ? 1 : 0;
            parent->children[side] = static_cast<std::uint16_t>(nodeIndex);
        } else {
            for (cm_buildNode_t* ancestor = buildNode->parent;
                 ancestor != nullptr; ancestor = ancestor->parent) {
                AddBuildNodePrimitivesToSubModelNode(buildModel, ancestor,
                    subModelPtrs, counts, node);
            }
        }
        AddBuildNodePrimitivesToSubModelNode(buildModel, buildNode,
            subModelPtrs, counts, node);
        if (buildNode->planeType == -1) {
            return;
        }
        parent = &node;
        CreateSingleSubModel_r(buildModel, buildNode->children[0],
            subModelPtrs, counts, parent);
        buildNode = buildNode->children[1];
    }
}

void idCollisionModelBuilder::CreateNodeStats_r(
    const cm_buildModel_t* const buildModel, cm_buildNode_t* buildNode) {
    if (buildModel == nullptr) {
        return;
    }
    cm_buildModel_t* const writable = const_cast<cm_buildModel_t*>(
        buildModel);
    while (buildNode != nullptr) {
        ++writable->checkCount;
        std::memset(&buildNode->stats, 0, sizeof(buildNode->stats));
        for (cm_buildNode_t* ancestor = buildNode->parent;
             ancestor != nullptr; ancestor = ancestor->parent) {
            GetStatsFromNode(buildModel, ancestor, buildNode->stats);
        }
        CreateStatsForSubTree_r(buildModel, buildNode, buildNode->stats);
        if (buildNode->stats.lastNumPolygonEdges > 0) {
            buildNode->stats.numPolygonEdges =
                buildNode->stats.numPolygonEdges
                - (buildNode->stats.lastNumPolygonEdges & 3) + 4;
        }
        CalculateSubModelDataSize(buildNode->stats);
        if (buildNode->planeType == -1) {
            return;
        }
        CreateNodeStats_r(buildModel, buildNode->children[0]);
        buildNode = buildNode->children[1];
    }
}

void idCollisionModelBuilder::CreateSubModels_r(
    const cm_buildModel_t* const buildModel, cm_buildNode_t* buildNode,
    idCollisionModelLocal* const model, cm_modelTreeNode_t* parent) {
    if (buildModel == nullptr || model == nullptr) {
        return;
    }
    while (buildNode != nullptr) {
        if (buildNode->stats.canCreateSubModel) {
            const int subModelIndex = model->polygonModel.numSubModels;
            cm_subModel_t& subModel =
                model->polygonModel.subModels[subModelIndex];
            cm_subModelPtrs_t pointers{};
            if (!AllocSubModelData(buildNode->stats, buildNode->bounds,
                    subModel, pointers)) {
                return;
            }
            subModel.fileOffset = -1;
            subModel.numUsers = 0;
            subModel.state = &model->polygonModel.subModelState[
                subModelIndex];
            *subModel.state = SUBMODEL_STATE_LOADED;
            cm_subModelData_t counts{};
            ++const_cast<cm_buildModel_t*>(buildModel)->checkCount;
            CreateSingleSubModel_r(buildModel, buildNode, pointers, counts,
                nullptr);
            if (counts.numPolygons > 0) {
                const int padding = 4 - (pointers.polygons[
                    counts.numPolygons - 1].numEdges & 3);
                for (int index = 0; index < padding; ++index) {
                    pointers.polygonEdges[counts.numPolygonEdges] =
                        pointers.polygonEdges[counts.numPolygonEdges - 1];
                    ++counts.numPolygonEdges;
                }
            }
            subModel.data->header = subModel.header;
            subModel.data->header.loadedSize =
                subModel.data->header.totalSize;
            ++model->polygonModel.numSubModels;
            if (parent != nullptr && buildNode->parent != nullptr) {
                const int side =
                    buildNode == buildNode->parent->children[1] ? 1 : 0;
                parent->children[side] =
                    -model->polygonModel.numSubModels;
            }
            return;
        }

        const int treeNodeIndex = model->polygonModel.numModelTreeNodes++;
        cm_modelTreeNode_t& node =
            model->polygonModel.modelTreeNodes[treeNodeIndex];
        node.planeType = buildNode->planeType;
        node.planeDist = buildNode->planeDist;
        node.children[0] = node.children[1] = 0;
        if (parent != nullptr && buildNode->parent != nullptr) {
            const int side = buildNode == buildNode->parent->children[1]
                ? 1 : 0;
            parent->children[side] = treeNodeIndex;
        }
        if (buildNode->planeType == -1) {
            return;
        }
        parent = &node;
        CreateSubModels_r(buildModel, buildNode->children[0], model,
            parent);
        buildNode = buildNode->children[1];
    }
}

void idCollisionModelBuilder::AddSubModelsToCollisionModel(
    idCollisionModelLocal* const model,
    const cm_buildModel_t* const buildModel) {
    if (model == nullptr || buildModel == nullptr
        || buildModel->node == nullptr) {
        return;
    }
    idBounds nodeBounds;
    GetNodeBounds(buildModel, buildModel->node, nodeBounds);
    if (model->bounds[0].x > model->bounds[1].x) {
        model->bounds = nodeBounds;
    } else {
        AddBounds(model->bounds, nodeBounds);
    }
    model->contents |= GetNodeContents(buildModel, buildModel->node);
    CreateNodeStats_r(buildModel, buildModel->node);
    int addTreeNodes = 0;
    int addSubModels = 0;
    FindSubModels_r(buildModel, buildModel->node, addTreeNodes,
        addSubModels);
    const int oldTreeNodes = model->polygonModel.numModelTreeNodes;
    const int oldSubModels = model->polygonModel.numSubModels;
    const int totalTreeNodes = oldTreeNodes + addTreeNodes;
    const int totalSubModels = oldSubModels + addSubModels;
    if (totalTreeNodes > 0x8000 || totalSubModels > 0x4000) {
        idLibPrint::Warning("collision model tree exceeds recovered limits");
        return;
    }

    cm_modelTreeNode_t* newTree = nullptr;
    if (totalTreeNodes > 0) {
        newTree = static_cast<cm_modelTreeNode_t*>(_aligned_malloc(
            sizeof(cm_modelTreeNode_t)
                * static_cast<std::size_t>(totalTreeNodes), 16));
        if (newTree == nullptr) {
            return;
        }
        if (oldTreeNodes > 0) {
            std::memcpy(newTree, model->polygonModel.modelTreeNodes,
                sizeof(cm_modelTreeNode_t)
                    * static_cast<std::size_t>(oldTreeNodes));
        }
    }
    cm_subModel_t* const newSubModels =
        static_cast<cm_subModel_t*>(_aligned_malloc(
            sizeof(cm_subModel_t)
                * static_cast<std::size_t>(totalSubModels), 16));
    volatile std::uint8_t* const newStates =
        static_cast<volatile std::uint8_t*>(_aligned_malloc(
            static_cast<std::size_t>(totalSubModels), 16));
    if (newSubModels == nullptr || newStates == nullptr) {
        _aligned_free(newTree);
        _aligned_free(newSubModels);
        _aligned_free(const_cast<std::uint8_t*>(newStates));
        return;
    }
    std::memset(newSubModels, 0,
        sizeof(cm_subModel_t) * static_cast<std::size_t>(totalSubModels));
    if (oldSubModels > 0) {
        std::memcpy(newSubModels, model->polygonModel.subModels,
            sizeof(cm_subModel_t) * static_cast<std::size_t>(oldSubModels));
    }
    for (int index = 0; index < totalSubModels; ++index) {
        newStates[index] = SUBMODEL_STATE_LOADED;
        newSubModels[index].state = &newStates[index];
    }
    _aligned_free(model->polygonModel.modelTreeNodes);
    _aligned_free(model->polygonModel.subModels);
    _aligned_free(const_cast<std::uint8_t*>(
        model->polygonModel.subModelState));
    model->polygonModel.modelTreeNodes = newTree;
    model->polygonModel.subModels = newSubModels;
    model->polygonModel.subModelState = newStates;
    model->polygonModel.numModelTreeNodes = oldTreeNodes;
    model->polygonModel.numSubModels = oldSubModels;
    CreateSubModels_r(buildModel, buildModel->node, model, nullptr);
}

int idCollisionModelBuilder::CountModelTreeNodes_r(
    idCollisionModelLocal* const model, const int nodeNum,
    idBounds& bounds) {
    if (model == nullptr) {
        return 0;
    }
    if (nodeNum < 0) {
        const int subModelIndex = -nodeNum - 1;
        if (subModelIndex >= 0
            && subModelIndex < model->polygonModel.numSubModels) {
            AddBounds(bounds, model->polygonModel.subModels[
                subModelIndex].header.bounds);
        }
        return 0;
    }
    if (nodeNum >= model->polygonModel.numModelTreeNodes) {
        return 0;
    }
    const cm_modelTreeNode_t& node =
        model->polygonModel.modelTreeNodes[nodeNum];
    if (node.planeType == -1) {
        return 1;
    }
    return CountModelTreeNodes_r(model, node.children[1], bounds)
        + CountModelTreeNodes_r(model, node.children[0], bounds) + 1;
}

void idCollisionModelBuilder::MergeModelTrees(
    idCollisionModelLocal* const model) {
    if (model == nullptr || model->polygonModel.numModelTreeNodes <= 0
        || model->polygonModel.modelTreeNodes == nullptr) {
        return;
    }
    // The recovered retail function inventories each independently appended
    // root and its bounds; it does not rewrite the serialized node array.
    // Keeping the roots sequential is significant because stream-area
    // submodels refer to the original negative child indices.
    int root = 0;
    while (root < model->polygonModel.numModelTreeNodes) {
        idBounds bounds;
        bounds[0].Set(1.0e30f, 1.0e30f, 1.0e30f);
        bounds[1].Set(-1.0e30f, -1.0e30f, -1.0e30f);
        const int descendants = CountModelTreeNodes_r(model, root, bounds);
        const int nextRoot = root + descendants + 1;
        if (nextRoot <= root) {
            break;
        }
        root = nextRoot;
    }
}

void idCollisionModelBuilder::GenerateEdgeNormals_r(
    cm_buildModel_t* const model, cm_buildNode_t* node) {
    if (model == nullptr) {
        return;
    }
    while (node != nullptr) {
        for (cm_buildPolygonRef_t* reference = node->polygons;
             reference != nullptr; reference = reference->next) {
            cm_buildPolygon_t& polygon =
                model->polygons[reference->polygonNum];
            if (polygon.checkCount == model->checkCount) {
                continue;
            }
            polygon.checkCount = model->checkCount;
            const idVec3 planeNormal(polygon.plane.a, polygon.plane.b,
                polygon.plane.c);
            for (int polygonEdge = 0; polygonEdge < polygon.numEdges;
                 ++polygonEdge) {
                const int edgeReference = model->polygonEdges[
                    polygon.firstEdge + polygonEdge];
                cm_buildEdge_t& edge =
                    model->edges[std::abs(edgeReference)];
                if (edge.normal.LengthSqr() != 0.0f) {
                    if (edge.normal.Dot(planeNormal) >= -0.7f) {
                        edge.normal = edge.normal + planeNormal;
                        edge.normal.NormalizeFast();
                    } else {
                        const int startIndex = edgeReference < 0
                            ? edge.vertexNum[1] : edge.vertexNum[0];
                        const int endIndex = edgeReference < 0
                            ? edge.vertexNum[0] : edge.vertexNum[1];
                        idVec3 direction = model->vertices[endIndex].p
                            - model->vertices[startIndex].p;
                        direction.NormalizeFast();
                        idVec3 sharp = direction.Cross(edge.normal)
                            + planeNormal.Cross(direction);
                        sharp.NormalizeFast();
                        edge.normal = sharp * 3.3333333f;
                        ++model->numSharpEdges;
                    }
                } else if (edge.numUsers == 1) {
                    const int startIndex = edgeReference < 0
                        ? edge.vertexNum[1] : edge.vertexNum[0];
                    const int endIndex = edgeReference < 0
                        ? edge.vertexNum[0] : edge.vertexNum[1];
                    idVec3 direction = model->vertices[endIndex].p
                        - model->vertices[startIndex].p;
                    direction.NormalizeFast();
                    edge.normal = direction.Cross(planeNormal);
                    edge.normal.NormalizeFast();
                    edge.normal = edge.normal + planeNormal;
                    edge.normal.NormalizeFast();
                } else {
                    edge.normal = planeNormal;
                }
            }
        }
        if (node->planeType == -1) {
            return;
        }
        GenerateEdgeNormals_r(model, node->children[1]);
        node = node->children[0];
    }
}

bool idCollisionModelBuilder::ChoppedAwayByProcBSP_r(
    int nodeNum, idFixedWinding* const winding, const idVec3& normal,
    const idVec3& origin, const float radius) {
    if (winding == nullptr || buildData.procNodes == nullptr
        || buildData.numProcNodes <= 0) {
        return false;
    }
    std::function<bool(int, idFixedWinding*, bool)> walk;
    walk = [&](int currentNode, idFixedWinding* fragment,
               bool rootNode) -> bool {
        while (rootNode || currentNode > 0) {
            rootNode = false;
            if (currentNode < 0 || currentNode >= buildData.numProcNodes) {
                return false;
            }
            const cm_procNode_t& node = buildData.procNodes[currentNode];
            const float distance = node.plane.Distance(origin);
            if (distance > radius) {
                currentNode = node.children[0];
                continue;
            }
            if (distance < -radius) {
                currentNode = node.children[1];
                continue;
            }
            idFixedWinding back;
            const int side = fragment->SplitInPlace(node.plane, 0.1f,
                &back);
            if (side == 0) {
                currentNode = node.children[0];
            } else if (side == 1) {
                currentNode = node.children[1];
            } else if (side == 2) {
                currentNode = node.plane.Normal().Dot(normal) > 0.0f
                    ? node.children[0] : node.children[1];
            } else {
                if (!walk(node.children[1], &back, false)) {
                    return false;
                }
                currentNode = node.children[0];
            }
        }
        return currentNode == 0;
    };
    return walk(nodeNum, winding, nodeNum == 0);
}

bool idCollisionModelBuilder::ChoppedAwayByProcBSP(
    const idFixedWinding& winding, const idPlane& plane,
    const int contents) {
    if (buildData.procNodes == nullptr || buildData.numProcNodes == 0
        || (contents & 1) == 0) {
        return false;
    }
    idFixedWinding clipped;
    clipped = winding;
    idBounds bounds;
    clipped.GetBounds(bounds);
    const idVec3 origin = (bounds[0] + bounds[1]) * 0.5f;
    const float radius = (bounds[1] - origin).Length() + 0.1f;
    return ChoppedAwayByProcBSP_r(0, &clipped, plane.Normal(), origin,
        radius);
}

void idCollisionModelBuilder::ReplacePolygons(cm_buildModel_t* const model,
    cm_buildNode_t* node, const int polygonNum1, const int polygonNum2,
    const int newPolygonNum) {
    if (model == nullptr || node == nullptr) {
        return;
    }
    while (node != nullptr) {
        bool replaced = false;
        cm_buildPolygonRef_t* previous = nullptr;
        cm_buildPolygonRef_t* reference = node->polygons;
        while (reference != nullptr) {
            cm_buildPolygonRef_t* const next = reference->next;
            if (reference->polygonNum == polygonNum1
                || reference->polygonNum == polygonNum2) {
                if (!replaced) {
                    reference->polygonNum = newPolygonNum;
                    replaced = true;
                    previous = reference;
                } else {
                    if (previous != nullptr) {
                        previous->next = next;
                    } else {
                        node->polygons = next;
                    }
                    --model->numPolygonRefs;
                }
            } else {
                previous = reference;
            }
            reference = next;
        }
        if (node->planeType == -1) {
            return;
        }
        const int axis = node->planeType;
        const idBounds& first = model->polygons[polygonNum1].bounds;
        const idBounds& second = model->polygons[polygonNum2].bounds;
        if (first[0][axis] <= node->planeDist
            || second[0][axis] <= node->planeDist) {
            if (first[1][axis] >= node->planeDist
                || second[1][axis] >= node->planeDist) {
                ReplacePolygons(model, node->children[1], polygonNum1,
                    polygonNum2, newPolygonNum);
                node = node->children[0];
            } else {
                node = node->children[1];
            }
        } else {
            node = node->children[0];
        }
    }
}

void idCollisionModelBuilder::FindInternalEdgesOnPolygon(
    cm_buildModel_t* const model, cm_buildPolygon_t* const polygon1,
    cm_buildPolygon_t* const polygon2) {
    if (model == nullptr || polygon1 == nullptr || polygon2 == nullptr) {
        return;
    }
    for (int axis = 0; axis < 3; ++axis) {
        if (polygon1->bounds[0][axis] > polygon2->bounds[1][axis]
            || polygon1->bounds[1][axis] < polygon2->bounds[0][axis]) {
            return;
        }
    }
    const idVec3 firstNormal(polygon1->plane.a, polygon1->plane.b,
        polygon1->plane.c);
    const idVec3 secondNormal(polygon2->plane.a, polygon2->plane.b,
        polygon2->plane.c);
    for (int polygonEdge = 0; polygonEdge < polygon1->numEdges;
         ++polygonEdge) {
        const int edgeReference = model->polygonEdges[
            polygon1->firstEdge + polygonEdge];
        cm_buildEdge_t& edge = model->edges[std::abs(edgeReference)];
        if (edge.internal != 0) {
            continue;
        }
        const int startIndex = edgeReference < 0
            ? edge.vertexNum[1] : edge.vertexNum[0];
        const int endIndex = edgeReference < 0
            ? edge.vertexNum[0] : edge.vertexNum[1];
        const idVec3& start = model->vertices[startIndex].p;
        const idVec3& end = model->vertices[endIndex].p;
        bool insideBounds = true;
        for (int axis = 0; axis < 3; ++axis) {
            insideBounds &= start[axis] <= polygon2->bounds[1][axis] + 0.1f
                && end[axis] <= polygon2->bounds[1][axis] + 0.1f
                && start[axis] >= polygon2->bounds[0][axis] - 0.1f
                && end[axis] >= polygon2->bounds[0][axis] - 0.1f;
        }
        if (!insideBounds) {
            continue;
        }
        int matchingEdge = -1;
        for (int otherEdge = 0; otherEdge < polygon2->numEdges;
             ++otherEdge) {
            if (std::abs(model->polygonEdges[polygon2->firstEdge
                    + otherEdge]) == std::abs(edgeReference)) {
                matchingEdge = otherEdge;
                break;
            }
        }
        if (matchingEdge < 0
            && (std::fabs(polygon2->plane.Distance(start)) > 0.1f
                || std::fabs(polygon2->plane.Distance(end)) > 0.1f)) {
            continue;
        }
        if (matchingEdge >= 0
            && (edge.numUsers > 2
                || edgeReference == model->polygonEdges[
                    polygon2->firstEdge + matchingEdge])) {
            continue;
        }
        if (secondNormal.Dot(firstNormal.Cross(end - start)) < 0.0f) {
            return;
        }
        if (matchingEdge >= 0
            || (PointInsidePolygon(model, polygon2, start)
                && PointInsidePolygon(model, polygon2, end))) {
            edge.internal = 1;
            ++model->numInternalEdges;
        }
    }
}

void idCollisionModelBuilder::FindInternalPolygonEdges(
    cm_buildModel_t* const model, cm_buildNode_t* node,
    cm_buildPolygon_t* const polygon) {
    if (model == nullptr || polygon == nullptr) {
        return;
    }
    while (node != nullptr) {
        for (cm_buildPolygonRef_t* reference = node->polygons;
             reference != nullptr; reference = reference->next) {
            cm_buildPolygon_t& candidate =
                model->polygons[reference->polygonNum];
            if (&candidate != polygon
                && candidate.material == polygon->material
                && candidate.contents == polygon->contents) {
                FindInternalEdgesOnPolygon(model, polygon, &candidate);
            }
        }
        if (node->planeType == -1) {
            return;
        }
        const int axis = node->planeType;
        if (polygon->bounds[0][axis] <= node->planeDist) {
            if (polygon->bounds[1][axis] >= node->planeDist) {
                FindInternalPolygonEdges(model, node->children[1], polygon);
                node = node->children[0];
            } else {
                node = node->children[1];
            }
        } else {
            node = node->children[0];
        }
    }
}

void idCollisionModelBuilder::FindInternalEdges(cm_buildModel_t* const model,
    cm_buildNode_t* node) {
    if (model == nullptr) {
        return;
    }
    while (node != nullptr) {
        for (cm_buildPolygonRef_t* reference = node->polygons;
             reference != nullptr; reference = reference->next) {
            cm_buildPolygon_t& polygon =
                model->polygons[reference->polygonNum];
            if (polygon.checkCount != model->checkCount) {
                polygon.checkCount = model->checkCount;
                FindInternalPolygonEdges(model, model->node, &polygon);
            }
        }
        if (node->planeType == -1) {
            return;
        }
        FindInternalEdges(model, node->children[1]);
        node = node->children[0];
    }
}

void idCollisionModelBuilder::OffsetPolygonEdges(
    cm_buildModel_t* const model, cm_buildPolygon_t* const polygon) {
    if (model == nullptr || polygon == nullptr || polygon->numEdges <= 1) {
        return;
    }
    int bestStart = 0;
    float lowestAlignment = 1.0f;
    for (int edgeIndex = 0; edgeIndex < polygon->numEdges; ++edgeIndex) {
        const int previousIndex = (edgeIndex + polygon->numEdges - 1)
            % polygon->numEdges;
        const int currentReference = model->polygonEdges[
            polygon->firstEdge + edgeIndex];
        const int previousReference = model->polygonEdges[
            polygon->firstEdge + previousIndex];
        const cm_buildEdge_t& current =
            model->edges[std::abs(currentReference)];
        const cm_buildEdge_t& previous =
            model->edges[std::abs(previousReference)];
        const int cornerIndex = currentReference < 0
            ? current.vertexNum[1] : current.vertexNum[0];
        const int currentEnd = currentReference < 0
            ? current.vertexNum[0] : current.vertexNum[1];
        const int previousStart = previousReference < 0
            ? previous.vertexNum[1] : previous.vertexNum[0];
        idVec3 outgoing = model->vertices[currentEnd].p
            - model->vertices[cornerIndex].p;
        idVec3 incoming = model->vertices[previousStart].p
            - model->vertices[cornerIndex].p;
        outgoing.NormalizeFast();
        incoming.NormalizeFast();
        const float alignment = std::fabs(outgoing.Dot(incoming));
        if (alignment < lowestAlignment) {
            lowestAlignment = alignment;
            bestStart = edgeIndex;
        }
    }
    std::vector<int> rotated(static_cast<std::size_t>(polygon->numEdges));
    for (int index = 0; index < polygon->numEdges; ++index) {
        rotated[static_cast<std::size_t>(index)] = model->polygonEdges[
            polygon->firstEdge
                + (bestStart + index) % polygon->numEdges];
    }
    std::copy(rotated.begin(), rotated.end(),
        model->polygonEdges + polygon->firstEdge);
}

void idCollisionModelBuilder::OffsetPolygonEdges_r(
    cm_buildModel_t* const model, cm_buildNode_t* node) {
    if (model == nullptr) {
        return;
    }
    while (node != nullptr) {
        for (cm_buildPolygonRef_t* reference = node->polygons;
             reference != nullptr; reference = reference->next) {
            cm_buildPolygon_t& polygon =
                model->polygons[reference->polygonNum];
            if (polygon.checkCount != model->checkCount) {
                polygon.checkCount = model->checkCount;
                OffsetPolygonEdges(model, &polygon);
            }
        }
        if (node->planeType == -1) {
            return;
        }
        OffsetPolygonEdges_r(model, node->children[1]);
        node = node->children[0];
    }
}

void idCollisionModelBuilder::ChopWindingListWithPolytope(
    cm_windingList_t* const list, const cm_buildModel_t* const model,
    const cm_buildPolytope_t* const polytope) {
    if (list == nullptr || model == nullptr || polytope == nullptr
        || list->numWindings <= 0 || polytope->numPlanes <= 0
        || polytope->numPlanes > 64) {
        return;
    }

    // A polytope plane points out of the solid.  Partition every source
    // winding by the inward-facing planes: front fragments are outside and
    // survive, while the final back fragment lies inside all planes and is
    // removed.  This is the scalar PC spelling of the recovered list ping-
    // pong implementation.
    std::vector<idFixedWinding> surviving;
    surviving.reserve(static_cast<std::size_t>(list->numWindings));
    for (int sourceIndex = 0; sourceIndex < list->numWindings;
         ++sourceIndex) {
        std::vector<idFixedWinding> candidates;
        candidates.push_back(list->w[sourceIndex]);
        std::vector<idFixedWinding> outside;
        for (int planeIndex = 0; planeIndex < polytope->numPlanes
             && !candidates.empty(); ++planeIndex) {
            const idPlane& outward = model->polytopePlanes[
                polytope->firstPlane + planeIndex];
            idPlane inward(-outward.a, -outward.b, -outward.c,
                -outward.d);
            std::vector<idFixedWinding> nextCandidates;
            for (idFixedWinding& candidate : candidates) {
                idFixedWinding back;
                const int side = candidate.SplitInPlace(inward, 0.1f,
                    &back);
                if (side == 0) {
                    nextCandidates.push_back(candidate);
                } else if (side == 1) {
                    outside.push_back(candidate);
                } else if (side == 2) {
                    // Coplanar primitive faces are only discarded when they
                    // face into the clipping solid.  This preserves the
                    // recovered world/non-world coplanar convention.
                    const idVec3 planeNormal(outward.a, outward.b,
                        outward.c);
                    if (list->primitiveNum >= 0
                        && planeNormal.Dot(list->normal) > 0.0f) {
                        outside.push_back(candidate);
                    } else {
                        nextCandidates.push_back(candidate);
                    }
                } else {
                    nextCandidates.push_back(candidate);
                    outside.push_back(back);
                }
                if (outside.size() + nextCandidates.size() >= 256u) {
                    break;
                }
            }
            candidates.swap(nextCandidates);
        }
        // Anything left in candidates is inside every plane and is chopped.
        for (const idFixedWinding& fragment : outside) {
            if (surviving.size() >= 256u) {
                break;
            }
            surviving.push_back(fragment);
        }
    }
    list->numWindings = static_cast<int>((std::min)(surviving.size(),
        static_cast<std::size_t>(256)));
    for (int index = 0; index < list->numWindings; ++index) {
        list->w[index] = surviving[static_cast<std::size_t>(index)];
    }
}

void idCollisionModelBuilder::ChopWindingListWithTreePolytopes_r(
    cm_windingList_t* const list, const cm_buildModel_t* const model,
    const cm_buildNode_t* node) {
    if (list == nullptr || model == nullptr || node == nullptr
        || list->numWindings <= 0) {
        return;
    }
    while (node != nullptr) {
        for (cm_buildPolytopeRef_t* reference = node->polytopes;
             reference != nullptr; reference = reference->next) {
            cm_buildPolytope_t& polytope = const_cast<cm_buildPolytope_t&>(
                model->polytopes[reference->polytopeNum]);
            if (polytope.checkCount == model->checkCount) {
                continue;
            }
            polytope.checkCount = model->checkCount;
            if (polytope.primitiveNum != list->primitiveNum
                && polytope.contents == list->contents
                && BoundsOverlap(polytope.bounds, list->bounds)) {
                ChopWindingListWithPolytope(list, model, &polytope);
                if (list->numWindings == 0) {
                    return;
                }
            }
        }
        if (node->planeType == -1) {
            return;
        }
        const int axis = node->planeType;
        if (list->bounds[0][axis] <= node->planeDist) {
            if (list->bounds[1][axis] >= node->planeDist) {
                ChopWindingListWithTreePolytopes_r(list, model,
                    node->children[1]);
                if (list->numWindings == 0) {
                    return;
                }
                node = node->children[0];
            } else {
                node = node->children[1];
            }
        } else {
            node = node->children[0];
        }
    }
}

cm_buildPolygon_t* idCollisionModelBuilder::TryMergePolygons(
    cm_buildModel_t* const model, const int polygonNum1,
    const int polygonNum2) {
    if (model == nullptr || polygonNum1 < 0 || polygonNum2 < 0
        || polygonNum1 >= model->numPolygons
        || polygonNum2 >= model->numPolygons
        || polygonNum1 == polygonNum2) {
        return nullptr;
    }
    const cm_buildPolygon_t& first = model->polygons[polygonNum1];
    const cm_buildPolygon_t& second = model->polygons[polygonNum2];
    if (first.numEdges < 3 || second.numEdges < 3
        || first.material != second.material
        || first.contents != second.contents
        || std::fabs(first.plane.a - second.plane.a) > 0.0001f
        || std::fabs(first.plane.b - second.plane.b) > 0.0001f
        || std::fabs(first.plane.c - second.plane.c) > 0.0001f
        || std::fabs(first.plane.d - second.plane.d) > 0.01f
        || !BoundsOverlap(first.bounds, second.bounds)) {
        return nullptr;
    }
    for (int edgeIndex = 0; edgeIndex < second.numEdges; ++edgeIndex) {
        const int reference = model->polygonEdges[
            second.firstEdge + edgeIndex];
        const idVec3& point = model->vertices[
            DirectedEdgeStart(model, reference)].p;
        if (std::fabs(first.plane.Distance(point)) > 0.1f) {
            return nullptr;
        }
    }

    std::vector<int> boundary;
    boundary.reserve(static_cast<std::size_t>(
        first.numEdges + second.numEdges));
    int sharedEdges = 0;
    const auto appendUnshared = [&](const cm_buildPolygon_t& polygon,
        const cm_buildPolygon_t& other) {
        for (int edgeIndex = 0; edgeIndex < polygon.numEdges; ++edgeIndex) {
            const int reference = model->polygonEdges[
                polygon.firstEdge + edgeIndex];
            bool shared = false;
            for (int otherIndex = 0; otherIndex < other.numEdges;
                 ++otherIndex) {
                const int otherReference = model->polygonEdges[
                    other.firstEdge + otherIndex];
                if (reference == -otherReference) {
                    shared = true;
                    break;
                }
            }
            if (!shared) {
                boundary.push_back(reference);
            } else if (&polygon == &first) {
                ++sharedEdges;
            }
        }
    };
    appendUnshared(first, second);
    appendUnshared(second, first);
    if (sharedEdges == 0 || boundary.size() < 3u || boundary.size() > 64u) {
        return nullptr;
    }

    // Reorder the surviving directed edges into one closed boundary.  This
    // also rejects point-touching or disconnected polygon unions.
    std::vector<int> ordered;
    ordered.reserve(boundary.size());
    ordered.push_back(boundary.front());
    boundary.erase(boundary.begin());
    while (!boundary.empty()) {
        const int endVertex = DirectedEdgeEnd(model, ordered.back());
        const auto next = std::find_if(boundary.begin(), boundary.end(),
            [&](const int reference) {
                return DirectedEdgeStart(model, reference) == endVertex;
            });
        if (next == boundary.end()) {
            return nullptr;
        }
        ordered.push_back(*next);
        boundary.erase(next);
    }
    if (DirectedEdgeEnd(model, ordered.back())
        != DirectedEdgeStart(model, ordered.front())) {
        return nullptr;
    }

    const idVec3 normal(first.plane.a, first.plane.b, first.plane.c);
    for (std::size_t index = 0; index < ordered.size(); ++index) {
        const int previous = ordered[(index + ordered.size() - 1)
            % ordered.size()];
        const int current = ordered[index];
        const idVec3& corner = model->vertices[
            DirectedEdgeStart(model, current)].p;
        idVec3 incoming = corner - model->vertices[
            DirectedEdgeStart(model, previous)].p;
        idVec3 outgoing = model->vertices[
            DirectedEdgeEnd(model, current)].p - corner;
        if (incoming.NormalizeFast() == 0.0f
            || outgoing.NormalizeFast() == 0.0f
            || normal.Dot(incoming.Cross(outgoing)) < -0.005f) {
            return nullptr;
        }
    }

    cm_buildPolygon_t* const merged = AllocPolygon(model,
        static_cast<int>(ordered.size()));
    if (merged == nullptr) {
        return nullptr;
    }
    // AllocPolygon may grow the polygon array, so reacquire the source.
    const cm_buildPolygon_t& currentFirst = model->polygons[polygonNum1];
    const cm_buildPolygon_t& currentSecond = model->polygons[polygonNum2];
    CopyPolygonFields(*merged, currentFirst);
    AddBounds(merged->bounds, currentSecond.bounds);
    for (int index = 0; index < merged->numEdges; ++index) {
        const int reference = ordered[static_cast<std::size_t>(index)];
        model->polygonEdges[merged->firstEdge + index] = reference;
        ++model->edges[std::abs(reference)].numUsers;
    }
    return merged;
}

bool idCollisionModelBuilder::MergePolygonWithTreePolygons(
    cm_buildModel_t* const model, cm_buildNode_t* node,
    const int polygonNum, const bool mergePrimitives) {
    if (model == nullptr || node == nullptr || polygonNum < 0
        || polygonNum >= model->numPolygons) {
        return false;
    }
    cm_buildPolygon_t* source = &model->polygons[polygonNum];
    while (node != nullptr) {
        for (cm_buildPolygonRef_t* reference = node->polygons;
             reference != nullptr; reference = reference->next) {
            const int otherNum = reference->polygonNum;
            if (otherNum == polygonNum
                || (!mergePrimitives
                    && model->polygons[otherNum].primitiveNum
                        != source->primitiveNum)) {
                continue;
            }
            cm_buildPolygon_t* const merged = TryMergePolygons(model,
                polygonNum, otherNum);
            if (merged == nullptr) {
                continue;
            }
            source = &model->polygons[polygonNum];
            cm_buildPolygon_t* const other = &model->polygons[otherNum];
            const int mergedNum = static_cast<int>(
                merged - model->polygons);
            ReplacePolygons(model, model->node, polygonNum, otherNum,
                mergedNum);
            for (int edge = 0; edge < source->numEdges; ++edge) {
                --model->edges[std::abs(model->polygonEdges[
                    source->firstEdge + edge])].numUsers;
            }
            for (int edge = 0; edge < other->numEdges; ++edge) {
                --model->edges[std::abs(model->polygonEdges[
                    other->firstEdge + edge])].numUsers;
            }
            source->numEdges = 0;
            other->numEdges = 0;
            ++model->numMergedPolys;
            return true;
        }
        if (node->planeType == -1) {
            return false;
        }
        const int axis = node->planeType;
        if (source->bounds[0][axis] <= node->planeDist) {
            if (source->bounds[1][axis] >= node->planeDist) {
                if (MergePolygonWithTreePolygons(model, node->children[1],
                        polygonNum, mergePrimitives)) {
                    return true;
                }
                node = node->children[0];
            } else {
                node = node->children[1];
            }
        } else {
            node = node->children[0];
        }
    }
    return false;
}

void idCollisionModelBuilder::MergeTreePolygons(
    cm_buildModel_t* const model, cm_buildNode_t* node,
    const bool mergePrimitives) {
    if (model == nullptr || node == nullptr) {
        return;
    }
    while (node != nullptr) {
        bool merged;
        do {
            merged = false;
            ++model->checkCount;
            for (cm_buildPolygonRef_t* reference = node->polygons;
                 reference != nullptr; reference = reference->next) {
                cm_buildPolygon_t& polygon =
                    model->polygons[reference->polygonNum];
                if (polygon.numEdges == 0
                    || polygon.checkCount == model->checkCount) {
                    continue;
                }
                polygon.checkCount = model->checkCount;
                if (MergePolygonWithTreePolygons(model, model->node,
                        reference->polygonNum, mergePrimitives)) {
                    merged = true;
                    break;
                }
            }
        } while (merged);
        if (node->planeType == -1) {
            return;
        }
        MergeTreePolygons(model, node->children[1], mergePrimitives);
        node = node->children[0];
    }
}

void idCollisionModelBuilder::SplitPolygon(cm_buildModel_t* const model,
    const int polygonNum) {
    if (model == nullptr || polygonNum < 0
        || polygonNum >= model->numPolygons) {
        return;
    }
    cm_buildPolygon_t* source = &model->polygons[polygonNum];
    if (source->numEdges <= 16) {
        return;
    }
    const int originalEdges = source->numEdges;
    const int splitStart = 0;
    const int splitEnd = originalEdges / 2;
    const int startReference = model->polygonEdges[
        source->firstEdge + splitStart];
    const int endReference = model->polygonEdges[
        source->firstEdge + splitEnd];
    const int startVertex = DirectedEdgeStart(model, startReference);
    const int endVertex = DirectedEdgeStart(model, endReference);
    if (startVertex == endVertex) {
        return;
    }

    int diagonal = 0;
    GetEdge(model, model->vertices[startVertex].p,
        model->vertices[endVertex].p, diagonal, startVertex);
    if (diagonal == 0) {
        return;
    }
    // GetEdge accounts for one user. Both split polygons use the diagonal.
    ++model->edges[std::abs(diagonal)].numUsers;

    const std::vector<int> original(model->polygonEdges + source->firstEdge,
        model->polygonEdges + source->firstEdge + originalEdges);
    const cm_buildPolygon_t originalFields = *source;
    for (int side = 0; side < 2; ++side) {
        const int begin = side == 0 ? splitStart : splitEnd;
        const int end = side == 0 ? splitEnd : originalEdges;
        const int count = end - begin + 1;
        cm_buildPolygon_t* const split = AllocPolygon(model, count);
        if (split == nullptr) {
            return;
        }
        CopyPolygonFields(*split, originalFields);
        split->bounds[0].Set(FLT_MAX, FLT_MAX, FLT_MAX);
        split->bounds[1].Set(-FLT_MAX, -FLT_MAX, -FLT_MAX);
        int cursor = 0;
        split->numEdges = count;
        const int closing = side == 0 ? -diagonal : diagonal;
        model->polygonEdges[split->firstEdge + cursor++] = closing;
        for (int edge = begin; edge < end; ++edge) {
            const int reference = original[static_cast<std::size_t>(edge)];
            model->polygonEdges[split->firstEdge + cursor++] = reference;
            ++model->edges[std::abs(reference)].numUsers;
        }
        for (int edge = 0; edge < split->numEdges; ++edge) {
            const int vertex = DirectedEdgeStart(model,
                model->polygonEdges[split->firstEdge + edge]);
            const idVec3& point = model->vertices[vertex].p;
            for (int axis = 0; axis < 3; ++axis) {
                split->bounds[0][axis] = (std::min)(
                    split->bounds[0][axis], point[axis]);
                split->bounds[1][axis] = (std::max)(
                    split->bounds[1][axis], point[axis]);
            }
        }
        FilterPolygonIntoTree_r(model, model->node, nullptr, split);
    }
    source = &model->polygons[polygonNum];
    RemovePolygon(model, model->node, polygonNum);
    for (int edge = 0; edge < source->numEdges; ++edge) {
        --model->edges[std::abs(model->polygonEdges[
            source->firstEdge + edge])].numUsers;
    }
    source->numEdges = 0;
}

void idCollisionModelBuilder::SplitPolygons(cm_buildModel_t* const model) {
    if (model == nullptr) {
        return;
    }
    for (int polygonNum = 0; polygonNum < model->numPolygons;
         ++polygonNum) {
        if (model->polygons[polygonNum].numEdges > 16) {
            SplitPolygon(model, polygonNum);
        }
    }
}

idFixedWinding* idCollisionModelBuilder::WindingOutsidePolytopes(
    cm_buildModel_t* const model, idFixedWinding* const winding,
    const idPlane& plane, const int contents, const int primitiveNum) {
    if (model == nullptr || winding == nullptr || model->node == nullptr
        || winding->GetNumPoints() < 3) {
        return winding;
    }
    if (buildData.cm_windingList == nullptr) {
        SetupHash();
    }
    cm_windingList_t& list = *buildData.cm_windingList;
    list.numWindings = 1;
    list.w[0] = *winding;
    list.normal.Set(plane.a, plane.b, plane.c);
    winding->GetBounds(list.bounds);
    list.origin = (list.bounds[0] + list.bounds[1]) * 0.5f;
    list.radius = (list.bounds[1] - list.origin).Length() + 0.1f;
    for (int axis = 0; axis < 3; ++axis) {
        list.bounds[0][axis] -= 0.1f;
        list.bounds[1][axis] += 0.1f;
    }
    list.contents = contents;
    list.primitiveNum = primitiveNum;
    ++model->checkCount;
    ChopWindingListWithTreePolytopes_r(&list, model, model->node);
    if (list.numWindings == 0) {
        return nullptr;
    }
    if (list.numWindings == 1) {
        return &list.w[0];
    }
    if (!model->isWorldModel) {
        return winding;
    }
    int outsideFragment = -1;
    for (int index = 0; index < list.numWindings; ++index) {
        if (!ChoppedAwayByProcBSP(list.w[index], plane, contents)) {
            if (outsideFragment >= 0) {
                return winding;
            }
            outsideFragment = index;
        }
    }
    return outsideFragment >= 0 ? &list.w[outsideFragment] : nullptr;
}

int idCollisionModelBuilder::SetupSubModelData(cm_subModelData_t& data,
    const cm_buildNodeStats_t& stats) {
    data.isConvex = 0;
    data.numNodes = stats.numNodes;
    data.numPrimitiveIndices = stats.numPrimitiveIndices;
    data.numMaterials = stats.numMaterials;
    data.numPolygons = stats.numPolygons;
    data.numPolygonEdges = stats.numPolygonEdges;
    data.numEdges = stats.numEdges;
    data.numVertices = stats.numVertices;
    data.numPolytopes = stats.numPolytopes;
    data.numPolytopePlanes = stats.numPolytopePlanes;
    data.pad = 0;

    data.nodeOffset = 112;
    data.primitiveIndexOffset = Align(
        data.nodeOffset + 16 * data.numNodes, 2);
    data.materialOffset = Align(data.primitiveIndexOffset +
        2 * data.numPrimitiveIndices, 16);
    data.polygonOffset = Align(data.materialOffset +
        16 * data.numMaterials, 16);
    data.polygonEdgeOffset = Align(data.polygonOffset +
        16 * data.numPolygons, 2);
    data.edgeOffset = Align(data.polygonEdgeOffset +
        2 * data.numPolygonEdges, 4);
    data.vertexOffset = Align(data.edgeOffset + 4 * data.numEdges, 16);
    data.polytopeOffset = Align(data.vertexOffset +
        16 * data.numVertices, 16);
    data.polytopePlaneOffset = Align(data.polytopeOffset +
        16 * data.numPolytopes, 16);
    return data.polytopePlaneOffset + 16 * data.numPolytopePlanes;
}

void idCollisionModelBuilder::CalculateSubModelDataSize(
    cm_buildNodeStats_t& stats) {
    cm_subModelData_t data{};
    stats.totalMemory = SetupSubModelData(data, stats);
    stats.canCreateSubModel = stats.numNodes <= 0x10000 &&
        stats.numPrimitiveIndices <= 0x10000 &&
        stats.numMaterials <= 256 && stats.numPolygons <= 0x10000 &&
        stats.numPolygonEdges <= 0x10000 && stats.numEdges <= 0x4000 &&
        stats.numVertices <= 0x10000 && stats.numPolytopes <= 0x10000 &&
        stats.numPolytopePlanes <= 0x10000 &&
        stats.totalMemory <= 0x10000;
}

bool idCollisionModelBuilder::AllocSubModelData(
    const cm_buildNodeStats_t& stats, const idBounds& bounds,
    cm_subModel_t& subModel, cm_subModelPtrs_t& pointers) {
    cm_buildNodeStats_t checked = stats;
    CalculateSubModelDataSize(checked);
    if (!checked.canCreateSubModel) {
        return false;
    }
    std::memset(&subModel, 0, sizeof(subModel));
    subModel.header.totalSize = checked.totalMemory;
    subModel.header.loadedSize = checked.totalMemory;
    subModel.header.bounds = bounds;
    subModel.data = static_cast<cm_subModelData_t*>(_aligned_malloc(
        static_cast<std::size_t>(checked.totalMemory), 16));
    if (subModel.data == nullptr) {
        return false;
    }
    std::memset(subModel.data, 0,
        static_cast<std::size_t>(checked.totalMemory));
    SetupSubModelData(*subModel.data, checked);
    subModel.data->header = subModel.header;
    idPolygonModelCollisionDetection::SetupSubModelPtrsFromData(
        pointers, subModel.data);
    return true;
}

bool idCollisionModelBuilder::BuildForTrm(idCollisionModelLocal* const model,
    const char* const modelName, const idTraceModel& traceModel,
    const idMaterial*) {
    if (model == nullptr) {
        return false;
    }

    model->SetName(modelName);
    model->bounds = traceModel.bounds;
    model->contents = 1;
    model->isWorldModel = false;
    model->isTraceModel = true;
    model->isConvex = traceModel.isConvex;
    model->modelType = CM_POLYGONMODEL;
    model->polygonModel.numModelTreeNodes = 0;
    model->polygonModel.modelTreeNodes = nullptr;
    model->polygonModel.numSubModels = 1;

    cm_buildNodeStats_t stats{};
    stats.numNodes = 1;
    stats.numPrimitiveIndices = static_cast<int>(traceModel.numPolys) +
        (traceModel.isConvex ? 1 : 0);
    stats.numMaterials = 1;
    stats.numPolygons = static_cast<int>(traceModel.numPolys);
    stats.numEdges = static_cast<int>(traceModel.numEdges);
    stats.numVertices = static_cast<int>(traceModel.numVerts);
    stats.numPolytopes = traceModel.isConvex ? 1 : 0;
    stats.numPolytopePlanes = traceModel.isConvex
        ? static_cast<int>(traceModel.numPolys)
        : 0;
    for (unsigned int polygon = 0; polygon < traceModel.numPolys;
         ++polygon) {
        stats.numPolygonEdges +=
            static_cast<int>(traceModel.numPolyEdges[polygon]);
    }
    const int polygonEdgePadding = traceModel.numPolys == 0
        ? 4
        : 4 - (static_cast<int>(
            traceModel.numPolyEdges[traceModel.numPolys - 1]) & 3);
    stats.numPolygonEdges += polygonEdgePadding;
    CalculateSubModelDataSize(stats);
    if (!stats.canCreateSubModel) {
        return false;
    }

    model->polygonModel.subModels = static_cast<cm_subModel_t*>(
        _aligned_malloc(sizeof(cm_subModel_t), 16));
    model->polygonModel.subModelState =
        static_cast<volatile std::uint8_t*>(_aligned_malloc(1, 16));
    if (model->polygonModel.subModels == nullptr ||
        model->polygonModel.subModelState == nullptr) {
        model->FreeData();
        return false;
    }
    std::memset(model->polygonModel.subModels, 0, sizeof(cm_subModel_t));

    cm_subModel_t& subModel = model->polygonModel.subModels[0];
    subModel.header.totalSize = stats.totalMemory;
    subModel.header.loadedSize = 32;
    subModel.header.bounds = traceModel.bounds;
    subModel.data = static_cast<cm_subModelData_t*>(
        _aligned_malloc(static_cast<std::size_t>(stats.totalMemory), 16));
    subModel.fileOffset = -1;
    subModel.numUsers = 0;
    subModel.state = model->polygonModel.subModelState;
    *subModel.state = SUBMODEL_STATE_LOADED;
    if (subModel.data == nullptr) {
        model->FreeData();
        return false;
    }
    std::memset(subModel.data, 0,
        static_cast<std::size_t>(stats.totalMemory));
    SetupSubModelData(*subModel.data, stats);
    subModel.data->header = subModel.header;
    subModel.data->header.loadedSize = subModel.data->header.totalSize;
    subModel.data->isConvex = traceModel.isConvex ? 1 : 0;

    cm_subModelPtrs_t pointers{};
    idPolygonModelCollisionDetection::SetupSubModelPtrsFromData(
        pointers, subModel.data);
    cm_node_t& node = pointers.nodes[0];
    node.planeType = -1;
    node.planeDist = 0.0f;
    node.children[0] = 0;
    node.children[1] = 0;
    node.firstPrimitive = 0;
    node.numPolygons = static_cast<std::uint8_t>(traceModel.numPolys);
    node.numPolytopes = traceModel.isConvex ? 1 : 0;

    if (traceModel.type == TRM_INVALID || traceModel.numPolys == 0) {
        return false;
    }

    cm_material_t& material = pointers.materials[0];
    material.contentFlags = 1;
    material.surfaceFlags = 0;
    material.surfaceType = 0;
    material.surfaceColor[0] = 0xFF;
    material.surfaceColor[1] = 0xFF;
    material.surfaceColor[2] = 0xFF;
    material.pad = 0;

    for (unsigned int vertex = 0; vertex < traceModel.numVerts; ++vertex) {
        pointers.vertices[vertex].p.Set(traceModel.vertsX[vertex],
            traceModel.vertsY[vertex], traceModel.vertsZ[vertex]);
        pointers.vertices[vertex].st[0] = 0;
        pointers.vertices[vertex].st[1] = 0;
    }
    for (unsigned int edge = 0; edge < traceModel.numEdges; ++edge) {
        pointers.edges[edge].vertexNum[0] = traceModel.edges[edge].v[0];
        pointers.edges[edge].vertexNum[1] = traceModel.edges[edge].v[1];
    }

    int polygonEdgeCursor = 0;
    for (unsigned int polygonIndex = 0;
         polygonIndex < traceModel.numPolys; ++polygonIndex) {
        cm_polygon_t& polygon = pointers.polygons[polygonIndex];
        polygon.material = 0;
        polygon.firstEdge =
            static_cast<std::uint16_t>(polygonEdgeCursor);
        polygon.numEdges = static_cast<std::uint8_t>(
            traceModel.numPolyEdges[polygonIndex]);

        idBounds polygonBounds;
        polygonBounds[0].Set(FLT_MAX, FLT_MAX, FLT_MAX);
        polygonBounds[1].Set(-FLT_MAX, -FLT_MAX, -FLT_MAX);
        for (unsigned int edge = 0;
             edge < traceModel.numPolyEdges[polygonIndex]; ++edge) {
            const std::uint8_t traceReference =
                traceModel.polyEdges[polygonIndex][edge];
            const std::uint16_t modelReference =
                static_cast<std::uint16_t>(traceReference & 0x7F) |
                ((traceReference & 0x80) != 0 ? 0x8000 : 0);
            pointers.polygonEdges[polygonEdgeCursor++] = modelReference;
            const cm_edge_t& modelEdge =
                pointers.edges[CM_EdgeIndex(modelReference)];
            const idVec3& point = pointers.vertices[
                CM_EdgeStartVertex(modelEdge, modelReference)].p;
            for (int axis = 0; axis < 3; ++axis) {
                polygonBounds[0][axis] = (std::min)(
                    polygonBounds[0][axis], point[axis]);
                polygonBounds[1][axis] = (std::max)(
                    polygonBounds[1][axis], point[axis]);
            }
        }
        polygon.bounds.SetBounds(polygonBounds);
        pointers.primitiveIndices[polygonIndex] =
            static_cast<std::uint16_t>(polygonIndex);
    }

    const std::uint16_t paddingValue = polygonEdgeCursor > 0
        ? pointers.polygonEdges[polygonEdgeCursor - 1]
        : 0;
    for (int padding = 0; padding < polygonEdgePadding; ++padding) {
        pointers.polygonEdges[polygonEdgeCursor++] = paddingValue;
    }

    if (traceModel.isConvex) {
        pointers.primitiveIndices[traceModel.numPolys] = 0;
        cm_polytope_t& polytope = pointers.polytopes[0];
        polytope.bounds.SetBounds(traceModel.bounds);
        polytope.material = 0;
        polytope.numPlanes =
            static_cast<std::uint8_t>(traceModel.numPolys);
        polytope.firstPlane = 0;
        for (unsigned int plane = 0; plane < traceModel.numPolys; ++plane) {
            pointers.polytopePlanes[plane].a = traceModel.polyPlaneX[plane];
            pointers.polytopePlanes[plane].b = traceModel.polyPlaneY[plane];
            pointers.polytopePlanes[plane].c = traceModel.polyPlaneZ[plane];
            pointers.polytopePlanes[plane].d = traceModel.polyPlaneW[plane];
        }
    }
    return true;
}

bool idCollisionModelBuilder::BuildForGrid(
    idCollisionModelLocal* const model, const char* const modelName,
    const idGenGridModel& grid, const idCollisionGridState& state,
    const idMaterial*) {
    if (model == nullptr || modelName == nullptr || state.numActive <= 0) {
        return false;
    }

    std::vector<int> selectedParts;
    std::vector<int> nodePolygonCounts((std::max)(1, grid.nodes.Num()), 0);
    int sourcePolygonCount = 0;
    int sourcePolygonEdges = 0;
    idBounds modelBounds;
    modelBounds[0].Set(FLT_MAX, FLT_MAX, FLT_MAX);
    modelBounds[1].Set(-FLT_MAX, -FLT_MAX, -FLT_MAX);
    for (int active = state.FirstActive(); active >= 0;
         active = state.NextActive(active)) {
        if (active >= grid.indices.Num()) {
            continue;
        }
        const int partIndex = grid.indices[active];
        if (partIndex == idGenGridModel::INVALID_INDEX
            || partIndex < 0 || partIndex >= grid.parts.Num()) {
            continue;
        }
        const cm_gridPart_t& part = grid.parts[partIndex];
        if (part.nodeIndex >= nodePolygonCounts.size()
            || part.firstPolygonIndex + part.numPolygons
                > grid.polygons.Num()) {
            return false;
        }
        selectedParts.push_back(partIndex);
        sourcePolygonCount += part.numPolygons;
        nodePolygonCounts[part.nodeIndex] += 2 * part.numPolygons;
        const idBounds partBounds = part.bounds.ToBounds();
        for (int axis = 0; axis < 3; ++axis) {
            modelBounds[0][axis] = (std::min)(modelBounds[0][axis],
                partBounds[0][axis]);
            modelBounds[1][axis] = (std::max)(modelBounds[1][axis],
                partBounds[1][axis]);
        }
        for (int polygon = 0; polygon < part.numPolygons; ++polygon) {
            sourcePolygonEdges += grid.polygons[
                part.firstPolygonIndex + polygon].numEdges;
        }
    }
    if (sourcePolygonCount <= 0) {
        return false;
    }
    for (int count : nodePolygonCounts) {
        if (count > 255) {
            return false;
        }
    }

    const int edgePadding = 4 - ((2 * sourcePolygonEdges) & 3);
    cm_buildNodeStats_t stats{};
    stats.numNodes = (std::max)(1, grid.nodes.Num());
    stats.numPrimitiveIndices = 2 * sourcePolygonCount;
    stats.numMaterials = 1;
    stats.numPolygons = 2 * sourcePolygonCount;
    stats.numPolygonEdges = 2 * sourcePolygonEdges + edgePadding;
    stats.numEdges = grid.edges.Num();
    stats.numVertices = grid.vertices.Num();
    stats.numPolytopes = 0;
    stats.numPolytopePlanes = 0;

    model->FreeData();
    model->SetName(modelName);
    model->modelType = CM_POLYGONMODEL;
    model->bounds = modelBounds;
    model->contents = 1;
    model->isWorldModel = false;
    model->isTraceModel = false;
    model->isConvex = false;
    model->isStreamed = false;
    model->polygonModel.numModelTreeNodes = 0;
    model->polygonModel.modelTreeNodes = nullptr;
    model->polygonModel.numSubModels = 1;
    model->polygonModel.subModels = static_cast<cm_subModel_t*>(
        _aligned_malloc(sizeof(cm_subModel_t), 16));
    model->polygonModel.subModelState =
        static_cast<volatile std::uint8_t*>(_aligned_malloc(1, 16));
    if (model->polygonModel.subModels == nullptr
        || model->polygonModel.subModelState == nullptr) {
        model->FreeData();
        return false;
    }
    cm_subModel_t& subModel = model->polygonModel.subModels[0];
    cm_subModelPtrs_t pointers{};
    if (!AllocSubModelData(stats, modelBounds, subModel, pointers)) {
        model->FreeData();
        return false;
    }
    subModel.fileOffset = -1;
    subModel.numUsers = 0;
    subModel.state = model->polygonModel.subModelState;
    *subModel.state = SUBMODEL_STATE_LOADED;
    subModel.data->isConvex = 0;

    cm_material_t& material = pointers.materials[0];
    material.contentFlags = 1;
    material.surfaceFlags = 0;
    material.surfaceType = 0;
    material.surfaceColor[0] = material.surfaceColor[1]
        = material.surfaceColor[2] = 0xFF;
    material.pad = 0;
    for (int index = 0; index < grid.vertices.Num(); ++index) {
        pointers.vertices[index].p = grid.vertices[index];
        pointers.vertices[index].st[0] = 0;
        pointers.vertices[index].st[1] = 0;
    }
    for (int index = 0; index < grid.edges.Num(); ++index) {
        pointers.edges[index] = grid.edges[index];
    }

    std::vector<int> nodeCursors(nodePolygonCounts.size(), 0);
    int primitiveOffset = 0;
    for (int node = 0; node < stats.numNodes; ++node) {
        cm_node_t& destination = pointers.nodes[node];
        if (node < grid.nodes.Num()) {
            const cm_gridNodeBSP_t& source = grid.nodes[node];
            destination.planeType = source.planeType;
            destination.planeDist = source.planeDist;
            destination.children[0] = source.children[0];
            destination.children[1] = source.children[1];
        } else {
            destination.planeType = -1;
            destination.planeDist = 0.0f;
            destination.children[0] = destination.children[1] = 0;
        }
        destination.firstPrimitive =
            static_cast<std::uint16_t>(primitiveOffset);
        destination.numPolygons = static_cast<std::uint8_t>(
            nodePolygonCounts[node]);
        destination.numPolytopes = 0;
        nodeCursors[node] = primitiveOffset;
        primitiveOffset += nodePolygonCounts[node];
    }

    int polygonCursor = 0;
    int edgeCursor = 0;
    for (int partIndex : selectedParts) {
        const cm_gridPart_t& part = grid.parts[partIndex];
        for (int partPolygon = 0; partPolygon < part.numPolygons;
             ++partPolygon) {
            const cm_polygon_t& source = grid.polygons[
                part.firstPolygonIndex + partPolygon];
            for (int side = 0; side < 2; ++side) {
                cm_polygon_t& destination = pointers.polygons[polygonCursor];
                destination = source;
                destination.material = 0;
                destination.firstEdge = static_cast<std::uint16_t>(
                    edgeCursor);
                for (int edge = 0; edge < source.numEdges; ++edge) {
                    const int sourceEdge = side == 0 ? edge
                        : source.numEdges - edge - 1;
                    std::uint16_t reference = grid.polygonEdges[
                        source.firstEdge + sourceEdge];
                    if (side != 0) {
                        reference ^= 0x8000;
                    }
                    pointers.polygonEdges[edgeCursor++] = reference;
                }
                pointers.primitiveIndices[
                    nodeCursors[part.nodeIndex]++] =
                    static_cast<std::uint16_t>(polygonCursor++);
            }
        }
    }
    const std::uint16_t padding = edgeCursor > 0
        ? pointers.polygonEdges[edgeCursor - 1] : 0;
    while (edgeCursor < stats.numPolygonEdges) {
        pointers.polygonEdges[edgeCursor++] = padding;
    }
    return true;
}
