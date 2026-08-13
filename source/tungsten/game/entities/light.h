#pragma once

#include "game/editor/entityinterfacelocal.h"
#include "game/entities/entity.h"

class idDeclEnv;
class idIESfile;
class idLight;

enum lightClass_t : int {
    LIGHT_NORMAL = 0,
    LIGHT_PRELIGHT_ONLY = 1,
    LIGHT_SLOWLIGHT_DYNAMIC_ONLY = 2,
    LIGHT_SLOWLIGHT_PRIVATE_ONLY = 3,
    LIGHT_DYNAMIC_ONLY = 4,
    LIGHT_PRIVATE_DYNAMIC_ONLY = 5,
    LIGHT_PRIVATE_PRIME = 6,
    LIGHT_BLENDED_ONLY = 7
};

enum lightType_t : int {
    LIGHT_POINT = 0,
    LIGHT_SPOT = 1,
    LIGHT_PARALLEL = 2,
    LIGHT_REAL = 3,
    LIGHT_MAX_TYPES = 4
};

enum lightFallOff_t : int {
    LIGHT_FALLOFF_TEXTURE = 0,
    LIGHT_FALLOFF_LINEAR = 1,
    LIGHT_FALLOFF_INV_SQUARE = 2,
    LIGHT_FALLOFF_RADIAL = 3
};

struct idLightRenderState {
    idVec3 origin = idVec3(0.0f, 0.0f, 0.0f);
    idMat3 axis = idMat3(1.0f);
    idVec3 target = idVec3(64.0f, 0.0f, 0.0f);
    idVec3 right = idVec3(0.0f, -64.0f, 0.0f);
    idVec3 up = idVec3(0.0f, 0.0f, 64.0f);
    idVec3 start = idVec3(0.0f, 0.0f, 0.0f);
    idVec3 end = idVec3(64.0f, 0.0f, 0.0f);
    idVec3 center = idVec3(0.0f, 0.0f, 0.0f);
    idVec3 radius = idVec3(320.0f, 320.0f, 320.0f);
    idColor color = idColor(1.0f, 1.0f, 1.0f, 1.0f);
    const idMaterial* shader = nullptr;
    const idIESfile* iesFile = nullptr;
    lightType_t type = LIGHT_POINT;
    lightClass_t lightClass = LIGHT_NORMAL;
    lightFallOff_t falloff = LIGHT_FALLOFF_TEXTURE;
    idVec3 dynamicModelLightingScale = idVec3(1.0f, 1.0f, 1.0f);
    idVec3 staticSpecularVector = idVec3(0.0f, 0.707f, 0.707f);
    float staticSpecularScale = 10.0f;
    float dimShadowStretch = 1.0f;
    float areaLightSize = 8.0f;
    float iesPowerScale = 1.0f;
    float iesAreaScale = 1.0f;
    int slowMultiPass = 1;
    bool noShadows = false;
    bool slowLight = false;
    bool bakedParallelShadows = false;
};

class idLightServices {
public:
    virtual ~idLightServices() = default;
    virtual idRenderLight* AllocateRenderLight(idLight& light);
    virtual void FreeRenderLight(idRenderLight* renderLight);
    virtual void CommitRenderLight(idLight& light,
        const idLightRenderState& state);
    virtual int GetScaledGameMilliseconds() const;
    virtual const idMaterial* FindMaterial(const char* name) const;
    virtual void PresentModelDefChange(idLight& light);
    virtual void ShowLightEditor(idLight& light);
    virtual void UpdateLightEditor(idLight& light);
    virtual void LinkLightToTarget(idLight& light, idEntity& target,
        bool additiveBlend);
    virtual void AddEnvironmentArea(idLight& light,
        const idBounds& bounds, const idDeclEnv* declaration);
    virtual bool HasGlobalShadows() const;
    virtual bool IsComboMapWithoutPrelights() const;
    virtual void ReportWarning(const idLight& light, const char* message);
};

class idLight : public idEntity {
public:
    struct idSpotLight {
        idVec3 lightTarget;
        idVec3 lightRight;
        idVec3 lightUp;
        idVec3 lightStart;
        idVec3 lightEnd;
    };
    struct idSoundInfo {
        const idSoundShader* shader = nullptr;
        bool waitForTrigger = false;
    };

    idLight();
    ~idLight() override;

    static void SetServices(idLightServices* services);
    static idLightServices& LightServices();

    void GetColor(idColor& out) const override;
    void GetColor(idVec3& out) const override;
    void GetColor(idVec4& out) const override;
    void SetColor(const idVec4& color) override;
    void SetColor(const idColor& color) override;
    void SetColor(float red, float green, float blue) override;
    void PlaySound(bool play);
    void UpdateModifiedProperties();
    void InitRenderLight();
    void SetRadius(float radius);
    void Fade(const idColor& to, float fadeTime);
    void GetSoundTransform(idVec3& soundOrigin,
        idMat3& soundAxis) const override;
    void ShowEditingDialog() override;
    void UpdateEditingDialog() override;
    void Event_SetRadiusXYZ(float x, float y, float z);
    void Event_SetRadius(float radius);
    void Event_Hide();
    void Event_Show();
    void Event_FadeOutLight(float time);
    void Event_FadeInLight(float time);
    void SetLightTarget(const idVec3& value);
    void SetLightRight(const idVec3& value);
    void SetLightUp(const idVec3& value);
    void SetLightStart(const idVec3& value);
    void SetLightEnd(const idVec3& value);
    void SetLightCenter(const idVec3& value);
    void SetParallel(bool parallel);
    void SetSpot(bool spot);
    void UpdateModelTransform() override;
    idEntityInterface* CreateEntityInterface(idGame* game) override;
    void SetShader(const char* shaderName);
    void PresentModelDefChange();
    void Think() override;
    void Event_SetShader(const char* shaderName);
    void SetLightMaterial(const char* materialName);
    void SetLightLevel();
    void SetLightParms(float parm0, float parm1,
        float parm2, float parm3);
    void On();
    void Off();
    void Event_SetLightParms(float parm0, float parm1,
        float parm2, float parm3);
    void Hide() override;
    void Show() override;
    void Event_On();
    void Event_PostOff();
    void OnActivate(idEntity* activator) override;
    void Event_PostSpawn();
    void Spawn() override;

    idColor lightColor;
    idVec3 lightRadius;
    idVec3 lightCenter;
    idVec3 lightOffset;
    idMat3 lightOrientation;
    idSpotLight spotLight;
    bool noShadows;
    lightType_t lightType;
    lightClass_t lightClass;
    lightFallOff_t lightFalloff;
    bool startOff;
    const idMaterial* lightMaterial;
    const idIESfile* lightIesFile;
    float iesPowerScale;
    float iesAreaScale;
    const idDeclEnv* envEffectsDecl;
    idSoundInfo soundInfo;
    float dimShadowStretch;
    float lightGenAreaScale;
    idVec3 dynamicModelLightingScale;
    bool slowLight;
    float staticSpecularScale;
    idVec3 staticSpecularVector;
    bool additiveBlendLight;
    bool bakedParallelShadows;
    int slowMultiPass;
    idRenderLight* renderLight;
    idLightRenderState renderState;
    idEntity* lightParent;
    idColor fadeFrom;
    idColor fadeTo;
    idColor originalColor;
    int fadeStart;
    int fadeEnd;
    bool soundWasPlaying;
};

class idEditorLightInterface : public idEntityInterfaceLocal {
public:
    idEditorLightInterface(idGame* game, idEntity* entity);

    bool GetCastShadows();
    bool GetLightSpotlight();
    bool GetLightParallel();
    void SetLightClass(lightClass_t lightClass);
    void GetLightColor(idColor* color);
    void SetLightRadius(const idVec3* radius);
    void GetLightRadius(idVec3* radius);
    void SetLightSpotlight(bool spot);
    void SetLightParallel(bool parallel);
    void SetLightCenter(const idVec3* center);
    void GetLightCenter(idVec3* center);
    void SetLightTarget(const idVec3* target);
    void SetLightRight(const idVec3* right);
    void SetLightUp(const idVec3* up);
    void SetLightStart(const idVec3* start);
    void SetLightEnd(const idVec3* end);
    void SetLightMaterial(const char* materialName);
    void SetLightColor(const idColor* color);
    void SetCastShadows(bool castShadows);

private:
    idLight* Light() const;
};

class idBuildArea : public idLight {
public:
    struct buildVar_t {
        idStr varName;
        idStr varValue;
    };

    idBuildArea();
    ~idBuildArea() override;

    idVec3 areaOrigin;
    idVec3 areaSecondaryOrigin;
    idList<buildVar_t, 5> buildVars;
};
