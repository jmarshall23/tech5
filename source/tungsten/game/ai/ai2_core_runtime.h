#pragma once

#include "aievents/aievent.h"
#include "cover/coveractions.h"
#include "fsm/aifsm.h"
#include "fsm/fsm_melee.h"
#include "animfsm/aianimwebstate.h"
#include "aivoicecontroller.h"
#include "aidamageinfo.h"
#include "../gamesys/eventarg.h"
#include "../gamesys/eventdef.h"
#include "../player/crosshairinfo.h"
#include "../../../engine/cm/jobs/collisionresults.h"
#include "../../../shared/idlib/bv/bounds.h"
#include "../../../shared/idlib/index.h"
#include "../../../shared/idlib/containers/list.h"
#include "../../../shared/idlib/callback.h"
#include "../../../engine/gamelib/animstack/animweb/animwebpath.h"
#include "../../../engine/gamelib/animstack/animweb/animwebeventhandler.h"
#include "../../../engine/gamelib/animstack/animator_af.h"
#include "../../../engine/gamelib/aas2/aas2.h"
#include "idlib/math/vector.h"
#include "idlib/text/str.h"

#include <array>
#include <vector>

class idAI2;
class idAI2CoreServices;
class idAtomicString;
class idDeclDamage;
class idDamageGroup;
class idDeclFacialAnimationSet;
class idDeclInventory;
class idDeclProjectileImpactEffect;
class idEntity;
class idFile_String;
class idFiniteStateMachine;
class idRenderModel;
class idTypeInfo;
class idWeapon;
class idPlayer;
class idAIEventSound;
class idAIEventSphere;
class idAIEvent_PlayerAim;
class idAIEventVoice;
class idAIEventProjectile;
class idAIEventProjectedSphere;
class idAIEvent_Vehicle;
class idAICover;
class aiSenseState_t;
enum aiSense_t : int;
class idClipModel;
class idEncounterGroup;
class idAIActionFSM;
class idAIAction;
class idScriptAction;
class idThread;
class idPresentable;
class idRagdollInfo;
class idAIOrientation;
class idAIMoveInterface;
class idAIFSM;
class idAIState;
class idFocusTrace;
class idAIVoiceController;
class idMD6Anim;
class idCmdArgs;
class idInventoryItem;
class idSoundShader;
class idFireParms;
class idTestFireResults;
class idFinishFireResults;
struct testFireWeaponParms_t;
struct testForBlockedTraceParms_t;
#ifndef TUNGSTEN_ID_ENTITY_INFLUENCE_TRAIL_DEFINED
#define TUNGSTEN_ID_ENTITY_INFLUENCE_TRAIL_DEFINED
class idEntityInfluenceTrail {
public:
    float innerRadius;
    float outerRadius;
    float angle;
    float trailDist;
    float trailFadeInTime;
    float trailFadeOutTime;
};
#endif
enum invalidJointIndex_t : int;
using idJointIndex = idIndex<short, invalidJointIndex_t>;

struct idHudBossInfo {
    float amount;
    int numBars;
    int visibleBars;

    idHudBossInfo() : amount(0.0f), numBars(0), visibleBars(0) {}
};

struct idAI2RobotRuntime {
    bool usesRobot;
    bool isCharging;
    int noFireTime;
    int lastShootTime;
    int numStages;
    int curStage;
    int chargeDoneTime;
    float shootHealthDrain;
    float stageHealth;
    float chargeHealthFract;
    float curStageHealth;
    float bossHealth;
    idEntity* triggerOnPowerOut;
    idEntity* triggerOnChargingDone;
    std::vector<idEntity*> stageTriggers;
    int chargeStartTime;
    int immuneDoneTime;
    float chargeTime;

    idAI2RobotRuntime()
        : usesRobot(false), isCharging(false), noFireTime(-1),
          lastShootTime(-1), numStages(1), curStage(0),
          chargeDoneTime(-1), shootHealthDrain(0.0f),
          stageHealth(300.0f), chargeHealthFract(0.15f),
          curStageHealth(300.0f), bossHealth(1.0f),
          triggerOnPowerOut(nullptr), triggerOnChargingDone(nullptr),
          stageTriggers(), chargeStartTime(-1), immuneDoneTime(-1),
          chargeTime(5.0f) {}
};

enum aiMovePushStatus_t : int;
enum aiSubWeb_t : int;
enum alertCycle_t : int;
enum walkState_t : int;
enum aimPoint_t : int;
enum aiFocus_t : int;
enum equipSlot_t : int;

enum talkState_t : int {
    TALKSTATE_NONE = 0,
    TALKSTATE_WAIT = 1,
    TALKSTATE_AVAILABLE = 2
};

class idAICombatHint {
public:
    enum combatHintClass_t : int {
        COMBATHINTCLASS_DEFAULT = 0,
        COMBATHINTCLASS_MAX = 1
    };
};

enum idAI2OpenCombatTransition_t : int {
    AI2_OC_NONE = 0,
    AI2_OC_DIVE_LEFT,
    AI2_OC_DIVE_RIGHT,
    AI2_OC_DIVE_FORWARD,
    AI2_OC_DIVE_BACKWARD,
    AI2_OC_DODGE_LEFT,
    AI2_OC_DODGE_RIGHT,
    AI2_OC_CROUCH,
    AI2_OC_FLINCH_LEFT,
    AI2_OC_FLINCH_RIGHT
};

enum takedownMode_t : int {
    TAKEDOWNMODE_UNAVAILABLE = 0,
    TAKEDOWNMODE_WINDOW_OPEN = 1,
    TAKEDOWNMODE_STEALTH = 2,
    TAKEDOWNMODE_WINDOW_CLOSED = 3
};

struct idAI2GoreLevelRuntime {
    int goreLevel;
    bool requiresPain;
    float healthRatioThreshold;
    float forwardRunIndex;
    int injuredIdleIndex;

    idAI2GoreLevelRuntime()
        : goreLevel(0), requiresPain(false), healthRatioThreshold(0.0f),
          forwardRunIndex(0.0f), injuredIdleIndex(0) {}
};

struct idAI2GoreGroupRuntime {
    bool valid;
    const char* name;
    int currentGoreLevel;
    float healthRatio;
    idVec3 lastHitForward;
    std::vector<idAI2GoreLevelRuntime> levels;

    idAI2GoreGroupRuntime()
        : valid(false), name(nullptr), currentGoreLevel(0),
          healthRatio(1.0f), lastHitForward(1.0f, 0.0f, 0.0f),
          levels() {}
};

class idAIDeathInfo {
public:
    idAIDeathInfo();
    void Set(const idAIDamageInfo& information);

    idEntity* attacker;
    idEntity* inflictor;
    idDamageImpulse impulse;
    int startDeathTime;
    int currentTime;
    idAI2CoreServices* services;
};

enum runIndexType_t : int {
    ANIMWEBAI_RUNINDEXTYPE_NORMAL = 0,
    ANIMWEBAI_RUNINDEXTYPE_INJURED = 1,
    ANIMWEBAI_RUNINDEXTYPE_SCRAMBLE = 2,
    ANIMWEBAI_RUNINDEXTYPE_FAR = 3,
    ANIMWEBAI_RUNINDEXTYPE_GUNDOWN = 4,
    ANIMWEBAI_RUNINDEXTYPE_NARROW = 5,
    ANIMWEBAI_RUNINDEXTYPE_UP_STAIRS = 6,
    ANIMWEBAI_RUNINDEXTYPE_DOWN_STAIRS = 7,
    ANIMWEBAI_RUNINDEXTYPE_DUCK = 8,
    ANIMWEBAI_RUNINDEXTYPE_MAX = 9
};

class idAIEditable {
public:
    idAIEditable();

    struct idConditionalMerchantInventoryDef {
        enum merchantConditionType_t : int {
            MERCHANTCONDITION_AVAILABLE = 0,
            MERCHANTCONDITION_NOTININVENTORY = 1,
            MERCHANTCONDITION_PLAYERINVENTORY = 2,
            MERCHANTCONDITION_JOB_ACCEPTED = 3,
            MERCHANTCONDITION_JOB_READY = 4,
            MERCHANTCONDITION_JOB_COMPLETE = 5
        };

        struct merchantCondition_t {
            merchantConditionType_t condition;
            const idDeclInventory* testInventory;
            const char* jobDeclaration;

            merchantCondition_t()
                : condition(MERCHANTCONDITION_AVAILABLE),
                  testInventory(nullptr), jobDeclaration(nullptr) {
            }
        };
    };
};

struct idAI2ConditionalMerchantList {
    std::vector<idAIEditable::idConditionalMerchantInventoryDef::
        merchantCondition_t> conditions;
    std::vector<const idDeclInventory*> goods;
    bool listGiven;

    idAI2ConditionalMerchantList() : listGiven(false) {}
};

struct idAI2DynamicMerchantGood {
    const idDeclInventory* inventory;
    bool itemGiven;
    bool giveOnce;
    bool singular;
    const char* requiredCompletedJob;
    const char* expiredJob;
    int desiredCount;
    int currentCount;

    idAI2DynamicMerchantGood()
        : inventory(nullptr), itemGiven(false), giveOnce(false),
          singular(false), requiredCompletedJob(nullptr),
          expiredJob(nullptr), desiredCount(1), currentCount(0) {
    }
};

class idCheckSurroundingsState {
public:
    idCheckSurroundingsState();

    float DistanceExponentToDistance(unsigned int distanceExponent) const;
    float FindNetDirectionInterest(const idAI2* ai,
        const idVec3& testDirection) const;
    bool CanUse(const idAI2* ai) const;
    float FindBestLookInterestPoint(const idAI2* ai,
        idVec3& point) const;
    bool TraceVector(const idAI2* ai, const idVec3& start,
        const idVec3& end) const;
    int UpdateDirectionDistanceExponent(int directionToTrace,
        const idAI2* ai);
    void UpdateLookInterests(const idAI2* ai);
    void Update(const idAI2* ai);
    int GetLookedAtElapsedTime(const idEntity* entity) const;
    void SetLastLookedAtTime(const idEntity* entity, int setTime);

    idAI2CoreServices* services;
    float unitsPerInch;
    float velocityScale;
    int currentTime;
    std::array<idVec3, 8> directions;
    std::array<float, 8> lookInterest;
    std::array<int, 4> lookedAtEntitySpawnIds;
    std::array<int, 4> lookedAtEntityTimes;
};

class idAI2LookDebug {
public:
    idAI2LookDebug(idAI2* owner, const char* text, int duration)
        : owner(owner), text(text), duration(duration) {}
    ~idAI2LookDebug();

    idAI2* owner;
    const char* text;
    int duration;
};

struct idAI2WaterEffectRuntime {
    bool valid;
    idVec3 ownerOrigin;
    idVec3 waterOrigin;
    idVec3 ownerVelocity;
    float waterTop;
    float ownerRadius;

    idAI2WaterEffectRuntime()
        : valid(false), ownerOrigin(0.0f, 0.0f, 0.0f),
          waterOrigin(0.0f, 0.0f, 0.0f),
          ownerVelocity(0.0f, 0.0f, 0.0f), waterTop(0.0f),
          ownerRadius(0.0f) {
    }
};

struct idAI2ModelRuntime {
    unsigned int requestedCapabilities;
    unsigned int modelCapabilities;
    bool faceAnimationEnabled;
    bool hasLookLimits;
    bool hasAimLimits;
    float lookLimits[4];
    float aimLimits[4];

    idAI2ModelRuntime()
        : requestedCapabilities(0), modelCapabilities(0),
          faceAnimationEnabled(false), hasLookLimits(false),
          hasAimLimits(false), lookLimits{ -90.0f, 90.0f, -80.0f, 80.0f },
          aimLimits{ -90.0f, 90.0f, -80.0f, 80.0f } {
    }
};

enum idAI2CoreChildFSM_t : int {
    AI2_CORE_FSM_AVOID = 0,
    AI2_CORE_FSM_PLAYER_INTERACT = 1
};

enum idAI2CoreTargetClass_t : int {
    AI2_CORE_TARGET_OTHER = 0,
    AI2_CORE_TARGET_ACTOR = 1,
    AI2_CORE_TARGET_ROBOT = 2,
    AI2_CORE_TARGET_TURRET = 3
};

class idAI2CoreServices {
public:
    virtual ~idAI2CoreServices() = default;

    virtual void ApplyDamage(idAI2&, int, int,
        const idDeclDamage&, float) {}
    virtual idRenderModel* AllocRenderModel(const char*) { return nullptr; }
    virtual bool SaveFSM(const idAI2&, idFile_String&, const char*,
        const char*) const { return false; }
    virtual void Print(const char*) const {}
    virtual void ActivateItemsOnDeath(idAI2&) {}
    virtual void DeleteClipModel(idAI2&, void*) {}
    virtual int GetAIEventClass(const idAIEvent&) const { return 0; }
    virtual bool DrawControlCamera(idAI2&, idEntity*) { return false; }
    virtual idFiniteStateMachine* GetAlertCycleFSM(idAI2&) const {
        return nullptr;
    }
    virtual bool IsChildFSMActive(const idFiniteStateMachine&,
        const idTypeInfo&) const { return false; }
    virtual void ResetSpecifiedInteractAI(idAI2&) {}
    virtual void SetDyingAI(idAI2&, bool) {}
    virtual bool CheckForGoreByName(idAI2&,
        const idAtomicString&) { return false; }
    virtual void ApplyBaseWaterEffects(idAI2&, int, int) {}
    virtual bool GetWaterEffectRuntime(const idAI2&, int,
        idAI2WaterEffectRuntime&) const { return false; }
    virtual void AddWaterRipple(const idVec3&, float, float) {}
    virtual int AddEncounterGroup(idAI2&, const char*) { return -1; }
    virtual void AddDroppedStimulus(idAI2&, idEntity*) {}
    virtual bool IsWeapon(const idEntity*) const { return false; }
    virtual int WeaponHolsterSlot(const idEntity*) const { return -1; }
    virtual void PrepareModelChange(idAI2&) {}
    virtual bool SetActorModel(idAI2&, idRenderModel*,
        idAI2ModelRuntime&) { return false; }
    virtual void ConfigureModelFocus(idAI2&,
        const idAI2ModelRuntime&) {}
    virtual void InitNavigation(idAI2&) {}
    virtual void InitMovement(idAI2&) {}
    virtual void SetHoldFire(idAI2&) {}
    virtual bool IsCoreChildFSMActive(const idAI2&,
        idAI2CoreChildFSM_t) const { return false; }
    virtual void JobSync(idAI2&, bool) {}
    virtual bool BaseShouldLeaveDormancy(const idAI2&) const {
        return false;
    }
    virtual bool BaseShouldEnterDormancy(const idAI2&) const {
        return false;
    }
    virtual void ProcessFSMEvent(idAI2&, idEventArg&,
        const idEventDef&, const idEventArg*) {}
    virtual bool ControllingFSMRespondsTo(const idAI2&,
        const idEventDef&) const { return false; }
    virtual bool IsPlayerEntity(const idEntity*) const { return false; }
    virtual short JointIndexFromTrace(const idAI2&,
        const trace_t&) const { return -1; }
    virtual void ApplyFakeDamageImpulse(idAI2&, const idVec3&,
        const idVec3&) {}
    virtual void AddPainStimulus(idAI2&, idEntity*) {}
    virtual void DisableAnimatorsOnDeath(idAI2&) {}
    virtual bool GetMeleeJointOrigin(const idAI2&, idJointIndex,
        idVec3&) const { return false; }
    virtual int GetMeleeTargets(const idBounds&, idEntity**, int) const {
        return 0;
    }
    virtual bool IsDeadActor(const idEntity&) const { return false; }
    virtual bool IsKickableDoor(const idEntity&) const { return false; }
    virtual void KickOpenDoor(idEntity&, idAI2&) {}
    virtual void PlayMeleeImpact(const idDeclProjectileImpactEffect&,
        int, const idVec3&, const idVec3&, idEntity&) {}
    virtual void DamageMeleeTarget(idEntity&, idAI2&,
        const idDeclDamage&, float) {}
    virtual idAI2CoreTargetClass_t ClassifyTarget(
        const idEntity*) const { return AI2_CORE_TARGET_OTHER; }
    virtual int PlayerInventoryCount(const idPlayer&,
        const idDeclInventory&) const { return 0; }
    virtual int PlayerJobStatus(const idPlayer&,
        const char*) const { return 0; }
    virtual bool GiveMerchantItem(idAI2&,
        const idDeclInventory&, bool) { return false; }
    virtual int MerchantInventoryForSale(const idAI2&,
        const idPlayer*) const { return 0; }
    virtual bool MerchantHasNeededGoods(const idAI2&,
        const idPlayer&) const { return false; }
    virtual void AddFakePositionStimulus(idAI2&,
        const idEntity*, const idVec3&) {}
    virtual float GetVehicleSoundStimulus(const idAI2&,
        const idAIEventSound&) const { return 0.0f; }
    virtual void AddEventStimulus(idAI2&, const idAIEvent&,
        float) {}
    virtual void PostAlertCycleEvent(idAI2&, const idAIEvent&,
        int) {}
    virtual void EnableInteractionFaceAnimation(idAI2&,
        unsigned int) {}
    virtual void SignalPlayerInteracting(idAI2&) {}
    virtual void* CloneExtendedClipModel(idAI2&) { return nullptr; }
    virtual void ActivateExtendedClipModel(idAI2&, void*, int) {}
    virtual void DrawAI2CoreDebugText(const char*, const idVec3&,
        bool, int) const {}
    virtual void PrintAI2CoreLookDebug(int, int,
        const char*) const {}
    virtual bool GetCoreMuzzlePoint(const idAI2&,
        idVec3&) const { return false; }
    virtual void DrawDodgeDebug(const idAI2&, const char*,
        bool) const {}
    virtual idEncounterGroup* EncounterGroupForHandle(int) const {
        return nullptr;
    }
    virtual void SetSolid(idAI2&, bool, int, int) {}
    virtual void SetAimFocusEntity(idAI2&, const idEntity*, bool,
        int, int) {}
    virtual void SetExplicitAimFocusPoint(idAI2&, const idVec3&,
        bool, int, int) {}
    virtual void ReloadAIWeapon(idAI2&, idWeapon&) {}
    virtual void GetWeaponSkillInterval(const idWeapon&, aiSkill_t,
        int, int&, int&) const {}
    virtual bool GetBlendedEyeOffset(const idAI2&,
        idVec3&) const { return false; }
    virtual int EntitySpawnId(const idEntity*) const { return 0x1FFF; }
    virtual void SetActionScript(idAI2&,
        const idList<idScriptAction, 5>&, idEntity*, idEntity*) {}
    virtual void ClearActionScript(idAI2&) {}
    virtual idAIActionFSM* GetActionFSM(idAI2&) const { return nullptr; }
    virtual idAIAction* GetCurrentAction(const idAI2&) const {
        return nullptr;
    }
    virtual void SetSubWeb(idAI2&, int) {}
    virtual void SetFocusPoint(idAI2&, int, const idVec3&, int,
        int) {}
    virtual void ClearFocus(idAI2&, int) {}
    virtual void SetFocusTrackingEnabled(idAI2&, int, bool) {}
    virtual void SetFocusTrackingSuppressed(idAI2&, int, bool) {}
    virtual void PlayAnimWebPathPerfect(idAI2&,
        const idAnimWebPath&, const idVec3&, const idMat3&,
        bool, bool) {}
    virtual idPresentable* AllocAIPresentable(idAI2&,
        idRenderModel*) { return nullptr; }
    virtual void UpdateInfluenceTrail(idAI2&, const idVec3&, int) {}
    virtual bool IsOnMovingElevator(const idAI2&) const { return false; }
    virtual idAnimator_AF::testSolidResult_t StartAIRagdoll(
        idAI2&, const idRagdollInfo&) {
        return idAnimator_AF::TESTSOLID_NOT_IN_SOLID;
    }
    virtual void StopAIRagdoll(idAI2&) {}
    virtual void SetAIOrientationAxis(idAI2&,
        const idMat3&, bool) {}
    virtual bool IsScriptFiberValid(int) const { return false; }
    virtual bool IsScriptThreadAlive(int) const { return false; }
    virtual int ScriptThreadHandle(const idThread&) const { return 0; }
    virtual void WaitFiberForActionFSM(int) {}
    virtual void WaitThreadForActionFSM(idThread&) {}
    virtual void Error(const char*) const {}
    virtual void ActivateRobotPowerOut(idAI2&, idEntity&) {}
    virtual void SetAimTrackingParmsIndex(idAI2&, aiAccuracy_t) {}
    virtual void GetAFModelTransform(const idAI2&, idVec3& origin,
        idMat3& axis) const {
        origin.Set(0.0f, 0.0f, 0.0f);
        axis = idMat3(1.0f);
    }
    virtual bool PollDropToGroundQuery(idAI2&, float&) { return false; }
    virtual void SubmitDropToGroundQuery(idAI2&, const idVec3&,
        const idVec3&, int) {}
    virtual void PlayAIAdditivePain(idAI2&, idEntity*, idPlayer*,
        const idDeclDamage*, float, const idVec3&, const idVec3&,
        idJointIndex) {}
    virtual bool PollDeathCollisionQuery(idAI2&, int&) { return false; }
    virtual void SubmitDeathCollisionQuery(idAI2&) {}
    virtual void StartDeathCollisionRagdoll(idAI2&) {}
    virtual bool GetEntityPhysicalState(const idAI2&, const idEntity*,
        bool, idVec3&, idVec3&) const { return false; }
    virtual void DrawMeleeDirectionDebug(const idAI2&,
        const idVec3&, const idVec3&, const idVec3&) const {}
    virtual void BeginReloadAction(idAI2&, idAIFSM&, idAIState*,
        int, equipSlot_t, int) {}
    virtual bool PlayerHasCompletedJobForAI(const idPlayer&,
        const idAI2&) const { return false; }
    virtual float FocusTraceDistance(const idFocusTrace&) const {
        return 0.0f;
    }
    virtual int AttitudeToPlayer(const idAI2&,
        const idPlayer&) const { return 3; }
    virtual void SetAnimationWebEvent(idAI2&, aiAnimWeb_t,
        idAnimWebEvent::priority_t, idAnimWebSubWebIndex,
        idAnimWebStateIndex, animWebEvent_t, const idEventDef*) {}
    virtual void ClearAnimationWebEvent(idAI2&, aiAnimWeb_t,
        animWebEvent_t) {}
    virtual void ClearAllAnimationWebEvents(idAI2&, aiAnimWeb_t) {}
    virtual bool IsAnyAnimationWebEventPending(const idAI2&,
        aiAnimWeb_t) const { return false; }
    virtual bool WaitForOverrideAnimation(idAI2&,
        idAnimWebEvent::priority_t, overrideAnim_t,
        animWebEvent_t, bool, int&) { return false; }
    virtual bool ResolveAnimationWebState(const idAI2&, aiAnimWeb_t,
        const char*, const char*, idAnimWebSubWebIndex&,
        idAnimWebStateIndex&) const { return false; }
    virtual void GetCurrentAnimationWebState(const idAI2&, aiAnimWeb_t,
        idAnimWebSubWebIndex&, idAnimWebStateIndex&) const {}
    virtual awPathResult_t ChangeAnimationWebState(idAI2&, aiAnimWeb_t,
        idAnimWebSubWebIndex, idAnimWebStateIndex) {
        return AWPATH_FAILED;
    }
    virtual awPathResult_t ChangeAnimationWebStateVia(idAI2&,
        aiAnimWeb_t, idAnimWebSubWebIndex, idAnimWebStateIndex,
        idAnimWebSubWebIndex, idAnimWebStateIndex) {
        return AWPATH_FAILED;
    }
    virtual void UpdateAIAttachments(idAI2&) {}
    virtual void UpdateExtendedClipModelHips(idAI2&, void*) {}
    virtual void ReleaseCurrentCover(idAI2&) {}
    virtual void DebugScenePoints(const idAI2&) const {}
    virtual void BeginDirectionalMoveAction(idAI2&, aiMoveReason_t,
        idAIState*, idAIFSM*, float, float) {}
    virtual void BeginOverrideMoveAction(idAI2&, aiMoveReason_t,
        idAIState*, idAIFSM*, overrideAnim_t) {}
    virtual idAIVoiceController* GroupVoiceController(idAI2&) {
        return nullptr;
    }
    virtual idAIVoiceController* GlobalVoiceController() {
        return nullptr;
    }
    virtual void GetAIViewTransform(const idAI2&, bool, bool,
        idVec3&, idMat3&) const {}
    virtual void TeleportAI(idAI2&, const idVec3&,
        const idAngles&, const idMat3&) {}
    virtual float CombatRoleHintScore(const idAI2&, const idVec3&,
        idAICombatHint::combatHintClass_t) const { return 0.0f; }
    virtual bool GetAnimationRootDeltas(const idMD6Anim&,
        idVec3&, idVec3&, idQuat&) const { return false; }
    virtual awPathResult_t ForceAnimationWebState(idAI2&, aiAnimWeb_t,
        idAnimWebSubWebIndex, idAnimWebStateIndex, int) {
        return AWPATH_FAILED;
    }
    virtual idThread* CurrentScriptThread() { return nullptr; }
    virtual int CurrentScriptFiberHandle() const { return 0; }
    virtual void RegisterCurrentScriptThread(idAI2&, int) {}
    virtual void RegisterCurrentScriptFiber(idAI2&, int) {}
    virtual bool ExtractAIDamageDeathInfo(const idAIDamageInfo&,
        idEntity*&, idEntity*&, idDamageImpulse&) const { return false; }
    virtual void ApplyGoreLevel(idAI2&, const char*, int,
        const idVec3&) {}
    virtual void SetInjuredRunIndices(idAI2&, float, int) {}
    virtual void ActivateRobotStageTrigger(idAI2&, idEntity&,
        idEntity*) {}
    virtual void ActivateRobotChargingDone(idAI2&, idEntity&) {}
    virtual void KillRobotAI(idAI2&, idEntity*) {}
    virtual void UpdateMovingBodyOrientation(idAI2&, bool) {}
    virtual bool StartAIStaggeringPain(idAI2&,
        const idAIDamageInfo&) { return false; }
    virtual bool StartAIStunningPain(idAI2&,
        const idAIDamageInfo&) { return false; }
    virtual void ApplyAIDamageFeedback(idAI2&, idEntity*, idEntity*,
        const idDeclDamage*, float&) {}
    virtual bool GetTakedownActivatorState(const idAI2&,
        const idEntity&, idVec3&, idVec3&, int&) const { return false; }
    virtual void SetPlayerInteractionDoneState(idAI2&, int) {}
    virtual bool GiveMerchantItemCount(idAI2&,
        const idDeclInventory&, int) { return false; }
    virtual void WipeMerchantInventory(idAI2&) {}
    virtual void AddInvestigateEntityState(idAI2&,
        const idAIEventSound&) {}
    virtual void HandlePlayerAimEvent(idAI2&,
        const idAIEvent_PlayerAim&) {}
    virtual void ReserveAICover(idAI2&, const idAICover&) {}
    virtual void SetAILookFocusEntity(idAI2&, const idEntity*, bool,
        aimPoint_t, int) {}
    virtual const aiSenseState_t* EnemySenseState(
        const idAI2&, aiSense_t) const { return nullptr; }
    virtual bool EnemySenseStateValid(
        const idAI2&, aiSense_t) const { return false; }
    virtual bool UpdateSuspectedEnemyTrail(idAI2&, int) { return false; }
    virtual bool FindClosestAIFocus(idAI2&) { return false; }
    virtual void LeaveCurrentActionNode(idAI2&, bool) {}
    virtual void RestartPlayerInteraction(idAI2&) {}
    virtual void SetAIRunCycleHint(idAI2&, runIndexType_t) {}
    virtual void ApplyBleedOutDamage(idAI2&) {}
    virtual bool GetCoverTransitionState(const idAI2&, const idAICover&,
        idVec3&, idMat3&, posture_t&, bool&, bool&) const { return false; }
    virtual posture_t GetCoverPosture(const idAICover&) const {
        return POSTURE_STANDING;
    }
    virtual bool GetCoverTransitionAnimation(const idAI2&, const char*,
        idVec3&, int&) const { return false; }
    virtual bool DamageRobotAI(idAI2&, idEntity*, const idDeclDamage*,
        trace_t*) { return false; }
    virtual void ThinkRobotAI(idAI2&, int) {}
    virtual void SetAIHidden(idAI2&, bool) {}
    virtual void PopOffAIDamageGroupArmor(idAI2&, idDamageGroup*,
        const idVec3&, const idVec3&, float, bool&) {}
    virtual void NotifyAIKilledEntity(idAI2&, const idEntity*,
        const idEntity*, const idDeclDamage*, float) {}
    virtual bool IsAIGroupMemberMostFaced(const idAI2&,
        const idEntity&, float) const { return true; }
    virtual bool RelinquishAIPlayerControl(idAI2&) { return false; }
    virtual void StartAITakedown(idAI2&, idEntity&, bool, bool,
        takedownMode_t) {}
    virtual bool UseAI(idAI2&, idEntity&, usableState_t) { return false; }
    virtual void SetupAIInteractionView(idAI2&, idPlayer&) {}
    virtual void EndAIInteractionView(idAI2&, idPlayer&) {}
    virtual void UpdateAIAvoidCharacter(idAI2&) {}
    virtual float FakeEnemyWeight(const idEntity&) const { return 0.0f; }
    virtual void SetAIFakeEnemy(idAI2&, idEntity*) {}
    virtual void ClearAIWorldState(idAI2&) {}
    virtual void HandleAIVoiceEvent(idAI2&, const idAIEventVoice&) {}
    virtual void HandleAISoundEvent(idAI2&, const idAIEventSound&, int) {}
    virtual void HandleAIProjectileEvent(idAI2&,
        const idAIEventProjectile&) {}
    virtual void HandleAIGrenadeEvent(idAI2&,
        const idAIEventProjectedSphere&) {}
    virtual void HandleAIVehicleEvent(idAI2&,
        const idAIEvent_Vehicle&) {}
    virtual bool StartAIMoveToCover(idAI2&, const idAICover&,
        idAIFSM*, idAIState*, bool, int) { return false; }
    virtual void DebugAIPerception(const idAI2&) const {}
    virtual int ChooseAIDefensiveTransition(idAI2&,
        const idAIFSM*) { return 0; }
    virtual void BeginAIDormancy(idAI2&) {}
    virtual bool CanUseCheckSurroundings(
        const idCheckSurroundingsState&, const idAI2*) const {
        return false;
    }
    virtual float FindBestAILookInterestPoint(
        const idCheckSurroundingsState&, const idAI2*, idVec3&) const {
        return 0.0f;
    }
    virtual float FindAIAutoFocusEntity(idAI2&,
        const idEntity*&) { return 0.0f; }
    virtual void BeginAIActionScript(idAI2&, int) {}
    virtual void GiveAIAwareness(idAI2&, const idEntity&,
        alertCycle_t) {}
    virtual const idEntity* NearestPlayerForAI(const idAI2&) const {
        return nullptr;
    }
    virtual void ForceAIOpenCombat(idAI2&, const idEntity*) {}
    virtual void ForceAIPlayerInteraction(idAI2&, const idEntity*) {}
    virtual void ForceAIFollowFriendly(idAI2&, const idEntity*) {}
    virtual float ScoreAIPosition(idAI2&, const idVec3&,
        const aiSenseState_t*, float&, float&, float&, float&) {
        return 0.0f;
    }
    virtual void HandleForceFollowCommand(const idCmdArgs&) {}
    virtual bool ForceAIExecuteScriptFSM(idAI2&) { return false; }
    virtual float DamageAI(idAI2&, idEntity*, idEntity*,
        const idDeclDamage*, float, const idVec3&, trace_t*) {
        return 0.0f;
    }
    virtual bool ModifyAICrosshairInfo(const idAI2&, const idEntity*,
        const idFocusTrace&, usableState_t, idCrosshairInfo&) const {
        return false;
    }
    virtual void GatherKnownEnemyCoverTargets(const idAI2&, void*, int) const {}
    virtual void ForceAIEntranceAnimationToCombat(idAI2&) {}
    virtual void ForceAISearchToEntity(idAI2&, idEntity*) {}
    virtual void ProxyCallAIEvent(idAI2&, idEventArg&,
        const idEventDef&, const idEventArg*) {}
    virtual void PrintAIStats(const idCmdArgs&) const {}
    virtual void UpdateAIGroupStatusConditions(idAI2&) {}
    virtual float InitialAIConfidence(const idAI2&) const { return 0.0f; }
    virtual void InitializeAIScriptObjects(idAI2&) {}
    virtual void InitializeAIFSMs(idAI2&) {}
    virtual void InitializeAIActionSettings(idAI2&) {}
    virtual void InitializeAIFireControl(idAI2&) {}
    virtual int ComputeAIMeleeCapabilities(idAI2&) { return 0; }
    virtual bool EquipAIItem(idAI2&, idInventoryItem*,
        equipSlot_t) { return false; }
    virtual bool UnequipAIItem(idAI2&, idInventoryItem*) { return false; }
    virtual bool IsWeaponInventoryItem(const idInventoryItem*) const {
        return false;
    }
    virtual void InitializeAIHeadTracking(idAI2&) {}
    virtual void InitializeAIPhysics(idAI2&) {}
    virtual void InitializeAIAAS(idAI2&) {}
    virtual bool InitializeAIAnimation(idAI2&) { return false; }
    virtual int ComputeAITravelFlags(idAI2&) { return 0; }
    virtual void PlayAIAmbientSound(idAI2&, const idSoundShader*) {}
    virtual void UpdateAIEffects(idAI2&) {}
    virtual void UpdateAIMovement(idAI2&) {}
    virtual void UpdateAIConfidence(idAI2&) {}
    virtual void UpdateAIPathToEnemy(idAI2&, bool) {}
    virtual bool CheckAIGore(idAI2&) { return false; }
    virtual void UpdateAIWorldState(idAI2&) {}
    virtual void DispatchAIEvent(idAI2&, const idAIEvent&) {}
    virtual void HandlePendingAIEvents(idAI2&) {}
    virtual bool UpdateAIAnimationControllers(idAI2&) { return false; }
    virtual bool AIPathPassesNear(const idAI2&, const idVec3&,
        const idVec3&, int, int, const idVec3&, int, float, bool) const {
        return false;
    }
    virtual void UpdateAIVisibilityObscurity(idAI2&, void*) {}
    virtual bool TestAIFireWeapon(idAI2&, idWeapon*, idFireParms&,
        idTestFireResults&, const testFireWeaponParms_t&) { return false; }
    virtual const idEntity* TestAIBlockedTrace(const idAI2&,
        const idFireParms&, const idTestFireResults&, int&,
        const testForBlockedTraceParms_t&) const { return nullptr; }
    virtual bool FinishAIFireWeapon(idAI2&, idWeapon*,
        const idFireParms&, idTestFireResults&, idFinishFireResults&) {
        return false;
    }
    virtual void UpdateAIAimFocus(idAI2&) {}
    virtual bool TraceAISurroundingsVector(
        const idCheckSurroundingsState&, const idAI2*,
        const idVec3&, const idVec3&) const { return false; }
    virtual int UpdateAISurroundingsDirection(
        idCheckSurroundingsState&, int, const idAI2*) { return 0; }
    virtual void UpdateAILookInterests(
        idCheckSurroundingsState&, const idAI2*) {}
    virtual void UpdateAICheckSurroundings(
        idCheckSurroundingsState&, const idAI2*) {}
    virtual void FindAIAutoFocus(idAI2&) {}
    virtual void UpdateAIActions(idAI2&, int) {}
    virtual void PrepAITakeCover(idAI2&, idAICover&, const idEntity*,
        const idEntity*, const idEntity*) {}
    virtual void EnableAIInfluenceTrail(idAI2&,
        const idEntityInfluenceTrail&) {}
    virtual void SpawnAI(idAI2&) {}
    virtual void ShowAI(idAI2&) {}
    virtual void UpdateAIFSMs(idAI2&) {}
    virtual void StartAIDeathSystem(idAI2&) {}
    virtual bool WaitForAITraversal(idAI2&,
        idAnimWebEvent::priority_t, const char*, const char*,
        animWebEvent_t) { return false; }
    virtual void EndAIDormancy(idAI2&, int) {}
    virtual void UpdateAILookFocus(idAI2&) {}
    virtual void ThinkAIPlayerControl(idAI2&) {}
    virtual void ForceAITakeCoverFromEntity(idAI2&,
        const idEntity*, const idEntity*, const idEntity*) {}
    virtual void ThinkAIControl(idAI2&) {}
    virtual void UpdateAIDeath(idAI2&) {}
    virtual void ForceAITakeCoverFromNearestPlayer(idAI2&,
        const idEntity*, const idEntity*) {}
    virtual void ApplyAISpawnSettings(idAI2&) {}
    virtual void CompleteAIDrop(idAI2&) {}
    virtual void FirstAIThink(idAI2&) {}
    virtual void ShutdownAI(idAI2&) {}
    virtual void ThinkAI(idAI2&) {}
};

struct idAI2CoreRuntime {
    idAI2CoreServices* services;
    overrideAnim_t entranceAnim;
    int perceptionFlags;
    int deathFadeOutTime;
    int bodyFadeTime;
    int standingMeleeTypes;
    int crouchingMeleeTypes;
    bool crouching;
    bool relaxedChatter;
    int nextAIEventTime;
    int eventFlags;
    int eventOverloadEnableFlags;
    int eventOverloadDisableFlags;
    void* extendedClipModel;
    int extendedClipModelStatus;
    int extendedClipModelEndTime;
    bool useMoveFSM;
    int movePushStatus;
    int movePushEndTime;
    int currentTime;
    int millisecondsPerFrame;
    int physicsClipModelCount;
    int physicsClipMasks[2];
    int configuredClipMask;
    const idDeclFacialAnimationSet* currentFacialAnimationSet;
    const idDeclFacialAnimationSet* defaultFacialAnimationSet;
    bool interacting;
    bool enableHeadTracking;
    coverAction_t coverAction;
    coverAction_t coverActionToAvoid;
    bool ragdolling;
    bool usesScenePoints;
    bool behaviorUsesScenePoints;
    int encounterGroupHandle;
    const char* encounterGroupName;
    const char* entityName;
    const idDeclInventory* inventoryDecl;
    int gameDifficulty;
    int skillOffset;
    int minimumWalkState;
    int maximumWalkState;
    int walkState;
    std::array<const idEntity*, 15> equippedItems;
    std::array<bool, 15> equippedItemIsWeapon;
    std::array<int, 15> weaponHolsterSlots;
    int groupCondition;
    aiAccuracy_t aimAccuracy;
    std::array<aiAccuracy_t, AISKILL_MAX> skillAccuracy;
    idAI2ModelRuntime model;
    bool navPowerEnabled;
    bool multiplayer;
    bool hasNavigationDeclaration;
    int defaultMovementMode;
    float maximumMoveSpeed;
    float accelerationRate;
    float decelerationRate;
    bool showTrajectories;
    bool dormancyEnabled;
    bool baseShouldLeaveDormancy;
    int dropState;
    bool torsoItemEquipped;
    bool ignoreDamageWhileDropping;
    mutable unsigned int randomSeed;
    float nonPlayerOneShotChance;
    idVec3 physicsOrigin;
    idVec3 gravityNormal;
    float physicsBoundsHeight;
    bool actionScriptRunning;
    bool painStimulusEnabled;
    bool meleeDefinitionAvailable[2];
    bool behaviorCanMelee;
    bool equippedWeaponFireIdle;
    bool equippedWeaponReloading;
    int actorClass;
    float meleeExtrapolate;
    float closeMeleeDistance;
    float mediumMeleeDistance;
    float longMeleeDistance;
    float movingMeleeDistance;
    float minimumLeapAttackDistance;
    float maximumLeapAttackDistance;
    idVec3 bodyForward;
    float crouchMoveMaximum;
    float injuredCrouchMoveMaximum;
    float runMoveMinimum;
    float sprintMoveMinimum;
    bool sprintAllowed;
    bool runWhenFiredAt;
    bool postureCrouched;
    int tauntRageChances[4];
    float angryRageChances[4];
    bool providesFormationCover;
    bool hasPlayerInteraction;
    float interactionApproachRadius;
    int takedownWindowClosed;
    int takedownWindowMaximumTime;
    std::vector<idAI2ConditionalMerchantList> conditionalMerchantLists;
    std::vector<idAI2DynamicMerchantGood> dynamicMerchantGoods;
    int specialDynamicMerchantGoodCount;
    int gameFrame;
    float hearingStimulusScale;
    unsigned int faceAnimationFlags;
    int debugLevel;
    int aimDebugLevel;
    int lookDebugLevel;
    int entityNumber;
    idVec3 eyeOffset;
    idVec3 bodyRight;
    float sidestepDistance;
    float diveDistance;
    float muzzleTraceClearOffset;
    int rangedItemSelection;
    int dodgeDebugLevel;
    int forcedWalkState;
    aiWalkModifier_t walkModifier;
    aiWalkModifier_t runModifier;
    const char* forcedWalkModifierName;
    const char* forcedRunModifierName;
    int configuredContents;
    int physicsContents[2];
    bool solid;
    int aimFocusAimPoint;
    std::array<int, AISKILL_MAX> minFireAtLastKnownDuration;
    std::array<int, AISKILL_MAX> maxFireAtLastKnownDuration;
    idVec3 linearVelocity;
    bool enableAutoFocus;
    int lookFocusTimeout;
    bool dead;
    int actionScriptFlags;
    bool defaultPainStimulusEnabled;
    idFiniteStateMachine::fsmStatus_t actionStatus;
    bool currentActionIsIdle;
    bool alwaysInCombat;
    int alertCycle;
    int previousAlertCycle;
    int highestAlertCycle;
    int lastSurprisedTime;
    bool suppressHeadTracking;
    std::array<int, ANIMWEBAI_RUNINDEXTYPE_MAX> runCycleIndices;
    std::array<int, ANIMWEBAI_RUNINDEXTYPE_MAX> idleIndices;
    bool influenceTrailsEnabled;
    bool animationMoveInterfaceActive;
    bool animationMoveDone;
    bool physicsMoveDone;
    idAIOrientation* animationMoveOrientation;
    idAIOrientation* physicsMoveOrientation;
    idAIOrientation* animationBodyOrientation;
    idAIOrientation* focusBodyOrientation;
    idAIMoveInterface* animationMoveInterface;
    idAIMoveInterface* physicsMoveInterface;
    bool ragdollStartBlockedInSolid;
    int waitActionFiberHandle;
    int waitActionThreadHandle;
    idAnimWebPath entranceAnimWebPath;
    idAI2RobotRuntime robot;
    bool afActive;
    bool afClientAuthoritativeActive;
    bool afSyncing;
    idMat3 physicsAxis;
    idMat3 bodyOrientationAxis;
    idVec3 modelOffset;
    bool dropQueryPending;
    float dropQueryFraction;
    bool additivePainEnabled;
    float maximumBaseHealth;
    int moveStatus;
    float twitchThresholdStanding;
    float twitchThresholdWalking;
    float twitchThresholdRunning;
    bool dying;
    bool deathCollisionSuppressed;
    bool deathCollisionPending;
    bool deathCollisionQueryPending;
    float movingPainSpeed;
    float baseHealthRatio;
    int lastDamageTime;
    int takedownId;
    std::array<bool, 15> reloadWeaponPresent;
    std::array<bool, 15> reloadCurrentAmmoValid;
    std::array<bool, 15> reloadNextAmmoValid;
    std::array<int, 15> reloadAmmoToken;
    std::array<int, 15> reloadAmmoInClip;
    std::array<int, 15> reloadClipSize;
    bool interactionHasJob;
    bool interactionHasMessageVoiceOver;
    bool interactionHasMessageTrigger;
    int disassembleLootCount;
    bool deathLootOverride;
    bool lootable;
    bool looted;
    bool hasLootableItems;
    bool taggableBehavior;
    bool passified;
    bool hasMutantTag;
    bool playerInteractionDeclarationAvailable;
    bool interactionIsUsable;
    int deathTime;
    int lootDelayMilliseconds;
    bool forceNoMerchant;
    int animAfterOverride;
    int movementType;
    float flyMoveMaximum;
    bool currentCoverValid;
    bool lastCoverValid;
    unsigned int memoryFlags;
    bool visibilityObscurityValid;
    std::array<int, 7> visibilityObscurity;
    int transitionCode;
    int minimumAimDodgeInterval;
    int maximumAimDodgeInterval;
    int nextDodgeTime;
    int nextMoveTime;
    bool onlyCoverHideNoHelmet;
    float headArmor;
    int encounterLivingMembers;
    idAIVoiceController* selfVoiceController;
    float minimumMoveSpeed;
    float minimumMoveTurnRate;
    float maximumMoveTurnRate;
    float forcedMoveSpeed;
    bool forceTurnRate;
    float forcedMinimumTurnRate;
    float forcedMaximumTurnRate;
    bool viewTagValid;
    bool eyeJointValid;
    bool scramblesEnabled;
    int scrambleTime;
    int lastFiredAtTime;
    bool currentCombatStageRetreat;
    int encounterStageChangeTime;
    bool injuredRunsEnabled;
    bool injuredRunUsesGoreLevel;
    bool advancedGoreSupported;
    int previousInjuryGoreLevel;
    int injuryGoreLevelIndex;
    const char* injuryDamageGroupName;
    idAI2GoreGroupRuntime goreGroup;
    bool movementUsesAnimationModes;
    bool playingTraversalAnimation;
    int movementStartFrame;
    int remainingTransitionFrames;
    bool enableBodyRotation;
    bool suppressBodyRotation;
    bool sitting;
    bool moveAlignToNextPoint;
    float enemyTooCloseToGoProneDistance;
    float enemyTooCloseToGoProneFacingDistance;
    idEntity* currentEnemy;
    bool currentEnemyVisible;
    bool currentEnemyRecentlyConfirmed;
    idEntity* currentFriendlyBlocker;
    bool angryRageConfigured;
    bool tauntRageConfigured;
    bool useGroupRageLimit;
    int noRageMemberCount;
    bool closestGroupMemberToEnemy;
    int wantAngryRageTime;
    int wantTauntRageTime;
    int soonestAngryRageTime;
    int soonestTauntRageTime;
    int staleAngryRageThreshold;
    int staleTauntRageThreshold;
    bool takedownDeathDisabled;
    int takeDownType;
    bool interactionCanBeClosed;
    int interactionTempState;
    std::vector<const idDeclInventory*> specialDynamicMerchantItems;
    int specialDynamicNextGiveTime;
    bool specialDynamicIsMerchant;
    bool specialDynamicWipeInventory;
    idEntity* fakeEnemy;
    float fakeEnemyWeight;
    bool playerControlled;
    bool playerInteractionFSMActive;
    runIndexType_t currentRunCycleHint;
    bool coverTransitionObstacleValid;
    idVec3 coverTransitionObstacleOrigin;
    bool hidden;
    bool inNonResidentCollisionArea;
    bool hasControllingPlayer;
    bool animationEdgeTransitionActive;
    bool afAtRest;
    bool boundToZipline;
    int alertCycleLastTransitionTime;
    bool movementDropping;
    int tauntRageAfterKillingEnemyChance;
    const idEntity* currentActionEntity;
    idStr actionNodeGroupName;
    bool interactionViewActive;
    float avoidCharacterRadius;
    bool dormant;
    bool executeScriptFSMActive;
    const idEntity* interactionEntity;
    const idEntity* friendlyEntity;
    int spawnTime;
    float confidenceLevel;
    int meleeCapabilities;
    int travelFlags;
    bool influenceTrailEnabled;
    bool spawned;
    bool firstThinkComplete;
    bool deathSystemStarted;
    bool dropComplete;
    bool spawnSettingsApplied;
    int lastFSMUpdateTime;
    int lastDormantDuration;

    idAI2CoreRuntime()
        : services(nullptr), entranceAnim(ANIMOVERRIDE_NONE),
          perceptionFlags(0), deathFadeOutTime(0), bodyFadeTime(0),
          standingMeleeTypes(0), crouchingMeleeTypes(0), crouching(false),
          relaxedChatter(false), nextAIEventTime(0), eventFlags(0),
          eventOverloadEnableFlags(0), eventOverloadDisableFlags(0),
          extendedClipModel(nullptr), extendedClipModelStatus(0),
          extendedClipModelEndTime(0), useMoveFSM(false),
          movePushStatus(0), movePushEndTime(0), currentTime(0),
          millisecondsPerFrame(16), physicsClipModelCount(1),
          physicsClipMasks{ 0, 0 }, configuredClipMask(0),
          currentFacialAnimationSet(nullptr),
          defaultFacialAnimationSet(nullptr), interacting(false),
          enableHeadTracking(true), coverAction(COVERACTION_NONE),
          coverActionToAvoid(COVERACTION_NONE), ragdolling(false),
          usesScenePoints(false), behaviorUsesScenePoints(false),
          encounterGroupHandle(-1), encounterGroupName(nullptr),
          entityName(nullptr), inventoryDecl(nullptr), gameDifficulty(1),
          skillOffset(0), minimumWalkState(0), maximumWalkState(3),
          walkState(0), equippedItems{}, equippedItemIsWeapon{},
          weaponHolsterSlots{}, groupCondition(0),
          aimAccuracy(ACCURACY_FROMSKILL), skillAccuracy{}, model(),
          navPowerEnabled(false), multiplayer(false),
          hasNavigationDeclaration(false), defaultMovementMode(0),
          maximumMoveSpeed(0.0f), accelerationRate(0.0f),
          decelerationRate(0.0f), showTrajectories(false),
          dormancyEnabled(true), baseShouldLeaveDormancy(false),
          dropState(-1), torsoItemEquipped(false),
          ignoreDamageWhileDropping(false), randomSeed(0),
          nonPlayerOneShotChance(0.0f),
          physicsOrigin(0.0f, 0.0f, 0.0f),
          gravityNormal(0.0f, 0.0f, -1.0f),
          physicsBoundsHeight(0.0f), actionScriptRunning(false),
          painStimulusEnabled(false),
          meleeDefinitionAvailable{ false, false },
          behaviorCanMelee(false), equippedWeaponFireIdle(true),
          equippedWeaponReloading(false), actorClass(0),
          meleeExtrapolate(0.0f), closeMeleeDistance(0.0f),
          mediumMeleeDistance(0.0f), longMeleeDistance(0.0f),
          movingMeleeDistance(0.0f), minimumLeapAttackDistance(0.0f),
          maximumLeapAttackDistance(0.0f),
          bodyForward(1.0f, 0.0f, 0.0f), crouchMoveMaximum(0.0f),
          injuredCrouchMoveMaximum(0.0f), runMoveMinimum(0.0f),
          sprintMoveMinimum(0.0f), sprintAllowed(false),
          runWhenFiredAt(false), postureCrouched(false),
          tauntRageChances{ 0, 0, 0, 0 },
          angryRageChances{ 0.0f, 0.0f, 0.0f, 0.0f },
          providesFormationCover(false), hasPlayerInteraction(false),
          interactionApproachRadius(160.0f), takedownWindowClosed(-1),
          takedownWindowMaximumTime(-1), conditionalMerchantLists(),
          dynamicMerchantGoods(), specialDynamicMerchantGoodCount(0),
          gameFrame(0), hearingStimulusScale(1.0f),
          faceAnimationFlags(0), debugLevel(0), aimDebugLevel(0),
          lookDebugLevel(0), entityNumber(-1),
          eyeOffset(0.0f, 0.0f, 0.0f),
          bodyRight(0.0f, 1.0f, 0.0f), sidestepDistance(0.0f),
          diveDistance(0.0f), muzzleTraceClearOffset(0.0f),
          rangedItemSelection(0), dodgeDebugLevel(0),
          forcedWalkState(0), walkModifier(AIWALKMOD_DEFAULT),
          runModifier(AIWALKMOD_DEFAULT),
          forcedWalkModifierName(nullptr), forcedRunModifierName(nullptr),
          configuredContents(0), physicsContents{ 0, 0 }, solid(true),
          aimFocusAimPoint(0), minFireAtLastKnownDuration{},
          maxFireAtLastKnownDuration{},
          linearVelocity(0.0f, 0.0f, 0.0f), enableAutoFocus(false),
          lookFocusTimeout(0), dead(false), actionScriptFlags(0),
          defaultPainStimulusEnabled(false),
          actionStatus(idFiniteStateMachine::FSMSTATUS_DONE),
          currentActionIsIdle(false), alwaysInCombat(false),
          alertCycle(1), previousAlertCycle(1), highestAlertCycle(1),
          lastSurprisedTime(0), suppressHeadTracking(false),
          runCycleIndices{}, idleIndices{}, influenceTrailsEnabled(false),
          animationMoveInterfaceActive(false), animationMoveDone(true),
          physicsMoveDone(true), animationMoveOrientation(nullptr),
          physicsMoveOrientation(nullptr), animationBodyOrientation(nullptr),
          focusBodyOrientation(nullptr), animationMoveInterface(nullptr),
          physicsMoveInterface(nullptr), ragdollStartBlockedInSolid(false),
          waitActionFiberHandle(0), waitActionThreadHandle(0),
          entranceAnimWebPath(), robot(), afActive(false),
          afClientAuthoritativeActive(false), afSyncing(false),
          physicsAxis(1.0f), bodyOrientationAxis(1.0f),
          modelOffset(0.0f, 0.0f, 0.0f), dropQueryPending(false),
          dropQueryFraction(1.0f), additivePainEnabled(true),
          maximumBaseHealth(1.0f), moveStatus(0),
          twitchThresholdStanding(0.0f),
          twitchThresholdWalking(0.0f),
          twitchThresholdRunning(0.0f), dying(false),
          deathCollisionSuppressed(false), deathCollisionPending(false),
          deathCollisionQueryPending(false), movingPainSpeed(0.0f),
          baseHealthRatio(1.0f), lastDamageTime(0), takedownId(-1),
          reloadWeaponPresent{}, reloadCurrentAmmoValid{},
          reloadNextAmmoValid{}, reloadAmmoToken{}, reloadAmmoInClip{},
          reloadClipSize{}, interactionHasJob(false),
          interactionHasMessageVoiceOver(false),
          interactionHasMessageTrigger(false), disassembleLootCount(0),
          deathLootOverride(false), lootable(false), looted(false),
          hasLootableItems(false), taggableBehavior(false),
          passified(false), hasMutantTag(false),
          playerInteractionDeclarationAvailable(false),
          interactionIsUsable(false), deathTime(0),
          lootDelayMilliseconds(0), forceNoMerchant(false),
          animAfterOverride(0), movementType(0),
          flyMoveMaximum(0.0f), currentCoverValid(false),
          lastCoverValid(false), memoryFlags(0),
          visibilityObscurityValid(false), visibilityObscurity{},
          transitionCode(AI2_OC_NONE), minimumAimDodgeInterval(0),
          maximumAimDodgeInterval(0), nextDodgeTime(0), nextMoveTime(0),
          onlyCoverHideNoHelmet(false), headArmor(0.0f),
          encounterLivingMembers(0), selfVoiceController(nullptr),
          minimumMoveSpeed(0.0f), minimumMoveTurnRate(0.0f),
          maximumMoveTurnRate(0.0f), forcedMoveSpeed(0.0f),
          forceTurnRate(false), forcedMinimumTurnRate(0.0f),
          forcedMaximumTurnRate(0.0f), viewTagValid(false),
          eyeJointValid(false), scramblesEnabled(false), scrambleTime(0),
          lastFiredAtTime(0), currentCombatStageRetreat(false),
          encounterStageChangeTime(0), injuredRunsEnabled(false),
          injuredRunUsesGoreLevel(false), advancedGoreSupported(true),
          previousInjuryGoreLevel(0), injuryGoreLevelIndex(-1),
          injuryDamageGroupName(nullptr), goreGroup(),
          movementUsesAnimationModes(false),
          playingTraversalAnimation(false), movementStartFrame(-1),
          remainingTransitionFrames(0), enableBodyRotation(true),
          suppressBodyRotation(false), sitting(false),
          moveAlignToNextPoint(false),
          enemyTooCloseToGoProneDistance(0.0f),
          enemyTooCloseToGoProneFacingDistance(0.0f),
          currentEnemy(nullptr), currentEnemyVisible(false),
          currentEnemyRecentlyConfirmed(false),
          currentFriendlyBlocker(nullptr), angryRageConfigured(false),
          tauntRageConfigured(false), useGroupRageLimit(false),
          noRageMemberCount(0), closestGroupMemberToEnemy(false),
          wantAngryRageTime(0), wantTauntRageTime(0),
          soonestAngryRageTime(0), soonestTauntRageTime(0),
          staleAngryRageThreshold(0), staleTauntRageThreshold(0),
          takedownDeathDisabled(false), takeDownType(0),
          interactionCanBeClosed(false), interactionTempState(0),
          specialDynamicMerchantItems(), specialDynamicNextGiveTime(-1),
          specialDynamicIsMerchant(false),
          specialDynamicWipeInventory(false), fakeEnemy(nullptr),
          fakeEnemyWeight(0.0f), playerControlled(false),
          playerInteractionFSMActive(false),
          currentRunCycleHint(ANIMWEBAI_RUNINDEXTYPE_NORMAL),
          coverTransitionObstacleValid(false),
          coverTransitionObstacleOrigin(0.0f, 0.0f, 0.0f),
          hidden(false), inNonResidentCollisionArea(false),
          hasControllingPlayer(false),
          animationEdgeTransitionActive(false), afAtRest(true),
          boundToZipline(false), alertCycleLastTransitionTime(0),
          movementDropping(false), tauntRageAfterKillingEnemyChance(0),
          currentActionEntity(nullptr), actionNodeGroupName(),
          interactionViewActive(false), avoidCharacterRadius(0.0f),
          dormant(false), executeScriptFSMActive(false),
          interactionEntity(nullptr), friendlyEntity(nullptr),
          spawnTime(0), confidenceLevel(0.0f), meleeCapabilities(0),
          travelFlags(0), influenceTrailEnabled(false), spawned(false),
          firstThinkComplete(false), deathSystemStarted(false),
          dropComplete(false), spawnSettingsApplied(false),
          lastFSMUpdateTime(0), lastDormantDuration(0) {
        skillAccuracy.fill(ACCURACY_DECENT);
        weaponHolsterSlots.fill(-1);
    }
};

class idAI2Patch1 {
public:
    idAI2Patch1();

    int bleedOutGroundQueryIndex;
    int bleedOutHipQueryIndex;
    idVec3 unclippedOffset;
    bool aasPositionManagerConstructed;
    bool stuckStateConstructed;
};

idAIStateTransition::aiTransCode_t DebugDodge(const idAI2* ai,
    char* text, idAIStateTransition::aiTransCode_t transition);
bool OkToFocus(const idVec3& target, const idVec3& origin,
    const idVec3& actualPosition);
