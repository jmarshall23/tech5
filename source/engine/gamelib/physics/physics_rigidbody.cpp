#include "gamelib/physics/physics_rigidbody.h"

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

const idBounds kRigidZeroBounds{{idVec3(0.0f, 0.0f, 0.0f),
    idVec3(0.0f, 0.0f, 0.0f)}};
const idVec3 kRigidZeroVector(0.0f, 0.0f, 0.0f);
const idMat3 kRigidIdentityAxis(1.0f);

idVec3 SpatialLinear(const idVec6& value) {
    return idVec3(value[0], value[1], value[2]);
}
idVec3 SpatialAngular(const idVec6& value) {
    return idVec3(value[3], value[4], value[5]);
}
void SetSpatialLinear(idVec6& value, const idVec3& vector) {
    value[0] = vector.x; value[1] = vector.y; value[2] = vector.z;
}
void SetSpatialAngular(idVec6& value, const idVec3& vector) {
    value[3] = vector.x; value[4] = vector.y; value[5] = vector.z;
}
void ZeroSpatial(idVec6& value) {
    for (int index = 0; index < 6; ++index) value[index] = 0.0f;
}

idMat3 Inverse3x3(const idMat3& matrix) {
    const float determinant =
        matrix[0].x * (matrix[1].y * matrix[2].z
            - matrix[1].z * matrix[2].y)
        - matrix[0].y * (matrix[1].x * matrix[2].z
            - matrix[1].z * matrix[2].x)
        + matrix[0].z * (matrix[1].x * matrix[2].y
            - matrix[1].y * matrix[2].x);
    if (std::fabs(determinant) < 1.0e-12f) return idMat3(1.0f);
    const float inverse = 1.0f / determinant;
    return idMat3(
        (matrix[1].y * matrix[2].z - matrix[1].z * matrix[2].y) * inverse,
        (matrix[0].z * matrix[2].y - matrix[0].y * matrix[2].z) * inverse,
        (matrix[0].y * matrix[1].z - matrix[0].z * matrix[1].y) * inverse,
        (matrix[1].z * matrix[2].x - matrix[1].x * matrix[2].z) * inverse,
        (matrix[0].x * matrix[2].z - matrix[0].z * matrix[2].x) * inverse,
        (matrix[0].z * matrix[1].x - matrix[0].x * matrix[1].z) * inverse,
        (matrix[1].x * matrix[2].y - matrix[1].y * matrix[2].x) * inverse,
        (matrix[0].y * matrix[2].x - matrix[0].x * matrix[2].y) * inverse,
        (matrix[0].x * matrix[1].y - matrix[0].y * matrix[1].x) * inverse);
}

idMat3 WorldInverseInertia(const idPhysics_RigidBody& body) {
    return body.current.worldAxis * body.inverseInertiaTensor
        * body.current.worldAxis.Transpose();
}

} // namespace

idPhysics_RigidBody::idPhysics_RigidBody()
    : idPhysics_DynamicBase()
    , clipModel(nullptr)
    , linearFriction(0.6f)
    , angularFriction(0.6f)
    , contactFriction(0.0f)
    , linearFrictionWater(1.0f)
    , angularFrictionWater(1.0f)
    , bouncyness(0.6f)
    , inertiaScale(1.0f, 1.0f, 1.0f)
    , mass(1.0f)
    , inverseMass(1.0f)
    , centerOfMass(0.0f, 0.0f, 0.0f)
    , inertiaTensor(1.0f)
    , inverseInertiaTensor(1.0f)
    , fl{}
    , current{}
    , saved{}
    , motionQuery{0}
    , lastTimeStep(0.0f) {
    type = PHYSICS_RIGIDBODY;
    idPhysics_DynamicBase::SetClipMask(1, -1);
    current.atRest = -1;
    current.localOrigin.Zero();
    current.localAxis = idMat3(1.0f);
    current.worldOrigin.Zero();
    current.worldAxis = idMat3(1.0f);
    ZeroSpatial(current.spatialVelocity);
    ZeroSpatial(current.externalForce);
    ZeroSpatial(current.pushVelocity);
    saved = current;
}

idPhysics_RigidBody::~idPhysics_RigidBody() {
    if (clipModel != nullptr) clipModel->Unlink();
    clipModel = nullptr;
}

void idPhysics_RigidBody::SetClipModel(idClipModel* const model,
        const float density, int, const bool freeOld) {
    if (clipModel != nullptr && clipModel != model && freeOld)
        clipModel->Delete();
    clipModel = model;
    if (clipModel == nullptr) return;
    current.worldOrigin = clipModel->GetOrigin();
    current.worldAxis = clipModel->GetAxis();
    current.localOrigin = current.worldOrigin;
    current.localAxis = current.worldAxis;
    clipModel->Link(GetEntityNumber(), GetEntityNumber(), 0,
        current.worldOrigin, current.worldAxis);
    idVec3 modelCenter;
    idMat3 modelInertia;
    float modelMass = 0.0f;
    clipModel->GetMassProperties(density, modelMass, modelCenter,
        modelInertia);
    if (modelMass > 0.0f && std::isfinite(modelMass)) {
        mass = modelMass;
        centerOfMass = modelCenter;
        inertiaTensor = modelInertia;
        inertiaTensor[0].x *= inertiaScale.x;
        inertiaTensor[1].y *= inertiaScale.y;
        inertiaTensor[2].z *= inertiaScale.z;
    } else {
        mass = 1.0f;
        centerOfMass.Zero();
        inertiaTensor = idMat3(1.0f);
    }
    inverseMass = 1.0f / mass;
    inverseInertiaTensor = Inverse3x3(inertiaTensor);
    ZeroSpatial(current.spatialVelocity);
}

idClipModel* idPhysics_RigidBody::GetClipModel(int) { return clipModel; }
int idPhysics_RigidBody::GetNumClipModels() { return clipModel != nullptr; }

void idPhysics_RigidBody::SetMass(const float newMass, int) {
    if (newMass <= 0.0f || !std::isfinite(newMass)) return;
    const float scale = newMass / mass;
    for (int row = 0; row < 3; ++row)
        for (int column = 0; column < 3; ++column)
            inertiaTensor[row][column] *= scale;
    mass = newMass;
    inverseMass = 1.0f / mass;
    inverseInertiaTensor = Inverse3x3(inertiaTensor);
}
float idPhysics_RigidBody::GetMass(int) { return mass; }

void idPhysics_RigidBody::SetFriction(const float linear,
        const float angular, const float contact) {
    linearFriction = (std::max)(0.0f, (std::min)(1.0f, linear));
    angularFriction = (std::max)(0.0f, (std::min)(1.0f, angular));
    contactFriction = (std::max)(0.0f, (std::min)(1.0f, contact));
}
void idPhysics_RigidBody::SetWaterFriction(const float linear,
        const float angular) {
    linearFrictionWater = (std::max)(0.0f, (std::min)(1.0f, linear));
    angularFrictionWater = (std::max)(0.0f, (std::min)(1.0f, angular));
}
void idPhysics_RigidBody::SetBouncyness(const float value) {
    bouncyness = (std::max)(0.0f, (std::min)(1.0f, value));
}
void idPhysics_RigidBody::SetInertiaScale(const idVec3& scale) {
    inertiaScale = scale;
}

void idPhysics_RigidBody::SetContents(const int contents, int) {
    if (clipModel != nullptr) clipModel->SetContents(contents);
}
int idPhysics_RigidBody::GetContents(int) {
    return clipModel != nullptr ? clipModel->GetContents() : 0;
}
const idBounds* idPhysics_RigidBody::GetBounds(int) {
    return clipModel != nullptr ? &clipModel->GetBounds() : &kRigidZeroBounds;
}
const idBounds* idPhysics_RigidBody::GetAbsBounds(int) {
    return clipModel != nullptr ? &clipModel->GetAbsBounds() : &kRigidZeroBounds;
}

void idPhysics_RigidBody::SetOrigin(const idVec3* const origin, int) {
    if (origin == nullptr) return;
    current.worldOrigin = *origin;
    if (fl.hasMaster && callbacks != nullptr) {
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
void idPhysics_RigidBody::SetAxis(const idMat3* const axis, int) {
    if (axis == nullptr) return;
    current.worldAxis = *axis;
    if (fl.hasMaster && fl.isOrientated && callbacks != nullptr) {
        idVec3 masterOrigin;
        idMat3 masterAxis;
        if (GameLib_GetMasterPhysicsTransform(callbacks, masterOrigin,
                masterAxis))
            current.localAxis = *axis * masterAxis.Transpose();
    } else {
        current.localAxis = *axis;
    }
    LinkClip();
    Activate();
}
void idPhysics_RigidBody::Translate(const idVec3* const translation, int) {
    if (translation == nullptr) return;
    ResolveCollisions();
    current.worldOrigin = current.worldOrigin + *translation;
    current.localOrigin = current.localOrigin + *translation;
    LinkClip();
    Activate();
}
void idPhysics_RigidBody::Rotate(const idRotation* const rotation, int) {
    if (rotation == nullptr) return;
    ResolveCollisions();
    current.worldOrigin = *rotation * current.worldOrigin;
    current.worldAxis *= rotation->ToMat3();
    current.localOrigin = *rotation * current.localOrigin;
    current.localAxis *= rotation->ToMat3();
    LinkClip();
    Activate();
}
const idVec3* idPhysics_RigidBody::GetOrigin(int) {
    return &current.worldOrigin;
}
const idMat3* idPhysics_RigidBody::GetAxis(int) { return &current.worldAxis; }
const idVec3* idPhysics_RigidBody::GetLocalOrigin(int) {
    return &current.localOrigin;
}
const idMat3* idPhysics_RigidBody::GetLocalAxis(int) {
    return &current.localAxis;
}

void idPhysics_RigidBody::SetLinearVelocity(const idVec3* const value, int) {
    if (value == nullptr) return;
    SetSpatialLinear(current.spatialVelocity, *value);
    Activate();
}
void idPhysics_RigidBody::SetAngularVelocity(const idVec3* const value, int) {
    if (value == nullptr) return;
    SetSpatialAngular(current.spatialVelocity, *value);
    Activate();
}
idVec3* idPhysics_RigidBody::GetLinearVelocity(idVec3* const result, int) {
    if (result != nullptr) *result = SpatialLinear(current.spatialVelocity);
    return result;
}
idVec3* idPhysics_RigidBody::GetAngularVelocity(idVec3* const result, int) {
    if (result != nullptr) *result = SpatialAngular(current.spatialVelocity);
    return result;
}
void idPhysics_RigidBody::SetWaterEntNum(int) {}
int idPhysics_RigidBody::GetWaterEntNum() { return -1; }
void idPhysics_RigidBody::SetWaterSurfaceWrldHeight(float) {}
float idPhysics_RigidBody::GetWaterSurfaceWrldHeight() { return 0.0f; }

void idPhysics_RigidBody::GetImpactInfo(int, const idVec3* const point,
        impactInfo_t* const info) {
    if (info == nullptr) return;
    info->Zero();
    info->invMass = inverseMass;
    info->invInertiaTensor = WorldInverseInertia(*this);
    const idVec3 worldCenter = current.worldOrigin
        + current.worldAxis * centerOfMass;
    info->position = point != nullptr ? *point - worldCenter : kRigidZeroVector;
    info->velocity = SpatialLinear(current.spatialVelocity)
        + SpatialAngular(current.spatialVelocity).Cross(info->position);
}

void idPhysics_RigidBody::ApplyImpulse(int, const idVec3* const point,
        const idVec3* const impulse) {
    if (fl.noImpact || impulse == nullptr) return;
    idVec3 linear = SpatialLinear(current.spatialVelocity)
        + *impulse * inverseMass;
    idVec3 angular = SpatialAngular(current.spatialVelocity);
    if (point != nullptr) {
        const idVec3 center = current.worldOrigin
            + current.worldAxis * centerOfMass;
        angular = angular + WorldInverseInertia(*this)
            * ((*point - center).Cross(*impulse));
    }
    SetSpatialLinear(current.spatialVelocity, linear);
    SetSpatialAngular(current.spatialVelocity, angular);
    CapVelocity();
    Activate();
}
void idPhysics_RigidBody::ApplyForce(int, const idVec3* const point,
        const idVec3* const force) {
    if (force == nullptr) return;
    SetSpatialLinear(current.externalForce,
        SpatialLinear(current.externalForce) + *force);
    if (point != nullptr) {
        const idVec3 center = current.worldOrigin
            + current.worldAxis * centerOfMass;
        SetSpatialAngular(current.externalForce,
            SpatialAngular(current.externalForce)
                + (*point - center).Cross(*force));
    }
    Activate();
}

void idPhysics_RigidBody::Activate() {
    current.atRest = -1;
    if (callbacks != nullptr)
        GameLib_NotifyPhysicsActivated(callbacks, GetPhysicsId());
}
void idPhysics_RigidBody::PutToRest() {
    current.atRest = 1;
    ZeroSpatial(current.spatialVelocity);
    ZeroSpatial(current.externalForce);
}
bool idPhysics_RigidBody::IsAtRest() { return current.atRest >= 0; }
bool idPhysics_RigidBody::IsPushable(const int sourceContentType) {
    return (sourceContentType & fl.noPushMask) == 0;
}
void idPhysics_RigidBody::SaveState() { saved = current; }
void idPhysics_RigidBody::RestoreState() {
    current = saved;
    LinkClip();
}
void idPhysics_RigidBody::UpdateTime(int) {}

void idPhysics_RigidBody::ClipRotation(trace_t* const results,
        const idRotation* const rotation, const idClipModel* const model) {
    if (results == nullptr) return;
    const idClipModel* moving = model != nullptr ? model : clipModel;
    if (clip == nullptr || moving == nullptr || rotation == nullptr) {
        std::memset(results, 0, sizeof(*results));
        results->fraction = 1.0f;
        return;
    }
    clip->Rotation(results, current.worldOrigin, *rotation, moving,
        current.worldAxis, clipMask, GetEntityNumber(), false,
        "idPhysics_RigidBody::ClipRotation");
}
int idPhysics_RigidBody::ClipContents(const idClipModel* const model,
        int queryMask) {
    if (clip == nullptr || clipModel == nullptr) return 0;
    if (queryMask == 0) queryMask = clipMask;
    trace_t result{};
    if (model != nullptr)
        clip->ContentsModel(result, current.worldOrigin, clipModel,
            current.worldAxis, queryMask, model->GetOrigin(), model,
            model->GetAxis());
    else
        clip->Contents(&result, current.worldOrigin, clipModel,
            current.worldAxis, queryMask, GetEntityNumber(),
            "idPhysics_RigidBody::ClipContents");
    return result.c.contentFlags;
}
void idPhysics_RigidBody::DisableClip() {
    if (clipModel != nullptr) clipModel->Disable();
}
void idPhysics_RigidBody::EnableClip() {
    if (clipModel != nullptr) clipModel->Enable();
}
void idPhysics_RigidBody::UnlinkClip() {
    if (clipModel != nullptr) clipModel->Unlink();
}
void idPhysics_RigidBody::LinkClip() {
    if (clipModel != nullptr)
        clipModel->Link(GetEntityNumber(), GetEntityNumber(),
            clipModel->GetBodyId(), current.worldOrigin, current.worldAxis);
}
bool idPhysics_RigidBody::EvaluateContacts() {
    ClearContacts();
    AddGroundContacts(clipModel, 12);
    return contacts.Num() != 0;
}
bool idPhysics_RigidBody::IsGroundClipModel(const int entityNum,
        const int id) {
    return idPhysics_DynamicBase::IsGroundClipModel(entityNum, id);
}

void idPhysics_RigidBody::SetPushed(const int deltaTime) {
    if (deltaTime <= 0) {
        ZeroSpatial(current.pushVelocity);
        return;
    }
    const float scale = 1000.0f / static_cast<float>(deltaTime);
    SetSpatialLinear(current.pushVelocity,
        (current.worldOrigin - saved.worldOrigin) * scale);
    SetSpatialAngular(current.pushVelocity,
        SpatialAngular(current.spatialVelocity));
}
idVec3* idPhysics_RigidBody::GetPushedLinearVelocity(idVec3* const result,
        int) {
    if (result != nullptr) *result = SpatialLinear(current.pushVelocity);
    return result;
}
idVec3* idPhysics_RigidBody::GetPushedAngularVelocity(idVec3* const result,
        int) {
    if (result != nullptr) *result = SpatialAngular(current.pushVelocity);
    return result;
}

void idPhysics_RigidBody::SetMaster(const bool enable,
        const idVec3* const masterOrigin, const idMat3* const masterAxis,
        const bindFlags_t flags) {
    motionQuery.index = 0;
    if (enable && masterOrigin != nullptr && masterAxis != nullptr) {
        if (!fl.hasMaster) {
            current.localOrigin = masterAxis->Transpose()
                * (current.worldOrigin - *masterOrigin);
            current.localAxis = (static_cast<int>(flags) & 1) != 0
                ? current.worldAxis * masterAxis->Transpose()
                : current.worldAxis;
        }
        fl.hasMaster = 1;
        fl.isOrientated = (static_cast<int>(flags) & 1) != 0;
        ClearContacts();
    } else if (fl.hasMaster) {
        fl.hasMaster = 0;
        Activate();
    }
}
void idPhysics_RigidBody::SetLocalOrigin(const idVec3* const origin, int) {
    if (origin == nullptr) return;
    current.localOrigin = *origin;
    if (fl.hasMaster && callbacks != nullptr) {
        idVec3 masterOrigin;
        idMat3 masterAxis;
        if (GameLib_GetMasterPhysicsTransform(callbacks, masterOrigin,
                masterAxis))
            current.worldOrigin = masterOrigin + masterAxis * *origin;
    } else {
        current.worldOrigin = *origin;
    }
    LinkClip();
    Activate();
}
void idPhysics_RigidBody::SetLocalAxis(const idMat3* const axis, int) {
    if (axis == nullptr) return;
    current.localAxis = *axis;
    if (fl.hasMaster && fl.isOrientated && callbacks != nullptr) {
        idVec3 masterOrigin;
        idMat3 masterAxis;
        if (GameLib_GetMasterPhysicsTransform(callbacks, masterOrigin,
                masterAxis)) current.worldAxis = *axis * masterAxis;
    } else {
        current.worldAxis = *axis;
    }
    LinkClip();
    Activate();
}

void idPhysics_RigidBody::CapVelocity() {
    idVec3 linear = SpatialLinear(current.spatialVelocity);
    idVec3 angular = SpatialAngular(current.spatialVelocity);
    const float linearSpeed = linear.Length();
    const float angularSpeed = angular.Length();
    if (linearSpeed > 16000.0f) linear = linear * (16000.0f / linearSpeed);
    if (angularSpeed > 62.831853f)
        angular = angular * (62.831853f / angularSpeed);
    SetSpatialLinear(current.spatialVelocity, linear);
    SetSpatialAngular(current.spatialVelocity, angular);
}

bool idPhysics_RigidBody::TestIfAtRest() {
    const idVec3 linear = SpatialLinear(current.spatialVelocity);
    const idVec3 angular = SpatialAngular(current.spatialVelocity);
    if (linear.LengthSqr() > 4.0f || angular.LengthSqr() > 0.01f)
        return false;
    if (!EvaluateContacts()) return false;
    PutToRest();
    return true;
}

void idPhysics_RigidBody::ResolveCollisions(const trace_t* const collision,
        const contactsResult_t* const contactResults) {
    if (contactResults != nullptr) {
        ClearContacts();
        const int count = (std::min)(contactResults->numContacts, 12);
        for (int index = 0; index < count; ++index) {
            contacts.Append(contactResults->contacts[index]);
            UpdateCollisionResidency(contactResults->contacts[index]);
        }
        AddContactPhysicsForContacts();
    }
    if (collision == nullptr || collision->fraction >= 1.0f) return;
    idVec3 linear = SpatialLinear(current.spatialVelocity);
    const float intoSurface = linear.Dot(collision->c.normal);
    if (intoSurface < 0.0f)
        linear = linear - collision->c.normal
            * ((1.0f + bouncyness) * intoSurface);
    const idVec3 tangent = linear
        - collision->c.normal * linear.Dot(collision->c.normal);
    linear = linear - tangent * contactFriction;
    SetSpatialLinear(current.spatialVelocity, linear);
    if (callbacks != nullptr)
        GameLib_NotifyPhysicsCollision(callbacks, GetPhysicsId(),
            *collision, linear);
}

void idPhysics_RigidBody::Evolve(const float timeStep,
        trace_t* const collisionOverride,
        contactsResult_t* const contactsOverride) {
    if (clipModel == nullptr || clip == nullptr || timeStep <= 0.0f) return;
    idVec3 linear = SpatialLinear(current.spatialVelocity);
    idVec3 angular = SpatialAngular(current.spatialVelocity);
    linear = linear + (gravityVector
        + SpatialLinear(current.externalForce) * inverseMass) * timeStep;
    angular = angular + WorldInverseInertia(*this)
        * SpatialAngular(current.externalForce) * timeStep;
    float linearDrag = linearFriction;
    float angularDrag = angularFriction;
    if (waterLevel > 0.0f) {
        linearDrag += waterLevel * linearFrictionWater;
        angularDrag += waterLevel * angularFrictionWater;
    }
    linear = linear * (std::max)(0.0f, 1.0f - linearDrag * timeStep);
    angular = angular * (std::max)(0.0f, 1.0f - angularDrag * timeStep);
    SetSpatialLinear(current.spatialVelocity, linear);
    SetSpatialAngular(current.spatialVelocity, angular);
    CapVelocity();

    idVec3 angularAxis = angular;
    const float angularSpeed = angularAxis.NormalizeFast();
    const idRotation rotation(current.worldOrigin,
        angularSpeed > 0.0f ? angularAxis : idVec3(0.0f, 0.0f, 1.0f),
        angularSpeed * timeStep * 57.29577951308232f);
    const idVec3 end = current.worldOrigin + linear * timeStep;
    trace_t localCollision{};
    localCollision.fraction = 1.0f;
    localCollision.endpos = end;
    localCollision.endAxis = current.worldAxis * rotation.ToMat3();
    contactsResult_t localContacts{};
    trace_t* collision = collisionOverride != nullptr
        ? collisionOverride : &localCollision;
    contactsResult_t* results = contactsOverride != nullptr
        ? contactsOverride : &localContacts;
    motionQuery = clip->MotionContacts(collision, results,
        current.worldOrigin, end, rotation, 0.25f, clipModel,
        current.worldAxis, clipMask, GetEntityNumber(), false,
        "idPhysics_RigidBody::Evolve");
    current.worldOrigin = collision->endpos;
    current.worldAxis = collision->endAxis;
    LinkClip();
    lastTimeStep = timeStep;
    ResolveCollisions(collision, results);
}

void idPhysics_RigidBody::DropToFloorAndRest() {
    if (!fl.dropToFloor || clipModel == nullptr || clip == nullptr) return;
    fl.dropToFloor = 0;
    trace_t trace{};
    const idVec3 end = current.worldOrigin + gravityNormal * 128.0f;
    clip->Translation(&trace, current.worldOrigin, end, clipModel,
        current.worldAxis, clipMask, GetEntityNumber(), false,
        "idPhysics_RigidBody::DropToFloorAndRest");
    current.worldOrigin = trace.endpos;
    LinkClip();
    EvaluateContacts();
    if (trace.fraction < 1.0f) PutToRest();
}

bool idPhysics_RigidBody::Evaluate(const int timeStepMSec, int) {
    if (fl.hasMaster && callbacks != nullptr) {
        idVec3 masterOrigin;
        idMat3 masterAxis;
        if (!GameLib_GetMasterPhysicsTransform(callbacks, masterOrigin,
                masterAxis)) return false;
        const idVec3 oldOrigin = current.worldOrigin;
        current.worldOrigin = masterOrigin + masterAxis * current.localOrigin;
        current.worldAxis = fl.isOrientated
            ? current.localAxis * masterAxis : current.localAxis;
        LinkClip();
        return (current.worldOrigin - oldOrigin).LengthSqr() != 0.0f;
    }
    DropToFloorAndRest();
    if (IsAtRest()) return false;
    Evolve(timeStepMSec * 0.001f);
    ZeroSpatial(current.externalForce);
    if (IsOutsideWorld()) {
        PutToRest();
        if (callbacks != nullptr)
            GameLib_NotifyPhysicsDeactivated(callbacks, GetPhysicsId());
    } else {
        TestIfAtRest();
    }
    return true;
}

int idPhysics_RigidBody::GetBlockingEntityNum() {
    return contacts.Num() != 0 ? contacts[0].entityNum : 0x1FFF;
}
int idPhysics_RigidBody::GetLinearEndTime() { return 0; }
int idPhysics_RigidBody::GetAngularEndTime() { return 0; }
bool idPhysics_RigidBody::IsOutsideWorld() {
    return idPhysics_DynamicBase::IsOutsideWorld();
}
