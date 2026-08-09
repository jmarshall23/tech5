#include "gamelib/effects/gamelibeffects.h"

idRenderModelEffects* GameLib_AllocEffectsModel(idRenderWorld* renderWorld);
idRenderModelDecal* GameLib_GetDecalModel(idRenderWorld* renderWorld);
idRenderModelBeam* GameLib_AllocBeamModel(idRenderWorld* renderWorld);
void GameLib_CommitEffectsModel(idRenderModelEffects* model);
void GameLib_CommitDecalModel(idRenderModelDecal* model);
void GameLib_CommitBeamModel(idRenderModelBeam* model);
void GameLib_FreeEffectsModel(idRenderModelEffects* model);
void GameLib_FreeBeamModel(idRenderModelBeam* model);
void GameLib_UpdateEffectsModel(idRenderModelEffects* model,
    int currentTime, int gameMsPerFrame);
void GameLib_UpdateBeamModel(idRenderModelBeam* model, int currentTime);

idGameLibEffects::idGameLibEffects()
    : effectsModel(nullptr)
    , decalModel(nullptr)
    , beamModel(nullptr)
    , effectsModelManager()
    , deferredDecalManager()
    , ribbonModelManager()
    , weaponTraceManager()
    , fxModelRecycler()
    , weaponImpactManager()
    , impactManager()
    , initialized(false) {
}

idGameLibEffects::~idGameLibEffects() {
    Shutdown();
}

void idGameLibEffects::Init(idRenderWorld* const renderWorld,
    idClip* const clip, const float diversity,
    const int localPlayerIndex) {
    if (initialized) {
        Shutdown();
    }
    if (renderWorld == nullptr) {
        return;
    }

    effectsModel = GameLib_AllocEffectsModel(renderWorld);
    decalModel = GameLib_GetDecalModel(renderWorld);
    beamModel = GameLib_AllocBeamModel(renderWorld);
    if (effectsModel != nullptr) {
        GameLib_CommitEffectsModel(effectsModel);
    }
    if (decalModel != nullptr) {
        GameLib_CommitDecalModel(decalModel);
    }
    if (beamModel != nullptr) {
        GameLib_CommitBeamModel(beamModel);
    }

    effectsModelManager.Init();
    deferredDecalManager.Init(clip, decalModel);
    ribbonModelManager.Shutdown();
    weaponTraceManager.Init();
    fxModelRecycler.Init();
    weaponImpactManager.Init(&effectsModelManager, diversity, 64,
        localPlayerIndex);
    impactManager.Init(&effectsModelManager, diversity, 32,
        localPlayerIndex);
    initialized = true;
}

void idGameLibEffects::Shutdown() {
    initialized = false;
    effectsModelManager.Shutdown();
    deferredDecalManager.Shutdown();
    ribbonModelManager.Shutdown();
    weaponTraceManager.Init();
    fxModelRecycler.Shutdown();
    weaponImpactManager.Shutdown();
    impactManager.Shutdown();

    if (effectsModel != nullptr) {
        GameLib_FreeEffectsModel(effectsModel);
        effectsModel = nullptr;
    }
    if (beamModel != nullptr) {
        GameLib_FreeBeamModel(beamModel);
        beamModel = nullptr;
    }
    // The decal model is owned by idRenderWorld and is not freed here in the
    // recovered shutdown path.
    decalModel = nullptr;
}

bool idGameLibEffects::Update(const int currentTime,
    const int gameMsPerFrame, const int serverCurrentTime) {
    if (!initialized) {
        return false;
    }
    deferredDecalManager.Update(currentTime);
    if (effectsModel != nullptr) {
        GameLib_UpdateEffectsModel(effectsModel, currentTime, gameMsPerFrame);
    }
    if (beamModel != nullptr) {
        GameLib_UpdateBeamModel(beamModel, currentTime);
    }
    weaponTraceManager.Update();
    const idVec3 origin(0.0f, 0.0f, 0.0f);
    const idMat3 axis(1.0f);
    weaponImpactManager.Update(origin, axis, currentTime, serverCurrentTime);
    impactManager.Update(origin, axis, currentTime, serverCurrentTime);
    return true;
}
