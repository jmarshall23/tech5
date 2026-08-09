#pragma once

#include "gamelib/effects/effectsmodelmanager.h"
#include "idlib/color.h"
#include "idlib/containers/list.h"
#include "idlib/math/random.h"

class idDeclParticle;
class idRenderModelParticle;
class idSerializer;

class idImpactManager {
public:
    struct impactState_t {
        idRenderModelParticle* pmodel;
        int startTime;
        int endTime;
    };

    struct impactBindState_t {
        bool bindToParent;
        idVec3 relOrg;
        idMat3 relRot;
    };

    struct impactBufferItem_t {
        idVec3 pos;
        idMat3 axis;
        const idDeclParticle* prt;
        bool bindToParent;
        int playerIndex;
        int serverTime;
    };

    idImpactManager();
    ~idImpactManager();

    void Init(idEffectsModelManager* effectsModelManager, float diversity,
        int maxImpacts, int localPlayerIndex);
    void Shutdown();
    void StopImpacts();
    void UseImpact(const idVec3& origin, const idMat3& axis,
        const idDeclParticle* particle, int startTime, bool bindToParent,
        const idVec3& parentOrigin, const idMat3& parentAxis,
        float distanceSqr, int playerIndex, const idColor& color,
        int numCycles);
    void Update(const idVec3& parentOrigin, const idMat3& parentAxis,
        int localTime, int serverTime);
    void Serialize(idSerializer& serializer);

    idList<impactState_t, 5> impacts;
    idList<impactBindState_t, 5> impactBinds;
    int next;
    idRandom2 random;
    bool initialized;
    idEffectsModelManager* effectsModelManager;
    impactBufferItem_t impactBuffer[16];
    int impactBufferPos;
    int serializeImpactCount;
    int localPlayerIndex;
};

static_assert(sizeof(idImpactManager::impactState_t) == 12,
    "Recovered impact state ABI changed");
static_assert(sizeof(idImpactManager::impactBindState_t) == 52,
    "Recovered impact bind ABI changed");
static_assert(sizeof(idImpactManager::impactBufferItem_t) == 64,
    "Recovered impact buffer ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idImpactManager) == 1084,
    "Recovered idImpactManager ABI changed");
#endif
