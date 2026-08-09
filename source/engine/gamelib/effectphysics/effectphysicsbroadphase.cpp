#include "gamelib/effectphysics/effectphysicsbroadphase.h"

#include "gamelib/physics/physics.h"

#include <algorithm>

bool GameLib_GetEffectPhysicsMotionResult(
    idCollisionQuery& query, trace_t& result);
idCollisionQuery GameLib_SubmitEffectPhysicsMotion(idClip* clip,
    const idTraceModel& traceModel, const idSPObject& object,
    const idPositionedCollisionModel* models, int numModels,
    bool worldCollisionModelOnly);

idEffectPhysicsBroadPhase::idEffectPhysicsBroadPhase()
    : clip(nullptr)
    , traceModelCache(nullptr)
    , objects(0)
    , markers{idList<idSPMarker, 59>(0), idList<idSPMarker, 59>(0),
          idList<idSPMarker, 59>(0)} {
}

idEffectPhysicsBroadPhase::~idEffectPhysicsBroadPhase() {
    clip = nullptr;
    traceModelCache = nullptr;
    objects.Clear();
    for (idList<idSPMarker, 59>& axisMarkers : markers) {
        axisMarkers.Clear();
    }
}

void idEffectPhysicsBroadPhase::Init(idClip* const clip_,
    idTraceModelCache* const traceModelCache_) {
    clip = clip_;
    traceModelCache = traceModelCache_;
}

const idBounds* idEffectPhysicsBroadPhase::ResolveBounds(
    const idSPObject* const object, const idBounds* const suppliedBounds) const {
    if (suppliedBounds != nullptr) {
        return suppliedBounds;
    }
    if (traceModelCache == nullptr) {
        return nullptr;
    }
    const idTraceModelCache::trmCache_t* const entry =
        traceModelCache->GetEntry(object->traceModelIndex);
    return entry != nullptr && entry->trm != nullptr
        ? &entry->trm->bounds
        : nullptr;
}

void idEffectPhysicsBroadPhase::AddObject(idSPObject* const object,
    const idVec3& origin, const idMat3& axis, const idBounds* const bounds) {
    const idBounds* const localBounds = ResolveBounds(object, bounds);
    if (localBounds == nullptr) {
        return;
    }

    idBounds transformedBounds;
    transformedBounds.FromTransformedBounds(*localBounds, origin, axis);
    object->origin = origin;
    object->axis = axis;
    object->absBounds.SetBounds(transformedBounds);

    int slot = 0;
    while (slot < objects.Num() && objects[slot] != nullptr) {
        ++slot;
    }
    if (slot == objects.Num()) {
        object->id = objects.Append(object);
    } else {
        object->id = slot;
        objects[slot] = object;
    }
    RebuildBroadPhase();
}

void idEffectPhysicsBroadPhase::RemoveObject(idSPObject* const object) {
    if (object == nullptr || object->id < 0 || object->id >= objects.Num() ||
        objects[object->id] != object) {
        return;
    }
    objects[object->id] = nullptr;
    object->id = -1;
    object->overlap.Clear();
    for (int side = 0; side < 2; ++side) {
        for (int axis = 0; axis < 3; ++axis) {
            object->index[side][axis] = -1;
        }
    }
    RebuildBroadPhase();
}

void idEffectPhysicsBroadPhase::RebuildBroadPhase() {
    for (idList<idSPMarker, 59>& axisMarkers : markers) {
        axisMarkers.Clear();
    }
    for (int index = 0; index < objects.Num(); ++index) {
        idSPObject* const object = objects[index];
        if (object == nullptr) {
            continue;
        }
        object->overlap.Clear();
        if (object->motion.worldCollisionOnly) {
            continue;
        }
        for (int axis = 0; axis < 3; ++axis) {
            idSPMarker minimum = {
                object->absBounds.b[0][axis],
                static_cast<unsigned short>(object->id)};
            idSPMarker maximum = {
                object->absBounds.b[1][axis],
                static_cast<unsigned short>(object->id | 0x8000)};
            markers[axis].Append(minimum);
            markers[axis].Append(maximum);
        }
    }

    for (int axis = 0; axis < 3; ++axis) {
        idList<idSPMarker, 59>& axisMarkers = markers[axis];
        std::sort(axisMarkers.Ptr(), axisMarkers.Ptr() + axisMarkers.Num(),
            [](const idSPMarker& left, const idSPMarker& right) {
                if (left.value != right.value) {
                    return left.value < right.value;
                }
                return left.data < right.data;
            });
        for (int markerIndex = 0; markerIndex < axisMarkers.Num();
             ++markerIndex) {
            const unsigned short data = axisMarkers[markerIndex].data;
            const int objectIndex = data & 0x7FFF;
            if (objectIndex < objects.Num() && objects[objectIndex] != nullptr) {
                objects[objectIndex]->index[data >> 15][axis] = markerIndex;
            }
        }
    }

    for (int first = 0; first < objects.Num(); ++first) {
        idSPObject* const firstObject = objects[first];
        if (firstObject == nullptr || firstObject->motion.worldCollisionOnly) {
            continue;
        }
        for (int second = first + 1; second < objects.Num(); ++second) {
            idSPObject* const secondObject = objects[second];
            if (secondObject == nullptr ||
                secondObject->motion.worldCollisionOnly ||
                !firstObject->absBounds.IntersectsBounds(
                    secondObject->absBounds)) {
                continue;
            }
            firstObject->overlap.Append(static_cast<short>(second));
            secondObject->overlap.Append(static_cast<short>(first));
        }
    }
}

void idEffectPhysicsBroadPhase::MoveObject(idSPObject* const object) {
    (void)object;
    RebuildBroadPhase();
}

void idEffectPhysicsBroadPhase::SetObjectPosition(idSPObject* const object,
    const idVec3& origin, const idMat3& axis, const idBounds* const bounds) {
    const idBounds* const localBounds = ResolveBounds(object, bounds);
    if (localBounds == nullptr) {
        return;
    }

    idBounds transformedBounds;
    transformedBounds.FromTransformedBounds(*localBounds, origin, axis);
    object->absBounds.SetBounds(transformedBounds);
    object->origin = origin;
    object->axis = axis;
    if (!object->motion.worldCollisionOnly) {
        MoveObject(object);
    }
    object->motion.valid = false;
    object->query.offset = 0;
}

void idEffectPhysicsBroadPhase::ApplyMotion(idSPObject* const object,
    const idVec3& translation, const idRotation& rotation) {
    const idBounds* const localBounds = ResolveBounds(object, nullptr);
    if (localBounds == nullptr) {
        return;
    }

    idBounds startBounds;
    startBounds.FromTransformedBounds(*localBounds, object->origin,
        object->axis);
    idMat3 endAxis = object->axis;
    rotation.RotateAxis(endAxis);
    idBounds endBounds;
    endBounds.FromTransformedBounds(*localBounds,
        object->origin + translation, endAxis);

    idBounds motionBounds;
    for (int axis = 0; axis < 3; ++axis) {
        motionBounds[0][axis] = (std::min)(
            startBounds[0][axis], endBounds[0][axis]) - 1.0f;
        motionBounds[1][axis] = (std::max)(
            startBounds[1][axis], endBounds[1][axis]) + 1.0f;
    }
    object->absBounds.SetBounds(motionBounds);
    if (!object->motion.worldCollisionOnly) {
        MoveObject(object);
    }

    object->motion.valid = true;
    object->motion.translation = translation;
    object->motion.rotationVec = rotation.vec;
    object->motion.rotationAngle = rotation.angle;
}

int idEffectPhysicsBroadPhase::GetPositionedModels(
    const idSPObject* const object, idPositionedCollisionModel* const models,
    const int maxModels) const {
    if (traceModelCache == nullptr) {
        return 0;
    }

    int count = 0;
    for (int index = 0; index < object->overlap.Num() && count < maxModels;
         ++index) {
        const int objectIndex = object->overlap[index];
        if (objectIndex < 0 || objectIndex >= objects.Num()) {
            continue;
        }
        const idSPObject* const other = objects[objectIndex];
        if (other == nullptr || other->traceModelIndex == -1 ||
            other->motion.ignore) {
            continue;
        }
        const idTraceModelCache::trmCache_t* const entry =
            traceModelCache->GetEntry(other->traceModelIndex);
        if (entry == nullptr || entry->collisionModel == nullptr) {
            continue;
        }

        idPositionedCollisionModel& model = models[count++];
        model.model = entry->collisionModel;
        model.modelJoints = nullptr;
        model.modelOrigin = other->origin;
        model.modelAxis = other->axis;
        model.modelEntityNum = 0x1FFF;
        model.modelPhysicsId = other->id;
        model.modelBodyId = 0;
        model.modelContentsOverride = other->clipMask;
        model.modelQuery = other->query;
    }
    return count;
}

void idEffectPhysicsBroadPhase::SubmitQueries(
    const bool worldCollisionModelOnly) {
    if (traceModelCache == nullptr || clip == nullptr) {
        return;
    }

    idPositionedCollisionModel models[128]{};
    for (int index = 0; index < objects.Num(); ++index) {
        idSPObject* const object = objects[index];
        if (object == nullptr || !object->motion.valid) {
            continue;
        }
        const idTraceModelCache::trmCache_t* const entry =
            traceModelCache->GetEntry(object->traceModelIndex);
        if (entry == nullptr || entry->trm == nullptr) {
            object->motion.valid = false;
            continue;
        }
        const int numModels = object->motion.worldCollisionOnly
            ? 0
            : GetPositionedModels(object, models, 128);
        object->query = GameLib_SubmitEffectPhysicsMotion(
            clip, *entry->trm, *object, models, numModels,
            worldCollisionModelOnly);
        object->motion.valid = false;
    }
}

bool idEffectPhysicsBroadPhase::GetMotionResult(trace_t* const result,
    idSPObject* const object) {
    const bool available = GameLib_GetEffectPhysicsMotionResult(
        object->query, *result);
    object->origin = result->endpos;
    object->axis = result->endAxis;
    object->axis.OrthoNormalizeSelf();
    return available;
}
