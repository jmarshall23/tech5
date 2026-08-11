#pragma once

#include "idlib/color.h"
#include "idlib/math/vector.h"
#include "idlib/text/str.h"

#include <cstdint>
#include <vector>

class idDeclRenderParm;
class idMaterial;
class idParmBlock;
class idRenderModel;
class idRenderModelInfo;

struct idSpawnRenderParm {
    const idDeclRenderParm* parm{nullptr};
    idStr value;
};

class idRenderModelInfoServices {
public:
    virtual ~idRenderModelInfoServices() = default;
    virtual void ReleaseRenderModel(idRenderModel*) {}
    virtual void CommitRenderModel(idRenderModel*) {}
    virtual idRenderModel* ResolveComboModel(idRenderModelInfo&,
        idRenderModel* current, const char*) { return current; }
    virtual void InitializeRenderModel(idRenderModelInfo&, idRenderModel*,
        const idVec3&, const idMat3&, bool, const char*) {}
    virtual void* GetCustomSkin(idRenderModel*) const { return nullptr; }
    virtual const idMaterial* GetCustomMaterial(idRenderModel*) const {
        return nullptr;
    }
    virtual void SetCustomAppearance(idRenderModel*, void*,
        const idMaterial*) {}
    virtual idRenderModel* AllocateRenderModel(const char*) { return nullptr; }
    virtual const idMaterial* GetRenderModelMaterial(idRenderModel*) const {
        return nullptr;
    }
    virtual void CopyParmBlock(idRenderModel*, const idParmBlock*) {}
    virtual void ApplyRenderParm(idRenderModel*, const idDeclRenderParm*,
        const char*) {}
    virtual void ApplyColor(idRenderModel*, const idColor&) {}
    virtual bool IsColorParm(const idDeclRenderParm*) const { return false; }
};

void Tungsten_SetRenderModelInfoServices(idRenderModelInfoServices* services);

class idRenderModelInfo {
public:
    enum flags_t : std::uint32_t {
        FLAG_NONE = 0,
        FLAG_NO_SHADOWS = 1u << 5
    };

    explicit idRenderModelInfo(idRenderModelInfo* nextModel = nullptr);
    ~idRenderModelInfo();

    void SetColor(const idColor& color);
    void GetColor(idColor& color) const;
    void SetNoShadows(bool set);
    void FreeRenderModel();
    void InitRenderModel(const idVec3& spawnPosition,
        const idMat3& spawnOrientation, bool enableStaticSpecular,
        const char* name, const char* className);
    void SetModel(idRenderModel* model, const char* className);
    void SetColor(float red, float green, float blue, float alpha);
    void SetColor(float red, float green, float blue);
    void SetColor(const idVec3& color);
    void SetColor(const idVec4& color);
    void GetColor(idVec3& color) const;
    void GetColor(idVec4& color) const;
    void GetScale(idVec3& scale) const;
    void SetScale(const idVec3& scale);
    const idMaterial* GetRenderModelMaterial() const;
    void SetModelByName(const char* modelName, const char* className);
    void CleanRenderParms();

    std::uint32_t flags;
    idColor color;
    std::vector<idSpawnRenderParm> renderParms;
    idStr editorModel;
    float maxTexelDensity;
    float maxVisibleRange;
    float fadeVisibilityOver;
    idRenderModelInfo* next;
    float dimShadowClipZ;
    idRenderModel* model;
    const idMaterial* customMaterial;
    idVec3 scale;
    float radiosityScale;
    float staticReflectionStrength;
    std::uint8_t traceGroup;
    bool ownedByPresentable;
    const idParmBlock* parmBlock;
};
