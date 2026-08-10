#pragma once

#include "../../../engine/decls/decltypeinfo.h"
#include "idlib/containers/list.h"
#include "idlib/text/str.h"

class idMaterial;

enum vehicleLoadoutSlot_t : int {
    LOADOUT_SLOT_VEHICLE_CLASS = 0,
    LOADOUT_SLOT_VEHICLE = 1,
    LOADOUT_SLOT_WEAPON_PRIMARY = 2,
    LOADOUT_SLOT_WEAPON_SECONDARY = 3,
    LOADOUT_SLOT_QUICK_USE_1 = 4,
    LOADOUT_SLOT_QUICK_USE_2 = 5,
    LOADOUT_SLOT_MAX = 6
};

class idDeclMenuItem : public idDeclTypeInfo {
public:
    idDeclMenuItem();
    ~idDeclMenuItem() override;

    idDeclInfo* GetDeclInfo() const override { return &resourceList; }
    static void LoadAllDecls();

    const idMaterial* material;
    idStr title;
    idStr help;
    vehicleLoadoutSlot_t loadoutSlot;
    int index;

    static idDeclInfoTemplate<idDeclMenuItem> resourceList;
    static idList<const idDeclMenuItem*, 5> orderedList;
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idDeclMenuItem) == 140,
    "Recovered menu-item declaration ABI changed");
#endif
