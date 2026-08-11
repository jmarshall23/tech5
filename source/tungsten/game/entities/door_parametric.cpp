#include "game/entities/door_parametric.h"

#include <algorithm>
#include <cmath>

namespace {
idDoorParametricServices defaultParametricServices;
idDoorParametricServices* parametricServices = &defaultParametricServices;

idEntity* AsEntity(idDoor_Parametric* const door) {
    return reinterpret_cast<idEntity*>(door);
}

const idEntity* AsEntity(const idDoor_Parametric* const door) {
    return reinterpret_cast<const idEntity*>(door);
}

idVec3 TransformVector(const idMat3& axis, const idVec3& vector) {
    return axis[0] * vector.x + axis[1] * vector.y
        + axis[2] * vector.z;
}

idBounds Expanded(const idBounds& source, const float amount) {
    idBounds result = source;
    const idVec3 expansion(amount, amount, amount);
    result[0] = result[0] - expansion;
    result[1] = result[1] + expansion;
    return result;
}

idBounds UnionBounds(const idBounds& left, const idBounds& right) {
    idBounds result;
    for (int axis = 0; axis < 3; ++axis) {
        result[0][axis] = std::min(left[0][axis], right[0][axis]);
        result[1][axis] = std::max(left[1][axis], right[1][axis]);
    }
    return result;
}

bool NearZero(const idVec3& value, const float epsilonSquared) {
    return value.LengthSqr() <= epsilonSquared;
}

idVec3 RotateAroundAxis(const idVec3& vector, const idVec3& axis,
        const float degrees) {
    constexpr float degreesToRadians = 0.01745329251994329577f;
    const float radians = degrees * degreesToRadians;
    const float cosine = std::cos(radians);
    const float sine = std::sin(radians);
    return vector * cosine + axis.Cross(vector) * sine
        + axis * (axis.Dot(vector) * (1.0f - cosine));
}

idMat3 OrientationAtAngle(const idMat3& base, const idVec3& axis,
        const float degrees) {
    idMat3 result;
    for (int index = 0; index < 3; ++index) {
        result[index] = RotateAroundAxis(base[index], axis, degrees);
    }
    return result;
}
}

int idDoorParametricServices::GetGameMilliseconds() const { return 0; }
void idDoorParametricServices::HideEntity(idDoor_Parametric&) {}
void idDoorParametricServices::ShowEntity(idDoor_Parametric&) {}
void idDoorParametricServices::BecomeInactive(idDoor_Parametric&, int) {}
void idDoorParametricServices::BecomeActive(idDoor_Parametric&, int) {}
void idDoorParametricServices::UnlinkClip(idDoor_Parametric&) {}
void idDoorParametricServices::LinkClip(idDoor_Parametric&) {}
void idDoorParametricServices::RunPhysics(idDoor_Parametric&) {}
bool idDoorParametricServices::IsActor(const idEntity*) const { return false; }
bool idDoorParametricServices::IsAI(const idEntity*) const { return false; }
void idDoorParametricServices::ReportNonActorAIUse(const idEntity*) const {}
idVec3 idDoorParametricServices::GetEntityOrigin(const idEntity*) const {
    return idVec3(0.0f, 0.0f, 0.0f);
}
idBounds idDoorParametricServices::GetEntityBounds(const idEntity*) const {
    idBounds result;
    result[0].Zero();
    result[1].Zero();
    return result;
}
void idDoorParametricServices::PlaySound(idDoor_Parametric&,
        const idSoundShader*) {}
void idDoorParametricServices::DeleteRequiredKey(idEntity*,
        const idDeclInventory*) {}
bool idDoorParametricServices::IsMegaModel(
        const idDoor_Parametric&) const { return false; }
void idDoorParametricServices::WarnSpawn(const idDoor_Parametric&,
        const char*) {}
void idDoorParametricServices::QueueRemove(idDoor_Parametric&) {}
idClipModel* idDoorParametricServices::AllocateFrameClip(
        idDoor_Parametric&, idRenderModel*) { return nullptr; }
idPresentable* idDoorParametricServices::AllocateFramePresentable(
        idDoor_Parametric&, idRenderModel*) { return nullptr; }
idPresentable* idDoorParametricServices::AllocateAnimatedPresentable(
        idDoor_Parametric&, idRenderModel*) { return nullptr; }
void idDoorParametricServices::DeleteClipModel(idClipModel*) {}
void idDoorParametricServices::DeletePresentable(idPresentable*) {}
void idDoorParametricServices::FreeMainPresentable(idDoor_Parametric&) {}
void idDoorParametricServices::ReleaseRenderModel(idRenderModel*) {}
void idDoorParametricServices::ConfigureFrame(idDoor_Parametric&,
        idClipModel*, idPresentable*, const idVec3&, const idMat3&) {}
void idDoorParametricServices::ConfigureParametricPhysics(
        idDoor_Parametric&, idRenderModel*, const idVec3&,
        const idMat3&, int) {}
idBounds idDoorParametricServices::GetDoorClipBounds(
        const idDoor_Parametric&) const {
    idBounds result;
    result[0].Set(-1.0f, -1.0f, -1.0f);
    result[1].Set(1.0f, 1.0f, 1.0f);
    return result;
}
void idDoorParametricServices::SetDoorContents(idDoor_Parametric&, int) {}
void idDoorParametricServices::PresentFrame(idPresentable*) {}
void idDoorParametricServices::PresentAttachment(idPresentable*,
        const idVec3&, const idMat3&) {}
void idDoorParametricServices::PresentDoor(idDoor_Parametric&) {}
void idDoorParametricServices::ConfigureMainClipInfo(
        idDoor_Parametric&, const idVec3&, const idMat3&, int) {}
void idDoorParametricServices::AddDoorMotionEvent(idDoor_Parametric&,
        idEntity*, const idVec3&, int) {}
bool idDoorParametricServices::IsGatherQuerySubmitted(
        std::uint64_t) const { return false; }
bool idDoorParametricServices::GatheredQueryHasActor(
        std::uint64_t) const { return false; }
std::uint64_t idDoorParametricServices::SubmitActorGather(
        const idBounds&, int) { return 0; }
float idDoorParametricServices::GetDoorClosingRange() const {
    return 16.0f;
}
void idDoorParametricServices::BeginAngularInterpolation(
        idDoor_Parametric&, int, int, float, float) {}
void idDoorParametricServices::BeginLinearInterpolation(
        idDoor_Parametric&, int, int, const idVec3&, const idVec3&) {}
void idDoorParametricServices::ConvertToRigidBody(idDoor_Parametric&,
        const idVec3&, const idMat3&, const idVec3&) {}
void idDoorParametricServices::SetFrameClipContents(
        idDoor_Parametric&, int) {}
void idDoorParametricServices::ScheduleLockGrindAngle(
        idDoor_Parametric&, const idDoorParametricAngleCommand&) {}
void idDoorParametricServices::ScheduleDisableObstacle(
        idDoor_Parametric&, int) {}

void idDoor_Parametric::SetServices(
        idDoorParametricServices* const services) {
    parametricServices = services == nullptr
        ? &defaultParametricServices : services;
}

idDoorParametricServices& idDoor_Parametric::ParametricServices() {
    return *parametricServices;
}

// Retail: 0x82C24870 ?Hide@idDoor_Parametric@@UAAXXZ
void idDoor_Parametric::Hide() {
    ParametricServices().HideEntity(*this);
    hidden = true;
    thinkFlags &= ~7;
    ParametricServices().BecomeInactive(*this, 7);
    clipLinked = false;
    ParametricServices().UnlinkClip(*this);
}

// Retail: 0x82C248C0 ?Show@idDoor_Parametric@@UAAXXZ
void idDoor_Parametric::Show() {
    ParametricServices().ShowEntity(*this);
    hidden = false;
    clipLinked = true;
    ParametricServices().LinkClip(*this);
}

// Retail: 0x82C24908 ?SetLocked@idDoor_Parametric@@UAAX_NPAVidEntity@@@Z
void idDoor_Parametric::SetLocked(const bool lock, idEntity* const user) {
    locked = lock;
    if (!lock && IsClosed() && opensWhenUnlocked) {
        Use(user, USABLE_DOOR);
    }
    UpdateAASAreas();
}

// Retail: 0x82C249A8 ?IsLockedForEntity@idDoor_Parametric@@UBA_NPBVidEntity@@M@Z
bool idDoor_Parametric::IsLockedForEntity(const idEntity* const entity,
        const float kickedAmount) const {
    if (kickedAmount != 0.0f && kickUnlocks
            && ParametricServices().IsAI(entity)) {
        return false;
    }
    return idDoor_Base::IsLockedForEntity(entity, kickedAmount);
}

// Retail: 0x82C24A30 ?Event_IsOpen@idDoor_Parametric@@AAA?AVeventBool@@XZ
bool idDoor_Parametric::Event_IsOpen() const { return IsOpen(); }

// Retail: 0x82C24A80 ?Event_IsClosed@idDoor_Parametric@@AAA?AVeventBool@@XZ
bool idDoor_Parametric::Event_IsClosed() const { return IsClosed(); }

// Retail: 0x82C24AD0 ?Event_IsLockedForEntity@idDoor_Parametric@@AAA?AVeventBool@@PAVidEntity@@@Z
bool idDoor_Parametric::Event_IsLockedForEntity(
        idEntity* const entity) const {
    return ParametricServices().IsActor(entity)
        && IsLockedForEntity(entity, 0.0f);
}

// Retail: 0x82C24B48 ?Event_GetCenterOfDoor@idDoor_Parametric@@AAA?AVeventVector@@XZ
idVec3 idDoor_Parametric::Event_GetCenterOfDoor() const {
    return door_center;
}

// Retail: 0x82C24B88 ?AllocPresentable@idDoor_Parametric@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
idPresentable* idDoor_Parametric::AllocPresentable(
        idRenderModel* const renderModel) {
    return ParametricServices().AllocateAnimatedPresentable(
        *this, renderModel);
}

// Retail: 0x82C24C48 ?AutoClose@idDoor_Parametric@@AAAXXZ
void idDoor_Parametric::AutoClose() {
    if (state == DOOR_BROKEN || autoCloseTime == 0 || close_time <= 0) {
        return;
    }
    const int currentTime = ParametricServices().GetGameMilliseconds();
    if (currentTime - autoCloseTime <= close_time) {
        if (!CanClose(false)) {
            autoCloseTime = currentTime;
        }
        return;
    }
    autoCloseTime = 0;
    Use(AsEntity(this), USABLE_DOOR);
}

// Retail: 0x82C24D18 ?Unlock@idDoor_Parametric@@AAA_NPAVidActor@@M@Z
bool idDoor_Parametric::Unlock(idEntity* const user,
        const float kickedAmount) {
    if (IsLockedForEntity(user, kickedAmount)) {
        ParametricServices().PlaySound(*this, lockedSound);
        return false;
    }
    SetLocked(false, user);
    ParametricServices().PlaySound(*this,
        kickedAmount == 0.0f ? unlockSound : kick_open_sound);
    if (removeKeyOnUse) {
        ParametricServices().DeleteRequiredKey(user, requiredKey);
    }
    return true;
}

// Retail: 0x82C24E20 ?GetUseLocation@idDoor_Parametric@@UBAXPBVidActor@@AAVidVec3@@@Z
void idDoor_Parametric::GetUseLocation(const idEntity* const actor,
        idVec3& position) const {
    const idVec3 actorDelta = ParametricServices().GetEntityOrigin(actor)
        - physicsOrigin;
    const idVec3 sideNormal = default_axis.Cross(rotate_axis);
    const idBounds actorBounds = ParametricServices().GetEntityBounds(actor);
    const idVec3 actorSize = actorBounds[1] - actorBounds[0];
    const float radius = std::max(actorSize.x, actorSize.y) * 0.5f + 1.0f;
    const idVec3 offset = door_ai_offset + sideNormal * radius;
    position = sideNormal.Dot(actorDelta) <= 0.0f
        ? door_center - offset : door_center + offset;
}

// Retail: 0x82C24FC0 ?GetCurrentAngle@idDoor_Parametric@@ABAMXZ
float idDoor_Parametric::GetCurrentAngle() const {
    constexpr float radiansToDegrees = 57.295779513082320876f;
    const idVec3& heading = physicsAxis[heading_axis];
    const float cosine = std::max(-1.0f,
        std::min(1.0f, heading.Dot(default_axis)));
    float angle = std::acos(cosine) * radiansToDegrees;
    if (rotate_axis.Dot(default_axis.Cross(heading)) < 0.0f) {
        angle = -angle;
    }
    return angle;
}

// Retail: 0x82C250C0 ?GetSoundTransform@idDoor_Parametric@@UBAXAAVidVec3@@AAVidMat3@@@Z
void idDoor_Parametric::GetSoundTransform(idVec3& soundOrigin,
        idMat3& soundAxis) const {
    const idVec3 localCenter = (doorClipBounds[0]
        + doorClipBounds[1]) * 0.5f;
    soundOrigin = physicsOrigin + TransformVector(physicsAxis, localCenter);
    soundAxis = physicsAxis;
}

// Retail: 0x82C25278 ?Event_GetAIUsePosition@idDoor_Parametric@@AAA?AVeventVector@@PAVidEntity@@@Z
idVec3 idDoor_Parametric::Event_GetAIUsePosition(
        idEntity* const entity) const {
    idVec3 result(0.0f, 0.0f, 0.0f);
    if (!ParametricServices().IsActor(entity)) {
        ParametricServices().ReportNonActorAIUse(entity);
        return result;
    }
    GetUseLocation(entity, result);
    return result;
}

// Retail: 0x82C252E8 ?Event_LockGrinderSetAngleAtTime@idDoor_Parametric@@AAA?AVeventVoid@@PAVidEntity@@ABVidVec3@@MM@Z
void idDoor_Parametric::Event_LockGrinderSetAngleAtTime(
        idEntity* const activator, const idVec3& direction,
        const float duration, const float yaw) {
    const idVec3 sideNormal = default_axis.Cross(rotate_axis);
    float desiredYaw;
    if (direction.Dot(sideNormal) <= 0.0f) {
        desiredYaw = std::max(-max_angle, std::min(0.0f, -yaw));
    } else {
        desiredYaw = std::max(0.0f, std::min(max_angle, yaw));
    }
    const int currentTime = ParametricServices().GetGameMilliseconds();
    const int durationMilliseconds = std::max(0,
        static_cast<int>(duration));
    targetAngle = desiredYaw;
    angularEndTime = currentTime + durationMilliseconds;
    ParametricServices().BeginAngularInterpolation(*this,
        currentTime, durationMilliseconds, GetCurrentAngle(), desiredYaw);
    (void)activator;
}

// Retail: 0x82C25448 ?Event_DisableObstacleFlag@idDoor_Parametric@@AAA?AVeventVoid@@XZ
void idDoor_Parametric::Event_DisableObstacleFlag() {
    physicsContents = 1;
    ParametricServices().SetDoorContents(*this, physicsContents);
}

// Retail: 0x82C25490 ?LockGrind@idDoor_Parametric@@UAAXPAVidEntity@@0@Z
void idDoor_Parametric::LockGrind(idEntity* const source,
        idEntity* const lockGrinder) {
    SetDoorState(source, DOOR_OPENING);
    const int currentTime = ParametricServices().GetGameMilliseconds();
    autoCloseTime = currentTime;
    if (forceUnusableWhenOpened || forcedUnusable) {
        forcedUnusable = true;
        autoCloseTime = 0;
    }
    const idVec3 direction = ParametricServices().GetEntityOrigin(lockGrinder)
        - physicsOrigin;
    physicsContents = 128;
    ParametricServices().SetDoorContents(*this, physicsContents);

    const auto schedule = [this, source, &direction](
            const float duration, const float yaw) {
        idDoorParametricAngleCommand command;
        command.activator = source;
        command.direction = direction;
        command.duration = duration;
        command.yaw = yaw;
        ParametricServices().ScheduleLockGrindAngle(*this, command);
    };
    if (lockGrindRestAngle == 160.0f) {
        schedule(80.0f, lockGrindRestAngle);
        schedule(110.0f, lockGrindRestAngle * 0.33329999f);
    } else {
        schedule(90.0f, 80.0f);
        schedule(30.0f, 110.0f);
    }
    schedule(lockGrindRestAngle + 10.0f, 510.0f);
    schedule(500.0f, lockGrindRestAngle);
    ParametricServices().ScheduleDisableObstacle(*this, 700);
    forceUnopenedTime = currentTime + 1250;
}

// Retail: 0x82C25990 ??1idDoor_Parametric@@UAA@XZ
idDoor_Parametric::~idDoor_Parametric() {
    if (frameClip != nullptr) {
        ParametricServices().DeleteClipModel(frameClip);
        frameClip = nullptr;
    }
    if (framePresentable != nullptr) {
        ParametricServices().DeletePresentable(framePresentable);
        framePresentable = nullptr;
    }
    if (doorAttachment != nullptr) {
        ParametricServices().DeletePresentable(doorAttachment);
        doorAttachment = nullptr;
    }
    ParametricServices().FreeMainPresentable(*this);
    if (frame != nullptr) {
        ParametricServices().ReleaseRenderModel(frame);
        frame = nullptr;
    }
    if (door != nullptr) {
        ParametricServices().ReleaseRenderModel(door);
        door = nullptr;
    }
}

// Retail: 0x82C25B20 ?Spawn@idDoor_Parametric@@QAAXXZ
void idDoor_Parametric::Spawn() {
    if (max_angle <= min_angle) {
        ParametricServices().WarnSpawn(*this, "max_angle <= min_angle");
        removed = true;
        ParametricServices().QueueRemove(*this);
        return;
    }
    if (door == nullptr) {
        ParametricServices().WarnSpawn(*this, "door render model isn't set");
        removed = true;
        ParametricServices().QueueRemove(*this);
        return;
    }
    if (ParametricServices().IsMegaModel(*this)) {
        ParametricServices().WarnSpawn(*this, "door cannot be a mega model");
        removed = true;
        ParametricServices().QueueRemove(*this);
        return;
    }

    spawnOrientation.OrthoNormalizeSelf();
    physicsOrigin = spawnPosition;
    physicsAxis = spawnOrientation;
    if (frame != nullptr) {
        frameClip = ParametricServices().AllocateFrameClip(*this, frame);
        framePresentable = ParametricServices().AllocateFramePresentable(
            *this, frame);
        ParametricServices().ConfigureFrame(*this, frameClip,
            framePresentable, spawnPosition, spawnOrientation);
    }

    physicsContents = (!usableByAI || IsLocked()) ? 131073 : 1;
    ParametricServices().ConfigureParametricPhysics(*this, door,
        spawnPosition, spawnOrientation, physicsContents);
    if (slidingDoor) {
        linearOffset.Zero();
        targetLinearOffset.Zero();
        linearEndTime = ParametricServices().GetGameMilliseconds();
    } else {
        currentAngle = start_angle;
        targetAngle = start_angle;
        angularEndTime = ParametricServices().GetGameMilliseconds();
    }

    if (rotation_axis < AXIS_X || rotation_axis > AXIS_Z) {
        rotation_axis = AXIS_Z;
    }
    rotate_axis = spawnOrientation[rotation_axis];
    heading_axis = static_cast<axis_t>((rotation_axis + 1) % 3);
    default_axis = spawnOrientation[heading_axis];
    if (!slidingDoor) {
        physicsAxis = OrientationAtAngle(spawnOrientation,
            rotate_axis, currentAngle);
    }
    switch (slideDir) {
        case SLIDE_UP: slideVec.Set(0.0f, 0.0f, 1.0f); break;
        case SLIDE_DOWN: slideVec.Set(0.0f, 0.0f, -1.0f); break;
        case SLIDE_LEFT: slideVec.Set(-1.0f, 0.0f, 0.0f); break;
        case SLIDE_RIGHT: slideVec.Set(1.0f, 0.0f, 0.0f); break;
        case SLIDE_FORWARD: slideVec.Set(0.0f, 1.0f, 0.0f); break;
        default: slideVec.Set(0.0f, -1.0f, 0.0f); break;
    }
    closedPos = spawnPosition;
    doorClipBounds = ParametricServices().GetDoorClipBounds(*this);
    idBounds absoluteDoorBounds;
    absoluteDoorBounds.FromTransformedBounds(doorClipBounds,
        physicsOrigin, physicsAxis);
    if (frame == nullptr) {
        bounds = absoluteDoorBounds;
    } else {
        bounds = UnionBounds(bounds, absoluteDoorBounds);
    }

    idVec3 localCenter = (doorClipBounds[0] + doorClipBounds[1]) * 0.5f;
    localCenter.y = doorClipBounds[1].y;
    localCenter.z = doorClipBounds[0].z;
    door_center = physicsOrigin + TransformVector(spawnOrientation,
        localCenter);
    const float halfDepth = (doorClipBounds[1].y
        - doorClipBounds[0].y) * 0.5f;
    door_ai_offset = spawnOrientation[1] * -halfDepth;
    UpdateAASAreas();
    SetDoorState(AsEntity(this), DOOR_UNKNOWN);
    UpdateState();
    ParametricServices().PresentDoor(*this);
    ParametricServices().ConfigureMainClipInfo(*this,
        physicsOrigin, physicsAxis, physicsContents);
}

// Retail: 0x82C26560 ?Think@idDoor_Parametric@@UAAXXZ
void idDoor_Parametric::Think() {
    AutoClose();
    ParametricServices().RunPhysics(*this);
    UpdateState();
    if (framePresentable != nullptr) {
        ParametricServices().PresentFrame(framePresentable);
    }
    if (doorAttachment != nullptr) {
        ParametricServices().PresentAttachment(doorAttachment,
            physicsOrigin, physicsAxis);
    }
    if (state == DOOR_CLOSED || state == DOOR_BROKEN) {
        thinkFlags &= ~7;
        ParametricServices().BecomeInactive(*this, 7);
    } else if ((autoCloseTime <= 0 || close_time <= 0)
            && state == DOOR_OPENED) {
        thinkFlags &= ~7;
        forceUnopenedTime = 0;
        ParametricServices().BecomeInactive(*this, 7);
    } else {
        thinkFlags |= 1;
        ParametricServices().BecomeActive(*this, 1);
    }
}

// Retail: 0x82C266F0 ?CanClose@idDoor_Parametric@@EBA_N_N@Z
bool idDoor_Parametric::CanClose(const bool testingForUse) const {
    idBounds queryBounds;
    if (testingForUse) {
        idBounds absoluteDoorBounds;
        absoluteDoorBounds.FromTransformedBounds(doorClipBounds,
            physicsOrigin, physicsAxis);
        queryBounds = Expanded(UnionBounds(bounds, absoluteDoorBounds),
            ParametricServices().GetDoorClosingRange());
    } else {
        const float range = static_cast<float>(close_range);
        queryBounds[0].Set(door_center.x - range,
            door_center.y - range, door_center.z);
        queryBounds[1].Set(door_center.x + range,
            door_center.y + range, door_center.z + 64.0f);
    }
    if (ParametricServices().IsGatherQuerySubmitted(canCloseQuery)
            && ParametricServices().GatheredQueryHasActor(canCloseQuery)) {
        return false;
    }
    canCloseQuery = ParametricServices().SubmitActorGather(
        queryBounds, 33792);
    return true;
}

// Retail: 0x82C268F8 ?Use@idDoor_Parametric@@UAA_NPAVidEntity@@W4usableState_t@@@Z
bool idDoor_Parametric::Use(idEntity* const user, int) {
    float minimumAngle = kicked == 0.0f ? min_angle : min_kick_angle;
    const float maximumAngle = kicked == 0.0f
        ? max_angle : max_kick_angle;
    const bool wasClosed = IsClosed();
    if (wasClosed && locked) {
        if (!ParametricServices().IsActor(user) || !Unlock(user, kicked)) {
            return false;
        }
        if (kicked != 0.0f && kickOffHinges) {
            frameClipContents = 186;
            ParametricServices().SetFrameClipContents(*this,
                frameClipContents);
            idVec3 impulseDirection = physicsOrigin
                - ParametricServices().GetEntityOrigin(user);
            impulseDirection.NormalizeFast();
            const idVec3 velocity(impulseDirection.x * 150.0f,
                impulseDirection.y * 150.0f, 200.0f);
            usingRigidBody = true;
            physicsContents = 0;
            ParametricServices().ConvertToRigidBody(*this,
                physicsOrigin, physicsAxis, velocity);
            SetDoorState(user, DOOR_BROKEN);
            return true;
        }
    }

    bool closing = false;
    if (!wasClosed && state != DOOR_CLOSING) {
        minimumAngle = 0.0f;
        closing = true;
    } else if (minimumAngle == 0.0f) {
        minimumAngle = maximumAngle;
    } else if (maximumAngle != 0.0f) {
        bool chooseMaximum = !invertRotationDir;
        if (user != nullptr) {
            const idBounds userBounds =
                ParametricServices().GetEntityBounds(user);
            const idVec3 userCenter =
                ParametricServices().GetEntityOrigin(user)
                + (userBounds[0] + userBounds[1]) * 0.5f;
            const idVec3 heading = physicsAxis[heading_axis];
            const float side = (userCenter - physicsOrigin).Dot(
                heading.Cross(rotate_axis));
            chooseMaximum = side > 0.0f
                ? !invertRotationDir : invertRotationDir;
        }
        if (chooseMaximum) {
            minimumAngle = maximumAngle;
        }
    }

    if (closing && !CanClose(true)) {
        return false;
    }
    ParametricServices().PlaySound(*this,
        closing ? close_sound : start_sound);
    const int currentTime = ParametricServices().GetGameMilliseconds();
    ParametricServices().AddDoorMotionEvent(*this, user,
        physicsOrigin, 1000);

    if (slidingDoor) {
        const float currentDistance = (physicsOrigin - closedPos).Length();
        linearOffset = slideVec * currentDistance;
        targetLinearOffset = closing
            ? idVec3(0.0f, 0.0f, 0.0f) : slideVec * slideDist;
        const float distance = (targetLinearOffset - linearOffset).Length();
        const int duration = slideSpeed > 0.0f
            ? static_cast<int>(distance / slideSpeed * 1000.0f) : 0;
        linearEndTime = currentTime + duration;
        ParametricServices().BeginLinearInterpolation(*this,
            currentTime, duration, linearOffset, targetLinearOffset);
    } else {
        const float speed = kicked == 0.0f ? angularspeed
            : angularspeed * kicked * 4.0f;
        const int duration = speed > 0.0f
            ? static_cast<int>(std::fabs(minimumAngle - GetCurrentAngle())
                / speed * 1000.0f) : 0;
        targetAngle = minimumAngle;
        angularEndTime = currentTime + duration;
        ParametricServices().BeginAngularInterpolation(*this,
            currentTime, duration, GetCurrentAngle(), minimumAngle);
    }

    if (closing) {
        SetDoorState(user, DOOR_CLOSING);
        if (forceUnusableWhenOpened) {
            forcedUnusable = false;
        }
        autoCloseTime = 0;
    } else {
        SetDoorState(user, DOOR_OPENING);
        autoCloseTime = currentTime;
        if (forceUnusableWhenOpened) {
            forcedUnusable = true;
            autoCloseTime = 0;
        }
    }
    return true;
}

// Retail: 0x82C272E8 ?IsOpen@idDoor_Parametric@@UBA_NXZ
bool idDoor_Parametric::IsOpen() const {
    const int currentTime = ParametricServices().GetGameMilliseconds();
    if (forceUnopenedTime > 0) {
        return currentTime >= forceUnopenedTime;
    }
    if (slidingDoor) {
        if (linearEndTime > currentTime) {
            return false;
        }
        const idVec3 openedPosition = closedPos
            + TransformVector(spawnOrientation, slideVec * slideDist);
        return NearZero(physicsOrigin - openedPosition, 0.0001f);
    }
    return angularEndTime <= currentTime
        && std::fabs(GetCurrentAngle()) > 0.1f;
}

// Retail: 0x82C274E0 ?IsClosed@idDoor_Parametric@@UBA_NXZ
bool idDoor_Parametric::IsClosed() const {
    const int currentTime = ParametricServices().GetGameMilliseconds();
    if (slidingDoor) {
        return linearEndTime <= currentTime
            && NearZero(physicsOrigin - closedPos, 0.0001f);
    }
    return angularEndTime <= currentTime
        && std::fabs(GetCurrentAngle()) < 0.1f;
}

// Retail: 0x82C27608 ?Event_SetAngleAtTime@idDoor_Parametric@@AAA?AVeventVoid@@PAVidEntity@@MM@Z
void idDoor_Parametric::Event_SetAngleAtTime(idEntity* const source,
        const float duration, const float yaw) {
    const idVec3 direction = ParametricServices().GetEntityOrigin(source)
        - physicsOrigin;
    Event_LockGrinderSetAngleAtTime(source, direction, duration, yaw);
}

// Retail: 0x82C276E0 ??0idDoor_Parametric@@QAA@XZ
idDoor_Parametric::idDoor_Parametric()
    : idDoor_Base(), frameClip(nullptr), framePresentable(nullptr),
      doorAttachment(nullptr), frame(nullptr), door(nullptr),
      heading_axis(AXIS_X), rotation_axis(AXIS_Z), min_angle(-90.0f),
      max_angle(90.0f), min_kick_angle(-90.0f), max_kick_angle(90.0f),
      start_angle(0.0f), angularspeed(90.0f), invertRotationDir(false),
      slidingDoor(false), slideDir(SLIDE_UP), slideDist(128.0f),
      slideSpeed(90.0f), lockGrindRestAngle(80.0f),
      rotate_axis(0.0f, 0.0f, 0.0f),
      default_axis(0.0f, 0.0f, 0.0f), start_sound(nullptr),
      close_sound(nullptr), kick_open_sound(nullptr),
      door_center(0.0f, 0.0f, 0.0f),
      door_ai_offset(0.0f, 0.0f, 0.0f), close_time(8000),
      close_range(70), autoCloseTime(0), forceUnopenedTime(0),
      slideVec(0.0f, 0.0f, 0.0f), closedPos(0.0f, 0.0f, 0.0f),
      canCloseQuery(0), spawnPosition(0.0f, 0.0f, 0.0f),
      spawnOrientation(1.0f), physicsOrigin(0.0f, 0.0f, 0.0f),
      physicsAxis(1.0f), doorClipBounds(),
      linearOffset(0.0f, 0.0f, 0.0f),
      targetLinearOffset(0.0f, 0.0f, 0.0f), currentAngle(0.0f),
      targetAngle(0.0f), linearEndTime(0), angularEndTime(0),
      physicsContents(0), frameClipContents(0), thinkFlags(0),
      hidden(false), clipLinked(true), removed(false),
      usingRigidBody(false) {
    doorClipBounds[0].Zero();
    doorClipBounds[1].Zero();
}
