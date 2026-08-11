#include "healthcomponent.h"

#include <algorithm>
#include <cmath>

namespace {

idTungstenHealthServices defaultHealthServices;
idTungstenHealthServices* healthServices = &defaultHealthServices;

bool ValidComponent(int type) { return type >= 0 && type < 2; }

} // namespace

void Tungsten_SetHealthComponentServices(idTungstenHealthServices* services) {
    healthServices = services != nullptr ? services : &defaultHealthServices;
}

void idBaseHealth::Kill(float damage) {
    idTungstenHealth* tungsten = dynamic_cast<idTungstenHealth*>(this);
    if (tungsten != nullptr) healthServices->Killed(*tungsten, damage);
    SetDeadFlag();
}

bool idBaseHealth::HasMaxCurBaseHealth() const {
    return GetCurBaseHealth() >= GetMaxBaseHealth();
}

void idBaseHealth::SetCurBaseHealth(float health) {
    if (health > 0.0f) {
        ClearDeadFlag();
        SetComponentCur_Impl(0, health);
    }
}

// EA 0x82BB56B0
void idTungstenHealth::Reset_Impl() {
    lastUpdateTime = 0;
    lastDamageTime = 0;
    isDead = false;
    components[0].max = 100.0f;
    components[1].max = 100.0f;
    components[0].cur = 100.0f;
    components[1].cur = 0.0f;
}

// EA 0x82BB56E0
bool idTungstenHealth::DamageComponent_Impl(int, float, bool, bool,
        float& remainingDamage) {
    remainingDamage = 0.0f;
    return false;
}

// EA 0x82BB56F8
void idTungstenHealth::HealComponent_Impl(int type, float health, bool) {
    if (ValidComponent(type)) components[type].cur += health;
}

// EA 0x82BB5718
float idTungstenHealth::GetTotalCurHealth_Impl() const {
    return components[0].cur + components[1].cur;
}

// EA 0x82BB5728
float idTungstenHealth::GetTotalMaxHealth_Impl() const {
    return components[0].max + components[1].max;
}

// EA 0x82BB5738
void ReportDamage(idTungstenHealth& health, float damage, bool allowDeath) {
    float remainingDamage = 0.0f;
    const bool killed = health.Damage_Impl(damage, allowDeath,
        remainingDamage);
    healthServices->DamageReported(health, damage, killed, remainingDamage);
}

// EA 0x82BB5878
idTungstenHealth::idTungstenHealth() {
    Reset_Impl();
}

// EA 0x82BB5A38
void idTungstenHealth::SetDeadFlag() {
    isDead = true;
}

// EA 0x82BB5AA8
idTungstenHealth::idTungstenHealth(float health, float armor) {
    Reset_Impl();
    components[0].cur = health;
    components[1].cur = armor;
}

// EA 0x82BB5B48
void idTungstenHealth::Update_Impl() {
    const int currentTime = healthServices->GetGameTime();
    if (lastUpdateTime != -1) {
        const float elapsed = std::max(0, currentTime - lastUpdateTime)
            * 0.001f;
        component_t& hitpoints = components[0];
        if (hitpoints.cur < hitpoints.max
                && currentTime > lastDamageTime
                    + static_cast<int>(healthServices->GetRegenDelaySeconds()
                        * 1000.0f)) {
            const int stepCount = std::max(1, healthServices->GetRegenSteps());
            const float stepSize = hitpoints.max / stepCount;
            const float threshold = std::min(hitpoints.max,
                std::ceil(hitpoints.cur / stepSize) * stepSize);
            hitpoints.cur = std::min(threshold,
                hitpoints.cur + healthServices->GetRegenSpeed() * elapsed);
        }
        for (component_t& component : components) {
            if (component.cur > component.max) {
                component.cur = std::max(component.max,
                    component.cur - healthServices->GetDecaySpeed()
                        * elapsed);
            }
        }
    }
    lastUpdateTime = currentTime;
}

// EA 0x82BB5CD0
bool idTungstenHealth::Damage_Impl(float damage, bool allowDeath,
        float& remainingDamage) {
    lastDamageTime = healthServices->GetGameTime();
    const float armorAbsorbed = std::min(std::max(damage, 0.0f),
        components[1].cur);
    components[1].cur -= armorAbsorbed;
    float healthDamage = std::max(damage - armorAbsorbed, 0.0f)
        + armorAbsorbed * 0.2f;
    if (!allowDeath) {
        healthDamage = std::min(healthDamage,
            std::max(components[0].cur - 1.0f, 0.0f));
    }
    remainingDamage = 0.0f;
    if (healthDamage <= components[0].cur) {
        components[0].cur -= healthDamage;
        return false;
    }
    remainingDamage = healthDamage - components[0].cur;
    components[0].cur = 0.0f;
    Kill(damage);
    return true;
}

// EA 0x82BB5E08
void idTungstenHealth::WriteComponents_Impl(idFile* file) const {
    if (file == nullptr) return;
    for (const component_t& component : components) {
        file->Write(&component.max, sizeof(component.max));
        file->Write(&component.cur, sizeof(component.cur));
    }
    file->Write(&isDead, sizeof(isDead));
}

// EA 0x82BB5E98
void testHealthComponent_f(const idCmdArgs&) {
    const float values[] = {200.0f, 200.1f, 201.0f, 50.0f, 150.0f};
    for (float value : values) {
        idTungstenHealth health(100.0f, 100.0f);
        ReportDamage(health, value, true);
    }
}

// EA 0x82BB6050
void idTungstenHealth::ReadComponents_Impl(idFile* file) {
    if (file == nullptr) return;
    for (component_t& component : components) {
        file->Read(&component.max, sizeof(component.max));
        file->Read(&component.cur, sizeof(component.cur));
    }
    file->Read(&isDead, sizeof(isDead));
}

float idTungstenHealth::GetComponentCur_Impl(int type) const {
    return ValidComponent(type) ? components[type].cur : 0.0f;
}

float idTungstenHealth::GetComponentMax_Impl(int type) const {
    return ValidComponent(type) ? components[type].max : 0.0f;
}

void idTungstenHealth::SetComponentCur_Impl(int type, float health) {
    if (ValidComponent(type)) components[type].cur = health;
}

void idTungstenHealth::SetComponentMax_Impl(int type, float health) {
    if (ValidComponent(type)) components[type].max = health;
}

float idTungstenHealth::GetBaseHealthRatio_Impl() const {
    return components[0].max > 0.0f
        ? components[0].cur / components[0].max : 0.0f;
}

float idTungstenHealth::GetTotalHealthRatio_Impl() const {
    const float maximum = GetTotalMaxHealth_Impl();
    return maximum > 0.0f ? GetTotalCurHealth_Impl() / maximum : 0.0f;
}

void idTungstenHealth::SetCurBaseHealth_Impl(float health) {
    components[0].cur = health;
}
