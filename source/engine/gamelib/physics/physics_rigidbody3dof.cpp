#include "gamelib/physics/physics_rigidbody3dof.h"

#include "gamelib/physics/clipmodel.h"
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

const idBounds kThreeDofZeroBounds{{idVec3(0.0f, 0.0f, 0.0f),
    idVec3(0.0f, 0.0f, 0.0f)}};
const idVec3 kThreeDofZeroVector(0.0f, 0.0f, 0.0f);
const idMat3 kThreeDofIdentityAxis(1.0f);

float ClampUnit(const float value) {
    return (std::max)(0.0f, (std::min)(1.0f, value));
}

} // namespace

idPhysics_RigidBody3DOF::bodyState_t::bodyState_t()
    : atRest(-1)
    , lastTimeStep(0.0f)
    , localOrigin(0.0f, 0.0f, 0.0f)
    , localAxis(1.0f)
    , linearPushVelocity(0.0f, 0.0f, 0.0f)
    , angularPushVelocity(0.0f, 0.0f, 0.0f)
    , externalForce(0.0f, 0.0f, 0.0f)
    , i{} {
    i.position.Zero();
    i.orientation = idMat3(1.0f);
    i.linearVelocity.Zero();
    i.angularVelocity.Zero();
}

idPhysics_RigidBody3DOF::idPhysics_RigidBody3DOF()
    : idPhysics_DynamicBase()
    , clipModel(nullptr)
    , mass(1.0f)
    , inverseMass(1.0f)
    , linearFriction(1.0f)
    , angularFriction(1.0f)
    , contactFriction(1.0f)
    , linearFrictionWater(1.0f)
    , angularFrictionWater(1.0f)
    , coefficientOfRestitution(1.0f)
    , current()
    , saved()
    , random(0)
    , translationQuery{0}
    , flags{} {
    type = PHYSICS_RIGIDBODY3DOF;
}

idPhysics_RigidBody3DOF::~idPhysics_RigidBody3DOF() {
    if (clipModel != nullptr) clipModel->Unlink();
    clipModel = nullptr;
}

void idPhysics_RigidBody3DOF::SetCoefficientOfRestitution(
        const float coefficient) {
    coefficientOfRestitution = ClampUnit(coefficient);
}
void idPhysics_RigidBody3DOF::SetFriction(const float linear,
        const float angular, const float contact) {
    linearFriction = ClampUnit(linear);
    angularFriction = ClampUnit(angular);
    contactFriction = ClampUnit(contact);
}
void idPhysics_RigidBody3DOF::SetWaterFriction(const float linear,
        const float angular) {
    linearFrictionWater = ClampUnit(linear);
    angularFrictionWater = ClampUnit(angular);
}

void idPhysics_RigidBody3DOF::SetClipModel(idClipModel* const model,
        const float density, int, const bool freeOld) {
    if (clipModel != nullptr && clipModel != model && freeOld)
        clipModel->Delete();
    clipModel = model;
    if (clipModel == nullptr) return;
    current.i.position = clipModel->GetOrigin();
    current.i.orientation = clipModel->GetAxis();
    current.localOrigin = current.i.position;
    current.localAxis = current.i.orientation;
    LinkClip();
    const idBounds& bounds = clipModel->GetBounds();
    const idVec3 size = bounds[1] - bounds[0];
    SetMass(size.x > 0.0f && size.y > 0.0f && size.z > 0.0f
        ? size.x * size.y * size.z * density : 1.0f, 0);
    current.i.linearVelocity.Zero();
    current.i.angularVelocity.Zero();
}
idClipModel* idPhysics_RigidBody3DOF::GetClipModel(int) {
    return clipModel;
}
int idPhysics_RigidBody3DOF::GetNumClipModels() {
    return clipModel != nullptr;
}
void idPhysics_RigidBody3DOF::SetMass(const float newMass, int) {
    mass = newMass > 0.0f && std::isfinite(newMass) ? newMass : 1.0f;
    inverseMass = 1.0f / mass;
}
float idPhysics_RigidBody3DOF::GetMass(int) { return mass; }
void idPhysics_RigidBody3DOF::SetContents(const int contents, int) {
    if (clipModel != nullptr) clipModel->SetContents(contents);
}
int idPhysics_RigidBody3DOF::GetContents(int) {
    return clipModel != nullptr ? clipModel->GetContents() : 0;
}
const idBounds* idPhysics_RigidBody3DOF::GetBounds(int) {
    return clipModel != nullptr ? &clipModel->GetBounds()
        : &kThreeDofZeroBounds;
}
const idBounds* idPhysics_RigidBody3DOF::GetAbsBounds(int) {
    return clipModel != nullptr ? &clipModel->GetAbsBounds()
        : &kThreeDofZeroBounds;
}

void idPhysics_RigidBody3DOF::SetOrigin(const idVec3* const origin, int) {
    if (origin == nullptr) return;
    current.i.position = *origin;
    if (flags.hasMaster && callbacks != nullptr) {
        idVec3 masterOrigin;
        idMat3 masterAxis;
        if (GameLib_GetMasterPhysicsTransform(callbacks, masterOrigin,
                masterAxis))
            current.localOrigin = masterAxis.Transpose()
                * (*origin - masterOrigin);
    } else {
        current.localOrigin = *origin;
    }
    LinkClip();
    Activate();
}
void idPhysics_RigidBody3DOF::SetAxis(const idMat3* const axis, int) {
    if (axis == nullptr) return;
    current.i.orientation = *axis;
    current.localAxis = *axis;
    LinkClip();
    Activate();
}
void idPhysics_RigidBody3DOF::Translate(const idVec3* const translation,
        int) {
    if (translation == nullptr) return;
    current.i.position = current.i.position + *translation;
    current.localOrigin = current.localOrigin + *translation;
    LinkClip();
    Activate();
}
void idPhysics_RigidBody3DOF::Rotate(const idRotation* const rotation, int) {
    if (rotation == nullptr) return;
    current.i.position = *rotation * current.i.position;
    current.i.orientation *= rotation->ToMat3();
    current.localOrigin = *rotation * current.localOrigin;
    current.localAxis *= rotation->ToMat3();
    LinkClip();
    Activate();
}
const idVec3* idPhysics_RigidBody3DOF::GetOrigin(int) {
    return &current.i.position;
}
const idMat3* idPhysics_RigidBody3DOF::GetAxis(int) {
    return &current.i.orientation;
}
const idVec3* idPhysics_RigidBody3DOF::GetLocalOrigin(int) {
    return &current.localOrigin;
}
const idMat3* idPhysics_RigidBody3DOF::GetLocalAxis(int) {
    return &current.localAxis;
}
void idPhysics_RigidBody3DOF::SetLinearVelocity(const idVec3* const value,
        int) {
    if (value == nullptr) return;
    current.i.linearVelocity = *value;
    Activate();
}
void idPhysics_RigidBody3DOF::SetAngularVelocity(const idVec3* const value,
        int) {
    if (value == nullptr) return;
    current.i.angularVelocity = *value;
    Activate();
}
idVec3* idPhysics_RigidBody3DOF::GetLinearVelocity(idVec3* const result,
        int) {
    if (result != nullptr) *result = current.i.linearVelocity;
    return result;
}
idVec3* idPhysics_RigidBody3DOF::GetAngularVelocity(idVec3* const result,
        int) {
    if (result != nullptr) *result = current.i.angularVelocity;
    return result;
}
void idPhysics_RigidBody3DOF::SetWaterEntNum(int) {}
int idPhysics_RigidBody3DOF::GetWaterEntNum() { return -1; }
void idPhysics_RigidBody3DOF::SetWaterSurfaceWrldHeight(float) {}
float idPhysics_RigidBody3DOF::GetWaterSurfaceWrldHeight() { return 0.0f; }

void idPhysics_RigidBody3DOF::GetImpactInfo(int,
        const idVec3* const point, impactInfo_t* const info) {
    if (info == nullptr) return;
    info->Zero();
    info->invMass = inverseMass;
    info->position = point != nullptr
        ? *point - current.i.position : kThreeDofZeroVector;
    info->velocity = current.i.linearVelocity
        + current.i.angularVelocity.Cross(info->position);
}
void idPhysics_RigidBody3DOF::ApplyImpulse(int,
        const idVec3* const point, const idVec3* const impulse) {
    if (flags.noImpact || impulse == nullptr) return;
    current.i.linearVelocity = current.i.linearVelocity
        + *impulse * inverseMass;
    if (point != nullptr)
        current.i.angularVelocity = current.i.angularVelocity
            + (*point - current.i.position).Cross(*impulse) * inverseMass;
    Activate();
}
void idPhysics_RigidBody3DOF::ApplyForce(int,
        const idVec3*, const idVec3* const force) {
    if (force == nullptr) return;
    current.externalForce = current.externalForce + *force * inverseMass;
    Activate();
}
void idPhysics_RigidBody3DOF::Activate() {
    current.atRest = -1;
    if (callbacks != nullptr)
        GameLib_NotifyPhysicsActivated(callbacks, GetPhysicsId());
}
void idPhysics_RigidBody3DOF::PutToRest() {
    current.atRest = 1;
    current.i.linearVelocity.Zero();
    current.i.angularVelocity.Zero();
    current.externalForce.Zero();
}
bool idPhysics_RigidBody3DOF::IsAtRest() { return current.atRest >= 0; }
bool idPhysics_RigidBody3DOF::IsPushable(int) { return true; }
void idPhysics_RigidBody3DOF::SaveState() { saved = current; }
void idPhysics_RigidBody3DOF::RestoreState() {
    current = saved;
    LinkClip();
}
void idPhysics_RigidBody3DOF::UpdateTime(int) {}

void idPhysics_RigidBody3DOF::ClipTranslation(trace_t* const results,
        const idVec3* const translation, const idClipModel* const model) {
    idPhysics_DynamicBase::ClipTranslation(results, translation,
        model != nullptr ? model : clipModel);
}
void idPhysics_RigidBody3DOF::ClipRotation(trace_t* const results,
        const idRotation* const rotation, const idClipModel* const model) {
    if (results == nullptr) return;
    const idClipModel* moving = model != nullptr ? model : clipModel;
    if (clip == nullptr || moving == nullptr || rotation == nullptr) {
        std::memset(results, 0, sizeof(*results));
        results->fraction = 1.0f;
        return;
    }
    clip->Rotation(results, current.i.position, *rotation, moving,
        current.i.orientation, clipMask, GetEntityNumber(), false,
        "idPhysics_RigidBody3DOF::ClipRotation");
}
int idPhysics_RigidBody3DOF::ClipContents(const idClipModel* const model,
        int queryMask) {
    if (clip == nullptr || clipModel == nullptr) return 0;
    if (queryMask == 0) queryMask = clipMask;
    trace_t result{};
    if (model != nullptr)
        clip->ContentsModel(result, current.i.position, clipModel,
            current.i.orientation, queryMask, model->GetOrigin(), model,
            model->GetAxis());
    else
        clip->Contents(&result, current.i.position, clipModel,
            current.i.orientation, queryMask, GetEntityNumber(),
            "idPhysics_RigidBody3DOF::ClipContents");
    return result.c.contentFlags;
}
void idPhysics_RigidBody3DOF::DisableClip() {
    if (clipModel != nullptr) clipModel->Disable();
}
void idPhysics_RigidBody3DOF::EnableClip() {
    if (clipModel != nullptr) clipModel->Enable();
}
void idPhysics_RigidBody3DOF::UnlinkClip() {
    if (clipModel != nullptr) clipModel->Unlink();
}
void idPhysics_RigidBody3DOF::LinkClip() {
    if (clipModel != nullptr)
        clipModel->Link(GetEntityNumber(), GetEntityNumber(),
            clipModel->GetBodyId(), current.i.position,
            current.i.orientation);
}
bool idPhysics_RigidBody3DOF::EvaluateContacts() {
    ClearContacts();
    AddGroundContacts(clipModel, 12);
    return contacts.Num() != 0;
}
void idPhysics_RigidBody3DOF::SetPushed(const int deltaTime) {
    if (deltaTime <= 0) {
        current.linearPushVelocity.Zero();
        current.angularPushVelocity.Zero();
        return;
    }
    current.linearPushVelocity = (current.i.position - saved.i.position)
        * (1000.0f / static_cast<float>(deltaTime));
    current.angularPushVelocity = current.i.angularVelocity;
}
idVec3* idPhysics_RigidBody3DOF::GetPushedLinearVelocity(
        idVec3* const result, int) {
    if (result != nullptr) *result = current.linearPushVelocity;
    return result;
}
idVec3* idPhysics_RigidBody3DOF::GetPushedAngularVelocity(
        idVec3* const result, int) {
    if (result != nullptr) *result = current.angularPushVelocity;
    return result;
}

void idPhysics_RigidBody3DOF::SetMaster(const bool enable,
        const idVec3* const masterOrigin, const idMat3* const masterAxis,
        const bindFlags_t bindFlags) {
    translationQuery.index = 0;
    if (enable && masterOrigin != nullptr && masterAxis != nullptr) {
        if (!flags.hasMaster) {
            current.localOrigin = masterAxis->Transpose()
                * (current.i.position - *masterOrigin);
            current.localAxis = (static_cast<int>(bindFlags) & 1) != 0
                ? current.i.orientation * masterAxis->Transpose()
                : current.i.orientation;
        }
        flags.hasMaster = 1;
        flags.isOriented = (static_cast<int>(bindFlags) & 1) != 0;
        ClearContacts();
    } else if (flags.hasMaster) {
        flags.hasMaster = 0;
        Activate();
    }
}
void idPhysics_RigidBody3DOF::SetLocalOrigin(const idVec3* const origin,
        int) {
    if (origin == nullptr) return;
    current.localOrigin = *origin;
    if (flags.hasMaster && callbacks != nullptr) {
        idVec3 masterOrigin;
        idMat3 masterAxis;
        if (GameLib_GetMasterPhysicsTransform(callbacks, masterOrigin,
                masterAxis))
            current.i.position = masterOrigin + masterAxis * *origin;
    } else {
        current.i.position = *origin;
    }
    LinkClip();
    Activate();
}
void idPhysics_RigidBody3DOF::SetLocalAxis(const idMat3* const axis, int) {
    if (axis == nullptr) return;
    current.localAxis = *axis;
    if (flags.hasMaster && flags.isOriented && callbacks != nullptr) {
        idVec3 masterOrigin;
        idMat3 masterAxis;
        if (GameLib_GetMasterPhysicsTransform(callbacks, masterOrigin,
                masterAxis)) current.i.orientation = *axis * masterAxis;
    } else {
        current.i.orientation = *axis;
    }
    LinkClip();
    Activate();
}

void idPhysics_RigidBody3DOF::Integrate(const float deltaTime,
        const bodyState_t& source, bodyState_t& next) const {
    next = source;
    next.lastTimeStep = deltaTime;
    next.i.position = source.i.position
        + (source.i.linearVelocity + source.externalForce) * deltaTime;
    idVec3 axis = source.i.angularVelocity;
    const float speed = axis.NormalizeFast();
    const idRotation rotation(kThreeDofZeroVector,
        speed > 0.0f ? axis : idVec3(0.0f, 0.0f, 1.0f),
        speed * deltaTime * 57.29577951308232f);
    next.i.orientation *= rotation.ToMat3();
    next.i.linearVelocity = source.i.linearVelocity
        + gravityVector * deltaTime;
    float linearDrag = linearFriction;
    float angularDrag = angularFriction;
    if (waterLevel > 0.0f) {
        linearDrag += waterLevel * linearFrictionWater;
        angularDrag += waterLevel * angularFrictionWater;
    }
    next.i.linearVelocity = next.i.linearVelocity
        * (std::max)(0.0f, 1.0f - linearDrag * deltaTime);
    next.i.angularVelocity = source.i.angularVelocity
        * (std::max)(0.0f, 1.0f - angularDrag * deltaTime);
}

bool idPhysics_RigidBody3DOF::CheckForCollisions(
        const bodyState_t& source, bodyState_t& next,
        trace_t& collision) {
    if (clip == nullptr || clipModel == nullptr) return false;
    idVec3 angularAxis = source.i.angularVelocity;
    const float speed = angularAxis.NormalizeFast();
    const idRotation rotation(source.i.position,
        speed > 0.0f ? angularAxis : idVec3(0.0f, 0.0f, 1.0f),
        speed * next.lastTimeStep * 57.29577951308232f);
    collision = {};
    collision.fraction = 1.0f;
    collision.endpos = next.i.position;
    collision.endAxis = next.i.orientation;
    translationQuery = clip->Motion(&collision, source.i.position,
        next.i.position, rotation, clipModel, source.i.orientation,
        clipMask, GetEntityNumber(), false,
        "idPhysics_RigidBody3DOF::CheckForCollisions");
    next.i.position = collision.endpos;
    next.i.orientation = collision.endAxis;
    return collision.fraction < 1.0f;
}

bool idPhysics_RigidBody3DOF::CollisionImpulse(
        const trace_t& collision, float, bodyState_t& state,
        idVec3& impulse) {
    const float normalSpeed = state.i.linearVelocity.Dot(collision.c.normal);
    if (normalSpeed >= 0.0f) {
        impulse.Zero();
        return false;
    }
    impulse = collision.c.normal
        * (-(1.0f + coefficientOfRestitution) * normalSpeed * mass);
    state.i.linearVelocity = state.i.linearVelocity + impulse * inverseMass;
    const idVec3 tangent = state.i.linearVelocity
        - collision.c.normal * state.i.linearVelocity.Dot(collision.c.normal);
    state.i.linearVelocity = state.i.linearVelocity
        - tangent * contactFriction;
    return true;
}

bool idPhysics_RigidBody3DOF::Evaluate(const int timeStepMSec, int) {
    const float deltaTime = timeStepMSec * 0.001f;
    current.lastTimeStep = deltaTime;
    if (flags.hasMaster && callbacks != nullptr) {
        idVec3 masterOrigin;
        idMat3 masterAxis;
        if (!GameLib_GetMasterPhysicsTransform(callbacks, masterOrigin,
                masterAxis)) return false;
        const idVec3 oldPosition = current.i.position;
        current.i.position = masterOrigin + masterAxis * current.localOrigin;
        current.i.orientation = flags.isOriented
            ? current.localAxis * masterAxis : current.localAxis;
        if (deltaTime > 0.0f)
            current.i.linearVelocity = (current.i.position - oldPosition)
                * (1.0f / deltaTime);
        LinkClip();
        current.externalForce.Zero();
        return (current.i.position - oldPosition).LengthSqr() != 0.0f;
    }
    if (current.atRest >= 0 || deltaTime <= 0.0f) return false;
    if (flags.dropToFloor) {
        flags.dropToFloor = 0;
        trace_t down{};
        const idVec3 end = current.i.position + gravityNormal * 128.0f;
        clip->Translation(&down, current.i.position, end, clipModel,
            current.i.orientation, clipMask, GetEntityNumber(), false,
            "idPhysics_RigidBody3DOF::DropToFloor");
        current.i.position = down.endpos;
        if (down.fraction < 1.0f) PutToRest();
        LinkClip();
        return true;
    }
    bodyState_t next;
    Integrate(deltaTime, current, next);
    trace_t collision{};
    const bool collided = CheckForCollisions(current, next, collision);
    current = next;
    if (collided) {
        idVec3 impulse;
        CollisionImpulse(collision, deltaTime, current, impulse);
        ClearContacts();
        contacts.Append(collision.c);
        UpdateCollisionResidency(collision.c);
        AddContactPhysicsForContacts();
        if (callbacks != nullptr)
            GameLib_NotifyPhysicsCollision(callbacks, GetPhysicsId(),
                collision, current.i.linearVelocity);
        const idVec3 alongGround = current.i.linearVelocity
            - gravityNormal * current.i.linearVelocity.Dot(gravityNormal);
        if (alongGround.Length() <= 10.0f
                && std::fabs(current.i.linearVelocity.Dot(gravityNormal))
                    < 20.0f)
            PutToRest();
    }
    LinkClip();
    current.linearPushVelocity.Zero();
    current.angularPushVelocity.Zero();
    current.externalForce.Zero();
    if (IsOutsideWorld() && callbacks != nullptr)
        GameLib_NotifyPhysicsDeactivated(callbacks, GetPhysicsId());
    return true;
}

int idPhysics_RigidBody3DOF::GetBlockingEntityNum() {
    return contacts.Num() != 0 ? contacts[0].entityNum : 0x1FFF;
}
int idPhysics_RigidBody3DOF::GetLinearEndTime() { return 0; }
int idPhysics_RigidBody3DOF::GetAngularEndTime() { return 0; }
bool idPhysics_RigidBody3DOF::IsOutsideWorld() {
    return idPhysics_DynamicBase::IsOutsideWorld();
}
