#pragma once

#include "idlib/math/vector.h"

class idDeclRibbon;
class idMaterial;
class idRenderModelBeam;

enum ribbonState_t : int {
    RIBBON_ACTIVE = 0,
    RIBBON_DEACTIVATING = 1,
    RIBBON_INACTIVE = 2
};

struct idRibbonParameters {
    const idMaterial* material;
    int duration;
    float maxLength;
    float fadeInFraction;
    float fadeOutFraction;
    idVec3 gravity;
    idVec3 velocity;
    float startWidth;
    float endWidth;
    idVec4 color;
    bool viewOriented;
    bool reorientNodes;
    bool textureRepeat;
    bool textureRepeatStretch;
    float textureTMin;
    float textureTMax;
    float nodeSubdivision;
    float minNodeDistance;
    float helixRotationScale;
    float helixRadius;
    float helixVelocity;
    idVec2 helixDistortion0;
    idVec2 helixDistortion1;
    float turbulenceFrequency;
    float turbulenceMagnitude;
    float turbulenceVelocity;
    idVec4 turbulenceMagic;
};

class alignas(4) idRibbon {
public:
    static constexpr int MAX_NODES = 128;

    struct ribbonNode_t {
        idVec3 origin;
        idVec3 origin2;
        idVec3 velocity;
        idVec3 orientVec;
        idVec4 color;
        int spawnTime;
        float nodeLength;
    };

    explicit idRibbon(const idDeclRibbon* decl);

    void StartRibbon(int time, const idVec3& origin);
    void StopRibbon() {
        if (ribbonState == RIBBON_ACTIVE) ribbonState = RIBBON_DEACTIVATING;
    }
    void UpdatePosition(int currentTime, const idVec3& origin,
        const idMat3& axis, const idVec3& velocity, const idVec4& color);
    void UpdatePosition(int currentTime, const idVec3& origin,
        const idVec3& origin2, const idMat3& axis,
        const idVec3& velocity, const idVec4& color);
    void UpdateGeometry(int currentTime, idRenderModelBeam* beamModel,
        const idMat3& viewAxis, const idVec3& viewOrigin);
    void RemoveOldNodes(int currentTime);
    int GetRemainingTime(int currentTime) const;

    ribbonState_t ribbonState;
    idVec3 spawnOrg;
    int spawnTime;
    int numActiveNodes;
    int currHeadIdx;
    float startVariance;
    int prevTime;
    idVec3 prevOrigin;
    idVec3 prevOrigin2;
    const idDeclRibbon* ribbonDecl;
    idVec4 globalColor;
    ribbonNode_t ribbonNodes[MAX_NODES];
    bool explicitDefineBothEdges;

private:
    void ResetNodes();
    void AddNode(int currentTime, const idVec3& origin,
        const idVec3& origin2, const idMat3& axis,
        const idVec3& velocity, const idVec4& color);
    void CalcTurbulence(const idVec3& origin, const idMat3& axis,
        idVec3& turbulence) const;
    void CalcHelix(int currentTime, const idVec3& origin,
        const idMat3& axis, const idVec3& velocity, idVec3& helix) const;
};

static_assert(sizeof(idRibbon::ribbonNode_t) == 72,
    "Recovered ribbon node ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idRibbon) == 9300,
    "Recovered idRibbon ABI changed");
#endif
