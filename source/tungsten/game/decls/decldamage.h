#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\decls\decldamage.h
// Recovered logical types: 10
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1049; PDB kind: enum.
enum idDeclDamage::damageType_t : __int32
{
  DAMAGETYPE_NONE = 0x0,
  DAMAGETYPE_GENERIC = 0x1,
  DAMAGETYPE_MELEE = 0x2,
  DAMAGETYPE_PISTOL = 0x4,
  DAMAGETYPE_RIFLE = 0x8,
  DAMAGETYPE_SHOTGUN = 0x10,
  DAMAGETYPE_TURRET = 0x20,
  DAMAGETYPE_VEHICLE_RAM = 0x40,
  DAMAGETYPE_LASER = 0x80,
  DAMAGETYPE_EXPLOSION = 0x100,
  DAMAGETYPE_FIRE = 0x200,
  DAMAGETYPE_ELECTRIC = 0x400,
  DAMAGETYPE_EDGED = 0x1000,
  DAMAGETYPE_BLUNT = 0x2000,
  DAMAGETYPE_LASER_CUTTING = 0x4000,
  DAMAGETYPE_NO_DAMAGE = 0x8000,
  DAMAGETYPE_ALL = 0x7FFFFFFF,
  DAMAGETYPE_LIGHT = 0x8C,
  DAMAGETYPE_HEAVY = 0x30,
};

// IDA Local Type ordinal 1283; PDB kind: enum.
enum idDeclDamage::goreType_t : __int32
{
  GORETYPE_NONE = 0x0,
  GORETYPE_DECAPITATION = 0x1,
  GORETYPE_DISMEMBER_ARMS = 0x2,
  GORETYPE_DISMEMBER_LEGS = 0x4,
  GORETYPE_GIB = 0x8,
  GORETYPE_HEAD_EXPLODE = 0x10,
  GORETYPE_SMALL_WOUND = 0x20,
  GORETYPE_BIG_WOUND = 0x40,
  GORETYPE_TORSO_SAW = 0x80,
  GORETYPE_BFG = 0x100,
  GORETYPE_ANY = 0x7FFFFFFF,
};

// IDA Local Type ordinal 1625; PDB kind: enum.
enum idDeclDamage::damageSource_t : __int32
{
  DAMAGESRC_UNKNOWN = 0x0,
  DAMAGESRC_BULLET = 0x1,
  DAMAGESRC_MELEE = 0x2,
  DAMAGESRC_FIRE = 0x4,
  DAMAGESRC_ELECTRICAL = 0x8,
  DAMAGESRC_FALL = 0x10,
  DAMAGESRC_CRUSH = 0x20,
  DAMAGESRC_EXPLOSIVE = 0x40,
  DAMAGESRC_CHAINSAW = 0x80,
  DAMAGESRC_ACID = 0x100,
  DAMAGESRC_HELLSPIKE = 0x200,
  DAMAGESRC_PLASMA = 0x400,
  DAMAGESRC_BFG = 0x800,
  DAMAGESRC_SPIRITWEB = 0x1000,
  DAMAGESRC_POISON_GAS = 0x2000,
  DAMAGESRC_SYNCED_FATALITY = 0x4000,
};

// IDA Local Type ordinal 13784; PDB kind: class.
class __declspec(align(4)) idDeclVisionDamage : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13785.
  virtual ~idDeclVisionDamage();
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

  idVisionDamageElement contrast;
  idVisionDamageElement brightness;
  idVisionDamageElement brightnessAdd;
  idVisionDamageElement saturation;
  idVisionDamageElement tintRed;
  idVisionDamageElement tintGreen;
  idVisionDamageElement tintBlue;
  idVisionDamageElement doubleVision;
  idVisionDamageElement blur;
  idVisionDamageElement negative;
  idVisionDamageElement chromaticAberration;
  idVisionDamageElement radialBlur;
  idVisionDamageElement distortion;
  idVisionDamageElement colorDodge;
  idVisionDamageElement colorBurn;
  bool interruptible;
  bool applyAfterDeath;
};

// IDA Local Type ordinal 13786; PDB kind: struct.
struct idDeclDamage::damageScreenEffectParms_t
{
  float screenDamageTime;
  idMaterial *screenDamageMtr;
  idVec2 screenDamageSize;
  idVec2 offsetPctX;
  idVec2 offsetPctY;
  idVec2 distribPctX;
  idVec2 distribPctY;
  idVec2 driftYAmount;
  idVec2 delay;
  float fadeOutTime;
  int screenDamageFrames;
  int numQuads;
};

// IDA Local Type ordinal 13787; PDB kind: struct.
struct idDeclDamage::damageScreenEffect_t
{
  idDeclDamage::damageScreenEffectParms_t parms;
  float damagePct;
  float radius;
};

// IDA Local Type ordinal 13788; PDB kind: struct.
struct idDeclDamage::damageFeedbackScreenEffects_t
{
  idDeclDamage::damageScreenEffect_t feedbackSmall;
  idDeclDamage::damageScreenEffect_t feedbackMedium;
  idDeclDamage::damageScreenEffect_t feedbackLarge;
  idDeclDamage::damageScreenEffect_t feedbackGib;
};

// IDA Local Type ordinal 13789; PDB kind: struct.
struct idDeclDamage::playerDamageScreenEffects_t
{
  idDeclDamage::damageScreenEffect_t damageSmall;
  idDeclDamage::damageScreenEffect_t damageMedium;
  idDeclDamage::damageScreenEffect_t damageLarge;
};

// IDA Local Type ordinal 13793; PDB kind: class.
class idDeclDamage : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13794.
  virtual ~idDeclDamage();
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

  idStr damageName;
  idDeclDamage::damageType_t damageTypes;
  idDeclDamage::goreType_t goreTypes;
  idDeclDamage::damageSource_t damageSource;
  idHandsHitReactionType_t handsHitReactionType;
  idPlayerBodyReactionDescriptor_t playerBodyReactionDescriptor;
  const idDeclVisionDamage *visionDamage;
  float minDamage;
  float maxDamage;
  float vehicleDamageScale;
  float selfDamageScale;
  float playerDamageScale;
  bool damageIsCurrentHealth;
  bool ignoreGodMode;
  bool ignoreArmor;
  bool ignorePlayer;
  bool ignoreArmoredBreakables;
  bool ignoreFriendlyFire;
  bool isMelee;
  bool burning;
  bool noSound;
  bool stuns;
  bool instantRagdoll;
  bool ragdollOnDeath;
  bool coopSpecial;
  bool simplifiedRadiusDamage;
  int knockBack;
  int knockUp;
  float selfKnockbackScale;
  bool absoluteknockBack;
  float kickTime;
  float kickAmplitude;
  idVec3 kickDir;
  float radius;
  int radiusInner;
  int radiusOuterDamageStrength;
  float ragdollImpulseMag;
  float vehicleImpulseMag;
  float blur;
  float blurTime;
  float doubleVision;
  float doubleVisionTime;
  fxCondition_t hitFXStartCondition;
  damageIntensity_t intensity;
  idSoundShader *damageSound;
  bool isStealthy;
  specialDeath_t specialDeathType;
  bool friendlyFire;
  bool knocksOffArmor;
  idDeclDamage::damageFeedbackScreenEffects_t feedbackScreenEffects;
  idDeclDamage::playerDamageScreenEffects_t playerDamageScreenEffects;
  const idMaterial *damageIcon;
  idDeclGoreBehavior *declGoreBehavior;
};

// IDA Local Type ordinal 17978; PDB kind: class.
class idDeclDamageBoostItem : public idDeclInventory
{
public:
  // Recovered virtual interface; IDA vtable ordinal 17979.
  virtual ~idDeclDamageBoostItem();
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

  float damageBoostMultiplier;
  float damageBoostDuration;
};
