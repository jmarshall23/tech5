
// ========================================================================
// ?InternalExitState@idVS_as_RAM@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B20B20
// RVA : 0x00B20B20
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_RAM::InternalExitState(idVS_as_RAM *this, idFiniteStateMachine *baseFSM, const int curTime)
{
  idStr::operator=(this: &this->debugInfo, text: &byte_8200D768);
  idVehicleAI::SetCollideAttack(this: this->ai, bl: false);
  idVehicleAI::StopFiringWeapon(this: this->ai);
  idVehicleAI::PopControlParams(this: this->ai);
}


// ========================================================================
// ?InternalExitState@idVS_as_ChaseSideShoot@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B20B78
// RVA : 0x00B20B78
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_ChaseSideShoot::InternalExitState(
        idVS_as_RangeShoot *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  idVehicleAI::SetCollideAttack(this: this->ai, bl: false);
  idVehicleAI::StopFiringWeapon(this: this->ai);
  idVehicleAI::PopControlParams(this: this->ai);
}


// ========================================================================
// ?InternalEnterState@idVS_as_ChaseSideBump@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B20BC0
// RVA : 0x00B20BC0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_ChaseSideBump::InternalEnterState(
        idVS_as_ChaseSideBump *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  idVehicleAI *ai; // r3

  idVehicleAI::PushControlParams(this: this->ai);
  ai = this->ai;
  this->bumpDelay = 0;
  this->lastAttemptTime = 0;
  this->bumpRange = 250.0;
  this->bumpRangeDir = -0.1;
  idVehicleAI::SetCollideAttack(this: ai, bl: true);
  this->ai->debugCount = 0;
}


// ========================================================================
// ?InternalEnterState@idVS_as_ChaseRearBump@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B20C30
// RVA : 0x00B20C30
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_ChaseRearBump::InternalEnterState(
        idVS_as_ChaseRearBump *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  idVehicleAI *ai; // r3

  idVehicleAI::PushControlParams(this: this->ai);
  ai = this->ai;
  this->bumpDelay = 0;
  this->bumpAttemptTime = 0;
  this->lastAttemptTime = 0;
  idVehicleAI::SetCollideAttack(this: ai, bl: true);
}


// ========================================================================
// ?InternalExitState@idVS_as_ChaseRearBump@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B20C80
// RVA : 0x00B20C80
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_ChaseRearBump::InternalExitState(
        idVS_as_ChaseRearBump *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  idVehicleAI::SetCollideAttack(this: this->ai, bl: false);
  idVehicleAI::PopControlParams(this: this->ai);
}


// ========================================================================
// ?ValidAttack@idVS_as_RangeShoot@@UAA_NM@Z
// EA  : 0x82B20CC0
// RVA : 0x00B20CC0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

BOOL __fastcall idVS_as_RangeShoot::ValidAttack(idVS_as_RangeShoot *this, double range)
{
  return (unsigned __int8)XGComparePixelShaders() != 0;
}


// ========================================================================
// ?InternalExitState@idVS_as_PowerTurnShoot@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B20CF0
// RVA : 0x00B20CF0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_PowerTurnShoot::InternalExitState(
        idVS_as_PowerTurnShoot *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  idVehicleAI::StopFiringWeapon(this: this->ai);
  idVehicleAI::PopControlParams(this: this->ai);
}


// ========================================================================
// ?InternalExitState@idVS_as_RunAway@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B20D28
// RVA : 0x00B20D28
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_RunAway::InternalExitState(
        idVS_as_RunAway *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  vehicleAiSetup_t::difficultyLevel_t v4; // [sp+50h] [-30h] BYREF

  idVehicleAI::GetDifficultyData(this: this->ai, difficultyLevel: &v4);
  v4.speedRate = this->speedRate;
  idVehicleAI::SetDifficultyData(this: this->ai, difficultyLevel: &v4);
}


// ========================================================================
// ?InternalEnterState@idVS_as_FireWeapon@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B20D70
// RVA : 0x00B20D70
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_FireWeapon::InternalEnterState(
        idVS_as_FireWeapon *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  idPlayerStart *Enemy; // r3
  int v5; // r31
  idPlayer *Player; // r4

  Enemy = (idPlayerStart *)idVehicleAI::GetEnemy(this: this->ai);
  if ( idPlayerStart::CastTo(c: Enemy) != nullptr )
  {
    v5 = 0;
    while ( 1 )
    {
      Player = idGameLocal::GetPlayer(this: gameLocal, i: v5);
      if ( Player != nullptr )
        break;
      if ( ++v5 >= 6 )
        return;
    }
    idVehicleAI::SetEnemy(this: this->ai, enemy: Player);
  }
}


// ========================================================================
// ?InternalExitState@idVS_as_FireWeapon@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B20DD8
// RVA : 0x00B20DD8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_FireWeapon::InternalExitState(
        idVS_as_FireWeapon *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  idVehicleAI::StopFiringWeapon(this: this->ai);
}


// ========================================================================
// ?InternalExitState@idVS_as_HitAndRun@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B20DE0
// RVA : 0x00B20DE0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_HitAndRun::InternalExitState(
        idVS_as_HitAndRun *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  idVehicleAI::SetCollideAttack(this: this->ai, bl: false);
}


// ========================================================================
// ?InternalWork@idVS_ms_MoveToGoal@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B20EB0
// RVA : 0x00B20EB0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_ms_MoveToGoal::InternalWork(
        idVS_ms_MoveToGoal *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  int v4; // r3
  idVehicleAI *ai; // r4
  char v6; // r30
  idVehicleAI *v7; // r11
  double desiredSpeed; // fp0

  this->ai->desiredSteering = idVehicleAI::DetermineSteering(this: this->ai);
  this->ai->desiredSpeed = idVehicleAI::DetermineSpeed(this: this->ai);
  this->ai->desiredWheelForce = idVehicleAI::DetermineWheelForce(this: this->ai);
  this->ai->desiredBraking = idVehicleAI::DetermineBraking(this: this->ai);
  v4 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  ai = this->ai;
  if ( v4 > ai->lastBackupTime + 2000 )
  {
    v6 = 0;
    if ( (unsigned __int8)idVehicleAI::CheckForBlocked(this: this->ai, dSpeed: ai->desiredSpeed) == 0 )
    {
      v7 = this->ai;
      desiredSpeed = v7->desiredSpeed;
      if ( desiredSpeed >= 45.0 )
        goto LABEL_13;
      if ( v7->drivingBackwards )
      {
        if ( desiredSpeed >= 0.0 || v7->actualSpeed <= -1.0 || __fabs(v7->immediateGoalAngle) >= 90.0 )
          goto LABEL_13;
      }
      else if ( desiredSpeed <= 0.0 || v7->actualSpeed >= 1.0 || __fabs(v7->immediateGoalAngle) <= 90.0 )
      {
        goto LABEL_13;
      }
    }
    v6 = 1;
LABEL_13:
    if ( v6 != 0 )
      idVehicleBaseFSM::PushState(this: &this->ai->movementFSM, stateType: &idVS_ms_Backup::Type, delayTime: 0);
  }
}


// ========================================================================
// ?InternalWork@idVS_ms_MoveToGoalOnSpline@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B21030
// RVA : 0x00B21030
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_ms_MoveToGoalOnSpline::InternalWork(
        idVS_ms_MoveToGoalOnSpline *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  char v4; // r30
  int v5; // r3
  idVehicleAI *ai; // r8
  idVehicleAI *v7; // r11
  double desiredSpeed; // fp0

  idVehicleAI::DetermineImmediateGoal(this: this->ai);
  this->ai->desiredSteering = idVehicleAI::DetermineSteering(this: this->ai);
  this->ai->desiredSpeed = idVehicleAI::DetermineSpeed(this: this->ai);
  this->ai->desiredWheelForce = idVehicleAI::DetermineWheelForce(this: this->ai);
  this->ai->desiredBraking = idVehicleAI::DetermineBraking(this: this->ai);
  if ( this->ai->control.avoidanceType == OAT_GENERAL )
    idVehicleAI::AvoidSplineObstacles(this: this->ai);
  v4 = 0;
  v5 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  ai = this->ai;
  if ( v5 > ai->lastBackupTime + 2000 )
  {
    if ( (unsigned __int8)idVehicleAI::CheckForBlocked(this: this->ai, dSpeed: ai->desiredSpeed) != 0 )
      goto LABEL_13;
    v7 = this->ai;
    desiredSpeed = v7->desiredSpeed;
    if ( desiredSpeed < 45.0 )
    {
      if ( v7->drivingBackwards )
      {
        if ( desiredSpeed >= 0.0 || v7->actualSpeed <= -1.0 )
          goto LABEL_14;
      }
      else if ( desiredSpeed <= 0.0 || v7->actualSpeed >= 1.0 )
      {
        goto LABEL_14;
      }
      if ( __fabs(v7->immediateGoalAngle) > 90.0 )
LABEL_13:
        v4 = 1;
    }
LABEL_14:
    if ( v4 != 0 )
      idVehicleBaseFSM::PushState(this: &this->ai->movementFSM, stateType: &idVS_ms_Backup::Type, delayTime: 0);
  }
}


// ========================================================================
// ?InternalExitState@idVS_cs_PowerSlide@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B211B8
// RVA : 0x00B211B8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_cs_PowerSlide::InternalExitState(
        idVS_cs_PowerSlide *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  this->ai->movementFSM.SetState_3(
    this: &this->ai->movementFSM,
    a2: &idVS_ms_MoveToGoalOnSpline::Type,
    a3: 0,
    a4: false);
}


// ========================================================================
// ?InternalWork@idVS_ds_FollowPlayerInFront@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B211E0
// RVA : 0x00B211E0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_ds_FollowPlayerInFront::InternalWork(
        idVS_ds_FollowPlayerInFront *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  idVehicle *Enemy; // r3
  idNavPathPosTracker *EnemyTracker; // r3
  double v6; // fp12
  float distance; // [sp+50h] [-30h]
  idVehicleAI *v8; // [sp+50h] [-30h]
  idNavSplinePosition *rightDistance_low; // [sp+54h] [-2Ch]

  Enemy = idVehicleAI::FindEnemy(this: this->ai);
  idVehicleAI::SetEnemy(this: this->ai, enemy: Enemy);
  EnemyTracker = idVehicleAI::GetEnemyTracker(this: this->ai);
  distance = EnemyTracker->pathPosition.distance;
  rightDistance_low = (idNavSplinePosition *)LODWORD(EnemyTracker->pathPosition.rightDistance);
  if ( idNavPathPosTracker::GetFacing(this: EnemyTracker) <= 0.0 )
    v6 = (float)(distance - (float)2000.0);
  else
    v6 = (float)(distance + (float)2000.0);
  *(float *)&v8 = v6;
  idVehicleAI::MoveToPosition(
    this: v8,
    pathPos: rightDistance_low,
    isStoppingGoal: false,
    passThroughGoal: 1u,
    a5: false);
  idVehicleAI::SetSpeedLimit(this: this->ai, speed: 45.0);
}


// ========================================================================
// ?InternalEnterState@idVS_ds_Patrol@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B212A0
// RVA : 0x00B212A0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_ds_Patrol::InternalEnterState(
        idVS_ds_Patrol *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  this->ai->movementFSM.SetState_3(
    this: &this->ai->movementFSM,
    a2: &idVS_ms_MoveToGoalOnSpline::Type,
    a3: 0,
    a4: false);
  idVehicleAI::InitDecisionStatePatrol(this: this->ai);
  this->startPos = idVehicleAI::GetSplineTracker(this: this->ai)->pathPosition;
}


// ========================================================================
// ?InternalEnterState@idVS_ds_Barricade@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B21318
// RVA : 0x00B21318
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_ds_Barricade::InternalEnterState(
        idVS_ds_Barricade *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  idVehicle *Enemy; // r3

  idVehicleAI::PushControlParams(this: this->ai);
  this->ai->movementFSM.SetState_3(
    this: &this->ai->movementFSM,
    a2: &idVS_ms_MoveToGoalOnSpline::Type,
    a3: 0,
    a4: false);
  Enemy = idVehicleAI::FindEnemy(this: this->ai);
  idVehicleAI::SetEnemy(this: this->ai, enemy: Enemy);
}


// ========================================================================
// ?InternalExitState@idVS_ds_Barricade@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B21388
// RVA : 0x00B21388
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_ds_Barricade::InternalExitState(
        idVS_ds_Barricade *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  if ( idVehicleAI::GetSplineTracker(this: this->ai) != nullptr )
    idVehicleAI::GetSplineTracker(this: this->ai)->useVelocityToGetClosestSpline = true;
  idVehicleAI::PopControlParams(this: this->ai);
}


// ========================================================================
// ?InternalWork@idVS_as_FreeForm@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B213D8
// RVA : 0x00B213D8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_FreeForm::InternalWork(
        idVS_as_FreeForm *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  idNavPathPosTracker *EnemyTracker; // r3
  idNavPathPosTracker *v5; // r31
  idVehicle_Car *Owner; // r3
  idVehicle_Car *v7; // r3

  EnemyTracker = idVehicleAI::GetEnemyTracker(this: this->ai);
  v5 = EnemyTracker;
  if ( EnemyTracker != nullptr )
  {
    idVehicleAI::MoveToPosition(
      this: (idVehicleAI *)LODWORD(EnemyTracker->pathPosition.distance),
      pathPos: (idNavSplinePosition *)LODWORD(EnemyTracker->pathPosition.rightDistance),
      isStoppingGoal: __ROL4__(EnemyTracker->pathPosition.navSpline, 32),
      passThroughGoal: 1u,
      a5: false);
    Owner = (idVehicle_Car *)idNavPathPosTracker::GetOwner(this: v5);
    v7 = idVehicle_Car::CastTo(c: Owner);
    if ( v7 != nullptr )
      idVehicle_Car::SetMaxSpeed(this: v7, speed: vai_test_speedLimit.valueFloat);
    idVehicleAI::SetSpeedLimit(this: this->ai, speed: vai_test_speedLimit.valueFloat);
  }
}


// ========================================================================
// ?ValidAttack@idVS_as_RAM@@UAA_NM@Z
// EA  : 0x82B21468
// RVA : 0x00B21468
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

int __fastcall idVS_as_RAM::ValidAttack(
        idVS_as_RAM *this,
        double range,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int a37,
        int a38,
        int a39,
        int a40,
        int a41,
        int a42,
        float a43,
        float a44,
        idNavSpline *a45,
        int a46,
        float a47,
        float a48,
        float a49,
        float a50,
        float a51,
        float a52,
        int a53,
        int a54,
        float r,
        float g,
        float b,
        float a,
        float a59,
        float a60,
        float a61,
        float a62,
        float a63,
        float a64)
{
  float a65; // [sp+81E8h] [+C8h]
  float a66; // [sp+81ECh] [+CCh]
  __int128 a67; // [sp+81F0h] [+D0h] BYREF
  idClipModel *a68; // [sp+8200h] [+E0h] BYREF
  double v68; // fp1
  int v69; // r3
  int v70; // r30
  double v71; // fp31
  idNavPathPosTracker *EnemyTracker; // r3
  double rightDistance; // fp30
  idNavPathPosTracker *SplineTracker; // r3
  idNavPathPosTracker *v75; // r3
  idVehicleAI *v76; // r3
  float distance; // r10
  float v78; // r9
  idNavSpline *navSpline; // r8
  idNavPathPosTracker *v80; // r3
  idVec3 *WorldPos; // r3
  bool v82; // r11
  idNavPathPosTracker *v83; // r3
  const char *ClipModelsTouchingBounds; // r3
  int v85; // r11
  idClipModel **i; // r10
  idEntity *Enemy; // r3
  idPhysics *Physics; // r3
  float *v90; // r3
  double v91; // fp9
  double v92; // fp7
  double v93; // fp8
  __int64 v94; // [sp+8180h] [+60h]
  __int64 v95; // [sp+8180h] [+60h]
  float x; // [sp+8180h] [+60h]
  float y; // [sp+8184h] [+64h]
  float z; // [sp+8188h] [+68h]
  float v99; // [sp+8188h] [+68h]

  v68 = ((double (*)(void))RtlCheckStack12)();
  v70 = v69;
  v71 = v68;
  if ( (unsigned __int8)XGComparePixelShaders() != 0 )
  {
    EnemyTracker = idVehicleAI::GetEnemyTracker(this: *(idVehicleAI **)(v70 + 96));
    rightDistance = EnemyTracker->pathPosition.rightDistance;
    if ( rightDistance < idNavPathPosTracker::GetSplineWidth(this: EnemyTracker) )
    {
      v94 = *(_QWORD *)&idVehicleAI::GetEnemyTracker(this: *(idVehicleAI **)(v70 + 96))->pathPosition.distance;
      SplineTracker = idVehicleAI::GetSplineTracker(this: *(idVehicleAI **)(v70 + 96));
      if ( idNavSplinePathMgr::GetPathDistance(
             this: (idNavSplinePathMgr *)(LODWORD(SplineTracker->pathPosition.distance) - 11336),
             start: (idNavSplinePosition *)LODWORD(SplineTracker->pathPosition.rightDistance),
             end: (idNavSplinePosition *)__ROL4__(SplineTracker->pathPosition.navSpline, 32),
             forward: (idVec3 *)v94,
             includeRightDistance: SLOBYTE(vec3_origin.x)) <= v71 )
      {
        v75 = idVehicleAI::GetEnemyTracker(this: *(idVehicleAI **)(v70 + 96));
        distance = v75->pathPosition.distance;
        v78 = v75->pathPosition.rightDistance;
        navSpline = v75->pathPosition.navSpline;
        v76 = *(idVehicleAI **)(v70 + 96);
        a43 = distance;
        a44 = v78;
        a45 = navSpline;
        v80 = idVehicleAI::GetEnemyTracker(this: v76);
        v95 = *(_QWORD *)&v80->worldPosition.x;
        z = v80->worldPosition.z;
        WorldPos = idNavSplinePosition::GetWorldPos(this: (idNavSplinePosition *)&a67, result: (idVec3 *)&a43);
        v82 = false;
        if ( __fabs((float)(*(float *)&v95 - WorldPos->x)) <= 100.0
          && __fabs((float)(*((float *)&v95 + 1) - WorldPos->y)) <= 100.0 )
        {
          v82 = __fabs((float)(z - WorldPos->z)) <= 100.0;
        }
        if ( v82 )
        {
          v83 = idVehicleAI::GetEnemyTracker(this: *(idVehicleAI **)(v70 + 96));
          y = v83->worldPosition.y;
          v99 = v83->worldPosition.z;
          x = v83->worldPosition.x;
          a47 = x - (float)150.0;
          a48 = y - (float)150.0;
          a49 = v99;
          a50 = x + (float)150.0;
          a51 = y + (float)150.0;
          a52 = v99;
          if ( vai_debug_attackstate_draw.valueInteger != 0 )
          {
            r = idColor::colorYellow.r;
            a = idColor::colorYellow.a;
            g = idColor::colorYellow.g;
            b = idColor::colorYellow.b;
            clientGame->renderWorld->DebugBounds(
              this: clientGame->renderWorld,
              a2: (const idVec4 *)&r,
              a3: (const idBounds *)&a47,
              a4: &vec3_origin,
              a5: 0,
              a6: false);
          }
          ClipModelsTouchingBounds = idClip::GetClipModelsTouchingBounds(
                                       this: &clientGame->clip,
                                       bounds: (const idBounds *)&a47,
                                       clipMask: 0x20000,
                                       clipModelList: &a68,
                                       maxCount: (const char *)0x2000);
          v85 = 0;
          if ( (int)ClipModelsTouchingBounds <= 0 )
            return 1;
          for ( i = &a68; (*i)->contents != 0x20000; ++i )
          {
            if ( ++v85 >= (int)ClipModelsTouchingBounds )
              return 1;
          }
          if ( vai_debug_attackstate_draw.valueInteger != 0 )
          {
            Enemy = idVehicleAI::GetEnemy(this: *(idVehicleAI **)(v70 + 96));
            Physics = idEntity::GetPhysics(this: Enemy);
            v90 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
            v91 = *v90;
            v92 = v90[1];
            v93 = (float)(v90[2] + (float)50.0);
            a62 = 250.0;
            a63 = idColor::colorBrown.r;
            a64 = idColor::colorBrown.g;
            a65 = idColor::colorBrown.b;
            a66 = idColor::colorBrown.a;
            a59 = v91;
            a60 = v92;
            a61 = v93;
            clientGame->renderWorld->DebugSphere(
              this: clientGame->renderWorld,
              a2: (const idVec4 *)&a63,
              a3: (const idSphere *)&a59,
              a4: 24,
              a5: 0,
              a6: true);
          }
        }
      }
    }
  }
  return 0;
}


// ========================================================================
// ?InternalEnterState@idVS_as_ChaseShoot@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B217F0
// RVA : 0x00B217F0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_ChaseShoot::InternalEnterState(
        idVS_as_ChaseShoot *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  unsigned int v4; // r9
  idVehicleAI *ai; // r3
  int v6; // r6

  idVehicleAI::PushControlParams(this: this->ai);
  v4 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v4;
  v6 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + ((v4 >> 10) & 0x7FFF) % 0x5DC + 1000;
  ai = this->ai;
  this->delayTime = 0;
  this->shootTime = v6;
  this->goalDistOfs = 100.0;
  idVehicleAI::SetCollideAttack(this: ai, bl: true);
}


// ========================================================================
// ?InternalEnterState@idVS_as_ChaseSideShoot@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B218C0
// RVA : 0x00B218C0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_ChaseSideShoot::InternalEnterState(
        idVS_as_ChaseSideShoot *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  unsigned int v4; // r9
  unsigned int v5; // r11
  idVehicleAI *ai; // r3

  idVehicleAI::PushControlParams(this: this->ai);
  v4 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v4;
  v5 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + ((v4 >> 10) & 0x7FFF) % 0x5DC;
  ai = this->ai;
  this->delayTime = 0;
  this->shootTime = v5 + 1000;
  this->goalDistOfs = 100.0;
  this->goalOfsDir = 1.0;
  idVehicleAI::SetCollideAttack(this: ai, bl: true);
  this->ai->debugCount = 0;
}


// ========================================================================
// ?InternalWork@idVS_as_ChaseSideShoot@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B219A0
// RVA : 0x00B219A0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_ChaseSideShoot::InternalWork(
        idVS_as_ChaseSideShoot *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  double v4; // fp31
  idNavPathPosTracker *EnemyTracker; // r3
  double RightDistance; // fp1
  idVehicleAI *ai; // r3
  double v8; // fp1
  double v9; // fp13
  double v10; // fp0
  double v11; // fp0
  double goalDistOfs; // fp0
  double v13; // fp13
  idVehicleAI *v14; // r3
  idNavPathPosTracker *v15; // r3
  idNavPathPosTracker *v16; // r30
  idNavPathPosTracker *SplineTracker; // r3
  idNavPathPosTracker *v18; // r3
  idEntity *Owner; // r3
  idPhysics *Physics; // r3
  int v21; // r3
  idNavPathPosTracker *v22; // r3
  double CurrentSpeedInMPH; // fp31
  idVehicleAI *v24; // r3
  double distanceToFinalGoal; // fp0
  int v26; // r8
  int v27; // r7
  int v28; // r6
  long double v29; // fp2
  __int64 v30; // r10
  idEntity *Enemy; // r3
  idVehicleAI *v32; // r3
  unsigned int v33; // r3
  unsigned int v34; // r30
  int v35; // r3
  unsigned int v36; // r10
  float distance; // [sp+50h] [-A0h]
  float v38; // [sp+50h] [-A0h]
  float v39; // [sp+50h] [-A0h]
  float v40; // [sp+54h] [-9Ch]
  idNavSpline *navSpline; // [sp+58h] [-98h]
  char v42; // [sp+60h] [-90h] BYREF
  vaiControl_t v43; // [sp+70h] [-80h] BYREF

  if ( idVehicleAI::GetEnemyTracker(this: this->ai) != nullptr )
  {
    ++this->ai->debugCount;
    v4 = idVehicleAI::NormalizeEnemyRightDistance(this: this->ai);
    EnemyTracker = idVehicleAI::GetEnemyTracker(this: this->ai);
    distance = EnemyTracker->pathPosition.distance;
    navSpline = EnemyTracker->pathPosition.navSpline;
    RightDistance = idVehicleAI::GetRightDistance(this: this->ai);
    ai = this->ai;
    v40 = RightDistance;
    if ( ai->distanceToFinalGoal < 1000.0 )
    {
      v8 = idVehicleAI::GetRightDistance(this: ai);
      v9 = __fabs((float)((float)v4 - (float)v8));
      if ( v9 > 400.0 )
      {
        if ( v4 <= v8 )
          v10 = (float)((float)v4 + (float)400.0);
        else
          v10 = (float)((float)v4 - (float)400.0);
        v40 = v10;
      }
      if ( v9 < 300.0 )
      {
        if ( v4 <= v8 )
          v11 = (float)((float)v4 + (float)300.0);
        else
          v11 = (float)((float)v4 - (float)300.0);
        v40 = v11;
      }
    }
    goalDistOfs = this->goalDistOfs;
    v13 = 250.0;
    if ( goalDistOfs >= 250.0 || (v13 = 150.0, goalDistOfs <= 150.0) )
    {
      this->goalOfsDir = -this->goalOfsDir;
      this->goalDistOfs = v13;
    }
    v14 = this->ai;
    this->goalDistOfs = this->goalOfsDir + this->goalDistOfs;
    v15 = idVehicleAI::GetEnemyTracker(this: v14);
    v38 = distance + (float)(idNavPathPosTracker::GetFacing(this: v15) * this->goalDistOfs);
    v16 = idVehicleAI::GetEnemyTracker(this: this->ai);
    SplineTracker = idVehicleAI::GetSplineTracker(this: this->ai);
    v39 = v38 + idNavPathPosTracker::GetMoveAheadDist(this: SplineTracker, otherTracker: v16);
    v18 = idVehicleAI::GetEnemyTracker(this: this->ai);
    Owner = idNavPathPosTracker::GetOwner(this: v18);
    Physics = idEntity::GetPhysics(this: Owner);
    v21 = (int)Physics->GetLinearVelocity(this: (idPhysics *)&v42, result: (idVec3 *)Physics, a3: 0);
    idNavSplinePosition::Validate(this: *(idNavSplinePosition **)v21, velocity: *(idVec3 **)(v21 + 4));
    idVehicleAI::MoveToPosition(
      this: (idVehicleAI *)LODWORD(v39),
      pathPos: (idNavSplinePosition *)LODWORD(v40),
      isStoppingGoal: __ROL4__(navSpline, 32),
      passThroughGoal: 1u,
      a5: false);
    v22 = idVehicleAI::GetEnemyTracker(this: this->ai);
    CurrentSpeedInMPH = idNavPathPosTracker::GetCurrentSpeedInMPH(this: v22);
    if ( CurrentSpeedInMPH < 0.0 )
      CurrentSpeedInMPH = 0.0;
    v24 = this->ai;
    distanceToFinalGoal = v24->distanceToFinalGoal;
    if ( distanceToFinalGoal <= 500.0 )
    {
      if ( distanceToFinalGoal > 100.0 )
        CurrentSpeedInMPH = (float)((float)CurrentSpeedInMPH + (float)10.0);
    }
    else
    {
      CurrentSpeedInMPH = idVehicleAI::GetMaxSpeed(this: v24);
    }
    idVehicleAI::SetSpeedLimit(this: this->ai, speed: CurrentSpeedInMPH);
    HIDWORD(v30) = 0x82000000;
    v43.avoidanceType = OAT_INIT;
    v43.powerTurnTime = -1;
    v43.speedLimit = -1.0;
    v43.maxCurveAngle = -1.0;
    v43.maxStepAngle = -1.0;
    v43.powerTurnSpeed = -1.0;
    v43.stopPowerTurnSpeed = -1.0;
    v43.traversalStepSize = -1.0;
    v43.backupSpeed = -1.0;
    v43.maxCurveCosine = -1.0;
    v43.maxStepCosine = -1.0;
    if ( CurrentSpeedInMPH >= 40.0 )
    {
      v43.maxCurveSpeed = 40.0;
      LODWORD(v30) = &unk_821C0000;
      v43.maxCurveCosine = 0.0;
      v43.moveDistance = 100.0;
      v43.stopDistance = 50.0;
      v43.decelDistance = 200.0;
    }
    else
    {
      v43.stopDistance = 400.0;
      LODWORD(v30) = &unk_821F0000;
      HIDWORD(v30) = &unk_822D0000;
      v43.maxCurveSpeed = 65.0;
      v43.moveDistance = 800.0;
      v43.decelDistance = 2000.0;
    }
    idVehicleAI::UpdateControlParams(
      this: this->ai,
      params: &v43,
      initialize: false,
      a4: v29,
      a5: v28,
      a6: v27,
      a7: v26,
      a8: v30);
    Enemy = idVehicleAI::GetEnemy(this: this->ai);
    idVehicleAI::SetTarget(this: this->ai, entity: Enemy);
    v32 = this->ai;
    if ( v32->distanceToFinalGoal < 1400.0 )
    {
      if ( this->shootTime != 0 )
      {
        if ( this->shootTime <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
          this->shootTime = 0;
        idVehicleAI::FireWeapon(this: this->ai);
        ++this->ai->numAttackAttempts;
      }
      else
      {
        idVehicleAI::StopFiringWeapon(this: v32);
        if ( this->delayTime != 0 )
        {
          if ( this->delayTime < gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
          {
            v33 = 1664525 * clientGame->random.seed + 1013904223;
            clientGame->random.seed = v33;
            v34 = ((v33 >> 10) & 0x7FFF) % 0x5DC;
            v35 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
            this->delayTime = 0;
            this->shootTime = v35 + v34 + 500;
          }
        }
        else
        {
          v36 = 1664525 * clientGame->random.seed + 1013904223;
          clientGame->random.seed = v36;
          this->delayTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED)
                          + ((v36 >> 10) & 0x7FFF) % 0x3E8
                          + 500;
        }
      }
    }
  }
}


// ========================================================================
// ?InternalEnterState@idVS_as_CircleShoot@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B21E60
// RVA : 0x00B21E60
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_CircleShoot::InternalEnterState(
        idVS_as_CircleShoot *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  __int64 v4; // r10
  idVehicleAI *ai; // r3
  int v6; // r7
  int v7; // r6
  long double v8; // fp2
  vaiControl_t v9; // [sp+50h] [-50h] BYREF

  idVehicleAI::PushControlParams(this: this->ai);
  LODWORD(v4) = 0x82000000;
  HIDWORD(v4) = 0x82000000;
  ai = this->ai;
  v9.avoidanceType = OAT_INIT;
  v9.powerTurnTime = -1;
  v9.speedLimit = -1.0;
  v9.maxCurveAngle = -1.0;
  v9.maxStepAngle = -1.0;
  v9.powerTurnSpeed = -1.0;
  v9.stopPowerTurnSpeed = -1.0;
  v9.traversalStepSize = -1.0;
  v9.backupSpeed = -1.0;
  v9.maxCurveCosine = -1.0;
  v9.maxStepCosine = -1.0;
  v9.decelDistance = 0.0;
  v9.stopDistance = 0.0;
  v9.moveDistance = 0.0;
  v9.maxCurveSpeed = 90.0;
  idVehicleAI::UpdateControlParams(
    this: ai,
    params: &v9,
    initialize: false,
    a4: v8,
    a5: v7,
    a6: v6,
    a7: (int)&off_82010000,
    a8: v4);
  this->driveTowardsEnemy = true;
}


// ========================================================================
// ?InternalExitState@idVS_as_CircleShoot@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B21F00
// RVA : 0x00B21F00
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_CircleShoot::InternalExitState(
        idVS_as_CircleShoot *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  this->ai->movementFSM.SetState_3(
    this: &this->ai->movementFSM,
    a2: &idVS_ms_MoveToGoalOnSpline::Type,
    a3: 0,
    a4: false);
  idVehicleAI::StopFiringWeapon(this: this->ai);
  idVehicleAI::PopControlParams(this: this->ai);
}


// ========================================================================
// ?ValidAttack@idVS_as_CircleShoot@@UAA_NM@Z
// EA  : 0x82B21F60
// RVA : 0x00B21F60
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

BOOL __fastcall idVS_as_CircleShoot::ValidAttack(idVS_as_CircleShoot *this, double range)
{
  idNavPathPosTracker *EnemyTracker; // r3
  double rightDistance; // fp31

  if ( (unsigned __int8)XGComparePixelShaders() == 0 )
    return false;
  EnemyTracker = idVehicleAI::GetEnemyTracker(this: this->ai);
  rightDistance = EnemyTracker->pathPosition.rightDistance;
  return rightDistance < idNavPathPosTracker::GetSplineWidth(this: EnemyTracker);
}


// ========================================================================
// ?DetermineNewGoal@idVS_as_RandomFollow@@QAAXXZ
// EA  : 0x82B21FD8
// RVA : 0x00B21FD8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_RandomFollow::DetermineNewGoal(idVS_as_RandomFollow *this)
{
  idNavPathPosTracker *EnemyTracker; // r11
  idVehicleAI *ai; // r3
  idNavSplinePosition *p_goalPos; // r31
  idNavPathPosTracker *v5; // r3
  idEntity *Owner; // r3
  idPhysics *Physics; // r3
  float *v8; // r30
  idVec3 *Forward; // r3
  double v10; // fp6
  unsigned int v11; // r4
  idVehicleAI *v12; // r3
  __int64 v13; // r10
  double v14; // fp8
  __int64 v15; // r7
  unsigned int v16; // r10
  __int64 v17; // [sp+50h] [-60h] BYREF
  idNavSplinePosition v18[2]; // [sp+60h] [-50h] BYREF

  p_goalPos = &this->goalPos;
  EnemyTracker = idVehicleAI::GetEnemyTracker(this: this->ai);
  ai = this->ai;
  this->goalPos = EnemyTracker->pathPosition;
  v5 = idVehicleAI::GetEnemyTracker(this: ai);
  Owner = idNavPathPosTracker::GetOwner(this: v5);
  Physics = idEntity::GetPhysics(this: Owner);
  v8 = (float *)Physics->GetLinearVelocity(this: (idPhysics *)&v17, result: (idVec3 *)Physics, a3: 0);
  Forward = idNavSplinePosition::GetForward(this: v18, result: (idVec3 *)&this->goalPos);
  HIDWORD(v13) = 1013841920;
  v10 = (float)((float)(*v8 * Forward->x) + (float)((float)(v8[2] * Forward->z) + (float)(v8[1] * Forward->y)));
  v11 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v11;
  v12 = this->ai;
  LODWORD(v13) = (v11 >> 10) & 0x7FFF;
  v17 = v13;
  if ( v10 < 0.0 )
    v14 = (float)(p_goalPos->distance
                - (float)(idVehicleAI::GetAttackRange(this: v12) * (float)((float)v13 * (float)0.000030518509)));
  else
    v14 = (float)(p_goalPos->distance
                + (float)(idVehicleAI::GetAttackRange(this: v12) * (float)((float)v13 * (float)0.000030518509)));
  p_goalPos->distance = v14;
  idNavSplinePosition::Validate(
    this: (idNavSplinePosition *)LODWORD(vec3_origin.x),
    velocity: (idVec3 *)LODWORD(vec3_origin.y));
  HIDWORD(v15) = 0x82000000;
  v16 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v16;
  LODWORD(v15) = (v16 >> 10) & 0x7FFF;
  v17 = v15;
  this->goalPos.rightDistance = idNavSplinePosition::GetSplineWidth(this: &this->goalPos, dist: -1.0)
                              * (float)((float)((float)v15 * (float)0.000061037019) - (float)1.0);
}


// ========================================================================
// ?InternalEnterState@idVS_as_PowerTurnShoot@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B22198
// RVA : 0x00B22198
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_PowerTurnShoot::InternalEnterState(
        idVS_as_PowerTurnShoot *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  unsigned int v4; // r9
  unsigned int v5; // r30
  int v6; // r3
  idVehicleAI *ai; // r8

  idVehicleAI::PushControlParams(this: this->ai);
  v4 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v4;
  v5 = ((v4 >> 10) & 0x7FFF) % 0x5DC;
  v6 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  ai = this->ai;
  this->delayTime = 0;
  this->shootTime = v6 + v5 + 1000;
  this->mode = 1;
  ai->debugCount = 0;
}


// ========================================================================
// ?InternalEnterState@idVS_as_RunAway@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B22260
// RVA : 0x00B22260
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_RunAway::InternalEnterState(
        idVS_as_RunAway *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  idNavPathPosTracker *SplineTracker; // r3
  __int64 v5; // r6
  int navSpline; // r10
  int v7; // r9
  bool v8; // r8
  idVehicleAI *ai; // r3
  int v10; // [sp+8h] [-78h]
  __int64 v11; // [sp+10h] [-70h]
  __int64 v12; // [sp+18h] [-68h]
  __int64 v13; // [sp+20h] [-60h]
  __int64 v14; // [sp+28h] [-58h]
  __int64 v15; // [sp+30h] [-50h]
  vehicleAiSetup_t::difficultyLevel_t v16; // [sp+50h] [-30h] BYREF

  SplineTracker = idVehicleAI::GetSplineTracker(this: this->ai);
  LODWORD(v5) = 0;
  navSpline = (int)SplineTracker->pathPosition.navSpline;
  HIDWORD(v5) = __ROL4__(navSpline, 32);
  idVehicleAI::MoveToPathPosition(
    this: (idVehicleAI *)LODWORD(SplineTracker->pathPosition.distance),
    isStoppingGoal: v5,
    passThroughGoal: false,
    a4: v8,
    a5: v7,
    a6: navSpline,
    a7: v10,
    a8: v11,
    a9: v12,
    a10: v13,
    a11: v14,
    a12: v15);
  idVehicleAI::GetDifficultyData(this: this->ai, difficultyLevel: &v16);
  this->speedRate = v16.speedRate;
  ai = this->ai;
  v16.speedRate = 1.0;
  idVehicleAI::SetDifficultyData(this: ai, difficultyLevel: &v16);
}


// ========================================================================
// ?InternalEnterState@idVS_as_ForcedRetreat@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B222E0
// RVA : 0x00B222E0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_ForcedRetreat::InternalEnterState(
        idVS_as_ForcedRetreat *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  idVehicleAI *ai; // r5
  __int64 v5; // r6
  __int64 v6; // r4
  int v7; // r10
  int v8; // r9
  bool v9; // r8
  int v10; // [sp+8h] [-58h]
  __int64 v11; // [sp+10h] [-50h]
  __int64 v12; // [sp+18h] [-48h]
  __int64 v13; // [sp+20h] [-40h]
  __int64 v14; // [sp+28h] [-38h]
  __int64 v15; // [sp+30h] [-30h]

  idVehicleAI::SetSpeedLimit(this: this->ai, speed: 100.0);
  this->ai->movementFSM.SetState_3(
    this: &this->ai->movementFSM,
    a2: &idVS_ms_MoveToGoalOnSpline::Type,
    a3: 0,
    a4: false);
  ai = this->ai;
  LODWORD(v5) = 0;
  v6 = *(_QWORD *)&ai->startingPathPosition.distance;
  HIDWORD(v5) = __ROL4__(ai->startingPathPosition.navSpline, 32);
  idVehicleAI::MoveToPathPosition(
    this: (idVehicleAI *)HIDWORD(v6),
    isStoppingGoal: v5,
    passThroughGoal: false,
    a4: v9,
    a5: v8,
    a6: v7,
    a7: v10,
    a8: v11,
    a9: v12,
    a10: v13,
    a11: v14,
    a12: v15);
}


// ========================================================================
// ?InternalWork@idVS_as_Bypass@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B22360
// RVA : 0x00B22360
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_Bypass::InternalWork(idVS_as_Bypass *this, idFiniteStateMachine *baseFSM, const int curTime)
{
  bool v4; // r4
  idNavPathPosTracker *EnemyTracker; // r3
  idVehicleAI *ai; // r3
  float distance; // r10
  float rightDistance; // r9
  idNavSpline *navSpline; // r8
  idNavPathPosTracker *SplineTracker; // r3
  float v11; // r5
  idNavSpline *v12; // r4
  double v13; // fp0
  __int64 v14; // r6
  double PathDirection; // fp1
  __int64 v16; // r6
  int v17; // r10
  int v18; // r9
  bool v19; // r8
  idNavPathPosTracker *v20; // r3
  idEntity *Owner; // r3
  idPhysics *Physics; // r3
  float *v23; // r3
  idNavPathPosTracker *v24; // r3
  idEntity *v25; // r3
  idPhysics *v26; // r3
  float *v27; // r3
  double y; // fp13
  float v29; // r7
  double z; // fp12
  float v31; // r6
  double x; // fp11
  idNavPathPosTracker *v33; // r3
  double v34; // fp0
  double v35; // fp13
  idVehicleAI *v36; // r3
  bool v37; // zf
  int v38; // [sp+8h] [-98h]
  __int64 v39; // [sp+10h] [-90h]
  __int64 v40; // [sp+18h] [-88h]
  __int64 v41; // [sp+20h] [-80h]
  __int64 v42; // [sp+28h] [-78h]
  __int64 v43; // [sp+30h] [-70h]
  idNavSplinePosition v44; // [sp+50h] [-50h] BYREF
  __int64 v45; // [sp+60h] [-40h]
  float v46; // [sp+68h] [-38h]

  if ( idVehicleAI::GetEnemy(this: this->ai) != nullptr )
  {
    if ( this->state == ST_INIT )
    {
      if ( idVehicleAI::GetEnemyTracker(this: this->ai) != nullptr )
      {
        EnemyTracker = idVehicleAI::GetEnemyTracker(this: this->ai);
        distance = EnemyTracker->pathPosition.distance;
        rightDistance = EnemyTracker->pathPosition.rightDistance;
        navSpline = EnemyTracker->pathPosition.navSpline;
        ai = this->ai;
        v44.distance = distance;
        v44.rightDistance = rightDistance;
        v44.navSpline = navSpline;
        SplineTracker = idVehicleAI::GetSplineTracker(this: ai);
        v11 = SplineTracker->pathPosition.distance;
        v12 = SplineTracker->pathPosition.navSpline;
        LODWORD(v45) = LODWORD(SplineTracker->pathPosition.rightDistance);
        *(float *)&v45 = v11;
        v46 = *(float *)&v12;
        if ( *((float *)&v45 + 1) <= 0.0 )
          v13 = 10.0;
        else
          v13 = -10.0;
        v44.rightDistance = (float)v13 + *((float *)&v45 + 1);
        v14 = *(_QWORD *)&idVehicleAI::GetSplineTracker(this: this->ai)->pathPosition.distance;
        v45 = *(_QWORD *)&vec3_origin.x;
        PathDirection = idNavSplinePathMgr::GetPathDirection(
                          this: (idNavSplinePathMgr *)&gameLocal->aiSplinePathMgr.trackerPool.trackers[-1].userPath[0].path.num,
                          startPos: (idNavSplinePosition *)LODWORD(v44.rightDistance),
                          endPos: (idNavSplinePosition *)HIDWORD(v14));
        idNavSplinePosition::MoveDelta(
          this: &v44,
          delta: (float)((float)PathDirection * *(float *)(HIDWORD(v45) + 10056)),
          velocity: (idVec3 *)HIDWORD(v45));
        LODWORD(v16) = 1;
        HIDWORD(v16) = __ROL4__(v44.navSpline, 32);
        idVehicleAI::MoveToPathPosition(
          this: (idVehicleAI *)LODWORD(v44.distance),
          isStoppingGoal: v16,
          passThroughGoal: false,
          a4: v19,
          a5: v18,
          a6: v17,
          a7: v38,
          a8: v39,
          a9: v40,
          a10: v41,
          a11: v42,
          a12: v43);
        v20 = idVehicleAI::GetEnemyTracker(this: this->ai);
        Owner = idNavPathPosTracker::GetOwner(this: v20);
        Physics = idEntity::GetPhysics(this: Owner);
        v23 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
        this->oldEnemyPos.x = *v23;
        this->oldEnemyPos.y = v23[1];
        this->oldEnemyPos.z = v23[2];
      }
      this->state = 1;
    }
    if ( this->state == 1 )
    {
      if ( idVehicleAI::GetEnemyTracker(this: this->ai) != nullptr )
      {
        v24 = idVehicleAI::GetEnemyTracker(this: this->ai);
        v25 = idNavPathPosTracker::GetOwner(this: v24);
        v26 = idEntity::GetPhysics(this: v25);
        v27 = (float *)v26->GetOrigin(this: v26, a2: 0);
        y = this->oldEnemyPos.y;
        v29 = *v27;
        z = this->oldEnemyPos.z;
        v31 = v27[1];
        x = this->oldEnemyPos.x;
        v46 = v27[2];
        *(float *)&v45 = v29;
        *((float *)&v45 + 1) = v31;
        if ( (float)((float)((float)((float)x - v29) * (float)((float)x - v29))
                   + (float)((float)((float)((float)z - v46) * (float)((float)z - v46))
                           + (float)((float)((float)y - v31) * (float)((float)y - v31)))) >= 40000.0 )
          this->state = ST_INIT;
      }
      if ( this->ai->distanceToFinalGoal <= 500.0 )
        this->state = ST_INIT;
    }
    if ( this->state == ST_MOVE_AWAY )
    {
      idVehicleAI::MoveForward(this: this->ai, distance: 3000.0, isStoppingGoal: v4, passThroughGoal: 1u, a5: false);
      this->state = 3;
    }
    if ( this->state == 3 && this->ai->distanceToFinalGoal <= 500.0 )
      this->state = ST_INIT;
    v33 = idVehicleAI::GetEnemyTracker(this: this->ai);
    v34 = (float)(idNavPathPosTracker::GetCurrentSpeedInMPH(this: v33) + (float)20.0);
    v35 = 90.0;
    if ( v34 < 90.0 || (v35 = 150.0, v34 > 150.0) )
      v34 = v35;
    idVehicleAI::SetSpeedLimit(this: this->ai, speed: v34);
    v37 = idVehicleAI::GetEnemy(this: this->ai) == nullptr;
    v36 = this->ai;
    if ( v37 )
      idVehicleAI::StopFiringWeapon(this: v36);
    else
      idVehicleAI::FireWeapon(this: v36);
  }
}


// ========================================================================
// ?InternalEnterState@idVS_ds_Ambush@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B22668
// RVA : 0x00B22668
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_ds_Ambush::InternalEnterState(
        idVS_ds_Ambush *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  idVehicleAI *ai; // r11
  idVehicle *Enemy; // r3
  idNavPathPosTracker *SplineTracker; // r3
  float rightDistance; // r7
  idNavSpline *navSpline; // r6
  idVehicleAI *v9; // r3
  idNavSpline *v10; // r11
  int num; // r9
  char v12; // r10
  char v13; // r11
  double length; // fp0

  idVehicleAI::PushControlParams(this: this->ai);
  ai = this->ai;
  this->delayTime = 1;
  ai->movementFSM.SetState_3(this: &ai->movementFSM, a2: &idVS_ms_MoveToGoalOnSpline::Type, a3: 0, a4: false);
  Enemy = idVehicleAI::FindEnemy(this: this->ai);
  idVehicleAI::SetEnemy(this: this->ai, enemy: Enemy);
  SplineTracker = idVehicleAI::GetSplineTracker(this: this->ai);
  this->startingPathPos = SplineTracker->pathPosition;
  idVehicleAI::MoveToPosition(
    this: (idVehicleAI *)LODWORD(SplineTracker->pathPosition.distance),
    pathPos: (idNavSplinePosition *)LODWORD(SplineTracker->pathPosition.rightDistance),
    isStoppingGoal: __ROL4__(SplineTracker->pathPosition.navSpline, 32),
    passThroughGoal: 1u,
    a5: false);
  rightDistance = this->startingPathPos.rightDistance;
  navSpline = this->startingPathPos.navSpline;
  v9 = this->ai;
  this->backupPos.distance = this->startingPathPos.distance;
  this->backupPos.rightDistance = rightDistance;
  this->backupPos.navSpline = navSpline;
  v10 = idVehicleAI::GetSplineTracker(this: v9)->pathPosition.navSpline;
  if ( v10 != nullptr )
  {
    num = v10->prev.num;
    if ( num != 0 || (v12 = 1, v10->next.num <= 0) )
      v12 = 0;
    if ( v10->next.num != 0 || (v13 = 1, num <= 0) )
      v13 = 0;
    if ( v12 != 0 )
    {
      length = this->backupPos.navSpline->length;
    }
    else
    {
      if ( v13 == 0 )
        return;
      length = 0.0;
    }
    this->backupPos.distance = length;
  }
}


// ========================================================================
// ?InternalWork@idVS_ds_Ambush@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B227B8
// RVA : 0x00B227B8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_ds_Ambush::InternalWork(idVS_ds_Ambush *this, idFiniteStateMachine *baseFSM, const int curTime)
{
  bool v4; // r30
  idNavPathPosTracker *SplineTracker; // r3
  long double v6; // fp2
  float rightDistance; // r10
  int distance_low; // r7
  int rightDistance_low; // r6
  idNavSpline *navSpline; // r8
  idNavSpline *v11; // r5
  char v12; // r11
  idVehicleAI *ai; // r3
  __int64 v14; // r10
  bool v15; // r4
  idVehicleAI *v16; // r3
  idNavPathPosTracker *v17; // r3
  float v18; // r10
  float v19; // r8
  float v20; // r7
  idNavSpline *v21; // r9
  idNavSpline *v22; // r6
  char v23; // r11
  idVehicleAI *v24; // r3
  idNavPathPosTracker *v25; // r3
  idVehicleAI *v26; // r3
  float v27; // r10
  float v28; // r9
  idNavSpline *v29; // r8
  idEntity *v30; // r4
  double v31; // fp31
  idNavPathPosTracker *Tracker; // r3
  idNavPathPosTracker *v33; // r30
  idVehicleAI *v34; // r30
  idEntityPtr<idSplineWaypoint> *p_secondaryAmbushPos; // r3
  idSplineWaypoint *Entity; // r3
  idNavSpline *v37; // r9
  float v38; // r10
  idVehicleAI *v39; // r3
  __int64 v40; // r10
  int v41; // r8
  int v42; // r7
  int v43; // r6
  long double v44; // fp2
  idNavSplinePosition v45; // [sp+50h] [-100h] BYREF
  float distance; // [sp+60h] [-F0h]
  float v47; // [sp+64h] [-ECh]
  float v48; // [sp+70h] [-E0h]
  float v49; // [sp+74h] [-DCh]
  vaiControl_t v50; // [sp+80h] [-D0h] BYREF
  vaiControl_t v51; // [sp+C0h] [-90h] BYREF

  v4 = idVehicleAI::GetEnemy(this: this->ai) != nullptr;
  idVehicleAI::EngageEnemy(this: this->ai);
  if ( v4 && idVehicleAI::GetEnemy(this: this->ai) == nullptr )
  {
    idVehicleAI::MoveToPosition(
      this: (idVehicleAI *)LODWORD(this->backupPos.distance),
      pathPos: (idNavSplinePosition *)LODWORD(this->backupPos.rightDistance),
      isStoppingGoal: __ROL4__(this->backupPos.navSpline, 32),
      passThroughGoal: 1u,
      a5: false);
    this->finalBackupMove = false;
  }
  idVehicleAI::GetSplineTracker(this: this->ai)->useVelocityToGetClosestSpline = true;
  if ( idVehicleAI::GetEnemy(this: this->ai) == nullptr )
  {
    SplineTracker = idVehicleAI::GetSplineTracker(this: this->ai);
    rightDistance = this->ambushStartPos.rightDistance;
    distance_low = SLODWORD(SplineTracker->goalPathPosition.distance);
    rightDistance_low = LODWORD(SplineTracker->goalPathPosition.rightDistance);
    navSpline = this->ambushStartPos.navSpline;
    v11 = SplineTracker->goalPathPosition.navSpline;
    distance = this->ambushStartPos.distance;
    v47 = rightDistance;
    v48 = *(float *)&distance_low;
    v49 = *(float *)&rightDistance_low;
    if ( v11 != navSpline || (v12 = 1, __fabs((float)(v48 - distance)) > 0.1) )
      v12 = 0;
    ai = this->ai;
    if ( v12 != 0 )
    {
      if ( ai->distanceToFinalGoal >= 1000.0 )
        idVehicleAI::SetSpeedLimit(this: ai, speed: -20.0);
      else
        idVehicleAI::SetSpeedLimit(this: ai, speed: -10.0);
    }
    else
    {
      LODWORD(v14) = &unk_82150000;
      HIDWORD(v14) = &unk_821C0000;
      v50.avoidanceType = OAT_INIT;
      v50.powerTurnTime = -1;
      v50.moveDistance = -1.0;
      v50.maxCurveSpeed = -1.0;
      v50.maxCurveAngle = -1.0;
      v50.maxStepAngle = -1.0;
      v50.powerTurnSpeed = -1.0;
      v50.stopPowerTurnSpeed = -1.0;
      v50.traversalStepSize = -1.0;
      v50.backupSpeed = -1.0;
      v50.maxCurveCosine = -1.0;
      v50.maxStepCosine = -1.0;
      v50.speedLimit = 80.0;
      v50.stopDistance = 200.0;
      v50.decelDistance = 2000.0;
      idVehicleAI::UpdateControlParams(
        this: ai,
        params: &v50,
        initialize: false,
        a4: v6,
        a5: rightDistance_low,
        a6: distance_low,
        a7: (int)&unk_822D0000,
        a8: v14);
      v16 = this->ai;
      if ( v16->distanceToFinalGoal < 1000.0 )
        idVehicleAI::SetRightDistance(this: v16, dist: 0.0, splineReference: v15, a4: false);
      v17 = idVehicleAI::GetSplineTracker(this: this->ai);
      v18 = this->backupPos.rightDistance;
      v19 = v17->goalPathPosition.distance;
      v20 = v17->goalPathPosition.rightDistance;
      v21 = this->backupPos.navSpline;
      v22 = v17->goalPathPosition.navSpline;
      v48 = this->backupPos.distance;
      v49 = v18;
      distance = v19;
      v47 = v20;
      if ( v22 != v21 || (v23 = 1, __fabs((float)(distance - v48)) > 0.1) )
        v23 = 0;
      if ( v23 != 0 )
      {
        v24 = this->ai;
        if ( v24->distanceToFinalGoal > 400.0 )
        {
          v30 = idVehicleAI::EnemyNearMe(this: v24);
          if ( v30 != nullptr )
          {
            v31 = 110.0;
            Tracker = idNavSplinePathMgr::FindTracker(
                        this: (idNavSplinePathMgr *)&gameLocal->aiSplinePathMgr.trackerPool.trackers[-1].userPath[0].path.num,
                        owner: v30,
                        createTrackerIfNotFound: false);
            v33 = Tracker;
            if ( Tracker != nullptr && idNavPathPosTracker::GetCurrentSpeedInMPH(this: Tracker) > 110.0 )
              v31 = (float)(idNavPathPosTracker::GetCurrentSpeedInMPH(this: v33) + (float)10.0);
            idVehicleAI::SetSpeedLimit(this: this->ai, speed: v31);
          }
        }
        else
        {
          v25 = idVehicleAI::GetSplineTracker(this: v24);
          v27 = v25->pathPosition.distance;
          v28 = v25->pathPosition.rightDistance;
          v29 = v25->pathPosition.navSpline;
          v26 = this->ai;
          v45.distance = v27;
          v45.rightDistance = v28;
          v45.navSpline = v29;
          if ( idVehicleAI::GetSplineTracker(this: v26)->pathToGoal.path.list->dir <= 0.0 )
            v45.distance = -500.0;
          else
            v45.distance = v45.navSpline->length + (float)500.0;
          idNavSplinePosition::Validate(this: &v45, nextSpline: nullptr, prevSpline: nullptr);
          idVehicleAI::MoveToPosition(
            this: (idVehicleAI *)LODWORD(v45.distance),
            pathPos: (idNavSplinePosition *)LODWORD(v45.rightDistance),
            isStoppingGoal: __ROL4__(v45.navSpline, 32),
            passThroughGoal: 1u,
            a5: false);
          this->finalBackupMove = true;
        }
      }
      else if ( this->finalBackupMove )
      {
        v34 = this->ai;
        if ( v34->desiredSpeed == 0.0 && v34->distanceToFinalGoal < (double)idVehicleAI::GetStopDistance(this: this->ai) )
        {
          p_secondaryAmbushPos = &this->ai->setup.secondaryAmbushPos;
          if ( gameLocal->spawnIds.ptr[p_secondaryAmbushPos->spawnId.value & 0x1FFF] == p_secondaryAmbushPos->spawnId.value >> 13 )
          {
            Entity = idEntityPtr<idSplineWaypoint>::GetEntity(this: p_secondaryAmbushPos);
            this->ambushStartPos.distance = Entity->splinePathPosition.distance;
            this->ambushStartPos.rightDistance = Entity->splinePathPosition.rightDistance;
            v37 = Entity->splinePathPosition.navSpline;
          }
          else
          {
            v38 = this->startingPathPos.rightDistance;
            v37 = this->startingPathPos.navSpline;
            this->ambushStartPos.distance = this->startingPathPos.distance;
            this->ambushStartPos.rightDistance = v38;
          }
          this->ambushStartPos.navSpline = v37;
          idVehicleAI::MoveToPosition(
            this: this->ai,
            pathPos: (idNavSplinePosition *)LODWORD(this->ambushStartPos.rightDistance),
            isStoppingGoal: __ROL4__(v37, 32),
            passThroughGoal: 1u,
            a5: false);
          idVehicleAI::GetSplineTracker(this: this->ai)->useVelocityToGetClosestSpline = false;
          v51.moveDistance = -1.0;
          v51.avoidanceType = OAT_INIT;
          v51.decelDistance = -1.0;
          v51.powerTurnTime = -1;
          v51.maxCurveSpeed = -1.0;
          v51.maxCurveAngle = -1.0;
          v51.maxStepAngle = -1.0;
          v39 = this->ai;
          v51.powerTurnSpeed = -1.0;
          v51.stopPowerTurnSpeed = -1.0;
          v51.traversalStepSize = -1.0;
          v51.backupSpeed = -1.0;
          v51.maxCurveCosine = -1.0;
          v51.maxStepCosine = -1.0;
          v51.stopDistance = 200.0;
          v51.speedLimit = 0.0;
          idVehicleAI::UpdateControlParams(
            this: v39,
            params: &v51,
            initialize: false,
            a4: v44,
            a5: v43,
            a6: v42,
            a7: v41,
            a8: v40);
          this->ai->lastBackupTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + 2000;
        }
      }
    }
  }
}


// ========================================================================
// ?FindNewGoalPos@idVS_as_RangeShoot@@QAAXXZ
// EA  : 0x82B22C70
// RVA : 0x00B22C70
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_RangeShoot::FindNewGoalPos(idVS_as_RangeShoot *this)
{
  __int64 v2; // r10
  unsigned int v3; // r6
  double v4; // fp31
  idNavPathPosTracker *EnemyTracker; // r3
  idNavSplinePosition *p_goalPathPos; // r30
  idNavSpline *navSpline; // r5
  idNavSpline *v8; // r27
  double attackRange; // fp0
  double v10; // fp31
  idNavSpline *NextSplines; // r3
  idNavSpline *v12; // r3
  idNavSpline *PrevSplines; // r3
  idNavSpline *v14; // r4
  double v15; // fp1
  idNavSpline *v16; // r10
  idNavPathPosTracker *SplineTracker; // r3
  double PathDirection; // fp1
  unsigned int v19; // r3
  __int64 v20; // r9
  double SplineWidth; // fp1
  unsigned int v22; // r9
  idVehicleAI *ai; // r3
  __int64 v24; // r5
  idNavPathPosTracker *v25; // r3
  idEntity *Owner; // r3
  idPhysics *Physics; // r3
  float *v28; // r9
  idGameLocal *v29; // r3
  idGameLocal_vtbl *v30; // r8
  int (__fastcall *GetGameMs)(struct idGameLocal *, const gameTimeType_t); // r7
  idNavSplinePosition v32; // [sp+58h] [-88h] BYREF

  if ( this->cycleDone )
  {
    ++this->ai->numAttackAttempts;
    this->cycleDone = false;
    this->lastCycleDonePosition = vec3_origin;
  }
  this->inRange = false;
  this->aligned = false;
  HIDWORD(v2) = byte_821B0000;
  v3 = 1664525 * clientGame->random.seed;
  clientGame->random.seed = v3 + 1013904223;
  LODWORD(v2) = ((v3 + 1013904223) >> 10) & 0x7FFF;
  v4 = (float)((float)(idVehicleAI::GetAttackRange(this: this->ai)
                     * (float)((float)((float)v2 * (float)0.000061037019) - (float)1.0))
             * (float)0.2);
  this->attackRange = idVehicleAI::GetAttackRange(this: this->ai) + (float)v4;
  EnemyTracker = idVehicleAI::GetEnemyTracker(this: this->ai);
  p_goalPathPos = &this->goalPathPos;
  this->goalPathPos.distance = EnemyTracker->pathPosition.distance;
  this->goalPathPos.rightDistance = EnemyTracker->pathPosition.rightDistance;
  navSpline = EnemyTracker->pathPosition.navSpline;
  this->goalPathPos.navSpline = navSpline;
  if ( navSpline == nullptr )
  {
    idStr::operator=(this: &this->debugInfo, text: "bad");
    return;
  }
  if ( !idNavSplinePosition::IsOnDeadendPath(this: &this->goalPathPos) )
  {
    SplineTracker = idVehicleAI::GetSplineTracker(this: this->ai);
    PathDirection = idNavSplinePathMgr::GetPathDirection(
                      this: (idNavSplinePathMgr *)(LODWORD(this->goalPathPos.distance) - 11336),
                      startPos: (idNavSplinePosition *)LODWORD(this->goalPathPos.rightDistance),
                      endPos: (idNavSplinePosition *)LODWORD(SplineTracker->pathPosition.distance));
    v19 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v19;
    LODWORD(v20) = (v19 >> 10) & 0x7FFF;
    if ( (float)((float)v20 * (float)0.000030518509) >= 0.5 )
      PathDirection = -PathDirection;
    idNavSplinePosition::MoveDelta(
      this: &this->goalPathPos,
      delta: (float)(this->attackRange * (float)PathDirection),
      velocity: (idVec3 *)LODWORD(vec3_origin.x));
    goto LABEL_21;
  }
  v8 = this->goalPathPos.navSpline;
  v32.navSpline = nullptr;
  attackRange = this->attackRange;
  v32.distance = 0.0;
  v32.rightDistance = 0.0;
  if ( v8->next.num <= 0 )
  {
    v10 = (float)((float)attackRange - p_goalPathPos->distance);
    PrevSplines = idNavSpline::GetPrevSplines(this: v8, num: 0);
    v12 = idNavSpline::GetPrevSplines(
            this: this->goalPathPos.navSpline,
            num: (_cntlzw((char *)v8 - (char *)PrevSplines) & 0x20) != 0);
  }
  else
  {
    v10 = (float)((float)attackRange - v8->length);
    NextSplines = idNavSpline::GetNextSplines(this: v8, num: 0);
    v12 = idNavSpline::GetNextSplines(
            this: this->goalPathPos.navSpline,
            num: (_cntlzw((char *)v8 - (char *)NextSplines) & 0x20) != 0);
  }
  v14 = this->goalPathPos.navSpline;
  v32.navSpline = v12;
  if ( v14 == nullptr )
    goto LABEL_13;
  if ( idNavSpline::GetDirFromLinkedSpline(this: v14, spline: v14) != 1 )
  {
    v12 = v32.navSpline;
LABEL_13:
    if ( v12 != nullptr )
      v32.distance = v12->length;
    else
      v32.distance = 0.0;
    v15 = -v10;
    goto LABEL_17;
  }
  v32.distance = 0.0;
  v15 = v10;
LABEL_17:
  idNavSplinePosition::MoveDelta(this: &v32, delta: v15, velocity: (idVec3 *)LODWORD(vec3_origin.x));
  v32.rightDistance = 0.0;
  v16 = v32.navSpline;
  p_goalPathPos->distance = v32.distance;
  this->goalPathPos.navSpline = v16;
  this->goalPathPos.rightDistance = v32.rightDistance;
LABEL_21:
  SplineWidth = idNavSplinePosition::GetSplineWidth(this: &this->goalPathPos, dist: -1.0);
  v22 = 1664525 * clientGame->random.seed;
  clientGame->random.seed = v22 + 1013904223;
  ai = this->ai;
  LODWORD(v24) = ((v22 + 1013904223) >> 10) & 0x7FFF;
  this->goalPathPos.rightDistance = (float)((float)((float)v24 * (float)0.000061037019) - (float)1.0)
                                  * (float)SplineWidth;
  v25 = idVehicleAI::GetEnemyTracker(this: ai);
  Owner = idNavPathPosTracker::GetOwner(this: v25);
  Physics = idEntity::GetPhysics(this: Owner);
  v28 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v29 = gameLocal;
  v30 = gameLocal->__vftable;
  this->enemyWorldPos.x = *v28;
  this->enemyWorldPos.y = v28[1];
  GetGameMs = v30->GetGameMs;
  this->enemyWorldPos.z = v28[2];
  this->lastNewPosTime = GetGameMs(this: v29, a2: GAMETIME_SCALED);
}


// ========================================================================
// ?InternalEnterState@idVS_as_RandomFollow@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B23000
// RVA : 0x00B23000
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_RandomFollow::InternalEnterState(
        idVS_as_RandomFollow *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  idVehicleAI::PushControlParams(this: this->ai);
  this->startingPos = idVehicleAI::GetSplineTracker(this: this->ai)->pathPosition;
  idVS_as_RandomFollow::DetermineNewGoal(this);
}


// ========================================================================
// ?InternalWork@idVS_as_RandomFollow@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B23060
// RVA : 0x00B23060
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_RandomFollow::InternalWork(
        idVS_as_RandomFollow *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  int v4; // r10
  int v5; // r9
  bool v6; // r8
  __int64 v7; // r6
  idNavPathPosTracker *EnemyTracker; // r3
  idEntity *Owner; // r3
  idPhysics *Physics; // r29
  idVec3 *WorldPos; // r28
  bool v12; // r8
  float *v13; // r3
  char *v14; // r9
  double v15; // fp10
  double v16; // fp6
  enum idAIStateTransition::aiTransCode_t (__fastcall **v17)(COMBAT_AtPlugAnim *__hidden, struct idAI2 *, struct idAIFSM *, struct idAIState *, int); // r10
  __int64 v18; // r6
  idNavPathPosTracker *v19; // r3
  double CurrentSpeedInMPH; // fp1
  double v21; // fp1
  int v22; // [sp+8h] [-88h]
  __int64 v23; // [sp+10h] [-80h]
  __int64 v24; // [sp+18h] [-78h]
  __int64 v25; // [sp+20h] [-70h]
  __int64 v26; // [sp+28h] [-68h]
  __int64 v27; // [sp+30h] [-60h]
  idNavSplinePosition v28[5]; // [sp+50h] [-40h] BYREF

  if ( idVehicleAI::GetEnemyTracker(this: this->ai) != nullptr )
  {
    EnemyTracker = idVehicleAI::GetEnemyTracker(this: this->ai);
    Owner = idNavPathPosTracker::GetOwner(this: EnemyTracker);
    Physics = idEntity::GetPhysics(this: Owner);
    WorldPos = idNavSplinePosition::GetWorldPos(this: v28, result: (idVec3 *)&this->goalPos);
    v13 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v14 = "Could not find AI state, idVS_ds_Car_Chase! ";
    v15 = (float)(v13[2] - WorldPos->z);
    v16 = (float)(v13[1] - WorldPos->y);
    if ( (float)((float)((float)v16 * (float)v16)
               + (float)((float)((float)(*v13 - WorldPos->x) * (float)(*v13 - WorldPos->x))
                       + (float)((float)v15 * (float)v15))) > 16000000.0
      || (v17 = &off_82040000, this->ai->splineDistanceToFinalGoal < 500.0) )
    {
      idVS_as_RandomFollow::DetermineNewGoal(this);
    }
    LODWORD(v18) = 1;
    HIDWORD(v18) = __ROL4__(this->goalPos.navSpline, 32);
    idVehicleAI::MoveToPathPosition(
      this: this->ai,
      isStoppingGoal: v18,
      passThroughGoal: false,
      a4: v12,
      a5: (int)v14,
      a6: (int)v17,
      a7: v22,
      a8: v23,
      a9: v24,
      a10: v25,
      a11: v26,
      a12: v27);
    v19 = idVehicleAI::GetEnemyTracker(this: this->ai);
    CurrentSpeedInMPH = idNavPathPosTracker::GetCurrentSpeedInMPH(this: v19);
    if ( CurrentSpeedInMPH >= 55.0 )
      v21 = (float)((float)CurrentSpeedInMPH + (float)10.0);
    else
      v21 = 65.0;
    idVehicleAI::SetSpeedLimit(this: this->ai, speed: v21);
    idVehicleAI::FireWeapon(this: this->ai);
  }
  else
  {
    LODWORD(v7) = 1;
    HIDWORD(v7) = __ROL4__(this->startingPos.navSpline, 32);
    idVehicleAI::MoveToPathPosition(
      this: (idVehicleAI *)LODWORD(this->startingPos.distance),
      isStoppingGoal: v7,
      passThroughGoal: false,
      a4: v6,
      a5: v5,
      a6: v4,
      a7: v22,
      a8: v23,
      a9: v24,
      a10: v25,
      a11: v26,
      a12: v27);
    idVehicleAI::SetSpeedLimit(this: this->ai, speed: 65.0);
  }
}


// ========================================================================
// ?InternalEnterState@idVS_as_HitAndRun@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B231B8
// RVA : 0x00B231B8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_HitAndRun::InternalEnterState(
        idVS_as_HitAndRun *this,
        idFiniteStateMachine *baseFSM,
        const int curTime,
        int a4,
        int a5,
        bool a6,
        int a7,
        int a8)
{
  __int64 v9; // r6
  unsigned int v10; // r4
  int v11; // [sp+8h] [-58h]
  __int64 v12; // [sp+10h] [-50h]
  __int64 v13; // [sp+18h] [-48h]
  __int64 v14; // [sp+20h] [-40h]
  __int64 v15; // [sp+28h] [-38h]
  __int64 v16; // [sp+30h] [-30h]

  if ( this->stacked )
  {
    if ( this->state == ST_MOVING_AWAY )
    {
      LODWORD(v9) = 0;
      HIDWORD(v9) = __ROL4__(this->saveGoalPos.navSpline, 32);
      idVehicleAI::MoveToPathPosition(
        this: (idVehicleAI *)LODWORD(this->saveGoalPos.distance),
        isStoppingGoal: v9,
        passThroughGoal: false,
        a4: a6,
        a5: a7,
        a6: a8,
        a7: v11,
        a8: v12,
        a9: v13,
        a10: v14,
        a11: v15,
        a12: v16);
    }
  }
  else
  {
    this->state = ST_CHASING;
    v10 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v10;
    this->actionCount = ((v10 >> 10) & 0x7FFF) - 2 * ((int)((v10 >> 10) & 0x7FFF) >> 1) + 1;
  }
  idVehicleAI::SetCollideAttack(this: this->ai, bl: true);
}


// ========================================================================
// ?InternalEnterState@idVS_as_WaypointTag@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B23270
// RVA : 0x00B23270
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_WaypointTag::InternalEnterState(
        idVS_as_WaypointTag *this,
        idFiniteStateMachine *baseFSM,
        const int curTime,
        int a4,
        int a5,
        bool a6,
        int a7,
        int a8,
        int a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14)
{
  __int64 v15; // r6
  unsigned int v16; // r3

  if ( this->stacked )
  {
    if ( this->state == ST_MOVING_AWAY )
    {
      LODWORD(v15) = 0;
      HIDWORD(v15) = __ROL4__(this->saveGoalPos.navSpline, 32);
      idVehicleAI::MoveToPathPosition(
        this: (idVehicleAI *)LODWORD(this->saveGoalPos.distance),
        isStoppingGoal: v15,
        passThroughGoal: false,
        a4: a6,
        a5: a7,
        a6: (int)this,
        a7: a9,
        a8: a10,
        a9: a11,
        a10: a12,
        a11: a13,
        a12: a14);
    }
  }
  else
  {
    this->state = ST_CHASING;
    v16 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v16;
    this->actionCount = ((v16 >> 10) & 0x7FFF) - 2 * ((int)((v16 >> 10) & 0x7FFF) >> 1) + 1;
  }
}


// ========================================================================
// ?InternalEnterState@idVS_ds_RoverBomb@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B232F8
// RVA : 0x00B232F8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_ds_RoverBomb::InternalEnterState(
        idVS_ds_RoverBomb *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  int value; // r10
  idVehicle_Car *v4; // r3
  idVehicle_Car *v5; // r3

  value = this->ownerCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v4 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v4 != nullptr )
      v5 = idVehicle_Car::CastTo(c: v4);
    else
      v5 = nullptr;
    idVehicle_Car::AddQuickUseActive(this: v5, t: VQU_ROVER_BOMBS, timeMS: 0);
  }
}


// ========================================================================
// ?InternalExitState@idVS_ds_RoverBomb@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B23380
// RVA : 0x00B23380
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_ds_RoverBomb::InternalExitState(
        idVS_ds_RoverBomb *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  int value; // r10
  idVehicle_Car *v4; // r3
  idVehicle_Car *v5; // r3

  value = this->ownerCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v4 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v4 != nullptr )
      v5 = idVehicle_Car::CastTo(c: v4);
    else
      v5 = nullptr;
    idVehicle_Car::RemoveQuickUseActive(this: v5, t: VQU_ROVER_BOMBS);
  }
}


// ========================================================================
// ?InternalEnterState@idVS_ms_Backup@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B23400
// RVA : 0x00B23400
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_ms_Backup::InternalEnterState(
        idVS_ms_Backup *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  double BackupSpeed; // fp1
  idVehicleAI *ai; // r11
  idVehicleAI *v6; // r3
  double speed; // fp1
  int value; // r9
  idVehicle_Car *v9; // r3
  idVehicle_Car *v10; // r3
  idPhysics *Physics; // r3
  float *v12; // r3
  idVehicleAI *v13; // r30
  int valueInteger; // r28

  idVehicleAI::PushControlParams(this: this->ai);
  BackupSpeed = idVehicleAI::GetBackupSpeed(this: this->ai);
  ai = this->ai;
  this->speed = BackupSpeed;
  if ( ai->attackFSM.curState == &ai->attackFSM.s_Idle )
    this->speed = (float)BackupSpeed * (float)2.0;
  ai->desiredBraking = 0;
  v6 = this->ai;
  if ( v6->desiredSpeed <= 0.0 )
    speed = this->speed;
  else
    speed = -this->speed;
  this->speed = speed;
  idVehicleAI::SetSpeedLimit(this: v6, speed);
  this->steering = -idVehicleAI::DetermineSteering(this: this->ai);
  this->startTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  value = this->ai->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v9 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v10 = idVehicle_Car::CastTo(c: v9);
  }
  else
  {
    v10 = nullptr;
  }
  Physics = idEntity::GetPhysics(this: v10);
  v12 = (float *)Physics->GetAxis(this: Physics, a2: 0);
  this->goalFacing.x = *v12;
  this->goalFacing.y = v12[1];
  this->goalFacing.z = v12[2];
  this->backupTime = 1000;
  v13 = this->ai;
  valueInteger = vai_excessiveBackupsTime.valueInteger;
  if ( gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - v13->lastBackupTime >= valueInteger )
    v13->excessiveBackupAttempts = 0;
  else
    ++v13->excessiveBackupAttempts;
  this->ai->lastBackupTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
}


// ========================================================================
// ?InternalWork@idVS_ms_Backup@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B235A8
// RVA : 0x00B235A8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_ms_Backup::InternalWork(idVS_ms_Backup *this, idFiniteStateMachine *baseFSM, const int curTime)
{
  int value; // r9
  idVehicle_Car *v5; // r3
  idVehicle_Car *v6; // r3
  idPhysics *Physics; // r3
  float *v8; // r3

  idVehicleAI::SetSpeedLimit(this: this->ai, speed: this->speed);
  this->ai->desiredSpeed = idVehicleAI::DetermineSpeed(this: this->ai);
  this->ai->desiredSteering = this->steering;
  value = this->ai->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v6 = idVehicle_Car::CastTo(c: v5);
  }
  else
  {
    v6 = nullptr;
  }
  Physics = idEntity::GetPhysics(this: v6);
  v8 = (float *)Physics->GetAxis(this: Physics, a2: 0);
  if ( (float)((float)(this->goalFacing.x * *v8)
             + (float)((float)(this->goalFacing.y * v8[1]) + (float)(this->goalFacing.z * v8[2]))) <= 0.2
    || gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - this->startTime > this->backupTime )
  {
    idVehicleBaseFSM::PopState(this: &this->ai->movementFSM, setPoppedState: true);
    idVehicleAI::PopControlParams(this: this->ai);
  }
}


// ========================================================================
// ?InternalEnterState@idVS_ms_PowerTurn@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B236F8
// RVA : 0x00B236F8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_ms_PowerTurn::InternalEnterState(
        idVS_ms_PowerTurn *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  idNavPathPosTracker *SplineTracker; // r3
  double CurrentSpeedInMPH; // fp1
  idVehicleAI *ai; // r11
  double v7; // fp0
  int value; // r9
  idVehicle_Car *v9; // r3
  idVehicle_Car *v10; // r3
  idPhysics *Physics; // r3
  idVec3 *v12; // r3

  SplineTracker = idVehicleAI::GetSplineTracker(this: this->ai);
  CurrentSpeedInMPH = idNavPathPosTracker::GetCurrentSpeedInMPH(this: SplineTracker);
  ai = this->ai;
  if ( CurrentSpeedInMPH <= 50.0 )
    ai->desiredSpeed = 50.0;
  else
    ai->desiredSpeed = 0.0;
  this->ai->desiredBraking = 2;
  if ( idVehicleAI::GetRightDistance(this: this->ai) <= 0.0 )
    v7 = 45.0;
  else
    v7 = -45.0;
  this->ai->desiredSteering = v7;
  value = this->ai->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v9 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v10 = idVehicle_Car::CastTo(c: v9);
  }
  else
  {
    v10 = nullptr;
  }
  Physics = idEntity::GetPhysics(this: v10);
  v12 = (idVec3 *)Physics->GetAxis(this: Physics, a2: 0);
  this->startYaw = idVec3::ToYaw(this: v12);
  this->endTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + 2000;
}


// ========================================================================
// ?InternalWork@idVS_ms_PowerTurn@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B23828
// RVA : 0x00B23828
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_ms_PowerTurn::InternalWork(
        idVS_ms_PowerTurn *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  int value; // r9
  idVehicle_Car *v5; // r3
  idVehicle_Car *v6; // r3
  idPhysics *Physics; // r3
  idVec3 *v8; // r3

  value = this->ai->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v6 = idVehicle_Car::CastTo(c: v5);
  }
  else
  {
    v6 = nullptr;
  }
  Physics = idEntity::GetPhysics(this: v6);
  v8 = (idVec3 *)Physics->GetAxis(this: Physics, a2: 0);
  if ( __fabs((float)(idVec3::ToYaw(this: v8) - this->startYaw)) > 120.0 )
  {
    this->ai->desiredBraking = 1;
    this->ai->desiredSteering = 0.0;
  }
  if ( this->endTime <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
    idVehicleBaseFSM::PopState(this: &this->ai->movementFSM, setPoppedState: true);
}


// ========================================================================
// ?InternalWork@idVS_ds_Patrol@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B23930
// RVA : 0x00B23930
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_ds_Patrol::InternalWork(idVS_ds_Patrol *this, idFiniteStateMachine *baseFSM, const int curTime)
{
  int v4; // r10
  int v5; // r9
  bool v6; // r8
  idVehicleAI *ai; // r3
  vehicleAiSetup_t::patrol_t *v8; // r30
  __int64 v9; // r6
  idVehicleAI *v10; // r4
  idEventArg *v11; // r3
  idVehicle_Car *VehicleCar; // r3
  idVehicleAI *v13; // r3
  idEntity *v14; // r4
  double v15; // fp31
  idNavPathPosTracker *Tracker; // r3
  idNavPathPosTracker *v17; // r30
  int v18; // [sp+8h] [-88h]
  __int64 v19; // [sp+10h] [-80h]
  __int64 v20; // [sp+18h] [-78h]
  __int64 v21; // [sp+20h] [-70h]
  __int64 v22; // [sp+28h] [-68h]
  __int64 v23; // [sp+30h] [-60h]
  idEventArg v24; // [sp+50h] [-40h] BYREF

  idVehicleAI::EngageEnemy(this: this->ai);
  if ( idVehicleAI::GetEnemy(this: this->ai) == nullptr )
  {
    ai = this->ai;
    v8 = &ai->patrolPaths[1];
    if ( ai->patrolPaths[1].waypoints.num >= 1 )
    {
      idVehicleAI::UpdatePatrolPath(this: ai);
    }
    else
    {
      LODWORD(v9) = 1;
      HIDWORD(v9) = __ROL4__(this->startPos.navSpline, 32);
      idVehicleAI::MoveToPathPosition(
        this: (idVehicleAI *)LODWORD(this->startPos.distance),
        isStoppingGoal: v9,
        passThroughGoal: false,
        a4: v6,
        a5: v5,
        a6: v4,
        a7: v18,
        a8: v19,
        a9: v20,
        a10: v21,
        a11: v22,
        a12: v23);
      v10 = this->ai;
      if ( v10->hideWhenIdle && v10->distanceToFinalGoal <= 500.0 && (v10->thinkFlags & 1) != 0 )
      {
        v11 = idEventArg::idEventArg(this: &v24, data: v10);
        idEventReceiver::PostEventMS(
          this: this->ai,
          ev: &EV_Activate,
          time: *(_DWORD *)&v11->type,
          arg1: (const idEventArg *)LODWORD(v11->value.v[1]));
        VehicleCar = idVehicleAI::GetVehicleCar(this: this->ai);
        VehicleCar->Hide_2(this: VehicleCar);
      }
      idVehicleAI::SetSpeedLimit(this: this->ai, speed: v8->speed);
    }
    v13 = this->ai;
    if ( v13->setup.patrol.fleeNearEnemy )
    {
      v14 = idVehicleAI::EnemyNearMe(this: v13);
      if ( v14 != nullptr )
      {
        v15 = 110.0;
        Tracker = idNavSplinePathMgr::FindTracker(
                    this: (idNavSplinePathMgr *)&gameLocal->aiSplinePathMgr.trackerPool.trackers[-1].userPath[0].path.num,
                    owner: v14,
                    createTrackerIfNotFound: false);
        v17 = Tracker;
        if ( Tracker != nullptr && idNavPathPosTracker::GetCurrentSpeedInMPH(this: Tracker) > 110.0 )
          v15 = (float)(idNavPathPosTracker::GetCurrentSpeedInMPH(this: v17) + (float)10.0);
        idVehicleAI::SetSpeedLimit(this: this->ai, speed: v15);
      }
    }
  }
}


// ========================================================================
// ?InternalWork@idVS_ds_Barricade@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B23AB8
// RVA : 0x00B23AB8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_ds_Barricade::InternalWork(
        idVS_ds_Barricade *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  int v4; // r29
  idPlayer *Player; // r31
  int value; // r9
  idVehicle_Car *v7; // r3
  idVehicle_Car *v8; // r3
  idPhysics *Physics; // r27
  idPhysics *v10; // r26
  float *v11; // r27
  float *v12; // r3
  double v13; // fp10
  double v14; // fp6
  idEntity *v15; // r3

  idVehicleAI::EngageEnemy(this: this->ai);
  idVehicleAI::GetSplineTracker(this: this->ai)->useVelocityToGetClosestSpline = true;
  if ( idVehicleAI::GetEnemy(this: this->ai) == nullptr )
  {
    v4 = 0;
    while ( 1 )
    {
      Player = idGameLocal::GetPlayer(this: gameLocal, i: v4);
      if ( Player != nullptr )
      {
        value = this->ai->vehicleCar.spawnId.value;
        if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
          && (v7 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
        {
          v8 = idVehicle_Car::CastTo(c: v7);
        }
        else
        {
          v8 = nullptr;
        }
        Physics = idEntity::GetPhysics(this: v8);
        v10 = idEntity::GetPhysics(this: Player);
        v11 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
        v12 = (float *)v10->GetOrigin(this: v10, a2: 0);
        v13 = (float)(v12[2] - v11[2]);
        v14 = (float)(v12[1] - v11[1]);
        if ( (float)((float)((float)v14 * (float)v14)
                   + (float)((float)((float)(*v12 - *v11) * (float)(*v12 - *v11)) + (float)((float)v13 * (float)v13))) < 16000000.0
          && Player->GetVehicle_2(this: Player) != nullptr )
        {
          break;
        }
      }
      if ( ++v4 >= 6 )
        return;
    }
    v15 = Player->GetVehicle_2(this: Player);
    idVehicleAI::SetTarget(this: this->ai, entity: v15);
    idVehicleAI::FireWeapon(this: this->ai);
  }
}


// ========================================================================
// ?InternalWork@idVS_as_ChaseShoot@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B23C50
// RVA : 0x00B23C50
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_ChaseShoot::InternalWork(
        idVS_as_ChaseShoot *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  double v4; // fp31
  double rightDistance; // fp30
  idNavPathPosTracker *EnemyTracker; // r3
  double v7; // fp29
  idVehicleAI *ai; // r11
  double v9; // fp0
  double v10; // fp0
  idNavPathPosTracker *v11; // r3
  double v12; // fp0
  idNavPathPosTracker *v13; // r3
  idNavPathPosTracker *v14; // r30
  idNavPathPosTracker *SplineTracker; // r3
  idNavPathPosTracker *v16; // r3
  idEntity *Owner; // r3
  idPhysics *Physics; // r3
  int v19; // r3
  idNavPathPosTracker *v20; // r3
  double CurrentSpeedInMPH; // fp31
  idVehicleAI *v22; // r3
  double distanceToFinalGoal; // fp0
  void *v24; // r8
  int v25; // r7
  int v26; // r6
  long double v27; // fp2
  __int64 v28; // r10
  double v29; // fp0
  double v30; // fp13
  int value; // r10
  idGameLocal *v32; // r30
  idVehicle_Car *v33; // r3
  idVehicle_Car *v34; // r3
  idPresentable *presentable; // r3
  int v36; // r3
  idEntity *v37; // r3
  idEntity *v38; // r30
  int v39; // r3
  idEntity *Enemy; // r3
  idVehicleAI *v41; // r3
  unsigned int v42; // r3
  unsigned int v43; // r30
  int v44; // r3
  unsigned int v45; // r3
  float distance; // [sp+50h] [-130h]
  float v47; // [sp+50h] [-130h]
  float v48; // [sp+50h] [-130h]
  idNavSplinePosition *v49; // [sp+54h] [-12Ch]
  idNavSpline *navSpline; // [sp+58h] [-128h]
  vaiControl_t v51; // [sp+60h] [-120h] BYREF
  _DWORD v52[46]; // [sp+A0h] [-E0h] BYREF

  if ( idVehicleAI::GetEnemyTracker(this: this->ai) != nullptr )
  {
    v4 = idVehicleAI::NormalizeEnemyRightDistance(this: this->ai);
    rightDistance = idVehicleAI::GetSplineTracker(this: this->ai)->pathPosition.rightDistance;
    EnemyTracker = idVehicleAI::GetEnemyTracker(this: this->ai);
    v7 = (float)((float)v4 - (float)rightDistance);
    ai = this->ai;
    distance = EnemyTracker->pathPosition.distance;
    *(float *)&v49 = rightDistance;
    navSpline = EnemyTracker->pathPosition.navSpline;
    if ( ai->distanceToFinalGoal < 500.0 && __fabs(v7) < 100.0 )
    {
      if ( rightDistance <= v4 )
        v9 = (float)((float)v4 - (float)100.0);
      else
        v9 = (float)((float)v4 + (float)100.0);
      *(float *)&v49 = v9;
    }
    if ( __fabs(v7) > 300.0 )
    {
      if ( rightDistance <= v4 )
        v10 = (float)((float)v4 - (float)300.0);
      else
        v10 = (float)((float)v4 + (float)300.0);
      *(float *)&v49 = v10;
    }
    v11 = idVehicleAI::GetEnemyTracker(this: ai);
    if ( idNavPathPosTracker::GetCurrentSpeedInMPH(this: v11) > 10.0 )
    {
      if ( __fabs(v7) <= 200.0 )
        v12 = 250.0;
      else
        v12 = 125.0;
      this->goalDistOfs = v12;
    }
    else
    {
      this->goalDistOfs = 500.0;
    }
    v13 = idVehicleAI::GetEnemyTracker(this: this->ai);
    v47 = distance - (float)(idNavPathPosTracker::GetFacing(this: v13) * this->goalDistOfs);
    v14 = idVehicleAI::GetEnemyTracker(this: this->ai);
    SplineTracker = idVehicleAI::GetSplineTracker(this: this->ai);
    v48 = v47 + idNavPathPosTracker::GetMoveAheadDist(this: SplineTracker, otherTracker: v14);
    v16 = idVehicleAI::GetEnemyTracker(this: this->ai);
    Owner = idNavPathPosTracker::GetOwner(this: v16);
    Physics = idEntity::GetPhysics(this: Owner);
    v19 = (int)Physics->GetLinearVelocity(this: (idPhysics *)v52, result: (idVec3 *)Physics, a3: 0);
    idNavSplinePosition::Validate(this: *(idNavSplinePosition **)v19, velocity: *(idVec3 **)(v19 + 4));
    idVehicleAI::MoveToPosition(
      this: (idVehicleAI *)LODWORD(v48),
      pathPos: v49,
      isStoppingGoal: __ROL4__(navSpline, 32),
      passThroughGoal: 1u,
      a5: false);
    v20 = idVehicleAI::GetEnemyTracker(this: this->ai);
    CurrentSpeedInMPH = idNavPathPosTracker::GetCurrentSpeedInMPH(this: v20);
    if ( CurrentSpeedInMPH < 0.0 )
      CurrentSpeedInMPH = 0.0;
    v22 = this->ai;
    distanceToFinalGoal = v22->distanceToFinalGoal;
    if ( distanceToFinalGoal <= 500.0 )
    {
      if ( distanceToFinalGoal > 100.0 )
        CurrentSpeedInMPH = (float)((float)CurrentSpeedInMPH + (float)10.0);
    }
    else
    {
      CurrentSpeedInMPH = idVehicleAI::GetMaxSpeed(this: v22);
    }
    idVehicleAI::SetSpeedLimit(this: this->ai, speed: CurrentSpeedInMPH);
    HIDWORD(v28) = 0x82000000;
    v51.avoidanceType = OAT_INIT;
    v51.powerTurnTime = -1;
    v51.speedLimit = -1.0;
    v51.maxCurveAngle = -1.0;
    v51.maxStepAngle = -1.0;
    v51.powerTurnSpeed = -1.0;
    v51.stopPowerTurnSpeed = -1.0;
    v51.traversalStepSize = -1.0;
    v51.backupSpeed = -1.0;
    v51.maxCurveCosine = -1.0;
    v51.maxStepCosine = -1.0;
    if ( CurrentSpeedInMPH >= 40.0 )
    {
      v51.maxCurveCosine = 0.0;
      LODWORD(v28) = &unk_82150000;
      v51.decelDistance = 200.0;
      v51.moveDistance = 100.0;
      v29 = 80.0;
      v30 = 50.0;
    }
    else
    {
      HIDWORD(v28) = &unk_821F0000;
      v24 = &unk_822D0000;
      LODWORD(v28) = &unk_821C0000;
      v29 = 65.0;
      v30 = 400.0;
      v51.moveDistance = 800.0;
      v51.decelDistance = 2000.0;
    }
    v51.stopDistance = v30;
    v51.maxCurveSpeed = v29;
    idVehicleAI::UpdateControlParams(
      this: this->ai,
      params: &v51,
      initialize: false,
      a4: v27,
      a5: v26,
      a6: v25,
      a7: (int)v24,
      a8: v28);
    value = this->ai->vehicleCar.spawnId.value;
    v32 = gameLocal;
    if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
      && (v33 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
    {
      v34 = idVehicle_Car::CastTo(c: v33);
      v32 = gameLocal;
    }
    else
    {
      v34 = nullptr;
    }
    presentable = v34->presentable;
    if ( presentable != nullptr )
    {
      v36 = (int)presentable->GetVehicleInterface(this: presentable);
      v32 = gameLocal;
    }
    else
    {
      v36 = 0;
    }
    memcpy(Dst: &v52[4], Src: (const void *)(v36 + 20272), Size: 0x68u);
    if ( v32->spawnIds.ptr[v52[7] & 0x1FFF] == v52[7] >> 13 && (v37 = v32->entities.ptr[v52[7] & 0x1FFF]) != nullptr )
      v38 = idEntity::CastTo(c: v37);
    else
      v38 = nullptr;
    if ( v38 == idVehicleAI::GetEnemy(this: this->ai) )
    {
      v39 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      if ( v52[4] + 500 >= v39 && BYTE1(v52[16]) == 0 && this->delayTime == 0 )
        this->shootTime = 0;
    }
    Enemy = idVehicleAI::GetEnemy(this: this->ai);
    idVehicleAI::SetTarget(this: this->ai, entity: Enemy);
    v41 = this->ai;
    if ( v41->distanceToFinalGoal < 3000.0 )
    {
      if ( this->shootTime != 0 )
      {
        if ( this->shootTime <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
          this->shootTime = 0;
        idVehicleAI::FireWeapon(this: this->ai);
        ++this->ai->numAttackAttempts;
      }
      else
      {
        idVehicleAI::StopFiringWeapon(this: v41);
        if ( this->delayTime != 0 )
        {
          if ( this->delayTime < gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
          {
            v42 = 1664525 * clientGame->random.seed + 1013904223;
            clientGame->random.seed = v42;
            v43 = ((v42 >> 10) & 0x7FFF) % 0x5DC;
            v44 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
            this->delayTime = 0;
            this->shootTime = v44 + v43 + 500;
          }
        }
        else
        {
          v45 = 1664525 * clientGame->random.seed + 1013904223;
          clientGame->random.seed = v45;
          this->delayTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED)
                          + ((v45 >> 10) & 0x7FFF) % 0x3E8
                          + 500;
        }
      }
    }
  }
}


// ========================================================================
// ?InternalWork@idVS_as_ChaseSideBump@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B24208
// RVA : 0x00B24208
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_ChaseSideBump::InternalWork(
        idVS_as_ChaseSideBump *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  double v4; // fp31
  idNavPathPosTracker *EnemyTracker; // r3
  idNavPathPosTracker *SplineTracker; // r3
  double rightDistance; // fp0
  double v8; // fp13
  double bumpRangeDir; // fp13
  double v10; // fp0
  char v11; // r29
  int v12; // r3
  double v13; // fp0
  idVehicle_Car *VehicleCar; // r3
  idEntityPtr<idEntity> *LastCollision; // r3
  idEntity *v16; // r28
  idVehicle_Car *v17; // r3
  int v18; // r3
  idVehicleAI *ai; // r9
  double v20; // fp0
  idNavPathPosTracker *v21; // r3
  idNavPathPosTracker *v22; // r30
  idNavPathPosTracker *v23; // r3
  idNavPathPosTracker *v24; // r3
  idEntity *Owner; // r3
  idPhysics *Physics; // r3
  int v27; // r3
  idNavPathPosTracker *v28; // r3
  double CurrentSpeedInMPH; // fp31
  idVehicleAI *v30; // r3
  double distanceToFinalGoal; // fp0
  void *v32; // r8
  int v33; // r7
  int v34; // r6
  long double v35; // fp2
  __int64 v36; // r10
  double v37; // fp0
  double v38; // fp13
  float distance; // [sp+50h] [-B0h]
  float v40; // [sp+50h] [-B0h]
  float v41; // [sp+50h] [-B0h]
  float v42; // [sp+54h] [-ACh]
  idNavSpline *navSpline; // [sp+58h] [-A8h]
  char v44; // [sp+60h] [-A0h] BYREF
  vaiControl_t v45; // [sp+70h] [-90h] BYREF

  if ( idVehicleAI::GetEnemyTracker(this: this->ai) != nullptr )
  {
    ++this->ai->debugCount;
    v4 = idVehicleAI::NormalizeEnemyRightDistance(this: this->ai);
    EnemyTracker = idVehicleAI::GetEnemyTracker(this: this->ai);
    distance = EnemyTracker->pathPosition.distance;
    navSpline = EnemyTracker->pathPosition.navSpline;
    SplineTracker = idVehicleAI::GetSplineTracker(this: this->ai);
    rightDistance = SplineTracker->pathPosition.rightDistance;
    v42 = SplineTracker->pathPosition.rightDistance;
    v8 = (float)((float)v4 + (float)500.0);
    if ( rightDistance > v8 || (v8 = (float)((float)v4 - (float)500.0), rightDistance < v8) )
      v42 = v8;
    bumpRangeDir = this->bumpRangeDir;
    v10 = (float)(this->bumpRangeDir + this->bumpRange);
    this->bumpRange = this->bumpRangeDir + this->bumpRange;
    if ( v10 > 300.0 || v10 < 200.0 )
      this->bumpRangeDir = -bumpRangeDir;
    v11 = 0;
    if ( this->bumpDelay != 0 )
    {
      if ( this->bumpDelay <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
        this->bumpDelay = 0;
    }
    else if ( this->bumpAttemptTime >= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
    {
      v11 = 1;
      if ( v4 >= idVehicleAI::GetSplineTracker(this: this->ai)->pathPosition.rightDistance )
        v13 = (float)((float)v4 + (float)200.0);
      else
        v13 = (float)((float)v4 - (float)200.0);
      v42 = v13;
      VehicleCar = idVehicleAI::GetVehicleCar(this: this->ai);
      LastCollision = (idEntityPtr<idEntity> *)idVehicle::GetLastCollision(this: VehicleCar);
      v16 = idEntityPtr<idEntity const>::operator->(this: LastCollision + 3);
      if ( v16 == idVehicleAI::GetEnemy(this: this->ai) )
      {
        v17 = idVehicleAI::GetVehicleCar(this: this->ai);
        if ( *(_DWORD *)idVehicle::GetLastCollision(this: v17) > this->lastAttemptTime - 750 )
        {
          v11 = 0;
          v18 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
          ai = this->ai;
          this->bumpDelay = v18 + 1000;
          ++ai->numAttackAttempts;
        }
      }
    }
    else if ( this->ai->distanceToFinalGoal <= (double)this->bumpRange )
    {
      v12 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      this->lastAttemptTime = v12;
      this->bumpAttemptTime = v12 + 750;
    }
    if ( v11 == 0
      && __fabs((float)((float)v4 - idVehicleAI::GetSplineTracker(this: this->ai)->pathPosition.rightDistance)) < 300.0 )
    {
      if ( idVehicleAI::GetSplineTracker(this: this->ai)->pathPosition.rightDistance <= v4 )
        v20 = (float)((float)v4 - (float)200.0);
      else
        v20 = (float)((float)v4 + (float)200.0);
      v42 = v20;
    }
    v21 = idVehicleAI::GetEnemyTracker(this: this->ai);
    v40 = distance + (float)(idNavPathPosTracker::GetFacing(this: v21) * (float)200.0);
    v22 = idVehicleAI::GetEnemyTracker(this: this->ai);
    v23 = idVehicleAI::GetSplineTracker(this: this->ai);
    v41 = v40 + idNavPathPosTracker::GetMoveAheadDist(this: v23, otherTracker: v22);
    v24 = idVehicleAI::GetEnemyTracker(this: this->ai);
    Owner = idNavPathPosTracker::GetOwner(this: v24);
    Physics = idEntity::GetPhysics(this: Owner);
    v27 = (int)Physics->GetLinearVelocity(this: (idPhysics *)&v44, result: (idVec3 *)Physics, a3: 0);
    idNavSplinePosition::Validate(this: *(idNavSplinePosition **)v27, velocity: *(idVec3 **)(v27 + 4));
    idVehicleAI::MoveToPosition(
      this: (idVehicleAI *)LODWORD(v41),
      pathPos: (idNavSplinePosition *)LODWORD(v42),
      isStoppingGoal: __ROL4__(navSpline, 32),
      passThroughGoal: 1u,
      a5: false);
    v28 = idVehicleAI::GetEnemyTracker(this: this->ai);
    CurrentSpeedInMPH = idNavPathPosTracker::GetCurrentSpeedInMPH(this: v28);
    if ( CurrentSpeedInMPH < 0.0 )
      CurrentSpeedInMPH = 0.0;
    v30 = this->ai;
    distanceToFinalGoal = v30->distanceToFinalGoal;
    if ( distanceToFinalGoal <= 500.0 )
    {
      if ( distanceToFinalGoal > 100.0 )
        CurrentSpeedInMPH = (float)((float)CurrentSpeedInMPH + (float)10.0);
    }
    else
    {
      CurrentSpeedInMPH = idVehicleAI::GetMaxSpeed(this: v30);
    }
    idVehicleAI::SetSpeedLimit(this: this->ai, speed: CurrentSpeedInMPH);
    HIDWORD(v36) = 0x82000000;
    v45.avoidanceType = OAT_INIT;
    v45.powerTurnTime = -1;
    v45.speedLimit = -1.0;
    v45.maxCurveAngle = -1.0;
    v45.maxStepAngle = -1.0;
    v45.powerTurnSpeed = -1.0;
    v45.stopPowerTurnSpeed = -1.0;
    v45.traversalStepSize = -1.0;
    v45.backupSpeed = -1.0;
    v45.maxCurveCosine = -1.0;
    v45.maxStepCosine = -1.0;
    if ( CurrentSpeedInMPH >= 40.0 )
    {
      v45.maxCurveCosine = 0.0;
      LODWORD(v36) = &unk_82150000;
      v45.decelDistance = 200.0;
      v45.moveDistance = 100.0;
      v37 = 80.0;
      v38 = 50.0;
    }
    else
    {
      HIDWORD(v36) = &unk_821F0000;
      v32 = &unk_822D0000;
      LODWORD(v36) = &unk_821C0000;
      v37 = 65.0;
      v38 = 400.0;
      v45.moveDistance = 800.0;
      v45.decelDistance = 2000.0;
    }
    v45.stopDistance = v38;
    v45.maxCurveSpeed = v37;
    idVehicleAI::UpdateControlParams(
      this: this->ai,
      params: &v45,
      initialize: false,
      a4: v35,
      a5: v34,
      a6: v33,
      a7: (int)v32,
      a8: v36);
    if ( idVehicleAI::OkToFire(this: this->ai) )
      idVehicleAI::FireWeapon(this: this->ai);
  }
}


// ========================================================================
// ?InternalWork@idVS_as_ChaseRearBump@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B24658
// RVA : 0x00B24658
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_ChaseRearBump::InternalWork(
        idVS_as_ChaseRearBump *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  double v4; // fp31
  idNavPathPosTracker *EnemyTracker; // r3
  idVehicleAI *ai; // r3
  idVehicleAI *distance_low; // r10
  idNavSplinePosition *rightDistance_low; // r9
  idNavSpline *navSpline; // r8
  idNavPathPosTracker *SplineTracker; // r3
  idVehicleAI *v11; // r11
  idNavPathPosTracker *v12; // r3
  idNavPathPosTracker *v13; // r3
  idEntity *Owner; // r3
  idPhysics *Physics; // r3
  int v16; // r3
  idNavPathPosTracker *v17; // r3
  double CurrentSpeedInMPH; // fp1
  double v19; // fp31
  double MaxSpeed; // fp31
  int value; // r9
  idVehicle_Car *v22; // r3
  idVehicle_Car *v23; // r3
  int v24; // r9
  idEntity *v25; // r3
  idVehicle *v26; // r4
  idVehicle_Car *VehicleCar; // r3
  __int64 v28; // r9
  unsigned int v29; // r6
  double v30; // fp30
  __int64 v31; // r6
  idVehicleAI *v32; // r3
  double distanceToFinalGoal; // fp0
  int v34; // r8
  int v35; // r7
  int v36; // r6
  long double v37; // fp2
  __int64 v38; // r10
  __int64 v39; // [sp+50h] [-A0h] BYREF
  float v40; // [sp+60h] [-90h]
  float rightDistance; // [sp+64h] [-8Ch]
  idNavSpline *v42; // [sp+68h] [-88h]
  vaiControl_t v43; // [sp+70h] [-80h] BYREF

  if ( idVehicleAI::GetEnemyTracker(this: this->ai) != nullptr )
  {
    v4 = idVehicleAI::NormalizeEnemyRightDistance(this: this->ai);
    EnemyTracker = idVehicleAI::GetEnemyTracker(this: this->ai);
    distance_low = (idVehicleAI *)LODWORD(EnemyTracker->pathPosition.distance);
    rightDistance_low = (idNavSplinePosition *)LODWORD(EnemyTracker->pathPosition.rightDistance);
    navSpline = EnemyTracker->pathPosition.navSpline;
    ai = this->ai;
    v40 = *(float *)&distance_low;
    rightDistance = *(float *)&rightDistance_low;
    v42 = navSpline;
    SplineTracker = idVehicleAI::GetSplineTracker(this: ai);
    v11 = this->ai;
    rightDistance = SplineTracker->pathPosition.rightDistance;
    if ( v11->distanceToFinalGoal < 2000.0 )
      rightDistance = v4;
    v12 = idVehicleAI::GetEnemyTracker(this: v11);
    v40 = v40 + idNavPathPosTracker::GetFacing(this: v12);
    v13 = idVehicleAI::GetEnemyTracker(this: this->ai);
    Owner = idNavPathPosTracker::GetOwner(this: v13);
    Physics = idEntity::GetPhysics(this: Owner);
    v16 = (int)Physics->GetLinearVelocity(this: (idPhysics *)&v39, result: (idVec3 *)Physics, a3: 0);
    idNavSplinePosition::Validate(this: *(idNavSplinePosition **)v16, velocity: *(idVec3 **)(v16 + 4));
    idVehicleAI::MoveToPosition(
      this: (idVehicleAI *)LODWORD(v40),
      pathPos: (idNavSplinePosition *)LODWORD(rightDistance),
      isStoppingGoal: __ROL4__(v42, 32),
      passThroughGoal: 1u,
      a5: false);
    v17 = idVehicleAI::GetEnemyTracker(this: this->ai);
    CurrentSpeedInMPH = idNavPathPosTracker::GetCurrentSpeedInMPH(this: v17);
    v19 = CurrentSpeedInMPH;
    if ( this->bumpDelay != 0 )
    {
      if ( this->bumpDelay <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
        this->bumpDelay = 0;
      this->lastBumpDelayTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      MaxSpeed = (float)((float)v19 - (float)30.0);
    }
    else
    {
      MaxSpeed = (float)((float)CurrentSpeedInMPH + (float)50.0);
      value = this->ai->vehicleCar.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v22 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v23 = idVehicle_Car::CastTo(c: v22);
      }
      else
      {
        v23 = nullptr;
      }
      v24 = *(_DWORD *)(idVehicle::GetLastCollision(this: v23) + 12);
      if ( gameLocal->spawnIds.ptr[v24 & 0x1FFF] == v24 >> 13
        && (v25 = gameLocal->entities.ptr[v24 & 0x1FFF]) != nullptr )
      {
        v26 = (idVehicle *)idEntity::CastTo(c: v25);
      }
      else
      {
        v26 = nullptr;
      }
      if ( (unsigned __int8)idVehicleAI::IsEnemy(this: this->ai, entity: v26) != 0 )
      {
        VehicleCar = idVehicleAI::GetVehicleCar(this: this->ai);
        if ( *(_DWORD *)idVehicle::GetLastCollision(this: VehicleCar) > this->lastBumpDelayTime )
        {
          HIDWORD(v28) = 1664525;
          v29 = 1664525 * clientGame->random.seed;
          clientGame->random.seed = v29 + 1013904223;
          LODWORD(v28) = ((v29 + 1013904223) >> 10) & 0x7FFF;
          v39 = v28;
          v30 = (float)((float)v28 * (float)0.000030518509);
          LODWORD(v31) = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
          HIDWORD(v31) = this->ai;
          v39 = v31;
          this->bumpDelay = (int)(float)((float)((float)((float)v30 * (float)1000.0) + (float)v31) + (float)1000.0);
          ++*(_DWORD *)(HIDWORD(v31) + 2648);
        }
      }
    }
    if ( MaxSpeed < 0.0 )
      MaxSpeed = 10.0;
    v32 = this->ai;
    distanceToFinalGoal = v32->distanceToFinalGoal;
    if ( distanceToFinalGoal <= 2000.0 )
    {
      if ( distanceToFinalGoal > 500.0 )
        MaxSpeed = (float)((float)MaxSpeed + (float)10.0);
    }
    else
    {
      MaxSpeed = idVehicleAI::GetMaxSpeed(this: v32);
    }
    idVehicleAI::SetSpeedLimit(this: this->ai, speed: MaxSpeed);
    HIDWORD(v38) = 0x82000000;
    v43.avoidanceType = OAT_INIT;
    v43.powerTurnTime = -1;
    v43.speedLimit = -1.0;
    v43.maxCurveAngle = -1.0;
    v43.maxStepAngle = -1.0;
    v43.powerTurnSpeed = -1.0;
    v43.stopPowerTurnSpeed = -1.0;
    v43.traversalStepSize = -1.0;
    v43.backupSpeed = -1.0;
    v43.maxCurveCosine = -1.0;
    v43.maxStepCosine = -1.0;
    if ( MaxSpeed >= 40.0 )
    {
      v43.maxCurveCosine = 0.0;
      LODWORD(v38) = &unk_82150000;
      v43.stopDistance = 50.0;
      v43.maxCurveSpeed = 80.0;
      v43.decelDistance = 100.0;
      v43.moveDistance = 100.0;
    }
    else
    {
      v43.decelDistance = 2000.0;
      LODWORD(v38) = &unk_821C0000;
      HIDWORD(v38) = &unk_821F0000;
      v43.maxCurveSpeed = 65.0;
      v43.stopDistance = 400.0;
      v43.moveDistance = 800.0;
    }
    idVehicleAI::UpdateControlParams(
      this: this->ai,
      params: &v43,
      initialize: false,
      a4: v37,
      a5: v36,
      a6: v35,
      a7: v34,
      a8: v38);
    if ( idVehicleAI::OkToFire(this: this->ai) )
      idVehicleAI::FireWeapon(this: this->ai);
  }
}


// ========================================================================
// ?InternalEnterState@idVS_as_RangeShoot@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B24A88
// RVA : 0x00B24A88
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_RangeShoot::InternalEnterState(
        idVS_as_RangeShoot *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  idVehicleAI *ai; // r3
  idVehicleAI *v5; // r3
  long double v6; // fp2
  __int64 v7; // r10
  idVehicleAI *v8; // r3
  int v9; // r8
  int v10; // r7
  int v11; // r6
  vaiControl_t v12; // [sp+50h] [-50h] BYREF

  ai = this->ai;
  this->adjustTime = 0;
  idVehicleAI::PushControlParams(this: ai);
  v5 = this->ai;
  v12.avoidanceType = OAT_INIT;
  v12.powerTurnTime = -1;
  v12.speedLimit = -1.0;
  v12.stopDistance = -1.0;
  v12.decelDistance = -1.0;
  v12.maxCurveSpeed = -1.0;
  v12.maxCurveAngle = -1.0;
  v12.maxStepAngle = -1.0;
  v12.powerTurnSpeed = -1.0;
  v12.stopPowerTurnSpeed = -1.0;
  v12.traversalStepSize = -1.0;
  v12.backupSpeed = -1.0;
  v12.maxCurveCosine = -1.0;
  v12.maxStepCosine = -1.0;
  *(double *)&v6 = idVehicleAI::GetStopDistance(this: v5);
  HIDWORD(v7) = &off_82040000;
  v12.moveDistance = *(double *)&v6;
  v8 = this->ai;
  v12.decelDistance = 500.0;
  idVehicleAI::UpdateControlParams(this: v8, params: &v12, initialize: false, a4: v6, a5: v11, a6: v10, a7: v9, a8: v7);
  idVS_as_RangeShoot::FindNewGoalPos(this);
}


// ========================================================================
// ?InternalWork@idVS_as_RangeShoot@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B24B38
// RVA : 0x00B24B38
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_RangeShoot::InternalWork(
        idVS_as_RangeShoot *this,
        idFiniteStateMachine *baseFSM,
        const int curTime,
        long double a4)
{
  long double v5; // fp2
  int value; // r9
  idVehicle_Car *v7; // r3
  idVehicle_Car *v8; // r29
  idNavPathPosTracker *EnemyTracker; // r3
  idEntity *Owner; // r3
  idPhysics *Physics; // r3
  float *v12; // r3
  double v13; // fp10
  double v14; // fp8
  double v15; // fp6
  idVehicleAI *ai; // r3
  idPhysics *v17; // r3
  float *v18; // r3
  double v19; // fp13
  double v20; // fp12
  idVec3 *WorldPos; // r3
  double y; // fp9
  double v23; // fp8
  idNavPathPosTracker *v24; // r3
  idVehicleAI *v27; // r29
  idNavPathPosTracker *v28; // r3
  idPhysics *v29; // r24
  idEntity *v30; // r3
  idPhysics *v31; // r23
  float *v32; // r24
  float *v33; // r3
  double v34; // fp7
  double v35; // fp6
  idPhysics *v36; // r3
  float *v37; // r3
  idVehicleAI *v38; // r30
  idPhysics *v39; // r24
  idEntity *Enemy; // r3
  idPhysics *v41; // r23
  float *v42; // r24
  float *v43; // r3
  double v44; // fp7
  double v45; // fp6
  idPhysics *v46; // r3
  float *v47; // r3
  idNavPathPosTracker *SplineTracker; // r3
  int excessiveBackupAttempts; // r11
  int v50; // r11
  int GameMs; // r30
  idVehicle_Car *VehicleCar; // r3
  idVehicle_Car *v53; // r30
  idVehicle_Car *v54; // r3
  idVehicleAI *v55; // r3
  idVehicleAI *v56; // r3
  idEntity *v57; // r3
  double v58; // fp1
  idVehicleAI *v59; // r3
  idVehicle_Car *v60; // r3
  idPhysics *v61; // r3
  float *v62; // r3
  double v63; // fp10
  double v64; // fp8
  double v65; // fp6
  idVehicle_Car *v66; // r3
  idPhysics *v67; // r3
  float *v68; // r3
  idVehicleAI *v69; // r3
  idPhysics *v70; // r3
  float *v71; // r3
  idVehicleAI *v72; // r11
  double v73; // fp13
  BOOL aligned; // r7
  double v75; // fp12
  float v76; // r5
  float z; // r4
  idColor *v78; // r10
  double v79; // fp0
  double v80; // fp13
  double v81; // fp0
  idVec3 v82; // [sp+50h] [-110h] BYREF
  float r; // [sp+60h] [-100h] BYREF
  float g; // [sp+64h] [-FCh]
  float b; // [sp+68h] [-F8h]
  float a; // [sp+6Ch] [-F4h]
  float v87; // [sp+70h] [-F0h] BYREF
  float v88; // [sp+74h] [-ECh]
  float v89; // [sp+78h] [-E8h]
  float x; // [sp+80h] [-E0h] BYREF
  float v91; // [sp+84h] [-DCh]
  float v92; // [sp+88h] [-D8h]
  float v93[4]; // [sp+90h] [-D0h] BYREF
  float v94[4]; // [sp+A0h] [-C0h] BYREF
  float v95[4]; // [sp+B0h] [-B0h] BYREF
  float v96[4]; // [sp+C0h] [-A0h] BYREF
  float v97[4]; // [sp+D0h] [-90h] BYREF
  char v98; // [sp+E0h] [-80h] BYREF
  float v99; // [sp+E4h] [-7Ch]
  char v100; // [sp+F0h] [-70h] BYREF
  float v101; // [sp+F4h] [-6Ch]

  if ( (_S18_7 & 1) == 0 )
  {
    _S18_7 |= 1u;
    *(double *)&a4 = (float)(idMath::M_DEG2RAD * (float)45.0);
    v5 = cos(x: a4);
    ALIGN_ANGLE = *(double *)&v5;
  }
  if ( idVehicleAI::GetEnemyTracker(this: this->ai) == nullptr )
    goto LABEL_14;
  value = this->ai->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
    goto LABEL_14;
  v7 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
  if ( v7 == nullptr )
    goto LABEL_14;
  v8 = idVehicle_Car::CastTo(c: v7);
  if ( v8 == nullptr )
    goto LABEL_14;
  if ( idVehicleAI::GetEnemy(this: this->ai) == nullptr )
  {
    idStr::operator=(this: &this->debugInfo, text: "bad no enemy");
    return;
  }
  EnemyTracker = idVehicleAI::GetEnemyTracker(this: this->ai);
  Owner = idNavPathPosTracker::GetOwner(this: EnemyTracker);
  Physics = idEntity::GetPhysics(this: Owner);
  v12 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
  v13 = (float)(v12[1] - this->enemyWorldPos.y);
  v14 = (float)(v12[2] - this->enemyWorldPos.z);
  v15 = (float)(*v12 - this->enemyWorldPos.x);
  if ( (float)((float)((float)v15 * (float)v15)
             + (float)((float)((float)v14 * (float)v14) + (float)((float)v13 * (float)v13))) > 1000000.0
    || gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - this->lastNewPosTime > 8000 )
  {
    idVS_as_RangeShoot::FindNewGoalPos(this);
  }
  if ( this->goalPathPos.navSpline == nullptr )
  {
    idVS_as_RangeShoot::FindNewGoalPos(this);
LABEL_14:
    idStr::operator=(this: &this->debugInfo, text: "bad");
    return;
  }
  if ( vai_debug_attackstate_draw.valueInteger != 0 )
  {
    ai = this->ai;
    v93[0] = idColor::colorOrange.r;
    v93[1] = idColor::colorOrange.g;
    v93[2] = idColor::colorOrange.b;
    v93[3] = idColor::colorOrange.a;
    v17 = idEntity::GetPhysics(this: ai);
    v18 = (float *)v17->GetOrigin(this: v17, a2: 0);
    v19 = v18[1];
    v20 = (float)(v18[2] + (float)55.0);
    v95[0] = *v18;
    v95[1] = v19;
    v95[2] = v20;
    WorldPos = idNavSplinePosition::GetWorldPos(this: (idNavSplinePosition *)&v82, result: (idVec3 *)&this->goalPathPos);
    y = WorldPos->y;
    v23 = (float)(WorldPos->z + (float)55.0);
    x = WorldPos->x;
    v91 = y;
    v92 = v23;
    clientGame->renderWorld->DebugLine(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)v93,
      a3: (const idVec3 *)v95,
      a4: (const idVec3 *)&x,
      a5: 0,
      a6: false);
    v97[3] = 25.0;
    v97[0] = x;
    v97[1] = v91;
    v97[2] = v92;
    clientGame->renderWorld->DebugSphere(
      this: clientGame->renderWorld,
      a2: (const idVec4 *)v93,
      a3: (const idSphere *)v97,
      a4: 12,
      a5: 0,
      a6: false);
  }
  v24 = idVehicleAI::GetEnemyTracker(this: this->ai);
  _FP12 = (float)((float)80.0 - (float)(idNavPathPosTracker::GetCurrentSpeedInMPH(this: v24) + (float)15.0));
  __asm { fsel      f1, f12, f0, f13# speed }
  idVehicleAI::SetSpeedLimit(this: this->ai, speed: _FP1);
  if ( this->inRange )
  {
    if ( this->aligned )
    {
      idStr::operator=(this: &this->debugInfo, text: "VALID");
      v39 = idEntity::GetPhysics(this: v8);
      Enemy = idVehicleAI::GetEnemy(this: this->ai);
      v41 = idEntity::GetPhysics(this: Enemy);
      v42 = (float *)v39->GetOrigin(this: v39, a2: 0);
      v43 = (float *)v41->GetOrigin(this: v41, a2: 0);
      v44 = (float)(v43[1] - v42[1]);
      v45 = (float)(v43[2] - v42[2]);
      v82.x = *v43 - *v42;
      v82.y = v44;
      v82.z = v45;
      idVec3::NormalizeFast(this: &v82);
      v46 = idEntity::GetPhysics(this: v8);
      v47 = (float *)v46->GetAxis(this: v46, a2: 0);
      if ( (float)((float)(*v47 * v82.x) + (float)((float)(v47[2] * v82.z) + (float)(v47[1] * v82.y))) >= (double)ALIGN_ANGLE )
      {
        idStr::operator=(this: &this->debugInfo, text: "REALLY VALID");
        SplineTracker = idVehicleAI::GetSplineTracker(this: this->ai);
        idVehicleAI::MoveToPosition(
          this: (idVehicleAI *)LODWORD(SplineTracker->pathPosition.distance),
          pathPos: (idNavSplinePosition *)LODWORD(SplineTracker->pathPosition.rightDistance),
          isStoppingGoal: __ROL4__(SplineTracker->pathPosition.navSpline, 32),
          passThroughGoal: 1u,
          a5: false);
      }
    }
    else
    {
      idStr::operator=(this: &this->debugInfo, text: "ALIGN");
      v28 = idVehicleAI::GetEnemyTracker(this: this->ai);
      idVehicleAI::MoveToPosition(
        this: (idVehicleAI *)LODWORD(v28->pathPosition.distance),
        pathPos: (idNavSplinePosition *)LODWORD(v28->pathPosition.rightDistance),
        isStoppingGoal: __ROL4__(v28->pathPosition.navSpline, 32),
        passThroughGoal: 1u,
        a5: false);
      v29 = idEntity::GetPhysics(this: v8);
      v30 = idVehicleAI::GetEnemy(this: this->ai);
      v31 = idEntity::GetPhysics(this: v30);
      v32 = (float *)v29->GetOrigin(this: v29, a2: 0);
      v33 = (float *)v31->GetOrigin(this: v31, a2: 0);
      v34 = (float)(v33[1] - v32[1]);
      v35 = (float)(v33[2] - v32[2]);
      v82.x = *v33 - *v32;
      v82.y = v34;
      v82.z = v35;
      idVec3::NormalizeFast(this: &v82);
      v36 = idEntity::GetPhysics(this: v8);
      v37 = (float *)v36->GetAxis(this: v36, a2: 0);
      if ( (float)((float)(*v37 * v82.x) + (float)((float)(v37[2] * v82.z) + (float)(v37[1] * v82.y))) >= (double)ALIGN_ANGLE )
      {
        this->aligned = true;
        this->alignedTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
      }
      v38 = this->ai;
      if ( v38->distanceToFinalGoal <= (double)idVehicleAI::GetStopDistance(this: v38) )
        idVS_as_RangeShoot::FindNewGoalPos(this);
    }
  }
  else
  {
    idVehicleAI::MoveToPosition(
      this: (idVehicleAI *)LODWORD(this->goalPathPos.distance),
      pathPos: (idNavSplinePosition *)LODWORD(this->goalPathPos.rightDistance),
      isStoppingGoal: __ROL4__(this->goalPathPos.navSpline, 32),
      passThroughGoal: 1u,
      a5: true);
    v27 = this->ai;
    if ( v27->splineDistanceToFinalGoal <= (double)idVehicleAI::GetDecelDistance(this: v27) )
      this->inRange = true;
    this->lastNewPosTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
  }
  excessiveBackupAttempts = this->ai->excessiveBackupAttempts;
  if ( excessiveBackupAttempts < 0 )
  {
    v50 = 2;
  }
  else
  {
    if ( excessiveBackupAttempts <= this->newGoalFromBackupsCount )
      goto LABEL_33;
    idVS_as_RangeShoot::FindNewGoalPos(this);
    v50 = this->newGoalFromBackupsCount + 2;
  }
  this->newGoalFromBackupsCount = v50;
LABEL_33:
  if ( this->inRange )
  {
    GameMs = idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED);
    if ( GameMs - idVehicleAI::GetVehicleCar(this: this->ai)->lastDamage.time < 200 )
    {
      VehicleCar = idVehicleAI::GetVehicleCar(this: this->ai);
      v53 = (idVehicle_Car *)idEntityPtr<idEntity const>::operator->(this: &VehicleCar->lastDamage.attacker);
      v54 = idVehicle_Car::CastTo(c: v53);
      v55 = (idVehicleAI *)(v54 != nullptr ? idVehicle::GetDriver(this: v54) : v53);
      v56 = idVehicleAI::CastTo(c: v55);
      if ( v56 != nullptr && v56 != this->ai )
        idVS_as_RangeShoot::FindNewGoalPos(this);
    }
  }
  v57 = idVehicleAI::GetEnemy(this: this->ai);
  idVehicleAI::SetTarget(this: this->ai, entity: v57);
  idVehicleAI::GetTargetAngles(this: (idVehicleAI *)&v98, result: (idAngles *)this->ai);
  idVehicleAI::GetWeaponAngles(this: (idVehicleAI *)&v100, result: (idAngles *)this->ai);
  v58 = idMath::AngleNormalize360(angle: (float)(v99 - v101));
  if ( v58 > 180.0 )
    v58 = (float)((float)v58 - (float)360.0);
  if ( __fabs(v58) >= 50.0 )
  {
    if ( this->inRange && this->aligned )
    {
      idStr::operator=(this: &this->debugInfo, text: "RESET");
LABEL_57:
      idVS_as_RangeShoot::FindNewGoalPos(this);
    }
  }
  else if ( (unsigned __int8)idVehicleAI::FireWeapon(this: this->ai) != 0 || this->ai->inFireDelayState )
  {
    v59 = this->ai;
    if ( v59->distanceToFinalGoal < 500.0 )
    {
      v60 = idVehicleAI::GetVehicleCar(this: v59);
      v61 = idEntity::GetPhysics(this: v60);
      v62 = (float *)v61->GetOrigin(this: v61, a2: 0);
      v63 = (float)(this->lastCycleDonePosition.y - v62[1]);
      v64 = (float)(this->lastCycleDonePosition.z - v62[2]);
      v65 = (float)(this->lastCycleDonePosition.x - *v62);
      if ( (float)((float)((float)v65 * (float)v65)
                 + (float)((float)((float)v64 * (float)v64) + (float)((float)v63 * (float)v63))) > 250000.0 )
      {
        v66 = idVehicleAI::GetVehicleCar(this: this->ai);
        v67 = idEntity::GetPhysics(this: v66);
        v68 = (float *)v67->GetOrigin(this: v67, a2: 0);
        this->lastCycleDonePosition.x = *v68;
        this->lastCycleDonePosition.y = v68[1];
        this->lastCycleDonePosition.z = v68[2];
        this->cycleDone = true;
      }
    }
  }
  else if ( this->inRange
         && this->aligned
         && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED) - this->alignedTime > 500
         && idGameTimeManager::GetGameMs(this: &clientGame->gameTimeManager, type: GAMETIME_SCALED)
          - this->ai->weaponFiredTime > 1000 )
  {
    goto LABEL_57;
  }
  if ( vai_debug_attackstate_draw.valueInteger == 0 )
    return;
  v69 = this->ai;
  r = idColor::colorRed.r;
  g = idColor::colorRed.g;
  b = idColor::colorRed.b;
  a = idColor::colorRed.a;
  v70 = idEntity::GetPhysics(this: v69);
  v71 = (float *)v70->GetOrigin(this: v70, a2: 0);
  v72 = this->ai;
  v73 = v71[1];
  aligned = this->aligned;
  v75 = (float)(v71[2] + (float)55.0);
  v94[0] = *v71;
  v94[1] = v73;
  v94[2] = v75;
  v76 = v72->finalGoalPosition.y;
  z = v72->finalGoalPosition.z;
  v87 = v72->finalGoalPosition.x;
  v88 = v76;
  v89 = z;
  if ( aligned )
  {
    v78 = &idColor::colorGreen;
    v79 = idColor::colorGreen.r;
LABEL_63:
    r = v79;
    v80 = v78->b;
    v81 = v78->g;
    a = v78->a;
    b = v80;
    g = v81;
    goto LABEL_64;
  }
  if ( this->inRange )
  {
    v78 = &idColor::colorYellow;
    v79 = idColor::colorYellow.r;
    goto LABEL_63;
  }
LABEL_64:
  clientGame->renderWorld->DebugLine(
    this: clientGame->renderWorld,
    a2: (const idVec4 *)&r,
    a3: (const idVec3 *)v94,
    a4: (const idVec3 *)&v87,
    a5: 0,
    a6: false);
  v96[3] = 25.0;
  v96[2] = v89;
  v96[0] = v87;
  v96[1] = v88;
  clientGame->renderWorld->DebugSphere(
    this: clientGame->renderWorld,
    a2: (const idVec4 *)&r,
    a3: (const idSphere *)v96,
    a4: 12,
    a5: 0,
    a6: false);
}


// ========================================================================
// ?InternalWork@idVS_as_CircleShoot@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B25528
// RVA : 0x00B25528
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_CircleShoot::InternalWork(
        idVS_as_CircleShoot *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  idVehicleAI *ai; // r3
  idNavPathPosTracker *EnemyTracker; // r3
  idNavPathPosTracker *v8; // r3
  idVehicleAI *v9; // r11
  float rightDistance; // r7
  double distanceToFinalGoal; // fp11
  idNavPathPosTracker *v12; // r3
  idEntity *Owner; // r3
  idPhysics *Physics; // r3
  int v15; // r3
  idVehicleAI *v16; // r3
  float v17; // r4
  float v18; // r11
  float v19; // r10
  idVehicle_Car *v20; // r3
  idPhysics *v21; // r3
  float *v22; // r3
  double v23; // fp9
  double v24; // fp7
  double v25; // fp31
  double v26; // fp1
  idNavPathPosTracker *v27; // r3
  idEntity *v28; // r3
  idPhysics *v29; // r3
  int v30; // r3
  idVehicleAI *v31; // r3
  float v32; // r8
  float v33; // r7
  float v34; // r6
  idVehicle_Car *v35; // r3
  idPhysics *v36; // r3
  float *v37; // r3
  double roll; // fp31
  double yaw; // fp30
  double pitch; // fp29
  double v41; // fp12
  double v42; // fp10
  idVehicle_Car *v43; // r3
  idPhysics *v44; // r3
  float *v45; // r3
  double v46; // fp0
  int circle; // r11
  double v48; // fp12
  double v49; // fp11
  idVehicleAI *v50; // r10
  double v51; // fp28
  double v52; // fp28
  idNavPathPosTracker *v53; // r3
  double SplineWidth; // fp1
  idVehicleAI *v55; // r3
  double AttackRange; // fp28
  idVec3 *v57; // r3
  double v58; // fp10
  double v59; // fp9
  idVehicleAI *v60; // r11
  idNavPathPosTracker *v61; // r3
  idEntity *v62; // r3
  idPhysics *v63; // r30
  int value; // r9
  idVehicle_Car *v65; // r3
  idVehicle_Car *v66; // r3
  idPhysics *v67; // r29
  float *v68; // r30
  float *v69; // r3
  double v70; // fp10
  double v71; // fp8
  double v72; // fp30
  double v74; // fp29
  double v76; // fp1
  double v77; // fp11
  double v78; // fp28
  idVehicleAI *v79; // r11
  idEntity *Enemy; // r3
  idAngles v81; // [sp+50h] [-80h] BYREF
  idAngles v82; // [sp+60h] [-70h] BYREF
  idVec3 v83; // [sp+70h] [-60h] BYREF
  idVec3 v84; // [sp+80h] [-50h] BYREF

  if ( idVehicleAI::GetEnemyTracker(this: this->ai) != nullptr )
  {
    ai = this->ai;
    if ( this->driveTowardsEnemy )
    {
      EnemyTracker = idVehicleAI::GetEnemyTracker(this: ai);
      _FP12 = (float)((float)80.0 - (float)(idNavPathPosTracker::GetCurrentSpeedInMPH(this: EnemyTracker) + (float)15.0));
      __asm { fsel      f1, f12, f0, f13# speed }
      idVehicleAI::SetSpeedLimit(this: this->ai, speed: _FP1);
      v8 = idVehicleAI::GetEnemyTracker(this: this->ai);
      v9 = this->ai;
      rightDistance = v8->pathPosition.rightDistance;
      distanceToFinalGoal = v9->distanceToFinalGoal;
      v83.x = v8->pathPosition.distance;
      v83.y = rightDistance;
      if ( distanceToFinalGoal < 400.0 )
      {
        this->driveTowardsEnemy = false;
        v9->movementFSM.SetState_3(this: &v9->movementFSM, a2: &idVS_ms_MoveToGoal::Type, a3: 0, a4: false);
        v12 = idVehicleAI::GetEnemyTracker(this: this->ai);
        Owner = idNavPathPosTracker::GetOwner(this: v12);
        Physics = idEntity::GetPhysics(this: Owner);
        v15 = (int)Physics->GetOrigin(this: Physics, a2: 0);
        v17 = *(float *)v15;
        v18 = *(float *)(v15 + 4);
        v19 = *(float *)(v15 + 8);
        v16 = this->ai;
        v82.pitch = v17;
        v82.yaw = v18;
        v82.roll = v19;
        v20 = idVehicleAI::GetOwner(this: v16);
        v21 = idEntity::GetPhysics(this: v20);
        v22 = (float *)v21->GetOrigin(this: v21, a2: 0);
        v23 = (float)(v22[2] - v82.roll);
        v24 = (float)(v22[1] - v82.yaw);
        v84.x = *v22 - v82.pitch;
        v84.z = v23;
        v84.y = v24;
        this->startingYaw = idVec3::ToYaw(this: &v84);
        this->circle = 0;
        idVehicleAI::SetBeingAttackedTime(this: this->ai, msecs: 5000);
      }
      v25 = idVehicleAI::GetSplineTracker(this: this->ai)->pathPosition.rightDistance;
      v83.y = idVehicleAI::GetEnemyTracker(this: this->ai)->pathToGoal.rightDelta + (float)v25;
      idVehicleAI::MoveToPosition(
        this: (idVehicleAI *)LODWORD(v83.x),
        pathPos: (idNavSplinePosition *)LODWORD(v83.y),
        isStoppingGoal: false,
        passThroughGoal: 1u,
        a5: false);
    }
    else
    {
      if ( idVehicleAI::IsBeingAttacked(this: ai, lastAttackedTime: 1000, aggressiveTime: 15000) )
        v26 = 90.0;
      else
        v26 = 40.0;
      idVehicleAI::SetSpeedLimit(this: this->ai, speed: v26);
      v27 = idVehicleAI::GetEnemyTracker(this: this->ai);
      v28 = idNavPathPosTracker::GetOwner(this: v27);
      v29 = idEntity::GetPhysics(this: v28);
      v30 = (int)v29->GetOrigin(this: v29, a2: 0);
      v32 = *(float *)v30;
      v33 = *(float *)(v30 + 4);
      v34 = *(float *)(v30 + 8);
      v31 = this->ai;
      v82.pitch = v32;
      v82.yaw = v33;
      v82.roll = v34;
      v35 = idVehicleAI::GetOwner(this: v31);
      v36 = idEntity::GetPhysics(this: v35);
      v37 = (float *)v36->GetOrigin(this: v36, a2: 0);
      roll = v82.roll;
      yaw = v82.yaw;
      pitch = v82.pitch;
      v41 = (float)(v37[2] - v82.roll);
      v42 = (float)(v37[1] - v82.yaw);
      v81.pitch = *v37 - v82.pitch;
      v81.roll = v41;
      v81.yaw = v42;
      idVec3::ToAngles(this: &v83, result: &v81);
      v43 = idVehicleAI::GetOwner(this: this->ai);
      v44 = idEntity::GetPhysics(this: v43);
      v45 = (float *)v44->GetAxis(this: v44, a2: 0);
      if ( (float)((float)(v81.pitch * v45[3]) + (float)((float)(v45[5] * v81.roll) + (float)(v45[4] * v81.yaw))) <= 0.0 )
        v46 = (float)(v83.y + (float)10.0);
      else
        v46 = (float)(v83.y - (float)10.0);
      circle = this->circle;
      v48 = (float)((float)v46 - this->startingYaw);
      v83.y = v46;
      v49 = __fabs(v48);
      if ( circle <= 0 )
      {
        if ( v49 > 160.0 )
          this->circle = circle + 1;
      }
      else if ( v49 < 20.0 )
      {
        v50 = this->ai;
        this->circle = 0;
        ++v50->numAttackAttempts;
      }
      v51 = idVehicleAI::GetEnemyTracker(this: this->ai)->pathPosition.rightDistance;
      v52 = (float)(idVehicleAI::GetAttackRange(this: this->ai) + (float)v51);
      v53 = idVehicleAI::GetEnemyTracker(this: this->ai);
      SplineWidth = idNavPathPosTracker::GetSplineWidth(this: v53);
      v55 = this->ai;
      if ( v52 >= SplineWidth )
      {
        idVehicleAI::ChooseAttackState(this: v55);
      }
      else
      {
        AttackRange = idVehicleAI::GetAttackRange(this: v55);
        v57 = idAngles::ToForward(this: &v82, result: &v83);
        v58 = (float)(v57->y * (float)AttackRange);
        v59 = (float)(v57->z * (float)AttackRange);
        v60 = this->ai;
        v60->immediateGoalPosition.x = (float)(v57->x * (float)AttackRange) + (float)pitch;
        v60->immediateGoalPosition.y = (float)v58 + (float)yaw;
        v60->immediateGoalPosition.z = (float)v59 + (float)roll;
      }
      v61 = idVehicleAI::GetEnemyTracker(this: this->ai);
      v62 = idNavPathPosTracker::GetOwner(this: v61);
      v63 = idEntity::GetPhysics(this: v62);
      value = this->ai->vehicleCar.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v65 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v66 = idVehicle_Car::CastTo(c: v65);
      }
      else
      {
        v66 = nullptr;
      }
      v67 = idEntity::GetPhysics(this: v66);
      v68 = (float *)v63->GetOrigin(this: v63, a2: 0);
      v69 = (float *)v67->GetOrigin(this: v67, a2: 0);
      v70 = (float)(v69[1] - v68[1]);
      v71 = (float)(v69[2] - v68[2]);
      v72 = (float)((float)((float)(*v69 - *v68) * (float)(*v69 - *v68))
                  + (float)((float)((float)v71 * (float)v71) + (float)((float)v70 * (float)v70)));
      _FP3 = (float)((float)((float)((float)(*v69 - *v68) * (float)(*v69 - *v68))
                           + (float)((float)((float)v71 * (float)v71) + (float)((float)v70 * (float)v70)))
                   - idMath::FLT_SMALLEST_NON_DENORMAL);
      v74 = (float)((float)((float)((float)(*v69 - *v68) * (float)(*v69 - *v68))
                          + (float)((float)((float)v71 * (float)v71) + (float)((float)v70 * (float)v70)))
                  * (float)0.5);
      __asm { fsel      f2, f3, f30, f0 }
      v76 = __frsqrte(_FP2);
      v77 = (float)((float)-(float)((float)((float)((float)v76
                                                  * (float)((float)((float)((float)(*v69 - *v68) * (float)(*v69 - *v68))
                                                                  + (float)((float)((float)v71 * (float)v71)
                                                                          + (float)((float)v70 * (float)v70)))
                                                          * (float)0.5))
                                          * (float)v76)
                                  - (float)1.5)
                  * (float)v76);
      v78 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v76
                                                                                          * (float)((float)((float)((float)(*v69 - *v68) * (float)(*v69 - *v68)) + (float)((float)((float)v71 * (float)v71) + (float)((float)v70 * (float)v70)))
                                                                                                  * (float)0.5))
                                                                                  * (float)v76)
                                                                          - (float)1.5)
                                                          * (float)v76)
                                                  * (float)((float)((float)((float)(*v69 - *v68) * (float)(*v69 - *v68))
                                                                  + (float)((float)((float)v71 * (float)v71)
                                                                          + (float)((float)v70 * (float)v70)))
                                                          * (float)0.5))
                                          * (float)v77)
                                  - (float)1.5)
                  * (float)v77);
      if ( (float)((float)((float)-(float)((float)((float)((float)v78 * (float)v74) * (float)v78) - (float)1.5)
                         * (float)v78)
                 * (float)v72) > (double)(float)(idVehicleAI::GetAttackRange(this: this->ai) + (float)800.0) )
      {
        v79 = this->ai;
        this->driveTowardsEnemy = true;
        v79->movementFSM.SetState_3(this: &v79->movementFSM, a2: &idVS_ms_MoveToGoalOnSpline::Type, a3: 0, a4: false);
      }
      idVehicleAI::FireWeapon(this: this->ai);
    }
    Enemy = idVehicleAI::GetEnemy(this: this->ai);
    idVehicleAI::SetTarget(this: this->ai, entity: Enemy);
  }
}


// ========================================================================
// ?InternalWork@idVS_as_PowerTurnShoot@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B25AA8
// RVA : 0x00B25AA8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_PowerTurnShoot::InternalWork(
        idVS_as_PowerTurnShoot *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  idEntity *Enemy; // r3
  idNavPathPosTracker *SplineTracker; // r3
  idVehicleAI *ai; // r3
  float distance; // r9
  idNavSplinePosition *rightDistance_low; // r8
  idNavPathPosTracker *EnemyTracker; // r3
  double PathDistance; // fp23
  double rightDistance; // fp26
  double v12; // fp31
  double v13; // fp1
  double v14; // fp13
  idVehicleAI *v15; // r3
  double splineDistanceToFinalGoal; // fp31
  idNavPathPosTracker *v17; // r3
  idNavPathPosTracker *v18; // r3
  idNavPathPosTracker *v19; // r29
  idNavPathPosTracker *v20; // r3
  double MoveAheadDist; // fp1
  idVehicleAI *v22; // r3
  idNavPathPosTracker *v23; // r3
  idNavPathPosTracker *v24; // r3
  double Facing; // fp30
  idNavPathPosTracker *v26; // r29
  idNavPathPosTracker *v27; // r3
  idNavPathPosTracker *v28; // r3
  idNavPathPosTracker *v29; // r3
  idEntity *Owner; // r3
  idPhysics *Physics; // r3
  int value; // r9
  idVehicle_Car *v33; // r3
  idVehicle_Car *v34; // r3
  idPhysics *v35; // r28
  idNavPathPosTracker *v36; // r3
  idEntity *v37; // r3
  idPhysics *v38; // r27
  float *v39; // r28
  float *v40; // r3
  double v41; // fp31
  double v42; // fp30
  double v43; // fp29
  idVehicleAI *v44; // r10
  idNavPathPosTracker *v45; // r3
  idEntity *v46; // r3
  idPhysics *v47; // r3
  int v48; // r3
  idVehicleAI *v49; // r3
  bool v50; // zf
  idNavPathPosTracker *v51; // r3
  double v52; // fp31
  idNavPathPosTracker *v53; // r3
  int v54; // r8
  int v55; // r7
  int v56; // r6
  long double v57; // fp2
  __int64 v58; // r10
  idEntity *v59; // r3
  char v60; // r11
  int (*GetGameMs)(void); // ctr
  unsigned int v62; // r3
  unsigned int v63; // r28
  int v64; // r3
  float v65; // [sp+60h] [-F0h]
  float v66; // [sp+60h] [-F0h]
  float v67; // [sp+60h] [-F0h]
  float v68; // [sp+60h] [-F0h]
  idNavSplinePosition *v69; // [sp+64h] [-ECh]
  idNavSpline *navSpline; // [sp+68h] [-E8h]
  float v71[4]; // [sp+70h] [-E0h] BYREF
  float v72; // [sp+80h] [-D0h] BYREF
  idNavSplinePosition *v73; // [sp+84h] [-CCh]
  vaiControl_t v74; // [sp+90h] [-C0h] BYREF

  if ( idVehicleAI::GetEnemyTracker(this: this->ai) != nullptr )
  {
    ++this->ai->debugCount;
    Enemy = idVehicleAI::GetEnemy(this: this->ai);
    idVehicleAI::SetTarget(this: this->ai, entity: Enemy);
    SplineTracker = idVehicleAI::GetSplineTracker(this: this->ai);
    distance = SplineTracker->pathPosition.distance;
    rightDistance_low = (idNavSplinePosition *)LODWORD(SplineTracker->pathPosition.rightDistance);
    ai = this->ai;
    v72 = distance;
    v73 = rightDistance_low;
    EnemyTracker = idVehicleAI::GetEnemyTracker(this: ai);
    PathDistance = idNavSplinePathMgr::GetPathDistance(
                     this: (idNavSplinePathMgr *)&gameLocal->aiSplinePathMgr.trackerPool.trackers[-1].userPath[0].path.num,
                     start: v73,
                     end: *(idNavSplinePosition **)(LODWORD(v72) + 4),
                     forward: *(idVec3 **)(LODWORD(v72) + 8),
                     includeRightDistance: __ROL4__(EnemyTracker->pathPosition.navSpline, 32));
    rightDistance = idVehicleAI::GetSplineTracker(this: this->ai)->pathPosition.rightDistance;
    v12 = idVehicleAI::GetEnemyTracker(this: this->ai)->pathPosition.rightDistance;
    if ( this->ai->splineDistanceToFinalGoal < 1000.0 )
    {
      v13 = idVehicleAI::GetRightDistance(this: this->ai);
      v14 = __fabs((float)((float)v12 - (float)v13));
      if ( v14 > 400.0 )
      {
        if ( v12 <= v13 )
          rightDistance = (float)((float)v12 + (float)300.0);
        else
          rightDistance = (float)((float)v12 - (float)300.0);
      }
      if ( v14 < 200.0 )
      {
        if ( v12 <= v13 )
          rightDistance = (float)((float)v12 + (float)200.0);
        else
          rightDistance = (float)((float)v12 - (float)200.0);
      }
    }
    v15 = this->ai;
    splineDistanceToFinalGoal = v15->splineDistanceToFinalGoal;
    v17 = idVehicleAI::GetEnemyTracker(this: v15);
    v65 = v17->pathPosition.distance;
    navSpline = v17->pathPosition.navSpline;
    if ( this->mode == 1 )
    {
      v18 = idVehicleAI::GetEnemyTracker(this: this->ai);
      v66 = v65 - (float)(idNavPathPosTracker::GetFacing(this: v18) * (float)200.0);
      v19 = idVehicleAI::GetEnemyTracker(this: this->ai);
      v20 = idVehicleAI::GetSplineTracker(this: this->ai);
      MoveAheadDist = idNavPathPosTracker::GetMoveAheadDist(this: v20, otherTracker: v19);
      v22 = this->ai;
      v65 = v66 + (float)MoveAheadDist;
      if ( v22->splineDistanceToFinalGoal <= 2000.0 )
      {
        if ( splineDistanceToFinalGoal < 200.0 )
        {
          splineDistanceToFinalGoal = 2000.0;
          this->mode = 2;
        }
      }
      else
      {
        idVehicleAI::GetMaxSpeed(this: v22);
      }
    }
    if ( this->mode == 2 )
    {
      v23 = idVehicleAI::GetEnemyTracker(this: this->ai);
      v67 = v23->pathPosition.distance;
      navSpline = v23->pathPosition.navSpline;
      v24 = idVehicleAI::GetEnemyTracker(this: this->ai);
      Facing = idNavPathPosTracker::GetFacing(this: v24);
      v68 = (float)((float)Facing * idVehicleAI::GetAttackRange(this: this->ai)) + v67;
      v26 = idVehicleAI::GetEnemyTracker(this: this->ai);
      v27 = idVehicleAI::GetSplineTracker(this: this->ai);
      v65 = idNavPathPosTracker::GetMoveAheadDist(this: v27, otherTracker: v26) + v68;
      if ( splineDistanceToFinalGoal < 200.0 )
      {
        this->mode = 3;
        this->attackTime = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) + 4000;
      }
    }
    if ( this->mode == 3 )
    {
      v28 = idVehicleAI::GetEnemyTracker(this: this->ai);
      v65 = v28->pathPosition.distance;
      navSpline = v28->pathPosition.navSpline;
      v29 = idVehicleAI::GetEnemyTracker(this: this->ai);
      Owner = idNavPathPosTracker::GetOwner(this: v29);
      Physics = idEntity::GetPhysics(this: Owner);
      Physics->GetLinearVelocity(this: (idPhysics *)v71, result: (idVec3 *)Physics, a3: 0);
      value = this->ai->vehicleCar.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] != value >> 13 )
        goto LABEL_23;
      v33 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
      if ( v33 != nullptr )
        v34 = idVehicle_Car::CastTo(c: v33);
      else
LABEL_23:
        v34 = nullptr;
      v35 = idEntity::GetPhysics(this: v34);
      v36 = idVehicleAI::GetEnemyTracker(this: this->ai);
      v37 = idNavPathPosTracker::GetOwner(this: v36);
      v38 = idEntity::GetPhysics(this: v37);
      v39 = (float *)v35->GetOrigin(this: v35, a2: 0);
      v40 = (float *)v38->GetOrigin(this: v38, a2: 0);
      v41 = (float)(*v40 - *v39);
      v42 = (float)(v40[1] - v39[1]);
      v43 = (float)(v40[2] - v39[2]);
      if ( this->attackTime < gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED)
        || (float)((float)(v71[0] * (float)v41) + (float)((float)(v71[2] * (float)v43) + (float)(v71[1] * (float)v42))) > 0.0
        && PathDistance > 200.0 )
      {
        v44 = this->ai;
        this->mode = 1;
        ++v44->numAttackAttempts;
      }
    }
    v45 = idVehicleAI::GetEnemyTracker(this: this->ai);
    v46 = idNavPathPosTracker::GetOwner(this: v45);
    v47 = idEntity::GetPhysics(this: v46);
    v48 = (int)v47->GetLinearVelocity(this: (idPhysics *)&v72, result: (idVec3 *)v47, a3: 0);
    idNavSplinePosition::Validate(this: *(idNavSplinePosition **)v48, velocity: *(idVec3 **)(v48 + 4));
    *(float *)&v69 = rightDistance;
    idVehicleAI::MoveToPosition(
      this: (idVehicleAI *)LODWORD(v65),
      pathPos: v69,
      isStoppingGoal: __ROL4__(navSpline, 32),
      passThroughGoal: 1u,
      a5: false);
    v50 = !idVehicleAI::IsBeingAttacked(this: this->ai, lastAttackedTime: 1000, aggressiveTime: 15000);
    v49 = this->ai;
    if ( v50 )
    {
      v53 = idVehicleAI::GetEnemyTracker(this: v49);
      v52 = (float)(idNavPathPosTracker::GetCurrentSpeedInMPH(this: v53) + (float)50.0);
    }
    else
    {
      v51 = idVehicleAI::GetEnemyTracker(this: v49);
      v52 = (float)(idNavPathPosTracker::GetCurrentSpeedInMPH(this: v51) + (float)80.0);
    }
    idVehicleAI::SetSpeedLimit(this: this->ai, speed: v52);
    LODWORD(v58) = &off_82040000;
    HIDWORD(v58) = 0x82000000;
    v74.avoidanceType = OAT_INIT;
    v74.powerTurnTime = -1;
    v74.speedLimit = -1.0;
    v74.maxCurveAngle = -1.0;
    v74.maxStepAngle = -1.0;
    v74.powerTurnSpeed = -1.0;
    v74.stopPowerTurnSpeed = -1.0;
    v74.traversalStepSize = -1.0;
    v74.backupSpeed = -1.0;
    v74.maxCurveCosine = -1.0;
    v74.maxStepCosine = -1.0;
    if ( v52 >= 40.0 )
    {
      v74.maxCurveCosine = 0.0;
      v74.maxCurveSpeed = 80.0;
      v74.stopDistance = 100.0;
      v74.decelDistance = 100.0;
      v74.moveDistance = 100.0;
    }
    else
    {
      v74.stopDistance = 400.0;
      LODWORD(v58) = &unk_821F0000;
      v74.decelDistance = 2000.0;
      v74.maxCurveSpeed = 65.0;
      v74.moveDistance = 800.0;
    }
    idVehicleAI::UpdateControlParams(
      this: this->ai,
      params: &v74,
      initialize: false,
      a4: v57,
      a5: v56,
      a6: v55,
      a7: v54,
      a8: v58);
    v59 = idVehicleAI::GetEnemy(this: this->ai);
    idVehicleAI::SetTarget(this: this->ai, entity: v59);
    v60 = 0;
    if ( this->mode == 3 || PathDistance < 500.0 )
      v60 = 1;
    if ( v60 != 0 && this->shootTime == 0 )
    {
      GetGameMs = (int (*)(void))gameLocal->GetGameMs;
      if ( this->delayTime != 0 )
      {
        if ( this->delayTime < GetGameMs() )
        {
          v62 = 1664525 * clientGame->random.seed + 1013904223;
          clientGame->random.seed = v62;
          v63 = ((v62 >> 10) & 0x7FFF) % 0x5DC;
          v64 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
          this->delayTime = 0;
          this->shootTime = v64 + v63 + 500;
        }
      }
      else
      {
        this->delayTime = GetGameMs() + 500;
      }
    }
    if ( this->shootTime != 0 )
    {
      if ( this->shootTime <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) )
        this->shootTime = 0;
      idVehicleAI::FireWeapon(this: this->ai);
    }
  }
}


// ========================================================================
// ?InternalWork@idVS_as_ForcedRetreat@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B26188
// RVA : 0x00B26188
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_ForcedRetreat::InternalWork(
        idVS_as_ForcedRetreat *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  int value; // r9
  idVehicle_Car *v5; // r3
  int v6; // r9
  bool v7; // r8
  idVehicleAI *ai; // r11
  __int64 v9; // r6
  int navSpline; // r10
  idEntity *Enemy; // r3
  double v12; // fp1
  idVehicle_Car *EnemyVehicle; // r3
  idVehicle_Car *v14; // r3
  idVehicleAI *v15; // r3
  idPhysics *Physics; // r3
  float *v17; // r3
  idVehicleAI *v18; // r11
  double v19; // fp13
  double v20; // fp12
  float distance; // r6
  float rightDistance; // r5
  float v23; // r11
  idVec3 *WorldPos; // r3
  double y; // fp9
  double x; // fp13
  double v27; // fp8
  idVehicleAI *v28; // r11
  bool v29; // r29
  int v30; // r9
  idVehicle_Car *v31; // r3
  idVehicle_Car *v32; // r3
  idPresentable *presentable; // r3
  int v34; // r3
  idVehicleAI *v35; // r4
  idEventArg *v36; // r3
  idVehicle_Car *VehicleCar; // r3
  int v38; // [sp+8h] [-118h]
  __int64 v39; // [sp+10h] [-110h]
  __int64 v40; // [sp+18h] [-108h]
  __int64 v41; // [sp+20h] [-100h]
  __int64 v42; // [sp+28h] [-F8h]
  __int64 v43; // [sp+30h] [-F0h]
  idVec3 v44; // [sp+50h] [-D0h] BYREF
  float v45[4]; // [sp+60h] [-C0h] BYREF
  float v46[4]; // [sp+70h] [-B0h] BYREF
  char v47; // [sp+80h] [-A0h] BYREF
  float v48; // [sp+84h] [-9Ch]
  char v49; // [sp+90h] [-90h] BYREF
  float v50; // [sp+94h] [-8Ch]
  idEventArg v51; // [sp+A0h] [-80h] BYREF
  float v52[4]; // [sp+C0h] [-60h] BYREF
  float v53[4]; // [sp+D0h] [-50h] BYREF
  float v54[6]; // [sp+E0h] [-40h] BYREF

  value = this->ai->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr
    && idVehicle_Car::CastTo(c: v5) != nullptr )
  {
    ai = this->ai;
    LODWORD(v9) = 0;
    navSpline = (int)ai->startingPathPosition.navSpline;
    HIDWORD(v9) = __ROL4__(navSpline, 32);
    idVehicleAI::MoveToPathPosition(
      this: (idVehicleAI *)LODWORD(ai->startingPathPosition.distance),
      isStoppingGoal: v9,
      passThroughGoal: false,
      a4: v7,
      a5: v6,
      a6: navSpline,
      a7: v38,
      a8: v39,
      a9: v40,
      a10: v41,
      a11: v42,
      a12: v43);
    Enemy = idVehicleAI::GetEnemy(this: this->ai);
    idVehicleAI::SetTarget(this: this->ai, entity: Enemy);
    idVehicleAI::GetTargetAngles(this: (idVehicleAI *)&v47, result: (idAngles *)this->ai);
    idVehicleAI::GetWeaponAngles(this: (idVehicleAI *)&v49, result: (idAngles *)this->ai);
    v12 = idMath::AngleNormalize360(angle: (float)(v48 - v50));
    if ( v12 > 180.0 )
      v12 = (float)((float)v12 - (float)360.0);
    if ( __fabs(v12) < 50.0 && (unsigned __int8)idVehicleAI::FireWeapon(this: this->ai) != 0 )
    {
      EnemyVehicle = (idVehicle_Car *)idVehicleAI::GetEnemyVehicle(this: this->ai);
      v14 = idVehicle_Car::CastTo(c: EnemyVehicle);
      if ( v14 != nullptr )
        idVehicle_Car::PingAttack(this: v14);
    }
    if ( vai_debug_attackstate_draw.valueInteger != 0 )
    {
      v15 = this->ai;
      v52[0] = idColor::colorPink.r;
      v52[1] = idColor::colorPink.g;
      v52[2] = idColor::colorPink.b;
      v52[3] = idColor::colorPink.a;
      Physics = idEntity::GetPhysics(this: v15);
      v17 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v18 = this->ai;
      v19 = v17[1];
      v20 = (float)(v17[2] + (float)50.0);
      v46[0] = *v17;
      v46[1] = v19;
      v46[2] = v20;
      distance = v18->startingPathPosition.distance;
      rightDistance = v18->startingPathPosition.rightDistance;
      v23 = *(float *)&v18->startingPathPosition.navSpline;
      v44.x = distance;
      v44.y = rightDistance;
      v44.z = v23;
      WorldPos = idNavSplinePosition::GetWorldPos(this: (idNavSplinePosition *)&v51, result: &v44);
      y = WorldPos->y;
      x = WorldPos->x;
      v27 = (float)(WorldPos->z + (float)45.0);
      v45[1] = WorldPos->y;
      v45[0] = x;
      v53[1] = y;
      v53[3] = 25.0;
      v45[2] = v27;
      v53[2] = v27;
      v53[0] = x;
      clientGame->renderWorld->DebugSphere(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)v52,
        a3: (const idSphere *)v53,
        a4: 12,
        a5: 0,
        a6: false);
      v54[0] = idColor::colorRed.r;
      v54[1] = idColor::colorRed.g;
      v54[2] = idColor::colorRed.b;
      v54[3] = idColor::colorRed.a;
      ((void (__fastcall *)(idRenderWorld *, float *, float *, float *, double))clientGame->renderWorld->DebugArrow)(
        a1: clientGame->renderWorld,
        a2: v54,
        a3: v46,
        a4: v45,
        a5: 20.0);
    }
    v28 = this->ai;
    v29 = false;
    if ( v28->hideWhenIdle )
      v29 = v28->distanceToFinalGoal <= 500.0;
    v30 = v28->vehicleCar.spawnId.value;
    if ( gameLocal->spawnIds.ptr[v30 & 0x1FFF] == v30 >> 13
      && (v31 = (idVehicle_Car *)gameLocal->entities.ptr[v30 & 0x1FFF]) != nullptr )
    {
      v32 = idVehicle_Car::CastTo(c: v31);
    }
    else
    {
      v32 = nullptr;
    }
    presentable = v32->presentable;
    if ( presentable != nullptr )
      v34 = (int)presentable->GetVehicleInterface(this: presentable);
    else
      v34 = 0;
    if ( (*(_BYTE *)(v34 + 20320) & 1) != 0 )
      v29 = true;
    if ( v29 )
    {
      v35 = this->ai;
      if ( (v35->thinkFlags & 1) != 0 )
      {
        v36 = idEventArg::idEventArg(this: &v51, data: v35);
        idEventReceiver::PostEventMS(
          this: this->ai,
          ev: &EV_Activate,
          time: *(_DWORD *)&v36->type,
          arg1: (const idEventArg *)LODWORD(v36->value.v[1]));
        VehicleCar = idVehicleAI::GetVehicleCar(this: this->ai);
        VehicleCar->Hide_2(this: VehicleCar);
      }
    }
  }
  else
  {
    idStr::operator=(this: &this->debugInfo, text: "bad");
  }
}


// ========================================================================
// ?InternalWork@idVS_as_FireWeapon@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B26540
// RVA : 0x00B26540
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_FireWeapon::InternalWork(
        idVS_as_FireWeapon *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  int value; // r9
  idVehicle_Car *v5; // r3
  idVehicle_Car *v6; // r3
  idVehicleAI *ai; // r11
  idVehicle_Car *Enemy; // r3
  idVehicle_Car *v9; // r3

  value = this->ai->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v6 = idVehicle_Car::CastTo(c: v5);
  }
  else
  {
    v6 = nullptr;
  }
  v6->hasInfiniteAmmo = true;
  this->ai->ignoreEngageEnemy = true;
  if ( this->endTime > 0 && gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) >= this->endTime )
  {
    this->ai->attackFSM.SetState_3(this: &this->ai->attackFSM, a2: &idVS_Idle::Type, a3: 0, a4: false);
    idVehicleAI::SetEnemy(this: this->ai, enemy: nullptr);
    idVehicleAI::SetTarget(this: this->ai, entity: nullptr);
  }
  ai = this->ai;
  if ( ai->decisionFSM.curState == &ai->ds_Patrol )
    idVehicleAI::UpdatePatrolPath(this: ai);
  Enemy = (idVehicle_Car *)idVehicleAI::GetEnemy(this: this->ai);
  v9 = idVehicle_Car::CastTo(c: Enemy);
  if ( v9 != nullptr )
  {
    if ( ((double (__fastcall *)(idVehicle_Car *))v9->GetHealth)(a1: v9) <= 0.0 )
      return;
  }
  else if ( idVehicleAI::GetEnemy(this: this->ai) == nullptr )
  {
    return;
  }
  idVehicleAI::FireWeapon(this: this->ai);
}


// ========================================================================
// ?InternalEnterState@idVS_as_Bypass@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B266A8
// RVA : 0x00B266A8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_Bypass::InternalEnterState(
        idVS_as_Bypass *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  idVehicleAI *ai; // r11
  int value; // r9
  idVehicle_Car *v6; // r3
  int v7; // r9
  idVehicle_Car *v8; // r3
  idVehicle_Car *v9; // r3

  ai = this->ai;
  this->state = ST_INIT;
  value = ai->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v6 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v6 != nullptr && idVehicle_Car::CastTo(c: v6) != nullptr )
    {
      v7 = this->ai->vehicleCar.spawnId.value;
      if ( gameLocal->spawnIds.ptr[v7 & 0x1FFF] == v7 >> 13
        && (v8 = (idVehicle_Car *)gameLocal->entities.ptr[v7 & 0x1FFF]) != nullptr )
      {
        v9 = idVehicle_Car::CastTo(c: v8);
      }
      else
      {
        v9 = nullptr;
      }
      v9->hasInfiniteAmmo = true;
    }
  }
}


// ========================================================================
// ?AssignFollowing@idVS_ds_Group_FollowLeader@@QAAXXZ
// EA  : 0x82B26780
// RVA : 0x00B26780
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_ds_Group_FollowLeader::AssignFollowing(idVS_ds_Group_FollowLeader *this)
{
  int num; // r11
  int v3; // r30
  int v4; // r31
  int value; // r9
  idVehicleAI *v6; // r3
  idVehicleAI *v7; // r3
  idVehicleAI *ai; // r26
  int v9; // r24
  idPhysics *Physics; // r3
  float *v11; // r3
  double v12; // fp31
  int v13; // r28
  int v14; // r30
  idGameLocal *v15; // r11
  int v16; // r31
  int v17; // r9
  idVehicleAI *v18; // r3
  idVehicleAI *v19; // r3
  int v20; // r9
  idVehicleAI *v21; // r3
  idVehicleAI *v22; // r3
  idPhysics *v23; // r3
  float *v24; // r3
  int v25; // r9
  idVehicleAI *v26; // r3
  idVehicleAI *v27; // r3
  int v28; // r9
  idVehicleAI *v29; // r3
  float v30; // [sp+50h] [-80h]
  float v31; // [sp+54h] [-7Ch]
  float v32; // [sp+58h] [-78h]

  this->following.spawnId.value = 0x1FFF;
  num = this->others.num;
  v3 = 0;
  if ( num > 0 )
  {
    v4 = 0;
    do
    {
      value = this->others.list[v4].spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v6 = (idVehicleAI *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v7 = idVehicleAI::CastTo(c: v6);
      }
      else
      {
        v7 = nullptr;
      }
      ++v3;
      v7->ds_Group_FollowLeader.following.spawnId.value = 0x1FFF;
      num = this->others.num;
      ++v4;
    }
    while ( v3 < num );
  }
  ai = this->ai;
  v9 = 0;
  if ( num > 0 )
  {
    do
    {
      Physics = idEntity::GetPhysics(this: this->ai);
      v11 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v12 = 1.0e30;
      v13 = -1;
      v14 = 0;
      v15 = gameLocal;
      v30 = *v11;
      v31 = v11[1];
      v32 = v11[2];
      if ( this->others.num > 0 )
      {
        v16 = 0;
        do
        {
          v17 = this->others.list[v16].spawnId.value;
          if ( v15->spawnIds.ptr[v17 & 0x1FFF] == v17 >> 13
            && (v18 = (idVehicleAI *)v15->entities.ptr[v17 & 0x1FFF]) != nullptr )
          {
            v19 = idVehicleAI::CastTo(c: v18);
            v15 = gameLocal;
          }
          else
          {
            v19 = nullptr;
          }
          if ( v15->spawnIds.ptr[v19->ds_Group_FollowLeader.following.spawnId.value & 0x1FFF] != v19->ds_Group_FollowLeader.following.spawnId.value >> 13 )
          {
            v20 = this->others.list[v16].spawnId.value;
            if ( v15->spawnIds.ptr[v20 & 0x1FFF] == v20 >> 13
              && (v21 = (idVehicleAI *)v15->entities.ptr[v20 & 0x1FFF]) != nullptr )
            {
              v22 = idVehicleAI::CastTo(c: v21);
            }
            else
            {
              v22 = nullptr;
            }
            v23 = idEntity::GetPhysics(this: v22);
            v24 = (float *)v23->GetOrigin(this: v23, a2: 0);
            v15 = gameLocal;
            if ( (float)((float)((float)(*v24 - v30) * (float)(*v24 - v30))
                       + (float)((float)((float)(v24[2] - v32) * (float)(v24[2] - v32))
                               + (float)((float)(v24[1] - v31) * (float)(v24[1] - v31)))) < v12 )
            {
              v12 = (float)((float)((float)(*v24 - v30) * (float)(*v24 - v30))
                          + (float)((float)((float)(v24[2] - v32) * (float)(v24[2] - v32))
                                  + (float)((float)(v24[1] - v31) * (float)(v24[1] - v31))));
              v13 = v14;
            }
          }
          ++v14;
          ++v16;
        }
        while ( v14 < this->others.num );
      }
      v25 = this->others.list[v13].spawnId.value;
      if ( v15->spawnIds.ptr[v25 & 0x1FFF] == v25 >> 13
        && (v26 = (idVehicleAI *)v15->entities.ptr[this->others.list[v13].spawnId.value & 0x1FFF]) != nullptr )
      {
        v27 = idVehicleAI::CastTo(c: v26);
        v15 = gameLocal;
      }
      else
      {
        v27 = nullptr;
      }
      if ( ai != nullptr )
        v27->ds_Group_FollowLeader.following.spawnId.value = (v15->spawnIds.ptr[ai->entityNumber] << 13)
                                                           | ai->entityNumber;
      else
        v27->ds_Group_FollowLeader.following.spawnId.value = 0x1FFF;
      v28 = this->others.list[v13].spawnId.value;
      if ( gameLocal->spawnIds.ptr[v28 & 0x1FFF] == v28 >> 13
        && (v29 = (idVehicleAI *)gameLocal->entities.ptr[this->others.list[v13].spawnId.value & 0x1FFF]) != nullptr )
      {
        ai = idVehicleAI::CastTo(c: v29);
      }
      else
      {
        ai = nullptr;
      }
      ++v9;
    }
    while ( v9 < this->others.num );
  }
}


// ========================================================================
// ?ActivateWayPoint@idVS_ds_Car_Chase@@QAAXXZ
// EA  : 0x82B27188
// RVA : 0x00B27188
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_ds_Car_Chase::ActivateWayPoint(idVS_ds_Car_Chase *this)
{
  idSplineWaypoint *currentWayPoint; // r11
  int num; // r27
  int v4; // r29
  int v5; // r30
  idSplineWaypoint *v6; // r11
  int value; // r9
  idEntity *v8; // r3
  idEntity *v9; // r31

  currentWayPoint = this->currentWayPoint;
  if ( currentWayPoint != nullptr )
  {
    num = currentWayPoint->targets.num;
    v4 = 0;
    if ( num > 0 )
    {
      v5 = 0;
      do
      {
        v6 = this->currentWayPoint;
        if ( v4 < v6->targets.num
          && (value = v6->targets.list[v5].spawnId.value, gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
          && (v8 = gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
        {
          v9 = idEntity::CastTo(c: v8);
        }
        else
        {
          v9 = nullptr;
        }
        if ( v9 != nullptr
          && (unsigned __int8)idSplineWaypoint::IsTypeOf(c: v9) == 0
          && (unsigned __int8)idAISplinePath::IsTypeOf(c: v9) == 0 )
        {
          idEntity::Activate(this: v9, activator: this->ai);
        }
        ++v4;
        ++v5;
      }
      while ( v4 < num );
    }
  }
}


// ========================================================================
// ?GetEnemySplineStatus@idVS_ds_Car_Chase@@QAAXXZ
// EA  : 0x82B27270
// RVA : 0x00B27270
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_ds_Car_Chase::GetEnemySplineStatus(idVS_ds_Car_Chase *this)
{
  idNavSplinePath *splinePath; // r29
  idNavSplinePath *v3; // r28
  int v4; // r27
  int v5; // r30
  int v6; // r31
  idNavSplinePath *v7; // r3
  idNavSplinePath *v8; // r3
  int num; // r30
  int v10; // r31
  idNavSplinePath *Target; // r3
  idNavSplinePath *v12; // r3
  float distance; // [sp+50h] [-50h]

  if ( idVehicleAI::GetEnemy(this: this->ai) != nullptr )
  {
    splinePath = idVehicleAI::GetSplineTracker(this: this->ai)->pathPosition.navSpline->splinePath;
    v3 = idVehicleAI::GetEnemyTracker(this: this->ai)->pathPosition.navSpline->splinePath;
    if ( v3 != nullptr
      && (*(_BYTE *)&v3->splineFlags & 0x80) != 0
      && splinePath != nullptr
      && (*(_BYTE *)&splinePath->splineFlags & 0x80) != 0 )
    {
      if ( splinePath == v3 )
      {
        distance = idVehicleAI::GetSplineTracker(this: this->ai)->pathPosition.distance;
        if ( distance >= (double)idVehicleAI::GetEnemyTracker(this: this->ai)->pathPosition.distance )
          this->enemySplineStatus = ENEMY_SPLINE_STATUS_BEHIND;
        else
LABEL_8:
          this->enemySplineStatus = ENEMY_SPLINE_STATUS_IN_FRONT;
      }
      else
      {
        v4 = 0;
        if ( this->enemySplineStatus != ENEMY_SPLINE_STATUS_BEHIND )
        {
          while ( v4 <= 20 )
          {
            num = splinePath->targets.num;
            ++v4;
            if ( num <= 0 )
              break;
            v10 = 0;
            while ( 1 )
            {
              Target = (idNavSplinePath *)idEntity::GetTarget(this: splinePath, i: v10);
              v12 = idNavSplinePath::CastTo(c: Target);
              if ( v12 != nullptr )
                break;
              if ( ++v10 >= num )
              {
                this->enemySplineStatus = ENEMY_SPLINE_STATUS_BEHIND;
                return;
              }
            }
            if ( v12 == v3 )
              goto LABEL_8;
            splinePath = v12;
          }
LABEL_20:
          this->enemySplineStatus = ENEMY_SPLINE_STATUS_BEHIND;
        }
        else
        {
          while ( v4 <= 20 )
          {
            v5 = v3->targets.num;
            ++v4;
            if ( v5 <= 0 )
              goto LABEL_8;
            v6 = 0;
            while ( 1 )
            {
              v7 = (idNavSplinePath *)idEntity::GetTarget(this: v3, i: v6);
              v8 = idNavSplinePath::CastTo(c: v7);
              if ( v8 != nullptr )
                break;
              if ( ++v6 >= v5 )
              {
                this->enemySplineStatus = ENEMY_SPLINE_STATUS_IN_FRONT;
                return;
              }
            }
            if ( v8 == splinePath )
              goto LABEL_20;
            v3 = v8;
          }
          idLib::Warning(
            fmt: "idVS_ds_Car_Chase::GetEnemySplineStatus, exceeded the amount of allowed splines to check. Setting status to unknown.");
          this->enemySplineStatus = ENEMY_SPLINE_STATUS_UNKNOWN;
        }
      }
    }
    else
    {
      this->enemySplineStatus = ENEMY_SPLINE_STATUS_UNKNOWN;
    }
  }
}


// ========================================================================
// ?SetPhysics@idVS_ds_Car_Chase@@QAAX_N@Z
// EA  : 0x82B27468
// RVA : 0x00B27468
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_ds_Car_Chase::SetPhysics(idVS_ds_Car_Chase *this, bool physicsOn)
{
  int value; // r9
  idVehicle_Car *v4; // r3
  idVehicle_Car *v5; // r3
  idEntity *v6; // r31
  idPhysics *Physics; // r3
  idPhysics *v8; // r3
  int v9; // r4

  value = this->ai->vehicleCar.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13 )
  {
    v4 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF];
    if ( v4 != nullptr )
    {
      v5 = idVehicle_Car::CastTo(c: v4);
      v6 = v5;
      if ( v5 != nullptr )
      {
        Physics = idEntity::GetPhysics(this: v5);
        if ( physicsOn )
        {
          Physics->SetClipMask(this: Physics, a2: 107553, a3: -1);
          v8 = idEntity::GetPhysics(this: v6);
          v9 = 0x10000;
        }
        else
        {
          Physics->SetClipMask(this: Physics, a2: 0, a3: -1);
          v8 = idEntity::GetPhysics(this: v6);
          v9 = 0;
        }
        v8->SetContents(this: v8, a2: v9, a3: -1);
      }
    }
  }
}


// ========================================================================
// ?SetMoveAwayPos@idVS_as_RAM@@QAAXXZ
// EA  : 0x82B27568
// RVA : 0x00B27568
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_RAM::SetMoveAwayPos(idVS_as_RAM *this)
{
  __int64 v2; // r9
  unsigned int v3; // r4
  idVehicleAI *ai; // r3
  double v5; // fp30
  idNavPathPosTracker *EnemyTracker; // r3
  float distance; // r7
  float rightDistance; // r6
  idNavSpline *navSpline; // r21
  idNavSpline *v10; // r28
  idNavPathPosTracker *SplineTracker; // r3
  double FacingDir; // fp28
  navSplinePathNode_t *startNode; // r30
  int v14; // r20
  idPhysics *Physics; // r3
  float *v16; // r3
  double v17; // fp10
  double v18; // fp6
  double v19; // fp31
  idPhysics *v20; // r3
  float *v21; // r3
  double v22; // fp12
  double v23; // fp8
  int num; // r11
  int v26; // r29
  double v28; // fp10
  double v29; // fp31
  int v30; // r11
  idNavSpline *v31; // r3
  int v32; // r11
  int v33; // r10
  idNavPathPosTracker *v34; // r3
  double dir; // fp12
  __int64 v36; // r6
  int v37; // r10
  int v38; // r9
  bool v39; // r8
  __int64 v40; // r6
  int v41; // r10
  int v42; // r9
  bool v43; // r8
  idClientGame *v44; // r11
  unsigned int v45; // r6
  encounterGroupRole_t *list; // r5
  navSplineLink_t *v47; // r10
  int v48; // r3
  int v49; // r11
  int v50; // r3
  unsigned int v51; // r11
  int v52; // r11
  idNavSpline *v53; // r10
  __int64 v54; // r6
  int v55; // r10
  bool v56; // r8
  idNavSpline *v57; // r10
  __int64 v58; // r6
  int v59; // r10
  bool v60; // r8
  int v61; // [sp+8h] [-178h]
  __int64 v62; // [sp+10h] [-170h]
  __int64 v63; // [sp+18h] [-168h]
  __int64 v64; // [sp+20h] [-160h]
  __int64 v65; // [sp+28h] [-158h]
  __int64 v66; // [sp+30h] [-150h]
  _QWORD v67[2]; // [sp+50h] [-130h] BYREF
  idNavSplinePosition v68; // [sp+60h] [-120h] BYREF
  idNavSplinePosition v69; // [sp+70h] [-110h] BYREF
  idNavSplinePosition v70; // [sp+80h] [-100h] BYREF
  float v71; // [sp+90h] [-F0h]
  float v72; // [sp+94h] [-ECh]
  idNavSplinePosition v73; // [sp+A0h] [-E0h] BYREF
  idList<enum encounterGroupRole_t,5> v74; // [sp+B0h] [-D0h] BYREF
  int v75; // [sp+C0h] [-C0h] BYREF

  HIDWORD(v2) = 0x82000000;
  v3 = 1664525 * clientGame->random.seed;
  clientGame->random.seed = v3 + 1013904223;
  ai = this->ai;
  LODWORD(v2) = ((v3 + 1013904223) >> 10) & 0x7FFF;
  v67[1] = v2;
  v5 = (float)((float)((float)((float)((float)v2 * (float)0.000061037019) - (float)1.0) * (float)750.0) + (float)2500.0);
  EnemyTracker = idVehicleAI::GetEnemyTracker(this: ai);
  distance = EnemyTracker->pathPosition.distance;
  rightDistance = EnemyTracker->pathPosition.rightDistance;
  navSpline = EnemyTracker->pathPosition.navSpline;
  v74.size = 5;
  v74.num = 0;
  v71 = distance;
  v72 = rightDistance;
  v74.granularity = 1;
  v74.list = (encounterGroupRole_t *)&v75;
  v74.memTag = 5;
  v74.listStatic = 1;
  v10 = idVehicleAI::GetSplineTracker(this: this->ai)->pathPosition.navSpline;
  SplineTracker = idVehicleAI::GetSplineTracker(this: this->ai);
  FacingDir = idNavPathPosTracker::GetFacingDir(this: SplineTracker);
  if ( FacingDir <= 0.0 )
    startNode = v10->startNode;
  else
    startNode = v10->endNode;
  v14 = 0;
  while ( 1 )
  {
    if ( startNode == nullptr )
    {
      startNode = v10->startNode;
      if ( startNode == nullptr )
        startNode = v10->endNode;
      goto LABEL_18;
    }
    Physics = idEntity::GetPhysics(this: this->ai);
    v16 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v17 = (float)(v16[1] - startNode->position.y);
    v18 = (float)(v16[2] - startNode->position.z);
    v19 = (float)((float)((float)v18 * (float)v18)
                + (float)((float)((float)(*v16 - startNode->position.x) * (float)(*v16 - startNode->position.x))
                        + (float)((float)v17 * (float)v17)));
    v20 = idEntity::GetPhysics(this: this->ai);
    v21 = (float *)v20->GetOrigin(this: v20, a2: 0);
    v22 = (float)(v21[1] - startNode->position.y);
    v23 = (float)(v21[2] - startNode->position.z);
    if ( (float)((float)((float)v23 * (float)v23)
               + (float)((float)((float)(*v21 - startNode->position.x) * (float)(*v21 - startNode->position.x))
                       + (float)((float)v22 * (float)v22))) > (double)(float)((float)v5 * (float)v5) )
    {
      v70.navSpline = navSpline;
      v70.rightDistance = v72;
      v70.distance = -(float)((float)((float)FacingDir * (float)v5) - v71);
      idNavSplinePosition::Validate(this: &v70, nextSpline: nullptr, prevSpline: nullptr);
      LODWORD(v40) = 1;
      HIDWORD(v40) = __ROL4__(v70.navSpline, 32);
      idVehicleAI::MoveToPathPosition(
        this: (idVehicleAI *)LODWORD(v70.distance),
        isStoppingGoal: v40,
        passThroughGoal: false,
        a4: v43,
        a5: v42,
        a6: v41,
        a7: v61,
        a8: v62,
        a9: v63,
        a10: v64,
        a11: v65,
        a12: v66);
      goto LABEL_20;
    }
    _FP12 = (float)((float)v19 - idMath::FLT_SMALLEST_NON_DENORMAL);
    num = startNode->links.num;
    v26 = 0;
    HIDWORD(v67[0]) = 0;
    __asm { fsel      f11, f12, f31, f0 }
    v28 = __frsqrte(_FP11);
    v29 = (float)-(float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v28 * (float)((float)v19 * (float)0.5)) * (float)v28)
                                                                                                - (float)1.5)
                                                                                * (float)v28)
                                                                        * (float)((float)v19 * (float)0.5))
                                                                * (float)((float)-(float)((float)((float)((float)v28 * (float)((float)v19 * (float)0.5))
                                                                                                * (float)v28)
                                                                                        - (float)1.5)
                                                                        * (float)v28))
                                                        - (float)1.5)
                                        * (float)((float)-(float)((float)((float)((float)v28
                                                                                * (float)((float)v19 * (float)0.5))
                                                                        * (float)v28)
                                                                - (float)1.5)
                                                * (float)v28))
                                * (float)v19)
                        - (float)v5);
    if ( num > 0 )
    {
      do
      {
        v30 = (int)&startNode->links.list[v26];
        if ( *(idNavSpline **)(v30 + 8) != v10 )
        {
          v31 = *(idNavSpline **)(v30 + 8);
          HIDWORD(v67[1]) = &startNode->links.list[v26];
          if ( !idNavSpline::IsDeadEnd(this: v31) )
            idList<idAnimWebBlendTree *,5>::Append(this: &v74, obj: (const encounterGroupRole_t *)v67);
        }
        v32 = startNode->links.num;
        HIDWORD(v67[0]) = ++v26;
      }
      while ( v26 < v32 );
    }
    v33 = v74.num;
    if ( v74.num > 0 )
      break;
    if ( startNode == v10->startNode )
      startNode = v10->endNode;
    else
      startNode = v10->startNode;
LABEL_18:
    ++v14;
    FacingDir = (float)((float)FacingDir * (float)-1.0);
    if ( v14 >= 2 )
    {
      idLib::Warning(fmt: "Could not find a move to point in idVS_as_RAM::SetMoveAwayPos, doing it the old way");
      v34 = idVehicleAI::GetSplineTracker(this: this->ai);
      HIDWORD(v67[1]) = &v34->pathToGoal;
      dir = v34->pathToGoal.path.list[v34->pathToGoal.path.num - 1].dir;
      v73.navSpline = navSpline;
      v73.rightDistance = v72;
      v73.distance = v71 - (float)((float)dir * (float)v5);
      idNavSplinePosition::Validate(this: &v73, nextSpline: nullptr, prevSpline: nullptr);
      LODWORD(v36) = 1;
      HIDWORD(v36) = __ROL4__(v73.navSpline, 32);
      idVehicleAI::MoveToPathPosition(
        this: (idVehicleAI *)LODWORD(v73.distance),
        isStoppingGoal: v36,
        passThroughGoal: false,
        a4: v39,
        a5: v38,
        a6: v37,
        a7: v61,
        a8: v62,
        a9: v63,
        a10: v64,
        a11: v65,
        a12: v66);
      goto LABEL_20;
    }
  }
  v44 = clientGame;
  __twllei(v74.num, 0);
  v45 = 1664525 * v44->random.seed + 1013904223;
  v44->random.seed = v45;
  list = v74.list;
  v48 = (v45 >> 10) & 0x7FFF;
  v49 = __ROL4__(v48, 1);
  v50 = v48 % v33;
  v51 = v33 & ~(v49 - 1);
  v47 = startNode->links.list;
  __twlgei(v51, 0xFFFFFFFF);
  v52 = list[v50];
  if ( v47[v52].navSpline->startNode == startNode )
  {
    v68.distance = 0.0;
    v68.navSpline = nullptr;
    v68.rightDistance = 0.0;
    v53 = startNode->links.list[v52].navSpline;
    v68.distance = v29;
    v68.rightDistance = 0.0;
    v68.navSpline = v53;
    idNavSplinePosition::Validate(this: &v68, nextSpline: nullptr, prevSpline: nullptr);
    LODWORD(v54) = 1;
    HIDWORD(v54) = __ROL4__(v68.navSpline, 32);
    idVehicleAI::MoveToPathPosition(
      this: (idVehicleAI *)LODWORD(v68.distance),
      isStoppingGoal: v54,
      passThroughGoal: false,
      a4: v56,
      a5: (int)v68.navSpline,
      a6: v55,
      a7: v61,
      a8: v62,
      a9: v63,
      a10: v64,
      a11: v65,
      a12: v66);
  }
  else
  {
    v69.distance = 0.0;
    v69.navSpline = nullptr;
    v69.rightDistance = 0.0;
    v57 = startNode->links.list[v52].navSpline;
    v69.distance = v57->length - (float)v29;
    v69.rightDistance = 0.0;
    v69.navSpline = v57;
    idNavSplinePosition::Validate(this: &v69, nextSpline: nullptr, prevSpline: nullptr);
    LODWORD(v58) = 1;
    HIDWORD(v58) = __ROL4__(v69.navSpline, 32);
    idVehicleAI::MoveToPathPosition(
      this: (idVehicleAI *)LODWORD(v69.distance),
      isStoppingGoal: v58,
      passThroughGoal: false,
      a4: v60,
      a5: (int)v69.navSpline,
      a6: v59,
      a7: v61,
      a8: v62,
      a9: v63,
      a10: v64,
      a11: v65,
      a12: v66);
  }
LABEL_20:
  if ( (v74.listStatic == 0 || v74.listStatic == 2) && v74.list != nullptr )
    idMem::Free(this: &mem, ptr: v74.list, align: ALIGN_16);
}


// ========================================================================
// __unwind$497379
// EA  : 0x82B27A30
// RVA : 0x00B27A30
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void _unwind_497379()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 384 + 176));
}


// ========================================================================
// ?SetMoveAwayPos@idVS_as_StrafeShoot@@QAAXMVidNavSplinePosition@@@Z
// EA  : 0x82B27A60
// RVA : 0x00B27A60
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall idVS_as_StrafeShoot::SetMoveAwayPos(idVS_as_StrafeShoot *this, double range, __int64 enemyPos)
{
  int v3; // r2 OVERLAPPED
  unsigned int v5; // r8
  int v6; // r3
  double v7; // fp29
  idNavSpline *navSpline; // r28
  idNavPathPosTracker *SplineTracker; // r3
  double FacingDir; // fp27
  navSplinePathNode_t *startNode; // r30
  int v12; // r22
  idPhysics *Physics; // r3
  float *v14; // r3
  double v15; // fp10
  double v16; // fp6
  double v17; // fp31
  idPhysics *v18; // r3
  float *v19; // r3
  double v20; // fp13
  double v21; // fp9
  int num; // r11
  int v24; // r29
  double v26; // fp10
  double v27; // fp31
  int v28; // r11
  idNavSpline *v29; // r3
  int v30; // r11
  int v31; // r10
  idNavPathPosTracker *v32; // r3
  int v33; // r11
  double v34; // fp12
  idNavSpline *v35; // r10
  __int64 v36; // r6
  int v37; // r9
  bool v38; // r8
  idNavSpline *v39; // r8
  __int64 v40; // r6
  int v41; // r10
  int v42; // r9
  idClientGame *v43; // r11
  unsigned int v44; // r7
  encounterGroupRole_t *list; // r6
  int v46; // r4
  navSplineLink_t *v47; // r9
  idNavSplinePosition *p_moveAwayPos; // r3
  int v49; // r10
  idNavSpline *v50; // r11
  int v51; // r10
  idNavSpline *v52; // r9
  bool v53; // r8
  __int64 v54; // r6
  idNavSpline *v55; // r10
  double length; // fp0
  int v57; // [sp+8h] [-138h]
  __int64 v58; // [sp+10h] [-130h]
  __int64 v59; // [sp+18h] [-128h]
  __int64 v60; // [sp+20h] [-120h]
  __int64 v61; // [sp+28h] [-118h]
  __int64 v62; // [sp+30h] [-110h]
  _QWORD v63[3]; // [sp+50h] [-F0h] BYREF
  float v64; // [sp+68h] [-D8h]
  float v65; // [sp+6Ch] [-D4h]
  idList<enum encounterGroupRole_t,5> v66; // [sp+80h] [-C0h] BYREF
  int v67; // [sp+90h] [-B0h] BYREF
  idNavSpline *v69; // [sp+168h] [+28h]

  v69 = (idNavSpline *)enemyPos;
  v5 = 1664525 * clientGame->random.seed + 1013904223;
  clientGame->random.seed = v5;
  v66.size = 5;
  v6 = (v5 >> 10) & 0x7FFF;
  v66.num = 0;
  v66.granularity = 1;
  v63[1] = *(_QWORD *)(&v3 - 1);
  v66.list = (encounterGroupRole_t *)&v67;
  v66.memTag = 5;
  v66.listStatic = 1;
  v7 = (float)((float)((float)((float)((float)((float)*(__int64 *)(&v3 - 1) * (float)0.000061037019) - (float)1.0)
                             * (float)0.30000001)
                     + (float)1.0)
             * (float)range);
  navSpline = idVehicleAI::GetSplineTracker(this: this->ai)->pathPosition.navSpline;
  SplineTracker = idVehicleAI::GetSplineTracker(this: this->ai);
  FacingDir = idNavPathPosTracker::GetFacingDir(this: SplineTracker);
  if ( FacingDir <= 0.0 )
    startNode = navSpline->startNode;
  else
    startNode = navSpline->endNode;
  v12 = 0;
  while ( 1 )
  {
    Physics = idEntity::GetPhysics(this: this->ai);
    v14 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
    v15 = (float)(v14[1] - startNode->position.y);
    v16 = (float)(v14[2] - startNode->position.z);
    v17 = (float)((float)((float)v16 * (float)v16)
                + (float)((float)((float)(*v14 - startNode->position.x) * (float)(*v14 - startNode->position.x))
                        + (float)((float)v15 * (float)v15)));
    v18 = idEntity::GetPhysics(this: this->ai);
    v19 = (float *)v18->GetOrigin(this: v18, a2: 0);
    v20 = (float)(v19[1] - startNode->position.y);
    v21 = (float)(v19[2] - startNode->position.z);
    if ( (float)((float)((float)v21 * (float)v21)
               + (float)((float)((float)(*v19 - startNode->position.x) * (float)(*v19 - startNode->position.x))
                       + (float)((float)v20 * (float)v20))) > (double)(float)((float)v7 * (float)v7) )
    {
      *(float *)&v63[1] = -(float)((float)((float)FacingDir * (float)v7) - *(float *)&enemyPos);
      *((float *)&v63[1] + 1) = *((float *)&enemyPos + 1);
      LODWORD(this->moveAwayPos.rightDistance) = enemyPos;
      this->moveAwayPos.navSpline = v69;
      this->moveAwayPos.distance = -(float)((float)((float)FacingDir * (float)v7) - *(float *)&enemyPos);
      idNavSplinePosition::Validate(this: &this->moveAwayPos, nextSpline: nullptr, prevSpline: nullptr);
      v39 = this->moveAwayPos.navSpline;
      LODWORD(v40) = 1;
      HIDWORD(v40) = __ROL4__(v39, 32);
      idVehicleAI::MoveToPathPosition(
        this: this->ai,
        isStoppingGoal: v40,
        passThroughGoal: false,
        a4: (bool)v39,
        a5: v42,
        a6: v41,
        a7: v57,
        a8: v58,
        a9: v59,
        a10: v60,
        a11: v61,
        a12: v62);
      goto LABEL_17;
    }
    _FP12 = (float)((float)v17 - idMath::FLT_SMALLEST_NON_DENORMAL);
    num = startNode->links.num;
    v24 = 0;
    HIDWORD(v63[0]) = 0;
    __asm { fsel      f11, f12, f31, f0 }
    v26 = __frsqrte(_FP11);
    v27 = (float)-(float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v26 * (float)((float)v17 * (float)0.5)) * (float)v26)
                                                                                                - (float)1.5)
                                                                                * (float)v26)
                                                                        * (float)((float)v17 * (float)0.5))
                                                                * (float)((float)-(float)((float)((float)((float)v26 * (float)((float)v17 * (float)0.5))
                                                                                                * (float)v26)
                                                                                        - (float)1.5)
                                                                        * (float)v26))
                                                        - (float)1.5)
                                        * (float)((float)-(float)((float)((float)((float)v26
                                                                                * (float)((float)v17 * (float)0.5))
                                                                        * (float)v26)
                                                                - (float)1.5)
                                                * (float)v26))
                                * (float)v17)
                        - (float)v7);
    if ( num > 0 )
    {
      do
      {
        v28 = (int)&startNode->links.list[v24];
        if ( *(idNavSpline **)(v28 + 8) != navSpline )
        {
          v29 = *(idNavSpline **)(v28 + 8);
          HIDWORD(v63[1]) = &startNode->links.list[v24];
          if ( !idNavSpline::IsDeadEnd(this: v29) )
            idList<idAnimWebBlendTree *,5>::Append(this: &v66, obj: (const encounterGroupRole_t *)v63);
        }
        v30 = startNode->links.num;
        HIDWORD(v63[0]) = ++v24;
      }
      while ( v24 < v30 );
    }
    v31 = v66.num;
    if ( v66.num > 0 )
      break;
    if ( startNode == navSpline->startNode )
      startNode = navSpline->endNode;
    else
      startNode = navSpline->startNode;
    ++v12;
    FacingDir = (float)((float)FacingDir * (float)-1.0);
    if ( v12 >= 2 )
    {
      idLib::Warning(fmt: "Could not find a move to point in idVS_as_StrafeShoot::SetMoveAwayPos, doing it the old way");
      v32 = idVehicleAI::GetSplineTracker(this: this->ai);
      v33 = (int)&v32->pathToGoal.path.list[v32->pathToGoal.path.num];
      v65 = *((float *)&enemyPos + 1);
      HIDWORD(v63[1]) = &v32->pathToGoal;
      v34 = *(float *)(v33 - 4);
      this->moveAwayPos.navSpline = v69;
      LODWORD(this->moveAwayPos.rightDistance) = enemyPos;
      v64 = *(float *)&enemyPos - (float)((float)v34 * (float)v7);
      this->moveAwayPos.distance = v64;
      idNavSplinePosition::Validate(this: &this->moveAwayPos, nextSpline: nullptr, prevSpline: nullptr);
      v35 = this->moveAwayPos.navSpline;
      LODWORD(v36) = 1;
      HIDWORD(v36) = __ROL4__(v35, 32);
      idVehicleAI::MoveToPathPosition(
        this: this->ai,
        isStoppingGoal: v36,
        passThroughGoal: false,
        a4: v38,
        a5: v37,
        a6: (int)v35,
        a7: v57,
        a8: v58,
        a9: v59,
        a10: v60,
        a11: v61,
        a12: v62);
      goto LABEL_17;
    }
  }
  v43 = clientGame;
  __twllei(v66.num, 0);
  v44 = 1664525 * v43->random.seed + 1013904223;
  v43->random.seed = v44;
  list = v66.list;
  v46 = (v44 >> 10) & 0x7FFF;
  v47 = startNode->links.list;
  __twlgei(v31 & ~(__ROL4__(v46, 1) - 1), 0xFFFFFFFF);
  p_moveAwayPos = &this->moveAwayPos;
  v49 = list[v46 % v31];
  v50 = v47[v49].navSpline;
  if ( v50->startNode == startNode )
  {
    this->moveAwayPos.distance = v27;
    this->moveAwayPos.navSpline = v50;
    this->moveAwayPos.rightDistance = 0.0;
    HIDWORD(v63[1]) = v50;
    idNavSplinePosition::Validate(this: p_moveAwayPos, nextSpline: nullptr, prevSpline: nullptr);
    LODWORD(v54) = 1;
    HIDWORD(v54) = __ROL4__(this->moveAwayPos.navSpline, 32);
  }
  else
  {
    v55 = startNode->links.list[v49].navSpline;
    length = v55->length;
    this->moveAwayPos.navSpline = v55;
    this->moveAwayPos.distance = (float)length - (float)v27;
    this->moveAwayPos.rightDistance = 0.0;
    HIDWORD(v63[1]) = v55;
    idNavSplinePosition::Validate(this: p_moveAwayPos, nextSpline: nullptr, prevSpline: nullptr);
    v52 = this->moveAwayPos.navSpline;
    LODWORD(v54) = 1;
    HIDWORD(v54) = __ROL4__(v52, 32);
  }
  idVehicleAI::MoveToPathPosition(
    this: this->ai,
    isStoppingGoal: v54,
    passThroughGoal: false,
    a4: v53,
    a5: (int)v52,
    a6: v51,
    a7: v57,
    a8: v58,
    a9: v59,
    a10: v60,
    a11: v61,
    a12: v62);
LABEL_17:
  if ( (v66.listStatic == 0 || v66.listStatic == 2) && v66.list != nullptr )
    idMem::Free(this: &mem, ptr: v66.list, align: ALIGN_16);
}


// ========================================================================
// __unwind$497843
// EA  : 0x82B27EFC
// RVA : 0x00B27EFC
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void _unwind_497843()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 320 + 128));
}


// ========================================================================
// ?InternalWork@idVS_as_RunAway@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B27F30
// RVA : 0x00B27F30
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_RunAway::InternalWork(idVS_as_RunAway *this, idFiniteStateMachine *baseFSM, const int curTime)
{
  idVehicleAI *ai; // r30
  idNavSpline *v5; // r10
  int num; // r9
  int v7; // r8
  idNavSpline *navSpline; // r27
  idNavPathPosTracker *SplineTracker; // r3
  navSplinePathNode_t *startNode; // r29
  int v11; // r25
  int v12; // r28
  int v13; // r30
  navSplineLink_t *v14; // r11
  encounterGroupRole_t *list; // r4
  idClientGame *v16; // r11
  unsigned int v17; // r3
  int v18; // r10
  __int64 v19; // r6
  double v20; // fp31
  idNavPathPosTracker *EnemyTracker; // r3
  double CurrentSpeedInMPH; // fp1
  int v23; // [sp+8h] [-D8h]
  __int64 v24; // [sp+10h] [-D0h]
  __int64 v25; // [sp+18h] [-C8h]
  __int64 v26; // [sp+20h] [-C0h]
  __int64 v27; // [sp+28h] [-B8h]
  __int64 v28; // [sp+30h] [-B0h]
  idList<enum encounterGroupRole_t,5> v29; // [sp+60h] [-80h] BYREF
  int v30; // [sp+70h] [-70h] BYREF

  if ( idVehicleAI::GetEnemyTracker(this: this->ai) != nullptr )
  {
    ai = this->ai;
    if ( ai->distanceToFinalGoal <= (double)idVehicleAI::GetDecelDistance(this: ai) )
    {
      v29.size = 5;
      v29.granularity = 1;
      v29.num = 0;
      v29.list = (encounterGroupRole_t *)&v30;
      v29.memTag = 5;
      v29.listStatic = 1;
      navSpline = idVehicleAI::GetSplineTracker(this: this->ai)->pathPosition.navSpline;
      SplineTracker = idVehicleAI::GetSplineTracker(this: this->ai);
      if ( idNavPathPosTracker::GetFacingDir(this: SplineTracker) <= 0.0 )
        startNode = navSpline->startNode;
      else
        startNode = navSpline->endNode;
      v11 = 0;
      while ( 1 )
      {
        v12 = 0;
        if ( startNode->links.num > 0 )
        {
          v13 = 0;
          do
          {
            v14 = &startNode->links.list[v13];
            v5 = v14->navSpline;
            if ( v5 != navSpline && !idNavSpline::IsDeadEnd(this: v14->navSpline) )
              idList<idAnimWebBlendTree *,5>::Append(
                this: &v29,
                obj: (const encounterGroupRole_t *)&startNode->links.list[v13].navSpline);
            ++v12;
            ++v13;
          }
          while ( v12 < startNode->links.num );
        }
        if ( v29.num > 0 )
          break;
        if ( startNode == navSpline->startNode )
          startNode = navSpline->endNode;
        else
          startNode = navSpline->startNode;
        if ( ++v11 >= 2 )
        {
          list = v29.list;
          goto LABEL_20;
        }
      }
      num = v29.num;
      v16 = clientGame;
      __twllei(v29.num, 0);
      v17 = 1664525 * v16->random.seed + 1013904223;
      v16->random.seed = v17;
      list = v29.list;
      v18 = (v17 >> 10) & 0x7FFF;
      v7 = v18 / num;
      __twlgei(num & ~(__ROL4__(v18, 1) - 1), 0xFFFFFFFF);
      v5 = (idNavSpline *)list[v18 % num];
      this->runawayPathPos.distance = v5->length * (float)0.5;
      this->runawayPathPos.rightDistance = 0.0;
      this->runawayPathPos.navSpline = v5;
LABEL_20:
      if ( v29.listStatic == 0 || v29.listStatic == 2 )
      {
        if ( list != nullptr )
          idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
        v29.list = nullptr;
        v29.size = 0;
      }
      v29.num = 0;
    }
    LODWORD(v19) = 0;
    HIDWORD(v19) = __ROL4__(this->runawayPathPos.navSpline, 32);
    idVehicleAI::MoveToPathPosition(
      this: (idVehicleAI *)LODWORD(this->runawayPathPos.distance),
      isStoppingGoal: v19,
      passThroughGoal: false,
      a4: v7,
      a5: num,
      a6: (int)v5,
      a7: v23,
      a8: v24,
      a9: v25,
      a10: v26,
      a11: v27,
      a12: v28);
    v20 = 120.0;
    EnemyTracker = idVehicleAI::GetEnemyTracker(this: this->ai);
    CurrentSpeedInMPH = idNavPathPosTracker::GetCurrentSpeedInMPH(this: EnemyTracker);
    if ( CurrentSpeedInMPH > 120.0 )
      v20 = (float)((float)CurrentSpeedInMPH + (float)15.0);
    idVehicleAI::SetSpeedLimit(this: this->ai, speed: v20);
    idVehicleAI::FireWeapon(this: this->ai);
  }
}


// ========================================================================
// __unwind$498298
// EA  : 0x82B28188
// RVA : 0x00B28188
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void _unwind_498298()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 224 + 96));
}


// ========================================================================
// ?FleeToWaypoint@idVS_as_HitAndRun@@QAAXXZ
// EA  : 0x82B281B8
// RVA : 0x00B281B8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_HitAndRun::FleeToWaypoint(idVS_as_HitAndRun *this)
{
  int v2; // r29
  idSplineWaypoint *v3; // r24
  int v4; // r27
  unsigned int v5; // r5
  idVehicleAI *ai; // r4
  double v7; // fp30
  idGameLocal *v8; // r11
  int v9; // r28
  int value; // r9
  idSplineWaypoint *v11; // r3
  idSplineWaypoint *v12; // r3
  idPhysics *Physics; // r30
  idEntityPtr<idVehicle_Car> *p_vehicleCar; // r9
  idVehicle_Car *v15; // r3
  idVehicle_Car *v16; // r3
  idPhysics *v17; // r22
  float *v18; // r30
  float *v19; // r3
  double v20; // fp10
  double v21; // fp6
  double v22; // fp31
  int v23; // r9
  idSplineWaypoint *v24; // r3
  idSplineWaypoint *v25; // r3
  encounterGroupRole_t *list; // r9
  int v27; // r28
  int v28; // r30
  int v29; // r9
  idSplineWaypoint *v30; // r3
  idSplineWaypoint *v31; // r3
  int v32; // r9
  idSplineWaypoint *v33; // r3
  idSplineWaypoint *v34; // r3
  encounterGroupRole_t v35; // r27
  idVehicle_Car *v36; // r3
  idVehicle_Car *v37; // r3
  idPhysics *v38; // r3
  const idVec3 *v39; // r3
  float x; // r7
  float y; // r6
  float z; // r5
  int v43; // r8
  int v44; // r11
  int v45; // r4
  idVehicle_Car *v46; // r3
  idVehicle_Car *v47; // r3
  idPhysics *v48; // r3
  int v49; // r3
  float v50; // r7
  float v51; // r6
  idPhysics *v52; // r3
  float *v53; // r3
  double v54; // fp28
  int v55; // r10
  double v56; // fp13
  double v57; // fp27
  int v58; // r9
  double v59; // fp11
  double v60; // fp26
  char num; // r8
  double v62; // fp9
  encounterGroupRole_t *v63; // r4
  double v64; // fp25
  double v65; // fp24
  double v66; // fp23
  double v69; // fp2
  double v70; // fp6
  double v71; // fp1
  double v72; // fp0
  double v73; // fp29
  int v74; // r30
  idEntity *v75; // r3
  idPhysics *v76; // r3
  float *v77; // r3
  double v78; // fp12
  double v79; // fp8
  double v82; // fp1
  double v83; // fp5
  double v84; // fp3
  double v85; // fp0
  double v86; // fp13
  double v87; // fp0
  __int64 v88; // r6
  int v89; // [sp+8h] [-148h]
  __int64 v90; // [sp+10h] [-140h]
  __int64 v91; // [sp+18h] [-138h]
  __int64 v92; // [sp+20h] [-130h]
  __int64 v93; // [sp+28h] [-128h]
  __int64 v94; // [sp+30h] [-120h]
  idEntityPtr<idVehicle_Car> *v95; // [sp+50h] [-100h] BYREF
  float v96; // [sp+58h] [-F8h]
  float v97; // [sp+5Ch] [-F4h]
  float v98; // [sp+60h] [-F0h]
  float v99; // [sp+68h] [-E8h]
  float v100; // [sp+6Ch] [-E4h]
  float v101; // [sp+70h] [-E0h]
  idList<enum encounterGroupRole_t,5> v102; // [sp+80h] [-D0h] BYREF
  _BYTE v103[104]; // [sp+90h] [-C0h] BYREF

  if ( (-this->ai->setup.encounter.waypoints.num & ~this->ai->setup.encounter.waypoints.num) < 0 )
  {
    v2 = 1;
    this->state = ST_MOVING_AWAY;
    v3 = nullptr;
    v4 = 0;
    v5 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v5;
    ai = this->ai;
    this->actionCount = ((v5 >> 10) & 0x7FFF) - 2 * ((int)((v5 >> 10) & 0x7FFF) >> 1) + 1;
    v7 = 1.0e30;
    v8 = gameLocal;
    if ( ai->setup.encounter.waypoints.num > 0 )
    {
      v9 = 0;
      do
      {
        value = this->ai->setup.encounter.waypoints.list[v9].spawnId.value;
        if ( v8->spawnIds.ptr[value & 0x1FFF] == value >> 13
          && (v11 = (idSplineWaypoint *)v8->entities.ptr[this->ai->setup.encounter.waypoints.list[v9].spawnId.value
                                                       & 0x1FFF]) != nullptr )
        {
          v12 = idSplineWaypoint::CastTo(c: v11);
        }
        else
        {
          v12 = nullptr;
        }
        Physics = idEntity::GetPhysics(this: v12);
        p_vehicleCar = &this->ai->vehicleCar;
        v95 = p_vehicleCar;
        if ( gameLocal->spawnIds.ptr[p_vehicleCar->spawnId.value & 0x1FFF] == p_vehicleCar->spawnId.value >> 13
          && (v15 = (idVehicle_Car *)gameLocal->entities.ptr[p_vehicleCar->spawnId.value & 0x1FFF]) != nullptr )
        {
          v16 = idVehicle_Car::CastTo(c: v15);
        }
        else
        {
          v16 = nullptr;
        }
        v17 = idEntity::GetPhysics(this: v16);
        v18 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
        v19 = (float *)v17->GetOrigin(this: v17, a2: 0);
        v8 = gameLocal;
        v20 = (float)(v19[1] - v18[1]);
        v21 = (float)(v19[2] - v18[2]);
        v22 = (float)((float)((float)v21 * (float)v21)
                    + (float)((float)((float)(*v19 - *v18) * (float)(*v19 - *v18)) + (float)((float)v20 * (float)v20)));
        if ( v22 < v7 )
        {
          v23 = this->ai->setup.encounter.waypoints.list[v9].spawnId.value;
          if ( gameLocal->spawnIds.ptr[v23 & 0x1FFF] == v23 >> 13
            && (v24 = (idSplineWaypoint *)gameLocal->entities.ptr[this->ai->setup.encounter.waypoints.list[v9].spawnId.value
                                                                & 0x1FFF]) != nullptr )
          {
            v25 = idSplineWaypoint::CastTo(c: v24);
            v8 = gameLocal;
          }
          else
          {
            v25 = nullptr;
          }
          v3 = v25;
          v7 = v22;
        }
        ++v4;
        ++v9;
      }
      while ( v4 < this->ai->setup.encounter.waypoints.num );
    }
    v102.num = 0;
    v102.granularity = 1;
    list = (encounterGroupRole_t *)v103;
    v102.size = 6;
    v102.memTag = 5;
    v102.list = (encounterGroupRole_t *)v103;
    v102.listStatic = 1;
    v27 = 0;
    if ( this->ai->setup.encounter.waypoints.num > 0 )
    {
      v28 = 0;
      do
      {
        v29 = this->ai->setup.encounter.waypoints.list[v28].spawnId.value;
        if ( v8->spawnIds.ptr[v29 & 0x1FFF] == v29 >> 13 )
        {
          v30 = (idSplineWaypoint *)v8->entities.ptr[this->ai->setup.encounter.waypoints.list[v28].spawnId.value
                                                   & 0x1FFF];
          if ( v30 != nullptr )
          {
            v31 = idSplineWaypoint::CastTo(c: v30);
            v8 = gameLocal;
          }
          else
          {
            v31 = nullptr;
          }
        }
        else
        {
          v31 = nullptr;
        }
        if ( v31 != v3 )
        {
          v32 = this->ai->setup.encounter.waypoints.list[v28].spawnId.value;
          if ( v8->spawnIds.ptr[v32 & 0x1FFF] == v32 >> 13
            && (v33 = (idSplineWaypoint *)v8->entities.ptr[this->ai->setup.encounter.waypoints.list[v28].spawnId.value
                                                         & 0x1FFF]) != nullptr )
          {
            v34 = idSplineWaypoint::CastTo(c: v33);
          }
          else
          {
            v34 = nullptr;
          }
          v95 = (idEntityPtr<idVehicle_Car> *)v34;
          idList<idAnimWebBlendTree *,5>::Append(this: &v102, obj: (const encounterGroupRole_t *)&v95);
          v8 = gameLocal;
        }
        ++v27;
        ++v28;
      }
      while ( v27 < this->ai->setup.encounter.waypoints.num );
      list = v102.list;
    }
    v35 = *list;
    v95 = &this->ai->vehicleCar;
    if ( v8->spawnIds.ptr[v95->spawnId.value & 0x1FFF] == v95->spawnId.value >> 13
      && (v36 = (idVehicle_Car *)v8->entities.ptr[v95->spawnId.value & 0x1FFF]) != nullptr )
    {
      v37 = idVehicle_Car::CastTo(c: v36);
    }
    else
    {
      v37 = nullptr;
    }
    v38 = idEntity::GetPhysics(this: v37);
    v39 = v38->GetOrigin(this: v38, a2: 0);
    x = v39->x;
    y = v39->y;
    z = v39->z;
    v95 = &this->ai->vehicleCar;
    v43 = v95->spawnId.value;
    v44 = v95->spawnId.value & 0x1FFF;
    v45 = v95->spawnId.value >> 13;
    v96 = x;
    v97 = y;
    v98 = z;
    if ( gameLocal->spawnIds.ptr[v43 & 0x1FFF] == v45
      && (v46 = (idVehicle_Car *)gameLocal->entities.ptr[v44]) != nullptr )
    {
      v47 = idVehicle_Car::CastTo(c: v46);
    }
    else
    {
      v47 = nullptr;
    }
    v48 = idEntity::GetPhysics(this: v47);
    v49 = (int)v48->GetAxis(this: v48, a2: 0);
    v50 = *(float *)(v49 + 4);
    v51 = *(float *)(v49 + 8);
    v99 = *(float *)v49;
    v100 = v50;
    v101 = v51;
    v52 = idEntity::GetPhysics(this: *(idEntity **)v102.list);
    v53 = (float *)v52->GetOrigin(this: v52, a2: 0);
    v54 = v97;
    v55 = 0x82000000;
    v56 = (float)(v53[1] - v97);
    v57 = v96;
    v58 = 0x82000000;
    v59 = (float)(*v53 - v96);
    v60 = v98;
    num = v102.num;
    v62 = (float)(v53[2] - v98);
    v63 = v102.list;
    v64 = v100;
    v65 = v101;
    v66 = v99;
    _FP5 = (float)((float)((float)((float)(v53[2] - v98) * (float)(v53[2] - v98))
                         + (float)((float)((float)(*v53 - v96) * (float)(*v53 - v96))
                                 + (float)((float)(v53[1] - v97) * (float)(v53[1] - v97))))
                 - idMath::FLT_SMALLEST_NON_DENORMAL);
    __asm { fsel      f3, f5, f6, f0 }
    v69 = __frsqrte(_FP3);
    v70 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v69
                                                                                        * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)v59 * (float)v59) + (float)((float)v56 * (float)v56)))
                                                                                                * (float)0.5))
                                                                                * (float)v69)
                                                                        - (float)1.5)
                                                        * (float)v69)
                                                * (float)((float)((float)((float)v62 * (float)v62)
                                                                + (float)((float)((float)v59 * (float)v59)
                                                                        + (float)((float)v56 * (float)v56)))
                                                        * (float)0.5))
                                        * (float)((float)-(float)((float)((float)((float)v69
                                                                                * (float)((float)((float)((float)v62 * (float)v62)
                                                                                                + (float)((float)((float)v59 * (float)v59) + (float)((float)v56 * (float)v56)))
                                                                                        * (float)0.5))
                                                                        * (float)v69)
                                                                - (float)1.5)
                                                * (float)v69))
                                - (float)1.5)
                * (float)((float)-(float)((float)((float)((float)v69
                                                        * (float)((float)((float)((float)v62 * (float)v62)
                                                                        + (float)((float)((float)v59 * (float)v59)
                                                                                + (float)((float)v56 * (float)v56)))
                                                                * (float)0.5))
                                                * (float)v69)
                                        - (float)1.5)
                        * (float)v69));
    v71 = (float)((float)v62
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v69 * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)v59 * (float)v59) + (float)((float)v56 * (float)v56))) * (float)0.5)) * (float)v69) - (float)1.5) * (float)v69)
                                                                                                * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)v59 * (float)v59) + (float)((float)v56 * (float)v56))) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v69 * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)v59 * (float)v59) + (float)((float)v56 * (float)v56))) * (float)0.5)) * (float)v69) - (float)1.5)
                                                                                                * (float)v69))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v69 * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)v59 * (float)v59) + (float)((float)v56 * (float)v56))) * (float)0.5))
                                                                                                * (float)v69)
                                                                                        - (float)1.5)
                                                                        * (float)v69))
                                                        * (float)((float)((float)((float)v62 * (float)v62)
                                                                        + (float)((float)((float)v59 * (float)v59)
                                                                                + (float)((float)v56 * (float)v56)))
                                                                * (float)0.5))
                                                * (float)v70)
                                        - (float)1.5)
                        * (float)v70));
    v72 = (float)((float)v59
                * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v69 * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)v59 * (float)v59) + (float)((float)v56 * (float)v56))) * (float)0.5)) * (float)v69) - (float)1.5) * (float)v69)
                                                                                                * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)v59 * (float)v59) + (float)((float)v56 * (float)v56))) * (float)0.5))
                                                                                        * (float)((float)-(float)((float)((float)((float)v69 * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)v59 * (float)v59) + (float)((float)v56 * (float)v56))) * (float)0.5)) * (float)v69) - (float)1.5)
                                                                                                * (float)v69))
                                                                                - (float)1.5)
                                                                * (float)((float)-(float)((float)((float)((float)v69 * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)v59 * (float)v59) + (float)((float)v56 * (float)v56))) * (float)0.5))
                                                                                                * (float)v69)
                                                                                        - (float)1.5)
                                                                        * (float)v69))
                                                        * (float)((float)((float)((float)v62 * (float)v62)
                                                                        + (float)((float)((float)v59 * (float)v59)
                                                                                + (float)((float)v56 * (float)v56)))
                                                                * (float)0.5))
                                                * (float)v70)
                                        - (float)1.5)
                        * (float)v70));
    v73 = (float)((float)(v99 * (float)v72)
                + (float)((float)(v101 * (float)v71)
                        + (float)(v100
                                * (float)((float)v56
                                        * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v69 * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)v59 * (float)v59) + (float)((float)v56 * (float)v56))) * (float)0.5)) * (float)v69) - (float)1.5) * (float)v69) * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)v59 * (float)v59) + (float)((float)v56 * (float)v56))) * (float)0.5)) * (float)((float)-(float)((float)((float)((float)v69 * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)v59 * (float)v59) + (float)((float)v56 * (float)v56))) * (float)0.5)) * (float)v69) - (float)1.5) * (float)v69)) - (float)1.5)
                                                                                        * (float)((float)-(float)((float)((float)((float)v69 * (float)((float)((float)((float)v62 * (float)v62) + (float)((float)((float)v59 * (float)v59) + (float)((float)v56 * (float)v56))) * (float)0.5)) * (float)v69) - (float)1.5)
                                                                                                * (float)v69))
                                                                                * (float)((float)((float)((float)v62 * (float)v62)
                                                                                                + (float)((float)((float)v59 * (float)v59) + (float)((float)v56 * (float)v56)))
                                                                                        * (float)0.5))
                                                                        * (float)v70)
                                                                - (float)1.5)
                                                * (float)v70)))));
    if ( v102.num > 1 )
    {
      v74 = 1;
      do
      {
        v75 = (idEntity *)v63[v74];
        v95 = (idEntityPtr<idVehicle_Car> *)&v63[v74];
        v76 = idEntity::GetPhysics(this: v75);
        v77 = (float *)v76->GetOrigin(this: v76, a2: 0);
        v63 = v102.list;
        v78 = (float)(v77[1] - (float)v54);
        v79 = (float)(v77[2] - (float)v60);
        _FP4 = (float)((float)((float)((float)v79 * (float)v79)
                             + (float)((float)((float)(*v77 - (float)v57) * (float)(*v77 - (float)v57))
                                     + (float)((float)v78 * (float)v78)))
                     - idMath::FLT_SMALLEST_NON_DENORMAL);
        __asm { fsel      f2, f4, f5, f0 }
        v82 = __frsqrte(_FP2);
        v83 = (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v82
                                                                                            * (float)((float)((float)((float)v79 * (float)v79) + (float)((float)((float)(*v77 - (float)v57) * (float)(*v77 - (float)v57)) + (float)((float)v78 * (float)v78))) * (float)0.5))
                                                                                    * (float)v82)
                                                                            - (float)1.5)
                                                            * (float)v82)
                                                    * (float)((float)((float)((float)v79 * (float)v79)
                                                                    + (float)((float)((float)(*v77 - (float)v57)
                                                                                    * (float)(*v77 - (float)v57))
                                                                            + (float)((float)v78 * (float)v78)))
                                                            * (float)0.5))
                                            * (float)((float)-(float)((float)((float)((float)v82
                                                                                    * (float)((float)((float)((float)v79 * (float)v79) + (float)((float)((float)(*v77 - (float)v57) * (float)(*v77 - (float)v57)) + (float)((float)v78 * (float)v78)))
                                                                                            * (float)0.5))
                                                                            * (float)v82)
                                                                    - (float)1.5)
                                                    * (float)v82))
                                    - (float)1.5)
                    * (float)((float)-(float)((float)((float)((float)v82
                                                            * (float)((float)((float)((float)v79 * (float)v79)
                                                                            + (float)((float)((float)(*v77 - (float)v57)
                                                                                            * (float)(*v77 - (float)v57))
                                                                                    + (float)((float)v78 * (float)v78)))
                                                                    * (float)0.5))
                                                    * (float)v82)
                                            - (float)1.5)
                            * (float)v82));
        v84 = (float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v82 * (float)((float)((float)((float)v79 * (float)v79) + (float)((float)((float)(*v77 - (float)v57) * (float)(*v77 - (float)v57)) + (float)((float)v78 * (float)v78))) * (float)0.5)) * (float)v82) - (float)1.5)
                                                                                            * (float)v82)
                                                                                    * (float)((float)((float)((float)v79 * (float)v79) + (float)((float)((float)(*v77 - (float)v57) * (float)(*v77 - (float)v57)) + (float)((float)v78 * (float)v78)))
                                                                                            * (float)0.5))
                                                                            * (float)((float)-(float)((float)((float)((float)v82 * (float)((float)((float)((float)v79 * (float)v79) + (float)((float)((float)(*v77 - (float)v57) * (float)(*v77 - (float)v57)) + (float)((float)v78 * (float)v78))) * (float)0.5)) * (float)v82) - (float)1.5)
                                                                                    * (float)v82))
                                                                    - (float)1.5)
                                                    * (float)((float)-(float)((float)((float)((float)v82
                                                                                            * (float)((float)((float)((float)v79 * (float)v79) + (float)((float)((float)(*v77 - (float)v57) * (float)(*v77 - (float)v57)) + (float)((float)v78 * (float)v78))) * (float)0.5))
                                                                                    * (float)v82)
                                                                            - (float)1.5)
                                                            * (float)v82))
                                            * (float)((float)((float)((float)v79 * (float)v79)
                                                            + (float)((float)((float)(*v77 - (float)v57)
                                                                            * (float)(*v77 - (float)v57))
                                                                    + (float)((float)v78 * (float)v78)))
                                                    * (float)0.5))
                                    * (float)v83)
                            - (float)1.5);
        v85 = (float)((float)v79
                    * (float)((float)v84
                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v82 * (float)((float)((float)((float)v79 * (float)v79) + (float)((float)((float)(*v77 - (float)v57) * (float)(*v77 - (float)v57)) + (float)((float)v78 * (float)v78))) * (float)0.5)) * (float)v82)
                                                                                            - (float)1.5)
                                                                            * (float)v82)
                                                                    * (float)((float)((float)((float)v79 * (float)v79)
                                                                                    + (float)((float)((float)(*v77 - (float)v57) * (float)(*v77 - (float)v57))
                                                                                            + (float)((float)v78 * (float)v78)))
                                                                            * (float)0.5))
                                                            * (float)((float)-(float)((float)((float)((float)v82 * (float)((float)((float)((float)v79 * (float)v79) + (float)((float)((float)(*v77 - (float)v57) * (float)(*v77 - (float)v57)) + (float)((float)v78 * (float)v78))) * (float)0.5))
                                                                                            * (float)v82)
                                                                                    - (float)1.5)
                                                                    * (float)v82))
                                                    - (float)1.5)
                                    * (float)((float)-(float)((float)((float)((float)v82
                                                                            * (float)((float)((float)((float)v79 * (float)v79)
                                                                                            + (float)((float)((float)(*v77 - (float)v57) * (float)(*v77 - (float)v57)) + (float)((float)v78 * (float)v78)))
                                                                                    * (float)0.5))
                                                                    * (float)v82)
                                                            - (float)1.5)
                                            * (float)v82))));
        v86 = (float)((float)(*v77 - (float)v57)
                    * (float)((float)v84
                            * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v82 * (float)((float)((float)((float)v79 * (float)v79) + (float)((float)((float)(*v77 - (float)v57) * (float)(*v77 - (float)v57)) + (float)((float)v78 * (float)v78))) * (float)0.5)) * (float)v82)
                                                                                            - (float)1.5)
                                                                            * (float)v82)
                                                                    * (float)((float)((float)((float)v79 * (float)v79)
                                                                                    + (float)((float)((float)(*v77 - (float)v57) * (float)(*v77 - (float)v57))
                                                                                            + (float)((float)v78 * (float)v78)))
                                                                            * (float)0.5))
                                                            * (float)((float)-(float)((float)((float)((float)v82 * (float)((float)((float)((float)v79 * (float)v79) + (float)((float)((float)(*v77 - (float)v57) * (float)(*v77 - (float)v57)) + (float)((float)v78 * (float)v78))) * (float)0.5))
                                                                                            * (float)v82)
                                                                                    - (float)1.5)
                                                                    * (float)v82))
                                                    - (float)1.5)
                                    * (float)((float)-(float)((float)((float)((float)v82
                                                                            * (float)((float)((float)((float)v79 * (float)v79)
                                                                                            + (float)((float)((float)(*v77 - (float)v57) * (float)(*v77 - (float)v57)) + (float)((float)v78 * (float)v78)))
                                                                                    * (float)0.5))
                                                                    * (float)v82)
                                                            - (float)1.5)
                                            * (float)v82))));
        v87 = (float)((float)((float)v66 * (float)v86)
                    + (float)((float)((float)v65 * (float)v85)
                            + (float)((float)v64
                                    * (float)((float)v78
                                            * (float)((float)v84
                                                    * (float)((float)-(float)((float)((float)((float)((float)-(float)((float)((float)((float)v82 * (float)((float)((float)((float)v79 * (float)v79) + (float)((float)((float)(*v77 - (float)v57) * (float)(*v77 - (float)v57)) + (float)((float)v78 * (float)v78))) * (float)0.5)) * (float)v82) - (float)1.5) * (float)v82)
                                                                                            * (float)((float)((float)((float)v79 * (float)v79) + (float)((float)((float)(*v77 - (float)v57) * (float)(*v77 - (float)v57)) + (float)((float)v78 * (float)v78))) * (float)0.5))
                                                                                    * (float)((float)-(float)((float)((float)((float)v82 * (float)((float)((float)((float)v79 * (float)v79) + (float)((float)((float)(*v77 - (float)v57) * (float)(*v77 - (float)v57)) + (float)((float)v78 * (float)v78))) * (float)0.5)) * (float)v82) - (float)1.5)
                                                                                            * (float)v82))
                                                                            - (float)1.5)
                                                            * (float)((float)-(float)((float)((float)((float)v82 * (float)((float)((float)((float)v79 * (float)v79) + (float)((float)((float)(*v77 - (float)v57) * (float)(*v77 - (float)v57)) + (float)((float)v78 * (float)v78))) * (float)0.5))
                                                                                            * (float)v82)
                                                                                    - (float)1.5)
                                                                    * (float)v82)))))));
        if ( v87 > v73 )
        {
          v35 = v102.list[v74];
          v73 = v87;
        }
        ++v2;
        ++v74;
      }
      while ( v2 < v102.num );
    }
    if ( v102.listStatic == 0 || v102.listStatic == 2 )
    {
      if ( v63 != nullptr )
        idMem::Free(this: &mem, ptr: v63, align: ALIGN_16);
      v102.list = nullptr;
      v102.size = 0;
    }
    v102.num = 0;
    LODWORD(v88) = 0;
    HIDWORD(v88) = __ROL4__(*(_DWORD *)(v35 + 824), 32);
    idVehicleAI::MoveToPathPosition(
      this: this->ai,
      isStoppingGoal: v88,
      passThroughGoal: false,
      a4: num,
      a5: v58,
      a6: v55,
      a7: v89,
      a8: v90,
      a9: v91,
      a10: v92,
      a11: v93,
      a12: v94);
    this->saveGoalPos.distance = *(float *)(v35 + 816);
    this->saveGoalPos.rightDistance = *(float *)(v35 + 820);
    this->saveGoalPos.navSpline = *(idNavSpline **)(v35 + 824);
  }
}


// ========================================================================
// __unwind$498432
// EA  : 0x82B28818
// RVA : 0x00B28818
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void _unwind_498432()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 336 + 128));
}


// ========================================================================
// ?FleeToWaypoint@idVS_as_WaypointTag@@QAAXXZ
// EA  : 0x82B28848
// RVA : 0x00B28848
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_WaypointTag::FleeToWaypoint(idVS_as_WaypointTag *this)
{
  idSplineWaypoint *v2; // r24
  int v3; // r26
  unsigned int v4; // r6
  idVehicleAI *ai; // r5
  double v6; // fp30
  idGameLocal *v7; // r11
  int v8; // r28
  int value; // r9
  idSplineWaypoint *v10; // r3
  idSplineWaypoint *v11; // r3
  idPhysics *Physics; // r30
  idEntityPtr<idVehicle_Car> *p_vehicleCar; // r9
  idVehicle_Car *v14; // r3
  idVehicle_Car *v15; // r3
  idPhysics *v16; // r19
  float *v17; // r30
  float *v18; // r3
  double v19; // fp10
  double v20; // fp6
  double v21; // fp31
  int v22; // r9
  idSplineWaypoint *v23; // r3
  idSplineWaypoint *v24; // r3
  int v25; // r8
  encounterGroupRole_t *list; // r4
  int num; // r9
  int v28; // r28
  int v29; // r30
  int v30; // r9
  idSplineWaypoint *v31; // r3
  idSplineWaypoint *v32; // r3
  int v33; // r9
  idSplineWaypoint *v34; // r3
  idSplineWaypoint *v35; // r3
  int v36; // r10
  signed int v37; // r11
  int v38; // r11
  unsigned int seed; // r9
  signed int v40; // r5
  encounterGroupRole_t v41; // r30
  __int64 v42; // r6
  int v43; // [sp+8h] [-108h]
  __int64 v44; // [sp+10h] [-100h]
  __int64 v45; // [sp+18h] [-F8h]
  __int64 v46; // [sp+20h] [-F0h]
  __int64 v47; // [sp+28h] [-E8h]
  __int64 v48; // [sp+30h] [-E0h]
  void *v49; // [sp+50h] [-C0h] BYREF
  idList<enum encounterGroupRole_t,5> v50; // [sp+60h] [-B0h] BYREF
  _BYTE v51[32]; // [sp+70h] [-A0h] BYREF

  if ( (-this->ai->setup.encounter.waypoints.num & ~this->ai->setup.encounter.waypoints.num) < 0 )
  {
    this->state = ST_MOVING_AWAY;
    v2 = nullptr;
    v3 = 0;
    v4 = 1664525 * clientGame->random.seed + 1013904223;
    clientGame->random.seed = v4;
    ai = this->ai;
    this->actionCount = ((v4 >> 10) & 0x7FFF) - 2 * ((int)((v4 >> 10) & 0x7FFF) >> 1) + 1;
    v6 = 1.0e30;
    v7 = gameLocal;
    if ( ai->setup.encounter.waypoints.num > 0 )
    {
      v8 = 0;
      do
      {
        value = this->ai->setup.encounter.waypoints.list[v8].spawnId.value;
        if ( v7->spawnIds.ptr[value & 0x1FFF] == value >> 13
          && (v10 = (idSplineWaypoint *)v7->entities.ptr[this->ai->setup.encounter.waypoints.list[v8].spawnId.value
                                                       & 0x1FFF]) != nullptr )
        {
          v11 = idSplineWaypoint::CastTo(c: v10);
        }
        else
        {
          v11 = nullptr;
        }
        Physics = idEntity::GetPhysics(this: v11);
        p_vehicleCar = &this->ai->vehicleCar;
        v49 = p_vehicleCar;
        if ( gameLocal->spawnIds.ptr[p_vehicleCar->spawnId.value & 0x1FFF] == p_vehicleCar->spawnId.value >> 13
          && (v14 = (idVehicle_Car *)gameLocal->entities.ptr[p_vehicleCar->spawnId.value & 0x1FFF]) != nullptr )
        {
          v15 = idVehicle_Car::CastTo(c: v14);
        }
        else
        {
          v15 = nullptr;
        }
        v16 = idEntity::GetPhysics(this: v15);
        v17 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
        v18 = (float *)v16->GetOrigin(this: v16, a2: 0);
        v7 = gameLocal;
        v19 = (float)(v18[1] - v17[1]);
        v20 = (float)(v18[2] - v17[2]);
        v21 = (float)((float)((float)v20 * (float)v20)
                    + (float)((float)((float)(*v18 - *v17) * (float)(*v18 - *v17)) + (float)((float)v19 * (float)v19)));
        if ( v21 < v6 )
        {
          v22 = this->ai->setup.encounter.waypoints.list[v8].spawnId.value;
          if ( gameLocal->spawnIds.ptr[v22 & 0x1FFF] == v22 >> 13
            && (v23 = (idSplineWaypoint *)gameLocal->entities.ptr[this->ai->setup.encounter.waypoints.list[v8].spawnId.value
                                                                & 0x1FFF]) != nullptr )
          {
            v24 = idSplineWaypoint::CastTo(c: v23);
            v7 = gameLocal;
          }
          else
          {
            v24 = nullptr;
          }
          v2 = v24;
          v6 = v21;
        }
        ++v3;
        ++v8;
      }
      while ( v3 < this->ai->setup.encounter.waypoints.num );
    }
    v50.granularity = 1;
    LOBYTE(v25) = 5;
    v50.listStatic = 1;
    list = (encounterGroupRole_t *)v51;
    v50.size = 6;
    num = 0;
    v50.memTag = 5;
    v50.num = 0;
    v50.list = (encounterGroupRole_t *)v51;
    v28 = 0;
    if ( this->ai->setup.encounter.waypoints.num > 0 )
    {
      v29 = 0;
      do
      {
        v30 = this->ai->setup.encounter.waypoints.list[v29].spawnId.value;
        v25 = v30 >> 13;
        if ( v7->spawnIds.ptr[v30 & 0x1FFF] == v30 >> 13 )
        {
          v31 = (idSplineWaypoint *)v7->entities.ptr[this->ai->setup.encounter.waypoints.list[v29].spawnId.value
                                                   & 0x1FFF];
          if ( v31 != nullptr )
          {
            v32 = idSplineWaypoint::CastTo(c: v31);
            v7 = gameLocal;
          }
          else
          {
            v32 = nullptr;
          }
        }
        else
        {
          v32 = nullptr;
        }
        if ( v32 != v2 )
        {
          v33 = this->ai->setup.encounter.waypoints.list[v29].spawnId.value;
          if ( v7->spawnIds.ptr[v33 & 0x1FFF] == v33 >> 13
            && (v34 = (idSplineWaypoint *)v7->entities.ptr[this->ai->setup.encounter.waypoints.list[v29].spawnId.value
                                                         & 0x1FFF]) != nullptr )
          {
            v35 = idSplineWaypoint::CastTo(c: v34);
          }
          else
          {
            v35 = nullptr;
          }
          v49 = v35;
          idList<idAnimWebBlendTree *,5>::Append(this: &v50, obj: (const encounterGroupRole_t *)&v49);
          v7 = gameLocal;
        }
        ++v28;
        ++v29;
      }
      while ( v28 < this->ai->setup.encounter.waypoints.num );
      num = v50.num;
      list = v50.list;
    }
    v36 = (int)clientGame;
    v37 = num;
    if ( num != 0 )
    {
      seed = clientGame->random.seed;
      __twllei(v37, 0);
      clientGame->random.seed = 1664525 * seed + 1013904223;
      v40 = ((1664525 * seed + 1013904223) >> 10) & 0x7FFF;
      v36 = __ROL4__(v40, 1) - 1;
      num = v40 / v37 * v37;
      v25 = v37 & ~v36;
      v38 = v40 % v37;
      __twlgei(v25, 0xFFFFFFFF);
      list = v50.list;
    }
    else
    {
      v38 = 0;
    }
    v41 = list[v38];
    if ( v50.listStatic == 0 || v50.listStatic == 2 )
    {
      if ( list != nullptr )
        idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
      v50.list = nullptr;
      v50.size = 0;
    }
    v50.num = 0;
    LODWORD(v42) = 0;
    HIDWORD(v42) = __ROL4__(*(_DWORD *)(v41 + 824), 32);
    idVehicleAI::MoveToPathPosition(
      this: this->ai,
      isStoppingGoal: v42,
      passThroughGoal: false,
      a4: v25,
      a5: num,
      a6: v36,
      a7: v43,
      a8: v44,
      a9: v45,
      a10: v46,
      a11: v47,
      a12: v48);
    this->saveGoalPos.distance = *(float *)(v41 + 816);
    this->saveGoalPos.rightDistance = *(float *)(v41 + 820);
    this->saveGoalPos.navSpline = *(idNavSpline **)(v41 + 824);
  }
}


// ========================================================================
// __unwind$499131
// EA  : 0x82B28C74
// RVA : 0x00B28C74
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void _unwind_499131()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 272 + 96));
}


// ========================================================================
// ?UpdateOthers@idVS_ds_Group_FollowLeader@@QAAXXZ
// EA  : 0x82B28CA0
// RVA : 0x00B28CA0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_ds_Group_FollowLeader::UpdateOthers(idVS_ds_Group_FollowLeader *this)
{
  int num; // r11
  int v3; // r31
  int v4; // r26
  idList<idEntityPtr<idVehicleAI>,5> *p_others; // r29
  int v6; // r30
  idEntityPtr<idVehicleAI> *v7; // r11
  idVehicleAI *v8; // r3
  idVehicleAI *v9; // r3
  int v10; // r11
  int v11; // r11

  num = this->others.num;
  v3 = 0;
  v4 = num;
  if ( num > 0 )
  {
    p_others = &this->others;
    v6 = 0;
    do
    {
      v7 = &p_others->list[v6];
      if ( gameLocal->spawnIds.ptr[v7->spawnId.value & 0x1FFF] != v7->spawnId.value >> 13
        || ((v8 = (idVehicleAI *)gameLocal->entities.ptr[v7->spawnId.value & 0x1FFF]) == nullptr
          ? (v9 = nullptr)
          : (v9 = idVehicleAI::CastTo(c: v8)),
            (v9->thinkFlags & 1) == 0) )
      {
        if ( v3 >= 0 )
        {
          v10 = p_others->num;
          if ( v3 < v10 )
          {
            v11 = v10 - 1;
            p_others->num = v11;
            if ( v3 != v11 )
              p_others->list[v6].spawnId.value = p_others->list[v11].spawnId.value;
          }
        }
        --v3;
        --v6;
      }
      num = this->others.num;
      ++v3;
      ++v6;
    }
    while ( v3 < num );
  }
  if ( v4 != num )
    idVS_ds_Group_FollowLeader::AssignFollowing(this);
}


// ========================================================================
// ?GetNextSplineWayPoint@idVS_ds_Car_Chase@@QAAPAVidSplineWaypoint@@XZ
// EA  : 0x82B28DC8
// RVA : 0x00B28DC8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

idSplineWaypoint *__fastcall idVS_ds_Car_Chase::GetNextSplineWayPoint(idVS_ds_Car_Chase *this)
{
  idVehicleAI *ai; // r11
  idSplineWaypoint *result; // r3
  int v4; // r29
  int v5; // r27
  int v6; // r30
  idVehicleAI *v7; // r11
  int v8; // r9
  idEntity *v9; // r3
  idSplineWaypoint *v10; // r3
  int v11; // r28
  int num; // r25
  signed int v13; // r30
  int v14; // r29
  encounterGroupRole_t *list; // r26
  idSplineWaypoint *currentWayPoint; // r11
  int value; // r9
  idEntity *v18; // r3
  idSplineWaypoint *v19; // r3
  idSplineWaypoint *v20; // r3
  int v21; // r10
  encounterGroupRole_t *v22; // r11
  unsigned int v23; // r6
  int v24; // r4
  encounterGroupRole_t v25; // r30
  idSplineWaypoint *v26; // [sp+50h] [-70h] BYREF
  idList<enum encounterGroupRole_t,5> v27[6]; // [sp+60h] [-60h] BYREF

  if ( this->currentWayPoint != nullptr )
  {
    memset(v27, 0, 14);
    v27[0].listStatic = 0;
    v27[0].memTag = 5;
    idList<idThread *,58>::Clear(this: (idList<idVehicleState *,5> *)v27);
    v11 = 0;
    num = this->currentWayPoint->targets.num;
    if ( num <= 0 )
    {
      v13 = v27[0].num;
      list = v27[0].list;
    }
    else
    {
      v13 = v27[0].num;
      v14 = 0;
      list = v27[0].list;
      do
      {
        currentWayPoint = this->currentWayPoint;
        if ( v11 < currentWayPoint->targets.num
          && (value = currentWayPoint->targets.list[v14].spawnId.value,
              gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13) )
        {
          v18 = gameLocal->entities.ptr[value & 0x1FFF];
          if ( v18 != nullptr )
            v19 = (idSplineWaypoint *)idEntity::CastTo(c: v18);
          else
            v19 = nullptr;
        }
        else
        {
          v19 = nullptr;
        }
        v20 = idSplineWaypoint::CastTo(c: v19);
        v26 = v20;
        if ( v20 != nullptr )
        {
          v21 = 0;
          if ( v13 <= 0 )
            goto LABEL_27;
          v22 = list;
          while ( *(idSplineWaypoint **)v22 != v20 )
          {
            ++v21;
            ++v22;
            if ( v21 >= v13 )
              goto LABEL_27;
          }
          if ( v21 < 0 )
          {
LABEL_27:
            idList<idAnimWebBlendTree *,5>::Append(this: v27, obj: (const encounterGroupRole_t *)&v26);
            v13 = v27[0].num;
            list = v27[0].list;
          }
        }
        ++v11;
        ++v14;
      }
      while ( v11 < num );
    }
    if ( v13 > 0 )
    {
      __twllei(v13, 0);
      v23 = 1664525 * clientGame->random.seed + 1013904223;
      clientGame->random.seed = v23;
      v24 = (v23 >> 10) & 0x7FFF;
      __twlgei(v13 & ~(__ROL4__(v24, 1) - 1), 0xFFFFFFFF);
      v25 = list[v24 % v13];
      if ( (v27[0].listStatic == 0 || v27[0].listStatic == 2) && list != nullptr )
        idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
      return (idSplineWaypoint *)v25;
    }
    else
    {
      if ( (v27[0].listStatic == 0 || v27[0].listStatic == 2) && list != nullptr )
        idMem::Free(this: &mem, ptr: list, align: ALIGN_16);
      return nullptr;
    }
  }
  else
  {
    ai = this->ai;
    result = nullptr;
    v4 = 0;
    v5 = ai->targets.num;
    if ( v5 > 0 )
    {
      v6 = 0;
      do
      {
        v7 = this->ai;
        if ( v4 < v7->targets.num
          && (v8 = v7->targets.list[v6].spawnId.value, gameLocal->spawnIds.ptr[v8 & 0x1FFF] == v8 >> 13)
          && (v9 = gameLocal->entities.ptr[v8 & 0x1FFF]) != nullptr )
        {
          v10 = (idSplineWaypoint *)idEntity::CastTo(c: v9);
        }
        else
        {
          v10 = nullptr;
        }
        result = idSplineWaypoint::CastTo(c: v10);
        if ( result != nullptr )
          break;
        ++v4;
        ++v6;
      }
      while ( v4 < v5 );
    }
  }
  return result;
}


// ========================================================================
// __unwind$499919
// EA  : 0x82B29074
// RVA : 0x00B29074
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void _unwind_499919()
{
  int v0; // r12

  idList<idDeclSecretType const *,5>::~idList<idDeclSecretType const *,5>(this: (idStaticList<idVehicleState *,4> *)(v0 - 192 + 96));
}


// ========================================================================
// ?InternalEnterState@idVS_as_RAM@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B29118
// RVA : 0x00B29118
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_RAM::InternalEnterState(idVS_as_RAM *this, idFiniteStateMachine *baseFSM, const int curTime)
{
  __int64 v4; // r10
  idVehicleAI *ai; // r3
  int v6; // r8
  int v7; // r7
  int v8; // r6
  long double v9; // fp2
  idNavPathPosTracker *EnemyTracker; // r3
  idNavPathPosTracker *SplineTracker; // r3
  float distance; // [sp+60h] [-70h]
  idVec3 *rightDistance_low; // [sp+64h] [-6Ch]
  vaiControl_t v14; // [sp+70h] [-60h] BYREF

  idVehicleAI::PushControlParams(this: this->ai);
  LODWORD(v4) = 0x82000000;
  HIDWORD(v4) = 0x82000000;
  ai = this->ai;
  v14.avoidanceType = OAT_INIT;
  this->driveTowardsEnemy = true;
  v14.powerTurnTime = -1;
  v14.speedLimit = -1.0;
  v14.moveDistance = -1.0;
  v14.maxCurveSpeed = -1.0;
  v14.maxCurveAngle = -1.0;
  v14.maxStepAngle = -1.0;
  v14.powerTurnSpeed = -1.0;
  v14.stopPowerTurnSpeed = -1.0;
  v14.traversalStepSize = -1.0;
  v14.backupSpeed = -1.0;
  v14.maxCurveCosine = -1.0;
  v14.maxStepCosine = -1.0;
  v14.decelDistance = 0.0;
  v14.stopDistance = 0.0;
  idVehicleAI::UpdateControlParams(this: ai, params: &v14, initialize: false, a4: v9, a5: v8, a6: v7, a7: v6, a8: v4);
  idVehicleAI::SetCollideAttack(this: this->ai, bl: true);
  EnemyTracker = idVehicleAI::GetEnemyTracker(this: this->ai);
  distance = EnemyTracker->pathPosition.distance;
  rightDistance_low = (idVec3 *)LODWORD(EnemyTracker->pathPosition.rightDistance);
  SplineTracker = idVehicleAI::GetSplineTracker(this: this->ai);
  if ( idNavSplinePathMgr::GetPathDistance(
         this: (idNavSplinePathMgr *)&gameLocal->aiSplinePathMgr.trackerPool.trackers[-1].userPath[0].path.num,
         start: (idNavSplinePosition *)LODWORD(SplineTracker->pathPosition.rightDistance),
         end: (idNavSplinePosition *)__ROL4__(SplineTracker->pathPosition.navSpline, 32),
         forward: rightDistance_low,
         includeRightDistance: *(_DWORD *)(LODWORD(distance) - 16600)) < 500.0 )
  {
    this->moveAwayFromEnemy = true;
    idVS_as_RAM::SetMoveAwayPos(this);
  }
}


// ========================================================================
// ?InternalWork@idVS_as_RAM@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B29230
// RVA : 0x00B29230
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_RAM::InternalWork(idVS_as_RAM *this, idFiniteStateMachine *baseFSM, const int curTime)
{
  idNavPathPosTracker *EnemyTracker; // r3
  idVehicleAI *ai; // r3
  float distance; // r10
  float rightDistance; // r9
  idNavPathPosTracker *SplineTracker; // r3
  double PathDistance; // fp28
  idNavPathPosTracker *v10; // r3
  float v11; // r11
  float v12; // r9
  idVec3 *WorldPos; // r3
  double y; // fp10
  double v15; // fp11
  idVehicleAI *v16; // r3
  idNavPathPosTracker *v17; // r3
  float v18; // r29
  float x; // r9
  idNavPathPosTracker *v20; // r3
  double CurrentSpeedInMPH; // fp1
  char v22; // r29
  idVehicle_Car *VehicleCar; // r3
  const void *LastCollision; // r3
  idEntity *v25; // r26
  idEntity *v26; // r26
  int v27; // r3
  idVehicleAI *v28; // r3
  idPhysics *Physics; // r3
  float *v30; // r3
  double v31; // fp9
  double v32; // fp8
  idVehicleAI *v33; // r10
  float v34; // r9
  float v35; // r3
  float z; // r10
  double AttackRange; // fp1
  idVehicleAI *v38; // r3
  idEntity *Enemy; // r3
  idVehicleAI *v40; // r3
  idPhysics *v41; // r3
  float *v42; // r3
  idVehicleAI *v43; // r11
  double v44; // fp12
  double v45; // fp11
  BOOL moveAwayFromEnemy; // r7
  float v47; // r6
  float v48; // r5
  idColor *v49; // r10
  double v50; // fp0
  double v51; // fp13
  double v52; // fp0
  idNavSplinePosition v53; // [sp+60h] [-190h] BYREF
  float r; // [sp+70h] [-180h] BYREF
  float g; // [sp+74h] [-17Ch]
  float b; // [sp+78h] [-178h]
  float a; // [sp+7Ch] [-174h]
  float v58; // [sp+80h] [-170h] BYREF
  float v59; // [sp+84h] [-16Ch]
  float v60; // [sp+88h] [-168h]
  float v61; // [sp+8Ch] [-164h]
  float v62; // [sp+90h] [-160h] BYREF
  float v63; // [sp+94h] [-15Ch]
  float v64; // [sp+98h] [-158h]
  idVec3 v65; // [sp+A0h] [-150h] BYREF
  float v66[4]; // [sp+B0h] [-140h] BYREF
  float v67[4]; // [sp+C0h] [-130h] BYREF
  float v68[4]; // [sp+D0h] [-120h] BYREF
  float v69[4]; // [sp+E0h] [-110h] BYREF
  float v70[4]; // [sp+F0h] [-100h] BYREF
  float v71[4]; // [sp+100h] [-F0h] BYREF
  float v72[4]; // [sp+110h] [-E0h] BYREF
  float v73[4]; // [sp+120h] [-D0h] BYREF
  idEntityPtr<idEntity> v74[34]; // [sp+130h] [-C0h] BYREF

  if ( idVehicleAI::GetEnemyTracker(this: this->ai) != nullptr )
  {
    EnemyTracker = idVehicleAI::GetEnemyTracker(this: this->ai);
    distance = EnemyTracker->pathPosition.distance;
    rightDistance = EnemyTracker->pathPosition.rightDistance;
    ai = this->ai;
    v53.distance = distance;
    v53.rightDistance = rightDistance;
    SplineTracker = idVehicleAI::GetSplineTracker(this: ai);
    PathDistance = idNavSplinePathMgr::GetPathDistance(
                     this: (idNavSplinePathMgr *)&gameLocal->aiSplinePathMgr.trackerPool.trackers[-1].userPath[0].path.num,
                     start: (idNavSplinePosition *)LODWORD(SplineTracker->pathPosition.rightDistance),
                     end: (idNavSplinePosition *)__ROL4__(SplineTracker->pathPosition.navSpline, 32),
                     forward: (idVec3 *)LODWORD(v53.rightDistance),
                     includeRightDistance: SLOBYTE(vec3_origin.x));
    if ( this->moveAwayFromEnemy )
    {
      idStr::operator=(this: &this->debugInfo, text: "AWAY");
      idVehicleAI::SetSpeedLimit(this: this->ai, speed: 60.0);
      if ( this->ai->distanceToFinalGoal < 500.0 || __fabs(PathDistance) >= 2500.0 )
      {
        this->moveAwayFromEnemy = false;
        this->driveTowardsEnemy = true;
      }
    }
    else if ( this->driveTowardsEnemy )
    {
      v10 = idVehicleAI::GetEnemyTracker(this: this->ai);
      v11 = *(float *)&v10->pathPosition.navSpline;
      v12 = v10->pathPosition.rightDistance;
      v65.x = v10->pathPosition.distance;
      v65.z = v11;
      v65.y = v12;
      if ( vai_debug_attackstate_draw.valueInteger != 0 )
      {
        v67[0] = idColor::colorPink.r;
        v67[1] = idColor::colorPink.g;
        v67[2] = idColor::colorPink.b;
        v67[3] = idColor::colorPink.a;
        WorldPos = idNavSplinePosition::GetWorldPos(this: &v53, result: &v65);
        y = WorldPos->y;
        v15 = (float)(WorldPos->z + (float)45.0);
        v69[0] = WorldPos->x;
        v69[3] = 25.0;
        v69[1] = y;
        v69[2] = v15;
        clientGame->renderWorld->DebugSphere(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)v67,
          a3: (const idSphere *)v69,
          a4: 12,
          a5: 0,
          a6: false);
        if ( vai_debug_attackstate_draw.valueInteger != 0 )
        {
          v16 = this->ai;
          v73[0] = idColor::colorOrange.r;
          v73[1] = idColor::colorOrange.g;
          v73[2] = idColor::colorOrange.b;
          v73[3] = idColor::colorOrange.a;
          v17 = idVehicleAI::GetEnemyTracker(this: v16);
          v18 = v17->worldPosition.y;
          v53.navSpline = (idNavSpline *)LODWORD(v17->worldPosition.z);
          x = v17->worldPosition.x;
          v53.rightDistance = v18;
          v71[3] = 25.0;
          v71[1] = v18;
          v53.distance = x;
          v71[0] = x;
          v71[2] = *(float *)&v53.navSpline + (float)40.0;
          clientGame->renderWorld->DebugSphere(
            this: clientGame->renderWorld,
            a2: (const idVec4 *)v73,
            a3: (const idSphere *)v71,
            a4: 12,
            a5: 0,
            a6: false);
        }
      }
      idVehicleAI::MoveToPosition(
        this: (idVehicleAI *)LODWORD(v65.x),
        pathPos: (idNavSplinePosition *)LODWORD(v65.y),
        isStoppingGoal: __ROL4__(LODWORD(v65.z), 32),
        passThroughGoal: 1u,
        a5: false);
      v20 = idVehicleAI::GetEnemyTracker(this: this->ai);
      CurrentSpeedInMPH = idNavPathPosTracker::GetCurrentSpeedInMPH(this: v20);
      if ( CurrentSpeedInMPH < 70.0 )
        CurrentSpeedInMPH = 70.0;
      idVehicleAI::SetSpeedLimit(this: this->ai, speed: (float)((float)CurrentSpeedInMPH + (float)20.0));
      v22 = 0;
      VehicleCar = idVehicleAI::GetVehicleCar(this: this->ai);
      LastCollision = (const void *)idVehicle::GetLastCollision(this: VehicleCar);
      memcpy(Dst: v74, Src: LastCollision, Size: 0x68u);
      if ( gameLocal->spawnIds.ptr[v74[3].spawnId.value & 0x1FFF] == v74[3].spawnId.value >> 13 )
      {
        v25 = idEntityPtr<idEntity const>::operator->(this: &v74[3]);
        if ( v25 == idVehicleAI::GetEnemy(this: this->ai)
          || (v26 = idEntityPtr<idEntity const>::operator->(this: &v74[3])) == idVehicleAI::GetEnemyVehicle(this: this->ai) )
        {
          v27 = gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED);
          if ( v27 - v74[0].spawnId.value < 1000 )
            v22 = 1;
        }
      }
      v28 = this->ai;
      if ( v28->distanceToFinalGoal < 100.0 )
      {
        v22 = 1;
        if ( vai_debug_attackstate_draw.valueInteger != 0 )
        {
          Physics = idEntity::GetPhysics(this: v28);
          v30 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
          v31 = (float)(v30[2] + (float)50.0);
          v32 = v30[1];
          v58 = *v30;
          v59 = v32;
          v61 = 100.0;
          v68[1] = idColor::colorCyan.g;
          v68[2] = idColor::colorCyan.b;
          v68[3] = idColor::colorCyan.a;
          v68[0] = idColor::colorCyan.r;
          v60 = v31;
          clientGame->renderWorld->DebugSphere(
            this: clientGame->renderWorld,
            a2: (const idVec4 *)v68,
            a3: (const idSphere *)&v58,
            a4: 24,
            a5: 5000,
            a6: true);
          v33 = this->ai;
          v34 = v33->finalGoalPosition.x;
          v35 = v33->finalGoalPosition.y;
          z = v33->finalGoalPosition.z;
          v70[0] = idColor::colorCyan.r;
          v61 = 25.0;
          v70[1] = idColor::colorCyan.g;
          v53.distance = v34;
          v53.rightDistance = v35;
          *(float *)&v53.navSpline = z;
          v70[2] = idColor::colorCyan.b;
          v70[3] = idColor::colorCyan.a;
          v58 = v34;
          v59 = v35;
          v60 = z + (float)50.0;
          clientGame->renderWorld->DebugSphere(
            this: clientGame->renderWorld,
            a2: (const idVec4 *)v70,
            a3: (const idSphere *)&v58,
            a4: 24,
            a5: 5000,
            a6: true);
        }
      }
      if ( v22 != 0 )
      {
        idVS_as_RAM::SetMoveAwayPos(this);
        ++this->ai->numAttackAttempts;
        *(_WORD *)&this->driveTowardsEnemy = 1;
      }
    }
    else
    {
      idStr::operator=(this: &this->debugInfo, text: "? ? ?");
      if ( this->ai->distanceToFinalGoal < 400.0 )
        this->driveTowardsEnemy = true;
    }
    AttackRange = idVehicleAI::GetAttackRange(this: this->ai);
    v38 = this->ai;
    if ( PathDistance >= (float)((float)AttackRange * (float)0.5) )
    {
      idVehicleAI::StopFiringWeapon(this: v38);
    }
    else
    {
      Enemy = idVehicleAI::GetEnemy(this: v38);
      idVehicleAI::SetTarget(this: this->ai, entity: Enemy);
      idVehicleAI::FireWeapon(this: this->ai);
    }
    if ( vai_debug_attackstate_draw.valueInteger != 0 )
    {
      v40 = this->ai;
      r = idColor::colorRed.r;
      g = idColor::colorRed.g;
      b = idColor::colorRed.b;
      a = idColor::colorRed.a;
      v41 = idEntity::GetPhysics(this: v40);
      v42 = (float *)v41->GetOrigin(this: v41, a2: 0);
      v43 = this->ai;
      v44 = (float)(v42[2] + (float)50.0);
      v45 = *v42;
      moveAwayFromEnemy = this->moveAwayFromEnemy;
      v66[1] = v42[1];
      v66[2] = v44;
      v66[0] = v45;
      v47 = v43->finalGoalPosition.x;
      v48 = v43->finalGoalPosition.z;
      v63 = v43->finalGoalPosition.y;
      v62 = v47;
      v64 = v48;
      if ( !moveAwayFromEnemy )
      {
        if ( this->driveTowardsEnemy )
        {
          v49 = &idColor::colorGreen;
          v50 = idColor::colorGreen.r;
        }
        else
        {
          v49 = &idColor::colorYellow;
          v50 = idColor::colorYellow.r;
        }
        r = v50;
        v51 = v49->b;
        v52 = v49->g;
        a = v49->a;
        b = v51;
        g = v52;
      }
      clientGame->renderWorld->DebugLine(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&r,
        a3: (const idVec3 *)v66,
        a4: (const idVec3 *)&v62,
        a5: 0,
        a6: false);
      v72[3] = 25.0;
      v72[0] = v62;
      v72[1] = v63;
      v72[2] = v64;
      clientGame->renderWorld->DebugSphere(
        this: clientGame->renderWorld,
        a2: (const idVec4 *)&r,
        a3: (const idSphere *)v72,
        a4: 12,
        a5: 0,
        a6: false);
    }
  }
  else
  {
    idStr::operator=(this: &this->debugInfo, text: "No Enemy Tracker");
  }
}


// ========================================================================
// ?InternalEnterState@idVS_as_StrafeShoot@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B29910
// RVA : 0x00B29910
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_StrafeShoot::InternalEnterState(
        idVS_as_StrafeShoot *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  __int64 v4; // r10
  idVehicleAI *ai; // r3
  int v6; // r8
  int v7; // r7
  int v8; // r6
  long double v9; // fp2
  idVehicleAI *v10; // r3
  idNavPathPosTracker *EnemyTracker; // r3
  idNavPathPosTracker *SplineTracker; // r3
  __int128 v13; // r6
  float distance; // [sp+60h] [-70h]
  idVec3 *rightDistance_low; // [sp+64h] [-6Ch]
  vaiControl_t v16; // [sp+70h] [-60h] BYREF

  idVehicleAI::PushControlParams(this: this->ai);
  LODWORD(v4) = 0x82000000;
  HIDWORD(v4) = 0x82000000;
  ai = this->ai;
  v16.avoidanceType = OAT_INIT;
  v16.powerTurnTime = -1;
  v16.speedLimit = -1.0;
  v16.moveDistance = -1.0;
  v16.maxCurveSpeed = -1.0;
  v16.maxCurveAngle = -1.0;
  v16.maxStepAngle = -1.0;
  v16.powerTurnSpeed = -1.0;
  v16.stopPowerTurnSpeed = -1.0;
  v16.traversalStepSize = -1.0;
  v16.backupSpeed = -1.0;
  v16.maxCurveCosine = -1.0;
  v16.maxStepCosine = -1.0;
  v16.decelDistance = 0.0;
  v16.stopDistance = 0.0;
  idVehicleAI::UpdateControlParams(this: ai, params: &v16, initialize: false, a4: v9, a5: v8, a6: v7, a7: v6, a8: v4);
  v10 = this->ai;
  *(_WORD *)&this->moveAwayFromEnemy = 1;
  EnemyTracker = idVehicleAI::GetEnemyTracker(this: v10);
  distance = EnemyTracker->pathPosition.distance;
  rightDistance_low = (idVec3 *)LODWORD(EnemyTracker->pathPosition.rightDistance);
  SplineTracker = idVehicleAI::GetSplineTracker(this: this->ai);
  if ( idNavSplinePathMgr::GetPathDistance(
         this: (idNavSplinePathMgr *)&gameLocal->aiSplinePathMgr.trackerPool.trackers[-1].userPath[0].path.num,
         start: (idNavSplinePosition *)LODWORD(SplineTracker->pathPosition.rightDistance),
         end: (idNavSplinePosition *)__ROL4__(SplineTracker->pathPosition.navSpline, 32),
         forward: rightDistance_low,
         includeRightDistance: *(_DWORD *)(LODWORD(distance) - 16600)) < 500.0 )
  {
    this->moveAwayFromEnemy = true;
    HIDWORD(v13) = idVehicleAI::GetEnemyTracker(this: this->ai);
    *(_QWORD *)((char *)&v13 + 4) = *(_QWORD *)(HIDWORD(v13) + 4);
    LODWORD(v13) = __ROL4__(*(_DWORD *)(HIDWORD(v13) + 12), 32);
    idVS_as_StrafeShoot::SetMoveAwayPos(this, range: 4000.0, enemyPos: v13);
  }
}


// ========================================================================
// ?InternalWork@idVS_as_StrafeShoot@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B29A48
// RVA : 0x00B29A48
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_StrafeShoot::InternalWork(
        idVS_as_StrafeShoot *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  idNavPathPosTracker *EnemyTracker; // r3
  idNavPathPosTracker *SplineTracker; // r3
  char v8; // r5
  float distance; // r8
  idNavSpline *navSpline; // r11
  __int64 v11; // r4
  idNavPathPosTracker *v12; // r3
  float rightDistance; // r7
  float v14; // r6
  idVehicleAI *ai; // r10
  idVec3 *WorldPos; // r29
  idVec3 *v17; // r3
  double v18; // fp10
  double v19; // fp8
  idVehicleAI *v20; // r3
  float z; // r30
  double AttackRange; // fp1
  idPhysics *Physics; // r3
  float *v24; // r30
  idVec3 *v25; // r3
  double v26; // fp31
  double v27; // fp30
  double v28; // fp29
  double v29; // fp28
  idNavPathPosTracker *v30; // r3
  idVehicleAI *v31; // r3
  float v32; // r10
  float v33; // r9
  idNavSpline *v34; // r8
  double v35; // fp31
  double v36; // fp0
  float v37; // r10
  float v38; // r8
  idVehicleAI *v39; // r3
  idNavSpline *v40; // r30
  double v41; // fp1
  idVehicleAI *v42; // r30
  idVehicleAI *v43; // r3
  idPhysics *v44; // r3
  float *v45; // r3
  double v46; // fp13
  double v47; // fp12
  idVehicleAI *v48; // r11
  BOOL moveAwayFromEnemy; // r6
  float y; // r4
  float v51; // r3
  idColor *v52; // r10
  double v53; // fp0
  double v54; // fp13
  double v55; // fp0
  idEntity *Enemy; // r3
  idNavSplinePosition v57; // [sp+50h] [-C0h] BYREF
  idVec3 v58; // [sp+60h] [-B0h] BYREF
  float x; // [sp+70h] [-A0h] BYREF
  float v60; // [sp+74h] [-9Ch]
  float v61; // [sp+78h] [-98h]
  idNavSplinePosition v62; // [sp+80h] [-90h] BYREF
  float v63[4]; // [sp+90h] [-80h] BYREF
  idNavSplinePosition v64; // [sp+A0h] [-70h] BYREF
  float r; // [sp+B0h] [-60h] BYREF
  float g; // [sp+B4h] [-5Ch]
  float b; // [sp+B8h] [-58h]
  float a; // [sp+BCh] [-54h]
  float v69[12]; // [sp+C0h] [-50h] BYREF

  if ( idVehicleAI::GetEnemyTracker(this: this->ai) != nullptr )
  {
    EnemyTracker = idVehicleAI::GetEnemyTracker(this: this->ai);
    _FP12 = (float)((float)80.0 - (float)(idNavPathPosTracker::GetCurrentSpeedInMPH(this: EnemyTracker) + (float)15.0));
    __asm { fsel      f1, f12, f0, f13# speed }
    idVehicleAI::SetSpeedLimit(this: this->ai, speed: _FP1);
    if ( this->moveAwayFromEnemy )
    {
      SplineTracker = idVehicleAI::GetSplineTracker(this: this->ai);
      v8 = __ROL4__(this->moveAwayPos.navSpline, 32);
      distance = SplineTracker->pathPosition.distance;
      navSpline = SplineTracker->pathPosition.navSpline;
      v62.rightDistance = SplineTracker->pathPosition.rightDistance;
      this->moveAwayPos.rightDistance = v62.rightDistance;
      v11 = *(_QWORD *)&this->moveAwayPos.distance;
      v62.distance = distance;
      v62.navSpline = navSpline;
      idVehicleAI::MoveToPosition(
        this: (idVehicleAI *)HIDWORD(v11),
        pathPos: (idNavSplinePosition *)v11,
        isStoppingGoal: v8,
        passThroughGoal: 1u,
        a5: false);
      v12 = idVehicleAI::GetEnemyTracker(this: this->ai);
      rightDistance = v12->pathPosition.rightDistance;
      v14 = *(float *)&v12->pathPosition.navSpline;
      ai = this->ai;
      v58.x = v12->pathPosition.distance;
      v58.y = rightDistance;
      v58.z = v14;
      if ( ai->distanceToFinalGoal >= 500.0 )
      {
        WorldPos = idNavSplinePosition::GetWorldPos(this: &v62, result: &v58);
        v17 = idNavSplinePosition::GetWorldPos(this: &v64, result: (idVec3 *)&this->moveAwayPos);
        v18 = (float)(WorldPos->y - v17->y);
        v19 = (float)(WorldPos->z - v17->z);
        if ( (float)((float)((float)(WorldPos->x - v17->x) * (float)(WorldPos->x - v17->x))
                   + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18))) < 360000.0 )
        {
          v20 = this->ai;
          z = v58.z;
          *(_QWORD *)&v62.distance = *(_QWORD *)&v58.x;
          AttackRange = idVehicleAI::GetAttackRange(this: v20);
          idVS_as_StrafeShoot::SetMoveAwayPos(
            this,
            range: AttackRange,
            enemyPos: __SPAIR64__(LODWORD(v62.rightDistance), __ROL4__(LODWORD(z), 32)));
          ++this->ai->numAttackAttempts;
        }
      }
      else
      {
        *(_WORD *)&this->moveAwayFromEnemy = 1;
      }
      Physics = idEntity::GetPhysics(this: this->ai);
      v24 = (float *)Physics->GetOrigin(this: Physics, a2: 0);
      v25 = idNavSplinePosition::GetWorldPos(this: &v64, result: &v58);
      v26 = (float)(v25->x - *v24);
      v27 = (float)(v25->y - v24[1]);
      v28 = (float)(v25->z - v24[2]);
      v29 = idVehicleAI::GetAttackRange(this: this->ai);
      if ( (float)((float)((float)v26 * (float)v26)
                 + (float)((float)((float)v28 * (float)v28) + (float)((float)v27 * (float)v27))) >= (double)(float)((float)v29 * idVehicleAI::GetAttackRange(this: this->ai)) )
      {
        idVehicleAI::StopFiringWeapon(this: this->ai);
        idStr::operator=(this: &this->debugInfo, text: "AWAY");
      }
      else
      {
        idStr::operator=(this: &this->debugInfo, text: "AWAY FIRE");
        idVehicleAI::FireWeapon(this: this->ai);
      }
    }
    else if ( this->driveTowardsEnemy )
    {
      v30 = idVehicleAI::GetEnemyTracker(this: this->ai);
      v32 = v30->pathPosition.distance;
      v33 = v30->pathPosition.rightDistance;
      v34 = v30->pathPosition.navSpline;
      v31 = this->ai;
      v57.distance = v32;
      v57.rightDistance = v33;
      v57.navSpline = v34;
      v35 = idVehicleAI::NormalizeEnemyRightDistance(this: v31);
      if ( idVehicleAI::GetSplineTracker(this: this->ai)->pathPosition.rightDistance <= v35 )
        v36 = (float)((float)v35 - (float)400.0);
      else
        v36 = (float)((float)v35 + (float)400.0);
      v57.rightDistance = v36;
      idNavSplinePosition::Validate(this: &v57, nextSpline: nullptr, prevSpline: nullptr);
      idVehicleAI::MoveToPosition(
        this: (idVehicleAI *)LODWORD(v57.distance),
        pathPos: (idNavSplinePosition *)LODWORD(v57.rightDistance),
        isStoppingGoal: __ROL4__(v57.navSpline, 32),
        passThroughGoal: 1u,
        a5: false);
      if ( this->ai->distanceToFinalGoal < 600.0 || idNavSplinePosition::IsOnDeadendPath(this: &v57) )
      {
        v37 = v57.distance;
        v38 = v57.rightDistance;
        this->driveTowardsEnemy = false;
        this->moveAwayFromEnemy = true;
        v39 = this->ai;
        v40 = v57.navSpline;
        v62.distance = v37;
        v62.rightDistance = v38;
        v41 = idVehicleAI::GetAttackRange(this: v39);
        idVS_as_StrafeShoot::SetMoveAwayPos(
          this,
          range: v41,
          enemyPos: __SPAIR64__(LODWORD(v62.rightDistance), __ROL4__(v40, 32)));
        ++this->ai->numAttackAttempts;
      }
      v42 = this->ai;
      if ( v42->distanceToFinalGoal >= (double)idVehicleAI::GetAttackRange(this: v42) )
      {
        idVehicleAI::StopFiringWeapon(this: this->ai);
        idStr::operator=(this: &this->debugInfo, text: "TOWARDS");
      }
      else
      {
        idStr::operator=(this: &this->debugInfo, text: "TOWARDS FIRE");
        idVehicleAI::FireWeapon(this: this->ai);
      }
    }
    else
    {
      idStr::operator=(this: &this->debugInfo, text: "? ? ?");
      idVehicleAI::StopFiringWeapon(this: this->ai);
      if ( this->ai->distanceToFinalGoal < 600.0 )
        this->driveTowardsEnemy = true;
    }
    if ( vai_debug_attackstate_draw.valueInteger == 0 )
      goto LABEL_29;
    v43 = this->ai;
    r = idColor::colorRed.r;
    g = idColor::colorRed.g;
    b = idColor::colorRed.b;
    a = idColor::colorRed.a;
    v44 = idEntity::GetPhysics(this: v43);
    v45 = (float *)v44->GetOrigin(this: v44, a2: 0);
    v46 = v45[2];
    v47 = v45[1];
    v48 = this->ai;
    moveAwayFromEnemy = this->moveAwayFromEnemy;
    v63[0] = *v45;
    v63[1] = v47;
    v63[2] = (float)v46 + (float)55.0;
    y = v48->finalGoalPosition.y;
    v51 = v48->finalGoalPosition.z;
    x = v48->finalGoalPosition.x;
    v60 = y;
    v61 = v51;
    if ( moveAwayFromEnemy )
    {
      v52 = &idColor::colorGreen;
      v53 = idColor::colorGreen.r;
    }
    else
    {
      if ( this->driveTowardsEnemy )
      {
LABEL_28:
        clientGame->renderWorld->DebugLine(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)&r,
          a3: (const idVec3 *)v63,
          a4: (const idVec3 *)&x,
          a5: 0,
          a6: false);
        v69[1] = v60;
        v69[2] = v61;
        v69[3] = 25.0;
        v69[0] = x;
        clientGame->renderWorld->DebugSphere(
          this: clientGame->renderWorld,
          a2: (const idVec4 *)&r,
          a3: (const idSphere *)v69,
          a4: 12,
          a5: 0,
          a6: false);
LABEL_29:
        Enemy = idVehicleAI::GetEnemy(this: this->ai);
        idVehicleAI::SetTarget(this: this->ai, entity: Enemy);
        return;
      }
      v52 = &idColor::colorYellow;
      v53 = idColor::colorYellow.r;
    }
    r = v53;
    v54 = v52->b;
    v55 = v52->g;
    a = v52->a;
    b = v54;
    g = v55;
    goto LABEL_28;
  }
}


// ========================================================================
// ?InternalWork@idVS_as_HitAndRun@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B29FB8
// RVA : 0x00B29FB8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_HitAndRun::InternalWork(
        idVS_as_HitAndRun *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  char v4; // r28
  int value; // r9
  idVehicle_Car *v6; // r3
  idVehicle_Car *v7; // r3
  int v8; // r9
  idEntity *v9; // r3
  idVehicle_Car *v10; // r3
  idVehicle_Car *v11; // r30
  idPlayer *v12; // r30
  idVehicle_Car *VehicleCar; // r3
  _DWORD *LastCollision; // r30
  int v15; // r11
  unsigned int v16; // r7
  idNavPathPosTracker *EnemyTracker; // r3
  __int64 v18; // r6
  int navSpline; // r10
  int v20; // r9
  bool v21; // r8
  idNavPathPosTracker *v22; // r3
  double v23; // fp0
  idNavPathPosTracker *v24; // r3
  double v25; // fp0
  idVehicleAI *ai; // r30
  int v27; // r11
  unsigned int v28; // r7
  idVehicleAI *v29; // r3
  bool v30; // zf
  int v31; // [sp+8h] [-A8h]
  __int64 v32; // [sp+10h] [-A0h]
  __int64 v33; // [sp+18h] [-98h]
  __int64 v34; // [sp+20h] [-90h]
  __int64 v35; // [sp+28h] [-88h]
  __int64 v36; // [sp+30h] [-80h]

  if ( idVehicleAI::GetEnemy(this: this->ai) != nullptr )
  {
    if ( this->state == ST_CHASING )
    {
      v4 = 0;
      value = this->ai->vehicleCar.spawnId.value;
      if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
        && (v6 = (idVehicle_Car *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
      {
        v7 = idVehicle_Car::CastTo(c: v6);
      }
      else
      {
        v7 = nullptr;
      }
      v8 = *(_DWORD *)(idVehicle::GetLastCollision(this: v7) + 12);
      if ( gameLocal->spawnIds.ptr[v8 & 0x1FFF] == v8 >> 13 && (v9 = gameLocal->entities.ptr[v8 & 0x1FFF]) != nullptr )
        v10 = (idVehicle_Car *)idEntity::CastTo(c: v9);
      else
        v10 = nullptr;
      v11 = idVehicle_Car::CastTo(c: v10);
      if ( v11 != nullptr
        && (v11 == idVehicleAI::GetEnemy(this: this->ai)
         || (v12 = idVehicle::PlayerIsOccupant(this: v11)) == idVehicleAI::GetEnemy(this: this->ai)) )
      {
        v4 = 1;
      }
      if ( v4 != 0 )
      {
        VehicleCar = idVehicleAI::GetVehicleCar(this: this->ai);
        LastCollision = (_DWORD *)idVehicle::GetLastCollision(this: VehicleCar);
        if ( *LastCollision <= gameLocal->GetGameMs(this: gameLocal, a2: GAMETIME_SCALED) - 250 )
        {
          this->state = ST_CHASING;
          v16 = 1664525 * clientGame->random.seed + 1013904223;
          clientGame->random.seed = v16;
          this->actionCount = ((v16 >> 10) & 0x7FFF) - 2 * ((int)((v16 >> 10) & 0x7FFF) >> 1) + 1;
        }
        else
        {
          v15 = this->actionCount - 1;
          this->actionCount = v15;
          if ( v15 <= 0 )
            idVS_as_HitAndRun::FleeToWaypoint(this);
        }
      }
      if ( this->state == ST_CHASING )
      {
        EnemyTracker = idVehicleAI::GetEnemyTracker(this: this->ai);
        LODWORD(v18) = 0;
        navSpline = (int)EnemyTracker->pathPosition.navSpline;
        HIDWORD(v18) = __ROL4__(navSpline, 32);
        idVehicleAI::MoveToPathPosition(
          this: (idVehicleAI *)LODWORD(EnemyTracker->pathPosition.distance),
          isStoppingGoal: v18,
          passThroughGoal: true,
          a4: v21,
          a5: v20,
          a6: navSpline,
          a7: v31,
          a8: v32,
          a9: v33,
          a10: v34,
          a11: v35,
          a12: v36);
        v22 = idVehicleAI::GetEnemyTracker(this: this->ai);
        v23 = (float)(idNavPathPosTracker::GetCurrentSpeedInMPH(this: v22) + (float)20.0);
        if ( v23 >= 80.0 )
        {
          if ( v23 > 130.0 )
            v23 = 130.0;
        }
        else
        {
          v23 = 80.0;
        }
        idVehicleAI::SetSpeedLimit(this: this->ai, speed: v23);
      }
    }
    if ( this->state == ST_MOVING_AWAY )
    {
      v24 = idVehicleAI::GetEnemyTracker(this: this->ai);
      v25 = (float)(idNavPathPosTracker::GetCurrentSpeedInMPH(this: v24) + (float)20.0);
      if ( v25 >= 80.0 )
      {
        if ( v25 > 130.0 )
          v25 = 130.0;
      }
      else
      {
        v25 = 80.0;
      }
      idVehicleAI::SetSpeedLimit(this: this->ai, speed: v25);
      ai = this->ai;
      if ( ai->distanceToFinalGoal <= (double)idVehicleAI::GetDecelDistance(this: ai) )
      {
        v27 = this->actionCount - 1;
        this->actionCount = v27;
        if ( v27 > 0 )
        {
          idVS_as_HitAndRun::FleeToWaypoint(this);
        }
        else
        {
          this->state = ST_CHASING;
          v28 = 1664525 * clientGame->random.seed + 1013904223;
          clientGame->random.seed = v28;
          this->actionCount = ((v28 >> 10) & 0x7FFF) - 2 * ((int)((v28 >> 10) & 0x7FFF) >> 1) + 1;
        }
      }
    }
    v30 = idVehicleAI::GetEnemy(this: this->ai) == nullptr;
    v29 = this->ai;
    if ( v30 )
      idVehicleAI::StopFiringWeapon(this: v29);
    else
      idVehicleAI::FireWeapon(this: v29);
  }
}


// ========================================================================
// ?InternalWork@idVS_as_WaypointTag@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B2A2F8
// RVA : 0x00B2A2F8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_as_WaypointTag::InternalWork(
        idVS_as_WaypointTag *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  idNavPathPosTracker *EnemyTracker; // r3
  __int64 v5; // r6
  int navSpline; // r10
  int v7; // r9
  bool v8; // r8
  idNavPathPosTracker *v9; // r3
  double v10; // fp0
  idNavPathPosTracker *v11; // r3
  double v12; // fp0
  idVehicleAI *ai; // r30
  int v14; // r11
  unsigned int v15; // r4
  idVehicleAI *v16; // r3
  bool v17; // zf
  int v18; // [sp+8h] [-78h]
  __int64 v19; // [sp+10h] [-70h]
  __int64 v20; // [sp+18h] [-68h]
  __int64 v21; // [sp+20h] [-60h]
  __int64 v22; // [sp+28h] [-58h]
  __int64 v23; // [sp+30h] [-50h]

  if ( idVehicleAI::GetEnemy(this: this->ai) != nullptr )
  {
    if ( this->state == ST_CHASING )
    {
      if ( this->ai->distanceToFinalGoal <= 4000.0 )
        idVS_as_WaypointTag::FleeToWaypoint(this);
      if ( this->state == ST_CHASING )
      {
        EnemyTracker = idVehicleAI::GetEnemyTracker(this: this->ai);
        LODWORD(v5) = 0;
        navSpline = (int)EnemyTracker->pathPosition.navSpline;
        HIDWORD(v5) = __ROL4__(navSpline, 32);
        idVehicleAI::MoveToPathPosition(
          this: (idVehicleAI *)LODWORD(EnemyTracker->pathPosition.distance),
          isStoppingGoal: v5,
          passThroughGoal: true,
          a4: v8,
          a5: v7,
          a6: navSpline,
          a7: v18,
          a8: v19,
          a9: v20,
          a10: v21,
          a11: v22,
          a12: v23);
        v9 = idVehicleAI::GetEnemyTracker(this: this->ai);
        v10 = (float)(idNavPathPosTracker::GetCurrentSpeedInMPH(this: v9) + (float)20.0);
        if ( v10 >= 80.0 )
        {
          if ( v10 > 130.0 )
            v10 = 130.0;
        }
        else
        {
          v10 = 80.0;
        }
        idVehicleAI::SetSpeedLimit(this: this->ai, speed: v10);
      }
    }
    if ( this->state == ST_MOVING_AWAY )
    {
      v11 = idVehicleAI::GetEnemyTracker(this: this->ai);
      v12 = (float)(idNavPathPosTracker::GetCurrentSpeedInMPH(this: v11) + (float)20.0);
      if ( v12 >= 80.0 )
      {
        if ( v12 > 130.0 )
          v12 = 130.0;
      }
      else
      {
        v12 = 80.0;
      }
      idVehicleAI::SetSpeedLimit(this: this->ai, speed: v12);
      ai = this->ai;
      if ( ai->distanceToFinalGoal <= (double)idVehicleAI::GetDecelDistance(this: ai) )
      {
        v14 = this->actionCount - 1;
        this->actionCount = v14;
        if ( v14 > 0 )
        {
          idVS_as_WaypointTag::FleeToWaypoint(this);
        }
        else
        {
          this->state = ST_CHASING;
          v15 = 1664525 * clientGame->random.seed + 1013904223;
          clientGame->random.seed = v15;
          this->actionCount = ((v15 >> 10) & 0x7FFF) - 2 * ((int)((v15 >> 10) & 0x7FFF) >> 1) + 1;
        }
      }
    }
    v17 = idVehicleAI::GetEnemy(this: this->ai) == nullptr;
    v16 = this->ai;
    if ( v17 )
      idVehicleAI::StopFiringWeapon(this: v16);
    else
      idVehicleAI::FireWeapon(this: v16);
  }
}


// ========================================================================
// ?LeaderUpdate@idVS_ds_Group_FollowLeader@@QAAXXZ
// EA  : 0x82B2A4E8
// RVA : 0x00B2A4E8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_ds_Group_FollowLeader::LeaderUpdate(idVS_ds_Group_FollowLeader *this)
{
  idVehicleAI *ai; // r3
  __int64 v3; // r6
  idVehicleAI *v4; // r4
  idEventArg *v5; // r3
  idVehicle_Car *VehicleCar; // r3
  idVehicleAI *v7; // r3
  idEntity *v8; // r4
  double v9; // fp31
  idNavPathPosTracker *Tracker; // r3
  idNavPathPosTracker *v11; // r30
  int v12; // [sp+8h] [-88h]
  __int64 v13; // [sp+10h] [-80h]
  __int64 v14; // [sp+18h] [-78h]
  __int64 v15; // [sp+20h] [-70h]
  __int64 v16; // [sp+28h] [-68h]
  __int64 v17; // [sp+30h] [-60h]
  idEventArg v18; // [sp+50h] [-40h] BYREF

  idVS_ds_Group_FollowLeader::UpdateOthers(this);
  if ( idVehicleAI::GetEnemy(this: this->ai) == nullptr )
  {
    ai = this->ai;
    if ( gameLocal->spawnIds.ptr[ai->setup.patrol.waypoint.spawnId.value & 0x1FFF] == ai->setup.patrol.waypoint.spawnId.value >> 13 )
    {
      if ( ai->patrolPaths[1].waypoints.num >= 1 )
      {
        idVehicleAI::UpdatePatrolPath(this: ai);
      }
      else
      {
        LODWORD(v3) = 1;
        HIDWORD(v3) = __ROL4__(this->startPos.navSpline, 32);
        idVehicleAI::MoveToPathPosition(
          this: (idVehicleAI *)LODWORD(this->startPos.distance),
          isStoppingGoal: v3,
          passThroughGoal: false,
          a4: ai->setup.patrol.waypoint.spawnId.value >> 13,
          a5: ai->setup.patrol.waypoint.spawnId.value,
          a6: ai->setup.patrol.waypoint.spawnId.value & 0x1FFF,
          a7: v12,
          a8: v13,
          a9: v14,
          a10: v15,
          a11: v16,
          a12: v17);
        v4 = this->ai;
        if ( v4->hideWhenIdle && v4->distanceToFinalGoal <= 500.0 && (v4->thinkFlags & 1) != 0 )
        {
          v5 = idEventArg::idEventArg(this: &v18, data: v4);
          idEventReceiver::PostEventMS(
            this: this->ai,
            ev: &EV_Activate,
            time: *(_DWORD *)&v5->type,
            arg1: (const idEventArg *)LODWORD(v5->value.v[1]));
          VehicleCar = idVehicleAI::GetVehicleCar(this: this->ai);
          VehicleCar->Hide_2(this: VehicleCar);
        }
      }
      v7 = this->ai;
      if ( v7->setup.patrol.fleeNearEnemy )
      {
        v8 = idVehicleAI::EnemyNearMe(this: v7);
        if ( v8 != nullptr )
        {
          v9 = 110.0;
          Tracker = idNavSplinePathMgr::FindTracker(
                      this: (idNavSplinePathMgr *)&gameLocal->aiSplinePathMgr.trackerPool.trackers[-1].userPath[0].path.num,
                      owner: v8,
                      createTrackerIfNotFound: false);
          v11 = Tracker;
          if ( Tracker != nullptr && idNavPathPosTracker::GetCurrentSpeedInMPH(this: Tracker) > 110.0 )
            v9 = (float)(idNavPathPosTracker::GetCurrentSpeedInMPH(this: v11) + (float)10.0);
          idVehicleAI::SetSpeedLimit(this: this->ai, speed: v9);
        }
      }
    }
    else
    {
      idVehicleAI::SetSpeedLimit(this: ai, speed: 0.0);
      this->ai->desiredBraking = 2;
    }
  }
}


// ========================================================================
// ?AddFollower@idVS_ds_Group_FollowLeader@@QAAXPAVidVehicleAI@@@Z
// EA  : 0x82B2A698
// RVA : 0x00B2A698
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_ds_Group_FollowLeader::AddFollower(idVS_ds_Group_FollowLeader *this, idVehicleAI *vai)
{
  int v3; // r7
  int num; // r8
  int v5; // r10
  int v6; // r11
  idEntityPtr<idEntity> v7; // [sp+50h] [-20h] BYREF

  if ( vai != nullptr )
    v3 = (gameLocal->spawnIds.ptr[vai->entityNumber] << 13) | vai->entityNumber;
  else
    v3 = 0x1FFF;
  num = this->others.num;
  v5 = 0;
  v7.spawnId.value = v3;
  if ( num <= 0 )
  {
LABEL_8:
    idList<idEntityPtr<idEntity>,58>::Append(this: (idList<idEntityPtr<idEntity>,58> *)&this->others, obj: &v7);
    idVS_ds_Group_FollowLeader::AssignFollowing(this);
  }
  else
  {
    v6 = 0;
    while ( this->others.list[v6].spawnId.value != v3 )
    {
      ++v5;
      ++v6;
      if ( v5 >= num )
        goto LABEL_8;
    }
  }
}


// ========================================================================
// ?FindLeader@idVS_ds_Group_FollowLeader@@QAAXXZ
// EA  : 0x82B2A740
// RVA : 0x00B2A740
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_ds_Group_FollowLeader::FindLeader(idVS_ds_Group_FollowLeader *this)
{
  idGameLocal *v2; // r9
  idLinkList<idVehicleAI> *next; // r11
  _DWORD *v4; // r31
  idVehicleAI *v5; // r3
  idVehicleAI *v6; // r3
  int v7; // r11
  _DWORD *v8; // r11
  int v9; // r9
  idVehicleAI *v10; // r3
  idVehicleAI *v11; // r3
  idVehicleAI *ai; // r11

  this->leader.spawnId.value = 0x1FFF;
  v2 = gameLocal;
  next = gameLocal->vehicleAIEntities.next;
  if ( next != nullptr && next != gameLocal->vehicleAIEntities.head )
  {
    v4 = &next->owner->__vftable;
    if ( v4 != nullptr )
    {
      while ( 1 )
      {
        if ( v4[586] == this->ai->setup.groupNumber && v2->spawnIds.ptr[v4[1696] & 0x1FFF] == (int)v4[1696] >> 13 )
        {
          v5 = (idVehicleAI *)v2->entities.ptr[v4[1696] & 0x1FFF];
          if ( v5 != nullptr )
          {
            v6 = idVehicleAI::CastTo(c: v5);
            v2 = gameLocal;
          }
          else
          {
            v6 = nullptr;
          }
          if ( (v6->thinkFlags & 1) != 0 )
            break;
        }
        v7 = v4[1094];
        if ( v7 == 0 || v7 == v4[1093] )
          v8 = nullptr;
        else
          v8 = *(_DWORD **)(v7 + 12);
        v4 = v8;
        if ( v8 == nullptr )
          goto LABEL_21;
      }
      v9 = v4[1696];
      this->leader.spawnId.value = v9;
      if ( gameLocal->spawnIds.ptr[v9 & 0x1FFF] == v9 >> 13
        && (v10 = (idVehicleAI *)gameLocal->entities.ptr[v9 & 0x1FFF]) != nullptr )
      {
        v11 = idVehicleAI::CastTo(c: v10);
      }
      else
      {
        v11 = nullptr;
      }
      idVS_ds_Group_FollowLeader::AddFollower(this: &v11->ds_Group_FollowLeader, vai: this->ai);
      this->ai->autoChooseAttackState = false;
      v2 = gameLocal;
    }
  }
LABEL_21:
  if ( v2->spawnIds.ptr[this->leader.spawnId.value & 0x1FFF] != this->leader.spawnId.value >> 13 )
  {
    ai = this->ai;
    if ( ai != nullptr )
      this->leader.spawnId.value = (v2->spawnIds.ptr[ai->entityNumber] << 13) | ai->entityNumber;
    else
      this->leader.spawnId.value = 0x1FFF;
    this->ai->autoChooseAttackState = true;
  }
}


// ========================================================================
// ?InternalEnterState@idVS_ds_Group_FollowLeader@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B2A9B8
// RVA : 0x00B2A9B8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_ds_Group_FollowLeader::InternalEnterState(
        idVS_ds_Group_FollowLeader *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  idVehicleAI *ai; // r3
  idNavPathPosTracker *SplineTracker; // r3
  idNavSpline *navSpline; // r9
  int value; // r8
  idVehicleAI *v8; // r3
  idVehicleAI *v9; // r3
  idNavSpline *v10; // r10
  __int64 v11; // r6
  int v12; // [sp+8h] [-68h]
  __int64 v13; // [sp+10h] [-60h]
  __int64 v14; // [sp+18h] [-58h]
  __int64 v15; // [sp+20h] [-50h]
  __int64 v16; // [sp+28h] [-48h]
  __int64 v17; // [sp+30h] [-40h]

  this->ai->movementFSM.SetState_3(
    this: &this->ai->movementFSM,
    a2: &idVS_ms_MoveToGoalOnSpline::Type,
    a3: 0,
    a4: false);
  ai = this->ai;
  if ( gameLocal->spawnIds.ptr[ai->setup.patrol.waypoint.spawnId.value & 0x1FFF] == ai->setup.patrol.waypoint.spawnId.value >> 13 )
    idVehicleAI::InitDecisionStatePatrol(this: ai);
  idVS_ds_Group_FollowLeader::FindLeader(this);
  SplineTracker = idVehicleAI::GetSplineTracker(this: this->ai);
  this->startPos.distance = SplineTracker->pathPosition.distance;
  this->startPos.rightDistance = SplineTracker->pathPosition.rightDistance;
  navSpline = SplineTracker->pathPosition.navSpline;
  this->startPos.navSpline = navSpline;
  value = this->leader.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (navSpline = (idNavSpline *)(4 * ((value & 0x1FFF) + 21563)),
        (v8 = *(idVehicleAI **)((char *)&gameLocal->__vftable + (_DWORD)navSpline)) != nullptr) )
  {
    v9 = idVehicleAI::CastTo(c: v8);
  }
  else
  {
    v9 = nullptr;
  }
  if ( v9 == this->ai )
  {
    v10 = this->startPos.navSpline;
    LODWORD(v11) = 1;
    HIDWORD(v11) = __ROL4__(v10, 32);
    idVehicleAI::MoveToPathPosition(
      this: this->ai,
      isStoppingGoal: v11,
      passThroughGoal: false,
      a4: value,
      a5: (int)navSpline,
      a6: (int)v10,
      a7: v12,
      a8: v13,
      a9: v14,
      a10: v15,
      a11: v16,
      a12: v17);
    idVehicleAI::SetSpeedLimit(this: this->ai, speed: 45.0);
  }
}


// ========================================================================
// ?FollowerUpdate@idVS_ds_Group_FollowLeader@@QAAXXZ
// EA  : 0x82B2AAE8
// RVA : 0x00B2AAE8
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_ds_Group_FollowLeader::FollowerUpdate(idVS_ds_Group_FollowLeader *this)
{
  idGameLocal *v2; // r11
  idVehicleAI *v3; // r3
  idVehicleAI *v4; // r3
  idEntity *Enemy; // r3
  idVehicleAI *ai; // r11
  idVehicleAI *curState; // r9
  idVehicleAI *Entity; // r3
  idNavPathPosTracker *SplineTracker; // r31
  float rightDistance; // r10
  idNavSpline *navSpline; // r9
  idVehicleAI *v12; // r3
  idEntity *v13; // r4
  __int64 v14; // r6
  int v15; // r10
  int v16; // r9
  bool v17; // r8
  idVehicleAI *v18; // r3
  idVehicleAI *v19; // r3
  int v20; // [sp+8h] [-78h]
  __int64 v21; // [sp+10h] [-70h]
  __int64 v22; // [sp+18h] [-68h]
  __int64 v23; // [sp+20h] [-60h]
  __int64 v24; // [sp+28h] [-58h]
  __int64 v25; // [sp+30h] [-50h]
  idNavSplinePosition v26; // [sp+50h] [-30h] BYREF

  v2 = gameLocal;
  if ( gameLocal->spawnIds.ptr[this->leader.spawnId.value & 0x1FFF] == this->leader.spawnId.value >> 13
    && ((v3 = (idVehicleAI *)gameLocal->entities.ptr[this->leader.spawnId.value & 0x1FFF]) == nullptr
      ? (v4 = nullptr)
      : (idVehicleAI *)(v4 = idVehicleAI::CastTo(c: v3), v2 = gameLocal),
        (v4->thinkFlags & 1) != 0) )
  {
    if ( v2->spawnIds.ptr[this->following.spawnId.value & 0x1FFF] == this->following.spawnId.value >> 13 )
    {
      Enemy = idVehicleAI::GetEnemy(this: this->ai);
      ai = this->ai;
      curState = (idVehicleAI *)ai->attackFSM.curState;
      if ( Enemy != nullptr )
      {
        if ( curState != (idVehicleAI *)&ai->as_RangeShoot && this->ai->attackFSM.curState != &this->ai->as_RunAway )
          idVehicleAI::SetAttackState(
            this: this->ai,
            stateType: &idVS_as_RangeShoot::Type,
            delayTime: 0,
            pushState: false);
      }
      else
      {
        if ( curState != (idVehicleAI *)&ai->attackFSM.s_Idle )
          idVehicleAI::SetAttackState(this: this->ai, stateType: &idVS_Idle::Type, delayTime: 0, pushState: false);
        Entity = idEntityPtr<idVehicleAI>::GetEntity(this: &this->following);
        SplineTracker = idVehicleAI::GetSplineTracker(this: Entity);
        if ( idNavSpline::IsDeadEnd(this: SplineTracker->pathPosition.navSpline) )
          idVehicleAI::SetSpeedLimit(this: this->ai, speed: 0.0);
        rightDistance = SplineTracker->pathPosition.rightDistance;
        navSpline = SplineTracker->pathPosition.navSpline;
        v12 = this->ai;
        v26.distance = SplineTracker->pathPosition.distance;
        v26.rightDistance = rightDistance;
        v26.navSpline = navSpline;
        idVehicleAI::GetVehicleCar(this: v12);
        idNavSplinePosition::MoveDeltaRelativeToEntity(this: &v26, delta: -1000.0, ent: v13);
        LODWORD(v14) = 1;
        HIDWORD(v14) = __ROL4__(v26.navSpline, 32);
        idVehicleAI::MoveToPathPosition(
          this: (idVehicleAI *)LODWORD(v26.distance),
          isStoppingGoal: v14,
          passThroughGoal: false,
          a4: v17,
          a5: v16,
          a6: v15,
          a7: v20,
          a8: v21,
          a9: v22,
          a10: v23,
          a11: v24,
          a12: v25);
        idNavPathPosTracker::GetCurrentSpeedInMPH(this: SplineTracker);
      }
    }
  }
  else
  {
    if ( v2->spawnIds.ptr[this->leader.spawnId.value & 0x1FFF] == this->leader.spawnId.value >> 13 )
    {
      v18 = (idVehicleAI *)v2->entities.ptr[this->leader.spawnId.value & 0x1FFF];
      if ( v18 != nullptr )
        v19 = idVehicleAI::CastTo(c: v18);
      else
        v19 = nullptr;
      v19->ds_Group_FollowLeader.leader.spawnId.value = 0x1FFF;
    }
    idVS_ds_Group_FollowLeader::FindLeader(this);
    idVS_ds_Group_FollowLeader::LeaderUpdate(this);
  }
}


// ========================================================================
// ?InternalEnterState@idVS_ds_Car_Chase@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B2AD20
// RVA : 0x00B2AD20
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_ds_Car_Chase::InternalEnterState(
        idVS_ds_Car_Chase *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  idSplineWaypoint *NextSplineWayPoint; // r3

  NextSplineWayPoint = idVS_ds_Car_Chase::GetNextSplineWayPoint(this);
  this->currentWayPoint = NextSplineWayPoint;
  if ( NextSplineWayPoint != nullptr )
  {
    idSplineWaypoint::AddWayPointUser(this: NextSplineWayPoint, vAI: this->ai);
    idVS_ds_Car_Chase::SetPhysics(this, physicsOn: false);
  }
  else
  {
    idLib::Warning(
      fmt: "VS_General.cpp, idVS_ds_Car_Chase::GetNextSplineWayPoint, car set to chase has no inital waypoint! %s",
      this->ai->name.data);
  }
}


// ========================================================================
// ?InternalWork@idVS_ds_Car_Chase@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B2AD98
// RVA : 0x00B2AD98
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_ds_Car_Chase::InternalWork(
        idVS_ds_Car_Chase *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  idVehicleAI *ai; // r3
  double v5; // fp31
  idNavPathPosTracker *SplineTracker; // r3
  idNavSplinePosition *p_currentDestination; // r24
  float y; // r8
  float z; // r7
  double v10; // fp29
  double v11; // fp28
  double v12; // fp27
  double v13; // fp25
  int num; // r26
  idVehicleAI *v15; // r25
  int v16; // r28
  int v17; // r29
  idSplineWaypoint *currentWayPoint; // r11
  int value; // r9
  idVehicleAI *v20; // r3
  idVehicleAI *v21; // r30
  idNavPathPosTracker *v22; // r3
  float v23; // r10
  float v24; // r9
  double v25; // fp0
  idNavPathPosTracker *v26; // r3
  float v27; // r9
  float v28; // r8
  idVehicleAI *v29; // r3
  idVehicle *Enemy; // r30
  idNavPathPosTracker *EnemyTracker; // r3
  double CurrentSpeedInMPH; // fp31
  idNavPathPosTracker *v33; // r3
  float v34; // r10
  float v35; // r8
  idVS_ds_Car_Chase::enemySplineStatus_t enemySplineStatus; // r11
  double v37; // fp0
  idSplineWaypoint *v45; // r11
  idSplineWaypoint *v46; // r11
  idVS_ds_Car_Chase::state_t currentState; // r11
  idSplineWaypoint *v48; // r11
  idSplineWaypoint *NextSplineWayPoint; // r3
  idSplineWaypoint *v52; // r11
  double MaxSpeed; // fp1
  __int64 v54; // r6
  int v55; // r10
  int v56; // r9
  bool v57; // r8
  idVehicleAI *v58; // r3
  double v59; // fp1
  double overrideSpeed; // fp1
  __int64 v61; // r6
  int v62; // r10
  int v63; // r9
  bool v64; // r8
  int v65; // [sp+8h] [-E8h]
  __int64 v66; // [sp+10h] [-E0h]
  __int64 v67; // [sp+18h] [-D8h]
  __int64 v68; // [sp+20h] [-D0h]
  __int64 v69; // [sp+28h] [-C8h]
  __int64 v70; // [sp+30h] [-C0h]
  idNavSplinePosition v71; // [sp+50h] [-A0h] BYREF
  float x; // [sp+60h] [-90h]
  float v73; // [sp+64h] [-8Ch]
  float v74; // [sp+68h] [-88h]

  if ( this->currentWayPoint == nullptr )
    return;
  ai = this->ai;
  v5 = -1.0;
  this->overrideSpeed = -1.0;
  SplineTracker = idVehicleAI::GetSplineTracker(this: ai);
  p_currentDestination = &this->currentDestination;
  y = SplineTracker->worldPosition.y;
  z = SplineTracker->worldPosition.z;
  x = SplineTracker->worldPosition.x;
  v73 = y;
  v74 = z;
  idNavSplinePosition::GetWorldPos(this: &v71, result: (idVec3 *)&this->currentDestination);
  v10 = v74;
  v11 = x;
  v12 = v73;
  v13 = (float)((float)((float)(v71.rightDistance - v73) * (float)(v71.rightDistance - v73))
              + (float)((float)((float)(v71.distance - x) * (float)(v71.distance - x))
                      + (float)((float)(*(float *)&v71.navSpline - v74) * (float)(*(float *)&v71.navSpline - v74))));
  if ( this->overrideSpeed <= 0.0 )
  {
    num = this->currentWayPoint->users.num;
    if ( num > 1 )
    {
      v15 = nullptr;
      v16 = 0;
      v17 = 0;
      do
      {
        currentWayPoint = this->currentWayPoint;
        if ( v16 < currentWayPoint->users.num
          && (value = currentWayPoint->users.list[v17].spawnId.value,
              gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13)
          && (v20 = (idVehicleAI *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
        {
          v21 = idVehicleAI::CastTo(c: v20);
        }
        else
        {
          v21 = nullptr;
        }
        if ( v21 != this->ai && v21 != nullptr )
        {
          v22 = idVehicleAI::GetSplineTracker(this: v21);
          v23 = v22->worldPosition.y;
          v24 = v22->worldPosition.z;
          x = v22->worldPosition.x;
          v73 = v23;
          v74 = v24;
          v25 = (float)((float)((float)(v71.rightDistance - v23) * (float)(v71.rightDistance - v23))
                      + (float)((float)((float)(v71.distance - x) * (float)(v71.distance - x))
                              + (float)((float)(*(float *)&v71.navSpline - v24) * (float)(*(float *)&v71.navSpline - v24))));
          if ( v25 <= v13 && (v5 < 0.0 || v25 < v5) )
          {
            v5 = (float)((float)((float)(v71.rightDistance - v23) * (float)(v71.rightDistance - v23))
                       + (float)((float)((float)(v71.distance - x) * (float)(v71.distance - x))
                               + (float)((float)(*(float *)&v71.navSpline - v24)
                                       * (float)(*(float *)&v71.navSpline - v24))));
            v15 = v21;
          }
        }
        ++v16;
        ++v17;
      }
      while ( v16 < num );
      if ( v15 != nullptr )
      {
        idVehicleAI::GetSplineTracker(this: v15);
        v26 = idVehicleAI::GetSplineTracker(this: v15);
        v27 = v26->worldPosition.x;
        v28 = v26->worldPosition.y;
        v74 = v26->worldPosition.z;
        x = v27;
        v73 = v28;
        if ( (float)((float)((float)(v27 - (float)v11) * (float)(v27 - (float)v11))
                   + (float)((float)((float)(v74 - (float)v10) * (float)(v74 - (float)v10))
                           + (float)((float)(v28 - (float)v12) * (float)(v28 - (float)v12)))) < 562500.0
          && (float)(v15->control.speedLimit - (float)10.0) >= 0.0 )
        {
          this->overrideSpeed = v15->control.speedLimit - (float)10.0;
        }
      }
    }
  }
  if ( this->overrideSpeed < 0.0 )
  {
    v29 = this->ai;
    if ( v29->setup.forcePlayerEnemy )
    {
      if ( idVehicleAI::GetEnemy(this: v29) == nullptr )
      {
        Enemy = idVehicleAI::FindEnemy(this: this->ai);
        idVehicleAI::SetEnemy(this: this->ai, enemy: Enemy);
        if ( Enemy == nullptr )
        {
LABEL_36:
          v46 = this->currentWayPoint;
          if ( this->overrideSpeed > (double)v46->speedLimit )
            this->overrideSpeed = v46->speedLimit;
          goto LABEL_38;
        }
      }
      idVS_ds_Car_Chase::GetEnemySplineStatus(this);
      EnemyTracker = idVehicleAI::GetEnemyTracker(this: this->ai);
      CurrentSpeedInMPH = idNavPathPosTracker::GetCurrentSpeedInMPH(this: EnemyTracker);
      if ( this->enemySplineStatus != ENEMY_SPLINE_STATUS_UNKNOWN )
      {
        v33 = idVehicleAI::GetEnemyTracker(this: this->ai);
        v34 = v33->worldPosition.y;
        v35 = v33->worldPosition.x;
        enemySplineStatus = this->enemySplineStatus;
        v74 = v33->worldPosition.z;
        v73 = v34;
        x = v35;
        v37 = (float)((float)((float)(v35 - (float)v11) * (float)(v35 - (float)v11))
                    + (float)((float)((float)(v74 - (float)v10) * (float)(v74 - (float)v10))
                            + (float)((float)(v34 - (float)v12) * (float)(v34 - (float)v12))));
        if ( enemySplineStatus == ENEMY_SPLINE_STATUS_IN_FRONT )
        {
          if ( v37 >= 250000.0 )
          {
            _FP12 = (float)((float)5.0 - (float)((float)CurrentSpeedInMPH + (float)80.0));
            __asm { fsel      f11, f12, f0, f13 }
            this->overrideSpeed = _FP11;
            goto LABEL_34;
          }
          _FP13 = (float)((float)3.0 - (float)CurrentSpeedInMPH);
          __asm { fsel      f12, f13, f0, f31 }
        }
        else
        {
          if ( v37 < 250000.0 )
          {
            _FP12 = (float)((float)5.0 - (float)((float)CurrentSpeedInMPH - (float)5.0));
            __asm { fsel      f11, f12, f0, f13 }
            this->overrideSpeed = _FP11;
            goto LABEL_34;
          }
          _FP13 = (float)((float)10.0 - (float)((float)CurrentSpeedInMPH - (float)40.0));
          __asm { fsel      f12, f13, f26, f0 }
        }
        this->overrideSpeed = _FP12;
      }
LABEL_34:
      v45 = this->currentWayPoint;
      if ( v45->adaptToTargetSpeed != 0.0 )
        this->overrideSpeed = v45->adaptToTargetSpeed + (float)CurrentSpeedInMPH;
      goto LABEL_36;
    }
  }
LABEL_38:
  currentState = this->currentState;
  if ( currentState == 0 )
  {
    v48 = this->currentWayPoint;
    p_currentDestination->distance = v48->splinePathPosition.distance;
    this->currentDestination.rightDistance = v48->splinePathPosition.rightDistance;
    this->currentDestination.navSpline = v48->splinePathPosition.navSpline;
    if ( (*(_BYTE *)&v48->flags & 8) == 0 )
    {
LABEL_40:
      idVehicleAI::SetSpeedLimit(this: this->ai, speed: 0.0);
      this->currentState = STATE_WAITING_FOR_WAYPOINT;
      return;
    }
LABEL_55:
    overrideSpeed = this->overrideSpeed;
    if ( overrideSpeed < 0.0 )
    {
      if ( v48 == nullptr )
      {
LABEL_63:
        overrideSpeed = idVehicleAI::GetMaxSpeed(this: this->ai);
        goto LABEL_64;
      }
LABEL_62:
      overrideSpeed = v48->speedLimit;
      if ( overrideSpeed < 0.0 )
        goto LABEL_63;
    }
LABEL_64:
    idVehicleAI::SetSpeedLimit(this: this->ai, speed: overrideSpeed);
    LODWORD(v61) = 0;
    HIDWORD(v61) = __ROL4__(this->currentDestination.navSpline, 32);
    idVehicleAI::MoveToPathPosition(
      this: this->ai,
      isStoppingGoal: v61,
      passThroughGoal: true,
      a4: v64,
      a5: v63,
      a6: v62,
      a7: v65,
      a8: v66,
      a9: v67,
      a10: v68,
      a11: v69,
      a12: v70);
    this->currentState = STATE_MOVING;
    return;
  }
  if ( currentState != STATE_MOVING )
  {
    if ( currentState == STATE_WAITING_FOR_WAYPOINT )
    {
      v48 = this->currentWayPoint;
      if ( (*(_BYTE *)&v48->flags & 8) == 0 )
        return;
      goto LABEL_55;
    }
    if ( currentState != STATE_HANDLE_SCRIPT )
      return;
    v48 = this->currentWayPoint;
    if ( v48 != nullptr )
    {
      p_currentDestination->distance = v48->splinePathPosition.distance;
      this->currentDestination.rightDistance = v48->splinePathPosition.rightDistance;
      this->currentDestination.navSpline = v48->splinePathPosition.navSpline;
      if ( (*(_BYTE *)&v48->flags & 8) == 0 )
        goto LABEL_40;
      overrideSpeed = this->overrideSpeed;
      if ( overrideSpeed >= 0.0 )
        goto LABEL_64;
      goto LABEL_62;
    }
    goto LABEL_50;
  }
  _FP13 = this->currentWayPoint->radius;
  __asm { fsel      f12, f13, f13, f0 }
  if ( v13 > (float)((float)_FP12 * (float)_FP12) )
  {
    v59 = this->overrideSpeed;
    if ( v59 >= 0.0 )
      idVehicleAI::SetSpeedLimit(this: this->ai, speed: v59);
    return;
  }
  idVS_ds_Car_Chase::ActivateWayPoint(this);
  idSplineWaypoint::RemoveWayPointUser(this: this->currentWayPoint, vAI: this->ai);
  NextSplineWayPoint = idVS_ds_Car_Chase::GetNextSplineWayPoint(this);
  this->currentWayPoint = NextSplineWayPoint;
  if ( NextSplineWayPoint == nullptr )
  {
LABEL_50:
    v58 = this->ai;
    this->currentState = STATE_STOPPING;
    idVehicleAI::SetSpeedLimit(this: v58, speed: 0.0);
    return;
  }
  idSplineWaypoint::AddWayPointUser(this: NextSplineWayPoint, vAI: this->ai);
  v52 = this->currentWayPoint;
  p_currentDestination->distance = v52->splinePathPosition.distance;
  this->currentDestination.rightDistance = v52->splinePathPosition.rightDistance;
  this->currentDestination.navSpline = v52->splinePathPosition.navSpline;
  if ( (*(_BYTE *)&v52->flags & 8) == 0 )
    goto LABEL_40;
  MaxSpeed = this->overrideSpeed;
  if ( MaxSpeed < 0.0 && (v52 == nullptr || (MaxSpeed = v52->speedLimit) < 0.0) )
    MaxSpeed = idVehicleAI::GetMaxSpeed(this: this->ai);
  idVehicleAI::SetSpeedLimit(this: this->ai, speed: MaxSpeed);
  LODWORD(v54) = 0;
  HIDWORD(v54) = __ROL4__(this->currentDestination.navSpline, 32);
  idVehicleAI::MoveToPathPosition(
    this: this->ai,
    isStoppingGoal: v54,
    passThroughGoal: true,
    a4: v57,
    a5: v56,
    a6: v55,
    a7: v65,
    a8: v66,
    a9: v67,
    a10: v68,
    a11: v69,
    a12: v70);
}


// ========================================================================
// ?InternalWork@idVS_ds_Group_FollowLeader@@UAAXPAVidFiniteStateMachine@@H@Z
// EA  : 0x82B2B3A0
// RVA : 0x00B2B3A0
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __fastcall idVS_ds_Group_FollowLeader::InternalWork(
        idVS_ds_Group_FollowLeader *this,
        idFiniteStateMachine *baseFSM,
        const int curTime)
{
  int value; // r9
  idVehicleAI *v5; // r3
  idVehicleAI *v6; // r3

  idVehicleAI::EngageEnemy(this: this->ai);
  value = this->leader.spawnId.value;
  if ( gameLocal->spawnIds.ptr[value & 0x1FFF] == value >> 13
    && (v5 = (idVehicleAI *)gameLocal->entities.ptr[value & 0x1FFF]) != nullptr )
  {
    v6 = idVehicleAI::CastTo(c: v5);
  }
  else
  {
    v6 = nullptr;
  }
  if ( v6 == this->ai )
    idVS_ds_Group_FollowLeader::LeaderUpdate(this);
  else
    idVS_ds_Group_FollowLeader::FollowerUpdate(this);
}


// ========================================================================
// `dynamic initializer for 'vai_test_speedLimit''
// EA  : 0x8336B850
// RVA : 0x0136B850
// PDB : w:\tech5\tungsten\game\ai\vehicleai\vs_general.cpp
// ========================================================================

void __noreturn _dynamic_initializer_for__vai_test_speedLimit__()
{
  idCVar::idCVar(
    this: &vai_test_speedLimit,
    name: "vai_test_speedLimit",
    value: "130",
    flags: 4,
    description: "Speed limit",
    valueCompletion: nullptr);
  atexit(func: (void (__fastcall *)())_dynamic_atexit_destructor_for__vai_test_speedLimit__);
}

