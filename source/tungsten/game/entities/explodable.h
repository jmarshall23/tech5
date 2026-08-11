#pragma once

#include "game/components/healthcomponent.h"
#include "game/decls/decldamage.h"
#include "game/entities/entity.h"

class idDeclFX;
class idDeclParticle;

struct idExplodableClipModelInfo {
    enum clipModelType_t {
        CLIPMODEL_NONE = 0,
        CLIPMODEL_RENDERMODEL = 1,
        CLIPMODEL_CUSTOM = 2,
        CLIPMODEL_BOX = 3
    };

    clipModelType_t type = CLIPMODEL_NONE;
    idVec3 size;
    idVec3 offset;
};

class idExplodable;

class idExplodableServices {
public:
    virtual ~idExplodableServices() = default;
    virtual idBounds GetRenderModelBounds(const idExplodable& entity) const;
    virtual void InstallBoxClip(idExplodable& entity,
        const idBounds& bounds, int contents);
    virtual void DisablePhysics(idExplodable& entity);
    virtual void SetBrokenModel(idExplodable& entity,
        idRenderModel* model);
    virtual void UpdateVisuals(idExplodable& entity);
    virtual void PlayExplosionSound(idExplodable& entity,
        const idSoundShader* sound);
    virtual void StartEffect(idExplodable& entity, int condition,
        const idVec3& origin, const idMat3& axis, int gameTime);
    virtual void RadiusDamage(const idVec3& origin,
        idExplodable& inflictor, idEntity& attacker,
        const idDeclDamage& damage, float damagePower);
    virtual bool HasScriptObject(const idExplodable& entity) const;
    virtual bool HasOnExplodeFunction(const idExplodable& entity) const;
    virtual void CallOnExplode(idExplodable& entity,
        idEntity& attacker, bool deferred);
    virtual idPresentable* AllocatePresentable(idExplodable& entity,
        idRenderModel* model, int entityNumber, const idDeclFX* effect);
    virtual bool GetImpactTransform(const idExplodable& entity,
        const idVec3& direction, const trace_t* trace,
        idVec3& origin, idMat3& axis) const;
    virtual void DamageFeedback(idEntity& attacker,
        idExplodable& victim, idEntity* inflictor,
        const idDeclDamage& damage, float& amount);
    virtual void Warning(const char* message);
    virtual int GetGameMilliseconds() const;
};

class idExplodable : public idEntity {
public:
    idExplodable();

    static void SetServices(idExplodableServices* services);
    static idExplodableServices& Services();

    void Spawn() override;
    void Explode(idEntity* attacker);
    idPresentable* AllocPresentable(idRenderModel* renderModel) override;
    void Event_DisablePhysics();
    float Damage(idEntity* inflictor, idEntity* attacker,
        const idDeclDamage* damageDef, float damageScale,
        const idVec3& direction, trace_t* trace);
    void Think() override;
    void Hide() override;
    void Show() override;

    const idSoundShader* soundExplosion;
    const idDeclParticle* impactParticle;
    idRenderModel* brokenModel;
    const idDeclDamage* damageDecl;
    const idDeclFX* fxDecl;
    idDeclDamage::damageType_t explodingDamageTypes;
    idSimpleHealth explodableHealth;
    bool steamOnDamage;
    bool callScriptOnExplode;
    int fxLastSteamIndex;
    idExplodableClipModelInfo clipModelInfo;
};

struct explodableEmit_t {
    idMat3 localAxis;
    idVec3 localOrigin;
    int startTime = 0;
    int endTime = 0;
    float diversity = 0.0f;
    bool free = false;
};
