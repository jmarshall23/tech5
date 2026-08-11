#include "game/entities/alignedentity.h"

namespace {
idAlignedEntityServices defaultAlignedEntityServices;
idAlignedEntityServices* activeAlignedEntityServices =
    &defaultAlignedEntityServices;

idAlignedBlendParms CopyBlend(const idAlignedBlendParms* blend) {
    return blend == nullptr ? idAlignedBlendParms{} : *blend;
}
}

void idAlignedEntity::SetServices(idAlignedEntityServices* services) {
    activeAlignedEntityServices = services == nullptr
        ? &defaultAlignedEntityServices : services;
}

idAlignedEntityServices& idAlignedEntity::Services() {
    return *activeAlignedEntityServices;
}

// EA 0x82BEF040
void idAlignedEntity::JobSync() {
    Services().JobSync(*this);
}

// EA 0x82BEF048
void idAlignedEntity::SetAnimRateScale(const float scale) {
    Services().SetAnimationRate(*this, false, scale);
}

// EA 0x82BEF0C8
bool idAlignedEntity::IsAnimating() const {
    return Services().IsAnimatorActive(*this, false)
        || Services().IsAnimatorActive(*this, true);
}

// EA 0x82BEF168
void idAlignedEntity::GetSoundTransform(
        idVec3& soundOrigin, idMat3& soundAxis) const {
    Services().GetSoundTransform(*this, soundOrigin, soundAxis);
}

// EA 0x82BEF238
void idAlignedEntity::GetModelTransform(
        idVec3& modelOrigin, idMat3& modelAxis) const {
    Services().GetModelTransform(*this, modelOrigin, modelAxis);
}

// EA 0x82BEF3D0
bool idAlignedEntity::InternalPlayAnim(const bool additive,
        animInfo_t& info, const idAnimAliasHandle& handle,
        const bool loop, const int durationMS,
        const idAlignedBlendParms* blendParms, const float rateScale) {
    if (!handle.IsValid()) return false;
    if (!Services().PlayAnimation(*this, additive, handle, loop,
            durationMS, blendParms, rateScale)) {
        return false;
    }
    info.curAliasHandle = handle;
    info.startTime = Services().GetGameMilliseconds();
    info.animDurationMS = durationMS > 0
        ? durationMS : Services().GetAnimationDuration(*this, additive, handle);
    info.startBlendOut = false;
    return true;
}

// EA 0x82BEF500
bool idAlignedEntity::IsAnimDone(
        const idAnimAliasHandle handle, const int blendOut) const {
    if (!handle.IsValid() || baseAnimInfo.curAliasHandle != handle) {
        return true;
    }
    return Services().IsAnimationDone(*this, false, blendOut);
}

// EA 0x82BEF5B0
const char* idAlignedEntity::GetCurAnimName() const {
    return Services().GetAnimationName(*this, false);
}

// EA 0x82BEF640
void idAlignedEntity::GetLastOriginDeltas(
        idMat3& deltaAxis, idVec3& deltaOrigin, int* deltaTime) const {
    Services().GetLastOriginDeltas(
        *this, deltaAxis, deltaOrigin, deltaTime);
}

// EA 0x82BEF690
void idAlignedEntity::StopAdditiveAnim() {
    Services().StopAnimation(*this, true);
    additiveAnimInfo.curAliasHandle.Invalidate();
    additiveAnimInfo.queuedAnims.Clear();
}

// EA 0x82BEF6A8
void idAlignedEntity::SetAdditiveAnimAlpha(
        const float alpha, const float blendTime) {
    Services().SetAnimationAlpha(*this, true, alpha, blendTime);
}

// EA 0x82BEF738
bool idAlignedEntity::ForceNonDeferredAnimationUpdate() {
    return Services().ForceAnimationUpdate(*this);
}

// EA 0x82BEF7F0
void idAlignedEntity::Align(const idVec3& position,
        const idMat3& orientation, const ALIGNMODE mode) {
    if (mode == SET_POS_SET_AXIS || alignNodeName.IsEmpty()) {
        origin = position;
        axis = orientation;
    }
    Services().AlignEntity(
        *this, position, orientation, mode, alignNodeName.c_str());
}

// EA 0x82BEFD68
void idAlignedEntity::AttachToOwner(const int blendTime) {
    attachToOwnerBlend = blendTime;
    attachToOwnerStart = Services().GetGameMilliseconds();
    Services().AttachToOwner(*this, attachToOwnerStart, blendTime);
}

// EA 0x82BEFE60
void idAlignedEntity::DetachFromOwner(const int blendTime,
        const idVec3& detachedOrigin, const idQuat& detachedRotation) {
    endBlendOrigin = detachedOrigin;
    endBlendRot = detachedRotation;
    attachToOwnerBlend = blendTime;
    attachToOwnerStart = Services().GetGameMilliseconds();
    Services().DetachFromOwner(
        *this, blendTime, detachedOrigin, detachedRotation);
}

// EA 0x82BEFF60
void idAlignedEntity::SetManualUpdateCamera(const bool value) {
    manualUpdate = value;
    Services().SetManualCameraUpdate(*this, value);
}

// EA 0x82BEFF80
void idAlignedEntity::SetOrigin(const idVec3& value) {
    origin = value;
    Services().SetEntityTransform(*this, &origin, nullptr);
}

// EA 0x82BF0070
void idAlignedEntity::SetAxis(const idMat3& value) {
    axis = value;
    Services().SetEntityTransform(*this, nullptr, &axis);
}

// EA 0x82BF0158
void idAlignedEntity::DetachCamera(const bool force) {
    updateCamera = false;
    Services().DetachCamera(*this, force);
}

// EA 0x82BF0170
eventVoid idAlignedEntity::AnimEvent_DetachAttachmentByModel(
        const idMD6Anim*, const idDeclMD6* model) {
    Services().DetachAttachmentByModel(*this, model);
    return {};
}

// EA 0x82BF0280
eventVoid idAlignedEntity::AnimEvent_StartWeaponFX(
        const idMD6Anim*, const int condition) {
    Services().WeaponFX(*this, condition, true);
    return {};
}

// EA 0x82BF0440
eventVoid idAlignedEntity::AnimEvent_StopWeaponFX(
        const idMD6Anim*, const int condition) {
    Services().WeaponFX(*this, condition, false);
    return {};
}

// EA 0x82BF0558
eventVoid idAlignedEntity::AnimEvent_StartSlowMotion(
        const idMD6Anim*, const float in, const float scale,
        const float out) {
    Services().StartSlowMotion(*this, in, scale, out);
    return {};
}

// EA 0x82BF0658
eventVoid idAlignedEntity::AnimEvent_StopSlowMotion(const idMD6Anim*) {
    Services().StopSlowMotion(*this);
    return {};
}

// EA 0x82BF0718
eventVoid idAlignedEntity::AnimEvent_SoundBody(
        const idMD6Anim*, const idSoundShader* sound) {
    Services().PlayBodySound(*this, sound, 1, false);
    return {};
}

// EA 0x82BF07C0
eventVoid idAlignedEntity::AnimEvent_SoundBody2(
        const idMD6Anim*, const idSoundShader* sound) {
    Services().PlayBodySound(*this, sound, 2, false);
    return {};
}

// EA 0x82BF0868
eventVoid idAlignedEntity::AnimEvent_SoundBody3(
        const idMD6Anim*, const idSoundShader* sound) {
    Services().PlayBodySound(*this, sound, 3, false);
    return {};
}

// EA 0x82BF0910
eventVoid idAlignedEntity::AnimEvent_SoundBodyLoopUntilStopped(
        const idMD6Anim*, const idSoundShader* sound) {
    loopingSound.shader = sound;
    Services().PlayBodySound(*this, sound, 1, true);
    return {};
}

// EA 0x82BF09F8
eventVoid idAlignedEntity::AnimEvent_SoundBodyLoopStop(const idMD6Anim*) {
    Services().StopBodyLoopSound(*this);
    loopingSound.shader = nullptr;
    loopingSound.aliasHandle.Invalidate();
    return {};
}

// EA 0x82BF0AB0
eventVoid idAlignedEntity::AnimEvent_DetachCamera(const idMD6Anim*) {
    DetachCamera(false);
    return {};
}

// EA 0x82BF0B50
eventVoid idAlignedEntity::AnimEvent_StartCameraShake(
        const idMD6Anim*, const int amplitude, const int duration) {
    Services().StartCameraShake(*this, amplitude, duration);
    return {};
}

// EA 0x82BF0BE8
eventVoid idAlignedEntity::AnimEvent_SetControllerShake(
        const idMD6Anim*, const float low, const int lowTime,
        const float high, const int highTime) {
    Services().SetControllerShake(*this, low, lowTime, high, highTime);
    return {};
}

// EA 0x82BF0CD0
eventVoid idAlignedEntity::AnimEvent_HideHands(const idMD6Anim*) {
    Services().SetHandsVisible(*this, false);
    return {};
}

// EA 0x82BF0D60
eventVoid idAlignedEntity::AnimEvent_ShowHands(const idMD6Anim*) {
    Services().SetHandsVisible(*this, true);
    return {};
}

// EA 0x82BF0DF0
eventVoid idAlignedEntity::AnimEvent_CarryNPC(const idMD6Anim*) {
    Services().CarryNPC(*this);
    return {};
}

// EA 0x82BF0E88
eventVoid idAlignedEntity::AnimEvent_EntitySnapToPlayer(const idMD6Anim*) {
    Services().SnapEntityToPlayer(*this);
    return {};
}

// EA 0x82BF0F88
eventVoid idAlignedEntity::AnimEvent_PlayerSnapToEntity(const idMD6Anim*) {
    Services().SnapPlayerToEntity(*this);
    return {};
}

// EA 0x82BF11F0
eventVoid idAlignedEntity::AnimEvent_LeftFoot(const idMD6Anim*) {
    Services().PlayFootstep(*this, 0);
    return {};
}

// EA 0x82BF1280
eventVoid idAlignedEntity::AnimEvent_RightFoot(const idMD6Anim*) {
    Services().PlayFootstep(*this, 1);
    return {};
}

// EA 0x82BF1310
eventVoid idAlignedEntity::AnimEvent_LeftRearFoot(const idMD6Anim*) {
    Services().PlayFootstep(*this, 2);
    return {};
}

// EA 0x82BF13A0
eventVoid idAlignedEntity::AnimEvent_RightRearFoot(const idMD6Anim*) {
    Services().PlayFootstep(*this, 3);
    return {};
}

// EA 0x82BF1430
eventVoid idAlignedEntity::AnimEvent_Land(const idMD6Anim*) {
    Services().PlayFootstep(*this, 4);
    return {};
}

// EA 0x82BF14C0
eventVoid idAlignedEntity::AnimEvent_LeftFootLadder(const idMD6Anim*) {
    Services().PlayFootstep(*this, 5);
    return {};
}

// EA 0x82BF1550
eventVoid idAlignedEntity::AnimEvent_RightFootLadder(const idMD6Anim*) {
    Services().PlayFootstep(*this, 6);
    return {};
}

// EA 0x82BF15E0
eventVoid idAlignedEntity::AnimEvent_LegsCrossing(const idMD6Anim*) {
    Services().SetLegsCrossing(*this);
    return {};
}

// EA 0x82BF1678
eventVoid idAlignedEntity::AnimEvent_AnimStartBlendOut(const idMD6Anim*) {
    baseAnimInfo.startBlendOut = true;
    Services().StartBlendOut(*this, false);
    return {};
}

// EA 0x82BF1708
eventVoid idAlignedEntity::AnimEvent_AdditiveAnimStartBlendOut(
        const idMD6Anim*) {
    additiveAnimInfo.startBlendOut = true;
    Services().StartBlendOut(*this, true);
    return {};
}

// EA 0x82BF1798
eventVoid idAlignedEntity::AnimEvent_Unbind(const idMD6Anim*) {
    Services().Unbind(*this);
    return {};
}

// EA 0x82BF1830
eventVoid idAlignedEntity::AnimEvent_SwitchLedge(const idMD6Anim*) {
    Services().SwitchLedge(*this);
    return {};
}

// EA 0x82BF1898
eventVoid idAlignedEntity::AnimEvent_SprintSlideStartLoopingSlideSound(
        const idMD6Anim*) {
    Services().SetSprintSlide(*this, 1);
    return {};
}

// EA 0x82BF1928
eventVoid idAlignedEntity::AnimEvent_SprintSlideStopLoopingSlideSound(
        const idMD6Anim*) {
    Services().SetSprintSlide(*this, 2);
    return {};
}

// EA 0x82BF19B8
eventVoid idAlignedEntity::AnimEvent_SprintSlideStop(const idMD6Anim*) {
    Services().SetSprintSlide(*this, 0);
    return {};
}

// EA 0x82BF1A40
idAttachmentHandle idAlignedEntity::GetAnimatedAttachmentHandle(
        const char* group, const char* attachmentName) {
    return Services().FindAnimatedAttachment(
        *this, group, attachmentName);
}

// EA 0x82BF1B30
eventVoid idAlignedEntity::AnimEvent_AnimatedAttachment_Show(
        const idMD6Anim*, const char* group, const char* attachmentName) {
    Services().SetAnimatedAttachmentVisible(*this,
        GetAnimatedAttachmentHandle(group, attachmentName), true);
    return {};
}

// EA 0x82BF1BA0
eventVoid idAlignedEntity::AnimEvent_AnimatedAttachment_Hide(
        const idMD6Anim*, const char* group, const char* attachmentName) {
    Services().SetAnimatedAttachmentVisible(*this,
        GetAnimatedAttachmentHandle(group, attachmentName), false);
    return {};
}

// EA 0x82BF1C18
eventVoid idAlignedEntity::AnimEvent_AnimatedAttachment_PlayAnim(
        const idMD6Anim*, const char* group, const char* attachmentName,
        const char* animationName, const int blendTime) {
    Services().PlayAnimatedAttachmentAnimation(*this,
        GetAnimatedAttachmentHandle(group, attachmentName),
        animationName, blendTime);
    return {};
}

// EA 0x82BF1D10
bool idAlignedEntity::IsCurAnimDone(
        const int blendOut, const bool additive) const {
    const animInfo_t& info = additive ? additiveAnimInfo : baseAnimInfo;
    return !info.curAliasHandle.IsValid()
        || Services().IsAnimationDone(*this, additive, blendOut);
}

// EA 0x82BF1E00
void idAlignedEntity::ApplyOriginDeltas(const bool force) {
    Services().ApplyOriginDeltas(*this, force);
}

// EA 0x82BF22A0
bool idAlignedEntity::PlayAdditiveAnim(const idAnimAliasHandle& handle,
        const bool loop, const int durationMS,
        const idAlignedBlendParms* blendParms) {
    additiveAnimInfo.queuedAnims.Clear();
    return InternalPlayAnim(true, additiveAnimInfo, handle,
        loop, durationMS, blendParms, 1.0f);
}

// EA 0x82BF2370
void idAlignedEntity::UpdateOwnerFromCamera(const bool a, const bool b,
        const bool c, const bool d, const bool e) {
    Services().UpdateOwnerFromCamera(*this, a, b, c, d, e);
}

// EA 0x82BF26E0
void idAlignedEntity::UpdateOwnerToDefaultViewAngles(
        const bool a, const bool b, const bool c) {
    Services().UpdateOwnerDefaultView(*this, a, b, c);
}

// EA 0x82BF2780
void idAlignedEntity::DetachItems() {
    Services().DetachItems(*this);
    attachmentInfos.Clear();
}

// EA 0x82BF28E8
eventVoid idAlignedEntity::AnimEvent_DetachItem(const idMD6Anim*) {
    DetachItems();
    return {};
}

// EA 0x82BF2978
eventVoid idAlignedEntity::AnimEvent_SoundBodyLoopUntilAnimEnd(
        const idMD6Anim*, const idSoundShader* sound) {
    loopingSound.shader = sound;
    loopingSound.aliasHandle = baseAnimInfo.curAliasHandle;
    Services().PlayBodySound(*this, sound, 1, true);
    return {};
}

// EA 0x82BF2AA0
eventVoid idAlignedEntity::AnimEvent_SetViewAnglesFromCamera(
        const idMD6Anim*) {
    Services().SetViewAnglesFromCamera(*this, true, true, true);
    return {};
}

// EA 0x82BF2B40
eventVoid idAlignedEntity::AnimEvent_SetViewAnglesFromCameraExt(
        const idMD6Anim*, const int pitch, const int yaw, const int roll) {
    Services().SetViewAnglesFromCamera(
        *this, pitch != 0, yaw != 0, roll != 0);
    return {};
}

// EA 0x82BF2BF8
eventVoid idAlignedEntity::AnimEvent_SetViewAnglesToDefault(
        const idMD6Anim*) {
    UpdateOwnerToDefaultViewAngles(true, true, true);
    return {};
}

// EA 0x82BF2C90
eventVoid idAlignedEntity::Event_SetViewAnglesFromCamera() {
    Services().SetViewAnglesFromCamera(*this, true, true, true);
    return {};
}

// EA 0x82BF2D38
void idAlignedEntity::InternalBecomeInactive() {
    Services().BecomeInactive(*this);
}

// EA 0x82BF3070
bool idAlignedEntity::PlayAnim(const idAnimAliasHandle& handle,
        const bool loop, const int durationMS,
        const idAlignedBlendParms* blendParms, const float rateScale) {
    baseAnimInfo.queuedAnims.Clear();
    return InternalPlayAnim(false, baseAnimInfo, handle,
        loop, durationMS, blendParms, rateScale);
}

// EA 0x82BF31D0
void idAlignedEntity::StopAnim() {
    Services().StopAnimation(*this, false);
    baseAnimInfo.curAliasHandle.Invalidate();
    baseAnimInfo.queuedAnims.Clear();
}

// EA 0x82BF3220
void idAlignedEntity::SetExternalTime(const float time) {
    Services().SetExternalTime(*this, time);
}

// EA 0x82BF3300
bool idAlignedEntity::PlayAdditiveAnim(const char* animationName,
        const bool loop, const int durationMS,
        const idAlignedBlendParms* blendParms) {
    return PlayAdditiveAnim(
        Services().ResolveAnimationAlias(*this, animationName),
        loop, durationMS, blendParms);
}

// EA 0x82BF33A0
void idAlignedEntity::AttachCamera(const char* jointName,
        const int duration, const int lookMode, const int blendMode,
        const int blendTime, const float yawLimit, const float pitchLimit) {
    updateCamera = true;
    Services().AttachCamera(*this, jointName, duration, lookMode,
        blendMode, blendTime, yawLimit, pitchLimit);
}

// EA 0x82BF3470
eventVoid idAlignedEntity::AnimEvent_AttachCamera(const idMD6Anim*,
        const char* joint, const int duration,
        const int lookMode, const int blendMode) {
    AttachCamera(joint, duration, lookMode, blendMode, 0, 0.0f, 0.0f);
    return {};
}

// EA 0x82BF3540
eventVoid idAlignedEntity::AnimEvent_AttachCameraExt(const idMD6Anim*,
        const char* joint, const int duration, const int lookMode,
        const int blendMode, const int blendTime) {
    AttachCamera(joint, duration, lookMode, blendMode,
        blendTime, 0.0f, 0.0f);
    return {};
}

// EA 0x82BF3610
eventVoid idAlignedEntity::AnimEvent_AttachLimitViewCamera(
        const idMD6Anim*, const char* joint, const int duration,
        const float yawLimit, const float pitchLimit) {
    AttachCamera(joint, duration, 0, 0, 0, yawLimit, pitchLimit);
    return {};
}

// EA 0x82BF3750
eventVoid idAlignedEntity::Event_AttachLimitViewCamera(
        const char* joint, const int duration, const int blendTime,
        const float yawLimit, const float pitchLimit) {
    AttachCamera(joint, duration, 0, 0, blendTime, yawLimit, pitchLimit);
    return {};
}

// EA 0x82BF3938
void idAlignedEntity::Spawn() {
    Services().Spawn(*this);
    okToShow = true;
    lastAnimBlendFrame = -1;
    UpdateAttachments();
    UpdateInventoryItems();
}

// EA 0x82BF4190
bool idAlignedEntity::PlayAnim(const char* animationName,
        const bool loop, const int durationMS,
        const idAlignedBlendParms* blendParms, const float rateScale) {
    return PlayAnim(Services().ResolveAnimationAlias(*this, animationName),
        loop, durationMS, blendParms, rateScale);
}

// EA 0x82BF4628
idAlignedEntity::idAlignedEntity()
    : name(),
      origin(0.0f, 0.0f, 0.0f),
      axis(1.0f),
      loopingSound(),
      baseAnimInfo(),
      additiveAnimInfo(),
      alignNodeName(),
      isAlive(true),
      soundTagName(),
      attachmentInfos(0),
      manualUpdate(false),
      okToShow(false),
      updateCamera(false),
      owner(nullptr),
      lastAnimBlendFrame(-1),
      attachToOwnerBlend(0),
      attachToOwnerStart(0),
      deltaTransExternalWorld(0.0f, 0.0f, 0.0f),
      deltaTransScale(1.0f, 1.0f, 1.0f),
      startBlendOrigin(0.0f, 0.0f, 0.0f),
      startBlendRot(0.0f, 0.0f, 0.0f, 1.0f),
      endBlendOrigin(0.0f, 0.0f, 0.0f),
      endBlendRot(0.0f, 0.0f, 0.0f, 1.0f),
      attachedModelOrigin(0.0f, 0.0f, 0.0f),
      attachedModelAxis(1.0f) {}

// EA 0x82BF4AC8
idAlignedEntity::~idAlignedEntity() {
    DetachCamera(true);
    DetachItems();
    StopAdditiveAnim();
    StopAnim();
}

// EA 0x82BF4E18
void idAlignedEntity::UpdateAttachments() {
    Services().UpdateAttachments(*this);
}

// EA 0x82BF4FB8
void idAlignedEntity::QueueAnim(const idAnimAliasHandle& handle,
        const bool loop, const int durationMS,
        const idAlignedBlendParms* blendParms, const float rateScale) {
    if (!baseAnimInfo.curAliasHandle.IsValid() || IsCurAnimDone(0, false)) {
        InternalPlayAnim(false, baseAnimInfo, handle,
            loop, durationMS, blendParms, rateScale);
        return;
    }
    queuedAnim_t queued;
    queued.aliasHandle = handle;
    queued.loop = loop;
    queued.durationMS = durationMS;
    queued.rateScale = rateScale;
    queued.blendParms = CopyBlend(blendParms);
    baseAnimInfo.queuedAnims.Append(queued);
}

// EA 0x82BF50D8
void idAlignedEntity::QueueAdditiveAnim(const idAnimAliasHandle& handle,
        const bool loop, const int durationMS,
        const idAlignedBlendParms* blendParms) {
    if (!additiveAnimInfo.curAliasHandle.IsValid()
            || IsCurAnimDone(0, true)) {
        InternalPlayAnim(true, additiveAnimInfo, handle,
            loop, durationMS, blendParms, 1.0f);
        return;
    }
    queuedAnim_t queued;
    queued.aliasHandle = handle;
    queued.loop = loop;
    queued.durationMS = durationMS;
    queued.rateScale = 1.0f;
    queued.blendParms = CopyBlend(blendParms);
    additiveAnimInfo.queuedAnims.Append(queued);
}

// EA 0x82BF5178
void idAlignedEntity::UpdateInventoryItems() {
    Services().UpdateInventoryItems(*this);
}

// EA 0x82BF54F8
void idAlignedEntity::Update() {
    const auto advanceQueue = [this](const bool additive,
            animInfo_t& info) {
        if (!info.curAliasHandle.IsValid()
                || !Services().IsAnimationDone(*this, additive, 0)) {
            return;
        }
        if (info.queuedAnims.IsEmpty()) {
            info.curAliasHandle.Invalidate();
            return;
        }
        const queuedAnim_t queued = info.queuedAnims[0];
        info.queuedAnims.RemoveIndex(0);
        InternalPlayAnim(additive, info, queued.aliasHandle,
            queued.loop, queued.durationMS,
            &queued.blendParms, queued.rateScale);
    };
    advanceQueue(false, baseAnimInfo);
    advanceQueue(true, additiveAnimInfo);
    if (loopingSound.shader != nullptr
            && loopingSound.aliasHandle.IsValid()
            && loopingSound.aliasHandle != baseAnimInfo.curAliasHandle) {
        AnimEvent_SoundBodyLoopStop(nullptr);
    }
    if (updateCamera && !manualUpdate) {
        UpdateOwnerFromCamera(true, true, true, true, true);
    }
    UpdateInventoryItems();
    UpdateAttachments();
    Services().Update(*this);
}

// EA 0x82BF5CE8
void idAlignedEntity::QueueAnim(const char* animationName,
        const bool loop, const int durationMS,
        const idAlignedBlendParms* blendParms, const float rateScale) {
    QueueAnim(Services().ResolveAnimationAlias(*this, animationName),
        loop, durationMS, blendParms, rateScale);
}

// EA 0x82BF5D98
void idAlignedEntity::QueueAdditiveAnim(const char* animationName,
        const bool loop, const int durationMS,
        const idAlignedBlendParms* blendParms) {
    QueueAdditiveAnim(
        Services().ResolveAnimationAlias(*this, animationName),
        loop, durationMS, blendParms);
}

// EA 0x82BF5E38
void idAlignedEntity::AttachItem(const idDeclInventory* declaration,
        const char* joint, const bool autoDetach,
        const bool noClone, const bool special) {
    Services().AttachItem(
        *this, declaration, joint, autoDetach, noClone, special);
}

// EA 0x82BF6190
void idAlignedEntity::AttachEntity(idEntity* entity, const char* joint) {
    Services().AttachEntity(*this, entity, joint);
}

// EA 0x82BF61E0
eventVoid idAlignedEntity::AnimEvent_AttachItem(const idMD6Anim*,
        const idDeclInventory* declaration, const char* joint) {
    AttachItem(declaration, joint, true, false, false);
    return {};
}

// EA 0x82BF6288
eventVoid idAlignedEntity::AnimEvent_AttachItemForManualDetach(
        const idMD6Anim*, const idDeclInventory* declaration,
        const char* joint) {
    AttachItem(declaration, joint, false, false, false);
    return {};
}

// EA 0x82BF6330
eventVoid idAlignedEntity::AnimEvent_AttachSpecialItemForManualDetach(
        const idMD6Anim*, const idDeclInventory* declaration,
        const char* joint) {
    AttachItem(declaration, joint, false, false, true);
    return {};
}

// EA 0x82BF63D8
void idAlignedEntity::Think() {
    Update();
    Services().Think(*this);
}
