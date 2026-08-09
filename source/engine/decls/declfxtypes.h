#pragma once

// Shared declaration/runtime enums recovered from tungsten.exe metadata.
// Keep these in a small header so GameLib can consume FX declarations
// without manufacturing a second, numerically different enum set.
enum fxCondition_t : int {
    FX_NONE = 0
};

enum fxExtraCondition_t : int {
    FX_EXTRA_COND_NONE = 0,
    FX_EXTRA_COND_WEAP_AMMOTYPE_0 = 0x0004,
    FX_EXTRA_COND_WEAP_AMMOTYPE_1 = 0x0008,
    FX_EXTRA_COND_WEAP_AMMOTYPE_2 = 0x0010,
    FX_EXTRA_COND_WEAP_AMMOTYPE_3 = 0x0020,
    FX_EXTRA_COND_WEAP_ATTACK_DEFAULT = 0x0040,
    FX_EXTRA_COND_WEAP_ATTACK_LEFT = 0x0080,
    FX_EXTRA_COND_WEAP_ATTACK_RIGHT = 0x0100,
    FX_EXTRA_COND_WEAP_ATTACK_LEFT2 = 0x0200,
    FX_EXTRA_COND_WEAP_ATTACK_RIGHT2 = 0x0400,
    FX_EXTRA_COND_SMALL = 0x0800,
    FX_EXTRA_COND_MEDIUM = 0x1000,
    FX_EXTRA_COND_LARGE = 0x2000,
    FX_EXTRA_COND_ENGINE_1 = 0x4000,
    FX_EXTRA_COND_ENGINE_2 = 0x8000,
    FX_EXTRA_COND_MAX = 0x10000
};

enum soundChannel_t : int {
    SND_CHANNEL_ANY = 0
};

enum fxActionType_t : int {
    FX_LIGHT = 0,
    FX_PARTICLE = 1,
    FX_DECAL = 2,
    FX_DECAL2 = 3,
    FX_MODEL = 4,
    FX_SOUND = 5,
    FX_SCREEN_SHAKE = 6,
    FX_CONTROLLER_SHAKE = 7,
    FX_WIND = 8,
    FX_RENDERPARM = 9,
    FX_ENV_OVERRIDE = 10,
    FX_ENV_CHANGE = 11,
    FX_FLARE = 12,
    FX_RADIAL_BLUR = 13,
    FX_RIBBON = 14,
    FX_FADE_PARENT = 15,
    FX_MAX = 16
};

enum fxMultiTagUseType_t : int {
    FX_MULTI_TAG_USE_RND = 0,
    FX_MULTI_TAG_USE_EXPLICIT = 1,
    FX_MULTI_TAG_USE_ALL = 2
};

enum fxRotationType_t : int {
    FX_ROT_START_AXIS = 0,
    FX_ROT_START_AXIS_PARENT = 1,
    FX_ROT_TRACK_AXIS = 2,
    FX_ROT_TRACK_AXIS_PARENT = 3,
    FX_ROT_TRACK_LOCAL_AXIS = 4,
    FX_ROT_EXPLICIT_ANGLES = 5,
    FX_ROT_EXPLICIT_TABLES = 6,
    FX_ROT_EXPLICIT_TABLES_LOCAL = 7,
    FX_ROT_EXTERNALROT = 8
};

enum fxOriginType_t : int {
    FX_ORG_START_POS = 0,
    FX_ORG_TRACK_POS = 1,
    FX_ORG_TRACK_LOCAL_POS = 2,
    FX_ORG_EXTERNALPOS = 3
};
