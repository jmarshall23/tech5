#include "cm/collisionmodelmanager.h"

#include "cm/collisiongrid.h"
#include "cm/collisionmodel.h"
#include "cm/collisionmodelbuilder.h"
#include "cm/jobs/polygonmodel/polygonmodel.h"
#include "cm/jobs/polygonmodel/polygonmodeldata.h"

#include "idlib/sys/sys_alloc.h"
#include "idlib/filesystem/file.h"
#include "idlib/filesystem/filesystem.h"
#include "idlib/geometry/tracemodel.h"
#include "idlib/lib_print.h"
#include "idlib/text/cmdargs.h"
#include "framework/resourcelist.h"

#include <algorithm>
#include <cfloat>
#include <cstdlib>
#include <cstring>
#include <vector>

idCollisionModelManager collisionModelManager;

namespace {

idCollisionQueryJobManager cdQuery;
idTraceWork* baseTraceWork = nullptr;

void EnsureQueryManager() {
    if (cdQuery.queryData == nullptr) {
        cdQuery.Init();
    }
    if (baseTraceWork == nullptr) {
        baseTraceWork = idPolygonModelCollisionDetection::AllocTraceWork();
    }
}

} // namespace

idCollisionGridState::idCollisionGridState()
    : material(nullptr), numActive(0), firstActive(-1),
      active(TAG_BITARRAY) {
}

void idCollisionGridState::Create(const int num,
    const idMaterial* const material_) {
    active.Alloc(static_cast<unsigned int>(num));
    for (int index = 0; index < num; ++index) {
        active.Set(static_cast<unsigned int>(index));
    }
    numActive = num;
    material = material_;
    firstActive = num > 0 ? 0 : -1;
}

void idCollisionGridState::Activate(const unsigned int id) {
    if (active.Get(id)) {
        return;
    }
    if (firstActive < 0 || static_cast<int>(id) < firstActive) {
        firstActive = static_cast<int>(id);
    }
    active.Set(id);
    ++numActive;
}

int idCollisionGridState::NextActive(const int id) const {
    for (unsigned int candidate = static_cast<unsigned int>(id + 1);
         candidate < active.Num(); ++candidate) {
        if (active.Get(candidate)) {
            return static_cast<int>(candidate);
        }
    }
    return -1;
}

void idCollisionGridState::Inactivate(const unsigned int id) {
    if (!active.Get(id)) {
        return;
    }
    active.Clear(id);
    --numActive;
    if (numActive == 0) {
        firstActive = -1;
    } else if (firstActive == static_cast<int>(id)) {
        firstActive = NextActive(static_cast<int>(id));
    }
}

int idCollisionGridState::FirstActive() const {
    return numActive > 0 ? firstActive : -1;
}

idCollisionModel* idCollisionModelManager::ModelFromTrm(
    const char* const modelName, const idTraceModel& traceModel,
    const idMaterial* const material) {
    idCollisionModelLocal* const model = new idCollisionModelLocal();
    if (model == nullptr) {
        return nullptr;
    }
    if (!idCollisionModelBuilder::BuildForTrm(
            model, modelName, traceModel, material)) {
        delete model;
        return nullptr;
    }
    return model;
}

idCollisionModel* idCollisionModelManager::BuildModel(
    const char* const modelName, const idStaticModel* const staticModel,
    const int* const subModelIndices, const int numSubModelIndices) {
    if (staticModel == nullptr) {
        return nullptr;
    }
    idCollisionModelLocal* const model = new idCollisionModelLocal();
    if (model == nullptr || !idCollisionModelBuilder::BuildForStaticModel(
            model, staticModel, subModelIndices, numSubModelIndices,
            modelName)) {
        delete model;
        return nullptr;
    }
    idCollisionModelLocal::resourceList.Add(model);
    return model;
}

void idCollisionModelManager::BuildModelsForMapFile(
    const idMapFile* const mapFile, const bool mapModelOnly) {
    idCollisionModelBuilder::BuildForMapFile(mapFile, true,
        mapModelOnly);
}

idCollisionModel* idCollisionModelManager::ModelFromRender(
    const char*, const idRenderModel* const renderModel) {
    if (renderModel == nullptr) {
        return nullptr;
    }
    idCollisionModelLocal* const model = new idCollisionModelLocal();
    if (model == nullptr
        || !idCollisionModelBuilder::BuildForRenderModel(model,
            renderModel)) {
        delete model;
        return nullptr;
    }
    return model;
}

idCollisionModel* idCollisionModelManager::ModelFromGrid(
    const char* const modelName, const idCollisionGrid* const grid,
    const idCollisionGridState& state, const idMaterial* const material) {
    const idCollisionGridLocal* const localGrid =
        dynamic_cast<const idCollisionGridLocal*>(grid);
    if (localGrid == nullptr) {
        return nullptr;
    }
    idCollisionModelLocal* const model = new idCollisionModelLocal();
    if (!idCollisionModelBuilder::BuildForGrid(model, modelName,
            localGrid->grid, state, material)) {
        delete model;
        return nullptr;
    }
    return model;
}

void idCollisionModelManager::Init() {
    EnsureQueryManager();
}

void idCollisionModelManager::Shutdown() {
    if (baseTraceWork != nullptr) {
        baseTraceWork->~idTraceWork();
        mem.Free(baseTraceWork, ALIGN_16);
        baseTraceWork = nullptr;
    }
    cdQuery.Shutdown();
}

void idCollisionModelManager::StartQueryFrame() {
    EnsureQueryManager();
    cdQuery.StartFrame();
}

void idCollisionModelManager::EndQueryFrame() {
    EnsureQueryManager();
    cdQuery.EndFrame();
}

void idCollisionModelManager::SubmitQueries() {
    EnsureQueryManager();
    cdQuery.SubmitQueries();
}

void idCollisionModelManager::WaitForAllQueries() {
    EnsureQueryManager();
    cdQuery.WaitForAllQueries();
}

idCollisionModel* idCollisionModelManager::LoadModel(
    const char* const modelName) {
    if (modelName == nullptr || *modelName == '\0') {
        return nullptr;
    }
    idCollisionModelLocal* const model = new idCollisionModelLocal();
    model->SetName(modelName);
    model->LoadResource();
    return model;
}

idCollisionGrid* idCollisionModelManager::LoadGrid(
    const char* const modelName) {
    if (modelName == nullptr || *modelName == '\0') {
        return nullptr;
    }
    idCollisionGridLocal* const grid = new idCollisionGridLocal();
    grid->SetName(modelName);
    grid->LoadResource();
    return grid;
}

int idCollisionModelManager::FindStreamArea(idCollisionModel* const model,
    const char* const areaName) {
    idCollisionModelLocal* const local =
        dynamic_cast<idCollisionModelLocal*>(model);
    if (local == nullptr || local->streamAreas == nullptr
        || areaName == nullptr) {
        return -1;
    }
    streamAreasPtrs_t pointers{};
    SetupStreamAreaPtrs(local->streamAreas, pointers);
    for (int index = 0; index < local->streamAreas->numStreamAreas;
         ++index) {
        const char* const name = pointers.streamAreaNameBytes
            + pointers.streamAreas[index].volumeNameOffset;
        if (_stricmp(name, areaName) == 0) {
            return index;
        }
    }
    return -1;
}

void idCollisionModelManager::StreamModel(idCollisionModel* const model,
    const int* const areaIndices, const int numAreaIndices,
    const bool wait) {
    idCollisionModelLocal* const local =
        dynamic_cast<idCollisionModelLocal*>(model);
    if (local == nullptr || !local->isStreamed
        || local->streamAreas == nullptr
        || (numAreaIndices != -1
            && (numAreaIndices < 0
                || (numAreaIndices > 0 && areaIndices == nullptr)))) {
        return;
    }

    // The recovered interface describes the complete desired-area set.  The
    // final flag only controls whether the Xenon implementation waits for its
    // asynchronous I/O passes; the PC port performs those reads synchronously.
    (void)wait;
    std::vector<bool> desired(
        static_cast<std::size_t>(local->polygonModel.numSubModels), false);
    streamAreasPtrs_t areas{};
    SetupStreamAreaPtrs(local->streamAreas, areas);
    if (numAreaIndices == -1) {
        std::fill(desired.begin(), desired.end(), true);
    } else {
        for (int areaListIndex = 0; areaListIndex < numAreaIndices;
             ++areaListIndex) {
            const int areaIndex = areaIndices[areaListIndex];
            if (areaIndex < 0
                || areaIndex >= local->streamAreas->numStreamAreas) {
                continue;
            }
            const streamArea_t& area = areas.streamAreas[areaIndex];
            for (int index = 0; index < area.numSubModels; ++index) {
                const int subModelIndex = areas.streamAreaSubModels[
                    area.subModelsOffset + index];
                if (subModelIndex >= 0
                    && subModelIndex < local->polygonModel.numSubModels) {
                    desired[static_cast<std::size_t>(subModelIndex)] = true;
                }
            }
        }
    }

    for (int subModelIndex = 0;
         subModelIndex < local->polygonModel.numSubModels;
         ++subModelIndex) {
        cm_subModel_t& subModel =
            local->polygonModel.subModels[subModelIndex];
        if (!desired[static_cast<std::size_t>(subModelIndex)]) {
            if (*subModel.state == SUBMODEL_STATE_LOADED
                && subModel.numUsers == 0
                && local->memoryMappedFile == nullptr) {
                *subModel.state = SUBMODEL_STATE_UNLOADED;
                _aligned_free(subModel.data);
                subModel.data = nullptr;
            }
            continue;
        }
        if (*subModel.state == SUBMODEL_STATE_LOADED
            || local->streamFilePtr == nullptr
            || subModel.fileOffset < 0) {
            continue;
        }
        cm_subModelData_t* const data =
            static_cast<cm_subModelData_t*>(_aligned_malloc(
                subModel.header.totalSize, 16));
        if (data != nullptr && local->streamFilePtr->ReadOfs(
                subModel.fileOffset, data,
                subModel.header.totalSize)
                == static_cast<unsigned int>(subModel.header.totalSize)) {
            subModel.data = data;
            *subModel.state = SUBMODEL_STATE_LOADED;
        } else {
            _aligned_free(data);
        }
    }
}

bool idCollisionModelManager::IsResident(const idBounds&,
    const idPositionedCollisionModel* const models,
    const int numModels) {
    if (models == nullptr || numModels <= 0) {
        return true;
    }
    for (int modelIndex = 0; modelIndex < numModels; ++modelIndex) {
        const idCollisionModelLocal* const model =
            dynamic_cast<const idCollisionModelLocal*>(
                models[modelIndex].model);
        if (model == nullptr || model->modelType != CM_POLYGONMODEL) {
            continue;
        }
        for (int subModelIndex = 0;
             subModelIndex < model->polygonModel.numSubModels;
             ++subModelIndex) {
            if (*model->polygonModel.subModels[subModelIndex].state
                != SUBMODEL_STATE_LOADED) {
                return false;
            }
        }
    }
    return true;
}

void PrintSubModelInfo(const cm_subModelData_t* const data) {
    if (data == nullptr) {
        return;
    }
    idLibPrint::Printf("  %6i nodes (%i kB)\n", data->numNodes,
        data->numNodes * 16 / 1024);
    idLibPrint::Printf("  %6i primitive indices (%i kB)\n",
        data->numPrimitiveIndices, data->numPrimitiveIndices * 2 / 1024);
    idLibPrint::Printf("  %6i materials (%i kB)\n", data->numMaterials,
        data->numMaterials * 16 / 1024);
    idLibPrint::Printf("  %6i polygons (%i kB)\n", data->numPolygons,
        data->numPolygons * 16 / 1024);
    idLibPrint::Printf("  %6i polygon edges (%i kB)\n",
        data->numPolygonEdges, data->numPolygonEdges * 2 / 1024);
    idLibPrint::Printf("  %6i edges (%i kB)\n", data->numEdges,
        data->numEdges * 4 / 1024);
    idLibPrint::Printf("  %6i vertices (%i kB)\n", data->numVertices,
        data->numVertices * 16 / 1024);
    idLibPrint::Printf("  %6i polytopes (%i kB)\n", data->numPolytopes,
        data->numPolytopes * 16 / 1024);
    idLibPrint::Printf("  %6i polytope planes (%i kB)\n",
        data->numPolytopePlanes, data->numPolytopePlanes * 16 / 1024);
}

void AddCollisionModelInfo(const idCollisionModelLocal* const model,
    cm_subModelData_t* const stats) {
    if (model == nullptr || stats == nullptr
        || model->modelType != CM_POLYGONMODEL) {
        return;
    }
    for (int index = 0; index < model->polygonModel.numSubModels; ++index) {
        const cm_subModel_t& subModel = model->polygonModel.subModels[index];
        const cm_subModelData_t* const data = AcquireSubModelData(subModel);
        if (data != nullptr && data->header.loadedSize != 32) {
            stats->numNodes += data->numNodes;
            stats->numPrimitiveIndices += data->numPrimitiveIndices;
            stats->numMaterials += data->numMaterials;
            stats->numPolygons += data->numPolygons;
            stats->numPolygonEdges += data->numPolygonEdges;
            stats->numEdges += data->numEdges;
            stats->numVertices += data->numVertices;
            stats->numPolytopes += data->numPolytopes;
            stats->numPolytopePlanes += data->numPolytopePlanes;
        }
        ReleaseSubModelData(subModel, data);
    }
}

void PrintCollisionModelInfo(const idCollisionModelLocal* const model) {
    if (model == nullptr) {
        return;
    }
    idLibPrint::Printf("collision model %s: %i total / %i loaded bytes\n",
        model->GetName(), model->GetTotalMemory(), model->GetLoadedMemory());
    if (model->modelType != CM_POLYGONMODEL) {
        return;
    }
    for (int index = 0; index < model->polygonModel.numSubModels; ++index) {
        const cm_subModel_t& subModel = model->polygonModel.subModels[index];
        const cm_subModelData_t* const data = AcquireSubModelData(subModel);
        if (data != nullptr && data->header.loadedSize != 32) {
            PrintSubModelInfo(data);
        }
        ReleaseSubModelData(subModel, data);
    }
}

bool idTrmFromSubModel::TrmFromSubModel(
    const idCollisionModelLocal* const model,
    const cm_subModelData_t* const data, idTraceModel& trm) {
    if (model == nullptr || data == nullptr || data->header.loadedSize == 32
        || data->numVertices > 32 || data->numEdges > 32
        || data->numPolygons > 16 || data->numVertices <= 3) {
        return false;
    }
    std::memset(&trm, 0, sizeof(trm));
    trm.type = TRM_CUSTOM;
    trm.bounds[0].Set(FLT_MAX, FLT_MAX, FLT_MAX);
    trm.bounds[1].Set(-FLT_MAX, -FLT_MAX, -FLT_MAX);
    cm_subModelPtrs_t pointers{};
    idPolygonModelCollisionDetection::SetupSubModelPtrsFromData(
        pointers, data);
    trm.numPolys = data->numPolygons;
    trm.maxPolyEdges = 0;
    for (int polygonIndex = 0; polygonIndex < data->numPolygons;
         ++polygonIndex) {
        const cm_polygon_t& polygon = pointers.polygons[polygonIndex];
        idPlane plane;
        CM_GetPolygonPlane(pointers, polygon, plane);
        trm.polyPlaneX[polygonIndex] = plane.a;
        trm.polyPlaneY[polygonIndex] = plane.b;
        trm.polyPlaneZ[polygonIndex] = plane.c;
        trm.polyPlaneW[polygonIndex] = plane.d;
        trm.numPolyEdges[polygonIndex] = polygon.numEdges;
        trm.maxPolyEdges = (std::max)(trm.maxPolyEdges,
            static_cast<unsigned int>(polygon.numEdges));
        for (int edge = 0; edge < polygon.numEdges; ++edge) {
            const std::uint16_t reference = pointers.polygonEdges[
                polygon.firstEdge + edge];
            trm.polyEdges[polygonIndex][edge] = static_cast<std::uint8_t>(
                CM_EdgeIndex(reference)
                | ((reference & 0x8000) != 0 ? 0x80 : 0));
        }
    }
    trm.numVerts = data->numVertices;
    for (int index = 0; index < data->numVertices; ++index) {
        const idVec3& vertex = pointers.vertices[index].p;
        trm.vertsX[index] = vertex.x;
        trm.vertsY[index] = vertex.y;
        trm.vertsZ[index] = vertex.z;
        for (int axis = 0; axis < 3; ++axis) {
            trm.bounds[0][axis] = (std::min)(trm.bounds[0][axis],
                vertex[axis]);
            trm.bounds[1][axis] = (std::max)(trm.bounds[1][axis],
                vertex[axis]);
        }
    }
    trm.numEdges = data->numEdges;
    for (int index = 0; index < data->numEdges; ++index) {
        trm.edges[index].v[0] = pointers.edges[index].vertexNum[0];
        trm.edges[index].v[1] = pointers.edges[index].vertexNum[1];
    }
    if (!trm.IsClosedSurface()) {
        return false;
    }
    trm.CalculateInsetSphereRadius();
    trm.offset = (trm.bounds[0] + trm.bounds[1]) * 0.5f;
    trm.GenerateEdgeNormals();
    trm.TestConvexity();
    trm.ClearUnused();
    return true;
}

bool TrmFromModel(idCollisionModelLocal* const model, idTraceModel* const trm) {
    if (model == nullptr || trm == nullptr
        || model->modelType != CM_POLYGONMODEL
        || model->polygonModel.numSubModels != 1) {
        return false;
    }
    const cm_subModel_t& subModel = model->polygonModel.subModels[0];
    const cm_subModelData_t* const data = AcquireSubModelData(subModel);
    const bool result = idTrmFromSubModel::TrmFromSubModel(
        model, data, *trm);
    ReleaseSubModelData(subModel, data);
    return result;
}

bool idCollisionModelManager::TrmFromModel(const char* const modelName,
    idTraceModel& trm) {
    idCollisionModelLocal* const model = dynamic_cast<idCollisionModelLocal*>(
        LoadModel(modelName));
    if (model == nullptr) {
        return false;
    }
    const bool result = ::TrmFromModel(model, &trm);
    delete model;
    return result;
}

int idCollisionModelManager::CompoundTrmFromModel(
    const char* const modelName, idTraceModel* const trms,
    const int maxTrms, int* const invalidSubmodelIndices,
    int* const numInvalidIndices) {
    idCollisionModelLocal* const model = dynamic_cast<idCollisionModelLocal*>(
        LoadModel(modelName));
    if (model == nullptr || trms == nullptr || maxTrms <= 0
        || model->modelType != CM_POLYGONMODEL
        || model->polygonModel.numSubModels > maxTrms) {
        delete model;
        return 0;
    }
    const int invalidCapacity = numInvalidIndices != nullptr
        ? *numInvalidIndices : 0;
    if (numInvalidIndices != nullptr) {
        *numInvalidIndices = 0;
    }
    int count = 0;
    for (int index = 0; index < model->polygonModel.numSubModels; ++index) {
        const cm_subModel_t& subModel = model->polygonModel.subModels[index];
        const cm_subModelData_t* const data = AcquireSubModelData(subModel);
        const bool valid = idTrmFromSubModel::TrmFromSubModel(
            model, data, trms[count]);
        ReleaseSubModelData(subModel, data);
        if (valid) {
            ++count;
        } else if (invalidSubmodelIndices != nullptr
            && numInvalidIndices != nullptr
            && *numInvalidIndices < invalidCapacity) {
            invalidSubmodelIndices[(*numInvalidIndices)++] = index + 1;
        } else {
            delete model;
            return 0;
        }
    }
    delete model;
    return count;
}

idCollisionQuery idCollisionModelManager::Translation(trace_t* const result,
    const idVec3& start, const idVec3& end, const idBounds& globalBounds,
    const idTraceModel** const trms, const int numTrms,
    const idMat3& trmAxis, const int contentMask,
    const idPositionedCollisionModel* const models, const int numModels,
    const char* const userName) {
    EnsureQueryManager();
    idCollisionQuery query = cdQuery.SubmitTranslationQuery(start, end,
        globalBounds, trms, numTrms, trmAxis, contentMask, models,
        numModels, userName);
    if (result != nullptr) {
        cdQuery.GetTraceResult(result, query, false);
    }
    return query;
}

idCollisionQuery idCollisionModelManager::LocalTranslation(
    const idCollisionQuery localSpace, const idVec3& start,
    const idVec3& end, const idBounds& globalBounds,
    const idTraceModel** const trms, const int numTrms,
    const idMat3& trmAxis, const int contentMask,
    const idPositionedCollisionModel* const models, const int numModels,
    const char* const userName) {
    EnsureQueryManager();
    return cdQuery.SubmitLocalTranslationQuery(localSpace, start, end,
        globalBounds, trms, numTrms, trmAxis, contentMask, models,
        numModels, userName);
}

idCollisionQuery idCollisionModelManager::Rotation(trace_t* const result,
    const idVec3& start, const idRotation& rotation,
    const idBounds& globalBounds, const idTraceModel** const trms,
    const int numTrms, const idMat3& trmAxis, const int contentMask,
    const idPositionedCollisionModel* const models, const int numModels,
    const char* const userName) {
    EnsureQueryManager();
    idCollisionQuery query = cdQuery.SubmitRotationQuery(start, rotation,
        globalBounds, trms, numTrms, trmAxis, contentMask, models,
        numModels, userName);
    if (result != nullptr) {
        cdQuery.GetRotationResult(baseTraceWork, result, query, false);
    }
    return query;
}

idCollisionQuery idCollisionModelManager::Motion(trace_t* const result,
    const idVec3& start, const idVec3& end, const idRotation& rotation,
    const idBounds& globalBounds, const idTraceModel** const trms,
    const int numTrms, const idMat3& trmAxis, const int contentMask,
    const idPositionedCollisionModel* const models, const int numModels,
    const char* const userName) {
    EnsureQueryManager();
    idCollisionQuery query = cdQuery.SubmitMotionQuery(start, end, rotation,
        globalBounds, trms, numTrms, trmAxis, contentMask, models,
        numModels, userName);
    if (result != nullptr) {
        cdQuery.GetTraceResult(result, query, false);
    }
    return query;
}

idCollisionQuery idCollisionModelManager::MotionContacts(
    trace_t* const result, contactsResult_t* const contacts,
    const idVec3& start, const idVec3& end, const idRotation& rotation,
    const float depth, const idBounds& globalBounds,
    const idTraceModel** const trms, const int numTrms,
    const idMat3& trmAxis, const int contentMask,
    const idPositionedCollisionModel* const models, const int numModels,
    const char* const userName) {
    EnsureQueryManager();
    idCollisionQuery query = cdQuery.SubmitMotionContactsQuery(start, end,
        rotation, depth, globalBounds, trms, numTrms, trmAxis,
        contentMask, models, numModels, userName);
    if (result != nullptr || contacts != nullptr) {
        cdQuery.GetMotionContactsResult(baseTraceWork, result, contacts,
            query, false);
    }
    return query;
}

idCollisionQuery idCollisionModelManager::Contents(trace_t* const result,
    const idVec3& start, const idBounds& globalBounds,
    const idTraceModel** const trms, const int numTrms,
    const idMat3& trmAxis, const int contentMask,
    const idPositionedCollisionModel* const models, const int numModels,
    const char* const userName) {
    EnsureQueryManager();
    idCollisionQuery query = cdQuery.SubmitContentsQuery(start, globalBounds,
        trms, numTrms, trmAxis, contentMask, models, numModels, userName);
    if (result != nullptr) {
        cdQuery.GetTraceResult(result, query, false);
    }
    return query;
}

idCollisionQuery idCollisionModelManager::LocalContents(
    const idCollisionQuery localSpace, const idVec3& start,
    const idBounds& globalBounds, const idTraceModel** const trms,
    const int numTrms, const idMat3& trmAxis, const int contentMask,
    const idPositionedCollisionModel* const models, const int numModels,
    const char* const userName) {
    EnsureQueryManager();
    return cdQuery.SubmitLocalContentsQuery(localSpace, start, globalBounds,
        trms, numTrms, trmAxis, contentMask, models, numModels, userName);
}

idCollisionQuery idCollisionModelManager::Contacts(
    contactsResult_t* const result, const idVec3& start,
    const idVec3& direction, const float depth,
    const idBounds& globalBounds, const idTraceModel** const trms,
    const int numTrms, const idMat3& trmAxis, const int contentMask,
    const idPositionedCollisionModel* const models, const int numModels,
    const char* const userName) {
    EnsureQueryManager();
    idCollisionQuery query = cdQuery.SubmitContactsQuery(start, direction,
        depth, globalBounds, trms, numTrms, trmAxis, contentMask, models,
        numModels, userName);
    if (result != nullptr) {
        cdQuery.GetContactsResult(result, query, false);
    }
    return query;
}

idCollisionQuery idCollisionModelManager::Clip(clipResult_t* const result,
    const idVec3& start, const idBounds& globalBounds,
    const idTraceModel** const trms, const int numTrms,
    const idMat3& trmAxis, const int contentMask,
    const idPositionedCollisionModel* const models, const int numModels,
    const char* const userName) {
    EnsureQueryManager();
    idCollisionQuery query = cdQuery.SubmitClipQuery(start, globalBounds,
        trms, numTrms, trmAxis, contentMask, models, numModels, userName);
    if (result != nullptr) {
        cdQuery.GetClipResult(baseTraceWork, result, query, false);
    }
    return query;
}

idCollisionQuery idCollisionModelManager::StepMove(trace_t* const result,
    const idVec3& start, const idVec3& end, const idVec3& downNormal,
    const float stepUp, const float stepDown,
    const idBounds& globalBounds, const idTraceModel** const trms,
    const int numTrms, const idMat3& trmAxis, const int contentMask,
    const idPositionedCollisionModel* const models, const int numModels,
    const char* const userName) {
    EnsureQueryManager();
    idCollisionQuery query = cdQuery.SubmitStepMoveQuery(start, end,
        downNormal, stepUp, stepDown, globalBounds, trms, numTrms,
        trmAxis, contentMask, models, numModels, userName);
    if (result != nullptr) {
        cdQuery.GetTraceResult(result, query, false);
    }
    return query;
}

idCollisionQuery idCollisionModelManager::StepMoveContacts(
    trace_t* const result, contactsResult_t* const contacts,
    const idVec3& start, const idVec3& end, const idVec3& downNormal,
    const float stepUp, const float stepDown,
    const idBounds& globalBounds, const idTraceModel** const trms,
    const int numTrms, const idMat3& trmAxis, const int contentMask,
    const idPositionedCollisionModel* const models, const int numModels,
    const char* const userName) {
    EnsureQueryManager();
    idCollisionQuery query = cdQuery.SubmitStepMoveContactsQuery(start, end,
        downNormal, stepUp, stepDown, globalBounds, trms, numTrms,
        trmAxis, contentMask, models, numModels, userName);
    if (result != nullptr || contacts != nullptr) {
        cdQuery.GetSlideMoveContactsResult(baseTraceWork, result, contacts,
            query, false);
    }
    return query;
}

idCollisionQuery idCollisionModelManager::SlideMove(trace_t* const result,
    const idVec3& start, const idVec3& velocity,
    const idVec3& gravityVector, const float stepUp,
    const float stepDown, const idBounds& globalBounds,
    const idTraceModel** const trms, const int numTrms,
    const idMat3& trmAxis, const int contentMask,
    const idPositionedCollisionModel* const models, const int numModels,
    const char* const userName) {
    EnsureQueryManager();
    idCollisionQuery query = cdQuery.SubmitSlideMoveQuery(start, velocity,
        gravityVector, stepUp, stepDown, globalBounds, trms, numTrms,
        trmAxis, contentMask, models, numModels, userName);
    if (result != nullptr) {
        cdQuery.GetTraceResult(result, query, false);
    }
    return query;
}

idCollisionQuery idCollisionModelManager::SlideMoveContacts(
    trace_t* const result, contactsResult_t* const contacts,
    const idVec3& start, const idVec3& velocity,
    const idVec3& gravityVector, const float stepUp,
    const float stepDown, const idBounds& globalBounds,
    const idTraceModel** const trms, const int numTrms,
    const idMat3& trmAxis, const int contentMask,
    const idPositionedCollisionModel* const models, const int numModels,
    const char* const userName) {
    EnsureQueryManager();
    idCollisionQuery query = cdQuery.SubmitSlideMoveContactsQuery(start,
        velocity, gravityVector, stepUp, stepDown, globalBounds, trms,
        numTrms, trmAxis, contentMask, models, numModels, userName);
    if (result != nullptr || contacts != nullptr) {
        cdQuery.GetSlideMoveContactsResult(baseTraceWork, result, contacts,
            query, false);
    }
    return query;
}

bool idCollisionModelManager::GetContentsResult(trace_t* const result,
    idCollisionQuery& query, const bool peek) {
    EnsureQueryManager();
    return cdQuery.GetTraceResult(result, query, peek);
}

bool idCollisionModelManager::GetMotionContactsResult(trace_t* const result,
    contactsResult_t* const contacts, idCollisionQuery& query,
    const bool peek) {
    EnsureQueryManager();
    return cdQuery.GetMotionContactsResult(baseTraceWork, result, contacts,
        query, peek);
}

bool idCollisionModelManager::GetClipResult(clipResult_t* const result,
    idCollisionQuery& query, const bool peek) {
    EnsureQueryManager();
    return cdQuery.GetClipResult(baseTraceWork, result, query, peek);
}

bool idCollisionModelManager::GetStepMoveContactsResult(
    trace_t* const result, contactsResult_t* const contacts,
    idCollisionQuery& query, const bool peek) {
    EnsureQueryManager();
    return cdQuery.GetSlideMoveContactsResult(baseTraceWork, result,
        contacts, query, peek);
}

void StepMoveInternal(trace_t* const result, const idVec3& start,
    const idVec3& end, const idVec3& downNormal, const float stepUp,
    const float stepDown, const idBounds& globalBounds,
    const idTraceModel** const traceModels, const int numTraceModels,
    const idMat3& traceModelAxis, const int contentMask,
    const idPositionedCollisionModel* const models, const int numModels,
    const char* const userName) {
    collisionModelManager.StepMove(result, start, end, downNormal, stepUp,
        stepDown, globalBounds, traceModels, numTraceModels,
        traceModelAxis, contentMask, models, numModels, userName);
}

void ListCollisionModels() {
    int totalMemory = 0;
    int loadedMemory = 0;
    int maxResidentMemory = 0;
    for (int index = 0; index < idCollisionModelLocal::resourceList.num;
         ++index) {
        const idCollisionModelLocal* const model =
            static_cast<const idCollisionModelLocal*>(
                idCollisionModelLocal::resourceList.Index(index));
        if (model != nullptr) {
            const int modelTotal = model->GetTotalMemory();
            const int modelLoaded = model->GetLoadedMemory();
            const int modelResident = model->GetMaxResidentMemory(nullptr);
            idLibPrint::Printf(
                "%4d: %6d kB / %6d kB / %6d kB / %4d / %s\n",
                index, modelTotal >> 10, modelLoaded >> 10,
                modelResident >> 10,
                model->modelType == CM_POLYGONMODEL
                    ? model->polygonModel.numSubModels : 0,
                model->GetName());
            totalMemory += modelTotal;
            loadedMemory += modelLoaded;
            maxResidentMemory += modelResident;
        }
    }
    idLibPrint::Printf(
        "%d kB in %d models (%d kB loaded, %d kB max resident)\n",
        totalMemory >> 10, idCollisionModelLocal::resourceList.num,
        loadedMemory >> 10, maxResidentMemory >> 10);
}

void ListCollisionModels_f(const idCmdArgs*) {
    ListCollisionModels();
}

void CollisionModelInfo_f(const idCmdArgs* const args) {
    if (args == nullptr || args->Argc() < 2) {
        idLibPrint::Printf(
            "usage: collisionModelInfo <num>; use -1 for totals\n");
        return;
    }
    const int index = std::atoi(args->Argv(1));
    if (index >= 0) {
        PrintCollisionModelInfo(static_cast<const idCollisionModelLocal*>(
            idCollisionModelLocal::resourceList.Index(index)));
        return;
    }
    cm_subModelData_t totals{};
    for (int modelIndex = 0;
         modelIndex < idCollisionModelLocal::resourceList.num;
         ++modelIndex) {
        AddCollisionModelInfo(static_cast<const idCollisionModelLocal*>(
            idCollisionModelLocal::resourceList.Index(modelIndex)),
            &totals);
    }
    PrintSubModelInfo(&totals);
}

void ExportCollisionModel_f(const idCmdArgs* const args) {
    if (args == nullptr || args->Argc() < 2) {
        idLibPrint::Printf(
            "usage: exportCollisionModel <model.bcm> [output.obj]\n");
        return;
    }
    idCollisionModelLocal* const model =
        dynamic_cast<idCollisionModelLocal*>(
            collisionModelManager.LoadModel(args->Argv(1)));
    if (model == nullptr || model->modelType != CM_POLYGONMODEL) {
        delete model;
        idLibPrint::Warning("could not load collision model %s",
            args->Argv(1));
        return;
    }
    idStr outputName(args->Argc() > 2 ? args->Argv(2) : args->Argv(1));
    if (args->Argc() <= 2) {
        outputName.SetFileExtension("obj");
    } else if (std::strrchr(outputName.c_str(), '.') == nullptr) {
        outputName.Append(".obj");
    }
    idFileLocal output(fileSystem->OpenFileWrite(outputName.c_str(),
        FSPATH_BASE));
    if (output.file == nullptr) {
        delete model;
        idLibPrint::Warning("could not create %s", outputName.c_str());
        return;
    }
    output->Printf("# recovered idTech 5 collision model %s\n",
        model->GetName());
    int vertexBase = 1;
    for (int subModelIndex = 0;
         subModelIndex < model->polygonModel.numSubModels;
         ++subModelIndex) {
        const cm_subModel_t& subModel =
            model->polygonModel.subModels[subModelIndex];
        const cm_subModelData_t* const data = AcquireSubModelData(subModel);
        if (data == nullptr || data->header.loadedSize == 32) {
            ReleaseSubModelData(subModel, data);
            continue;
        }
        cm_subModelPtrs_t pointers{};
        idPolygonModelCollisionDetection::SetupSubModelPtrsFromData(
            pointers, data);
        for (int vertex = 0; vertex < data->numVertices; ++vertex) {
            const idVec3& point = pointers.vertices[vertex].p;
            output->Printf("v %.9g %.9g %.9g\n", point.x, point.y,
                point.z);
        }
        output->Printf("g submodel_%d\n", subModelIndex);
        for (int polygonIndex = 0; polygonIndex < data->numPolygons;
             ++polygonIndex) {
            const cm_polygon_t& polygon = pointers.polygons[polygonIndex];
            if (polygon.numEdges < 3) {
                continue;
            }
            output->Printf("f");
            for (int edgeIndex = 0; edgeIndex < polygon.numEdges;
                 ++edgeIndex) {
                const std::uint16_t reference = pointers.polygonEdges[
                    polygon.firstEdge + edgeIndex];
                const cm_edge_t& edge = pointers.edges[
                    CM_EdgeIndex(reference)];
                output->Printf(" %d", vertexBase
                    + CM_EdgeStartVertex(edge, reference));
            }
            output->Printf("\n");
        }
        vertexBase += data->numVertices;
        ReleaseSubModelData(subModel, data);
    }
    delete model;
    idLibPrint::Printf("wrote %s\n", outputName.c_str());
}

void BuildCollisionModelsForMap_f(const idCmdArgs* const args) {
    if (args == nullptr || args->Argc() < 2) {
        idLibPrint::Printf("usage: bcm <map> [-entityOnly]\n");
        return;
    }
    idLibPrint::Warning(
        "bcm command requires the framework map-file loader for %s",
        args->Argv(1));
}

void StripBCM_f(const idCmdArgs* const args) {
    if (args == nullptr || args->Argc() < 2) {
        idLibPrint::Printf("usage: stripBCM <model.bcm>\n");
        return;
    }
    idLibPrint::Warning(
        "stripBCM requires the recovered map-specific strip volume set");
}
