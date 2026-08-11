#include "game/entities/animatedsimple.h"

#include <algorithm>
#include <cmath>

namespace {
idAnimatedSimpleServices defaultAnimatedSimpleServices;
idAnimatedSimpleServices* animatedSimpleServices =
    &defaultAnimatedSimpleServices;

idQuat AnglesToQuat(const idAngles& angles) {
    constexpr float halfDegreesToRadians =
        0.00872664625997164788f;
    const float pitch = angles.pitch * halfDegreesToRadians;
    const float yaw = angles.yaw * halfDegreesToRadians;
    const float roll = angles.roll * halfDegreesToRadians;
    const float sp = std::sin(pitch), cp = std::cos(pitch);
    const float sy = std::sin(yaw), cy = std::cos(yaw);
    const float sr = std::sin(roll), cr = std::cos(roll);
    return idQuat(
        sr * cp * cy - cr * sp * sy,
        cr * sp * cy + sr * cp * sy,
        cr * cp * sy - sr * sp * cy,
        cr * cp * cy + sr * sp * sy);
}

void ActivateList(idAnimatedSimple& owner,
        const idList<idEntity*, 5>& entities) {
    for (int index = 0; index < entities.Num(); ++index) {
        if (entities[index] != nullptr) {
            idAnimatedSimple::SimpleServices().ActivateEntity(
                owner, entities[index]);
        }
    }
}
}

void idAnimatedSimple::SetSimpleServices(
        idAnimatedSimpleServices* const services) {
    animatedSimpleServices = services == nullptr
        ? &defaultAnimatedSimpleServices : services;
}

idAnimatedSimpleServices& idAnimatedSimple::SimpleServices() {
    return *animatedSimpleServices;
}

// Retail: 0x82BFCAB0 ?Hide@idAnimatedSimple@@UAAXXZ
void idAnimatedSimple::Hide() {
    physicsContent = SimpleServices().GetPhysicsContents(*this);
    SimpleServices().SetPhysicsContents(*this, 0);
    SimpleServices().Hide(*this, true, true);
    SimpleServices().ShowAttachments(*this, false);
}

// Retail: 0x82BFCB88 ?Hide@idAnimatedSimple@@UAAX_N@Z
void idAnimatedSimple::Hide(const bool stopFX) {
    physicsContent = SimpleServices().GetPhysicsContents(*this);
    SimpleServices().SetPhysicsContents(*this, 0);
    SimpleServices().Hide(*this, stopFX, false);
}

// Retail: 0x82BFCBF8 ?IsAnimating@idAnimatedSimple@@UBA_NXZ
bool idAnimatedSimple::IsAnimating() const {
    return !SimpleServices().IsChannelDone(*this);
}

// Retail: 0x82BFCC78 ?ModifyCrosshairInfo@idAnimatedSimple@@...
bool idAnimatedSimple::ModifyCrosshairInfo(const idEntity*,
        const idFocusTrace*, const usableState_t,
        idCrosshairInfo& info) const {
    SimpleServices().SetCrosshairHidden(info, true);
    return true;
}

// Retail: 0x82BFCC88 ?Event_GetAnimState@idAnimatedSimple@@QBA?AVeventInt@@XZ
eventInt idAnimatedSimple::Event_GetAnimState() const {
    return eventInt(currentState);
}

// Retail: 0x82BFCCC8 ?Teleport@idAnimatedSimple@@UAAXABVidVec3@@ABVidAngles@@@Z
void idAnimatedSimple::Teleport(
        const idVec3& origin, const idAngles& angles) {
    orgOrigin = origin;
    orgRotation = AnglesToQuat(angles);
    SimpleServices().Teleport(*this, origin, angles);
}

// Retail: 0x82BFCDB8 ?UpdateModelTransform@idAnimatedSimple@@UAAXXZ
void idAnimatedSimple::UpdateModelTransform() {
    SimpleServices().UpdateBaseModelTransform(*this);
    if ((thinkFlags & 5) == 0) {
        UpdateAttachments();
    }
}

// Retail: 0x82BFCE10 ?PostBind@idAnimatedSimple@@UAAXXZ
void idAnimatedSimple::PostBind() {
    if (applyAnimTransformLocal) {
        SimpleServices().GetTransform(
            *this, true, orgOrigin, orgRotation);
        nextOrigin = orgOrigin;
        nextRotation = orgRotation;
    }
}

// Retail: 0x82BFCF08 ?IsEverUsable@idAnimatedSimple@@UBA_NPBVidEntity@@@Z
bool idAnimatedSimple::IsEverUsable(
        const idEntity* const activator) const {
    return displayName >= 0
        || SimpleServices().IsBaseEverUsable(*this, activator);
}

// Retail: 0x82BFCF20 ?AnimEvent_DetachAttachment@idAnimatedSimple@@...
eventVoid idAnimatedSimple::AnimEvent_DetachAttachment(
        const idMD6Anim*, const char* const slotName) {
    SimpleServices().SetAttachmentDetached(*this, slotName, true);
    return {};
}

// Retail: 0x82BFCFF8 ?AnimEvent_ReattachAttachment@idAnimatedSimple@@...
eventVoid idAnimatedSimple::AnimEvent_ReattachAttachment(
        const idMD6Anim*, const char* const slotName) {
    SimpleServices().SetAttachmentDetached(*this, slotName, false);
    return {};
}

// Retail: 0x82BFD0D0 ?AnimEvent_VoiceOver@idAnimatedSimple@@...
eventVoid idAnimatedSimple::AnimEvent_VoiceOver(
        const idMD6Anim*, const idDeclVoiceOver* const voiceOver) {
    if (voiceOver != nullptr && SimpleServices().HasTreeAnimator(*this)) {
        SimpleServices().StartVoiceOver(*this, nullptr, voiceOver);
    }
    return {};
}

// Retail: 0x82BFD180 ?AnimEvent_StartWeaponFX@idAnimatedSimple@@...
eventVoid idAnimatedSimple::AnimEvent_StartWeaponFX(
        const idMD6Anim*, const fxCondition_t condition) {
    SimpleServices().WeaponFX(*this, condition, true);
    return {};
}

// Retail: 0x82BFD240 ?AnimEvent_StopWeaponFX@idAnimatedSimple@@...
eventVoid idAnimatedSimple::AnimEvent_StopWeaponFX(
        const idMD6Anim*, const fxCondition_t condition) {
    SimpleServices().WeaponFX(*this, condition, false);
    return {};
}

// Retail: 0x82BFD2B8 ?AnimEvent_HideModel@idAnimatedSimple@@...
eventVoid idAnimatedSimple::AnimEvent_HideModel(
        const idMD6Anim*, const idDeclMD6* const model) {
    if (model != nullptr) {
        SimpleServices().SetModelAttachment(*this, model, nullptr, false);
    }
    return {};
}

// Retail: 0x82BFD2F8 ?AnimEvent_ShowModel@idAnimatedSimple@@...
eventVoid idAnimatedSimple::AnimEvent_ShowModel(const idMD6Anim*,
        const idDeclMD6* const model, const char* const tag) {
    if (model != nullptr && tag != nullptr) {
        SimpleServices().SetModelAttachment(*this, model, tag, true);
    }
    return {};
}

// Retail: 0x82BFD350 ?AnimEvent_SetSceneModel@idAnimatedSimple@@...
eventVoid idAnimatedSimple::AnimEvent_SetSceneModel(const idMD6Anim*) {
    sceneModel = true;
    SimpleServices().SetSceneModel(*this, true);
    return {};
}

// Retail: 0x82BFD3E8 ?AnimEvent_ClearSceneModel@idAnimatedSimple@@...
eventVoid idAnimatedSimple::AnimEvent_ClearSceneModel(const idMD6Anim*) {
    sceneModel = false;
    SimpleServices().SetSceneModel(*this, false);
    return {};
}

// Retail: 0x82BFD488 ?Event_ShowAttachments@idAnimatedSimple@@...
eventVoid idAnimatedSimple::Event_ShowAttachments(const bool show) {
    SimpleServices().ShowAttachments(*this, show);
    return {};
}

// Retail: 0x82BFD4D8 ?Event_StartVoiceOver@idAnimatedSimple@@...
eventBool idAnimatedSimple::Event_StartVoiceOver(idEntity* const talkingTo,
        const idDeclVoiceOver* const voiceOver, const bool) {
    return eventBool(voiceOver != nullptr
        && SimpleServices().HasTreeAnimator(*this)
        && SimpleServices().StartVoiceOver(*this, talkingTo, voiceOver));
}

// Retail: 0x82BFD5B8 ?Event_IsVoiceOverPlaying@idAnimatedSimple@@...
eventBool idAnimatedSimple::Event_IsVoiceOverPlaying(
        const idDeclVoiceOver* const voiceOver) const {
    return eventBool(
        SimpleServices().IsVoiceOverPlaying(*this, voiceOver));
}

// Retail: 0x82BFD5F8 ??0idASDebugGUI@@QAA@XZ
idASDebugGUI::idASDebugGUI()
    : guiModel(nullptr)
    , hasFont(true) {
}

// Retail: 0x82BFD650 ??1idASDebugGUI@@QAA@XZ
idASDebugGUI::~idASDebugGUI() {
    if (guiModel != nullptr) {
        idAnimatedSimple::SimpleServices().DestroyDebugGUI(
            *this, guiModel);
        guiModel = nullptr;
    }
    hasFont = false;
}

// Retail: 0x82BFD6A8 ?Spawn@idAnimatedSimple@@QAAXXZ
void idAnimatedSimple::Spawn() {
    physicsContent = SimpleServices().GetPhysicsContents(*this) | 0x200000;
    SimpleServices().SetPhysicsContents(*this, physicsContent);
    SimpleServices().Spawn(*this);
    if (!SimpleServices().HasTreeAnimator(*this)) {
        return;
    }
    for (int index = 0; index < animList.Num(); ++index) {
        if (!animList[index].animation.IsEmpty()) {
            animList[index].animationHandle = SimpleServices().ResolveAlias(
                *this, animList[index].animation.c_str());
        }
    }
    SimpleServices().GetTransform(
        *this, false, orgOrigin, orgRotation);
    nextOrigin = orgOrigin;
    nextRotation = orgRotation;
    thinkFlags |= 1;
}

// Retail: 0x82BFDF08 ?LeaveState@idAnimatedSimple@@AAAXH@Z
void idAnimatedSimple::LeaveState(const int state) {
    if (state < 0 || state >= animList.Num()) {
        return;
    }
    animEntry_t& entry = animList[state];
    if (entry.useDeltaMovement) {
        SimpleServices().GetTransform(*this, applyAnimTransformLocal,
            nextOrigin, nextRotation);
    }
    ActivateList(*this, entry.triggerLeave);
}

// Retail: 0x82BFE070 ?PlayAnim@idAnimatedSimple@@QAAXABV?$idHandle...
void idAnimatedSimple::PlayAnim(const idAnimAliasHandle alias,
        const bool loop, const int blendTime) {
    if (!SimpleServices().HasTreeAnimator(*this)) {
        return;
    }
    SimpleServices().GetTransform(*this, applyAnimTransformLocal,
        orgOrigin, orgRotation);
    animStartFrame = SimpleServices().GetGameFrame();
    currentLoopCount = 0;
    if (!alias.IsValid()) {
        return;
    }
    thinkFlags |= 7;
    SimpleServices().PlayAnimation(*this, alias, loop, blendTime, 1.0f);
    SimpleServices().ComputeStateEndTransform(
        *this, STATE_NONE, nextOrigin, nextRotation);
}

// Retail: 0x82BFE4C0 ?PlayAnim@idAnimatedSimple@@QAAXABVidAnimAliasRef@@...
void idAnimatedSimple::PlayAnim(const idAnimAliasRef& alias,
        const bool loop, const int blendTime) {
    idAnimAliasHandle handle;
    for (int index = 0; index < animList.Num(); ++index) {
        if (animList[index].animation == alias) {
            handle = animList[index].animationHandle;
            break;
        }
    }
    PlayAnim(handle, loop, blendTime);
}

// Retail: 0x82BFE558 ?Event_PlayAnim@idAnimatedSimple@@...
eventVoid idAnimatedSimple::Event_PlayAnim(const char* const animName,
        const bool loop, const int blendTime) {
    if (SimpleServices().HasTreeAnimator(*this)) {
        PlayAnim(SimpleServices().ResolveAlias(*this, animName),
            loop, blendTime);
    }
    return {};
}

// Retail: 0x82BFE5D8 ?Damage@idAnimatedSimple@@UAAMPAVidEntity@@...
float idAnimatedSimple::Damage(idEntity*, idEntity* const attacker,
        const idDeclDamage* const damageDef, const float,
        const idVec3&, trace_t*) {
    if (!hitDetectionOptions.shouldGetHit
            || hitDetectionOptions.hasBeenKilled || damageDef == nullptr) {
        return 0.0f;
    }
    const int damageTypes = SimpleServices().GetDamageTypes(damageDef);
    if ((damageTypes & ~hitDetectionOptions.ignoreDamageTypes) == 0) {
        if (hitDetectionOptions.onIgnoredDamageTrigger != nullptr) {
            SimpleServices().ActivateEntity(
                *this, hitDetectionOptions.onIgnoredDamageTrigger);
        }
        return 0.0f;
    }
    const int amount = SimpleServices().GetDamageAmount(damageDef);
    hitDetectionOptions.health -= amount;
    if (hitDetectionOptions.health <= 0) {
        hitDetectionOptions.hasBeenKilled = true;
        if (!hitDetectionOptions.callWhenDead.IsEmpty()) {
            SimpleServices().CallDeathFunction(*this,
                hitDetectionOptions.callWhenDead.c_str(), attacker);
        }
        if (hitDetectionOptions.callTargetWhenDead != nullptr) {
            SimpleServices().ActivateEntity(
                *this, hitDetectionOptions.callTargetWhenDead);
        }
    }
    return static_cast<float>(amount);
}

// Retail: 0x82BFE778 ?PauseCurrentAnim@idAnimatedSimple@@QAAX_NH0@Z
void idAnimatedSimple::PauseCurrentAnim(const bool pause,
        const int pauseFrame, const bool queuePause_) {
    if (pause) {
        if (queuePause_ && pauseFrame >= 0
                && (SimpleServices().GetAnimationFrame(*this) < pauseFrame
                    || wasLooping)) {
            queuePauseFrame = pauseFrame;
            queuePause = true;
            return;
        }
        SimpleServices().PauseAnimation(*this, pauseFrame, wasLooping);
        isPaused = true;
    } else {
        SimpleServices().UnpauseAnimation(*this, wasLooping);
        isPaused = false;
        thinkFlags |= 7;
    }
}

// Retail: 0x82BFE9F0 ?SetExternalTime@idAnimatedSimple@@QAAXM@Z
void idAnimatedSimple::SetExternalTime(float normalizedTime) {
    if (currentState < 0 || currentState >= animList.Num()
            || !animList[currentState].useTimeControl) {
        return;
    }
    externalTime = normalizedTime;
    normalizedTime = (std::max)(0.0f, (std::min)(0.99f, normalizedTime));
    SimpleServices().SetExternalAnimationTime(*this, normalizedTime);
}

// Retail: 0x82BFEAF0 ?Event_PauseAnim@idAnimatedSimple@@...
eventVoid idAnimatedSimple::Event_PauseAnim(const bool pause,
        const int frame, const bool queuePause_) {
    PauseCurrentAnim(pause, frame, queuePause_);
    return {};
}

// Retail: 0x82BFEB38 ?DrawDebugGUI@idASDebugGUI@@QAAPAVidRenderModelGui@@XZ
idRenderModelGui* idASDebugGUI::DrawDebugGUI() {
    if (guiModel == nullptr) {
        guiModel = idAnimatedSimple::SimpleServices().CreateDebugGUI(*this);
    }
    return guiModel == nullptr || !hasFont ? nullptr
        : idAnimatedSimple::SimpleServices().DrawDebugGUI(*this, guiModel);
}

// Retail: 0x82BFEDE8 ?EnterState@idAnimatedSimple@@AAAXHH_N@Z
void idAnimatedSimple::EnterState(const int state,
        const int blendTime, const bool checkpoint) {
    if (state < 0 || state >= animList.Num()
            || !SimpleServices().HasTreeAnimator(*this)) {
        return;
    }
    animEntry_t& entry = animList[state];
    currentState = state;
    hasCheckedDefault = true;
    currentLoopCount = 0;
    ActivateList(*this, entry.triggerEnter);
    SimpleServices().SetupState(*this, state, checkpoint);
    animStartFrame = SimpleServices().GetGameFrame();
    if (!checkpoint && entry.animationHandle.IsValid()) {
        const int duration = blendTime == -1 ? entry.blendTime : blendTime;
        thinkFlags |= 7;
        SimpleServices().PlayAnimation(*this, entry.animationHandle,
            entry.loop, duration, entry.timeScale);
        if (entry.useTimeControl) {
            SetExternalTime(externalTime);
        }
    }
    SimpleServices().ComputeStateEndTransform(
        *this, state, nextOrigin, nextRotation);
}

// Retail: 0x82BFF680 ?SetAnimState@idAnimatedSimple@@QAAXHH_N0@Z
void idAnimatedSimple::SetAnimState(int state, const int blendTime,
        const bool queue, const bool checkpoint) {
    if (state != STATE_RANDOM && state < 0) {
        return;
    }
    if (animList.IsEmpty()) {
        return;
    }
    if (state == STATE_RANDOM) {
        state = SimpleServices().RandomInt(animList.Num());
        if (animList.Num() > 1 && state == currentState) {
            state = (state + 1) % animList.Num();
        }
    }
    if (state < 0 || state >= animList.Num()) {
        return;
    }
    if (queue && currentState != STATE_NONE) {
        queuedAnimState = state;
        queuedBlendTime = blendTime;
        return;
    }
    if (currentState == STATE_NONE) {
        SimpleServices().GetTransform(*this, applyAnimTransformLocal,
            orgOrigin, orgRotation);
    } else {
        LeaveState(currentState);
        orgOrigin = nextOrigin;
        orgRotation = nextRotation;
    }
    EnterState(state, blendTime, checkpoint);
}

// Retail: 0x82BFF888 ?SetAnimStateFromAnimAliasRef@idAnimatedSimple@@...
void idAnimatedSimple::SetAnimStateFromAnimAliasRef(
        const idAnimAliasRef& alias, const int blendTime, const bool queue) {
    for (int index = 0; index < animList.Num(); ++index) {
        if (animList[index].animation == alias) {
            SetAnimState(index, blendTime, queue, false);
            return;
        }
    }
}

// Retail: 0x82BFF910 ?GotoNextState@idAnimatedSimple@@QAAXH_N@Z
void idAnimatedSimple::GotoNextState(
        const int blendTime, const bool queue) {
    SetAnimState(currentState + 1, blendTime, queue, false);
}

// Retail: 0x82BFF928 ?GotoPrevState@idAnimatedSimple@@QAAXH_N@Z
void idAnimatedSimple::GotoPrevState(
        const int blendTime, const bool queue) {
    SetAnimState(currentState - 1, blendTime, queue, false);
}

// Retail: 0x82BFF940 ?Event_SetAnimState@idAnimatedSimple@@...
eventVoid idAnimatedSimple::Event_SetAnimState(const int state,
        const int blendTime, const bool queue) {
    SetAnimState(state, blendTime, queue, false);
    return {};
}

// Retail: 0x82BFF988 ?Show@idAnimatedSimple@@UAAXXZ
void idAnimatedSimple::Show() {
    SimpleServices().Hide(*this, false, true);
    SimpleServices().SetPhysicsContents(*this, physicsContent);
    SimpleServices().ShowAttachments(*this, true);
    if (!hasCheckedDefault) {
        hasCheckedDefault = true;
        for (int index = 0; index < animList.Num(); ++index) {
            if (animList[index].playDefault) {
                EnterState(index, -1, false);
                return;
            }
        }
    }
}

// Retail: 0x82BFFAB0 ?Think@idAnimatedSimple@@UAAXXZ
void idAnimatedSimple::Think() {
    if (!SimpleServices().HasTreeAnimator(*this)) {
        SimpleServices().SetThinkActive(*this, false);
        return;
    }
    if (!hasCheckedDefault && !SimpleServices().UseRelaxedChatter(*this)) {
        for (int index = 0; index < animList.Num(); ++index) {
            if (animList[index].playDefault) {
                EnterState(index, -1, false);
            }
        }
    }
    if (queuePause && SimpleServices().GetAnimationFrame(*this)
            == queuePauseFrame) {
        queuePauseFrame = -1;
        queuePause = false;
        PauseCurrentAnim(true, -1, false);
    }

    if (SimpleServices().IsChannelDone(*this)) {
        int jumpState = STATE_NONE;
        int transitionBlend = -1;
        bool hideWhenDone = false;
        const int completedState = currentState;
        if (currentState != STATE_NONE) {
            animEntry_t& entry = animList[currentState];
            jumpState = entry.jumpToState;
            hideWhenDone = entry.hideWhenDone;
            ActivateList(*this, entry.triggerAnimDone);
            LeaveState(currentState);
            currentState = STATE_NONE;
            if (queuedAnimState != STATE_NONE) {
                jumpState = queuedAnimState;
                transitionBlend = queuedBlendTime;
                queuedAnimState = STATE_NONE;
                queuedBlendTime = -1;
            }
        }
        if (applyAnimTransform && !isPaused) {
            orgOrigin = nextOrigin;
            orgRotation = nextRotation;
            SimpleServices().SetTransform(*this, applyAnimTransformLocal,
                nextOrigin, nextRotation);
        }
        if (jumpState == STATE_NONE) {
            thinkFlags &= ~7;
            SimpleServices().SetThinkActive(*this, false);
            if (hideWhenDone) {
                Hide();
            }
        } else {
            if (jumpState == STATE_RANDOM) {
                jumpState = SimpleServices().RandomInt(animList.Num());
                if (animList.Num() > 1 && jumpState == completedState) {
                    jumpState = (jumpState + 1) % animList.Num();
                }
            }
            EnterState(jumpState, transitionBlend, false);
        }
    } else if (applyAnimTransform && !ignoreMovement
            && animUpdatedFrame > animStartFrame) {
        SimpleServices().ApplyAnimationMovement(*this);
        UpdateModelTransform();
    }

    if (currentState != STATE_NONE) {
        const int loopCount = SimpleServices().GetAnimationLoopCount(*this);
        if (loopCount != currentLoopCount) {
            animEntry_t& entry = animList[currentState];
            const bool trigger = entry.loopTriggerType == LOOP_TRIGGER_MULTIPLE
                ? entry.loopCountToTrigger > 0
                    && loopCount % entry.loopCountToTrigger == 0
                : loopCount == entry.loopCountToTrigger;
            currentLoopCount = loopCount;
            if (trigger) {
                ActivateList(*this, entry.triggerLoopCount);
            }
        }
    }
    if (facialOptions.useFaceManager) {
        SimpleServices().UpdateFace(*this);
    }
    idAnimatedEntity::Think();
    animUpdatedFrame = SimpleServices().GetGameFrame();
}

// Retail: 0x82C00680 ??0idAnimatedSimple@@QAA@XZ
idAnimatedSimple::idAnimatedSimple()
    : idAnimatedEntity()
    , hitDetectionOptions()
    , animList(16)
    , startingAttachments(16)
    , facialOptions()
    , displayName(-1)
    , noDeferredPosition(false)
    , sceneModel(false)
    , isOkWithoutModel(false)
    , ignoreMovement(false)
    , playerShouldLowerWeapon(false)
    , applyAnimTransformLocal(false)
    , applyAnimTransform(true)
    , orgRotation(0.0f, 0.0f, 0.0f, 1.0f)
    , orgOrigin(0.0f, 0.0f, 0.0f)
    , nextRotation(0.0f, 0.0f, 0.0f, 1.0f)
    , nextOrigin(0.0f, 0.0f, 0.0f)
    , prevTrans(0.0f, 0.0f, 0.0f)
    , externalTime(0.0f)
    , animStartFrame(-1)
    , animUpdatedFrame(-1)
    , physicsContent(0)
    , currentState(STATE_NONE)
    , queuedAnimState(STATE_NONE)
    , queuedBlendTime(-1)
    , currentLoopCount(0)
    , queuePauseFrame(-1)
    , queuePause(false)
    , wasLooping(false)
    , isPaused(false)
    , hasCheckedDefault(false) {
}

// Retail: 0x82C009E8 ??1idAnimatedSimple@@UAA@XZ
idAnimatedSimple::~idAnimatedSimple() {
    SimpleServices().Shutdown(*this);
}
