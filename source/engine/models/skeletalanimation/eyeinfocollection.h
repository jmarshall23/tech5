#pragma once

#include "idlib/containers/list.h"
#include "idlib/handle.h"
#include "idlib/index.h"
#include "idlib/math/vector.h"
#include "idlib/text/str.h"

#include <cstdint>

enum invalidEyeInfo_t : int;
enum invalidJointIndex_t : int;
using eyeInfoHandle_t = idHandle<unsigned short, invalidEyeInfo_t, 65535>;

class idEyeInfo {
public:
    struct perEyeInfo_t {
        float focusScale;
        float wanderRate;
        float maxWanderPitch;
        float maxWanderYaw;
        float jitterScale;
        float slerpScale;
        idAngles angleOffset;
    };

    idEyeInfo();

    idStr name;
    eyeInfoHandle_t handle;
    idIndex<short, invalidJointIndex_t> basisJointIndex;
    float minEyePitch;
    float maxEyePitch;
    float minEyeYaw;
    float maxEyeYaw;
    float lidMinPitch;
    float lidMaxPitch;
    float lidMinYaw;
    float lidMaxYaw;
    perEyeInfo_t perEyeInfo[2];
};

class idEyeInfoCollection {
public:
    idEyeInfoCollection();

    void Free();
    eyeInfoHandle_t AddEyeInfo(const idEyeInfo& info);
    const idEyeInfo* GetEyeInfo(eyeInfoHandle_t handle) const;
    eyeInfoHandle_t FindEyeInfoHandle(const char* name) const;

    std::uint16_t curHandle;
    idList<idEyeInfo, 5> eyeInfos;
};

static_assert(sizeof(idEyeInfo::perEyeInfo_t) == 36,
    "Recovered per-eye information ABI changed");
#if INTPTR_MAX == INT32_MAX
static_assert(sizeof(idEyeInfo) == 140,
    "Recovered eye-information ABI changed");
static_assert(sizeof(idEyeInfoCollection) == 20,
    "Recovered eye-information collection ABI changed");
#endif
