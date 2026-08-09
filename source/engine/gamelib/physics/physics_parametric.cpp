#include "gamelib/physics/physics_parametric.h"

#include "gamelib/physics/clip.h"
#include "gamelib/physics/clipmodel.h"
#include "gamelib/physics/push.h"
#include "idlib/math/rotation.h"

#include <algorithm>
#include <cmath>
#include <cstring>

bool GameLib_GetMasterPhysicsTransform(idPhysicsCallbacks* callbacks,
    idVec3& origin, idMat3& axis);
void GameLib_NotifyPhysicsActivated(idPhysicsCallbacks* callbacks,
    int physicsId);

namespace {

const idBounds kParametricZeroBounds{{idVec3(0.0f, 0.0f, 0.0f),
    idVec3(0.0f, 0.0f, 0.0f)}};
const idVec3 kParametricZeroVector(0.0f, 0.0f, 0.0f);
const idMat3 kParametricIdentityAxis(1.0f);

void ZeroSpatial(idVec6& value) {
    for (int index = 0; index < 6; ++index) value[index] = 0.0f;
}
void SetSpatial(idVec6& value, const idVec3& linear,
        const idVec3& angular) {
    value[0] = linear.x; value[1] = linear.y; value[2] = linear.z;
    value[3] = angular.x; value[4] = angular.y; value[5] = angular.z;
}
idVec3 SpatialLinear(const idVec6& value) {
    return idVec3(value[0], value[1], value[2]);
}
idVec3 SpatialAngular(const idVec6& value) {
    return idVec3(value[3], value[4], value[5]);
}

idAngles Mat3ToAngles(const idMat3& axis) {
    idAngles angles;
    const float forwardLength = std::sqrt(axis[0].x * axis[0].x
        + axis[0].y * axis[0].y);
    angles.pitch = std::atan2(-axis[0].z, forwardLength)
        * 57.29577951308232f;
    angles.yaw = std::atan2(axis[0].y, axis[0].x)
        * 57.29577951308232f;
    angles.roll = std::atan2(-axis[1].z, axis[2].z)
        * 57.29577951308232f;
    return angles;
}

idQuat Mat3ToQuat(const idMat3& matrix) {
    idQuat result;
    const float trace = matrix[0].x + matrix[1].y + matrix[2].z;
    if (trace > 0.0f) {
        const float scale = std::sqrt(trace + 1.0f) * 2.0f;
        result.w = 0.25f * scale;
        result.x = (matrix[2].y - matrix[1].z) / scale;
        result.y = (matrix[0].z - matrix[2].x) / scale;
        result.z = (matrix[1].x - matrix[0].y) / scale;
    } else if (matrix[0].x > matrix[1].y
            && matrix[0].x > matrix[2].z) {
        const float scale = std::sqrt(1.0f + matrix[0].x
            - matrix[1].y - matrix[2].z) * 2.0f;
        result.w = (matrix[2].y - matrix[1].z) / scale;
        result.x = 0.25f * scale;
        result.y = (matrix[0].y + matrix[1].x) / scale;
        result.z = (matrix[0].z + matrix[2].x) / scale;
    } else if (matrix[1].y > matrix[2].z) {
        const float scale = std::sqrt(1.0f + matrix[1].y
            - matrix[0].x - matrix[2].z) * 2.0f;
        result.w = (matrix[0].z - matrix[2].x) / scale;
        result.x = (matrix[0].y + matrix[1].x) / scale;
        result.y = 0.25f * scale;
        result.z = (matrix[1].z + matrix[2].y) / scale;
    } else {
        const float scale = std::sqrt(1.0f + matrix[2].z
            - matrix[0].x - matrix[1].y) * 2.0f;
        result.w = (matrix[1].x - matrix[0].y) / scale;
        result.x = (matrix[0].z + matrix[2].x) / scale;
        result.y = (matrix[1].z + matrix[2].y) / scale;
        result.z = 0.25f * scale;
    }
    result.Normalize();
    return result;
}

idMat3 QuatToMat3(idQuat quat) {
    quat.Normalize();
    const float xx = quat.x * quat.x;
    const float yy = quat.y * quat.y;
    const float zz = quat.z * quat.z;
    const float xy = quat.x * quat.y;
    const float xz = quat.x * quat.z;
    const float yz = quat.y * quat.z;
    const float wx = quat.w * quat.x;
    const float wy = quat.w * quat.y;
    const float wz = quat.w * quat.z;
    return idMat3(
        1.0f - 2.0f * (yy + zz), 2.0f * (xy - wz),
        2.0f * (xz + wy), 2.0f * (xy + wz),
        1.0f - 2.0f * (xx + zz), 2.0f * (yz - wx),
        2.0f * (xz - wy), 2.0f * (yz + wx),
        1.0f - 2.0f * (xx + yy));
}

bool MatrixChanged(const idMat3& first, const idMat3& second) {
    return (first[0] - second[0]).LengthSqr() != 0.0f
        || (first[1] - second[1]).LengthSqr() != 0.0f
        || (first[2] - second[2]).LengthSqr() != 0.0f;
}

} // namespace

parametricPState_t::parametricPState_t()
    : time(0)
    , atRest(-1)
    , worldOrigin(0.0f, 0.0f, 0.0f)
    , worldAngles(0.0f, 0.0f, 0.0f)
    , worldAxis(1.0f)
    , localOrigin(0.0f, 0.0f, 0.0f)
    , localAngles(0.0f, 0.0f, 0.0f)
    , linearExtrapolation()
    , angularExtrapolation()
    , linearInterpolation()
    , angularInterpolation()
    , spline(nullptr)
    , angularSpline(nullptr)
    , splineInterpolate()
    , useSplineAngles(false) {
    linearInterpolation.Init(0.0f, 0.0f, 0.0f, 0.0f,
        kParametricZeroVector, kParametricZeroVector);
    angularInterpolation.Init(0.0f, 0.0f, 0.0f, 0.0f,
        idAngles(0.0f, 0.0f, 0.0f), idAngles(0.0f, 0.0f, 0.0f));
    splineInterpolate.Init(0.0f, 1.0f, 1.0f, 2.0f, 0.0f, 0.0f);
}

idPhysics_Parametric::idPhysics_Parametric()
    : idPhysics_DynamicBase()
    , current()
    , saved(current)
    , spatialVelocity{}
    , blockingPhysicsId(-1)
    , absBounds(kParametricZeroBounds)
    , pusher(nullptr)
    , isPusher(false)
    , clipModel(nullptr)
    , pushFlags(0)
    , hasMaster(false)
    , isOrientated(false)
    , hasWorldOrientation(false)
    , worldAxis(1.0f)
    , worldOrigin(0.0f, 0.0f, 0.0f) {
    type = PHYSICS_PARAMETRIC;
    ZeroSpatial(spatialVelocity);
}

idPhysics_Parametric::~idPhysics_Parametric() {
    if (clipModel != nullptr) clipModel->Unlink();
    clipModel = nullptr;
}

void idPhysics_Parametric::SetPusher(idPush* const push, const int flags) {
    pusher = push;
    isPusher = push != nullptr;
    pushFlags = flags;
}
bool idPhysics_Parametric::IsPusher() const { return isPusher; }
idCurve_Spline<idVec3>* idPhysics_Parametric::GetSpline() {
    return current.spline;
}
const idAngles* idPhysics_Parametric::GetLocalAngles() const {
    return &current.localAngles;
}

void idPhysics_Parametric::SetClipModel(idClipModel* const model, float,
        int, const bool freeOld) {
    if (clipModel != nullptr && clipModel != model && freeOld)
        clipModel->Delete();
    clipModel = model;
    LinkClip();
}
idClipModel* idPhysics_Parametric::GetClipModel(int) { return clipModel; }
int idPhysics_Parametric::GetNumClipModels() { return clipModel != nullptr; }
void idPhysics_Parametric::SetMass(float, int) {}
float idPhysics_Parametric::GetMass(int) { return 0.0f; }
void idPhysics_Parametric::SetContents(const int contents, int) {
    if (clipModel != nullptr) clipModel->SetContents(contents);
}
int idPhysics_Parametric::GetContents(int) {
    return clipModel != nullptr ? clipModel->GetContents() : 0;
}
const idBounds* idPhysics_Parametric::GetBounds(int) {
    return clipModel != nullptr ? &clipModel->GetBounds()
        : &kParametricZeroBounds;
}
const idBounds* idPhysics_Parametric::GetAbsBounds(int) {
    if (clipModel != nullptr) return &clipModel->GetAbsBounds();
    absBounds[0] = current.worldOrigin;
    absBounds[1] = current.worldOrigin;
    return &absBounds;
}

void idPhysics_Parametric::SetLinearExtrapolation(
        const extrapolation_t extrapolation, const int currentTime,
        const int startTime, const int duration, const idVec3& base,
        const idVec3& baseSpeed, const idVec3& speed) {
    current.time = currentTime;
    current.linearExtrapolation.Init(static_cast<float>(startTime),
        static_cast<float>(duration), base, baseSpeed, speed, extrapolation);
    current.localOrigin = base;
    Activate();
}
void idPhysics_Parametric::SetAngularExtrapolation(
        const extrapolation_t extrapolation, const int currentTime,
        const int startTime, const int duration, const idAngles& base,
        const idAngles& baseSpeed, const idAngles& speed) {
    current.time = currentTime;
    current.angularExtrapolation.Init(static_cast<float>(startTime),
        static_cast<float>(duration), base, baseSpeed, speed, extrapolation);
    current.localAngles = base;
    Activate();
}
idAngles idPhysics_Parametric::GetCurrentAngularExtrapolationAngles(
        const int time) const {
    return current.angularExtrapolation.GetCurrentValue(
        static_cast<float>(time));
}
void idPhysics_Parametric::SetLinearInterpolation(const int currentTime,
        const int startTime, const int accelTime, const int decelTime,
        const int duration, const idVec3& start, const idVec3& end) {
    current.time = currentTime;
    current.linearInterpolation.Init(static_cast<float>(startTime),
        static_cast<float>(accelTime), static_cast<float>(decelTime),
        static_cast<float>(duration), start, end);
    current.localOrigin = start;
    Activate();
}
void idPhysics_Parametric::SetAngularInterpolation(const int currentTime,
        const int startTime, const int accelTime, const int decelTime,
        const int duration, const idAngles& start, const idAngles& end) {
    current.time = currentTime;
    current.angularInterpolation.Init(static_cast<float>(startTime),
        static_cast<float>(accelTime), static_cast<float>(decelTime),
        static_cast<float>(duration), start, end);
    current.localAngles = start;
    Activate();
}
void idPhysics_Parametric::SetSpline(idCurve_Spline<idVec3>* const spline,
        const int accelTime, const int decelTime,
        const bool useAngles,
        idCurve_Spline<idAngles>* const angularSpline) {
    current.spline = spline;
    current.angularSpline = angularSpline;
    current.useSplineAngles = useAngles;
    if (spline != nullptr && spline->GetNumValues() > 0) {
        const float start = spline->GetTime(0);
        const float end = spline->GetTime(spline->GetNumValues() - 1);
        const float length = spline->GetLengthForTime(end);
        current.splineInterpolate.Init(start,
            static_cast<float>(accelTime), static_cast<float>(decelTime),
            end - start, 0.0f, length);
    }
    Activate();
}

void idPhysics_Parametric::SetOrigin(const idVec3* const origin, int) {
    if (origin == nullptr) return;
    current.localOrigin = *origin;
    current.worldOrigin = *origin;
    current.linearExtrapolation.SetStartValue(*origin);
    current.linearInterpolation.SetStartValue(*origin);
    current.linearInterpolation.SetEndValue(*origin);
    if (hasMaster && callbacks != nullptr) {
        idVec3 masterOrigin;
        idMat3 masterAxis;
        if (GameLib_GetMasterPhysicsTransform(callbacks, masterOrigin,
                masterAxis)) {
            current.localOrigin = masterAxis.Transpose()
                * (*origin - masterOrigin);
            current.worldOrigin = *origin;
        }
    }
    LinkClip();
    Activate();
}
void idPhysics_Parametric::SetAxis(const idMat3* const axis, int) {
    if (axis == nullptr) return;
    current.worldAxis = *axis;
    current.worldAngles = Mat3ToAngles(*axis);
    current.localAngles = current.worldAngles;
    current.angularExtrapolation.SetStartValue(current.localAngles);
    current.angularInterpolation.SetStartValue(current.localAngles);
    current.angularInterpolation.SetEndValue(current.localAngles);
    LinkClip();
    Activate();
}
void idPhysics_Parametric::Translate(const idVec3* const translation, int) {
    if (translation == nullptr) return;
    const idVec3 target = current.worldOrigin + *translation;
    SetOrigin(&target, 0);
}
void idPhysics_Parametric::Rotate(const idRotation* const rotation, int) {
    if (rotation == nullptr) return;
    current.worldOrigin = *rotation * current.worldOrigin;
    current.worldAxis *= rotation->ToMat3();
    current.worldAngles = Mat3ToAngles(current.worldAxis);
    current.localAngles = current.worldAngles;
    LinkClip();
    Activate();
}
const idVec3* idPhysics_Parametric::GetOrigin(int) {
    return &current.worldOrigin;
}
const idMat3* idPhysics_Parametric::GetAxis(int) {
    return &current.worldAxis;
}
const idVec3* idPhysics_Parametric::GetLocalOrigin(int) {
    return &current.localOrigin;
}
const idMat3* idPhysics_Parametric::GetLocalAxis(int) {
    static idMat3 localAxis;
    localAxis = current.localAngles.ToMat3();
    return &localAxis;
}
void idPhysics_Parametric::SetLinearVelocity(const idVec3* const velocity,
        int) {
    if (velocity == nullptr) return;
    SetLinearExtrapolation(static_cast<extrapolation_t>(
        EXTRAPOLATION_LINEAR | EXTRAPOLATION_NOSTOP),
        current.time, current.time, 0, current.localOrigin,
        kParametricZeroVector, *velocity);
}
void idPhysics_Parametric::SetAngularVelocity(const idVec3* const velocity,
        int) {
    if (velocity == nullptr) return;
    const idAngles angularSpeed(velocity->x, velocity->y, velocity->z);
    SetAngularExtrapolation(static_cast<extrapolation_t>(
        EXTRAPOLATION_LINEAR | EXTRAPOLATION_NOSTOP),
        current.time, current.time, 0, current.localAngles,
        idAngles(0.0f, 0.0f, 0.0f), angularSpeed);
}
idVec3* idPhysics_Parametric::GetLinearVelocity(idVec3* const result, int) {
    if (result != nullptr) *result = SpatialLinear(spatialVelocity);
    return result;
}
idVec3* idPhysics_Parametric::GetAngularVelocity(idVec3* const result, int) {
    if (result != nullptr) *result = SpatialAngular(spatialVelocity);
    return result;
}
void idPhysics_Parametric::SetWaterEntNum(int) {}
int idPhysics_Parametric::GetWaterEntNum() { return -1; }
void idPhysics_Parametric::SetWaterSurfaceWrldHeight(float) {}
float idPhysics_Parametric::GetWaterSurfaceWrldHeight() { return 0.0f; }
void idPhysics_Parametric::GetImpactInfo(int, const idVec3*,
        impactInfo_t* const info) {
    if (info == nullptr) return;
    info->Zero();
    info->velocity = SpatialLinear(spatialVelocity);
}
void idPhysics_Parametric::ApplyImpulse(int, const idVec3*, const idVec3*) {}
void idPhysics_Parametric::ApplyForce(int, const idVec3*, const idVec3*) {}
void idPhysics_Parametric::Activate() {
    current.atRest = -1;
    if (callbacks != nullptr)
        GameLib_NotifyPhysicsActivated(callbacks, GetPhysicsId());
}
void idPhysics_Parametric::PutToRest() {
    current.atRest = current.time;
    ZeroSpatial(spatialVelocity);
}
bool idPhysics_Parametric::IsAtRest() { return current.atRest >= 0; }
bool idPhysics_Parametric::IsPushable(int) { return false; }
void idPhysics_Parametric::SaveState() { saved = current; }
void idPhysics_Parametric::RestoreState() {
    current = saved;
    LinkClip();
}

void idPhysics_Parametric::ForceUpdateSpatialVelocity(
        const int timeStepMSec) {
    if (timeStepMSec <= 0) return;
    const float inverseSeconds = 1000.0f / static_cast<float>(timeStepMSec);
    const idVec3 oldOrigin = current.worldOrigin;
    const idAngles oldAngles = current.worldAngles;
    const float sampleTime = static_cast<float>(current.time + timeStepMSec);
    idVec3 newOrigin = current.linearExtrapolation.GetCurrentValue(sampleTime);
    if (current.linearInterpolation.GetDuration() > 0.0f)
        newOrigin = current.linearInterpolation.GetCurrentValue(sampleTime);
    idAngles newAngles = current.angularExtrapolation.GetCurrentValue(sampleTime);
    if (current.angularInterpolation.GetDuration() > 0.0f)
        newAngles = current.angularInterpolation.GetCurrentValue(sampleTime);
    SetSpatial(spatialVelocity, (newOrigin - oldOrigin) * inverseSeconds,
        idVec3(newAngles.pitch - oldAngles.pitch,
            newAngles.yaw - oldAngles.yaw,
            newAngles.roll - oldAngles.roll) * inverseSeconds);
}

bool idPhysics_Parametric::Evaluate(int timeStepMSec,
        const int endTimeMSec) {
    const idVec3 oldOrigin = current.worldOrigin;
    const idMat3 oldAxis = current.worldAxis;
    current.time = endTimeMSec;
    idVec3 localOrigin = current.linearExtrapolation.GetCurrentValue(
        static_cast<float>(endTimeMSec));
    if (current.linearInterpolation.GetDuration() > 0.0f)
        localOrigin = current.linearInterpolation.GetCurrentValue(
            static_cast<float>(endTimeMSec));
    idAngles localAngles = current.angularExtrapolation.GetCurrentValue(
        static_cast<float>(endTimeMSec));
    if (current.angularInterpolation.GetDuration() > 0.0f)
        localAngles = current.angularInterpolation.GetCurrentValue(
            static_cast<float>(endTimeMSec));
    if (current.spline != nullptr && current.spline->GetNumValues() > 0) {
        const float length = current.splineInterpolate.GetCurrentValue(
            static_cast<float>(endTimeMSec));
        const float splineTime = current.spline->GetTimeForLength(length);
        localOrigin = current.spline->GetCurrentValue(splineTime);
        if (current.angularSpline != nullptr)
            localAngles = current.angularSpline->GetCurrentValue(splineTime);
    }
    current.localOrigin = localOrigin;
    current.localAngles = localAngles;
    idVec3 desiredOrigin = localOrigin;
    idMat3 desiredAxis = localAngles.ToMat3();
    if (hasMaster && callbacks != nullptr) {
        idVec3 masterOrigin;
        idMat3 masterAxis;
        if (GameLib_GetMasterPhysicsTransform(callbacks, masterOrigin,
                masterAxis)) {
            desiredOrigin = masterOrigin + masterAxis * localOrigin;
            if (isOrientated) desiredAxis *= masterAxis;
        }
    }
    if (hasWorldOrientation) {
        desiredOrigin = worldOrigin + worldAxis * desiredOrigin;
        desiredAxis *= worldAxis;
    }
    blockingPhysicsId = -1;
    if (isPusher && pusher != nullptr) {
        trace_t pushTrace{};
        pusher->ClipPush(pushTrace, this, pushFlags, oldOrigin, oldAxis,
            desiredOrigin, desiredAxis);
        if (pushTrace.fraction < 1.0f)
            blockingPhysicsId = pushTrace.c.physicsId;
    }
    current.worldOrigin = desiredOrigin;
    current.worldAngles = Mat3ToAngles(desiredAxis);
    current.worldAxis = desiredAxis;
    if (timeStepMSec > 0)
        SetSpatial(spatialVelocity,
            (current.worldOrigin - oldOrigin)
                * (1000.0f / static_cast<float>(timeStepMSec)),
            idVec3(current.worldAngles.pitch - Mat3ToAngles(oldAxis).pitch,
                current.worldAngles.yaw - Mat3ToAngles(oldAxis).yaw,
                current.worldAngles.roll - Mat3ToAngles(oldAxis).roll)
                * (1000.0f / static_cast<float>(timeStepMSec)));
    LinkClip();
    const bool linearDone = current.linearInterpolation.GetDuration() > 0.0f
        ? current.linearInterpolation.IsDone(static_cast<float>(endTimeMSec))
        : current.linearExtrapolation.IsDone(static_cast<float>(endTimeMSec));
    const bool angularDone = current.angularInterpolation.GetDuration() > 0.0f
        ? current.angularInterpolation.IsDone(static_cast<float>(endTimeMSec))
        : current.angularExtrapolation.IsDone(static_cast<float>(endTimeMSec));
    const bool splineDone = current.spline == nullptr
        || current.splineInterpolate.IsDone(static_cast<float>(endTimeMSec));
    if (linearDone && angularDone && splineDone) PutToRest();
    return (current.worldOrigin - oldOrigin).LengthSqr() != 0.0f
        || MatrixChanged(current.worldAxis, oldAxis);
}

void idPhysics_Parametric::UpdateTime(const int endTimeMSec) {
    const float delta = static_cast<float>(endTimeMSec - current.time);
    current.time = endTimeMSec;
    current.linearExtrapolation.SetStartTime(
        current.linearExtrapolation.GetStartTime() + delta);
    current.angularExtrapolation.SetStartTime(
        current.angularExtrapolation.GetStartTime() + delta);
    current.linearInterpolation.SetStartTime(
        current.linearInterpolation.GetStartTime() + delta);
    current.angularInterpolation.SetStartTime(
        current.angularInterpolation.GetStartTime() + delta);
    current.splineInterpolate.SetStartTime(
        current.splineInterpolate.GetStartTime() + delta);
    if (current.spline != nullptr) current.spline->ShiftTime(delta);
    if (current.angularSpline != nullptr) current.angularSpline->ShiftTime(delta);
}

void idPhysics_Parametric::ClipRotation(trace_t* const results,
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
        "idPhysics_Parametric::ClipRotation");
}
int idPhysics_Parametric::ClipContents(const idClipModel* const model,
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
            "idPhysics_Parametric::ClipContents");
    return result.c.contentFlags;
}
void idPhysics_Parametric::DisableClip() {
    if (clipModel != nullptr) clipModel->Disable();
}
void idPhysics_Parametric::EnableClip() {
    if (clipModel != nullptr) clipModel->Enable();
}
void idPhysics_Parametric::UnlinkClip() {
    if (clipModel != nullptr) clipModel->Unlink();
}
void idPhysics_Parametric::LinkClip() {
    if (clipModel != nullptr)
        clipModel->Link(GetEntityNumber(), GetEntityNumber(), 0,
            current.worldOrigin, current.worldAxis);
}
bool idPhysics_Parametric::EvaluateContacts() { return false; }
void idPhysics_Parametric::SetPushed(int) {}
idVec3* idPhysics_Parametric::GetPushedLinearVelocity(idVec3* result, int) {
    if (result != nullptr) result->Zero(); return result;
}
idVec3* idPhysics_Parametric::GetPushedAngularVelocity(idVec3* result, int) {
    if (result != nullptr) result->Zero(); return result;
}
void idPhysics_Parametric::SetMaster(const bool enable,
        const idVec3* const masterOrigin, const idMat3* const masterAxis,
        const bindFlags_t flags) {
    if (enable && masterOrigin != nullptr && masterAxis != nullptr) {
        current.localOrigin = masterAxis->Transpose()
            * (current.worldOrigin - *masterOrigin);
        current.localAngles = Mat3ToAngles((static_cast<int>(flags) & 1) != 0
            ? current.worldAxis * masterAxis->Transpose()
            : current.worldAxis);
        hasMaster = true;
        isOrientated = (static_cast<int>(flags) & 1) != 0;
    } else {
        hasMaster = false;
    }
}
void idPhysics_Parametric::SetLocalOrigin(const idVec3* origin, int) {
    if (origin == nullptr) return;
    current.localOrigin = *origin;
    current.linearExtrapolation.SetStartValue(*origin);
    Activate();
}
void idPhysics_Parametric::SetLocalAxis(const idMat3* axis, int) {
    if (axis == nullptr) return;
    current.localAngles = Mat3ToAngles(*axis);
    current.angularExtrapolation.SetStartValue(current.localAngles);
    Activate();
}
int idPhysics_Parametric::GetBlockingEntityNum() {
    idPhysics* physics = idPhysics::GetPhysicsForId(blockingPhysicsId);
    return physics != nullptr ? physics->GetEntityNumber() : 0x1FFF;
}
int idPhysics_Parametric::GetLinearEndTime() {
    if (current.linearInterpolation.GetDuration() > 0.0f)
        return static_cast<int>(current.linearInterpolation.GetEndTime());
    return (static_cast<int>(current.linearExtrapolation.extrapolationType)
        & EXTRAPOLATION_NOSTOP) != 0 ? 0
        : static_cast<int>(current.linearExtrapolation.GetEndTime());
}
int idPhysics_Parametric::GetAngularEndTime() {
    if (current.angularInterpolation.GetDuration() > 0.0f)
        return static_cast<int>(current.angularInterpolation.GetEndTime());
    return (static_cast<int>(current.angularExtrapolation.extrapolationType)
        & EXTRAPOLATION_NOSTOP) != 0 ? 0
        : static_cast<int>(current.angularExtrapolation.GetEndTime());
}
bool idPhysics_Parametric::IsOutsideWorld() {
    return idPhysics_DynamicBase::IsOutsideWorld();
}
void idPhysics_Parametric::SetWorldOrientation(const idVec3& origin,
        const idMat3& axis) {
    if (hasWorldOrientation) ClearWorldOrientation();
    worldOrigin = origin;
    worldAxis = axis;
    hasWorldOrientation = true;
}
void idPhysics_Parametric::ClearWorldOrientation() {
    hasWorldOrientation = false;
    worldOrigin.Zero();
    worldAxis = idMat3(1.0f);
}
extrapolation_t idPhysics_Parametric::GetAngularExtrapolationType() const {
    return current.angularExtrapolation.extrapolationType;
}

// Motion-matching parametric implementation.  Its authority uses the same
// physics contract but stores quaternion interpolation and explicit velocity.
parametricPState_tMM::parametricPState_tMM()
    : time(0), length(0.0f), totalLength(0.0f), atRest(-1),
      worldOrigin(0.0f, 0.0f, 0.0f), worldAxis(1.0f),
      localOrigin(0.0f, 0.0f, 0.0f), localAxis(1.0f),
      linearExtrapolation(), angularExtrapolation(),
      angularExtrapolationStartAxis(1.0f),
      angularExtrapolationRotVec(0.0f, 0.0f, 1.0f),
      linearVelocity(0.0f, 0.0f, 0.0f),
      angularVelocity(0.0f, 0.0f, 0.0f), linearInterpolation(),
      angularInterpolation(), splineInterpolate(),
      splineAngleInterpolate(), spline(nullptr),
      splineDerivative(0.0f, 0.0f, 0.0f), useSplineAngles(false),
      pauseTime(0), oscillationExtrapolation{},
      oscillationZRelative(false), localOffsetInterpolation(),
      splineMaster(nullptr), localOriginScaleInterpolation(),
      splineChilds(16), splineDummy(false) {
}

idPhysics_ParametricMM::idPhysics_ParametricMM()
    : idPhysics_DynamicBase(), current(), saved(current),
      blockingPhysicsId(-1), absBounds(kParametricZeroBounds), pusher(nullptr),
      isPusher(false), clipModel(nullptr), pushFlags(0), hasMaster(false),
      isOrientated(false), hasWorldOrientation(false), worldAxis(1.0f),
      worldOrigin(0.0f, 0.0f, 0.0f), collideClipMask(0),
      collideCallbackEnabled(false) {
    type = PHYSICS_PARAMETRIC;
}
idPhysics_ParametricMM::~idPhysics_ParametricMM() {
    if (clipModel != nullptr) clipModel->Unlink();
    clipModel = nullptr;
}
void idPhysics_ParametricMM::SetPusher(idPush* push, int flags) {
    pusher = push; isPusher = push != nullptr; pushFlags = flags;
}
idCurve_Spline<idVec3>* idPhysics_ParametricMM::GetSpline() {
    return current.spline;
}
void idPhysics_ParametricMM::SetUseSplineAngles(bool value) {
    current.useSplineAngles = value;
}
void idPhysics_ParametricMM::PauseParametricUntil(int resumeTime) {
    current.pauseTime = resumeTime;
}
void idPhysics_ParametricMM::SetClipModel(idClipModel* model, float, int,
        bool freeOld) {
    if (clipModel != nullptr && clipModel != model && freeOld)
        clipModel->Delete();
    clipModel = model; LinkClip();
}
idClipModel* idPhysics_ParametricMM::GetClipModel(int) { return clipModel; }
int idPhysics_ParametricMM::GetNumClipModels() { return clipModel != nullptr; }
void idPhysics_ParametricMM::SetMass(float, int) {}
float idPhysics_ParametricMM::GetMass(int) { return 0.0f; }
void idPhysics_ParametricMM::SetContents(int value, int) {
    if (clipModel != nullptr) clipModel->SetContents(value);
}
int idPhysics_ParametricMM::GetContents(int) {
    return clipModel != nullptr ? clipModel->GetContents() : 0;
}
const idBounds* idPhysics_ParametricMM::GetBounds(int) {
    return clipModel != nullptr ? &clipModel->GetBounds()
        : &kParametricZeroBounds;
}
const idBounds* idPhysics_ParametricMM::GetAbsBounds(int) {
    return clipModel != nullptr ? &clipModel->GetAbsBounds()
        : &kParametricZeroBounds;
}
void idPhysics_ParametricMM::SetOrigin(const idVec3* value, int) {
    if (value == nullptr) return;
    current.worldOrigin = *value; current.localOrigin = *value;
    current.linearExtrapolation.SetStartValue(*value); LinkClip(); Activate();
}
void idPhysics_ParametricMM::SetAxis(const idMat3* value, int) {
    if (value == nullptr) return;
    current.worldAxis = *value; current.localAxis = *value;
    LinkClip(); Activate();
}
void idPhysics_ParametricMM::Translate(const idVec3* value, int) {
    if (value == nullptr) return;
    current.worldOrigin = current.worldOrigin + *value;
    current.localOrigin = current.localOrigin + *value; LinkClip(); Activate();
}
void idPhysics_ParametricMM::Rotate(const idRotation* value, int) {
    if (value == nullptr) return;
    current.worldOrigin = *value * current.worldOrigin;
    current.worldAxis *= value->ToMat3();
    current.localAxis *= value->ToMat3(); LinkClip(); Activate();
}
const idVec3* idPhysics_ParametricMM::GetOrigin(int) {
    return &current.worldOrigin;
}
const idMat3* idPhysics_ParametricMM::GetAxis(int) { return &current.worldAxis; }
const idVec3* idPhysics_ParametricMM::GetLocalOrigin(int) {
    return &current.localOrigin;
}
const idMat3* idPhysics_ParametricMM::GetLocalAxis(int) {
    return &current.localAxis;
}
void idPhysics_ParametricMM::SetLinearVelocity(const idVec3* value, int) {
    if (value != nullptr) { current.linearVelocity = *value; Activate(); }
}
void idPhysics_ParametricMM::SetAngularVelocity(const idVec3* value, int) {
    if (value != nullptr) { current.angularVelocity = *value; Activate(); }
}
idVec3* idPhysics_ParametricMM::GetLinearVelocity(idVec3* result, int) {
    if (result != nullptr) *result = current.linearVelocity; return result;
}
idVec3* idPhysics_ParametricMM::GetAngularVelocity(idVec3* result, int) {
    if (result != nullptr) *result = current.angularVelocity; return result;
}
void idPhysics_ParametricMM::SetWaterEntNum(int) {}
int idPhysics_ParametricMM::GetWaterEntNum() { return -1; }
void idPhysics_ParametricMM::SetWaterSurfaceWrldHeight(float) {}
float idPhysics_ParametricMM::GetWaterSurfaceWrldHeight() { return 0.0f; }
void idPhysics_ParametricMM::GetImpactInfo(int, const idVec3*,
        impactInfo_t* info) {
    if (info != nullptr) { info->Zero(); info->velocity = current.linearVelocity; }
}
void idPhysics_ParametricMM::ApplyImpulse(int, const idVec3*, const idVec3*) {}
void idPhysics_ParametricMM::ApplyForce(int, const idVec3*, const idVec3*) {}
void idPhysics_ParametricMM::Activate() {
    current.atRest = -1;
    if (callbacks != nullptr)
        GameLib_NotifyPhysicsActivated(callbacks, GetPhysicsId());
}
void idPhysics_ParametricMM::PutToRest() {
    current.atRest = current.time; current.linearVelocity.Zero();
    current.angularVelocity.Zero();
}
bool idPhysics_ParametricMM::IsAtRest() { return current.atRest >= 0; }
bool idPhysics_ParametricMM::IsPushable(int) { return false; }
void idPhysics_ParametricMM::SaveState() { saved = current; }
void idPhysics_ParametricMM::RestoreState() { current = saved; LinkClip(); }
void idPhysics_ParametricMM::SetLinearExtrapolation(extrapolation_t type,
        int currentTime, int startTime, int duration, const idVec3& base,
        const idVec3& baseSpeed, const idVec3& speed) {
    current.time = currentTime;
    current.linearExtrapolation.Init(static_cast<float>(startTime),
        static_cast<float>(duration), base, baseSpeed, speed, type);
    current.localOrigin = base; Activate();
}
void idPhysics_ParametricMM::SetAngularExtrapolation(extrapolation_t type,
        int currentTime, int startTime, int duration,
        const idMat3& startAxis, const idVec3& rotationVector,
        float baseSpeed, float speed) {
    current.time = currentTime;
    current.angularExtrapolationStartAxis = startAxis;
    current.angularExtrapolationRotVec = rotationVector;
    current.angularExtrapolation.Init(static_cast<float>(startTime),
        static_cast<float>(duration), 0.0f, baseSpeed, speed, type);
    Activate();
}
void idPhysics_ParametricMM::SetSpline(idCurve_Spline<idVec3>* spline,
        int accelTime, int decelTime, bool useAngles) {
    current.spline = spline; current.useSplineAngles = useAngles;
    if (spline != nullptr && spline->GetNumValues() > 0) {
        const float start = spline->GetTime(0);
        const float end = spline->GetTime(spline->GetNumValues() - 1);
        current.totalLength = spline->GetLengthForTime(end);
        current.splineInterpolate.InitDuration(start, 0.0f,
            end - start, 0.0f, current.totalLength);
        (void)accelTime; (void)decelTime;
    }
    Activate();
}

bool idPhysics_ParametricMM::Evaluate(int timeStepMSec, int endTimeMSec) {
    if (current.pauseTime > endTimeMSec) return false;
    const idVec3 oldOrigin = current.worldOrigin;
    const idMat3 oldAxis = current.worldAxis;
    current.time = endTimeMSec;
    idVec3 localOrigin = current.linearExtrapolation.GetCurrentValue(
        static_cast<float>(endTimeMSec));
    if (current.linearInterpolation.GetDuration() > 0.0f)
        localOrigin = current.linearInterpolation.GetCurrentValue(
            static_cast<float>(endTimeMSec));
    if (current.spline != nullptr && current.spline->GetNumValues() > 0) {
        current.length = current.splineInterpolate.GetCurrentValue(
            static_cast<float>(endTimeMSec));
        const float time = current.spline->GetTimeForLength(current.length);
        localOrigin = current.spline->GetCurrentValue(time);
        current.splineDerivative = current.spline->GetCurrentFirstDerivative(time);
    }
    idMat3 localAxis = current.localAxis;
    if (current.angularInterpolation.GetDuration() > 0.0f)
        localAxis = QuatToMat3(current.angularInterpolation.GetCurrentValue(
            static_cast<float>(endTimeMSec)));
    else {
        const float angle = current.angularExtrapolation.GetCurrentValue(
            static_cast<float>(endTimeMSec));
        idRotation rotation(kParametricZeroVector,
            current.angularExtrapolationRotVec, angle);
        localAxis = current.angularExtrapolationStartAxis * rotation.ToMat3();
    }
    current.localOrigin = localOrigin;
    current.localAxis = localAxis;
    idVec3 desiredOrigin = localOrigin;
    idMat3 desiredAxis = localAxis;
    if (hasMaster && callbacks != nullptr) {
        idVec3 masterOrigin; idMat3 masterAxis;
        if (GameLib_GetMasterPhysicsTransform(callbacks, masterOrigin,
                masterAxis)) {
            desiredOrigin = masterOrigin + masterAxis * localOrigin;
            if (isOrientated) desiredAxis *= masterAxis;
        }
    }
    if (hasWorldOrientation) {
        desiredOrigin = worldOrigin + worldAxis * desiredOrigin;
        desiredAxis *= worldAxis;
    }
    blockingPhysicsId = -1;
    if (isPusher && pusher != nullptr) {
        trace_t trace{};
        pusher->ClipPush(trace, this, pushFlags, oldOrigin, oldAxis,
            desiredOrigin, desiredAxis);
        if (trace.fraction < 1.0f) blockingPhysicsId = trace.c.physicsId;
    }
    current.worldOrigin = desiredOrigin;
    current.worldAxis = desiredAxis;
    if (timeStepMSec > 0) {
        current.linearVelocity = (desiredOrigin - oldOrigin)
            * (1000.0f / static_cast<float>(timeStepMSec));
        const idAngles oldAngles = Mat3ToAngles(oldAxis);
        const idAngles newAngles = Mat3ToAngles(desiredAxis);
        current.angularVelocity = idVec3(
            newAngles.pitch - oldAngles.pitch,
            newAngles.yaw - oldAngles.yaw,
            newAngles.roll - oldAngles.roll)
            * (1000.0f / static_cast<float>(timeStepMSec));
    }
    LinkClip();
    return (desiredOrigin - oldOrigin).LengthSqr() != 0.0f
        || MatrixChanged(desiredAxis, oldAxis);
}
void idPhysics_ParametricMM::UpdateTime(int endTimeMSec) {
    const float delta = static_cast<float>(endTimeMSec - current.time);
    current.time = endTimeMSec;
    current.linearExtrapolation.SetStartTime(
        current.linearExtrapolation.GetStartTime() + delta);
    current.angularExtrapolation.SetStartTime(
        current.angularExtrapolation.GetStartTime() + delta);
    if (current.spline != nullptr) current.spline->ShiftTime(delta);
}
void idPhysics_ParametricMM::ClipRotation(trace_t* results,
        const idRotation* rotation, const idClipModel* model) {
    if (results == nullptr) return;
    const idClipModel* moving = model != nullptr ? model : clipModel;
    if (clip == nullptr || moving == nullptr || rotation == nullptr) {
        std::memset(results, 0, sizeof(*results)); results->fraction = 1.0f;
        return;
    }
    clip->Rotation(results, current.worldOrigin, *rotation, moving,
        current.worldAxis, clipMask, GetEntityNumber(), false,
        "idPhysics_ParametricMM::ClipRotation");
}
int idPhysics_ParametricMM::ClipContents(const idClipModel* model,
        int mask) {
    if (clip == nullptr || clipModel == nullptr) return 0;
    if (mask == 0) mask = clipMask;
    trace_t result{};
    if (model != nullptr)
        clip->ContentsModel(result, current.worldOrigin, clipModel,
            current.worldAxis, mask, model->GetOrigin(), model,
            model->GetAxis());
    else
        clip->Contents(&result, current.worldOrigin, clipModel,
            current.worldAxis, mask, GetEntityNumber(),
            "idPhysics_ParametricMM::ClipContents");
    return result.c.contentFlags;
}
void idPhysics_ParametricMM::DisableClip() { if (clipModel) clipModel->Disable(); }
void idPhysics_ParametricMM::EnableClip() { if (clipModel) clipModel->Enable(); }
void idPhysics_ParametricMM::UnlinkClip() { if (clipModel) clipModel->Unlink(); }
void idPhysics_ParametricMM::LinkClip() {
    if (clipModel) clipModel->Link(GetEntityNumber(), GetEntityNumber(), 0,
        current.worldOrigin, current.worldAxis);
}
bool idPhysics_ParametricMM::EvaluateContacts() { return false; }
void idPhysics_ParametricMM::SetPushed(int) {}
idVec3* idPhysics_ParametricMM::GetPushedLinearVelocity(idVec3* result, int) {
    if (result) result->Zero(); return result;
}
idVec3* idPhysics_ParametricMM::GetPushedAngularVelocity(idVec3* result, int) {
    if (result) result->Zero(); return result;
}
void idPhysics_ParametricMM::SetMaster(bool enable,
        const idVec3* masterOrigin, const idMat3* masterAxis,
        bindFlags_t flags) {
    if (enable && masterOrigin != nullptr && masterAxis != nullptr) {
        current.localOrigin = masterAxis->Transpose()
            * (current.worldOrigin - *masterOrigin);
        current.localAxis = (static_cast<int>(flags) & 1) != 0
            ? current.worldAxis * masterAxis->Transpose() : current.worldAxis;
        hasMaster = true; isOrientated = (static_cast<int>(flags) & 1) != 0;
    } else hasMaster = false;
}
void idPhysics_ParametricMM::SetLocalOrigin(const idVec3* value, int) {
    if (value) { current.localOrigin = *value; Activate(); }
}
void idPhysics_ParametricMM::SetLocalAxis(const idMat3* value, int) {
    if (value) { current.localAxis = *value; Activate(); }
}
int idPhysics_ParametricMM::GetBlockingEntityNum() {
    idPhysics* physics = idPhysics::GetPhysicsForId(blockingPhysicsId);
    return physics ? physics->GetEntityNumber() : 0x1FFF;
}
int idPhysics_ParametricMM::GetLinearEndTime() {
    return (static_cast<int>(current.linearExtrapolation.extrapolationType)
        & EXTRAPOLATION_NOSTOP) != 0 ? 0
        : static_cast<int>(current.linearExtrapolation.GetEndTime());
}
int idPhysics_ParametricMM::GetAngularEndTime() {
    return (static_cast<int>(current.angularExtrapolation.extrapolationType)
        & EXTRAPOLATION_NOSTOP) != 0 ? 0
        : static_cast<int>(current.angularExtrapolation.GetEndTime());
}
bool idPhysics_ParametricMM::IsOutsideWorld() {
    return idPhysics_DynamicBase::IsOutsideWorld();
}
