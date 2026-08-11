#include "game/entities/cuttable.h"

#include "cm/collisiongrid.h"
#include "idlib/filesystem/file.h"
#include "idlib/geometry/tracemodel.h"
#include "models/cuttable/convexhull.h"
#include "models/cuttable/cutterclip.h"
#include "models/cuttable/earcliptriangulate.h"
#include "models/cuttable/rendermodelcuttablebeams.h"
#include "models/cuttable/rendermodelcuttableresource.h"
#include "models/cuttable/rendermodelcuttablesurface.h"

#include <algorithm>

namespace {
idCuttableServices defaultCuttableServices;
idCuttableServices* cuttableServices = &defaultCuttableServices;

idStr MakeAssetName(const idStr& worldName, const idStr& entityName,
        const char* extension) {
    idStr result(worldName);
    if (!result.IsEmpty()) {
        result.Append("/");
    }
    result.Append(entityName.c_str());
    result.SetFileExtension(extension);
    return result;
}

void AppendContourPoints(const Contour* contour,
        idList<idVec2i, 5>& points) {
    points.Clear();
    if (contour == nullptr) {
        return;
    }
    for (const ContourEdge_t* edge = contour->edges; edge != nullptr;
            edge = edge->next) {
        for (const ContourNode_t* node = edge->node; node != nullptr;
                node = node->next) {
            if (points.Num() == 0 || points[points.Num() - 1].x != node->pos.x
                    || points[points.Num() - 1].y != node->pos.y) {
                points.Append(node->pos);
            }
        }
    }
    if (points.Num() > 1
            && points[0].x == points[points.Num() - 1].x
            && points[0].y == points[points.Num() - 1].y) {
        points.SetNum(points.Num() - 1);
    }
}

void FreeContourChain(idCutterGraphManager& manager, Contour* contour) {
    while (contour != nullptr) {
        Contour* const next = contour->next;
        manager.FreeContour(contour);
        contour = next;
    }
}
}

idPresentable* idCuttableServices::AllocPresentable(
        idCuttable&, idRenderModel*) { return nullptr; }
void idCuttableServices::RegisterCuttable(idCuttable&) {}
void idCuttableServices::UnregisterCuttable(idCuttable&) {}
void idCuttableServices::ClearCuttable(int) {}
idCutterGraphManager* idCuttableServices::GetGraphManager() { return nullptr; }
idCutterClip* idCuttableServices::GetClipHelper() { return nullptr; }
bool idCuttableServices::ShouldSaveCuttableState() const { return true; }
idStr idCuttableServices::GetRenderWorldName() const { return idStr(); }
idRenderModelCuttableSurface* idCuttableServices::LoadCuttableSurface(
        const idStr&) { return nullptr; }
bool idCuttableServices::SurfaceHasGeometry(
        const idRenderModelCuttableSurface* const model) const {
    return model != nullptr && model->surfaces.Num() != 0;
}
idCollisionGrid* idCuttableServices::LoadCollisionGrid(const idStr&) {
    return nullptr;
}
bool idCuttableServices::CollisionGridIsValid(
        const idCollisionGrid* const grid) const {
    return grid != nullptr && grid->IsValid();
}
void idCuttableServices::ReleaseCollisionGrid(idCollisionGrid*) {}
idPhysics* idCuttableServices::CreatePhysics(idCuttable&) { return nullptr; }
void idCuttableServices::AttachModelAndPhysics(idCuttable&) {}
int idCuttableServices::AllocateCuttableInfo(const idStr&,
        idRenderModelCuttableSurface*, idPhysics*) { return -1; }
idRenderModelCuttableBeams* idCuttableServices::CreateBeamModel(
        idCuttable&) { return nullptr; }
void idCuttableServices::ConfigureBeamModel(idCuttable&) {}
void idCuttableServices::SetAllClipTransforms(
        idCuttable&, const idVec3&, const idMat3&) {}
void idCuttableServices::UpdateVisuals(idCuttable&) {}
void idCuttableServices::SetThinkActive(idCuttable&, bool) {}
void idCuttableServices::SetHidden(idCuttable&, bool) {}
void idCuttableServices::DetachClipModels(idCuttable&) {}
bool idCuttableServices::RebuildClipModels(idCuttable&,
        const idList<idCuttableContourPoints, 5>&) { return false; }
void idCuttableServices::ReleaseRuntimeResources(idCuttable&) {}
void idCuttableServices::GetTransform(const idCuttable& cuttable,
        idVec3& origin, idMat3& axis) const {
    origin = cuttable.spawnPosition;
    axis = cuttable.spawnOrientation;
}
bool idCuttableServices::DebugCuttable() const { return false; }
int idCuttableServices::GetGameMillisecondsPerFrame() const { return 16; }
void idCuttableServices::DebugDrawGraph(
        idCutterGraphManager&, int, int) {}
void idCuttableServices::UpdateBeamModel(idCuttable&,
        idCutterGraphManager&, int, const idVec3&, const idMat3&) {}
void idCuttableServices::RunPhysics(idCuttable&) {}
void idCuttableServices::UpdateEffects(idCuttable&) {}
int idCuttableServices::GetGameMilliseconds() const { return 0; }
int idCuttableServices::GetEntityNumber(
        const idCuttable& cuttable) const { return cuttable.entityNumber; }
bool idCuttableServices::EmitCutPiece(const cuttablePhysicsEmitInfo_t&,
        const idList<idDrawVert, 5>&, const idList<idVec2, 5>&,
        const idList<unsigned short, 5>&) { return false; }
void idCuttableServices::UpdateCuttableModel(
        int, Contour*, Contour*) {}
void idCuttableServices::InvalidateCuttableModel(idCuttable&) {}
void idCuttableServices::Warning(const char*) {}
int idCuttableServices::GetDamageTypes(const idDeclDamage*) const { return 0; }
bool idCuttableServices::GetDamageCutPoint(
        const trace_t*, idVec3&) const { return false; }

void idCuttable::SetServices(idCuttableServices* const services) {
    cuttableServices = services != nullptr ? services
        : &defaultCuttableServices;
}

idCuttableServices& idCuttable::Services() {
    return *cuttableServices;
}

// Retail: 0x82C18548 ?AllocPresentable@idCuttable@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
idPresentable* idCuttable::AllocPresentable(idRenderModel* const renderModel) {
    return Services().AllocPresentable(*this, renderModel);
}

// Retail: 0x82C185D8 ?CreateStateInfo@idCuttable@@QBAXAAUcuttableStateInfo_t@@@Z
void idCuttable::CreateStateInfo(cuttableStateInfo_t& state) const {
    state.name = name;
    state.graphValid = graphHandle >= 0;
}

// Retail: 0x82C18628 ?GetPolygon@idCuttable@@QAA_NAAV?$idList@VidVec2i@@$04@@PAVidCutterClip@@@Z
bool idCuttable::GetPolygon(idList<idVec2i, 5>& points,
        idCutterClip* const cutterClip) {
    if (cutterClip == nullptr) {
        points.Clear();
        return false;
    }
    const int polygonCount = cutterClip->GetNumPolygons();
    while (nestedPolygons < polygonCount) {
        cutterClip->GetPolygon(nestedPolygons++, points);
        if (points.Num() > 0) {
            return true;
        }
    }
    const int connectedCount = cutterClip->GetConnectedPolygons();
    while (connectedPolygons < connectedCount) {
        cutterClip->GetConnectedPolygon(connectedPolygons++, points);
        if (points.Num() > 0) {
            return true;
        }
    }
    points.Clear();
    return false;
}

// Retail: 0x82C186F8 ??0idCuttable@@QAA@XZ
idCuttable::idCuttable()
    : name(), spawnPosition(0.0f, 0.0f, 0.0f), spawnOrientation(1.0f),
      thinkFlags(0), entityNumber(-1), physicsObj(nullptr),
      cuttableNode(this), collisionGrid(nullptr), cutModel(nullptr),
      beamModel(nullptr), clipModel(nullptr), gridClipModel(nullptr),
      collisionModel(nullptr), gridCollisionModel(nullptr), graphHandle(-1),
      infoHandle(-1), impactTable(nullptr), nestedPolygons(0),
      connectedPolygons(0) {
    Services().RegisterCuttable(*this);
}

// Retail: 0x82C187E8 ??1idCuttable@@UAA@XZ
idCuttable::~idCuttable() {
    if (infoHandle >= 0) {
        Services().ClearCuttable(infoHandle);
        infoHandle = -1;
    }
    idCutterGraphManager* const manager = Services().GetGraphManager();
    if (graphHandle >= 0 && manager != nullptr) {
        manager->FreeGraph(graphHandle);
        graphHandle = -1;
    }
    cuttableNode.Remove();
    Services().UnregisterCuttable(*this);
    Services().ReleaseRuntimeResources(*this);
    physicsObj = nullptr;
    collisionGrid = nullptr;
    cutModel = nullptr;
    beamModel = nullptr;
    clipModel = nullptr;
    gridClipModel = nullptr;
    collisionModel = nullptr;
    gridCollisionModel = nullptr;
}

// Retail: 0x82C18A40 ?WriteLevelStateToFile@idCuttable@@SAXPAVidFile@@AAV?$idList@UcuttableStateInfo_t@@$04@@AAVidCutterGraphState@@@Z
void idCuttable::WriteLevelStateToFile(idFile* const file,
        idList<cuttableStateInfo_t, 5>& stateInfo,
        idCutterGraphState& graphState) {
    if (file == nullptr) {
        return;
    }
    const bool saveState = Services().ShouldSaveCuttableState();
    const unsigned char stored = saveState ? 1 : 0;
    file->Write(&stored, 1);
    if (!saveState) {
        return;
    }
    const int graphCount = graphState.graphHandles.Num();
    file->WriteLittle(graphCount);
    for (int index = 0; index < graphCount; ++index) {
        idCutterGraphManager::Write(graphState.manager, file,
            graphState.graphHandles[index]);
    }
    const int stateCount = stateInfo.Num();
    file->WriteLittle(stateCount);
    for (int index = 0; index < stateCount; ++index) {
        file->WriteString(stateInfo[index].name);
        const unsigned char valid = stateInfo[index].graphValid ? 1 : 0;
        file->Write(&valid, 1);
    }
}

// Retail: 0x82C18E68 ?BuildClipModel@idCuttable@@AAAXXZ
void idCuttable::BuildClipModel() {
    idCutterGraphManager* const manager = Services().GetGraphManager();
    if (graphHandle < 0 || manager == nullptr || cutModel == nullptr) {
        Services().DetachClipModels(*this);
        clipModel = nullptr;
        gridClipModel = nullptr;
        return;
    }

    idList<idCuttableContourPoints, 5> inactiveFills;
    if (collisionGrid != nullptr) {
        for (Contour* contour = manager->GetInnerContour(graphHandle);
                contour != nullptr; contour = contour->next) {
            idCuttableContourPoints fill;
            AppendContourPoints(contour, fill.points);
            if (fill.points.Num() > 0) {
                inactiveFills.Append(fill);
            }
        }
    }
    Services().DetachClipModels(*this);
    Services().RebuildClipModels(*this, inactiveFills);
}

// Retail: 0x82C19660 ?Spawn@idCuttable@@QAAXXZ
void idCuttable::Spawn() {
    const idStr worldName = Services().GetRenderWorldName();
    const idStr surfaceName = MakeAssetName(worldName, name, "csurf");
    cutModel = Services().LoadCuttableSurface(surfaceName);
    if (!Services().SurfaceHasGeometry(cutModel)) {
        Services().SetHidden(*this, true);
        Services().DetachClipModels(*this);
        return;
    }

    const idStr gridName = MakeAssetName(worldName, name, "cgrid");
    collisionGrid = Services().LoadCollisionGrid(gridName);
    if (collisionGrid != nullptr
            && !Services().CollisionGridIsValid(collisionGrid)) {
        Services().ReleaseCollisionGrid(collisionGrid);
        collisionGrid = nullptr;
    }

    physicsObj = Services().CreatePhysics(*this);
    Services().AttachModelAndPhysics(*this);
    infoHandle = Services().AllocateCuttableInfo(name, cutModel, physicsObj);

    idCutterGraphManager* const manager = Services().GetGraphManager();
    if (manager != nullptr && cutModel->triangleInterpolator != nullptr
            && cutModel->modelResource != nullptr) {
        graphHandle = manager->AllocateGraph(name, spawnPosition,
            spawnOrientation, cutModel->triangleInterpolator->refNormal,
            cutModel->modelResource->contourBound);
    }
    BuildClipModel();
    Services().SetAllClipTransforms(*this, spawnPosition, spawnOrientation);

    beamModel = Services().CreateBeamModel(*this);
    if (beamModel != nullptr) {
        Services().ConfigureBeamModel(*this);
    }
    Services().UpdateVisuals(*this);
    Services().SetThinkActive(*this, true);
    thinkFlags |= 1;
}

// Retail: 0x82C19C78 ?Think@idCuttable@@UAAXXZ
void idCuttable::Think() {
    if ((thinkFlags & 1) != 0) {
        if (graphHandle >= 0) {
            if (clipModel == nullptr) {
                BuildClipModel();
            }
            idCutterGraphManager* const manager = Services().GetGraphManager();
            if (manager != nullptr) {
                idVec3 origin;
                idMat3 axis;
                Services().GetTransform(*this, origin, axis);
                manager->SetPosition(graphHandle, origin, axis);
                if (Services().DebugCuttable()) {
                    Services().DebugDrawGraph(*manager, graphHandle,
                        Services().GetGameMillisecondsPerFrame());
                }
                if (beamModel != nullptr) {
                    Services().UpdateBeamModel(*this, *manager,
                        graphHandle, origin, axis);
                }
            }
        } else {
            thinkFlags &= ~1;
            Services().SetThinkActive(*this, false);
        }
    }
    Services().RunPhysics(*this);
    Services().UpdateEffects(*this);
}

// Retail: 0x82C19E50 ?ApplyStateInfo@idCuttable@@QAAXABUcuttableStateInfo_t@@@Z
void idCuttable::ApplyStateInfo(const cuttableStateInfo_t& state) {
    if (!state.graphValid) {
        graphHandle = -1;
    }
    BuildClipModel();
}

// Retail: 0x82C19E70 ?PushCut@idCuttable@@AAAXVidVec3@@ABV2@@Z
void idCuttable::PushCut(const idVec3 point, const idVec3& direction) {
    idCutterGraphManager* const manager = Services().GetGraphManager();
    idCutterClip* const clipper = Services().GetClipHelper();
    if (graphHandle < 0 || manager == nullptr || clipper == nullptr) {
        return;
    }

    manager->Acquire(graphHandle);
    const idVec2i localPoint = manager->GetLocal2D(point);
    if (!manager->BuildEdge(localPoint)) {
        return;
    }

    idList<idVec2i, 5> pathPoints;
    if (!manager->PathFind(pathPoints)) {
        return;
    }

    Contour* pathContour = manager->CreateContour(pathPoints);
    if (pathContour == nullptr) {
        return;
    }
    Contour* const intersectedContours =
        manager->IntersectContours(pathContour);
    Contour* emittedContours = nullptr;
    bool contourAdded = false;

    if (intersectedContours != nullptr) {
        clipper->Prepare();
        clipper->PreAllocate();
        clipper->AddContour(pathContour, POLYTYPE_SUBJECT);
        clipper->AddContour(intersectedContours, POLYTYPE_CLIP);
        clipper->Clip(CLIPMODE_UNION, FILLTYPE_NON_ZERO);
        nestedPolygons = 0;
        connectedPolygons = 0;
        idList<idVec2i, 5> polygon;
        while (GetPolygon(polygon, clipper)) {
            Contour* const created = manager->CreateContour(polygon);
            if (created != nullptr) {
                created->next = emittedContours;
                emittedContours = created;
            }
        }
        pathContour->next = intersectedContours;
        if (emittedContours != nullptr) {
            clipper->Prepare();
            clipper->AddContour(emittedContours, POLYTYPE_SUBJECT);
            clipper->AddContour(intersectedContours, POLYTYPE_CLIP);
            clipper->Clip(CLIPMODE_DIFFERENCE, FILLTYPE_NON_ZERO);
        }
        manager->MergeContours(pathContour);
        contourAdded = manager->AddContour(emittedContours, pathContour);
        FreeContourChain(*manager, pathContour);
        pathContour = nullptr;
    } else {
        contourAdded = manager->AddContour(pathContour, pathContour);
    }

    idEarClipTriangulate triangulator;
    idConvexHull convexHull;
    int outerHullCount = 0;
    bool pieceGeometryValid = false;

    if (emittedContours != nullptr) {
        const int polygonCount = clipper->GetNumPolygons();
        idList<idVec2i, 5> polygon;
        for (int polygonIndex = 0; polygonIndex < polygonCount;
                ++polygonIndex) {
            clipper->GetPolygon(polygonIndex, polygon);
            if (polygon.Num() == 0) {
                continue;
            }
            ++outerHullCount;
            if (outerHullCount == 1) {
                triangulator.SetOuterFromPoints(polygon);
                convexHull.Create(polygon, 2.0f);
                while (clipper->currentInnerPolygon != nullptr) {
                    clipper->GetInnerPolygon(polygon);
                    if (polygon.Num() > 0) {
                        triangulator.AddInnerFromPoints(polygon);
                    }
                }
            }
        }
        if (outerHullCount > 1) {
            Services().Warning(
                "Discarding cut piece because of multiple outer hulls");
        } else if (outerHullCount == 0) {
            Services().Warning(
                "Discarding cut piece because of no outer hull");
        } else {
            pieceGeometryValid = true;
        }
    } else if (pathContour != nullptr) {
        idList<idVec2i, 5> polygon;
        AppendContourPoints(pathContour, polygon);
        if (polygon.Num() > 0) {
            triangulator.SetOuterFromPoints(polygon);
            convexHull.Create(polygon, 2.0f);
            pieceGeometryValid = true;
        } else {
            Services().Warning(
                "Discarding cut physics piece because no outer contour was generated");
        }
    }

    if (pieceGeometryValid && cutModel != nullptr
            && cutModel->triangleInterpolator != nullptr) {
        const idVec3 normal = cutModel->triangleInterpolator->refNormal;
        idList<idVec3, 5> collisionVertices;
        for (int index = 0; index < convexHull.vertices.Num(); ++index) {
            collisionVertices.Append(
                manager->GetLocal3D(convexHull.vertices[index]) + normal);
        }

        idTraceModel traceModel;
        if (collisionVertices.Num() >= 3) {
            traceModel.SetupPolygonVolume(collisionVertices.Ptr(),
                collisionVertices.Num(), -normal * 2.0f);
        }

        triangulator.Triangulate();
        idList<idVec2, 5> positions;
        idList<unsigned short, 5> indices;
        triangulator.BuildGeometry(normal, positions, indices);
        if (positions.Num() <= 64 && indices.Num() <= 192
                && collisionVertices.Num() >= 3) {
            idList<idDrawVert, 5> vertices;
            idList<idVec2, 5> textureCoordinates;
            vertices.PreAllocate(positions.Num() * 2);
            textureCoordinates.PreAllocate(positions.Num() * 2);
            for (int index = 0; index < positions.Num(); ++index) {
                idDrawVert vertex = {};
                idVec2 texture;
                cutModel->triangleInterpolator->Interpolate(
                    positions[index], vertex, texture);
                vertices.Append(vertex);
                textureCoordinates.Append(texture);
            }

            const int frontVertexCount = vertices.Num();
            for (int index = 0; index < frontVertexCount; ++index) {
                idDrawVert back = vertices[index];
                back.SetNormal(-vertices[index].GetNormal());
                back.SetTangent(-vertices[index].GetTangent());
                back.SetBiTangent(-vertices[index].GetBiTangent());
                vertices.Append(back);
                textureCoordinates.Append(textureCoordinates[index]);
            }
            const int frontIndexCount = indices.Num();
            for (int index = 0; index + 2 < frontIndexCount; index += 3) {
                indices.Append(static_cast<unsigned short>(
                    indices[index] + frontVertexCount));
                indices.Append(static_cast<unsigned short>(
                    indices[index + 2] + frontVertexCount));
                indices.Append(static_cast<unsigned short>(
                    indices[index + 1] + frontVertexCount));
            }

            cuttablePhysicsEmitInfo_t emitInfo = {};
            if (cutModel->surfaces.Num() > 1) {
                emitInfo.depthMaterial = cutModel->surfaces[0].material;
                emitInfo.renderMaterial = cutModel->surfaces[1].material;
            } else if (cutModel->surfaces.Num() == 1) {
                emitInfo.renderMaterial = cutModel->surfaces[0].material;
            }
            emitInfo.soundTable = impactTable;
            emitInfo.traceModel = &traceModel;
            Services().GetTransform(*this, emitInfo.position,
                emitInfo.orientation);
            emitInfo.impulsePoint = point;
            emitInfo.impulse = -direction * 25.0f;
            emitInfo.emitTime = Services().GetGameMilliseconds();
            emitInfo.entityNum = Services().GetEntityNumber(*this);
            emitInfo.minBounceVelocitySqr = 3025.0f;
            Services().EmitCutPiece(emitInfo, vertices,
                textureCoordinates, indices);
        } else {
            Services().Warning(
                "Discarding cut physics piece due to excess vertices or indices");
        }
    }

    Contour* const outer = manager->GetOuterContour(graphHandle);
    Contour* const inner = manager->GetInnerContour(graphHandle);
    if (outer != nullptr && contourAdded) {
        Services().UpdateCuttableModel(infoHandle, outer, inner);
        BuildClipModel();
    } else {
        manager->ReleaseGraph(graphHandle);
        manager->FreeGraph(graphHandle);
        graphHandle = -1;
        Services().InvalidateCuttableModel(*this);
        Services().DetachClipModels(*this);
    }
}

// Retail: 0x82C1B310 ?Damage@idCuttable@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
float idCuttable::Damage(idEntity*, idEntity*,
        const idDeclDamage* const damageDef, float,
        const idVec3& direction, trace_t* const trace) {
    constexpr int DAMAGE_TYPE_CUTTABLE = 0x4000;
    if (damageDef != nullptr && graphHandle >= 0
            && (Services().GetDamageTypes(damageDef)
                & DAMAGE_TYPE_CUTTABLE) != 0) {
        idVec3 cutPoint;
        if (Services().GetDamageCutPoint(trace, cutPoint)) {
            idVec3 normalizedDirection = direction;
            normalizedDirection.NormalizeFast();
            PushCut(cutPoint, normalizedDirection);
        }
    }
    return 0.0f;
}

// Retail: 0x82C1B3B8 ?ReadLevelStateFromFile@idCuttable@@SAXPAVidFile@@AAV?$idList@UcuttableStateInfo_t@@$04@@AAVidCutterGraphState@@@Z
void idCuttable::ReadLevelStateFromFile(idFile* const file,
        idList<cuttableStateInfo_t, 5>& stateInfo,
        idCutterGraphState& graphState) {
    if (file == nullptr) {
        return;
    }
    unsigned char stored = 1;
    if (file->Read(&stored, 1) != 1 || stored == 0) {
        return;
    }

    int graphCount = 0;
    if (file->ReadLittle(graphCount) != sizeof(graphCount)
            || graphCount < 0) {
        return;
    }
    idCutterGraphManager discardedGraphs;
    idCutterGraphManager* const targetManager =
        Services().ShouldSaveCuttableState() && graphState.manager != nullptr
        ? graphState.manager : &discardedGraphs;
    for (int index = 0; index < graphCount; ++index) {
        idCutterGraphManager::Read(targetManager, file);
    }

    int stateCount = 0;
    if (file->ReadLittle(stateCount) != sizeof(stateCount)
            || stateCount < 0 || !stateInfo.SetNum(stateCount)) {
        stateInfo.Clear();
        return;
    }
    for (int index = 0; index < stateCount; ++index) {
        if (file->ReadString(stateInfo[index].name) < sizeof(int)) {
            stateInfo.SetNum(index);
            return;
        }
        unsigned char valid = 0;
        if (file->Read(&valid, 1) != 1) {
            stateInfo.SetNum(index);
            return;
        }
        stateInfo[index].graphValid = valid != 0;
    }
}
