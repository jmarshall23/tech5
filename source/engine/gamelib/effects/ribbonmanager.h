#pragma once

#include "idlib/containers/staticlist.h"
#include "gamelib/effects/ribbon.h"

class idDeclRibbon;
class idRenderModelBeam;
class idRibbonModelManager {
public:
    struct ribbonEffects_t {
        // Materialized in the authoritative effects/ribbonmanager.h dump.
        ribbonEffects_t()
            : ribbons()
            , next(0) {
        }

        idStaticList<idRibbon*, 16> ribbons;
        int next;
    };

    idRibbonModelManager();
    ~idRibbonModelManager();

    void CreateRibbonEffectModelType(const idDeclRibbon* ribbonDecl);
    idRibbon* GetNextRibbonEffectModel(const idDeclRibbon* ribbonDecl);
    void Shutdown();

    idStaticList<ribbonEffects_t, 4> ribbonEffects;

private:
    int FindRibbonEffect(const idDeclRibbon* ribbonDecl) const;
};

class idRibbonManager {
public:
    idRibbonManager();
    ~idRibbonManager();

    void Init(const idDeclRibbon* ribbonDecl, idRenderModelBeam* beamModel,
        idRibbonModelManager* modelManager);
    void Shutdown();
    void StartRibbon(int spawnTime, const idVec3& spawnOrigin);
    void StopRibbon();
    bool UpdateRibbon(int time, const idVec3& origin, const idMat3& axis,
        const idVec3& velocity, const idVec4& color,
        const idVec3& translate);

    idRibbon* ribbon;
    const idDeclRibbon* ribbonDecl;
    idRenderModelBeam* beamModel;
    idRibbonModelManager* modelManager;
    bool isInitialized;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idRibbonModelManager::ribbonEffects_t) == 84,
    "Recovered ribbonEffects_t ABI changed");
static_assert(sizeof(idRibbonModelManager) == 352,
    "Recovered idRibbonModelManager ABI changed");
static_assert(sizeof(idRibbonManager) == 20,
    "Recovered idRibbonManager ABI changed");
#endif
