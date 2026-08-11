#include "game/entities/animatedinteractable.h"

#include "game/player/crosshairinfo.h"

namespace {
idAnimatedInteractableServices defaultInteractableServices;
idAnimatedInteractableServices* interactableServices =
    &defaultInteractableServices;
}

void idAnimatedInteractable::SetInteractableServices(
        idAnimatedInteractableServices* const services) {
    interactableServices = services == nullptr
        ? &defaultInteractableServices : services;
}

idAnimatedInteractableServices&
idAnimatedInteractable::InteractableServices() {
    return *interactableServices;
}

// Retail: 0x82BFC1B8 ?IsAnimating@idAnimatedInteractable@@UBA_NXZ
bool idAnimatedInteractable::IsAnimating() const {
    return playing;
}

// Retail: 0x82BFC1C0 ?IsEverUsable@idAnimatedInteractable@@...
bool idAnimatedInteractable::IsEverUsable(
        const idEntity* const activator) const {
    if (activator == nullptr || playing) {
        return false;
    }
    return !isOn || offAnim.IsValid();
}

// Retail: 0x82BFC200 ?GetUsableState@idAnimatedInteractable@@...
usableState_t idAnimatedInteractable::GetUsableState(
        const idEntity* const activator, const idFocusTrace*) const {
    if ((!availableJobDecl.IsEmpty() || !notAvailableJobDecl.IsEmpty())
            && !InteractableServices().IsPlayer(activator)) {
        return USABLE_NOT_USABLE;
    }
    return USABLE_PROP;
}

// Retail: 0x82BFC268 ?ModifyCrosshairInfo@idAnimatedInteractable@@...
bool idAnimatedInteractable::ModifyCrosshairInfo(
        const idEntity* const activator, const idFocusTrace*,
        const usableState_t, idCrosshairInfo& info) const {
    if (!InteractableServices().IsPlayer(activator)) {
        return true;
    }
    bool available = true;
    if (!availableJobDecl.IsEmpty()) {
        int status = 0;
        available = InteractableServices().GetJobStatus(
            activator, availableJobDecl.c_str(), status)
            && status >= availableJobStatus;
    }
    bool notBlocked = true;
    if (available && !notAvailableJobDecl.IsEmpty()) {
        int status = 0;
        notBlocked = !InteractableServices().GetJobStatus(
            activator, notAvailableJobDecl.c_str(), status)
            || status < notAvailableJobStatus;
    }
    const bool usable = available && notBlocked;
    InteractableServices().SetCrosshair(info, displayText, !usable);
    return usable;
}

// Retail: 0x82BFC380 ?Think@idAnimatedInteractable@@UAAXXZ
void idAnimatedInteractable::Think() {
    if (!InteractableServices().HasTreeAnimator(*this)) {
        return;
    }
    UpdateFrameCommands();
    UpdateAnimation(false);
    if (playing && InteractableServices().IsAnimationDone(*this)) {
        playing = false;
        isOn = !isOn;
        Fire();
    }
    InteractableServices().UpdateVisuals(*this);
}

// Retail: 0x82BFC480 ??0idAnimatedInteractable@@QAA@XZ
idAnimatedInteractable::idAnimatedInteractable()
    : idAnimatedEntity()
    , usedByEntity(nullptr)
    , onAnim()
    , offAnim()
    , availableJobDecl()
    , availableJobStatus(INTERACTABLE_JOB_ACCEPTED)
    , notAvailableJobDecl()
    , notAvailableJobStatus(INTERACTABLE_JOB_COMPLETED)
    , displayText(-1)
    , isOn(false)
    , playing(false) {
}

// Retail: 0x82BFC6D8 ?Fire@idAnimatedInteractable@@UAAXXZ
void idAnimatedInteractable::Fire() {
    InteractableServices().ActivateTargets(*this, usedByEntity);
    InteractableServices().SetThinkActive(*this, false);
}

// Retail: 0x82BFC778 ?Spawn@idAnimatedInteractable@@QAAXXZ
void idAnimatedInteractable::Spawn() {
    InteractableServices().Spawn(*this);
    thinkFlags |= TH_ANIMATE;
    UpdateAnimation(false);
    thinkFlags &= ~TH_ANIMATE;
}

// Retail: 0x82BFC8E8 ?Use@idAnimatedInteractable@@UAA_N...
bool idAnimatedInteractable::Use(
        idEntity* const activator, const usableState_t) {
    if (!InteractableServices().HasTreeAnimator(*this)) {
        return false;
    }
    usedByEntity = activator;
    const idAnimAliasHandle selected = isOn ? offAnim : onAnim;
    if (InteractableServices().PlayAnimation(*this, selected)) {
        thinkFlags |= TH_ANIMATE;
        playing = true;
        InteractableServices().SetThinkActive(*this, true);
    } else {
        Fire();
    }
    return true;
}
