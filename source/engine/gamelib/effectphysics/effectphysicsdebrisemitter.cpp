#include "gamelib/effectphysics/effectphysicsdebrisemitter.h"

#include "gamelib/physics/clip.h"

#include <algorithm>

idRenderModelDiscreteAnimation* GameLib_CreateDebrisRenderModel(
    const idDeclBreakable* breakableDecl);

idEffectPhysicsDebrisEmitter::idEffectPhysicsDebrisEmitter()
    : piecePhysics()
    , emitBuffer{}
    , emitBufferPos(0)
    , serializeEmitCount(0)
    , skipFirstFrame(false)
    , active(false)
    , random(0) {
}

void idEffectPhysicsDebrisEmitter::Init(
    const idDeclBreakable* const breakableDebris, const int entityNumber,
    idClip& clip, idRenderModelEffects* const renderModelEffects) {
    active = false;
    if (breakableDebris == nullptr || clip.traceModelCache == nullptr) {
        return;
    }
    idRenderModelDiscreteAnimation* const model =
        GameLib_CreateDebrisRenderModel(breakableDebris);
    if (model == nullptr) {
        return;
    }
    piecePhysics.Init(&clip, clip.traceModelCache, model,
        renderModelEffects, nullptr, entityNumber);
    piecePhysics.pieceLifeTime = 2500;
    piecePhysics.pieceFriction = 15.0f;
    const idVec3 unitScale(1.0f, 1.0f, 1.0f);
    piecePhysics.UpdateModel(unitScale);
    emitBufferPos = 0;
    serializeEmitCount = 0;
    skipFirstFrame = true;
    active = true;
    random.SetSeed(0);
}

void idEffectPhysicsDebrisEmitter::EmitBuffered(
    const emitBufferItem_t& item, const idVec3& velocity,
    const int currentTime) {
    idVec3 normal = item.normal;
    if (normal.NormalizeFast() == 0.0f) {
        normal.Set(0.0f, 0.0f, 1.0f);
    }
    for (int index = 0; index < item.count; ++index) {
        idVec3 randomOffset(random.CRandomFloat() * 4.0f,
            random.CRandomFloat() * 4.0f,
            random.CRandomFloat() * 4.0f);
        // Keep the recovered disk-shaped spawn scatter perpendicular to the
        // impact normal rather than spraying pieces into the surface.
        randomOffset = randomOffset - normal * randomOffset.Dot(normal);
        const idVec3 position = item.pos + randomOffset;
        const float upwardSpeed = 2000.0f + random.RandomFloat() * 1250.0f;
        const idVec3 impulse = velocity + normal * upwardSpeed +
            idVec3(random.CRandomFloat(), random.CRandomFloat(),
                random.CRandomFloat()) * 40.0f;
        piecePhysics.EmitPiece(currentTime, position, idMat3(1.0f),
            item.pos, impulse);
    }
}

void idEffectPhysicsDebrisEmitter::EmitDebris(const idVec3 position,
    const idVec3 velocity, const idVec3 normal, int count,
    const int currentTime) {
    if (!active) {
        return;
    }
    count = (std::max)(0, (std::min)(15, count));
    emitBufferItem_t& item = emitBuffer[emitBufferPos];
    item.pos = position;
    item.normal = normal;
    item.count = count;
    emitBufferPos = (emitBufferPos + 1) % 10;
    EmitBuffered(item, velocity, currentTime);
}

void idEffectPhysicsDebrisEmitter::Update(const idVec3& origin,
    const idMat3& axis, const idVec3& drawScale3D,
    const int currentTime, const int gameMsPerFrame) {
    while (serializeEmitCount > 0) {
        const int first = (emitBufferPos - serializeEmitCount + 10) % 10;
        EmitBuffered(emitBuffer[first], idVec3(0.0f, 0.0f, 0.0f),
            currentTime);
        --serializeEmitCount;
    }
    if (skipFirstFrame) {
        skipFirstFrame = false;
    }
    if (piecePhysics.numPiecesInUse > 0) {
        piecePhysics.UpdateSimulation(origin, axis,
            currentTime, gameMsPerFrame);
        piecePhysics.UpdateModel(drawScale3D);
        piecePhysics.SubmitCollisionQueries(false);
    }
}
