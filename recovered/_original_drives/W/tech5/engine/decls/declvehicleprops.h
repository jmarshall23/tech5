
// ========================================================================
// ??0idVehicleEffectsDef@@QAA@XZ
// EA  : 0x82622998
// RVA : 0x00622998
// PDB : w:\tech5\engine\decls\declvehicleprops.h
// ========================================================================

idVehicleEffectsDef *__fastcall idVehicleEffectsDef::idVehicleEffectsDef(idVehicleEffectsDef *this)
{
  this->dustVelocityScale = 0.25;
  this->tireKickup = nullptr;
  this->tireKickup2 = nullptr;
  this->tireKickupSpacing = 32.0;
  this->tireInitialKickup = nullptr;
  this->tireKickup2Spacing = 32.0;
  this->rolloverKickup = nullptr;
  this->tireSkidParms.fadeTime = 500;
  this->tireSkidParms.halfLength = 32.0;
  this->tireSkidParms.lifeTime = 2000;
  this->tireSkidParms.halfWidth = 16.0;
  this->tireSkidParms.material.metal = nullptr;
  this->tireSkidParms.material.stone = nullptr;
  this->tireSkidParms.material.wood = nullptr;
  this->tireSkidParms.material.cardboard = nullptr;
  this->tireSkidParms.material.liquid = nullptr;
  this->tireSkidParms.material.glass = nullptr;
  this->tireSkidParms.material.plastic = nullptr;
  this->tireSkidParms.material.dirt = nullptr;
  this->tireSkidParms.material.asphalt = nullptr;
  this->tireSkidParms.material.concrete = nullptr;
  this->tireSkidParms.material.linoleum = nullptr;
  this->tireSkidParms.material.fabric = nullptr;
  this->tireSkidParms.material.rubber = nullptr;
  this->tireSkidParms.material.rock = nullptr;
  this->tireSkidParms.material.foliage = nullptr;
  this->tireTrackParms.halfWidth = 16.0;
  this->tireTrackParms.fadeTime = 500;
  this->tireTrackParms.halfLength = 32.0;
  this->tireTrackParms.lifeTime = 2000;
  this->tireTrackParms.material.metal = nullptr;
  this->tireTrackParms.material.stone = nullptr;
  this->tireTrackParms.material.wood = nullptr;
  this->tireTrackParms.material.cardboard = nullptr;
  this->tireTrackParms.material.liquid = nullptr;
  this->tireTrackParms.material.glass = nullptr;
  this->tireTrackParms.material.plastic = nullptr;
  this->tireTrackParms.material.dirt = nullptr;
  this->tireTrackParms.material.asphalt = nullptr;
  this->tireTrackParms.material.concrete = nullptr;
  this->tireTrackParms.material.linoleum = nullptr;
  this->tireTrackParms.material.fabric = nullptr;
  this->tireTrackParms.material.rubber = nullptr;
  this->tireTrackParms.material.rock = nullptr;
  this->tireTrackParms.material.foliage = nullptr;
  this->particleImpact = nullptr;
  this->particleExplode = nullptr;
  this->particleRpmFlame = nullptr;
  this->particleShotDamage = nullptr;
  this->particleShotShield = nullptr;
  this->breakable = nullptr;
  this->particleAttachmentLost = nullptr;
  this->particleViolentRoll = nullptr;
  this->exhaustEmitterParticle_right = nullptr;
  this->exhaustEmitterParticle_left = nullptr;
  this->vehicleFX = nullptr;
  return this;
}


// ========================================================================
// ??0idVehicleSoundDef@@QAA@XZ
// EA  : 0x82622AA8
// RVA : 0x00622AA8
// PDB : w:\tech5\engine\decls\declvehicleprops.h
// ========================================================================

idVehicleSoundDef *__fastcall idVehicleSoundDef::idVehicleSoundDef(idVehicleSoundDef *this)
{
  this->gears.list = nullptr;
  this->gears.granularity = 0;
  this->gears.memTag = 5;
  this->gears.listStatic = 0;
  this->gears.size = 0;
  this->gears.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->idle.sound = nullptr;
  this->idle.engineSoundFadeInTimeMilliSec = 0;
  this->idle.speedMPH = 10.0;
  this->idle.outTime = 1.0;
  this->idle.loadedUnloadedMPH = 5.0;
  this->idle.loadedUnloadedInTime = 0.2;
  this->idle.loadedUnloadedOutTime = 10.0;
  this->idle.inTime = 4.0;
  this->boostParms.boostOverlayDelay = 1.0;
  this->boostParms.boost = nullptr;
  this->boostParms.boostOverlay = nullptr;
  this->boostParms.boostFull = nullptr;
  this->boostParms.boostEmpty = nullptr;
  this->boostParms.boostNotReady = nullptr;
  this->boostParms.boostFadeOutTime = 1.5;
  this->boostParms.boostPitchModifier = 1.5;
  this->boostParms.minVolume = -60.0;
  this->boostParms.maxVolume = -4.0;
  this->boostParms.boostOverlayFadeInTime = 0.5;
  this->shifting.engineShiftUp = nullptr;
  this->shifting.engineShiftDown = nullptr;
  this->shifting.shiftSilenceTime = 0.050000001;
  this->shifting.playShiftDownDuringCoast = false;
  this->shifting.shiftRampOutTime = 0.050000001;
  this->shifting.playShiftUpOnShiftDown = true;
  this->shifting.shiftUpPercent = 0.89999998;
  this->shifting.shiftDownPercent = 0.69999999;
  this->shifting.shiftRampInTime = 0.0;
  this->revLimiter.delay = 500;
  this->revLimiter.enabled = true;
  this->revLimiter.pitchMultiplier = 1.5;
  this->revLimiter.frequency = 20;
  this->revLimiter.squareMinVolumeMultiplier = 0.25;
  this->revLimiter.throttleMin = 0.5;
  this->windParms.wind = nullptr;
  this->windParms.windVolumeTable = nullptr;
  this->windParms.windPitchTable = nullptr;
  this->brakingReverse.maxReversePitch = 0.40000001;
  this->brakingReverse.brakeWhine = nullptr;
  this->brakingReverse.brakeWhineMPH = 35.0;
  idVehicleSoundDef::surfaceSoundList_t::surfaceSoundList_t(this: &this->surfaceList);
  this->crash.human = nullptr;
  this->crash.vehicle = nullptr;
  this->crash.generic = nullptr;
  this->landing.easy = nullptr;
  this->landing.medium = nullptr;
  this->landing.hard = nullptr;
  this->impact.maxEasyForce = 15000.0;
  this->impact.easy = nullptr;
  this->impact.medium = nullptr;
  this->impact.maxMediumForce = 40000.0;
  this->impact.hard = nullptr;
  this->bumpSounds.delay = 100;
  this->bumpSounds.easyCompression = 0.1;
  this->bumpSounds.easy = nullptr;
  this->tireWobble.minPitch = 0.0;
  this->tireWobble.sound = nullptr;
  this->tireWobble.maxPitch = 0.0;
  this->tireWobble.minVolume = 0.0;
  this->tireWobble.maxVolume = 0.0;
  this->engineDamage.damagedEngine1 = nullptr;
  this->engineDamage.minPitch = 0.0;
  this->engineDamage.damagedEngine2 = nullptr;
  this->engineDamage.maxPitch = 0.0;
  this->engineDamage.damagedEngine3 = nullptr;
  this->engineDamage.minVolume = 0.0;
  this->engineDamage.EngineExplode = nullptr;
  this->engineDamage.maxVolume = 0.0;
  this->engineStop = nullptr;
  this->explode = nullptr;
  this->backfire = nullptr;
  this->smokeburp = nullptr;
  this->attachmentCollision = nullptr;
  this->impactSpark = nullptr;
  this->debris = nullptr;
  this->steering = nullptr;
  this->zooming = nullptr;
  this->rcbombTriggered = nullptr;
  this->lockOnWarningSound = nullptr;
  this->nonCombatMusic = nullptr;
  this->combatMusic = nullptr;
  this->combatMusic2 = nullptr;
  this->enterVehicle = nullptr;
  this->exitVehicle = nullptr;
  this->quickReverse = nullptr;
  this->hornOnce = nullptr;
  this->hornLoop = nullptr;
  this->engineSmoke = nullptr;
  this->engineFire = nullptr;
  this->quickUseError = nullptr;
  this->foliage = nullptr;
  this->bodyToBody = nullptr;
  this->tireToTire = nullptr;
  this->projectileToBody = nullptr;
  return this;
}


// ========================================================================
// ??0idDeclVehicleProps@@QAA@XZ
// EA  : 0x826233E8
// RVA : 0x006233E8
// PDB : w:\tech5\engine\decls\declvehicleprops.h
// ========================================================================

idDeclVehicleProps *__fastcall idDeclVehicleProps::idDeclVehicleProps(idDeclVehicleProps *this)
{
  idDeclTypeInfo::idDeclTypeInfo(this: &this->idDeclTypeInfo);
  this->__vftable = (idDeclVehicleProps_vtbl *)&idDeclVehicleProps::`vftable';
  this->camera.yaw = 0.0;
  this->camera.pitch = 0.0;
  this->camera.recovery = nullptr;
  this->camera.height = 0.0;
  this->camera.rotationOffset = nullptr;
  this->camera.lateral = 0.0;
  this->camera.minRange = 0.0;
  this->camera.maxRange = 0.0;
  this->camera2.recovery = nullptr;
  this->camera2.yaw = 0.0;
  this->camera2.rotationOffset = nullptr;
  this->camera2.pitch = 0.0;
  this->camera2.height = 0.0;
  this->camera2.lateral = 0.0;
  this->camera2.minRange = 0.0;
  this->camera2.maxRange = 0.0;
  this->steeringWheel.jointName.allocedAndFlag = 20;
  this->steeringWheel.jointName.data = this->steeringWheel.jointName.baseBuffer;
  this->steeringWheel.jointName.len = 0;
  this->steeringWheel.jointName.baseBuffer[0] = 0;
  this->steeringWheel.speed = 90.0;
  this->steeringWheel.rotationAxis = 1;
  this->steeringWheel.rotationDirection = ROTATE_LEFT;
  this->steeringWheel.maxAngle = nullptr;
  this->tachometer.jointName.allocedAndFlag = 20;
  this->tachometer.jointName.len = 0;
  this->tachometer.jointName.data = this->tachometer.jointName.baseBuffer;
  this->tachometer.jointName.baseBuffer[0] = 0;
  this->tachometer.axis = DIAL_AXIS_Y;
  this->tachometer.direction = DIAL_ROTATE_LEFT;
  this->tachometer.startValue = 0;
  this->tachometer.endValue = 100;
  this->tachometer.startAmount = 0;
  this->tachometer.endAmount = 90;
  this->tachometer.table = nullptr;
  this->speedometer.jointName.allocedAndFlag = 20;
  this->speedometer.jointName.len = 0;
  this->speedometer.jointName.data = this->speedometer.jointName.baseBuffer;
  this->speedometer.jointName.baseBuffer[0] = 0;
  this->speedometer.axis = DIAL_AXIS_Y;
  this->speedometer.direction = DIAL_ROTATE_LEFT;
  this->speedometer.startValue = 0;
  this->speedometer.endValue = 100;
  this->speedometer.startAmount = 0;
  this->speedometer.endAmount = 90;
  this->speedometer.table = nullptr;
  this->sheildModel.allocedAndFlag = 20;
  this->sheildModel.len = 0;
  this->sheildModel.data = this->sheildModel.baseBuffer;
  this->sheildModel.baseBuffer[0] = 0;
  this->hasEngineIdle = true;
  this->removeOnExit = false;
  this->jumpImpulse = 3250000.0;
  this->influence.innerRadius = 32.0;
  this->influence.outerRadius = 64.0;
  this->influence.angle = 0.0;
  this->influence.trailDist = 32.0;
  this->influence.trailFadeInTime = 0.25;
  this->influence.trailFadeOutTime = 2.0;
  this->remoteControl = false;
  this->raceRemoteControl = false;
  this->wheels.granularity = 0;
  this->wheels.memTag = 5;
  this->wheels.listStatic = 0;
  this->wheels.list = nullptr;
  this->wheels.size = 0;
  this->wheels.num = 0;
  this->body.model = nullptr;
  this->body.density = 0.00094;
  this->body.linearFriction = 0.059999999;
  this->body.angularFriction = 0.059999999;
  this->body.contactFriction = 0.5;
  this->body.bouncyness = 0.30000001;
  idVehicleSoundDef::idVehicleSoundDef(this: &this->sounds);
  idVehicleEffectsDef::idVehicleEffectsDef(this: &this->effects);
  this->camera.yaw = 0.0;
  this->camera.lateral = 0.0;
  this->camera2.yaw = 0.0;
  this->breakableDebris = nullptr;
  this->steerControlInfluence = 0.55000001;
  this->camera2.height = 8.0;
  this->camera2.minRange = 8.0;
  this->camera2.maxRange = 8.0;
  this->camera.pitch = 5.0;
  this->camera.height = 40.0;
  this->camera.minRange = 300.0;
  this->camera2.pitch = 10.0;
  this->camera.maxRange = 500.0;
  this->camera2.lateral = 7.0;
  this->cgLocation.z = 0.0;
  this->cgLocation.y = 0.0;
  this->cgLocation.x = 0.0;
  this->maxCgLocation.z = 0.0;
  this->maxCgLocation.y = 0.0;
  this->maxCgLocation.x = 0.0;
  this->motorTorque = nullptr;
  this->hasBoost = true;
  this->boostBlurMaterial = nullptr;
  this->maxSpeed = 100.0;
  this->baseBoostUpgrade = 1;
  this->boostMaxSpeedScalar = 1.0;
  this->fpsStickYawTable = nullptr;
  this->additionalRaceSpeed = 10.0;
  this->fpsStickPitchTable = nullptr;
  this->maxReverseSpeed = 40.0;
  this->handbrakeMinThreshold = 1.0;
  this->handbrakeFrictionScale = 0.30000001;
  this->handBrakeForce = 3000.0;
  this->brakeForce = 400.0;
  this->frictionForce = 30.0;
  this->pitchStabilization = 0.69999999;
  this->rollStabilization = 0.69999999;
  this->skidRoll = 0.00060000003;
  this->skidRollBoostMult = 1.8;
  return this;
}


// ========================================================================
// __unwind$224366
// EA  : 0x82623744
// RVA : 0x00623744
// PDB : w:\tech5\engine\decls\declvehicleprops.h
// ========================================================================

void _unwind_224366()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$224367
// EA  : 0x8262376C
// RVA : 0x0062376C
// PDB : w:\tech5\engine\decls\declvehicleprops.h
// ========================================================================

void _unwind_224367()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 136));
}


// ========================================================================
// __unwind$224368
// EA  : 0x82623798
// RVA : 0x00623798
// PDB : w:\tech5\engine\decls\declvehicleprops.h
// ========================================================================

void _unwind_224368()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 188));
}


// ========================================================================
// __unwind$224369
// EA  : 0x826237C4
// RVA : 0x006237C4
// PDB : w:\tech5\engine\decls\declvehicleprops.h
// ========================================================================

void _unwind_224369()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 248));
}


// ========================================================================
// __unwind$224370
// EA  : 0x826237F0
// RVA : 0x006237F0
// PDB : w:\tech5\engine\decls\declvehicleprops.h
// ========================================================================

void _unwind_224370()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 400));
}


// ========================================================================
// __unwind$224371
// EA  : 0x8262381C
// RVA : 0x0062381C
// PDB : w:\tech5\engine\decls\declvehicleprops.h
// ========================================================================

void _unwind_224371()
{
  int v0; // r12

  idList<idWheelDef,5>::~idList<idWheelDef,5>(this: (idList<idWheelDef,5> *)(*(_DWORD *)(v0 - 160 + 180) + 468));
}


// ========================================================================
// ?GetDeclInfo@idDeclVehicleProps@@UBAPAVidDeclInfo@@XZ
// EA  : 0x82623848
// RVA : 0x00623848
// PDB : w:\tech5\engine\decls\declvehicleprops.h
// ========================================================================

idDeclInfoTemplate<idDeclVehicleProps> *__fastcall idDeclVehicleProps::GetDeclInfo(idDeclVehicleProps *this)
{
  return &idDeclVehicleProps::resourceList;
}


// ========================================================================
// ??1idDeclVehicleProps@@UAA@XZ
// EA  : 0x82623860
// RVA : 0x00623860
// PDB : w:\tech5\engine\decls\declvehicleprops.h
// ========================================================================

void __fastcall idDeclVehicleProps::~idDeclVehicleProps(idDeclVehicleProps *this)
{
  char *list; // r3

  this->__vftable = (idDeclVehicleProps_vtbl *)&idDeclVehicleProps::`vftable';
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->sounds);
  if ( this->wheels.listStatic == 0 || this->wheels.listStatic == 2 )
  {
    list = (char *)this->wheels.list;
    if ( list != nullptr )
      idListArrayDelete<idWheelDef>(ptr: list, num: this->wheels.size);
    this->wheels.list = nullptr;
    this->wheels.size = 0;
  }
  this->wheels.num = 0;
  idStr::FreeData(this: &this->sheildModel);
  idStr::FreeData(this: &this->speedometer.jointName);
  idStr::FreeData(this: &this->tachometer.jointName);
  idStr::FreeData(this: &this->steeringWheel.jointName);
  idDeclTypeInfo::~idDeclTypeInfo(this: &this->idDeclTypeInfo);
}


// ========================================================================
// __unwind$224648
// EA  : 0x826238F4
// RVA : 0x006238F4
// PDB : w:\tech5\engine\decls\declvehicleprops.h
// ========================================================================

void _unwind_224648()
{
  int v0; // r12

  idDeclTypeInfo::~idDeclTypeInfo(this: *(idDeclTypeInfo **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$224649
// EA  : 0x8262391C
// RVA : 0x0062391C
// PDB : w:\tech5\engine\decls\declvehicleprops.h
// ========================================================================

void _unwind_224649()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 136));
}


// ========================================================================
// __unwind$224650
// EA  : 0x82623948
// RVA : 0x00623948
// PDB : w:\tech5\engine\decls\declvehicleprops.h
// ========================================================================

void _unwind_224650()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 188));
}


// ========================================================================
// __unwind$224651
// EA  : 0x82623974
// RVA : 0x00623974
// PDB : w:\tech5\engine\decls\declvehicleprops.h
// ========================================================================

void _unwind_224651()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 248));
}


// ========================================================================
// __unwind$224652_0
// EA  : 0x826239A0
// RVA : 0x006239A0
// PDB : w:\tech5\engine\decls\declvehicleprops.h
// ========================================================================

void _unwind_224652_0()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 112 + 132) + 400));
}


// ========================================================================
// __unwind$224653
// EA  : 0x826239CC
// RVA : 0x006239CC
// PDB : w:\tech5\engine\decls\declvehicleprops.h
// ========================================================================

void _unwind_224653()
{
  int v0; // r12

  idList<idWheelDef,5>::~idList<idWheelDef,5>(this: (idList<idWheelDef,5> *)(*(_DWORD *)(v0 - 112 + 132) + 468));
}

