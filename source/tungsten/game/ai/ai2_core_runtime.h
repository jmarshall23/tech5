#pragma once

#include "aievents/aievent.h"
#include "cover/coveractions.h"
#include "../gamesys/eventarg.h"
#include "../gamesys/eventdef.h"
#include "../../../engine/cm/jobs/collisionresults.h"
#include "../../../shared/idlib/bv/bounds.h"
#include "../../../shared/idlib/index.h"
#include "idlib/math/vector.h"

#include <array>
#include <vector>

class idAI2;
class idAtomicString;
class idDeclDamage;
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
class idClipModel;
class idEncounterGroup;
enum invalidJointIndex_t : int;
using idJointIndex = idIndex<short, invalidJointIndex_t>;

enum aiMovePushStatus_t : int;
enum aiSubWeb_t : int;
enum alertCycle_t : int;
enum walkState_t : int;
enum aimPoint_t : int;
enum aiFocus_t : int;

class idAIStateTransition {
public:
    enum aiTransCode_t : int {
        AITRANS_NONE = 0
    };
};

class idAIEditable {
public:
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

    idAI2DynamicMerchantGood()
        : inventory(nullptr), itemGiven(false), giveOnce(false),
          singular(false), requiredCompletedJob(nullptr),
          expiredJob(nullptr) {
    }
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
    unsigned int randomSeed;
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
          dropState(0), torsoItemEquipped(false),
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
          maxFireAtLastKnownDuration{} {
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
