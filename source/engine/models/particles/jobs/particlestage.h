#pragma once

#include "idlib/bv/bounds.h"
#include "idlib/geometry/drawvert.h"
#include "idlib/math/matrix.h"
#include "models/particles/jobs/particleparm.h"

#include <cstdint>

class idMaterial;
class idStaticParticleModelData;

enum prtDistributionType_t : int {
    PDIST_RECT = 0,
    PDIST_CYLINDER,
    PDIST_SPHERE,
    PDIST_RECT_SURFACE,
    PDIST_CYLINDER_SURFACE,
    PDIST_SPHERE_SURFACE,
    NUM_PDIST_TYPES
};

enum prtDirectionType_t : int {
    PDIR_CONE = 0,
    PDIR_OUTWARD,
    PDIR_SPEED,
    NUM_PDIR_TYPES
};

enum prtCustomPthType_t : int {
    PPATH_STANDARD = 0,
    PPATH_HELIX,
    PPATH_FLIES,
    PPATH_ORBIT,
    PPATH_DRIP,
    NUM_PCUSTOM_TYPES
};

enum prtOrientationType_t : int {
    POR_VIEW = 0,
    POR_TRAIL,
    POR_AIMED,
    POR_X,
    POR_Y,
    POR_Z,
    POR_XYZ,
    NUM_POR_TYPES
};

enum prtTextureFlipMode_t : int {
    PTEXTURE_FLIP_NONE = 0,
    PTEXTURE_FLIP_RANDOM,
    PTEXTURE_FLIP_ALWAYS,
    NUM_PTEXTURE_FLIP_TYPES
};

enum prtAnimationType_t : int {
    PANIM_TYPE_CYLE_RATE = 0,
    PANIM_TYPE_SINGLE_CYCLE_RATE,
    PANIM_TYPE_SINGLE_CYCLE,
    NUM_PANIM_TYPES
};

enum prtSortType_t : int {
    PSORT_TYPE_NONE = 0,
    PSORT_TYPE_NEWEST_TO_OLDEST,
    PSORT_TYPE_OLDEST_TO_NEWEST,
    NUM_PSORT_TYPES
};

class idParticleStage {
public:
    struct materialTraits_t {
        idVec4 atlasScaleBias;
        bool hasEmissivePass;
        bool usesTransSortAtlas;
        bool isTransparencySorted;
        bool alphaBlended;

        materialTraits_t()
            : atlasScaleBias(1.0f, 1.0f, 0.0f, 0.0f),
              hasEmissivePass(false), usesTransSortAtlas(false),
              isTransparencySorted(false), alphaBlended(false) {}
    };
    using MaterialTraitsCallback = bool (*)(const idMaterial* material,
        materialTraits_t& traits);
    using DefaultMaterialCallback = const idMaterial* (*)();

    struct prtStageProperties_t {
        const idMaterial* material;
        std::int16_t totalParticles;
        std::int16_t cycles;
        int diversity;
        idParticleParm particleLife;
        float timeOffset;
        idParticleParm deadTime;
        float useSysTime;
        float spawnBunching;
        float emissionTime;
        prtTextureFlipMode_t textureFlipS;
        prtTextureFlipMode_t textureFlipT;
        idParticleParm windBias;
        prtSortType_t sortType;
        float boundsExpansion;
        bool randomOnCycle;
    };

    struct prtDistribution_t {
        prtDistributionType_t type;
        idParticleParm size[3];
        bool random;
    };

    struct prtOrientation_t {
        prtOrientationType_t type;
        std::int16_t numTrails;
        float segmentLength;
        float viewFade;
        bool orientToVelOnly;
        bool world;
        bool aimedSafeQuad;
        float aimedSafeQuadAlign;
        float depthOffset;
    };

    struct prtDirection_t {
        prtDirectionType_t type;
        float parms[4];
        float angleOffsetStart[2];
        float angleOffsetRange[2];
        idMat3 coneAxis;
    };

    struct prtSpeed_t { idParticleParm speed[3]; };
    struct prtAcceleration_t {
        idParticleParm acceleration[3];
        bool world;
    };
    struct prtGravity_t {
        idParticleParm gravity;
        bool world;
    };
    struct prtFriction_t { idParticleParm friction[3]; };
    struct prtOffset_t { idParticleParm offset[3]; };
    struct prtSpawnLocation_t { idParticleParm spawnLocation[3]; };

    struct prtColorAttributes_t {
        idParticleParm baseColor[4];
        idVec4 fadeColor;
        float fadeInFraction;
        float fadeOutFraction;
        float fadeIndexFraction;
        float softParticleAlphaScale;
        idParticleParm brightness;
        bool useGlobalShadows;
        float minShadowVal;
        float entityColorBlendVal;
    };

    struct prtRotation_t {
        idParticleParm rotation[3];
        bool allowRotDirOverride;
    };
    struct prtInitialRotation_t { idParticleParm initialAngle[3]; };
    struct prtPivot_t { idVec2 pivotOffset; };
    struct prtSize_t {
        idParticleParm size[3];
        idParticleParm aspectRatio;
    };

    struct prtTexAnimation_t {
        prtAnimationType_t type;
        std::uint16_t numColumns;
        std::uint16_t numRows;
        idParticleParm rate;
        std::int16_t startFrame;
        bool useRandomRow;
        bool useFrameBlending;
    };

    struct prtCustomPath_t {
        prtCustomPthType_t type;
        idParticleParm parms[5];
    };
    struct prtGenericParms_t { idParticleParm genericParm[4]; };
    struct prtLODParms_t {
        float sizeScale;
        float lerpAmount;
        std::int16_t radius;
        std::int16_t totalParticles;
    };

    idParticleStage();
    void Default(const idLookupTable* tables = nullptr);
    void SetMaterial(const idMaterial* material);
    void SetStaticMesh(const idStaticParticleModelData* data,
        const idDrawVert* vertices = nullptr, int vertexCount = 0);
    static void SetMaterialCallbacks(MaterialTraitsCallback traits,
        DefaultMaterialCallback defaultMaterial);
    int NumVertsPerParticle() const;
    void CalculateBounds(const idLookupTable* tables);

    const idStaticParticleModelData* staticData;
    const idDrawVert* staticVerts;
    int numStaticVerts;
    int cycleMsec;
    float maxParticleLife;
    float maxDeadTime;
    float bunchTime;
    idBounds bounds;
    idVec4 atlasScaleBias;
    std::uint8_t reserved : 3;
    std::uint8_t hidden : 1;
    std::uint8_t hasEmissivePass : 1;
    std::uint8_t usesTransSortAtlas : 1;
    std::uint8_t isTransparencySorted : 1;
    std::uint8_t alphaBlended : 1;
    prtStageProperties_t systemProperties;
    prtDistribution_t distribution;
    prtOrientation_t orientation;
    prtDirection_t direction;
    prtSpeed_t speed;
    prtAcceleration_t acceleration;
    prtGravity_t gravity;
    prtFriction_t friction;
    prtOffset_t offset;
    prtSpawnLocation_t spawnLocation;
    prtColorAttributes_t colorAttributes;
    prtRotation_t rotation;
    prtInitialRotation_t initialRotation;
    prtPivot_t pivot;
    prtSize_t size;
    prtTexAnimation_t texAnimation;
    prtCustomPath_t customPath;
    prtGenericParms_t genericParm;
    prtLODParms_t lodParms;

private:
    static MaterialTraitsCallback materialTraitsCallback;
    static DefaultMaterialCallback defaultMaterialCallback;
};

#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idParticleStage) == 0x4EC,
    "Recovered particle-stage ABI changed");
#endif
