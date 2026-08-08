
// ========================================================================
// ?GetDifficultyData@idVehicleAI@@QAAXAAUdifficultyLevel_t@vehicleAiSetup_t@@@Z
// EA  : 0x82B08838
// RVA : 0x00B08838
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::GetDifficultyData(idVehicleAI *this, vehicleAiSetup_t::difficultyLevel_t *difficultyLevel)
{
  bool *p_forcePlayerEnemy; // r11
  _DWORD *p_damageTakenScale; // r10
  int i; // ctr

  p_forcePlayerEnemy = &this->setup.forcePlayerEnemy;
  p_damageTakenScale = (_DWORD *)&difficultyLevel[-1].damageTakenScale;
  for ( i = 6; i != 0; --i )
  {
    p_forcePlayerEnemy += 4;
    *++p_damageTakenScale = *(_DWORD *)p_forcePlayerEnemy;
  }
}


// ========================================================================
// ?GetDifficultyRating@idVehicleAI@@QAAHXZ
// EA  : 0x82B08858
// RVA : 0x00B08858
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

int __fastcall idVehicleAI::GetDifficultyRating(idVehicleAI *this)
{
  vehicleAiSetup_t::difficultyLevel_t::difficulty_t level; // r11

  level = this->setup.difficultyLevel.level;
  if ( level != DIFFICULTY_LOW )
    return ((_cntlzw(level - 1) & 0x20) == 0) + 2;
  else
    return 1;
}


// ========================================================================
// ?GetDifficulty_AttackScale@idVehicleAI@@QAAMXZ
// EA  : 0x82B08888
// RVA : 0x00B08888
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

float __fastcall idVehicleAI::GetDifficulty_AttackScale(idVehicleAI *this)
{
  idGameLocal_vtbl *v2; // r6
  int v3; // r3
  char v4; // r11
  double attackScale; // fp1
  float v7[4]; // [sp+50h] [-20h] BYREF

  v2 = gameLocal->__vftable;
  v7[0] = 0.85000002;
  v7[1] = 0.89999998;
  v7[2] = 0.94999999;
  v7[3] = 1.0;
  v3 = v2->GetGameDifficulty(this: gameLocal);
  if ( v3 < 0 || (v4 = 1, v3 > 3) )
    v4 = 0;
  if ( v4 != 0 )
    attackScale = (float)(v7[v3] * this->setup.difficultyLevel.attackScale);
  else
    attackScale = this->setup.difficultyLevel.attackScale;
  return *((float *)&attackScale + 1);
}


// ========================================================================
// ?GetDifficulty_DamageScale@idVehicleAI@@QAAMXZ
// EA  : 0x82B08948
// RVA : 0x00B08948
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

float __fastcall idVehicleAI::GetDifficulty_DamageScale(idVehicleAI *this)
{
  idGameLocal_vtbl *v2; // r9
  int v3; // r3
  char v4; // r11
  double damageScale; // fp1
  float v7[4]; // [sp+50h] [-20h] BYREF

  v7[0] = 1.0;
  v7[1] = 1.0;
  v2 = gameLocal->__vftable;
  v7[2] = 1.0;
  v7[3] = 1.0;
  v3 = v2->GetGameDifficulty(this: gameLocal);
  if ( v3 < 0 || (v4 = 1, v3 > 3) )
    v4 = 0;
  if ( v4 != 0 )
    damageScale = (float)(v7[v3] * this->setup.difficultyLevel.damageScale);
  else
    damageScale = this->setup.difficultyLevel.damageScale;
  return *((float *)&damageScale + 1);
}


// ========================================================================
// ?GetDifficulty_SpeedRate@idVehicleAI@@QAAMXZ
// EA  : 0x82B089F0
// RVA : 0x00B089F0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

float __fastcall idVehicleAI::GetDifficulty_SpeedRate(idVehicleAI *this)
{
  idGameLocal_vtbl *v2; // r6
  int v3; // r3
  char v4; // r11
  double speedRate; // fp1
  float v7[4]; // [sp+50h] [-20h] BYREF

  v2 = gameLocal->__vftable;
  v7[0] = 0.85000002;
  v7[1] = 0.89999998;
  v7[2] = 0.94999999;
  v7[3] = 1.0;
  v3 = v2->GetGameDifficulty(this: gameLocal);
  if ( v3 < 0 || (v4 = 1, v3 > 3) )
    v4 = 0;
  if ( v4 != 0 )
    speedRate = (float)(v7[v3] * this->setup.difficultyLevel.speedRate);
  else
    speedRate = this->setup.difficultyLevel.speedRate;
  return *((float *)&speedRate + 1);
}


// ========================================================================
// ?GetDifficulty_Accuracy@idVehicleAI@@QAAMXZ
// EA  : 0x82B08AB0
// RVA : 0x00B08AB0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

float __fastcall idVehicleAI::GetDifficulty_Accuracy(idVehicleAI *this)
{
  idGameLocal_vtbl *v2; // r6
  int v3; // r3
  char v4; // r11
  double accuracy; // fp1
  float v7[4]; // [sp+50h] [-20h] BYREF

  v2 = gameLocal->__vftable;
  v7[0] = 0.85000002;
  v7[1] = 0.89999998;
  v7[2] = 0.94999999;
  v7[3] = 1.0;
  v3 = v2->GetGameDifficulty(this: gameLocal);
  if ( v3 < 0 || (v4 = 1, v3 > 3) )
    v4 = 0;
  if ( v4 != 0 )
    accuracy = (float)(v7[v3] * this->setup.difficultyLevel.accuracy);
  else
    accuracy = this->setup.difficultyLevel.accuracy;
  return *((float *)&accuracy + 1);
}


// ========================================================================
// ?GetDifficulty_DamageTakenScale@idVehicleAI@@QAAMXZ
// EA  : 0x82B08B70
// RVA : 0x00B08B70
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

float __fastcall idVehicleAI::GetDifficulty_DamageTakenScale(idVehicleAI *this)
{
  idGameLocal_vtbl *v2; // r9
  int v3; // r3
  char v4; // r11
  double damageTakenScale; // fp1
  float v7[4]; // [sp+50h] [-20h] BYREF

  v7[0] = 1.0;
  v7[1] = 1.0;
  v2 = gameLocal->__vftable;
  v7[2] = 1.0;
  v7[3] = 1.0;
  v3 = v2->GetGameDifficulty(this: gameLocal);
  if ( v3 < 0 || (v4 = 1, v3 > 3) )
    v4 = 0;
  if ( v4 != 0 )
    damageTakenScale = (float)(v7[v3] * this->setup.difficultyLevel.damageTakenScale);
  else
    damageTakenScale = this->setup.difficultyLevel.damageTakenScale;
  return *((float *)&damageTakenScale + 1);
}


// ========================================================================
// ?SetBeingAttackedTime@idVehicleAI@@QAAXH@Z
// EA  : 0x82B08C18
// RVA : 0x00B08C18
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::SetBeingAttackedTime(idVehicleAI *this, int msecs)
{
  this->beingAttackedTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + msecs;
}


// ========================================================================
// ?SetRightDistance@idVehicleAI@@QAAXM_N@Z
// EA  : 0x82B08C70
// RVA : 0x00B08C70
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::SetRightDistance(idVehicleAI *this, double dist, bool splineReference, bool a4)
{
  this->goalRightDistance = dist;
  this->rdSplineReference = a4;
}


// ========================================================================
// ?SetCollideAttack@idVehicleAI@@QAAX_N@Z
// EA  : 0x82B08C80
// RVA : 0x00B08C80
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::SetCollideAttack(idVehicleAI *this, bool bl)
{
  this->collideAttack = bl;
  this->passThroughGoal = bl;
}


// ========================================================================
// ?GetEnemy@idVehicleAI@@QAAPAVidEntity@@XZ
// EA  : 0x82B08C90
// RVA : 0x00B08C90
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

idEntity *__fastcall idVehicleAI::GetEnemy(idVehicleAI *this)
{
  idNavPathPosTracker *enemyTracker; // r3

  enemyTracker = this->enemyTracker;
  if ( enemyTracker != nullptr )
    return idNavPathPosTracker::GetOwner(this: enemyTracker);
  else
    return nullptr;
}


// ========================================================================
// ?IsEnemy@idVehicleAI@@QAA_NPAVidEntity@@@Z
// EA  : 0x82B08CA8
// RVA : 0x00B08CA8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

int __fastcall idVehicleAI::IsEnemy(idVehicleAI *this, idVehicle *entity)
{
  idNavPathPosTracker *enemyTracker; // r3
  idPlayer *Owner; // r3
  int result; // r3
  idPlayer *v6; // r3
  idVehicle *v7; // r3
  bool IsAnOccupant; // zf

  enemyTracker = this->enemyTracker;
  if ( enemyTracker == nullptr )
    return 0;
  Owner = (idPlayer *)idNavPathPosTracker::GetOwner(this: enemyTracker);
  if ( Owner == nullptr )
    return 0;
  if ( Owner == (idPlayer *)entity )
    return 1;
  v6 = idPlayer::CastTo(c: Owner);
  if ( v6 != nullptr && v6->GetVehicle_2(this: v6) == entity )
    return 1;
  v7 = idVehicle::CastTo(c: entity);
  if ( v7 == nullptr )
    return 0;
  IsAnOccupant = idVehicle::IsAnOccupant(this: v7, entity);
  result = 1;
  if ( !IsAnOccupant )
    return 0;
  return result;
}


// ========================================================================
// ?GetEnemyVehicle@idVehicleAI@@QAAPAVidVehicle@@XZ
// EA  : 0x82B08D58
// RVA : 0x00B08D58
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

idVehicle *__fastcall idVehicleAI::GetEnemyVehicle(idVehicleAI *this)
{
  idNavPathPosTracker *enemyTracker; // r3
  idVehicle *Owner; // r3
  idEntity *v3; // r31
  idVehicle *result; // r3
  idVehicle *BindMaster; // r3

  enemyTracker = this->enemyTracker;
  if ( enemyTracker == nullptr )
    return nullptr;
  Owner = (idVehicle *)idNavPathPosTracker::GetOwner(this: enemyTracker);
  v3 = Owner;
  if ( Owner == nullptr )
    return nullptr;
  result = idVehicle::CastTo(c: Owner);
  if ( result != nullptr )
    return result;
  if ( (unsigned __int8)idPlayer::IsTypeOf(c: v3) != 0
    && (BindMaster = (idVehicle *)idEntity::GetBindMaster(this: v3)) != nullptr )
  {
    return idVehicle::CastTo(c: BindMaster);
  }
  else
  {
    return nullptr;
  }
}


// ========================================================================
// ?GetFaction@idVehicleAI@@UAAPAVidFaction@@XZ
// EA  : 0x82B08DE8
// RVA : 0x00B08DE8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

idFaction *__fastcall idVehicleAI::GetFaction(idVehicleAI *this)
{
  return &this->setup.faction;
}


// ========================================================================
// ?GetEnemyTracker@idVehicleAI@@QAAPAVidNavPathPosTracker@@XZ
// EA  : 0x82B08DF0
// RVA : 0x00B08DF0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

idNavPathPosTracker *__fastcall idVehicleAI::GetEnemyTracker(idVehicleAI *this)
{
  return this->enemyTracker;
}


// ========================================================================
// ?SetSpeedLimit@idVehicleAI@@QAAXM@Z
// EA  : 0x82B08DF8
// RVA : 0x00B08DF8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::SetSpeedLimit(idVehicleAI *this, double speed)
{
  this->control.speedLimit = speed;
}


// ========================================================================
// ?SetForcedRetreatState@idVehicleAI@@QAAX_N@Z
// EA  : 0x82B08E00
// RVA : 0x00B08E00
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::SetForcedRetreatState(idVehicleAI *this, bool setState)
{
  this->inForcedRetreatState = setState;
}


// ========================================================================
// ?GetSpeedLimit@idVehicleAI@@QAAMXZ
// EA  : 0x82B08E08
// RVA : 0x00B08E08
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

float __fastcall idVehicleAI::GetSpeedLimit(idVehicleAI *this)
{
  double speedLimit; // fp1

  if ( this->overrideControlTime <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED)
    || (speedLimit = this->overrideControl.speedLimit) == -1.0 )
  {
    speedLimit = this->control.speedLimit;
  }
  return *((float *)&speedLimit + 1);
}


// ========================================================================
// ?GetStopDistance@idVehicleAI@@QAAMXZ
// EA  : 0x82B08E70
// RVA : 0x00B08E70
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

float __fastcall idVehicleAI::GetStopDistance(idVehicleAI *this)
{
  double stopDistance; // fp1

  if ( this->overrideControlTime <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED)
    || (stopDistance = this->overrideControl.stopDistance) == -1.0 )
  {
    stopDistance = this->control.stopDistance;
  }
  return *((float *)&stopDistance + 1);
}


// ========================================================================
// ?GetMoveDistance@idVehicleAI@@QAAMXZ
// EA  : 0x82B08ED8
// RVA : 0x00B08ED8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

float __fastcall idVehicleAI::GetMoveDistance(idVehicleAI *this)
{
  double moveDistance; // fp1

  if ( this->overrideControlTime <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED)
    || (moveDistance = this->overrideControl.moveDistance) == -1.0 )
  {
    moveDistance = this->control.moveDistance;
  }
  return *((float *)&moveDistance + 1);
}


// ========================================================================
// ?GetDecelDistance@idVehicleAI@@QAAMXZ
// EA  : 0x82B08F40
// RVA : 0x00B08F40
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

float __fastcall idVehicleAI::GetDecelDistance(idVehicleAI *this)
{
  double decelDistance; // fp1

  if ( this->overrideControlTime <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED)
    || (decelDistance = this->overrideControl.decelDistance) == -1.0 )
  {
    decelDistance = this->control.decelDistance;
  }
  return *((float *)&decelDistance + 1);
}


// ========================================================================
// ?GetMaxCurveSpeed@idVehicleAI@@QAAMXZ
// EA  : 0x82B08FA8
// RVA : 0x00B08FA8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

float __fastcall idVehicleAI::GetMaxCurveSpeed(idVehicleAI *this)
{
  double maxCurveSpeed; // fp1

  if ( this->overrideControlTime <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED)
    || (maxCurveSpeed = this->overrideControl.maxCurveSpeed) == -1.0 )
  {
    maxCurveSpeed = this->control.maxCurveSpeed;
  }
  return *((float *)&maxCurveSpeed + 1);
}


// ========================================================================
// ?GetMaxCurveCosine@idVehicleAI@@QAAMXZ
// EA  : 0x82B09010
// RVA : 0x00B09010
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

float __fastcall idVehicleAI::GetMaxCurveCosine(idVehicleAI *this)
{
  double maxCurveCosine; // fp1

  if ( this->overrideControlTime <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED)
    || (maxCurveCosine = this->overrideControl.maxCurveCosine) == -1.0 )
  {
    maxCurveCosine = this->control.maxCurveCosine;
  }
  return *((float *)&maxCurveCosine + 1);
}


// ========================================================================
// ?GetMaxStepCosine@idVehicleAI@@QAAMXZ
// EA  : 0x82B09078
// RVA : 0x00B09078
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

float __fastcall idVehicleAI::GetMaxStepCosine(idVehicleAI *this)
{
  double maxStepCosine; // fp1

  if ( this->overrideControlTime <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED)
    || (maxStepCosine = this->overrideControl.maxStepCosine) == -1.0 )
  {
    maxStepCosine = this->control.maxStepCosine;
  }
  return *((float *)&maxStepCosine + 1);
}


// ========================================================================
// ?GetAvoidanceType@idVehicleAI@@QAA?AW4vaiObstacleAvoidance_t@@XZ
// EA  : 0x82B090E0
// RVA : 0x00B090E0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

vaiObstacleAvoidance_t __fastcall idVehicleAI::GetAvoidanceType(idVehicleAI *this)
{
  vaiObstacleAvoidance_t result; // r3

  if ( this->overrideControlTime <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
    return this->control.avoidanceType;
  result = this->overrideControl.avoidanceType;
  if ( result == OAT_INIT )
    return this->control.avoidanceType;
  return result;
}


// ========================================================================
// ?GetPowerTurnSpeed@idVehicleAI@@QAAMXZ
// EA  : 0x82B09140
// RVA : 0x00B09140
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

float __fastcall idVehicleAI::GetPowerTurnSpeed(idVehicleAI *this)
{
  double powerTurnSpeed; // fp1

  if ( this->overrideControlTime <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED)
    || (powerTurnSpeed = this->overrideControl.powerTurnSpeed) == -1.0 )
  {
    powerTurnSpeed = this->control.powerTurnSpeed;
  }
  return *((float *)&powerTurnSpeed + 1);
}


// ========================================================================
// ?GetPowerTurnTime@idVehicleAI@@QAAMXZ
// EA  : 0x82B091A8
// RVA : 0x00B091A8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall idVehicleAI::GetPowerTurnTime(idVehicleAI *this)
{
  __int64 v2; // r11 OVERLAPPED
  int v3; // r9 OVERLAPPED
  __int64 v4; // fp0
  int powerTurnTime; // r10
  double v6; // fp1

  if ( this->overrideControlTime <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED)
    || (LODWORD(v2) = this->overrideControl.powerTurnTime, (_DWORD)v2 == -1) )
  {
    powerTurnTime = this->control.powerTurnTime;
    v4 = *(_QWORD *)(&v3 - 1);
  }
  else
  {
    v4 = v2;
  }
  v6 = (float)v4;
  return *((float *)&v6 + 1);
}


// ========================================================================
// ?GetStopPowerTurnSpeed@idVehicleAI@@QAAMXZ
// EA  : 0x82B09230
// RVA : 0x00B09230
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

float __fastcall idVehicleAI::GetStopPowerTurnSpeed(idVehicleAI *this)
{
  double stopPowerTurnSpeed; // fp1

  if ( this->overrideControlTime <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED)
    || (stopPowerTurnSpeed = this->overrideControl.stopPowerTurnSpeed) == -1.0 )
  {
    stopPowerTurnSpeed = this->control.stopPowerTurnSpeed;
  }
  return *((float *)&stopPowerTurnSpeed + 1);
}


// ========================================================================
// ?GetTraversalStepSize@idVehicleAI@@QAAMXZ
// EA  : 0x82B09298
// RVA : 0x00B09298
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

float __fastcall idVehicleAI::GetTraversalStepSize(idVehicleAI *this)
{
  double traversalStepSize; // fp1

  if ( this->overrideControlTime <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED)
    || (traversalStepSize = this->overrideControl.traversalStepSize) == -1.0 )
  {
    traversalStepSize = this->control.traversalStepSize;
  }
  return *((float *)&traversalStepSize + 1);
}


// ========================================================================
// ?GetBackupSpeed@idVehicleAI@@QAAMXZ
// EA  : 0x82B09300
// RVA : 0x00B09300
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

float __fastcall idVehicleAI::GetBackupSpeed(idVehicleAI *this)
{
  double backupSpeed; // fp1

  if ( this->overrideControlTime <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED)
    || (backupSpeed = this->overrideControl.backupSpeed) == -1.0 )
  {
    backupSpeed = this->control.backupSpeed;
  }
  return *((float *)&backupSpeed + 1);
}


// ========================================================================
// ?UpdateControlParams@idVehicleAI@@QAAXAAUvaiControl_t@@_N@Z
// EA  : 0x82B09B40
// RVA : 0x00B09B40
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::UpdateControlParams(
        idVehicleAI *this,
        vaiControl_t *params,
        bool initialize,
        long double a4,
        int a5,
        int a6,
        int a7,
        __int64 a8)
{
  double speedLimit; // fp0
  double stopDistance; // fp0
  double moveDistance; // fp0
  double decelDistance; // fp0
  double maxCurveSpeed; // fp0
  double maxCurveAngle; // fp0
  double maxStepAngle; // fp13
  double powerTurnSpeed; // fp13
  int powerTurnTime; // r11
  double stopPowerTurnSpeed; // fp13
  double traversalStepSize; // fp13
  double backupSpeed; // fp13
  long double v22; // fp2
  long double v23; // fp2
  double v24; // fp0
  double v25; // fp0
  double v26; // fp0
  double v27; // fp0
  double maxCurveCosine; // fp0
  double maxStepCosine; // fp0
  long double v30; // fp2
  vaiObstacleAvoidance_t avoidanceType; // r11
  double v32; // fp0
  int v33; // r11
  double v34; // fp0
  double v35; // fp0
  double v36; // fp0

  speedLimit = params->speedLimit;
  if ( initialize )
  {
    if ( speedLimit == -1.0 )
      speedLimit = 0.0;
    this->control.speedLimit = speedLimit;
    stopDistance = params->stopDistance;
    if ( stopDistance == -1.0 )
      stopDistance = 400.0;
    this->control.stopDistance = stopDistance;
    moveDistance = params->moveDistance;
    if ( moveDistance == -1.0 )
      moveDistance = 800.0;
    this->control.moveDistance = moveDistance;
    decelDistance = params->decelDistance;
    if ( decelDistance == -1.0 )
      decelDistance = 2000.0;
    this->control.decelDistance = decelDistance;
    maxCurveSpeed = params->maxCurveSpeed;
    if ( maxCurveSpeed == -1.0 )
      maxCurveSpeed = 95.0;
    this->control.maxCurveSpeed = maxCurveSpeed;
    maxCurveAngle = params->maxCurveAngle;
    if ( maxCurveAngle == -1.0 )
      maxCurveAngle = 60.0;
    this->control.maxCurveCosine = maxCurveAngle;
    maxStepAngle = params->maxStepAngle;
    if ( maxStepAngle == -1.0 )
      maxStepAngle = 60.0;
    this->control.maxStepCosine = maxStepAngle;
    this->control.avoidanceType = params->avoidanceType == OAT_INIT ? OAT_GENERAL : params->avoidanceType;
    powerTurnSpeed = params->powerTurnSpeed;
    if ( powerTurnSpeed == -1.0 )
      powerTurnSpeed = 30.0;
    this->control.powerTurnSpeed = powerTurnSpeed;
    powerTurnTime = params->powerTurnTime;
    if ( powerTurnTime == -1 )
      powerTurnTime = 250;
    this->control.powerTurnTime = powerTurnTime;
    stopPowerTurnSpeed = params->stopPowerTurnSpeed;
    if ( stopPowerTurnSpeed == -1.0 )
      stopPowerTurnSpeed = 0.0;
    this->control.stopPowerTurnSpeed = stopPowerTurnSpeed;
    traversalStepSize = params->traversalStepSize;
    if ( traversalStepSize == -1.0 )
      traversalStepSize = 500.0;
    this->control.traversalStepSize = traversalStepSize;
    backupSpeed = params->backupSpeed;
    if ( backupSpeed == -1.0 )
      backupSpeed = 22.5;
    this->control.backupSpeed = backupSpeed;
    *(double *)&a4 = (float)((float)maxCurveAngle * idMath::M_DEG2RAD);
    v22 = cos(x: a4);
    this->control.maxCurveCosine = *(double *)&v22;
    *(double *)&v22 = (float)(this->control.maxStepCosine * idMath::M_DEG2RAD);
    v23 = cos(x: v22);
    this->control.maxStepCosine = *(double *)&v23;
  }
  else
  {
    if ( speedLimit == -1.0 )
      speedLimit = this->control.speedLimit;
    this->control.speedLimit = speedLimit;
    v24 = params->stopDistance;
    if ( v24 == -1.0 )
      v24 = this->control.stopDistance;
    this->control.stopDistance = v24;
    v25 = params->moveDistance;
    if ( v25 == -1.0 )
      v25 = this->control.moveDistance;
    this->control.moveDistance = v25;
    v26 = params->decelDistance;
    if ( v26 == -1.0 )
      v26 = this->control.decelDistance;
    this->control.decelDistance = v26;
    v27 = params->maxCurveSpeed;
    if ( v27 == -1.0 )
      v27 = this->control.maxCurveSpeed;
    this->control.maxCurveSpeed = v27;
    if ( params->maxCurveAngle == -1.0 )
    {
      maxCurveCosine = this->control.maxCurveCosine;
    }
    else
    {
      *(double *)&a4 = (float)(params->maxCurveAngle * idMath::M_DEG2RAD);
      a4 = cos(x: a4);
      maxCurveCosine = (float)*(double *)&a4;
    }
    this->control.maxCurveCosine = maxCurveCosine;
    if ( params->maxStepAngle == -1.0 )
    {
      maxStepCosine = this->control.maxStepCosine;
    }
    else
    {
      *(double *)&a4 = (float)(params->maxStepAngle * idMath::M_DEG2RAD);
      v30 = cos(x: a4);
      maxStepCosine = (float)*(double *)&v30;
    }
    this->control.maxStepCosine = maxStepCosine;
    avoidanceType = params->avoidanceType;
    LODWORD(a8) = avoidanceType;
    if ( (float)a8 == -1.0 )
      avoidanceType = this->control.avoidanceType;
    this->control.avoidanceType = avoidanceType;
    v32 = params->powerTurnSpeed;
    if ( v32 == -1.0 )
      v32 = this->control.powerTurnSpeed;
    this->control.powerTurnSpeed = v32;
    v33 = params->powerTurnTime;
    if ( v33 == -1 )
      v33 = this->control.powerTurnTime;
    this->control.powerTurnTime = v33;
    v34 = params->stopPowerTurnSpeed;
    if ( v34 == -1.0 )
      v34 = this->control.stopPowerTurnSpeed;
    this->control.stopPowerTurnSpeed = v34;
    v35 = params->traversalStepSize;
    if ( v35 == -1.0 )
      v35 = this->control.traversalStepSize;
    this->control.traversalStepSize = v35;
    v36 = params->backupSpeed;
    if ( v36 == -1.0 )
      v36 = this->control.backupSpeed;
    this->control.backupSpeed = v36;
  }
}


// ========================================================================
// ?SetNoControl@idVehicleAI@@QAAXHM@Z
// EA  : 0x82B09E30
// RVA : 0x00B09E30
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::SetNoControl(idVehicleAI *this, int timeMS, double velocitySqr)
{
  int GameMs; // r3

  GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
  this->aiNoControlVelocitySqr = velocitySqr;
  this->aiNoControlTime = GameMs + timeMS;
}


// ========================================================================
// ?ClearTimers@idVehicleAI@@IAAXXZ
// EA  : 0x82B09E98
// RVA : 0x00B09E98
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::ClearTimers(idVehicleAI *this)
{
  __int64 v1; // r9
  idDebugHUD_vtbl *v2; // r29
  double v3; // fp1
  idDebugHUD_vtbl *v4; // r29
  double v5; // fp1
  idDebugHUD_vtbl *v6; // r29
  double v7; // fp1
  idDebugHUD_vtbl *v8; // r29
  double v9; // fp1
  idDebugHUD_vtbl *v10; // r29
  double v11; // fp1
  idDebugHUD_vtbl *v12; // r29
  double v13; // fp1
  idDebugHUD_vtbl *v14; // r28
  int determineGoal_count; // r29
  double v16; // fp1
  idDebugHUD_vtbl *v17; // r29
  double v18; // fp1
  idDebugHUD_vtbl *v19; // r29
  double v20; // fp1
  idDebugHUD_vtbl *v21; // r29
  double v22; // fp1
  int entsWithinDist_count; // r29
  idDebugHUD_vtbl *v24; // r28
  double v25; // fp1
  idDebugHUD_vtbl *v26; // r29
  double v27; // fp1
  idDebugHUD_vtbl *v28; // r29
  double v29; // fp1
  idDebugHUD_vtbl *v30; // r29
  double v31; // fp1
  idDebugHUD_vtbl *v32; // r29
  double v33; // fp1
  idDebugHUD_vtbl *v34; // r29
  double v35; // fp1
  idDebugHUD_vtbl *v36; // r29
  double v37; // fp1
  idDebugHUD_vtbl *v38; // r29
  double v39; // fp1
  idDebugHUD_vtbl *v40; // r29
  double v41; // fp1
  idDebugHUD_vtbl *v42; // r29
  double v43; // [sp+20h] [-60h]

  if ( vaiTimer.framenum != idAccolade::Count(this: &clientGame->gameTimeManager) )
  {
    vaiTimer.framenum = idAccolade::Count(this: &clientGame->gameTimeManager);
    if ( vai_timer.valueFloat != 0.0 )
    {
      if ( spl_timer.valueInteger == 0 )
      {
        cvarSystem->SetCVarInteger(this: cvarSystem, a2: "com_debugHUD", a3: 1, a4: 0);
        debugHUD->Clear(this: debugHUD, a2: false);
        debugHUD->Printf_3(this: debugHUD, a2: 0, a3: 0, a4: &byte_8200D768);
      }
      debugHUD->SetTextScale(this: debugHUD, a2: 1.0);
      debugHUD->Printf(this: debugHUD, a2: "\n\n\n^3     -- VAI TIMING ( %d active ) --\n", vaiTimer.activeCount);
      v2 = debugHUD->__vftable;
      v3 = idTimer::Milliseconds(this: &vaiTimer.total);
      v2->Printf(this: debugHUD, a2: "^7           Total: ^2%4.2fms\n", LODWORD(v3));
      v4 = debugHUD->__vftable;
      v5 = idTimer::Milliseconds(this: &vaiTimer.states);
      v4->Printf(this: debugHUD, a2: "\n^7          States: ^2%4.2fms\n", LODWORD(v5));
      v6 = debugHUD->__vftable;
      v7 = idTimer::Milliseconds(this: &vaiTimer.st_commands);
      v6->Printf(this: debugHUD, a2: "^7     ST Commands: ^2%4.2fms\n", LODWORD(v7));
      v8 = debugHUD->__vftable;
      v9 = idTimer::Milliseconds(this: &vaiTimer.st_decision);
      v8->Printf(this: debugHUD, a2: "^7     ST Decision: ^2%4.2fms\n", LODWORD(v9));
      v10 = debugHUD->__vftable;
      v11 = idTimer::Milliseconds(this: &vaiTimer.st_attack);
      v10->Printf(this: debugHUD, a2: "^7     ST   Attack: ^2%4.2fms\n", LODWORD(v11));
      v12 = debugHUD->__vftable;
      v13 = idTimer::Milliseconds(this: &vaiTimer.st_movement);
      v12->Printf(this: debugHUD, a2: "^7     ST Movement: ^2%4.2fms\n", LODWORD(v13));
      v14 = debugHUD->__vftable;
      determineGoal_count = vaiTimer.determineGoal_count;
      v16 = idTimer::Milliseconds(this: &vaiTimer.determineGoal);
      v14->Printf(this: debugHUD, a2: "\n^7      Determine Goal: ^2%4.2fms ( %d )\n", LODWORD(v16), determineGoal_count);
      v17 = debugHUD->__vftable;
      v18 = idTimer::Milliseconds(this: &vaiTimer.determineGoal_path);
      v17->Printf(this: debugHUD, a2: "             .. path: ^7( ^2%4.2fms ^7)\n", LODWORD(v18));
      v19 = debugHUD->__vftable;
      v20 = idTimer::Milliseconds(this: &vaiTimer.determineGoal_distWangle);
      v19->Printf(this: debugHUD, a2: "       .. distWangle: ^7( ^2%4.2fms ^7)\n", LODWORD(v20));
      v21 = debugHUD->__vftable;
      v22 = idTimer::Milliseconds(this: &vaiTimer.findEnemy);
      v21->Printf(this: debugHUD, a2: "^7          Find Enemy: ^2%4.2fms\n", LODWORD(v22));
      entsWithinDist_count = vaiTimer.entsWithinDist_count;
      v24 = debugHUD->__vftable;
      v25 = idTimer::Milliseconds(this: &vaiTimer.findEnemy_entsWithinDist);
      v24->Printf(this: debugHUD, a2: (const char *)HIDWORD(v25), LODWORD(v25), entsWithinDist_count);
      v26 = debugHUD->__vftable;
      v27 = idTimer::Milliseconds(this: &vaiTimer.findEnemy_spliWithinDist);
      v26->Printf(this: debugHUD, a2: "       .. spliInDist: ^7( ^2%4.2fms ^7)\n", LODWORD(v27));
      v28 = debugHUD->__vftable;
      v29 = idTimer::Milliseconds(this: &vaiTimer.avoidObstacles);
      v28->Printf(this: debugHUD, a2: (const char *)HIDWORD(v29), LODWORD(v29));
      v30 = debugHUD->__vftable;
      v31 = idTimer::Milliseconds(this: &vaiTimer.avoidObstacles_findPath);
      v30->Printf(this: debugHUD, a2: "         .. findPath: ^7( ^2%4.2fms ^7)\n", LODWORD(v31));
      v32 = debugHUD->__vftable;
      v33 = idTimer::Milliseconds(this: &vaiTimer.calcSteering);
      v32->Printf(this: debugHUD, a2: "^7  Determine Steering: ^2%4.2fms\n", LODWORD(v33));
      v34 = debugHUD->__vftable;
      v35 = idTimer::Milliseconds(this: &vaiTimer.calcSpeed);
      v34->Printf(this: debugHUD, a2: "^7     Determine Speed: ^2%4.2fms\n", LODWORD(v35));
      v36 = debugHUD->__vftable;
      v37 = idTimer::Milliseconds(this: &vaiTimer.calcSpeed_distWinAngle);
      v36->Printf(this: debugHUD, a2: (const char *)HIDWORD(v37), LODWORD(v37));
      v38 = debugHUD->__vftable;
      v39 = idTimer::Milliseconds(this: &vaiTimer.movement);
      v38->Printf(this: debugHUD, a2: "^7     Update Movement: ^2%4.2fms\n", LODWORD(v39));
      v40 = debugHUD->__vftable;
      v41 = idTimer::Milliseconds(this: &vaiTimer.weapons);
      v40->Printf(this: debugHUD, a2: "^7      Update weapons: ^2%4.2fms\n", LODWORD(v41));
      v42 = debugHUD->__vftable;
      v43 = idTimer::Milliseconds(this: &vaiTimer.sounds);
      v42->Printf(this: debugHUD, a2: "^7       Update Sounds: ^2%4.2fms\n", LODWORD(v43));
    }
    LODWORD(v1) = 0;
    vaiTimer.total.clockTicks = 0;
    vaiTimer.states.clockTicks = 0;
    vaiTimer.st_decision.clockTicks = v1;
    vaiTimer.st_movement.clockTicks = 0;
    vaiTimer.st_attack.clockTicks = 0;
    vaiTimer.st_commands.clockTicks = v1;
    vaiTimer.determineGoal.clockTicks = 0;
    vaiTimer.determineGoal_path.clockTicks = 0;
    vaiTimer.determineGoal_distWangle.clockTicks = v1;
    vaiTimer.findEnemy.clockTicks = 0;
    vaiTimer.findEnemy_entsWithinDist.clockTicks = 0;
    vaiTimer.findEnemy_spliWithinDist.clockTicks = v1;
    vaiTimer.avoidObstacles.clockTicks = 0;
    vaiTimer.avoidObstacles_findPath.clockTicks = 0;
    vaiTimer.distToGoal.clockTicks = v1;
    vaiTimer.calcSpeed.clockTicks = 0;
    vaiTimer.calcSpeed_distWinAngle.clockTicks = 0;
    vaiTimer.script.clockTicks = v1;
    vaiTimer.getObs.clockTicks = 0;
    vaiTimer.calcSteering.clockTicks = 0;
    vaiTimer.movement.clockTicks = v1;
    vaiTimer.weapons.clockTicks = 0;
    vaiTimer.sounds.clockTicks = 0;
    vaiTimer.activeCount = 0;
    vaiTimer.determineGoal_count = 0;
    vaiTimer.entsWithinDist_count = 0;
  }
}


// ========================================================================
// ?GetAttackRange@idVehicleAI@@QAAMXZ
// EA  : 0x82B0A400
// RVA : 0x00B0A400
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

float __fastcall idVehicleAI::GetAttackRange(idVehicleAI *this)
{
  double range; // fp1
  vehicleAiSetup_t::attack_t *currentAttack; // r11

  if ( vai_attackState.valueInteger > 0x1Du
    || idStr::Icmp(s1: vai_follow.valueString.data, s2: this->name.data) != 0
    || (range = vai_attackRange.valueFloat, vai_attackRange.valueFloat <= 0.0) )
  {
    currentAttack = this->currentAttack;
    if ( currentAttack != nullptr )
    {
      range = currentAttack->params.range;
      if ( range == -1.0 )
        range = currentAttack->decl->params.range;
    }
    else
    {
      range = 0.0;
    }
  }
  return *((float *)&range + 1);
}


// ========================================================================
// ?AngleTowardsGoal@idVehicleAI@@IAAXAAVidAngles@@V2@M11M@Z
// EA  : 0x82B0A4B8
// RVA : 0x00B0A4B8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::AngleTowardsGoal(
        idVehicleAI *this,
        idAngles *current,
        idAngles *goal,
        double moveScale,
        idAngles *minAngles,
        idAngles *maxAngles,
        double rotateSpeed,
        int a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        int a15,
        int a16,
        float a17,
        float a18,
        float a19,
        float a20,
        float a21,
        float a22,
        float a23,
        float a24,
        float a25,
        float a26,
        float a27,
        float a28,
        float a29,
        float a30,
        float a31,
        float a32,
        float a33,
        float a34,
        float a35,
        float a36,
        float a37)
{
  double v32; // fp19
  double v34; // fp17
  double v36; // fp25
  double v37; // fp1
  double v38; // fp28
  double v39; // fp21
  double v40; // fp20
  double v41; // fp27
  double v42; // fp1
  double v43; // fp31
  double v44; // fp23
  double v45; // fp22
  double v46; // fp30
  double v47; // fp1
  char v48; // r11
  double v49; // fp0
  double v50; // fp7
  double v51; // fp6
  double v52; // fp0
  double v53; // fp13
  double v54; // fp11
  double v55; // fp9
  double v56; // fp13
  double v57; // fp13
  double pitch; // fp0
  double yaw; // fp0
  double roll; // fp0

  v32 = *(float *)&maxAngles;
  v34 = COERCE_FLOAT(byte_821B0000);
  if ( *(float *)&maxAngles >= -180.0 || v34 <= 180.0 )
  {
    v36 = *(float *)&current;
    if ( *(float *)&current >= v32 )
    {
      if ( v36 > v34 )
        v36 = COERCE_FLOAT(byte_821B0000);
    }
    else
    {
      v36 = *(float *)&maxAngles;
    }
    v38 = (float)((float)v36 - current->pitch);
  }
  else
  {
    v36 = *(float *)&current;
    v37 = idMath::AngleNormalize360(angle: (float)(*(float *)&current - current->pitch));
    if ( v37 > 180.0 )
      v37 = (float)((float)v37 - (float)360.0);
    v38 = v37;
  }
  v39 = *(float *)&a8;
  v40 = *(float *)&a16;
  if ( *(float *)&a8 >= -180.0 || v40 <= 180.0 )
  {
    v41 = *(float *)&goal;
    if ( *(float *)&goal >= v39 )
    {
      if ( v41 > v40 )
        v41 = *(float *)&a16;
    }
    else
    {
      v41 = *(float *)&a8;
    }
    v43 = (float)((float)v41 - current->yaw);
  }
  else
  {
    v41 = *(float *)&goal;
    v42 = idMath::AngleNormalize360(angle: (float)(*(float *)&goal - current->yaw));
    if ( v42 > 180.0 )
      v42 = (float)((float)v42 - (float)360.0);
    v43 = v42;
  }
  v44 = *(float *)&a8;
  v45 = a37;
  if ( *(float *)&a8 >= -180.0 || v45 <= 180.0 )
  {
    v46 = *(float *)&goal;
    if ( *(float *)&goal >= v44 )
    {
      if ( v46 > v45 )
        v46 = a37;
    }
    else
    {
      v46 = *(float *)&a8;
    }
    v47 = (float)((float)v46 - current->roll);
  }
  else
  {
    v46 = *(float *)&goal;
    v47 = idMath::AngleNormalize360(angle: (float)(*(float *)&goal - current->roll));
    if ( v47 > 180.0 )
      v47 = (float)((float)v47 - (float)360.0);
  }
  if ( ang_zero.pitch != v38 || ang_zero.yaw != v43 || (v48 = 1, ang_zero.roll != v47) )
    v48 = 0;
  if ( v48 == 0 )
  {
    v49 = __fabs(v43) <= __fabs(v38)
        ? (float)((float)v38 / (float)((float)moveScale * (float)rotateSpeed))
        : (float)((float)v43 / (float)((float)moveScale * (float)rotateSpeed));
    if ( __fabs(v49) >= 0.000099999997 )
    {
      v50 = (float)((float)((float)1.0 / (float)v49) * (float)v38);
      v51 = (float)((float)((float)1.0 / (float)v49) * (float)v47);
      v52 = __fabs((float)((float)((float)1.0 / (float)v49) * (float)v43));
      v53 = __fabs(v50);
      v54 = __fabs(v51);
      if ( v52 <= __fabs(v43) )
      {
        if ( v43 <= 0.0 )
          v55 = (float)(current->yaw - (float)v52);
        else
          v55 = (float)(current->yaw + (float)v52);
        current->yaw = v55;
      }
      else
      {
        current->yaw = v41;
      }
      if ( v53 <= __fabs(v38) )
      {
        if ( v38 <= 0.0 )
          v56 = (float)(current->pitch - (float)v53);
        else
          v56 = (float)(current->pitch + (float)v53);
        current->pitch = v56;
      }
      else
      {
        current->pitch = v36;
      }
      if ( (float)((float)v54 * (float)moveScale) <= __fabs(v38) )
      {
        if ( v47 <= 0.0 )
          v57 = (float)(current->roll - (float)v54);
        else
          v57 = (float)(current->roll + (float)v54);
        current->roll = v57;
      }
      else
      {
        current->roll = v46;
      }
      if ( v32 != -180.0 || v34 != 180.0 )
      {
        pitch = current->pitch;
        if ( pitch >= v32 )
        {
          if ( pitch > v34 )
            pitch = COERCE_FLOAT(byte_821B0000);
        }
        else
        {
          pitch = v32;
        }
        current->pitch = pitch;
      }
      if ( v39 != -180.0 || v40 != 180.0 )
      {
        yaw = current->yaw;
        if ( yaw >= v39 )
        {
          if ( yaw > v40 )
            yaw = *(float *)&a16;
        }
        else
        {
          yaw = *(float *)&a8;
        }
        current->yaw = yaw;
      }
      if ( v44 != -180.0 || v45 != 180.0 )
      {
        roll = current->roll;
        if ( roll >= v44 )
        {
          if ( roll > v45 )
            roll = a37;
        }
        else
        {
          roll = *(float *)&a8;
        }
        current->roll = roll;
      }
    }
  }
}


// ========================================================================
// ?DetermineBraking@idVehicleAI@@QAAHXZ
// EA  : 0x82B0A820
// RVA : 0x00B0A820
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

int __fastcall idVehicleAI::DetermineBraking(idVehicleAI *this)
{
  double desiredSpeed; // fp0
  int v3; // r29
  double powerTurnSpeed; // fp0
  __int64 v5; // r9
  int result; // r3
  bool v7; // zf

  desiredSpeed = this->desiredSpeed;
  v3 = 0;
  if ( desiredSpeed <= 0.0 )
  {
    if ( desiredSpeed >= 0.0 || this->actualSpeed < desiredSpeed )
      goto LABEL_6;
  }
  else if ( this->actualSpeed > desiredSpeed )
  {
LABEL_6:
    v3 = 1;
  }
  if ( this->overrideControlTime <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED)
    || (powerTurnSpeed = this->overrideControl.powerTurnSpeed) == -1.0 )
  {
    powerTurnSpeed = this->control.powerTurnSpeed;
  }
  if ( powerTurnSpeed == 0.0 )
    return v3;
  if ( __fabs(this->immediateGoalAngle) < 120.0 )
    goto LABEL_15;
  if ( this->actualSpeed > (double)idVehicleAI::GetPowerTurnSpeed(this) )
  {
    LODWORD(v5) = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    this->handBrakeTime = (int)(float)(idVehicleAI::GetPowerTurnTime(this) + (float)v5);
  }
  if ( this->actualSpeed <= (double)idVehicleAI::GetPowerTurnSpeed(this) )
LABEL_15:
    this->handBrakeTime = 0;
  v7 = this->handBrakeTime > gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  result = v3 | 2;
  if ( !v7 )
    return v3;
  return result;
}


// ========================================================================
// ?GetSplineTracker@idVehicleAI@@QBAPAVidNavPathPosTracker@@XZ
// EA  : 0x82B0A980
// RVA : 0x00B0A980
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

idNavPathPosTracker *__fastcall idVehicleAI::GetSplineTracker(idVehicleAI *this)
{
  idNavPathPosTracker *result; // r3

  result = this->splineTracker;
  if ( result == nullptr )
    return &this->splinePathMgr->null_splineTracker;
  return result;
}


// ========================================================================
// ?GetRightDistance@idVehicleAI@@QAAMXZ
// EA  : 0x82B0A9A0
// RVA : 0x00B0A9A0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

float __fastcall idVehicleAI::GetRightDistance(idVehicleAI *this)
{
  idNavPathPosTracker *splineTracker; // r11
  double rightDistance; // fp1

  splineTracker = this->splineTracker;
  if ( splineTracker != nullptr )
    rightDistance = splineTracker->pathPosition.rightDistance;
  else
    rightDistance = this->splinePathMgr->null_splineTracker.pathPosition.rightDistance;
  return *((float *)&rightDistance + 1);
}


// ========================================================================
// ?Event_SetNewChaseWaypoint@idVehicleAI@@QAA?AVeventVoid@@PAVidSplineWaypoint@@@Z
// EA  : 0x82B0A9C8
// RVA : 0x00B0A9C8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

idVehicleAI *__fastcall idVehicleAI::Event_SetNewChaseWaypoint(
        idVehicleAI *this,
        eventVoid *result,
        idSplineWaypoint *newWayPoint)
{
  idVS_ds_Car_Chase *State; // r3
  idVS_ds_Car_Chase *v6; // r3

  State = (idVS_ds_Car_Chase *)idFiniteStateMachine::FindState(
                                 this: (idFiniteStateMachine *)&result[3124],
                                 name: "idVS_ds_Car_Chase");
  if ( State != nullptr )
  {
    v6 = idVS_ds_Car_Chase::CastTo(c: State);
    if ( v6 != nullptr )
    {
      v6->currentWayPoint = newWayPoint;
      v6->currentState = STATE_HANDLE_SCRIPT;
    }
    else
    {
      idLib::Warning(fmt: "Vehicle AI::Event_SetNewChaseWaypoint - Could not convert state to idVS_ds_Car_Chase! ");
    }
  }
  else
  {
    idLib::Warning(fmt: "Vehicle AI::Event_SetNewChaseWaypoint - Could not find AI state, idVS_ds_Car_Chase! ");
  }
  return this;
}


// ========================================================================
// ?EnemyNearMe@idVehicleAI@@QAAPAVidEntity@@XZ
// EA  : 0x82B0AA58
// RVA : 0x00B0AA58
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

idEntity *__fastcall idVehicleAI::EnemyNearMe(idVehicleAI *this)
{
  idPhysics *Physics; // r3
  float *v3; // r3
  double v4; // fp8
  double v5; // fp7
  double v6; // fp5
  int EntitiesTouchingBounds; // r3
  idEntity *v8; // r26
  double v9; // fp31
  int *v10; // r29
  int i; // r27
  idEntity *v12; // r31
  idFaction *v13; // r3
  idPhysics *v14; // r25
  idPhysics *v15; // r24
  float *v16; // r25
  float *v17; // r3
  double v18; // fp10
  double v19; // fp8
  idBounds v21; // [sp+50h] [-F0h] BYREF
  int v22[32]; // [sp+70h] [-D0h] BYREF

  Physics = idEntity::GetPhysics(this);
  v3 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v21.b[0].x = *v3;
  v21.b[0].y = v3[1];
  v21.b[0].z = v3[2];
  v4 = (float)(*v3 + (float)5000.0);
  v21.b[1].x = *v3;
  v5 = (float)(v3[1] + (float)5000.0);
  v21.b[1].y = v3[1];
  v6 = (float)(v3[2] + (float)5000.0);
  v21.b[0].x = v21.b[0].x - (float)5000.0;
  v21.b[0].y = v21.b[0].y - (float)5000.0;
  v21.b[0].z = v21.b[0].z - (float)5000.0;
  v21.b[1].x = v4;
  v21.b[1].y = v5;
  v21.b[1].z = v6;
  EntitiesTouchingBounds = idClip::GetEntitiesTouchingBounds(
                             this: &clientGame->clip,
                             bounds: &v21,
                             clipMask: 99328,
                             entityList: v22,
                             maxCount: 32);
  v8 = nullptr;
  v9 = 1.0e30;
  if ( EntitiesTouchingBounds > 0 )
  {
    v10 = v22;
    for ( i = EntitiesTouchingBounds; i != 0; --i )
    {
      v12 = gameLocal->entities.ptr[*v10];
      v13 = this->GetFaction(this);
      if ( idFaction::GetAttitudeTowards(this: v13, otherEnt: v12) < ATTITUDE_NEUTRAL )
      {
        v14 = idEntity::GetPhysics(this: v12);
        v15 = idEntity::GetPhysics(this);
        v16 = (float *)v14->GetOrigin(this: v14, a2: 0);
        v17 = (float *)v15->GetOrigin(this: v15, a2: 0);
        v18 = (float)(v17[1] - v16[1]);
        v19 = (float)(v17[2] - v16[2]);
        if ( (float)((float)((float)(*v17 - *v16) * (float)(*v17 - *v16))
                   + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18))) < v9 )
        {
          v9 = (float)((float)((float)(*v17 - *v16) * (float)(*v17 - *v16))
                     + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18)));
          v8 = v12;
        }
      }
      ++v10;
    }
  }
  return v8;
}


// ========================================================================
// ?OverrideControl@idVehicleAI@@QAAXAAUvaiControl_t@@M@Z
// EA  : 0x82B0AC10
// RVA : 0x00B0AC10
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::OverrideControl(
        idVehicleAI *this,
        vaiControl_t *control,
        long double time,
        int a4,
        int a5,
        int a6,
        int a7,
        __int64 a8)
{
  double v8; // fp31

  v8 = *(double *)&time;
  if ( *(double *)&time == -1.0 )
  {
    idVehicleAI::UpdateControlParams(this, params: control, initialize: false, a4: time, a5, a6, a7, a8);
  }
  else
  {
    memcpy(Dst: &this->overrideControl, Src: control, Size: sizeof(this->overrideControl));
    this->overrideControlTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED)
                              - (int)(float)((float)v8 * (float)-1000.0);
  }
}


// ========================================================================
// ?CheckForBlocked@idVehicleAI@@QAA_NM@Z
// EA  : 0x82B0ACA8
// RVA : 0x00B0ACA8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

int __fastcall idVehicleAI::CheckForBlocked(idVehicleAI *this, double dSpeed)
{
  bool v3; // r11
  int valueInteger; // r30

  if ( vai_noMovement.valueInteger == 0 )
  {
    v3 = false;
    if ( __fabs(dSpeed) > 1.0 )
      v3 = __fabs((float)(this->actualSpeed / (float)dSpeed)) < 0.1;
    if ( v3 )
    {
      if ( this->blockedTime == 0 )
      {
        this->blockedTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
        return 0;
      }
      valueInteger = vai_blockedBackupTime.valueInteger;
      if ( gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - this->blockedTime > valueInteger )
      {
        this->blockedTime = 0;
        return 1;
      }
    }
    else
    {
      this->blockedTime = 0;
    }
  }
  return 0;
}


// ========================================================================
// ?GetCurrentCommand@idVehicleAI@@QAAPAUcommands_t@vehicleAiSetup_t@@XZ
// EA  : 0x82B0AD98
// RVA : 0x00B0AD98
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

vehicleAiSetup_t::commands_t *__fastcall idVehicleAI::GetCurrentCommand(idVehicleAI *this)
{
  int mCurrentCommand; // r11

  mCurrentCommand = this->cs_NextCommand.mCurrentCommand;
  if ( mCurrentCommand < 0 )
    return nullptr;
  else
    return &this->setup.commands.list[mCurrentCommand];
}


// ========================================================================
// ?Event_Gibbed@idActor@@AAA?AVeventVoid@@XZ
// EA  : 0x82B0ADC0
// RVA : 0x00B0ADC0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

idVehicleAI *__fastcall idActor::Event_Gibbed(idVehicleAI *this, idEventReceiver *result)
{
  idEventReceiver::PostEventMS(this: result, ev: &EV_Remove, time: 0);
  return this;
}


// ========================================================================
// ?PopControlParams@idVehicleAI@@QAAXXZ
// EA  : 0x82B0AE00
// RVA : 0x00B0AE00
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::PopControlParams(idVehicleAI *this)
{
  int v1; // r31
  idList<vaiControl_t,5> *p_controlStack; // r30

  v1 = this->controlStack.num - 1;
  if ( v1 >= 0 )
  {
    p_controlStack = &this->controlStack;
    memcpy(Dst: &this->control, Src: &this->controlStack.list[v1], Size: sizeof(this->control));
    idList<vaiControl_t,5>::RemoveIndex(this: p_controlStack, index: v1);
  }
}


// ========================================================================
// ?NormalizeEnemyRightDistance@idVehicleAI@@QAAMXZ
// EA  : 0x82B0B148
// RVA : 0x00B0B148
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

double __fastcall idVehicleAI::NormalizeEnemyRightDistance(idVehicleAI *this)
{
  idNavPathPosTracker *splineTracker; // r11

  splineTracker = this->splineTracker;
  if ( splineTracker == nullptr )
    splineTracker = &this->splinePathMgr->null_splineTracker;
  return idNavSplinePathMgr::NormalizeRightDistance(
           this: (idNavSplinePathMgr *)LODWORD(this->enemyTracker->pathPosition.distance),
           start: (idNavSplinePosition *)LODWORD(this->enemyTracker->pathPosition.rightDistance),
           end: (idNavSplinePosition *)__ROL4__(this->enemyTracker->pathPosition.navSpline, 32),
           path: (navSplinePath_t *)LODWORD(splineTracker->pathPosition.rightDistance));
}


// ========================================================================
// ?SetDecisionState@idVehicleAI@@QAAXHH_N@Z
// EA  : 0x82B0B188
// RVA : 0x00B0B188
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::SetDecisionState(idVehicleAI *this, int num, int delayTime, bool pushState)
{
  idVehicleFSM *p_decisionFSM; // r31
  idState *State; // r3
  const idTypeInfo *v9; // r4

  p_decisionFSM = &this->decisionFSM;
  State = idFiniteStateMachine::FindState(this: &this->decisionFSM, name: vehicleAiStateNames[num]);
  v9 = (const idTypeInfo *)State->GetType(this: State);
  if ( pushState )
    idVehicleBaseFSM::PushState(this: p_decisionFSM, stateType: v9, delayTime);
  else
    p_decisionFSM->SetState_3(this: p_decisionFSM, a2: v9, a3: delayTime, a4: false);
  this->attackFSM.nextUpdateTime = 0;
}


// ========================================================================
// ?SetAttackState@idVehicleAI@@QAAXABVidTypeInfo@@H_N@Z
// EA  : 0x82B0B220
// RVA : 0x00B0B220
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::SetAttackState(
        idVehicleAI *this,
        const idTypeInfo *stateType,
        int delayTime,
        bool pushState)
{
  idVehicleFSM *p_attackFSM; // r30

  p_attackFSM = &this->attackFSM;
  if ( idFiniteStateMachine::FindState(this: &this->attackFSM, stateType) == &this->attackFSM.s_Idle )
  {
    idList<idThread *,58>::Clear(this: &this->attackFSM.stateStack);
    pushState = false;
  }
  if ( pushState )
    idVehicleBaseFSM::PushState(this: p_attackFSM, stateType, delayTime);
  else
    p_attackFSM->SetState_3(this: p_attackFSM, a2: stateType, a3: delayTime, a4: false);
  this->attackFSM.nextUpdateTime = 0;
}


// ========================================================================
// ?SetNextAttack@idVehicleAI@@QAA_NPAUattack_t@vehicleAiSetup_t@@_N@Z
// EA  : 0x82B0B2B0
// RVA : 0x00B0B2B0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

int __fastcall idVehicleAI::SetNextAttack(idVehicleAI *this, vehicleAiSetup_t::attack_t *attack, bool pushState)
{
  idVehicleState *State; // r3
  idVehicleState *v7; // r3
  double range; // fp0
  idVehicleState *v9; // r29
  double time; // fp31
  const idTypeInfo *v12; // r3
  __int64 v13; // [sp+50h] [-40h]

  State = (idVehicleState *)idFiniteStateMachine::FindState(
                              this: &this->attackFSM,
                              name: vehicleAttackStateNames[attack->decl->state]);
  v7 = idVehicleState::CastTo(c: State);
  range = attack->params.range;
  v9 = v7;
  if ( range == -1.0 )
    range = attack->decl->params.range;
  if ( !v7->ValidAttack(this: v7, a2: range) )
    return 0;
  this->currentAttack = attack;
  if ( attack->params.time == -1.0 )
    time = attack->decl->params.time;
  else
    time = attack->params.time;
  v13 = __PAIR64__(&unk_82150000, gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED));
  this->numAttackAttempts = 0;
  this->nextAttackTime = (int)(float)((float)((float)time * (float)1000.0) + (float)v13);
  v12 = (const idTypeInfo *)v9->GetType(this: v9);
  idVehicleAI::SetAttackState(this, stateType: v12, delayTime: 0, pushState);
  return 1;
}


// ========================================================================
// ?SetNextAttack@idVehicleAI@@QAA_NW4vehicleAttack_t@@_N@Z
// EA  : 0x82B0B3F0
// RVA : 0x00B0B3F0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

int __fastcall idVehicleAI::SetNextAttack(idVehicleAI *this, vehicleAttack_t attackType, bool pushState)
{
  int v5; // r10
  const idDeclVehicleAttack **list; // r9
  int v7; // r11
  const idDeclVehicleAttack *v8; // r11
  vehicleAiSetup_t::attack_t *p_dynamicAttack; // r30
  idVehicleState *State; // r3
  idVehicleState *v12; // r3
  double range; // fp0
  idVehicleState *v14; // r29
  double time; // fp31
  const idTypeInfo *v16; // r3
  __int64 v17; // [sp+50h] [-40h]

  v5 = 0;
  if ( this->declPreload.declAttacks.num <= 0 )
  {
LABEL_5:
    v8 = nullptr;
  }
  else
  {
    list = this->declPreload.declAttacks.list;
    v7 = 0;
    while ( list[v7]->state != attackType )
    {
      ++v5;
      ++v7;
      if ( v5 >= this->declPreload.declAttacks.num )
        goto LABEL_5;
    }
    v8 = list[v5];
  }
  p_dynamicAttack = &this->dynamicAttack;
  this->dynamicAttack.decl = v8;
  if ( v8 == nullptr )
    return 0;
  State = (idVehicleState *)idFiniteStateMachine::FindState(
                              this: &this->attackFSM,
                              name: vehicleAttackStateNames[v8->state]);
  v12 = idVehicleState::CastTo(c: State);
  range = this->dynamicAttack.params.range;
  v14 = v12;
  if ( range == -1.0 )
    range = p_dynamicAttack->decl->params.range;
  if ( !v12->ValidAttack(this: v12, a2: range) )
    return 0;
  this->currentAttack = p_dynamicAttack;
  if ( this->dynamicAttack.params.time == -1.0 )
    time = p_dynamicAttack->decl->params.time;
  else
    time = this->dynamicAttack.params.time;
  v17 = __PAIR64__(&unk_82150000, gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED));
  this->numAttackAttempts = 0;
  this->nextAttackTime = (int)(float)((float)((float)time * (float)1000.0) + (float)v17);
  v16 = (const idTypeInfo *)v14->GetType(this: v14);
  idVehicleAI::SetAttackState(this, stateType: v16, delayTime: 0, pushState);
  return 1;
}


// ========================================================================
// ?ChooseAttackState@idVehicleAI@@QAAXXZ
// EA  : 0x82B0B580
// RVA : 0x00B0B580
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::ChooseAttackState(idVehicleAI *this)
{
  idNavPathPosTracker *enemyTracker; // r11
  int v3; // r30
  float rightDistance; // r9
  idNavSpline *navSpline; // r8
  signed int v6; // r29
  int v7; // r28
  _DWORD *v8; // r26
  const idDeclVehicleAttack *decl; // r10
  idVehicleState *State; // r3
  idVehicleState *v11; // r3
  vehicleAiSetup_t::attack_t *v12; // r11
  double range; // fp0
  vehicleAiSetup_t::attack_t *v14; // r11
  double minSpeed; // fp30
  double maxSpeed; // fp31
  double CurrentSpeedInMPH; // fp1
  unsigned int v18; // r7
  vehicleAiSetup_t::attack_t *list; // r9
  int v20; // r6
  vehicleAiSetup_t::attack_t *v21; // r4
  int num; // r4
  idNavSplinePosition v23; // [sp+50h] [-80h] BYREF
  _DWORD v24[9]; // [sp+5Ch] [-74h] BYREF

  if ( this->attackFSM.stateStack.num != 0 )
  {
    idVehicleBaseFSM::PopState(this: &this->attackFSM, setPoppedState: true);
    return;
  }
  enemyTracker = this->enemyTracker;
  v3 = 0;
  this->currentAttack = nullptr;
  rightDistance = enemyTracker->pathPosition.rightDistance;
  navSpline = enemyTracker->pathPosition.navSpline;
  v23.distance = enemyTracker->pathPosition.distance;
  v23.rightDistance = rightDistance;
  v23.navSpline = navSpline;
  if ( !idNavSplinePosition::IsOnDeadendPath(this: &v23)
    || (unsigned __int8)idVehicleAI::SetNextAttack(this, attackType: ATTACK_RANGE_SHOOT, pushState: false) == 0 )
  {
    memset(&v24[1], 0, 20);
    v6 = 0;
    v7 = 0;
    if ( this->setup.attack.types.num > 0 )
    {
      v8 = v24;
      do
      {
        decl = this->setup.attack.types.list[v3].decl;
        if ( decl != nullptr )
        {
          State = (idVehicleState *)idFiniteStateMachine::FindState(
                                      this: &this->attackFSM,
                                      name: vehicleAttackStateNames[decl->state]);
          v11 = idVehicleState::CastTo(c: State);
          if ( v11 != nullptr )
          {
            v12 = &this->setup.attack.types.list[v3];
            range = v12->params.range;
            if ( range == -1.0 )
              range = v12->decl->params.range;
            if ( v11->ValidAttack(this: v11, a2: range) )
            {
              v14 = &this->setup.attack.types.list[v3];
              if ( v14->params.minSpeed == -1.0 )
                minSpeed = v14->decl->params.minSpeed;
              else
                minSpeed = v14->params.minSpeed;
              if ( v14->params.maxSpeed == -1.0 )
                maxSpeed = v14->decl->params.maxSpeed;
              else
                maxSpeed = v14->params.maxSpeed;
              CurrentSpeedInMPH = idNavPathPosTracker::GetCurrentSpeedInMPH(this: this->enemyTracker);
              if ( CurrentSpeedInMPH >= minSpeed && CurrentSpeedInMPH <= maxSpeed )
              {
                *++v8 = v7;
                ++v6;
              }
            }
          }
        }
        ++v7;
        ++v3;
      }
      while ( v7 < this->setup.attack.types.num );
      if ( v6 > 0 )
      {
        __twllei(v6, 0);
        v18 = 1664525 * clientGame->random.seed + 1013904223;
        clientGame->random.seed = v18;
        list = this->setup.attack.types.list;
        v20 = (v18 >> 10) & 0x7FFF;
        __twlgei(v6 & ~(__ROL4__(v20, 1) - 1), 0xFFFFFFFF);
        v21 = &list[v24[v20 % v6 + 1]];
LABEL_27:
        idVehicleAI::SetNextAttack(this, attack: v21, pushState: false);
        return;
      }
    }
    if ( (unsigned __int8)idVehicleAI::SetNextAttack(this, attackType: ATTACK_RANGE_SHOOT, pushState: false) == 0 )
    {
      num = this->setup.attack.types.num;
      if ( num > 0 )
      {
        v21 = &this->setup.attack.types.list[idRandom2::RandomInt(this: &clientGame->random, max: num)];
        goto LABEL_27;
      }
    }
  }
}


// ========================================================================
// ?StopControllingVehicle@idVehicleAI@@QAAXXZ
// EA  : 0x82B0B828
// RVA : 0x00B0B828
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::StopControllingVehicle(idVehicleAI *this)
{
  this->movementFSM.SetState_3(this: &this->movementFSM, a2: &idVS_Idle::Type, a3: 0, a4: false);
  this->decisionFSM.SetState_3(this: &this->decisionFSM, a2: &idVS_Idle::Type, a3: 0, a4: false);
  this->attackFSM.nextUpdateTime = 0;
  idVehicleAI::SetAttackState(this, stateType: &idVS_Idle::Type, delayTime: 0, pushState: false);
  this->canControlVehicle = false;
  idEntity::BecomeInactive(this, flags: 1);
}


// ========================================================================
// ?Event_AiStopControllingVehicle@idVehicleAI@@QAA?AVeventVoid@@XZ
// EA  : 0x82B0B8B8
// RVA : 0x00B0B8B8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

idVehicleAI *__fastcall idVehicleAI::Event_AiStopControllingVehicle(idVehicleAI *this, idVehicleAI *result)
{
  idVehicleAI::StopControllingVehicle(this: result);
  return this;
}


// ========================================================================
// ?ResetStates@idVehicleAI@@QAAXXZ
// EA  : 0x82B0B8F0
// RVA : 0x00B0B8F0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::ResetStates(idVehicleAI *this)
{
  this->cs_NextCommand.mCurrentCommand = -1;
  this->commandsFSM.SetState_3(this: &this->commandsFSM, a2: &idVS_Idle::Type, a3: 0, a4: false);
  this->decisionFSM.SetState_3(this: &this->decisionFSM, a2: &idVS_Idle::Type, a3: 0, a4: false);
  this->movementFSM.SetState_3(this: &this->movementFSM, a2: &idVS_Idle::Type, a3: 0, a4: false);
  idVehicleAI::SetAttackState(this, stateType: &idVS_Idle::Type, delayTime: 0, pushState: false);
}


// ========================================================================
// ?HandleForcedRetreatState@idVehicleAI@@QAA_NXZ
// EA  : 0x82B0B9A8
// RVA : 0x00B0B9A8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

int __fastcall idVehicleAI::HandleForcedRetreatState(idVehicleAI *this)
{
  if ( this->inForcedRetreatState )
  {
    idVehicleAI::SetAttackState(this, stateType: &idVS_as_ForcedRetreat::Type, delayTime: 0, pushState: false);
    return 1;
  }
  else
  {
    if ( this->attackFSM.curState == &this->as_ForcedRetreat )
      idVehicleAI::ChooseAttackState(this);
    return 0;
  }
}


// ========================================================================
// ?ReleaseWeaponTriggers@idVehicleAI@@AAAXXZ
// EA  : 0x82B0BB48
// RVA : 0x00B0BB48
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::ReleaseWeaponTriggers(idVehicleAI *this)
{
  int value; // r10
  idVehicle_Car *v3; // r3
  int v4; // r28
  int i; // r30
  int v6; // r10
  idVehicle_Car *v7; // r3
  idVehicle_Car *v8; // r3
  idPresentable *presentable; // r3
  int v10; // r3
  int v11; // r10
  idVehicle_Car *v12; // r3
  idVehicle_Car *v13; // r3
  idPresentable *v14; // r3
  int v15; // r3
  idVehicleWeapon *v16; // r3

  value = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v3 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v3 != nullptr && idVehicle_Car::CastTo(c: v3) != nullptr )
    {
      v4 = 0;
      for ( i = 0; ; i += 4 )
      {
        v6 = this->vehicleCar.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v6 & 0x1FFF] == v6 >> 13
          && (v7 = (idVehicle_Car *)gameLocal->entities.ptr[v6 & 0x1FFF]) != nullptr )
        {
          v8 = idVehicle_Car::CastTo(c: v7);
        }
        else
        {
          v8 = nullptr;
        }
        presentable = v8->presentable;
        v10 = presentable != nullptr ? (int)presentable->GetVehicleInterface(this: presentable) : 0;
        if ( v4 >= *(_DWORD *)(v10 + 18748) )
          break;
        v11 = this->vehicleCar.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v11 & 0x1FFF] == v11 >> 13
          && (v12 = (idVehicle_Car *)gameLocal->entities.ptr[v11 & 0x1FFF]) != nullptr )
        {
          v13 = idVehicle_Car::CastTo(c: v12);
        }
        else
        {
          v13 = nullptr;
        }
        v14 = v13->presentable;
        if ( v14 != nullptr )
          v15 = (int)v14->GetVehicleInterface(this: v14);
        else
          v15 = 0;
        v16 = *(idVehicleWeapon **)(*(_DWORD *)(v15 + 18744) + i);
        if ( v16 != nullptr )
          idVehicleWeapon::ReleaseTrigger(this: v16);
        ++v4;
      }
    }
  }
}


// ========================================================================
// ?PullWeaponTriggers@idVehicleAI@@AAAXXZ
// EA  : 0x82B0BCB8
// RVA : 0x00B0BCB8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::PullWeaponTriggers(idVehicleAI *this)
{
  idNavPathPosTracker *enemyTracker; // r3
  BOOL v3; // r26
  idActor *Owner; // r3
  idActor *v5; // r3
  int value; // r10
  idVehicle_Car *v7; // r3
  int v8; // r27
  int i; // r28
  int v10; // r10
  idVehicle_Car *v11; // r3
  idVehicle_Car *v12; // r3
  idPresentable *presentable; // r3
  int v14; // r3
  int v15; // r10
  idVehicle_Car *v16; // r3
  idVehicle_Car *v17; // r3
  idPresentable *v18; // r3
  int v19; // r3
  idVehicleWeapon *v20; // r31
  int v21; // r10
  idVehicle_Car *v22; // r3
  idVehicle_Car *v23; // r3
  idPresentable *v24; // r3
  idPresentableVehicle *v25; // r3
  int CurrentWeaponGroup; // r25

  enemyTracker = this->enemyTracker;
  LOBYTE(v3) = 1;
  if ( enemyTracker != nullptr )
    Owner = (idActor *)idNavPathPosTracker::GetOwner(this: enemyTracker);
  else
    Owner = nullptr;
  v5 = idActor::CastTo(c: Owner);
  if ( v5 != nullptr )
    v3 = v5->GetVehicle_2(this: v5) != nullptr;
  value = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v7 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v7 != nullptr && idVehicle_Car::CastTo(c: v7) != nullptr )
    {
      v8 = 0;
      for ( i = 0; ; i += 4 )
      {
        while ( 1 )
        {
          v10 = this->vehicleCar.spawnId.value;
          if ( gameLocal->spawnIds.ptr[v10 & 0x1FFF] == v10 >> 13
            && (v11 = (idVehicle_Car *)gameLocal->entities.ptr[v10 & 0x1FFF]) != nullptr )
          {
            v12 = idVehicle_Car::CastTo(c: v11);
          }
          else
          {
            v12 = nullptr;
          }
          presentable = v12->presentable;
          if ( presentable != nullptr )
            v14 = (int)presentable->GetVehicleInterface(this: presentable);
          else
            v14 = 0;
          if ( v8 >= *(_DWORD *)(v14 + 18748) )
            return;
          v15 = this->vehicleCar.spawnId.value;
          if ( gameLocal->spawnIds.ptr[v15 & 0x1FFF] == v15 >> 13
            && (v16 = (idVehicle_Car *)gameLocal->entities.ptr[v15 & 0x1FFF]) != nullptr )
          {
            v17 = idVehicle_Car::CastTo(c: v16);
          }
          else
          {
            v17 = nullptr;
          }
          v18 = v17->presentable;
          v19 = v18 != nullptr ? (int)v18->GetVehicleInterface(this: v18) : 0;
          v20 = *(idVehicleWeapon **)(*(_DWORD *)(v19 + 18744) + i);
          if ( v20 != nullptr )
          {
            v21 = this->vehicleCar.spawnId.value;
            if ( gameLocal->spawnIds.ptr[v21 & 0x1FFF] == v21 >> 13
              && (v22 = (idVehicle_Car *)gameLocal->entities.ptr[v21 & 0x1FFF]) != nullptr )
            {
              v23 = idVehicle_Car::CastTo(c: v22);
            }
            else
            {
              v23 = nullptr;
            }
            v24 = v23->presentable;
            v25 = v24 != nullptr ? v24->GetVehicleInterface(this: v24) : nullptr;
            CurrentWeaponGroup = idPresentableVehicle::GetCurrentWeaponGroup(this: v25);
            if ( idVehicleWeapon::GetDeclVehicleWeapon(this: v20)->weaponSlot == CurrentWeaponGroup )
              break;
          }
LABEL_38:
          ++v8;
          i += 4;
        }
        if ( v3 || idVehicleWeapon::GetDeclVehicleWeapon(this: v20)->canAttackActors )
        {
          idVehicleWeapon::PullTrigger(this: v20);
          goto LABEL_38;
        }
        idVehicleWeapon::ReleaseTrigger(this: v20);
        ++v8;
      }
    }
  }
}


// ========================================================================
// ?UpdateWeaponsHaveClearShot@idVehicleAI@@IAAXXZ
// EA  : 0x82B0BF28
// RVA : 0x00B0BF28
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::UpdateWeaponsHaveClearShot(idVehicleAI *this)
{
  idNavPathPosTracker *enemyTracker; // r3
  idEntity *Owner; // r26
  int v4; // r27
  int i; // r28
  int value; // r9
  idGameLocal *v7; // r11
  idVehicle_Car *v8; // r3
  idVehicle_Car *v9; // r3
  idPresentable *presentable; // r3
  int v11; // r3
  int v12; // r9
  idVehicle_Car *v13; // r3
  idVehicle_Car *v14; // r3
  idPresentable *v15; // r3
  int v16; // r3
  int v17; // r9
  idVehicleWeapon *v18; // r31
  idVehicle_Car *v19; // r3
  idVehicle_Car *v20; // r3
  idPresentable *v21; // r3
  idPresentableVehicle *v22; // r3
  int CurrentWeaponGroup; // r25
  idPhysics *Physics; // r3
  int v25; // r3

  enemyTracker = this->enemyTracker;
  if ( enemyTracker != nullptr )
  {
    Owner = idNavPathPosTracker::GetOwner(this: enemyTracker);
    if ( Owner != nullptr )
    {
      v4 = 0;
      for ( i = 0; ; i += 4 )
      {
        value = this->vehicleCar.spawnId.value;
        v7 = gameLocal;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
          && (v8 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
        {
          v9 = idVehicle_Car::CastTo(c: v8);
          v7 = gameLocal;
        }
        else
        {
          v9 = nullptr;
        }
        presentable = v9->presentable;
        if ( presentable != nullptr )
        {
          v11 = (int)presentable->GetVehicleInterface(this: presentable);
          v7 = gameLocal;
        }
        else
        {
          v11 = 0;
        }
        if ( v4 >= *(_DWORD *)(v11 + 18748) )
          break;
        v12 = this->vehicleCar.spawnId.value;
        if ( v7->spawnIds.ptr[v12 & 0x1FFF] == v12 >> 13
          && (v13 = (idVehicle_Car *)v7->entities.ptr[v12 & 0x1FFF]) != nullptr )
        {
          v14 = idVehicle_Car::CastTo(c: v13);
          v7 = gameLocal;
        }
        else
        {
          v14 = nullptr;
        }
        v15 = v14->presentable;
        if ( v15 != nullptr )
        {
          v16 = (int)v15->GetVehicleInterface(this: v15);
          v7 = gameLocal;
        }
        else
        {
          v16 = 0;
        }
        v17 = this->vehicleCar.spawnId.value;
        v18 = *(idVehicleWeapon **)(*(_DWORD *)(v16 + 18744) + i);
        if ( v7->spawnIds.ptr[v17 & 0x1FFF] == v17 >> 13
          && (v19 = (idVehicle_Car *)v7->entities.ptr[v17 & 0x1FFF]) != nullptr )
        {
          v20 = idVehicle_Car::CastTo(c: v19);
        }
        else
        {
          v20 = nullptr;
        }
        v21 = v20->presentable;
        if ( v21 != nullptr )
          v22 = v21->GetVehicleInterface(this: v21);
        else
          v22 = nullptr;
        CurrentWeaponGroup = idPresentableVehicle::GetCurrentWeaponGroup(this: v22);
        if ( idVehicleWeapon::GetWeaponSlot(this: v18) == CurrentWeaponGroup )
        {
          Physics = idEntity::GetPhysics(this: Owner);
          v25 = (int)Physics->GetOrigin(this: Physics, a2: 0);
          idVehicleWeapon::TestClearShot(this: *(idVehicleWeapon **)v25, endpos: *(idVec3 **)(v25 + 4));
        }
        ++v4;
      }
    }
  }
}


// ========================================================================
// ?UpdateWeapons@idVehicleAI@@IAAXXZ
// EA  : 0x82B0C118
// RVA : 0x00B0C118
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::UpdateWeapons(idVehicleAI *this)
{
  int value; // r10
  idVehicle_Car *v3; // r3
  idVehicle_Car *v4; // r3
  idEntity *v5; // r27
  idPresentable *presentable; // r17
  float *v7; // r19
  int v8; // r23
  int i; // r22
  idPresentable *v10; // r3
  int v11; // r3
  idPresentable *v12; // r3
  int v13; // r3
  int v14; // r11
  idPresentable *v15; // r3
  idVehicleWeapon *v16; // r30
  idPresentableVehicle *v17; // r3
  int CurrentWeaponGroup; // r31
  int v19; // r9
  idEntity *v20; // r3
  idVehicle_Car *v21; // r28
  bool v22; // r31
  idVehicle_Car *v23; // r3
  idEntity *v24; // r3
  idPhysics *Physics; // r3
  float *v26; // r3
  double v27; // fp9
  double v28; // fp13
  double v29; // fp6
  double v30; // fp3
  double v32; // fp1
  double v34; // fp13
  double v35; // fp31
  idPhysics *v36; // r3
  idAngles *v37; // r3
  idAngles *v38; // r31
  idAngles *v39; // r3
  double v40; // fp10
  idPlayer *v41; // r3
  idPlayer *v42; // r31
  bool hasClearShot; // r31
  const idDeclProjectile *projectileDecl; // r11
  float roll; // r9
  float pitch; // r11
  const idDeclVehicleWeapon *DeclVehicleWeapon; // r3
  double v48; // fp8
  double v49; // fp7
  double v50; // fp6
  double v51; // fp5
  double v52; // fp4
  double v53; // fp3
  idPhysics *v54; // r3
  idAngles *v55; // r3
  idAngles *v56; // r3
  double v57; // fp6
  double v58; // fp4
  idVec3 *v59; // r3
  double v60; // fp13
  double v61; // fp12
  double v62; // fp31
  idPresentable *v63; // r31
  double Difficulty_DamageScale; // fp1
  bool v65; // r8
  bool v66; // r7
  float v67; // [sp+8h] [-228h]
  float v68; // [sp+Ch] [-224h]
  float v69; // [sp+10h] [-220h]
  float v70; // [sp+14h] [-21Ch]
  float v71; // [sp+18h] [-218h]
  float v72; // [sp+1Ch] [-214h]
  float v73; // [sp+20h] [-210h]
  float v74; // [sp+24h] [-20Ch]
  float v75; // [sp+28h] [-208h]
  float v76; // [sp+2Ch] [-204h]
  float v77; // [sp+30h] [-200h]
  float v78; // [sp+34h] [-1FCh]
  float v79; // [sp+38h] [-1F8h]
  float v80; // [sp+3Ch] [-1F4h]
  float v81; // [sp+40h] [-1F0h]
  float v82; // [sp+44h] [-1ECh]
  float v83; // [sp+48h] [-1E8h]
  float v84; // [sp+4Ch] [-1E4h]
  float v85; // [sp+50h] [-1E0h]
  float v86; // [sp+54h] [-1DCh]
  idAngles v87; // [sp+70h] [-1C0h] BYREF
  idVec3 v88; // [sp+80h] [-1B0h] BYREF
  float v89; // [sp+90h] [-1A0h]
  float v90; // [sp+94h] [-19Ch]
  float v91; // [sp+98h] [-198h]
  float v92; // [sp+A0h] [-190h]
  float yaw; // [sp+A4h] [-18Ch]
  float v94; // [sp+A8h] [-188h]
  idAngles v95; // [sp+B0h] [-180h] BYREF
  idVec3 v96; // [sp+C0h] [-170h] BYREF
  idAngles v97; // [sp+D0h] [-160h] BYREF
  idAngles v98; // [sp+E0h] [-150h] BYREF
  idVec3 v99; // [sp+F0h] [-140h] BYREF
  idMat3 v100; // [sp+100h] [-130h] BYREF
  idVec3 v101; // [sp+130h] [-100h] BYREF
  idMat3 v102[3]; // [sp+140h] [-F0h] BYREF

  value = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v3 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v3 != nullptr )
    {
      v4 = idVehicle_Car::CastTo(c: v3);
      v5 = v4;
      if ( v4 != nullptr )
      {
        if ( v4->presentable != nullptr )
        {
          presentable = v4->presentable;
        }
        else
        {
          idEntity::InitPresentableInternal(this: v4);
          presentable = v5->presentable;
        }
        v7 = (float *)((char *)&v5[19].defaultPhysicsObj + 68);
        v8 = 0;
        for ( i = 0; ; i += 4 )
        {
          v10 = v5->presentable;
          v11 = v10 != nullptr ? (int)v10->GetVehicleInterface(this: v10) : 0;
          if ( v8 >= *(_DWORD *)(v11 + 18748) )
            break;
          v12 = v5->presentable;
          if ( v12 != nullptr )
            v13 = (int)v12->GetVehicleInterface(this: v12);
          else
            v13 = 0;
          v14 = *(_DWORD *)(v13 + 18744);
          v15 = v5->presentable;
          v16 = *(idVehicleWeapon **)(v14 + i);
          if ( v15 != nullptr )
            v17 = v15->GetVehicleInterface(this: v15);
          else
            v17 = nullptr;
          CurrentWeaponGroup = idPresentableVehicle::GetCurrentWeaponGroup(this: v17);
          if ( idVehicleWeapon::GetWeaponSlot(this: v16) == CurrentWeaponGroup )
          {
            v19 = this->target.spawnId.value;
            if ( gameLocal->spawnIds.ptr[v19 & 0x1FFF] == v19 >> 13
              && (v20 = gameLocal->entities.ptr[v19 & 0x1FFF]) != nullptr )
            {
              v21 = (idVehicle_Car *)idEntity::CastTo(c: v20);
            }
            else
            {
              v21 = nullptr;
            }
            v22 = true;
            v23 = idVehicle_Car::CastTo(c: v21);
            if ( v23 != nullptr )
              v22 = ((double (__fastcall *)(idVehicle_Car *))v23->GetHealth)(a1: v23) > 0.0;
            if ( gameLocal->spawnIds.ptr[this->target.spawnId.value & 0x1FFF] == this->target.spawnId.value >> 13
              && v22
              && idVehicleWeapon::HasAmmo(this: v16) )
            {
              idVehicleWeapon::GetMuzzlePosition(
                this: v16,
                origin: &v96,
                axis: v102,
                attackType: v16->weapon->attackType);
              v24 = idEntityPtr<idEntity const>::operator->(this: &this->target);
              Physics = idEntity::GetPhysics(this: v24);
              v26 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
              v27 = (float)(v26[1] - v96.y);
              v28 = (float)(*v26 - v96.x);
              v29 = (float)(v26[2] - v96.z);
              v98.pitch = *v26 - v96.x;
              v98.yaw = v27;
              v98.roll = v29;
              v30 = (float)((float)((float)v29 * (float)v29)
                          + (float)((float)((float)v28 * (float)v28) + (float)((float)v27 * (float)v27)));
              _FP2 = (float)((float)((float)((float)v29 * (float)v29)
                                   + (float)((float)((float)v28 * (float)v28) + (float)((float)v27 * (float)v27)))
                           - idMath::FLT_SMALLEST_NON_DENORMAL);
              v32 = (float)((float)((float)((float)v29 * (float)v29)
                                  + (float)((float)((float)v28 * (float)v28) + (float)((float)v27 * (float)v27)))
                          * (float)0.5);
              __asm { fsel      f0, f2, f3, f0 }
              v34 = __frsqrte(_FP0);
              v35 = (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v34 * (float)v32) * (float)v34) - (float)1.5) * (float)v34) * (float)v32)
                                                                                                  * (float)((float)-(float)((float)((float)((float)v34 * (float)v32) * (float)v34) - (float)1.5) * (float)v34))
                                                                                          - (float)1.5)
                                                                          * (float)((float)-(float)((float)((float)((float)v34 * (float)v32) * (float)v34)
                                                                                                  - (float)1.5)
                                                                                  * (float)v34))
                                                                  * (float)v32)
                                                          * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v34 * (float)v32) * (float)v34) - (float)1.5) * (float)v34)
                                                                                                  * (float)v32)
                                                                                          * (float)((float)-(float)((float)((float)((float)v34 * (float)v32) * (float)v34) - (float)1.5)
                                                                                                  * (float)v34))
                                                                                  - (float)1.5)
                                                                  * (float)((float)-(float)((float)((float)((float)v34 * (float)v32)
                                                                                                  * (float)v34)
                                                                                          - (float)1.5)
                                                                          * (float)v34)))
                                                  - (float)1.5)
                                  * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v34 * (float)v32) * (float)v34)
                                                                                                  - (float)1.5)
                                                                                  * (float)v34)
                                                                          * (float)v32)
                                                                  * (float)((float)-(float)((float)((float)((float)v34 * (float)v32)
                                                                                                  * (float)v34)
                                                                                          - (float)1.5)
                                                                          * (float)v34))
                                                          - (float)1.5)
                                          * (float)((float)-(float)((float)((float)((float)v34 * (float)v32) * (float)v34)
                                                                  - (float)1.5)
                                                  * (float)v34)))
                          * (float)v30);
              v36 = idEntity::GetPhysics(this: v5);
              v37 = (idAngles *)v36->GetAxis(this: v36, a2: 0);
              v38 = idMat3::ToAngles(this: &v100, result: v37);
              v39 = idVec3::ToAngles(this: &v101, result: &v98);
              v40 = (float)(v39->yaw - v38->yaw);
              v87.pitch = v39->pitch - v38->pitch;
              v87.roll = 0.0;
              v87.yaw = v40;
              idAngles::Normalize180(this: &v87);
              v41 = idPlayer::CastTo(c: (idPlayer *)v21);
              v42 = v41;
              if ( v41 != nullptr )
              {
                idEntity::GetBindMaster(this: v41);
                if ( v42->GetVehicle_2(this: v42) != nullptr )
                  v21 = (idVehicle_Car *)v42->GetVehicle_2(this: v42);
              }
            }
            else
            {
              v35 = 500.0;
              v87.pitch = ang_zero.pitch;
              v87.yaw = ang_zero.yaw;
              v87.roll = ang_zero.roll;
            }
            idVehicleWeapon::GetAiAngleLimits(this: v16, minAngles: &v97, maxAngles: &v95);
            hasClearShot = v16->hasClearShot;
            if ( (float)(v87.yaw - (float)15.0) > (double)v95.yaw || (float)(v87.yaw + (float)15.0) < (double)v97.yaw )
            {
              v87.pitch = ang_zero.pitch;
              v87.yaw = ang_zero.yaw;
              v87.roll = ang_zero.roll;
              if ( idVehicleWeapon::GetDeclVehicleWeapon(this: v16)->initialAmmoDecl != nullptr )
              {
                projectileDecl = idVehicleWeapon::GetDeclVehicleWeapon(this: v16)->initialAmmoDecl->projectileDecl;
                if ( projectileDecl != nullptr
                  && (projectileDecl->hitscan
                   || projectileDecl->hitscan_till_solid
                   || projectileDecl->hitscan_through_vehicles) )
                {
                  hasClearShot = false;
                }
              }
            }
            roll = v16->targetAngles.roll;
            pitch = v16->targetAngles.pitch;
            yaw = v16->targetAngles.yaw;
            v94 = roll;
            v92 = pitch;
            v89 = pitch;
            v91 = roll;
            v90 = yaw;
            DeclVehicleWeapon = idVehicleWeapon::GetDeclVehicleWeapon(this: v16);
            idVehicleAI::AngleTowardsGoal(
              this,
              current: (idAngles *)LODWORD(v87.pitch),
              goal: (idAngles *)LODWORD(v87.yaw),
              moveScale: 0.75,
              minAngles: (idAngles *)__ROL4__(LODWORD(v87.roll), 32),
              maxAngles: (idAngles *)LODWORD(v97.pitch),
              rotateSpeed: DeclVehicleWeapon->rotateSpeed,
              a8: SLODWORD(v97.yaw),
              a9: v53,
              a10: v52,
              a11: v51,
              a12: v50,
              a13: v49,
              a14: v48,
              a15: SLODWORD(v95.pitch),
              a16: SLODWORD(v95.yaw),
              a17: v67,
              a18: v68,
              a19: v69,
              a20: v70,
              a21: v71,
              a22: v72,
              a23: v73,
              a24: v74,
              a25: v75,
              a26: v76,
              a27: v77,
              a28: v78,
              a29: v79,
              a30: v80,
              a31: v81,
              a32: v82,
              a33: v83,
              a34: v84,
              a35: v85,
              a36: v86,
              a37: v97.pitch);
            v54 = idEntity::GetPhysics(this: v5);
            v55 = (idAngles *)v54->GetAxis(this: v54, a2: 0);
            v56 = idMat3::ToAngles(this: (idMat3 *)&v100.mat[1].y, result: v55);
            v57 = (float)(v56->roll + v91);
            v58 = (float)(v56->yaw + v90);
            v99.x = v56->pitch + v89;
            v99.z = v57;
            v99.y = v58;
            idVehicleWeapon::GetOrigin(this: v16, origin: &v88);
            v88.x = v88.x + vec3_up.x;
            v88.z = v88.z + vec3_up.z;
            v88.y = v88.y + vec3_up.y;
            v59 = idAngles::ToForward(this: (idAngles *)&v100.mat[2].z, result: &v99);
            v60 = (float)((float)(v59->y * (float)v35) + v88.y);
            v61 = (float)((float)(v59->z * (float)v35) + v88.z);
            if ( v8 < 8 )
            {
              *(v7 - 2) = (float)((float)v35 * v59->x) + v88.x;
              *(v7 - 1) = v60;
              *v7 = v61;
            }
            if ( hasClearShot )
            {
              v62 = (float)((float)((float)1.0 - idVehicleAI::GetDifficulty_Accuracy(this)) * (float)8.0);
              if ( v21 != nullptr )
              {
                v63 = v21->presentable;
                if ( v63 == nullptr )
                {
                  idEntity::InitPresentableInternal(this: v21);
                  v63 = v21->presentable;
                }
              }
              else
              {
                v63 = nullptr;
              }
              Difficulty_DamageScale = idVehicleAI::GetDifficulty_DamageScale(this);
              LOBYTE(v86) = 0;
              idVehicleWeapon::Fire(
                this: v16,
                attacker: presentable,
                lockedOn: true,
                target: v63,
                damageScale: Difficulty_DamageScale,
                addSpread: v62,
                infiniteAmmo: v66,
                beingRemoteFired: v65,
                skipClientFireRecord: false);
            }
          }
          ++v8;
          v7 += 3;
        }
      }
    }
  }
}


// ========================================================================
// ?SetDifficultyData@idVehicleAI@@QAAXAAUdifficultyLevel_t@vehicleAiSetup_t@@@Z
// EA  : 0x82B0C770
// RVA : 0x00B0C770
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::SetDifficultyData(idVehicleAI *this, vehicleAiSetup_t::difficultyLevel_t *difficultyLevel)
{
  vehicleAiSetup_t::difficultyLevel_t::difficulty_t level; // r11
  char v4; // r10
  int value; // r10
  idVehicle_Car *v6; // r3
  int v7; // r9
  idVehicle_Car *v8; // r3
  idVehicle_Car *v9; // r30

  level = difficultyLevel->level;
  if ( difficultyLevel->level < DIFFICULTY_LOW || (v4 = 1, level >= (DIFFICULTY_HIGH|DIFFICULTY_MED)) )
    v4 = 0;
  if ( v4 != 0 )
  {
    if ( difficultyLevel->attackScale == -1.0 )
      this->setup.difficultyLevel.attackScale = vaiDifficultySetting[level].attackScale;
    if ( difficultyLevel->damageScale == -1.0 )
      this->setup.difficultyLevel.damageScale = vaiDifficultySetting[level].damageScale;
    if ( difficultyLevel->speedRate == -1.0 )
      this->setup.difficultyLevel.speedRate = vaiDifficultySetting[level].speedRate;
    if ( difficultyLevel->accuracy == -1.0 )
      this->setup.difficultyLevel.accuracy = vaiDifficultySetting[level].accuracy;
    if ( difficultyLevel->damageTakenScale == -1.0 )
      this->setup.difficultyLevel.damageTakenScale = vaiDifficultySetting[level].damageTakenScale;
  }
  value = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v6 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v6 != nullptr && idVehicle_Car::CastTo(c: v6) != nullptr )
    {
      v7 = this->vehicleCar.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v7 & 0x1FFF] == v7 >> 13
        && (v8 = (idVehicle_Car *)gameLocal->entities.ptr[v7 & 0x1FFF]) != nullptr )
      {
        v9 = idVehicle_Car::CastTo(c: v8);
      }
      else
      {
        v9 = nullptr;
      }
      v9->overallDamageScale = idVehicleAI::GetDifficulty_DamageTakenScale(this);
    }
  }
}


// ========================================================================
// ?GetTargetAngles@idVehicleAI@@QAA?AVidAngles@@XZ
// EA  : 0x82B0C928
// RVA : 0x00B0C928
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

idVehicleAI *__fastcall idVehicleAI::GetTargetAngles(idVehicleAI *this, idAngles *result)
{
  float pitch; // r10
  idVehicle_Car *v5; // r3
  float v6; // r9
  float yaw; // r8
  float roll; // r7
  float v9; // r9
  idVehicle_Car *v10; // r3
  idVehicle_Car *v11; // r3
  idPhysics *Physics; // r31
  idEntity *Owner; // r3
  idPhysics *v14; // r27
  float *v15; // r31
  float *v16; // r3
  double v17; // fp9
  double v18; // fp7
  float v19; // r6
  idVehicle_Car *v20; // r3
  idVehicle_Car *v21; // r3
  idPhysics *v22; // r3
  idAngles *v23; // r3
  idAngles v25; // [sp+50h] [-70h] BYREF
  idAngles v26; // [sp+60h] [-60h] BYREF
  idVec3 v27; // [sp+70h] [-50h] BYREF
  idVec3 v28; // [sp+80h] [-40h] BYREF

  pitch = result[129].pitch;
  if ( gameLocal->spawnIds.ptr[LOWORD(pitch) & 0x1FFF] == SLODWORD(pitch) >> 13
    && (v5 = (idVehicle_Car *)gameLocal->entities.ptr[LOWORD(pitch) & 0x1FFF]) != nullptr
    && idVehicle_Car::CastTo(c: v5) != nullptr )
  {
    v9 = result[129].pitch;
    if ( gameLocal->spawnIds.ptr[LOWORD(v9) & 0x1FFF] == SLODWORD(v9) >> 13
      && (v10 = (idVehicle_Car *)gameLocal->entities.ptr[LOWORD(v9) & 0x1FFF]) != nullptr )
    {
      v11 = idVehicle_Car::CastTo(c: v10);
    }
    else
    {
      v11 = nullptr;
    }
    Physics = idEntity::GetPhysics(this: v11);
    if ( LODWORD(result[109].pitch) != 0 )
      Owner = idNavPathPosTracker::GetOwner(this: (idNavPathPosTracker *)LODWORD(result[109].pitch));
    else
      Owner = nullptr;
    v14 = idEntity::GetPhysics(this: Owner);
    v15 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v16 = (float *)v14->GetOrigin(this: v14, a2: 0);
    v17 = (float)(v16[2] - v15[2]);
    v18 = (float)(v16[1] - v15[1]);
    v26.pitch = *v16 - *v15;
    v26.roll = v17;
    v26.yaw = v18;
    idVec3::ToAngles(this: &v27, result: &v26);
    v19 = result[129].pitch;
    if ( gameLocal->spawnIds.ptr[LOWORD(v19) & 0x1FFF] == SLODWORD(v19) >> 13
      && (v20 = (idVehicle_Car *)gameLocal->entities.ptr[LOWORD(v19) & 0x1FFF]) != nullptr )
    {
      v21 = idVehicle_Car::CastTo(c: v20);
    }
    else
    {
      v21 = nullptr;
    }
    v22 = idEntity::GetPhysics(this: v21);
    v23 = (idAngles *)v22->GetAxis(this: v22, a2: 0);
    idVec3::ToAngles(this: &v28, result: v23);
    v25.pitch = v27.x - v28.x;
    v25.yaw = v27.y - v28.y;
    v25.roll = v27.z - v28.z;
    idAngles::Normalize180(this: &v25);
    v6 = v25.pitch;
    yaw = v25.yaw;
    roll = v25.roll;
  }
  else
  {
    v6 = ang_zero.pitch;
    yaw = ang_zero.yaw;
    roll = ang_zero.roll;
  }
  *(float *)&this->listeningToList = roll;
  *(float *)&this->listenerList = yaw;
  *(float *)&this->__vftable = v6;
  return this;
}


// ========================================================================
// ?GetWeaponAngles@idVehicleAI@@QAA?AVidAngles@@XZ
// EA  : 0x82B0CB48
// RVA : 0x00B0CB48
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

idVehicleAI *__fastcall idVehicleAI::GetWeaponAngles(idVehicleAI *this, idAngles *result)
{
  float pitch; // r10
  idVehicle_Car *v5; // r3
  int v6; // r27
  int i; // r28
  float v8; // r9
  idGameLocal *v9; // r11
  idVehicle_Car *v10; // r3
  idVehicle_Car *v11; // r3
  idPresentable *presentable; // r3
  int v13; // r3
  float v14; // r9
  idVehicle_Car *v15; // r3
  idVehicle_Car *v16; // r3
  idPresentable *v17; // r3
  int v18; // r3
  float v19; // r9
  int v20; // r31
  idVehicle_Car *v21; // r3
  idVehicle_Car *v22; // r3
  idPresentable *v23; // r3
  idPresentableVehicle *v24; // r3
  int CurrentWeaponGroup; // r25
  idList<idEventReceiver *,5> *v27; // r10
  idList<idEventReceiver *,5> *v28; // r9
  float roll; // r7
  float yaw; // r8

  pitch = result[129].pitch;
  if ( gameLocal->spawnIds.ptr[LOWORD(pitch) & 0x1FFF] == SLODWORD(pitch) >> 13 )
  {
    v5 = (idVehicle_Car *)gameLocal->entities.ptr[LOWORD(pitch) & 0x1FFF];
    if ( v5 != nullptr && idVehicle_Car::CastTo(c: v5) != nullptr )
    {
      v6 = 0;
      for ( i = 0; ; i += 4 )
      {
        v8 = result[129].pitch;
        v9 = gameLocal;
        if ( gameLocal->spawnIds.ptr[LOWORD(v8) & 0x1FFF] == SLODWORD(v8) >> 13
          && (v10 = (idVehicle_Car *)gameLocal->entities.ptr[LOWORD(v8) & 0x1FFF]) != nullptr )
        {
          v11 = idVehicle_Car::CastTo(c: v10);
          v9 = gameLocal;
        }
        else
        {
          v11 = nullptr;
        }
        presentable = v11->presentable;
        if ( presentable != nullptr )
        {
          v13 = (int)presentable->GetVehicleInterface(this: presentable);
          v9 = gameLocal;
        }
        else
        {
          v13 = 0;
        }
        if ( v6 >= *(_DWORD *)(v13 + 18748) )
          break;
        v14 = result[129].pitch;
        if ( v9->spawnIds.ptr[LOWORD(v14) & 0x1FFF] == SLODWORD(v14) >> 13
          && (v15 = (idVehicle_Car *)v9->entities.ptr[LOWORD(v14) & 0x1FFF]) != nullptr )
        {
          v16 = idVehicle_Car::CastTo(c: v15);
          v9 = gameLocal;
        }
        else
        {
          v16 = nullptr;
        }
        v17 = v16->presentable;
        if ( v17 != nullptr )
        {
          v18 = (int)v17->GetVehicleInterface(this: v17);
          v9 = gameLocal;
        }
        else
        {
          v18 = 0;
        }
        v19 = result[129].pitch;
        v20 = *(_DWORD *)(*(_DWORD *)(v18 + 18744) + i);
        if ( v9->spawnIds.ptr[LOWORD(v19) & 0x1FFF] == SLODWORD(v19) >> 13
          && (v21 = (idVehicle_Car *)v9->entities.ptr[LOWORD(v19) & 0x1FFF]) != nullptr )
        {
          v22 = idVehicle_Car::CastTo(c: v21);
        }
        else
        {
          v22 = nullptr;
        }
        v23 = v22->presentable;
        if ( v23 != nullptr )
          v24 = v23->GetVehicleInterface(this: v23);
        else
          v24 = nullptr;
        CurrentWeaponGroup = idPresentableVehicle::GetCurrentWeaponGroup(this: v24);
        if ( idVehicleWeapon::GetWeaponSlot(this: (idVehicleWeapon *)v20) == CurrentWeaponGroup )
        {
          v27 = *(idList<idEventReceiver *,5> **)(v20 + 240);
          v28 = *(idList<idEventReceiver *,5> **)(v20 + 244);
          this->__vftable = *(idVehicleAI_vtbl **)(v20 + 236);
          this->listenerList = v27;
          this->listeningToList = v28;
          return this;
        }
        ++v6;
      }
    }
  }
  roll = ang_zero.roll;
  yaw = ang_zero.yaw;
  this->__vftable = (idVehicleAI_vtbl *)LODWORD(ang_zero.pitch);
  *(float *)&this->listeningToList = roll;
  *(float *)&this->listenerList = yaw;
  return this;
}


// ========================================================================
// ?DetermineWheelForce@idVehicleAI@@QAAMXZ
// EA  : 0x82B0CD80
// RVA : 0x00B0CD80
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

float __fastcall idVehicleAI::DetermineWheelForce(idVehicleAI *this)
{
  int value; // r10
  idVehicle_Car *v3; // r3
  bool v4; // r4
  double v5; // fp1
  idGameLocal *v6; // r11
  int v7; // r9
  idVehicle_Car *v8; // r3
  idVehicle_Car *v9; // r3
  double wheelForceScale; // fp31
  int v11; // r9
  idVehicle_Car *v12; // r3
  idVehicle_Car *v13; // r3
  const idDeclTable *motorTorque; // r11
  double v15; // fp1
  double v16; // fp1

  value = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v3 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && idVehicle_Car::CastTo(c: v3) != nullptr )
  {
    v6 = gameLocal;
    if ( vai_wf_scale.valueFloat == 0.0 )
    {
      v7 = this->vehicleCar.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v7 & 0x1FFF] == v7 >> 13
        && (v8 = (idVehicle_Car *)gameLocal->entities.ptr[v7 & 0x1FFF]) != nullptr )
      {
        v9 = idVehicle_Car::CastTo(c: v8);
        v6 = gameLocal;
        wheelForceScale = v9->aiProperties.wheelForceScale;
      }
      else
      {
        wheelForceScale = MEMORY[0x4164];
      }
    }
    else
    {
      wheelForceScale = vai_wf_scale.valueFloat;
    }
    v11 = this->vehicleCar.spawnId.value;
    if ( v6->spawnIds.ptr[v11 & 0x1FFF] == v11 >> 13
      && (v12 = (idVehicle_Car *)v6->entities.ptr[v11 & 0x1FFF]) != nullptr )
    {
      v13 = idVehicle_Car::CastTo(c: v12);
    }
    else
    {
      v13 = nullptr;
    }
    motorTorque = v13->aiProperties.motorTorque;
    v15 = (float)((float)__fabs(this->actualSpeed) / v13->aiProperties.maxSpeed);
    if ( motorTorque != nullptr )
      v16 = idLookupTable::TableLookup(this: motorTorque->table, time: v15, fastSearch: v4);
    else
      v16 = (float)((float)-(float)((float)((float)v15 * (float)v15) - (float)1.0) * v13->aiProperties.maxSpeed);
    v5 = (float)((float)((float)v16 * (float)wheelForceScale) * (float)1000.0);
  }
  else
  {
    v5 = 0.0;
  }
  return *((float *)&v5 + 1);
}


// ========================================================================
// ?GetMaxSpeed@idVehicleAI@@QAAMXZ
// EA  : 0x82B0CF10
// RVA : 0x00B0CF10
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

float __fastcall idVehicleAI::GetMaxSpeed(idVehicleAI *this)
{
  int value; // r10
  idVehicle_Car *v3; // r3
  double maxSpeed; // fp1
  int v5; // r9
  idVehicle_Car *v6; // r3
  idVehicle_Car *v7; // r3

  value = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v3 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && idVehicle_Car::CastTo(c: v3) != nullptr )
  {
    v5 = this->vehicleCar.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v5 & 0x1FFF] == v5 >> 13
      && (v6 = (idVehicle_Car *)gameLocal->entities.ptr[v5 & 0x1FFF]) != nullptr )
    {
      v7 = idVehicle_Car::CastTo(c: v6);
    }
    else
    {
      v7 = nullptr;
    }
    maxSpeed = v7->aiProperties.maxSpeed;
  }
  else
  {
    maxSpeed = 0.0099999998;
  }
  return *((float *)&maxSpeed + 1);
}


// ========================================================================
// ?IsBeingAttacked@idVehicleAI@@QAA_NHH@Z
// EA  : 0x82B0CFE0
// RVA : 0x00B0CFE0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

BOOL __fastcall idVehicleAI::IsBeingAttacked(idVehicleAI *this, int lastAttackedTime, int aggressiveTime)
{
  int value; // r10
  idVehicle_Car *v7; // r3
  int v9; // r9
  idGameLocal *v10; // r11
  idVehicle_Car *v11; // r3
  idVehicle_Car *v12; // r3

  value = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return false;
  v7 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
  if ( v7 == nullptr || idVehicle_Car::CastTo(c: v7) == nullptr )
    return false;
  v9 = this->vehicleCar.spawnId.value;
  v10 = gameLocal;
  if ( gameLocal->spawnIds.ptr[v9 & 0x1FFF] == v9 >> 13
    && (v11 = (idVehicle_Car *)gameLocal->entities.ptr[v9 & 0x1FFF]) != nullptr )
  {
    v12 = idVehicle_Car::CastTo(c: v11);
    v10 = gameLocal;
  }
  else
  {
    v12 = nullptr;
  }
  if ( v10->spawnIds.ptr[v12->lastDamage.attacker.spawnId.value & 0x1FFF] == v12->lastDamage.attacker.spawnId.value >> 13 )
  {
    if ( v12->lastDamage.time > v10->GetGameMs(this: v10, a2: GAMETIME_SCALED) - lastAttackedTime )
      idVehicleAI::SetBeingAttackedTime(this, msecs: aggressiveTime);
    v10 = gameLocal;
  }
  return this->beingAttackedTime >= v10->GetGameMs(this: v10, a2: GAMETIME_SCALED);
}


// ========================================================================
// ?SetAttackState@idVehicleAI@@QAAXHH_N@Z
// EA  : 0x82B0D128
// RVA : 0x00B0D128
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::SetAttackState(idVehicleAI *this, int num, int delayTime, bool pushState)
{
  idState *State; // r3
  const idTypeInfo *v8; // r3

  State = idFiniteStateMachine::FindState(this: &this->attackFSM, name: vehicleAttackStateNames[num]);
  v8 = (const idTypeInfo *)State->GetType(this: State);
  idVehicleAI::SetAttackState(this, stateType: v8, delayTime, pushState);
}


// ========================================================================
// ?StopFiringWeapon@idVehicleAI@@QAAXXZ
// EA  : 0x82B0D188
// RVA : 0x00B0D188
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::StopFiringWeapon(idVehicleAI *this)
{
  int value; // r9
  idVehicle_Car *v3; // r3
  int v4; // r28
  int i; // r29
  int v6; // r10
  idVehicle_Car *v7; // r3
  idVehicle_Car *v8; // r3
  idPresentable *presentable; // r3
  int v10; // r3
  int v11; // r10
  idVehicle_Car *v12; // r3
  idVehicle_Car *v13; // r3
  idPresentable *v14; // r3
  int v15; // r3
  idVehicleWeapon *v16; // r3

  idStr::operator=(this: &this->debugFireInfo, text: &byte_8200D768);
  value = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v3 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v3 != nullptr && idVehicle_Car::CastTo(c: v3) != nullptr )
    {
      v4 = 0;
      for ( i = 0; ; i += 4 )
      {
        v6 = this->vehicleCar.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v6 & 0x1FFF] == v6 >> 13
          && (v7 = (idVehicle_Car *)gameLocal->entities.ptr[v6 & 0x1FFF]) != nullptr )
        {
          v8 = idVehicle_Car::CastTo(c: v7);
        }
        else
        {
          v8 = nullptr;
        }
        presentable = v8->presentable;
        v10 = presentable != nullptr ? (int)presentable->GetVehicleInterface(this: presentable) : 0;
        if ( v4 >= *(_DWORD *)(v10 + 18748) )
          break;
        v11 = this->vehicleCar.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v11 & 0x1FFF] == v11 >> 13
          && (v12 = (idVehicle_Car *)gameLocal->entities.ptr[v11 & 0x1FFF]) != nullptr )
        {
          v13 = idVehicle_Car::CastTo(c: v12);
        }
        else
        {
          v13 = nullptr;
        }
        v14 = v13->presentable;
        if ( v14 != nullptr )
          v15 = (int)v14->GetVehicleInterface(this: v14);
        else
          v15 = 0;
        v16 = *(idVehicleWeapon **)(*(_DWORD *)(v15 + 18744) + i);
        if ( v16 != nullptr )
          idVehicleWeapon::ReleaseTrigger(this: v16);
        ++v4;
      }
    }
  }
}


// ========================================================================
// ?HasAmmo@idVehicleAI@@QAA_NXZ
// EA  : 0x82B0D308
// RVA : 0x00B0D308
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

int __fastcall idVehicleAI::HasAmmo(idVehicleAI *this)
{
  int v2; // r27
  int i; // r29
  int value; // r10
  idVehicle_Car *v5; // r3
  idVehicle_Car *v6; // r3
  idPresentable *presentable; // r3
  int v8; // r3
  int v9; // r10
  idVehicle_Car *v10; // r3
  idVehicle_Car *v11; // r3
  idPresentable *v12; // r3
  int v13; // r3
  int v14; // r11
  idVehicleWeapon *v15; // r31

  v2 = 0;
  for ( i = 0; ; i += 4 )
  {
    value = this->vehicleCar.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v5 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v6 = idVehicle_Car::CastTo(c: v5);
    }
    else
    {
      v6 = nullptr;
    }
    presentable = v6->presentable;
    v8 = presentable != nullptr ? (int)presentable->GetVehicleInterface(this: presentable) : 0;
    if ( v2 >= *(_DWORD *)(v8 + 18748) )
      break;
    v9 = this->vehicleCar.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v9 & 0x1FFF] == v9 >> 13
      && (v10 = (idVehicle_Car *)gameLocal->entities.ptr[v9 & 0x1FFF]) != nullptr )
    {
      v11 = idVehicle_Car::CastTo(c: v10);
    }
    else
    {
      v11 = nullptr;
    }
    v12 = v11->presentable;
    if ( v12 != nullptr )
      v13 = (int)v12->GetVehicleInterface(this: v12);
    else
      v13 = 0;
    v14 = *(_DWORD *)(v13 + 18744);
    v15 = *(idVehicleWeapon **)(v14 + i);
    if ( v15 != nullptr
      && idVehicleWeapon::IsActive(this: *(idVehicleWeapon **)(v14 + i))
      && idVehicleWeapon::HasAmmo(this: v15) )
    {
      return 1;
    }
    ++v2;
  }
  return 0;
}


// ========================================================================
// ?OkToFire@idVehicleAI@@QAA_NXZ
// EA  : 0x82B0D468
// RVA : 0x00B0D468
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

BOOL __fastcall idVehicleAI::OkToFire(idVehicleAI *this)
{
  idVehicleWeapon *v2; // r31
  int v3; // r28
  int i; // r30
  int value; // r9
  idGameLocal *v6; // r11
  idVehicle_Car *v7; // r3
  idVehicle_Car *v8; // r3
  idPresentable *presentable; // r3
  int v10; // r3
  int v11; // r9
  idVehicle_Car *v12; // r3
  idVehicle_Car *v13; // r3
  idPresentable *v14; // r3
  int v15; // r3
  int v16; // r9
  idVehicle_Car *v17; // r3
  idVehicle_Car *v18; // r3
  idPresentable *v19; // r3
  idPresentableVehicle *v20; // r3
  BOOL v21; // r28
  double aiMinDelayTimeSecs; // fp30
  double aiMaxDelayTimeSecs; // fp31
  int v24; // r31
  const char *v25; // r4
  double aiMinFireTimeSecs; // fp30
  double valueFloat; // fp31
  int v28; // r9
  idEntity *v29; // r3
  idNavPathPosTracker *enemyTracker; // r3
  idGameLocal *v31; // r11
  int v32; // r30
  int j; // r31
  int v34; // r9
  idVehicle_Car *v35; // r3
  idVehicle_Car *v36; // r3
  idPresentable *v37; // r3
  int v38; // r3
  int v39; // r9
  idVehicle_Car *v40; // r3
  idVehicle_Car *v41; // r3
  idPresentable *v42; // r3
  int v43; // r3
  int v44; // r9
  idVehicle_Car *v45; // r3
  idVehicle_Car *v46; // r3
  idPresentable *v47; // r3
  int v48; // r3
  int v50; // [sp+54h] [-4Ch]

  v2 = nullptr;
  v3 = 0;
  for ( i = 0; ; i += 4 )
  {
    value = this->vehicleCar.spawnId.value;
    v6 = gameLocal;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v7 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v8 = idVehicle_Car::CastTo(c: v7);
      v6 = gameLocal;
    }
    else
    {
      v8 = nullptr;
    }
    presentable = v8->presentable;
    if ( presentable != nullptr )
    {
      v10 = (int)presentable->GetVehicleInterface(this: presentable);
      v6 = gameLocal;
    }
    else
    {
      v10 = 0;
    }
    if ( v3 >= *(_DWORD *)(v10 + 18748) )
      break;
    v11 = this->vehicleCar.spawnId.value;
    if ( v6->spawnIds.ptr[v11 & 0x1FFF] == v11 >> 13
      && (v12 = (idVehicle_Car *)v6->entities.ptr[v11 & 0x1FFF]) != nullptr )
    {
      v13 = idVehicle_Car::CastTo(c: v12);
      v6 = gameLocal;
    }
    else
    {
      v13 = nullptr;
    }
    v14 = v13->presentable;
    if ( v14 != nullptr )
    {
      v15 = (int)v14->GetVehicleInterface(this: v14);
      v6 = gameLocal;
    }
    else
    {
      v15 = 0;
    }
    v16 = this->vehicleCar.spawnId.value;
    v2 = *(idVehicleWeapon **)(*(_DWORD *)(v15 + 18744) + i);
    if ( v6->spawnIds.ptr[v16 & 0x1FFF] == v16 >> 13
      && (v17 = (idVehicle_Car *)v6->entities.ptr[v16 & 0x1FFF]) != nullptr )
    {
      v18 = idVehicle_Car::CastTo(c: v17);
    }
    else
    {
      v18 = nullptr;
    }
    v19 = v18->presentable;
    if ( v19 != nullptr )
      v20 = v19->GetVehicleInterface(this: v19);
    else
      v20 = nullptr;
    idPresentableVehicle::GetCurrentWeaponGroup(this: v20);
    idVehicleWeapon::GetWeaponSlot(this: v2);
    ++v3;
  }
  v21 = true;
  if ( this->nextFireTime >= 0 )
  {
    this->inFireDelayState = true;
    if ( this->nextFireTime > gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
    {
      v25 = "in delay";
      goto LABEL_78;
    }
    if ( v2 != nullptr )
    {
      if ( vai_minFireTimeSecs.valueFloat <= -1.0 )
        aiMinFireTimeSecs = idVehicleWeapon::GetDeclVehicleWeapon(this: v2)->aiMinFireTimeSecs;
      else
        aiMinFireTimeSecs = vai_minFireTimeSecs.valueFloat;
      valueFloat = vai_maxFireTimeSecs.valueFloat;
      if ( vai_maxFireTimeSecs.valueFloat <= -1.0 )
        valueFloat = idVehicleWeapon::GetDeclVehicleWeapon(this: v2)->aiMaxFireTimeSecs;
      v50 = (int)(float)((float)((float)(idVehicleAI::GetDifficulty_AttackScale(this)
                                       * (float)((float)valueFloat - (float)aiMinFireTimeSecs))
                               + (float)aiMinFireTimeSecs)
                       * (float)1000.0);
      this->nextFireTime = -(gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + v50);
    }
  }
  else
  {
    this->inFireDelayState = false;
    if ( v2 != nullptr && -this->nextFireTime <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
    {
      aiMinDelayTimeSecs = vai_minFireDelayTimeSecs.valueFloat;
      if ( vai_minFireDelayTimeSecs.valueFloat <= -1.0 )
        aiMinDelayTimeSecs = idVehicleWeapon::GetDeclVehicleWeapon(this: v2)->aiMinDelayTimeSecs;
      aiMaxDelayTimeSecs = vai_maxFireDelayTimeSecs.valueFloat;
      if ( vai_maxFireDelayTimeSecs.valueFloat <= -1.0 )
        aiMaxDelayTimeSecs = idVehicleWeapon::GetDeclVehicleWeapon(this: v2)->aiMaxDelayTimeSecs;
      v24 = (int)(float)((float)((float)((float)((float)1.0 - idVehicleAI::GetDifficulty_AttackScale(this))
                                       * (float)((float)aiMaxDelayTimeSecs - (float)aiMinDelayTimeSecs))
                               + (float)aiMinDelayTimeSecs)
                       * (float)1000.0);
      this->nextFireTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + v24;
      if ( v24 > 0 )
      {
        v25 = "stop fire";
LABEL_78:
        idStr::operator=(this: &this->debugFireInfo, text: v25);
        return false;
      }
    }
  }
  v28 = this->target.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v28 & 0x1FFF] != v28 >> 13
    || (v29 = gameLocal->entities.ptr[v28 & 0x1FFF]) == nullptr
    || idEntity::CastTo(c: v29) == nullptr )
  {
    v25 = "no target";
    goto LABEL_78;
  }
  enemyTracker = this->enemyTracker;
  if ( enemyTracker != nullptr && idNavPathPosTracker::GetOwner(this: enemyTracker) != nullptr )
  {
    v31 = gameLocal;
    v32 = 0;
    for ( j = 0; ; j += 4 )
    {
      v34 = this->vehicleCar.spawnId.value;
      if ( v31->spawnIds.ptr[v34 & 0x1FFF] == v34 >> 13
        && (v35 = (idVehicle_Car *)v31->entities.ptr[v34 & 0x1FFF]) != nullptr )
      {
        v36 = idVehicle_Car::CastTo(c: v35);
        v31 = gameLocal;
      }
      else
      {
        v36 = nullptr;
      }
      v37 = v36->presentable;
      if ( v37 != nullptr )
      {
        v38 = (int)v37->GetVehicleInterface(this: v37);
        v31 = gameLocal;
      }
      else
      {
        v38 = 0;
      }
      if ( v32 >= *(_DWORD *)(v38 + 18748) )
        break;
      v39 = this->vehicleCar.spawnId.value;
      if ( v31->spawnIds.ptr[v39 & 0x1FFF] == v39 >> 13
        && (v40 = (idVehicle_Car *)v31->entities.ptr[v39 & 0x1FFF]) != nullptr )
      {
        v41 = idVehicle_Car::CastTo(c: v40);
        v31 = gameLocal;
      }
      else
      {
        v41 = nullptr;
      }
      v42 = v41->presentable;
      if ( v42 != nullptr )
      {
        v43 = (int)v42->GetVehicleInterface(this: v42);
        v31 = gameLocal;
      }
      else
      {
        v43 = 0;
      }
      if ( *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(v43 + 18744) + j) + 504) != 0 )
        break;
      ++v32;
    }
    v44 = this->vehicleCar.spawnId.value;
    if ( v31->spawnIds.ptr[v44 & 0x1FFF] == v44 >> 13
      && (v45 = (idVehicle_Car *)v31->entities.ptr[v44 & 0x1FFF]) != nullptr )
    {
      v46 = idVehicle_Car::CastTo(c: v45);
    }
    else
    {
      v46 = nullptr;
    }
    v47 = v46->presentable;
    if ( v47 != nullptr )
      v48 = (int)v47->GetVehicleInterface(this: v47);
    else
      v48 = 0;
    v21 = *(_DWORD *)(v48 + 18748) != v32;
  }
  if ( !v21 )
    idStr::operator=(this: &this->debugFireInfo, text: "not vis");
  return v21;
}


// ========================================================================
// ?SetTarget@idVehicleAI@@QAAXPAVidEntity@@@Z
// EA  : 0x82B0DA10
// RVA : 0x00B0DA10
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::SetTarget(idVehicleAI *this, idEntity *entity)
{
  if ( entity != nullptr )
    this->target.spawnId.value = (gameLocal->spawnIds.ptr[entity->entityNumber] << 13) | entity->entityNumber;
  else
    this->target.spawnId.value = 0x1FFF;
}


// ========================================================================
// ?GetGuardDistance@idVehicleAI@@QAAMPAVidEntity@@0@Z
// EA  : 0x82B0DA50
// RVA : 0x00B0DA50
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

float __fastcall idVehicleAI::GetGuardDistance(idVehicleAI *this, idEntity *enemy, idSplineWaypoint *guard)
{
  double PathDistance; // fp31
  idNavPathPosTracker *Tracker; // r3
  idNavPathPosTracker *v8; // r30
  double rightDistance; // fp30
  double excessEdgeLimit; // fp29
  double v11; // fp1
  idSplineWaypoint *v12; // r3
  __int64 v13; // r6
  idAISplinePath *v14; // r3
  idNavSpline *NavSpline; // r30
  int v16; // r29
  int v17; // r31
  idGameLocal *v18; // r10
  int value; // r9
  idEntity *v20; // r3
  idEntity *v21; // r3
  idVehicleAI *v22; // r3
  idNavPathPosTracker *v23; // r3

  PathDistance = 1.0e30;
  Tracker = idNavSplinePathMgr::FindTracker(this: this->splinePathMgr, owner: enemy, createTrackerIfNotFound: true);
  v8 = Tracker;
  if ( Tracker != nullptr )
  {
    rightDistance = Tracker->pathPosition.rightDistance;
    excessEdgeLimit = Tracker->pathPosition.navSpline->splinePath->excessEdgeLimit;
    if ( rightDistance > (float)(idNavPathPosTracker::GetSplineWidth(this: Tracker) + (float)excessEdgeLimit) )
    {
      v11 = 1.0e30;
      return *((float *)&v11 + 1);
    }
  }
  if ( (unsigned __int8)idSplineWaypoint::IsTypeOf(c: guard) != 0 )
  {
    v12 = idSplineWaypoint::CastTo(c: guard);
    if ( v8 != nullptr )
    {
      v13 = *(_QWORD *)&v12->splinePathPosition.distance;
LABEL_23:
      PathDistance = idNavSplinePathMgr::GetPathDistance(
                       this: this->splinePathMgr,
                       start: (idNavSplinePosition *)LODWORD(v8->pathPosition.rightDistance),
                       end: (idNavSplinePosition *)__ROL4__(v8->pathPosition.navSpline, 32),
                       forward: (idVec3 *)v13,
                       includeRightDistance: SLOBYTE(vec3_origin.x));
      goto LABEL_24;
    }
    goto LABEL_24;
  }
  if ( (unsigned __int8)idAISplinePath::IsTypeOf(c: guard) == 0 )
  {
    v22 = idVehicleAI::CastTo(c: (idVehicleAI *)guard);
    if ( v22 != nullptr )
      guard = (idSplineWaypoint *)idVehicleAI::GetVehicleCar(this: v22);
    v23 = idNavSplinePathMgr::FindTracker(this: this->splinePathMgr, owner: guard, createTrackerIfNotFound: false);
    if ( v23 == nullptr || v8 == nullptr )
      goto LABEL_24;
    v13 = *(_QWORD *)&v23->pathPosition.distance;
    goto LABEL_23;
  }
  v14 = idAISplinePath::CastTo(c: (idAISplinePath *)guard);
  NavSpline = idNavSplinePathMgr::GetNavSpline(this: this->splinePathMgr, splineName: v14->name.data);
  v16 = 0;
  if ( NavSpline->entityList.num <= 0 )
  {
LABEL_24:
    v11 = PathDistance;
    return *((float *)&v11 + 1);
  }
  v17 = 0;
  v18 = gameLocal;
  while ( 1 )
  {
    value = NavSpline->entityList.list[v17].spawnId.value;
    if ( v18->spawnIds.ptr[value & 0x1FFF] == value >> 13 && (v20 = v18->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v21 = idEntity::CastTo(c: v20);
      v18 = gameLocal;
    }
    else
    {
      v21 = nullptr;
    }
    if ( v21 == enemy )
      break;
    ++v16;
    ++v17;
    if ( v16 >= NavSpline->entityList.num )
      goto LABEL_24;
  }
  v11 = 0.0;
  return *((float *)&v11 + 1);
}


// ========================================================================
// ?DrawSplineDebug@idVehicleAI@@IAAXXZ
// EA  : 0x82B0DC58
// RVA : 0x00B0DC58
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idVehicleAI::DrawSplineDebug(idVehicleAI *this, __int64 a2)
{
  __int64 v2; // r7
  idNavPathPosTracker *splineTracker; // r11
  __int64 v4; // fp13
  float rightDistance; // r8
  idRenderWorld_vtbl *v7; // r29
  idVec3 *SplineWorldPos; // r3
  int value; // r10
  idVehicle_Car *v10; // r3
  idVehicle_Car *v11; // r3
  idPhysics *Physics; // r3
  int v13; // r3
  float *p_y; // r10
  _DWORD *v15; // r11
  int i; // ctr
  int v17; // r9
  idVehicle_Car *v18; // r3
  idVehicle_Car *v19; // r3
  idPhysics *v20; // r3
  double v21; // fp31
  float *v22; // r3
  int v23; // r9
  double v24; // fp11
  double v25; // fp9
  idVehicle_Car *v26; // r3
  idVehicle_Car *v27; // r3
  idPhysics *v28; // r3
  idAngles *v29; // r3
  idVec3 *v30; // r3
  double v31; // fp3
  double v32; // fp0
  idVec3 *v33; // r3
  double v34; // fp4
  double v35; // fp12
  int v36; // r9
  idVehicle_Car *v37; // r3
  idVehicle_Car *v38; // r28
  double MaxSpeed; // fp1
  idPresentable *presentable; // r3
  double v41; // fp29
  idPresentableVehicle *v42; // r3
  double MaxSteerAngle; // fp1
  idVec3 *v44; // r3
  double v45; // fp7
  double v46; // fp1
  int v47; // r9
  idVehicle_Car *v48; // r3
  idVehicle_Car *v49; // r28
  double v50; // fp1
  idPresentable *v51; // r3
  double v52; // fp29
  idPresentableVehicle *v53; // r3
  double v54; // fp1
  idVec3 *v55; // r3
  double v56; // fp3
  double v57; // fp1
  float y; // r3
  float z; // r10
  idNavPathPosTracker *v60; // r11
  float distance; // r5
  float v62; // r10
  float v63; // r9
  idRenderWorld_vtbl *v64; // r31
  idVec3 *WorldPos; // r3
  __int64 v66; // [sp+50h] [-120h] BYREF
  float v67; // [sp+58h] [-118h]
  idMat3 v68; // [sp+60h] [-110h] BYREF
  float v69; // [sp+84h] [-ECh]
  float v70; // [sp+88h] [-E8h]
  float v71; // [sp+8Ch] [-E4h]
  float v72; // [sp+90h] [-E0h]
  float v73[4]; // [sp+98h] [-D8h] BYREF
  idVec3 v74; // [sp+A8h] [-C8h] BYREF
  idVec3 v75; // [sp+B8h] [-B8h] BYREF
  float v76[4]; // [sp+C8h] [-A8h] BYREF
  _DWORD v77[4]; // [sp+D8h] [-98h] BYREF
  float v78[4]; // [sp+E8h] [-88h] BYREF
  float v79[6]; // [sp+F8h] [-78h] BYREF
  float v80[6]; // [sp+110h] [-60h] BYREF

  LODWORD(v2) = (unsigned __int8)this;
  splineTracker = this->splineTracker;
  HIDWORD(v2) = BYTE2(this);
  v4 = *(__int64 *)((char *)&a2 - 4);
  LODWORD(a2) = BYTE1(this);
  v66 = a2;
  v68.mat[2].y = 1.0;
  v68.mat[2].x = (float)a2 * (float)0.0039215689;
  v68.mat[1].z = (float)v4 * (float)0.0039215689;
  v68.mat[1].y = (float)v2 * (float)0.0039215689;
  rightDistance = splineTracker->pathPosition.rightDistance;
  LODWORD(v2) = splineTracker->pathPosition.navSpline;
  v75.x = splineTracker->pathPosition.distance;
  v75.y = rightDistance;
  LODWORD(v75.z) = v2;
  v7 = clientGame->renderWorld->__vftable;
  SplineWorldPos = idNavSplinePosition::GetSplineWorldPos(this: (idNavSplinePosition *)&v68.mat[2].z, result: &v75);
  ((void (__fastcall *)(idRenderWorld *, float *, idVec3 *, idVec3 *, double))v7->DebugCircle)(
    a1: clientGame->renderWorld,
    a2: &v68.mat[1].y,
    a3: SplineWorldPos,
    a4: &vec3_up,
    a5: 4.0);
  if ( idNavSplinePathMgr::GetShortestPath(
         this: (idNavSplinePathMgr *)LODWORD(this->splineTracker->pathPosition.distance),
         start: (idNavSplinePosition *)LODWORD(this->splineTracker->pathPosition.rightDistance),
         end: (idNavSplinePosition *)__ROL4__(this->splineTracker->pathPosition.navSpline, 32),
         path: (navSplinePath_t *)LODWORD(this->splineTracker->goalPathPosition.rightDistance)) != nullptr )
  {
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)this->splinePathMgr);
    v68.mat[2].z = v68.mat[1].y * (float)0.5;
    v69 = v68.mat[1].z * (float)0.5;
    v70 = v68.mat[2].x * (float)0.5;
    v71 = v68.mat[2].y * (float)0.5;
    navSplinePath_t::Draw(
      this: (navSplinePath_t *)LODWORD(v68.mat[2].z),
      color: (idColor *)LODWORD(v70),
      stepSize: 500.0);
  }
  value = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v10 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v11 = idVehicle_Car::CastTo(c: v10);
  }
  else
  {
    v11 = nullptr;
  }
  Physics = idEntity::GetPhysics(this: v11);
  v13 = (int)Physics->GetBounds(this: Physics, a2: -1);
  p_y = &v68.mat[2].y;
  v15 = (_DWORD *)(v13 - 4);
  for ( i = 6; i != 0; --i )
    *++p_y = *(float *)++v15;
  v17 = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v17 & 0x1FFF] == v17 >> 13
    && (v18 = (idVehicle_Car *)gameLocal->entities.ptr[v17 & 0x1FFF]) != nullptr )
  {
    v19 = idVehicle_Car::CastTo(c: v18);
  }
  else
  {
    v19 = nullptr;
  }
  v20 = idEntity::GetPhysics(this: v19);
  v21 = (float)(v72 - v69);
  v22 = (float *)v20->GetOrigin(this: v20, a2: 0);
  v23 = this->vehicleCar.spawnId.value;
  v24 = v22[1];
  v25 = *v22;
  v67 = v22[2] + (float)v21;
  *(float *)&v66 = v25;
  *((float *)&v66 + 1) = v24;
  if ( gameLocal->spawnIds.ptr[v23 & 0x1FFF] == v23 >> 13
    && (v26 = (idVehicle_Car *)gameLocal->entities.ptr[v23 & 0x1FFF]) != nullptr )
  {
    v27 = idVehicle_Car::CastTo(c: v26);
  }
  else
  {
    v27 = nullptr;
  }
  v28 = idEntity::GetPhysics(this: v27);
  v29 = (idAngles *)v28->GetAxis(this: v28, a2: 0);
  idMat3::ToAngles(this: &v68, result: v29);
  v68.mat[0].y = v68.mat[0].y - this->desiredSteering;
  v30 = idAngles::ToForward(this: (idAngles *)&v68.mat[2].z, result: v68.mat);
  v31 = (float)(v30->z * (float)50.0);
  v32 = (float)((float)(v30->y * (float)50.0) + *((float *)&v66 + 1));
  v76[0] = (float)(v30->x * (float)50.0) + *(float *)&v66;
  v76[1] = v32;
  v76[2] = (float)v31 + v67;
  ((void (__fastcall *)(idRenderWorld *, float *, __int64 *, float *, double))clientGame->renderWorld->DebugArrow)(
    a1: clientGame->renderWorld,
    a2: &v68.mat[1].y,
    a3: &v66,
    a4: v76,
    a5: 6.0);
  v68.mat[0].y = v68.mat[0].y + this->desiredSteering;
  v33 = idAngles::ToForward(this: (idAngles *)&v68.mat[2].z, result: v68.mat);
  v34 = (float)(v33->y * (float)25.0);
  v35 = (float)((float)(v33->z * (float)25.0) + v67);
  v78[0] = (float)(v33->x * (float)25.0) + *(float *)&v66;
  v78[2] = v35;
  v78[1] = (float)v34 + *((float *)&v66 + 1);
  clientGame->renderWorld->DebugLine(
    this: clientGame->renderWorld,
    a2: (const idVec4 *)&idColor::colorWhite,
    a3: (const idVec3 *)&v66,
    a4: (const idVec3 *)v78,
    a5: 0,
    a6: false);
  v36 = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v36 & 0x1FFF] == v36 >> 13
    && (v37 = (idVehicle_Car *)gameLocal->entities.ptr[v36 & 0x1FFF]) != nullptr )
  {
    v38 = idVehicle_Car::CastTo(c: v37);
  }
  else
  {
    v38 = nullptr;
  }
  MaxSpeed = idVehicleAI::GetMaxSpeed(this);
  presentable = v38->presentable;
  v41 = (float)(this->actualSpeed / (float)MaxSpeed);
  if ( presentable != nullptr )
    v42 = presentable->GetVehicleInterface(this: presentable);
  else
    v42 = nullptr;
  MaxSteerAngle = idPresentableVehicle::GetMaxSteerAngle(this: v42, speed: v41);
  v68.mat[0].y = (float)MaxSteerAngle + v68.mat[0].y;
  v44 = idAngles::ToForward(this: (idAngles *)&v68.mat[2].z, result: v68.mat);
  v45 = (float)(v44->z * (float)50.0);
  v46 = (float)((float)(v44->y * (float)50.0) + *((float *)&v66 + 1));
  v73[0] = (float)(v44->x * (float)50.0) + *(float *)&v66;
  v73[1] = v46;
  v73[2] = (float)v45 + v67;
  clientGame->renderWorld->DebugLine(
    this: clientGame->renderWorld,
    a2: (const idVec4 *)&idColor::colorWhite,
    a3: (const idVec3 *)&v66,
    a4: (const idVec3 *)v73,
    a5: 0,
    a6: false);
  v47 = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v47 & 0x1FFF] == v47 >> 13
    && (v48 = (idVehicle_Car *)gameLocal->entities.ptr[v47 & 0x1FFF]) != nullptr )
  {
    v49 = idVehicle_Car::CastTo(c: v48);
  }
  else
  {
    v49 = nullptr;
  }
  v50 = idVehicleAI::GetMaxSpeed(this);
  v51 = v49->presentable;
  v52 = (float)(this->actualSpeed / (float)v50);
  if ( v51 != nullptr )
    v53 = v51->GetVehicleInterface(this: v51);
  else
    v53 = nullptr;
  v54 = idPresentableVehicle::GetMaxSteerAngle(this: v53, speed: v52);
  v68.mat[0].y = -(float)((float)((float)v54 * (float)2.0) - v68.mat[0].y);
  v55 = idAngles::ToForward(this: (idAngles *)&v68.mat[2].z, result: v68.mat);
  v56 = (float)(v55->z * (float)50.0);
  v57 = (float)((float)(v55->y * (float)50.0) + *((float *)&v66 + 1));
  v79[0] = (float)(v55->x * (float)50.0) + *(float *)&v66;
  v79[1] = v57;
  v79[2] = (float)v56 + v67;
  clientGame->renderWorld->DebugLine(
    this: clientGame->renderWorld,
    a2: (const idVec4 *)&idColor::colorWhite,
    a3: (const idVec3 *)&v66,
    a4: (const idVec3 *)v79,
    a5: 0,
    a6: false);
  y = this->immediateGoalPosition.y;
  z = this->immediateGoalPosition.z;
  v77[0] = LODWORD(this->immediateGoalPosition.x);
  *(float *)&v77[1] = y;
  *(float *)&v77[2] = z;
  ((void (__fastcall *)(idRenderWorld *, float *, __int64 *, _DWORD *, double))clientGame->renderWorld->DebugArrow)(
    a1: clientGame->renderWorld,
    a2: &v68.mat[1].y,
    a3: &v66,
    a4: v77,
    a5: 4.0);
  ((void (__fastcall *)(idRenderWorld *, idColor *, __int64 *, idVec3 *, double))clientGame->renderWorld->DebugArrow)(
    a1: clientGame->renderWorld,
    a2: &idColor::colorWhite,
    a3: &v66,
    a4: this->desiredGoalPosition,
    a5: 4.0);
  v60 = this->splineTracker;
  distance = v60->goalPathPosition.distance;
  v62 = v60->goalPathPosition.rightDistance;
  v63 = *(float *)&v60->goalPathPosition.navSpline;
  v80[1] = v68.mat[1].z * (float)0.40000001;
  v80[3] = v68.mat[2].y * (float)0.40000001;
  v80[0] = v68.mat[1].y * (float)0.40000001;
  v74.x = distance;
  v80[2] = v68.mat[2].x * (float)0.40000001;
  v74.y = v62;
  v74.z = v63;
  v64 = clientGame->renderWorld->__vftable;
  WorldPos = idNavSplinePosition::GetWorldPos(this: (idNavSplinePosition *)&v68.mat[2].z, result: &v74);
  ((void (__fastcall *)(idRenderWorld *, float *, __int64 *, idVec3 *, double))v64->DebugArrow)(
    a1: clientGame->renderWorld,
    a2: v80,
    a3: &v66,
    a4: WorldPos,
    a5: 4.0);
}


// ========================================================================
// ?SteeringTowardsClosestEdge@idVehicleAI@@IAA_NAAMAAH@Z
// EA  : 0x82B0E3B0
// RVA : 0x00B0E3B0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

int __fastcall idVehicleAI::SteeringTowardsClosestEdge(idVehicleAI *this, float *dot, int *turnDir)
{
  int value; // r10
  idVehicle_Car *v7; // r3
  idNavPathPosTracker *splineTracker; // r11
  int v9; // r8
  idVehicle_Car *v10; // r3
  idVehicle_Car *v11; // r3
  idPhysics *Physics; // r3
  int v13; // r9
  idVehicle_Car *v14; // r3
  idVehicle_Car *v15; // r3
  idPhysics *v16; // r3
  float *v17; // r3
  double v18; // fp13
  double v19; // fp30
  double v20; // fp12
  idNavPathPosTracker *v21; // r11
  double v22; // fp29
  double v23; // fp28
  idNavPathPosTracker *p_null_splineTracker; // r10
  double rightDistance; // fp31
  double v26; // fp8
  double v27; // fp9
  double v28; // fp10
  double immediateGoalAngle; // fp11
  float x; // [sp+50h] [-60h]
  float y; // [sp+54h] [-5Ch]
  float z; // [sp+58h] [-58h]

  value = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v7 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v7 != nullptr && idVehicle_Car::CastTo(c: v7) != nullptr )
    {
      splineTracker = this->splineTracker;
      if ( splineTracker == nullptr )
        splineTracker = &this->splinePathMgr->null_splineTracker;
      v9 = this->vehicleCar.spawnId.value;
      x = splineTracker->forward.x;
      y = splineTracker->forward.y;
      z = splineTracker->forward.z;
      if ( gameLocal->spawnIds.ptr[v9 & 0x1FFF] == v9 >> 13
        && (v10 = (idVehicle_Car *)gameLocal->entities.ptr[v9 & 0x1FFF]) != nullptr )
      {
        v11 = idVehicle_Car::CastTo(c: v10);
      }
      else
      {
        v11 = nullptr;
      }
      Physics = idEntity::GetPhysics(this: v11);
      Physics->GetAxis(this: Physics, a2: 0);
      v13 = this->vehicleCar.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v13 & 0x1FFF] == v13 >> 13
        && (v14 = (idVehicle_Car *)gameLocal->entities.ptr[v13 & 0x1FFF]) != nullptr )
      {
        v15 = idVehicle_Car::CastTo(c: v14);
      }
      else
      {
        v15 = nullptr;
      }
      v16 = idEntity::GetPhysics(this: v15);
      v17 = (float *)v16->GetAxis(this: v16, a2: 0);
      v18 = v17[4];
      v19 = -v17[3];
      v20 = v17[5];
      *turnDir = -1;
      v21 = this->splineTracker;
      v22 = -v18;
      v23 = -v20;
      if ( v21 != nullptr )
        p_null_splineTracker = this->splineTracker;
      else
        p_null_splineTracker = &this->splinePathMgr->null_splineTracker;
      rightDistance = p_null_splineTracker->pathPosition.rightDistance;
      if ( v21 == nullptr )
        v21 = &this->splinePathMgr->null_splineTracker;
      if ( idNavPathPosTracker::GetFacing(this: v21) >= 0.0 )
      {
        v28 = z;
        v27 = y;
        v26 = x;
      }
      else
      {
        rightDistance = -rightDistance;
        v26 = -x;
        v27 = -y;
        v28 = -z;
      }
      immediateGoalAngle = this->immediateGoalAngle;
      if ( rightDistance < 0.0 )
      {
        v19 = -v19;
        v22 = -v22;
        v23 = -v23;
        immediateGoalAngle = -immediateGoalAngle;
        *turnDir = -*turnDir;
      }
      if ( (float)((float)((float)v28 * (float)v23)
                 + (float)((float)((float)v27 * (float)v22) + (float)((float)v26 * (float)v19))) < 0.0
        && immediateGoalAngle > 0.0 )
      {
        *dot = (float)((float)((float)v28 * (float)v23)
                     + (float)((float)((float)v27 * (float)v22) + (float)((float)v26 * (float)v19)))
             + (float)1.0;
        return 1;
      }
      *dot = -1.0;
    }
  }
  return 0;
}


// ========================================================================
// ?UseSplinePath@idVehicleAI@@QAAXPAD@Z
// EA  : 0x82B0E628
// RVA : 0x00B0E628
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::UseSplinePath(idVehicleAI *this, char *pathName)
{
  idGameLocal *v3; // r11
  idVehicle_Car *v5; // r3
  int value; // r9
  idVehicle_Car *v7; // r3
  idVehicle_Car *v8; // r3
  int v9; // r9
  idEntity *v10; // r3
  idEntity *v11; // r31
  idNavPathPosTracker *splineTracker; // r11
  idNavPathPosTracker *v13; // r3

  v3 = gameLocal;
  if ( gameLocal->spawnIds.ptr[this->vehicleCar.spawnId.value & 0x1FFF] == this->vehicleCar.spawnId.value >> 13 )
  {
    v5 = (idVehicle_Car *)gameLocal->entities.ptr[this->vehicleCar.spawnId.value & 0x1FFF];
    if ( v5 != nullptr )
    {
      if ( idVehicle_Car::CastTo(c: v5) != nullptr )
      {
        value = this->vehicleCar.spawnId.value;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
        {
          v7 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
          if ( v7 != nullptr )
          {
            v8 = idVehicle_Car::CastTo(c: v7);
            goto LABEL_12;
          }
        }
        goto LABEL_11;
      }
      v3 = gameLocal;
    }
  }
  v9 = this->vehicleEntity.spawnId.value;
  if ( v3->spawnIds.ptr[v9 & 0x1FFF] == v9 >> 13 )
  {
    v10 = v3->entities.ptr[v9 & 0x1FFF];
    if ( v10 != nullptr )
    {
      v8 = (idVehicle_Car *)idEntity::CastTo(c: v10);
      goto LABEL_12;
    }
  }
LABEL_11:
  v8 = nullptr;
LABEL_12:
  v11 = v8;
  if ( v8 != nullptr )
  {
    splineTracker = this->splineTracker;
    this->pathType = VEHICLE_PATH_SPLINE;
    if ( splineTracker == nullptr )
      this->splineTracker = idNavSplinePathMgr::FindTracker(
                              this: this->splinePathMgr,
                              owner: v8,
                              createTrackerIfNotFound: true);
    v13 = this->splineTracker;
    if ( v13 != nullptr )
      idNavPathPosTracker::Init(this: v13, pathName, owner: v11);
    this->distanceToFinalGoal = 0.0;
    this->deltaToFinalGoal = 0.0;
  }
}


// ========================================================================
// ?GetOwner@idVehicleAI@@QBAPAVidEntity@@XZ
// EA  : 0x82B0E770
// RVA : 0x00B0E770
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

idVehicle_Car *__fastcall idVehicleAI::GetOwner(idVehicleAI *this)
{
  idGameLocal *v2; // r11
  idVehicle_Car *v3; // r3
  int value; // r9
  idVehicle_Car *v5; // r3
  int v7; // r9
  idEntity *v8; // r3

  v2 = gameLocal;
  if ( gameLocal->spawnIds.ptr[this->vehicleCar.spawnId.value & 0x1FFF] == this->vehicleCar.spawnId.value >> 13 )
  {
    v3 = (idVehicle_Car *)gameLocal->entities.ptr[this->vehicleCar.spawnId.value & 0x1FFF];
    if ( v3 != nullptr )
    {
      if ( idVehicle_Car::CastTo(c: v3) != nullptr )
      {
        value = this->vehicleCar.spawnId.value;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
        {
          v5 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
          if ( v5 != nullptr )
            return idVehicle_Car::CastTo(c: v5);
        }
        return nullptr;
      }
      v2 = gameLocal;
    }
  }
  v7 = this->vehicleEntity.spawnId.value;
  if ( v2->spawnIds.ptr[v7 & 0x1FFF] == v7 >> 13 )
  {
    v8 = v2->entities.ptr[v7 & 0x1FFF];
    if ( v8 != nullptr )
      return (idVehicle_Car *)idEntity::CastTo(c: v8);
  }
  return nullptr;
}


// ========================================================================
// ?GetOwnerVehicle@idVehicleAI@@QBAPAVidVehicle@@XZ
// EA  : 0x82B0E870
// RVA : 0x00B0E870
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

idVehicle_Car *__fastcall idVehicleAI::GetOwnerVehicle(idVehicleAI *this)
{
  idGameLocal *v2; // r11
  idVehicle_Car *v3; // r3
  idVehicle_Car *v4; // r3
  idVehicle_Car *v5; // r29
  int value; // r9
  idEntity *v7; // r3
  idVehicle *v8; // r31
  idVehicle_Car *result; // r3
  bool v10; // zf

  v2 = gameLocal;
  if ( gameLocal->spawnIds.ptr[this->vehicleCar.spawnId.value & 0x1FFF] == this->vehicleCar.spawnId.value >> 13
    && (v3 = (idVehicle_Car *)gameLocal->entities.ptr[this->vehicleCar.spawnId.value & 0x1FFF]) != nullptr )
  {
    v4 = idVehicle_Car::CastTo(c: v3);
    v2 = gameLocal;
    v5 = v4;
  }
  else
  {
    v5 = nullptr;
  }
  if ( v5 != nullptr )
    return v5;
  value = this->vehicleEntity.spawnId.value;
  if ( v2->spawnIds.ptr[value & 0x1FFF] == value >> 13 && (v7 = v2->entities.ptr[value & 0x1FFF]) != nullptr )
    v8 = (idVehicle *)idEntity::CastTo(c: v7);
  else
    v8 = nullptr;
  v10 = (unsigned __int8)idVehicle::IsTypeOf(c: v8) != 0;
  result = (idVehicle_Car *)v8;
  if ( !v10 )
    return v5;
  return result;
}


// ========================================================================
// ?Boost@idVehicleAI@@QAAXH_N@Z
// EA  : 0x82B0E940
// RVA : 0x00B0E940
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::Boost(idVehicleAI *this, int ms, bool affectVelocity)
{
  int v6; // r3
  BOOL boostAltersVelocity; // r9
  bool v8; // r11
  int value; // r9
  idVehicle_Car *v10; // r3
  idVehicle_Car *v11; // r3
  idPresentable *presentable; // r3
  idPresentableVehicle *v13; // r3

  if ( this->boostTime < gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + ms )
  {
    v6 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    boostAltersVelocity = this->setup.boostAltersVelocity;
    this->boostTime = v6 + ms;
    if ( !boostAltersVelocity || (v8 = true, !affectVelocity) )
      v8 = false;
    this->boostAltersVelocity = v8;
  }
  value = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v10 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v10 != nullptr )
    {
      v11 = idVehicle_Car::CastTo(c: v10);
      if ( v11 != nullptr )
      {
        presentable = v11->presentable;
        if ( presentable != nullptr )
        {
          v13 = presentable->GetVehicleInterface(this: presentable);
          idPresentableVehicle::StartBoostFX(this: v13);
        }
        else
        {
          idPresentableVehicle::StartBoostFX(this: nullptr);
        }
      }
    }
  }
}


// ========================================================================
// ?Event_Boost@idVehicleAI@@QAA?AVeventVoid@@H@Z
// EA  : 0x82B0EA48
// RVA : 0x00B0EA48
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

idVehicleAI *__fastcall idVehicleAI::Event_Boost(idVehicleAI *this, idVehicleAI *result, int ms)
{
  idVehicleAI::Boost(this: result, ms, affectVelocity: true);
  return this;
}


// ========================================================================
// ?SetEnemy@idVehicleAI@@QAAXPAVidEntity@@@Z
// EA  : 0x82B0EA88
// RVA : 0x00B0EA88
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::SetEnemy(idVehicleAI *this, idEntity *enemy)
{
  idNavPathPosTracker *enemyTracker; // r3
  idNavPathPosTracker *Tracker; // r3
  idNavPathPosTracker *v6; // r3

  enemyTracker = this->enemyTracker;
  if ( enemyTracker != nullptr && idNavPathPosTracker::GetOwner(this: enemyTracker) != enemy )
    this->setup.engage.alertSoundTime = 0;
  if ( enemy != nullptr )
  {
    Tracker = idNavSplinePathMgr::FindTracker(this: this->splinePathMgr, owner: enemy, createTrackerIfNotFound: false);
    this->enemyTracker = Tracker;
    if ( Tracker == nullptr )
    {
      v6 = idNavSplinePathMgr::FindTracker(this: this->splinePathMgr, owner: enemy, createTrackerIfNotFound: true);
      this->enemyTracker = v6;
      idNavPathPosTracker::Init(this: v6, pathName: nullptr, owner: enemy);
    }
    this->target.spawnId.value = (gameLocal->spawnIds.ptr[enemy->entityNumber] << 13) | enemy->entityNumber;
  }
  else
  {
    this->enemyTracker = nullptr;
    this->target.spawnId.value = 0x1FFF;
  }
}


// ========================================================================
// ?CheckForStuck@idVehicleAI@@QAA_NM@Z
// EA  : 0x82B0EB40
// RVA : 0x00B0EB40
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

int __fastcall idVehicleAI::CheckForStuck(idVehicleAI *this, double dSpeed)
{
  int value; // r10
  idVehicle_Car *v4; // r3
  bool v5; // r11
  int valueInteger; // r30

  if ( vai_noMovement.valueInteger == 0 )
  {
    value = this->vehicleCar.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
    {
      v4 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
      if ( v4 != nullptr && idVehicle_Car::CastTo(c: v4) != nullptr )
      {
        v5 = false;
        if ( __fabs(this->desiredSpeed) > 10.0 )
          v5 = __fabs(this->actualSpeed) < 2.0;
        if ( v5 )
        {
          if ( this->stuckTime == 0 )
          {
            this->stuckTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
            return 0;
          }
          valueInteger = vai_stuckBlowupTime.valueInteger;
          if ( gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - this->stuckTime > valueInteger )
          {
            this->stuckTime = 0;
            return 1;
          }
        }
        else
        {
          this->stuckTime = 0;
        }
      }
    }
  }
  return 0;
}


// ========================================================================
// ?ShouldRunAway@idVehicleAI@@QAA_NXZ
// EA  : 0x82B0EC78
// RVA : 0x00B0EC78
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

int __fastcall idVehicleAI::ShouldRunAway(idVehicleAI *this)
{
  idNavPathPosTracker *enemyTracker; // r3
  idEntity *Owner; // r3
  idEntity *v5; // r29
  idPhysics *Physics; // r3
  int value; // r10
  idPhysics *v8; // r31
  idVehicle_Car *v9; // r3
  idVehicle_Car *v10; // r3
  idPhysics *v11; // r27
  float *v12; // r31
  float *v13; // r3
  double v14; // fp0
  double v15; // fp8
  double v16; // fp7
  double v17; // fp31
  double v18; // fp1
  double v19; // fp6
  double v20; // fp31
  int v21; // r31
  idPhysics *v22; // r3
  float *v23; // r3
  double z; // fp30
  double y; // fp29
  double x; // fp28
  idVehicle_Car *VehicleCar; // r3
  idPhysics *v28; // r3
  float *v29; // r3
  int (*GetGameMs)(void); // ctr
  idVec3 v31; // [sp+50h] [-60h] BYREF

  if ( !this->setup.canRunAway )
    return 0;
  enemyTracker = this->enemyTracker;
  if ( enemyTracker == nullptr )
    return 0;
  Owner = idNavPathPosTracker::GetOwner(this: enemyTracker);
  v5 = Owner;
  if ( Owner == nullptr )
    return 0;
  Physics = idEntity::GetPhysics(this: Owner);
  value = this->vehicleCar.spawnId.value;
  v8 = Physics;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v9 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v10 = idVehicle_Car::CastTo(c: v9);
  }
  else
  {
    v10 = nullptr;
  }
  v11 = idEntity::GetPhysics(this: v10);
  v12 = (float *)v8->GetOrigin(this: v8, a2: 0);
  v13 = (float *)v11->GetOrigin(this: v11, a2: 0);
  v14 = (float)(v13[2] - v12[2]);
  v15 = (float)(*v13 - *v12);
  v16 = (float)(v13[1] - v12[1]);
  v31.z = v13[2] - v12[2];
  v31.x = v15;
  v31.y = v16;
  v17 = v14;
  v18 = idVec3::NormalizeFast(this: &v31);
  v19 = __fabs(v17);
  v20 = v18;
  v21 = 1;
  if ( v19 > 300.0 )
    goto LABEL_14;
  if ( idNavPathPosTracker::GetCurrentSpeedInMPH(this: this->enemyTracker) < 30.0 )
    goto LABEL_14;
  if ( v20 > 3000.0 )
    goto LABEL_14;
  v22 = idEntity::GetPhysics(this: v5);
  v23 = (float *)v22->GetAxis(this: v22, a2: 0);
  z = v31.z;
  y = v31.y;
  x = v31.x;
  if ( (float)((float)(*v23 * v31.x) + (float)((float)(v23[1] * v31.y) + (float)(v23[2] * v31.z))) < 0.0
    || (VehicleCar = idVehicleAI::GetVehicleCar(this),
        v28 = idEntity::GetPhysics(this: VehicleCar),
        v29 = (float *)v28->GetAxis(this: v28, a2: 0),
        (float)((float)((float)x * *v29) + (float)((float)(v29[1] * (float)y) + (float)(v29[2] * (float)z))) < 0.0) )
  {
LABEL_14:
    v21 = 0;
  }
  if ( this->attackFSM.curState == &this->as_RunAway )
  {
    if ( (_BYTE)v21 == 0 )
    {
      GetGameMs = (int (*)(void))gameLocal->GetGameMs;
      if ( this->runawayTime == 0 )
      {
        this->runawayTime = GetGameMs();
        return 1;
      }
      if ( GetGameMs() - this->runawayTime < 1000 )
        return 1;
    }
  }
  else
  {
    this->runawayTime = 0;
  }
  return v21;
}


// ========================================================================
// ?IsValid@idVehicleAI@@QAA_NXZ
// EA  : 0x82B0F458
// RVA : 0x00B0F458
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

int __fastcall idVehicleAI::IsValid(idVehicleAI *this)
{
  idNavPathPosTracker *splineTracker; // r3
  unsigned __int8 v3; // r11

  if ( idVehicleAI::GetOwner(this) == nullptr )
    return 0;
  splineTracker = this->splineTracker;
  if ( splineTracker == nullptr )
    return 0;
  if ( idNavPathPosTracker::GetOwner(this: splineTracker) == nullptr )
    return 0;
  v3 = 1;
  if ( this->splineTracker->pathPosition.navSpline == nullptr )
    return 0;
  return v3;
}


// ========================================================================
// ?GetHealth@idVehicleAI@@UBAMXZ
// EA  : 0x82B0F4C0
// RVA : 0x00B0F4C0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

float __fastcall idVehicleAI::GetHealth(idVehicleAI *this)
{
  double v2; // fp1
  idVehicle_Car *Owner; // r3
  idVehicle *v4; // r3
  float (*GetHealth)(void); // r10
  idVehicle_Car *v6; // r3
  int v7; // r3

  if ( idVehicleAI::GetOwner(this) != nullptr )
  {
    Owner = idVehicleAI::GetOwner(this);
    v4 = idVehicle::CastTo(c: Owner);
    if ( v4 != nullptr )
    {
      GetHealth = (float (*)(void))v4->GetHealth;
LABEL_7:
      v2 = GetHealth();
      return *((float *)&v2 + 1);
    }
    v6 = idVehicleAI::GetOwner(this);
    v7 = (int)v6->GetHealthComponent_2(this: v6);
    if ( v7 != 0 )
    {
      GetHealth = *(float (**)(void))(*(_DWORD *)v7 + 60);
      goto LABEL_7;
    }
  }
  v2 = 0.0;
  return *((float *)&v2 + 1);
}


// ========================================================================
// ?ActivateBoost@idVehicleAI@@QAAXXZ
// EA  : 0x82B0F560
// RVA : 0x00B0F560
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::ActivateBoost(idVehicleAI *this)
{
  int value; // r10
  idVehicle_Car *v3; // r3
  int v4; // r9
  idVehicle_Car *v5; // r3
  idVehicle_Car *v6; // r3
  double desiredSpeed; // fp31

  value = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v3 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v3 != nullptr && idVehicle_Car::CastTo(c: v3) != nullptr )
    {
      v4 = this->vehicleCar.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v4 & 0x1FFF] == v4 >> 13
        && (v5 = (idVehicle_Car *)gameLocal->entities.ptr[v4 & 0x1FFF]) != nullptr )
      {
        v6 = idVehicle_Car::CastTo(c: v5);
      }
      else
      {
        v6 = nullptr;
      }
      desiredSpeed = this->desiredSpeed;
      if ( desiredSpeed >= ((double (__fastcall *)(idVehicle_Car *))v6->GetMaxSpeed)(a1: v6) && desiredSpeed >= 100.0 )
        idVehicleAI::Boost(this, ms: 150, affectVelocity: false);
    }
  }
}


// ========================================================================
// ?DrawDebug@idVehicleAI@@QAAXXZ
// EA  : 0x82B0F668
// RVA : 0x00B0F668
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idVehicleAI::DrawDebug(idVehicleAI *this, int a2, __int64 a3)
{
  __int64 v3; // r8
  char *data; // r4
  __int64 v5; // fp12
  __int64 v7; // r8
  bool v8; // r22
  int value; // r10
  idVehicle_Car *v10; // r3
  idVehicle_Car *v11; // r3
  idPhysics *Physics; // r3
  int v13; // r9
  idPhysics *v14; // r30
  idVehicle_Car *v15; // r3
  idVehicle_Car *v16; // r3
  idPhysics *v17; // r24
  idPhysics *v18; // r3
  double valueFloat; // fp30
  idRenderWorld_vtbl *v20; // r30
  const idBounds *(__fastcall *GetBounds)(idPhysics *, int); // ctr
  idBounds *v22; // r3
  double v23; // fp30
  int v24; // r3
  int v25; // r6
  idVehicle_Car *v26; // r3
  idVehicle_Car *v27; // r3
  idPhysics *v28; // r3
  int v29; // r9
  idPhysics *v30; // r30
  idVehicle_Car *v31; // r3
  idVehicle_Car *v32; // r3
  idPhysics *v33; // r26
  idPhysics *v34; // r3
  double v35; // fp30
  const idBounds *(__fastcall *v36)(idPhysics *, int); // ctr
  idRenderWorld_vtbl *v37; // r30
  idBounds *v38; // r3
  double v39; // fp30
  int v40; // r3
  __int64 v41; // r6
  double v42; // fp0
  vehicleAiSetup_t::death_t::respawnType_t respawnType; // r11
  idPresentablePlayer *LocalPresentablePlayer; // r3
  double v45; // fp10
  double v46; // fp31
  double x; // fp1
  double v48; // fp29
  double v49; // fp30
  double v50; // fp28
  double v51; // fp5
  double v52; // fp3
  double v53; // fp11
  double v54; // fp9
  double z; // fp10
  double v56; // fp8
  double v57; // fp13
  double v58; // fp11
  double v59; // fp0
  double v60; // fp12
  idStr *v61; // r3
  const char *v62; // r4
  idVehicleState *v63; // r3
  idStr *v64; // r30
  bool v65; // r28
  idVehicleState *DebugName; // r3
  const char *Classname; // r3
  idVehicleState *DebugInfo; // r3
  idPhysics *v69; // r3
  int v70; // r3
  float v71; // r28
  float v72; // r6
  float v73; // r3
  idPhysics *v74; // r3
  float *v75; // r3
  idPhysics *v76; // r3
  float *v77; // r3
  float v78[6]; // [sp+68h] [-228h] BYREF
  float v79[4]; // [sp+80h] [-210h] BYREF
  idVec3 v80; // [sp+90h] [-200h] BYREF
  float v81; // [sp+A0h] [-1F0h] BYREF
  float v82; // [sp+A4h] [-1ECh]
  float v83; // [sp+A8h] [-1E8h]
  float v84; // [sp+ACh] [-1E4h]
  float v85[4]; // [sp+B0h] [-1E0h] BYREF
  float v86[4]; // [sp+C0h] [-1D0h] BYREF
  float v87[4]; // [sp+D0h] [-1C0h] BYREF
  float v88[4]; // [sp+E0h] [-1B0h] BYREF
  idStr v89; // [sp+F0h] [-1A0h] BYREF
  idStr v90; // [sp+110h] [-180h] BYREF
  idStr v91; // [sp+130h] [-160h] BYREF
  idStr v92; // [sp+150h] [-140h] BYREF
  idStr v93; // [sp+170h] [-120h] BYREF
  idStr v94; // [sp+190h] [-100h] BYREF
  idVehicleState v95; // [sp+1B0h] [-E0h] BYREF

  LODWORD(v3) = (unsigned __int8)this;
  data = this->name.data;
  HIDWORD(v3) = BYTE2(this);
  v5 = *(__int64 *)((char *)&a3 - 4);
  LODWORD(a3) = BYTE1(this);
  v84 = 1.0;
  v83 = (float)a3 * (float)0.0039215689;
  v81 = (float)v3 * (float)0.0039215689;
  v82 = (float)v5 * (float)0.0039215689;
  HIDWORD(v7) = _cntlzw(idStr::Icmp(s1: vai_follow.valueString.data, s2: data));
  v8 = (v7 & 0x2000000000LL) != 0;
  if ( this->pathType == VEHICLE_PATH_SPLINE
    && (vai_showPath.valueFloat == 1.0 || vai_showPath.valueFloat == 2.0 && (v7 & 0x2000000000LL) != 0) )
  {
    value = this->vehicleCar.spawnId.value;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v10 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v11 = idVehicle_Car::CastTo(c: v10);
    }
    else
    {
      v11 = nullptr;
    }
    Physics = idEntity::GetPhysics(this: v11);
    v13 = this->vehicleCar.spawnId.value;
    v14 = Physics;
    if ( gameLocal->spawnIds.ptr[v13 & 0x1FFF] == v13 >> 13
      && (v15 = (idVehicle_Car *)gameLocal->entities.ptr[v13 & 0x1FFF]) != nullptr )
    {
      v16 = idVehicle_Car::CastTo(c: v15);
    }
    else
    {
      v16 = nullptr;
    }
    v17 = idEntity::GetPhysics(this: v16);
    v18 = v14;
    v88[3] = v84 * (float)0.5;
    v88[2] = v83 * (float)0.5;
    v88[1] = v82 * (float)0.5;
    v88[0] = v81 * (float)0.5;
    valueFloat = vai_fwdObsScale.valueFloat;
    GetBounds = v14->GetBounds;
    v20 = clientGame->renderWorld->__vftable;
    v22 = (idBounds *)GetBounds(this: v18, a2: -1);
    v23 = (float)(idBounds::GetRadius(this: v22) * (float)valueFloat);
    v24 = (int)v17->GetOrigin(this: v17, a2: 0);
    ((void (__fastcall *)(idRenderWorld *, float *, int, idVec3 *, double))v20->DebugCircle)(
      a1: clientGame->renderWorld,
      a2: v88,
      a3: v24,
      a4: &vec3_up,
      a5: v23);
    v25 = this->vehicleCar.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v25 & 0x1FFF] == v25 >> 13
      && (v26 = (idVehicle_Car *)gameLocal->entities.ptr[v25 & 0x1FFF]) != nullptr )
    {
      v27 = idVehicle_Car::CastTo(c: v26);
    }
    else
    {
      v27 = nullptr;
    }
    v28 = idEntity::GetPhysics(this: v27);
    v29 = this->vehicleCar.spawnId.value;
    v30 = v28;
    if ( gameLocal->spawnIds.ptr[v29 & 0x1FFF] == v29 >> 13
      && (v31 = (idVehicle_Car *)gameLocal->entities.ptr[v29 & 0x1FFF]) != nullptr )
    {
      v32 = idVehicle_Car::CastTo(c: v31);
    }
    else
    {
      v32 = nullptr;
    }
    v33 = idEntity::GetPhysics(this: v32);
    v34 = v30;
    v35 = vai_rtObsScale.valueFloat;
    v36 = v30->GetBounds;
    v37 = clientGame->renderWorld->__vftable;
    v38 = (idBounds *)v36(this: v34, a2: -1);
    v39 = (float)(idBounds::GetRadius(this: v38) * (float)v35);
    v40 = (int)v33->GetOrigin(this: v33, a2: 0);
    ((void (__fastcall *)(idRenderWorld *, float *, int, idVec3 *, double))v37->DebugCircle)(
      a1: clientGame->renderWorld,
      a2: &v81,
      a3: v40,
      a4: &vec3_up,
      a5: v39);
    idVehicleAI::DrawSplineDebug(this, a2: v41);
  }
  LODWORD(v7) = vai_showRespawnRadius.valueInteger;
  v42 = (float)v7;
  if ( v42 == 1.0 || v42 == 2.0 && v8 )
  {
    respawnType = this->setup.death.respawnType;
    if ( respawnType == RESPAWN_AT_SPAWN_POINT )
    {
      LocalPresentablePlayer = idClientGame::GetLocalPresentablePlayer(this: clientGame);
      v45 = (float)(LocalPresentablePlayer->origin.y - this->startingOrigin.y);
      v80.x = LocalPresentablePlayer->origin.x - this->startingOrigin.x;
      v80.z = 0.0;
      v80.y = v45;
      v46 = idVec3::NormalizeFast(this: &v80);
      ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, idVec3 *, double))clientGame->renderWorld->DebugCircle)(
        a1: clientGame->renderWorld,
        a2: &idColor::colorRed,
        a3: &this->startingOrigin,
        a4: &vec3_up,
        a5: this->setup.death.minBackgroundDistance);
      ((void (__fastcall *)(idRenderWorld *, idColor *, idVec3 *, idVec3 *, double))clientGame->renderWorld->DebugCircle)(
        a1: clientGame->renderWorld,
        a2: &idColor::colorYellow,
        a3: &this->startingOrigin,
        a4: &vec3_up,
        a5: this->setup.death.minBackgroundViewDistance);
      x = this->startingOrigin.x;
      v48 = (float)((float)(vec3_up.y * v80.x) - (float)(v80.y * vec3_up.x));
      v49 = (float)((float)(vec3_up.z * v80.y) - (float)(vec3_up.y * v80.z));
      v50 = (float)((float)(vec3_up.x * v80.z) - (float)(vec3_up.z * v80.x));
      v51 = (float)((float)((float)(vec3_up.z * v80.y) - (float)(vec3_up.y * v80.z))
                  * this->setup.death.minBackgroundViewDistance);
      v52 = (float)((float)((float)((float)(vec3_up.x * v80.z) - (float)(vec3_up.z * v80.x))
                          * this->setup.death.minBackgroundViewDistance)
                  + this->startingOrigin.y);
      v85[2] = this->startingOrigin.z
             + (float)((float)((float)(vec3_up.y * v80.x) - (float)(v80.y * vec3_up.x))
                     * this->setup.death.minBackgroundViewDistance);
      v85[1] = v52;
      v85[0] = (float)v51 + (float)x;
      clientGame->renderWorld->DebugLine(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&idColor::colorGreen,
        a3: &this->startingOrigin,
        a4: (const idVec3 *)v85,
        a5: 0,
        a6: false);
      v94.allocedAndFlag = 20;
      v94.len = 0;
      v94.data = v94.baseBuffer;
      v94.baseBuffer[0] = 0;
      idStr::Format(this: &v94, fmt: "%.0f", this->setup.death.minBackgroundDistance);
      v53 = (float)(this->setup.death.minBackgroundDistance * (float)v48);
      v54 = (float)(this->setup.death.minBackgroundDistance * (float)v49);
      z = this->startingOrigin.z;
      v56 = this->startingOrigin.x;
      v86[1] = (float)(this->setup.death.minBackgroundDistance * (float)v50) + this->startingOrigin.y;
      v86[2] = (float)z + (float)v53;
      v86[0] = (float)v54 + (float)v56;
      ((void (__fastcall *)(idRenderWorld *, char *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
        a1: clientGame->renderWorld,
        a2: v94.data,
        a3: v86,
        a4: clientGame->renderWorld->DebugText,
        a5: &idColor::colorWhite,
        a6: 1,
        a7: 0,
        a8: 0,
        a9: vai_showRespawnTextSize.valueFloat);
      v92.allocedAndFlag = 20;
      v92.len = 0;
      v92.data = v92.baseBuffer;
      v92.baseBuffer[0] = 0;
      idStr::Format(this: &v92, fmt: "%.0f", this->setup.death.minBackgroundViewDistance);
      v57 = this->startingOrigin.x;
      v58 = this->startingOrigin.z;
      v59 = (float)(this->setup.death.minBackgroundViewDistance * (float)v49);
      v60 = (float)(this->setup.death.minBackgroundViewDistance * (float)v48);
      v87[1] = (float)(this->setup.death.minBackgroundViewDistance * (float)v50) + this->startingOrigin.y;
      v87[0] = (float)v59 + (float)v57;
      v87[2] = (float)v58 + (float)v60;
      ((void (__fastcall *)(idRenderWorld *, char *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
        a1: clientGame->renderWorld,
        a2: v92.data,
        a3: v87,
        a4: clientGame->renderWorld->DebugText,
        a5: &idColor::colorWhite,
        a6: 1,
        a7: 0,
        a8: 0,
        a9: vai_showRespawnTextSize.valueFloat);
      v93.allocedAndFlag = 20;
      v93.len = 0;
      v93.data = v93.baseBuffer;
      v93.baseBuffer[0] = 0;
      idStr::Format(this: &v93, fmt: "%.0f", v46);
      ((void (__fastcall *)(idRenderWorld *, char *, idVec3 *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
        a1: clientGame->renderWorld,
        a2: v93.data,
        a3: &this->startingOrigin,
        a4: clientGame->renderWorld->DebugText,
        a5: &idColor::colorWhite,
        a6: 1,
        a7: 0,
        a8: 0,
        a9: vai_showRespawnTextSize.valueFloat);
      idStr::FreeData(this: &v93);
      idStr::FreeData(this: &v92);
      v61 = &v94;
LABEL_35:
      idStr::FreeData(this: v61);
      goto LABEL_36;
    }
    v90.allocedAndFlag = 20;
    v90.len = 0;
    v90.data = v90.baseBuffer;
    v90.baseBuffer[0] = 0;
    if ( respawnType != NO_RESPAWN )
    {
      if ( respawnType == DO_NOTHING )
      {
        v62 = "DO_NOTHING";
      }
      else
      {
        if ( respawnType != RESPAWN_NEAR_DEATHSPOT )
        {
LABEL_34:
          ((void (__fastcall *)(idRenderWorld *, char *, idVec3 *, idRenderWorld_vtbl *, idColor *, int, _DWORD, _DWORD, double))clientGame->renderWorld->DebugText)(
            a1: clientGame->renderWorld,
            a2: v90.data,
            a3: &this->startingOrigin,
            a4: clientGame->renderWorld->__vftable,
            a5: &idColor::colorWhite,
            a6: 1,
            a7: 0,
            a8: 0,
            a9: vai_showRespawnTextSize.valueFloat);
          v61 = &v90;
          goto LABEL_35;
        }
        v62 = "RESPAWN_NEAR_DEATHSPOT";
      }
    }
    else
    {
      v62 = "NO_RESPAWN";
    }
    idStr::operator=(this: &v90, text: v62);
    goto LABEL_34;
  }
LABEL_36:
  if ( vai_debug_attackstate.valueInteger != 0 )
  {
    v89.allocedAndFlag = 20;
    v89.data = v89.baseBuffer;
    v89.len = 0;
    v79[0] = idColor::colorRed.r;
    v89.baseBuffer[0] = 0;
    v79[1] = idColor::colorRed.g;
    v79[2] = idColor::colorRed.b;
    v79[3] = idColor::colorRed.a;
    v91.allocedAndFlag = 20;
    v91.data = v91.baseBuffer;
    v91.len = 0;
    v91.baseBuffer[0] = 0;
    v63 = idVehicleState::CastTo(c: (idVehicleState *)this->attackFSM.curState);
    v64 = (idStr *)v63;
    if ( v63 != nullptr )
    {
      v65 = idVehicleState::GetDebugName(this: &v95, result: (const idStr *)v63)->__vftable != nullptr;
      idStr::FreeData(this: (idStr *)&v95);
      if ( v65 )
      {
        DebugName = idVehicleState::GetDebugName(this: (idVehicleState *)&v95.debugName, result: v64);
        idStr::operator=(this: &v89, text: (const char *)DebugName->listenerList);
        idStr::FreeData(this: &v95.debugName);
      }
      else
      {
        Classname = idClass::GetClassname(this: (idClass *)v64);
        idStr::operator=(this: &v89, text: Classname);
      }
      DebugInfo = idVehicleState::GetDebugInfo(this: (idVehicleState *)&v95.debugInfo, result: v64);
      idStr::operator=(this: &v91, text: (const char *)DebugInfo->listenerList);
      idStr::FreeData(this: &v95.debugInfo);
    }
    else
    {
      idStr::operator=(this: &v89, text: "NO ATTACK STATE");
    }
    v69 = idEntity::GetPhysics(this);
    v70 = (int)v69->GetOrigin(this: v69, a2: 0);
    v71 = *(float *)v70;
    v72 = *(float *)(v70 + 8);
    v73 = *(float *)(v70 + 4);
    v78[0] = v71;
    v78[1] = v73;
    v78[2] = vai_debug_attackstate_zoffset.valueFloat + v72;
    ((void (__fastcall *)(idRenderWorld *, char *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), float *, int, _DWORD, int, double))clientGame->renderWorld->DebugText)(
      a1: clientGame->renderWorld,
      a2: v89.data,
      a3: v78,
      a4: clientGame->renderWorld->DebugText,
      a5: v79,
      a6: 1,
      a7: 0,
      a8: 1,
      a9: vai_debug_attackstate_textscale.valueFloat);
    if ( v91.len != 0 )
    {
      v79[0] = idColor::colorGreen.r;
      v79[1] = idColor::colorGreen.g;
      v79[2] = idColor::colorGreen.b;
      v79[3] = idColor::colorGreen.a;
      v74 = idEntity::GetPhysics(this);
      v75 = (float *)v74->GetOrigin(this: v74, a2: 0);
      v78[0] = *v75;
      v78[1] = v75[1];
      v78[2] = v75[2] + vai_debug_attackstate_zoffset2.valueFloat;
      ((void (__fastcall *)(idRenderWorld *, char *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), float *, int, _DWORD, int, double))clientGame->renderWorld->DebugText)(
        a1: clientGame->renderWorld,
        a2: v91.data,
        a3: v78,
        a4: clientGame->renderWorld->DebugText,
        a5: v79,
        a6: 1,
        a7: 0,
        a8: 1,
        a9: vai_debug_attackstate_textscale2.valueFloat);
    }
    if ( this->debugFireInfo.len != 0 )
    {
      v79[0] = idColor::colorRed.r;
      v79[1] = idColor::colorRed.g;
      v79[2] = idColor::colorRed.b;
      v79[3] = idColor::colorRed.a;
      v76 = idEntity::GetPhysics(this);
      v77 = (float *)v76->GetOrigin(this: v76, a2: 0);
      v78[0] = *v77;
      v78[1] = v77[1];
      v78[2] = v77[2] + vai_debug_attackstate_zoffset3.valueFloat;
      ((void (__fastcall *)(idRenderWorld *, char *, float *, void (__fastcall *)(idRenderWorld *, const char *, const idVec3 *, float, const idVec4 *, const int, const int, const bool, const bool), float *, int, _DWORD, int, double))clientGame->renderWorld->DebugText)(
        a1: clientGame->renderWorld,
        a2: this->debugFireInfo.data,
        a3: v78,
        a4: clientGame->renderWorld->DebugText,
        a5: v79,
        a6: 1,
        a7: 0,
        a8: 1,
        a9: vai_debug_attackstate_textscale3.valueFloat);
    }
    idStr::FreeData(this: &v91);
    idStr::FreeData(this: &v89);
  }
}


// ========================================================================
// __unwind$511305
// EA  : 0x82B10114
// RVA : 0x00B10114
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_511305()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 656 + 400));
}


// ========================================================================
// __unwind$511306
// EA  : 0x82B1013C
// RVA : 0x00B1013C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_511306()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 656 + 336));
}


// ========================================================================
// __unwind$511307
// EA  : 0x82B10164
// RVA : 0x00B10164
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_511307()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 656 + 368));
}


// ========================================================================
// __unwind$511308
// EA  : 0x82B1018C
// RVA : 0x00B1018C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_511308()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 656 + 272));
}


// ========================================================================
// __unwind$511309
// EA  : 0x82B101B4
// RVA : 0x00B101B4
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_511309()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 656 + 240));
}


// ========================================================================
// __unwind$511310
// EA  : 0x82B101DC
// RVA : 0x00B101DC
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_511310()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 656 + 304));
}


// ========================================================================
// __unwind$511312
// EA  : 0x82B10204
// RVA : 0x00B10204
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_511312()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 656 + 464));
}


// ========================================================================
// __unwind$511313
// EA  : 0x82B1022C
// RVA : 0x00B1022C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_511313()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 656 + 496));
}


// ========================================================================
// ?AdjustAggression@idVehicleAI@@IAAXXZ
// EA  : 0x82B10258
// RVA : 0x00B10258
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::AdjustAggression(idVehicleAI *this)
{
  double valueFloat; // fp0
  double v2; // fp13
  double v3; // fp12
  double v4; // fp11
  double v5; // fp0
  double v6; // fp13
  double v7; // fp12
  double v8; // fp11
  double v9; // fp0
  double v10; // fp13
  double v11; // fp12
  double v12; // fp11

  if ( vai_difficulty_mode.valueInteger != 0 )
  {
    switch ( vai_difficulty_mode.valueInteger )
    {
      case 1:
        valueFloat = vai_difficulty_damageTakenScale.valueFloat;
        v2 = vai_difficulty_accuracy.valueFloat;
        v3 = vai_difficulty_speedRate.valueFloat;
        v4 = vai_difficulty_damageScale.valueFloat;
        this->setup.difficultyLevel.attackScale = vai_difficulty_attackScale.valueFloat;
        this->setup.difficultyLevel.level = DIFFICULTY_LOW;
        this->setup.difficultyLevel.damageScale = v4;
        this->setup.difficultyLevel.speedRate = v3;
        this->setup.difficultyLevel.accuracy = v2;
        this->setup.difficultyLevel.damageTakenScale = valueFloat;
        idVehicleAI::SetDifficultyData(this, difficultyLevel: &this->setup.difficultyLevel);
        break;
      case 2:
        v5 = vai_difficulty_damageTakenScale.valueFloat;
        v6 = vai_difficulty_accuracy.valueFloat;
        v7 = vai_difficulty_speedRate.valueFloat;
        v8 = vai_difficulty_damageScale.valueFloat;
        this->setup.difficultyLevel.attackScale = vai_difficulty_attackScale.valueFloat;
        this->setup.difficultyLevel.level = DIFFICULTY_MED;
        this->setup.difficultyLevel.damageScale = v8;
        this->setup.difficultyLevel.speedRate = v7;
        this->setup.difficultyLevel.accuracy = v6;
        this->setup.difficultyLevel.damageTakenScale = v5;
        idVehicleAI::SetDifficultyData(this, difficultyLevel: &this->setup.difficultyLevel);
        break;
      case 3:
        v9 = vai_difficulty_damageTakenScale.valueFloat;
        v10 = vai_difficulty_accuracy.valueFloat;
        v11 = vai_difficulty_speedRate.valueFloat;
        v12 = vai_difficulty_damageScale.valueFloat;
        this->setup.difficultyLevel.attackScale = vai_difficulty_attackScale.valueFloat;
        this->setup.difficultyLevel.level = DIFFICULTY_HIGH;
        this->setup.difficultyLevel.damageScale = v12;
        this->setup.difficultyLevel.speedRate = v11;
        this->setup.difficultyLevel.accuracy = v10;
        this->setup.difficultyLevel.damageTakenScale = v9;
        idVehicleAI::SetDifficultyData(this, difficultyLevel: &this->setup.difficultyLevel);
        break;
      default:
        break;
    }
  }
}


// ========================================================================
// ?CalcDistanceToFinalGoal@idVehicleAI@@QAAXPAUnavSplinePath_t@@@Z
// EA  : 0x82B103A8
// RVA : 0x00B103A8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::CalcDistanceToFinalGoal(idVehicleAI *this, navSplinePath_t *path)
{
  double distance; // fp0
  double v4; // fp11
  idVehicle_Car *Owner; // r3
  idPhysics *Physics; // r3
  float *v7; // r3
  float v8[4]; // [sp+50h] [-20h] BYREF

  distance = path->distance;
  this->splineDistanceToFinalGoal = path->distance;
  v4 = __fabs(path->rightDelta);
  this->rightDistanceToFinalGoal = v4;
  this->distanceToFinalGoal = (float)distance + (float)v4;
  if ( path->path.num > 0 )
  {
    idNavSpline::GetForward(
      this: (idNavSpline *)v8,
      result: (idVec3 *)path->path.list->navSpline,
      distance: path->startDistance);
    Owner = idVehicleAI::GetOwner(this);
    Physics = idEntity::GetPhysics(this: Owner);
    v7 = (float *)Physics->GetAxis(this: Physics, a2: 0);
    if ( (float)((float)(*v7 * v8[0]) + (float)((float)(v7[1] * v8[1]) + (float)(v7[2] * v8[2]))) <= 0.0 )
      this->deltaToFinalGoal = -this->distanceToFinalGoal;
    else
      this->deltaToFinalGoal = this->distanceToFinalGoal;
  }
}


// ========================================================================
// ?DetermineSteering@idVehicleAI@@QAAMXZ
// EA  : 0x82B10488
// RVA : 0x00B10488
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

float __fastcall idVehicleAI::DetermineSteering(idVehicleAI *this)
{
  int value; // r10
  idVehicle_Car *v3; // r3
  double MaxSteerAngle; // fp1
  int forceSteeringTime; // r29
  int v6; // r9
  idVehicle_Car *v7; // r3
  idVehicle_Car *v8; // r30
  double MaxSpeed; // fp1
  double forceSteeringDir; // fp0
  idVehicle_Car *VehicleCar; // r3
  __int64 v12; // r11
  idVehicle_Car *v13; // r3
  idPhysics *Physics; // r3
  int v15; // r3
  float v16; // r7
  float v17; // r6
  double v18; // fp0
  idVehicle_Car *v19; // r3
  idPhysics *v20; // r3
  float y; // r10
  float z; // r9
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // r7
  float *v24; // r3
  double v25; // fp9
  double v26; // fp7
  double v27; // fp0
  double v28; // fp31
  idVehicle_Car *v29; // r30
  double v30; // fp1
  bool v31; // r4
  double v32; // fp1
  idNavPathPosTracker *splineTracker; // r11
  float rightDistance; // r8
  idNavSpline *navSpline; // r7
  __int64 v36; // r10
  char v37; // r3
  double v38; // fp13
  int v39; // r11
  double pitch; // fp0
  double yaw; // fp13
  double roll; // fp12
  double v43; // fp0
  double v44; // fp30
  idVehicle_Car *v45; // r3
  float v47[2]; // [sp+50h] [-A0h] BYREF
  __int64 v48; // [sp+58h] [-98h] BYREF
  float v49; // [sp+60h] [-90h]
  idAngles v50; // [sp+68h] [-88h] BYREF
  idAngles v51; // [sp+78h] [-78h] BYREF
  idVec3 v52; // [sp+88h] [-68h] BYREF
  idVec3 v53; // [sp+98h] [-58h] BYREF
  idNavSplinePosition v54; // [sp+A8h] [-48h] BYREF

  value = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13
    || (v3 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) == nullptr
    || idVehicle_Car::CastTo(c: v3) == nullptr )
  {
    MaxSteerAngle = 0.0;
    return *((float *)&MaxSteerAngle + 1);
  }
  forceSteeringTime = this->forceSteeringTime;
  if ( gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) <= forceSteeringTime )
  {
    v6 = this->vehicleCar.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v6 & 0x1FFF] == v6 >> 13
      && (v7 = (idVehicle_Car *)gameLocal->entities.ptr[v6 & 0x1FFF]) != nullptr )
    {
      v8 = idVehicle_Car::CastTo(c: v7);
    }
    else
    {
      v8 = nullptr;
    }
    MaxSpeed = idVehicleAI::GetMaxSpeed(this);
    MaxSteerAngle = idVehicle::GetMaxSteerAngle(this: v8, speed: (float)(this->actualSpeed / (float)MaxSpeed));
    forceSteeringDir = this->forceSteeringDir;
    if ( forceSteeringDir >= -MaxSteerAngle )
    {
      if ( forceSteeringDir <= MaxSteerAngle )
        MaxSteerAngle = this->forceSteeringDir;
    }
    else
    {
      MaxSteerAngle = -MaxSteerAngle;
    }
    return *((float *)&MaxSteerAngle + 1);
  }
  if ( forceSteeringTime > 0 )
  {
    this->forceSteeringTime = 0;
    VehicleCar = idVehicleAI::GetVehicleCar(this);
    if ( VehicleCar != nullptr )
      idVehicle::SetMaxSteerSpeed(this: VehicleCar, speed: this->defaultMaxSteerSpeed);
  }
  if ( this->desiredSpeed == 0.0 && __fabs(this->actualSpeed) < 0.050000001 )
  {
    this->immediateGoalAngle = 0.0;
    MaxSteerAngle = 0.0;
    return *((float *)&MaxSteerAngle + 1);
  }
  vaiTimer.calcSteering.state = TS_STARTED;
  LODWORD(v12) = (unsigned __int64)Sys_GetClockTicks() >> 32;
  vaiTimer.calcSteering.start = v12;
  v13 = idVehicleAI::GetVehicleCar(this);
  Physics = idEntity::GetPhysics(this: v13);
  v15 = (int)Physics->GetAxis(this: Physics, a2: 0);
  v16 = *(float *)(v15 + 4);
  v17 = *(float *)(v15 + 8);
  v51.pitch = *(float *)v15;
  v51.yaw = v16;
  v51.roll = v17;
  idVec3::ToAngles(this: &v52, result: &v51);
  if ( this->drivingBackwards && this->desiredSpeed < 0.0 )
  {
    if ( v52.y >= 0.0 )
      v18 = (float)(v52.y - (float)180.0);
    else
      v18 = (float)(v52.y + (float)180.0);
    v52.y = v18;
  }
  v19 = idVehicleAI::GetVehicleCar(this);
  v20 = idEntity::GetPhysics(this: v19);
  y = this->immediateGoalPosition.y;
  z = this->immediateGoalPosition.z;
  GetOrigin = v20->GetOrigin;
  *(float *)&v48 = this->immediateGoalPosition.x;
  *((float *)&v48 + 1) = y;
  v49 = z;
  v24 = (float *)GetOrigin(this: v20, a2: 0);
  v25 = (float)(v49 - v24[2]);
  v26 = (float)(*((float *)&v48 + 1) - v24[1]);
  v50.pitch = *(float *)&v48 - *v24;
  v50.roll = v25;
  v50.yaw = v26;
  idVec3::ToAngles(this: &v53, result: &v50);
  v27 = v53.y;
  if ( v53.y >= (double)(float)(v52.y - (float)180.0) )
  {
    if ( v27 <= (float)(v52.y + (float)180.0) )
      goto LABEL_31;
    v27 = (float)(v53.y - (float)360.0);
  }
  else
  {
    v27 = (float)(v53.y + (float)360.0);
  }
  v53.y = v27;
LABEL_31:
  v28 = (float)((float)(v52.y - (float)v27) * vai_turnScale.valueFloat);
  if ( this->drivingBackwards )
  {
    v28 = -v28;
  }
  else
  {
    splineTracker = this->splineTracker;
    rightDistance = splineTracker->pathPosition.rightDistance;
    navSpline = splineTracker->pathPosition.navSpline;
    v54.distance = splineTracker->pathPosition.distance;
    v54.rightDistance = rightDistance;
    v54.navSpline = navSpline;
    if ( idNavSplinePosition::GetSplineWidth(this: &v54, dist: -1.0) > (double)this->setup.narrowPathDistance
      && this->setup.turnaroundTowardsMiddle )
    {
      this->steeringOffSpline = false;
      if ( __fabs(v28) > 90.0 )
      {
        v37 = idVehicleAI::SteeringTowardsClosestEdge(this, dot: v47, turnDir: (int *)&v48);
        v38 = v47[0];
        this->steeringOffSpline = v37;
        if ( v38 >= 0.34202
          && (float)(idNavPathPosTracker::GetSplineWidth(this: this->splineTracker)
                   - (float)__fabs(this->splineTracker->pathPosition.rightDistance)) < 150.0 )
        {
          v39 = HIDWORD(v48);
          pitch = v50.pitch;
          yaw = v50.yaw;
          this->controlTurn = true;
          roll = v50.roll;
          this->controlTurnDir = v39;
          this->controlTurnVec.x = pitch;
          this->controlTurnVec.y = yaw;
          this->controlTurnVec.z = roll;
        }
      }
      if ( !this->controlTurn )
        goto LABEL_34;
      if ( (float)((float)(v51.pitch * this->controlTurnVec.x)
                 + (float)((float)(this->controlTurnVec.y * v51.yaw) + (float)(this->controlTurnVec.z * v51.roll))) < 0.70700002 )
      {
        LODWORD(v36) = this->controlTurnDir;
        v48 = v36;
        v43 = (float)v36;
        if ( v43 > 0.0 && v28 < 0.0 || v43 < 0.0 && v28 > 0.0 )
        {
          v28 = -v28;
          this->steerFlags |= 1u;
        }
        goto LABEL_34;
      }
    }
  }
  this->controlTurn = false;
LABEL_34:
  this->immediateGoalAngle = v28;
  if ( idVehicleAI::GetVehicleCar(this)->aiProperties.maxAngle != nullptr )
  {
    v29 = idVehicleAI::GetVehicleCar(this);
    v30 = idVehicleAI::GetMaxSpeed(this);
    v32 = idLookupTable::TableLookup(
            this: v29->aiProperties.maxAngle->table,
            time: (float)(this->actualSpeed / (float)v30),
            fastSearch: v31);
  }
  else
  {
    v44 = (float)(this->actualSpeed / idVehicleAI::GetMaxSpeed(this));
    v45 = idVehicleAI::GetVehicleCar(this);
    v32 = idVehicle::GetMaxSteerAngle(this: v45, speed: v44);
  }
  if ( v28 <= v32 )
  {
    if ( v28 < -v32 )
      v28 = -v32;
  }
  else
  {
    v28 = v32;
  }
  idTimer::Stop(this: &vaiTimer.calcSteering);
  MaxSteerAngle = v28;
  return *((float *)&MaxSteerAngle + 1);
}


// ========================================================================
// ?DetermineSpeed@idVehicleAI@@QAAMXZ
// EA  : 0x82B109B0
// RVA : 0x00B109B0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

float __fastcall idVehicleAI::DetermineSpeed(idVehicleAI *this)
{
  __int64 v2; // r3
  int value; // r9
  idVehicle_Car *v4; // r3
  double v5; // fp1
  int v6; // r27
  idVehicleAI *v7; // r3
  double DecelDistance; // fp1
  double v9; // fp31
  bool v11; // r4
  BOOL steeringOffSpline; // r10
  int v13; // r9
  idVehicle_Car *v14; // r3
  idVehicle_Car *v15; // r3
  double v16; // fp31
  double SpeedLimit; // fp28
  double MaxSpeed; // fp1
  idNavPathPosTracker *splineTracker; // r11
  float rightDistance; // r7
  double actualSpeed; // fp13
  idNavSpline *navSpline; // r10
  double v23; // fp31
  double v24; // fp9
  __int64 v25; // r3
  idVec3 *Forward; // r26
  double MaxCurveCosine; // fp1
  float *v28; // r8
  idNavSplinePosition *ClosestDistWithinAngle; // r3
  float v30; // r9
  idNavSpline *v31; // r8
  double v32; // fp13
  double MaxCurveSpeed; // fp1
  idNavSplinePosition v35; // [sp+68h] [-A8h] BYREF
  idVec3 v36; // [sp+78h] [-98h] BYREF
  idNavSplinePosition v37; // [sp+88h] [-88h] BYREF
  char v38; // [sp+98h] [-78h] BYREF

  vaiTimer.calcSpeed.state = TS_STARTED;
  LODWORD(v2) = (unsigned __int64)Sys_GetClockTicks() >> 32;
  vaiTimer.calcSpeed.start = v2;
  value = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13
    || (v4 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) == nullptr
    || idVehicle_Car::CastTo(c: v4) == nullptr )
  {
    v5 = 0.0;
    return *((float *)&v5 + 1);
  }
  v6 = 0;
  v7 = this;
  if ( this->actualSpeed == 0.0 )
  {
    if ( this->distanceToFinalGoal <= (double)idVehicleAI::GetMoveDistance(this) )
    {
      v6 = 4;
      goto LABEL_17;
    }
    v7 = this;
LABEL_15:
    _FP30 = idVehicleAI::GetSpeedLimit(this: v7);
    goto LABEL_18;
  }
  if ( !this->stoppingGoal )
    goto LABEL_15;
  if ( this->distanceToFinalGoal <= (double)idVehicleAI::GetStopDistance(this) )
  {
    v6 = 1;
LABEL_17:
    _FP30 = 0.0;
    goto LABEL_18;
  }
  DecelDistance = idVehicleAI::GetDecelDistance(this);
  v7 = this;
  if ( this->distanceToFinalGoal >= DecelDistance )
    goto LABEL_15;
  v9 = (float)(this->distanceToFinalGoal / idVehicleAI::GetDecelDistance(this));
  _FP30 = (float)(idVehicleAI::GetSpeedLimit(this) * (float)v9);
  if ( __fabs(_FP30) < 5.0 )
    __asm { fsel      f30, f30, f0, f13 }
  v6 = 2;
LABEL_18:
  if ( idVehicleAI::GetSpeedLimit(this) <= 0.0 )
  {
    if ( _FP30 >= idVehicleAI::GetSpeedLimit(this) )
      goto LABEL_23;
  }
  else if ( _FP30 <= idVehicleAI::GetSpeedLimit(this) )
  {
    goto LABEL_23;
  }
  _FP30 = idVehicleAI::GetSpeedLimit(this);
LABEL_23:
  steeringOffSpline = this->steeringOffSpline;
  this->turnSpeedRatio = __fabs((float)(this->immediateGoalAngle * (float)0.011111111));
  if ( !steeringOffSpline
    && this->setup.allowSlideTurn
    && idNavPathPosTracker::GetSplineWidth(this: this->splineTracker) > 200.0 )
  {
    this->turnSpeedRatio = this->turnSpeedRatio * (float)0.25;
  }
  v13 = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v13 & 0x1FFF] == v13 >> 13
    && (v14 = (idVehicle_Car *)gameLocal->entities.ptr[v13 & 0x1FFF]) != nullptr )
  {
    v15 = idVehicle_Car::CastTo(c: v14);
  }
  else
  {
    v15 = nullptr;
  }
  v16 = idLookupTable::TableLookup(
          this: v15->aiProperties.turnspeed->table,
          time: this->turnSpeedRatio,
          fastSearch: v11);
  SpeedLimit = idVehicleAI::GetSpeedLimit(this);
  if ( SpeedLimit <= idVehicleAI::GetMaxSpeed(this) )
    MaxSpeed = idVehicleAI::GetMaxSpeed(this);
  else
    MaxSpeed = idVehicleAI::GetSpeedLimit(this);
  if ( _FP30 > (float)((float)MaxSpeed * (float)v16) )
  {
    _FP30 = (float)((float)MaxSpeed * (float)v16);
    v6 = 8;
  }
  splineTracker = this->splineTracker;
  if ( splineTracker->pathToGoal.path.num != 0 )
  {
    if ( this->pathType == VEHICLE_PATH_SPLINE )
    {
      rightDistance = splineTracker->pathPosition.rightDistance;
      actualSpeed = this->actualSpeed;
      navSpline = splineTracker->pathPosition.navSpline;
      v36.x = splineTracker->pathPosition.distance;
      v36.y = rightDistance;
      LODWORD(v36.z) = navSpline;
      v23 = (float)((float)actualSpeed * (float)30.0);
      v24 = (float)((float)(splineTracker->pathToGoal.path.list->dir * (float)((float)actualSpeed * (float)30.0)) + v36.x);
      v35.navSpline = navSpline;
      v35.rightDistance = rightDistance;
      v35.distance = v24;
      idNavSplinePosition::Validate(this: &v35, path: &splineTracker->pathToGoal);
      vaiTimer.calcSpeed_distWinAngle.state = TS_STARTED;
      LODWORD(v25) = (unsigned __int64)Sys_GetClockTicks() >> 32;
      vaiTimer.calcSpeed_distWinAngle.start = v25;
      Forward = idNavSplinePosition::GetForward(this: &v37, result: &v36);
      MaxCurveCosine = idVehicleAI::GetMaxCurveCosine(this);
      ClosestDistWithinAngle = idNavSplinePathMgr::GetClosestDistWithinAngle(
                                 this: (idNavSplinePathMgr *)&v38,
                                 result: (idNavSplinePosition *)this->splinePathMgr,
                                 splinePath: (navSplinePath_t *)LODWORD(Forward->x),
                                 forward: (idVec3 *)LODWORD(Forward->y),
                                 cosangle: MaxCurveCosine,
                                 step: __fabs((float)((float)v23 * (float)0.125)),
                                 iterations: __ROL4__(LODWORD(Forward->z), 32),
                                 distanceMoved: v28);
      v30 = ClosestDistWithinAngle->rightDistance;
      v31 = ClosestDistWithinAngle->navSpline;
      v35.distance = ClosestDistWithinAngle->distance;
      v35.rightDistance = v30;
      v35.navSpline = v31;
      idTimer::Stop(this: &vaiTimer.calcSpeed_distWinAngle);
      v32 = (float)0.0;
      if ( v32 < (float)(this->splineTracker->pathToGoal.distance - (float)100.0) )
      {
        if ( v32 >= (float)((float)v23 - (float)10.0) || v32 > this->distanceToFinalGoal )
          MaxCurveSpeed = 9999.0;
        else
          MaxCurveSpeed = idVehicleAI::GetMaxCurveSpeed(this);
        if ( MaxCurveSpeed < _FP30 )
        {
          _FP30 = MaxCurveSpeed;
          v6 = 16;
        }
      }
    }
    this->speedFlags |= v6;
    idTimer::Stop(this: &vaiTimer.calcSpeed);
    v5 = _FP30;
  }
  else
  {
    idTimer::Stop(this: &vaiTimer.calcSpeed);
    v5 = 0.0;
  }
  return *((float *)&v5 + 1);
}


// ========================================================================
// ?ApplyMovement@idVehicleAI@@IAAXMMH@Z
// EA  : 0x82B10DE8
// RVA : 0x00B10DE8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::ApplyMovement(
        idVehicleAI *this,
        double speed,
        double wheelForce,
        int braking,
        int a5,
        int a6)
{
  int value; // r10
  idVehicle_Car *v11; // r3
  idVehicle_Car *v12; // r29
  double Difficulty_SpeedRate; // fp1
  idPresentable *presentable; // r3
  double v15; // fp27
  int v16; // r11
  int v17; // r31
  int v18; // r31
  int AFPhysics; // r3
  __int64 v20; // r11
  unsigned int v21; // r4
  double v22; // fp0
  double brakeForce; // fp26
  double handBrakeForce; // fp28
  int v25; // r26
  int v26; // r27
  int v27; // r28
  idPresentable *v28; // r3
  int v29; // r3
  int v30; // r9
  idVehicle_Car *v31; // r3
  idVehicle_Car *v32; // r3
  idPresentable *v33; // r3
  int v34; // r11
  double v35; // fp31
  double valueFloat; // fp31
  idPresentable *v37; // r3
  int v38; // r3
  int v39; // r9
  idPresentable *v40; // r3
  idWheelDef *v41; // r30
  int v42; // r31
  int v43; // r3
  idPresentable *v44; // r3
  int v45; // r3
  double BoostPower; // fp1
  bool boostAltersVelocity; // r11

  if ( vai_noMovement.valueInteger != 0 )
  {
    speed = 0.0;
    a6 = 3;
    wheelForce = 0.0;
  }
  value = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v11 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v11 != nullptr )
    {
      v12 = idVehicle_Car::CastTo(c: v11);
      if ( v12 != nullptr )
      {
        Difficulty_SpeedRate = idVehicleAI::GetDifficulty_SpeedRate(this);
        presentable = v12->presentable;
        v15 = (float)((float)Difficulty_SpeedRate * (float)speed);
        v16 = presentable != nullptr ? (int)presentable->GetVehicleInterface(this: presentable) : 0;
        v17 = *(_DWORD *)(v16 + 16492);
        if ( idVehicle_Car::GetNumWheelsOnGround(this: v12) >= v17 )
        {
          v18 = idVehicle::GetNumWheels(this: v12) / 2;
          if ( idVehicle_Car::GetNumWheelsOnGround(this: v12) > v18 )
          {
            if ( v15 == 0.0 )
            {
              *(_BYTE *)(idVehicle::GetAFPhysics(this: v12) + 753) = 1;
            }
            else
            {
              *(_BYTE *)(idVehicle::GetAFPhysics(this: v12) + 753) = 0;
              if ( this->lastSpeed == 0.0 || (this->thinkFlags & 2) == 0 )
              {
                AFPhysics = idVehicle::GetAFPhysics(this: v12);
                (*(void (__fastcall **)(int))(*(_DWORD *)AFPhysics + 152))(a1: AFPhysics);
              }
            }
            idVehicle_Car::SetBraking(this: v12, bl: a6 & 1);
            idVehicle_Car::SetHandBraking(this: v12, bl: (a6 & 2) != 0);
            if ( a6 == 0 )
            {
              idVehicle_Car::SetAccelerating(this: v12, bl: v15 > 0.0);
              idVehicle_Car::SetReversing(this: v12, bl: v15 < 0.0);
            }
            if ( this->revvingEngine )
            {
              HIDWORD(v20) = 1638400;
              v21 = 1664525 * clientGame->random.seed + 1013904223;
              clientGame->random.seed = v21;
              LODWORD(v20) = (v21 >> 10) & 0x7FFF;
              if ( (float)((float)v20 * (float)0.000030518509) < 0.15000001 )
              {
                v22 = this->revFrac >= 1.0 ? 0.0 : 1.0;
                this->revFrac = v22;
                if ( v22 != 0.0 )
                  idVehicleAI::Boost(this, ms: 250, affectVelocity: false);
              }
              idVehicle::UpdateCurrentThrottle(this: v12, newthrottle: this->revFrac);
              idVehicle_Car::SetAccelerating(this: v12, bl: true);
              idVehicle_Car::SetHandBraking(this: v12, bl: true);
            }
            this->appliedSpeed = v15;
            if ( vai_brakeForce.valueFloat == 0.0 )
              brakeForce = v12->aiProperties.brakeForce;
            else
              brakeForce = vai_brakeForce.valueFloat;
            if ( vai_handBrakeForce.valueFloat == 0.0 )
              handBrakeForce = v12->aiProperties.handBrakeForce;
            else
              handBrakeForce = vai_handBrakeForce.valueFloat;
            v25 = 0;
            v26 = 0;
            v27 = 0;
            while ( 1 )
            {
              v28 = v12->presentable;
              v29 = v28 != nullptr ? (int)v28->GetVehicleInterface(this: v28) : 0;
              if ( v25 >= *(_DWORD *)(v29 + 16492) )
                break;
              v30 = this->vehicleCar.spawnId.value;
              if ( gameLocal->spawnIds.ptr[v30 & 0x1FFF] == v30 >> 13
                && (v31 = (idVehicle_Car *)gameLocal->entities.ptr[v30 & 0x1FFF]) != nullptr )
              {
                v32 = idVehicle_Car::CastTo(c: v31);
              }
              else
              {
                v32 = nullptr;
              }
              v33 = v32->presentable;
              if ( v33 != nullptr )
                v34 = (int)v33->GetVehicleInterface(this: v33);
              else
                v34 = 0;
              v35 = *(float *)(v34 + 17864);
              valueFloat = (float)((float)1.0 - (float)((float)v35 / idVehicleAI::GetMaxSpeed(this)));
              if ( valueFloat >= vai_minSkidFrac.valueFloat )
              {
                if ( valueFloat > 1.0 )
                  valueFloat = 1.0;
              }
              else
              {
                valueFloat = vai_minSkidFrac.valueFloat;
              }
              v37 = v12->presentable;
              if ( v37 != nullptr )
                v38 = (int)v37->GetVehicleInterface(this: v37);
              else
                v38 = 0;
              v39 = *(_DWORD *)(v38 + 16488) + v27;
              v40 = v12->presentable;
              v41 = &v12->vehicleProps->wheels.list[v26];
              v42 = *(_DWORD *)(v39 + 4);
              if ( v40 != nullptr )
                v43 = (int)v40->GetVehicleInterface(this: v40);
              else
                v43 = 0;
              *(float *)(v42 + 536) = *(float *)(v43 + 17444) * v41->steering;
              *(float *)(v42 + 500) = 1.0;
              *(float *)(v42 + 504) = 1.0;
              if ( v41->hasHandbrake
                && ((v44 = v12->presentable) == nullptr ? (v45 = 0) : (v45 = (int)v44->GetVehicleInterface(this: v44)),
                    *(_BYTE *)(v45 + 11883) != 0) )
              {
                *(float *)(v42 + 548) = 0.0;
                *(_BYTE *)(v42 + 540) = 1;
                *(float *)(v42 + 544) = handBrakeForce;
                ++v25;
                *(float *)(v42 + 500) = valueFloat;
                v27 += 12;
                *(float *)(v42 + 504) = 1.0;
                ++v26;
              }
              else if ( v41->hasBrake && (unsigned __int8)idVehicle_Car::IsBraking(this: v12) != 0 )
              {
                *(_BYTE *)(v42 + 540) = 1;
                *(float *)(v42 + 548) = (float)v15 * (float)17.6;
                *(float *)(v42 + 544) = brakeForce;
                ++v25;
                v27 += 12;
                ++v26;
              }
              else if ( v41->hasDrive
                     && ((unsigned __int8)idVehicle_Car::IsAccelerating(this: v12) != 0
                      || (unsigned __int8)idVehicle_Car::IsReversing(this: v12) != 0) )
              {
                *(_BYTE *)(v42 + 540) = 1;
                *(float *)(v42 + 548) = (float)v15 * (float)17.6;
                *(float *)(v42 + 544) = wheelForce;
                ++v25;
                v27 += 12;
                ++v26;
              }
              else
              {
                *(_BYTE *)(v42 + 540) = 0;
                ++v25;
                v27 += 12;
                ++v26;
              }
            }
            if ( this->boostTime > 0 )
            {
              if ( this->boostTime <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
              {
                idVehicle_Car::RechargeBoost(this: v12);
                idVehicle_Car::StopBoostFX(this: v12);
                boostAltersVelocity = this->setup.boostAltersVelocity;
                this->boostTime = 0;
                this->boostAltersVelocity = boostAltersVelocity;
              }
              else if ( this->boostAltersVelocity )
              {
                if ( vehicle_boostUseRatio.valueInteger != 0 )
                  BoostPower = idVehicle_Car::GetBoostPower(this: v12);
                else
                  BoostPower = 1.0;
                idVehicle_Car::BoostForce(this: v12, f: (float)((float)BoostPower * vai_boostPower.valueFloat));
              }
            }
          }
        }
      }
    }
  }
}


// ========================================================================
// ?MoveToPathPosition@idVehicleAI@@QAAXVidNavSplinePosition@@_N1@Z
// EA  : 0x82B113D0
// RVA : 0x00B113D0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idVehicleAI::MoveToPathPosition(
        idVehicleAI *this,
        __int64 isStoppingGoal,
        bool passThroughGoal,
        bool a4,
        int a5,
        int a6,
        int a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  idNavPathPosTracker *splineTracker; // r11
  idNavPathPosTracker *p_null_splineTracker; // r10
  double SplineWidth; // fp1
  double distance; // fp0
  double rightDistance; // fp13
  double v20; // fp12
  idNavPathPosTracker *v21; // r11
  idNavSplinePosition v22; // [sp+50h] [-40h] BYREF

  splineTracker = this->splineTracker;
  a11 = *(__int64 *)((char *)&isStoppingGoal + 4);
  a12 = isStoppingGoal;
  if ( splineTracker != nullptr )
    p_null_splineTracker = splineTracker;
  else
    p_null_splineTracker = &this->splinePathMgr->null_splineTracker;
  if ( splineTracker == nullptr )
    splineTracker = &this->splinePathMgr->null_splineTracker;
  idNavSplinePosition::Validate(
    this: (idNavSplinePosition *)&a11,
    nextSpline: splineTracker->nextSpline,
    prevSpline: p_null_splineTracker->prevSpline);
  SplineWidth = idNavSplinePosition::GetSplineWidth(this: (idNavSplinePosition *)&a11, dist: -1.0);
  if ( __fabs(*((float *)&a11 + 1)) > SplineWidth )
  {
    if ( *((float *)&a11 + 1) < 0.0 )
      SplineWidth = -SplineWidth;
    *((float *)&a11 + 1) = SplineWidth;
  }
  idNavSplinePosition::GetWorldPos(this: &v22, result: (idVec3 *)&a11);
  idNavPathPosTracker::SetGoalWorldPosition(
    this: (idNavPathPosTracker *)LODWORD(v22.distance),
    pos: (idVec3 *)LODWORD(v22.rightDistance),
    pathPos: (idNavSplinePosition *)__ROL4__(v22.navSpline, 32));
  distance = v22.distance;
  rightDistance = v22.rightDistance;
  this->stoppingGoal = passThroughGoal;
  v20 = *(float *)&v22.navSpline;
  this->passThroughGoal = a4;
  this->finalGoalPosition.x = distance;
  this->finalGoalPosition.y = rightDistance;
  this->finalGoalPosition.z = v20;
  v21 = this->splineTracker;
  if ( v21 == nullptr )
    v21 = &this->splinePathMgr->null_splineTracker;
  idVehicleAI::CalcDistanceToFinalGoal(this, path: &v21->pathToGoal);
}


// ========================================================================
// ?MoveToPosition@idVehicleAI@@QAAXVidNavSplinePosition@@_N1@Z
// EA  : 0x82B114F0
// RVA : 0x00B114F0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::MoveToPosition(
        idVehicleAI *this,
        idNavSplinePosition *pathPos,
        bool isStoppingGoal,
        unsigned int passThroughGoal,
        bool a5)
{
  idNavPathPosTracker *splineTracker; // r11
  int v9; // r10
  int v10; // r9
  bool v11; // r8
  int v12; // [sp+8h] [-78h]
  __int64 v13; // [sp+10h] [-70h]
  __int64 v14; // [sp+18h] [-68h]
  __int64 v15; // [sp+20h] [-60h]
  __int64 v16; // [sp+28h] [-58h]
  __int64 v17; // [sp+30h] [-50h]

  splineTracker = this->splineTracker;
  if ( splineTracker == nullptr )
    splineTracker = &this->splinePathMgr->null_splineTracker;
  idNavPathPosTracker::SetPathTraversal(this: splineTracker, traversalType: NAVSP_SHORTEST, forceRecalcLinks: true);
  idVehicleAI::MoveToPathPosition(
    this,
    isStoppingGoal: __SPAIR64__(__ROL4__(pathPos, 32), passThroughGoal),
    passThroughGoal: a5,
    a4: v11,
    a5: v10,
    a6: v9,
    a7: v12,
    a8: v13,
    a9: v14,
    a10: v15,
    a11: v16,
    a12: v17);
}


// ========================================================================
// ?FireWeapon@idVehicleAI@@QAA_NXZ
// EA  : 0x82B11560
// RVA : 0x00B11560
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

int __fastcall idVehicleAI::FireWeapon(idVehicleAI *this)
{
  idVehicleAI *v2; // r3
  int value; // r10
  idVehicle_Car *v5; // r3
  int v6; // r9
  idVehicle_Car *v7; // r3
  idVehicle_Car *v8; // r3
  bool v9; // zf
  idStr *p_debugFireInfo; // r3

  if ( vai_nofire.valueInteger != 0 )
  {
    idStr::operator=(this: &this->debugFireInfo, text: "cvar");
    v2 = this;
LABEL_3:
    idVehicleAI::ReleaseWeaponTriggers(this: v2);
    return 0;
  }
  value = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && idVehicle_Car::CastTo(c: v5) != nullptr )
  {
    v6 = this->vehicleCar.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v6 & 0x1FFF] == v6 >> 13
      && (v7 = (idVehicle_Car *)gameLocal->entities.ptr[v6 & 0x1FFF]) != nullptr )
    {
      v8 = idVehicle_Car::CastTo(c: v7);
    }
    else
    {
      v8 = nullptr;
    }
    if ( (unsigned __int8)idVehicle::CanFireWeapons(this: v8) != 0 )
    {
      v9 = !idVehicleAI::OkToFire(this);
      v2 = this;
      if ( v9 )
        goto LABEL_3;
      v9 = (unsigned __int8)idVehicleAI::HasAmmo(this) != 0;
      p_debugFireInfo = &this->debugFireInfo;
      if ( v9 )
      {
        idStr::operator=(this: p_debugFireInfo, text: "fire");
        idVehicleAI::PullWeaponTriggers(this);
        this->weaponFiredFrame = idAccolade::Count(this: &clientGame->gameTimeManager);
        this->weaponFiredTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
        return 1;
      }
      else
      {
        idStr::operator=(this: p_debugFireInfo, text: "no ammo");
        idVehicleAI::ReleaseWeaponTriggers(this);
        return 0;
      }
    }
    else
    {
      idStr::operator=(this: &this->debugFireInfo, text: "can not");
      idVehicleAI::ReleaseWeaponTriggers(this);
      return 0;
    }
  }
  else
  {
    idStr::operator=(this: &this->debugFireInfo, text: "no car");
    idVehicleAI::ReleaseWeaponTriggers(this);
    return 0;
  }
}


// ========================================================================
// ?DebugForceAttack@idVehicleAI@@QAA_NXZ
// EA  : 0x82B11738
// RVA : 0x00B11738
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

int __fastcall idVehicleAI::DebugForceAttack(idVehicleAI *this)
{
  idState *State; // r30
  idPlayer *DebugPlayer; // r3

  if ( vai_attackState.valueInteger > 0x1Du || idStr::Icmp(s1: vai_follow.valueString.data, s2: this->name.data) != 0 )
    return 0;
  State = idFiniteStateMachine::FindState(
            this: &this->attackFSM,
            name: vehicleAttackStateNames[vai_attackState.valueInteger]);
  if ( State != nullptr )
  {
    DebugPlayer = idGameLocal::GetDebugPlayer(this: gameLocal);
    idVehicleAI::SetEnemy(this, enemy: DebugPlayer);
    if ( this->attackFSM.curState != State )
      idVehicleAI::SetAttackState(this, num: vai_attackState.valueInteger, delayTime: 0, pushState: false);
  }
  return 1;
}


// ========================================================================
// ?HandleActions@idVehicleAI@@QAAXAAUvaiAction_t@@@Z
// EA  : 0x82B117F8
// RVA : 0x00B117F8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::HandleActions(idVehicleAI *this, vaiAction_t *actions)
{
  idGameLocal *v2; // r11
  idEntity *v5; // r3
  idVehicleAI *v6; // r3
  idVehicle_Car *VehicleCar; // r31
  idVehicleAI *v8; // r3
  int v9; // r31
  int v10; // r3
  idNavPathPosTracker *enemyTracker; // r3
  int v12; // r28
  int v13; // r29
  int value; // r9
  idEntity *v15; // r3
  idVehicleAI *v16; // r3
  idEntity *v17; // r30
  idVehicleAI *v18; // r3
  idGameLocal *v19; // r11
  int v20; // r9
  idVehicle_Car *v21; // r3
  idVehicle_Car *v22; // r3
  int v23; // r9
  idEntity *v24; // r3
  idEntity *v25; // r31
  int v26; // r9
  idVehicle_Car *v27; // r3
  idVehicle_Car *v28; // r27
  idEntity *v29; // r3
  idPhysics *Physics; // r26
  idPhysics *v31; // r25
  idInventoryCollection *v32; // r28
  int v33; // r26
  int v34; // r29
  int v35; // r31
  char *data; // r30
  idInventoryItem *InventoryItem; // r3
  idVehicle_Car_vtbl *v38; // r30
  idInventoryItem *v39; // r3
  idEntity *v40; // r31
  int v41; // r9
  idEntity *v42; // r3
  idEntity *v43; // r30
  idPhysics *v44; // r30
  idPhysics *v45; // r19
  float *v46; // r30
  float *v47; // r3
  double v48; // fp0
  double v49; // fp13
  double v50; // fp12
  idPhysics *v51; // r19
  idPhysics *v52; // r30
  float *v53; // r19
  double v54; // fp12
  double v55; // fp0
  double v56; // fp13
  double valueFloat; // fp10
  double v60; // fp3
  double v61; // fp6
  double v62; // fp3
  double v63; // fp0
  double v64; // fp13
  double v65; // fp12
  idPhysics *v66; // r3
  int v67; // r29
  int v68; // r30
  idEntityPtr<idEntity> *v69; // r10
  idEntity *v70; // r3
  idEntity *v71; // r31
  idEventArg *v72; // r3
  vaiAction_t::occupantLookAt_t *p_occupantLookAt; // r31
  int v75; // r9
  idVehicle_Car *v76; // r3
  idVehicle_Car *v77; // r3
  idVehicle *v78; // r30
  int v79; // r9
  int v80; // r31
  idEntity *v81; // r3
  idEntity *v82; // r5
  int v83; // r9
  int v84; // r31
  idEntity *v85; // r3
  idEntity *v86; // r5
  double angle; // fp31
  int v88; // r31
  int v89; // r3
  int v90; // r9
  idVehicle_Car *v91; // r3
  idVehicle_Car *v92; // r3
  idPresentable *presentable; // r3
  double speed; // fp31
  int v95; // r3
  int v96; // r9
  idVehicle_Car *v97; // r3
  idVehicle_Car *v98; // r3
  idPresentable *v99; // r3
  int v100; // r31
  idPresentableVehicle *v101; // r3
  int v102; // r30
  int v103; // r31
  int v104; // r9
  idEntity *v105; // r3
  idEntity *v106; // r3
  int v107; // r9
  idVehicle_Car *v108; // r3
  idVehicle_Car *v109; // r31
  int v110; // r9
  idVehicle_Car *v111; // r3
  idVehicle_Car *v112; // r3
  int v113; // r9
  idVehicle_Car *v114; // r3
  idVehicle_Car *v115; // r3
  idVehicle_Car *v116; // r31
  idPresentable *v117; // r3
  idPresentableVehicle *v118; // r3
  idPresentable *v119; // r3
  idPresentableVehicle *v120; // r3
  int v121; // r30
  int v122; // r31
  int v123; // r9
  idEntity *v124; // r3
  idVehicle_Car *v125; // r3
  idVehicle_Car *v126; // r3
  int v127; // r9
  idEntity *v128; // r3
  idVehicleAI *v129; // r3
  idVehicleAI *v130; // r3
  int v131; // r9
  idVehicle_Car *v132; // r3
  int v133; // r30
  int v134; // r31
  int v135; // r9
  idEntity *v136; // r3
  idVehicle_Car *v137; // r3
  idVehicle_Car *v138; // r3
  int v139; // r9
  idEntity *v140; // r3
  idVehicleAI *v141; // r3
  idVehicleAI *v142; // r3
  int v143; // r9
  idVehicle_Car *v144; // r3
  int v145; // r30
  int v146; // r31
  int v147; // r9
  idEntity *v148; // r3
  idVehicle_Car *v149; // r3
  idVehicle_Car *v150; // r3
  int v151; // r9
  idEntity *v152; // r3
  idVehicleAI *v153; // r3
  idVehicleAI *v154; // r3
  int v155; // r9
  idVehicle_Car *v156; // r3
  double verticalImpulse; // fp0
  int v158; // r9
  idVehicle_Car *v159; // r3
  int v160; // r8
  int v161; // r31
  idVehicle_Car *v162; // r3
  idVehicle_Car *v163; // r3
  float v164; // [sp+68h] [-C8h] BYREF
  float v165; // [sp+6Ch] [-C4h]
  float v166; // [sp+70h] [-C0h]
  idEventArg v167[3]; // [sp+80h] [-B0h] BYREF

  v2 = gameLocal;
  if ( gameLocal->spawnIds.ptr[actions->fireAtEnemy.enemy.spawnId.value & 0x1FFF] == actions->fireAtEnemy.enemy.spawnId.value >> 13 )
  {
    v5 = gameLocal->entities.ptr[actions->fireAtEnemy.enemy.spawnId.value & 0x1FFF];
    if ( v5 != nullptr && (v6 = (idVehicleAI *)idEntity::CastTo(c: v5), VehicleCar = (idVehicle_Car *)v6, v6 != nullptr) )
    {
      v8 = idVehicleAI::CastTo(c: v6);
      if ( v8 != nullptr )
        VehicleCar = idVehicleAI::GetVehicleCar(this: v8);
      idVehicleAI::SetEnemy(this, enemy: VehicleCar);
      if ( VehicleCar != nullptr )
        this->target.spawnId.value = (gameLocal->spawnIds.ptr[VehicleCar->entityNumber] << 13)
                                   | VehicleCar->entityNumber;
      else
        this->target.spawnId.value = 0x1FFF;
      idVehicleAI::SetAttackState(this, stateType: &idVS_as_FireWeapon::Type, delayTime: 0, pushState: false);
      if ( actions->fireAtEnemy.time > 0.0 )
      {
        v9 = (int)(float)(actions->fireAtEnemy.time * (float)1000.0);
        v10 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
        this->as_FireWeapon.endTime = v10 + v9;
        if ( v10 + v9 < 0 )
          this->as_FireWeapon.endTime = 9999000;
      }
    }
    else
    {
      enemyTracker = this->enemyTracker;
      if ( enemyTracker != nullptr && idNavPathPosTracker::GetOwner(this: enemyTracker) != nullptr )
        this->setup.engage.alertSoundTime = 0;
      this->enemyTracker = nullptr;
      this->target.spawnId.value = 0x1FFF;
      this->target.spawnId.value = 0x1FFF;
      idVehicleAI::SetAttackState(this, stateType: &idVS_Idle::Type, delayTime: 0, pushState: false);
    }
    v2 = gameLocal;
  }
  if ( actions->aiGoIdle.activate && actions->aiGoIdle.goIdle )
  {
    idVehicleAI::StopControllingVehicle(this);
    v2 = gameLocal;
  }
  if ( actions->damageEntity.entityList.num > 0 )
  {
    v12 = 0;
    v13 = 0;
    do
    {
      value = actions->damageEntity.entityList.list[v13].spawnId.value;
      if ( v2->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
      {
        v15 = v2->entities.ptr[value & 0x1FFF];
        if ( v15 != nullptr )
        {
          v16 = (idVehicleAI *)idEntity::CastTo(c: v15);
          v17 = v16;
          if ( v16 != nullptr )
          {
            v18 = idVehicleAI::CastTo(c: v16);
            v19 = gameLocal;
            if ( v18 != nullptr )
            {
              v20 = v18->vehicleCar.spawnId.value;
              if ( gameLocal->spawnIds.ptr[v20 & 0x1FFF] == v20 >> 13
                && (v21 = (idVehicle_Car *)gameLocal->entities.ptr[v20 & 0x1FFF]) != nullptr )
              {
                v22 = idVehicle_Car::CastTo(c: v21);
                v19 = gameLocal;
              }
              else
              {
                v22 = nullptr;
              }
              v17 = v22;
            }
            v23 = actions->damageEntity.attacker.spawnId.value;
            if ( v19->spawnIds.ptr[v23 & 0x1FFF] == v23 >> 13 && (v24 = v19->entities.ptr[v23 & 0x1FFF]) != nullptr )
            {
              v29 = idEntity::CastTo(c: v24);
              v25 = v29;
              if ( v29 != nullptr )
              {
                Physics = idEntity::GetPhysics(this: v29);
                v31 = idEntity::GetPhysics(this: v17);
                Physics->GetOrigin(this: Physics, a2: 0);
                v31->GetOrigin(this: v31, a2: 0);
              }
            }
            else
            {
              v25 = nullptr;
            }
            ((void (__fastcall *)(idEntity *, idEntity *, idEntity *, const idDeclDamage *, double))v17->Damage)(
              a1: v17,
              a2: v25,
              a3: v25,
              a4: this->declPreload.declDamage1,
              a5: actions->damageEntity.damage);
          }
          v2 = gameLocal;
        }
      }
      ++v12;
      ++v13;
    }
    while ( v12 < actions->damageEntity.entityList.num );
  }
  if ( actions->throwAttachedItem.itemList.num > 0 )
  {
    v26 = this->vehicleCar.spawnId.value;
    if ( v2->spawnIds.ptr[v26 & 0x1FFF] == v26 >> 13
      && (v27 = (idVehicle_Car *)v2->entities.ptr[v26 & 0x1FFF]) != nullptr )
    {
      v28 = idVehicle_Car::CastTo(c: v27);
    }
    else
    {
      v28 = nullptr;
    }
    v32 = v28->GetInventory_2(this: v28);
    v33 = 0;
    if ( actions->throwAttachedItem.itemList.num > 0 )
    {
      v34 = 0;
      do
      {
        v35 = 0;
        if ( (int)idScriptObject::GetTypeDef(this: (bfx::Planner3D *)v32) > 0 )
        {
          while ( 1 )
          {
            data = actions->throwAttachedItem.itemList.list[v34].name.data;
            InventoryItem = idInventoryCollection::GetInventoryItem(this: v32, index: v35);
            if ( idStr::Find(
                   searchIn: InventoryItem->decl->name.str,
                   searchFor: data,
                   casesensitive: false,
                   start: 0,
                   end: -1) != -1 )
              break;
            if ( ++v35 >= (int)idScriptObject::GetTypeDef(this: (bfx::Planner3D *)v32) )
              goto LABEL_58;
          }
          v38 = v28->__vftable;
          v39 = idInventoryCollection::GetInventoryItem(this: v32, index: v35);
          v40 = v38->ThrowAttachedItem(this: v28, a2: v39);
          v41 = actions->throwAttachedItem.itemList.list[v34].atEntity.spawnId.value;
          if ( gameLocal->spawnIds.ptr[v41 & 0x1FFF] == v41 >> 13
            && (v42 = gameLocal->entities.ptr[actions->throwAttachedItem.itemList.list[v34].atEntity.spawnId.value
                                            & 0x1FFF]) != nullptr
            && (v43 = idEntity::CastTo(c: v42)) != nullptr )
          {
            v51 = idEntity::GetPhysics(this: v40);
            v52 = idEntity::GetPhysics(this: v43);
            v53 = (float *)v51->GetOrigin(this: v51, a2: 0);
            v47 = (float *)v52->GetOrigin(this: v52, a2: 0);
            v48 = *v53;
            v49 = v53[1];
            v50 = v53[2];
          }
          else
          {
            v44 = idEntity::GetPhysics(this: v28);
            v45 = idEntity::GetPhysics(this: v40);
            v46 = (float *)v44->GetOrigin(this: v44, a2: 0);
            v47 = (float *)v45->GetOrigin(this: v45, a2: 0);
            v48 = *v46;
            v49 = v46[1];
            v50 = v46[2];
          }
          v54 = (float)(v47[2] - (float)v50);
          v55 = (float)(*v47 - (float)v48);
          v56 = (float)(v47[1] - (float)v49);
          valueFloat = vai_throwforce.valueFloat;
          _FP6 = (float)((float)((float)((float)v56 * (float)v56)
                               + (float)((float)((float)v55 * (float)v55) + (float)((float)v54 * (float)v54)))
                       - idMath::FLT_SMALLEST_NON_DENORMAL);
          __asm { fsel      f4, f6, f7, f11 }
          v60 = __frsqrte(_FP4);
          v61 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v60
                                                                                              * (float)((float)((float)((float)v56 * (float)v56) + (float)((float)((float)v55 * (float)v55) + (float)((float)v54 * (float)v54))) * (float)0.5))
                                                                                      * (float)v60)
                                                                              - (float)1.5)
                                                              * (float)v60)
                                                      * (float)((float)((float)((float)v56 * (float)v56)
                                                                      + (float)((float)((float)v55 * (float)v55)
                                                                              + (float)((float)v54 * (float)v54)))
                                                              * (float)0.5))
                                              * (float)((float)-(float)((float)((float)((float)v60
                                                                                      * (float)((float)((float)((float)v56 * (float)v56) + (float)((float)((float)v55 * (float)v55) + (float)((float)v54 * (float)v54)))
                                                                                              * (float)0.5))
                                                                              * (float)v60)
                                                                      - (float)1.5)
                                                      * (float)v60))
                                      - (float)1.5)
                      * (float)((float)-(float)((float)((float)((float)v60
                                                              * (float)((float)((float)((float)v56 * (float)v56)
                                                                              + (float)((float)((float)v55 * (float)v55)
                                                                                      + (float)((float)v54 * (float)v54)))
                                                                      * (float)0.5))
                                                      * (float)v60)
                                              - (float)1.5)
                              * (float)v60));
          v62 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v60 * (float)((float)((float)((float)v56 * (float)v56) + (float)((float)((float)v55 * (float)v55) + (float)((float)v54 * (float)v54))) * (float)0.5)) * (float)v60) - (float)1.5) * (float)v60)
                                                                                              * (float)((float)((float)((float)v56 * (float)v56) + (float)((float)((float)v55 * (float)v55) + (float)((float)v54 * (float)v54))) * (float)0.5))
                                                                                      * (float)((float)-(float)((float)((float)((float)v60 * (float)((float)((float)((float)v56 * (float)v56) + (float)((float)((float)v55 * (float)v55) + (float)((float)v54 * (float)v54))) * (float)0.5)) * (float)v60) - (float)1.5)
                                                                                              * (float)v60))
                                                                              - (float)1.5)
                                                              * (float)((float)-(float)((float)((float)((float)v60 * (float)((float)((float)((float)v56 * (float)v56) + (float)((float)((float)v55 * (float)v55) + (float)((float)v54 * (float)v54))) * (float)0.5))
                                                                                              * (float)v60)
                                                                                      - (float)1.5)
                                                                      * (float)v60))
                                                      * (float)((float)((float)((float)v56 * (float)v56)
                                                                      + (float)((float)((float)v55 * (float)v55)
                                                                              + (float)((float)v54 * (float)v54)))
                                                              * (float)0.5))
                                              * (float)v61)
                                      - (float)1.5)
                      * (float)v61);
          v63 = (float)((float)v62 * (float)v55);
          v164 = v63;
          v64 = (float)((float)v62 * (float)v56);
          v165 = v64;
          v65 = (float)((float)v62 * (float)v54);
          v166 = v65;
          if ( vai_throwforce.valueFloat <= 0.0 )
            valueFloat = actions->throwAttachedItem.itemList.list[v34].force;
          v164 = (float)v63 * (float)valueFloat;
          v165 = (float)v64 * (float)valueFloat;
          v166 = (float)v65 * (float)valueFloat;
          v66 = idEntity::GetPhysics(this: v40);
          v66->SetLinearVelocity(this: v66, a2: (const idVec3 *)&v164, a3: 0);
        }
LABEL_58:
        ++v33;
        ++v34;
      }
      while ( v33 < actions->throwAttachedItem.itemList.num );
    }
    v2 = gameLocal;
  }
  if ( actions->trigger.targetList.num > 0 )
  {
    v67 = 0;
    v68 = 0;
    do
    {
      v69 = &actions->trigger.targetList.list[v68];
      if ( v2->spawnIds.ptr[v69->spawnId.value & 0x1FFF] == v69->spawnId.value >> 13 )
      {
        v70 = v2->entities.ptr[v69->spawnId.value & 0x1FFF];
        if ( v70 != nullptr )
          v71 = idEntity::CastTo(c: v70);
        else
          v71 = nullptr;
        v72 = idEventArg::idEventArg(this: v167, data: this);
        idEventReceiver::PostEventMS(
          this: v71,
          ev: &EV_Activate,
          time: *(_DWORD *)&v72->type,
          arg1: (const idEventArg *)LODWORD(v72->value.v[1]));
        v2 = gameLocal;
      }
      ++v67;
      ++v68;
    }
    while ( v67 < actions->trigger.targetList.num );
  }
  p_occupantLookAt = &actions->occupantLookAt;
  if ( v2->spawnIds.ptr[actions->occupantLookAt.target.spawnId.value & 0x1FFF] == actions->occupantLookAt.target.spawnId.value >> 13
    && (p_occupantLookAt->driver || actions->occupantLookAt.passenger) )
  {
    v75 = this->vehicleCar.spawnId.value;
    if ( v2->spawnIds.ptr[v75 & 0x1FFF] == v75 >> 13
      && (v76 = (idVehicle_Car *)v2->entities.ptr[v75 & 0x1FFF]) != nullptr )
    {
      v77 = idVehicle_Car::CastTo(c: v76);
      v2 = gameLocal;
      v78 = v77;
    }
    else
    {
      v78 = nullptr;
    }
    if ( p_occupantLookAt->driver )
    {
      v79 = actions->occupantLookAt.target.spawnId.value;
      v80 = (int)(float)(actions->occupantLookAt.time * (float)1000.0);
      if ( v2->spawnIds.ptr[v79 & 0x1FFF] == v79 >> 13 && (v81 = v2->entities.ptr[v79 & 0x1FFF]) != nullptr )
        v82 = idEntity::CastTo(c: v81);
      else
        v82 = nullptr;
      idVehicle::ForceOccupantLookAt(this: v78, occupantNum: 0, target: v82, time: v80);
      v2 = gameLocal;
    }
    if ( actions->occupantLookAt.passenger )
    {
      v83 = actions->occupantLookAt.target.spawnId.value;
      v84 = (int)(float)(actions->occupantLookAt.time * (float)1000.0);
      if ( v2->spawnIds.ptr[v83 & 0x1FFF] == v83 >> 13 && (v85 = v2->entities.ptr[v83 & 0x1FFF]) != nullptr )
        v86 = idEntity::CastTo(c: v85);
      else
        v86 = nullptr;
      idVehicle::ForceOccupantLookAt(this: v78, occupantNum: 1, target: v86, time: v84);
      v2 = gameLocal;
    }
  }
  if ( actions->forceSteering.time > 0.0 )
  {
    angle = actions->forceSteering.angle;
    v88 = (int)(float)(actions->forceSteering.time * (float)1000.0);
    v89 = v2->GetGameMs(this: v2, a2: GAMETIME_SCALED);
    this->forceSteeringDir = angle;
    this->forceSteeringTime = v89 + v88;
    if ( actions->forceSteering.speed != -1.0 )
    {
LABEL_99:
      v2 = gameLocal;
      goto LABEL_100;
    }
    v90 = this->vehicleCar.spawnId.value;
    v2 = gameLocal;
    if ( gameLocal->spawnIds.ptr[v90 & 0x1FFF] == v90 >> 13 )
    {
      v91 = (idVehicle_Car *)gameLocal->entities.ptr[v90 & 0x1FFF];
      if ( v91 != nullptr )
      {
        v92 = idVehicle_Car::CastTo(c: v91);
        if ( v92 != nullptr )
        {
          presentable = v92->presentable;
          speed = actions->forceSteering.speed;
          if ( presentable != nullptr )
            v95 = (int)presentable->GetVehicleInterface(this: presentable);
          else
            v95 = 0;
          *(float *)(v95 + 17448) = speed;
        }
        goto LABEL_99;
      }
    }
  }
LABEL_100:
  if ( actions->boostFx.time > 0.0 )
  {
    v96 = this->vehicleCar.spawnId.value;
    if ( v2->spawnIds.ptr[v96 & 0x1FFF] == v96 >> 13 )
    {
      v97 = (idVehicle_Car *)v2->entities.ptr[v96 & 0x1FFF];
      if ( v97 != nullptr )
      {
        v98 = idVehicle_Car::CastTo(c: v97);
        if ( v98 != nullptr )
        {
          v99 = v98->presentable;
          v100 = (int)(float)(actions->boostFx.time * (float)1000.0);
          if ( v99 != nullptr )
            v101 = v99->GetVehicleInterface(this: v99);
          else
            v101 = nullptr;
          idPresentableVehicle::ForceBoostFx(this: v101, time: v100);
        }
        v2 = gameLocal;
      }
    }
  }
  if ( actions->removeEntity.entityList.num > 0 )
  {
    v102 = 0;
    v103 = 0;
    do
    {
      v104 = actions->removeEntity.entityList.list[v103].spawnId.value;
      if ( v2->spawnIds.ptr[v104 & 0x1FFF] == v104 >> 13 )
      {
        v105 = v2->entities.ptr[v104 & 0x1FFF];
        if ( v105 != nullptr )
        {
          v106 = idEntity::CastTo(c: v105);
          if ( v106 != nullptr )
            idEventReceiver::PostEventMS(this: v106, ev: &EV_Remove, time: 0);
          v2 = gameLocal;
        }
      }
      ++v102;
      ++v103;
    }
    while ( v102 < actions->removeEntity.entityList.num );
  }
  if ( actions->vehicleCam.activate )
  {
    v107 = this->vehicleCar.spawnId.value;
    if ( v2->spawnIds.ptr[v107 & 0x1FFF] == v107 >> 13 )
    {
      v108 = (idVehicle_Car *)v2->entities.ptr[v107 & 0x1FFF];
      if ( v108 != nullptr )
      {
        v109 = idVehicle_Car::CastTo(c: v108);
        if ( v109 != nullptr )
        {
          if ( actions->vehicleCam.tagName.len != 0 )
          {
            ((void (__fastcall *)(idCVarSystem *, const char *, double))cvarSystem->SetCVarFloat)(
              a1: cvarSystem,
              a2: "vehicle_cam",
              a3: 1.0);
            cvarSystem->SetCVarString(this: cvarSystem, a2: "vehicle_follow", a3: v109->name.data, a4: 0);
            cvarSystem->SetCVarString(
              this: cvarSystem,
              a2: "vehicle_cam_tag",
              a3: actions->vehicleCam.tagName.data,
              a4: 0);
            ((void (__fastcall *)(idCVarSystem *, const char *, char *, _DWORD, double))cvarSystem->SetCVarFloat)(
              a1: cvarSystem,
              a2: "vehicle_cam_fwd",
              a3: "Could not find AI state, idVS_ds_Car_Chase! ",
              a4: 0,
              a5: actions->vehicleCam.fwdOfs);
            ((void (__fastcall *)(idCVarSystem *, const char *, double))cvarSystem->SetCVarFloat)(
              a1: cvarSystem,
              a2: "vehicle_cam_rt",
              a3: actions->vehicleCam.rtOfs);
            ((void (__fastcall *)(double))cvarSystem->SetCVarFloat)(a1: actions->vehicleCam.upOfs);
          }
          else
          {
            ((void (__fastcall *)(double))cvarSystem->SetCVarFloat)(a1: 0.0);
          }
        }
        v2 = gameLocal;
      }
    }
  }
  if ( actions->allowWeaponChange.activate )
  {
    v110 = this->vehicleCar.spawnId.value;
    if ( v2->spawnIds.ptr[v110 & 0x1FFF] == v110 >> 13 )
    {
      v111 = (idVehicle_Car *)v2->entities.ptr[v110 & 0x1FFF];
      if ( v111 != nullptr )
      {
        v112 = idVehicle_Car::CastTo(c: v111);
        if ( v112 != nullptr )
          v112->allowWeaponChange = actions->allowWeaponChange.allowChange;
        v2 = gameLocal;
      }
    }
  }
  if ( actions->nextWeapon.activate )
  {
    v113 = this->vehicleCar.spawnId.value;
    if ( v2->spawnIds.ptr[v113 & 0x1FFF] == v113 >> 13 )
    {
      v114 = (idVehicle_Car *)v2->entities.ptr[v113 & 0x1FFF];
      if ( v114 != nullptr )
      {
        v115 = idVehicle_Car::CastTo(c: v114);
        v116 = v115;
        if ( v115 != nullptr )
        {
          v117 = v115->presentable;
          if ( v117 != nullptr )
            v118 = v117->GetVehicleInterface(this: v117);
          else
            v118 = nullptr;
          idPresentableVehicle::NextWeapon(this: v118, ignoreReadyToFire: false);
          v119 = v116->presentable;
          if ( v119 != nullptr )
            v120 = v119->GetVehicleInterface(this: v119);
          else
            v120 = nullptr;
          idPresentableVehicle::ActivateCrosshair(this: v120);
        }
        v2 = gameLocal;
      }
    }
  }
  if ( actions->vehicleDamageScale.entityList.num > 0 )
  {
    v121 = 0;
    v122 = 0;
    do
    {
      v123 = actions->vehicleDamageScale.entityList.list[v122].spawnId.value;
      if ( v2->spawnIds.ptr[v123 & 0x1FFF] == v123 >> 13 && (v124 = v2->entities.ptr[v123 & 0x1FFF]) != nullptr )
        v125 = (idVehicle_Car *)idEntity::CastTo(c: v124);
      else
        v125 = nullptr;
      v126 = idVehicle_Car::CastTo(c: v125);
      if ( v126 != nullptr )
        goto LABEL_160;
      v127 = actions->vehicleDamageScale.entityList.list[v122].spawnId.value;
      if ( gameLocal->spawnIds.ptr[v127 & 0x1FFF] == v127 >> 13
        && (v128 = gameLocal->entities.ptr[v127 & 0x1FFF]) != nullptr )
      {
        v129 = (idVehicleAI *)idEntity::CastTo(c: v128);
      }
      else
      {
        v129 = nullptr;
      }
      v130 = idVehicleAI::CastTo(c: v129);
      v2 = gameLocal;
      if ( v130 != nullptr )
      {
        v131 = v130->vehicleCar.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v131 & 0x1FFF] == v131 >> 13
          && (v132 = (idVehicle_Car *)gameLocal->entities.ptr[v131 & 0x1FFF]) != nullptr )
        {
          v126 = idVehicle_Car::CastTo(c: v132);
          v2 = gameLocal;
        }
        else
        {
          v126 = nullptr;
        }
        if ( v126 != nullptr )
        {
LABEL_160:
          v2 = gameLocal;
          v126->overallDamageScale = actions->vehicleDamageScale.damageScale;
        }
      }
      ++v121;
      ++v122;
    }
    while ( v121 < actions->vehicleDamageScale.entityList.num );
  }
  if ( actions->vehicleCollisionDamage.entityList.num > 0 )
  {
    v133 = 0;
    v134 = 0;
    do
    {
      v135 = actions->vehicleCollisionDamage.entityList.list[v134].spawnId.value;
      if ( v2->spawnIds.ptr[v135 & 0x1FFF] == v135 >> 13 && (v136 = v2->entities.ptr[v135 & 0x1FFF]) != nullptr )
        v137 = (idVehicle_Car *)idEntity::CastTo(c: v136);
      else
        v137 = nullptr;
      v138 = idVehicle_Car::CastTo(c: v137);
      if ( v138 != nullptr )
        goto LABEL_179;
      v139 = actions->vehicleCollisionDamage.entityList.list[v134].spawnId.value;
      if ( gameLocal->spawnIds.ptr[v139 & 0x1FFF] == v139 >> 13
        && (v140 = gameLocal->entities.ptr[v139 & 0x1FFF]) != nullptr )
      {
        v141 = (idVehicleAI *)idEntity::CastTo(c: v140);
      }
      else
      {
        v141 = nullptr;
      }
      v142 = idVehicleAI::CastTo(c: v141);
      v2 = gameLocal;
      if ( v142 != nullptr )
      {
        v143 = v142->vehicleCar.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v143 & 0x1FFF] == v143 >> 13
          && (v144 = (idVehicle_Car *)gameLocal->entities.ptr[v143 & 0x1FFF]) != nullptr )
        {
          v138 = idVehicle_Car::CastTo(c: v144);
          v2 = gameLocal;
        }
        else
        {
          v138 = nullptr;
        }
        if ( v138 != nullptr )
        {
LABEL_179:
          idVehicle::SetCollisionDamage(
            this: v138,
            decl: actions->vehicleCollisionDamage.declDamage,
            delayMS: 0,
            attacker: nullptr);
          v2 = gameLocal;
        }
      }
      ++v133;
      ++v134;
    }
    while ( v133 < actions->vehicleCollisionDamage.entityList.num );
  }
  if ( actions->vehicleCollisionImpulse.entityList.num > 0 )
  {
    v145 = 0;
    v146 = 0;
    do
    {
      v147 = actions->vehicleCollisionImpulse.entityList.list[v146].spawnId.value;
      if ( v2->spawnIds.ptr[v147 & 0x1FFF] == v147 >> 13 && (v148 = v2->entities.ptr[v147 & 0x1FFF]) != nullptr )
        v149 = (idVehicle_Car *)idEntity::CastTo(c: v148);
      else
        v149 = nullptr;
      v150 = idVehicle_Car::CastTo(c: v149);
      if ( v150 != nullptr )
        goto LABEL_198;
      v151 = actions->vehicleCollisionImpulse.entityList.list[v146].spawnId.value;
      if ( gameLocal->spawnIds.ptr[v151 & 0x1FFF] == v151 >> 13
        && (v152 = gameLocal->entities.ptr[v151 & 0x1FFF]) != nullptr )
      {
        v153 = (idVehicleAI *)idEntity::CastTo(c: v152);
      }
      else
      {
        v153 = nullptr;
      }
      v154 = idVehicleAI::CastTo(c: v153);
      v2 = gameLocal;
      if ( v154 != nullptr )
      {
        v155 = v154->vehicleCar.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v155 & 0x1FFF] == v155 >> 13
          && (v156 = (idVehicle_Car *)gameLocal->entities.ptr[v155 & 0x1FFF]) != nullptr )
        {
          v150 = idVehicle_Car::CastTo(c: v156);
          v2 = gameLocal;
        }
        else
        {
          v150 = nullptr;
        }
        if ( v150 != nullptr )
        {
LABEL_198:
          verticalImpulse = actions->vehicleCollisionImpulse.verticalImpulse;
          v2 = gameLocal;
          v150->collisionImpulse = actions->vehicleCollisionImpulse.impulse;
          v150->collisionVerticalImpulse = verticalImpulse;
        }
      }
      ++v145;
      ++v146;
    }
    while ( v145 < actions->vehicleCollisionImpulse.entityList.num );
  }
  if ( actions->tireFriction.frictionTime > 0.0 )
  {
    v158 = this->vehicleCar.spawnId.value;
    if ( v2->spawnIds.ptr[v158 & 0x1FFF] == v158 >> 13 )
    {
      v159 = (idVehicle_Car *)v2->entities.ptr[v158 & 0x1FFF];
      if ( v159 != nullptr && idVehicle_Car::CastTo(c: v159) != nullptr )
      {
        v160 = this->vehicleCar.spawnId.value;
        v161 = (int)(float)((float)1000.0 * actions->tireFriction.frictionTime);
        if ( gameLocal->spawnIds.ptr[v160 & 0x1FFF] == v160 >> 13
          && (v162 = (idVehicle_Car *)gameLocal->entities.ptr[v160 & 0x1FFF]) != nullptr )
        {
          v163 = idVehicle_Car::CastTo(c: v162);
        }
        else
        {
          v163 = nullptr;
        }
        idVehicle_Car::OverrideFriction(
          this: v163,
          time: v161,
          frontFriction: actions->tireFriction.frontFriction,
          rearFriction: actions->tireFriction.rearFriction);
      }
    }
  }
}


// ========================================================================
// ?UseVehicle@idVehicleAI@@QAAXPAVidEntity@@W4vehicleSeat_t@@@Z
// EA  : 0x82B129C0
// RVA : 0x00B129C0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::UseVehicle(idVehicleAI *this, idVehicle_Car *entity, vehicleSeat_t seat)
{
  idVehicle_Car *v4; // r30
  int value; // r9
  idVehicle_Car *v7; // r3
  idVehicle_Car *v8; // r3
  idVehicle_Car_vtbl *v9; // r29
  int OccupantNum; // r3
  int AFPhysics; // r3
  bool infiniteAmmo; // r4
  idVehicle_Car *Owner; // r3
  idNavPathPosTracker *splineTracker; // r9

  v4 = entity;
  if ( entity != nullptr
    || (value = this->vehicleCar.spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
    && (v7 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && (v4 = idVehicle_Car::CastTo(c: v7)) != nullptr )
  {
    if ( (unsigned __int8)idVehicle_Car::IsTypeOf(c: v4) != 0 )
    {
      if ( idVehicle::GetOccupantNum(this: v4, entity: this) == -1 )
      {
        v4->EnterVehicle(this: v4, a2: this, a3: seat);
        *(_BYTE *)(idVehicle::GetAFPhysics(this: v4) + 753) = 0;
        if ( (this->thinkFlags & 2) == 0 )
        {
          AFPhysics = idVehicle::GetAFPhysics(this: v4);
          (*(void (__fastcall **)(int))(*(_DWORD *)AFPhysics + 152))(a1: AFPhysics);
        }
        this->vehicleCar.spawnId.value = (gameLocal->spawnIds.ptr[v4->entityNumber] << 13) | v4->entityNumber;
        infiniteAmmo = this->setup.infiniteAmmo;
        this->vehicleHadInfiniteAmmo = v4->hasInfiniteAmmo;
        v4->hasInfiniteAmmo = infiniteAmmo;
        if ( this->splineTracker != nullptr )
        {
          Owner = idVehicleAI::GetOwner(this);
          splineTracker = this->splineTracker;
          if ( Owner != nullptr )
            splineTracker->owner.spawnId.value = (gameLocal->spawnIds.ptr[Owner->entityNumber] << 13)
                                               | Owner->entityNumber;
          else
            splineTracker->owner.spawnId.value = 0x1FFF;
        }
        if ( this->setup.health != 0.0 )
          ((void (__fastcall *)(idVehicle_Car *))v4->SetHealth)(a1: v4);
        v4->overallDamageScale = idVehicleAI::GetDifficulty_DamageTakenScale(this);
      }
      else
      {
        if ( this->splineTracker != nullptr )
        {
          v8 = idVehicleAI::GetOwner(this);
          idNavPathPosTracker::RemoveFromEntityList(this: this->splineTracker, entity: v8);
        }
        v9 = v4->__vftable;
        OccupantNum = idVehicle::GetOccupantNum(this: v4, entity: this);
        v9->ExitVehicle(this: v4, a2: OccupantNum, a3: false, a4: false);
        this->vehicleCar.spawnId.value = 0x1FFF;
        v4->UseAiProperties(this: v4, a2: false);
        v4->hasInfiniteAmmo = this->vehicleHadInfiniteAmmo;
        this->decisionFSM.SetState_3(this: &this->decisionFSM, a2: &idVS_Idle::Type, a3: 0, a4: false);
        this->movementFSM.SetState_3(this: &this->movementFSM, a2: &idVS_Idle::Type, a3: 0, a4: false);
        idVehicleAI::SetAttackState(this, stateType: &idVS_Idle::Type, delayTime: 0, pushState: false);
      }
    }
    else
    {
      idLib::Warning(fmt: "UseVehicle: Entity passed not a vehicle.");
    }
  }
}


// ========================================================================
// ?Reset@idVehicleAI@@QAAXXZ
// EA  : 0x82B12C50
// RVA : 0x00B12C50
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::Reset(idVehicleAI *this)
{
  int v2; // r3
  int v3; // r3
  int v4; // r3
  int v5; // r3
  idPhysics *Physics; // r3
  idPhysics *v7; // r3
  int value; // r9
  idVehicle_Car *v9; // r3
  int v10; // r9
  idVehicle_Car *v11; // r3
  idVehicle_Car *v12; // r4

  idVehicleAI::ResetStates(this);
  v2 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  idFiniteStateMachine::Update(this: &this->commandsFSM, curTime: v2, info: nullptr);
  v3 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  idFiniteStateMachine::Update(this: &this->decisionFSM, curTime: v3, info: nullptr);
  v4 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  idFiniteStateMachine::Update(this: &this->attackFSM, curTime: v4, info: nullptr);
  v5 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  idFiniteStateMachine::Update(this: &this->movementFSM, curTime: v5, info: nullptr);
  this->desiredBraking = 3;
  this->desiredSpeed = 0.0;
  this->desiredSteering = 0.0;
  this->desiredWheelForce = 0.0;
  Physics = idEntity::GetPhysics(this);
  Physics->SetLinearVelocity(this: Physics, a2: &vec3_origin, a3: 0);
  v7 = idEntity::GetPhysics(this);
  v7->SetAngularVelocity(this: v7, a2: &vec3_origin, a3: 0);
  value = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v9 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v9 != nullptr && idVehicle_Car::CastTo(c: v9) != nullptr )
    {
      v10 = this->vehicleCar.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v10 & 0x1FFF] == v10 >> 13
        && (v11 = (idVehicle_Car *)gameLocal->entities.ptr[v10 & 0x1FFF]) != nullptr )
      {
        v12 = idVehicle_Car::CastTo(c: v11);
      }
      else
      {
        v12 = nullptr;
      }
      idVehicleAI::UseVehicle(this, entity: v12, seat: SEAT_MAX);
    }
  }
  idNavSplinePathMgr::ReleaseTracker(this: this->splinePathMgr, tracker: this->splineTracker);
  this->splineTracker = nullptr;
  this->enemyTracker = nullptr;
}


// ========================================================================
// ?MoveForward@idVehicleAI@@QAAXM_N0@Z
// EA  : 0x82B12E28
// RVA : 0x00B12E28
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::MoveForward(
        idVehicleAI *this,
        double distance,
        bool isStoppingGoal,
        unsigned int passThroughGoal,
        bool a5)
{
  int value; // r10
  idVehicle_Car *v10; // r3
  idNavPathPosTracker *splineTracker; // r3
  idNavPathPosTracker *p_null_splineTracker; // r11
  int v13; // r8
  idVehicle_Car *v14; // r3
  idVehicle_Car *v15; // r3
  idPhysics *Physics; // r3
  int v17; // r3
  idNavPathPosTracker *v18; // r11
  float *v19; // r30
  float v20; // r9
  float v21; // r8
  bool v22; // r8
  idVec3 *Forward; // r3
  double v24; // fp6
  double v25; // fp13
  int v26; // [sp+8h] [-B8h]
  __int64 v27; // [sp+10h] [-B0h]
  __int64 v28; // [sp+18h] [-A8h]
  __int64 v29; // [sp+20h] [-A0h]
  __int64 v30; // [sp+28h] [-98h]
  __int64 v31; // [sp+30h] [-90h]
  float v32; // [sp+50h] [-70h]
  float rightDistance; // [sp+54h] [-6Ch]
  idVec3 v34; // [sp+60h] [-60h] BYREF
  idNavSplinePosition v35; // [sp+70h] [-50h] BYREF

  value = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v10 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v10 != nullptr && idVehicle_Car::CastTo(c: v10) != nullptr )
    {
      splineTracker = this->splineTracker;
      if ( splineTracker == nullptr )
        splineTracker = &this->splinePathMgr->null_splineTracker;
      idNavPathPosTracker::SetPathTraversal(this: splineTracker, traversalType: NAVSP_RANDOM, forceRecalcLinks: false);
      p_null_splineTracker = this->splineTracker;
      if ( p_null_splineTracker == nullptr )
        p_null_splineTracker = &this->splinePathMgr->null_splineTracker;
      v13 = this->vehicleCar.spawnId.value;
      v32 = p_null_splineTracker->pathPosition.distance;
      rightDistance = p_null_splineTracker->pathPosition.rightDistance;
      if ( gameLocal->spawnIds.ptr[v13 & 0x1FFF] == v13 >> 13
        && (v14 = (idVehicle_Car *)gameLocal->entities.ptr[v13 & 0x1FFF]) != nullptr )
      {
        v15 = idVehicle_Car::CastTo(c: v14);
      }
      else
      {
        v15 = nullptr;
      }
      Physics = idEntity::GetPhysics(this: v15);
      v17 = (int)Physics->GetAxis(this: Physics, a2: 0);
      v18 = this->splineTracker;
      v19 = (float *)v17;
      if ( v18 == nullptr )
        v18 = &this->splinePathMgr->null_splineTracker;
      v20 = v18->pathPosition.rightDistance;
      v21 = *(float *)&v18->pathPosition.navSpline;
      v34.x = v18->pathPosition.distance;
      v34.y = v20;
      v34.z = v21;
      Forward = idNavSplinePosition::GetForward(this: &v35, result: &v34);
      v24 = (float)((float)(*v19 * Forward->x) + (float)((float)(Forward->z * v19[2]) + (float)(Forward->y * v19[1])));
      v35.rightDistance = rightDistance;
      if ( v24 <= 0.0 )
        v25 = (float)(v32 - (float)distance);
      else
        v25 = (float)(v32 + (float)distance);
      v35.distance = v25;
      idVehicleAI::MoveToPathPosition(
        this,
        isStoppingGoal: passThroughGoal,
        passThroughGoal: a5,
        a4: v22,
        a5: SLODWORD(rightDistance),
        a6: SLODWORD(v35.distance),
        a7: v26,
        a8: v27,
        a9: v28,
        a10: v29,
        a11: v30,
        a12: v31);
    }
  }
}


// ========================================================================
// ?HandleRunAway@idVehicleAI@@QAA_NXZ
// EA  : 0x82B13000
// RVA : 0x00B13000
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

int __fastcall idVehicleAI::HandleRunAway(idVehicleAI *this)
{
  if ( (unsigned __int8)idVehicleAI::ShouldRunAway(this) != 0 )
  {
    idVehicleAI::SetAttackState(this, stateType: &idVS_as_RunAway::Type, delayTime: 0, pushState: false);
    return 1;
  }
  else
  {
    if ( this->attackFSM.curState == &this->as_RunAway )
      idVehicleAI::ChooseAttackState(this);
    return 0;
  }
}


// ========================================================================
// ?InitDecisionStatePatrol@idVehicleAI@@QAAXXZ
// EA  : 0x82B13088
// RVA : 0x00B13088
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::InitDecisionStatePatrol(idVehicleAI *this)
{
  vehicleAiSetup_t::patrol_t *v2; // r22
  int value; // r4
  idSplineWaypoint *v4; // r3
  idSplineWaypoint *v5; // r3
  idSplineWaypoint *v6; // r28
  char v7; // r27
  int v8; // r29
  int v9; // r30
  int v10; // r9
  idEntity *v11; // r3
  idSplineWaypoint *v12; // r31
  int v13; // r9
  idSplineWaypoint *v14; // r3
  idSplineWaypoint *v15; // r3
  idSplineWaypoint *v16; // [sp+50h] [-70h] BYREF

  if ( this->setup.patrol.pathType == PATROL_ONCE )
  {
    this->setup.patrol.pathType = PATROL_CYCLICAL;
    this->setup.patrol.iterations = 1;
  }
  v2 = &this->patrolPaths[1];
  vehicleAiSetup_t::patrol_t::operator=(this: &this->patrolPaths[1], __that: &this->setup.patrol);
  if ( this->setup.patrol.pathType == PATROL_REBOUND )
  {
    this->patrolPaths[1].curPatrolPoint = 1;
    this->patrolPaths[1].curPatrolDir = -1;
  }
  else
  {
    this->patrolPaths[1].curPatrolDir = 1;
    this->patrolPaths[1].curPatrolPoint = -1;
  }
  this->patrolPaths[1].delayTime = 1;
  if ( this->patrolPaths[1].waypoints.size < 0 )
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&v2->waypoints);
  v2->waypoints.num = __CFADD__(-v2->waypoints.size, v2->waypoints.size ^ 0x80000000) ? 0 : v2->waypoints.size;
  value = this->setup.patrol.waypoint.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v4 = (idSplineWaypoint *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v5 = idSplineWaypoint::CastTo(c: v4);
  }
  else
  {
    v5 = nullptr;
  }
  v6 = v5;
  v16 = v5;
  if ( v5 != nullptr )
  {
    do
    {
      v7 = 0;
      idList<idAnimWebBlendTree *,5>::Append(
        this: (idList<enum encounterGroupRole_t,5> *)&this->patrolPaths[1].waypoints,
        obj: (const encounterGroupRole_t *)&v16);
      v8 = 0;
      if ( v6->targets.num > 0 )
      {
        v9 = 0;
        while ( 1 )
        {
          v10 = v6->targets.list[v9].spawnId.value;
          if ( gameLocal->spawnIds.ptr[v10 & 0x1FFF] == v10 >> 13
            && (v11 = gameLocal->entities.ptr[v10 & 0x1FFF]) != nullptr )
          {
            v12 = (idSplineWaypoint *)idEntity::CastTo(c: v11);
          }
          else
          {
            v12 = nullptr;
          }
          if ( (unsigned __int8)idSplineWaypoint::IsTypeOf(c: v12) != 0 )
            break;
          ++v8;
          ++v9;
          if ( v8 >= v6->targets.num )
            goto LABEL_23;
        }
        v6 = idSplineWaypoint::CastTo(c: v12);
        v7 = 1;
        v16 = v6;
      }
LABEL_23:
      if ( v7 == 0 )
        break;
      v13 = this->setup.patrol.waypoint.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v13 & 0x1FFF] == v13 >> 13
        && (v14 = (idSplineWaypoint *)gameLocal->entities.ptr[v13 & 0x1FFF]) != nullptr )
      {
        v15 = idSplineWaypoint::CastTo(c: v14);
      }
      else
      {
        v15 = nullptr;
      }
    }
    while ( v6 != v15 && v6 != nullptr );
  }
  this->patrolPaths[1].iterationCount = 0;
  this->currentPatrol = 1;
  this->control.speedLimit = this->patrolPaths[1].speed;
}


// ========================================================================
// ?ActivateVehicle@idVehicleAI@@QAAXPAVidVehicle@@@Z
// EA  : 0x82B13768
// RVA : 0x00B13768
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::ActivateVehicle(idVehicleAI *this, idVehicle_Car *vehicle)
{
  unsigned __int8 v4; // r29
  bool useAiOriginAxis; // r27
  idGameLocal *v6; // r11
  idVehicle_Car *VehicleCar; // r3
  int v8; // r28
  int value; // r9
  idVehicle_Car *v10; // r3
  idVehicle_Car *v11; // r3
  idVehicle_Car *Entity; // r3
  double health; // fp31
  idPhysics *Physics; // r29
  idPhysics *v15; // r27
  idPhysics *v16; // r3
  idPhysics_vtbl *v17; // r29
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  int v19; // r3
  idPhysics *v20; // r3
  idAngles *v21; // r3
  const idAngles *v22; // r3
  int v23; // r9
  idVehicle_Car *v24; // r3
  int v25; // r9
  idVehicle_Car *v26; // r3
  idVehicle_Car *v27; // r3
  idVehicle_Car *v28; // r3
  idVehicle_Car *v29; // r3
  idNavSplinePath *v30; // r3
  char *data; // r4
  int v32; // r9
  idVehicle_Car *v33; // r3
  idNavPathPosTracker *splineTracker; // r11
  idNavPathPosTracker *p_null_splineTracker; // r10
  idNavPathPosTracker *v36; // r10
  char *v37; // r10
  char *v38; // r11
  int v39; // r9
  int v40; // r9
  bool v41; // zf
  idVehicleFSM *p_decisionFSM; // r3
  idState *State; // r3
  int num; // r6
  idNavPathPosTracker *v45; // r11
  double rightDistance; // fp0
  int v47; // r10
  bool v48; // r10
  idMat3 v49; // [sp+50h] [-60h] BYREF

  idEntity::BecomeActive(this, flags: 1);
  v4 = 0;
  useAiOriginAxis = this->setup.controlVehicle.useAiOriginAxis;
  if ( vehicle != nullptr )
    goto LABEL_6;
  v6 = gameLocal;
  if ( gameLocal->spawnIds.ptr[this->setup.controlVehicle.vehicleEnt.spawnId.value & 0x1FFF] == this->setup.controlVehicle.vehicleEnt.spawnId.value >> 13 )
  {
    VehicleCar = (idVehicle_Car *)gameLocal->entities.ptr[this->setup.controlVehicle.vehicleEnt.spawnId.value & 0x1FFF];
    if ( VehicleCar == nullptr )
      goto LABEL_44;
  }
  else
  {
    if ( this->setup.controlVehicle.vehicleDef == nullptr )
      goto LABEL_44;
    VehicleCar = idVehicleAI::GetVehicleCar(this);
    if ( VehicleCar == nullptr )
    {
      Entity = idEntityPtr<idVehicle_Car>::GetEntity(this: &this->prespawnedVehicle);
      vehicle = Entity;
      if ( Entity == nullptr )
        return;
      Entity->Show(this: Entity);
      v4 = 1;
      useAiOriginAxis = true;
      goto LABEL_5;
    }
  }
  vehicle = (idVehicle_Car *)idVehicle::CastTo(c: VehicleCar);
LABEL_5:
  if ( vehicle != nullptr )
  {
LABEL_6:
    v8 = v4;
    if ( v4 != 0
      && ((value = this->vehicleCar.spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13)
       || (v10 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) == nullptr
        ? (v11 = nullptr)
        : (v11 = idVehicle_Car::CastTo(c: v10)),
          v11 == vehicle)
      || ((double (__fastcall *)(idVehicle_Car *))vehicle->GetHealth)(a1: vehicle) <= 0.0 )
    {
      vehicle->Respawn(this: vehicle);
    }
    vehicle->removeWhenDead = vai_instantRespawn.valueInteger == 0
                           && (_cntlzw(this->setup.death.respawnType) & 0x20) != 0;
    health = ((double (__fastcall *)(idVehicle_Car *))vehicle->GetMaxHealth)(a1: vehicle);
    if ( (unsigned __int8)idVehicle_Car::IsTypeOf(c: vehicle) != 0 )
      health = vehicle->aiProperties.health;
    if ( useAiOriginAxis )
    {
      Physics = idEntity::GetPhysics(this);
      v15 = idEntity::GetPhysics(this: vehicle);
      v16 = Physics;
      GetOrigin = Physics->GetOrigin;
      v17 = v15->__vftable;
      v19 = (int)GetOrigin(this: v16, a2: 0);
      v17->SetOrigin(this: v15, a2: (const idVec3 *)v19, a3: -1);
      v20 = idEntity::GetPhysics(this);
      v21 = (idAngles *)v20->GetAxis(this: v20, a2: 0);
      v22 = idMat3::ToAngles(this: &v49, result: v21);
      idEntity::SetAngles(this: vehicle, ang: v22);
    }
    *(_BYTE *)&vehicle->flags = (2 * this->setup.takesDamage) & 2 | *(_BYTE *)&vehicle->flags & 0xFD;
    if ( v8 != 0 )
    {
      vehicle->SetMaxHealth(this: vehicle, a2: health);
      vehicle->SetHealth(this: vehicle, a2: health);
    }
    v23 = this->vehicleCar.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v23 & 0x1FFF] == v23 >> 13 )
    {
      v24 = (idVehicle_Car *)gameLocal->entities.ptr[v23 & 0x1FFF];
      if ( v24 != nullptr && idVehicle_Car::CastTo(c: v24) != nullptr )
      {
        v25 = this->vehicleCar.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v25 & 0x1FFF] == v25 >> 13
          && (v26 = (idVehicle_Car *)gameLocal->entities.ptr[v25 & 0x1FFF]) != nullptr )
        {
          v27 = idVehicle_Car::CastTo(c: v26);
        }
        else
        {
          v27 = nullptr;
        }
        if ( v27 != vehicle )
        {
          v28 = idVehicleAI::GetVehicleCar(this);
          idVehicleAI::UseVehicle(this, entity: v28, seat: SEAT_MAX);
        }
      }
    }
    if ( !idVehicle::IsAnOccupant(this: vehicle, entity: this) )
      idVehicleAI::UseVehicle(this, entity: vehicle, seat: SEAT_MAX);
    vehicle->Show(this: vehicle);
    v29 = idVehicle_Car::CastTo(c: vehicle);
    idVehicle_Car::SetGhostMode(this: v29, bl: this->setup.ghostCollision, time: -1);
    goto LABEL_39;
  }
  v6 = gameLocal;
LABEL_44:
  v32 = this->vehicleCar.spawnId.value;
  if ( v6->spawnIds.ptr[v32 & 0x1FFF] == v32 >> 13 )
  {
    v33 = (idVehicle_Car *)v6->entities.ptr[v32 & 0x1FFF];
    if ( v33 != nullptr )
    {
      if ( idVehicle_Car::CastTo(c: v33) != nullptr )
      {
LABEL_39:
        v6 = gameLocal;
        goto LABEL_40;
      }
      v6 = gameLocal;
    }
  }
  if ( this->setup.commands.num == 0 )
  {
    idLib::Error(fmt: "AI Vehicle not created!  ai: %s\n", this->name.data);
_LN230_0:
    data = (char *)MEMORY[0x10];
    goto LABEL_52;
  }
LABEL_40:
  if ( v6->spawnIds.ptr[this->setup.initialPath.spawnId.value & 0x1FFF] == this->setup.initialPath.spawnId.value >> 13 )
  {
    v30 = (idNavSplinePath *)v6->entities.ptr[this->setup.initialPath.spawnId.value & 0x1FFF];
    if ( v30 != nullptr )
    {
      data = idNavSplinePath::CastTo(c: v30)->name.data;
      goto LABEL_52;
    }
    goto _LN230_0;
  }
  data = nullptr;
LABEL_52:
  idVehicleAI::UseSplinePath(this, pathName: data);
  if ( this->splineTracker == nullptr && this->splinePathMgr == (idAISplinePathMgr *)-158480 )
    this->splineTracker = idNavSplinePathMgr::GetTracker(
                            this: (idNavSplinePathMgr *)&gameLocal->aiSplinePathMgr.trackerPool.trackers[-1].userPath[0].path.num,
                            owner: this);
  splineTracker = this->splineTracker;
  if ( splineTracker != nullptr )
    p_null_splineTracker = this->splineTracker;
  else
    p_null_splineTracker = &this->splinePathMgr->null_splineTracker;
  if ( p_null_splineTracker != nullptr )
  {
    if ( splineTracker != nullptr )
      v36 = this->splineTracker;
    else
      v36 = &this->splinePathMgr->null_splineTracker;
    if ( v36 != nullptr )
    {
      if ( splineTracker == nullptr )
        splineTracker = &this->splinePathMgr->null_splineTracker;
      splineTracker->allowSplineJumping = this->setup.allowSplineJumping;
    }
    v37 = &byte_8200D768;
    v38 = this->setup.debugState.data;
    do
    {
      v39 = (unsigned __int8)*v38;
      v41 = v39 == 0;
      v40 = v39 - (unsigned __int8)*v37;
      if ( v41 )
        break;
      ++v38;
      ++v37;
    }
    while ( v40 == 0 );
    p_decisionFSM = &this->decisionFSM;
    if ( v40 != 0 )
      State = idFiniteStateMachine::FindState(this: p_decisionFSM, name: this->setup.debugState.data);
    else
      State = idFiniteStateMachine::FindState(this: p_decisionFSM, name: vehicleAiStateNames[this->setup.decisionState]);
    this->decisionFSM.SetState_2(this: &this->decisionFSM, a2: State, a3: 0, a4: false);
    this->movementFSM.SetState_3(this: &this->movementFSM, a2: &idVS_ms_MoveToGoalOnSpline::Type, a3: 0, a4: false);
    idVehicleAI::SetDifficultyData(this, difficultyLevel: &this->setup.difficultyLevel);
    num = this->setup.commands.num;
    this->forceSteeringTime = 0;
    this->vehicleWasActive = true;
    this->canControlVehicle = true;
    if ( num > 0 )
      this->commandsFSM.SetState_3(this: &this->commandsFSM, a2: &idVS_cs_NextCommand::Type, a3: 0, a4: false);
    v45 = this->splineTracker;
    this->nextAttackTime = 0;
    this->currentAttack = nullptr;
    this->controlTurn = false;
    this->setup.engage.alertSoundTime = 0;
    if ( v45 != nullptr )
      rightDistance = v45->pathPosition.rightDistance;
    else
      rightDistance = this->goalRightDistance;
    v47 = this->setup.conditionalAudio.afterKills.sounds.num;
    this->goalRightDistance = rightDistance;
    if ( v47 > 0
      || this->setup.conditionalAudio.duringFireFight.sounds.num > 0
      || this->setup.conditionalAudio.takingDamage.sounds.num > 0
      || (v48 = false, this->setup.conditionalAudio.lowHealth.sounds.num > 0) )
    {
      v48 = true;
    }
    this->hasConditionalAudio = v48;
    if ( v45 == nullptr )
      v45 = &this->splinePathMgr->null_splineTracker;
    this->startingPathPosition.distance = v45->pathPosition.distance;
    this->startingPathPosition.rightDistance = v45->pathPosition.rightDistance;
    this->startingPathPosition.navSpline = v45->pathPosition.navSpline;
  }
  else
  {
    idLib::Warning(fmt: "No spline tracker created. AI dormant!   %s", this->name.data);
    idVehicleAI::ResetStates(this);
  }
}


// ========================================================================
// ?UpdatePatrolPath@idVehicleAI@@QAAXXZ
// EA  : 0x82B13E38
// RVA : 0x00B13E38
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::UpdatePatrolPath(idVehicleAI *this)
{
  int currentPatrol; // r11
  char *v3; // r11
  char *v4; // r31
  char v5; // r29
  char v6; // r30
  int v7; // r4
  idVec3 *v8; // r30
  bool v9; // cr56
  idVehicle_Car *VehicleCar; // r3
  idPhysics *Physics; // r25
  idVec3 *WorldPos; // r30
  float *v13; // r3
  double v14; // fp9
  double v15; // fp7
  char v16; // r11
  double v17; // fp2
  double v19; // fp12
  double v21; // fp9
  idSplineWaypoint *v22; // r25
  int (__fastcall *GetGameMs)(struct idGameLocal *, const gameTimeType_t); // r8
  float rightDistance; // r25
  char v25; // r29
  int v26; // r11
  int v27; // r11
  int v28; // r11
  int v29; // r10
  int v30; // r11
  int v31; // r10
  int v32; // r11
  int v33; // r9
  int v34; // r11
  bool v35; // r10
  idNavSplinePosition v36; // [sp+50h] [-60h] BYREF

  currentPatrol = this->currentPatrol;
  if ( currentPatrol != -1 )
  {
    v3 = (char *)this + 80 * currentPatrol;
    v4 = v3 + 4200;
    if ( v3[4248] != 0 )
    {
      this->control.speedLimit = 0;
      return;
    }
    v5 = 0;
    v6 = 0;
    if ( *((int *)v3 + 1060) > 0 )
    {
      if ( *((_DWORD *)v3 + 1060) > gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
        goto LABEL_8;
      *((_DWORD *)v4 + 10) = 0;
      goto LABEL_7;
    }
    v8 = *(idVec3 **)(4 * *((_DWORD *)v3 + 1058) + *((_DWORD *)v3 + 1063));
    if ( v8[69].x <= 0.0 )
    {
      if ( this->passThroughGoal )
      {
        VehicleCar = idVehicleAI::GetVehicleCar(this);
        Physics = idEntity::GetPhysics(this: VehicleCar);
        WorldPos = idNavSplinePosition::GetWorldPos(this: &v36, result: v8 + 68);
        v13 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
        v14 = (float)(v13[2] - WorldPos->z);
        v15 = (float)(v13[1] - WorldPos->y);
        v16 = 1;
        v17 = (float)((float)((float)(*v13 - WorldPos->x) * (float)(*v13 - WorldPos->x))
                    + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14)));
        _FP1 = (float)((float)((float)((float)(*v13 - WorldPos->x) * (float)(*v13 - WorldPos->x))
                             + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14)))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        v19 = (float)((float)((float)((float)(*v13 - WorldPos->x) * (float)(*v13 - WorldPos->x))
                            + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14)))
                    * (float)0.5);
        __asm { fsel      f10, f1, f2, f13 }
        v21 = __frsqrte(_FP10);
        if ( (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)v19) * (float)v21) - (float)1.5) * (float)v21) * (float)v19)
                                                                                           * (float)((float)-(float)((float)((float)((float)v21 * (float)v19) * (float)v21) - (float)1.5) * (float)v21))
                                                                                   - (float)1.5)
                                                                   * (float)((float)-(float)((float)((float)((float)v21 * (float)v19) * (float)v21)
                                                                                           - (float)1.5)
                                                                           * (float)v21))
                                                           * (float)v19)
                                                   * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)v19) * (float)v21) - (float)1.5) * (float)v21)
                                                                                           * (float)v19)
                                                                                   * (float)((float)-(float)((float)((float)((float)v21 * (float)v19) * (float)v21) - (float)1.5)
                                                                                           * (float)v21))
                                                                           - (float)1.5)
                                                           * (float)((float)-(float)((float)((float)((float)v21 * (float)v19)
                                                                                           * (float)v21)
                                                                                   - (float)1.5)
                                                                   * (float)v21)))
                                           - (float)1.5)
                           * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v21 * (float)v19) * (float)v21)
                                                                                           - (float)1.5)
                                                                           * (float)v21)
                                                                   * (float)v19)
                                                           * (float)((float)-(float)((float)((float)((float)v21 * (float)v19)
                                                                                           * (float)v21)
                                                                                   - (float)1.5)
                                                                   * (float)v21))
                                                   - (float)1.5)
                                   * (float)((float)-(float)((float)((float)((float)v21 * (float)v19) * (float)v21)
                                                           - (float)1.5)
                                           * (float)v21)))
                   * (float)v17) > (double)*((float *)v4 + 7) )
LABEL_18:
          v16 = 0;
LABEL_19:
        v6 = v16;
        if ( v16 != 0 )
        {
          v22 = *(idSplineWaypoint **)(4 * *((_DWORD *)v4 + 8) + *((_DWORD *)v4 + 13));
          idSplineWaypoint::AiReachedWaypoint(this: v22, ai: this);
          if ( v22->delay <= 0.0 || *((int *)v4 + 14) <= 1 )
          {
LABEL_7:
            v5 = 1;
            goto LABEL_8;
          }
          GetGameMs = gameLocal->GetGameMs;
          LODWORD(v36.rightDistance) = (int)(float)(v22->delay * (float)1000.0);
          rightDistance = v36.rightDistance;
          *((_DWORD *)v4 + 10) = GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + LODWORD(rightDistance);
        }
LABEL_8:
        if ( v5 == 0 )
        {
LABEL_56:
          idNavPathPosTracker::SetGoalPathPosition(
            this: *((idNavPathPosTracker **)v4 + 17),
            pathPos: *((idNavSplinePosition **)v4 + 18),
            doPathSearch: __ROL4__(*((_DWORD *)v4 + 19), 32));
          return;
        }
        v7 = *((_DWORD *)v4 + 14);
        if ( v7 == 0 )
        {
          this->control.speedLimit = 0.0;
          v4[48] = 1;
          goto LABEL_56;
        }
        v25 = 0;
        if ( v7 == 1 )
        {
          *((_DWORD *)v4 + 8) = 0;
          if ( v6 != 0 )
            v4[48] = 1;
        }
        else
        {
          v26 = *((_DWORD *)v4 + 2);
          if ( v26 == 2 )
          {
            *((_DWORD *)v4 + 8) = idRandom2::RandomInt(this: &clientGame->random, max: v7);
            goto LABEL_50;
          }
          if ( v26 != 0 )
          {
            if ( v26 != 1 )
              goto LABEL_50;
            v30 = *((_DWORD *)v4 + 9) + *((_DWORD *)v4 + 8);
            *((_DWORD *)v4 + 8) = v30;
            if ( v30 < v7 )
            {
              if ( v30 < 0 )
              {
                v31 = *((_DWORD *)v4 + 5);
                v32 = *((_DWORD *)v4 + 11) + 1;
                *((_DWORD *)v4 + 11) = v32;
                if ( v32 == v31 )
                  v4[48] = 1;
                if ( v4[48] != 0 )
                {
                  *((_DWORD *)v4 + 8) = 0;
                }
                else
                {
                  *((_DWORD *)v4 + 8) = 1;
                  *((_DWORD *)v4 + 9) = 1;
                }
              }
            }
            else
            {
              *((_DWORD *)v4 + 8) = v7 - 2;
              *((_DWORD *)v4 + 9) = -1;
            }
            if ( *((_DWORD *)v4 + 9) + *((_DWORD *)v4 + 8) >= 0 )
              goto LABEL_50;
          }
          else
          {
            v27 = *((_DWORD *)v4 + 8) + 1;
            *((_DWORD *)v4 + 8) = v27;
            if ( v27 >= v7 )
            {
              v28 = *((_DWORD *)v4 + 5);
              v29 = *((_DWORD *)v4 + 11) + 1;
              *((_DWORD *)v4 + 11) = v29;
              if ( v28 > 0 && v29 >= v28 )
                v4[48] = 1;
              if ( v4[48] != 0 )
              {
                *((_DWORD *)v4 + 8) = v7 - 1;
                this->control.speedLimit = 0.0;
              }
              else
              {
                *((_DWORD *)v4 + 8) = 0;
              }
            }
            if ( *((_DWORD *)v4 + 8) + 1 < *((_DWORD *)v4 + 14) )
              goto LABEL_50;
          }
          if ( *((_DWORD *)v4 + 11) + 1 != *((_DWORD *)v4 + 5) )
          {
LABEL_50:
            v33 = *((_DWORD *)v4 + 8);
            v34 = *(_DWORD *)(4 * v33 + *((_DWORD *)v4 + 13));
            v35 = *(float *)(v34 + 828) > 0.0;
            if ( v33 > -1 && v34 != 0 )
            {
              *((_DWORD *)v4 + 17) = *(_DWORD *)(v34 + 816);
              *((_DWORD *)v4 + 18) = *(_DWORD *)(v34 + 820);
              *((_DWORD *)v4 + 19) = *(_DWORD *)(v34 + 824);
              idVehicleAI::MoveToPosition(
                this: *(idVehicleAI **)(v34 + 816),
                pathPos: *(idNavSplinePosition **)(v34 + 820),
                isStoppingGoal: __ROL4__(*(_DWORD *)(v34 + 824), 32),
                passThroughGoal: (unsigned __int8)v25 | v35,
                a5: *(_BYTE *)(v34 + 852));
            }
            if ( this->distanceToFinalGoal <= (double)idVehicleAI::GetStopDistance(this) && v4[48] != 0 )
              this->control.speedLimit = 0.0;
            goto LABEL_56;
          }
        }
        v25 = 1;
        goto LABEL_50;
      }
      v9 = this->splineDistanceToFinalGoal < (double)*((float *)v3 + 1057);
    }
    else
    {
      v9 = this->distanceToFinalGoal < (double)idVehicleAI::GetStopDistance(this);
    }
    v16 = 1;
    if ( v9 )
      goto LABEL_19;
    goto LABEL_18;
  }
}


// ========================================================================
// ?Respawn@idVehicleAI@@QAAXXZ
// EA  : 0x82B142C0
// RVA : 0x00B142C0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::Respawn(idVehicleAI *this)
{
  int value; // r9
  idGameLocal *v3; // r11
  idVehicle_Car *v4; // r3
  idVehicle_Car *v5; // r3
  int v6; // r9
  idVehicle_Car *v7; // r3
  idVehicle_Car *v8; // r3
  idTarget_DynamicVehicleAiController *dynamicVehicleAIController; // r3
  idTarget_DynamicVehicleAiController *v10; // r3
  BOOL respawnInBackground; // r10
  double y; // fp13
  double z; // fp12
  double x; // fp11
  double v15; // fp10
  double v16; // fp9
  double v17; // fp8
  double v18; // fp7
  double v19; // fp6
  double v20; // fp5
  double v21; // fp4
  double v22; // fp3
  int i; // r30
  idPlayer *Player; // r3
  idEntity *v25; // r31
  idEntity *v26; // r3
  idPhysics *Physics; // r3
  float *v28; // r3
  double v29; // fp31
  double v30; // fp30
  double v31; // fp29
  idMat3 *v32; // r3
  float *LastViewAxis; // r3
  double v34; // fp0
  idPhysics *v35; // r3
  float *v36; // r9
  idPresentable *presentable; // r3
  double v38; // fp29
  float *v39; // r3
  double v40; // fp13
  bool v41; // r11
  int v42; // r9
  idVehicle_Car *v43; // r3
  int v44; // r9
  idVehicle_Car *v45; // r3
  idVehicle_Car *v46; // r3
  int v47; // r9
  idEntity *v48; // r27
  int EntitiesTouchingBounds; // r28
  idPhysics *v50; // r3
  int v51; // r3
  char *v52; // r10
  _DWORD *v53; // r9
  int j; // ctr
  idGameLocal *v55; // r10
  int v56; // r29
  int *v57; // r30
  int v58; // r11
  idVehicleAI *v59; // r31
  idPhysics *v60; // r3
  int v61; // r3
  char *v62; // r10
  _DWORD *v63; // r11
  int k; // ctr
  idPhysics *v65; // r3
  float *v66; // r3
  double v67; // fp8
  double v68; // fp6
  double v69; // fp5
  double v70; // fp3
  double v71; // fp2
  int v72; // r9
  idVehicle_Car *v73; // r3
  int v74; // r9
  idVehicle_Car *v75; // r3
  idVehicle_Car *v76; // r3
  idPhysics *v77; // r3
  int v78; // r9
  idVehicle_Car *v79; // r3
  idVehicle_Car *v80; // r3
  idPhysics *v81; // r3
  idPhysics *v82; // r3
  idPhysics *v83; // r3
  int respawns; // r11
  idVec3 v85; // [sp+50h] [-190h] BYREF
  char v86; // [sp+5Ch] [-184h] BYREF
  idBounds v87; // [sp+60h] [-180h] BYREF
  char v88; // [sp+7Ch] [-164h] BYREF
  idBounds v89[2]; // [sp+80h] [-160h] BYREF
  idMat3 v90; // [sp+B0h] [-130h] BYREF
  idBounds v91; // [sp+E0h] [-100h] BYREF
  int v92[40]; // [sp+100h] [-E0h] BYREF

  this->excessiveBackupAttempts = 0;
  value = this->vehicleCar.spawnId.value;
  v3 = gameLocal;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v4 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v4 != nullptr )
    {
      v5 = idVehicle_Car::CastTo(c: v4);
      v3 = gameLocal;
      if ( v5 != nullptr )
      {
        v6 = this->vehicleCar.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v6 & 0x1FFF] == v6 >> 13
          && (v7 = (idVehicle_Car *)gameLocal->entities.ptr[v6 & 0x1FFF]) != nullptr )
        {
          v8 = idVehicle_Car::CastTo(c: v7);
          v3 = gameLocal;
        }
        else
        {
          v8 = nullptr;
        }
        if ( v8->specialDeathActive )
        {
          idEventReceiver::PostEventMS(this, ev: &EV_Respawn, time: 2000);
          return;
        }
      }
    }
  }
  dynamicVehicleAIController = (idTarget_DynamicVehicleAiController *)this->dynamicVehicleAIController;
  if ( dynamicVehicleAIController != nullptr )
  {
    v10 = idTarget_DynamicVehicleAiController::CastTo(c: dynamicVehicleAIController);
    if ( v10 != nullptr )
    {
      if ( !idTarget_DynamicVehicleAiController::GetVehicleRespawnPosition(
              this: v10,
              vehAI: this,
              spawnPos: &v85,
              spawnAxis: &v90) )
      {
LABEL_13:
        idEventReceiver::PostEventMS(this, ev: &EV_Respawn, time: 2000);
        idEntity::BecomeInactive(this, flags: 1);
        return;
      }
      v3 = gameLocal;
      goto LABEL_32;
    }
    v3 = gameLocal;
  }
  respawnInBackground = this->setup.death.respawnInBackground;
  y = this->startingOrigin.y;
  z = this->startingOrigin.z;
  x = this->startingAxis.mat[0].x;
  v15 = this->startingAxis.mat[0].y;
  v16 = this->startingAxis.mat[0].z;
  v17 = this->startingAxis.mat[1].x;
  v18 = this->startingAxis.mat[1].y;
  v19 = this->startingAxis.mat[1].z;
  v20 = this->startingAxis.mat[2].x;
  v21 = this->startingAxis.mat[2].y;
  v22 = this->startingAxis.mat[2].z;
  v85.x = this->startingOrigin.x;
  v85.y = y;
  v85.z = z;
  v90.mat[0].x = x;
  v90.mat[0].y = v15;
  v90.mat[0].z = v16;
  v90.mat[1].x = v17;
  v90.mat[1].y = v18;
  v90.mat[1].z = v19;
  v90.mat[2].x = v20;
  v90.mat[2].y = v21;
  v90.mat[2].z = v22;
  if ( respawnInBackground && vai_forceNoRespawnInBackground.valueInteger == 0 )
  {
    for ( i = 0; i < 6; ++i )
    {
      Player = idGameLocal::GetPlayer(this: v3, i);
      v25 = Player;
      if ( Player != nullptr )
      {
        if ( Player->IsDrivingVehicle(this: Player) )
        {
          v26 = (idEntity *)((int (__fastcall *)(idEntity *))v25->__vftable[1].ForceAnimWebState)(a1: v25);
          Physics = idEntity::GetPhysics(this: v26);
          v28 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
          v29 = (float)(v85.x - *v28);
          v30 = (float)(v85.y - v28[1]);
          v31 = (float)(v85.z - v28[2]);
          v32 = (idMat3 *)((int (__fastcall *)(idEntity *))v25->__vftable[1].ForceAnimWebState)(a1: v25);
          LastViewAxis = (float *)idVehicle::GetLastViewAxis(this: (idVehicle *)v89, result: v32);
          v34 = (float)((float)(*LastViewAxis * (float)v29)
                      + (float)((float)(LastViewAxis[2] * (float)v31) + (float)(LastViewAxis[1] * (float)v30)));
        }
        else
        {
          v35 = idEntity::GetPhysics(this: v25);
          v36 = (float *)v35->GetOrigin(this: v35, a2: 0);
          v29 = (float)(v85.x - *v36);
          v30 = (float)(v85.y - v36[1]);
          v38 = (float)(v85.z - v36[2]);
          presentable = v25->presentable;
          if ( presentable != nullptr )
            v39 = (float *)presentable->GetPlayerInterface_2(this: presentable);
          else
            v39 = nullptr;
          v34 = (float)((float)((float)v29 * v39[11636])
                      + (float)((float)(v39[11638] * (float)v38) + (float)(v39[11637] * (float)v30)));
        }
        v40 = (float)((float)((float)v29 * (float)v29) + (float)((float)v30 * (float)v30));
        v41 = v40 < (float)(this->setup.death.minBackgroundDistance * this->setup.death.minBackgroundDistance);
        if ( v34 > 0.0
          && v40 < (float)(this->setup.death.minBackgroundViewDistance * this->setup.death.minBackgroundViewDistance) )
        {
          v41 = true;
        }
        if ( v41 )
          goto LABEL_13;
      }
      v3 = gameLocal;
    }
  }
LABEL_32:
  v42 = this->vehicleCar.spawnId.value;
  if ( v3->spawnIds.ptr[v42 & 0x1FFF] != v42 >> 13 || (v43 = (idVehicle_Car *)v3->entities.ptr[v42 & 0x1FFF]) == nullptr )
  {
LABEL_39:
    v47 = this->prespawnedVehicle.spawnId.value;
    if ( v3->spawnIds.ptr[v47 & 0x1FFF] == v47 >> 13 )
    {
      v45 = (idVehicle_Car *)v3->entities.ptr[v47 & 0x1FFF];
      if ( v45 != nullptr )
        goto LABEL_37;
    }
LABEL_41:
    v46 = nullptr;
    goto LABEL_42;
  }
  if ( idVehicle_Car::CastTo(c: v43) == nullptr )
  {
    v3 = gameLocal;
    goto LABEL_39;
  }
  v44 = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v44 & 0x1FFF] != v44 >> 13 )
    goto LABEL_41;
  v45 = (idVehicle_Car *)gameLocal->entities.ptr[v44 & 0x1FFF];
  if ( v45 == nullptr )
    goto LABEL_41;
LABEL_37:
  v46 = idVehicle_Car::CastTo(c: v45);
LABEL_42:
  v48 = v46;
  if ( v46 != nullptr )
  {
    v91.b[0].x = v85.x - (float)1500.0;
    v91.b[0].y = v85.y - (float)1500.0;
    v91.b[0].z = v85.z - (float)1500.0;
    v91.b[1].x = v85.x + (float)1500.0;
    v91.b[1].y = v85.y + (float)1500.0;
    v91.b[1].z = v85.z + (float)1500.0;
    EntitiesTouchingBounds = idClip::GetEntitiesTouchingBounds(
                               this: &clientGame->clip,
                               bounds: &v91,
                               clipMask: -1,
                               entityList: v92,
                               maxCount: 32);
    v50 = idEntity::GetPhysics(this: v48);
    v51 = (int)v50->GetBounds(this: v50, a2: -1);
    v52 = &v86;
    v53 = (_DWORD *)(v51 - 4);
    for ( j = 6; j != 0; --j )
    {
      ++v53;
      v52 += 4;
      *(_DWORD *)v52 = *v53;
    }
    v55 = gameLocal;
    v56 = 0;
    v87.b[0].x = v87.b[0].x + v85.x;
    v87.b[0].y = v87.b[0].y + v85.y;
    v87.b[0].z = v87.b[0].z + v85.z;
    v87.b[1].x = v87.b[1].x + v85.x;
    v87.b[1].y = v87.b[1].y + v85.y;
    v87.b[1].z = v87.b[1].z + v85.z;
    if ( EntitiesTouchingBounds > 0 )
    {
      v57 = v92;
      do
      {
        v58 = *v57 + 21563;
        v59 = *((idVehicleAI **)&v55->__vftable + v58);
        if ( v59 != this )
        {
          if ( (unsigned __int8)idStaticEntity::IsTypeOf(c: *((idClass **)&v55->__vftable + v58)) == 0 && v59 != v48 )
          {
            v60 = idEntity::GetPhysics(this: v59);
            v61 = (int)v60->GetBounds(this: v60, a2: -1);
            v62 = &v88;
            v63 = (_DWORD *)(v61 - 4);
            for ( k = 6; k != 0; --k )
            {
              ++v63;
              v62 += 4;
              *(_DWORD *)v62 = *v63;
            }
            v65 = idEntity::GetPhysics(this: v59);
            v66 = (float *)v65->GetOrigin(this: v65, a2: 0);
            v67 = v66[1];
            v68 = v66[2];
            v69 = (float)(v89[0].b[0].y + v66[1]);
            v70 = (float)(v89[0].b[0].z + v66[2]);
            v71 = (float)(v89[0].b[1].x + *v66);
            v89[0].b[0].x = v89[0].b[0].x + *v66;
            v89[0].b[0].y = v69;
            v89[0].b[0].z = v70;
            v89[0].b[1].x = v71;
            v89[0].b[1].y = v89[0].b[1].y + (float)v67;
            v89[0].b[1].z = v89[0].b[1].z + (float)v68;
            if ( (unsigned __int8)idBounds::IntersectsBounds(this: &v87, a: v89) != 0 )
              goto LABEL_13;
          }
          v55 = gameLocal;
        }
        ++v56;
        ++v57;
      }
      while ( v56 < EntitiesTouchingBounds );
    }
    v72 = this->vehicleCar.spawnId.value;
    if ( v55->spawnIds.ptr[v72 & 0x1FFF] == v72 >> 13 )
    {
      v73 = (idVehicle_Car *)v55->entities.ptr[v72 & 0x1FFF];
      if ( v73 != nullptr && idVehicle_Car::CastTo(c: v73) != nullptr )
      {
        v74 = this->vehicleCar.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v74 & 0x1FFF] == v74 >> 13
          && (v75 = (idVehicle_Car *)gameLocal->entities.ptr[v74 & 0x1FFF]) != nullptr )
        {
          v76 = idVehicle_Car::CastTo(c: v75);
        }
        else
        {
          v76 = nullptr;
        }
        v77 = idEntity::GetPhysics(this: v76);
        v77->SetOrigin(this: v77, a2: &v85, a3: -1);
        v78 = this->vehicleCar.spawnId.value;
        if ( gameLocal->spawnIds.ptr[v78 & 0x1FFF] == v78 >> 13
          && (v79 = (idVehicle_Car *)gameLocal->entities.ptr[v78 & 0x1FFF]) != nullptr )
        {
          v80 = idVehicle_Car::CastTo(c: v79);
        }
        else
        {
          v80 = nullptr;
        }
        v81 = idEntity::GetPhysics(this: v80);
        v81->SetAxis(this: v81, a2: &v90, a3: -1);
      }
    }
  }
  v82 = idEntity::GetPhysics(this);
  v82->SetOrigin(this: v82, a2: &v85, a3: -1);
  v83 = idEntity::GetPhysics(this);
  v83->SetAxis(this: v83, a2: &v90, a3: -1);
  idVehicleAI::ActivateVehicle(this, vehicle: nullptr);
  respawns = this->setup.death.respawns;
  if ( respawns > 0 )
    this->setup.death.respawns = respawns - 1;
}


// ========================================================================
// ?UpdateMovement@idVehicleAI@@IAAXXZ
// EA  : 0x82B14A98
// RVA : 0x00B14A98
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::UpdateMovement(idVehicleAI *this)
{
  int value; // r10
  idVehicle_Car *v3; // r3
  int v4; // r9
  idVehicle_Car *v5; // r3
  idVehicle_Car *v6; // r3
  int v7; // r9
  idGameLocal *v8; // r11
  idVehicle_Car *v9; // r3
  idVehicle_Car *v10; // r3
  idVehicle_Car *v11; // r31
  int v12; // r28
  idVehicle_Car *VehicleCar; // r3
  idVehicle_Car *v14; // r3
  idPhysics *Physics; // r3
  float *v16; // r3
  double v19; // fp2
  double v20; // fp7
  double v21; // fp4
  idVehicle_Car *v22; // r3
  idPhysics *v23; // r3
  float *v24; // r3
  double v25; // fp31
  bool v26; // r4
  idVehicle_Car *v27; // r3
  double v28; // fp2
  double v29; // fp1
  double v30; // fp31
  idVehicle_Car *v31; // r3
  double v32; // fp31
  int v33; // r9
  idVehicle_Car *v34; // r3
  idVehicle_Car *v35; // r3
  idPresentable *presentable; // r3
  double desiredSteering; // fp31
  idPresentableVehicle *v38; // r3
  int v39; // r5
  int v40; // r4
  __int64 v41; // r6
  int v42; // r4
  char v43; // [sp+50h] [-40h] BYREF

  value = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return;
  v3 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
  if ( v3 == nullptr || idVehicle_Car::CastTo(c: v3) == nullptr )
    return;
  v4 = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v4 & 0x1FFF] == v4 >> 13
    && (v5 = (idVehicle_Car *)gameLocal->entities.ptr[v4 & 0x1FFF]) != nullptr )
  {
    v6 = idVehicle_Car::CastTo(c: v5);
  }
  else
  {
    v6 = nullptr;
  }
  if ( (unsigned __int8)idVehicle_Car::IsViolentRoll(this: v6) == 0 )
  {
    v7 = this->vehicleCar.spawnId.value;
    v8 = gameLocal;
    if ( gameLocal->spawnIds.ptr[v7 & 0x1FFF] == v7 >> 13
      && (v9 = (idVehicle_Car *)gameLocal->entities.ptr[v7 & 0x1FFF]) != nullptr )
    {
      v10 = idVehicle_Car::CastTo(c: v9);
      v8 = gameLocal;
      v11 = v10;
    }
    else
    {
      v11 = nullptr;
    }
    v12 = v8->GetGameMs(this: v8, a2: GAMETIME_SCALED) - 1000;
    if ( idVehicle_Car::GetViolentRollStopTime(this: v11) < v12 )
    {
      VehicleCar = idVehicleAI::GetVehicleCar(this);
      if ( idVehicle_Car::GetNumWheelsOnGround(this: VehicleCar) > 2 )
      {
        v30 = (float)(this->actualSpeed / idVehicleAI::GetMaxSpeed(this));
        v31 = idVehicleAI::GetVehicleCar(this);
        v32 = (float)(this->desiredSteering / idVehicle::GetMaxSteerAngle(this: v31, speed: v30));
        v27 = idVehicleAI::GetVehicleCar(this);
        v29 = v32;
        v28 = 0.0;
      }
      else
      {
        v14 = idVehicleAI::GetVehicleCar(this);
        Physics = idEntity::GetPhysics(this: v14);
        v16 = (float *)Physics->GetAngularVelocity(this: (idPhysics *)&v43, result: (idVec3 *)Physics, a3: 0);
        _FP5 = (float)((float)((float)(v16[2] * v16[2]) + (float)((float)(*v16 * *v16) + (float)(v16[1] * v16[1])))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f3, f5, f6, f13 }
        v19 = __frsqrte(_FP3);
        v20 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19
                                                                                            * (float)((float)((float)(v16[2] * v16[2]) + (float)((float)(*v16 * *v16) + (float)(v16[1] * v16[1]))) * (float)0.5))
                                                                                    * (float)v19)
                                                                            - (float)1.5)
                                                            * (float)v19)
                                                    * (float)((float)((float)(v16[2] * v16[2])
                                                                    + (float)((float)(*v16 * *v16)
                                                                            + (float)(v16[1] * v16[1])))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v19
                                                                                    * (float)((float)((float)(v16[2] * v16[2]) + (float)((float)(*v16 * *v16) + (float)(v16[1] * v16[1])))
                                                                                            * (float)0.5))
                                                                            * (float)v19)
                                                                    - (float)1.5)
                                                    * (float)v19))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v19
                                                            * (float)((float)((float)(v16[2] * v16[2])
                                                                            + (float)((float)(*v16 * *v16)
                                                                                    + (float)(v16[1] * v16[1])))
                                                                    * (float)0.5))
                                                    * (float)v19)
                                            - (float)1.5)
                            * (float)v19));
        v21 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)(v16[2] * v16[2]) + (float)((float)(*v16 * *v16) + (float)(v16[1] * v16[1]))) * (float)0.5)) * (float)v19) - (float)1.5)
                                                                                            * (float)v19)
                                                                                    * (float)((float)((float)(v16[2] * v16[2]) + (float)((float)(*v16 * *v16) + (float)(v16[1] * v16[1])))
                                                                                            * (float)0.5))
                                                                            * (float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)(v16[2] * v16[2]) + (float)((float)(*v16 * *v16) + (float)(v16[1] * v16[1]))) * (float)0.5)) * (float)v19) - (float)1.5)
                                                                                    * (float)v19))
                                                                    - (float)1.5)
                                                    * (float)((float)-(float)((float)((float)((float)v19
                                                                                            * (float)((float)((float)(v16[2] * v16[2]) + (float)((float)(*v16 * *v16) + (float)(v16[1] * v16[1]))) * (float)0.5))
                                                                                    * (float)v19)
                                                                            - (float)1.5)
                                                            * (float)v19))
                                            * (float)((float)((float)(v16[2] * v16[2])
                                                            + (float)((float)(*v16 * *v16) + (float)(v16[1] * v16[1])))
                                                    * (float)0.5))
                                    * (float)v20)
                            - (float)1.5);
        if ( (float)((float)((float)v21
                           * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)(v16[2] * v16[2]) + (float)((float)(*v16 * *v16) + (float)(v16[1] * v16[1]))) * (float)0.5)) * (float)v19)
                                                                                           - (float)1.5)
                                                                           * (float)v19)
                                                                   * (float)((float)((float)(v16[2] * v16[2])
                                                                                   + (float)((float)(*v16 * *v16)
                                                                                           + (float)(v16[1] * v16[1])))
                                                                           * (float)0.5))
                                                           * (float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)(v16[2] * v16[2]) + (float)((float)(*v16 * *v16) + (float)(v16[1] * v16[1]))) * (float)0.5))
                                                                                           * (float)v19)
                                                                                   - (float)1.5)
                                                                   * (float)v19))
                                                   - (float)1.5)
                                   * (float)((float)-(float)((float)((float)((float)v19
                                                                           * (float)((float)((float)(v16[2] * v16[2])
                                                                                           + (float)((float)(*v16 * *v16) + (float)(v16[1] * v16[1])))
                                                                                   * (float)0.5))
                                                                   * (float)v19)
                                                           - (float)1.5)
                                           * (float)v19)))
                   * (float)((float)(v16[2] * v16[2]) + (float)((float)(*v16 * *v16) + (float)(v16[1] * v16[1])))) >= 3.0 )
          goto LABEL_19;
        v22 = idVehicleAI::GetVehicleCar(this);
        v23 = idEntity::GetPhysics(this: v22);
        v24 = (float *)v23->GetAxis(this: v23, a2: 0);
        v25 = (float)((float)((float)(vec3_up.x * *v24)
                            + (float)((float)(v24[1] * vec3_up.y) + (float)(v24[2] * vec3_up.z)))
                    * (float)5.0);
        v27 = idVehicleAI::GetVehicleCar(this);
        v28 = v25;
        v29 = 0.0;
      }
      idVehicle_Car::UpdateStickControl(this: v27, xFrac: v29, yFrac: v28, a4: v26);
    }
  }
LABEL_19:
  v33 = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v33 & 0x1FFF] == v33 >> 13
    && (v34 = (idVehicle_Car *)gameLocal->entities.ptr[v33 & 0x1FFF]) != nullptr )
  {
    v35 = idVehicle_Car::CastTo(c: v34);
  }
  else
  {
    v35 = nullptr;
  }
  presentable = v35->presentable;
  desiredSteering = this->desiredSteering;
  if ( presentable != nullptr )
    v38 = presentable->GetVehicleInterface(this: presentable);
  else
    v38 = nullptr;
  idPresentableVehicle::UpdateSteerAngle(this: v38, idealSteerAngle: desiredSteering);
  idVehicleAI::ApplyMovement(
    this,
    speed: this->desiredSpeed,
    wheelForce: this->desiredWheelForce,
    braking: v40,
    a5: v39,
    a6: this->desiredBraking);
  idVehicleAI::DrawDebug(this, a2: v42, a3: v41);
}


// ========================================================================
// ?GetSplineImmediateGoal@idVehicleAI@@IAAXXZ
// EA  : 0x82B14DC8
// RVA : 0x00B14DC8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::GetSplineImmediateGoal(idVehicleAI *this)
{
  __int64 v2; // r3
  int v3; // r9
  bool v4; // r8
  idNavPathPosTracker *p_null_splineTracker; // r11
  int v6; // r10
  __int64 v7; // r6
  idNavPathPosTracker *v8; // r11
  float v9; // r9
  float v10; // r8
  idVec3 *v11; // r3
  float v12; // r6
  double v13; // fp13
  double v14; // fp0
  double SplineWidth; // fp30
  double v16; // fp29
  double TraversalStepSize; // fp31
  int value; // r9
  int v19; // r4
  idVehicle_Car *v20; // r3
  idVehicle_Car *v21; // r3
  idPhysics *Physics; // r3
  idBounds *v23; // r3
  double RadiusXY; // fp1
  double v25; // fp26
  __int64 v26; // r3
  idNavPathPosTracker *splineTracker; // r11
  float distance; // r6
  idNavSplinePosition *splinePathMgr; // r4
  double FacingDir; // fp1
  idNavPathPosTracker *v32; // r11
  double v33; // fp30
  float rightDistance; // r9
  float v35; // r8
  idVec3 *WorldPos; // r3
  float x; // r6
  float z; // r7
  double y; // fp0
  double v40; // fp12
  idVec3 *Right; // r3
  double v42; // fp26
  double v43; // fp25
  double v44; // fp30
  idVec3 *SplineWorldPos; // r3
  double v46; // fp4
  double v47; // fp3
  idVec3 *p_immediateGoalPosition; // r30
  idNavPathPosTracker *v49; // r11
  float v50; // r9
  idNavSpline *navSpline; // r8
  idVehicle_Car *VehicleCar; // r3
  idPhysics *v53; // r3
  float v54; // r8
  float v55; // r7
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // r5
  float *v57; // r3
  double v58; // fp7
  double v59; // fp6
  idVehicle_Car *v60; // r3
  idPhysics *v61; // r3
  float *v62; // r3
  bool v63; // r11
  idNavPathPosTracker *v64; // r11
  float v65; // r8
  idVehicle_Car *v66; // r3
  idPhysics *v67; // r3
  int v68; // r3
  idNavPathPosTracker *v69; // r11
  float *v70; // r29
  float v71; // r10
  float v72; // r9
  idVec3 *Forward; // r3
  double valueFloat; // fp0
  idVec3 *v77; // r3
  float v78; // r7
  float v79; // r8
  double v80; // fp8
  double v81; // fp6
  float v82; // r9
  float v83; // r11
  double v84; // fp12
  int v85; // [sp+8h] [-138h]
  __int64 v86; // [sp+10h] [-130h]
  __int64 v87; // [sp+18h] [-128h]
  __int64 v88; // [sp+20h] [-120h]
  __int64 v89; // [sp+28h] [-118h]
  __int64 v90; // [sp+30h] [-110h]
  float v91; // [sp+50h] [-F0h]
  idVec3 v92; // [sp+58h] [-E8h] BYREF
  idVec3 v93; // [sp+68h] [-D8h] BYREF
  idNavSplinePosition v94; // [sp+78h] [-C8h] BYREF
  idVec3 v95; // [sp+88h] [-B8h] BYREF
  idVec3 v96; // [sp+98h] [-A8h] BYREF
  idVec3 v97; // [sp+A8h] [-98h] BYREF
  idNavSplinePosition v98; // [sp+B8h] [-88h] BYREF
  idVec3 v99; // [sp+C8h] [-78h] BYREF

  vaiTimer.determineGoal_path.state = TS_STARTED;
  LODWORD(v2) = (unsigned __int64)Sys_GetClockTicks() >> 32;
  vaiTimer.determineGoal_path.start = v2;
  idNavSplinePathMgr::GetShortestPath(
    this: (idNavSplinePathMgr *)LODWORD(this->splineTracker->pathPosition.distance),
    start: (idNavSplinePosition *)LODWORD(this->splineTracker->pathPosition.rightDistance),
    end: (idNavSplinePosition *)__ROL4__(this->splineTracker->pathPosition.navSpline, 32),
    path: (navSplinePath_t *)LODWORD(this->splineTracker->goalPathPosition.rightDistance));
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)this->splinePathMgr);
  if ( this->splineTracker->pathToGoal.path.num >= 1 )
  {
    idTimer::Stop(this: &vaiTimer.determineGoal_path);
    idVehicleAI::CalcDistanceToFinalGoal(this, path: &this->splineTracker->pathToGoal);
    SplineWidth = idNavPathPosTracker::GetSplineWidth(this: this->splineTracker);
    v16 = (float)(vai_immediateGoalScanScale.valueFloat * (float)SplineWidth);
    v91 = 0.0;
    if ( vai_traversalStepSize.valueFloat == -1.0 )
      TraversalStepSize = idVehicleAI::GetTraversalStepSize(this);
    else
      TraversalStepSize = vai_traversalStepSize.valueFloat;
    value = this->vehicleCar.spawnId.value;
    v19 = gameLocal->spawnIds.ptr[value & 0x1FFF];
    LODWORD(v92.y) = (int)(float)((float)((float)v16 / (float)TraversalStepSize) + (float)1.0);
    if ( v19 == value >> 13 && (v20 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      v21 = idVehicle_Car::CastTo(c: v20);
    else
      v21 = nullptr;
    Physics = idEntity::GetPhysics(this: v21);
    v23 = (idBounds *)Physics->GetBounds(this: Physics, a2: -1);
    RadiusXY = idBounds::GetRadiusXY(this: v23);
    vaiTimer.determineGoal_distWangle.state = TS_STARTED;
    v25 = (float)((float)RadiusXY * (float)0.40000001);
    LODWORD(v26) = (unsigned __int64)Sys_GetClockTicks() >> 32;
    vaiTimer.determineGoal_distWangle.start = v26;
    splineTracker = this->splineTracker;
    distance = splineTracker->pathPosition.distance;
    v94.rightDistance = splineTracker->pathPosition.rightDistance;
    splinePathMgr = (idNavSplinePosition *)this->splinePathMgr;
    v94.navSpline = splineTracker->pathPosition.navSpline;
    v94.distance = distance;
    idNavSplinePathMgr::GetFurthestPositionAlongPath(
      this: (idNavSplinePathMgr *)&v95,
      result: splinePathMgr,
      splinePath: &splineTracker->pathToGoal,
      rightDistance: v94.rightDistance,
      adjustWidth: -v25,
      step: TraversalStepSize,
      iterations: SLODWORD(distance),
      distanceMoved: (float *)v94.navSpline);
    idTimer::Stop(this: &vaiTimer.determineGoal_distWangle);
    _FP31 = this->goalRightDistance;
    if ( (float)(idNavSplinePosition::GetSplineWidth(this: (idNavSplinePosition *)&v95, dist: -1.0) - (float)v25) < __fabs(_FP31) )
      __asm { fsel      f31, f31, f0, f13 }
    if ( _FP31 >= -SplineWidth )
    {
      if ( _FP31 > SplineWidth )
        _FP31 = SplineWidth;
    }
    else
    {
      _FP31 = -SplineWidth;
    }
    FacingDir = idNavSplinePathMgr::GetFacingDir(
                  this: this->splinePathMgr,
                  splinePath: &this->splineTracker->pathToGoal,
                  maxLength: v91);
    v32 = this->splineTracker;
    v33 = FacingDir;
    if ( (float)(v32->pathToGoal.distance - v91) < 1.0 && (this->stoppingGoal || this->passThroughGoal) )
    {
      rightDistance = v32->goalPathPosition.rightDistance;
      v35 = *(float *)&v32->goalPathPosition.navSpline;
      v97.x = v32->goalPathPosition.distance;
      v97.y = rightDistance;
      v97.z = v35;
      WorldPos = idNavSplinePosition::GetWorldPos(this: &v94, result: &v97);
      x = WorldPos->x;
      z = WorldPos->z;
      v92.y = WorldPos->y;
      y = v92.y;
      v92.x = x;
      v92.z = z;
      this->immediateGoalPosition.z = z;
      v40 = v92.x;
      this->immediateGoalPosition.y = y;
      this->immediateGoalPosition.x = v40;
    }
    else
    {
      Right = idNavSplinePosition::GetRight(this: &v94, result: &v95);
      v42 = (float)((float)(Right->x * (float)_FP31) * (float)v33);
      v43 = (float)((float)(Right->y * (float)_FP31) * (float)v33);
      v44 = (float)((float)(Right->z * (float)_FP31) * (float)v33);
      SplineWorldPos = idNavSplinePosition::GetSplineWorldPos(this: (idNavSplinePosition *)&v92, result: &v95);
      v46 = (float)(SplineWorldPos->y + (float)v43);
      v47 = (float)(SplineWorldPos->z + (float)v44);
      this->immediateGoalPosition.x = (float)v42 + SplineWorldPos->x;
      this->immediateGoalPosition.y = v46;
      this->immediateGoalPosition.z = v47;
    }
    p_immediateGoalPosition = &this->immediateGoalPosition;
    if ( !this->allowUTurnOnNarrowPath && !idNavSpline::IsDeadEnd(this: (idNavSpline *)LODWORD(v95.z)) )
    {
      v49 = this->splineTracker;
      v50 = v49->pathPosition.rightDistance;
      navSpline = v49->pathPosition.navSpline;
      v98.distance = v49->pathPosition.distance;
      v98.rightDistance = v50;
      v98.navSpline = navSpline;
      if ( !idNavSplinePosition::IsOnDeadendPath(this: &v98)
        && idNavPathPosTracker::GetSplineWidth(this: this->splineTracker) < (double)this->setup.narrowPathDistance )
      {
        this->steerFlags |= 2u;
        VehicleCar = idVehicleAI::GetVehicleCar(this);
        v53 = idEntity::GetPhysics(this: VehicleCar);
        v54 = this->immediateGoalPosition.y;
        v55 = this->immediateGoalPosition.z;
        GetOrigin = v53->GetOrigin;
        v94.distance = p_immediateGoalPosition->x;
        v94.rightDistance = v54;
        *(float *)&v94.navSpline = v55;
        v57 = (float *)GetOrigin(this: v53, a2: 0);
        v58 = (float)(v94.rightDistance - v57[1]);
        v59 = (float)(*(float *)&v94.navSpline - v57[2]);
        v92.x = v94.distance - *v57;
        v92.y = v58;
        v92.z = v59;
        idVec3::NormalizeFast(this: &v92);
        v60 = idVehicleAI::GetVehicleCar(this);
        v61 = idEntity::GetPhysics(this: v60);
        v62 = (float *)v61->GetAxis(this: v61, a2: 0);
        v63 = (float)((float)(*v62 * v92.x) + (float)((float)(v62[2] * v92.z) + (float)(v62[1] * v92.y))) < 0.0;
        if ( this->desiredSpeed < 0.0 )
          v63 = (_cntlzw((float)((float)(*v62 * v92.x) + (float)((float)(v62[2] * v92.z) + (float)(v62[1] * v92.y))) < 0.0)
               & 0x20) != 0;
        if ( v63 )
        {
          v64 = this->splineTracker;
          v65 = *(float *)&v64->pathPosition.navSpline;
          v93.x = v64->pathPosition.distance;
          v93.y = _FP31;
          v93.z = v65;
          v66 = idVehicleAI::GetVehicleCar(this);
          v67 = idEntity::GetPhysics(this: v66);
          v68 = (int)v67->GetAxis(this: v67, a2: 0);
          v69 = this->splineTracker;
          v70 = (float *)v68;
          v71 = v69->pathPosition.rightDistance;
          v72 = *(float *)&v69->pathPosition.navSpline;
          v99.x = v69->pathPosition.distance;
          v99.y = v71;
          v99.z = v72;
          Forward = idNavSplinePosition::GetForward(this: &v94, result: &v99);
          valueFloat = vai_traversalStepSize.valueFloat;
          if ( (float)((float)(Forward->x * *v70) + (float)((float)(Forward->z * v70[2]) + (float)(Forward->y * v70[1]))) <= 0.0 )
          {
            if ( valueFloat == -1.0 )
              valueFloat = -idVehicleAI::GetTraversalStepSize(this);
            else
              valueFloat = -valueFloat;
          }
          else if ( valueFloat == -1.0 )
          {
            valueFloat = idVehicleAI::GetTraversalStepSize(this);
          }
          v94.rightDistance = v93.y;
          _FP13 = this->desiredSpeed;
          __asm { fsel      f12, f13, f29, f28 }
          v94.distance = (float)((float)_FP12 * (float)valueFloat) + v93.x;
          v93.x = v94.distance;
          v77 = idNavSplinePosition::GetWorldPos(this: (idNavSplinePosition *)&v92, result: &v93);
          v78 = v77->x;
          v79 = v77->y;
          v94.navSpline = (idNavSpline *)LODWORD(v77->z);
          v80 = *(float *)&v94.navSpline;
          v94.distance = v78;
          v94.rightDistance = v79;
          this->immediateGoalPosition.y = v79;
          v81 = v94.distance;
          this->immediateGoalPosition.z = v80;
          p_immediateGoalPosition->x = v81;
        }
      }
    }
    v82 = this->immediateGoalPosition.z;
    v83 = p_immediateGoalPosition->x;
    v94.rightDistance = this->immediateGoalPosition.y;
    v84 = v94.rightDistance;
    *(float *)&v94.navSpline = v82;
    this->desiredGoalPosition[0].x = v83;
    this->desiredGoalPosition[0].z = *(float *)&v94.navSpline;
    this->desiredGoalPosition[0].y = v84;
  }
  else
  {
    idTimer::Stop(this: &vaiTimer.determineGoal_path);
    p_null_splineTracker = this->splineTracker;
    if ( p_null_splineTracker == nullptr )
      p_null_splineTracker = &this->splinePathMgr->null_splineTracker;
    v6 = (int)p_null_splineTracker->pathPosition.navSpline;
    LODWORD(v7) = 1;
    HIDWORD(v7) = __ROL4__(v6, 32);
    idVehicleAI::MoveToPathPosition(
      this,
      isStoppingGoal: v7,
      passThroughGoal: false,
      a4: v4,
      a5: v3,
      a6: v6,
      a7: v85,
      a8: v86,
      a9: v87,
      a10: v88,
      a11: v89,
      a12: v90);
    v8 = this->splineTracker;
    if ( v8 == nullptr )
      v8 = &this->splinePathMgr->null_splineTracker;
    v9 = v8->pathPosition.rightDistance;
    v10 = *(float *)&v8->pathPosition.navSpline;
    v96.x = v8->pathPosition.distance;
    v96.y = v9;
    v96.z = v10;
    v11 = idNavSplinePosition::GetWorldPos(this: &v94, result: &v96);
    v12 = v11->y;
    v13 = v11->z;
    v93.x = v11->x;
    v93.y = v12;
    this->immediateGoalPosition.y = v12;
    v14 = v93.x;
    this->immediateGoalPosition.z = v13;
    this->immediateGoalPosition.x = v14;
  }
}


// ========================================================================
// ?ContinueToEngageEnemy@idVehicleAI@@QAA_NXZ
// EA  : 0x82B15478
// RVA : 0x00B15478
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall idVehicleAI::ContinueToEngageEnemy(idVehicleAI *this)
{
  idNavPathPosTracker *enemyTracker; // r3
  idEntity *v4; // r30
  int value; // r10
  idEntity *v6; // r3
  idEntity *v7; // r3
  idNavPathPosTracker *v8; // r3
  char v9; // r26
  int v10; // r27
  idGameLocal *v11; // r9
  int v12; // r28
  vehicleAiSetup_t::engage_t::guardEntity_t *v13; // r30
  idNavPathPosTracker *v14; // r3
  idEntity *Owner; // r29
  idSplineWaypoint *v16; // r3
  int v17; // r28
  int v18; // r29
  int v19; // r8
  idEntity *v20; // r3
  idSplineWaypoint *v21; // r30
  idNavPathPosTracker *v22; // r3
  idEntity *v23; // r4
  idNavPathPosTracker *v24; // r3
  idEntity *v25; // r3
  int v26; // r3
  idNavPathPosTracker *v27; // r3
  idPlayer *v28; // r3
  idPlayer *v29; // r3
  idNavPathPosTracker *v30; // r3
  char v31; // r28
  bool v32; // r29
  __int64 v33; // r8 OVERLAPPED
  double CurrentSpeedInMPH; // fp1
  vehicleAiSetup_t::attack_t *currentAttack; // r11
  double minSpeed; // fp0
  double maxSpeed; // fp0
  int attempts; // r11
  int v39; // r9
  idVehicleState *v40; // r30
  idVehicleState_vtbl *v41; // r29
  double AttackRange; // fp1

  if ( (unsigned __int8)idVehicleAI::DebugForceAttack(this) != 0 )
    return 1;
  enemyTracker = this->enemyTracker;
  if ( this->ignoreEnemy )
  {
    if ( enemyTracker != nullptr && idNavPathPosTracker::GetOwner(this: enemyTracker) != nullptr )
      this->setup.engage.alertSoundTime = 0;
    this->enemyTracker = nullptr;
    this->target.spawnId.value = 0x1FFF;
    return 0;
  }
  v4 = enemyTracker != nullptr ? idNavPathPosTracker::GetOwner(this: enemyTracker) : nullptr;
  value = this->specificEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v7 = idEntity::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  if ( v4 == v7 )
    return 1;
  v8 = this->enemyTracker;
  v9 = 1;
  if ( v8 == nullptr || idNavPathPosTracker::GetOwner(this: v8) == nullptr )
    goto LABEL_52;
  if ( idNavPathPosTracker::GetOwner(this: this->enemyTracker) != nullptr && !this->setup.forcePlayerEnemy )
  {
    v10 = 0;
    if ( this->setup.engage.guard.num > 0 )
    {
      v11 = gameLocal;
      v12 = 0;
      while ( 1 )
      {
        v13 = &this->setup.engage.guard.list[v12];
        if ( v13->disengageDist == -1.0 )
        {
          if ( this->setup.engage.extension.num <= 0 )
            goto LABEL_33;
        }
        else if ( v11->spawnIds.ptr[v13->entity.spawnId.value & 0x1FFF] == v13->entity.spawnId.value >> 13 )
        {
          v14 = this->enemyTracker;
          if ( v14 != nullptr )
            Owner = idNavPathPosTracker::GetOwner(this: v14);
          else
            Owner = nullptr;
          v16 = (idSplineWaypoint *)idEntityPtr<idEntity const>::operator->(this: &v13->entity);
          if ( idVehicleAI::GetGuardDistance(this, enemy: Owner, guard: v16) <= (double)this->setup.engage.guard.list[v12].disengageDist )
            break;
          v11 = gameLocal;
        }
        ++v10;
        ++v12;
        if ( v10 >= this->setup.engage.guard.num )
          goto LABEL_33;
      }
    }
    v11 = gameLocal;
LABEL_33:
    v17 = 0;
    if ( this->setup.engage.extension.num > 0 )
    {
      v18 = 0;
      do
      {
        v19 = this->setup.engage.extension.list[v18].entity.spawnId.value;
        if ( v11->spawnIds.ptr[v19 & 0x1FFF] == v19 >> 13 )
        {
          v20 = v11->entities.ptr[v19 & 0x1FFF];
          if ( v20 != nullptr )
            v21 = (idSplineWaypoint *)idEntity::CastTo(c: v20);
          else
            v21 = nullptr;
          v22 = this->enemyTracker;
          if ( v22 != nullptr )
            v23 = idNavPathPosTracker::GetOwner(this: v22);
          else
            v23 = nullptr;
          if ( idVehicleAI::GetGuardDistance(this, enemy: v23, guard: v21) <= (double)this->setup.engage.extension.list[v18].engageDist )
            break;
          v11 = gameLocal;
        }
        ++v17;
        ++v18;
      }
      while ( v17 < this->setup.engage.extension.num );
    }
    if ( v10 == this->setup.engage.guard.num )
      v9 = this->setup.engage.extension.num != v17;
  }
  v24 = this->enemyTracker;
  v25 = v24 != nullptr ? idNavPathPosTracker::GetOwner(this: v24) : nullptr;
  v26 = (int)v25->GetHealthComponent_2(this: v25);
  if ( v26 == 0 || (*(unsigned __int8 (__fastcall **)(int))(*(_DWORD *)v26 + 88))(a1: v26) != 0 )
LABEL_52:
    v9 = 0;
  v27 = this->enemyTracker;
  if ( v27 != nullptr )
    v28 = (idPlayer *)idNavPathPosTracker::GetOwner(this: v27);
  else
    v28 = nullptr;
  v29 = idPlayer::CastTo(c: v28);
  if ( v29 != nullptr )
    v9 = (*((_BYTE *)v29 + 12824) & 8) != 0 ? 0 : v9;
  if ( v9 != 0 )
  {
    v31 = 0;
    v32 = false;
    if ( this->currentAttack != nullptr )
    {
      CurrentSpeedInMPH = idNavPathPosTracker::GetCurrentSpeedInMPH(this: this->enemyTracker);
      currentAttack = this->currentAttack;
      minSpeed = currentAttack->params.minSpeed;
      if ( minSpeed == -1.0 )
        minSpeed = currentAttack->decl->params.minSpeed;
      if ( CurrentSpeedInMPH < (float)((float)minSpeed - (float)5.0) )
        goto LABEL_70;
      maxSpeed = currentAttack->params.maxSpeed;
      if ( maxSpeed == -1.0 )
        maxSpeed = currentAttack->decl->params.maxSpeed;
      if ( CurrentSpeedInMPH > (float)((float)maxSpeed + (float)5.0) )
LABEL_70:
        v31 = 1;
      if ( currentAttack->params.attempts == -1 )
        attempts = currentAttack->decl->params.attempts;
      else
        attempts = currentAttack->params.attempts;
      v39 = attempts;
      LODWORD(v33) = this->numAttackAttempts;
      v32 = (float)v33 >= (double)(float)*(__int64 *)((char *)&v33 - 4);
    }
    v40 = idVehicleState::CastTo(c: (idVehicleState *)this->attackFSM.curState);
    if ( this->nextAttackTime <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED)
      || v31 != 0
      || v32
      || v40 != nullptr
      && (v41 = v40->__vftable,
          AttackRange = idVehicleAI::GetAttackRange(this),
          !v41->ValidAttack(this: v40, a2: AttackRange)) )
    {
      idVehicleAI::ChooseAttackState(this);
    }
    return 1;
  }
  v30 = this->enemyTracker;
  if ( v30 != nullptr && idNavPathPosTracker::GetOwner(this: v30) != nullptr )
    this->setup.engage.alertSoundTime = 0;
  this->enemyTracker = nullptr;
  this->target.spawnId.value = 0x1FFF;
  idVehicleAI::SetAttackState(this, stateType: &idVS_Idle::Type, delayTime: 0, pushState: false);
  return 0;
}


// ========================================================================
// ?Event_AiExitVehicle@idVehicleAI@@QAA?AVeventVoid@@XZ
// EA  : 0x82B15988
// RVA : 0x00B15988
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

idVehicleAI *__fastcall idVehicleAI::Event_AiExitVehicle(idVehicleAI *this, idVehicleAI *result)
{
  int value; // r10
  idVehicle_Car *v5; // r3
  int v6; // r9
  idVehicle_Car *v7; // r3
  idVehicle_Car *v8; // r4

  value = result->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v5 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v5 != nullptr && idVehicle_Car::CastTo(c: v5) != nullptr )
    {
      v6 = result->vehicleCar.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v6 & 0x1FFF] == v6 >> 13
        && (v7 = (idVehicle_Car *)gameLocal->entities.ptr[v6 & 0x1FFF]) != nullptr )
      {
        v8 = idVehicle_Car::CastTo(c: v7);
      }
      else
      {
        v8 = nullptr;
      }
      idVehicleAI::UseVehicle(this: result, entity: v8, seat: SEAT_MAX);
    }
  }
  return this;
}


// ========================================================================
// ?OnActivate@idVehicleAI@@UAAXPAVidEntity@@@Z
// EA  : 0x82B15A48
// RVA : 0x00B15A48
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::OnActivate(idVehicleAI *this, idEntity *activator)
{
  int mCurrentCommand; // r10
  int num; // r11
  vehicleAiSetup_t::commands_t *v5; // r31
  idVehicle_Car *VehicleCar; // r3
  idVehicle_Car *v7; // r3

  if ( (((int (__fastcall *)(idGameLocal *, idEntity *))gameLocal->GetGameFlags)(a1: gameLocal, a2: activator) & 2) == 0 )
  {
    if ( this->vehicleWasActive )
    {
      if ( this->triggerAction != TA_CONTINUE_EVALUATING_COMMANDS
        || (mCurrentCommand = this->cs_NextCommand.mCurrentCommand) < 0
        || (num = this->setup.commands.num) <= 0 )
      {
        if ( (this->thinkFlags & 1) != 0 )
        {
          idEntity::BecomeInactive(this, flags: 1);
        }
        else
        {
          if ( idVehicleAI::GetVehicleCar(this) != nullptr )
          {
            VehicleCar = idVehicleAI::GetVehicleCar(this);
            if ( ((double (__fastcall *)(idVehicle_Car *))VehicleCar->GetHealth)(a1: VehicleCar) <= 0.0 )
              idVehicleAI::Respawn(this);
          }
          idEntity::BecomeActive(this, flags: 1);
          if ( idVehicleAI::GetVehicleCar(this) != nullptr )
          {
            v7 = idVehicleAI::GetVehicleCar(this);
            v7->Show(this: v7);
          }
        }
      }
      else if ( mCurrentCommand < num )
      {
        v5 = &this->setup.commands.list[mCurrentCommand];
        if ( v5->type == CMD_WAIT_FOR_TRIGGER )
          v5->trigger.triggerTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      }
    }
    else
    {
      idVehicleAI::ActivateVehicle(this, vehicle: nullptr);
    }
  }
}


// ========================================================================
// ?Event_Respawn@idVehicleAI@@QAA?AVeventVoid@@XZ
// EA  : 0x82B15BB0
// RVA : 0x00B15BB0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

idVehicleAI *__fastcall idVehicleAI::Event_Respawn(idVehicleAI *this, idVehicleAI *result)
{
  idVehicleAI::Respawn(this: result);
  return this;
}


// ========================================================================
// ?PushControlParams@idVehicleAI@@QAAXXZ
// EA  : 0x82B15BE8
// RVA : 0x00B15BE8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::PushControlParams(idVehicleAI *this)
{
  idList<vaiControl_t,5>::Append(this: &this->controlStack, obj: &this->control);
}


// ========================================================================
// ?HandleDeath@idVehicleAI@@IAAXXZ
// EA  : 0x82B15E48
// RVA : 0x00B15E48
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::HandleDeath(idVehicleAI *this)
{
  idNavPathPosTracker *splineTracker; // r4
  BOOL clearEnemyTracker; // r11
  idTarget_DynamicVehicleAiController *v4; // r30
  idEntity *v5; // r3
  idEntity *v6; // r29
  idEventArg *v7; // r3
  idTarget_DynamicVehicleAiController *dynamicVehicleAIController; // r3
  idTarget_DynamicVehicleAiController *v9; // r3
  int ShouldVehicleRespawn; // r5
  vehicleAiSetup_t::death_t::respawnType_t respawnType; // r11
  int numWaves; // r11
  idEventArg *v13; // r3
  char *v14; // r10
  _DWORD *v15; // r11
  int i; // ctr
  int triggerAfterWaveMilliSec; // r30
  idEntity *v18; // r3
  __int64 v19; // r7
  int v20; // r5
  __int64 v21; // r7
  char v22; // [sp+5Ch] [-74h] BYREF
  idEventArg v23; // [sp+60h] [-70h] BYREF
  idEventArg v24[4]; // [sp+80h] [-50h] BYREF

  splineTracker = this->splineTracker;
  if ( splineTracker != nullptr )
  {
    idNavSplinePathMgr::ReleaseTracker(this: this->splinePathMgr, tracker: splineTracker);
    clearEnemyTracker = this->setup.death.clearEnemyTracker;
    v4 = nullptr;
    this->splineTracker = nullptr;
    if ( clearEnemyTracker )
      this->enemyTracker = nullptr;
    if ( gameLocal->spawnIds.ptr[this->setup.death.trigger.spawnId.value & 0x1FFF] == this->setup.death.trigger.spawnId.value >> 13 )
    {
      v5 = gameLocal->entities.ptr[this->setup.death.trigger.spawnId.value & 0x1FFF];
      if ( v5 != nullptr )
        v6 = idEntity::CastTo(c: v5);
      else
        v6 = nullptr;
      v7 = idEventArg::idEventArg(this: &v23, data: this);
      idEventReceiver::PostEventMS(
        this: v6,
        ev: &EV_Activate,
        time: *(_DWORD *)&v7->type,
        arg1: (const idEventArg *)LODWORD(v7->value.v[1]));
    }
    dynamicVehicleAIController = (idTarget_DynamicVehicleAiController *)this->dynamicVehicleAIController;
    if ( dynamicVehicleAIController != nullptr )
    {
      v9 = idTarget_DynamicVehicleAiController::CastTo(c: dynamicVehicleAIController);
      v4 = v9;
      if ( v9 != nullptr )
        idTarget_DynamicVehicleAiController::VehicleKilled(this: v9, vehAI: this);
    }
    idVehicleAI::ResetStates(this);
    if ( v4 != nullptr )
    {
      ShouldVehicleRespawn = idTarget_DynamicVehicleAiController::WhenShouldVehicleRespawn(this: v4, vehAI: this);
      if ( ShouldVehicleRespawn < 0 )
        idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
      else
        idEventReceiver::PostEventMS(this, ev: &EV_Respawn, time: ShouldVehicleRespawn);
      return;
    }
    respawnType = this->setup.death.respawnType;
    if ( respawnType == NO_RESPAWN )
    {
LABEL_17:
      idEventReceiver::PostEventMS(this, ev: &EV_Remove, time: 0);
      return;
    }
    if ( respawnType != DO_NOTHING )
    {
      if ( vai_instantRespawn.valueInteger != 0 )
      {
LABEL_20:
        idVehicleAI::Respawn(this);
        return;
      }
      if ( this->setup.death.respawns != 0 )
      {
        if ( this->setup.death.minRespawnTime == 0.0 && this->setup.death.maxRespawnTime == 0.0 )
          goto LABEL_20;
        HIDWORD(v21) = 1664525 * clientGame->random.seed + 1013904223;
        clientGame->random.seed = HIDWORD(v21);
        if ( (this->thinkFlags & 1) != 0 )
        {
          LODWORD(v21) = (HIDWORD(v21) >> 10) & 0x7FFF;
          v20 = (int)(float)((float)((float)((float)v21
                                           * (float)(this->setup.death.maxRespawnTime - this->setup.death.minRespawnTime))
                                   * (float)0.030518509)
                           + (float)(this->setup.death.minRespawnTime * (float)1000.0));
          goto LABEL_34;
        }
      }
      else
      {
        numWaves = this->setup.death.numWaves;
        if ( numWaves > 0 )
        {
          this->setup.death.numWaves = numWaves - 1;
          if ( gameLocal->spawnIds.ptr[this->setup.death.triggerAfterWave.spawnId.value & 0x1FFF] == this->setup.death.triggerAfterWave.spawnId.value >> 13 )
          {
            v13 = idEventArg::idEventArg(this: v24, data: this);
            v14 = &v22;
            v15 = (_DWORD *)&v13[-1].value.q[3];
            for ( i = 5; i != 0; --i )
            {
              ++v15;
              v14 += 4;
              *(_DWORD *)v14 = *v15;
            }
            triggerAfterWaveMilliSec = this->setup.death.triggerAfterWaveMilliSec;
            v18 = idEntityPtr<idEntity const>::operator->(this: &this->setup.death.triggerAfterWave);
            idEventReceiver::PostEventMS(
              this: v18,
              ev: &EV_Activate,
              time: triggerAfterWaveMilliSec,
              arg1: (const idEventArg *)LODWORD(v23.value.v[1]));
          }
        }
        if ( this->setup.death.numWaves == 0 )
          goto LABEL_17;
        this->setup.death.respawns = this->setup.death.numRespawns;
        HIDWORD(v19) = 1664525 * clientGame->random.seed;
        clientGame->random.seed = HIDWORD(v19) + 1013904223;
        if ( (this->thinkFlags & 1) != 0 )
        {
          LODWORD(v19) = ((unsigned int)(HIDWORD(v19) + 1013904223) >> 10) & 0x7FFF;
          v20 = (int)(float)((float)((float)((float)(this->setup.death.waveMinDelayTime
                                                   - this->setup.death.waveMaxDelayTime)
                                           * (float)v19)
                                   * (float)0.030518509)
                           + (float)(this->setup.death.waveMinDelayTime * (float)1000.0));
LABEL_34:
          idEventReceiver::PostEventMS(this, ev: &EV_Respawn, time: v20);
        }
      }
    }
    idEntity::BecomeInactive(this, flags: 1);
  }
}


// ========================================================================
// ?DetermineImmediateGoal@idVehicleAI@@QAAXXZ
// EA  : 0x82B161E0
// RVA : 0x00B161E0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::DetermineImmediateGoal(idVehicleAI *this)
{
  __int64 v2; // r3

  vaiTimer.determineGoal.state = TS_STARTED;
  LODWORD(v2) = (unsigned __int64)Sys_GetClockTicks() >> 32;
  vaiTimer.determineGoal.start = v2;
  ++vaiTimer.determineGoal_count;
  if ( this->pathType == VEHICLE_PATH_SPLINE )
    idVehicleAI::GetSplineImmediateGoal(this);
  idTimer::Stop(this: &vaiTimer.determineGoal);
}


// ========================================================================
// ?CollectObstacles@idVehicleAI@@QAAXPBVidPhysics@@ABVidVec3@@1M@Z
// EA  : 0x82B16258
// RVA : 0x00B16258
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

// bad sp value at call has been detected, the output may be wrong!
void __fastcall idVehicleAI::CollectObstacles(
        idVehicleAI *this,
        const idPhysics *physics,
        const idVec3 *startPos,
        const idVec3 *seekPos,
        double radius)
{
  double v5; // fp31
  idVehicleAI *v6; // r3
  idVehicleAI *v7; // r27
  int v8; // r4
  int v9; // r23
  float *v10; // r5
  float *v11; // r30
  unsigned __int64 v12; // r6
  const char *v13; // r7
  int value; // r9
  idVehicle_Car *v15; // r3
  idPhysics *v16; // r3
  int v17; // r3
  double v18; // fp0
  double v19; // fp13
  double v20; // fp8
  double v21; // fp5
  double v22; // fp4
  unsigned __int64 index; // r11
  char v24; // r11
  bool v25; // zf
  int GatheredEntities; // r3
  int *v27; // r28
  int i; // r26
  int v29; // r9
  idActor *v30; // r29
  idVehicle_Car *BindMaster; // r30
  idNavPathPosTracker *enemyTracker; // r3
  idEntity *Owner; // r3
  idNavPathPosTracker *v34; // r3
  idEntity *v35; // r30
  idActor *v36; // r3
  idPhysics *v37; // r3
  int v38; // r30
  const idSpawnId **SpawnId; // r3
  int entityNumber; // r30
  int v41; // r3
  int v42; // r3
  const char *ClipModelsTouchingBounds; // r3
  idClipModel **v44; // r26
  const char *j; // r25
  idClipModel *v46; // r28
  idActor *v47; // r30
  idVehicle_Car *v48; // r29
  idNavPathPosTracker *v49; // r3
  idEntity *v50; // r3
  idNavPathPosTracker *v51; // r3
  idEntity *v52; // r29
  idActor *v53; // r3
  const idSpawnId **v54; // r3
  idPLog *pLog; // r29
  idPLog::logEntry_t *v56; // r30
  int v57; // r3
  __int64 totalTicks; // r11
  __int64 v59; // r9
  float v60[4]; // [sp+50h] [-8230h] BYREF
  idBounds v61; // [sp+60h] [-8220h] BYREF
  idPLogScope v62; // [sp+78h] [-8208h] BYREF
  int v63[100]; // [sp+80h] [-8200h] BYREF
  idClipModel *v64[8196]; // [sp+210h] [-8070h] BYREF

  v5 = ((double (*)(void))RtlCheckStack12)();
  v7 = v6;
  v9 = v8;
  v11 = v10;
  RD_EventBegin(name: "idVehicleAI::CollectObstacles");
  LODWORD(v12) = "idVehicleAI::CollectObstacles";
  HIDWORD(v12) = 2;
  idPLogScope::idPLogScope(this: &v62, pl: &::pLog, gMask: v12, label: v13);
  value = v7->vehicleCar.spawnId.value;
  LODWORD(v60[0]) = &v7->vehicleCar;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v15 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v15 != nullptr )
      v15 = idVehicle_Car::CastTo(c: v15);
  }
  else
  {
    v15 = nullptr;
  }
  v16 = idEntity::GetPhysics(this: v15);
  v17 = (int)v16->GetAbsBounds(this: v16, a2: -1);
  v18 = *v11;
  v19 = v11[1];
  v20 = (float)(v11[2] + (float)v5);
  v61.b[0].z = v11[2] - (float)v5;
  v61.b[1].z = v20;
  v61.b[0].x = (float)v18 - (float)v5;
  v61.b[0].y = (float)v19 - (float)v5;
  v61.b[1].x = (float)v18 + (float)v5;
  v61.b[1].y = (float)v19 + (float)v5;
  v21 = *(float *)(v17 + 20);
  v22 = *(float *)(v17 + 8);
  v61.b[0].z = *(float *)(v17 + 8) - (float)(*(float *)(v17 + 20) - *(float *)(v17 + 8));
  v60[0] = v22;
  v61.b[1].z = *(float *)(v17 + 20) + (float)((float)v21 - (float)v22);
  if ( vai_deferCollectObstacles.valueInteger != 0 )
  {
    index = v7->gatherQuery.index;
    if ( (unsigned int)index < LODWORD(clientGame->clip.gatherQueryFirstSubmittedIndex)
      || (v25 = (unsigned int)index <= LODWORD(clientGame->clip.gatherQueryLastSubmittedIndex), v24 = 1, !v25) )
    {
      v24 = 0;
    }
    if ( v24 != 0 )
    {
      GatheredEntities = idClip::GetGatheredEntities(
                           this: &clientGame->clip,
                           query: &v7->gatherQuery,
                           entityList: v63,
                           maxCount: 100);
      if ( GatheredEntities > 0 )
      {
        v27 = v63;
        for ( i = GatheredEntities; i != 0; --i )
        {
          v29 = *v27 + 21563;
          v30 = *((idActor **)&gameLocal->__vftable + v29);
          if ( v30 != nullptr
            && (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: *((void **)&gameLocal->__vftable + v29)) == 0
            && v30 != (idActor *)idVehicleAI::GetOwnerVehicle(this: v7) )
          {
            BindMaster = (idVehicle_Car *)idEntity::GetBindMaster(this: v30);
            if ( BindMaster != idVehicleAI::GetOwnerVehicle(this: v7) )
            {
              if ( !v7->collideAttack
                || ((enemyTracker = v7->enemyTracker) == nullptr
                  ? (Owner = nullptr)
                  : (Owner = idNavPathPosTracker::GetOwner(this: enemyTracker)),
                    v30 != Owner
                 && ((v34 = v7->enemyTracker) == nullptr
                   ? (v35 = nullptr)
                   : (v35 = idNavPathPosTracker::GetOwner(this: v34)),
                     idEntity::GetBindMaster(this: v30) != v35
                  && v30 != (idActor *)idVehicleAI::GetEnemyVehicle(this: v7))) )
              {
                v36 = idActor::CastTo(c: v30);
                if ( v36 == nullptr || !v36->IsDead(this: v36) )
                {
                  v37 = idEntity::GetPhysics(this: v30);
                  v38 = (int)v37->GetClipModel(this: v37, a2: 0);
                  SpawnId = (const idSpawnId **)idGameLocal::GetSpawnId(
                                                  this: (idGameLocal *)v60,
                                                  result: (idSpawnId *)gameLocal,
                                                  ent: v30);
                  idObstacleAvoidance::AddObstacle(
                    this: &v7->obstacleAvoidance,
                    bounds: (const idBounds *)(v38 + 80),
                    origin: (const idVec3 *)(v38 + 32),
                    axis: (const idMat3 *)(v38 + 44),
                    id: *SpawnId,
                    soft: false);
                }
              }
            }
          }
          ++v27;
        }
      }
    }
    entityNumber = idVehicleAI::GetOwnerVehicle(this: v7)->entityNumber;
    v41 = (*(int (__fastcall **)(int, int))(*(_DWORD *)v9 + 28))(a1: v9, a2: -1);
    v7->gatherQuery.index = *(_QWORD *)&idClip::GatherTouchingBounds(
                                          this: (idClip *)v60,
                                          result: (idGatherQuery *)&clientGame->clip,
                                          bounds: &v61,
                                          clipMask: v41 | 0x20000,
                                          passEntityNumber: entityNumber,
                                          userName: "w:\\tech5\\tungsten\\game\\ai\\VehicleAI\\VehicleControl.cpp(3201) : GatherTouchingBounds")->world;
  }
  else
  {
    v42 = (*(int (__fastcall **)(int, int))(*(_DWORD *)v9 + 28))(a1: v9, a2: -1);
    ClipModelsTouchingBounds = idClip::GetClipModelsTouchingBounds(
                                 this: &clientGame->clip,
                                 bounds: &v61,
                                 clipMask: v42 | 0x20000,
                                 clipModelList: v64,
                                 maxCount: (const char *)0x2000);
    if ( (int)ClipModelsTouchingBounds > 0 )
    {
      v44 = v64;
      for ( j = ClipModelsTouchingBounds; j != nullptr; --j )
      {
        v46 = *v44;
        v47 = (idActor *)gameLocal->entities.ptr[(*v44)->entityNumber];
        if ( (unsigned __int8)Get_idCombatStage_useRelaxedChatterVO(ptr: v47) == 0
          && v47 != (idActor *)idVehicleAI::GetOwnerVehicle(this: v7) )
        {
          v48 = (idVehicle_Car *)idEntity::GetBindMaster(this: v47);
          if ( v48 != idVehicleAI::GetOwnerVehicle(this: v7) )
          {
            if ( !v7->collideAttack
              || ((v49 = v7->enemyTracker) == nullptr
                ? (v50 = nullptr)
                : (v50 = idNavPathPosTracker::GetOwner(this: v49)),
                  v47 != v50
               && ((v51 = v7->enemyTracker) == nullptr
                 ? (v52 = nullptr)
                 : (v52 = idNavPathPosTracker::GetOwner(this: v51)),
                   idEntity::GetBindMaster(this: v47) != v52 && v47 != (idActor *)idVehicleAI::GetEnemyVehicle(this: v7))) )
            {
              v53 = idActor::CastTo(c: v47);
              if ( v53 == nullptr || !v53->IsDead(this: v53) )
              {
                v54 = (const idSpawnId **)idGameLocal::GetSpawnId(
                                            this: (idGameLocal *)v60,
                                            result: (idSpawnId *)gameLocal,
                                            ent: v47);
                idObstacleAvoidance::AddObstacle(
                  this: &v7->obstacleAvoidance,
                  bounds: &v46->bounds,
                  origin: &v46->origin,
                  axis: &v46->axis,
                  id: *v54,
                  soft: false);
              }
            }
          }
        }
        ++v44;
      }
    }
  }
  if ( v62.logIndex >= 0 )
  {
    pLog = v62.pLog;
    v56 = &v62.pLog->logEntries.list[v62.logIndex];
    v57 = (unsigned __int64)Sys_GetClockTicks() >> 32;
    totalTicks = v56->totalTicks;
    HIDWORD(totalTicks) = v56->parent;
    LODWORD(v59) = v57 - totalTicks;
    v56->totalTicks = v59;
    pLog->lastEntry = HIDWORD(totalTicks);
  }
  RD_EventEnd();
}


// ========================================================================
// __unwind$521364
// EA  : 0x82B16760
// RVA : 0x00B16760
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_521364()
{
  idRDScopedEvent *v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: v0 + 65424);
}


// ========================================================================
// __unwind$521365
// EA  : 0x82B16790
// RVA : 0x00B16790
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_521365()
{
  idPLogScope *v0; // r12

  idPLogScope::~idPLogScope(this: v0 + 4031);
}


// ========================================================================
// ?FindEnemy@idVehicleAI@@QAAPAVidEntity@@XZ
// EA  : 0x82B167C0
// RVA : 0x00B167C0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

idVehicle *__fastcall idVehicleAI::FindEnemy(idVehicleAI *this)
{
  __int64 v2; // r3
  int value; // r10
  idEntity *v4; // r3
  int i; // r29
  idPlayer *Player; // r3
  encounterGroupRole_t v8; // r30
  encounterGroupRole_t v9; // r28
  int v10; // r29
  double v11; // fp31
  int v12; // r30
  idPhysics *Physics; // r27
  idPhysics *v14; // r26
  float *v15; // r27
  float *v16; // r3
  double v17; // fp10
  double v18; // fp8
  int v19; // r29
  int v20; // r30
  idEntityPtr<idEntity> *v21; // r3
  int v22; // r25
  int v23; // r27
  idEntity *v24; // r3
  idSplineWaypoint *v25; // r30
  bool v26; // r6
  idSplineWaypoint *v27; // r3
  float rightDistance; // r8
  idNavSpline *navSpline; // r10
  char v30; // r10
  bool v31; // zf
  idStr *v32; // r3
  idNavSpline *v33; // r3
  idNavSpline *v34; // r28
  int v35; // r29
  int v36; // r30
  idVehicleAI *v37; // r3
  idVehicle_Car *VehicleCar; // r3
  bool v39; // r6
  idNavPathPosTracker *Tracker; // r3
  idList<idVehicleAI::enemyListInfo_t,5> *p_enemyList; // r20
  int v42; // r22
  int num; // r11
  int v44; // r27
  idFaction *v45; // r29
  int (***v46)(void); // r10
  int v47; // r11
  char v48; // r11
  idVehicle *v49; // r30
  idEntity *Driver; // r3
  int (*GetFaction)(void); // ctr
  idEntity *v52; // r3
  int (***v53)(void); // r10
  int v54; // r11
  char v55; // r11
  int v56; // r30
  const idFaction *v57; // r3
  idRelationship::attitude_t AttitudeTowards; // r3
  int (***v59)(void); // r10
  int v60; // r11
  char v61; // r11
  encounterGroupRole_t v62; // r11
  int v63; // r11
  int v64; // r29
  int v65; // r28
  idEntity *v66; // r3
  idEntity *v67; // r3
  idPhysics *v68; // r3
  int v69; // r9
  idPhysics *v70; // r30
  idVehicle_Car *v71; // r3
  idVehicle_Car *v72; // r3
  idPhysics *v73; // r14
  float *v74; // r30
  float *v75; // r3
  double v76; // fp10
  double v77; // fp6
  int v78; // r5
  idEntity *v79; // r3
  idEntity *v80; // r4
  idNavPathPosTracker *SplineTracker; // r3
  int v82; // r9
  idVehicle *v83; // r25
  int v84; // r24
  double v85; // fp30
  int v86; // r28
  int v87; // r26
  idAISplinePathMgr *splinePathMgr; // r3
  double alertDistance; // fp0
  int v90; // r27
  idGameLocal *v91; // r11
  int v92; // r29
  vehicleAiSetup_t::engage_t::guardEntity_t *v93; // r10
  int v94; // r8
  idEntity *v95; // r3
  idEntity *v96; // r3
  idSplineWaypoint *v97; // r30
  int v98; // r9
  idEntity *v99; // r3
  idEntity *v100; // r4
  double GuardDistance; // fp1
  double v102; // fp31
  int v103; // r9
  idEntity *v104; // r3
  idEntity *v105; // r3
  idVehicle *v106; // r30
  idEntity *v107; // r3
  int v108; // r11
  char v109; // r11
  idPlayer *v110; // r3
  idPlayer *v111; // r3
  encounterGroupRole_t v112[2]; // [sp+60h] [-100h] BYREF
  idVehicleAI::enemyListInfo_t v113; // [sp+68h] [-F8h] BYREF
  idList<enum encounterGroupRole_t,5> v114; // [sp+80h] [-E0h] BYREF
  idStr v115; // [sp+90h] [-D0h] BYREF

  vaiTimer.findEnemy.state = TS_STARTED;
  LODWORD(v2) = (unsigned __int64)Sys_GetClockTicks() >> 32;
  vaiTimer.findEnemy.start = v2;
  if ( this->ignoreEnemy || vai_enableFindEnemy.valueInteger == 0 )
  {
    idTimer::Stop(this: &vaiTimer.findEnemy);
    return nullptr;
  }
  value = this->specificEnemy.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v4 = gameLocal->entities.ptr[value & 0x1FFF];
    if ( v4 != nullptr && idEntity::CastTo(c: v4) != nullptr )
    {
      idTimer::Stop(this: &vaiTimer.findEnemy);
      return (idVehicle *)idEntityPtr<idEntity const>::operator->(this: &this->specificEnemy);
    }
  }
  idList<idVehicleKey *,5>::idList<idVehicleKey *,5>(this: (idList<idDeclVehicleUpgrade const *,5> *)&v114);
  if ( this->setup.forcePlayerEnemy )
  {
    for ( i = 0; i < 6; ++i )
    {
      Player = idGameLocal::GetPlayer(this: gameLocal, i);
      v8 = (encounterGroupRole_t)Player;
      if ( Player != nullptr
        && !Player->playerHealth.IsDead_Impl(this: &Player->playerHealth)
        && (*(_BYTE *)(v8 + 12824) & 8) == 0 )
      {
        v112[0] = v8;
        idList<idAnimWebBlendTree *,5>::Append(this: &v114, obj: v112);
      }
    }
    v9 = ROLE_NONE;
    v10 = 0;
    v11 = 1.0e30;
    if ( v114.num > 0 )
    {
      v12 = 0;
      do
      {
        Physics = idEntity::GetPhysics(this);
        v112[0] = (encounterGroupRole_t)&v114.list[v12];
        v14 = idEntity::GetPhysics(this: (idEntity *)v114.list[v12]);
        v15 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
        v16 = (float *)v14->GetOrigin(this: v14, a2: 0);
        v17 = (float)(v16[2] - v15[2]);
        v18 = (float)(v16[1] - v15[1]);
        if ( (float)((float)((float)(*v16 - *v15) * (float)(*v16 - *v15))
                   + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17))) < v11 )
        {
          v11 = (float)((float)((float)(*v16 - *v15) * (float)(*v16 - *v15))
                      + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)));
          v9 = v114.list[v12];
        }
        ++v10;
        ++v12;
      }
      while ( v10 < v114.num );
    }
    idTimer::Stop(this: &vaiTimer.findEnemy);
    if ( (v114.listStatic == 0 || v114.listStatic == 2) && v114.list != nullptr )
      idMem::Free(this: &mem, ptr: v114.list, align: ALIGN_16);
    return (idVehicle *)v9;
  }
  v112[0] = (encounterGroupRole_t)this->setup.specificEnemyList.num;
  if ( v112[0] <= ROLE_NONE )
  {
    v22 = 0;
    if ( this->setup.engage.guard.num > 0 )
    {
      v23 = 0;
      do
      {
        v24 = idEntityPtr<idEntity const>::operator->(this: &this->setup.engage.guard.list[v23].entity);
        v25 = (idSplineWaypoint *)v24;
        if ( v24 != nullptr )
        {
          if ( (unsigned __int8)idSplineWaypoint::IsTypeOf(c: v24) != 0 )
          {
            v27 = idSplineWaypoint::CastTo(c: v25);
            rightDistance = v27->splinePathPosition.rightDistance;
            navSpline = v27->splinePathPosition.navSpline;
            v113.entity.spawnId.value = LODWORD(v27->splinePathPosition.distance);
            v113.splineDistance = rightDistance;
            if ( *(float *)&v113.entity.spawnId.value != 0.0
              || v113.splineDistance != 0.0
              || (v31 = navSpline == nullptr, v30 = 0, !v31) )
            {
              v30 = 1;
            }
            if ( v30 != 0 )
            {
              this->splinePathMgr->isStaticPathPos = true;
              idNavSplinePathMgr::GetEntitiesWithinDistance(
                this: (idNavSplinePathMgr *)LODWORD(v27->splinePathPosition.distance),
                pathPos: (idNavSplinePosition *)LODWORD(v27->splinePathPosition.rightDistance),
                distance: this->setup.engage.guard.list[v23].engageDist,
                entityList: (idList<idEntity *,5> *)__ROL4__(v27->splinePathPosition.navSpline, 32),
                clearList: v26);
              this->splinePathMgr->isStaticPathPos = false;
            }
          }
          else if ( (unsigned __int8)idAISplinePath::IsTypeOf(c: v25) != 0 )
          {
            v32 = idStr::idStr(this: &v115, text: v25->name.data);
            v33 = idNavSplinePathMgr::FindNavSpline(this: this->splinePathMgr, splineName: v32, searchExact: true);
            v34 = v33;
            if ( v33 != nullptr )
            {
              v35 = 0;
              if ( v33->entityList.num > 0 )
              {
                v36 = 0;
                do
                {
                  v112[0] = (encounterGroupRole_t)idEntityPtr<idEntity const>::operator->(this: &v34->entityList.list[v36]);
                  idList<idAnimWebBlendTree *,5>::Append(this: &v114, obj: v112);
                  ++v35;
                  ++v36;
                }
                while ( v35 < v34->entityList.num );
              }
            }
          }
          else
          {
            v37 = idVehicleAI::CastTo(c: (idVehicleAI *)v25);
            VehicleCar = idVehicleAI::GetVehicleCar(this: v37);
            Tracker = idNavSplinePathMgr::FindTracker(
                        this: this->splinePathMgr,
                        owner: VehicleCar,
                        createTrackerIfNotFound: false);
            if ( Tracker != nullptr )
              idNavSplinePathMgr::GetEntitiesWithinDistance(
                this: (idNavSplinePathMgr *)LODWORD(Tracker->pathPosition.distance),
                pathPos: (idNavSplinePosition *)LODWORD(Tracker->pathPosition.rightDistance),
                distance: this->setup.engage.guard.list[v23].engageDist,
                entityList: (idList<idEntity *,5> *)__ROL4__(Tracker->pathPosition.navSpline, 32),
                clearList: v39);
          }
        }
        ++v22;
        ++v23;
      }
      while ( v22 < this->setup.engage.guard.num );
    }
  }
  else
  {
    v19 = 0;
    v20 = 0;
    do
    {
      v21 = &this->setup.specificEnemyList.list[v20];
      v112[0] = (encounterGroupRole_t)v21;
      if ( gameLocal->spawnIds.ptr[v21->spawnId.value & 0x1FFF] == v21->spawnId.value >> 13 )
      {
        v112[0] = (encounterGroupRole_t)v21;
        v112[0] = (encounterGroupRole_t)idEntityPtr<idEntity const>::operator->(this: v21);
        idList<idAnimWebBlendTree *,5>::Append(this: &v114, obj: v112);
      }
      ++v19;
      ++v20;
    }
    while ( v19 < this->setup.specificEnemyList.num );
  }
  p_enemyList = &this->enemyList;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->enemyList);
  v42 = 0;
  num = v114.num;
  if ( v114.num > 0 )
  {
    v44 = 0;
    do
    {
      v45 = nullptr;
      v46 = (int (***)(void))v114.list[v44];
      if ( v46 == nullptr )
        goto LABEL_61;
      v112[0] = (encounterGroupRole_t)&v114.list[v44];
      v47 = *(_DWORD *)((**v46)() + 36);
      if ( v47 < idVehicle::Type.typeNum || (v31 = v47 <= idVehicle::Type.lastChild, v48 = 1, !v31) )
        v48 = 0;
      if ( v48 != 0 )
      {
        v49 = (idVehicle *)v114.list[v44];
        if ( idVehicle::GetDriver(this: v49) == nullptr )
          goto LABEL_68;
        Driver = idVehicle::GetDriver(this: v49);
        if ( (unsigned __int8)idClass::IsType(this: Driver, superclass: &idPlayer::Type) == 0 )
        {
          v52 = idVehicle::GetDriver(this: v49);
          if ( (unsigned __int8)idClass::IsType(this: v52, superclass: &idVehicleAI::Type) == 0 )
            goto LABEL_68;
        }
        GetFaction = (int (*)(void))idVehicle::GetDriver(this: v49)->GetFaction;
      }
      else
      {
LABEL_61:
        v53 = (int (***)(void))v114.list[v44];
        if ( v53 == nullptr )
          goto LABEL_68;
        v112[0] = (encounterGroupRole_t)&v114.list[v44];
        v54 = *(_DWORD *)((**v53)() + 36);
        if ( v54 < idPlayer::Type.typeNum || (v31 = v54 <= idPlayer::Type.lastChild, v55 = 1, !v31) )
          v55 = 0;
        if ( v55 == 0 )
          goto LABEL_68;
        GetFaction = *(int (**)(void))(*(_DWORD *)v114.list[v44] + 516);
      }
      v45 = (idFaction *)GetFaction();
LABEL_68:
      LOBYTE(v56) = 1;
      if ( v45 != nullptr )
      {
        v57 = this->GetFaction(this);
        AttitudeTowards = idFaction::GetAttitudeTowards(this: v45, otherFaction: v57);
        v56 = (((unsigned int)AttitudeTowards - __PAIR64__((unsigned int)AttitudeTowards >> 31, 3)) >> 32) & 1;
      }
      v59 = (int (***)(void))v114.list[v44];
      if ( v59 == nullptr )
        goto LABEL_75;
      v112[0] = (encounterGroupRole_t)&v114.list[v44];
      v60 = *(_DWORD *)((**v59)() + 36);
      if ( v60 < idProp::Type.typeNum || (v31 = v60 <= idProp::Type.lastChild, v61 = 1, !v31) )
        v61 = 0;
      if ( v61 != 0 )
LABEL_75:
        LOBYTE(v56) = 0;
      if ( (_BYTE)v56 != 0 )
      {
        v62 = v114.list[v44];
        if ( v62 != ROLE_NONE )
        {
          v112[0] = *(encounterGroupRole_t *)(v62 + 492);
          v63 = (gameLocal->spawnIds.ptr[v112[0]] << 13) | v112[0];
        }
        else
        {
          v63 = 0x1FFF;
        }
        v64 = v63 & 0x1FFF;
        v113.entity.spawnId.value = v63;
        v65 = v63 >> 13;
        if ( gameLocal->spawnIds.ptr[v64] == v63 >> 13 && (v66 = gameLocal->entities.ptr[v64]) != nullptr )
          v67 = idEntity::CastTo(c: v66);
        else
          v67 = nullptr;
        v68 = idEntity::GetPhysics(this: v67);
        v69 = this->vehicleCar.spawnId.value;
        v112[0] = (encounterGroupRole_t)&this->vehicleCar;
        v70 = v68;
        if ( gameLocal->spawnIds.ptr[v69 & 0x1FFF] == v69 >> 13
          && (v71 = (idVehicle_Car *)gameLocal->entities.ptr[v69 & 0x1FFF]) != nullptr )
        {
          v72 = idVehicle_Car::CastTo(c: v71);
        }
        else
        {
          v72 = nullptr;
        }
        v73 = idEntity::GetPhysics(this: v72);
        v74 = (float *)v70->GetOrigin(this: v70, a2: 0);
        v75 = (float *)v73->GetOrigin(this: v73, a2: 0);
        v76 = (float)(v75[1] - v74[1]);
        v77 = (float)(v75[2] - v74[2]);
        v78 = gameLocal->spawnIds.ptr[v64];
        v113.linearDistanceSqr = (float)((float)v77 * (float)v77)
                               + (float)((float)((float)(*v75 - *v74) * (float)(*v75 - *v74))
                                       + (float)((float)v76 * (float)v76));
        if ( v78 == v65 && (v79 = gameLocal->entities.ptr[v64]) != nullptr )
          v80 = idEntity::CastTo(c: v79);
        else
          v80 = nullptr;
        if ( idNavSplinePathMgr::FindTracker(this: this->splinePathMgr, owner: v80, createTrackerIfNotFound: false) != nullptr )
        {
          SplineTracker = idVehicleAI::GetSplineTracker(this);
          v113.splineDistance = idNavSplinePathMgr::GetPathDistance(
                                  this: (idNavSplinePathMgr *)LODWORD(SplineTracker->pathPosition.distance),
                                  start: (idNavSplinePosition *)LODWORD(SplineTracker->pathPosition.rightDistance),
                                  end: (idNavSplinePosition *)__ROL4__(SplineTracker->pathPosition.navSpline, 32),
                                  forward: *(idVec3 **)(v82 + 8),
                                  includeRightDistance: SLOBYTE(vec3_origin.x));
        }
        idList<idVehicleAI::enemyListInfo_t,5>::Append(this: &this->enemyList, obj: &v113);
      }
      num = v114.num;
      ++v42;
      ++v44;
    }
    while ( v42 < v114.num );
  }
  v83 = nullptr;
  v84 = 0;
  v85 = 1.0e30;
  if ( num > 0 )
  {
    v86 = 0;
    v87 = 0;
    while ( 1 )
    {
      splinePathMgr = this->splinePathMgr;
      v112[0] = (encounterGroupRole_t)&v114.list[v87];
      if ( idNavSplinePathMgr::FindTracker(
             this: splinePathMgr,
             owner: (idEntity *)v114.list[v87],
             createTrackerIfNotFound: false) == nullptr
        || (alertDistance = this->setup.engage.alertDistance) == -1.0
        || p_enemyList->list[v86].splineDistance <= alertDistance )
      {
        v90 = 0;
        if ( this->setup.engage.guard.num > 0 )
          break;
      }
LABEL_131:
      ++v84;
      ++v87;
      ++v86;
      if ( v84 >= v114.num )
        goto LABEL_132;
    }
    v91 = gameLocal;
    v92 = 0;
    while ( 1 )
    {
      v93 = &this->setup.engage.guard.list[v92];
      v112[0] = (encounterGroupRole_t)v93;
      v94 = v93->entity.spawnId.value;
      if ( v91->spawnIds.ptr[v93->entity.spawnId.value & 0x1FFF] == v93->entity.spawnId.value >> 13 )
        break;
LABEL_130:
      ++v90;
      ++v92;
      if ( v90 >= this->setup.engage.guard.num )
        goto LABEL_131;
    }
    v112[0] = (encounterGroupRole_t)v93;
    if ( v91->spawnIds.ptr[v94 & 0x1FFF] == v94 >> 13 && (v95 = v91->entities.ptr[v94 & 0x1FFF]) != nullptr )
    {
      v96 = idEntity::CastTo(c: v95);
      v91 = gameLocal;
      v97 = (idSplineWaypoint *)v96;
    }
    else
    {
      v97 = nullptr;
    }
    v98 = p_enemyList->list[v86].entity.spawnId.value;
    if ( v91->spawnIds.ptr[v98 & 0x1FFF] == v98 >> 13 && (v99 = v91->entities.ptr[v98 & 0x1FFF]) != nullptr )
      v100 = idEntity::CastTo(c: v99);
    else
      v100 = nullptr;
    GuardDistance = idVehicleAI::GetGuardDistance(this, enemy: v100, guard: v97);
    v102 = GuardDistance;
    if ( GuardDistance >= v85 || GuardDistance >= this->setup.engage.guard.list[v92].engageDist )
      goto LABEL_129;
    v91 = gameLocal;
    v103 = p_enemyList->list[v86].entity.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v103 & 0x1FFF] != v103 >> 13 )
      goto LABEL_130;
    v104 = gameLocal->entities.ptr[v103 & 0x1FFF];
    if ( v104 == nullptr )
      goto LABEL_130;
    v105 = idEntity::CastTo(c: v104);
    v106 = (idVehicle *)v105;
    if ( v105 == nullptr )
    {
LABEL_129:
      v91 = gameLocal;
      goto LABEL_130;
    }
    if ( (unsigned __int8)idVehicle::IsTypeOf(c: v105) != 0 )
    {
      if ( idVehicle::GetDriver(this: v106) != nullptr )
      {
        v107 = idVehicle::GetDriver(this: v106);
        v108 = *(_DWORD *)(v107->GetType(this: v107) + 36);
        if ( v108 < idPlayer::Type.typeNum || (v31 = v108 <= idPlayer::Type.lastChild, v109 = 1, !v31) )
          v109 = 0;
        if ( v109 != 0 )
        {
          v110 = (idPlayer *)idVehicle::GetDriver(this: v106);
LABEL_126:
          v111 = idPlayer::CastTo(c: v110);
          if ( v111 != nullptr && (*((_BYTE *)v111 + 12824) & 8) != 0 )
            goto LABEL_129;
        }
      }
    }
    else if ( (unsigned __int8)idPlayer::IsTypeOf(c: v106) != 0 )
    {
      v110 = (idPlayer *)v106;
      goto LABEL_126;
    }
    v85 = v102;
    v83 = v106;
    goto LABEL_129;
  }
LABEL_132:
  idTimer::Stop(this: &vaiTimer.findEnemy);
  if ( (v114.listStatic == 0 || v114.listStatic == 2) && v114.list != nullptr )
    idMem::Free(this: &mem, ptr: v114.list, align: ALIGN_16);
  return v83;
}


// ========================================================================
// __unwind$521805
// EA  : 0x82B17384
// RVA : 0x00B17384
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_521805()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 352 + 128));
}


// ========================================================================
// ??1idVehicleAI@@UAA@XZ
// EA  : 0x82B177F8
// RVA : 0x00B177F8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::~idVehicleAI(idVehicleAI *this)
{
  idVehicle_Car *Owner; // r3
  idEntityPtr<idVehicle_Car> *p_vehicleCar; // r28
  int value; // r7
  idVehicle_Car *v5; // r3
  idVehicle_Car *v6; // r3
  idVehicle_Car *v7; // r3
  idVehicle_Car *VehicleCar; // r3

  this->__vftable = (idVehicleAI_vtbl *)&idVehicleAI::`vftable';
  if ( this->splineTracker != nullptr )
  {
    Owner = idVehicleAI::GetOwner(this);
    idNavPathPosTracker::RemoveFromEntityList(this: this->splineTracker, entity: Owner);
  }
  p_vehicleCar = &this->vehicleCar;
  this->controlNode.prev->next = this->controlNode.next;
  this->controlNode.next->prev = this->controlNode.prev;
  this->controlNode.next = &this->controlNode;
  this->controlNode.prev = &this->controlNode;
  this->controlNode.head = &this->controlNode;
  value = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v5 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v5 != nullptr && idVehicle_Car::CastTo(c: v5) != nullptr && this->setup.controlVehicle.vehicleDef != nullptr )
    {
      if ( gameLocal->spawnIds.ptr[p_vehicleCar->spawnId.value & 0x1FFF] == p_vehicleCar->spawnId.value >> 13
        && (v6 = (idVehicle_Car *)gameLocal->entities.ptr[p_vehicleCar->spawnId.value & 0x1FFF]) != nullptr )
      {
        v7 = idVehicle_Car::CastTo(c: v6);
      }
      else
      {
        v7 = nullptr;
      }
      if ( v7->specialDeathActive )
      {
        idVehicleAI::GetVehicleCar(this)->removeWhenDead = true;
      }
      else
      {
        VehicleCar = idVehicleAI::GetVehicleCar(this);
        idEventReceiver::PostEventMS(this: VehicleCar, ev: &EV_Remove, time: 0);
      }
      p_vehicleCar->spawnId.value = 0x1FFF;
    }
  }
  idVehicleState::~idVehicleState(this: &this->ms_PowerTurn);
  idVehicleState::~idVehicleState(this: &this->ms_MoveToGoal);
  idVehicleState::~idVehicleState(this: &this->ms_Backup);
  idVehicleState::~idVehicleState(this: &this->ms_MoveToGoalOnSpline);
  idVehicleState::~idVehicleState(this: &this->as_FreeForm);
  idVehicleState::~idVehicleState(this: &this->as_FireWeapon);
  idVehicleState::~idVehicleState(this: &this->as_WaypointTag);
  idVehicleState::~idVehicleState(this: &this->as_ForcedRetreat);
  idVehicleState::~idVehicleState(this: &this->as_RunAway);
  idVehicleState::~idVehicleState(this: &this->as_HitAndRun);
  idVehicleState::~idVehicleState(this: &this->as_Bypass);
  idVehicleState::~idVehicleState(this: &this->as_RandomFollow);
  idVehicleState::~idVehicleState(this: &this->as_CircleShoot);
  idVehicleState::~idVehicleState(this: &this->as_StrafeShoot);
  idVehicleState::~idVehicleState(this: &this->as_RangeShoot);
  idVehicleState::~idVehicleState(this: &this->as_ChaseRearBump);
  idVehicleState::~idVehicleState(this: &this->as_ChaseSideBump);
  idVehicleState::~idVehicleState(this: &this->as_PowerTurnShoot);
  idVehicleState::~idVehicleState(this: &this->as_ChaseSideShoot);
  idVehicleState::~idVehicleState(this: &this->as_ChaseShoot);
  idVehicleState::~idVehicleState(this: &this->as_Ram);
  idVehicleState::~idVehicleState(this: &this->ds_FollowPlayerInFront);
  idVehicleState::~idVehicleState(this: &this->ds_RoverBomb);
  idVS_ds_Group_FollowLeader::~idVS_ds_Group_FollowLeader(this: &this->ds_Group_FollowLeader);
  idVehicleState::~idVehicleState(this: &this->ds_Barricade);
  idVehicleState::~idVehicleState(this: &this->ds_Ambush);
  idVehicleState::~idVehicleState(this: &this->ds_Patrol);
  idVehicleState::~idVehicleState(this: &this->ds_Car_Chase);
  idVS_cs_Travel::~idVS_cs_Travel(this: &this->cs_TravelTilDead);
  idVehicleState::~idVehicleState(this: &this->cs_WaitForPlayer);
  idVehicleState::~idVehicleState(this: &this->cs_WaitTilDead);
  idVehicleState::~idVehicleState(this: &this->cs_PowerSlide);
  idVehicleState::~idVehicleState(this: &this->cs_WaitForVoiceOver);
  idVehicleState::~idVehicleState(this: &this->cs_WaitForSound);
  idVehicleState::~idVehicleState(this: &this->cs_WaitForTime);
  idVehicleState::~idVehicleState(this: &this->cs_UnlockOccupants);
  idVehicleState::~idVehicleState(this: &this->cs_ExitVehicle);
  idVehicleState::~idVehicleState(this: &this->cs_EnterVehicle);
  idVehicleState::~idVehicleState(this: &this->cs_ChangeState);
  idVehicleState::~idVehicleState(this: &this->cs_PauseState);
  idVehicleState::~idVehicleState(this: &this->cs_ToTrigger);
  idVehicleState::~idVehicleState(this: &this->cs_WaitForTrigger);
  idVS_cs_Travel::~idVS_cs_Travel(this: (idVS_cs_TravelTilDead *)&this->cs_Travel);
  idVehicleState::~idVehicleState(this: &this->cs_Occupants);
  idVehicleState::~idVehicleState(this: &this->cs_NextCommand);
  idLinkList<idEvent>::Clear(this: (idLinkList<idProp_VehiclePickup> *)&this->controlNode);
  `eh vector destructor iterator'(
    ptr: this->patrolPaths,
    size: 0x50u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idInfluenceTrail::~idInfluenceTrail);
  idVehicleFSM::~idVehicleFSM(this: &this->attackFSM);
  idVehicleFSM::~idVehicleFSM(this: &this->movementFSM);
  idVehicleFSM::~idVehicleFSM(this: &this->decisionFSM);
  idVehicleFSM::~idVehicleFSM(this: &this->commandsFSM);
  idVehicleFSMManager::~idVehicleFSMManager(this: &this->fsmMgr);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->enemyList);
  idStr::FreeData(this: &this->debugFireInfo);
  vehicleAiSetup_t::~vehicleAiSetup_t(this: &this->setup);
  idStr::FreeData(this: &this->startDecisionState);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->pickupList);
  idStr::FreeData(this: &this->idObstaclesStr);
  idObstacleAvoidance::~idObstacleAvoidance(this: &this->obstacleAvoidance);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->controlStack);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->ammoFrac);
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->declPreload.declAttacks);
  idEntity::~idEntity(this);
}


// ========================================================================
// __unwind$522880
// EA  : 0x82B17B5C
// RVA : 0x00B17B5C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522880()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$522881
// EA  : 0x82B17B84
// RVA : 0x00B17B84
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522881()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(*(_DWORD *)(v0 - 144 + 164) + 812));
}


// ========================================================================
// __unwind$522882
// EA  : 0x82B17BB0
// RVA : 0x00B17BB0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522882()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 944));
}


// ========================================================================
// __unwind$522883
// EA  : 0x82B17BDC
// RVA : 0x00B17BDC
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522883()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 1208));
}


// ========================================================================
// __unwind$522884
// EA  : 0x82B17C08
// RVA : 0x00B17C08
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522884()
{
  int v0; // r12

  idObstacleAvoidance::~idObstacleAvoidance(this: (idObstacleAvoidance *)(*(_DWORD *)(v0 - 144 + 164) + 1372));
}


// ========================================================================
// __unwind$522885
// EA  : 0x82B17C34
// RVA : 0x00B17C34
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522885()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 1612));
}


// ========================================================================
// __unwind$522886
// EA  : 0x82B17C60
// RVA : 0x00B17C60
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522886()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 1648));
}


// ========================================================================
// __unwind$522887
// EA  : 0x82B17C8C
// RVA : 0x00B17C8C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522887()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 1908));
}


// ========================================================================
// __unwind$522888
// EA  : 0x82B17CB8
// RVA : 0x00B17CB8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522888()
{
  int v0; // r12

  vehicleAiSetup_t::~vehicleAiSetup_t(this: (vehicleAiSetup_t *)(*(_DWORD *)(v0 - 144 + 164) + 2004));
}


// ========================================================================
// __unwind$522889
// EA  : 0x82B17CE4
// RVA : 0x00B17CE4
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522889()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 144 + 164) + 2692));
}


// ========================================================================
// __unwind$522890
// EA  : 0x82B17D10
// RVA : 0x00B17D10
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522890()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 144 + 164) + 2724));
}


// ========================================================================
// __unwind$522891
// EA  : 0x82B17D3C
// RVA : 0x00B17D3C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522891()
{
  int v0; // r12

  idVehicleFSMManager::~idVehicleFSMManager(this: (idVehicleFSMManager *)(*(_DWORD *)(v0 - 144 + 164) + 2740));
}


// ========================================================================
// __unwind$522892
// EA  : 0x82B17D68
// RVA : 0x00B17D68
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522892()
{
  int v0; // r12

  idVehicleFSM::~idVehicleFSM(this: (idVehicleFSM *)(*(_DWORD *)(v0 - 144 + 164) + 2772));
}


// ========================================================================
// __unwind$522893
// EA  : 0x82B17D94
// RVA : 0x00B17D94
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522893()
{
  int v0; // r12

  idVehicleFSM::~idVehicleFSM(this: (idVehicleFSM *)(*(_DWORD *)(v0 - 144 + 164) + 3124));
}


// ========================================================================
// __unwind$522894
// EA  : 0x82B17DC0
// RVA : 0x00B17DC0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522894()
{
  int v0; // r12

  idVehicleFSM::~idVehicleFSM(this: (idVehicleFSM *)(*(_DWORD *)(v0 - 144 + 164) + 3476));
}


// ========================================================================
// __unwind$522895
// EA  : 0x82B17DEC
// RVA : 0x00B17DEC
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522895()
{
  int v0; // r12

  idVehicleFSM::~idVehicleFSM(this: (idVehicleFSM *)(*(_DWORD *)(v0 - 144 + 164) + 3828));
}


// ========================================================================
// __unwind$522896
// EA  : 0x82B17E18
// RVA : 0x00B17E18
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522896()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 144 + 164) + 4200),
    size: 0x50u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idInfluenceTrail::~idInfluenceTrail);
}


// ========================================================================
// __unwind$522897
// EA  : 0x82B17E54
// RVA : 0x00B17E54
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522897()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                           + 4372));
}


// ========================================================================
// __unwind$522898
// EA  : 0x82B17E80
// RVA : 0x00B17E80
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522898()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 4404));
}


// ========================================================================
// __unwind$522899
// EA  : 0x82B17EAC
// RVA : 0x00B17EAC
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522899()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 4516));
}


// ========================================================================
// __unwind$522900
// EA  : 0x82B17ED8
// RVA : 0x00B17ED8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522900()
{
  int v0; // r12

  idVS_cs_Travel::~idVS_cs_Travel(this: (idVS_cs_TravelTilDead *)(*(_DWORD *)(v0 - 144 + 164) + 4620));
}


// ========================================================================
// __unwind$522901
// EA  : 0x82B17F04
// RVA : 0x00B17F04
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522901()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 4756));
}


// ========================================================================
// __unwind$522902
// EA  : 0x82B17F30
// RVA : 0x00B17F30
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522902()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 4856));
}


// ========================================================================
// __unwind$522903
// EA  : 0x82B17F5C
// RVA : 0x00B17F5C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522903()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 4956));
}


// ========================================================================
// __unwind$522904
// EA  : 0x82B17F88
// RVA : 0x00B17F88
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522904()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 5056));
}


// ========================================================================
// __unwind$522905
// EA  : 0x82B17FB4
// RVA : 0x00B17FB4
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522905()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 5156));
}


// ========================================================================
// __unwind$522906
// EA  : 0x82B17FE0
// RVA : 0x00B17FE0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522906()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 5256));
}


// ========================================================================
// __unwind$522907
// EA  : 0x82B1800C
// RVA : 0x00B1800C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522907()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 5356));
}


// ========================================================================
// __unwind$522908
// EA  : 0x82B18038
// RVA : 0x00B18038
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522908()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 5456));
}


// ========================================================================
// __unwind$522909
// EA  : 0x82B18064
// RVA : 0x00B18064
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522909()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 5560));
}


// ========================================================================
// __unwind$522910
// EA  : 0x82B18090
// RVA : 0x00B18090
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522910()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 5664));
}


// ========================================================================
// __unwind$522911
// EA  : 0x82B180BC
// RVA : 0x00B180BC
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522911()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 5764));
}


// ========================================================================
// __unwind$522912
// EA  : 0x82B180E8
// RVA : 0x00B180E8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522912()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 5864));
}


// ========================================================================
// __unwind$522913
// EA  : 0x82B18114
// RVA : 0x00B18114
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522913()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 5964));
}


// ========================================================================
// __unwind$522914
// EA  : 0x82B18140
// RVA : 0x00B18140
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522914()
{
  int v0; // r12

  idVS_cs_Travel::~idVS_cs_Travel(this: (idVS_cs_TravelTilDead *)(*(_DWORD *)(v0 - 144 + 164) + 6064));
}


// ========================================================================
// __unwind$522915
// EA  : 0x82B1816C
// RVA : 0x00B1816C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522915()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 6200));
}


// ========================================================================
// __unwind$522916
// EA  : 0x82B18198
// RVA : 0x00B18198
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522916()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 6328));
}


// ========================================================================
// __unwind$522917
// EA  : 0x82B181C4
// RVA : 0x00B181C4
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522917()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 6440));
}


// ========================================================================
// __unwind$522918
// EA  : 0x82B181F0
// RVA : 0x00B181F0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522918()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 6584));
}


// ========================================================================
// __unwind$522919
// EA  : 0x82B1821C
// RVA : 0x00B1821C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522919()
{
  int v0; // r12

  idVS_ds_Group_FollowLeader::~idVS_ds_Group_FollowLeader(this: (idVS_ds_Group_FollowLeader *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                             + 6684));
}


// ========================================================================
// __unwind$522920
// EA  : 0x82B18248
// RVA : 0x00B18248
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522920()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 6824));
}


// ========================================================================
// __unwind$522921
// EA  : 0x82B18274
// RVA : 0x00B18274
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522921()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 6928));
}


// ========================================================================
// __unwind$522922
// EA  : 0x82B182A0
// RVA : 0x00B182A0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522922()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 7028));
}


// ========================================================================
// __unwind$522923
// EA  : 0x82B182CC
// RVA : 0x00B182CC
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522923()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 7140));
}


// ========================================================================
// __unwind$522924
// EA  : 0x82B182F8
// RVA : 0x00B182F8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522924()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 7252));
}


// ========================================================================
// __unwind$522925
// EA  : 0x82B18324
// RVA : 0x00B18324
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522925()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 7368));
}


// ========================================================================
// __unwind$522926
// EA  : 0x82B18350
// RVA : 0x00B18350
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522926()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 7484));
}


// ========================================================================
// __unwind$522927
// EA  : 0x82B1837C
// RVA : 0x00B1837C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522927()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 7604));
}


// ========================================================================
// __unwind$522928
// EA  : 0x82B183A8
// RVA : 0x00B183A8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522928()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 7720));
}


// ========================================================================
// __unwind$522929
// EA  : 0x82B183D4
// RVA : 0x00B183D4
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522929()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 7884));
}


// ========================================================================
// __unwind$522930
// EA  : 0x82B18400
// RVA : 0x00B18400
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522930()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 8060));
}


// ========================================================================
// __unwind$522931
// EA  : 0x82B1842C
// RVA : 0x00B1842C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522931()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 8180));
}


// ========================================================================
// __unwind$522932
// EA  : 0x82B18458
// RVA : 0x00B18458
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522932()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 8304));
}


// ========================================================================
// __unwind$522933
// EA  : 0x82B18484
// RVA : 0x00B18484
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522933()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 8420));
}


// ========================================================================
// __unwind$522934
// EA  : 0x82B184B0
// RVA : 0x00B184B0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522934()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 8540));
}


// ========================================================================
// __unwind$522935
// EA  : 0x82B184DC
// RVA : 0x00B184DC
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522935()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 8656));
}


// ========================================================================
// __unwind$522936
// EA  : 0x82B18508
// RVA : 0x00B18508
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522936()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 8756));
}


// ========================================================================
// __unwind$522937
// EA  : 0x82B18534
// RVA : 0x00B18534
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522937()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 8876));
}


// ========================================================================
// __unwind$522938
// EA  : 0x82B18560
// RVA : 0x00B18560
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522938()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 8980));
}


// ========================================================================
// __unwind$522939
// EA  : 0x82B1858C
// RVA : 0x00B1858C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522939()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 9080));
}


// ========================================================================
// __unwind$522940
// EA  : 0x82B185B8
// RVA : 0x00B185B8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522940()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 9188));
}


// ========================================================================
// __unwind$522941
// EA  : 0x82B185E4
// RVA : 0x00B185E4
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522941()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 9316));
}


// ========================================================================
// __unwind$522942
// EA  : 0x82B18610
// RVA : 0x00B18610
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_522942()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 144 + 164) + 9416));
}


// ========================================================================
// ?Spawn@idVehicleAI@@QAAXXZ
// EA  : 0x82B18658
// RVA : 0x00B18658
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::Spawn(idVehicleAI *this)
{
  idPresentable *presentable; // r11
  idRenderModel *model; // r10
  char v4; // r11
  int value; // r7
  idVehicle_Car *v6; // r3
  int v7; // r9
  idVehicle_Car *v8; // r3
  idVehicle_Car *v9; // r3
  idPhysics *Physics; // r3
  idVec3 *v11; // r3
  float x; // r9
  float y; // r7
  float z; // r5
  float v15; // r6
  idPhysics *v16; // r3
  float *v17; // r3
  idPhysics *v18; // r3
  float *v19; // r3
  long double v20; // fp2
  __int64 v21; // r10
  __int64 v22; // r9
  unsigned int v23; // r6
  double v24; // fp31
  __int64 v25; // r7
  int v26; // r9
  idNavSplinePath *v27; // r3
  idNavSplinePath *v28; // r3
  const idDeclEntityDef *vehicleDef; // r4
  idEntity *v30; // r29
  float v31; // [sp+54h] [-DCh]
  float v32; // [sp+58h] [-D8h]
  idEventArg v33; // [sp+60h] [-D0h] BYREF
  idStr v34; // [sp+80h] [-B0h] BYREF
  idStr v35; // [sp+A0h] [-90h] BYREF
  idStr v36; // [sp+C0h] [-70h] BYREF

  presentable = this->presentable;
  if ( presentable == nullptr || (model = presentable->model, v4 = 1, model == nullptr) )
    v4 = 0;
  if ( v4 != 0 )
    this->SetModel(this, a2: nullptr);
  idStr::idStr(this: &v36, text: this->name.data);
  idVehicleFSMManager::Init(this: &this->fsmMgr, owner: this);
  idStr::idStr(this: &v34, text: "FSM_");
  idStr::Append(this: &v34, text: this->name.data);
  idStr::Append(this: &v34, text: "_Decision");
  idVehicleFSMManager::AddFSM(this: &this->fsmMgr, fsm: &this->decisionFSM, name: v34.data);
  idStr::operator=(this: &v34, text: "FSM_");
  idStr::Append(this: &v34, text: this->name.data);
  idStr::Append(this: &v34, text: "_Attack");
  idVehicleFSMManager::AddFSM(this: &this->fsmMgr, fsm: &this->attackFSM, name: v34.data);
  idStr::operator=(this: &v34, text: "FSM_");
  idStr::Append(this: &v34, text: this->name.data);
  idStr::Append(this: &v34, text: "_Movement");
  idVehicleFSMManager::AddFSM(this: &this->fsmMgr, fsm: &this->movementFSM, name: v34.data);
  idStr::operator=(this: &v34, text: "FSM_");
  idStr::Append(this: &v34, text: this->name.data);
  idStr::Append(this: &v34, text: "_Commands");
  idVehicleFSMManager::AddFSM(this: &this->fsmMgr, fsm: &this->commandsFSM, name: v34.data);
  this->commandsFSM.AddState(this: &this->commandsFSM, a2: &this->cs_NextCommand);
  this->commandsFSM.AddState(this: &this->commandsFSM, a2: &this->cs_Occupants);
  this->commandsFSM.AddState(this: &this->commandsFSM, a2: &this->cs_Travel);
  this->commandsFSM.AddState(this: &this->commandsFSM, a2: &this->cs_WaitForTrigger);
  this->commandsFSM.AddState(this: &this->commandsFSM, a2: &this->cs_ToTrigger);
  this->commandsFSM.AddState(this: &this->commandsFSM, a2: &this->cs_PauseState);
  this->commandsFSM.AddState(this: &this->commandsFSM, a2: &this->cs_ChangeState);
  this->commandsFSM.AddState(this: &this->commandsFSM, a2: &this->cs_EnterVehicle);
  this->commandsFSM.AddState(this: &this->commandsFSM, a2: &this->cs_ExitVehicle);
  this->commandsFSM.AddState(this: &this->commandsFSM, a2: &this->cs_UnlockOccupants);
  this->commandsFSM.AddState(this: &this->commandsFSM, a2: &this->cs_WaitForTime);
  this->commandsFSM.AddState(this: &this->commandsFSM, a2: &this->cs_WaitForSound);
  this->commandsFSM.AddState(this: &this->commandsFSM, a2: &this->cs_WaitForVoiceOver);
  this->commandsFSM.AddState(this: &this->commandsFSM, a2: &this->cs_PowerSlide);
  this->commandsFSM.AddState(this: &this->commandsFSM, a2: &this->cs_WaitTilDead);
  this->commandsFSM.AddState(this: &this->commandsFSM, a2: &this->cs_WaitForPlayer);
  this->commandsFSM.AddState(this: &this->commandsFSM, a2: &this->cs_TravelTilDead);
  this->decisionFSM.AddState(this: &this->decisionFSM, a2: &this->ds_Car_Chase);
  this->decisionFSM.AddState(this: &this->decisionFSM, a2: &this->ds_FollowPlayerInFront);
  this->decisionFSM.AddState(this: &this->decisionFSM, a2: &this->ds_Patrol);
  this->decisionFSM.AddState(this: &this->decisionFSM, a2: &this->ds_Ambush);
  this->decisionFSM.AddState(this: &this->decisionFSM, a2: &this->ds_Barricade);
  this->decisionFSM.AddState(this: &this->decisionFSM, a2: &this->ds_Group_FollowLeader);
  this->decisionFSM.AddState(this: &this->decisionFSM, a2: &this->ds_RoverBomb);
  this->movementFSM.AddState(this: &this->movementFSM, a2: &this->ms_MoveToGoalOnSpline);
  this->movementFSM.AddState(this: &this->movementFSM, a2: &this->ms_Backup);
  this->movementFSM.AddState(this: &this->movementFSM, a2: &this->ms_MoveToGoal);
  this->movementFSM.AddState(this: &this->movementFSM, a2: &this->ms_PowerTurn);
  this->attackFSM.AddState(this: &this->attackFSM, a2: &this->as_Ram);
  this->attackFSM.AddState(this: &this->attackFSM, a2: &this->as_ChaseShoot);
  this->attackFSM.AddState(this: &this->attackFSM, a2: &this->as_ChaseSideShoot);
  this->attackFSM.AddState(this: &this->attackFSM, a2: &this->as_RangeShoot);
  this->attackFSM.AddState(this: &this->attackFSM, a2: &this->as_StrafeShoot);
  this->attackFSM.AddState(this: &this->attackFSM, a2: &this->as_CircleShoot);
  this->attackFSM.AddState(this: &this->attackFSM, a2: &this->as_RandomFollow);
  this->attackFSM.AddState(this: &this->attackFSM, a2: &this->as_Bypass);
  this->attackFSM.AddState(this: &this->attackFSM, a2: &this->as_HitAndRun);
  this->attackFSM.AddState(this: &this->attackFSM, a2: &this->as_RunAway);
  this->attackFSM.AddState(this: &this->attackFSM, a2: &this->as_ForcedRetreat);
  this->attackFSM.AddState(this: &this->attackFSM, a2: &this->as_WaypointTag);
  this->attackFSM.AddState(this: &this->attackFSM, a2: &this->as_PowerTurnShoot);
  this->attackFSM.AddState(this: &this->attackFSM, a2: &this->as_ChaseSideBump);
  this->attackFSM.AddState(this: &this->attackFSM, a2: &this->as_ChaseRearBump);
  this->attackFSM.AddState(this: &this->attackFSM, a2: &this->as_FireWeapon);
  this->attackFSM.AddState(this: &this->attackFSM, a2: &this->as_FreeForm);
  idVehicleAI::ResetStates(this);
  value = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && idVehicle_Car::CastTo(c: v6) != nullptr )
  {
    v7 = this->vehicleCar.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v7 & 0x1FFF] == v7 >> 13
      && (v8 = (idVehicle_Car *)gameLocal->entities.ptr[v7 & 0x1FFF]) != nullptr )
    {
      v9 = idVehicle_Car::CastTo(c: v8);
    }
    else
    {
      v9 = nullptr;
    }
    Physics = idEntity::GetPhysics(this: v9);
    v11 = (idVec3 *)Physics->GetOrigin(this: Physics, a2: 0);
  }
  else
  {
    v11 = &vec3_origin;
  }
  x = v11->x;
  y = v11->y;
  this->immediateGoalPosition.z = v11->z;
  this->immediateGoalPosition.y = y;
  this->immediateGoalPosition.x = x;
  z = this->immediateGoalPosition.z;
  v15 = this->immediateGoalPosition.y;
  this->desiredGoalPosition[0].x = this->immediateGoalPosition.x;
  this->desiredGoalPosition[0].y = v15;
  this->desiredGoalPosition[0].z = z;
  v32 = this->immediateGoalPosition.z;
  v31 = this->immediateGoalPosition.y;
  this->finalGoalPosition.x = this->immediateGoalPosition.x;
  this->finalGoalPosition.y = v31;
  this->finalGoalPosition.z = v32;
  v16 = idEntity::GetPhysics(this);
  v17 = (float *)v16->GetOrigin(this: v16, a2: 0);
  this->startingOrigin.x = *v17;
  this->startingOrigin.y = v17[1];
  this->startingOrigin.z = v17[2];
  v18 = idEntity::GetPhysics(this);
  v19 = (float *)v18->GetAxis(this: v18, a2: 0);
  *((double *)&v20 + 1) = *v19;
  this->startingAxis.mat[0].x = *v19;
  LODWORD(v21) = &this->startingAxis;
  *(double *)&v20 = v19[1];
  HIDWORD(v21) = v19 + 3;
  this->startingAxis.mat[0].y = v19[1];
  this->startingAxis.mat[0].z = v19[2];
  this->startingAxis.mat[1].x = v19[3];
  this->startingAxis.mat[1].y = v19[4];
  this->startingAxis.mat[1].z = v19[5];
  this->startingAxis.mat[2].x = v19[6];
  this->startingAxis.mat[2].y = v19[7];
  this->startingAxis.mat[2].z = v19[8];
  idVehicleAI::UpdateControlParams(
    this,
    params: &this->setup.control,
    initialize: true,
    a4: v20,
    a5: (int)&this->startingAxis.mat[2],
    a6: (int)(v19 + 6),
    a7: (int)&this->startingAxis.mat[1],
    a8: v21);
  idDeclInfo::FindWithInheritance(this: &idDeclEntityDef::resourceList, name: "path/splinewaypoint", makeDefault: false);
  idEntity::BecomeInactive(this, flags: 1);
  if ( this->startActive )
  {
    HIDWORD(v22) = 1664525;
    v23 = 1664525 * clientGame->random.seed;
    clientGame->random.seed = v23 + 1013904223;
    LODWORD(v22) = ((v23 + 1013904223) >> 10) & 0x7FFF;
    v24 = (float)((float)((float)((float)v22 * this->maxStartDelay) * (float)0.000030518509) + this->minStartDelay);
    v25 = *(_QWORD *)&idEventArg::idEventArg(this: &v33, data: this)->value.q[1];
    idEventReceiver::PostEventMS(
      this,
      ev: &EV_Activate,
      time: (int)(float)((float)v24 * (float)1000.0),
      arg1: (const idEventArg *)HIDWORD(v25));
  }
  if ( this->setup.guardInitialPath )
  {
    v26 = this->setup.initialPath.spawnId.value;
    v33.value.f = 10000.0;
    v33.value.v[1] = 12000.0;
    if ( gameLocal->spawnIds.ptr[v26 & 0x1FFF] == v26 >> 13
      && (v27 = (idNavSplinePath *)gameLocal->entities.ptr[v26 & 0x1FFF]) != nullptr
      && (v28 = idNavSplinePath::CastTo(c: v27)) != nullptr )
    {
      *(_DWORD *)&v33.type = (gameLocal->spawnIds.ptr[v28->entityNumber] << 13) | v28->entityNumber;
    }
    else
    {
      *(_DWORD *)&v33.type = 0x1FFF;
    }
    idList<vehicleAiSetup_t::engage_t::guardEntity_t,5>::Append(
      this: &this->setup.engage.guard,
      obj: (const vehicleAiSetup_t::engage_t::guardEntity_t *)&v33);
  }
  vehicleDef = this->setup.controlVehicle.vehicleDef;
  this->setup.death.respawns = this->setup.death.numRespawns;
  if ( vehicleDef != nullptr )
  {
    v30 = gameLocal->SpawnEntityFromDef(this: gameLocal, a2: vehicleDef, a3: -1, a4: -1, a5: -1);
    if ( (unsigned __int8)idVehicle::IsTypeOf(c: v30) != 0 )
    {
      idStr::idStr(this: &v35, text: v30->name.data);
      idStr::ReplaceChar(this: &v35, oldChar: 47, newChar: 95);
      idEntity::SetName(this: v30, newName: v35.data);
      v30->Hide_2(this: v30);
      this->prespawnedVehicle.spawnId.value = (gameLocal->spawnIds.ptr[v30->entityNumber] << 13) | v30->entityNumber;
      idStr::FreeData(this: &v35);
    }
  }
  idStr::FreeData(this: &v34);
  idStr::FreeData(this: &v36);
}


// ========================================================================
// __unwind$523902
// EA  : 0x82B1908C
// RVA : 0x00B1908C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_523902()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 192));
}


// ========================================================================
// __unwind$523903
// EA  : 0x82B190B4
// RVA : 0x00B190B4
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_523903()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 128));
}


// ========================================================================
// __unwind$523904
// EA  : 0x82B190DC
// RVA : 0x00B190DC
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_523904()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(v0 - 304 + 160));
}


// ========================================================================
// ?Think@idVehicleAI@@UAAXXZ
// EA  : 0x82B19110
// RVA : 0x00B19110
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::Think(idVehicleAI *this)
{
  unsigned __int64 v2; // r6
  const char *v3; // r7
  __int64 v4; // r3
  int value; // r8
  idVehicle_Car *v6; // r3
  idVehicle_Car *v7; // r24
  idNavPathPosTracker *splineTracker; // r3
  char v9; // r11
  int v10; // r3
  int v11; // r5
  int v12; // r4
  bool v13; // r28
  float *LinearVelocity; // r3
  idPhysics *Physics; // r3
  void (*GetGameMs)(void); // ctr
  long double v17; // fp2
  long double v18; // fp2
  idPhysics *v19; // r28
  idPhysics *v20; // r27
  idPhysics *v21; // r3
  idPhysics_vtbl *v22; // r28
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // ctr
  int v24; // r3
  idNavPathPosTracker *v25; // r11
  float rightDistance; // r9
  idNavSpline *navSpline; // r8
  idNavSpline *NavSplineFromIndex; // r3
  idPhysics *v29; // r3
  char v30; // r3
  idPhysics *v31; // r28
  idPhysics *v32; // r3
  float *v33; // r27
  float *v34; // r3
  idState *curState; // r27
  idPresentable *presentable; // r3
  idPresentableVehicle *v37; // r26
  char v38; // r11
  idNavPathPosTracker *v39; // r11
  double passThroughGoalDist; // fp0
  float v41; // r9
  float v42; // r6
  double v43; // fp12
  double v44; // fp0
  float v45; // r9
  idNavSpline *v46; // r8
  char v47; // r25
  int v48; // r28
  idVehicleWeapon *Weapon; // r27
  int WeaponSlot; // r19
  int v51; // r3
  __int64 v52; // r3
  __int64 v53; // r3
  int v54; // r3
  __int64 v55; // r3
  int v56; // r3
  __int64 v57; // r3
  int v58; // r3
  idVehicle_Car *EnemyVehicle; // r3
  idVehicle_Car *v60; // r3
  __int64 v61; // r3
  int v62; // r3
  __int64 v63; // r3
  int v64; // r5
  int v65; // r4
  __int64 v66; // r11
  __int64 v67; // r11
  double actualSpeed; // fp31
  double v69; // fp0
  double v70; // fp0
  double v71; // fp0
  idPLogScope v72; // [sp+58h] [-A8h] BYREF
  float distance; // [sp+60h] [-A0h] BYREF
  float v74; // [sp+64h] [-9Ch]
  idNavSpline *v75; // [sp+68h] [-98h]

  RD_EventBegin(name: "idVehicleAI::Think()");
  LODWORD(v2) = "idVehicleAI::Think()";
  HIDWORD(v2) = 2;
  idPLogScope::idPLogScope(this: &v72, pl: &pLog, gMask: v2, label: v3);
  idVehicleAI::ClearTimers(this);
  vaiTimer.total.state = TS_STARTED;
  LODWORD(v4) = (unsigned __int64)Sys_GetClockTicks() >> 32;
  vaiTimer.total.start = v4;
  value = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v6 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v7 = idVehicle_Car::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  if ( idVehicleAI::GetOwner(this) == nullptr
    || (splineTracker = this->splineTracker) == nullptr
    || idNavPathPosTracker::GetOwner(this: splineTracker) == nullptr
    || (v9 = 1, this->splineTracker->pathPosition.navSpline == nullptr) )
  {
    v9 = 0;
  }
  if ( v9 == 0 )
  {
    if ( this->vehicleWasActive )
    {
      v10 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      idFiniteStateMachine::Update(this: &this->commandsFSM, curTime: v10, info: nullptr);
    }
    if ( this->setup.commands.num == 0 )
    {
      if ( v7 != nullptr && ((double (__fastcall *)(idVehicle_Car *))v7->GetHealth)(a1: v7) > 0.0 )
        idVehicleAI::ApplyMovement(this, speed: 0.0, wheelForce: 0.0, braking: v12, a5: v11, a6: 1);
      else
        idVehicleAI::HandleDeath(this);
    }
    goto LABEL_20;
  }
  if ( v7 == nullptr )
  {
LABEL_20:
    ++vaiTimer.activeCount;
    idTimer::Stop(this: &vaiTimer.total);
    idPLogScope::~idPLogScope(this: &v72);
    goto LABEL_108;
  }
  if ( idEntity::UpdateDormant(this) )
    goto LABEL_44;
  ++vaiTimer.activeCount;
  if ( ((double (__fastcall *)(idVehicle_Car *))v7->GetHealth)(a1: v7) > 0.0 )
  {
    v13 = this->aiNoControlTime > idGameTimeManager::GetGameMs(
                                    this: &clientGame->gameTimeManager,
                                    type: GAMETIME_SCALED);
    if ( this->aiNoControlVelocitySqr > 0.0 )
    {
      LinearVelocity = (float *)idEntity::GetLinearVelocity(this: (idEntity *)&distance, result: v7);
      if ( (float)((float)(LinearVelocity[2] * LinearVelocity[2])
                 + (float)((float)(*LinearVelocity * *LinearVelocity) + (float)(LinearVelocity[1] * LinearVelocity[1]))) > (double)this->aiNoControlVelocitySqr )
        v13 = true;
    }
    if ( v13 )
      goto LABEL_44;
  }
  this->aiNoControlVelocitySqr = 0.0;
  this->aiNoControlTime = 0;
  Physics = idEntity::GetPhysics(this: v7);
  if ( ((double (__fastcall *)(idPhysics *, _DWORD))Physics->GetWaterLevel)(a1: Physics, a2: 0) <= 0.0 )
  {
    this->inWaterTime = 0;
  }
  else
  {
    GetGameMs = (void (*)(void))gameLocal->GetGameMs;
    if ( this->inWaterTime != 0 )
      GetGameMs();
    else
      this->inWaterTime = ((int (*)(void))GetGameMs)();
  }
  if ( ((double (__fastcall *)(idVehicle_Car *))v7->GetHealth)(a1: v7) <= 0.0 )
  {
    idVehicleAI::HandleDeath(this);
    idTimer::Stop(this: &vaiTimer.total);
    idPLogScope::~idPLogScope(this: &v72);
    goto LABEL_108;
  }
  if ( vai_maxCurveSpeed.valueFloat != 0.0 )
    this->control.maxCurveSpeed = vai_maxCurveSpeed.valueFloat;
  if ( vai_maxCurveAngle.valueFloat != 0.0 )
  {
    *(double *)&v17 = vai_maxCurveAngle.valueFloat;
    v18 = cos(x: v17);
    this->control.maxCurveCosine = *(double *)&v18;
  }
  this->vehicleWasActive = true;
  v19 = idEntity::GetPhysics(this: v7);
  v20 = idEntity::GetPhysics(this);
  v21 = v19;
  GetOrigin = v19->GetOrigin;
  v22 = v20->__vftable;
  v24 = (int)GetOrigin(this: v21, a2: 0);
  v22->SetOrigin(this: v20, a2: (const idVec3 *)v24, a3: -1);
  if ( vai_enable.valueFloat == 0.0 )
  {
    v25 = this->splineTracker;
    rightDistance = v25->pathPosition.rightDistance;
    navSpline = v25->pathPosition.navSpline;
    distance = v25->pathPosition.distance;
    v74 = rightDistance;
    if ( navSpline == nullptr )
    {
      NavSplineFromIndex = idNavSplinePathMgr::GetNavSplineFromIndex(this: this->splinePathMgr, index: 0);
      idNavPathPosTracker::Init(
        this: this->splineTracker,
        pathName: NavSplineFromIndex->splinePath->name.data,
        owner: nullptr);
    }
    v29 = idEntity::GetPhysics(this: v7);
    v29->SetLinearVelocity(this: v29, a2: &vec3_origin, a3: 0);
    idTimer::Stop(this: &vaiTimer.total);
    idPLogScope::~idPLogScope(this: &v72);
    goto LABEL_108;
  }
  this->lastSpeed = this->actualSpeed;
  this->actualSpeed = idVehicle::GetCurrentSpeedInMPH(this: v7);
  if ( idVehicleAI::GetVehicleEntity(this) != nullptr )
  {
LABEL_44:
    idTimer::Stop(this: &vaiTimer.total);
    idPLogScope::~idPLogScope(this: &v72);
    goto LABEL_108;
  }
  if ( vai_noExplodeWhenStuck.valueInteger == 0 && this->setup.death.killWhenStuck )
  {
    v30 = idVehicleAI::CheckForStuck(this, dSpeed: this->desiredSpeed);
    if ( this->excessiveBackupAttempts >= vai_excessiveBackupsCount.valueInteger )
    {
      v30 = 1;
      this->excessiveBackupAttempts = 0;
    }
    if ( v30 != 0 )
    {
      ((void (__fastcall *)(idVehicle_Car *, idVehicleAI *, idVehicleAI *, const idDeclDamage *, double))v7->Damage)(
        a1: v7,
        a2: this,
        a3: this,
        a4: this->declPreload.declDamage1,
        a5: 9999999.0);
      idTimer::Stop(this: &vaiTimer.total);
      idPLogScope::~idPLogScope(this: &v72);
      goto LABEL_108;
    }
  }
  v31 = idEntity::GetPhysics(this: v7);
  v32 = idEntity::GetPhysics(this: v7);
  v33 = (float *)v32->GetAxis(this: v32, a2: 0);
  v34 = (float *)v31->GetLinearVelocity(this: (idPhysics *)&distance, result: (idVec3 *)v31, a3: 0);
  this->drivingBackwards = (float)((float)(*v34 * *v33) + (float)((float)(v34[2] * v33[2]) + (float)(v34[1] * v33[1]))) < 0.0;
  if ( vai_boost.valueInteger > 0 )
  {
    if ( this->boostTime >= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
      idCVar::SetInteger(this: &vai_boost, newValue: 0, force: true);
    else
      idVehicleAI::Boost(this, ms: vai_boost.valueInteger, affectVelocity: true);
  }
  if ( vai_stopControllingVehicle.valueInteger > 0 )
  {
    curState = this->movementFSM.curState;
    if ( curState == idFiniteStateMachine::FindState(this: &this->movementFSM, stateType: &idVS_Idle::Type) )
      idCVar::SetInteger(this: &vai_stopControllingVehicle, newValue: 0, force: true);
    else
      idEventReceiver::PostEventMS(this, ev: &EV_AiStopControllingVehicle, time: 0);
  }
  presentable = v7->presentable;
  if ( presentable != nullptr )
    v37 = presentable->GetVehicleInterface(this: presentable);
  else
    v37 = nullptr;
  if ( __fabs(this->immediateGoalAngle) > 30.0 || (v38 = 1, this->actualSpeed < 100.0) )
    v38 = 0;
  v37->boosting = v38;
  if ( this->stoppingGoal || this->passThroughGoal )
  {
    v39 = this->splineTracker;
    passThroughGoalDist = this->setup.passThroughGoalDist;
    v41 = v39->pathPosition.rightDistance;
    v42 = v39->pathPosition.distance;
    v74 = v39->goalPathPosition.rightDistance;
    v43 = (float)(v74 - v41);
    v74 = v41;
    v75 = v39->pathPosition.navSpline;
    distance = v42;
    if ( passThroughGoalDist <= 0.0 )
    {
      v45 = v39->pathPosition.distance;
      v46 = v39->pathPosition.navSpline;
      v74 = v39->pathPosition.rightDistance;
      this->goalRightDistance = v74 + (float)v43;
    }
    else
    {
      v44 = (float)((float)(this->splineDistanceToFinalGoal - (float)500.0) / (float)passThroughGoalDist);
      if ( v44 >= 0.0 )
      {
        if ( v44 > 1.0 )
          v44 = 1.0;
      }
      else
      {
        v44 = 0.0;
      }
      v45 = v39->pathPosition.distance;
      v46 = v39->pathPosition.navSpline;
      v74 = v39->pathPosition.rightDistance;
      this->goalRightDistance = (float)((float)((float)1.0 - (float)v44) * (float)v43) + v74;
    }
    v75 = v46;
    distance = v45;
  }
  v47 = 0;
  v48 = 0;
  if ( idVehicle::GetNumWeapons(this: v7) > 0 )
  {
    while ( 1 )
    {
      Weapon = idVehicle::GetWeapon(this: v7, num: v48);
      WeaponSlot = idVehicleWeapon::GetWeaponSlot(this: Weapon);
      if ( WeaponSlot == idPresentableVehicle::GetCurrentWeaponGroup(this: v37) )
      {
        v51 = idVehicleWeapon::GetWeaponSlot(this: Weapon);
        if ( idPresentableVehicle::WeaponGroupHasAmmo(this: v37, groupnum: v51) )
          break;
      }
      if ( ++v48 >= idVehicle::GetNumWeapons(this: v7) )
        goto LABEL_81;
    }
    v47 = 1;
  }
LABEL_81:
  if ( v47 == 0 )
    idPresentableVehicle::NextWeapon(this: v37, ignoreReadyToFire: false);
  idVehicleAI::UpdateWeaponsHaveClearShot(this);
  vaiTimer.states.state = TS_STARTED;
  LODWORD(v52) = (unsigned __int64)Sys_GetClockTicks() >> 32;
  vaiTimer.states.start = v52;
  this->obstacleFlags = 0;
  this->speedFlags = 0;
  this->steerFlags = 0;
  idStr::operator=(this: &this->idObstaclesStr, text: "None");
  vaiTimer.st_commands.state = TS_STARTED;
  LODWORD(v53) = (unsigned __int64)Sys_GetClockTicks() >> 32;
  vaiTimer.st_commands.start = v53;
  v54 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  idFiniteStateMachine::Update(this: &this->commandsFSM, curTime: v54, info: nullptr);
  idTimer::Stop(this: &vaiTimer.st_commands);
  if ( this->splineTracker->pathToGoal.path.num > 0 )
  {
    if ( this->runDecisionFSM )
    {
      vaiTimer.st_decision.state = TS_STARTED;
      LODWORD(v55) = (unsigned __int64)Sys_GetClockTicks() >> 32;
      vaiTimer.st_decision.start = v55;
      v56 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      idFiniteStateMachine::Update(this: &this->decisionFSM, curTime: v56, info: nullptr);
      idTimer::Stop(this: &vaiTimer.st_decision);
    }
    vaiTimer.st_attack.state = TS_STARTED;
    LODWORD(v57) = (unsigned __int64)Sys_GetClockTicks() >> 32;
    vaiTimer.st_attack.start = v57;
    v58 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
    idFiniteStateMachine::Update(this: &this->attackFSM, curTime: v58, info: nullptr);
    if ( this->attackFSM.curState != &this->attackFSM.s_Idle && !this->inForcedRetreatState )
    {
      EnemyVehicle = (idVehicle_Car *)idVehicleAI::GetEnemyVehicle(this);
      v60 = idVehicle_Car::CastTo(c: EnemyVehicle);
      if ( v60 != nullptr )
        idVehicle_Car::PingAttack(this: v60);
    }
    idTimer::Stop(this: &vaiTimer.st_attack);
  }
  this->desiredGoalPosition[2].x = this->desiredGoalPosition[1].x;
  this->desiredGoalPosition[2].y = this->desiredGoalPosition[1].y;
  this->desiredGoalPosition[2].z = this->desiredGoalPosition[1].z;
  this->desiredGoalPosition[1].x = this->desiredGoalPosition[0].x;
  this->desiredGoalPosition[1].y = this->desiredGoalPosition[0].y;
  this->desiredGoalPosition[1].z = this->desiredGoalPosition[0].z;
  vaiTimer.st_movement.state = TS_STARTED;
  LODWORD(v61) = (unsigned __int64)Sys_GetClockTicks() >> 32;
  vaiTimer.st_movement.start = v61;
  v62 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  idFiniteStateMachine::Update(this: &this->movementFSM, curTime: v62, info: nullptr);
  idTimer::Stop(this: &vaiTimer.st_movement);
  idTimer::Stop(this: &vaiTimer.states);
  idVehicleAI::ActivateBoost(this);
  vaiTimer.movement.state = TS_STARTED;
  LODWORD(v63) = (unsigned __int64)Sys_GetClockTicks() >> 32;
  vaiTimer.movement.start = v63;
  if ( this->canControlVehicle )
  {
    idVehicleAI::UpdateMovement(this);
  }
  else
  {
    idVehicle::UpdateSteerAngle(this: v7, desiredAngle: 0.0);
    idVehicleAI::ApplyMovement(this, speed: 0.0, wheelForce: 0.0, braking: v65, a5: v64, a6: 0);
  }
  idTimer::Stop(this: &vaiTimer.movement);
  vaiTimer.weapons.state = TS_STARTED;
  LODWORD(v66) = (unsigned __int64)Sys_GetClockTicks() >> 32;
  vaiTimer.weapons.start = v66;
  idVehicleAI::UpdateWeapons(this);
  idTimer::Stop(this: &vaiTimer.weapons);
  vaiTimer.sounds.state = TS_STARTED;
  LODWORD(v67) = (unsigned __int64)Sys_GetClockTicks() >> 32;
  vaiTimer.sounds.start = v67;
  idVehicle_Car::UpdateSounds(this: v7);
  idTimer::Stop(this: &vaiTimer.sounds);
  actualSpeed = this->actualSpeed;
  v69 = (float)((float)actualSpeed / v7->GetMaxSpeed(this: v7));
  if ( v69 >= 0.0 )
  {
    if ( v69 > 1.0 )
      v69 = 1.0;
  }
  else
  {
    v69 = 0.0;
  }
  v70 = (float)((float)v69 - this->throttleValue);
  if ( __fabs(actualSpeed) >= 2.0 )
  {
    if ( v70 <= 0.050000001 )
    {
      if ( v70 >= -0.050000001 )
        goto LABEL_105;
      v71 = (float)(this->throttleValue - (float)0.0049999999);
    }
    else
    {
      v71 = (float)(this->throttleValue + (float)0.0049999999);
    }
    this->throttleValue = v71;
    goto LABEL_105;
  }
  this->throttleValue = 0.0;
LABEL_105:
  idVehicle::UpdateCurrentThrottle(this: v7, newthrottle: this->throttleValue);
  idTimer::Stop(this: &vaiTimer.total);
  idVehicleAI::AdjustAggression(this);
  if ( this->weaponFiredFrame != idAccolade::Count(this: &clientGame->gameTimeManager) )
    idVehicleAI::ReleaseWeaponTriggers(this);
  idPLogScope::~idPLogScope(this: &v72);
LABEL_108:
  RD_EventEnd();
}


// ========================================================================
// __unwind$524635
// EA  : 0x82B19CF4
// RVA : 0x00B19CF4
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_524635()
{
  int v0; // r12

  idRDScopedEvent::~idRDScopedEvent(this: (idRDScopedEvent *)(v0 - 256 + 108));
}


// ========================================================================
// __unwind$524636
// EA  : 0x82B19D1C
// RVA : 0x00B19D1C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_524636()
{
  int v0; // r12

  idPLogScope::~idPLogScope(this: (idPLogScope *)(v0 - 256 + 88));
}


// ========================================================================
// ?AvoidSplineObstacles@idVehicleAI@@QAAXXZ
// EA  : 0x82B19D48
// RVA : 0x00B19D48
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::AvoidSplineObstacles(idVehicleAI *this)
{
  int value; // r10
  idVehicle_Car *v3; // r3
  __int64 v4; // r3
  int v5; // r9
  idVehicle_Car *v6; // r3
  idVehicle_Car *v7; // r3
  const idPhysics *Physics; // r30
  int v9; // r3
  char *v10; // r10
  _DWORD *v11; // r11
  int i; // ctr
  double v13; // fp4
  double v14; // fp1
  __int64 v15; // r3
  float *v16; // r3
  double v19; // fp2
  double v20; // fp5
  double v21; // fp3
  int v26; // r9
  float x; // r7
  float z; // r6
  idVehicle_Car *v29; // r3
  idVehicle_Car *v30; // r3
  idPhysics *v31; // r3
  double immediateGoalAngle; // fp0
  double v33; // fp1
  int v34; // r9
  idVehicle_Car *v35; // r3
  idVehicle_Car *v36; // r3
  idPhysics *v37; // r28
  const idMat3 *v38; // r26
  idMat3 *v39; // r3
  idVehicle_Car *VehicleCar; // r3
  idPhysics *v41; // r3
  double v42; // fp29
  double v43; // fp28
  double v44; // fp27
  float *v45; // r3
  double v46; // fp6
  double v47; // fp5
  float v48; // r9
  float v49; // r8
  float v50; // r8
  float v51; // r7
  const idVec3 *(__fastcall *GetOrigin)(idPhysics *, int); // r10
  const idVec3 *v53; // r3
  float *v54; // r28
  idBounds *v55; // r3
  double Radius; // fp1
  double v57; // fp30
  double v58; // fp29
  double v59; // fp28
  float *v60; // r3
  double v61; // fp6
  double v62; // fp4
  double v63; // fp3
  int v64; // r30
  int v65; // r3
  bool PathAroundObstacles; // r30
  idVehicle_Car *v67; // r3
  idPhysics *v68; // r3
  float *v69; // r3
  double v70; // fp22
  double v71; // fp24
  double v72; // fp23
  double v75; // fp1
  double v76; // fp8
  float v77; // r10
  float v78; // r9
  float v79; // r8
  idVehicle_Car *v80; // r3
  idPhysics *v81; // r3
  float *v82; // r3
  double v83; // fp11
  idVehicle_Car *v84; // r3
  idPhysics *v85; // r30
  idVehicle_Car *v86; // r3
  idPhysics *v87; // r29
  double v88; // fp30
  double v89; // fp29
  double v90; // fp28
  float *v91; // r3
  double v92; // fp3
  double v93; // fp2
  idPhysics *v94; // r3
  idRenderWorld *renderWorld; // r30
  idRenderWorld_vtbl *v96; // r29
  const idVec3 *(__fastcall *v97)(idPhysics *, int); // ctr
  int v98; // r3
  idVehicle_Car *v99; // r3
  idPhysics *v100; // r30
  idVehicle_Car *v101; // r3
  idPhysics *v102; // r29
  float *v103; // r3
  double v104; // fp13
  double v105; // fp11
  idPhysics *v106; // r3
  idRenderWorld *v107; // r30
  idRenderWorld_vtbl *v108; // r29
  const idVec3 *(__fastcall *v109)(idPhysics *, int); // ctr
  int v110; // r3
  idVehicle_Car *v111; // r3
  idPhysics *v112; // r3
  int v113; // r3
  float v114; // r7
  float v115; // r6
  idPhysics *v116; // r3
  idVehicle_Car *v117; // r3
  idPhysics *v118; // r3
  int v119; // r3
  float v120; // r6
  float v121; // r5
  idPhysics *v122; // r3
  float *v123; // r3
  double v124; // fp30
  double v125; // fp29
  double v126; // fp28
  double v127; // fp27
  idVehicle_Car *v128; // r3
  idPhysics *v129; // r3
  idPhysics *v130; // r3
  idVehicle_Car *v131; // r3
  idVehicle *v132; // r29
  idNavPathPosTracker *Tracker; // r3
  double v134; // fp30
  idVehicle_Car *v135; // r3
  idPhysics *v136; // r3
  float *v137; // r3
  idPhysics *v138; // r30
  idPhysics *v139; // r28
  float *v140; // r30
  float *v141; // r3
  double v142; // fp29
  idNavPathPosTracker *enemyTracker; // r3
  idEntity *Owner; // r3
  idNavPathPosTracker *v145; // r3
  idEntity *v146; // r30
  idPhysics *v148; // r3
  idBounds *v149; // r3
  double v150; // fp31
  idVehicle_Car *v151; // r3
  double v152; // fp11
  double v153; // fp0
  double v154; // fp31
  float v155; // r10
  float v156; // r9
  char v157; // r11
  float v158; // r3
  float v159; // r10
  float v160; // r7
  float v161; // r10
  float v162; // r9
  float v163; // r8
  idVec3 *p_lastValidObstaclePos; // r28
  char v165; // r11
  char v166; // r25
  idVehicle_Car *v167; // r3
  idPhysics *v168; // r3
  float *v169; // r3
  double v170; // fp9
  double v171; // fp5
  double v172; // fp2
  double v174; // fp13
  double v176; // fp11
  double v177; // fp9
  idVec3 *v178; // r29
  double v179; // fp31
  double v180; // fp30
  double v181; // fp29
  double v182; // fp11
  double v183; // fp9
  double v184; // fp4
  double v185; // fp3
  idVec3 *desiredGoalPosition; // r30
  double v187; // fp1
  double v188; // fp29
  double v189; // fp30
  double v190; // fp28
  double v191; // fp12
  double v192; // fp7
  double v193; // fp11
  double v194; // fp9
  double v195; // fp10
  double v196; // fp3
  double v197; // fp2
  double v198; // fp0
  double v199; // fp13
  double v200; // fp10
  double v201; // fp9
  double v202; // fp30
  double v203; // fp29
  double v204; // fp28
  double v205; // fp13
  double v206; // fp12
  double v207; // fp11
  double v208; // fp26
  double v209; // fp25
  double v210; // fp18
  double v211; // fp13
  double v212; // fp12
  double v213; // fp7
  double v214; // fp6
  double v215; // fp12
  double v216; // fp10
  double v217; // fp11
  idColor *v218; // r4
  double v219; // fp6
  double v220; // fp5
  double v221; // fp4
  float *v222; // r6
  double v223; // fp3
  float *v224; // r5
  double v225; // fp2
  double v226; // fp12
  double v227; // fp10
  double v228; // fp11
  double v229; // fp6
  double v230; // fp5
  double v231; // fp4
  double v232; // fp3
  double v233; // fp2
  int v234; // r3
  float v235; // r11
  float v236; // r10
  float v237; // r9
  idGameLocal *v238; // r3
  idGameLocal_vtbl *v239; // r8
  obstacleTraceSet_t *v240; // [sp+8h] [-7A8h]
  int v241; // [sp+Ch] [-7A4h]
  int v242; // [sp+10h] [-7A0h]
  int v243; // [sp+14h] [-79Ch]
  int v244; // [sp+18h] [-798h]
  int v245; // [sp+1Ch] [-794h]
  int v246; // [sp+20h] [-790h]
  int v247; // [sp+24h] [-78Ch]
  int v248; // [sp+28h] [-788h]
  int v249; // [sp+2Ch] [-784h]
  int v250; // [sp+30h] [-780h]
  int v251; // [sp+34h] [-77Ch]
  int v252; // [sp+38h] [-778h]
  int v253; // [sp+3Ch] [-774h]
  int v254; // [sp+40h] [-770h]
  int v255; // [sp+44h] [-76Ch]
  int v256; // [sp+48h] [-768h]
  int v257; // [sp+4Ch] [-764h]
  int v258; // [sp+50h] [-760h]
  int v259; // [sp+54h] [-75Ch]
  int v260; // [sp+58h] [-758h]
  int v261; // [sp+60h] [-750h]
  int v262; // [sp+68h] [-748h]
  idVec3 v263; // [sp+70h] [-740h] BYREF
  idVec3 v264; // [sp+80h] [-730h] BYREF
  float v265; // [sp+90h] [-720h] BYREF
  float y; // [sp+94h] [-71Ch]
  float v267; // [sp+98h] [-718h]
  char v268; // [sp+9Ch] [-714h] BYREF
  idBounds v269; // [sp+A0h] [-710h] BYREF
  float v270[4]; // [sp+B8h] [-6F8h] BYREF
  float v271[4]; // [sp+C8h] [-6E8h] BYREF
  float v272[4]; // [sp+D8h] [-6D8h] BYREF
  float v273[4]; // [sp+E8h] [-6C8h] BYREF
  _DWORD v274[4]; // [sp+F8h] [-6B8h] BYREF
  float v275[4]; // [sp+108h] [-6A8h] BYREF
  _DWORD v276[4]; // [sp+118h] [-698h] BYREF
  float v277[4]; // [sp+128h] [-688h] BYREF
  _DWORD v278[4]; // [sp+138h] [-678h] BYREF
  float v279[4]; // [sp+148h] [-668h] BYREF
  float v280[4]; // [sp+158h] [-658h] BYREF
  float v281[4]; // [sp+168h] [-648h] BYREF
  float v282[4]; // [sp+178h] [-638h] BYREF
  float v283[4]; // [sp+188h] [-628h] BYREF
  idVec3 v284; // [sp+198h] [-618h] BYREF
  float v285[4]; // [sp+1A8h] [-608h] BYREF
  float v286[4]; // [sp+1B8h] [-5F8h] BYREF
  float v287[4]; // [sp+1C8h] [-5E8h] BYREF
  _DWORD v288[4]; // [sp+1D8h] [-5D8h] BYREF
  float v289[4]; // [sp+1E8h] [-5C8h] BYREF
  float v290[6]; // [sp+1F8h] [-5B8h] BYREF
  float v291[4]; // [sp+210h] [-5A0h] BYREF
  float v292[4]; // [sp+220h] [-590h] BYREF
  float v293[4]; // [sp+230h] [-580h] BYREF
  float v294[4]; // [sp+240h] [-570h] BYREF
  idVec3 v295; // [sp+250h] [-560h] BYREF
  idVec3 v296; // [sp+260h] [-550h] BYREF
  idMat3 v297; // [sp+270h] [-540h] BYREF
  obstacleRoute_t v298; // [sp+2A0h] [-510h] BYREF
  obstaclePath_t v299; // [sp+3F0h] [-3C0h] BYREF
  idVehicle_Car *v300; // [sp+660h] [-150h]
  int v301; // [sp+664h] [-14Ch]
  idRotation v302[2]; // [sp+670h] [-140h] BYREF

  if ( vai_avoidObstacles.valueInteger == 0 )
    return;
  value = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    return;
  v3 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
  if ( v3 == nullptr || idVehicle_Car::CastTo(c: v3) == nullptr )
    return;
  obstaclePath_t::obstaclePath_t(this: &v299);
  v300 = nullptr;
  v301 = 0;
  vaiTimer.avoidObstacles.state = TS_STARTED;
  LODWORD(v4) = (unsigned __int64)Sys_GetClockTicks() >> 32;
  vaiTimer.avoidObstacles.start = v4;
  v5 = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v5 & 0x1FFF] == v5 >> 13
    && (v6 = (idVehicle_Car *)gameLocal->entities.ptr[v5 & 0x1FFF]) != nullptr )
  {
    v7 = idVehicle_Car::CastTo(c: v6);
  }
  else
  {
    v7 = nullptr;
  }
  Physics = idEntity::GetPhysics(this: v7);
  v9 = (int)Physics->GetBounds(this: Physics, a2: -1);
  v10 = &v268;
  v11 = (_DWORD *)(v9 - 4);
  for ( i = 6; i != 0; --i )
  {
    ++v11;
    v10 += 4;
    *(_DWORD *)v10 = *v11;
  }
  v300 = nullptr;
  vaiTimer.avoidObstacles_findPath.state = TS_STARTED;
  v13 = (float)((float)(v269.b[1].z - v269.b[0].z) * (float)0.5);
  v269.b[1].z = (float)(v269.b[1].z - v269.b[0].z) * (float)0.5;
  v269.b[0].z = -v13;
  v14 = (float)((float)((float)((float)(v269.b[1].y - v269.b[0].y) + (float)(v269.b[1].x - v269.b[0].x))
                      * (float)0.80000001)
              * (float)0.5);
  v269.b[1].x = (float)((float)((float)(v269.b[1].y - v269.b[0].y) + (float)(v269.b[1].x - v269.b[0].x))
                      * (float)0.80000001)
              * (float)0.5;
  v269.b[1].y = v269.b[1].x;
  v269.b[0].x = -v14;
  v269.b[0].y = v269.b[0].x;
  LODWORD(v15) = (unsigned __int64)Sys_GetClockTicks() >> 32;
  vaiTimer.avoidObstacles_findPath.start = v15;
  v16 = (float *)Physics->GetLinearVelocity(this: (idPhysics *)&v295, result: (idVec3 *)Physics, a3: 0);
  _FP5 = (float)((float)((float)(v16[2] * v16[2]) + (float)((float)(*v16 * *v16) + (float)(v16[1] * v16[1])))
               - idMath::FLT_SMALLEST_NON_DENORMAL);
  __asm { fsel      f3, f5, f6, f0 }
  v19 = __frsqrte(_FP3);
  v20 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19
                                                                                      * (float)((float)((float)(v16[2] * v16[2]) + (float)((float)(*v16 * *v16) + (float)(v16[1] * v16[1])))
                                                                                              * (float)0.5))
                                                                              * (float)v19)
                                                                      - (float)1.5)
                                                      * (float)v19)
                                              * (float)((float)((float)(v16[2] * v16[2])
                                                              + (float)((float)(*v16 * *v16) + (float)(v16[1] * v16[1])))
                                                      * (float)0.5))
                                      * (float)((float)-(float)((float)((float)((float)v19
                                                                              * (float)((float)((float)(v16[2] * v16[2])
                                                                                              + (float)((float)(*v16 * *v16) + (float)(v16[1] * v16[1])))
                                                                                      * (float)0.5))
                                                                      * (float)v19)
                                                              - (float)1.5)
                                              * (float)v19))
                              - (float)1.5)
              * (float)((float)-(float)((float)((float)((float)v19
                                                      * (float)((float)((float)(v16[2] * v16[2])
                                                                      + (float)((float)(*v16 * *v16)
                                                                              + (float)(v16[1] * v16[1])))
                                                              * (float)0.5))
                                              * (float)v19)
                                      - (float)1.5)
                      * (float)v19));
  v21 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)(v16[2] * v16[2]) + (float)((float)(*v16 * *v16) + (float)(v16[1] * v16[1]))) * (float)0.5)) * (float)v19) - (float)1.5)
                                                                                      * (float)v19)
                                                                              * (float)((float)((float)(v16[2] * v16[2])
                                                                                              + (float)((float)(*v16 * *v16) + (float)(v16[1] * v16[1])))
                                                                                      * (float)0.5))
                                                                      * (float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)(v16[2] * v16[2]) + (float)((float)(*v16 * *v16) + (float)(v16[1] * v16[1]))) * (float)0.5)) * (float)v19)
                                                                                              - (float)1.5)
                                                                              * (float)v19))
                                                              - (float)1.5)
                                              * (float)((float)-(float)((float)((float)((float)v19
                                                                                      * (float)((float)((float)(v16[2] * v16[2]) + (float)((float)(*v16 * *v16) + (float)(v16[1] * v16[1])))
                                                                                              * (float)0.5))
                                                                              * (float)v19)
                                                                      - (float)1.5)
                                                      * (float)v19))
                                      * (float)((float)((float)(v16[2] * v16[2])
                                                      + (float)((float)(*v16 * *v16) + (float)(v16[1] * v16[1])))
                                              * (float)0.5))
                              * (float)v20)
                      - (float)1.5);
  _FP11 = (float)((float)((float)((float)((float)v21
                                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)(v16[2] * v16[2]) + (float)((float)(*v16 * *v16) + (float)(v16[1] * v16[1]))) * (float)0.5)) * (float)v19) - (float)1.5)
                                                                                        * (float)v19)
                                                                                * (float)((float)((float)(v16[2] * v16[2])
                                                                                                + (float)((float)(*v16 * *v16) + (float)(v16[1] * v16[1])))
                                                                                        * (float)0.5))
                                                                        * (float)((float)-(float)((float)((float)((float)v19 * (float)((float)((float)(v16[2] * v16[2]) + (float)((float)(*v16 * *v16) + (float)(v16[1] * v16[1]))) * (float)0.5)) * (float)v19)
                                                                                                - (float)1.5)
                                                                                * (float)v19))
                                                                - (float)1.5)
                                                * (float)((float)-(float)((float)((float)((float)v19
                                                                                        * (float)((float)((float)(v16[2] * v16[2]) + (float)((float)(*v16 * *v16) + (float)(v16[1] * v16[1])))
                                                                                                * (float)0.5))
                                                                                * (float)v19)
                                                                        - (float)1.5)
                                                        * (float)v19)))
                                * (float)((float)(v16[2] * v16[2])
                                        + (float)((float)(*v16 * *v16) + (float)(v16[1] * v16[1]))))
                        * (float)3.0)
                - (float)2048.0);
  __asm { fsel      f10, f11, f13, f12 }
  _FP9 = (float)((float)_FP10 - (float)128.0);
  __asm { fsel      f30, f9, f10, f0 }
  idObstacleAvoidance::AllocBuffers(this: &this->obstacleAvoidance);
  v26 = this->vehicleCar.spawnId.value;
  x = this->immediateGoalPosition.x;
  z = this->immediateGoalPosition.z;
  y = this->immediateGoalPosition.y;
  v265 = x;
  v267 = z;
  if ( gameLocal->spawnIds.ptr[v26 & 0x1FFF] == v26 >> 13
    && (v29 = (idVehicle_Car *)gameLocal->entities.ptr[v26 & 0x1FFF]) != nullptr )
  {
    v30 = idVehicle_Car::CastTo(c: v29);
  }
  else
  {
    v30 = nullptr;
  }
  v31 = idEntity::GetPhysics(this: v30);
  v31->GetOrigin(this: v31, a2: 0);
  immediateGoalAngle = this->immediateGoalAngle;
  v263 = vec3_up;
  if ( immediateGoalAngle <= 0.0 )
    v33 = -45.0;
  else
    v33 = 45.0;
  idRotation::idRotation(this: v302, rotationOrigin: &vec3_origin, rotationVec: &v263, rotationAngle: v33);
  v34 = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[v34 & 0x1FFF] == v34 >> 13
    && (v35 = (idVehicle_Car *)gameLocal->entities.ptr[v34 & 0x1FFF]) != nullptr )
  {
    v36 = idVehicle_Car::CastTo(c: v35);
  }
  else
  {
    v36 = nullptr;
  }
  v37 = idEntity::GetPhysics(this: v36);
  v38 = idRotation::ToMat3(this: v302);
  v39 = (idMat3 *)v37->GetAxis(this: v37, a2: 0);
  idMat3::operator*(this: &v297, result: v39, a: v38);
  if ( __fabs(this->immediateGoalAngle) < 45.0 )
  {
    v48 = this->immediateGoalPosition.y;
    v49 = this->immediateGoalPosition.z;
    v263.x = this->immediateGoalPosition.x;
    v263.y = v48;
    v263.z = v49;
  }
  else
  {
    VehicleCar = idVehicleAI::GetVehicleCar(this);
    v41 = idEntity::GetPhysics(this: VehicleCar);
    v42 = (float)(v297.mat[0].x * (float)500.0);
    v43 = (float)(v297.mat[0].y * (float)500.0);
    v44 = (float)(v297.mat[0].z * (float)500.0);
    v45 = (float *)v41->GetOrigin(this: v41, a2: 0);
    v46 = (float)(v45[1] + (float)v43);
    v47 = (float)(v45[2] + (float)v44);
    v263.x = (float)v42 + *v45;
    v263.y = v46;
    v263.z = v47;
  }
  v50 = this->immediateGoalPosition.y;
  v51 = this->immediateGoalPosition.z;
  GetOrigin = Physics->GetOrigin;
  v264.x = this->immediateGoalPosition.x;
  v264.y = v50;
  v264.z = v51;
  v53 = GetOrigin(this: (idPhysics *)Physics, a2: 0);
  idVehicleAI::CollectObstacles(this, physics: Physics, startPos: v53, seekPos: &v264, radius: _FP30);
  obstacleRoute_t::obstacleRoute_t(this: &v298);
  v298.areas[0].areaNum = 0;
  v298.numAreas = 1;
  v54 = (float *)Physics->GetAxis(this: Physics, a2: 0);
  v55 = (idBounds *)Physics->GetBounds(this: Physics, a2: -1);
  Radius = idBounds::GetRadius(this: v55);
  v57 = (float)((float)Radius * *v54);
  v58 = (float)(v54[1] * (float)Radius);
  v59 = (float)(v54[2] * (float)Radius);
  v60 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v61 = (float)(*v60 + (float)v57);
  v62 = (float)(v60[1] + (float)v58);
  v63 = (float)(v60[2] + (float)v59);
  v298.endAlignDir.x = vec3_origin.x;
  v298.areas[0].end.x = v263.x;
  v298.areas[0].end.y = v263.y;
  v298.areas[0].end.z = v263.z;
  v298.endTurnRadius = 0.0;
  v298.endAlignDir.y = vec3_origin.y;
  v298.endAlignDir.z = vec3_origin.z;
  v284.x = 0.0;
  v284.y = 0.0;
  v298.areas[0].start.x = v61;
  v298.areas[0].start.y = v62;
  v284.z = -1.0;
  v298.areas[0].start.z = v63;
  v64 = gameLocal->GetGameMsPerFrame(this: gameLocal, a2: GAMETIME_SCALED);
  v65 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  PathAroundObstacles = idObstacleAvoidance::FindPathAroundObstacles(
                          this: &this->obstacleAvoidance,
                          path: &v299,
                          time: v65,
                          gameMsPerFrame: v64,
                          bbox: &v269,
                          gravity: &v284,
                          obstacleRadius: 16384.0,
                          frameMoveDist: 32.0,
                          cornerCircleRadius: 64.0,
                          flags: (const int)&unk_82150000,
                          route: (const obstacleRoute_t *)&unk_821C0000,
                          traceSet: v240,
                          a13: v241,
                          a14: v242,
                          a15: v243,
                          a16: v244,
                          a17: v245,
                          a18: v246,
                          a19: v247,
                          a20: v248,
                          a21: v249,
                          a22: v250,
                          a23: v251,
                          a24: v252,
                          a25: v253,
                          a26: v254,
                          a27: v255,
                          a28: v256,
                          a29: v257,
                          a30: v258,
                          a31: v259,
                          a32: v260,
                          a33: 2,
                          a34: v261,
                          a35: &v298,
                          a36: v262,
                          a37: nullptr);
  if ( v299.firstObstacle != -1 || v299.startPosObstacle != -1 || v299.seekPosObstacle != -1 )
    v300 = (idVehicle_Car *)((int (__fastcall *)(idGameLocal *))gameLocal->GetEntityForSpawnId_2)(a1: gameLocal);
  idTimer::Stop(this: &vaiTimer.avoidObstacles_findPath);
  if ( v300 == nullptr )
    goto LABEL_62;
  if ( PathAroundObstacles )
  {
    v263 = v299.seekPos[0];
    v67 = idVehicleAI::GetVehicleCar(this);
    v68 = idEntity::GetPhysics(this: v67);
    v69 = (float *)v68->GetOrigin(this: v68, a2: 0);
    v70 = v263.z;
    v71 = v263.x;
    v72 = v263.y;
    _FP4 = (float)((float)((float)((float)(v69[1] - v263.y) * (float)(v69[1] - v263.y))
                         + (float)((float)((float)(*v69 - v263.x) * (float)(*v69 - v263.x))
                                 + (float)((float)(v69[2] - v263.z) * (float)(v69[2] - v263.z))))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f2, f4, f5, f0 }
    v75 = __frsqrte(_FP2);
    v76 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v75
                                                                                        * (float)((float)((float)((float)(v69[1] - v263.y) * (float)(v69[1] - v263.y)) + (float)((float)((float)(*v69 - v263.x) * (float)(*v69 - v263.x)) + (float)((float)(v69[2] - v263.z) * (float)(v69[2] - v263.z))))
                                                                                                * (float)0.5))
                                                                                * (float)v75)
                                                                        - (float)1.5)
                                                        * (float)v75)
                                                * (float)((float)((float)((float)(v69[1] - v263.y)
                                                                        * (float)(v69[1] - v263.y))
                                                                + (float)((float)((float)(*v69 - v263.x)
                                                                                * (float)(*v69 - v263.x))
                                                                        + (float)((float)(v69[2] - v263.z)
                                                                                * (float)(v69[2] - v263.z))))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v75
                                                                                * (float)((float)((float)((float)(v69[1] - v263.y) * (float)(v69[1] - v263.y))
                                                                                                + (float)((float)((float)(*v69 - v263.x) * (float)(*v69 - v263.x)) + (float)((float)(v69[2] - v263.z) * (float)(v69[2] - v263.z))))
                                                                                        * (float)0.5))
                                                                        * (float)v75)
                                                                - (float)1.5)
                                                * (float)v75))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v75
                                                        * (float)((float)((float)((float)(v69[1] - v263.y)
                                                                                * (float)(v69[1] - v263.y))
                                                                        + (float)((float)((float)(*v69 - v263.x)
                                                                                        * (float)(*v69 - v263.x))
                                                                                + (float)((float)(v69[2] - v263.z)
                                                                                        * (float)(v69[2] - v263.z))))
                                                                * (float)0.5))
                                                * (float)v75)
                                        - (float)1.5)
                        * (float)v75));
    if ( (float)((float)((float)-(float)((float)((float)((float)v76
                                                       * (float)((float)((float)((float)(v69[1] - v263.y)
                                                                               * (float)(v69[1] - v263.y))
                                                                       + (float)((float)((float)(*v69 - v263.x)
                                                                                       * (float)(*v69 - v263.x))
                                                                               + (float)((float)(v69[2] - v263.z)
                                                                                       * (float)(v69[2] - v263.z))))
                                                               * (float)0.5))
                                               * (float)v76)
                                       - (float)1.5)
                       * (float)v76)
               * (float)((float)((float)(v69[1] - v263.y) * (float)(v69[1] - v263.y))
                       + (float)((float)((float)(*v69 - v263.x) * (float)(*v69 - v263.x))
                               + (float)((float)(v69[2] - v263.z) * (float)(v69[2] - v263.z))))) <= 200.0 )
    {
      v71 = v299.seekPos[1].x;
      v72 = v299.seekPos[1].y;
      v70 = v299.seekPos[1].z;
    }
    if ( vai_showObstacleAvoidance.valueInteger != 0 )
    {
      v291[1] = 0.0;
      v77 = this->immediateGoalPosition.y;
      v291[3] = 1.0;
      v78 = this->immediateGoalPosition.z;
      v79 = this->immediateGoalPosition.x;
      v291[0] = 1.0;
      v291[2] = 1.0;
      *(float *)&v288[1] = v77;
      *(float *)&v288[2] = v78;
      *(float *)v288 = v79;
      ((void (__fastcall *)(idRenderWorld *, float *, _DWORD *, idVec3 *, double))clientGame->renderWorld->DebugCircle)(
        a1: clientGame->renderWorld,
        a2: v291,
        a3: v288,
        a4: &vec3_up,
        a5: 4.0);
      v292[0] = 1.0;
      v292[2] = 1.0;
      v292[3] = 1.0;
      v292[1] = 0.0;
      clientGame->renderWorld->DebugLine(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)v292,
        a3: &this->desiredGoalPosition[1],
        a4: this->desiredGoalPosition,
        a5: 10000,
        a6: false);
      v80 = idVehicleAI::GetVehicleCar(this);
      v81 = idEntity::GetPhysics(this: v80);
      v82 = (float *)v81->GetOrigin(this: v81, a2: 0);
      v264.z = 0.0;
      v83 = (float)((float)v72 - v82[1]);
      v264.x = (float)v71 - *v82;
      v264.y = v83;
      idVec3::NormalizeFast(this: &v264);
      v84 = idVehicleAI::GetVehicleCar(this);
      v85 = idEntity::GetPhysics(this: v84);
      v86 = idVehicleAI::GetVehicleCar(this);
      v87 = idEntity::GetPhysics(this: v86);
      v88 = (float)(v264.x * (float)5000.0);
      v89 = (float)(v264.y * (float)5000.0);
      v90 = (float)(v264.z * (float)5000.0);
      v91 = (float *)v85->GetOrigin(this: v85, a2: 0);
      v92 = (float)(v91[1] + (float)v89);
      v93 = (float)(v91[2] + (float)v90);
      v286[0] = (float)v88 + *v91;
      v286[1] = v92;
      v94 = v87;
      v286[2] = v93;
      renderWorld = clientGame->renderWorld;
      v97 = v87->GetOrigin;
      v96 = renderWorld->__vftable;
      v98 = (int)v97(this: v94, a2: 0);
      v96->DebugLine(
        this: renderWorld,
        a2: (const idVec4 *)&idColor::colorGreen,
        a3: (const idVec3 *)v98,
        a4: (const idVec3 *)v286,
        a5: 0,
        a6: false);
      v99 = idVehicleAI::GetVehicleCar(this);
      v100 = idEntity::GetPhysics(this: v99);
      v101 = idVehicleAI::GetVehicleCar(this);
      v102 = idEntity::GetPhysics(this: v101);
      v103 = (float *)v100->GetOrigin(this: v100, a2: 0);
      v104 = (float)(v103[2] - (float)v90);
      v105 = (float)(v103[1] - (float)v89);
      v273[0] = *v103 - (float)v88;
      v273[2] = v104;
      v106 = v102;
      v273[1] = v105;
      v107 = clientGame->renderWorld;
      v109 = v102->GetOrigin;
      v108 = v107->__vftable;
      v110 = (int)v109(this: v106, a2: 0);
      v108->DebugLine(
        this: v107,
        a2: (const idVec4 *)&idColor::colorRed,
        a3: (const idVec3 *)v110,
        a4: (const idVec3 *)v273,
        a5: 0,
        a6: false);
    }
    v111 = idVehicleAI::GetVehicleCar(this);
    v112 = idEntity::GetPhysics(this: v111);
    v113 = (int)v112->GetAxis(this: v112, a2: 0);
    v114 = *(float *)(v113 + 4);
    v115 = *(float *)(v113 + 8);
    v264.x = *(float *)v113;
    v264.y = v114;
    v264.z = v115;
    v116 = idEntity::GetPhysics(this: v300);
    v116->GetAxis(this: v116, a2: 0);
    v117 = idVehicleAI::GetVehicleCar(this);
    v118 = idEntity::GetPhysics(this: v117);
    v119 = (int)v118->GetOrigin(this: v118, a2: 0);
    v120 = *(float *)(v119 + 4);
    v121 = *(float *)(v119 + 8);
    v263.x = *(float *)v119;
    v263.y = v120;
    v263.z = v121;
    v122 = idEntity::GetPhysics(this: v300);
    v123 = (float *)v122->GetOrigin(this: v122, a2: 0);
    v124 = (float)(v123[2] - v263.z);
    v125 = (float)(*v123 - v263.x);
    v126 = (float)(v123[1] - v263.y);
    v127 = (float)((float)(v264.y * (float)(v123[1] - v263.y))
                 + (float)((float)((float)(*v123 - v263.x) * v264.x) + (float)(v264.z * (float)(v123[2] - v263.z))));
    if ( this->drivingBackwards )
      v127 = -v127;
    v128 = idVehicleAI::GetVehicleCar(this);
    v129 = idEntity::GetPhysics(this: v128);
    v129->GetLinearVelocity(this: (idPhysics *)&v296, result: (idVec3 *)v129, a3: 0);
    idVec3::NormalizeFast(this: &v296);
    v130 = idEntity::GetPhysics(this: v300);
    v130->GetLinearVelocity(this: (idPhysics *)&v295, result: (idVec3 *)v130, a3: 0);
    idVec3::NormalizeFast(this: &v295);
    v131 = idVehicle_Car::CastTo(c: v300);
    v132 = v131;
    if ( v131 != nullptr )
    {
      Tracker = idNavSplinePathMgr::GetTracker(this: this->splinePathMgr, owner: v131);
      if ( Tracker != nullptr )
      {
        v134 = (float)(this->splineTracker->pathPosition.rightDistance - Tracker->pathPosition.rightDistance);
      }
      else
      {
        v135 = idVehicleAI::GetVehicleCar(this);
        v136 = idEntity::GetPhysics(this: v135);
        v137 = (float *)v136->GetAxis(this: v136, a2: 0);
        v134 = (float)((float)((float)v125 * v137[3])
                     + (float)((float)(v137[5] * (float)v124) + (float)(v137[4] * (float)v126)));
      }
      v138 = idEntity::GetPhysics(this: v300);
      v139 = idEntity::GetPhysics(this: v300);
      v140 = (float *)v138->GetAxis(this: v138, a2: 0);
      v141 = (float *)v139->GetLinearVelocity(this: (idPhysics *)&v263, result: (idVec3 *)v139, a3: 0);
      v142 = (float)((float)((float)(*v141 * *v140) + (float)((float)(v140[2] * v141[2]) + (float)(v140[1] * v141[1])))
                   * (float)0.056818184);
      if ( !this->collideAttack
        || ((enemyTracker = this->enemyTracker) == nullptr
          ? (Owner = nullptr)
          : (Owner = idNavPathPosTracker::GetOwner(this: enemyTracker)),
            v132 != Owner
         && ((v145 = this->enemyTracker) == nullptr
           ? (v146 = nullptr)
           : (v146 = idNavPathPosTracker::GetOwner(this: v145)),
             idVehicle::GetDriver(this: v132) != v146)) )
      {
        v148 = idEntity::GetPhysics(this: v132);
        v149 = (idBounds *)v148->GetBounds(this: v148, a2: -1);
        v150 = idBounds::GetRadius(this: v149);
        if ( v127 > (float)((float)v150 * (float)-0.75) )
        {
          v151 = idVehicleAI::GetVehicleCar(this);
          idStr::operator=(this: &this->idObstaclesStr, text: v151->name.data);
          idStr::Append(this: &this->idObstaclesStr, text: " avoiding ");
          idStr::Append(this: &this->idObstaclesStr, text: v300->name.data);
          idStr::Append(this: &this->idObstaclesStr, text: " -- FRONT");
          this->immediateGoalPosition.x = v71;
          this->immediateGoalPosition.y = v72;
          this->immediateGoalPosition.z = v70;
          this->desiredSteering = idVehicleAI::DetermineSteering(this);
          if ( __fabs(v134) <= (float)((float)v150 * (float)0.75)
            && this->desiredSpeed > (double)(float)((float)v142 - (float)1.0) )
          {
            v152 = __fabs((float)(this->immediateGoalAngle * (float)0.011111111));
            v153 = (float)((float)1.0 - (float)v152);
            if ( v153 >= 0.0 )
            {
              if ( v153 <= 1.0 )
                v154 = (float)((float)1.0 - (float)v152);
              else
                v154 = 1.0;
            }
            else
            {
              v154 = 0.0;
            }
            this->desiredSpeed = (float)((float)(idVehicleAI::GetSpeedLimit(this) - (float)((float)v142 - (float)1.0))
                                       * (float)((float)v154 * (float)v154))
                               + (float)((float)v142 - (float)1.0);
          }
        }
      }
LABEL_62:
      this->lastValidObstaclePos = vec3_origin;
      goto LABEL_63;
    }
    p_lastValidObstaclePos = &this->lastValidObstaclePos;
    if ( this->lastValidObstaclePos.x != vec3_origin.x
      || this->lastValidObstaclePos.y != vec3_origin.y
      || (v165 = 1, this->lastValidObstaclePos.z != vec3_origin.z) )
    {
      v165 = 0;
    }
    if ( v165 != 0 )
      goto LABEL_108;
    if ( vai_showObstacleAvoidance.valueInteger != 0 )
      idLib::Printf(fmt: "VALID POS:");
    v166 = 1;
    v167 = idVehicleAI::GetVehicleCar(this);
    v168 = idEntity::GetPhysics(this: v167);
    v169 = (float *)v168->GetOrigin(this: v168, a2: 0);
    v170 = (float)(v169[2] - this->lastValidObstaclePos.z);
    v171 = (float)(v169[1] - this->lastValidObstaclePos.y);
    v172 = (float)((float)((float)v171 * (float)v171)
                 + (float)((float)((float)(*v169 - p_lastValidObstaclePos->x)
                                 * (float)(*v169 - p_lastValidObstaclePos->x))
                         + (float)((float)v170 * (float)v170)));
    _FP1 = (float)((float)((float)((float)v171 * (float)v171)
                         + (float)((float)((float)(*v169 - p_lastValidObstaclePos->x)
                                         * (float)(*v169 - p_lastValidObstaclePos->x))
                                 + (float)((float)v170 * (float)v170)))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    v174 = (float)((float)((float)((float)v171 * (float)v171)
                         + (float)((float)((float)(*v169 - p_lastValidObstaclePos->x)
                                         * (float)(*v169 - p_lastValidObstaclePos->x))
                                 + (float)((float)v170 * (float)v170)))
                 * (float)0.5);
    __asm { fsel      f12, f1, f2, f0 }
    v176 = __frsqrte(_FP12);
    v177 = (float)((float)v176
                 * (float)((float)((float)((float)v171 * (float)v171)
                                 + (float)((float)((float)(*v169 - p_lastValidObstaclePos->x)
                                                 * (float)(*v169 - p_lastValidObstaclePos->x))
                                         + (float)((float)v170 * (float)v170)))
                         * (float)0.5));
    if ( (float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v177 * (float)v176) - (float)1.5) * (float)v176)
                                                                                               * (float)v174)
                                                                                       * (float)((float)-(float)((float)((float)v177 * (float)v176) - (float)1.5)
                                                                                               * (float)v176))
                                                                               - (float)1.5)
                                                               * (float)((float)-(float)((float)((float)v177
                                                                                               * (float)v176)
                                                                                       - (float)1.5)
                                                                       * (float)v176))
                                                       * (float)v174)
                                               * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v177 * (float)v176) - (float)1.5)
                                                                                               * (float)v176)
                                                                                       * (float)v174)
                                                                               * (float)((float)-(float)((float)((float)v177 * (float)v176) - (float)1.5)
                                                                                       * (float)v176))
                                                                       - (float)1.5)
                                                       * (float)((float)-(float)((float)((float)v177 * (float)v176)
                                                                               - (float)1.5)
                                                               * (float)v176)))
                                       - (float)1.5)
                       * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)v177
                                                                                               * (float)v176)
                                                                                       - (float)1.5)
                                                                       * (float)v176)
                                                               * (float)v174)
                                                       * (float)((float)-(float)((float)((float)v177 * (float)v176)
                                                                               - (float)1.5)
                                                               * (float)v176))
                                               - (float)1.5)
                               * (float)((float)-(float)((float)((float)v177 * (float)v176) - (float)1.5) * (float)v176)))
               * (float)v172) < 200.0 )
    {
      v166 = 0;
      if ( vai_showObstacleAvoidance.valueInteger != 0 )
        idLib::Printf(fmt: " .. reached pos, abort maintain");
    }
    if ( v166 == 0 )
      goto LABEL_104;
    v178 = &this->desiredGoalPosition[1];
    v179 = this->desiredGoalPosition[1].x;
    v180 = this->desiredGoalPosition[1].y;
    v181 = this->desiredGoalPosition[1].z;
    v182 = (float)(this->desiredGoalPosition[1].y - this->desiredGoalPosition[2].y);
    v183 = (float)(this->desiredGoalPosition[1].z - this->desiredGoalPosition[2].z);
    v263.x = this->desiredGoalPosition[1].x - this->desiredGoalPosition[2].x;
    v263.y = v182;
    v263.z = v183;
    idVec3::NormalizeFast(this: &v263);
    v184 = (float)(this->desiredGoalPosition[0].y - (float)v180);
    v185 = (float)(this->desiredGoalPosition[0].z - (float)v181);
    v264.x = this->desiredGoalPosition[0].x - (float)v179;
    v264.y = v184;
    v264.z = v185;
    desiredGoalPosition = this->desiredGoalPosition;
    v187 = idVec3::NormalizeFast(this: &v264);
    v188 = v264.z;
    v189 = v264.y;
    v190 = v264.x;
    if ( v187 > 100.0
      && (float)((float)(v264.y * v263.y) + (float)((float)(v264.x * v263.x) + (float)(v264.z * v263.z))) < 0.5 )
    {
      v166 = 0;
      if ( vai_showObstacleAvoidance.valueInteger == 0 )
        goto LABEL_91;
      idLib::Printf(fmt: " .. desired goal not moving forward, abort maintain");
    }
    if ( vai_showObstacleAvoidance.valueInteger != 0 )
    {
      v191 = (float)(this->desiredGoalPosition[0].z + (float)50.0);
      v192 = (float)(this->desiredGoalPosition[1].z + (float)50.0);
      v193 = this->desiredGoalPosition[1].y;
      v194 = desiredGoalPosition->x;
      v195 = this->desiredGoalPosition[0].y;
      v275[0] = v178->x;
      v275[1] = v193;
      v287[2] = v191;
      v287[0] = v194;
      v275[2] = v192;
      v287[1] = v195;
      ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))clientGame->renderWorld->DebugArrow)(
        a1: clientGame->renderWorld,
        a2: &idColor::colorWhite,
        a3: v275,
        a4: v287,
        a5: 5.0);
      v196 = v178->x;
      v197 = (float)(this->desiredGoalPosition[2].z + (float)50.0);
      v198 = this->desiredGoalPosition[1].y;
      v199 = this->desiredGoalPosition[2].x;
      v280[2] = this->desiredGoalPosition[1].z + (float)50.0;
      v280[0] = v196;
      v277[2] = v197;
      v280[1] = v198;
      v277[0] = v199;
      v277[1] = this->desiredGoalPosition[2].y;
      ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))clientGame->renderWorld->DebugArrow)(
        a1: clientGame->renderWorld,
        a2: &idColor::colorLtGrey,
        a3: v277,
        a4: v280,
        a5: 5.0);
    }
LABEL_91:
    if ( v166 == 0 )
      goto LABEL_104;
    v200 = (float)((float)v72 - this->lastValidObstaclePos.y);
    v201 = (float)((float)v70 - this->lastValidObstaclePos.z);
    v263.x = (float)v71 - p_lastValidObstaclePos->x;
    v263.y = v200;
    v263.z = v201;
    if ( idVec3::NormalizeFast(this: &v263) < 1.0 )
      goto LABEL_104;
    if ( vai_showObstacleAvoidance.valueInteger != 0 )
      idLib::Printf(fmt: " .. new obs goal");
    if ( (float)((float)(v263.y * (float)v189) + (float)((float)((float)v190 * v263.x) + (float)(v263.z * (float)v188))) <= 0.70710599 )
      goto LABEL_104;
    v203 = (float)((float)(vec3_up.x * (float)0.0) - (float)((float)v190 * vec3_up.z));
    v204 = (float)((float)((float)v190 * vec3_up.y) - (float)((float)v189 * vec3_up.x));
    v202 = (float)((float)((float)v189 * vec3_up.z) - (float)(vec3_up.y * (float)0.0));
    if ( vai_showObstacleAvoidance.valueInteger != 0 )
    {
      v205 = (float)(this->desiredGoalPosition[0].z + (float)50.0);
      v206 = desiredGoalPosition->x;
      v207 = this->desiredGoalPosition[0].y;
      v281[1] = this->desiredGoalPosition[0].y;
      v281[0] = v206;
      v281[2] = v205;
      v279[0] = (float)v206 + (float)((float)v202 * (float)20.0);
      v279[1] = (float)v207 + (float)((float)v203 * (float)20.0);
      v279[2] = (float)v205 + (float)((float)v204 * (float)20.0);
      ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))clientGame->renderWorld->DebugArrow)(
        a1: clientGame->renderWorld,
        a2: &idColor::colorYellow,
        a3: v281,
        a4: v279,
        a5: 5.0);
    }
    v208 = desiredGoalPosition->x;
    v209 = this->desiredGoalPosition[0].y;
    v210 = this->desiredGoalPosition[0].z;
    v211 = (float)(this->desiredGoalPosition[0].y - (float)v72);
    v212 = (float)(this->desiredGoalPosition[0].z - (float)v70);
    v263.x = desiredGoalPosition->x - (float)v71;
    v263.y = v211;
    v263.z = v212;
    idVec3::NormalizeFast(this: &v263);
    v213 = (float)((float)v209 - this->lastValidObstaclePos.y);
    v214 = (float)((float)v210 - this->lastValidObstaclePos.z);
    v264.x = (float)v208 - p_lastValidObstaclePos->x;
    v264.y = v213;
    v264.z = v214;
    idVec3::NormalizeFast(this: &v264);
    if ( (float)((float)((float)(v264.x * (float)v202)
                       + (float)((float)(v264.z * (float)v204) + (float)(v264.y * (float)v203)))
               * (float)((float)(v263.x * (float)v202)
                       + (float)((float)(v263.z * (float)v204) + (float)(v263.y * (float)v203)))) <= 0.0 )
    {
      if ( vai_showObstacleAvoidance.valueInteger != 0 )
      {
        idLib::Printf(fmt: " - invalid pos, maintain last goal");
        v226 = desiredGoalPosition->x;
        v227 = this->desiredGoalPosition[0].y;
        v228 = (float)(this->desiredGoalPosition[0].z + (float)50.0);
        v270[0] = v71;
        v270[1] = v72;
        v270[2] = (float)v70 + (float)50.0;
        v290[0] = v226;
        v290[2] = v228;
        v290[1] = v227;
        ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))clientGame->renderWorld->DebugArrow)(
          a1: clientGame->renderWorld,
          a2: &idColor::colorRed,
          a3: v290,
          a4: v270,
          a5: 5.0);
        v218 = &idColor::colorRed;
        v229 = p_lastValidObstaclePos->x;
        v230 = (float)(this->desiredGoalPosition[0].z + (float)50.0);
        v231 = desiredGoalPosition->x;
        v222 = v272;
        v232 = this->desiredGoalPosition[0].y;
        v224 = v271;
        v233 = this->lastValidObstaclePos.y;
        v272[2] = this->lastValidObstaclePos.z + (float)50.0;
        v272[0] = v229;
        v271[2] = v230;
        v271[0] = v231;
        v271[1] = v232;
        v272[1] = v233;
        goto LABEL_103;
      }
    }
    else
    {
      v166 = 0;
      if ( vai_showObstacleAvoidance.valueInteger != 0 )
      {
        idLib::Printf(fmt: " - in front & same side, abort maintain");
        v215 = this->desiredGoalPosition[0].y;
        v216 = desiredGoalPosition->x;
        v217 = (float)(this->desiredGoalPosition[0].z + (float)50.0);
        v283[0] = v71;
        v283[1] = v72;
        v283[2] = (float)v70 + (float)50.0;
        v285[2] = v217;
        v285[1] = v215;
        v285[0] = v216;
        ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))clientGame->renderWorld->DebugArrow)(
          a1: clientGame->renderWorld,
          a2: &idColor::colorGreen,
          a3: v285,
          a4: v283,
          a5: 5.0);
        v218 = &idColor::colorGreen;
        v219 = p_lastValidObstaclePos->x;
        v220 = (float)(this->desiredGoalPosition[0].z + (float)50.0);
        v221 = this->lastValidObstaclePos.y;
        v222 = v282;
        v223 = desiredGoalPosition->x;
        v224 = v289;
        v225 = this->desiredGoalPosition[0].y;
        v282[2] = this->lastValidObstaclePos.z + (float)50.0;
        v282[0] = v219;
        v289[2] = v220;
        v282[1] = v221;
        v289[0] = v223;
        v289[1] = v225;
LABEL_103:
        ((void (__fastcall *)(idRenderWorld *, idColor *, float *, float *, double))clientGame->renderWorld->DebugArrow)(
          a1: clientGame->renderWorld,
          a2: v218,
          a3: v224,
          a4: v222,
          a5: 5.0);
      }
    }
LABEL_104:
    if ( v166 != 0 )
    {
      v71 = p_lastValidObstaclePos->x;
      v72 = this->lastValidObstaclePos.y;
      v70 = this->lastValidObstaclePos.z;
    }
    if ( vai_showObstacleAvoidance.valueInteger != 0 )
      idLib::Printf(fmt: "\n");
LABEL_108:
    this->immediateGoalPosition.x = v71;
    this->immediateGoalPosition.y = v72;
    this->immediateGoalPosition.z = v70;
    this->desiredSteering = idVehicleAI::DetermineSteering(this);
    this->desiredWheelForce = idVehicleAI::DetermineWheelForce(this);
    v234 = idVehicleAI::DetermineBraking(this);
    v235 = this->immediateGoalPosition.x;
    v236 = this->immediateGoalPosition.y;
    v237 = this->immediateGoalPosition.z;
    this->desiredBraking = v234;
    v263.x = v235;
    v263.y = v236;
    v263.z = v237;
    v238 = gameLocal;
    p_lastValidObstaclePos->x = v235;
    v239 = v238->__vftable;
    this->lastValidObstaclePos.y = v236;
    this->lastValidObstaclePos.z = v237;
    this->lastValidObstacleFrame = v239->GetGameFrame(this: v238);
    goto LABEL_63;
  }
  if ( vai_showObstacleAvoidance.valueInteger != 0 )
  {
    idLib::Printf(fmt: "INVALID PATH\n");
LABEL_63:
    if ( vai_showObstacleAvoidance.valueInteger != 0 )
    {
      v155 = this->immediateGoalPosition.y;
      v156 = this->immediateGoalPosition.z;
      v263.x = this->immediateGoalPosition.x;
      v263.y = v155;
      v263.z = v156;
      if ( v265 != v263.x || y != v263.y || (v157 = 1, v267 != v263.z) )
        v157 = 0;
      if ( v157 == 0 )
      {
        ((void (__fastcall *)(idRenderWorld *, idColor *, float *, idVec3 *, double))clientGame->renderWorld->DebugCircle)(
          a1: clientGame->renderWorld,
          a2: &idColor::colorBlue,
          a3: &v265,
          a4: &vec3_up,
          a5: 10.0);
        v158 = this->immediateGoalPosition.y;
        v274[2] = LODWORD(this->immediateGoalPosition.z);
        *(float *)&v274[1] = v158;
        v274[0] = LODWORD(this->immediateGoalPosition.x);
        ((void (__fastcall *)(idRenderWorld *, idColor *, _DWORD *, idVec3 *, double))clientGame->renderWorld->DebugCircle)(
          a1: clientGame->renderWorld,
          a2: &idColor::colorBlue,
          a3: v274,
          a4: &vec3_up,
          a5: 10.0);
        v159 = this->immediateGoalPosition.y;
        v160 = this->immediateGoalPosition.z;
        v276[0] = LODWORD(this->immediateGoalPosition.x);
        *(float *)&v276[1] = v159;
        *(float *)&v276[2] = v160;
        ((void (__fastcall *)(idRenderWorld *, idColor *, float *, _DWORD *, double))clientGame->renderWorld->DebugArrow)(
          a1: clientGame->renderWorld,
          a2: &idColor::colorBlue,
          a3: &v265,
          a4: v276,
          a5: 10.0);
      }
    }
  }
  if ( vai_showImmediateGoal.valueInteger != 0 )
  {
    v161 = this->immediateGoalPosition.x;
    v294[2] = 1.0;
    v162 = this->immediateGoalPosition.y;
    v294[1] = 0.0;
    v163 = this->immediateGoalPosition.z;
    v294[3] = 1.0;
    v294[0] = 1.0;
    *(float *)v278 = v161;
    *(float *)&v278[1] = v162;
    *(float *)&v278[2] = v163;
    ((void (__fastcall *)(idRenderWorld *, float *, _DWORD *, idVec3 *, double))clientGame->renderWorld->DebugCircle)(
      a1: clientGame->renderWorld,
      a2: v294,
      a3: v278,
      a4: &vec3_up,
      a5: 4.0);
    v293[0] = 1.0;
    v293[2] = 1.0;
    v293[3] = 1.0;
    v293[1] = 0.0;
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)v293,
      a3: &this->desiredGoalPosition[1],
      a4: this->desiredGoalPosition,
      a5: 10000,
      a6: false);
  }
  idTimer::Stop(this: &vaiTimer.avoidObstacles);
}


// ========================================================================
// ?CheckToEngageEnemy@idVehicleAI@@QAA_NXZ
// EA  : 0x82B1B3F8
// RVA : 0x00B1B3F8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

int __fastcall idVehicleAI::CheckToEngageEnemy(idVehicleAI *this)
{
  idNavPathPosTracker *enemyTracker; // r3
  idEntity *Owner; // r30
  idVehicle *Enemy; // r3
  idNavPathPosTracker *v5; // r3
  idEntity *v7; // r3

  if ( (unsigned __int8)idVehicleAI::DebugForceAttack(this) == 0 )
  {
    enemyTracker = this->enemyTracker;
    if ( enemyTracker != nullptr )
      Owner = idNavPathPosTracker::GetOwner(this: enemyTracker);
    else
      Owner = nullptr;
    Enemy = idVehicleAI::FindEnemy(this);
    idVehicleAI::SetEnemy(this, enemy: Enemy);
    v5 = this->enemyTracker;
    if ( v5 == nullptr || idNavPathPosTracker::GetOwner(this: v5) == nullptr )
      return 0;
    if ( Owner == nullptr )
    {
      if ( this->autoChooseAttackState )
        idVehicleAI::ChooseAttackState(this);
      if ( gameLocal->spawnIds.ptr[this->setup.engage.trigger.spawnId.value & 0x1FFF] == this->setup.engage.trigger.spawnId.value >> 13 )
      {
        if ( idEntityPtr<idEntity const>::operator->(this: &this->setup.engage.trigger) != nullptr )
        {
          v7 = idEntityPtr<idEntity const>::operator->(this: &this->setup.engage.trigger);
          idEntity::Activate(this: v7, activator: this);
        }
        else
        {
          idLib::Warning(
            fmt: "idVehicleAI::CheckToEngageEnemy - '%s' attempted to activate NULL trigger entity",
            this->name.data);
        }
      }
    }
  }
  return 1;
}


// ========================================================================
// ??0idVehicleAI@@QAA@XZ
// EA  : 0x82B1B8F8
// RVA : 0x00B1B8F8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

idVehicleAI *__fastcall idVehicleAI::idVehicleAI(idVehicleAI *this)
{
  idLinkList<idVehicleAI> *p_controlNode; // r27
  int *p_num; // r7
  vehiclePickupInfo_t *list; // r3
  int size; // r11
  int v6; // ctr
  bool *p_forcePlayerEnemy; // r9
  float *v8; // r11
  idLinkList<idVehicleAI> *head; // r9
  float v11[7]; // [sp+5Ch] [-C4h] BYREF

  idEntity::idEntity(this);
  this->__vftable = (idVehicleAI_vtbl *)&idVehicleAI::`vftable';
  this->declPreload.declAttacks.granularity = 1;
  this->declPreload.declAttacks.size = 20;
  this->declPreload.declAttacks.num = 0;
  this->declPreload.declAttacks.memTag = 5;
  this->declPreload.declAttacks.list = this->declPreload.declAttacks.staticList;
  this->declPreload.declAttacks.listStatic = 1;
  this->gatherQuery.index = 0x1FFF00000000LL;
  this->bestTarget.spawnId.value = 0x1FFF;
  idStaticList<idVehicleAI::ammoF_t,8>::idStaticList<idVehicleAI::ammoF_t,8>(this: &this->ammoFrac);
  this->bestPickup.spawnId.value = 0x1FFF;
  this->quickGrabPickup.spawnId.value = 0x1FFF;
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
  this->controlStack.list = nullptr;
  this->controlStack.granularity = 0;
  this->controlStack.memTag = 5;
  this->controlStack.listStatic = 0;
  this->controlStack.size = 0;
  this->controlStack.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->controlStack);
  this->overrideControl.speedLimit = -1.0;
  this->overrideControl.avoidanceType = OAT_INIT;
  this->overrideControl.stopDistance = -1.0;
  this->overrideControl.powerTurnTime = -1;
  this->overrideControl.moveDistance = -1.0;
  this->overrideControl.decelDistance = -1.0;
  this->overrideControl.maxCurveSpeed = -1.0;
  this->overrideControl.maxCurveAngle = -1.0;
  this->overrideControl.maxStepAngle = -1.0;
  this->overrideControl.powerTurnSpeed = -1.0;
  this->overrideControl.stopPowerTurnSpeed = -1.0;
  this->overrideControl.traversalStepSize = -1.0;
  this->overrideControl.backupSpeed = -1.0;
  this->overrideControl.maxCurveCosine = -1.0;
  this->overrideControl.maxStepCosine = -1.0;
  idObstacleAvoidance::idObstacleAvoidance(this: &this->obstacleAvoidance);
  this->startingPathPosition.navSpline = nullptr;
  this->startingPathPosition.distance = 0.0;
  this->startingPathPosition.rightDistance = 0.0;
  this->target.spawnId.value = 0x1FFF;
  this->specificEnemy.spawnId.value = 0x1FFF;
  this->vehicleCar.spawnId.value = 0x1FFF;
  this->vehicleEntity.spawnId.value = 0x1FFF;
  this->prespawnedVehicle.spawnId.value = 0x1FFF;
  this->idObstaclesStr.allocedAndFlag = 20;
  this->idObstaclesStr.data = this->idObstaclesStr.baseBuffer;
  this->idObstaclesStr.len = 0;
  this->idObstaclesStr.baseBuffer[0] = 0;
  idStaticList<vehiclePickupInfo_t,10>::idStaticList<vehiclePickupInfo_t,10>(this: &this->pickupList);
  this->startDecisionState.allocedAndFlag = 20;
  this->startDecisionState.len = 0;
  this->startDecisionState.data = this->startDecisionState.baseBuffer;
  this->startDecisionState.baseBuffer[0] = 0;
  vehicleAiSetup_t::vehicleAiSetup_t(this: &this->setup);
  this->dynamicAttack.decl = nullptr;
  this->dynamicAttack.params.range = -1.0;
  this->dynamicAttack.params.time = -1.0;
  this->dynamicAttack.params.minSpeed = -1.0;
  this->dynamicAttack.params.attempts = -1;
  this->dynamicAttack.params.maxSpeed = -1.0;
  this->currentWaypoint.spawnId.value = 0x1FFF;
  this->debugFireInfo.allocedAndFlag = 20;
  this->debugFireInfo.data = this->debugFireInfo.baseBuffer;
  this->debugFireInfo.len = 0;
  this->debugFireInfo.baseBuffer[0] = 0;
  this->enemyList.list = nullptr;
  this->enemyList.granularity = 0;
  this->enemyList.memTag = 5;
  this->enemyList.listStatic = 0;
  this->enemyList.size = 0;
  this->enemyList.num = 0;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->enemyList);
  idVehicleFSMManager::idVehicleFSMManager(this: &this->fsmMgr);
  idVehicleFSM::idVehicleFSM(this: &this->commandsFSM);
  idVehicleFSM::idVehicleFSM(this: &this->decisionFSM);
  idVehicleFSM::idVehicleFSM(this: &this->movementFSM);
  idVehicleFSM::idVehicleFSM(this: &this->attackFSM);
  `eh vector constructor iterator'(
    ptr: this->patrolPaths,
    size: 0x50u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))vehicleAiSetup_t::patrol_t::patrol_t,
    pDtor: (void (__fastcall *)(void *))idInfluenceTrail::~idInfluenceTrail);
  p_controlNode = &this->controlNode;
  this->controlNode.owner = nullptr;
  this->controlNode.head = &this->controlNode;
  this->controlNode.next = &this->controlNode;
  this->controlNode.prev = &this->controlNode;
  idVehicleState::idVehicleState(this: &this->cs_NextCommand, stateType: &idVS_cs_NextCommand::Type);
  this->cs_NextCommand.__vftable = (idVS_cs_NextCommand_vtbl *)&idVS_cs_NextCommand::`vftable';
  this->cs_NextCommand.mLastTrigger.spawnId.value = 0x1FFF;
  *(_QWORD *)&this->cs_NextCommand.mCurrentCommand = 0;
  idVehicleState::idVehicleState(this: &this->cs_Occupants, stateType: &idVS_cs_Occupants::Type);
  this->cs_Occupants.nextVOTime = -1;
  this->cs_Occupants.__vftable = (idVS_cs_Occupants_vtbl *)&idVS_cs_Occupants::`vftable';
  idVS_cs_Travel::idVS_cs_Travel(this: &this->cs_Travel, stateType: &idVS_cs_Travel::Type);
  idVehicleState::idVehicleState(this: &this->cs_WaitForTrigger, stateType: &idVS_cs_WaitForTrigger::Type);
  this->cs_WaitForTrigger.__vftable = (idVS_cs_WaitForTrigger_vtbl *)&idVS_cs_WaitForTrigger::`vftable';
  idVehicleState::idVehicleState(this: &this->cs_ToTrigger, stateType: &idVS_cs_ToTrigger::Type);
  this->cs_ToTrigger.__vftable = (idVS_cs_ToTrigger_vtbl *)&idVS_cs_ToTrigger::`vftable';
  idVehicleState::idVehicleState(this: &this->cs_PauseState, stateType: &idVS_cs_PauseState::Type);
  this->cs_PauseState.__vftable = (idVS_cs_PauseState_vtbl *)&idVS_cs_PauseState::`vftable';
  idVehicleState::idVehicleState(this: &this->cs_ChangeState, stateType: &idVS_cs_ChangeState::Type);
  this->cs_ChangeState.__vftable = (idVS_cs_ChangeState_vtbl *)&idVS_cs_ChangeState::`vftable';
  idVehicleState::idVehicleState(this: &this->cs_EnterVehicle, stateType: &idVS_cs_EnterVehicle::Type);
  this->cs_EnterVehicle.__vftable = (idVS_cs_EnterVehicle_vtbl *)&idVS_cs_EnterVehicle::`vftable';
  idVehicleState::idVehicleState(this: &this->cs_ExitVehicle, stateType: &idVS_cs_ExitVehicle::Type);
  this->cs_ExitVehicle.__vftable = (idVS_cs_ExitVehicle_vtbl *)&idVS_cs_ExitVehicle::`vftable';
  idVehicleState::idVehicleState(this: &this->cs_UnlockOccupants, stateType: &idVS_cs_UnlockOccupants::Type);
  this->cs_UnlockOccupants.__vftable = (idVS_cs_UnlockOccupants_vtbl *)&idVS_cs_UnlockOccupants::`vftable';
  idVehicleState::idVehicleState(this: &this->cs_WaitForTime, stateType: &idVS_cs_WaitForTime::Type);
  this->cs_WaitForTime.endTime = 0;
  this->cs_WaitForTime.__vftable = (idVS_cs_WaitForTime_vtbl *)&idVS_cs_WaitForTime::`vftable';
  idVehicleState::idVehicleState(this: &this->cs_WaitForSound, stateType: &idVS_cs_WaitForSound::Type);
  this->cs_WaitForSound.__vftable = (idVS_cs_WaitForSound_vtbl *)&idVS_cs_WaitForSound::`vftable';
  this->cs_WaitForSound.mPlayer.spawnId.value = 0x1FFF;
  idVehicleState::idVehicleState(this: &this->cs_WaitForVoiceOver, stateType: &idVS_cs_WaitForVoiceOver::Type);
  this->cs_WaitForVoiceOver.__vftable = (idVS_cs_WaitForVoiceOver_vtbl *)&idVS_cs_WaitForVoiceOver::`vftable';
  idVehicleState::idVehicleState(this: &this->cs_PowerSlide, stateType: &idVS_cs_PowerSlide::Type);
  this->cs_PowerSlide.__vftable = (idVS_cs_PowerSlide_vtbl *)&idVS_cs_PowerSlide::`vftable';
  idVehicleState::idVehicleState(this: &this->cs_WaitTilDead, stateType: &idVS_cs_WaitTilDead::Type);
  this->cs_WaitTilDead.__vftable = (idVS_cs_WaitTilDead_vtbl *)&idVS_cs_WaitTilDead::`vftable';
  idVehicleState::idVehicleState(this: &this->cs_WaitForPlayer, stateType: &idVS_CS_WaitForPlayer::Type);
  this->cs_WaitForPlayer.__vftable = (idVS_CS_WaitForPlayer_vtbl *)&idVS_CS_WaitForPlayer::`vftable';
  idVS_cs_TravelTilDead::idVS_cs_TravelTilDead(this: &this->cs_TravelTilDead, stateType: &idVS_cs_TravelTilDead::Type);
  idVehicleState::idVehicleState(this: &this->ds_Car_Chase, stateType: &idVS_ds_Car_Chase::Type);
  this->ds_Car_Chase.__vftable = (idVS_ds_Car_Chase_vtbl *)&idVS_ds_Car_Chase::`vftable';
  this->ds_Car_Chase.currentDestination.distance = 0.0;
  this->ds_Car_Chase.currentDestination.rightDistance = 0.0;
  this->ds_Car_Chase.currentDestination.navSpline = nullptr;
  this->ds_Car_Chase.overrideSpeed = -1.0;
  this->ds_Car_Chase.currentState = 0;
  this->ds_Car_Chase.enemySplineStatus = ENEMY_SPLINE_STATUS_UNKNOWN;
  this->ds_Car_Chase.currentWayPoint = nullptr;
  idVehicleState::idVehicleState(this: &this->ds_Patrol, stateType: &idVS_ds_Patrol::Type);
  this->ds_Patrol.__vftable = (idVS_ds_Patrol_vtbl *)&idVS_ds_Patrol::`vftable';
  this->ds_Patrol.startPos.distance = 0.0;
  this->ds_Patrol.startPos.rightDistance = 0.0;
  this->ds_Patrol.startPos.navSpline = nullptr;
  idVS_ds_Ambush::idVS_ds_Ambush(this: &this->ds_Ambush, stateType: &idVS_ds_Ambush::Type);
  idVehicleState::idVehicleState(this: &this->ds_Barricade, stateType: &idVS_ds_Barricade::Type);
  this->ds_Barricade.__vftable = (idVS_ds_Barricade_vtbl *)&idVS_ds_Barricade::`vftable';
  idVS_ds_Group_FollowLeader::idVS_ds_Group_FollowLeader(
    this: &this->ds_Group_FollowLeader,
    stateType: &idVS_ds_Group_FollowLeader::Type);
  idVehicleState::idVehicleState(this: &this->ds_RoverBomb, stateType: &idVS_ds_RoverBomb::Type);
  this->ds_RoverBomb.__vftable = (idVS_ds_RoverBomb_vtbl *)&idVS_ds_RoverBomb::`vftable';
  this->ds_RoverBomb.ownerCar.spawnId.value = 0x1FFF;
  idVehicleState::idVehicleState(this: &this->ds_FollowPlayerInFront, stateType: &idVS_ds_FollowPlayerInFront::Type);
  this->ds_FollowPlayerInFront.__vftable = (idVS_ds_FollowPlayerInFront_vtbl *)&idVS_ds_FollowPlayerInFront::`vftable';
  idVehicleState::idVehicleState(this: &this->as_Ram, stateType: &idVS_as_RAM::Type);
  this->as_Ram.save_decelDistance = 0.0;
  this->as_Ram.driveTowardsEnemy = false;
  this->as_Ram.save_stopDistance = 0.0;
  this->as_Ram.moveAwayFromEnemy = false;
  this->as_Ram.__vftable = (idVS_as_RAM_vtbl *)&idVS_as_RAM::`vftable';
  idVehicleState::idVehicleState(this: &this->as_ChaseShoot, stateType: &idVS_as_ChaseShoot::Type);
  this->as_ChaseShoot.goalDistOfs = 0.0;
  this->as_ChaseShoot.shootTime = 0;
  this->as_ChaseShoot.delayTime = 0;
  this->as_ChaseShoot.__vftable = (idVS_as_ChaseShoot_vtbl *)&idVS_as_ChaseShoot::`vftable';
  idVehicleState::idVehicleState(this: &this->as_ChaseSideShoot, stateType: &idVS_as_ChaseSideShoot::Type);
  this->as_ChaseSideShoot.goalDistOfs = 0.0;
  this->as_ChaseSideShoot.shootTime = 0;
  this->as_ChaseSideShoot.goalOfsDir = 0.0;
  this->as_ChaseSideShoot.delayTime = 0;
  this->as_ChaseSideShoot.__vftable = (idVS_as_ChaseSideShoot_vtbl *)&idVS_as_ChaseSideShoot::`vftable';
  idVehicleState::idVehicleState(this: &this->as_PowerTurnShoot, stateType: &idVS_as_PowerTurnShoot::Type);
  *(_QWORD *)&this->as_PowerTurnShoot.attackTime = 0;
  this->as_PowerTurnShoot.delayTime = 0;
  this->as_PowerTurnShoot.__vftable = (idVS_as_PowerTurnShoot_vtbl *)&idVS_as_PowerTurnShoot::`vftable';
  this->as_PowerTurnShoot.mode = 0;
  idVehicleState::idVehicleState(this: &this->as_ChaseSideBump, stateType: &idVS_as_ChaseSideBump::Type);
  this->as_ChaseSideBump.bumpRange = 0.0;
  this->as_ChaseSideBump.bumpDelay = 0;
  this->as_ChaseSideBump.bumpRangeDir = 0.0;
  this->as_ChaseSideBump.lastAttemptTime = 0;
  this->as_ChaseSideBump.__vftable = (idVS_as_ChaseSideBump_vtbl *)&idVS_as_ChaseSideBump::`vftable';
  this->as_ChaseSideBump.bumpAttemptTime = 0;
  idVehicleState::idVehicleState(this: &this->as_ChaseRearBump, stateType: &idVS_as_ChaseRearBump::Type);
  *(_QWORD *)&this->as_ChaseRearBump.bumpDelay = 0;
  this->as_ChaseRearBump.bumpAttemptTime = 0;
  this->as_ChaseRearBump.__vftable = (idVS_as_ChaseRearBump_vtbl *)&idVS_as_ChaseRearBump::`vftable';
  this->as_ChaseRearBump.lastBumpDelayTime = 0;
  idVS_as_RangeShoot::idVS_as_RangeShoot(this: &this->as_RangeShoot, stateType: &idVS_as_RangeShoot::Type);
  idVS_as_StrafeShoot::idVS_as_StrafeShoot(this: &this->as_StrafeShoot, stateType: &idVS_as_StrafeShoot::Type);
  idVehicleState::idVehicleState(this: &this->as_CircleShoot, stateType: &idVS_as_CircleShoot::Type);
  this->as_CircleShoot.startingYaw = 0.0;
  this->as_CircleShoot.driveTowardsEnemy = false;
  this->as_CircleShoot.save_decelDistance = 0.0;
  this->as_CircleShoot.save_stopDistance = 0.0;
  this->as_CircleShoot.circle = 0;
  this->as_CircleShoot.__vftable = (idVS_as_CircleShoot_vtbl *)&idVS_as_CircleShoot::`vftable';
  idVehicleState::idVehicleState(this: &this->as_RandomFollow, stateType: &idVS_as_RandomFollow::Type);
  this->as_RandomFollow.__vftable = (idVS_as_RandomFollow_vtbl *)&idVS_as_RandomFollow::`vftable';
  this->as_RandomFollow.startingPos.distance = 0.0;
  this->as_RandomFollow.startingPos.rightDistance = 0.0;
  this->as_RandomFollow.startingPos.navSpline = nullptr;
  this->as_RandomFollow.goalPos.distance = 0.0;
  this->as_RandomFollow.goalPos.rightDistance = 0.0;
  this->as_RandomFollow.goalPos.navSpline = nullptr;
  idVehicleState::idVehicleState(this: &this->as_Bypass, stateType: &idVS_as_Bypass::Type);
  this->as_Bypass.state = ST_INIT;
  this->as_Bypass.__vftable = (idVS_as_Bypass_vtbl *)&idVS_as_Bypass::`vftable';
  this->as_Bypass.oldEnemyPos = vec3_origin;
  idVehicleState::idVehicleState(this: &this->as_HitAndRun, stateType: &idVS_as_HitAndRun::Type);
  this->as_HitAndRun.__vftable = (idVS_as_HitAndRun_vtbl *)&idVS_as_HitAndRun::`vftable';
  this->as_HitAndRun.saveGoalPos.distance = 0.0;
  this->as_HitAndRun.saveGoalPos.rightDistance = 0.0;
  this->as_HitAndRun.saveGoalPos.navSpline = nullptr;
  *(_QWORD *)&this->as_HitAndRun.state = 0;
  idVehicleState::idVehicleState(this: &this->as_RunAway, stateType: &idVS_as_RunAway::Type);
  this->as_RunAway.__vftable = (idVS_as_RunAway_vtbl *)&idVS_as_RunAway::`vftable';
  this->as_RunAway.runawayPathPos.distance = 0.0;
  this->as_RunAway.runawayPathPos.rightDistance = 0.0;
  this->as_RunAway.runawayPathPos.navSpline = nullptr;
  this->as_RunAway.speedRate = 1.0;
  idVehicleState::idVehicleState(this: &this->as_ForcedRetreat, stateType: &idVS_as_ForcedRetreat::Type);
  this->as_ForcedRetreat.__vftable = (idVS_as_ForcedRetreat_vtbl *)&idVS_as_ForcedRetreat::`vftable';
  idVehicleState::idVehicleState(this: &this->as_WaypointTag, stateType: &idVS_as_WaypointTag::Type);
  this->as_WaypointTag.__vftable = (idVS_as_WaypointTag_vtbl *)&idVS_as_WaypointTag::`vftable';
  this->as_WaypointTag.saveGoalPos.distance = 0.0;
  this->as_WaypointTag.saveGoalPos.rightDistance = 0.0;
  this->as_WaypointTag.saveGoalPos.navSpline = nullptr;
  *(_QWORD *)&this->as_WaypointTag.state = 0;
  idVehicleState::idVehicleState(this: &this->as_FireWeapon, stateType: &idVS_as_FireWeapon::Type);
  this->as_FireWeapon.endTime = 0;
  this->as_FireWeapon.__vftable = (idVS_as_FireWeapon_vtbl *)&idVS_as_FireWeapon::`vftable';
  idVehicleState::idVehicleState(this: &this->as_FreeForm, stateType: &idVS_as_FreeForm::Type);
  this->as_FreeForm.__vftable = (idVS_as_FreeForm_vtbl *)&idVS_as_FreeForm::`vftable';
  idVehicleState::idVehicleState(this: &this->ms_MoveToGoalOnSpline, stateType: &idVS_ms_MoveToGoalOnSpline::Type);
  this->ms_MoveToGoalOnSpline.steerAroundObstacleTime = -1;
  this->ms_MoveToGoalOnSpline.steerAroundObstacleAngle = 0;
  this->ms_MoveToGoalOnSpline.__vftable = (idVS_ms_MoveToGoalOnSpline_vtbl *)&idVS_ms_MoveToGoalOnSpline::`vftable';
  idVS_ms_Backup::idVS_ms_Backup(this: &this->ms_Backup, stateType: &idVS_ms_Backup::Type);
  idVehicleState::idVehicleState(this: &this->ms_MoveToGoal, stateType: &idVS_ms_MoveToGoal::Type);
  this->ms_MoveToGoal.__vftable = (idVS_ms_MoveToGoal_vtbl *)&idVS_ms_MoveToGoal::`vftable';
  idVehicleState::idVehicleState(this: &this->ms_PowerTurn, stateType: &idVS_ms_PowerTurn::Type);
  this->ms_PowerTurn.startYaw = 0.0;
  this->ms_PowerTurn.endTime = 0;
  this->ms_PowerTurn.__vftable = (idVS_ms_PowerTurn_vtbl *)&idVS_ms_PowerTurn::`vftable';
  this->minStartDelay = 0.0;
  this->maxStartDelay = 0.0;
  this->startActive = false;
  this->declPreload.declDamage1 = nullptr;
  idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)&this->declPreload.declAttacks);
  this->bestTarget.spawnId.value = 0x1FFF;
  this->bestTargetDSqr = 1.0e30;
  this->healthFrac = 0.0;
  this->armoredHealthFrac = 0.0;
  this->totalAmmoFrac = 0.0;
  this->ramFrac = 0.0;
  this->bestPickup.spawnId.value = 0x1FFF;
  this->quickGrabPickup.spawnId.value = 0x1FFF;
  this->bestRepairIndex = -1;
  this->autoChooseAttackState = true;
  this->controlTurn = false;
  this->controlTurnVec = vec3_origin;
  this->controlTurnDir = 0;
  this->overrideControlTime = -1;
  p_num = &gameLocal->aiSplinePathMgr.trackerPool.trackers[-1].userPath[0].path.num;
  *(_QWORD *)&this->pathType = 0;
  this->enemyTracker = nullptr;
  this->splinePathMgr = (idAISplinePathMgr *)p_num;
  this->immediateGoalPosition.z = 0.0;
  this->immediateGoalPosition.y = 0.0;
  this->immediateGoalPosition.x = 0.0;
  this->desiredGoalPosition[0].z = 0.0;
  this->desiredGoalPosition[0].y = 0.0;
  this->desiredGoalPosition[0].x = 0.0;
  this->desiredGoalPosition[1].z = 0.0;
  this->desiredGoalPosition[1].y = 0.0;
  this->desiredGoalPosition[1].x = 0.0;
  this->desiredGoalPosition[2].z = 0.0;
  this->desiredGoalPosition[2].y = 0.0;
  this->desiredGoalPosition[2].x = 0.0;
  this->finalGoalPosition.z = 0.0;
  this->finalGoalPosition.y = 0.0;
  this->finalGoalPosition.x = 0.0;
  this->lastValidObstaclePos = vec3_origin;
  this->lastValidObstacleFrame = 0;
  this->startingOrigin = vec3_origin;
  this->startingAxis = mat3_identity;
  this->drivingBackwards = false;
  this->lastSpeed = 0.0;
  this->driveBackwards = false;
  this->aiNoControlVelocitySqr = 0.0;
  this->steeringOffSpline = false;
  this->turnRate = 100.0;
  this->aiNoControlTime = 0;
  this->goalRightDistance = 0.0;
  this->rdSplineReference = false;
  this->avoidTurningSteerAngle = 0.0;
  this->lockToRightDistance = false;
  this->revFrac = 0.0;
  this->allowUTurnOnNarrowPath = false;
  this->throttleValue = 0.0;
  this->avoidTurningOffSpline = false;
  this->obstacleDistance = 0.0;
  this->revvingEngine = false;
  *(_QWORD *)&this->obstacleNum = 0;
  *(_QWORD *)&this->speedFlags = 0;
  *(_QWORD *)&this->weaponFiredFrame = 0;
  this->fireWeapon = false;
  this->target.spawnId.value = 0x1FFF;
  this->vehicleCar.spawnId.value = 0x1FFF;
  this->vehicleEntity.spawnId.value = 0x1FFF;
  this->inWaterTime = 0;
  this->changeControls = true;
  this->blockedTime = 0;
  this->blockedPos = vec3_origin;
  this->stuckTime = 0;
  list = this->pickupList.list;
  this->turnSpeedRatio = 0.0;
  size = this->pickupList.size;
  *(_QWORD *)&this->handBrakeTime = 0;
  this->powerTurnTime = 0;
  this->boostAltersVelocity = true;
  this->hasConditionalAudio = false;
  *(_WORD *)&this->collideAttack = 0;
  this->triggerAction = TA_CONTINUE_EVALUATING_COMMANDS;
  memset(Dst: list, Val: 0, Size: 24 * size);
  memset(Dst: this->declPreload.declAttacks.list, Val: 0, Size: 4 * this->declPreload.declAttacks.size);
  this->desiredWheelForce = 0.0;
  this->desiredSteering = 0.0;
  this->desiredSpeed = 0.0;
  this->actualSpeed = 0.0;
  this->appliedSpeed = 0.0;
  this->vehicleWasActive = false;
  this->immediateGoalAngle = 0.0;
  *(_QWORD *)&this->lastBackupTime = 0;
  this->deltaToFinalGoal = 0.0;
  this->desiredBraking = 1;
  this->distanceToFinalGoal = 0.0;
  this->stoppingGoal = true;
  this->splineDistanceToFinalGoal = 0.0;
  this->passThroughGoal = false;
  this->rightDistanceToFinalGoal = 0.0;
  *(_QWORD *)&this->runawayTime = 0;
  this->canControlVehicle = true;
  this->dynamicVehicleAIController = nullptr;
  this->nextFireTime = 0;
  this->shootTime = 0;
  this->damageTime = 0;
  v6 = 6;
  this->guardIndex = 0;
  v11[2] = -1.0;
  this->nextAttackTime = 0;
  v11[3] = -1.0;
  this->numAttackAttempts = 0;
  v11[4] = -1.0;
  this->currentAttack = nullptr;
  v11[5] = -1.0;
  this->debugCount = 0;
  v11[6] = -1.0;
  this->ignoreEngageEnemy = false;
  p_forcePlayerEnemy = &this->setup.forcePlayerEnemy;
  this->ignoreEnemy = false;
  v8 = v11;
  this->hideWhenIdle = false;
  this->currentWaypoint.spawnId.value = 0x1FFF;
  this->wheelForce = 0.0;
  this->currentAppliedSpeed = 0.0;
  this->runDecisionFSM = true;
  this->findEnemyTime = 0;
  this->currentPatrol = 0;
  this->edgeTurnBase = 200.0;
  this->edgeTurnDist = 300.0;
  LODWORD(v11[1]) = 2;
  this->edgeTurnMinWidth = 400.0;
  this->forceSteeringTime = 0;
  this->forceSteeringDir = 0.0;
  this->defaultMaxSteerSpeed = 90.0;
  do
  {
    ++v8;
    p_forcePlayerEnemy += 4;
    *(float *)p_forcePlayerEnemy = *v8;
    --v6;
  }
  while ( v6 != 0 );
  *(_WORD *)&this->inForcedRetreatState = 0;
  head = gameLocal->vehicleAIEntities.head;
  this->controlNode.prev->next = this->controlNode.next;
  this->controlNode.next->prev = this->controlNode.prev;
  this->controlNode.prev = &this->controlNode;
  p_controlNode->head = p_controlNode;
  this->controlNode.next = head;
  this->controlNode.prev = head->prev;
  head->prev = p_controlNode;
  this->controlNode.prev->next = &this->controlNode;
  p_controlNode->head = head->head;
  this->controlNode.owner = this;
  return this;
}


// ========================================================================
// __unwind$528592
// EA  : 0x82B1C650
// RVA : 0x00B1C650
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528592()
{
  int v0; // r12

  idEntity::~idEntity(this: *(idEntity **)(v0 - 288 + 308));
}


// ========================================================================
// __unwind$528593
// EA  : 0x82B1C678
// RVA : 0x00B1C678
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528593()
{
  int v0; // r12

  idLobby::migrationInfo_t::~migrationInfo_t(this: (idSkin *)(*(_DWORD *)(v0 - 288 + 308) + 812));
}


// ========================================================================
// __unwind$528594
// EA  : 0x82B1C6A4
// RVA : 0x00B1C6A4
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528594()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 288 + 308) + 944));
}


// ========================================================================
// __unwind$528595
// EA  : 0x82B1C6D0
// RVA : 0x00B1C6D0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528595()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 288 + 308) + 1208));
}


// ========================================================================
// __unwind$528596
// EA  : 0x82B1C6FC
// RVA : 0x00B1C6FC
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528596()
{
  int v0; // r12

  idObstacleAvoidance::~idObstacleAvoidance(this: (idObstacleAvoidance *)(*(_DWORD *)(v0 - 288 + 308) + 1372));
}


// ========================================================================
// __unwind$528597
// EA  : 0x82B1C728
// RVA : 0x00B1C728
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528597()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 288 + 308) + 1612));
}


// ========================================================================
// __unwind$528598
// EA  : 0x82B1C754
// RVA : 0x00B1C754
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528598()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 288 + 308) + 1648));
}


// ========================================================================
// __unwind$528599
// EA  : 0x82B1C780
// RVA : 0x00B1C780
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528599()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 288 + 308) + 1908));
}


// ========================================================================
// __unwind$528600
// EA  : 0x82B1C7AC
// RVA : 0x00B1C7AC
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528600()
{
  int v0; // r12

  vehicleAiSetup_t::~vehicleAiSetup_t(this: (vehicleAiSetup_t *)(*(_DWORD *)(v0 - 288 + 308) + 2004));
}


// ========================================================================
// __unwind$528601
// EA  : 0x82B1C7D8
// RVA : 0x00B1C7D8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528601()
{
  int v0; // r12

  idStrStatic<260>::~idStrStatic<260>(this: (idStr *)(*(_DWORD *)(v0 - 288 + 308) + 2692));
}


// ========================================================================
// __unwind$528602
// EA  : 0x82B1C804
// RVA : 0x00B1C804
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528602()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(*(_DWORD *)(v0 - 288 + 308) + 2724));
}


// ========================================================================
// __unwind$528603
// EA  : 0x82B1C830
// RVA : 0x00B1C830
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528603()
{
  int v0; // r12

  idVehicleFSMManager::~idVehicleFSMManager(this: (idVehicleFSMManager *)(*(_DWORD *)(v0 - 288 + 308) + 2740));
}


// ========================================================================
// __unwind$528604
// EA  : 0x82B1C85C
// RVA : 0x00B1C85C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528604()
{
  int v0; // r12

  idVehicleFSM::~idVehicleFSM(this: (idVehicleFSM *)(*(_DWORD *)(v0 - 288 + 308) + 2772));
}


// ========================================================================
// __unwind$528605
// EA  : 0x82B1C888
// RVA : 0x00B1C888
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528605()
{
  int v0; // r12

  idVehicleFSM::~idVehicleFSM(this: (idVehicleFSM *)(*(_DWORD *)(v0 - 288 + 308) + 3124));
}


// ========================================================================
// __unwind$528606
// EA  : 0x82B1C8B4
// RVA : 0x00B1C8B4
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528606()
{
  int v0; // r12

  idVehicleFSM::~idVehicleFSM(this: (idVehicleFSM *)(*(_DWORD *)(v0 - 288 + 308) + 3476));
}


// ========================================================================
// __unwind$528607
// EA  : 0x82B1C8E0
// RVA : 0x00B1C8E0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528607()
{
  int v0; // r12

  idVehicleFSM::~idVehicleFSM(this: (idVehicleFSM *)(*(_DWORD *)(v0 - 288 + 308) + 3828));
}


// ========================================================================
// __unwind$528608
// EA  : 0x82B1C90C
// RVA : 0x00B1C90C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528608()
{
  int v0; // r12

  `eh vector destructor iterator'(
    ptr: (void *)(*(_DWORD *)(v0 - 288 + 308) + 4200),
    size: 0x50u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))idInfluenceTrail::~idInfluenceTrail);
}


// ========================================================================
// __unwind$528609
// EA  : 0x82B1C948
// RVA : 0x00B1C948
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528609()
{
  int v0; // r12

  idLinkList<idWaypoint>::~idLinkList<idWaypoint>(this: (idLinkList<idProp_VehiclePickup> *)(*(_DWORD *)(v0 - 288 + 308)
                                                                                           + 4372));
}


// ========================================================================
// __unwind$528610
// EA  : 0x82B1C974
// RVA : 0x00B1C974
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528610()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 4404));
}


// ========================================================================
// __unwind$528611
// EA  : 0x82B1C9A0
// RVA : 0x00B1C9A0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528611()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 4516));
}


// ========================================================================
// __unwind$528612
// EA  : 0x82B1C9CC
// RVA : 0x00B1C9CC
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528612()
{
  int v0; // r12

  idVS_cs_Travel::~idVS_cs_Travel(this: (idVS_cs_TravelTilDead *)(*(_DWORD *)(v0 - 288 + 308) + 4620));
}


// ========================================================================
// __unwind$528613
// EA  : 0x82B1C9F8
// RVA : 0x00B1C9F8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528613()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 4756));
}


// ========================================================================
// __unwind$528614
// EA  : 0x82B1CA24
// RVA : 0x00B1CA24
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528614()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 4856));
}


// ========================================================================
// __unwind$528615
// EA  : 0x82B1CA50
// RVA : 0x00B1CA50
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528615()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 4956));
}


// ========================================================================
// __unwind$528616_0
// EA  : 0x82B1CA7C
// RVA : 0x00B1CA7C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528616_0()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 5056));
}


// ========================================================================
// __unwind$528617
// EA  : 0x82B1CAA8
// RVA : 0x00B1CAA8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528617()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 5156));
}


// ========================================================================
// __unwind$528618
// EA  : 0x82B1CAD4
// RVA : 0x00B1CAD4
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528618()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 5256));
}


// ========================================================================
// __unwind$528619
// EA  : 0x82B1CB00
// RVA : 0x00B1CB00
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528619()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 5356));
}


// ========================================================================
// __unwind$528620
// EA  : 0x82B1CB2C
// RVA : 0x00B1CB2C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528620()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 5456));
}


// ========================================================================
// __unwind$528621
// EA  : 0x82B1CB58
// RVA : 0x00B1CB58
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528621()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 5560));
}


// ========================================================================
// __unwind$528622
// EA  : 0x82B1CB84
// RVA : 0x00B1CB84
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528622()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 5664));
}


// ========================================================================
// __unwind$528623
// EA  : 0x82B1CBB0
// RVA : 0x00B1CBB0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528623()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 5764));
}


// ========================================================================
// __unwind$528624
// EA  : 0x82B1CBDC
// RVA : 0x00B1CBDC
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528624()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 5864));
}


// ========================================================================
// __unwind$528625
// EA  : 0x82B1CC08
// RVA : 0x00B1CC08
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528625()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 5964));
}


// ========================================================================
// __unwind$528626
// EA  : 0x82B1CC34
// RVA : 0x00B1CC34
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528626()
{
  int v0; // r12

  idVS_cs_Travel::~idVS_cs_Travel(this: (idVS_cs_TravelTilDead *)(*(_DWORD *)(v0 - 288 + 308) + 6064));
}


// ========================================================================
// __unwind$528627
// EA  : 0x82B1CC60
// RVA : 0x00B1CC60
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528627()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 6200));
}


// ========================================================================
// __unwind$528628
// EA  : 0x82B1CC8C
// RVA : 0x00B1CC8C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528628()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 6328));
}


// ========================================================================
// __unwind$528629
// EA  : 0x82B1CCB8
// RVA : 0x00B1CCB8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528629()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 6440));
}


// ========================================================================
// __unwind$528630
// EA  : 0x82B1CCE4
// RVA : 0x00B1CCE4
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528630()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 6584));
}


// ========================================================================
// __unwind$528631
// EA  : 0x82B1CD10
// RVA : 0x00B1CD10
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528631()
{
  int v0; // r12

  idVS_ds_Group_FollowLeader::~idVS_ds_Group_FollowLeader(this: (idVS_ds_Group_FollowLeader *)(*(_DWORD *)(v0 - 288 + 308)
                                                                                             + 6684));
}


// ========================================================================
// __unwind$528632
// EA  : 0x82B1CD3C
// RVA : 0x00B1CD3C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528632()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 6824));
}


// ========================================================================
// __unwind$528633
// EA  : 0x82B1CD68
// RVA : 0x00B1CD68
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528633()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 6928));
}


// ========================================================================
// __unwind$528634
// EA  : 0x82B1CD94
// RVA : 0x00B1CD94
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528634()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 7028));
}


// ========================================================================
// __unwind$528635
// EA  : 0x82B1CDC0
// RVA : 0x00B1CDC0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528635()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 7140));
}


// ========================================================================
// __unwind$528636
// EA  : 0x82B1CDEC
// RVA : 0x00B1CDEC
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528636()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 7252));
}


// ========================================================================
// __unwind$528637
// EA  : 0x82B1CE18
// RVA : 0x00B1CE18
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528637()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 7368));
}


// ========================================================================
// __unwind$528638
// EA  : 0x82B1CE44
// RVA : 0x00B1CE44
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528638()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 7484));
}


// ========================================================================
// __unwind$528639
// EA  : 0x82B1CE70
// RVA : 0x00B1CE70
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528639()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 7604));
}


// ========================================================================
// __unwind$528640
// EA  : 0x82B1CE9C
// RVA : 0x00B1CE9C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528640()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 7720));
}


// ========================================================================
// __unwind$528641
// EA  : 0x82B1CEC8
// RVA : 0x00B1CEC8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528641()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 7884));
}


// ========================================================================
// __unwind$528642
// EA  : 0x82B1CEF4
// RVA : 0x00B1CEF4
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528642()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 8060));
}


// ========================================================================
// __unwind$528643
// EA  : 0x82B1CF20
// RVA : 0x00B1CF20
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528643()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 8180));
}


// ========================================================================
// __unwind$528644
// EA  : 0x82B1CF4C
// RVA : 0x00B1CF4C
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528644()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 8304));
}


// ========================================================================
// __unwind$528645
// EA  : 0x82B1CF78
// RVA : 0x00B1CF78
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528645()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 8420));
}


// ========================================================================
// __unwind$528646
// EA  : 0x82B1CFA4
// RVA : 0x00B1CFA4
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528646()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 8540));
}


// ========================================================================
// __unwind$528647
// EA  : 0x82B1CFD0
// RVA : 0x00B1CFD0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528647()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 8656));
}


// ========================================================================
// __unwind$528648
// EA  : 0x82B1CFFC
// RVA : 0x00B1CFFC
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528648()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 8756));
}


// ========================================================================
// __unwind$528649
// EA  : 0x82B1D028
// RVA : 0x00B1D028
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528649()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 8876));
}


// ========================================================================
// __unwind$528650
// EA  : 0x82B1D054
// RVA : 0x00B1D054
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528650()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 8980));
}


// ========================================================================
// __unwind$528651
// EA  : 0x82B1D080
// RVA : 0x00B1D080
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528651()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 9080));
}


// ========================================================================
// __unwind$528652
// EA  : 0x82B1D0AC
// RVA : 0x00B1D0AC
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528652()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 9188));
}


// ========================================================================
// __unwind$528653
// EA  : 0x82B1D0D8
// RVA : 0x00B1D0D8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528653()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 9316));
}


// ========================================================================
// __unwind$528654
// EA  : 0x82B1D104
// RVA : 0x00B1D104
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void _unwind_528654()
{
  int v0; // r12

  idVS_as_ForcedRetreat::~idVS_as_ForcedRetreat(this: (idVS_cs_NextCommand *)(*(_DWORD *)(v0 - 288 + 308) + 9416));
}


// ========================================================================
// ?DetermineDormancy@idVehicleAI@@QAAXXZ
// EA  : 0x82B1D190
// RVA : 0x00B1D190
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::DetermineDormancy(idVehicleAI *this)
{
  idNavPathPosTracker *enemyTracker; // r3
  idState *curState; // r30
  idPlayer *Player; // r4
  idNavPathPosTracker *Tracker; // r3
  idNavPathPosTracker *splineTracker; // r11
  navSplinePath_t *ShortestPath; // r3
  bool v8; // cr57
  char v9; // r11
  char v10; // r28
  int v11; // r29
  idGameLocal *v12; // r10
  int v13; // r30
  int value; // r9
  idVehicleAI *v15; // r3
  idVehicleAI *v16; // r3
  idVehicle_Car *VehicleCar; // r3
  idVehicle_Car *v18; // r3
  idVehicle_Car *v19; // r3
  idAISplinePathMgr *splinePathMgr; // r3

  if ( vai_dormancyTest.valueInteger != 0 )
  {
    if ( this->setup.dormancy.distance <= 0.0 )
      return;
    if ( this->setup.dormancy.isDormant )
    {
      if ( idAISplinePathMgr::CanFindEnemy(this: this->splinePathMgr, vai: this) )
      {
        enemyTracker = this->enemyTracker;
        if ( enemyTracker != nullptr && idNavPathPosTracker::GetOwner(this: enemyTracker) != nullptr )
          this->setup.engage.alertSoundTime = 0;
        this->enemyTracker = nullptr;
        this->target.spawnId.value = 0x1FFF;
        this->setup.dormancy.isAttacking = idVehicleAI::CheckToEngageEnemy(this);
      }
      else
      {
        this->setup.dormancy.isAttacking = false;
      }
    }
    else
    {
      curState = this->attackFSM.curState;
      this->setup.dormancy.isAttacking = idFiniteStateMachine::FindState(
                                           this: &this->attackFSM,
                                           stateType: &idVS_Idle::Type) != curState;
    }
    if ( !this->setup.dormancy.isAttacking )
    {
      Player = idGameLocal::GetPlayer(this: gameLocal, i: 0);
      if ( Player == nullptr )
        return;
      Tracker = idNavSplinePathMgr::FindTracker(
                  this: this->splinePathMgr,
                  owner: Player,
                  createTrackerIfNotFound: false);
      if ( Tracker == nullptr )
        return;
      splineTracker = this->splineTracker;
      if ( splineTracker == nullptr )
        splineTracker = &this->splinePathMgr->null_splineTracker;
      ShortestPath = idNavSplinePathMgr::GetShortestPath(
                       this: (idNavSplinePathMgr *)LODWORD(splineTracker->pathPosition.distance),
                       start: (idNavSplinePosition *)LODWORD(splineTracker->pathPosition.rightDistance),
                       end: (idNavSplinePosition *)__ROL4__(splineTracker->pathPosition.navSpline, 32),
                       path: (navSplinePath_t *)LODWORD(Tracker->pathPosition.rightDistance));
      if ( ShortestPath != nullptr )
      {
        if ( this->setup.dormancy.isDormant )
          v8 = ShortestPath->distance > (double)(float)(this->setup.dormancy.distance - (float)1000.0);
        else
          v8 = ShortestPath->distance > (double)this->setup.dormancy.distance;
        this->setup.dormancy.isNearPlayer = !v8;
      }
      else
      {
        this->setup.dormancy.isNearPlayer = true;
      }
    }
    if ( this->setup.dormancy.isAttacking || (v9 = 1, this->setup.dormancy.isNearPlayer) )
      v9 = 0;
    v10 = v9;
    if ( v9 != 0 )
    {
      v11 = 0;
      if ( this->setup.dormancy.group.num > 0 )
      {
        v12 = gameLocal;
        v13 = 0;
        while ( 1 )
        {
          value = this->setup.dormancy.group.list[v13].spawnId.value;
          if ( v12->spawnIds.ptr[value & 0x1FFF] == value >> 13
            && (v15 = (idVehicleAI *)v12->entities.ptr[value & 0x1FFF]) != nullptr )
          {
            v16 = idVehicleAI::CastTo(c: v15);
            v12 = gameLocal;
          }
          else
          {
            v16 = nullptr;
          }
          if ( v16->setup.dormancy.isAttacking || v16->setup.dormancy.isNearPlayer )
            break;
          ++v11;
          ++v13;
          if ( v11 >= this->setup.dormancy.group.num )
            goto LABEL_37;
        }
        v10 = 0;
      }
    }
LABEL_37:
    if ( vai_canChangeDormancy.valueInteger != 0 )
    {
      if ( v10 != 0 )
      {
        if ( !this->setup.dormancy.isDormant )
        {
          VehicleCar = idVehicleAI::GetVehicleCar(this);
          VehicleCar->Hide_2(this: VehicleCar);
          this->setup.dormancy.isDormant = true;
          idAISplinePathMgr::AddToDormancyList(this: this->splinePathMgr, vai: this);
        }
      }
      else if ( this->setup.dormancy.isDormant )
      {
        v18 = idVehicleAI::GetVehicleCar(this);
        v18->Show(this: v18);
        this->setup.dormancy.isDormant = false;
        idAISplinePathMgr::RemoveFromDormancyList(this: this->splinePathMgr, vai: this);
      }
    }
  }
  else if ( vai_canChangeDormancy.valueInteger != 0 && this->setup.dormancy.isDormant )
  {
    v19 = idVehicleAI::GetVehicleCar(this);
    v19->Show(this: v19);
    splinePathMgr = this->splinePathMgr;
    this->setup.dormancy.isDormant = false;
    idAISplinePathMgr::RemoveFromDormancyList(this: splinePathMgr, vai: this);
  }
}


// ========================================================================
// ?ShouldEnterDormancy@idVehicleAI@@UAA_NXZ
// EA  : 0x82B1D4C8
// RVA : 0x00B1D4C8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

BOOL __fastcall idVehicleAI::ShouldEnterDormancy(idVehicleAI *this)
{
  int value; // r10
  idVehicle_Car *v3; // r3
  idVehicle_Car *v4; // r3

  value = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v3 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v4 = idVehicle_Car::CastTo(c: v3);
  }
  else
  {
    v4 = nullptr;
  }
  if ( (*((_BYTE *)&v4->flags + 1) & 0x80) != 0 )
    return true;
  idVehicleAI::DetermineDormancy(this);
  return this->setup.dormancy.isDormant;
}


// ========================================================================
// ?ShouldLeaveDormancy@idVehicleAI@@UAA_NXZ
// EA  : 0x82B1D570
// RVA : 0x00B1D570
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

BOOL __fastcall idVehicleAI::ShouldLeaveDormancy(idVehicleAI *this)
{
  int value; // r10
  idVehicle_Car *v3; // r3
  idVehicle_Car *v4; // r3

  value = this->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v3 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v4 = idVehicle_Car::CastTo(c: v3);
  }
  else
  {
    v4 = nullptr;
  }
  if ( (*((_BYTE *)&v4->flags + 1) & 0x80) != 0 )
    return false;
  idVehicleAI::DetermineDormancy(this);
  return (_cntlzw(this->setup.dormancy.isDormant) & 0x20) != 0;
}


// ========================================================================
// ?EngageEnemy@idVehicleAI@@QAAXXZ
// EA  : 0x82B1D620
// RVA : 0x00B1D620
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __fastcall idVehicleAI::EngageEnemy(idVehicleAI *this)
{
  idNavPathPosTracker *enemyTracker; // r3

  if ( !this->ignoreEngageEnemy )
  {
    enemyTracker = this->enemyTracker;
    if ( enemyTracker != nullptr && idNavPathPosTracker::GetOwner(this: enemyTracker) != nullptr )
    {
      if ( (unsigned __int8)idVehicleAI::HandleForcedRetreatState(this) == 0
        && (unsigned __int8)idVehicleAI::HandleRunAway(this) == 0 )
      {
        idVehicleAI::ContinueToEngageEnemy(this);
      }
    }
    else
    {
      idVehicleAI::CheckToEngageEnemy(this);
    }
  }
}


// ========================================================================
// `dynamic initializer for 'vai_throwforce''
// EA  : 0x83369F18
// RVA : 0x01369F18
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_throwforce__()
{
  idCVar::idCVar(
    this: &vai_throwforce,
    name: "vai_throwforce",
    value: "0",
    flags: 4,
    description: "Throw force",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_throwforce__);
}


// ========================================================================
// `dynamic initializer for 'vai_minSkidFrac''
// EA  : 0x83369F70
// RVA : 0x01369F70
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_minSkidFrac__()
{
  idCVar::idCVar(
    this: &vai_minSkidFrac,
    name: "vai_minSkidFrac",
    value: "0.5",
    flags: 4,
    description: "0 - 1. Applied to friction when handbraking.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_minSkidFrac__);
}


// ========================================================================
// `dynamic initializer for 'vai_attackState''
// EA  : 0x83369FC8
// RVA : 0x01369FC8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_attackState__()
{
  idCVar::idCVar(
    this: &vai_attackState,
    name: "vai_attackState",
    value: "-1",
    flags: 2,
    description: "Force ai to use specific attack state.  0 - 10 (-1 disables)",
    valueMin: -1.0,
    valueMax: 30.0,
    valueCompletion: (void (__fastcall *)(idAutoComplete *))"visemeExType_t",
    a9: (int)"Could not find AI state, idVS_ds_Car_Chase! ",
    a10: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_attackState__);
}


// ========================================================================
// `dynamic initializer for 'vai_attackRange''
// EA  : 0x8336A030
// RVA : 0x0136A030
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_attackRange__()
{
  idCVar::idCVar(
    this: &vai_attackRange,
    name: "vai_attackRange",
    value: "0",
    flags: 4,
    description: "Range to use for vai_attackState (depending on state).",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_attackRange__);
}


// ========================================================================
// `dynamic initializer for 'vai_showEnemyVisibleTrace''
// EA  : 0x8336A088
// RVA : 0x0136A088
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_showEnemyVisibleTrace__()
{
  idCVar::idCVar(
    this: &vai_showEnemyVisibleTrace,
    name: "vai_showEnemyVisibleTrace",
    value: "0",
    flags: 1,
    description: "Draws a line between ai and enemy (red=obsruction, green=no obstruction)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_showEnemyVisibleTrace__);
}


// ========================================================================
// `dynamic initializer for 'vai_showPath''
// EA  : 0x8336A0E0
// RVA : 0x0136A0E0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_showPath__()
{
  idCVar::idCVar(
    this: &vai_showPath,
    name: "vai_showPath",
    value: "0",
    flags: 4,
    description: "Enable displaying of spline paths",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_showPath__);
}


// ========================================================================
// `dynamic initializer for 'vai_stats''
// EA  : 0x8336A138
// RVA : 0x0136A138
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_stats__()
{
  idCVar::idCVar(
    this: &vai_stats,
    name: "vai_stats",
    value: "0",
    flags: 1,
    description: "Enable vehicle stats display",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_stats__);
}


// ========================================================================
// `dynamic initializer for 'vai_enableFindEnemy''
// EA  : 0x8336A190
// RVA : 0x0136A190
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_enableFindEnemy__()
{
  idCVar::idCVar(
    this: &vai_enableFindEnemy,
    name: "vai_enableFindEnemy",
    value: "1",
    flags: 1,
    description: "Enable FindEnemy()",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_enableFindEnemy__);
}


// ========================================================================
// `dynamic initializer for 'vai_dormancyTest''
// EA  : 0x8336A1E8
// RVA : 0x0136A1E8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_dormancyTest__()
{
  idCVar::idCVar(
    this: &vai_dormancyTest,
    name: "vai_dormancyTest",
    value: "1",
    flags: 1,
    description: "AI that have been marked will become dormant when player is out of range",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_dormancyTest__);
}


// ========================================================================
// `dynamic initializer for 'vai_debug_attackstate''
// EA  : 0x8336A240
// RVA : 0x0136A240
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_debug_attackstate__()
{
  idCVar::idCVar(
    this: &vai_debug_attackstate,
    name: "vai_debug_attackstate",
    value: "0",
    flags: 1,
    description: "print attack state info over their heads",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_debug_attackstate__);
}


// ========================================================================
// `dynamic initializer for 'vai_debug_attackstate_draw''
// EA  : 0x8336A298
// RVA : 0x0136A298
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_debug_attackstate_draw__()
{
  idCVar::idCVar(
    this: &vai_debug_attackstate_draw,
    name: "vai_debug_attackstate_draw",
    value: "0",
    flags: 1,
    description: "draw debug info for attack states",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_debug_attackstate_draw__);
}


// ========================================================================
// `dynamic initializer for 'vai_debug_attackstate_textscale''
// EA  : 0x8336A2F0
// RVA : 0x0136A2F0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_debug_attackstate_textscale__()
{
  idCVar::idCVar(
    this: &vai_debug_attackstate_textscale,
    name: "vai_debug_attackstate_textscale",
    value: "1.0",
    flags: 4,
    description: "scale of debug text",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_debug_attackstate_textscale__);
}


// ========================================================================
// `dynamic initializer for 'vai_debug_attackstate_textscale2''
// EA  : 0x8336A348
// RVA : 0x0136A348
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_debug_attackstate_textscale2__()
{
  idCVar::idCVar(
    this: &vai_debug_attackstate_textscale2,
    name: "vai_debug_attackstate_textscale2",
    value: "1.0",
    flags: 4,
    description: "scale of debug text",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_debug_attackstate_textscale2__);
}


// ========================================================================
// `dynamic initializer for 'vai_debug_attackstate_textscale3''
// EA  : 0x8336A3A0
// RVA : 0x0136A3A0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_debug_attackstate_textscale3__()
{
  idCVar::idCVar(
    this: &vai_debug_attackstate_textscale3,
    name: "vai_debug_attackstate_textscale3",
    value: "1.0",
    flags: 4,
    description: "scale of debug text",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_debug_attackstate_textscale3__);
}


// ========================================================================
// `dynamic initializer for 'vai_debug_attackstate_zoffset''
// EA  : 0x8336A3F8
// RVA : 0x0136A3F8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_debug_attackstate_zoffset__()
{
  idCVar::idCVar(
    this: &vai_debug_attackstate_zoffset,
    name: "vai_debug_attackstate_zoffset",
    value: "100.0",
    flags: 4,
    description: "up offset of text",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_debug_attackstate_zoffset__);
}


// ========================================================================
// `dynamic initializer for 'vai_debug_attackstate_zoffset2''
// EA  : 0x8336A450
// RVA : 0x0136A450
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_debug_attackstate_zoffset2__()
{
  idCVar::idCVar(
    this: &vai_debug_attackstate_zoffset2,
    name: "vai_debug_attackstate_zoffset2",
    value: "80.0",
    flags: 4,
    description: "up offset of text",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_debug_attackstate_zoffset2__);
}


// ========================================================================
// `dynamic initializer for 'vai_debug_attackstate_zoffset3''
// EA  : 0x8336A4A8
// RVA : 0x0136A4A8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_debug_attackstate_zoffset3__()
{
  idCVar::idCVar(
    this: &vai_debug_attackstate_zoffset3,
    name: "vai_debug_attackstate_zoffset3",
    value: "60.0",
    flags: 4,
    description: "up offset of text",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_debug_attackstate_zoffset3__);
}


// ========================================================================
// `dynamic initializer for 'vai_follow''
// EA  : 0x8336A500
// RVA : 0x0136A500
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_follow__()
{
  idCVar::idCVar(
    this: &vai_follow,
    name: "vai_follow",
    value: "0",
    flags: 0,
    description: "Name of vehicle to follow.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_follow__);
}


// ========================================================================
// `dynamic initializer for 'vai_next''
// EA  : 0x8336A558
// RVA : 0x0136A558
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_next__()
{
  idCVar::idCVar(
    this: &vai_next,
    name: "vai_next",
    value: "0",
    flags: 1,
    description: "Cycle to next vehicle to follow.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_next__);
}


// ========================================================================
// `dynamic initializer for 'vai_prev''
// EA  : 0x8336A5B0
// RVA : 0x0136A5B0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_prev__()
{
  idCVar::idCVar(
    this: &vai_prev,
    name: "vai_prev",
    value: "0",
    flags: 1,
    description: "Cycle to prev vehicle to follow.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_prev__);
}


// ========================================================================
// `dynamic initializer for 'vai_cam''
// EA  : 0x8336A608
// RVA : 0x0136A608
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_cam__()
{
  idCVar::idCVar(
    this: &vai_cam,
    name: "vai_cam",
    value: "0",
    flags: 4,
    description: "Enable vehicle AI camera.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_cam__);
}


// ========================================================================
// `dynamic initializer for 'vai_cam_yaw''
// EA  : 0x8336A660
// RVA : 0x0136A660
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_cam_yaw__()
{
  idCVar::idCVar(
    this: &vai_cam_yaw,
    name: "vai_cam_yaw",
    value: "0",
    flags: 4,
    description: "Yaw to view vehicle",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_cam_yaw__);
}


// ========================================================================
// `dynamic initializer for 'vai_cam_pitch''
// EA  : 0x8336A6B8
// RVA : 0x0136A6B8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_cam_pitch__()
{
  idCVar::idCVar(
    this: &vai_cam_pitch,
    name: "vai_cam_pitch",
    value: "0",
    flags: 4,
    description: "Pitch to view vehicle",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_cam_pitch__);
}


// ========================================================================
// `dynamic initializer for 'vai_cam_range''
// EA  : 0x8336A710
// RVA : 0x0136A710
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_cam_range__()
{
  idCVar::idCVar(
    this: &vai_cam_range,
    name: "vai_cam_range",
    value: "500",
    flags: 4,
    description: "Range to view vehicle",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_cam_range__);
}


// ========================================================================
// `dynamic initializer for 'vai_cam_height''
// EA  : 0x8336A768
// RVA : 0x0136A768
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_cam_height__()
{
  idCVar::idCVar(
    this: &vai_cam_height,
    name: "vai_cam_height",
    value: "100",
    flags: 4,
    description: "Height to view vehicle",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_cam_height__);
}


// ========================================================================
// `dynamic initializer for 'vai_showRespawnRadius''
// EA  : 0x8336A7C0
// RVA : 0x0136A7C0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_showRespawnRadius__()
{
  idCVar::idCVar(
    this: &vai_showRespawnRadius,
    name: "vai_showRespawnRadius",
    value: "0",
    flags: 2,
    description: "Show data about AI waiting to respawn.  1 = show all AI radius, 2 = show selected AI radius",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_showRespawnRadius__);
}


// ========================================================================
// `dynamic initializer for 'vai_showRespawnSteps''
// EA  : 0x8336A818
// RVA : 0x0136A818
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_showRespawnSteps__()
{
  idCVar::idCVar(
    this: &vai_showRespawnSteps,
    name: "vai_showRespawnSteps",
    value: "20",
    flags: 4,
    description: "Steps for showRespawn radius",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_showRespawnSteps__);
}


// ========================================================================
// `dynamic initializer for 'vai_showRespawnTextSize''
// EA  : 0x8336A870
// RVA : 0x0136A870
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_showRespawnTextSize__()
{
  idCVar::idCVar(
    this: &vai_showRespawnTextSize,
    name: "vai_showRespawnTextSize",
    value: "10",
    flags: 4,
    description: "Text size for respawn info",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_showRespawnTextSize__);
}


// ========================================================================
// `dynamic initializer for 'vai_defaultFriction''
// EA  : 0x8336A8C8
// RVA : 0x0136A8C8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_defaultFriction__()
{
  idCVar::idCVar(
    this: &vai_defaultFriction,
    name: "vai_defaultFriction",
    value: "0",
    flags: 1,
    description: "Uses vehicle's default friction tables.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_defaultFriction__);
}


// ========================================================================
// `dynamic initializer for 'vai_god''
// EA  : 0x8336A920
// RVA : 0x0136A920
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_god__()
{
  idCVar::idCVar(
    this: &vai_god,
    name: "vai_god",
    value: "0",
    flags: 1,
    description: "God mode for vehicle AI",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_god__);
}


// ========================================================================
// `dynamic initializer for 'vai_deferCollectObstacles''
// EA  : 0x8336A978
// RVA : 0x0136A978
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_deferCollectObstacles__()
{
  idCVar::idCVar(
    this: &vai_deferCollectObstacles,
    name: "vai_deferCollectObstacles",
    value: "1",
    flags: 1,
    description: "Use deferred GatherTouchingBounds()",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_deferCollectObstacles__);
}


// ========================================================================
// `dynamic initializer for 'vai_forceNoRespawnInBackground''
// EA  : 0x8336A9D0
// RVA : 0x0136A9D0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_forceNoRespawnInBackground__()
{
  idCVar::idCVar(
    this: &vai_forceNoRespawnInBackground,
    name: "vai_forceNoRespawnInBackground",
    value: "0",
    flags: 1,
    description: "Forces AI to spawn regardless of player being able to see it",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_forceNoRespawnInBackground__);
}


// ========================================================================
// `dynamic initializer for 'vai_canChangeDormancy''
// EA  : 0x8336AA28
// RVA : 0x0136AA28
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_canChangeDormancy__()
{
  idCVar::idCVar(
    this: &vai_canChangeDormancy,
    name: "vai_canChangeDormancy",
    value: "1",
    flags: 1,
    description: "1 = Dormancy state will change as needed, 0 = Dormancy states are locked -- they won't change",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_canChangeDormancy__);
}


// ========================================================================
// `dynamic initializer for 'vai_showObstacleAvoidance''
// EA  : 0x8336AA80
// RVA : 0x0136AA80
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_showObstacleAvoidance__()
{
  idCVar::idCVar(
    this: &vai_showObstacleAvoidance,
    name: "vai_showObstacleAvoidance",
    value: "0",
    flags: 1,
    description: "Show obstacle avoidance debug.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_showObstacleAvoidance__);
}


// ========================================================================
// `dynamic initializer for 'vai_ignoreObstaclePathDist''
// EA  : 0x8336AAD8
// RVA : 0x0136AAD8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_ignoreObstaclePathDist__()
{
  idCVar::idCVar(
    this: &vai_ignoreObstaclePathDist,
    name: "vai_ignoreObstaclePathDist",
    value: "300.0",
    flags: 4,
    description: "Distance at which AI ignores obstacle pos and drives towards goal.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_ignoreObstaclePathDist__);
}


// ========================================================================
// `dynamic initializer for 'vai_stuckBlowupTime''
// EA  : 0x8336AB30
// RVA : 0x0136AB30
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_stuckBlowupTime__()
{
  idCVar::idCVar(
    this: &vai_stuckBlowupTime,
    name: "vai_stuckBlowupTime",
    value: "5000",
    flags: 2,
    description: "Millisec to wait before blowing up when stuck.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_stuckBlowupTime__);
}


// ========================================================================
// `dynamic initializer for 'vai_blockedBackupTime''
// EA  : 0x8336AB88
// RVA : 0x0136AB88
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_blockedBackupTime__()
{
  idCVar::idCVar(
    this: &vai_blockedBackupTime,
    name: "vai_blockedBackupTime",
    value: "500",
    flags: 2,
    description: "Millisec to wait before backing up.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_blockedBackupTime__);
}


// ========================================================================
// `dynamic initializer for 'vai_excessiveBackupsTime''
// EA  : 0x8336ABE0
// RVA : 0x0136ABE0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_excessiveBackupsTime__()
{
  idCVar::idCVar(
    this: &vai_excessiveBackupsTime,
    name: "vai_excessiveBackupsTime",
    value: "5000",
    flags: 2,
    description: "Millisec since we previously backed up (to be considered excessive).",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_excessiveBackupsTime__);
}


// ========================================================================
// `dynamic initializer for 'vai_excessiveBackupsCount''
// EA  : 0x8336AC38
// RVA : 0x0136AC38
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_excessiveBackupsCount__()
{
  idCVar::idCVar(
    this: &vai_excessiveBackupsCount,
    name: "vai_excessiveBackupsCount",
    value: "5",
    flags: 2,
    description: "Number of times AI performs excessive backup, before it explodes.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_excessiveBackupsCount__);
}


// ========================================================================
// `dynamic initializer for 'vai_showImmediateGoal''
// EA  : 0x8336AC90
// RVA : 0x0136AC90
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_showImmediateGoal__()
{
  idCVar::idCVar(
    this: &vai_showImmediateGoal,
    name: "vai_showImmediateGoal",
    value: "0",
    flags: 1,
    description: "Show immediate goal position",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_showImmediateGoal__);
}


// ========================================================================
// `dynamic initializer for 'vai_immediateGoalScanScale''
// EA  : 0x8336ACE8
// RVA : 0x0136ACE8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_immediateGoalScanScale__()
{
  idCVar::idCVar(
    this: &vai_immediateGoalScanScale,
    name: "vai_immediateGoalScanScale",
    value: "4",
    flags: 4,
    description: "this scalar * splineWidth -- how far ahead to scan for immediate goal",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_immediateGoalScanScale__);
}


// ========================================================================
// `dynamic initializer for 'vai_enable''
// EA  : 0x8336AD40
// RVA : 0x0136AD40
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_enable__()
{
  idCVar::idCVar(
    this: &vai_enable,
    name: "vai_enable",
    value: "1",
    flags: 4,
    description: "Enable vehicle AI",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_enable__);
}


// ========================================================================
// `dynamic initializer for 'vai_nofire''
// EA  : 0x8336AD98
// RVA : 0x0136AD98
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_nofire__()
{
  idCVar::idCVar(
    this: &vai_nofire,
    name: "vai_nofire",
    value: "0",
    flags: 1,
    description: "Makes AI not fire weapons",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_nofire__);
}


// ========================================================================
// `dynamic initializer for 'vai_avoidObstacles''
// EA  : 0x8336ADF0
// RVA : 0x0136ADF0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_avoidObstacles__()
{
  idCVar::idCVar(
    this: &vai_avoidObstacles,
    name: "vai_avoidObstacles",
    value: "1",
    flags: 1,
    description: "Obstacle avoidance",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_avoidObstacles__);
}


// ========================================================================
// `dynamic initializer for 'vai_instantRespawn''
// EA  : 0x8336AE48
// RVA : 0x0136AE48
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_instantRespawn__()
{
  idCVar::idCVar(
    this: &vai_instantRespawn,
    name: "vai_instantRespawn",
    value: "0",
    flags: 1,
    description: "No respawn delay",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_instantRespawn__);
}


// ========================================================================
// `dynamic initializer for 'vai_turnScale''
// EA  : 0x8336AEA0
// RVA : 0x0136AEA0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_turnScale__()
{
  idCVar::idCVar(
    this: &vai_turnScale,
    name: "vai_turnScale",
    value: "1",
    flags: 4,
    description: "Steering is scaled by this amount",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_turnScale__);
}


// ========================================================================
// `dynamic initializer for 'vai_traversalStepSize''
// EA  : 0x8336AEF8
// RVA : 0x0136AEF8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_traversalStepSize__()
{
  idCVar::idCVar(
    this: &vai_traversalStepSize,
    name: "vai_traversalStepSize",
    value: "-1",
    flags: 4,
    description: "Distance towards final goal to search for immediate goal",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_traversalStepSize__);
}


// ========================================================================
// `dynamic initializer for 'vai_maxCurveSpeed''
// EA  : 0x8336AF50
// RVA : 0x0136AF50
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_maxCurveSpeed__()
{
  idCVar::idCVar(
    this: &vai_maxCurveSpeed,
    name: "vai_maxCurveSpeed",
    value: "0",
    flags: 4,
    description: "Max speed for driving around tight curves",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_maxCurveSpeed__);
}


// ========================================================================
// `dynamic initializer for 'vai_maxCurveAngle''
// EA  : 0x8336AFA8
// RVA : 0x0136AFA8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_maxCurveAngle__()
{
  idCVar::idCVar(
    this: &vai_maxCurveAngle,
    name: "vai_maxCurveAngle",
    value: "0",
    flags: 4,
    description: "Angle that defines a tight curve",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_maxCurveAngle__);
}


// ========================================================================
// `dynamic initializer for 'vai_fwdObsScale''
// EA  : 0x8336B000
// RVA : 0x0136B000
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_fwdObsScale__()
{
  idCVar::idCVar(
    this: &vai_fwdObsScale,
    name: "vai_fwdObsScale",
    value: ".45",
    flags: 4,
    description: "Fwd Obs Scale",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_fwdObsScale__);
}


// ========================================================================
// `dynamic initializer for 'vai_rtObsScale''
// EA  : 0x8336B058
// RVA : 0x0136B058
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_rtObsScale__()
{
  idCVar::idCVar(
    this: &vai_rtObsScale,
    name: "vai_rtObsScale",
    value: ".65",
    flags: 4,
    description: "Rt Obs Scale",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_rtObsScale__);
}


// ========================================================================
// `dynamic initializer for 'vai_latMult''
// EA  : 0x8336B0B0
// RVA : 0x0136B0B0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_latMult__()
{
  idCVar::idCVar(
    this: &vai_latMult,
    name: "vai_latMult",
    value: ".52",
    flags: 4,
    description: "Latitudinal multiplier.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_latMult__);
}


// ========================================================================
// `dynamic initializer for 'vai_longMult''
// EA  : 0x8336B108
// RVA : 0x0136B108
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_longMult__()
{
  idCVar::idCVar(
    this: &vai_longMult,
    name: "vai_longMult",
    value: "1.2",
    flags: 4,
    description: "Longitudinal multiplier.",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_longMult__);
}


// ========================================================================
// `dynamic initializer for 'vai_multAngle''
// EA  : 0x8336B160
// RVA : 0x0136B160
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_multAngle__()
{
  idCVar::idCVar(
    this: &vai_multAngle,
    name: "vai_multAngle",
    value: "90",
    flags: 4,
    description: "Mult Angle .. testing",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_multAngle__);
}


// ========================================================================
// `dynamic initializer for 'vai_minFireTimeSecs''
// EA  : 0x8336B1B8
// RVA : 0x0136B1B8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_minFireTimeSecs__()
{
  idCVar::idCVar(
    this: &vai_minFireTimeSecs,
    name: "vai_minFireTimeSecs",
    value: "-1",
    flags: 4,
    description: "Min time to fire weapon",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_minFireTimeSecs__);
}


// ========================================================================
// `dynamic initializer for 'vai_maxFireTimeSecs''
// EA  : 0x8336B210
// RVA : 0x0136B210
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_maxFireTimeSecs__()
{
  idCVar::idCVar(
    this: &vai_maxFireTimeSecs,
    name: "vai_maxFireTimeSecs",
    value: "-1",
    flags: 4,
    description: "Max time to fire weapon",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_maxFireTimeSecs__);
}


// ========================================================================
// `dynamic initializer for 'vai_minFireDelayTimeSecs''
// EA  : 0x8336B268
// RVA : 0x0136B268
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_minFireDelayTimeSecs__()
{
  idCVar::idCVar(
    this: &vai_minFireDelayTimeSecs,
    name: "vai_minFireDelayTimeSecs",
    value: "-1",
    flags: 4,
    description: "Min time to delay between firing weapon",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_minFireDelayTimeSecs__);
}


// ========================================================================
// `dynamic initializer for 'vai_maxFireDelayTimeSecs''
// EA  : 0x8336B2C0
// RVA : 0x0136B2C0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_maxFireDelayTimeSecs__()
{
  idCVar::idCVar(
    this: &vai_maxFireDelayTimeSecs,
    name: "vai_maxFireDelayTimeSecs",
    value: "-1",
    flags: 4,
    description: "Max time to delay between firing weapon",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_maxFireDelayTimeSecs__);
}


// ========================================================================
// `dynamic initializer for 'vai_noMovement''
// EA  : 0x8336B318
// RVA : 0x0136B318
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_noMovement__()
{
  idCVar::idCVar(
    this: &vai_noMovement,
    name: "vai_noMovement",
    value: "0",
    flags: 4,
    description: "make ai not move (0 speed, apply brakes)",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_noMovement__);
}


// ========================================================================
// `dynamic initializer for 'vai_noExplodeWhenStuck''
// EA  : 0x8336B370
// RVA : 0x0136B370
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_noExplodeWhenStuck__()
{
  idCVar::idCVar(
    this: &vai_noExplodeWhenStuck,
    name: "vai_noExplodeWhenStuck",
    value: "0",
    flags: 4,
    description: "ai explode when stuck",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_noExplodeWhenStuck__);
}


// ========================================================================
// `dynamic initializer for 'vai_saveobj''
// EA  : 0x8336B3C8
// RVA : 0x0136B3C8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_saveobj__()
{
  idCVar::idCVar(
    this: &vai_saveobj,
    name: "vai_savepath",
    value: "0",
    flags: 2,
    description: "saves active vehicle ai to .obj file.  value = sample rate in MS\nex: vai_savepath 500 saves every 500ms",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_saveobj__);
}


// ========================================================================
// `dynamic initializer for 'vai_boost''
// EA  : 0x8336B420
// RVA : 0x0136B420
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_boost__()
{
  idCVar::idCVar(
    this: &vai_boost,
    name: "vai_boost",
    value: "0",
    flags: 2,
    description: "All active ai will use boost for number of MS entered. ex: 'vai_boost 2000' boosts for 2 sec",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_boost__);
}


// ========================================================================
// `dynamic initializer for 'vai_boostPower''
// EA  : 0x8336B478
// RVA : 0x0136B478
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_boostPower__()
{
  idCVar::idCVar(
    this: &vai_boostPower,
    name: "vai_boostPower",
    value: "1000000",
    flags: 4,
    description: "Vehicle AI .. boost power",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_boostPower__);
}


// ========================================================================
// `dynamic initializer for 'vai_stopControllingVehicle''
// EA  : 0x8336B4D0
// RVA : 0x0136B4D0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_stopControllingVehicle__()
{
  idCVar::idCVar(
    this: &vai_stopControllingVehicle,
    name: "vai_stopControllingVehicle",
    value: "0",
    flags: 2,
    description: "for testing StopControllingVehicle event",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_stopControllingVehicle__);
}


// ========================================================================
// `dynamic initializer for 'vai_difficulty_mode''
// EA  : 0x8336B528
// RVA : 0x0136B528
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_difficulty_mode__()
{
  idCVar::idCVar(
    this: &vai_difficulty_mode,
    name: "vai_difficulty_mode",
    value: "0",
    flags: 2,
    description: "1: low, 2: med, 3: high",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_difficulty_mode__);
}


// ========================================================================
// `dynamic initializer for 'vai_difficulty_attackScale''
// EA  : 0x8336B580
// RVA : 0x0136B580
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_difficulty_attackScale__()
{
  idCVar::idCVar(
    this: &vai_difficulty_attackScale,
    name: "vai_difficulty_attackScale",
    value: "-1",
    flags: 4,
    description: "0.0: no attacks, 1.0: constant attacks",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_difficulty_attackScale__);
}


// ========================================================================
// `dynamic initializer for 'vai_difficulty_damageScale''
// EA  : 0x8336B5D8
// RVA : 0x0136B5D8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_difficulty_damageScale__()
{
  idCVar::idCVar(
    this: &vai_difficulty_damageScale,
    name: "vai_difficulty_damageScale",
    value: "-1",
    flags: 4,
    description: "0.0: no damage, 1.0: full damage",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_difficulty_damageScale__);
}


// ========================================================================
// `dynamic initializer for 'vai_difficulty_speedRate''
// EA  : 0x8336B630
// RVA : 0x0136B630
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_difficulty_speedRate__()
{
  idCVar::idCVar(
    this: &vai_difficulty_speedRate,
    name: "vai_difficulty_speedRate",
    value: "-1",
    flags: 4,
    description: "0.0: no speed, 1.0: top speed",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_difficulty_speedRate__);
}


// ========================================================================
// `dynamic initializer for 'vai_difficulty_accuracy''
// EA  : 0x8336B688
// RVA : 0x0136B688
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_difficulty_accuracy__()
{
  idCVar::idCVar(
    this: &vai_difficulty_accuracy,
    name: "vai_difficulty_accuracy",
    value: "-1",
    flags: 4,
    description: "0.0: no accuracy, 1.0: perfect accuracy",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_difficulty_accuracy__);
}


// ========================================================================
// `dynamic initializer for 'vai_difficulty_damageTakenScale''
// EA  : 0x8336B6E0
// RVA : 0x0136B6E0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_difficulty_damageTakenScale__()
{
  idCVar::idCVar(
    this: &vai_difficulty_damageTakenScale,
    name: "vai_difficulty_damageTakenScale",
    value: "-1",
    flags: 4,
    description: "0.0: no damage, 1.0: full damage",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_difficulty_damageTakenScale__);
}


// ========================================================================
// `dynamic initializer for 'splineBoundsList''
// EA  : 0x8336B738
// RVA : 0x0136B738
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__splineBoundsList__()
{
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__splineBoundsList__);
}


// ========================================================================
// `dynamic initializer for 'vai_wf_scale''
// EA  : 0x8336B748
// RVA : 0x0136B748
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_wf_scale__()
{
  idCVar::idCVar(
    this: &vai_wf_scale,
    name: "vai_wf_scale",
    value: "0.0",
    flags: 4,
    description: "Wheel force scale",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_wf_scale__);
}


// ========================================================================
// `dynamic initializer for 'vai_brakeForce''
// EA  : 0x8336B7A0
// RVA : 0x0136B7A0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_brakeForce__()
{
  idCVar::idCVar(
    this: &vai_brakeForce,
    name: "vai_brakeForce",
    value: "0",
    flags: 4,
    description: "Force used when AI is braking",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_brakeForce__);
}


// ========================================================================
// `dynamic initializer for 'vai_handBrakeForce''
// EA  : 0x8336B7F8
// RVA : 0x0136B7F8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vehiclecontrol.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_handBrakeForce__()
{
  idCVar::idCVar(
    this: &vai_handBrakeForce,
    name: "vai_handBrakeForce",
    value: "0",
    flags: 4,
    description: "Force used when AI is hand braking",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_handBrakeForce__);
}

