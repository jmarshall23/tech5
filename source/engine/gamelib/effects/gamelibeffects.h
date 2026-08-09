#pragma once

#include "gamelib/effects/deferreddecalmanager.h"
#include "gamelib/effects/effectsmodelmanager.h"
#include "gamelib/effects/fxmanager.h"
#include "gamelib/effects/impactmanager.h"
#include "gamelib/effects/ribbonmanager.h"
#include "gamelib/effects/weapontracemanager.h"

class idClip;
class idRenderModelBeam;
class idRenderModelDecal;
class idRenderModelEffects;
class idRenderWorld;

class alignas(8) idGameLibEffects {
public:
    idGameLibEffects();
    ~idGameLibEffects();

    void Init(idRenderWorld* renderWorld, idClip* clip, float diversity,
        int localPlayerIndex);
    void Shutdown();
    bool Update(int currentTime, int gameMsPerFrame, int serverCurrentTime);

    idRenderModelEffects* effectsModel;
    idRenderModelDecal* decalModel;
    idRenderModelBeam* beamModel;
    idEffectsModelManager effectsModelManager;
    idDeferredDecalManager deferredDecalManager;
    idRibbonModelManager ribbonModelManager;
    idWeaponTraceManager weaponTraceManager;
    idFXModelRecycler fxModelRecycler;
    idImpactManager weaponImpactManager;
    idImpactManager impactManager;
    bool initialized;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idFXModelRecycler) == 2720,
    "Recovered idFXModelRecycler ABI changed");
static_assert(sizeof(idGameLibEffects) == 10432,
    "Recovered idGameLibEffects ABI changed");
#endif
