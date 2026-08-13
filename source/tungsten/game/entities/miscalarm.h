#pragma once

#include "game/components/healthcomponent.h"
#include "game/entities/misc.h"

class idAlarm;
class idDeclFX;
class idDeclImpactSound;
class idEffectPhysicsBreakable;
class idPresentableBreakable;
enum fxCondition_t : int;

enum idAlarmBreakableSetupResult : int {
    ALARM_BREAKABLE_NOT_REQUESTED = 0,
    ALARM_BREAKABLE_READY,
    ALARM_BREAKABLE_MODEL_ALLOCATION_FAILED,
    ALARM_BREAKABLE_MODEL_NOT_DISCRETE,
    ALARM_BREAKABLE_DECL_MISSING,
    ALARM_BREAKABLE_PHYSICS_ALLOCATION_FAILED,
    ALARM_BREAKABLE_PRESENTABLE_ALLOCATION_FAILED
};

enum idAlarmSoundChannel : int {
    ALARM_SOUND_CHANNEL_VOICE = 0,
    ALARM_SOUND_CHANNEL_BREAK = 1
};

class idAlarmServices {
public:
    virtual ~idAlarmServices() = default;

    virtual idPresentable* AllocatePresentable(idAlarm& alarm,
        idRenderModel* model, const idDeclFX* effect);
    virtual idAlarmBreakableSetupResult SetupBreakable(idAlarm& alarm,
        const char* modelName, const idDeclImpactSound* impactSounds,
        float minimumBounceVelocity,
        idEffectPhysicsBreakable*& physics,
        idRenderModel*& model,
        idPresentableBreakable*& presentable);
    virtual void ReleaseBreakablePresentable(
        idPresentableBreakable* presentable);
    virtual void ReleaseBrokenModel(idRenderModel* model);
    virtual void ReleaseBreakablePhysics(idEffectPhysicsBreakable* physics);
    virtual void Warn(const idAlarm& alarm, const char* message);

    virtual bool UpdateDormant(idAlarm& alarm);
    virtual void BaseThink(idAlarm& alarm);
    virtual bool UsesRelaxedChatter(const idAlarm& alarm) const;
    virtual int GetGameMilliseconds() const;
    virtual int GetGameFrame() const;
    virtual int GetGameMillisecondsPerFrame() const;
    virtual float GetRealMillisecondsPerFrame() const;
    virtual void GetTransform(const idAlarm& alarm,
        idVec3& origin, idMat3& axis) const;
    virtual void UpdateBreakableTransform(idAlarm& alarm,
        const idVec3& origin, const idMat3& axis);
    virtual void StartBreakableExplosions(idAlarm& alarm,
        const idVec3& origin, const idMat3& axis, int currentTime);
    virtual void UpdateBreakableSimulation(idAlarm& alarm,
        const idVec3& origin, const idMat3& axis, int currentTime,
        int millisecondsPerFrame, int frameNumber,
        float realMillisecondsPerFrame);
    virtual void UpdateBreakableModel(idAlarm& alarm,
        const idVec3& origin, const idMat3& axis,
        int millisecondsPerFrame);
    virtual void RegisterBreakableSimulation(idAlarm& alarm);
    virtual void UpdatePVSAreas(idAlarm& alarm);

    virtual void StartEffect(idAlarm& alarm, fxCondition_t condition);
    virtual void StopEffect(idAlarm& alarm, fxCondition_t condition);
    virtual void PostColorModulate(idAlarm& alarm, bool active);
    virtual void SetAlarmColor(idAlarm& alarm, const idColor& color);
    virtual void Present(idAlarm& alarm);
    virtual void ShowAlarm(idAlarm& alarm);
    virtual void StartSound(idAlarm& alarm, idAlarmSoundChannel channel,
        const idSoundShader* sound);
    virtual void StopSound(idAlarm& alarm, idAlarmSoundChannel channel);
    virtual bool IsSoundPlaying(const idAlarm& alarm,
        idAlarmSoundChannel channel) const;
    virtual void GetBaseSoundTransform(const idAlarm& alarm,
        idVec3& origin, idMat3& axis) const;

    virtual void HidePrimaryPresentable(idAlarm& alarm);
    virtual void ShowBreakablePresentable(idAlarm& alarm);
    virtual void BreakPresentable(idAlarm& alarm);
    virtual void PresentBreakableState(idAlarm& alarm);
    virtual void UnlinkMainClip(idAlarm& alarm);
    virtual void ForceDormancy(idAlarm& alarm, bool dormant,
        int durationMilliseconds);
    virtual void SetThinkFlag(idAlarm& alarm, int flag, bool active);
    virtual float GetDamageAmount(const idDeclDamage* damage) const;
};

void Tungsten_SetAlarmServices(idAlarmServices* services);
idAlarmServices& Tungsten_AlarmServices();

class idAlarm : public idDynamicEntity {
public:
    idAlarm();
    ~idAlarm() override;

    idPresentable* AllocPresentable(idRenderModel* model) override;
    void Spawn() override;
    void Think() override;
    void OnActivate(idEntity* activator) override;
    virtual void OnMakeActivatable(bool activatable);
    void GetSoundTransform(idVec3& origin, idMat3& axis) const override;
    virtual float Damage(idEntity* inflictor, idEntity* attacker,
        const idDeclDamage* damage, float damageScale,
        const idVec3& direction, trace_t* trace);

    // Retail: 0x82C7C020 ?GetHealthComponent@idAlarm@@UAAPAVidBaseHealth@@XZ
    virtual idBaseHealth* GetHealthComponent() { return &alarmHealth; }
    virtual const idBaseHealth* GetHealthComponent() const {
        return &alarmHealth;
    }

    idStr breakModel;
    const idSoundShader* alarmSound;
    const idSoundShader* alarmBreakSound;
    const idSoundShader* breakSound;
    idColor colorInactive;
    idColor colorActive;
    idSimpleHealth alarmHealth;
    const idDeclFX* fxDecl;
    fxCondition_t fxConditionActivate;
    fxCondition_t fxConditionBreak;
    const idDeclImpactSound* impactSoundTable;
    float pieceMinBounceVelocity;
    idMat3 soundTransform;
    bool alarmActive;
    int brokenTime;
    int brokenFrame;
    idEffectPhysicsBreakable* breakablePhysics;
    idRenderModel* brokenModel;
    idPresentableBreakable* breakablePresentable;

private:
    void SetupBreakable();
    void StartFX(fxCondition_t condition);
    void ToggleAlarm(bool enable);
    void Break();
};
