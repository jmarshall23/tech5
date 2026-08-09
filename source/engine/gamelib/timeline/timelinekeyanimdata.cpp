#include "gamelib/timeline/timelinekeyanimdata.h"

#include "idlib/containers/search.h"

#include <cstddef>
#include <cstring>

namespace {

idSearch_BinaryDefault<float> timelineKeySearch;

template<typename type_t>
const type_t& KeyAt(const idList<char, 5>& data, const int index,
        const int keySize) {
    return *reinterpret_cast<const type_t*>(
        data.Ptr() + static_cast<std::ptrdiff_t>(index) * keySize
    );
}

} // namespace

mgTimelineKeyAnimData::mgTimelineKeyAnimData()
    : type(TL_KEYTYPE_MAX)
    , keySize(0)
    , times(0)
    , data(0) {
}

void mgTimelineKeyAnimData::PostLoadInit() {
    keySize = mgTimelineKeyUtil::KeySize(type);
}

bool mgTimelineKeyAnimData::FindLerpKeys(const float time, int *key0,
        int *key1, float *fraction) const {
    if (key0 == nullptr || key1 == nullptr || fraction == nullptr
            || times.Num() == 0 || times.Ptr() == nullptr) {
        return false;
    }

    const int index = timelineKeySearch.Search_LastLessEqual(
        times.Ptr(), times.Num(), time
    );
    if (times[index] > time) {
        return false;
    }

    *key0 = index;
    if (index < times.Num() - 1) {
        *key1 = index + 1;
        const float duration = times[index + 1] - times[index];
        *fraction = duration != 0.0f ? (time - times[index]) / duration : 0.0f;
    } else {
        *key1 = index;
        *fraction = 0.0f;
    }
    return true;
}

template<typename type_t>
bool mgTimelineKeyAnimData::GetLerped(const float time, type_t *value) const {
    int key0 = 0;
    int key1 = 0;
    float fraction = 0.0f;
    if (value == nullptr || keySize != static_cast<int>(sizeof(type_t))
            || !FindLerpKeys(time, &key0, &key1, &fraction)) {
        return false;
    }

    const type_t& value0 = KeyAt<type_t>(data, key0, keySize);
    const type_t& value1 = KeyAt<type_t>(data, key1, keySize);
    *value = value0 + (value1 - value0) * fraction;
    return true;
}

template<>
bool mgTimelineKeyAnimData::GetLerped<int>(const float time, int *value) const {
    int key0 = 0;
    int key1 = 0;
    float fraction = 0.0f;
    if (value == nullptr || keySize != static_cast<int>(sizeof(int))
            || !FindLerpKeys(time, &key0, &key1, &fraction)) {
        return false;
    }

    const int value0 = KeyAt<int>(data, key0, keySize);
    const int value1 = KeyAt<int>(data, key1, keySize);
    *value = static_cast<int>(static_cast<float>(value0)
        + static_cast<float>(value1 - value0) * fraction);
    return true;
}

template<>
bool mgTimelineKeyAnimData::GetLerped<idVec3>(const float time,
        idVec3 *value) const {
    int key0 = 0;
    int key1 = 0;
    float fraction = 0.0f;
    if (value == nullptr || keySize != static_cast<int>(sizeof(idVec3))
            || !FindLerpKeys(time, &key0, &key1, &fraction)) {
        return false;
    }

    const idVec3& value0 = KeyAt<idVec3>(data, key0, keySize);
    const idVec3& value1 = KeyAt<idVec3>(data, key1, keySize);
    value->x = value0.x + (value1.x - value0.x) * fraction;
    value->y = value0.y + (value1.y - value0.y) * fraction;
    value->z = value0.z + (value1.z - value0.z) * fraction;
    return true;
}

template<>
bool mgTimelineKeyAnimData::GetLerped<idVec4>(const float time,
        idVec4 *value) const {
    int key0 = 0;
    int key1 = 0;
    float fraction = 0.0f;
    if (value == nullptr || keySize != static_cast<int>(sizeof(idVec4))
            || !FindLerpKeys(time, &key0, &key1, &fraction)) {
        return false;
    }

    const idVec4& value0 = KeyAt<idVec4>(data, key0, keySize);
    const idVec4& value1 = KeyAt<idVec4>(data, key1, keySize);
    value->x = value0.x + (value1.x - value0.x) * fraction;
    value->y = value0.y + (value1.y - value0.y) * fraction;
    value->z = value0.z + (value1.z - value0.z) * fraction;
    value->w = value0.w + (value1.w - value0.w) * fraction;
    return true;
}

bool mgTimelineKeyAnimData::GetData(const float time, bool *value) const {
    int key0 = 0;
    int key1 = 0;
    float fraction = 0.0f;
    if (value == nullptr || keySize != 1
            || !FindLerpKeys(time, &key0, &key1, &fraction)) {
        return false;
    }
    *value = data[key0] != 0;
    return true;
}

bool mgTimelineKeyAnimData::GetData(const float time, int *value) const {
    return GetLerped(time, value);
}

bool mgTimelineKeyAnimData::GetData(const float time, float *value) const {
    return GetLerped(time, value);
}

bool mgTimelineKeyAnimData::GetData(const float time, idVec3 *value) const {
    return GetLerped(time, value);
}

bool mgTimelineKeyAnimData::GetData(const float time, idVec4 *value) const {
    return GetLerped(time, value);
}
