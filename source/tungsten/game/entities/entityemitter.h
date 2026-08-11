#pragma once

#include "game/entities/entity.h"
#include "idlib/math/random.h"

class idDeclImpactSound;

class idEntityParticle : public idEntity {
public:
    enum idEntityParticleState {
        STATE_IDLE = 0,
        STATE_ACTIVE_MOVING = 1,
        STATE_ACTIVE_STOPPED = 2,
        STATE_FADE = 3
    };

    idEntityParticle();
    void Spawn() override;

    float emitTime;
    float nextSoundTime;
    idEntityParticleState state;
    idVec3 vel;
    idVec3 rotationAxis;
    float rotationSpeed;
    idVec3 lastCollisionPos;
    idVec3 lastCollisionNormal;
    float fovScale;
    float modelDepthHack;
};

struct idEntityEmitterTrace {
    bool hit = false;
    float fraction = 1.0f;
    idVec3 point;
    idVec3 normal;
    int surfaceType = 0;
};

class idEntityEmitterServices {
public:
    virtual ~idEntityEmitterServices() = default;
    virtual int GetGameMilliseconds() const;
    virtual int GetFrameMilliseconds() const;
    virtual idVec3 GetGravity() const;
    virtual bool RunParticlePhysics() const;
    virtual bool CheckParticleCollisions() const;
    virtual float GetFovScaleSpeed() const;
    virtual float GetPushAwayFactor() const;
    virtual bool TracePoint(const idEntityParticle& particle,
        const idVec3& start, const idVec3& end,
        idEntityEmitterTrace& trace) const;
    virtual idEntityParticle* SpawnParticle(const idDeclEntityDef* def);
    virtual void DisableDimShadows(idEntityParticle& particle);
    virtual void PresentParticle(idEntityParticle& particle);
    virtual bool PlayImpactSound(idEntityParticle& particle,
        const idDeclImpactSound* table, int surfaceType);
    virtual int GetImpactSoundInterval(
        const idDeclImpactSound* table) const;
};

class idEntityEmitter : public idEntity {
public:
    enum AXIS {
        AXIS_NONE = -1,
        AXIS_X = 0,
        AXIS_Y = 1,
        AXIS_Z = 2
    };

    idEntityEmitter();
    ~idEntityEmitter() override;

    static void SetServices(idEntityEmitterServices* services);
    static idEntityEmitterServices& Services();

    bool RunState_Fade(idEntityParticle* particle);
    void RunPhysics(idEntityParticle* particle);
    void RunState_Active(idEntityParticle* particle);
    void Think() override;
    void Spawn() override;

    int particleCount;
    float particleLifespan;
    float particleFadeTime;
    float particleFadeSpeed;
    float particleCollisionElasticity;
    float particleCrazyBounceChance;
    float particleAngularVelocity;
    float particleFriction;
    float particleAngularFriction;
    AXIS particleAlignmentExcludeAxis;
    const idDeclImpactSound* impactSoundTable;
    const idDeclEntityDef* particleDef;
    idList<idEntityParticle*, 5> particles;
    int particleIndex;
    int numParticlesInUse;
    idRandom random;
    float emitFovScale;
    float emitModelDepthHack;
};
