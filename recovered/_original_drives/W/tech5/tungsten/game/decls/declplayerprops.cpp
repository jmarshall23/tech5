
// ========================================================================
// ??0playerSounds_t@idDeclPlayerProps@@QAA@XZ
// EA  : 0x82BCA978
// RVA : 0x00BCA978
// PDB : w:\tech5\tungsten\game\decls\declplayerprops.cpp
// ========================================================================

idDeclPlayerProps::playerSounds_t *__fastcall idDeclPlayerProps::playerSounds_t::playerSounds_t(
        idDeclPlayerProps::playerSounds_t *this)
{
  this->sndAlmostDead = nullptr;
  this->sndBreatheHeavy = nullptr;
  this->sndBreatheMedium = nullptr;
  this->sndBreatheSprinting = nullptr;
  this->sndCantUseItem = nullptr;
  this->sndJobAccepted = nullptr;
  this->sndJobCompleted = nullptr;
  this->sndJobReadyToTurnIn = nullptr;
  this->sndJobUpdated = nullptr;
  this->sndOutOfItems = nullptr;
  this->sndPickup = nullptr;
  this->sndPossess = nullptr;
  this->sndPossessLoop = nullptr;
  this->sndUseBandage = nullptr;
  this->sndBurn = nullptr;
  this->sndButtonBad = nullptr;
  this->sndButtonDown = nullptr;
  this->sndButtonUp = nullptr;
  this->sndCantDropItem = nullptr;
  this->sndCantLootEntity = nullptr;
  this->sndClickDown = nullptr;
  this->sndClickUp = nullptr;
  this->sndDeath = nullptr;
  this->sndDisassemble = nullptr;
  this->sndEnterWater = nullptr;
  this->sndExitWater = nullptr;
  this->sndJobFailed = nullptr;
  this->sndJump = nullptr;
  this->sndCrouch = nullptr;
  this->sndStandUp = nullptr;
  this->sndLandHard = nullptr;
  this->sndLootEntity = nullptr;
  this->sndSkipCinematic = nullptr;
  this->sndSpecialEventJump = nullptr;
  this->sndSpecialEventNewArea = nullptr;
  this->sndStepladder = nullptr;
  this->sndPainSmall = nullptr;
  this->sndPainMedium = nullptr;
  this->sndPainLarge = nullptr;
  this->sndHeartBeatLub = nullptr;
  this->sndHeartBeatDub = nullptr;
  this->sndThrownLandingWater = nullptr;
  this->sndThrownLanding = nullptr;
  this->sndThrown = nullptr;
  this->sndCancelRevive = nullptr;
  this->sndFinishRevive = nullptr;
  this->sndMPDmgDealtFeedback = nullptr;
  this->sndMPDmgDealtFeedbackVeh = nullptr;
  this->sndMPRoverBombSelfDestruct = nullptr;
  this->sndEndQuadDamage = nullptr;
  return this;
}


// ========================================================================
// ??0idDeclPlayerProps@@QAA@XZ
// EA  : 0x82BCAA50
// RVA : 0x00BCAA50
// PDB : w:\tech5\tungsten\game\decls\declplayerprops.cpp
// ========================================================================

idDeclPlayerProps *__fastcall idDeclPlayerProps::idDeclPlayerProps(idDeclPlayerProps *this)
{
  idDeclTable *v2; // r10

  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclPlayerProps_vtbl *)&idDeclPlayerProps::`vftable';
  this->screenParticles.waterDroplets = nullptr;
  this->screenParticles.waterDripsSmall = nullptr;
  this->screenParticles.waterDripsMedium = nullptr;
  this->screenParticles.waterDripsLarge = nullptr;
  idDeclPlayerProps::playerSounds_t::playerSounds_t(this: &this->sounds);
  this->soundParms.lowHealthThreshold = 20.0;
  this->pain.pain_mediumDamageAmount = 20.0;
  this->pain.pain_heavyDamageAmount = 50.0;
  this->pain.pain_delay = (int)v2;
  this->pain.pain_threshold = (int)v2;
  this->damageFeedback.IndicatorMaxAlpha = 255;
  this->damageFeedback.spikeIndicatorMaxAlpha = 255;
  this->damageFeedback.IndicatorMinAlpha = (int)v2;
  this->damageFeedback.spikeIndicatorMinAlpha = (int)v2;
  this->damageFeedback.worldFadeTable = v2;
  this->damageFeedback.centerIndicatorOffset = 0.1;
  this->damageFeedback.centerIndicatorSize = 0.34999999;
  this->damageFeedback.centerIndicatorDecay = 0.02;
  this->damageFeedback.outerIndicatorSize = 0.5;
  this->damageFeedback.spikeIndicatorOffset = 0.75;
  this->damageFeedback.spikeIndicatorWidth = 0.2;
  this->damageFeedback.spikeIndicatorDecay = 0.1;
  this->damageFeedback.dryGainEnd = -45.0;
  this->damageFeedback.roomGainEnd = -15.0;
  this->damageFeedback.roomHFGainEnd = -14.0;
  this->declReachIK = (const idDeclReachIK *)v2;
  this->reviveItemDecl = (const idDeclInventory *)v2;
  this->coopMultiplierBG = (const idMaterial *)v2;
  this->coopMultiplierIcon = (const idMaterial *)v2;
  this->reviveDuck = (const idDeclDuck *)v2;
  this->collectorCardDeck.earlyDeckName.index = -1;
  this->collectorCardDeck.earlyDeckDesc.index = -1;
  this->collectorCardDeck.realDeckName.index = -1;
  this->collectorCardDeck.realDeckDesc.index = -1;
  this->dlcItemInfo.granularity = (__int16)v2;
  this->dlcItemInfo.memTag = 5;
  this->dlcItemInfo.listStatic = (unsigned __int8)v2;
  this->dlcItemInfo.list = (idDLCRewardInfo *)v2;
  this->dlcItemInfo.size = (int)v2;
  this->dlcItemInfo.num = (int)v2;
  this->collectorCardDeck.cardDeckRealDecl = (const idDeclInventory *)v2;
  this->collectorCardDeck.earlyDeckTexture = (const idMaterial *)v2;
  this->collectorCardDeck.realDeckTexture = (const idMaterial *)v2;
  this->tutorialData.bandageTutorial = (const idDeclTutorialEvent *)v2;
  this->tutorialData.reloadTutorial = (const idDeclTutorialEvent *)v2;
  this->tutorialData.merchantSellGameStateInt = (const idDeclGameStateInt *)v2;
  return this;
}


// ========================================================================
// __unwind$487379
// EA  : 0x82BCABF4
// RVA : 0x00BCABF4
// PDB : w:\tech5\tungsten\game\decls\declplayerprops.cpp
// ========================================================================

void _unwind_487379()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 144 + 164));
}

