#pragma once

#include "game/entities/animatedentity.h"

class idCrosshairInfo;
class idFocusTrace;

enum usableState_t : int;

enum idAnimatedInteractableJobStatus : int {
    INTERACTABLE_JOB_ACCEPTED = 0,
    INTERACTABLE_JOB_COMPLETED = 1
};

class idAnimatedInteractable;

class idAnimatedInteractableServices {
public:
    virtual ~idAnimatedInteractableServices() = default;
    virtual bool IsPlayer(const idEntity*) const { return false; }
    virtual bool GetJobStatus(const idEntity*, const char*, int&) const {
        return false;
    }
    virtual void SetCrosshair(idCrosshairInfo&, int, bool) const {}
    virtual bool HasTreeAnimator(const idAnimatedInteractable&) const {
        return false;
    }
    virtual bool IsAnimationDone(const idAnimatedInteractable&) const {
        return true;
    }
    virtual bool PlayAnimation(idAnimatedInteractable&,
        idAnimAliasHandle) { return false; }
    virtual void SetThinkActive(idAnimatedInteractable&, bool) {}
    virtual void UpdateVisuals(idAnimatedInteractable&) {}
    virtual void ActivateTargets(
        idAnimatedInteractable&, idEntity*) {}
    virtual void Spawn(idAnimatedInteractable&) {}
};

class idAnimatedInteractable : public idAnimatedEntity {
public:
    idAnimatedInteractable();

    static void SetInteractableServices(
        idAnimatedInteractableServices* services);
    static idAnimatedInteractableServices& InteractableServices();

    bool IsAnimating() const override;
    virtual bool IsEverUsable(const idEntity* activator) const;
    virtual usableState_t GetUsableState(
        const idEntity* activator, const idFocusTrace*) const;
    virtual bool ModifyCrosshairInfo(const idEntity* activator,
        const idFocusTrace*, usableState_t, idCrosshairInfo& info) const;
    void Think() override;
    virtual void Fire();
    void Spawn();
    virtual bool Use(idEntity* activator, usableState_t usable);

    idEntity* usedByEntity;
    idAnimAliasHandle onAnim;
    idAnimAliasHandle offAnim;
    idStr availableJobDecl;
    int availableJobStatus;
    idStr notAvailableJobDecl;
    int notAvailableJobStatus;
    int displayText;
    bool isOn;
    bool playing;
};
