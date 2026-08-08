
// ========================================================================
// ?Parse@idDeclDamage@@UAAXAAVidParser@@@Z
// EA  : 0x82BBD598
// RVA : 0x00BBD598
// PDB : w:\tech5\tungsten\game\decls\decldamage.cpp
// ========================================================================

// attributes: thunk
void __fastcall idDeclDamage::Parse(idDeclVehicleProps *this, idParser *src)
{
  idDeclTypeInfo::Parse(this: &this->idDeclTypeInfo, src);
}


// ========================================================================
// ??1idDeclDamage@@UAA@XZ
// EA  : 0x82BBD860
// RVA : 0x00BBD860
// PDB : w:\tech5\tungsten\game\decls\decldamage.cpp
// ========================================================================

void __fastcall idDeclDamage::~idDeclDamage(idDeclDamage *this)
{
  this->__vftable = (idDeclDamage_vtbl *)&idDeclDamage::`vftable';
  idStr::FreeData(this: &this->damageName);
  idDeclTypeInfo::~idDeclTypeInfo(this: &this->idDeclTypeInfo);
}


// ========================================================================
// __unwind$487760
// EA  : 0x82BBD8B4
// RVA : 0x00BBD8B4
// PDB : w:\tech5\tungsten\game\decls\decldamage.cpp
// ========================================================================

void _unwind_487760()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// ?DamageAmount@idDeclDamage@@QBAMXZ
// EA  : 0x82BBD8F0
// RVA : 0x00BBD8F0
// PDB : w:\tech5\tungsten\game\decls\decldamage.cpp
// ========================================================================

float __fastcall idDeclDamage::DamageAmount(idDeclDamage *this)
{
  __int64 v1; // r11
  unsigned int v2; // r4
  double v3; // fp1

  HIDWORD(v1) = 1638400;
  v2 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v2;
  LODWORD(v1) = (v2 >> 10) & 0x7FFF;
  v3 = (float)((float)((float)((float)v1 * (float)0.000030518509) * (float)(this->maxDamage - this->minDamage))
             + this->minDamage);
  return *((float *)&v3 + 1);
}


// ========================================================================
// ??0idDeclDamage@@QAA@XZ
// EA  : 0x82BBD958
// RVA : 0x00BBD958
// PDB : w:\tech5\tungsten\game\decls\decldamage.cpp
// ========================================================================

idDeclDamage *__fastcall idDeclDamage::idDeclDamage(idDeclDamage *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclDamage_vtbl *)&idDeclDamage::`vftable';
  idStr::idStr(this: &this->damageName, text: "default");
  this->goreTypes = GORETYPE_NONE;
  this->damageTypes = DAMAGETYPE_GENERIC;
  this->damageSource = DAMAGESRC_UNKNOWN;
  this->handsHitReactionType = HITREACTION_GENERIC;
  this->playerBodyReactionDescriptor.name.str = &byte_8200D768;
  this->playerBodyReactionDescriptor.type = PLAYER_BODY_REACTION_NONE;
  this->playerBodyReactionDescriptor.useAlive = false;
  this->playerBodyReactionDescriptor.useDead = false;
  this->playerBodyReactionDescriptor.throwsPlayer = false;
  this->kickAmplitude = 0.80000001;
  this->visionDamage = nullptr;
  this->minDamage = 1.0;
  this->damageIsCurrentHealth = false;
  this->maxDamage = 1.0;
  this->ignoreGodMode = false;
  this->vehicleDamageScale = 1.0;
  this->ignoreArmor = false;
  this->selfDamageScale = 1.0;
  this->ignorePlayer = false;
  this->playerDamageScale = 1.0;
  this->ignoreArmoredBreakables = false;
  this->selfKnockbackScale = 1.0;
  this->ignoreFriendlyFire = false;
  this->kickTime = 150.0;
  this->isMelee = false;
  this->burning = false;
  this->noSound = false;
  this->stuns = false;
  this->instantRagdoll = false;
  this->ragdollOnDeath = false;
  this->coopSpecial = false;
  this->simplifiedRadiusDamage = false;
  this->knockBack = 0;
  this->knockUp = 0;
  this->absoluteknockBack = false;
  this->kickDir.y = 1.0;
  this->kickDir.x = 0.0;
  this->kickDir.z = 0.0;
  this->radiusInner = 0;
  this->radius = 0.0;
  this->radiusOuterDamageStrength = 0;
  this->ragdollImpulseMag = 0.0;
  this->hitFXStartCondition = FX_MAX_CONDITIONS;
  this->vehicleImpulseMag = 0.0;
  this->intensity = DAMAGEINTENSITY_NONE;
  this->blur = 1.5;
  this->damageSound = nullptr;
  this->blurTime = 150.0;
  this->isStealthy = false;
  this->doubleVision = 0.1;
  this->specialDeathType = DEATH_INSTANT;
  this->doubleVisionTime = 130.0;
  this->friendlyFire = true;
  this->knocksOffArmor = true;
  idDeclDamage::damageFeedbackScreenEffects_t::damageFeedbackScreenEffects_t(this: &this->feedbackScreenEffects);
  idDeclDamage::playerDamageScreenEffects_t::playerDamageScreenEffects_t(this: &this->playerDamageScreenEffects);
  this->feedbackScreenEffects.feedbackSmall.damagePct = 0.1;
  this->damageIcon = nullptr;
  this->declGoreBehavior = nullptr;
  this->feedbackScreenEffects.feedbackMedium.damagePct = 0.2;
  this->feedbackScreenEffects.feedbackLarge.damagePct = 0.30000001;
  return this;
}


// ========================================================================
// __unwind$487830
// EA  : 0x82BBDB0C
// RVA : 0x00BBDB0C
// PDB : w:\tech5\tungsten\game\decls\decldamage.cpp
// ========================================================================

void _unwind_487830()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 128 + 148));
}

