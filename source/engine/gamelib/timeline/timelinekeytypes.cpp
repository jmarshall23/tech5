#include "gamelib/timeline/timelinekeytypes.h"

#include <cerrno>
#include <cstdlib>

namespace {

// The seven-entry maps are recovered from the tlKeyId_t/tlKeyType_t metadata,
// the typed SetValue overloads in entityvalueaccess.cpp, and the serialized
// key widths consumed by timelinekeyanimdata.cpp.
constexpr tlKeyType_t keyTypeMap[TL_KEY_MAX] = {
    TL_KEYTYPE_BOOL,
    TL_KEYTYPE_COLOR_RGB,
    TL_KEYTYPE_FLOAT4,
    TL_KEYTYPE_FLOAT,
    TL_KEYTYPE_FLOAT,
    TL_KEYTYPE_FLOAT,
    TL_KEYTYPE_FLOAT,
};

constexpr int keySizes[TL_KEYTYPE_MAX] = {
    1,
    4,
    4,
    12,
    12,
    16,
    16,
};

bool ParseNextFloat(const char *&cursor, float &value) {
    if (cursor == nullptr) {
        return false;
    }

    char *end = nullptr;
    errno = 0;
    value = std::strtof(cursor, &end);
    if (end == cursor || errno == ERANGE) {
        return false;
    }
    cursor = end;
    return true;
}

} // namespace

tlKeyType_t mgTimelineKeyUtil::GetType(const tlKeyId_t key) {
    if (key < TL_KEY_VISIBILITY || key >= TL_KEY_MAX) {
        return TL_KEYTYPE_MAX;
    }
    return keyTypeMap[static_cast<int>(key)];
}

int mgTimelineKeyUtil::KeySize(const tlKeyType_t type) {
    if (type < TL_KEYTYPE_BOOL || type >= TL_KEYTYPE_MAX) {
        return 0;
    }
    return keySizes[static_cast<int>(type)];
}

bool mgTimelineKeyUtil::FromString(const idStr& valueStr, bool *value) {
    if (value == nullptr) {
        return false;
    }
    *value = std::strtol(valueStr.c_str(), nullptr, 10) != 0;
    return true;
}

bool mgTimelineKeyUtil::FromString(const idStr& valueStr, int *value) {
    if (value == nullptr) {
        return false;
    }
    *value = static_cast<int>(std::strtol(valueStr.c_str(), nullptr, 10));
    return true;
}

bool mgTimelineKeyUtil::FromString(const idStr& valueStr, float *value) {
    if (value == nullptr) {
        return false;
    }
    const char *cursor = valueStr.c_str();
    return ParseNextFloat(cursor, *value);
}

bool mgTimelineKeyUtil::FromString(const idStr& valueStr, idVec3 *value) {
    if (value == nullptr) {
        return false;
    }
    const char *cursor = valueStr.c_str();
    return ParseNextFloat(cursor, value->x)
        && ParseNextFloat(cursor, value->y)
        && ParseNextFloat(cursor, value->z);
}

bool mgTimelineKeyUtil::FromString(const idStr& valueStr, idVec4 *value) {
    if (value == nullptr) {
        return false;
    }
    const char *cursor = valueStr.c_str();
    return ParseNextFloat(cursor, value->x)
        && ParseNextFloat(cursor, value->y)
        && ParseNextFloat(cursor, value->z)
        && ParseNextFloat(cursor, value->w);
}
