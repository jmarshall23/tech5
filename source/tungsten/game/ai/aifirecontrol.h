#pragma once

#include "animfsm/aianimwebstate.h"

class idAI2;
class idAIEntityState;
class idWeapon;

enum aiFireMode_t : int {
    FIREMODE_WEAPON = 0,
    FIREMODE_HOLDFIRE = 1,
    FIREMODE_FIREWHENREADY = 2,
    FIREMODE_SPRAYWHENREADY = 3,
    FIREMODE_MAX = 4
};

struct updateWeaponStateParms_t {
    enum fireType_t : int {
        WFT_SINGLE = 0,
        WFT_AUTO = 1,
        WFT_SPRAY = 2
    } fireType;
    int numBlockedShotsConsecutiveToReleaseTrigger;
    float percentBlockedShotsToReleaseTrigger;

    updateWeaponStateParms_t()
        : fireType(WFT_SINGLE),
          numBlockedShotsConsecutiveToReleaseTrigger(0),
          percentBlockedShotsToReleaseTrigger(0.0f) {
    }
};

class idAIFireControl;

struct idAIFireControlCall {
    const char* operation;
    idAI2* owner;
    idWeapon* weapon;
    const idAIEntityState* entityState;
    const void* object;
    int integers[8];
    float scalars[4];
    bool booleans[4];
    bool boolResult;

    explicit idAIFireControlCall(const char* operationValue)
        : operation(operationValue), owner(nullptr), weapon(nullptr),
          entityState(nullptr), object(nullptr), integers{}, scalars{},
          booleans{}, boolResult(false) {
    }
};

using idAIFireControlTimeProvider = int (*)();
using idAIFireControlWeaponSlotResolver = int (*)(const idWeapon*);

void Tungsten_SetAIFireControlTimeProvider(
    idAIFireControlTimeProvider provider);
void Tungsten_SetAIFireControlWeaponSlotResolver(
    idAIFireControlWeaponSlotResolver resolver);

class idAIFireControl {
public:
    struct weaponInfo_t {
        equipSlot_t slot;
    };

    idAIFireControl();
    virtual ~idAIFireControl() = default;

    virtual void DormantEnd(int timeDormant) {}
    virtual int GetNextPullTriggerTime(const idWeapon*) const {
        return -1;
    }
    virtual void ResetNextPullTriggerTime(idAI2*) {}
    virtual void Update_Weapon(idAI2* owner, int currentTime);
    virtual void Update_HoldFire(idAI2* owner, int currentTime);
    virtual void Update_FireWhenReady(idAI2* owner, int currentTime);
    virtual void Update_SprayWhenReady(idAI2* owner, int currentTime);
    virtual int NumWeaponInfos() const { return 0; }
    virtual const weaponInfo_t& GetWeaponInfo(int index) const;
    virtual bool CanFireWeapons(idAI2* owner,
        const idAIEntityState* entityState, int currentTime) const;
    virtual void SetNextPullTriggerTime(
        const idWeapon* weapon, int time) {}
    virtual void SetEndBurstTime(const idWeapon* weapon, int time) {}
    virtual int GetEndBurstTime(const idWeapon* weapon) const {
        return -1;
    }
    virtual void SetFireAtLastKnownDuration(
        const idWeapon* weapon, int duration) {}
    virtual int GetFireAtLastKnownDuration(
        const idWeapon* weapon) const { return -1; }

    void SetFireMode(idAI2* owner, aiFireMode_t mode);
    void InhibitFire(const idWeapon* weapon, int inhibitLength);
    void ClearInhibitFire(const idWeapon* weapon);
    void Update(idAI2* owner, int currentTime);

    aiFireMode_t GetFireMode() const { return fireMode; }
    bool HasFreeAmmo() const { return freeAmmo; }
    bool AllowsReloads() const { return allowReloads; }

protected:
    bool CanFireWeapon(idAI2* owner, idWeapon* weapon,
        const idAIEntityState* entityState, int currentTime);
    bool CheckReleaseTrigger(idAI2* owner, idWeapon* weapon,
        const idAIEntityState* entityState, int currentTime,
        const weaponInfo_t& info);
    bool CheckPullTrigger(idAI2* owner, idWeapon* weapon,
        const idAIEntityState* entityState, int currentTime,
        const weaponInfo_t& info);
    void PullWeaponTrigger(idAI2* owner, idWeapon* weapon,
        const idAIEntityState* entityState, int currentTime);
    void ReleaseWeaponTrigger(idAI2* owner, idWeapon* weapon,
        int currentTime);
    void UpdateWeaponState(idAI2* owner, idWeapon* weapon,
        const idAIEntityState* entityState, int currentTime,
        const weaponInfo_t& info,
        const updateWeaponStateParms_t& parameters);

    void Dispatch(idAI2* owner, idAIFireControlCall& call) const;

    aiFireMode_t fireMode;
    bool freeAmmo;
    bool allowReloads;
};

class idAIFireControl_Human : public idAIFireControl {
public:
    struct fcWeaponState_t {
        int nextPullTriggerTime;
        int endBurstTime;
        int fireAtLastKnownDuration;
    };

    idAIFireControl_Human();
    ~idAIFireControl_Human() override = default;

    void DormantEnd(int timeDormant) override;
    int GetNextPullTriggerTime(const idWeapon* weapon) const override;
    void ResetNextPullTriggerTime(idAI2* owner) override;
    int NumWeaponInfos() const override { return 2; }
    const weaponInfo_t& GetWeaponInfo(int index) const override;
    void SetNextPullTriggerTime(
        const idWeapon* weapon, int time) override;
    void SetEndBurstTime(const idWeapon* weapon, int time) override;
    int GetEndBurstTime(const idWeapon* weapon) const override;
    void SetFireAtLastKnownDuration(
        const idWeapon* weapon, int duration) override;
    int GetFireAtLastKnownDuration(
        const idWeapon* weapon) const override;

private:
    int WeaponStateIndex(const idWeapon* weapon) const;

    fcWeaponState_t weaponStates[2];
    static const weaponInfo_t weaponInfos[2];
};
