#pragma once

// Reconstructed C++ declarations from IDA Local Types and PDB/DIA metadata.
// Original PDB header: w:\tech5\tungsten\game\decls\declprojectile.h
// Recovered logical types: 16
// Signatures retain Xbox 360 ABI evidence and may still require manual review.


// IDA Local Type ordinal 1043; PDB kind: enum.
enum idDeclProjectile::notHitscanInfo_t::homingInfo_t::attackStyle_t : __int32
{
  CLUSTER_BOMB = 0x0,
  GUIDED_RPG = 0x1,
  JAVELIN = 0x2,
};

// IDA Local Type ordinal 1112; PDB kind: enum.
enum idDeclProjectile::projectileClientPredictive_t : __int32
{
  PROJCLIENT_NONE = 0x0,
  PROJCLIENT_GRENADE = 0x1,
  PROJCLIENT_ROCKET = 0x2,
  PROJCLIENT_HOMING = 0x3,
};

// IDA Local Type ordinal 2061; PDB kind: enum.
enum idDeclProjectile::aiDodgeType_t : __int32
{
  AI_DODGE_TYPE_MELEE = 0x0,
  AI_DODGE_TYPE_LIGHT = 0x1,
  AI_DODGE_TYPE_MEDIUM = 0x2,
  AI_DODGE_TYPE_HEAVY_CLOSE_RANGE = 0x3,
  AI_DODGE_TYPE_HEAVY_MEDIUM_RANGE = 0x4,
  AI_DODGE_TYPE_HEAVY_LONG_RANGE = 0x5,
};

// IDA Local Type ordinal 2876; PDB kind: enum.
enum idDeclProjectile::projectileSoundEvent_t : __int32
{
  PROJSOUND_NONE = 0x0,
  PROJSOUND_NORMAL = 0x1,
  PROJSOUND_SILENCED = 0x2,
};

// IDA Local Type ordinal 13774; PDB kind: struct.
struct __declspec(align(4)) idDeclProjectileImpactEffect::projectileImpactEffect_t
{
  idList<idMaterial const *,5> decalMaterial;
  float decalSize;
  int decalLifetime;
  float decalDepth;
  float decalAngle;
  bool decalQuad;
  const idDeclParticle *particleImpact;
  const idSoundShader *sndImpact;
  bool useSmokeSystem;
  bool isBloody;
};

// IDA Local Type ordinal 13775; PDB kind: class.
class idDeclProjectileImpactEffect : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13776.
  virtual ~idDeclProjectileImpactEffect();
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

  idDeclProjectileImpactEffect::projectileImpactEffect_t debugDefaultEffect;
  idDeclProjectileImpactEffect::projectileImpactEffect_t defaultEffect;
  idDeclProjectileImpactEffect::projectileImpactEffect_t metalEffect;
  idDeclProjectileImpactEffect::projectileImpactEffect_t metalHollow;
  idDeclProjectileImpactEffect::projectileImpactEffect_t metalSheet;
  idDeclProjectileImpactEffect::projectileImpactEffect_t stoneEffect;
  idDeclProjectileImpactEffect::projectileImpactEffect_t fleshEffect;
  idDeclProjectileImpactEffect::projectileImpactEffect_t fleshPlayerEffect;
  idDeclProjectileImpactEffect::projectileImpactEffect_t woodEffect;
  idDeclProjectileImpactEffect::projectileImpactEffect_t cardboardEffect;
  idDeclProjectileImpactEffect::projectileImpactEffect_t liquidEffect;
  idDeclProjectileImpactEffect::projectileImpactEffect_t glassEffect;
  idDeclProjectileImpactEffect::projectileImpactEffect_t plasticEffect;
  idDeclProjectileImpactEffect::projectileImpactEffect_t asphaltEffect;
  idDeclProjectileImpactEffect::projectileImpactEffect_t dirtEffect;
  idDeclProjectileImpactEffect::projectileImpactEffect_t concreteEffect;
  idDeclProjectileImpactEffect::projectileImpactEffect_t foilageEffect;
  idDeclProjectileImpactEffect::projectileImpactEffect_t linoleumEffect;
  idDeclProjectileImpactEffect::projectileImpactEffect_t fabricEffect;
  idDeclProjectileImpactEffect::projectileImpactEffect_t rubberEffect;
  idDeclProjectileImpactEffect::projectileImpactEffect_t rockEffect;
  idDeclProjectileImpactEffect::projectileImpactEffect_t steamPipeEffect;
  idDeclProjectileImpactEffect::projectileImpactEffect_t waterPipeEffect;
  idDeclProjectileImpactEffect::projectileImpactEffect_t armorEffect;
  idDeclProjectileImpactEffect::projectileImpactEffect_t sludgeEffect;
  idDeclProjectileImpactEffect::projectileImpactEffect_t bloodPoolEffect;
  idDeclProjectileImpactEffect::projectileImpactEffect_t mutantFleshEffect;
  idDeclProjectileImpactEffect::projectileImpactEffect_t thickPaddingEffect;
  idDeclProjectileImpactEffect::projectileImpactEffect_t ricketyMetal;
  idDeclProjectileImpactEffect::projectileImpactEffect_t ricketyWood;
  idDeclProjectileImpactEffect::projectileImpactEffect_t bloodReplacementEffect;
};

// IDA Local Type ordinal 13778; PDB kind: struct.
struct __declspec(align(4)) idDeclProjectile::notHitscanInfo_t::physicsProperties_t
{
  float density;
  float linearFriction;
  float angularFriction;
  float contactFriction;
  float linearFrictionWater;
  float angularFrictionWater;
  float bounciness;
  bool noGravity;
};

// IDA Local Type ordinal 13779; PDB kind: struct.
struct idDeclProjectile::notHitscanInfo_t::explosion_t
{
  int minDetonationDelay;
  int maxDetonationDelay;
  bool countDownOnThrow;
  bool cookable;
  bool inheritParentSpeed;
  const idSoundShader *warningSound;
  const idSoundShader *bounceSound;
  float minSpeed;
  float maxSpeed;
};

// IDA Local Type ordinal 13780; PDB kind: struct.
struct idDeclProjectile::notHitscanInfo_t::homingInfo_t
{
  int arcMinAngle;
  int arcMaxAngle;
  float heightLimit;
  idDeclProjectile::notHitscanInfo_t::homingInfo_t::attackStyle_t attackStyle;
};

// IDA Local Type ordinal 13781; PDB kind: struct.
struct idDeclProjectile::notHitscanInfo_t
{
  bool fireFromMuzzle;
  const idDeclEntityDef *entityDef;
  idDeclProjectile::notHitscanInfo_t::physicsProperties_t physicsProperties;
  const idSoundShader *explodeSound;
  const idSoundShader *flySound;
  int thrustDelay;
  int thrustDelayVariance;
  bool useLocking;
  bool fireAtPoint;
  float speed;
  bool explodeOnImpact;
  bool isRetrievable;
  bool allowOnlyOne;
  bool followDeployableRules;
  bool inheritParentSpeed;
  bool adjustStartForCollision;
  float adjustFireAngle;
  const idSoundShader *breakAwaySnd;
  idDeclProjectile::notHitscanInfo_t::explosion_t grenadeInfo;
  bool parabolicFlight;
  float minTrajectoryTime;
  float maxTrajectoryTime;
  idDeclProjectile::notHitscanInfo_t::homingInfo_t homingInfo;
};

// IDA Local Type ordinal 13795; PDB kind: class.
class idDeclProjectile : public idDeclTypeInfo
{
public:
  // Recovered virtual interface; IDA vtable ordinal 13801.
  virtual ~idDeclProjectile();
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

  idDeclProjectile::projectileClientPredictive_t clientType;
  idStr clientModelName;
  idVec3 clientMinAngularVelocity;
  idVec3 clientMaxAngularVelocity;
  float clientMaxSpeed;
  float clientMinSpeed;
  bool hitscan;
  bool hitscan_till_solid;
  bool hitscan_through_vehicles;
  bool hitscan_through_water;
  float deviation;
  bool ribbonEffect;
  idList<projectileEnvSound,5> envFireSounds;
  idList<projectileEnvSound,5> envOnlineFireSounds;
  idList<projectileEnvSound,5> envLastShotSound;
  idList<projectileEnvSound,5> envOnlineLastShotSound;
  const idSoundShader *fireSound;
  const idSoundShader *onlineFireSound;
  const idSoundShader *lastShotSound;
  const idSoundShader *onlineLastShotSound;
  bool skipEndSoundOnEarlyRelease;
  idDeclProjectile::aiDodgeType_t aiDodgeType;
  const idDeclAiEvent *aiEventDecl;
  const idDeclAiEvent *playerAIEventDecl;
  const idDeclAiEvent *explodeAIEventDecl;
  const idDeclAiEvent *collideAIEventDecl;
  const idDeclProjectileImpactEffect *impactEffectTable;
  const idDeclFX *fxDecl;
  const idDeclFX *fxDeclQuad;
  idEntityInfluenceTrail impactInfluence;
  idEntityInfluenceTrail influence;
  idDeclProjectile::notHitscanInfo_t notHitscanInfo;
  const idDeclDamage *damageDecl;
  float damageFalloff;
  const idDeclDamage *splashDamageDecl;
  const idDeclDamage *electricDamageDecl;
  const idDeclProjectile *delayedProjectile;
  int delayedProjectileDelayMS;
  int maxRange;
  int minRange;
  int optimalRange;
  int maxOptimalRange;
  int aimAssistRange;
  float aimAssistZoomSnapScale;
  float spread;
  int spawnCount;
  idDeclProjectile::tracerInfo_t tracerInfo;
  idDeclProjectile::waterInteraction_t waterInteraction;
  idDeclProjectile::weaponFeedBack_t weaponFeedBack;
  idDeclProjectile::laserDotInfo_t laserDotInfo;
};

// IDA Local Type ordinal 13796; PDB kind: struct.
struct idDeclProjectile::tracerInfo_t
{
  const idMaterial *tracerMtr;
  const idMaterial *tracerMtrQuad;
  int tracers;
  bool doRandomTracers;
  float tracerSpeed;
  float tracerLength;
  float tracerHeight;
  idVec3 tracerZoomedOffset;
  const idSoundShader *sndTracer;
};

// IDA Local Type ordinal 13797; PDB kind: struct.
struct idDeclProjectile::waterInteraction_t
{
  bool allowWaterInteraction;
  float waterHitMagnitude;
  float waterHitRadius;
  bool shouldIlluminateWater;
  float waterIlluminationRadius;
  int waterIlluminateTime;
};

// IDA Local Type ordinal 13798; PDB kind: struct.
struct idDeclProjectile::weaponFeedBack_t::weaponKikInfo_t
{
  float kick;
  float maxKick;
  float recoilSpeed;
  float recoverySpeed;
};

// IDA Local Type ordinal 13799; PDB kind: struct.
struct idDeclProjectile::weaponFeedBack_t
{
  idDeclProjectile::weaponFeedBack_t::weaponKikInfo_t weaponKickInfo[5];
  float controllerShakeHighMag;
  int controllerShakeHighTime;
  float controllerShakeLowMag;
  int controllerShakeLowTime;
  float spreadAdditionPerShot;
  float spreadAdditionMax;
  float spreadRecoveryDelay;
};

// IDA Local Type ordinal 13800; PDB kind: struct.
struct idDeclProjectile::laserDotInfo_t
{
  const idMaterial *laserDotMtr;
  float laserDotSize;
  float laserDotDepth;
  float laserDotMinSizeScale;
  float laserDotMaxSizeScale;
  float laserDotMaxDistance;
};
