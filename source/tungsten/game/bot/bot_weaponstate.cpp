#include "bot_weaponstate.h"

#include <cstring>

namespace {
idBotWeaponStateServices* g_weaponServices = nullptr;

idBotWeapon* FindLoadedWeapon(const idBotWeaponState& state,
        const char* const name) {
    if (state.owner == nullptr || g_weaponServices == nullptr) {
        return nullptr;
    }
    idBotWeapon* const weapon =
        g_weaponServices->FindWeapon(*state.owner, name);
    return weapon != nullptr
            && g_weaponServices->HasLoadedAmmo(*state.owner, *weapon)
        ? weapon : nullptr;
}
} // namespace

void Tungsten_SetBotWeaponStateServices(
        idBotWeaponStateServices* const services) {
    g_weaponServices = services;
}

// Header retail symbol: ??0BotWeaponRequest_t@idBotWeaponState@@QAA@XZ
// EA: 0x82B44420, RVA: 0x00B44420
idBotWeaponState::BotWeaponRequest_t::BotWeaponRequest_t()
    : weaponPriority(WEAPON_PRIORITY_NULL), weaponSlot(WEAPON_SLOT_MAX),
      weaponFireMode(WEAPON_FIRE_MODE_WHEN_READY), weaponHandler(nullptr),
      weaponUserName() {
}

// Retail symbol: ?Update@idBotWeaponState@@QAAXABVidVec3@@@Z
// EA: 0x82B444B8, RVA: 0x00B444B8
void idBotWeaponState::Update(const idVec3&) {
    if (owner == nullptr || g_weaponServices == nullptr) {
        return;
    }
    idBotWeapon* weapon = FindLoadedWeapon(*this, "smg_reflex_scope");
    if (weapon == nullptr) {
        weapon = FindLoadedWeapon(*this, "assault_rifle_iron_sight");
    }
    if (weapon != nullptr) {
        g_weaponServices->SelectWeapon(*owner, *weapon);
        currentWeaponCategory = WEAPON_CATEGORY_SMG;
        return;
    }
    weapon = FindLoadedWeapon(*this,
        "double_barrel_shotgun_iron_sight");
    if (weapon != nullptr) {
        g_weaponServices->SelectWeapon(*owner, *weapon);
        currentWeaponCategory = WEAPON_CATEGORY_SHOTGUN;
        return;
    }
    weapon = g_weaponServices->FindWeapon(*owner, "fists");
    if (weapon != nullptr) {
        g_weaponServices->SelectWeapon(*owner, *weapon);
        currentWeaponCategory = WEAPON_CATEGORY_MELEE;
    }
}

// Retail symbol: ?FindIndexOfWeaponRequestUser@idBotWeaponState@@QAAHPBD@Z
// EA: 0x82B447B8, RVA: 0x00B447B8
int idBotWeaponState::FindIndexOfWeaponRequestUser(
        const char* const userName) const {
    for (int index = 0; index < 4; ++index) {
        if (weaponRequests[index].weaponUserName.Length() != 0
                && idStr::Icmp(weaponRequests[index].weaponUserName.c_str(),
                    userName) == 0) {
            return index;
        }
    }
    return -1;
}

// Retail symbol: ?AddWeaponRequest@idBotWeaponState@@QAAXW4botWeaponPriority_t@@W4botWeaponSlots_t@@PBDW4botWeaponFireMode_t@@@Z
// EA: 0x82B44818, RVA: 0x00B44818
void idBotWeaponState::AddWeaponRequest(const botWeaponPriority_t,
        const botWeaponSlots_t, const char* const userName,
        const botWeaponFireMode_t) {
    // This retail routine is intentionally unfinished: it checks whether the
    // user already owns a slot, otherwise scans for a free slot, then returns
    // without mutating the request. Preserve that shipped behavior exactly.
    if (FindIndexOfWeaponRequestUser(userName) != -1) {
        return;
    }
    for (int index = 0; index < 4; ++index) {
        if (weaponRequests[index].weaponUserName.Length() == 0) {
            return;
        }
    }
}

// Retail symbol: ??0idBotWeaponState@@QAA@XZ
// EA: 0x82B44880, RVA: 0x00B44880
idBotWeaponState::idBotWeaponState()
    : owner(nullptr), weaponRequests(), weapons(0),
      currentWeaponCategory(WEAPON_CATEGORY_MAX) {
    std::memset(&weaponRequests[0], 0, sizeof(weaponRequests[0]));
}

// Retail symbol: ??1idBotWeaponState@@QAA@XZ
// EA: 0x82B44950, RVA: 0x00B44950
idBotWeaponState::~idBotWeaponState() = default;
