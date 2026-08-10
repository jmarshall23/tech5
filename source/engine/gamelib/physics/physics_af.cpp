#include "gamelib/physics/physics_af.h"

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
void GameLib_SerializeAFPhysics(idSerializer* serializer,
    idPhysics_AF& physics);

namespace {

constexpr int ENTITYNUM_NONE = 0x1FFF;
constexpr float RAD2DEG = 57.29577951308232f;
const idVec3 kZeroVector(0.0f, 0.0f, 0.0f);
const idMat3 kIdentityAxis(1.0f);
const idBounds kZeroBounds{{idVec3(0.0f, 0.0f, 0.0f),
    idVec3(0.0f, 0.0f, 0.0f)}};

idAFBody* SelectBody(idList<idAFBody*, 71>& bodies, const int id) {
    if (bodies.Num() == 0) return nullptr;
    if (id < 0) return bodies[0];
    return id < bodies.Num() ? bodies[id] : nullptr;
}

const idAFBody* SelectBody(const idList<idAFBody*, 71>& bodies,
        const int id) {
    if (bodies.Num() == 0) return nullptr;
    if (id < 0) return bodies[0];
    return id < bodies.Num() ? bodies[id] : nullptr;
}

idVec3 LinearVelocity(const idAFBody& body) {
    return idVec3(body.current.spatialVelocity[0],
        body.current.spatialVelocity[1], body.current.spatialVelocity[2]);
}

idVec3 AngularVelocity(const idAFBody& body) {
    return idVec3(body.current.spatialVelocity[3],
        body.current.spatialVelocity[4], body.current.spatialVelocity[5]);
}

void SetLinearVelocity(idAFBody& body, const idVec3& velocity) {
    body.current.spatialVelocity[0] = velocity.x;
    body.current.spatialVelocity[1] = velocity.y;
    body.current.spatialVelocity[2] = velocity.z;
}

void SetAngularVelocity(idAFBody& body, const idVec3& velocity) {
    body.current.spatialVelocity[3] = velocity.x;
    body.current.spatialVelocity[4] = velocity.y;
    body.current.spatialVelocity[5] = velocity.z;
}

void ZeroSpatial(idVec6& vector) {
    for (int i = 0; i < 6; ++i) vector[i] = 0.0f;
}

float RowVelocity(const idAFConstraint& constraint, const int row) {
    float velocity = 0.0f;
    if (constraint.body1 != nullptr) {
        for (int i = 0; i < 6; ++i)
            velocity += constraint.J1(row, i)
                * constraint.body1->current.spatialVelocity[i];
    }
    if (constraint.body2 != nullptr) {
        for (int i = 0; i < 6; ++i)
            velocity += constraint.J2(row, i)
                * constraint.body2->current.spatialVelocity[i];
    }
    return velocity;
}

float RowEffectiveMass(const idAFConstraint& constraint, const int row) {
    float inverseMass = 0.0f;
    const idAFBody* bodyList[2] = {constraint.body1, constraint.body2};
    const idSpatialMat* jacobians[2] = {&constraint.J1, &constraint.J2};
    for (int bodyIndex = 0; bodyIndex < 2; ++bodyIndex) {
        const idAFBody* const body = bodyList[bodyIndex];
        if (body == nullptr) continue;
        const idSpatialMat& jacobian = *jacobians[bodyIndex];
        const idVec3 linear(jacobian(row, 0), jacobian(row, 1),
            jacobian(row, 2));
        const idVec3 angular(jacobian(row, 3), jacobian(row, 4),
            jacobian(row, 5));
        inverseMass += linear.LengthSqr() * body->invMass;
        inverseMass += angular.Dot(body->inverseInertiaTensor * angular);
    }
    return (std::max)(inverseMass, 1.0e-6f);
}

void ApplyConstraintImpulse(idAFBody* const body,
        const idSpatialMat& jacobian, const int row, const float impulse) {
    if (body == nullptr) return;
    idVec3 linear(jacobian(row, 0), jacobian(row, 1), jacobian(row, 2));
    idVec3 angular(jacobian(row, 3), jacobian(row, 4), jacobian(row, 5));
    SetLinearVelocity(*body, LinearVelocity(*body)
        + linear * (impulse * body->invMass));
    SetAngularVelocity(*body, AngularVelocity(*body)
        + body->inverseInertiaTensor * angular * impulse);
}

void SolveConstraintRows(idList<idAFConstraint*, 71>& list,
        const int iterations) {
    for (int iteration = 0; iteration < iterations; ++iteration) {
        for (int index = 0; index < list.Num(); ++index) {
            idAFConstraint* const constraint = list[index];
            if (constraint == nullptr) continue;
            const int rows = constraint->J1.GetNumRows();
            for (int row = 0; row < rows; ++row) {
                float lambda = -(RowVelocity(*constraint, row)
                    + constraint->c1[row])
                    / RowEffectiveMass(*constraint, row);
                const float oldLambda = constraint->lm[row];
                const float next = (std::max)(constraint->lo[row],
                    (std::min)(constraint->hi[row], oldLambda + lambda));
                lambda = next - oldLambda;
                constraint->lm[row] = next;
                ApplyConstraintImpulse(constraint->body1, constraint->J1,
                    row, lambda);
                ApplyConstraintImpulse(constraint->body2, constraint->J2,
                    row, lambda);
            }
        }
    }
}

bool IsDescendantOf(const idAFBody* body, const idAFBody* ancestor) {
    for (const idAFBody* current = body; current != nullptr;
         current = current->parent) {
        if (current == ancestor) return true;
    }
    return false;
}

void ExpandBounds(idBounds& destination, const idBounds& source) {
    for (int axis = 0; axis < 3; ++axis) {
        destination[0][axis] = (std::min)(destination[0][axis],
            source[0][axis]);
        destination[1][axis] = (std::max)(destination[1][axis],
            source[1][axis]);
    }
}

} // namespace

// Constraint code calls through these ownership-boundary functions so the
// circular AF/constraint dependency remains link-clean.
void GameLib_AddAFFrameConstraint(idPhysics_AF* physics,
        idAFConstraint* constraint) {
    if (physics != nullptr) physics->AddFrameConstraint(constraint);
}
float GameLib_GetAFJointFrictionScale(const idPhysics_AF* physics) {
    return physics != nullptr ? physics->GetJointFrictionScale() : 1.0f;
}
float GameLib_GetAFContactFrictionScale(const idPhysics_AF* physics) {
    return physics != nullptr ? physics->GetContactFrictionScale() : 1.0f;
}

idPhysics_AF::idPhysics_AF()
    : idPhysics_DynamicBase()
    , trees(4)
    , bodies(4)
    , constraints(4)
    , primaryConstraints(4)
    , auxiliaryConstraints(4)
    , frameConstraints(4)
    , contactConstraints(4)
    , contactBodies(4)
    , noclipBodies()
    , changedAF(true)
    , linearFriction(0.005f)
    , angularFriction(0.005f)
    , contactFriction(0.8f)
    , bouncyness(0.5f)
    , totalMass(-1.0f)
    , suspendVelocity(10.0f, 15.0f)
    , suspendAcceleration(20.0f, 20.0f)
    , noMoveTime(1.0f)
    , noMoveTranslation(10.0f)
    , noMoveRotation(10.0f)
    , minMoveTime(-1.0f)
    , maxMoveTime(-1.0f)
    , impulseThreshold(1.0f)
    , timeScale(1.0f)
    , timeScaleRampStart(0.0f)
    , timeScaleRampEnd(0.0f)
    , jointFrictionScale(0.0f)
    , jointFrictionDent(0.0f)
    , jointFrictionDentStart(0.0f)
    , jointFrictionDentEnd(0.0f)
    , jointFrictionDentScale(0.0f)
    , contactFrictionScale(0.0f)
    , contactFrictionDent(0.0f)
    , contactFrictionDentStart(0.0f)
    , contactFrictionDentEnd(0.0f)
    , contactFrictionDentScale(0.0f)
    , errorReduction(idFader::FADE_LINEAR, 0.5f)
    , errorReductionMax(idFader::FADE_LINEAR, 0.5f)
    , lcpEpsilon(idFader::FADE_LINEAR, 1.0e-7f)
    , limitErrorReduction(idFader::FADE_LINEAR, 0.3f)
    , limitErrorReductionMax(idFader::FADE_LINEAR, 0.5f)
    , limitLcpEpsilon(idFader::FADE_LINEAR, 1.0e-6f)
    , contactErrorReduction(idFader::FADE_LINEAR, 0.7f)
    , contactErrorReductionMax(idFader::FADE_LINEAR, 0.9f)
    , contactLcpEpsilon(idFader::FADE_LINEAR, 1.0e-6f)
    , universalErrorReduction(idFader::FADE_LINEAR, 0.5f)
    , universalErrorReductionMax(idFader::FADE_LINEAR, 0.5f)
    , universalTorsionLcpEpsilon(idFader::FADE_LINEAR, 1.0e-6f)
    , passEntityNum(ENTITYNUM_NONE)
    , selfCollision(true)
    , comeToRest(true)
    , linearTime(true)
    , noImpact(false)
    , worldConstraintsLocked(false)
    , forcePushable(false)
    , addContactConstraints(true)
    , addGravity(true)
    , masterBody(nullptr)
    , current{}
    , saved{}
    , lastTimeStep(1.0f / 60.0f)
    , endTime(0)
    , timeStep(0.0f)
    , lastImpulse(0.0f, 0.0f, 0.0f)
    , lcp(nullptr) {
    type = PHYSICS_AF;
    current.atRest = false;
    saved = current;
    for (int i = 0; i < 8; ++i) {
        noclipBodies.staticList[i].bodyId = -1;
        noclipBodies.staticList[i].originalClipMask = 0;
        noclipBodies.staticList[i].query.index = 0x100000000ULL;
    }
}

idPhysics_AF::~idPhysics_AF() { Shutdown(); }

void idPhysics_AF::Shutdown() {
    UnlinkClip();
    for (int i = 0; i < contactConstraints.Num(); ++i)
        delete contactConstraints[i];
    contactConstraints.Clear();
    frameConstraints.Clear();
    for (int i = 0; i < constraints.Num(); ++i) delete constraints[i];
    constraints.Clear();
    primaryConstraints.Clear();
    auxiliaryConstraints.Clear();
    for (int i = 0; i < trees.Num(); ++i) delete trees[i];
    trees.Clear();
    for (int i = 0; i < bodies.Num(); ++i) delete bodies[i];
    bodies.Clear();
    contactBodies.Clear();
    noclipBodies.Clear();
    delete lcp;
    lcp = nullptr;
    masterBody = nullptr;
}

void idPhysics_AF::SetSuspendTime(const float minimum,
        const float maximum) { minMoveTime = minimum; maxMoveTime = maximum; }
void idPhysics_AF::SetSuspendTolerance(const float quietTime,
        const float translation, const float rotation) {
    noMoveTime = quietTime;
    noMoveTranslation = translation;
    noMoveRotation = rotation;
}
void idPhysics_AF::SetSuspendSpeed(const idVec2& velocity,
        const idVec2& acceleration) {
    suspendVelocity = velocity;
    suspendAcceleration = acceleration;
}
void idPhysics_AF::SetTimeScaleRamp(const float start, const float end) {
    timeScaleRampStart = start;
    timeScaleRampEnd = end;
}
void idPhysics_AF::SetJointFrictionDent(const float dent,
        const float start, const float end) {
    jointFrictionDent = dent;
    jointFrictionDentStart = start;
    jointFrictionDentEnd = end;
}
void idPhysics_AF::SetContactFrictionDent(const float dent,
        const float start, const float end) {
    contactFrictionDent = dent;
    contactFrictionDentStart = start;
    contactFrictionDentEnd = end;
}
void idPhysics_AF::SetDefaultFriction(const float linear,
        const float angular, const float contact) {
    if (linear < 0.0f || linear > 1.0f || angular < 0.0f
            || angular > 1.0f || contact < 0.0f || contact > 1.0f) return;
    linearFriction = linear;
    angularFriction = angular;
    contactFriction = contact;
}

float idPhysics_AF::GetJointFrictionScale() const {
    float scale = jointFrictionScale > 0.0f ? jointFrictionScale : 1.0f;
    if (current.activateTime >= jointFrictionDentStart
            && current.activateTime <= jointFrictionDentEnd)
        scale *= (std::max)(0.0f, 1.0f - jointFrictionDent);
    return scale;
}
float idPhysics_AF::GetContactFrictionScale() const {
    float scale = contactFrictionScale > 0.0f ? contactFrictionScale : 1.0f;
    if (current.activateTime >= contactFrictionDentStart
            && current.activateTime <= contactFrictionDentEnd)
        scale *= (std::max)(0.0f, 1.0f - contactFrictionDent);
    return scale;
}

void idPhysics_AF::SetClipModel(idClipModel* const model,
        const float density, const int id, const bool freeOld) {
    idAFBody* const body = SelectBody(bodies, id);
    if (body == nullptr) {
        if (model != nullptr && freeOld) model->Delete();
        return;
    }
    if (!freeOld && body->clipModel != nullptr && body->clipModel != model)
        body->clipModel->Unlink();
    body->SetClipModel(model);
    if (density > 0.0f) body->SetDensity(density, kIdentityAxis);
    changedAF = true;
    Activate();
}
idClipModel* idPhysics_AF::GetClipModel(const int id) {
    idAFBody* const body = SelectBody(bodies, id);
    return body != nullptr ? body->clipModel : nullptr;
}
int idPhysics_AF::GetNumClipModels() { return bodies.Num(); }
void idPhysics_AF::SetMass(const float newMass, const int id) {
    idAFBody* const body = SelectBody(bodies, id);
    if (body == nullptr || newMass <= 0.0f) return;
    const float scale = newMass / (std::max)(body->mass, 1.0e-6f);
    body->mass = newMass;
    body->invMass = 1.0f / newMass;
    for (int row = 0; row < 3; ++row)
        for (int column = 0; column < 3; ++column)
            body->inertiaTensor[row][column] *= scale;
    body->inverseInertiaTensor = body->inertiaTensor;
    body->inverseInertiaTensor.InverseSelf();
    totalMass = -1.0f;
}
float idPhysics_AF::GetMass(const int id) {
    if (id >= 0) {
        const idAFBody* const body = SelectBody(bodies, id);
        return body != nullptr ? body->mass : 0.0f;
    }
    if (totalMass < 0.0f) {
        totalMass = 0.0f;
        for (int i = 0; i < bodies.Num(); ++i)
            if (bodies[i] != nullptr) totalMass += bodies[i]->mass;
    }
    return totalMass;
}
void idPhysics_AF::SetContents(const int contents, const int id) {
    if (id >= 0) {
        idClipModel* const model = GetClipModel(id);
        if (model != nullptr) model->SetContents(contents);
        return;
    }
    for (int i = 0; i < bodies.Num(); ++i)
        if (bodies[i] != nullptr && bodies[i]->clipModel != nullptr)
            bodies[i]->clipModel->SetContents(contents);
}
int idPhysics_AF::GetContents(const int id) {
    if (id >= 0) {
        const idClipModel* const model = GetClipModel(id);
        return model != nullptr ? model->GetContents() : 0;
    }
    int contents = 0;
    for (int i = 0; i < bodies.Num(); ++i)
        if (bodies[i] != nullptr && bodies[i]->clipModel != nullptr)
            contents |= bodies[i]->clipModel->GetContents();
    return contents;
}
void idPhysics_AF::SetClipMask(const int mask, const int id) {
    if (id >= 0) {
        idAFBody* const body = SelectBody(bodies, id);
        if (body != nullptr) { body->clipMask = mask; body->fl.clipMaskSet = 1; }
        return;
    }
    clipMask = mask;
    for (int i = 0; i < bodies.Num(); ++i)
        if (bodies[i] != nullptr && !bodies[i]->fl.clipMaskSet)
            bodies[i]->clipMask = mask;
}
int idPhysics_AF::GetClipMask(const int id) {
    const idAFBody* const body = SelectBody(bodies, id);
    return body != nullptr ? body->clipMask : clipMask;
}

const idBounds* idPhysics_AF::GetBounds(const int id) {
    if (id >= 0) {
        const idClipModel* const model = GetClipModel(id);
        return model != nullptr ? &model->GetBounds() : &kZeroBounds;
    }
    static thread_local idBounds bounds;
    bool initialized = false;
    for (int i = 0; i < bodies.Num(); ++i) {
        const idClipModel* const model = bodies[i] != nullptr
            ? bodies[i]->clipModel : nullptr;
        if (model == nullptr) continue;
        if (!initialized) { bounds = model->GetBounds(); initialized = true; }
        else ExpandBounds(bounds, model->GetBounds());
    }
    if (!initialized) bounds = kZeroBounds;
    return &bounds;
}
const idBounds* idPhysics_AF::GetAbsBounds(const int id) {
    if (id >= 0) {
        const idClipModel* const model = GetClipModel(id);
        return model != nullptr ? &model->GetAbsBounds() : &kZeroBounds;
    }
    static thread_local idBounds bounds;
    bool initialized = false;
    for (int i = 0; i < bodies.Num(); ++i) {
        const idClipModel* const model = bodies[i] != nullptr
            ? bodies[i]->clipModel : nullptr;
        if (model == nullptr) continue;
        if (!initialized) { bounds = model->GetAbsBounds(); initialized = true; }
        else ExpandBounds(bounds, model->GetAbsBounds());
    }
    if (!initialized) bounds = kZeroBounds;
    return &bounds;
}

void idPhysics_AF::SetOrigin(const idVec3* const origin, const int id) {
    if (origin == nullptr) return;
    idAFBody* const reference = SelectBody(bodies, id);
    if (reference == nullptr) return;
    const idVec3 delta = *origin - reference->current.worldOrigin;
    Translate(&delta, id);
}
void idPhysics_AF::SetAxis(const idMat3* const axis, const int id) {
    if (axis == nullptr) return;
    idAFBody* const reference = SelectBody(bodies, id);
    if (reference == nullptr) return;
    const idMat3 rotationMatrix = *axis * reference->current.worldAxis.Transpose();
    const idVec3 pivot = reference->current.worldOrigin;
    for (int i = 0; i < bodies.Num(); ++i) {
        idAFBody* const body = bodies[i];
        if (body == nullptr || (id >= 0 && i != id)) continue;
        body->current.worldOrigin = pivot
            + rotationMatrix * (body->current.worldOrigin - pivot);
        body->current.worldAxis = rotationMatrix * body->current.worldAxis;
    }
    UpdateClipModels();
    Activate();
}
void idPhysics_AF::Translate(const idVec3* const translation, const int id) {
    if (translation == nullptr) return;
    for (int i = 0; i < bodies.Num(); ++i) {
        idAFBody* const body = bodies[i];
        if (body == nullptr || (id >= 0 && i != id)) continue;
        body->current.worldOrigin = body->current.worldOrigin + *translation;
    }
    if (id < 0)
        for (int i = 0; i < constraints.Num(); ++i)
            if (constraints[i] != nullptr) constraints[i]->Translate(*translation);
    UpdateClipModels();
    Activate();
}
void idPhysics_AF::Rotate(const idRotation* const rotation, const int id) {
    if (rotation == nullptr) return;
    const idMat3 matrix = rotation->ToMat3();
    for (int i = 0; i < bodies.Num(); ++i) {
        idAFBody* const body = bodies[i];
        if (body == nullptr || (id >= 0 && i != id)) continue;
        body->current.worldOrigin = *rotation * body->current.worldOrigin;
        body->current.worldAxis = matrix * body->current.worldAxis;
    }
    if (id < 0)
        for (int i = 0; i < constraints.Num(); ++i)
            if (constraints[i] != nullptr) constraints[i]->Rotate(*rotation);
    UpdateClipModels();
    Activate();
}
const idVec3* idPhysics_AF::GetOrigin(const int id) {
    const idAFBody* const body = SelectBody(bodies, id);
    return body != nullptr ? &body->current.worldOrigin : &kZeroVector;
}
const idMat3* idPhysics_AF::GetAxis(const int id) {
    const idAFBody* const body = SelectBody(bodies, id);
    return body != nullptr ? &body->current.worldAxis : &kIdentityAxis;
}
const idVec3* idPhysics_AF::GetLocalOrigin(const int id) {
    return GetOrigin(id);
}
const idMat3* idPhysics_AF::GetLocalAxis(const int id) { return GetAxis(id); }

void idPhysics_AF::SetLinearVelocity(const idVec3* const velocity,
        const int id) {
    if (velocity == nullptr) return;
    if (id >= 0) {
        idAFBody* const body = SelectBody(bodies, id);
        if (body != nullptr) ::SetLinearVelocity(*body, *velocity);
    } else {
        for (int i = 0; i < bodies.Num(); ++i)
            if (bodies[i] != nullptr) ::SetLinearVelocity(*bodies[i], *velocity);
    }
    Activate();
}
void idPhysics_AF::SetAngularVelocity(const idVec3* const velocity,
        const int id) {
    if (velocity == nullptr) return;
    if (id >= 0) {
        idAFBody* const body = SelectBody(bodies, id);
        if (body != nullptr) ::SetAngularVelocity(*body, *velocity);
    } else {
        for (int i = 0; i < bodies.Num(); ++i)
            if (bodies[i] != nullptr) ::SetAngularVelocity(*bodies[i], *velocity);
    }
    Activate();
}
idVec3* idPhysics_AF::GetLinearVelocity(idVec3* const result,
        const int id) {
    if (result == nullptr) return nullptr;
    const idAFBody* const body = SelectBody(bodies, id);
    *result = body != nullptr ? LinearVelocity(*body) : kZeroVector;
    return result;
}
idVec3* idPhysics_AF::GetAngularVelocity(idVec3* const result,
        const int id) {
    if (result == nullptr) return nullptr;
    const idAFBody* const body = SelectBody(bodies, id);
    *result = body != nullptr ? AngularVelocity(*body) : kZeroVector;
    return result;
}
void idPhysics_AF::SetWaterEntNum(int) {}
int idPhysics_AF::GetWaterEntNum() { return -1; }
void idPhysics_AF::SetWaterSurfaceWrldHeight(float) {}
float idPhysics_AF::GetWaterSurfaceWrldHeight() { return 0.0f; }

void idPhysics_AF::GetImpactInfo(const int id, const idVec3* const point,
        impactInfo_t* const info) {
    if (info == nullptr) return;
    info->Zero();
    const idAFBody* const body = SelectBody(bodies, id);
    if (body == nullptr) return;
    info->invMass = body->invMass;
    info->invInertiaTensor = body->inverseInertiaTensor;
    info->position = point != nullptr ? *point : body->current.worldOrigin;
    info->velocity = body->GetPointVelocity(info->position);
}
void idPhysics_AF::ApplyImpulse(const int bodyId, const idVec3* const point,
        const idVec3* const impulse) {
    idAFBody* const body = SelectBody(bodies, bodyId);
    if (body == nullptr || impulse == nullptr || noImpact) return;
    const idVec3 applicationPoint = point != nullptr
        ? *point : body->current.worldOrigin;
    ::SetLinearVelocity(*body, LinearVelocity(*body)
        + *impulse * body->invMass);
    const idVec3 torque = (applicationPoint - body->current.worldOrigin)
        .Cross(*impulse);
    ::SetAngularVelocity(*body, AngularVelocity(*body)
        + body->inverseInertiaTensor * torque);
    lastImpulse = *impulse;
    Activate();
}
void idPhysics_AF::ApplyForce(const int bodyId, const idVec3* const point,
        const idVec3* const force) {
    idAFBody* const body = SelectBody(bodies, bodyId);
    if (body == nullptr || force == nullptr) return;
    body->AddForce(point != nullptr ? *point : body->current.worldOrigin,
        *force);
    Activate();
}

void idPhysics_AF::Activate() {
    current.atRest = false;
    current.noMoveTime = 0.0f;
    current.activateTime = 0.0f;
    if (callbacks != nullptr)
        GameLib_NotifyPhysicsActivated(callbacks, GetPhysicsId());
}
void idPhysics_AF::PutToRest() {
    current.atRest = true;
    for (int i = 0; i < bodies.Num(); ++i) {
        if (bodies[i] == nullptr) continue;
        ZeroSpatial(bodies[i]->current.spatialVelocity);
        ZeroSpatial(bodies[i]->current.externalForce);
    }
}
bool idPhysics_AF::IsAtRest() { return current.atRest; }
bool idPhysics_AF::IsPushable(int) {
    return !noImpact && (masterBody == nullptr || forcePushable);
}

void idPhysics_AF::SaveState() {
    saved = current;
    for (int i = 0; i < bodies.Num(); ++i)
        if (bodies[i] != nullptr) bodies[i]->saved = bodies[i]->current;
}
void idPhysics_AF::RestoreState() {
    current = saved;
    for (int i = 0; i < bodies.Num(); ++i)
        if (bodies[i] != nullptr) bodies[i]->current = bodies[i]->saved;
    UpdateClipModels();
}
void idPhysics_AF::UpdateTime(const int newEndTime) { endTime = newEndTime; }

void idPhysics_AF::SetPushed(const int deltaTime) {
    ZeroSpatial(current.pushVelocity);
    if (deltaTime <= 0 || bodies.Num() == 0) return;
    const float scale = 1000.0f / static_cast<float>(deltaTime);
    int count = 0;
    for (int i = 0; i < bodies.Num(); ++i) {
        const idAFBody* const body = bodies[i];
        if (body == nullptr) continue;
        const idVec3 velocity = (body->current.worldOrigin
            - body->saved.worldOrigin) * scale;
        current.pushVelocity[0] += velocity.x;
        current.pushVelocity[1] += velocity.y;
        current.pushVelocity[2] += velocity.z;
        ++count;
    }
    if (count > 0)
        for (int i = 0; i < 3; ++i) current.pushVelocity[i] /= count;
}
idVec3* idPhysics_AF::GetPushedLinearVelocity(idVec3* const result, int) {
    if (result != nullptr) result->Set(current.pushVelocity[0],
        current.pushVelocity[1], current.pushVelocity[2]);
    return result;
}
idVec3* idPhysics_AF::GetPushedAngularVelocity(idVec3* const result, int) {
    if (result != nullptr) result->Set(current.pushVelocity[3],
        current.pushVelocity[4], current.pushVelocity[5]);
    return result;
}
void idPhysics_AF::SetAuxAngularVelocity(const idVec3& angular) {
    current.auxVelocity[3] = angular.x;
    current.auxVelocity[4] = angular.y;
    current.auxVelocity[5] = angular.z;
}

void idPhysics_AF::SetMaster(const bool enable,
        const idVec3* const masterOrigin, const idMat3* const masterAxis,
        bindFlags_t) {
    if (enable && masterOrigin != nullptr && masterAxis != nullptr
            && bodies.Num() > 0) {
        masterBody = bodies[0];
        const idVec3 oldOrigin = masterBody->current.worldOrigin;
        const idMat3 oldAxis = masterBody->current.worldAxis;
        const idMat3 rotation = *masterAxis * oldAxis.Transpose();
        for (int i = 0; i < bodies.Num(); ++i) {
            idAFBody* const body = bodies[i];
            if (body == nullptr) continue;
            body->current.worldOrigin = *masterOrigin
                + rotation * (body->current.worldOrigin - oldOrigin);
            body->current.worldAxis = rotation * body->current.worldAxis;
        }
        worldConstraintsLocked = true;
        UpdateClipModels();
    } else {
        masterBody = nullptr;
        worldConstraintsLocked = false;
        Activate();
    }
}
void idPhysics_AF::SetLocalOrigin(const idVec3* const origin,
        const int id) { SetOrigin(origin, id); }
void idPhysics_AF::SetLocalAxis(const idMat3* const axis,
        const int id) { SetAxis(axis, id); }
int idPhysics_AF::GetBlockingEntityNum() {
    return contacts.Num() > 0 ? contacts[0].entityNum : ENTITYNUM_NONE;
}
int idPhysics_AF::GetLinearEndTime() { return 0; }
int idPhysics_AF::GetAngularEndTime() { return 0; }

void idPhysics_AF::Serialize(idSerializer* const serializer) {
    if (serializer != nullptr) GameLib_SerializeAFPhysics(serializer, *this);
}

void idPhysics_AF::DisableClip() {
    for (int i = 0; i < bodies.Num(); ++i)
        if (bodies[i] != nullptr && bodies[i]->clipModel != nullptr)
            bodies[i]->clipModel->Disable();
}
void idPhysics_AF::EnableClip() {
    for (int i = 0; i < bodies.Num(); ++i)
        if (bodies[i] != nullptr && bodies[i]->clipModel != nullptr)
            bodies[i]->clipModel->Enable();
}
void idPhysics_AF::UnlinkClip() {
    for (int i = 0; i < bodies.Num(); ++i)
        if (bodies[i] != nullptr && bodies[i]->clipModel != nullptr)
            bodies[i]->clipModel->Unlink();
}
void idPhysics_AF::LinkClip() { UpdateClipModels(); }
void idPhysics_AF::UpdateClipModels() {
    for (int i = 0; i < bodies.Num(); ++i) {
        idAFBody* const body = bodies[i];
        if (body == nullptr || body->clipModel == nullptr) continue;
        body->clipModel->Link(GetEntityNumber(), GetEntityNumber(), i,
            body->current.worldOrigin, body->current.worldAxis);
    }
}

void idPhysics_AF::ClipTranslation(trace_t* const result,
        const idVec3* const translation, const idClipModel* const model) {
    if (result == nullptr) return;
    std::memset(result, 0, sizeof(*result));
    result->fraction = 1.0f;
    if (translation == nullptr || clip == nullptr) return;
    for (int i = 0; i < bodies.Num(); ++i) {
        const idAFBody* const body = bodies[i];
        if (body == nullptr || body->clipModel == nullptr) continue;
        trace_t local{};
        local.fraction = 1.0f;
        if (model != nullptr) {
            clip->TranslationModel(local, body->current.worldOrigin,
                body->current.worldOrigin + *translation, body->clipModel,
                body->current.worldAxis, body->clipMask,
                model->GetOrigin(), model, model->GetAxis());
        } else {
            clip->Translation(&local, body->current.worldOrigin,
                body->current.worldOrigin + *translation, body->clipModel,
                body->current.worldAxis, body->clipMask, passEntityNum,
                false, "idPhysics_AF::ClipTranslation");
        }
        if (local.fraction < result->fraction) *result = local;
    }
}
void idPhysics_AF::ClipRotation(trace_t* const result,
        const idRotation* const rotation, const idClipModel* const model) {
    if (result == nullptr) return;
    std::memset(result, 0, sizeof(*result));
    result->fraction = 1.0f;
    if (rotation == nullptr || clip == nullptr) return;
    for (int i = 0; i < bodies.Num(); ++i) {
        const idAFBody* const body = bodies[i];
        if (body == nullptr || body->clipModel == nullptr) continue;
        trace_t local{};
        local.fraction = 1.0f;
        if (model != nullptr) {
            clip->RotationModel(local, body->current.worldOrigin,
                *rotation, body->clipModel, body->current.worldAxis,
                body->clipMask, model->GetOrigin(), model, model->GetAxis());
        } else {
            clip->Rotation(&local, body->current.worldOrigin, *rotation,
                body->clipModel, body->current.worldAxis, body->clipMask,
                passEntityNum, false, "idPhysics_AF::ClipRotation");
        }
        if (local.fraction < result->fraction) *result = local;
    }
}
int idPhysics_AF::ClipContents(const idClipModel* const model,
        const int contentMask) {
    if (clip == nullptr) return 0;
    int contents = 0;
    for (int i = 0; i < bodies.Num(); ++i) {
        const idAFBody* const body = bodies[i];
        if (body == nullptr || body->clipModel == nullptr) continue;
        trace_t local{};
        if (model != nullptr) {
            clip->ContentsModel(local, body->current.worldOrigin,
                body->clipModel, body->current.worldAxis, contentMask,
                model->GetOrigin(), model, model->GetAxis());
        } else {
            clip->Contents(&local, body->current.worldOrigin,
                body->clipModel, body->current.worldAxis, contentMask,
                passEntityNum, "idPhysics_AF::ClipContents");
        }
        contents |= local.c.contentFlags;
    }
    return contents;
}

int idPhysics_AF::AddBody(idAFBody* const body) {
    if (body == nullptr) return -1;
    for (int i = 0; i < bodies.Num(); ++i)
        if (bodies[i] == body) return i;
    if (!body->fl.clipMaskSet) body->clipMask = clipMask;
    if (body->linearFriction < 0.0f) body->linearFriction = linearFriction;
    if (body->angularFriction < 0.0f) body->angularFriction = angularFriction;
    if (body->contactFriction < 0.0f) body->contactFriction = contactFriction;
    if (body->bouncyness < 0.0f) body->bouncyness = bouncyness;
    bodies.Append(body);
    totalMass = -1.0f;
    changedAF = true;
    return bodies.Num() - 1;
}
void idPhysics_AF::ForceBodyId(idAFBody* const body, const int newId) {
    const int oldId = GetBodyId(body);
    if (oldId < 0 || newId < 0 || newId >= bodies.Num()
            || oldId == newId) return;
    idAFBody* const displaced = bodies[newId];
    bodies[newId] = body;
    bodies[oldId] = displaced;
    changedAF = true;
}
int idPhysics_AF::GetBodyId(const idAFBody* const body) const {
    for (int i = 0; i < bodies.Num(); ++i) if (bodies[i] == body) return i;
    return -1;
}
idAFBody* idPhysics_AF::GetBody(const char* const bodyName) const {
    if (bodyName == nullptr) return nullptr;
    for (int i = 0; i < bodies.Num(); ++i)
        if (bodies[i] != nullptr
                && std::strcmp(bodies[i]->name.c_str(), bodyName) == 0)
            return bodies[i];
    return nullptr;
}
idAFBody* idPhysics_AF::GetBody(const int id) const {
    return const_cast<idAFBody*>(SelectBody(bodies, id));
}
idAFConstraint* idPhysics_AF::GetConstraint(
        const char* const constraintName) const {
    if (constraintName == nullptr) return nullptr;
    for (int i = 0; i < constraints.Num(); ++i)
        if (constraints[i] != nullptr
                && std::strcmp(constraints[i]->name.c_str(),
                    constraintName) == 0)
            return constraints[i];
    return nullptr;
}
idAFConstraint* idPhysics_AF::GetConstraint(const int id) const {
    return id >= 0 && id < constraints.Num() ? constraints[id] : nullptr;
}
void idPhysics_AF::AddConstraint(idAFConstraint* const constraint) {
    if (constraint == nullptr) return;
    for (int i = 0; i < constraints.Num(); ++i)
        if (constraints[i] == constraint) return;
    constraint->physics = this;
    constraints.Append(constraint);
    changedAF = true;
}
void idPhysics_AF::DeleteConstraint(const int id) {
    if (id < 0 || id >= constraints.Num()) return;
    idAFConstraint* const constraint = constraints[id];
    constraints.RemoveIndex(id);
    primaryConstraints.Remove(constraint);
    auxiliaryConstraints.Remove(constraint);
    frameConstraints.Remove(constraint);
    delete constraint;
    changedAF = true;
}
void idPhysics_AF::DeleteConstraint(const char* const constraintName) {
    idAFConstraint* const constraint = GetConstraint(constraintName);
    if (constraint == nullptr) return;
    DeleteConstraint(constraints.FindIndex(constraint));
}
void idPhysics_AF::DeleteBody(const int id) {
    if (id < 0 || id >= bodies.Num()) return;
    idAFBody* const body = bodies[id];
    for (int i = constraints.Num() - 1; i >= 0; --i)
        if (constraints[i] != nullptr
                && (constraints[i]->body1 == body
                    || constraints[i]->body2 == body))
            DeleteConstraint(i);
    bodies.RemoveIndex(id);
    delete body;
    totalMass = -1.0f;
    changedAF = true;
}
void idPhysics_AF::AddFrameConstraint(idAFConstraint* const constraint) {
    if (constraint == nullptr) return;
    for (int i = 0; i < frameConstraints.Num(); ++i)
        if (frameConstraints[i] == constraint) return;
    constraint->physics = this;
    constraint->fl.frameConstraint = 1;
    frameConstraints.Append(constraint);
}

int idPhysics_AF::AddNoclipBody(const int bodyId) {
    idAFBody* const body = GetBody(bodyId);
    if (body == nullptr || noclipBodies.Num() >= noclipBodies.Max()) return -1;
    for (int i = 0; i < noclipBodies.Num(); ++i)
        if (noclipBodies[i].bodyId == bodyId) return i;
    noclipBodyInfo_t info{};
    info.bodyId = bodyId;
    info.originalClipMask = body->clipMask;
    info.query.index = 0;
    noclipBodies.Append(info);
    body->clipMask = 0;
    return noclipBodies.Num() - 1;
}
void idPhysics_AF::TestNoclipBodies() {
    if (clip == nullptr) return;
    for (int i = noclipBodies.Num() - 1; i >= 0; --i) {
        noclipBodyInfo_t& info = noclipBodies[i];
        idAFBody* const body = GetBody(info.bodyId);
        if (body == nullptr || body->clipModel == nullptr) {
            noclipBodies.RemoveIndex(i);
            continue;
        }
        trace_t result{};
        info.query = clip->Contents(&result, body->current.worldOrigin,
            body->clipModel, body->current.worldAxis,
            info.originalClipMask, passEntityNum,
            "idPhysics_AF::TestNoclipBodies");
        if (result.c.contentFlags == 0) {
            body->clipMask = info.originalClipMask;
            noclipBodies.RemoveIndex(i);
        }
    }
}

void idPhysics_AF::ApplyFriction(const float step, float) {
    const float jointScale = GetJointFrictionScale();
    for (int i = 0; i < bodies.Num(); ++i) {
        idAFBody* const body = bodies[i];
        if (body == nullptr) continue;
        const float linear = body->linearFriction >= 0.0f
            ? body->linearFriction : linearFriction;
        const float angular = body->angularFriction >= 0.0f
            ? body->angularFriction : angularFriction;
        ::SetLinearVelocity(*body, LinearVelocity(*body)
            * (std::max)(0.0f, 1.0f - linear * step));
        ::SetAngularVelocity(*body, AngularVelocity(*body)
            * (std::max)(0.0f, 1.0f - angular * jointScale * step));
    }
}
void idPhysics_AF::AddGravity() {
    if (!addGravity) return;
    for (int i = 0; i < bodies.Num(); ++i) {
        idAFBody* const body = bodies[i];
        if (body == nullptr) continue;
        body->current.externalForce[0] += gravityVector.x * body->mass;
        body->current.externalForce[1] += gravityVector.y * body->mass;
        body->current.externalForce[2] += gravityVector.z * body->mass;
    }
}

void idPhysics_AF::PrimaryFactor() {
    for (int i = 0; i < trees.Num(); ++i)
        if (trees[i] != nullptr) trees[i]->Factor();
}
void idPhysics_AF::PrimaryForces(const float step) {
    for (int i = 0; i < trees.Num(); ++i)
        if (trees[i] != nullptr) trees[i]->CalculateForces(step);
}
void idPhysics_AF::AuxiliaryForces(float) {
    SolveConstraintRows(auxiliaryConstraints, 8);
    SolveConstraintRows(frameConstraints, 8);
}

void idPhysics_AF::AddFrameConstraints() {
    frameConstraints.Clear();
    const float inverseStep = timeStep > 0.0f ? 1.0f / timeStep : 0.0f;
    for (int i = 0; i < constraints.Num(); ++i)
        if (constraints[i] != nullptr)
            constraints[i]->ApplyFriction(inverseStep);
    for (int i = 0; i < contactConstraints.Num(); ++i)
        if (contactConstraints[i] != nullptr)
            contactConstraints[i]->ApplyFriction(inverseStep);
}
void idPhysics_AF::RemoveFrameConstraints() { frameConstraints.Clear(); }

void idPhysics_AF::EvaluateConstraints(const float step) {
    const float inverseStep = step > 0.0f ? 1.0f / step : 0.0f;
    for (int i = 0; i < primaryConstraints.Num(); ++i)
        if (primaryConstraints[i] != nullptr)
            primaryConstraints[i]->Evaluate(this, inverseStep);
    for (int i = 0; i < auxiliaryConstraints.Num(); ++i)
        if (auxiliaryConstraints[i] != nullptr)
            auxiliaryConstraints[i]->Evaluate(this, inverseStep);
    for (int i = 0; i < contactConstraints.Num(); ++i)
        if (contactConstraints[i] != nullptr)
            contactConstraints[i]->Evaluate(this, inverseStep);
    AddFrameConstraints();
    for (int i = 0; i < frameConstraints.Num(); ++i)
        if (frameConstraints[i] != nullptr
                && frameConstraints[i]->J1.GetNumRows() == 0)
            frameConstraints[i]->Evaluate(this, inverseStep);
    SolveConstraintRows(primaryConstraints, 8);
    SolveConstraintRows(auxiliaryConstraints, 8);
    // Contact rows are kept in their own authoritative list.
    idList<idAFConstraint*, 71> contactRows(4);
    for (int i = 0; i < contactConstraints.Num(); ++i)
        contactRows.Append(contactConstraints[i]);
    SolveConstraintRows(contactRows, 8);
    SolveConstraintRows(frameConstraints, 8);
}

void idPhysics_AF::AddContacts(idAFBody* const body,
        const contactsResult_t& result) {
    if (body == nullptr) return;
    const int count = (std::min)(12, result.numContacts);
    for (int i = 0; i < count; ++i) {
        const contactInfo_t& info = result.contacts[i];
        contacts.Append(info);
        UpdateCollisionResidency(info);
        bool bodyListed = false;
        const int bodyId = GetBodyId(body);
        for (int j = 0; j < contactBodies.Num(); ++j)
            bodyListed |= contactBodies[j] == bodyId;
        if (!bodyListed) contactBodies.Append(bodyId);
        if (!addContactConstraints) continue;
        idAFBody* otherBody = nullptr;
        idPhysics* const otherPhysics = idPhysics::GetPhysicsForId(
            info.physicsId);
        if (otherPhysics == this)
            otherBody = GetBody(info.bodyId);
        idAFConstraint_Contact* const contact =
            new idAFConstraint_Contact();
        contact->physics = this;
        contact->Setup(body, otherBody, info, info.separation,
            timeStep > 0.0f ? 1.0f / timeStep : 0.0f);
        contactConstraints.Append(contact);
    }
}
void idPhysics_AF::SetupContactConstraints(const float step) {
    const float inverseStep = step > 0.0f ? 1.0f / step : 0.0f;
    for (int i = 0; i < contactConstraints.Num(); ++i) {
        idAFConstraint_Contact* const constraint = contactConstraints[i];
        if (constraint != nullptr)
            constraint->Setup(constraint->body1, constraint->body2,
                constraint->contact, constraint->separation, inverseStep);
    }
}

void idPhysics_AF::CollisionImpulse(idAFBody* const body,
        const trace_t& collision, float) {
    if (body == nullptr || collision.fraction >= 1.0f) return;
    idVec3 velocity = body->GetPointVelocity(collision.c.point);
    const float into = velocity.Dot(collision.c.normal);
    if (into >= 0.0f) return;
    const float bounce = body->bouncyness >= 0.0f
        ? body->bouncyness : bouncyness;
    const idVec3 impulse = collision.c.normal
        * (-(1.0f + bounce) * into / (std::max)(body->invMass, 1.0e-6f));
    ApplyImpulse(GetBodyId(body), &collision.c.point, &impulse);
    if (callbacks != nullptr)
        GameLib_NotifyPhysicsCollision(callbacks, GetPhysicsId(),
            collision, velocity);
}

void idPhysics_AF::IssueCollisionQueries() {
    for (int i = 0; i < constraints.Num(); ++i)
        if (constraints[i] != nullptr)
            constraints[i]->IssueCollisionQueries();
}

void idPhysics_AF::EvaluateBodies(const float step) {
    for (int i = 0; i < bodies.Num(); ++i) {
        idAFBody* const body = bodies[i];
        if (body == nullptr) continue;
        idVec3 linear = LinearVelocity(*body);
        idVec3 angular = AngularVelocity(*body);
        linear = linear + idVec3(body->current.externalForce[0],
            body->current.externalForce[1],
            body->current.externalForce[2]) * (body->invMass * step);
        angular = angular + body->inverseInertiaTensor
            * idVec3(body->current.externalForce[3],
                body->current.externalForce[4],
                body->current.externalForce[5]) * step;
        ::SetLinearVelocity(*body, linear);
        ::SetAngularVelocity(*body, angular);
        const idVec3 start = body->current.worldOrigin;
        const idVec3 end = start + linear * step;
        idVec3 angularAxis = angular;
        const float angularSpeed = angularAxis.NormalizeFast();
        idRotation rotation(start, angularSpeed > 0.0f ? angularAxis
            : idVec3(0.0f, 0.0f, 1.0f), angularSpeed * step * RAD2DEG);
        trace_t collision{};
        collision.fraction = 1.0f;
        collision.endpos = end;
        collision.endAxis = rotation.ToMat3() * body->current.worldAxis;
        contactsResult_t contactResult{};
        if (clip != nullptr && body->clipModel != nullptr
                && body->clipMask != 0) {
            body->motionQuery = clip->MotionContacts(&collision,
                &contactResult, start, end, rotation, 0.25f,
                body->clipModel, body->current.worldAxis, body->clipMask,
                passEntityNum, false, "idPhysics_AF::EvaluateBodies");
        }
        body->current.worldOrigin = collision.endpos;
        body->current.worldAxis = collision.endAxis;
        if (contactResult.numContacts > 0) AddContacts(body, contactResult);
        if (collision.fraction < 1.0f)
            CollisionImpulse(body, collision, step);
        ZeroSpatial(body->current.externalForce);
    }
    UpdateClipModels();
}

void idPhysics_AF::ResolveCollisions(float) {
    AddContactPhysicsForContacts();
}

bool idPhysics_AF::EvaluateContacts() {
    ClearContacts();
    for (int i = 0; i < contactConstraints.Num(); ++i)
        delete contactConstraints[i];
    contactConstraints.Clear();
    contactBodies.Clear();
    if (clip == nullptr) return false;
    for (int i = 0; i < bodies.Num(); ++i) {
        idAFBody* const body = bodies[i];
        if (body == nullptr || body->clipModel == nullptr) continue;
        contactsResult_t result{};
        body->motionQuery = clip->Contacts(&result,
            body->current.worldOrigin, gravityNormal, 0.25f,
            body->clipModel, body->current.worldAxis, body->clipMask,
            passEntityNum, "idPhysics_AF::EvaluateContacts");
        AddContacts(body, result);
    }
    AddContactPhysicsForContacts();
    return contacts.Num() > 0;
}

bool idPhysics_AF::TestIfAtRest(const float step) {
    float maximumLinear = 0.0f;
    float maximumAngular = 0.0f;
    float maximumAcceleration = 0.0f;
    for (int i = 0; i < bodies.Num(); ++i) {
        const idAFBody* const body = bodies[i];
        if (body == nullptr) continue;
        maximumLinear = (std::max)(maximumLinear, LinearVelocity(*body).Length());
        maximumAngular = (std::max)(maximumAngular, AngularVelocity(*body).Length());
        maximumAcceleration = (std::max)(maximumAcceleration,
            idVec3(body->acceleration[0], body->acceleration[1],
                body->acceleration[2]).Length());
    }
    const bool quiet = maximumLinear <= suspendVelocity.x
        && maximumAngular <= suspendVelocity.y
        && maximumAcceleration <= (std::max)(suspendAcceleration.x,
            suspendAcceleration.y);
    current.activateTime += step;
    if (quiet) current.noMoveTime += step;
    else current.noMoveTime = 0.0f;
    const bool minimumElapsed = minMoveTime < 0.0f
        || current.activateTime >= minMoveTime;
    const bool maximumElapsed = maxMoveTime >= 0.0f
        && current.activateTime >= maxMoveTime;
    if (comeToRest && ((minimumElapsed && current.noMoveTime >= noMoveTime)
            || maximumElapsed)) {
        PutToRest();
        return true;
    }
    return false;
}

void idPhysics_AF::Evolve(const float step) {
    timeStep = step;
    lastTimeStep = step;
    ClearContacts();
    for (int i = 0; i < contactConstraints.Num(); ++i)
        delete contactConstraints[i];
    contactConstraints.Clear();
    contactBodies.Clear();
    RemoveFrameConstraints();
    TestNoclipBodies();
    ApplyFriction(step, static_cast<float>(endTime));
    AddGravity();
    IssueCollisionQueries();
    EvaluateConstraints(step);
    EvaluateBodies(step);
    ResolveCollisions(step);
    EvaluateContacts();
    SetupContactConstraints(step);
    TestIfAtRest(step);
}

void idPhysics_AF::BuildTrees() {
    for (int i = 0; i < trees.Num(); ++i) delete trees[i];
    trees.Clear();
    primaryConstraints.Clear();
    auxiliaryConstraints.Clear();
    for (int i = 0; i < bodies.Num(); ++i) {
        if (bodies[i] == nullptr) continue;
        bodies[i]->parent = nullptr;
        bodies[i]->children.Clear();
        bodies[i]->primaryConstraint = nullptr;
        bodies[i]->tree = nullptr;
    }
    for (int i = 0; i < constraints.Num(); ++i) {
        idAFConstraint* const constraint = constraints[i];
        if (constraint == nullptr || !constraint->fl.allowPrimary
                || constraint->body1 == nullptr
                || constraint->body2 == nullptr
                || constraint->body1->parent != nullptr
                || IsDescendantOf(constraint->body2, constraint->body1)) {
            if (constraint != nullptr) auxiliaryConstraints.Append(constraint);
            continue;
        }
        constraint->fl.isPrimary = 1;
        constraint->body1->parent = constraint->body2;
        constraint->body1->primaryConstraint = constraint;
        constraint->body2->children.Append(constraint->body1);
        primaryConstraints.Append(constraint);
    }
    for (int i = 0; i < bodies.Num(); ++i) {
        idAFBody* const body = bodies[i];
        if (body == nullptr || body->parent != nullptr) continue;
        idAFTree* const tree = new idAFTree();
        tree->sortedBodies.Append(body);
        tree->SortBodies();
        tree->SetMaxSubTreeAuxiliaryIndex();
        trees.Append(tree);
    }
    changedAF = false;
}

void idPhysics_AF::DebugDraw() {
    for (int i = 0; i < constraints.Num(); ++i)
        if (constraints[i] != nullptr) constraints[i]->DebugDraw();
    const idVec4 color(0.2f, 0.8f, 1.0f, 1.0f);
    for (int i = 0; i < trees.Num(); ++i)
        if (trees[i] != nullptr) trees[i]->DebugDraw(color);
}

float idPhysics_AF::GetLcpEpsilon(float) const {
    return lcpEpsilon.GetValue(endTime);
}
float idPhysics_AF::GetErrorReduction(float) const {
    return errorReduction.GetValue(endTime);
}
float idPhysics_AF::GetErrorReductionMax(float) const {
    return errorReductionMax.GetValue(endTime);
}
float idPhysics_AF::GetLimitErrorReduction(float) const {
    return limitErrorReduction.GetValue(endTime);
}
float idPhysics_AF::GetLimitErrorReductionMax(float) const {
    return limitErrorReductionMax.GetValue(endTime);
}
float idPhysics_AF::GetLimitLcpEpsilon(float) const {
    return limitLcpEpsilon.GetValue(endTime);
}
float idPhysics_AF::GetContactErrorReduction(float) const {
    return contactErrorReduction.GetValue(endTime);
}
float idPhysics_AF::GetContactErrorReductionMax(float) const {
    return contactErrorReductionMax.GetValue(endTime);
}
float idPhysics_AF::GetContactLcpEpsilon(float) const {
    return contactLcpEpsilon.GetValue(endTime);
}
float idPhysics_AF::GetUniversalErrorReduction(float) const {
    return universalErrorReduction.GetValue(endTime);
}
float idPhysics_AF::GetUniversalTorsionLcpEpsilon(float) const {
    return universalTorsionLcpEpsilon.GetValue(endTime);
}

bool idPhysics_AF::Evaluate(const int timeStepMSec,
        const int newEndTime) {
    endTime = newEndTime;
    if (changedAF) BuildTrees();
    if (masterBody != nullptr && callbacks != nullptr) {
        idVec3 masterOrigin;
        idMat3 masterAxis;
        if (GameLib_GetMasterPhysicsTransform(callbacks, masterOrigin,
                masterAxis)) {
            SetMaster(true, &masterOrigin, &masterAxis,
                static_cast<bindFlags_t>(0));
        }
    }
    if (current.atRest) return false;
    float step = timeStepMSec * 0.001f * timeScale;
    if (timeScaleRampEnd > timeScaleRampStart
            && current.activateTime < timeScaleRampEnd) {
        const float fraction = (std::max)(0.0f, (std::min)(1.0f,
            (current.activateTime - timeScaleRampStart)
            / (timeScaleRampEnd - timeScaleRampStart)));
        step *= fraction;
    }
    if (step <= 0.0f) return false;
    Evolve(step);
    if (IsOutsideWorld()) {
        PutToRest();
        if (callbacks != nullptr)
            GameLib_NotifyPhysicsDeactivated(callbacks, GetPhysicsId());
    }
    return true;
}
