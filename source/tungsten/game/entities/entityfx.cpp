#include "game/entities/entityfx.h"

namespace {
idEntityFxServices defaultEntityFxServices;
idEntityFxServices* entityFxServices = &defaultEntityFxServices;
unsigned int entityFxRandomSeed = 0;
} // namespace

void idEntityFxServices::OpenFxEditor(idEntityFx&) {}
void idEntityFxServices::UpdateFxEditor(idEntityFx&) {}
idPresentable* idEntityFxServices::AllocateFxPresentable(idEntityFx&,
        const idDeclFX*) {
    return nullptr;
}
bool idEntityFxServices::IsFxStopped(const idEntityFx&,
        const idPresentable*, int) const {
    return true;
}
void idEntityFxServices::StartFx(idEntityFx&, idPresentable*,
        fxCondition_t, fxExtraCondition_t) {}
void idEntityFxServices::StopFx(idEntityFx&, idPresentable*,
        fxCondition_t, fxExtraCondition_t) {}
void idEntityFxServices::ShutdownFx(idEntityFx&, idPresentable*) {}
void idEntityFxServices::InitFx(idEntityFx&, idPresentable*,
        const idDeclFX*, float) {}
void idEntityFxServices::SetSystemColor(idEntityFx&, idPresentable*,
        const idVec4&) {}
void idEntityFxServices::UpdateModelTransform(idEntityFx& entity) {
    entity.idEntity::UpdateModelTransform();
}
void idEntityFxServices::UpdateVisuals(idEntityFx& entity) {
    entity.idEntity::UpdateVisuals();
}
int idEntityFxServices::GetGameMilliseconds() const {
    return idEntity::Services().GetGameMilliseconds();
}
float idEntityFxServices::RandomFloat() {
    entityFxRandomSeed = 1664525u * entityFxRandomSeed + 1013904223u;
    return static_cast<float>((entityFxRandomSeed >> 10) & 0x7FFF)
        * (1.0f / 32768.0f);
}
int idEntityFxServices::GetMaxFadeOutTime(const idDeclFX*,
        fxCondition_t) const {
    return 0;
}
void idEntityFxServices::CancelHideEvent(idEntityFx&) {}
void idEntityFxServices::PostStopFxEvent(idEntityFx& entity,
        const fxCondition_t condition, int) {
    entity.Event_StopFX(condition);
}
void idEntityFxServices::PostHideEvent(idEntityFx& entity, int) {
    entity.idEntity::Hide();
}

// Retail: 0x82C49770 ?ShowEditingDialog@idEntityFx@@UAAXXZ
void idEntityFx::ShowEditingDialog() {
    Services().OpenFxEditor(*this);
}

// Retail: 0x82C49790 ?UpdateEditingDialog@idEntityFx@@UAAXXZ
void idEntityFx::UpdateEditingDialog() {
    Services().UpdateFxEditor(*this);
}

// Retail: 0x82C49828 ??0idEntityFx@@QAA@XZ
idEntityFx::idEntityFx()
    : idEntity(),
      startOff(false),
      cycleTrigger(false),
      actionDelay(0.0f),
      fxEffect(nullptr),
      startCondition(FX_NONE),
      extraConditions(FX_EXTRA_COND_NONE),
      nextTriggerTime(-1),
      clipModelType(0) {
}

void idEntityFx::SetServices(idEntityFxServices* services) {
    entityFxServices = services != nullptr ? services
        : &defaultEntityFxServices;
}

idEntityFxServices& idEntityFx::Services() {
    return *entityFxServices;
}

// Retail: 0x82C498A0 ?AllocPresentable@idEntityFx@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
idPresentable* idEntityFx::AllocPresentable(idRenderModel*) {
    return Services().AllocateFxPresentable(*this, fxEffect);
}

// Retail: 0x82C49950 ?Hide@idEntityFx@@UAAXXZ
void idEntityFx::Hide() {
    idEntity::Hide();
    Services().PostStopFxEvent(*this, FX_NONE, 0);
    BecomeInactive(1);
}

// Retail: 0x82C499C0 ?Think@idEntityFx@@UAAXXZ
void idEntityFx::Think() {
    idEntity::Think();
    if ((thinkFlags & 1) != 0
            && (presentable == nullptr
                || Services().IsFxStopped(*this, presentable,
                    Services().GetGameMilliseconds()))) {
        BecomeInactive(1);
    }
}

// Retail: 0x82C49A50 ?StartFX@idEntityFx@@QAAXW4fxCondition_t@@@Z
void idEntityFx::StartFX(const fxCondition_t condition) {
    if (presentable == nullptr) {
        InitPresentableInternal();
    }
    Services().StartFx(*this, presentable, condition, extraConditions);
}

// Retail: 0x82C49AB8 ?TestEntityDeclFx@idEntityFx@@QAAXPBVidDeclFX@@W4fxCondition_t@@@Z
void idEntityFx::TestEntityDeclFx(const idDeclFX* declFx,
        const fxCondition_t condition) {
    fxEffect = declFx;
    if (presentable == nullptr) {
        InitPresentableInternal();
    }
    Services().ShutdownFx(*this, presentable);
    if (fxEffect != nullptr) {
        Services().InitFx(*this, presentable, fxEffect,
            Services().RandomFloat());
    }
    Services().StartFx(*this, presentable, condition, extraConditions);
}

// Retail: 0x82C49BE8 ?Spawn@idEntityFx@@QAAXXZ
void idEntityFx::Spawn() {
    nextTriggerTime = 0;
    if (presentable == nullptr) {
        InitPresentableInternal();
    }
    Services().SetSystemColor(*this, presentable, color);
    if (startOff) {
        Hide();
    } else {
        BecomeActive(1);
        Services().UpdateModelTransform(*this);
        StartFX(startCondition);
    }
    Services().UpdateVisuals(*this);
}

// Retail: 0x82C49CC0 ?Show@idEntityFx@@UAAXXZ
void idEntityFx::Show() {
    if (startOff) {
        return;
    }
    idEntity::Show();
    BecomeActive(1);
    StartFX(startCondition);
}

// Retail: 0x82C49D10 ?OnActivate@idEntityFx@@UAAXPAVidEntity@@@Z
void idEntityFx::OnActivate(idEntity*) {
    const int gameTime = Services().GetGameMilliseconds();
    if (gameTime < nextTriggerTime) {
        return;
    }

    if (cycleTrigger || startOff) {
        Services().CancelHideEvent(*this);
        if (presentable == nullptr) {
            InitPresentableInternal();
        }
        Services().StopFx(*this, presentable, startCondition,
            FX_EXTRA_COND_NONE);
        const bool restoreStartOff = startOff;
        startOff = false;
        Show();
        startOff = restoreStartOff;
    } else {
        Services().PostStopFxEvent(*this, FX_NONE, 0);
        const int fadeOutTime = fxEffect != nullptr
            ? Services().GetMaxFadeOutTime(fxEffect, FX_NONE) : 0;
        Services().PostHideEvent(*this, fadeOutTime);
    }

    nextTriggerTime = gameTime + (actionDelay == 0.0f
        ? 1 : static_cast<int>(actionDelay * 1000.0f));
}

// Retail: 0x82C49E98 ?Event_StartFX@idEntityFx@@AAA?AVeventVoid@@W4fxCondition_t@@@Z
void idEntityFx::Event_StartFX(const fxCondition_t condition) {
    StartFX(condition == FX_NONE ? startCondition : condition);
}

// Retail: 0x82C49EF8 ?Event_StopFX@idEntityFx@@AAA?AVeventVoid@@W4fxCondition_t@@@Z
void idEntityFx::Event_StopFX(const fxCondition_t condition) {
    if (presentable == nullptr) {
        InitPresentableInternal();
    }
    Services().StopFx(*this, presentable,
        condition == FX_NONE ? startCondition : condition,
        FX_EXTRA_COND_NONE);
}
