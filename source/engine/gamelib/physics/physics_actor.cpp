#include "gamelib/physics/physics_actor.h"

#include "gamelib/physics/clip.h"
#include "gamelib/physics/clipmodel.h"

#include <algorithm>
#include <cmath>
#include <cstring>

int GameLib_GetPhysicsCurrentTime(const idPhysics* physics);

namespace {

const idBounds kActorZeroBounds{{idVec3(0.0f, 0.0f, 0.0f),
    idVec3(0.0f, 0.0f, 0.0f)}};
const idVec3 kActorZeroOrigin(0.0f, 0.0f, 0.0f);
const idMat3 kActorIdentityAxis(1.0f);

int ClampClipIndex(const int id) {
    return id >= 0 && id < idPhysics_Actor::ACTORCLIP_MAX ? id : 0;
}

} // namespace

idPhysics_Actor::idPhysics_Actor()
    : idPhysics_DynamicBase()
    , clipModels{nullptr, nullptr}
    , clipMasks{0, 0}
    , clipModelAxis(1.0f)
    , mass(100.0f)
    , invMass(0.01f)
    , hasMaster(false)
    , masterYaw(0.0f)
    , masterDeltaYaw(0.0f)
    , wasHistoryInitialized(false)
    , lastHistorySaveTime(0)
    , originHistory{}
    , yawHistory{} {
}

idPhysics_Actor::~idPhysics_Actor() {
    UnlinkClip();
    clipModels[0] = nullptr;
    clipModels[1] = nullptr;
}

void idPhysics_Actor::SetClipModel(idClipModel* const model,
    const float density, const int id, const bool freeOld) {
    const int index = ClampClipIndex(id);
    if (clipModels[index] != nullptr && clipModels[index] != model &&
        freeOld) {
        clipModels[index]->Delete();
    }
    clipModels[index] = model;
    if (model != nullptr) {
        if (density > 0.0f && index == ACTORCLIP_DEFAULT) {
            float modelMass = 0.0f;
            idVec3 center;
            idMat3 inertia;
            model->GetMassProperties(density, modelMass, center, inertia);
            if (modelMass > 0.0f) SetMass(modelMass, index);
        }
        model->Link(GetEntityNumber(), GetEntityNumber(), index,
            model->GetOrigin(), clipModelAxis);
    }
}

idClipModel* idPhysics_Actor::GetClipModel(const int id) {
    return clipModels[ClampClipIndex(id)];
}

int idPhysics_Actor::GetNumClipModels() {
    return (clipModels[0] != nullptr ? 1 : 0) +
        (clipModels[1] != nullptr ? 1 : 0);
}

void idPhysics_Actor::SetMass(const float newMass, const int id) {
    (void)id;
    mass = (std::max)(1.0e-6f, newMass);
    invMass = 1.0f / mass;
}
float idPhysics_Actor::GetMass(int) { return mass; }

void idPhysics_Actor::SetContents(const int contents, const int id) {
    idClipModel* const model = clipModels[ClampClipIndex(id)];
    if (model != nullptr) model->SetContents(contents);
}
int idPhysics_Actor::GetContents(const int id) {
    idClipModel* const model = clipModels[ClampClipIndex(id)];
    return model != nullptr ? model->GetContents() : 0;
}
void idPhysics_Actor::SetClipMask(const int mask, const int id) {
    clipMasks[ClampClipIndex(id)] = mask;
    if (id <= 0) idPhysics_DynamicBase::SetClipMask(mask, id);
}
int idPhysics_Actor::GetClipMask(const int id) {
    return clipMasks[ClampClipIndex(id)];
}
const idBounds* idPhysics_Actor::GetBounds(const int id) {
    idClipModel* const model = clipModels[ClampClipIndex(id)];
    return model != nullptr ? &model->GetBounds() : &kActorZeroBounds;
}
const idBounds* idPhysics_Actor::GetAbsBounds(const int id) {
    idClipModel* const model = clipModels[ClampClipIndex(id)];
    return model != nullptr ? &model->GetAbsBounds() : &kActorZeroBounds;
}
const idVec3* idPhysics_Actor::GetOrigin(const int id) {
    idClipModel* const model = clipModels[ClampClipIndex(id)];
    return model != nullptr ? &model->GetOrigin() : &kActorZeroOrigin;
}
const idMat3* idPhysics_Actor::GetAxis(const int id) {
    idClipModel* const model = clipModels[ClampClipIndex(id)];
    return model != nullptr ? &model->GetAxis() : &kActorIdentityAxis;
}

void idPhysics_Actor::SetGravity(const idVec3* const gravity) {
    idPhysics_DynamicBase::SetGravity(gravity);
    SetClipModelAxis();
}

bool idPhysics_Actor::IsPushable(int) { return false; }

void idPhysics_Actor::DisableClip() {
    DisableClip(ACTORCLIP_DEFAULT);
    DisableClip(ACTORCLIP_PLAYER);
}
void idPhysics_Actor::EnableClip() {
    EnableClip(ACTORCLIP_DEFAULT);
    EnableClip(ACTORCLIP_PLAYER);
}
void idPhysics_Actor::DisableClip(const actorClipModel_t type_) {
    if (clipModels[type_] != nullptr) clipModels[type_]->Disable();
}
void idPhysics_Actor::EnableClip(const actorClipModel_t type_) {
    if (clipModels[type_] != nullptr) clipModels[type_]->Enable();
}
void idPhysics_Actor::UnlinkClip() {
    for (idClipModel* model : clipModels)
        if (model != nullptr) model->Unlink();
}
void idPhysics_Actor::LinkClip() {
    LinkClip(*GetOrigin(0), clipModelAxis);
}
void idPhysics_Actor::LinkClip(const idVec3& origin,
    const idMat3& axis) {
    for (int index = 0; index < ACTORCLIP_MAX; ++index) {
        if (clipModels[index] != nullptr) {
            clipModels[index]->Link(GetEntityNumber(), GetEntityNumber(),
                index, origin, axis);
        }
    }
}

void idPhysics_Actor::SetClipModelAxis() {
    idVec3 down = gravityNormal;
    if (down.NormalizeFast() == 0.0f) {
        clipModelAxis = idMat3(1.0f);
        return;
    }
    idVec3 right = std::fabs(down.z) < 0.7f
        ? down.Cross(idVec3(0.0f, 0.0f, 1.0f))
        : down.Cross(idVec3(0.0f, 1.0f, 0.0f));
    right.NormalizeFast();
    idVec3 forward = right.Cross(down);
    forward.NormalizeFast();
    clipModelAxis[0] = forward;
    clipModelAxis[1] = right;
    clipModelAxis[2] = -down;
}

bool idPhysics_Actor::EvaluateContacts() {
    ClearContacts();
    for (idClipModel* model : clipModels)
        if (model != nullptr) AddGroundContacts(model, 12 - contacts.Num());
    return contacts.Num() > 0;
}

void idPhysics_Actor::ClipTranslation(trace_t* const results,
    const idVec3* const translation, const idClipModel* const model) {
    idPhysics_DynamicBase::ClipTranslation(results, translation,
        model != nullptr ? model : clipModels[0]);
}

void idPhysics_Actor::ClipRotation(trace_t* const results,
    const idRotation* const rotation, const idClipModel* const model) {
    if (results == nullptr) return;
    const idClipModel* moving = model != nullptr ? model : clipModels[0];
    if (clip == nullptr || moving == nullptr || rotation == nullptr) {
        std::memset(results, 0, sizeof(*results));
        results->fraction = 1.0f;
        return;
    }
    clip->Rotation(results, moving->GetOrigin(), *rotation, moving,
        moving->GetAxis(), clipMasks[0], GetEntityNumber(), false,
        "idPhysics_Actor::ClipRotation");
}

int idPhysics_Actor::ClipContents(const idClipModel* const model,
    const int id) {
    idClipModel* const self = clipModels[ClampClipIndex(id)];
    if (clip == nullptr || model == nullptr || self == nullptr) return 0;
    trace_t result{};
    clip->ContentsModel(result, self->GetOrigin(), self, self->GetAxis(),
        clipMasks[ClampClipIndex(id)], model->GetOrigin(), model,
        model->GetAxis());
    return result.c.contentFlags;
}

float idPhysics_Actor::GetMasterDeltaYaw() const { return masterDeltaYaw; }

void idPhysics_Actor::RememberHistorySample() {
    const int time = GameLib_GetPhysicsCurrentTime(this);
    const idVec3 currentOrigin = *const_cast<idPhysics_Actor*>(this)->GetOrigin(0);
    if (!wasHistoryInitialized) {
        for (int i = 0; i < 16; ++i) {
            originHistory[i] = currentOrigin;
            yawHistory[i] = masterYaw;
        }
        wasHistoryInitialized = true;
    } else {
        for (int i = 15; i > 0; --i) {
            originHistory[i] = originHistory[i - 1];
            yawHistory[i] = yawHistory[i - 1];
        }
        originHistory[0] = currentOrigin;
        yawHistory[0] = masterYaw;
    }
    lastHistorySaveTime = time;
}

idVec3 idPhysics_Actor::GetOriginHistory(const int millisecondsAgo) const {
    if (!wasHistoryInitialized) return kActorZeroOrigin;
    const int sample = (std::max)(0, (std::min)(15,
        (millisecondsAgo + 7) / 16));
    return originHistory[sample];
}

idVec3 idPhysics_Actor::GetVelocityHistory(const int millisecondsAgo) const {
    if (!wasHistoryInitialized) return kActorZeroOrigin;
    const int sample = (std::max)(1, (std::min)(15,
        (millisecondsAgo + 7) / 16));
    return (originHistory[0] - originHistory[sample]) *
        (1000.0f / static_cast<float>(sample * 16));
}
