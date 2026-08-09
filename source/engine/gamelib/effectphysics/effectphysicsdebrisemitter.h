#pragma once

#include "gamelib/effectphysics/effectphysicspieceemitter.h"

class idDeclBreakable;

class idEffectPhysicsDebrisEmitter {
public:
    struct emitBufferItem_t {
        idVec3 pos;
        idVec3 normal;
        int count;
    };

    idEffectPhysicsDebrisEmitter();

    void Init(const idDeclBreakable* breakableDebris, int entityNumber,
        idClip& clip, idRenderModelEffects* renderModelEffects);
    void EmitDebris(idVec3 position, idVec3 velocity, idVec3 normal,
        int count, int currentTime);
    void Update(const idVec3& origin, const idMat3& axis,
        const idVec3& drawScale3D, int currentTime, int gameMsPerFrame);

    idEffectPhysicsPieceEmitter piecePhysics;
    emitBufferItem_t emitBuffer[10];
    int emitBufferPos;
    int serializeEmitCount;
    bool skipFirstFrame;
    bool active;
    idRandom2 random;

private:
    void EmitBuffered(const emitBufferItem_t& item,
        const idVec3& velocity, int currentTime);
};

static_assert(sizeof(idEffectPhysicsDebrisEmitter::emitBufferItem_t) == 28,
    "Recovered debris emit-buffer ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idEffectPhysicsDebrisEmitter) == 464,
    "Recovered idEffectPhysicsDebrisEmitter ABI changed");
#endif
