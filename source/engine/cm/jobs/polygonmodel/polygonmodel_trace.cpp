#include "cm/jobs/polygonmodel/polygonmodel.h"

#include <algorithm>
#include <cmath>
#include <cstring>

namespace {

idVec3 Vec3(const idVec4& value) {
    return idVec3(value.x, value.y, value.z);
}

bool PointInsideBounds(const idVec3& point, const idBounds& bounds) {
    return point.x >= bounds[0].x && point.x <= bounds[1].x
        && point.y >= bounds[0].y && point.y <= bounds[1].y
        && point.z >= bounds[0].z && point.z <= bounds[1].z;
}

bool BoundsIntersect(const idBounds& lhs, const idBounds& rhs) {
    return lhs[0].x <= rhs[1].x && lhs[1].x >= rhs[0].x
        && lhs[0].y <= rhs[1].y && lhs[1].y >= rhs[0].y
        && lhs[0].z <= rhs[1].z && lhs[1].z >= rhs[0].z;
}

void ProcessLeaf(idTraceWork* const tw, const cm_node_t& node) {
    // The recovered contents path tests convex polytopes before individual
    // polygons.  A polytope hit is sufficient and avoids reporting one of its
    // boundary polygons as the containing primitive.
    if (tw->traceType == TRACE_CONTENTS
        || tw->traceType == TRACE_CONTENTS_POINT) {
        for (int index = 0; index < node.numPolytopes; ++index) {
            const int polytopeNum = tw->subModelPtrs.primitiveIndices[
                node.firstPrimitive + node.numPolygons + index];
            if (idPolygonModelCollisionDetection::TestTrmVertsInPolytope(
                    tw, polytopeNum)) {
                return;
            }
        }
        if (tw->traceType == TRACE_CONTENTS_POINT) {
            return;
        }
    }

    for (int index = 0; index < node.numPolygons && !tw->quickExit; ++index) {
        const int polygonNum = tw->subModelPtrs.primitiveIndices[
            node.firstPrimitive + index];
        switch (tw->traceType) {
        case TRACE_TRANSLATION:
        case TRACE_CONTACTS_UNI_DIR:
            if (idPolygonModelCollisionDetection::TranslateTrmThroughPolygon(
                    tw, polygonNum)) {
                return;
            }
            break;
        case TRACE_TRANSLATION_POINT:
            if (idPolygonModelCollisionDetection::TranslatePointThroughPolygon(
                    tw, polygonNum)) {
                return;
            }
            break;
        case TRACE_ROTATION:
        case TRACE_ROTATION_POINT:
            if (idPolygonModelCollisionDetection::RotateTrmThroughPolygon(
                    tw, polygonNum)) {
                return;
            }
            break;
        case TRACE_CONTENTS:
            if (idPolygonModelCollisionDetection::TestTrmInPolygon(
                    tw, polygonNum)) {
                return;
            }
            break;
        case TRACE_CONTACTS_OMNI_DIR:
            if (idPolygonModelCollisionDetection::TestTrmInContactWithPolygon(
                    tw, polygonNum)) {
                return;
            }
            break;
        case TRACE_CLIP:
            if (idPolygonModelCollisionDetection::ClipPolygonWithTrm(
                    tw, polygonNum)) {
                return;
            }
            break;
        default:
            break;
        }
    }

}

} // namespace

// Recovered from engine/cm/jobs/polygonmodel/polygonmodel_trace.cpp.
void idPolygonModelCollisionDetection::SetupSubModelPtrsFromData(
    cm_subModelPtrs_t& pointers, const cm_subModelData_t* const data) {
    std::uint8_t* const base = reinterpret_cast<std::uint8_t*>(
        const_cast<cm_subModelData_t*>(data));
    pointers.isConvex = data->isConvex;
    pointers.nodes = reinterpret_cast<cm_node_t*>(base + data->nodeOffset);
    pointers.primitiveIndices = reinterpret_cast<std::uint16_t*>(
        base + data->primitiveIndexOffset);
    pointers.materials = reinterpret_cast<cm_material_t*>(
        base + data->materialOffset);
    pointers.polygons = reinterpret_cast<cm_polygon_t*>(
        base + data->polygonOffset);
    pointers.polygonEdges = reinterpret_cast<std::uint16_t*>(
        base + data->polygonEdgeOffset);
    pointers.edges = reinterpret_cast<cm_edge_t*>(base + data->edgeOffset);
    pointers.vertices = reinterpret_cast<cm_vertex_t*>(
        base + data->vertexOffset);
    pointers.polytopes = reinterpret_cast<cm_polytope_t*>(
        base + data->polytopeOffset);
    pointers.polytopePlanes = reinterpret_cast<idPlane*>(
        base + data->polytopePlaneOffset);
}

cm_subModelData_t* idPolygonModelCollisionDetection::SetupSubModelForBounds(
    cm_subModelData_t* const data, const int size, const idBounds& bounds) {
    constexpr int requiredSize = 608;
    if (data == nullptr || size < requiredSize) {
        return nullptr;
    }
    std::memset(data, 0, requiredSize);
    data->header.totalSize = requiredSize;
    data->header.loadedSize = requiredSize;
    data->header.bounds = bounds;
    data->isConvex = 1;
    data->numNodes = 1;
    data->nodeOffset = 112;
    data->numPrimitiveIndices = 7;
    data->primitiveIndexOffset = 128;
    data->numMaterials = 1;
    data->materialOffset = 144;
    data->numPolygons = 6;
    data->polygonOffset = 160;
    data->numPolygonEdges = 28;
    data->polygonEdgeOffset = 256;
    data->numEdges = 12;
    data->edgeOffset = 312;
    data->numVertices = 8;
    data->vertexOffset = 368;
    data->numPolytopes = 1;
    data->polytopeOffset = 496;
    data->numPolytopePlanes = 6;
    data->polytopePlaneOffset = 512;

    cm_subModelPtrs_t model;
    SetupSubModelPtrsFromData(model, data);
    cm_node_t& node = model.nodes[0];
    node.planeType = -1;
    node.planeDist = 0.0f;
    node.children[0] = node.children[1] = 0;
    node.firstPrimitive = 0;
    node.numPolygons = 6;
    node.numPolytopes = 1;
    for (int index = 0; index < 6; ++index) {
        model.primitiveIndices[index] = static_cast<std::uint16_t>(index);
    }
    model.primitiveIndices[6] = 0;

    cm_material_t& material = model.materials[0];
    material.contentFlags = -1;
    material.surfaceFlags = -1;
    material.surfaceType = 0;
    material.surfaceColor[0] = material.surfaceColor[1]
        = material.surfaceColor[2] = 0xFF;
    material.pad = 0;

    idBounds expanded = bounds;
    for (int axis = 0; axis < 3; ++axis) {
        expanded[0][axis] -= 1.0f;
        expanded[1][axis] += 1.0f;
    }
    for (int polygonNumber = 0; polygonNumber < 6; ++polygonNumber) {
        model.polygons[polygonNumber].bounds.SetBounds(expanded);
        model.polygons[polygonNumber].material = 0;
        model.polygons[polygonNumber].numEdges = 4;
        model.polygons[polygonNumber].firstEdge =
            static_cast<std::uint16_t>(polygonNumber * 4);
    }

    const std::uint16_t polygonEdges[28] = {
        0x8003, 0x8002, 0x8001, 0x8000,
        4, 5, 6, 7,
        0, 9, 0x8004, 0x8008,
        1, 10, 0x8005, 0x8009,
        2, 11, 0x8006, 0x800A,
        3, 8, 0x8007, 0x800B,
        0x800B, 0x800B, 0x800B, 0x800B
    };
    std::memcpy(model.polygonEdges, polygonEdges, sizeof(polygonEdges));

    for (int index = 0; index < 4; ++index) {
        model.edges[index].vertexNum[0] = static_cast<std::uint16_t>(index);
        model.edges[index].vertexNum[1] =
            static_cast<std::uint16_t>((index + 1) & 3);
        model.edges[index + 4].vertexNum[0] =
            static_cast<std::uint16_t>(index + 4);
        model.edges[index + 4].vertexNum[1] =
            static_cast<std::uint16_t>(((index + 1) & 3) + 4);
        model.edges[index + 8].vertexNum[0] =
            static_cast<std::uint16_t>(index);
        model.edges[index + 8].vertexNum[1] =
            static_cast<std::uint16_t>(index + 4);
    }

    for (int index = 0; index < 8; ++index) {
        model.vertices[index].p.Set(
            (index == 1 || index == 2 || index == 5 || index == 6)
                ? bounds[1].x : bounds[0].x,
            (index == 2 || index == 3 || index == 6 || index == 7)
                ? bounds[1].y : bounds[0].y,
            index >= 4 ? bounds[1].z : bounds[0].z);
        model.vertices[index].st[0] = model.vertices[index].st[1] = 0;
    }

    model.polytopes[0].bounds.SetBounds(expanded);
    model.polytopes[0].material = 0;
    model.polytopes[0].numPlanes = 6;
    model.polytopes[0].firstPlane = 0;
    model.polytopePlanes[0] = idPlane(0.0f, 0.0f, -1.0f, bounds[0].z);
    model.polytopePlanes[1] = idPlane(0.0f, 0.0f, 1.0f, -bounds[1].z);
    model.polytopePlanes[2] = idPlane(0.0f, -1.0f, 0.0f, bounds[0].y);
    model.polytopePlanes[3] = idPlane(0.0f, 1.0f, 0.0f, -bounds[1].y);
    model.polytopePlanes[4] = idPlane(1.0f, 0.0f, 0.0f, -bounds[1].x);
    model.polytopePlanes[5] = idPlane(-1.0f, 0.0f, 0.0f, bounds[0].x);
    return data;
}

bool idPolygonModelCollisionDetection::TestStuckInSubModelBounds(
    idTraceWork* const tw, const idBounds& subModelBounds) {
    if (tw->traceType <= TRACE_INVALID || tw->traceType > TRACE_CLIP) {
        return false;
    }
    idBounds traceAtStart;
    traceAtStart[0] = Vec3(tw->start) + Vec3(tw->trmBoundsMin);
    traceAtStart[1] = Vec3(tw->start) + Vec3(tw->trmBoundsMax);
    if (!BoundsIntersect(traceAtStart, subModelBounds)) {
        return false;
    }
    int vertexNumber = 0;
    for (; vertexNumber < static_cast<int>(tw->numVerts); ++vertexNumber) {
        if (PointInsideBounds(Vec3(tw->vertexPosition[vertexNumber]),
                subModelBounds)) {
            break;
        }
    }
    if (vertexNumber >= static_cast<int>(tw->numVerts)) {
        return false;
    }
    if (tw->traceResult != nullptr) {
        trace_t& trace = *tw->traceResult;
        trace.fraction = 0.0f;
        trace.c.type = CONTACT_MODELVERTEX;
        trace.c.point = Vec3(tw->start);
        trace.c.normal.Set(0.0f, 0.0f, 1.0f);
        trace.c.dist = tw->start.w;
        trace.c.separation = 0.0f;
        trace.c.contentFlags = -1;
        trace.c.surfaceFlags = 0;
        trace.c.surfaceType = 0;
        trace.c.surfaceColor[0] = trace.c.surfaceColor[1]
            = trace.c.surfaceColor[2] = 0xFF;
        trace.c.modelFeature = (tw->subModelNum << 16) & 0x1FFF0000;
        trace.c.trmFeature = 0;
        trace.c.flags = CONTACT_FLAG_SUBMODEL_NOT_RESIDENT;
    }
    return true;
}

idVec3 idPolygonModelCollisionDetection::LocalExtentsFromUnTransformedBounds(
    const idBounds& globalBounds, const idVec3& globalStart,
    const idVec3& globalEnd, const idMat3& modelAxis) {
    idVec3 globalExtents;
    for (int axis = 0; axis < 3; ++axis) {
        const float pathMinimum = (std::min)(globalStart[axis], globalEnd[axis]);
        const float pathMaximum = (std::max)(globalStart[axis], globalEnd[axis]);
        const float negativeExtent = pathMinimum - globalBounds[0][axis];
        const float positiveExtent = globalBounds[1][axis] - pathMaximum;
        globalExtents[axis] = (std::max)(negativeExtent, positiveExtent);
    }
    return idVec3(
        std::fabs(modelAxis[0].x) * globalExtents.x
            + std::fabs(modelAxis[0].y) * globalExtents.y
            + std::fabs(modelAxis[0].z) * globalExtents.z,
        std::fabs(modelAxis[1].x) * globalExtents.x
            + std::fabs(modelAxis[1].y) * globalExtents.y
            + std::fabs(modelAxis[1].z) * globalExtents.z,
        std::fabs(modelAxis[2].x) * globalExtents.x
            + std::fabs(modelAxis[2].y) * globalExtents.y
            + std::fabs(modelAxis[2].z) * globalExtents.z);
}

void idPolygonModelCollisionDetection::TraceThroughSubModelTree(
    idTraceWork* const tw) {
    if (tw == nullptr || tw->subModelPtrs.nodes == nullptr || tw->quickExit) {
        return;
    }
    std::uint16_t stack[128];
    int stackSize = 0;
    stack[stackSize++] = 0;
    int iterations = 0;
    while (stackSize != 0 && !tw->quickExit && iterations++ < 65536) {
        const std::uint16_t nodeNumber = stack[--stackSize];
        const cm_node_t& node = tw->subModelPtrs.nodes[nodeNumber];
        if (node.numPolygons != 0 || node.numPolytopes != 0) {
            ProcessLeaf(tw, node);
        }
        if (node.planeType == -1) {
            continue;
        }
        // Check-counts remove duplicate primitive work, so visiting both sides
        // is a conservative scalar replacement for the VMX swept-tree walk.
        if (stackSize <= 126) {
            stack[stackSize++] = node.children[1];
            stack[stackSize++] = node.children[0];
        }
    }
}

void idPolygonModelCollisionDetection::TraceThroughSubModel(
    idTraceWork* const tw, const cm_subModelData_t* subModelData,
    const int subModelNum) {
    if (tw == nullptr || subModelData == nullptr) {
        return;
    }
    const cm_subModelData_t* data = subModelData;
    if (data->header.loadedSize == sizeof(cm_subModelHeader_t)) {
        if (TestStuckInSubModelBounds(tw, data->header.bounds)) {
            return;
        }
        data = SetupSubModelForBounds(
            reinterpret_cast<cm_subModelData_t*>(tw->subModelDataForBounds),
            static_cast<int>(sizeof(tw->subModelDataForBounds)),
            data->header.bounds);
        if (data == nullptr) {
            return;
        }
    }
    SetupSubModelPtrsFromData(tw->subModelPtrs, data);
    tw->modelCheckCounts.SetupForSubModel(data);
    tw->subModelNum = subModelNum;
    TraceThroughSubModelTree(tw);
    if (subModelData->header.loadedSize == sizeof(cm_subModelHeader_t)
        && tw->traceResult != nullptr && tw->traceResult->fraction < 1.0f) {
        tw->traceResult->c.flags |= CONTACT_FLAG_SUBMODEL_NOT_RESIDENT;
    }
}

unsigned int idPolygonModelCollisionDetection::GetSubModelsForTrace(
    const cm_polygonModel_t& model, const idVec3&, const idVec3&,
    const idVec3&, int* const subModelNums) {
    if (subModelNums == nullptr || model.numSubModels <= 0) {
        return 0;
    }
    const unsigned int count = static_cast<unsigned int>((std::min)(
        model.numSubModels, 128));
    for (unsigned int index = 0; index < count; ++index) {
        subModelNums[index] = static_cast<int>(index);
    }
    return count;
}

void idPolygonModelCollisionDetection::TraceThroughModel(
    idTraceWork* const tw, const cm_polygonModel_t& model) {
    int subModelNums[128];
    const unsigned int count = GetSubModelsForTrace(model, Vec3(tw->start),
        Vec3(tw->end), Vec3(tw->trmExtents), subModelNums);
    for (unsigned int index = 0; index < count && !tw->quickExit; ++index) {
        const int subModelNum = subModelNums[index];
        const cm_subModel_t& subModel = model.subModels[subModelNum];
        const cm_subModelData_t* const data = AcquireSubModelData(subModel);
        TraceThroughSubModel(tw, data, subModelNum);
        ReleaseSubModelData(subModel, data);
    }
}
