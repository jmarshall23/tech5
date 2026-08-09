#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\decls\declplayerprops.h
// Recovered logical types: 9
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 14329; PDB kind: struct.
struct idDeclPlayerProps::screenParticle_t
{
  const idDeclParticle *waterDroplets;
  const idDeclParticle *waterDripsSmall;
  const idDeclParticle *waterDripsMedium;
  const idDeclParticle *waterDripsLarge;
};

// IDA Local Type ordinal 14330; PDB kind: struct.
struct idDeclPlayerProps::playerSounds_t
{
  const idSoundShader *sndAlmostDead;
  const idSoundShader *sndBreatheHeavy;
  const idSoundShader *sndBreatheMedium;
  const idSoundShader *sndBreatheSprinting;
  const idSoundShader *sndCantUseItem;
  const idSoundShader *sndJobAccepted;
  const idSoundShader *sndJobCompleted;
  const idSoundShader *sndJobReadyToTurnIn;
  const idSoundShader *sndJobUpdated;
  const idSoundShader *sndOutOfItems;
  const idSoundShader *sndPickup;
  const idSoundShader *sndPossess;
  const idSoundShader *sndPossessLoop;
  const idSoundShader *sndUseBandage;
  const idSoundShader *sndBurn;
  const idSoundShader *sndButtonBad;
  const idSoundShader *sndButtonDown;
  const idSoundShader *sndButtonUp;
  const idSoundShader *sndCantDropItem;
  const idSoundShader *sndCantLootEntity;
  const idSoundShader *sndClickDown;
  const idSoundShader *sndClickUp;
  const idSoundShader *sndDeath;
  const idSoundShader *sndDisassemble;
  const idSoundShader *sndEnterWater;
  const idSoundShader *sndExitWater;
  const idSoundShader *sndJobFailed;
  const idSoundShader *sndJump;
  const idSoundShader *sndCrouch;
  const idSoundShader *sndStandUp;
  const idSoundShader *sndLandHard;
  const idSoundShader *sndLootEntity;
  const idSoundShader *sndSkipCinematic;
  const idSoundShader *sndSpecialEventJump;
  const idSoundShader *sndSpecialEventNewArea;
  const idSoundShader *sndStepladder;
  const idSoundShader *sndPainSmall;
  const idSoundShader *sndPainMedium;
  const idSoundShader *sndPainLarge;
  const idSoundShader *sndHeartBeatLub;
  const idSoundShader *sndHeartBeatDub;
  const idSoundShader *sndThrownLandingWater;
  const idSoundShader *sndThrownLanding;
  const idSoundShader *sndThrown;
  const idSoundShader *sndCancelRevive;
  const idSoundShader *sndFinishRevive;
  const idSoundShader *sndMPDmgDealtFeedback;
  const idSoundShader *sndMPDmgDealtFeedbackVeh;
  const idSoundShader *sndMPRoverBombSelfDestruct;
  const idSoundShader *sndEndQuadDamage;
};

// IDA Local Type ordinal 14331; PDB kind: struct.
struct idDeclPlayerProps::playerSoundsParms_t
{
  float lowHealthThreshold;
};

// IDA Local Type ordinal 14332; PDB kind: struct.
struct idDeclPlayerProps::pain_t
{
  int pain_delay;
  int pain_threshold;
  float pain_mediumDamageAmount;
  float pain_heavyDamageAmount;
};

// IDA Local Type ordinal 14333; PDB kind: struct.
struct idDeclPlayerProps::damageFeedback_t
{
  float centerIndicatorOffset;
  float centerIndicatorSize;
  float centerIndicatorDecay;
  float outerIndicatorSize;
  int IndicatorMinAlpha;
  int IndicatorMaxAlpha;
  float spikeIndicatorOffset;
  float spikeIndicatorWidth;
  float spikeIndicatorDecay;
  int spikeIndicatorMinAlpha;
  int spikeIndicatorMaxAlpha;
  float dryGainEnd;
  float roomGainEnd;
  float roomHFGainEnd;
  idDeclTable *worldFadeTable;
};

// IDA Local Type ordinal 14339; PDB kind: struct.
struct idDeclPlayerProps::collectorCardDeck_t
{
  const idDeclInventory *cardDeckRealDecl;
  idStrId earlyDeckName;
  idStrId earlyDeckDesc;
  const idMaterial *earlyDeckTexture;
  idStrId realDeckName;
  idStrId realDeckDesc;
  const idMaterial *realDeckTexture;
};

// IDA Local Type ordinal 14344; PDB kind: struct.
struct idDeclPlayerProps::tutorialData_t
{
  const idDeclTutorialEvent *bandageTutorial;
  const idDeclTutorialEvent *reloadTutorial;
  const idDeclGameStateInt *merchantSellGameStateInt;
};

// IDA Local Type ordinal 14349; PDB kind: class.
class idDeclPlayerProps : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 14350.
  virtual ~idDeclPlayerProps();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();
  virtual unsigned int GetDeclTimestamp();
  virtual idDeclInfo *GetDeclInfo();
  virtual bool RebuildTextSource();
  virtual bool SetImplicitText();
  virtual const char *DefaultDefinition();
  virtual void LogMissingDecl();
  virtual void Parse(idParser *);
  virtual void FreeData();
  virtual unsigned int Size();

  idDeclPlayerProps::screenParticle_t screenParticles;
  idDeclPlayerProps::playerSounds_t sounds;
  idDeclPlayerProps::playerSoundsParms_t soundParms;
  idDeclPlayerProps::pain_t pain;
  idDeclPlayerProps::damageFeedback_t damageFeedback;
  const idDeclReachIK *declReachIK;
  const idDeclInventory *reviveItemDecl;
  const idMaterial *coopMultiplierBG;
  const idMaterial *coopMultiplierIcon;
  const idDeclDuck *reviveDuck;
  idDeclPlayerProps::collectorCardDeck_t collectorCardDeck;
  idDeclPlayerProps::tutorialData_t tutorialData;
  idList<idDLCRewardInfo,5> dlcItemInfo;
};

// IDA Local Type ordinal 16616; PDB kind: class.
class idDeclPlayerArmor : public idDeclInventory
{
public:
  // Recovered virtual interface; IDA vtable ordinal 16617.
  virtual ~idDeclPlayerArmor();
  virtual void LoadResource();
  virtual bool ReloadIfStale();
  virtual void WriteResourceFile();
  virtual idResourceList *GetResourceList();
  virtual void Print();
  virtual void List();
  virtual unsigned int GetDeclTimestamp();
  virtual idDeclInfo *GetDeclInfo();
  virtual bool RebuildTextSource();
  virtual bool SetImplicitText();
  virtual const char *DefaultDefinition();
  virtual void LogMissingDecl();
  virtual void Parse(idParser *);
  virtual void FreeData();
  virtual unsigned int Size();

  float protectionPercent;
  float armorReductionPercent;
  float armorAmount;
  float maxArmor;
};
