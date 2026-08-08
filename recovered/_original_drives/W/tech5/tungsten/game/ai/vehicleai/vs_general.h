
// ========================================================================
// ??0idVS_as_StrafeShoot@@QAA@ABVidTypeInfo@@@Z
// EA  : 0x824E38C8
// RVA : 0x004E38C8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.h
// ========================================================================

idVS_as_StrafeShoot *__fastcall idVS_as_StrafeShoot::idVS_as_StrafeShoot(
        idVS_as_StrafeShoot *this,
        const idTypeInfo *stateType)
{
  double x; // fp10

  idVehicleState::idVehicleState(this, stateType);
  this->__vftable = (idVS_as_StrafeShoot_vtbl *)&idVS_as_StrafeShoot::`vftable';
  this->moveAwayPos.navSpline = nullptr;
  this->moveAwayPos.distance = 0.0;
  this->moveAwayPos.rightDistance = 0.0;
  this->moveAwayFromEnemy = false;
  this->driveTowardsEnemy = false;
  this->circleShoot = false;
  this->point[3] = vec3_origin;
  x = this->point[3].x;
  this->point[2] = this->point[3];
  this->point[1].x = x;
  this->point[1].y = this->point[2].y;
  this->point[1].z = this->point[2].z;
  this->point[0].x = x;
  this->point[0].y = this->point[1].y;
  this->point[0].z = this->point[1].z;
  this->curpoint = 0;
  this->save_decelDistance = 0.0;
  this->save_stopDistance = 0.0;
  return this;
}


// ========================================================================
// ??0idVS_as_Bypass@@QAA@ABVidTypeInfo@@@Z
// EA  : 0x824E39A8
// RVA : 0x004E39A8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.h
// ========================================================================

idVS_as_Bypass *__fastcall idVS_as_Bypass::idVS_as_Bypass(idVS_as_Bypass *this, const idTypeInfo *stateType)
{
  idVehicleState::idVehicleState(this, stateType);
  this->__vftable = (idVS_as_Bypass_vtbl *)&idVS_as_Bypass::`vftable';
  this->state = ST_INIT;
  this->oldEnemyPos = vec3_origin;
  return this;
}


// ========================================================================
// ??0idVS_ds_Group_FollowLeader@@QAA@ABVidTypeInfo@@@Z
// EA  : 0x824FC770
// RVA : 0x004FC770
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.h
// ========================================================================

idVS_ds_Group_FollowLeader *__fastcall idVS_ds_Group_FollowLeader::idVS_ds_Group_FollowLeader(
        idVS_ds_Group_FollowLeader *this,
        const idTypeInfo *stateType)
{
  idVehicleState::idVehicleState(this, stateType);
  this->__vftable = (idVS_ds_Group_FollowLeader_vtbl *)&idVS_ds_Group_FollowLeader::`vftable';
  this->leader.spawnId.value = 0x1FFF;
  this->others.list = nullptr;
  this->others.granularity = 0;
  this->others.memTag = 5;
  this->others.listStatic = 0;
  this->others.size = 0;
  this->others.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->others);
  this->following.spawnId.value = 0x1FFF;
  this->startPos.navSpline = nullptr;
  this->startPos.distance = 0.0;
  this->startPos.rightDistance = 0.0;
  this->moveDir = 1.0;
  return this;
}


// ========================================================================
// __unwind$586304
// EA  : 0x824FC810
// RVA : 0x004FC810
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.h
// ========================================================================

void _unwind_586304()
{
  int v0; // r12

  idVehicleState::~idVehicleState(this: *(idVehicleState **)(v0 - 128 + 148));
}


// ========================================================================
// ??0idVS_ds_Ambush@@QAA@ABVidTypeInfo@@@Z
// EA  : 0x8251D5B0
// RVA : 0x0051D5B0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.h
// ========================================================================

idVS_ds_Ambush *__fastcall idVS_ds_Ambush::idVS_ds_Ambush(idVS_ds_Ambush *this, const idTypeInfo *stateType)
{
  idVehicleState::idVehicleState(this, stateType);
  this->__vftable = (idVS_ds_Ambush_vtbl *)&idVS_ds_Ambush::`vftable';
  this->startingPathPos.navSpline = nullptr;
  this->startingPathPos.distance = 0.0;
  this->startingPathPos.rightDistance = 0.0;
  this->backupPos.navSpline = nullptr;
  this->backupPos.distance = 0.0;
  this->backupPos.rightDistance = 0.0;
  this->ambushStartPos.navSpline = nullptr;
  this->ambushStartPos.distance = 0.0;
  this->ambushStartPos.rightDistance = 0.0;
  this->delayTime = 0;
  this->finalBackupMove = false;
  return this;
}


// ========================================================================
// ??0idVS_as_RangeShoot@@QAA@ABVidTypeInfo@@@Z
// EA  : 0x8251D628
// RVA : 0x0051D628
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.h
// ========================================================================

idVS_as_RangeShoot *__fastcall idVS_as_RangeShoot::idVS_as_RangeShoot(
        idVS_as_RangeShoot *this,
        const idTypeInfo *stateType)
{
  idVehicleState::idVehicleState(this, stateType);
  this->__vftable = (idVS_as_RangeShoot_vtbl *)&idVS_as_RangeShoot::`vftable';
  this->goalPathPos.navSpline = nullptr;
  this->goalPathPos.distance = 0.0;
  this->goalPathPos.rightDistance = 0.0;
  this->adjustTime = 0;
  this->attackRange = 0.0;
  this->inRange = false;
  this->aligned = false;
  this->enemyWorldPos = vec3_origin;
  this->lastNewPosTime = 0;
  this->lastCycleDonePosition = vec3_origin;
  this->cycleDone = false;
  this->alignedTime = 0;
  this->newGoalFromBackupsCount = 2;
  return this;
}


// ========================================================================
// ??0idVS_ms_Backup@@QAA@ABVidTypeInfo@@@Z
// EA  : 0x82541430
// RVA : 0x00541430
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.h
// ========================================================================

idVS_ms_Backup *__fastcall idVS_ms_Backup::idVS_ms_Backup(idVS_ms_Backup *this, const idTypeInfo *stateType)
{
  idVehicleState::idVehicleState(this, stateType);
  this->startTime = 0;
  this->__vftable = (idVS_ms_Backup_vtbl *)&idVS_ms_Backup::`vftable';
  this->goalFacing = vec3_origin;
  this->backupTime = 0;
  this->speed = 0.0;
  this->steering = 0.0;
  return this;
}


// ========================================================================
// ??0idVS_ds_Car_Chase@@QAA@ABVidTypeInfo@@@Z
// EA  : 0x825414A8
// RVA : 0x005414A8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.h
// ========================================================================

idVS_ds_Car_Chase *__fastcall idVS_ds_Car_Chase::idVS_ds_Car_Chase(
        idVS_ds_Car_Chase *this,
        const idTypeInfo *stateType)
{
  idVehicleState::idVehicleState(this, stateType);
  this->__vftable = (idVS_ds_Car_Chase_vtbl *)&idVS_ds_Car_Chase::`vftable';
  this->currentDestination.navSpline = nullptr;
  this->currentDestination.distance = 0.0;
  this->currentDestination.rightDistance = 0.0;
  this->currentState = 0;
  this->enemySplineStatus = ENEMY_SPLINE_STATUS_UNKNOWN;
  this->overrideSpeed = -1.0;
  this->currentWayPoint = nullptr;
  return this;
}

