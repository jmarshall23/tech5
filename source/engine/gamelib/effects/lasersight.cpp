#include "gamelib/effects/lasersight.h"

#include <algorithm>

void GameLib_DrawLaserBeam(idRenderModelBeam* beamModel,
    const idMaterial* material, const idVec3& start,
    const idVec3& end, float halfWidth, unsigned char alpha);
int GameLib_CreateLaserDecal(idRenderModelDecal* decalModel,
    const idMaterial* material, int startTime, float size, float depth,
    bool quad);
void GameLib_RemoveLaserDecal(idRenderModelDecal* decalModel, int handle);
void GameLib_UpdateLaserDecal(idRenderModelDecal* decalModel, int handle,
    const idVec3& position, const idMat3& axis, float sizeScale);

idLaserBeam::idLaserBeam()
    : material(nullptr)
    , height(1.0f) {
}

void idLaserBeam::Update(idRenderModelBeam* const beamEffects,
    const idVec3& startPos, const idVec3& endPos, const float fade) {
    if (beamEffects == nullptr) {
        return;
    }
    const int alpha = static_cast<int>(fade * 255.9f);
    GameLib_DrawLaserBeam(beamEffects, material, startPos, endPos,
        height * 0.5f, static_cast<unsigned char>(
            (std::max)(0, (std::min)(255, alpha))));
}

idLaserSight::idLaserSight()
    : initialized(false)
    , hidden(false)
    , laserBeam()
    , laserEndPoint{nullptr, 1.0f, 8.0f, -1, false}
    , beamEffects(nullptr)
    , decalEffects(nullptr)
    , fadeInDuration(1.0f)
    , fadeOutDuration(1.0f) {
}

idLaserSight::~idLaserSight() {
    Shutdown();
    beamEffects = nullptr;
    decalEffects = nullptr;
}

void idLaserSight::Init(idRenderModelBeam* const beamEffects_,
    idRenderModelDecal* const decalEffects_,
    const idMaterial* const laserBeamMtr, const float laserBeamHeight,
    const idMaterial* const laserPointMtr, const float laserPointSize,
    const float laserPointDepth, const float fadeIn, const float fadeOut,
    const bool isQuad) {
    beamEffects = beamEffects_;
    decalEffects = decalEffects_;
    laserBeam.material = laserBeamMtr;
    laserBeam.height = laserBeamHeight;
    laserEndPoint.material = laserPointMtr;
    laserEndPoint.size = laserPointSize;
    laserEndPoint.depth = laserPointDepth;
    laserEndPoint.quad = isQuad;
    laserEndPoint.handle = -1;
    fadeInDuration = fadeIn;
    fadeOutDuration = fadeOut;
    initialized = true;
    hidden = false;
}

void idLaserSight::Shutdown() {
    initialized = false;
    if (decalEffects != nullptr && laserEndPoint.handle != -1) {
        GameLib_RemoveLaserDecal(decalEffects, laserEndPoint.handle);
        laserEndPoint.handle = -1;
    }
}

void idLaserSight::Show(const int startTime) {
    if (!initialized || !hidden) {
        return;
    }
    hidden = false;
    if (decalEffects != nullptr && laserEndPoint.material != nullptr) {
        laserEndPoint.handle = GameLib_CreateLaserDecal(decalEffects,
            laserEndPoint.material, startTime, laserEndPoint.size,
            laserEndPoint.depth, laserEndPoint.quad);
    }
}

void idLaserSight::Hide() {
    if (!initialized || hidden) {
        return;
    }
    hidden = true;
    if (decalEffects != nullptr && laserEndPoint.handle != -1) {
        GameLib_RemoveLaserDecal(decalEffects, laserEndPoint.handle);
        laserEndPoint.handle = -1;
    }
}

void idLaserSight::Update(const idVec3& startPos, const idVec3& endPos,
    const idMat3& axis, const float sizeScale, const float fade) {
    if (hidden) {
        return;
    }
    laserBeam.Update(beamEffects, startPos, endPos, fade);
    if (decalEffects != nullptr && laserEndPoint.handle != -1) {
        GameLib_UpdateLaserDecal(decalEffects, laserEndPoint.handle,
            endPos, axis, sizeScale * fade);
    }
}
