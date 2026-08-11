#pragma once

#include "idlib/bv/bounds.h"
#include "idlib/containers/list.h"
#include "idlib/text/str.h"

#include <cstdint>

class idDeclAiEvent;
class idEntity;
class idPresentableDoorAnimated;
class idSoundShader;
struct trace_t;
class idDoor_Animated;

enum idAnimatedDoorState {
    ANIMATED_DOOR_UNKNOWN = 0,
    ANIMATED_DOOR_CLOSING = 1,
    ANIMATED_DOOR_CLOSED = 2,
    ANIMATED_DOOR_OPENING = 3,
    ANIMATED_DOOR_OPENED = 4,
    ANIMATED_DOOR_BROKEN = 5
};

struct idDoor_AnimatedPiece {
    idStr clipModel;
    idStr joint;
    bool isObstacle = false;
    short jointIndex = -1;
    idPresentableDoorAnimated* presentable = nullptr;
    int physicsId = -1;
    idVec3 origin{0.0f, 0.0f, 0.0f};
    idMat3 axis{1.0f};
    idBounds bounds{};
    bool hidden = false;
    bool collisionLinked = false;
};

class idDoorAnimatedServices {
public:
    virtual ~idDoorAnimatedServices() = default;
    virtual int GetGameMilliseconds() const;
    virtual bool HasAnimator(const idDoor_Animated& door) const;
    virtual void UpdateModelTransform(idDoor_Animated& door);
    virtual void UpdateFrameCommands(idDoor_Animated& door);
    virtual void UpdateAnimation(idDoor_Animated& door);
    virtual void UpdateFX(idDoor_Animated& door);
    virtual void UpdateDoorState(idDoor_Animated& door);
    virtual void SetDoorState(idDoor_Animated& door, idEntity* activator,
        idAnimatedDoorState state);
    virtual void UpdateAASAreas(idDoor_Animated& door);
    virtual void ActivateTargets(idDoor_Animated& door, idEntity* user);
    virtual void BecomeActive(idDoor_Animated& door, int flags);
    virtual void BecomeInactive(idDoor_Animated& door, int flags);
    virtual void PlaySound(idDoor_Animated& door,
        const idSoundShader* sound, int channel);
    virtual bool IsLockedForEntity(const idDoor_Animated& door,
        const idEntity* user, float distance) const;
    virtual bool IsActor(const idEntity* entity) const;
    virtual void AddMotionEvent(idDoor_Animated& door,
        const idDeclAiEvent* eventDeclaration, idEntity* user,
        int currentTime, const idVec3& origin, int delay);
    virtual bool PlayAnimation(idDoor_Animated& door,
        unsigned short animationHandle, int currentTime);
    virtual bool IsAnimationDone(const idDoor_Animated& door,
        int currentTime) const;
    virtual idVec3 GetOrigin(const idDoor_Animated& door) const;

    virtual void HideDoor(idDoor_Animated& door);
    virtual void ShowDoor(idDoor_Animated& door);
    virtual void UnlinkMainClip(idDoor_Animated& door);
    virtual void LinkMainClip(idDoor_Animated& door);
    virtual void HidePiece(idDoor_Animated& door,
        idDoor_AnimatedPiece& piece);
    virtual void ShowPiece(idDoor_Animated& door,
        idDoor_AnimatedPiece& piece);
    virtual void UnlinkPieceCollision(idDoor_Animated& door,
        idDoor_AnimatedPiece& piece);
    virtual void LinkPieceCollision(idDoor_Animated& door,
        idDoor_AnimatedPiece& piece);
    virtual void PresentPiece(idDoor_Animated& door,
        idDoor_AnimatedPiece& piece);
    virtual bool GetDoorTransform(const idDoor_Animated& door,
        idVec3& origin, idMat3& axis) const;
    virtual bool GetJointTransform(const idDoor_Animated& door,
        short jointIndex, idVec3& origin, idMat3& axis) const;
    virtual void PushPiece(idDoor_Animated& door,
        idDoor_AnimatedPiece& piece, int pushFlags,
        const idVec3& newOrigin, const idMat3& newAxis);
    virtual idBounds GetPieceBounds(const idDoor_Animated& door,
        const idDoor_AnimatedPiece& piece) const;
    virtual idBounds GetPhysicsBounds(const idDoor_Animated& door) const;
    virtual int GetTracePhysicsId(const trace_t* trace) const;
    virtual void WarnInvalidJoint(const idDoor_Animated& door,
        int pieceIndex, short jointIndex);

    virtual bool IsGatherQuerySubmitted(std::uint64_t query) const;
    virtual bool GatheredQueryHasActor(std::uint64_t query) const;
    virtual std::uint64_t SubmitActorGather(const idBounds& bounds,
        int contentsMask);
    virtual float GetDoorClosingRange() const;

    virtual void InitializeAnimatorChannel(idDoor_Animated& door);
    virtual short FindJointIndex(const idDoor_Animated& door,
        const char* jointName) const;
    virtual idPresentableDoorAnimated* AllocatePiecePresentable(
        idDoor_Animated& door, idDoor_AnimatedPiece& piece);
    virtual void RegisterPiecePresentable(idDoor_Animated& door,
        idDoor_AnimatedPiece& piece);
    virtual void DeletePiecePresentable(idDoor_Animated& door,
        idDoor_AnimatedPiece& piece);
    virtual unsigned short LoadAnimationAlias(
        const idDoor_Animated& door, const char* aliasName) const;
    virtual void WarnBadAnimation(const idDoor_Animated& door,
        const char* purpose, const char* aliasName);
    virtual void WarnMissingAnimator(const idDoor_Animated& door);
};

class idDoor_Animated {
public:
    static constexpr unsigned short INVALID_ANIMATION = 0xFFFF;
    static constexpr int USABLE_NONE = 0;
    static constexpr int USABLE_DOOR = 7;

    idDoor_Animated();
    virtual ~idDoor_Animated();

    static void SetServices(idDoorAnimatedServices* services);
    static idDoorAnimatedServices& Services();

    virtual void SetLocked(bool lock, idEntity* user);
    virtual bool IsOpen() const;
    virtual bool IsClosed() const;
    virtual int GetUsableState(const idEntity* user = nullptr) const;
    virtual short GetJointIndexFromTrace(const trace_t* trace) const;
    virtual bool Use(idEntity* user, int usableState);
    virtual void Hide();
    virtual void Show();
    virtual bool CanClose(bool testingForUse) const;
    virtual void Think();
    void Spawn();

    void UpdateCollisionParts(idBounds& updatedBounds, bool push);

    bool usableByAI;
    bool locked;
    bool opensWhenUnlocked;
    bool forcedUnusable;
    bool forceUnusableWhenOpened;
    bool playerUsable;
    const idSoundShader* lockedSound;
    const idSoundShader* unlockSound;
    const idDeclAiEvent* motionEventDecl;
    idAnimatedDoorState state;
    idBounds bounds;
    idVec3 origin;
    idMat3 axis;

    int pushFlags;
    idStr openAnim;
    idStr closeAnim;
    idStr lockAnim;
    idStr unlockAnim;
    int msUntilClose;
    bool triggerTargetsOnOpen;
    bool playerCanClose;
    int numMaxOpens;
    idList<idDoor_AnimatedPiece, 5> collisionParts;
    bool testForActorsWhenClosing;
    int autoCloseTime;
    bool playing;
    int openCount;
    unsigned short openAnimHandle;
    unsigned short closeAnimHandle;
    unsigned short lockAnimHandle;
    unsigned short unlockAnimHandle;
    mutable std::uint64_t canCloseQuery;
    int thinkFlags;
    bool hidden;
    bool mainClipLinked;

private:
    void SetDoorState(idEntity* activator, idAnimatedDoorState newState);
};
