#include "cm/collisionmodelmanager.h"

#include "cm/collisionmodel.h"
#include "cm/jobs/polygonmodel/polygonmodel.h"
#include "cm/jobs/polygonmodel/polygonmodeldata.h"
#include "cm/jobs/spheremodel/spheremodel.h"
#include "idlib/geometry/jointtransform.h"

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

namespace {

idCollisionDebugDrawSink* debugDrawSink = nullptr;

struct contentsName_t {
    const char* name;
    int flag;
};

const contentsName_t contentsNames[] = {
    { "solid", 0x00000001 }, { "opaque", 0x00000002 },
    { "water", 0x00000004 }, { "playerclip", 0x00000008 },
    { "monsterclip", 0x00000010 }, { "vehicleclip", 0x00000020 },
    { "moveableclip", 0x00000040 }, { "shotclip", 0x00000080 },
    { "ikclip", 0x00000100 }, { "aiaware", 0x00000200 },
    { "ai", 0x00000400 }, { "projectile", 0x00000800 },
    { "corpse", 0x00001000 }, { "breakable", 0x00002000 },
    { "trigger", 0x00004000 }, { "player", 0x00008000 },
    { "vehicle", 0x00010000 }, { "obstacle", 0x00020000 },
    { "contextualcover_clip", 0x00040000 },
    { "playercoverclip", 0x00080000 },
    { "monstercoverclip", 0x00100000 },
    { "playerfocus", 0x00200000 }, { "pushable", 0x00400000 },
    { "shield", 0x00800000 }, { "tickclip", 0x01000000 },
    { "aas_fly", 0x02000000 }, { "aas_solid", 0x04000000 },
    { "aas_obstacle", 0x08000000 },
    { "aas_cluster_portal", 0x10000000 },
    { "aas_walkable_wall", 0x20000000 },
    { "nocover", 0x40000000 },
    { "do_not_use", static_cast<int>(0x80000000u) }
};

idVec3 TransformPoint(const idVec3& point, const idVec3& origin,
    const idMat3& axis) {
    return origin + idVec3(
        axis[0].x * point.x + axis[1].x * point.y + axis[2].x * point.z,
        axis[0].y * point.x + axis[1].y * point.y + axis[2].y * point.z,
        axis[0].z * point.x + axis[1].z * point.y + axis[2].z * point.z);
}

bool InRadius(const idVec3& point, const idVec3& viewOrigin,
    const float radius) {
    return radius <= 0.0f
        || (point - viewOrigin).LengthSqr() <= radius * radius;
}

void DrawEdge(const cm_subModelPtrs_t* const pointers,
    const std::uint16_t edgeReference, const idVec3& origin,
    const idMat3& axis, const idVec3& viewOrigin, const float radius,
    const int lifeTime) {
    if (debugDrawSink == nullptr) {
        return;
    }
    const cm_edge_t& edge = pointers->edges[CM_EdgeIndex(edgeReference)];
    const idVec3 start = TransformPoint(pointers->vertices[
        CM_EdgeStartVertex(edge, edgeReference)].p, origin, axis);
    const idVec3 end = TransformPoint(pointers->vertices[
        CM_EdgeEndVertex(edge, edgeReference)].p, origin, axis);
    if (InRadius(start, viewOrigin, radius)
        || InRadius(end, viewOrigin, radius)) {
        debugDrawSink->DrawLine(start, end,
            (edgeReference & 0x4000) != 0, lifeTime);
    }
}

void DrawPolygon(const cm_subModelPtrs_t* const pointers,
    const cm_polygon_t& polygon, const idVec3& origin,
    const idMat3& axis, const idVec3& viewOrigin, const float radius,
    const int lifeTime) {
    if (debugDrawSink == nullptr || polygon.numEdges == 0) {
        return;
    }
    std::vector<idVec3> points;
    points.reserve(polygon.numEdges);
    bool visible = radius <= 0.0f;
    for (int index = 0; index < polygon.numEdges; ++index) {
        const std::uint16_t edgeReference = pointers->polygonEdges[
            polygon.firstEdge + index];
        const cm_edge_t& edge = pointers->edges[CM_EdgeIndex(edgeReference)];
        points.push_back(TransformPoint(pointers->vertices[
            CM_EdgeStartVertex(edge, edgeReference)].p, origin, axis));
        visible = visible || InRadius(points.back(), viewOrigin, radius);
    }
    if (!visible) {
        return;
    }
    const cm_material_t& material = pointers->materials[polygon.material];
    debugDrawSink->DrawPolygon(points.data(),
        static_cast<int>(points.size()), material.contentFlags,
        material.surfaceFlags, material.surfaceType, lifeTime);
    for (int index = 0; index < polygon.numEdges; ++index) {
        DrawEdge(pointers, pointers->polygonEdges[polygon.firstEdge + index],
            origin, axis, viewOrigin, radius, lifeTime);
    }
}

void DrawNodePolygons(const cm_subModelPtrs_t* const pointers,
    const cm_subModelData_t& data, const idVec3& origin,
    const idMat3& axis, const idVec3& viewOrigin, const float radius,
    const int lifeTime) {
    for (int polygon = 0; polygon < data.numPolygons; ++polygon) {
        DrawPolygon(pointers, pointers->polygons[polygon], origin, axis,
            viewOrigin, radius, lifeTime);
    }
}

void SpeedTest(const idVec3*) {
    // The recovered benchmark is command/CVar driven.  Query timing belongs
    // to the console integration layer; collision drawing itself is live.
}

void DebugTranslationFailure(const idVec3*, const idMat3*) {}
void DebugRotationFailure(const idVec3*, const idMat3*) {}
void DebugFailedQuery(const idVec3*, const idMat3*) {}

} // namespace

int ContentsFromString(const char* const string) {
    if (string == nullptr) {
        return 0;
    }
    int flags = 0;
    const char* cursor = string;
    while (*cursor != '\0') {
        while (*cursor != '\0'
            && (std::isspace(static_cast<unsigned char>(*cursor))
                || *cursor == ',')) {
            ++cursor;
        }
        const char* const begin = cursor;
        while (*cursor != '\0'
            && !std::isspace(static_cast<unsigned char>(*cursor))
            && *cursor != ',') {
            ++cursor;
        }
        if (cursor == begin) {
            continue;
        }
        std::string token(begin, cursor);
        if (token.compare(0, 9, "CONTENTS_") == 0
            || token.compare(0, 9, "contents_") == 0) {
            token.erase(0, 9);
        }
        for (const contentsName_t& entry : contentsNames) {
            if (_stricmp(token.c_str(), entry.name) == 0) {
                flags |= entry.flag;
                break;
            }
        }
    }
    return flags;
}

void idCollisionModelManager::SetDebugDrawSink(
    idCollisionDebugDrawSink* const sink) {
    debugDrawSink = sink;
}

void idCollisionModelManager::DrawCollisionModel(
    idCollisionModel* const model, const idJointMat* const modelJoints,
    const idVec3& modelOrigin, const idMat3& modelAxis,
    const idVec3& viewOrigin, const idMat3&, const float radius,
    const int lifeTime) {
    if (debugDrawSink == nullptr || model == nullptr) {
        return;
    }
    idCollisionModelLocal* const local =
        dynamic_cast<idCollisionModelLocal*>(model);
    if (local == nullptr) {
        return;
    }
    if (local->modelType == CM_SPHEREMODEL && local->sphereModel != nullptr) {
        cm_sphereModelPtrs_t spheres{};
        const int count = idSphereModelCollisionDetection::
            SetupCollisionSpherePtrs(local->sphereModel, spheres);
        for (int index = 0; index < count; ++index) {
            idVec3 center(spheres.offsetX[index], spheres.offsetY[index],
                spheres.offsetZ[index]);
            if (modelJoints != nullptr) {
                const idJointMat& joint = modelJoints[spheres.joint[index]];
                center.Set(
                    joint.mat[0] * center.x + joint.mat[1] * center.y
                        + joint.mat[2] * center.z + joint.mat[3],
                    joint.mat[4] * center.x + joint.mat[5] * center.y
                        + joint.mat[6] * center.z + joint.mat[7],
                    joint.mat[8] * center.x + joint.mat[9] * center.y
                        + joint.mat[10] * center.z + joint.mat[11]);
            }
            center = TransformPoint(center, modelOrigin, modelAxis);
            if (InRadius(center, viewOrigin, radius)) {
                debugDrawSink->DrawSphere(center, spheres.radius[index],
                    spheres.surfType[index], lifeTime);
            }
        }
        return;
    }
    if (local->modelType != CM_POLYGONMODEL) {
        return;
    }
    for (int index = 0; index < local->polygonModel.numSubModels; ++index) {
        const cm_subModel_t& subModel = local->polygonModel.subModels[index];
        const cm_subModelData_t* const data = AcquireSubModelData(subModel);
        if (data != nullptr && data->header.loadedSize != 32) {
            cm_subModelPtrs_t pointers{};
            idPolygonModelCollisionDetection::SetupSubModelPtrsFromData(
                pointers, data);
            DrawNodePolygons(&pointers, *data, modelOrigin, modelAxis,
                viewOrigin, radius, lifeTime);
        }
        ReleaseSubModelData(subModel, data);
    }
}

void idCollisionModelManager::DebugOutput(const idVec3& viewOrigin,
    const idMat3& viewAxis) {
    SpeedTest(&viewOrigin);
    DebugTranslationFailure(&viewOrigin, &viewAxis);
    DebugRotationFailure(&viewOrigin, &viewAxis);
    DebugFailedQuery(&viewOrigin, &viewAxis);
}
