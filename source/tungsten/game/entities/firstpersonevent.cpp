#include "game/entities/firstpersonevent.h"

#include <algorithm>

namespace {
constexpr int FIRST_PERSON_USABLE_PROP = 3;
constexpr int FIRST_PERSON_HAND_HIDE_REASON = 0x40;
constexpr int FIRST_PERSON_INHIBIT_NONE = 0;
constexpr int FIRST_PERSON_INHIBIT_MOVEMENT = 1;

idFirstPersonEventServices defaultFirstPersonEventServices;
idFirstPersonEventServices* firstPersonEventServices =
    &defaultFirstPersonEventServices;
unsigned int firstPersonRandomSeed = 0x13579BDFu;

idVec3 ZeroVector() {
    return idVec3(0.0f, 0.0f, 0.0f);
}

idMat3 IdentityMatrix() {
    return idMat3(1.0f);
}

bool ValidAnimation(const idFirstPersonAnimHandle handle) {
    return handle != INVALID_FIRST_PERSON_ANIM;
}
} // namespace

int idFirstPersonEventServices::GetGameMilliseconds() const {
    return idEntity::Services().GetGameMilliseconds();
}

int idFirstPersonEventServices::GetGameFrame() const {
    const int frameMilliseconds =
        (std::max)(idEntity::Services().GetGameMillisecondsPerFrame(), 1);
    return GetGameMilliseconds() / frameMilliseconds;
}

int idFirstPersonEventServices::RandomInt(const int maximum) {
    if (maximum <= 0) {
        return 0;
    }
    firstPersonRandomSeed =
        1664525u * firstPersonRandomSeed + 1013904223u;
    return static_cast<int>((firstPersonRandomSeed >> 8)
        % static_cast<unsigned int>(maximum));
}

idEntity* idFirstPersonEventServices::GetPrimaryPlayer() const {
    return nullptr;
}

bool idFirstPersonEventServices::IsPlayer(const idEntity*) const {
    return false;
}

idEntity* idFirstPersonEventServices::GetPlayerLegs(idEntity*) const {
    return nullptr;
}

idEntity* idFirstPersonEventServices::GetPlayerHands(idEntity*) const {
    return nullptr;
}

void idFirstPersonEventServices::SetEventContents(
        idFirstPersonEvent& event, const int contents) {
    event.contents = contents;
}

void idFirstPersonEventServices::QueuePostSpawn(idFirstPersonEvent& event) {
    event.Event_PostSpawn();
}

idFirstPersonAnimHandle
idFirstPersonEventServices::ResolveAnimationAlias(
        idEntity*, const char*) const {
    return INVALID_FIRST_PERSON_ANIM;
}

bool idFirstPersonEventServices::GetAnimationMotion(idEntity*,
        idFirstPersonAnimHandle, idVec3&, idMat3&, idVec3&, idMat3&,
        idVec3&, idMat3&) const {
    return false;
}

bool idFirstPersonEventServices::ComputePickupTransform(idEntity*,
        idFirstPersonAnimHandle, const char*, idEntity*, bool,
        idVec3&, idMat3&) const {
    return false;
}

void idFirstPersonEventServices::EndPlayerBehaviors(idEntity*) {}

void idFirstPersonEventServices::TeleportPlayer(idEntity* player,
        const idVec3& newOrigin, const idMat3& newAxis) {
    if (player != nullptr) {
        player->origin = newOrigin;
        player->axis = newAxis;
    }
}

void idFirstPersonEventServices::SetPlayerCrouch(idEntity*, bool) {}
void idFirstPersonEventServices::ForcePlayerPhysicsQuery(idEntity*) {}
void idFirstPersonEventServices::SetPlayerCrouchTransition(
    idEntity*, bool) {}
void idFirstPersonEventServices::SetCameraBlendDuration(
    idEntity*, int) {}
void idFirstPersonEventServices::SetSpringCameraFov(
    idEntity*, const char*) {}
void idFirstPersonEventServices::SetSpringCameraCalculateInDraw(
    idEntity*, bool) {}

int idFirstPersonEventServices::GetPlayerShowFlags(idEntity*) const {
    return 0;
}

void idFirstPersonEventServices::HidePlayerHands(idEntity*, int) {}
void idFirstPersonEventServices::ShowPlayerHands(idEntity*, int) {}

int idFirstPersonEventServices::GetPlayerInputInhibitFlags(
        idEntity*) const {
    return FIRST_PERSON_INHIBIT_NONE;
}

void idFirstPersonEventServices::SetPlayerInputInhibitFlags(
    idEntity*, int) {}

bool idFirstPersonEventServices::IsPlayerButtonPressed(
        idEntity*, int) const {
    return false;
}

void idFirstPersonEventServices::GetPlayerMove(
        idEntity*, int& forward, int& right) const {
    forward = 0;
    right = 0;
}

bool idFirstPersonEventServices::GetPlayerViewTransform(
        idEntity* player, idVec3& viewOrigin, idMat3& viewAxis) const {
    return GetEntityTransform(player, viewOrigin, viewAxis);
}

void idFirstPersonEventServices::StartPlayerPerfectOrigin(
    idEntity*, const idVec3&, int) {}
void idFirstPersonEventServices::MarkPlayerPerfectOrigin(idEntity*) {}

bool idFirstPersonEventServices::GetEntityTransform(const idEntity* entity,
        idVec3& transformOrigin, idMat3& transformAxis) const {
    if (entity == nullptr) {
        return false;
    }
    transformOrigin = entity->origin;
    transformAxis = entity->axis;
    return true;
}

void idFirstPersonEventServices::SetAlignedTransform(idEntity* entity,
        const idVec3& transformOrigin, const idMat3& transformAxis, bool) {
    if (entity != nullptr) {
        entity->origin = transformOrigin;
        entity->axis = transformAxis;
    }
}

bool idFirstPersonEventServices::IsAlignedBound(
        const idEntity* entity) const {
    return entity != nullptr && entity->IsBound();
}

void idFirstPersonEventServices::BindAligned(idEntity* entity,
        idEntity* parent, const idAngles&, const char* jointName,
        const char* tagName, idVec3& resultingOrigin,
        idMat3& resultingAxis) {
    if (entity == nullptr || parent == nullptr) {
        return;
    }
    if (tagName != nullptr && tagName[0] != '\0') {
        entity->BindToTag(parent, tagName, true);
    } else if (jointName != nullptr && jointName[0] != '\0') {
        entity->BindToJoint(parent, jointName, nullptr, true);
    } else {
        entity->Bind(parent, true);
    }
    resultingOrigin = entity->origin;
    resultingAxis = entity->axis;
}

void idFirstPersonEventServices::UnbindAligned(idEntity* entity) {
    if (entity != nullptr) {
        entity->Unbind();
    }
}

void idFirstPersonEventServices::SetAlignedDeferredPosition(
    idEntity*, bool) {}
void idFirstPersonEventServices::SetAlignedVisible(idEntity*, bool) {}

bool idFirstPersonEventServices::GetRemoveOriginTranslation(
        const idEntity*) const {
    return true;
}

void idFirstPersonEventServices::SetRemoveOriginRotation(
    idEntity*, bool) {}
void idFirstPersonEventServices::PlayAnimation(idEntity*,
    idFirstPersonAnimHandle, bool, int, float) {}
void idFirstPersonEventServices::StopAnimation(idEntity*) {}

bool idFirstPersonEventServices::IsAnimationDone(
        idEntity*, int) const {
    return false;
}

bool idFirstPersonEventServices::GetTotalOriginTransform(idEntity*,
        idVec3&, idMat3&, int&) const {
    return false;
}

bool idFirstPersonEventServices::GetWorldJointTransform(idEntity*,
        const char*, idVec3&, idMat3&) const {
    return false;
}

void idFirstPersonEventServices::ForceNonDeferredAnimationUpdate(
    idEntity*) {}
void idFirstPersonEventServices::AttachCamera(
    idEntity*, const char*, bool, int) {}
void idFirstPersonEventServices::DetachCamera(idEntity*, bool) {}
void idFirstPersonEventServices::SetExternalTime(idEntity*, float) {}
void idFirstPersonEventServices::AttachEntity(
    idEntity*, idEntity*, const char*) {}
void idFirstPersonEventServices::AttachToOwner(idEntity*, int) {}
void idFirstPersonEventServices::UpdateOwnerFromCamera(idEntity*, bool) {}
void idFirstPersonEventServices::DetachFromOwner(
    idEntity*, int, const idVec3&, const idMat3&) {}
void idFirstPersonEventServices::SetManualCameraUpdate(
    idEntity*, bool) {}
void idFirstPersonEventServices::SetAlignedModelVisible(
    idEntity*, bool) {}

bool idFirstPersonEventServices::CanPickupItem(
        const idEntity* item) const {
    return item != nullptr;
}

void idFirstPersonEventServices::AttachItem(
    idEntity*, idEntity*, const char*) {}
void idFirstPersonEventServices::GiveItemToPlayer(
    idEntity*, idEntity*) {}

void idFirstPersonEventServices::HideAndRemoveItem(idEntity* item) {
    if (item != nullptr) {
        item->Hide();
        item->Remove();
    }
}

void idFirstPersonEventServices::ShowItem(idEntity* item) {
    if (item != nullptr) {
        item->Show();
    }
}

void idFirstPersonEventServices::ActivateTrigger(
        idEntity* trigger, idEntity* activator) {
    if (trigger != nullptr) {
        trigger->Activate(activator);
    }
}

void idFirstPersonEventServices::Warn(const char*) {}

idFirstPersonEvent::bindInfo_t::bindInfo_t()
    : bindParent(nullptr),
      bindOffset(0.0f, 0.0f, 0.0f) {
}

idFirstPersonEvent::animEntry_t::animEntry_t()
    : legsAnimationHandle(INVALID_FIRST_PERSON_ANIM),
      handsAnimationHandle(INVALID_FIRST_PERSON_ANIM),
      stateStarted(0),
      triggerEnter(nullptr),
      triggerLeave(nullptr),
      exitCondition(EXITCONDITION_NONE),
      exitConditionMoveType(EXITCONDITION_MOVETYPE_NONE),
      exitConditionButton(0),
      timeScale(1.0f),
      exitParameters(0),
      exitStateSucceded(-1),
      exitStateFailed(-1),
      maxLoopTime(0),
      blendTime(0),
      useTimeControl(false),
      loop(false) {
}

// Retail: 0x82C4F908 ??0idFirstPersonEvent@@QAA@XZ
idFirstPersonEvent::idFirstPersonEvent()
    : idEntity(),
      extraAnimations(0),
      perfectOriginRef(nullptr),
      perfectDestinationRef(nullptr),
      triggerEnter(0),
      triggerLeave(0),
      cameraJoint("camera"),
      playerEndOffset(ZeroVector()),
      attachMode(ATTACHMODE_LEGS),
      blendInTime(500),
      blendOutTime(500),
      cameraBlendOutTime(-1),
      makePlayerFollowAlong(false),
      shouldEndInCrouch(false),
      forceActivateOnPlayer(false),
      useAnimationEndPos(true),
      useAnimationOrigin(false),
      legsEntity(nullptr),
      handsEntity(nullptr),
      playerActivator(nullptr),
      orgPosLegs(ZeroVector()),
      orgAxisLegs(IdentityMatrix()),
      orgPosHands(ZeroVector()),
      orgAxisHands(IdentityMatrix()),
      nextPosLegs(ZeroVector()),
      nextRotLegs(IdentityMatrix()),
      nextPosHands(ZeroVector()),
      nextRotHands(IdentityMatrix()),
      playerEndPos(ZeroVector()),
      playerEndRot(IdentityMatrix()),
      legsAnimationHandle(INVALID_FIRST_PERSON_ANIM),
      handsAnimationHandle(INVALID_FIRST_PERSON_ANIM),
      animStartFrame(-1),
      eventStartTime(-1),
      eventEndTime(-1),
      curExtraAnimation(-1),
      externalTime(0.0f),
      playerShowFlags(FIRST_PERSON_HAND_HIDE_REASON),
      playerSavedInhibitFlags(FIRST_PERSON_INHIBIT_NONE),
      removeOriginTransformLegs(true),
      removeOriginTransformHands(true),
      applyMovement(false) {
}

void idFirstPersonEvent::SetServices(idFirstPersonEventServices* services) {
    firstPersonEventServices = services != nullptr ? services
        : &defaultFirstPersonEventServices;
}

idFirstPersonEventServices& idFirstPersonEvent::Services() {
    return *firstPersonEventServices;
}

// Retail: 0x82C4B298 ?Spawn@idFirstPersonEvent@@QAAXXZ
void idFirstPersonEvent::Spawn() {
    Services().SetEventContents(*this, 0);
    if (cameraBlendOutTime == -1) {
        cameraBlendOutTime = blendOutTime;
    }
    Services().QueuePostSpawn(*this);
}

// Retail: 0x82C4B448 ?Event_PostSpawn@idFirstPersonEvent@@QAA?AVeventVoid@@XZ
void idFirstPersonEvent::Event_PostSpawn() {
    idEntity* const player = Services().GetPrimaryPlayer();
    if (player == nullptr) {
        return;
    }

    idEntity* const legs = Services().GetPlayerLegs(player);
    idEntity* const hands = Services().GetPlayerHands(player);
    for (int index = 0; index < extraAnimations.Num(); ++index) {
        animEntry_t& animation = extraAnimations[index];
        if (!animation.legsAnimation.IsEmpty() && legs != nullptr) {
            animation.legsAnimationHandle =
                Services().ResolveAnimationAlias(
                    legs, animation.legsAnimation.c_str());
        }
        if (!animation.handsAnimation.IsEmpty() && hands != nullptr) {
            animation.handsAnimationHandle =
                Services().ResolveAnimationAlias(
                    hands, animation.handsAnimation.c_str());
        }
    }
    if (!legsAnimation.IsEmpty() && legs != nullptr) {
        legsAnimationHandle = Services().ResolveAnimationAlias(
            legs, legsAnimation.c_str());
    }
    if (!handsAnimation.IsEmpty() && hands != nullptr) {
        handsAnimationHandle = Services().ResolveAnimationAlias(
            hands, handsAnimation.c_str());
    }
}

// Retail: 0x82C4B5A0 ??0idUseFirstPersonEvent@@QAA@XZ
idUseFirstPersonEvent::idUseFirstPersonEvent()
    : idEntity(), additionalPickup(false), additionalPickupState(0) {
}

// Retail: 0x82C4B5E8 ?Use@idUseFirstPersonEvent@@UAA_NPAVidEntity@@W4usableState_t@@@Z
bool idUseFirstPersonEvent::Use(idEntity* user, const int usableState) {
    if (!flags.isActivatable || usableState != FIRST_PERSON_USABLE_PROP) {
        return false;
    }
    idEntity::Use(user, FIRST_PERSON_USABLE_PROP);
    ActivateTargets(this);
    Event_NotifyProgressionOwner();
    return true;
}

// Retail: 0x82C4B678 ?StartEndEvent@idFirstPersonEvent@@IAAXXZ
void idFirstPersonEvent::StartEndEvent() {
    eventEndTime = Services().GetGameMilliseconds();
    if (playerActivator != nullptr) {
        const idVec3 destination =
            playerEndPos + playerEndRot * playerEndOffset;
        Services().TeleportPlayer(
            playerActivator, destination, playerEndRot);
        Services().SetPlayerCrouch(
            playerActivator, shouldEndInCrouch);
        Services().ForcePlayerPhysicsQuery(playerActivator);
        Services().SetPlayerCrouchTransition(
            playerActivator, shouldEndInCrouch);
        Services().SetCameraBlendDuration(
            playerActivator, cameraBlendOutTime);
    }

    idEntity* const attached = GetAttachedEntity();
    if (attached != nullptr) {
        Services().DetachCamera(attached, cameraBlendOutTime == 0);
    }
}

// Retail: 0x82C4B928 ?GetAnimTotalMovement@idFirstPersonEvent@@ABAXPBVidTreeAnimator@@V?$idHandle@GW4invalidAliasHandle_t@@$0PPPP@@@AAVidVec3@@AAVidMat3@@23@Z
void idFirstPersonEvent::GetAnimTotalMovement(idEntity* alignedEntity,
        const idFirstPersonAnimHandle animHandle, idVec3& startOrigin,
        idMat3& startAxis, idVec3& endOrigin, idMat3& endAxis) const {
    if (alignedEntity == nullptr || !ValidAnimation(animHandle)) {
        return;
    }

    idVec3 animationOrigin = ZeroVector();
    idMat3 animationAxis = IdentityMatrix();
    idVec3 firstOrigin = ZeroVector();
    idMat3 firstAxis = IdentityMatrix();
    idVec3 lastOrigin = ZeroVector();
    idMat3 lastAxis = IdentityMatrix();
    if (!Services().GetAnimationMotion(alignedEntity, animHandle,
            animationOrigin, animationAxis, firstOrigin, firstAxis,
            lastOrigin, lastAxis)) {
        return;
    }

    if (useAnimationOrigin) {
        startOrigin = animationOrigin;
        startAxis = animationAxis;
    }

    const idVec3 deltaOrigin = lastOrigin - firstOrigin;
    const idMat3 deltaAxis = firstAxis.Transpose() * lastAxis;
    endOrigin = startOrigin + startAxis * deltaOrigin;
    endAxis = startAxis * deltaAxis;
}

// Retail: 0x82C4C518 ?Event_AttachEntity@idFirstPersonEvent@@QAA?AVeventVoid@@PAVidEntity@@PBD@Z
void idFirstPersonEvent::Event_AttachEntity(
        idEntity* entity, const char* tag) {
    if (entity == nullptr) {
        Services().Warn("Event_AttachEntity: Tried to attach NULL");
        return;
    }
    if (handsEntity == nullptr) {
        Services().Warn("Event_AttachEntity: Hands not valid");
        return;
    }
    Services().AttachEntity(handsEntity, entity,
        tag != nullptr ? tag : "");
}

// Retail: 0x82C4C5D0 ?EndEvent@idFirstPersonEvent@@IAAXXZ
void idFirstPersonEvent::EndEvent() {
    BecomeInactive(1);
    eventStartTime = -1;
    eventEndTime = -1;

    if (playerActivator != nullptr) {
        Services().ShowPlayerHands(playerActivator, playerShowFlags);
        Services().SetPlayerInputInhibitFlags(
            playerActivator, playerSavedInhibitFlags);
        Services().SetSpringCameraCalculateInDraw(
            playerActivator, false);
    }
    if (legsEntity != nullptr) {
        Services().UnbindAligned(legsEntity);
        Services().SetAlignedDeferredPosition(legsEntity, true);
        Services().SetRemoveOriginRotation(
            legsEntity, removeOriginTransformLegs);
    }
    if (handsEntity != nullptr) {
        Services().UnbindAligned(handsEntity);
        Services().SetAlignedDeferredPosition(handsEntity, true);
        Services().SetRemoveOriginRotation(
            handsEntity, removeOriginTransformHands);
    }
    for (int index = 0; index < triggerLeave.Num(); ++index) {
        if (triggerLeave[index] != nullptr) {
            Services().ActivateTrigger(
                triggerLeave[index], playerActivator);
        }
    }
}

// Retail: 0x82C4CA60 ?SetCurrentState@idFirstPersonEvent@@IAAXH@Z
void idFirstPersonEvent::SetCurrentState(const int requestedState) {
    int nextState = requestedState;
    if (nextState == -1) {
        nextState = curExtraAnimation == -1 ? 0 : -1;
    }

    if (curExtraAnimation >= 0
            && curExtraAnimation < extraAnimations.Num()) {
        idEntity* const leave =
            extraAnimations[curExtraAnimation].triggerLeave;
        if (leave != nullptr) {
            Services().ActivateTrigger(leave, playerActivator);
        }
    }

    if (extraAnimations.Num() == 0
            || nextState < 0 || nextState >= extraAnimations.Num()) {
        StartEndEvent();
        return;
    }

    curExtraAnimation = nextState;
    animStartFrame = Services().GetGameFrame() + 1;
    animEntry_t& animation = extraAnimations[curExtraAnimation];
    animation.stateStarted = Services().GetGameMilliseconds();
    if (animation.triggerEnter != nullptr) {
        Services().ActivateTrigger(
            animation.triggerEnter, playerActivator);
    }

    if (ValidAnimation(animation.legsAnimationHandle)
            && legsEntity != nullptr) {
        orgPosLegs = nextPosLegs;
        orgAxisLegs = nextRotLegs;
        GetAnimTotalMovement(legsEntity,
            animation.legsAnimationHandle, orgPosLegs, orgAxisLegs,
            nextPosLegs, nextRotLegs);
        Services().PlayAnimation(legsEntity,
            animation.legsAnimationHandle, animation.loop,
            animation.blendTime, animation.timeScale);
        Services().SetAlignedTransform(legsEntity,
            orgPosLegs, orgAxisLegs,
            Services().IsAlignedBound(legsEntity));
    }
    if (ValidAnimation(animation.handsAnimationHandle)
            && handsEntity != nullptr) {
        orgPosHands = nextPosHands;
        orgAxisHands = nextRotHands;
        GetAnimTotalMovement(handsEntity,
            animation.handsAnimationHandle, orgPosHands, orgAxisHands,
            nextPosHands, nextRotHands);
        Services().PlayAnimation(handsEntity,
            animation.handsAnimationHandle, animation.loop,
            animation.blendTime, animation.timeScale);
        Services().SetAlignedTransform(handsEntity,
            orgPosHands, orgAxisHands,
            Services().IsAlignedBound(handsEntity));
    }

    if (perfectDestinationRef == nullptr || useAnimationEndPos) {
        if (attachMode == ATTACHMODE_LEGS) {
            playerEndPos = nextPosLegs;
            playerEndRot = nextRotLegs;
        } else if (attachMode == ATTACHMODE_HANDS) {
            playerEndPos = nextPosHands;
            playerEndRot = nextRotHands;
        }
    }
}

// Retail: 0x82C4D0A8 ?SetExternalTime@idFirstPersonEvent@@QAAXM@Z
void idFirstPersonEvent::SetExternalTime(const float normalizedTime) {
    externalTime = normalizedTime;
    if (curExtraAnimation < 0
            || curExtraAnimation >= extraAnimations.Num()
            || !extraAnimations[curExtraAnimation].useTimeControl) {
        return;
    }
    if (legsEntity != nullptr) {
        Services().SetExternalTime(legsEntity, normalizedTime);
    }
    if (handsEntity != nullptr) {
        Services().SetExternalTime(handsEntity, normalizedTime);
    }
}

// Retail: 0x82C4D180 ?Event_ForceEndFirstPersonEvent@idFirstPersonEvent@@QAA?AVeventVoid@@XZ
void idFirstPersonEvent::Event_ForceEndFirstPersonEvent() {
    idEntity* const player = Services().GetPrimaryPlayer();
    if (player != nullptr) {
        idEntity* const legs = Services().GetPlayerLegs(player);
        idEntity* const hands = Services().GetPlayerHands(player);
        if (legs != nullptr) {
            Services().StopAnimation(legs);
        }
        if (hands != nullptr) {
            Services().StopAnimation(hands);
        }
    }
    StartEndEvent();
    if (eventEndTime != -1 && blendOutTime == 0) {
        EndEvent();
    }
}

// Retail: 0x82C4D208 ?Event_SetFirstPersonEventAnimState@idFirstPersonEvent@@QAA?AVeventVoid@@H@Z
void idFirstPersonEvent::Event_SetFirstPersonEventAnimState(
        const int state) {
    SetCurrentState(state);
}

// Retail: 0x82C4D240 ?UpdateAnimation@idFirstPersonEvent@@IAA_NXZ
bool idFirstPersonEvent::UpdateAnimation() {
    bool animationEnded = false;

    const auto updateAligned = [this, &animationEnded](
            idEntity* alignedEntity, const attachMode_t mode,
            const idVec3& startOrigin, const idMat3& startAxis) {
        if (alignedEntity == nullptr || eventEndTime != -1) {
            return;
        }
        if (Services().IsAnimationDone(alignedEntity, 4)) {
            if (attachMode == mode) {
                animationEnded = true;
            }
            return;
        }
        if (!applyMovement) {
            return;
        }
        idVec3 rootTranslation = ZeroVector();
        idMat3 rootRotation = IdentityMatrix();
        int lastBlendFrame = -1;
        if (Services().GetTotalOriginTransform(alignedEntity,
                rootTranslation, rootRotation, lastBlendFrame)
                && lastBlendFrame > animStartFrame) {
            const idVec3 currentOrigin =
                startOrigin + startAxis * rootTranslation;
            const idMat3 currentAxis =
                startAxis * rootRotation.Transpose();
            Services().SetAlignedTransform(alignedEntity,
                currentOrigin, currentAxis,
                Services().IsAlignedBound(alignedEntity));
        }
    };

    updateAligned(legsEntity, ATTACHMODE_LEGS,
        orgPosLegs, orgAxisLegs);
    updateAligned(handsEntity, ATTACHMODE_HANDS,
        orgPosHands, orgAxisHands);

    int exitState = -1;
    if (curExtraAnimation >= 0
            && curExtraAnimation < extraAnimations.Num()) {
        animEntry_t& animation = extraAnimations[curExtraAnimation];
        if (playerActivator != nullptr
                && animation.exitCondition != EXITCONDITION_NONE) {
            if (animationEnded) {
                exitState = animation.exitStateFailed;
            } else {
                bool conditionMet = false;
                if ((animation.exitCondition
                        & EXITCONDITION_BUTTONPRESS) != 0) {
                    conditionMet = Services().IsPlayerButtonPressed(
                        playerActivator, animation.exitConditionButton);
                }
                if ((animation.exitCondition
                        & EXITCONDITION_MOVEMENT) != 0) {
                    int forward = 0;
                    int right = 0;
                    Services().GetPlayerMove(
                        playerActivator, forward, right);
                    const int movement = animation.exitConditionMoveType;
                    conditionMet = conditionMet
                        || ((movement & EXITCONDITION_MOVETYPE_RIGHT) != 0
                            && right >= animation.exitParameters)
                        || ((movement & EXITCONDITION_MOVETYPE_LEFT) != 0
                            && -right >= animation.exitParameters)
                        || ((movement & EXITCONDITION_MOVETYPE_FORWARD) != 0
                            && forward >= animation.exitParameters)
                        || ((movement & EXITCONDITION_MOVETYPE_BACKWARD) != 0
                            && -forward >= animation.exitParameters);
                }
                if (conditionMet) {
                    animationEnded = true;
                    exitState = animation.exitStateSucceded;
                }
            }
        } else if (animation.loop) {
            if (animation.maxLoopTime > 0
                    && Services().GetGameMilliseconds()
                        - animation.stateStarted > animation.maxLoopTime) {
                animationEnded = true;
                exitState = animation.exitStateFailed;
            }
        } else if (animationEnded
                && animation.exitCondition == EXITCONDITION_NONE) {
            exitState = animation.exitStateSucceded;
        }
    }

    if (animationEnded) {
        SetCurrentState(exitState);
        return true;
    }

    if (makePlayerFollowAlong && playerActivator != nullptr
            && eventEndTime == -1) {
        idEntity* const attached = GetAttachedEntity();
        idVec3 jointOrigin = ZeroVector();
        idMat3 jointAxis = IdentityMatrix();
        if (attached != nullptr
                && Services().GetWorldJointTransform(attached, nullptr,
                    jointOrigin, jointAxis)) {
            Services().StartPlayerPerfectOrigin(
                playerActivator, jointOrigin, 0);
            Services().MarkPlayerPerfectOrigin(playerActivator);
        }
    }
    return false;
}

// Retail: 0x82C4DB60 ?OnActivate@idFirstPersonEvent@@UAAXPAVidEntity@@@Z
void idFirstPersonEvent::OnActivate(idEntity* activator) {
    idEntity* player = Services().IsPlayer(activator)
        ? activator : nullptr;
    if (player == nullptr && forceActivateOnPlayer) {
        player = Services().GetPrimaryPlayer();
    }
    if (player == nullptr) {
        return;
    }

    Services().EndPlayerBehaviors(player);
    playerActivator = player;
    BecomeActive(1);
    eventStartTime = Services().GetGameMilliseconds();
    animStartFrame = Services().GetGameFrame();
    eventEndTime = -1;
    curExtraAnimation = -1;
    applyMovement = extraAnimations.Num() == 0;
    legsEntity = Services().GetPlayerLegs(player);
    handsEntity = Services().GetPlayerHands(player);

    idVec3 initialOrigin = origin;
    idMat3 initialAxis = axis;
    Services().GetEntityTransform(this, initialOrigin, initialAxis);
    if (perfectOriginRef != nullptr) {
        Services().GetEntityTransform(
            perfectOriginRef, initialOrigin, initialAxis);
    }

    orgPosLegs = initialOrigin;
    orgAxisLegs = initialAxis;
    orgPosHands = initialOrigin;
    orgAxisHands = initialAxis;
    nextPosLegs = initialOrigin;
    nextRotLegs = initialAxis;
    nextPosHands = initialOrigin;
    nextRotHands = initialAxis;
    playerEndPos = initialOrigin;
    playerEndRot = initialAxis;

    bool hasPerfectDestination = false;
    if (perfectDestinationRef != nullptr) {
        hasPerfectDestination = Services().GetEntityTransform(
            perfectDestinationRef, playerEndPos, playerEndRot);
    }

    if (legsEntity != nullptr) {
        Services().SetAlignedVisible(legsEntity, false);
        removeOriginTransformLegs =
            Services().GetRemoveOriginTranslation(legsEntity);
        Services().SetRemoveOriginRotation(legsEntity, applyMovement);
    }
    if (handsEntity != nullptr) {
        Services().SetAlignedVisible(handsEntity, false);
        removeOriginTransformHands =
            Services().GetRemoveOriginTranslation(handsEntity);
        Services().SetRemoveOriginRotation(handsEntity, applyMovement);
    }

    idFirstPersonAnimHandle currentLegsHandle = legsAnimationHandle;
    idFirstPersonAnimHandle currentHandsHandle = handsAnimationHandle;
    if (!ValidAnimation(currentLegsHandle)
            && !ValidAnimation(currentHandsHandle)
            && extraAnimations.Num() != 0) {
        curExtraAnimation = 0;
        animEntry_t& firstAnimation = extraAnimations[0];
        currentLegsHandle = firstAnimation.legsAnimationHandle;
        currentHandsHandle = firstAnimation.handsAnimationHandle;
        firstAnimation.stateStarted = Services().GetGameMilliseconds();
        if (firstAnimation.triggerEnter != nullptr) {
            Services().ActivateTrigger(
                firstAnimation.triggerEnter, playerActivator);
        }
    }

    if (fpBindinfo.bindParent != nullptr) {
        if (legsEntity != nullptr) {
            Services().BindAligned(legsEntity, fpBindinfo.bindParent,
                fpBindinfo.bindOffset, fpBindinfo.bindToJoint.c_str(),
                fpBindinfo.bindToTag.c_str(), orgPosLegs, orgAxisLegs);
            Services().SetAlignedDeferredPosition(legsEntity, false);
        }
        if (handsEntity != nullptr) {
            Services().BindAligned(handsEntity, fpBindinfo.bindParent,
                fpBindinfo.bindOffset, fpBindinfo.bindToJoint.c_str(),
                fpBindinfo.bindToTag.c_str(), orgPosHands, orgAxisHands);
            Services().SetAlignedDeferredPosition(handsEntity, false);
        }
    }

    if (ValidAnimation(currentLegsHandle) && legsEntity != nullptr) {
        nextPosLegs = orgPosLegs;
        nextRotLegs = orgAxisLegs;
        GetAnimTotalMovement(legsEntity, currentLegsHandle,
            orgPosLegs, orgAxisLegs, nextPosLegs, nextRotLegs);
    }
    if (ValidAnimation(currentHandsHandle) && handsEntity != nullptr) {
        nextPosHands = orgPosHands;
        nextRotHands = orgAxisHands;
        GetAnimTotalMovement(handsEntity, currentHandsHandle,
            orgPosHands, orgAxisHands, nextPosHands, nextRotHands);
    }

    if (!hasPerfectDestination || useAnimationEndPos) {
        if (attachMode == ATTACHMODE_LEGS) {
            playerEndPos = nextPosLegs;
            playerEndRot = nextRotLegs;
        } else if (attachMode == ATTACHMODE_HANDS) {
            playerEndPos = nextPosHands;
            playerEndRot = nextRotHands;
        }
    }

    if (ValidAnimation(currentLegsHandle) && legsEntity != nullptr) {
        Services().PlayAnimation(
            legsEntity, currentLegsHandle, false, 0, 1.0f);
        Services().SetAlignedTransform(legsEntity,
            orgPosLegs, orgAxisLegs,
            Services().IsAlignedBound(legsEntity));
    }
    if (ValidAnimation(currentHandsHandle) && handsEntity != nullptr) {
        Services().PlayAnimation(
            handsEntity, currentHandsHandle, false, 0, 1.0f);
        Services().SetAlignedTransform(handsEntity,
            orgPosHands, orgAxisHands,
            Services().IsAlignedBound(handsEntity));
    }

    idEntity* const attached = GetAttachedEntity();
    if (attached != nullptr) {
        Services().ForceNonDeferredAnimationUpdate(attached);
        Services().AttachCamera(attached, cameraJoint.c_str(),
            true, blendInTime);
    }

    if (!fovUserChannel.IsEmpty()) {
        Services().SetSpringCameraFov(
            player, fovUserChannel.c_str());
    }
    Services().SetSpringCameraCalculateInDraw(player, true);
    playerShowFlags =
        Services().GetPlayerShowFlags(player)
        | FIRST_PERSON_HAND_HIDE_REASON;
    Services().HidePlayerHands(
        player, FIRST_PERSON_HAND_HIDE_REASON);
    playerSavedInhibitFlags =
        Services().GetPlayerInputInhibitFlags(player);
    Services().SetPlayerInputInhibitFlags(
        player, FIRST_PERSON_INHIBIT_MOVEMENT);

    for (int index = 0; index < triggerEnter.Num(); ++index) {
        if (triggerEnter[index] != nullptr) {
            Services().ActivateTrigger(triggerEnter[index], player);
        }
    }
}

// Retail: 0x82C4EBC8 ?SetCurrentState@idFirstPersonEvent@@QAAXW4changeType_t@idTarget_ChangeAnimState@@H@Z
void idFirstPersonEvent::SetCurrentState(
        const changeType_t changeType, int nextState) {
    if (changeType > CHANGE_STOP) {
        return;
    }
    switch (changeType) {
        case CHANGE_NEXT:
            nextState = curExtraAnimation + 1;
            break;
        case CHANGE_PREVIOUS:
            nextState = curExtraAnimation > 0
                ? curExtraAnimation - 1 : 0;
            break;
        case CHANGE_SET:
            break;
        case CHANGE_RANDOM:
            if (extraAnimations.Num() <= 0) {
                nextState = -1;
                break;
            }
            nextState = Services().RandomInt(extraAnimations.Num());
            if (curExtraAnimation != -1
                    && nextState == curExtraAnimation) {
                nextState = (nextState + 1) % extraAnimations.Num();
            }
            break;
        case CHANGE_STOP:
            nextState = -1;
            break;
    }
    SetCurrentState(nextState);
}

idEntity* idFirstPersonEvent::GetAttachedEntity() const {
    if (attachMode == ATTACHMODE_LEGS) {
        return legsEntity;
    }
    if (attachMode == ATTACHMODE_HANDS) {
        return handsEntity;
    }
    return nullptr;
}

// Retail: 0x82C4F710 ?Think@idFirstPersonEvent@@UAAXXZ
void idFirstPersonEvent::Think() {
    if (eventStartTime == -1) {
        BecomeInactive(1);
        return;
    }

    const int gameTime = Services().GetGameMilliseconds();
    if (gameTime >= eventStartTime + blendInTime) {
        if (legsEntity != nullptr) {
            Services().SetAlignedVisible(legsEntity, true);
        }
        if (handsEntity != nullptr) {
            Services().SetAlignedVisible(handsEntity, true);
        }
    }

    if (eventEndTime != -1
            && gameTime >= eventEndTime + blendOutTime) {
        EndEvent();
        return;
    }
    UpdateAnimation();
    if (eventEndTime != -1 && blendOutTime == 0) {
        EndEvent();
    }
}

idFirstPersonPickup::additionalPickup_t::additionalPickup_t()
    : pickupItem(nullptr),
      animState(-1),
      removePickupItem(false),
      giveItemToPlayer(false),
      startOrigin(ZeroVector()),
      startAxis(IdentityMatrix()) {
}

// Retail: 0x82C4FF90 ??0idFirstPersonPickup@@QAA@XZ
idFirstPersonPickup::idFirstPersonPickup()
    : idFirstPersonEvent(),
      additionalPickups(0),
      pickupItem(nullptr),
      putdownItem(nullptr),
      pickupEndPosition(nullptr),
      endAnimState(-1),
      attachToPlayerBlend(500),
      removePickupItem(true),
      giveItemToPlayer(false),
      startOrigin(ZeroVector()),
      startAxis(IdentityMatrix()),
      endOrigin(ZeroVector()),
      endAxis(IdentityMatrix()),
      pickupState(PICKUPSTATE_NONE) {
}

// Retail: 0x82C4BC28 ?Event_PostSpawn@idFirstPersonPickup@@QAA?AVeventVoid@@XZ
void idFirstPersonPickup::Event_PostSpawn() {
    idFirstPersonEvent::Event_PostSpawn();
    idEntity* const player = Services().GetPrimaryPlayer();
    if (player == nullptr) {
        return;
    }
    idEntity* const aligned = attachMode == ATTACHMODE_LEGS
        ? Services().GetPlayerLegs(player)
        : attachMode == ATTACHMODE_HANDS
            ? Services().GetPlayerHands(player) : nullptr;
    if (aligned == nullptr) {
        return;
    }

    const idFirstPersonAnimHandle baseHandle =
        attachMode == ATTACHMODE_LEGS
            ? legsAnimationHandle : handsAnimationHandle;
    if (pickupItem != nullptr && ValidAnimation(baseHandle)) {
        Services().ComputePickupTransform(aligned, baseHandle,
            alignedJoint.c_str(), pickupItem, false,
            startOrigin, startAxis);
    }
    if (putdownItem != nullptr && endAnimState >= 0
            && endAnimState < extraAnimations.Num()) {
        const animEntry_t& animation = extraAnimations[endAnimState];
        const idFirstPersonAnimHandle handle =
            attachMode == ATTACHMODE_LEGS
                ? animation.legsAnimationHandle
                : animation.handsAnimationHandle;
        if (ValidAnimation(handle)) {
            Services().ComputePickupTransform(aligned, handle,
                alignedJoint.c_str(), putdownItem, true,
                endOrigin, endAxis);
        }
    }
    for (int index = 0; index < additionalPickups.Num(); ++index) {
        additionalPickup_t& pickup = additionalPickups[index];
        if (pickup.pickupItem == nullptr || pickup.animState < 0
                || pickup.animState >= extraAnimations.Num()) {
            continue;
        }
        const animEntry_t& animation = extraAnimations[pickup.animState];
        const idFirstPersonAnimHandle handle =
            attachMode == ATTACHMODE_LEGS
                ? animation.legsAnimationHandle
                : animation.handsAnimationHandle;
        if (ValidAnimation(handle)) {
            Services().ComputePickupTransform(aligned, handle,
                alignedJoint.c_str(), pickup.pickupItem, false,
                pickup.startOrigin, pickup.startAxis);
        }
    }
}

// Retail: 0x82C4ECA8 ?Think@idFirstPersonPickup@@UAAXXZ
void idFirstPersonPickup::Think() {
    if (UpdateAnimation()) {
        if (pickupState == PICKUPSTATE_PICKUP) {
            pickupState = PICKUPSTATE_WALKING;
            if (playerActivator != nullptr
                    && pickupEndPosition != nullptr) {
                idVec3 destination = ZeroVector();
                idMat3 destinationAxis = IdentityMatrix();
                if (Services().GetEntityTransform(pickupEndPosition,
                        destination, destinationAxis)) {
                    Services().TeleportPlayer(playerActivator,
                        destination, destinationAxis);
                }
            }
            if (playerActivator != nullptr) {
                Services().SetPlayerCrouch(
                    playerActivator, shouldEndInCrouch);
                Services().SetPlayerCrouchTransition(
                    playerActivator, shouldEndInCrouch);
                Services().SetPlayerInputInhibitFlags(
                    playerActivator, playerSavedInhibitFlags);
            }
            idEntity* const attached = GetAttachedEntity();
            if (attached != nullptr) {
                Services().AttachToOwner(attached, 0);
                Services().UpdateOwnerFromCamera(attached, true);
                Services().DetachCamera(attached, false);
            }
        } else if (pickupState == PICKUPSTATE_PUTDOWN) {
            if (putdownItem != nullptr) {
                Services().ShowItem(putdownItem);
            }
            if (handsEntity != nullptr) {
                Services().SetAlignedModelVisible(handsEntity, true);
            }
        }
    }

    if (eventEndTime != -1
            && Services().GetGameMilliseconds()
                >= eventEndTime + blendOutTime) {
        pickupState = PICKUPSTATE_NONE;
        if (handsEntity != nullptr) {
            Services().SetManualCameraUpdate(handsEntity, false);
        }
        EndEvent();
    }
}

// Retail: 0x82C4F050 ?OnActivate@idFirstPersonPickup@@UAAXPAVidEntity@@@Z
void idFirstPersonPickup::OnActivate(idEntity* activator) {
    idUseFirstPersonEvent* const useEvent =
        dynamic_cast<idUseFirstPersonEvent*>(activator);
    if (useEvent != nullptr && useEvent->additionalPickup
            && useEvent->additionalPickupState >= 0
            && useEvent->additionalPickupState
                < additionalPickups.Num()) {
        additionalPickup_t& pickup =
            additionalPickups[useEvent->additionalPickupState];
        if (pickup.animState >= 0
                && pickup.animState < extraAnimations.Num()) {
            pickupState = PICKUPSTATE_PICKUP;
            curExtraAnimation = pickup.animState;
            const animEntry_t& animation =
                extraAnimations[pickup.animState];
            const idFirstPersonAnimHandle handle =
                attachMode == ATTACHMODE_LEGS
                    ? animation.legsAnimationHandle
                    : animation.handsAnimationHandle;
            idEntity* const aligned = GetAttachedEntity();
            if (aligned != nullptr && pickup.pickupItem != nullptr
                    && playerActivator != nullptr) {
                Services().PlayAnimation(
                    aligned, handle, false, 0, 1.0f);
                Services().SetAlignedTransform(aligned,
                    pickup.startOrigin, pickup.startAxis, false);
                if (Services().CanPickupItem(pickup.pickupItem)) {
                    Services().AttachItem(aligned, pickup.pickupItem,
                        pickup.attachTag.c_str());
                    if (pickup.giveItemToPlayer) {
                        Services().GiveItemToPlayer(
                            playerActivator, pickup.pickupItem);
                    }
                }
                idVec3 viewOrigin = ZeroVector();
                idMat3 viewAxis = IdentityMatrix();
                Services().GetPlayerViewTransform(
                    playerActivator, viewOrigin, viewAxis);
                Services().DetachFromOwner(aligned,
                    attachToPlayerBlend, viewOrigin, viewAxis);
                Services().SetManualCameraUpdate(aligned, true);
                Services().AttachCamera(aligned,
                    cameraJoint.c_str(), false, 0);
                if (pickup.removePickupItem) {
                    Services().HideAndRemoveItem(pickup.pickupItem);
                }
            }
        }
    }

    if (pickupState == PICKUPSTATE_WALKING) {
        pickupState = PICKUPSTATE_PUTDOWN;
        if (playerActivator != nullptr && putdownItem != nullptr
                && endAnimState >= 0
                && endAnimState < extraAnimations.Num()) {
            curExtraAnimation = endAnimState;
            const animEntry_t& animation = extraAnimations[endAnimState];
            const idFirstPersonAnimHandle handle =
                attachMode == ATTACHMODE_LEGS
                    ? animation.legsAnimationHandle
                    : animation.handsAnimationHandle;
            idEntity* const aligned = GetAttachedEntity();
            Services().SetPlayerInputInhibitFlags(
                playerActivator, FIRST_PERSON_INHIBIT_MOVEMENT);
            if (aligned != nullptr) {
                Services().PlayAnimation(
                    aligned, handle, false, 0, 1.0f);
                Services().SetAlignedTransform(
                    aligned, endOrigin, endAxis, false);
                idVec3 viewOrigin = ZeroVector();
                idMat3 viewAxis = IdentityMatrix();
                Services().GetPlayerViewTransform(
                    playerActivator, viewOrigin, viewAxis);
                Services().DetachFromOwner(aligned,
                    attachToPlayerBlend, viewOrigin, viewAxis);
                Services().SetManualCameraUpdate(aligned, true);
                Services().AttachCamera(aligned,
                    cameraJoint.c_str(), false, 0);
            }
        }
    } else if (pickupState == PICKUPSTATE_NONE) {
        idFirstPersonEvent::OnActivate(activator);
        pickupState = PICKUPSTATE_PICKUP;
        applyMovement = false;
        if (handsEntity != nullptr && pickupItem != nullptr
                && playerActivator != nullptr) {
            Services().SetAlignedTransform(
                handsEntity, startOrigin, startAxis, false);
            Services().SetAlignedModelVisible(handsEntity, true);
            if (Services().CanPickupItem(pickupItem)) {
                Services().AttachItem(
                    handsEntity, pickupItem, attachTag.c_str());
                if (giveItemToPlayer) {
                    Services().GiveItemToPlayer(
                        playerActivator, pickupItem);
                }
            }
            Services().SetAlignedVisible(handsEntity, true);
            if (removePickupItem) {
                Services().HideAndRemoveItem(pickupItem);
            }
        }
        if (legsEntity != nullptr) {
            Services().SetAlignedVisible(legsEntity, true);
        }
    }
}
