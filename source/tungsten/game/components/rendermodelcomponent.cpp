#include "rendermodelcomponent.h"

#include <algorithm>

namespace {

idRenderModelInfoServices defaultRenderModelInfoServices;
idRenderModelInfoServices* renderModelInfoServices =
    &defaultRenderModelInfoServices;

} // namespace

void Tungsten_SetRenderModelInfoServices(idRenderModelInfoServices* services) {
    renderModelInfoServices = services != nullptr
        ? services : &defaultRenderModelInfoServices;
}

idRenderModelInfo::~idRenderModelInfo() {
    FreeRenderModel();
    renderParms.clear();
}

// EA 0x82BB60D8
void idRenderModelInfo::SetColor(const idColor& value) { color = value; }

// EA 0x82BB6100
void idRenderModelInfo::GetColor(idColor& out) const { out = color; }

// EA 0x82BB6128
void idRenderModelInfo::SetNoShadows(bool set) {
    if (set) flags |= FLAG_NO_SHADOWS;
    else flags &= ~FLAG_NO_SHADOWS;
}

// EA 0x82BB6140
void idRenderModelInfo::FreeRenderModel() {
    if (model != nullptr && !ownedByPresentable) {
        renderModelInfoServices->ReleaseRenderModel(model);
        model = nullptr;
    }
}

// EA 0x82BB61A8
void idRenderModelInfo::InitRenderModel(const idVec3& spawnPosition,
        const idMat3& spawnOrientation, bool enableStaticSpecular,
        const char* name, const char* className) {
    if (model == nullptr) return;
    idRenderModel* resolved = renderModelInfoServices->ResolveComboModel(
        *this, model, name != nullptr ? name : "");
    if (resolved != model) {
        if (!ownedByPresentable) renderModelInfoServices->ReleaseRenderModel(model);
        model = resolved;
    }
    if (model == nullptr) return;
    renderModelInfoServices->InitializeRenderModel(*this, model,
        spawnPosition, spawnOrientation, enableStaticSpecular, className);
    if (parmBlock != nullptr) {
        renderModelInfoServices->CopyParmBlock(model, parmBlock);
    }
    for (const idSpawnRenderParm& parm : renderParms) {
        renderModelInfoServices->ApplyRenderParm(model, parm.parm,
            parm.value.c_str());
    }
    renderModelInfoServices->ApplyColor(model, color);
}

// EA 0x82BB6650
void idRenderModelInfo::SetModel(idRenderModel* newModel,
        const char* className) {
    void* preservedSkin = nullptr;
    const idMaterial* preservedMaterial = nullptr;
    if (model != nullptr) {
        preservedSkin = renderModelInfoServices->GetCustomSkin(model);
        preservedMaterial = renderModelInfoServices->GetCustomMaterial(model);
    }
    FreeRenderModel();
    model = newModel;
    if (model != nullptr) {
        renderModelInfoServices->CommitRenderModel(model);
        renderModelInfoServices->SetCustomAppearance(model, preservedSkin,
            preservedMaterial);
        renderModelInfoServices->InitializeRenderModel(*this, model,
            idVec3(0.0f, 0.0f, 0.0f), idMat3(1.0f), false, className);
    }
}

// EA 0x82BB6708
void idRenderModelInfo::SetColor(float red, float green, float blue,
        float alpha) {
    color.Set(red, green, blue, alpha);
}

// EA 0x82BB6748
void idRenderModelInfo::SetColor(float red, float green, float blue) {
    color.Set(red, green, blue, 1.0f);
}

// EA 0x82BB6790
void idRenderModelInfo::SetColor(const idVec3& value) {
    color.Set(value.x, value.y, value.z, 1.0f);
}

// EA 0x82BB67E0
void idRenderModelInfo::SetColor(const idVec4& value) {
    color.Set(value.x, value.y, value.z, value.w);
}

// EA 0x82BB6830
void idRenderModelInfo::GetColor(idVec3& out) const {
    out.Set(color.r, color.g, color.b);
}

// EA 0x82BB6850
void idRenderModelInfo::GetColor(idVec4& out) const {
    out.Set(color.r, color.g, color.b, color.a);
}

// EA 0x82BB6878
void idRenderModelInfo::GetScale(idVec3& out) const { out = scale; }

// EA 0x82BB6898
void idRenderModelInfo::SetScale(const idVec3& value) { scale = value; }

// EA 0x82BB68B8
const idMaterial* idRenderModelInfo::GetRenderModelMaterial() const {
    if (model == nullptr) return nullptr;
    const idMaterial* material =
        renderModelInfoServices->GetCustomMaterial(model);
    return material != nullptr ? material
        : renderModelInfoServices->GetRenderModelMaterial(model);
}

// EA 0x82BB6968
void idRenderModelInfo::SetModelByName(const char* modelName,
        const char* className) {
    SetModel(renderModelInfoServices->AllocateRenderModel(modelName),
        className);
}

// EA 0x82BB6A90
void idRenderModelInfo::CleanRenderParms() {
    renderParms.erase(std::remove_if(renderParms.begin(), renderParms.end(),
        [](const idSpawnRenderParm& parm) {
            return renderModelInfoServices->IsColorParm(parm.parm);
        }), renderParms.end());
}

// EA 0x82BB6B08
idRenderModelInfo::idRenderModelInfo(idRenderModelInfo* nextModel)
    : flags(FLAG_NONE), color(1.0f, 1.0f, 1.0f, 1.0f), renderParms(),
      editorModel(), maxTexelDensity(0.0f), maxVisibleRange(0.0f),
      fadeVisibilityOver(400.0f), next(nextModel), dimShadowClipZ(0.0f),
      model(nullptr), customMaterial(nullptr), scale(1.0f, 1.0f, 1.0f),
      radiosityScale(1.0f), staticReflectionStrength(1.0f), traceGroup(0),
      ownedByPresentable(false), parmBlock(nullptr) {}
