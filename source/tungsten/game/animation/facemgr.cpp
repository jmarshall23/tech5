#include "facemgr.h"

#include <algorithm>
#include <cmath>
#include <utility>

namespace {

void SetFlag(std::uint16_t& flags, const std::uint16_t flag,
        const bool enable) {
    if (enable) {
        flags = static_cast<std::uint16_t>(flags | flag);
    } else {
        flags = static_cast<std::uint16_t>(flags & ~flag);
    }
}

void Dispatch(idFaceMgr* const manager, idFaceAnimator& animator,
        const idFaceAnimatorOperation operation, idEntity* const owner,
        idTreeAnimator* const treeAnimator,
        const idAnimAliasHandle alias = idAnimAliasHandle(),
        const faceChannel_t channel = FACECHANNEL_MAX,
        const float rate = 1.0f, const int startFrame = 0,
        const int blendIn = 0, const int blendOut = 0,
        const bool cycle = false) {
    if (manager != nullptr && manager->GetServices() != nullptr) {
        manager->GetServices()->AnimatorOperation(operation, animator,
            *manager, owner, treeAnimator, alias, channel, rate,
            startFrame, blendIn, blendOut, cycle);
    }
}

float Clamp(const float value, const float minimum, const float maximum) {
    return (std::max)(minimum, (std::min)(value, maximum));
}

} // namespace

// Retail symbol: ?SetEnableEyeTracking@idFaceMgr@@QAAXPAVidEntity@@_N@Z
// EA: 0x82B2D238, RVA: 0x00B2D238
void idFaceMgr::SetEnableEyeTracking(idEntity*, const bool enable) {
    if (enable) {
        initEyeTracking = true;
    }
    SetFlag(flags, FACEFLAG_EYE_TRACK, enable);
}

// Retail symbol: ?SuppressBlinking@idFaceMgr@@QAAX_N@Z
// EA: 0x82B2D270, RVA: 0x00B2D270
void idFaceMgr::SuppressBlinking(const bool suppress) {
    SetFlag(flags, FACEFLAG_SUPPRESS_BLINK, suppress);
}

// Retail symbol: ?SuppressLidDeformation@idFaceMgr@@QAAX_N@Z
// EA: 0x82B2D2A0, RVA: 0x00B2D2A0
void idFaceMgr::SuppressLidDeformation(const bool suppress) {
    SetFlag(flags, FACEFLAG_SUPPRESS_LID_DEFORM, suppress);
}

// Retail symbol: ?GetFacialAnimSetDecl@idFaceMgr@@QBAPBVidDeclFacialAnimationSet@@PAVidEntity@@@Z
// EA: 0x82B2D2D0, RVA: 0x00B2D2D0
const idDeclFacialAnimationSet* idFaceMgr::GetFacialAnimSetDecl(
        idEntity* const owner) const {
    return services != nullptr ? services->GetFacialAnimationSet(owner)
                               : nullptr;
}

// Retail symbol: ?Shutdown@idFaceAnimator@@QAAXPAVidFaceMgr@@PAVidEntity@@PAVidTreeAnimator@@@Z
// EA: 0x82B2D320, RVA: 0x00B2D320
void idFaceAnimator::Shutdown(idFaceMgr* const manager,
        idEntity* const owner, idTreeAnimator* const treeAnimator) {
    Dispatch(manager, *this, FACEANIM_SHUTDOWN, owner, treeAnimator);
    initialized = false;
    currentlyGlancing = false;
    currentlyFidgeting = false;
}

// Retail symbol: ?SortAliasesAndWeights@@YAXPAV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@PAMH@Z
// EA: 0x82B2D428, RVA: 0x00B2D428
void SortAliasesAndWeights(idAnimAliasHandle* const aliases,
        float* const weights, const int count) {
    if (aliases == nullptr || weights == nullptr) {
        return;
    }
    for (int index = 1; index < count; ++index) {
        const idAnimAliasHandle alias = aliases[index];
        const float weight = weights[index];
        int destination = index;
        while (destination > 0 && weight > weights[destination - 1]) {
            weights[destination] = weights[destination - 1];
            aliases[destination] = aliases[destination - 1];
            --destination;
        }
        weights[destination] = weight;
        aliases[destination] = alias;
    }
}

// Retail symbol: ?SetEnableAnimation@idFaceAnimator@@QAAXPAVidFaceMgr@@PAVidEntity@@_N@Z
// EA: 0x82B2D4C8, RVA: 0x00B2D4C8
void idFaceAnimator::SetEnableAnimation(idFaceMgr* const manager,
        idEntity* const owner, const bool enable) {
    animationEnabled = enable;
    Dispatch(manager, *this, FACEANIM_ENABLE_ALL, owner, nullptr,
        idAnimAliasHandle(), FACECHANNEL_MAX, enable ? 1.0f : 0.0f);
}

// Retail symbol: ?SetEnableGestures@idFaceAnimator@@QAAXPAVidFaceMgr@@PAVidEntity@@_N@Z
// EA: 0x82B2D6F0, RVA: 0x00B2D6F0
void idFaceAnimator::SetEnableGestures(idFaceMgr* const manager,
        idEntity* const owner, const bool enable) {
    gesturesEnabled = enable;
    Dispatch(manager, *this, FACEANIM_ENABLE_GESTURES, owner, nullptr,
        idAnimAliasHandle(), FACECHANNEL_MAX, enable ? 1.0f : 0.0f);
}

// Retail symbol: ?SetEnableGlancing@idFaceAnimator@@QAAXPAVidFaceMgr@@PAVidEntity@@_N@Z
// EA: 0x82B2D838, RVA: 0x00B2D838
void idFaceAnimator::SetEnableGlancing(idFaceMgr* const manager,
        idEntity* const owner, const bool enable) {
    glancingEnabled = enable;
    if (!enable) {
        currentlyGlancing = false;
    }
    Dispatch(manager, *this, FACEANIM_ENABLE_GLANCE, owner, nullptr,
        idAnimAliasHandle(), FACECHANNEL_MAX, enable ? 1.0f : 0.0f);
}

// Retail symbol: ?SetEnableIdleCycles@idFaceAnimator@@QAAXPAVidFaceMgr@@PAVidEntity@@_N@Z
// EA: 0x82B2D8B0, RVA: 0x00B2D8B0
void idFaceAnimator::SetEnableIdleCycles(idFaceMgr* const manager,
        idEntity* const owner, const bool enable) {
    idleCyclesEnabled = enable;
    Dispatch(manager, *this, FACEANIM_ENABLE_IDLE_CYCLE, owner, nullptr,
        idAnimAliasHandle(), FACECHANNEL_MAX, enable ? 1.0f : 0.0f);
}

// Retail symbol: ?SetEnableIdleFidgets@idFaceAnimator@@QAAXPAVidFaceMgr@@PAVidEntity@@_N@Z
// EA: 0x82B2D928, RVA: 0x00B2D928
void idFaceAnimator::SetEnableIdleFidgets(idFaceMgr* const manager,
        idEntity* const owner, const bool enable) {
    idleFidgetsEnabled = enable;
    if (!enable) {
        currentlyFidgeting = false;
    }
    Dispatch(manager, *this, FACEANIM_ENABLE_IDLE_FIDGET, owner, nullptr,
        idAnimAliasHandle(), FACECHANNEL_MAX, enable ? 1.0f : 0.0f);
}

// Retail symbol: ?Shutdown@idFaceMgr@@QAAXPAVidEntity@@PAVidTreeAnimator@@@Z
// EA: 0x82B2D9A0, RVA: 0x00B2D9A0
void idFaceMgr::Shutdown(idEntity* const owner,
        idTreeAnimator* const treeAnimator) {
    faceAnimator.Shutdown(this, owner, treeAnimator);
}

// Retail symbol: ?DormantEnd@idFaceMgr@@QAAXPAVidEntity@@H@Z
// EA: 0x82B2D9B8, RVA: 0x00B2D9B8
void idFaceMgr::DormantEnd(idEntity* const owner, const int) {
    int blinkMinimum = 500;
    int blinkMaximum = 7500;
    int jitterMinimum = 100;
    int jitterMaximum = 1500;
    const int now = services != nullptr ? services->GetGameTime() : 0;
    if (services != nullptr) {
        services->GetDormantIntervals(owner, blinkMinimum, blinkMaximum,
            jitterMinimum, jitterMaximum);
        nextBlinkTime = now
            + services->RandomInterval(blinkMinimum, blinkMaximum);
        nextJitterTime = now
            + services->RandomInterval(jitterMinimum, jitterMaximum);
    } else {
        nextBlinkTime = now + blinkMinimum;
        nextJitterTime = now + jitterMinimum;
    }
}

// Retail symbol: ?SetEnableAnimation@idFaceMgr@@QAAXPAVidEntity@@_N@Z
// EA: 0x82B2DAC8, RVA: 0x00B2DAC8
void idFaceMgr::SetEnableAnimation(idEntity* const owner, const bool enable) {
    faceAnimator.SetEnableAnimation(this, owner, enable);
    SetFlag(flags, FACEFLAG_ENABLE, enable);
}

// Retail symbol: ?SetEnableMoodAnimation@idFaceMgr@@QAAXPAVidEntity@@_N@Z
// EA: 0x82B2DB38, RVA: 0x00B2DB38
void idFaceMgr::SetEnableMoodAnimation(idEntity* const owner,
        const bool enable) {
    SetFlag(flags, FACEFLAG_ANIMATE_MOODS, enable);
    Dispatch(this, faceAnimator, FACEANIM_ANIMATE_MOOD, owner, nullptr,
        idAnimAliasHandle(), FACECHANNEL_MAX, enable ? 1.0f : 0.0f);
}

// Retail symbol: ?SetEnableLipSyncAnimation@idFaceMgr@@QAAXPAVidEntity@@_N@Z
// EA: 0x82B2DBD0, RVA: 0x00B2DBD0
void idFaceMgr::SetEnableLipSyncAnimation(idEntity* const owner,
        const bool enable) {
    SetFlag(flags, FACEFLAG_ANIMATE_LIPSYNC, enable);
    Dispatch(this, faceAnimator, FACEANIM_START_LIPSYNC, owner, nullptr,
        idAnimAliasHandle(), FACECHANNEL_MAX, enable ? 1.0f : 0.0f);
}

// Retail symbol: ?SetEnableGestureAnimation@idFaceMgr@@QAAXPAVidEntity@@_N@Z
// EA: 0x82B2DC70, RVA: 0x00B2DC70
void idFaceMgr::SetEnableGestureAnimation(idEntity* const owner,
        const bool enable) {
    SetFlag(flags, FACEFLAG_ANIMATE_GESTURES, enable);
    faceAnimator.SetEnableGestures(this, owner, enable);
}

// Retail symbol: ?SetEnableBlinking@idFaceMgr@@QAAXPAVidEntity@@_N@Z
// EA: 0x82B2DCB0, RVA: 0x00B2DCB0
void idFaceMgr::SetEnableBlinking(idEntity* const owner, const bool enable) {
    SetFlag(flags, FACEFLAG_ANIMATE_BLINK, enable);
    Dispatch(this, faceAnimator, FACEANIM_BLINK, owner, nullptr,
        idAnimAliasHandle(), FACECHANNEL_MAX, enable ? 1.0f : 0.0f);
}

// Retail symbol: ?SetEnableLidDeformation@idFaceMgr@@QAAXPAVidEntity@@_N@Z
// EA: 0x82B2DD50, RVA: 0x00B2DD50
void idFaceMgr::SetEnableLidDeformation(idEntity* const owner,
        const bool enable) {
    SetFlag(flags, FACEFLAG_LID_DEFORMATION, enable);
    Dispatch(this, faceAnimator, FACEANIM_ANIMATE_EYES, owner, nullptr,
        idAnimAliasHandle(), FACECHANNEL_MAX, enable ? 1.0f : 0.0f);
}

// Retail symbol: ?CalcEyeFocusPoint@idFaceMgr@@AAA?AVidVec3@@ABV2@0PBVidEyeInfo@@W4eye_t@3@@Z
// EA: 0x82B2DDF0, RVA: 0x00B2DDF0
idVec3 idFaceMgr::CalcEyeFocusPoint(const idVec3& focusPoint,
        const idVec3& eyeDelta, const idEyeInfo* const eyeInfo,
        const int eye) {
    if (eyeInfo == nullptr || eye < 0 || eye >= 2) {
        return focusPoint;
    }
    const idEyeInfo::perEyeInfo_t& info = eyeInfo->perEyeInfo[eye];
    const float side = eye == 0 ? 1.0f : -1.0f;
    idVec3 result(
        focusPoint.x + eyeDelta.x * info.focusScale * side
            + eyeJitterOffset.x * info.jitterScale,
        focusPoint.y + eyeDelta.y * info.focusScale * side
            + eyeJitterOffset.y * info.jitterScale,
        focusPoint.z + eyeDelta.z * info.focusScale * side
            + eyeJitterOffset.z * info.jitterScale);
    if (info.wanderRate != 0.0f) {
        const float radians = eyeWander[eye] * 0.01745329252f;
        result.y += std::cos(radians) * info.maxWanderYaw;
        result.z += std::sin(radians) * info.maxWanderPitch;
    }
    result.x += info.angleOffset.pitch;
    result.y += info.angleOffset.yaw;
    result.z += info.angleOffset.roll;
    return result;
}

// Retail symbol: ?AlignEye@idFaceMgr@@AAAXPAVidEntity@@PAVidTreeAnimator@@V?$idIndex@FW4invalidJointIndex_t@@@@ABVidVec3@@ABVidMat3@@3PBVidEyeInfo@@W4eye_t@7@AAVidAngles@@@Z
// EA: 0x82B2DFC0, RVA: 0x00B2DFC0
void idFaceMgr::AlignEye(idEntity* const owner,
        idTreeAnimator* const treeAnimator, const idJointIndex eyeJoint,
        const idVec3& eyeJointPosition, const idMat3&,
        const idVec3& focusPoint, const idEyeInfo* const eyeInfo,
        const int eye, idAngles& offsetAngle) {
    if (eyeInfo == nullptr || eye < 0 || eye >= 2) {
        return;
    }
    const float dx = focusPoint.x - eyeJointPosition.x;
    const float dy = focusPoint.y - eyeJointPosition.y;
    const float dz = focusPoint.z - eyeJointPosition.z;
    const float horizontal = std::sqrt(dx * dx + dy * dy);
    offsetAngle.yaw = Clamp(std::atan2(dy, dx) * 57.2957795f,
        eyeInfo->minEyeYaw, eyeInfo->maxEyeYaw);
    offsetAngle.pitch = Clamp(-std::atan2(dz, horizontal) * 57.2957795f,
        eyeInfo->minEyePitch, eyeInfo->maxEyePitch);
    offsetAngle.roll = 0.0f;
    if (services != nullptr) {
        services->ApplyEyeAngles(owner, treeAnimator, eyeJoint, offsetAngle);
    }
}

// Retail symbol: ?AnimateBlinks@idFaceMgr@@QBA_NXZ
// EA: 0x82B2E5A0, RVA: 0x00B2E5A0
bool idFaceMgr::AnimateBlinks() const {
    return (flags & FACEFLAG_ANIMATE_BLINK) != 0
        && (flags & FACEFLAG_SUPPRESS_BLINK) == 0
        && (services == nullptr || (!services->ShouldSkipBlink()
            && !services->ShouldSkipProceduralAnimation()));
}

// Retail symbol: ?StartLipSync@idFaceAnimator@@QAAXPAVidFaceMgr@@PAVidEntity@@PAVidTreeAnimator@@@Z
// EA: 0x82B2E5F8, RVA: 0x00B2E5F8
void idFaceAnimator::StartLipSync(idFaceMgr* const manager,
        idEntity* const owner, idTreeAnimator* const treeAnimator) {
    Dispatch(manager, *this, FACEANIM_START_LIPSYNC, owner, treeAnimator);
}

// Retail symbol: ?AnimateMood@idFaceAnimator@@QAAXPAVidFaceMgr@@PAVidEntity@@PAVidTreeAnimator@@@Z
// EA: 0x82B2E6B8, RVA: 0x00B2E6B8
void idFaceAnimator::AnimateMood(idFaceMgr* const manager,
        idEntity* const owner, idTreeAnimator* const treeAnimator) {
    Dispatch(manager, *this, FACEANIM_ANIMATE_MOOD, owner, treeAnimator);
}

// Retail symbol: ?Reset@idFaceAnimator@@QAAXPAVidFaceMgr@@PAVidEntity@@PAVidTreeAnimator@@@Z
// EA: 0x82B2E7E0, RVA: 0x00B2E7E0
void idFaceAnimator::Reset(idFaceMgr* const manager, idEntity* const owner,
        idTreeAnimator* const treeAnimator) {
    currentlyGlancing = false;
    currentlyFidgeting = false;
    Dispatch(manager, *this, FACEANIM_RESET, owner, treeAnimator);
}

// Retail symbol: ?LipSyncFinished@idFaceAnimator@@QAAXPAVidFaceMgr@@PAVidEntity@@PAVidTreeAnimator@@@Z
// EA: 0x82B2E988, RVA: 0x00B2E988
void idFaceAnimator::LipSyncFinished(idFaceMgr* const manager,
        idEntity* const owner, idTreeAnimator* const treeAnimator) {
    Dispatch(manager, *this, FACEANIM_LIPSYNC_FINISHED, owner, treeAnimator);
}

// Retail symbol: ?PlayAnimation@idFaceAnimator@@QAAXPAVidFaceMgr@@PAVidEntity@@PAVidTreeAnimator@@V?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@W4faceChannel_t@@MHHH_N@Z
// EA: 0x82B2EAC0, RVA: 0x00B2EAC0
void idFaceAnimator::PlayAnimation(idFaceMgr* const manager,
        idEntity* const owner, idTreeAnimator* const treeAnimator,
        const idAnimAliasHandle aliasHandle, const faceChannel_t channel,
        const float rateScale, const int startFrame,
        const int blendInDurationMS, const int blendOutDurationMS,
        const bool cycleAnimation) {
    Dispatch(manager, *this, FACEANIM_PLAY_ANIMATION, owner, treeAnimator,
        aliasHandle, channel, rateScale, startFrame, blendInDurationMS,
        blendOutDurationMS, cycleAnimation);
}

// Retail symbol: ?PlayWebAnimation@idFaceAnimator@@QAAXPAVidFaceMgr@@PAVidEntity@@PAVidTreeAnimator@@PAVidAnimator_AnimWeb@@ABVidAnimWebPath@@@Z
// EA: 0x82B2EC40, RVA: 0x00B2EC40
void idFaceAnimator::PlayWebAnimation(idFaceMgr* const manager,
        idEntity* const owner, idTreeAnimator* const treeAnimator,
        idAnimator_AnimWeb*, const idAnimWebPath&) {
    Dispatch(manager, *this, FACEANIM_PLAY_WEB_ANIMATION, owner,
        treeAnimator);
}

// Retail symbol: ?AnimateEyes@idFaceAnimator@@QAAXPAVidFaceMgr@@PAVidEntity@@PAVidTreeAnimator@@PBVidEyeInfo@@PBV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@PBMH@Z
// EA: 0x82B2ED88, RVA: 0x00B2ED88
void idFaceAnimator::AnimateEyes(idFaceMgr* const manager,
        idEntity* const owner, idTreeAnimator* const treeAnimator,
        const idEyeInfo*, const idAnimAliasHandle* const aliases,
        const float* const weights, const int count) {
    idAnimAliasHandle alias;
    float weight = 0.0f;
    if (aliases != nullptr && weights != nullptr && count > 0) {
        alias = aliases[0];
        weight = weights[0];
    }
    Dispatch(manager, *this, FACEANIM_ANIMATE_EYES, owner, treeAnimator,
        alias, FACECHANNEL_EYES, weight, count);
}

// Retail symbol: ?Blink@idFaceAnimator@@QAAXPAVidFaceMgr@@PAVidEntity@@PAVidTreeAnimator@@@Z
// EA: 0x82B2EF80, RVA: 0x00B2EF80
void idFaceAnimator::Blink(idFaceMgr* const manager, idEntity* const owner,
        idTreeAnimator* const treeAnimator) {
    Dispatch(manager, *this, FACEANIM_BLINK, owner, treeAnimator);
}

// Retail symbol: ?Glance@idFaceAnimator@@QAAXABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@PAVidFaceMgr@@PAVidEntity@@PAVidTreeAnimator@@@Z
// EA: 0x82B2F030, RVA: 0x00B2F030
void idFaceAnimator::Glance(const idAnimAliasHandle& aliasHandle,
        idFaceMgr* const manager, idEntity* const owner,
        idTreeAnimator* const treeAnimator) {
    currentlyGlancing = true;
    Dispatch(manager, *this, FACEANIM_GLANCE, owner, treeAnimator,
        aliasHandle);
}

// Retail symbol: ?Fidget@idFaceAnimator@@QAAXABV?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@PAVidFaceMgr@@PAVidEntity@@PAVidTreeAnimator@@@Z
// EA: 0x82B2F0C8, RVA: 0x00B2F0C8
void idFaceAnimator::Fidget(const idAnimAliasHandle& aliasHandle,
        idFaceMgr* const manager, idEntity* const owner,
        idTreeAnimator* const treeAnimator) {
    currentlyFidgeting = true;
    Dispatch(manager, *this, FACEANIM_FIDGET, owner, treeAnimator,
        aliasHandle);
}

// Retail symbol: ?IsCurrentlyGlancing@idFaceAnimator@@QBA_NPAVidEntity@@@Z
// EA: 0x82B2F160, RVA: 0x00B2F160
bool idFaceAnimator::IsCurrentlyGlancing(idEntity* const owner) const {
    (void)owner;
    return currentlyGlancing;
}

// Retail symbol: ?IsCurrentlyFidgeting@idFaceAnimator@@QBA_NPAVidEntity@@@Z
// EA: 0x82B2F1E0, RVA: 0x00B2F1E0
bool idFaceAnimator::IsCurrentlyFidgeting(idEntity* const owner) const {
    (void)owner;
    return currentlyFidgeting;
}

// Retail symbol: ?GetVoiceTrackTime@idFaceMgr@@ABA?AV?$idTypesafeNumber@HW4millisecondUnique_t@@@@PAVidEntity@@PBVidVoiceTrack@@@Z
// EA: 0x82B2F260, RVA: 0x00B2F260
millisecond_t idFaceMgr::GetVoiceTrackTime(idEntity*,
        const idVoiceTrack*) const {
    if (services == nullptr) {
        return millisecond_t(0);
    }
    if (realStartTime.value >= 0) {
        return millisecond_t(services->GetRealTime() - realStartTime.value);
    }
    if (vtrackStartTime.value >= 0) {
        return millisecond_t(services->GameToRealTime(
            services->GetGameTime() - vtrackStartTime.value));
    }
    return millisecond_t(0);
}

// Retail symbol: ?LipSyncFinished@idFaceMgr@@AAAXPAVidEntity@@PAVidTreeAnimator@@@Z
// EA: 0x82B2F370, RVA: 0x00B2F370
void idFaceMgr::LipSyncFinished(idEntity* const owner,
        idTreeAnimator* const treeAnimator) {
    faceAnimator.LipSyncFinished(this, owner, treeAnimator);
    lastSoundShader = nullptr;
    voiceOver = nullptr;
    voiceTrackIndex = -1;
    vtrackStartTime = -1;
    lastSampleTime = -1;
    startedVO = false;
    endLipsyncTime = services != nullptr ? services->GetGameTime() : 0;
    flags = static_cast<std::uint16_t>(flags
        & ~(FACEFLAG_SUPPRESS_BLINK | FACEFLAG_SUPPRESS_GLANCE));
    mood = defaultMood;
    faceAnimator.SetEnableGlancing(this, owner, true);
    SetFlag(flags, FACEFLAG_SUPPRESS_CYCLE, false);
    faceAnimator.SetEnableIdleCycles(this, owner, true);
    SetFlag(flags, FACEFLAG_SUPPRESS_FIDGET, false);
    faceAnimator.SetEnableIdleFidgets(this, owner, true);
}

// Retail symbol: ?ReallyStartVoiceOver@idFaceMgr@@AAAXPAVidEntity@@PAVidTreeAnimator@@@Z
// EA: 0x82B2F4B0, RVA: 0x00B2F4B0
void idFaceMgr::ReallyStartVoiceOver(idEntity* const owner,
        idTreeAnimator* const treeAnimator) {
    if (services == nullptr || voiceOver == nullptr || voiceTrackIndex < 0) {
        return;
    }
    idFaceVoiceTrackInfo info;
    if (!services->GetVoiceTrackInfo(voiceOver, voiceTrackIndex, info)) {
        return;
    }
    vtrackStartTime = services->GetGameTime();
    startedVO = true;
    startSoundTime = info.soundOffsetMilliseconds;
    if (info.soundOffsetMilliseconds == 0) {
        services->StartSound(owner, voiceChannel, lastSoundShader);
        startSoundTime = -1;
    }
    lastSampleTime = 0;
    if (info.defaultMood != MOOD_NONE) {
        mood = info.defaultMood;
        defaultMood = info.defaultMood;
    }
    SuppressBlinking(info.suppressBlinking);
    SetFlag(flags, FACEFLAG_SUPPRESS_GLANCE, true);
    faceAnimator.SetEnableGlancing(this, owner, false);
    SetFlag(flags, FACEFLAG_SUPPRESS_CYCLE, true);
    faceAnimator.SetEnableIdleCycles(this, owner, false);
    SetFlag(flags, FACEFLAG_SUPPRESS_FIDGET, true);
    faceAnimator.SetEnableIdleFidgets(this, owner, false);
    if (info.animationAlias.IsValid()) {
        faceAnimator.PlayAnimation(this, owner, treeAnimator,
            info.animationAlias, info.faceChannel, 1.0f, 0,
            info.blendInMilliseconds, info.blendOutMilliseconds,
            info.cycleAnimation);
        clearChannel = info.clearAnimationAfter
            ? info.faceChannel : FACECHANNEL_MAX;
    }
    if ((flags & FACEFLAG_ANIMATE_LIPSYNC) != 0) {
        faceAnimator.StartLipSync(this, owner, treeAnimator);
    }
    services->NotifyVoiceOverStarted(owner, voiceOver, voiceTrackIndex);
    realStartTime = services->GetRealTime();
    realEndTime = realStartTime.value + vtrackDuration.value;
}

// Retail symbol: ?Reset@idFaceMgr@@QAAXPAVidEntity@@PAVidTreeAnimator@@@Z
// EA: 0x82B2F830, RVA: 0x00B2F830
void idFaceMgr::Reset(idEntity* const owner,
        idTreeAnimator* const treeAnimator) {
    faceAnimator.Reset(this, owner, treeAnimator);
    lastSoundShader = nullptr;
    voiceOver = nullptr;
    voiceTrackIndex = -1;
}

// Retail symbol: ?RecentlyPlayedVoiceOver@idFaceMgr@@QBA_NV?$idTypesafeNumber@HW4gameTimeUnique_t@@@@@Z
// EA: 0x82B2F880, RVA: 0x00B2F880
bool idFaceMgr::RecentlyPlayedVoiceOver(const gameTime_t threshold) const {
    if (endLipsyncTime.value <= 0 || services == nullptr
            || threshold.value < 0) {
        return false;
    }
    const int elapsed = services->GetGameTime() - endLipsyncTime.value;
    return elapsed >= 0 && elapsed <= threshold.value;
}

// Retail symbol: ?StartVOIfStreamedSampleIsReady@idFaceMgr@@AAA_NPAVidEntity@@PAVidTreeAnimator@@PBVidVoiceTrack@@@Z
// EA: 0x82B2F900, RVA: 0x00B2F900
bool idFaceMgr::StartVOIfStreamedSampleIsReady(idEntity* const owner,
        idTreeAnimator* const treeAnimator, const idVoiceTrack*) {
    if (services == nullptr || voiceOver == nullptr || voiceTrackIndex < 0) {
        return false;
    }
    idFaceVoiceTrackInfo info;
    if (!services->GetVoiceTrackInfo(voiceOver, voiceTrackIndex, info)
            || !info.sampleValid || info.soundShader == nullptr) {
        return false;
    }
    lastSoundShader = info.soundShader;
    if (info.streamReady) {
        ReallyStartVoiceOver(owner, treeAnimator);
    }
    return true;
}

// Retail symbol: ?SelectNewGlanceIndex@idFaceMgr@@ABAHPAVidEntity@@PAVidTreeAnimator@@@Z
// EA: 0x82B2F9B8, RVA: 0x00B2F9B8
int idFaceMgr::SelectNewGlanceIndex(idEntity* const owner,
        idTreeAnimator* const treeAnimator) const {
    float minimumDot = -1.0f;
    if (focusAttentionLevel == ATTENTION_MODERATE) {
        minimumDot = 0.70710677f;
    } else if (focusAttentionLevel == ATTENTION_HIGH) {
        minimumDot = 0.9238795f;
    }
    return services != nullptr
        ? services->SelectFacialAnimation(*this, owner, treeAnimator,
            true, minimumDot)
        : -1;
}

// Retail symbol: ?SelectNewFidgetIndex@idFaceMgr@@ABAHPAVidEntity@@PAVidTreeAnimator@@@Z
// EA: 0x82B2FBD8, RVA: 0x00B2FBD8
int idFaceMgr::SelectNewFidgetIndex(idEntity* const owner,
        idTreeAnimator* const treeAnimator) const {
    return services != nullptr
        ? services->SelectFacialAnimation(*this, owner, treeAnimator,
            false, -1.0f)
        : -1;
}

// Retail symbol: ??1idFaceAnimator@@UAA@XZ
// EA: 0x82B2FDB8, RVA: 0x00B2FDB8
idFaceAnimator::~idFaceAnimator() = default;

// Retail symbol: ??1idFaceMgr@@UAA@XZ
// EA: 0x82B30118, RVA: 0x00B30118
idFaceMgr::~idFaceMgr() = default;

// Retail symbol: ??0idFaceAnimator@@QAA@XZ
// EA: 0x82B301D8, RVA: 0x00B301D8
idFaceAnimator::idFaceAnimator()
    : initialized(false), animationEnabled(false), gesturesEnabled(false),
      glancingEnabled(false), idleCyclesEnabled(false),
      idleFidgetsEnabled(false), currentlyGlancing(false),
      currentlyFidgeting(false) {
}

// Retail symbol: ??0idFaceMgr@@QAA@XZ
// EA: 0x82B30590, RVA: 0x00B30590
idFaceMgr::idFaceMgr()
    : mood(MOOD_NONE), lastMood(MOOD_NONE), defaultMood(MOOD_CLEAR),
      voiceChannel(static_cast<soundChannel_t>(-1)),
      clearChannel(FACECHANNEL_MAX), flags(0), lastFlags(0),
      voiceOver(nullptr), voiceTrackIndex(-1), lastSoundShader(nullptr),
      curVisemeSet(nullptr), vtrackDuration(-1), realStartTime(-1),
      realEndTime(-1), vtrackStartTime(-1), startSoundTime(-1),
      lastSampleTime(-1), endLipsyncTime(-1), nextBlinkTime(-1),
      nextJitterTime(-1), eyeJitterOffset(0.0f, 0.0f, 0.0f),
      initEyeTracking(false), useFaceSetupEyeTracking(false),
      useFaceSetupBlinking(false), startedVO(false),
      focusAttentionLevel(ATTENTION_MODERATE), lastGlanceTime(-1),
      currentGlanceInterval(-1), glancingPreviousFrame(false),
      lastFidgetTime(-1), currentFidgetInterval(-1),
      fidgetingPreviousFrame(false), nextCycleSelectTime(-1),
      currentFluffInterval(-1), services(nullptr) {
    for (int index = 0; index < EYEFACECHANNEL_NUM; ++index) {
        eyeFaceChannels[index] = -1;
    }
    for (int eye = 0; eye < 2; ++eye) {
        eyeAngles[eye].pitch = 0.0f;
        eyeAngles[eye].yaw = 0.0f;
        eyeAngles[eye].roll = 0.0f;
        eyeWander[eye] = 0.0f;
    }
}

// Retail symbol: ?LoadVisemeSetAnims@idFaceMgr@@AAAXPAVidTreeAnimator@@PBVidDeclVisemeSet@@_N@Z
// EA: 0x82B30860, RVA: 0x00B30860
void idFaceMgr::LoadVisemeSetAnims(idTreeAnimator* const treeAnimator,
        const idDeclVisemeSet* const visemeSet, const bool load) {
    visemeTable.clear();
    if (services != nullptr && visemeSet != nullptr) {
        services->LoadVisemeAliases(treeAnimator, visemeSet, load,
            visemeTable);
    }
}

// Retail symbol: ?UpdateLipSync@idFaceMgr@@AAAXPAVidEntity@@PAVidTreeAnimator@@@Z
// EA: 0x82B30958, RVA: 0x00B30958
void idFaceMgr::UpdateLipSync(idEntity* const owner,
        idTreeAnimator* const treeAnimator) {
    if (voiceOver == nullptr || voiceTrackIndex < 0 || services == nullptr) {
        return;
    }
    if (!startedVO
            && !StartVOIfStreamedSampleIsReady(owner, treeAnimator, nullptr)) {
        return;
    }
    const int trackTime = GetVoiceTrackTime(owner, nullptr).value;
    if (lastSampleTime.value >= trackTime) {
        lastSampleTime = trackTime - 1;
    }
    if (vtrackDuration.value >= 0 && trackTime >= vtrackDuration.value) {
        LipSyncFinished(owner, treeAnimator);
        return;
    }
    if (startSoundTime.value >= 0 && trackTime >= startSoundTime.value) {
        services->StartSound(owner, voiceChannel, lastSoundShader);
        startSoundTime = -1;
    }
    if ((flags & FACEFLAG_ENABLE) != 0) {
        services->UpdateLipSync(*this, owner, treeAnimator, trackTime);
    }
    lastSampleTime = trackTime;
}

// Retail symbol: ?StartVoiceTrack@idFaceMgr@@QAA_NPAVidEntity@@PAVidTreeAnimator@@PBVidDeclVoiceOver@@H@Z
// EA: 0x82B31790, RVA: 0x00B31790
bool idFaceMgr::StartVoiceTrack(idEntity* const owner,
        idTreeAnimator* const treeAnimator,
        const idDeclVoiceOver* const voiceOverDeclaration,
        const int trackIndex) {
    if (services == nullptr || voiceOverDeclaration == nullptr
            || trackIndex < 0
            || trackIndex >= services->GetVoiceTrackCount(
                voiceOverDeclaration)) {
        return false;
    }
    idFaceVoiceTrackInfo info;
    if (!services->GetVoiceTrackInfo(
            voiceOverDeclaration, trackIndex, info)) {
        return false;
    }
    voiceOver = voiceOverDeclaration;
    voiceTrackIndex = trackIndex;
    vtrackDuration = info.durationMilliseconds;
    realStartTime = -1;
    realEndTime = -1;
    vtrackStartTime = -1;
    startSoundTime = -1;
    lastSampleTime = -1;
    startedVO = false;
    if (curVisemeSet != info.visemeSet) {
        LoadVisemeSetAnims(treeAnimator, info.visemeSet, false);
        curVisemeSet = info.visemeSet;
    }
    return StartVOIfStreamedSampleIsReady(owner, treeAnimator, nullptr);
}

// Retail symbol: ?Init@idFaceAnimator@@QAA_NPAVidFaceMgr@@PAVidEntity@@PAVidTreeAnimator@@@Z
// EA: 0x82B319A0, RVA: 0x00B319A0
bool idFaceAnimator::Init(idFaceMgr* const manager, idEntity* const owner,
        idTreeAnimator* const treeAnimator) {
    if (manager == nullptr || owner == nullptr || treeAnimator == nullptr) {
        initialized = false;
        return false;
    }
    initialized = true;
    Dispatch(manager, *this, FACEANIM_INIT, owner, treeAnimator);
    return true;
}

// Retail symbol: ?Update@idFaceAnimator@@QAAXPAVidFaceMgr@@PAVidEntity@@PAVidTreeAnimator@@@Z
// EA: 0x82B32058, RVA: 0x00B32058
void idFaceAnimator::Update(idFaceMgr* const manager,
        idEntity* const owner, idTreeAnimator* const treeAnimator) {
    if (initialized) {
        Dispatch(manager, *this, FACEANIM_UPDATE, owner, treeAnimator);
    }
}

// Retail symbol: ?Init@idFaceMgr@@QAA_NPAVidEntity@@PAVidTreeAnimator@@W4mood_t@@W4soundChannel_t@@_N444444@Z
// EA: 0x82B32380, RVA: 0x00B32380
bool idFaceMgr::Init(idEntity* const owner,
        idTreeAnimator* const treeAnimator, const mood_t initialMood,
        const soundChannel_t channel, const bool enableMoodAnimation,
        const bool enableLipSyncAnimation, const bool enableGestureAnimation,
        const bool enableEyeTracking, const bool useFaceSetupEyeTracking_,
        const bool enableBlinking, const bool enableLidDeformation) {
    if (!faceAnimator.Init(this, owner, treeAnimator)) {
        return false;
    }
    mood = initialMood;
    lastMood = MOOD_NONE;
    defaultMood = initialMood;
    voiceChannel = channel;
    useFaceSetupEyeTracking = useFaceSetupEyeTracking_;
    useFaceSetupBlinking = enableBlinking;
    SetEnableAnimation(owner, true);
    SetEnableMoodAnimation(owner, enableMoodAnimation);
    SetEnableLipSyncAnimation(owner, enableLipSyncAnimation);
    SetEnableGestureAnimation(owner, enableGestureAnimation);
    SetEnableEyeTracking(owner, enableEyeTracking);
    SetEnableBlinking(owner, enableBlinking);
    SetEnableLidDeformation(owner, enableLidDeformation);
    DormantEnd(owner, 0);
    return true;
}

// Retail symbol: ?Update@idFaceMgr@@QAAXPAVidEntity@@PAVidTreeAnimator@@ABVidVec3@@@Z
// EA: 0x82B330C0, RVA: 0x00B330C0
void idFaceMgr::Update(idEntity* const owner,
        idTreeAnimator* const treeAnimator, const idVec3& focusPoint) {
    if ((flags & FACEFLAG_ENABLE) == 0) {
        return;
    }
    UpdateLipSync(owner, treeAnimator);
    faceAnimator.Update(this, owner, treeAnimator);
    const int now = services != nullptr ? services->GetGameTime() : 0;
    if (AnimateBlinks() && nextBlinkTime >= 0 && now >= nextBlinkTime) {
        faceAnimator.Blink(this, owner, treeAnimator);
        nextBlinkTime = now + (services != nullptr
            ? services->RandomInterval(500, 7500) : 500);
    }
    if ((flags & FACEFLAG_ANIMATE_GLANCE) != 0
            && (flags & FACEFLAG_SUPPRESS_GLANCE) == 0
            && faceAnimator.IsGlancingEnabled()
            && (lastGlanceTime < 0
                || now - lastGlanceTime >= currentGlanceInterval)) {
        const int glance = SelectNewGlanceIndex(owner, treeAnimator);
        if (glance >= 0) {
            faceAnimator.Glance(idAnimAliasHandle(
                static_cast<unsigned short>(glance)), this, owner,
                treeAnimator);
            lastGlanceTime = now;
        }
    }
    if ((flags & FACEFLAG_ANIMATE_FIDGET) != 0
            && (flags & FACEFLAG_SUPPRESS_FIDGET) == 0
            && faceAnimator.AreIdleFidgetsEnabled()
            && (lastFidgetTime < 0
                || now - lastFidgetTime >= currentFidgetInterval)) {
        const int fidget = SelectNewFidgetIndex(owner, treeAnimator);
        if (fidget >= 0) {
            faceAnimator.Fidget(idAnimAliasHandle(
                static_cast<unsigned short>(fidget)), this, owner,
                treeAnimator);
            lastFidgetTime = now;
        }
    }
    lastMood = mood;
    lastFlags = flags;
    if (services != nullptr) {
        services->UpdateFace(*this, owner, treeAnimator, focusPoint);
    }
}

// Retail symbol: ?StartVoiceOver@idFaceMgr@@QAA_NPAVidEntity@@PAVidTreeAnimator@@PBVidDeclVoiceOver@@@Z
// EA: 0x82B34430, RVA: 0x00B34430
bool idFaceMgr::StartVoiceOver(idEntity* const owner,
        idTreeAnimator* const treeAnimator,
        const idDeclVoiceOver* const voiceOverDeclaration) {
    if (services == nullptr || voiceOverDeclaration == nullptr) {
        return false;
    }
    const int count = services->GetVoiceTrackCount(voiceOverDeclaration);
    if (count <= 0) {
        return false;
    }
    if (voiceOver == voiceOverDeclaration) {
        return true;
    }
    const int track = services->ChooseVoiceTrack(
        voiceOverDeclaration, count, -1);
    return StartVoiceTrack(owner, treeAnimator,
        voiceOverDeclaration, track);
}
