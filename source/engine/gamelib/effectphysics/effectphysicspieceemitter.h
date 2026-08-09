#pragma once

#include "gamelib/effectphysics/effectphysicsrigidbody.h"
#include "idlib/containers/list.h"
#include "idlib/math/random.h"

class idClip;
class idDeclBreakable;
class idDeclImpactSound;
class idMaterial;
class idRenderModelDiscreteAnimation;
class idRenderModelEffects;
class idSoundWorld;
class idTraceModel;
class idTraceModelCache;

// PC-side copy of the physics fields read from idDeclBreakable.  The engine
// declaration adapter fills it, keeping GameLib independent of the unfinished
// declaration/render-model class hierarchy.
struct idEffectPhysicsPieceSettings {
    float linearFriction;
    float angularFriction;
    float contactFriction;
    float linearFrictionWater;
    float angularFrictionWater;
    float bouncyness;
    idVec3 gravityVector;
    bool worldCollisionOnly;
    bool simplePointCollision;
    float crazyBounceChance;
    float stopSpeed;
    float maxLinearVelocity;
    float maxAngularVelocity;
    int clipMask;
};

class alignas(4) idEffectPhysicsPieceEmitter {
public:
    struct idBreakablePiece {
        idEffectPhysicsRigidBody* rigidBody;
        idEffectPhysicsCollision collision;
        int emitTime;
        int firstCollisionTime;
    };

    struct pieceEmitterSound_t {
        idSoundWorld* soundWorld;
        const idDeclImpactSound* impactTable;
        int nextSoundTime;
        float minBounceVelSqr;
    };

    idEffectPhysicsPieceEmitter();
    ~idEffectPhysicsPieceEmitter();

    void Init(idClip* clip, idTraceModelCache* traceModelCache,
        idRenderModelDiscreteAnimation* renderModel,
        idRenderModelEffects* renderModelEffects,
        const pieceEmitterSound_t* sound, int entityNumber);
    void Reset();
    void EmitPiece(int emitTime, const idVec3& position,
        const idMat3& orientation, const idVec3& impulsePoint,
        const idVec3& impulse);
    void UpdateSimulation(const idVec3& origin, const idMat3& axis,
        int currentTime, int gameMsPerFrame);
    void UpdateModel(const idVec3& activeDrawScale3D);
    void SubmitCollisionQueries(bool worldCollisionModelOnly);
    void DrawCollisionModels(int single, const idVec3& offset,
        const idMat3& axis);
    void Hide();
    void Show();

    idList<idEffectPhysicsProperties*, 59> properties;
    idList<idBreakablePiece, 59> pieces;
    idEffectPhysicsBroadPhase broadPhase;
    idRandom random;
    float pieceMass;
    float pieceCollisionAgeDecay;
    float pieceCollisionVolumeDecay;
    idRenderModelDiscreteAnimation* model;
    const idDeclBreakable* decl;
    idRenderModelEffects* modelEffects;
    pieceEmitterSound_t soundInfo;
    int pieceLifeTime;
    float pieceFriction;
    int pieceIndex;
    int numPiecesInUse;
    bool hidden;
    bool hiddenOverride;

private:
    idEffectPhysicsProperties* GetPropertiesForTraceModel(
        const idTraceModel& traceModel, const idMaterial* material);
    void ApplyDeclSettings(idEffectPhysicsProperties& target) const;
};

static_assert(sizeof(idEffectPhysicsPieceEmitter::idBreakablePiece) == 40,
    "Recovered idBreakablePiece ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idEffectPhysicsPieceEmitter) == 168,
    "Recovered idEffectPhysicsPieceEmitter ABI changed");
#endif
