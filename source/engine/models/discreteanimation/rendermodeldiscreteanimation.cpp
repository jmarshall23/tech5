#include "models/discreteanimation/rendermodeldiscreteanimation.h"

#include "idlib/filesystem/file.h"

#include <algorithm>
#include <cstdint>
#include <cstring>
#include <new>

namespace {

bool WriteExact(idFile* const file, const void* const data,
        const unsigned int size) {
    return file != nullptr && file->Write(data, size) == size;
}

bool ReadExact(idFile* const file, void* const data,
        const unsigned int size) {
    return file != nullptr && file->Read(data, size) == size;
}

void SetJointTransform(idJointMat& transform, const idVec3& position,
        const idMat3& orientation) {
    transform.mat[0] = orientation[0].x;
    transform.mat[1] = orientation[1].x;
    transform.mat[2] = orientation[2].x;
    transform.mat[3] = position.x;
    transform.mat[4] = orientation[0].y;
    transform.mat[5] = orientation[1].y;
    transform.mat[6] = orientation[2].y;
    transform.mat[7] = position.y;
    transform.mat[8] = orientation[0].z;
    transform.mat[9] = orientation[1].z;
    transform.mat[10] = orientation[2].z;
    transform.mat[11] = position.z;
}

void GetJointTransform(const idJointMat& transform, idVec3& position,
        idMat3& orientation) {
    position.Set(transform.mat[3], transform.mat[7], transform.mat[11]);
    orientation[0].Set(transform.mat[0], transform.mat[4], transform.mat[8]);
    orientation[1].Set(transform.mat[1], transform.mat[5], transform.mat[9]);
    orientation[2].Set(transform.mat[2], transform.mat[6], transform.mat[10]);
}

void InitializeJointBufferFallback(idJointBuffer& buffer,
        const int numJoints) {
    buffer.numJoints = numJoints;
    buffer.offsetInOtherBuffer = 0;
    buffer.apiObject = nullptr;
    buffer.flags = 0;
}

} // namespace

idRenderModelDiscreteAnimation::UpdateCallback
    idRenderModelDiscreteAnimation::updateCallback = nullptr;
idRenderModelDiscreteAnimation::ModelResolver
    idRenderModelDiscreteAnimation::modelResolver = nullptr;
idRenderModelDiscreteAnimation::BreakableResolver
    idRenderModelDiscreteAnimation::breakableResolver = nullptr;
idRenderModelDiscreteAnimation::ShadowPolicyCallback
    idRenderModelDiscreteAnimation::shadowPolicyCallback = nullptr;
idRenderModelDiscreteAnimation::JointBufferInitCallback
    idRenderModelDiscreteAnimation::jointBufferInitCallback = nullptr;
idRenderModelDiscreteAnimation::JointBufferUpdateCallback
    idRenderModelDiscreteAnimation::jointBufferUpdateCallback = nullptr;
idRenderModelDiscreteAnimation::JointBufferReferenceCallback
    idRenderModelDiscreteAnimation::jointBufferReferenceCallback = nullptr;
idRenderModelDiscreteAnimation::JointBufferFreeCallback
    idRenderModelDiscreteAnimation::jointBufferFreeCallback = nullptr;

idRenderModelDiscreteAnimation::idRenderModelDiscreteAnimation()
    : modelData(nullptr), declBreakable(nullptr), modelTimestamp(0),
      currentJointBuffer(0), changed(false) {
    std::memset(jointBuffers, 0, sizeof(jointBuffers));
}

idRenderModelDiscreteAnimation::idRenderModelDiscreteAnimation(
        const char* const modelName, const idDecl* const declaration)
    : modelData(nullptr),
      declBreakable(breakableResolver != nullptr
          ? breakableResolver(declaration) : nullptr),
      modelTimestamp(static_cast<unsigned int>(-1)),
      currentJointBuffer(0), changed(false) {
    std::memset(jointBuffers, 0, sizeof(jointBuffers));
    LoadModel(modelName);
    if (!deferredPositionInitialized || !useDeferredPosition) {
        g.origin.Zero();
    }
    deferredOrigin.Zero();
    g.axis = idMat3(1.0f);
    g.addAlways = 1;
}

idRenderModelDiscreteAnimation::~idRenderModelDiscreteAnimation() {
    FreeModelSurfaces();
    for (idJointBuffer& buffer : jointBuffers) {
        if (jointBufferFreeCallback != nullptr) {
            jointBufferFreeCallback(&buffer);
        }
        InitializeJointBufferFallback(buffer, 0);
    }
}

void idRenderModelDiscreteAnimation::SetUpdateCallback(
    UpdateCallback callback) {
    updateCallback = callback;
}

void idRenderModelDiscreteAnimation::SetRuntimeCallbacks(
        const ModelResolver resolver,
        const BreakableResolver declarationResolver,
        const ShadowPolicyCallback shadowPolicy) {
    modelResolver = resolver;
    breakableResolver = declarationResolver;
    shadowPolicyCallback = shadowPolicy;
}

void idRenderModelDiscreteAnimation::SetJointBufferCallbacks(
        const JointBufferInitCallback initialize,
        const JointBufferUpdateCallback update,
        const JointBufferReferenceCallback reference,
        const JointBufferFreeCallback freeBuffer) {
    jointBufferInitCallback = initialize;
    jointBufferUpdateCallback = update;
    jointBufferReferenceCallback = reference;
    jointBufferFreeCallback = freeBuffer;
}

void idRenderModelDiscreteAnimation::Save(idFile* const file) {
    if (file == nullptr) return;
    idRenderModel::Save(file);
    const int transformCount = transforms.Num();
    if (!WriteExact(file, &transformCount, sizeof(transformCount))) return;
    for (int index = 0; index < transformCount; ++index) {
        if (!WriteExact(file, &transforms[index], sizeof(transforms[index])))
            return;
    }
    for (int index = 0; index < transformCount; ++index) {
        const std::uint8_t value = index < collapsed.Num() && collapsed[index]
            ? 1u : 0u;
        if (!WriteExact(file, &value, sizeof(value))) return;
    }
}

bool idRenderModelDiscreteAnimation::Load(idFile* const file) {
    if (file == nullptr || !idRenderModel::Load(file)) return false;
    int transformCount = 0;
    if (!ReadExact(file, &transformCount, sizeof(transformCount)) ||
        transformCount < 0 || transformCount > (1 << 20)) {
        return false;
    }
    transforms.SetNum(transformCount);
    for (int index = 0; index < transformCount; ++index) {
        if (!ReadExact(file, &transforms[index], sizeof(transforms[index])))
            return false;
    }
    collapsed.SetNum(transformCount);
    for (int index = 0; index < transformCount; ++index) {
        std::uint8_t value = 0;
        if (!ReadExact(file, &value, sizeof(value))) return false;
        collapsed[index] = value != 0;
    }
    changed = true;
    return true;
}

void idRenderModelDiscreteAnimation::SerializeSnapshot(
        idSerializer* const serializer, const bool serializeParmBlock) {
    idRenderModel::SerializeSnapshot(serializer, serializeParmBlock);
}

bool idRenderModelDiscreteAnimation::UpdateInView(
    const idRenderView* currentView, const idRenderView* nextView,
    idRenderModelUpdateTools* tools) {
    return updateCallback != nullptr
        ? updateCallback(this, currentView, nextView, tools)
        : false;
}

bool idRenderModelDiscreteAnimation::LoadModel(const char* const modelName) {
    if (modelData != nullptr || modelName == nullptr || modelName[0] == '\0') {
        return false;
    }
    SetName(modelName);
    modelData = modelResolver != nullptr
        ? modelResolver(modelName)
        : static_cast<const idDiscreteAnimationModelData*>(
            idDiscreteAnimationModelData::resourceList.Load(
                modelName, false, false));
    if (modelData == nullptr) return false;
    LoadModelData();
    return true;
}

void idRenderModelDiscreteAnimation::SetModelData(
        const idDiscreteAnimationModelData* const data) {
    if (modelData == data) return;
    modelData = data;
    LoadModelData();
}

void idRenderModelDiscreteAnimation::FreeModelSurfaces() {
    for (int index = 0; index < surfaces.Num(); ++index) {
        idJointBuffer* const reference = surfaces[index].joints;
        if (reference != nullptr) {
            if (jointBufferFreeCallback != nullptr)
                jointBufferFreeCallback(reference);
            delete reference;
            surfaces[index].joints = nullptr;
        }
    }
    surfaces.ClearFree();
}

void idRenderModelDiscreteAnimation::LoadModelData() {
    FreeModelSurfaces();
    transforms.Clear();
    collapsed.Clear();
    changed = false;
    currentJointBuffer = 0;
    if (modelData == nullptr) {
        modelTimestamp = 0;
        referenceBounds[0].Zero();
        referenceBounds[1].Zero();
        return;
    }

    modelTimestamp = modelData->timestamp;
    transforms = modelData->transforms;
    collapsed.SetNum(transforms.Num());
    for (int index = 0; index < collapsed.Num(); ++index)
        collapsed[index] = false;

    for (idJointBuffer& buffer : jointBuffers) {
        if (jointBufferFreeCallback != nullptr)
            jointBufferFreeCallback(&buffer);
        InitializeJointBufferFallback(buffer, transforms.Num());
        if (jointBufferInitCallback != nullptr) {
            jointBufferInitCallback(&buffer,
                transforms.Num() > 0 ? &transforms[0] : nullptr,
                transforms.Num());
        }
    }

    SetMaxSurfaces(modelData->surfaces.Num());
    for (int index = 0; index < modelData->surfaces.Num(); ++index) {
        const idDiscreteAnimationModelSurface* const dataSurface =
            modelData->surfaces[index];
        if (dataSurface == nullptr) continue;
        idRenderModelSurface surface{};
        surface.material = modelData->material;
        surface.materialNum = index;
        surface.geometry = dataSurface->triangles;
        surface.geometryIsReference = true;
        surface.joints = new (std::nothrow) idJointBuffer{};
        AddSurface(surface);
    }
    ReferenceSurfaceJointBuffers();
    referenceBounds = modelData->bounds;
    g.castDimShadows = shadowPolicyCallback != nullptr &&
            shadowPolicyCallback(declBreakable)
        ? DIMSHADOW_ON : DIMSHADOW_OFF;
    changed = true;
}

void idRenderModelDiscreteAnimation::ReferenceSurfaceJointBuffers() {
    if (modelData == nullptr) return;
    const int count = (std::min)(surfaces.Num(), modelData->surfaces.Num());
    for (int index = 0; index < count; ++index) {
        const idDiscreteAnimationModelSurface* const dataSurface =
            modelData->surfaces[index];
        idJointBuffer* const reference = surfaces[index].joints;
        if (dataSurface == nullptr || reference == nullptr) continue;
        if (jointBufferReferenceCallback != nullptr &&
            jointBufferReferenceCallback(reference,
                &jointBuffers[currentJointBuffer],
                dataSurface->jointOffset, dataSurface->numJoints)) {
            continue;
        }
        *reference = jointBuffers[currentJointBuffer];
        reference->numJoints = dataSurface->numJoints;
        reference->offsetInOtherBuffer += dataSurface->jointOffset;
    }
}

void idRenderModelDiscreteAnimation::UpdateReferenceBounds() {
    if (modelData == nullptr) return;
    bool havePoint = false;
    idVec3 minimum;
    idVec3 maximum;
    for (int index = 0; index < transforms.Num(); ++index) {
        if (index < collapsed.Num() && collapsed[index]) continue;
        const idVec3 point(transforms[index].mat[3],
            transforms[index].mat[7], transforms[index].mat[11]);
        if (!havePoint) {
            minimum = maximum = point;
            havePoint = true;
        } else {
            for (int axis = 0; axis < 3; ++axis) {
                minimum[axis] = (std::min)(minimum[axis], point[axis]);
                maximum[axis] = (std::max)(maximum[axis], point[axis]);
            }
        }
    }
    if (!havePoint) {
        referenceBounds[0].Zero();
        referenceBounds[1].Zero();
        return;
    }
    const idVec3 radius(modelData->maxRadius, modelData->maxRadius,
        modelData->maxRadius);
    referenceBounds[0] = minimum - radius;
    referenceBounds[1] = maximum + radius;
}

bool idRenderModelDiscreteAnimation::CommitSubclass() {
    if (!changed) return true;
    if (modelData == nullptr) {
        changed = false;
        return false;
    }
    UpdateReferenceBounds();
    currentJointBuffer = (currentJointBuffer + 1) & 1;
    idJointBuffer& buffer = jointBuffers[currentJointBuffer];
    if (jointBufferUpdateCallback != nullptr) {
        jointBufferUpdateCallback(&buffer,
            transforms.Num() > 0 ? &transforms[0] : nullptr,
            transforms.Num());
    } else {
        buffer.numJoints = transforms.Num();
    }
    ReferenceSurfaceJointBuffers();
    if (modelTimestamp != modelData->timestamp) {
        const int count = (std::min)(surfaces.Num(),
            modelData->surfaces.Num());
        for (int index = 0; index < count; ++index) {
            const idDiscreteAnimationModelSurface* const dataSurface =
                modelData->surfaces[index];
            surfaces[index].material = modelData->material;
            surfaces[index].geometry = dataSurface != nullptr
                ? dataSurface->triangles : nullptr;
        }
        modelTimestamp = modelData->timestamp;
    }
    changed = false;
    return true;
}

void idRenderModelDiscreteAnimation::Update() {
    CommitThisFrame();
}

void idRenderModelDiscreteAnimation::Reset() {
    if (modelData == nullptr) return;
    transforms = modelData->transforms;
    changed = true;
    CommitThisFrame();
}

int idRenderModelDiscreteAnimation::GetNumPieces() const {
    return modelData != nullptr ? modelData->traceModels.Num() : 0;
}

const idDeclBreakable*
idRenderModelDiscreteAnimation::GetDeclBreakable() const {
    return declBreakable;
}

bool idRenderModelDiscreteAnimation::GetPiecePosition(const int index,
        idVec3& position, idMat3& orientation) const {
    if (index < 0 || index >= transforms.Num()) return false;
    GetJointTransform(transforms[index], position, orientation);
    return true;
}

bool idRenderModelDiscreteAnimation::SetPiecePosition(const int index,
        const idVec3& position, const idMat3& orientation) {
    if (index < 0 || index >= transforms.Num()) return false;
    SetJointTransform(transforms[index], position, orientation);
    if (index < collapsed.Num()) collapsed[index] = false;
    changed = true;
    return true;
}

bool idRenderModelDiscreteAnimation::CollapsePiece(const int index) {
    if (index < 0 || index >= transforms.Num()) return false;
    const idMat3 zero(0.0f);
    idVec3 origin;
    origin.Zero();
    SetJointTransform(transforms[index], origin, zero);
    if (index < collapsed.Num()) collapsed[index] = true;
    changed = true;
    return true;
}

bool idRenderModelDiscreteAnimation::SetBasePiecePosition(
        const idVec3& position, const idMat3& orientation) {
    if (modelData == nullptr) return false;
    const int index = modelData->traceModels.Num();
    return SetPiecePosition(index, position, orientation);
}

bool idRenderModelDiscreteAnimation::GetPieceTraceModel(const int index,
        idTraceModel& traceModel) const {
    if (modelData == nullptr || index < 0 ||
        index >= modelData->traceModels.Num()) {
        return false;
    }
    traceModel = modelData->traceModels[index];
    return true;
}

const idList<sourceSurface_t, 5>*
idRenderModelDiscreteAnimation::GetSourceSurfaces() const {
    return modelData != nullptr
        ? reinterpret_cast<const idList<sourceSurface_t, 5>*>(
              &modelData->sourceSurfaces)
        : nullptr;
}
