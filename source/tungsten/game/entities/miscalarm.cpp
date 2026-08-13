#include "game/entities/miscalarm.h"

namespace {
idAlarmServices defaultAlarmServices;
idAlarmServices* alarmServices = &defaultAlarmServices;

constexpr int ALARM_TH_UPDATEVISUALS = 2;
constexpr int ALARM_BREAKABLE_DORMANCY_MILLISECONDS = 10000;
constexpr fxCondition_t ALARM_FX_NONE =
    static_cast<fxCondition_t>(0);
constexpr fxCondition_t ALARM_FX_PROP_BREAK =
    static_cast<fxCondition_t>(1);
} // namespace

idPresentable* idAlarmServices::AllocatePresentable(idAlarm& alarm,
        idRenderModel* model, const idDeclFX*) {
    return idEntity::Services().AllocatePresentable(alarm, model);
}

idAlarmBreakableSetupResult idAlarmServices::SetupBreakable(idAlarm&,
        const char*, const idDeclImpactSound*, float,
        idEffectPhysicsBreakable*&, idRenderModel*&,
        idPresentableBreakable*&) {
    return ALARM_BREAKABLE_MODEL_ALLOCATION_FAILED;
}

void idAlarmServices::ReleaseBreakablePresentable(
        idPresentableBreakable*) {}
void idAlarmServices::ReleaseBrokenModel(idRenderModel*) {}
void idAlarmServices::ReleaseBreakablePhysics(idEffectPhysicsBreakable*) {}
void idAlarmServices::Warn(const idAlarm&, const char*) {}

bool idAlarmServices::UpdateDormant(idAlarm& alarm) {
    return alarm.UpdateDormant();
}
void idAlarmServices::BaseThink(idAlarm& alarm) {
    alarm.idDynamicEntity::Think();
}
bool idAlarmServices::UsesRelaxedChatter(const idAlarm& alarm) const {
    return idEntity::Services().UsesRelaxedChatter(alarm);
}
int idAlarmServices::GetGameMilliseconds() const {
    return idEntity::Services().GetGameMilliseconds();
}
int idAlarmServices::GetGameFrame() const { return 0; }
int idAlarmServices::GetGameMillisecondsPerFrame() const {
    return idEntity::Services().GetGameMillisecondsPerFrame();
}
float idAlarmServices::GetRealMillisecondsPerFrame() const {
    return static_cast<float>(GetGameMillisecondsPerFrame());
}
void idAlarmServices::GetTransform(const idAlarm& alarm,
        idVec3& outOrigin, idMat3& outAxis) const {
    outOrigin = alarm.origin;
    outAxis = alarm.axis;
}
void idAlarmServices::UpdateBreakableTransform(idAlarm&,
        const idVec3&, const idMat3&) {}
void idAlarmServices::StartBreakableExplosions(idAlarm&,
        const idVec3&, const idMat3&, int) {}
void idAlarmServices::UpdateBreakableSimulation(idAlarm&,
        const idVec3&, const idMat3&, int, int, int, float) {}
void idAlarmServices::UpdateBreakableModel(idAlarm&,
        const idVec3&, const idMat3&, int) {}
void idAlarmServices::RegisterBreakableSimulation(idAlarm&) {}
void idAlarmServices::UpdatePVSAreas(idAlarm&) {}

void idAlarmServices::StartEffect(idAlarm&, fxCondition_t) {}
void idAlarmServices::StopEffect(idAlarm&, fxCondition_t) {}
void idAlarmServices::PostColorModulate(idAlarm& alarm,
        const bool active) {
    if (active) alarm.Event_ActivateColorModulate();
    else alarm.Event_DeactivateColorModulate();
}
void idAlarmServices::SetAlarmColor(idAlarm& alarm,
        const idColor& color) {
    alarm.idDynamicEntity::SetColor(color);
}
void idAlarmServices::Present(idAlarm&) {}
void idAlarmServices::ShowAlarm(idAlarm& alarm) {
    alarm.idDynamicEntity::Show();
}
void idAlarmServices::StartSound(idAlarm& alarm,
        const idAlarmSoundChannel channel, const idSoundShader* sound) {
    alarm.StartSoundShader(static_cast<int>(channel), sound, 0, true);
}
void idAlarmServices::StopSound(idAlarm& alarm,
        const idAlarmSoundChannel channel) {
    alarm.StopSound(static_cast<int>(channel), false);
}
bool idAlarmServices::IsSoundPlaying(const idAlarm& alarm,
        const idAlarmSoundChannel channel) const {
    return alarm.IsPlayingSound(static_cast<int>(channel));
}
void idAlarmServices::GetBaseSoundTransform(const idAlarm& alarm,
        idVec3& outOrigin, idMat3& outAxis) const {
    alarm.idEntity::GetSoundTransform(outOrigin, outAxis);
}

void idAlarmServices::HidePrimaryPresentable(idAlarm&) {}
void idAlarmServices::ShowBreakablePresentable(idAlarm&) {}
void idAlarmServices::BreakPresentable(idAlarm&) {}
void idAlarmServices::PresentBreakableState(idAlarm&) {}
void idAlarmServices::UnlinkMainClip(idAlarm&) {}
void idAlarmServices::ForceDormancy(idAlarm& alarm, const bool dormant,
        const int durationMilliseconds) {
    alarm.ForceDormancy(dormant, durationMilliseconds);
}
void idAlarmServices::SetThinkFlag(idAlarm& alarm, const int flag,
        const bool enabled) {
    if (enabled) alarm.BecomeActive(flag);
    else alarm.BecomeInactive(flag);
}
float idAlarmServices::GetDamageAmount(
        const idDeclDamage*) const {
    return 0.0f;
}

void Tungsten_SetAlarmServices(idAlarmServices* const services) {
    alarmServices = services == nullptr ? &defaultAlarmServices : services;
}

idAlarmServices& Tungsten_AlarmServices() { return *alarmServices; }

// Retail: 0x82C7B398 ?AllocPresentable@idAlarm@@UAAPAVidPresentable@@PAVidRenderModel@@@Z
idPresentable* idAlarm::AllocPresentable(idRenderModel* const model) {
    return Tungsten_AlarmServices().AllocatePresentable(
        *this, model, fxDecl);
}

// Retail: 0x82C7B440 ?SetupBreakable@idAlarm@@AAAXXZ
void idAlarm::SetupBreakable() {
    if (breakModel.IsEmpty()) return;

    idAlarmServices& services = Tungsten_AlarmServices();
    const idAlarmBreakableSetupResult result = services.SetupBreakable(
        *this, breakModel.c_str(), impactSoundTable,
        pieceMinBounceVelocity, breakablePhysics,
        brokenModel, breakablePresentable);
    if (result == ALARM_BREAKABLE_READY) return;

    const char* warning = "alarm breakable setup failed";
    switch (result) {
    case ALARM_BREAKABLE_MODEL_ALLOCATION_FAILED:
        warning = "couldn't allocate alarm breakable render model";
        break;
    case ALARM_BREAKABLE_MODEL_NOT_DISCRETE:
        warning = "alarm break model is not a discrete breakable model";
        break;
    case ALARM_BREAKABLE_DECL_MISSING:
        warning = "alarm break model has no breakable declaration";
        break;
    case ALARM_BREAKABLE_PHYSICS_ALLOCATION_FAILED:
        warning = "couldn't allocate alarm breakable physics";
        break;
    case ALARM_BREAKABLE_PRESENTABLE_ALLOCATION_FAILED:
        warning = "couldn't allocate alarm breakable presentable";
        break;
    default:
        break;
    }
    services.Warn(*this, warning);

    if (breakablePresentable != nullptr) {
        services.ReleaseBreakablePresentable(breakablePresentable);
        breakablePresentable = nullptr;
    }
    if (breakablePhysics != nullptr) {
        services.ReleaseBreakablePhysics(breakablePhysics);
        breakablePhysics = nullptr;
    }
    if (brokenModel != nullptr) {
        services.ReleaseBrokenModel(brokenModel);
        brokenModel = nullptr;
    }
}

// Retail: 0x82C7B948 ?Think@idAlarm@@UAAXXZ
void idAlarm::Think() {
    idAlarmServices& services = Tungsten_AlarmServices();
    if (services.UpdateDormant(*this)) return;

    services.BaseThink(*this);
    if ((thinkFlags & ALARM_TH_UPDATEVISUALS) != 0
            && breakablePhysics != nullptr) {
        idVec3 physicsOrigin;
        idMat3 physicsAxis(1.0f);
        services.GetTransform(*this, physicsOrigin, physicsAxis);
        services.UpdateBreakableTransform(
            *this, physicsOrigin, physicsAxis);

        if (brokenFrame == services.GetGameFrame()) {
            services.StartBreakableExplosions(*this,
                physicsOrigin, physicsAxis,
                services.GetGameMilliseconds());
        }
        if (brokenTime != -1) {
            services.UpdateBreakableSimulation(*this,
                physicsOrigin, physicsAxis,
                services.GetGameMilliseconds(),
                services.GetGameMillisecondsPerFrame(),
                services.GetGameFrame(),
                services.GetRealMillisecondsPerFrame());
            if (!services.UsesRelaxedChatter(*this)) {
                services.UpdateBreakableModel(*this,
                    physicsOrigin, physicsAxis,
                    services.GetGameMillisecondsPerFrame());
            }
            services.RegisterBreakableSimulation(*this);
        }
    }
    services.UpdatePVSAreas(*this);
}

// Retail: 0x82C7BC70 ?StartFX@idAlarm@@IAAXW4fxCondition_t@@@Z
void idAlarm::StartFX(const fxCondition_t condition) {
    Tungsten_AlarmServices().StartEffect(*this, condition);
}

// Retail: 0x82C7BCD8 ?ToggleAlarm@idAlarm@@AAAX_N@Z
void idAlarm::ToggleAlarm(const bool enable) {
    if (alarmActive == enable) return;

    idAlarmServices& services = Tungsten_AlarmServices();
    if (enable) {
        if (services.UsesRelaxedChatter(*this)) {
            services.ShowAlarm(*this);
        }
        if (brokenTime == -1) {
            services.PostColorModulate(*this, true);
            StartFX(fxConditionActivate);
            if (alarmSound != nullptr) {
                services.StartSound(*this,
                    ALARM_SOUND_CHANNEL_VOICE, alarmSound);
            }
            services.SetAlarmColor(*this, colorActive);
        }
    } else {
        services.PostColorModulate(*this, false);
        services.StopEffect(*this, fxConditionActivate);
        if (alarmSound != nullptr) {
            services.StopSound(*this, ALARM_SOUND_CHANNEL_VOICE);
        }
        services.SetAlarmColor(*this, colorInactive);
    }
    alarmActive = enable;
    services.Present(*this);
}

// Retail: 0x82C7BE20 ?OnActivate@idAlarm@@UAAXPAVidEntity@@@Z
void idAlarm::OnActivate(idEntity*) { ToggleAlarm(true); }

// Retail: 0x82C7BE28 ?OnMakeActivatable@idAlarm@@UAAX_N@Z
void idAlarm::OnMakeActivatable(const bool activatable) {
    if (!activatable) ToggleAlarm(false);
}

// Retail: 0x82C7BE40 ?GetSoundTransform@idAlarm@@UBAXAAVidVec3@@AAVidMat3@@@Z
void idAlarm::GetSoundTransform(idVec3& outOrigin,
        idMat3& outAxis) const {
    Tungsten_AlarmServices().GetBaseSoundTransform(
        *this, outOrigin, outAxis);
    outAxis = soundTransform * outAxis;
    outAxis.OrthoNormalizeSelf();
}

// Retail: 0x82C7BEE0 ??1idAlarm@@UAA@XZ
idAlarm::~idAlarm() {
    idAlarmServices& services = Tungsten_AlarmServices();
    if (breakablePresentable != nullptr) {
        services.ReleaseBreakablePresentable(breakablePresentable);
        breakablePresentable = nullptr;
    }
    if (brokenModel != nullptr) {
        services.ReleaseBrokenModel(brokenModel);
        brokenModel = nullptr;
    }
    if (breakablePhysics != nullptr) {
        services.ReleaseBreakablePhysics(breakablePhysics);
        breakablePhysics = nullptr;
    }
}

// Retail: 0x82C7C028 ?Spawn@idAlarm@@QAAXXZ
void idAlarm::Spawn() {
    Tungsten_AlarmServices().SetAlarmColor(*this, colorInactive);
    SetupBreakable();
}

// Retail: 0x82C7C070 ?Break@idAlarm@@AAAXXZ
void idAlarm::Break() {
    if (brokenTime != -1) return;

    idAlarmServices& services = Tungsten_AlarmServices();
    if (breakablePresentable != nullptr) {
        services.HidePrimaryPresentable(*this);
        services.ShowBreakablePresentable(*this);
        idVec3 physicsOrigin;
        idMat3 physicsAxis(1.0f);
        services.GetTransform(*this, physicsOrigin, physicsAxis);
        services.UpdateBreakableTransform(
            *this, physicsOrigin, physicsAxis);
        services.BreakPresentable(*this);
        services.PresentBreakableState(*this);
    }

    brokenTime = services.GetGameMilliseconds();
    brokenFrame = services.GetGameFrame() + 1;
    services.UnlinkMainClip(*this);

    const idSoundShader* const damageSound =
        services.IsSoundPlaying(*this, ALARM_SOUND_CHANNEL_VOICE)
            ? alarmBreakSound : breakSound;
    if (damageSound != nullptr) {
        services.StartSound(*this,
            ALARM_SOUND_CHANNEL_BREAK, damageSound);
    }
    StartFX(fxConditionBreak);
    if (breakablePhysics != nullptr) {
        services.ForceDormancy(*this, false,
            ALARM_BREAKABLE_DORMANCY_MILLISECONDS);
        services.SetThinkFlag(*this, ALARM_TH_UPDATEVISUALS, true);
    }
}

// Retail: 0x82C7C2A0 ?Damage@idAlarm@@UAAMPAVidEntity@@0PBVidDeclDamage@@MABVidVec3@@PAUtrace_t@@@Z
float idAlarm::Damage(idEntity*, idEntity*,
        const idDeclDamage* const damage, const float damageScale,
        const idVec3&, trace_t*) {
    if (brokenTime != -1) return 0.0f;

    const float damageAmount =
        Tungsten_AlarmServices().GetDamageAmount(damage) * damageScale;
    float remainingDamage = 0.0f;
    if (alarmHealth.Damage(damageAmount, true, remainingDamage)) {
        ToggleAlarm(false);
        Break();
    }
    return damageAmount;
}

// Retail: 0x82C7C348 ??0idAlarm@@QAA@XZ
idAlarm::idAlarm()
    : idDynamicEntity(), breakModel(), alarmSound(nullptr),
      alarmBreakSound(nullptr), breakSound(nullptr),
      colorInactive(idColor::colorBlack),
      colorActive(idColor::colorWhite), alarmHealth(), fxDecl(nullptr),
      fxConditionActivate(ALARM_FX_NONE),
      fxConditionBreak(ALARM_FX_PROP_BREAK), impactSoundTable(nullptr),
      pieceMinBounceVelocity(40.0f), soundTransform(1.0f),
      alarmActive(false), brokenTime(-1), brokenFrame(-1),
      breakablePhysics(nullptr), brokenModel(nullptr),
      breakablePresentable(nullptr) {
    alarmHealth.components[0].cur = 1.0f;
    alarmHealth.components[0].max = 1.0f;
    flags.takesDamage = true;
}
