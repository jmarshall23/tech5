#include "game/entities/drone.h"

#include <algorithm>
#include <cmath>

namespace {
idDroneServices defaultDroneServices;
idDroneServices* droneServices = &defaultDroneServices;

constexpr int CHANNEL_ENGINE_FIRST = 0;
constexpr int CHANNEL_ENGINE_LIMIT = 16;
constexpr int CHANNEL_WEAPON_DEPLOY = 20;
constexpr int CHANNEL_WEAPON_STOW = 21;
constexpr int CHANNEL_SCAN_HIT = 22;
constexpr int CHANNEL_VOICE = 23;
constexpr int CHANNEL_COLLIDE = 24;

constexpr int FX_AFTERBURNER_START = 31;
constexpr int FX_AFTERBURNER_STOP = 32;
constexpr int FX_SCANNER_START = 33;
constexpr int FX_SCANNER_STOP = 34;

constexpr float MAX_SPLINE_AHEAD_DISTANCE = 1000.0f;
constexpr float MAX_POSITION_DISTANCE_FOR_SPLINE_ERROR = 4.0f;
constexpr float MAX_COLLISION_DISTANCE = 1000.0f;
constexpr float MAX_OBSTACLE_AVOIDANCE_SPEED = 15.0f;
constexpr float MIN_AVOID_AI_DISTANCE_BY_SPEED = 20.0f;
constexpr float MAX_AVOID_AI_DISTANCE_BY_SPEED = 80.0f;

const int moveStateByDroneState[idDrone::DS_NUM_DRONE_STATES] = {
    idDrone::DMS_STOPPED, idDrone::DMS_SEARCHING,
    idDrone::DMS_NORMAL, idDrone::DMS_STOPPED,
    idDrone::DMS_FAST, idDrone::DMS_STOPPED,
    idDrone::DMS_STOPPED, idDrone::DMS_NORMAL,
    idDrone::DMS_NORMAL
};

float Clamp(const float value, const float minimum, const float maximum) {
    return std::max(minimum, std::min(maximum, value));
}

float Lerp(const float from, const float to, const float fraction) {
    return from + (to - from) * fraction;
}

idVec3 Lerp(const idVec3& from, const idVec3& to,
        const float fraction) {
    return from * (1.0f - fraction) + to * fraction;
}

idVec3 Normalized(idVec3 vector, const idVec3& fallback) {
    if (vector.NormalizeFast() < 0.0001f) {
        return fallback;
    }
    return vector;
}

idQuat Multiply(const idQuat& left, const idQuat& right) {
    return idQuat(
        left.w * right.x + left.x * right.w
            + left.y * right.z - left.z * right.y,
        left.w * right.y - left.x * right.z
            + left.y * right.w + left.z * right.x,
        left.w * right.z + left.x * right.y
            - left.y * right.x + left.z * right.w,
        left.w * right.w - left.x * right.x
            - left.y * right.y - left.z * right.z);
}

idQuat AxisAngle(idVec3 axis, const float radians) {
    if (axis.NormalizeFast() < 0.0001f) {
        return idQuat(0.0f, 0.0f, 0.0f, 1.0f);
    }
    const float half = radians * 0.5f;
    const float sine = std::sin(half);
    return idQuat(axis.x * sine, axis.y * sine,
        axis.z * sine, std::cos(half));
}

idMat3 FacingToAxis(idVec3 forward, const float rollDegrees) {
    const idVec3 up(0.0f, 0.0f, 1.0f);
    forward = Normalized(forward, idVec3(1.0f, 0.0f, 0.0f));
    idVec3 side = Normalized(forward.Cross(up),
        idVec3(0.0f, -1.0f, 0.0f));
    idVec3 adjustedUp = Normalized(side.Cross(forward), up);
    constexpr float degreesToRadians = 0.01745329251994329577f;
    const float roll = rollDegrees * degreesToRadians;
    const idVec3 rolledSide = side * std::cos(roll)
        + adjustedUp * std::sin(roll);
    const idVec3 rolledUp = adjustedUp * std::cos(roll)
        - side * std::sin(roll);
    idMat3 result;
    result[0] = forward;
    result[1] = rolledSide;
    result[2] = rolledUp;
    return result;
}

bool SameEntity(const idEntity* left, const idEntity* right) {
    return left != nullptr && left == right;
}
}

int idDroneServices::GetGameMilliseconds() const { return 0; }
int idDroneServices::GetGameMillisecondsPerFrame() const { return 16; }
float idDroneServices::RandomFloat(float) { return 0.0f; }
float idDroneServices::RandomFloat(float minimum, float) { return minimum; }
int idDroneServices::RandomInt(int) { return 0; }
float idDroneServices::MoveStateScaler(const int row,
        const int moveState) const {
    static const float minimum[idDrone::DMS_NUM_DRONE_MOVE_STATES] = {
        0.0f, 1.0f, 3.0f, 6.0f, 12.0f
    };
    static const float maximum[idDrone::DMS_NUM_DRONE_MOVE_STATES] = {
        0.0f, 4.0f, 8.0f, 15.0f, 30.0f
    };
    const int state = std::max(0,
        std::min(idDrone::DMS_NUM_DRONE_MOVE_STATES - 1, moveState));
    return row == 0 ? minimum[state] : maximum[state];
}
float idDroneServices::MoveStateTransitionTime(int, int) const {
    return 0.25f;
}
float idDroneServices::MoveStateFacingAllowance(int, int) const {
    return 0.0f;
}
float idDroneServices::MoveStateSpeedAllowance(int, int) const {
    return 0.0f;
}
float idDroneServices::MoveStateRollAllowance(int, int) const {
    return 0.0f;
}
float idDroneServices::StateFacingAllowance(int, int) const { return 1.0f; }
float idDroneServices::StateSpeedAllowance(int, int) const { return 1.0f; }
float idDroneServices::StateRollAllowance(int, int) const { return 1.0f; }
idVec3 idDroneServices::GetOrigin(const idDrone& drone) const {
    return drone.physicsOrigin;
}
idMat3 idDroneServices::GetAxis(const idDrone& drone) const {
    return drone.physicsAxis;
}
idVec3 idDroneServices::GetEntityOrigin(const idEntity*) const {
    return idVec3(0.0f, 0.0f, 0.0f);
}
idBounds idDroneServices::GetEntityBounds(const idEntity*) const {
    idBounds result;
    result[0].Zero();
    result[1].Zero();
    return result;
}
idVec3 idDroneServices::GetEntityAimPoint(const idEntity* entity) const {
    return GetEntityOrigin(entity);
}
bool idDroneServices::IsValidEntity(const idEntity* entity) const {
    return entity != nullptr;
}
bool idDroneServices::IsPlayer(const idEntity*) const { return false; }
bool idDroneServices::IsAI(const idEntity*) const { return false; }
bool idDroneServices::PlayerSubstituteMatches(const idEntity*,
        const idEntity*) const { return false; }
void idDroneServices::StartSound(idDrone&, int, const idSoundShader*) {}
void idDroneServices::StopSound(idDrone&, int) {}
bool idDroneServices::IsPlayingSound(const idDrone&, int) const {
    return false;
}
void idDroneServices::SetSoundVolume(idDrone&, int, float) {}
void idDroneServices::SetSoundPitch(idDrone&, int, float) {}
void idDroneServices::UpdateSound(idDrone&) {}
void idDroneServices::StartConditionFX(idDrone&, int) {}
void idDroneServices::StopConditionFX(idDrone&, int) {}
void idDroneServices::UpdateBaseFX(idDrone&) {}
void idDroneServices::EmitGroundParticles(idDrone&,
        const idDeclParticle*, const idVec3&, const idVec3&, float) {}
bool idDroneServices::TraceDown(const idDrone&, const idVec3&,
        float, idDroneTraceResult&) { return false; }
void idDroneServices::UpdateInfluenceTrail(idDrone&,
        const idVec3&, float) {}
void idDroneServices::AddInfluenceExplosion(idDrone&,
        const idVec3&, float) {}
void idDroneServices::UpdateThrusterBeam(idDrone&, int,
        const idVec3&, const idVec3&, float, float) {}
void idDroneServices::UpdateFocusBeam(idDrone&, idEntity*,
        float, float, float, float) {}
void idDroneServices::EmitHealthParticles(idDrone&,
        const idDeclParticle*, const idVec3&, const idMat3&) {}
void idDroneServices::RegisterWorldStateUser(idDrone&) {}
void idDroneServices::UnregisterWorldStateUser(idDrone&) {}
void idDroneServices::RegisterDrone(idDrone&) {}
void idDroneServices::UnregisterDrone(idDrone&) {}
bool idDroneServices::UsesRelaxedChatter(const idDrone&) const {
    return false;
}
bool idDroneServices::HasFaction(const idDrone&) const { return true; }
void idDroneServices::ReportMissingFaction(const idDrone&) {}
int idDroneServices::AddAttachment(idDrone&, const char*, const char*) {
    return -1;
}
void idDroneServices::HideAttachments(idDrone&) {}
void idDroneServices::ShowAttachments(idDrone&) {}
void idDroneServices::ShowAttachment(idDrone&, int) {}
void idDroneServices::HideAttachment(idDrone&, int) {}
void idDroneServices::ConfigureSpawnPhysics(idDrone&, int,
        const idVec3&) {}
void idDroneServices::ConfigureRigidPhysics(idDrone&, int, int) {}
void idDroneServices::SetRigidPhysicsEnabled(idDrone&, bool) {}
void idDroneServices::BecomeActive(idDrone&, int) {}
void idDroneServices::HideEntity(idDrone&) {}
void idDroneServices::ShowEntity(idDrone&) {}
void idDroneServices::DormantBegin(idDrone&) {}
void idDroneServices::DormantEnd(idDrone&, int) {}
void idDroneServices::UpdateAnimation(idDrone&) {}
void idDroneServices::TouchTriggers(idDrone&) {}
void idDroneServices::BaseThink(idDrone&) {}
void idDroneServices::Present(idDrone&) {}
bool idDroneServices::BuildPatrolWaypoints(idDrone&,
        idSplineWaypoint*, idList<idSplineWaypoint*, 5>&) { return false; }
bool idDroneServices::BuildInitialPath(idDrone&,
        const idList<idSplineWaypoint*, 5>&, float, float&) { return false; }
bool idDroneServices::RebuildPath(idDrone&,
        const idList<idSplineWaypoint*, 5>&,
        const idList<float, 5>&, float&) { return false; }
idVec3 idDroneServices::GetWorldPosAlongPath(const idDrone& drone,
        float) const { return drone.currentPosition; }
void idDroneServices::StepPath(idDrone&, float) {}
void idDroneServices::GatherFocusCandidates(const idDrone&,
        idList<idDroneFocusCandidate, 5>&) const {}
void idDroneServices::GatherObstacleEntities(const idDrone&,
        idList<idEntity*, 5>&) const {}
void idDroneServices::GatherPlayers(const idDrone&,
        idList<idEntity*, 5>&) const {}
void idDroneServices::UpdateAIWorldState(idDrone&) {}
float idDroneServices::DamageAmount(const idDeclDamage*) const {
    return 0.0f;
}
bool idDroneServices::GetTraceImpactPoint(const trace_t*, idVec3&) const {
    return false;
}
void idDroneServices::ActivateEntity(idEntity*, idEntity*) {}
bool idDroneServices::HasExplosionFX(const idDrone&) const { return false; }
void idDroneServices::StartExplosion(idDrone&) {}
void idDroneServices::BeginSpinningDeath(idDrone&,
        const idVec3&, const idVec3&) {}
void idDroneServices::ApplyDeathVelocity(idDrone&, const idVec3&) {}
idDroneTraceResult idDroneServices::TraceMotion(const idDrone&,
        const idVec3&, const idVec3& end, const idMat3&,
        const idMat3&) {
    idDroneTraceResult result;
    result.endPosition = end;
    return result;
}
void idDroneServices::EmitWallImpact(idDrone&,
        const idDeclProjectileImpactEffect*, const idDroneTraceResult&) {}
void idDroneServices::QueueRemove(idDrone&) {}
void idDroneServices::ReleaseRuntime(idDrone&) {}
void idDroneServices::DeleteTemporaryClip(idClipModel*) {}

void idDrone::SetServices(idDroneServices* const services) {
    droneServices = services == nullptr ? &defaultDroneServices : services;
}

idDroneServices& idDrone::Services() { return *droneServices; }

// Retail: 0x82C27900 ?OnActivate@idDrone@@UAAXPAVidEntity@@@Z
void idDrone::OnActivate(idEntity*) {
    ++numActivates;
    if (activateCuriosityOverride >= 0.0f
            && activateCuriosityOverride < currentScanEntityCuriosity) {
        currentScanEntityCuriosity = activateCuriosityOverride;
    }
}

// Retail: 0x82C27938 ?DeployWeaponNow@idDrone@@QAAXH@Z
void idDrone::DeployWeaponNow(const int gunId) {
    if (gunId < 0 || gunId >= NUM_ATTACHMENTS) return;
    if (weaponArmSpeed[gunId] <= 0.0f
            && (weaponArmSpeed[gunId] < 0.0f
                || weaponStatus[gunId] <= 0.0f)
            && deployWeaponSound != nullptr) {
        Services().StopSound(*this, CHANNEL_WEAPON_STOW);
        Services().StartSound(*this, CHANNEL_WEAPON_DEPLOY,
            deployWeaponSound);
        Services().SetSoundVolume(*this, CHANNEL_WEAPON_DEPLOY, 0.0f);
    }
    weaponArmTime[gunId] = 0;
    weaponArmSpeed[gunId] = weaponStatus[gunId] < 1.0f ? 0.02f : 0.0f;
}

// Retail: 0x82C27A10 ?StowWeaponNow@idDrone@@QAAXH@Z
void idDrone::StowWeaponNow(const int gunId) {
    if (gunId < 0 || gunId >= NUM_ATTACHMENTS) return;
    if (weaponArmSpeed[gunId] >= 0.0f
            && (weaponArmSpeed[gunId] > 0.0f
                || weaponStatus[gunId] >= 1.0f)
            && stowWeaponSound != nullptr) {
        Services().StopSound(*this, CHANNEL_WEAPON_DEPLOY);
        Services().StartSound(*this, CHANNEL_WEAPON_STOW,
            stowWeaponSound);
        Services().SetSoundVolume(*this, CHANNEL_WEAPON_STOW, 0.0f);
    }
    weaponDisarmTime[gunId] = 0;
    weaponArmSpeed[gunId] = weaponStatus[gunId] > 0.0f ? -0.01f : 0.0f;
}

// Retail: 0x82C27C10 ?UpdateMoveStateMemberships@idDrone@@QAAXXZ
void idDrone::UpdateMoveStateMemberships() {
    float remaining = 1.0f;
    for (int index = 1; index < 4; ++index) {
        if (moveStateMemberships[index] == 0.0f) continue;
        moveStateMemberships[index] += moveStateMembershipDeltas[index];
        if (moveStateMemberships[index] <= 0.0f) {
            moveStateMemberships[index] = 0.0f;
            moveStateMembershipDeltas[index] = 0.0f;
        } else {
            remaining -= moveStateMemberships[index];
        }
    }
    moveStateMemberships[0] = Clamp(remaining, 0.0f, 1.0f);
}

// Retail: 0x82C27C90 ?GetDesiredSpeedForMoving@idDrone@@QAAMXZ
float idDrone::GetDesiredSpeedForMoving() {
    const float turnDot = dot0to1to2 + dot1to2to3;
    float result = turnDot < 1.8f
        ? desiredSpeed - (1.8f - turnDot) * 17.5f
        : desiredSpeed + (turnDot - 1.8f) * 0.15000001f;
    result -= toAhead[0].z * 0.050000001f;
    float minimum = 0.0f;
    float maximum = 0.0f;
    for (int index = 0; index < 4; ++index) {
        minimum += Services().MoveStateScaler(0, moveStates[index])
            * moveStateMemberships[index];
        maximum += Services().MoveStateScaler(3, moveStates[index])
            * moveStateMemberships[index];
    }
    return Clamp(result, minimum, maximum);
}

// Retail: 0x82C27D88 ?GetDesiredRollForMoving@idDrone@@QAAMXZ
float idDrone::GetDesiredRollForMoving() {
    idVec3 right = toAhead[0].Cross(idVec3(0.0f, 0.0f, 1.0f));
    if (right.NormalizeFast() < 0.1f) return currentRoll;
    const float vertical = 1.0f - std::fabs(toAhead[0].z);
    float result = right.Dot(toAhead[2]) * 300.0f
        * vertical * vertical * vertical * vertical;
    const float maximum = currentSpeed >= 6.0f
        ? 70.0f : std::max(0.0f, currentSpeed * 11.666667f);
    return Clamp(result, -maximum, maximum);
}

// Retail: 0x82C27EF0 ?GetModelTransform@idDrone@@UBAXAAVidVec3@@AAVidMat3@@@Z
void idDrone::GetModelTransform(idVec3& origin, idMat3& axis) const {
    origin = Services().GetOrigin(*this);
    axis = currentAxis;
}

// Retail: 0x82C27F88 ?DeployAndStowWeapon@idDrone@@QAAXHHH@Z
void idDrone::DeployAndStowWeapon(const int gunId, const int armDelay,
        const int disarmDelay) {
    if (gunId < 0 || gunId >= NUM_ATTACHMENTS) return;
    const int currentTime = Services().GetGameMilliseconds();
    if (armDelay > 0) {
        if (weaponStatus[gunId] == 0.0f
                && weaponArmSpeed[gunId] == 0.0f
                && weaponArmTime[gunId] == 0) {
            weaponArmTime[gunId] = currentTime + armDelay;
        }
    } else {
        DeployWeaponNow(gunId);
    }
    if (disarmDelay > 0) {
        weaponDisarmTime[gunId] = currentTime + disarmDelay;
    }
}

// Retail: 0x82C28058 ?UpdateEngineSound@idDrone@@QAAXW4soundChannel_t@@AAUblendedSounds_t@1@MMMMM@Z
void idDrone::UpdateEngineSound(const int channel,
        blendedSounds_t& sound, float, const float closure,
        const float thrust, const float minThrust,
        const float maxThrust) {
    const float thrustFraction = maxThrust > minThrust
        ? Clamp((thrust - minThrust) / (maxThrust - minThrust),
            0.0f, 1.0f) : (thrust > minThrust ? 1.0f : 0.0f);
    const float volume = Lerp(sound.minThrustVolume,
        sound.maxThrustVolume, thrustFraction);
    const float speedFraction = Clamp((currentSpeed - 4.0f) * 0.125f,
        0.0f, 1.0f);
    const float speedPitch = Lerp(sound.minSpeedPitch,
        sound.maxSpeedPitch, speedFraction);
    const float thrustPitch = Lerp(sound.minThrustPitch,
        sound.maxThrustPitch, thrustFraction);
    const float closingPitch = Lerp(minPitchByClosing,
        maxPitchByClosing, Clamp((closure + 1.0f) * 0.5f, 0.0f, 1.0f));
    Services().SetSoundVolume(*this, channel, volume);
    Services().SetSoundPitch(*this, channel,
        closingPitch + thrustPitch + speedPitch);
}

// Retail: 0x82C281E0 ?SetEngineSoundVolume@idDrone@@QAAXW4soundChannel_t@@AAUblendedSounds_t@1@MMM@Z
void idDrone::SetEngineSoundVolume(const int channel,
        blendedSounds_t& sound, const float thrust,
        const float minThrust, const float maxThrust) {
    if (!Services().IsPlayingSound(*this, channel)) return;
    const float fraction = maxThrust > minThrust
        ? Clamp((thrust - minThrust) / (maxThrust - minThrust),
            0.0f, 1.0f) : (thrust > minThrust ? 1.0f : 0.0f);
    const float volume = Lerp(sound.minThrustVolume,
        sound.maxThrustVolume, fraction);
    Services().SetSoundVolume(*this, channel,
        volume - engineSoundsFade * 100.0f);
}

// Retail: 0x82C28288 ?ChangeMoveState@idDrone@@QAAXV?$idEnum@W4droneMoveState_t@idDrone@@$04@@M@Z
void idDrone::ChangeMoveState(int newState, float time) {
    newState = std::max(0, std::min(static_cast<int>(DMS_FAST), newState));
    const int oldState = std::max(0,
        std::min(static_cast<int>(DMS_FAST), moveStates[0]));
    if (oldState == newState) return;
    time = Clamp(time, 0.01f, 1.0f);
    const int frameTime = std::max(1, Services().GetGameMillisecondsPerFrame());
    float delta = -time / static_cast<float>(frameTime);
    if (delta >= 0.0f || delta < -0.5f) {
        const float fallback = Services().MoveStateTransitionTime(
            oldState, newState);
        delta = -fallback / static_cast<float>(frameTime);
    }
    int replacement = 1;
    for (int index = 2; index < 4; ++index) {
        if (moveStateMemberships[index]
                < moveStateMemberships[replacement]) {
            replacement = index;
        }
    }
    moveStates[replacement] = oldState;
    moveStateMemberships[replacement] = moveStateMemberships[0];
    moveStateMembershipDeltas[replacement] = delta;
    moveStates[0] = newState;
    moveStateMemberships[0] = Clamp(1.0f - moveStateMemberships[1]
        - moveStateMemberships[2] - moveStateMemberships[3], 0.0f, 1.0f);
    allowFacingChanges = Clamp(allowFacingChanges
        - Services().MoveStateFacingAllowance(oldState, newState),
        0.0f, 1.0f);
    allowSpeedChanges = Clamp(allowSpeedChanges
        - Services().MoveStateSpeedAllowance(oldState, newState),
        0.0f, 1.0f);
    allowRollChanges = Clamp(allowRollChanges
        - Services().MoveStateRollAllowance(oldState, newState),
        0.0f, 1.0f);
}

// Retail: 0x82C28538 ?NearestSplinePositionFastGuess@idDrone@@QBAMAAVidVec3@@0@Z
float idDrone::NearestSplinePositionFastGuess(const idVec3& goalPosition,
        idVec3& returnPosition) const {
    returnPosition = currentPosition;
    if (toAhead[0].Dot(goalPosition - currentPosition) <= 0.0f) {
        return MAX_SPLINE_AHEAD_DISTANCE;
    }
    int segment = 0;
    for (; segment < 4; ++segment) {
        idVec3 tangent = segment == 0 ? toAhead[0]
            : aheadToAhead[segment - 1];
        if (segment < 3) tangent = Normalized(tangent
            + aheadToAhead[segment], tangent);
        if (tangent.Dot(goalPosition - ahead[segment]) <= 0.0f) break;
    }
    if (segment >= 4) {
        returnPosition = ahead[3];
        return aheadDistance[3] + (goalPosition - returnPosition).Length();
    }
    float lowDistance = segment == 0 ? 0.0f : aheadDistance[segment - 1];
    float highDistance = aheadDistance[segment];
    idVec3 lowPosition = segment == 0 ? currentPosition : ahead[segment - 1];
    idVec3 highPosition = ahead[segment];
    while (highDistance - lowDistance
            > MAX_POSITION_DISTANCE_FOR_SPLINE_ERROR) {
        const float middleDistance = (lowDistance + highDistance) * 0.5f;
        const idVec3 middle = Services().GetWorldPosAlongPath(
            *this, pathDistance + middleDistance);
        const idVec3 segmentDirection = highPosition - lowPosition;
        if ((goalPosition - middle).Dot(segmentDirection) >= 0.0f) {
            lowDistance = middleDistance;
            lowPosition = middle;
        } else {
            highDistance = middleDistance;
            highPosition = middle;
        }
    }
    const idVec3 lowGoal = Normalized(goalPosition - lowPosition,
        idVec3(1.0f, 0.0f, 0.0f));
    const idVec3 highGoal = Normalized(goalPosition - highPosition,
        idVec3(1.0f, 0.0f, 0.0f));
    const idVec3 pathDirection = Normalized(highPosition - lowPosition,
        idVec3(0.0f, 0.0f, 1.0f));
    float lowWeight = std::fabs(lowGoal.Dot(pathDirection));
    float highWeight = std::fabs(highGoal.Dot(pathDirection));
    if (lowWeight + highWeight < 0.0001f) {
        lowWeight = highWeight = 0.0001f;
    }
    const float inverse = 1.0f / (lowWeight + highWeight);
    returnPosition = lowPosition * (highWeight * inverse)
        + highPosition * (lowWeight * inverse);
    return lowDistance * (highWeight * inverse)
        + highDistance * (lowWeight * inverse);
}

// Retail: 0x82C28ED8 ?GetDesiredFacingForMoving@idDrone@@QAA?AVidVec3@@XZ
idVec3 idDrone::GetDesiredFacingForMoving() {
    idVec3 facing = toAhead[0] * 0.75f + toAhead[1] * 0.25f;
    const float vertical = facing.z;
    facing.z *= 0.5f;
    facing = Normalized(facing, currentFacing);
    float climbLook = 0.0f;
    for (int index = 0; index < 3; ++index) {
        const float distance = std::max(1.0f,
            (ahead[index + 1] - ahead[index]).Length());
        const float rise = ahead[index + 1].z - ahead[index].z;
        if (rise > 0.0f && aheadDistance[index] < aheadDistance[index + 1]) {
            climbLook += rise / distance;
        }
    }
    if (ahead[1].z > currentPosition.z
            && aheadDistance[0] < aheadDistance[1]) {
        climbLook += (ahead[1].z - currentPosition.z)
            / std::max(1.0f, (ahead[1] - currentPosition).Length());
    }
    pitchToAlterSpeed = pitchToAlterSpeed * 0.975f
        + Clamp(vertical < 0.0f ? -vertical : 0.0f,
            -0.666f, 0.666f) * 0.025f;
    lookUpToGoUpAount = climbLook < lookUpToGoUpAount
        ? lookUpToGoUpAount * 0.99f + climbLook * 0.01f
        : lookUpToGoUpAount * 0.965f + climbLook * 0.035f;
    facing.z = Clamp(facing.z + pitchToAlterSpeed
        + lookUpToGoUpAount * 5.0f, -1.0f, 1.0f);
    return Normalized(facing, currentFacing);
}

// Retail: 0x82C29600 ?UpdateFX@idDrone@@UAAXXZ
void idDrone::UpdateFX() {
    Services().UpdateBaseFX(*this);
    if (health <= 0.0f) return;
    const int currentTime = Services().GetGameMilliseconds();
    if (groundParticlesFromFan != nullptr
            && currentTime > nextGroundFXTime) {
        nextGroundFXTime = currentTime
            + static_cast<int>(secBetweenAdd * 1000.0f);
        for (int fan = 0; fan < 2; ++fan) {
            const float side = fan == 0 ? -12.0f : 12.0f;
            const idVec3 fanOrigin = physicsOrigin + currentAxis[1] * side;
            idDroneTraceResult trace;
            if (!Services().TraceDown(*this, fanOrigin, 5000.0f, trace)) {
                continue;
            }
            const float altitude = (fanOrigin - trace.endPosition).Length();
            const float range = maxAltitude * particlesMultiplier;
            if (altitude < range
                    && Services().RandomFloat(range * particlesMultiplier)
                        > altitude) {
                const int count = particlesMultiplier > 1.0f
                    ? static_cast<int>(Services().RandomFloat(2.0f,
                        particlesMultiplier * 2.0f + 0.5f)) : 2;
                for (int particle = 0; particle < count; ++particle) {
                    const float extra = addedParticleMovement > 0.5f
                        ? Services().RandomFloat(addedParticleMovement * 0.5f,
                            addedParticleMovement)
                        : addedParticleMovement < -0.5f
                            ? Services().RandomFloat(addedParticleMovement,
                                addedParticleMovement * 0.5f) : 0.0f;
                    const idVec3 velocity(lastMovement.x
                        * (currentSpeed * 3.0f + extra)
                        + Services().RandomFloat(-25.0f, 25.0f),
                        lastMovement.y * (currentSpeed * 3.0f + extra)
                        + Services().RandomFloat(-25.0f, 25.0f), 0.0f);
                    Services().EmitGroundParticles(*this,
                        groundParticlesFromFan, trace.endPosition, velocity,
                        Services().RandomFloat(1.0f));
                }
            }
        }
    }
    idDroneTraceResult groundTrace;
    if (Services().TraceDown(*this, physicsOrigin, 5000.0f, groundTrace)) {
        constexpr float lowAngle = 5.0f;
        constexpr float highAngle = 20.0f;
        const float wave = std::sin(currentTime * 0.001f) * 0.5f + 0.5f;
        Services().UpdateInfluenceTrail(*this, groundTrace.endPosition,
            Lerp(lowAngle, highAngle, wave));
    }
    Services().AddInfluenceExplosion(*this, physicsOrigin,
        influenceOuterRadius);
    if (particlesMultiplier != 1.0f) {
        particlesMultiplier += particlesMultiplier > 1.0f ? -0.25f : 0.25f;
        if ((particlesMultiplier > 1.0f) != (particlesMultiplier -
                (particlesMultiplier > 1.0f ? -0.25f : 0.25f) > 1.0f)) {
            particlesMultiplier = 1.0f;
        }
    }
    if (addedParticleMovement != 0.0f) {
        const float old = addedParticleMovement;
        addedParticleMovement += old > 0.0f ? -1.0f : 1.0f;
        if ((old > 0.0f && addedParticleMovement < 0.0f)
                || (old < 0.0f && addedParticleMovement > 0.0f)) {
            addedParticleMovement = 0.0f;
        }
    }
}

// Retail: 0x82C29F90 ?Bump@idDrone@@QAA?AVidVec3@@V2@0MMM@Z
idVec3 idDrone::Bump(const idVec3& contactPosition,
        const idVec3& forceDirection, const float translationalForce,
        const float rotationalForce, const float reduceZScaler) {
    idVec3 direction = forceDirection;
    direction.z *= reduceZScaler;
    direction = Normalized(direction, currentFacing);
    idVec3 arm = contactPosition - (currentPosition + additivePosition);
    arm.z *= reduceZScaler;
    arm = Normalized(arm, currentAxis[1]);
    idVec3 rotationAxis = arm.Cross(direction);
    const float rotationMagnitude = rotationAxis.NormalizeFast();
    const float alignment = Clamp((arm.Dot(direction) + 1.0f) * 0.5f,
        0.0f, 1.0f);
    const float rotationalBlend = rotationMagnitude >= 0.2f
        ? rotationMagnitude + (rotationMagnitude - 0.2f) * 0.75f
        : rotationMagnitude + (0.2f - rotationMagnitude) * 0.33329999f;
    const idQuat rotation = AxisAngle(rotationAxis,
        rotationalBlend * rotationalForce * 0.055f);
    additiveAngularMomentum = Multiply(rotation,
        additiveAngularMomentum);
    additiveAngularMomentum.Normalize();
    if (alignment > 0.1f) {
        outOfControl = Clamp(outOfControl
            + (alignment - 0.1f) * rotationalBlend * 0.35f,
            0.0f, 1.0f);
    }
    const idVec3 impulse = direction
        * ((1.0f - rotationalBlend) * translationalForce * 6.0f);
    additivePosition = additivePosition + impulse;
    additiveMomentum = additiveMomentum + impulse;
    recentForceApplied = recentForceApplied + impulse;
    if (alignment >= 0.2f) {
        const float speedScale = alignment < 1.0f
            ? 1.0f - (alignment - 0.2f) * 0.3125f : 0.75f;
        currentSpeed = (currentSpeed + 3.0f) * speedScale - 3.0f;
    } else {
        float maximum = 0.0f;
        for (int index = 0; index < 4; ++index) {
            maximum += Services().MoveStateScaler(3, moveStates[index])
                * moveStateMemberships[index];
        }
        if (currentSpeed < maximum * 0.75f) {
            currentSpeed += (0.2f - alignment) * 2.5f;
        }
    }
    allowRollChanges = std::max(-0.1f, allowRollChanges - 0.25f);
    return impulse;
}

// Retail: 0x82C2A488 ?KillDrone@idDrone@@QAAXXZ
void idDrone::KillDrone() {
    health = 0.0f;
    if (Services().IsValidEntity(deathTrigger)) {
        Services().ActivateEntity(deathTrigger,
            reinterpret_cast<idEntity*>(this));
    }
    if (deathVarietyDesired >= DD_RANDOM_DRONE_DEATH) {
        deathVarietyDesired = static_cast<droneDeath_t>(
            Services().RandomInt(2));
    }
    if (deathVarietyDesired == DD_EXPLOSION
            && !Services().HasExplosionFX(*this)) {
        deathVarietyDesired = DD_SPINNING_OUT_OF_CONTROL;
    }
    const int currentTime = Services().GetGameMilliseconds();
    if (deathVarietyDesired == DD_SPINNING_OUT_OF_CONTROL) {
        nextEngineSmokeTime = currentTime;
        engineSmokeAmount = Services().RandomFloat(0.8f, 1.0f);
        const idVec3 linearVelocity = (physicsOrigin - previousOrigin) * 25.0f;
        const idVec3 angularVelocity = (physicsAxis[0]
            - previousAxis[0]) * -8.0f;
        Services().BeginSpinningDeath(*this,
            linearVelocity, angularVelocity);
        rigidPhysicsEnabled = true;
        deathThrust.Set(0.0f, 0.0f, 1.0f);
        deathDoneTime = currentTime + static_cast<int>(
            Services().RandomFloat(minDeathThrustDuration,
                maxDeathThrustDuration) * 1000.0f);
        weaponArmTime[0] = 0;
        weaponDisarmTime[0] = currentTime + 500;
        Services().BecomeActive(*this, 2);
    } else {
        Services().StartExplosion(*this);
        if (explosionSound != nullptr) {
            Services().StopSound(*this, CHANNEL_COLLIDE);
            Services().StartSound(*this, CHANNEL_COLLIDE, explosionSound);
            Services().SetSoundVolume(*this, CHANNEL_COLLIDE, 0.0f);
        }
        deathDoneTime = currentTime
            + static_cast<int>(delayToHideDrone * 1000.0f);
        if (rigidPhysicsEnabled) {
            rigidPhysicsEnabled = false;
            Services().SetRigidPhysicsEnabled(*this, false);
        }
    }
}

// Retail: 0x82C2A9F8 ?Hide@idDrone@@UAAXXZ
void idDrone::Hide() {
    Services().HideAttachments(*this);
    if (rigidPhysicsEnabled) {
        rigidPhysicsEnabled = false;
        Services().SetRigidPhysicsEnabled(*this, false);
    }
    hidden = true;
    Services().HideEntity(*this);
    if (!Services().UsesRelaxedChatter(*this)) {
        Services().UnregisterWorldStateUser(*this);
        registeredWorldState = false;
    }
}

// Retail: 0x82C2AAC0 ?DormantBegin@idDrone@@UAAXXZ
void idDrone::DormantBegin() {
    Services().DormantBegin(*this);
    Services().UnregisterWorldStateUser(*this);
    registeredWorldState = false;
}

// Retail: 0x82C2AB78 ?GetDesiredFacingForScanning@idDrone@@QAA?AVidVec3@@XZ
idVec3 idDrone::GetDesiredFacingForScanning() {
    if (!Services().IsValidEntity(currentScanEntity)) {
        return GetDesiredFacingForMoving();
    }
    pitchToAlterSpeed *= 0.975f;
    lookUpToGoUpAount *= 0.965f;
    idVec3 target = Services().GetEntityAimPoint(currentScanEntity);
    idVec3 facing = Normalized(target - physicsOrigin, currentFacing);
    focusEntityScanBob += focusEntityScanBobDelta;
    if (focusEntityScanBob < -0.15f) {
        focusEntityScanBob = -0.15f;
        focusEntityScanBobDelta = Services().RandomFloat(0.006f, 0.01f);
    } else if (focusEntityScanBob > 0.15f) {
        focusEntityScanBob = 0.15f;
        focusEntityScanBobDelta = Services().RandomFloat(-0.01f, -0.006f);
    }
    facing.z = Clamp(facing.z + focusEntityScanBob, -1.0f, 1.0f);
    return Normalized(facing, currentFacing);
}

// Retail: 0x82C2AEA0 ?FindAutoFocusEntity@idDrone@@QAAMAAPBVidEntity@@@Z
float idDrone::FindAutoFocusEntity(idEntity*& bestEntity) {
    bestEntity = nullptr;
    float bestScore = -1.0f;
    idList<idDroneFocusCandidate, 5> candidates;
    Services().GatherFocusCandidates(*this, candidates);
    const int currentTime = Services().GetGameMilliseconds();
    for (int index = 0; index < candidates.Num(); ++index) {
        const idDroneFocusCandidate& candidate = candidates[index];
        if (candidate.entity == nullptr || candidate.entity
                == reinterpret_cast<idEntity*>(this) || !candidate.visible
                || !candidate.recentlyConfirmed
                || (!candidate.isPlayer && !candidate.isAI)) {
            continue;
        }
        bool configuredBehavior = false;
        for (int behavior = 0; behavior < behaviorPoints.Num(); ++behavior) {
            if (SameEntity(behaviorPoints[behavior].entityToScan,
                    candidate.entity)
                    || Services().PlayerSubstituteMatches(
                        behaviorPoints[behavior].entityToScan,
                        candidate.entity)) {
                configuredBehavior = true;
                break;
            }
        }
        if (configuredBehavior) continue;
        idVec3 direction = candidate.aimPoint - physicsOrigin;
        const float distance = direction.NormalizeFast();
        const float forwardDot = currentAxis[0].Dot(direction);
        if (forwardDot < 0.75f || direction.z < -0.5f
                || direction.z > 0.5f) continue;
        const float distanceWeight = std::max(0.0f,
            1.0f - distance / std::max(1.0f,
                optimalFocusEntityDistance));
        const float forwardWeight = Clamp(forwardDot, 0.0f, 1.0f)
            * 0.9f + 0.1f;
        float recencyWeight = 1.0f;
        for (int previous = 0; previous < previousFocusEntities.Num();
                ++previous) {
            if (!SameEntity(previousFocusEntities[previous],
                    candidate.entity)) continue;
            const int elapsed = currentTime - previousFocusEntityTimes[previous];
            recencyWeight = elapsed < 10000 ? 0.01f
                : elapsed < 30000 ? 0.1f
                    + (elapsed - 10000) * 0.000045f : 1.0f;
            break;
        }
        const float playerWeight = candidate.isPlayer ? 1.75f : 1.0f;
        const float score = recencyWeight * candidate.mutualFocusWeight
            * candidate.visibilityWeight * candidate.attitudeWeight
            * playerWeight * forwardWeight * distanceWeight * 5.0f;
        if (score > bestScore) {
            bestScore = score;
            bestEntity = candidate.entity;
        }
    }
    return bestScore;
}

// Retail: 0x82C2B490 ?TurnOnScanner@idDrone@@QAAXXZ
void idDrone::TurnOnScanner() {
    if (isScannerOn || !Services().IsValidEntity(currentScanEntity)) return;
    const float deployChance = Services().IsPlayer(currentScanEntity)
        ? 0.333f : 0.2f;
    if (Services().RandomFloat(1.0f) < deployChance) {
        DeployAndStowWeapon(0, 200, 3000);
    }
    const float maximum = Services().IsPlayer(currentScanEntity)
        ? optimalFocusPlayerCuriosity : optimalFocusAICuriosity;
    currentScanEntityCuriosity = maximum * 0.5f
        + Services().RandomFloat(maximum);
    if (scannerSound != nullptr) {
        Services().StartSound(*this, CHANNEL_VOICE, scannerSound);
        Services().SetSoundVolume(*this, CHANNEL_VOICE, -10.0f);
    }
    Services().StartConditionFX(*this, FX_SCANNER_START);
    isScannerOn = true;
}

// Retail: 0x82C2B628 ?TurnOffScanner@idDrone@@QAAXXZ
void idDrone::TurnOffScanner() {
    if (!isScannerOn) return;
    if (stopScannerSound != nullptr) {
        Services().StartSound(*this, CHANNEL_VOICE, stopScannerSound);
        Services().SetSoundVolume(*this, CHANNEL_VOICE, -10.0f);
    } else {
        Services().StopSound(*this, CHANNEL_VOICE);
    }
    Services().StopConditionFX(*this, FX_SCANNER_START);
    Services().StartConditionFX(*this, FX_SCANNER_STOP);
    currentScanEntity = nullptr;
    isScannerOn = false;
}

// Retail: 0x82C2B740 ??0idDrone@@QAA@XZ
idDrone::idDrone()
    : slowForPlayer(true), initialWaypoint(nullptr), initialPath(nullptr),
      initialState(DS_MOVING), fleeNearEnemyFlag(true),
      startingHealth(333.0f), declWallSpark(nullptr),
      declBreakable(nullptr), currentState(DS_MOVING),
      nextState(DS_MOVING), changeStateTime(0),
      lastNonScanState(DS_MOVING), currentPathType(DPT_PATROL),
      currentPathTypeParm(0), patrolWaypointOn(0), patrolDirection(1),
      patrolWaypoints(), searchDirection(1.0f), searchNextUpdateTime(0),
      goals(), goalSearchDirections(), firstThinkFlag(true),
      health(333.0f), currentPosition(0.0f, 0.0f, 0.0f),
      previousOrigin(0.0f, 0.0f, 0.0f),
      desiredFacing(1.0f, 0.0f, 0.0f),
      currentFacing(1.0f, 0.0f, 0.0f), allowFacingChanges(1.0f),
      currentAxis(1.0f), previousAxis(1.0f), desiredSpeed(0.0f),
      desiredSpeedMultiplier(1.0f), overrideMaxDesiredSpeed(0.0f),
      resetSpeedOverrideCounter(0), currentSpeed(0.0f),
      allowSpeedChanges(1.0f), lastFrameOverMove(0.0f),
      desiredRoll(0.0f), currentRoll(0.0f), allowRollChanges(1.0f),
      pitchToAlterSpeed(0.0f), lookUpToGoUpAount(0.0f),
      lowerNoseWhenAccelerating(1.0f), emergencyBrakeScaler(1.0f),
      obstacleAvoidanceMaxSpeed(15.0f),
      goalAvoidanceOffset(0.0f, 0.0f, 0.0f),
      averageAvoidanceOffset(0.0f, 0.0f, 0.0f), numActivates(0),
      pathDistance(0.0f), splinePathLength(0.0f),
      deltaToFinalGoal(0.0f), distanceToFinalGoal(0.0f),
      immediateGoalPosition(0.0f, 0.0f, 0.0f),
      finalGoalPosition(0.0f, 0.0f, 0.0f),
      splineDistanceToFinalGoal(0.0f), rightDistanceToFinalGoal(0.0f),
      nearestPlayerDistance(3000.0f), outOfControl(0.0f),
      additivePosition(0.0f, 0.0f, 0.0f),
      additiveMomentum(0.0f, 0.0f, 0.0f),
      additiveFacing(0.0f, 0.0f, 0.0f, 1.0f),
      additiveAngularMomentum(0.0f, 0.0f, 0.0f, 1.0f),
      groundParticlesFromFan(nullptr), secBetweenAdd(0.02f),
      maxAltitude(150.0f), particlesMultiplier(1.0f),
      addedParticleMovement(0.0f), influenceOuterRadius(64.0f),
      controllerShakeHighMag(500.0f), controllerShakeLowMag(300.0f),
      nextGroundFXTime(0), smallEngineSounds(), largeEngineSounds(),
      afterburnerSounds(), scannerSound(nullptr), stopScannerSound(nullptr),
      deployWeaponSound(nullptr), stowWeaponSound(nullptr),
      scanPlayerSound(nullptr), explosionSound(nullptr),
      minPitchByClosing(-3.0f), maxPitchByClosing(3.0f),
      largeEngineThrustLevel(0.0f), smallEngineThrustLevel(0.0f),
      afterburnerThrustLevel(0.0f), engineSoundsFade(0.0f),
      declTrackingParms(nullptr), visibleSightTime(0.5f),
      visibleSightRadius(5000.0f), disengageEnemyDistance(4000.0f),
      optimalFocusEntityDistance(1000.0f),
      optimalFocusAICuriosity(1.5f), optimalFocusPlayerCuriosity(2.0f),
      focusEntityMaterial(nullptr), focusEntityWidth(1.0f),
      focusEntityLength(1.0f), currentEnemy(nullptr), isScannerOn(false),
      currentScanEntity(nullptr), currentScanEntityCuriosity(0.0f),
      currentScanEntityEffectOn(0.0f), previousFocusEntities(),
      previousFocusEntityTimes(), focusEntityScanBob(0.0f),
      focusEntityScanBobDelta(0.0f), nearestForwardAi(nullptr),
      nearestForwardAiTime(0), thrusterMaterial(nullptr),
      thrusterWidth(5.0f), thrusterLength(25.0f),
      wasAfterburnerFxStarted(false),
      lastMovement(0.0f, 0.0f, 0.0f),
      previousNonThrustMovement(0.0f, 0.0f, 0.0f),
      thrusterPerceivedFriction(2.0f), afterburnerAmount(0.0f),
      nextAfterburnerSmokeTime(0), bobGoal(0.0f, 0.0f, 0.0f),
      engineSmokeAmount(0.0f), nextEngineSmokeTime(0),
      nextSputterTime(0), touching(), behaviorPoints(),
      nextBehaviorPointToTest(0), damageBehaviors(),
      activateCuriosityOverride(-1.0f), currentBehaviorPoint(-1),
      dot0to1to2(0.0f), dot1to2to3(0.0f),
      rigidPhysicsEnabled(false), wasRemoveEventPosted(false),
      deathVarietyDesired(DD_EXPLOSION), deathDoneTime(0),
      deathTrigger(nullptr), delayToHideDrone(0.2f),
      minDeathThrustDuration(0.75f), maxDeathThrustDuration(2.5f),
      recentForceApplied(0.0f, 0.0f, 0.0f),
      deathThrust(0.0f, 0.0f, 0.0f),
      physicsOrigin(0.0f, 0.0f, 0.0f), physicsAxis(1.0f),
      clipModelSize(64.0f, 64.0f, 32.0f), hidden(false),
      registeredWorldState(false), registeredDrone(false) {
    for (int index = 0; index < 3; ++index) {
        smokeParticle[index] = nullptr;
        sputterParticle[index] = nullptr;
        deathParticle[index] = nullptr;
    }
    sparkParticle[0] = sparkParticle[1] = nullptr;
    for (int index = 0; index < 4; ++index) {
        moveStates[index] = DMS_NORMAL;
        moveStateMemberships[index] = 0.0f;
        moveStateMembershipDeltas[index] = 0.0f;
        attachmentHandles[index] = -1;
        weaponStatus[index] = 0.0f;
        weaponArmSpeed[index] = 0.0f;
        weaponArmTime[index] = 0;
        weaponDisarmTime[index] = 0;
        splineAheadPositions[index].Zero();
        ahead[index].Zero();
        aheadDistance[index] = 0.0f;
        toAhead[index].Zero();
        aheadToAhead[index].Zero();
    }
    moveStates[0] = moveStates[1] = moveStates[2]
        = moveStates[3] = DMS_STOPPED;
    for (int index = 0; index < 10; ++index) {
        lastThrusterPower[index] = 0.0f;
        thrusterShown[index] = 0.0f;
        thrusterFx[index] = 0;
    }
}

// Retail: 0x82C2C340 ??1idDrone@@UAA@XZ
idDrone::~idDrone() {
    if (registeredWorldState) Services().UnregisterWorldStateUser(*this);
    if (registeredDrone) Services().UnregisterDrone(*this);
    Services().ReleaseRuntime(*this);
    damageBehaviors.Clear();
    behaviorPoints.Clear();
    touching.Clear();
    previousFocusEntityTimes.Clear();
    previousFocusEntities.Clear();
    afterburnerSounds.Clear();
    largeEngineSounds.Clear();
    smallEngineSounds.Clear();
    goalSearchDirections.Clear();
    goals.Clear();
    patrolWaypoints.Clear();
}

// Retail: 0x82C2C7B0 ?FirstThink@idDrone@@QAA_NXZ
bool idDrone::FirstThink() {
    physicsAxis = Services().GetAxis(*this);
    physicsOrigin = Services().GetOrigin(*this);
    health = startingHealth;
    currentPosition = previousOrigin = physicsOrigin;
    desiredFacing = currentFacing = physicsAxis[0];
    currentAxis = previousAxis = physicsAxis;
    desiredRoll = currentRoll = pitchToAlterSpeed = lookUpToGoUpAount = 0.0f;
    lowerNoseWhenAccelerating = 1.0f;
    immediateGoalPosition = finalGoalPosition = currentPosition;
    outOfControl = 0.0f;
    additivePosition.Zero();
    additiveMomentum.Zero();
    additiveFacing = idQuat(0.0f, 0.0f, 0.0f, 1.0f);
    additiveAngularMomentum = additiveFacing;
    bobGoal.Zero();
    engineSmokeAmount = 0.0f;
    nextEngineSmokeTime = nextSputterTime = 0;
    recentForceApplied.Zero();
    desiredSpeedMultiplier = Clamp(desiredSpeedMultiplier, 0.25f, 2.0f);
    patrolWaypoints.Clear();
    if (!Services().BuildPatrolWaypoints(*this, initialWaypoint,
            patrolWaypoints) || patrolWaypoints.Num() < 2) {
        return false;
    }
    goals.Clear();
    goalSearchDirections.Clear();
    if (patrolWaypointOn < 0 || patrolWaypointOn >= patrolWaypoints.Num()) {
        patrolWaypointOn = 0;
    }
    goals.Append(patrolWaypoints[patrolWaypointOn]);
    goalSearchDirections.Append(searchDirection);
    pathDistance = 0.0f;
    if (!Services().BuildInitialPath(*this, goals, searchDirection,
            splinePathLength) || splinePathLength <= 0.0f) {
        return false;
    }
    Services().ConfigureRigidPhysics(*this, 0, 37953);
    rigidPhysicsEnabled = true;
    Services().SetRigidPhysicsEnabled(*this, true);
    initialState = static_cast<droneState_t>(Clamp(
        static_cast<float>(initialState), 0.0f,
        static_cast<float>(DS_ADJUST_SPEED)));
    currentState = nextState = initialState;
    if (initialState != DS_SCANNING) lastNonScanState = initialState;
    changeStateTime = 0;
    moveStates[0] = moveStateByDroneState[initialState];
    moveStateMemberships[0] = 1.0f;
    int channel = CHANNEL_ENGINE_FIRST;
    idList<blendedSounds_t, 5>* soundGroups[3] = {
        &smallEngineSounds, &largeEngineSounds, &afterburnerSounds
    };
    for (int group = 0; group < 3; ++group) {
        for (int index = 0; index < soundGroups[group]->Num()
                && channel < CHANNEL_ENGINE_LIMIT; ++index) {
            blendedSounds_t& sound = (*soundGroups[group])[index];
            if (sound.sound == nullptr) continue;
            if (sound.minSpeedPitch > sound.maxSpeedPitch - 2.0f) {
                sound.minSpeedPitch = sound.maxSpeedPitch - 2.0f;
            }
            if (group == 2) {
                sound.minThrustVolume = -100.0f;
            } else if (sound.minThrustVolume
                    > sound.maxThrustVolume - 15.0f) {
                sound.minThrustVolume = sound.maxThrustVolume - 15.0f;
            }
            Services().StartSound(*this, channel, sound.sound);
            Services().SetSoundVolume(*this, channel, 0.0f);
            ++channel;
        }
    }
    firstThinkFlag = false;
    return true;
}

// Retail: 0x82C2D2D0 ?SetNewStateInternal@idDrone@@QAAXV?$idEnum@W4droneState_t@idDrone@@$08@@@Z
void idDrone::SetNewStateInternal(const int requestedState) {
    const int newState = std::max(0,
        std::min(static_cast<int>(DS_ADJUST_SPEED), requestedState));
    if (currentState == newState) return;
    if (newState == DS_SCANNING) {
        lastNonScanState = currentState;
    } else {
        lastNonScanState = newState;
        currentScanEntity = nullptr;
    }
    if (currentState == DS_SCANNING) TurnOffScanner();
    if (newState == DS_SCANNING) TurnOnScanner();
    allowFacingChanges = Services().StateFacingAllowance(
        currentState, newState);
    allowSpeedChanges = Services().StateSpeedAllowance(
        currentState, newState);
    allowRollChanges = Services().StateRollAllowance(
        currentState, newState);
    currentState = nextState = newState;
}

// Retail: 0x82C2D398 ?GetDesiredFacing@idDrone@@QAA?AVidVec3@@XZ
idVec3 idDrone::GetDesiredFacing() {
    if (currentState < DS_WAITING || currentState > DS_RETREATING) {
        currentState = DS_WAITING;
    }
    return currentState == DS_SCANNING
        ? GetDesiredFacingForScanning() : GetDesiredFacingForMoving();
}

// Retail: 0x82C2D470 ?Spawn@idDrone@@QAAXXZ
void idDrone::Spawn() {
    Services().RegisterWorldStateUser(*this);
    registeredWorldState = true;
    if (!Services().HasFaction(*this)) {
        Services().ReportMissingFaction(*this);
    }
    attachmentHandles[BOTTOM_ATTACHMENT] = Services().AddAttachment(
        *this, "models/vehicles/weapons/class3turret/class3turret.lwo", "ba");
    Services().ConfigureSpawnPhysics(*this, 197120, clipModelSize);
    physicsAxis = idMat3(1.0f);
    currentAxis = physicsAxis;
    Services().HideAttachments(*this);
    visibleSightTime = Clamp(visibleSightTime, 0.3f, 1.5f);
    Services().BecomeActive(*this, 5);
    Services().RegisterDrone(*this);
    registeredDrone = true;
}

// Retail: 0x82C2D76C $LN104_2
void idDroneSpawnClipCleanup(idClipModel* const clipModel) {
    idDrone::Services().DeleteTemporaryClip(clipModel);
}

// Retail: 0x82C2D798 ?Show@idDrone@@UAAXXZ
void idDrone::Show() {
    hidden = false;
    Services().ShowEntity(*this);
    if (!Services().UsesRelaxedChatter(*this)) {
        Services().RegisterWorldStateUser(*this);
        registeredWorldState = true;
        Services().ShowAttachments(*this);
    }
}

// Retail: 0x82C2D838 ?DormantEnd@idDrone@@UAAXH@Z
void idDrone::DormantEnd(const int timeDormant) {
    Services().DormantEnd(*this, timeDormant);
    Services().RegisterWorldStateUser(*this);
    registeredWorldState = true;
}

// Retail: 0x82C2D8E8 ?SetStateSetMoveState@idDrone@@QAAXV?$idEnum@W4droneState_t@idDrone@@$08@@V?$idEnum@W4droneMoveState_t@idDrone@@$04@@@Z
void idDrone::SetStateSetMoveState(int newState, int newMoveState) {
    newState = std::max(0,
        std::min(static_cast<int>(DS_ADJUST_SPEED), newState));
    if (newState == currentState) return;
    SetNewStateInternal(newState);
    if (newMoveState < DMS_STOPPED
            || newMoveState >= DMS_NUM_DRONE_MOVE_STATES) {
        newMoveState = moveStateByDroneState[newState];
    }
    newMoveState = std::max(0,
        std::min(static_cast<int>(DMS_FAST), newMoveState));
    ChangeMoveState(newMoveState,
        Services().MoveStateTransitionTime(moveStates[0], newMoveState));
}

// Retail: 0x82C2D9B8 ?SetState@idDrone@@QAAXV?$idEnum@W4droneState_t@idDrone@@$08@@@Z
void idDrone::SetState(int newState) {
    newState = std::max(0,
        std::min(static_cast<int>(DS_ADJUST_SPEED), newState));
    SetStateSetMoveState(newState, moveStateByDroneState[newState]);
}

// Retail: 0x82C2DA10 ?HandleObstacleAvoidance@idDrone@@QAA_NPBVidAI2@@AAVidBounds@@AAVidVec3@@AAVidMat3@@@Z
bool idDrone::HandleObstacleAvoidance(const idEntity* const ai,
        idBounds& bounds, idVec3& origin, idMat3& otherAxis) {
    if (health <= 0.0f || aheadDistance[0] <= 0.0f
            || ai == nullptr) return true;
    const idVec3 otherOrigin = Services().GetEntityOrigin(ai);
    idVec3 toOther = otherOrigin - physicsOrigin;
    const float directDistance = toOther.NormalizeFast();
    if (directDistance <= 0.01f) {
        obstacleAvoidanceMaxSpeed = 0.0f;
        return true;
    }
    if (directDistance >= MAX_COLLISION_DISTANCE) return true;
    if (nearestForwardAi == nullptr
            || (Services().GetEntityOrigin(nearestForwardAi)
                - physicsOrigin).Length() > directDistance
            || lastMovement.Dot(Services().GetEntityOrigin(nearestForwardAi)
                - physicsOrigin) < 0.0f) {
        nearestForwardAi = const_cast<idEntity*>(ai);
    }
    nearestForwardAiTime = Services().GetGameMilliseconds() + 100;
    idVec3 nearestPoint;
    const float splineDistance = NearestSplinePositionFastGuess(
        otherOrigin, nearestPoint);
    const float lookAhead = splineDistance + (splineDistance > 500.0f
        ? 32.0f : splineDistance > 100.0f
            ? (splineDistance - 100.0f) * 0.08f : 0.0f);
    origin = Services().GetWorldPosAlongPath(*this,
        pathDistance + lookAhead);
    const idVec3 next = Services().GetWorldPosAlongPath(*this,
        pathDistance + lookAhead + 1.0f);
    otherAxis = FacingToAxis(next - origin, 0.0f);
    const idVec3 expansion(16.0f, 16.0f, 16.0f);
    bounds[0] = bounds[0] - expansion;
    bounds[1] = bounds[1] + expansion;
    if (splineDistance >= aheadDistance[3] * 0.9f) return true;
    const idVec3 lateral = nearestPoint - otherOrigin;
    const float lateralDistance = lateral.Length();
    if (lateralDistance >= 333.0f) return true;
    const float combinedDistance = splineDistance + (lateralDistance > 40.0f
        ? (lateralDistance - 40.0f) * lateralDistance * 4.0f
            * 0.0034129692f : 0.0f);
    float speedLimit = 0.5f;
    if (combinedDistance > 400.0f) {
        speedLimit = combinedDistance < MAX_COLLISION_DISTANCE
            ? Lerp(0.5f, MAX_OBSTACLE_AVOIDANCE_SPEED,
                (combinedDistance - 400.0f)
                / (MAX_COLLISION_DISTANCE - 400.0f))
            : MAX_OBSTACLE_AVOIDANCE_SPEED;
    }
    obstacleAvoidanceMaxSpeed = std::min(obstacleAvoidanceMaxSpeed,
        speedLimit);
    if (lateralDistance < 350.0f) {
        const float splineDelta = std::fabs(splineDistance
            - aheadDistance[3]);
        const float avoidDistance = currentSpeed > 1.0f
            ? currentSpeed < 10.5f ? Lerp(MIN_AVOID_AI_DISTANCE_BY_SPEED,
                MAX_AVOID_AI_DISTANCE_BY_SPEED,
                (currentSpeed - 1.0f) / 9.5f)
                : MAX_AVOID_AI_DISTANCE_BY_SPEED
            : MIN_AVOID_AI_DISTANCE_BY_SPEED;
        if (splineDelta < avoidDistance) {
            const float amount = 1.0f - std::sqrt(
                (splineDelta / avoidDistance) * (splineDelta / avoidDistance)
                + (lateralDistance / 350.0f)
                    * (lateralDistance / 350.0f));
            if (amount > 0.0f) {
                idVec3 horizontal(lateral.x, lateral.y, 0.0f);
                horizontal = Normalized(horizontal,
                    idVec3(1.0f, 0.0f, 0.0f));
                goalAvoidanceOffset = goalAvoidanceOffset
                    + horizontal * amount;
                goalAvoidanceOffset.z += amount * 1.5f;
            }
        }
    }
    return true;
}

// Retail: 0x82C2E1A0 ?GetPlayerAvoidanceDistance@idDrone@@QAAMPBVidPlayer@@@Z
float idDrone::GetPlayerAvoidanceDistance(const idEntity* const player) {
    const idVec3 playerOrigin = Services().GetEntityOrigin(player);
    idVec3 direction = playerOrigin - physicsOrigin;
    const float directDistance = direction.NormalizeFast();
    if (directDistance >= 3000.0f
            || toAhead[0].Dot(direction) < 0.0f) return 3000.0f;
    if (directDistance <= 100.0f) return directDistance;
    idVec3 nearestPoint;
    const float splineDistance = NearestSplinePositionFastGuess(
        playerOrigin, nearestPoint);
    return splineDistance + (nearestPoint - playerOrigin).Length() * 10.0f;
}

// Retail: 0x82C2E4A8 ?StateThinkForScanning@idDrone@@QAA_NXZ
bool idDrone::StateThinkForScanning() {
    if (!Services().IsValidEntity(currentScanEntity)) {
        if (currentState == DS_SCANNING) {
            SetStateSetMoveState(DS_RETREATING, DMS_FAST);
        }
        return true;
    }
    idVec3 horizontalCurrent(currentFacing.x, currentFacing.y, 0.0f);
    idVec3 horizontalDesired(desiredFacing.x, desiredFacing.y, 0.0f);
    if (horizontalCurrent.NormalizeFast() < 0.001f
            || horizontalDesired.NormalizeFast() < 0.001f) {
        currentScanEntityCuriosity -= 0.01f;
        return true;
    }
    const float alignment = horizontalCurrent.Dot(horizontalDesired);
    if (alignment <= 0.9f || currentSpeed >= 2.0f) return true;
    const float reduction = alignment < 1.0f
        ? (alignment - 0.9f) * 0.1f : 0.01f;
    currentScanEntityCuriosity -= reduction;
    if (currentScanEntityCuriosity > 0.0f) return true;
    if (scanPlayerSound != nullptr && Services().IsPlayer(currentScanEntity)) {
        Services().StartSound(*this, CHANNEL_SCAN_HIT, scanPlayerSound);
        Services().SetSoundVolume(*this, CHANNEL_SCAN_HIT, 0.0f);
    }
    if (currentBehaviorPoint < 0
            || currentBehaviorPoint >= behaviorPoints.Num()) {
        if (lastNonScanState < DS_WAITING
                || lastNonScanState >= DS_NUM_DRONE_STATES
                || lastNonScanState == DS_SCANNING) {
            lastNonScanState = DS_MOVING;
        }
        SetState(lastNonScanState);
        return true;
    }
    behaviorPoint_t& behavior = behaviorPoints[currentBehaviorPoint];
    if (behavior.endScanDesiredSpeedMultiplier > 0.0f) {
        desiredSpeedMultiplier = Clamp(
            behavior.endScanDesiredSpeedMultiplier, 0.25f, 2.0f);
    }
    if (Services().IsValidEntity(behavior.endScanTrigger)) {
        Services().ActivateEntity(behavior.endScanTrigger,
            Services().IsValidEntity(behavior.entityToScan)
                ? behavior.entityToScan
                : reinterpret_cast<idEntity*>(this));
    }
    if (behavior.endScanWaypoint != nullptr) {
        goals.Clear();
        goalSearchDirections.Clear();
        goals.Append(behavior.endScanWaypoint);
        goalSearchDirections.Append(1.0f);
        searchNextUpdateTime = Services().GetGameMilliseconds() + 500;
        splinePathLength = 999.0f;
    }
    ++behavior.numScansDone;
    behavior.nextScanTime = Services().GetGameMilliseconds() + 5000;
    SetState(behavior.exitScanState);
    currentBehaviorPoint = -1;
    return true;
}

// Retail: 0x82C2EA68 ?Damage@idDrone@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
float idDrone::Damage(idEntity*, idEntity* const attacker,
        const idDeclDamage* const damage, const float damageScale,
        const idVec3&, trace_t* const trace) {
    if (damage == nullptr) return 0.0f;
    const float amount = Services().DamageAmount(damage) * damageScale;
    idVec3 impact;
    const bool hasImpact = Services().GetTraceImpactPoint(trace, impact);
    if (health <= 0.0f) {
        if (attacker != nullptr && hasImpact) {
            idVec3 force = impact - Services().GetEntityOrigin(attacker);
            if (force.NormalizeFast() >= 0.01f) {
                recentForceApplied = recentForceApplied + force * 0.333f;
            }
        }
    } else {
        DeployAndStowWeapon(0, 500, 10000);
        const int currentTime = Services().GetGameMilliseconds();
        nextEngineSmokeTime = currentTime;
        engineSmokeAmount += (1.0f - engineSmokeAmount) * 0.333f;
        if (nextSputterTime == 0 || nextSputterTime > currentTime + 1000) {
            const int maximum = std::max(1,
                static_cast<int>(std::max(0.0f, GetHealthPercent()) * 1500.0f));
            nextSputterTime = currentTime + Services().RandomInt(maximum);
        }
        if (attacker != nullptr && hasImpact) {
            Bump(impact, impact - Services().GetEntityOrigin(attacker),
                1.0f, 1.0f, 0.5f);
        }
        health -= amount;
        const float healthPercent = GetHealthPercent();
        for (int index = 0; index < damageBehaviors.Num(); ++index) {
            damageBehavior_t& behavior = damageBehaviors[index];
            if (behavior.hasBehaviorTriggered
                    || numActivates < behavior.minTriggerCount
                    || numActivates > behavior.maxTriggerCount
                    || healthPercent >= behavior.healthPercent) continue;
            behavior.hasBehaviorTriggered = true;
            if (healthPercent > 0.0f) {
                idEntity* scan = behavior.scanAttackerFlag
                    ? attacker : behavior.scanEntity;
                if (Services().IsValidEntity(scan)) {
                    currentScanEntity = scan;
                    SetState(DS_SCANNING);
                }
                if (behavior.forcedCuriosity > 0.0f) {
                    currentScanEntityCuriosity
                        = behavior.forcedCuriosity * 2.0f;
                }
                if (behavior.desiredSpeedMultiplier > 0.0f) {
                    desiredSpeedMultiplier
                        = behavior.desiredSpeedMultiplier;
                }
            }
            if (Services().IsValidEntity(behavior.trigger)) {
                Services().ActivateEntity(behavior.trigger,
                    reinterpret_cast<idEntity*>(this));
            }
        }
        if (health <= 0.0f) {
            KillDrone();
        } else if (amount > 0.0f && startingHealth > 0.0f) {
            const float horizontal = amount / startingHealth * 0.5f;
            const float vertical = amount / startingHealth * 1.5f;
            bobGoal.x = Clamp(bobGoal.x + (bobGoal.x < 0.0f ? -1.0f : 1.0f)
                * Services().RandomFloat(horizontal), -1.0f, 1.0f);
            bobGoal.y = Clamp(bobGoal.y + (bobGoal.y < 0.0f ? -1.0f : 1.0f)
                * Services().RandomFloat(horizontal), -1.0f, 1.0f);
            bobGoal.z = Clamp(bobGoal.z + (bobGoal.z < 0.0f ? -1.0f : 1.0f)
                * Services().RandomFloat(vertical), -1.0f, 1.0f);
        }
    }
    if (health <= 0.0f && recentForceApplied.LengthSqr() != 0.0f) {
        Services().ApplyDeathVelocity(*this, recentForceApplied * 25.0f);
        recentForceApplied.Zero();
    }
    return amount;
}

// Retail: 0x82C2F0F8 ?StateThink@idDrone@@QAA_NXZ
bool idDrone::StateThink() {
    if (currentState == DS_SCANNING) {
        currentScanEntityEffectOn = std::min(1.0f,
            currentScanEntityEffectOn + 0.03f);
    } else if (currentScanEntityEffectOn != 0.0f) {
        currentScanEntityEffectOn = std::max(0.0f,
            currentScanEntityEffectOn - 0.005f);
    }
    if (currentState < DS_WAITING || currentState > DS_RETREATING) {
        currentState = DS_WAITING;
    } else if (currentState == DS_SCANNING) {
        return StateThinkForScanning();
    }
    return true;
}

// Retail: 0x82C2F1A0 ?Think@idDrone@@UAAXXZ
void idDrone::Think() {
    const int currentTime = Services().GetGameMilliseconds();
    const float frameScale = std::max(1,
        Services().GetGameMillisecondsPerFrame()) / 16.0f;

    if (Services().UsesRelaxedChatter(*this)) {
        if (health <= 0.0f && currentTime >= deathDoneTime) {
            if (!wasRemoveEventPosted) {
                Services().QueueRemove(*this);
                wasRemoveEventPosted = true;
            }
        }
        engineSoundsFade = std::min(2.0f, engineSoundsFade + 0.01f);
        int channel = CHANNEL_ENGINE_FIRST;
        idList<blendedSounds_t, 5>* groups[3] = {
            &smallEngineSounds, &largeEngineSounds, &afterburnerSounds
        };
        for (int group = 0; group < 3; ++group) {
            for (int index = 0; index < groups[group]->Num()
                    && channel < CHANNEL_ENGINE_LIMIT; ++index) {
                blendedSounds_t& sound = (*groups[group])[index];
                SetEngineSoundVolume(channel++, sound,
                    group == 0 ? smallEngineThrustLevel
                    : group == 1 ? largeEngineThrustLevel
                    : afterburnerThrustLevel, 0.0f, 1.0f);
            }
        }
    } else {
        engineSoundsFade = 3.0f;
    }

    if (health <= 0.0f) {
        if (deathVarietyDesired == DD_SPINNING_OUT_OF_CONTROL) {
            if (currentTime < deathDoneTime) {
                Services().ApplyDeathVelocity(*this, deathThrust);
            } else if (currentTime >= deathDoneTime
                    + static_cast<int>(delayToHideDrone * 1000.0f)) {
                Hide();
                return;
            }
        } else if (currentTime >= deathDoneTime) {
            Hide();
            return;
        }
    }

    Services().UpdateAnimation(*this);
    UpdateFX();
    Services().TouchTriggers(*this);
    if (hidden) {
        Services().UpdateSound(*this);
        return;
    }
    if (firstThinkFlag && !FirstThink()) return;

    recentForceApplied = recentForceApplied * 0.95f;
    UpdateMoveStateMemberships();
    for (int gun = 0; gun < NUM_ATTACHMENTS; ++gun) {
        if (weaponArmTime[gun] != 0 && weaponArmTime[gun] <= currentTime) {
            DeployWeaponNow(gun);
        }
        if (weaponDisarmTime[gun] != 0
                && weaponDisarmTime[gun] <= currentTime) {
            StowWeaponNow(gun);
        }
        if (weaponArmSpeed[gun] != 0.0f) {
            weaponStatus[gun] = Clamp(weaponStatus[gun]
                + weaponArmSpeed[gun] * frameScale, 0.0f, 1.0f);
            if (weaponStatus[gun] == 0.0f
                    || weaponStatus[gun] == 1.0f) {
                weaponArmSpeed[gun] = 0.0f;
            }
        }
        if (attachmentHandles[gun] >= 0) {
            if (weaponStatus[gun] > 0.0f) {
                Services().ShowAttachment(*this, attachmentHandles[gun]);
            } else {
                Services().HideAttachment(*this, attachmentHandles[gun]);
            }
        }
    }

    if (currentBehaviorPoint < 0 && behaviorPoints.Num() > 0) {
        if (nextBehaviorPointToTest >= behaviorPoints.Num()) {
            nextBehaviorPointToTest = 0;
        }
        behaviorPoint_t& behavior = behaviorPoints[nextBehaviorPointToTest];
        idEntity* target = behavior.entityToScan;
        const bool validActivation = numActivates >= behavior.minTriggerCount
            && numActivates <= behavior.maxTriggerCount;
        if (validActivation && Services().IsValidEntity(target)) {
            const float distance = (Services().GetEntityOrigin(target)
                - physicsOrigin).Length();
            const bool canScanAgain = behavior.maxNumScans <= 0
                || behavior.numScansDone < behavior.maxNumScans;
            const bool timeReady = behavior.nextScanTime <= currentTime;
            if (distance < behavior.slowDistance) {
                overrideMaxDesiredSpeed = std::min(
                    overrideMaxDesiredSpeed > 0.0f
                        ? overrideMaxDesiredSpeed : currentSpeed,
                    std::max(0.5f, distance * 0.02f));
            }
            if (distance <= behavior.distanceToScan && canScanAgain
                    && timeReady && !behavior.wasDroneWithinRange
                    && Services().RandomFloat(1.0f)
                        <= behavior.scanChance) {
                currentScanEntity = target;
                currentScanEntityCuriosity = behavior.forcedCuriosity > 0.0f
                    ? behavior.forcedCuriosity * 2.0f
                    : currentScanEntityCuriosity;
                currentBehaviorPoint = nextBehaviorPointToTest;
                behavior.wasDroneWithinRange = true;
                if (Services().IsValidEntity(behavior.startScanTrigger)) {
                    Services().ActivateEntity(behavior.startScanTrigger,
                        target);
                }
                SetStateSetMoveState(DS_SCANNING, DMS_STOPPED);
            } else if (distance > behavior.distanceToScan) {
                behavior.wasDroneWithinRange = false;
            }
        }
        nextBehaviorPointToTest = (nextBehaviorPointToTest + 1)
            % behaviorPoints.Num();
    }

    if (health > 0.0f) {
        const float healthFraction = Clamp(GetHealthPercent(), 0.0f, 1.0f);
        engineSmokeAmount = std::max(0.0f,
            engineSmokeAmount - 0.0025f * frameScale);
        if (healthFraction < 0.5f) {
            engineSmokeAmount = std::max(engineSmokeAmount,
                (0.5f - healthFraction) * 2.0f);
        }
        if (engineSmokeAmount > 0.0f
                && currentTime >= nextEngineSmokeTime) {
            const int particleIndex = std::min(2,
                std::max(0, static_cast<int>((1.0f - healthFraction) * 3.0f)));
            Services().EmitHealthParticles(*this,
                smokeParticle[particleIndex], physicsOrigin, currentAxis);
            nextEngineSmokeTime = currentTime + 100;
        }
        if (nextSputterTime != 0 && currentTime >= nextSputterTime) {
            const int index = Services().RandomInt(3);
            Services().EmitHealthParticles(*this,
                sputterParticle[std::max(0, std::min(2, index))],
                physicsOrigin, currentAxis);
            nextSputterTime = currentTime
                + Services().RandomInt(std::max(1,
                    static_cast<int>(healthFraction * 1500.0f)));
        }
    }

    if (health <= 0.0f) {
        Services().Present(*this);
        Services().UpdateSound(*this);
        return;
    }

    if (patrolWaypoints.Num() <= 0) return;
    distanceToFinalGoal = std::max(0.0f,
        splinePathLength - pathDistance);
    if (distanceToFinalGoal <= std::max(4.0f, currentSpeed)) {
        if (goals.Num() > 0) goals.RemoveIndex(0);
        if (goalSearchDirections.Num() > 0) {
            searchDirection = goalSearchDirections[0];
            goalSearchDirections.RemoveIndex(0);
        }
        if (goals.Num() == 0) {
            patrolWaypointOn += patrolDirection;
            if (patrolWaypointOn >= patrolWaypoints.Num()) {
                patrolWaypointOn = 0;
            } else if (patrolWaypointOn < 0) {
                patrolWaypointOn = patrolWaypoints.Num() - 1;
            }
            goals.Append(patrolWaypoints[patrolWaypointOn]);
            goalSearchDirections.Append(searchDirection);
            currentPathType = DPT_PATROL;
        }
        if (!Services().RebuildPath(*this, goals,
                goalSearchDirections, splinePathLength)) return;
        pathDistance = 0.0f;
    }

    Services().UpdateAIWorldState(*this);
    idEntity* focusEntity = nullptr;
    const float focusScore = FindAutoFocusEntity(focusEntity);
    if (focusEntity != nullptr && focusScore > 0.0f
            && focusEntity != currentScanEntity
            && currentBehaviorPoint < 0) {
        if (Services().IsValidEntity(currentScanEntity)) {
            previousFocusEntities.Append(currentScanEntity);
            previousFocusEntityTimes.Append(currentTime);
        }
        currentScanEntity = focusEntity;
        SetStateSetMoveState(DS_SCANNING, DMS_STOPPED);
    }
    if (!StateThink()) {
        SetStateSetMoveState(DS_WAITING, DMS_STOPPED);
    }

    const float sampleDistances[4] = {
        std::max(20.0f, currentSpeed * 4.0f),
        std::max(60.0f, currentSpeed * 10.0f),
        std::max(150.0f, currentSpeed * 20.0f),
        MAX_SPLINE_AHEAD_DISTANCE
    };
    for (int index = 0; index < 4; ++index) {
        aheadDistance[index] = std::min(sampleDistances[index],
            std::max(0.0f, splinePathLength - pathDistance));
        ahead[index] = Services().GetWorldPosAlongPath(*this,
            pathDistance + aheadDistance[index]);
        toAhead[index] = Normalized(ahead[index] - currentPosition,
            index == 0 ? currentFacing : toAhead[index - 1]);
        if (index > 0) {
            aheadToAhead[index - 1] = Normalized(
                ahead[index] - ahead[index - 1], toAhead[index]);
        }
    }
    aheadToAhead[3] = aheadToAhead[2];
    dot0to1to2 = aheadToAhead[0].Dot(aheadToAhead[1]);
    dot1to2to3 = aheadToAhead[1].Dot(aheadToAhead[2]);

    nearestPlayerDistance = 3000.0f;
    if (slowForPlayer) {
        idList<idEntity*, 5> players;
        Services().GatherPlayers(*this, players);
        for (int index = 0; index < players.Num(); ++index) {
            nearestPlayerDistance = std::min(nearestPlayerDistance,
                GetPlayerAvoidanceDistance(players[index]));
        }
    }
    obstacleAvoidanceMaxSpeed = MAX_OBSTACLE_AVOIDANCE_SPEED;
    goalAvoidanceOffset.Zero();
    idList<idEntity*, 5> obstacles;
    Services().GatherObstacleEntities(*this, obstacles);
    for (int index = 0; index < obstacles.Num(); ++index) {
        idBounds obstacleBounds = Services().GetEntityBounds(obstacles[index]);
        idVec3 obstacleOrigin;
        idMat3 obstacleAxis;
        HandleObstacleAvoidance(obstacles[index], obstacleBounds,
            obstacleOrigin, obstacleAxis);
    }
    averageAvoidanceOffset = averageAvoidanceOffset * 0.9f
        + goalAvoidanceOffset * 0.1f;

    desiredFacing = GetDesiredFacing();
    if (averageAvoidanceOffset.LengthSqr() > 0.0001f) {
        desiredFacing = Normalized(desiredFacing
            + averageAvoidanceOffset, desiredFacing);
    }
    const float facingRate = Clamp(allowFacingChanges
        * 0.08f * frameScale, 0.0f, 1.0f);
    currentFacing = Normalized(Lerp(currentFacing,
        desiredFacing, facingRate), desiredFacing);
    allowFacingChanges = std::min(1.0f,
        allowFacingChanges + 0.01f * frameScale);

    desiredSpeed = GetDesiredSpeedForMoving();
    if (overrideMaxDesiredSpeed > 0.0f) {
        desiredSpeed = std::min(desiredSpeed, overrideMaxDesiredSpeed);
        if (++resetSpeedOverrideCounter > 1) {
            overrideMaxDesiredSpeed = 0.0f;
            resetSpeedOverrideCounter = 0;
        }
    }
    desiredSpeed *= Clamp(desiredSpeedMultiplier, 0.25f, 2.0f);
    desiredSpeed *= 1.0f - Clamp(outOfControl, 0.0f, 1.0f);
    if (nearestPlayerDistance < 300.0f) {
        desiredSpeed *= Clamp(nearestPlayerDistance / 300.0f,
            0.0f, 1.0f);
    }
    desiredSpeed = std::min(desiredSpeed, obstacleAvoidanceMaxSpeed);
    const float speedDelta = desiredSpeed - currentSpeed;
    const float speedStep = std::max(0.01f,
        allowSpeedChanges * emergencyBrakeScaler * frameScale * 0.2f);
    currentSpeed += Clamp(speedDelta, -speedStep, speedStep);
    allowSpeedChanges = std::min(1.0f,
        allowSpeedChanges + 0.01f * frameScale);
    emergencyBrakeScaler = std::min(1.0f,
        emergencyBrakeScaler + 0.0002f * frameScale);
    obstacleAvoidanceMaxSpeed = std::min(MAX_OBSTACLE_AVOIDANCE_SPEED,
        obstacleAvoidanceMaxSpeed + 0.1f * frameScale);
    lowerNoseWhenAccelerating = std::min(1.0f,
        lowerNoseWhenAccelerating + 0.01f * frameScale);

    desiredRoll = currentState == DS_SCANNING
        ? 0.0f : GetDesiredRollForMoving();
    currentRoll += (desiredRoll - currentRoll)
        * Clamp(allowRollChanges * 0.08f * frameScale, 0.0f, 1.0f);
    allowRollChanges = std::min(1.0f,
        allowRollChanges + 0.01f * frameScale);

    outOfControl = std::max(0.0f, outOfControl - 0.002f * frameScale);
    additiveMomentum = additiveMomentum * 0.95f;
    additivePosition = additivePosition * 0.9f + additiveMomentum;
    additiveAngularMomentum = additiveAngularMomentum * 0.95f;
    additiveAngularMomentum.w += 0.05f;
    additiveAngularMomentum.Normalize();
    additiveFacing = Multiply(additiveFacing,
        additiveAngularMomentum);
    additiveFacing.Normalize();

    previousOrigin = physicsOrigin;
    previousAxis = physicsAxis;
    const float stepDistance = std::max(0.0f, currentSpeed);
    Services().StepPath(*this, stepDistance);
    pathDistance = std::min(splinePathLength,
        pathDistance + stepDistance);
    currentPosition = Services().GetWorldPosAlongPath(*this, pathDistance);
    currentAxis = FacingToAxis(currentFacing, currentRoll)
        * additiveFacing.ToMat3();
    const idVec3 intendedOrigin = currentPosition + additivePosition;
    const idDroneTraceResult motion = Services().TraceMotion(*this,
        previousOrigin, intendedOrigin, previousAxis, currentAxis);
    physicsOrigin = motion.endPosition;
    physicsAxis = currentAxis;
    if (motion.fraction < 1.0f) {
        outOfControl = 1.0f;
        currentSpeed = desiredSpeed = 0.0f;
        Bump(motion.endPosition, motion.normal,
            1.0f, 1.0f, 0.5f);
        if (declWallSpark != nullptr) {
            Services().EmitWallImpact(*this, declWallSpark, motion);
        }
    }
    const idVec3 movement = physicsOrigin - previousOrigin;
    lastMovement = lastMovement * 0.8f + movement * 0.2f;

    const float acceleration = desiredSpeed - currentSpeed;
    afterburnerAmount = acceleration > 5.0f
        ? Clamp(acceleration * allowSpeedChanges * 0.1f, 0.0f, 1.0f)
        : 0.0f;
    if (afterburnerAmount > 0.0f && !wasAfterburnerFxStarted) {
        Services().StartConditionFX(*this, FX_AFTERBURNER_START);
        wasAfterburnerFxStarted = true;
    } else if (afterburnerAmount == 0.0f && wasAfterburnerFxStarted) {
        Services().StopConditionFX(*this, FX_AFTERBURNER_START);
        Services().StartConditionFX(*this, FX_AFTERBURNER_STOP);
        wasAfterburnerFxStarted = false;
        nextAfterburnerSmokeTime = 0;
    }
    smallEngineThrustLevel = smallEngineThrustLevel * 0.9f
        + Clamp(currentSpeed / 12.0f, 0.0f, 1.0f) * 0.1f;
    largeEngineThrustLevel = largeEngineThrustLevel * 0.9f
        + Clamp(std::fabs(acceleration) / 8.0f, 0.0f, 1.0f) * 0.1f;
    afterburnerThrustLevel = afterburnerThrustLevel * 0.9f
        + afterburnerAmount * 0.1f;
    for (int thruster = 0; thruster < 10; ++thruster) {
        const float targetPower = thruster < 2
            ? Clamp(largeEngineThrustLevel + afterburnerAmount, 0.0f, 1.0f)
            : Clamp(smallEngineThrustLevel, 0.0f, 1.0f);
        lastThrusterPower[thruster] = lastThrusterPower[thruster] * 0.9f
            + targetPower * 0.1f;
        const idVec3 start = physicsOrigin;
        const idVec3 end = start - currentAxis[0]
            * (thrusterLength * lastThrusterPower[thruster]);
        Services().UpdateThrusterBeam(*this, thruster, start, end,
            thrusterWidth * lastThrusterPower[thruster],
            lastThrusterPower[thruster]);
    }
    int channel = CHANNEL_ENGINE_FIRST;
    for (int index = 0; index < smallEngineSounds.Num()
            && channel < CHANNEL_ENGINE_LIMIT; ++index) {
        UpdateEngineSound(channel++, smallEngineSounds[index], currentSpeed,
            currentFacing.Dot(desiredFacing), smallEngineThrustLevel,
            0.0f, 1.0f);
    }
    for (int index = 0; index < largeEngineSounds.Num()
            && channel < CHANNEL_ENGINE_LIMIT; ++index) {
        UpdateEngineSound(channel++, largeEngineSounds[index], currentSpeed,
            currentFacing.Dot(desiredFacing), largeEngineThrustLevel,
            0.0f, 1.0f);
    }
    for (int index = 0; index < afterburnerSounds.Num()
            && channel < CHANNEL_ENGINE_LIMIT; ++index) {
        UpdateEngineSound(channel++, afterburnerSounds[index], currentSpeed,
            currentFacing.Dot(desiredFacing), afterburnerThrustLevel,
            0.0f, 1.0f);
    }
    if (currentScanEntityEffectOn != 0.0f
            && focusEntityMaterial != nullptr
            && Services().IsValidEntity(currentScanEntity)) {
        Services().UpdateFocusBeam(*this, currentScanEntity,
            focusEntityWidth * currentScanEntityEffectOn,
            focusEntityLength * currentScanEntityEffectOn,
            currentScanEntityEffectOn, focusEntityScanBob);
    }
    Services().Present(*this);
    Services().UpdateSound(*this);
    Services().BaseThink(*this);
}

// Retail: 0x82C356C8 $LN2520
void idDroneThinkStringCleanup(idStr& string) {
    string.Clear();
}
