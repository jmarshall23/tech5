#include "focusinfo.h"

#include <algorithm>

namespace {

idVec3 ProjectOntoPlane(const idVec3& vector, idVec3 normal) {
    if (normal.NormalizeFast() == 0.0f) {
        return vector;
    }
    return vector - normal * vector.Dot(normal);
}

} // namespace

// Retail symbol: ?Shutdown@idFocusInfo@@QAAXPAVidAnimatedEntity@@@Z
// EA: 0x82A9C058, RVA: 0x00A9C058
void idFocusInfo::Shutdown(idAnimatedEntity* const owner) {
    if (owner == nullptr || fociType > AIFOCI_LOOK) {
        return;
    }
    for (idAnimator_TrackerBase* const animator : animators) {
        if (animator != nullptr) {
            Tungsten_ShutdownFocusAnimator(*animator, *owner);
        }
    }
}

// Retail symbol: ?SetConstraints@idFocusInfo@@QAAXABVidRotationTrackerRange@@@Z
// EA: 0x82A9C0B8, RVA: 0x00A9C0B8
void idFocusInfo::SetConstraints(
        const idRotationTrackerRange& constraints) {
    if (animators[0] != nullptr && animators[1] != nullptr) {
        aimTracker.SetConstraints(constraints);
    }
}

// Retail symbol: ?AddWeaponFireKickback@idFocusInfo@@QAAXPBVidAnimatedEntity@@PBVidWeapon@@@Z
// EA: 0x82A9C0E0, RVA: 0x00A9C0E0
void idFocusInfo::AddWeaponFireKickback(
        const idAnimatedEntity* const owner,
        const idWeapon* const weapon) {
    wanderingAim.AddWeaponFireKickbackImpulse(
        Tungsten_CastFocusOwnerToAI2(owner), weapon);
}

// Retail symbol: ?SetEnableTracking@idFocusInfo@@QAAXPBVidAnimatedEntity@@_N@Z
// EA: 0x82A9C130, RVA: 0x00A9C130
void idFocusInfo::SetEnableTracking(
        const idAnimatedEntity* const owner, const bool enable) {
    (void)owner;
    enableTracking = enable;
}

// Retail symbol: ?SetSuppressTracking@idFocusInfo@@QAAXPBVidAnimatedEntity@@_N@Z
// EA: 0x82A9C138, RVA: 0x00A9C138
void idFocusInfo::SetSuppressTracking(
        const idAnimatedEntity* const owner, const bool suppress) {
    (void)owner;
    suppressTracking = suppress;
}

// Retail symbol: ?SetDeclTrackingParms@idFocusInfo@@QAAXPBVidDeclTrackingParms@@@Z
// EA: 0x82A9C140, RVA: 0x00A9C140
void idFocusInfo::SetDeclTrackingParms(
        const idDeclTrackingParms* const declaration) {
    if (declaration != nullptr) {
        declTrackingParms = declaration;
    }
}

// Retail symbol: ?SetTrackingParmsIndex@idFocusInfo@@QAAXH@Z
// EA: 0x82A9C150, RVA: 0x00A9C150
void idFocusInfo::SetTrackingParmsIndex(const int index) {
    trackingParmsIndex = index;
}

// Retail symbol: ??1idFocusInfo@@QAA@XZ
// EA: 0x82A9C168, RVA: 0x00A9C168
idFocusInfo::~idFocusInfo() {
    for (idAnimator_TrackerBase*& animator : animators) {
        Tungsten_DestroyFocusAnimator(animator);
        animator = nullptr;
    }
}

// Retail symbol: ?SetTempFocusPoint@idFocusInfo@@QAAXPAVidAnimatedEntity@@ABVidVec3@@W4aiFocus_t@@@Z
// EA: 0x82A9C200, RVA: 0x00A9C200
void idFocusInfo::SetTempFocusPoint(idAnimatedEntity* const owner,
        const idVec3& focusPoint, const aiFocus_t type) {
    (void)owner;
    if (animators[0] != nullptr && animators[1] != nullptr) {
        idealFocusPoint = focusPoint;
        focusType = type;
    }
}

// Retail symbol: ?SetLockTracking@idFocusInfo@@QAAX_N@Z
// EA: 0x82A9C238, RVA: 0x00A9C238
void idFocusInfo::SetLockTracking(const bool lock) {
    lockTracking = lock;
    for (idAnimator_TrackerBase* const animator : animators) {
        if (animator != nullptr) {
            Tungsten_SetFocusAnimatorLock(*animator, lock);
        }
    }
}

// Retail symbol: ?Init@idFocusInfo@@QAAXPAVidAnimatedEntity@@W4aiFoci_t@@@Z
// EA: 0x82A9C380, RVA: 0x00A9C380
void idFocusInfo::Init(idAnimatedEntity* const owner,
        const aiFoci_t type) {
    fociType = type;
    if (owner == nullptr || (type != AIFOCI_AIM && type != AIFOCI_LOOK)) {
        return;
    }
    const bool aim = type == AIFOCI_AIM;
    const char* const names[2] = {
        aim ? "torso_track_1" : "head_track_1",
        aim ? "torso_track_2" : "head_track_2"
    };
    for (int index = 0; index < 2; ++index) {
        if (animators[index] != nullptr) {
            Tungsten_DestroyFocusAnimator(animators[index]);
        }
        animators[index] = Tungsten_CreateFocusAnimator(
            *owner, type, index, names[index], aim);
    }
}

// Retail symbol: ?GetCurHeadTrackGroup@idFocusInfo@@QBAPBVidHeadTrackGroup@idDeclMD6@@PBVidAnimatedEntity@@@Z
// EA: 0x82A9C7D8, RVA: 0x00A9C7D8
const idDeclMD6::idHeadTrackGroup* idFocusInfo::GetCurHeadTrackGroup(
        const idAnimatedEntity* const owner) const {
    if (owner == nullptr) {
        return nullptr;
    }
    int groupIndex = 0;
    if (animators[0] != nullptr && animators[1] != nullptr) {
        groupIndex = Tungsten_GetFocusAnimatorTrackGroup(
            *animators[curAnimatorIndex]);
    }
    const int groupCount = Tungsten_GetFocusHeadTrackGroupCount(*owner);
    return groupIndex >= 0 && groupIndex < groupCount
        ? Tungsten_GetFocusHeadTrackGroup(*owner, groupIndex) : nullptr;
}

// Retail symbol: ?SwapTrackers@idFocusInfo@@AAAXPBVidAnimatedEntity@@H@Z
// EA: 0x82A9C8C8, RVA: 0x00A9C8C8
void idFocusInfo::SwapTrackers(const idAnimatedEntity* const owner,
        int blendTime) {
    if (owner == nullptr || animators[0] == nullptr
            || animators[1] == nullptr) {
        return;
    }
    if (blendTime < 0) {
        const int trackGroup = Tungsten_GetFocusAnimatorTrackGroup(
            *animators[curAnimatorIndex]);
        const idDeclMD6::idHeadTrackGroup* const group =
            GetCurHeadTrackGroup(owner);
        blendTime = trackGroup < 0 || group == nullptr
            ? 500 : group->blendTime;
    }
    const int currentTime = Tungsten_GetFocusGameMilliseconds();
    Tungsten_EndFocusAnimator(*animators[curAnimatorIndex],
        *owner, currentTime, blendTime, true);
    curAnimatorIndex = curAnimatorIndex == 0 ? 1 : 0;
    Tungsten_StartFocusAnimator(*animators[curAnimatorIndex],
        *owner, currentTime, blendTime, true);
}

// Retail symbol: ?SetReferenceJointOverride@idFocusInfo@@QAAXPBVidAnimatedEntity@@V?$idIndex@FW4invalidJointIndex_t@@@@@Z
// EA: 0x82A9CA28, RVA: 0x00A9CA28
void idFocusInfo::SetReferenceJointOverride(
        const idAnimatedEntity* const owner,
        const idIndex<short, invalidJointIndex_t> jointIndex) {
    if (animators[curAnimatorIndex] == nullptr
            || Tungsten_GetFocusAnimatorReferenceJoint(
                *animators[curAnimatorIndex]) == jointIndex) {
        return;
    }
    const int trackGroup = Tungsten_GetFocusAnimatorTrackGroup(
        *animators[curAnimatorIndex]);
    SwapTrackers(owner, -1);
    Tungsten_SetFocusAnimatorTrackGroup(
        *animators[curAnimatorIndex], trackGroup);
    Tungsten_SetFocusAnimatorReferenceJoint(
        *animators[curAnimatorIndex], jointIndex);
}

// Retail symbol: ??0idFocusInfo@@QAA@XZ
// EA: 0x82A9CAE0, RVA: 0x00A9CAE0
idFocusInfo::idFocusInfo()
    : wanderingAim()
    , focusEntity()
    , aimPoint(AIMPOINT_HEAD)
    , declTrackingParms(nullptr)
    , trackingParmsIndex(-1)
    , focusTimeout(-1)
    , idealFocusPoint(0.0f, 0.0f, 0.0f)
    , curFocusPoint(0.0f, 0.0f, 0.0f)
    , offset(0.0f, 0.0f, 0.0f)
    , explicitOffset(0.0f, 0.0f, 0.0f)
    , explicitOffsetAngles(0.0f, 0.0f, 0.0f)
    , aimTracker()
    , fociType(AIFOCI_MAX)
    , focusType(AIFOCUS_NOTHING)
    , defaultHeadTrackGroup(-1)
    , animators{ nullptr, nullptr }
    , curAnimatorIndex(1)
    , wsReferenceAxis(1.0f)
    , enableTracking(true)
    , suppressTracking(false)
    , keepFocusInView(false)
    , hasExplicitFocusPoint(false)
    , lockTracking(false) {
}

// Retail symbol: ?SetExplicitFocusPoint@idFocusInfo@@QAAXPAVidAnimatedEntity@@ABVidVec3@@_NHW4aiFocus_t@@@Z
// EA: 0x82A9CC38, RVA: 0x00A9CC38
void idFocusInfo::SetExplicitFocusPoint(idAnimatedEntity* const owner,
        const idVec3& focusPoint, const bool keepInView,
        const int duration, const aiFocus_t type) {
    (void)owner;
    if (animators[0] == nullptr || animators[1] == nullptr) {
        return;
    }
    idealFocusPoint = focusPoint;
    hasExplicitFocusPoint = true;
    focusEntity.Invalidate();
    keepFocusInView = keepInView;
    aimPoint = AIMPOINT_HEAD;
    focusType = type;
    focusTimeout = duration == -1
        ? -1 : Tungsten_GetFocusGameMilliseconds() + duration;
}

// Retail symbol: ?Clear@idFocusInfo@@QAAXPAVidAnimatedEntity@@@Z
// EA: 0x82A9CCF0, RVA: 0x00A9CCF0
void idFocusInfo::Clear(idAnimatedEntity* const owner) {
    (void)owner;
    hasExplicitFocusPoint = false;
    focusEntity.Invalidate();
    keepFocusInView = false;
    aimPoint = AIMPOINT_EYELEVEL;
    focusTimeout = -1;
    focusType = AIFOCUS_NOTHING;
    offset.Zero();
}

// Retail symbol: ?BlendOut@idFocusInfo@@AAAXPBVidAnimatedEntity@@H@Z
// EA: 0x82A9CD40, RVA: 0x00A9CD40
void idFocusInfo::BlendOut(const idAnimatedEntity* const owner,
        int blendTime) {
    if (owner == nullptr || animators[0] == nullptr
            || animators[1] == nullptr) {
        return;
    }
    if (blendTime < 0) {
        const idDeclMD6::idHeadTrackGroup* const group =
            GetCurHeadTrackGroup(owner);
        blendTime = group != nullptr ? group->blendTime : 500;
    }
    Tungsten_EndFocusAnimator(*animators[curAnimatorIndex], *owner,
        Tungsten_GetFocusGameMilliseconds(), blendTime, false);
}

// Retail symbol: ?BlendIn@idFocusInfo@@AAAXPBVidAnimatedEntity@@H@Z
// EA: 0x82A9CDE0, RVA: 0x00A9CDE0
void idFocusInfo::BlendIn(const idAnimatedEntity* const owner,
        int blendTime) {
    if (owner == nullptr || animators[0] == nullptr
            || animators[1] == nullptr) {
        return;
    }
    if (blendTime < 0) {
        const idDeclMD6::idHeadTrackGroup* const group =
            GetCurHeadTrackGroup(owner);
        blendTime = group != nullptr ? group->blendTime : 500;
    }
    Tungsten_StartFocusAnimator(*animators[curAnimatorIndex], *owner,
        Tungsten_GetFocusGameMilliseconds(), blendTime, false);
}

// Retail symbol: ?ShowTrackingInfo@idFocusInfo@@ABAXPBVidAnimatedEntity@@PBDABVidVec3@@2@Z
// EA: 0x82A9CE88, RVA: 0x00A9CE88
void idFocusInfo::ShowTrackingInfo(
        const idAnimatedEntity* const owner, const char* const name,
        const idVec3& eyePosition,
        const idVec3& debugOffset) const {
    if (owner == nullptr || animators[curAnimatorIndex] == nullptr) {
        return;
    }
    Tungsten_DebugFocusTracking(*this, *owner, name, eyePosition,
        debugOffset, GetCurHeadTrackGroup(owner),
        Tungsten_GetFocusAnimatorReferenceJoint(
            *animators[curAnimatorIndex]),
        Tungsten_GetFocusTrackingDeclName(declTrackingParms));
}

// Retail symbol: ?SetCurHeadTrackGroup@idFocusInfo@@QAAXPBVidAnimatedEntity@@H@Z
// EA: 0x82A9D278, RVA: 0x00A9D278
void idFocusInfo::SetCurHeadTrackGroup(
        const idAnimatedEntity* const owner,
        const int trackGroupIndex) {
    if (animators[0] == nullptr || animators[1] == nullptr
            || Tungsten_GetFocusAnimatorTrackGroup(
                *animators[curAnimatorIndex]) == trackGroupIndex
            || !Tungsten_CanSwapFocusAnimators(
                *animators[0], *animators[1])) {
        return;
    }
    SwapTrackers(owner, -1);
    idIndex<short, invalidJointIndex_t> invalidJoint;
    Tungsten_SetFocusAnimatorReferenceJoint(
        *animators[curAnimatorIndex], invalidJoint);
    Tungsten_SetFocusAnimatorTrackGroup(
        *animators[curAnimatorIndex], trackGroupIndex);
}

// Retail symbol: ?SetFocusEntity@idFocusInfo@@QAAXPAVidAnimatedEntity@@PBVidEntity@@_NW4aimPoint_t@@H@Z
// EA: 0x82A9D390, RVA: 0x00A9D390
void idFocusInfo::SetFocusEntity(idAnimatedEntity* const owner,
        const idEntity* const entity, const bool keepInView,
        const aimPoint_t point, const int duration) {
    if (animators[0] == nullptr || animators[1] == nullptr) {
        return;
    }
    if (reinterpret_cast<const void*>(entity)
            == reinterpret_cast<const void*>(owner)) {
        Tungsten_WarnFocusInfo(
            "idFocusInfo::SetFocusEntity - owner told to focus on itself");
        Clear(owner);
        return;
    }
    hasExplicitFocusPoint = false;
    focusEntity.SetSpawnId(Tungsten_GetFocusEntitySpawnId(entity));
    keepFocusInView = keepInView;
    aimPoint = point;
    focusType = AIFOCUS_ENTITY;
    if (entity != nullptr) {
        Tungsten_GetFocusEntityAimPoint(
            *entity, point, idealFocusPoint);
    }
    focusTimeout = duration == -1
        ? -1 : Tungsten_GetFocusGameMilliseconds() + duration;
}

bool idFocusInfo::HasFocus() const {
    if (focusTimeout != -1
            && Tungsten_GetFocusGameMilliseconds() >= focusTimeout) {
        return false;
    }
    return focusType != AIFOCUS_NOTHING
        && (hasExplicitFocusPoint || focusType != AIFOCUS_ENTITY
            || Tungsten_ResolveFocusEntity(
                focusEntity.GetSpawnId()) != nullptr);
}

// Retail symbol: ?Update@idFocusInfo@@QAAXPBVidAnimatedEntity@@PBVidAnimator_TrackerBase@@@Z
// EA: 0x82A9D4F0, RVA: 0x00A9D4F0
void idFocusInfo::Update(const idAnimatedEntity* const owner,
        const idAnimator_TrackerBase* const parentTracker) {
    if (owner == nullptr || animators[0] == nullptr
            || animators[1] == nullptr) {
        return;
    }
    idFocusUpdateRuntime runtime;
    if (!Tungsten_GetFocusUpdateRuntime(*owner, runtime)
            || runtime.skipForDeathGore) {
        return;
    }
    idAnimator_TrackerBase& animator =
        *animators[curAnimatorIndex];
    idFocusAnimatorState animatorState = {};
    if (!Tungsten_GetFocusAnimatorState(animator, animatorState)) {
        return;
    }
    if (HasFocus() && enableTracking && !suppressTracking) {
        if (animatorState.alpha < 1.0f && !animatorState.blendingIn) {
            BlendIn(owner, -1);
        }
    } else if (animatorState.alpha > 0.0f
            && !animatorState.blendingOut) {
        BlendOut(owner, -1);
    }
    const int trackingParmsCount = declTrackingParms != nullptr
        ? Tungsten_GetFocusTrackingParmsCount(*declTrackingParms) : 0;
    if (trackingParmsCount <= 0) {
        return;
    }

    idVec3 eyePosition;
    float ownerRadius = 0.0f;
    idVec3 gravityNormal(0.0f, 0.0f, -1.0f);
    if (!Tungsten_GetFocusFrameOfReference(*owner, animator,
            parentTracker, eyePosition, wsReferenceAxis,
            ownerRadius, gravityNormal)) {
        return;
    }

    idRotationTrackerRange constraints;
    aimTracker.GetConstraints(constraints);
    idVec3 animatorOffset = offset;
    if (!lockTracking) {
        int parameterIndex = trackingParmsIndex;
        if (fociType == AIFOCI_AIM
                && runtime.aimTrackingIndexOverride >= 0) {
            parameterIndex = runtime.aimTrackingIndexOverride;
        } else if (fociType == AIFOCI_LOOK
                && runtime.lookTrackingIndexOverride >= 0) {
            parameterIndex = runtime.lookTrackingIndexOverride;
        }
        parameterIndex = (std::max)(0, (std::min)(parameterIndex,
            trackingParmsCount - 1));
        if (!Tungsten_GetFocusTrackingParms(*declTrackingParms,
                parameterIndex, aimTracker.curParms)) {
            return;
        }

        idVec3 direction = idealFocusPoint - eyePosition;
        if (fociType == AIFOCI_AIM
                && direction.LengthSqr()
                    < ownerRadius * ownerRadius * 2.25f) {
            direction = ProjectOntoPlane(direction, gravityNormal);
            animatorOffset.Zero();
        }
        float distance = direction.NormalizeFast();
        if (distance < 0.0001f) {
            distance = 32.0f;
            direction = wsReferenceAxis[0];
        }
        if (runtime.aiOwner != nullptr && fociType == AIFOCI_AIM
                && runtime.wanderingAimEnabled
                && !runtime.accuracyPerfect) {
            idVec3 wanderedFocus = idealFocusPoint;
            wanderingAim.Update(runtime.aiOwner, eyePosition, direction,
                distance, wanderedFocus, runtime.showWanderingAim);
            direction = wanderedFocus - eyePosition;
            distance = direction.NormalizeFast();
            if (distance < 0.00001f) {
                distance = 32.0f;
                direction = wsReferenceAxis[0];
            }
        }
        const int trackerDebug = fociType == AIFOCI_AIM
            ? runtime.aimTrackerDebugLevel
            : runtime.lookTrackerDebugLevel;
        aimTracker.Update(eyePosition, wsReferenceAxis, direction,
            runtime.frameMilliseconds * 0.001f,
            fociType == AIFOCI_AIM, trackerDebug);
        idVec3 trackedDirection;
        aimTracker.GetWorldSpaceDir(wsReferenceAxis, trackedDirection);
        curFocusPoint = eyePosition + trackedDirection * distance;
    }

    const idVec3 finalFocusPoint =
        curFocusPoint + animatorOffset + explicitOffset;
    if (animatorState.contributing) {
        Tungsten_UpdateFocusAnimator(animator, parentTracker,
            finalFocusPoint, explicitOffsetAngles, constraints);
    }
    if (runtime.globalDebugLevel > 0
            && ((fociType == AIFOCI_AIM && runtime.aimDebugLevel >= 2)
                || (fociType == AIFOCI_LOOK
                    && runtime.lookDebugLevel >= 2))) {
        Tungsten_DebugFocusGeometry(
            *this, *owner, eyePosition, finalFocusPoint);
    }
    if (runtime.globalDebugLevel > 0
            && runtime.trackingDebugLevel > 0) {
        const idVec3 debugOffset(0.0f, 0.0f,
            fociType == AIFOCI_AIM ? 8.0f : 2.0f);
        ShowTrackingInfo(owner,
            fociType == AIFOCI_AIM ? "aim" : "look",
            eyePosition, debugOffset);
    }
}
