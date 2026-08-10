#pragma once

#include "../../../shared/idlib/containers/list.h"
#include "../../../shared/idlib/text/str.h"

class idBot;
struct idBotWeapon;

enum botWeaponPriority_t : int {
    WEAPON_PRIORITY_NULL = 0,
    WEAPON_PRIORITY_BEHAVIOR_DRIVEN = 1,
    WEAPON_PRIORITY_MAX = 2
};

enum botWeaponSlots_t : int {
    WEAPON_SLOT_MELEE = 0,
    WEAPON_SLOT_PRIMARY = 1,
    WEAPON_SLOT_SECONDARY = 2,
    WEAPON_SLOT_EXPLOSIVE = 3,
    WEAPON_SLOT_MAX = 4
};

enum botWeaponFireMode_t : int {
    WEAPON_FIRE_MODE_HOLD = 0,
    WEAPON_FIRE_MODE_FORCE = 1,
    WEAPON_FIRE_MODE_FORCE_ONCE = 2,
    WEAPON_FIRE_MODE_WHEN_READY = 3,
    WEAPON_MODE_MAX = 4
};

enum botWeaponCategory_t : int {
    WEAPON_CATEGORY_MELEE = 0,
    WEAPON_CATEGORY_SMG = 1,
    WEAPON_CATEGORY_SHOTGUN = 2,
    WEAPON_CATEGORY_SNIPER = 3,
    WEAPON_CATEGORY_THROWN = 4,
    WEAPON_CATEGORY_MAX = 5
};

class idBotWeaponState {
public:
    struct BotWeaponRequest_t {
        BotWeaponRequest_t();

        botWeaponPriority_t weaponPriority;
        botWeaponSlots_t weaponSlot;
        botWeaponFireMode_t weaponFireMode;
        idBotWeapon* weaponHandler;
        idStr weaponUserName;
    };

    idBotWeaponState();
    ~idBotWeaponState();

    int FindIndexOfWeaponRequestUser(const char* userName) const;

    idBot* owner;
    BotWeaponRequest_t weaponRequests[4];
    idList<idBotWeapon*, 5> weapons;
    botWeaponCategory_t currentWeaponCategory;
};

static_assert(sizeof(idBotWeaponState::BotWeaponRequest_t) == 48,
    "Recovered bot weapon request ABI changed");
#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idBotWeaponState) == 216,
    "Recovered bot weapon state ABI changed");
#endif

