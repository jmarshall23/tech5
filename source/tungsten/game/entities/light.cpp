#include "game/entities/light.h"

#include <algorithm>

namespace {
idLightServices defaultLightServices;
idLightServices* lightServices = &defaultLightServices;

bool IsZero(const idVec3& value) {
    return value.x == 0.0f && value.y == 0.0f && value.z == 0.0f;
}

bool IsBlack(const idColor& color) {
    return color.r == idColor::colorBlack.r
        && color.g == idColor::colorBlack.g
        && color.b == idColor::colorBlack.b
        && color.a == idColor::colorBlack.a;
}
} // namespace

idRenderLight* idLightServices::AllocateRenderLight(idLight&) {
    return reinterpret_cast<idRenderLight*>(1);
}
void idLightServices::FreeRenderLight(idRenderLight*) {}
void idLightServices::CommitRenderLight(
        idLight&, const idLightRenderState&) {}
int idLightServices::GetScaledGameMilliseconds() const { return 0; }
const idMaterial* idLightServices::FindMaterial(const char*) const {
    return nullptr;
}
void idLightServices::PresentModelDefChange(idLight&) {}
void idLightServices::ShowLightEditor(idLight& light) {
    light.idEntity::ShowEditingDialog();
}
void idLightServices::UpdateLightEditor(idLight& light) {
    light.idEntity::UpdateEditingDialog();
}
void idLightServices::LinkLightToTarget(idLight&, idEntity&, bool) {}
void idLightServices::AddEnvironmentArea(
        idLight&, const idBounds&, const idDeclEnv*) {}
bool idLightServices::HasGlobalShadows() const { return true; }
bool idLightServices::IsComboMapWithoutPrelights() const { return false; }
void idLightServices::ReportWarning(const idLight&, const char*) {}

void idLight::SetServices(idLightServices* services) {
    lightServices = services != nullptr ? services : &defaultLightServices;
}
idLightServices& idLight::LightServices() { return *lightServices; }

// Retail: 0x82C6A2C8
idLight::~idLight() {
    if (renderLight != nullptr) {
        LightServices().FreeRenderLight(renderLight);
        renderLight = nullptr;
    }
}

// Retail: 0x82C6A358
void idLight::GetColor(idColor& out) const { out = lightColor; }

// Retail: 0x82C6A380
void idLight::SetColor(const idVec4& value) {
    lightColor.Set(value.x, value.y, value.z, value.w);
}

// Retail: 0x82C6A3A8
void idLight::PlaySound(bool play) {
    if (play && soundInfo.shader != nullptr) {
        StartSoundShader(0, soundInfo.shader, 0, true);
        soundWasPlaying = false;
    } else {
        StopSound(0, true);
        soundWasPlaying = true;
    }
}

// Retail: 0x82C6A418
void idLight::UpdateModifiedProperties() {
    StopSound(0, true);
    soundWasPlaying = true;
    if (soundInfo.shader != nullptr) PlaySound(true);
}

// Retail: 0x82C6A5F8
void idLight::InitRenderLight() {
    if (renderLight == nullptr) {
        renderLight = LightServices().AllocateRenderLight(*this);
    }
    renderState.origin = origin + axis * lightOffset;
    renderState.axis = lightType == LIGHT_REAL
        ? axis * lightOrientation : axis;
    renderState.type = lightType;
    if (lightType == LIGHT_SPOT) {
        renderState.target = spotLight.lightTarget;
        renderState.right = spotLight.lightRight;
        renderState.up = spotLight.lightUp;
        renderState.start = spotLight.lightStart;
        renderState.end = IsZero(spotLight.lightEnd)
            ? spotLight.lightTarget : spotLight.lightEnd;
        const bool anySpotVector = !IsZero(spotLight.lightTarget)
            || !IsZero(spotLight.lightUp) || !IsZero(spotLight.lightRight);
        const bool allSpotVectors = !IsZero(spotLight.lightTarget)
            && !IsZero(spotLight.lightUp) && !IsZero(spotLight.lightRight);
        if (anySpotVector != allSpotVectors) {
            LightServices().ReportWarning(*this, "bad spotlight target info");
        }
    } else {
        renderState.center = lightCenter;
        renderState.radius = IsZero(lightRadius)
            ? idVec3(320.0f, 320.0f, 320.0f) : lightRadius;
    }
    renderState.noShadows = noShadows;
    renderState.slowLight = slowLight;
    renderState.lightClass = lightClass;
    renderState.falloff = lightFalloff;
    renderState.dimShadowStretch = dimShadowStretch;
    renderState.dynamicModelLightingScale = dynamicModelLightingScale;
    renderState.staticSpecularScale = staticSpecularScale;
    renderState.staticSpecularVector = staticSpecularVector;
    renderState.iesFile = lightIesFile;
    renderState.iesPowerScale = iesPowerScale;
    renderState.iesAreaScale = iesAreaScale;
    renderState.bakedParallelShadows = bakedParallelShadows;
    renderState.slowMultiPass = (std::max)(1, (std::min)(4, slowMultiPass));
    renderState.shader = lightMaterial;
    renderState.areaLightSize = lightGenAreaScale;
    renderState.color = lightColor;
}

// Retail: 0x82C6AD90
void idLight::GetColor(idVec3& out) const {
    out.Set(lightColor.r, lightColor.g, lightColor.b);
}

// Retail: 0x82C6ADB0
void idLight::GetColor(idVec4& out) const {
    out.Set(lightColor.r, lightColor.g, lightColor.b, lightColor.a);
}

// Retail: 0x82C6ADD8
void idLight::SetRadius(float radius) {
    lightRadius.Set(radius, radius, radius);
    renderState.radius = lightRadius;
    LightServices().CommitRenderLight(*this, renderState);
}

// Retail: 0x82C6ADF8
void idLight::Fade(const idColor& to, float fadeTime) {
    fadeFrom = lightColor;
    fadeTo = to;
    fadeStart = LightServices().GetScaledGameMilliseconds();
    fadeEnd = fadeStart + static_cast<int>(fadeTime * 1000.0f);
    BecomeActive(1);
}

// Retail: 0x82C6AEB0
void idLight::GetSoundTransform(idVec3& soundOrigin,
        idMat3& soundAxis) const {
    soundOrigin = origin + axis * renderState.center;
    soundAxis = axis;
}

// Retail: 0x82C6B030
void idLight::ShowEditingDialog() { LightServices().ShowLightEditor(*this); }

// Retail: 0x82C6B068
void idLight::UpdateEditingDialog() {
    LightServices().UpdateLightEditor(*this);
}

// Retail: 0x82C6B0A0
void idLight::Event_SetRadiusXYZ(float x, float y, float z) {
    lightRadius.Set(x, y, z);
    renderState.radius = lightRadius;
    LightServices().CommitRenderLight(*this, renderState);
}

// Retail: 0x82C6B0F0
void idLight::Event_SetRadius(float radius) { SetRadius(radius); }

// Retail: 0x82C6B140
void idLight::Event_Hide() { Hide(); }

// Retail: 0x82C6B180
void idLight::Event_Show() { Show(); }

// Retail: 0x82C6B1C0
void idLight::Event_FadeOutLight(float time) {
    Fade(idColor::colorBlack, time);
}

// Retail: 0x82C6B200
void idLight::Event_FadeInLight(float time) { Fade(originalColor, time); }

// Retail: 0x82C6B238
void idLight::SetLightTarget(const idVec3& value) {
    spotLight.lightTarget = value;
    InitRenderLight();
}

// Retail: 0x82C6B258
void idLight::SetLightRight(const idVec3& value) {
    spotLight.lightRight = value;
    InitRenderLight();
}

// Retail: 0x82C6B278
void idLight::SetLightUp(const idVec3& value) {
    spotLight.lightUp = value;
    InitRenderLight();
}

// Retail: 0x82C6B298
void idLight::SetLightStart(const idVec3& value) {
    spotLight.lightStart = value;
    InitRenderLight();
}

// Retail: 0x82C6B2B8
void idLight::SetLightEnd(const idVec3& value) {
    spotLight.lightEnd = value;
    InitRenderLight();
}

// Retail: 0x82C6B2D8
void idLight::SetLightCenter(const idVec3& value) {
    lightCenter = value;
    InitRenderLight();
}

// Retail: 0x82C6B2F8
void idLight::SetParallel(bool parallel) {
    if (parallel) lightType = LIGHT_PARALLEL;
    else if (lightType == LIGHT_PARALLEL) lightType = LIGHT_POINT;
    InitRenderLight();
}

// Retail: 0x82C6B328
void idLight::SetSpot(bool spot) {
    if (spot) lightType = LIGHT_SPOT;
    else if (lightType == LIGHT_SPOT) lightType = LIGHT_POINT;
    InitRenderLight();
}

// Retail: 0x82C6B358
void idLight::UpdateModelTransform() {
    if (renderLight != nullptr) {
        GetModelTransform(renderState.origin, renderState.axis);
        LightServices().CommitRenderLight(*this, renderState);
    }
}

// Retail: 0x82C6B458
idEntityInterface* idLight::CreateEntityInterface(idGame* game) {
    return new idEditorLightInterface(game, this);
}

idEditorLightInterface::idEditorLightInterface(
        idGame* game, idEntity* entity)
    : idEntityInterfaceLocal(game, entity) {}

idLight* idEditorLightInterface::Light() const {
    return dynamic_cast<idLight*>(entityPtr);
}

// Retail: 0x82C6A498
bool idEditorLightInterface::GetCastShadows() {
    const idLight* light = Light();
    return light == nullptr || !light->noShadows;
}

// Retail: 0x82C6A4F0
bool idEditorLightInterface::GetLightSpotlight() {
    const idLight* light = Light();
    return light != nullptr && light->lightType == LIGHT_SPOT;
}

// Retail: 0x82C6A550
bool idEditorLightInterface::GetLightParallel() {
    const idLight* light = Light();
    return light != nullptr && light->lightType == LIGHT_PARALLEL;
}

// Retail: 0x82C6A5B0
void idEditorLightInterface::SetLightClass(lightClass_t value) {
    idLight* light = Light();
    if (light != nullptr) light->lightClass = value;
}

// Retail: 0x82C6B500
void idEditorLightInterface::GetLightColor(idColor* color) {
    if (color == nullptr) return;
    *color = idColor::colorWhite;
    idLight* light = Light();
    if (light != nullptr) light->GetColor(*color);
}

// Retail: 0x82C6B570
void idEditorLightInterface::SetLightRadius(const idVec3* radius) {
    idLight* light = Light();
    if (light != nullptr && radius != nullptr) {
        light->Event_SetRadiusXYZ(radius->x, radius->y, radius->z);
    }
}

// Retail: 0x82C6B5E8
void idEditorLightInterface::GetLightRadius(idVec3* radius) {
    if (radius == nullptr) return;
    radius->Zero();
    idLight* light = Light();
    if (light != nullptr) *radius = light->renderState.radius;
}

// Retail: 0x82C6B678
void idEditorLightInterface::SetLightSpotlight(bool spot) {
    idLight* light = Light();
    if (light != nullptr) light->SetSpot(spot);
}

// Retail: 0x82C6B6E8
void idEditorLightInterface::SetLightParallel(bool parallel) {
    idLight* light = Light();
    if (light != nullptr) light->SetParallel(parallel);
}

// Retail: 0x82C6B758
void idEditorLightInterface::SetLightCenter(const idVec3* center) {
    idLight* light = Light();
    if (light != nullptr && center != nullptr) {
        light->SetLightCenter(*center);
        light->UpdateVisuals();
    }
}

// Retail: 0x82C6B7D0
void idEditorLightInterface::GetLightCenter(idVec3* center) {
    if (center == nullptr) return;
    center->Zero();
    idLight* light = Light();
    if (light != nullptr) *center = light->lightCenter;
}

// Retail: 0x82C6B830
void idEditorLightInterface::SetLightTarget(const idVec3* value) {
    idLight* light = Light();
    if (light != nullptr && value != nullptr) light->SetLightTarget(*value);
}

// Retail: 0x82C6B890
void idEditorLightInterface::SetLightRight(const idVec3* value) {
    idLight* light = Light();
    if (light != nullptr && value != nullptr) light->SetLightRight(*value);
}

// Retail: 0x82C6B8F0
void idEditorLightInterface::SetLightUp(const idVec3* value) {
    idLight* light = Light();
    if (light != nullptr && value != nullptr) light->SetLightUp(*value);
}

// Retail: 0x82C6B950
void idEditorLightInterface::SetLightStart(const idVec3* value) {
    idLight* light = Light();
    if (light != nullptr && value != nullptr) light->SetLightStart(*value);
}

// Retail: 0x82C6B9B0
void idEditorLightInterface::SetLightEnd(const idVec3* value) {
    idLight* light = Light();
    if (light != nullptr && value != nullptr) light->SetLightEnd(*value);
}

// Retail: 0x82C6BA10
idLight::idLight()
    : lightColor(idColor::colorWhite),
      lightRadius(320.0f, 320.0f, 320.0f),
      lightCenter(0.0f, 0.0f, 0.0f), lightOffset(0.0f, 0.0f, 0.0f),
      lightOrientation(1.0f), noShadows(false), lightType(LIGHT_POINT),
      lightClass(LIGHT_NORMAL), lightFalloff(LIGHT_FALLOFF_TEXTURE),
      startOff(false), lightMaterial(nullptr), lightIesFile(nullptr),
      iesPowerScale(1.0f), iesAreaScale(1.0f), envEffectsDecl(nullptr),
      dimShadowStretch(1.0f), lightGenAreaScale(8.0f),
      dynamicModelLightingScale(1.0f, 1.0f, 1.0f), slowLight(false),
      staticSpecularScale(10.0f),
      staticSpecularVector(0.0f, 0.707f, 0.707f),
      additiveBlendLight(false), bakedParallelShadows(false),
      slowMultiPass(1), renderLight(nullptr), lightParent(nullptr),
      fadeFrom(idColor::colorWhite), fadeTo(idColor::colorWhite),
      originalColor(idColor::colorWhite), fadeStart(0), fadeEnd(0),
      soundWasPlaying(false) {
    spotLight.lightTarget.Set(64.0f, 0.0f, 0.0f);
    spotLight.lightRight.Set(0.0f, -64.0f, 0.0f);
    spotLight.lightUp.Set(0.0f, 0.0f, 64.0f);
    spotLight.lightStart.Zero();
    spotLight.lightEnd.Zero();
}

// Retail: 0x82C6BC38
void idLight::SetShader(const char* shaderName) {
    lightMaterial = shaderName != nullptr
        ? LightServices().FindMaterial(shaderName) : nullptr;
    renderState.shader = lightMaterial;
    LightServices().CommitRenderLight(*this, renderState);
}

// Retail: 0x82C6BCD0
void idLight::PresentModelDefChange() {
    LightServices().PresentModelDefChange(*this);
}

// Retail: 0x82C6BD60
void idLight::Think() {
    if ((thinkFlags & 1) != 0 && fadeEnd > 0) {
        const int now = LightServices().GetScaledGameMilliseconds();
        if (now >= fadeEnd) {
            lightColor = fadeTo;
            fadeEnd = 0;
            BecomeInactive(1);
        } else {
            const float fraction = fadeEnd != fadeStart
                ? static_cast<float>(now - fadeStart)
                    / static_cast<float>(fadeEnd - fadeStart)
                : 1.0f;
            lightColor.Lerp(fadeFrom, fadeTo, fraction);
        }
        SetColor(lightColor);
    }
    RunPhysics();
    renderState.origin = origin;
    renderState.axis = axis;
    LightServices().CommitRenderLight(*this, renderState);
    PresentModelDefChange();
}

// Retail: 0x82C6BF88
void idLight::Event_SetShader(const char* shaderName) { SetShader(shaderName); }

// Retail: 0x82C6BFC0
void idLight::SetLightMaterial(const char* materialName) {
    lightMaterial = materialName != nullptr
        ? LightServices().FindMaterial(materialName) : nullptr;
    InitRenderLight();
}

// Retail: 0x82C6C018
void idEditorLightInterface::SetLightMaterial(const char* materialName) {
    idLight* light = Light();
    if (light != nullptr) light->SetLightMaterial(materialName);
}

// Retail: 0x82C6C098
void idLight::SetLightLevel() {
    InitRenderLight();
    LightServices().CommitRenderLight(*this, renderState);
    PresentModelDefChange();
}

// Retail: 0x82C6C0D8
void idLight::SetColor(float red, float green, float blue) {
    lightColor.r = red;
    lightColor.g = green;
    lightColor.b = blue;
    SetLightLevel();
}

// Retail: 0x82C6C120
void idLight::SetColor(const idColor& value) {
    lightColor = value;
    SetLightLevel();
}

// Retail: 0x82C6C180
void idLight::SetLightParms(
        float parm0, float parm1, float parm2, float parm3) {
    lightColor.Set(parm0, parm1, parm2, parm3);
    originalColor = lightColor;
    SetLightLevel();
}

// Retail: 0x82C6C1F0
void idLight::On() {
    if ((soundWasPlaying || soundInfo.waitForTrigger)
            && soundInfo.shader != nullptr) {
        PlaySound(true);
    }
    lightColor = originalColor;
    SetLightLevel();
    if (targets.Num() > 0) Event_PostSpawn();
}

// Retail: 0x82C6C2A8
void idLight::Off() {
    if (IsPlayingSound(0)) PlaySound(false);
    lightColor = idColor::colorBlack;
    SetLightLevel();
    for (int index = 0; index < targets.Num(); ++index) {
        if (targets[index] != nullptr) {
            LightServices().LinkLightToTarget(
                *this, *targets[index], additiveBlendLight);
        }
    }
}

// Retail: 0x82C6C460
void idLight::Event_SetLightParms(
        float parm0, float parm1, float parm2, float parm3) {
    SetLightParms(parm0, parm1, parm2, parm3);
}

// Retail: 0x82C6C4E8
void idLight::Hide() {
    idEntity::Hide();
    PresentModelDefChange();
    Off();
}

// Retail: 0x82C6C528
void idLight::Show() {
    idEntity::Show();
    PresentModelDefChange();
    On();
}

// Retail: 0x82C6C568
void idLight::Event_On() { On(); }

// Retail: 0x82C6C5A0
void idLight::Event_PostOff() { Off(); }

// Retail: 0x82C6C5D8
void idLight::OnActivate(idEntity*) {
    if (IsBlack(lightColor)) On();
    else Off();
}

// Retail: 0x82C6C640
void idLight::Event_PostSpawn() {
    for (int index = 0; index < targets.Num(); ++index) {
        idEntity* const target = targets[index];
        if (target == nullptr) continue;
        idLight* const childLight = dynamic_cast<idLight*>(target);
        if (childLight != nullptr) {
            childLight->lightParent = this;
            childLight->FreeSoundEmitter(true);
            childLight->UpdateVisuals();
        } else {
            LightServices().LinkLightToTarget(
                *this, *target, additiveBlendLight);
        }
    }
}

// Retail: 0x82C6CA38
void idEditorLightInterface::SetLightColor(const idColor* color) {
    idLight* light = Light();
    if (light != nullptr && color != nullptr) {
        light->SetLightParms(color->r, color->g, color->b, color->a);
    }
}

// Retail: 0x82C6CA90
void idEditorLightInterface::SetCastShadows(bool castShadows) {
    idLight* light = Light();
    if (light != nullptr) {
        light->noShadows = !castShadows;
        light->SetLightLevel();
    }
}

// Retail: 0x82C6CB08
void idLight::Spawn() {
    if (lightType == LIGHT_PARALLEL
            && !LightServices().HasGlobalShadows()) {
        LightServices().ReportWarning(
            *this, "parallel light without global shadows");
    }
    if (envEffectsDecl != nullptr) {
        idBounds environmentBounds;
        environmentBounds[0] = spawnPosition - lightRadius;
        environmentBounds[1] = spawnPosition + lightRadius;
        LightServices().AddEnvironmentArea(
            *this, environmentBounds, envEffectsDecl);
        if (soundInfo.shader != nullptr) {
            LightServices().ReportWarning(
                *this, "environment area has a sound shader");
        }
        if (lightMaterial != nullptr) {
            LightServices().ReportWarning(
                *this, "environment area has a light material");
        }
        Remove();
        return;
    }
    if (lightClass == LIGHT_PRELIGHT_ONLY
            && LightServices().IsComboMapWithoutPrelights()) {
        if (soundInfo.shader != nullptr) {
            LightServices().ReportWarning(
                *this, "prelight-only light has a sound shader");
        }
        Remove();
        return;
    }
    if (slowMultiPass > 2) {
        LightServices().ReportWarning(
            *this, "light has more than two blend passes");
    }
    InitRenderLight();
    LightServices().CommitRenderLight(*this, renderState);
    originalColor = lightColor;
    if (startOff) Off();
    else {
        if (!soundInfo.waitForTrigger && soundInfo.shader != nullptr) {
            PlaySound(true);
        }
        if (targets.Num() > 0) Event_PostSpawn();
    }
    fadeFrom = idColor::colorWhite;
    fadeTo = idColor::colorWhite;
    fadeStart = 0;
    fadeEnd = 0;
    UpdateVisuals();
}

// Retail: 0x82C6CED8
idBuildArea::idBuildArea()
    : areaOrigin(0.0f, 0.0f, 0.0f),
      areaSecondaryOrigin(0.0f, 0.0f, 0.0f) {}

// Retail: 0x82C6CFA8
idBuildArea::~idBuildArea() { buildVars.ClearFree(); }
