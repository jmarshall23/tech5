#pragma once

#include "idlib/math/vector.h"

class idDeclFlare;
class idRenderModelFlare;
class idRenderModelFlareOcclusionQuad;
class idRenderWorld;

class alignas(4) idLensFlareManager {
public:
    idLensFlareManager();
    ~idLensFlareManager();

    void Init(idRenderWorld* renderWorld, const idDeclFlare* flareDecl,
        float quadSize, const idVec3& sunDirection,
        const idVec3& occlusionOffset, bool isAutosprited);
    void StartFlare(const idVec3& origin, const idMat3& axis,
        const idVec4& color, float fadeStartRange, float fadeEndRange);
    void StopFlare();
    void Update(const idVec3& origin, const idMat3& axis, int time,
        bool bindOrigin, bool bindAxis);
    void ApplyFade(float fade);
    void ApplyColor(const idVec4& color);

    idRenderModelFlare* flareRenderModel;
    idRenderModelFlareOcclusionQuad* flareOcclusionQuadModel;
    idVec3 sunDirection;
    idVec3 occlusionOffset;
    bool isAutosprited;
    bool isInitialized;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idLensFlareManager) == 36,
    "Recovered idLensFlareManager ABI changed");
#endif
