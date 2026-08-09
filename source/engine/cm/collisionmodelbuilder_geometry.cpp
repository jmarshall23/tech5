#include "cm/collisionmodelbuilder.h"

#include "cm/collisionmodel.h"
#include "framework/resourcelist.h"
#include "idlib/geometry/drawvert.h"
#include "idlib/geometry/surface_patch.h"
#include "idlib/lib_print.h"
#include "idlib/sys/sys_alloc.h"
#include "mapfile/mapfile.h"

#include <algorithm>
#include <cfloat>
#include <cmath>
#include <cstring>
#include <malloc.h>
#include <vector>

namespace {

cm_materialBuildInfoExtractor_t materialInfoExtractor = nullptr;
cm_materialResolver_t materialResolver = nullptr;
cm_renderModelBuildExtractor_t renderModelExtractor = nullptr;
cm_staticModelBuildExtractor_t staticModelExtractor = nullptr;
cm_mapFileBuildCallback_t mapFileBuildCallback = nullptr;

idVec3 TransformPoint(const idVec3& point, const idVec3& origin,
    const idMat3& axis, const idVec3& scale) {
    const idVec3 scaled(point.x * scale.x, point.y * scale.y,
        point.z * scale.z);
    return origin + idVec3(
        axis[0].x * scaled.x + axis[1].x * scaled.y
            + axis[2].x * scaled.z,
        axis[0].y * scaled.x + axis[1].y * scaled.y
            + axis[2].y * scaled.z,
        axis[0].z * scaled.x + axis[1].z * scaled.y
            + axis[2].z * scaled.z);
}

bool PlaneFromPoints(const idVec3& first, const idVec3& second,
    const idVec3& third, idPlane& plane) {
    idVec3 normal = (second - first).Cross(third - first);
    if (normal.NormalizeFast() == 0.0f) {
        return false;
    }
    plane = idPlane(normal.x, normal.y, normal.z, -normal.Dot(first));
    return true;
}

idFixedWinding BasePlaneWinding(const idPlane& plane) {
    idVec3 normal(plane.a, plane.b, plane.c);
    normal.NormalizeFast();
    idVec3 reference = std::fabs(normal.z) < 0.9f
        ? idVec3(0.0f, 0.0f, 1.0f)
        : idVec3(0.0f, 1.0f, 0.0f);
    idVec3 right = reference.Cross(normal);
    right.NormalizeFast();
    idVec3 up = normal.Cross(right);
    up.NormalizeFast();
    const idVec3 center = normal * -plane.d;
    constexpr float radius = 131072.0f;
    right = right * radius;
    up = up * radius;
    idFixedWinding winding;
    winding.AddPoint(center - right - up);
    winding.AddPoint(center + right - up);
    winding.AddPoint(center + right + up);
    winding.AddPoint(center - right + up);
    return winding;
}

bool ClipWindingToBrush(const idMapBrush& brush, const int sideIndex,
    idFixedWinding& winding) {
    for (int otherIndex = 0; otherIndex < brush.sides.Num(); ++otherIndex) {
        if (otherIndex == sideIndex || brush.sides[otherIndex] == nullptr) {
            continue;
        }
        idFixedWinding back;
        const int side = winding.SplitInPlace(
            brush.sides[otherIndex]->plane, 0.1f, &back);
        if (side == 0) {
            winding.Clear();
            return false;
        }
        if (side == 3) {
            winding = back;
        }
        if (winding.GetNumPoints() < 3) {
            return false;
        }
    }
    return winding.GetNumPoints() >= 3;
}

void TransformWinding(idFixedWinding& winding, const idVec3& origin,
    const idMat3& axis, const idVec3& scale) {
    for (int index = 0; index < winding.GetNumPoints(); ++index) {
        const idVec3 transformed = TransformPoint(idVec3(
            winding[index].x, winding[index].y, winding[index].z),
            origin, axis, scale);
        winding[index].x = transformed.x;
        winding[index].y = transformed.y;
        winding[index].z = transformed.z;
    }
}

void AddPointToBounds(idBounds& bounds, const idVec3& point) {
    for (int axis = 0; axis < 3; ++axis) {
        bounds[0][axis] = (std::min)(bounds[0][axis], point[axis]);
        bounds[1][axis] = (std::max)(bounds[1][axis], point[axis]);
    }
}

void AddBoundsToBounds(idBounds& destination, const idBounds& source) {
    for (int axis = 0; axis < 3; ++axis) {
        destination[0][axis] = (std::min)(destination[0][axis],
            source[0][axis]);
        destination[1][axis] = (std::max)(destination[1][axis],
            source[1][axis]);
    }
}

const idMaterial* ResolveMaterial(const idStr& name,
    const idMaterial* const overrideMaterial) {
    if (overrideMaterial != nullptr) {
        return overrideMaterial;
    }
    return materialResolver != nullptr ? materialResolver(name.c_str())
                                       : nullptr;
}

bool ExtractModel(const idCollisionModelBuilder::idStaticModelGeometry& g,
    cm_modelBuildSource_t& source) {
    std::memset(&source, 0, sizeof(source));
    if (g.staticModel != nullptr && staticModelExtractor != nullptr) {
        return staticModelExtractor(g.staticModel, source);
    }
    if (g.renderModel != nullptr && renderModelExtractor != nullptr) {
        return renderModelExtractor(g.renderModel, source);
    }
    return false;
}

int PrimitiveGroup(
    const idCollisionModelBuilder::idStaticModelGeometry& geometry,
    const int primitiveIndex) {
    return primitiveIndex >= 0
            && primitiveIndex < geometry.primitiveGroupNumbers.Num()
        ? geometry.primitiveGroupNumbers[primitiveIndex]
        : 0;
}

const idMaterial* MapPrimitiveMaterial(const idMapPrimitive* primitive,
    const idMaterial* overrideMaterial) {
    if (overrideMaterial != nullptr) {
        return overrideMaterial;
    }
    if (primitive == nullptr) {
        return nullptr;
    }
    if (primitive->type == MAP_PRIMITIVE_PATCH) {
        return ResolveMaterial(static_cast<const idMapPatch*>(primitive)
            ->material, nullptr);
    }
    const idMapBrush* const brush =
        static_cast<const idMapBrush*>(primitive);
    return brush->sides.Num() > 0 && brush->sides[0] != nullptr
        ? ResolveMaterial(brush->sides[0]->material, nullptr) : nullptr;
}

} // namespace

bool CM_GetMaterialBuildInfo(const idMaterial* const material,
    cm_materialBuildInfo_t& info) {
    info.contents = 1;
    info.surfaceFlags = 0;
    info.surfaceType = 0;
    info.discrete = false;
    return materialInfoExtractor != nullptr
        ? materialInfoExtractor(material, info) : material == nullptr;
}

void idCollisionModelBuilder::SetMaterialBuildInfoExtractor(
    const cm_materialBuildInfoExtractor_t extractor) {
    materialInfoExtractor = extractor;
}

void idCollisionModelBuilder::SetMaterialResolver(
    const cm_materialResolver_t resolver) {
    materialResolver = resolver;
}

void idCollisionModelBuilder::SetRenderModelBuildExtractor(
    const cm_renderModelBuildExtractor_t extractor) {
    renderModelExtractor = extractor;
}

void idCollisionModelBuilder::SetStaticModelBuildExtractor(
    const cm_staticModelBuildExtractor_t extractor) {
    staticModelExtractor = extractor;
}

void idCollisionModelBuilder::SetMapFileBuildCallback(
    const cm_mapFileBuildCallback_t callback) {
    mapFileBuildCallback = callback;
}

int idCollisionModelBuilder::SetupBuildGroups(
    idCollisionModelGeometry& geometry) {
    int nextGroup = 1;
    for (int modelIndex = 0; modelIndex < geometry.models.Num();
         ++modelIndex) {
        idStaticModelGeometry& model = geometry.models[modelIndex];
        if (model.mapModel != nullptr) {
            model.primitiveGroupNumbers.SetNum(
                model.mapModel->primitives.Num());
            for (int index = 0; index < model.primitiveGroupNumbers.Num();
                 ++index) {
                model.primitiveGroupNumbers[index] = 0;
            }
            continue;
        }
        cm_modelBuildSource_t source{};
        if (!ExtractModel(model, source) || source.numSurfaces < 0) {
            model.primitiveGroupNumbers.Clear();
            continue;
        }
        model.primitiveGroupNumbers.SetNum(source.numSurfaces);
        bool hasCollisionSurface = false;
        for (int index = 0; index < source.numSurfaces; ++index) {
            cm_materialBuildInfo_t info{};
            CM_GetMaterialBuildInfo(source.surfaces[index].material, info);
            hasCollisionSurface |= (info.surfaceFlags & 0x40) != 0;
        }
        for (int index = 0; index < source.numSurfaces; ++index) {
            cm_materialBuildInfo_t info{};
            CM_GetMaterialBuildInfo(source.surfaces[index].material, info);
            const bool enabled = (info.contents & 0xEBFFFFFF) != 0
                && (!hasCollisionSurface
                    || (info.surfaceFlags & 0x40) != 0);
            model.primitiveGroupNumbers[index] = !enabled ? -1
                : geometry.allowDiscrete && info.discrete
                    ? nextGroup++ : 0;
        }
    }
    return nextGroup;
}

void idCollisionModelBuilder::AddRenderModelEstimates(
    const idStaticModelGeometry& geometry, const int groupNum,
    const int, int& numVertices, int& numEdges, int& numPolygons,
    idBounds& bounds) {
    cm_modelBuildSource_t source{};
    if (!ExtractModel(geometry, source)) {
        return;
    }
    for (int surfaceIndex = 0; surfaceIndex < source.numSurfaces;
         ++surfaceIndex) {
        if (PrimitiveGroup(geometry, surfaceIndex) != groupNum) {
            continue;
        }
        const cm_modelSurfaceBuildSource_t& surface =
            source.surfaces[surfaceIndex];
        if (surface.vertices == nullptr || surface.indices == nullptr
            || surface.numIndices < 3) {
            continue;
        }
        numVertices += surface.numVertices;
        numEdges += surface.numIndices;
        numPolygons += surface.numIndices / 3;
        for (int vertex = 0; vertex < surface.numVertices; ++vertex) {
            AddPointToBounds(bounds, TransformPoint(
                surface.vertices[vertex].xyz, geometry.origin,
                geometry.axis, geometry.scale));
        }
    }
}

void idCollisionModelBuilder::GetMapModelBrushBounds(
    const idStaticModelGeometry& geometry, const int groupNum,
    idBounds& bounds) {
    if (geometry.mapModel == nullptr) {
        return;
    }
    for (int primitiveIndex = 0;
         primitiveIndex < geometry.mapModel->primitives.Num();
         ++primitiveIndex) {
        const idMapPrimitive* const primitive =
            geometry.mapModel->primitives[primitiveIndex];
        if (primitive == nullptr || primitive->type != MAP_PRIMITIVE_BRUSH
            || PrimitiveGroup(geometry, primitiveIndex) != groupNum) {
            continue;
        }
        const idMapBrush& brush = *static_cast<const idMapBrush*>(primitive);
        for (int sideIndex = 0; sideIndex < brush.sides.Num(); ++sideIndex) {
            if (brush.sides[sideIndex] == nullptr) {
                continue;
            }
            idFixedWinding side = BasePlaneWinding(
                brush.sides[sideIndex]->plane);
            if (!ClipWindingToBrush(brush, sideIndex, side)) {
                continue;
            }
            TransformWinding(side, geometry.origin, geometry.axis,
                geometry.scale);
            idBounds sideBounds;
            side.GetBounds(sideBounds);
            AddBoundsToBounds(bounds, sideBounds);
        }
    }
}

void idCollisionModelBuilder::AddMapModelEstimates(
    const idStaticModelGeometry& geometry, const int groupNum,
    const int, int& numVertices, int& numEdges, int& numPolygons,
    idBounds& bounds) {
    if (geometry.mapModel == nullptr) {
        return;
    }
    GetMapModelBrushBounds(geometry, groupNum, bounds);
    for (int primitiveIndex = 0;
         primitiveIndex < geometry.mapModel->primitives.Num();
         ++primitiveIndex) {
        const idMapPrimitive* const primitive =
            geometry.mapModel->primitives[primitiveIndex];
        if (primitive == nullptr
            || PrimitiveGroup(geometry, primitiveIndex) != groupNum) {
            continue;
        }
        if (primitive->type == MAP_PRIMITIVE_BRUSH) {
            const int sides = static_cast<const idMapBrush*>(primitive)
                ->sides.Num();
            numVertices += sides * 8;
            numEdges += sides * 8;
            numPolygons += sides;
        } else if (primitive->type == MAP_PRIMITIVE_PATCH) {
            const idMapPatch* const patch =
                static_cast<const idMapPatch*>(primitive);
            numVertices += patch->verts.Num();
            numEdges += patch->indexes.Num();
            numPolygons += patch->indexes.Num() / 3;
            for (int vertex = 0; vertex < patch->verts.Num(); ++vertex) {
                AddPointToBounds(bounds, TransformPoint(
                    patch->verts[vertex].xyz, geometry.origin,
                    geometry.axis, geometry.scale));
            }
        }
    }
}

void idCollisionModelBuilder::ConvertBrush(cm_buildModel_t* const model,
    const idMapBrush* const brush, const idVec3& origin,
    const idMat3& axis, const idVec3& scale,
    const idMaterial* const overrideMaterial, const int primitiveNum) {
    if (model == nullptr || brush == nullptr || brush->sides.Num() < 4) {
        return;
    }
    cm_buildPolytope_t* const polytope = AllocPolytope(model,
        brush->sides.Num());
    if (polytope == nullptr) {
        return;
    }
    polytope->bounds[0].Set(FLT_MAX, FLT_MAX, FLT_MAX);
    polytope->bounds[1].Set(-FLT_MAX, -FLT_MAX, -FLT_MAX);
    polytope->primitiveNum = primitiveNum;
    const idMaterial* material = overrideMaterial;
    for (int sideIndex = 0; sideIndex < brush->sides.Num(); ++sideIndex) {
        const idMapBrushSide* const side = brush->sides[sideIndex];
        if (side == nullptr) {
            polytope->numPlanes = 0;
            return;
        }
        if (material == nullptr) {
            material = ResolveMaterial(side->material, nullptr);
        }
        idFixedWinding winding = BasePlaneWinding(side->plane);
        if (!ClipWindingToBrush(*brush, sideIndex, winding)) {
            polytope->numPlanes = 0;
            return;
        }
        TransformWinding(winding, origin, axis, scale);
        idBounds windingBounds;
        winding.GetBounds(windingBounds);
        AddBoundsToBounds(polytope->bounds, windingBounds);
        idPlane transformedPlane;
        if (!PlaneFromPoints(idVec3(winding[0].x, winding[0].y,
                winding[0].z), idVec3(winding[1].x, winding[1].y,
                winding[1].z), idVec3(winding[2].x, winding[2].y,
                winding[2].z), transformedPlane)) {
            polytope->numPlanes = 0;
            return;
        }
        model->polytopePlanes[polytope->firstPlane + sideIndex] =
            transformedPlane;
    }
    cm_materialBuildInfo_t info{};
    CM_GetMaterialBuildInfo(material, info);
    polytope->contents = info.contents;
    polytope->material = FindMaterial(model, info.contents,
        info.surfaceFlags, info.surfaceType);
    if (model->node == nullptr) {
        model->node = AllocNode(model, 8);
    }
    AddBoundsToBounds(model->node->bounds, polytope->bounds);
    AddPolytopeToNode(model, model->node, polytope);
}

void idCollisionModelBuilder::ConvertBrushSides(
    cm_buildModel_t* const model, const idMapBrush* const brush,
    const idVec3& origin, const idMat3& axis, const idVec3& scale,
    const idMaterial* const overrideMaterial, const int primitiveNum) {
    if (model == nullptr || brush == nullptr) {
        return;
    }
    for (int sideIndex = 0; sideIndex < brush->sides.Num(); ++sideIndex) {
        const idMapBrushSide* const side = brush->sides[sideIndex];
        if (side == nullptr) {
            continue;
        }
        idFixedWinding winding = BasePlaneWinding(side->plane);
        if (!ClipWindingToBrush(*brush, sideIndex, winding)) {
            continue;
        }
        TransformWinding(winding, origin, axis, scale);
        idPlane plane;
        if (!PlaneFromPoints(idVec3(winding[0].x, winding[0].y,
                winding[0].z), idVec3(winding[1].x, winding[1].y,
                winding[1].z), idVec3(winding[2].x, winding[2].y,
                winding[2].z), plane)) {
            continue;
        }
        const idMaterial* const material = ResolveMaterial(side->material,
            overrideMaterial);
        cm_materialBuildInfo_t info{};
        CM_GetMaterialBuildInfo(material, info);
        idFixedWinding* const outside = WindingOutsidePolytopes(model,
            &winding, plane, info.contents, primitiveNum);
        if (outside != nullptr) {
            PolygonFromWinding(model, outside, plane, material,
                primitiveNum);
        }
    }
}

void idCollisionModelBuilder::CreatePatchPolygons(
    cm_buildModel_t* const model, const idSurface_Patch* const mesh,
    const idVec3& origin, const idMat3& axis, const idVec3& scale,
    const idMaterial* const material, const int primitiveNum) {
    if (model == nullptr || mesh == nullptr) {
        return;
    }
    std::vector<int> generatedIndices;
    const int* indices = mesh->indexes.Num() > 0
        ? mesh->indexes.Ptr() : nullptr;
    int numIndices = mesh->indexes.Num();
    if (indices == nullptr && mesh->width > 1 && mesh->height > 1) {
        for (int row = 0; row < mesh->height - 1; ++row) {
            for (int column = 0; column < mesh->width - 1; ++column) {
                const int first = row * mesh->width + column;
                generatedIndices.push_back(first);
                generatedIndices.push_back(first + 1);
                generatedIndices.push_back(first + mesh->width + 1);
                generatedIndices.push_back(first);
                generatedIndices.push_back(first + mesh->width + 1);
                generatedIndices.push_back(first + mesh->width);
            }
        }
        indices = generatedIndices.data();
        numIndices = static_cast<int>(generatedIndices.size());
    }
    for (int index = 0; index + 2 < numIndices; index += 3) {
        const int i0 = indices[index + 0];
        const int i1 = indices[index + 1];
        const int i2 = indices[index + 2];
        if (i0 < 0 || i1 < 0 || i2 < 0 || i0 >= mesh->verts.Num()
            || i1 >= mesh->verts.Num() || i2 >= mesh->verts.Num()) {
            continue;
        }
        const idVec3 p0 = TransformPoint(mesh->verts[i0].xyz, origin,
            axis, scale);
        const idVec3 p1 = TransformPoint(mesh->verts[i1].xyz, origin,
            axis, scale);
        const idVec3 p2 = TransformPoint(mesh->verts[i2].xyz, origin,
            axis, scale);
        idPlane plane;
        if (!PlaneFromPoints(p0, p1, p2, plane)) {
            continue;
        }
        idFixedWinding winding;
        winding.AddPoint(p0);
        winding.AddPoint(p1);
        winding.AddPoint(p2);
        cm_materialBuildInfo_t info{};
        CM_GetMaterialBuildInfo(material, info);
        idFixedWinding* const outside = WindingOutsidePolytopes(model,
            &winding, plane, info.contents, primitiveNum);
        if (outside != nullptr) {
            PolygonFromWinding(model, outside, plane, material,
                primitiveNum);
        }
    }
}

void idCollisionModelBuilder::ConvertPatch(cm_buildModel_t* const model,
    const idMapPatch* const patch, const idVec3& origin,
    const idMat3& axis, const idVec3& scale,
    const idMaterial* const overrideMaterial, const int primitiveNum) {
    if (patch == nullptr) {
        return;
    }
    CreatePatchPolygons(model, patch, origin, axis, scale,
        ResolveMaterial(patch->material, overrideMaterial), primitiveNum);
}

void idCollisionModelBuilder::ConvertMapModelPolytopes(
    cm_buildModel_t* const model, const idStaticModelGeometry& geometry,
    const int groupNum, int primitiveNum) {
    if (model == nullptr || geometry.mapModel == nullptr) {
        return;
    }
    for (int index = 0; index < geometry.mapModel->primitives.Num();
         ++index, ++primitiveNum) {
        const idMapPrimitive* const primitive =
            geometry.mapModel->primitives[index];
        if (primitive != nullptr && primitive->type == MAP_PRIMITIVE_BRUSH
            && PrimitiveGroup(geometry, index) == groupNum) {
            ConvertBrush(model, static_cast<const idMapBrush*>(primitive),
                geometry.origin, geometry.axis, geometry.scale,
                geometry.overrideClipMaterial, primitiveNum);
        }
    }
}

void idCollisionModelBuilder::ConvertMapModelPrimitives(
    cm_buildModel_t* const model, const idStaticModelGeometry& geometry,
    const int groupNum, int primitiveNum) {
    if (model == nullptr || geometry.mapModel == nullptr) {
        return;
    }
    for (int index = 0; index < geometry.mapModel->primitives.Num();
         ++index, ++primitiveNum) {
        const idMapPrimitive* const primitive =
            geometry.mapModel->primitives[index];
        if (primitive == nullptr || PrimitiveGroup(geometry, index)
                != groupNum) {
            continue;
        }
        if (primitive->type == MAP_PRIMITIVE_PATCH) {
            ConvertPatch(model, static_cast<const idMapPatch*>(primitive),
                geometry.origin, geometry.axis, geometry.scale,
                geometry.overrideClipMaterial, primitiveNum);
        } else if (primitive->type == MAP_PRIMITIVE_BRUSH) {
            ConvertBrushSides(model,
                static_cast<const idMapBrush*>(primitive), geometry.origin,
                geometry.axis, geometry.scale,
                geometry.overrideClipMaterial, primitiveNum);
        }
    }
}

void idCollisionModelBuilder::ConvertRenderModelSurfaces(
    cm_buildModel_t* const model, const idStaticModelGeometry& geometry,
    const int groupNum, int primitiveNum) {
    cm_modelBuildSource_t source{};
    if (model == nullptr || !ExtractModel(geometry, source)) {
        return;
    }
    for (int surfaceIndex = 0; surfaceIndex < source.numSurfaces;
         ++surfaceIndex, ++primitiveNum) {
        if (PrimitiveGroup(geometry, surfaceIndex) != groupNum) {
            continue;
        }
        const cm_modelSurfaceBuildSource_t& surface =
            source.surfaces[surfaceIndex];
        if (surface.vertices == nullptr || surface.indices == nullptr) {
            continue;
        }
        cm_materialBuildInfo_t info{};
        CM_GetMaterialBuildInfo(surface.material, info);
        for (int index = 0; index + 2 < surface.numIndices; index += 3) {
            const int i0 = surface.indices[index + 0];
            const int i1 = surface.indices[index + 1];
            const int i2 = surface.indices[index + 2];
            if (i0 < 0 || i1 < 0 || i2 < 0
                || i0 >= surface.numVertices || i1 >= surface.numVertices
                || i2 >= surface.numVertices) {
                continue;
            }
            const idVec3 p0 = TransformPoint(surface.vertices[i0].xyz,
                geometry.origin, geometry.axis, geometry.scale);
            const idVec3 p1 = TransformPoint(surface.vertices[i1].xyz,
                geometry.origin, geometry.axis, geometry.scale);
            const idVec3 p2 = TransformPoint(surface.vertices[i2].xyz,
                geometry.origin, geometry.axis, geometry.scale);
            idPlane plane;
            if (!PlaneFromPoints(p0, p1, p2, plane)) {
                continue;
            }
            idFixedWinding winding;
            winding.AddPoint(p0);
            winding.AddPoint(p1);
            winding.AddPoint(p2);
            idFixedWinding* const outside = WindingOutsidePolytopes(model,
                &winding, plane, info.contents, primitiveNum);
            if (outside != nullptr) {
                PolygonFromWinding(model, outside, plane, surface.material,
                    primitiveNum);
            }
        }
    }
}

void idCollisionModelBuilder::AddCollisionModelGeometry(
    idCollisionModelLocal* const collisionModel,
    const idCollisionModelGeometry& geometry, const int groupNum) {
    if (collisionModel == nullptr) {
        return;
    }
    int numVertices = 0;
    int numEdges = 0;
    int numPolygons = 0;
    int primitiveNum = 0;
    idBounds bounds;
    bounds[0].Set(FLT_MAX, FLT_MAX, FLT_MAX);
    bounds[1].Set(-FLT_MAX, -FLT_MAX, -FLT_MAX);
    for (int index = 0; index < geometry.models.Num(); ++index) {
        const idStaticModelGeometry& modelGeometry = geometry.models[index];
        if (modelGeometry.mapModel != nullptr) {
            AddMapModelEstimates(modelGeometry, groupNum, primitiveNum,
                numVertices, numEdges, numPolygons, bounds);
            primitiveNum += modelGeometry.mapModel->primitives.Num();
        } else {
            AddRenderModelEstimates(modelGeometry, groupNum, primitiveNum,
                numVertices, numEdges, numPolygons, bounds);
            cm_modelBuildSource_t source{};
            if (ExtractModel(modelGeometry, source)) {
                primitiveNum += source.numSurfaces;
            }
        }
    }
    if (numVertices == 0 || numPolygons == 0) {
        return;
    }
    cm_buildModel_t* const buildModel = AllocBuildModel();
    buildModel->name = collisionModel->GetName();
    buildModel->isWorldModel = geometry.isWorldEntity;
    buildModel->node = AllocNode(buildModel, 8);
    buildModel->node->bounds = bounds;
    ClearHash(bounds);

    primitiveNum = 0;
    for (int index = 0; index < geometry.models.Num(); ++index) {
        const idStaticModelGeometry& modelGeometry = geometry.models[index];
        if (modelGeometry.mapModel != nullptr) {
            ConvertMapModelPolytopes(buildModel, modelGeometry, groupNum,
                primitiveNum);
            primitiveNum += modelGeometry.mapModel->primitives.Num();
        } else {
            cm_modelBuildSource_t source{};
            if (ExtractModel(modelGeometry, source)) {
                primitiveNum += source.numSurfaces;
            }
        }
    }
    if (buildModel->numPolytopes > 1) {
        CreateAxialBSPTree(buildModel);
    }
    ClearHash(bounds);
    primitiveNum = 0;
    for (int index = 0; index < geometry.models.Num(); ++index) {
        const idStaticModelGeometry& modelGeometry = geometry.models[index];
        if (modelGeometry.mapModel != nullptr) {
            ConvertMapModelPrimitives(buildModel, modelGeometry, groupNum,
                primitiveNum);
            primitiveNum += modelGeometry.mapModel->primitives.Num();
        } else {
            ConvertRenderModelSurfaces(buildModel, modelGeometry, groupNum,
                primitiveNum);
            cm_modelBuildSource_t source{};
            if (ExtractModel(modelGeometry, source)) {
                primitiveNum += source.numSurfaces;
            }
        }
    }
    CreateAxialBSPTree(buildModel);
    ++buildModel->checkCount;
    MergeTreePolygons(buildModel, buildModel->node, true);
    SplitPolygons(buildModel);
    ++buildModel->checkCount;
    FindInternalEdges(buildModel, buildModel->node);
    ++buildModel->checkCount;
    GenerateEdgeNormals_r(buildModel, buildModel->node);
    ++buildModel->checkCount;
    OffsetPolygonEdges_r(buildModel, buildModel->node);
    CreateAxialBSPTree(buildModel);
    TestBoundsRange(collisionModel->GetName(), bounds);
    AddSubModelsToCollisionModel(collisionModel, buildModel);
    FreeModelMemory(buildModel);
    delete buildModel;
}

void idCollisionModelBuilder::BuildCollisionModelForGeometry(
    idCollisionModelLocal* const model, idCollisionModelGeometry& geometry,
    const int* const subModelIndices, const int numSubModelIndices,
    const char* const optionalModelName) {
    if (model == nullptr) {
        return;
    }
    model->FreeData();
    model->SetName(optionalModelName != nullptr ? optionalModelName
                                                : geometry.modelName.c_str());
    model->modelType = CM_POLYGONMODEL;
    model->bounds[0].Set(FLT_MAX, FLT_MAX, FLT_MAX);
    model->bounds[1].Set(-FLT_MAX, -FLT_MAX, -FLT_MAX);
    model->contents = 0;
    model->sourceFileTime = geometry.fileTime;
    model->isWorldModel = geometry.isWorldEntity;
    model->isTraceModel = false;
    model->isConvex = false;
    model->isStreamed = geometry.isStreamed;
    const int numGroups = SetupBuildGroups(geometry);
    if (subModelIndices != nullptr && numSubModelIndices > 0) {
        for (int index = 0; index < numSubModelIndices; ++index) {
            AddCollisionModelGeometry(model, geometry,
                subModelIndices[index]);
        }
    } else {
        for (int group = 0; group < numGroups; ++group) {
            AddCollisionModelGeometry(model, geometry, group);
        }
    }
    MergeModelTrees(model);
}

bool idCollisionModelBuilder::BuildForRenderModel(
    idCollisionModelLocal* const model,
    const idRenderModel* const renderModel) {
    cm_modelBuildSource_t source{};
    if (model == nullptr || renderModel == nullptr
        || renderModelExtractor == nullptr
        || !renderModelExtractor(renderModel, source)) {
        return false;
    }
    idStaticModelGeometry modelGeometry;
    modelGeometry.renderModel = renderModel;
    modelGeometry.origin.Zero();
    modelGeometry.axis = idMat3(1.0f);
    modelGeometry.scale.Set(1.0f, 1.0f, 1.0f);
    idCollisionModelGeometry geometry;
    geometry.modelName = source.name != nullptr ? source.name
                                                : "_renderModel";
    geometry.fileTime = source.timeStamp;
    geometry.allowDiscrete = true;
    geometry.models.Append(modelGeometry);
    SetupHash();
    BuildCollisionModelForGeometry(model, geometry, nullptr, 0, nullptr);
    ShutdownHash();
    return model->polygonModel.numSubModels > 0;
}

bool idCollisionModelBuilder::BuildForStaticModel(
    idCollisionModelLocal* const model,
    const idStaticModel* const staticModel,
    const int* const subModelIndices, const int numSubModelIndices,
    const char* const optionalModelName) {
    cm_modelBuildSource_t source{};
    if (model == nullptr || staticModel == nullptr
        || staticModelExtractor == nullptr
        || !staticModelExtractor(staticModel, source)) {
        return false;
    }
    idStaticModelGeometry modelGeometry;
    modelGeometry.staticModel = staticModel;
    modelGeometry.origin.Zero();
    modelGeometry.axis = idMat3(1.0f);
    modelGeometry.scale.Set(1.0f, 1.0f, 1.0f);
    idCollisionModelGeometry geometry;
    geometry.modelName = source.name != nullptr ? source.name
                                                : "_staticModel";
    geometry.fileTime = source.timeStamp;
    geometry.allowDiscrete = true;
    geometry.models.Append(modelGeometry);
    SetupHash();
    BuildCollisionModelForGeometry(model, geometry, subModelIndices,
        numSubModelIndices, optionalModelName);
    ShutdownHash();
    return model->polygonModel.numSubModels > 0;
}

void idCollisionModelBuilder::BuildForMapFile(
    const idMapFile* const mapFile, const bool inlineStatic,
    const bool mapModelOnly) {
    if (mapFileBuildCallback != nullptr) {
        mapFileBuildCallback(mapFile, inlineStatic, mapModelOnly);
        return;
    }
    if (mapFile == nullptr) {
        return;
    }
    (void)inlineStatic;
    (void)mapModelOnly;
    SetupHash();
    for (int entityIndex = 0; entityIndex < mapFile->entities.Num();
         ++entityIndex) {
        const idMapEntity* const entity = mapFile->entities[entityIndex];
        if (entity == nullptr || entity->model.primitives.Num() == 0) {
            continue;
        }
        idStaticModelGeometry modelGeometry;
        modelGeometry.mapModel = &entity->model;
        modelGeometry.origin.Zero();
        modelGeometry.axis = idMat3(1.0f);
        modelGeometry.scale.Set(1.0f, 1.0f, 1.0f);
        idCollisionModelGeometry geometry;
        if (entityIndex == 0) {
            geometry.modelName = mapFile->name;
            geometry.isWorldEntity = true;
        } else if (entity->model.name.Length() > 0) {
            geometry.modelName = entity->model.name;
        } else {
            char generatedName[64];
            _snprintf_s(generatedName, sizeof(generatedName), _TRUNCATE,
                "%s_entity_%d", mapFile->name.c_str(), entityIndex);
            geometry.modelName = generatedName;
        }
        geometry.fileTime = mapFile->fileTime;
        geometry.models.Append(modelGeometry);
        idCollisionModelLocal* const collisionModel =
            new idCollisionModelLocal();
        BuildCollisionModelForGeometry(collisionModel, geometry, nullptr,
            0, nullptr);
        if (collisionModel->polygonModel.numSubModels == 0) {
            delete collisionModel;
            continue;
        }
        idCollisionModelLocal::resourceList.Add(collisionModel);
        collisionModel->Write_Binary();
    }
    ShutdownHash();
}

void idCollisionModelBuilder::CreateStreamAreas(
    idCollisionModelLocal* const model,
    const idList<idCollisionModelGeometry, TAG_IDLIB>& geometries) {
    if (model == nullptr) {
        return;
    }
    int numAreas = 0;
    int nameBytes = 0;
    for (int index = 0; index < geometries.Num(); ++index) {
        if (geometries[index].isStreamArea) {
            ++numAreas;
            nameBytes += geometries[index].modelName.Length() + 1;
        }
    }
    if (numAreas == 0) {
        return;
    }
    const int numAreaSubModels = numAreas
        * model->polygonModel.numSubModels;
    const int totalSize = sizeof(streamAreasHeader_t)
        + numAreas * sizeof(streamArea_t)
        + numAreaSubModels * sizeof(std::uint16_t) + nameBytes;
    streamAreasHeader_t* const header =
        static_cast<streamAreasHeader_t*>(_aligned_malloc(totalSize, 16));
    if (header == nullptr) {
        return;
    }
    std::memset(header, 0, totalSize);
    header->totalSize = totalSize;
    header->numStreamAreas = numAreas;
    header->numStreamAreaSubModels = numAreaSubModels;
    header->numStreamAreaNameBytes = nameBytes;
    streamAreasPtrs_t pointers{};
    SetupStreamAreaPtrs(header, pointers);
    int areaIndex = 0;
    int subModelOffset = 0;
    int nameOffset = 0;
    for (int index = 0; index < geometries.Num(); ++index) {
        const idCollisionModelGeometry& geometry = geometries[index];
        if (!geometry.isStreamArea) {
            continue;
        }
        streamArea_t& area = pointers.streamAreas[areaIndex++];
        area.volumeNameOffset = nameOffset;
        area.volumeOrigin = geometry.streamVolumeOrigin;
        area.volumeAxis = geometry.streamVolumeAxis;
        area.numSubModels = model->polygonModel.numSubModels;
        area.subModelsOffset = subModelOffset;
        for (int subModel = 0;
             subModel < model->polygonModel.numSubModels; ++subModel) {
            pointers.streamAreaSubModels[subModelOffset++] =
                static_cast<std::uint16_t>(subModel);
        }
        const int length = geometry.modelName.Length() + 1;
        std::memcpy(pointers.streamAreaNameBytes + nameOffset,
            geometry.modelName.c_str(), length);
        nameOffset += length;
    }
    _aligned_free(model->streamAreas);
    model->streamAreas = header;
}
