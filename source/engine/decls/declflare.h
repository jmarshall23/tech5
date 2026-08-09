#pragma once

#include "decls/decltypeinfo.h"
#include "idlib/math/vector.h"

class idMaterial;

class idDeclFlare : public idDeclTypeInfo {
public:
    struct alignas(4) subFlare_t {
        float width;
        float height;
        float minScaleX;
        float minScaleY;
        float viewScaleX;
        float viewScaleY;
        float coneAngle;
        float maxDistScaleX;
        float maxDistScaleY;
        float scaleDistance;
        float position;
        idVec4 color;
        const idMaterial* mtr;
        bool reflectX;
        bool reflectY;
    };

    idDeclFlare();
    idDeclInfo* GetDeclInfo() const override;

    idList<subFlare_t, 79> subflares;
    unsigned char reservedFlags : 7;
    unsigned char useAltViewVecCalc : 1;
    float viewAngleFade;
    float invViewAngleFade;
    float brightness;

    static idDeclInfoTemplate<idDeclFlare> resourceList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclFlare::subFlare_t) == 68,
    "Recovered sub-flare ABI changed");
static_assert(sizeof(idDeclFlare) == 96,
    "Recovered flare declaration ABI changed");
#endif
