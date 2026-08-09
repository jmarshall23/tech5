#pragma once

#include "decls/decltypeinfo.h"
#include "idlib/math/vector.h"

class idMaterial;

class idDeclRibbon : public idDeclTypeInfo {
public:
    struct helix_t {
        float rotationScale;
        float radius;
        float velocity;
        idVec2 distortion0;
        idVec2 distortion1;
    };
    struct turbulence_t {
        float frequency;
        float magnitude;
        float velocity;
        idVec4 magic;
    };

    idDeclRibbon();
    idDeclInfo* GetDeclInfo() const override;

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
    helix_t helix;
    turbulence_t turbulence;

    static idDeclInfoTemplate<idDeclRibbon> resourceList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclRibbon::helix_t) == 28,
    "Recovered ribbon helix ABI changed");
static_assert(sizeof(idDeclRibbon::turbulence_t) == 28,
    "Recovered ribbon turbulence ABI changed");
static_assert(sizeof(idDeclRibbon) == 208,
    "Recovered ribbon declaration ABI changed");
#endif
