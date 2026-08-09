#include "models/skeletalanimation/eyeinfocollection.h"

#include <cstring>

idEyeInfo::idEyeInfo()
    : basisJointIndex(static_cast<short>(-1)),
      minEyePitch(-16.0f), maxEyePitch(16.0f),
      minEyeYaw(-23.0f), maxEyeYaw(23.0f),
      lidMinPitch(-15.0f), lidMaxPitch(15.0f),
      lidMinYaw(-21.0f), lidMaxYaw(21.0f) {
    for (perEyeInfo_t& eye : perEyeInfo) {
        eye.focusScale = 0.25f;
        eye.wanderRate = 0.0f;
        eye.maxWanderPitch = 15.0f;
        eye.maxWanderYaw = 15.0f;
        eye.jitterScale = 1.0f;
        eye.slerpScale = 0.5f;
        eye.angleOffset = idAngles();
    }
}

idEyeInfoCollection::idEyeInfoCollection()
    : curHandle(0), eyeInfos(16) {
}

void idEyeInfoCollection::Free() {
    eyeInfos.ClearFree();
    curHandle = 0;
}

eyeInfoHandle_t idEyeInfoCollection::AddEyeInfo(const idEyeInfo& info) {
    eyeInfoHandle_t result(curHandle++);
    const int index = eyeInfos.Append(info);
    if (index < 0) {
        result.Invalidate();
        return result;
    }
    eyeInfos[index].handle = result.Get();
    return result;
}

const idEyeInfo* idEyeInfoCollection::GetEyeInfo(
    eyeInfoHandle_t handle) const {
    for (int index = 0; index < eyeInfos.Num(); ++index) {
        if (eyeInfos[index].handle == handle) {
            return &eyeInfos[index];
        }
    }
    return nullptr;
}

eyeInfoHandle_t idEyeInfoCollection::FindEyeInfoHandle(
    const char* searchName) const {
    if (searchName != nullptr) {
        for (int index = 0; index < eyeInfos.Num(); ++index) {
            if (std::strcmp(eyeInfos[index].name.c_str(), searchName) == 0) {
                return eyeInfos[index].handle;
            }
        }
    }
    return eyeInfoHandle_t();
}
