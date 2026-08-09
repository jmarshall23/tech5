#include "gamelib/effects/ribbonmanager.h"

idRibbonModelManager::idRibbonModelManager()
    : ribbonEffects() {
}

idRibbonModelManager::~idRibbonModelManager() {
    Shutdown();
}

int idRibbonModelManager::FindRibbonEffect(
    const idDeclRibbon* const ribbonDecl) const {
    for (int index = 0; index < ribbonEffects.Num(); ++index) {
        const ribbonEffects_t& effect = ribbonEffects[index];
        if (!effect.ribbons.IsEmpty() && effect.ribbons[0] != nullptr &&
            effect.ribbons[0]->ribbonDecl == ribbonDecl) {
            return index;
        }
    }
    return -1;
}

void idRibbonModelManager::CreateRibbonEffectModelType(
    const idDeclRibbon* const ribbonDecl) {
    if (ribbonDecl == nullptr || FindRibbonEffect(ribbonDecl) >= 0 ||
        ribbonEffects.Num() >= ribbonEffects.Max()) {
        return;
    }
    ribbonEffects_t* const effect = ribbonEffects.Alloc();
    if (effect == nullptr) {
        return;
    }
    effect->next = 0;
    for (int index = 0; index < effect->ribbons.Max(); ++index) {
        effect->ribbons.Append(new idRibbon(ribbonDecl));
    }
}

idRibbon* idRibbonModelManager::GetNextRibbonEffectModel(
    const idDeclRibbon* const ribbonDecl) {
    const int index = FindRibbonEffect(ribbonDecl);
    if (index < 0) {
        return nullptr;
    }
    ribbonEffects_t& effect = ribbonEffects[index];
    if (effect.ribbons.IsEmpty()) {
        return nullptr;
    }
    idRibbon* const result = effect.ribbons[effect.next];
    effect.next = (effect.next + 1) % effect.ribbons.Num();
    return result;
}

void idRibbonModelManager::Shutdown() {
    for (int effectIndex = 0; effectIndex < ribbonEffects.Num();
         ++effectIndex) {
        ribbonEffects_t& effect = ribbonEffects[effectIndex];
        for (int ribbonIndex = 0; ribbonIndex < effect.ribbons.Num();
             ++ribbonIndex) {
            delete effect.ribbons[ribbonIndex];
        }
        effect.ribbons.Clear();
        effect.next = 0;
    }
    ribbonEffects.Clear();
}

idRibbonManager::idRibbonManager()
    : ribbon(nullptr)
    , ribbonDecl(nullptr)
    , beamModel(nullptr)
    , modelManager(nullptr)
    , isInitialized(false) {
}

idRibbonManager::~idRibbonManager() {
    Shutdown();
    ribbonDecl = nullptr;
    beamModel = nullptr;
    modelManager = nullptr;
}

void idRibbonManager::Init(const idDeclRibbon* const ribbonDecl_,
    idRenderModelBeam* const beamModel_,
    idRibbonModelManager* const modelManager_) {
    if (ribbonDecl_ == nullptr || beamModel_ == nullptr ||
        modelManager_ == nullptr) {
        return;
    }
    ribbonDecl = ribbonDecl_;
    beamModel = beamModel_;
    modelManager = modelManager_;
    modelManager->CreateRibbonEffectModelType(ribbonDecl);
    isInitialized = true;
}

void idRibbonManager::Shutdown() {
    StopRibbon();
    ribbon = nullptr;
    isInitialized = false;
}

void idRibbonManager::StartRibbon(const int spawnTime,
    const idVec3& spawnOrigin) {
    if (ribbonDecl == nullptr || modelManager == nullptr) {
        return;
    }
    ribbon = modelManager->GetNextRibbonEffectModel(ribbonDecl);
    if (ribbon != nullptr) {
        ribbon->StartRibbon(spawnTime, spawnOrigin);
    }
}

void idRibbonManager::StopRibbon() {
    if (ribbon != nullptr) {
        ribbon->StopRibbon();
    }
}

bool idRibbonManager::UpdateRibbon(const int time, const idVec3& origin,
    const idMat3& axis, const idVec3& velocity, const idVec4& color,
    const idVec3& translate) {
    if (ribbon == nullptr) {
        return false;
    }
    ribbon->RemoveOldNodes(time);
    ribbon->UpdatePosition(time, origin, axis, velocity, color);
    ribbon->UpdateGeometry(time, beamModel, axis, translate);
    return ribbon->ribbonState != RIBBON_INACTIVE;
}
