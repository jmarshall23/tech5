#include "game/decls/declaibehavior.h"

#include <algorithm>

namespace {

template<typename type>
void FillSkill(idSkillSetting<type>& setting, const type& value) {
    std::fill(setting.setting, setting.setting + 5, value);
}

} // namespace

// EA 0x82BBB778
idDeclAIBehaviorEvents::idDeclAIBehaviorEvents()
    : bodyEventDecl(nullptr)
    , electricDeathEventDecl(nullptr)
    , mutantAttackEventDecl(nullptr)
    , possessionEventDecl(nullptr)
    , deadBodyLandEventDecl(nullptr)
    , gotKilledVoiceEventDecl(nullptr)
    , sawSomethingVoiceEventDecl(nullptr)
    , heardSomethingVoiceEventDecl(nullptr)
    , memberKilledVoiceEventDecl(nullptr)
    , foundDeadBodyVoiceEventDecl(nullptr)
    , enemySightedVoiceEventDecl(nullptr)
    , injuredVOEventDecl(nullptr)
    , crapVOEventDecl(nullptr)
    , intimidatedVOEventDecl(nullptr)
    , enemyKilledVOEventDecl(nullptr)
    , losingBattleVOEventDecl(nullptr)
    , memberKilledVOEventDecl(nullptr) {
}

// EA 0x82BBBAA8
idDeclAIBehaviorVO::idDeclAIBehaviorVO()
    : search()
    , combat()
    , jobResponseInfo() {
    search.startFromCombat.controller = VC_GROUP;
    search.startFromCombat.playOnce = true;
    search.startFromCombat.dontPlayIfGroupDead = true;
}

// EA 0x82BBBCD8
idDeclAIBehavior::idDeclAIBehavior()
    : rolePreferenceOrder()
    , formations()
    , turnParms()
    , navpower() {
    traversalAimEvasionDuration = 0;
    traversalGunfireEvasionDuration = 0;
    traversalAttackTolerance = 0;
    traversalEvasionAimDist = 400.0f;
    traversalEvasionGunfireDist = 1024.0f;
    canUseTeleporters = false;
    canUseElevators = false;
    canUseLadders = false;
    canClimbBarriers = false;
    canDropOffBarriers = false;
    canClimbLedges = false;
    canDropOffLedges = false;
    canUseStairs = true;
    usesSearch = false;
    isVehicleChaser = false;
    useTurningCircles = false;
    hasBumpedReaction = false;
    canUseTraversalEvasions = false;
    canUseTraversals = false;
    canSwim = false;
    canJump = false;
    usesOnElevator = false;
    usesBackStand = false;
    usesPanic = false;
    usesAvoidCower = false;
    usesAvoidDive = false;
    usesAvoidCover = false;
    usesAvoidRun = false;
    usesAvoid = false;
    reservedTraversal = 0;
    usesCombatLookFocusRelaxed = false;
    usesCombatLookFocus = false;
    canBeTagged = false;

    damageBehaviors = {};
    damageBehaviors.staggerThresholdStanding = 0.25f;
    damageBehaviors.staggerThresholdWalking = 0.25f;
    damageBehaviors.staggerThresholdRunning = 0.25f;
    damageBehaviors.minStaggerPainInterval = 1000;
    damageBehaviors.movingPainSpeed = 50.0f;
    damageBehaviors.movingDeathSpeed = 50.0f;
    damageBehaviors.slowMovingDeathSpeed = 50.0f;
    damageBehaviors.injuredRunThreshold = 0.5f;
    damageBehaviors.injuredChance = 100;
    damageBehaviors.injuredDontMoveCount = 2;
    damageBehaviors.hasBlood = true;
    damageBehaviors.usesRechargeHints = false;
    damageBehaviors.hasDeathIntensities = true;
    damageBehaviors.hasMovingDeathAnims = true;
    damageBehaviors.hasDeathAnims = false;
    damageBehaviors.hasMovingPainAnims = true;
    damageBehaviors.hasAdditivePains = true;
    damageBehaviors.canTakeDamage = true;
    damageBehaviors.reserved = 0;
    damageBehaviors.fourDirExplosionPain = false;
    damageBehaviors.usesExplosionPains = true;
    damageBehaviors.ignoreDeathRagdoll = false;
    damageBehaviors.deathStopsAmbientSound = true;
    damageBehaviors.explodesOnStrike = false;
    damageBehaviors.canRocketsImpale = false;
    damageBehaviors.shieldChargeThreshold = 0.0f;
    damageBehaviors.shieldBackOnThreshold = 1.0f;
    damageBehaviors.injuredRunMode = 0;
    FillSkill(damageBehaviors.difficultyDamageScale, 1.0f);

    usesStrafeApproach = false;
    usesSneakUpOnEnemy = false;
    usesMelee = true;
    usesOpenCombat = false;
    usesFallback = false;
    usesAdvance = false;
    usesScenePoints = false;
    usesCombat = true;
    reservedCombat = 0;
    subtitlesInCombat = false;
    usesShootIdle = false;
    dontLeaveTurretsEasily = false;
    usesTurrets = true;
    weaponSlot = 2;
    friendlyAttitudeAdjust = -0.5f;
    neutralAttitudeAdjust = -0.5f;
    attitudeAdjust = -0.5f;
    FillSkill(throwLag, 0.1f);
    FillSkill(maxThrowError, 0.0f);
    itemSelect[0] = itemSelect[1] = itemSelect[2] = 0;
    muzzleTraceClearOffset = 0.0f;
    minThrowDot = 0.0f;
    combatAmmo = nullptr;
    aimOffset = 0.0f;

    movementBehaviors = {};
    movementBehaviors.crouchMoveMax = 128.0f;
    movementBehaviors.injuredCrouchMoveMax = 256.0f;
    movementBehaviors.runMoveMin = 128.0f;
    movementBehaviors.sprintMoveMin = 2048.0f;
    movementBehaviors.coverCrouchPathTime = 500;
    movementBehaviors.coverRunPathTime = 500;
    movementBehaviors.coverSprintPathTime = 8000;
    movementBehaviors.fireRunningToCoverChance = 100;
    movementBehaviors.cornerCircleRadius = 32.0f;
    movementBehaviors.alignToPointDistance = 64.0f;
    movementBehaviors.strafeMoveToEntity = true;
    movementBehaviors.useOldAlignToPoint = true;

    followFriendlyThreshold = idRelationship::ATTITUDE_LOVE;
    lookAtFriendlyTarget = false;
    chasesProjectiles = true;
    canGreetPlayers = false;
    canGreetHumans = true;
    investigatesBody = false;
    FillSkill(takeCoverBehaviors.maxWaitTimeAfterReachingCover, 1000);
    FillSkill(takeCoverBehaviors.minWaitInCoverTime, 1000);
    FillSkill(takeCoverBehaviors.maxWaitInCoverTime, 5000);
    FillSkill(takeCoverBehaviors.usesForwardCover, false);
    FillSkill(takeCoverBehaviors.usesBackwardCover, false);
    hasCrouches = false;
    has157Turns = false;
    hasCombatSprints = false;
    hasWalkInserts = false;
    hasSyncedWalks = false;
    hasCombatWalks = false;
    canRetreat = false;
    canCharge = false;
    reservedCover = 0;
    hasBackStandLerps = false;

    doubleBlinkChance = 25;
    doubleBlinkInterval = 300;
    minBlinkInterval = 2500;
    maxBlinkInterval = 10000;
    jitterMinInterval = 100;
    jitterMaxInterval = 1500;
    runTypeBehaviors = {-1, -1, -1, -1, -1, -1, -1,
        0.0f, 0.0f, 0.05f};
    idleBehaviors = {0, 0, 0};
    openCombatDuration = 5.0f;
    exposeCoverDistance = 500.0f;
    exposeCoverMinDistance = 256.0f;
    optimalCoverDistance = 360.0f;
    exposeCoverTravelTime = 0.5f;
    exposeCoverOpenCombatChance = 100;
    coverPathNearDistance = 256.0f;
    minFireFromCoverDuration = 2500;
    maxFireFromCoverDuration = 10000;
    repeatExposeCoverChargeTime = 5000;
    friendlyFireThreshold = idRelationship::ATTITUDE_NEUTRAL;
    freeAmmoDistance = 128.0f;

    rageBehaviors = {};
    rageBehaviors.minRageInterval = 4000;
    rageBehaviors.maxRageInterval = 8000;
    rageBehaviors.staleTauntRageThreshold = 2000;
    rageBehaviors.staleAngryRageThreshold = 3000;
    rageBehaviors.useGroupRageLimit = true;
    rageBehaviors.minRageFacingDot = 0.5f;
    enemyTooCloseToGoProne = 250.0f;
    enemyTooCloseToGoProneFacing = 400.0f;
    closeMeleeDist = 80.0f;
    mediumMeleeDist = 0.0f;
    longMeleeDist = 0.0f;
    movingMeleeDist = 0.0f;
    minCloseMeleeInterval = 2000;
    maxCloseMeleeInterval = 5000;
    meleeExtrapolate = 0.25f;
    closeMeleeKickDamage = nullptr;
    closeMeleePunchDamage = nullptr;
    meleeImpactEffect = nullptr;
    meleeFromStunChance = 50;
    stunIgnoreTime = 5000;
    leapAttackChance = 0;
    minLeapAttackInterval = 3000;
    maxLeapAttackInterval = 8000;
    maxLeapAttackDistance = 256.0f;
    minLeapAttackDistance = 128.0f;
    leapAttackTargetExtrapolate = 1.0f;
    leapAttackSpeed = 320.0f;
    backstandBehaviors = {110.0f, 164.0f, 128.0f, 128.0f,
        200.0f, 96.0f, 0.75f};
    intimidation = {0, 4, 0, 3, 10000, 0.0f, 0.0f, 0.5f,
        0.5f, 0.5f, 0.75f, 2.0f, 1.0f, 2.0f, 2.0f, 1.0f,
        512.0f};
    clanDistinctionBehaviors.reserved = 0;
    clanDistinctionBehaviors.dodgeOnlyAfterMemberKilled = false;
    clanDistinctionBehaviors.fallbackVo = true;
    clanDistinctionBehaviors.retreatVo = true;
    clanDistinctionBehaviors.advanceVo = true;
    clanDistinctionBehaviors.coveringFire = true;

    maxChargeDuration = 5000;
    minChargeInterval = 5000;
    maxChargeInterval = 15000;
    chargeChance = 1;
    minChargeDistance = 100.0f;
    maxChargeDistance = 100000.0f;
    dodging = {};
    FillSkill(dodging.aimForwardDiveChance, 0);
    dodging.tooCloseDist = 250.0f;
    dodging.closeRangeDist = 600.0f;
    dodging.mediumRangeDist = 1024.0f;
    dodging.sidestepDistance = 64.0f;
    dodging.diveDistance = 160.0f;
    dodging.mustBeDirectTarget = true;
    dodging.lightFiredAtAngle = 11.5f;
    dodging.mediumFiredAtAngle = 11.5f;
    dodging.heavyFiredAtAngle = 11.5f;
    meleeDodgeChance = 50;
    minMeleeDodgeInterval = 1000;
    maxMeleeDodgeInterval = 1000;
    noticeGrenadeChance = 100.0f;
    minThrowInterval = 5000;
    maxThrowInterval = 5000;
    minOCThrowInterval = 0;
    maxOCThrowInterval = 0;
    minCoverDuration = 2000;
    maxCoverDuration = 3000;
    noContactInterval = 10000;
    breakCoverDuration = 25000;
    combatTimeoutInterval = -1;
    searchTimeoutInterval = -1;
    obstacleStopDistance = 80;
    surroundRadius = 400;
    minControlTime = 15000;
    maxControlTime = 15000;
    controlIntroDuration = 1500;
    controlSelfDamage = nullptr;
    controlSplashDamage = nullptr;
    controlEndParticle = nullptr;
    berzerkerFaction = nullptr;
    bfgDeathParticle = nullptr;
    dynamicCoverCaps.reserved = 0;
    dynamicCoverCaps.providesFormationCover = false;
    dynamicCoverCaps.usesFormationCover = false;
    dynamicCoverCaps.usesVehicleCover = false;
}

// EA 0x82BBC7B0
idDeclAIBehaviorVOChains::idDeclAIBehaviorVOChains()
    : combatVoChains() {
}

