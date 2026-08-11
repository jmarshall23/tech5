#include "presentablevehiclecar.h"

#include <algorithm>
#include <cmath>

namespace {

idPresentableVehicleServices defaultVehicleServices;
idPresentableVehicleServices* vehicleServices = &defaultVehicleServices;

void VehicleEvent(idPresentableVehicle& vehicle, const char* name) {
    vehicleServices->Event(vehicle, name);
}

float ClampVehicle(float value, float minimum, float maximum) {
    return std::max(minimum, std::min(maximum, value));
}

idQuat MatrixToQuaternion(const idMat3& matrix) {
    idQuat result;
    const float trace = matrix[0][0] + matrix[1][1] + matrix[2][2];
    if (trace > 0.0f) {
        const float scale = std::sqrt(trace + 1.0f) * 2.0f;
        result.w = 0.25f * scale;
        result.x = (matrix[2][1] - matrix[1][2]) / scale;
        result.y = (matrix[0][2] - matrix[2][0]) / scale;
        result.z = (matrix[1][0] - matrix[0][1]) / scale;
    } else if (matrix[0][0] > matrix[1][1]
            && matrix[0][0] > matrix[2][2]) {
        const float scale = std::sqrt(1.0f + matrix[0][0]
            - matrix[1][1] - matrix[2][2]) * 2.0f;
        result.w = (matrix[2][1] - matrix[1][2]) / scale;
        result.x = 0.25f * scale;
        result.y = (matrix[0][1] + matrix[1][0]) / scale;
        result.z = (matrix[0][2] + matrix[2][0]) / scale;
    } else if (matrix[1][1] > matrix[2][2]) {
        const float scale = std::sqrt(1.0f + matrix[1][1]
            - matrix[0][0] - matrix[2][2]) * 2.0f;
        result.w = (matrix[0][2] - matrix[2][0]) / scale;
        result.x = (matrix[0][1] + matrix[1][0]) / scale;
        result.y = 0.25f * scale;
        result.z = (matrix[1][2] + matrix[2][1]) / scale;
    } else {
        const float scale = std::sqrt(1.0f + matrix[2][2]
            - matrix[0][0] - matrix[1][1]) * 2.0f;
        result.w = (matrix[1][0] - matrix[0][1]) / scale;
        result.x = (matrix[0][2] + matrix[2][0]) / scale;
        result.y = (matrix[1][2] + matrix[2][1]) / scale;
        result.z = 0.25f * scale;
    }
    return result.Normalize();
}

} // namespace

void Tungsten_SetPresentableVehicleServices(
        idPresentableVehicleServices* services) {
    vehicleServices = services != nullptr ? services : &defaultVehicleServices;
}

// EA 0x82B90390
const idDeclMaterial* GetEffectsMaterial(
        const vehicleEffectsMaterials_t& materials, int surfaceType) {
    switch (surfaceType) {
    case 1: return materials.metal;
    case 2: return materials.stone;
    case 4: return materials.wood;
    case 5: return materials.cardboard;
    case 6: return materials.liquid;
    case 7: return materials.glass;
    case 8: return materials.plastic;
    case 9: return materials.asphalt;
    case 10: return materials.dirt;
    case 11: return materials.concrete;
    case 12: return materials.foliage;
    case 13: return materials.linoleum;
    case 14: return materials.fabric;
    case 15: return materials.rubber;
    case 16: return materials.rock;
    default: return nullptr;
    }
}

// EA 0x82B91AE0
idVec3 Mat3DiffToAngularVelocity(const idMat3& from, const idMat3& to) {
    idQuat rotation = MatrixToQuaternion(from.Transpose() * to);
    if (rotation.w < 0.0f) {
        rotation.x = -rotation.x;
        rotation.y = -rotation.y;
        rotation.z = -rotation.z;
        rotation.w = -rotation.w;
    }
    const float sinHalfAngle = std::sqrt(rotation.x * rotation.x
        + rotation.y * rotation.y + rotation.z * rotation.z);
    if (sinHalfAngle <= 1.0e-6f) {
        return idVec3(0.0f, 0.0f, 0.0f);
    }
    const float angle = 2.0f * std::atan2(sinHalfAngle,
        ClampVehicle(rotation.w, -1.0f, 1.0f));
    return idVec3(rotation.x, rotation.y, rotation.z)
        * (angle / sinHalfAngle);
}

// EA 0x82B91FE8
idVec3 ComputeCameraViewOrigin(const vehicleCameraPlacement_t& placement,
        const idVec3& targetOrigin, const idMat3& targetAxis, float range) {
    constexpr float DEG2RAD = 0.01745329251994329577f;
    const float yaw = placement.yaw * DEG2RAD;
    idVec3 result = targetOrigin + targetAxis[1] * placement.lateral;
    result.z += placement.height + 8.0f;
    result = result - targetAxis[0] * (std::cos(yaw) * range);
    result = result + targetAxis[1] * (std::sin(yaw) * range);
    return result;
}

// EA 0x82B90480
void idPresentableVehicle::Interpolate(int currentTime, float fraction) {
    if (!ServerOverridingPosition()) {
        idPresentableAnimatedEntity::Interpolate(currentTime, fraction);
    }
    VehicleEvent(*this, "Interpolate");
}

// EA 0x82B90488
void idPresentableVehicle::Megaboost(float acceleration, int duration) {
    megaBoostAcceleration = acceleration;
    megaBoostTime = duration;
    hasBoosted = duration > 0;
    VehicleEvent(*this, "Megaboost");
}

// EA 0x82B904D8
int idPresentableVehicle::GetCurrentWeaponGroup() const {
    return currentWeaponGroup;
}

// EA 0x82B904E0
void* idPresentableVehicle::GetCrosshair() {
    return vehicleServices->EventPointer(*this, "GetCrosshair");
}

// EA 0x82B904E8
void idPresentableVehicle::DeactivateCrosshair() {
    crosshairActive = false;
    VehicleEvent(*this, "DeactivateCrosshair");
}

// EA 0x82B90520
void idPresentableVehicle::WeaponFiredWithNoAmmo() {
    VehicleEvent(*this, "WeaponFiredWithNoAmmo");
}

// EA 0x82B90598
void idPresentableVehicle::AddProjectileLock() {
    ++numLockedProjectiles;
}

// EA 0x82B905A8
const char* idPresentableVehiclePhysicsCB::GetName() const {
    return "idPresentableVehicle";
}

// EA 0x82B905D0
bool idPresentableVehiclePhysicsCB::GetMasterPosition(idVec3& origin,
        idMat3& axis) const {
    if (vehicle == nullptr) return false;
    origin = vehicleServices->EventVector(*vehicle, "GetMasterPositionOrigin");
    axis = vehicleServices->EventMatrix(*vehicle, "GetMasterPositionAxis");
    return vehicleServices->EventBool(*vehicle, "GetMasterPosition", true);
}

// EA 0x82B905F0
vehicleCollideResult_t idPresentableVehiclePhysicsCB::Contact(
        int, void*) {
    if (vehicle == nullptr) return VEHICLE_COLLIDE_NONE;
    VehicleEvent(*vehicle, "PhysicsContact");
    return static_cast<vehicleCollideResult_t>(vehicleServices->EventInt(
        *vehicle, "PhysicsContactResult", VEHICLE_COLLIDE_NONE));
}

// EA 0x82B906C8
void idPresentableVehiclePhysicsCB::ApplyImpulse(int, int,
        const idVec3&, const idVec3&) {
    if (vehicle != nullptr) VehicleEvent(*vehicle, "ApplyImpulse");
}

// EA 0x82B90850
void idPresentableVehiclePhysicsCB::ApplyForce(int, int,
        const idVec3&, const idVec3&) {
    if (vehicle != nullptr) VehicleEvent(*vehicle, "ApplyForce");
}

// EA 0x82B90878
bool idPresentableVehiclePhysicsCB::Crush(int) {
    return vehicle != nullptr
        && vehicleServices->EventBool(*vehicle, "Crush", false);
}

// EA 0x82B908A0
void idPresentableVehiclePhysicsCB::ApplyDamage(int, int,
        const idDeclDamage*) {
    if (vehicle != nullptr) VehicleEvent(*vehicle, "ApplyDamage");
}

// EA 0x82B908C8
void idPresentableVehiclePhysicsCB::ActivatePhysics(int) {
    if (vehicle != nullptr) VehicleEvent(*vehicle, "ActivatePhysics");
}

// EA 0x82B90900
void idPresentableVehiclePhysicsCB::DeactivatePhysics(int) {
    if (vehicle != nullptr) VehicleEvent(*vehicle, "DeactivatePhysics");
}

// EA 0x82B90928
void idPresentableVehiclePhysicsCB::ApplyWaterEffects(int, int) {
    if (vehicle != nullptr) VehicleEvent(*vehicle, "ApplyWaterEffects");
}

// EA 0x82B90950
void idPresentableVehiclePhysicsCB::ApplyWaterSplashEffects(
        int, int, int, int) {
    if (vehicle != nullptr) VehicleEvent(*vehicle, "ApplyWaterSplashEffects");
}

// EA 0x82B90978
void idPresentableVehicle::Present() {
    idPresentableAnimatedEntity::Present();
    VehicleEvent(*this, "Present");
}

// EA 0x82B909E8
void idPresentableVehicle::InitImpactMgr() {
    VehicleEvent(*this, "InitImpactMgr");
}

// EA 0x82B90A98
int Tungsten_GetVehicleSurfaceSound(int surfaceType, int fallback) {
    return surfaceType >= 0 ? surfaceType : fallback;
}

// EA 0x82B90C98
void idPresentableVehicle::KillEngineSounds() {
    engineRunning = false;
    VehicleEvent(*this, "KillEngineSounds");
}

// EA 0x82B90D20
void idPresentableVehicle::UpdateAirTime() {
    if (numWheelsOnGround == 0) ++timeInAir;
    else timeInAir = 0;
}

// EA 0x82B90DA0
bool idPresentableVehicle::InitVehicleBody() {
    const bool result = vehicleServices->EventBool(*this,
        "InitVehicleBody", true);
    VehicleEvent(*this, "InitVehicleBodyComplete");
    return result;
}

// EA 0x82B91270
bool idPresentableVehicle::InitVehiclePhysics(idPhysicsCallbacks* callbacks) {
    clientPhysicsCB = callbacks;
    physicsObj = static_cast<idPhysics*>(
        vehicleServices->EventPointer(*this, "InitVehiclePhysics"));
    return physicsObj != nullptr
        || vehicleServices->EventBool(*this, "InitVehiclePhysicsResult", true);
}

// EA 0x82B914A8
void idPresentableVehicle::UpdateCurrentThrottle(float target) {
    currentThrottle = ClampVehicle(target, -1.0f, 1.0f);
}

// EA 0x82B914F0
void idPresentableVehicle::UpdateCurrentMPH() {
    currentApproxMPH = vehicleServices->EventFloat(*this,
        "CurrentMPH", currentApproxLinearVelocity.Length() * 0.05681818f);
    currentMPH = currentApproxMPH;
}

// EA 0x82B915D0
float idPresentableVehicle::GetBoostPower() const { return boostPower; }

// EA 0x82B91630
float idPresentableVehicle::GetBoostDuration() const { return boostDuration; }

// EA 0x82B916E8
void idPresentableVehicle::RechargeBoost(int elapsedMS) {
    if (!boosting && !boostDisabled && boostDuration > 0.0f) {
        boostPower = ClampVehicle(boostPower
            + elapsedMS / boostDuration, 0.0f, 1.0f);
    }
}

// EA 0x82B91798
void idPresentableVehicle::ResetBoostPower() {
    boostPower = 1.0f;
    resetBoost.count = (resetBoost.count + 1) & 7;
}

// EA 0x82B91880
void idPresentableVehicle::BoostForce(float scale) {
    if (!boostDisabled && boostPower > 0.0f) {
        boosting = true;
        boostScalePercent = ClampVehicle(scale, 0.0f, 1.0f);
        hasBoosted = true;
        VehicleEvent(*this, "BoostForce");
    }
}

// EA 0x82B919C0
float idPresentableVehicle::GetMaxSteerAngle(float speed) const {
    const float base = vehicleServices->EventFloat(*this,
        "MaxSteerAngle", 30.0f);
    const float maximum = std::max(1.0f, GetMaxSpeed());
    return base * (1.0f - 0.65f * ClampVehicle(std::fabs(speed) / maximum,
        0.0f, 1.0f));
}

// EA 0x82B919F0
void idPresentableVehicle::RunPhysics() {
    VehicleEvent(*this, "RunPhysics");
    UpdateCurrentMPH();
    CalcWheelsOnGround();
}

// EA 0x82B91C20
bool idPresentableVehicle::UseSteerControl() {
    return enableVehicleControls && !engineDisabled
        && vehicleServices->EventBool(*this, "UseSteerControl", true);
}

// EA 0x82B91C58
void idPresentableVehicle::PitchRollStabilize() {
    if (autoRollState != AUTOROLL_NONE) VehicleEvent(*this, "PitchRollStabilize");
}

// EA 0x82B91F80
void idPresentableVehicle::GetViewOriginAndAxis(idVec3& outOrigin,
        idMat3& outAxis) {
    outOrigin = driverViewOrigin;
    outAxis = driverViewAxis;
    if (vehicleServices->EventBool(*this, "UseServiceView", false)) {
        outOrigin = vehicleServices->EventVector(*this, "ViewOrigin", outOrigin);
        outAxis = vehicleServices->EventMatrix(*this, "ViewAxis", outAxis);
    }
}

// EA 0x82B92118
void idPresentableVehicle::GetDriverView(idVec3& outOrigin,
        idMat3& outAxis, float& outFov, idView*) {
    GetViewOriginAndAxis(outOrigin, outAxis);
    outFov = driverViewFov;
    VehicleEvent(*this, "GetDriverView");
}

// EA 0x82B92188
void idPresentableVehicle::ResetDriverView() {
    driverViewAngles = idAngles(0.0f, 0.0f, 0.0f);
    driverViewAxis = idMat3(1.0f);
    driverViewFov = vehicleServices->EventFloat(*this,
        "DefaultDriverFov", 90.0f);
}

// EA 0x82B92230
void idPresentableVehicle::AddQuickSlotItem(idInventoryItem*, int slot) {
    curQuickItemSlot = slot;
    VehicleEvent(*this, "AddQuickSlotItem");
}

// EA 0x82B923D8
void idPresentableVehicle::SetCurQuickItem(int itemIndex) {
    curQuickItem = quickItems.empty() ? -1
        : std::max(0, std::min(itemIndex,
            static_cast<int>(quickItems.size()) - 1));
}

// EA 0x82B92438
void idPresentableVehicle::RemoveQuickItemThink(idVehicleQuickItem* item) {
    quickItems.erase(std::remove(quickItems.begin(), quickItems.end(), item),
        quickItems.end());
}

// EA 0x82B924C8
void idPresentableVehicle::QuickItemThink() {
    VehicleEvent(*this, "QuickItemThink");
}

// EA 0x82B925E0
void idPresentableVehicle::UpdateDriverViewAngles(const usercmd_t&,
        const usercmd_t&) { VehicleEvent(*this, "UpdateDriverViewAngles"); }

// EA 0x82B92798
void idPresentableVehicle::AdjustCg() { VehicleEvent(*this, "AdjustCg"); }

// EA 0x82B92898
void idPresentableVehicle::UpdateStickControl(float x, float y,
        bool absolute) {
    currentSteerAngle = absolute ? x : currentSteerAngle + x;
    currentThrottle = ClampVehicle(absolute ? y : currentThrottle + y,
        -1.0f, 1.0f);
    VehicleEvent(*this, "UpdateStickControl");
}

// EA 0x82B931D8
void idPresentableVehicle::ResetBoostFOV() {
    boostScalePercent = 0.0f;
    VehicleEvent(*this, "ResetBoostFOV");
}

// EA 0x82B931F0
void idPresentableVehicle::StopBoost() {
    boosting = false;
    StopBoostFX();
}

// EA 0x82B93228
void idPresentableVehicle::SetBoostDuration(float duration) {
    boostDuration = std::max(0.0f, duration);
}

// EA 0x82B932C8
float idPresentableVehicle::GetHealth() const { return healthSerialized; }

// EA 0x82B932E8
bool idPresentableVehicle::GetHasInfiniteAmmo() const {
    return hasInfiniteAmmoSerialized;
}

// EA 0x82B93308
void idPresentableVehicle::PredictPickup() {
    VehicleEvent(*this, "PredictPickup");
}

// EA 0x82B93410
void idPresentableVehicle::RestoreDetachableItems() {
    VehicleEvent(*this, "RestoreDetachableItems");
}

// EA 0x82B934B0
void idPresentableVehicle::GetInputSettings(idPresentablePlayer*) {
    VehicleEvent(*this, "GetInputSettings");
}

// EA 0x82B93578
void* idPresentableVehicle::GetPredictedFXMgr() {
    return vehicleServices->EventPointer(*this, "PredictedFXManager");
}

// EA 0x82B935D0
void idPresentableVehicle::UpdateFX(float fovScale, float depthHack) {
    idPresentable::UpdateFX(fovScale, depthHack);
    VehicleEvent(*this, "UpdatePredictedFX");
}

// EA 0x82B93668
void idPresentableVehicle::UpdateFX(const idVec3&, const idMat3&) {
    VehicleEvent(*this, "UpdateVehicleFXTransform");
}

// EA 0x82B93720
void idPresentableVehicle::InitFXMgr(const idDeclFX* declaration) {
    idPresentable::InitFXMgr(declaration);
    VehicleEvent(*this, "InitPredictedFX");
}

// EA 0x82B937A0
void idPresentableVehicle::ShutdownFXMgr() {
    VehicleEvent(*this, "ShutdownPredictedFX");
    idPresentable::ShutdownFXMgr();
}

// EA 0x82B93818
void idPresentableVehicle::StartPredictedFX(fxCondition_t,
        fxExtraCondition_t) { VehicleEvent(*this, "StartPredictedFX"); }

// EA 0x82B939D0
void idPresentableVehicle::StopPredictedFX(fxCondition_t,
        fxExtraCondition_t) { VehicleEvent(*this, "StopPredictedFX"); }

// EA 0x82B93A88
bool idPresentableVehicle::IsDead() const { return healthSerialized <= 0.0f; }

// EA 0x82B93AD0
void idPresentableVehicle::AddBoostUpSP(int amount) {
    AddBoost(static_cast<float>(amount));
}

// EA 0x82B93B00
void idPresentableVehicle::AddJumpManSP() {
    VehicleEvent(*this, "AddJumpManSP");
}

// EA 0x82B93B28
void idPresentableVehicle::DrawBirdsView(idPresentablePlayer*) {
    VehicleEvent(*this, "DrawBirdsView");
}

// EA 0x82B93C88
bool idPresentableVehicle::GetTagPosition(const char* prop,
        const char* tag, idVec3& outOrigin, idMat3& outAxis) const {
    return GetPresentableTagPosition(prop, tag, outOrigin, outAxis);
}

// EA 0x82B93D08
void idPresentableVehicle::ClearDamageFX() {
    VehicleEvent(*this, "ClearDamageFX");
}

// EA 0x82B93DC0
void Tungsten_TestServerArmor(const idCmdArgs&) {}

// EA 0x82B93EC8
void Tungsten_TestServerArmorRestore(const idCmdArgs&) {}

// EA 0x82B93F58
void idPresentableVehicle::TransformDetachable(int) {
    VehicleEvent(*this, "TransformDetachable");
}

// EA 0x82B94078
void idPresentableVehicle::PredictHitScanHit(idPresentable*, float,
        const idVec3&, const idVec3&, const idDeclProjectile*, trace_t*) {
    VehicleEvent(*this, "PredictHitScanHit");
}

// EA 0x82B94150
bool idPresentableVehicle::HasAlternateEngine() const {
    return vehicleServices->EventBool(*this, "HasAlternateEngine", false);
}

// EA 0x82B941C8
void idPresentableVehicle::OnHitByEMP() {
    engineDisabled = true;
    EMPTimeout = vehicleServices->EventInt(*this, "EMPTimeout", 1000);
    KillEngineSounds();
}

// EA 0x82B94258
void idPresentableVehicle::RemoveProjectileLock() {
    if (numLockedProjectiles > 0) --numLockedProjectiles;
}

// EA 0x82B94280
void idPresentableVehicle::UpdateSmash() {
    if (isSmashActive && smashTimeout <= 0) SetSmashActive(false);
    else if (isSmashActive) --smashTimeout;
}

// EA 0x82B94740
void idPresentableVehicle::SerializePredictionOnly(
        idSerializer& serializer) {
    serializer.Serialize(currentThrottle);
    serializer.Serialize(currentMPH);
    serializer.Serialize(currentApproxLinearVelocity);
    serializer.Serialize(currentSteerAngle);
    serializer.Serialize(boostPower);
    serializer.Serialize(boosting);
    serializer.Serialize(braking);
    serializer.Serialize(handBraking);
    vehicleServices->SerializeExtra(*this, serializer,
        "SerializePredictionOnly");
}

// EA 0x82B94D90
void idPresentableVehicle::SerializeNonPredictionState(
        idSerializer& serializer) {
    serializer.Serialize(healthSerialized);
    serializer.Serialize(maxHealthSerialized);
    serializer.Serialize(engineRunning);
    serializer.Serialize(engineDisabled);
    serializer.Serialize(hasInfiniteAmmoSerialized);
    serializer.Serialize(numLockedProjectiles);
    vehicleServices->SerializeExtra(*this, serializer,
        "SerializeNonPredictionState");
}

// EA 0x82B94E20
void idPresentableVehicle::HandleWheelDustTrail(wheelLoc_t,
        const idVec3&, int, float, float) {
    VehicleEvent(*this, "HandleWheelDustTrail");
}

// EA 0x82B95420
void idPresentableVehicle::HandleWheelDust(wheelLoc_t,
        const idDeclParticle*, const idVec3&, int, float) {
    VehicleEvent(*this, "HandleWheelDust");
}

// EA 0x82B95610
void idPresentableVehicle::CheckRampLanding() {
    if (timeInAir > 0 && numWheelsOnGround > 0) {
        VehicleEvent(*this, "RampLanding");
        timeInAir = 0;
    }
}

// EA 0x82B957E8
void idPresentableVehicle::DropTireMark(bool, const idVec3&, void*,
        float, float, float, const idVec3&, const void*, float, float,
        float, int, int) {
    VehicleEvent(*this, "DropTireMark");
}

// EA 0x82B95B98
idVehicleWeapon* idPresentableVehicle::GetWeaponForGroup(int group) {
    return group >= 0 && group < static_cast<int>(weapons.size())
        ? weapons[group] : nullptr;
}

// EA 0x82B95C08
void idPresentableVehicle::InventoryAdded(idInventoryItem* item,
        int count, bool canIntro) {
    idPresentableAnimatedEntity::InventoryAdded(item, count, canIntro);
    VehicleEvent(*this, "InventoryAdded");
}

// EA 0x82B95C78
bool idPresentableVehicle::AddBoost(float amount) {
    const float oldPower = boostPower;
    boostPower = ClampVehicle(boostPower + amount, 0.0f, 1.0f);
    if (boostPower != oldPower) VehicleEvent(*this, "AddBoost");
    return boostPower != oldPower;
}

// EA 0x82B95D78
float idPresentableVehicle::GetMaxSpeed() const {
    return currentMaxSpeed > 0.0f ? currentMaxSpeed : maxSpeed;
}

// EA 0x82B95DC0
void idPresentableVehicle::ArcadeSteering() {
    if (UseSteerControl()) VehicleEvent(*this, "ArcadeSteering");
}

// EA 0x82B964A8
void idPresentableVehicle::AutoRollOver() {
    if (autoRollState != AUTOROLL_NONE) VehicleEvent(*this, "AutoRollOver");
}

// EA 0x82B96A78
void idPresentableVehicle::CalcWheelsOnGround() {
    numWheelsOnGround = std::max(0, vehicleServices->EventInt(*this,
        "WheelsOnGround", numWheelsOnGround));
    UpdateAirTime();
}

// EA 0x82B96AD8
void idPresentableVehicle::UpdateHorn(usercmd_t&, usercmd_t&) {
    VehicleEvent(*this, "UpdateHorn");
}

// EA 0x82B96C08
void idPresentableVehicle::StartBoostFX() {
    VehicleEvent(*this, "StartBoostFX");
}

// EA 0x82B96C90
void idPresentableVehicle::StopBoostFX() {
    VehicleEvent(*this, "StopBoostFX");
}

// EA 0x82B96D18
void idPresentableVehicle::ForceBoostFx(int duration) {
    forceBoostFxTime = std::max(0, duration);
    if (duration > 0) StartBoostFX();
}

// EA 0x82B96D68
void idPresentableVehicle::SetBoostDisabled(bool disabled) {
    boostDisabled = disabled;
    if (disabled) StopBoost();
}

// EA 0x82B96E38
bool idPresentableVehicle::GetUserCommand(vehicleSeat_t seat,
        usercmd_t*, usercmd_t*) const {
    return seat >= VEHICLE_SEAT_DRIVER && seat <= VEHICLE_SEAT_GUNNER
        && occupants[seat] != nullptr
        && vehicleServices->EventBool(*this, "GetUserCommand", true);
}

// EA 0x82B96EF0
void idPresentableVehicle::DeleteWeapons() {
    VehicleEvent(*this, "DeleteWeapons");
    weapons.clear();
    currentWeaponGroup = -1;
}

// EA 0x82B96F98
void idPresentableVehicle::UpdateDetachableItems() {
    VehicleEvent(*this, "UpdateDetachableItems");
}

// EA 0x82B97068
bool idPresentableVehicle::WeaponGroupHasAmmo(int group) {
    return hasInfiniteAmmoSerialized || (GetWeaponForGroup(group) != nullptr
        && vehicleServices->EventBool(*this, "WeaponGroupHasAmmo", true));
}

// EA 0x82B970E8
void idPresentableVehicle::ClearAllWeaponAnims() {
    VehicleEvent(*this, "ClearAllWeaponAnims");
}

// EA 0x82B97138
void idPresentableVehicle::SetCurrentWeapon() {
    currentWeaponGroup = clientPendingWeaponGroup >= 0
        ? clientPendingWeaponGroup : currentWeaponGroup;
    clientPendingWeaponGroup = -1;
    VehicleEvent(*this, "SetCurrentWeapon");
}

// EA 0x82B971B8
bool idPresentableVehicle::PlayWeaponGroupAnim(
        vehicleWeaponAnimState_t) {
    VehicleEvent(*this, "PlayWeaponGroupAnim");
    return vehicleServices->EventBool(*this, "WeaponAnimPlayed", true);
}

// EA 0x82B97238
bool idPresentableVehicle::CheckInhibitFire(usercmd_t*) {
    return !weaponGroupActive || IsDead() || engineDisabled
        || vehicleServices->EventBool(*this, "InhibitFire", false);
}

// EA 0x82B97300
const idDeclWeapon* idPresentableVehicle::GetWeaponDecl() {
    return static_cast<const idDeclWeapon*>(
        vehicleServices->EventPointer(*this, "WeaponDeclaration"));
}

// EA 0x82B97378
void idPresentableVehicle::RecordClientDamageInfo(
        const idDeclDamage* damage, const idVec3& direction,
        const idVec3& point, float damageScale, float damageAmount,
        float startHealth, float endHealth, idPresentable* attacker,
        bool predicted) {
    vehicleDamageInfo_t& item = damageHistory[damageHistoryIndex & 7];
    item.damageDef = damage;
    item.damageDir = direction;
    item.impactPoint = point;
    item.damageScale = damageScale;
    item.damage = damageAmount;
    item.startHealth = startHealth;
    item.endHealth = endHealth;
    item.attackerSpawnId = attacker != nullptr ? attacker->spawnId : 0;
    item.predicted = predicted;
    item.time = vehicleServices->EventInt(*this, "DamageTime", 0);
    ++damageHistoryIndex;
}

// EA 0x82B974C0
bool idPresentableVehicle::GetWeaponView(idVec3& outOrigin,
        idMat3& outAxis, float& outFov, bool& thirdPerson) {
    outOrigin = driverViewOrigin;
    outAxis = driverViewAxis;
    outFov = driverViewFov;
    thirdPerson = vehicleServices->EventBool(*this,
        "WeaponThirdPerson", true);
    return vehicleServices->EventBool(*this, "GetWeaponView", true);
}

// EA 0x82B97AC0
void idPresentableVehicle::GetDetachableWorldTransform(
        const idDeclInventory*, idVec3& outOrigin, idMat3& outAxis) {
    outOrigin = origin;
    outAxis = axis;
    VehicleEvent(*this, "GetDetachableWorldTransform");
}

// EA 0x82B98088
bool idPresentableVehicle::PredictSpecialDeath() {
    const bool predicted = healthSerialized <= 0.0f
        && vehicleServices->EventBool(*this, "PredictSpecialDeath", false);
    if (predicted) VehicleEvent(*this, "SpecialDeath");
    return predicted;
}

// EA 0x82B98100
void idPresentableVehicle::UpdateWheelSkid() {
    VehicleEvent(*this, "UpdateWheelSkid");
}

// EA 0x82B98250
void idPresentableVehicle::HandleBoostViewFx(float fraction,
        float& fov, float& shake) {
    const float effect = ClampVehicle(fraction, 0.0f, 1.0f)
        * boostScalePercent;
    fov += vehicleServices->EventFloat(*this, "BoostFovDelta", 12.0f)
        * effect;
    shake += vehicleServices->EventFloat(*this, "BoostShake", 1.0f)
        * effect;
}

// EA 0x82B986A8
void idPresentableVehicle::GetSimpleCameraInternal(idVec3& outOrigin,
        idMat3& outAxis, float& outFov) {
    GetViewOriginAndAxis(outOrigin, outAxis);
    outFov = driverViewFov;
    HandleBoostViewFx(boostScalePercent, outFov, currentThrottle);
    VehicleEvent(*this, "GetSimpleCameraInternal");
}

// EA 0x82B99098
void idPresentableVehicle::StopBlurFX() {
    VehicleEvent(*this, "StopBlurFX");
}

// EA 0x82B99128
idPresentablePlayer* idPresentableVehicle::PlayerIsOccupant() const {
    for (idPresentable* occupant : occupants) {
        if (occupant != nullptr && occupant->GetPlayerInterface() != nullptr) {
            return occupant->GetPlayerInterface();
        }
    }
    return nullptr;
}

// EA 0x82B991F0
idPresentable* idPresentableVehicle::GetDriver() const {
    return occupants[VEHICLE_SEAT_DRIVER];
}

// EA 0x82B99210
idPresentablePlayer* idPresentableVehicle::GetPlayerDriver() const {
    return GetDriver() != nullptr ? GetDriver()->GetPlayerInterface() : nullptr;
}

// EA 0x82B992B8
idEntity* idPresentableVehicle::GetDriverAsEntity() const {
    return GetDriver() != nullptr ? GetDriver()->entity : nullptr;
}

// EA 0x82B99348
idPresentable* idPresentableVehicle::GetGunner() const {
    return occupants[VEHICLE_SEAT_GUNNER];
}

// EA 0x82B99368
idEntity* idPresentableVehicle::GetDriverEntity() {
    return GetDriverAsEntity();
}

// EA 0x82B993C0
void* idPresentableVehicle::GetVisualAsEntity(void* occupant) const {
    return occupant != nullptr ? occupant
        : vehicleServices->EventPointer(*this, "VisualOccupantEntity");
}

// EA 0x82B99428
void* idPresentableVehicle::GetNpcAsEntity(void* occupant) const {
    return occupant != nullptr ? occupant
        : vehicleServices->EventPointer(*this, "NpcOccupantEntity");
}

// EA 0x82B99498
void idPresentableVehicle::SendCurrentWeaponToServer() {
    VehicleEvent(*this, "SendCurrentWeaponToServer");
}

// EA 0x82B99520
int idPresentableVehicle::GetNumActiveOccupants() const {
    int count = 0;
    for (idPresentable* occupant : occupants) {
        if (occupant != nullptr) ++count;
    }
    return count;
}

// EA 0x82B995B8
bool idPresentableVehicle::IsLocallyControlled() const {
    return vehicleServices->EventBool(*this, "IsLocallyControlled",
        IsLocallyControlledByPlayer());
}

// EA 0x82B99618
bool idPresentableVehicle::IsLocallyControlledByPlayer() const {
    return GetPlayerDriver() != nullptr
        && vehicleServices->EventBool(*this,
            "IsLocalPlayerDriver", false);
}

// EA 0x82B99680
bool idPresentableVehicle::IsRemotelyControlledByPlayer() const {
    return GetPlayerDriver() != nullptr && !IsLocallyControlledByPlayer();
}

// EA 0x82B996E8
void idPresentableVehicle::ClientHandleDamageInfo(
        vehicleDamageInfo_t& damage) {
    healthSerialized = damage.endHealth;
    VehicleEvent(*this, damage.predicted
        ? "ClientPredictedDamage" : "ClientDamage");
}

// EA 0x82B99880
void* idPresentableVehicle::GetClientFire() {
    return vehicleServices->EventPointer(*this, "ClientFire");
}

// EA 0x82B998D8
bool idPresentableVehicle::GetPassengerView(idVec3& outOrigin,
        idMat3& outAxis, float& outFov) {
    outOrigin = driverViewOrigin;
    outAxis = driverViewAxis;
    outFov = driverViewFov;
    return vehicleServices->EventBool(*this, "GetPassengerView",
        GetGunner() != nullptr);
}

// EA 0x82B99BB8
bool idPresentableVehicle::GetFPSDriverView(idVec3& outOrigin,
        idMat3& outAxis, float& outFov) {
    GetViewOriginAndAxis(outOrigin, outAxis);
    outFov = driverViewFov;
    return vehicleServices->EventBool(*this, "GetFPSDriverView",
        GetPlayerDriver() != nullptr);
}

// EA 0x82B9A468
void idPresentableVehicle::UpdateWhiplash() {
    VehicleEvent(*this, "UpdateWhiplash");
}

// EA 0x82B9AA28
idPresentable* idPresentableVehicle::ThrowAttachedItem(
        const idDeclInventory* declaration) {
    const auto found = std::find(detachableItems.begin(),
        detachableItems.end(), declaration);
    if (found == detachableItems.end()) return nullptr;
    detachableItems.erase(found);
    VehicleEvent(*this, "ThrowAttachedItem");
    return static_cast<idPresentable*>(
        vehicleServices->EventPointer(*this, "ThrownAttachedPresentable"));
}

// EA 0x82B9AF28
void idPresentableVehicle::SetLockScrambling(bool scrambling) {
    isLockScrambling = scrambling;
    VehicleEvent(*this, "SetLockScrambling");
}

// EA 0x82B9B040
void idPresentableVehicle::TriggerBoostExtender() {
    externalBoostDuration = vehicleServices->EventInt(*this,
        "BoostExtenderDuration", externalBoostDuration);
    AddBoost(1.0f);
    VehicleEvent(*this, "TriggerBoostExtender");
}

// EA 0x82B9B1B8
void idPresentableVehicle::SetSmashActive(bool active) {
    isSmashActive = active;
    predictSmashActiveFrame = active
        ? vehicleServices->EventInt(*this, "SmashFrame", 0) : 0;
    if (!active) smashTimeout = 0;
    VehicleEvent(*this, "SetSmashActive");
}

// EA 0x82B9B2C0
idPresentable* idPresentableVehicle::GetLockedTarget() {
    return lockedTarget;
}

// EA 0x82B9B748
void idPresentableVehicle::SerializeWeaponList(idSerializer& serializer) {
    int count = static_cast<int>(weapons.size());
    serializer.SerializePacked(count);
    if (serializer.IsReading()) weapons.resize(std::max(0, count), nullptr);
    vehicleServices->SerializeExtra(*this, serializer,
        "SerializeWeaponList");
}

// EA 0x82B9B8F8
void idPresentableVehicle::SerializePredictionState(
        idSerializer& serializer) {
    SerializePredictionOnly(serializer);
    serializer.Serialize(driverViewOrigin);
    serializer.SerializeQ(driverViewAxis);
    serializer.Serialize(driverViewFov);
    serializer.Serialize(currentWeaponGroup);
    vehicleServices->SerializeExtra(*this, serializer,
        "SerializePredictionState");
}

// EA 0x82B9BA98
bool idPresentableVehicle::ServerOverridingPosition() const {
    return serverOverridePositionTime > 0
        || vehicleServices->EventBool(*this,
            "ServerOverridingPosition", false);
}

// EA 0x82B9BB58
void idPresentableVehicle::UpdateTireTracks() {
    VehicleEvent(*this, "UpdateTireTracks");
}

// EA 0x82B9BF30
void* idPresentableVehicle::GetFXMgrForActiveWeapon() {
    return vehicleServices->EventPointer(*this, "ActiveWeaponFXManager");
}

// EA 0x82B9BF98
void idPresentableVehicle::UpdateRemoteClientSimulation(
        const idVec3& newOrigin, const idMat3& newAxis) {
    origin = newOrigin;
    axis = newAxis;
    currentApproxLinearVelocity = vehicleServices->EventVector(*this,
        "RemoteLinearVelocity", currentApproxLinearVelocity);
    VehicleEvent(*this, "UpdateRemoteClientSimulation");
}

// EA 0x82B9C578
void idPresentableVehicle::GetDriverViewInternalTest(idVec3& outOrigin,
        idMat3& outAxis, float& outFov) {
    GetSimpleCameraInternal(outOrigin, outAxis, outFov);
    VehicleEvent(*this, "GetDriverViewInternalTest");
}

// EA 0x82B9D690
void idPresentableVehicle::AddQuickItemThink(idVehicleQuickItem* item) {
    if (item != nullptr && std::find(quickItems.begin(), quickItems.end(), item)
            == quickItems.end()) quickItems.push_back(item);
}

// EA 0x82B9D6D8
void idPresentableVehicle::UpdateExhaust() {
    if (engineRunning) VehicleEvent(*this, "UpdateExhaust");
}

// EA 0x82B9D7E8
int idPresentableVehicle::StartSoundShader_Predicted(
        soundChannel_t channel, const idSoundShader* shader, int flags) {
    VehicleEvent(*this, "StartSoundShader_Predicted");
    return idPresentable::StartSoundShader(channel, shader, flags, 0);
}

// EA 0x82B9D890
void idPresentableVehicle::StopSound_Predicted(soundChannel_t channel) {
    StopSound(channel, 0);
    VehicleEvent(*this, "StopSound_Predicted");
}

// EA 0x82B9D920
int idPresentableVehicle::GetPeerIndex() {
    return vehicleServices->EventInt(*this, "PeerIndex", -1);
}

// EA 0x82B9D978
idVehicleWeapon* idPresentableVehicle::AddWeaponToVehicle(
        const idDeclWeapon*) {
    idVehicleWeapon* weapon = static_cast<idVehicleWeapon*>(
        vehicleServices->EventPointer(*this, "CreateVehicleWeapon"));
    if (weapon != nullptr) weapons.push_back(weapon);
    return weapon;
}

// EA 0x82B9DB00
void idPresentableVehicle::SetCurrentWeaponGroup(int group) {
    if (group >= 0 && group < static_cast<int>(weapons.size())) {
        clientPendingWeaponGroup = group;
        currentWeaponGroup = group;
        VehicleEvent(*this, "SetCurrentWeaponGroup");
    }
}

// EA 0x82B9DBE0
bool idPresentableVehicle::Draw(idPresentablePlayer*) {
    VehicleEvent(*this, "Draw");
    return vehicleServices->EventBool(*this, "DrawResult", true);
}

// EA 0x82B9F080
void idPresentableVehicle::ThrowAllDetachableItems() {
    while (!detachableItems.empty()) {
        ThrowAttachedItem(detachableItems.back());
    }
}

// EA 0x82B9F148
void idPresentableVehicle::ActivateWeaponGroup(bool active) {
    weaponGroupActive = active;
    VehicleEvent(*this, "ActivateWeaponGroup");
}

// EA 0x82B9F370
void idPresentableVehicle::StartMannedWeaponChange() {
    VehicleEvent(*this, "StartMannedWeaponChange");
}

// EA 0x82B9F610
void idPresentableVehicle::ActivateCrosshair() {
    crosshairActive = true;
    VehicleEvent(*this, "ActivateCrosshair");
}

// EA 0x82B9FAF8
bool idPresentableVehicle::IsTargetLockable(const idDeclAmmo* ammo) const {
    return !IsDead() && !isLockScrambling
        && (idPresentableAnimatedEntity::IsTargetLockable(ammo)
            || vehicleServices->EventBool(*this,
                "VehicleTargetLockable", false));
}

// EA 0x82B9FB90
void idPresentableVehicle::UpdateCrosshair(vehicleSeat_t,
        const usercmd_t&, const usercmd_t&) {
    if (crosshairActive) VehicleEvent(*this, "UpdateCrosshair");
}

// EA 0x82B9FFC8
void idPresentableVehicle::ClientHitScanHit(int, int, int,
        const idDeclWeapon*, const idDeclProjectile*, int) {
    VehicleEvent(*this, "ClientHitScanHit");
}

// EA 0x82BA0550
void idPresentableVehicle::RecordClientFire(const idWeapon*,
        const idDeclProjectile*, const idFireParms&,
        const idTestFireResults&, const idFinishFireResults&) {
    VehicleEvent(*this, "RecordClientFire");
}

// EA 0x82BA0A48
void idPresentableVehicle::EvaluateClientWeaponSwitch() {
    if (clientPendingWeaponGroup >= 0
            && allowWeaponChange) SetCurrentWeapon();
}

// EA 0x82BA0B10
void idPresentableVehicle::PerformClientFire(idVehicleWeapon*, int,
        const idVec3&, const idMat3&, idPresentable*) {
    VehicleEvent(*this, "PerformClientFire");
}

// EA 0x82BA10B0
void idPresentableVehicle::StartFxOnAttachments(fxCondition_t) {
    VehicleEvent(*this, "StartFxOnAttachments");
}

// EA 0x82BA1160
void idPresentableVehicle::StopFxOnAttachments(fxCondition_t) {
    VehicleEvent(*this, "StopFxOnAttachments");
}

// EA 0x82BA1200
void idPresentableVehicle::TriggerSmashActive() {
    smashTimeout = vehicleServices->EventInt(*this,
        "SmashDuration", 1000);
    SetSmashActive(true);
}

// EA 0x82BA1708
idPresentableVehicle::~idPresentableVehicle() {
    VehicleEvent(*this, "Destroy");
    weapons.clear();
    quickItems.clear();
    detachableItems.clear();
    physicsObj = nullptr;
}

// EA 0x82BA1D38
bool idPresentableVehicle::Init(idRenderModel* renderModel,
        idAnimator_VehicleCar* vehicleAnimator,
        const idDeclVehicleProps* properties, idPhysicsCallbacks* callbacks) {
    animator = vehicleAnimator;
    vehicleProps = properties;
    SetRenderModel(renderModel, true);
    const bool body = InitVehicleBody();
    const bool physics = InitVehiclePhysics(callbacks);
    InitImpactMgr();
    ResetDriverView();
    return body && physics;
}

// EA 0x82BA2620
void idPresentableVehicle::SerializeOccupants(idSerializer& serializer) {
    for (int seat = 0; seat < 2; ++seat) {
        bool occupied = occupants[seat] != nullptr;
        serializer.Serialize(occupied);
        if (serializer.IsReading() && !occupied) occupants[seat] = nullptr;
    }
    vehicleServices->SerializeExtra(*this, serializer,
        "SerializeOccupants");
}

// EA 0x82BA26B8
void idPresentableVehicle::UpdateRemoteSimulationParms_Server() {
    currentApproxLinearVelocity = vehicleServices->EventVector(*this,
        "ServerLinearVelocity", currentApproxLinearVelocity);
    VehicleEvent(*this, "UpdateRemoteSimulationParms_Server");
}

// EA 0x82BA2878
void idPresentableVehicle::UpdateAnimator() {
    VehicleEvent(*this, "UpdateAnimator");
}

// EA 0x82BA2F98
void idPresentableVehicle::Respawn() {
    SetDefaults();
    healthSerialized = maxHealthSerialized;
    Show();
    VehicleEvent(*this, "Respawn");
}

// EA 0x82BA3280
void idPresentableVehicle::UpdateDriverView() {
    GetViewOriginAndAxis(driverViewOrigin, driverViewAxis);
    VehicleEvent(*this, "UpdateDriverView");
}

// EA 0x82BA36A8
const void* idPresentableVehicle::GetSoundDef() const {
    return vehicleServices->EventPointer(*this, "VehicleSoundDef");
}

// EA 0x82BA3758
void idPresentableVehicle::NextWeapon(bool force) {
    if (weapons.empty()) return;
    int candidate = currentWeaponGroup;
    for (std::size_t attempt = 0; attempt < weapons.size(); ++attempt) {
        candidate = (candidate + 1) % static_cast<int>(weapons.size());
        if (force || WeaponGroupHasAmmo(candidate)) {
            SetCurrentWeaponGroup(candidate);
            return;
        }
    }
}

// EA 0x82BA3AE8
void idPresentableVehicle::PrevWeapon(bool force) {
    if (weapons.empty()) return;
    int candidate = currentWeaponGroup < 0 ? 0 : currentWeaponGroup;
    for (std::size_t attempt = 0; attempt < weapons.size(); ++attempt) {
        candidate = (candidate + static_cast<int>(weapons.size()) - 1)
            % static_cast<int>(weapons.size());
        if (force || WeaponGroupHasAmmo(candidate)) {
            SetCurrentWeaponGroup(candidate);
            return;
        }
    }
}

// EA 0x82BA3C90
void idPresentableVehicle::SerializeWeaponChange(idSerializer& serializer) {
    serializer.Serialize(currentWeaponGroup);
    serializer.Serialize(clientPendingWeaponGroup);
    serializer.Serialize(allowWeaponChange);
    if (serializer.IsReading() && currentWeaponGroup
            >= static_cast<int>(weapons.size())) currentWeaponGroup = -1;
}

// EA 0x82BA3E28
void idPresentableVehicle::UpdateWeapons() {
    EvaluateClientWeaponSwitch();
    VehicleEvent(*this, "UpdateWeapons");
}

// EA 0x82BA52E8
void idPresentableVehicle::CheckImpulse_Local(vehicleSeat_t,
        usercmd_t&, usercmd_t&) {
    VehicleEvent(*this, "CheckImpulse_Local");
}

// EA 0x82BA5750
void idPresentableVehicle::ClientHitScanHit_ClientFire(int,
        const idDeclWeapon*, int) {
    VehicleEvent(*this, "ClientHitScanHit_ClientFire");
}

// EA 0x82BA5A60
void idPresentableVehicle::EvaluateClientFire() {
    if (weaponGroupActive && !IsDead()) VehicleEvent(*this,
        "EvaluateClientFire");
}

// EA 0x82BA5ED8
void idPresentableVehicle::ThrowDebris(const idVec3&, const idVec3&,
        const idVec3&, int count) {
    if (count > 0) VehicleEvent(*this, "ThrowDebris");
}

// EA 0x82BA6398
void idPresentableVehicle::SetDefaults() {
    enableVehicleControls = true;
    engineRunning = false;
    accelerating = false;
    reversing = false;
    boosting = false;
    canAccelerate = true;
    braking = false;
    handBraking = false;
    engineDisabled = false;
    boostDisabled = false;
    hasBoosted = false;
    hasQuad = false;
    allowWeaponChange = true;
    hasInfiniteAmmoSerialized = false;
    isLockScrambling = false;
    isSmashActive = false;
    crosshairActive = false;
    weaponGroupActive = false;
    pushCrosshairLocked = false;
    currentThrottle = 0.0f;
    currentMPH = 0.0f;
    currentApproxMPH = 0.0f;
    maxSpeed = vehicleServices->EventFloat(*this, "DefaultMaxSpeed", 100.0f);
    currentMaxSpeed = maxSpeed;
    currentMaxReverseSpeed = maxSpeed * 0.5f;
    currentSteerAngle = 0.0f;
    boostPower = 1.0f;
    boostDuration = vehicleServices->EventFloat(*this,
        "DefaultBoostDuration", 1000.0f);
    boostScalePercent = 0.0f;
    megaBoostAcceleration = 0.0f;
    if (maxHealthSerialized <= 0.0f) {
        maxHealthSerialized = vehicleServices->EventFloat(*this,
            "DefaultMaxHealth", 100.0f);
    }
    healthSerialized = maxHealthSerialized;
    megaBoostTime = 0;
    boostStartTime = 0;
    externalBoostDuration = 0;
    numWheelsOnGround = 0;
    timeInAir = 0;
    currentWeaponGroup = -1;
    clientPendingWeaponGroup = -1;
    forceBoostFxTime = 0;
    EMPTimeout = 0;
    numLockedProjectiles = 0;
    smashTimeout = 0;
    predictSmashActiveFrame = 0;
    serverOverridePositionTime = 0;
    curQuickItem = -1;
    curQuickItemSlot = -1;
    damageHistoryIndex = 0;
    damageHistoryLastSerialize = 0;
    reverseBoostState = RBS_NONE;
    autoRollState = AUTOROLL_NONE;
    currentApproxLinearVelocity.Zero();
    driverViewOrigin.Zero();
    driverViewAxis = idMat3(1.0f);
    driverViewFov = 90.0f;
    driverViewAngles = idAngles(0.0f, 0.0f, 0.0f);
    occupants[0] = occupants[1] = nullptr;
    lockedTarget = nullptr;
    quadOn.count = quadOn.lastCount = 0;
    quadOff.count = quadOff.lastCount = 0;
    resetBoost.count = resetBoost.lastCount = 0;
    for (vehicleDamageInfo_t& damage : damageHistory) {
        damage = vehicleDamageInfo_t();
    }
}

// EA 0x82BA6BB0
void idPresentableVehicle::SerializeDetachableItems(
        idSerializer& serializer) {
    int count = static_cast<int>(detachableItems.size());
    serializer.SerializePacked(count);
    if (serializer.IsReading()) {
        detachableItems.resize(std::max(0, count), nullptr);
    }
    vehicleServices->SerializeExtra(*this, serializer,
        "SerializeDetachableItems");
}

// EA 0x82BA6DE8
void idPresentableVehicle::UpdateSounds() {
    if (engineDisabled && engineRunning) KillEngineSounds();
    VehicleEvent(*this, "UpdateSounds");
}

// EA 0x82BA9F48
void idPresentableVehicle::UpdateEffects() {
    UpdateExhaust();
    UpdateWheelSkid();
    UpdateTireTracks();
    UpdateSmash();
    VehicleEvent(*this, "UpdateEffects");
}

// EA 0x82BAB328
void idPresentableVehicle::UpdateSteerAngle(float fraction) {
    const float target = UseSteerControl()
        ? GetMaxSteerAngle(currentMPH) * currentThrottle : 0.0f;
    currentSteerAngle += (target - currentSteerAngle)
        * ClampVehicle(fraction, 0.0f, 1.0f);
}

// EA 0x82BAB528
void idPresentableVehicle::UseQuickItem(idVehicleQuickItem* item) {
    if (item == nullptr) return;
    VehicleEvent(*this, "UseQuickItemObject");
    RemoveQuickItemThink(item);
}

// EA 0x82BAB7A0
vehicleCollideResult_t idPresentableVehicle::HandleCollisionClientServer(
        idPresentable*, int, trace_t&, const idVec3&) {
    VehicleEvent(*this, "HandleCollisionClientServer");
    return static_cast<vehicleCollideResult_t>(vehicleServices->EventInt(
        *this, "CollisionResult", VEHICLE_COLLIDE));
}

// EA 0x82BAD278
void idPresentableVehicle::AddDetachableItem(const void* detachable,
        bool attached) {
    const idDeclInventory* declaration =
        static_cast<const idDeclInventory*>(detachable);
    if (attached && declaration != nullptr
            && std::find(detachableItems.begin(), detachableItems.end(),
                declaration) == detachableItems.end()) {
        detachableItems.push_back(declaration);
    }
    VehicleEvent(*this, "AddDetachableItem");
}

// EA 0x82BAD320
idPresentableVehicle::idPresentableVehicle(idVehicle* vehicle,
        idRenderModel* renderModel, idAnimStack* stack,
        idAnimator_VehicleCar* vehicleAnimator,
        const idDeclVehicleProps* properties, idPhysicsCallbacks* callbacks,
        int newEntityNumber)
    : idPresentableAnimatedEntity(reinterpret_cast<idEntity*>(vehicle),
        renderModel, stack, newEntityNumber, nullptr, true),
      animator(nullptr), vehicleProps(nullptr), physicsObj(nullptr),
      clientPhysicsCB(nullptr), physicsCallbacks(this) {
    maxHealthSerialized = 0.0f;
    SetDefaults();
    Init(renderModel, vehicleAnimator, properties, callbacks);
}

// EA 0x82BADC58
void idPresentableVehicle::Serialize(idSerializer& serializer) {
    idPresentableAnimatedEntity::Serialize(serializer);
    SerializePredictionState(serializer);
    SerializeNonPredictionState(serializer);
    SerializeOccupants(serializer);
    SerializeWeaponList(serializer);
    SerializeWeaponChange(serializer);
    SerializeDetachableItems(serializer);
    quadOn.Serialize(serializer);
    quadOff.Serialize(serializer);
    resetBoost.Serialize(serializer);
    serializer.Serialize(isLockScrambling);
    serializer.Serialize(isSmashActive);
    serializer.Serialize(smashTimeout);
    vehicleServices->SerializeExtra(*this, serializer, "Serialize");
}

// EA 0x82BAE7C8
void idPresentableVehicle::ServerClientThink(int) {
    UpdateAnimator();
    UpdateWeapons();
    UpdateSounds();
    UpdateEffects();
    QuickItemThink();
    VehicleEvent(*this, "ServerClientThink");
}

// EA 0x82BAF170
void idPresentableVehicle::UseQuickItem() {
    if (curQuickItem >= 0 && curQuickItem < static_cast<int>(quickItems.size())) {
        UseQuickItem(quickItems[curQuickItem]);
    }
}

// EA 0x82BAF268
vehicleCollideResult_t idPresentableVehicle::Collide(int, trace_t& trace,
        const idVec3& velocity) {
    return HandleCollisionClientServer(nullptr, 0, trace, velocity);
}

// EA 0x82BAF610
vehicleCollideResult_t idPresentableVehiclePhysicsCB::Collide(
        int entityNumber, trace_t& trace, const idVec3& velocity) {
    return vehicle != nullptr ? vehicle->Collide(entityNumber, trace, velocity)
        : VEHICLE_COLLIDE_NONE;
}

// EA 0x82BAF700
void idPresentableVehicle::ClientThink(int currentTime, float fraction,
        bool predict) {
    idPresentableAnimatedEntity::ClientThink(currentTime, fraction, predict);
    ServerClientThink(currentTime);
    UpdateDriverView();
    if (!IsLocallyControlled()) UpdateRemoteClientSimulation(origin, axis);
}

// EA 0x82BAF9C0
void idPresentableVehicle::ServerThink(int currentTime) {
    ServerClientThink(currentTime);
    UpdateRemoteSimulationParms_Server();
    RunPhysics();
}

// EA 0x82BAFC60
bool idPresentableVehicle::SelectQuickItem(int itemIndex) {
    if (itemIndex < 0
            || itemIndex >= static_cast<int>(quickItems.size())) return false;
    SetCurQuickItem(itemIndex);
    return true;
}

// EA 0x82BAFD78
void idPresentableVehicle::UpdateQuickUse(usercmd_t&, usercmd_t&,
        int, int) {
    VehicleEvent(*this, "UpdateQuickUse");
}

// EA 0x82BB0028
void idPresentableVehicle::PostSerializeRead(bool firstClientFrame) {
    idPresentableAnimatedEntity::PostSerializeRead(firstClientFrame);
    if (quadOn.count != quadOn.lastCount) {
        quadOn.lastCount = quadOn.count;
        hasQuad = true;
    }
    if (quadOff.count != quadOff.lastCount) {
        quadOff.lastCount = quadOff.count;
        hasQuad = false;
    }
    if (resetBoost.count != resetBoost.lastCount) {
        resetBoost.lastCount = resetBoost.count;
        boostPower = 1.0f;
    }
    VehicleEvent(*this, "PostSerializeRead");
}

// EA 0x82BB0260
void idPresentableVehicle::DriveControl_Local(idPresentablePlayer*,
        usercmd_t& oldCommand, usercmd_t& command, int, int, bool) {
    if (!enableVehicleControls || engineDisabled) return;
    CheckImpulse_Local(VEHICLE_SEAT_DRIVER, oldCommand, command);
    UpdateHorn(oldCommand, command);
    UpdateDriverViewAngles(oldCommand, command);
    VehicleEvent(*this, "DriveControl_Local");
}

// EA 0x82BB1600
void idPresentableVehicle::DriveControl(idPresentablePlayer* player) {
    if (player != nullptr && enableVehicleControls) {
        VehicleEvent(*this, "DriveControl");
    }
}

// EA 0x82BB1738
void idPresentableVehicle::ClientPredict(int, float fraction) {
    UpdateSteerAngle(fraction);
    ArcadeSteering();
    AutoRollOver();
    PitchRollStabilize();
    RunPhysics();
    EvaluateClientFire();
    EvaluateClientWeaponSwitch();
}
