#pragma once

#include "game/entities/animatedentity.h"
#include "gamelib/timeline/timelineeventdata.h"

class idCrosshairInfo;
class idDeclEntityDef;
class idDeclInventory;
class idDeclMD6;
class idDeclVoiceOver;
class idFocusTrace;
class idRenderModelGui;

enum usableState_t : int;

class idAnimatedSimple;
class idASDebugGUI;

class idAnimatedSimpleServices {
public:
    virtual ~idAnimatedSimpleServices() = default;
    virtual int GetGameMilliseconds() const { return 0; }
    virtual int GetGameFrame() const { return 0; }
    virtual bool HasTreeAnimator(const idAnimatedSimple&) const {
        return false;
    }
    virtual void Hide(idAnimatedSimple&, bool, bool) {}
    virtual int GetPhysicsContents(const idAnimatedSimple&) const { return 0; }
    virtual void SetPhysicsContents(idAnimatedSimple&, int) {}
    virtual void SetCrosshairHidden(idCrosshairInfo&, bool) const {}
    virtual bool IsChannelDone(const idAnimatedSimple&) const { return true; }
    virtual void Teleport(idAnimatedSimple&,
        const idVec3&, const idAngles&) {}
    virtual void UpdateBaseModelTransform(idAnimatedSimple&) {}
    virtual void GetTransform(const idAnimatedSimple&, bool,
        idVec3& origin, idQuat& rotation) const {
        origin.Zero(); rotation = idQuat(0.0f, 0.0f, 0.0f, 1.0f);
    }
    virtual void SetTransform(idAnimatedSimple&, bool,
        const idVec3&, const idQuat&) {}
    virtual bool IsBaseEverUsable(
        const idAnimatedSimple&, const idEntity*) const { return false; }
    virtual void SetAttachmentDetached(
        idAnimatedSimple&, const char*, bool) {}
    virtual bool StartVoiceOver(idAnimatedSimple&,
        idEntity*, const idDeclVoiceOver*) { return false; }
    virtual bool IsVoiceOverPlaying(
        const idAnimatedSimple&, const idDeclVoiceOver*) const { return false; }
    virtual void WeaponFX(idAnimatedSimple&, fxCondition_t, bool) {}
    virtual void SetModelAttachment(idAnimatedSimple&,
        const idDeclMD6*, const char*, bool) {}
    virtual void SetSceneModel(idAnimatedSimple&, bool) {}
    virtual void ShowAttachments(idAnimatedSimple&, bool) {}
    virtual void Spawn(idAnimatedSimple&) {}
    virtual void ActivateEntity(idAnimatedSimple&, idEntity*) {}
    virtual idAnimAliasHandle ResolveAlias(
        const idAnimatedSimple&, const char*) const { return {}; }
    virtual bool PlayAnimation(idAnimatedSimple&, idAnimAliasHandle,
        bool, int, float) { return false; }
    virtual void SetupState(idAnimatedSimple&, int, bool) {}
    virtual void ComputeStateEndTransform(idAnimatedSimple&, int,
        idVec3& origin, idQuat& rotation) const {
        origin.Zero(); rotation = idQuat(0.0f, 0.0f, 0.0f, 1.0f);
    }
    virtual int RandomInt(int maximum) const {
        return maximum > 0 ? 0 : 0;
    }
    virtual int GetDamageTypes(const idDeclDamage*) const { return 0; }
    virtual int GetDamageAmount(const idDeclDamage*) const { return 0; }
    virtual void CallDeathFunction(idAnimatedSimple&,
        const char*, idEntity*) {}
    virtual void PauseAnimation(idAnimatedSimple&, int, bool&) {}
    virtual void UnpauseAnimation(idAnimatedSimple&, bool) {}
    virtual int GetAnimationFrame(const idAnimatedSimple&) const { return -1; }
    virtual void SetExternalAnimationTime(idAnimatedSimple&, float) {}
    virtual int GetAnimationLoopCount(const idAnimatedSimple&) const {
        return 0;
    }
    virtual bool UseRelaxedChatter(const idAnimatedSimple&) const {
        return false;
    }
    virtual void ApplyAnimationMovement(idAnimatedSimple&) {}
    virtual void UpdateFace(idAnimatedSimple&) {}
    virtual void SetThinkActive(idAnimatedSimple&, bool) {}
    virtual void Shutdown(idAnimatedSimple&) {}

    virtual idRenderModelGui* CreateDebugGUI(idASDebugGUI&) {
        return nullptr;
    }
    virtual void DestroyDebugGUI(idASDebugGUI&, idRenderModelGui*) {}
    virtual idRenderModelGui* DrawDebugGUI(
        idASDebugGUI&, idRenderModelGui*) { return nullptr; }
};

class idAnimatedSimple : public idAnimatedEntity {
public:
    enum stateMarker_t : int {
        STATE_RANDOM = -2,
        STATE_NONE = -1
    };
    enum loopTriggerType_t : int {
        LOOP_TRIGGER_EXACT = 0,
        LOOP_TRIGGER_MULTIPLE = 1
    };
    struct idHitDetection_t {
        idEntity* callTargetWhenDead = nullptr;
        idEntity* onIgnoredDamageTrigger = nullptr;
        idStr callWhenDead;
        int health = 0;
        int ignoreDamageTypes = 0;
        bool shouldGetHit = false;
        bool hasBeenKilled = false;
    };
    struct animEntry_t {
        idAnimAliasHandle animationHandle;
        idAnimAliasRef animation;
        idEntity* perfectOriginRef = nullptr;
        idList<idEntity*, 5> triggerEnter{0};
        idList<idEntity*, 5> triggerLeave{0};
        idList<idEntity*, 5> triggerLoopCount{0};
        idList<idEntity*, 5> triggerAnimDone{0};
        float timeScale = 1.0f;
        int jumpToState = STATE_NONE;
        int blendTime = -1;
        int loopCountToTrigger = 0;
        loopTriggerType_t loopTriggerType = LOOP_TRIGGER_EXACT;
        bool useTimeControl = false;
        bool useAnimationScale = false;
        bool hideWhenDone = false;
        bool useDeltaMovement = false;
        bool loop = false;
        bool useAnimationOrigin = false;
        bool playDefault = false;
    };
    struct attachment_t {
        idStr tag;
        const idDeclEntityDef* entityDef = nullptr;
        idStr entityName;
        const idDeclMD6* md6 = nullptr;
        idStr lwoName;
        const idDeclInventory* itemDef = nullptr;
        int attachHandle = -1;
        int equipSlot = -1;
    };
    struct idFacialOptions_t {
        bool useFacialAnims = false;
        bool useFaceManager = false;
        bool useLidDeformation = false;
        bool useBlinking = false;
        bool useFaceSetupEyeTracking = false;
        bool useEyeTracking = false;
        bool useLipsync = false;
    };

    idAnimatedSimple();
    ~idAnimatedSimple() override;

    static void SetSimpleServices(idAnimatedSimpleServices* services);
    static idAnimatedSimpleServices& SimpleServices();

    virtual void Hide();
    virtual void Hide(bool stopFX);
    virtual void Show();
    bool IsAnimating() const override;
    virtual bool ModifyCrosshairInfo(const idEntity*, const idFocusTrace*,
        usableState_t, idCrosshairInfo& info) const;
    eventInt Event_GetAnimState() const;
    virtual void Teleport(const idVec3& origin, const idAngles& angles);
    virtual void UpdateModelTransform();
    virtual void PostBind();
    virtual bool IsEverUsable(const idEntity* activator) const;

    eventVoid AnimEvent_DetachAttachment(
        const idMD6Anim*, const char* slotName);
    eventVoid AnimEvent_ReattachAttachment(
        const idMD6Anim*, const char* slotName);
    eventVoid AnimEvent_VoiceOver(
        const idMD6Anim*, const idDeclVoiceOver* voiceOver);
    eventVoid AnimEvent_StartWeaponFX(
        const idMD6Anim*, fxCondition_t condition);
    eventVoid AnimEvent_StopWeaponFX(
        const idMD6Anim*, fxCondition_t condition);
    eventVoid AnimEvent_HideModel(
        const idMD6Anim*, const idDeclMD6* model);
    eventVoid AnimEvent_ShowModel(
        const idMD6Anim*, const idDeclMD6* model, const char* tag);
    eventVoid AnimEvent_SetSceneModel(const idMD6Anim*);
    eventVoid AnimEvent_ClearSceneModel(const idMD6Anim*);
    eventVoid Event_ShowAttachments(bool show);
    eventBool Event_StartVoiceOver(
        idEntity* talkingTo, const idDeclVoiceOver*, bool playInCombat);
    eventBool Event_IsVoiceOverPlaying(const idDeclVoiceOver*) const;

    void Spawn();
    void LeaveState(int state);
    void PlayAnim(idAnimAliasHandle alias, bool loop, int blendTime);
    void PlayAnim(const idAnimAliasRef& alias, bool loop, int blendTime);
    eventVoid Event_PlayAnim(const char* name, bool loop, int blendTime);
    virtual float Damage(idEntity* inflictor, idEntity* attacker,
        const idDeclDamage* damageDef, float damageScale,
        const idVec3& direction, trace_t* trace);
    void PauseCurrentAnim(bool pause, int pauseFrame, bool queuePause);
    void SetExternalTime(float normalizedTime);
    eventVoid Event_PauseAnim(bool pause, int frame, bool queuePause);
    void EnterState(int state, int blendTime, bool checkpoint);
    void SetAnimState(int state, int blendTime,
        bool queue, bool checkpoint);
    void SetAnimStateFromAnimAliasRef(
        const idAnimAliasRef& alias, int blendTime, bool queue);
    void GotoNextState(int blendTime, bool queue);
    void GotoPrevState(int blendTime, bool queue);
    eventVoid Event_SetAnimState(int state, int blendTime, bool queue);
    void Think() override;

    idHitDetection_t hitDetectionOptions;
    idList<animEntry_t, 5> animList;
    idList<attachment_t, 5> startingAttachments;
    idFacialOptions_t facialOptions;
    int displayName;
    bool noDeferredPosition;
    bool sceneModel;
    bool isOkWithoutModel;
    bool ignoreMovement;
    bool playerShouldLowerWeapon;
    bool applyAnimTransformLocal;
    bool applyAnimTransform;
    idQuat orgRotation;
    idVec3 orgOrigin;
    idQuat nextRotation;
    idVec3 nextOrigin;
    idVec3 prevTrans;
    float externalTime;
    int animStartFrame;
    int animUpdatedFrame;
    int physicsContent;
    int currentState;
    int queuedAnimState;
    int queuedBlendTime;
    int currentLoopCount;
    int queuePauseFrame;
    bool queuePause;
    bool wasLooping;
    bool isPaused;
    bool hasCheckedDefault;
};

class idASDebugGUI {
public:
    idASDebugGUI();
    ~idASDebugGUI();
    idRenderModelGui* DrawDebugGUI();

    idRenderModelGui* guiModel;
    bool hasFont;
};
