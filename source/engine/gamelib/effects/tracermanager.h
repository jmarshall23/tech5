#pragma once

#include "idlib/math/vector.h"

class idMaterial;
class idRenderModelEffects;
class idSerializer;

class idTracerManager {
public:
    struct tracerBufferItem_t {
        int startTime;
        int lifeTime;
        float speed;
        idVec3 origin;
        idVec3 dir;
        float length;
        float height;
        const idMaterial* mat;
        idVec3 maxDist;
        bool ensureVisual;
        float fractionInsured;
        int playerIndex;
    };

    idTracerManager();

    void Init(idRenderModelEffects* effectsModel, int playerIndex);
    void AddTracer(const idMaterial* material, const idVec3& origin,
        const idVec3& direction, const idVec3& maxDistance, float speed,
        float length, float height, bool ensureVisual,
        float fractionInsured, int playerIndex);
    void Update(int time);
    void Serialize(idSerializer& serializer);

    idRenderModelEffects* effectsModel;
    tracerBufferItem_t tracerBuffer[4];
    int tracerBufferPos;
    int serializeTracerCount;
    bool catchingUp;
    int localPlayerIndex;
};

static_assert(sizeof(idTracerManager::tracerBufferItem_t) == 72,
    "Recovered tracer buffer ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idTracerManager) == 308,
    "Recovered idTracerManager ABI changed");
#endif
