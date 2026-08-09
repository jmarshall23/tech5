#include "gamelib/physics/afconstraint.h"

#include "gamelib/physics/clipmodel.h"
#include "idlib/math/rotation.h"

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>

void GameLib_SerializeAFConstraint(idSerializer* serializer,
    idAFConstraint& constraint);
void GameLib_DrawAFConstraint(const idAFConstraint& constraint,
    const idVec3& center);
void GameLib_AddAFFrameConstraint(idPhysics_AF* physics,
    idAFConstraint* constraint);
float GameLib_GetAFJointFrictionScale(const idPhysics_AF* physics);
float GameLib_GetAFContactFrictionScale(const idPhysics_AF* physics);
void GameLib_SerializeAFSuspension(idSerializer* serializer,
    idAFConstraint_Suspension& suspension);

namespace {

constexpr float PI = 3.14159265358979323846f;
constexpr float DEG2RAD = PI / 180.0f;
constexpr int ENTITYNUM_NONE = 0x1FFF;
const idVec3 kZeroVector(0.0f, 0.0f, 0.0f);

void ProjectOntoPlane(idVec3& vector, const idVec3& normal) {
    vector = vector - normal * vector.Dot(normal);
}

idVec3 BodyOrigin(const idAFBody* const body) {
    if (body == nullptr) return idVec3(0.0f, 0.0f, 0.0f);
    return body->clipModel != nullptr ? body->clipModel->GetOrigin()
        : body->current.worldOrigin;
}

idMat3 BodyAxis(const idAFBody* const body) {
    if (body == nullptr) return idMat3(1.0f);
    return body->clipModel != nullptr ? body->clipModel->GetAxis()
        : body->current.worldAxis;
}

idVec3 WorldPoint(const idAFBody* const body, const idVec3& local) {
    return body != nullptr ? BodyOrigin(body) + BodyAxis(body) * local
        : local;
}

idVec3 LocalPoint(const idAFBody* const body, const idVec3& world) {
    return body != nullptr
        ? BodyAxis(body).Transpose() * (world - BodyOrigin(body)) : world;
}

idVec3 WorldAxis(const idAFBody* const body, const idVec3& local) {
    return body != nullptr ? BodyAxis(body) * local : local;
}

idVec3 LocalAxis(const idAFBody* const body, const idVec3& world) {
    return body != nullptr ? BodyAxis(body).Transpose() * world : world;
}

void RegisterConstraint(idAFBody* const body, idAFConstraint* const c) {
    if (body == nullptr || c == nullptr) return;
    for (int i = 0; i < body->constraints.Num(); ++i)
        if (body->constraints[i] == c) return;
    body->constraints.Append(c);
}

void UnregisterConstraint(idAFBody* const body, idAFConstraint* const c) {
    if (body == nullptr) return;
    body->constraints.Remove(c);
    if (body->primaryConstraint == c) body->primaryConstraint = nullptr;
}

void SetSpatialRow(idSpatialMat& matrix, const int row,
        const idVec3& linear, const idVec3& angular) {
    matrix(row, 0) = linear.x;
    matrix(row, 1) = linear.y;
    matrix(row, 2) = linear.z;
    matrix(row, 3) = angular.x;
    matrix(row, 4) = angular.y;
    matrix(row, 5) = angular.z;
}

void SetPointRow(idSpatialMat& matrix, const int row,
        const idAFBody* const body, const idVec3& point,
        const idVec3& direction, const float sign) {
    const idVec3 linear = direction * sign;
    const idVec3 angular = (point - BodyOrigin(body)).Cross(direction)
        * sign;
    SetSpatialRow(matrix, row, linear, angular);
}

void BasisForNormal(const idVec3& normal, idVec3& tangent1,
        idVec3& tangent2) {
    const idVec3 reference = std::fabs(normal.z) < 0.7f
        ? idVec3(0.0f, 0.0f, 1.0f) : idVec3(1.0f, 0.0f, 0.0f);
    tangent1 = normal.Cross(reference);
    tangent1.NormalizeFast();
    tangent2 = normal.Cross(tangent1);
    tangent2.NormalizeFast();
}

float ClampUnit(const float value) {
    return (std::max)(-1.0f, (std::min)(1.0f, value));
}

float SafeInverseTime(const float timeStep) {
    return timeStep > 1.0e-6f ? 1.0f / timeStep : 0.0f;
}

} // namespace

idAFConstraint::idAFConstraint(const char* const constraintName,
        const constraintType_t constraintType, idAFBody* const firstBody,
        idAFBody* const secondBody)
    : type(constraintType)
    , name()
    , body1(nullptr)
    , body2(nullptr)
    , physics(nullptr)
    , lm()
    , J1()
    , J2()
    , c1()
    , c2()
    , lo()
    , hi()
    , e()
    , boxConstraint(nullptr)
    , boxIndex{}
    , boxScale{}
    , invI()
    , J()
    , firstIndex(0)
    , fl{} {
    name.Set(constraintName != nullptr ? constraintName : "noname");
    for (int i = 0; i < 6; ++i) {
        lo[i] = -1.0e20f;
        hi[i] = 1.0e20f;
        e[i] = 0.0f;
        boxIndex[i] = -1;
        boxScale[i] = 1.0f;
    }
    fl.allowPrimary = 1;
    SetBody1(firstBody);
    SetBody2(secondBody);
}

idAFConstraint::~idAFConstraint() {
    UnregisterConstraint(body1, this);
    UnregisterConstraint(body2, this);
}

void* idAFConstraint::operator new(const std::size_t size) {
#if defined(_MSC_VER)
    return _aligned_malloc(size, 16);
#else
    const std::size_t alignedSize = (size + 15u) & ~std::size_t(15u);
    return std::aligned_alloc(16, alignedSize);
#endif
}

void idAFConstraint::operator delete(void* const pointer) noexcept {
#if defined(_MSC_VER)
    _aligned_free(pointer);
#else
    std::free(pointer);
#endif
}

void idAFConstraint::SetBody1(idAFBody* const body) {
    if (body1 == body) return;
    UnregisterConstraint(body1, this);
    body1 = body;
    RegisterConstraint(body1, this);
}

void idAFConstraint::SetBody2(idAFBody* const body) {
    if (body2 == body) return;
    UnregisterConstraint(body2, this);
    body2 = body;
    RegisterConstraint(body2, this);
}

void idAFConstraint::DebugDraw() {
    idVec3 center;
    GetCenter(center);
    GameLib_DrawAFConstraint(*this, center);
}
void idAFConstraint::Translate(const idVec3&) {}
void idAFConstraint::Rotate(const idRotation&) {}
void idAFConstraint::GetCenter(idVec3& center) const {
    if (body1 != nullptr && body2 != nullptr)
        center = (BodyOrigin(body1) + BodyOrigin(body2)) * 0.5f;
    else if (body1 != nullptr) center = BodyOrigin(body1);
    else if (body2 != nullptr) center = BodyOrigin(body2);
    else center.Zero();
}
void idAFConstraint::IssueCollisionQueries() {}
void idAFConstraint::CancelCollisionQueries() {}
void idAFConstraint::Serialize(idSerializer* const serializer) {
    if (serializer != nullptr) GameLib_SerializeAFConstraint(serializer, *this);
}
void idAFConstraint::Evaluate(const idPhysics_AF*, float) {
    J1.Zero();
    J2.Zero();
    c1.Zero();
    c2.Zero();
}
void idAFConstraint::ApplyFriction(float) {}

void idAFConstraint::InitSize(const int size) {
    const int rows = (std::max)(0, (std::min)(6, size));
    J1.Zero(rows, 6);
    J2.Zero(rows, 6);
    invI.Zero(rows, rows);
    J.Zero(rows, rows);
    lm.Zero();
    c1.Zero();
    c2.Zero();
    lo.Zero();
    hi.Zero();
    e.Zero();
    for (int i = 0; i < 6; ++i) {
        lo[i] = i < rows ? -1.0e20f : 0.0f;
        hi[i] = i < rows ? 1.0e20f : 0.0f;
        boxIndex[i] = -1;
        boxScale[i] = 1.0f;
    }
}

idAFConstraint_Fixed::idAFConstraint_Fixed(const char* const fixedName,
        idAFBody* const firstBody, idAFBody* const secondBody)
    : idAFConstraint(fixedName, CONSTRAINT_FIXED, firstBody, secondBody)
    , offset(0.0f, 0.0f, 0.0f)
    , relAxis(1.0f)
    , shouldClamp(false) {
    InitSize(6);
    InitOffset();
}

void idAFConstraint_Fixed::InitOffset() {
    if (body1 == nullptr) return;
    offset = LocalPoint(body1, BodyOrigin(body2));
    relAxis = BodyAxis(body1).Transpose() * BodyAxis(body2);
}
void idAFConstraint_Fixed::SetBody1(idAFBody* const body) {
    idAFConstraint::SetBody1(body);
    InitOffset();
}
void idAFConstraint_Fixed::SetBody2(idAFBody* const body) {
    idAFConstraint::SetBody2(body);
    InitOffset();
}
void idAFConstraint_Fixed::Rotate(const idRotation& rotation) {
    if (body2 == nullptr) offset *= rotation;
}
void idAFConstraint_Fixed::GetCenter(idVec3& center) const {
    center = body1 != nullptr ? WorldPoint(body1, offset)
        : BodyOrigin(body2);
}
void idAFConstraint_Fixed::DebugDraw() { idAFConstraint::DebugDraw(); }
void idAFConstraint_Fixed::Evaluate(const idPhysics_AF*,
        const float invTimeStep) {
    InitSize(6);
    const idVec3 p1 = WorldPoint(body1, offset);
    const idVec3 p2 = BodyOrigin(body2);
    const idVec3 delta = p2 - p1;
    const idVec3 axes[3] = {idVec3(1.0f, 0.0f, 0.0f),
        idVec3(0.0f, 1.0f, 0.0f), idVec3(0.0f, 0.0f, 1.0f)};
    for (int row = 0; row < 3; ++row) {
        SetPointRow(J1, row, body1, p1, axes[row], -1.0f);
        if (body2 != nullptr)
            SetPointRow(J2, row, body2, p2, axes[row], 1.0f);
        c1[row] = delta.Dot(axes[row]) * invTimeStep;
    }
    const idMat3 target = BodyAxis(body1) * relAxis;
    const idMat3 actual = BodyAxis(body2);
    const idVec3 angularError = (target[0].Cross(actual[0])
        + target[1].Cross(actual[1]) + target[2].Cross(actual[2])) * 0.5f;
    for (int row = 0; row < 3; ++row) {
        SetSpatialRow(J1, row + 3, idVec3(0.0f, 0.0f, 0.0f),
            axes[row] * -1.0f);
        if (body2 != nullptr)
            SetSpatialRow(J2, row + 3, idVec3(0.0f, 0.0f, 0.0f),
                axes[row]);
        c1[row + 3] = angularError.Dot(axes[row]) * invTimeStep;
    }
}

idAFConstraint_BallAndSocketJoint::idAFConstraint_BallAndSocketJoint(
        const char* const jointName, idAFBody* const firstBody,
        idAFBody* const secondBody)
    : idAFConstraint(jointName, CONSTRAINT_BALLANDSOCKETJOINT,
        firstBody, secondBody)
    , anchor1(0.0f, 0.0f, 0.0f)
    , anchor2(0.0f, 0.0f, 0.0f)
    , friction(0.0f)
    , coneLimit(nullptr)
    , pyramidLimit(nullptr)
    , fc(nullptr) {
    InitSize(3);
}

idAFConstraint_BallAndSocketJoint::~idAFConstraint_BallAndSocketJoint() {
    delete coneLimit;
    delete pyramidLimit;
    delete fc;
}
void idAFConstraint_BallAndSocketJoint::SetNoLimit() {
    delete coneLimit; coneLimit = nullptr;
    delete pyramidLimit; pyramidLimit = nullptr;
}
void idAFConstraint_BallAndSocketJoint::SetWorldPosition(
        const idVec3& position) { SetAnchor(position); }
float idAFConstraint_BallAndSocketJoint::GetFriction() const {
    const float scale = physics != nullptr
        ? GameLib_GetAFJointFrictionScale(physics) : 1.0f;
    return (std::max)(0.0f, friction * scale);
}
void idAFConstraint_BallAndSocketJoint::SetAnchor(
        const idVec3& position) {
    anchor1 = LocalPoint(body1, position);
    anchor2 = LocalPoint(body2, position);
    if (coneLimit != nullptr) coneLimit->coneAnchor = anchor2;
    if (pyramidLimit != nullptr) pyramidLimit->pyramidAnchor = anchor2;
}
void idAFConstraint_BallAndSocketJoint::Translate(
        const idVec3& translation) {
    if (body2 == nullptr) anchor2 = anchor2 + translation;
}
void idAFConstraint_BallAndSocketJoint::Rotate(
        const idRotation& rotation) {
    if (body2 == nullptr) anchor2 *= rotation;
    if (coneLimit != nullptr) coneLimit->Rotate(rotation);
    if (pyramidLimit != nullptr) pyramidLimit->Rotate(rotation);
}
void idAFConstraint_BallAndSocketJoint::GetCenter(idVec3& center) const {
    center = WorldPoint(body1, anchor1);
}
void idAFConstraint_BallAndSocketJoint::DebugDraw() {
    idAFConstraint::DebugDraw();
    if (coneLimit != nullptr) coneLimit->DebugDraw();
    if (pyramidLimit != nullptr) pyramidLimit->DebugDraw();
}
void idAFConstraint_BallAndSocketJoint::Evaluate(const idPhysics_AF*,
        const float invTimeStep) {
    InitSize(3);
    const idVec3 p1 = WorldPoint(body1, anchor1);
    const idVec3 p2 = WorldPoint(body2, anchor2);
    const idVec3 delta = p2 - p1;
    const idVec3 axes[3] = {idVec3(1.0f, 0.0f, 0.0f),
        idVec3(0.0f, 1.0f, 0.0f), idVec3(0.0f, 0.0f, 1.0f)};
    for (int row = 0; row < 3; ++row) {
        SetPointRow(J1, row, body1, p1, axes[row], -1.0f);
        if (body2 != nullptr)
            SetPointRow(J2, row, body2, p2, axes[row], 1.0f);
        c1[row] = delta.Dot(axes[row]) * invTimeStep;
    }
    if (coneLimit != nullptr) coneLimit->Add(physics, invTimeStep);
    if (pyramidLimit != nullptr) pyramidLimit->Add(physics, invTimeStep);
}
void idAFConstraint_BallAndSocketJoint::SetConeLimit(
        const idVec3& axis, const float angle, const idVec3& bodyAxis) {
    delete pyramidLimit; pyramidLimit = nullptr;
    if (coneLimit == nullptr) coneLimit = new idAFConstraint_ConeLimit();
    coneLimit->physics = physics;
    coneLimit->Setup(body1, body2, anchor2, axis, angle, bodyAxis);
}
void idAFConstraint_BallAndSocketJoint::SetPyramidLimit(
        const idVec3& axis, const idVec3& baseAxis, const float angle1,
        const float angle2, const idVec3& bodyAxis) {
    delete coneLimit; coneLimit = nullptr;
    if (pyramidLimit == nullptr)
        pyramidLimit = new idAFConstraint_PyramidLimit();
    pyramidLimit->physics = physics;
    pyramidLimit->Setup(body1, body2, anchor2, axis, baseAxis,
        angle1, angle2, bodyAxis);
}
void idAFConstraint_BallAndSocketJoint::ApplyFriction(
        const float invTimeStep) {
    if (GetFriction() <= 0.0f) return;
    if (fc == nullptr) fc = new idAFConstraint_BallAndSocketJointFriction(this);
    fc->Add(physics, invTimeStep);
}

idAFConstraint_BallAndSocketJointFriction::
idAFConstraint_BallAndSocketJointFriction(
        idAFConstraint_BallAndSocketJoint* const sourceJoint)
    : idAFConstraint("ballAndSocketFriction", CONSTRAINT_FRICTION,
        sourceJoint != nullptr ? sourceJoint->body1 : nullptr,
        sourceJoint != nullptr ? sourceJoint->body2 : nullptr)
    , joint(sourceJoint) {
    InitSize(3);
    fl.frameConstraint = 1;
    fl.allowPrimary = 0;
}
bool idAFConstraint_BallAndSocketJointFriction::Add(
        idPhysics_AF* const af, float) {
    if (joint == nullptr || joint->GetFriction() <= 0.0f) return false;
    physics = af;
    InitSize(3);
    const idVec3 axes[3] = {idVec3(1.0f, 0.0f, 0.0f),
        idVec3(0.0f, 1.0f, 0.0f), idVec3(0.0f, 0.0f, 1.0f)};
    for (int row = 0; row < 3; ++row) {
        SetSpatialRow(J1, row, idVec3(0.0f, 0.0f, 0.0f), axes[row]);
        if (body2 != nullptr)
            SetSpatialRow(J2, row, idVec3(0.0f, 0.0f, 0.0f),
                axes[row] * -1.0f);
        lo[row] = -joint->GetFriction();
        hi[row] = joint->GetFriction();
    }
    GameLib_AddAFFrameConstraint(af, this);
    return true;
}

idAFConstraint_UniversalJoint::idAFConstraint_UniversalJoint(
        const char* const jointName, idAFBody* const firstBody,
        idAFBody* const secondBody)
    : idAFConstraint(jointName, CONSTRAINT_UNIVERSALJOINT,
        firstBody, secondBody)
    , anchor1(0.0f, 0.0f, 0.0f)
    , anchor2(0.0f, 0.0f, 0.0f)
    , shaft1(1.0f, 0.0f, 0.0f)
    , shaft2(0.0f, 1.0f, 0.0f)
    , axis1(0.0f, 1.0f, 0.0f)
    , axis2(1.0f, 0.0f, 0.0f)
    , friction(0.0f)
    , coneLimit(nullptr)
    , pyramidLimit(nullptr)
    , fc(nullptr) { InitSize(4); }

idAFConstraint_UniversalJoint::~idAFConstraint_UniversalJoint() {
    delete coneLimit;
    delete pyramidLimit;
    delete fc;
}
void idAFConstraint_UniversalJoint::SetNoLimit() {
    delete coneLimit; coneLimit = nullptr;
    delete pyramidLimit; pyramidLimit = nullptr;
}
float idAFConstraint_UniversalJoint::GetFriction() const {
    const float scale = physics != nullptr
        ? GameLib_GetAFJointFrictionScale(physics) : 1.0f;
    return (std::max)(0.0f, friction * scale);
}
void idAFConstraint_UniversalJoint::SetAnchor(const idVec3& position) {
    anchor1 = LocalPoint(body1, position);
    anchor2 = LocalPoint(body2, position);
    if (coneLimit != nullptr) coneLimit->coneAnchor = anchor2;
    if (pyramidLimit != nullptr) pyramidLimit->pyramidAnchor = anchor2;
}
void idAFConstraint_UniversalJoint::SetShafts(const idVec3& first,
        const idVec3& second) {
    idVec3 normalizedFirst = first;
    idVec3 normalizedSecond = second;
    normalizedFirst.NormalizeFast();
    normalizedSecond.NormalizeFast();
    shaft1 = LocalAxis(body1, normalizedFirst);
    shaft2 = LocalAxis(body2, normalizedSecond);
    axis1 = LocalAxis(body1, normalizedSecond);
    axis2 = LocalAxis(body2, normalizedFirst);
}
void idAFConstraint_UniversalJoint::Translate(const idVec3& translation) {
    if (body2 == nullptr) anchor2 = anchor2 + translation;
}
void idAFConstraint_UniversalJoint::Rotate(const idRotation& rotation) {
    if (body2 == nullptr) {
        anchor2 *= rotation;
        shaft2 = rotation.ToMat3() * shaft2;
        axis2 = rotation.ToMat3() * axis2;
    }
    if (coneLimit != nullptr) coneLimit->Rotate(rotation);
    if (pyramidLimit != nullptr) pyramidLimit->Rotate(rotation);
}
void idAFConstraint_UniversalJoint::GetCenter(idVec3& center) const {
    center = WorldPoint(body1, anchor1);
}
void idAFConstraint_UniversalJoint::DebugDraw() {
    idAFConstraint::DebugDraw();
    if (coneLimit != nullptr) coneLimit->DebugDraw();
    if (pyramidLimit != nullptr) pyramidLimit->DebugDraw();
}
void idAFConstraint_UniversalJoint::Evaluate(const idPhysics_AF*,
        const float invTimeStep) {
    InitSize(4);
    const idVec3 p1 = WorldPoint(body1, anchor1);
    const idVec3 p2 = WorldPoint(body2, anchor2);
    const idVec3 delta = p2 - p1;
    const idVec3 axes[3] = {idVec3(1.0f, 0.0f, 0.0f),
        idVec3(0.0f, 1.0f, 0.0f), idVec3(0.0f, 0.0f, 1.0f)};
    for (int row = 0; row < 3; ++row) {
        SetPointRow(J1, row, body1, p1, axes[row], -1.0f);
        if (body2 != nullptr)
            SetPointRow(J2, row, body2, p2, axes[row], 1.0f);
        c1[row] = delta.Dot(axes[row]) * invTimeStep;
    }
    const idVec3 worldShaft1 = WorldAxis(body1, shaft1);
    const idVec3 worldShaft2 = WorldAxis(body2, shaft2);
    const idVec3 angular = worldShaft1.Cross(worldShaft2);
    SetSpatialRow(J1, 3, idVec3(0.0f, 0.0f, 0.0f), angular);
    if (body2 != nullptr)
        SetSpatialRow(J2, 3, idVec3(0.0f, 0.0f, 0.0f), -angular);
    c1[3] = worldShaft1.Dot(worldShaft2) * invTimeStep;
    if (coneLimit != nullptr) coneLimit->Add(physics, invTimeStep);
    if (pyramidLimit != nullptr) pyramidLimit->Add(physics, invTimeStep);
}
void idAFConstraint_UniversalJoint::SetConeLimit(const idVec3& axis,
        const float angle, const idVec3& bodyAxis) {
    delete pyramidLimit; pyramidLimit = nullptr;
    if (coneLimit == nullptr) coneLimit = new idAFConstraint_ConeLimit();
    coneLimit->physics = physics;
    coneLimit->Setup(body1, body2, anchor2, axis, angle, bodyAxis);
}
void idAFConstraint_UniversalJoint::SetPyramidLimit(
        const idVec3& axis, const idVec3& baseAxis, const float angle1,
        const float angle2, const idVec3& bodyAxis) {
    delete coneLimit; coneLimit = nullptr;
    if (pyramidLimit == nullptr)
        pyramidLimit = new idAFConstraint_PyramidLimit();
    pyramidLimit->physics = physics;
    pyramidLimit->Setup(body1, body2, anchor2, axis, baseAxis,
        angle1, angle2, bodyAxis);
}
void idAFConstraint_UniversalJoint::ApplyFriction(
        const float invTimeStep) {
    if (GetFriction() <= 0.0f) return;
    if (fc == nullptr) fc = new idAFConstraint_UniversalJointFriction(this);
    fc->Add(physics, invTimeStep);
}

idAFConstraint_UniversalJointFriction::
idAFConstraint_UniversalJointFriction(
        idAFConstraint_UniversalJoint* const sourceJoint)
    : idAFConstraint("universalFriction", CONSTRAINT_FRICTION,
        sourceJoint != nullptr ? sourceJoint->body1 : nullptr,
        sourceJoint != nullptr ? sourceJoint->body2 : nullptr)
    , joint(sourceJoint) {
    InitSize(2);
    fl.frameConstraint = 1;
    fl.allowPrimary = 0;
}
bool idAFConstraint_UniversalJointFriction::Add(idPhysics_AF* const af,
        float) {
    if (joint == nullptr || joint->GetFriction() <= 0.0f) return false;
    physics = af;
    Evaluate(af, 0.0f);
    for (int row = 0; row < 2; ++row) {
        lo[row] = -joint->GetFriction();
        hi[row] = joint->GetFriction();
    }
    GameLib_AddAFFrameConstraint(af, this);
    return true;
}
void idAFConstraint_UniversalJointFriction::Evaluate(
        const idPhysics_AF*, float) {
    InitSize(2);
    if (joint == nullptr) return;
    idVec3 first = WorldAxis(body1, joint->shaft1);
    idVec3 second = WorldAxis(body2, joint->shaft2);
    idVec3 cross = first.Cross(second);
    if (cross.NormalizeFast() == 0.0f) BasisForNormal(first, cross, second);
    const idVec3 axes[2] = {first, second};
    for (int row = 0; row < 2; ++row) {
        SetSpatialRow(J1, row, idVec3(0.0f, 0.0f, 0.0f), axes[row]);
        if (body2 != nullptr)
            SetSpatialRow(J2, row, idVec3(0.0f, 0.0f, 0.0f), -axes[row]);
    }
}

idAFConstraint_Hinge::idAFConstraint_Hinge(const char* const hingeName,
        idAFBody* const firstBody, idAFBody* const secondBody)
    : idAFConstraint(hingeName, CONSTRAINT_HINGE, firstBody, secondBody)
    , anchor1(0.0f, 0.0f, 0.0f)
    , anchor2(0.0f, 0.0f, 0.0f)
    , axis1(0.0f, 0.0f, 1.0f)
    , axis2(0.0f, 0.0f, 1.0f)
    , initialAxis(1.0f)
    , friction(0.0f)
    , coneLimit(nullptr)
    , steering(nullptr)
    , fc(nullptr) { InitSize(5); }

idAFConstraint_Hinge::~idAFConstraint_Hinge() {
    delete coneLimit;
    delete steering;
    delete fc;
}
void idAFConstraint_Hinge::SetNoLimit() {
    delete coneLimit; coneLimit = nullptr;
}
void idAFConstraint_Hinge::SetAnchor(const idVec3& position) {
    anchor1 = LocalPoint(body1, position);
    anchor2 = LocalPoint(body2, position);
}
void idAFConstraint_Hinge::SetAxis(const idVec3& sourceAxis) {
    idVec3 normalized = sourceAxis;
    normalized.NormalizeFast();
    axis1 = LocalAxis(body1, normalized);
    axis2 = LocalAxis(body2, normalized);
    initialAxis = BodyAxis(body1).Transpose() * BodyAxis(body2);
}
float idAFConstraint_Hinge::GetFriction() const {
    const float scale = physics != nullptr
        ? GameLib_GetAFJointFrictionScale(physics) : 1.0f;
    return (std::max)(0.0f, friction * scale);
}
float idAFConstraint_Hinge::GetAngle() const {
    const idVec3 hingeAxis = WorldAxis(body1, axis1);
    const idMat3 relative = BodyAxis(body1).Transpose() * BodyAxis(body2);
    idVec3 reference = initialAxis[0];
    idVec3 currentReference = relative[0];
    ProjectOntoPlane(reference, axis1);
    ProjectOntoPlane(currentReference, axis1);
    reference.NormalizeFast();
    currentReference.NormalizeFast();
    return std::atan2(hingeAxis.Dot(reference.Cross(currentReference)),
        ClampUnit(reference.Dot(currentReference))) / DEG2RAD;
}
void idAFConstraint_Hinge::Translate(const idVec3& translation) {
    if (body2 == nullptr) anchor2 = anchor2 + translation;
}
void idAFConstraint_Hinge::Rotate(const idRotation& rotation) {
    if (body2 == nullptr) {
        anchor2 *= rotation;
        axis2 = rotation.ToMat3() * axis2;
    }
    if (coneLimit != nullptr) coneLimit->Rotate(rotation);
}
void idAFConstraint_Hinge::GetCenter(idVec3& center) const {
    center = WorldPoint(body1, anchor1);
}
void idAFConstraint_Hinge::DebugDraw() {
    idAFConstraint::DebugDraw();
    if (coneLimit != nullptr) coneLimit->DebugDraw();
}
void idAFConstraint_Hinge::Evaluate(const idPhysics_AF*,
        const float invTimeStep) {
    InitSize(5);
    const idVec3 p1 = WorldPoint(body1, anchor1);
    const idVec3 p2 = WorldPoint(body2, anchor2);
    const idVec3 delta = p2 - p1;
    const idVec3 axes[3] = {idVec3(1.0f, 0.0f, 0.0f),
        idVec3(0.0f, 1.0f, 0.0f), idVec3(0.0f, 0.0f, 1.0f)};
    for (int row = 0; row < 3; ++row) {
        SetPointRow(J1, row, body1, p1, axes[row], -1.0f);
        if (body2 != nullptr)
            SetPointRow(J2, row, body2, p2, axes[row], 1.0f);
        c1[row] = delta.Dot(axes[row]) * invTimeStep;
    }
    const idVec3 a1 = WorldAxis(body1, axis1);
    const idVec3 a2 = WorldAxis(body2, axis2);
    idVec3 tangent1;
    idVec3 tangent2;
    BasisForNormal(a1, tangent1, tangent2);
    const idVec3 tangents[2] = {tangent1, tangent2};
    for (int row = 0; row < 2; ++row) {
        SetSpatialRow(J1, row + 3, kZeroVector, tangents[row]);
        if (body2 != nullptr)
            SetSpatialRow(J2, row + 3, kZeroVector, -tangents[row]);
        c1[row + 3] = a2.Dot(tangents[row]) * invTimeStep;
    }
    if (coneLimit != nullptr) coneLimit->Add(physics, invTimeStep);
    if (steering != nullptr) steering->Add(physics, invTimeStep);
}
void idAFConstraint_Hinge::SetLimit(const float angle1,
        const float angle2, const float limitEpsilon) {
    if (coneLimit == nullptr) coneLimit = new idAFConstraint_ConeLimit();
    idVec3 normal;
    idVec3 base;
    BasisForNormal(WorldAxis(body1, axis1), normal, base);
    coneLimit->physics = physics;
    coneLimit->Setup(body1, body2, anchor2, normal,
        (std::max)(std::fabs(angle1), std::fabs(angle2)), base);
    coneLimit->epsilon = limitEpsilon;
}
void idAFConstraint_Hinge::ApplyFriction(const float invTimeStep) {
    if (GetFriction() <= 0.0f) return;
    if (fc == nullptr) fc = new idAFConstraint_HingeFriction(this);
    fc->Add(physics, invTimeStep);
}

idAFConstraint_HingeFriction::idAFConstraint_HingeFriction(
        idAFConstraint_Hinge* const sourceHinge)
    : idAFConstraint("hingeFriction", CONSTRAINT_FRICTION,
        sourceHinge != nullptr ? sourceHinge->body1 : nullptr,
        sourceHinge != nullptr ? sourceHinge->body2 : nullptr)
    , hinge(sourceHinge) {
    InitSize(1);
    fl.frameConstraint = 1;
    fl.allowPrimary = 0;
}
bool idAFConstraint_HingeFriction::Add(idPhysics_AF* const af, float) {
    if (hinge == nullptr || hinge->GetFriction() <= 0.0f) return false;
    physics = af;
    InitSize(1);
    const idVec3 axis = WorldAxis(body1, hinge->axis1);
    SetSpatialRow(J1, 0, kZeroVector, axis);
    if (body2 != nullptr) SetSpatialRow(J2, 0, kZeroVector, -axis);
    lo[0] = -hinge->GetFriction();
    hi[0] = hinge->GetFriction();
    GameLib_AddAFFrameConstraint(af, this);
    return true;
}

idAFConstraint_HingeSteering::idAFConstraint_HingeSteering(
        idAFConstraint_Hinge* const sourceHinge)
    : idAFConstraint("hingeSteering", CONSTRAINT_HINGESTEERING,
        sourceHinge != nullptr ? sourceHinge->body1 : nullptr,
        sourceHinge != nullptr ? sourceHinge->body2 : nullptr)
    , hinge(sourceHinge)
    , steerAngle(0.0f)
    , steerSpeed(0.0f)
    , epsilon(0.001f) {
    InitSize(1);
    fl.frameConstraint = 1;
    fl.allowPrimary = 0;
}
bool idAFConstraint_HingeSteering::Add(idPhysics_AF* const af,
        const float invTimeStep) {
    if (hinge == nullptr) return false;
    physics = af;
    InitSize(1);
    const idVec3 axis = WorldAxis(body1, hinge->axis1);
    SetSpatialRow(J1, 0, kZeroVector, axis);
    if (body2 != nullptr) SetSpatialRow(J2, 0, kZeroVector, -axis);
    const float delta = steerAngle - hinge->GetAngle();
    c1[0] = (std::max)(-steerSpeed, (std::min)(steerSpeed,
        delta * invTimeStep));
    GameLib_AddAFFrameConstraint(af, this);
    return std::fabs(delta) > epsilon;
}

idAFConstraint_Slider::idAFConstraint_Slider(const char* const sliderName,
        idAFBody* const firstBody, idAFBody* const secondBody)
    : idAFConstraint(sliderName, CONSTRAINT_SLIDER, firstBody, secondBody)
    , axis(1.0f, 0.0f, 0.0f)
    , offset(0.0f, 0.0f, 0.0f)
    , relAxis(1.0f) { InitSize(5); }
void idAFConstraint_Slider::SetAxis(const idVec3& sourceAxis) {
    axis = sourceAxis;
    axis.NormalizeFast();
    if (body1 != nullptr) axis = LocalAxis(body1, axis);
    offset = LocalPoint(body1, BodyOrigin(body2));
    relAxis = BodyAxis(body1).Transpose() * BodyAxis(body2);
}
void idAFConstraint_Slider::GetCenter(idVec3& center) const {
    center = (BodyOrigin(body1) + BodyOrigin(body2)) * 0.5f;
}
void idAFConstraint_Slider::DebugDraw() { idAFConstraint::DebugDraw(); }
void idAFConstraint_Slider::Evaluate(const idPhysics_AF*,
        const float invTimeStep) {
    InitSize(5);
    const idVec3 worldAxis = WorldAxis(body1, axis);
    idVec3 tangent1;
    idVec3 tangent2;
    BasisForNormal(worldAxis, tangent1, tangent2);
    const idVec3 delta = BodyOrigin(body2) - WorldPoint(body1, offset);
    const idVec3 tangents[2] = {tangent1, tangent2};
    for (int row = 0; row < 2; ++row) {
        SetSpatialRow(J1, row, -tangents[row], kZeroVector);
        if (body2 != nullptr)
            SetSpatialRow(J2, row, tangents[row], kZeroVector);
        c1[row] = delta.Dot(tangents[row]) * invTimeStep;
    }
    const idMat3 target = BodyAxis(body1) * relAxis;
    const idMat3 actual = BodyAxis(body2);
    const idVec3 error = (target[0].Cross(actual[0])
        + target[1].Cross(actual[1]) + target[2].Cross(actual[2])) * 0.5f;
    const idVec3 axes[3] = {idVec3(1.0f, 0.0f, 0.0f),
        idVec3(0.0f, 1.0f, 0.0f), idVec3(0.0f, 0.0f, 1.0f)};
    for (int row = 0; row < 3; ++row) {
        SetSpatialRow(J1, row + 2, kZeroVector, -axes[row]);
        if (body2 != nullptr)
            SetSpatialRow(J2, row + 2, kZeroVector, axes[row]);
        c1[row + 2] = error.Dot(axes[row]) * invTimeStep;
    }
}

idAFConstraint_Spring::idAFConstraint_Spring(const char* const springName,
        idAFBody* const firstBody, idAFBody* const secondBody)
    : idAFConstraint(springName, CONSTRAINT_SPRING, firstBody, secondBody)
    , anchor1(0.0f, 0.0f, 0.0f)
    , anchor2(0.0f, 0.0f, 0.0f)
    , kstretch(100.0f)
    , kcompress(100.0f)
    , damping(0.0f)
    , restLength(0.0f)
    , minLength(0.0f)
    , maxLength(0.0f) { InitSize(0); }
void idAFConstraint_Spring::SetSpring(const float stretch,
        const float compress, const float damping_, const float rest) {
    kstretch = stretch;
    kcompress = compress;
    damping = damping_;
    restLength = rest;
}
void idAFConstraint_Spring::SetLimit(const float minimum,
        const float maximum) { minLength = minimum; maxLength = maximum; }
void idAFConstraint_Spring::SetAnchor(const idVec3& first,
        const idVec3& second) {
    anchor1 = LocalPoint(body1, first);
    anchor2 = LocalPoint(body2, second);
}
void idAFConstraint_Spring::Translate(const idVec3& translation) {
    if (body2 == nullptr) anchor2 = anchor2 + translation;
}
void idAFConstraint_Spring::Rotate(const idRotation& rotation) {
    if (body2 == nullptr) anchor2 *= rotation;
}
void idAFConstraint_Spring::GetCenter(idVec3& center) const {
    center = (WorldPoint(body1, anchor1) + WorldPoint(body2, anchor2))
        * 0.5f;
}
void idAFConstraint_Spring::DebugDraw() { idAFConstraint::DebugDraw(); }
void idAFConstraint_Spring::Evaluate(const idPhysics_AF*, float) {
    const idVec3 p1 = WorldPoint(body1, anchor1);
    const idVec3 p2 = WorldPoint(body2, anchor2);
    idVec3 direction = p2 - p1;
    const float length = direction.NormalizeFast();
    if (length <= 1.0e-6f) return;
    float displacement = length - restLength;
    if (maxLength > minLength) {
        if (length < minLength) displacement = length - minLength;
        else if (length > maxLength) displacement = length - maxLength;
    }
    const float stiffness = displacement >= 0.0f ? kstretch : kcompress;
    const idVec3 relativeVelocity = (body2 != nullptr
        ? body2->GetPointVelocity(p2) : kZeroVector)
        - (body1 != nullptr ? body1->GetPointVelocity(p1) : kZeroVector);
    const float forceMagnitude = stiffness * displacement
        + damping * relativeVelocity.Dot(direction);
    const idVec3 force = direction * forceMagnitude;
    if (body1 != nullptr) body1->AddForce(p1, force);
    if (body2 != nullptr) body2->AddForce(p2, -force);
}

idAFConstraint_Contact::idAFConstraint_Contact()
    : idAFConstraint("contact", CONSTRAINT_CONTACT, nullptr, nullptr)
    , contact{}
    , separation(0.0f)
    , fc(nullptr) {
    InitSize(1);
    fl.allowPrimary = 0;
}
idAFConstraint_Contact::~idAFConstraint_Contact() { delete fc; }
void idAFConstraint_Contact::Setup(idAFBody* const firstBody,
        idAFBody* const secondBody, const contactInfo_t& info,
        const float separation_, const float invTimeStep) {
    SetBody1(firstBody);
    SetBody2(secondBody);
    contact = info;
    separation = separation_;
    InitSize(1);
    SetPointRow(J1, 0, body1, contact.point, contact.normal, 1.0f);
    if (body2 != nullptr)
        SetPointRow(J2, 0, body2, contact.point, contact.normal, -1.0f);
    c1[0] = (std::min)(0.0f, separation) * invTimeStep;
    lo[0] = 0.0f;
    hi[0] = 1.0e20f;
}
void idAFConstraint_Contact::GetCenter(idVec3& center) const {
    center = contact.point;
}
void idAFConstraint_Contact::DebugDraw() { idAFConstraint::DebugDraw(); }
void idAFConstraint_Contact::ApplyFriction(const float invTimeStep) {
    const float frictionScale = physics != nullptr
        ? GameLib_GetAFContactFrictionScale(physics) : 1.0f;
    if (frictionScale <= 0.0f || body1 == nullptr) return;
    if (fc == nullptr) fc = new idAFConstraint_ContactFriction(this);
    fc->Add(physics, invTimeStep);
}

idAFConstraint_ContactFriction::idAFConstraint_ContactFriction(
        idAFConstraint_Contact* const contactConstraint)
    : idAFConstraint("contactFriction", CONSTRAINT_FRICTION,
        contactConstraint != nullptr ? contactConstraint->body1 : nullptr,
        contactConstraint != nullptr ? contactConstraint->body2 : nullptr)
    , cc(contactConstraint) {
    InitSize(2);
    fl.frameConstraint = 1;
    fl.allowPrimary = 0;
}
bool idAFConstraint_ContactFriction::Add(idPhysics_AF* const af, float) {
    if (cc == nullptr || body1 == nullptr) return false;
    physics = af;
    InitSize(2);
    idVec3 tangent1;
    idVec3 tangent2;
    BasisForNormal(cc->contact.normal, tangent1, tangent2);
    const idVec3 tangents[2] = {tangent1, tangent2};
    float friction = body1->contactFriction;
    if (friction < 0.0f) friction = 0.0f;
    friction *= af != nullptr ? GameLib_GetAFContactFrictionScale(af) : 1.0f;
    for (int row = 0; row < 2; ++row) {
        SetPointRow(J1, row, body1, cc->contact.point,
            tangents[row], 1.0f);
        if (body2 != nullptr)
            SetPointRow(J2, row, body2, cc->contact.point,
                tangents[row], -1.0f);
        lo[row] = -friction;
        hi[row] = friction;
        boxIndex[row] = cc->firstIndex;
        boxConstraint = cc;
    }
    GameLib_AddAFFrameConstraint(af, this);
    return true;
}

idAFConstraint_ConeLimit::idAFConstraint_ConeLimit()
    : idAFConstraint("coneLimit", CONSTRAINT_CONELIMIT, nullptr, nullptr)
    , coneAnchor(0.0f, 0.0f, 0.0f)
    , coneAxis(0.0f, 0.0f, 1.0f)
    , body1Axis(0.0f, 0.0f, 1.0f)
    , cosAngle(1.0f)
    , sinHalfAngle(0.0f)
    , cosHalfAngle(1.0f)
    , epsilon(0.001f) {
    InitSize(1);
    fl.allowPrimary = 0;
}
void idAFConstraint_ConeLimit::Setup(idAFBody* const firstBody,
        idAFBody* const secondBody, const idVec3& anchor,
        const idVec3& axis, const float angle,
        const idVec3& firstBodyAxis) {
    SetBody1(firstBody);
    SetBody2(secondBody);
    coneAnchor = anchor;
    coneAxis = axis;
    coneAxis.NormalizeFast();
    body1Axis = firstBodyAxis;
    body1Axis.NormalizeFast();
    cosAngle = std::cos(angle * DEG2RAD);
    sinHalfAngle = std::sin(angle * DEG2RAD * 0.5f);
    cosHalfAngle = std::cos(angle * DEG2RAD * 0.5f);
}
bool idAFConstraint_ConeLimit::Add(idPhysics_AF* const af,
        const float invTimeStep) {
    const idVec3 cone = WorldAxis(body2, coneAxis);
    const idVec3 body = WorldAxis(body1, body1Axis);
    const float cosine = cone.Dot(body);
    if (cosine >= cosAngle) return false;
    physics = af;
    InitSize(1);
    idVec3 axis = cone.Cross(body);
    axis.NormalizeFast();
    SetSpatialRow(J1, 0, kZeroVector, axis);
    if (body2 != nullptr) SetSpatialRow(J2, 0, kZeroVector, -axis);
    c1[0] = (std::acos(ClampUnit(cosine))
        - std::acos(ClampUnit(cosAngle))) * invTimeStep;
    lo[0] = 0.0f;
    hi[0] = 1.0e20f;
    GameLib_AddAFFrameConstraint(af, this);
    return true;
}
void idAFConstraint_ConeLimit::Translate(const idVec3& translation) {
    if (body2 == nullptr) coneAnchor = coneAnchor + translation;
}
void idAFConstraint_ConeLimit::Rotate(const idRotation& rotation) {
    if (body2 == nullptr) {
        coneAnchor *= rotation;
        coneAxis = rotation.ToMat3() * coneAxis;
    }
}
void idAFConstraint_ConeLimit::DebugDraw() { idAFConstraint::DebugDraw(); }

idAFConstraint_PyramidLimit::idAFConstraint_PyramidLimit()
    : idAFConstraint("pyramidLimit", CONSTRAINT_PYRAMIDLIMIT,
        nullptr, nullptr)
    , pyramidAnchor(0.0f, 0.0f, 0.0f)
    , pyramidBasis(1.0f)
    , body1Axis(0.0f, 0.0f, 1.0f)
    , cosAngle{1.0f, 1.0f}
    , sinHalfAngle{0.0f, 0.0f}
    , cosHalfAngle{1.0f, 1.0f}
    , epsilon(0.001f) {
    InitSize(1);
    fl.allowPrimary = 0;
}
void idAFConstraint_PyramidLimit::Setup(idAFBody* const firstBody,
        idAFBody* const secondBody, const idVec3& anchor,
        const idVec3& axis, const idVec3& baseAxis,
        const float angle1, const float angle2,
        const idVec3& firstBodyAxis) {
    SetBody1(firstBody);
    SetBody2(secondBody);
    pyramidAnchor = anchor;
    pyramidBasis[0] = axis;
    pyramidBasis[0].NormalizeFast();
    pyramidBasis[1] = baseAxis;
    ProjectOntoPlane(pyramidBasis[1], pyramidBasis[0]);
    pyramidBasis[1].NormalizeFast();
    pyramidBasis[2] = pyramidBasis[0].Cross(pyramidBasis[1]);
    pyramidBasis[2].NormalizeFast();
    body1Axis = firstBodyAxis;
    body1Axis.NormalizeFast();
    const float angles[2] = {angle1, angle2};
    for (int i = 0; i < 2; ++i) {
        cosAngle[i] = std::cos(angles[i] * DEG2RAD);
        sinHalfAngle[i] = std::sin(angles[i] * DEG2RAD * 0.5f);
        cosHalfAngle[i] = std::cos(angles[i] * DEG2RAD * 0.5f);
    }
}
bool idAFConstraint_PyramidLimit::Add(idPhysics_AF* const af,
        const float invTimeStep) {
    const idMat3 basis = BodyAxis(body2) * pyramidBasis;
    const idVec3 body = WorldAxis(body1, body1Axis);
    const float x = body.Dot(basis[0]);
    const float y = body.Dot(basis[1]);
    const float z = body.Dot(basis[2]);
    const float limits[2] = {std::tan(std::acos(ClampUnit(cosAngle[0]))),
        std::tan(std::acos(ClampUnit(cosAngle[1])))};
    const float excessY = std::fabs(y) - std::fabs(x) * limits[0];
    const float excessZ = std::fabs(z) - std::fabs(x) * limits[1];
    if (excessY <= 0.0f && excessZ <= 0.0f) return false;
    physics = af;
    InitSize(1);
    idVec3 normal = excessY > excessZ ? basis[1] : basis[2];
    if (body.Dot(normal) < 0.0f) normal = -normal;
    idVec3 axis = body.Cross(normal);
    axis.NormalizeFast();
    SetSpatialRow(J1, 0, kZeroVector, axis);
    if (body2 != nullptr) SetSpatialRow(J2, 0, kZeroVector, -axis);
    c1[0] = (std::max)(excessY, excessZ) * invTimeStep;
    lo[0] = 0.0f;
    hi[0] = 1.0e20f;
    GameLib_AddAFFrameConstraint(af, this);
    return true;
}
void idAFConstraint_PyramidLimit::Translate(const idVec3& translation) {
    if (body2 == nullptr) pyramidAnchor = pyramidAnchor + translation;
}
void idAFConstraint_PyramidLimit::Rotate(const idRotation& rotation) {
    if (body2 == nullptr) {
        pyramidAnchor *= rotation;
        pyramidBasis *= rotation.ToMat3();
    }
}
void idAFConstraint_PyramidLimit::DebugDraw() {
    idAFConstraint::DebugDraw();
}

idAFConstraint_Suspension::idAFConstraint_Suspension()
    : idAFConstraint("suspension", CONSTRAINT_SUSPENSION, nullptr, nullptr)
    , localOrigin(0.0f, 0.0f, 0.0f)
    , suspensionUp(0.0f)
    , suspensionDown(0.0f)
    , suspensionCompress(0.0f)
    , suspensionDamping(0.0f)
    , friction_longitudinal(nullptr)
    , friction_lateral(nullptr)
    , frictionLatMultiplier(1.0f)
    , frictionLongMultiplier(1.0f)
    , clip(nullptr)
    , wheelModel(nullptr)
    , wheelRadius(0.0f)
    , clipMask(0)
    , cgLocation(0.0f, 0.0f, 0.0f)
    , steerAngle(0.0f)
    , motorEnabled(false)
    , motorForce(0.0f)
    , motorVelocity(0.0f)
    , traceQuery{}
    , traceFraction(1.0f)
    , traceEndPos(0.0f, 0.0f, 0.0f)
    , traceNormal(0.0f, 0.0f, 1.0f)
    , tracePoint(0.0f, 0.0f, 0.0f)
    , traceSurfaceFlags(0)
    , traceEntityNum(ENTITYNUM_NONE)
    , wheelVelocity(0.0f)
    , wheelAngle(0.0f)
    , lastWheelHeight(0.0f)
    , lastMotorVelocity(0.0f)
    , lastTorque(0.0f)
    , lastGrip(0.0f)
    , lastOnGround(false)
    , limitLateralGrip(false)
    , lateralSlip(0.0f)
    , longitudinalSlip(0.0f)
    , debugSpringForce(0.0f)
    , debugv1(0.0f, 0.0f, 0.0f)
    , debugv2(0.0f, 0.0f, 0.0f)
    , debugv3(0.0f, 0.0f, 0.0f)
    , debugf1(0.0f)
    , debugf2(0.0f)
    , debugf3(0.0f)
    , debugf4(0.0f) {
    InitSize(1);
    fl.allowPrimary = 0;
}
void idAFConstraint_Suspension::Setup(const char* const suspensionName,
        idAFBody* const body, const idVec3& origin, idClip* const ownerClip,
        idClipModel* const model, const int mask, const float radius) {
    name.Set(suspensionName != nullptr ? suspensionName : "suspension");
    SetBody1(body);
    SetBody2(nullptr);
    localOrigin = origin;
    clip = ownerClip;
    wheelModel = model;
    clipMask = mask;
    wheelRadius = radius;
    traceEndPos = WorldPoint(body1, localOrigin);
}
void idAFConstraint_Suspension::SetSuspension(const float up,
        const float down, const float compress, const float damping_) {
    suspensionUp = up;
    suspensionDown = down;
    suspensionCompress = compress;
    suspensionDamping = damping_;
}
int idAFConstraint_Suspension::GetContactEntity() const {
    return lastOnGround ? traceEntityNum : ENTITYNUM_NONE;
}
void idAFConstraint_Suspension::Translate(const idVec3& translation) {
    traceEndPos = traceEndPos + translation;
}
void idAFConstraint_Suspension::IssueCollisionQueries() {
    traceFraction = 1.0f;
    traceEntityNum = ENTITYNUM_NONE;
    lastOnGround = false;
    if (clip == nullptr || body1 == nullptr || wheelModel == nullptr) return;
    const idVec3 start = WorldPoint(body1, localOrigin)
        + BodyAxis(body1)[2] * suspensionUp;
    const idVec3 end = WorldPoint(body1, localOrigin)
        - BodyAxis(body1)[2] * suspensionDown;
    trace_t result{};
    result.fraction = 1.0f;
    result.endpos = end;
    result.endAxis = BodyAxis(body1);
    traceQuery = clip->Translation(&result, start, end, wheelModel,
        BodyAxis(body1), clipMask, body1->clipModel != nullptr
            ? body1->clipModel->GetEntityNumber() : ENTITYNUM_NONE,
        false, "idAFConstraint_Suspension::IssueCollisionQueries");
    traceFraction = result.fraction;
    traceEndPos = result.endpos;
    traceNormal = result.c.normal;
    tracePoint = result.c.point;
    traceSurfaceFlags = result.c.surfaceFlags;
    traceEntityNum = result.c.entityNum;
    lastOnGround = traceFraction < 1.0f;
}
void idAFConstraint_Suspension::CancelCollisionQueries() {
    traceQuery.index = 0;
}
void idAFConstraint_Suspension::DebugDraw() {
    idAFConstraint::DebugDraw();
}
void idAFConstraint_Suspension::Evaluate(const idPhysics_AF*,
        const float invTimeStep) {
    InitSize(1);
    if (!lastOnGround || body1 == nullptr) return;
    const idVec3 axis = BodyAxis(body1)[2];
    SetPointRow(J1, 0, body1, tracePoint, axis, 1.0f);
    const float totalTravel = suspensionUp + suspensionDown;
    const float compression = totalTravel * (1.0f - traceFraction);
    const float pointVelocity = body1->GetPointVelocity(tracePoint).Dot(axis);
    c1[0] = compression * suspensionCompress * invTimeStep
        - pointVelocity * suspensionDamping;
    lo[0] = 0.0f;
    hi[0] = motorEnabled ? (std::max)(motorForce, 0.0f) : 1.0e20f;
    debugSpringForce = c1[0];
    lastWheelHeight = compression;
}
void idAFConstraint_Suspension::Serialize(idSerializer* const serializer) {
    if (serializer != nullptr)
        GameLib_SerializeAFSuspension(serializer, *this);
}
