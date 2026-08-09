#include "gamelib/physics/physics_ai.h"

#include "gamelib/physics/clipmodel.h"
#include "idlib/geometry/tracemodel.h"
#include "idlib/math/rotation.h"

#include <algorithm>
#include <cmath>
#include <cstring>

bool GameLib_GetMasterPhysicsTransform(idPhysicsCallbacks* callbacks,
    idVec3& origin, idMat3& axis);
void GameLib_NotifyPhysicsActivated(idPhysicsCallbacks* callbacks,
    int physicsId);
void GameLib_NotifyPhysicsDeactivated(idPhysicsCallbacks* callbacks,
    int physicsId);
void GameLib_NotifyPhysicsCollision(idPhysicsCallbacks* callbacks,
    int physicsId, const trace_t& collision, const idVec3& velocity);

namespace {

const idVec3 kAIZeroVector(0.0f, 0.0f, 0.0f);
const idMat3 kAIIdentityAxis(1.0f);

float AxisYaw(const idMat3& axis) {
    return std::atan2(axis[0].y, axis[0].x) * 57.29577951308232f;
}

void ProjectOntoPlane(idVec3& vector, const idVec3& normal,
        const float overBounce = 1.0f) {
    if (normal.LengthSqr() <= 1.0e-12f) return;
    vector = vector - normal * (vector.Dot(normal) * overBounce);
}

} // namespace

idPhysics_AI::idPhysics_AI()
    : idPhysics_Actor()
    , current{}
    , saved{}
    , stepMoveQuery{0}
    , contactsQuery{0}
    , lastCollisionNormal(0.0f, 0.0f, 0.0f)
    , lastCollisionPoint(0.0f, 0.0f, 0.0f)
    , stuckCollisionNormal(0.0f, 0.0f, 0.0f)
    , stuckCollisionPoint(0.0f, 0.0f, 0.0f)
    , clipModel_standing(nullptr)
    , clipModel_crouched(nullptr)
    , maxStepHeight(18.0f)
    , minFloorCosine(0.70710677f)
    , maxDropVelocity(-500.0f)
    , heightCrouched(48.0f)
    , movementType(AI_MOVE_WALKING)
    , noImpact(false)
    , masterControlledVelocity(false)
    , swimmer(false)
    , crouched(false)
    , canSetCrouchedPhysics(false) {
    type = PHYSICS_AI;
    current.atRest = -1;
    saved = current;
}

idPhysics_AI::~idPhysics_AI() {
    UnlinkClip();
    if (clipModel_crouched != nullptr
            && clipModel_crouched != clipModel_standing)
        clipModel_crouched->Delete();
    if (clipModel_standing != nullptr) clipModel_standing->Delete();
    clipModel_standing = nullptr;
    clipModel_crouched = nullptr;
    clipModels[0] = nullptr;
}

void idPhysics_AI::SetClipModel(idClipModel* const model,
        const float density, const int id, const bool freeOld) {
    if (id != 0) {
        idPhysics_Actor::SetClipModel(model, density, id, freeOld);
        return;
    }
    if (freeOld) {
        if (clipModel_crouched != nullptr
                && clipModel_crouched != clipModel_standing)
            clipModel_crouched->Delete();
        if (clipModel_standing != nullptr && clipModel_standing != model)
            clipModel_standing->Delete();
    }
    clipModel_standing = model;
    clipModel_crouched = nullptr;
    clipModels[0] = nullptr;
    if (model != nullptr && clip != nullptr) {
        idBounds crouchedBounds = model->GetBounds();
        crouchedBounds[1].z = heightCrouched;
        if (crouchedBounds[1].z < crouchedBounds[0].z)
            crouchedBounds[1].z = crouchedBounds[0].z;
        idTraceModel crouchedTrace{};
        crouchedTrace.SetupBox(crouchedBounds);
        clipModel_crouched = new idClipModel(clip, &crouchedTrace, -1,
            nullptr);
        clipModel_crouched->SetContents(model->GetContents());
    }
    idPhysics_Actor::SetClipModel(model, density, 0, false);
    current.worldOrigin = model != nullptr ? model->GetOrigin()
        : kAIZeroVector;
    current.localOrigin = current.worldOrigin;
    LinkClip(current.worldOrigin, model != nullptr ? model->GetAxis()
        : kAIIdentityAxis);
}

void idPhysics_AI::SetContents(const int contents, const int id) {
    if (id <= 0) {
        if (clipModel_standing != nullptr)
            clipModel_standing->SetContents(contents);
        if (clipModel_crouched != nullptr)
            clipModel_crouched->SetContents(contents);
    } else {
        idPhysics_Actor::SetContents(contents, id);
    }
}

void idPhysics_AI::SetOrigin(const idVec3* const newOrigin, int) {
    if (newOrigin == nullptr) return;
    stepMoveQuery.index = 0;
    const idMat3 axis = clipModels[0] != nullptr
        ? clipModels[0]->GetAxis() : clipModelAxis;
    LinkClip(*newOrigin, axis);
    if (hasMaster && callbacks != nullptr) {
        idVec3 masterOrigin;
        idMat3 masterAxis;
        if (GameLib_GetMasterPhysicsTransform(callbacks, masterOrigin,
                masterAxis))
            current.localOrigin = masterAxis.Transpose()
                * (*newOrigin - masterOrigin);
    } else {
        current.localOrigin = *newOrigin;
    }
    Activate();
}

void idPhysics_AI::SetAxis(const idMat3* const newAxis, int) {
    if (newAxis == nullptr) return;
    stepMoveQuery.index = 0;
    LinkClip(current.worldOrigin, *newAxis);
    Activate();
}

void idPhysics_AI::Translate(const idVec3* const translation, int) {
    if (translation == nullptr) return;
    ResolveCollisions();
    SetOrigin(&(current.worldOrigin = current.worldOrigin + *translation), 0);
}

void idPhysics_AI::Rotate(const idRotation* const rotation, int) {
    if (rotation == nullptr) return;
    ResolveCollisions();
    current.worldOrigin = *rotation * current.worldOrigin;
    const idMat3 axis = (clipModels[0] != nullptr
        ? clipModels[0]->GetAxis() : clipModelAxis) * rotation->ToMat3();
    LinkClip(current.worldOrigin, axis);
    current.localOrigin = *rotation * current.localOrigin;
    Activate();
}

const idVec3* idPhysics_AI::GetLocalOrigin(int) {
    return &current.localOrigin;
}
const idMat3* idPhysics_AI::GetLocalAxis(int) {
    return clipModels[0] != nullptr ? &clipModels[0]->GetAxis()
        : &kAIIdentityAxis;
}

void idPhysics_AI::SetLinearVelocity(const idVec3* const velocity, int) {
    if (velocity == nullptr) return;
    current.velocity = *velocity;
    Activate();
}
void idPhysics_AI::SetAngularVelocity(const idVec3*, int) {}
idVec3* idPhysics_AI::GetLinearVelocity(idVec3* const result, int) {
    if (result != nullptr) *result = current.velocity;
    return result;
}
idVec3* idPhysics_AI::GetAngularVelocity(idVec3* const result, int) {
    if (result != nullptr) result->Zero();
    return result;
}
void idPhysics_AI::SetWaterEntNum(int) {}
int idPhysics_AI::GetWaterEntNum() { return -1; }
void idPhysics_AI::SetWaterSurfaceWrldHeight(float) {}
float idPhysics_AI::GetWaterSurfaceWrldHeight() { return 0.0f; }

void idPhysics_AI::GetImpactInfo(int, const idVec3*,
        impactInfo_t* const info) {
    if (info == nullptr) return;
    info->Zero();
    info->invMass = invMass;
    info->velocity = current.velocity;
}

void idPhysics_AI::ApplyImpulse(int, const idVec3*,
        const idVec3* const impulse) {
    if (noImpact || impulse == nullptr) return;
    if (swimmer && std::fabs(impulse->z) >= impulse->Length() - 1.0e-5f)
        current.velocity.z += impulse->z * invMass * 1000.0f;
    else
        current.velocity = current.velocity + *impulse * invMass;
    const float speed = current.velocity.Length();
    if (speed > 2000.0f) current.velocity = current.velocity
        * (2000.0f / speed);
    Activate();
}

void idPhysics_AI::ApplyForce(int id, const idVec3* point,
        const idVec3* force) {
    ApplyImpulse(id, point, force);
}

void idPhysics_AI::Activate() {
    current.atRest = -1;
    if (callbacks != nullptr)
        GameLib_NotifyPhysicsActivated(callbacks, GetPhysicsId());
}
void idPhysics_AI::PutToRest() {
    current.atRest = 1;
    current.velocity.Zero();
}
bool idPhysics_AI::IsAtRest() { return current.atRest >= 0; }

void idPhysics_AI::SaveState() {
    saved = current;
    if (clipModels[0] != nullptr) saved.worldOrigin = clipModels[0]->GetOrigin();
}
void idPhysics_AI::RestoreState() {
    current = saved;
    const idMat3 axis = clipModels[0] != nullptr
        ? clipModels[0]->GetAxis() : clipModelAxis;
    LinkClip(current.worldOrigin, axis);
}

void idPhysics_AI::ResolveCollisions() {
    lastCollisionNormal.Zero();
    lastCollisionPoint.Zero();
    ClearContacts();
    current.onGround = false;
    idClipModel* const model = clipModels[0];
    if (model == nullptr) return;
    AddGroundContacts(model, 12);
    if (contacts.Num() == 0) return;
    idVec3 normal;
    normal.Zero();
    for (int index = 0; index < contacts.Num(); ++index) {
        normal = normal + contacts[index].normal;
        UpdateCollisionResidency(contacts[index]);
        if (contacts[index].normal.Dot(gravityNormal) < -minFloorCosine)
            current.onGround = true;
    }
    normal.NormalizeFast();
    lastCollisionNormal = normal;
    lastCollisionPoint = contacts[0].point;
    if (normal.LengthSqr() > 0.0f
            && std::fabs(normal.Dot(gravityNormal)) < 0.9999f) {
        stuckCollisionNormal = normal;
        stuckCollisionPoint = lastCollisionPoint;
    }
}

void idPhysics_AI::Evolve(const float timeStep) {
    idClipModel* const model = clipModels[0];
    if (model == nullptr || clip == nullptr || timeStep <= 0.0f) return;
    float stepDown = 0.0f;
    if (movementType == AI_MOVE_FLYING) {
        stepDown = maxStepHeight;
    } else if (movementType == AI_MOVE_DROPPING) {
        current.velocity = current.velocity + gravityVector * timeStep;
        if (current.velocity.z < maxDropVelocity)
            current.velocity.z = maxDropVelocity;
        stepDown = maxStepHeight;
    } else if (current.onGround
            && (!swimmer || GetWaterLevel(0) <= 0.0f)) {
        ProjectOntoPlane(current.velocity, gravityNormal);
        stepDown = maxStepHeight * 2.0f;
    } else {
        current.velocity = current.velocity + gravityVector * timeStep;
        stepDown = maxStepHeight * 2.0f;
    }
    if (swimmer && GetWaterLevel(0) > 0.0f) {
        const float damping = (std::max)(0.0f, 1.0f
            - GetWaterViscosity(0) * GetWaterLevel(0) * timeStep);
        current.velocity = current.velocity * damping;
    }
    ProjectOntoPlane(current.velocity, lastCollisionNormal, 1.001f);
    const idVec3 start = model->GetOrigin();
    const idVec3 end = start + current.velocity * timeStep;
    trace_t collision{};
    collision.fraction = 1.0f;
    collision.endpos = end;
    collision.endAxis = model->GetAxis();
    contactsResult_t contactResults{};
    stepMoveQuery = clip->StepMoveContacts(&collision, &contactResults,
        start, end, gravityNormal, maxStepHeight, stepDown, model,
        model->GetAxis(), clipMasks[0], GetEntityNumber(), false,
        "idPhysics_AI::Evolve");
    current.worldOrigin = collision.endpos;
    LinkClip(current.worldOrigin, collision.endAxis);
    ClearContacts();
    const int count = (std::min)(contactResults.numContacts, 12);
    for (int index = 0; index < count; ++index) {
        contacts.Append(contactResults.contacts[index]);
        UpdateCollisionResidency(contactResults.contacts[index]);
    }
    AddContactPhysicsForContacts();
    lastCollisionNormal = collision.c.normal;
    lastCollisionPoint = collision.c.point;
    current.onGround = false;
    for (int index = 0; index < contacts.Num(); ++index)
        if (contacts[index].normal.Dot(gravityNormal) < -minFloorCosine)
            current.onGround = true;
    if (collision.fraction < 1.0f) {
        ProjectOntoPlane(current.velocity, collision.c.normal, 1.001f);
        if (callbacks != nullptr)
            GameLib_NotifyPhysicsCollision(callbacks, GetPhysicsId(),
                collision, current.velocity);
    }
}

bool idPhysics_AI::Evaluate(const int timeStepMSec, int) {
    RememberHistorySample();
    idClipModel* desired = crouched && canSetCrouchedPhysics
        ? clipModel_crouched : clipModel_standing;
    if (desired != nullptr && desired != clipModels[0]) {
        const idVec3 origin = current.worldOrigin;
        const idMat3 axis = clipModels[0] != nullptr
            ? clipModels[0]->GetAxis() : clipModelAxis;
        if (clipModels[0] != nullptr) clipModels[0]->Unlink();
        clipModels[0] = desired;
        LinkClip(origin, axis);
    }
    if (hasMaster && callbacks != nullptr) {
        idVec3 masterOrigin;
        idMat3 masterAxis;
        if (!GameLib_GetMasterPhysicsTransform(callbacks, masterOrigin,
                masterAxis)) return false;
        const idVec3 oldOrigin = current.worldOrigin;
        current.worldOrigin = masterOrigin + masterAxis * current.localOrigin;
        const idMat3 axis = clipModels[0] != nullptr
            ? clipModels[0]->GetAxis() : clipModelAxis;
        LinkClip(current.worldOrigin, axis);
        const float seconds = timeStepMSec * 0.001f;
        if (seconds > 0.0f && masterControlledVelocity)
            current.velocity = (current.worldOrigin - oldOrigin)
                * (1.0f / seconds);
        masterDeltaYaw = AxisYaw(masterAxis) - masterYaw;
        masterYaw += masterDeltaYaw;
        return (current.worldOrigin - oldOrigin).LengthSqr() != 0.0f;
    }
    if (IsAtRest()) return false;
    ResolveCollisions();
    Evolve(timeStepMSec * 0.001f);
    if (IsOutsideWorld() && callbacks != nullptr)
        GameLib_NotifyPhysicsDeactivated(callbacks, GetPhysicsId());
    return true;
}

void idPhysics_AI::UpdateTime(int) {}
void idPhysics_AI::SetPushed(const int deltaTime) {
    if (deltaTime <= 0) {
        current.pushVelocity.Zero();
        return;
    }
    current.pushVelocity = (current.worldOrigin - saved.worldOrigin)
        * (1000.0f / static_cast<float>(deltaTime));
}
idVec3* idPhysics_AI::GetPushedLinearVelocity(idVec3* const result, int) {
    if (result != nullptr) *result = current.pushVelocity;
    return result;
}
idVec3* idPhysics_AI::GetPushedAngularVelocity(idVec3* const result, int) {
    if (result != nullptr) result->Zero();
    return result;
}

void idPhysics_AI::SetMaster(const bool enable,
        const idVec3* const masterOrigin, const idMat3* const masterAxis,
        bindFlags_t) {
    stepMoveQuery.index = 0;
    if (enable && masterOrigin != nullptr && masterAxis != nullptr) {
        if (!hasMaster) {
            current.localOrigin = masterAxis->Transpose()
                * (current.worldOrigin - *masterOrigin);
            masterYaw = AxisYaw(*masterAxis);
        }
        hasMaster = true;
        ClearContacts();
    } else if (hasMaster) {
        hasMaster = false;
        Activate();
    }
}

void idPhysics_AI::SetLocalOrigin(const idVec3* const newOrigin, int) {
    if (newOrigin == nullptr) return;
    stepMoveQuery.index = 0;
    current.localOrigin = *newOrigin;
    if (hasMaster && callbacks != nullptr) {
        idVec3 masterOrigin;
        idMat3 masterAxis;
        if (GameLib_GetMasterPhysicsTransform(callbacks, masterOrigin,
                masterAxis))
            LinkClip(masterOrigin + masterAxis * *newOrigin,
                clipModels[0] != nullptr ? clipModels[0]->GetAxis()
                    : clipModelAxis);
    } else {
        LinkClip(*newOrigin, clipModels[0] != nullptr
            ? clipModels[0]->GetAxis() : clipModelAxis);
    }
    Activate();
}

void idPhysics_AI::SetLocalAxis(const idMat3* const newAxis, int) {
    if (newAxis == nullptr) return;
    idMat3 worldAxis = *newAxis;
    if (hasMaster && callbacks != nullptr) {
        idVec3 masterOrigin;
        idMat3 masterAxis;
        if (GameLib_GetMasterPhysicsTransform(callbacks, masterOrigin,
                masterAxis)) worldAxis *= masterAxis;
    }
    LinkClip(current.worldOrigin, worldAxis);
    Activate();
}

int idPhysics_AI::GetBlockingEntityNum() {
    return contacts.Num() != 0 ? contacts[0].entityNum : 0x1FFF;
}
int idPhysics_AI::GetLinearEndTime() { return 0; }
int idPhysics_AI::GetAngularEndTime() { return 0; }
bool idPhysics_AI::IsOutsideWorld() {
    return idPhysics_DynamicBase::IsOutsideWorld();
}
const idMat3* idPhysics_AI::GetGravityAxis() { return &clipModelAxis; }
void idPhysics_AI::DisableClip(const actorClipModel_t type_) {
    idPhysics_Actor::DisableClip(type_);
}
void idPhysics_AI::EnableClip(const actorClipModel_t type_) {
    idPhysics_Actor::EnableClip(type_);
}
void idPhysics_AI::LinkClip(const idVec3& origin, const idMat3& axis) {
    current.worldOrigin = origin;
    idPhysics_Actor::LinkClip(origin, axis);
}
