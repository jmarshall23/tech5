#pragma once

#include "game/player/crosshairinfo.h"
#include "idlib/math/vector.h"

class idEntity;
class idFocusTrace;
class idInventoryItem;
class idPlayer;
class idSoundShader;
class idProp_BatteryChargePoint;

class idBatteryChargePointServices {
public:
    virtual ~idBatteryChargePointServices() = default;
    virtual bool IsPlayer(idEntity*) const { return false; }
    virtual bool HasInventoryItem(idEntity*, const char*) const {
        return false;
    }
    virtual bool BaseBeforeUse(
        idProp_BatteryChargePoint&, idEntity*) { return true; }
    virtual bool BaseUse(idProp_BatteryChargePoint&, idEntity*,
        usableState_t) { return true; }
    virtual bool BaseModifyCrosshair(const idProp_BatteryChargePoint&,
        const idEntity*, const idFocusTrace*, usableState_t,
        idCrosshairInfo&) const { return true; }
    virtual void BaseThink(idProp_BatteryChargePoint&) {}
    virtual void SetThinkActive(idProp_BatteryChargePoint&, bool) {}
    virtual void Hide(idProp_BatteryChargePoint&) {}
    virtual void Show(idProp_BatteryChargePoint&) {}
    virtual void StartLoopingSound(
        idProp_BatteryChargePoint&, const idSoundShader*) {}
    virtual void StopLoopingSound(idProp_BatteryChargePoint&) {}
    virtual void UpdateVisuals(idProp_BatteryChargePoint&) {}
    virtual bool IsRelaxedChatterEnabled(
        const idProp_BatteryChargePoint&) const { return false; }
    virtual void GetBaseSoundTransform(const idProp_BatteryChargePoint&,
        idVec3& origin, idMat3& axis) const {
        origin.Zero(); axis = idMat3(1.0f);
    }
    virtual idEntity* GetFocusEntity(idEntity*) const { return nullptr; }
    virtual bool GetEquippedLaserCutter(idEntity*, void*& cutter) const {
        cutter = nullptr; return false;
    }
    virtual bool IsHandsChargingBattery(idEntity*) const { return false; }
    virtual float GetAmmoInClipPercentage(void*) const { return 1.0f; }
    virtual void ChargeBattery(void*, int) {}
    virtual void SetChargingEffects(void*, bool, idEntity*) {}
    virtual int GetGameMilliseconds() const { return 0; }
    virtual int GetTicksPerSecond() const { return 60; }
    virtual idInventoryItem* FindChargeWeapon(idEntity*) const {
        return nullptr;
    }
    virtual void SelectChargeWeapon(idEntity*, idInventoryItem*) {}
};

class idProp_BatteryChargePoint {
public:
    idProp_BatteryChargePoint();

    static void SetServices(idBatteryChargePointServices* services);
    static idBatteryChargePointServices& Services();

    virtual bool BeforeUse(idEntity* activator);
    virtual bool Use(idEntity* activator, usableState_t usable);
    virtual bool ModifyCrosshairInfo(const idEntity* activator,
        const idFocusTrace& focusTrace, usableState_t usable,
        idCrosshairInfo& info) const;
    virtual usableState_t GetUsableState(const idEntity* activator,
        const idFocusTrace& focusTrace) const;
    virtual void Hide();
    virtual void Show();
    virtual void Spawn();
    virtual void GetSoundTransform(idVec3& origin, idMat3& axis) const;
    virtual void Think();

    idEntity* user;
    bool activatable;
    int lastChargetTime;
    float curChargeAmount;
    float chargePerSecond;
    const idSoundShader* loopingSound;
    idMat3 soundTransform;
};
