
// ========================================================================
// ??0idDeclAIBehaviorEvents@@QAA@XZ
// EA  : 0x82BBB778
// RVA : 0x00BBB778
// PDB : w:\tech5\tungsten\game\decls\declaibehavior.cpp
// ========================================================================

idDeclAIBehaviorEvents *__fastcall idDeclAIBehaviorEvents::idDeclAIBehaviorEvents(idDeclAIBehaviorEvents *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->bodyEventDecl = nullptr;
  this->__vftable = (idDeclAIBehaviorEvents_vtbl *)&idDeclAIBehaviorEvents::`vftable';
  this->electricDeathEventDecl = nullptr;
  this->mutantAttackEventDecl = nullptr;
  this->possessionEventDecl = nullptr;
  this->deadBodyLandEventDecl = nullptr;
  this->gotKilledVoiceEventDecl = nullptr;
  this->sawSomethingVoiceEventDecl = nullptr;
  this->heardSomethingVoiceEventDecl = nullptr;
  this->memberKilledVoiceEventDecl = nullptr;
  this->foundDeadBodyVoiceEventDecl = nullptr;
  this->enemySightedVoiceEventDecl = nullptr;
  this->injuredVOEventDecl = nullptr;
  this->crapVOEventDecl = nullptr;
  this->intimidatedVOEventDecl = nullptr;
  this->enemyKilledVOEventDecl = nullptr;
  this->losingBattleVOEventDecl = nullptr;
  this->memberKilledVOEventDecl = nullptr;
  return this;
}


// ========================================================================
// ??0idDeclAIBehaviorVO@@QAA@XZ
// EA  : 0x82BBBAA8
// RVA : 0x00BBBAA8
// PDB : w:\tech5\tungsten\game\decls\declaibehavior.cpp
// ========================================================================

idDeclAIBehaviorVO *__fastcall idDeclAIBehaviorVO::idDeclAIBehaviorVO(idDeclAIBehaviorVO *this)
{
  char v2; // r7

  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclAIBehaviorVO_vtbl *)&idDeclAIBehaviorVO::`vftable';
  v2 = *((_BYTE *)&this->search.startFromCombat + 25);
  this->search.startFromCombat.shader = nullptr;
  this->search.startFromCombat.voiceOver = nullptr;
  this->search.startFromCombat.priority = AIVOICEPRIORITY_NONE;
  this->search.startFromCombat.interval = 0;
  this->search.startFromCombat.intervalMax = 0;
  this->search.startFromCombat.controller = VC_GROUP;
  this->search.startFromCombat.playChance = 100;
  *((_BYTE *)&this->search.startFromCombat + 25) = v2 | 0xC0;
  idDeclAIBehaviorVO::idVoiceCombat::idVoiceCombat(this: &this->combat);
  this->jobResponseInfo.granularity = 0;
  this->jobResponseInfo.listStatic = 0;
  this->jobResponseInfo.memTag = 5;
  this->jobResponseInfo.list = nullptr;
  this->jobResponseInfo.size = 0;
  this->jobResponseInfo.num = 0;
  return this;
}


// ========================================================================
// __unwind$489021
// EA  : 0x82BBBB3C
// RVA : 0x00BBBB3C
// PDB : w:\tech5\tungsten\game\decls\declaibehavior.cpp
// ========================================================================

void _unwind_489021()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 128 + 148));
}


// ========================================================================
// ??0idDeclAIBehavior@@QAA@XZ
// EA  : 0x82BBBCD8
// RVA : 0x00BBBCD8
// PDB : w:\tech5\tungsten\game\decls\declaibehavior.cpp
// ========================================================================

idDeclAIBehavior *__fastcall idDeclAIBehavior::idDeclAIBehavior(idDeclAIBehavior *this)
{
  char v2; // r5
  char v3; // r4
  int v4; // r10
  int v5; // ctr
  int v6; // ctr
  int v7; // r11

  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  v2 = *((_BYTE *)this + 87) & 0x1F;
  this->traversalEvasionAimDist = 400.0;
  this->traversalAimEvasionDuration = 0;
  this->traversalEvasionGunfireDist = 1024.0;
  this->__vftable = (idDeclAIBehavior_vtbl *)&idDeclAIBehavior::`vftable';
  this->traversalGunfireEvasionDuration = 0;
  this->traversalAttackTolerance = 0;
  *((_BYTE *)this + 84) = 0x80;
  *((_BYTE *)this + 85) = 0;
  *((_BYTE *)this + 86) = 0;
  *((_BYTE *)this + 87) = v2;
  this->damageBehaviors.difficultyDamageScale.setting[0] = 0.0;
  this->damageBehaviors.difficultyDamageScale.setting[1] = 0.0;
  this->damageBehaviors.difficultyDamageScale.setting[2] = 0.0;
  this->damageBehaviors.difficultyDamageScale.setting[3] = 0.0;
  this->damageBehaviors.difficultyDamageScale.setting[4] = 0.0;
  *((_BYTE *)this + 196) = -124;
  this->friendlyAttitudeAdjust = -0.5;
  this->neutralAttitudeAdjust = -0.5;
  this->weaponSlot = EQUIP_RIGHT_HAND;
  this->attitudeAdjust = -0.5;
  *((_BYTE *)this + 197) = *((_BYTE *)this + 197) & 0xF | 0x80;
  this->throwLag.setting[0] = 0.1;
  this->throwLag.setting[1] = 0.1;
  this->throwLag.setting[2] = 0.1;
  this->throwLag.setting[3] = 0.1;
  this->throwLag.setting[4] = 0.1;
  this->maxThrowError.setting[0] = 0.0;
  this->maxThrowError.setting[1] = 0.0;
  this->maxThrowError.setting[2] = 0.0;
  this->maxThrowError.setting[3] = 0.0;
  this->maxThrowError.setting[4] = 0.0;
  this->itemSelect[0] = AIITEMSELECT_NONE;
  this->itemSelect[1] = AIITEMSELECT_NONE;
  this->itemSelect[2] = AIITEMSELECT_NONE;
  this->muzzleTraceClearOffset = 0.0;
  this->combatAmmo = nullptr;
  this->minThrowDot = 0.0;
  this->aimOffset = 0.0;
  this->rolePreferenceOrder.list = nullptr;
  this->rolePreferenceOrder.granularity = 0;
  this->rolePreferenceOrder.memTag = 5;
  this->rolePreferenceOrder.listStatic = 0;
  this->rolePreferenceOrder.size = 0;
  this->rolePreferenceOrder.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->rolePreferenceOrder);
  this->followFriendlyThreshold = ATTITUDE_LOVE;
  this->lookAtFriendlyTarget = false;
  *(_WORD *)&this->chasesProjectiles = 1;
  this->canGreetHumans = true;
  this->investigatesBody = false;
  this->takeCoverBehaviors.maxWaitTimeAfterReachingCover.setting[0] = 0;
  this->takeCoverBehaviors.maxWaitTimeAfterReachingCover.setting[1] = 0;
  this->takeCoverBehaviors.maxWaitTimeAfterReachingCover.setting[2] = 0;
  this->takeCoverBehaviors.maxWaitTimeAfterReachingCover.setting[3] = 0;
  this->takeCoverBehaviors.maxWaitTimeAfterReachingCover.setting[4] = 0;
  this->takeCoverBehaviors.minWaitInCoverTime.setting[0] = 0;
  this->takeCoverBehaviors.minWaitInCoverTime.setting[1] = 0;
  this->takeCoverBehaviors.minWaitInCoverTime.setting[2] = 0;
  this->takeCoverBehaviors.minWaitInCoverTime.setting[3] = 0;
  this->takeCoverBehaviors.minWaitInCoverTime.setting[4] = 0;
  this->takeCoverBehaviors.maxWaitInCoverTime.setting[0] = 0;
  this->takeCoverBehaviors.maxWaitInCoverTime.setting[1] = 0;
  this->takeCoverBehaviors.maxWaitInCoverTime.setting[2] = 0;
  this->takeCoverBehaviors.maxWaitInCoverTime.setting[3] = 0;
  this->takeCoverBehaviors.maxWaitInCoverTime.setting[4] = 0;
  this->takeCoverBehaviors.usesForwardCover.setting[0] = false;
  this->takeCoverBehaviors.usesForwardCover.setting[1] = false;
  this->takeCoverBehaviors.usesForwardCover.setting[2] = false;
  this->takeCoverBehaviors.usesForwardCover.setting[3] = false;
  this->takeCoverBehaviors.usesForwardCover.setting[4] = false;
  this->takeCoverBehaviors.usesBackwardCover.setting[0] = false;
  this->takeCoverBehaviors.usesBackwardCover.setting[1] = false;
  this->takeCoverBehaviors.usesBackwardCover.setting[2] = false;
  this->takeCoverBehaviors.usesBackwardCover.setting[3] = false;
  this->takeCoverBehaviors.usesBackwardCover.setting[4] = false;
  this->openCombatDuration = 5.0;
  this->exposeCoverDistance = 500.0;
  this->exposeCoverMinDistance = 256.0;
  this->optimalCoverDistance = 360.0;
  this->enemyTooCloseToGoProneFacing = 400.0;
  v3 = *((_BYTE *)this + 429) & 0x7F;
  this->doubleBlinkChance = 25;
  this->minBlinkInterval = 2500;
  this->minFireFromCoverDuration = 2500;
  this->exposeCoverTravelTime = 0.5;
  this->coverPathNearDistance = 256.0;
  *((_BYTE *)this + 428) = 0;
  this->freeAmmoDistance = 128.0;
  this->doubleBlinkInterval = 300;
  this->enemyTooCloseToGoProne = 250.0;
  this->maxBlinkInterval = 10000;
  this->closeMeleeDist = 80.0;
  this->jitterMinInterval = 100;
  this->mediumMeleeDist = 0.0;
  this->jitterMaxInterval = 1500;
  this->longMeleeDist = 0.0;
  this->exposeCoverOpenCombatChance = 100;
  this->movingMeleeDist = 0.0;
  *((_BYTE *)this + 429) = v3;
  this->meleeExtrapolate = 0.25;
  this->maxFireFromCoverDuration = 10000;
  this->maxLeapAttackDistance = 256.0;
  this->repeatExposeCoverChargeTime = 5000;
  this->minLeapAttackDistance = 128.0;
  this->friendlyFireThreshold = ATTITUDE_NEUTRAL;
  this->leapAttackTargetExtrapolate = 1.0;
  this->minCloseMeleeInterval = 2000;
  this->leapAttackSpeed = 320.0;
  this->maxCloseMeleeInterval = 5000;
  this->minChargeDistance = 100.0;
  this->closeMeleeKickDamage = nullptr;
  this->maxChargeDistance = 100000.0;
  this->closeMeleePunchDamage = nullptr;
  this->meleeImpactEffect = nullptr;
  this->meleeFromStunChance = 50;
  this->stunIgnoreTime = 5000;
  this->leapAttackChance = 0;
  this->minLeapAttackInterval = 3000;
  this->maxLeapAttackInterval = 8000;
  this->maxChargeDuration = 5000;
  this->minChargeInterval = 5000;
  this->maxChargeInterval = 15000;
  this->chargeChance = 1;
  this->dodging.aimForwardDiveChance.setting[0] = 0;
  this->dodging.aimForwardDiveChance.setting[1] = 0;
  this->dodging.aimForwardDiveChance.setting[2] = 0;
  this->dodging.aimForwardDiveChance.setting[3] = 0;
  this->dodging.aimForwardDiveChance.setting[4] = 0;
  this->noticeGrenadeChance = 100.0;
  this->meleeDodgeChance = 50;
  this->minMeleeDodgeInterval = 1000;
  this->maxMeleeDodgeInterval = 1000;
  this->minThrowInterval = 5000;
  this->maxThrowInterval = 5000;
  this->minOCThrowInterval = 0;
  this->maxOCThrowInterval = 0;
  this->minCoverDuration = 2000;
  this->maxCoverDuration = 3000;
  this->noContactInterval = 10000;
  this->breakCoverDuration = 25000;
  this->combatTimeoutInterval = -1;
  this->searchTimeoutInterval = -1;
  this->obstacleStopDistance = 80;
  this->surroundRadius = 400;
  this->minControlTime = 15000;
  this->maxControlTime = 15000;
  this->controlIntroDuration = 1500;
  this->controlSelfDamage = nullptr;
  this->controlSplashDamage = nullptr;
  this->controlEndParticle = nullptr;
  this->berzerkerFaction = nullptr;
  this->bfgDeathParticle = nullptr;
  idDeclAIBehavior::idForwardCoverCaps::idForwardCoverCaps(this: (idDeclAIBehavior::idBackwardCoverCaps *)&this->forwardCoverCaps);
  idDeclAIBehavior::idForwardCoverCaps::idForwardCoverCaps(this: &this->backwardCoverCaps);
  this->formations.granularity = 0;
  this->formations.memTag = 5;
  this->formations.listStatic = 0;
  this->formations.list = nullptr;
  this->formations.size = 0;
  this->formations.num = 0;
  this->turnParms.size = 3;
  this->turnParms.num = 0;
  this->turnParms.granularity = 1;
  this->turnParms.list = this->turnParms.staticList;
  this->turnParms.memTag = 5;
  this->turnParms.listStatic = 1;
  idAINavPowerMoverParms::idAINavPowerMoverParms(this: &this->navpower);
  this->damageBehaviors.twitchThresholdStanding = 0.0;
  this->damageBehaviors.staggerThresholdStanding = 0.25;
  this->damageBehaviors.twitchThresholdWalking = 0.0;
  this->damageBehaviors.staggerThresholdWalking = 0.25;
  this->damageBehaviors.twitchThresholdRunning = 0.0;
  this->damageBehaviors.staggerThresholdRunning = 0.25;
  this->damageBehaviors.minStaggerPainInterval = 1000;
  this->damageBehaviors.movingPainSpeed = 50.0;
  this->damageBehaviors.movingDeathSpeed = 50.0;
  this->damageBehaviors.slowMovingDeathSpeed = 50.0;
  this->damageBehaviors.injuredRunThreshold = 0.5;
  this->damageBehaviors.injuredChance = 100;
  this->damageBehaviors.injuredDontMoveCount = 2;
  this->damageBehaviors.groundBleedRate = 0.0;
  this->damageBehaviors.standingBleedRate = 0.0;
  this->damageBehaviors.bleedOutDamageDecl = nullptr;
  *((_BYTE *)&this->damageBehaviors + 84) = -19;
  this->damageBehaviors.shieldChargeThreshold = 0.0;
  this->damageBehaviors.shieldBackOnThreshold = 1.0;
  this->damageBehaviors.injuredRunMode = AIINJUREDRUNMODE_AFTERPAIN;
  *((_BYTE *)&this->damageBehaviors + 85) = *((_BYTE *)&this->damageBehaviors + 85) & 3 | 0x28;
  this->damageBehaviors.explosionEntity = nullptr;
  this->damageBehaviors.lootBox = nullptr;
  this->damageBehaviors.difficultyDamageScale.setting[0] = 1.0;
  this->damageBehaviors.difficultyDamageScale.setting[1] = 1.0;
  this->damageBehaviors.difficultyDamageScale.setting[2] = 1.0;
  this->damageBehaviors.difficultyDamageScale.setting[3] = 1.0;
  this->damageBehaviors.difficultyDamageScale.setting[4] = 1.0;
  this->backstandBehaviors.approachDistance = 110.0;
  v4 = 0;
  this->backstandBehaviors.riseDistance = 164.0;
  v5 = 5;
  this->backstandBehaviors.commitDistance = 128.0;
  this->backstandBehaviors.attackReach = 128.0;
  this->backstandBehaviors.standReach = 200.0;
  this->backstandBehaviors.groundReach = 96.0;
  this->backstandBehaviors.riseTime = 0.75;
  this->takeCoverBehaviors.maxWaitTimeAfterReachingCover.setting[0] = 1000;
  this->takeCoverBehaviors.maxWaitTimeAfterReachingCover.setting[1] = 1000;
  this->takeCoverBehaviors.maxWaitTimeAfterReachingCover.setting[2] = 1000;
  this->takeCoverBehaviors.maxWaitTimeAfterReachingCover.setting[3] = 1000;
  this->takeCoverBehaviors.maxWaitTimeAfterReachingCover.setting[4] = 1000;
  this->takeCoverBehaviors.maxWaitInCoverTime.setting[0] = 1000;
  this->takeCoverBehaviors.maxWaitInCoverTime.setting[1] = 1000;
  this->takeCoverBehaviors.maxWaitInCoverTime.setting[2] = 1000;
  this->takeCoverBehaviors.maxWaitInCoverTime.setting[3] = 1000;
  this->takeCoverBehaviors.maxWaitInCoverTime.setting[4] = 1000;
  this->takeCoverBehaviors.maxWaitInCoverTime.setting[0] = 5000;
  this->takeCoverBehaviors.maxWaitInCoverTime.setting[1] = 5000;
  this->takeCoverBehaviors.maxWaitInCoverTime.setting[2] = 5000;
  this->takeCoverBehaviors.maxWaitInCoverTime.setting[3] = 5000;
  this->takeCoverBehaviors.maxWaitInCoverTime.setting[4] = 5000;
  do
  {
    this->takeCoverBehaviors.usesForwardCover.setting[v4++] = false;
    --v5;
  }
  while ( v5 != 0 );
  v6 = 5;
  v7 = 0;
  do
  {
    this->takeCoverBehaviors.usesBackwardCover.setting[v7++] = false;
    --v6;
  }
  while ( v6 != 0 );
  this->dodging.gunfireDodgeCoverChance = 0;
  this->dodging.gunfireDodgeNoCoverChance = 0;
  this->dodging.aimDodgeCoverChance = 0;
  this->dodging.aimHeavyDodgeNoCoverChance = 0;
  this->dodging.painDiveCoverChance = 0;
  this->dodging.painDiveNoCoverChance = 0;
  this->dodging.gunfireHeavyDiveCoverChance = 0;
  this->dodging.gunfireHeavyDiveNoCoverChance = 0;
  this->dodging.aimHeavyDiveCoverChance = 0;
  this->dodging.aimHeavyDiveNoCoverChance = 0;
  this->dodging.gunfireFlinchChance = 0;
  this->dodging.gunfireLightDiveNoCoverChance = 0;
  this->dodging.aimLightDiveNoCoverChance = 0;
  this->dodging.aimForwardDiveChance.setting[0] = 0;
  this->dodging.aimForwardDiveChance.setting[1] = 0;
  this->dodging.aimForwardDiveChance.setting[2] = 0;
  this->dodging.aimForwardDiveChance.setting[3] = 0;
  this->dodging.aimForwardDiveChance.setting[4] = 0;
  this->dodging.gunfireForwardDiveChance = 0;
  this->dodging.avoidDiveChance = 0;
  this->dodging.avoidForwardDiveChance = 0;
  this->dodging.tooCloseDist = 250.0;
  this->dodging.closeRangeDist = 600.0;
  this->dodging.mediumRangeDist = 1024.0;
  this->dodging.aimCoverHideChance = 0;
  this->dodging.aimHeavyCoverHideChance = 0;
  this->dodging.gunfireCoverHideChance = 0;
  this->dodging.damageCoverHideChance = 0;
  this->dodging.onlyCoverHideNoHelmet = false;
  this->dodging.gunfireHideBailChance = 0;
  this->dodging.damageHideBailChance = 0;
  this->dodging.damageHideBailMaxChance = 0;
  this->dodging.minAimDodgeInterval = 0;
  this->dodging.maxAimDodgeInterval = 0;
  this->dodging.sidestepDistance = 64.0;
  this->dodging.diveDistance = 160.0;
  this->dodging.mustBeDirectTarget = true;
  this->dodging.lightFiredAtAngle = 11.5;
  this->dodging.mediumFiredAtAngle = 11.5;
  this->dodging.heavyFiredAtAngle = 11.5;
  this->dodging.disableHintNodeUnderFire = false;
  this->rageBehaviors.angryRageAfterHurtChance = 0;
  this->rageBehaviors.angryRageAfterMissingChance = 0;
  this->rageBehaviors.angryRageAfterAttractChance = 0;
  this->rageBehaviors.angryRageWhenCloseDistance = 0.0;
  this->rageBehaviors.tauntRageAfterHitEnemyChance = 0;
  this->rageBehaviors.tauntRageAfterKillingEnemyChance = 0;
  this->rageBehaviors.tauntRageBehindEnemyChance = 0;
  this->rageBehaviors.tauntRageFleeingEnemyChance = 0;
  this->rageBehaviors.minRageInterval = 4000;
  this->rageBehaviors.maxRageInterval = 8000;
  this->rageBehaviors.staleTauntRageThreshold = 2000;
  this->rageBehaviors.staleAngryRageThreshold = 3000;
  this->rageBehaviors.useGroupRageLimit = true;
  this->rageBehaviors.minRageFacingDot = 0.5;
  this->movementBehaviors.crouchMoveMax = 128.0;
  this->movementBehaviors.injuredCrouchMoveMax = 256.0;
  this->movementBehaviors.runMoveMin = 128.0;
  this->movementBehaviors.sprintMoveMin = 2048.0;
  this->movementBehaviors.coverCrouchPathTime = 500;
  this->movementBehaviors.coverRunPathTime = 500;
  this->movementBehaviors.coverSprintPathTime = 8000;
  *((_BYTE *)&this->movementBehaviors + 40) &= 0x1Fu;
  this->movementBehaviors.fireRunningToCoverChance = 100;
  this->movementBehaviors.cornerCircleRadius = 32.0;
  this->movementBehaviors.alignToPointDistance = 64.0;
  *((_BYTE *)&this->movementBehaviors + 40) = *((_BYTE *)&this->movementBehaviors + 40) & 0xE0 | 0x14;
  *((_BYTE *)&this->movementBehaviors + 41) &= ~0x80u;
  *(_BYTE *)&this->dynamicCoverCaps &= 0x1Fu;
  this->runTypeBehaviors.scrambleRunIndex = -1;
  this->runTypeBehaviors.gunDownIndex = -1;
  this->runTypeBehaviors.downStairsIndex = -1;
  this->runTypeBehaviors.upStairsIndex = -1;
  this->runTypeBehaviors.narrowIndex = -1;
  this->runTypeBehaviors.duckIndex = -1;
  this->runTypeBehaviors.farRunIndex = -1;
  this->runTypeBehaviors.minFarRunDistance = 0.0;
  this->runTypeBehaviors.maxFarRunDistance = 0.0;
  this->runTypeBehaviors.blendRate = 0.050000001;
  this->idleBehaviors.gunDownIndex = 0;
  this->idleBehaviors.narrowIndex = 0;
  this->idleBehaviors.duckIndex = 0;
  this->intimidation.minConfidenceLevel = AICONFIDENCE_SCARED;
  this->intimidation.maxConfidenceLevel = AICONFIDENCE_FEARLESS;
  this->intimidation.intimidationConfidence = AICONFIDENCE_SCARED;
  this->intimidation.minTauntConfidence = AICONFIDENCE_SURE;
  this->intimidation.minIntimidationTime = 10000;
  this->intimidation.healthFactor = 0.0;
  this->intimidation.avoidFactor = 0.0;
  this->intimidation.firedAtFactor = 0.5;
  this->intimidation.heavyFiredAtFactor = 0.5;
  this->intimidation.recentlyKilledGroupMemberFactor = 0.5;
  this->intimidation.recentHeavilyKilledGroupMemberFactor = 0.75;
  this->intimidation.injured = 1.0;
  this->intimidation.heavyConfidenceBoost = 2.0;
  this->intimidation.recentlyKilledHeaviesFactor = 2.0;
  this->intimidation.deadGroupMemberCap = 2.0;
  this->intimidation.closeEnemyFactor = 1.0;
  this->intimidation.closeEnemyDist = 512.0;
  this->clanDistinctionBehaviors = (idDeclAIBehavior::idAIClanDistinctionBehaviors)(*(_BYTE *)&this->clanDistinctionBehaviors
                                                                                  & 7
                                                                                  | 0xF0);
  return this;
}


// ========================================================================
// __unwind$489177
// EA  : 0x82BBC464
// RVA : 0x00BBC464
// PDB : w:\tech5\tungsten\game\decls\declaibehavior.cpp
// ========================================================================

void _unwind_489177()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 288 + 308));
}


// ========================================================================
// __unwind$489178
// EA  : 0x82BBC48C
// RVA : 0x00BBC48C
// PDB : w:\tech5\tungsten\game\decls\declaibehavior.cpp
// ========================================================================

void _unwind_489178()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 288 + 308) + 328));
}


// ========================================================================
// __unwind$489179
// EA  : 0x82BBC4B8
// RVA : 0x00BBC4B8
// PDB : w:\tech5\tungsten\game\decls\declaibehavior.cpp
// ========================================================================

void _unwind_489179()
{
  int v0; // r12

  idDeclAIBehavior::idForwardCoverCaps::~idForwardCoverCaps(this: (idDeclAIBehavior::idBackwardCoverCaps *)(*(_DWORD *)(v0 - 288 + 308) + 1068));
}


// ========================================================================
// __unwind$489180
// EA  : 0x82BBC4E4
// RVA : 0x00BBC4E4
// PDB : w:\tech5\tungsten\game\decls\declaibehavior.cpp
// ========================================================================

void _unwind_489180()
{
  int v0; // r12

  idDeclAIBehavior::idForwardCoverCaps::~idForwardCoverCaps(this: (idDeclAIBehavior::idBackwardCoverCaps *)(*(_DWORD *)(v0 - 288 + 308) + 1140));
}


// ========================================================================
// __unwind$489181
// EA  : 0x82BBC510
// RVA : 0x00BBC510
// PDB : w:\tech5\tungsten\game\decls\declaibehavior.cpp
// ========================================================================

void _unwind_489181()
{
  int v0; // r12

  idList<idAIFormation,5>::~idList<idAIFormation,5>(this: (idList<idAIFormation,5> *)(*(_DWORD *)(v0 - 288 + 308) + 1216));
}


// ========================================================================
// __unwind$489182
// EA  : 0x82BBC53C
// RVA : 0x00BBC53C
// PDB : w:\tech5\tungsten\game\decls\declaibehavior.cpp
// ========================================================================

void _unwind_489182()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 288 + 308) + 1232));
}


// ========================================================================
// ??0idDeclAIBehaviorVOChains@@QAA@XZ
// EA  : 0x82BBC7B0
// RVA : 0x00BBC7B0
// PDB : w:\tech5\tungsten\game\decls\declaibehavior.cpp
// ========================================================================

idDeclAIBehaviorVOChains *__fastcall idDeclAIBehaviorVOChains::idDeclAIBehaviorVOChains(idDeclAIBehaviorVOChains *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclAIBehaviorVOChains_vtbl *)&idDeclAIBehaviorVOChains::`vftable';
  this->combatVoChains.granularity = 0;
  this->combatVoChains.memTag = 5;
  this->combatVoChains.listStatic = 0;
  this->combatVoChains.list = nullptr;
  this->combatVoChains.size = 0;
  this->combatVoChains.num = 0;
  return this;
}


// ========================================================================
// __unwind$490000
// EA  : 0x82BBC820
// RVA : 0x00BBC820
// PDB : w:\tech5\tungsten\game\decls\declaibehavior.cpp
// ========================================================================

void _unwind_490000()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}

