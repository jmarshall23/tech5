#include "gamelib/effects/impactmanager.h"

#include <algorithm>

const idDeclParticle* GameLib_GetParticleModelDecl(
    const idRenderModelParticle* model);
int GameLib_GetParticleEffectDuration(const idDeclParticle* particle,
    int numCycles);
void GameLib_ConfigureImpactParticleModel(idRenderModelParticle* model,
    const idDeclParticle* particle, const idVec3& origin,
    const idMat3& axis, int startTime, float diversity,
    float distanceSqr, const idColor& color);
void GameLib_UpdateImpactParticleTransform(idRenderModelParticle* model,
    const idVec3& origin, const idMat3& axis);
void GameLib_HideImpactParticleModel(idRenderModelParticle* model);
void GameLib_SerializeImpactBuffer(idSerializer& serializer,
    idImpactManager::impactBufferItem_t* buffer, int count,
    int& bufferPosition);

idImpactManager::idImpactManager()
    : impacts(0)
    , impactBinds(0)
    , next(0)
    , random(0)
    , initialized(false)
    , effectsModelManager(nullptr)
    , impactBuffer{}
    , impactBufferPos(0)
    , serializeImpactCount(0)
    , localPlayerIndex(0) {
}

idImpactManager::~idImpactManager() {
    Shutdown();
}

void idImpactManager::Init(
    idEffectsModelManager* const effectsModelManager_,
    const float diversity, const int maxImpacts,
    const int localPlayerIndex_) {
    if (initialized) {
        return;
    }
    effectsModelManager = effectsModelManager_;
    localPlayerIndex = localPlayerIndex_;
    next = 0;
    random.SetSeed(static_cast<unsigned int>(diversity * 65535.0f));
    impacts.SetNum((std::max)(0, maxImpacts));
    impactBinds.SetNum(impacts.Num());
    for (int index = 0; index < impacts.Num(); ++index) {
        impacts[index] = impactState_t{nullptr, 0, 0};
        impactBinds[index].bindToParent = false;
        impactBinds[index].relOrg.Zero();
        impactBinds[index].relRot = idMat3(1.0f);
    }
    initialized = true;
}

void idImpactManager::StopImpacts() {
    for (int index = 0; index < impacts.Num(); ++index) {
        impactState_t& impact = impacts[index];
        if (impact.pmodel != nullptr) {
            GameLib_HideImpactParticleModel(impact.pmodel);
            if (effectsModelManager != nullptr) {
                effectsModelManager->RecycleParticleFxModel(
                    GameLib_GetParticleModelDecl(impact.pmodel),
                    impact.pmodel);
            }
            impact.pmodel = nullptr;
        }
        impact.startTime = 0;
        impact.endTime = 0;
    }
}

void idImpactManager::Shutdown() {
    StopImpacts();
    impacts.Clear();
    impactBinds.Clear();
    effectsModelManager = nullptr;
    impactBufferPos = 0;
    serializeImpactCount = 0;
    next = 0;
    initialized = false;
    localPlayerIndex = 0;
}

void idImpactManager::UseImpact(const idVec3& origin,
    const idMat3& axis, const idDeclParticle* const particle,
    const int startTime, const bool bindToParent,
    const idVec3& parentOrigin, const idMat3& parentAxis,
    const float distanceSqr, const int playerIndex,
    const idColor& color, const int numCycles) {
    if (!initialized || particle == nullptr || impacts.IsEmpty() ||
        effectsModelManager == nullptr) {
        return;
    }
    impactState_t& impact = impacts[next];
    impactBindState_t& bind = impactBinds[next];
    if (impact.pmodel != nullptr) {
        GameLib_HideImpactParticleModel(impact.pmodel);
        effectsModelManager->RecycleParticleFxModel(
            GameLib_GetParticleModelDecl(impact.pmodel), impact.pmodel);
    }
    impact.pmodel =
        effectsModelManager->GetNextParticleEffectModel(particle);
    if (impact.pmodel == nullptr) {
        return;
    }
    impact.startTime = startTime;
    impact.endTime = startTime +
        GameLib_GetParticleEffectDuration(particle, numCycles) + 1000;
    bind.bindToParent = bindToParent;
    if (bindToParent) {
        const idMat3 inverseParent = parentAxis.Transpose();
        bind.relOrg = inverseParent * (origin - parentOrigin);
        bind.relRot = axis * inverseParent;
    } else {
        bind.relOrg.Zero();
        bind.relRot = idMat3(1.0f);
    }

    impactBufferItem_t& item = impactBuffer[impactBufferPos];
    item.pos = bindToParent ? bind.relOrg : origin;
    item.axis = bindToParent ? bind.relRot : axis;
    item.prt = particle;
    item.bindToParent = bindToParent;
    item.playerIndex = playerIndex;
    item.serverTime = startTime;
    impactBufferPos = (impactBufferPos + 1) % 16;

    GameLib_ConfigureImpactParticleModel(impact.pmodel, particle,
        origin, axis, startTime, random.RandomFloat(), distanceSqr, color);
    next = (next + 1) % impacts.Num();
}

void idImpactManager::Update(const idVec3& parentOrigin,
    const idMat3& parentAxis, const int localTime, const int serverTime) {
    while (serializeImpactCount > 0) {
        const impactBufferItem_t& item = impactBuffer[impactBufferPos];
        if (serverTime != 0 && item.serverTime > serverTime) {
            break;
        }
        impactBufferPos = (impactBufferPos + 1) % 16;
        --serializeImpactCount;
        if (item.prt == nullptr || item.playerIndex == localPlayerIndex) {
            continue;
        }
        const idVec3 origin = item.bindToParent
            ? parentOrigin + parentAxis * item.pos : item.pos;
        const idMat3 axis = item.bindToParent
            ? parentAxis * item.axis : item.axis;
        UseImpact(origin, axis, item.prt, localTime, item.bindToParent,
            parentOrigin, parentAxis, 0.0f, 0,
            idColor(1.0f, 1.0f, 1.0f, 1.0f), 1);
    }

    for (int index = 0; index < impacts.Num(); ++index) {
        impactState_t& impact = impacts[index];
        if (impact.pmodel == nullptr) {
            continue;
        }
        if (impact.endTime != 0 && localTime < impact.endTime) {
            const impactBindState_t& bind = impactBinds[index];
            if (bind.bindToParent) {
                GameLib_UpdateImpactParticleTransform(impact.pmodel,
                    parentOrigin + parentAxis * bind.relOrg,
                    bind.relRot * parentAxis);
            }
        } else {
            GameLib_HideImpactParticleModel(impact.pmodel);
            if (effectsModelManager != nullptr) {
                effectsModelManager->RecycleParticleFxModel(
                    GameLib_GetParticleModelDecl(impact.pmodel),
                    impact.pmodel);
            }
            impact.pmodel = nullptr;
        }
    }
}

void idImpactManager::Serialize(idSerializer& serializer) {
    const int oldPosition = impactBufferPos;
    GameLib_SerializeImpactBuffer(serializer, impactBuffer, 16,
        impactBufferPos);
    serializeImpactCount = impactBufferPos - oldPosition;
    if (serializeImpactCount < 0) serializeImpactCount += 16;
    serializeImpactCount = (std::min)(16, serializeImpactCount);
}
