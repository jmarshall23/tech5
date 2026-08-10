#pragma once

#include "idlib/color.h"
#include "idlib/containers/staticlist.h"
#include "idlib/langdict.h"

class idMaterial;
class idSoundShader;

enum usableState_t : int {
    USABLE_NOT_USABLE = 0,
    USABLE_DISABLED = 1,
    USABLE_LOOT = 2,
    USABLE_PROP = 3,
    USABLE_AI_TALK = 4,
    USABLE_AI_TOWN = 5,
    USABLE_AI_TAGGABLE = 6,
    USABLE_DOOR = 7,
    USABLE_MOVER = 8,
    USABLE_RC_PICKUP = 9,
    USABLE_VEHICLE_DRIVE = 10,
    USABLE_VEHICLE_GUNNER = 11,
    USABLE_DISASSEMBLE = 12,
    USABLE_AMMO_REFILL = 13,
    USABLE_MAX = 14
};

enum crosshairMaterial_t : int {
    CHMATERIAL_DEFAULT = 0,
    CHMATERIAL_DEFAULT_FRIENDLY = 1,
    CHMATERIAL_DEFAULT_ENEMY = 2,
    CHMATERIAL_CUSTOM = 3,
    CHMATERIAL_TALK = 4,
    CHMATERIAL_DOOR = 5,
    CHMATERIAL_MOVER = 6,
    CHMATERIAL_PROP = 7,
    CHMATERIAL_RC_PICKUP = 8,
    CHMATERIAL_BEATUP = 9,
    CHMATERIAL_VEHICLE_GUNNER = 10,
    CHMATERIAL_VEHICLE_DRIVE = 11,
    CHMATERIAL_LOOT = 12,
    CHMATERIAL_AMMO_REFILL = 13,
    CHMATERIAL_REQ_INV = 14,
    CHMATERIAL_TOWN = 15,
    CHMATERIAL_TAGGABLE = 16,
    CHMATERIAL_DISASSEMBLE = 17,
    CHMATERIAL_DOOR_LOCKED = 18,
    CHMATERIAL_MAX = 19
};

enum crosshairColorState_t : int {
    CROSSHAIR_COLOR_NORMAL = 0,
    CROSSHAIR_COLOR_NEGATIVE = 1,
    CROSSHAIR_COLOR_NEGATIVE_WITH_TEXT = 2
};

enum crosshairTextColorState_t : int {
    CROSSHAIR_TEXT_COLOR_NORMAL = 0,
    CROSSHAIR_TEXT_COLOR_NEGATIVE = 1,
    CROSSHAIR_TEXT_COLOR_SUBDUED = 2
};

struct idCrosshairCustomIcon {
    const idMaterial* material;
    int itemCount;
    bool usable;
};

int Tungsten_GetCrosshairStringId(const char* key);

class idCrosshairInfo {
public:
    enum : int {
        MAX_COMBINERS = 3,
        MAX_ICONS = 3
    };

    idCrosshairInfo();
    idCrosshairInfo(const idColor& color, const idColor& textColor,
        const char* text, crosshairMaterial_t material,
        crosshairColorState_t colorState,
        crosshairTextColorState_t textColorState,
        const idMaterial* customMaterial, const idSoundShader* hoverSound);

    static const idCrosshairInfo& GetCrosshairInfo(usableState_t usableState);

    static const idColor DEFAULT_COLOR;
    static const idColor DEFAULT_TEXT_COLOR;
    static idCrosshairInfo crosshairInfos[USABLE_MAX];

    idColor color;
    idColor textColor;
    idStrId text;
    crosshairMaterial_t material;
    crosshairColorState_t colorState;
    crosshairTextColorState_t textColorState;
    float useAmount;
    bool hideCrossHairInfo;
    const idSoundShader* hoverSound;
    bool useCheckbox;
    idStaticList<idCrosshairCustomIcon, MAX_ICONS> icons;
};

class idCrosshairCombinerInfo {
public:
    enum : int { MAX_ITEMS = 5 };

    bool hovered;
    int itemCount;
    int itemIndex;
    int itemState[MAX_ITEMS];
    const idMaterial* itemIcons[MAX_ITEMS];
};

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(idCrosshairCustomIcon) == 12,
    "Recovered crosshair custom-icon ABI changed");
static_assert(sizeof(idCrosshairInfo) == 116,
    "Recovered crosshair-info ABI changed");
static_assert(sizeof(idCrosshairCombinerInfo) == 52,
    "Recovered crosshair combiner ABI changed");
#endif
