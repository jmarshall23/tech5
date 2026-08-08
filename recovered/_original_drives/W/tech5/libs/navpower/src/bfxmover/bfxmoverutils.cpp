
// ========================================================================
// ?ApplyLimits_JumperTune@bfx@@YAXAAUJumperTune@1@@Z
// EA  : 0x832AE030
// RVA : 0x012AE030
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverutils.cpp
// ========================================================================

void __fastcall bfx::ApplyLimits_JumperTune(bfx::JumperTune *tune, int a2, int a3, int a4, __int64 a5)
{
  __int64 v5; // r10
  __int64 v7; // r8
  __int64 v8; // r10
  int v9; // r5
  int v10; // r4
  const char *v11; // r3

  LODWORD(v5) = 0x82000000;
  HIDWORD(v5) = &dword_82420000;
  tune->m_arcFraction = bfx::LimitWarn(
                          val: tune->m_arcFraction,
                          min: 0.0,
                          max: 1.0,
                          name: (const char *)tune,
                          a5: a2,
                          a6: a3,
                          a7: (unsigned int)"m_arcFraction",
                          a8: a5,
                          a9: v5);
  LODWORD(v7) = &unk_821D0000;
  HIDWORD(v7) = &dword_82420000;
  tune->m_turnBeforeJumpAngle = bfx::LimitWarn(
                                  val: tune->m_turnBeforeJumpAngle,
                                  min: 0.0,
                                  max: 180.0,
                                  name: v11,
                                  a5: v10,
                                  a6: v9,
                                  a7: (unsigned int)"m_turnBeforeJumpAngle",
                                  a8: v7,
                                  a9: v8);
}


// ========================================================================
// ?ApplyLimits_SurfaceOrientTune@bfx@@YAXAAVSurfaceOrientTune@1@@Z
// EA  : 0x832AE0A8
// RVA : 0x012AE0A8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverutils.cpp
// ========================================================================

void __fastcall bfx::ApplyLimits_SurfaceOrientTune(bfx::SurfaceOrientTune *tune, int a2, int a3, int a4, __int64 a5)
{
  __int64 v5; // r10
  __int64 v7; // r8
  __int64 v8; // r10
  int v9; // r5
  int v10; // r4
  const char *v11; // r3

  LODWORD(v5) = 0x82000000;
  HIDWORD(v5) = &dword_82420000;
  tune->m_surfaceOrientThreshold = bfx::LimitWarn(
                                     val: tune->m_surfaceOrientThreshold,
                                     min: 0.0,
                                     max: 60.0,
                                     name: (const char *)tune,
                                     a5: a2,
                                     a6: a3,
                                     a7: (unsigned int)"SurfaceOrientTune::m_surfaceOrientThreshold",
                                     a8: a5,
                                     a9: v5);
  LODWORD(v7) = &unk_82150000;
  HIDWORD(v7) = &dword_82420000;
  tune->m_surfaceOrientSlerpTime = bfx::LimitWarn(
                                     val: tune->m_surfaceOrientSlerpTime,
                                     min: 0.0,
                                     max: 5.0,
                                     name: v11,
                                     a5: v10,
                                     a6: v9,
                                     a7: (unsigned int)"SurfaceOrientTune::m_surfaceOrientSlerpTime",
                                     a8: v7,
                                     a9: v8);
}


// ========================================================================
// ?BuildMoverPathSpec@bfx@@YA?AVPathSpec@1@PBUMoverTune@1@@Z
// EA  : 0x832AE120
// RVA : 0x012AE120
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverutils.cpp
// ========================================================================

bfx::PathSpec *__fastcall bfx::BuildMoverPathSpec(bfx::PathSpec *result, const bfx::MoverTune *pTune)
{
  bfx::BlockageMode m_obstacleMode; // r9
  unsigned int m_obstacleBlockageFlags; // r8
  unsigned int m_areaUsageFlags; // r7
  double m_pathSharingPenalty; // fp13
  unsigned int m_linkUsageFlags; // r6
  double m_maxPathSharingPenalty; // fp0

  m_obstacleMode = pTune->m_obstacleMode;
  m_obstacleBlockageFlags = pTune->m_obstacleBlockageFlags;
  m_areaUsageFlags = pTune->m_areaUsageFlags;
  m_pathSharingPenalty = pTune->m_pathSharingPenalty;
  m_linkUsageFlags = pTune->m_linkUsageFlags;
  result->m_usePathSharingPenalty = false;
  result->m_obstacleMode = m_obstacleMode;
  result->m_maxSearchDist = 0.0;
  result->m_obstacleBlockageFlags = m_obstacleBlockageFlags;
  result->m_pathSharingPenalty = 0.0;
  result->m_areaUsageFlags = m_areaUsageFlags;
  result->m_maxPathSharingPenalty = 0.0;
  result->m_linkUsageFlags = m_linkUsageFlags;
  m_maxPathSharingPenalty = pTune->m_maxPathSharingPenalty;
  result->m_usePathSharingPenalty = m_pathSharingPenalty > 0.0;
  result->m_pathSharingPenalty = m_pathSharingPenalty;
  result->m_maxPathSharingPenalty = m_maxPathSharingPenalty;
  return result;
}


// ========================================================================
// ?OkToMoveOntoArea@bfx@@YA_NPAVArea@1@PBUMoverTune@1@@Z
// EA  : 0x832AE180
// RVA : 0x012AE180
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverutils.cpp
// ========================================================================

int __fastcall bfx::OkToMoveOntoArea(bfx::Area *pArea, const bfx::MoverTune *pTune)
{
  unsigned int m_obstacleBlockageFlags; // r11
  int m_flags2_low; // r10
  bool v4; // r11
  char v5; // r11
  bool v6; // zf
  unsigned int m_usageFlags; // r11
  unsigned int v8; // r9
  char v9; // r11
  unsigned __int8 v10; // r11

  m_obstacleBlockageFlags = pTune->m_obstacleBlockageFlags;
  if ( (pArea->m_flags.m_flags1 & 0x20000000) == 0
    || ((m_flags2_low = LOWORD(pArea->m_flags.m_flags2), pTune->m_obstacleMode != BLOCKED_IF_ANY_MATCH)
      ? (v4 = (_cntlzw(m_obstacleBlockageFlags - (m_flags2_low & m_obstacleBlockageFlags)) & 0x20) != 0)
      : (v4 = (m_flags2_low & m_obstacleBlockageFlags) != 0),
        v6 = v4,
        v5 = 1,
        !v6) )
  {
    v5 = 0;
  }
  if ( v5 != 0 )
    return 0;
  m_usageFlags = pArea->m_usageFlags;
  if ( m_usageFlags == 0 || (v8 = pTune->m_areaUsageFlags & m_usageFlags, v9 = 1, v8 != 0) )
    v9 = 0;
  v6 = v9 == 0;
  v10 = 1;
  if ( !v6 )
    return 0;
  return v10;
}


// ========================================================================
// ?CalcRampAcc@bfx@@YAMMMMM@Z
// EA  : 0x832AE228
// RVA : 0x012AE228
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverutils.cpp
// ========================================================================

float __fastcall bfx::CalcRampAcc(double dist, double startDist, double endDist, double maxAcc)
{
  double v4; // fp1

  if ( dist > startDist )
  {
    if ( dist < endDist )
      v4 = (float)((float)((float)((float)dist - (float)startDist) / (float)((float)endDist - (float)startDist))
                 * (float)maxAcc);
    else
      v4 = maxAcc;
  }
  else
  {
    v4 = 0.0;
  }
  return *((float *)&v4 + 1);
}


// ========================================================================
// bfx::LimitWarnStartStopMuchLessThanOtherAcc
// EA  : 0x832AE268
// RVA : 0x012AE268
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverutils.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
float __fastcall bfx::LimitWarnStartStopMuchLessThanOtherAcc(
        double startStopAcc,
        double otherAcc,
        const char *otherAccName,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        __int64 a9)
{
  double v9; // fp31
  int v10; // r8 OVERLAPPED
  __int128 v12; // r5 OVERLAPPED
  int v14; // [sp+8h] [-58h]
  int v15; // [sp+Ch] [-54h]
  int v16; // [sp+10h] [-50h]
  int v17; // [sp+14h] [-4Ch]

  v9 = (float)((float)otherAcc * (float)0.25);
  if ( startStopAcc < v9 )
  {
    v10 = LODWORD(v9);
    LODWORD(a9) = &dword_82420000;
    DWORD1(v12) = "m_startStopAcc (%.0f) is less than %.0f percent of %s (%.0f) and will be increased to %.0f\n";
    *((_QWORD *)&v12 + 1) = 0x4039000000000000LL;
    bfx::InternalWarning(
      fmt: *(__int64 *)((char *)&v12 + 4),
      a2: *(__int64 *)((char *)&otherAcc + 4),
      a3: *(__int64 *)&v10,
      a4: a9,
      a5: v14,
      a6: v15,
      a7: v16,
      a8: v17);
    startStopAcc = v9;
  }
  return *((float *)&startStopAcc + 1);
}


// ========================================================================
// ?Update@BlockedMonitor@bfx@@QAAXABVVec3@2@MMM@Z
// EA  : 0x832AE2E8
// RVA : 0x012AE2E8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverutils.cpp
// ========================================================================

void __fastcall bfx::BlockedMonitor::Update(
        bfx::BlockedMonitor *this,
        const bfx::Vec3 *pos,
        double desiredSpeed,
        double radius,
        double simTime)
{
  double v5; // fp0
  double v6; // fp12
  double v7; // fp13

  if ( desiredSpeed <= 1.0842022e-19 )
  {
    this->m_blockedTimer = 0.0;
  }
  else
  {
    v7 = (float)(pos->m_y - this->m_oldPosForBlockedCheck.m_y);
    _FP5 = (float)((float)((float)((float)desiredSpeed * 2.0) * (float)0.0625) - (float)radius);
    __asm { fsel      f2, f5, f2, f7 }
    v6 = (float)(pos->m_z - this->m_oldPosForBlockedCheck.m_z);
    v5 = (float)(pos->m_x - this->m_oldPosForBlockedCheck.m_x);
    if ( __fsqrts((float)((float)((float)v7 * (float)v7)
                        + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5)))) <= _FP2 )
    {
      this->m_blockedTimer = this->m_blockedTimer + (float)simTime;
    }
    else
    {
      this->m_blockedTimer = 0.0;
      this->m_oldPosForBlockedCheck = *pos;
    }
  }
}


// ========================================================================
// ?Teleport@BlockedMonitor@bfx@@QAAXABVVec3@2@@Z
// EA  : 0x832AE3A0
// RVA : 0x012AE3A0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverutils.cpp
// ========================================================================

void __fastcall bfx::BlockedMonitor::Teleport(bfx::BlockedMonitor *this, const bfx::Vec3 *pos)
{
  this->m_oldPosForBlockedCheck = *pos;
  this->m_blockedTimer = 0.0;
}


// ========================================================================
// ?IsTurningInPlaceHelper@MotionBase@bfx@@IBA_NPAVTurningInPlaceData@2@ABVMotionState@2@ABVVec3@2@@Z
// EA  : 0x832AE3C8
// RVA : 0x012AE3C8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverutils.cpp
// ========================================================================

int __fastcall bfx::MotionBase::IsTurningInPlaceHelper(
        bfx::MotionBase *this,
        bfx::TurningInPlaceData *pDataOut,
        const bfx::MotionState *commonState,
        const bfx::Vec3 *curVel)
{
  bfx::Orienter::State m_state; // r11
  bfx::Vec3 *RotVel; // r3
  double v10; // fp7
  double v11; // fp5
  double v12; // fp0
  double v13; // fp12
  double v14; // fp30
  double Scale; // fp1
  double v16; // fp4
  double v17; // fp6
  double v18; // fp3
  double v19; // fp9
  double v20; // fp10
  double v21; // fp8
  bfx::Vector3 *m_pSpace; // r4
  double v23; // fp0
  double v24; // fp13
  double v25; // fp9
  bfx::Space *v28; // r3
  bfx::Vec3 v30; // [sp+50h] [-90h] BYREF
  bfx::Vec3 v31; // [sp+60h] [-80h] BYREF
  float v32[4]; // [sp+70h] [-70h] BYREF
  bfx::Vec3 v33; // [sp+80h] [-60h] BYREF
  char v34; // [sp+90h] [-50h] BYREF

  m_state = commonState->m_orienter.m_state;
  if ( m_state != FACE_IN_DIR && m_state != FACE_TARGET )
    return 0;
  RotVel = bfx::Orienter::GetRotVel(this: (bfx::Orienter *)&v31, result: (bfx::Vec3 *)&commonState->m_orienter);
  v10 = (float)(RotVel->m_z * (float)57.295776);
  v11 = (float)(RotVel->m_y * (float)57.295776);
  v12 = __fsqrts((float)((float)(curVel->m_z * curVel->m_z)
                       + (float)((float)(curVel->m_x * curVel->m_x) + (float)(curVel->m_y * curVel->m_y))));
  v13 = __fsqrts((float)((float)((float)v11 * (float)v11)
                       + (float)((float)((float)v10 * (float)v10)
                               + (float)((float)(RotVel->m_x * (float)57.295776)
                                       * (float)(RotVel->m_x * (float)57.295776)))));
  if ( v12 != 0.0 && v12 >= (float)(commonState->m_pTune->m_speed * (float)0.0099999998) )
    return 0;
  if ( v13 < (float)(commonState->m_pTune->m_turnInPlace.m_speed * (float)0.050000001) )
    return 0;
  if ( pDataOut != nullptr )
  {
    this->GetPos(this: (bfx::MotionBase *)&v30, result: (bfx::Vec3 *)this);
    v31 = bfx::ZERO_VEC;
    bfx::Orienter::GetDesiredFacingVec(
      this: (bfx::Orienter *)v32,
      result: (bfx::Vec3 *)&commonState->m_orienter,
      pos: &v30,
      vel: curVel,
      nextCornerG: &v31);
    v14 = bfx::Orienter::CalcHeadingError(this: &commonState->m_orienter, pos: &v30, vel: curVel, nextCornerG: &v31);
    Scale = bfx::GetScale();
    v16 = (float)(v32[2] * (float)Scale);
    v17 = (float)(v32[1] * (float)Scale);
    v18 = (float)(v32[0] * (float)Scale);
    pDataOut->m_degreesToTarget = (float)v14 * (float)-57.295776;
    v19 = (float)(v30.m_z + (float)((float)v16 * (float)10.0));
    v20 = (float)(v30.m_y + (float)((float)v17 * (float)10.0));
    v21 = (float)((float)((float)v18 * (float)10.0) + v30.m_x);
    pDataOut->m_turnTime = __fabs((float)((float)v14
                                        / (float)(commonState->m_pTune->m_turnInPlace.m_speed * (float)0.017453292)));
    m_pSpace = (bfx::Vector3 *)commonState->m_pSpace;
    v23 = (float)((float)v20 - commonState->m_surfer.m_pos.m_y);
    v24 = (float)((float)v19 - commonState->m_surfer.m_pos.m_z);
    v25 = (float)((float)v21 - commonState->m_surfer.m_pos.m_x);
    _FP5 = (float)((float)__fsqrts((float)((float)((float)v25 * (float)v25)
                                         + (float)((float)((float)v24 * (float)v24) + (float)((float)v23 * (float)v23))))
                 - (float)1.0842022e-19);
    __asm { fsel      f3, f5, f4, f31 }
    v33.m_y = (float)((float)v20 - commonState->m_surfer.m_pos.m_y) * (float)_FP3;
    v33.m_x = (float)_FP3 * (float)v25;
    v33.m_z = (float)v24 * (float)_FP3;
    v28 = bfx::Space::RotateToWorld(this: (bfx::Space *)&v34, result: m_pSpace, vecIn: &v33);
    *(bfx::HandleTargetBase *)&pDataOut->m_desiredDirectionVec.m_x = v28->bfx::HandleTargetBase;
    LODWORD(pDataOut->m_desiredDirectionVec.m_z) = v28->m_spaceID;
  }
  return 1;
}


// ========================================================================
// ?DrawStripedCylinder@bfx@@YAXPAVSpace@1@ABVMatrix@1@MMABVColor@1@@Z
// EA  : 0x832AE638
// RVA : 0x012AE638
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverutils.cpp
// ========================================================================

void __fastcall bfx::DrawStripedCylinder(
        bfx::Vector3 *pSpace,
        bfx::Vec3 *mat,
        double height,
        double radius,
        const bfx::Color *color,
        int a6,
        const bfx::Color *a7)
{
  double v7; // fp30
  double v8; // fp29
  double v9; // fp28
  double m_x; // fp11
  double m_y; // fp10
  double m_z; // fp9
  __int64 v17; // r11
  long double v18; // fp2
  int v19; // r30
  double v20; // fp25
  long double v21; // fp2
  double v22; // fp24
  long double v23; // fp2
  bfx::Matrix v24; // [sp+58h] [-E8h] BYREF
  bfx::Vec3 v25; // [sp+98h] [-A8h] BYREF
  bfx::Vec3 v26; // [sp+A8h] [-98h] BYREF
  bfx::Vec3 v27; // [sp+B8h] [-88h] BYREF
  bfx::Vec3 v28; // [sp+C8h] [-78h] BYREF

  v7 = (float)(mat[2].m_z * (float)height);
  v8 = (float)(mat[3].m_x * (float)height);
  v9 = (float)(mat[3].m_y * (float)height);
  m_x = mat[4].m_x;
  m_y = mat[4].m_y;
  m_z = mat[4].m_z;
  v25.m_x = radius;
  v25.m_y = 0.0;
  v25.m_z = 0.0;
  v27.m_x = m_x;
  v27.m_y = m_y;
  v27.m_z = m_z;
  v28.m_x = (float)m_x + (float)v7;
  v28.m_y = (float)m_y + (float)v8;
  v28.m_z = (float)m_z + (float)v9;
  bfx::Matrix::operator*(this: (bfx::Matrix *)&v24.m_data[4], result: mat, rhs: &v25);
  v19 = 1;
  do
  {
    LODWORD(v17) = v19;
    v20 = (float)((float)v17 * (float)0.39269909);
    *(double *)&v18 = v20;
    v21 = sin(x: v18);
    v22 = (float)*(double *)&v21;
    *(double *)&v21 = v20;
    v23 = cos(x: v21);
    v26.m_z = 0.0;
    v26.m_y = (float)v22 * (float)radius;
    v26.m_x = (float)*(double *)&v23 * (float)radius;
    bfx::Matrix::operator*(this: &v24, result: mat, rhs: &v26);
    HIDWORD(v17) = v19 & 1;
    *((double *)&v18 + 1) = (float)(v24.m_data[0] + (float)v7);
    v24.m_data[12] = v24.m_data[0] + (float)v7;
    v24.m_data[13] = v24.m_data[1] + (float)v8;
    v24.m_data[14] = v24.m_data[2] + (float)v9;
    v24.m_data[8] = v24.m_data[4] + (float)v7;
    v24.m_data[9] = v24.m_data[5] + (float)v8;
    v24.m_data[10] = v24.m_data[6] + (float)v9;
    if ( (v19 & 1) != 0 )
    {
      bfx::DrawSolidTri(pSpace, v0: &v27, v1: (const bfx::Vec3 *)&v24, v2: (const bfx::Vec3 *)&v24.m_data[4], color: a7);
      bfx::DrawSolidTri(
        pSpace,
        v0: &v28,
        v1: (const bfx::Vec3 *)&v24.m_data[8],
        v2: (const bfx::Vec3 *)&v24.m_data[12],
        color: a7);
      bfx::DrawSolidTri(
        pSpace,
        v0: (const bfx::Vec3 *)&v24.m_data[4],
        v1: (const bfx::Vec3 *)&v24,
        v2: (const bfx::Vec3 *)&v24.m_data[8],
        color: a7);
      bfx::DrawSolidTri(
        pSpace,
        v0: (const bfx::Vec3 *)&v24,
        v1: (const bfx::Vec3 *)&v24.m_data[12],
        v2: (const bfx::Vec3 *)&v24.m_data[8],
        color: a7);
    }
    ++v19;
    v24.m_data[4] = v24.m_data[0];
    v24.m_data[5] = v24.m_data[1];
    v24.m_data[6] = v24.m_data[2];
  }
  while ( v19 <= 16 );
}


// ========================================================================
// ?StrCpyMaxN@bfx@@YAXPADH0@Z
// EA  : 0x832AE810
// RVA : 0x012AE810
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverutils.cpp
// ========================================================================

void __fastcall bfx::StrCpyMaxN(char *pBufIn, int bufLen, char *pBufOut)
{
  char *v3; // r11
  char v4; // r8
  int v5; // r10

  v3 = pBufIn;
  v4 = 0;
  v5 = 0;
  if ( bufLen > 0 )
  {
    while ( 1 )
    {
      v3[pBufOut - pBufIn] = *v3;
      if ( *v3 == 0 )
        break;
      ++v5;
      ++v3;
      if ( v5 >= bufLen )
        goto LABEL_6;
    }
    v4 = 1;
  }
LABEL_6:
  if ( v4 == 0 )
    pBufOut[bufLen - 1] = 0;
}


// ========================================================================
// ?GetStateDesc@MoverImpl@bfx@@QBAXPADH@Z
// EA  : 0x832AE870
// RVA : 0x012AE870
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverutils.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::GetStateDesc(bfx::MoverImpl *this, char *pBuf, int bufLen)
{
  int v4; // r9
  char *v6; // r11
  const char *v7; // r10
  int v8; // r9
  char *v9; // r11
  int v10; // r9
  const char *v11; // r3
  char *v12; // r11
  int v13; // r10
  char *v14; // r11
  int v15; // r10
  char v16[1032]; // [sp+50h] [-420h] BYREF

  v4 = *((_BYTE *)this + 872) & 0x40;
  v16[0] = 0;
  if ( v4 != 0 )
  {
    v6 = v16;
    v7 = "Freeze ";
    do
      v8 = (unsigned __int8)*v6++;
    while ( v8 != 0 );
    v9 = v6 - 1;
    do
    {
      v10 = *(unsigned __int8 *)v7++;
      *v9++ = v10;
    }
    while ( v10 != 0 );
  }
  else
  {
    v11 = this->m_behavior.m_pCurMotion->GetName(this: this->m_behavior.m_pCurMotion);
    v12 = v16;
    do
      v13 = (unsigned __int8)*v12++;
    while ( v13 != 0 );
    v14 = v12 - 1;
    do
    {
      v15 = *(unsigned __int8 *)v11++;
      *v14++ = v15;
    }
    while ( v15 != 0 );
  }
  bfx::StrCpyMaxN(pBufIn: v16, bufLen, pBufOut: pBuf);
}


// ========================================================================
// ?ComputeFinalJumpPosition@bfx@@YA?AVVec3@1@PAVHalfLink@1@ABV21@_N@Z
// EA  : 0x832AE950
// RVA : 0x012AE950
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverutils.cpp
// ========================================================================

bfx::Vec3 *__fastcall bfx::ComputeFinalJumpPosition(
        bfx::Vec3 *result,
        bfx::HalfLink *pLink,
        const bfx::Vec3 *jumperStartPos,
        bool allowPileupAtLinkExit)
{
  double v8; // fp31
  double v9; // fp30
  double v10; // fp29
  double m_y; // fp13
  bfx::Vec3 *v12; // r3
  double m_z; // fp12
  double v14; // fp11
  bfx::Vec3 v15; // [sp+50h] [-60h] BYREF
  bfx::Vec3 v16; // [sp+60h] [-50h] BYREF

  bfx::GetClosestPtOnLineSeg(result: &v16, seg: &pLink->m_startSeg, pos: jumperStartPos);
  v8 = (float)(jumperStartPos->m_x - v16.m_x);
  v9 = (float)(jumperStartPos->m_y - v16.m_y);
  v10 = (float)(jumperStartPos->m_z - v16.m_z);
  bfx::GetLinkOutputPos(result: &v15, pLink, posOnLinkStart: &v16);
  m_y = v15.m_y;
  v12 = result;
  if ( allowPileupAtLinkExit )
  {
    m_z = v15.m_z;
    result->m_x = v15.m_x;
    result->m_y = m_y;
    result->m_z = m_z;
  }
  else
  {
    v14 = v15.m_z;
    result->m_x = (float)v8 + v15.m_x;
    result->m_y = (float)m_y + (float)v9;
    result->m_z = (float)v14 + (float)v10;
  }
  return v12;
}


// ========================================================================
// ?GenerateRandomColor@bfx@@YA?AVColor@1@I@Z
// EA  : 0x832AEA28
// RVA : 0x012AEA28
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverutils.cpp
// ========================================================================

bfx::Color *__fastcall bfx::GenerateRandomColor(bfx::Color *result, char seedNum)
{
  double v2; // fp0
  double v3; // fp11
  double v4; // fp13

  if ( (seedNum & 8) != 0 )
    v2 = 0.5;
  else
    v2 = 1.0;
  if ( (seedNum & 1) != 0 )
    v3 = v2;
  else
    v3 = 0.0;
  if ( (seedNum & 2) != 0 )
    v4 = v2;
  else
    v4 = 0.0;
  if ( (seedNum & 4) == 0 )
    v2 = 0.0;
  result->m_r = v3;
  result->m_g = v4;
  result->m_b = v2;
  result->m_a = 1.0;
  return result;
}


// ========================================================================
// ?ApplyLimits_MoverTune@bfx@@YAXAAUMoverTune@1@@Z
// EA  : 0x832AEAA8
// RVA : 0x012AEAA8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverutils.cpp
// ========================================================================

void __fastcall bfx::ApplyLimits_MoverTune(bfx::MoverTune *tune, int a2, int a3, int a4, __int64 a5)
{
  bfx::RadiusData *v6; // r3
  __int64 v7; // r10
  double m_bulk; // fp1
  __int64 v9; // r8
  int v10; // r6
  int v11; // r5
  __int64 v12; // r10
  __int64 v13; // r8
  int v14; // r6
  int v15; // r5
  int v16; // r4
  double v17; // fp31
  double v18; // fp30
  __int64 v19; // r10
  __int64 v20; // r8
  const char *v21; // r3
  __int64 v22; // r10
  __int64 v23; // r8
  int v24; // r5
  int v25; // r4
  __int64 v26; // r10
  __int64 v27; // r8
  int v28; // r5
  int v29; // r4
  const char *v30; // r3
  __int64 v31; // r10
  __int64 v32; // r8
  int v33; // r5
  int v34; // r4
  const char *v35; // r3
  __int64 v36; // r8
  __int64 v37; // r10
  int v38; // r5
  int v39; // r4
  const char *v40; // r3
  __int64 v41; // r10
  __int64 v42; // r8
  __int64 v43; // r10
  __int64 v44; // r8
  int v45; // r5
  int v46; // r4
  const char *v47; // r3
  __int64 v48; // r10
  __int64 v49; // r8
  int v50; // r5
  int v51; // r4
  const char *v52; // r3
  __int64 v53; // r10
  int v54; // r7
  int v55; // r6
  int v56; // r4
  const char *v57; // r3
  double started; // fp1
  __int64 v59; // r10
  int v60; // r8
  int v61; // r6
  int v62; // r4
  const char *v63; // r3
  double v64; // fp1
  __int64 v65; // r10
  int v66; // r8
  int v67; // r7
  int v68; // r4
  const char *v69; // r3
  __int64 v70; // r8
  int v71; // r6
  int v72; // r5
  int v73; // r4
  __int64 v74; // r10
  __int64 v75; // r8
  int v76; // r4
  const char *v77; // r3
  __int64 v78; // r10
  __int64 v79; // r8
  int v80; // r5
  int v81; // r4
  const char *v82; // r3
  double m_accelAngle; // fp1
  __int64 v84; // r10
  __int64 v85; // r8
  int v86; // r5
  int v87; // r4
  const char *v88; // r3
  double Scale; // fp1
  __int64 v90; // r10
  __int64 v91; // r8
  int v92; // r5
  int v93; // r4
  const char *v94; // r3
  bfx::RadiusData v95[5]; // [sp+50h] [-60h] BYREF

  bfx::ApplyLimits_SurfaceOrientTune(tune: &tune->m_surfaceOrientTune, a2, a3, a4, a5);
  v6 = bfx::ApplyLimits_RadiusDat(result: v95, radiusData: &tune->m_radiusData);
  LODWORD(v7) = LODWORD(v6->m_radius);
  m_bulk = tune->m_bulk;
  tune->m_radiusData.m_radius = v6->m_radius;
  *(float *)&v7 = v6->m_outerCushion;
  tune->m_radiusData.m_outerCushion = *(float *)&v7;
  LODWORD(v9) = LODWORD(v6->m_innerCushion);
  LODWORD(tune->m_radiusData.m_innerCushion) = v9;
  tune->m_bulk = bfx::ApplyLimits_Bulk(
                   bulk: m_bulk,
                   pNameOfVariable: (const char *)v6,
                   a3: (int)"MoverTune::bulk",
                   a4: v11,
                   a5: v10,
                   a6: v9,
                   a7: v7);
  tune->m_repulsorType = bfx::ApplyLimits_RepulsorType(
                           type: tune->m_repulsorType,
                           a2: v16,
                           a3: v15,
                           a4: v14,
                           a5: v13,
                           a6: v12);
  v17 = (float)(bfx::GetScale() * (float)0.001);
  v18 = (float)(bfx::GetScale() * (float)1000.0);
  tune->m_pathAcc = bfx::LimitWarn(
                      val: tune->m_pathAcc,
                      min: v17,
                      max: v18,
                      name: v21,
                      a5: (int)&dword_82420000,
                      a6: (int)&unk_82150000,
                      a7: (unsigned int)"MoverTune::m_pathAcc",
                      a8: v20,
                      a9: v19);
  tune->m_cruiseAcc = bfx::LimitWarn(
                        val: tune->m_cruiseAcc,
                        min: v17,
                        max: v18,
                        name: (const char *)&dword_82420000,
                        a5: v25,
                        a6: v24,
                        a7: (unsigned int)"MoverTune::m_cruiseAcc",
                        a8: v23,
                        a9: v22);
  tune->m_startStopAcc = bfx::LimitWarn(
                           val: tune->m_startStopAcc,
                           min: v17,
                           max: v18,
                           name: v30,
                           a5: v29,
                           a6: v28,
                           a7: (unsigned int)"MoverTune::m_startStopAcc",
                           a8: v27,
                           a9: v26);
  LODWORD(v31) = 0x82000000;
  HIDWORD(v31) = &dword_82420000;
  tune->m_flockAcc = bfx::LimitWarn(
                       val: tune->m_flockAcc,
                       min: 0.0,
                       max: v18,
                       name: v35,
                       a5: v34,
                       a6: v33,
                       a7: (unsigned int)"MoverTune::m_flockAcc",
                       a8: v32,
                       a9: v31);
  LODWORD(v36) = 0x82000000;
  HIDWORD(v36) = byte_821B0000;
  tune->m_cautionTune.m_speedX = bfx::LimitWarn(
                                   val: tune->m_cautionTune.m_speedX,
                                   min: 0.0099999998,
                                   max: 1.0,
                                   name: v40,
                                   a5: v39,
                                   a6: v38,
                                   a7: (unsigned int)"MoverTune::m_cautionSpeedX",
                                   a8: v36,
                                   a9: v37);
  tune->m_cautionTune.m_tightTurnDegrees = bfx::LimitWarn(
                                             val: tune->m_cautionTune.m_tightTurnDegrees,
                                             min: 5.0,
                                             max: 180.0,
                                             name: (const char *)&dword_82420000,
                                             a5: (int)&unk_82150000,
                                             a6: (int)&unk_821D0000,
                                             a7: (unsigned int)"MoverTune::m_tightTurnDegrees",
                                             a8: v42,
                                             a9: v41);
  LODWORD(v43) = &dword_82420000;
  tune->m_pathSharingPenalty = bfx::LimitWarn(
                                 val: tune->m_pathSharingPenalty,
                                 min: 0.0,
                                 max: 3.4028235e38,
                                 name: v47,
                                 a5: v46,
                                 a6: v45,
                                 a7: (unsigned int)"MoverTune.m_pathSharingPenalty",
                                 a8: v44,
                                 a9: v43);
  HIDWORD(v48) = &dword_82420000;
  tune->m_maxPathSharingPenalty = bfx::LimitWarn(
                                    val: tune->m_maxPathSharingPenalty,
                                    min: 0.0,
                                    max: 3.4028235e38,
                                    name: v52,
                                    a5: v51,
                                    a6: v50,
                                    a7: (unsigned int)"MoverTune.m_maxPathSharingPenalty",
                                    a8: v49,
                                    a9: v48);
  started = bfx::LimitWarnStartStopMuchLessThanOtherAcc(
              startStopAcc: tune->m_startStopAcc,
              otherAcc: tune->m_pathAcc,
              otherAccName: v57,
              a4: v56,
              a5: (int)"pathAcc",
              a6: v55,
              a7: v54,
              a8: (int)&dword_82420000,
              a9: v53);
  tune->m_startStopAcc = started;
  v64 = bfx::LimitWarnStartStopMuchLessThanOtherAcc(
          startStopAcc: started,
          otherAcc: tune->m_cruiseAcc,
          otherAccName: v63,
          a4: v62,
          a5: (int)"cruiseAcc",
          a6: v61,
          a7: (int)&dword_82420000,
          a8: v60,
          a9: v59);
  tune->m_startStopAcc = v64;
  tune->m_startStopAcc = bfx::LimitWarnStartStopMuchLessThanOtherAcc(
                           startStopAcc: v64,
                           otherAcc: tune->m_flockAcc,
                           otherAccName: v69,
                           a4: v68,
                           a5: (int)"flockAcc",
                           a6: (int)&dword_82420000,
                           a7: v67,
                           a8: v66,
                           a9: v65);
  bfx::ApplyLimits_JumperTune(tune: &tune->m_jumperTune, a2: v73, a3: v72, a4: v71, a5: v70);
  tune->m_proberTune.m_probeInterval = bfx::LimitWarn(
                                         val: tune->m_proberTune.m_probeInterval,
                                         min: 0.0099999998,
                                         max: 1.0,
                                         name: v77,
                                         a5: v76,
                                         a6: (int)&dword_82420000,
                                         a7: (unsigned int)"m_probeInterval",
                                         a8: v75,
                                         a9: v74);
  m_accelAngle = tune->m_turnInPlace.m_accelAngle;
  if ( m_accelAngle != 0.0 )
  {
    LODWORD(v78) = &dword_82420000;
    tune->m_turnInPlace.m_accelAngle = bfx::LimitWarn(
                                         val: m_accelAngle,
                                         min: 15.0,
                                         max: 180.0,
                                         name: v82,
                                         a5: v81,
                                         a6: v80,
                                         a7: (unsigned int)"m_accelAngle",
                                         a8: v79,
                                         a9: v78);
  }
  tune->m_sidestepFraction = bfx::LimitWarn(
                               val: tune->m_sidestepFraction,
                               min: 0.0,
                               max: 1.0,
                               name: v82,
                               a5: v81,
                               a6: v80,
                               a7: (unsigned int)"MoverTune::m_sidestepFraction",
                               a8: v79,
                               a9: v78);
  LODWORD(v84) = &dword_82420000;
  tune->m_backpedalFraction = bfx::LimitWarn(
                                val: tune->m_backpedalFraction,
                                min: 0.0,
                                max: 2.0,
                                name: v88,
                                a5: v87,
                                a6: v86,
                                a7: (unsigned int)"MoverTune::m_backpedalFraction",
                                a8: v85,
                                a9: v84);
  Scale = bfx::GetScale();
  HIDWORD(v90) = &dword_82420000;
  tune->m_goalTune.m_preferredTurningRadius = bfx::LimitWarn(
                                                val: tune->m_goalTune.m_preferredTurningRadius,
                                                min: 0.0,
                                                max: (float)((float)Scale * (float)1000.0),
                                                name: v94,
                                                a5: v93,
                                                a6: v92,
                                                a7: (unsigned int)"GoalTune::m_preferredTurningRadius",
                                                a8: v91,
                                                a9: v90);
  if ( bfx::g_disableClientMotion )
    tune->m_clientMotion = false;
}


// ========================================================================
// ?SimulateProber@MotionState@bfx@@QAAXM@Z
// EA  : 0x832AED50
// RVA : 0x012AED50
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverutils.cpp
// ========================================================================

void __fastcall bfx::MotionState::SimulateProber(bfx::MotionState *this, double simTime)
{
  unsigned int m_planLayer; // r11
  bfx::NavLayer *v5; // r30
  const bfx::Vec3 *LocalUpAxis; // r3
  char v7; // [sp+50h] [-30h] BYREF

  if ( this->m_pProber != nullptr )
  {
    m_planLayer = this->m_pTune->m_planLayer;
    if ( m_planLayer >= 0x20 )
      v5 = nullptr;
    else
      v5 = *(bfx::NavLayer **)(*((_DWORD *)this->m_pSpace->m_components.m_data + 1) + 4 * (m_planLayer + 2));
    LocalUpAxis = bfx::Orienter::GetLocalUpAxis(this: (bfx::Orienter *)&v7, result: (bfx::Vec3 *)&this->m_orienter);
    bfx::Prober::Simulate(
      this: this->m_pProber,
      pNavLayer: v5,
      surferPos: &this->m_surfer.m_pos,
      localUpAxis: LocalUpAxis,
      simTime);
  }
}


// ========================================================================
// ?GetMoverSpaceComponent@bfx@@YAPAVMoverSpaceComponent@1@PAVSpace@1@@Z
// EA  : 0x832AEDF0
// RVA : 0x012AEDF0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverutils.cpp
// ========================================================================

bfx::MoverSpaceComponent *__fastcall bfx::GetMoverSpaceComponent(bfx::Space *pSpace)
{
  return *((bfx::MoverSpaceComponent **)pSpace->m_components.m_data + 4);
}


// ========================================================================
// ?DrawSpokes@bfx@@YAXPAVSpace@1@ABVMatrix@1@MH_NABVColor@1@@Z
// EA  : 0x832AEE00
// RVA : 0x012AEE00
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverutils.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall bfx::DrawSpokes(
        bfx::Vector3 *pSpace,
        bfx::Vec3 *mat,
        double radius,
        int numSpokes,
        int solidSpokes,
        const bfx::Color *color,
        const bfx::Color *a7)
{
  double m_y; // fp13
  double m_z; // fp12
  int v14; // r30
  __int64 v15; // r11
  int v16; // r25
  double v17; // fp28
  double v18; // fp30
  long double v19; // fp2
  long double v20; // fp2
  double v21; // fp25
  long double v22; // fp2
  long double v23; // fp2
  double v24; // fp30
  long double v25; // fp2
  double v26; // fp26
  long double v27; // fp2
  bfx::Vec3 v28; // [sp+58h] [-E8h] BYREF
  bfx::Matrix v29; // [sp+68h] [-D8h] BYREF
  bfx::Vec3 v30; // [sp+B0h] [-90h] BYREF
  float v31; // [sp+BCh] [-84h]
  float v32; // [sp+C0h] [-80h]
  float v33; // [sp+C4h] [-7Ch]

  m_y = mat[4].m_y;
  m_z = mat[4].m_z;
  v28.m_x = mat[4].m_x;
  v28.m_y = m_y;
  v28.m_z = m_z;
  v14 = 0;
  if ( solidSpokes > 0 )
  {
    HIDWORD(v15) = 0x82000000;
    v16 = (unsigned __int8)color;
    v17 = (float)__SPAIR64__(0x82000000, solidSpokes);
    do
    {
      LODWORD(v15) = v14;
      v18 = (float)((float)((float)v15 * 6.2831855) / (float)v17);
      *(double *)&v19 = v18;
      v20 = sin(x: v19);
      v21 = (float)*(double *)&v20;
      *(double *)&v20 = v18;
      v22 = cos(x: v20);
      v29.m_data[6] = 0.0;
      v29.m_data[5] = (float)v21 * (float)radius;
      v29.m_data[4] = (float)*(double *)&v22 * (float)radius;
      bfx::Matrix::operator*(this: &v29, result: mat, rhs: (const bfx::Vec3 *)&v29.m_data[4]);
      if ( v16 != 0 )
      {
        v24 = (float)((float)((float)(6.2831855 / (float)v17) * (float)0.33000001) + (float)v18);
        *(double *)&v23 = v24;
        v25 = sin(x: v23);
        v26 = (float)*(double *)&v25;
        *(double *)&v25 = v24;
        v27 = cos(x: v25);
        v29.m_data[10] = 0.0;
        v29.m_data[9] = (float)v26 * (float)radius;
        v29.m_data[8] = (float)*(double *)&v27 * (float)radius;
        bfx::Matrix::operator*(
          this: (bfx::Matrix *)&v29.m_data[12],
          result: mat,
          rhs: (const bfx::Vec3 *)&v29.m_data[8]);
        bfx::DrawSolidTri(
          pSpace,
          v0: &v28,
          v1: (const bfx::Vec3 *)&v29,
          v2: (const bfx::Vec3 *)&v29.m_data[12],
          color: a7);
        bfx::DrawSolidTri(
          pSpace,
          v0: &v28,
          v1: (const bfx::Vec3 *)&v29.m_data[12],
          v2: (const bfx::Vec3 *)&v29,
          color: a7);
      }
      else
      {
        v30.m_x = v28.m_x;
        v30.m_y = v28.m_y;
        v30.m_z = v28.m_z;
        v31 = v29.m_data[0];
        v32 = v29.m_data[1];
        v33 = v29.m_data[2];
        bfx::DrawLineList((const bfx::Space *)pSpace, pVerts: &v30, numVerts: 2, color: a7);
      }
      ++v14;
    }
    while ( v14 < solidSpokes );
  }
}


// ========================================================================
// ?Draw@MoverImpl@bfx@@QBAXABVDrawCullData@2@@Z
// EA  : 0x832AF020
// RVA : 0x012AF020
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverutils.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::Draw(bfx::MoverImpl *this, const bfx::DrawCullData *drawCull)
{
  bfx::ComponentManager *m_pComponentManager; // r9
  bfx::InstanceComponent_vtbl *v5; // r28
  bfx::InstanceComponent_vtbl *v6; // r19
  char IsSphereCulled; // r3
  char v8; // r18
  bfx::Color *p_m_overrideColor; // r29
  BOOL m_selected; // r9
  const bfx::MoverTune *m_pTune; // r10
  unsigned int m_planLayer; // r11
  int v13; // r11
  double m_radius; // fp29
  double v15; // fp30
  const bfx::MoverTune *v16; // r11
  double Scale; // fp1
  int v20; // r8
  int v21; // r6
  const bfx::Color *v22; // r5
  const bfx::MoverTune *v23; // r9
  long double v24; // fp2
  int v25; // r8
  int v26; // r6
  const bfx::Color *v27; // r5
  const bfx::MoverTune *v28; // r9
  long double v29; // fp2
  const bfx::Color *v30; // r5
  const bfx::MoverTune *v31; // r6
  bfx::Matrix *v32; // r4
  double v33; // fp1
  double v34; // fp2
  int v35; // r6
  const bfx::Color *v36; // r5
  const bfx::MoverTune *v37; // r9
  bfx::Vector3 *m_pSpace; // r3
  long double v39; // fp2
  long double v40; // fp2
  bool IsBlockedByRepulsor; // r3
  const bfx::MoverTune *v42; // r11
  int v43; // r6
  const bfx::Color *v44; // r5
  bfx::Space *v45; // r3
  const bfx::MoverTune *v46; // r11
  double v47; // fp5
  double v48; // fp4
  double v49; // fp3
  bfx::Space *v50; // r3
  int v51; // r6
  const bfx::Color *v52; // r5
  const bfx::MoverTune *v53; // r9
  long double v54; // fp2
  long double v55; // fp2
  double v56; // fp13
  double v57; // fp11
  double m_x; // fp10
  double m_y; // fp4
  double m_z; // fp5
  double v63; // fp29
  double v64; // fp27
  double v65; // fp23
  double v66; // fp1
  bfx::Vector3 *v67; // r3
  const bfx::MoverTune *v68; // r9
  long double v69; // fp2
  double v70; // fp13
  const bfx::MoverTune *v71; // r10
  bfx::Space *v72; // r3
  const bfx::Color *v73; // r6
  double v74; // fp27
  long double v75; // fp2
  double v76; // fp23
  long double v77; // fp2
  bfx::Matrix *v78; // r27
  bfx::Matrix *v79; // r26
  bfx::Matrix *v80; // r3
  bfx::Matrix *v81; // r27
  bfx::Matrix *v82; // r26
  bfx::Matrix *v83; // r3
  bfx::RepulsorImpl *m_pRepulsor; // r11
  float v85; // r9
  float v86; // r10
  double v87; // fp30
  bfx::Vec3 *UpVec; // r3
  double v89; // fp29
  double v90; // fp27
  double v91; // fp30
  __int64 v92; // r8
  __int64 v93; // r6
  __int64 v94; // r10
  char *m_data; // r29
  double v96; // fp30
  bfx::Vec3 *v97; // r3
  double v98; // fp30
  double v99; // fp29
  double v100; // fp27
  __int64 v101; // r8
  __int64 v102; // r10
  bool IsTurningInPlace; // r29
  __int64 v104; // r6
  __int64 v105; // r10
  __int64 v106; // r8
  double v107; // fp30
  bfx::Vec3 *v108; // r3
  double v109; // fp29
  double v110; // fp27
  double v111; // fp30
  __int64 v112; // r8
  __int64 v113; // r6
  __int64 v114; // r10
  bfx::HandleProxy *m_pProxy; // r11
  bfx::Handle<bfx::MoverImpl> *p_m_targetMover; // r27
  bool v117; // r11
  bfx::HandleTargetBase *m_pTarget; // r10
  bool v119; // r11
  bfx::HandleTargetBase *v120; // r10
  bfx::MoverImpl::State m_state; // r11
  double v122; // fp1
  const bfx::Color *v123; // r5
  double v124; // fp1
  const bfx::Color *v125; // r5
  double v126; // fp30
  double v127; // fp29
  double v128; // fp27
  double v129; // fp1
  double v130; // fp10
  double v131; // fp9
  double v132; // fp1
  double v133; // fp9
  double v134; // fp7
  bfx::Vector3 *v135; // r3
  bfx::AreaProxy *v136; // r11
  const bfx::Area *m_pArea; // r4
  const bfx::Color *v140; // r5
  int v141; // r5
  const bfx::Color *v142; // r5
  double m_desiredStopDist; // fp1
  bfx::InstanceComponent_vtbl *v144; // r24
  double v145; // fp30
  bfx::Vec3 *v146; // r3
  double v147; // fp30
  double v148; // fp29
  double v149; // fp27
  const bfx::MoverTune *v150; // r6
  __int64 v151; // r8
  __int64 v152; // r6
  __int64 v153; // r10
  bfx::HandleProxy *v155; // r29
  const bfx::FollowerLeaderDatabase::DatabaseRecord *Follower; // r29
  double v157; // fp30
  bfx::Vec3 *v158; // r3
  double v159; // fp29
  double v160; // fp27
  double v161; // fp30
  __int64 v162; // r10
  __int64 v163; // r8
  __int64 v164; // r6
  bfx::FollowerLeaderDatabase::FollowerStates v165; // r11
  bfx::Vector3 *v166; // r3
  bfx::AreaProxy *v167; // r11
  const bfx::Area *v168; // r4
  bfx::MotionBase *m_pCurMotion; // r4
  bfx::MotionBase *v172; // r11
  bfx::Vec3 *v173; // r3
  double v174; // fp31
  bfx::Vec3 *v175; // r3
  double v176; // fp2
  double v177; // fp12
  double v178; // fp11
  double v179; // fp10
  double v180; // fp8
  double v181; // fp31
  double v182; // fp30
  __int64 v183; // r8
  __int64 v184; // r10
  bfx::Trail *m_pTrail; // r3
  int m_size; // r11
  int v187; // r27
  int v188; // r28
  bfx::GoalReachedData *v189; // r29
  double v190; // fp1
  double v191; // fp31
  const bfx::Color *v192; // r5
  float v197; // r11
  float v198; // r10
  float v199; // r9
  bfx::Space *v200; // r3
  __int64 v201; // r10
  __int64 v202; // r8
  bfx::Space *v203; // r3
  bfx::GoalReachedData *v204; // r11
  const bfx::Color *v205; // r5
  int v206; // r28
  int v207; // r29
  bfx::Space *v208; // r3
  bfx::GoalReachedData *v209; // r11
  bfx::Space *v210; // r3
  double v211; // fp31
  bfx::Vec3 *v212; // r3
  double v213; // fp30
  double v214; // fp29
  double v215; // fp31
  __int64 v216; // r8
  __int64 v217; // r6
  __int64 v218; // r10
  double v219; // fp1
  double v220; // fp9
  double v221; // fp7
  double v222; // fp3
  double v223; // fp0
  bfx::Vector3 *v224; // r3
  double v225; // fp1
  const bfx::Color *v226; // r5
  double v227; // fp1
  bfx::Space *v228; // r3
  bool v229; // r29
  bool v230; // r11
  char *v231; // r4
  double v232; // fp12
  double v233; // fp13
  double v234; // fp0
  BOOL v235; // r23
  float *i; // r29
  bfx::Space *v237; // r3
  float *v238; // r28
  __int64 v239; // r10
  __int64 v240; // r8
  __int64 v241; // r6
  float v242; // r11
  int v243; // [sp+8h] [-B68h]
  int v244; // [sp+Ch] [-B64h]
  int v245; // [sp+10h] [-B60h]
  int v246; // [sp+14h] [-B5Ch]
  int v247; // [sp+18h] [-B58h]
  int v248; // [sp+1Ch] [-B54h]
  int v249; // [sp+20h] [-B50h]
  int v250; // [sp+24h] [-B4Ch]
  int v251; // [sp+28h] [-B48h]
  int v252; // [sp+2Ch] [-B44h]
  int v253; // [sp+30h] [-B40h]
  int v254; // [sp+34h] [-B3Ch]
  int v255; // [sp+38h] [-B38h]
  int v256; // [sp+3Ch] [-B34h]
  int v257; // [sp+40h] [-B30h]
  int v258; // [sp+44h] [-B2Ch]
  int v259; // [sp+48h] [-B28h]
  int v260; // [sp+4Ch] [-B24h]
  int v261; // [sp+50h] [-B20h]
  bfx::Vec3 v262; // [sp+68h] [-B08h] BYREF
  bfx::Vec3 v263[2]; // [sp+78h] [-AF8h] BYREF
  bfx::Matrix v264; // [sp+90h] [-AE0h] BYREF
  bfx::Matrix v265; // [sp+D0h] [-AA0h] BYREF
  bfx::Vec3 v266; // [sp+110h] [-A60h] BYREF
  bfx::Vec3 v267; // [sp+120h] [-A50h] BYREF
  bfx::Vec3 v268; // [sp+130h] [-A40h] BYREF
  bfx::Vec3 v269; // [sp+140h] [-A30h] BYREF
  bfx::Vec3 v270; // [sp+150h] [-A20h] BYREF
  bfx::Vec3 v271; // [sp+160h] [-A10h] BYREF
  bfx::Vec3 v272; // [sp+170h] [-A00h] BYREF
  bfx::Vec3 v273; // [sp+180h] [-9F0h] BYREF
  bfx::Vec3 v274; // [sp+190h] [-9E0h] BYREF
  bfx::Vec3 v275; // [sp+1A0h] [-9D0h] BYREF
  float v276[4]; // [sp+1B0h] [-9C0h] BYREF
  bfx::Vec3 v277; // [sp+1C0h] [-9B0h] BYREF
  bfx::Vec3 v278; // [sp+1D0h] [-9A0h] BYREF
  bfx::Vec3 v279; // [sp+1E0h] [-990h] BYREF
  bfx::Vec3 v280; // [sp+1F0h] [-980h] BYREF
  bfx::Vec3 v281; // [sp+200h] [-970h] BYREF
  float v282[4]; // [sp+210h] [-960h] BYREF
  bfx::Vec3 v283; // [sp+220h] [-950h] BYREF
  float v284[4]; // [sp+230h] [-940h] BYREF
  bfx::Vec3 v285; // [sp+240h] [-930h] BYREF
  bfx::Vec3 v286; // [sp+250h] [-920h] BYREF
  bfx::Vec3 v287; // [sp+260h] [-910h] BYREF
  bfx::Vec3 v288; // [sp+270h] [-900h] BYREF
  bfx::Vec3 v289; // [sp+280h] [-8F0h] BYREF
  bfx::Vec3 v290; // [sp+290h] [-8E0h] BYREF
  float v291[4]; // [sp+2A0h] [-8D0h] BYREF
  bfx::Vec3 v292; // [sp+2B0h] [-8C0h] BYREF
  bfx::Vec3 v293; // [sp+2C0h] [-8B0h] BYREF
  bfx::Vec3 v294; // [sp+2D0h] [-8A0h] BYREF
  float v295[4]; // [sp+2E0h] [-890h] BYREF
  bfx::Vec3 v296; // [sp+2F0h] [-880h] BYREF
  float v297[4]; // [sp+300h] [-870h] BYREF
  bfx::Vec3 v298; // [sp+310h] [-860h] BYREF
  float v299[4]; // [sp+320h] [-850h] BYREF
  bfx::Vec3 v300; // [sp+330h] [-840h] BYREF
  bfx::Sphere v301; // [sp+340h] [-830h] BYREF
  bfx::Sphere v302; // [sp+350h] [-820h] BYREF
  bfx::Vec3 m_pos; // [sp+360h] [-810h] BYREF
  float v304; // [sp+36Ch] [-804h]
  float v305; // [sp+370h] [-800h]
  float v306; // [sp+374h] [-7FCh]
  bfx::Vec3 v307; // [sp+380h] [-7F0h] BYREF
  float v308; // [sp+38Ch] [-7E4h]
  float v309; // [sp+390h] [-7E0h]
  float v310; // [sp+394h] [-7DCh]
  bfx::Vec3 v311; // [sp+3A0h] [-7D0h] BYREF
  float v312; // [sp+3ACh] [-7C4h]
  float v313; // [sp+3B0h] [-7C0h]
  float v314; // [sp+3B4h] [-7BCh]
  bfx::Vec3 v315; // [sp+3C0h] [-7B0h] BYREF
  float v316; // [sp+3CCh] [-7A4h]
  float v317; // [sp+3D0h] [-7A0h]
  float v318; // [sp+3D4h] [-79Ch]
  bfx::Color v319; // [sp+3E0h] [-790h] BYREF
  bfx::Color v320; // [sp+3F0h] [-780h] BYREF
  bfx::Vec3 v321; // [sp+400h] [-770h] BYREF
  bfx::Vec3 v322; // [sp+410h] [-760h] BYREF
  bfx::Vec3 v323; // [sp+420h] [-750h] BYREF
  bfx::Vec3 v324; // [sp+430h] [-740h] BYREF
  bfx::Vec3 v325; // [sp+440h] [-730h] BYREF
  bfx::Vec3 v326; // [sp+450h] [-720h] BYREF
  bfx::Matrix v327; // [sp+460h] [-710h] BYREF
  bfx::Matrix v328; // [sp+4A0h] [-6D0h] BYREF
  bfx::Matrix v329; // [sp+4E0h] [-690h] BYREF
  bfx::Matrix v330; // [sp+520h] [-650h] BYREF
  bfx::Vec3 v331[4]; // [sp+560h] [-610h] BYREF
  float v332; // [sp+590h] [-5E0h]
  float v333; // [sp+594h] [-5DCh]
  float v334; // [sp+598h] [-5D8h]
  float v335[16]; // [sp+5A0h] [-5D0h] BYREF
  bfx::Matrix v336; // [sp+5E0h] [-590h] BYREF
  bfx::Matrix v337; // [sp+620h] [-550h] BYREF
  bfx::Matrix v338; // [sp+660h] [-510h] BYREF
  char v339[1104]; // [sp+6A0h] [-4D0h] BYREF

  m_pComponentManager = bfx::g_pCurInstance->m_pComponentManager;
  v5 = m_pComponentManager->m_components[3][12].__vftable;
  v6 = m_pComponentManager->m_components[4][8].__vftable;
  ((void (__fastcall *)(bfx::Vec3 *))this->m_behavior.m_pCurMotion->GetPos)(a1: &v326);
  IsSphereCulled = bfx::DrawCullData::IsSphereCulled(
                     this: drawCull,
                     centerPos: &v326,
                     radius: (float)(this->m_pTune->m_radiusData.m_radius * (float)5.0));
  v8 = IsSphereCulled;
  p_m_overrideColor = &ColorWhite_17;
  if ( this->m_overrideColor.m_r != 0.0 || this->m_overrideColor.m_g != 0.0 || this->m_overrideColor.m_b != 0.0 )
    p_m_overrideColor = &this->m_overrideColor;
  if ( HIBYTE(v6->dtr_InstanceComponent) != 0 && IsSphereCulled == 0 )
  {
    this->m_behavior.m_pCurMotion->GetMatrix(this: this->m_behavior.m_pCurMotion, a2: &v264);
    m_selected = this->m_commonState.m_selected;
    v298.m_x = v264.m_data[12];
    v298.m_y = v264.m_data[13];
    v298.m_z = v264.m_data[14];
    if ( m_selected )
      p_m_overrideColor = &ColorYellow_17;
    m_pTune = this->m_pTune;
    m_planLayer = m_pTune->m_planLayer;
    if ( m_planLayer < 0x20
      && (v13 = *(_DWORD *)(4 * (m_planLayer + 2) + *((_DWORD *)this->m_pSpace->m_components.m_data + 1))) != 0 )
    {
      m_radius = m_pTune->m_radiusData.m_radius;
      v15 = (float)(*(float *)(v13 + 16) - m_pTune->m_radiusData.m_radius);
    }
    else
    {
      v16 = this->m_pTune;
      m_radius = v16->m_radiusData.m_radius;
      v15 = (float)(v16->m_radiusData.m_radius * 2.0);
    }
    Scale = bfx::GetScale();
    v290.m_x = 0.0;
    v290.m_y = 0.0;
    v290.m_z = m_radius;
    _FP13 = (float)((float)v15 - (float)((float)Scale * (float)0.2));
    __asm { fsel      f30, f13, f30, f0 }
    bfx::Matrix::PreTrans(this: &v264, offset: &v290);
    if ( this->m_stranded )
    {
      bfx::Matrix::Build(this: &v337, q: &this->m_cachedRot, pos: &v298);
      v23 = this->m_pTune;
      *((double *)&v24 + 1) = v23->m_radiusData.m_radius;
      *(double *)&v24 = _FP30;
      bfx::DrawSolidCylinderParts(
        a1: (bfx::Vector3 *)this->m_pSpace,
        a2: (bfx::Vec3 *)&v337,
        radius: v24,
        color: v27,
        startAngle: 0.0,
        stopAngle: 6.2831855,
        numSegments: v26,
        partsToDraw: &ColorRed_17,
        a9: v25,
        a10: (int)v23,
        a11: 16,
        a12: v243,
        a13: v244,
        a14: v245,
        a15: v246,
        a16: v247,
        a17: v248,
        a18: v249,
        a19: v250,
        a20: v251,
        a21: v252,
        a22: v253,
        a23: v254,
        a24: v255,
        a25: v256,
        a26: v257,
        a27: v258,
        a28: v259,
        a29: v260,
        a30: v261,
        a31: -1);
      goto LABEL_28;
    }
    if ( (*((_BYTE *)this + 872) & 0x40) != 0 )
    {
      v28 = this->m_pTune;
      *((double *)&v29 + 1) = v28->m_radiusData.m_radius;
      *(double *)&v29 = (float)((float)_FP30 * (float)0.5);
      bfx::DrawSolidCylinderParts(
        a1: (bfx::Vector3 *)this->m_pSpace,
        a2: (bfx::Vec3 *)&v264,
        radius: v29,
        color: v22,
        startAngle: 0.0,
        stopAngle: 6.2831855,
        numSegments: v21,
        partsToDraw: p_m_overrideColor,
        a9: v20,
        a10: (int)v28,
        a11: 16,
        a12: v243,
        a13: v244,
        a14: v245,
        a15: v246,
        a16: v247,
        a17: v248,
        a18: v249,
        a19: v250,
        a20: v251,
        a21: v252,
        a22: v253,
        a23: v254,
        a24: v255,
        a25: v256,
        a26: v257,
        a27: v258,
        a28: v259,
        a29: v260,
        a30: v261,
        a31: -1);
      v330 = v264;
      v31 = this->m_pTune;
      v32 = &v330;
      v33 = (float)((float)_FP30 * (float)0.5);
      v330.m_data[14] = (float)((float)((float)_FP30 * (float)0.5) * v264.m_data[10]) + v264.m_data[14];
      v330.m_data[13] = (float)((float)((float)_FP30 * (float)0.5) * v264.m_data[9]) + v264.m_data[13];
      v330.m_data[12] = (float)((float)((float)_FP30 * (float)0.5) * v264.m_data[8]) + v264.m_data[12];
      v34 = v31->m_radiusData.m_radius;
    }
    else
    {
      if ( (*((_BYTE *)this + 872) & 0x20) != 0 )
      {
        bfx::DrawCylinder(
          pSpace: this->m_pSpace,
          mat: (bfx::Vec3 *)&v264,
          height: _FP30,
          radius: this->m_pTune->m_radiusData.m_radius,
          color: v22,
          segments: v21,
          a7: p_m_overrideColor,
          a8: 16);
        v328 = v264;
        v37 = this->m_pTune;
        m_pSpace = (bfx::Vector3 *)this->m_pSpace;
        *(double *)&v39 = (float)((float)_FP30 * (float)0.25);
        v328.m_data[14] = (float)((float)((float)_FP30 * (float)0.5) * v264.m_data[10]) + v264.m_data[14];
        v328.m_data[12] = (float)((float)((float)_FP30 * (float)0.5) * v264.m_data[8]) + v264.m_data[12];
        v328.m_data[13] = (float)((float)((float)_FP30 * (float)0.5) * v264.m_data[9]) + v264.m_data[13];
        *((double *)&v39 + 1) = v37->m_radiusData.m_radius;
        bfx::DrawSolidCylinderParts(
          a1: m_pSpace,
          a2: (bfx::Vec3 *)&v328,
          radius: v39,
          color: v36,
          startAngle: 0.0,
          stopAngle: 6.2831855,
          numSegments: v35,
          partsToDraw: p_m_overrideColor,
          a9: 2,
          a10: (int)v37,
          a11: 16,
          a12: v243,
          a13: v244,
          a14: v245,
          a15: v246,
          a16: v247,
          a17: v248,
          a18: v249,
          a19: v250,
          a20: v251,
          a21: v252,
          a22: v253,
          a23: v254,
          a24: v255,
          a25: v256,
          a26: v257,
          a27: v258,
          a28: v259,
          a29: v260,
          a30: v261,
          a31: 2);
        goto LABEL_28;
      }
      if ( this->m_behavior.m_state == PUPPET )
      {
        *((double *)&v40 + 1) = this->m_pTune->m_radiusData.m_radius;
        *(double *)&v40 = _FP30;
        bfx::DrawSolidCylinderParts(
          a1: (bfx::Vector3 *)this->m_pSpace,
          a2: (bfx::Vec3 *)&v264,
          radius: v40,
          color: v22,
          startAngle: 0.0,
          stopAngle: 6.2831855,
          numSegments: v21,
          partsToDraw: p_m_overrideColor,
          a9: v20,
          a10: -1,
          a11: 16,
          a12: v243,
          a13: v244,
          a14: v245,
          a15: v246,
          a16: v247,
          a17: v248,
          a18: v249,
          a19: v250,
          a20: v251,
          a21: v252,
          a22: v253,
          a23: v254,
          a24: v255,
          a25: v256,
          a26: v257,
          a27: v258,
          a28: v259,
          a29: v260,
          a30: v261,
          a31: -1);
        goto LABEL_28;
      }
      IsBlockedByRepulsor = bfx::MoverImpl::IsBlockedByRepulsor(this);
      v42 = this->m_pTune;
      if ( IsBlockedByRepulsor )
      {
        bfx::DrawStripedCylinder(
          pSpace: (bfx::Vector3 *)this->m_pSpace,
          mat: (bfx::Vec3 *)&v264,
          height: _FP30,
          radius: v42->m_radiusData.m_radius,
          color: v30,
          a6: (int)v31,
          a7: p_m_overrideColor);
        goto LABEL_28;
      }
      if ( v42->m_clientMotion && this->m_behavior.m_state != PUPPET )
      {
        bfx::DrawCylinder(
          pSpace: this->m_pSpace,
          mat: (bfx::Vec3 *)&v264,
          height: _FP30,
          radius: v42->m_radiusData.m_radius,
          color: v30,
          segments: (int)v31,
          a7: p_m_overrideColor,
          a8: 8);
        bfx::DrawCylinderDiagonals(
          pSpace: this->m_pSpace,
          mat: (bfx::Vec3 *)&v264,
          height: _FP30,
          radius: this->m_pTune->m_radiusData.m_radius,
          color: v44,
          segments: v43,
          a7: p_m_overrideColor,
          a8: 8);
        goto LABEL_28;
      }
      v34 = v42->m_radiusData.m_radius;
      v32 = &v264;
      v33 = _FP30;
    }
    bfx::DrawCylinder(
      pSpace: this->m_pSpace,
      mat: (bfx::Vec3 *)v32,
      height: v33,
      radius: v34,
      color: v30,
      segments: (int)v31,
      a7: p_m_overrideColor,
      a8: 16);
LABEL_28:
    v262.m_x = v264.m_data[12];
    v45 = this->m_pSpace;
    v262.m_y = v264.m_data[13];
    v262.m_z = v264.m_data[14];
    v263[0].m_z = v264.m_data[14] - (float)(v264.m_data[10] * (float)m_radius);
    v263[0].m_y = v264.m_data[13] - (float)(v264.m_data[9] * (float)m_radius);
    v263[0].m_x = v264.m_data[12] - (float)(v264.m_data[8] * (float)m_radius);
    bfx::DrawLine(pSpace: v45, v0: &v262, v1: v263, color: p_m_overrideColor);
    v46 = this->m_pTune;
    v47 = (float)(v264.m_data[0] * v46->m_radiusData.m_radius);
    v48 = (float)(v46->m_radiusData.m_radius * v264.m_data[2]);
    v49 = (float)(v46->m_radiusData.m_radius * v264.m_data[1]);
    v50 = this->m_pSpace;
    v263[0].m_z = v264.m_data[14] - (float)(v264.m_data[10] * (float)m_radius);
    v263[0].m_y = v264.m_data[13] - (float)(v264.m_data[9] * (float)m_radius);
    v263[0].m_x = v264.m_data[12] - (float)(v264.m_data[8] * (float)m_radius);
    v262.m_x = v263[0].m_x + (float)((float)v47 * (float)0.5);
    v262.m_z = v263[0].m_z + (float)((float)v48 * (float)0.5);
    v262.m_y = v263[0].m_y + (float)((float)v49 * (float)0.5);
    bfx::DrawLine(pSpace: v50, v0: v263, v1: &v262, color: p_m_overrideColor);
    if ( !this->m_stranded )
    {
      if ( this->m_commonState.m_orientCmd.m_mode < (unsigned int)ORIENT_TARGET )
      {
        v68 = this->m_pTune;
        *(double *)&v69 = _FP30;
        *((double *)&v69 + 1) = v68->m_radiusData.m_radius;
        bfx::DrawSolidCylinderParts(
          a1: (bfx::Vector3 *)this->m_pSpace,
          a2: (bfx::Vec3 *)&v264,
          radius: v69,
          color: v52,
          startAngle: -0.2,
          stopAngle: 0.2,
          numSegments: v51,
          partsToDraw: p_m_overrideColor,
          a9: 3,
          a10: (int)v68,
          a11: 1,
          a12: v243,
          a13: v244,
          a14: v245,
          a15: v246,
          a16: v247,
          a17: v248,
          a18: v249,
          a19: v250,
          a20: v251,
          a21: v252,
          a22: v253,
          a23: v254,
          a24: v255,
          a25: v256,
          a26: v257,
          a27: v258,
          a28: v259,
          a29: v260,
          a30: v261,
          a31: 3);
      }
      else
      {
        v53 = this->m_pTune;
        *(double *)&v54 = _FP30;
        *((double *)&v54 + 1) = v53->m_radiusData.m_radius;
        bfx::DrawSolidCylinderParts(
          a1: (bfx::Vector3 *)this->m_pSpace,
          a2: (bfx::Vec3 *)&v264,
          radius: v54,
          color: v52,
          startAngle: 0.2,
          stopAngle: 6.0831857,
          numSegments: v51,
          partsToDraw: p_m_overrideColor,
          a9: 1,
          a10: (int)v53,
          a11: 16,
          a12: v243,
          a13: v244,
          a14: v245,
          a15: v246,
          a16: v247,
          a17: v248,
          a18: v249,
          a19: v250,
          a20: v251,
          a21: v252,
          a22: v253,
          a23: v254,
          a24: v255,
          a25: v256,
          a26: v257,
          a27: v258,
          a28: v259,
          a29: v260,
          a30: v261,
          a31: 1);
        if ( this->m_commonState.m_orientCmd.m_mode == ORIENT_IN_DIR )
        {
          v329 = v264;
          v56 = (float)((float)(this->m_pTune->m_radiusData.m_radius * (float)0.15000001) + (float)_FP30);
          v292.m_x = 0.0;
          v292.m_y = 0.0;
          v292.m_z = v56;
          bfx::Matrix::PreTrans(this: &v329, offset: &v292);
          v57 = (float)(this->m_commonState.m_orientCmd.m_vec.m_y * this->m_commonState.m_orientCmd.m_vec.m_y);
          m_x = this->m_commonState.m_orientCmd.m_vec.m_x;
          m_y = this->m_commonState.m_orientCmd.m_vec.m_y;
          m_z = this->m_commonState.m_orientCmd.m_vec.m_z;
          v268.m_x = v329.m_data[12];
          v268.m_y = v329.m_data[13];
          v268.m_z = v329.m_data[14];
          _FP0 = (float)((float)__fsqrts((float)((float)((float)m_z * (float)m_z)
                                               + (float)((float)((float)m_x * (float)m_x) + (float)v57)))
                       - (float)1.0842022e-19);
          __asm { fsel      f12, f0, f13, f31 }
          v63 = (float)((float)_FP12 * (float)m_z);
          v64 = (float)((float)_FP12 * (float)m_y);
          v65 = (float)((float)_FP12 * (float)m_x);
          v66 = bfx::GetScale();
          v67 = (bfx::Vector3 *)this->m_pSpace;
          v277.m_z = (float)((float)v63 * (float)v66) + v268.m_z;
          v277.m_y = (float)((float)v64 * (float)v66) + v268.m_y;
          v277.m_x = (float)((float)v65 * (float)v66) + v268.m_x;
          bfx::DrawArrowhead(pSpace: v67, startPos: &v268, endPos: &v277, color: p_m_overrideColor);
        }
      }
      if ( this->m_commonState.m_forceUseClientMotion )
      {
        v327 = v264;
        v70 = (float)(this->m_pTune->m_radiusData.m_radius * (float)0.25);
        v288.m_x = 0.0;
        v288.m_y = 0.0;
        v288.m_z = (float)v70 + (float)_FP30;
        bfx::Matrix::PreTrans(this: &v327, offset: &v288);
        v71 = this->m_pTune;
        v72 = this->m_pSpace;
        v293.m_x = v327.m_data[8];
        v293.m_y = v327.m_data[9];
        v293.m_z = v327.m_data[10];
        v279.m_x = v327.m_data[12];
        v279.m_y = v327.m_data[13];
        v279.m_z = v327.m_data[14];
        bfx::DrawCircle(
          pSpace: v72,
          pos: &v279,
          N: &v293,
          radius: v71->m_radiusData.m_radius,
          color: v73,
          a6: p_m_overrideColor);
      }
      if ( this->m_behavior.m_state == LOCOMOTING )
      {
        v74 = this->m_pTune->m_radiusData.m_radius;
        *(double *)&v55 = 0.4000000059604645;
        v75 = cos(x: v55);
        v76 = (float)*(double *)&v75;
        *(double *)&v75 = 0.4000000059604645;
        v77 = sin(x: v75);
        v273.m_z = 0.0;
        v281.m_z = 0.0;
        v300.m_z = _FP30;
        v270.m_z = _FP30;
        v273.m_x = (float)v76 * (float)v74;
        v281.m_x = v273.m_x;
        v300.m_x = v273.m_x;
        v270.m_x = v273.m_x;
        v273.m_y = (float)*(double *)&v77 * (float)v74;
        v300.m_y = v273.m_y;
        v281.m_y = -v273.m_y;
        v270.m_y = v281.m_y;
        v78 = bfx::Matrix::operator*(this: (bfx::Matrix *)v263, result: (bfx::Vec3 *)&v264, rhs: &v270);
        v79 = bfx::Matrix::operator*(this: (bfx::Matrix *)&v262, result: (bfx::Vec3 *)&v264, rhs: &v300);
        v80 = bfx::Matrix::operator*(this: &v265, result: (bfx::Vec3 *)&v264, rhs: &v273);
        bfx::DrawSolidTri(
          pSpace: (bfx::Vector3 *)this->m_pSpace,
          v0: (const bfx::Vec3 *)v80,
          v1: (const bfx::Vec3 *)v79,
          v2: (const bfx::Vec3 *)v78,
          color: p_m_overrideColor);
        v81 = bfx::Matrix::operator*(this: &v265, result: (bfx::Vec3 *)&v264, rhs: &v281);
        v82 = bfx::Matrix::operator*(this: (bfx::Matrix *)v263, result: (bfx::Vec3 *)&v264, rhs: &v270);
        v83 = bfx::Matrix::operator*(this: (bfx::Matrix *)&v262, result: (bfx::Vec3 *)&v264, rhs: &v273);
        bfx::DrawSolidTri(
          pSpace: (bfx::Vector3 *)this->m_pSpace,
          v0: (const bfx::Vec3 *)v83,
          v1: (const bfx::Vec3 *)v82,
          v2: (const bfx::Vec3 *)v81,
          color: p_m_overrideColor);
      }
    }
  }
  if ( LOBYTE(v5->dtr_InstanceComponent) != 0 && this->m_commonState.m_pRepulsor != nullptr && v8 == 0 )
  {
    this->m_behavior.m_pCurMotion->GetMatrix(this: this->m_behavior.m_pCurMotion, a2: (bfx::Matrix *)v331);
    m_pRepulsor = this->m_commonState.m_pRepulsor;
    if ( m_pRepulsor != nullptr )
    {
      v85 = m_pRepulsor->m_pos.m_x;
      v86 = m_pRepulsor->m_pos.m_z;
      v262.m_y = m_pRepulsor->m_pos.m_y;
      v262.m_x = v85;
      v262.m_z = v86;
      v334 = v86;
      v333 = v262.m_y;
      v332 = v85;
    }
    bfx::DrawRepulsorCircles(
      pSpace: this->m_pSpace,
      mat: v331,
      radiusData: (const bfx::Color *)&m_pRepulsor->m_radiusData);
  }
  if ( bfx::g_drawMoverIds && v8 == 0 )
  {
    v87 = bfx::GetScale();
    UpVec = bfx::GetUpVec(result: (bfx::Vec3 *)&v265);
    v89 = (float)((float)(UpVec->m_z * (float)v87) * (float)0.5);
    v90 = (float)((float)(UpVec->m_y * (float)v87) * (float)0.5);
    v91 = (float)((float)((float)v87 * UpVec->m_x) * (float)0.5);
    ((void (__fastcall *)(float *))this->m_behavior.m_pCurMotion->GetPos)(a1: v295);
    LODWORD(v92) = &unk_82410000;
    v283.m_x = (float)v91 + v295[0];
    v283.m_z = (float)v89 + v295[2];
    v283.m_y = (float)v90 + v295[1];
    HIDWORD(v93) = "\nid %d";
    LODWORD(v93) = this->m_commonState.m_replayID;
    bfx::DrawString(
      pSpace: (bfx::Vector3 *)this->m_pSpace,
      inputPos: &v283,
      fmt: v93,
      a4: v92,
      a5: v94,
      a6: v243,
      a7: v244,
      a8: v245,
      a9: v246,
      a10: v247,
      a11: v248,
      a12: v249,
      a13: v250);
  }
  if ( LOBYTE(v6->dtr_InstanceComponent) != 0 && v8 == 0 )
  {
    m_data = this->m_debugName.m_data;
    v96 = bfx::GetScale();
    v97 = bfx::GetUpVec(result: (bfx::Vec3 *)&v265);
    v99 = (float)((float)(v97->m_z * (float)v96) * (float)0.85000002);
    v100 = (float)((float)(v97->m_y * (float)v96) * (float)0.85000002);
    v98 = (float)((float)((float)v96 * v97->m_x) * (float)0.85000002);
    ((void (__fastcall *)(float *))this->m_behavior.m_pCurMotion->GetPos)(a1: v299);
    HIDWORD(v101) = &off_82230000;
    v285.m_x = (float)v98 + v299[0];
    v285.m_z = (float)v99 + v299[2];
    v285.m_y = (float)v100 + v299[1];
    bfx::DrawString(
      pSpace: (bfx::Vector3 *)this->m_pSpace,
      inputPos: &v285,
      fmt: __SPAIR64__("\n%s", (unsigned int)m_data),
      a4: v101,
      a5: v102,
      a6: v243,
      a7: v244,
      a8: v245,
      a9: v246,
      a10: v247,
      a11: v248,
      a12: v249,
      a13: v250);
  }
  if ( (HIBYTE(v6->Start) != 0 || (this->m_commonState.m_debugFlags & 8) != 0) && v8 == 0 )
  {
    IsTurningInPlace = bfx::MoverImpl::IsTurningInPlace(this, pDataOut: nullptr);
    bfx::MoverImpl::GetStateDesc(this, pBuf: v339, bufLen: 1023);
    ((void (__fastcall *)(bfx::Vec3 *))this->m_behavior.m_pCurMotion->GetPos)(a1: &v325);
    HIDWORD(v104) = v339;
    bfx::DrawString(
      pSpace: (bfx::Vector3 *)this->m_pSpace,
      inputPos: &v325,
      fmt: v104,
      a4: v106,
      a5: v105,
      a6: v243,
      a7: v244,
      a8: v245,
      a9: v246,
      a10: v247,
      a11: v248,
      a12: v249,
      a13: v250);
    if ( IsTurningInPlace )
    {
      v107 = bfx::GetScale();
      v108 = bfx::GetUpVec(result: (bfx::Vec3 *)&v265);
      v109 = (float)((float)(v108->m_z * (float)v107) * (float)0.5);
      v110 = (float)((float)(v108->m_y * (float)v107) * (float)0.5);
      v111 = (float)((float)((float)v107 * v108->m_x) * (float)0.5);
      ((void (__fastcall *)(float *))this->m_behavior.m_pCurMotion->GetPos)(a1: v297);
      LODWORD(v112) = &dword_82420000;
      v287.m_x = (float)v111 + v297[0];
      v287.m_z = (float)v109 + v297[2];
      v287.m_y = (float)v110 + v297[1];
      HIDWORD(v113) = "Turning";
      bfx::DrawString(
        pSpace: (bfx::Vector3 *)this->m_pSpace,
        inputPos: &v287,
        fmt: v113,
        a4: v112,
        a5: v114,
        a6: v243,
        a7: v244,
        a8: v245,
        a9: v246,
        a10: v247,
        a11: v248,
        a12: v249,
        a13: v250);
    }
  }
  if ( this->m_stranded )
    return;
  m_pProxy = this->m_commonState.m_followData.m_targetMover.m_pProxy;
  p_m_targetMover = &this->m_commonState.m_followData.m_targetMover;
  v117 = m_pProxy != nullptr && m_pProxy->m_pTarget != nullptr;
  if ( (!v117
     || (p_m_targetMover->m_pProxy == nullptr
       ? (m_pTarget = nullptr)
       : (m_pTarget = p_m_targetMover->m_pProxy->m_pTarget),
         m_pTarget == nullptr))
    && bfx::MotionState::DrawMoverGoals(this: &this->m_commonState)
    || (p_m_targetMover->m_pProxy == nullptr ? (v119 = false) : (v119 = p_m_targetMover->m_pProxy->m_pTarget != nullptr),
        v119
     && (p_m_targetMover->m_pProxy == nullptr ? (v120 = nullptr) : (v120 = p_m_targetMover->m_pProxy->m_pTarget),
         v120 != nullptr && HIBYTE(v6->Draw) != 0)) )
  {
    m_state = this->m_behavior.m_state;
    if ( m_state == PATH_WALKING || m_state == JUMPING )
    {
      bfx::DrawLine(pSpace: this->m_pSpace, v0: &this->m_goalPos, v1: &this->m_lastGoalPosActedOn, color: &ColorRed_17);
      v122 = bfx::GetScale();
      bfx::DrawBox(
        pSpace: this->m_pSpace,
        pos: &this->m_lastGoalPosActedOn,
        r: (float)((float)v122 * (float)0.25),
        color: v123,
        a5: &ColorRed_17);
      ((void (__fastcall *)(bfx::Vec3 *))this->m_behavior.m_pCurMotion->GetPos)(a1: &v321);
      bfx::DrawLine(pSpace: this->m_pSpace, v0: &v321, v1: &this->m_goalPos, color: &ColorRed_17);
      v124 = bfx::GetScale();
      bfx::DrawBox(
        pSpace: this->m_pSpace,
        pos: &this->m_goalPos,
        r: (float)((float)v124 * (float)0.25),
        color: v125,
        a5: &ColorOrange_17);
      if ( (*((_BYTE *)this + 872) & 0x80) != 0 && this->m_gotoPosSpec.m_orientAtGoalEnable )
      {
        this->m_behavior.m_pCurMotion->GetMatrix(this: this->m_behavior.m_pCurMotion, a2: (bfx::Matrix *)v335);
        v126 = (float)(v335[10] * (float)0.25);
        v127 = (float)(v335[9] * (float)0.25);
        v128 = (float)(v335[8] * (float)0.25);
        v129 = bfx::GetScale();
        v130 = this->m_goalPos.m_y;
        v131 = this->m_goalPos.m_x;
        v267.m_z = this->m_goalPos.m_z + (float)((float)v126 * (float)v129);
        v267.m_y = (float)v130 + (float)((float)v127 * (float)v129);
        v267.m_x = (float)v131 + (float)((float)v128 * (float)v129);
        v132 = bfx::GetScale();
        v133 = (float)(this->m_gotoPosSpec.m_orientAtGoalDir.m_y * (float)v132);
        v134 = (float)(this->m_gotoPosSpec.m_orientAtGoalDir.m_x * (float)v132);
        v135 = (bfx::Vector3 *)this->m_pSpace;
        v294.m_z = (float)(this->m_gotoPosSpec.m_orientAtGoalDir.m_z * (float)v132) + v267.m_z;
        v294.m_y = (float)v133 + v267.m_y;
        v294.m_x = (float)v134 + v267.m_x;
        bfx::DrawArrow(pSpace: v135, startPos: &v267, endPos: &v294, color: &ColorYellow_17);
      }
      v136 = this->m_commonState.m_pSmartPath->m_snappedGoalArea.m_pProxy;
      if ( v136 != nullptr )
        m_pArea = v136->m_pArea;
      else
        m_pArea = nullptr;
      if ( m_pArea != nullptr )
      {
        bfx::GetUpAxisForStandingOnArea(result: &v271, pArea: m_pArea, pTune: this->m_pTune);
        v263[0].m_z = 0.0;
        if ( __fabs(v271.m_x) <= __fabs(v271.m_y) )
        {
          v263[0].m_x = 1.0;
          v263[0].m_y = 0.0;
        }
        else
        {
          v263[0].m_x = 0.0;
          v263[0].m_y = 1.0;
        }
        v262 = v263[0];
        _FP8 = (float)((float)__fsqrts((float)((float)((float)((float)(v263[0].m_y * v271.m_x)
                                                             - (float)(v271.m_y * v263[0].m_x))
                                                     * (float)((float)(v263[0].m_y * v271.m_x)
                                                             - (float)(v271.m_y * v263[0].m_x)))
                                             + (float)((float)((float)((float)(v263[0].m_z * v271.m_y)
                                                                     - (float)(v271.m_z * v263[0].m_y))
                                                             * (float)((float)(v263[0].m_z * v271.m_y)
                                                                     - (float)(v271.m_z * v263[0].m_y)))
                                                     + (float)((float)((float)(v271.m_z * v263[0].m_x)
                                                                     - (float)(v263[0].m_z * v271.m_x))
                                                             * (float)((float)(v271.m_z * v263[0].m_x)
                                                                     - (float)(v263[0].m_z * v271.m_x))))))
                     - (float)1.0842022e-19);
        __asm { fsel      f6, f8, f7, f31 }
        v289.m_x = (float)((float)(v263[0].m_z * v271.m_y) - (float)(v271.m_z * v263[0].m_y)) * (float)_FP6;
        v289.m_z = (float)((float)(v263[0].m_y * v271.m_x) - (float)(v271.m_y * v263[0].m_x)) * (float)_FP6;
        v289.m_y = (float)((float)(v271.m_z * v263[0].m_x) - (float)(v263[0].m_z * v271.m_x)) * (float)_FP6;
        v296.m_z = (float)((float)((float)((float)(v271.m_z * v263[0].m_x) - (float)(v262.m_z * v271.m_x)) * (float)_FP6)
                         * v271.m_x)
                 - (float)(v271.m_y
                         * (float)((float)((float)(v262.m_z * v271.m_y) - (float)(v271.m_z * v263[0].m_y)) * (float)_FP6));
        v296.m_y = (float)(v271.m_z
                         * (float)((float)((float)(v263[0].m_z * v271.m_y) - (float)(v271.m_z * v262.m_y)) * (float)_FP6))
                 - (float)((float)((float)((float)(v262.m_y * v271.m_x) - (float)(v271.m_y * v263[0].m_x)) * (float)_FP6)
                         * v271.m_x);
        v296.m_x = (float)(v271.m_y
                         * (float)((float)((float)(v263[0].m_y * v271.m_x) - (float)(v271.m_y * v262.m_x)) * (float)_FP6))
                 - (float)(v271.m_z
                         * (float)((float)((float)(v271.m_z * v262.m_x) - (float)(v263[0].m_z * v271.m_x)) * (float)_FP6));
        bfx::Matrix::Build(this: &v336, xAxis: &v289, yAxis: &v296, zAxis: &v271, trans: &this->m_goalPos);
        bfx::DrawCircle(
          pSpace: this->m_pSpace,
          mat: (bfx::Vec3 *)&v336,
          radius: this->m_gotoPosSpec.m_allowedToStopDist,
          color: v140,
          a5: &ColorOrange_17);
        bfx::DrawSpokes(
          pSpace: (bfx::Vector3 *)this->m_pSpace,
          mat: (bfx::Vec3 *)&v336,
          radius: this->m_gotoPosSpec.m_allowedToStopDist,
          numSpokes: v141,
          solidSpokes: 5,
          color: (const bfx::Color *)this->m_gotoPosSpec.m_stopAtGoal,
          a7: &ColorOrange_17);
        m_desiredStopDist = this->m_gotoPosSpec.m_desiredStopDist;
        if ( m_desiredStopDist > 0.0 )
          bfx::DrawCircle(
            pSpace: this->m_pSpace,
            mat: (bfx::Vec3 *)&v336,
            radius: m_desiredStopDist,
            color: v142,
            a5: &ColorYellow_17);
      }
    }
  }
  v144 = bfx::g_pCurInstance->m_pComponentManager->m_components[1][9].__vftable;
  if ( BYTE2(v144->Draw) != 0 )
  {
    v145 = bfx::GetScale();
    v146 = bfx::GetUpVec(result: (bfx::Vec3 *)&v265);
    v148 = (float)((float)(v146->m_z * (float)v145) * (float)1.2);
    v149 = (float)((float)(v146->m_y * (float)v145) * (float)1.2);
    v147 = (float)((float)(v146->m_x * (float)v145) * (float)1.2);
    ((void (__fastcall *)(float *))this->m_behavior.m_pCurMotion->GetPos)(a1: v291);
    v150 = this->m_pTune;
    v275.m_x = (float)v147 + v291[0];
    v275.m_z = v291[2] + (float)v148;
    HIDWORD(v151) = &dword_82420000;
    v275.m_y = v291[1] + (float)v149;
    HIDWORD(v152) = "   %08x";
    LODWORD(v152) = v150->m_linkUsageFlags;
    bfx::DrawString(
      pSpace: (bfx::Vector3 *)this->m_pSpace,
      inputPos: &v275,
      fmt: v152,
      a4: v151,
      a5: v153,
      a6: v243,
      a7: v244,
      a8: v245,
      a9: v246,
      a10: v247,
      a11: v248,
      a12: v249,
      a13: v250);
  }
  if ( bfx::g_drawFollowerData )
  {
    if ( bfx::MotionState::IsFollowerMode(this: &this->m_commonState) )
    {
      if ( p_m_targetMover->m_pProxy != nullptr && p_m_targetMover->m_pProxy->m_pTarget != nullptr )
        v155 = p_m_targetMover->m_pProxy != nullptr
             ? p_m_targetMover->m_pProxy->m_pTarget[146].m_pProxy
             : (bfx::HandleProxy *)MEMORY[0x494];
      else
        v155 = (bfx::HandleProxy *)MEMORY[0x494];
    }
    else
    {
      v155 = nullptr;
    }
    if ( v155 != nullptr )
    {
      ((void (__fastcall *)(bfx::Vec3 *))this->m_behavior.m_pCurMotion->GetPos)(a1: &v324);
      bfx::MotionState::FollowData::DebugDrawRank(
        this: &this->m_commonState.m_followData,
        pSpace: this->m_pSpace,
        pos: &v324);
      if ( v155[2].m_pTarget == (bfx::HandleTargetBase *)1 )
      {
        Follower = bfx::FollowerLeaderDatabase::FindFollower(this: (bfx::FollowerLeaderDatabase *)v155, pMover: this);
        v157 = bfx::GetScale();
        v158 = bfx::GetUpVec(result: (bfx::Vec3 *)&v265);
        v159 = (float)((float)(v158->m_z * (float)v157) * (float)0.5);
        v160 = (float)((float)(v158->m_y * (float)v157) * (float)0.5);
        v161 = (float)((float)(v158->m_x * (float)v157) * (float)0.5);
        ((void (__fastcall *)(float *))this->m_behavior.m_pCurMotion->GetPos)(a1: v276);
        v266.m_z = v276[2] + (float)v159;
        v266.m_x = (float)v161 + v276[0];
        v266.m_y = v276[1] + (float)v160;
        v165 = Follower->m_state;
        if ( v165 == 1 )
        {
          HIDWORD(v164) = "FollowState=Idle";
        }
        else
        {
          if ( v165 != HOMING )
          {
            v166 = (bfx::Vector3 *)this->m_pSpace;
            if ( v165 == NEAR_GOAL )
              HIDWORD(v164) = "FollowState=NearGoal";
            else
              HIDWORD(v164) = "FollowState=Uninitialized";
            goto LABEL_110;
          }
          HIDWORD(v164) = "FollowState=Homing";
        }
        v166 = (bfx::Vector3 *)this->m_pSpace;
LABEL_110:
        bfx::DrawString(
          pSpace: v166,
          inputPos: &v266,
          fmt: v164,
          a4: v163,
          a5: v162,
          a6: v243,
          a7: v244,
          a8: v245,
          a9: v246,
          a10: v247,
          a11: v248,
          a12: v249,
          a13: v250);
      }
    }
  }
  if ( bfx::g_drawFollowerData && this->m_pLeaderDatabase != nullptr )
  {
    v167 = this->m_commonState.m_surfer.m_area.m_pProxy;
    v168 = v167 != nullptr ? v167->m_pArea : nullptr;
    if ( v168 != nullptr )
    {
      bfx::GetUpAxisForStandingOnArea(result: &v272, pArea: v168, pTune: this->m_pTune);
      v263[0].m_z = 0.0;
      if ( __fabs(v272.m_x) <= __fabs(v272.m_y) )
      {
        v263[0].m_x = 1.0;
        v263[0].m_y = 0.0;
      }
      else
      {
        v263[0].m_x = 0.0;
        v263[0].m_y = 1.0;
      }
      m_pCurMotion = this->m_behavior.m_pCurMotion;
      v262 = v263[0];
      _FP8 = (float)((float)__fsqrts((float)((float)((float)((float)(v263[0].m_y * v272.m_x)
                                                           - (float)(v272.m_y * v263[0].m_x))
                                                   * (float)((float)(v263[0].m_y * v272.m_x)
                                                           - (float)(v272.m_y * v263[0].m_x)))
                                           + (float)((float)((float)((float)(v263[0].m_z * v272.m_y)
                                                                   - (float)(v272.m_z * v263[0].m_y))
                                                           * (float)((float)(v263[0].m_z * v272.m_y)
                                                                   - (float)(v272.m_z * v263[0].m_y)))
                                                   + (float)((float)((float)(v272.m_z * v263[0].m_x)
                                                                   - (float)(v263[0].m_z * v272.m_x))
                                                           * (float)((float)(v272.m_z * v263[0].m_x)
                                                                   - (float)(v263[0].m_z * v272.m_x))))))
                   - (float)1.0842022e-19);
      __asm { fsel      f5, f8, f7, f31 }
      v280.m_x = (float)((float)(v263[0].m_z * v272.m_y) - (float)(v272.m_z * v263[0].m_y)) * (float)_FP5;
      v280.m_z = (float)((float)(v263[0].m_y * v272.m_x) - (float)(v272.m_y * v263[0].m_x)) * (float)_FP5;
      v280.m_y = (float)((float)(v272.m_z * v263[0].m_x) - (float)(v263[0].m_z * v272.m_x)) * (float)_FP5;
      v278.m_z = (float)((float)((float)((float)(v272.m_z * v263[0].m_x) - (float)(v262.m_z * v272.m_x)) * (float)_FP5)
                       * v272.m_x)
               - (float)(v272.m_y
                       * (float)((float)((float)(v262.m_z * v272.m_y) - (float)(v272.m_z * v263[0].m_y)) * (float)_FP5));
      v278.m_y = (float)(v272.m_z
                       * (float)((float)((float)(v263[0].m_z * v272.m_y) - (float)(v272.m_z * v262.m_y)) * (float)_FP5))
               - (float)((float)((float)((float)(v262.m_y * v272.m_x) - (float)(v272.m_y * v263[0].m_x)) * (float)_FP5)
                       * v272.m_x);
      v278.m_x = (float)(v272.m_y
                       * (float)((float)((float)(v263[0].m_y * v272.m_x) - (float)(v272.m_y * v262.m_x)) * (float)_FP5))
               - (float)(v272.m_z
                       * (float)((float)((float)(v272.m_z * v262.m_x) - (float)(v263[0].m_z * v272.m_x)) * (float)_FP5));
      ((void (__fastcall *)(bfx::Vec3 *))m_pCurMotion->GetPos)(a1: &v322);
      bfx::Matrix::Build(this: &v338, xAxis: &v280, yAxis: &v278, zAxis: &v272, trans: &v322);
      bfx::DrawCircle(
        pSpace: this->m_pSpace,
        mat: (bfx::Vec3 *)&v338,
        radius: this->m_pLeaderDatabase->m_spec.m_radius,
        color: (const bfx::Color *)this->m_pLeaderDatabase,
        a5: &ColorYellow_17);
    }
  }
  v172 = this->m_behavior.m_pCurMotion;
  if ( v172 != nullptr )
    ((void (*)(void))v172->Draw)();
  if ( bfx::g_drawWalkerSpeeds )
  {
    v173 = bfx::GetUpVec(result: (bfx::Vec3 *)&v265);
    v174 = (float)((float)(this->m_vel.m_x * v173->m_x)
                 + (float)((float)(v173->m_y * this->m_vel.m_y) + (float)(v173->m_z * this->m_vel.m_z)));
    v175 = bfx::GetUpVec(result: v263);
    v176 = (float)(v175->m_y * (float)v174);
    v177 = (float)(v175->m_z * (float)v174);
    v178 = (float)(this->m_vel.m_y - (float)(v175->m_y * (float)v174));
    v179 = (float)(this->m_vel.m_x - (float)(v175->m_x * (float)v174));
    v180 = (float)(this->m_vel.m_z - (float)(v175->m_z * (float)v174));
    v181 = __fsqrts((float)((float)((float)v176 * (float)v176)
                          + (float)((float)((float)(v175->m_x * (float)v174) * (float)(v175->m_x * (float)v174))
                                  + (float)((float)v177 * (float)v177))));
    v182 = __fsqrts((float)((float)((float)v180 * (float)v180)
                          + (float)((float)((float)v179 * (float)v179) + (float)((float)v178 * (float)v178))));
    ((void (__fastcall *)(bfx::Vec3 *))this->m_behavior.m_pCurMotion->GetPos)(a1: &v323);
    HIDWORD(v183) = LODWORD(v181);
    bfx::DrawString(
      pSpace: (bfx::Vector3 *)this->m_commonState.m_pSpace,
      inputPos: &v323,
      fmt: *(__int64 *)&v182,
      a4: v183,
      a5: v184,
      a6: v243,
      a7: v244,
      a8: v245,
      a9: v246,
      a10: v247,
      a11: v248,
      a12: v249,
      a13: v250,
      v182,
      v181);
  }
  m_pTrail = this->m_pTrail;
  if ( m_pTrail != nullptr )
    bfx::Trail::Draw(this: m_pTrail, pSpace: this->m_pSpace, color: &ColorWhite_17);
  if ( bfx::MotionState::DrawMoverGoalsReached(this: &this->m_commonState) )
  {
    m_size = this->m_goalsReached.m_size;
    if ( m_size != 0 )
    {
      v187 = 0;
      v319 = ColorCyan_17;
      v265.m_data[0] = ColorYellow_17.m_r;
      v265.m_data[1] = ColorYellow_17.m_g;
      v265.m_data[2] = ColorYellow_17.m_b;
      v265.m_data[3] = ColorYellow_17.m_a;
      if ( m_size > 0 )
      {
        v188 = 0;
        do
        {
          v189 = &this->m_goalsReached.m_data[v188];
          v190 = bfx::GetScale();
          v191 = (float)((float)v190 * (float)0.15000001);
          v192 = (const bfx::Color *)&v265;
          _FP10 = -(float)((float)1.0 - v189->m_age);
          _FP9 = (float)((float)1.0 - (float)((float)1.0 - v189->m_age));
          __asm { fsel      f7, f10, f29, f13 }
          __asm { fsel      f5, f9, f6, f28 }
          if ( !v189->m_stop )
            v192 = &v319;
          v197 = v189->m_pos.m_x;
          v198 = v189->m_pos.m_y;
          v199 = v189->m_pos.m_z;
          v301.m_radius = (float)((float)_FP5
                                * (float)((float)(this->m_pTune->m_radiusData.m_radius * (float)3.0)
                                        - (float)((float)v190 * (float)0.15000001)))
                        + (float)((float)v190 * (float)0.15000001);
          v200 = this->m_pSpace;
          v301.m_pos.m_x = v197;
          v301.m_pos.m_y = v198;
          v301.m_pos.m_z = v199;
          bfx::DrawSphere(pSpace: v200, sphere: &v301, color: v192);
          bfx::DrawString(
            pSpace: (bfx::Vector3 *)this->m_pSpace,
            inputPos: &v189->m_pos,
            fmt: __SPAIR64__("%u", v187),
            a4: v202,
            a5: v201,
            a6: v243,
            a7: v244,
            a8: v245,
            a9: v246,
            a10: v247,
            a11: v248,
            a12: v249,
            a13: v250);
          v203 = this->m_pSpace;
          v204 = &this->m_goalsReached.m_data[v188];
          m_pos = v204->m_pos;
          v304 = v204->m_goalPos.m_x;
          v305 = v204->m_goalPos.m_y;
          v306 = v204->m_goalPos.m_z;
          bfx::DrawLineList(pSpace: v203, pVerts: &m_pos, numVerts: 2, color: &ColorGray_17);
          bfx::DrawBox(
            pSpace: this->m_pSpace,
            pos: &this->m_goalsReached.m_data[v188].m_goalPos,
            r: (float)((float)v191 * (float)0.5),
            color: v205,
            a5: &ColorGray_17);
          ++v187;
          ++v188;
          m_size = this->m_goalsReached.m_size;
        }
        while ( v187 < m_size );
      }
      v206 = 0;
      if ( m_size - 1 > 0 )
      {
        v207 = 0;
        do
        {
          v208 = this->m_pSpace;
          v209 = &this->m_goalsReached.m_data[v207];
          v307 = v209->m_pos;
          v308 = v209[1].m_pos.m_x;
          v309 = v209[1].m_pos.m_y;
          v310 = v209[1].m_pos.m_z;
          bfx::DrawLineList(pSpace: v208, pVerts: &v307, numVerts: 2, color: &v319);
          ++v206;
          ++v207;
        }
        while ( v206 < this->m_goalsReached.m_size - 1 );
      }
      ((void (__fastcall *)(float *))this->m_behavior.m_pCurMotion->GetPos)(a1: v282);
      v210 = this->m_pSpace;
      v311 = this->m_goalsReached.m_data[this->m_goalsReached.m_size - 1].m_pos;
      v312 = v282[0];
      v313 = v282[1];
      v314 = v282[2];
      bfx::DrawLineList(pSpace: v210, pVerts: &v311, numVerts: 2, color: &v319);
    }
  }
  else
  {
    bfx::Array<bfx::HoleRecord>::clear(this: (bfx::Array<bfx::QueuedTri> *)&this->m_goalsReached);
  }
  if ( BYTE1(v144->Start) != 0 && v8 == 0 )
  {
    v211 = bfx::GetScale();
    v212 = bfx::GetUpVec(result: (bfx::Vec3 *)&v265);
    v213 = (float)((float)(v212->m_z * (float)v211) * (float)0.5);
    v214 = (float)((float)(v212->m_y * (float)v211) * (float)0.5);
    v215 = (float)((float)(v212->m_x * (float)v211) * (float)0.5);
    ((void (__fastcall *)(float *))this->m_behavior.m_pCurMotion->GetPos)(a1: v284);
    HIDWORD(v216) = this->m_pTune;
    v286.m_z = v284[2] + (float)v213;
    v286.m_x = (float)v215 + v284[0];
    LODWORD(v216) = &unk_82410000;
    v286.m_y = v284[1] + (float)v214;
    HIDWORD(v217) = "ObstacleFlags=%04x";
    LODWORD(v217) = *(_DWORD *)(HIDWORD(v216) + 76);
    bfx::DrawString(
      pSpace: (bfx::Vector3 *)this->m_pSpace,
      inputPos: &v286,
      fmt: v217,
      a4: v216,
      a5: v218,
      a6: v243,
      a7: v244,
      a8: v245,
      a9: v246,
      a10: v247,
      a11: v248,
      a12: v249,
      a13: v250);
  }
  if ( this->m_pTune->m_clientMotion && BYTE2(v6->Start) != 0 && this->m_behavior.m_state != PUPPET && v8 == 0 )
  {
    ((void (__fastcall *)(bfx::Vec3 *))this->m_behavior.m_pCurMotion->GetPos)(a1: &v269);
    v219 = (float)(v269.m_z + this->m_clientMotionDebugData.m_clientVel.m_z);
    v220 = (float)(v269.m_x + this->m_clientMotionDebugData.m_desiredVel.m_x);
    v221 = (float)(this->m_clientMotionDebugData.m_clientVel.m_x + v269.m_x);
    v222 = (float)(v269.m_y + this->m_clientMotionDebugData.m_desiredVel.m_y);
    v223 = (float)(v269.m_y + this->m_clientMotionDebugData.m_clientVel.m_y);
    v274.m_z = v269.m_z + this->m_clientMotionDebugData.m_desiredVel.m_z;
    v274.m_y = v222;
    v265.m_data[14] = v219;
    v265.m_data[13] = v223;
    v224 = (bfx::Vector3 *)this->m_pSpace;
    v274.m_x = v220;
    v265.m_data[12] = v221;
    bfx::DrawArrow(pSpace: v224, startPos: &v269, endPos: &v274, color: &ColorBlue_17);
    v225 = bfx::GetScale();
    bfx::DrawBox(
      pSpace: this->m_pSpace,
      pos: &v274,
      r: (float)((float)v225 * (float)0.079999998),
      color: v226,
      a5: &ColorBlue_17);
    bfx::DrawArrow(
      pSpace: (bfx::Vector3 *)this->m_pSpace,
      startPos: &v269,
      endPos: (const bfx::Vec3 *)&v265.m_data[12],
      color: &ColorPurple_17);
    v227 = bfx::GetScale();
    v228 = this->m_pSpace;
    v302.m_radius = (float)v227 * (float)0.059999999;
    v302.m_pos = *(bfx::Vec3 *)&v265.m_data[12];
    bfx::DrawSphere(pSpace: v228, sphere: &v302, color: &ColorPurple_17);
  }
  v320 = ColorBlue_17;
  v229 = bfx::g_drawNextNCorners;
  v230 = bfx::g_drawNextNCorners;
  if ( LOBYTE(v6->Start) != 0 )
  {
    v230 = true;
    v320 = ColorYellow_17;
  }
  if ( v230 )
  {
    memset(&v265.m_data[4], 0, 12);
    LODWORD(v265.m_data[7]) = bfx::MEM_BFXMOVER;
    if ( bfx::MoverImpl::CalculateCornersArray(
           this,
           cornersOut: (bfx::Array<bfx::SmartPathCorner> *)&v265.m_data[4],
           maxNumCorners: 0x7FFFFFFF) )
    {
      ((void (__fastcall *)(float *))this->m_behavior.m_pCurMotion->GetPos)(a1: &v265.m_data[8]);
      v231 = (char *)LODWORD(v265.m_data[4]);
      if ( LODWORD(v265.m_data[4]) != 28 * LODWORD(v265.m_data[5]) + LODWORD(v265.m_data[4]) )
      {
        v232 = v265.m_data[10];
        v233 = v265.m_data[9];
        v234 = v265.m_data[8];
        v235 = v229;
        for ( i = (float *)(LODWORD(v265.m_data[4]) + 16);
              i - 4 != (float *)(28 * LODWORD(v265.m_data[5]) + LODWORD(v265.m_data[4]));
              i += 7 )
        {
          v315.m_z = v232;
          v315.m_x = v234;
          v315.m_y = v233;
          v237 = this->m_pSpace;
          v316 = *(i - 4);
          v238 = i - 4;
          v317 = *(i - 3);
          v318 = *(i - 2);
          bfx::DrawLineList(pSpace: v237, pVerts: &v315, numVerts: 2, color: &v320);
          if ( v235 )
          {
            if ( *((_BYTE *)i - 4) != 0 )
            {
              HIDWORD(v241) = "Goal";
LABEL_162:
              bfx::DrawString(
                pSpace: (bfx::Vector3 *)this->m_pSpace,
                inputPos: (const bfx::Vec3 *)(i - 4),
                fmt: v241,
                a4: v240,
                a5: v239,
                a6: v243,
                a7: v244,
                a8: v245,
                a9: v246,
                a10: v247,
                a11: v248,
                a12: v249,
                a13: v250);
              goto LABEL_163;
            }
            v242 = *i;
            if ( *(_DWORD *)i == 0 )
            {
              HIDWORD(v241) = "Corner";
              goto LABEL_162;
            }
            if ( LODWORD(v242) == 1 )
            {
              HIDWORD(v241) = "LinkStart";
              goto LABEL_162;
            }
            if ( LODWORD(v242) == 2 )
            {
              HIDWORD(v241) = "LinkEnd";
              goto LABEL_162;
            }
          }
LABEL_163:
          v234 = *v238;
          v265.m_data[8] = *v238;
          v231 = (char *)LODWORD(v265.m_data[4]);
          v233 = *(i - 3);
          v265.m_data[9] = *(i - 3);
          v232 = *(i - 2);
          v265.m_data[10] = *(i - 2);
        }
      }
    }
    else
    {
      v231 = (char *)LODWORD(v265.m_data[4]);
    }
    v265.m_data[5] = 0.0;
    if ( v231 != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v231);
  }
}


// ========================================================================
// __unwind$89294
// EA  : 0x832B0AF0
// RVA : 0x012B0AF0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverutils.cpp
// ========================================================================

void _unwind_89294()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 2928 + 224));
}


// ========================================================================
// ??1MotionState@bfx@@QAA@XZ
// EA  : 0x832B0BF0
// RVA : 0x012B0BF0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverutils.cpp
// ========================================================================

void __fastcall bfx::MotionState::~MotionState(bfx::MotionState *this)
{
  char *m_pProber; // r30
  bfx::SmartPath *m_pSmartPath; // r30
  bfx::HandleProxy *m_pProxy; // r3

  m_pProber = (char *)this->m_pProber;
  if ( m_pProber != nullptr )
  {
    bfx::Prober::~Prober(this: this->m_pProber);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pProber);
  }
  m_pSmartPath = this->m_pSmartPath;
  this->m_pProber = nullptr;
  if ( m_pSmartPath != nullptr )
  {
    bfx::SmartPath::~SmartPath(this: m_pSmartPath);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)m_pSmartPath);
  }
  this->m_pSmartPath = nullptr;
  m_pProxy = this->m_followData.m_targetMover.m_pProxy;
  if ( m_pProxy != nullptr )
  {
    bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
    this->m_followData.m_targetMover.m_pProxy = nullptr;
  }
  bfx::Surfer::~Surfer(this: &this->m_surfer);
}


// ========================================================================
// __unwind$91314
// EA  : 0x832B0C8C
// RVA : 0x012B0C8C
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverutils.cpp
// ========================================================================

void _unwind_91314()
{
  int v0; // r12

  bfx::MSurfer::~MSurfer(this: (bfx::MSurfer *)(*(_DWORD *)(v0 - 144 + 164) + 16));
}


// ========================================================================
// __unwind$91315
// EA  : 0x832B0CB8
// RVA : 0x012B0CB8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverutils.cpp
// ========================================================================

void _unwind_91315()
{
  int v0; // r12

  bfx::MotionState::FollowData::~FollowData(this: (bfx::MotionState::FollowData *)(*(_DWORD *)(v0 - 144 + 164) + 340));
}


// ========================================================================
// ??0MotionState@bfx@@QAA@PAVSpace@1@PBUMoverTune@1@I@Z
// EA  : 0x832B0CF0
// RVA : 0x012B0CF0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverutils.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
bfx::MotionState *__fastcall bfx::MotionState::MotionState(
        bfx::MotionState *this,
        bfx::Space *pSpace,
        const bfx::MoverTune *pTune,
        unsigned int replayID)
{
  bfx::bfxMemTag v6; // r11
  bfx::bfxMemTag v7; // r11
  bfx::SmartPath *v8; // r3
  bfx::SmartPath *v9; // r3
  unsigned __int64 v10; // r6 OVERLAPPED
  bfx::Prober *v11; // r3
  bfx::Prober *v12; // r3
  __int16 v14; // [sp+50h] [-70h] BYREF
  __int16 v15; // [sp+52h] [-6Eh]
  void *v16; // [sp+54h] [-6Ch]
  bfx::PathSpec v17; // [sp+60h] [-60h] BYREF

  this->m_replayID = replayID;
  this->m_pTune = pTune;
  this->m_pSpace = pSpace;
  this->m_selected = false;
  this->m_surfer.__vftable = (bfx::MSurfer_vtbl *)&bfx::Surfer::`vftable';
  this->m_surfer.m_area.m_pProxy = nullptr;
  this->m_surfer.m_areaNormal.m_x = 0.0;
  this->m_surfer.m_areaNormal.m_y = 0.0;
  this->m_surfer.m_areaNormal.m_z = 0.0;
  this->m_surfer.m_edgeCursor.m_i = -1;
  this->m_surfer.m_edgeCursor.m_pArea = nullptr;
  this->m_surfer.m_state = ON_AREA;
  v6 = bfx::MEM_BFXNAVIGATOR;
  this->m_surfer.m_areasTraversed.m_data = nullptr;
  this->m_surfer.m_areasTraversed.m_size = 0;
  this->m_surfer.m_areasTraversed.m_cap = 0;
  this->m_surfer.m_areasTraversed.m_tag = v6;
  v7 = bfx::MEM_BFXNAVIGATOR;
  this->m_surfer.m_edgesTraversed.m_data = nullptr;
  this->m_surfer.m_edgesTraversed.m_size = 0;
  this->m_surfer.m_edgesTraversed.m_cap = 0;
  this->m_surfer.m_edgesTraversed.m_tag = v7;
  v15 = (_WORD)this + 76;
  this->m_surfer.__vftable = (bfx::MSurfer_vtbl *)&bfx::MSurfer::`vftable';
  this->m_surfer.m_pMoverImpl = nullptr;
  this->m_pRepulsor = nullptr;
  this->m_pSmartPath = nullptr;
  this->m_smartPathTimeStamp = 0;
  this->m_flockID = 0;
  this->m_orientCmd.m_mode = ORIENT_IN_TRAVEL_DIR;
  this->m_orientCmd.m_vec = bfx::ZERO_VEC;
  bfx::Orienter::Orienter(this: &this->m_orienter, pSpace, pTune);
  this->m_pProber = nullptr;
  bfx::MotionState::FollowData::FollowData(this: &this->m_followData);
  v17.m_pathSharingPenalty = 0.0;
  this->m_debugFlags = 0;
  v17.m_maxPathSharingPenalty = 0.0;
  this->m_speedX = 1.0;
  v17.m_areaUsageFlags = -1;
  this->m_slowTime = 1.0;
  v17.m_linkUsageFlags = -1;
  this->m_cautionData.m_internalSpeedX = 1.0;
  this->m_cautionData.m_radius = 0.0;
  this->m_contactTime = -3.4028235e38;
  this->m_externalForce.m_x = bfx::ZERO_VEC.m_x;
  v17.m_maxSearchDist = 0.0;
  this->m_externalForce.m_y = bfx::ZERO_VEC.m_y;
  this->m_externalForce.m_z = bfx::ZERO_VEC.m_z;
  this->m_blockedMonitor.m_blockedTimer = 0.0;
  this->m_blockedMonitor.m_oldPosForBlockedCheck = bfx::ZERO_VEC;
  this->m_forceUseClientMotion = false;
  this->m_clientMotionSkidTurnAllowed = false;
  this->m_randPrev = 0;
  v17.m_obstacleBlockageFlags = 0xFFFF;
  v17.m_obstacleMode = BLOCKED_IF_ANY_MATCH;
  v17.m_usePathSharingPenalty = false;
  v14 = 256;
  v8 = (bfx::SmartPath *)bfx::MemoryManager::Malloc(
                           this: bfx::g_pCurInstance->m_pMemoryManager,
                           size: 0x118u,
                           tag: bfx::MEM_BFXPLANNER);
  v16 = v8;
  if ( v8 != nullptr )
    v9 = bfx::SmartPath::SmartPath(
           this: v8,
           pSpace: this->m_pSpace,
           layer: this->m_pTune->m_planLayer,
           pathSpec: &v17,
           options: (const bfx::PathCreationOptions *)&v14);
  else
    v9 = nullptr;
  this->m_pSmartPath = v9;
  if ( pTune->m_proberTune.m_probeForGround )
  {
    v11 = (bfx::Prober *)bfx::MemoryManager::Malloc(
                           this: bfx::g_pCurInstance->m_pMemoryManager,
                           size: 0x30u,
                           tag: bfx::MEM_BFXMOVER);
    v16 = v11;
    if ( v11 != nullptr )
    {
      *(unsigned __int64 *)((char *)&v10 + 4) = pTune->m_proberTune.m_probeUserData;
      v12 = bfx::Prober::Prober(this: v11, probeInterval: pTune->m_proberTune.m_probeInterval, probeUserData: v10);
    }
    else
    {
      v12 = nullptr;
    }
    this->m_pProber = v12;
  }
  return this;
}


// ========================================================================
// __unwind$91400
// EA  : 0x832B0F70
// RVA : 0x012B0F70
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverutils.cpp
// ========================================================================

void _unwind_91400()
{
  int v0; // r12

  bfx::MSurfer::~MSurfer(this: (bfx::MSurfer *)(*(_DWORD *)(v0 - 192 + 212) + 16));
}


// ========================================================================
// __unwind$91401
// EA  : 0x832B0F9C
// RVA : 0x012B0F9C
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverutils.cpp
// ========================================================================

void _unwind_91401()
{
  int v0; // r12

  bfx::MotionState::FollowData::~FollowData(this: (bfx::MotionState::FollowData *)(*(_DWORD *)(v0 - 192 + 212) + 340));
}


// ========================================================================
// __unwind$91402
// EA  : 0x832B0FC8
// RVA : 0x012B0FC8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverutils.cpp
// ========================================================================

void _unwind_91402()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(char **)(v0 - 192 + 84), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// __unwind$91403
// EA  : 0x832B0FF4
// RVA : 0x012B0FF4
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverutils.cpp
// ========================================================================

void _unwind_91403()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(char **)(v0 - 192 + 84), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// bfx::`dynamic initializer for 'g_disableClientMotionRestore''
// EA  : 0x83399260
// RVA : 0x01399260
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverutils.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_disableClientMotionRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_disableClientMotionRestore);
  bfx::g_disableClientMotionRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_disableClientMotionRestore.m_targetBool = &bfx::g_disableClientMotion;
  bfx::g_disableClientMotionRestore.m_name = "disable_client_motion";
  bfx::g_disableClientMotionRestore.m_defaultBool = bfx::g_disableClientMotion;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_disableClientMotionRestore__);
}


// ========================================================================
// bfx::`dynamic initializer for 'g_drawNextNCornersRestore''
// EA  : 0x833992D8
// RVA : 0x013992D8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverutils.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_drawNextNCornersRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_drawNextNCornersRestore);
  bfx::g_drawNextNCornersRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_drawNextNCornersRestore.m_targetBool = &bfx::g_drawNextNCorners;
  bfx::g_drawNextNCornersRestore.m_name = "draw_next_n_corners";
  bfx::g_drawNextNCornersRestore.m_defaultBool = bfx::g_drawNextNCorners;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_drawNextNCornersRestore__);
}


// ========================================================================
// bfx::`dynamic initializer for 'g_drawFollowerDataRestore''
// EA  : 0x83399350
// RVA : 0x01399350
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverutils.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_drawFollowerDataRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_drawFollowerDataRestore);
  bfx::g_drawFollowerDataRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_drawFollowerDataRestore.m_targetBool = &bfx::g_drawFollowerData;
  bfx::g_drawFollowerDataRestore.m_name = "draw_follower_data";
  bfx::g_drawFollowerDataRestore.m_defaultBool = bfx::g_drawFollowerData;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_drawFollowerDataRestore__);
}

