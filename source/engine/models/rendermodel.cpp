#include "models/rendermodel.h"

#include "network/serializer.h"
#include "idlib/filesystem/file.h"

#include <algorithm>
#include <cstdint>
#include <cstring>

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

} // namespace

idRenderModel::MaterialNameCallback idRenderModel::materialNameCallback = nullptr;
idRenderModel::MaterialResolver idRenderModel::materialResolver = nullptr;
idRenderModel::ParmBlockSaveCallback idRenderModel::parmBlockSaveCallback = nullptr;
idRenderModel::ParmBlockLoadCallback idRenderModel::parmBlockLoadCallback = nullptr;
idRenderModel::SnapshotMaterialCallback idRenderModel::snapshotMaterialCallback = nullptr;
idRenderModel::SnapshotParmBlockCallback idRenderModel::snapshotParmBlockCallback = nullptr;

idRenderModel::idRenderModel()
    : name("")
    , debugName(nullptr)
    , deferredOrigin(0.0f, 0.0f, 0.0f)
    , deferredAxis(1.0f)
    , useDeferredPosition(false)
    , deferredPositionInitialized(false)
    , deleteOnSync(false)
    , unlinked(false)
    , needWriteToSnapshot(false)
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
}

idRenderModel::~idRenderModel() {
    RemoveDecals();
    FreeSurfaces();
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

decalHandle_t idRenderModel::AddDecalFromPoint(const decalParams_t*, int,
        const idVec3&, const idVec3&, idJointIndex) {
    return decalHandle_t();
}

bool idRenderModel::RemoveDecal(const decalHandle_t handle) {
    for (int index = 0; index < decalData.Num(); ++index) {
        if (decalData[index].handle == handle) {
            decalData.RemoveIndexFast(index);
            return true;
        }
    }
    return false;
}

void idRenderModel::RemoveDecals() {
    decalData.Clear();
}

void idRenderModel::FreeSurfaces() {
    surfaces.ClearFree();
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
}

void idRenderModel::AddSurface(const idRenderModelSurface& surface) {
    surfaces.Append(surface);
}

void idRenderModel::SetMaxSurfaces(const int maximum) {
    if (maximum >= 0) {
        surfaces.PreAllocate(maximum);
    }
}

void idRenderModel::FinishSurfaces() {
    referenceBounds[0].Zero();
    referenceBounds[1].Zero();
    bool haveBounds = false;
    for (int index = 0; index < surfaces.Num(); ++index) {
        // Geometry bounds are renderer-owned and deliberately opaque here.
        // A renderer integration may populate referenceBounds before commit.
        haveBounds = haveBounds || surfaces[index].geometry != nullptr;
    }
    if (!haveBounds) {
        referenceBounds[0].Zero();
        referenceBounds[1].Zero();
    }
}

void idRenderModel::CommitThisFrame() {
    CommitSubclass();
}

void idRenderModel::SetViewport(const int x, const int y, const int width,
        const int height) {
    g.viewport.x1 = static_cast<short>(x);
    g.viewport.y1 = static_cast<short>(y);
    g.viewport.x2 = static_cast<short>(x + width);
    g.viewport.y2 = static_cast<short>(y + height);
}

void idRenderModel::ClearOcclusionQuery() {
}

void idRenderModel::SetParm(const idDeclRenderParm*, const parmValue_t&) {
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
    return committed != nullptr && !unlinked;
}

int idRenderModel::GetNumReferences() const {
    return IsRendered() ? 1 : 0;
}

int idRenderModel::GetIndex() const {
    return -1;
}

idRenderWorld* idRenderModel::GetWorld() const {
    return nullptr;
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
