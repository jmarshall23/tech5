#include "gamelib/physics/physics_static.h"

#include "gamelib/physics/clip.h"
#include "gamelib/physics/clipmodel.h"
#include "idlib/math/rotation.h"

#include <cstring>

bool GameLib_GetMasterPhysicsTransform(idPhysicsCallbacks* callbacks,
    idVec3& origin, idMat3& axis);
void GameLib_ActivateContactPhysics(idPhysics* physics);

namespace {

const idVec3 kZeroVector(0.0f, 0.0f, 0.0f);
const idVec3 kDownVector(0.0f, 0.0f, -1.0f);
const idMat3 kIdentityAxis(1.0f);
const idBounds kZeroBounds{{idVec3(0.0f, 0.0f, 0.0f),
    idVec3(0.0f, 0.0f, 0.0f)}};

} // namespace

idPhysics_Static::idPhysics_Static()
    : idPhysics()
    , clipModel(nullptr)
    , contactPhysicsIds(4)
    , isOrientated(0)
    , hasMaster(0)
    , reservedFlags(0)
    , current{} {
    type = PHYSICS_STATIC;
    current.worldOrigin.Zero();
    current.worldAxis = idMat3(1.0f);
    current.localOrigin.Zero();
    current.localAxis = idMat3(1.0f);
}

idPhysics_Static::~idPhysics_Static() {
    if (clipModel != nullptr) {
        clipModel->Unlink();
    }
    clipModel = nullptr;
}

void idPhysics_Static::SetClipModel(idClipModel* const model,
    const float density, const int id, const bool freeOld) {
    (void)density;
    if (clipModel != nullptr && clipModel != model && freeOld) {
        clipModel->Delete();
    }
    clipModel = model;
    if (clipModel != nullptr) {
        clipModel->Link(GetEntityNumber(), GetEntityNumber(), id,
            current.worldOrigin, current.worldAxis);
    }
}

idClipModel* idPhysics_Static::GetClipModel(const int id) {
    (void)id;
    return clipModel;
}

int idPhysics_Static::GetNumClipModels() { return clipModel != nullptr; }
void idPhysics_Static::SetMass(float, int) {}
float idPhysics_Static::GetMass(int) { return 0.0f; }

void idPhysics_Static::SetContents(const int contents, const int id) {
    (void)id;
    if (clipModel != nullptr) clipModel->SetContents(contents);
}
int idPhysics_Static::GetContents(const int id) {
    (void)id;
    return clipModel != nullptr ? clipModel->GetContents() : 0;
}
void idPhysics_Static::SetClipMask(int, int) {}
int idPhysics_Static::GetClipMask(int) { return 0; }

const idBounds* idPhysics_Static::GetBounds(const int id) {
    (void)id;
    return clipModel != nullptr ? &clipModel->GetBounds() : &kZeroBounds;
}

const idBounds* idPhysics_Static::GetAbsBounds(const int id) {
    (void)id;
    if (clipModel != nullptr) return &clipModel->GetAbsBounds();
    static idBounds pointBounds;
    pointBounds[0] = current.worldOrigin;
    pointBounds[1] = current.worldOrigin;
    return &pointBounds;
}

void idPhysics_Static::SetOrigin(const idVec3* const origin, const int id) {
    (void)id;
    if (origin == nullptr) return;
    current.worldOrigin = *origin;
    if (!hasMaster) current.localOrigin = *origin;
    if (clipModel != nullptr) {
        clipModel->Link(GetEntityNumber(), GetEntityNumber(),
            clipModel->GetBodyId(), current.worldOrigin, current.worldAxis);
    }
}

void idPhysics_Static::SetAxis(const idMat3* const axis, const int id) {
    (void)id;
    if (axis == nullptr) return;
    current.worldAxis = *axis;
    if (!hasMaster || !isOrientated) current.localAxis = *axis;
    if (clipModel != nullptr) {
        clipModel->Link(GetEntityNumber(), GetEntityNumber(),
            clipModel->GetBodyId(), current.worldOrigin, current.worldAxis);
    }
}

void idPhysics_Static::Translate(const idVec3* const translation,
    const int id) {
    (void)id;
    if (translation == nullptr) return;
    current.worldOrigin = current.worldOrigin + *translation;
    current.localOrigin = current.localOrigin + *translation;
    if (clipModel != nullptr) {
        clipModel->Link(GetEntityNumber(), GetEntityNumber(),
            clipModel->GetBodyId(), current.worldOrigin, current.worldAxis);
    }
}

void idPhysics_Static::Rotate(const idRotation* const rotation,
    const int id) {
    (void)id;
    if (rotation == nullptr) return;
    current.worldOrigin = *rotation * current.worldOrigin;
    current.worldAxis *= rotation->ToMat3();
    current.localAxis *= rotation->ToMat3();
    if (clipModel != nullptr) {
        clipModel->Link(GetEntityNumber(), GetEntityNumber(),
            clipModel->GetBodyId(), current.worldOrigin, current.worldAxis);
    }
}

const idVec3* idPhysics_Static::GetOrigin(int) { return &current.worldOrigin; }
const idMat3* idPhysics_Static::GetAxis(int) { return &current.worldAxis; }
const idVec3* idPhysics_Static::GetLocalOrigin(int) { return &current.localOrigin; }
const idMat3* idPhysics_Static::GetLocalAxis(int) { return &current.localAxis; }
void idPhysics_Static::SetLinearVelocity(const idVec3*, int) {}
void idPhysics_Static::SetAngularVelocity(const idVec3*, int) {}
idVec3* idPhysics_Static::GetLinearVelocity(idVec3* result, int) {
    if (result != nullptr) result->Zero();
    return result;
}
idVec3* idPhysics_Static::GetAngularVelocity(idVec3* result, int) {
    if (result != nullptr) result->Zero();
    return result;
}
void idPhysics_Static::SetGravity(const idVec3*) {}
const idVec3* idPhysics_Static::GetGravity() { return &kZeroVector; }
const idVec3* idPhysics_Static::GetGravityNormal() { return &kDownVector; }
void idPhysics_Static::SetWaterLevel(float, int) {}
float idPhysics_Static::GetWaterLevel(int) { return 0.0f; }
void idPhysics_Static::SetWaterViscosity(float, int) {}
float idPhysics_Static::GetWaterViscosity(int) { return 0.0f; }
void idPhysics_Static::SetWaterEntNum(int) {}
int idPhysics_Static::GetWaterEntNum() { return -1; }
void idPhysics_Static::SetWaterSurfaceWrldHeight(float) {}
float idPhysics_Static::GetWaterSurfaceWrldHeight() { return 0.0f; }

void idPhysics_Static::GetImpactInfo(int, const idVec3*,
    impactInfo_t* const info) {
    if (info != nullptr) info->Zero();
}
void idPhysics_Static::ApplyImpulse(int, const idVec3*, const idVec3*) {}
void idPhysics_Static::ApplyForce(int, const idVec3*, const idVec3*) {}
void idPhysics_Static::Activate() {}
void idPhysics_Static::PutToRest() {}
bool idPhysics_Static::IsAtRest() { return true; }
bool idPhysics_Static::IsPushable(int) { return false; }
void idPhysics_Static::SaveState() {}
void idPhysics_Static::RestoreState() {}

bool idPhysics_Static::Evaluate(int, int) {
    if (!hasMaster || callbacks == nullptr) return false;
    idVec3 masterOrigin;
    idMat3 masterAxis;
    if (!GameLib_GetMasterPhysicsTransform(callbacks, masterOrigin,
        masterAxis)) return false;
    const idVec3 oldOrigin = current.worldOrigin;
    const idMat3 oldAxis = current.worldAxis;
    current.worldOrigin = masterOrigin + masterAxis * current.localOrigin;
    current.worldAxis = isOrientated
        ? current.localAxis * masterAxis : current.localAxis;
    if (clipModel != nullptr) {
        clipModel->Link(GetEntityNumber(), GetEntityNumber(),
            clipModel->GetBodyId(), current.worldOrigin, current.worldAxis);
    }
    return (current.worldOrigin - oldOrigin).LengthSqr() > 0.0f ||
        (current.worldAxis[0] - oldAxis[0]).LengthSqr() > 0.0f ||
        (current.worldAxis[1] - oldAxis[1]).LengthSqr() > 0.0f ||
        (current.worldAxis[2] - oldAxis[2]).LengthSqr() > 0.0f;
}

void idPhysics_Static::UpdateTime(int) {}

void idPhysics_Static::ClipTranslation(trace_t* const results,
    const idVec3* const translation, const idClipModel* const model) {
    if (results == nullptr) return;
    const idClipModel* moving = model != nullptr ? model : clipModel;
    if (clip == nullptr || moving == nullptr || translation == nullptr) {
        std::memset(results, 0, sizeof(*results));
        results->fraction = 1.0f;
        return;
    }
    clip->Translation(results, current.worldOrigin,
        current.worldOrigin + *translation, moving, current.worldAxis, 0,
        GetEntityNumber(), false, "idPhysics_Static::ClipTranslation");
}

void idPhysics_Static::ClipRotation(trace_t* const results,
    const idRotation* const rotation, const idClipModel* const model) {
    if (results == nullptr) return;
    const idClipModel* moving = model != nullptr ? model : clipModel;
    if (clip == nullptr || moving == nullptr || rotation == nullptr) {
        std::memset(results, 0, sizeof(*results));
        results->fraction = 1.0f;
        return;
    }
    clip->Rotation(results, current.worldOrigin, *rotation, moving,
        current.worldAxis, 0, GetEntityNumber(), false,
        "idPhysics_Static::ClipRotation");
}

int idPhysics_Static::ClipContents(const idClipModel* const model, int) {
    if (clip == nullptr || model == nullptr) return 0;
    trace_t result{};
    clip->Contents(&result, current.worldOrigin, model, current.worldAxis,
        0, GetEntityNumber(), "idPhysics_Static::ClipContents");
    return result.c.contentFlags;
}

void idPhysics_Static::DisableClip() { if (clipModel) clipModel->Disable(); }
void idPhysics_Static::EnableClip() { if (clipModel) clipModel->Enable(); }
void idPhysics_Static::UnlinkClip() { if (clipModel) clipModel->Unlink(); }
void idPhysics_Static::LinkClip() {
    if (clipModel) clipModel->Link(GetEntityNumber(), GetEntityNumber(),
        clipModel->GetBodyId(), current.worldOrigin, current.worldAxis);
}
bool idPhysics_Static::EvaluateContacts() { return false; }
int idPhysics_Static::GetNumContacts() { return 0; }
const contactInfo_t* idPhysics_Static::GetContact(int) { return nullptr; }
void idPhysics_Static::ClearContacts() {}

void idPhysics_Static::AddContactPhysics(idPhysics* const physics) {
    if (physics == nullptr || physics == this) return;
    const int physicsId = physics->GetPhysicsId();
    for (int i = 0; i < contactPhysicsIds.Num(); ++i)
        if (contactPhysicsIds[i] == physicsId) return;
    contactPhysicsIds.Append(physicsId);
}
void idPhysics_Static::RemoveContactPhysics(idPhysics* const physics) {
    if (physics == nullptr) return;
    for (int i = contactPhysicsIds.Num() - 1; i >= 0; --i)
        if (contactPhysicsIds[i] == physics->GetPhysicsId())
            contactPhysicsIds.RemoveIndexFast(i);
}
int idPhysics_Static::GetNumContactPhysics() { return contactPhysicsIds.Num(); }
idPhysics* idPhysics_Static::GetContactPhysics(const int index) {
    return index >= 0 && index < contactPhysicsIds.Num()
        ? idPhysics::GetPhysicsForId(contactPhysicsIds[index]) : nullptr;
}
void idPhysics_Static::ActivateContactPhysics() {
    for (int i = contactPhysicsIds.Num() - 1; i >= 0; --i) {
        idPhysics* physics = idPhysics::GetPhysicsForId(contactPhysicsIds[i]);
        if (physics) GameLib_ActivateContactPhysics(physics);
        else contactPhysicsIds.RemoveIndexFast(i);
    }
}
bool idPhysics_Static::HasGroundContacts() { return false; }
bool idPhysics_Static::IsGroundEntity(int) { return false; }
bool idPhysics_Static::IsGroundClipModel(int, int) { return false; }
void idPhysics_Static::SetPushed(int) {}
idVec3* idPhysics_Static::GetPushedLinearVelocity(idVec3* result, int) {
    if (result) result->Zero(); return result;
}
idVec3* idPhysics_Static::GetPushedAngularVelocity(idVec3* result, int) {
    if (result) result->Zero(); return result;
}

void idPhysics_Static::SetMaster(const bool orientated,
    const idVec3* const masterOrigin, const idMat3* const masterAxis,
    const bindFlags_t flags) {
    (void)flags;
    if (masterOrigin != nullptr && masterAxis != nullptr) {
        const idMat3 inverse = masterAxis->Transpose();
        current.localOrigin = inverse *
            (current.worldOrigin - *masterOrigin);
        current.localAxis = orientated
            ? current.worldAxis * inverse : current.worldAxis;
        hasMaster = 1;
        isOrientated = orientated ? 1 : 0;
    } else {
        current.localOrigin = current.worldOrigin;
        current.localAxis = current.worldAxis;
        hasMaster = 0;
        isOrientated = 0;
    }
}
void idPhysics_Static::SetLocalOrigin(const idVec3* origin, int id) {
    if (origin) { current.localOrigin = *origin; Evaluate(0, 0); }
    (void)id;
}
void idPhysics_Static::SetLocalAxis(const idMat3* axis, int id) {
    if (axis) { current.localAxis = *axis; Evaluate(0, 0); }
    (void)id;
}
int idPhysics_Static::GetBlockingEntityNum() { return 0x1FFF; }
int idPhysics_Static::GetLinearEndTime() { return 0; }
int idPhysics_Static::GetAngularEndTime() { return 0; }
