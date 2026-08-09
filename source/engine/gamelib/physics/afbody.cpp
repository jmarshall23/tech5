#include "gamelib/physics/afbody.h"

#include "gamelib/physics/clipmodel.h"
#include "idlib/lib_print.h"

#include <algorithm>
#include <cstring>

void GameLib_SerializeAFBody(idSerializer* serializer, idAFBody& body);

namespace {

void ZeroState(AFBodyPState_t& state) {
    state.worldOrigin.Zero();
    state.worldAxis = idMat3(1.0f);
    state.atRestOrigin.Zero();
    state.atRestAxis = idMat3(1.0f);
    std::memset(state.spatialVelocity.p, 0, sizeof(state.spatialVelocity.p));
    std::memset(state.externalForce.p, 0, sizeof(state.externalForce.p));
}

} // namespace

idAFBody::idAFBody()
    : name()
    , clipModel(nullptr)
    , children(4)
    , constraints(4)
    , motionQuery{0}
    , inverseWorldSpatialInertia()
    , I()
    , invI()
    , J()
    , s()
    , totalForce()
    , auxForce()
    , acceleration() {
    Init();
}

idAFBody::idAFBody(const char* const bodyName,
    idClipModel* const model, const float density)
    : idAFBody() {
    name.Set(bodyName != nullptr ? bodyName : "noname");
    SetClipModel(model);
    SetDensity(density, idMat3(1.0f));
}

idAFBody::~idAFBody() {
    if (clipModel != nullptr) {
        clipModel->Delete();
        clipModel = nullptr;
    }
    children.Clear();
    constraints.Clear();
    response = nullptr;
    responseIndex = nullptr;
}

void idAFBody::Init() {
    name.Set("noname");
    clipModel = nullptr;
    clipMask = 0;
    linearFrictionWater = -1.0f;
    angularFrictionWater = -1.0f;
    linearFriction = -1.0f;
    angularFriction = -1.0f;
    contactFriction = -1.0f;
    bouncyness = -1.0f;
    frictionDir.Zero();
    contactMotorDir.Zero();
    contactMotorVelocity = 0.0f;
    contactMotorForce = 0.0f;
    mass = 1.0f;
    invMass = 1.0f;
    centerOfMass.Zero();
    inertiaTensor = idMat3(1.0f);
    inverseInertiaTensor = idMat3(1.0f);
    parent = nullptr;
    primaryConstraint = nullptr;
    tree = nullptr;
    std::memset(&fl, 0, sizeof(fl));
    fl.isZero = 1;
    fl.selfCollision = 1;
    ZeroState(current);
    saved = current;
    inverseWorldSpatialInertia.Zero(6, 6);
    I.Zero(6, 6);
    invI.Zero(6, 6);
    J.Zero(6, 6);
    s.Zero();
    totalForce.Zero();
    auxForce.Zero();
    acceleration.Zero();
    response = nullptr;
    responseIndex = nullptr;
    numResponses = 0;
    maxAuxiliaryIndex = 0;
    maxSubTreeAuxiliaryIndex = 0;
}

void idAFBody::SetClipModel(idClipModel* const model) {
    if (clipModel != nullptr && clipModel != model) {
        clipModel->Delete();
    }
    clipModel = model;
}

void idAFBody::SetBouncyness(const float bounce) {
    if (bounce < 0.0f || bounce > 1.0f) {
        idLibPrint::Warning("idAFBody::SetBouncyness: %.1f out of range",
            bounce);
        return;
    }
    bouncyness = bounce;
}

void idAFBody::SetFriction(const float linear, const float angular,
    const float contact) {
    if (linear < 0.0f || linear > 1.0f || angular < 0.0f ||
        angular > 1.0f || contact < 0.0f) {
        idLibPrint::Warning("idAFBody::SetFriction: invalid coefficients");
        return;
    }
    linearFriction = linear;
    angularFriction = angular;
    contactFriction = contact;
    linearFrictionWater = (std::min)(1.0f,
        (std::max)(0.0f, linear * 1.2f));
    angularFrictionWater = (std::min)(1.0f,
        (std::max)(0.0f, angular * 1.2f));
}

void idAFBody::SetDensity(const float density,
    const idMat3& inertiaScale) {
    if (clipModel == nullptr) return;
    clipModel->GetMassProperties(density, mass, centerOfMass,
        inertiaTensor);
    if (mass <= 0.0f) {
        idLibPrint::Warning("idAFBody::SetDensity: invalid mass for '%s'",
            name.c_str());
        mass = 1.0f;
        centerOfMass.Zero();
        inertiaTensor = idMat3(1.0f);
    }
    invMass = 1.0f / mass;
    inertiaTensor *= inertiaScale;
    inverseInertiaTensor = inertiaTensor;
    if (!inverseInertiaTensor.InverseSelf()) {
        inverseInertiaTensor = idMat3(1.0f);
    }
}

void idAFBody::SetFrictionDirection(const idVec3& direction) {
    frictionDir = clipModel != nullptr
        ? clipModel->GetAxis().Transpose() * direction : direction;
    fl.useFrictionDir = 1;
}

bool idAFBody::GetFrictionDirection(idVec3& direction) const {
    if (!fl.useFrictionDir) return false;
    direction = clipModel != nullptr
        ? clipModel->GetAxis() * frictionDir : frictionDir;
    return true;
}

void idAFBody::SetContactMotorDirection(const idVec3& direction) {
    contactMotorDir = clipModel != nullptr
        ? clipModel->GetAxis().Transpose() * direction : direction;
    fl.useContactMotorDir = 1;
}

bool idAFBody::GetContactMotorDirection(idVec3& direction) const {
    if (!fl.useContactMotorDir) return false;
    direction = clipModel != nullptr
        ? clipModel->GetAxis() * contactMotorDir : contactMotorDir;
    return true;
}

idVec3 idAFBody::GetPointVelocity(const idVec3& point) const {
    const idVec3 linear(current.spatialVelocity[0],
        current.spatialVelocity[1], current.spatialVelocity[2]);
    const idVec3 angular(current.spatialVelocity[3],
        current.spatialVelocity[4], current.spatialVelocity[5]);
    const idVec3 origin = clipModel != nullptr
        ? clipModel->GetOrigin() : current.worldOrigin;
    return linear + angular.Cross(point - origin);
}

void idAFBody::AddForce(const idVec3& point, const idVec3& force) {
    current.externalForce[0] += force.x;
    current.externalForce[1] += force.y;
    current.externalForce[2] += force.z;
    const idVec3 origin = clipModel != nullptr
        ? clipModel->GetOrigin() : current.worldOrigin;
    const idVec3 torque = (point - origin).Cross(force);
    current.externalForce[3] += torque.x;
    current.externalForce[4] += torque.y;
    current.externalForce[5] += torque.z;
}

void idAFBody::Serialize(idSerializer* const serializer) {
    if (serializer != nullptr) GameLib_SerializeAFBody(serializer, *this);
}
