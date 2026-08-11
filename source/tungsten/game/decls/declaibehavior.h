#pragma once

#include "decls/decltypeinfo.h"
#include "game/ai/aivoicecontroller.h"
#include "game/ai/cover/covercapabilities.h"
#include "game/ai/skillsetting.h"
#include "game/decls/decljobref.h"
#include "game/decls/relationship_core.h"
#include "game/navpower/navpowermover.h"
#include "idlib/containers/staticlist.h"

#include <cstdint>

class idDeclAiEvent;
class idDeclAmmo;
class idDeclAITurnParms;
class idDeclDamage;
class idDeclEntityDef;
class idDeclFaction;
class idDeclParticle;
class idDeclProjectileImpactEffect;
class idDeclVoiceOver;

// The authored formation payload is held indirectly by idList here; these
// fields are the reflected flag byte locations retained by the retail type.
struct idAIFormation {
    unsigned char opaque[32]{};
    unsigned char reserved : 6;
    unsigned char canFollow : 1;
    unsigned char canLead : 1;
};

struct idVOChain {
    idStr name;
};

class idDeclAIBehavior : public idDeclTypeInfo {
public:
    struct idDamageBehaviors {
        float twitchThresholdStanding;
        float staggerThresholdStanding;
        float twitchThresholdWalking;
        float staggerThresholdWalking;
        float twitchThresholdRunning;
        float staggerThresholdRunning;
        int minStaggerPainInterval;
        float movingPainSpeed;
        float movingDeathSpeed;
        float slowMovingDeathSpeed;
        float injuredRunThreshold;
        int injuredChance;
        int injuredDontMoveCount;
        float groundBleedRate;
        float standingBleedRate;
        const idDeclDamage* bleedOutDamageDecl;
        idSkillSetting<float> difficultyDamageScale;
        std::uint8_t hasBlood : 1;
        std::uint8_t usesRechargeHints : 1;
        std::uint8_t hasDeathIntensities : 1;
        std::uint8_t hasMovingDeathAnims : 1;
        std::uint8_t hasDeathAnims : 1;
        std::uint8_t hasMovingPainAnims : 1;
        std::uint8_t hasAdditivePains : 1;
        std::uint8_t canTakeDamage : 1;
        std::uint8_t reserved : 2;
        std::uint8_t fourDirExplosionPain : 1;
        std::uint8_t usesExplosionPains : 1;
        std::uint8_t ignoreDeathRagdoll : 1;
        std::uint8_t deathStopsAmbientSound : 1;
        std::uint8_t explodesOnStrike : 1;
        std::uint8_t canRocketsImpale : 1;
        const idDeclEntityDef* explosionEntity;
        const idDeclEntityDef* lootBox;
        float shieldChargeThreshold;
        float shieldBackOnThreshold;
        int injuredRunMode;
    };

    struct idMovementBehaviors {
        float crouchMoveMax;
        float injuredCrouchMoveMax;
        float runMoveMin;
        float sprintMoveMin;
        int coverCrouchPathTime;
        int coverRunPathTime;
        int coverSprintPathTime;
        int fireRunningToCoverChance;
        float cornerCircleRadius;
        float alignToPointDistance;
        std::uint8_t allowEnemySightedCrouchIdle : 1;
        std::uint8_t enemyCloseObscurityTest : 1;
        std::uint8_t strafeMoveToEntity : 1;
        std::uint8_t runFacingForward : 1;
        std::uint8_t useOldAlignToPoint : 1;
        std::uint8_t allowTransitionOvershoot : 1;
        std::uint8_t crouchWhenStill : 1;
        std::uint8_t runsIfShotAt : 1;
        std::uint8_t reserved : 7;
        std::uint8_t obstacleAvoidIgnorePlayer : 1;
    };

    struct idTakeCoverBehaviors {
        idSkillSetting<int> maxWaitTimeAfterReachingCover;
        idSkillSetting<int> minWaitInCoverTime;
        idSkillSetting<int> maxWaitInCoverTime;
        idSkillSetting<bool> usesForwardCover;
        idSkillSetting<bool> usesBackwardCover;
    };

    struct idRunTypeBehaviors {
        int scrambleRunIndex;
        int gunDownIndex;
        int downStairsIndex;
        int upStairsIndex;
        int narrowIndex;
        int duckIndex;
        int farRunIndex;
        float minFarRunDistance;
        float maxFarRunDistance;
        float blendRate;
    };

    struct idIdleBehaviors { int gunDownIndex; int narrowIndex; int duckIndex; };
    struct idRageBehaviors {
        int angryRageAfterHurtChance;
        int angryRageAfterMissingChance;
        int angryRageAfterAttractChance;
        float angryRageWhenCloseDistance;
        int tauntRageAfterHitEnemyChance;
        int tauntRageBehindEnemyChance;
        int tauntRageFleeingEnemyChance;
        int tauntRageAfterKillingEnemyChance;
        int minRageInterval;
        int maxRageInterval;
        int staleAngryRageThreshold;
        int staleTauntRageThreshold;
        bool useGroupRageLimit;
        float minRageFacingDot;
    };
    struct idBackstandBehaviors {
        float approachDistance;
        float riseDistance;
        float commitDistance;
        float attackReach;
        float standReach;
        float groundReach;
        float riseTime;
    };
    struct idAIIntimidationBehaviors {
        int minConfidenceLevel;
        int maxConfidenceLevel;
        int intimidationConfidence;
        int minTauntConfidence;
        int minIntimidationTime;
        float healthFactor;
        float avoidFactor;
        float firedAtFactor;
        float heavyFiredAtFactor;
        float recentlyKilledGroupMemberFactor;
        float recentHeavilyKilledGroupMemberFactor;
        float recentlyKilledHeaviesFactor;
        float injured;
        float heavyConfidenceBoost;
        float deadGroupMemberCap;
        float closeEnemyFactor;
        float closeEnemyDist;
    };
    struct idAIClanDistinctionBehaviors {
        std::uint8_t reserved : 3;
        std::uint8_t dodgeOnlyAfterMemberKilled : 1;
        std::uint8_t fallbackVo : 1;
        std::uint8_t retreatVo : 1;
        std::uint8_t advanceVo : 1;
        std::uint8_t coveringFire : 1;
    };
    struct idAIDodgingBehaviors {
        int gunfireDodgeCoverChance;
        int gunfireDodgeNoCoverChance;
        int aimDodgeCoverChance;
        int aimHeavyDodgeNoCoverChance;
        int painDiveCoverChance;
        int painDiveNoCoverChance;
        int gunfireHeavyDiveCoverChance;
        int gunfireHeavyDiveNoCoverChance;
        int aimHeavyDiveCoverChance;
        int aimHeavyDiveNoCoverChance;
        int gunfireFlinchChance;
        int gunfireLightDiveNoCoverChance;
        int aimLightDiveNoCoverChance;
        int gunfireForwardDiveChance;
        idSkillSetting<int> aimForwardDiveChance;
        int avoidDiveChance;
        int avoidForwardDiveChance;
        float tooCloseDist;
        float closeRangeDist;
        float mediumRangeDist;
        int aimCoverHideChance;
        int aimHeavyCoverHideChance;
        int gunfireCoverHideChance;
        int damageCoverHideChance;
        bool onlyCoverHideNoHelmet;
        int gunfireHideBailChance;
        int damageHideBailChance;
        int damageHideBailMaxChance;
        int minAimDodgeInterval;
        int maxAimDodgeInterval;
        float sidestepDistance;
        float diveDistance;
        bool mustBeDirectTarget;
        float lightFiredAtAngle;
        float mediumFiredAtAngle;
        float heavyFiredAtAngle;
        bool disableHintNodeUnderFire;
    };
    struct idForwardCoverCaps {
        idAICoverCapabilities meleeCoverCaps;
        idAICoverCapabilities pistolCoverCaps;
        idAICoverCapabilities rifleCoverCaps;
    };
    using idBackwardCoverCaps = idForwardCoverCaps;
    struct idDynamicCoverCaps {
        std::uint8_t reserved : 5;
        std::uint8_t providesFormationCover : 1;
        std::uint8_t usesFormationCover : 1;
        std::uint8_t usesVehicleCover : 1;
    };

    idDeclAIBehavior();
    ~idDeclAIBehavior() override = default;
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    int traversalAimEvasionDuration;
    int traversalGunfireEvasionDuration;
    int traversalAttackTolerance;
    float traversalEvasionAimDist;
    float traversalEvasionGunfireDist;
    std::uint8_t canUseTeleporters : 1;
    std::uint8_t canUseElevators : 1;
    std::uint8_t canUseLadders : 1;
    std::uint8_t canClimbBarriers : 1;
    std::uint8_t canDropOffBarriers : 1;
    std::uint8_t canClimbLedges : 1;
    std::uint8_t canDropOffLedges : 1;
    std::uint8_t canUseStairs : 1;
    std::uint8_t usesSearch : 1;
    std::uint8_t isVehicleChaser : 1;
    std::uint8_t useTurningCircles : 1;
    std::uint8_t hasBumpedReaction : 1;
    std::uint8_t canUseTraversalEvasions : 1;
    std::uint8_t canUseTraversals : 1;
    std::uint8_t canSwim : 1;
    std::uint8_t canJump : 1;
    std::uint8_t usesOnElevator : 1;
    std::uint8_t usesBackStand : 1;
    std::uint8_t usesPanic : 1;
    std::uint8_t usesAvoidCower : 1;
    std::uint8_t usesAvoidDive : 1;
    std::uint8_t usesAvoidCover : 1;
    std::uint8_t usesAvoidRun : 1;
    std::uint8_t usesAvoid : 1;
    std::uint8_t reservedTraversal : 5;
    std::uint8_t usesCombatLookFocusRelaxed : 1;
    std::uint8_t usesCombatLookFocus : 1;
    std::uint8_t canBeTagged : 1;
    idDamageBehaviors damageBehaviors;
    std::uint8_t usesStrafeApproach : 1;
    std::uint8_t usesSneakUpOnEnemy : 1;
    std::uint8_t usesMelee : 1;
    std::uint8_t usesOpenCombat : 1;
    std::uint8_t usesFallback : 1;
    std::uint8_t usesAdvance : 1;
    std::uint8_t usesScenePoints : 1;
    std::uint8_t usesCombat : 1;
    std::uint8_t reservedCombat : 4;
    std::uint8_t subtitlesInCombat : 1;
    std::uint8_t usesShootIdle : 1;
    std::uint8_t dontLeaveTurretsEasily : 1;
    std::uint8_t usesTurrets : 1;
    int weaponSlot;
    float friendlyAttitudeAdjust;
    float neutralAttitudeAdjust;
    float attitudeAdjust;
    idSkillSetting<float> throwLag;
    idSkillSetting<float> maxThrowError;
    int itemSelect[3];
    float muzzleTraceClearOffset;
    float minThrowDot;
    idDeclAmmo* combatAmmo;
    float aimOffset;
    idMovementBehaviors movementBehaviors;
    idList<int, 5> rolePreferenceOrder;
    idRelationship::attitude_t followFriendlyThreshold;
    bool lookAtFriendlyTarget;
    bool chasesProjectiles;
    bool canGreetPlayers;
    bool canGreetHumans;
    bool investigatesBody;
    idTakeCoverBehaviors takeCoverBehaviors;
    std::uint8_t hasCrouches : 1;
    std::uint8_t has157Turns : 1;
    std::uint8_t hasCombatSprints : 1;
    std::uint8_t hasWalkInserts : 1;
    std::uint8_t hasSyncedWalks : 1;
    std::uint8_t hasCombatWalks : 1;
    std::uint8_t canRetreat : 1;
    std::uint8_t canCharge : 1;
    std::uint8_t reservedCover : 7;
    std::uint8_t hasBackStandLerps : 1;
    std::uint8_t doubleBlinkChance;
    std::int16_t doubleBlinkInterval;
    std::int16_t minBlinkInterval;
    std::int16_t maxBlinkInterval;
    std::int16_t jitterMinInterval;
    std::int16_t jitterMaxInterval;
    idRunTypeBehaviors runTypeBehaviors;
    idIdleBehaviors idleBehaviors;
    float openCombatDuration;
    float exposeCoverDistance;
    float exposeCoverMinDistance;
    float optimalCoverDistance;
    float exposeCoverTravelTime;
    int exposeCoverOpenCombatChance;
    float coverPathNearDistance;
    int minFireFromCoverDuration;
    int maxFireFromCoverDuration;
    int repeatExposeCoverChargeTime;
    idRelationship::attitude_t friendlyFireThreshold;
    float freeAmmoDistance;
    idRageBehaviors rageBehaviors;
    float enemyTooCloseToGoProne;
    float enemyTooCloseToGoProneFacing;
    float closeMeleeDist;
    float mediumMeleeDist;
    float longMeleeDist;
    float movingMeleeDist;
    int minCloseMeleeInterval;
    int maxCloseMeleeInterval;
    float meleeExtrapolate;
    const idDeclDamage* closeMeleeKickDamage;
    const idDeclDamage* closeMeleePunchDamage;
    const idDeclProjectileImpactEffect* meleeImpactEffect;
    int meleeFromStunChance;
    int stunIgnoreTime;
    int leapAttackChance;
    int minLeapAttackInterval;
    int maxLeapAttackInterval;
    float maxLeapAttackDistance;
    float minLeapAttackDistance;
    float leapAttackTargetExtrapolate;
    float leapAttackSpeed;
    idBackstandBehaviors backstandBehaviors;
    idAIIntimidationBehaviors intimidation;
    idAIClanDistinctionBehaviors clanDistinctionBehaviors;
    int maxChargeDuration;
    int minChargeInterval;
    int maxChargeInterval;
    int chargeChance;
    float minChargeDistance;
    float maxChargeDistance;
    idAIDodgingBehaviors dodging;
    int meleeDodgeChance;
    int minMeleeDodgeInterval;
    int maxMeleeDodgeInterval;
    float noticeGrenadeChance;
    int minThrowInterval;
    int maxThrowInterval;
    int minOCThrowInterval;
    int maxOCThrowInterval;
    int minCoverDuration;
    int maxCoverDuration;
    int noContactInterval;
    int breakCoverDuration;
    int combatTimeoutInterval;
    int searchTimeoutInterval;
    int obstacleStopDistance;
    int surroundRadius;
    int minControlTime;
    int maxControlTime;
    int controlIntroDuration;
    const idDeclDamage* controlSelfDamage;
    const idDeclDamage* controlSplashDamage;
    const idDeclParticle* controlEndParticle;
    const idDeclFaction* berzerkerFaction;
    const idDeclParticle* bfgDeathParticle;
    idForwardCoverCaps forwardCoverCaps;
    idBackwardCoverCaps backwardCoverCaps;
    idDynamicCoverCaps dynamicCoverCaps;
    idList<idAIFormation, 5> formations;
    idStaticList<const idDeclAITurnParms*, 3> turnParms;
    idAINavPowerMoverParms navpower;

    static idDeclInfoTemplate<idDeclAIBehavior> resourceList;
};

class idDeclAIBehaviorVO : public idDeclTypeInfo {
public:
    struct idVoiceSearch { idVoiceInfo startFromCombat; };
    struct idVoiceCombat {
        idVoiceInfo changePosition;
        idVoiceInfo firstSpot;
        idVoiceInfo reSpot;
        idVoiceInfo flankSpot;
        idVoiceInfo downed;
        idVoiceInfo losingBattle;
        idVoiceInfo reload;
        idVoiceInfo fightMotivation;
        idVoiceInfo fightMotivationResponse;
    };
    struct jobResponseInfo_t {
        idDeclJobRef jobDecl;
        const idDeclVoiceOver* voiceOver;
    };

    idDeclAIBehaviorVO();
    ~idDeclAIBehaviorVO() override = default;
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    idVoiceSearch search;
    idVoiceCombat combat;
    idList<jobResponseInfo_t, 5> jobResponseInfo;
    static idDeclInfoTemplate<idDeclAIBehaviorVO> resourceList;
};

class idDeclAIBehaviorVOChains : public idDeclTypeInfo {
public:
    idDeclAIBehaviorVOChains();
    ~idDeclAIBehaviorVOChains() override = default;
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    idList<idVOChain, 5> combatVoChains;
    static idDeclInfoTemplate<idDeclAIBehaviorVOChains> resourceList;
};

class idDeclAIBehaviorEvents : public idDeclTypeInfo {
public:
    idDeclAIBehaviorEvents();
    ~idDeclAIBehaviorEvents() override = default;
    idDeclInfo* GetDeclInfo() const override { return &resourceList; }

    const idDeclAiEvent* bodyEventDecl;
    const idDeclAiEvent* electricDeathEventDecl;
    const idDeclAiEvent* mutantAttackEventDecl;
    const idDeclAiEvent* possessionEventDecl;
    const idDeclAiEvent* deadBodyLandEventDecl;
    const idDeclAiEvent* gotKilledVoiceEventDecl;
    const idDeclAiEvent* sawSomethingVoiceEventDecl;
    const idDeclAiEvent* heardSomethingVoiceEventDecl;
    const idDeclAiEvent* memberKilledVoiceEventDecl;
    const idDeclAiEvent* foundDeadBodyVoiceEventDecl;
    const idDeclAiEvent* enemySightedVoiceEventDecl;
    const idDeclAiEvent* injuredVOEventDecl;
    const idDeclAiEvent* crapVOEventDecl;
    const idDeclAiEvent* intimidatedVOEventDecl;
    const idDeclAiEvent* enemyKilledVOEventDecl;
    const idDeclAiEvent* losingBattleVOEventDecl;
    const idDeclAiEvent* memberKilledVOEventDecl;
    static idDeclInfoTemplate<idDeclAIBehaviorEvents> resourceList;
};
