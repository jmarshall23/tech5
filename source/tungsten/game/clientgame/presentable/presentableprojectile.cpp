#include "presentableprojectile.h"

#include <algorithm>
#include <cmath>

namespace {

idPresentableProjectileServices defaultProjectileServices;
idPresentableProjectileServices* projectileServices =
    &defaultProjectileServices;

idMat3 IdentityMatrix() {
    return idMat3(1.0f);
}

float ClampFloat(float value, float minimum, float maximum) {
    return std::max(minimum, std::min(maximum, value));
}

idMat3 BlendMatrix(const idMat3& from, const idMat3& to, float fraction) {
    idMat3 result;
    fraction = ClampFloat(fraction, 0.0f, 1.0f);
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            result[row][column] = from[row][column]
                + (to[row][column] - from[row][column]) * fraction;
        }
    }
    result.OrthoNormalizeSelf();
    return result;
}

idVec3 Normalized(idVec3 value) {
    value.NormalizeFast();
    return value;
}

} // namespace

void Tungsten_SetPresentableProjectileServices(
        idPresentableProjectileServices* services) {
    projectileServices = services != nullptr
        ? services : &defaultProjectileServices;
}

// EA 0x82B8AE50
idPresentableProjectile::~idPresentableProjectile() = default;

// EA 0x82B8AE68
idPresentableProjectile_Rocket::~idPresentableProjectile_Rocket() {
    if (ownsProjectilePhysics && projectilePhysics != nullptr) {
        projectileServices->DestroyRigidBody(projectilePhysics);
        projectilePhysics = nullptr;
        ownsProjectilePhysics = false;
    }
}

// EA 0x82B8AEF8
idPresentableProjectile_Grenade::~idPresentableProjectile_Grenade() {
    if (ownsProjectilePhysics && projectilePhysics != nullptr) {
        projectileServices->DestroyRigidBody(projectilePhysics);
        projectilePhysics = nullptr;
        ownsProjectilePhysics = false;
    }
}

// EA 0x82B8B000
void idPresentableProjectile::SetDefaults() {
    projectileDecl = nullptr;
    launchTime = 0;
    state = ACTIVE;
    projectilePhysics = nullptr;
    attackerSpawnId = 0;
    playingWarningSound = false;
    launchOrigin.Zero();
    launchAxis = IdentityMatrix();
    launched = false;
    hasQuad = false;
    smoothOrigin.Zero();
    smoothAxis = IdentityMatrix();
    initialFireAxis = IdentityMatrix();
    ownsProjectilePhysics = false;
}

// EA 0x82B8B100
void idPresentableProjectile::UpdateFX(const idVec3&, const idMat3&,
        float, float) {
    const idVec3 fxOrigin = origin + smoothOrigin;
    const idMat3 fxAxis = axis * smoothAxis;
    projectileServices->UpdateEffects(*this, fxOrigin, fxAxis,
        projectileServices->GetScaledGameTime(),
        projectileServices->GetScaledFrameTime(),
        projectileServices->GetFrameNumber());
}

// EA 0x82B8B1D0
void idPresentableProjectile::GetWorldTransform(idVec3& outOrigin,
        idMat3& outAxis) {
    GetWorldTransformInternal(origin + smoothOrigin, axis * smoothAxis,
        outOrigin, outAxis);
}

// EA 0x82B8B248
void idPresentableProjectile::InternalClientLaunch(idPresentable* attacker,
        const idVec3& start, const idMat3& fireAxis,
        const idProjectileTarget& target, float initialSpeed,
        int startTime) {
    if (projectileServices->IsServer()) {
        projectileServices->ServerLaunch(*this, attacker, start, fireAxis,
            target, initialSpeed, startTime);
    }
}

// EA 0x82B8B2D8
void idPresentableProjectile::SetupClientProjectilePhysics(idPhysics& physics,
        const idClipModelInfo& information, const idTraceModel* traceModel,
        float overrideCollision, idPhysicsCallbacks* callbacks) {
    projectilePhysics = &physics;
    projectileServices->SetupPhysics(*this, physics, information, traceModel,
        overrideCollision, callbacks, 8462469);
}

// EA 0x82B8B6E0
bool idPresentableProjectile::IsDead() const {
    return state == EXPLODED;
}

// EA 0x82B8B6F8
bool idPresentableProjectile::IsActive() const {
    return state == ACTIVE;
}

// EA 0x82B8B710
void idPresentableProjectile::DecayOriginAndAxisSmoothing() {
    const float distance = smoothOrigin.Length();
    if (distance <= 0.01f) {
        smoothOrigin.Zero();
    } else {
        const float decay = std::min(
            projectileServices->GetErrorSmoothingDecay() * distance,
            projectileServices->GetErrorSmoothingMaxDecay());
        smoothOrigin = smoothOrigin
            - Normalized(smoothOrigin) * std::min(decay, distance);
    }
    smoothAxis = BlendMatrix(smoothAxis, IdentityMatrix(),
        projectileServices->GetErrorSmoothingDecay());
}

// EA 0x82B8B8E0
void idPresentableProjectile::SmoothFromOriginAndAxis(
        const idVec3& oldOrigin, const idMat3& oldAxis) {
    smoothOrigin = oldOrigin - origin;
    smoothAxis = axis.Transpose() * oldAxis;
}

// EA 0x82B8BA08
idVec3 idPresentableProjectile_Rocket::GetInitialDir(
        const idMat3& fireAxis) const {
    return fireAxis[0];
}

// EA 0x82B8BA90
idVec3 idPresentableProjectile_Homing::GetInitialDir(
        const idMat3& fireAxis) const {
    return Normalized(projectileServices->GetHomingInitialDirection(
        *this, fireAxis));
}

// EA 0x82B8BBC8
float idPresentableProjectile_Grenade::GetSpeedForFireAxis(
        const idPresentable* attacker, const idMat3& fireAxis) const {
    idVec3 gravity = projectileServices->GetAttackerGravityNormal(attacker);
    if (gravity.NormalizeFast() == 0.0f) {
        gravity.Set(0.0f, 0.0f, 1.0f);
    }
    const idVec3 forward = Normalized(fireAxis[0]);
    const idVec3 projected = forward - gravity * forward.Dot(gravity);
    const float projectedDot = ClampFloat(forward.Dot(projected), -1.0f, 1.0f);
    float angle;
    constexpr float radiansToDegrees = 57.29577951308232f;
    if (forward.Dot(gravity) <= 0.0f) {
        angle = ClampFloat(std::acos(projectedDot) * radiansToDegrees
            + 90.0f, 90.0f, 135.0f);
    } else {
        angle = std::acos(ClampFloat(1.0f - projectedDot, -1.0f, 1.0f))
            * radiansToDegrees;
    }

    const idProjectileDeclParameters parameters =
        projectileServices->GetDeclarationParameters(projectileDecl);
    const float range = parameters.grenadeMaxSpeed
        - parameters.grenadeMinSpeed;
    const float lowSegment = range * 0.33f;
    if (angle >= 75.0f) {
        return parameters.grenadeMinSpeed + lowSegment
            + ((angle - 75.0f) / 60.0f) * (range - lowSegment);
    }
    return parameters.grenadeMinSpeed
        + (angle / 75.0f) * lowSegment;
}

// EA 0x82B8BD80
void idPresentableProjectile::SmoothFromLaunchOriginAxis() {
    SmoothFromOriginAndAxis(launchOrigin, launchAxis);
}

// EA 0x82B8BD90
void idPresentableProjectile::ClientThink(int currentTime, float fraction,
        bool predict) {
    idPresentableAnimatedEntity::ClientThink(currentTime, fraction, predict);
    DecayOriginAndAxisSmoothing();
    if (index >= 0x2000) {
        const int age = projectileServices->GetScaledGameTime() - launchTime;
        if (age > 1000
                * projectileServices->GetPredictedProjectileExpireSeconds()) {
            projectileServices->Print(
                "Predicted projectile expired before server version spawned\n");
            queueForDelete = true;
        }
        UpdateFX(origin, axis, 1.0f, 0.0f);
    }
}

// EA 0x82B8BF18
bool idPresentableProjectile::AdjustStartToCollision(
        idPresentable* attacker, idVec3& start, const idVec3& direction) {
    if (attacker == nullptr) {
        return false;
    }
    return projectileServices->AdjustStartToCollision(*this, attacker,
        start, direction);
}

// EA 0x82B8C528
void idPresentableProjectile_Rocket::InternalClientLaunch(
        idPresentable*, const idVec3&, const idMat3& fireAxis,
        const idProjectileTarget&, float initialSpeed, int) {
    const idProjectileDeclParameters parameters =
        projectileServices->GetDeclarationParameters(projectileDecl);
    calcThrustDelay = parameters.thrustDelay;
    if (parameters.thrustDelayVariance > 0) {
        calcThrustDelay += projectileServices->RandomInt(
            parameters.thrustDelayVariance);
    }
    idVec3 direction = GetInitialDir(fireAxis);
    direction.NormalizeFast();
    const float speed = initialSpeed == -1.0f
        ? parameters.speed : initialSpeed;
    initialFireAxis = fireAxis;
    goalSpeed = parameters.speed;
    projectileServices->SetLinearVelocity(projectilePhysics,
        direction * speed);
    projectileServices->StartBreakAwaySound(*this);
}

void idPresentableProjectile::UpdatePredictedPhysics() {
    if (index < 0x2000) {
        return;
    }
    if (!projectileServices->DontMoveClientProjectiles()) {
        projectileServices->EvaluatePhysics(projectilePhysics,
            projectileServices->GetScaledFrameTime(),
            projectileServices->GetScaledGameTime());
    }
    projectileServices->GetPhysicsTransform(projectilePhysics, origin, axis);
    projectileServices->Present(*this);
}

// EA 0x82B8C758
void idPresentableProjectile_Grenade::ClientThink(int currentTime,
        float fraction, bool predict) {
    idPresentableProjectile::ClientThink(currentTime, fraction, predict);
    UpdatePredictedPhysics();
}

// EA 0x82B8C890
void idPresentableProjectile_Homing::ClientThink(int currentTime,
        float fraction, bool predict) {
    idPresentableProjectile::ClientThink(currentTime, fraction, predict);
    UpdatePredictedPhysics();
}

// EA 0x82B8C898
void idPresentableProjectile_Grenade::InternalClientLaunch(
        idPresentable* attacker, const idVec3& start,
        const idMat3& fireAxis, const idProjectileTarget& target,
        float initialSpeed, int startTime) {
    const float speed = initialSpeed == -1.0f
        ? GetSpeedForFireAxis(attacker, fireAxis) : initialSpeed;
    projectileServices->SetLinearVelocity(projectilePhysics,
        fireAxis[0] * speed);
    if (projectileServices->IsServer()) {
        projectileServices->ServerLaunch(*this, attacker, start, fireAxis,
            target, initialSpeed, startTime);
    }
}

// EA 0x82B8C9A8
void idPresentableProjectile::ClientLaunch(idPresentable* attacker,
        const idVec3& start, const idMat3& fireAxis,
        const idProjectileTarget& target, float initialSpeed,
        int startTime, int launchTimeValue) {
    const idProjectileDeclParameters parameters =
        projectileServices->GetDeclarationParameters(projectileDecl);
    launchTime = launchTimeValue;
    launchOrigin = start;
    launchAxis = fireAxis;
    launched = true;
    attackerSpawnId = attacker != nullptr ? attacker->spawnId : 0;
    state = ACTIVE;
    Show();

    if (attacker != nullptr) {
        projectileServices->SetPhysicsOwner(projectilePhysics,
            attacker->entityNumber);
    }

    idVec3 adjustedStart = start;
    bool adjusted = false;
    const bool mayAdjust = !projectileServices->IsMultiplayer()
        || !projectileServices->IsClient();
    if (attacker != nullptr && parameters.adjustStartForCollision
            && mayAdjust) {
        adjusted = AdjustStartToCollision(attacker, adjustedStart,
            fireAxis[0]);
    }
    projectileServices->SetPhysicsTransform(projectilePhysics,
        adjustedStart, fireAxis);
    InternalClientLaunch(attacker, start, fireAxis, target, initialSpeed,
        startTime);
    if (parameters.inheritParentSpeed && projectileServices->IsServer()) {
        projectileServices->InheritParentSpeed(*this, attacker, fireAxis);
    }
    if (!parameters.grenadeCookable) {
        projectileServices->StartFlySound(*this);
    }
    projectileServices->GetPhysicsTransform(projectilePhysics, origin, axis);
    projectileServices->StartLaunchEffects(*this, launchTime);
    hideDuringFirstSSInterval = false;
    if (adjusted) {
        projectileServices->ExplodeAfterAdjustedLaunch(*this);
    }
}

// EA 0x82B8CE68
void idPresentableProjectile_Homing::InternalClientLaunch(
        idPresentable* attacker, const idVec3& start,
        const idMat3& fireAxis, const idProjectileTarget& newTarget,
        float initialSpeed, int startTime) {
    idPresentableProjectile_Rocket::InternalClientLaunch(attacker, start,
        fireAxis, newTarget, initialSpeed, startTime);
    if (projectileServices->IsServer()
            && newTarget.type == TARGET_PRESENTABLE
            && newTarget.presentableSpawnId != 0) {
        projectileServices->NotifyHomingTarget(*this,
            newTarget.presentableSpawnId, true);
    }
    const idProjectileDeclParameters parameters =
        projectileServices->GetDeclarationParameters(projectileDecl);
    if (parameters.guidedRPG) {
        homingState = FLYOUT;
    } else if (newTarget.type != TARGET_NONE) {
        homingState = LAUNCHING;
        projectileServices->SetPhysicsGravityToGameGravity(projectilePhysics);
    }
    target = newTarget;
}

// EA 0x82B8CF80
void idPresentableProjectile::Init() {
    if (projectileDecl != nullptr) {
        projectileServices->InitializeEffects(*this, projectileDecl, hasQuad);
        projectileServices->StartSpawnEffects(*this);
    }
    launchTime = projectileServices->GetScaledGameTime();
}

// EA 0x82B8D138
void idPresentableProjectile::Serialize(idSerializer& serializer) {
    idPresentableAnimatedEntity::Serialize(serializer);
    const bool hadDeclaration = projectileDecl != nullptr;
    const bool wasLaunched = launched;
    projectileServices->SerializeDeclaration(serializer, projectileDecl);
    serializer.Serialize(attackerSpawnId);
    serializer.SerializeQ<32768, 17>(launchOrigin);
    serializer.SerializeQ(launchAxis, 15);
    serializer.Serialize(launched);
    serializer.Serialize(hasQuad);
    if (!hadDeclaration && projectileDecl != nullptr) {
        Init();
    }
    if (serializer.IsReading() && !wasLaunched && launched
            && !becameReplicated) {
        origins[0] = launchOrigin;
        axes[0] = launchAxis;
        origin = launchOrigin;
        axis = launchAxis;
        projectileServices->StartFlySound(*this);
    }
    projectileServices->SerializeEffects(*this, serializer);
    int serializedState = static_cast<int>(state);
    serializer.SerializeUMax(serializedState, EXPLODED);
    state = static_cast<projectileState_t>(serializedState);
}

// EA 0x82B8D438
idPresentableProjectile::idPresentableProjectile(idProjectile* projectile,
        idRenderModel* renderModel, idAnimStack* stack)
    : idPresentableAnimatedEntity(reinterpret_cast<idEntity*>(projectile),
        renderModel, stack, ENTITYNUM_NONE, nullptr) {
    SetDefaults();
    projectileDecl = projectileServices->GetEntityDeclaration(projectile);
    Init();
}

// EA 0x82B8D4D0
idPresentableProjectile::idPresentableProjectile(
        const idDeclProjectile* declaration, idRenderModel* renderModel,
        idAnimStack* stack)
    : idPresentableAnimatedEntity(nullptr, renderModel, stack,
        ENTITYNUM_NONE, nullptr) {
    SetDefaults();
    projectileDecl = declaration;
    Init();
}

// EA 0x82B8D568
idPresentableProjectile_Rocket::idPresentableProjectile_Rocket(
        idProjectile_Rocket* projectile, idRenderModel* renderModel,
        idAnimStack* stack)
    : idPresentableProjectile(reinterpret_cast<idProjectile*>(projectile),
        renderModel, stack), calcThrustDelay(0), goalSpeed(0.0f) {
}

// EA 0x82B8D600
idPresentableProjectile_Rocket::idPresentableProjectile_Rocket(
        const idDeclProjectile* declaration, idRenderModel* renderModel,
        idAnimStack* stack)
    : idPresentableProjectile(declaration, renderModel, stack),
      calcThrustDelay(0), goalSpeed(0.0f) {
    projectilePhysics = projectileServices->CreateRigidBody(false);
    ownsProjectilePhysics = projectilePhysics != nullptr;
    if (projectilePhysics != nullptr) {
        idClipModelInfo information;
        information.Clear();
        information.type = idClipModelInfo::CLIPMODEL_BOX;
        information.size.Set(5.0f, 5.0f, 5.0f);
        SetupClientProjectilePhysics(*projectilePhysics, information,
            nullptr, -1.0f, nullptr);
    }
}

// EA 0x82B8D718
idPresentableProjectile_Homing::idPresentableProjectile_Homing(
        idProjectile_Homing* projectile, idRenderModel* renderModel,
        idAnimStack* stack)
    : idPresentableProjectile_Rocket(
        reinterpret_cast<idProjectile_Rocket*>(projectile), renderModel,
        stack), homingState(ACQUIRING), target() {
}

// EA 0x82B8D790
idPresentableProjectile_Homing::idPresentableProjectile_Homing(
        const idDeclProjectile* declaration, idRenderModel* renderModel,
        idAnimStack* stack)
    : idPresentableProjectile_Rocket(declaration, renderModel, stack),
      homingState(ACQUIRING), target() {
}

// EA 0x82B8D810
idPresentableProjectile_Grenade::idPresentableProjectile_Grenade(
        idProjectile_Grenade* projectile, idRenderModel* renderModel,
        idAnimStack* stack)
    : idPresentableProjectile(reinterpret_cast<idProjectile*>(projectile),
        renderModel, stack) {
}

// EA 0x82B8D898
idPresentableProjectile_Grenade::idPresentableProjectile_Grenade(
        const idDeclProjectile* declaration, idRenderModel* renderModel,
        idAnimStack* stack)
    : idPresentableProjectile(declaration, renderModel, stack) {
    projectilePhysics = projectileServices->CreateRigidBody(true);
    ownsProjectilePhysics = projectilePhysics != nullptr;
    if (projectilePhysics != nullptr) {
        idClipModelInfo information;
        information.Clear();
        information.type = idClipModelInfo::CLIPMODEL_BOX;
        information.size.Set(5.0f, 5.0f, 5.0f);
        SetupClientProjectilePhysics(*projectilePhysics, information,
            nullptr, -1.0f, nullptr);
    }
}
