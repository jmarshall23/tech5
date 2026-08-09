#pragma once

#include "decls/decltypeinfo.h"
#include "idlib/math/vector.h"

class idDeclTable;
class idMaterial;

class idDeclElectricBolt : public idDeclTypeInfo {
public:
    struct branchOverride_t {
        const idMaterial* material;
        int frames;
        int width;
    };

    idDeclElectricBolt();
    idDeclInfo* GetDeclInfo() const override;

    const idMaterial* material;
    bool applyGradient;
    int revealTime;
    float startWidth;
    float endWidth;
    float maxDeviation;
    idVec4 color;
    float brightness;
    int subdivisions;
    float branchProbability;
    int maxBranchLevels;
    float branchStartWidth;
    float branchEndWidth;
    idVec2 branchLength;
    float maxBranchAngle;
    int branchSubdivisions;
    float maxBranchDeviation;
    const idDeclTable* jitterTable;
    const idDeclTable* jitterFalloffTable;
    float jitterDecay;
    float jitterSpeed;
    idVec2 jitterLeftMag;
    idVec2 jitterUpMag;
    bool useBranchOverride;
    branchOverride_t branchOverride;

    static idDeclInfoTemplate<idDeclElectricBolt> resourceList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclElectricBolt::branchOverride_t) == 12,
    "Recovered electric-bolt branch override ABI changed");
static_assert(sizeof(idDeclElectricBolt) == 196,
    "Recovered electric-bolt declaration ABI changed");
#endif
