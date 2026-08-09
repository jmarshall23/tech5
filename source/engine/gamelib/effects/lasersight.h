#pragma once

#include "idlib/math/vector.h"

class idMaterial;
class idRenderModelBeam;
class idRenderModelDecal;

struct laserSightInfo_t {
    const idMaterial* laserBeamMtr;
    const idMaterial* laserDotMtr;
    float laserBeamHeight;
    float laserDotSize;
    float laserDotDepth;
    float laserDotMinSizeScale;
    float laserDotMaxSizeScale;
    bool laserDotQuad;
    float fadeIn;
    float fadeOut;
};

class idLaserBeam {
public:
    idLaserBeam();
    void Update(idRenderModelBeam* beamEffects, const idVec3& startPos,
        const idVec3& endPos, float fade);

    const idMaterial* material;
    float height;
};

class alignas(4) idLaserEndPoint {
public:
    const idMaterial* material;
    float size;
    float depth;
    int handle;
    bool quad;
};

class idLaserSight {
public:
    idLaserSight();
    ~idLaserSight();

    void Init(idRenderModelBeam* beamEffects,
        idRenderModelDecal* decalEffects, const idMaterial* laserBeamMtr,
        float laserBeamHeight, const idMaterial* laserPointMtr,
        float laserPointSize, float laserPointDepth, float fadeIn,
        float fadeOut, bool isQuad);
    void Shutdown();
    void Show(int startTime);
    void Hide();
    void Update(const idVec3& startPos, const idVec3& endPos,
        const idMat3& axis, float sizeScale, float fade);

    bool initialized;
    bool hidden;
    idLaserBeam laserBeam;
    idLaserEndPoint laserEndPoint;
    idRenderModelBeam* beamEffects;
    idRenderModelDecal* decalEffects;
    float fadeInDuration;
    float fadeOutDuration;
};

static_assert(sizeof(laserSightInfo_t) == 40,
    "Recovered laserSightInfo_t ABI changed");
static_assert(sizeof(idLaserBeam) == 8,
    "Recovered idLaserBeam ABI changed");
static_assert(sizeof(idLaserEndPoint) == 20,
    "Recovered idLaserEndPoint ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idLaserSight) == 48,
    "Recovered idLaserSight ABI changed");
#endif
