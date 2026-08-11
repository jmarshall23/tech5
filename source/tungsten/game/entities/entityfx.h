#pragma once

#include "game/entities/entity.h"

class idDeclFX;

enum fxCondition_t : int {
    FX_NONE = 0
};

enum fxExtraCondition_t : int {
    FX_EXTRA_COND_NONE = 0
};

class idEntityFx;

class idEntityFxServices {
public:
    virtual ~idEntityFxServices() = default;
    virtual void OpenFxEditor(idEntityFx& entity);
    virtual void UpdateFxEditor(idEntityFx& entity);
    virtual idPresentable* AllocateFxPresentable(idEntityFx& entity,
        const idDeclFX* effect);
    virtual bool IsFxStopped(const idEntityFx& entity,
        const idPresentable* presentable, int gameTime) const;
    virtual void StartFx(idEntityFx& entity, idPresentable* presentable,
        fxCondition_t condition, fxExtraCondition_t extraCondition);
    virtual void StopFx(idEntityFx& entity, idPresentable* presentable,
        fxCondition_t condition, fxExtraCondition_t extraCondition);
    virtual void ShutdownFx(idEntityFx& entity,
        idPresentable* presentable);
    virtual void InitFx(idEntityFx& entity, idPresentable* presentable,
        const idDeclFX* effect, float diversity);
    virtual void SetSystemColor(idEntityFx& entity,
        idPresentable* presentable, const idVec4& color);
    virtual void UpdateModelTransform(idEntityFx& entity);
    virtual void UpdateVisuals(idEntityFx& entity);
    virtual int GetGameMilliseconds() const;
    virtual float RandomFloat();
    virtual int GetMaxFadeOutTime(const idDeclFX* effect,
        fxCondition_t condition) const;
    virtual void CancelHideEvent(idEntityFx& entity);
    virtual void PostStopFxEvent(idEntityFx& entity,
        fxCondition_t condition, int delayMilliseconds);
    virtual void PostHideEvent(idEntityFx& entity,
        int delayMilliseconds);
};

class idEntityFx : public idEntity {
public:
    idEntityFx();

    static void SetServices(idEntityFxServices* services);
    static idEntityFxServices& Services();

    void ShowEditingDialog() override;
    void UpdateEditingDialog() override;
    idPresentable* AllocPresentable(idRenderModel* renderModel) override;
    void Hide() override;
    void Think() override;
    void StartFX(fxCondition_t condition);
    void TestEntityDeclFx(const idDeclFX* declFx,
        fxCondition_t condition);
    void Spawn() override;
    void Show() override;
    void OnActivate(idEntity* activator) override;
    void Event_StartFX(fxCondition_t condition);
    void Event_StopFX(fxCondition_t condition);

    bool startOff;
    bool cycleTrigger;
    float actionDelay;
    const idDeclFX* fxEffect;
    fxCondition_t startCondition;
    fxExtraCondition_t extraConditions;
    int nextTriggerTime;
    int clipModelType;
};
