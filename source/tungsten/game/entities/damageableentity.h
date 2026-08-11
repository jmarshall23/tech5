#pragma once

#include "idlib/bv/bounds.h"
#include "idlib/containers/list.h"
#include "idlib/math/vector.h"

class idClipModel;
class idDeclAiEvent;
class idDeclAmmo;
class idDeclBreakable;
class idDeclDamage;
class idDeclImpactSound;
class idDeclParticle;
class idEntity;
class idPhysics;
class idPresentable;
class idRenderModel;
class idRenderModelDiscreteAnimation;
class idSoundShader;
struct trace_t;
class idDamageableEntity;

enum idDamageableBreakState {
    DAMAGEABLE_UNBREAKABLE = 0,
    DAMAGEABLE_BREAKABLE = 1,
    DAMAGEABLE_READY_TO_BREAK = 2,
    DAMAGEABLE_BREAKING = 3,
    DAMAGEABLE_BROKEN = 4,
    DAMAGEABLE_DEAD = 5
};

enum idDamageablePhysicsType {
    DAMAGEABLE_PHYSICS_NONE = 0,
    DAMAGEABLE_PHYSICS_STATIC = 1,
    DAMAGEABLE_PHYSICS_STATIC_MULTI = 2,
    DAMAGEABLE_PHYSICS_RIGID_BODY = 3
};

struct idDamageablePieceState {
    bool active = false;
    bool settled = true;
    int contents = 0x2000;
};

struct idDamageableRigidBodySettings {
    float density = 0.003f;
    float bounciness = 0.3f;
    float linearFriction = 0.6f;
    float angularFriction = 0.6f;
    float contactFriction = 0.5f;
    int contents = 139584;
    int clipMask = 1;
    bool moveable = false;
    bool barrelCollision = false;
};

struct idDamageableTraceInfo {
    bool valid = false;
    idVec3 point{0.0f, 0.0f, 0.0f};
    idVec3 normal{0.0f, 0.0f, 1.0f};
};

struct idDamageableExplosionInfo {
    idVec3 position{0.0f, 0.0f, 0.0f};
    float radius = 0.0f;
    float impulse = 0.0f;
    float falloff = 0.2f;
    float angular = 350.0f;
    int delay = 500;
    int duration = 500;
    int activateAllDelay = 100;
};

class idDamageableEntityServices {
public:
    virtual ~idDamageableEntityServices() = default;

    virtual int GetGameMilliseconds() const;
    virtual int GetPreviousGameMilliseconds() const;
    virtual int GetGameMillisecondsPerFrame() const;
    virtual int GetGameFrame() const;
    virtual float GetRealMillisecondsPerFrame() const;
    virtual float RandomFloat();
    virtual bool IsMultiplayer() const;
    virtual bool UpdateDormant(idDamageableEntity& entity);
    virtual void DormantBegin(idDamageableEntity& entity);
    virtual void PostRemove(idDamageableEntity& entity);
    virtual void GetModelTransform(const idDamageableEntity& entity,
        idVec3& origin, idMat3& axis) const;
    virtual int BaseCollide(idDamageableEntity& entity, int physicsId,
        trace_t* collision, const idVec3& velocity);
    virtual bool TakesDamage(const idDamageableEntity& entity) const;
    virtual float GetDamageAmount(const idDeclDamage* damage) const;
    virtual bool DamageIgnoresArmoredBreakables(
        const idDeclDamage* damage) const;
    virtual bool DamageIsMelee(const idDeclDamage* damage) const;
    virtual void DamageFeedback(idEntity* attacker,
        idDamageableEntity& victim, idEntity* inflictor,
        const idDeclDamage* damage, float amount);
    virtual idEntity* GetWorldEntity() const;
    virtual const idDeclDamage* GetSuicideDamage() const;
    virtual bool IsVehicle(const idEntity* entity) const;
    virtual void GetTraceInfo(const trace_t* trace,
        idDamageableTraceInfo& info) const;

    virtual idPresentable* AllocatePresentable(idDamageableEntity& entity,
        idRenderModel* renderModel, const idDeclImpactSound* impactTable,
        float minimumBounceVelocity);
    virtual idRenderModel* GetRenderModel(
        const idDamageableEntity& entity) const;
    virtual idRenderModel* AllocateRenderModelCopy(idRenderModel* model);
    virtual idRenderModelDiscreteAnimation* AsBreakableModel(
        idRenderModel* model) const;
    virtual bool HasBreakableDeclaration(
        const idRenderModelDiscreteAnimation* model) const;
    virtual int GetBreakablePieceCount(
        const idRenderModelDiscreteAnimation* model) const;
    virtual float GetBreakableAnimationSeconds(
        const idRenderModelDiscreteAnimation* model) const;
    virtual void GetBreakableFriction(
        const idRenderModelDiscreteAnimation* model,
        idDamageableRigidBodySettings& settings) const;
    virtual void SetModel(idDamageableEntity& entity,
        idRenderModel* model);
    virtual void PresentAtIdentity(idDamageableEntity& entity);
    virtual void ConfigurePresentableClip(idDamageableEntity& entity,
        int contents);

    virtual idPhysics* CreateRigidBody(idDamageableEntity& entity,
        const idDamageableRigidBodySettings& settings);
    virtual idPhysics* CreateStaticMulti(idDamageableEntity& entity,
        int pieceCount, float density);
    virtual void AddStaticMultiPiece(idDamageableEntity& entity,
        idPhysics* physics, int pieceIndex, float density);
    virtual void AddStaticMultiAggregate(idDamageableEntity& entity,
        idPhysics* physics, int pieceCount, float density);
    virtual void ConfigureSimpleBreakablePhysics(
        idDamageableEntity& entity, float density);
    virtual void AttachPhysics(idDamageableEntity& entity,
        idPhysics* physics);
    virtual void DetachPhysics(idDamageableEntity& entity);
    virtual void DestroyPhysics(idPhysics* physics);
    virtual void UnlinkPhysics(idDamageableEntity& entity);
    virtual void PutPhysicsToRest(idDamageableEntity& entity);
    virtual void SetPhysicsOrigin(idDamageableEntity& entity,
        const idVec3& origin);
    virtual void SetPhysicsAxis(idDamageableEntity& entity,
        const idMat3& axis);
    virtual void SetPieceContents(idDamageableEntity& entity,
        int pieceIndex, int contents);
    virtual void SetAllContents(idDamageableEntity& entity, int contents);
    virtual float GetPhysicsFloor(const idDamageableEntity& entity) const;
    virtual idBounds GetPhysicsBounds(
        const idDamageableEntity& entity) const;
    virtual idVec3 GetLinearVelocity(
        const idDamageableEntity& entity) const;
    virtual void ActivateNearbyPhysics(idDamageableEntity& entity,
        const idBounds& bounds);

    virtual void InitializeBreakablePhysics(idDamageableEntity& entity,
        idRenderModelDiscreteAnimation* model, int pieceCount);
    virtual void ResetBreakablePhysics(idDamageableEntity& entity);
    virtual void UpdateBreakableSimulation(idDamageableEntity& entity,
        const idVec3& origin, const idMat3& axis, int currentTime,
        int millisecondsPerFrame, int frameNumber,
        float realMillisecondsPerFrame);
    virtual void UpdateBreakableModel(idDamageableEntity& entity,
        const idVec3& origin, const idMat3& axis, int currentTime);
    virtual bool ActivateAllBreakable(idDamageableEntity& entity,
        const idVec3& origin, const idMat3& axis);
    virtual bool ActivateFloatingPieces(idDamageableEntity& entity,
        const idVec3& origin, const idMat3& axis, float floor);
    virtual void StartBreakableExplosions(idDamageableEntity& entity,
        const idVec3& origin, const idMat3& axis, int currentTime);
    virtual void AddRayImpact(idDamageableEntity& entity, int currentTime,
        const idVec3& origin, const idMat3& axis,
        const idVec3& start, const idVec3& end);
    virtual void AddRadiusImpact(idDamageableEntity& entity, int currentTime,
        const idVec3& position, float radius, float power);
    virtual void AddExplosion(idDamageableEntity& entity, int currentTime,
        const idDamageableExplosionInfo& explosion);
    virtual void EmitSmokeForEachPiece(idDamageableEntity& entity,
        const idDeclParticle* particle, int currentTime);
    virtual void DrawBreakableCollision(idDamageableEntity& entity,
        int single, const idVec3& origin, const idMat3& axis);
    virtual void RegisterBreakableSimulation(idDamageableEntity& entity);
    virtual void UnregisterBreakableSimulation(idDamageableEntity& entity);

    virtual void InitializeDebris(idDamageableEntity& entity,
        const idDeclBreakable* debris);
    virtual void EmitDebris(idDamageableEntity& entity,
        const idVec3& position, const idVec3& velocity,
        const idVec3& normal, int count, int currentTime);
    virtual void UpdateDebris(idDamageableEntity& entity,
        const idVec3& origin, const idMat3& axis,
        const idVec3& scale, int currentTime, int millisecondsPerFrame);
    virtual void ResetDebris(idDamageableEntity& entity);
    virtual void RegisterDebrisSimulation(idDamageableEntity& entity);
    virtual void UnregisterDebrisSimulation(idDamageableEntity& entity);

    virtual void ActivateTargets(idDamageableEntity& entity,
        idEntity* activator);
    virtual void StartPresentableExplosions(idDamageableEntity& entity);
    virtual void ActivateAllPresentable(idDamageableEntity& entity);
    virtual void AddPresentableRayImpact(idDamageableEntity& entity,
        const idVec3& start, const idVec3& end);
    virtual void SetModelFade(idDamageableEntity& entity, float fade);
    virtual float GetModelFade(const idDamageableEntity& entity) const;
    virtual void HidePresentable(idDamageableEntity& entity);
    virtual void PlaySound(idDamageableEntity& entity,
        const idSoundShader* shader, int channel);
    virtual void AddParticle(idDamageableEntity& entity,
        const idDeclParticle* particle, int currentTime,
        float diversity, const idVec3& origin, const idMat3& axis);
    virtual void AddDamagedAIEvent(idDamageableEntity& entity,
        const idDeclAiEvent* eventDeclaration, idEntity* attacker,
        int currentTime, const idVec3& origin, int delay);

    virtual void SetOrigin(idDamageableEntity& entity,
        const idVec3& origin);
    virtual void SetAxis(idDamageableEntity& entity,
        const idMat3& axis);
    virtual void RunPhysics(idDamageableEntity& entity);
    virtual void UpdateFX(idDamageableEntity& entity);
    virtual void UpdatePVSAreas(idDamageableEntity& entity);
    virtual void UpdateVisuals(idDamageableEntity& entity);
    virtual bool IsPresentableAnimating(
        const idDamageableEntity& entity) const;
    virtual void BecomeActive(idDamageableEntity& entity, int flags);
    virtual void BecomeInactive(idDamageableEntity& entity, int flags);
    virtual void ForceDormancy(idDamageableEntity& entity,
        bool dormant, int durationMilliseconds);
    virtual void NotifyProgressionOwner(idDamageableEntity& entity);
    virtual void UnlinkMainClip(idDamageableEntity& entity);
    virtual void InternalApplyRadiusDamage(idDamageableEntity& entity,
        const idEntity* inflictor, const idEntity* attacker,
        const idDeclDamage* damage, const idVec3& position,
        float damageScale, float radiusScale, float radius,
        bool radiusKills, bool shouldBreak);
    virtual float GetDamageablePowerBase() const;
    virtual float GetDamageablePowerScale() const;
    virtual float GetBreakableExplosionImpulseScale() const;
    virtual int GetShowBreakableCollision() const;
    virtual bool GetDebugBreakableIslands() const;
    virtual bool IsPlayerWithinDebugDistance(
        const idDamageableEntity& entity, float distance) const;
    virtual void ReleaseClipModel(idClipModel*& clipModel);
};

class idDamageableEntity {
public:
    using breakState_t = idDamageableBreakState;
    static constexpr breakState_t UNBREAKABLE = DAMAGEABLE_UNBREAKABLE;
    static constexpr breakState_t BREAKABLE = DAMAGEABLE_BREAKABLE;
    static constexpr breakState_t READY_TO_BREAK =
        DAMAGEABLE_READY_TO_BREAK;
    static constexpr breakState_t BREAKING = DAMAGEABLE_BREAKING;
    static constexpr breakState_t BROKEN = DAMAGEABLE_BROKEN;
    static constexpr breakState_t DEAD = DAMAGEABLE_DEAD;

    idDamageableEntity();
    virtual ~idDamageableEntity();

    static void SetServices(idDamageableEntityServices* services);
    static idDamageableEntityServices& Services();

    virtual void DormantBegin();
    virtual void GetModelTransform(idVec3& modelOrigin,
        idMat3& modelAxis) const;
    virtual int Collide(int physicsId, trace_t* collision,
        const idVec3& velocity);
    virtual bool IsTargetLockable(const idDeclAmmo* ammo) const;
    virtual idPresentable* AllocPresentable(idRenderModel* renderModel);
    virtual void DeactivatePhysics(int physicsId);
    virtual void SetOrigin(const idVec3& origin);
    virtual void SetAxis(const idMat3& axis);
    virtual void Think();
    virtual float Damage(idEntity* inflictor, idEntity* attacker,
        const idDeclDamage* damage, float damageScale,
        const idVec3& direction, trace_t* trace);

    void SetupRigidBodyPhysics();
    void ThrowDebris(const idVec3& position, const idVec3& hitVelocity,
        const idVec3& normal, int count);
    void StartExplosions();
    void ReorientSwap(const idVec3& spot);
    void ActivateAll();
    void UpdateBreakableSim();
    void Event_Kill();
    void SetupStaticMultiPhysics();
    bool AllSettled() const;
    void CheckDamagedPieces();
    void SetBreakableModel();
    bool BreakBreakable(const idVec3& source);
    void ApplyRadiusDamage(const idEntity* inflictor,
        const idEntity* attacker, const idDeclDamage* damage,
        const idVec3& position, float damageScale,
        float radiusScale, float radius);
    void Spawn();

    float health;
    float healthMax;
    idPhysics* physicsObj;
    idRenderModel* initialModel;
    bool useRigidBody;
    bool useStaticMulti;
    const idSoundShader* sndBreak;
    const idSoundShader* sndCrumble;
    const idDeclImpactSound* impactSoundTable;
    float pieceMinBounceVelocity;
    int armorValue;
    bool radiusDamageKills;
    bool reorientOnSwap;
    int fadeTime;
    int maxSimulationTime;
    const idDeclParticle* fadeParticle;
    const idDeclParticle* swapParticle;
    const idDeclParticle* destroyParticle;
    const idDeclAiEvent* damagedAiEventDecl;
    int collideIgnoreImpulse;
    float destructionPercent;
    float noClipPercent;
    float resistPercent;
    float secondBlastScale;
    float density;
    int hitsTaken;
    int breakableTime;
    bool explosionsStarted;
    bool moveable;
    bool barrelCollision;
    bool targetable;
    idClipModel* deadClipModel;
    const idDeclBreakable* breakableDebris;
    idVec3 debrisScale;
    bool staticVehicleCollisions;
    breakState_t state;
    idRenderModelDiscreteAnimation* breakableModel;
    idRenderModel* renderModel;
    int fadeStartTime;
    int fadeEndTime;
    int lastBump;
    bool resetWhenDormant;
    bool breakImmediately;
    int playerOwnerSpawnId;

    idVec3 origin;
    idMat3 axis;
    idVec3 spawnPosition;
    idMat3 spawnOrientation;
    idVec3 linearVelocity;
    idDamageablePhysicsType physicsType;
    idList<idDamageablePieceState, 5> pieces;
    int thinkFlags;
    bool removed;
    bool hidden;
    bool mainClipLinked;
    bool debrisInitialized;
    bool breakableInitialized;
    bool debrisSimulationRegistered;
    bool breakableSimulationRegistered;

private:
    void SetPieceContents(int pieceIndex, int contents);
    void SetAllPieceContents(int contents);
    void AddRayDamageImpact(int currentTime, const idVec3& start,
        const idVec3& end);
};

// Retail $LN88 is the exception cleanup for Spawn's temporary clip model.
void DamageableEntityAllocationCleanup(idClipModel*& clipModel);
