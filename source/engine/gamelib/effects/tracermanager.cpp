#include "gamelib/effects/tracermanager.h"

#include <algorithm>
#include <cstring>

void GameLib_AddTracerToEffectsModel(idRenderModelEffects* model,
    const idMaterial* material, const idVec3& origin,
    const idVec3& direction, const idVec3& maxDistance, float speed,
    float length, float height, bool ensureVisual, float fractionInsured,
    float lifeTime);
void GameLib_SerializeTracerBuffer(idSerializer& serializer,
    idTracerManager::tracerBufferItem_t* buffer, int count,
    int& bufferPosition);

idTracerManager::idTracerManager()
    : effectsModel(nullptr)
    , tracerBuffer{}
    , tracerBufferPos(0)
    , serializeTracerCount(0)
    , catchingUp(false)
    , localPlayerIndex(0) {
}

void idTracerManager::Init(idRenderModelEffects* const effectsModel_,
    const int playerIndex) {
    effectsModel = effectsModel_;
    localPlayerIndex = playerIndex;
}

void idTracerManager::AddTracer(const idMaterial* const material,
    const idVec3& origin, const idVec3& direction,
    const idVec3& maxDistance, const float speed, const float length,
    const float height, const bool ensureVisual,
    const float fractionInsured, const int playerIndex) {
    if (effectsModel != nullptr) {
        GameLib_AddTracerToEffectsModel(effectsModel, material, origin,
            direction, maxDistance, speed, length, height, ensureVisual,
            fractionInsured, -1.0f);
    }
    if (catchingUp) {
        return;
    }
    tracerBufferItem_t& item = tracerBuffer[tracerBufferPos];
    item.startTime = 0;
    item.lifeTime = 0;
    item.speed = speed;
    item.origin = origin;
    item.dir = direction;
    item.length = length;
    item.height = height;
    item.mat = material;
    item.maxDist = maxDistance;
    item.ensureVisual = ensureVisual;
    item.fractionInsured = fractionInsured;
    item.playerIndex = playerIndex;
    tracerBufferPos = (tracerBufferPos + 1) % 4;
}

void idTracerManager::Update(const int time) {
    (void)time;
    catchingUp = true;
    while (serializeTracerCount > 0) {
        const int index = tracerBufferPos;
        tracerBufferPos = (tracerBufferPos + 1) % 4;
        --serializeTracerCount;
        const tracerBufferItem_t& item = tracerBuffer[index];
        if (item.playerIndex == localPlayerIndex || effectsModel == nullptr) {
            continue;
        }
        GameLib_AddTracerToEffectsModel(effectsModel, item.mat, item.origin,
            item.dir, item.maxDist, item.speed, item.length, item.height,
            item.ensureVisual, item.fractionInsured, -1.0f);
    }
    catchingUp = false;
}

void idTracerManager::Serialize(idSerializer& serializer) {
    const int oldPosition = tracerBufferPos;
    GameLib_SerializeTracerBuffer(serializer, tracerBuffer, 4,
        tracerBufferPos);
    serializeTracerCount = tracerBufferPos - oldPosition;
    if (serializeTracerCount < 0) {
        serializeTracerCount += 4;
    }
    serializeTracerCount = (std::min)(4, serializeTracerCount);
}
