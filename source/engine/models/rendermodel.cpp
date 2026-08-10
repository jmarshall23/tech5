#include "models/rendermodel.h"

#include "network/serializer.h"
#include "idlib/filesystem/file.h"
#include "idlib/geometry/rendermatrix.h"

struct lightContribution_t;
struct ambientMap_t;
struct shadowMap_t;
class idRenderLightCommitted;
enum lightingModel_t : int;
#include "renderer/jobs/approximatelighting/approximatelighting.h"

#include <algorithm>
#include <cstdint>
#include <cstring>
#include <memory>
#include <unordered_map>

namespace {

const idVec3& ActiveOrigin(const idRenderModel& model) {
    return model.useDeferredPosition ? model.deferredOrigin : model.g.origin;
}

const idMat3& ActiveAxis(const idRenderModel& model) {
    return model.useDeferredPosition ? model.deferredAxis : model.g.axis;
}

bool WriteExact(idFile* file, const void* data, unsigned int size) {
    return file != nullptr && file->Write(data, size) == size;
}

bool ReadExact(idFile* file, void* data, unsigned int size) {
    return file != nullptr && file->Read(data, size) == size;
}

bool SaveEmptyParmBlock(const idParmBlock* block, idFile* file) {
    const std::uint8_t usingTemporaryOps = block != nullptr &&
        block->usingTempOps ? 1u : 0u;
    const std::int32_t operationCount = 0;
    return WriteExact(file, &usingTemporaryOps, sizeof(usingTemporaryOps)) &&
        WriteExact(file, &operationCount, sizeof(operationCount));
}

bool LoadEmptyParmBlock(idParmBlock* block, idFile* file) {
    std::uint8_t usingTemporaryOps = 0;
    std::int32_t operationCount = 0;
    if (!ReadExact(file, &usingTemporaryOps, sizeof(usingTemporaryOps)) ||
            !ReadExact(file, &operationCount, sizeof(operationCount)) ||
            operationCount != 0) {
        return false;
    }
    block->ops.Clear();
    block->constants.Clear();
    block->usingTempOps = usingTemporaryOps != 0;
    return true;
}

struct portableCommittedState_t {
    idRenderMatrix modelMatrix;
    idStaticParmBlock<32> renderParmBlock;
    approximateLighting_t approximateLighting{};
    idList<idRenderModelSurface, 85> surfaces;
    idRenderWorld* world = nullptr;
    int index = -1;
    int referenceCount = 0;
    bool rendered = false;
    bool litTransSort = false;

    portableCommittedState_t() {
        modelMatrix.Identity();
    }
};

std::unordered_map<const idRenderModel*,
    std::unique_ptr<portableCommittedState_t>> portableCommittedStates;

portableCommittedState_t& PortableState(const idRenderModel* const model) {
    std::unique_ptr<portableCommittedState_t>& state =
        portableCommittedStates[model];
    if (!state) state.reset(new portableCommittedState_t());
    return *state;
}

const portableCommittedState_t* FindPortableState(
        const idRenderModel* const model) {
    const auto found = portableCommittedStates.find(model);
    return found != portableCommittedStates.end()
        ? found->second.get() : nullptr;
}

} // namespace

idRenderModel::MaterialNameCallback idRenderModel::materialNameCallback = nullptr;
idRenderModel::MaterialResolver idRenderModel::materialResolver = nullptr;
idRenderModel::ParmBlockSaveCallback idRenderModel::parmBlockSaveCallback = nullptr;
idRenderModel::ParmBlockLoadCallback idRenderModel::parmBlockLoadCallback = nullptr;
idRenderModel::SnapshotMaterialCallback idRenderModel::snapshotMaterialCallback = nullptr;
idRenderModel::SnapshotParmBlockCallback idRenderModel::snapshotParmBlockCallback = nullptr;
idRenderModel::ScheduleCommitCallback idRenderModel::scheduleCommitCallback =
    nullptr;
idRenderModel::CommitCallback idRenderModel::commitCallback = nullptr;
idRenderModel::WorldResolver idRenderModel::worldResolver = nullptr;
idRenderModel::IntegerResolver idRenderModel::indexResolver = nullptr;
idRenderModel::IntegerResolver idRenderModel::referenceCountResolver =
    nullptr;
idRenderModel::VisibilityResolver idRenderModel::visibilityResolver =
    nullptr;
idRenderModel::ClearOcclusionCallback
    idRenderModel::clearOcclusionCallback = nullptr;
idRenderModel::NameCommitCallback idRenderModel::nameCommitCallback =
    nullptr;
idRenderModel::SurfaceCommitCallback idRenderModel::surfaceCommitCallback =
    nullptr;
idRenderModel::ParmSetCallback idRenderModel::parmSetCallback = nullptr;
idRenderModel::SurfaceResourceFreeCallback
    idRenderModel::surfaceResourceFreeCallback = nullptr;
idRenderModel::DecalCreateCallback idRenderModel::decalCreateCallback =
    nullptr;
idRenderModel::DecalPositionCallback idRenderModel::decalPositionCallback =
    nullptr;
idRenderModel::DecalRemoveCallback idRenderModel::decalRemoveCallback =
    nullptr;

idRenderModel::idRenderModel()
    : name("")
    , debugName(nullptr)
    , deferredOrigin(0.0f, 0.0f, 0.0f)
    , deferredAxis(1.0f)
    , useDeferredPosition(false)
    , deferredPositionInitialized(false)
    , deleteOnSync(false)
    , unlinked(true)
    , needWriteToSnapshot(true)
    , nextOnCommitList(nullptr)
    , needCommitFrameNum(-1)
    , committed(nullptr)
    , gameParmBlock()
    , surfaces()
    , decalData() {
    referenceBounds[0].Zero();
    referenceBounds[1].Zero();
    std::memset(&g, 0, sizeof(g));
    g.axis = idMat3(1.0f);
    g.scale.Set(1.0f, 1.0f, 1.0f);
    g.customSkin = -1;
    g.groupMasterIndex = -1;
    g.suppressShadowInLightIndex = -1;
    g.firstVisibleFrameCount = 2;
    g.fovScale = 1.0f;
    g.castDimShadows = DIMSHADOW_OFF;
    g.radiosityScale = 1.0f;
    g.staticReflectionStrength = 1.0f;
    g.highlightColor = HIGHLIGHT_COLOR_NONE;
    g.modelFade = 1.0f;
    g.fadeVisibilityOver = 400.0f;
    g.viewport.Zero();
    PortableState(this);
}

idRenderModel::~idRenderModel() {
    RemoveDecals();
    FreeSurfaces();
    portableCommittedStates.erase(this);
}

void idRenderModel::Save(idFile* file) {
    if (file == nullptr) return;

    WriteExact(file, &deferredOrigin, sizeof(deferredOrigin));
    WriteExact(file, &deferredAxis, sizeof(deferredAxis));
    const std::uint8_t deferred = useDeferredPosition ? 1u : 0u;
    const std::uint8_t deferredInitialized =
        deferredPositionInitialized ? 1u : 0u;
    const std::uint8_t savedUnlinked = unlinked ? 1u : 0u;
    WriteExact(file, &deferred, sizeof(deferred));
    WriteExact(file, &deferredInitialized, sizeof(deferredInitialized));
    WriteExact(file, &savedUnlinked, sizeof(savedUnlinked));
    WriteExact(file, &referenceBounds, sizeof(referenceBounds));

    const char* materialName = g.customMaterial != nullptr &&
        materialNameCallback != nullptr
        ? materialNameCallback(g.customMaterial) : "";
    file->WriteString(materialName != nullptr ? materialName : "");
    WriteExact(file, &g.customSkin, sizeof(g.customSkin));
    WriteExact(file, &g.origin, sizeof(g.origin));
    WriteExact(file, &g.axis, sizeof(g.axis));
    WriteExact(file, &g.scale, sizeof(g.scale));
    WriteExact(file, &g.groupMasterIndex, sizeof(g.groupMasterIndex));
    WriteExact(file, &g.allowSurfaceOnlyInViewID,
        sizeof(g.allowSurfaceOnlyInViewID));
    WriteExact(file, &g.suppressSurfaceInViewID,
        sizeof(g.suppressSurfaceInViewID));
    WriteExact(file, &g.suppressShadowInViewID,
        sizeof(g.suppressShadowInViewID));
    WriteExact(file, &g.suppressShadowInLightIndex,
        sizeof(g.suppressShadowInLightIndex));
    WriteExact(file, &g.fovScale, sizeof(g.fovScale));
    WriteExact(file, &g.modelDepthHack, sizeof(g.modelDepthHack));
    WriteExact(file, &g.castDimShadows, sizeof(g.castDimShadows));
    WriteExact(file, &g.dimShadowClipZ, sizeof(g.dimShadowClipZ));

    const std::uint8_t flags[] = {
        static_cast<std::uint8_t>(g.allowHighQualityDimShadows),
        static_cast<std::uint8_t>(g.noShadow),
        static_cast<std::uint8_t>(g.acceptDimShadows),
        static_cast<std::uint8_t>(g.megatexturedModel),
        static_cast<std::uint8_t>(g.privateLightOnly),
        static_cast<std::uint8_t>(g.noLocalLighting),
        static_cast<std::uint8_t>(g.moveLightingPoint),
        static_cast<std::uint8_t>(g.boostLightingPoint),
        static_cast<std::uint8_t>(g.noAmbient),
        static_cast<std::uint8_t>(g.addAlways),
        static_cast<std::uint8_t>(g.mvpIsIdentity),
        static_cast<std::uint8_t>(g.mvpIsSunFlare),
        static_cast<std::uint8_t>(g.mvpIsOrthographic),
        static_cast<std::uint8_t>(g.noGPUocclusionTest),
        static_cast<std::uint8_t>(g.neverOcclusionCullBounds),
        static_cast<std::uint8_t>(g.alwaysOcclusionCullBounds),
        static_cast<std::uint8_t>(g.addAlwaysForceOcclusionQuery),
        static_cast<std::uint8_t>(g.viewOriented)
    };
    WriteExact(file, flags, sizeof(flags));
    WriteExact(file, &g.highlightColor, sizeof(g.highlightColor));
    WriteExact(file, &g.modelFade, sizeof(g.modelFade));
    WriteExact(file, &g.maxVisibleRange, sizeof(g.maxVisibleRange));
    WriteExact(file, &g.fadeVisibilityOver, sizeof(g.fadeVisibilityOver));
    const std::uint8_t augment = g.augmentShowOnlyWhenOccluded ? 1u : 0u;
    WriteExact(file, &augment, sizeof(augment));

    if (parmBlockSaveCallback != nullptr) {
        parmBlockSaveCallback(&gameParmBlock, file);
    } else {
        SaveEmptyParmBlock(&gameParmBlock, file);
    }
}

bool idRenderModel::Load(idFile* file) {
    if (file == nullptr) return false;

    idVec3 loadedDeferredOrigin;
    idMat3 loadedDeferredAxis;
    idBounds loadedBounds;
    idRenderModelParms loadedParms = g;
    std::uint8_t deferred = 0;
    std::uint8_t deferredInitialized = 0;
    std::uint8_t loadedUnlinked = 0;
    if (!ReadExact(file, &loadedDeferredOrigin, sizeof(loadedDeferredOrigin)) ||
            !ReadExact(file, &loadedDeferredAxis, sizeof(loadedDeferredAxis)) ||
            !ReadExact(file, &deferred, sizeof(deferred)) ||
            !ReadExact(file, &deferredInitialized,
                sizeof(deferredInitialized)) ||
            !ReadExact(file, &loadedUnlinked, sizeof(loadedUnlinked)) ||
            !ReadExact(file, &loadedBounds, sizeof(loadedBounds))) {
        return false;
    }

    idStr materialName;
    if (file->ReadString(materialName) == 0) return false;
    loadedParms.customMaterial = nullptr;
    if (materialName.Length() != 0) {
        if (materialResolver == nullptr) return false;
        loadedParms.customMaterial = materialResolver(materialName.c_str(), true);
        if (loadedParms.customMaterial == nullptr) return false;
    }

    if (!ReadExact(file, &loadedParms.customSkin,
                sizeof(loadedParms.customSkin)) ||
            !ReadExact(file, &loadedParms.origin, sizeof(loadedParms.origin)) ||
            !ReadExact(file, &loadedParms.axis, sizeof(loadedParms.axis)) ||
            !ReadExact(file, &loadedParms.scale, sizeof(loadedParms.scale)) ||
            !ReadExact(file, &loadedParms.groupMasterIndex,
                sizeof(loadedParms.groupMasterIndex)) ||
            !ReadExact(file, &loadedParms.allowSurfaceOnlyInViewID,
                sizeof(loadedParms.allowSurfaceOnlyInViewID)) ||
            !ReadExact(file, &loadedParms.suppressSurfaceInViewID,
                sizeof(loadedParms.suppressSurfaceInViewID)) ||
            !ReadExact(file, &loadedParms.suppressShadowInViewID,
                sizeof(loadedParms.suppressShadowInViewID)) ||
            !ReadExact(file, &loadedParms.suppressShadowInLightIndex,
                sizeof(loadedParms.suppressShadowInLightIndex)) ||
            !ReadExact(file, &loadedParms.fovScale,
                sizeof(loadedParms.fovScale)) ||
            !ReadExact(file, &loadedParms.modelDepthHack,
                sizeof(loadedParms.modelDepthHack)) ||
            !ReadExact(file, &loadedParms.castDimShadows,
                sizeof(loadedParms.castDimShadows)) ||
            !ReadExact(file, &loadedParms.dimShadowClipZ,
                sizeof(loadedParms.dimShadowClipZ))) {
        return false;
    }

    std::uint8_t flags[18] = {};
    if (!ReadExact(file, flags, sizeof(flags))) return false;
    loadedParms.allowHighQualityDimShadows = flags[0] != 0;
    loadedParms.noShadow = flags[1] != 0;
    loadedParms.acceptDimShadows = flags[2] != 0;
    loadedParms.megatexturedModel = flags[3] != 0;
    loadedParms.privateLightOnly = flags[4] != 0;
    loadedParms.noLocalLighting = flags[5] != 0;
    loadedParms.moveLightingPoint = flags[6] != 0;
    loadedParms.boostLightingPoint = flags[7] != 0;
    loadedParms.noAmbient = flags[8] != 0;
    loadedParms.addAlways = flags[9] != 0;
    loadedParms.mvpIsIdentity = flags[10] != 0;
    loadedParms.mvpIsSunFlare = flags[11] != 0;
    loadedParms.mvpIsOrthographic = flags[12] != 0;
    loadedParms.noGPUocclusionTest = flags[13] != 0;
    loadedParms.neverOcclusionCullBounds = flags[14] != 0;
    loadedParms.alwaysOcclusionCullBounds = flags[15] != 0;
    loadedParms.addAlwaysForceOcclusionQuery = flags[16] != 0;
    loadedParms.viewOriented = flags[17] != 0;
    std::uint8_t augment = 0;
    if (!ReadExact(file, &loadedParms.highlightColor,
                sizeof(loadedParms.highlightColor)) ||
            !ReadExact(file, &loadedParms.modelFade,
                sizeof(loadedParms.modelFade)) ||
            !ReadExact(file, &loadedParms.maxVisibleRange,
                sizeof(loadedParms.maxVisibleRange)) ||
            !ReadExact(file, &loadedParms.fadeVisibilityOver,
                sizeof(loadedParms.fadeVisibilityOver)) ||
            !ReadExact(file, &augment, sizeof(augment))) {
        return false;
    }
    loadedParms.augmentShowOnlyWhenOccluded = augment != 0;
    const bool parmBlockLoaded = parmBlockLoadCallback != nullptr
        ? parmBlockLoadCallback(&gameParmBlock, file)
        : LoadEmptyParmBlock(&gameParmBlock, file);
    if (!parmBlockLoaded) return false;

    deferredOrigin = loadedDeferredOrigin;
    deferredAxis = loadedDeferredAxis;
    useDeferredPosition = deferred != 0;
    deferredPositionInitialized = deferredInitialized != 0;
    unlinked = loadedUnlinked != 0;
    referenceBounds = loadedBounds;
    g = loadedParms;
    return true;
}

void idRenderModel::SerializeSnapshot(idSerializer* serializer,
        bool serializeParmBlock) {
    if (serializer == nullptr) return;
    serializer->SerializeQ<1, 8>(g.modelFade);
    if (serializeParmBlock && snapshotParmBlockCallback != nullptr)
        snapshotParmBlockCallback(serializer, &gameParmBlock);
    if (snapshotMaterialCallback != nullptr)
        snapshotMaterialCallback(serializer, g.customMaterial);
    serializer->Serialize(g.scale);
    serializer->SerializePacked(g.customSkin);
    serializer->SerializePacked(g.allowSurfaceOnlyInViewID);
    serializer->SerializePacked(g.suppressSurfaceInViewID);
    serializer->SerializePacked(g.suppressShadowInViewID);
    serializer->SerializePacked(g.suppressShadowInLightIndex);
    serializer->SerializeUQ<255, 16>(g.fovScale);
    serializer->SerializeQ<128, 16>(g.modelDepthHack);

    bool flags[] = {
        g.noShadow != 0,
        g.castDimShadows != DIMSHADOW_OFF,
        g.megatexturedModel != 0,
        g.addAlways != 0,
        g.mvpIsIdentity != 0,
        g.mvpIsSunFlare != 0,
        g.mvpIsOrthographic != 0,
        g.noGPUocclusionTest != 0,
        g.neverOcclusionCullBounds != 0,
        g.alwaysOcclusionCullBounds != 0,
        g.addAlwaysForceOcclusionQuery != 0,
        g.augmentShowOnlyWhenOccluded != 0
    };
    for (bool& flag : flags) serializer->Serialize(flag);
    if (serializer->IsReading()) {
        g.noShadow = flags[0];
        g.castDimShadows = flags[1] ? DIMSHADOW_ON : DIMSHADOW_OFF;
        g.megatexturedModel = flags[2];
        g.addAlways = flags[3];
        g.mvpIsIdentity = flags[4];
        g.mvpIsSunFlare = flags[5];
        g.mvpIsOrthographic = flags[6];
        g.noGPUocclusionTest = flags[7];
        g.neverOcclusionCullBounds = flags[8];
        g.alwaysOcclusionCullBounds = flags[9];
        g.addAlwaysForceOcclusionQuery = flags[10];
        g.augmentShowOnlyWhenOccluded = flags[11];
    }
    unlinked = serializer->SerializeBoolNonRef(unlinked);
}

const idDeclSkins* idRenderModel::GetSkins() const {
    return nullptr;
}

decalHandle_t idRenderModel::AddDecalFromPoint(const decalParams_t* parms,
        const int startTime, const idVec3& position,
        const idVec3& direction, idJointIndex) {
    if (decalData.Num() >= 16) return decalHandle_t();

    decalData_t decal{};
    decal.handle.Invalidate();
    decal.jointId.Invalidate();
    InitDecalData(decal, parms, startTime, position, direction);
    if (decal.handle.IsValid()) decalData.Append(decal);
    return decal.handle;
}

bool idRenderModel::RemoveDecal(const decalHandle_t handle) {
    if (!handle.IsValid()) {
        const bool removedAny = decalData.Num() != 0;
        RemoveDecals();
        return removedAny;
    }
    for (int index = 0; index < decalData.Num(); ++index) {
        if (decalData[index].handle == handle) {
            if (decalRemoveCallback != nullptr)
                decalRemoveCallback(this, handle);
            decalData.RemoveIndexFast(index);
            return true;
        }
    }
    return false;
}

void idRenderModel::RemoveDecals() {
    if (decalRemoveCallback != nullptr) {
        for (int index = 0; index < decalData.Num(); ++index)
            decalRemoveCallback(this, decalData[index].handle);
    }
    decalData.Clear();
}

void idRenderModel::FreeSurfaces() {
    for (int index = 0; index < surfaces.Num(); ++index) {
        idRenderModelSurface& surface = surfaces[index];
        if (surfaceResourceFreeCallback != nullptr) {
            surfaceResourceFreeCallback(surface);
            continue;
        }
        if (surface.geometry != nullptr && !surface.geometryIsReference) {
            delete surface.geometry;
            surface.geometry = nullptr;
        }
        if (surface.stMap != nullptr && (surface.referenceMask & 3u) == 0) {
            delete surface.stMap;
            surface.stMap = nullptr;
        }
        if (surface.morphMap != nullptr && (surface.referenceMask & 2u) == 0) {
            delete surface.morphMap;
            surface.morphMap = nullptr;
        }
        if (surface.joints != nullptr && (surface.referenceMask & 1u) == 0) {
            delete surface.joints;
            surface.joints = nullptr;
        }
    }
    surfaces.ClearFree();
    PortableState(this).surfaces.ClearFree();
}

bool idRenderModel::CommitSubclass() {
    return true;
}

bool idRenderModel::UpdateInView(const idRenderView*, const idRenderView*,
        idRenderModelUpdateTools*) {
    return false;
}

const idList<sourceSurface_t, 5>* idRenderModel::GetSourceSurfaces() const {
    return nullptr;
}

void idRenderModel::SetName(const char* modelName) {
    name.Set(modelName != nullptr ? modelName : "");
    debugName = name.c_str();
    if (nameCommitCallback != nullptr)
        nameCommitCallback(this, name.c_str());
}

void idRenderModel::AddSurface(const idRenderModelSurface& surface) {
    surfaces.Append(surface);
}

void idRenderModel::SetMaxSurfaces(const int maximum) {
    if (maximum >= 0) {
        surfaces.PreAllocate(maximum);
        PortableState(this).surfaces.PreAllocate(maximum);
    }
}

void idRenderModel::FinishSurfaces() {
    bool haveBounds = false;
    for (int index = 0; index < surfaces.Num(); ++index) {
        idRenderModelSurface& surface = surfaces[index];
        if (g.customMaterial != nullptr && surface.material != nullptr)
            surface.material = g.customMaterial;
        if (surface.geometry == nullptr) continue;
        const idBounds& bounds = surface.geometry->bounds;
        if (!haveBounds) {
            referenceBounds = bounds;
            haveBounds = true;
        } else {
            for (int axis = 0; axis < 3; ++axis) {
                referenceBounds[0][axis] = (std::min)(
                    referenceBounds[0][axis], bounds[0][axis]);
                referenceBounds[1][axis] = (std::max)(
                    referenceBounds[1][axis], bounds[1][axis]);
            }
        }
    }
    if (!haveBounds) {
        referenceBounds[0].Zero();
        referenceBounds[1].Zero();
    }
}

void idRenderModel::CommitThisFrame() {
    unlinked = false;
    if (scheduleCommitCallback != nullptr && scheduleCommitCallback(this))
        return;
    Commit();
}

void idRenderModel::Commit() {
    portableCommittedState_t& state = PortableState(this);
    state.renderParmBlock.ops = gameParmBlock.ops;
    state.renderParmBlock.constants = gameParmBlock.constants;
    state.renderParmBlock.thread = gameParmBlock.thread;
    state.renderParmBlock.usingTempOps = gameParmBlock.usingTempOps;

    const bool subclassChanged = CommitSubclass();
    if (useDeferredPosition) {
        g.origin = deferredOrigin;
        g.axis = deferredAxis;
    }
    deferredPositionInitialized = true;
    idRenderMatrix::FromOriginAxisScale(
        g.origin, g.axis, g.scale, state.modelMatrix);
    CommitSurfaces();
    state.rendered = !unlinked;
    if (commitCallback != nullptr)
        commitCallback(this, subclassChanged);
}

void idRenderModel::CommitSurfaces() {
    portableCommittedState_t& state = PortableState(this);
    state.surfaces = surfaces;
    if (surfaceCommitCallback != nullptr)
        surfaceCommitCallback(this, state.surfaces);
}

void idRenderModel::SetViewport(const int x, const int y, const int width,
        const int height) {
    g.viewport.x1 = static_cast<short>(x);
    g.viewport.y1 = static_cast<short>(y);
    g.viewport.x2 = static_cast<short>(x + width - 1);
    g.viewport.y2 = static_cast<short>(y + height - 1);
}

void idRenderModel::ClearOcclusionQuery() {
    if (clearOcclusionCallback != nullptr)
        clearOcclusionCallback(this);
}

void idRenderModel::SetParm(const idDeclRenderParm* parm,
        const parmValue_t& value) {
    if (parm != nullptr && parmSetCallback != nullptr)
        parmSetCallback(&gameParmBlock, parm, value);
}

void idRenderModel::SetMaterialPersistenceCallbacks(
        MaterialNameCallback nameCallback, MaterialResolver resolver) {
    materialNameCallback = nameCallback;
    materialResolver = resolver;
}

void idRenderModel::SetParmBlockPersistenceCallbacks(
        ParmBlockSaveCallback saveCallback,
        ParmBlockLoadCallback loadCallback) {
    parmBlockSaveCallback = saveCallback;
    parmBlockLoadCallback = loadCallback;
}

void idRenderModel::SetSnapshotPersistenceCallbacks(
        SnapshotMaterialCallback materialCallback,
        SnapshotParmBlockCallback parmBlockCallback) {
    snapshotMaterialCallback = materialCallback;
    snapshotParmBlockCallback = parmBlockCallback;
}

void idRenderModel::SetRuntimeCallbacks(
        ScheduleCommitCallback scheduleCommit,
        CommitCallback commit,
        WorldResolver resolveWorld,
        IntegerResolver resolveIndex,
        IntegerResolver resolveReferenceCount,
        VisibilityResolver resolveVisibility,
        ClearOcclusionCallback clearOcclusion,
        NameCommitCallback commitName,
        SurfaceCommitCallback commitSurfacesCallback) {
    scheduleCommitCallback = scheduleCommit;
    commitCallback = commit;
    worldResolver = resolveWorld;
    indexResolver = resolveIndex;
    referenceCountResolver = resolveReferenceCount;
    visibilityResolver = resolveVisibility;
    clearOcclusionCallback = clearOcclusion;
    nameCommitCallback = commitName;
    surfaceCommitCallback = commitSurfacesCallback;
}

void idRenderModel::SetDecalCallbacks(DecalCreateCallback create,
        DecalPositionCallback position, DecalRemoveCallback remove) {
    decalCreateCallback = create;
    decalPositionCallback = position;
    decalRemoveCallback = remove;
}

void idRenderModel::SetModelResourceCallbacks(ParmSetCallback setParm,
        SurfaceResourceFreeCallback freeSurfaceResources) {
    parmSetCallback = setParm;
    surfaceResourceFreeCallback = freeSurfaceResources;
}

void idRenderModel::SetParm(const idDeclRenderParm* parm, const float scalar) {
    parmValue_t value = {};
    value.value[0] = value.value[1] = value.value[2] = value.value[3] = scalar;
    SetParm(parm, value);
}

void idRenderModel::SetParm(const idDeclRenderParm* parm,
        const idVec3& vector) {
    parmValue_t value = {};
    value.value[0] = vector.x;
    value.value[1] = vector.y;
    value.value[2] = vector.z;
    SetParm(parm, value);
}

void idRenderModel::SetParm(const idDeclRenderParm* parm,
        const idVec4& vector) {
    parmValue_t value = {};
    value.value[0] = vector.x;
    value.value[1] = vector.y;
    value.value[2] = vector.z;
    value.value[3] = vector.w;
    SetParm(parm, value);
}

idParmBlock* idRenderModel::GetParmBlock() {
    return &gameParmBlock;
}

const idParmBlock* idRenderModel::GetParmBlock() const {
    return &gameParmBlock;
}

bool idRenderModel::IsRendered() const {
    if (visibilityResolver != nullptr) return visibilityResolver(this);
    const portableCommittedState_t* state = FindPortableState(this);
    return state != nullptr && state->rendered;
}

int idRenderModel::GetNumReferences() const {
    if (referenceCountResolver != nullptr)
        return referenceCountResolver(this);
    const portableCommittedState_t* state = FindPortableState(this);
    return state != nullptr ? state->referenceCount : 0;
}

int idRenderModel::GetIndex() const {
    if (indexResolver != nullptr) return indexResolver(this);
    const portableCommittedState_t* state = FindPortableState(this);
    return state != nullptr ? state->index : -1;
}

idRenderWorld* idRenderModel::GetWorld() const {
    if (worldResolver != nullptr) return worldResolver(this);
    const portableCommittedState_t* state = FindPortableState(this);
    return state != nullptr ? state->world : nullptr;
}

const idRenderMatrix& idRenderModel::GetModelMatrix() const {
    return PortableState(this).modelMatrix;
}

idParmBlock* idRenderModel::GetRenderParmBlock() {
    return &PortableState(this).renderParmBlock;
}

const idParmBlock* idRenderModel::GetRenderParmBlock() const {
    return &PortableState(this).renderParmBlock;
}

const approximateLighting_t& idRenderModel::GetApproximateLighting() const {
    return PortableState(this).approximateLighting;
}

void idRenderModel::SetLitTransSortFlag() {
    PortableState(this).litTransSort = true;
}

bool idRenderModel::SetDecalPosition(const decalHandle_t handle,
        const idVec3& worldPosition, const idMat3& worldAxis) {
    return handle.IsValid() && decalPositionCallback != nullptr
        && decalPositionCallback(this, handle, worldPosition, worldAxis);
}

void idRenderModel::InitDecalData(decalData_t& decal,
        const decalParams_t* parms, const int startTime,
        const idVec3& position, const idVec3& direction) {
    decal.handle.Invalidate();
    decal.jointId.Invalidate();
    if (decalCreateCallback == nullptr) return;

    idMat3 decalWorldAxis(1.0f);
    decal.handle = decalCreateCallback(this, parms, startTime,
        position, direction, decalWorldAxis);
    if (!decal.handle.IsValid()) return;
    GlobalPointToLocal(position, decal.relativePos);
    decal.relativeAxis = decalWorldAxis * ActiveAxis(*this).Transpose();
}

void idRenderModel::GlobalPointToLocal(const idVec3& input,
        idVec3& output) const {
    const idVec3 delta = input - ActiveOrigin(*this);
    const idMat3& axis = ActiveAxis(*this);
    output.Set(delta.Dot(axis[0]), delta.Dot(axis[1]), delta.Dot(axis[2]));
}

void idRenderModel::LocalPointToGlobal(const idVec3& input,
        idVec3& output) const {
    const idMat3& axis = ActiveAxis(*this);
    output = ActiveOrigin(*this) + axis[0] * input.x + axis[1] * input.y +
        axis[2] * input.z;
}

bool CompareEqualMat3(const idMat3& left, const idMat3& right) {
    return std::memcmp(&left, &right, sizeof(left)) == 0;
}
