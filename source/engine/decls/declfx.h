#pragma once

#include "decls/declfxtypes.h"
#include "decls/decltypeinfo.h"
#include "idlib/containers/staticlist.h"
#include "idlib/math/vector.h"

class idDeclEnv;
class idDeclFlare;
class idDeclParticle;
class idDeclRenderParm;
class idDeclRibbon;
class idDeclTable;
class idFile;
class idMaterial;
class idParser;
class idSoundShader;

struct idFXRenderParm {
    const idDeclRenderParm* parm;
    idVec4 value;
};

class alignas(4) idFXSingleAction {
public:
    struct fxLightParms_t {
        idVec3 radius;
        float intensity;
        const idMaterial* lightMtr;
    };
    struct fxParticleParms_t {
        bool trackVelocity;
        float velocityScale;
        float minVelocity;
        bool useSmokeSystem;
        int smokeSystemRate;
        float trailSpacing;
        bool isScreenPrt;
        float screenPrtExcludeAngle;
        const idDeclParticle* declPrt;
    };
    struct fxDecalParms_t {
        float angle;
        float depth;
        const idMaterial* decalMtr;
    };
    struct fxModelParms_t {
        idAtomicString modelName;
        const idMaterial* customMaterial;
    };
    struct fxSoundParms_t {
        soundChannel_t channel;
        const idSoundShader* sound;
    };
    struct fxScreenShakeParms_t {
        float magnitude;
        idAngles maxAngles;
        idVec3 maxOffset;
    };
    struct fxControllerShakeParms_t {
        float highMag;
        float lowMag;
        float highDuration;
        float lowDuration;
    };
    struct fxWindParms_t {
        float angle;
        float multiplier;
        idVec2 strength;
    };
    struct fxRenderParmParms_t {
        const idDeclRenderParm* declRenderParm;
    };
    struct fxEnvParms_t {
        const idDeclEnv* declEnv;
        idStaticList<idFXRenderParm, 16> envRenderParm;
    };
    struct fxRadialBlurParms_t {
        float maxScale;
    };
    struct fxFlareParms_t {
        idVec3 position;
        bool isAutosprited;
        const idDeclFlare* declFlare;
    };
    struct fxRibbonParms_t {
        const idDeclRibbon* declRibbon;
    };

    idFXSingleAction();
    void Default();

    idAtomicString name;
    idAtomicString group;
    fxActionType_t type;
    float duration;
    idVec2 delay;
    bool restart;
    bool looping;
    float fadeInTime;
    float fadeOutTime;
    float fadeStartDistance;
    float distance;
    float size;
    idVec4 color;
    bool noshadows;
    idAtomicString fire;
    fxMultiTagUseType_t multiTagUseType;
    idList<idAtomicString, 109> tagNames;
    idList<fxCondition_t, 109> startCondition;
    idList<fxCondition_t, 109> stopCondition;
    idList<fxExtraCondition_t, 109> extraCondition;
    fxOriginType_t originType;
    idVec3 offset;
    fxRotationType_t rotationType;
    idAngles rotOffsetAngles;
    idVec2 rndRotX;
    idVec2 rndRotY;
    idVec2 rndRotZ;
    idAngles explicitAngles;
    const idDeclTable* rotateTablePitch;
    const idDeclTable* rotateTableYaw;
    const idDeclTable* rotateTableRoll;
    const idDeclTable* colorTableRGB;
    const idDeclTable* colorTableA;
    const idDeclTable* customTable1;
    const idDeclTable* customTable2;
    const idDeclRenderParm* customRenderParm;
    fxLightParms_t lightParms;
    fxParticleParms_t particleParms;
    fxDecalParms_t decalParms;
    fxModelParms_t modelParms;
    fxSoundParms_t soundParms;
    fxScreenShakeParms_t screenShakeParms;
    fxControllerShakeParms_t controllerShakeParms;
    fxWindParms_t windParms;
    fxRenderParmParms_t renderParmParms;
    fxEnvParms_t envParms;
    fxRadialBlurParms_t radialBlurParms;
    fxFlareParms_t flareParms;
    fxRibbonParms_t ribbonParms;
    idMat3 axis;
    idMat3 rotOffset;
    bool implicit;
    bool triggered;
};

class alignas(4) idDeclFX : public idDecl {
public:
    idDeclFX();
    ~idDeclFX() override;

    idDeclInfo* GetDeclInfo() const override;
    bool RebuildTextSource() override;
    const char* DefaultDefinition() const override;
    void Parse(idParser* parser) override;
    void FreeData() override;
    unsigned int Size() const override;

    int GetMaxDuration(fxCondition_t startCondition) const;
    int GetMaxFadeOutTime(fxCondition_t startCondition) const;

    static const char* FXActionTypeToName(fxActionType_t type);
    static const char* FXConditionToName(fxCondition_t condition);

    idList<idFXSingleAction, 109> editEvents;
    idList<idFXSingleAction, 109> events;
    int changeId;

    static idDeclInfoTemplate<idDeclFX> resourceList;

private:
    void WriteSingleFXAction(idFile& file,
        const idFXSingleAction& action) const;
    void ParseSingleFXAction(idParser& parser, idFXSingleAction& action);
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idFXRenderParm) == 20,
    "Recovered FX render-parm ABI changed");
static_assert(sizeof(idFXSingleAction::fxParticleParms_t) == 36,
    "Recovered FX particle-parm ABI changed");
static_assert(sizeof(idFXSingleAction::fxEnvParms_t) == 340,
    "Recovered FX environment-parm ABI changed");
static_assert(sizeof(idFXSingleAction) == 832,
    "Recovered FX action ABI changed");
static_assert(sizeof(idDeclFX) == 92,
    "Recovered FX declaration ABI changed");
#endif
