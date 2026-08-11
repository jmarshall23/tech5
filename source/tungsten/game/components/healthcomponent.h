#pragma once

#include "idlib/filesystem/file.h"

class idCmdArgs;
class idTungstenHealth;

enum aiHealthComponent_t : int {
    AI_HEALTH_HITPOINTS = 0,
    AI_HEALTH_SHIELD = 1,
    AI_HEALTH_MAX = 2
};

enum vehicleHealthComponent_t : int {
    VEHICLE_HEALTH_HITPOINTS = 0,
    VEHICLE_HEALTH_ARMOR = 1,
    VEHICLE_HEALTH_MAX = 2
};

enum simpleHealthComponent_t : int {
    SIMPLE_HEALTH_HITPOINTS = 0,
    SIMPLE_HEALTH_MAX = 1
};

class idTungstenHealthServices {
public:
    virtual ~idTungstenHealthServices() = default;
    virtual int GetGameTime() const { return 0; }
    virtual float GetRegenDelaySeconds() const { return 0.0f; }
    virtual int GetRegenSteps() const { return 1; }
    virtual float GetRegenSpeed() const { return 0.0f; }
    virtual float GetDecaySpeed() const { return 0.0f; }
    virtual void Killed(idTungstenHealth&, float) {}
    virtual void DamageReported(idTungstenHealth&, float, bool, float) {}
};

void Tungsten_SetHealthComponentServices(idTungstenHealthServices* services);

class idBaseHealth {
public:
    virtual ~idBaseHealth() = default;
    virtual void Reset_Impl() = 0;
    virtual void Update_Impl() = 0;
    virtual bool Damage_Impl(float damage, bool allowDeath,
        float& remainingDamage) = 0;
    virtual bool DamageComponent_Impl(int type, float damage,
        bool allowDeath, bool overflow, float& remainingDamage) = 0;
    virtual void HealComponent_Impl(int type, float health,
        bool overflow) = 0;
    virtual float GetComponentCur_Impl(int type) const = 0;
    virtual float GetComponentMax_Impl(int type) const = 0;
    virtual void SetComponentCur_Impl(int type, float health) = 0;
    virtual void SetComponentMax_Impl(int type, float health) = 0;
    virtual float GetTotalCurHealth_Impl() const = 0;
    virtual float GetTotalMaxHealth_Impl() const = 0;
    virtual bool IsDead_Impl() const = 0;
    virtual void SetDeadFlag() = 0;
    virtual void ClearDeadFlag() = 0;
    virtual void WriteComponents_Impl(idFile* file) const = 0;
    virtual void ReadComponents_Impl(idFile* file) = 0;

    void Reset() { Reset_Impl(); }
    void Update() { Update_Impl(); }
    bool Damage(float damage, bool allowDeath, float& remainingDamage) {
        return Damage_Impl(damage, allowDeath, remainingDamage);
    }
    void Kill(float damage);
    bool HasMaxCurBaseHealth() const;
    void SetCurBaseHealth(float health);
    float GetCurBaseHealth() const { return GetComponentCur_Impl(0); }
    float GetMaxBaseHealth() const { return GetComponentMax_Impl(0); }
    bool IsDead() const { return IsDead_Impl(); }
};

class idTungstenHealth : public idBaseHealth {
public:
    struct component_t {
        float cur{0.0f};
        float max{100.0f};
    };

    idTungstenHealth();
    idTungstenHealth(float health, float armor);

    void Reset_Impl() override;
    void Update_Impl() override;
    bool Damage_Impl(float damage, bool allowDeath,
        float& remainingDamage) override;
    bool DamageComponent_Impl(int type, float damage, bool allowDeath,
        bool overflow, float& remainingDamage) override;
    void HealComponent_Impl(int type, float health, bool overflow) override;
    float GetComponentCur_Impl(int type) const override;
    float GetComponentMax_Impl(int type) const override;
    void SetComponentCur_Impl(int type, float health) override;
    void SetComponentMax_Impl(int type, float health) override;
    float GetTotalCurHealth_Impl() const override;
    float GetTotalMaxHealth_Impl() const override;
    bool IsDead_Impl() const override { return isDead; }
    void SetDeadFlag() override;
    void ClearDeadFlag() override { isDead = false; }
    void WriteComponents_Impl(idFile* file) const override;
    void ReadComponents_Impl(idFile* file) override;

    float GetBaseHealthRatio_Impl() const;
    float GetTotalHealthRatio_Impl() const;
    void SetCurBaseHealth_Impl(float health);

    component_t components[2];
    int lastUpdateTime;
    int lastDamageTime;
    bool isDead;
};

class idSimpleHealth : public idTungstenHealth {
public:
    using idTungstenHealth::idTungstenHealth;
};
class idAIHealth : public idTungstenHealth {
public:
    using idTungstenHealth::idTungstenHealth;
};
class idVehicleHealth : public idTungstenHealth {
public:
    using idTungstenHealth::idTungstenHealth;
};

void ReportDamage(idTungstenHealth& health, float damage, bool allowDeath);
void testHealthComponent_f(const idCmdArgs& args);
