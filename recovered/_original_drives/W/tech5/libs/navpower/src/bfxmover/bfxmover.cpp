
// ========================================================================
// ??0GPSpec@bfx@@QAA@XZ
// EA  : 0x8325EF30
// RVA : 0x0125EF30
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

bfx::GPSpec *__fastcall bfx::GPSpec::GPSpec(bfx::GPSpec *this)
{
  double Scale; // fp1

  Scale = bfx::GetScale();
  this->m_pushThroughCrowdAtGoal = false;
  this->m_allowedToStopDist = (float)Scale * (float)2.0;
  this->m_stopAtGoal = true;
  this->m_desiredStopDist = 0.0;
  this->m_orientAtGoalEnable = false;
  this->m_orientAtGoalDir = bfx::ZERO_VEC;
  this->m_tinyStep = false;
  return this;
}


// ========================================================================
// ??0GPSpec@bfx@@QAA@PAVSpace@1@ABVGotoPosSpec@1@@Z
// EA  : 0x8325EFB8
// RVA : 0x0125EFB8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

bfx::GPSpec *__fastcall bfx::GPSpec::GPSpec(bfx::GPSpec *this, bfx::Space *pSpace, const bfx::GotoPosSpec *inputSpec)
{
  double m_x; // fp11
  double m_y; // fp10
  double v6; // fp8
  double v7; // fp3
  double v8; // fp9
  double v9; // fp7
  double v10; // fp4
  bfx::Vec3 v14; // [sp+50h] [-30h] BYREF
  float v15; // [sp+60h] [-20h] BYREF
  float v16; // [sp+64h] [-1Ch]
  float v17; // [sp+68h] [-18h]

  this->m_allowedToStopDist = inputSpec->m_allowedToStopDist;
  this->m_desiredStopDist = inputSpec->m_desiredStopDist;
  this->m_stopAtGoal = inputSpec->m_stopAtGoal;
  this->m_pushThroughCrowdAtGoal = inputSpec->m_pushThroughCrowdAtGoal;
  this->m_orientAtGoalEnable = inputSpec->m_orientAtGoalEnable;
  m_x = inputSpec->m_orientAtGoalDir.m_x;
  m_y = inputSpec->m_orientAtGoalDir.m_y;
  v14.m_z = inputSpec->m_orientAtGoalDir.m_z;
  v14.m_y = m_y;
  v14.m_x = m_x;
  bfx::Matrix::Rot(this: (bfx::Matrix *)&v15, result: (bfx::Vec3 *)&pSpace->m_matWorldToSpace, rhs: &v14);
  v6 = v16;
  v7 = (float)(v16 * v16);
  v8 = v15;
  v9 = v17;
  this->m_orientAtGoalDir.m_x = v15;
  this->m_orientAtGoalDir.m_y = v6;
  v10 = v6;
  this->m_orientAtGoalDir.m_z = v9;
  _FP10 = (float)((float)__fsqrts((float)((float)((float)v9 * (float)v9)
                                        + (float)((float)((float)v8 * (float)v8) + (float)v7)))
                - (float)1.0842022e-19);
  __asm { fsel      f8, f10, f9, f12 }
  this->m_orientAtGoalDir.m_x = (float)v8 * (float)_FP8;
  this->m_orientAtGoalDir.m_y = (float)v10 * (float)_FP8;
  this->m_orientAtGoalDir.m_z = (float)v9 * (float)_FP8;
  this->m_tinyStep = false;
  return this;
}


// ========================================================================
// ??0MIDSpec@bfx@@QAA@XZ
// EA  : 0x8325F0B8
// RVA : 0x0125F0B8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

bfx::MIDSpec *__fastcall bfx::MIDSpec::MIDSpec(bfx::MIDSpec *this)
{
  this->m_stopWhenBlocked = false;
  this->m_blockedIgnoresCushions = false;
  this->m_pushableByConstraintSolver = false;
  return this;
}


// ========================================================================
// ??0MIDSpec@bfx@@QAA@ABVMoveInDirectionSpec@1@@Z
// EA  : 0x8325F0D0
// RVA : 0x0125F0D0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

bfx::MIDSpec *__fastcall bfx::MIDSpec::MIDSpec(bfx::MIDSpec *this, bfx::MIDSpec *inputSpec)
{
  *this = *inputSpec;
  return this;
}


// ========================================================================
// ??0StpSpec@bfx@@QAA@XZ
// EA  : 0x8325F0F0
// RVA : 0x0125F0F0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

bfx::StpSpec *__fastcall bfx::StpSpec::StpSpec(bfx::StpSpec *this)
{
  *this = (bfx::StpSpec)1;
  return this;
}


// ========================================================================
// ??0FMSpec@bfx@@QAA@XZ
// EA  : 0x8325F108
// RVA : 0x0125F108
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

bfx::FMSpec *__fastcall bfx::FMSpec::FMSpec(bfx::FMSpec *this)
{
  double Scale; // fp1

  Scale = bfx::GetScale();
  this->m_formation = CIRCLE;
  this->m_arcSpread = 135.0;
  this->m_radius = (float)Scale * (float)4.0;
  return this;
}


// ========================================================================
// ??0FMSpec@bfx@@QAA@ABVFollowMoverSpec@1@@Z
// EA  : 0x8325F160
// RVA : 0x0125F160
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

bfx::FMSpec *__fastcall bfx::FMSpec::FMSpec(bfx::FMSpec *this, bfx::FMSpec *inputSpec)
{
  *this = *inputSpec;
  return this;
}


// ========================================================================
// ??0TurnInPlaceTune@bfx@@QAA@XZ
// EA  : 0x8325F180
// RVA : 0x0125F180
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

bfx::TurnInPlaceTune *__fastcall bfx::TurnInPlaceTune::TurnInPlaceTune(bfx::TurnInPlaceTune *this)
{
  bfx::APICriticalSection *m_pGlobalCS; // r30

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &bfx::g_pCurInstance->m_pGlobalCS->m_criticalSection);
  this->m_enableUTurn = false;
  this->m_whenMovingAngle = 110.0;
  this->m_whenStoppedAngle = 45.0;
  this->m_speed = 360.0;
  this->m_accelAngle = 0.0;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return this;
}


// ========================================================================
// ??0MoverTune@bfx@@QAA@XZ
// EA  : 0x8325F220
// RVA : 0x0125F220
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

bfx::MoverTune *__fastcall bfx::MoverTune::MoverTune(bfx::MoverTune *this)
{
  double Scale; // fp1
  bfx::APICriticalSection *m_pGlobalCS; // r26
  double v4; // fp1
  double v5; // fp1

  Scale = bfx::GetScale();
  this->m_radiusData.m_radius = (float)Scale * (float)0.25;
  this->m_radiusData.m_outerCushion = (float)((float)Scale * (float)0.25) * (float)0.2;
  this->m_radiusData.m_innerCushion = (float)((float)Scale * (float)0.25) * (float)0.2;
  this->m_cautionTune.m_speedX = 1.0;
  this->m_cautionTune.m_tightTurnDegrees = 90.0;
  this->m_autoObTune.m_obstacleDat.m_layerMask = -1;
  this->m_autoObTune.m_obstacleDat.m_penaltyMult = 15.0;
  this->m_autoObTune.m_obstacleDat.m_obstacleBlockageFlags = 0xFFFF;
  this->m_autoObTune.m_obstacleDat.m_userData = 0xFFFFFFFF00000000uLL;
  this->m_autoObTune.m_obstacleDat.m_obstacleName = nullptr;
  this->m_autoObTune.m_delay = 0.5;
  this->m_autoObTune.m_autoCreateObstacle = false;
  this->m_pathOptions.m_performInitialNavProbe = true;
  this->m_pathOptions.m_performAdditionalSmoothing = false;
  bfx::JumperTune::JumperTune(this: &this->m_jumperTune);
  this->m_puppetTune.m_exitPuppetInObstacles = false;
  this->m_puppetTune.m_repulsionConstraintMode = NOT_PUSHABLE;
  this->m_proberTune.m_probeInterval = 0.25;
  this->m_proberTune.m_probeForGround = true;
  this->m_proberTune.m_probeUserData = 0xFFFFFFFF00000000uLL;
  this->m_goalTune.m_useCircularApproach = false;
  this->m_goalTune.m_preferredTurningRadius = 0.0;
  this->m_idleTune.m_tetherDist = bfx::GetScale() * (float)2.0;
  this->m_idleTune.m_returnDelay = 2.0;
  bfx::TurnInPlaceTune::TurnInPlaceTune(this: &this->m_turnInPlace);
  this->m_surfaceOrientTune.m_surfaceOrientSlerpTime = 0.5;
  this->m_surfaceOrientTune.m_alwaysVerticalOnAutoGen = true;
  this->m_surfaceOrientTune.m_surfaceOrientThreshold = 60.0;
  bfx::FollowerTune::FollowerTune(this: &this->m_followerTune);
  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  this->m_speed = bfx::GetScale() * (float)2.0;
  this->m_maxSpeedFraction = 2.0;
  this->m_radiusData.m_radius = bfx::GetScale() * (float)0.25;
  this->m_radiusData.m_outerCushion = bfx::GetScale() * (float)0.050000001;
  this->m_radiusData.m_innerCushion = bfx::GetScale() * (float)0.050000001;
  this->m_bulk = 1.0;
  this->m_cruiseAcc = bfx::GetScale() * (float)2.0;
  v4 = bfx::GetScale();
  this->m_repulsionAccelerationTune.m_initialAcc = 0.0;
  this->m_startStopAcc = (float)v4 * (float)5.0;
  this->m_repulsionAccelerationTune.m_outerCushionAcc = bfx::GetScale() * (float)3.0;
  v5 = bfx::GetScale();
  this->m_repulsorType = 0;
  this->m_repulsionAccelerationTune.m_innerCushionAcc = (float)v5 * (float)10.0;
  this->m_flockAcc = bfx::GetScale() * (float)0.2;
  this->m_maxFlockAccDist = bfx::GetScale() * (float)5.0;
  this->m_pathAcc = bfx::GetScale();
  this->m_planLayer = 0;
  this->m_sidestepFraction = 0.2;
  this->m_obstacleMode = BLOCKED_IF_ANY_MATCH;
  this->m_pathSharingPenalty = 0.0;
  this->m_obstacleBlockageFlags = 0xFFFF;
  this->m_maxPathSharingPenalty = 0.0;
  this->m_repulsorBlockageFlags = -1;
  this->m_repulsorIdentityFlags = -1;
  this->m_backpedalFraction = 1.2;
  this->m_areaUsageFlags = -1;
  this->m_linkUsageFlags = -1;
  this->m_clientMotion = false;
  this->m_allowDetour = false;
  this->m_ignoreUpsideDownMovers = false;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return this;
}


// ========================================================================
// __unwind$86482
// EA  : 0x8325F4A4
// RVA : 0x0125F4A4
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_86482()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 192 + 80));
}


// ========================================================================
// ??0DesiredMotion@bfx@@QAA@XZ
// EA  : 0x8325F4D0
// RVA : 0x0125F4D0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

bfx::DesiredMotion *__fastcall bfx::DesiredMotion::DesiredMotion(bfx::DesiredMotion *this)
{
  float m_z; // r6

  this->m_desiredVel.m_x = ZERO_VECTOR_20.m_x;
  this->m_desiredVel.m_y = ZERO_VECTOR_20.m_y;
  m_z = ZERO_VECTOR_20.m_z;
  this->m_desiredRotSpeed = 0.0;
  this->m_desiredVel.m_z = m_z;
  return this;
}


// ========================================================================
// ?OkToMoveOntoArea@MSurfer@bfx@@UBA_NPAVArea@2@@Z
// EA  : 0x8325F500
// RVA : 0x0125F500
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

BOOL __fastcall bfx::MSurfer::OkToMoveOntoArea(bfx::MSurfer *this, bfx::Area *pArea)
{
  return bfx::MoverImpl::OkToMoveOntoArea(this: this->m_pMoverImpl, pArea);
}


// ========================================================================
// ?MovedOntoArea@MSurfer@bfx@@UAAXABVVec3@2@PAVArea@2@010@Z
// EA  : 0x8325F508
// RVA : 0x0125F508
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::MSurfer::MovedOntoArea(
        bfx::MSurfer *this,
        const bfx::Vec3 *oldPos,
        bfx::Area *pOldArea,
        const bfx::Vec3 *newPos,
        bfx::Area *pNewArea,
        const bfx::Vec3 *edgeVec)
{
  bfx::MoverImpl::MovedOntoArea(this: this->m_pMoverImpl, oldPos, pOldArea, newPos, pNewArea, edgeVec);
}


// ========================================================================
// ?OnEdge@MSurfer@bfx@@UAAXABVVec3@2@@Z
// EA  : 0x8325F510
// RVA : 0x0125F510
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::MSurfer::OnEdge(bfx::MSurfer *this, const bfx::Vec3 *outwardEdgeNormal)
{
  bfx::MoverImpl::OnEdge(this: this->m_pMoverImpl, outwardEdgeNormal);
}


// ========================================================================
// ?PushingIntoCorner@MSurfer@bfx@@UAAXABVVec3@2@0@Z
// EA  : 0x8325F518
// RVA : 0x0125F518
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::MSurfer::PushingIntoCorner(bfx::MSurfer *this, const bfx::Vec3 *edge1, const bfx::Vec3 *edge2)
{
  bfx::MoverImpl::PushingIntoCorner(this: this->m_pMoverImpl, edge1, edge2);
}


// ========================================================================
// ?AddPos@Trail@bfx@@QAAXABVVec3@2@@Z
// EA  : 0x8325F520
// RVA : 0x0125F520
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Trail::AddPos(bfx::Trail *this, const bfx::Vec3 *pt)
{
  int m_head; // r11
  float *p_m_x; // r11
  double v6; // fp30
  double v7; // fp29
  int m_tail; // r9
  int v9; // r11
  float *v10; // r11

  m_head = this->m_head;
  if ( m_head == -1 )
  {
    this->m_head = 0;
  }
  else if ( m_head == this->m_tail )
  {
    this->m_head = 1;
  }
  else
  {
    p_m_x = &this->m_pts[(m_head + 999) % 1000].m_x;
    v6 = (float)(pt->m_y - p_m_x[1]);
    v7 = (float)(pt->m_z - p_m_x[2]);
    if ( __fsqrts((float)((float)((float)v6 * (float)v6)
                        + (float)((float)((float)v7 * (float)v7)
                                + (float)((float)(pt->m_x - *p_m_x) * (float)(pt->m_x - *p_m_x))))) > (float)(bfx::GetScale() * (float)0.1) )
    {
      m_tail = this->m_tail;
      v9 = this->m_head + 1;
      this->m_head = v9 % 1000;
      if ( m_tail == v9 % 1000 )
        this->m_tail = (m_tail + 1) % 1000;
    }
  }
  v10 = &this->m_pts[this->m_head].m_x;
  *v10 = pt->m_x;
  v10[1] = pt->m_y;
  v10[2] = pt->m_z;
}


// ========================================================================
// ?UpdateMoverContact@bfx@@YAXPAVMover@1@0@Z
// EA  : 0x8325F680
// RVA : 0x0125F680
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::UpdateMoverContact(bfx::Mover *pInputMoverA, bfx::Mover *pInputMoverB)
{
  float v6; // [sp+50h] [-40h] BYREF
  float v7; // [sp+54h] [-3Ch]
  float v8; // [sp+58h] [-38h]
  float v9; // [sp+60h] [-30h] BYREF
  float v10; // [sp+64h] [-2Ch]
  float v11; // [sp+68h] [-28h]

  (*(void (__fastcall **)(float *))(**(_DWORD **)&pInputMoverB[776] + 24))(a1: &v9);
  (*(void (__fastcall **)(float *))(**(_DWORD **)&pInputMoverA[776] + 24))(a1: &v6);
  if ( __fsqrts((float)((float)((float)(v6 - v9) * (float)(v6 - v9))
                      + (float)((float)((float)(v8 - v11) * (float)(v8 - v11))
                              + (float)((float)(v7 - v10) * (float)(v7 - v10))))) < (float)((float)((float)((float)((float)(*(float *)(*(_DWORD *)&pInputMoverB[748] + 16) + *(float *)(*(_DWORD *)&pInputMoverB[748] + 12)) + *(float *)(*(_DWORD *)&pInputMoverA[748] + 16)) + *(float *)(*(_DWORD *)&pInputMoverA[748] + 12))
                                                                                                  + *(float *)(*(_DWORD *)&pInputMoverA[748] + 8))
                                                                                          + *(float *)(*(_DWORD *)&pInputMoverB[748] + 8)) )
  {
    if ( *(_DWORD *)&pInputMoverA[752] != 0 || *(_DWORD *)&pInputMoverB[752] != 0 )
    {
      _FP1 = bfx::GetTime();
    }
    else
    {
      _FP12 = (float)(*(float *)&pInputMoverA[708] - *(float *)&pInputMoverB[708]);
      __asm { fsel      f1, f12, f13, f0 }
    }
    *(float *)&pInputMoverA[708] = _FP1;
    *(float *)&pInputMoverB[708] = _FP1;
  }
}


// ========================================================================
// ?GetDesiredMotion@MoverImpl@bfx@@QBAXAAVDesiredMotion@2@@Z
// EA  : 0x8325F790
// RVA : 0x0125F790
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::GetDesiredMotion(bfx::MoverImpl *this, bfx::DesiredMotion *desiredMotion)
{
  bfx::Vec3 *v4; // r3
  float m_x; // r7
  float m_y; // r6
  double VolumeAdjustment; // fp1
  double v8; // fp11
  double v9; // fp10
  double m_z; // fp9
  bfx::Vec3 v11; // [sp+60h] [-40h] BYREF
  char v12; // [sp+70h] [-30h] BYREF

  ((void (__fastcall *)(bfx::Vec3 *))this->m_behavior.m_pCurMotion->GetDesiredVel)(a1: &v11);
  v4 = bfx::Matrix::Rot(this: (bfx::Matrix *)&v12, result: (bfx::Vec3 *)&this->m_pSpace->m_matSpaceToWorld, rhs: &v11);
  m_x = v4->m_x;
  m_y = v4->m_y;
  desiredMotion->m_desiredVel.m_z = v4->m_z;
  desiredMotion->m_desiredVel.m_y = m_y;
  desiredMotion->m_desiredVel.m_x = m_x;
  VolumeAdjustment = idSoundEmitterLocal::GetVolumeAdjustment(this: &this->m_commonState.m_orienter);
  v8 = v11.m_x;
  v9 = v11.m_y;
  m_z = v11.m_z;
  desiredMotion->m_desiredRotSpeed = (float)VolumeAdjustment * (float)57.295776;
  this->m_clientMotionDebugData.m_desiredVel.m_x = v8;
  this->m_clientMotionDebugData.m_desiredVel.m_y = v9;
  this->m_clientMotionDebugData.m_desiredVel.m_z = m_z;
}


// ========================================================================
// ?ForceUseOfClientMotion@bfx@@YAXPAVMover@1@_N@Z
// EA  : 0x8325F860
// RVA : 0x0125F860
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::ForceUseOfClientMotion(bfx::Mover *pMover, bool bEnable)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogMoverForceUseOfClientMotion(replayID: *(_DWORD *)&pMover[312], bEnable);
  pMover[740] = (bfx::Mover)bEnable;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$86826
// EA  : 0x8325F8C0
// RVA : 0x0125F8C0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_86826()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?ApplyClientMotion@MoverImpl@bfx@@QAAXABVVec3@2@M@Z
// EA  : 0x8325F8E8
// RVA : 0x0125F8E8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::ApplyClientMotion(
        bfx::MoverImpl *this,
        const bfx::Vec3 *vel,
        double rotSpeedDegPerSecond)
{
  if ( this->m_pTune->m_clientMotion )
  {
    ((void (__fastcall *)(bfx::MotionBase *))this->m_behavior.m_pCurMotion->ApplyClientMotion)(a1: this->m_behavior.m_pCurMotion);
    bfx::Orienter::ApplyClientRotSpeed(
      this: &this->m_commonState.m_orienter,
      rotSpeed: (float)((float)rotSpeedDegPerSecond * (float)0.017453292));
    this->m_clientMotionDebugData.m_clientVel.m_x = vel->m_x;
    this->m_clientMotionDebugData.m_clientVel.m_y = vel->m_y;
    this->m_clientMotionDebugData.m_clientVel.m_z = vel->m_z;
  }
}


// ========================================================================
// ?SetClientMotionSkidTurnAllowed@bfx@@YAXPAVMover@1@_N@Z
// EA  : 0x8325F980
// RVA : 0x0125F980
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::SetClientMotionSkidTurnAllowed(bfx::Mover *pMover, bool bEnable)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogMoverSetClientMotionSkidTurnAllowed(replayID: *(_DWORD *)&pMover[312], bEnable);
  pMover[741] = (bfx::Mover)bEnable;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$86916
// EA  : 0x8325F9E0
// RVA : 0x0125F9E0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_86916()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?ForceSnapToNavgraphForCreateAndTeleport@bfx@@YAX_N@Z
// EA  : 0x8325FA10
// RVA : 0x0125FA10
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::ForceSnapToNavgraphForCreateAndTeleport(bool bEnable)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogMoverForceSnapToNavgraphForCreateAndTeleport(bEnable);
  BYTE1(bfx::g_pCurInstance->m_pComponentManager->m_components[4][10].__vftable) = bEnable;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$86993
// EA  : 0x8325FA74
// RVA : 0x0125FA74
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_86993()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?GotoPos@Mover@bfx@@QAAXABVVector3@2@ABVGotoPosSpec@2@_N@Z
// EA  : 0x8325FAA8
// RVA : 0x0125FAA8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Mover::GotoPos(
        bfx::Mover *this,
        const bfx::Vector3 *requestedGoalPos,
        const bfx::GotoPosSpec *origSpec,
        bool forceUpdate)
{
  int v8; // r27
  double m_y; // fp13
  double m_x; // fp12
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-90h]
  bfx::Vec3 v12; // [sp+58h] [-88h] BYREF
  bfx::Matrix v13; // [sp+68h] [-78h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  v8 = *((_DWORD *)this + 4);
  bfx::LogMoverGotoPos(replayID: *((_DWORD *)this + 78), goalPos: requestedGoalPos, spec: origSpec, forceUpdate);
  bfx::GPSpec::GPSpec(this: (bfx::GPSpec *)&v13.m_data[6], pSpace: (bfx::Space *)v8, inputSpec: origSpec);
  m_y = requestedGoalPos->m_y;
  m_x = requestedGoalPos->m_x;
  v12.m_z = requestedGoalPos->m_z;
  v12.m_x = m_x;
  v12.m_y = m_y;
  bfx::Matrix::operator*(this: &v13, result: (bfx::Vec3 *)(v8 + 124), rhs: &v12);
  bfx::MoverImpl::GotoPos(
    (bfx::MoverImpl *)this,
    inputGoalPos: (const bfx::Vec3 *)&v13,
    origSpec: (const bfx::GPSpec *)&v13.m_data[6],
    forceUpdate);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$87079
// EA  : 0x8325FB64
// RVA : 0x0125FB64
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_87079()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 224 + 80));
}


// ========================================================================
// ?GotoPosAsync@Mover@bfx@@QAAXABVVector3@2@ABVGotoPosSpec@2@_N@Z
// EA  : 0x8325FB98
// RVA : 0x0125FB98
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Mover::GotoPosAsync(
        bfx::Mover *this,
        const bfx::Vector3 *requestedGoalPos,
        const bfx::GotoPosSpec *origSpec,
        bool forceUpdate)
{
  bfx::Space *v8; // r28
  bool v9; // r3
  double m_y; // fp13
  bfx::Vec3 *p_m_matWorldToSpace; // r4
  double m_x; // fp12
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-C0h]
  bfx::Vec3 v14; // [sp+58h] [-B8h] BYREF
  bfx::Vec3 v15; // [sp+68h] [-A8h] BYREF
  bfx::Matrix v16[2]; // [sp+78h] [-98h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  v8 = *((bfx::Space **)this + 4);
  bfx::LogMoverGotoPosAsync(replayID: *((_DWORD *)this + 78), goalPos: requestedGoalPos, spec: origSpec, forceUpdate);
  bfx::GPSpec::GPSpec(this: (bfx::GPSpec *)&v16[0].m_data[10], pSpace: v8, inputSpec: origSpec);
  v9 = bfx::g_pCurInstance->m_pSystemMCore->IsAsyncEnabled(this: bfx::g_pCurInstance->m_pSystemMCore);
  m_y = requestedGoalPos->m_y;
  p_m_matWorldToSpace = (bfx::Vec3 *)&v8->m_matWorldToSpace;
  m_x = requestedGoalPos->m_x;
  if ( v9 )
  {
    v14.m_z = requestedGoalPos->m_z;
    v14.m_x = m_x;
    v14.m_y = m_y;
    bfx::Matrix::operator*(this: v16, result: p_m_matWorldToSpace, rhs: &v14);
    bfx::MoverImpl::GotoPosAsync(
      (bfx::MoverImpl *)this,
      inputGoalPos: (const bfx::Vec3 *)v16,
      origSpec: (const bfx::GPSpec *)&v16[0].m_data[10],
      forceUpdate);
  }
  else
  {
    v15.m_z = requestedGoalPos->m_z;
    v15.m_x = m_x;
    v15.m_y = m_y;
    bfx::Matrix::operator*(this: (bfx::Matrix *)&v16[0].m_data[4], result: p_m_matWorldToSpace, rhs: &v15);
    bfx::MoverImpl::GotoPos(
      (bfx::MoverImpl *)this,
      inputGoalPos: (const bfx::Vec3 *)&v16[0].m_data[4],
      origSpec: (const bfx::GPSpec *)&v16[0].m_data[10],
      forceUpdate);
  }
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$87147
// EA  : 0x8325FCA8
// RVA : 0x0125FCA8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_87147()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 272 + 80));
}


// ========================================================================
// ?Stop@Mover@bfx@@QAAXABVStopSpec@2@@Z
// EA  : 0x8325FCD8
// RVA : 0x0125FCD8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Mover::Stop(bfx::Mover *this, const bfx::StopSpec *spec)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogMoverStop(replayID: *((_DWORD *)this + 78), spec);
  bfx::MoverImpl::Stop((bfx::MoverImpl *)this, spec);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$87233
// EA  : 0x8325FD40
// RVA : 0x0125FD40
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_87233()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?MoveInDirection@Mover@bfx@@QAAXABVVector3@2@MABVMoveInDirectionSpec@2@@Z
// EA  : 0x8325FD70
// RVA : 0x0125FD70
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Mover::MoveInDirection(
        bfx::Mover *this,
        const bfx::Vector3 *dir,
        double speed,
        const bfx::MoveInDirectionSpec *spec)
{
  int v7; // r26
  double m_y; // fp13
  double m_x; // fp12
  const bfx::MoveInDirectionSpec *v10; // r5
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-70h]
  bfx::Vec3 v12; // [sp+58h] [-68h] BYREF
  bfx::Matrix v13; // [sp+68h] [-58h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  v7 = *((_DWORD *)this + 4);
  bfx::LogMoverMoveInDirection(replayID: *((_DWORD *)this + 78), dir, speed, spec);
  m_y = dir->m_y;
  m_x = dir->m_x;
  v12.m_z = dir->m_z;
  v12.m_x = m_x;
  v12.m_y = m_y;
  bfx::Matrix::Rot(this: &v13, result: (bfx::Vec3 *)(v7 + 124), rhs: &v12);
  bfx::MoverImpl::MoveInDirection((bfx::MoverImpl *)this, dir: (const bfx::Vec3 *)&v13, speed, spec: v10);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$87275
// EA  : 0x8325FE24
// RVA : 0x0125FE24
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_87275()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 192 + 80));
}


// ========================================================================
// ?FollowMover@Mover@bfx@@QAAXPAV12@ABVFollowMoverSpec@2@@Z
// EA  : 0x8325FE58
// RVA : 0x0125FE58
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Mover::FollowMover(bfx::Mover *this, bfx::Mover *pTargetMover, const bfx::FollowMoverSpec *spec)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-40h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogMoverFollowMover(replayID: *((_DWORD *)this + 78), pTargetMover, spec);
  bfx::MoverImpl::FollowMover((bfx::MoverImpl *)this, pMoverTarget: pTargetMover, spec);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$87339
// EA  : 0x8325FECC
// RVA : 0x0125FECC
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_87339()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 144 + 80));
}


// ========================================================================
// ?Freeze@Mover@bfx@@QAAX_N@Z
// EA  : 0x8325FF00
// RVA : 0x0125FF00
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Mover::Freeze(bfx::Mover *this, bool freeze)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogMoverFreeze(replayID: *((_DWORD *)this + 78), freeze);
  bfx::MoverImpl::Freeze((bfx::MoverImpl *)this, freeze);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$87382
// EA  : 0x8325FF68
// RVA : 0x0125FF68
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_87382()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?FreezeTranslation@Mover@bfx@@QAAX_N@Z
// EA  : 0x8325FF98
// RVA : 0x0125FF98
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Mover::FreezeTranslation(bfx::Mover *this, bool freeze)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogMoverFreezeTranslation(replayID: *((_DWORD *)this + 78), freeze);
  bfx::MoverImpl::FreezeTranslation((bfx::MoverImpl *)this, freeze);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$87423
// EA  : 0x83260000
// RVA : 0x01260000
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_87423()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?EnablePuppetMode@Mover@bfx@@QAAX_N@Z
// EA  : 0x83260030
// RVA : 0x01260030
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Mover::EnablePuppetMode(bfx::Mover *this, bool enable)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogEnablePuppetMode(replayID: *((_DWORD *)this + 78), enable);
  bfx::MoverImpl::EnablePuppetMode((bfx::MoverImpl *)this, enable);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$87464
// EA  : 0x83260098
// RVA : 0x01260098
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_87464()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?SetPuppetPos@Mover@bfx@@QAAXABVVector3@2@@Z
// EA  : 0x832600C8
// RVA : 0x012600C8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Mover::SetPuppetPos(bfx::Mover *this, const bfx::Vector3 *pos)
{
  int v4; // r27
  double m_y; // fp13
  double m_x; // fp12
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-60h]
  bfx::Vec3 v8; // [sp+58h] [-58h] BYREF
  bfx::Matrix v9; // [sp+68h] [-48h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  v4 = *((_DWORD *)this + 4);
  bfx::LogMoverSetPuppetPos(replayID: *((_DWORD *)this + 78), pos);
  m_y = pos->m_y;
  m_x = pos->m_x;
  v8.m_z = pos->m_z;
  v8.m_x = m_x;
  v8.m_y = m_y;
  bfx::Matrix::operator*(this: &v9, result: (bfx::Vec3 *)(v4 + 124), rhs: &v8);
  bfx::MoverImpl::SetPuppetPos((bfx::MoverImpl *)this, pos: (const bfx::Vec3 *)&v9);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$87506
// EA  : 0x8326015C
// RVA : 0x0126015C
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_87506()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 176 + 80));
}


// ========================================================================
// ?SetPuppetRot@Mover@bfx@@QAAXABVQuaternion@2@@Z
// EA  : 0x83260190
// RVA : 0x01260190
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Mover::SetPuppetRot(bfx::Mover *this, const bfx::Quaternion *rot)
{
  int v4; // r27
  double m_y; // fp13
  double m_x; // fp12
  double m_w; // fp11
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-60h]
  bfx::Quat v9; // [sp+60h] [-50h] BYREF
  bfx::Quat v10[4]; // [sp+70h] [-40h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  v4 = *((_DWORD *)this + 4);
  bfx::LogMoverSetPuppetRot(replayID: *((_DWORD *)this + 78), rot);
  m_y = rot->m_y;
  m_x = rot->m_x;
  m_w = rot->m_w;
  v9.m_z = rot->m_z;
  v9.m_y = m_y;
  v9.m_w = m_w;
  v9.m_x = m_x;
  bfx::Quat::Normalize(this: &v9);
  bfx::Quat::operator*(this: v10, result: (bfx::Quat *)(v4 + 40), rhs: &v9);
  bfx::MoverImpl::SetPuppetRot((bfx::MoverImpl *)this, rot: v10);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$87571
// EA  : 0x83260234
// RVA : 0x01260234
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_87571()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 176 + 80));
}


// ========================================================================
// ?EnableCustomLinkMode@Mover@bfx@@QAA_N_N@Z
// EA  : 0x83260268
// RVA : 0x01260268
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

BOOL __fastcall bfx::Mover::EnableCustomLinkMode(bfx::Mover *this, bool enable)
{
  BOOL v4; // r29
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogEnableCustomLinkMode(replayID: *((_DWORD *)this + 78), enable);
  v4 = bfx::MoverImpl::EnableCustomLinkMode((bfx::MoverImpl *)this, enable);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return v4;
}


// ========================================================================
// __unwind$87639
// EA  : 0x832602D8
// RVA : 0x012602D8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_87639()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?SetCustomLinkPos@Mover@bfx@@QAAXABVVector3@2@@Z
// EA  : 0x83260308
// RVA : 0x01260308
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Mover::SetCustomLinkPos(bfx::Mover *this, const bfx::Vector3 *pos)
{
  int v4; // r27
  double m_y; // fp13
  double m_x; // fp12
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-60h]
  bfx::Vec3 v8; // [sp+58h] [-58h] BYREF
  bfx::Matrix v9; // [sp+68h] [-48h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  v4 = *((_DWORD *)this + 4);
  bfx::LogMoverSetCustomLinkPos(replayID: *((_DWORD *)this + 78), pos);
  m_y = pos->m_y;
  m_x = pos->m_x;
  v8.m_z = pos->m_z;
  v8.m_x = m_x;
  v8.m_y = m_y;
  bfx::Matrix::operator*(this: &v9, result: (bfx::Vec3 *)(v4 + 124), rhs: &v8);
  bfx::MoverImpl::SetCustomLinkPos((bfx::MoverImpl *)this, pos: (const bfx::Vec3 *)&v9);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$87682
// EA  : 0x8326039C
// RVA : 0x0126039C
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_87682()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 176 + 80));
}


// ========================================================================
// ?SetCustomLinkRot@Mover@bfx@@QAAXABVQuaternion@2@@Z
// EA  : 0x832603D0
// RVA : 0x012603D0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Mover::SetCustomLinkRot(bfx::Mover *this, const bfx::Quaternion *rot)
{
  int v4; // r27
  double m_y; // fp13
  double m_x; // fp12
  double m_w; // fp11
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-60h]
  bfx::Quat v9; // [sp+60h] [-50h] BYREF
  bfx::Quat v10[4]; // [sp+70h] [-40h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  v4 = *((_DWORD *)this + 4);
  bfx::LogMoverSetCustomLinkRot(replayID: *((_DWORD *)this + 78), rot);
  m_y = rot->m_y;
  m_x = rot->m_x;
  m_w = rot->m_w;
  v9.m_z = rot->m_z;
  v9.m_y = m_y;
  v9.m_w = m_w;
  v9.m_x = m_x;
  bfx::Quat::Normalize(this: &v9);
  bfx::Quat::operator*(this: v10, result: (bfx::Quat *)(v4 + 40), rhs: &v9);
  bfx::MoverImpl::SetCustomLinkRot((bfx::MoverImpl *)this, rot: v10);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$87747
// EA  : 0x83260474
// RVA : 0x01260474
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_87747()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 176 + 80));
}


// ========================================================================
// ?SwapToDefaultJump@Mover@bfx@@QAAXPBM@Z
// EA  : 0x832604A8
// RVA : 0x012604A8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Mover::SwapToDefaultJump(bfx::Mover *this, const float *pInitialSpeed)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogMoverSwapToDefaultJump(replayID: *((_DWORD *)this + 78), pInitialSpeed);
  bfx::MoverImpl::SwapToDefaultJump((bfx::MoverImpl *)this, pInitialSpeed);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$87814
// EA  : 0x83260510
// RVA : 0x01260510
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_87814()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?OrientInDirectionOfTravel@Mover@bfx@@QAAXXZ
// EA  : 0x83260540
// RVA : 0x01260540
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Mover::OrientInDirectionOfTravel(bfx::Mover *this)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogMoverOrientInDirectionOfTravel(replayID: *((_DWORD *)this + 78));
  bfx::MoverImpl::OrientInDirectionOfTravel((bfx::MoverImpl *)this);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$87855
// EA  : 0x8326059C
// RVA : 0x0126059C
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_87855()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?OrientStrictlyInDirectionOfTravel@Mover@bfx@@QAAXXZ
// EA  : 0x832605D0
// RVA : 0x012605D0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Mover::OrientStrictlyInDirectionOfTravel(bfx::Mover *this)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogMoverOrientStrictlyInDirectionOfTravel(replayID: *((_DWORD *)this + 78));
  bfx::MoverImpl::OrientStrictlyInDirectionOfTravel((bfx::MoverImpl *)this);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$87896
// EA  : 0x8326062C
// RVA : 0x0126062C
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_87896()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?OrientTowardsTargetPos@Mover@bfx@@QAAXABVVector3@2@@Z
// EA  : 0x83260660
// RVA : 0x01260660
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Mover::OrientTowardsTargetPos(bfx::Mover *this, const bfx::Vector3 *targetPos)
{
  int v4; // r27
  double m_y; // fp13
  double m_x; // fp12
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-60h]
  bfx::Vec3 v8; // [sp+58h] [-58h] BYREF
  bfx::Matrix v9; // [sp+68h] [-48h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  v4 = *((_DWORD *)this + 4);
  bfx::LogMoverOrientTowardsTargetPos(replayID: *((_DWORD *)this + 78), targetPos);
  m_y = targetPos->m_y;
  m_x = targetPos->m_x;
  v8.m_z = targetPos->m_z;
  v8.m_x = m_x;
  v8.m_y = m_y;
  bfx::Matrix::operator*(this: &v9, result: (bfx::Vec3 *)(v4 + 124), rhs: &v8);
  bfx::MoverImpl::OrientTowardsTargetPos((bfx::MoverImpl *)this, targetPos: (const bfx::Vec3 *)&v9);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$87938
// EA  : 0x832606F4
// RVA : 0x012606F4
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_87938()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 176 + 80));
}


// ========================================================================
// ?OrientInDirection@Mover@bfx@@QAAXABVVector3@2@@Z
// EA  : 0x83260728
// RVA : 0x01260728
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Mover::OrientInDirection(bfx::Mover *this, const bfx::Vector3 *dir)
{
  int v4; // r27
  double m_y; // fp13
  double m_x; // fp12
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-60h]
  bfx::Vec3 v8; // [sp+58h] [-58h] BYREF
  bfx::Matrix v9; // [sp+68h] [-48h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  v4 = *((_DWORD *)this + 4);
  bfx::LogMoverOrientInDirection(replayID: *((_DWORD *)this + 78), dir);
  m_y = dir->m_y;
  m_x = dir->m_x;
  v8.m_z = dir->m_z;
  v8.m_x = m_x;
  v8.m_y = m_y;
  bfx::Matrix::Rot(this: &v9, result: (bfx::Vec3 *)(v4 + 124), rhs: &v8);
  bfx::MoverImpl::OrientInDirection((bfx::MoverImpl *)this, dir: (const bfx::Vec3 *)&v9);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$88003
// EA  : 0x832607BC
// RVA : 0x012607BC
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_88003()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 176 + 80));
}


// ========================================================================
// ?SetTune@Mover@bfx@@QAAXPBUMoverTune@2@@Z
// EA  : 0x832607F0
// RVA : 0x012607F0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Mover::SetTune(bfx::Mover *this, const bfx::MoverTune *pTune)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogMoverSetTune(replayID: *((_DWORD *)this + 78), pTune);
  bfx::MoverImpl::SetTune((bfx::MoverImpl *)this, pTune);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$88067
// EA  : 0x83260858
// RVA : 0x01260858
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_88067()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?SetSpeedX@Mover@bfx@@QAAXM@Z
// EA  : 0x83260888
// RVA : 0x01260888
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Mover::SetSpeedX(bfx::Mover *this, double speedX)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogMoverSetSpeedX(replayID: *((_DWORD *)this + 78), speedX);
  *((float *)this + 173) = speedX;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$88108
// EA  : 0x832608F0
// RVA : 0x012608F0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_88108()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?SetSlowTime@Mover@bfx@@QAAXM@Z
// EA  : 0x83260920
// RVA : 0x01260920
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Mover::SetSlowTime(bfx::Mover *this, double slowTime)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogMoverSlowTime(replayID: *((_DWORD *)this + 78), slowTime);
  _FP12 = (float)((float)0.0099999998 - (float)slowTime);
  _FP11 = (float)((float)1.0 - (float)slowTime);
  __asm { fsel      f10, f12, f13, f31 }
  __asm { fsel      f8, f11, f9, f0 }
  *((float *)this + 174) = _FP8;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$88152
// EA  : 0x832609B4
// RVA : 0x012609B4
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_88152()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?SetFlockID@Mover@bfx@@QAAXI@Z
// EA  : 0x832609E8
// RVA : 0x012609E8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Mover::SetFlockID(bfx::Mover *this, unsigned int flockID)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogMoverSetFlockID(replayID: *((_DWORD *)this + 78), flockID);
  *((_DWORD *)this + 103) = flockID;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$88201
// EA  : 0x83260A48
// RVA : 0x01260A48
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_88201()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?SetExternalForce@Mover@bfx@@QAAXABVVector3@2@@Z
// EA  : 0x83260A78
// RVA : 0x01260A78
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Mover::SetExternalForce(bfx::Mover *this, const bfx::Vector3 *force)
{
  int v4; // r27
  double m_y; // fp13
  double m_x; // fp12
  double v7; // fp10
  double v8; // fp9
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-60h]
  bfx::Vec3 v10; // [sp+58h] [-58h] BYREF
  bfx::Matrix v11; // [sp+68h] [-48h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  v4 = *((_DWORD *)this + 4);
  bfx::LogMoverSetExternalForce(replayID: *((_DWORD *)this + 78), force);
  m_y = force->m_y;
  m_x = force->m_x;
  v10.m_z = force->m_z;
  v10.m_x = m_x;
  v10.m_y = m_y;
  bfx::Matrix::Rot(this: &v11, result: (bfx::Vec3 *)(v4 + 124), rhs: &v10);
  v7 = v11.m_data[1];
  v8 = v11.m_data[2];
  *((float *)this + 178) = v11.m_data[0];
  *((float *)this + 179) = v7;
  *((float *)this + 180) = v8;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$88246
// EA  : 0x83260B20
// RVA : 0x01260B20
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_88246()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 176 + 80));
}


// ========================================================================
// ?ReachedGoal@Mover@bfx@@QBA_NXZ
// EA  : 0x83260B50
// RVA : 0x01260B50
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

BOOL __fastcall bfx::Mover::ReachedGoal(bfx::Mover *this)
{
  BOOL v2; // r3
  unsigned int v3; // r11
  BOOL v4; // r29
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  v2 = bfx::MoverImpl::ReachedGoal((bfx::MoverImpl *)this);
  v3 = *((_DWORD *)this + 78);
  v4 = v2;
  bfx::LogMoverReachedGoal(replayID: v3, reachedGoal: v2);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return v4;
}


// ========================================================================
// __unwind$88928
// EA  : 0x83260BBC
// RVA : 0x01260BBC
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_88928()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?IsWaitingAtLink@Mover@bfx@@QBA_NPAVLinkUsageData@2@@Z
// EA  : 0x83260BF0
// RVA : 0x01260BF0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

BOOL __fastcall bfx::Mover::IsWaitingAtLink(bfx::Mover *this, bfx::LinkUsageData *pDataOut)
{
  BOOL IsWaitingAtLink; // r3
  unsigned int v5; // r11
  BOOL v6; // r29
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  IsWaitingAtLink = bfx::MoverImpl::IsWaitingAtLink((bfx::MoverImpl *)this, pDataOut);
  v5 = *((_DWORD *)this + 78);
  v6 = IsWaitingAtLink;
  bfx::LogMoverIsWaitingAtLink(replayID: v5, isWaitingAtLink: IsWaitingAtLink);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return v6;
}


// ========================================================================
// __unwind$89205
// EA  : 0x83260C64
// RVA : 0x01260C64
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_89205()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?IsBlockedByRepulsor@Mover@bfx@@QBA_NXZ
// EA  : 0x83260C98
// RVA : 0x01260C98
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

BOOL __fastcall bfx::Mover::IsBlockedByRepulsor(bfx::Mover *this)
{
  BOOL IsBlockedByRepulsor; // r3
  unsigned int v3; // r11
  BOOL v4; // r29
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  IsBlockedByRepulsor = bfx::MoverImpl::IsBlockedByRepulsor((bfx::MoverImpl *)this);
  v3 = *((_DWORD *)this + 78);
  v4 = IsBlockedByRepulsor;
  bfx::LogMoverIsBlockedByRepulsor(replayID: v3, isBlockedByRepulsor: IsBlockedByRepulsor);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return v4;
}


// ========================================================================
// __unwind$89281
// EA  : 0x83260D04
// RVA : 0x01260D04
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_89281()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?GetClosestReachablePos@Mover@bfx@@QAA?AVVector3@2@ABV32@@Z
// EA  : 0x83260D38
// RVA : 0x01260D38
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

bfx::Mover *__fastcall bfx::Mover::GetClosestReachablePos(
        bfx::Mover *this,
        bfx::Vec3 *result,
        const bfx::Vector3 *goalPos)
{
  double m_y; // fp13
  double m_x; // fp12
  float v8; // r26
  const bfx::Vec3 *ClosestReachablePos; // r3
  bfx::Vec3 *v10; // r3
  double m_z; // fp11
  double v12; // fp10
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-80h]
  bfx::Vec3 v15; // [sp+58h] [-78h] BYREF
  bfx::Matrix v16; // [sp+68h] [-68h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogMoverGetClosestReachablePos(replayID: LODWORD(result[26].m_x), testPos: goalPos);
  m_y = goalPos->m_y;
  m_x = goalPos->m_x;
  v15.m_z = goalPos->m_z;
  v15.m_x = m_x;
  v15.m_y = m_y;
  v8 = result[1].m_y;
  bfx::Matrix::operator*(this: &v16, result: (bfx::Vec3 *)(LODWORD(v8) + 124), rhs: &v15);
  ClosestReachablePos = bfx::MoverImpl::GetClosestReachablePos(
                          this: (bfx::MoverImpl *)&v16.m_data[4],
                          result,
                          goalPos: (const bfx::Vec3 *)&v16);
  v10 = bfx::Matrix::operator*(
          this: (bfx::Matrix *)&v16.m_data[8],
          result: (bfx::Vec3 *)(LODWORD(v8) + 60),
          rhs: ClosestReachablePos);
  m_z = v10->m_z;
  v12 = v10->m_y;
  *(float *)this = v10->m_x;
  *((float *)this + 1) = v12;
  *((float *)this + 2) = m_z;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return this;
}


// ========================================================================
// __unwind$89455
// EA  : 0x83260E00
// RVA : 0x01260E00
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_89455()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 208 + 80));
}


// ========================================================================
// ?GetClosestReachablePos@Mover@bfx@@QAA?AVVector3@2@ABV32@AAVAreaHandle@2@@Z
// EA  : 0x83260E30
// RVA : 0x01260E30
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

bfx::Mover *__fastcall bfx::Mover::GetClosestReachablePos(
        bfx::Mover *this,
        bfx::Vec3 *result,
        const bfx::Vector3 *goalPos,
        bfx::AreaHandle *startArea)
{
  double m_y; // fp13
  double m_x; // fp12
  float v10; // r26
  bfx::Area *Volume; // r3
  const bfx::Vec3 *ClosestReachablePos; // r3
  bfx::Vec3 *v13; // r3
  double m_z; // fp11
  double v15; // fp10
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-90h]
  bfx::Vec3 v18; // [sp+58h] [-88h] BYREF
  bfx::Matrix v19; // [sp+68h] [-78h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogMoverGetClosestReachablePos(replayID: LODWORD(result[26].m_x), testPos: goalPos, startArea);
  m_y = goalPos->m_y;
  m_x = goalPos->m_x;
  v18.m_z = goalPos->m_z;
  v18.m_x = m_x;
  v18.m_y = m_y;
  v10 = result[1].m_y;
  bfx::Matrix::operator*(this: &v19, result: (bfx::Vec3 *)(LODWORD(v10) + 124), rhs: &v18);
  Volume = (bfx::Area *)bfx::GetVolume(spaceHandle: (bfx::SpaceHandle *)startArea);
  ClosestReachablePos = bfx::MoverImpl::GetClosestReachablePos(
                          this: (bfx::MoverImpl *)&v19.m_data[4],
                          result,
                          goalPos: (const bfx::Vec3 *)&v19,
                          pStartArea: Volume);
  v13 = bfx::Matrix::operator*(
          this: (bfx::Matrix *)&v19.m_data[8],
          result: (bfx::Vec3 *)(LODWORD(v10) + 60),
          rhs: ClosestReachablePos);
  m_z = v13->m_z;
  v15 = v13->m_y;
  *(float *)this = v13->m_x;
  *((float *)this + 1) = v15;
  *((float *)this + 2) = m_z;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return this;
}


// ========================================================================
// __unwind$89565
// EA  : 0x83260F0C
// RVA : 0x01260F0C
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_89565()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 224 + 80));
}


// ========================================================================
// ?Teleport@Mover@bfx@@QAAXABVVector3@2@ABVQuaternion@2@0ABVAreaHandle@2@@Z
// EA  : 0x83260F40
// RVA : 0x01260F40
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Mover::Teleport(
        bfx::Mover *this,
        const bfx::Vector3 *newPos,
        const bfx::Quaternion *newRot,
        const bfx::Vector3 *newVel,
        bfx::AreaHandle *area)
{
  double m_y; // fp13
  double m_x; // fp12
  int v12; // r25
  double v13; // fp10
  double v14; // fp9
  double m_w; // fp8
  double v16; // fp6
  double v17; // fp5
  bfx::Area *Volume; // r3
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-C0h]
  bfx::Vec3 v20; // [sp+58h] [-B8h] BYREF
  bfx::Vec3 v21; // [sp+68h] [-A8h] BYREF
  bfx::Matrix v22[2]; // [sp+78h] [-98h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogMoverTeleport(replayID: *((_DWORD *)this + 78), newPos, newRot, newVel, area);
  m_y = newVel->m_y;
  m_x = newVel->m_x;
  v20.m_z = newVel->m_z;
  v20.m_x = m_x;
  v20.m_y = m_y;
  v12 = *((_DWORD *)this + 4);
  bfx::Matrix::Rot(this: v22, result: (bfx::Vec3 *)(v12 + 124), rhs: &v20);
  v13 = newRot->m_y;
  v14 = newRot->m_x;
  m_w = newRot->m_w;
  v22[0].m_data[13] = newRot->m_z;
  v22[0].m_data[12] = v13;
  v22[0].m_data[10] = m_w;
  v22[0].m_data[11] = v14;
  bfx::Quat::Normalize(this: (bfx::Quat *)&v22[0].m_data[10]);
  bfx::Quat::operator*(
    this: (bfx::Quat *)&v22[0].m_data[14],
    result: (bfx::Quat *)(v12 + 40),
    rhs: (const bfx::Quat *)&v22[0].m_data[10]);
  v16 = newPos->m_y;
  v17 = newPos->m_x;
  v21.m_z = newPos->m_z;
  v21.m_x = v17;
  v21.m_y = v16;
  bfx::Matrix::operator*(this: (bfx::Matrix *)&v22[0].m_data[4], result: (bfx::Vec3 *)(v12 + 124), rhs: &v21);
  Volume = (bfx::Area *)bfx::GetVolume(spaceHandle: (bfx::SpaceHandle *)area);
  bfx::MoverImpl::Teleport(
    (bfx::MoverImpl *)this,
    newPos: (const bfx::Vec3 *)&v22[0].m_data[4],
    newRot: (const bfx::Quat *)&v22[0].m_data[14],
    newVel: (const bfx::Vec3 *)v22,
    pArea: Volume);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$89676
// EA  : 0x83261064
// RVA : 0x01261064
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_89676()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 272 + 80));
}


// ========================================================================
// ?TeleportToSpace@Mover@bfx@@QAAXAAVSpaceHandle@2@ABVVector3@2@ABVQuaternion@2@1ABVAreaHandle@2@@Z
// EA  : 0x83261098
// RVA : 0x01261098
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Mover::TeleportToSpace(
        bfx::Mover *this,
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *newPos,
        const bfx::Quaternion *newRot,
        const bfx::Vector3 *newVel,
        bfx::AreaHandle *areaHandle)
{
  _RTL_CRITICAL_SECTION *p_m_criticalSection; // r21
  bfx::Space *Volume; // r28
  unsigned int v14; // r24
  unsigned int v15; // r22
  double m_z; // fp13
  double m_y; // fp12
  bfx::Space *v18; // r3
  char v19; // r11
  bfx::Space *TypeDef; // r22
  bfx::Area *v21; // r24
  __int64 v22; // r10
  __int64 v23; // r8
  __int64 v24; // r6
  __int64 v25; // r4
  double v26; // fp13
  double m_x; // fp12
  double v28; // fp10
  double v29; // fp9
  bfx::Space *v30; // r3
  int v31; // [sp+8h] [-2A8h]
  int v32; // [sp+Ch] [-2A4h]
  int v33; // [sp+10h] [-2A0h]
  int v34; // [sp+14h] [-29Ch]
  bfx::Vec3 v35; // [sp+50h] [-260h] BYREF
  bfx::Vec3 v36; // [sp+60h] [-250h] BYREF
  bfx::Vec3 v37; // [sp+70h] [-240h] BYREF
  bfx::APICriticalSection *m_pGlobalCS; // [sp+7Ch] [-234h]
  bfx::Mover *v39; // [sp+80h] [-230h]
  bfx::Matrix v40; // [sp+88h] [-228h] BYREF
  bfx::MoverSaveRestoreState v41; // [sp+D0h] [-1E0h] BYREF
  bfx::MoverTune v42; // [sp+130h] [-180h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  p_m_criticalSection = &m_pGlobalCS->m_criticalSection;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogMoverTeleportToSpace(replayID: *((_DWORD *)this + 78), spaceHandle, newPos, newRot, newVel, area: areaHandle);
  Volume = bfx::GetVolume(spaceHandle);
  if ( Volume != nullptr )
  {
    bfx::MoverTune::MoverTune(this: &v42);
    v42 = *(bfx::MoverTune *)*((_DWORD *)this + 187);
    v14 = *((_DWORD *)this + 103);
    v15 = *((_DWORD *)this + 78);
    bfx::MoverSaveRestoreState::MoverSaveRestoreState(this: &v41);
    bfx::MoverImpl::SaveMoverState((bfx::MoverImpl *)this, moverSaveRestoreStateOut: &v41);
    (**(void (__fastcall ***)(bfx::Mover *, _DWORD))this)(a1: this, a2: 0);
    v39 = this;
    m_z = newPos->m_z;
    m_y = newPos->m_y;
    v35.m_x = newPos->m_x;
    v35.m_z = m_z;
    v35.m_y = m_y;
    bfx::Matrix::operator*(this: &v40, result: (bfx::Vec3 *)&Volume->m_matWorldToSpace, rhs: &v35);
    v18 = bfx::Space::RotateToSpace(this: (bfx::Space *)&v40.m_data[14], result: (bfx::Quat *)Volume, rotIn: newRot);
    bfx::MoverImpl::MoverImpl(
      (bfx::MoverImpl *)this,
      pSpace: Volume,
      initialClientProvidedPos: (const bfx::Vec3 *)&v40,
      rot: (const bfx::Quat *)v18,
      pInputTune: &v42,
      flockID: v14,
      replayID: v15);
    if ( newVel->m_x != 0.0 || newVel->m_y != 0.0 || (v19 = 1, newVel->m_z != 0.0) )
      v19 = 0;
    if ( v19 == 0 || (unsigned __int8)bfx::AreaHandle::IsValid(this: areaHandle) != 0 )
    {
      TypeDef = idScriptObject::GetTypeDef(this: (bfx::Planner3D *)areaHandle);
      v21 = nullptr;
      if ( (unsigned __int8)bfx::AreaHandle::IsValid(this: areaHandle) != 0 )
      {
        if ( TypeDef == Volume )
        {
          v21 = (bfx::Area *)bfx::GetVolume(spaceHandle: (bfx::SpaceHandle *)areaHandle);
        }
        else
        {
          HIDWORD(v25) = "TeleportToSpace called with AreaHandle from a different space.  Ignoring area.";
          bfx::InternalWarning(fmt: v25, a2: v24, a3: v23, a4: v22, a5: v31, a6: v32, a7: v33, a8: v34);
        }
      }
      v26 = newVel->m_y;
      m_x = newVel->m_x;
      v37.m_z = newVel->m_z;
      v37.m_x = m_x;
      v37.m_y = v26;
      bfx::Matrix::Rot(this: (bfx::Matrix *)&v40.m_data[8], result: (bfx::Vec3 *)&Volume->m_matWorldToSpace, rhs: &v37);
      v28 = newPos->m_y;
      v29 = newPos->m_x;
      v36.m_z = newPos->m_z;
      v36.m_x = v29;
      v36.m_y = v28;
      bfx::Matrix::operator*(
        this: (bfx::Matrix *)&v40.m_data[4],
        result: (bfx::Vec3 *)&Volume->m_matWorldToSpace,
        rhs: &v36);
      v30 = bfx::Space::RotateToSpace(this: (bfx::Space *)&v40.m_data[14], result: (bfx::Quat *)Volume, rotIn: newRot);
      bfx::MoverImpl::Teleport(
        (bfx::MoverImpl *)this,
        newPos: (const bfx::Vec3 *)&v40.m_data[4],
        newRot: (const bfx::Quat *)v30,
        newVel: (const bfx::Vec3 *)&v40.m_data[8],
        pArea: v21);
    }
    bfx::MoverImpl::RestoreFromMoverState((bfx::MoverImpl *)this, moverSaveRestoreState: &v41);
  }
  if ( p_m_criticalSection != nullptr )
    RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
}


// ========================================================================
// __unwind$89792
// EA  : 0x832612FC
// RVA : 0x012612FC
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_89792()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 688 + 124));
}


// ========================================================================
// __unwind$89793
// EA  : 0x83261324
// RVA : 0x01261324
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_89793()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 688 + 128));
}


// ========================================================================
// ?EnableRepulsor@Mover@bfx@@QAAX_N@Z
// EA  : 0x83261360
// RVA : 0x01261360
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Mover::EnableRepulsor(bfx::Mover *this, bool enable)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogMoverEnableRepulsor(replayID: *((_DWORD *)this + 78), enable);
  bfx::MoverImpl::EnableRepulsor((bfx::MoverImpl *)this, enable);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$89933
// EA  : 0x832613C8
// RVA : 0x012613C8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_89933()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?TurnToEnd@Mover@bfx@@QAAXPBVVector3@2@@Z
// EA  : 0x832613F8
// RVA : 0x012613F8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Mover::TurnToEnd(bfx::Mover *this, const bfx::Vector3 *pForwardVec)
{
  int v4; // r28
  double m_y; // fp13
  double m_x; // fp12
  const bfx::Vec3 *v7; // r4
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-70h]
  bfx::Vec3 v9; // [sp+58h] [-68h] BYREF
  bfx::Matrix v10; // [sp+68h] [-58h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  v4 = *((_DWORD *)this + 4);
  bfx::LogMoverTurnToEnd(replayID: *((_DWORD *)this + 78), pForwardVec);
  if ( pForwardVec != nullptr )
  {
    m_y = pForwardVec->m_y;
    m_x = pForwardVec->m_x;
    v9.m_z = pForwardVec->m_z;
    v9.m_x = m_x;
    v9.m_y = m_y;
    bfx::Matrix::Rot(this: &v10, result: (bfx::Vec3 *)(v4 + 124), rhs: &v9);
    v7 = (const bfx::Vec3 *)&v10.m_data[4];
    v10.m_data[4] = v10.m_data[0];
    v10.m_data[5] = v10.m_data[1];
    v10.m_data[6] = v10.m_data[2];
  }
  else
  {
    v7 = nullptr;
  }
  bfx::MoverImpl::TurnToEnd((bfx::MoverImpl *)this, pForwardVec: v7);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$89977
// EA  : 0x832614B4
// RVA : 0x012614B4
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_89977()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 192 + 80));
}


// ========================================================================
// ?OverrideColor@Mover@bfx@@QAAXABVColor@2@@Z
// EA  : 0x832614E8
// RVA : 0x012614E8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Mover::OverrideColor(bfx::Mover *this, const bfx::Color *color)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogMoverOverrideColor(replayID: *((_DWORD *)this + 78), color);
  *((_DWORD *)this + 266) = LODWORD(color->m_r);
  *((_DWORD *)this + 267) = LODWORD(color->m_g);
  *((_DWORD *)this + 268) = LODWORD(color->m_b);
  *((_DWORD *)this + 269) = LODWORD(color->m_a);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$90121
// EA  : 0x83261564
// RVA : 0x01261564
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_90121()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?SetDebugName@Mover@bfx@@QAAXPBD@Z
// EA  : 0x83261598
// RVA : 0x01261598
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Mover::SetDebugName(bfx::Mover *this, const char *name)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::MoverImpl::SetDebugName((bfx::MoverImpl *)this, name);
  bfx::LogMoverSetDebugName(replayID: *((_DWORD *)this + 78), name);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$90202
// EA  : 0x83261600
// RVA : 0x01261600
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_90202()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?GetDesiredMotion@Mover@bfx@@QBAXAAVDesiredMotion@2@@Z
// EA  : 0x83261630
// RVA : 0x01261630
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Mover::GetDesiredMotion(bfx::Mover *this, bfx::DesiredMotion *desiredMotion)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::MoverImpl::GetDesiredMotion((bfx::MoverImpl *)this, desiredMotion);
  bfx::LogMoverGetDesiredMotion(replayID: *((_DWORD *)this + 78), desiredMotion);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$90282
// EA  : 0x83261698
// RVA : 0x01261698
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_90282()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?ApplyClientMotion@Mover@bfx@@QAAXABVVector3@2@M@Z
// EA  : 0x832616C8
// RVA : 0x012616C8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Mover::ApplyClientMotion(bfx::Mover *this, const bfx::Vector3 *vel, double rotSpeed)
{
  int v6; // r27
  double m_y; // fp13
  double m_x; // fp12
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-60h]
  bfx::Vec3 v10; // [sp+58h] [-58h] BYREF
  bfx::Matrix v11; // [sp+68h] [-48h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  v6 = *((_DWORD *)this + 4);
  bfx::LogMoverApplyClientMotion(replayID: *((_DWORD *)this + 78), vel, rotSpeed);
  m_y = vel->m_y;
  m_x = vel->m_x;
  v10.m_z = vel->m_z;
  v10.m_x = m_x;
  v10.m_y = m_y;
  bfx::Matrix::Rot(this: &v11, result: (bfx::Vec3 *)(v6 + 124), rhs: &v10);
  bfx::MoverImpl::ApplyClientMotion(
    (bfx::MoverImpl *)this,
    vel: (const bfx::Vec3 *)&v11,
    rotSpeedDegPerSecond: rotSpeed);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$90324
// EA  : 0x83261770
// RVA : 0x01261770
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_90324()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 176 + 80));
}


// ========================================================================
// ?CreateMover@bfx@@YAPAVMover@1@AAVSpaceHandle@1@ABVVector3@1@ABVQuaternion@1@PBUMoverTune@1@I@Z
// EA  : 0x832617F0
// RVA : 0x012617F0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

bfx::MoverImpl *__fastcall bfx::CreateMover(
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *pos,
        const bfx::Quaternion *rot,
        const bfx::MoverTune *pTune,
        unsigned int flockID)
{
  _RTL_CRITICAL_SECTION *p_m_criticalSection; // r23
  bfx::InstanceComponent *v11; // r9
  unsigned int v12; // r28
  bfx::Space *Volume; // r30
  bfx::MoverImpl *v15; // r27
  double m_y; // fp13
  double m_x; // fp12
  bfx::Space *v18; // r3
  bfx::MoverImpl *v19; // r30
  bfx::FTimerOb v20; // [sp+50h] [-90h] BYREF
  bfx::APICriticalSection *m_pGlobalCS; // [sp+54h] [-8Ch]
  bfx::MoverImpl *v22; // [sp+58h] [-88h]
  bfx::Vec3 v23; // [sp+60h] [-80h] BYREF
  bfx::Matrix v24; // [sp+70h] [-70h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  p_m_criticalSection = &m_pGlobalCS->m_criticalSection;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::FTimerOb::FTimerOb(this: &v20, timerEntry: &bfx::createMoverTimer);
  v11 = bfx::g_pCurInstance->m_pComponentManager->m_components[4];
  v12 = (unsigned int)v11[5].__vftable;
  v11[5].__vftable = (bfx::InstanceComponent_vtbl *)(v12 + 1);
  bfx::LogCreateMover(spaceHandle, replayID: v12, pos, rot, pTune, flockID);
  Volume = bfx::GetVolume(spaceHandle);
  if ( Volume != nullptr )
  {
    v15 = (bfx::MoverImpl *)bfx::MemoryManager::Malloc(
                              this: bfx::g_pCurInstance->m_pMemoryManager,
                              size: 0x498u,
                              tag: bfx::MEM_BFXMOVER);
    v22 = v15;
    if ( v15 != nullptr )
    {
      m_y = pos->m_y;
      m_x = pos->m_x;
      v23.m_z = pos->m_z;
      v23.m_x = m_x;
      v23.m_y = m_y;
      bfx::Matrix::operator*(this: &v24, result: (bfx::Vec3 *)&Volume->m_matWorldToSpace, rhs: &v23);
      v18 = bfx::Space::RotateToSpace(this: (bfx::Space *)&v24.m_data[4], result: (bfx::Quat *)Volume, rotIn: rot);
      v19 = bfx::MoverImpl::MoverImpl(
              this: v15,
              pSpace: Volume,
              initialClientProvidedPos: (const bfx::Vec3 *)&v24,
              rot: (const bfx::Quat *)v18,
              pInputTune: pTune,
              flockID,
              replayID: v12);
    }
    else
    {
      v19 = nullptr;
    }
    if ( v20.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v20.m_pFTimer);
    if ( p_m_criticalSection != nullptr )
      RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
    return v19;
  }
  else
  {
    if ( v20.m_pFTimer != nullptr )
      bfx::FTimer::Stop(this: v20.m_pFTimer);
    if ( p_m_criticalSection != nullptr )
      RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
    return nullptr;
  }
}


// ========================================================================
// __unwind$90586
// EA  : 0x8326196C
// RVA : 0x0126196C
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_90586()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 224 + 84));
}


// ========================================================================
// __unwind$90587
// EA  : 0x83261994
// RVA : 0x01261994
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_90587()
{
  int v0; // r12

  bfx::FTimerOb::~FTimerOb(this: (bfx::FTimerOb *)(v0 - 224 + 80));
}


// ========================================================================
// __unwind$90588
// EA  : 0x832619BC
// RVA : 0x012619BC
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_90588()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 224 + 88), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?DestroyMover@bfx@@YAXPAVMover@1@@Z
// EA  : 0x832619F0
// RVA : 0x012619F0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::DestroyMover(bfx::Mover *pMover)
{
  _RTL_CRITICAL_SECTION *p_m_criticalSection; // r29
  bfx::FTimerOb v3; // [sp+50h] [-30h] BYREF
  bfx::APICriticalSection *m_pGlobalCS; // [sp+54h] [-2Ch]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  p_m_criticalSection = &m_pGlobalCS->m_criticalSection;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::FTimerOb::FTimerOb(this: &v3, timerEntry: &bfx::createMoverTimer);
  bfx::LogDestroyMover(replayID: *(_DWORD *)&pMover[312]);
  (**(void (__fastcall ***)(bfx::Mover *, int))pMover)(a1: pMover, a2: 1);
  if ( v3.m_pFTimer != nullptr )
    bfx::FTimer::Stop(this: v3.m_pFTimer);
  if ( p_m_criticalSection != nullptr )
    RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
}


// ========================================================================
// __unwind$90700
// EA  : 0x83261A7C
// RVA : 0x01261A7C
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_90700()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 84));
}


// ========================================================================
// __unwind$90701
// EA  : 0x83261AA4
// RVA : 0x01261AA4
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_90701()
{
  int v0; // r12

  bfx::FTimerOb::~FTimerOb(this: (bfx::FTimerOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?Draw@Trail@bfx@@QBAXPAVSpace@2@ABVColor@2@@Z
// EA  : 0x83261AD0
// RVA : 0x01261AD0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::Trail::Draw(bfx::Trail *this, bfx::Space *pSpace, const bfx::Color *color)
{
  int m_head; // r10
  int m_tail; // r11
  int v8; // r10
  unsigned int v9; // r9
  float *p_m_x; // r11
  int v11; // r31
  float *v12; // r11
  bfx::Vec3 v13; // [sp+50h] [-50h] BYREF
  float v14; // [sp+5Ch] [-44h]
  float v15; // [sp+60h] [-40h]
  float v16; // [sp+64h] [-3Ch]

  m_head = this->m_head;
  if ( m_head != -1 )
  {
    m_tail = this->m_tail;
    if ( m_tail != m_head )
    {
      do
      {
        v8 = m_tail + 1;
        v9 = (int)((unsigned __int64)(274877907LL * (m_tail + 1)) >> 32) >> 6;
        p_m_x = &this->m_pts[m_tail].m_x;
        v13.m_x = *p_m_x;
        v13.m_y = p_m_x[1];
        v11 = v8 - 1000 * (v9 + (v9 >> 31));
        v13.m_z = p_m_x[2];
        v12 = &this->m_pts[v11].m_x;
        v14 = *v12;
        v15 = v12[1];
        v16 = v12[2];
        bfx::DrawLineList(pSpace, pVerts: &v13, numVerts: 2, color);
        m_tail = v11;
      }
      while ( v11 != this->m_head );
    }
  }
}


// ========================================================================
// ?CalculateNextNCorners@Mover@bfx@@QAAHHQAVCornerData@2@@Z
// EA  : 0x83261BA8
// RVA : 0x01261BA8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

int __fastcall bfx::Mover::CalculateNextNCorners(
        bfx::Mover *this,
        int maxNumOutCorners,
        bfx::CornerData *cornersOutArray)
{
  bfx::AreaProxy *v6; // r26
  int v7; // r28
  bfx::SmartPathCorner *m_data; // r4
  bfx::SmartPathCorner *i; // r30
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-70h]
  bfx::Array<bfx::SmartPathCorner> v12[6]; // [sp+60h] [-60h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogMoverCalculateNextNCorners(replayID: *((_DWORD *)this + 78), maxNumCorners: maxNumOutCorners);
  memset(v12, 0, 12);
  v6 = *((bfx::AreaProxy **)this + 4);
  v12[0].m_tag = bfx::MEM_BFXMOVER;
  if ( bfx::MoverImpl::CalculateCornersArray((bfx::MoverImpl *)this, cornersOut: v12, maxNumCorners: maxNumOutCorners) )
  {
    v7 = 0;
    m_data = v12[0].m_data;
    for ( i = v12[0].m_data; i != &v12[0].m_data[v12[0].m_size]; ++cornersOutArray )
    {
      bfx::SmartPathCorners2CornerData(cornerOut: cornersOutArray, cornerIn: i, pSpace: v6);
      m_data = v12[0].m_data;
      ++i;
      ++v7;
    }
    v12[0].m_size = 0;
    if ( m_data != nullptr )
    {
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
      v12[0].m_data = nullptr;
    }
    v12[0].m_cap = 0;
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return v7;
  }
  else
  {
    v12[0].m_size = 0;
    if ( v12[0].m_data != nullptr )
    {
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v12[0].m_data);
      v12[0].m_data = nullptr;
    }
    v12[0].m_cap = 0;
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return 0;
  }
}


// ========================================================================
// __unwind$91119
// EA  : 0x83261CF8
// RVA : 0x01261CF8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_91119()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 192 + 80));
}


// ========================================================================
// __unwind$91120
// EA  : 0x83261D20
// RVA : 0x01261D20
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_91120()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 192 + 96));
}


// ========================================================================
// ?ClearObstacle@AutoObData@bfx@@QAAXXZ
// EA  : 0x83261D48
// RVA : 0x01261D48
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::AutoObData::ClearObstacle(bfx::AutoObData *this)
{
  bfx::Space *m_pSpace; // r3
  bfx::ObstacleImpl **m_pProxy; // r11
  bfx::Planner *v5; // r3
  bfx::MoverSpaceComponent *MoverSpaceComponent; // r3
  bfx::Handle<bfx::ObstacleImpl> v7; // [sp+50h] [-20h] BYREF

  m_pSpace = this->m_pSpace;
  if ( m_pSpace != nullptr )
  {
    m_pProxy = (bfx::ObstacleImpl **)this->m_obstacle.m_pProxy;
    if ( m_pProxy != nullptr && *m_pProxy != nullptr )
    {
      v5 = *((bfx::Planner **)m_pSpace->m_components.m_data + 1);
      if ( m_pProxy != nullptr )
        bfx::Planner::DestroyObstacle(this: v5, pObstacle: *m_pProxy);
      else
        bfx::Planner::DestroyObstacle(this: v5, pObstacle: nullptr);
    }
    else if ( this->m_obstacle.m_pProxy != nullptr )
    {
      MoverSpaceComponent = bfx::GetMoverSpaceComponent(pSpace: m_pSpace);
      v7.m_pProxy = this->m_obstacle.m_pProxy;
      if ( v7.m_pProxy != nullptr )
        *((_DWORD *)v7.m_pProxy + 1) = (unsigned __int8)*((_DWORD *)v7.m_pProxy + 1)
                                     | ((*((_DWORD *)v7.m_pProxy + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
      bfx::MoverSpaceComponent::CancelObstacleCreationRequest(this: MoverSpaceComponent, hObstacle: &v7);
    }
    this->m_pSpace = nullptr;
    this->m_timer = 0.0;
  }
}


// ========================================================================
// ??1AutoObData@bfx@@QAA@XZ
// EA  : 0x83261E28
// RVA : 0x01261E28
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __fastcall bfx::AutoObData::~AutoObData(bfx::AutoObData *this)
{
  bfx::HandleProxy *m_pProxy; // r3

  bfx::AutoObData::ClearObstacle(this);
  m_pProxy = this->m_obstacle.m_pProxy;
  if ( m_pProxy != nullptr )
  {
    bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
    this->m_obstacle.m_pProxy = nullptr;
  }
}


// ========================================================================
// __unwind$91544
// EA  : 0x83261E7C
// RVA : 0x01261E7C
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void _unwind_91544()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: (bfx::Handle<bfx::Space> *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// bfx::`dynamic initializer for 'g_drawMoverIdsRestore''
// EA  : 0x83398370
// RVA : 0x01398370
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_drawMoverIdsRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_drawMoverIdsRestore);
  bfx::g_drawMoverIdsRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_drawMoverIdsRestore.m_targetBool = &bfx::g_drawMoverIds;
  bfx::g_drawMoverIdsRestore.m_name = "draw_mover_ids";
  bfx::g_drawMoverIdsRestore.m_defaultBool = bfx::g_drawMoverIds;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_drawMoverIdsRestore__);
}


// ========================================================================
// bfx::`dynamic initializer for 'createMoverTimer''
// EA  : 0x833983E8
// RVA : 0x013983E8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmover.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__createMoverTimer__()
{
  int v0; // r9

  v0 = bfx::g_nextFTimerEntryID;
  bfx::createMoverTimer.m_pNext = bfx::g_pFTimerEntryHead;
  bfx::createMoverTimer.m_timerID = bfx::g_nextFTimerEntryID;
  if ( bfx::g_pFTimerEntryHead != nullptr )
  {
    bfx::g_pFTimerEntryHead->m_pPrev = &bfx::createMoverTimer;
    v0 = bfx::g_nextFTimerEntryID;
  }
  bfx::g_pFTimerEntryHead = &bfx::createMoverTimer;
  bfx::g_nextFTimerEntryID = v0 + 1;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__createMoverTimer__);
}

