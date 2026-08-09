#pragma once

#include "idlib/math/vector.h"
#include "idlib/text/str.h"

// Reconstructed from tungsten.exe local types 1723 and 1758. The numeric
// values are part of the serialized timeline format and must not be reordered.
enum tlKeyId_t : int {
    TL_KEY_INVALID = -1,
    TL_KEY_VISIBILITY = 0,
    TL_KEY_LIGHTCOLOR = 1,
    TL_KEY_DOF = 2,
    TL_KEY_FOCAL = 3,
    TL_KEY_NEARBP = 4,
    TL_KEY_FARBP = 5,
    TL_KEY_BSCALE = 6,
    TL_KEY_MAX = 7,
};

enum tlKeyType_t : int {
    TL_KEYTYPE_BOOL = 0,
    TL_KEYTYPE_INT = 1,
    TL_KEYTYPE_FLOAT = 2,
    TL_KEYTYPE_FLOAT3 = 3,
    TL_KEYTYPE_COLOR_RGB = 4,
    TL_KEYTYPE_FLOAT4 = 5,
    TL_KEYTYPE_COLOR_RGBA = 6,
    TL_KEYTYPE_MAX = 7,
};

class mgTimelineKeyUtil {
public:
    static tlKeyType_t GetType(tlKeyId_t key);
    static int KeySize(tlKeyType_t type);

    static bool FromString(const idStr& valueStr, bool* value);
    static bool FromString(const idStr& valueStr, int* value);
    static bool FromString(const idStr& valueStr, float* value);
    static bool FromString(const idStr& valueStr, idVec3* value);
    static bool FromString(const idStr& valueStr, idVec4* value);
};

static_assert(sizeof(tlKeyId_t) == 4, "Recovered tlKeyId_t ABI changed");
static_assert(sizeof(tlKeyType_t) == 4, "Recovered tlKeyType_t ABI changed");
