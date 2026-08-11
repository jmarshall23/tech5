#include "ai2.h"
#include "aifirecontrol.h"

#include <algorithm>

namespace {

idAIFireControlTimeProvider g_timeProvider = nullptr;
idAIFireControlWeaponSlotResolver g_slotResolver = nullptr;

int CurrentTime() {
    return g_timeProvider != nullptr ? g_timeProvider() : 0;
}

} // namespace

void Tungsten_SetAIFireControlTimeProvider(
        const idAIFireControlTimeProvider provider) {
    g_timeProvider = provider;
}

void Tungsten_SetAIFireControlWeaponSlotResolver(
        const idAIFireControlWeaponSlotResolver resolver) {
    g_slotResolver = resolver;
}

const idAIFireControl::weaponInfo_t
    idAIFireControl_Human::weaponInfos[2] = {
        { EQUIP_RIGHT_HAND },
        { EQUIP_LEFT_HAND }
    };

idAIFireControl::idAIFireControl()
    : fireMode(FIREMODE_HOLDFIRE), freeAmmo(true),
      allowReloads(false) {
}

const idAIFireControl::weaponInfo_t&
idAIFireControl::GetWeaponInfo(int) const {
    static const weaponInfo_t empty = { EQUIP_NONE };
    return empty;
}

void idAIFireControl::Dispatch(idAI2* const owner,
        idAIFireControlCall& call) const {
    call.owner = owner;
    if (owner != nullptr && owner->core.services != nullptr) {
        owner->core.services->DispatchAIFireControl(
            const_cast<idAIFireControl&>(*this), call);
    }
}

// Retail symbol: ?SetFireMode@idAIFireControl@@QAAXPAVidAI2@@W4aiFireMode_t@@@Z
// EA: 0x82A47E70, RVA: 0x00A47E70
void idAIFireControl::SetFireMode(idAI2* const owner,
        const aiFireMode_t mode) {
    if (fireMode == mode) {
        return;
    }
    fireMode = mode;
    idAIFireControlCall call("SetFireMode");
    call.integers[0] = static_cast<int>(mode);
    Dispatch(owner, call);
}

// Retail symbol: ?GetWeaponInfo@idAIFireControl_Human@@MBAABUweaponInfo_t@idAIFireControl@@H@Z
// EA: 0x82A47F20, RVA: 0x00A47F20
const idAIFireControl::weaponInfo_t&
idAIFireControl_Human::GetWeaponInfo(const int index) const {
    return weaponInfos[index >= 0 && index < 2 ? index : 0];
}

// Retail symbol: ?DormantEnd@idAIFireControl_Human@@UAAXH@Z
// EA: 0x82A47F38, RVA: 0x00A47F38
void idAIFireControl_Human::DormantEnd(const int timeDormant) {
    for (fcWeaponState_t& state : weaponStates) {
        state.nextPullTriggerTime += timeDormant;
        state.endBurstTime += timeDormant;
    }
}

// Retail symbol: ?InhibitFire@idAIFireControl@@QAAXPBVidWeapon@@H@Z
// EA: 0x82A47F70, RVA: 0x00A47F70
void idAIFireControl::InhibitFire(const idWeapon* const weapon,
        const int inhibitLength) {
    const int inhibitUntil = CurrentTime() + inhibitLength;
    if (GetNextPullTriggerTime(weapon) < inhibitUntil) {
        SetNextPullTriggerTime(weapon, inhibitUntil);
    }
}

// Retail symbol: ?ClearInhibitFire@idAIFireControl@@QAAXPBVidWeapon@@@Z
// EA: 0x82A48000, RVA: 0x00A48000
void idAIFireControl::ClearInhibitFire(const idWeapon* const weapon) {
    SetNextPullTriggerTime(weapon, CurrentTime());
}

// Retail symbol: ??0idAIFireControl_Human@@QAA@XZ
// EA: 0x82A48068, RVA: 0x00A48068
idAIFireControl_Human::idAIFireControl_Human()
    : idAIFireControl(), weaponStates{
        { -1, -1, -1 }, { -1, -1, -1 }} {
}

int idAIFireControl_Human::WeaponStateIndex(
        const idWeapon* const weapon) const {
    const int slot = g_slotResolver != nullptr
        ? g_slotResolver(weapon) : EQUIP_RIGHT_HAND;
    return slot == EQUIP_LEFT_HAND ? 1 : 0;
}

// Retail symbol: ?SetNextPullTriggerTime@idAIFireControl_Human@@MAAXPBVidWeapon@@H@Z
// EA: 0x82A480C8, RVA: 0x00A480C8
void idAIFireControl_Human::SetNextPullTriggerTime(
        const idWeapon* const weapon, const int time) {
    weaponStates[WeaponStateIndex(weapon)].nextPullTriggerTime = time;
}

// Retail symbol: ?GetNextPullTriggerTime@idAIFireControl_Human@@MBAHPBVidWeapon@@@Z
// EA: 0x82A480F8, RVA: 0x00A480F8
int idAIFireControl_Human::GetNextPullTriggerTime(
        const idWeapon* const weapon) const {
    return weaponStates[WeaponStateIndex(weapon)].nextPullTriggerTime;
}

// Retail symbol: ?ResetNextPullTriggerTime@idAIFireControl_Human@@UAAXPAVidAI2@@@Z
// EA: 0x82A48128, RVA: 0x00A48128
void idAIFireControl_Human::ResetNextPullTriggerTime(idAI2*) {
    weaponStates[0].nextPullTriggerTime = 0;
    weaponStates[1].nextPullTriggerTime = 0;
}

// Retail symbol: ?SetEndBurstTime@idAIFireControl_Human@@MAAXPBVidWeapon@@H@Z
// EA: 0x82A481E8, RVA: 0x00A481E8
void idAIFireControl_Human::SetEndBurstTime(
        const idWeapon* const weapon, const int time) {
    weaponStates[WeaponStateIndex(weapon)].endBurstTime = time;
}

// Retail symbol: ?GetEndBurstTime@idAIFireControl_Human@@MBAHPBVidWeapon@@@Z
// EA: 0x82A48218, RVA: 0x00A48218
int idAIFireControl_Human::GetEndBurstTime(
        const idWeapon* const weapon) const {
    return weaponStates[WeaponStateIndex(weapon)].endBurstTime;
}

// Retail symbol: ?SetFireAtLastKnownDuration@idAIFireControl_Human@@MAAXPBVidWeapon@@H@Z
// EA: 0x82A48248, RVA: 0x00A48248
void idAIFireControl_Human::SetFireAtLastKnownDuration(
        const idWeapon* const weapon, const int duration) {
    weaponStates[WeaponStateIndex(weapon)].fireAtLastKnownDuration
        = duration;
}

// Retail symbol: ?GetFireAtLastKnownDuration@idAIFireControl_Human@@MBAHPBVidWeapon@@@Z
// EA: 0x82A48278, RVA: 0x00A48278
int idAIFireControl_Human::GetFireAtLastKnownDuration(
        const idWeapon* const weapon) const {
    return weaponStates[WeaponStateIndex(weapon)]
        .fireAtLastKnownDuration;
}

// Retail symbol: ?CanFireWeapons@idAIFireControl@@MBA_NPAVidAI2@@PBVidAIEntityState@@H@Z
// EA: 0x82A482F0, RVA: 0x00A482F0
bool idAIFireControl::CanFireWeapons(idAI2* const owner,
        const idAIEntityState* const entityState,
        const int currentTime) const {
    idAIFireControlCall call("CanFireWeapons");
    call.entityState = entityState;
    call.integers[0] = currentTime;
    Dispatch(owner, call);
    return call.boolResult;
}

// Retail symbol: ?Update@idAIFireControl@@QAAXPAVidAI2@@H@Z
// EA: 0x82A48378, RVA: 0x00A48378
void idAIFireControl::Update(idAI2* const owner,
        const int currentTime) {
    if (owner == nullptr) {
        return;
    }
    if (owner->core.actionScriptRunning) {
        Update_Weapon(owner, currentTime);
        return;
    }
    switch (fireMode) {
        case FIREMODE_WEAPON:
            Update_Weapon(owner, currentTime);
            break;
        case FIREMODE_HOLDFIRE:
            Update_HoldFire(owner, currentTime);
            break;
        case FIREMODE_FIREWHENREADY:
            Update_FireWhenReady(owner, currentTime);
            break;
        case FIREMODE_SPRAYWHENREADY:
            Update_SprayWhenReady(owner, currentTime);
            break;
        default:
            break;
    }
}

// Retail symbol: ?CanFireWeapon@idAIFireControl@@IAA_NPAVidAI2@@PAVidWeapon@@PBVidAIEntityState@@H@Z
// EA: 0x82A48558, RVA: 0x00A48558
bool idAIFireControl::CanFireWeapon(idAI2* const owner,
        idWeapon* const weapon,
        const idAIEntityState* const entityState,
        const int currentTime) {
    idAIFireControlCall call("CanFireWeapon");
    call.weapon = weapon;
    call.entityState = entityState;
    call.integers[0] = currentTime;
    Dispatch(owner, call);
    return call.boolResult;
}

// Retail symbol: ?CheckReleaseTrigger@idAIFireControl@@IAA_NPAVidAI2@@PAVidWeapon@@PBVidAIEntityState@@HABUweaponInfo_t@1@@Z
// EA: 0x82A48A38, RVA: 0x00A48A38
bool idAIFireControl::CheckReleaseTrigger(idAI2* const owner,
        idWeapon* const weapon,
        const idAIEntityState* const entityState,
        const int currentTime, const weaponInfo_t& info) {
    idAIFireControlCall call("CheckReleaseTrigger");
    call.weapon = weapon;
    call.entityState = entityState;
    call.object = &info;
    call.integers[0] = currentTime;
    call.integers[1] = static_cast<int>(info.slot);
    Dispatch(owner, call);
    return call.boolResult;
}

// Retail symbol: ?CheckPullTrigger@idAIFireControl@@IAA_NPAVidAI2@@PAVidWeapon@@PBVidAIEntityState@@HABUweaponInfo_t@1@@Z
// EA: 0x82A48B98, RVA: 0x00A48B98
bool idAIFireControl::CheckPullTrigger(idAI2* const owner,
        idWeapon* const weapon,
        const idAIEntityState* const entityState,
        const int currentTime, const weaponInfo_t& info) {
    idAIFireControlCall call("CheckPullTrigger");
    call.weapon = weapon;
    call.entityState = entityState;
    call.object = &info;
    call.integers[0] = currentTime;
    call.integers[1] = static_cast<int>(info.slot);
    Dispatch(owner, call);
    return call.boolResult;
}

// Retail symbol: ?PullWeaponTrigger@idAIFireControl@@IAAXPAVidAI2@@PAVidWeapon@@PBVidAIEntityState@@H@Z
// EA: 0x82A48DE0, RVA: 0x00A48DE0
void idAIFireControl::PullWeaponTrigger(idAI2* const owner,
        idWeapon* const weapon,
        const idAIEntityState* const entityState,
        const int currentTime) {
    idAIFireControlCall call("PullWeaponTrigger");
    call.weapon = weapon;
    call.entityState = entityState;
    call.integers[0] = currentTime;
    Dispatch(owner, call);
}

// Retail symbol: ?ReleaseWeaponTrigger@idAIFireControl@@IAAXPAVidAI2@@PAVidWeapon@@H@Z
// EA: 0x82A48FA8, RVA: 0x00A48FA8
void idAIFireControl::ReleaseWeaponTrigger(idAI2* const owner,
        idWeapon* const weapon, const int currentTime) {
    idAIFireControlCall call("ReleaseWeaponTrigger");
    call.weapon = weapon;
    call.integers[0] = currentTime;
    Dispatch(owner, call);
}

// Retail symbol: ?UpdateWeaponState@idAIFireControl@@AAAXPAVidAI2@@PAVidWeapon@@PBVidAIEntityState@@HABUweaponInfo_t@1@ABUupdateWeaponStateParms_t@@@Z
// EA: 0x82A49148, RVA: 0x00A49148
void idAIFireControl::UpdateWeaponState(idAI2* const owner,
        idWeapon* const weapon,
        const idAIEntityState* const entityState,
        const int currentTime, const weaponInfo_t& info,
        const updateWeaponStateParms_t& parameters) {
    idAIFireControlCall call("UpdateWeaponState");
    call.weapon = weapon;
    call.entityState = entityState;
    call.object = &parameters;
    call.integers[0] = currentTime;
    call.integers[1] = static_cast<int>(info.slot);
    call.integers[2] = static_cast<int>(parameters.fireType);
    call.integers[3]
        = parameters.numBlockedShotsConsecutiveToReleaseTrigger;
    call.scalars[0]
        = parameters.percentBlockedShotsToReleaseTrigger;
    Dispatch(owner, call);
}

// Retail symbol: ?Update_Weapon@idAIFireControl@@MAAXPAVidAI2@@H@Z
// EA: 0x82A49B70, RVA: 0x00A49B70
void idAIFireControl::Update_Weapon(idAI2* const owner,
        const int currentTime) {
    idAIFireControlCall call("Update_Weapon");
    call.integers[0] = currentTime;
    Dispatch(owner, call);
}

// Retail symbol: ?Update_HoldFire@idAIFireControl@@MAAXPAVidAI2@@H@Z
// EA: 0x82A49D98, RVA: 0x00A49D98
void idAIFireControl::Update_HoldFire(idAI2* const owner,
        const int currentTime) {
    idAIFireControlCall call("Update_HoldFire");
    call.integers[0] = currentTime;
    Dispatch(owner, call);
}

// Retail symbol: ?Update_FireWhenReady@idAIFireControl@@MAAXPAVidAI2@@H@Z
// EA: 0x82A49FA0, RVA: 0x00A49FA0
void idAIFireControl::Update_FireWhenReady(idAI2* const owner,
        const int currentTime) {
    idAIFireControlCall call("Update_FireWhenReady");
    call.integers[0] = currentTime;
    Dispatch(owner, call);
}

// Retail symbol: ?Update_SprayWhenReady@idAIFireControl@@MAAXPAVidAI2@@H@Z
// EA: 0x82A4A378, RVA: 0x00A4A378
void idAIFireControl::Update_SprayWhenReady(idAI2* const owner,
        const int currentTime) {
    idAIFireControlCall call("Update_SprayWhenReady");
    call.integers[0] = currentTime;
    Dispatch(owner, call);
}
