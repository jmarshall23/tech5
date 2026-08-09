#pragma once

#include "gamelib/effectphysics/effectphysicspieceemitter.h"

class idClip;
class idCollisionModel;
class idDeclFX;
class idDeclParticle;
class idGameLibEffects;
class idMaterial;
class idPhysics;
class idRenderModelDiscreteAnimation;
class idSoundEmitter;
class idSoundWorld;
class idTraceModel;
class idTraceModelCache;

// Data records copied verbatim from the recovered declbreakable layout.  The
// declaration system owns parsing; GameLib owns the runtime copies below.
struct idBreakableExplosion {
    const idDeclFX* fx;
    const idDeclParticle* particle;
    idVec3 position;
    float radius;
    float impulse;
    float falloff;
    float angular;
    int delay;
    int duration;
    int activateAllDelay;
    float distTimeScaleDelay;
    bool useLinear;
    idVec3 endLinear;
    idList<int, 59> pieces;

    idBreakableExplosion() : fx(nullptr), particle(nullptr), position(),
        radius(0.0f), impulse(0.0f), falloff(0.0f), angular(0.0f), delay(0),
        duration(0), activateAllDelay(0), distTimeScaleDelay(0.0f),
        useLinear(false), endLinear(), pieces(0) {}
};

struct idBreakableTrail {
    const idDeclParticle* particleTrail;
    const idDeclParticle* particleBounce;
    const idDeclParticle* particleDie;
    const idMaterial* glowQuadMaterial;
    float glowQuadSize;
    float minTrailVelocity;
    float minBounceVelocity;
    float trailSpacing;
    float trailVelocityScale;
    int delay;
    int duration;
    int fadeInDuration;
    int fadeOutDuration;
    idList<int, 59> pieces;

    idBreakableTrail() : particleTrail(nullptr), particleBounce(nullptr),
        particleDie(nullptr), glowQuadMaterial(nullptr), glowQuadSize(0.0f),
        minTrailVelocity(0.0f), minBounceVelocity(0.0f), trailSpacing(0.0f),
        trailVelocityScale(0.0f), delay(0), duration(0), fadeInDuration(0),
        fadeOutDuration(0), pieces(0) {}
};

struct idBreakableDecal {
    idList<const idMaterial*, 59> materials;
    idVec2 minSize;
    idVec2 maxSize;
    int lifetime;
    int fadeOutStartTime;
    int fadeInEndTime;
    float minBounceVelocity;
    float decalSpacing;
    float depth;
    idList<int, 59> pieces;
    bool splatterOnBounce;
    bool splatterOnRest;

    idBreakableDecal() : materials(0), minSize(), maxSize(), lifetime(0),
        fadeOutStartTime(0), fadeInEndTime(0), minBounceVelocity(0.0f),
        decalSpacing(0.0f), depth(0.0f), pieces(0),
        splatterOnBounce(false), splatterOnRest(false) {}
};

struct idBreakableSpark {
    idList<const idMaterial*, 59> materials;
    float sizeMin;
    float sizeMax;
    float velocityScaleMin;
    float velocityScaleMax;

    idBreakableSpark() : materials(0), sizeMin(0.0f), sizeMax(0.0f),
        velocityScaleMin(0.0f), velocityScaleMax(0.0f) {}
};

struct idEffectPhysicsBreakableDeclView {
    int numPieces;
    idEffectPhysicsPieceSettings settings;
    float maxSimulationTime;
    float dampeningDecay;
    idList<idBreakableExplosion, 59> explosions;
    idList<idBreakableTrail, 59> trails;
    idList<idBreakableDecal, 59> decals;
    idBreakableSpark sparks;

    idEffectPhysicsBreakableDeclView() : numPieces(0), settings{},
        maxSimulationTime(0.0f), dampeningDecay(0.0f), explosions(0),
        trails(0), decals(0), sparks() {}
};

class idEffectPhysicsBreakable {
public:
    struct idExplosion {
        idBreakableExplosion decl;
        int startTime;
        int fxIndex;
        idVec3 worldPosition;
        bool effectsEnabled;
        bool forceApplied;
        bool localSpace;
    };

    struct idTrail {
        idBreakableTrail decl;
        idList<int, 59> pieceStartTime;
        idList<idVec3, 59> pieceLastParticleDropPos;

        idTrail() : decl(), pieceStartTime(0), pieceLastParticleDropPos(0) {}
    };

    struct idBreakableParticle {
        const idDeclParticle* particle;
        idVec3 pos;
        int startTime;
    };

    struct idDecalFX {
        idBreakableDecal decl;
        idList<int, 59> pieceStartTime;
        idList<idVec3, 59> lastCollisionPos;
        idList<idVec3, 59> lastCollisionNormal;
        idList<idVec3, 59> pieceLastDecalDropPos;

        idDecalFX() : decl(), pieceStartTime(0), lastCollisionPos(0),
            lastCollisionNormal(0), pieceLastDecalDropPos(0) {}
    };

    struct idSpark {
        const idMaterial* material;
        float velocityScale;
        float size;
    };

    struct breakablePieceSound_t {
        idSoundWorld* soundWorld;
        idSoundEmitter* emitter;
        int channel;
        const idDeclImpactSound* impactTable;
        int nextSoundTime;
        float minBounceVelSqr;
    };

    idEffectPhysicsBreakable();
    ~idEffectPhysicsBreakable();

    void Init(idClip* clip, idTraceModelCache* traceModelCache,
        idGameLibEffects* effects, idRenderModelDiscreteAnimation* model,
        int entityNumber, const breakablePieceSound_t* soundInfo);
    void Reset(bool skipModelReset);
    void UpdateSimulation(const idVec3& origin, const idMat3& axis,
        int currentTime, int gameMsPerFrame, int frameNumber,
        float lodScale, float effectScale);
    void UpdateModel(const idVec3& origin, const idMat3& axis,
        int currentTime);
    void DrawCollisionModels(int single, const idVec3& offset,
        const idMat3& axis);
    void ApplyForce(const idVec3& origin, const idMat3& axis,
        const idVec3& force);
    void AddRadiusImpact(int time, const idPhysics* impactPhysics,
        const idVec3& position, float radius, float impulse);
    void AddRayImpact(int time, const idVec3& origin, const idMat3& axis,
        const idVec3& start, const idVec3& end, bool activeOnly);
    void ApplyImpulseToBody(int bodyIndex, const idPhysics* impactPhysics,
        const idVec3& point, const idVec3& impulse);
    void CollideWith(const idVec3& origin, const idPhysics* impactPhysics,
        const idVec3& point, float impulseScale);
    bool ActivateAllNow(const idVec3& origin, const idMat3& axis);
    bool ActivateFloatingPieces(const idVec3& origin, const idMat3& axis,
        float impulse);
    void EmitSmokeForEachPiece(const idDeclParticle* particle, int time);
    void StartExplosions(const idVec3& origin, const idMat3& axis, int time);
    void StopExplosionFX(int index);
    void RemoveExplosions();
    void AddExplosion(const idDeclParticle* particle, int time,
        const idVec3& position, float radius, float impulse, float falloff,
        float angular, int delay, int duration, bool localSpace,
        int activateAllDelay, float distanceDelayScale,
        const idVec3& endLinear, float effectScale);

    idList<idEffectPhysicsProperties*, 59> properties;
    idList<idEffectPhysicsRigidBody*, 59> rigidBodies;
    idList<idEffectPhysicsCollision, 59> collisions;
    idCollisionModel* basePiece;
    idList<idExplosion, 59> explosions;
    // The recovered list stores idFXManager values. Runtime ownership crosses
    // into effects, so PC stores the returned manager handles at the same ABI.
    idList<int, 59> explosionFX;
    idList<idTrail, 59> trails;
    idList<float, 59> damage;
    idList<idBreakableParticle, 59> particles;
    idList<idDecalFX, 59> decals;
    idList<idSpark, 59> sparks;
    idList<int, 5> pieceActivationTimes;
    idEffectPhysicsBroadPhase broadPhase;
    idRandom random;
    idGameLibEffects* gameLibEffects;
    idRenderModelDiscreteAnimation* model;
    const idDeclBreakable* decl;
    breakablePieceSound_t soundInfo;

private:
    idEffectPhysicsProperties* GetPropertiesForTraceModel(
        const idTraceModel& traceModel, const idMaterial* material);
    bool ActivateNoisy(int pieceIndex, const idVec3& origin,
        const idMat3& axis);
    bool DamagePiece(int time, int pieceIndex, float amount,
        const idVec3& position);
    void InitExplosionsAndTrails(const breakablePieceSound_t* sound,
        idGameLibEffects* effects, float diversity);
};

static_assert(sizeof(idBreakableExplosion) == 84,
    "Recovered idBreakableExplosion ABI changed");
static_assert(sizeof(idBreakableTrail) == 68,
    "Recovered idBreakableTrail ABI changed");
static_assert(sizeof(idBreakableDecal) == 76,
    "Recovered idBreakableDecal ABI changed");
static_assert(sizeof(idEffectPhysicsBreakable::idExplosion) == 108,
    "Recovered breakable explosion ABI changed");
static_assert(sizeof(idEffectPhysicsBreakable::idTrail) == 100,
    "Recovered breakable trail ABI changed");
static_assert(sizeof(idEffectPhysicsBreakable::idDecalFX) == 140,
    "Recovered breakable decal ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idEffectPhysicsBreakable) == 292,
    "Recovered idEffectPhysicsBreakable ABI changed");
#endif
