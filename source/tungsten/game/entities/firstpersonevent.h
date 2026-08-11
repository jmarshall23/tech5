#pragma once

#include "game/entities/entity.h"

#include <cstdint>

class idFirstPersonEvent;
class idFirstPersonPickup;

using idFirstPersonAnimHandle = std::uint16_t;
constexpr idFirstPersonAnimHandle INVALID_FIRST_PERSON_ANIM = 0xFFFFu;

class idFirstPersonEventServices {
public:
    virtual ~idFirstPersonEventServices() = default;

    virtual int GetGameMilliseconds() const;
    virtual int GetGameFrame() const;
    virtual int RandomInt(int maximum);
    virtual idEntity* GetPrimaryPlayer() const;
    virtual bool IsPlayer(const idEntity* entity) const;
    virtual idEntity* GetPlayerLegs(idEntity* player) const;
    virtual idEntity* GetPlayerHands(idEntity* player) const;
    virtual void SetEventContents(idFirstPersonEvent& event, int contents);
    virtual void QueuePostSpawn(idFirstPersonEvent& event);

    virtual idFirstPersonAnimHandle ResolveAnimationAlias(
        idEntity* alignedEntity, const char* aliasName) const;
    virtual bool GetAnimationMotion(idEntity* alignedEntity,
        idFirstPersonAnimHandle handle, idVec3& animationOrigin,
        idMat3& animationAxis, idVec3& firstOrigin, idMat3& firstAxis,
        idVec3& lastOrigin, idMat3& lastAxis) const;
    virtual bool ComputePickupTransform(idEntity* alignedEntity,
        idFirstPersonAnimHandle handle, const char* jointName,
        idEntity* item, bool lastFrame, idVec3& origin, idMat3& axis) const;

    virtual void EndPlayerBehaviors(idEntity* player);
    virtual void TeleportPlayer(idEntity* player, const idVec3& origin,
        const idMat3& axis);
    virtual void SetPlayerCrouch(idEntity* player, bool crouch);
    virtual void ForcePlayerPhysicsQuery(idEntity* player);
    virtual void SetPlayerCrouchTransition(idEntity* player, bool changed);
    virtual void SetCameraBlendDuration(idEntity* player, int milliseconds);
    virtual void SetSpringCameraFov(idEntity* player,
        const char* userChannel);
    virtual void SetSpringCameraCalculateInDraw(idEntity* player,
        bool calculate);
    virtual int GetPlayerShowFlags(idEntity* player) const;
    virtual void HidePlayerHands(idEntity* player, int reason);
    virtual void ShowPlayerHands(idEntity* player, int reason);
    virtual int GetPlayerInputInhibitFlags(idEntity* player) const;
    virtual void SetPlayerInputInhibitFlags(idEntity* player, int flags);
    virtual bool IsPlayerButtonPressed(idEntity* player, int button) const;
    virtual void GetPlayerMove(idEntity* player, int& forward,
        int& right) const;
    virtual bool GetPlayerViewTransform(idEntity* player, idVec3& origin,
        idMat3& axis) const;
    virtual void StartPlayerPerfectOrigin(idEntity* player,
        const idVec3& origin, int lerpMilliseconds);
    virtual void MarkPlayerPerfectOrigin(idEntity* player);

    virtual bool GetEntityTransform(const idEntity* entity,
        idVec3& origin, idMat3& axis) const;
    virtual void SetAlignedTransform(idEntity* alignedEntity,
        const idVec3& origin, const idMat3& axis, bool local);
    virtual bool IsAlignedBound(const idEntity* alignedEntity) const;
    virtual void BindAligned(idEntity* alignedEntity, idEntity* parent,
        const idAngles& offset, const char* jointName, const char* tagName,
        idVec3& resultingOrigin, idMat3& resultingAxis);
    virtual void UnbindAligned(idEntity* alignedEntity);
    virtual void SetAlignedDeferredPosition(idEntity* alignedEntity,
        bool deferred);
    virtual void SetAlignedVisible(idEntity* alignedEntity, bool visible);
    virtual bool GetRemoveOriginTranslation(
        const idEntity* alignedEntity) const;
    virtual void SetRemoveOriginRotation(idEntity* alignedEntity,
        bool removeRotation);
    virtual void PlayAnimation(idEntity* alignedEntity,
        idFirstPersonAnimHandle handle, bool loop, int blendMilliseconds,
        float rateScale);
    virtual void StopAnimation(idEntity* alignedEntity);
    virtual bool IsAnimationDone(idEntity* alignedEntity,
        int framesAhead) const;
    virtual bool GetTotalOriginTransform(idEntity* alignedEntity,
        idVec3& translation, idMat3& rotation,
        int& lastAnimationBlendFrame) const;
    virtual bool GetWorldJointTransform(idEntity* alignedEntity,
        const char* jointName, idVec3& origin, idMat3& axis) const;
    virtual void ForceNonDeferredAnimationUpdate(idEntity* alignedEntity);
    virtual void AttachCamera(idEntity* alignedEntity,
        const char* jointName, bool smooth, int blendMilliseconds);
    virtual void DetachCamera(idEntity* alignedEntity, bool instant);
    virtual void SetExternalTime(idEntity* alignedEntity,
        float normalizedTime);
    virtual void AttachEntity(idEntity* alignedEntity, idEntity* entity,
        const char* tagName);
    virtual void AttachToOwner(idEntity* alignedEntity,
        int blendMilliseconds);
    virtual void UpdateOwnerFromCamera(idEntity* alignedEntity,
        bool clipMove);
    virtual void DetachFromOwner(idEntity* alignedEntity,
        int blendMilliseconds, const idVec3& viewOrigin,
        const idMat3& viewAxis);
    virtual void SetManualCameraUpdate(idEntity* alignedEntity,
        bool manual);
    virtual void SetAlignedModelVisible(idEntity* alignedEntity,
        bool visible);

    virtual bool CanPickupItem(const idEntity* item) const;
    virtual void AttachItem(idEntity* alignedEntity, idEntity* item,
        const char* slotName);
    virtual void GiveItemToPlayer(idEntity* player, idEntity* item);
    virtual void HideAndRemoveItem(idEntity* item);
    virtual void ShowItem(idEntity* item);
    virtual void ActivateTrigger(idEntity* trigger, idEntity* activator);
    virtual void Warn(const char* message);
};

class idFirstPersonEvent : public idEntity {
public:
    enum attachMode_t : int {
        ATTACHMODE_LEGS = 0,
        ATTACHMODE_HANDS = 1
    };

    enum exitCondition_t : int {
        EXITCONDITION_NONE = 0,
        EXITCONDITION_BUTTONPRESS = 1,
        EXITCONDITION_MOVEMENT = 2
    };

    enum exitConditionMoveType_t : int {
        EXITCONDITION_MOVETYPE_NONE = 0,
        EXITCONDITION_MOVETYPE_RIGHT = 1,
        EXITCONDITION_MOVETYPE_LEFT = 2,
        EXITCONDITION_MOVETYPE_FORWARD = 4,
        EXITCONDITION_MOVETYPE_BACKWARD = 8
    };

    enum changeType_t : unsigned int {
        CHANGE_NEXT = 0,
        CHANGE_PREVIOUS = 1,
        CHANGE_SET = 2,
        CHANGE_RANDOM = 3,
        CHANGE_STOP = 4
    };

    struct bindInfo_t {
        bindInfo_t();
        idEntity* bindParent;
        idAngles bindOffset;
        idStr bindToJoint;
        idStr bindToTag;
    };

    struct animEntry_t {
        animEntry_t();
        idFirstPersonAnimHandle legsAnimationHandle;
        idFirstPersonAnimHandle handsAnimationHandle;
        int stateStarted;
        idEntity* triggerEnter;
        idEntity* triggerLeave;
        idStr legsAnimation;
        idStr handsAnimation;
        exitCondition_t exitCondition;
        exitConditionMoveType_t exitConditionMoveType;
        int exitConditionButton;
        float timeScale;
        int exitParameters;
        int exitStateSucceded;
        int exitStateFailed;
        int maxLoopTime;
        int blendTime;
        bool useTimeControl;
        bool loop;
    };

    idFirstPersonEvent();

    static void SetServices(idFirstPersonEventServices* services);
    static idFirstPersonEventServices& Services();

    void Spawn() override;
    void Think() override;
    void OnActivate(idEntity* activator) override;
    virtual void Event_PostSpawn();
    void Event_AttachEntity(idEntity* entity, const char* tag);
    void Event_ForceEndFirstPersonEvent();
    void Event_SetFirstPersonEventAnimState(int state);
    void SetExternalTime(float normalizedTime);
    void SetCurrentState(changeType_t changeType, int nextState);

    void StartEndEvent();
    void EndEvent();
    bool UpdateAnimation();
    void SetCurrentState(int nextState);
    void GetAnimTotalMovement(idEntity* alignedEntity,
        idFirstPersonAnimHandle animHandle, idVec3& startOrigin,
        idMat3& startAxis, idVec3& endOrigin, idMat3& endAxis) const;
    idEntity* GetAttachedEntity() const;

    bindInfo_t fpBindinfo;
    idList<animEntry_t, 5> extraAnimations;
    idStr legsAnimation;
    idStr handsAnimation;
    idEntity* perfectOriginRef;
    idEntity* perfectDestinationRef;
    idList<idEntity*, 5> triggerEnter;
    idList<idEntity*, 5> triggerLeave;
    idStr cameraJoint;
    idStr fovUserChannel;
    idVec3 playerEndOffset;
    attachMode_t attachMode;
    int blendInTime;
    int blendOutTime;
    int cameraBlendOutTime;
    bool makePlayerFollowAlong;
    bool shouldEndInCrouch;
    bool forceActivateOnPlayer;
    bool useAnimationEndPos;
    bool useAnimationOrigin;
    idEntity* legsEntity;
    idEntity* handsEntity;
    idEntity* playerActivator;
    idVec3 orgPosLegs;
    idMat3 orgAxisLegs;
    idVec3 orgPosHands;
    idMat3 orgAxisHands;
    idVec3 nextPosLegs;
    idMat3 nextRotLegs;
    idVec3 nextPosHands;
    idMat3 nextRotHands;
    idVec3 playerEndPos;
    idMat3 playerEndRot;
    idFirstPersonAnimHandle legsAnimationHandle;
    idFirstPersonAnimHandle handsAnimationHandle;
    int animStartFrame;
    int eventStartTime;
    int eventEndTime;
    int curExtraAnimation;
    float externalTime;
    int playerShowFlags;
    int playerSavedInhibitFlags;
    bool removeOriginTransformLegs;
    bool removeOriginTransformHands;
    bool applyMovement;
};

class idUseFirstPersonEvent : public idEntity {
public:
    idUseFirstPersonEvent();
    bool Use(idEntity* user, int usableState) override;

    bool additionalPickup;
    int additionalPickupState;
};

class idFirstPersonPickup : public idFirstPersonEvent {
public:
    enum pickupState_t : int {
        PICKUPSTATE_NONE = 0,
        PICKUPSTATE_PICKUP = 1,
        PICKUPSTATE_WALKING = 2,
        PICKUPSTATE_PUTDOWN = 3
    };

    struct additionalPickup_t {
        additionalPickup_t();
        idStr attachTag;
        idEntity* pickupItem;
        int animState;
        bool removePickupItem;
        bool giveItemToPlayer;
        idVec3 startOrigin;
        idMat3 startAxis;
    };

    idFirstPersonPickup();
    void Event_PostSpawn() override;
    void Think() override;
    void OnActivate(idEntity* activator) override;

    idList<additionalPickup_t, 5> additionalPickups;
    idEntity* pickupItem;
    idEntity* putdownItem;
    idEntity* pickupEndPosition;
    idStr attachTag;
    idStr alignedJoint;
    int endAnimState;
    int attachToPlayerBlend;
    bool removePickupItem;
    bool giveItemToPlayer;
    idVec3 startOrigin;
    idMat3 startAxis;
    idVec3 endOrigin;
    idMat3 endAxis;
    pickupState_t pickupState;
};
