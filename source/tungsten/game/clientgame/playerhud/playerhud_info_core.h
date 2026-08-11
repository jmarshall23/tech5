#pragma once

#include "../../../../shared/idlib/langdict.h"
#include "../../../../shared/idlib/text/str.h"

struct idHudPickupInfo {
    idHudPickupInfo();
    void Clear();

    unsigned char reserved : 2;
    bool newItem : 1;
    bool inVehicle : 1;
    bool lastItem : 1;
    bool special : 1;
    bool isWeapon : 1;
    bool show : 1;
    int count;
    int wait;
    int index;
    int itemType;
    idStr icon;
    idStrId displayName;
    bool markShown;
};

static_assert(sizeof(idHudPickupInfo) == 60,
    "Recovered HUD pickup information ABI changed");

