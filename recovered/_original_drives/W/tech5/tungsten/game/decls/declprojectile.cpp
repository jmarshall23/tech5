
// ========================================================================
// ?GetImpactEffectForMaterial@idDeclProjectileImpactEffect@@QBAPBUprojectileImpactEffect_t@1@H@Z
// EA  : 0x82BCAD20
// RVA : 0x00BCAD20
// PDB : w:\tech5\tungsten\game\decls\declprojectile.cpp
// ========================================================================

const idDeclProjectileImpactEffect::projectileImpactEffect_t *__fastcall idDeclProjectileImpactEffect::GetImpactEffectForMaterial(
        idDeclProjectileImpactEffect *this,
        int materialID)
{
  const idDeclProjectileImpactEffect::projectileImpactEffect_t *result; // r3

  result = &this->defaultEffect;
  if ( g_projectileImpactDebug.valueInteger != 0 )
    result = &this->debugDefaultEffect;
  switch ( materialID )
  {
    case 1:
      result = &this->metalEffect;
      break;
    case 2:
      result = &this->stoneEffect;
      break;
    case 3:
      result = &this->fleshEffect;
      break;
    case 4:
      result = &this->woodEffect;
      break;
    case 5:
      result = &this->cardboardEffect;
      break;
    case 6:
      result = &this->liquidEffect;
      break;
    case 7:
      result = &this->glassEffect;
      break;
    case 8:
      result = &this->plasticEffect;
      break;
    case 9:
      result = &this->asphaltEffect;
      break;
    case 10:
      result = &this->dirtEffect;
      break;
    case 11:
      result = &this->concreteEffect;
      break;
    case 12:
      result = &this->foilageEffect;
      break;
    case 13:
      result = &this->linoleumEffect;
      break;
    case 14:
      result = &this->fabricEffect;
      break;
    case 15:
      result = &this->rubberEffect;
      break;
    case 16:
      result = &this->rockEffect;
      break;
    case 17:
      result = &this->steamPipeEffect;
      break;
    case 18:
      result = &this->waterPipeEffect;
      break;
    case 19:
      result = &this->armorEffect;
      break;
    case 20:
      result = &this->sludgeEffect;
      break;
    case 22:
      result = &this->metalHollow;
      break;
    case 23:
      result = &this->fleshPlayerEffect;
      break;
    case 25:
      result = &this->bloodPoolEffect;
      break;
    case 27:
      result = &this->mutantFleshEffect;
      break;
    case 28:
      result = &this->thickPaddingEffect;
      break;
    case 30:
      result = &this->ricketyMetal;
      break;
    case 31:
      result = &this->ricketyWood;
      break;
    case 32:
      result = &this->metalSheet;
      break;
    default:
      break;
  }
  if ( g_EnableGore.valueInteger == 0 )
  {
    if ( !result->isBloody )
      return result;
    return &this->bloodReplacementEffect;
  }
  if ( g_EnableGore.valueInteger == 2 && materialID == 3 )
    return &this->bloodReplacementEffect;
  return result;
}


// ========================================================================
// ??0idDeclProjectile@@QAA@XZ
// EA  : 0x82BCAF08
// RVA : 0x00BCAF08
// PDB : w:\tech5\tungsten\game\decls\declprojectile.cpp
// ========================================================================

idDeclProjectile *__fastcall idDeclProjectile::idDeclProjectile(idDeclProjectile *this)
{
  float z; // r6
  const idDeclAiEvent *v3; // r3

  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->clientType = PROJCLIENT_NONE;
  this->__vftable = (idDeclProjectile_vtbl *)&idDeclProjectile::`vftable';
  this->clientModelName.allocedAndFlag = 20;
  this->clientModelName.data = this->clientModelName.baseBuffer;
  this->clientModelName.len = 0;
  this->clientModelName.baseBuffer[0] = 0;
  this->clientMinAngularVelocity = vec3_origin;
  this->clientMaxAngularVelocity.x = vec3_origin.x;
  this->clientMaxAngularVelocity.y = vec3_origin.y;
  z = vec3_origin.z;
  this->clientMaxSpeed = 0.0;
  this->clientMinSpeed = 0.0;
  this->clientMaxAngularVelocity.z = z;
  this->deviation = 0.0;
  this->hitscan = true;
  this->hitscan_till_solid = false;
  this->hitscan_through_vehicles = false;
  this->hitscan_through_water = false;
  this->ribbonEffect = false;
  this->envFireSounds.list = nullptr;
  this->envFireSounds.granularity = 0;
  this->envFireSounds.memTag = 5;
  this->envFireSounds.listStatic = 0;
  this->envFireSounds.size = 0;
  this->envFireSounds.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->envFireSounds);
  this->envOnlineFireSounds.list = nullptr;
  this->envOnlineFireSounds.granularity = 0;
  this->envOnlineFireSounds.memTag = 5;
  this->envOnlineFireSounds.listStatic = 0;
  this->envOnlineFireSounds.size = 0;
  this->envOnlineFireSounds.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->envOnlineFireSounds);
  this->envLastShotSound.list = nullptr;
  this->envLastShotSound.granularity = 0;
  this->envLastShotSound.memTag = 5;
  this->envLastShotSound.listStatic = 0;
  this->envLastShotSound.size = 0;
  this->envLastShotSound.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->envLastShotSound);
  this->envOnlineLastShotSound.list = nullptr;
  this->envOnlineLastShotSound.granularity = 0;
  this->envOnlineLastShotSound.memTag = 5;
  this->envOnlineLastShotSound.listStatic = 0;
  this->envOnlineLastShotSound.size = 0;
  this->envOnlineLastShotSound.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->envOnlineLastShotSound);
  this->fireSound = nullptr;
  this->onlineFireSound = nullptr;
  this->lastShotSound = nullptr;
  this->onlineLastShotSound = nullptr;
  this->skipEndSoundOnEarlyRelease = false;
  this->aiDodgeType = AI_DODGE_TYPE_MEDIUM;
  this->aiEventDecl = nullptr;
  this->playerAIEventDecl = nullptr;
  this->impactEffectTable = nullptr;
  this->fxDecl = nullptr;
  this->fxDeclQuad = nullptr;
  this->impactInfluence.innerRadius = 32.0;
  this->impactInfluence.outerRadius = 64.0;
  this->impactInfluence.angle = 0.0;
  this->impactInfluence.trailDist = 32.0;
  this->impactInfluence.trailFadeInTime = 0.25;
  this->impactInfluence.trailFadeOutTime = 2.0;
  this->influence.innerRadius = 32.0;
  this->influence.outerRadius = 64.0;
  this->influence.angle = 0.0;
  this->influence.trailDist = 32.0;
  this->influence.trailFadeInTime = 0.25;
  this->influence.trailFadeOutTime = 2.0;
  this->damageDecl = nullptr;
  this->splashDamageDecl = nullptr;
  this->damageFalloff = 1.0;
  this->electricDamageDecl = nullptr;
  this->aimAssistZoomSnapScale = 1.0;
  this->delayedProjectile = nullptr;
  this->spread = 1.0;
  this->delayedProjectileDelayMS = 0;
  this->maxRange = 0x2000;
  this->minRange = 0;
  this->optimalRange = 512;
  this->maxOptimalRange = 2048;
  this->aimAssistRange = 0x2000;
  this->spawnCount = 1;
  this->explodeAIEventDecl = (const idDeclAiEvent *)idDeclInfo::FindWithInheritance(
                                                      this: &idDeclAiEvent::resourceList,
                                                      name: "base/explosion/explosion",
                                                      makeDefault: true);
  v3 = (const idDeclAiEvent *)idDeclInfo::FindWithInheritance(
                                this: &idDeclAiEvent::resourceList,
                                name: "base/sound/projectileimpact",
                                makeDefault: true);
  this->notHitscanInfo.physicsProperties.linearFriction = 0.0;
  this->notHitscanInfo.physicsProperties.angularFriction = 0.0;
  this->notHitscanInfo.physicsProperties.density = 0.0099999998;
  this->notHitscanInfo.physicsProperties.bounciness = 0.60000002;
  this->notHitscanInfo.speed = 500.0;
  this->collideAIEventDecl = v3;
  this->notHitscanInfo.fireFromMuzzle = true;
  this->notHitscanInfo.entityDef = nullptr;
  this->notHitscanInfo.physicsProperties.noGravity = false;
  this->notHitscanInfo.physicsProperties.linearFrictionWater = 0.1;
  this->notHitscanInfo.explodeSound = nullptr;
  this->notHitscanInfo.physicsProperties.angularFrictionWater = 0.1;
  this->notHitscanInfo.flySound = nullptr;
  this->notHitscanInfo.grenadeInfo.minSpeed = 256.0;
  this->notHitscanInfo.useLocking = true;
  this->notHitscanInfo.fireAtPoint = false;
  this->notHitscanInfo.explodeOnImpact = false;
  this->notHitscanInfo.physicsProperties.contactFriction = 0.5;
  this->notHitscanInfo.isRetrievable = true;
  this->notHitscanInfo.adjustFireAngle = 0.0;
  this->notHitscanInfo.allowOnlyOne = false;
  this->notHitscanInfo.homingInfo.heightLimit = 0.0;
  this->notHitscanInfo.followDeployableRules = false;
  this->notHitscanInfo.minTrajectoryTime = 0.0;
  this->notHitscanInfo.inheritParentSpeed = true;
  this->notHitscanInfo.maxTrajectoryTime = 0.0;
  this->notHitscanInfo.adjustStartForCollision = false;
  this->notHitscanInfo.grenadeInfo.maxSpeed = 1024.0;
  this->notHitscanInfo.breakAwaySnd = nullptr;
  this->tracerInfo.tracerSpeed = 2500.0;
  this->notHitscanInfo.grenadeInfo.minDetonationDelay = 0;
  this->tracerInfo.tracerLength = 48.0;
  this->notHitscanInfo.grenadeInfo.maxDetonationDelay = 0;
  this->tracerInfo.tracerHeight = 4.0;
  this->notHitscanInfo.grenadeInfo.countDownOnThrow = true;
  this->notHitscanInfo.grenadeInfo.cookable = false;
  this->notHitscanInfo.grenadeInfo.inheritParentSpeed = false;
  this->notHitscanInfo.grenadeInfo.warningSound = nullptr;
  this->notHitscanInfo.grenadeInfo.bounceSound = nullptr;
  this->notHitscanInfo.homingInfo.arcMinAngle = 0;
  this->notHitscanInfo.homingInfo.arcMaxAngle = 0;
  this->notHitscanInfo.homingInfo.attackStyle = GUIDED_RPG;
  this->notHitscanInfo.parabolicFlight = false;
  this->notHitscanInfo.thrustDelay = 0;
  this->notHitscanInfo.thrustDelayVariance = 0;
  this->tracerInfo.tracerMtr = nullptr;
  this->tracerInfo.tracerMtrQuad = nullptr;
  this->tracerInfo.tracers = 5;
  this->tracerInfo.doRandomTracers = false;
  this->tracerInfo.tracerZoomedOffset.x = 10.0;
  this->tracerInfo.tracerZoomedOffset.y = 0.0;
  this->tracerInfo.tracerZoomedOffset.z = -5.0;
  this->tracerInfo.sndTracer = nullptr;
  this->weaponFeedBack.weaponKickInfo[1].kick = 0.5;
  this->waterInteraction.waterHitRadius = 10.0;
  this->waterInteraction.waterIlluminationRadius = 0.0;
  this->waterInteraction.waterHitMagnitude = -30.0;
  this->weaponFeedBack.weaponKickInfo[1].maxKick = 1.0;
  this->waterInteraction.allowWaterInteraction = false;
  this->waterInteraction.shouldIlluminateWater = false;
  this->waterInteraction.waterIlluminateTime = 0;
  this->weaponFeedBack.weaponKickInfo[1].recoilSpeed = 25.0;
  this->weaponFeedBack.weaponKickInfo[1].recoverySpeed = 7.5;
  this->weaponFeedBack.weaponKickInfo[0].kick = 0.34999999;
  this->weaponFeedBack.weaponKickInfo[0].maxKick = 0.69999999;
  this->weaponFeedBack.weaponKickInfo[0].recoilSpeed = 17.0;
  this->weaponFeedBack.weaponKickInfo[0].recoverySpeed = 5.0;
  this->weaponFeedBack.weaponKickInfo[2].kick = 0.75;
  this->weaponFeedBack.weaponKickInfo[2].maxKick = 25.0;
  this->weaponFeedBack.weaponKickInfo[2].recoilSpeed = 25.0;
  this->weaponFeedBack.weaponKickInfo[2].recoverySpeed = 14.0;
  this->weaponFeedBack.weaponKickInfo[3].kick = 0.40000001;
  this->weaponFeedBack.weaponKickInfo[3].maxKick = 8.0;
  this->weaponFeedBack.weaponKickInfo[3].recoilSpeed = 25.0;
  this->weaponFeedBack.weaponKickInfo[3].recoverySpeed = 8.0;
  this->weaponFeedBack.controllerShakeHighMag = 0.0;
  this->weaponFeedBack.controllerShakeHighTime = 0;
  this->weaponFeedBack.controllerShakeLowMag = 0.0;
  this->weaponFeedBack.controllerShakeLowTime = 0;
  this->weaponFeedBack.spreadAdditionPerShot = 0.25;
  this->weaponFeedBack.spreadAdditionMax = 3.0;
  this->weaponFeedBack.spreadRecoveryDelay = 100.0;
  this->laserDotInfo.laserDotMtr = nullptr;
  this->laserDotInfo.laserDotSize = 350.0;
  this->laserDotInfo.laserDotDepth = 15.0;
  this->laserDotInfo.laserDotMinSizeScale = 0.25;
  this->laserDotInfo.laserDotMaxSizeScale = 3.0;
  this->laserDotInfo.laserDotMaxDistance = 5000.0;
  return this;
}


// ========================================================================
// __unwind$487371
// EA  : 0x82BCB3BC
// RVA : 0x00BCB3BC
// PDB : w:\tech5\tungsten\game\decls\declprojectile.cpp
// ========================================================================

void _unwind_487371()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 176 + 196));
}


// ========================================================================
// __unwind$487372
// EA  : 0x82BCB3E4
// RVA : 0x00BCB3E4
// PDB : w:\tech5\tungsten\game\decls\declprojectile.cpp
// ========================================================================

void _unwind_487372()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 176 + 196) + 68));
}


// ========================================================================
// __unwind$487373
// EA  : 0x82BCB410
// RVA : 0x00BCB410
// PDB : w:\tech5\tungsten\game\decls\declprojectile.cpp
// ========================================================================

void _unwind_487373()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 144));
}


// ========================================================================
// __unwind$487374
// EA  : 0x82BCB43C
// RVA : 0x00BCB43C
// PDB : w:\tech5\tungsten\game\decls\declprojectile.cpp
// ========================================================================

void _unwind_487374()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 160));
}


// ========================================================================
// __unwind$487375
// EA  : 0x82BCB468
// RVA : 0x00BCB468
// PDB : w:\tech5\tungsten\game\decls\declprojectile.cpp
// ========================================================================

void _unwind_487375()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 176));
}


// ========================================================================
// __unwind$487376
// EA  : 0x82BCB494
// RVA : 0x00BCB494
// PDB : w:\tech5\tungsten\game\decls\declprojectile.cpp
// ========================================================================

void _unwind_487376()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 176 + 196) + 192));
}


// ========================================================================
// `dynamic initializer for 'g_projectileImpactDebug''
// EA  : 0x833723D0
// RVA : 0x013723D0
// PDB : w:\tech5\tungsten\game\decls\declprojectile.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__g_projectileImpactDebug__()
{
  idCVar::idCVar(
    this: &g_projectileImpactDebug,
    name: "g_projectileImpactDebug",
    value: "0",
    flags: 1,
    description: "Use invalid surface as impact effect and decal instead for default",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__g_projectileImpactDebug__);
}

