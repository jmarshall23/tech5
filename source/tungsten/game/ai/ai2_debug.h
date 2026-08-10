#pragma once

#include "../entities/entityptr.h"
#include "../gametooldefs.h"
#include "cover/coveractions.h"
#include "cover/coverquery.h"
#include "idlib/math/vector.h"
#include "idlib/handle.h"
#include "idlib/index.h"
#include "idlib/typesafenumber.h"
#include "ai2_core_runtime.h"

class idDamageGroup;
class idEntity;
class idPlayer;
struct aiPlayerInteraction_t;
enum playerInteractionState_t : int;
enum invalidThreadHandle_t : int;
enum invalidFiberId_t : int;
using idThreadHandle = idHandle<int, invalidThreadHandle_t, 0>;
using idFiberHandle = idHandle<int, invalidFiberId_t, 0>;
class idEventDef;
class idThread;
class idDeclAIPlayerInteraction;
class idDeclJob;
class idDeclVoiceOver;
class idDeclInventory;
class idDeclProjectile;
class idWeapon;
class idMD6Anim;
class idEventDef;
class aiSenseState_t;
class idAICover;
class idAIEventVoice;
class idAIEventProjectile;
class idAIEventProjectedSphere;
class idAIEvent_Vehicle;
class idCmdArgs;
class idInventoryItem;
class idSoundShader;
class idFireParms;
class idTestFireResults;
class idFinishFireResults;
struct testFireWeaponParms_t;
struct testForBlockedTraceParms_t;
class idEntityInfluenceTrail;
enum aiAwareness_t : int;
enum aiSense_t : int;
enum secondUnique_t : int;
enum millisecondUnique_t : int;
enum invalidJointIndex_t : int;
enum invalidAIAnimNodeIndex_t : int;

enum aiItemSelect_t : int {
    AIITEMSELECT_NONE = 0,
    AIITEMSELECT_GRENADE = 1,
    AIITEMSELECT_DUAL_MUTANT = 2,
    AIITEMSELECT_CLUB_MUTANT = 3,
    AIITEMSELECT_SCOOP_MUTANT = 4,
    AIITEMSELECT_LARGE_RANGED_MUTANT = 5,
    AIITEMSELECT_HEAVY_BANDIT = 6,
    AIITEMSELECT_PIPE_BANDIT = 7,
    AIITEMSELECT_IMP = 8,
    AIITEMSELECT_MAX = 9
};

enum aiSelectCondition_t : int {
    AISELECTCONDITION_ADVANCE = 0,
    AISELECTCONDITION_OPENCOMBAT = 1,
    AISELECTCONDITION_COVER = 2,
    AISELECTCONDITION_MAX = 3
};

class idTrajectory {
public:
    struct parms_t {
        float time;
        float speed;
        float gravity;
    };
};

class idTrajectory_Parabolic {
public:
    struct parabolicParms_t : public idTrajectory::parms_t {
        float angle;
        float maxHeight;
        float horizSpeed;
        float vertSpeed;
    };
};

struct idCachedJoint {
    idIndex<short, invalidJointIndex_t> jointIndex;
    short frameNum;
    idVec3 trans;
    idQuat rot;
};

struct idAIProjectileInfo {
    idAIProjectileInfo()
        : itemDecl(nullptr), coverAction(COVERACTION_MAX),
          actualTargetPos(0.0f, 0.0f, 0.0f),
          actualTargetVel(0.0f, 0.0f, 0.0f),
          predictedTargetPos(0.0f, 0.0f, 0.0f), nodeIndex(),
          overrideAnim(ANIMOVERRIDE_NONE), jointIndex(),
          useMuzzleForLaunch(false), target() {
        linearParms = { 0.0f, 0.0f, 0.0f };
        parabolicParms.time = 0.0f;
        parabolicParms.speed = 0.0f;
        parabolicParms.gravity = 0.0f;
        parabolicParms.angle = 0.0f;
        parabolicParms.maxHeight = 0.0f;
        parabolicParms.horizSpeed = 0.0f;
        parabolicParms.vertSpeed = 0.0f;
    }

    const idDeclInventory* itemDecl;
    coverAction_t coverAction;
    idVec3 actualTargetPos;
    idVec3 actualTargetVel;
    idVec3 predictedTargetPos;
    idIndex<short, invalidAIAnimNodeIndex_t> nodeIndex;
    overrideAnim_t overrideAnim;
    idIndex<short, invalidJointIndex_t> jointIndex;
    bool useMuzzleForLaunch;
    idEntityPtr<const idEntity> target;
    idTrajectory::parms_t linearParms;
    idTrajectory_Parabolic::parabolicParms_t parabolicParms;
};

class idAI2 {
public:
    enum aiDebugLevel_t : int {
        AIDEBUGLEVEL_NONE = 0,
        AIDEBUGLEVEL_ERROR = 1,
        AIDEBUGLEVEL_ACTION = 2
    };

    class idVisibilityObscurity {
    public:
        enum obscurityTest_t : int {
            OBSCURITYTEST_MUZZLE_POS = 0,
            OBSCURITYTEST_HALF_HEIGHT_FAR_LEFT = 1,
            OBSCURITYTEST_HALF_HEIGHT_FAR_RIGHT = 2,
            OBSCURITYTEST_HALF_HEIGHT_NEAR_LEFT = 3,
            OBSCURITYTEST_HALF_HEIGHT_NEAR_RIGHT = 4,
            OBSCURITYTEST_FULL_HEIGHT_FORWARD = 5,
            OBSCURITYTEST_FULL_HEIGHT_BACK = 6,
            OBSCURITYTEST_NUM = 7
        };

        idVec3 GetDestination(const idAI2* ai,
            obscurityTest_t test) const;
        void Update(const idAI2* ai);
    };

    enum coverApproach_t : int {
        COVER_APPROACH_FORWARD = 0,
        COVER_APPROACH_LEFT = 1,
        COVER_APPROACH_RIGHT = 2,
        COVER_APPROACH_TURN_AROUND_LEFT = 3,
        COVER_APPROACH_TURN_AROUND_RIGHT = 4,
        COVER_APPROACH_WRAP_AROUND_LEFT = 5,
        COVER_APPROACH_WRAP_AROUND_RIGHT = 6,
        COVER_APPROACH_MAX = 7
    };

    class idAnimWebDefaults {
    public:
        idAnimWebDefaults();
        idAnimWebDefaults(const char* subWebName,
            const char* stateName, bool enabled);

        idAnimWebPath webPath;
        idList<int, 5> activeLayers;
        bool enabled;
    };

    class idAIVolatile {
    public:
        idAIVolatile();

        class idAIFocusInfo {
        public:
            idAIFocusInfo();

            std::array<int, 2> foci;
            float bodyMinimumTurnRate;
            float bodyMaximumTurnRate;
            idMat3 bodyAxis;
            bool enableHeadTracking;
            bool enableBodyRotation;
            bool enableAutoFocus;
            bool enableClosestFocus;
            idCheckSurroundingsState checkSurroundingsState;
        };

        idAIFocusInfo focus;
    };

    idAI2();
    virtual ~idAI2();

    void SetDebugText(const char* text, aiDebugLevel_t debugLevel);
    void ClearErrorFlags(int flags);
    static int GetDebugLevel();
    playerInteractionState_t GetCurrentPlayerInteractionTempInfoState() const;
    void SetCurrentPlayerInteractionTempInfoState(
        playerInteractionState_t newState);
    const aiPlayerInteraction_t* GetCurrentPlayerInteraction() const;
    void SetCurrentPlayerInteraction(
        const aiPlayerInteraction_t* interaction);
    bool CanIdleTrackFriendlyTarget(
        const idEntity* friendlyTarget) const;
    bool PlayerApproachingInteraction(idPlayer* player);
    void ExecuteThread(idThread* thread);
    bool AllThreadsAreFinished() const;
    bool IsExecutingScript() const;
    void RemoveFiber(idFiberHandle fiberHandle);
    void RemoveThread(idThreadHandle threadHandle);
    idThreadHandle GetThread(int index) const;
    int NumThreads() const;
    void ResetFSMWaitThreadIfPossible(idThread* thread);
    bool ForceFSMIntoExecutingCodeAction(const idEventDef& action);
    int AddThread(idThreadHandle threadHandle);
    int AddFiber(idFiberHandle fiberHandle);
    static void Job_DebugPrintf(const char* format, ...);
    const idDeclVoiceOver* Job_Approach(idEntity* player, bool playVoiceOver);
    const idDeclVoiceOver* Job_Offer(idEntity* player, bool playVoiceOver);
    const idDeclVoiceOver* Job_MessageVO(idEntity* player,
        bool playVoiceOver, bool checkAIType);
    const idDeclVoiceOver* Job_Complete(idEntity* player, bool playVoiceOver);
    const idDeclVoiceOver* Job_Failed(idEntity* player, bool playVoiceOver);
    const idDeclVoiceOver* Job_InProgress(idEntity* player, bool playVoiceOver);
    const idDeclVoiceOver* Job_Accepted(idEntity* player, bool playVoiceOver);
    const idDeclVoiceOver* Job_Declined(idEntity* player, bool playVoiceOver);
    bool Job_CompleteSavedJob(idPlayer* player);
    bool Job_AcceptSavedJob(idPlayer* player);
    playerInteractionState_t Job_GetPlayerInteractionState(
        const idPlayer* player) const;
    const idDeclVoiceOver* Job_PlayerLeft(idEntity* player,
        bool playVoiceOver);
    const idDeclVoiceOver* Job_End(idEntity* player, bool playVoiceOver);
    void ShowDebugDamageText(float baseDamage, float difficultyScale,
        float bodyDamage, float limbDamage, float armorDamage,
        float shieldDamage, float armorDamageScale,
        float armoredHealthDamageScale, float bleedThroughDamage,
        float excessDamage, float attitudeDamageScale,
        const idDamageGroup* damageGroup,
        const idVec3& impactPoint) const;

    void CalcTrajectories(const idVec3& start, const idVec3& destination,
        const idTypesafeNumber<float, secondUnique_t>* travelTimes,
        int numTravelTimes, idTrajectory_Parabolic* trajectories,
        bool deferred);
    bool CanThrowGrenade(aiSelectCondition_t condition) const;
    bool SelectThrowable(aiItemSelect_t selectorType,
        const idVec3& targetPosition, coverAction_t coverAction,
        idAIProjectileInfo& info) const;
    bool SelectAmmo(aiItemSelect_t selectorType, const idWeapon* weapon,
        const idVec3& targetPosition, coverAction_t coverAction,
        idAIProjectileInfo& info) const;
    bool WaitingOnTrajectoryTest() const;
    bool HasWaitingTrajectoryResults() const;
    void ClearTrajectoryResults();
    const idMD6Anim* GetAnimForOverride(overrideAnim_t overrideAnim) const;
    bool GetMuzzlePoint(idWeapon* weapon, idVec3& muzzlePosition,
        idMat3& muzzleAxis) const;
    bool GetLaserSightPoint(idWeapon* weapon, idVec3& laserPosition,
        idMat3& laserAxis) const;
    bool GetMinMaxRangedAttackDistancesForTargetPos(
        aiItemSelect_t selector, const idVec3& targetPosition,
        idAIProjectileInfo& projectileInfo, float& minimumRange,
        float& minimumOptimalRange, float& maximumOptimalRange,
        float& maximumRange) const;
    bool TestParabolicTrajectories(idAIProjectileInfo& info,
        const idCachedJoint* cachedJoint, const idVec3& origin,
        const idMat3& axis,
        idTypesafeNumber<float, secondUnique_t> minimumTime,
        idTypesafeNumber<float, secondUnique_t> maximumTime);
    static void TargetMovingPoint(const idVec3& launchPoint,
        float launchSpeed, const idVec3& targetPosition,
        const idVec3& targetVelocity,
        idTypesafeNumber<float, secondUnique_t> lagTime,
        idTypesafeNumber<float, secondUnique_t> animationDelay,
        idVec3& launchDirection, idVec3& predictedTargetPosition);
    bool LaunchParabolicProjectile(const idDeclProjectile* projectileDecl,
        const idTrajectory_Parabolic::parabolicParms_t& trajectory,
        const idVec3& targetPosition, const idVec3& startPosition,
        int startTime);
    bool LeadTargetWithLinearProjectile(const idAIProjectileInfo& info,
        const idVec3& currentTargetPosition,
        const idVec3& currentTargetVelocity,
        const idVec3& projectileStartPosition,
        idVec3& extrapolatedPosition,
        idVec3& directionToExtrapolatedPosition) const;
    bool LaunchLinearProjectile(const idDeclProjectile* projectileDecl,
        float speed, const idVec3& startPosition,
        const idVec3& targetPosition, const idVec3& launchDirection,
        int startTime);
    const idCachedJoint* GetModelSpaceJointTransformForAnimEvent(
        const idEventDef* eventDefinition, const idMD6Anim* animation,
        int cachedIndex, idVec3& jointOrigin, idMat3& jointAxis,
        idTypesafeNumber<int, millisecondUnique_t>& eventTime) const;
    const idCachedJoint* GetWorldSpaceJointTransformForAnimEvent(
        const idEventDef* eventDefinition, const idMD6Anim* animation,
        int cachedIndex, idVec3& worldOrigin, idMat3& worldAxis,
        idTypesafeNumber<int, millisecondUnique_t>& eventTime) const;
    const idCachedJoint* GetCachedMuzzlePointForAnimEvent(
        const idEventDef* eventDefinition, idWeapon* weapon,
        const idMD6Anim* animation, idVec3& muzzlePosition,
        idMat3& muzzleAxis,
        idTypesafeNumber<int, millisecondUnique_t>& eventTime) const;
    bool LaunchProjectile(const idEntity* target,
        const aiSenseState_t& senseState,
        idAIProjectileInfo& projectileInfo,
        const aiItemSelect_t& itemSelect);
    bool CheckGrenadeThrow(idAIProjectileInfo& info);

    overrideAnim_t GetEntranceAnim() const;
    void ApplyDamage(int physId, int bodyId,
        const idDeclDamage* damageDecl);
    void SetModelByName(const char* modelName);
    bool PerceptionFlagIsSet(int flags) const;
    void SaveFSM(idFile_String& file, const char* fsmName,
        const char* indent) const;
    void StartDeathFade();
    void ActivateItemsOnDeath();
    int GetValidMeleeTypes(int mask) const;
    float GetCrosshairIconDistance() const;
    bool CanReceiveAIEvents(int currentTime) const;
    int GetEventResponseFlags() const;
    bool RespondsToAIEvent(const idAIEvent* event) const;
    void DeactivateExtendedClipModel();
    bool ShouldAimAtEnemyWhileMoving() const;
    int BestDiveOrDodge(bool leftDodge, bool leftDive,
        bool rightDodge, bool rightDive, bool forwardDive,
        bool backwardDive, bool preferLeft) const;
    void SetMovePushStatus(aiMovePushStatus_t newStatus,
        int frameCount);
    void SetWorldCollision(bool collideWithWorld);
    float CalcTurnRadius(float speed, float turnRate) const;
    const idDeclFacialAnimationSet* GetFacialAnimationSet() const;
    void SetInteracting(bool interacting);
    bool Draw(idEntity* player);
    aiSubWeb_t AlertCycleToSubWeb(alertCycle_t cycle) const;
    const idFiniteStateMachine* GetAlertCycleFSM() const;
    idFiniteStateMachine* GetAlertCycleFSM();
    void SetEventOverloadEnableFlags(idAIEvent::aiEventClass_t flags);
    void SetEventOverloadDisableFlags(idAIEvent::aiEventClass_t flags);
    void EnableAIEventResponse(idAIEvent::aiEventClass_t flags);
    void DisableAIEventResponse(idAIEvent::aiEventClass_t flags);
    bool IsFSMActive(const idTypeInfo& fsmType) const;
    bool GetEnableHeadTracking() const;
    void SetCoverAction(coverAction_t action);
    void RememberCoverActionToAvoid(coverAction_t action);
    void SetIsRagdolling(bool isRagdolling);
    bool CheckForGoreByName(const idAtomicString& goreName);
    void ApplyWaterEffects(int physId, int bodyId);
    void InitEncounterGroup();
    bool UsesScenePoints() const;
    void Dropped(idEntity* user, const idDeclInventory* inventory);
    aiSkill_t GetModifiedSkill() const;
    void SetWalkState(walkState_t state);
    bool IsWeaponEquipped() const;
    const idWeapon* FindWeaponToDraw() const;
    aiAccuracy_t GetEffectiveAccuracy() const;
    void SetModel(idRenderModel* model);
    void InitNav();
    void InitMovement();
    void SetPerceptionFlags(int flags, bool setFlag);
    bool IsInAvoidFSM() const;
    bool IsInPlayerInteractFSM() const;
    void JobSync();
    bool ShouldLeaveDormancy() const;
    idEventArg InternalCallEvent(const idEventDef& event,
        const idEventArg* args);
    bool InternalRespondsTo(const idEventDef& event) const;
    bool CheckForOneShotKill(idEntity* attacker);
    idJointIndex GetJointIndexFromTrace(trace_t trace) const;
    void ApplyFakeDamageImpulse(const idVec3& impulse);
    void CheckPain(idEntity* inflictor, idEntity* attacker,
        const idDeclDamage* damageDecl, float damage,
        const idVec3& impactPoint, const idVec3& impactDirection,
        idJointIndex jointIndex);
    void DisableAnimatorsOnDeath();
    bool DoMeleeDamage(idJointIndex jointIndex,
        const idBounds& bounds, const idDeclDamage* damageDecl,
        const idDeclProjectileImpactEffect* impactEffect);
    bool CanMelee() const;
    void ExtrapolateMeleeTarget(const idVec3& targetPosition,
        const idVec3& targetVelocity, idVec3& attackPosition) const;
    bool IsTargetInMeleeRange(const idVec3& targetPosition,
        aiMelee_t meleeType) const;
    bool IsTargetInLeapAttackZone(const idVec3& targetPosition) const;
    int MeleePreference(const idEntity* target) const;
    walkState_t GetDesiredWalkStateForDistance(float distance,
        walkState_t maximumWalkState, bool firedAt) const;
    bool HasTauntRage() const;
    bool HasAngryRage() const;
    bool ProvidesFormationCover() const;
    float GetUsableDistance() const;
    bool TakedownWindoIsOpen() const;
    void SetTakeDownWindow(bool setOpen);
    bool PassMerchantTestCondition(
        const idAIEditable::idConditionalMerchantInventoryDef::
            merchantCondition_t& condition,
        const idPlayer* player) const;
    void AddConditionalGoodList(int index);
    bool ShouldAddDynamicGood(const idPlayer* player, int index) const;
    bool EverHasGoodsToSell(const idPlayer* player) const;
    bool HasGoodsToSellPlayerNeeds(const idPlayer* player) const;
    void SetupFakePosition(const idEntity* instigator,
        const idVec3& fakePosition);
    void OnAIEvent_VehicleSound(const idAIEventSound* event);
    void OnAIEvent_Body(const idAIEventSphere* event);
    void OnAIEvent_PlayerInteraction(const idAIEventSphere* event);
    idClipModel* ActivateExtendedClipModel(
        aiExtendedClipModelStatus_t status, int frameCount);
    void AimDebug(const char* text, int level) const;
    void LookDebug(const char* text, int level, int duration) const;
    idEncounterGroup* GetEncounterGroup();
    walkState_t GetWalkState() const;
    aiWalkModifier_t GetWalkModifier() const;
    aiWalkModifier_t GetRunModifier() const;
    void SetSolid(bool isSolid);
    void SetAimFocusEntity(const idEntity* entity, bool keepInView,
        aimPoint_t point, int timeout);
    void SetExplicitAimFocusPoint(const idVec3& point,
        bool keepInView, int timeout, aiFocus_t focusType);
    void SetAimFocusAimPoint(aimPoint_t point);
    void ReloadWeapon(idWeapon* weapon);
    void GetRepullTriggerInterval(const idWeapon* weapon,
        int& minimum, int& maximum) const;
    void GetBurstDuration(const idWeapon* weapon,
        int& minimum, int& maximum) const;
    void GetFireAtLastKnownDuration(const idWeapon* weapon,
        int& minimum, int& maximum);
    idVec3 GetEyeOffset() const;
    void SetEnableAutoFocus(bool enable);
    void SetSpeakingVO();
    void SetActionScript(const idList<idScriptAction, 5>& script,
        idEntity* scriptExecutor, idEntity* activator);
    void EndActionScript();
    void OnActionScriptFinished(int currentTime);
    void SetActionScriptFlag(int flags, bool setFlag);
    bool ActionScriptFlagIsSet(int flags) const;
    idAIActionFSM* GetActionFSM();
    idAIAction* GetCurrentAction() const;
    idFiniteStateMachine::fsmStatus_t GetActionStatus() const;
    bool IsIdling() const;
    void SetAlertCycle(alertCycle_t alertCycle);
    void SetIdealAimFocusPoint(const idVec3& point, int timeout,
        aiFocus_t focusType);
    void SetIdealLookFocusPoint(const idVec3& point, int timeout,
        aiFocus_t focusType);
    void ClearAimFocus();
    void ClearLookFocus();
    void SetEnableHeadTracking(bool enable);
    void SetSuppressHeadTracking(bool suppress);
    int GetRunCycleIndexForType(runIndexType_t type) const;
    int GetIdleIndexForType(runIndexType_t type) const;
    void PlayAnimWebPathPerfect(const idAnimWebPath& path,
        const idVec3& position, const idMat3& axis,
        bool forcedTransition, bool perfectDestination);
    idPresentable* AllocPresentable(idRenderModel* renderModel);
    void UpdateInfluenceTrail();
    bool IsOnElevator();
    idAnimator_AF::testSolidResult_t StartRagdoll(
        const idRagdollInfo& info);
    void StopRagdoll();
    idAIOrientation& GetMoveOrientation();
    idAIOrientation& GetBodyOrientation();
    void SetAxis(const idMat3& axis);
    bool IsMoveDone(bool checkAlignment);
    idAIMoveInterface& GetMoveInterface();
    idAnimWebPath GetEntranceAnimWebPath() const;
    bool CanFireRobot(int currentTime);
    void StopFireRobot(int currentTime);
    idHudBossInfo GetBossHudInfo();
    void SetAccuracy(aiAccuracy_t accuracy);
    void GetModelTransform(idVec3& modelOrigin,
        idMat3& modelAxis) const;
    void UpdateDrop();
    bool PlayAdditivePain(idEntity* inflictor, idPlayer* attacker,
        const idDeclDamage* damageDecl, float damage,
        const idVec3& impactPoint, const idVec3& impactDirection,
        idJointIndex jointIndex);
    void UpdateDeathCollision();
    aiDirection_t GetMeleeDirection(const idVec3& target,
        const idVec3& velocity, bool& narrowFront, bool debug) const;
    aiMelee_t GetMeleeTypeForTarget(const idVec3& targetPosition,
        const idVec3& targetVelocity, int meleeMask,
        int preferredMask) const;
    aiDirection_t GetDirectionTo(const idVec3& position) const;
    bool IsFacingMe(const idEntity* entity, float dotThreshold) const;
    bool AmIToEntitysLeft(const idEntity* entity) const;
    bool StartReloading(idAIFSM* fsm, idAIState* state,
        int currentTime, equipSlot_t reloadSlot);
    talkState_t GetTalkState(const idEntity* activator) const;
    void GetTakedownName(const idList<idStr, 5>& takedowns,
        idStr& takedownName);
    usableState_t GetUsableState(const idEntity* activator,
        const idFocusTrace& focusTrace) const;
    usableState_t GetOnlineUsableState() const;
    bool IsCrosshairSubdued(const idEntity* activator,
        const idFocusTrace& focusTrace, usableState_t usable) const;
    bool ShouldAddConditionalGoodList(const idPlayer* player,
        int index) const;
    bool IsMerchant(const idPlayer* player) const;
    void SetAnimWebEvent(aiAnimWeb_t web,
        idAnimWebEvent::priority_t priority,
        idAnimWebSubWebIndex subWebIndex,
        idAnimWebStateIndex stateIndex, animWebEvent_t eventType,
        const idEventDef& eventDefinition);
    void ClearAnimWebEvent(aiAnimWeb_t web,
        idAnimWebEvent::priority_t priority, animWebEvent_t eventType);
    void ClearAllAnimWebEvents(aiAnimWeb_t web,
        idAnimWebEvent::priority_t priority);
    void ClearWaitForOverrideAnim(idAnimWebEvent::priority_t priority);
    bool AnimEventReceived(idAnimWebEvent::priority_t priority) const;
    bool WaitForOverrideAnim(idAnimWebEvent::priority_t priority,
        overrideAnim_t overrideAnimation, animWebEvent_t eventType,
        bool force);
    bool WaitForAnimToEnd(idAnimWebEvent::priority_t priority,
        const char* subWebName, const char* stateName,
        animWebEvent_t eventType);
    bool WaitForAnimToStart(aiAnimWeb_t web,
        idAnimWebEvent::priority_t priority, const char* subWebName,
        const char* stateName, animWebEvent_t eventType);
    bool WaitForAnimToStartVia(aiAnimWeb_t web,
        idAnimWebEvent::priority_t priority,
        idAnimWebSubWebIndex destinationSubWeb,
        idAnimWebStateIndex destinationState,
        idAnimWebSubWebIndex viaSubWeb, idAnimWebStateIndex viaState,
        animWebEvent_t eventType);
    bool WaitForAnimToStartVia(aiAnimWeb_t web,
        idAnimWebEvent::priority_t priority, const char* subWebName,
        const char* stateName, const char* viaSubWebName,
        const char* viaStateName, animWebEvent_t eventType);
    void UpdateAttachments();
    idAAS2TravelSpeeds GetTravelSpeeds() const;
    bool UpdateExtendedClipModel();
    void ReleaseCover();
    void Debug_ScenePoints();
    bool CoverAvoidanceOptions(bool& dodgeRoomLeft,
        bool& diveRoomLeft, bool& dodgeCoverLeft,
        bool& diveCoverLeft, bool& dodgeRoomRight,
        bool& diveRoomRight, bool& dodgeCoverRight,
        bool& diveCoverRight, bool& diveRoomForward,
        bool& diveCoverForward, bool& diveRoomBack,
        bool& diveCoverBack, bool& coverByCrouching) const;
    void SetupDiveDodgeOrFlinchAction(aiMoveReason_t moveReason,
        idAIState* state, idAIFSM* fsm);
    bool CanHideHelmetGroupTest() const;
    idAIVoiceController* GetVoiceController(voiceController_t controller);
    float GetDefaultSpeedByCurrentWalkState() const;
    void GetViewTransform(idVec3& origin, idMat3& axis) const;
    float CalcMovementTurnRate(const idVec3& idealDirection,
        const idVec3& currentDirection) const;
    void Teleport(const idVec3& origin, const idAngles& angles);
    float RoleHintNodeScore(const idVec3& point,
        idAICombatHint::combatHintClass_t hintClass) const;
    void GetAnimationDelta(const idMD6Anim* animation,
        idVec3& delta) const;
    awPathResult_t PlayAnimWebPath(const idAnimWebPath& path,
        bool forceTransition);
    bool ShouldScramble() const;
    bool UpdateGoreLevel(bool painTest);
    bool RobotBatteryExplodes(idEntity* attacker);
    void OnActivateRobot(int currentTime, idEntity* activator);
    void OnActivate(idEntity* activator);
    void UpdateBodyOrientationWhileMoving();
    void UpdateBodyOrientationWhileMovingWithFSM();
    bool StartStaggeringPain(const idAIDamageInfo& information);
    bool StartStunningPain(const idAIDamageInfo& information);
    void DamageFeedback(idEntity* victim, idEntity* inflictor,
        const idDeclDamage* damageDecl, float& damage);
    bool EnemyTooCloseToGoProne(bool facingMatters,
        bool obscurityMatters) const;
    bool WantsToAngryRage() const;
    bool WantsToTauntRage() const;
    takedownMode_t CanBeTakenDown(const idEntity* activator) const;
    void PlayerInteractionDone(bool playerLeft);
    void AddDynamicGoods(idPlayer* player);
    bool AwareOfEnemy();
    bool IsBlockedByFriendly(const idEntity* enemy);
    float GetFakeEnemyWeight() const;
    void OnAIEvent_Investigate(const idAIEventSound* event);
    void OnAIEvent_PlayerAim(const idAIEvent_PlayerAim* event);
    void ReserveCover(const idAICover& cover);
    void SetLookFocusEntity(const idEntity* entity, bool keepFocusInView,
        aimPoint_t aimPoint, int timeout);
    const aiSenseState_t* GetEnemySenseState(aiSense_t senseType) const;
    bool IsEnemySenseStateValid(aiSense_t senseType) const;
    bool CheckForSuspectedToTrailUpdate(int currentTime);
    bool FindClosestFocus();
    alertCycle_t GetAlertCycle() const;
    void LeaveActionNode(bool force);
    static void RestartPlayerInteractions();
    void SetRunCycleHint(runIndexType_t runType);
    float GetCoverTransitionRadius(const idAICover& cover,
        bool desireScramble, bool desireMicro, idStr& animationName,
        float& yaw, idVec3& delta, int& frames) const;
    bool DamageRobot(idEntity* attacker, const idDeclDamage* damageDecl,
        trace_t* trace);
    void ThinkRobot(int currentTime);
    void Hide();
    bool ShouldDeadThink() const;
    bool ShouldEnterDormancy();
    void DamageGroupPopOffArmor(idDamageGroup* damageGroup,
        idVec3 impactPoint, idVec3 impactDirection, float damage,
        bool& armorPoppedOff);
    void KilledNotification(const idEntity* victim,
        const idEntity* inflictor, const idDeclDamage* damageDecl,
        float damage);
    bool IsFacingMeMoreThanAnyoneElse(const idEntity* entity,
        float dotThreshold) const;
    bool RelinquishControl();
    void Takedown(idEntity* activator, bool dualWield,
        bool reversedGrip, takedownMode_t mode);
    bool Use(idEntity* activator, usableState_t usable);
    void SetupInteractionView(idPlayer* player);
    void EndInteractionView(idPlayer* player);
    void InteractionCameraDeactivateCallback(idPlayer* player);
    void SetActionNodeGroupName(const char* groupName);
    void UpdateAvoidCharacter();
    void SetFakeEnemy(idEntity* entity);
    void ClearFakeEnemy();
    void ClearWorldState();
    void OnAIEvent_Voice(const idAIEventVoice* event);
    void OnAIEvent_Footstep(const idAIEventSound* event);
    void OnAIEvent_Gunfire(const idAIEventSound* event);
    void OnAIEvent_Explosion(const idAIEventSound* event);
    void OnAIEvent_ProjectileImpact(const idAIEventSound* event);
    void OnAIEvent_DeadBodyLand(const idAIEventSound* event);
    void OnAIEvent_DoorMotion(const idAIEventSound* event);
    void OnAIEvent_Projectile(const idAIEventProjectile* event);
    void OnAIEvent_Grenade(const idAIEventProjectedSphere* event);
    void OnAIEvent_Vehicle(const idAIEvent_Vehicle* event);
    bool StartMoveToCover(const idAICover& cover, idAIFSM* fsm,
        idAIState* state, bool allowInterrupt, int currentTime);
    void Debug_Perception();
    idAIStateTransition::aiTransCode_t ShouldDiveOrDodgeOrCrouch(
        const idAIFSM* fsm);
    void DormantBegin();
    float FindAutoFocusEntity(const idEntity*& entity);
    void StartActionScript(int currentTime);
    void GiveAwarenessOfEntity(const idEntity* entity,
        alertCycle_t alertCycle);
    void GiveAwarenessOfNearestPlayer(alertCycle_t alertCycle);
    void ForceOpenCombat(const idEntity* enemy);
    void ForcePlayerInteraction(const idEntity* entity);
    void ForceFollowFriendly(const idEntity* friendly);
    float PositionScore(const idVec3& candidatePosition,
        const aiSenseState_t* senseState, float& targetDistanceScore,
        float& aiDistanceScore, float& groupScore,
        float& hintNodeScore);
    static void Cmd_ForceFollow_f(const idCmdArgs& args);
    float Damage(idEntity* inflictor, idEntity* attacker,
        const idDeclDamage* damageDecl, float damageScale,
        const idVec3& direction, trace_t* trace);
    bool ModifyCrosshairInfo(const idEntity* activator,
        const idFocusTrace& focusTrace, usableState_t usable,
        idCrosshairInfo& crosshairInfo) const;
    void GetKnownEnemiesAsCoverTargets(
        idList<idCoverQuery::coverTarget_t, 5>& targets,
        aiAwareness_t minimumAwareness) const;
    void ForceEntranceAnimationToCombat();
    void ForceSearchToEntity(idEntity* entity);
    void ForceAwarenessOfNearestPlayer();
    void ForceSearchToNearestPlayer();
    void UpdateGroupStatusConditions();
    void InitMemory();
    void InitScriptObjects();
    void InitFSMs();
    void InitActionSettings();
    void InitFireControl();
    void UpdateMeleeCapabilities();
    bool EquipItem(idInventoryItem* item, equipSlot_t equipSlot);
    bool UnequipItem(idInventoryItem* item);
    void InitHeadTracking();
    void InitPhysics();
    void InitAAS();
    bool InitAnimation();
    void UpdateTravelFlags();
    void PlayAmbientSound(const idSoundShader* soundShader);
    void UpdateEffects();
    void UpdateMovement();
    void UpdateConfidenceLevel();
    void UpdatePathToEnemy(bool forceUpdate);
    bool CheckForGore();
    void UpdateWorldState();
    void OnAIEvent(const idAIEvent* event);
    void HandlePendingAIEvents();
    bool UpdateAnimationControllers();
    bool PathPassesNear(const idVec3& startPoint,
        const idVec3& goalPoint, int startAreaNum, int goalAreaNum,
        const idVec3& testPoint, int testAreaNum, float nearDistance,
        bool debug) const;
    bool TestFireWeapon(idWeapon* weapon, idFireParms& fireParms,
        idTestFireResults& results,
        const testFireWeaponParms_t& parameters);
    const idEntity* TestForBlockedTrace(const idFireParms& fireParms,
        const idTestFireResults& results, int& blockedJoint,
        const testForBlockedTraceParms_t& parameters) const;
    bool FinishFireWeapon(idWeapon* weapon,
        const idFireParms& fireParms, idTestFireResults& testResults,
        idFinishFireResults& finishResults);
    void UpdateAimFocus();
    void FindAutoFocus();
    void UpdateActions(int currentTime);
    idAICover PrepTakeCoverFromEntity(const idEntity* enemy,
        const idEntity* coverReference, const idEntity* coverTarget);
    void EnableInfluenceTrail(idEntityInfluenceTrail influenceTrail);

    void Spawn();
    virtual void Show();
    void UpdateFSMs();
    void StartDeathSystem();
    bool WaitForTraversal(idAnimWebEvent::priority_t priority,
        const char* traversalAnimRef, const char* destinationAnimRef,
        animWebEvent_t eventType);
    virtual void DormantEnd(int timeDormant);
    void UpdateLookFocus();
    void Think_PlayerControl();
    void ForceTakeCoverFromEntity(const idEntity* enemy,
        const idEntity* coverReference, const idEntity* coverTarget);
    void Think_AIControl();
    static void UpdateDeaths();
    void ForceTakeCoverFromNearestPlayer(
        const idEntity* coverReference, const idEntity* coverTarget);
    void DoSpawnSettings();
    void DropComplete();
    void FirstThink();
    virtual void Think();

    idAIEditable editable;
    idAIVolatile volatileState;
    idAI2CoreRuntime core;
};

idAI2::coverApproach_t CoverApproachForDirection(
    const idVec3& relativePosition, bool allowTurnAroundLeft,
    bool allowTurnAroundRight);
idStr GetCoverTransionAnimName(const idAICover& cover,
    idAI2::coverApproach_t approach, bool desireScramble,
    bool desireMicro);

class idAIScriptProxy {
public:
    explicit idAIScriptProxy(idAI2* owner = nullptr) : owner(owner) {}

    void PauseFiberTillActionCompletes(idFiberHandle fiberHandle);
    void PauseThreadTillActionCompletes(idThread* thread);
    void PauseCurrentThreadTillActionCompletes();
    void PauseCurrentFiberTillActionCompletes();
    bool ForceFSMIntoExecutingScript();
    idEventArg InternalCallEvent(const idEventDef& event,
        const idEventArg* args);

    idAI2* owner;
};

struct idAI2DebugRuntime {
    idAI2::aiDebugLevel_t textLevel;
    int errorFlags;
};

bool Tungsten_GetAI2DebugRuntime(
    const idAI2& ai, idAI2DebugRuntime& runtime);
void Tungsten_SetAI2DebugText(idAI2& ai,
    idAI2::aiDebugLevel_t level, const char* text);
void Tungsten_SetAI2ErrorFlags(idAI2& ai, int flags);
int Tungsten_GetAI2DebugLevelValue();
void AIStats_f(const idCmdArgs& args);
int Tungsten_GetAI2DebugHealthValue();
float Tungsten_GetAI2CurrentBaseHealth(const idAI2& ai);
bool Tungsten_GetAI2DamageGroupDebugInfo(const idDamageGroup& group,
    const char*& groupName, float& damageScale);
void Tungsten_DrawAI2DamageDebugText(const char* text,
    const idVec3& impactPoint, const idVec4& color,
    int durationMilliseconds, float scale);
void Tungsten_PrintAI2DebugText(const char* text);
