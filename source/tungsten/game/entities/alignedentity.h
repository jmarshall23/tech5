#pragma once

#include "game/gamesys/eventarg.h"
#include "gamelib/animstack/animstacktypes.h"
#include "idlib/containers/list.h"
#include "idlib/handle.h"
#include "idlib/math/matrix.h"
#include "idlib/math/vector.h"
#include "idlib/text/str.h"

class idAlignedEntity;
class idDeclInventory;
class idDeclMD6;
class idEntity;
class idInventoryItem;
class idMD6Anim;
class idPlayer;
class idSoundShader;

#ifndef TUNGSTEN_ATTACHMENT_HANDLE_DEFINED
#define TUNGSTEN_ATTACHMENT_HANDLE_DEFINED
enum invalidAttachment_t : int { INVALID_ATTACHMENT = -1 };
using idAttachmentHandle =
    idHandle<int, invalidAttachment_t, INVALID_ATTACHMENT>;
#endif

struct idAlignedBlendParms {
    int durationMS = 0;
};

class idAlignedEntityServices {
public:
    virtual ~idAlignedEntityServices() = default;
    virtual int GetGameMilliseconds() const { return 0; }
    virtual int GetGameFrame() const { return 0; }
    virtual void JobSync(idAlignedEntity&) {}
    virtual void SetAnimationRate(idAlignedEntity&, bool, float) {}
    virtual bool IsAnimatorActive(const idAlignedEntity&, bool) const {
        return false;
    }
    virtual void GetSoundTransform(
        const idAlignedEntity&, idVec3&, idMat3&) const {}
    virtual void GetModelTransform(
        const idAlignedEntity&, idVec3&, idMat3&) const {}
    virtual bool PlayAnimation(idAlignedEntity&, bool,
        idAnimAliasHandle, bool, int, const idAlignedBlendParms*, float) {
        return false;
    }
    virtual int GetAnimationDuration(
        const idAlignedEntity&, bool, idAnimAliasHandle) const { return 0; }
    virtual bool IsAnimationDone(
        const idAlignedEntity&, bool, int) const { return true; }
    virtual const char* GetAnimationName(
        const idAlignedEntity&, bool) const { return ""; }
    virtual idAnimAliasHandle ResolveAnimationAlias(
        const idAlignedEntity&, const char*) const { return {}; }
    virtual void GetLastOriginDeltas(const idAlignedEntity&,
        idMat3&, idVec3&, int*) const {}
    virtual void StopAnimation(idAlignedEntity&, bool) {}
    virtual void SetAnimationAlpha(idAlignedEntity&, bool, float, float) {}
    virtual bool ForceAnimationUpdate(idAlignedEntity&) { return false; }
    virtual void AlignEntity(idAlignedEntity&, const idVec3&,
        const idMat3&, int, const char*) {}
    virtual void AttachToOwner(idAlignedEntity&, int, int) {}
    virtual void DetachFromOwner(idAlignedEntity&, int,
        const idVec3&, const idQuat&) {}
    virtual void SetManualCameraUpdate(idAlignedEntity&, bool) {}
    virtual void SetEntityTransform(idAlignedEntity&,
        const idVec3*, const idMat3*) {}
    virtual void DetachCamera(idAlignedEntity&, bool) {}
    virtual void DetachAttachmentByModel(
        idAlignedEntity&, const idDeclMD6*) {}
    virtual void WeaponFX(idAlignedEntity&, int, bool) {}
    virtual void StartSlowMotion(idAlignedEntity&, float, float, float) {}
    virtual void StopSlowMotion(idAlignedEntity&) {}
    virtual void PlayBodySound(idAlignedEntity&,
        const idSoundShader*, int, bool) {}
    virtual void StopBodyLoopSound(idAlignedEntity&) {}
    virtual void StartCameraShake(idAlignedEntity&, int, int) {}
    virtual void SetControllerShake(
        idAlignedEntity&, float, int, float, int) {}
    virtual void SetHandsVisible(idAlignedEntity&, bool) {}
    virtual void CarryNPC(idAlignedEntity&) {}
    virtual void SnapEntityToPlayer(idAlignedEntity&) {}
    virtual void SnapPlayerToEntity(idAlignedEntity&) {}
    virtual void PlayFootstep(idAlignedEntity&, int) {}
    virtual void SetLegsCrossing(idAlignedEntity&) {}
    virtual void StartBlendOut(idAlignedEntity&, bool) {}
    virtual void Unbind(idAlignedEntity&) {}
    virtual void SwitchLedge(idAlignedEntity&) {}
    virtual void SetSprintSlide(idAlignedEntity&, int) {}
    virtual idAttachmentHandle FindAnimatedAttachment(
        idAlignedEntity&, const char*, const char*) const { return {}; }
    virtual void SetAnimatedAttachmentVisible(
        idAlignedEntity&, idAttachmentHandle, bool) {}
    virtual void PlayAnimatedAttachmentAnimation(idAlignedEntity&,
        idAttachmentHandle, const char*, int) {}
    virtual void ApplyOriginDeltas(idAlignedEntity&, bool) {}
    virtual void UpdateOwnerFromCamera(
        idAlignedEntity&, bool, bool, bool, bool, bool) {}
    virtual void UpdateOwnerDefaultView(
        idAlignedEntity&, bool, bool, bool) {}
    virtual void DetachItems(idAlignedEntity&) {}
    virtual void SetViewAnglesFromCamera(
        idAlignedEntity&, bool, bool, bool) {}
    virtual void BecomeInactive(idAlignedEntity&) {}
    virtual void SetExternalTime(idAlignedEntity&, float) {}
    virtual void AttachCamera(idAlignedEntity&, const char*,
        int, int, int, int, float, float) {}
    virtual void Spawn(idAlignedEntity&) {}
    virtual void UpdateAttachments(idAlignedEntity&) {}
    virtual void UpdateInventoryItems(idAlignedEntity&) {}
    virtual void Update(idAlignedEntity&) {}
    virtual void AttachItem(idAlignedEntity&, const idDeclInventory*,
        const char*, bool, bool, bool) {}
    virtual void AttachEntity(idAlignedEntity&, idEntity*, const char*) {}
    virtual void Think(idAlignedEntity&) {}
};

class idAlignedEntity {
public:
    enum ALIGNMODE : int {
        SET_POS_SET_AXIS = 0,
        ALIGN_NODE_POS_SET_AXIS = 1,
        ALIGN_NODE_POS_ALIGN_NODE_AXIS = 2
    };
    struct loopingSound_t {
        const idSoundShader* shader = nullptr;
        idAnimAliasHandle aliasHandle;
    };
    struct queuedAnim_t {
        idAnimAliasHandle aliasHandle;
        bool loop = false;
        int durationMS = 0;
        float rateScale = 1.0f;
        idAlignedBlendParms blendParms;
    };
    struct animInfo_t {
        idAnimAliasHandle curAliasHandle;
        int animDurationMS = 0;
        idList<queuedAnim_t, 5> queuedAnims{0};
        bool startBlendOut = false;
        int startTime = 0;
    };
    struct addedAttachment_t {
        const idDeclInventory* attachItemDecl = nullptr;
        idInventoryItem* attachItem = nullptr;
        idAttachmentHandle attachHandle;
        bool attachAutoDetach = false;
        bool noClone = false;
    };

    idAlignedEntity();
    virtual ~idAlignedEntity();

    static void SetServices(idAlignedEntityServices* services);
    static idAlignedEntityServices& Services();

    virtual void JobSync();
    void SetAnimRateScale(float scale);
    virtual bool IsAnimating() const;
    virtual void GetSoundTransform(idVec3& origin, idMat3& axis) const;
    virtual void GetModelTransform(idVec3& origin, idMat3& axis) const;
    bool InternalPlayAnim(bool additive, animInfo_t& info,
        const idAnimAliasHandle& handle, bool loop, int durationMS,
        const idAlignedBlendParms* blendParms, float rateScale);
    bool IsAnimDone(idAnimAliasHandle handle, int blendOut) const;
    const char* GetCurAnimName() const;
    void GetLastOriginDeltas(idMat3& axis, idVec3& delta, int* time) const;
    void StopAdditiveAnim();
    void SetAdditiveAnimAlpha(float alpha, float blendTime);
    bool ForceNonDeferredAnimationUpdate();
    void Align(const idVec3& position, const idMat3& axis, ALIGNMODE mode);
    void AttachToOwner(int blendTime);
    void DetachFromOwner(int blendTime, const idVec3& origin,
        const idQuat& rotation);
    void SetManualUpdateCamera(bool value);
    virtual void SetOrigin(const idVec3& origin);
    virtual void SetAxis(const idMat3& axis);
    void DetachCamera(bool force);
    eventVoid AnimEvent_DetachAttachmentByModel(
        const idMD6Anim*, const idDeclMD6* model);
    eventVoid AnimEvent_StartWeaponFX(const idMD6Anim*, int condition);
    eventVoid AnimEvent_StopWeaponFX(const idMD6Anim*, int condition);
    eventVoid AnimEvent_StartSlowMotion(
        const idMD6Anim*, float in, float scale, float out);
    eventVoid AnimEvent_StopSlowMotion(const idMD6Anim*);
    eventVoid AnimEvent_SoundBody(
        const idMD6Anim*, const idSoundShader* sound);
    eventVoid AnimEvent_SoundBody2(
        const idMD6Anim*, const idSoundShader* sound);
    eventVoid AnimEvent_SoundBody3(
        const idMD6Anim*, const idSoundShader* sound);
    eventVoid AnimEvent_SoundBodyLoopUntilStopped(
        const idMD6Anim*, const idSoundShader* sound);
    eventVoid AnimEvent_SoundBodyLoopStop(const idMD6Anim*);
    eventVoid AnimEvent_DetachCamera(const idMD6Anim*);
    eventVoid AnimEvent_StartCameraShake(const idMD6Anim*, int, int);
    eventVoid AnimEvent_SetControllerShake(
        const idMD6Anim*, float, int, float, int);
    eventVoid AnimEvent_HideHands(const idMD6Anim*);
    eventVoid AnimEvent_ShowHands(const idMD6Anim*);
    eventVoid AnimEvent_CarryNPC(const idMD6Anim*);
    eventVoid AnimEvent_EntitySnapToPlayer(const idMD6Anim*);
    eventVoid AnimEvent_PlayerSnapToEntity(const idMD6Anim*);
    eventVoid AnimEvent_LeftFoot(const idMD6Anim*);
    eventVoid AnimEvent_RightFoot(const idMD6Anim*);
    eventVoid AnimEvent_LeftRearFoot(const idMD6Anim*);
    eventVoid AnimEvent_RightRearFoot(const idMD6Anim*);
    eventVoid AnimEvent_Land(const idMD6Anim*);
    eventVoid AnimEvent_LeftFootLadder(const idMD6Anim*);
    eventVoid AnimEvent_RightFootLadder(const idMD6Anim*);
    eventVoid AnimEvent_LegsCrossing(const idMD6Anim*);
    eventVoid AnimEvent_AnimStartBlendOut(const idMD6Anim*);
    eventVoid AnimEvent_AdditiveAnimStartBlendOut(const idMD6Anim*);
    eventVoid AnimEvent_Unbind(const idMD6Anim*);
    eventVoid AnimEvent_SwitchLedge(const idMD6Anim*);
    eventVoid AnimEvent_SprintSlideStartLoopingSlideSound(const idMD6Anim*);
    eventVoid AnimEvent_SprintSlideStopLoopingSlideSound(const idMD6Anim*);
    eventVoid AnimEvent_SprintSlideStop(const idMD6Anim*);
    idAttachmentHandle GetAnimatedAttachmentHandle(
        const char* group, const char* name);
    eventVoid AnimEvent_AnimatedAttachment_Show(
        const idMD6Anim*, const char*, const char*);
    eventVoid AnimEvent_AnimatedAttachment_Hide(
        const idMD6Anim*, const char*, const char*);
    eventVoid AnimEvent_AnimatedAttachment_PlayAnim(
        const idMD6Anim*, const char*, const char*, const char*, int);
    bool IsCurAnimDone(int blendOut, bool additive) const;
    void ApplyOriginDeltas(bool force);
    bool PlayAdditiveAnim(const idAnimAliasHandle&, bool, int,
        const idAlignedBlendParms*);
    void UpdateOwnerFromCamera(bool, bool, bool, bool, bool);
    void UpdateOwnerToDefaultViewAngles(bool, bool, bool);
    void DetachItems();
    eventVoid AnimEvent_DetachItem(const idMD6Anim*);
    eventVoid AnimEvent_SoundBodyLoopUntilAnimEnd(
        const idMD6Anim*, const idSoundShader*);
    eventVoid AnimEvent_SetViewAnglesFromCamera(const idMD6Anim*);
    eventVoid AnimEvent_SetViewAnglesFromCameraExt(
        const idMD6Anim*, int, int, int);
    eventVoid AnimEvent_SetViewAnglesToDefault(const idMD6Anim*);
    eventVoid Event_SetViewAnglesFromCamera();
    void InternalBecomeInactive();
    bool PlayAnim(const idAnimAliasHandle&, bool, int,
        const idAlignedBlendParms*, float rateScale);
    void StopAnim();
    void SetExternalTime(float time);
    bool PlayAdditiveAnim(const char*, bool, int,
        const idAlignedBlendParms*);
    void AttachCamera(const char*, int, int, int, int, float, float);
    eventVoid AnimEvent_AttachCamera(
        const idMD6Anim*, const char*, int, int, int);
    eventVoid AnimEvent_AttachCameraExt(
        const idMD6Anim*, const char*, int, int, int, int);
    eventVoid AnimEvent_AttachLimitViewCamera(
        const idMD6Anim*, const char*, int, float, float);
    eventVoid Event_AttachLimitViewCamera(
        const char*, int, int, float, float);
    void Spawn();
    bool PlayAnim(const char*, bool, int,
        const idAlignedBlendParms*, float rateScale);
    virtual void UpdateAttachments();
    void QueueAnim(const idAnimAliasHandle&, bool, int,
        const idAlignedBlendParms*, float rateScale);
    void QueueAdditiveAnim(const idAnimAliasHandle&, bool, int,
        const idAlignedBlendParms*);
    void UpdateInventoryItems();
    void Update();
    void QueueAnim(const char*, bool, int,
        const idAlignedBlendParms*, float rateScale);
    void QueueAdditiveAnim(const char*, bool, int,
        const idAlignedBlendParms*);
    void AttachItem(const idDeclInventory*, const char*, bool, bool, bool);
    void AttachEntity(idEntity*, const char*);
    eventVoid AnimEvent_AttachItem(
        const idMD6Anim*, const idDeclInventory*, const char*);
    eventVoid AnimEvent_AttachItemForManualDetach(
        const idMD6Anim*, const idDeclInventory*, const char*);
    eventVoid AnimEvent_AttachSpecialItemForManualDetach(
        const idMD6Anim*, const idDeclInventory*, const char*);
    virtual void Think();

    idStr name;
    idVec3 origin;
    idMat3 axis;
    loopingSound_t loopingSound;
    animInfo_t baseAnimInfo;
    animInfo_t additiveAnimInfo;
    idStr alignNodeName;
    bool isAlive;
    idStr soundTagName;
    idList<addedAttachment_t, 5> attachmentInfos;
    bool manualUpdate;
    bool okToShow;
    bool updateCamera;
    idPlayer* owner;
    int lastAnimBlendFrame;
    int attachToOwnerBlend;
    int attachToOwnerStart;
    idVec3 deltaTransExternalWorld;
    idVec3 deltaTransScale;
    idVec3 startBlendOrigin;
    idQuat startBlendRot;
    idVec3 endBlendOrigin;
    idQuat endBlendRot;
    idVec3 attachedModelOrigin;
    idMat3 attachedModelAxis;
};
