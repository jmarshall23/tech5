
// ========================================================================
// ?CompareFollowerBuddiesRadius@bfx@@YAHPBX0@Z
// EA  : 0x832B2890
// RVA : 0x012B2890
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollower.cpp
// ========================================================================

int __fastcall bfx::CompareFollowerBuddiesRadius(float *a, float *b)
{
  double v2; // fp0
  double v3; // fp13
  int result; // r3

  v2 = a[1];
  v3 = b[1];
  if ( v2 > v3 )
    return 1;
  result = -1;
  if ( v2 >= v3 )
    return 0;
  return result;
}


// ========================================================================
// ?AngleBetween@bfx@@YAMABVVec3@1@0@Z
// EA  : 0x832B28C0
// RVA : 0x012B28C0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollower.cpp
// ========================================================================

float __fastcall bfx::AngleBetween(const bfx::Vec3 *vForward, const bfx::Vec3 *vOther)
{
  long double v4; // fp4
  long double v5; // fp2
  long double v6; // fp2
  double v7; // fp1
  bfx::Vec3 v9; // [sp+50h] [-30h] BYREF

  bfx::GetUpVec(result: &v9);
  *((double *)&v4 + 1) = (float)(vOther->m_y * vForward->m_y);
  *(double *)&v4 = vOther->m_x;
  *((double *)&v5 + 1) = (float)((float)(vOther->m_z * vForward->m_z)
                               + (float)((float)(vOther->m_x * vForward->m_x) + (float)(vOther->m_y * vForward->m_y)));
  *(double *)&v5 = (float)((float)(vOther->m_z
                                 * (float)((float)(vForward->m_y * v9.m_x) - (float)(vForward->m_x * v9.m_y)))
                         + (float)((float)(vOther->m_x
                                         * (float)((float)(vForward->m_z * v9.m_y) - (float)(vForward->m_y * v9.m_z)))
                                 + (float)(vOther->m_y
                                         * (float)((float)(vForward->m_x * v9.m_z) - (float)(vForward->m_z * v9.m_x)))));
  v6 = atan2(v: v5, u: v4);
  v7 = (float)((float)*(double *)&v6 * (float)57.295776);
  return *((float *)&v7 + 1);
}


// ========================================================================
// ?LeaderIsNearGoal@MoverImpl@bfx@@AAA_NXZ
// EA  : 0x832B2968
// RVA : 0x012B2968
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollower.cpp
// ========================================================================

int __fastcall bfx::MoverImpl::LeaderIsNearGoal(bfx::MoverImpl *this)
{
  double v2; // fp31
  double v3; // fp12
  float m_x; // r8
  float m_y; // r7
  int result; // r3
  double v7; // fp2
  float v8; // [sp+50h] [-30h] BYREF
  float v9; // [sp+54h] [-2Ch]
  float m_z; // [sp+58h] [-28h]

  if ( this->m_behavior.m_state != PATH_WALKING )
    return 0;
  v2 = (float)(this->m_pTune->m_radiusData.m_radius * (float)15.0);
  if ( !this->m_behavior.m_pWalker->IsGoalInView(this: this->m_behavior.m_pWalker) )
    return 0;
  ((void (__fastcall *)(float *))this->m_behavior.m_pCurMotion->GetPos)(a1: &v8);
  v3 = m_z;
  m_x = this->m_goalPos.m_x;
  m_y = this->m_goalPos.m_y;
  result = 1;
  m_z = this->m_goalPos.m_z;
  v7 = (float)((float)((float)(m_x - v8) * (float)(m_x - v8))
             + (float)((float)((float)(m_z - (float)v3) * (float)(m_z - (float)v3))
                     + (float)((float)(m_y - v9) * (float)(m_y - v9))));
  v8 = m_x;
  v9 = m_y;
  if ( v7 > (float)((float)v2 * (float)v2) )
    return 0;
  return result;
}


// ========================================================================
// ??0FollowerTune@bfx@@QAA@XZ
// EA  : 0x832B2A50
// RVA : 0x012B2A50
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollower.cpp
// ========================================================================

bfx::FollowerTune *__fastcall bfx::FollowerTune::FollowerTune(bfx::FollowerTune *this)
{
  double Scale; // fp1

  this->m_circulate.m_enable = true;
  this->m_circulate.m_minTime = 1.0;
  this->m_circulate.m_maxTime = 2.0;
  this->m_startupSlowness = 0.75;
  this->m_startupBulk = 0.2;
  Scale = bfx::GetScale();
  this->m_packingPadding = (float)Scale * (float)0.25;
  return this;
}


// ========================================================================
// ?FollowMover_AdjustDynamics@bfx@@YAXAAVMotionState@1@ABVVec3@1@PAVMoverImpl@1@1MAAVFMSpec@1@@Z
// EA  : 0x832B2AC8
// RVA : 0x012B2AC8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollower.cpp
// ========================================================================

void __fastcall bfx::FollowMover_AdjustDynamics(
        bfx::Vec3 *commonState,
        const bfx::Vec3 *newGoalPos,
        bfx::MoverImpl *pTargetMover,
        const bfx::Vec3 *myVel,
        double timerLerp,
        bfx::FMSpec *spec,
        int a7)
{
  const bfx::MoverTune *m_y_low; // r10
  bfx::Prober *m_x_low; // r9
  bfx::FollowerTune *p_m_followerTune; // r22
  bfx::Vec3 *p_m_surfer; // r11
  float m_y; // r7
  float m_z; // r6
  bfx::Vec3 *v18; // r29
  double v19; // fp31
  double v20; // fp25
  double v21; // fp12
  double v22; // fp30
  double v23; // fp0
  double v24; // fp29
  double v25; // fp1
  double v26; // fp27
  double v27; // fp24
  double v28; // fp26
  double v29; // fp23
  bfx::Prober *v30; // r10
  char v31; // r26
  bfx::Vec3 *v32; // r11
  const bfx::MoverTune *v33; // r8
  unsigned int m_z_low; // r7
  bfx::FollowerLeaderDatabase *m_pLeaderDatabase; // r25
  double v36; // fp21
  double v37; // fp0
  double v38; // fp13
  double v39; // fp12
  const bfx::MoverTune *v40; // r11
  double v41; // fp0
  double v42; // fp28
  bool v43; // r11
  double v44; // fp21
  double v45; // fp19
  double v46; // fp18
  bfx::MotionState *Pos; // r3
  bfx::MotionBase *m_pCurMotion; // r4
  double v51; // fp1
  float *v52; // r3
  double v54; // fp28
  double v55; // fp27
  double v56; // fp26
  double v58; // fp25
  double v59; // fp24
  double v60; // fp23
  double v61; // fp0
  double v62; // fp29
  double v63; // fp31
  double v64; // fp30
  bfx::Vec3 *UpVec; // r3
  double v66; // fp20
  double Scale; // fp1
  double v69; // fp3
  double v73; // fp5
  double v74; // fp4
  double v75; // fp28
  double v91; // fp30
  double v92; // fp29
  double v93; // fp31
  double v96; // fp28
  double v97; // fp27
  double v98; // fp22
  long double v99; // fp2
  const bfx::MoverTune *v100; // r11
  const bfx::MoverTune *v105; // r11
  bfx::RepulsorImpl *v110; // r11
  double m_startupBulk; // fp0
  float v112; // [sp+50h] [-230h] BYREF
  float v113; // [sp+54h] [-22Ch]
  float v114; // [sp+58h] [-228h]
  bfx::MotionState v115; // [sp+60h] [-220h] BYREF

  m_y_low = (const bfx::MoverTune *)LODWORD(commonState->m_y);
  m_x_low = (bfx::Prober *)LODWORD(commonState[28].m_x);
  p_m_followerTune = &m_y_low->m_followerTune;
  if ( m_x_low != nullptr )
  {
    p_m_surfer = (bfx::Vec3 *)&v115.m_surfer;
    m_y = m_x_low->m_pos3DOffset.m_y;
    m_z = m_x_low->m_pos3DOffset.m_z;
    v115.m_surfer.__vftable = (bfx::MSurfer_vtbl *)LODWORD(m_x_low->m_pos3DOffset.m_x);
    v115.m_surfer.m_pos.m_x = m_y;
    v115.m_surfer.m_pos.m_y = m_z;
  }
  else
  {
    p_m_surfer = &bfx::ZERO_VEC;
  }
  v18 = (bfx::Vec3 *)((char *)commonState + 20);
  v19 = (float)(pTargetMover->m_vel.m_z * pTargetMover->m_commonState.m_slowTime);
  v20 = (float)(m_y_low->m_radiusData.m_radius * (float)0.75);
  v21 = (float)(newGoalPos->m_z - (float)(p_m_surfer->m_z + commonState[2].m_y));
  v22 = (float)(pTargetMover->m_vel.m_x * pTargetMover->m_commonState.m_slowTime);
  v23 = (float)(newGoalPos->m_y - (float)(p_m_surfer->m_y + commonState[2].m_x));
  v24 = (float)(pTargetMover->m_vel.m_y * pTargetMover->m_commonState.m_slowTime);
  v25 = (float)(newGoalPos->m_x - (float)(p_m_surfer->m_x + commonState[1].m_z));
  v26 = (float)((float)((float)v24 * (float)v24)
              + (float)((float)((float)v22 * (float)v22) + (float)((float)v19 * (float)v19)));
  v27 = __fsqrts((float)((float)(myVel->m_z * myVel->m_z)
                       + (float)((float)(myVel->m_x * myVel->m_x) + (float)(myVel->m_y * myVel->m_y))));
  v28 = __fsqrts(v26);
  v29 = __fsqrts((float)((float)((float)v23 * (float)v23)
                       + (float)((float)((float)v25 * (float)v25) + (float)((float)v21 * (float)v21))));
  pTargetMover->m_behavior.m_pCurMotion->GetPos(
    this: (bfx::MotionBase *)&v112,
    result: (bfx::Vec3 *)pTargetMover->m_behavior.m_pCurMotion);
  bfx::MoverTune::MoverTune(this: (bfx::MoverTune *)&v115.m_surfer.m_areasTraversed.m_size);
  memcpy(Dst: &v115.m_surfer.m_areasTraversed.m_size, Src: pTargetMover->m_pTune, Size: 0x118u);
  v30 = (bfx::Prober *)LODWORD(commonState[28].m_x);
  v31 = 0;
  if ( v30 != nullptr )
  {
    v32 = (bfx::Vec3 *)&v115;
    v33 = (const bfx::MoverTune *)LODWORD(v30->m_pos3DOffset.m_y);
    m_z_low = LODWORD(v30->m_pos3DOffset.m_z);
    v115.m_pSpace = (bfx::Space *)LODWORD(v30->m_pos3DOffset.m_x);
    v115.m_pTune = v33;
    v115.m_replayID = m_z_low;
  }
  else
  {
    v32 = &bfx::ZERO_VEC;
  }
  m_pLeaderDatabase = pTargetMover->m_pLeaderDatabase;
  v36 = 0.0009765625;
  v37 = (float)((float)(v32->m_x + v18->m_x) - v112);
  v38 = (float)((float)(v32->m_y + commonState[2].m_x) - v113);
  v39 = (float)((float)(v32->m_z + commonState[2].m_y) - v114);
  if ( v28 > 0.0009765625
    && (float)((float)((float)((float)(v32->m_y + commonState[2].m_x) - v113) * (float)v24)
             + (float)((float)((float)((float)(v32->m_x + v18->m_x) - v112) * (float)v22)
                     + (float)((float)((float)(v32->m_z + commonState[2].m_y) - v114) * (float)v19))) > 0.0 )
  {
    v40 = (const bfx::MoverTune *)LODWORD(commonState->m_y);
    v41 = (float)((float)((float)v38 * (float)v38)
                + (float)((float)((float)v37 * (float)v37) + (float)((float)v39 * (float)v39)));
    v42 = (float)((float)((float)(v40->m_radiusData.m_radius + *(float *)&v115.m_surfer.m_edgesTraversed.m_data)
                        + *(float *)&v115.m_surfer.m_edgesTraversed.m_size)
                + *(float *)&v115.m_surfer.m_areasTraversed.m_tag);
    if ( __fsqrts(v41) > (float)((float)((float)((float)(v40->m_radiusData.m_radius
                                                       + *(float *)&v115.m_surfer.m_edgesTraversed.m_data)
                                               + *(float *)&v115.m_surfer.m_edgesTraversed.m_size)
                                       + *(float *)&v115.m_surfer.m_areasTraversed.m_tag)
                               * (float)1.1) )
    {
      v43 = v28 < (float)(v40->m_speed * (float)0.85000002);
      if ( __fsqrts(v41) <= (float)(*(float *)(a7 + 4) * (float)1.5) )
      {
        if ( v43 )
        {
          v31 = 1;
          commonState[28].m_z = 0.2;
        }
        else
        {
          v44 = (float)((float)v22 - myVel->m_x);
          v45 = (float)((float)v24 - myVel->m_y);
          v46 = (float)((float)v19 - myVel->m_z);
          Pos = bfx::MotionState::GetPos(this: &v115, result: commonState);
          m_pCurMotion = pTargetMover->m_behavior.m_pCurMotion;
          v115.m_surfer.m_area.m_pProxy = (bfx::AreaProxy *)Pos->m_pSpace;
          v115.m_surfer.m_areaNormal.m_x = *(float *)&Pos->m_pTune;
          _FP5 = (float)((float)__fsqrts((float)((float)((float)v45 * (float)v45)
                                               + (float)((float)((float)v44 * (float)v44)
                                                       + (float)((float)v46 * (float)v46))))
                       - (float)1.0842022e-19);
          __asm { fsel      f3, f5, f4, f22 }
          v115.m_surfer.m_areaNormal.m_y = (float)_FP3 * (float)v44;
          v115.m_surfer.m_areaNormal.m_z = (float)v45 * (float)_FP3;
          ((void (__fastcall *)(bfx::EdgeCursor *))m_pCurMotion->GetPos)(a1: &v115.m_surfer.m_edgeCursor);
          v115.m_surfer.__vftable = (bfx::MSurfer_vtbl *)v115.m_surfer.m_edgeCursor.m_pArea;
          v115.m_surfer.m_pos.m_x = *(float *)&v115.m_surfer.m_edgeCursor.m_i;
          v51 = bfx::CollideLineAndCircle(
                  lineStart: (const bfx::Vec2 *)&v115.m_surfer,
                  normalizedLineDir: (const bfx::Vec2 *)&v115.m_surfer.m_areaNormal.m_y,
                  circlePos: (const bfx::Vec2 *)&v115.m_surfer.m_area,
                  radius: (float)((float)v42 * (float)0.99000001));
          if ( v51 < 3.4028235e38 && v51 >= 0.0 )
          {
            v31 = 1;
            commonState[28].m_z = 0.2;
          }
          v36 = 0.0009765625;
        }
      }
    }
    else
    {
      v31 = 1;
      commonState[28].m_z = 0.2;
    }
  }
  if ( m_pLeaderDatabase != nullptr && m_pLeaderDatabase->m_leaderIsCloseToGoal )
    v31 = 1;
  if ( v31 != 0 )
  {
    v52 = (float *)bfx::MotionState::GetPos(this: &v115, result: commonState);
    _FP5 = (float)((float)__fsqrts(v26) - 1.0842022e-19);
    v54 = (float)(v52[2] - v114);
    v55 = (float)(*v52 - v112);
    v56 = (float)(v52[1] - v113);
    __asm { fsel      f3, f5, f4, f22 }
    v58 = (float)((float)v19 * (float)_FP3);
    v59 = (float)((float)_FP3 * (float)v22);
    v60 = (float)((float)v24 * (float)_FP3);
    v61 = (float)((float)((float)((float)v24 * (float)_FP3) * (float)(v52[1] - v113))
                + (float)((float)((float)((float)_FP3 * (float)v22) * (float)(*v52 - v112))
                        + (float)((float)((float)v19 * (float)_FP3) * (float)(v52[2] - v114))));
    if ( v61 < 0.0 )
    {
      commonState[30].m_z = (float)((float)(1.0 - p_m_followerTune->m_startupSlowness) * (float)timerLerp)
                          + p_m_followerTune->m_startupSlowness;
    }
    else
    {
      v62 = (float)((float)(v52[1] - v113)
                  - (float)((float)((float)v24 * (float)_FP3)
                          * (float)((float)((float)((float)v24 * (float)_FP3) * (float)(v52[1] - v113))
                                  + (float)((float)((float)((float)_FP3 * (float)v22) * (float)(*v52 - v112))
                                          + (float)((float)((float)v19 * (float)_FP3) * (float)(v52[2] - v114))))));
      v63 = (float)((float)(v52[2] - v114) - (float)((float)((float)v19 * (float)_FP3) * (float)v61));
      v64 = (float)((float)(*v52 - v112) - (float)((float)((float)_FP3 * (float)v22) * (float)v61));
      if ( (float)((float)((float)v64 * (float)v64)
                 + (float)((float)((float)v63 * (float)v63) + (float)((float)v62 * (float)v62))) < v36 )
      {
        UpVec = bfx::GetUpVec(result: (bfx::Vec3 *)&v115);
        v63 = (float)((float)((float)v60 * UpVec->m_x) - (float)(UpVec->m_y * (float)v59));
        v64 = (float)((float)((float)v58 * UpVec->m_y) - (float)((float)v60 * UpVec->m_z));
        v62 = (float)((float)(UpVec->m_z * (float)v59) - (float)((float)v58 * UpVec->m_x));
      }
      v66 = (float)(*(float *)(LODWORD(commonState->m_y) + 8) + *(float *)&v115.m_surfer.m_areasTraversed.m_tag);
      Scale = bfx::GetScale();
      _FP4 = (float)(1.0842022e-19 - (float)((float)((float)Scale * (float)2.0) - (float)v66));
      v69 = __fsqrts((float)((float)((float)v56 * (float)v56)
                           + (float)((float)((float)v55 * (float)v55) + (float)((float)v54 * (float)v54))));
      _FP2 = (float)((float)v69 - 1.0842022e-19);
      __asm { fsel      f13, f4, f12, f6 }
      __asm { fsel      f9, f2, f1, f22 }
      v73 = (float)((float)v54 * (float)_FP9);
      v74 = (float)((float)_FP9 * (float)v55);
      v75 = (float)((float)((float)((float)Scale * (float)2.0) - (float)v69) / (float)_FP13);
      *((double *)&_FP2 + 1) = -v75;
      __asm { fsel      f27, f2, f21, f28 }
      _FP12 = (float)((float)-1.0
                    - (float)((float)((float)v74 * (float)v59)
                            + (float)((float)((float)v73 * (float)v58)
                                    + (float)((float)((float)v56 * (float)_FP9) * (float)v60))));
      _FP11 = (float)(1.0
                    - (float)((float)((float)v74 * (float)v59)
                            + (float)((float)((float)v73 * (float)v58)
                                    + (float)((float)((float)v56 * (float)_FP9) * (float)v60))));
      __asm { fsel      f10, f12, f10, f13 }
      __asm { fsel      f1, f11, f9, f0# x }
      _FP2 = acos(x: _FP2);
      _FP6 = (float)(1.0 - (float)v75);
      __asm { fsel      f2, f6, f5, f0 }
      *(double *)&_FP2 = (float)((float)-(float)((float)((float)*(double *)&_FP2 * (float)57.295776) - (float)90.0)
                               * (float)0.011111111);
      _FP12 = -*(double *)&_FP2;
      __asm { fsel      f9, f12, f21, f1 }
      _FP8 = (float)((float)__fsqrts((float)((float)((float)v64 * (float)v64)
                                           + (float)((float)((float)v63 * (float)v63) + (float)((float)v62 * (float)v62))))
                   - 1.0842022e-19);
      _FP6 = (float)(1.0 - (float)*(double *)&_FP2);
      __asm
      {
        fsel      f4, f8, f7, f22
        fsel      f3, f6, f5, f0
      }
      commonState[31].m_x = (float)((float)_FP4 * (float)v64) * (float)((float)_FP3 + (float)*((double *)&_FP2 + 1));
      commonState[31].m_y = (float)((float)v62 * (float)_FP4) * (float)((float)_FP3 + (float)*((double *)&_FP2 + 1));
      commonState[31].m_z = (float)((float)v63 * (float)_FP4) * (float)((float)_FP3 + (float)*((double *)&_FP2 + 1));
    }
  }
  else
  {
    if ( v29 >= v20 && v27 > v36 && v28 > v36 )
    {
      *(_QWORD *)&_FP2 = 0x3FE921FB60000000LL;
      _FP5 = (float)((float)__fsqrts(v26) - 1.0842022e-19);
      __asm { fsel      f2, f5, f4, f22# x }
      v91 = (float)((float)*((double *)&_FP2 + 1) * (float)v22);
      v92 = (float)((float)v24 * (float)*((double *)&_FP2 + 1));
      v93 = (float)((float)v19 * (float)*((double *)&_FP2 + 1));
      _FP9 = (float)((float)__fsqrts((float)((float)(myVel->m_z * myVel->m_z)
                                           + (float)((float)(myVel->m_x * myVel->m_x) + (float)(myVel->m_y * myVel->m_y))))
                   - 1.0842022e-19);
      __asm { fsel      f5, f9, f6, f22 }
      v96 = (float)((float)_FP5 * myVel->m_x);
      v97 = (float)(myVel->m_y * (float)_FP5);
      v98 = (float)(myVel->m_z * (float)_FP5);
      v99 = cos(x: _FP2);
      if ( (float)((float)((float)v96 * (float)v91)
                 + (float)((float)((float)v98 * (float)v93) + (float)((float)v97 * (float)v92))) > (double)(float)*(double *)&v99 )
      {
        v100 = (const bfx::MoverTune *)LODWORD(commonState->m_y);
        _FP7 = -(float)((float)((float)v29 - (float)v20)
                      / (float)((float)(v100->m_radiusData.m_radius * (float)10.0) - (float)v20));
        _FP6 = (float)(1.0
                     - (float)((float)((float)v29 - (float)v20)
                             / (float)((float)(v100->m_radiusData.m_radius * (float)10.0) - (float)v20)));
        __asm { fsel      f5, f7, f13, f8 }
        __asm { fsel      f3, f6, f4, f0 }
        commonState[30].m_z = (float)((float)_FP3 * (float)3.0) + 1.0;
        goto LABEL_39;
      }
      v36 = 0.0009765625;
    }
    v105 = (const bfx::MoverTune *)LODWORD(commonState->m_y);
    if ( v28 >= (float)(v105->m_speed * (float)0.89999998) || v27 <= v28 || v27 <= v36 || v29 >= v20 )
    {
      commonState[30].m_z = 1065353216;
    }
    else
    {
      _FP9 = -(float)((float)((float)(v105->m_speed * (float)0.89999998) - (float)v28)
                    / (float)(v105->m_speed * (float)0.89999998));
      _FP8 = (float)(1.0
                   - (float)((float)((float)(v105->m_speed * (float)0.89999998) - (float)v28)
                           / (float)(v105->m_speed * (float)0.89999998)));
      __asm { fsel      f7, f9, f13, f10 }
      __asm { fsel      f5, f8, f6, f0 }
      commonState[30].m_z = 1.0 - (float)_FP5;
    }
  }
LABEL_39:
  if ( v31 == 0 )
    commonState[31] = bfx::ZERO_VEC;
  v110 = (bfx::RepulsorImpl *)LODWORD(commonState[8].m_x);
  m_startupBulk = p_m_followerTune->m_startupBulk;
  commonState[29].m_x = p_m_followerTune->m_startupBulk;
  if ( v110 != nullptr )
    v110->m_bulk = *(float *)(LODWORD(commonState->m_y) + 20) * (float)m_startupBulk;
}


// ========================================================================
// ?CalcOrganicPos@bfx@@YA?AVVec3@1@ABVDatabaseRecord@FollowerLeaderDatabase@1@ABV21@1MM@Z
// EA  : 0x832B3240
// RVA : 0x012B3240
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollower.cpp
// ========================================================================

bfx::Vec3 *__fastcall bfx::CalcOrganicPos(
        bfx::Vec3 *result,
        const bfx::FollowerLeaderDatabase::DatabaseRecord *curFollower,
        const bfx::Vec3 *flockCenter,
        const bfx::Vec3 *leaderPos,
        double radiusMax,
        double radiusMin)
{
  bfx::HandleTargetBase *m_pTarget; // r11
  bfx::HandleTargetBase *v13; // r11
  double v14; // fp6
  bfx::HandleProxy *m_pProxy; // r11
  bool v16; // cr58
  double v19; // fp3
  bfx::HandleTargetBase *v20; // r31
  __int64 v21; // r10
  double v22; // fp13
  double v23; // fp30
  double v24; // fp31
  bfx::Quat *v25; // r3
  double m_y; // fp6
  double m_z; // fp5
  double v29; // fp0
  double v30; // fp13
  bfx::Quat v31; // [sp+50h] [-A0h] BYREF
  float v32; // [sp+60h] [-90h] BYREF
  float v33; // [sp+64h] [-8Ch]
  float v34; // [sp+68h] [-88h]
  bfx::Vec3 v35; // [sp+70h] [-80h] BYREF
  bfx::Vec3 v36; // [sp+80h] [-70h] BYREF
  _BYTE v37[16]; // [sp+90h] [-60h] BYREF
  bfx::Quat v38; // [sp+A0h] [-50h] BYREF

  if ( curFollower->m_mover.m_pProxy != nullptr )
    m_pTarget = curFollower->m_mover.m_pProxy->m_pTarget;
  else
    m_pTarget = nullptr;
  (*((void (__fastcall **)(_BYTE *))m_pTarget[97].dtr_HandleTargetBase + 6))(a1: v37);
  if ( curFollower->m_mover.m_pProxy != nullptr )
    v13 = curFollower->m_mover.m_pProxy->m_pTarget;
  else
    v13 = nullptr;
  (*((void (__fastcall **)(float *))v13[97].dtr_HandleTargetBase + 6))(a1: &v32);
  v14 = (float)(v34 - flockCenter->m_z);
  m_pProxy = curFollower->m_mover.m_pProxy;
  v16 = curFollower->m_mover.m_pProxy == nullptr;
  _FP8 = (float)((float)__fsqrts((float)((float)((float)(v32 - flockCenter->m_x) * (float)(v32 - flockCenter->m_x))
                                       + (float)((float)((float)(v34 - flockCenter->m_z)
                                                       * (float)(v34 - flockCenter->m_z))
                                               + (float)((float)(v33 - flockCenter->m_y)
                                                       * (float)(v33 - flockCenter->m_y)))))
               - (float)1.0842022e-19);
  __asm { fsel      f5, f8, f7, f12 }
  v19 = (float)((float)(v33 - flockCenter->m_y) * (float)_FP5);
  v35.m_x = (float)(v32 - flockCenter->m_x) * (float)_FP5;
  v35.m_y = v19;
  v35.m_z = (float)v14 * (float)_FP5;
  if ( v16 )
    v20 = nullptr;
  else
    v20 = m_pProxy->m_pTarget;
  LODWORD(v21) = bfx::CalcRandFromSeed(seedNum: (__int16)v20[93].__vftable);
  v22 = (float)((float)radiusMax - (float)radiusMin);
  v20[93].__vftable = (bfx::HandleTargetBase_vtbl *)v21;
  *(_QWORD *)&v31.m_w = v21;
  v23 = (float)((float)v21 * (float)0.000015258789);
  v24 = (float)((float)((float)__fabs(v23) * (float)v22) + (float)radiusMin);
  bfx::GetUpVec(result: &v36);
  bfx::Quat::Quat(
    this: &v38,
    axis: &v36,
    angle: (float)((float)((float)((float)v23 * (float)40.0) - (float)20.0) * (float)0.017453292));
  v25 = bfx::Quat::Apply(this: &v31, result: &v38, v: &v35);
  m_y = leaderPos->m_y;
  m_z = leaderPos->m_z;
  v29 = (float)(v25->m_x * (float)v24);
  v30 = (float)(v25->m_y * (float)v24);
  result->m_x = leaderPos->m_x + (float)(v25->m_w * (float)v24);
  result->m_y = (float)m_y + (float)v29;
  result->m_z = (float)m_z + (float)v30;
  return result;
}


// ========================================================================
// ?CalcGatherNearPos@bfx@@YA?AVVec3@1@ABVDatabaseRecord@FollowerLeaderDatabase@1@ABV21@PAVMoverImpl@1@MM@Z
// EA  : 0x832B3428
// RVA : 0x012B3428
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollower.cpp
// ========================================================================

bfx::Vec3 *__fastcall bfx::CalcGatherNearPos(
        bfx::Vec3 *result,
        const bfx::FollowerLeaderDatabase::DatabaseRecord *curFollower,
        const bfx::Vec3 *flockCenter,
        bfx::MoverImpl *pLeader,
        double radiusMax,
        double radiusMin)
{
  bfx::HandleTargetBase *m_pTarget; // r11
  double v13; // fp26
  double v14; // fp25
  double v15; // fp24
  bfx::HandleTargetBase *v16; // r11
  double v19; // fp30
  double v20; // fp29
  double v21; // fp28
  bfx::HandleTargetBase *v22; // r31
  __int64 v23; // r10
  double v24; // fp11
  double v25; // fp31
  double v26; // fp30
  double v27; // fp29
  double v29; // fp10
  double v30; // fp9
  float v31[4]; // [sp+58h] [-B8h] BYREF
  float v32[4]; // [sp+68h] [-A8h] BYREF
  float v33; // [sp+78h] [-98h] BYREF
  float v34; // [sp+7Ch] [-94h]
  float v35; // [sp+80h] [-90h]
  float v36[24]; // [sp+88h] [-88h] BYREF

  if ( curFollower->m_mover.m_pProxy != nullptr )
    m_pTarget = curFollower->m_mover.m_pProxy->m_pTarget;
  else
    m_pTarget = nullptr;
  (*((void (__fastcall **)(float *))m_pTarget[97].dtr_HandleTargetBase + 6))(a1: v32);
  ((void (__fastcall *)(float *))pLeader->m_behavior.m_pCurMotion->GetPos)(a1: v31);
  v13 = (float)(v31[0] - v32[0]);
  v14 = (float)(v31[1] - v32[1]);
  v15 = (float)(v31[2] - v32[2]);
  if ( curFollower->m_mover.m_pProxy != nullptr )
    v16 = curFollower->m_mover.m_pProxy->m_pTarget;
  else
    v16 = nullptr;
  (*((void (__fastcall **)(float *))v16[97].dtr_HandleTargetBase + 6))(a1: &v33);
  _FP11 = (float)((float)__fsqrts((float)((float)((float)(v33 - flockCenter->m_x) * (float)(v33 - flockCenter->m_x))
                                        + (float)((float)((float)(v35 - flockCenter->m_z)
                                                        * (float)(v35 - flockCenter->m_z))
                                                + (float)((float)(v34 - flockCenter->m_y)
                                                        * (float)(v34 - flockCenter->m_y)))))
                - (float)1.0842022e-19);
  __asm { fsel      f8, f11, f9, f31 }
  v19 = (float)((float)(v33 - flockCenter->m_x) * (float)_FP8);
  v20 = (float)((float)(v34 - flockCenter->m_y) * (float)_FP8);
  v21 = (float)((float)(v35 - flockCenter->m_z) * (float)_FP8);
  if ( curFollower->m_mover.m_pProxy != nullptr )
    v22 = curFollower->m_mover.m_pProxy->m_pTarget;
  else
    v22 = nullptr;
  LODWORD(v23) = bfx::CalcRandFromSeed(seedNum: (__int16)v22[93].__vftable);
  v22[93].__vftable = (bfx::HandleTargetBase_vtbl *)v23;
  v24 = __fabs((float)((float)v23 * (float)0.000015258789));
  if ( (float)((float)((float)(pLeader->m_commonState.m_slowTime * pLeader->m_vel.m_x) * (float)v13)
             + (float)((float)((float)(pLeader->m_vel.m_z * pLeader->m_commonState.m_slowTime) * (float)v15)
                     + (float)((float)(pLeader->m_vel.m_y * pLeader->m_commonState.m_slowTime) * (float)v14))) < 0.0 )
  {
    v19 = -v19;
    v20 = -v20;
    v21 = -v21;
  }
  v25 = (float)((float)v19
              * (float)((float)((float)v24 * (float)((float)radiusMax - (float)radiusMin)) + (float)radiusMin));
  v26 = (float)((float)v20
              * (float)((float)((float)v24 * (float)((float)radiusMax - (float)radiusMin)) + (float)radiusMin));
  v27 = (float)((float)v21
              * (float)((float)((float)v24 * (float)((float)radiusMax - (float)radiusMin)) + (float)radiusMin));
  ((void (__fastcall *)(float *))pLeader->m_behavior.m_pCurMotion->GetPos)(a1: v36);
  v29 = (float)(v36[1] + (float)v26);
  v30 = (float)(v36[2] + (float)v27);
  result->m_x = (float)v25 + v36[0];
  result->m_y = v29;
  result->m_z = v30;
  return result;
}


// ========================================================================
// ?Update@FollowData@MotionState@bfx@@QAAXM@Z
// EA  : 0x832B3640
// RVA : 0x012B3640
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollower.cpp
// ========================================================================

void __fastcall bfx::MotionState::FollowData::Update(bfx::MotionState::FollowData *this, double simTime)
{
  double v2; // fp13
  double v3; // fp13
  bfx::HandleProxy *m_pProxy; // r11
  float *m_pTarget; // r11
  double v6; // fp12
  double v7; // fp10
  double v8; // fp8

  if ( this->m_millAroundCountdown > 0.0 )
  {
    v2 = (float)(this->m_millAroundCountdown - (float)simTime);
    this->m_millAroundCountdown = this->m_millAroundCountdown - (float)simTime;
    if ( v2 < 0.0 )
      this->m_millAroundCountdown = 0.0;
  }
  if ( this->m_sidePushCountdown > 0.0 )
  {
    v3 = (float)(this->m_sidePushCountdown - (float)simTime);
    this->m_sidePushCountdown = this->m_sidePushCountdown - (float)simTime;
    if ( v3 < 0.0 )
      this->m_sidePushCountdown = 0.0;
  }
  m_pProxy = this->m_targetMover.m_pProxy;
  if ( m_pProxy != nullptr )
  {
    m_pTarget = (float *)m_pProxy->m_pTarget;
    if ( m_pTarget != nullptr )
    {
      v6 = (float)(m_pTarget[265] * m_pTarget[174]);
      v7 = (float)(m_pTarget[263] * m_pTarget[174]);
      v8 = (float)(m_pTarget[264] * m_pTarget[174]);
      this->m_leadersPrevSpeed = __fsqrts((float)((float)((float)v8 * (float)v8)
                                                + (float)((float)((float)v7 * (float)v7) + (float)((float)v6 * (float)v6))));
    }
  }
}


// ========================================================================
// ?IsMillingAround@FollowData@MotionState@bfx@@QAA_NXZ
// EA  : 0x832B36D8
// RVA : 0x012B36D8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollower.cpp
// ========================================================================

int __fastcall bfx::MotionState::FollowData::IsMillingAround(bfx::MotionState::FollowData *this)
{
  bfx::HandleProxy *m_pProxy; // r11
  double m_millAroundCountdown; // fp13
  int result; // r3

  m_pProxy = this->m_targetMover.m_pProxy;
  if ( m_pProxy == nullptr )
    return 0;
  if ( m_pProxy->m_pTarget == nullptr )
    return 0;
  m_millAroundCountdown = this->m_millAroundCountdown;
  result = 1;
  if ( m_millAroundCountdown <= 0.0 )
    return 0;
  return result;
}


// ========================================================================
// ?CalcMillingAroundForce@FollowData@MotionState@bfx@@QAA?AVVec3@3@XZ
// EA  : 0x832B3710
// RVA : 0x012B3710
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollower.cpp
// ========================================================================

bfx::MotionState::FollowData *__fastcall bfx::MotionState::FollowData::CalcMillingAroundForce(
        bfx::MotionState::FollowData *this,
        bfx::Vec3 *result)
{
  float m_x; // r11
  float *v3; // r11
  float m_y; // r8
  float m_z; // r7
  double v6; // fp9
  double v7; // fp8

  m_x = result[2].m_x;
  if ( m_x != 0.0 && (v3 = *(float **)LODWORD(m_x)) != nullptr )
  {
    v6 = (float)(v3[264] * v3[174]);
    v7 = (float)(v3[265] * v3[174]);
    this->m_millAroundCountdown = (float)(v3[263] * v3[174]) * (float)0.75;
    this->m_sidePushCountdown = (float)v6 * (float)0.75;
    this->m_bulkScale = (float)v7 * (float)0.75;
  }
  else
  {
    m_y = bfx::ZERO_VEC.m_y;
    m_z = bfx::ZERO_VEC.m_z;
    this->m_millAroundCountdown = bfx::ZERO_VEC.m_x;
    this->m_sidePushCountdown = m_y;
    this->m_bulkScale = m_z;
  }
  return this;
}


// ========================================================================
// ?DebugDrawRank@FollowData@MotionState@bfx@@QBAXPAVSpace@3@ABVVec3@3@@Z
// EA  : 0x832B3790
// RVA : 0x012B3790
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollower.cpp
// ========================================================================

void __fastcall bfx::MotionState::FollowData::DebugDrawRank(
        bfx::MotionState::FollowData *this,
        bfx::Vector3 *pSpace,
        const bfx::Vec3 *pos)
{
  bfx::HandleProxy *m_pProxy; // r11
  bfx::HandleTargetBase *m_pTarget; // r11
  double Scale; // fp31
  __int64 v9; // r10
  __int64 v10; // r8
  bfx::Vec3 *UpVec; // r3
  bfx::HandleProxy *v12; // r11
  double m_z; // fp11
  double v14; // fp2
  double v15; // fp0
  bfx::HandleTargetBase *v16; // r11
  __int64 v17; // r6
  int v18; // [sp+8h] [-98h]
  int v19; // [sp+Ch] [-94h]
  int v20; // [sp+10h] [-90h]
  int v21; // [sp+14h] [-8Ch]
  int v22; // [sp+18h] [-88h]
  int v23; // [sp+1Ch] [-84h]
  int v24; // [sp+20h] [-80h]
  int v25; // [sp+24h] [-7Ch]
  bfx::Vec3 v26; // [sp+50h] [-50h] BYREF
  bfx::Vec3 v27[2]; // [sp+60h] [-40h] BYREF

  m_pProxy = this->m_targetMover.m_pProxy;
  if ( m_pProxy != nullptr )
    m_pTarget = m_pProxy->m_pTarget;
  else
    m_pTarget = nullptr;
  if ( m_pTarget[146].m_pProxy != nullptr )
  {
    Scale = bfx::GetScale();
    UpVec = bfx::GetUpVec(result: v27);
    v12 = this->m_targetMover.m_pProxy;
    m_z = pos->m_z;
    v14 = (float)((float)(UpVec->m_z * (float)Scale) * (float)0.5);
    v15 = (float)(pos->m_y + (float)((float)(UpVec->m_y * (float)Scale) * (float)0.5));
    v26.m_x = pos->m_x + (float)((float)(UpVec->m_x * (float)Scale) * (float)0.5);
    v26.m_y = v15;
    v26.m_z = (float)m_z + (float)v14;
    if ( v12 != nullptr )
      v16 = v12->m_pTarget;
    else
      v16 = nullptr;
    if ( v16[146].m_pProxy[2].m_pTarget == nullptr )
    {
      LODWORD(v9) = &dword_82420000;
      HIDWORD(v10) = this->m_dbgRank;
      HIDWORD(v17) = "rank %c-%d";
      LODWORD(v17) = this->m_dbgRing + 65;
      bfx::DrawString(
        pSpace,
        inputPos: &v26,
        fmt: v17,
        a4: v10,
        a5: v9,
        a6: v18,
        a7: v19,
        a8: v20,
        a9: v21,
        a10: v22,
        a11: v23,
        a12: v24,
        a13: v25);
    }
  }
}


// ========================================================================
// ?GetFlockInfo@MoverImpl@bfx@@AAAXV?$Array@PAVRepulsorImpl@bfx@@@2@AAVVec3@2@AAH@Z
// EA  : 0x832B3890
// RVA : 0x012B3890
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollower.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::GetFlockInfo(
        bfx::MoverImpl *this,
        const bfx::Array<bfx::RepulsorImpl *> *nearbyRepulsors,
        bfx::Vec3 *flockCenter,
        int *numInFlock)
{
  bfx::MotionBase *m_pCurMotion; // r4
  bfx::MotionBase_vtbl *v9; // r9
  bfx::Vec3 *(__fastcall *GetPos)(bfx::MotionBase *, bfx::Vec3 *); // r8
  bfx::RepulsorImpl **i; // r28
  bfx::RepulsorOwner *m_pOwner; // r11
  int v13; // r3
  int v14; // r30
  _DWORD *v15; // r11
  bfx::HandleTargetBase *v17; // r9
  bfx::HandleProxy *m_pProxy; // r11
  bfx::HandleTargetBase *v20; // r11
  double v33; // fp12
  double v34; // fp11
  double v35; // fp4
  double v36; // fp3
  char *m_data; // r4
  float v38; // [sp+58h] [-C8h] BYREF
  float v39; // [sp+5Ch] [-C4h]
  float v40; // [sp+60h] [-C0h]
  float v41; // [sp+68h] [-B8h] BYREF
  float v42; // [sp+6Ch] [-B4h]
  float v43; // [sp+70h] [-B0h]
  float v44; // [sp+78h] [-A8h] BYREF
  float v45[4]; // [sp+88h] [-98h] BYREF
  float v46[4]; // [sp+98h] [-88h] BYREF
  float v47; // [sp+A8h] [-78h] BYREF
  float v48[4]; // [sp+B8h] [-68h] BYREF
  float v49[22]; // [sp+C8h] [-58h] BYREF

  m_pCurMotion = this->m_behavior.m_pCurMotion;
  flockCenter->m_x = bfx::ZERO_VEC.m_x;
  v9 = m_pCurMotion->__vftable;
  flockCenter->m_y = bfx::ZERO_VEC.m_y;
  GetPos = v9->GetPos;
  flockCenter->m_z = bfx::ZERO_VEC.m_z;
  ((void (__fastcall *)(float *))GetPos)(a1: &v38);
  ((void (__fastcall *)(float *))this->m_behavior.m_pCurMotion->GetPos)(a1: &v41);
  *numInFlock = 1;
  for ( i = nearbyRepulsors->m_data; i != &nearbyRepulsors->m_data[nearbyRepulsors->m_size]; ++i )
  {
    m_pOwner = (*i)->m_pOwner;
    if ( m_pOwner != nullptr && m_pOwner->m_creatorType == REPULSOR_CREATOR_MOVER )
    {
      v13 = (int)(*i)->m_pOwner->GetRepulsorOwner(this: (*i)->m_pOwner);
      v14 = v13;
      if ( v13 != 0 )
      {
        v15 = *(_DWORD **)(v13 + 668);
        if ( v15 != nullptr && *v15 != 0 )
          v17 = v15 != nullptr ? (bfx::HandleTargetBase *)*v15 : nullptr;
        else
          v17 = nullptr;
        m_pProxy = this->m_commonState.m_followData.m_targetMover.m_pProxy;
        if ( m_pProxy != nullptr && m_pProxy->m_pTarget != nullptr )
          v20 = m_pProxy != nullptr ? m_pProxy->m_pTarget : nullptr;
        else
          v20 = nullptr;
        if ( v17 == v20 )
        {
          (*(void (__fastcall **)(float *))(**(_DWORD **)(v13 + 776) + 24))(a1: &v44);
          _FP12 = (float)(v38 - v44);
          __asm { fsel      f11, f12, f13, f0 }
          v38 = _FP11;
          (*(void (__fastcall **)(float *))(**(_DWORD **)(v14 + 776) + 24))(a1: v45);
          _FP10 = (float)(v39 - v45[1]);
          __asm { fsel      f9, f10, f13, f0 }
          v39 = _FP9;
          (*(void (__fastcall **)(float *))(**(_DWORD **)(v14 + 776) + 24))(a1: v46);
          _FP8 = (float)(v40 - v46[2]);
          __asm { fsel      f7, f8, f13, f0 }
          v40 = _FP7;
          (*(void (__fastcall **)(float *))(**(_DWORD **)(v14 + 776) + 24))(a1: &v47);
          _FP6 = (float)(v41 - v47);
          __asm { fsel      f5, f6, f0, f13 }
          v41 = _FP5;
          (*(void (__fastcall **)(float *))(**(_DWORD **)(v14 + 776) + 24))(a1: v48);
          _FP4 = (float)(v42 - v48[1]);
          __asm { fsel      f3, f4, f0, f13 }
          v42 = _FP3;
          (*(void (__fastcall **)(float *))(**(_DWORD **)(v14 + 776) + 24))(a1: v49);
          _FP2 = (float)(v43 - v49[2]);
          ++*numInFlock;
          __asm { fsel      f1, f2, f0, f13 }
          v43 = _FP1;
        }
      }
    }
  }
  v33 = v40;
  v34 = v39;
  v35 = (float)((float)(v42 - v39) * (float)0.5);
  v36 = (float)((float)(v43 - v40) * (float)0.5);
  flockCenter->m_x = (float)((float)(v41 - v38) * (float)0.5) + v38;
  flockCenter->m_y = (float)v35 + (float)v34;
  flockCenter->m_z = (float)v33 + (float)v36;
  m_data = (char *)nearbyRepulsors->m_data;
  nearbyRepulsors->m_size = 0;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    nearbyRepulsors->m_data = nullptr;
  }
  nearbyRepulsors->m_cap = 0;
}


// ========================================================================
// __unwind$30436
// EA  : 0x832B3BD8
// RVA : 0x012B3BD8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollower.cpp
// ========================================================================

void _unwind_30436()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: *(bfx::Array<bfx::SpaceComponent *> **)(v0 - 288 + 316));
}


// ========================================================================
// ?FindFollower@FollowerLeaderDatabase@bfx@@QBAPBVDatabaseRecord@12@PBVMoverImpl@2@@Z
// EA  : 0x832B3C00
// RVA : 0x012B3C00
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollower.cpp
// ========================================================================

const bfx::FollowerLeaderDatabase::DatabaseRecord *__fastcall bfx::FollowerLeaderDatabase::FindFollower(
        bfx::FollowerLeaderDatabase *this,
        const bfx::MoverImpl *pMover)
{
  const bfx::FollowerLeaderDatabase::DatabaseRecord *result; // r3
  const bfx::FollowerLeaderDatabase::DatabaseRecord *v3; // r9
  bfx::HandleProxy *m_pProxy; // r11
  const bfx::MoverImpl *v6; // r11

  v3 = &this->m_entries.m_data[this->m_entries.m_size];
  result = this->m_entries.m_data;
  if ( result == v3 )
    return nullptr;
  while ( 1 )
  {
    m_pProxy = result->m_mover.m_pProxy;
    if ( result->m_mover.m_pProxy != nullptr && m_pProxy->m_pTarget != nullptr )
    {
      v6 = m_pProxy != nullptr ? (const bfx::MoverImpl *)m_pProxy->m_pTarget : nullptr;
      if ( v6 == pMover )
        break;
    }
    if ( ++result == v3 )
      return nullptr;
  }
  return result;
}


// ========================================================================
// ?CalculateFollowMoverPositions@MoverImpl@bfx@@AAAXM@Z
// EA  : 0x832B3E28
// RVA : 0x012B3E28
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollower.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::CalculateFollowMoverPositions(bfx::MoverImpl *this, double simTime)
{
  bfx::FollowerLeaderDatabase *m_pLeaderDatabase; // r26
  long double v5; // fp2
  bfx::FMSpec *p_m_spec; // r21
  bfx::FollowMoverSpec::Formation m_formation; // r11
  char *v8; // r29
  char *v9; // r22
  double m_slowTime; // fp0
  double v11; // fp12
  double v12; // fp9
  double v13; // fp13
  double v14; // fp8
  double m_z; // fp11
  double v16; // fp7
  bfx::Vec3 *p_m_vel; // r16
  double v18; // fp12
  float *Forward; // r3
  double v22; // fp10
  double v23; // fp9
  bfx::FollowerLeaderDatabase::DatabaseRecord *v24; // r30
  bfx::HandleProxy *v25; // r11
  bool v26; // r10
  bfx::HandleTargetBase *m_pTarget; // r10
  double v28; // fp31
  bfx::HandleTargetBase *v29; // r10
  int v30; // r30
  char *v31; // r17
  bfx::EndPt *v32; // r19
  int v33; // r20
  double v34; // fp25
  double v35; // fp31
  int v36; // r11
  int v37; // r21
  unsigned int v38; // r30
  int i; // r30
  __int64 v40; // r10
  double v41; // fp0
  double v42; // fp12
  double v43; // fp8
  double v44; // fp11
  double v45; // fp7
  double v46; // fp5
  double v47; // fp10
  bfx::Orienter *LocalUpAxis; // r3
  __int64 v51; // r11
  bfx::Quat *v52; // r3
  int v53; // r28
  double v54; // fp9
  double v55; // fp8
  char *v56; // r29
  float v57; // r27
  float v58; // r26
  float v59; // r25
  float v60; // r24
  float *v61; // r30
  bfx::Orienter *v62; // r3
  bfx::Quat *v63; // r3
  double v64; // fp6
  double v65; // fp4
  double v66; // fp3
  double v67; // fp11
  double v68; // fp10
  char *v69; // r4
  bfx::MemoryManager *m_pMemoryManager; // r3
  double v71; // fp11
  double v72; // fp9
  double v73; // fp8
  double v74; // fp28
  double v75; // fp30
  double v76; // fp29
  const bfx::Array<bfx::RepulsorImpl *> *v77; // r3
  char v78; // r3
  int m_size; // r11
  bfx::FollowerLeaderDatabase::DatabaseRecord *m_data; // r29
  bool v81; // r11
  float *p_m_z; // r30
  bfx::Vec3 *v83; // r3
  int *m_pProxy; // r11
  int v85; // r10
  int v86; // r27
  int v87; // r28
  int v88; // r3
  __int64 v89; // r11
  double v90; // fp0
  bfx::Vec3 *v91; // r3
  bfx::FMSpec *v92; // r23
  int v93; // r30
  int *v94; // r11
  int **v95; // r27
  bool v96; // r10
  int v97; // r10
  int v98; // r11
  double v99; // fp13
  bfx::Vec3 *v100; // r3
  int *v101; // r10
  int v102; // r11
  int v103; // r28
  double v104; // fp0
  int v105; // r11
  bfx::Vec3 *v106; // r3
  int v107; // r29
  int v108; // r3
  __int64 v109; // r11
  double v110; // fp0
  bfx::Vec3 *v111; // r3
  double m_y; // fp10
  double v113; // fp13
  double m_x; // fp9
  double v115; // fp12
  double v116; // fp0
  double v117; // fp6
  double v118; // fp2
  double v119; // fp8
  double m_radius; // fp6
  double v123; // fp0
  double v124; // fp11
  double v125; // fp10
  float v126; // [sp+50h] [-240h] BYREF
  int v127; // [sp+54h] [-23Ch]
  bfx::Vec3 v128; // [sp+58h] [-238h] BYREF
  bfx::Vec3 v129; // [sp+68h] [-228h] BYREF
  bfx::Vec3 v130; // [sp+78h] [-218h] BYREF
  bfx::FMSpec *v131; // [sp+84h] [-20Ch]
  bfx::Array<bfx::EndPt> v132; // [sp+90h] [-200h] BYREF
  bfx::EndPt v133; // [sp+A0h] [-1F0h] BYREF
  bfx::Array<bfx::EndPt> v134; // [sp+B0h] [-1E0h] BYREF
  bfx::Array<bfx::SpaceComponent *> v135; // [sp+C0h] [-1D0h] BYREF
  bfx::Orienter v136; // [sp+D0h] [-1C0h] BYREF

  m_pLeaderDatabase = this->m_pLeaderDatabase;
  if ( m_pLeaderDatabase == nullptr )
    return;
  ((void (__fastcall *)(bfx::Vec3 *))this->m_behavior.m_pCurMotion->GetPos)(a1: &v129);
  p_m_spec = &m_pLeaderDatabase->m_spec;
  v131 = &m_pLeaderDatabase->m_spec;
  m_formation = m_pLeaderDatabase->m_spec.m_formation;
  if ( m_formation != CIRCLE )
  {
    if ( m_formation != ORGANIC_BLOB )
      return;
    v71 = (float)(this->m_vel.m_x * this->m_commonState.m_slowTime);
    v72 = (float)(this->m_vel.m_z * this->m_commonState.m_slowTime);
    v73 = (float)(this->m_vel.m_y * this->m_commonState.m_slowTime);
    memset(&v135, 0, 12);
    v135.m_tag = MEM_TEMP;
    v74 = (float)((float)v71 * (float)simTime);
    v75 = (float)((float)v72 * (float)simTime);
    v76 = (float)((float)v73 * (float)simTime);
    bfx::Repulsor3DImpl::GetNearbyRepulsors(
      this: this->m_commonState.m_pRepulsor,
      nearbyRepulsors: &v135,
      filterBasedOnBlockageFlags: true);
    v77 = (const bfx::Array<bfx::RepulsorImpl *> *)bfx::Array<bfx::RepulsorImpl *>::Array<bfx::RepulsorImpl *>(
                                                     this: (bfx::Array<bfx::Area *> *)&v136.m_targetPos.m_y,
                                                     rhs: (const bfx::Array<bfx::Area *> *)&v135);
    bfx::MoverImpl::GetFlockInfo(this, nearbyRepulsors: v77, flockCenter: &v128, numInFlock: (int *)&v126);
    v78 = bfx::MoverImpl::LeaderIsNearGoal(this);
    m_size = m_pLeaderDatabase->m_entries.m_size;
    m_data = m_pLeaderDatabase->m_entries.m_data;
    m_pLeaderDatabase->m_leaderIsCloseToGoal = v78;
    if ( m_data != &m_data[m_size] )
    {
      do
      {
        if ( m_data->m_mover.m_pProxy != nullptr )
        {
          v81 = m_data->m_mover.m_pProxy->m_pTarget != nullptr;
          v126 = *(float *)&m_data->m_mover.m_pProxy;
        }
        else
        {
          v81 = false;
        }
        if ( v81 )
        {
          p_m_z = &m_data->m_pos.m_z;
          if ( m_data->m_state == UNINITIALIZED )
          {
            m_data->m_state = 1;
            v83 = bfx::CalcOrganicPos(
                    result: (bfx::Vec3 *)&v136.m_headingFrameMatrix.m_data[9],
                    curFollower: m_data,
                    flockCenter: &v128,
                    leaderPos: &v129,
                    radiusMax: m_pLeaderDatabase->m_spec.m_radius,
                    radiusMin: (float)(this->m_commonState.m_pTune->m_radiusData.m_radius * (float)2.0));
            m_data->m_pos.m_x = v83->m_x;
            m_data->m_pos.m_y = v83->m_y;
            *p_m_z = v83->m_z;
            m_pProxy = (int *)m_data->m_mover.m_pProxy;
            if ( m_data->m_mover.m_pProxy != nullptr )
            {
              v85 = *m_pProxy;
              v126 = *(float *)&m_data->m_mover.m_pProxy;
            }
            else
            {
              v85 = 0;
            }
            v86 = *(_DWORD *)(v85 + 308);
            if ( *(_BYTE *)(v86 + 252) != 0 )
            {
              if ( *(float *)&m_pProxy == 0.0 )
              {
                *(float *)&v87 = 0.0;
              }
              else
              {
                v87 = *m_pProxy;
                v126 = *(float *)&m_pProxy;
              }
              v88 = *(_DWORD *)(v87 + 744);
              v126 = *(float *)&v87;
              LODWORD(v89) = bfx::CalcRandFromSeed(seedNum: v88);
              *(_DWORD *)(v87 + 744) = v89;
              v90 = *(float *)(v86 + 256);
              *(_QWORD *)&v130.m_x = v89;
              m_data->m_countDown = (float)((float)(*(float *)(v86 + 260) - (float)v90)
                                          * (float)((float)v89 * (float)0.000015258789))
                                  + (float)v90;
              v91 = bfx::CalcOrganicPos(
                      result: (bfx::Vec3 *)&v136.m_headingFrameMatrix.m_data[13],
                      curFollower: m_data,
                      flockCenter: &v128,
                      leaderPos: &v129,
                      radiusMax: m_pLeaderDatabase->m_spec.m_radius,
                      radiusMin: (float)(this->m_commonState.m_pTune->m_radiusData.m_radius * (float)2.0));
              m_data->m_pos.m_x = v91->m_x;
              m_data->m_pos.m_y = v91->m_y;
              *p_m_z = v91->m_z;
            }
          }
        }
        ++m_data;
      }
      while ( m_data != &m_pLeaderDatabase->m_entries.m_data[m_pLeaderDatabase->m_entries.m_size] );
    }
    if ( m_pLeaderDatabase->m_entries.m_data == &m_pLeaderDatabase->m_entries.m_data[m_pLeaderDatabase->m_entries.m_size] )
    {
LABEL_99:
      v69 = (char *)v135.m_data;
      v135.m_size = 0;
      if ( v135.m_data == nullptr )
        return;
      m_pMemoryManager = bfx::g_pCurInstance->m_pMemoryManager;
      goto LABEL_101;
    }
    v92 = v131;
    v93 = (int)&m_pLeaderDatabase->m_entries.m_data->m_pos.m_z;
    while ( 1 )
    {
      v94 = *(int **)(v93 - 12);
      v95 = (int **)(v93 - 12);
      if ( *(float *)&v94 == 0.0 )
      {
        v96 = false;
      }
      else
      {
        v96 = *v94 != 0;
        v126 = *(float *)(v93 - 12);
      }
      if ( !v96 )
        goto LABEL_98;
      if ( *(float *)&v94 == 0.0 )
      {
        v97 = 0;
      }
      else
      {
        v97 = *v94;
        v126 = *(float *)&v94;
      }
      (*(void (__fastcall **)(float *))(**(_DWORD **)(v97 + 776) + 24))(a1: &v136.m_headingVel);
      v98 = *(_DWORD *)(v93 + 4);
      v99 = __fsqrts((float)((float)((float)(v129.m_z - v136.m_clientSpecifiedRotSpeed)
                                   * (float)(v129.m_z - v136.m_clientSpecifiedRotSpeed))
                           + (float)((float)((float)(v129.m_x - v136.m_headingVel)
                                           * (float)(v129.m_x - v136.m_headingVel))
                                   + (float)((float)(v129.m_y - *(float *)&v136.m_accelMode)
                                           * (float)(v129.m_y - *(float *)&v136.m_accelMode)))));
      if ( m_pLeaderDatabase->m_leaderIsCloseToGoal )
        break;
      if ( v98 == 3 )
        *(_DWORD *)(v93 + 4) = 1;
      v101 = *v95;
      if ( *v95 != nullptr )
      {
        v102 = *v101;
        v126 = *(float *)v95;
      }
      else
      {
        v102 = 0;
      }
      v103 = *(_DWORD *)(v102 + 308);
      if ( *(float *)(v93 + 8) > 0.0 )
      {
        v104 = (float)(*(float *)(v93 + 8) - (float)simTime);
        *(float *)(v93 + 8) = *(float *)(v93 + 8) - (float)simTime;
        if ( v104 <= 0.0 )
          *(float *)(v93 + 8) = 0.0;
      }
      v105 = *(_DWORD *)(v93 + 4);
      if ( v105 == 1 )
      {
        if ( v99 <= (float)(v92->m_radius * (float)1.1) )
        {
          if ( *(_BYTE *)(v103 + 252) != 0 && *(float *)(v93 + 8) == 0.0 )
          {
            if ( *(float *)&v101 == 0.0 )
            {
              *(float *)&v107 = 0.0;
            }
            else
            {
              v107 = *v101;
              v126 = *(float *)&v101;
            }
            v108 = *(_DWORD *)(v107 + 744);
            v126 = *(float *)&v107;
            LODWORD(v109) = bfx::CalcRandFromSeed(seedNum: v108);
            *(_DWORD *)(v107 + 744) = v109;
            v110 = *(float *)(v103 + 260);
            *(_QWORD *)&v130.m_x = v109;
            *(float *)(v93 + 8) = (float)((float)((float)v110 - *(float *)(v103 + 256))
                                        * (float)((float)v109 * (float)0.000015258789))
                                + *(float *)(v103 + 256);
            v111 = bfx::CalcOrganicPos(
                     result: (bfx::Vec3 *)&v136.m_dir.m_z,
                     curFollower: (const bfx::FollowerLeaderDatabase::DatabaseRecord *)(v93 - 12),
                     flockCenter: &v128,
                     leaderPos: &v129,
                     radiusMax: v92->m_radius,
                     radiusMin: (float)(this->m_commonState.m_pTune->m_radiusData.m_radius * (float)2.0));
            *(float *)(v93 - 8) = v111->m_x;
            *(float *)(v93 - 4) = v111->m_y;
            *(float *)v93 = v111->m_z;
          }
          goto LABEL_97;
        }
        *(_DWORD *)(v93 + 4) = 2;
        *(float *)(v93 + 8) = 0.0;
        v106 = bfx::CalcOrganicPos(
                 result: (bfx::Vec3 *)&v136.m_headingFrameMatrix.m_data[13],
                 curFollower: (const bfx::FollowerLeaderDatabase::DatabaseRecord *)(v93 - 12),
                 flockCenter: &v128,
                 leaderPos: &v129,
                 radiusMax: v92->m_radius,
                 radiusMin: (float)(this->m_commonState.m_pTune->m_radiusData.m_radius * (float)2.0));
        *(float *)(v93 - 8) = v106->m_x;
        *(float *)(v93 - 4) = v106->m_y;
        *(float *)v93 = v106->m_z;
      }
      else if ( v105 == 2 )
      {
        if ( v99 <= v92->m_radius )
          *(_DWORD *)(v93 + 4) = 1;
        m_y = v129.m_y;
        v113 = (float)(*(float *)(v93 - 4) - v129.m_y);
        m_x = v129.m_x;
        v115 = (float)(*(float *)(v93 - 8) - v129.m_x);
        v116 = (float)(*(float *)v93 - v129.m_z);
        v117 = (float)(v92->m_radius * v92->m_radius);
        v118 = (float)((float)((float)(*(float *)v93 - v129.m_z) * (float)(*(float *)v93 - v129.m_z))
                     + (float)((float)((float)(*(float *)(v93 - 8) - v129.m_x) * (float)(*(float *)(v93 - 8) - v129.m_x))
                             + (float)((float)(*(float *)(v93 - 4) - v129.m_y) * (float)(*(float *)(v93 - 4) - v129.m_y))));
        v126 = *(float *)(v93 - 4) - v129.m_y;
        if ( v118 > v117 )
        {
          v119 = v115;
          m_radius = v92->m_radius;
          _FP2 = (float)((float)__fsqrts((float)((float)((float)v116 * (float)v116)
                                               + (float)((float)((float)v119 * (float)v119)
                                                       + (float)((float)v113 * (float)v113))))
                       - (float)1.0842022e-19);
          __asm { fsel      f12, f2, f1, f31 }
          v123 = (float)(v129.m_z + (float)((float)((float)_FP12 * (float)v116) * v92->m_radius));
          v126 = v113;
          *(float *)v93 = v123;
          *(float *)(v93 - 4) = (float)m_y + (float)((float)((float)_FP12 * (float)v113) * (float)m_radius);
          *(float *)(v93 - 8) = (float)((float)((float)_FP12 * (float)v119) * (float)m_radius) + (float)m_x;
        }
        goto LABEL_97;
      }
LABEL_98:
      v93 += 24;
      if ( (bfx::FollowerLeaderDatabase::DatabaseRecord *)(v93 - 12) == &m_pLeaderDatabase->m_entries.m_data[m_pLeaderDatabase->m_entries.m_size] )
        goto LABEL_99;
    }
    if ( v98 != 3 )
    {
      v100 = bfx::CalcGatherNearPos(
               result: (bfx::Vec3 *)&v136.m_headingFrameMatrix.m_data[9],
               curFollower: (const bfx::FollowerLeaderDatabase::DatabaseRecord *)(v93 - 12),
               flockCenter: &v128,
               pLeader: this,
               radiusMax: v92->m_radius,
               radiusMin: (float)(this->m_commonState.m_pTune->m_radiusData.m_radius * (float)2.0));
      *(float *)(v93 - 8) = v100->m_x;
      *(float *)(v93 - 4) = v100->m_y;
      *(float *)v93 = v100->m_z;
      *(_DWORD *)(v93 + 4) = 3;
      *(float *)(v93 + 8) = 0.0;
    }
LABEL_97:
    v124 = *(float *)(v93 - 8);
    v125 = (float)((float)v76 + *(float *)(v93 - 4));
    *(float *)v93 = (float)v75 + *(float *)v93;
    *(float *)(v93 - 4) = v125;
    *(float *)(v93 - 8) = (float)v124 + (float)v74;
    goto LABEL_98;
  }
  v8 = nullptr;
  v9 = nullptr;
  memset(&v132, 0, 12);
  v132.m_tag = MEM_TEMP;
  v134.m_tag = MEM_TEMP;
  memset(&v134, 0, 12);
  m_slowTime = this->m_commonState.m_slowTime;
  v11 = this->m_vel.m_y;
  v12 = (float)(this->m_vel.m_y * this->m_commonState.m_slowTime);
  v13 = this->m_vel.m_x;
  v14 = (float)(this->m_vel.m_x * this->m_commonState.m_slowTime);
  m_z = this->m_vel.m_z;
  v16 = (float)(this->m_vel.m_z * this->m_commonState.m_slowTime);
  v126 = this->m_commonState.m_slowTime;
  p_m_vel = &this->m_vel;
  if ( (float)((float)((float)v16 * (float)v16)
             + (float)((float)((float)v14 * (float)v14) + (float)((float)v12 * (float)v12))) <= 1.0842022e-19 )
  {
    Forward = (float *)bfx::Orienter::GetForward(
                         this: &v136,
                         result: (bfx::Vec3 *)&this->m_commonState.m_orienter,
                         a3: v5);
    v22 = -Forward[1];
    v23 = -*Forward;
    v128.m_z = -Forward[2];
    v128.m_y = v22;
    v128.m_x = v23;
  }
  else
  {
    v18 = (float)((float)v11 * (float)m_slowTime);
    v126 = m_slowTime;
    _FP3 = (float)((float)__fsqrts((float)((float)((float)((float)m_z * (float)m_slowTime)
                                                 * (float)((float)m_z * (float)m_slowTime))
                                         + (float)((float)((float)((float)v13 * (float)m_slowTime)
                                                         * (float)((float)v13 * (float)m_slowTime))
                                                 + (float)((float)v18 * (float)v18))))
                 - (float)1.0842022e-19);
    __asm { fsel      f1, f3, f2, f27 }
    v128.m_x = -(float)((float)((float)v13 * (float)m_slowTime) * (float)_FP1);
    v128.m_z = -(float)((float)((float)m_z * (float)m_slowTime) * (float)_FP1);
    v128.m_y = -(float)((float)v18 * (float)_FP1);
  }
  v24 = m_pLeaderDatabase->m_entries.m_data;
  if ( m_pLeaderDatabase->m_entries.m_data == &m_pLeaderDatabase->m_entries.m_data[m_pLeaderDatabase->m_entries.m_size] )
    goto LABEL_22;
  do
  {
    v25 = v24->m_mover.m_pProxy;
    if ( v24->m_mover.m_pProxy != nullptr )
    {
      v26 = v25->m_pTarget != nullptr;
      v126 = *(float *)&v24->m_mover.m_pProxy;
    }
    else
    {
      v26 = false;
    }
    if ( v26 )
    {
      if ( *(float *)&v25 == 0.0 )
      {
        m_pTarget = nullptr;
      }
      else
      {
        m_pTarget = v25->m_pTarget;
        v126 = *(float *)&v25;
      }
      (*((void (__fastcall **)(float *))m_pTarget[97].dtr_HandleTargetBase + 6))(a1: &v136.m_headingFrameMatrix.m_data[5]);
      v28 = __fsqrts((float)((float)((float)(v136.m_headingFrameMatrix.m_data[7] - v129.m_z)
                                   * (float)(v136.m_headingFrameMatrix.m_data[7] - v129.m_z))
                           + (float)((float)((float)(v136.m_headingFrameMatrix.m_data[5] - v129.m_x)
                                           * (float)(v136.m_headingFrameMatrix.m_data[5] - v129.m_x))
                                   + (float)((float)(v136.m_headingFrameMatrix.m_data[6] - v129.m_y)
                                           * (float)(v136.m_headingFrameMatrix.m_data[6] - v129.m_y)))));
      if ( v28 >= 1.0842022e-19 )
      {
        if ( v24->m_mover.m_pProxy != nullptr )
        {
          v29 = v24->m_mover.m_pProxy->m_pTarget;
          v126 = *(float *)&v24->m_mover.m_pProxy;
        }
        else
        {
          v29 = nullptr;
        }
        (*((void (__fastcall **)(float *))v29[97].dtr_HandleTargetBase + 6))(a1: &v136.m_headingFrameMatrix.m_data[1]);
        v130.m_z = (float)((float)1.0 / (float)v28) * (float)(v136.m_headingFrameMatrix.m_data[3] - v129.m_z);
        v130.m_y = (float)((float)1.0 / (float)v28) * (float)(v136.m_headingFrameMatrix.m_data[2] - v129.m_y);
        v130.m_x = (float)((float)1.0 / (float)v28) * (float)(v136.m_headingFrameMatrix.m_data[1] - v129.m_x);
        v133.m_val = bfx::AngleBetween(vForward: &v128, vOther: &v130);
        *(float *)&v133.m_pAABB = v28;
        v133.m_type = (bfx::EndPtType)v24;
        bfx::Array<bfx::FollowerBuddyData>::push_back(this: &v134, val: &v133);
      }
    }
    ++v24;
  }
  while ( v24 != &m_pLeaderDatabase->m_entries.m_data[m_pLeaderDatabase->m_entries.m_size] );
  v30 = v134.m_size;
  if ( v134.m_size == 0 )
  {
    v8 = (char *)v134.m_data;
LABEL_22:
    if ( v8 != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v8);
    return;
  }
  v31 = (char *)v134.m_data;
  v32 = v134.m_data;
  qsort(
    base: v134.m_data,
    num: v134.m_size,
    width: 0xCu,
    comp: (int (__fastcall *)(const void *, const void *))bfx::CompareFollowerBuddiesRadius);
  v33 = v30;
  v34 = (float)((float)(this->m_commonState.m_pTune->m_followerTune.m_packingPadding
                      + this->m_commonState.m_pTune->m_radiusData.m_radius)
              * (float)2.0);
  v35 = m_pLeaderDatabase->m_spec.m_radius;
  if ( v30 > 0 )
  {
    while ( 1 )
    {
      v127 = (int)(float)((float)((float)((float)v35 * p_m_spec->m_arcSpread) * (float)0.017453292)
                        * (float)((float)1.0 / (float)v34));
      v36 = v127;
      if ( v127 < 1 )
        v36 = 1;
      v37 = v36;
      if ( v36 >= v33 )
        v37 = v33;
      v132.m_size = 0;
      v38 = 0;
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v9);
      v9 = nullptr;
      v132.m_cap = 0;
      v132.m_data = nullptr;
      if ( v37 > 0 )
      {
        for ( i = v37; i != 0; --i )
          bfx::Array<bfx::FollowerBuddyData>::push_back(this: &v132, val: v32++);
        v38 = v132.m_size;
        v9 = (char *)v132.m_data;
      }
      qsort(
        base: v9,
        num: v38,
        width: 0xCu,
        comp: (int (__fastcall *)(const void *, const void *))bfx::CompareFollowerBuddies);
      v41 = this->m_commonState.m_slowTime;
      v42 = p_m_vel->m_x;
      v43 = (float)(p_m_vel->m_x * this->m_commonState.m_slowTime);
      v44 = this->m_vel.m_z;
      v45 = (float)(this->m_vel.m_z * this->m_commonState.m_slowTime);
      v126 = this->m_commonState.m_slowTime;
      v46 = (float)(this->m_vel.m_y * (float)v41);
      if ( (float)((float)((float)v45 * (float)v45)
                 + (float)((float)((float)v43 * (float)v43) + (float)((float)v46 * (float)v46))) <= 0.0009765625 )
      {
        this->m_behavior.m_pCurMotion->GetMatrix(
          this: this->m_behavior.m_pCurMotion,
          a2: (bfx::Matrix *)&v136.m_curRot.m_data[4]);
        v128.m_x = -v136.m_curRot.m_data[4];
        v128.m_y = -v136.m_curRot.m_data[5];
        v128.m_z = -v136.m_curRot.m_data[6];
      }
      else
      {
        v47 = (float)(this->m_vel.m_y * (float)v41);
        v126 = v41;
        _FP3 = (float)((float)__fsqrts((float)((float)((float)((float)v44 * (float)v41)
                                                     * (float)((float)v44 * (float)v41))
                                             + (float)((float)((float)((float)v42 * (float)v41)
                                                             * (float)((float)v42 * (float)v41))
                                                     + (float)((float)v47 * (float)v47))))
                     - (float)1.0842022e-19);
        __asm { fsel      f1, f3, f2, f27 }
        v128.m_x = -(float)((float)((float)v42 * (float)v41) * (float)_FP1);
        v128.m_y = -(float)((float)v47 * (float)_FP1);
        v128.m_z = -(float)((float)((float)v44 * (float)v41) * (float)_FP1);
      }
      LODWORD(v40) = v38 - 1;
      *(_QWORD *)&v133.m_val = v40;
      LocalUpAxis = bfx::Orienter::GetLocalUpAxis(
                      this: (bfx::Orienter *)&v136.m_curRot,
                      result: (bfx::Vec3 *)&this->m_commonState.m_orienter);
      bfx::Quat::Quat(
        this: (bfx::Quat *)&v136.m_slerpStartRot.m_z,
        axis: (const bfx::Vec3 *)LocalUpAxis,
        angle: (float)((float)((float)*(__int64 *)&v133.m_val
                      * (float)((float)6.2831855
                              / (float)((float)((float)((float)1.0 / (float)v34) * (float)v35) * (float)6.2831855)))
              * (float)-0.5));
      v52 = bfx::Quat::Apply(
              this: (bfx::Quat *)&v136.m_dir.m_z,
              result: (bfx::Quat *)&v136.m_slerpStartRot.m_z,
              v: &v128);
      v53 = 0;
      v54 = v52->m_x;
      v55 = v52->m_y;
      v56 = v9;
      v128.m_x = v52->m_w;
      v128.m_y = v54;
      LODWORD(v57) = &v9[12 * v38];
      v128.m_z = v55;
      v126 = v57;
      if ( v9 != (char *)LODWORD(v57) )
      {
        v58 = v128.m_z;
        v59 = v128.m_y;
        v60 = v128.m_x;
        do
        {
          LODWORD(v51) = v53;
          v61 = *((float **)v56 + 2);
          *(_QWORD *)&v130.m_x = v51;
          v62 = bfx::Orienter::GetLocalUpAxis(
                  this: (bfx::Orienter *)&v136.m_headingFrameMatrix.m_data[13],
                  result: (bfx::Vec3 *)&this->m_commonState.m_orienter);
          bfx::Quat::Quat(
            this: (bfx::Quat *)&v136.m_targetPos.m_y,
            axis: (const bfx::Vec3 *)v62,
            angle: (float)((float)*(__int64 *)&v130.m_x
                  * (float)((float)6.2831855
                          / (float)((float)((float)((float)1.0 / (float)v34) * (float)v35) * (float)6.2831855))));
          *(float *)&v136.m_pSpace = v60;
          *(float *)&v136.m_pTune = v59;
          *(float *)&v136.m_state = v58;
          v63 = bfx::Quat::Apply(
                  this: (bfx::Quat *)&v136.m_headingFrameMatrix.m_data[9],
                  result: (bfx::Quat *)&v136.m_targetPos.m_y,
                  v: (const bfx::Vec3 *)&v136);
          v64 = (float)(v63->m_w * (float)v35);
          v65 = (float)(v63->m_x * (float)v35);
          v66 = (float)(v63->m_y * (float)v35);
          v67 = v129.m_y;
          v68 = v129.m_z;
          v56 += 12;
          HIDWORD(v51) = v61 + 1;
          ++v53;
          LODWORD(v126) = v61 + 1;
          v61[1] = (float)v64 + v129.m_x;
          v61[2] = (float)v67 + (float)v65;
          v61[3] = (float)v68 + (float)v66;
        }
        while ( v56 != (char *)LODWORD(v57) );
      }
      v33 -= v37;
      v35 = (float)((float)v35 + (float)v34);
      if ( v33 <= 0 )
        break;
      p_m_spec = v131;
    }
  }
  if ( v31 != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v31);
  if ( v9 != nullptr )
  {
    v69 = v9;
    m_pMemoryManager = bfx::g_pCurInstance->m_pMemoryManager;
LABEL_101:
    bfx::MemoryManager::Free(this: m_pMemoryManager, ptr: v69);
  }
}


// ========================================================================
// __unwind$31055
// EA  : 0x832B4AB4
// RVA : 0x012B4AB4
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollower.cpp
// ========================================================================

void _unwind_31055()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 656 + 144));
}


// ========================================================================
// __unwind$31056
// EA  : 0x832B4ADC
// RVA : 0x012B4ADC
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollower.cpp
// ========================================================================

void _unwind_31056()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 656 + 176));
}


// ========================================================================
// __unwind$31057
// EA  : 0x832B4B04
// RVA : 0x012B4B04
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollower.cpp
// ========================================================================

void _unwind_31057()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 656 + 192));
}


// ========================================================================
// ?Clear@FollowData@MotionState@bfx@@QAAXXZ
// EA  : 0x832B4B30
// RVA : 0x012B4B30
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollower.cpp
// ========================================================================

void __fastcall bfx::MotionState::FollowData::Clear(bfx::MotionState::FollowData *this)
{
  bfx::HandleProxy *m_pProxy; // r11
  bfx::HandleProxy *v4; // r3

  m_pProxy = this->m_targetMover.m_pProxy;
  if ( m_pProxy != nullptr && m_pProxy->m_pTarget != nullptr )
  {
    v4 = this->m_targetMover.m_pProxy;
    if ( v4 != nullptr )
    {
      bfx::HandleProxy::RemRefToHandleProxy(this: v4);
      this->m_targetMover.m_pProxy = nullptr;
    }
  }
  this->m_dbgRank = -1;
  this->m_sidePushCountdown = 0.0;
  this->m_millAroundCountdown = 0.0;
  this->m_bulkScale = 1.0;
  this->m_leadersPrevSpeed = 0.0;
  this->m_followSpeedX = 1.0;
  this->m_externalForce.m_x = 0.0;
  this->m_externalForce.m_y = 0.0;
  this->m_externalForce.m_z = 0.0;
}


// ========================================================================
// ?AddFollower@FollowerLeaderDatabase@bfx@@QAAPAVDatabaseRecord@12@PAVMoverImpl@2@@Z
// EA  : 0x832B50D0
// RVA : 0x012B50D0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollower.cpp
// ========================================================================

bfx::FollowerLeaderDatabase::DatabaseRecord *__fastcall bfx::FollowerLeaderDatabase::AddFollower(
        bfx::FollowerLeaderDatabase *this,
        bfx::Space *pMover)
{
  bfx::FollowerLeaderDatabase::DatabaseRecord *v3; // r30
  bfx::FollowerLeaderDatabase::DatabaseRecord v5; // [sp+50h] [-30h] BYREF

  bfx::Handle<bfx::LinkBase>::Handle<bfx::LinkBase>(this: (bfx::Handle<bfx::Space> *)&v5, pTarget: pMover);
  v5.m_state = UNINITIALIZED;
  v5.m_pos.m_x = 0.0;
  v5.m_pos.m_y = 0.0;
  v5.m_pos.m_z = 0.0;
  v5.m_countDown = 0.0;
  bfx::Array<bfx::FollowerLeaderDatabase::DatabaseRecord>::push_back(this: &this->m_entries, val: &v5);
  v3 = &this->m_entries.m_data[this->m_entries.m_size - 1];
  if ( v5.m_mover.m_pProxy != nullptr )
    bfx::HandleProxy::RemRefToHandleProxy(this: v5.m_mover.m_pProxy);
  return v3;
}


// ========================================================================
// __unwind$32831
// EA  : 0x832B5168
// RVA : 0x012B5168
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollower.cpp
// ========================================================================

void _unwind_32831()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: (bfx::Handle<bfx::Space> *)(v0 - 128 + 80));
}


// ========================================================================
// ?GetFollowerPosition@MoverImpl@bfx@@AAA?AVVec3@2@PAV12@ABVFMSpec@2@@Z
// EA  : 0x832B5190
// RVA : 0x012B5190
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollower.cpp
// ========================================================================

bfx::MoverImpl *__fastcall bfx::MoverImpl::GetFollowerPosition(
        bfx::MoverImpl *this,
        const bfx::MoverImpl *result,
        bfx::MoverImpl *pFollowTarget,
        const bfx::FMSpec *spec)
{
  bfx::FollowerLeaderDatabase::DatabaseRecord *Follower; // r11
  bfx::FollowerLeaderDatabase *v8; // r7
  bfx::Space *v9; // r4
  bfx::HandleProxy *m_y_low; // r9
  bfx::RepulsorOwner_vtbl *m_z_low; // r8
  bfx::HandleProxy *v13; // r10
  bfx::MoverImpl_vtbl *v14; // r11
  _DWORD v15[12]; // [sp+50h] [-30h] BYREF

  ((void (__fastcall *)(_DWORD *))pFollowTarget->m_behavior.m_pCurMotion->GetPos)(a1: v15);
  if ( pFollowTarget->m_pLeaderDatabase != nullptr
    && ((Follower = (bfx::FollowerLeaderDatabase::DatabaseRecord *)bfx::FollowerLeaderDatabase::FindFollower(
                                                                     this: pFollowTarget->m_pLeaderDatabase,
                                                                     pMover: result)) != nullptr
     || (Follower = bfx::FollowerLeaderDatabase::AddFollower(this: v8, pMover: v9)) != nullptr) )
  {
    m_y_low = (bfx::HandleProxy *)LODWORD(Follower->m_pos.m_y);
    m_z_low = (bfx::RepulsorOwner_vtbl *)LODWORD(Follower->m_pos.m_z);
    this->bfx::HandleTargetBase::__vftable = (bfx::MoverImpl_vtbl *)LODWORD(Follower->m_pos.m_x);
    this->m_pProxy = m_y_low;
    this->bfx::RepulsorOwner::__vftable = m_z_low;
    return this;
  }
  else
  {
    v13 = (bfx::HandleProxy *)v15[1];
    v14 = (bfx::MoverImpl_vtbl *)v15[0];
    this->bfx::RepulsorOwner::__vftable = (bfx::RepulsorOwner_vtbl *)v15[2];
    this->m_pProxy = v13;
    this->bfx::HandleTargetBase::__vftable = v14;
    return this;
  }
}


// ========================================================================
// ?AddPet@MoverImpl@bfx@@QAAXPAV12@ABVFMSpec@2@@Z
// EA  : 0x832B5248
// RVA : 0x012B5248
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollower.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::AddPet(bfx::MoverImpl *this, bfx::MoverImpl *pFollower, const bfx::FMSpec *spec)
{
  bfx::FollowerLeaderDatabase *m_pLeaderDatabase; // r3
  bfx::FollowerLeaderDatabase *v7; // r3
  bfx::FollowerLeaderDatabase *v8; // r3
  bfx::FollowerLeaderDatabase *v9; // r11

  if ( pFollower != this )
  {
    m_pLeaderDatabase = this->m_pLeaderDatabase;
    if ( m_pLeaderDatabase != nullptr )
    {
      if ( bfx::FollowerLeaderDatabase::FindFollower(this: m_pLeaderDatabase, pMover: pFollower) != nullptr )
        return;
    }
    else
    {
      v7 = (bfx::FollowerLeaderDatabase *)bfx::MemoryManager::Malloc(
                                            this: bfx::g_pCurInstance->m_pMemoryManager,
                                            size: 0x24u,
                                            tag: bfx::MEM_BFXMOVER);
      if ( v7 != nullptr )
        v8 = bfx::FollowerLeaderDatabase::FollowerLeaderDatabase(this: v7);
      else
        v8 = nullptr;
      this->m_pLeaderDatabase = v8;
      bfx::Handle<bfx::MoverImpl>::operator=(
        this: (bfx::Handle<bfx::LinkBase> *)&v8->m_leader,
        pTarget: (bfx::LinkBase *)this);
    }
    v9 = this->m_pLeaderDatabase;
    if ( v9->m_entries.m_size == 0 )
    {
      v9->m_spec.m_formation = spec->m_formation;
      v9->m_spec.m_radius = spec->m_radius;
      v9->m_spec.m_arcSpread = spec->m_arcSpread;
    }
    bfx::FollowerLeaderDatabase::AddFollower(this: this->m_pLeaderDatabase, pMover: (bfx::Space *)pFollower);
  }
}


// ========================================================================
// __unwind$32915
// EA  : 0x832B530C
// RVA : 0x012B530C
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollower.cpp
// ========================================================================

void _unwind_32915()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(char **)(v0 - 128 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?RemovePet@MoverImpl@bfx@@QAAXPAV12@@Z
// EA  : 0x832B5338
// RVA : 0x012B5338
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollower.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::RemovePet(bfx::MoverImpl *this, bfx::MoverImpl *pFollower)
{
  bfx::FollowerLeaderDatabase *m_pLeaderDatabase; // r3
  bfx::FollowerLeaderDatabase::DatabaseRecord *m_data; // r8
  bfx::HandleProxy *m_pProxy; // r11
  bfx::MoverImpl *v6; // r11

  if ( pFollower != this )
  {
    m_pLeaderDatabase = this->m_pLeaderDatabase;
    if ( m_pLeaderDatabase != nullptr )
    {
      m_data = m_pLeaderDatabase->m_entries.m_data;
      if ( m_pLeaderDatabase->m_entries.m_data != &m_pLeaderDatabase->m_entries.m_data[m_pLeaderDatabase->m_entries.m_size] )
      {
        while ( 1 )
        {
          m_pProxy = m_data->m_mover.m_pProxy;
          if ( m_data->m_mover.m_pProxy != nullptr && m_pProxy->m_pTarget != nullptr )
          {
            v6 = m_pProxy != nullptr ? (bfx::MoverImpl *)m_pProxy->m_pTarget : nullptr;
            if ( v6 == pFollower )
              break;
          }
          if ( ++m_data == &m_pLeaderDatabase->m_entries.m_data[m_pLeaderDatabase->m_entries.m_size] )
            return;
        }
        bfx::Array<bfx::FollowerLeaderDatabase::DatabaseRecord>::erase(this: &m_pLeaderDatabase->m_entries, ptr: m_data);
      }
    }
  }
}


// ========================================================================
// ?ClearFollowMode@MoverImpl@bfx@@QAAXXZ
// EA  : 0x832B53E8
// RVA : 0x012B53E8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollower.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::ClearFollowMode(bfx::MoverImpl *this)
{
  bfx::HandleProxy *m_pProxy; // r11
  bfx::MotionState::FollowData *p_m_followData; // r31
  bfx::MoverImpl ***p_m_targetMover; // r10
  bfx::MoverImpl *v5; // r11
  bool v6; // r11
  bfx::MoverImpl *v7; // r11

  m_pProxy = this->m_commonState.m_followData.m_targetMover.m_pProxy;
  p_m_followData = &this->m_commonState.m_followData;
  p_m_targetMover = (bfx::MoverImpl ***)&this->m_commonState.m_followData.m_targetMover;
  if ( m_pProxy != nullptr && m_pProxy->m_pTarget != nullptr )
  {
    v5 = *p_m_targetMover != nullptr ? **p_m_targetMover : nullptr;
    if ( v5 != nullptr )
    {
      v6 = *p_m_targetMover != nullptr && **p_m_targetMover != nullptr;
      if ( v6 && *p_m_targetMover != nullptr )
        v7 = **p_m_targetMover;
      else
        v7 = nullptr;
      bfx::MoverImpl::RemovePet(this: v7, pFollower: this);
    }
  }
  bfx::MotionState::FollowData::Clear(this: p_m_followData);
}


// ========================================================================
// ?FollowMoverInternal@MoverImpl@bfx@@AAAXPAV12@ABVFMSpec@2@_N@Z
// EA  : 0x832B54B8
// RVA : 0x012B54B8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollower.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::FollowMoverInternal(
        bfx::MoverImpl *this,
        bfx::MoverImpl *pTargetMover,
        __int64 forceUpdate,
        __int64 a4,
        __int64 a5)
{
  float *v7; // r30
  unsigned __int8 v8; // r29
  bfx::MoverImpl::MoverBehavior *p_m_behavior; // r22
  __int64 v10; // r4
  bfx::HandleProxy *m_pProxy; // r11
  bfx::HandleTargetBase *m_pTarget; // r11
  float v13; // r9
  float v14; // r8
  bfx::AreaProxy *v15; // r11
  bfx::Area *m_pArea; // r24
  int v17; // r28
  char v18; // r11
  double v19; // fp0
  bool v20; // r29
  char v21; // r30
  double Scale; // fp1
  bfx::AreaProxy *v23; // r11
  bfx::Planner *v24; // r28
  const bfx::Area *v25; // r29
  __int64 v26; // r8
  bfx::AreaProxy *v27; // r11
  bfx::Area *v28; // r30
  __int64 v29; // r6
  bfx::MotionBase *m_pCurMotion; // r4
  double v31; // fp31
  const bfx::PathSpec *v32; // r6
  bfx::Vec3 *m_tag; // r30
  __int64 v34; // r6
  double v35; // fp12
  double v36; // fp10
  double v37; // fp8
  double v38; // fp31
  char m_data_high; // r11
  char v40; // r10
  double v41; // fp13
  char v42; // r9
  char m_curIslandSearchIndex_high; // r8
  double v44; // fp12
  double v45; // fp11
  double v46; // fp10
  double v47; // fp8
  double v48; // fp7
  int v49; // [sp+8h] [-2C8h]
  int v50; // [sp+Ch] [-2C4h]
  int v51; // [sp+10h] [-2C0h]
  int v52; // [sp+14h] [-2BCh]
  bfx::IslandGraph v53; // [sp+50h] [-280h] BYREF
  bfx::Vec3 v54; // [sp+80h] [-250h] BYREF
  bfx::Array<bfx::PathSeg> v55; // [sp+90h] [-240h] BYREF
  char v56; // [sp+A0h] [-230h]
  int v57; // [sp+A4h] [-22Ch]
  float v58; // [sp+A8h] [-228h]
  bfx::Vec3 v59; // [sp+B0h] [-220h] BYREF
  float v60; // [sp+C0h] [-210h] BYREF
  float v61; // [sp+C4h] [-20Ch]
  float v62; // [sp+C8h] [-208h]
  float v63; // [sp+D0h] [-200h] BYREF
  float v64; // [sp+D4h] [-1FCh]
  float v65; // [sp+D8h] [-1F8h]
  bfx::Vec3 v66; // [sp+E0h] [-1F0h] BYREF
  bfx::PathSpec v67; // [sp+F0h] [-1E0h] BYREF
  bfx::Matrix v68; // [sp+110h] [-1C0h] BYREF
  bfx::MoverTune v69; // [sp+150h] [-180h] BYREF

  v7 = (float *)HIDWORD(forceUpdate);
  v8 = forceUpdate;
  p_m_behavior = &this->m_behavior;
  if ( this->m_behavior.m_state != JUMPING && pTargetMover != nullptr )
  {
    LODWORD(a5) = this->m_pSpace;
    if ( (bfx::Space *)a5 == pTargetMover->m_pSpace )
    {
      if ( bfx::MoverImpl::ReattachSurfer(this) )
      {
        if ( bfx::SmartPath::GetNextLink(this: this->m_commonState.m_pSmartPath) != nullptr
          && bfx::MoverImpl::ShouldJumpNow(this) != DONT_JUMP )
        {
          m_pProxy = this->m_curGoalLink.m_pProxy;
          if ( m_pProxy != nullptr )
            m_pTarget = m_pProxy->m_pTarget;
          else
            m_pTarget = nullptr;
          bfx::MoverImpl::WalkingToJumping(
            this,
            startJumpFrozen: (_cntlzw(*((_DWORD *)&m_pTarget[6].m_pProxy[4] + 1) - 1) & 0x20) != 0);
        }
        else
        {
          v13 = v7[1];
          v14 = v7[2];
          v15 = this->m_commonState.m_surfer.m_area.m_pProxy;
          v54.m_x = *v7;
          v54.m_y = v13;
          v54.m_z = v14;
          if ( v15 != nullptr )
            m_pArea = v15->m_pArea;
          else
            m_pArea = nullptr;
          if ( m_pArea != nullptr )
          {
            v17 = v8;
            if ( v8 != 0 )
              goto LABEL_24;
            if ( !bfx::MoverImpl::ReachedGoal(this: pTargetMover) )
            {
              if ( pTargetMover->m_pLeaderDatabase == nullptr )
                goto LABEL_24;
              if ( (float)(pTargetMover->m_vel.m_x * pTargetMover->m_commonState.m_slowTime) != 0.0
                || (float)(pTargetMover->m_vel.m_y * pTargetMover->m_commonState.m_slowTime) != 0.0
                || (v18 = 1, (float)(pTargetMover->m_vel.m_z * pTargetMover->m_commonState.m_slowTime) != 0.0) )
              {
                v18 = 0;
              }
              if ( v18 == 0 )
              {
LABEL_24:
                bfx::MoverImpl::GetFollowerPosition(
                  this: (bfx::MoverImpl *)&v53,
                  result: this,
                  pFollowTarget: pTargetMover,
                  spec: (const bfx::FMSpec *)&v54);
                v19 = __fsqrts((float)((float)(pTargetMover->m_vel.m_x * pTargetMover->m_vel.m_x)
                                     + (float)((float)(pTargetMover->m_vel.m_y * pTargetMover->m_vel.m_y)
                                             + (float)(pTargetMover->m_vel.m_z * pTargetMover->m_vel.m_z))));
                v20 = v19 < (float)(this->m_commonState.m_pTune->m_speed * (float)0.85000002);
                if ( v19 < this->m_commonState.m_followData.m_leadersPrevSpeed || (v21 = 0, v19 < 0.0009765625) )
                  v21 = 1;
                bfx::GPSpec::GPSpec(this: (bfx::GPSpec *)&v53.m_largestIslandNumberEverUsed);
                *(float *)&v53.m_largestIslandNumberEverUsed = this->m_pTune->m_radiusData.m_radius * (float)3.0;
                *(float *)&v53.m_islandArray.m_pIslandGraph = 0.0;
                if ( !v20 || (HIBYTE(v53.m_islandArray.m_islands.m_data) = 1, v21 == 0) )
                  HIBYTE(v53.m_islandArray.m_islands.m_data) = 0;
                *(_WORD *)((char *)&v53.m_islandArray.m_islands.m_data + 1) = 0;
                *(float *)&v53.m_islandArray.m_islands.m_size = bfx::ZERO_VEC.m_x;
                *(float *)&v53.m_islandArray.m_islands.m_cap = bfx::ZERO_VEC.m_y;
                *(float *)&v53.m_islandArray.m_islands.m_tag = bfx::ZERO_VEC.m_z;
                if ( v17 != 0
                  || (Scale = bfx::GetScale(),
                      !bfx::MoverImpl::IgnoreGotoPosDueToSimilarParams(
                         this,
                         oldGoalPos: &this->m_lastGoalPosActedOn,
                         newGoalPos: (const bfx::Vec3 *)&v53,
                         newGotoPosSpec: (const bfx::GPSpec *)&v53.m_largestIslandNumberEverUsed,
                         ignoreThresholdDist: (float)((float)Scale * (float)0.1))) )
                {
                  bfx::BuildMoverPathSpec(result: &v67, pTune: this->m_pTune);
                  v23 = this->m_commonState.m_surfer.m_area.m_pProxy;
                  v24 = *((bfx::Planner **)this->m_pSpace->m_components.m_data + 1);
                  v25 = v23 != nullptr ? v23->m_pArea : nullptr;
                  if ( !bfx::MoverImpl::IsPuppet(this: pTargetMover)
                    && bfx::MotionState::IsFollowerMode(this: &this->m_commonState) )
                  {
                    v27 = pTargetMover->m_commonState.m_surfer.m_area.m_pProxy;
                    v28 = v27 != nullptr ? v27->m_pArea : nullptr;
                    if ( v28 != nullptr )
                    {
                      LODWORD(v26) = (v28->m_flags.m_flags4 ^ m_pArea->m_flags.m_flags4) & 0xF8000000;
                      if ( (_DWORD)v26 == 0 )
                      {
                        LODWORD(v29) = &v67;
                        HIDWORD(v29) = v28;
                        if ( bfx::Planner::IsAreaReachableFromArea(this: v24, pAreaA: v25, pathSpec: v29, a4: v26) )
                        {
                          ((void (__fastcall *)(float *))pTargetMover->m_behavior.m_pCurMotion->GetPos)(a1: &v60);
                          v55.m_tag = MEM_DEFAULT;
                          v56 = 0;
                          v58 = 0.0;
                          v57 = -1;
                          m_pCurMotion = pTargetMover->m_behavior.m_pCurMotion;
                          v31 = __fsqrts((float)((float)((float)(*(float *)&v53.m_numIslandsInUse - v60)
                                                       * (float)(*(float *)&v53.m_numIslandsInUse - v60))
                                               + (float)((float)((float)(*(float *)&v53.m_availableIslandNumbers.m_poolAutoPtr.m_data
                                                                       - v62)
                                                               * (float)(*(float *)&v53.m_availableIslandNumbers.m_poolAutoPtr.m_data
                                                                       - v62))
                                                       + (float)((float)(*(float *)&v53.m_availableIslandNumbers.m_pPool
                                                                       - v61)
                                                               * (float)(*(float *)&v53.m_availableIslandNumbers.m_pPool
                                                                       - v61)))));
                          v59.m_x = (float)((float)1.0 / (float)v31) * (float)(*(float *)&v53.m_numIslandsInUse - v60);
                          v59.m_y = (float)((float)1.0 / (float)v31)
                                  * (float)(*(float *)&v53.m_availableIslandNumbers.m_pPool - v61);
                          v59.m_z = (float)((float)1.0 / (float)v31)
                                  * (float)(*(float *)&v53.m_availableIslandNumbers.m_poolAutoPtr.m_data - v62);
                          ((void (__fastcall *)(bfx::Vec3 *))m_pCurMotion->GetPos)(a1: &v66);
                          bfx::RayCastThroughAreas(
                            pStartArea: (bfx::Vec3 *)v28,
                            origStartPos: &v66,
                            dir: &v59,
                            dist: v31,
                            pathSpec: v32,
                            rayCastData: &v67,
                            pPathOut: &v55,
                            a8: nullptr);
                          if ( v56 != 0 )
                          {
                            v53.m_numIslandsInUse = (int)v55.m_data;
                            v53.m_availableIslandNumbers.m_pPool = (bfx::Pool *)v55.m_size;
                            v53.m_availableIslandNumbers.m_poolAutoPtr.m_data = (bfx::Pool *)v55.m_cap;
                          }
                          m_tag = (bfx::Vec3 *)v55.m_tag;
                          if ( v55.m_tag != MEM_DEFAULT )
                            goto LABEL_48;
                        }
                      }
                    }
                  }
                  LODWORD(v34) = &v67;
                  HIDWORD(v34) = m_pArea;
                  m_tag = (bfx::Vec3 *)bfx::Planner::GetClosestReachableArea(
                                         this: *((bfx::Planner **)this->m_pSpace->m_components.m_data + 1),
                                         pos: &v53,
                                         pathSpec: v34,
                                         a4: v26);
                  if ( m_tag != nullptr )
                  {
LABEL_48:
                    if ( p_m_behavior->m_state == 0 || p_m_behavior->m_state == LOCOMOTING )
                    {
                      this->m_behavior.m_pCurMotion->GetMatrix(this: this->m_behavior.m_pCurMotion, a2: &v68);
                      bfx::MoverImpl::MoverBehavior::SwitchState(
                        this: p_m_behavior,
                        newState: PATH_WALKING,
                        startMat: &v68,
                        pStartArea: m_pArea,
                        commonState: &this->m_commonState);
                      this->m_behavior.m_pWalker->Initialize(
                        this: this->m_behavior.m_pWalker,
                        a2: &this->m_vel,
                        a3: &v68);
                    }
                    bfx::MoverTune::MoverTune(this: &v69);
                    v69 = *pTargetMover->m_pTune;
                    v35 = (float)(pTargetMover->m_vel.m_y * pTargetMover->m_commonState.m_slowTime);
                    v36 = (float)(pTargetMover->m_vel.m_z * pTargetMover->m_commonState.m_slowTime);
                    v37 = (float)(pTargetMover->m_vel.m_x * pTargetMover->m_commonState.m_slowTime);
                    if ( (float)((float)((float)v37 * (float)v37)
                               + (float)((float)((float)v36 * (float)v36) + (float)((float)v35 * (float)v35))) < (double)(float)((float)(v69.m_speed * (float)0.25) * (float)(v69.m_speed * (float)0.25)) )
                    {
                      v38 = (float)(this->m_commonState.m_pTune->m_radiusData.m_radius * (float)2.0);
                      ((void (__fastcall *)(float *))this->m_behavior.m_pCurMotion->GetPos)(a1: &v63);
                      if ( (float)((float)((float)(*(float *)&v53.m_numIslandsInUse - v63)
                                         * (float)(*(float *)&v53.m_numIslandsInUse - v63))
                                 + (float)((float)((float)(*(float *)&v53.m_availableIslandNumbers.m_poolAutoPtr.m_data
                                                         - v65)
                                                 * (float)(*(float *)&v53.m_availableIslandNumbers.m_poolAutoPtr.m_data
                                                         - v65))
                                         + (float)((float)(*(float *)&v53.m_availableIslandNumbers.m_pPool - v64)
                                                 * (float)(*(float *)&v53.m_availableIslandNumbers.m_pPool - v64)))) < (double)(float)((float)v38 * (float)v38) )
                        this->m_commonState.m_followData.m_millAroundCountdown = 1.5;
                    }
                    this->m_goalPos = *bfx::GetClosestPosInArea(
                                         result: &v54,
                                         pArea: m_tag,
                                         pos: (const bfx::Vec3 *)&v53,
                                         pEdgeIndexOut: nullptr);
                    bfx::SmartPath::SetGoalData(
                      this: this->m_commonState.m_pSmartPath,
                      goalPos: (const bfx::Vec3 *)&v53,
                      pGoalArea: (bfx::Area *)m_tag);
                    if ( bfx::SmartPath::HasPath(this: this->m_commonState.m_pSmartPath) )
                    {
                      m_data_high = HIBYTE(v53.m_islandArray.m_islands.m_data);
                      v40 = BYTE1(v53.m_islandArray.m_islands.m_data);
                      v41 = *(float *)&v53.m_islandArray.m_pIslandGraph;
                      v42 = BYTE2(v53.m_islandArray.m_islands.m_data);
                      this->m_gotoPosSpec.m_allowedToStopDist = *(float *)&v53.m_largestIslandNumberEverUsed;
                      m_curIslandSearchIndex_high = HIBYTE(v53.m_curIslandSearchIndex);
                      this->m_gotoPosSpec.m_desiredStopDist = v41;
                      v44 = *(float *)&v53.m_islandArray.m_islands.m_size;
                      this->m_gotoPosSpec.m_stopAtGoal = m_data_high;
                      v45 = *(float *)&v53.m_islandArray.m_islands.m_cap;
                      this->m_gotoPosSpec.m_pushThroughCrowdAtGoal = v40;
                      v46 = *(float *)&v53.m_islandArray.m_islands.m_tag;
                      this->m_gotoPosSpec.m_orientAtGoalEnable = v42;
                      this->m_gotoPosSpec.m_orientAtGoalDir.m_x = v44;
                      this->m_gotoPosSpec.m_orientAtGoalDir.m_y = v45;
                      this->m_gotoPosSpec.m_orientAtGoalDir.m_z = v46;
                      this->m_gotoPosSpec.m_tinyStep = m_curIslandSearchIndex_high;
                      *((_BYTE *)this + 872) |= 0x80u;
                      bfx::MoverImpl::WalkerGotoPos(
                        this,
                        spec: (const bfx::GPSpec *)&v53.m_largestIslandNumberEverUsed,
                        forceUpdate: false);
                      v47 = *(float *)&v53.m_availableIslandNumbers.m_pPool;
                      v48 = *(float *)&v53.m_availableIslandNumbers.m_poolAutoPtr.m_data;
                      this->m_lastGoalPosActedOn.m_x = *(float *)&v53.m_numIslandsInUse;
                      this->m_lastGoalPosActedOn.m_y = v47;
                      this->m_lastGoalPosActedOn.m_z = v48;
                      p_m_behavior->m_state = PATH_WALKING;
                    }
                    else
                    {
                      bfx::MoverImpl::MovingToIdle(this);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else
    {
      HIDWORD(forceUpdate) = pTargetMover->m_debugName.m_data;
      LODWORD(v10) = this->m_debugName.m_data;
      HIDWORD(v10) = "Follower named \"%s\" cannot follow the leader the leader named \"%s\" who is in different space.\n";
      bfx::InternalWarning(fmt: v10, a2: forceUpdate, a3: a4, a4: a5, a5: v49, a6: v50, a7: v51, a8: v52);
      bfx::MoverImpl::ClearFollowMode(this);
    }
  }
}


// ========================================================================
// ?FollowMover@MoverImpl@bfx@@QAAXPAVMover@2@ABVFollowMoverSpec@2@@Z
// EA  : 0x832B5B68
// RVA : 0x012B5B68
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxfollower.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::FollowMover(bfx::MoverImpl *this, bfx::LinkBase *pMoverTarget, bfx::FMSpec *spec)
{
  __int64 v6; // r6
  __int64 v7; // r10
  __int64 v8; // r8
  bfx::FMSpec v9; // [sp+50h] [-40h] BYREF
  bfx::FMSpec v10[4]; // [sp+60h] [-30h] BYREF

  bfx::FMSpec::FMSpec(this: v10, inputSpec: spec);
  bfx::CommandData::SetFollowMover(this: &this->m_lastMovementCommand, spec: v10);
  if ( !bfx::MoverImpl::RecordDeferredCommand(this) )
  {
    bfx::FMSpec::FMSpec(this: &v9, inputSpec: spec);
    if ( pMoverTarget != nullptr )
    {
      bfx::Handle<bfx::MoverImpl>::operator=(
        this: (bfx::Handle<bfx::LinkBase> *)&this->m_commonState.m_followData.m_targetMover,
        pTarget: pMoverTarget);
      bfx::MoverImpl::AddPet(this: (bfx::MoverImpl *)pMoverTarget, pFollower: this, spec: &v9);
      LODWORD(v6) = 0;
      HIDWORD(v6) = &v9;
      bfx::MoverImpl::FollowMoverInternal(
        this,
        pTargetMover: (bfx::MoverImpl *)pMoverTarget,
        forceUpdate: v6,
        a4: v8,
        a5: v7);
      *((_BYTE *)this + 872) &= ~0x20u;
    }
  }
}

