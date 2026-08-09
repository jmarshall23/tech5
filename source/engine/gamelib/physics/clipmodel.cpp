#include "gamelib/physics/clipmodel.h"

#include "cm/collisionmodel.h"
#include "cm/collisionmodelmanager.h"
#include "gamelib/aas2/aas2.h"
#include "gamelib/physics/clip.h"
#include "gamelib/physics/tracemodelcache.h"
#include "idlib/geometry/tracemodel.h"
#include "idlib/lib_print.h"

#include <algorithm>

namespace {

void ClearAASLinks(idClipModel& model) {
    for (idAASClipLink*& link : model.aasLinks) link = nullptr;
}

} // namespace

idClipModel::idClipModel() {
    Init(nullptr);
}

idClipModel::idClipModel(idClip* const ownerClip, const char* modelName,
        const idMaterial* const material) {
    Init(ownerClip);
    LoadCollisionModel(modelName, material);
}

idClipModel::idClipModel(idClip* const ownerClip,
        idCollisionModel* const model) {
    Init(ownerClip);
    LoadCollisionModel(model);
}

idClipModel::idClipModel(idClip* const ownerClip,
        const idTraceModel* const traceModel, const int traceModelIndex,
        const idMaterial* const material) {
    Init(ownerClip);
    LoadTraceModel(traceModel, traceModelIndex, material);
}

idClipModel::idClipModel(idClip* const ownerClip,
        idTreeAnimator* const animator) {
    Init(ownerClip);
    LoadAnimator(animator);
}

idClipModel::idClipModel(idClip* const ownerClip,
        const idClipModel& other) {
    Init(ownerClip);
    enabled = other.enabled;
    entityNumber = other.entityNumber;
    ownerNumber = other.ownerNumber;
    physicsId = other.physicsId;
    bodyId = other.bodyId;
    bodyMask = other.bodyMask;
    origin = other.origin;
    axis = other.axis;
    bounds = other.bounds;
    absBounds = other.absBounds;
    contents = other.contents;
    collisionModel = other.collisionModel;
    animatedModel = other.animatedModel;
    if (clip != nullptr && clip->traceModelCache != nullptr) {
        for (int index = 0; index < other.traceModels.Num(); ++index) {
            traceModels.Append(clip->traceModelCache->CopyTraceModel(
                other.traceModels[index]));
        }
    }
}

idClipModel::~idClipModel() {
    Unlink();
    FreeModel();
}

void idClipModel::Init(idClip* const ownerClip) {
    enabled = true;
    deleted = false;
    entityNumber = -1;
    ownerNumber = -1;
    physicsId = 0;
    bodyId = 0;
    bodyMask = -1;
    origin.Zero();
    axis = idMat3(1.0f);
    bounds[0].Zero();
    bounds[1].Zero();
    absBounds = bounds;
    contents = 0;
    collisionModel = nullptr;
    traceModels.Clear();
    animatedModel = nullptr;
    clip = ownerClip;
    clipLinks = nullptr;
    collisionQuery.offset = 0;
    touchCount = 0;
    nextDeleted = nullptr;
    ClearAASLinks(*this);
}

void idClipModel::Delete() {
    if (deleted) return;
    deleted = true;
    if (clip != nullptr) clip->DeleteClipModel(this);
}

idCollisionModel* idClipModel::NoTraceModelWarning() const {
    idLibPrint::Warning("idClipModel::GetCollisionModel: clip model %d on "
        "entity %d is not a collision or trace model", bodyId, entityNumber);
    return nullptr;
}

idCollisionModel* idClipModel::GetCollisionModel() const {
    if (collisionModel != nullptr) return collisionModel;
    if (clip != nullptr && clip->traceModelCache != nullptr
        && traceModels.Num() > 0) {
        const idTraceModelCache::trmCache_t* const entry =
            clip->traceModelCache->GetEntry(traceModels[0]);
        if (entry != nullptr) return entry->collisionModel;
    }
    return NoTraceModelWarning();
}

const idTraceModel* idClipModel::GetTraceModel(const int index) const {
    if (clip == nullptr || clip->traceModelCache == nullptr
        || index < 0 || index >= traceModels.Num()) return nullptr;
    const idTraceModelCache::trmCache_t* const entry =
        clip->traceModelCache->GetEntry(traceModels[index]);
    return entry != nullptr ? entry->trm : nullptr;
}

void idClipModel::GetMassProperties(const float density, float& mass,
        idVec3& centerOfMass, idMat3& inertiaTensor) const {
    mass = 0.0f;
    centerOfMass.Zero();
    inertiaTensor[0].Zero();
    inertiaTensor[1].Zero();
    inertiaTensor[2].Zero();
    if (clip == nullptr || clip->traceModelCache == nullptr) return;
    for (int index = 0; index < traceModels.Num(); ++index) {
        float partMass = 0.0f;
        idVec3 partCenter;
        idMat3 partInertia;
        clip->traceModelCache->GetMassProperties(traceModels[index],
            density, partMass, partCenter, partInertia);
        centerOfMass = centerOfMass + partCenter * partMass;
        mass += partMass;
        for (int row = 0; row < 3; ++row)
            for (int column = 0; column < 3; ++column)
                inertiaTensor[row][column] += partInertia[row][column];
    }
    if (mass > 0.0f) centerOfMass = centerOfMass * (1.0f / mass);
}

void idClipModel::SetContents(const int newContents) {
    if (contents == newContents) return;
    const bool relink = IsLinked();
    if (relink) Unlink();
    contents = newContents;
    if (relink) Link();
}

void idClipModel::FreeModel() {
    if (clip != nullptr && clip->traceModelCache != nullptr) {
        for (int index = 0; index < traceModels.Num(); ++index)
            clip->traceModelCache->FreeTraceModel(traceModels[index]);
    }
    traceModels.ClearFree();
    collisionModel = nullptr;
    animatedModel = nullptr;
}

bool idClipModel::LoadCollisionModel(const char* const modelName,
        const idMaterial*) {
    if (modelName == nullptr || *modelName == '\0') return false;
    LoadCollisionModel(collisionModelManager.LoadModel(modelName));
    return collisionModel != nullptr;
}

void idClipModel::LoadCollisionModel(idCollisionModel* const model) {
    FreeModel();
    collisionModel = model;
    if (model != nullptr) {
        model->GetBounds(bounds);
        model->GetContents(contents);
        absBounds.FromTransformedBounds(bounds, origin, axis);
    }
}

void idClipModel::LoadTraceModel(const idTraceModel* const traceModel,
        const int traceModelIndex, const idMaterial* const material) {
    FreeModel();
    if (traceModel == nullptr || clip == nullptr
        || clip->traceModelCache == nullptr) return;
    const int index = traceModelIndex >= 0
        ? clip->traceModelCache->CopyTraceModel(traceModelIndex)
        : clip->traceModelCache->AllocTraceModel(*traceModel, material);
    traceModels.Append(index);
    bounds = traceModel->bounds;
    absBounds.FromTransformedBounds(bounds, origin, axis);
}

void idClipModel::LoadAnimator(idTreeAnimator* const animator) {
    FreeModel();
    animatedModel = animator;
}

void idClipModel::Serialize(idSerializer&) {
    // The serializer transport lives in network; all recovered clip-model
    // state is held in explicit fields and can be serialized by that layer.
}

void idClipModel::Unlink() {
    for (int aas = 0; aas < 8; ++aas) {
        if (aasLinks[aas] != nullptr && clip != nullptr
            && clip->aases[aas] != nullptr) {
            aasLinks[aas] = clip->aases[aas]->UnLinkClipModel(aasLinks[aas]);
        }
    }
    while (clipLinks != nullptr) {
        clipLink_t* const link = clipLinks;
        clipLinks = link->nextLink;
        if (link->prevInSector != nullptr)
            link->prevInSector->nextInSector = link->nextInSector;
        else if (link->sector != nullptr)
            link->sector->clipLinks = link->nextInSector;
        if (link->nextInSector != nullptr)
            link->nextInSector->prevInSector = link->prevInSector;
        if (clip != nullptr) clip->clipLinkAllocator.Free(link);
    }
}

void idClipModel::Link_r(clipSector_t* const sector) {
    if (sector == nullptr || clip == nullptr) return;
    clipLink_t* const link = clip->clipLinkAllocator.Alloc();
    if (link == nullptr) return;
    link->clipModel = this;
    link->sector = sector;
    link->prevInSector = nullptr;
    link->nextInSector = sector->clipLinks;
    if (sector->clipLinks != nullptr)
        sector->clipLinks->prevInSector = link;
    sector->clipLinks = link;
    link->nextLink = clipLinks;
    clipLinks = link;
}

void idClipModel::Link() {
    if (clip == nullptr || deleted) return;
    Unlink();
    absBounds.FromTransformedBounds(bounds, origin, axis);
    if (!clip->clipSectors.IsEmpty()) Link_r(&clip->clipSectors[0]);
    for (int aas = 0; aas < 8; ++aas) {
        if (clip->aases[aas] != nullptr)
            aasLinks[aas] = clip->aases[aas]->LinkClipModel(this);
    }
}

void idClipModel::Link(const int entityNum, const int ownerNum,
        const int physicsBodyId, const idVec3& newOrigin,
        const idMat3& newAxis) {
    entityNumber = entityNum;
    ownerNumber = ownerNum;
    physicsId = physicsBodyId;
    bodyId = physicsBodyId;
    origin = newOrigin;
    axis = newAxis;
    Link();
}

void idClipModel::Link(const int entityNum, const int ownerNum,
        const int physicsBodyId, const idVec3& newOrigin,
        const idMat3& newAxis, const idBounds& newBounds) {
    bounds = newBounds;
    Link(entityNum, ownerNum, physicsBodyId, newOrigin, newAxis);
}
