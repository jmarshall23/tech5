#include "game/entities/batterychargepoint.h"

#include <cmath>

namespace {
idBatteryChargePointServices defaultBatteryChargePointServices;
idBatteryChargePointServices* batteryChargePointServices =
    &defaultBatteryChargePointServices;
}

void idProp_BatteryChargePoint::SetServices(
        idBatteryChargePointServices* const services) {
    batteryChargePointServices = services == nullptr
        ? &defaultBatteryChargePointServices : services;
}

idBatteryChargePointServices& idProp_BatteryChargePoint::Services() {
    return *batteryChargePointServices;
}

// Retail: 0x82C0B370 ?BeforeUse@idProp_BatteryChargePoint@@UAA_NPAVidEntity@@@Z
bool idProp_BatteryChargePoint::BeforeUse(idEntity* const activator) {
    if (!Services().IsPlayer(activator)
            || (!Services().HasInventoryItem(activator, "lasercutter")
                && !Services().HasInventoryItem(
                    activator, "laserkraftwerk"))
            || !Services().BaseBeforeUse(*this, activator)) {
        return false;
    }
    lastChargetTime = -1;
    curChargeAmount = 0.0f;
    return true;
}

// Retail: 0x82C0B430 ?Use@idProp_BatteryChargePoint@@UAA_NPAVidEntity@@W4usableState_t@@@Z
bool idProp_BatteryChargePoint::Use(
        idEntity* const activator, const usableState_t usable) {
    if (!Services().BaseUse(*this, activator, usable)) {
        return false;
    }
    Services().SetThinkActive(*this, false);
    if (Services().IsPlayer(activator)) {
        void* cutter = nullptr;
        if (Services().GetEquippedLaserCutter(activator, cutter)) {
            Services().SetChargingEffects(
                cutter, false, activator);
        }
    }
    return true;
}

// Retail: 0x82C0B4C8 ?ModifyCrosshairInfo@idProp_BatteryChargePoint@@...
bool idProp_BatteryChargePoint::ModifyCrosshairInfo(
        const idEntity* const activator, const idFocusTrace& focusTrace,
        const usableState_t usable, idCrosshairInfo& info) const {
    const bool result = Services().BaseModifyCrosshair(
        *this, activator, &focusTrace, usable, info);
    info.useAmount = -1.0f;
    return result;
}

// Retail: 0x82C0B500 ?GetUsableState@idPlayerControlled@@UBA?AW4usableState_t@@PBVidEntity@@ABVidFocusTrace@@@Z
usableState_t idProp_BatteryChargePoint::GetUsableState(
        const idEntity*, const idFocusTrace&) const {
    return activatable ? USABLE_PROP : USABLE_NOT_USABLE;
}

// Retail: 0x82C0B520 ?Hide@idProp_BatteryChargePoint@@UAAXXZ
void idProp_BatteryChargePoint::Hide() {
    Services().Hide(*this);
    if (loopingSound != nullptr) {
        Services().StopLoopingSound(*this);
    }
}

// Retail: 0x82C0B580 ?Show@idProp_BatteryChargePoint@@UAAXXZ
void idProp_BatteryChargePoint::Show() {
    Services().Show(*this);
    if (loopingSound != nullptr) {
        Services().StartLoopingSound(*this, loopingSound);
    }
}

// Retail: 0x82C0B5E8 ?Spawn@idProp_BatteryChargePoint@@QAAXXZ
void idProp_BatteryChargePoint::Spawn() {
    if (!Services().IsRelaxedChatterEnabled(*this)
            && loopingSound != nullptr) {
        Services().StartLoopingSound(*this, loopingSound);
        Services().UpdateVisuals(*this);
    }
}

// Retail: 0x82C0B660 ?GetSoundTransform@idProp_BatteryChargePoint@@UBAXAAVidVec3@@AAVidMat3@@@Z
void idProp_BatteryChargePoint::GetSoundTransform(
        idVec3& origin, idMat3& axis) const {
    Services().GetBaseSoundTransform(*this, origin, axis);
    axis = soundTransform * axis;
    axis.OrthoNormalizeSelf();
}

// Retail: 0x82C0B840 ??0idProp_BatteryChargePoint@@QAA@XZ
idProp_BatteryChargePoint::idProp_BatteryChargePoint()
    : user(nullptr), activatable(false), lastChargetTime(-1),
      curChargeAmount(0.0f), chargePerSecond(0.0f),
      loopingSound(nullptr),
      soundTransform(0.0f, -1.0f, 0.0f,
                     1.0f,  0.0f, 0.0f,
                     0.0f,  0.0f, 1.0f) {
}

// Retail: 0x82C0B908 ?Think@idProp_BatteryChargePoint@@UAAXXZ
void idProp_BatteryChargePoint::Think() {
    Services().BaseThink(*this);
    if (user == nullptr || !Services().IsPlayer(user)) {
        Services().SetThinkActive(*this, false);
        return;
    }
    if (Services().GetFocusEntity(user)
            != reinterpret_cast<idEntity*>(this)) {
        Use(user, USABLE_PROP);
        void* cutter = nullptr;
        if (Services().GetEquippedLaserCutter(user, cutter)) {
            Services().SetChargingEffects(cutter, false, user);
        }
        Services().SetThinkActive(*this, false);
        return;
    }

    const int currentTime = Services().GetGameMilliseconds();
    if (lastChargetTime == -1) {
        lastChargetTime = currentTime;
    }
    void* cutter = nullptr;
    if (Services().GetEquippedLaserCutter(user, cutter)) {
        if (Services().IsHandsChargingBattery(user)
                && Services().GetAmmoInClipPercentage(cutter) < 1.0f) {
            const int ticksPerSecond = Services().GetTicksPerSecond();
            if (ticksPerSecond > 0) {
                curChargeAmount +=
                    static_cast<float>(currentTime - lastChargetTime)
                    / static_cast<float>(ticksPerSecond)
                    * chargePerSecond;
                if (curChargeAmount > 1.0f) {
                    const int wholeCharge = static_cast<int>(
                        std::floor(curChargeAmount));
                    curChargeAmount -= static_cast<float>(wholeCharge);
                    Services().ChargeBattery(cutter, wholeCharge);
                }
            }
            Services().SetChargingEffects(cutter, true, user);
        } else {
            Services().SetChargingEffects(cutter, false, user);
        }
        lastChargetTime = currentTime;
        return;
    }

    const int ticksPerSecond = Services().GetTicksPerSecond();
    if (currentTime > lastChargetTime + ticksPerSecond / 2) {
        idInventoryItem* const weapon =
            Services().FindChargeWeapon(user);
        if (weapon != nullptr) {
            Services().SelectChargeWeapon(user, weapon);
        }
    }
}
