#include "game/entities/animated.h"

#include "idlib/lib_print.h"

#include <algorithm>

namespace {
idAnimatedServices defaultAnimatedServices;
idAnimatedServices* activeAnimatedServices = &defaultAnimatedServices;
}

void idAnimated::SetServices(idAnimatedServices* services) {
    activeAnimatedServices = services == nullptr
        ? &defaultAnimatedServices : services;
}

idAnimatedServices& idAnimated::Services() {
    return *activeAnimatedServices;
}

// EA 0x82BF63F0
void idAnimated::StartCurAnim() {
    if (curAnim < 0 || curAnim >= animations.Num()) return;
    anim_t& animation = animations[curAnim];
    if (!animation.animationHandle.IsValid()) {
        animation.animationHandle =
            Services().ResolveAlias(*this, animation.animation.c_str());
    }
    if (!animation.animationHandle.IsValid()) {
        idLibPrint::Warning(
            "idAnimated '%s' could not find animation alias '%s'",
            name.c_str(), animation.animation.c_str());
        return;
    }
    Services().PlayAnimation(*this, animation.animationHandle,
        animation.cycle, animation.blendDuration);
}

// EA 0x82BF6540
void idAnimated::OnActivate(idEntity*) {
    ++curAnim;
    if (curAnim >= animations.Num()) {
        if (loopAnimList && !animations.IsEmpty()) curAnim = 0;
        else {
            curAnim = animations.IsEmpty() ? 0 : animations.Num() - 1;
            Services().SetActive(*this, false, true);
            return;
        }
    }
    StartCurAnim();
}

// EA 0x82BF6590
eventVoid idAnimated::Event_Reset() {
    curAnim = 0;
    Services().SetActive(*this, true, false);
    return {};
}

// EA 0x82BF65D8
eventVoid idAnimated::AnimEvent_VoiceOver(
        const idMD6Anim*, const idDeclVoiceOver* voiceOver) {
    if (voiceOver == nullptr) {
        idLibPrint::Warning(
            "Invalid voice over decl specified for AnimEvent_VoiceOver");
        return {};
    }
    Services().StartVoiceOver(*this, voiceOver);
    return {};
}

// EA 0x82BF6670
idBinaryAnimation::idBinaryAnimation()
    : name(),
      animation(),
      animationHandle(),
      totalAnimMilliseconds(0),
      animStartMilliseconds(0),
      megaMorphTable(nullptr) {}

// EA 0x82BF6748
idBinaryAnimation::~idBinaryAnimation() {
    idAnimated::Services().ShutdownBinary(*this);
}

// EA 0x82BF67F8
void idBinaryAnimation::Think() {
    idAnimated::Services().UpdateBinaryAnimation(*this);
    const int elapsed = idAnimated::Services().GetGameMilliseconds()
        - animStartMilliseconds;
    const float fraction = totalAnimMilliseconds <= 0
        ? 1.0f
        : std::max(0.0f, std::min(1.0f,
            static_cast<float>(elapsed) / totalAnimMilliseconds));
    const float morph = megaMorphTable == nullptr
        ? fraction
        : idAnimated::Services().LookupMorph(megaMorphTable, fraction);
    idAnimated::Services().SetBinaryMorph(*this, morph);
    if (idAnimated::Services().IsBinaryAnimationDone(*this)) {
        idAnimated::Services().SetBinaryActive(*this, false);
    }
}

// EA 0x82BF6950
void idBinaryAnimation::OnActivate(idEntity*) {
    idAnimated::Services().PlayBinaryAnimation(*this, animationHandle);
    animStartMilliseconds = idAnimated::Services().GetGameMilliseconds();
    idAnimated::Services().SetBinaryActive(*this, true);
}

// EA 0x82BF6A18
void idAnimated::Spawn() {
    if (!Services().InitializeAnimated(*this)) {
        idLibPrint::Error("Invalid MD6 model on func/animated '%s'",
            name.c_str());
        return;
    }
    for (int index = 0; index < startingAttachments.Num(); ++index) {
        const attachment_t& attachment = startingAttachments[index];
        Services().AddStartingAttachment(*this, attachment.entityDef,
            attachment.md6, attachment.entityName.c_str(),
            attachment.lwoName.c_str(), attachment.tag.c_str());
    }
    for (int index = 0; index < animations.Num(); ++index) {
        animations[index].animationHandle = Services().ResolveAlias(
            *this, animations[index].animation.c_str());
    }
    curAnim = animations.IsEmpty() ? 0 : std::min(curAnim, animations.Num() - 1);
    StartCurAnim();
    Services().SetActive(*this, true, alwaysUpdate);

    // EA 0x82BF6D0C: the retail cleanup thunk released the temporary
    // animator-parameter name; automatic C++ storage owns that cleanup.
}

// EA 0x82BF6D38
void idAnimated::Think() {
    Services().UpdateAnimatedFrameCommands(*this);
    if (!animations.IsEmpty() && curAnim >= 0 && curAnim < animations.Num()
            && !animations[curAnim].cycle
            && Services().IsAnimationDone(*this)) {
        OnActivate(nullptr);
    }
    if (applyAnimDelta) {
        Services().ApplyAnimatedOriginDelta(*this);
    }
    Services().UpdateAnimatedFace(*this);
    Services().UpdateAnimatedAnimation(*this);
    Services().UpdateAnimatedVisuals(*this);
}

// EA 0x82BF7020
bool idBinaryAnimation::GetBinaryAnimationState(
        idTreeAnimator*& treeAnimator, idStr& animationName) {
    if (!idAnimated::Services().HasBinaryRenderModel(*this)) return false;
    treeAnimator = idAnimated::Services().GetBinaryTreeAnimator(*this);
    animationName = animation;
    return true;
}

// EA 0x82BF70C0
void idBinaryAnimation::Spawn() {
    if (!idAnimated::Services().InitializeBinary(*this)) {
        idLibPrint::Error(
            "Invalid MD6 model on func/binaryAnimation '%s'", name.c_str());
        return;
    }
    animationHandle =
        idAnimated::Services().ResolveBinaryAlias(*this, animation.c_str());
    if (!animationHandle.IsValid()) {
        const char* firstAlias =
            idAnimated::Services().FirstBinaryAlias(*this);
        if (firstAlias == nullptr) {
            idLibPrint::Error(
                "Invalid animation on func/binaryAnimation '%s'",
                name.c_str());
            return;
        }
        animation = firstAlias;
        animationHandle =
            idAnimated::Services().ResolveBinaryAlias(*this, firstAlias);
    }
    totalAnimMilliseconds = std::max(1,
        idAnimated::Services().GetBinaryAnimationDuration(
            *this, animationHandle));
    idAnimated::Services().SetBinaryFrameZero(*this, animationHandle);

    // EA 0x82BF72AC: temporary animator-parameter cleanup is represented by
    // automatic storage in the recovered implementation.
}

// EA 0x82BF7370
idAnimated::idAnimated()
    : name(),
      animations(0),
      startingAttachments(0),
      alwaysUpdate(false),
      applyAnimDelta(true),
      loopAnimList(true),
      curAnim(0) {}

// EA 0x82BF7500
idAnimated::~idAnimated() {
    Services().ShutdownAnimated(*this);
    animations.Clear();
    startingAttachments.Clear();
}
