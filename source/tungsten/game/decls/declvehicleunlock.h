#pragma once

#include "game/decls/declmenuitems.h"
#include "decls/decltypeinfo.h"
#include "idlib/containers/hashtable.h"
#include "idlib/containers/list.h"
#include "idlib/langdict.h"
#include "idlib/text/str.h"

class idDeclEntityDef;
class idDeclInventory;
class idMaterial;
class idSoundShader;
class idParser;
enum rageStat_t : int;

enum vehicleUnlockType_t : int {
    UNLOCK_TYPE_NONE = 0,
    UNLOCK_TYPE_VEHICLE_CLASS = 1,
    UNLOCK_TYPE_VEHICLE = 2,
    UNLOCK_TYPE_WEAPON_PRIMARY = 3,
    UNLOCK_TYPE_WEAPON_SECONDARY = 4,
    UNLOCK_TYPE_QUICK_USE_1 = 5,
    UNLOCK_TYPE_QUICK_USE_2 = 6,
    UNLOCK_TYPE_MAX = 7
};

enum itemUnlockType_t : int {
    ITEM_UNLOCK_NONE = 0,
    ITEM_UNLOCK_VEHICLE_CLASS = 1,
    ITEM_UNLOCK_VEHICLE = 2,
    ITEM_UNLOCK_WEAPON_PRIMARY_LEFT = 3,
    ITEM_UNLOCK_WEAPON_PRIMARY_RIGHT = 4,
    ITEM_UNLOCK_WEAPON_PRIMARY_AMMO = 5,
    ITEM_UNLOCK_WEAPON_SECONDARY_LEFT = 6,
    ITEM_UNLOCK_WEAPON_SECONDARY_RIGHT = 7,
    ITEM_UNLOCK_WEAPON_SECONDARY_AMMO = 8,
    ITEM_UNLOCK_QUICK_USE = 9,
    ITEM_UNLOCK_PVP = 10,
    ITEM_UNLOCK_MAX = 11
};

enum vehicleType_t : int {
    VEHICLE_TYPE_NONE = 0,
    VEHICLE_TYPE_BUGGY = 1,
    VEHICLE_TYPE_MONARCH = 2,
    VEHICLE_TYPE_CUPRINO = 3,
    VEHICLE_TYPE_REGIME = 4,
    VEHICLE_TYPE_ALL = 5,
    VEHICLE_TYPE_MAX = 6
};

class idDeclVehicleUnlock : public idDeclTypeInfo {
public:
    struct inventoryUnlock_t {
        idStr itemDeclStr;
        idStr entityDefStr;
        idStr soundDeclStr;
        int count;
        itemUnlockType_t itemType;
        vehicleType_t vehicleType;
    };

    idDeclVehicleUnlock();
    ~idDeclVehicleUnlock() override;

    idDeclInfo* GetDeclInfo() const override { return &resourceList; }
    void Parse(idParser* parser) override;

    static vehicleUnlockType_t GetUnlockTypeForSlot(
        vehicleLoadoutSlot_t slot);
    const char* GetBigLoadoutImageName() const;
    static const idDeclInventory* GetInventoryDecl(
        const inventoryUnlock_t& unlock);
    static const idDeclEntityDef* GetEntityDef(
        const inventoryUnlock_t& unlock);
    static const idSoundShader* GetSoundShader(
        const inventoryUnlock_t& unlock);
    static const idDeclVehicleUnlock* GetUnlockByOrdinal(int ordinal);
    static void LoadAllDecls();

    vehicleUnlockType_t unlockType;
    int levelRequired;
    idStrId displayName;
    int quantity;
    int rangeRank;
    int damageRank;
    int accuracyRank;
    int rateOfFireRank;
    idStrId description;
    const idMaterial* loadoutIcon;
    const idMaterial* bigLoadoutIcon;
    const idDeclVehicleUnlock* upgradeTo;
    int spRequired;
    rageStat_t metricType;
    int ordinal;
    idList<inventoryUnlock_t, 5> items;

    static idHashTableT<int, const idDeclVehicleUnlock*> unlockLookup;
    static idDeclInfoTemplate<idDeclVehicleUnlock> resourceList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclVehicleUnlock::inventoryUnlock_t) == 108,
    "Recovered vehicle-unlock item ABI changed");
static_assert(sizeof(idDeclVehicleUnlock) == 140,
    "Recovered vehicle-unlock declaration ABI changed");
#endif
