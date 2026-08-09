#include "gamelib/effects/lensflaremanager.h"

bool GameLib_CreateFlareModels(idRenderWorld* renderWorld,
    const idDeclFlare* flareDecl, idRenderModelFlare*& flareModel,
    idRenderModelFlareOcclusionQuad*& occlusionModel);
void GameLib_DeleteFlareModel(idRenderModelFlare* flareModel,
    idRenderModelFlareOcclusionQuad* occlusionModel);
void GameLib_ConfigureFlareModels(idRenderModelFlare* flareModel,
    idRenderModelFlareOcclusionQuad* occlusionModel, float quadScale,
    bool autosprited, bool sunFlare);
void GameLib_UpdateFlareModels(idRenderModelFlare* flareModel,
    idRenderModelFlareOcclusionQuad* occlusionModel,
    const idVec3& flareOrigin, const idVec3& occlusionOrigin,
    const idMat3& axis, float fadeStartRange, float fadeEndRange,
    const idVec4& color, float coverage, bool hidden);
void GameLib_ApplyFlareCoverage(idRenderModelFlare* flareModel,
    float coverage);
void GameLib_ApplyFlareColor(idRenderModelFlare* flareModel,
    const idVec4& color);

idLensFlareManager::idLensFlareManager()
    : flareRenderModel(nullptr)
    , flareOcclusionQuadModel(nullptr)
    , sunDirection()
    , occlusionOffset()
    , isAutosprited(false)
    , isInitialized(false) {
    sunDirection.Zero();
    occlusionOffset.Zero();
}

idLensFlareManager::~idLensFlareManager() {
    if (flareRenderModel != nullptr || flareOcclusionQuadModel != nullptr) {
        GameLib_DeleteFlareModel(flareRenderModel,
            flareOcclusionQuadModel);
    }
    flareRenderModel = nullptr;
    flareOcclusionQuadModel = nullptr;
    isInitialized = false;
}

void idLensFlareManager::Init(idRenderWorld* const renderWorld,
    const idDeclFlare* const flareDecl, const float quadSize,
    const idVec3& sunDirection_, const idVec3& occlusionOffset_,
    const bool isAutosprited_) {
    if (flareDecl == nullptr) {
        return;
    }
    sunDirection = sunDirection_;
    occlusionOffset = occlusionOffset_;
    isAutosprited = isAutosprited_;
    if (!GameLib_CreateFlareModels(renderWorld, flareDecl,
            flareRenderModel, flareOcclusionQuadModel)) {
        flareRenderModel = nullptr;
        flareOcclusionQuadModel = nullptr;
        return;
    }
    const bool sunFlare = sunDirection.LengthSqr() > 0.0f;
    const float quadScale = quadSize < 8.0f ? 8.0f - quadSize : 0.0f;
    GameLib_ConfigureFlareModels(flareRenderModel,
        flareOcclusionQuadModel, quadScale, isAutosprited, sunFlare);
    isInitialized = true;
}

void idLensFlareManager::ApplyFade(const float fade) {
    if (flareRenderModel != nullptr) {
        GameLib_ApplyFlareCoverage(flareRenderModel, fade);
    }
}

void idLensFlareManager::ApplyColor(const idVec4& color) {
    if (flareRenderModel != nullptr) {
        GameLib_ApplyFlareColor(flareRenderModel, color);
    }
}

void idLensFlareManager::StartFlare(const idVec3& origin,
    const idMat3& axis, const idVec4& color, const float fadeStartRange,
    const float fadeEndRange) {
    if (!isInitialized || flareRenderModel == nullptr ||
        flareOcclusionQuadModel == nullptr) {
        return;
    }
    const bool sunFlare = sunDirection.LengthSqr() > 0.0f;
    const idVec3 flareOrigin = sunFlare ? sunDirection : origin;
    const idVec3 quadOrigin = sunFlare
        ? sunDirection : origin + occlusionOffset;
    GameLib_UpdateFlareModels(flareRenderModel, flareOcclusionQuadModel,
        flareOrigin, quadOrigin, axis, fadeStartRange, fadeEndRange,
        color, 1.0f, false);
}

void idLensFlareManager::StopFlare() {
    if (flareRenderModel == nullptr || flareOcclusionQuadModel == nullptr) {
        return;
    }
    GameLib_UpdateFlareModels(flareRenderModel, flareOcclusionQuadModel,
        idVec3(0.0f, 0.0f, 0.0f), idVec3(0.0f, 0.0f, 0.0f),
        idMat3(1.0f), 0.0f, 0.0f,
        idVec4(1.0f, 1.0f, 1.0f, 1.0f), 0.0f, true);
}

void idLensFlareManager::Update(const idVec3& origin,
    const idMat3& axis, const int time, const bool bindOrigin,
    const bool bindAxis) {
    (void)time;
    if (!isInitialized || flareRenderModel == nullptr ||
        flareOcclusionQuadModel == nullptr) {
        return;
    }
    if (sunDirection.LengthSqr() == 0.0f && (bindOrigin || bindAxis)) {
        const idVec3 flareOrigin = bindOrigin ? origin : sunDirection;
        const idVec3 quadOrigin = flareOrigin + occlusionOffset;
        GameLib_UpdateFlareModels(flareRenderModel,
            flareOcclusionQuadModel, flareOrigin, quadOrigin,
            bindAxis ? axis : idMat3(1.0f), 0.0f, 0.0f,
            idVec4(1.0f, 1.0f, 1.0f, 1.0f), 1.0f, false);
    }
}
