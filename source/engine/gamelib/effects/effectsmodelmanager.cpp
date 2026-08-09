#include "gamelib/effects/effectsmodelmanager.h"

#include "idlib/lib_print.h"
#include "idlib/text/str.h"

// Renderer/decl access remains behind explicit PC-port boundaries until the
// renderer and decl translation units join the production source target.
const char* GameLib_GetParticleDeclName(const idDeclParticle* particleDecl);
idRenderModelParticle* GameLib_AllocParticleRenderModel(
    const char* modelName, const idDeclParticle* particleDecl);
void GameLib_RetireParticleRenderModel(idRenderModelParticle* model);
bool GameLib_ShowEffectsModelRecyclerStats();

namespace {

int ParticleNameHash(const char* const name) {
    int hash = 0;
    if (name != nullptr) {
        for (const unsigned char* cursor =
                 reinterpret_cast<const unsigned char*>(name);
             *cursor != 0; ++cursor) {
            hash = 31 * hash + *cursor;
        }
    }
    return hash;
}

void PrintRecyclerStats(const char* const action, const char* const name,
    const idEffectsModelManager& manager) {
    if (!GameLib_ShowEffectsModelRecyclerStats()) {
        return;
    }
    idLibPrint::Printf(
        "%s model %s, total models allocated %d inactive models spread %d "
        "active models spread %d\n",
        action, name, manager.fxPrtModels.Num(),
        manager.inactivePrtModelHash.GetSpread(),
        manager.activePrtModelHash.GetSpread());
}

} // namespace

idEffectsModelManager::idEffectsModelManager()
    : fxPrtModels()
    , activePrtModelHash(1024, 1024, TAG_HASHINDEX)
    , inactivePrtModelHash(1024, 1024, TAG_HASHINDEX) {
}

idEffectsModelManager::~idEffectsModelManager() {
    Shutdown();
}

void idEffectsModelManager::Init() {
    fxPrtModels.Clear();
    activePrtModelHash.Clear();
    activePrtModelHash.memTag = TAG_PARTICLE;
    inactivePrtModelHash.Clear();
    inactivePrtModelHash.memTag = TAG_PARTICLE;
}

void idEffectsModelManager::Shutdown() {
    activePrtModelHash.Clear();
    inactivePrtModelHash.Clear();
    for (int index = 0; index < fxPrtModels.Num(); ++index) {
        fxPrtModel_t& item = fxPrtModels[index];
        if (item.pmodel != nullptr) {
            GameLib_RetireParticleRenderModel(item.pmodel);
            item.pmodel = nullptr;
        }
    }
    fxPrtModels.Clear();
}

void idEffectsModelManager::RecycleParticleFxModel(
    const idDeclParticle* const particleDecl,
    idRenderModelParticle* const model) {
    if (model == nullptr || particleDecl == nullptr) {
        idLibPrint::Warning(
            "idFXModelRecycler::RecycleEffectModel : invalid model");
        return;
    }

    const char* const name = GameLib_GetParticleDeclName(particleDecl);
    const int key = ParticleNameHash(name);
    int index = activePrtModelHash.First(key);
    while (index != -1) {
        const fxPrtModel_t& item = fxPrtModels[index];
        if (item.pDecl == particleDecl && item.pmodel == model) {
            break;
        }
        index = activePrtModelHash.Next(index);
    }

    if (index == -1) {
        if (GameLib_ShowEffectsModelRecyclerStats()) {
            idLibPrint::Printf(
                "idEffectsModelManager::RecycleParticleFxModel : model %s "
                "not found in active list for recycling\n", name);
        }
        return;
    }

    activePrtModelHash.Remove(key, index);
    inactivePrtModelHash.Add(key, index);
    PrintRecyclerStats("Recycling", name, *this);
}

idRenderModelParticle* idEffectsModelManager::GetNextParticleEffectModel(
    const idDeclParticle* const particleDecl) {
    if (particleDecl == nullptr) {
        idLibPrint::Warning(
            "idEffectsModelManager::GetNextParticleEffectModel : "
            "particleDecl NULL");
        return nullptr;
    }

    const char* const name = GameLib_GetParticleDeclName(particleDecl);
    const int key = ParticleNameHash(name);
    int index = inactivePrtModelHash.First(key);
    while (index != -1) {
        const fxPrtModel_t& item = fxPrtModels[index];
        if (item.pDecl == particleDecl && item.pmodel != nullptr) {
            inactivePrtModelHash.Remove(key, index);
            activePrtModelHash.Add(key, index);
            PrintRecyclerStats("Found inactive", name, *this);
            return item.pmodel;
        }
        index = inactivePrtModelHash.Next(index);
    }

    if (fxPrtModels.Num() >= fxPrtModels.Max()) {
        idLibPrint::Warning(
            "idFXModelRecycler::GetParticleFxModel: Could not allocate "
            "model %s, out of slots", name);
        return nullptr;
    }

    idStr modelName(name);
    modelName.SetFileExtension("prt");
    idRenderModelParticle* const model = GameLib_AllocParticleRenderModel(
        modelName.c_str(), particleDecl);
    if (model == nullptr) {
        idLibPrint::Warning(
            "idFXModelRecycler::GetParticleFxModel: Could not allocate a "
            "rendermodel for '%s'", name);
        return nullptr;
    }

    const fxPrtModel_t item = {model, particleDecl};
    index = fxPrtModels.Append(item);
    activePrtModelHash.Add(key, index);
    PrintRecyclerStats("Allocated new", name, *this);
    return model;
}
