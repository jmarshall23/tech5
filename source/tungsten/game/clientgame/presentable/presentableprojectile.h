#pragma once

#include "presentable.h"

#include <cstdint>

class idAnimStack;
class idDeclProjectile;
class idPhysics;
class idPhysicsCallbacks;
class idProjectile;
class idProjectile_Grenade;
class idProjectile_Homing;
class idProjectile_Rocket;
class idRenderModel;
class idTraceModel;

// Values recovered from game/weapons/projectile.h and the state tests in the
// retail presentable implementation.
#ifndef TUNGSTEN_PROJECTILE_STATE_T
#define TUNGSTEN_PROJECTILE_STATE_T
enum projectileState_t : int {
    COOKING = 0,
    ACTIVE = 1,
    BOUNCING = 2,
    STUCK = 3,
    FADING = 4,
    EXPLODED = 5
};
#endif

enum projectileTargetType_t : int {
    TARGET_NONE = 0,
    TARGET_PRESENTABLE = 1,
    TARGET_POINT = 2
};

struct idProjectileTarget {
    projectileTargetType_t type{TARGET_NONE};
    idVec3 pos{0.0f, 0.0f, 0.0f};
    std::uint32_t presentableSpawnId{0};
};

struct idProjectileDeclParameters {
    float speed{0.0f};
    float grenadeMinSpeed{0.0f};
    float grenadeMaxSpeed{0.0f};
    int thrustDelay{0};
    int thrustDelayVariance{0};
    bool adjustStartForCollision{false};
    bool inheritParentSpeed{false};
    bool grenadeCookable{false};
    bool guidedRPG{false};
};

class idPresentableProjectile;

// The original implementation talks directly to the game physics, FX,
// declaration, sound and entity systems.  Those systems are reconstructed in
// later alphabetical folders, so this seam preserves the recovered control
// flow without inventing partial concrete engine objects here.
class idPresentableProjectileServices {
public:
    virtual ~idPresentableProjectileServices() = default;

    virtual const idDeclProjectile* GetEntityDeclaration(idProjectile*) const {
        return nullptr;
    }
    virtual idProjectileDeclParameters GetDeclarationParameters(
        const idDeclProjectile*) const { return idProjectileDeclParameters(); }
    virtual void SerializeDeclaration(idSerializer&, const idDeclProjectile*&)
        {}

    virtual int GetScaledGameTime() const { return 0; }
    virtual int GetScaledFrameTime() const { return 0; }
    virtual int GetFrameNumber() const { return 0; }
    virtual float GetErrorSmoothingDecay() const { return 0.1f; }
    virtual float GetErrorSmoothingMaxDecay() const { return 16.0f; }
    virtual int GetPredictedProjectileExpireSeconds() const { return 5; }
    virtual bool DontMoveClientProjectiles() const { return false; }
    virtual bool IsServer() const { return false; }
    virtual bool IsClient() const { return true; }
    virtual bool IsMultiplayer() const { return false; }
    virtual int RandomInt(int maximumExclusive) {
        return maximumExclusive > 0 ? 0 : 0;
    }

    virtual idPhysics* CreateRigidBody(bool) { return nullptr; }
    virtual void DestroyRigidBody(idPhysics*) {}
    virtual void SetupPhysics(idPresentableProjectile&, idPhysics&,
        const idClipModelInfo&, const idTraceModel*, float,
        idPhysicsCallbacks*, int) {}
    virtual void SetPhysicsTransform(idPhysics*, const idVec3&,
        const idMat3&) {}
    virtual void GetPhysicsTransform(idPhysics*, idVec3& origin,
        idMat3& axis) const {
        origin.Zero();
        axis = idMat3(1.0f);
    }
    virtual void SetLinearVelocity(idPhysics*, const idVec3&) {}
    virtual void EvaluatePhysics(idPhysics*, int, int) {}
    virtual void SetPhysicsGravityToGameGravity(idPhysics*) {}
    virtual void SetPhysicsOwner(idPhysics*, int) {}

    virtual void InitializeEffects(idPresentableProjectile&,
        const idDeclProjectile*, bool) {}
    virtual void StartSpawnEffects(idPresentableProjectile&) {}
    virtual void UpdateEffects(idPresentableProjectile&, const idVec3&,
        const idMat3&, int, int, int) {}
    virtual void StartLaunchEffects(idPresentableProjectile&, int) {}
    virtual void SerializeEffects(idPresentableProjectile&, idSerializer&) {}
    virtual void StartFlySound(idPresentableProjectile&) {}
    virtual void StartBreakAwaySound(idPresentableProjectile&) {}

    virtual void ServerLaunch(idPresentableProjectile&, idPresentable*,
        const idVec3&, const idMat3&, const idProjectileTarget&, float,
        int) {}
    virtual void InheritParentSpeed(idPresentableProjectile&,
        idPresentable*, const idMat3&) {}
    virtual bool AdjustStartToCollision(idPresentableProjectile&,
        idPresentable*, idVec3&, const idVec3&) { return false; }
    virtual void ExplodeAfterAdjustedLaunch(idPresentableProjectile&) {}
    virtual void NotifyHomingTarget(idPresentableProjectile&,
        std::uint32_t, bool) {}
    virtual idVec3 GetHomingInitialDirection(
        const idPresentableProjectile&, const idMat3& fireAxis) const {
        return fireAxis[0];
    }
    virtual idVec3 GetAttackerGravityNormal(const idPresentable*) const {
        return idVec3(0.0f, 0.0f, 1.0f);
    }
    virtual void Print(const char*) {}
    virtual void Present(idPresentableProjectile&) {}
};

void Tungsten_SetPresentableProjectileServices(
    idPresentableProjectileServices* services);

class idPresentableProjectile_Rocket;
class idPresentableProjectile_Homing;
class idPresentableProjectile_Grenade;

class idPresentableProjectile : public idPresentableAnimatedEntity {
public:
    idPresentableProjectile(idProjectile* entity, idRenderModel* renderModel,
        idAnimStack* animStack);
    idPresentableProjectile(const idDeclProjectile* declaration,
        idRenderModel* renderModel, idAnimStack* animStack);
    ~idPresentableProjectile() override;

    void SetDefaults();
    void UpdateFX(const idVec3& origin, const idMat3& axis,
        float fovScale, float depthHack) override;
    void GetWorldTransform(idVec3& outOrigin, idMat3& outAxis) override;
    virtual void InternalClientLaunch(idPresentable* attacker,
        const idVec3& start, const idMat3& fireAxis,
        const idProjectileTarget& target, float initialSpeed,
        int startTime);
    void SetupClientProjectilePhysics(idPhysics& physics,
        const idClipModelInfo& clipModelInfo, const idTraceModel* traceModel,
        float overrideCollision, idPhysicsCallbacks* callbacks);
    bool IsDead() const;
    bool IsActive() const;
    void DecayOriginAndAxisSmoothing();
    void SmoothFromOriginAndAxis(const idVec3& oldOrigin,
        const idMat3& oldAxis);
    void SmoothFromLaunchOriginAxis();
    void ClientThink(int currentTime, float fraction, bool predict) override;
    bool AdjustStartToCollision(idPresentable* attacker, idVec3& start,
        const idVec3& direction);
    void ClientLaunch(idPresentable* attacker, const idVec3& start,
        const idMat3& fireAxis, const idProjectileTarget& target,
        float initialSpeed, int startTime, int launchTime);
    void Init();
    void Serialize(idSerializer& serializer) override;

    presentableType_t GetType() const override {
        return PRESENTABLE_PROJECTILE;
    }
    virtual idPresentableProjectile* GetProjectileInterface() { return this; }
    virtual idPresentableProjectile_Rocket* GetProjectileRocketInterface() {
        return nullptr;
    }
    virtual idPresentableProjectile_Homing* GetProjectileHomingInterface() {
        return nullptr;
    }
    virtual idPresentableProjectile_Grenade* GetProjectileGrenadeInterface() {
        return nullptr;
    }

    const idDeclProjectile* projectileDecl;
    projectileState_t state;
    idPhysics* projectilePhysics;
    std::uint32_t attackerSpawnId;
    bool playingWarningSound;
    idVec3 launchOrigin;
    idMat3 launchAxis;
    bool launched;
    bool hasQuad;
    idVec3 smoothOrigin;
    idMat3 smoothAxis;
    int launchTime;
    idMat3 initialFireAxis;

protected:
    void UpdatePredictedPhysics();
    bool ownsProjectilePhysics;
};

class idPresentableProjectile_Rocket : public idPresentableProjectile {
public:
    idPresentableProjectile_Rocket(idProjectile_Rocket* entity,
        idRenderModel* renderModel, idAnimStack* animStack);
    idPresentableProjectile_Rocket(const idDeclProjectile* declaration,
        idRenderModel* renderModel, idAnimStack* animStack);
    ~idPresentableProjectile_Rocket() override;

    void InternalClientLaunch(idPresentable* attacker,
        const idVec3& start, const idMat3& fireAxis,
        const idProjectileTarget& target, float initialSpeed,
        int startTime) override;
    virtual idVec3 GetInitialDir(const idMat3& fireAxis) const;
    presentableType_t GetType() const override {
        return PRESENTABLE_PROJECTILE_ROCKET;
    }
    idPresentableProjectile_Rocket* GetProjectileRocketInterface() override {
        return this;
    }

    int calcThrustDelay;
    float goalSpeed;
};

class idPresentableProjectile_Homing : public idPresentableProjectile_Rocket {
public:
    enum homingState_t : int {
        LAUNCHING = 0,
        FLYOUT = 1,
        ACQUIRING = 2
    };

    idPresentableProjectile_Homing(idProjectile_Homing* entity,
        idRenderModel* renderModel, idAnimStack* animStack);
    idPresentableProjectile_Homing(const idDeclProjectile* declaration,
        idRenderModel* renderModel, idAnimStack* animStack);

    idVec3 GetInitialDir(const idMat3& fireAxis) const override;
    void ClientThink(int currentTime, float fraction, bool predict) override;
    void InternalClientLaunch(idPresentable* attacker,
        const idVec3& start, const idMat3& fireAxis,
        const idProjectileTarget& target, float initialSpeed,
        int startTime) override;
    presentableType_t GetType() const override {
        return PRESENTABLE_PROJECTILE_HOMING;
    }
    idPresentableProjectile_Homing* GetProjectileHomingInterface() override {
        return this;
    }

    homingState_t homingState;
    idProjectileTarget target;
};

class idPresentableProjectile_Grenade : public idPresentableProjectile {
public:
    idPresentableProjectile_Grenade(idProjectile_Grenade* entity,
        idRenderModel* renderModel, idAnimStack* animStack);
    idPresentableProjectile_Grenade(const idDeclProjectile* declaration,
        idRenderModel* renderModel, idAnimStack* animStack);
    ~idPresentableProjectile_Grenade() override;

    float GetSpeedForFireAxis(const idPresentable* attacker,
        const idMat3& fireAxis) const;
    void ClientThink(int currentTime, float fraction, bool predict) override;
    void InternalClientLaunch(idPresentable* attacker,
        const idVec3& start, const idMat3& fireAxis,
        const idProjectileTarget& target, float initialSpeed,
        int startTime) override;
    presentableType_t GetType() const override {
        return PRESENTABLE_PROJECTILE_GRENADE;
    }
    idPresentableProjectile_Grenade* GetProjectileGrenadeInterface() override {
        return this;
    }
};
