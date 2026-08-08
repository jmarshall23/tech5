
// ========================================================================
// ?GetIdObstaclesStr@idVehicleAI@@QAA?AVidStr@@XZ
// EA  : 0x82B04F00
// RVA : 0x00B04F00
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.h
// ========================================================================

idVehicleAI *__fastcall idVehicleAI::GetIdObstaclesStr(idVehicleAI *this, idStr *result)
{
  idStr::idStr((idStr *)this, text: (idStr *)((char *)result + 1612));
  return this;
}


// ========================================================================
// ?GetVehicleCar@idVehicleAI@@QBAPAVidVehicle_Car@@XZ
// EA  : 0x82B05D68
// RVA : 0x00B05D68
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.h
// ========================================================================

idVehicle_Car *__fastcall idVehicleAI::GetVehicleCar(idVehicleAI *this)
{
  int value; // r10
  idVehicle_Car *v2; // r3

  value = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idVehicle_Car::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetVehicleEntity@idVehicleAI@@QBAPAVidEntity@@XZ
// EA  : 0x82B0BB00
// RVA : 0x00B0BB00
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.h
// ========================================================================

idEntity *__fastcall idVehicleAI::GetVehicleEntity(idVehicleAI *this)
{
  int value; // r10
  idEntity *v2; // r3

  value = this->vehicleEntity.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idEntity::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ??0dormancy_t@vehicleAiSetup_t@@QAA@XZ
// EA  : 0x82B0F1D0
// RVA : 0x00B0F1D0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.h
// ========================================================================

vehicleAiSetup_t::dormancy_t *__fastcall vehicleAiSetup_t::dormancy_t::dormancy_t(vehicleAiSetup_t::dormancy_t *this)
{
  this->distance = 0.0;
  this->group.list = nullptr;
  this->group.granularity = 0;
  this->group.memTag = 5;
  this->group.listStatic = 0;
  this->group.size = 0;
  this->group.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->group);
  this->isDormant = false;
  this->isAttacking = false;
  this->isNearPlayer = true;
  return this;
}


// ========================================================================
// ??0patrol_t@vehicleAiSetup_t@@QAA@XZ
// EA  : 0x82B0F248
// RVA : 0x00B0F248
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.h
// ========================================================================

vehicleAiSetup_t::patrol_t *__fastcall vehicleAiSetup_t::patrol_t::patrol_t(vehicleAiSetup_t::patrol_t *this)
{
  this->waypointDef = nullptr;
  this->waypoint.spawnId.value = 0x1FFF;
  this->pathType = PATROL_REBOUND;
  this->speed = 45.0;
  this->fleeNearEnemy = true;
  this->maxRightDistance = 1.0;
  this->iterations = -1;
  this->nextWaypointDist = 1000.0;
  this->curPatrolPoint = 0;
  this->curPatrolDir = 0;
  this->delayTime = 0;
  this->iterationCount = 0;
  this->pathComplete = false;
  this->waypoints.list = nullptr;
  this->waypoints.granularity = 0;
  this->waypoints.memTag = 5;
  this->waypoints.listStatic = 0;
  this->waypoints.size = 0;
  this->waypoints.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->waypoints);
  this->goalPosition.navSpline = nullptr;
  this->goalPosition.distance = 0.0;
  this->goalPosition.rightDistance = 0.0;
  return this;
}


// ========================================================================
// ??0engage_t@vehicleAiSetup_t@@QAA@XZ
// EA  : 0x82B0F318
// RVA : 0x00B0F318
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.h
// ========================================================================

vehicleAiSetup_t::engage_t *__fastcall vehicleAiSetup_t::engage_t::engage_t(vehicleAiSetup_t::engage_t *this)
{
  this->guard.list = nullptr;
  this->guard.granularity = 0;
  this->guard.memTag = 5;
  this->guard.listStatic = 0;
  this->guard.size = 0;
  this->guard.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->extension.list = nullptr;
  this->extension.granularity = 0;
  this->extension.memTag = 5;
  this->extension.listStatic = 0;
  this->extension.size = 0;
  this->extension.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->extension);
  this->delay = 0.0;
  this->trigger.spawnId.value = 0x1FFF;
  this->alertSound = nullptr;
  this->alertDistance = -1.0;
  this->alertSoundTime = 0;
  return this;
}


// ========================================================================
// __unwind$510867
// EA  : 0x82B0F3B0
// RVA : 0x00B0F3B0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.h
// ========================================================================

void _unwind_510867()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 128 + 148));
}


// ========================================================================
// ??0aiAudio_t@vehicleAiSetup_t@@QAA@XZ
// EA  : 0x82B0F3D8
// RVA : 0x00B0F3D8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.h
// ========================================================================

vehicleAiSetup_t::aiAudio_t *__fastcall vehicleAiSetup_t::aiAudio_t::aiAudio_t(vehicleAiSetup_t::aiAudio_t *this)
{
  this->sounds.list = nullptr;
  this->sounds.granularity = 0;
  this->sounds.memTag = 5;
  this->sounds.listStatic = 0;
  this->sounds.size = 0;
  this->sounds.num = 0;
  idList<idThread *,58>::Clear((idList<idVehicleState *,5> *)this);
  this->nextPlayTime = 0;
  this->minDelay = 5.0;
  this->maxDelay = 10.0;
  return this;
}


// ========================================================================
// ??0conditionalAudio_t@vehicleAiSetup_t@@QAA@XZ
// EA  : 0x82B135A8
// RVA : 0x00B135A8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.h
// ========================================================================

vehicleAiSetup_t::conditionalAudio_t *__fastcall vehicleAiSetup_t::conditionalAudio_t::conditionalAudio_t(
        vehicleAiSetup_t::conditionalAudio_t *this)
{
  vehicleAiSetup_t::aiAudio_t::aiAudio_t(this: &this->afterKills);
  this->lastKillCount = 0;
  vehicleAiSetup_t::aiAudio_t::aiAudio_t(this: &this->duringFireFight);
  vehicleAiSetup_t::aiAudio_t::aiAudio_t(this: &this->takingDamage);
  vehicleAiSetup_t::aiAudio_t::aiAudio_t(this: &this->lowHealth);
  return this;
}


// ========================================================================
// __unwind$517430
// EA  : 0x82B13608
// RVA : 0x00B13608
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.h
// ========================================================================

void _unwind_517430()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: *(idStaticList<idVehicleState *,4> **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$517431
// EA  : 0x82B13630
// RVA : 0x00B13630
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.h
// ========================================================================

void _unwind_517431()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 32));
}


// ========================================================================
// __unwind$517432
// EA  : 0x82B1365C
// RVA : 0x00B1365C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.h
// ========================================================================

void _unwind_517432()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 112 + 132) + 60));
}


// ========================================================================
// ?IsDead@idVehicleAI@@UBA_NXZ
// EA  : 0x82B18640
// RVA : 0x00B18640
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.h
// ========================================================================

BOOL __fastcall idVehicleAI::IsDead(idVehicleAI *this)
{
  return (this->thinkFlags & 1) == 0;
}


// ========================================================================
// ??0vehicleAiSetup_t@@QAA@XZ
// EA  : 0x82B1B510
// RVA : 0x00B1B510
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.h
// ========================================================================

vehicleAiSetup_t *__fastcall vehicleAiSetup_t::vehicleAiSetup_t(vehicleAiSetup_t *this)
{
  this->decisionState = VEHICLE_IDLE;
  this->takesDamage = true;
  this->secondaryAmbushPos.spawnId.value = 0x1FFF;
  this->debugState.allocedAndFlag = 20;
  this->debugState.data = this->debugState.baseBuffer;
  this->debugState.len = 0;
  this->debugState.baseBuffer[0] = 0;
  this->control.avoidanceType = OAT_INIT;
  this->control.powerTurnTime = -1;
  this->control.speedLimit = -1.0;
  this->control.stopDistance = -1.0;
  this->control.moveDistance = -1.0;
  this->control.decelDistance = -1.0;
  this->control.maxCurveSpeed = -1.0;
  this->control.maxCurveAngle = -1.0;
  this->control.maxStepAngle = -1.0;
  this->control.powerTurnSpeed = -1.0;
  this->control.stopPowerTurnSpeed = -1.0;
  this->control.traversalStepSize = -1.0;
  this->control.backupSpeed = -1.0;
  this->control.maxCurveCosine = -1.0;
  this->control.maxStepCosine = -1.0;
  this->controlVehicle.vehicleDef = nullptr;
  this->controlVehicle.vehicleEnt.spawnId.value = 0x1FFF;
  this->controlVehicle.useAiOriginAxis = false;
  this->health = 0.0;
  this->infiniteAmmo = false;
  this->infiniteQuickUse = false;
  this->initialPath.spawnId.value = 0x1FFF;
  this->narrowPathDistance = 200.0;
  this->passThroughGoalDist = 2000.0;
  *(_WORD *)&this->guardInitialPath = 1;
  this->allowSlideTurn = true;
  this->boostAltersVelocity = true;
  *(_WORD *)&this->ghostCollision = 1;
  this->turnaroundTowardsMiddle = true;
  this->vehicleRating = -1;
  this->predatorHealthRegen = 0;
  vehicleAiSetup_t::dormancy_t::dormancy_t(this: &this->dormancy);
  vehicleAiSetup_t::patrol_t::patrol_t(this: &this->patrol);
  vehicleAiSetup_t::encounter_t::encounter_t(this: (idASEModel *)&this->encounter);
  vehicleAiSetup_t::engage_t::engage_t(this: &this->engage);
  this->groupNumber = -1;
  this->attack.freeForm = true;
  this->attack.types.list = nullptr;
  this->attack.types.granularity = 0;
  this->attack.types.memTag = 5;
  this->attack.types.listStatic = 0;
  this->attack.types.size = 0;
  this->attack.types.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->attack.types);
  this->specificEnemyList.list = nullptr;
  this->specificEnemyList.granularity = 0;
  this->specificEnemyList.memTag = 5;
  this->specificEnemyList.listStatic = 0;
  this->specificEnemyList.size = 0;
  this->specificEnemyList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->specificEnemyList);
  this->forcePlayerEnemy = false;
  this->death.respawnType = NO_RESPAWN;
  this->death.killWhenStuck = true;
  this->death.respawnInBackground = true;
  this->death.clearEnemyTracker = true;
  this->death.numRespawns = -1;
  this->death.minBackgroundDistance = 8000.0;
  this->death.numWaves = -1;
  this->death.minBackgroundViewDistance = 15000.0;
  this->death.minRespawnTime = 5.0;
  this->death.maxRespawnTime = 15.0;
  this->death.waveMinDelayTime = 240.0;
  this->death.waveMaxDelayTime = 480.0;
  this->death.trigger.spawnId.value = 0x1FFF;
  this->death.triggerMilliSec = 0;
  this->death.triggerAfterWave.spawnId.value = 0x1FFF;
  this->death.triggerAfterWaveMilliSec = 0;
  this->death.respawns = 0;
  idFaction::idFaction(this: &this->faction);
  this->commands.granularity = 0;
  this->commands.memTag = 5;
  this->commands.listStatic = 0;
  this->commands.list = nullptr;
  this->commands.size = 0;
  this->commands.num = 0;
  vehicleAiSetup_t::conditionalAudio_t::conditionalAudio_t(this: &this->conditionalAudio);
  return this;
}


// ========================================================================
// __unwind$528333
// EA  : 0x82B1B760
// RVA : 0x00B1B760
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.h
// ========================================================================

void _unwind_528333()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 160 + 180) + 12));
}


// ========================================================================
// __unwind$528334
// EA  : 0x82B1B78C
// RVA : 0x00B1B78C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.h
// ========================================================================

void _unwind_528334()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(*(_DWORD *)(v0 - 160 + 180) + 152));
}


// ========================================================================
// __unwind$528335
// EA  : 0x82B1B7B8
// RVA : 0x00B1B7B8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.h
// ========================================================================

void _unwind_528335()
{
  int v0; // r12

  idInfluenceTrail::~idInfluenceTrail(this: (idInfluenceTrail *)(*(_DWORD *)(v0 - 160 + 180) + 176));
}


// ========================================================================
// __unwind$528336
// EA  : 0x82B1B7E4
// RVA : 0x00B1B7E4
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.h
// ========================================================================

void _unwind_528336()
{
  int v0; // r12

  idPLog::~idPLog(this: (idFSMManager::idFSMStack *)(*(_DWORD *)(v0 - 160 + 180) + 256));
}


// ========================================================================
// __unwind$528337
// EA  : 0x82B1B810
// RVA : 0x00B1B810
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.h
// ========================================================================

void _unwind_528337()
{
  int v0; // r12

  idPLog::~idPLog(this: (idFSMManager::idFSMStack *)(*(_DWORD *)(v0 - 160 + 180) + 288));
}


// ========================================================================
// __unwind$528338
// EA  : 0x82B1B83C
// RVA : 0x00B1B83C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.h
// ========================================================================

void _unwind_528338()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(*(_DWORD *)(v0 - 160 + 180) + 344));
}


// ========================================================================
// __unwind$528339
// EA  : 0x82B1B868
// RVA : 0x00B1B868
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.h
// ========================================================================

void _unwind_528339()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 160 + 180) + 364));
}


// ========================================================================
// __unwind$528340
// EA  : 0x82B1B894
// RVA : 0x00B1B894
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.h
// ========================================================================

void _unwind_528340()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(*(_DWORD *)(v0 - 160 + 180) + 472));
}


// ========================================================================
// __unwind$528341
// EA  : 0x82B1B8C0
// RVA : 0x00B1B8C0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.h
// ========================================================================

void _unwind_528341()
{
  int v0; // r12

  idList<vehicleAiSetup_t::commands_t,5>::~idList<vehicleAiSetup_t::commands_t,5>(this: (idList<vehicleAiSetup_t::commands_t,5> *)(*(_DWORD *)(v0 - 160 + 180) + 492));
}


// ========================================================================
// ?GetPrespawnVehicleCar@idVehicleAI@@QBAPAVidVehicle_Car@@XZ
// EA  : 0x82CD1810
// RVA : 0x00CD1810
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.h
// ========================================================================

idVehicle_Car *__fastcall idVehicleAI::GetPrespawnVehicleCar(idVehicleAI *this)
{
  int value; // r10
  idVehicle_Car *v2; // r3

  value = this->prespawnedVehicle.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v2 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    return idVehicle_Car::CastTo(c: v2);
  }
  else
  {
    return nullptr;
  }
}

