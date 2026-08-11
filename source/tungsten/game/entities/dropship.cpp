#include "game/entities/dropship.h"

#include <algorithm>
#include <cmath>

namespace {
idDropShipServices defaultDropShipServices;
idDropShipServices* dropShipServices = &defaultDropShipServices;

constexpr int DROP_SHIP_SOUND_CHANNELS[3] = { 0, 1, 2 };
constexpr int FX_PROPELLER_START[3] = { 1, 3, 5 };
constexpr int FX_PROPELLER_STOP[3] = { 2, 4, 6 };
constexpr float DEG2RAD = 0.01745329251994329577f;
constexpr float RAD2DEG = 57.295779513082320876f;

float Clamp(const float value, const float minimum, const float maximum) {
    return std::max(minimum, std::min(maximum, value));
}

float Lerp(const float from, const float to, const float fraction) {
    return from + (to - from) * fraction;
}

idVec3 Normalized(idVec3 value, const idVec3& fallback) {
    if (value.NormalizeFast() < 0.0001f) return fallback;
    return value;
}

idMat3 FacingAxis(idVec3 forward) {
    forward = Normalized(forward, idVec3(1.0f, 0.0f, 0.0f));
    idVec3 right = forward.Cross(idVec3(0.0f, 0.0f, 1.0f));
    if (right.NormalizeFast() < 0.0001f) right.Set(0.0f, -1.0f, 0.0f);
    idVec3 up = right.Cross(forward);
    up.NormalizeFast();
    idMat3 result;
    result[0] = forward;
    result[1] = right;
    result[2] = up;
    return result;
}

float NormalizeAngle180(float angle) {
    while (angle > 180.0f) angle -= 360.0f;
    while (angle < -180.0f) angle += 360.0f;
    return angle;
}

float SpeedAtProximity(const idDropShip& ship, const float proximity,
        const float baseSpeed) {
    if (ship.speedTable.Num() == 0) return baseSpeed;
    if (proximity <= ship.speedTable[0].distance) {
        return ship.speedTable[0].speed;
    }
    for (int index = 1; index < ship.speedTable.Num(); ++index) {
        const dropShipSpeedTable_t& previous = ship.speedTable[index - 1];
        const dropShipSpeedTable_t& current = ship.speedTable[index];
        if (proximity <= current.distance) {
            const float range = current.distance - previous.distance;
            const float fraction = range > 0.0f
                ? Clamp((proximity - previous.distance) / range,
                    0.0f, 1.0f) : 1.0f;
            return Lerp(previous.speed, current.speed, fraction);
        }
    }
    return baseSpeed;
}

void ResetSpring(idDropShip& ship, const idVec3& origin) {
    ship.movementSpring.restLength = 0.0f;
    ship.movementSpring.k = ship.springConstant;
    ship.movementSpring.c = ship.springDampen;
    ship.movementSpring.m = std::max(0.001f, ship.springMass);
    ship.movementSpring.p0 = origin;
    ship.movementSpring.p1 = origin;
    ship.movementSpring.velocity.Zero();
    ship.movementSpring.maxSpeed = ship.springMaxSpeed;
}

void UpdateSpring(idDropShipSpring& spring, const float deltaSeconds) {
    const idVec3 displacement = spring.p0 - spring.p1;
    const idVec3 acceleration = displacement
        * (spring.k / std::max(0.001f, spring.m))
        - spring.velocity * (spring.c / std::max(0.001f, spring.m));
    spring.velocity = spring.velocity + acceleration * deltaSeconds;
    const float speed = spring.velocity.Length();
    if (spring.maxSpeed > 0.0f && speed > spring.maxSpeed) {
        spring.velocity = spring.velocity * (spring.maxSpeed / speed);
    }
    spring.p1 = spring.p1 + spring.velocity * deltaSeconds;
}
} // namespace

int idDropShipServices::GetGameMilliseconds() const { return 0; }
int idDropShipServices::GetGameMillisecondsPerFrame() const { return 16; }
float idDropShipServices::GetRealSecondsPerFrame() const { return 1.0f / 60.0f; }
float idDropShipServices::GetRealMillisecondsPerFrame() const { return 16.0f; }
bool idDropShipServices::UsesRelaxedChatter(const idDropShip&) const {
    return false;
}
void idDropShipServices::BecomeActive(idDropShip&, int) {}
void idDropShipServices::BecomeInactive(idDropShip&, int) {}
void idDropShipServices::QueueRemove(idDropShip&) {}
void idDropShipServices::ShowEntity(idDropShip&) {}
void idDropShipServices::StartConditionFX(idDropShip&, int) {}
void idDropShipServices::StopConditionFX(idDropShip&, int) {}
void idDropShipServices::UpdateBaseFX(idDropShip&) {}
void idDropShipServices::UpdateFrameCommands(idDropShip&) {}
void idDropShipServices::UpdateAnimation(idDropShip&) {}
void idDropShipServices::UpdateAttachments(idDropShip&) {}
bool idDropShipServices::IsPlayingSound(const idDropShip&, int) const {
    return false;
}
void idDropShipServices::StartSound(idDropShip&, int,
        const idSoundShader*, bool) {}
void idDropShipServices::SetSoundPitch(idDropShip&, int, float) {}
void idDropShipServices::SetSoundVolume(idDropShip&, int, float) {}
idVec3 idDropShipServices::GetOrigin(const idDropShip& ship) const {
    return ship.physicsOrigin;
}
idMat3 idDropShipServices::GetAxis(const idDropShip& ship) const {
    return ship.physicsAxis;
}
void idDropShipServices::SetOrigin(idDropShip& ship,
        const idVec3& origin) { ship.physicsOrigin = origin; }
void idDropShipServices::SetAxis(idDropShip& ship,
        const idMat3& axis) { ship.physicsAxis = axis; }
bool idDropShipServices::GetDropTagTransform(const idDropShip&,
        const char*, idVec3&, idMat3&) const { return false; }
bool idDropShipServices::IsSplinePathValid(const idSplinePath* path) const {
    return path != nullptr;
}
idDropShipSplineCurve* idDropShipServices::AllocateSpline(
        idSplinePath*, float) { return nullptr; }
void idDropShipServices::ReleaseSpline(idDropShipSplineCurve* spline) {
    delete spline;
}
void idDropShipServices::GatherPlayers(const idDropShip&,
        idList<idEntity*, 5>&) const {}
bool idDropShipServices::IsEntityDead(const idEntity*) const { return false; }
bool idDropShipServices::IsEntityDying(const idEntity*) const { return false; }
idVec3 idDropShipServices::GetEntityOrigin(const idEntity*) const {
    return idVec3(0.0f, 0.0f, 0.0f);
}
void idDropShipServices::SetControllerShake(idEntity*, float) {}
idWeapon* idDropShipServices::CreateWeapon(const idDeclVehicleWeapon*) {
    return nullptr;
}
void idDropShipServices::DestroyWeapon(idWeapon*) {}
void idDropShipServices::AttachWeapon(idDropShip&, idWeapon*, const char*) {}
bool idDropShipServices::AimWeapon(idDropShip&, idWeapon*, idEntity*,
        idVec3&, idMat3&) { return false; }
void idDropShipServices::FireWeapon(idDropShip&, idWeapon*, idEntity*,
        const idVec3&, const idMat3&) {}
idEntity* idDropShipServices::SpawnCargo(idTarget_Spawn*,
        const idDeclEntityDef*, const idVec3&) { return nullptr; }
bool idDropShipServices::IsAI(const idEntity*) const { return false; }
void idDropShipServices::SetCargoTransform(idEntity*, const idVec3&,
        const idMat3&) {}
void idDropShipServices::SetCargoDropState(idEntity*, int) {}
void idDropShipServices::GiveJetPack(idEntity*, const idDeclInventory*) {}
bool idDropShipServices::SpringTuningChanged() const { return false; }
void idDropShipServices::ClearSpringTuningChanged() {}
void idDropShipServices::DrawSpringDebug(const idDropShip&,
        const idDropShipSpring&) {}
void idDropShipServices::ReportWarning(const idDropShip&, const char*) {}
void idDropShipServices::ReportError(const idDropShip&, const char*) {}
void idDropShipServices::ReleaseRuntime(idDropShip&) {}

void idDropShip::SetServices(idDropShipServices* const services) {
    dropShipServices = services == nullptr ? &defaultDropShipServices : services;
}

idDropShipServices& idDropShip::Services() { return *dropShipServices; }

// Retail: 0x82C357B8 ?UpdatePropellerVisuals@idDropShip@@AAAX_N@Z
void idDropShip::UpdatePropellerVisuals(const bool on) {
    for (int index = 0; index < 3; ++index) {
        if (on) Services().StartConditionFX(*this, FX_PROPELLER_START[index]);
        else Services().StopConditionFX(*this, FX_PROPELLER_STOP[index]);
    }
    propellersOn = on;
}

// Retail: 0x82C35840 ?State_Done@idDropShip@@AAAXXZ
void idDropShip::State_Done() {
    const int currentTime = Services().GetGameMilliseconds();
    if (stateTimer == -1) stateTimer = currentTime;
    if (currentTime >= stateStartTime + 5000 && !removalPosted) {
        Services().QueueRemove(*this);
        removalPosted = true;
    }
}

// Retail: 0x82C358B8 ?ChangeState@idDropShip@@AAAXW4dropShipState_t@@@Z
void idDropShip::ChangeState(const dropShipState_t newState) {
    dropShipState = newState;
    stateStartTime = Services().GetGameMilliseconds();
    stateTimer = -1;
}

// Retail: 0x82C35908 ?UpdateSounds@idDropShip@@AAAXXZ
void idDropShip::UpdateSounds() {
    const int count = std::min(3, dropShipSound.Num());
    const float movementFraction = Clamp(currentDt * 0.0625f, 0.0f, 1.0f);
    const int currentTime = Services().GetGameMilliseconds();
    const float fadeMilliseconds = std::max(1.0f, soundFadeTime * 1000.0f);
    float fade = 1.0f;
    if (dropShipState == DPSP_DONE || dropShipState == DPSP_POWERDOWN) {
        fade = 1.0f - (currentTime - stateStartTime) / fadeMilliseconds;
    } else if (currentTime - soundStartTime <= fadeMilliseconds) {
        fade = (currentTime - soundStartTime) / fadeMilliseconds;
    }
    fade = Clamp(fade, 0.0f, 1.0f);
    for (int index = 0; index < count; ++index) {
        const dropShipSound_t& sound = dropShipSound[index];
        float volume = Lerp(sound.minVolume, sound.maxVolume,
            movementFraction);
        const float pitch = Lerp(sound.minPitch, sound.maxPitch,
            movementFraction);
        const int channel = DROP_SHIP_SOUND_CHANNELS[index];
        if (Services().IsPlayingSound(*this, channel)) {
            volume = (volume + 60.0f) * fade - 60.0f;
        }
        Services().SetSoundPitch(*this, channel, pitch);
        Services().SetSoundVolume(*this, channel, volume);
    }
}

// Retail: 0x82C35D10 ?GetDropLocation@idDropShip@@AAA?AVidVec3@@H@Z
idVec3 idDropShip::GetDropLocation(const int index) {
    static const char* const tagNames[3] = {
        "drop_left", "drop_right", "drop_back"
    };
    idVec3 origin = Services().GetOrigin(*this);
    idMat3 axis = Services().GetAxis(*this);
    const int tagIndex = ((index % 3) + 3) % 3;
    if (!Services().GetDropTagTransform(*this, tagNames[tagIndex],
            origin, axis)) {
        Services().ReportWarning(*this,
            "missing dropship tree animator, props collection, or drop tag");
        return Services().GetOrigin(*this);
    }
    return origin;
}

// Retail: 0x82C35F48 ?ModifyAxisFromMovementSpring@idDropShip@@ABAXAAVidMat3@@@Z
void idDropShip::ModifyAxisFromMovementSpring(idMat3& axis) const {
    const idVec3 displacement = movementSpring.p1 - movementSpring.p0;
    const float pitchAmount = springPitchClamp != 0.0f
        ? Clamp(currentAxis[0].Dot(displacement), -springPitchClamp,
            springPitchClamp) / springPitchClamp : 0.0f;
    const float rollAmount = springRollClamp != 0.0f
        ? Clamp(currentAxis[1].Dot(displacement), -springRollClamp,
            springRollClamp) / springRollClamp : 0.0f;
    axis = axis * idAngles(springMaxPitch * pitchAmount, 0.0f,
        springMaxRoll * rollAmount).ToMat3();
}

// Retail: 0x82C360E8 ?Show@idDropShip@@UAAXXZ
void idDropShip::Show() {
    Services().ShowEntity(*this);
    UpdatePropellerVisuals(true);
    soundStartTime = Services().GetGameMilliseconds();
    for (int index = 0; index < dropShipSound.Num(); ++index) {
        if (dropShipSound[index].sound == nullptr) {
            Services().ReportError(*this, "dropship contains a null loop sound");
            break;
        }
        if (index >= 3) continue;
        const int channel = DROP_SHIP_SOUND_CHANNELS[index];
        if (!Services().IsPlayingSound(*this, channel)) {
            Services().StartSound(*this, channel,
                dropShipSound[index].sound, true);
            Services().SetSoundVolume(*this, channel, -60.0f);
        }
    }
}

// Retail: 0x82C36238 ?State_EnRoute@idDropShip@@AAAXXZ
void idDropShip::State_EnRoute() {
    if (stateTimer == -1) stateTimer = Services().GetGameMilliseconds();
    if (currentSpline != nullptr
            && currentSpline->IsDone(currentSplineTime)) {
        ChangeState(DPSP_DROPCARGO);
    }
}

// Retail: 0x82C362C8 ?State_HeadingOut@idDropShip@@AAAXXZ
void idDropShip::State_HeadingOut() {
    if (stateTimer == -1) stateTimer = Services().GetGameMilliseconds();
    if (currentSpline != nullptr
            && currentSpline->IsDone(currentSplineTime)) {
        ChangeState(powerDownAtEndOfSpline ? DPSP_POWERDOWN : DPSP_DONE);
    }
}

// Retail: 0x82C36368 ?State_PowerDown@idDropShip@@AAAXXZ
void idDropShip::State_PowerDown() {
    if (stateTimer != -1) return;
    const int currentTime = Services().GetGameMilliseconds();
    if (currentTime < stateStartTime
            + static_cast<int>(timeToPowerDown * 1000.0f)) return;
    UpdatePropellerVisuals(false);
    stateTimer = currentTime;
    if (powerDownSound != nullptr) {
        Services().StartSound(*this, -1, powerDownSound, false);
    }
    ChangeState(DPSP_LANDED);
    Services().BecomeInactive(*this, 1);
}

// Retail: 0x82C36488 ?RunPhysics@idDropShip@@AAAXXZ
void idDropShip::RunPhysics() {
    if (currentSpline == nullptr) return;
    const float endTime = currentSpline->GetEndTime();
    const bool done = currentSpline->IsDone(currentSplineTime);
    float targetDelta = 0.0f;
    if (dropShipState != DPSP_HOVER && !done) {
        targetDelta = static_cast<float>(
            Services().GetGameMillisecondsPerFrame());
        const float travelled = currentSpline->GetLengthForTime(
            currentSplineTime);
        const float total = currentSpline->GetLengthForTime(endTime);
        const float remaining = std::max(0.0f, total - travelled);
        if (currentSplineIdx >= 0 && currentSplineIdx < splines.Num()
                && speedTable.Num() > 0) {
            const float baseSpeed = std::max(0.001f,
                splines[currentSplineIdx].speed);
            const float proximity = dropShipState == DPSP_ENROUTE
                ? remaining : std::min(travelled, remaining);
            const float speed = SpeedAtProximity(*this, proximity,
                baseSpeed);
            targetDelta *= speed / baseSpeed;
        }
        currentSplineTime += currentDt;
    }
    const float interpolation = Clamp(
        Services().GetGameMillisecondsPerFrame() / 16.0f, 0.0f, 1.0f);
    currentDt = Lerp(currentDt, targetDelta, interpolation);
    if (!currentSpline->IsDone(currentSplineTime)) {
        movementSpring.p0 = currentSpline->GetCurrentValue(currentSplineTime);
    }
    movementSpring.maxSpeed = springMaxSpeed;
    UpdateSpring(movementSpring,
        std::max(0.0f, Services().GetRealSecondsPerFrame()));
    movementSpring.p1.z -= springGravity;
    Services().SetOrigin(*this, movementSpring.p1);
    physicsOrigin = movementSpring.p1;

    idVec3 derivative = currentSpline->GetCurrentFirstDerivative(
        currentSplineTime);
    if (std::fabs(derivative.z) > std::fabs(derivative.x)
            && std::fabs(derivative.z) > std::fabs(derivative.y)) {
        derivative = Services().GetAxis(*this)[0];
    }
    derivative.z = 0.0f;
    derivative = Normalized(derivative, currentAxis[0]);
    const float desiredYaw = std::atan2(derivative.y, derivative.x)
        * RAD2DEG;
    angles.yaw += Clamp(NormalizeAngle180(desiredYaw - angles.yaw),
        -0.5f, 0.5f);
    currentAxis = idAngles(0.0f, angles.yaw, 0.0f).ToMat3();
    idMat3 outputAxis = currentAxis;
    ModifyAxisFromMovementSpring(outputAxis);

    float shakeScale = 1.0f;
    if (dropShipState == DPSP_POWERDOWN) {
        const float duration = std::max(1.0f, timeToPowerDown * 1000.0f);
        shakeScale = Clamp(1.0f
            - (Services().GetGameMilliseconds() - stateStartTime) / duration,
            0.0f, 1.0f);
    }
    engineShake.x -= 0.02f;
    engineShake.y -= 0.01f;
    const float shakeDegrees = shakeScale * 0.025f * RAD2DEG;
    outputAxis = outputAxis * idAngles(
        std::sin(engineShake.y) * shakeDegrees, 0.0f,
        std::sin(engineShake.x) * shakeDegrees).ToMat3();
    Services().SetAxis(*this, outputAxis);
    physicsAxis = outputAxis;
}

// Retail: 0x82C36D10 ?UpdateFX@idDropShip@@EAAXXZ
void idDropShip::UpdateFX() {
    Services().UpdateBaseFX(*this);
    idList<idEntity*, 5> players;
    Services().GatherPlayers(*this, players);
    const idVec3 shipOrigin = Services().GetOrigin(*this);
    const idVec3 effectCenter = shipOrigin - idVec3(0.0f, 0.0f, 2000.0f);
    const float fadeDuration = std::max(1.0f, soundFadeTime * 1000.0f);
    const float fade = Clamp((Services().GetGameMilliseconds()
        - soundStartTime) / fadeDuration, 0.0f, 1.0f);
    for (int index = 0; index < players.Num() && index < 6; ++index) {
        const idVec3 playerOrigin = Services().GetEntityOrigin(players[index]);
        if ((playerOrigin - effectCenter).LengthSqr() > 4000000.0f) continue;
        const float distance = (playerOrigin - shipOrigin).Length();
        const float proximity = Clamp(1.0f - distance * 0.00025f,
            0.0f, 1.0f);
        const float magnitude = std::pow(proximity, 5.0f) * 0.75f * fade;
        Services().SetControllerShake(players[index], magnitude);
    }
}

// Retail: 0x82C36F60 ?DebugDropShip@idDropShip@@AAAXXZ
void idDropShip::DebugDropShip() {
    if (Services().SpringTuningChanged()) {
        ResetSpring(*this, Services().GetOrigin(*this));
        Services().ClearSpringTuningChanged();
    }
    if (springDebug) Services().DrawSpringDebug(*this, movementSpring);
}

// Retail: 0x82C372F0 ?State_WaitTillEnemyCleared@idDropShip@@AAAXXZ
void idDropShip::State_WaitTillEnemyCleared() {
    for (int index = 0; index < droppedCargo.Num(); ++index) {
        idEntity* const entity = droppedCargo[index];
        if (entity != nullptr && Services().IsAI(entity)
                && !Services().IsEntityDead(entity)
                && !Services().IsEntityDying(entity)) {
            return;
        }
    }
    ChangeState(DPSP_DROPCARGO);
}

// Retail: 0x82C375A0 ??0idDropShip@@QAA@XZ
idDropShip::idDropShip()
    : splines(), cargo(), timeBetweenDrops(3.0f),
      jetPackInventory(nullptr), speedTable(), dropImmediately(false),
      startOffHovering(false), powerDownAtEndOfSpline(false),
      timeToPowerDown(5.0f), powerDownSound(nullptr),
      fireDelayWhenMoving(5.0f), fireDelayWhenHovering(5.0f),
      vehicleWeapon(nullptr), weaponAttachment(nullptr), dropShipSound(),
      soundFadeTime(5.0f), droppedCargo(), weapon(nullptr),
      currentSpline(nullptr), currentSplineIdx(-1), movementSpring(),
      currentAxis(1.0f), angles(0.0f, 0.0f, 0.0f), currentDt(0.0f),
      dropShipState(DPSP_ENROUTE), stateTimer(-1), stateStartTime(0),
      soundStartTime(0), currentSplineTime(0.0f), fireTimer(0),
      curNumDropped(0), engineShake(0.0f, 0.0f),
      physicsOrigin(0.0f, 0.0f, 0.0f), physicsAxis(1.0f),
      propellersOn(false), removalPosted(false), spawnValid(true),
      springConstant(1.0f), springDampen(0.85f), springMass(1.0f),
      springMaxSpeed(150000.0f), springGravity(0.5f),
      springRollClamp(1000.0f), springMaxRoll(60.0f),
      springPitchClamp(750.0f), springMaxPitch(-30.0f),
      springDebug(false) {
}

// Retail: 0x82C37948 ??1idDropShip@@UAA@XZ
idDropShip::~idDropShip() {
    Services().UpdateAttachments(*this);
    if (weapon != nullptr) Services().DestroyWeapon(weapon);
    if (currentSpline != nullptr) Services().ReleaseSpline(currentSpline);
    Services().ReleaseRuntime(*this);
    weapon = nullptr;
    currentSpline = nullptr;
    droppedCargo.Clear();
    dropShipSound.Clear();
    speedTable.Clear();
    cargo.Clear();
    splines.Clear();
}

// Retail: 0x82C37B60 ?FindSplineType@idDropShip@@AAAXW4dropShipSplineType_t@@@Z
void idDropShip::FindSplineType(const dropShipSplineType_t splineType) {
    if (currentSpline != nullptr) Services().ReleaseSpline(currentSpline);
    currentSpline = nullptr;
    currentSplineIdx = -1;
    currentSplineTime = 0.0f;
    if (splineType == DPST_NONE) return;
    for (int index = 0; index < splines.Num(); ++index) {
        const dropShipSpline& record = splines[index];
        if (record.type != splineType) continue;
        currentSplineIdx = index;
        if (record.speed <= 0.001f) {
            Services().ReportError(*this, "dropship spline speed is too small");
            spawnValid = false;
            return;
        }
        if (!Services().IsSplinePathValid(record.spline)) {
            Services().ReportError(*this, "dropship spline path is invalid");
            spawnValid = false;
            return;
        }
        currentSpline = Services().AllocateSpline(record.spline,
            record.speed);
        if (currentSpline == nullptr) {
            Services().ReportError(*this, "dropship failed to allocate spline");
            spawnValid = false;
        }
        return;
    }
}

// Retail: 0x82C37D30 ?UpdateWeapons@idDropShip@@AAAXXZ
void idDropShip::UpdateWeapons() {
    if (weapon == nullptr) return;
    idList<idEntity*, 5> players;
    Services().GatherPlayers(*this, players);
    idEntity* target = nullptr;
    for (int index = 0; index < players.Num() && index < 6; ++index) {
        if (players[index] != nullptr
                && !Services().IsEntityDead(players[index])
                && !Services().IsEntityDying(players[index])) {
            target = players[index];
            break;
        }
    }
    if (target == nullptr) return;
    idVec3 muzzleOrigin;
    idMat3 muzzleAxis(1.0f);
    if (!Services().AimWeapon(*this, weapon, target,
            muzzleOrigin, muzzleAxis)) return;
    fireTimer += static_cast<int>(Services().GetRealMillisecondsPerFrame());
    const float delay = fireDelayWhenMoving * 1000.0f;
    if (fireTimer > static_cast<int>(delay)) {
        fireTimer = 0;
        Services().FireWeapon(*this, weapon, target,
            muzzleOrigin, muzzleAxis);
    }
}

// Retail: 0x82C381E8 ?OnActivate@idDropShip@@EAAXPAVidEntity@@@Z
void idDropShip::OnActivate(idEntity*) {
    for (int index = 0; index < dropShipSound.Num(); ++index) {
        if (dropShipSound[index].sound == nullptr) {
            Services().ReportError(*this, "dropship contains a null loop sound");
            return;
        }
        if (index >= 3) continue;
        const int channel = DROP_SHIP_SOUND_CHANNELS[index];
        if (!Services().IsPlayingSound(*this, channel)) {
            Services().StartSound(*this, channel,
                dropShipSound[index].sound, true);
            Services().SetSoundVolume(*this, channel, -60.0f);
        }
    }
    if (dropShipState != DPSP_HOVER) return;
    FindSplineType(DPST_STARTSPLINE);
    if (currentSpline != nullptr) {
        ChangeState(DPSP_ENROUTE);
        return;
    }
    FindSplineType(DPST_ENDSPLINE);
    if (currentSpline != nullptr) ChangeState(DPSP_HEADINGOUT);
}

// Retail: 0x82C383D8 ?Spawn@idDropShip@@QAAXXZ
void idDropShip::Spawn() {
    Services().BecomeActive(*this, 5);
    spawnValid = true;
    dropShipState_t initial = DPSP_ENROUTE;
    FindSplineType(DPST_STARTSPLINE);
    if (currentSpline == nullptr) {
        FindSplineType(DPST_ENDSPLINE);
        initial = currentSpline == nullptr ? DPSP_HOVER : DPSP_HEADINGOUT;
    }
    dropShipState = startOffHovering ? DPSP_HOVER : initial;
    stateTimer = -1;
    stateStartTime = Services().GetGameMilliseconds();
    UpdatePropellerVisuals(true);

    idVec3 start = currentSpline != nullptr
        ? currentSpline->GetCurrentValue(0.0f) : Services().GetOrigin(*this);
    if (dropImmediately && currentSpline != nullptr) {
        currentSplineTime = currentSpline->GetEndTime();
        start = currentSpline->GetCurrentValue(currentSplineTime);
    }
    ResetSpring(*this, start);
    movementSpring.p1.z -= springGravity;
    Services().SetOrigin(*this, movementSpring.p1);
    physicsOrigin = movementSpring.p1;
    physicsAxis = Services().GetAxis(*this);
    currentAxis = physicsAxis;
    angles.yaw = std::atan2(currentAxis[0].y, currentAxis[0].x) * RAD2DEG;
    angles.pitch = angles.roll = 0.0f;
    currentDt = 0.0f;
    soundStartTime = Services().GetGameMilliseconds();

    float previousDistance = -1.0f;
    for (int index = 0; index < speedTable.Num(); ++index) {
        if (speedTable[index].speed <= 0.001f) {
            Services().ReportError(*this,
                "dropship speed-table speed is too small");
            spawnValid = false;
        }
        if (speedTable[index].distance <= previousDistance) {
            Services().ReportError(*this,
                "dropship speed-table distances are not increasing");
            spawnValid = false;
        }
        previousDistance = speedTable[index].distance;
    }
    for (int index = 0; index < splines.Num(); ++index) {
        if (!Services().IsSplinePathValid(splines[index].spline)) {
            Services().ReportError(*this, "dropship has bad spline info");
            spawnValid = false;
        }
    }
    if (vehicleWeapon != nullptr) {
        weapon = Services().CreateWeapon(vehicleWeapon);
        if (weapon != nullptr) Services().AttachWeapon(*this, weapon, "weapon");
    }
}

// Retail: 0x82C38810 ?DropCargo@idDropShip@@AAAXXZ
void idDropShip::DropCargo() {
    if (cargo.Num() == 0) return;
    idList<idEntity*, 5> players;
    Services().GatherPlayers(*this, players);
    idEntity* player = players.Num() > 0 ? players[0] : nullptr;
    dropShipCargo_t& entry = cargo[0];
    if (entry.targetSpawn == nullptr && entry.cargoDef == nullptr) {
        Services().ReportError(*this, "dropship cargo entry has no spawn target or entity definition");
        return;
    }
    const idVec3 origin = GetDropLocation(curNumDropped % 3);
    idEntity* const spawned = Services().SpawnCargo(entry.targetSpawn,
        entry.cargoDef, origin);
    if (spawned == nullptr) {
        Services().ReportError(*this, "dropship failed to spawn cargo");
        return;
    }
    idMat3 axis(1.0f);
    if (player != nullptr) {
        idVec3 direction = Services().GetEntityOrigin(player) - origin;
        direction.z = 0.0f;
        axis = FacingAxis(direction);
    }
    Services().SetCargoTransform(spawned, origin, axis);
    if (Services().IsAI(spawned)) {
        droppedCargo.Append(spawned);
        Services().SetCargoDropState(spawned, 0);
        if (jetPackInventory != nullptr) {
            Services().GiveJetPack(spawned, jetPackInventory);
        }
    }
    --entry.count;
    ++curNumDropped;
}

// Retail: 0x82C38C18 ?State_DropCargo@idDropShip@@AAAXXZ
void idDropShip::State_DropCargo() {
    const int currentTime = Services().GetGameMilliseconds();
    if (stateTimer == -1) {
        stateTimer = currentTime
            + static_cast<int>(timeBetweenDrops * 1000.0f);
    } else if (currentTime > stateTimer) {
        stateTimer = currentTime
            + static_cast<int>(timeBetweenDrops * 1000.0f);
        DropCargo();
    }
    if (cargo.Num() > 0 && cargo[0].count <= 0) {
        cargo.RemoveIndex(0);
        if (cargo.Num() > 0 && cargo[0].waitTillClear) {
            ChangeState(DPSP_WAITTILLCLEAR);
        }
    }
    if (cargo.Num() == 0) {
        FindSplineType(DPST_ENDSPLINE);
        if (currentSpline == nullptr) {
            Services().ReportError(*this,
                "dropship could not find a heading-out spline");
            spawnValid = false;
        }
        ChangeState(DPSP_HEADINGOUT);
    }
}

// Retail: 0x82C38D98 ?Think@idDropShip@@UAAXXZ
void idDropShip::Think() {
    if (Services().UsesRelaxedChatter(*this)) return;
    switch (dropShipState) {
        case DPSP_DROPCARGO: State_DropCargo(); break;
        case DPSP_WAITTILLCLEAR: State_WaitTillEnemyCleared(); break;
        case DPSP_HEADINGOUT: State_HeadingOut(); break;
        case DPSP_POWERDOWN: State_PowerDown(); break;
        case DPSP_ENROUTE: State_EnRoute(); break;
        case DPSP_DONE: State_Done(); break;
        case DPSP_HOVER:
        case DPSP_LANDED:
        default: break;
    }
    UpdateWeapons();
    Services().UpdateFrameCommands(*this);
    RunPhysics();
    Services().UpdateAnimation(*this);
    UpdateFX();
    UpdateSounds();
    DebugDropShip();
}
