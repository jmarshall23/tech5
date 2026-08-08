
// ========================================================================
// ?OkToMoveIntoVolume@MSurfer3D@bfx@@UBA_NPBVVolume@2@@Z
// EA  : 0x83264E00
// RVA : 0x01264E00
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

BOOL __fastcall bfx::MSurfer3D::OkToMoveIntoVolume(bfx::MSurfer3D *this, const bfx::Volume *pVolume)
{
  return (this->m_pMover->m_pTune->m_customGeoMatchFlags & pVolume->m_userData) != 0;
}


// ========================================================================
// ?IgnoreGotoPosDueToSimilarParams@Mover3DImpl@bfx@@QAA_NABVVec3@2@0ABVGotoPosSpec3D@2@M@Z
// EA  : 0x83264E20
// RVA : 0x01264E20
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

int __fastcall bfx::Mover3DImpl::IgnoreGotoPosDueToSimilarParams(
        bfx::Mover3DImpl *this,
        const bfx::Vec3 *oldGoalPos,
        const bfx::Vec3 *newGoalPos,
        const bfx::GotoPosSpec3D *newGotoPosSpec,
        double ignoreThresholdDist)
{
  bfx::Mover3DImpl::State m_state; // r11
  double v6; // fp12
  double v7; // fp9
  double v9; // fp6
  int result; // r3
  double v12; // fp12
  double v13; // fp9

  m_state = this->m_state;
  if ( m_state == GOTO_POS || m_state == DECEL_TO_STOP )
  {
    result = 1;
    v12 = (float)(oldGoalPos->m_y - newGoalPos->m_y);
    v13 = (float)(oldGoalPos->m_z - newGoalPos->m_z);
    if ( __fsqrts((float)((float)((float)(oldGoalPos->m_x - newGoalPos->m_x) * (float)(oldGoalPos->m_x - newGoalPos->m_x))
                        + (float)((float)((float)v13 * (float)v13) + (float)((float)v12 * (float)v12)))) < ignoreThresholdDist )
      return result;
  }
  else
  {
    v6 = (float)(newGoalPos->m_y - this->m_surfer.m_pos.m_y);
    v7 = (float)(newGoalPos->m_z - this->m_surfer.m_pos.m_z);
    _FP4 = (float)((float)ignoreThresholdDist - this->m_pTune->m_goalRadius);
    v9 = (float)(newGoalPos->m_x - this->m_surfer.m_pos.m_x);
    __asm { fsel      f2, f4, f5, f1 }
    if ( __fsqrts((float)((float)((float)v9 * (float)v9)
                        + (float)((float)((float)v7 * (float)v7) + (float)((float)v6 * (float)v6)))) < _FP2 )
      return 1;
  }
  return 0;
}


// ========================================================================
// ?ReattachSurfer3D@Mover3DImpl@bfx@@AAA_NXZ
// EA  : 0x83264ED0
// RVA : 0x01264ED0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

int __fastcall bfx::Mover3DImpl::ReattachSurfer3D(bfx::Mover3DImpl *this)
{
  float m_y; // r9
  float m_z; // r8
  const bfx::Mover3DTune *m_pTune; // r7
  bfx::Planner3D *Planner3D; // r3
  bfx::Vec3 *ClosestVolume; // r3
  const bfx::Volume *v7; // r30
  int result; // r3
  bfx::Path3DSpec v9; // [sp+50h] [-60h] BYREF
  bfx::Vec3 v10; // [sp+58h] [-58h] BYREF
  bfx::Volume v11; // [sp+68h] [-48h] BYREF

  if ( this->m_stranded )
  {
    m_y = this->m_surfer.m_pos.m_y;
    m_z = this->m_surfer.m_pos.m_z;
    m_pTune = this->m_pTune;
    v10.m_x = this->m_surfer.m_pos.m_x;
    v9.m_customGeoMatchFlags = -1;
    v10.m_y = m_y;
    v10.m_z = m_z;
    v9.m_customGeoMatchFlags = m_pTune->m_customGeoMatchFlags;
    Planner3D = bfx::GetPlanner3D(pSpace: this->m_pSpace);
    ClosestVolume = (bfx::Vec3 *)bfx::Planner3D::GetClosestVolume(this: Planner3D, pos: &v10, pathSpec: &v9);
    v7 = (const bfx::Volume *)ClosestVolume;
    if ( ClosestVolume != nullptr )
    {
      bfx::Volume::GetClosestPos(this: &v11, result: ClosestVolume, pos: &v10);
      if ( __fsqrts((float)((float)((float)(*(float *)&v11.__vftable - v10.m_x)
                                  * (float)(*(float *)&v11.__vftable - v10.m_x))
                          + (float)((float)((float)(*(float *)&v11.m_pParentGraph - v10.m_z)
                                          * (float)(*(float *)&v11.m_pParentGraph - v10.m_z))
                                  + (float)((float)(*(float *)&v11.m_pProxy - v10.m_y)
                                          * (float)(*(float *)&v11.m_pProxy - v10.m_y))))) < (float)(bfx::GetScale() * (float)10.0) )
      {
        bfx::Surfer3D::SetPosAndVolume(this: &this->m_surfer, pos: (const bfx::Vec3 *)&v11, pVolume: v7);
        this->m_stranded = false;
        return 1;
      }
    }
    return 0;
  }
  else
  {
    result = (int)bfx::Surfer3D::GetVolume(this: &this->m_surfer);
    if ( result != 0 )
      return 1;
    this->m_stranded = true;
  }
  return result;
}


// ========================================================================
// ?GetClosestReachablePos@Mover3DImpl@bfx@@QBA?AVVec3@2@ABV32@@Z
// EA  : 0x83265010
// RVA : 0x01265010
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

bfx::Mover3DImpl *__fastcall bfx::Mover3DImpl::GetClosestReachablePos(
        bfx::Mover3DImpl *this,
        bfx::Vec3 *result,
        const bfx::Vec3 *goalPos)
{
  const bfx::Volume *Volume; // r29
  float m_z; // r10
  float m_y; // r3
  bfx::Planner3D *Planner3D; // r3
  bfx::Vec3 *ClosestReachableVolume; // r4
  bfx::Path3DSpec v12; // [sp+50h] [-30h] BYREF

  Volume = bfx::Surfer3D::GetVolume(this: (bfx::Surfer3D *)&result[10].m_z);
  if ( Volume != nullptr
    && (m_z = result[8].m_z,
        m_y = result->m_y,
        v12.m_customGeoMatchFlags = -1,
        v12.m_customGeoMatchFlags = *(_DWORD *)(LODWORD(m_z) + 40),
        Planner3D = bfx::GetPlanner3D(pSpace: (bfx::Space *)LODWORD(m_y)),
        (ClosestReachableVolume = (bfx::Vec3 *)bfx::Planner3D::GetClosestReachableVolume(
                                                 this: Planner3D,
                                                 pStartVolume: Volume,
                                                 pos: goalPos,
                                                 pathSpec: &v12)) != nullptr) )
  {
    bfx::Volume::GetClosestPos((bfx::Volume *)this, result: ClosestReachableVolume, pos: goalPos);
    return this;
  }
  else
  {
    this->__vftable = (bfx::Mover3DImpl_vtbl *)LODWORD(result[11].m_y);
    this->m_pSpace = (bfx::Space *)LODWORD(result[11].m_z);
    *(float *)&this->m_stranded = result[12].m_x;
    return this;
  }
}


// ========================================================================
// ?SwitchState@Mover3DImpl@bfx@@AAAXW4State@12@@Z
// EA  : 0x832650B0
// RVA : 0x012650B0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __fastcall bfx::Mover3DImpl::SwitchState(bfx::Mover3DImpl *this, bfx::Mover3DImpl::State newState)
{
  int v4; // r30
  float m_x; // r9
  float m_y; // r8
  __int64 v8; // r11
  bfx::Quat *v9; // r10
  const bfx::Mover3DTune *m_pTune; // r9
  bfx::Space *m_pSpace; // r3
  bfx::Planner3D *Planner3D; // r3
  const bfx::Path3DSpec *v13; // r6
  bfx::Space *v14; // r3
  bfx::Planner3D *v15; // r3
  const bfx::Path3DSpec *v16; // r6
  double v17; // fp13
  double v18; // fp12
  bfx::Path3DSpec v20[2]; // [sp+50h] [-100h] BYREF
  bfx::Vec3 v21; // [sp+58h] [-F8h] BYREF
  bfx::Vec3 v22; // [sp+68h] [-E8h] BYREF
  bfx::Vec3 v23; // [sp+78h] [-D8h] BYREF
  bfx::Vec3 v24[2]; // [sp+88h] [-C8h] BYREF
  bfx::RayCast3DResults v25; // [sp+A0h] [-B0h] BYREF
  bfx::RayCast3DResults v26; // [sp+C0h] [-90h] BYREF
  bfx::Quat v27; // [sp+E0h] [-70h] BYREF
  bfx::Quat v28; // [sp+F0h] [-60h] BYREF

  if ( this->m_state != newState )
  {
    if ( newState == IDLE && this->m_pTune->m_idleTune.m_circleWhileIdle )
    {
      this->m_hoverData.m_idleStateData.m_vUp = *bfx::GetUpVec(result: v24);
      v4 = 0;
      m_x = this->m_orbitCenterPos.m_x;
      m_y = this->m_orbitCenterPos.m_y;
      _FP31 = this->m_pTune->m_idleTune.m_circlingRadius;
      v22.m_z = this->m_orbitCenterPos.m_z;
      v22.m_y = m_y;
      v22.m_x = m_x;
      do
      {
        bfx::GetHorizontalReferenceVec(result: &v21);
        LODWORD(v8) = v4;
        *(_QWORD *)&v24[0].m_x = v8;
        bfx::Quat::Quat(
          this: &v27,
          axis: &this->m_hoverData.m_idleStateData.m_vUp,
          angle: (float)((float)v8 * (float)0.52359879));
        v9 = bfx::Quat::Apply(this: &v28, result: &v27, v: &v21);
        m_pTune = this->m_pTune;
        m_pSpace = this->m_pSpace;
        v21.m_x = v9->m_w;
        v21.m_y = v9->m_x;
        v21.m_z = v9->m_y;
        v20[0].m_customGeoMatchFlags = -1;
        v26.m_collided = false;
        v25.m_collided = false;
        v20[0] = (bfx::Path3DSpec)m_pTune->m_customGeoMatchFlags;
        Planner3D = bfx::GetPlanner3D(pSpace: m_pSpace);
        bfx::Planner3D::Probe(
          this: Planner3D,
          startPos: &v22,
          dir: &v21,
          dist: _FP31,
          pathSpec: v13,
          results: v20,
          a7: &v26);
        v23.m_x = -v21.m_x;
        v23.m_y = -v21.m_y;
        v14 = this->m_pSpace;
        v23.m_z = -v21.m_z;
        v15 = bfx::GetPlanner3D(pSpace: v14);
        bfx::Planner3D::Probe(this: v15, startPos: &v22, dir: &v23, dist: _FP31, pathSpec: v16, results: v20, a7: &v25);
        ++v4;
        v17 = (float)(v26.m_endPos.m_y + (float)((float)(v25.m_endPos.m_y - v26.m_endPos.m_y) * (float)0.5));
        v22.m_y = v26.m_endPos.m_y + (float)((float)(v25.m_endPos.m_y - v26.m_endPos.m_y) * (float)0.5);
        v18 = (float)(v26.m_endPos.m_z + (float)((float)(v25.m_endPos.m_z - v26.m_endPos.m_z) * (float)0.5));
        v22.m_z = v26.m_endPos.m_z + (float)((float)(v25.m_endPos.m_z - v26.m_endPos.m_z) * (float)0.5);
        v22.m_x = v26.m_endPos.m_x + (float)((float)(v25.m_endPos.m_x - v26.m_endPos.m_x) * (float)0.5);
        _FP7 = (float)((float)_FP31
                     - (float)((float)__fsqrts((float)((float)((float)(v25.m_endPos.m_x - v26.m_endPos.m_x)
                                                             * (float)(v25.m_endPos.m_x - v26.m_endPos.m_x))
                                                     + (float)((float)((float)(v25.m_endPos.m_z - v26.m_endPos.m_z)
                                                                     * (float)(v25.m_endPos.m_z - v26.m_endPos.m_z))
                                                             + (float)((float)(v25.m_endPos.m_y - v26.m_endPos.m_y)
                                                                     * (float)(v25.m_endPos.m_y - v26.m_endPos.m_y)))))
                             * (float)0.5));
        __asm { fsel      f31, f7, f8, f31 }
      }
      while ( v4 < 6 );
      this->m_hoverData.m_idleStateData.m_center.m_x = v26.m_endPos.m_x
                                                     + (float)((float)(v25.m_endPos.m_x - v26.m_endPos.m_x) * (float)0.5);
      this->m_hoverData.m_idleStateData.m_center.m_y = v17;
      this->m_hoverData.m_idleStateData.m_center.m_z = v18;
      this->m_hoverData.m_idleStateData.m_maxRadius = _FP31;
      this->m_hoverData.m_debug.m_vRepulsion.m_x = 0.0;
      this->m_hoverData.m_debug.m_vRepulsion.m_y = 0.0;
      this->m_hoverData.m_debug.m_vRepulsion.m_z = 0.0;
      this->m_hoverData.m_debug.m_vSteering.m_x = 0.0;
      this->m_hoverData.m_debug.m_vSteering.m_y = 0.0;
      this->m_hoverData.m_debug.m_vSteering.m_z = 0.0;
      this->m_hoverData.m_debug.m_vTargetAttraction.m_x = 0.0;
      this->m_hoverData.m_debug.m_vTargetAttraction.m_y = 0.0;
      this->m_hoverData.m_debug.m_vTargetAttraction.m_z = 0.0;
      this->m_hoverData.m_debug.m_vBraking.m_x = 0.0;
      this->m_hoverData.m_debug.m_vBraking.m_y = 0.0;
      this->m_hoverData.m_debug.m_vBraking.m_z = 0.0;
      this->m_hoverData.m_debug.m_vCollisionPos.m_x = 0.0;
      this->m_hoverData.m_debug.m_vCollisionPos.m_y = 0.0;
      this->m_hoverData.m_debug.m_vCollisionPos.m_z = 0.0;
    }
    this->m_state = newState;
  }
}


// ========================================================================
// ?BaseSimulate@Mover3DImpl@bfx@@AAAXM@Z
// EA  : 0x83265318
// RVA : 0x01265318
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __fastcall bfx::Mover3DImpl::BaseSimulate(bfx::Mover3DImpl *this, double simTime)
{
  double v3; // fp13
  float m_y; // r10
  float m_z; // r9
  unsigned int m_idx; // r5
  float m_x; // r11
  bfx::Path3D *m_pPath; // r3
  bfx::Vec3 v9; // [sp+50h] [-30h] BYREF
  bfx::Vec3 v10; // [sp+60h] [-20h] BYREF

  if ( this->m_curPathCC.m_pPath != nullptr )
  {
    v3 = (float)(this->m_refinementCountdownTimer - (float)simTime);
    this->m_refinementCountdownTimer = this->m_refinementCountdownTimer - (float)simTime;
    m_y = this->m_surfer.m_pos.m_y;
    m_z = this->m_surfer.m_pos.m_z;
    m_idx = this->m_curPathCC.m_idx;
    m_x = this->m_surfer.m_pos.m_x;
    m_pPath = this->m_curPathCC.m_pPath;
    if ( v3 > 0.0 )
    {
      v10.m_x = m_x;
      v10.m_y = m_y;
      v10.m_z = m_z;
      bfx::Path3D::RefineNextPointOnce(this: m_pPath, startPos: &v10, nextPointIdx: m_idx);
    }
    else
    {
      v9.m_x = m_x;
      v9.m_y = m_y;
      v9.m_z = m_z;
      bfx::Path3D::Refine(this: m_pPath, startPos: &v9, nextPointIdx: m_idx);
      this->m_refinementCountdownTimer = bfx::RandFloat(min: 0.2, max: 0.30000001);
    }
  }
}


// ========================================================================
// ??0Mover3DTune@bfx@@QAA@XZ
// EA  : 0x832653D0
// RVA : 0x012653D0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

bfx::Mover3DTune *__fastcall bfx::Mover3DTune::Mover3DTune(bfx::Mover3DTune *this)
{
  double Scale; // fp1
  double v3; // fp1

  bfx::RepulsionPackage::RepulsionPackage(this: &this->m_repulsionPackage);
  this->m_orienter.m_angularVelMax = 360.0;
  this->m_orienter.m_stayRightSideUp = true;
  this->m_orienter.m_turnMode = SLIP_SLIDE_TURN;
  this->m_orienter.m_rollSpeed = 180.0;
  this->m_idleTune.m_circleWhileIdle = false;
  this->m_idleTune.m_idleSpeedScale = 1.0;
  this->m_idleTune.m_orbitHeight = -1.0;
  this->m_idleTune.m_circlingRadius = bfx::GetScale();
  this->m_movementType = HOVER;
  this->m_customGeoMatchFlags = -1;
  this->m_goalRadius = bfx::GetScale() * (float)5.0;
  Scale = bfx::GetScale();
  this->m_accTime = 1.0;
  this->m_desSpeed = (float)Scale * (float)4.0;
  v3 = bfx::GetScale();
  this->m_minTurningRadius = (float)v3 * (float)2.0;
  return this;
}


// ========================================================================
// ?ApplyLimits_Mover3DTune@bfx@@YAXAAUMover3DTune@1@@Z
// EA  : 0x832654B0
// RVA : 0x012654B0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __fastcall bfx::ApplyLimits_Mover3DTune(bfx::Mover3DTune *tune)
{
  double v2; // fp31
  double Scale; // fp1

  v2 = __fabs(tune->m_minTurningRadius);
  Scale = bfx::GetScale();
  _FP10 = (float)((float)v2 - tune->m_minTurningRadius);
  _FP8 = (float)((float)0.33333334 - tune->m_accTime);
  _FP7 = (float)((float)3.4028235e38 - tune->m_accTime);
  _FP6 = (float)((float)((float)Scale * (float)0.1) - tune->m_minTurningRadius);
  __asm
  {
    fsel      f5, f8, f13, f12
    fsel      f4, f6, f9, f11
  }
  __asm
  {
    fsel      f1, f7, f3, f0
    fsel      f0, f10, f2, f31
  }
  tune->m_minTurningRadius = _FP0;
  tune->m_accTime = _FP1;
}


// ========================================================================
// ?CalcAngleBetween@bfx@@YAMABVVec3@1@0@Z
// EA  : 0x83265558
// RVA : 0x01265558
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

float __fastcall bfx::CalcAngleBetween(const bfx::Vec3 *v1, const bfx::Vec3 *v2)
{
  double v7; // fp12
  long double v11; // fp2
  double v12; // fp1

  _FP7 = (float)((float)__fsqrts((float)((float)(v2->m_z * v2->m_z)
                                       + (float)((float)(v2->m_x * v2->m_x) + (float)(v2->m_y * v2->m_y))))
               - (float)1.0842022e-19);
  _FP3 = (float)((float)__fsqrts((float)((float)(v1->m_z * v1->m_z)
                                       + (float)((float)(v1->m_x * v1->m_x) + (float)(v1->m_y * v1->m_y))))
               - (float)1.0842022e-19);
  __asm
  {
    fsel      f13, f7, f6, f12
    fsel      f12, f3, f1, f12
  }
  *((double *)&_FP2 + 1) = (float)(v1->m_y * (float)_FP12);
  v7 = (float)((float)((float)(v1->m_y * (float)_FP12) * (float)((float)_FP13 * v2->m_y))
             + (float)((float)((float)(v1->m_x * (float)_FP12) * (float)(v2->m_x * (float)_FP13))
                     + (float)((float)(v1->m_z * (float)_FP12) * (float)((float)_FP13 * v2->m_z))));
  _FP11 = (float)((float)-1.0 - (float)v7);
  _FP9 = (float)((float)1.0 - (float)v7);
  __asm { fsel      f8, f11, f10, f12 }
  __asm { fsel      f1, f9, f7, f0# x }
  v11 = acos(x: _FP2);
  v12 = (float)*(double *)&v11;
  return *((float *)&v12 + 1);
}


// ========================================================================
// ?CalcRotationCloseness@bfx@@YAMABVVec3@1@0_N@Z
// EA  : 0x83265648
// RVA : 0x01265648
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

float __fastcall bfx::CalcRotationCloseness(const bfx::Vec3 *vForw, const bfx::Vec3 *vLeft, bool bCheckLeftAxis)
{
  const bfx::Vec3 *v3; // r11
  const bfx::Vec3 *v4; // r11
  double v7; // fp26
  double v8; // fp25
  double v9; // fp24
  double v12; // fp30
  double v13; // fp29
  double v14; // fp28
  bfx::Vec3 *UpVec; // r3
  double v16; // fp7
  double v17; // fp6
  double v18; // fp5
  bfx::Vec3 *v19; // r3
  double v22; // fp28
  double v23; // fp29
  double v24; // fp30
  bfx::Vec3 *v25; // r3
  double v26; // fp7
  double v27; // fp6
  double v28; // fp5
  double v31; // fp26
  double v32; // fp25
  double v33; // fp24
  double v34; // fp30
  bfx::Vec3 *v37; // r3
  long double v38; // fp4
  long double v41; // fp2
  double v42; // fp1
  bfx::Vec3 v44; // [sp+50h] [-70h] BYREF
  bfx::Vec3 v45[6]; // [sp+60h] [-60h] BYREF

  v3 = vLeft;
  if ( !bCheckLeftAxis )
    v3 = vForw;
  _FP5 = (float)((float)__fsqrts((float)((float)(v3->m_z * v3->m_z)
                                       + (float)((float)(v3->m_x * v3->m_x) + (float)(v3->m_y * v3->m_y))))
               - (float)1.0842022e-19);
  __asm { fsel      f3, f5, f4, f31 }
  v7 = (float)(v3->m_x * (float)_FP3);
  v8 = (float)(v3->m_y * (float)_FP3);
  v9 = (float)(v3->m_z * (float)_FP3);
  v4 = vForw;
  if ( !bCheckLeftAxis )
    v4 = vLeft;
  _FP4 = (float)((float)__fsqrts((float)((float)(v4->m_z * v4->m_z)
                                       + (float)((float)(v4->m_x * v4->m_x) + (float)(v4->m_y * v4->m_y))))
               - (float)1.0842022e-19);
  __asm { fsel      f2, f4, f3, f31 }
  v12 = (float)(v4->m_x * (float)_FP2);
  v13 = (float)(v4->m_y * (float)_FP2);
  v14 = (float)(v4->m_z * (float)_FP2);
  if ( bCheckLeftAxis )
  {
    UpVec = bfx::GetUpVec(result: &v44);
    v16 = (float)((float)(UpVec->m_z * (float)v12) - (float)(UpVec->m_x * (float)v14));
    v17 = (float)((float)(UpVec->m_x * (float)v13) - (float)(UpVec->m_y * (float)v12));
    v18 = (float)((float)(UpVec->m_y * (float)v14) - (float)(UpVec->m_z * (float)v13));
  }
  else
  {
    v19 = bfx::GetUpVec(result: &v44);
    v16 = (float)((float)(v19->m_x * (float)v14) - (float)(v19->m_z * (float)v12));
    v17 = (float)((float)(v19->m_y * (float)v12) - (float)(v19->m_x * (float)v13));
    v18 = (float)((float)(v19->m_z * (float)v13) - (float)(v19->m_y * (float)v14));
  }
  _FP0 = (float)((float)__fsqrts((float)((float)((float)v18 * (float)v18)
                                       + (float)((float)((float)v17 * (float)v17) + (float)((float)v16 * (float)v16))))
               - 1.0842022e-19);
  __asm { fsel      f12, f0, f13, f31 }
  v22 = (float)((float)v17 * (float)_FP12);
  v23 = (float)((float)v16 * (float)_FP12);
  v24 = (float)((float)_FP12 * (float)v18);
  v25 = bfx::GetUpVec(result: &v44);
  v26 = (float)((float)v8
              - (float)((float)((float)(v25->m_x * (float)v22) - (float)(v25->m_z * (float)v24))
                      * (float)((float)((float)((float)(v25->m_z * (float)v23) - (float)(v25->m_y * (float)v22))
                                      * (float)v7)
                              + (float)((float)((float)((float)(v25->m_y * (float)v24) - (float)(v25->m_x * (float)v23))
                                              * (float)v9)
                                      + (float)((float)((float)(v25->m_x * (float)v22) - (float)(v25->m_z * (float)v24))
                                              * (float)v8)))));
  v27 = (float)((float)v9
              - (float)((float)((float)(v25->m_y * (float)v24) - (float)(v25->m_x * (float)v23))
                      * (float)((float)((float)((float)(v25->m_z * (float)v23) - (float)(v25->m_y * (float)v22))
                                      * (float)v7)
                              + (float)((float)((float)((float)(v25->m_y * (float)v24) - (float)(v25->m_x * (float)v23))
                                              * (float)v9)
                                      + (float)((float)((float)(v25->m_x * (float)v22) - (float)(v25->m_z * (float)v24))
                                              * (float)v8)))));
  v28 = (float)((float)v7
              - (float)((float)((float)(v25->m_z * (float)v23) - (float)(v25->m_y * (float)v22))
                      * (float)((float)((float)((float)(v25->m_z * (float)v23) - (float)(v25->m_y * (float)v22))
                                      * (float)v7)
                              + (float)((float)((float)((float)(v25->m_y * (float)v24) - (float)(v25->m_x * (float)v23))
                                              * (float)v9)
                                      + (float)((float)((float)(v25->m_x * (float)v22) - (float)(v25->m_z * (float)v24))
                                              * (float)v8)))));
  _FP0 = (float)((float)__fsqrts((float)((float)((float)v28 * (float)v28)
                                       + (float)((float)((float)v27 * (float)v27) + (float)((float)v26 * (float)v26))))
               - 1.0842022e-19);
  __asm { fsel      f10, f0, f11, f31 }
  v31 = (float)((float)((float)v8
                      - (float)((float)((float)(v25->m_x * (float)v22) - (float)(v25->m_z * (float)v24))
                              * (float)((float)((float)((float)(v25->m_z * (float)v23) - (float)(v25->m_y * (float)v22))
                                              * (float)v7)
                                      + (float)((float)((float)((float)(v25->m_y * (float)v24)
                                                              - (float)(v25->m_x * (float)v23))
                                                      * (float)v9)
                                              + (float)((float)((float)(v25->m_x * (float)v22)
                                                              - (float)(v25->m_z * (float)v24))
                                                      * (float)v8)))))
              * (float)_FP10);
  v32 = (float)((float)v27 * (float)_FP10);
  v33 = (float)((float)v28 * (float)_FP10);
  v34 = (float)((float)((float)((float)v28 * (float)_FP10) * (float)v24)
              + (float)((float)((float)((float)v27 * (float)_FP10) * (float)v22) + (float)((float)v31 * (float)v23)));
  _FP7 = (float)((float)-1.0 - (float)v34);
  __asm { fsel      f29, f7, f12, f30 }
  v37 = bfx::GetUpVec(result: v45);
  *(double *)&_FP2 = (float)((float)(v37->m_x * (float)v33)
                           + (float)((float)(v37->m_z * (float)v32) + (float)(v37->m_y * (float)v31)));
  if ( *(double *)&_FP2 == 0.0 )
  {
    v42 = 1.5707964;
  }
  else
  {
    _FP0 = (float)((float)1.0 - (float)v34);
    __asm { fsel      f2, f0, f13, f27# v }
    *(double *)&v38 = v37->m_x;
    *((double *)&v38 + 1) = v37->m_z;
    v41 = atan2(v: _FP2, u: v38);
    v42 = (float)*(double *)&v41;
  }
  return *((float *)&v42 + 1);
}


// ========================================================================
// ?Simulate@Orienter3D@bfx@@QAAXMABVVec3@2@ABUOrienter3DTune@2@M@Z
// EA  : 0x832658A8
// RVA : 0x012658A8
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __fastcall bfx::Orienter3D::Simulate(
        bfx::Orienter3D *this,
        double simTime,
        const bfx::Vec3 *forwVel,
        const bfx::Orienter3DTune *tune,
        double minVelToChangeHeading,
        int a6)
{
  double v11; // fp13
  double v12; // fp12
  bfx::Vec3 *UpVec; // r3
  double v14; // fp6
  double v15; // fp4
  bfx::Quat *v16; // r3
  double m_x; // fp13
  double m_y; // fp12
  double m_z; // fp11
  bfx::Vec3 *p_m_angularVel; // r30
  double v21; // fp24
  double v24; // fp29
  double v25; // fp28
  double v26; // fp27
  double v27; // fp1
  char v28; // r11
  double v29; // fp1
  double v30; // fp1
  double v31; // fp0
  double m_w; // fp10
  double v33; // fp11
  double v34; // fp9
  double v39; // fp0
  char v40; // r11
  double v41; // fp13
  double v42; // fp12
  bfx::Quat *v43; // r3
  double v44; // fp10
  double v45; // fp9
  double v46; // fp8
  double v47; // fp0
  double v48; // fp13
  double v49; // fp4
  double v50; // fp3
  double v51; // fp2
  char v52; // r11
  double v53; // fp13
  double v54; // fp12
  bfx::Quat *v55; // r3
  double v56; // fp10
  double v57; // fp9
  double v58; // fp8
  double v59; // fp0
  double v60; // fp13
  double v61; // fp7
  double v62; // fp0
  double v63; // fp4
  double v64; // fp3
  double v65; // fp2
  bfx::Quat v66; // [sp+50h] [-150h] BYREF
  bfx::Quat v67; // [sp+60h] [-140h] BYREF
  bfx::Quat v68; // [sp+70h] [-130h] BYREF
  bfx::Quat v69; // [sp+80h] [-120h] BYREF
  bfx::Quat v70; // [sp+90h] [-110h] BYREF
  bfx::Vec3 v71; // [sp+A0h] [-100h] BYREF
  bfx::Quat v72; // [sp+B0h] [-F0h] BYREF
  bfx::Vec3 v73; // [sp+C0h] [-E0h] BYREF
  bfx::Vec3 v74; // [sp+D0h] [-D0h] BYREF
  bfx::Matrix v75[2]; // [sp+E0h] [-C0h] BYREF

  _FP0 = (float)((float)__fsqrts((float)((float)((float)(*(float *)&tune->m_stayRightSideUp
                                                       * *(float *)&tune->m_stayRightSideUp)
                                               + (float)(*(float *)&tune->m_turnMode * *(float *)&tune->m_turnMode))
                                       + (float)(tune->m_angularVelMax * tune->m_angularVelMax)))
               - (float)1.0842022e-19);
  __asm { fsel      f11, f0, f13, f31 }
  v11 = (float)(*(float *)&tune->m_stayRightSideUp * (float)_FP11);
  v12 = (float)(*(float *)&tune->m_turnMode * (float)_FP11);
  if ( (float)((float)((float)(*(float *)&tune->m_turnMode * *(float *)&tune->m_turnMode)
                     + (float)(*(float *)&tune->m_stayRightSideUp * *(float *)&tune->m_stayRightSideUp))
             + (float)(tune->m_angularVelMax * tune->m_angularVelMax)) <= (double)(float)((float)minVelToChangeHeading
                                                                                        * (float)minVelToChangeHeading) )
  {
    m_x = this->m_curRot.m_x;
    m_y = this->m_curRot.m_y;
    m_z = this->m_curRot.m_z;
    v72.m_w = this->m_curRot.m_w;
    v72.m_x = m_x;
    v72.m_y = m_y;
    v72.m_z = m_z;
  }
  else
  {
    v71.m_x = tune->m_angularVelMax * (float)_FP11;
    v71.m_y = v11;
    v71.m_z = v12;
    UpVec = bfx::GetUpVec(result: (bfx::Vec3 *)&v66);
    v73.m_x = UpVec->m_x;
    v73.m_y = UpVec->m_y;
    v14 = UpVec->m_z;
    v15 = (float)((float)(v73.m_y * v71.m_z) - (float)(UpVec->m_z * v71.m_y));
    v74.m_x = (float)(v73.m_y * v71.m_z) - (float)(UpVec->m_z * v71.m_y);
    v74.m_z = (float)(v71.m_y * v73.m_x) - (float)(v73.m_y * v71.m_x);
    v74.m_y = (float)((float)v14 * v71.m_x) - (float)(v71.m_z * v73.m_x);
    v73.m_z = (float)(v74.m_y * v71.m_x) - (float)(v71.m_y * (float)v15);
    v73.m_y = (float)(v71.m_z * (float)v15) - (float)(v74.m_z * v71.m_x);
    v73.m_x = (float)(v74.m_z * v71.m_y) - (float)(v74.m_y * v71.m_z);
    bfx::Matrix::Build(this: v75, xAxis: &v71, yAxis: &v74, zAxis: &v73, trans: &bfx::ZERO_VEC);
    v16 = bfx::Quat::Quat(this: &v66, m: v75);
    v72.m_w = v16->m_w;
    v72.m_x = v16->m_x;
    v72.m_y = v16->m_y;
    v72.m_z = v16->m_z;
  }
  v67.m_w = 1.0;
  v67.m_x = 0.0;
  v67.m_y = 0.0;
  bfx::Quat::Apply(this: &v68, result: &this->m_curRot, v: (const bfx::Vec3 *)&v67);
  v66.m_w = 1.0;
  v66.m_x = 0.0;
  v66.m_y = 0.0;
  bfx::Quat::Apply(this: &v67, result: &v72, v: (const bfx::Vec3 *)&v66);
  p_m_angularVel = &this->m_angularVel;
  v21 = __fsqrts((float)((float)(this->m_angularVel.m_z * this->m_angularVel.m_z)
                       + (float)((float)(this->m_angularVel.m_x * this->m_angularVel.m_x)
                               + (float)(this->m_angularVel.m_y * this->m_angularVel.m_y))));
  _FP1 = (float)((float)__fsqrts((float)((float)((float)((float)(v68.m_y * v67.m_w) - (float)(v67.m_y * v68.m_w))
                                               * (float)((float)(v68.m_y * v67.m_w) - (float)(v67.m_y * v68.m_w)))
                                       + (float)((float)((float)((float)(v67.m_y * v68.m_x) - (float)(v68.m_y * v67.m_x))
                                                       * (float)((float)(v67.m_y * v68.m_x) - (float)(v68.m_y * v67.m_x)))
                                               + (float)((float)((float)(v67.m_x * v68.m_w) - (float)(v68.m_x * v67.m_w))
                                                       * (float)((float)(v67.m_x * v68.m_w) - (float)(v68.m_x * v67.m_w))))))
               - 1.0842022e-19);
  __asm { fsel      f13, f1, f0, f31 }
  v24 = (float)((float)_FP13 * (float)((float)(v67.m_y * v68.m_x) - (float)(v68.m_y * v67.m_x)));
  v25 = (float)((float)((float)(v68.m_y * v67.m_w) - (float)(v67.m_y * v68.m_w)) * (float)_FP13);
  v26 = (float)((float)((float)(v67.m_x * v68.m_w) - (float)(v68.m_x * v67.m_w)) * (float)_FP13);
  v27 = bfx::CalcAngleBetween(v1: (const bfx::Vec3 *)&v68, v2: (const bfx::Vec3 *)&v67);
  this->m_angDiff = v27;
  if ( (float)((float)v27 * (float)57.295776) <= 0.5
    && (float)((float)(p_m_angularVel->m_x * p_m_angularVel->m_x)
             + (float)((float)(p_m_angularVel->m_y * p_m_angularVel->m_y)
                     + (float)(p_m_angularVel->m_z * p_m_angularVel->m_z))) < 0.00039999999 )
  {
    this->m_angDiff = 0.0;
    p_m_angularVel->m_x = 0.0;
    this->m_angularVel.m_y = 0.0;
    this->m_angularVel.m_z = 0.0;
  }
  if ( this->m_angDiff != 0.0 )
    goto LABEL_13;
  if ( p_m_angularVel->m_x != 0.0 || this->m_angularVel.m_y != 0.0 || (v28 = 1, this->m_angularVel.m_z != 0.0) )
    v28 = 0;
  if ( v28 == 0 )
  {
LABEL_13:
    if ( (float)((float)(this->m_angularVel.m_x * (float)v24)
               + (float)((float)((float)v25 * this->m_angularVel.m_y) + (float)((float)v26 * this->m_angularVel.m_z))) < 0.0 )
    {
      this->m_angDiff = this->m_angDiff * (float)-1.0;
      v24 = (float)((float)v24 * (float)-1.0);
      v25 = (float)((float)v25 * (float)-1.0);
      v26 = (float)((float)v26 * (float)-1.0);
    }
    v29 = bfx::CalcAccel(
            curX: 0.0,
            goalX: this->m_angDiff,
            speed: v21,
            maxAccel: (float)(*(float *)a6 * (float)0.017453292),
            simTime);
    p_m_angularVel->m_x = (float)((float)((float)v29 * (float)simTime) + (float)v21) * (float)v24;
    this->m_angularVel.m_y = (float)v25 * (float)((float)((float)v29 * (float)simTime) + (float)v21);
    this->m_angularVel.m_z = (float)v26 * (float)((float)((float)v29 * (float)simTime) + (float)v21);
  }
  if ( *(_BYTE *)(a6 + 4) == 0 )
    goto LABEL_24;
  v66.m_w = 1.0;
  v66.m_x = 0.0;
  v66.m_y = 0.0;
  bfx::Quat::Apply(this: &v68, result: &this->m_curRot, v: (const bfx::Vec3 *)&v66);
  v66.m_w = 0.0;
  v66.m_x = 0.0;
  v66.m_y = 1.0;
  bfx::Quat::Apply(this: &v67, result: &this->m_curRot, v: (const bfx::Vec3 *)&v66);
  v66.m_w = (float)(v68.m_y * v67.m_x) - (float)(v67.m_y * v68.m_x);
  v66.m_x = (float)(v67.m_y * v68.m_w) - (float)(v68.m_y * v67.m_w);
  v66.m_y = (float)(v68.m_x * v67.m_w) - (float)(v67.m_x * v68.m_w);
  v30 = bfx::CalcRotationCloseness(vForw: (const bfx::Vec3 *)&v68, vLeft: (const bfx::Vec3 *)&v66, bCheckLeftAxis: true);
  v31 = (float)((float)v30 * (float)57.295776);
  m_w = v68.m_w;
  v33 = v68.m_y;
  v34 = v68.m_x;
  if ( __fabs(v31) <= 0.5 )
  {
    this->m_rollAngularVel.m_x = 0.0;
    this->m_rollAngularVel.m_y = 0.0;
    this->m_rollAngularVel.m_z = 0.0;
LABEL_24:
    this->m_timeSpentRolled = 0.0;
    goto LABEL_25;
  }
  if ( (float)((float)(v68.m_x * this->m_rollAngularVel.m_y)
             + (float)((float)(v68.m_y * this->m_rollAngularVel.m_z) + (float)(v68.m_w * this->m_rollAngularVel.m_x))) < 0.0 )
  {
    m_w = (float)(v68.m_w * (float)-1.0);
    v34 = (float)(v68.m_x * (float)-1.0);
    v33 = (float)(v68.m_y * (float)-1.0);
    v31 = (float)((float)((float)v30 * (float)57.295776) * (float)-1.0);
  }
  _FP5 = (float)((float)-1.0 - (float)((float)v31 / (float)(*(float *)(a6 + 12) * 0.050000001)));
  _FP4 = (float)((float)1.0 - (float)((float)v31 / (float)(*(float *)(a6 + 12) * 0.050000001)));
  __asm { fsel      f3, f5, f13, f6 }
  __asm { fsel      f1, f4, f2, f30 }
  v39 = (float)((float)((float)_FP1 * *(float *)(a6 + 12)) * (float)-0.017453292);
  if ( v39 != 0.0 )
  {
    this->m_rollAngularVel.m_x = (float)m_w * (float)((float)((float)_FP1 * *(float *)(a6 + 12)) * (float)-0.017453292);
    this->m_rollAngularVel.m_y = (float)v34 * (float)v39;
    this->m_rollAngularVel.m_z = (float)v33 * (float)v39;
  }
  this->m_timeSpentRolled = (float)simTime + this->m_timeSpentRolled;
LABEL_25:
  if ( p_m_angularVel->m_x != 0.0 || this->m_angularVel.m_y != 0.0 || (v40 = 1, this->m_angularVel.m_z != 0.0) )
    v40 = 0;
  if ( v40 == 0 )
  {
    v41 = this->m_angularVel.m_y;
    v42 = this->m_angularVel.m_z;
    v70.m_x = p_m_angularVel->m_x;
    v70.m_y = v41;
    v70.m_w = 0.0;
    v70.m_z = v42;
    v43 = bfx::Quat::operator*(this: &v66, result: &v70, rhs: &this->m_curRot);
    v44 = this->m_curRot.m_w;
    v45 = this->m_curRot.m_x;
    v46 = this->m_curRot.m_y;
    v47 = v43->m_w;
    v70.m_w = v43->m_w;
    v48 = v43->m_x;
    v70.m_x = v43->m_x;
    v49 = (float)(v43->m_y * (float)((float)simTime * 0.5));
    v70.m_y = v43->m_y;
    v50 = (float)(v43->m_z * (float)((float)simTime * 0.5));
    v51 = this->m_curRot.m_z;
    this->m_curRot.m_w = (float)((float)v47 * (float)((float)simTime * 0.5)) + (float)v44;
    v70.m_w = (float)v47 * (float)((float)simTime * 0.5);
    v70.m_x = (float)v48 * (float)((float)simTime * 0.5);
    this->m_curRot.m_x = v70.m_x + (float)v45;
    v70.m_y = v49;
    this->m_curRot.m_y = (float)v46 + (float)v49;
    v70.m_z = v50;
    this->m_curRot.m_z = (float)v51 + (float)v50;
    bfx::Quat::Normalize(this: &this->m_curRot);
  }
  if ( this->m_rollAngularVel.m_x != 0.0
    || this->m_rollAngularVel.m_y != 0.0
    || (v52 = 1, this->m_rollAngularVel.m_z != 0.0) )
  {
    v52 = 0;
  }
  if ( v52 == 0 )
  {
    v53 = this->m_rollAngularVel.m_y;
    v54 = this->m_rollAngularVel.m_z;
    v69.m_x = this->m_rollAngularVel.m_x;
    v69.m_y = v53;
    v69.m_w = 0.0;
    v69.m_z = v54;
    v55 = bfx::Quat::operator*(this: &v66, result: &v69, rhs: &this->m_curRot);
    v56 = this->m_curRot.m_w;
    v57 = this->m_curRot.m_x;
    v58 = this->m_curRot.m_y;
    v59 = v55->m_w;
    v69.m_w = v55->m_w;
    v60 = v55->m_x;
    v69.m_x = v55->m_x;
    v61 = (float)((float)v59 * (float)((float)simTime * 0.5));
    v62 = v55->m_y;
    v63 = (float)(v55->m_y * (float)((float)simTime * 0.5));
    v69.m_y = v55->m_y;
    v64 = (float)(v55->m_z * (float)((float)simTime * 0.5));
    v65 = this->m_curRot.m_z;
    this->m_curRot.m_w = (float)v61 + (float)v56;
    v69.m_w = v61;
    v69.m_x = (float)v60 * (float)((float)simTime * 0.5);
    this->m_curRot.m_x = v69.m_x + (float)v57;
    v69.m_y = (float)v62 * (float)((float)simTime * 0.5);
    v69.m_z = v64;
    this->m_curRot.m_y = (float)v58 + (float)v63;
    this->m_curRot.m_z = (float)v65 + (float)v64;
    bfx::Quat::Normalize(this: &this->m_curRot);
  }
}


// ========================================================================
// ?CalcRepulsionAcc@Mover3DImpl@bfx@@QAA?AVVec3@2@PAVRepulsor3DImpl@2@M@Z
// EA  : 0x83265F60
// RVA : 0x01265F60
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

bfx::Mover3DImpl *__fastcall bfx::Mover3DImpl::CalcRepulsionAcc(
        bfx::Mover3DImpl *this,
        bfx::Vec3 *result,
        bfx::Repulsor3DImpl *pCurNeighbor,
        double maxRepulsionRadius)
{
  double Scale; // fp1
  float m_x; // r9
  float v10; // r7
  float m_y; // r5
  double v12; // fp0
  double v13; // fp29
  double v14; // fp10
  double v15; // fp31
  double v16; // fp0
  double v19; // fp4
  double v20; // fp3
  double v21; // fp2
  double v22; // fp0
  double v23; // fp12
  __int64 v24; // r10
  double v25; // fp11
  double v26; // fp13
  double v27; // fp12
  double v28; // fp11
  double v29; // fp0
  double v30; // fp10
  double v33; // fp12
  double v34; // fp10
  bfx::Quat *v37; // r3
  float v38; // r11
  double v39; // fp5
  double v44; // fp0
  double v49; // fp12
  float v50; // r9
  float v51; // r10
  float v52; // r8
  double v53; // fp9
  double v54; // fp8
  double v55; // fp7
  double v56; // fp5
  double v57; // fp13
  double v58; // fp12
  bfx::Vec3 v60; // [sp+50h] [-E0h]
  float m_z; // [sp+58h] [-D8h]
  bfx::Quat v62; // [sp+60h] [-D0h] BYREF
  bfx::Vec3 v63; // [sp+70h] [-C0h] BYREF
  bfx::Vec3 v64; // [sp+80h] [-B0h] BYREF
  bfx::Quat v65; // [sp+90h] [-A0h] BYREF
  bfx::Matrix v66; // [sp+A0h] [-90h] BYREF

  *(float *)&this->__vftable = 0.0;
  *(float *)&this->m_pSpace = 0.0;
  *(float *)&this->m_stranded = 0.0;
  Scale = bfx::GetScale();
  m_x = result[12].m_x;
  v10 = pCurNeighbor->m_pos.m_x;
  m_y = pCurNeighbor->m_pos.m_y;
  m_z = pCurNeighbor->m_pos.m_z;
  v62.m_w = result[11].m_y;
  v62.m_y = m_x;
  v62.m_x = result[11].m_z;
  v12 = (float)((float)((float)(v62.m_w - v10) * (float)(v62.m_w - v10))
              + (float)((float)((float)(m_x - m_z) * (float)(m_x - m_z))
                      + (float)((float)(v62.m_x - m_y) * (float)(v62.m_x - m_y))));
  v13 = __fsqrts(v12);
  if ( v13 < maxRepulsionRadius )
  {
    if ( v12 <= 1.1754944e-38 )
    {
      v22 = result[26].m_x;
      LODWORD(v24) = LODWORD(pCurNeighbor->m_vel.m_x);
      v23 = result[26].m_y;
      *(float *)&v24 = pCurNeighbor->m_vel.m_y;
      v25 = result[25].m_z;
      v62.m_y = pCurNeighbor->m_vel.m_z;
      v62.m_x = *(float *)&v24;
      LODWORD(v62.m_w) = v24;
      v26 = (float)((float)v22 - *(float *)&v24);
      v27 = (float)((float)v23 - v62.m_y);
      v28 = (float)((float)v25 - *((float *)&v24 + 1));
      v29 = (float)((float)((float)v28 * (float)v28)
                  + (float)((float)((float)v27 * (float)v27)
                          + (float)((float)((float)v22 - *(float *)&v24) * (float)((float)v22 - *(float *)&v24))));
      if ( v29 <= (float)((float)((float)Scale * (float)0.1) * (float)((float)Scale * (float)0.1)) )
      {
        v33 = result[15].m_x;
        v34 = result[15].m_y;
        LODWORD(v24) = LODWORD(result[47].m_z);
        v15 = 1.0;
        _FP4 = (float)((float)__fsqrts((float)((float)(result[14].m_z * result[14].m_z)
                                             + (float)((float)(result[15].m_y * result[15].m_y)
                                                     + (float)(result[15].m_x * result[15].m_x))))
                     - (float)1.0842022e-19);
        __asm { fsel      f1, f4, f3, f30 }
        v63.m_x = (float)_FP1 * result[14].m_z;
        v63.m_y = (float)v33 * (float)_FP1;
        v63.m_z = (float)v34 * (float)_FP1;
        bfx::Quat::Quat(this: &v65, axis: &v63, angle: (float)((float)v24 * (float)0.17453294));
        v37 = bfx::Quat::operator*(this: &v62, result: &v65, rhs: (const bfx::Quat *)&result[14].m_y);
        v65.m_w = v37->m_w;
        v65.m_x = v37->m_x;
        v65.m_y = v37->m_y;
        v65.m_z = v37->m_z;
        v64.m_x = 0.0;
        v64.m_y = 0.0;
        v64.m_z = 0.0;
        bfx::Matrix::Build(this: &v66, q: &v65, pos: &v64);
        v16 = 1.0842022e-19;
        v19 = v66.m_data[0];
        v20 = v66.m_data[1];
        v21 = v66.m_data[2];
      }
      else
      {
        v30 = __fsqrts(v29);
        v15 = 1.0;
        v16 = 1.0842022e-19;
        _FP9 = (float)((float)v30 - (float)1.0842022e-19);
        __asm { fsel      f7, f9, f8, f30 }
        v21 = -(float)((float)v27 * (float)_FP7);
        v20 = -(float)((float)v26 * (float)_FP7);
        v19 = -(float)((float)_FP7 * (float)v28);
      }
    }
    else
    {
      v14 = __fsqrts(v12);
      v15 = 1.0;
      v16 = 1.0842022e-19;
      _FP9 = (float)((float)v14 - (float)1.0842022e-19);
      __asm { fsel      f7, f9, f8, f30 }
      v19 = (float)((float)(v62.m_w - v10) * (float)_FP7);
      v20 = (float)((float)(v62.m_x - m_y) * (float)_FP7);
      v21 = (float)((float)(m_x - m_z) * (float)_FP7);
    }
    v38 = result[8].m_z;
    v39 = 0.0;
    if ( (float)(*(float *)(LODWORD(v38) + 4) + pCurNeighbor->m_repulsionPackage.m_sphereData.m_outerCushion) > v16 )
    {
      _FP8 = -(float)((float)((float)v13
                            - (float)((float)(*(float *)LODWORD(v38) + *(float *)(LODWORD(v38) + 8))
                                    + (float)(pCurNeighbor->m_repulsionPackage.m_sphereData.m_radius
                                            + pCurNeighbor->m_repulsionPackage.m_sphereData.m_innerCushion)))
                    / (float)((float)((float)((float)((float)((float)(*(float *)(LODWORD(v38) + 4)
                                                                    + pCurNeighbor->m_repulsionPackage.m_sphereData.m_outerCushion)
                                                            + *(float *)LODWORD(v38))
                                                    + *(float *)(LODWORD(v38) + 8))
                                            + pCurNeighbor->m_repulsionPackage.m_sphereData.m_radius)
                                    + pCurNeighbor->m_repulsionPackage.m_sphereData.m_innerCushion)
                            - (float)((float)(*(float *)LODWORD(v38) + *(float *)(LODWORD(v38) + 8))
                                    + (float)(pCurNeighbor->m_repulsionPackage.m_sphereData.m_radius
                                            + pCurNeighbor->m_repulsionPackage.m_sphereData.m_innerCushion))));
      _FP7 = (float)((float)v15
                   - (float)((float)((float)v13
                                   - (float)((float)(*(float *)LODWORD(v38) + *(float *)(LODWORD(v38) + 8))
                                           + (float)(pCurNeighbor->m_repulsionPackage.m_sphereData.m_radius
                                                   + pCurNeighbor->m_repulsionPackage.m_sphereData.m_innerCushion)))
                           / (float)((float)((float)((float)((float)((float)(*(float *)(LODWORD(v38) + 4)
                                                                           + pCurNeighbor->m_repulsionPackage.m_sphereData.m_outerCushion)
                                                                   + *(float *)LODWORD(v38))
                                                           + *(float *)(LODWORD(v38) + 8))
                                                   + pCurNeighbor->m_repulsionPackage.m_sphereData.m_radius)
                                           + pCurNeighbor->m_repulsionPackage.m_sphereData.m_innerCushion)
                                   - (float)((float)(*(float *)LODWORD(v38) + *(float *)(LODWORD(v38) + 8))
                                           + (float)(pCurNeighbor->m_repulsionPackage.m_sphereData.m_radius
                                                   + pCurNeighbor->m_repulsionPackage.m_sphereData.m_innerCushion)))));
      __asm { fsel      f5, f8, f6, f9 }
      __asm { fsel      f0, f7, f1, f31 }
      v39 = (float)((float)v15 - (float)_FP0);
    }
    v44 = 0.0;
    _FP9 = -(float)((float)((float)v13
                          - (float)(*(float *)LODWORD(v38) + pCurNeighbor->m_repulsionPackage.m_sphereData.m_radius))
                  / (float)((float)((float)(*(float *)LODWORD(v38) + *(float *)(LODWORD(v38) + 8))
                                  + (float)(pCurNeighbor->m_repulsionPackage.m_sphereData.m_radius
                                          + pCurNeighbor->m_repulsionPackage.m_sphereData.m_innerCushion))
                          - (float)(*(float *)LODWORD(v38) + pCurNeighbor->m_repulsionPackage.m_sphereData.m_radius)));
    _FP8 = (float)((float)v15
                 - (float)((float)((float)v13
                                 - (float)(*(float *)LODWORD(v38)
                                         + pCurNeighbor->m_repulsionPackage.m_sphereData.m_radius))
                         / (float)((float)((float)(*(float *)LODWORD(v38) + *(float *)(LODWORD(v38) + 8))
                                         + (float)(pCurNeighbor->m_repulsionPackage.m_sphereData.m_radius
                                                 + pCurNeighbor->m_repulsionPackage.m_sphereData.m_innerCushion))
                                 - (float)(*(float *)LODWORD(v38)
                                         + pCurNeighbor->m_repulsionPackage.m_sphereData.m_radius))));
    __asm { fsel      f7, f9, f6, f10 }
    __asm { fsel      f1, f8, f6, f31 }
    if ( v39 > 0.0 && *(float *)(LODWORD(v38) + 4) != 0.0 )
      v44 = (float)(*(float *)(LODWORD(v38) + 16) / *(float *)(LODWORD(v38) + 4));
    if ( (float)((float)v15 - (float)_FP1) > 0.0 && *(float *)(LODWORD(v38) + 8) != 0.0 )
      v44 = (float)(*(float *)(LODWORD(v38) + 20) / *(float *)(LODWORD(v38) + 8));
    v49 = __fsqrts(v44);
    if ( BYTE1(result[10].m_y) != 0 || *(_DWORD *)(LODWORD(v38) + 44) != 0 )
      v60 = bfx::ZERO_VEC;
    else
      v60 = *(bfx::Vec3 *)((char *)result + 308);
    v50 = pCurNeighbor->m_vel.m_z;
    v51 = pCurNeighbor->m_vel.m_x;
    v52 = result[8].m_z;
    v53 = *(float *)&this->__vftable;
    v54 = *(float *)&this->m_pSpace;
    v62.m_x = pCurNeighbor->m_vel.m_y;
    v62.m_y = v50;
    v55 = *(float *)&this->m_stranded;
    v62.m_w = v51;
    v56 = (float)((float)(*(float *)(LODWORD(v52) + 16) * (float)v39)
                + (float)((float)((float)((float)((float)(v51 - v60.m_x) * (float)v19)
                                        + (float)((float)((float)(v50 - v60.m_z) * (float)v21)
                                                + (float)((float)(v62.m_x - v60.m_y) * (float)v20)))
                                * (float)((float)v49 * (float)0.69999999))
                        + (float)(*(float *)(LODWORD(v52) + 20) * (float)((float)v15 - (float)_FP1))));
    v57 = (float)((float)v20 * (float)((float)v56 + *(float *)(LODWORD(v52) + 12)));
    v58 = (float)((float)v21 * (float)((float)v56 + *(float *)(LODWORD(v52) + 12)));
    *(float *)&this->__vftable = (float)v53 + (float)((float)((float)v56 + *(float *)(LODWORD(v52) + 12)) * (float)v19);
    *(float *)&this->m_pSpace = (float)v57 + (float)v54;
    *(float *)&this->m_stranded = (float)v55 + (float)v58;
  }
  return this;
}


// ========================================================================
// ?ChooseDefaultForward@Mover3DImpl@bfx@@QAA?AVVec3@2@ABV32@@Z
// EA  : 0x832663D0
// RVA : 0x012663D0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

bfx::Mover3DImpl *__fastcall bfx::Mover3DImpl::ChooseDefaultForward(
        bfx::Mover3DImpl *this,
        bfx::Vec3 *result,
        const bfx::Vec3 *vecToCorner)
{
  double v3; // fp13
  double m_z; // fp12
  double m_y; // fp11
  bfx::Quat *v7; // r3
  double m_w; // fp0
  double v9; // fp13
  double v10; // fp12
  double v11; // fp9
  double m_x; // fp12
  double v15; // fp2
  double v16; // fp0
  bfx::Quat v19; // [sp+50h] [-30h] BYREF

  v3 = (float)(result[27].m_x * result[27].m_x);
  m_z = result[26].m_z;
  m_y = result[27].m_y;
  *(float *)&this->__vftable = 0.0;
  *(float *)&this->m_pSpace = 0.0;
  *(float *)&this->m_stranded = 0.0;
  if ( (float)((float)((float)m_y * (float)m_y) + (float)((float)((float)m_z * (float)m_z) + (float)v3)) > 0.0009765625 )
  {
    m_x = result[26].m_x;
    _FP5 = (float)((float)__fsqrts((float)((float)(result[25].m_z * result[25].m_z)
                                         + (float)((float)(result[26].m_y * result[26].m_y)
                                                 + (float)(result[26].m_x * result[26].m_x))))
                 - 1.0842022e-19);
    __asm { fsel      f3, f5, f4, f31 }
    v15 = (float)(result[25].m_z * (float)_FP3);
    v16 = (float)(result[26].m_y * (float)_FP3);
  }
  else
  {
    if ( *(_DWORD *)(LODWORD(result[8].m_z) + 68) != 0 )
    {
      m_w = vecToCorner->m_x;
      v9 = vecToCorner->m_y;
      v10 = vecToCorner->m_z;
    }
    else
    {
      v7 = bfx::Quat::Apply(this: &v19, result: (bfx::Quat *)&result[14].m_y, v: &FWD_VEC);
      m_w = v7->m_w;
      v9 = v7->m_x;
      v10 = v7->m_y;
    }
    *(float *)&this->m_stranded = v10;
    v11 = *(float *)&this->m_stranded;
    *(float *)&this->__vftable = m_w;
    *(float *)&this->m_pSpace = v9;
    m_x = v9;
    _FP5 = (float)((float)__fsqrts((float)((float)((float)v11 * (float)v11)
                                         + (float)((float)((float)m_w * (float)m_w) + (float)((float)v9 * (float)v9))))
                 - 1.0842022e-19);
    __asm { fsel      f3, f5, f4, f31 }
    v15 = (float)((float)m_w * (float)_FP3);
    v16 = (float)((float)v11 * (float)_FP3);
  }
  *(float *)&this->m_stranded = v16;
  *(float *)&this->m_pSpace = (float)m_x * (float)_FP3;
  *(float *)&this->__vftable = v15;
  return this;
}


// ========================================================================
// ?CalcMaxDecel@Mover3DImpl@bfx@@QAA?AVVec3@2@MM@Z
// EA  : 0x83266528
// RVA : 0x01266528
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

bfx::Mover3DImpl *__fastcall bfx::Mover3DImpl::CalcMaxDecel(
        bfx::Mover3DImpl *this,
        bfx::Vec3 *result,
        double simTime,
        double desiredSpeed)
{
  float m_z; // r9
  float m_y; // r8
  double v7; // fp11
  double v8; // fp2
  double v9; // fp11
  double v10; // fp31
  double v11; // fp30
  double v12; // fp29
  double v13; // fp1
  float v14; // r8
  float v15; // r7
  float m_x; // [sp+54h] [-3Ch]

  m_z = result[25].m_z;
  m_y = result[26].m_y;
  m_x = result[26].m_x;
  v7 = __fsqrts((float)((float)(m_z * m_z) + (float)((float)(m_x * m_x) + (float)(m_y * m_y))));
  v8 = (float)((float)v7 - (float)desiredSpeed);
  if ( v8 <= 1.0842022e-19 )
  {
    v14 = bfx::ZERO_VEC.m_y;
    v15 = bfx::ZERO_VEC.m_z;
    this->__vftable = (bfx::Mover3DImpl_vtbl *)LODWORD(bfx::ZERO_VEC.m_x);
    *(float *)&this->m_pSpace = v14;
    *(float *)&this->m_stranded = v15;
  }
  else
  {
    v9 = (float)((float)1.0 / (float)v7);
    v10 = (float)((float)v9 * m_z);
    v11 = (float)((float)v9 * m_x);
    v12 = (float)((float)v9 * m_y);
    v13 = bfx::LimitDecelToPreventOvershoot(
            decel: (float)(*(float *)(LODWORD(result[8].m_z) + 48) / *(float *)(LODWORD(result[8].m_z) + 52)),
            speed: v8,
            simTime);
    *(float *)&this->m_stranded = (float)v12 * (float)-v13;
    *(float *)&this->m_pSpace = (float)v11 * (float)-v13;
    *(float *)&this->__vftable = (float)v10 * (float)-v13;
  }
  return this;
}


// ========================================================================
// ?GetSmallestOrbit@Mover3DImpl@bfx@@QAA?AUOrbit@2@ABVVec3@2@M000@Z
// EA  : 0x83266640
// RVA : 0x01266640
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

bfx::Mover3DImpl *__fastcall bfx::Mover3DImpl::GetSmallestOrbit(
        bfx::Mover3DImpl *this,
        bfx::Orbit *result,
        const bfx::Vec3 *vel,
        double maxAcc,
        const bfx::Vec3 *myPos,
        const bfx::Vec3 *vTanj,
        const bfx::Vec3 *vUp,
        float *a8)
{
  double v8; // fp13
  double v9; // fp7
  double v10; // fp10
  double v11; // fp8
  double v12; // fp7
  double m_x; // fp6
  double m_y; // fp5
  double m_z; // fp4

  if ( maxAcc == 0.0 )
  {
    v8 = 3.4028235e38;
  }
  else
  {
    v9 = __fsqrts((float)((float)(vel->m_z * vel->m_z)
                        + (float)((float)(vel->m_x * vel->m_x) + (float)(vel->m_y * vel->m_y))));
    v8 = (float)((float)((float)v9 / (float)maxAcc) * (float)v9);
  }
  v10 = (float)(vUp->m_z * (float)v8);
  v11 = (float)(vUp->m_x * (float)v8);
  v12 = (float)(vUp->m_y * (float)v8);
  m_x = vTanj->m_x;
  m_y = vTanj->m_y;
  m_z = vTanj->m_z;
  this->m_tune.m_repulsionPackage.m_sphereData.m_radius = v8;
  *(float *)&this->m_stranded = (float)m_z + (float)v10;
  *(float *)&this->__vftable = (float)m_x + (float)v11;
  *(float *)&this->m_pSpace = (float)m_y + (float)v12;
  this->m_tune.m_repulsionPackage.m_sphereData.m_outerCushion = *a8;
  this->m_tune.m_repulsionPackage.m_sphereData.m_innerCushion = a8[1];
  this->m_tune.m_repulsionPackage.m_sphereForces.m_initialAcc = a8[2];
  return this;
}


// ========================================================================
// ?GetCirclingDirection@bfx@@YAMABVVec3@1@000@Z
// EA  : 0x832666E0
// RVA : 0x012666E0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

float __fastcall bfx::GetCirclingDirection(
        const bfx::Vec3 *vel,
        const bfx::Vec3 *vCenter,
        const bfx::Vec3 *myPos,
        const bfx::Vec3 *vUp)
{
  double v4; // fp1

  if ( (float)((float)(vUp->m_x
                     * (float)((float)(vel->m_y * (float)(myPos->m_z - vCenter->m_z))
                             - (float)(vel->m_z * (float)(myPos->m_y - vCenter->m_y))))
             + (float)((float)(vUp->m_z
                             * (float)((float)(vel->m_x * (float)(myPos->m_y - vCenter->m_y))
                                     - (float)(vel->m_y * (float)(myPos->m_x - vCenter->m_x))))
                     + (float)(vUp->m_y
                             * (float)((float)(vel->m_z * (float)(myPos->m_x - vCenter->m_x))
                                     - (float)(vel->m_x * (float)(myPos->m_z - vCenter->m_z)))))) <= 0.0 )
    v4 = 1.0;
  else
    v4 = -1.0;
  return *((float *)&v4 + 1);
}


// ========================================================================
// ?GetTangential@Mover3DImpl@bfx@@QAA?AVVec3@2@ABV32@@Z
// EA  : 0x83266768
// RVA : 0x01266768
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

bfx::Mover3DImpl *__fastcall bfx::Mover3DImpl::GetTangential(
        bfx::Mover3DImpl *this,
        bfx::Vec3 *result,
        const bfx::Vec3 *desCenter)
{
  double m_z; // fp13
  double m_x; // fp12
  double m_y; // fp11
  float v9; // r10
  float v10; // r9
  double CirclingDirection; // fp1
  float v12; // r8
  bfx::Vec3 *UpVec; // r3
  double v14; // fp12
  double v15; // fp13
  bfx::Mover3DImpl *v16; // r3
  double v17; // fp4
  double v18; // fp3
  double v19; // fp2
  double v20; // fp1
  bfx::Quat v23; // [sp+50h] [-60h] BYREF
  bfx::Vec3 v24; // [sp+60h] [-50h] BYREF
  bfx::Quat v25; // [sp+70h] [-40h] BYREF

  m_z = result[14].m_z;
  m_x = result[15].m_x;
  m_y = result[15].m_y;
  v25.m_w = result[14].m_y;
  v24.m_x = 0.0;
  v25.m_x = m_z;
  v24.m_y = 0.0;
  v25.m_y = m_x;
  v24.m_z = 1.0;
  v25.m_z = m_y;
  bfx::Quat::Apply(this: &v23, result: &v25, v: &v24);
  if ( result[31].m_x == 0.0 )
  {
    v9 = result[11].m_z;
    v10 = result[12].m_x;
    v24.m_x = result[11].m_y;
    v24.m_y = v9;
    v24.m_z = v10;
    CirclingDirection = bfx::GetCirclingDirection(
                          vel: (bfx::Vec3 *)((char *)result + 320),
                          vCenter: desCenter,
                          myPos: &v24,
                          vUp: (const bfx::Vec3 *)&v23);
    v12 = result[8].m_z;
    result[31].m_x = CirclingDirection;
    if ( *(_BYTE *)(LODWORD(v12) + 64) != 0 )
    {
      UpVec = bfx::GetUpVec(result: &v24);
      result[33].m_x = UpVec->m_x;
      result[33].m_y = UpVec->m_y;
      v14 = UpVec->m_z;
    }
    else
    {
      v15 = v23.m_x;
      v14 = v23.m_y;
      result[33].m_x = v23.m_w;
      result[33].m_y = v15;
    }
    result[33].m_z = v14;
  }
  v16 = this;
  v17 = result[31].m_x;
  v18 = (float)((float)(result[26].m_z * result[33].m_z) - (float)(result[33].m_x * result[27].m_y));
  v19 = (float)((float)(result[33].m_x * result[27].m_x) - (float)(result[26].m_z * result[33].m_y));
  v20 = (float)((float)(result[33].m_y * result[27].m_y) - (float)(result[33].m_z * result[27].m_x));
  *(float *)&this->__vftable = (float)(result[33].m_y * result[27].m_y) - (float)(result[33].m_z * result[27].m_x);
  _FP8 = (float)((float)__fsqrts((float)((float)((float)v20 * (float)v20)
                                       + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18))))
               - (float)1.0842022e-19);
  __asm { fsel      f6, f8, f7, f31 }
  *(float *)&this->__vftable = (float)v20 * (float)_FP6;
  *(float *)&this->m_pSpace = (float)v18 * (float)_FP6;
  *(float *)&this->m_stranded = (float)v19 * (float)_FP6;
  if ( v17 > 0.0 )
  {
    *(float *)&this->__vftable = (float)((float)v20 * (float)_FP6) * (float)-1.0;
    *(float *)&this->m_pSpace = (float)((float)v18 * (float)_FP6) * (float)-1.0;
    *(float *)&this->m_stranded = (float)((float)v19 * (float)_FP6) * (float)-1.0;
  }
  return v16;
}


// ========================================================================
// ?CalcBestFitRadius@bfx@@YAMABVVec3@1@0AAUOrbit@1@@Z
// EA  : 0x83266910
// RVA : 0x01266910
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

float __fastcall bfx::CalcBestFitRadius(const bfx::Vec3 *moverPos, const bfx::Vec3 *vTanj, bfx::Orbit *desOrbit)
{
  double v5; // fp8
  double v6; // fp6
  bfx::UpAxis UpAxis; // r3
  double m_radius; // fp1
  bfx::Vec3 v10; // [sp+50h] [-30h] BYREF

  v5 = (float)(moverPos->m_y - desOrbit->m_center.m_y);
  v6 = (float)(moverPos->m_z - desOrbit->m_center.m_z);
  v10.m_x = moverPos->m_x - desOrbit->m_center.m_x;
  v10.m_y = v5;
  v10.m_z = v6;
  UpAxis = bfx::GetUpAxis();
  *bfx::GetUpComponent(vec: &v10, which: UpAxis) = 0.0;
  if ( (float)((float)((float)((float)(vTanj->m_x * v10.m_x)
                             + (float)((float)(vTanj->m_y * v10.m_y) + (float)(vTanj->m_z * v10.m_z)))
                     + desOrbit->m_radius)
             * (float)2.0) == 0.0 )
    m_radius = desOrbit->m_radius;
  else
    m_radius = (float)((float)((float)(desOrbit->m_radius * desOrbit->m_radius)
                             - (float)((float)(v10.m_z * v10.m_z)
                                     + (float)((float)(v10.m_x * v10.m_x) + (float)(v10.m_y * v10.m_y))))
                     / (float)((float)((float)((float)(vTanj->m_x * v10.m_x)
                                             + (float)((float)(vTanj->m_y * v10.m_y) + (float)(vTanj->m_z * v10.m_z)))
                                     + desOrbit->m_radius)
                             * (float)2.0));
  return *((float *)&m_radius + 1);
}


// ========================================================================
// ?KeepEvenKeel@Mover3DImpl@bfx@@QAAXABVVec3@2@@Z
// EA  : 0x832669F0
// RVA : 0x012669F0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __fastcall bfx::Mover3DImpl::KeepEvenKeel(bfx::Mover3DImpl *this, const bfx::Vec3 *vDesiredUp)
{
  char v4; // r11
  double v5; // fp13
  double m_x; // fp12
  double v7; // fp10
  double m_y; // fp9
  double m_z; // fp8
  bfx::Mover3DImpl::HoverData *p_m_hoverData; // r31
  double v11; // fp29
  double v12; // fp28
  bfx::UpAxis UpAxis; // r3
  float *UpComponent; // r3
  double v15; // fp0
  double v16; // fp1
  double v17; // fp2
  double v18; // fp11
  double v19; // fp8
  double v20; // fp7
  double v23; // fp8
  double v24; // fp5
  double v25; // fp6
  bfx::Vec3 v28; // [sp+50h] [-70h] BYREF
  bfx::Quat v29; // [sp+60h] [-60h] BYREF
  bfx::Quat v30; // [sp+70h] [-50h] BYREF

  if ( vDesiredUp->m_x != 0.0 || vDesiredUp->m_y != 0.0 || (v4 = 1, vDesiredUp->m_z != 0.0) )
    v4 = 0;
  if ( v4 == 0 )
  {
    v5 = (float)(this->m_hoverData.m_vForwVel.m_y * this->m_hoverData.m_vForwVel.m_y);
    m_x = this->m_hoverData.m_vForwVel.m_x;
    v7 = this->m_rot.m_x;
    m_y = this->m_rot.m_y;
    m_z = this->m_rot.m_z;
    p_m_hoverData = &this->m_hoverData;
    v30.m_w = this->m_rot.m_w;
    v28.m_x = 0.0;
    v30.m_x = v7;
    v30.m_y = m_y;
    v28.m_y = 0.0;
    v30.m_z = m_z;
    v28.m_z = 1.0;
    v11 = __fsqrts((float)((float)(this->m_hoverData.m_vForwVel.m_z * this->m_hoverData.m_vForwVel.m_z)
                         + (float)((float)((float)m_x * (float)m_x) + (float)v5)));
    bfx::Quat::Apply(this: &v29, result: &v30, v: &v28);
    v12 = (float)((float)(vDesiredUp->m_z * v29.m_y)
                + (float)((float)(vDesiredUp->m_x * v29.m_w) + (float)(vDesiredUp->m_y * v29.m_x)));
    UpAxis = bfx::GetUpAxis();
    UpComponent = bfx::GetUpComponent(vec: &this->m_hoverData.m_vForwVel, which: UpAxis);
    if ( v12 < 0.99902344 || (v15 = *UpComponent) > 0.0009765625 )
    {
      v16 = this->m_hoverData.m_vForwVel.m_z;
      v17 = this->m_hoverData.m_vForwVel.m_y;
      v18 = (float)((float)(this->m_hoverData.m_vForwVel.m_x * vDesiredUp->m_z)
                  - (float)(this->m_hoverData.m_vForwVel.m_z * vDesiredUp->m_x));
      v19 = (float)((float)(this->m_hoverData.m_vForwVel.m_y * vDesiredUp->m_x)
                  - (float)(this->m_hoverData.m_vForwVel.m_x * vDesiredUp->m_y));
      v20 = (float)((float)(this->m_hoverData.m_vForwVel.m_z * vDesiredUp->m_y)
                  - (float)(this->m_hoverData.m_vForwVel.m_y * vDesiredUp->m_z));
      _FP6 = (float)((float)__fsqrts((float)((float)((float)v20 * (float)v20)
                                           + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18))))
                   - 1.0842022e-19);
      __asm { fsel      f12, f6, f5, f31 }
      v23 = (float)((float)(vDesiredUp->m_x
                          * (float)((float)((float)(p_m_hoverData->m_vForwVel.m_y * vDesiredUp->m_x)
                                          - (float)(p_m_hoverData->m_vForwVel.m_x * vDesiredUp->m_y))
                                  * (float)_FP12))
                  - (float)(vDesiredUp->m_z
                          * (float)((float)((float)(p_m_hoverData->m_vForwVel.m_z * vDesiredUp->m_y)
                                          - (float)(p_m_hoverData->m_vForwVel.m_y * vDesiredUp->m_z))
                                  * (float)_FP12)));
      v24 = (float)((float)(vDesiredUp->m_z
                          * (float)((float)((float)(p_m_hoverData->m_vForwVel.m_x * vDesiredUp->m_z)
                                          - (float)(p_m_hoverData->m_vForwVel.m_z * vDesiredUp->m_x))
                                  * (float)_FP12))
                  - (float)(vDesiredUp->m_y
                          * (float)((float)((float)(p_m_hoverData->m_vForwVel.m_y * vDesiredUp->m_x)
                                          - (float)(p_m_hoverData->m_vForwVel.m_x * vDesiredUp->m_y))
                                  * (float)_FP12)));
      v25 = (float)((float)(vDesiredUp->m_y
                          * (float)((float)((float)(p_m_hoverData->m_vForwVel.m_z * vDesiredUp->m_y)
                                          - (float)(p_m_hoverData->m_vForwVel.m_y * vDesiredUp->m_z))
                                  * (float)_FP12))
                  - (float)(vDesiredUp->m_x
                          * (float)((float)((float)(p_m_hoverData->m_vForwVel.m_x * vDesiredUp->m_z)
                                          - (float)(p_m_hoverData->m_vForwVel.m_z * vDesiredUp->m_x))
                                  * (float)_FP12)));
      _FP11 = (float)((float)__fsqrts((float)((float)((float)v24 * (float)v24)
                                            + (float)((float)((float)v25 * (float)v25) + (float)((float)v23 * (float)v23))))
                    - 1.0842022e-19);
      __asm { fsel      f7, f11, f9, f31 }
      this->m_hoverData.m_vOrientationKeeping.m_x = (float)((float)((float)((float)(vDesiredUp->m_z
                                                                                  * (float)((float)((float)(p_m_hoverData->m_vForwVel.m_x * vDesiredUp->m_z)
                                                                                                  - (float)(p_m_hoverData->m_vForwVel.m_z * vDesiredUp->m_x))
                                                                                          * (float)_FP12))
                                                                          - (float)(vDesiredUp->m_y
                                                                                  * (float)((float)((float)(p_m_hoverData->m_vForwVel.m_y * vDesiredUp->m_x)
                                                                                                  - (float)(p_m_hoverData->m_vForwVel.m_x * vDesiredUp->m_y))
                                                                                          * (float)_FP12)))
                                                                  * (float)_FP7)
                                                          * (float)v11)
                                                  - p_m_hoverData->m_vForwVel.m_x;
      this->m_hoverData.m_vOrientationKeeping.m_y = (float)((float)((float)v23 * (float)_FP7) * (float)v11) - (float)v17;
      this->m_hoverData.m_vOrientationKeeping.m_z = (float)((float)((float)v25 * (float)_FP7) * (float)v11) - (float)v16;
    }
    else if ( v15 != 0.0 )
    {
      *UpComponent = 0.0;
    }
  }
}


// ========================================================================
// ?CompareFollowerBuddies@bfx@@YAHPBX0@Z
// EA  : 0x83266C08
// RVA : 0x01266C08
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

int __fastcall bfx::CompareFollowerBuddies(float *a, float *b)
{
  double v2; // fp0
  double v3; // fp13
  int result; // r3

  v2 = *a;
  v3 = *b;
  if ( v2 > v3 )
    return 1;
  result = -1;
  if ( v2 >= v3 )
    return 0;
  return result;
}


// ========================================================================
// ?RegeneratePath@Mover3DImpl@bfx@@AAAXPBVVolume@2@0@Z
// EA  : 0x83266C38
// RVA : 0x01266C38
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __fastcall bfx::Mover3DImpl::RegeneratePath(
        bfx::Mover3DImpl *this,
        const bfx::Volume *pOldVolume,
        const bfx::Volume *pNewVolume)
{
  bfx::Path3D *m_pPath; // r11
  bfx::Path3D *Path; // r27
  float m_y; // r9
  float m_z; // r8
  const bfx::Mover3DTune *m_pTune; // r7
  bfx::Planner3D *Planner3D; // r3
  bfx::Vec3 *ClosestReachableVolume; // r3
  bfx::Vec3 *v12; // r30
  const bfx::Mover3DTune *v13; // r11
  const bfx::Volume *v14; // r7
  float m_x; // r10
  float v16; // r9
  bfx::Space *m_pSpace; // r3
  float v18; // r30
  bfx::Path3D *v19; // r30
  bfx::Path3DSpec v20; // [sp+50h] [-80h] BYREF
  __int64 v21; // [sp+58h] [-78h] BYREF
  bfx::Vec3 v22; // [sp+60h] [-70h] BYREF
  bfx::Vec3 v23; // [sp+70h] [-60h] BYREF
  bfx::Volume v24; // [sp+80h] [-50h] BYREF

  if ( pNewVolume != pOldVolume )
  {
    m_pPath = this->m_pPath;
    Path = nullptr;
    if ( m_pPath != nullptr && pNewVolume != nullptr )
    {
      m_y = m_pPath->m_finalPos.m_y;
      m_z = m_pPath->m_finalPos.m_z;
      m_pTune = this->m_pTune;
      v22.m_x = m_pPath->m_finalPos.m_x;
      v20.m_customGeoMatchFlags = -1;
      v22.m_y = m_y;
      v22.m_z = m_z;
      v20.m_customGeoMatchFlags = m_pTune->m_customGeoMatchFlags;
      Planner3D = bfx::GetPlanner3D(pSpace: this->m_pSpace);
      ClosestReachableVolume = (bfx::Vec3 *)bfx::Planner3D::GetClosestReachableVolume(
                                              this: Planner3D,
                                              pStartVolume: pNewVolume,
                                              pos: &v22,
                                              pathSpec: &v20);
      v12 = ClosestReachableVolume;
      if ( ClosestReachableVolume != nullptr )
      {
        bfx::Volume::GetClosestPos(this: &v24, result: ClosestReachableVolume, pos: &v22);
        v13 = this->m_pTune;
        v14 = (const bfx::Volume *)v12;
        m_x = this->m_surfer.m_pos.m_x;
        v16 = this->m_surfer.m_pos.m_y;
        HIDWORD(v21) = -1;
        m_pSpace = this->m_pSpace;
        v18 = this->m_surfer.m_pos.m_z;
        HIDWORD(v21) = v13->m_customGeoMatchFlags;
        v23.m_x = m_x;
        v23.m_y = v16;
        v23.m_z = v18;
        Path = bfx::FindPath(
                 pSpace: m_pSpace,
                 startPos: &v23,
                 pStartVolume: pNewVolume,
                 goalPos: (const bfx::Vec3 *)&v24,
                 pGoalVolume: v14,
                 pathSpec: (const bfx::Path3DSpec *)&v21);
      }
    }
    v19 = this->m_pPath;
    if ( v19 != nullptr )
    {
      bfx::Path3D::~Path3D(this: this->m_pPath);
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v19);
    }
    this->m_pPath = nullptr;
    if ( Path != nullptr )
    {
      this->m_pPath = Path;
      this->m_curPathCC = (bfx::Path3D::Cursor)__PAIR64__((unsigned int)Path, 0);
    }
  }
}


// ========================================================================
// ?DestroyMover3D@bfx@@YAXPAVMover3D@1@@Z
// EA  : 0x83266D70
// RVA : 0x01266D70
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __fastcall bfx::DestroyMover3D(bfx::Mover3D *pMover)
{
  bfx::Mover3D *v2; // r11
  bfx::Mover3D *v3; // r30
  bool v4; // zf
  bfx::Mover3DSpaceComponent *Mover3DSpaceComponent; // r3
  int v6; // r10
  int v7; // r9
  int v8; // r8
  int v9; // r7
  int v10; // r6
  int v11; // r5
  int v12; // [sp+8h] [-78h]
  int v13; // [sp+Ch] [-74h]
  int v14; // [sp+10h] [-70h]
  int v15; // [sp+14h] [-6Ch]
  int v16; // [sp+18h] [-68h]
  bfx::Space *v17; // [sp+1Ch] [-64h]
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  v2 = pMover - 4;
  if ( pMover == nullptr )
    v2 = nullptr;
  bfx::LogDestroyMover3D(replayID: *(_DWORD *)&v2[576]);
  v4 = pMover != nullptr;
  v3 = pMover - 4;
  if ( !v4 )
    v3 = nullptr;
  Mover3DSpaceComponent = bfx::GetMover3DSpaceComponent(pSpace: *(bfx::Space **)&v3[4]);
  bfx::Mover3DSpaceComponent::RemoveMover(
    this: Mover3DSpaceComponent,
    pMover: (bfx::Space *)v3,
    a3: v11,
    a4: v10,
    a5: v9,
    a6: v8,
    a7: v7,
    a8: v6,
    a9: v12,
    a10: v13,
    a11: v14,
    a12: v15,
    a13: v16,
    a14: v17);
  (**(void (__fastcall ***)(bfx::Mover3D *, int))v3)(a1: v3, a2: 1);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$82719
// EA  : 0x83266E0C
// RVA : 0x01266E0C
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void _unwind_82719()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?Freeze@Mover3D@bfx@@QAAX_N@Z
// EA  : 0x83266E40
// RVA : 0x01266E40
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __fastcall bfx::Mover3D::Freeze(bfx::Mover3D *this, bool freeze)
{
  bfx::Mover3D *v4; // r30
  bool v5; // zf
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  v5 = this != nullptr;
  v4 = this - 4;
  if ( !v5 )
    v4 = nullptr;
  bfx::LogMover3DFreeze(replayID: *(_DWORD *)&v4[576], freeze);
  v4[125] = (bfx::Mover3D)freeze;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$82765
// EA  : 0x83266EB0
// RVA : 0x01266EB0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void _unwind_82765()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?SetTune@Mover3D@bfx@@QAAXPBUMover3DTune@2@@Z
// EA  : 0x83266EE0
// RVA : 0x01266EE0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __fastcall bfx::Mover3D::SetTune(bfx::Mover3D *this, const bfx::Mover3DTune *pTune)
{
  bfx::Mover3D *v4; // r30
  bool v5; // zf
  _DWORD *v6; // r11
  _DWORD *v7; // r10
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-40h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  v5 = this != nullptr;
  v4 = this - 4;
  if ( !v5 )
    v4 = nullptr;
  bfx::LogMover3DSetTune(replayID: *(_DWORD *)&v4[576], pTune);
  memcpy(Dst: &v4[12], Src: pTune, Size: 0x5Cu);
  bfx::ApplyLimits_Mover3DTune(tune: (bfx::Mover3DTune *)&v4[12]);
  v6 = *(_DWORD **)&v4[236];
  if ( v6 != nullptr )
  {
    v7 = *(_DWORD **)&v4[104];
    v6[8] = *v7;
    v6[9] = v7[1];
    v6[10] = v7[2];
  }
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$82811
// EA  : 0x83266F94
// RVA : 0x01266F94
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void _unwind_82811()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 144 + 80));
}


// ========================================================================
// ?GetClosestReachablePos@Mover3D@bfx@@QBA?AVVector3@2@ABV32@@Z
// EA  : 0x83266FC8
// RVA : 0x01266FC8
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

bfx::Mover3D *__fastcall bfx::Mover3D::GetClosestReachablePos(
        bfx::Mover3D *this,
        bfx::Vector3 *result,
        const bfx::Vector3 *goalPos)
{
  char *p_m_z; // r29
  bool v7; // zf
  int v8; // r27
  double m_y; // fp13
  double m_x; // fp12
  bfx::Mover3DImpl *ClosestReachablePos; // r3
  bfx::Vec3 *v12; // r3
  double m_z; // fp11
  double v14; // fp10
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-80h]
  bfx::Vec3 v17; // [sp+58h] [-78h] BYREF
  bfx::Matrix v18; // [sp+68h] [-68h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  v7 = result != nullptr;
  p_m_z = (char *)&result[-1].m_z;
  if ( !v7 )
    p_m_z = nullptr;
  v8 = *((_DWORD *)p_m_z + 1);
  bfx::LogMover3DGetClosestReachablePos(replayID: *((_DWORD *)p_m_z + 144), goalPos);
  m_y = goalPos->m_y;
  m_x = goalPos->m_x;
  v17.m_z = goalPos->m_z;
  v17.m_x = m_x;
  v17.m_y = m_y;
  bfx::Matrix::operator*(this: &v18, result: (bfx::Vec3 *)(v8 + 124), rhs: &v17);
  ClosestReachablePos = bfx::Mover3DImpl::GetClosestReachablePos(
                          this: (bfx::Mover3DImpl *)&v18.m_data[4],
                          result: (bfx::Vec3 *)p_m_z,
                          goalPos: (const bfx::Vec3 *)&v18);
  v12 = bfx::Matrix::operator*(
          this: (bfx::Matrix *)&v18.m_data[8],
          result: (bfx::Vec3 *)(v8 + 60),
          rhs: (const bfx::Vec3 *)ClosestReachablePos);
  m_z = v12->m_z;
  v14 = v12->m_y;
  *(float *)this = v12->m_x;
  *((float *)this + 1) = v14;
  *((float *)this + 2) = m_z;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return this;
}


// ========================================================================
// __unwind$83587
// EA  : 0x832670A0
// RVA : 0x012670A0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void _unwind_83587()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 208 + 80));
}


// ========================================================================
// ?SetDebug@Mover3D@bfx@@QAAX_N@Z
// EA  : 0x832670D0
// RVA : 0x012670D0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __fastcall bfx::Mover3D::SetDebug(bfx::Mover3D *this, bool debug)
{
  bfx::Mover3D *v4; // r30
  bool v5; // zf
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  v5 = this != nullptr;
  v4 = this - 4;
  if ( !v5 )
    v4 = nullptr;
  bfx::LogMover3DSetDebug(replayID: *(_DWORD *)&v4[576], debug);
  v4[124] = (bfx::Mover3D)debug;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$83697
// EA  : 0x83267140
// RVA : 0x01267140
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void _unwind_83697()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?OverrideColor@Mover3D@bfx@@QAAXABVColor@2@@Z
// EA  : 0x83267170
// RVA : 0x01267170
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __fastcall bfx::Mover3D::OverrideColor(bfx::Mover3D *this, const bfx::Color *color)
{
  bfx::Mover3D *v4; // r30
  bool v5; // zf
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  v5 = this != nullptr;
  v4 = this - 4;
  if ( !v5 )
    v4 = nullptr;
  bfx::LogMover3DOverrideColor(replayID: *(_DWORD *)&v4[576], color);
  *(float *)&v4[108] = color->m_r;
  *(float *)&v4[112] = color->m_g;
  *(float *)&v4[116] = color->m_b;
  *(float *)&v4[120] = color->m_a;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$83743
// EA  : 0x832671FC
// RVA : 0x012671FC
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void _unwind_83743()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ??0Debug@HoverData@Mover3DImpl@bfx@@QAA@PAVSpace@3@@Z
// EA  : 0x83267228
// RVA : 0x01267228
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

bfx::Mover3DImpl::HoverData::Debug *__fastcall bfx::Mover3DImpl::HoverData::Debug::Debug(
        bfx::Mover3DImpl::HoverData::Debug *this,
        bfx::Space *pSpace)
{
  this->m_pSpace = pSpace;
  this->m_myOrbit.m_center.m_x = 0.0;
  this->m_myOrbit.m_center.m_y = 0.0;
  this->m_myOrbit.m_center.m_z = 0.0;
  this->m_myOrbit.m_radius = 0.0;
  this->m_myOrbit.m_rotationAxis.m_x = 0.0;
  this->m_myOrbit.m_rotationAxis.m_y = 0.0;
  this->m_myOrbit.m_rotationAxis.m_z = 0.0;
  this->m_desiredOrbit.m_center.m_x = 0.0;
  this->m_desiredOrbit.m_center.m_y = 0.0;
  this->m_desiredOrbit.m_center.m_z = 0.0;
  this->m_desiredOrbit.m_radius = 0.0;
  this->m_desiredOrbit.m_rotationAxis.m_x = 0.0;
  this->m_desiredOrbit.m_rotationAxis.m_y = 0.0;
  this->m_desiredOrbit.m_rotationAxis.m_z = 0.0;
  this->m_vRepulsion.m_x = 0.0;
  this->m_vRepulsion.m_y = 0.0;
  this->m_vRepulsion.m_z = 0.0;
  this->m_vSteering.m_x = 0.0;
  this->m_vSteering.m_y = 0.0;
  this->m_vSteering.m_z = 0.0;
  this->m_vTargetAttraction.m_x = 0.0;
  this->m_vTargetAttraction.m_y = 0.0;
  this->m_vTargetAttraction.m_z = 0.0;
  this->m_vBraking.m_x = 0.0;
  this->m_vBraking.m_y = 0.0;
  this->m_vBraking.m_z = 0.0;
  this->m_vCollisionPos.m_x = 0.0;
  this->m_vCollisionPos.m_y = 0.0;
  this->m_vCollisionPos.m_z = 0.0;
  this->m_vMyPos.m_x = 0.0;
  this->m_vMyPos.m_y = 0.0;
  this->m_vMyPos.m_z = 0.0;
  this->m_vCollisionPos.m_x = 0.0;
  this->m_vCollisionPos.m_y = 0.0;
  this->m_vCollisionPos.m_z = 0.0;
  this->m_vCirclingCenter.m_x = 0.0;
  this->m_vCirclingCenter.m_y = 0.0;
  this->m_vCirclingCenter.m_z = 0.0;
  this->m_vCirclingTangential.m_x = 0.0;
  this->m_vCirclingTangential.m_y = 0.0;
  this->m_vCirclingTangential.m_z = 0.0;
  this->m_enable = false;
  return this;
}


// ========================================================================
// ?DrawOrbits@Debug@HoverData@Mover3DImpl@bfx@@QBAXABVVec3@4@@Z
// EA  : 0x832672F0
// RVA : 0x012672F0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __fastcall bfx::Mover3DImpl::HoverData::Debug::DrawOrbits(
        bfx::Mover3DImpl::HoverData::Debug *this,
        const bfx::Vec3 *curPos)
{
  float m_y; // r8
  float m_z; // r6
  bfx::Space *m_pSpace; // r3
  double v7; // fp13
  double v8; // fp12
  double v9; // fp9
  double v10; // fp7
  double v11; // fp6
  bfx::Space *v12; // r3
  const bfx::Color *v13; // r6
  const bfx::Color *v14; // r6
  bfx::Color v15; // [sp+50h] [-50h] BYREF
  bfx::Sphere v16; // [sp+60h] [-40h] BYREF
  bfx::Vec3 v17; // [sp+70h] [-30h] BYREF
  float v18; // [sp+7Ch] [-24h]
  float v19; // [sp+80h] [-20h]
  float v20; // [sp+84h] [-1Ch]

  m_y = this->m_vCirclingCenter.m_y;
  m_z = this->m_vCirclingCenter.m_z;
  v16.m_pos.m_x = this->m_vCirclingCenter.m_x;
  v16.m_pos.m_y = m_y;
  v16.m_pos.m_z = m_z;
  v15.m_r = 0.5;
  v15.m_g = 1.0;
  v15.m_b = 1.0;
  m_pSpace = this->m_pSpace;
  v15.m_a = 1.0;
  v16.m_radius = 0.1;
  bfx::DrawSphere(pSpace: m_pSpace, sphere: &v16, color: &v15);
  v7 = curPos->m_y;
  v8 = curPos->m_z;
  v9 = (float)(curPos->m_x + this->m_vCirclingTangential.m_x);
  v10 = (float)(this->m_vCirclingTangential.m_y + curPos->m_y);
  v11 = (float)(this->m_vCirclingTangential.m_z + curPos->m_z);
  v17.m_x = curPos->m_x;
  v17.m_y = v7;
  v17.m_z = v8;
  v12 = this->m_pSpace;
  v18 = v9;
  v19 = v10;
  v20 = v11;
  bfx::DrawLineList(pSpace: v12, pVerts: &v17, numVerts: 2, color: &ColorRed_7);
  bfx::DrawCircle(
    pSpace: this->m_pSpace,
    pos: &this->m_myOrbit.m_center,
    N: &this->m_myOrbit.m_rotationAxis,
    radius: this->m_myOrbit.m_radius,
    color: v13,
    a6: &ColorCyan_7);
  bfx::DrawCircle(
    pSpace: this->m_pSpace,
    pos: &this->m_desiredOrbit.m_center,
    N: &this->m_desiredOrbit.m_rotationAxis,
    radius: this->m_desiredOrbit.m_radius,
    color: v14,
    a6: &ColorGray_7);
}


// ========================================================================
// ?EnableRepulsor@Mover3DImpl@bfx@@QAAX_N@Z
// EA  : 0x83267410
// RVA : 0x01267410
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __fastcall bfx::Mover3DImpl::EnableRepulsor(bfx::Mover3DImpl *this, bool enable)
{
  double Scale; // fp1
  const bfx::Mover3DTune *m_pTune; // r10
  double v5; // fp31
  bfx::Repulsor3DImpl *v6; // r3
  float m_y; // r8
  float m_z; // r29
  const bfx::Mover3DTune *v9; // r7
  bfx::Space *m_pSpace; // r4
  bfx::Repulsor3DImpl *v11; // r3
  bfx::Repulsor3DImpl *m_pRepulsor; // r29
  bfx::Vec3 v13; // [sp+58h] [-38h] BYREF

  if ( !enable || this->m_pRepulsor != nullptr )
  {
    if ( !enable )
    {
      m_pRepulsor = this->m_pRepulsor;
      if ( m_pRepulsor != nullptr )
      {
        bfx::Repulsor3DImpl::~Repulsor3DImpl(this: this->m_pRepulsor);
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pRepulsor);
        this->m_pRepulsor = nullptr;
      }
    }
  }
  else
  {
    Scale = bfx::GetScale();
    m_pTune = this->m_pTune;
    v5 = (float)((float)Scale * (float)10.0);
    if ( (float)(m_pTune->m_repulsionPackage.m_sphereData.m_radius * (float)10.0) > v5 )
      v5 = (float)(m_pTune->m_repulsionPackage.m_sphereData.m_radius * (float)10.0);
    v6 = (bfx::Repulsor3DImpl *)bfx::MemoryManager::Malloc(
                                  this: bfx::g_pCurInstance->m_pMemoryManager,
                                  size: 0x5Cu,
                                  tag: bfx::MEM_BFXMOVER3D);
    if ( v6 != nullptr )
    {
      m_y = this->m_surfer.m_pos.m_y;
      m_z = this->m_surfer.m_pos.m_z;
      v9 = this->m_pTune;
      m_pSpace = this->m_pSpace;
      v13.m_x = this->m_surfer.m_pos.m_x;
      v13.m_y = m_y;
      v13.m_z = m_z;
      v11 = bfx::Repulsor3DImpl::Repulsor3DImpl(
              this: v6,
              pSpace: m_pSpace,
              pos: &v13,
              vel: &this->m_hoverData.m_vForwVel,
              rpack: &v9->m_repulsionPackage,
              detectRadius: v5,
              repulsorID: LODWORD(m_y),
              pMover: (bfx::Mover3D *)0xFFFFFFFF,
              a9: (bfx::Mover3D *)&this->m_pSpace);
    }
    else
    {
      v11 = nullptr;
    }
    this->m_pRepulsor = v11;
  }
}


// ========================================================================
// __unwind$84221
// EA  : 0x83267520
// RVA : 0x01267520
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void _unwind_84221()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 144 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?Stop@Mover3DImpl@bfx@@QAAXXZ
// EA  : 0x83267550
// RVA : 0x01267550
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __fastcall bfx::Mover3DImpl::Stop(bfx::Mover3DImpl *this)
{
  float m_x; // [sp+50h] [-20h]
  float m_y; // [sp+54h] [-1Ch]

  m_x = this->m_surfer.m_pos.m_x;
  m_y = this->m_surfer.m_pos.m_y;
  this->m_orbitCenterPos.m_z = this->m_surfer.m_pos.m_z;
  this->m_orbitCenterPos.m_y = m_y;
  this->m_orbitCenterPos.m_x = m_x;
  if ( this->m_gotoPosSpec.m_stopAtGoal )
  {
    if ( this->m_state != DECEL_TO_STOP )
      this->m_state = DECEL_TO_STOP;
  }
  else
  {
    bfx::Mover3DImpl::SwitchState(this, newState: IDLE);
  }
}


// ========================================================================
// ?CalcNextPathPos@Mover3DImpl@bfx@@ABA?AVVec3@2@XZ
// EA  : 0x832675D8
// RVA : 0x012675D8
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

bfx::Mover3DImpl *__fastcall bfx::Mover3DImpl::CalcNextPathPos(bfx::Mover3DImpl *this, bfx::Vec3 *result)
{
  __int64 v2; // r11
  int v3; // r7
  int v4; // r8
  _DWORD *v5; // r9
  float m_x; // r11
  bfx::Space *v7; // r9
  int v8; // r8
  bfx::Mover3DImpl_vtbl *v9; // r11
  bfx::Space *v10; // r10
  int v11; // r9

  v2 = *(_QWORD *)&result[20].m_y;
  v3 = *(_DWORD *)(HIDWORD(v2) + 12);
  if ( (int)v2 >= v3 )
  {
LABEL_5:
    m_x = result[20].m_x;
    v7 = *(bfx::Space **)(LODWORD(m_x) + 32);
    v8 = *(_DWORD *)(LODWORD(m_x) + 36);
    this->__vftable = *(bfx::Mover3DImpl_vtbl **)(LODWORD(m_x) + 28);
    this->m_pSpace = v7;
    *(_DWORD *)&this->m_stranded = v8;
  }
  else
  {
    v4 = *(_DWORD *)(HIDWORD(v2) + 8);
    HIDWORD(v2) = 36 * v2;
    while ( 1 )
    {
      v5 = (_DWORD *)(HIDWORD(v2) + v4);
      if ( *(_BYTE *)(HIDWORD(v2) + v4 + 32) != 0 )
        break;
      LODWORD(v2) = v2 + 1;
      HIDWORD(v2) += 36;
      if ( (int)v2 >= v3 )
        goto LABEL_5;
    }
    v9 = (bfx::Mover3DImpl_vtbl *)v5[1];
    v10 = (bfx::Space *)v5[2];
    v11 = v5[3];
    this->__vftable = v9;
    this->m_pSpace = v10;
    *(_DWORD *)&this->m_stranded = v11;
  }
  return this;
}


// ========================================================================
// ?TestForReachedPathPoint@Mover3DImpl@bfx@@ABA_NXZ
// EA  : 0x83267660
// RVA : 0x01267660
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

BOOL __fastcall bfx::Mover3DImpl::TestForReachedPathPoint(bfx::Mover3DImpl *this)
{
  bfx::Path3D *m_pPath; // r9
  signed int m_idx; // r11
  const bfx::Volume *VolumeTo; // r30
  BOOL result; // r3
  double v6; // fp12
  double m_prevDistanceToGoal; // fp0
  float v8; // [sp+60h] [-30h] BYREF
  float v9; // [sp+64h] [-2Ch]
  float v10; // [sp+68h] [-28h]

  m_pPath = this->m_curPathCC.m_pPath;
  m_idx = this->m_curPathCC.m_idx;
  if ( m_idx < m_pPath->m_portalPoints.m_size )
  {
    VolumeTo = bfx::Portal::GetVolumeTo(
                 this: (bfx::Portal *)m_pPath->m_portalPoints.m_data[m_idx].m_pPortal,
                 dir: m_pPath->m_portalPoints.m_data[m_idx].m_dir);
    return VolumeTo == bfx::Surfer3D::GetVolume(this: &this->m_surfer);
  }
  bfx::Mover3DImpl::CalcNextPathPos(this: (bfx::Mover3DImpl *)&v8, result: (bfx::Vec3 *)this);
  v6 = __fsqrts((float)((float)((float)(v8 - this->m_surfer.m_pos.m_x) * (float)(v8 - this->m_surfer.m_pos.m_x))
                      + (float)((float)((float)(v10 - this->m_surfer.m_pos.m_z) * (float)(v10 - this->m_surfer.m_pos.m_z))
                              + (float)((float)(v9 - this->m_surfer.m_pos.m_y) * (float)(v9 - this->m_surfer.m_pos.m_y)))));
  if ( v6 <= this->m_pTune->m_goalRadius )
    return true;
  if ( !this->m_finalApproach )
    return false;
  m_prevDistanceToGoal = this->m_hoverData.m_prevDistanceToGoal;
  if ( m_prevDistanceToGoal <= 0.0 )
    return false;
  result = true;
  if ( v6 <= m_prevDistanceToGoal )
    return false;
  return result;
}


// ========================================================================
// ?StartPathWalking@Mover3DImpl@bfx@@AAAXXZ
// EA  : 0x83267778
// RVA : 0x01267778
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __fastcall bfx::Mover3DImpl::StartPathWalking(bfx::Mover3DImpl *this)
{
  if ( this->m_state == IDLE )
  {
    this->m_hoverData.m_bFinalApproach = false;
    this->m_hoverData.m_prevDistanceToGoal = -1.0;
    this->m_hoverData.m_recentlyCrossedPaths = 0.0;
    this->m_hoverData.m_lingeringSteeringForce.m_x = 0.0;
    this->m_hoverData.m_lingeringSteeringForce.m_y = 0.0;
    this->m_hoverData.m_lingeringSteeringForce.m_z = 0.0;
    this->m_hoverData.m_idleStateData.m_circlingDir = 0.0;
    this->m_hoverData.m_idleStateData.m_bestFitRadius = 0.0;
    this->m_hoverData.m_idleStateData.m_maxRadius = 0.0;
    this->m_hoverData.m_idleStateData.m_center.m_x = 0.0;
    this->m_hoverData.m_idleStateData.m_center.m_y = 0.0;
    this->m_hoverData.m_idleStateData.m_center.m_z = 0.0;
    this->m_hoverData.m_idleStateData.m_vUp.m_x = 0.0;
    this->m_hoverData.m_idleStateData.m_vUp.m_y = 0.0;
    this->m_hoverData.m_idleStateData.m_vUp.m_z = 0.0;
  }
  if ( this->m_state != INITIAL_ROTATION )
    this->m_state = INITIAL_ROTATION;
}


// ========================================================================
// ?CalcSteeringAcc@Mover3DImpl@bfx@@QAA?AVVec3@2@PAVRepulsor3DImpl@2@MM@Z
// EA  : 0x832677F8
// RVA : 0x012677F8
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

bfx::Mover3DImpl *__fastcall bfx::Mover3DImpl::CalcSteeringAcc(
        bfx::Mover3DImpl *this,
        bfx::Vec3 *result,
        bfx::Repulsor3DImpl *pCurNeighbor,
        double steeringRadius,
        double mySpeed)
{
  float m_z; // r10
  float m_x; // r9
  float v9; // r7
  float m_y; // r6
  float v13; // r5
  float v14; // r4
  double v16; // fp12
  double v17; // fp11
  double v18; // fp10
  float v19; // r7
  float v20; // r6
  float v21; // r10
  float v22; // r9
  float *p_m_z; // r29
  float v24; // r8
  double v25; // fp4
  double v26; // fp25
  double v27; // fp29
  double v28; // fp26
  double v29; // fp24
  double v32; // fp1
  float v33; // r8
  float v34; // r7
  float v35; // r9
  float v36; // r10
  float v37; // r9
  float v38; // r8
  double v39; // fp0
  float v40; // r4
  double v41; // fp13
  float v42; // r3
  double v43; // fp11
  double v44; // fp12
  float v45; // r7
  double v46; // fp7
  float v47; // r6
  float v48; // r5
  char v49; // r25
  bool v50; // r24
  float v51; // r11
  float v52; // r8
  float v53; // r6
  float v54; // r5
  double v55; // fp13
  double v56; // fp6
  double v57; // fp12
  double v58; // fp11
  double v59; // fp1
  double v60; // fp10
  double v61; // fp13
  double v62; // fp12
  double v63; // fp9
  double v64; // fp11
  double v65; // fp8
  double v67; // fp25
  double v70; // fp22
  double v71; // fp21
  double v72; // fp1
  double v74; // fp7
  double v75; // fp5
  double v76; // fp6
  double v77; // fp4
  double v78; // fp3
  double v79; // fp2
  double v82; // fp7
  float v83; // r10
  double v84; // fp4
  double v85; // fp5
  float v86; // r9
  long double v91; // fp2
  double v94; // fp29
  long double v95; // fp2
  bfx::Vec3 *v96; // r3
  double v97; // fp4
  double v98; // fp3
  double v99; // fp2
  double v102; // fp30
  double v103; // fp29
  double v104; // fp28
  long double v105; // fp2
  bfx::Vec3 *UpVec; // r3
  double v107; // fp4
  double v108; // fp3
  double v109; // fp2
  double v112; // fp8
  double v113; // fp7
  double v114; // fp6
  float v117; // r11
  float v118; // r10
  float v119; // r9
  bool v120; // r11
  double v122; // fp9
  double v123; // fp7
  double v124; // fp6
  double v125; // fp5
  bfx::Mover3D *m_pMover; // r11
  double v127; // fp10
  double v128; // fp8
  double v129; // fp12
  double v130; // fp10
  double v131; // fp8
  bfx::SteeringCollisionType v132; // [sp+50h] [-160h] BYREF
  bfx::Vec3 v133; // [sp+58h] [-158h] BYREF
  bfx::Vec3 v134; // [sp+68h] [-148h] BYREF
  float v135; // [sp+78h] [-138h]
  float v136; // [sp+7Ch] [-134h]
  float v137; // [sp+80h] [-130h]
  float v138; // [sp+88h] [-128h]
  float v139; // [sp+8Ch] [-124h]
  float v140; // [sp+90h] [-120h]
  float v141; // [sp+98h] [-118h]
  float v142; // [sp+9Ch] [-114h]
  float v143; // [sp+A0h] [-110h]
  float v144; // [sp+A8h] [-108h]
  float v145; // [sp+ACh] [-104h]
  float v146; // [sp+B0h] [-100h]
  bfx::Vec3 v147; // [sp+B8h] [-F8h] BYREF
  bfx::Vec3 v148; // [sp+C8h] [-E8h] BYREF
  bfx::Vec3 v149; // [sp+D8h] [-D8h] BYREF
  bfx::Vec3 v150; // [sp+E8h] [-C8h] BYREF

  m_z = pCurNeighbor->m_pos.m_z;
  m_x = result[12].m_x;
  v9 = pCurNeighbor->m_pos.m_x;
  m_y = result[11].m_y;
  v13 = pCurNeighbor->m_pos.m_y;
  v14 = result[11].m_z;
  v134.m_z = m_z;
  v134.m_x = v9;
  v133.m_x = m_y;
  v134.m_y = v13;
  v133.m_y = v14;
  v133.m_z = m_x;
  *(float *)&this->__vftable = 0.0;
  *(float *)&this->m_pSpace = 0.0;
  *(float *)&this->m_stranded = 0.0;
  if ( __fsqrts((float)((float)((float)(m_y - v9) * (float)(m_y - v9))
                      + (float)((float)((float)(m_x - m_z) * (float)(m_x - m_z))
                              + (float)((float)(v14 - v13) * (float)(v14 - v13))))) >= 1.0842022e-19 )
  {
    v16 = result[27].m_x;
    v134.m_y = pCurNeighbor->m_vel.m_y;
    v17 = result[27].m_y;
    v134.m_z = pCurNeighbor->m_vel.m_z;
    v18 = result[26].m_z;
    v134.m_x = pCurNeighbor->m_vel.m_x;
    v19 = result[11].m_y;
    v20 = result[11].m_z;
    v21 = pCurNeighbor->m_pos.m_x;
    v22 = pCurNeighbor->m_pos.m_y;
    p_m_z = &result[26].m_z;
    v133.m_z = result[12].m_x;
    v133.m_x = v19;
    v24 = pCurNeighbor->m_pos.m_z;
    v148.m_x = v21;
    v148.m_y = v22;
    v149.m_x = v19;
    v148.m_z = v24;
    v149.m_y = v20;
    v149.m_z = v133.m_z;
    v25 = (float)((float)v17 - v134.m_z);
    v26 = (float)(v20 + (float)((float)((float)v16 - v134.m_y) * (float)2.0));
    v27 = (float)((float)((float)((float)v18 - v134.m_x) * (float)((float)v18 - v134.m_x))
                + (float)((float)((float)((float)v17 - v134.m_z) * (float)((float)v17 - v134.m_z))
                        + (float)((float)((float)v16 - v134.m_y) * (float)((float)v16 - v134.m_y))));
    v28 = (float)((float)((float)((float)v18 - v134.m_x) * (float)2.0) + v19);
    v29 = (float)(v133.m_z + (float)((float)((float)v17 - v134.m_z) * (float)2.0));
    _FP13 = (float)((float)__fsqrts(v27) - (float)1.0842022e-19);
    __asm { fsel      f11, f13, f12, f31 }
    v133.m_x = (float)_FP11 * (float)((float)v18 - v134.m_x);
    v133.m_y = (float)((float)v16 - v134.m_y) * (float)_FP11;
    v133.m_z = (float)v25 * (float)_FP11;
    v32 = bfx::CollideLineAndSphere(
            lineStart: &v149,
            normalizedLineDir: &v133,
            spherePos: &v148,
            radius: steeringRadius);
    v33 = result[12].m_x;
    v34 = result[11].m_z;
    v35 = result[11].m_y;
    v136 = v34;
    v137 = v33;
    v135 = v35;
    if ( v32 != 3.4028235e38
      && (float)((float)v32 * (float)v32) < (double)(float)((float)((float)((float)v28 - v35) * (float)((float)v28 - v35))
                                                          + (float)((float)((float)((float)v29 - v137)
                                                                          * (float)((float)v29 - v137))
                                                                  + (float)((float)((float)v26 - v34)
                                                                          * (float)((float)v26 - v34))))
      && v32 >= 0.0 )
    {
      v36 = pCurNeighbor->m_pos.m_y;
      v37 = v33;
      v38 = pCurNeighbor->m_pos.m_z;
      v139 = v34;
      v39 = result[27].m_y;
      v40 = result[11].m_y;
      v41 = (float)(result[27].m_y * result[27].m_y);
      v42 = pCurNeighbor->m_pos.m_x;
      v43 = __fsqrts(v27);
      v142 = v36;
      v44 = result[27].m_x;
      v45 = pCurNeighbor->m_vel.m_y;
      v46 = *p_m_z;
      v47 = pCurNeighbor->m_vel.m_x;
      v48 = pCurNeighbor->m_vel.m_z;
      v140 = v37;
      v49 = 0;
      v143 = v38;
      v50 = false;
      v136 = v45;
      v138 = v40;
      v141 = v42;
      v135 = v47;
      v137 = v48;
      v51 = result[11].m_z;
      v147.m_y = v36;
      v52 = result[12].m_x;
      v53 = pCurNeighbor->m_pos.m_z;
      v144 = v40;
      v145 = v51;
      v147.m_x = v42;
      v146 = v52;
      v147.m_z = v53;
      v55 = (float)((float)((float)v44 * (float)v44) + (float)v41);
      v56 = v44;
      v57 = (float)((float)v32 / (float)v43);
      v58 = (float)(v45 * (float)((float)v32 / (float)v43));
      v59 = __fsqrts((float)((float)((float)v46 * (float)v46) + (float)v55));
      v60 = (float)(v36 + (float)v58);
      v61 = (float)(v51 + (float)((float)v56 * (float)v57));
      v63 = (float)((float)(v135 * (float)v57) + v42);
      v65 = (float)(v53 + (float)(v48 * (float)v57));
      _FP29 = (float)((float)v59 - 1.0842022e-19);
      v67 = (float)((float)(v36 + (float)v58) - (float)(v51 + (float)((float)v56 * (float)v57)));
      v64 = (float)(v52 + (float)((float)v39 * (float)v57));
      __asm { fsel      f1, f29, f1, f31 }
      _FP26 = (float)((float)__fsqrts((float)((float)((float)(v42 - v40) * (float)(v42 - v40))
                                            + (float)((float)((float)(v143 - v37) * (float)(v143 - v37))
                                                    + (float)((float)(v36 - v139) * (float)(v36 - v139)))))
                    - 1.0842022e-19);
      v70 = (float)((float)_FP1 * (float)v56);
      v71 = (float)((float)_FP1 * (float)v39);
      v72 = (float)((float)_FP1 * (float)v46);
      v54 = result[8].m_z;
      v62 = (float)((float)((float)v46 * (float)v57) + v40);
      __asm { fsel      f7, f26, f29, f31 }
      v134.m_x = (float)(v42 - v40) * (float)_FP7;
      v134.m_y = (float)(v36 - v139) * (float)_FP7;
      v134.m_z = (float)(v143 - v37) * (float)_FP7;
      v74 = (float)((float)((float)v67
                          * (float)((float)((float)(*(float *)(LODWORD(v54) + 8) + *(float *)(LODWORD(v54) + 4))
                                          + *(float *)LODWORD(v54))
                                  / (float)steeringRadius))
                  + (float)v61);
      v75 = (float)((float)((float)((float)v65 - (float)v64)
                          * (float)((float)((float)(*(float *)(LODWORD(v54) + 8) + *(float *)(LODWORD(v54) + 4))
                                          + *(float *)LODWORD(v54))
                                  / (float)steeringRadius))
                  + (float)v64);
      v76 = (float)((float)((float)((float)v63 - (float)v62)
                          * (float)((float)((float)(*(float *)(LODWORD(v54) + 8) + *(float *)(LODWORD(v54) + 4))
                                          + *(float *)LODWORD(v54))
                                  / (float)steeringRadius))
                  + (float)v62);
      v77 = (float)((float)((float)((float)v67
                                  * (float)((float)((float)(*(float *)(LODWORD(v54) + 8) + *(float *)(LODWORD(v54) + 4))
                                                  + *(float *)LODWORD(v54))
                                          / (float)steeringRadius))
                          + (float)v61)
                  - (float)v61);
      v78 = (float)((float)((float)((float)((float)v65 - (float)v64)
                                  * (float)((float)((float)(*(float *)(LODWORD(v54) + 8) + *(float *)(LODWORD(v54) + 4))
                                                  + *(float *)LODWORD(v54))
                                          / (float)steeringRadius))
                          + (float)v64)
                  - (float)v64);
      v79 = (float)((float)((float)((float)((float)v63 - (float)v62)
                                  * (float)((float)((float)(*(float *)(LODWORD(v54) + 8) + *(float *)(LODWORD(v54) + 4))
                                                  + *(float *)LODWORD(v54))
                                          / (float)steeringRadius))
                          + (float)v62)
                  - (float)v62);
      _FP28 = (float)((float)__fsqrts((float)((float)((float)v79 * (float)v79)
                                            + (float)((float)((float)v78 * (float)v78) + (float)((float)v77 * (float)v77))))
                    - (float)1.0842022e-19);
      __asm { fsel      f29, f28, f29, f31 }
      if ( (float)((float)((float)((float)_FP29 * (float)v79) * (float)v72)
                 + (float)((float)((float)((float)v78 * (float)_FP29) * (float)v71)
                         + (float)((float)((float)v77 * (float)_FP29) * (float)v70))) >= 0.0 )
      {
        v82 = (float)((float)v74 - (float)v60);
        v83 = pCurNeighbor->m_vel.m_y;
        v84 = (float)((float)v76 - (float)v63);
        v85 = (float)((float)v75 - (float)v65);
        v86 = pCurNeighbor->m_vel.m_x;
        v147.m_z = pCurNeighbor->m_vel.m_z;
        v147.m_y = v83;
        v147.m_x = v86;
        _FP6 = (float)((float)__fsqrts((float)((float)((float)((float)v76 - (float)v63)
                                                     * (float)((float)v76 - (float)v63))
                                             + (float)((float)((float)v85 * (float)v85)
                                                     + (float)((float)v82 * (float)v82))))
                     - (float)1.0842022e-19);
        _FP1 = (float)((float)__fsqrts((float)((float)(v86 * v86)
                                             + (float)((float)(v83 * v83) + (float)(v147.m_z * v147.m_z))))
                     - (float)1.0842022e-19);
        __asm
        {
          fsel      f6, f6, f3, f31
          fsel      f3, f1, f2, f31
        }
        v50 = (float)((float)((float)((float)_FP6 * (float)v84) * (float)(v86 * (float)_FP3))
                    + (float)((float)((float)((float)v85 * (float)_FP6) * (float)(v147.m_z * (float)_FP3))
                            + (float)((float)((float)v82 * (float)_FP6) * (float)(v83 * (float)_FP3)))) < 0.0;
      }
      else
      {
        v49 = 1;
      }
      result[39].m_z = v61;
      result[39].m_y = v62;
      result[40].m_x = v64;
      *(_QWORD *)&v91 = 0x3FB6571855555556LL;
      *((double *)&v91 + 1) = __fsqrts((float)((float)(*p_m_z * *p_m_z)
                                             + (float)((float)(p_m_z[1] * p_m_z[1]) + (float)(p_m_z[2] * p_m_z[2]))));
      _FP0 = (float)((float)*((double *)&v91 + 1) - (float)1.0842022e-19);
      __asm { fsel      f8, f0, f13, f31 }
      v94 = (float)((float)((float)((float)_FP8 * result[27].m_x) * v133.m_y)
                  + (float)((float)((float)((float)_FP8 * result[26].m_z) * v133.m_x)
                          + (float)((float)((float)_FP8 * result[27].m_y) * v133.m_z)));
      v95 = cos(x: v91);
      *((double *)&v95 + 1) = (float)*(double *)&v95;
      if ( v94 < *((double *)&v95 + 1) )
      {
        *(_QWORD *)&v95 = 0x40086F429D555556LL;
        v105 = cos(x: v95);
        if ( v94 > (float)*(double *)&v105 )
        {
          v112 = (float)((float)((float)((float)(v133.m_z * p_m_z[1]) - (float)(v133.m_y * p_m_z[2])) * p_m_z[1])
                       - (float)((float)((float)(p_m_z[2] * v133.m_x) - (float)(v133.m_z * *p_m_z)) * *p_m_z));
          v113 = (float)((float)((float)((float)(p_m_z[2] * v133.m_x) - (float)(v133.m_z * *p_m_z)) * p_m_z[2])
                       - (float)((float)((float)(v133.m_y * *p_m_z) - (float)(p_m_z[1] * v133.m_x)) * p_m_z[1]));
          v114 = (float)((float)((float)((float)(v133.m_y * *p_m_z) - (float)(p_m_z[1] * v133.m_x)) * *p_m_z)
                       - (float)((float)((float)(v133.m_z * p_m_z[1]) - (float)(v133.m_y * p_m_z[2])) * p_m_z[2]));
          _FP0 = (float)((float)__fsqrts((float)((float)((float)v114 * (float)v114)
                                               + (float)((float)((float)v113 * (float)v113)
                                                       + (float)((float)v112 * (float)v112))))
                       - 1.0842022e-19);
          __asm { fsel      f13, f0, f1, f31 }
          v102 = (float)((float)_FP13
                       * (float)((float)((float)((float)(p_m_z[2] * v133.m_x) - (float)(v133.m_z * *p_m_z)) * p_m_z[2])
                               - (float)((float)((float)(v133.m_y * *p_m_z) - (float)(p_m_z[1] * v133.m_x)) * p_m_z[1])));
          v103 = (float)((float)((float)((float)((float)(v133.m_y * *p_m_z) - (float)(p_m_z[1] * v133.m_x)) * *p_m_z)
                               - (float)((float)((float)(v133.m_z * p_m_z[1]) - (float)(v133.m_y * p_m_z[2])) * p_m_z[2]))
                       * (float)_FP13);
          v104 = (float)((float)((float)((float)((float)(v133.m_z * p_m_z[1]) - (float)(v133.m_y * p_m_z[2])) * p_m_z[1])
                               - (float)((float)((float)(p_m_z[2] * v133.m_x) - (float)(v133.m_z * *p_m_z)) * *p_m_z))
                       * (float)_FP13);
        }
        else
        {
          UpVec = bfx::GetUpVec(result: &v147);
          v107 = (float)((float)(UpVec->m_x * v134.m_y) - (float)(UpVec->m_y * v134.m_x));
          v108 = (float)((float)(UpVec->m_y * v134.m_z) - (float)(UpVec->m_z * v134.m_y));
          v109 = (float)((float)(UpVec->m_z * v134.m_x) - (float)(UpVec->m_x * v134.m_z));
          _FP9 = (float)((float)__fsqrts((float)((float)((float)v109 * (float)v109)
                                               + (float)((float)((float)v108 * (float)v108)
                                                       + (float)((float)v107 * (float)v107))))
                       - 1.0842022e-19);
          __asm { fsel      f8, f9, f10, f31 }
          v102 = (float)((float)_FP8 * (float)((float)(UpVec->m_y * v134.m_z) - (float)(UpVec->m_z * v134.m_y)));
          v103 = (float)((float)((float)(UpVec->m_z * v134.m_x) - (float)(UpVec->m_x * v134.m_z)) * (float)_FP8);
          v104 = (float)((float)((float)(UpVec->m_x * v134.m_y) - (float)(UpVec->m_y * v134.m_x)) * (float)_FP8);
        }
      }
      else
      {
        v96 = bfx::GetUpVec(result: &v147);
        v97 = (float)((float)(v96->m_x * v134.m_y) - (float)(v96->m_y * v134.m_x));
        v98 = (float)((float)(v96->m_y * v134.m_z) - (float)(v96->m_z * v134.m_y));
        v99 = (float)((float)(v96->m_z * v134.m_x) - (float)(v96->m_x * v134.m_z));
        _FP9 = (float)((float)__fsqrts((float)((float)((float)v99 * (float)v99)
                                             + (float)((float)((float)v98 * (float)v98)
                                                     + (float)((float)v97 * (float)v97))))
                     - 1.0842022e-19);
        __asm { fsel      f8, f9, f10, f31 }
        v102 = (float)((float)_FP8 * (float)((float)(v96->m_y * v134.m_z) - (float)(v96->m_z * v134.m_y)));
        v103 = (float)((float)((float)(v96->m_z * v134.m_x) - (float)(v96->m_x * v134.m_z)) * (float)_FP8);
        v104 = (float)((float)((float)(v96->m_x * v134.m_y) - (float)(v96->m_y * v134.m_x)) * (float)_FP8);
      }
      v117 = pCurNeighbor->m_vel.m_x;
      v118 = pCurNeighbor->m_vel.m_y;
      v119 = pCurNeighbor->m_vel.m_z;
      v132.m_bHaveRightOfWay = false;
      v132.m_bIsFaster = false;
      v150.m_x = v117;
      v150.m_y = v118;
      v150.m_z = v119;
      v132.m_bHeadOn = false;
      v132.m_bOvertaking = false;
      v132.m_bCrossPaths = false;
      v132.m_bNeighborIsToRight = false;
      bfx::InterpretCrowdCollision(
        myVel: (bfx::Vec3 *)((char *)result + 320),
        neighborVel: &v150,
        colData: &v132,
        vToNeighbor: &v134,
        mySpeed);
      v120 = v49 != 0 || !v50 && v132.m_bHaveRightOfWay;
      v132.m_bHaveRightOfWay = v120;
      if ( v120 )
      {
        if ( v132.m_bCrossPaths )
          result[28].m_y = 0.0;
      }
      else
      {
        if ( v132.m_bOvertaking )
        {
          v122 = *(float *)&this->m_pSpace;
          v123 = *(float *)&this->m_stranded;
          v124 = (float)(result[27].m_x * (float)-0.2);
          v125 = (float)(result[27].m_y * (float)-0.2);
          *(float *)&this->__vftable = *(float *)&this->__vftable + (float)(*p_m_z * (float)-0.2);
          *(float *)&this->m_pSpace = (float)v124 + (float)v122;
          *(float *)&this->m_stranded = (float)v123 + (float)v125;
          return this;
        }
        if ( v132.m_bHeadOn || v132.m_bCrossPaths )
        {
          v129 = *(float *)&this->__vftable;
          v130 = *(float *)&this->m_pSpace;
          v131 = *(float *)&this->m_stranded;
          result[28].m_y = 1023969417;
          *(float *)&this->__vftable = (float)((float)v102 * 50.0) + (float)v129;
          *(float *)&this->m_pSpace = (float)((float)v103 * 50.0) + (float)v130;
          *(float *)&this->m_stranded = (float)((float)v104 * 50.0) + (float)v131;
          return this;
        }
        m_pMover = pCurNeighbor->m_pMover;
        if ( m_pMover == nullptr || SLODWORD(result[47].m_z) > *(_DWORD *)&m_pMover[568] )
        {
          v127 = *(float *)&this->m_pSpace;
          v128 = *(float *)&this->m_stranded;
          *(float *)&this->__vftable = (float)((float)v102 * 50.0) + *(float *)&this->__vftable;
          *(float *)&this->m_pSpace = (float)((float)v103 * 50.0) + (float)v127;
          *(float *)&this->m_stranded = (float)((float)v104 * 50.0) + (float)v128;
          return this;
        }
      }
    }
  }
  return this;
}


// ========================================================================
// ?CalcTargetAttractionAcc@Mover3DImpl@bfx@@QAA?AVVec3@2@MM@Z
// EA  : 0x83268050
// RVA : 0x01268050
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

bfx::Mover3DImpl *__fastcall bfx::Mover3DImpl::CalcTargetAttractionAcc(
        bfx::Mover3DImpl *this,
        bfx::Vec3 *result,
        double simTime,
        double curDesiredSpeed)
{
  float *v4; // r28
  double v8; // fp31
  double v9; // fp19
  double v10; // fp18
  double v11; // fp17
  double v12; // fp26
  double v13; // fp25
  bfx::Vec3 *v14; // r4
  float v15; // r9
  float m_x; // r11
  double v17; // fp22
  double v18; // fp21
  double v19; // fp20
  double v20; // fp27
  double v21; // fp28
  double v22; // fp29
  float *p_m_z; // r30
  double v24; // fp5
  double v25; // fp0
  double v26; // fp0
  long double v36; // fp2
  double v37; // fp5
  float v38; // r11
  double v39; // fp11
  double v40; // fp10
  double v41; // fp9
  double v42; // fp29
  double v43; // fp4
  double v44; // fp28
  double v45; // fp6
  double v46; // fp7
  double v47; // fp3
  double v48; // fp2
  double v51; // fp12
  double v52; // fp8
  double v53; // fp7
  double v54; // fp0
  double v55; // fp2
  float v56; // r10
  float v57; // r8
  double v58; // fp27
  double v59; // fp26
  double v60; // fp3
  double v61; // fp2
  double v62; // fp22
  double v64; // fp23
  double v72; // fp13
  double v74; // fp3
  float v78; // r6
  float v79; // r7
  float v80; // r8
  double v81; // fp3
  float m_y; // r8
  float m_z; // r7
  bfx::Vec3 v85; // [sp+50h] [-D0h] BYREF
  float v86; // [sp+60h] [-C0h] BYREF
  float v87; // [sp+64h] [-BCh]
  float v88; // [sp+68h] [-B8h]
  float v89; // [sp+70h] [-B0h] BYREF
  float v90; // [sp+74h] [-ACh]
  float v91; // [sp+78h] [-A8h]

  v4 = (float *)this;
  v8 = 0.0;
  if ( *(float *)(LODWORD(result[8].m_z) + 48) == 0.0 || simTime == 0.0 )
  {
    m_y = bfx::ZERO_VEC.m_y;
    m_z = bfx::ZERO_VEC.m_z;
    this->__vftable = (bfx::Mover3DImpl_vtbl *)LODWORD(bfx::ZERO_VEC.m_x);
    *(float *)&this->m_pSpace = m_y;
    *(float *)&this->m_stranded = m_z;
  }
  else
  {
    v9 = 0.0;
    v10 = 0.0;
    v11 = 0.0;
    v12 = 0.0;
    v13 = 0.0;
    bfx::Mover3DImpl::CalcNextPathPos(this: (bfx::Mover3DImpl *)&v86, result);
    v15 = v14[11].m_z;
    m_x = v14[12].m_x;
    v85.m_x = v14[11].m_y;
    v17 = v86;
    v18 = v87;
    v19 = v88;
    v20 = (float)(v88 - m_x);
    v85.m_z = v88 - m_x;
    v21 = (float)(v87 - v15);
    v85.m_y = v87 - v15;
    v22 = (float)(v86 - v85.m_x);
    v85.m_x = v86 - v85.m_x;
    bfx::Mover3DImpl::ChooseDefaultForward(this: (bfx::Mover3DImpl *)&v89, result: v14, vecToCorner: &v85);
    p_m_z = &result[25].m_z;
    v24 = __fsqrts((float)((float)(result[26].m_y * result[26].m_y)
                         + (float)((float)(result[25].m_z * result[25].m_z) + (float)(result[26].m_x * result[26].m_x))));
    if ( *(float *)(LODWORD(result[8].m_z) + 52) == 0.0 )
      v25 = 0.0;
    else
      v25 = (float)((float)curDesiredSpeed / *(float *)(LODWORD(result[8].m_z) + 52));
    v26 = (float)((float)v25 * (float)simTime);
    _FP8 = (float)((float)v26 - (float)((float)curDesiredSpeed - (float)v24));
    _FP7 = (float)((float)-v26 - (float)((float)curDesiredSpeed - (float)v24));
    __asm { fsel      f6, f7, f12, f13 }
    __asm { fsel      f0, f8, f5, f0 }
    if ( _FP0 > 0.0 )
    {
      v9 = (float)(v89 * (float)_FP0);
      v10 = (float)(v90 * (float)_FP0);
      v11 = (float)(v91 * (float)_FP0);
    }
    _FP4 = (float)((float)__fsqrts((float)((float)((float)v21 * (float)v21)
                                         + (float)((float)((float)v22 * (float)v22) + (float)((float)v20 * (float)v20))))
                 - (float)1.0842022e-19);
    __asm { fsel      f2, f4, f3, f31 }
    _FP4 = (float)((float)-1.0
                 - (float)((float)((float)((float)v20 * (float)_FP2) * v91)
                         + (float)((float)((float)((float)_FP2 * (float)v22) * v89)
                                 + (float)((float)((float)v21 * (float)_FP2) * v90))));
    _FP3 = (float)((float)1.0
                 - (float)((float)((float)((float)v20 * (float)_FP2) * v91)
                         + (float)((float)((float)((float)_FP2 * (float)v22) * v89)
                                 + (float)((float)((float)v21 * (float)_FP2) * v90))));
    __asm { fsel      f2, f4, f12, f5# x }
    __asm { fsel      f1, f3, f1, f30# x }
    v36 = acos(x: _FP2);
    v37 = (float)((float)*(double *)&v36 * (float)57.295776);
    if ( v37 > 2.0 )
    {
      v38 = result[8].m_z;
      v39 = (float)((float)(result[26].m_y * (float)v22) - (float)((float)v20 * result[25].m_z));
      v40 = (float)((float)((float)v21 * result[25].m_z) - (float)(result[26].m_x * (float)v22));
      v41 = (float)((float)((float)v20 * result[26].m_x) - (float)((float)v21 * result[26].m_y));
      v43 = (float)((float)(*(float *)(LODWORD(v38) + 48) * (float)0.25) * (float)((float)1.0 / (float)simTime));
      v45 = (float)((float)((float)(*(float *)(LODWORD(v38) + 48) / *(float *)(LODWORD(v38) + 56))
                          * *(float *)(LODWORD(v38) + 48))
                  * (float)simTime);
      v46 = (float)((float)(p_m_z[1] * (float)((float)((float)v20 * p_m_z[1]) - (float)((float)v21 * p_m_z[2])))
                  - (float)((float)((float)(p_m_z[2] * (float)v22) - (float)((float)v20 * *p_m_z)) * *p_m_z));
      v42 = (float)((float)((float)((float)v21 * result[25].m_z) - (float)(result[26].m_x * (float)v22)) * result[26].m_x);
      v44 = (float)(result[26].m_y * (float)((float)((float)v20 * result[26].m_x) - (float)((float)v21 * result[26].m_y)));
      v47 = (float)((float)((float)v39 * result[26].m_y) - (float)v42);
      v48 = (float)((float)((float)v40 * *p_m_z) - (float)v44);
      _FP1 = (float)((float)__fsqrts((float)((float)((float)v48 * (float)v48)
                                           + (float)((float)((float)v47 * (float)v47) + (float)((float)v46 * (float)v46))))
                   - 1.0842022e-19);
      __asm { fsel      f1, f1, f12, f31 }
      v51 = (float)((float)((float)((float)v39 * result[26].m_y) - (float)v42) * (float)_FP1);
      v52 = (float)((float)((float)((float)v40 * *p_m_z) - (float)v44) * (float)_FP1);
      v53 = (float)((float)v46 * (float)_FP1);
      if ( (float)((float)((float)1.0 / (float)simTime)
                 * (float)((float)((float)(*(float *)(LODWORD(v38) + 48) / *(float *)(LODWORD(v38) + 56))
                                 * *(float *)(LODWORD(v38) + 48))
                         * (float)simTime)) == 0.0 )
      {
        v54 = 3.4028235e38;
      }
      else
      {
        v55 = __fsqrts((float)((float)(result[26].m_y * result[26].m_y)
                             + (float)((float)(*p_m_z * *p_m_z) + (float)(result[26].m_x * result[26].m_x))));
        v54 = (float)((float)((float)v55
                            / (float)((float)((float)1.0 / (float)simTime)
                                    * (float)((float)((float)(*(float *)(LODWORD(v38) + 48)
                                                            / *(float *)(LODWORD(v38) + 56))
                                                    * *(float *)(LODWORD(v38) + 48))
                                            * (float)simTime)))
                    * (float)v55);
      }
      v56 = result[11].m_z;
      v57 = result[12].m_x;
      v85.m_x = result[11].m_y;
      v85.m_y = v56;
      v85.m_z = v57;
      v58 = (float)((float)((float)v53 * (float)v54) + v57);
      v59 = (float)((float)((float)v51 * (float)v54) + v85.m_x);
      v60 = (float)((float)v19 - (float)((float)((float)v53 * (float)v54) + v57));
      v61 = (float)((float)v17 - (float)((float)((float)v51 * (float)v54) + v85.m_x));
      v62 = (float)((float)v18 - (float)((float)((float)v52 * (float)v54) + v56));
      if ( (float)((float)((float)v62 * (float)v62)
                 + (float)((float)((float)v61 * (float)v61) + (float)((float)v60 * (float)v60))) < (double)(float)((float)v54 * (float)v54) )
        HIBYTE(result[30].m_z) = 1;
      _FP22 = (float)((float)2.0 - (float)v37);
      v64 = (float)((float)v43 * (float)simTime);
      _FP21 = (float)((float)45.0 - (float)v37);
      __asm { fsel      f5, f22, f4, f5 }
      __asm { fsel      f13, f21, f5, f13 }
      _FP5 = (float)((float)1.0 - (float)((float)((float)_FP13 - (float)2.0) * (float)0.023255814));
      _FP13 = -(float)((float)((float)_FP13 - (float)2.0) * (float)0.023255814);
      __asm { fsel      f3, f13, f2, f3 }
      __asm { fsel      f13, f5, f2, f30 }
      v72 = (float)((float)_FP13 * (float)v45);
      _FP6 = (float)((float)-v64 - (float)v72);
      v74 = v72;
      _FP5 = (float)((float)v64 - (float)v72);
      __asm { fsel      f2, f6, f4, f13 }
      __asm { fsel      f13, f5, f13, f23 }
      if ( _FP13 < v74 )
        HIBYTE(result[30].m_z) = 1;
      if ( HIBYTE(result[30].m_z) != 0 )
      {
        v9 = 0.0;
        v10 = 0.0;
        v11 = 0.0;
      }
      v78 = result[11].m_z;
      v79 = result[11].m_y;
      v80 = result[12].m_x;
      result[43].m_z = v54;
      v85.m_y = v78;
      v85.m_x = v79;
      v85.m_z = v80;
      result[43].m_y = (float)((float)v53 * (float)v54) + v80;
      v81 = (float)((float)((float)v51 * (float)v54) + v85.m_x);
      result[43].m_x = (float)((float)v52 * (float)v54) + v78;
      result[42].m_z = v81;
      result[44].m_x = v41;
      result[44].m_y = v39;
      result[44].m_z = v40;
      result[45].m_x = 0.0;
      result[45].m_y = 0.0;
      result[45].m_z = 0.0;
      result[46].m_x = 0.0;
      result[46].m_y = 0.0;
      result[46].m_z = 0.0;
      result[47].m_x = 0.0;
      result[40].m_y = v59;
      result[40].m_z = (float)((float)v52 * (float)v54) + v56;
      result[41].m_x = v58;
      result[41].m_y = v51;
      result[41].m_z = v52;
      result[42].m_x = v53;
      if ( HIBYTE(result[42].m_y) != 1 )
        HIBYTE(result[42].m_y) = 1;
      v8 = (float)((float)v51 * (float)_FP13);
      v12 = (float)((float)v52 * (float)_FP13);
      v13 = (float)((float)v53 * (float)_FP13);
    }
    *v4 = (float)v8 + (float)v9;
    v4[1] = (float)v12 + (float)v10;
    v4[2] = (float)v13 + (float)v11;
    return (bfx::Mover3DImpl *)v4;
  }
  return this;
}


// ========================================================================
// ?SearchOrbitList@Mover3DImpl@bfx@@QAAMAAV?$Array@M@2@HH@Z
// EA  : 0x832684E8
// RVA : 0x012684E8
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

float __fastcall bfx::Mover3DImpl::SearchOrbitList(
        bfx::Mover3DImpl *this,
        bfx::Array<float> *orbitList,
        int startIndex,
        int direction)
{
  double v4; // fp31
  int v5; // r31
  int v6; // r8
  __int64 v7; // r10
  int v8; // r11
  int i; // r7
  double v10; // fp0
  float *m_data; // r5
  float m_x; // r11
  float m_y; // r9
  float m_z; // r7
  float v15; // r6
  float v16; // r5
  float v17; // r4
  bfx::Planner3D *Planner3D; // r3
  const bfx::Path3DSpec *v19; // r6
  double v20; // fp1
  __int64 v22; // [sp+50h] [-70h] BYREF
  bfx::Vec3 v23; // [sp+58h] [-68h] BYREF
  bfx::Vec3 v24; // [sp+68h] [-58h] BYREF
  bfx::RayCast3DResults v25; // [sp+80h] [-40h] BYREF

  v4 = 0.0;
  if ( direction <= 0 )
    v5 = 0;
  else
    v5 = orbitList->m_size - 1;
  v6 = startIndex;
  HIDWORD(v7) = 4 * (startIndex + direction);
  v8 = 4 * startIndex;
  for ( i = 4 * direction; ; HIDWORD(v7) += i )
  {
    v10 = (float)(this->m_pTune->m_idleTune.m_orbitHeight * (float)0.5);
    if ( v6 == v5 )
    {
      LODWORD(v7) = direction;
      m_data = orbitList->m_data;
      v22 = v7;
      v4 = (float)((float)((float)((float)v10 + (float)v10) * (float)v7) + *(float *)((char *)m_data + v8));
    }
    else if ( __fabs((float)(*(float *)((char *)orbitList->m_data + HIDWORD(v7))
                           - *(float *)((char *)orbitList->m_data + v8))) > (float)((float)(this->m_pTune->m_idleTune.m_orbitHeight
                                                                                          + (float)v10)
                                                                                  + (float)v10) )
    {
      v4 = (float)((float)((float)(*(float *)((char *)orbitList->m_data + HIDWORD(v7))
                                 - *(float *)((char *)orbitList->m_data + v8))
                         * (float)0.5)
                 + *(float *)((char *)orbitList->m_data + v8));
    }
    if ( v4 != 0.0 )
      break;
    v6 += direction;
    v8 += i;
  }
  m_x = this->m_hoverData.m_idleStateData.m_center.m_x;
  m_y = this->m_hoverData.m_idleStateData.m_center.m_y;
  m_z = this->m_hoverData.m_idleStateData.m_center.m_z;
  v15 = this->m_hoverData.m_idleStateData.m_vUp.m_x;
  v16 = this->m_hoverData.m_idleStateData.m_vUp.m_y;
  v17 = this->m_hoverData.m_idleStateData.m_vUp.m_z;
  v25.m_collided = false;
  HIDWORD(v22) = -1;
  v23.m_x = m_x;
  v23.m_y = m_y;
  v23.m_z = m_z;
  v24.m_x = v15;
  v24.m_y = v16;
  v24.m_z = v17;
  Planner3D = bfx::GetPlanner3D(pSpace: this->m_pSpace);
  bfx::Planner3D::Probe(
    this: Planner3D,
    startPos: &v23,
    dir: &v24,
    dist: v4,
    pathSpec: v19,
    results: (const bfx::Path3DSpec *)&v22,
    a7: &v25);
  if ( v25.m_collided )
    v20 = 0.0;
  else
    v20 = v4;
  return *((float *)&v20 + 1);
}


// ========================================================================
// ?DrawPieWedge@bfx@@YAXPAVSpace@1@ABVMatrix@1@MABVColor@1@MM@Z
// EA  : 0x83268660
// RVA : 0x01268660
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __fastcall bfx::DrawPieWedge(
        bfx::Space *pSpace,
        bfx::Vec3 *mat,
        double radius,
        const bfx::Color *color,
        double radiansStart,
        double radiansEnd,
        const bfx::Color *a7)
{
  __int64 v12; // r10
  long double v13; // fp2
  int v14; // r28
  double v15; // fp28
  double v16; // fp27
  long double v17; // fp2
  double v18; // fp26
  long double v19; // fp2
  bfx::Vec3 *v20; // r4
  double m_x; // fp0
  double m_y; // fp12
  double m_z; // fp10
  double v24; // fp11
  double v25; // fp10
  double v26; // fp9
  bfx::Matrix v27; // [sp+58h] [-F8h] BYREF
  float v28[8]; // [sp+A0h] [-B0h] BYREF
  float v29[8]; // [sp+C0h] [-90h] BYREF
  bfx::Vec3 v30; // [sp+E0h] [-70h] BYREF
  float v31; // [sp+ECh] [-64h]
  float v32; // [sp+F0h] [-60h]
  float v33; // [sp+F4h] [-5Ch]

  v27.m_data[8] = radius;
  v27.m_data[9] = 0.0;
  v27.m_data[10] = 0.0;
  v14 = 0;
  v15 = (float)((float)radiansEnd - (float)radiansStart);
  bfx::Matrix::operator*(this: (bfx::Matrix *)&v27.m_data[4], result: mat, rhs: (const bfx::Vec3 *)&v27.m_data[8]);
  do
  {
    LODWORD(v12) = (unsigned int)v14 >> 3;
    v16 = (float)((float)((float)v12 * (float)v15) + (float)radiansStart);
    *(double *)&v13 = v16;
    v17 = sin(x: v13);
    v18 = (float)*(double *)&v17;
    *(double *)&v17 = v16;
    v19 = cos(x: v17);
    v27.m_data[14] = 0.0;
    v27.m_data[13] = (float)v18 * (float)radius;
    v27.m_data[12] = (float)*(double *)&v19 * (float)radius;
    bfx::Matrix::operator*(this: &v27, result: mat, rhs: (const bfx::Vec3 *)&v27.m_data[12]);
    if ( v14 != 0 )
    {
      v20 = (bfx::Vec3 *)v28;
      v28[0] = v27.m_data[4];
      v28[1] = v27.m_data[5];
      v28[2] = v27.m_data[6];
      v28[3] = v27.m_data[0];
      v28[4] = v27.m_data[1];
      v28[5] = v27.m_data[2];
    }
    else
    {
      m_x = mat[4].m_x;
      v20 = (bfx::Vec3 *)v29;
      m_y = mat[4].m_y;
      m_z = mat[4].m_z;
      v29[3] = v27.m_data[0];
      v29[4] = v27.m_data[1];
      v29[5] = v27.m_data[2];
      v29[0] = m_x;
      v29[1] = m_y;
      v29[2] = m_z;
    }
    bfx::DrawLineList(pSpace, pVerts: v20, numVerts: 2, color: a7);
    ++v14;
    v27.m_data[4] = v27.m_data[0];
    v27.m_data[5] = v27.m_data[1];
    v27.m_data[6] = v27.m_data[2];
  }
  while ( v14 <= 8 );
  v24 = mat[4].m_x;
  v25 = mat[4].m_y;
  v26 = mat[4].m_z;
  v31 = v27.m_data[0];
  v32 = v27.m_data[1];
  v33 = v27.m_data[2];
  v30.m_x = v24;
  v30.m_y = v25;
  v30.m_z = v26;
  bfx::DrawLineList(pSpace, pVerts: &v30, numVerts: 2, color: a7);
}


// ========================================================================
// ?Draw@Mover3DImpl@bfx@@UBAXXZ
// EA  : 0x832687F8
// RVA : 0x012687F8
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall bfx::Mover3DImpl::Draw(bfx::Mover3DImpl *this)
{
  bfx::Color *p_m_debugColor; // r11
  float m_g; // r6
  float m_b; // r5
  float m_a; // r3
  bfx::InstanceComponent_vtbl *v6; // r28
  float m_y; // r10
  float m_z; // r9
  double m_radius; // fp30
  const bfx::Color *v10; // r5
  long double v11; // fp2
  long double v12; // fp2
  double v13; // fp28
  long double v14; // fp2
  double v15; // fp28
  bfx::Vec3 *v16; // r30
  int v17; // r29
  double v18; // fp27
  bfx::Space *m_pSpace; // r3
  bfx::Space *v20; // r3
  bfx::Space *v21; // r3
  long double v22; // fp2
  long double v23; // fp2
  double v24; // fp26
  long double v25; // fp2
  bfx::Vec3 *v26; // r30
  int v27; // r29
  bfx::Space *v28; // r3
  bfx::Space *v29; // r3
  const bfx::Color *m_pRepulsor; // r11
  float v31; // r9
  float v32; // r10
  bfx::Mover3DImpl::State m_state; // r11
  bfx::Path3D *m_pPath; // r11
  float v35; // r8
  float v36; // r7
  float m_x; // r9
  float v38; // r10
  double v39; // fp29
  float v40; // r11
  double v41; // fp30
  double v42; // fp28
  bfx::Space *v43; // r3
  double Scale; // fp1
  const bfx::Color *v45; // r5
  double v46; // fp1
  const bfx::Color *v47; // r5
  double v48; // fp11
  double v49; // fp10
  double v50; // fp9
  bfx::Space *v51; // r3
  bfx::Path3D *v52; // r11
  float v53; // r10
  float v54; // r9
  bfx::Space *v55; // r4
  bfx::Path3D *v56; // r11
  float v57; // r9
  float v58; // r10
  bfx::Space *v59; // r3
  double v60; // fp1
  const bfx::Color *v61; // r5
  float v62; // r11
  float v63; // r10
  double v64; // fp13
  float v65; // r9
  double v66; // fp12
  double v67; // fp11
  const bfx::Color *v68; // r5
  bfx::Mover3DImpl::State v69; // r11
  __int64 v70; // r8 OVERLAPPED
  double v71; // fp13
  double v72; // fp12
  double v73; // fp11
  float v74; // r9
  __int64 v75; // r10
  __int64 v76; // r6
  bfx::Mover3DImpl::HoverData *p_m_hoverData; // r29
  char v78; // r11
  float v79; // r8
  double v80; // fp10
  float v81; // r10
  double v82; // fp9
  double v83; // fp6
  bfx::Space *v84; // r3
  char v85; // r11
  float v86; // r9
  float v87; // r10
  double v88; // fp10
  double v89; // fp9
  double v90; // fp7
  bfx::Space *v91; // r3
  char v92; // r11
  float v93; // r10
  float v94; // r11
  double v95; // fp10
  double v96; // fp9
  double v97; // fp7
  bfx::Space *v98; // r3
  char v99; // r11
  float v100; // r11
  float v101; // r9
  double v102; // fp10
  double v103; // fp9
  double v104; // fp8
  bfx::Space *v105; // r3
  float v106; // r10
  float v107; // r9
  char v108; // r11
  float v109; // r9
  float v110; // r7
  float v111; // r3
  float v112; // r30
  float v113; // r11
  bfx::Space *v114; // r3
  char v117; // r11
  const bfx::Mover3DTune *m_pTune; // r11
  float v119; // r10
  float v120; // r9
  float v121; // r8
  bfx::Space *v122; // r3
  char v123; // r11
  const bfx::Mover3DTune *v124; // r11
  float v125; // r8
  float v126; // r7
  bfx::Space *v127; // r3
  double v128; // fp12
  double v129; // fp11
  int v130; // [sp+8h] [-4D8h]
  int v131; // [sp+Ch] [-4D4h]
  int v132; // [sp+10h] [-4D0h]
  int v133; // [sp+14h] [-4CCh]
  int v134; // [sp+18h] [-4C8h]
  int v135; // [sp+1Ch] [-4C4h]
  int v136; // [sp+20h] [-4C0h]
  int v137; // [sp+24h] [-4BCh]
  bfx::Vec3 v138; // [sp+50h] [-490h] BYREF
  float v139; // [sp+60h] [-480h]
  float v140; // [sp+64h] [-47Ch]
  float v141; // [sp+68h] [-478h]
  bfx::Matrix v142; // [sp+70h] [-470h] BYREF
  float v143; // [sp+B0h] [-430h] BYREF
  float v144; // [sp+B4h] [-42Ch]
  float v145; // [sp+B8h] [-428h]
  float v146; // [sp+BCh] [-424h]
  float v147; // [sp+C0h] [-420h]
  float v148; // [sp+C4h] [-41Ch]
  float v149; // [sp+C8h] [-418h]
  float v150; // [sp+CCh] [-414h]
  float v151; // [sp+D0h] [-410h]
  bfx::Mover3DImpl v152; // [sp+D8h] [-408h] BYREF
  bfx::Vec3 v153; // [sp+320h] [-1C0h] BYREF
  bfx::Mover3DImpl_vtbl *v154; // [sp+32Ch] [-1B4h]
  bfx::Space *v155; // [sp+330h] [-1B0h]
  float v156; // [sp+334h] [-1ACh]
  bfx::Vec3 v157; // [sp+340h] [-1A0h] BYREF
  float v158; // [sp+34Ch] [-194h]
  float v159; // [sp+350h] [-190h]
  float v160; // [sp+354h] [-18Ch]
  bfx::Matrix v161; // [sp+360h] [-180h] BYREF
  bfx::Matrix v162; // [sp+3A0h] [-140h] BYREF
  bfx::Matrix v163; // [sp+3E0h] [-100h] BYREF
  bfx::Matrix v164; // [sp+420h] [-C0h] BYREF

  p_m_debugColor = &ColorRed_7;
  if ( !this->m_stranded )
    p_m_debugColor = &this->m_debugColor;
  m_g = p_m_debugColor->m_g;
  m_b = p_m_debugColor->m_b;
  m_a = p_m_debugColor->m_a;
  v152.m_tune.m_repulsionPackage.m_sphereForces.m_initialAcc = p_m_debugColor->m_r;
  v152.m_tune.m_repulsionPackage.m_sphereForces.m_outerCushionAcc = m_g;
  v152.m_tune.m_repulsionPackage.m_sphereForces.m_innerCushionAcc = m_b;
  v152.m_tune.m_repulsionPackage.m_bulk = m_a;
  v6 = bfx::g_pCurInstance->m_pComponentManager->m_components[5][3].__vftable;
  if ( HIBYTE(v6->dtr_InstanceComponent) != 0 )
  {
    m_y = this->m_surfer.m_pos.m_y;
    m_z = this->m_surfer.m_pos.m_z;
    v152.m_surfer.m_pos.m_x = this->m_surfer.m_pos.m_x;
    v152.m_surfer.m_pos.m_y = m_y;
    v152.m_surfer.m_pos.m_z = m_z;
    bfx::Matrix::Build(this: &v163, q: &this->m_rot, pos: &v152.m_surfer.m_pos);
    m_radius = this->m_pTune->m_repulsionPackage.m_sphereData.m_radius;
    bfx::DrawSphere(
      pSpace: this->m_pSpace,
      mat: (bfx::Vec3 *)&v163,
      radius: m_radius,
      color: v10,
      a5: (const bfx::Color *)&v152.m_tune.m_repulsionPackage.m_sphereForces);
    *(double *)&v11 = 0.3926990926265717;
    v12 = sin(x: v11);
    v13 = (float)((float)m_radius / (float)*(double *)&v12);
    *(double *)&v12 = 0.3926990926265717;
    v14 = tan(x: v12);
    v142.m_data[4] = v13;
    v142.m_data[5] = 0.0;
    v142.m_data[6] = 0.0;
    v142.m_data[9] = 0.0;
    v16 = (bfx::Vec3 *)&v142.m_data[4];
    v142.m_data[12] = 0.0;
    v17 = 3;
    v142.m_data[7] = -m_radius;
    v142.m_data[10] = v142.m_data[7];
    v18 = (float)((float)*(double *)&v14 * (float)((float)v13 + (float)m_radius));
    v142.m_data[8] = (float)*(double *)&v14 * (float)((float)v13 + (float)m_radius);
    v15 = -m_radius;
    v142.m_data[11] = -v18;
    do
    {
      *v16 = *bfx::Matrix::operator*(this: &v142, result: (bfx::Vec3 *)&v163, rhs: v16);
      --v17;
      ++v16;
    }
    while ( v17 != 0 );
    m_pSpace = this->m_pSpace;
    v152.m_orienter.m_angDiff = v142.m_data[4];
    *(float *)&v152.m_pRepulsor = v142.m_data[5];
    *(float *)&v152.m_pPath = v142.m_data[6];
    *(float *)&v152.m_curPathCC.m_pPath = v142.m_data[7];
    *(float *)&v152.m_curPathCC.m_idx = v142.m_data[8];
    v152.m_refinementCountdownTimer = v142.m_data[9];
    bfx::DrawLineList(
      pSpace: m_pSpace,
      pVerts: (bfx::Vec3 *)&v152.m_orienter.m_angDiff,
      numVerts: 2,
      color: (const bfx::Color *)&v152.m_tune.m_repulsionPackage.m_sphereForces);
    v20 = this->m_pSpace;
    v152.m_hoverData.m_debug.m_vSteering.m_x = v142.m_data[7];
    v152.m_hoverData.m_debug.m_vSteering.m_y = v142.m_data[8];
    v152.m_hoverData.m_debug.m_vSteering.m_z = v142.m_data[9];
    v152.m_hoverData.m_debug.m_vTargetAttraction.m_x = v142.m_data[10];
    v152.m_hoverData.m_debug.m_vTargetAttraction.m_y = v142.m_data[11];
    v152.m_hoverData.m_debug.m_vTargetAttraction.m_z = v142.m_data[12];
    bfx::DrawLineList(pSpace: v20, pVerts: &v152.m_hoverData.m_debug.m_vSteering, numVerts: 2, color: &ColorBlue_7);
    v21 = this->m_pSpace;
    v152.m_hoverData.m_debug.m_vCirclingCenter.m_y = v142.m_data[10];
    v152.m_hoverData.m_debug.m_vCirclingCenter.m_z = v142.m_data[11];
    v152.m_hoverData.m_debug.m_vCirclingTangential.m_x = v142.m_data[12];
    v152.m_hoverData.m_debug.m_vCirclingTangential.m_y = v142.m_data[4];
    v152.m_hoverData.m_debug.m_vCirclingTangential.m_z = v142.m_data[5];
    *(float *)&v152.m_hoverData.m_debug.m_enable = v142.m_data[6];
    bfx::DrawLineList(
      pSpace: v21,
      pVerts: (bfx::Vec3 *)&v152.m_hoverData.m_debug.m_vCirclingCenter.m_y,
      numVerts: 2,
      color: (const bfx::Color *)&v152.m_tune.m_repulsionPackage.m_sphereForces);
    *(double *)&v22 = 0.3926990926265717;
    v23 = cos(x: v22);
    v24 = (float)*(double *)&v23;
    *(double *)&v23 = 0.3926990926265717;
    v25 = sin(x: v23);
    v144 = 0.0;
    v145 = (float)v24 * (float)m_radius;
    v146 = v15;
    v26 = (bfx::Vec3 *)&v143;
    v147 = 0.0;
    v27 = 3;
    v148 = v18;
    v149 = v15;
    v150 = 0.0;
    v151 = 0.0;
    v143 = (float)*(double *)&v25 * (float)m_radius;
    do
    {
      *v26 = *bfx::Matrix::operator*(this: &v142, result: (bfx::Vec3 *)&v163, rhs: v26);
      --v27;
      ++v26;
    }
    while ( v27 != 0 );
    v28 = this->m_pSpace;
    v152.m_hoverData.m_debug.m_myOrbit.m_center.m_z = v143;
    v152.m_hoverData.m_debug.m_myOrbit.m_radius = v144;
    v152.m_hoverData.m_debug.m_myOrbit.m_rotationAxis.m_x = v145;
    v152.m_hoverData.m_debug.m_myOrbit.m_rotationAxis.m_y = v146;
    v152.m_hoverData.m_debug.m_myOrbit.m_rotationAxis.m_z = v147;
    v152.m_hoverData.m_debug.m_desiredOrbit.m_center.m_x = v148;
    bfx::DrawLineList(
      pSpace: v28,
      pVerts: (bfx::Vec3 *)&v152.m_hoverData.m_debug.m_myOrbit.m_center.m_z,
      numVerts: 2,
      color: (const bfx::Color *)&v152.m_tune.m_repulsionPackage.m_sphereForces);
    v29 = this->m_pSpace;
    v152.m_hoverData.m_vForwVelOld.m_z = v146;
    *(float *)&v152.m_hoverData.m_bFinalApproach = v147;
    v152.m_hoverData.m_prevDistanceToGoal = v148;
    v152.m_hoverData.m_recentlyCrossedPaths = v149;
    v152.m_hoverData.m_lingeringSteeringForce.m_x = v150;
    v152.m_hoverData.m_lingeringSteeringForce.m_y = v151;
    bfx::DrawLineList(
      pSpace: v29,
      pVerts: (bfx::Vec3 *)&v152.m_hoverData.m_vForwVelOld.m_z,
      numVerts: 2,
      color: (const bfx::Color *)&v152.m_tune.m_repulsionPackage.m_sphereForces);
  }
  if ( BYTE2(v6->dtr_InstanceComponent) != 0 && this->m_pRepulsor != nullptr )
  {
    *(float *)&v152.m_tune.m_idleTune.m_circleWhileIdle = 0.0;
    v152.m_tune.m_idleTune.m_idleSpeedScale = 0.0;
    v152.m_tune.m_idleTune.m_circlingRadius = 0.0;
    bfx::Matrix::Build(this: &v161, q: &this->m_rot, pos: (const bfx::Vec3 *)&v152.m_tune.m_idleTune);
    *(float *)&v152.m_surfer.m_state = v161.m_data[0];
    *(float *)&v152.m_surfer.m_iFace0 = v161.m_data[1];
    *(float *)&v152.m_surfer.m_iFace1 = v161.m_data[2];
    v152.m_tune.m_orienter.m_angularVelMax = v161.m_data[8];
    *(float *)&v152.m_tune.m_orienter.m_stayRightSideUp = v161.m_data[9];
    *(float *)&v152.m_tune.m_orienter.m_turnMode = v161.m_data[10];
    v152.m_debugColor.m_a = v161.m_data[4];
    *(float *)&v152.m_debug = v161.m_data[5];
    *(float *)&v152.m_surfer.__vftable = v161.m_data[6];
    bfx::Matrix::Build(
      this: &v162,
      xAxis: (const bfx::Vec3 *)&v152.m_debugColor.m_a,
      yAxis: (const bfx::Vec3 *)&v152.m_tune.m_orienter,
      zAxis: (const bfx::Vec3 *)&v152.m_surfer.m_state,
      trans: &this->m_surfer.m_pos);
    m_pRepulsor = (const bfx::Color *)this->m_pRepulsor;
    if ( m_pRepulsor != nullptr )
    {
      v31 = m_pRepulsor->m_g;
      v32 = m_pRepulsor->m_a;
      v138.m_y = m_pRepulsor->m_b;
      v138.m_x = v31;
      v138.m_z = v32;
      v162.m_data[14] = v32;
      v162.m_data[13] = v138.m_y;
      v162.m_data[12] = v31;
    }
    bfx::DrawRepulsorCircles(pSpace: this->m_pSpace, mat: (bfx::Vec3 *)&v162, sphereData: m_pRepulsor + 2);
  }
  if ( BYTE1(v6->dtr_InstanceComponent) != 0 )
  {
    m_state = this->m_state;
    if ( m_state == GOTO_POS || m_state == DECEL_TO_STOP || m_state == INITIAL_ROTATION )
    {
      m_pPath = this->m_pPath;
      if ( m_pPath != nullptr && m_pPath->m_valid )
      {
        v35 = this->m_surfer.m_pos.m_y;
        v36 = this->m_surfer.m_pos.m_z;
        m_x = this->m_surfer.m_pos.m_x;
        v38 = this->m_reachableGoalPos.m_z;
        v138.m_y = this->m_reachableGoalPos.m_y;
        v39 = v138.m_y;
        v40 = this->m_reachableGoalPos.m_x;
        v159 = v138.m_y;
        v140 = v35;
        v141 = v36;
        v138.m_x = v40;
        v41 = v40;
        v139 = m_x;
        v138.m_z = v38;
        v42 = v38;
        v160 = v38;
        v43 = this->m_pSpace;
        v158 = v40;
        v157.m_z = v36;
        v157.m_x = m_x;
        v157.m_y = v35;
        bfx::DrawLineList(pSpace: v43, pVerts: &v157, numVerts: 2, color: &ColorRed_7);
        Scale = bfx::GetScale();
        bfx::DrawBox(
          pSpace: this->m_pSpace,
          pos: &this->m_lastGoalPosActedOn,
          r: (float)((float)Scale * (float)0.25),
          color: v45,
          a5: &ColorRed_7);
        v46 = bfx::GetScale();
        bfx::DrawBox(
          pSpace: this->m_pSpace,
          pos: &v138,
          r: (float)((float)v46 * (float)0.30000001),
          color: v47,
          a5: &ColorOrange_7);
        v48 = this->m_lastGoalPosActedOn.m_x;
        v49 = this->m_lastGoalPosActedOn.m_y;
        v50 = this->m_lastGoalPosActedOn.m_z;
        v152.m_hoverData.m_idleStateData.m_center.m_z = v41;
        v51 = this->m_pSpace;
        v152.m_hoverData.m_idleStateData.m_vUp.m_x = v39;
        v152.m_hoverData.m_idleStateData.m_vUp.m_y = v42;
        v152.m_hoverData.m_idleStateData.m_vUp.m_z = v48;
        *(float *)&v152.m_hoverData.m_debug.m_pSpace = v49;
        v152.m_hoverData.m_debug.m_vRepulsion.m_x = v50;
        bfx::DrawLineList(
          pSpace: v51,
          pVerts: (bfx::Vec3 *)&v152.m_hoverData.m_idleStateData.m_center.m_z,
          numVerts: 2,
          color: &ColorRed_7);
      }
    }
  }
  if ( bfx::g_drawMover3DPath && this->m_state == GOTO_POS )
  {
    v52 = this->m_pPath;
    if ( v52 != nullptr && v52->m_valid )
    {
      v53 = this->m_surfer.m_pos.m_y;
      v54 = this->m_surfer.m_pos.m_z;
      v55 = this->m_pSpace;
      v152.m_tune.m_repulsionPackage.m_blockageFlags = LODWORD(this->m_surfer.m_pos.m_x);
      *(float *)&v152.m_tune.m_repulsionPackage.m_identityFlags = v53;
      v152.m_tune.m_goalRadius = v54;
      bfx::Path3D::Cursor::DrawToEnd(
        this: &this->m_curPathCC,
        pSpace: v55,
        curPos: (const bfx::Vec3 *)&v152.m_tune.m_repulsionPackage.m_blockageFlags);
    }
  }
  if ( bfx::g_drawMover3DNextPathPos && this->m_state == GOTO_POS )
  {
    v56 = this->m_pPath;
    if ( v56 != nullptr && v56->m_valid )
    {
      bfx::Mover3DImpl::CalcNextPathPos(this: &v152, result: (bfx::Vec3 *)this);
      v57 = this->m_surfer.m_pos.m_z;
      v58 = this->m_surfer.m_pos.m_y;
      v59 = this->m_pSpace;
      v139 = this->m_surfer.m_pos.m_x;
      v141 = v57;
      v140 = v58;
      v153.m_y = v58;
      v154 = v152.__vftable;
      v155 = v152.m_pSpace;
      v156 = *(float *)&v152.m_stranded;
      v153.m_x = v139;
      v153.m_z = v57;
      bfx::DrawLineList(pSpace: v59, pVerts: &v153, numVerts: 2, color: &ColorYellow_7);
      v60 = bfx::GetScale();
      bfx::DrawCross(
        pSpace: this->m_pSpace,
        pos: (const bfx::Vec3 *)&v152,
        radius: (float)((float)v60 * (float)0.5),
        color: v61,
        a5: &ColorYellow_7);
    }
  }
  if ( (bfx::g_drawMover3DMotion || this->m_debug) && this->m_pTune->m_movementType == HOVER )
  {
    if ( this->m_hoverData.m_recentlyCrossedPaths > 0.0 )
    {
      v62 = this->m_surfer.m_pos.m_x;
      v63 = this->m_surfer.m_pos.m_y;
      v64 = this->m_rot.m_x;
      v65 = this->m_surfer.m_pos.m_z;
      v66 = this->m_rot.m_y;
      v67 = this->m_rot.m_z;
      *(float *)&v152.m_surfer.m_pMover = this->m_rot.m_w;
      v152.m_rot.m_w = v64;
      *(float *)&v152.m_pTune = v62;
      v152.m_rot.m_x = v66;
      v152.m_debugColor.m_r = v63;
      v152.m_rot.m_y = v67;
      v152.m_debugColor.m_g = v65;
      bfx::Matrix::Build(
        this: &v164,
        q: (const bfx::Quat *)&v152.m_surfer.m_pMover,
        pos: (const bfx::Vec3 *)&v152.m_pTune);
      bfx::DrawPieWedge(
        pSpace: this->m_pSpace,
        mat: (bfx::Vec3 *)&v164,
        radius: 2.0,
        color: v68,
        radiansStart: 1.3089969,
        radiansEnd: 1.8325958,
        a7: &ColorGreen_7);
    }
    v69 = this->m_state;
    if ( (unsigned int)v69 > DECEL_TO_STOP )
    {
      HIDWORD(v70) = "unknown";
    }
    else if ( v69 == INITIAL_ROTATION )
    {
      HIDWORD(v70) = "initRot";
    }
    else if ( v69 == GOTO_POS )
    {
      HIDWORD(v70) = "gotoPos";
    }
    else if ( v69 != IDLE )
    {
      HIDWORD(v70) = "decel";
    }
    else
    {
      HIDWORD(v70) = "idle";
    }
    v71 = (float)(this->m_hoverData.m_vForwVel.m_y * this->m_hoverData.m_vForwVel.m_y);
    v72 = this->m_hoverData.m_vForwVel.m_x;
    v73 = this->m_hoverData.m_vForwVel.m_z;
    v74 = this->m_surfer.m_pos.m_z;
    LODWORD(v75) = LODWORD(this->m_surfer.m_pos.m_y);
    v152.m_tune.m_movementType = LODWORD(this->m_surfer.m_pos.m_x);
    HIDWORD(v76) = "%0d state=%s\nfailedTurn=%d vel=%.2f";
    LODWORD(v76) = this->m_steeringPriority;
    v152.m_tune.m_accTime = v74;
    p_m_hoverData = &this->m_hoverData;
    LODWORD(v152.m_tune.m_desSpeed) = v75;
    *(__int64 *)((char *)&v70 - 4) = __fsqrts((float)((float)((float)v73 * (float)v73)
                                                    + (float)((float)((float)v72 * (float)v72) + (float)v71)));
    bfx::DrawString(
      pSpace: (bfx::Vector3 *)this->m_pSpace,
      inputPos: (const bfx::Vec3 *)&v152.m_tune.m_movementType,
      fmt: v76,
      a4: v70,
      a5: v75,
      a6: v130,
      a7: v131,
      a8: v132,
      a9: v133,
      a10: v134,
      a11: v135,
      a12: v136,
      a13: v137);
    if ( this->m_hoverData.m_debug.m_vRepulsion.m_x != 0.0
      || this->m_hoverData.m_debug.m_vRepulsion.m_y != 0.0
      || (v78 = 1, this->m_hoverData.m_debug.m_vRepulsion.m_z != 0.0) )
    {
      v78 = 0;
    }
    if ( v78 == 0 )
    {
      v79 = this->m_surfer.m_pos.m_x;
      v80 = (float)(this->m_hoverData.m_debug.m_vRepulsion.m_x * s_drawScale);
      v81 = this->m_surfer.m_pos.m_y;
      v82 = (float)(this->m_hoverData.m_debug.m_vRepulsion.m_y * s_drawScale);
      v83 = (float)(this->m_hoverData.m_debug.m_vRepulsion.m_z * s_drawScale);
      v138.m_z = this->m_surfer.m_pos.m_z;
      v139 = v79;
      v138.m_y = v81;
      v138.m_x = v79;
      v140 = v81;
      v141 = v138.m_z;
      v84 = this->m_pSpace;
      v152.m_hoverData.m_debug.m_vCollisionPos.m_y = v138.m_z + (float)v83;
      v152.m_hoverData.m_debug.m_vMyPos.m_z = v79 + (float)v80;
      v152.m_hoverData.m_debug.m_vBraking.m_z = v79;
      v152.m_hoverData.m_debug.m_vMyPos.m_x = v81;
      v152.m_hoverData.m_debug.m_vMyPos.m_y = v138.m_z;
      v152.m_hoverData.m_debug.m_vCollisionPos.m_x = v81 + (float)v82;
      bfx::DrawLineList(
        pSpace: v84,
        pVerts: (bfx::Vec3 *)&v152.m_hoverData.m_debug.m_vBraking.m_z,
        numVerts: 2,
        color: &ColorMagenta_7);
    }
    if ( this->m_hoverData.m_debug.m_vSteering.m_x != 0.0
      || this->m_hoverData.m_debug.m_vSteering.m_y != 0.0
      || (v85 = 1, this->m_hoverData.m_debug.m_vSteering.m_z != 0.0) )
    {
      v85 = 0;
    }
    if ( v85 == 0 )
    {
      v86 = this->m_surfer.m_pos.m_y;
      v87 = this->m_surfer.m_pos.m_x;
      v88 = (float)(this->m_hoverData.m_debug.m_vSteering.m_x * s_drawScale);
      v89 = (float)(this->m_hoverData.m_debug.m_vSteering.m_y * s_drawScale);
      v90 = (float)(this->m_hoverData.m_debug.m_vSteering.m_z * s_drawScale);
      v141 = this->m_surfer.m_pos.m_z;
      v140 = v86;
      v138.m_z = v141;
      v138.m_x = v87;
      v138.m_y = v86;
      v139 = v87;
      v91 = this->m_pSpace;
      v152.m_hoverData.m_debug.m_desiredOrbit.m_rotationAxis.m_z = v87 + (float)v88;
      v152.m_hoverData.m_debug.m_desiredOrbit.m_rotationAxis.m_x = v86;
      *(float *)&v152.m_steeringPriority = v141 + (float)v90;
      v152.m_hoverData.m_debug.m_desiredOrbit.m_radius = v87;
      v152.m_hoverData.m_debug.m_desiredOrbit.m_rotationAxis.m_y = v141;
      *(float *)&v152.m_state = v86 + (float)v89;
      bfx::DrawLineList(
        pSpace: v91,
        pVerts: (bfx::Vec3 *)&v152.m_hoverData.m_debug.m_desiredOrbit.m_radius,
        numVerts: 2,
        color: &ColorYellow_7);
    }
    if ( this->m_hoverData.m_debug.m_vTargetAttraction.m_x != 0.0
      || this->m_hoverData.m_debug.m_vTargetAttraction.m_y != 0.0
      || (v92 = 1, this->m_hoverData.m_debug.m_vTargetAttraction.m_z != 0.0) )
    {
      v92 = 0;
    }
    if ( v92 == 0 )
    {
      v93 = this->m_surfer.m_pos.m_x;
      v94 = this->m_surfer.m_pos.m_y;
      v95 = (float)(this->m_hoverData.m_debug.m_vTargetAttraction.m_x * s_drawScale);
      v96 = (float)(this->m_hoverData.m_debug.m_vTargetAttraction.m_y * s_drawScale);
      v97 = (float)(this->m_hoverData.m_debug.m_vTargetAttraction.m_z * s_drawScale);
      v141 = this->m_surfer.m_pos.m_z;
      v139 = v93;
      v138.m_y = v94;
      v138.m_x = v93;
      v138.m_z = v141;
      v140 = v94;
      v98 = this->m_pSpace;
      v152.m_lastGoalPosActedOn.m_x = v94 + (float)v96;
      v152.m_reachableGoalPos.m_z = v93;
      v152.m_lastRequestedGoalPos.m_x = v94;
      v152.m_lastRequestedGoalPos.m_y = v141;
      v152.m_lastRequestedGoalPos.m_z = v93 + (float)v95;
      v152.m_lastGoalPosActedOn.m_y = v141 + (float)v97;
      bfx::DrawLineList(
        pSpace: v98,
        pVerts: (bfx::Vec3 *)&v152.m_reachableGoalPos.m_z,
        numVerts: 2,
        color: &ColorBlue_7);
    }
    if ( this->m_hoverData.m_debug.m_vBraking.m_x != 0.0
      || this->m_hoverData.m_debug.m_vBraking.m_y != 0.0
      || (v99 = 1, this->m_hoverData.m_debug.m_vBraking.m_z != 0.0) )
    {
      v99 = 0;
    }
    if ( v99 == 0 )
    {
      v100 = this->m_surfer.m_pos.m_x;
      v101 = this->m_surfer.m_pos.m_z;
      v102 = (float)(s_drawScale * this->m_hoverData.m_debug.m_vBraking.m_x);
      v103 = (float)(this->m_hoverData.m_debug.m_vBraking.m_y * s_drawScale);
      v104 = (float)(this->m_hoverData.m_debug.m_vBraking.m_z * s_drawScale);
      v140 = this->m_surfer.m_pos.m_y;
      v139 = v100;
      v141 = v101;
      v138.m_y = v140;
      v138.m_z = v101;
      v138.m_x = v100;
      v152.m_orbitCenterPos.m_x = v100;
      v105 = this->m_pSpace;
      v152.m_orbitCenterPos.m_y = v140;
      v152.m_orbitCenterPos.m_z = v101;
      v152.m_hoverData.m_vForwVel.m_x = v100 + (float)v102;
      v152.m_hoverData.m_vForwVel.m_y = v140 + (float)v103;
      v152.m_hoverData.m_vForwVel.m_z = v101 + (float)v104;
      bfx::DrawLineList(pSpace: v105, pVerts: &v152.m_orbitCenterPos, numVerts: 2, color: &ColorRed_7);
    }
    if ( this->m_hoverData.m_debug.m_enable )
    {
      v106 = this->m_surfer.m_pos.m_y;
      v107 = this->m_surfer.m_pos.m_z;
      v142.m_data[0] = this->m_surfer.m_pos.m_x;
      v142.m_data[1] = v106;
      v142.m_data[2] = v107;
      bfx::Mover3DImpl::HoverData::Debug::DrawOrbits(this: &this->m_hoverData.m_debug, curPos: (const bfx::Vec3 *)&v142);
    }
    if ( p_m_hoverData->m_vForwVel.m_x != 0.0
      || this->m_hoverData.m_vForwVel.m_y != 0.0
      || (v108 = 1, this->m_hoverData.m_vForwVel.m_z != 0.0) )
    {
      v108 = 0;
    }
    if ( v108 == 0 )
    {
      v109 = p_m_hoverData->m_vForwVel.m_x;
      v110 = this->m_hoverData.m_vForwVel.m_z;
      v111 = this->m_surfer.m_pos.m_x;
      v112 = this->m_surfer.m_pos.m_z;
      v140 = this->m_hoverData.m_vForwVel.m_y;
      v139 = v109;
      v141 = v110;
      v142.m_data[0] = v111;
      v113 = this->m_surfer.m_pos.m_y;
      v142.m_data[2] = v112;
      v138.m_x = v111;
      *(float *)&v152.m_hoverData.m_failedToTurnEnough = v112;
      v142.m_data[1] = v113;
      v138.m_y = v113;
      v138.m_z = v112;
      v152.m_hoverData.m_vOrientationKeeping.m_y = v111;
      v114 = this->m_pSpace;
      v152.m_hoverData.m_vOrientationKeeping.m_z = v113;
      _FP5 = (float)((float)__fsqrts((float)((float)(v110 * v110) + (float)((float)(v109 * v109) + (float)(v140 * v140))))
                   - (float)1.0842022e-19);
      __asm { fsel      f3, f5, f4, f31 }
      v152.m_hoverData.m_idleStateData.m_circlingDir = v138.m_x + (float)((float)(v109 * (float)_FP3) * (float)4.0);
      v152.m_hoverData.m_idleStateData.m_bestFitRadius = v113 + (float)((float)(v140 * (float)_FP3) * (float)4.0);
      v152.m_hoverData.m_idleStateData.m_maxRadius = v112 + (float)((float)(v110 * (float)_FP3) * (float)4.0);
      bfx::DrawLineList(
        pSpace: v114,
        pVerts: (bfx::Vec3 *)&v152.m_hoverData.m_vOrientationKeeping.m_y,
        numVerts: 2,
        color: &ColorGreen_7);
    }
    if ( this->m_state != IDLE || (v117 = 1, this->m_hoverData.m_idleStateData.m_circlingDir == 0.0) )
      v117 = 0;
    if ( v117 == 0 )
    {
      v152.m_rot.m_z = 1.0;
      m_pTune = this->m_pTune;
      v152.m_orienter.m_curRot.m_w = 0.5;
      v119 = this->m_hoverData.m_debug.m_vMyPos.m_x;
      v120 = this->m_hoverData.m_debug.m_vMyPos.m_y;
      v121 = this->m_hoverData.m_debug.m_vMyPos.m_z;
      v152.m_orienter.m_curRot.m_x = 1.0;
      v152.m_orienter.m_curRot.m_y = 0.5;
      v122 = this->m_pSpace;
      v152.m_orienter.m_timeSpentRolled = m_pTune->m_repulsionPackage.m_sphereData.m_radius * (float)2.0;
      v152.m_orienter.m_rollAngularVel.m_x = v119;
      v152.m_orienter.m_rollAngularVel.m_y = v120;
      v152.m_orienter.m_rollAngularVel.m_z = v121;
      bfx::DrawSphere(
        pSpace: v122,
        sphere: (const bfx::Sphere *)&v152.m_orienter.m_rollAngularVel,
        color: (const bfx::Color *)&v152.m_rot.m_z);
    }
    if ( this->m_hoverData.m_debug.m_vCollisionPos.m_x != 0.0
      || this->m_hoverData.m_debug.m_vCollisionPos.m_y != 0.0
      || (v123 = 1, this->m_hoverData.m_debug.m_vCollisionPos.m_z != 0.0) )
    {
      v123 = 0;
    }
    if ( v123 == 0 )
    {
      v124 = this->m_pTune;
      v125 = this->m_hoverData.m_debug.m_vCollisionPos.m_y;
      v126 = this->m_hoverData.m_debug.m_vCollisionPos.m_z;
      v127 = this->m_pSpace;
      v128 = (float)(v124->m_repulsionPackage.m_sphereData.m_innerCushion
                   + v124->m_repulsionPackage.m_sphereData.m_outerCushion);
      v129 = v124->m_repulsionPackage.m_sphereData.m_radius;
      v152.m_orienter.m_curRot.m_z = this->m_hoverData.m_debug.m_vCollisionPos.m_x;
      v152.m_orienter.m_angularVel.m_x = v125;
      v152.m_orienter.m_angularVel.m_y = v126;
      v152.m_orienter.m_angularVel.m_z = (float)v128 + (float)v129;
      bfx::DrawSphere(pSpace: v127, sphere: (const bfx::Sphere *)&v152.m_orienter.m_curRot.m_z, color: &ColorGray_7);
    }
  }
}


// ========================================================================
// ?Stop@Mover3D@bfx@@QAAXXZ
// EA  : 0x83269578
// RVA : 0x01269578
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __fastcall bfx::Mover3D::Stop(bfx::Mover3D *this)
{
  bfx::Mover3DImpl *v2; // r30
  bool v3; // zf
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  v3 = this != nullptr;
  v2 = (bfx::Mover3DImpl *)(this - 4);
  if ( !v3 )
    v2 = nullptr;
  bfx::LogMover3DStop(replayID: v2->m_replayID);
  bfx::Mover3DImpl::Stop(this: v2);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$87647
// EA  : 0x832695E4
// RVA : 0x012695E4
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void _unwind_87647()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?EnableRepulsor@Mover3D@bfx@@QAAX_N@Z
// EA  : 0x83269618
// RVA : 0x01269618
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __fastcall bfx::Mover3D::EnableRepulsor(bfx::Mover3D *this, bool enable)
{
  bfx::Mover3DImpl *v4; // r30
  bool v5; // zf
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  v5 = this != nullptr;
  v4 = (bfx::Mover3DImpl *)(this - 4);
  if ( !v5 )
    v4 = nullptr;
  bfx::LogMover3DEnableRepulsor(replayID: v4->m_replayID, enable);
  bfx::Mover3DImpl::EnableRepulsor(this: v4, enable);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$87690
// EA  : 0x83269690
// RVA : 0x01269690
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void _unwind_87690()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ??0HoverData@Mover3DImpl@bfx@@QAA@PAVSpace@2@@Z
// EA  : 0x83269750
// RVA : 0x01269750
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

bfx::Mover3DImpl::HoverData *__fastcall bfx::Mover3DImpl::HoverData::HoverData(
        bfx::Mover3DImpl::HoverData *this,
        bfx::Space *pSpace)
{
  this->m_vForwVel.m_x = 0.0;
  this->m_vForwVel.m_y = 0.0;
  this->m_vForwVel.m_z = 0.0;
  this->m_vForwVelOld.m_x = 0.0;
  this->m_vForwVelOld.m_y = 0.0;
  this->m_vForwVelOld.m_z = 0.0;
  this->m_bFinalApproach = false;
  this->m_prevDistanceToGoal = -1.0;
  this->m_recentlyCrossedPaths = 0.0;
  this->m_lingeringSteeringForce.m_x = 0.0;
  this->m_lingeringSteeringForce.m_y = 0.0;
  this->m_lingeringSteeringForce.m_z = 0.0;
  this->m_vOrientationKeeping.m_x = 0.0;
  this->m_vOrientationKeeping.m_y = 0.0;
  this->m_vOrientationKeeping.m_z = 0.0;
  this->m_failedToTurnEnough = false;
  this->m_idleStateData.m_circlingDir = 0.0;
  this->m_idleStateData.m_bestFitRadius = 0.0;
  this->m_idleStateData.m_maxRadius = 0.0;
  this->m_idleStateData.m_center.m_x = 0.0;
  this->m_idleStateData.m_center.m_y = 0.0;
  this->m_idleStateData.m_center.m_z = 0.0;
  this->m_idleStateData.m_vUp.m_x = 0.0;
  this->m_idleStateData.m_vUp.m_y = 0.0;
  this->m_idleStateData.m_vUp.m_z = 0.0;
  bfx::Mover3DImpl::HoverData::Debug::Debug(this: &this->m_debug, pSpace);
  return this;
}


// ========================================================================
// ?GotoPos@Mover3DImpl@bfx@@QAAXABVVec3@2@ABVGotoPosSpec3D@2@_N@Z
// EA  : 0x83269800
// RVA : 0x01269800
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __fastcall bfx::Mover3DImpl::GotoPos(
        bfx::Mover3DImpl *this,
        const bfx::Vec3 *requestedGoalPos,
        const bfx::GotoPosSpec3D *spec,
        bool forceUpdate)
{
  const bfx::Volume *Volume; // r27
  double Scale; // fp1
  const bfx::Mover3DTune *m_pTune; // r11
  bfx::Space *m_pSpace; // r3
  bfx::Planner3D *Planner3D; // r3
  bfx::Vec3 *ClosestReachableVolume; // r3
  bfx::Vec3 *v14; // r29
  const bfx::Volume *v15; // r7
  float m_y; // r9
  bfx::Space *v17; // r3
  unsigned int m_customGeoMatchFlags; // r11
  float m_z; // r29
  bfx::Path3D *Path; // r29
  bfx::Path3D *m_pPath; // r28
  double v22; // fp0
  double v23; // fp13
  double v24; // fp12
  bool m_stopAtGoal; // r10
  bool v26; // r7
  bfx::Path3DSpec v27; // [sp+50h] [-70h] BYREF
  bfx::Path3DSpec v28; // [sp+54h] [-6Ch] BYREF
  bfx::Path3D::Cursor v29; // [sp+58h] [-68h]
  bfx::Volume v30; // [sp+60h] [-60h] BYREF

  this->m_lastRequestedGoalPos = *requestedGoalPos;
  Volume = bfx::Surfer3D::GetVolume(this: &this->m_surfer);
  if ( Volume != nullptr )
  {
    if ( forceUpdate
      || (Scale = bfx::GetScale(),
          (unsigned __int8)bfx::Mover3DImpl::IgnoreGotoPosDueToSimilarParams(
                             this,
                             oldGoalPos: &this->m_lastGoalPosActedOn,
                             newGoalPos: requestedGoalPos,
                             newGotoPosSpec: spec,
                             ignoreThresholdDist: (float)((float)Scale * (float)0.1)) == 0) )
    {
      m_pTune = this->m_pTune;
      m_pSpace = this->m_pSpace;
      v27.m_customGeoMatchFlags = -1;
      v27.m_customGeoMatchFlags = m_pTune->m_customGeoMatchFlags;
      Planner3D = bfx::GetPlanner3D(pSpace: m_pSpace);
      ClosestReachableVolume = (bfx::Vec3 *)bfx::Planner3D::GetClosestReachableVolume(
                                              this: Planner3D,
                                              pStartVolume: Volume,
                                              pos: requestedGoalPos,
                                              pathSpec: &v27);
      v14 = ClosestReachableVolume;
      if ( ClosestReachableVolume != nullptr )
      {
        bfx::Volume::GetClosestPos(this: &v30, result: ClosestReachableVolume, pos: requestedGoalPos);
        v28.m_customGeoMatchFlags = -1;
        v15 = (const bfx::Volume *)v14;
        m_y = this->m_surfer.m_pos.m_y;
        v17 = this->m_pSpace;
        m_customGeoMatchFlags = this->m_pTune->m_customGeoMatchFlags;
        m_z = this->m_surfer.m_pos.m_z;
        v30.m_volumeIndex = LODWORD(this->m_surfer.m_pos.m_x);
        v30.m_centroid.m_x = m_y;
        v28.m_customGeoMatchFlags = m_customGeoMatchFlags;
        v30.m_centroid.m_y = m_z;
        Path = bfx::FindPath(
                 pSpace: v17,
                 startPos: (const bfx::Vec3 *)&v30.m_volumeIndex,
                 pStartVolume: Volume,
                 goalPos: (const bfx::Vec3 *)&v30,
                 pGoalVolume: v15,
                 pathSpec: &v28);
        if ( Path != nullptr )
        {
          m_pPath = this->m_pPath;
          if ( m_pPath != nullptr )
          {
            bfx::Path3D::~Path3D(this: this->m_pPath);
            bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pPath);
          }
          v29.m_pPath = Path;
          v22 = *(float *)&v30.__vftable;
          this->m_pPath = Path;
          v29.m_idx = 0;
          v23 = *(float *)&v30.m_pProxy;
          v24 = *(float *)&v30.m_pParentGraph;
          this->m_curPathCC = v29;
          this->m_reachableGoalPos.m_x = v22;
          this->m_reachableGoalPos.m_y = v23;
          this->m_reachableGoalPos.m_z = v24;
          bfx::Mover3DImpl::StartPathWalking(this);
          m_stopAtGoal = spec->m_stopAtGoal;
          this->m_frozen = v26;
          this->m_reachedGoal = v26;
          this->m_finalApproach = v26;
          this->m_gotoPosSpec.m_stopAtGoal = m_stopAtGoal;
          this->m_lastGoalPosActedOn.m_x = requestedGoalPos->m_x;
          this->m_lastGoalPosActedOn.m_y = requestedGoalPos->m_y;
          this->m_lastGoalPosActedOn.m_z = requestedGoalPos->m_z;
        }
      }
    }
  }
}


// ========================================================================
// ?RepathIfNeeded@Mover3DImpl@bfx@@AAA_NXZ
// EA  : 0x832699B8
// RVA : 0x012699B8
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

BOOL __fastcall bfx::Mover3DImpl::RepathIfNeeded(bfx::Mover3DImpl *this)
{
  const bfx::Volume *Volume; // r30
  bfx::Path3D *m_pPath; // r10
  char v5; // r9
  BOOL v6; // r28
  bfx::Path3D *v7; // r9
  signed int m_idx; // r11
  const bfx::Volume *m_pFinalVolume; // r3
  const bfx::Mover3DTune *m_pTune; // r10
  bfx::Path3D *v11; // r11
  const bfx::Volume *v12; // r5
  float m_x; // r3
  float m_y; // r30
  float m_z; // r29
  const bfx::Volume *v16; // r7
  bfx::Path3D *Path; // r30
  bfx::Path3D *v18; // r29
  bool v19; // r7
  bfx::Path3DSpec v20; // [sp+50h] [-50h] BYREF
  bfx::Path3D::Cursor v21; // [sp+58h] [-48h]
  bfx::Vec3 v22; // [sp+60h] [-40h] BYREF

  Volume = bfx::Surfer3D::GetVolume(this: &this->m_surfer);
  if ( Volume == nullptr )
    return false;
  m_pPath = this->m_pPath;
  v5 = _cntlzw(m_pPath->m_valid);
  v6 = (v5 & 0x20) != 0;
  if ( (v5 & 0x20) == 0 )
  {
    v7 = this->m_curPathCC.m_pPath;
    m_idx = this->m_curPathCC.m_idx;
    if ( m_idx >= v7->m_portalPoints.m_size )
      m_pFinalVolume = m_pPath->m_pFinalVolume;
    else
      m_pFinalVolume = bfx::Portal::GetVolumeFrom(
                         this: (bfx::Portal *)v7->m_portalPoints.m_data[m_idx].m_pPortal,
                         dir: v7->m_portalPoints.m_data[m_idx].m_dir);
    v6 = Volume != m_pFinalVolume;
  }
  if ( v6 )
  {
    m_pTune = this->m_pTune;
    v11 = this->m_pPath;
    v12 = Volume;
    m_x = this->m_surfer.m_pos.m_x;
    m_y = this->m_surfer.m_pos.m_y;
    m_z = this->m_surfer.m_pos.m_z;
    v20.m_customGeoMatchFlags = -1;
    v20.m_customGeoMatchFlags = m_pTune->m_customGeoMatchFlags;
    v16 = v11->m_pFinalVolume;
    v22.m_x = m_x;
    v22.m_y = m_y;
    v22.m_z = m_z;
    Path = bfx::FindPath(
             pSpace: this->m_pSpace,
             startPos: &v22,
             pStartVolume: v12,
             goalPos: &v11->m_finalPos,
             pGoalVolume: v16,
             pathSpec: &v20);
    if ( Path == nullptr )
      return false;
    v18 = this->m_pPath;
    if ( v18 != nullptr )
    {
      bfx::Path3D::~Path3D(this: this->m_pPath);
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v18);
    }
    v21.m_pPath = Path;
    this->m_pPath = Path;
    v21.m_idx = 0;
    this->m_curPathCC = v21;
    bfx::Mover3DImpl::StartPathWalking(this);
    this->m_frozen = v19;
  }
  return v6;
}


// ========================================================================
// ?Teleport@Mover3DImpl@bfx@@QAAXABVVec3@2@ABVQuat@2@@Z
// EA  : 0x83269B08
// RVA : 0x01269B08
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __fastcall bfx::Mover3DImpl::Teleport(bfx::Mover3DImpl *this, const bfx::Vec3 *newPos, const bfx::Quat *newRot)
{
  bfx::MSurfer3D *p_m_surfer; // r27
  const bfx::Volume *Volume; // r3
  const bfx::Mover3DTune *m_pTune; // r11
  const bfx::Volume *v9; // r26
  bfx::Space *m_pSpace; // r3
  bfx::Planner3D *Planner3D; // r3
  bfx::Vec3 *ClosestVolume; // r3
  const bfx::Volume *v13; // r29
  bfx::Path3DSpec v14; // [sp+50h] [-50h] BYREF
  bfx::Volume v15; // [sp+58h] [-48h] BYREF

  p_m_surfer = &this->m_surfer;
  Volume = bfx::Surfer3D::GetVolume(this: &this->m_surfer);
  m_pTune = this->m_pTune;
  v9 = Volume;
  m_pSpace = this->m_pSpace;
  v14.m_customGeoMatchFlags = -1;
  v14.m_customGeoMatchFlags = m_pTune->m_customGeoMatchFlags;
  Planner3D = bfx::GetPlanner3D(pSpace: m_pSpace);
  ClosestVolume = (bfx::Vec3 *)bfx::Planner3D::GetClosestVolume(this: Planner3D, pos: newPos, pathSpec: &v14);
  v13 = (const bfx::Volume *)ClosestVolume;
  if ( ClosestVolume != nullptr )
  {
    bfx::Volume::GetClosestPos(this: &v15, result: ClosestVolume, pos: newPos);
    bfx::Surfer3D::SetPosAndVolume(this: p_m_surfer, pos: (const bfx::Vec3 *)&v15, pVolume: v13);
    this->m_rot.m_w = newRot->m_w;
    this->m_rot.m_x = newRot->m_x;
    this->m_rot.m_y = newRot->m_y;
    this->m_rot.m_z = newRot->m_z;
    bfx::Mover3DImpl::RegeneratePath(this, pOldVolume: v9, pNewVolume: v13);
    if ( this->m_state == GOTO_POS )
      bfx::Mover3DImpl::RepathIfNeeded(this);
  }
}


// ========================================================================
// ?CalcCrowdAcc@Mover3DImpl@bfx@@QAA?AVVec3@2@AAV?$Array@PAVRepulsor3DImpl@bfx@@@2@_N@Z
// EA  : 0x83269BD0
// RVA : 0x01269BD0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

bfx::Mover3DImpl *__fastcall bfx::Mover3DImpl::CalcCrowdAcc(
        bfx::Mover3DImpl *this,
        bfx::Vec3 *result,
        bfx::Array<bfx::Repulsor3DImpl *> *nearbyMover3D,
        bool bRepulsion)
{
  double v7; // fp13
  float m_z; // r9
  double v9; // fp13
  float m_x; // r8
  double v11; // fp11
  double v12; // fp12
  double m_y; // fp10
  int v14; // r27
  double v15; // fp31
  BOOL v16; // r26
  int v17; // r29
  bfx::Repulsor3DImpl *v18; // r5
  double v19; // fp1
  float *v20; // r3
  int m_size; // r11
  double v22; // fp7
  double v23; // fp9
  float v25[4]; // [sp+50h] [-60h] BYREF
  char v26; // [sp+60h] [-50h] BYREF

  v7 = *(float *)(LODWORD(result[8].m_z) + 48);
  *(float *)&this->__vftable = 0.0;
  *(float *)&this->m_pSpace = 0.0;
  *(float *)&this->m_stranded = 0.0;
  if ( v7 != 0.0 )
  {
    m_z = result[11].m_z;
    v9 = (float)(result[27].m_x * result[27].m_x);
    m_x = result[12].m_x;
    v11 = result[27].m_x;
    v12 = result[26].m_z;
    m_y = result[27].m_y;
    v25[0] = result[11].m_y;
    v25[1] = m_z;
    v25[2] = m_x;
    v14 = 0;
    v15 = __fsqrts((float)((float)((float)m_y * (float)m_y) + (float)((float)((float)v12 * (float)v12) + (float)v9)));
    result[38].m_y = v25[0] + (float)((float)v12 * (float)2.0);
    result[38].m_z = m_z + (float)((float)v11 * (float)2.0);
    result[39].m_x = m_x + (float)((float)m_y * (float)2.0);
    if ( nearbyMover3D->m_size > 0 )
    {
      v16 = bRepulsion;
      v17 = 0;
      do
      {
        v18 = nearbyMover3D->m_data[v17];
        v19 = (float)((float)((float)((float)((float)(v18->m_repulsionPackage.m_sphereData.m_innerCushion
                                                    + v18->m_repulsionPackage.m_sphereData.m_outerCushion)
                                            + *(float *)(LODWORD(result[8].m_z) + 8))
                                    + *(float *)(LODWORD(result[8].m_z) + 4))
                            + *(float *)LODWORD(result[8].m_z))
                    + v18->m_repulsionPackage.m_sphereData.m_radius);
        if ( v16 )
          v20 = (float *)bfx::Mover3DImpl::CalcRepulsionAcc(
                           this: (bfx::Mover3DImpl *)v25,
                           result,
                           pCurNeighbor: v18,
                           maxRepulsionRadius: v19);
        else
          v20 = (float *)bfx::Mover3DImpl::CalcSteeringAcc(
                           this: (bfx::Mover3DImpl *)&v26,
                           result,
                           pCurNeighbor: v18,
                           steeringRadius: v19,
                           mySpeed: v15);
        m_size = nearbyMover3D->m_size;
        ++v14;
        ++v17;
        v22 = (float)(v20[1] + *(float *)&this->m_pSpace);
        v23 = (float)(*(float *)&this->__vftable + *v20);
        *(float *)&this->m_stranded = v20[2] + *(float *)&this->m_stranded;
        *(float *)&this->m_pSpace = v22;
        *(float *)&this->__vftable = v23;
      }
      while ( v14 < m_size );
    }
  }
  return this;
}


// ========================================================================
// ?AdjustOrbitforCrowd@Mover3DImpl@bfx@@QAAXAAV?$Array@PAVRepulsor3DImpl@bfx@@@2@@Z
// EA  : 0x83269D58
// RVA : 0x01269D58
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __fastcall bfx::Mover3DImpl::AdjustOrbitforCrowd(
        bfx::Mover3DImpl *this,
        bfx::Array<bfx::Repulsor3DImpl *> *nearbyMover3D)
{
  float v4; // r8
  double m_x; // fp13
  double m_z; // fp12
  float v7; // r11
  double m_y; // fp11
  double v9; // fp9
  float *v10; // r25
  char v11; // r24
  int v12; // r26
  int v13; // r28
  bfx::Mover3D *m_pMover; // r11
  bfx::Mover3D *v15; // r29
  char v16; // r11
  const bfx::Mover3DTune *m_pTune; // r11
  int v18; // r10
  double v19; // fp0
  double v20; // fp13
  double v21; // fp10
  double v22; // fp9
  double v23; // fp12
  double v24; // fp6
  double v25; // fp31
  int m_size; // r29
  float *m_data; // r4
  int v28; // r28
  double v29; // fp0
  __int64 v30; // r11
  float *v31; // r9
  int v32; // ctr
  double v33; // fp13
  double v34; // fp31
  double v35; // fp1
  double v36; // fp10
  double v37; // fp9
  double v38; // fp7
  double v39; // fp6
  double v40; // fp10
  double v41; // fp9
  double v42; // fp7
  double v43; // fp6
  __int64 v44; // [sp+50h] [-90h] BYREF
  float v45; // [sp+58h] [-88h]
  bfx::Array<float> v46; // [sp+60h] [-80h] BYREF

  if ( this->m_pTune->m_desSpeed != 0.0 )
  {
    m_x = this->m_hoverData.m_vForwVelOld.m_x;
    m_z = this->m_hoverData.m_vForwVelOld.m_z;
    v7 = this->m_surfer.m_pos.m_z;
    m_y = this->m_hoverData.m_vForwVelOld.m_y;
    v9 = this->m_surfer.m_pos.m_x;
    LODWORD(v44) = LODWORD(this->m_surfer.m_pos.m_y);
    v4 = *((float *)&v44 + 1);
    v45 = v7;
    v10 = nullptr;
    v11 = 1;
    memset(&v46, 0, 12);
    HIDWORD(v44) = &this->m_hoverData.m_debug.m_vMyPos;
    this->m_hoverData.m_debug.m_vMyPos.m_z = v7 + (float)((float)m_z * (float)2.0);
    this->m_hoverData.m_debug.m_vMyPos.m_y = v4 + (float)((float)m_y * (float)2.0);
    this->m_hoverData.m_debug.m_vMyPos.m_x = (float)v9 + (float)((float)m_x * (float)2.0);
    v46.m_tag = bfx::MEM_BFXMOVER3D;
    v12 = 0;
    if ( nearbyMover3D->m_size > 0 )
    {
      v13 = 0;
      do
      {
        m_pMover = nearbyMover3D->m_data[v13]->m_pMover;
        if ( m_pMover != nullptr )
        {
          v15 = m_pMover - 4;
          if ( m_pMover != (bfx::Mover3D *)4 && *(_DWORD *)&v15[572] >= this->m_steeringPriority )
          {
            if ( *(_DWORD *)&v15[568] != 0 || (v16 = 1, *(float *)&v15[372] == 0.0) )
              v16 = 0;
            if ( v16 != 0 )
            {
              m_pTune = this->m_pTune;
              v18 = *(_DWORD *)&v15[104];
              v19 = (float)(*(float *)&v15[388] - this->m_hoverData.m_idleStateData.m_center.m_y);
              v20 = (float)(*(float *)&v15[384] - this->m_hoverData.m_idleStateData.m_center.m_x);
              v21 = *(float *)&v15[392];
              v22 = this->m_hoverData.m_idleStateData.m_center.m_z;
              v23 = (float)(*(float *)&v15[392] - this->m_hoverData.m_idleStateData.m_center.m_z);
              HIDWORD(v44) = v15 + 384;
              v24 = (float)(*(float *)(v18 + 84) + m_pTune->m_idleTune.m_circlingRadius);
              if ( (float)((float)((float)((float)v21 - (float)v22) * (float)((float)v21 - (float)v22))
                         + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19))) <= (double)(float)((float)v24 * (float)v24) )
              {
                v25 = (float)((float)(this->m_hoverData.m_idleStateData.m_vUp.m_x * (float)v20)
                            + (float)((float)(this->m_hoverData.m_idleStateData.m_vUp.m_y * (float)v19)
                                    + (float)(this->m_hoverData.m_idleStateData.m_vUp.m_z * (float)v23)));
                *(float *)&v44 = (float)(this->m_hoverData.m_idleStateData.m_vUp.m_x * (float)v20)
                               + (float)((float)(this->m_hoverData.m_idleStateData.m_vUp.m_y * (float)v19)
                                       + (float)(this->m_hoverData.m_idleStateData.m_vUp.m_z * (float)v23));
                bfx::Array<float>::push_back(this: &v46, val: (float *)&v44);
                if ( __fabs(v25) < (float)((float)(*(float *)(*(_DWORD *)&v15[104] + 88)
                                                 + this->m_pTune->m_idleTune.m_orbitHeight)
                                         * (float)0.5) )
                  v11 = 0;
              }
            }
          }
        }
        ++v12;
        ++v13;
      }
      while ( v12 < nearbyMover3D->m_size );
      m_size = v46.m_size;
      if ( v46.m_size != 0 )
      {
        if ( v11 != 0 )
        {
          m_data = v46.m_data;
          if ( v46.m_data == nullptr )
            return;
LABEL_42:
          bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
          return;
        }
        v10 = v46.m_data;
        qsort(
          base: v46.m_data,
          num: v46.m_size,
          width: 4u,
          comp: (int (__fastcall *)(const void *, const void *))bfx::CompareFollowerBuddies);
        v28 = -1;
        v29 = 0.0;
        HIDWORD(v30) = 0;
        if ( m_size > 0 )
        {
          v31 = v10;
          v32 = m_size;
          while ( v28 >= 0 )
          {
            v33 = *v31;
            LODWORD(v30) = v33 < __fabs(v29);
            v44 = v30;
            if ( __fabs((float)v30) != 0.0 )
            {
              v29 = v33;
              goto LABEL_25;
            }
LABEL_26:
            ++HIDWORD(v30);
            ++v31;
            if ( --v32 == 0 )
              goto LABEL_27;
          }
          v29 = *v31;
LABEL_25:
          v28 = HIDWORD(v30);
          goto LABEL_26;
        }
LABEL_27:
        v34 = bfx::Mover3DImpl::SearchOrbitList(this, orbitList: &v46, startIndex: v28, direction: 1);
        v35 = bfx::Mover3DImpl::SearchOrbitList(this, orbitList: &v46, startIndex: v28, direction: -1);
        if ( v34 == 0.0 || v35 != 0.0 && __fabs(v34) >= __fabs(v35) )
        {
          if ( v35 != 0.0 && (v34 == 0.0 || __fabs(v35) < __fabs(v34)) || v34 != 0.0 && v35 != 0.0 && v34 == -v35 )
          {
            v40 = (float)(this->m_hoverData.m_idleStateData.m_vUp.m_y * (float)v35);
            v41 = (float)(this->m_hoverData.m_idleStateData.m_vUp.m_x * (float)v35);
            v42 = this->m_hoverData.m_idleStateData.m_center.m_y;
            v43 = this->m_hoverData.m_idleStateData.m_center.m_x;
            this->m_hoverData.m_idleStateData.m_center.m_z = this->m_hoverData.m_idleStateData.m_center.m_z
                                                           + (float)(this->m_hoverData.m_idleStateData.m_vUp.m_z
                                                                   * (float)v35);
            this->m_hoverData.m_idleStateData.m_center.m_y = (float)v40 + (float)v42;
            this->m_hoverData.m_idleStateData.m_center.m_x = (float)v43 + (float)v41;
          }
        }
        else
        {
          v36 = (float)(this->m_hoverData.m_idleStateData.m_vUp.m_y * (float)v34);
          v37 = (float)(this->m_hoverData.m_idleStateData.m_vUp.m_x * (float)v34);
          v38 = this->m_hoverData.m_idleStateData.m_center.m_y;
          v39 = this->m_hoverData.m_idleStateData.m_center.m_x;
          this->m_hoverData.m_idleStateData.m_center.m_z = this->m_hoverData.m_idleStateData.m_center.m_z
                                                         + (float)(this->m_hoverData.m_idleStateData.m_vUp.m_z
                                                                 * (float)v34);
          this->m_hoverData.m_idleStateData.m_center.m_y = (float)v36 + (float)v38;
          this->m_hoverData.m_idleStateData.m_center.m_x = (float)v39 + (float)v37;
        }
      }
      else
      {
        v10 = v46.m_data;
      }
    }
    if ( v10 == nullptr )
      return;
    m_data = v10;
    goto LABEL_42;
  }
}


// ========================================================================
// __unwind$88225
// EA  : 0x8326A19C
// RVA : 0x0126A19C
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void _unwind_88225()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 224 + 96));
}


// ========================================================================
// ?UpdateInitialRotationState@Mover3DImpl@bfx@@QAAXM@Z
// EA  : 0x8326A1D0
// RVA : 0x0126A1D0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __fastcall bfx::Mover3DImpl::UpdateInitialRotationState(bfx::Mover3DImpl *this, double simTime)
{
  const bfx::Mover3DTune *m_pTune; // r11
  double m_desSpeed; // fp27
  bfx::RepulsorImpl *m_pRepulsor; // r3
  float *v7; // r3
  double v8; // fp30
  double v9; // fp29
  double v10; // fp28
  float *v11; // r3
  double v12; // fp2
  double v13; // fp27
  double v14; // fp26
  double v15; // fp25
  float *v16; // r3
  double v17; // fp24
  double v18; // fp23
  double v19; // fp22
  float *v20; // r3
  double v21; // fp0
  double m_z; // fp6
  double v23; // fp13
  double m_y; // fp4
  double v25; // fp12
  double v26; // fp7
  double v27; // fp5
  double v28; // fp11
  _BYTE v29[16]; // [sp+58h] [-B8h] BYREF
  _BYTE v30[24]; // [sp+68h] [-A8h] BYREF
  bfx::Array<bfx::SpaceComponent *> v31[7]; // [sp+80h] [-90h] BYREF

  m_pTune = this->m_pTune;
  m_desSpeed = m_pTune->m_desSpeed;
  if ( m_pTune->m_orienter.m_turnMode == 1 )
    m_desSpeed = 0.0;
  memset(v31, 0, 12);
  v31[0].m_tag = bfx::MEM_BFXMOVER3D;
  m_pRepulsor = (bfx::RepulsorImpl *)this->m_pRepulsor;
  if ( m_pRepulsor != nullptr )
    bfx::Repulsor3DImpl::GetNearbyRepulsors(this: m_pRepulsor, nearbyRepulsors: v31, filterBasedOnBlockageFlags: true);
  v7 = (float *)bfx::Mover3DImpl::CalcCrowdAcc(
                  this: (bfx::Mover3DImpl *)v29,
                  result: (bfx::Vec3 *)this,
                  nearbyMover3D: (bfx::Array<bfx::Repulsor3DImpl *> *)v31,
                  bRepulsion: true);
  v8 = (float)(v7[2] * (float)simTime);
  v9 = (float)(v7[1] * (float)simTime);
  v10 = (float)(*v7 * (float)simTime);
  v11 = (float *)bfx::Mover3DImpl::CalcCrowdAcc(
                   this: (bfx::Mover3DImpl *)v30,
                   result: (bfx::Vec3 *)this,
                   nearbyMover3D: (bfx::Array<bfx::Repulsor3DImpl *> *)v31,
                   bRepulsion: false);
  v12 = m_desSpeed;
  v13 = (float)(v11[2] * (float)simTime);
  v14 = (float)(v11[1] * (float)simTime);
  v15 = (float)((float)simTime * *v11);
  v16 = (float *)bfx::Mover3DImpl::CalcTargetAttractionAcc(
                   this: (bfx::Mover3DImpl *)v29,
                   result: (bfx::Vec3 *)this,
                   simTime,
                   curDesiredSpeed: v12);
  v17 = *v16;
  v18 = v16[1];
  v19 = v16[2];
  v20 = (float *)bfx::Mover3DImpl::CalcMaxDecel(
                   this: (bfx::Mover3DImpl *)v30,
                   result: (bfx::Vec3 *)this,
                   simTime,
                   desiredSpeed: this->m_pTune->m_desSpeed);
  v21 = (float)(*v20 * (float)simTime);
  m_z = this->m_hoverData.m_vForwVel.m_z;
  v23 = (float)(v20[2] * (float)simTime);
  m_y = this->m_hoverData.m_vForwVel.m_y;
  v25 = (float)(v20[1] * (float)simTime);
  v26 = (float)((float)((float)v19 + (float)((float)v13 + (float)v8)) + (float)(v20[2] * (float)simTime));
  v27 = (float)((float)((float)v18 + (float)((float)v14 + (float)v9)) + (float)(v20[1] * (float)simTime));
  this->m_hoverData.m_vForwVel.m_x = this->m_hoverData.m_vForwVel.m_x
                                   + (float)((float)((float)((float)v15 + (float)v10) + (float)v17)
                                           + (float)(*v20 * (float)simTime));
  this->m_hoverData.m_vForwVel.m_z = (float)m_z + (float)v26;
  this->m_hoverData.m_vForwVel.m_y = (float)m_y + (float)v27;
  if ( this->m_hoverData.m_recentlyCrossedPaths > 0.0 )
  {
    v28 = (float)(this->m_hoverData.m_recentlyCrossedPaths - (float)simTime);
    this->m_hoverData.m_recentlyCrossedPaths = this->m_hoverData.m_recentlyCrossedPaths - (float)simTime;
    if ( v28 <= 0.0 )
      this->m_hoverData.m_recentlyCrossedPaths = 0.0;
  }
  this->m_hoverData.m_debug.m_vRepulsion.m_x = v10;
  this->m_hoverData.m_debug.m_vRepulsion.m_y = v9;
  this->m_hoverData.m_debug.m_vRepulsion.m_z = v8;
  this->m_hoverData.m_debug.m_vSteering.m_x = v15;
  this->m_hoverData.m_debug.m_vSteering.m_y = v14;
  this->m_hoverData.m_debug.m_vSteering.m_z = v13;
  this->m_hoverData.m_debug.m_vTargetAttraction.m_x = v17;
  this->m_hoverData.m_debug.m_vTargetAttraction.m_y = v18;
  this->m_hoverData.m_debug.m_vTargetAttraction.m_z = v19;
  this->m_hoverData.m_debug.m_vBraking.m_x = v21;
  this->m_hoverData.m_debug.m_vBraking.m_y = v25;
  this->m_hoverData.m_debug.m_vBraking.m_z = v23;
  v31[0].m_size = 0;
  if ( v31[0].m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v31[0].m_data);
}


// ========================================================================
// __unwind$89077
// EA  : 0x8326A3E4
// RVA : 0x0126A3E4
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void _unwind_89077()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 272 + 128));
}


// ========================================================================
// ?UpdateGotoPosState@Mover3DImpl@bfx@@QAAXM@Z
// EA  : 0x8326A418
// RVA : 0x0126A418
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __fastcall bfx::Mover3DImpl::UpdateGotoPosState(bfx::Mover3DImpl *this, double simTime)
{
  int v4; // r4
  float v5; // r10
  float v6; // r8
  int v7; // r7
  double v8; // fp30
  double v9; // fp20
  bfx::RepulsorImpl *v10; // r3
  float *v11; // r3
  double v12; // fp29
  double v13; // fp28
  double v14; // fp27
  float *v15; // r3
  double v16; // fp26
  double v17; // fp25
  double v18; // fp24
  float *v19; // r3
  double v20; // fp23
  double v21; // fp22
  double v22; // fp21
  float *v23; // r3
  double m_z; // fp10
  double m_y; // fp9
  double v26; // fp7
  double v27; // fp6
  double m_recentlyCrossedPaths; // fp13
  double v29; // fp13
  float v30[4]; // [sp+58h] [-B8h] BYREF
  float v31[6]; // [sp+68h] [-A8h] BYREF
  bfx::Array<bfx::SpaceComponent *> v32[7]; // [sp+80h] [-90h] BYREF

  bfx::Mover3DImpl::CalcNextPathPos(this: (bfx::Mover3DImpl *)v31, result: (bfx::Vec3 *)this);
  v5 = *(float *)(v4 + 144);
  v6 = *(float *)(v4 + 140);
  v7 = *(_DWORD *)(v4 + 104);
  v30[0] = *(float *)(v4 + 136);
  v30[2] = v5;
  v30[1] = v6;
  v8 = *(float *)(v7 + 48);
  memset(v32, 0, 12);
  v32[0].m_tag = bfx::MEM_BFXMOVER3D;
  v9 = __fsqrts((float)((float)((float)(v31[2] - v5) * (float)(v31[2] - v5))
                      + (float)((float)((float)(v31[0] - v30[0]) * (float)(v31[0] - v30[0]))
                              + (float)((float)(v31[1] - v6) * (float)(v31[1] - v6)))));
  v10 = *(bfx::RepulsorImpl **)(v4 + 236);
  if ( v10 != nullptr )
    bfx::Repulsor3DImpl::GetNearbyRepulsors(this: v10, nearbyRepulsors: v32, filterBasedOnBlockageFlags: true);
  v11 = (float *)bfx::Mover3DImpl::CalcCrowdAcc(
                   this: (bfx::Mover3DImpl *)v31,
                   result: (bfx::Vec3 *)this,
                   nearbyMover3D: (bfx::Array<bfx::Repulsor3DImpl *> *)v32,
                   bRepulsion: true);
  v12 = (float)(v11[2] * (float)simTime);
  v13 = (float)(v11[1] * (float)simTime);
  v14 = (float)(*v11 * (float)simTime);
  v15 = (float *)bfx::Mover3DImpl::CalcCrowdAcc(
                   this: (bfx::Mover3DImpl *)v30,
                   result: (bfx::Vec3 *)this,
                   nearbyMover3D: (bfx::Array<bfx::Repulsor3DImpl *> *)v32,
                   bRepulsion: false);
  v16 = (float)(v15[2] * (float)simTime);
  v17 = (float)(v15[1] * (float)simTime);
  v18 = (float)(*v15 * (float)simTime);
  v19 = (float *)bfx::Mover3DImpl::CalcTargetAttractionAcc(
                   this: (bfx::Mover3DImpl *)v31,
                   result: (bfx::Vec3 *)this,
                   simTime,
                   curDesiredSpeed: v8);
  v20 = *v19;
  v21 = v19[1];
  v22 = v19[2];
  if ( this->m_hoverData.m_failedToTurnEnough )
    v8 = (float)((float)__fsqrts((float)((float)(this->m_hoverData.m_vForwVel.m_z * this->m_hoverData.m_vForwVel.m_z)
                                       + (float)((float)(this->m_hoverData.m_vForwVel.m_x
                                                       * this->m_hoverData.m_vForwVel.m_x)
                                               + (float)(this->m_hoverData.m_vForwVel.m_y
                                                       * this->m_hoverData.m_vForwVel.m_y))))
               * (float)0.1);
  v23 = (float *)bfx::Mover3DImpl::CalcMaxDecel(
                   this: (bfx::Mover3DImpl *)v31,
                   result: (bfx::Vec3 *)this,
                   simTime,
                   desiredSpeed: v8);
  m_z = this->m_hoverData.m_vForwVel.m_z;
  m_y = this->m_hoverData.m_vForwVel.m_y;
  v26 = (float)((float)((float)v22 + (float)((float)v16 + (float)v12)) + (float)(v23[2] * (float)simTime));
  v27 = (float)((float)((float)v21 + (float)((float)v17 + (float)v13)) + (float)(v23[1] * (float)simTime));
  this->m_hoverData.m_vForwVel.m_x = this->m_hoverData.m_vForwVel.m_x
                                   + (float)((float)((float)((float)v18 + (float)v14) + (float)v20)
                                           + (float)(*v23 * (float)simTime));
  this->m_hoverData.m_vForwVel.m_z = (float)m_z + (float)v26;
  this->m_hoverData.m_vForwVel.m_y = (float)m_y + (float)v27;
  m_recentlyCrossedPaths = this->m_hoverData.m_recentlyCrossedPaths;
  this->m_hoverData.m_prevDistanceToGoal = v9;
  if ( m_recentlyCrossedPaths > 0.0 )
  {
    v29 = (float)((float)m_recentlyCrossedPaths - (float)simTime);
    this->m_hoverData.m_recentlyCrossedPaths = v29;
    if ( v29 <= 0.0 )
      this->m_hoverData.m_recentlyCrossedPaths = 0.0;
  }
  this->m_hoverData.m_debug.m_vRepulsion.m_x = v14;
  this->m_hoverData.m_debug.m_vRepulsion.m_y = v13;
  this->m_hoverData.m_debug.m_vRepulsion.m_z = v12;
  this->m_hoverData.m_debug.m_vSteering.m_x = v18;
  this->m_hoverData.m_debug.m_vSteering.m_y = v17;
  this->m_hoverData.m_debug.m_vSteering.m_z = v16;
  v32[0].m_size = 0;
  if ( v32[0].m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v32[0].m_data);
}


// ========================================================================
// __unwind$89292
// EA  : 0x8326A67C
// RVA : 0x0126A67C
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void _unwind_89292()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 272 + 128));
}


// ========================================================================
// ?UpdateDecelState@Mover3DImpl@bfx@@QAAXM@Z
// EA  : 0x8326A6B0
// RVA : 0x0126A6B0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __fastcall bfx::Mover3DImpl::UpdateDecelState(bfx::Mover3DImpl *this, double simTime)
{
  bfx::RepulsorImpl *m_pRepulsor; // r3
  float *v5; // r3
  double v6; // fp29
  double v7; // fp28
  double v8; // fp27
  float *v9; // r3
  double v10; // fp26
  double v11; // fp25
  double v12; // fp24
  float *v13; // r3
  double m_z; // fp6
  double m_y; // fp4
  double v16; // fp9
  double v17; // fp8
  double v18; // fp0
  _BYTE v19[16]; // [sp+58h] [-98h] BYREF
  int v20; // [sp+68h] [-88h] BYREF
  bfx::Array<bfx::SpaceComponent *> v21[5]; // [sp+80h] [-70h] BYREF

  memset(v21, 0, 12);
  v21[0].m_tag = bfx::MEM_BFXMOVER3D;
  m_pRepulsor = (bfx::RepulsorImpl *)this->m_pRepulsor;
  if ( m_pRepulsor != nullptr )
    bfx::Repulsor3DImpl::GetNearbyRepulsors(this: m_pRepulsor, nearbyRepulsors: v21, filterBasedOnBlockageFlags: true);
  v5 = (float *)bfx::Mover3DImpl::CalcCrowdAcc(
                  this: (bfx::Mover3DImpl *)v19,
                  result: (bfx::Vec3 *)this,
                  nearbyMover3D: (bfx::Array<bfx::Repulsor3DImpl *> *)v21,
                  bRepulsion: true);
  v6 = (float)(v5[2] * (float)simTime);
  v7 = (float)(v5[1] * (float)simTime);
  v8 = (float)(*v5 * (float)simTime);
  v9 = (float *)bfx::Mover3DImpl::CalcCrowdAcc(
                  this: (bfx::Mover3DImpl *)&v20,
                  result: (bfx::Vec3 *)this,
                  nearbyMover3D: (bfx::Array<bfx::Repulsor3DImpl *> *)v21,
                  bRepulsion: false);
  v10 = (float)(v9[2] * (float)simTime);
  v11 = (float)(v9[1] * (float)simTime);
  v12 = (float)(*v9 * (float)simTime);
  v13 = (float *)bfx::Mover3DImpl::CalcMaxDecel(
                   this: (bfx::Mover3DImpl *)v19,
                   result: (bfx::Vec3 *)this,
                   simTime,
                   desiredSpeed: 0.0);
  m_z = this->m_hoverData.m_vForwVel.m_z;
  m_y = this->m_hoverData.m_vForwVel.m_y;
  v16 = (float)((float)((float)v10 + (float)v6) + (float)(v13[2] * (float)simTime));
  v17 = (float)((float)((float)v11 + (float)v7) + (float)(v13[1] * (float)simTime));
  this->m_hoverData.m_vForwVel.m_x = this->m_hoverData.m_vForwVel.m_x
                                   + (float)((float)((float)v12 + (float)v8) + (float)((float)simTime * *v13));
  this->m_hoverData.m_vForwVel.m_z = (float)v16 + (float)m_z;
  this->m_hoverData.m_vForwVel.m_y = (float)v17 + (float)m_y;
  if ( this->m_hoverData.m_recentlyCrossedPaths > 0.0 )
  {
    v18 = (float)(this->m_hoverData.m_recentlyCrossedPaths - (float)simTime);
    this->m_hoverData.m_recentlyCrossedPaths = this->m_hoverData.m_recentlyCrossedPaths - (float)simTime;
    if ( v18 <= 0.0 )
      this->m_hoverData.m_recentlyCrossedPaths = 0.0;
  }
  this->m_hoverData.m_debug.m_vRepulsion.m_x = v8;
  this->m_hoverData.m_debug.m_vRepulsion.m_y = v7;
  this->m_hoverData.m_debug.m_vRepulsion.m_z = v6;
  this->m_hoverData.m_debug.m_vSteering.m_x = v12;
  this->m_hoverData.m_debug.m_vSteering.m_y = v11;
  this->m_hoverData.m_debug.m_vSteering.m_z = v10;
  v21[0].m_size = 0;
  if ( v21[0].m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v21[0].m_data);
}


// ========================================================================
// __unwind$89524
// EA  : 0x8326A850
// RVA : 0x0126A850
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void _unwind_89524()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 240 + 128));
}


// ========================================================================
// ?UpdateState@Mover3DImpl@bfx@@UAAXM@Z
// EA  : 0x8326A878
// RVA : 0x0126A878
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __fastcall bfx::Mover3DImpl::UpdateState(bfx::Mover3DImpl *this, double simTime)
{
  bfx::MSurfer3D *p_m_surfer; // r28
  const bfx::Volume *Volume; // r30
  bool m_valid; // r29
  bfx::Path3D *m_pPath; // r11
  const bfx::Volume *v8; // r3
  bfx::Repulsor3DImpl *m_pRepulsor; // r3
  float m_y; // r10
  float m_z; // r9
  bfx::Repulsor3DImpl *v12; // r11
  const bfx::Vec3 *v13; // r4
  char v14; // r11
  double v15; // fp7
  double v16; // fp6
  char v17; // r11
  double Scale; // fp2
  bfx::Path3D *v19; // r11
  float v20; // r10
  float v21; // r9
  float *PathPos; // r3
  int v23; // r5
  bfx::Orienter3DTune *p_m_orienter; // r6
  bfx::Mover3DImpl::HoverData *p_m_hoverData; // r5
  double v26; // fp7
  double v27; // fp6
  bfx::Mover3DImpl::HoverData *v28; // r30
  double v29; // fp13
  double v30; // fp12
  double v31; // fp11
  double v32; // fp13
  double v35; // fp9
  bfx::Repulsor3DImpl *v36; // r3
  float v37; // r10
  float v38; // r9
  bfx::Repulsor3DImpl *v39; // r11
  bfx::Mover3DImpl::State m_state; // r11
  float v41; // r10
  bfx::Path3D::Cursor *p_m_curPathCC; // r29
  float v43; // r9
  double v44; // fp11
  double v45; // fp12
  double v46; // fp0
  double v47; // fp13
  double v48; // fp0
  double v49; // fp12
  double v50; // fp13
  double v51; // fp11
  BOOL m_stopAtGoal; // r11
  float m_x; // [sp+50h] [-80h] BYREF
  float v54; // [sp+54h] [-7Ch]
  float v55; // [sp+58h] [-78h]
  bfx::Vec3 v56; // [sp+60h] [-70h] BYREF
  bfx::Vec3 v57; // [sp+70h] [-60h] BYREF
  float v58[2]; // [sp+80h] [-50h] BYREF
  float v59; // [sp+88h] [-48h]

  p_m_surfer = &this->m_surfer;
  Volume = bfx::Surfer3D::GetVolume(this: &this->m_surfer);
  m_valid = false;
  if ( Volume == nullptr )
  {
    m_pPath = this->m_pPath;
    if ( m_pPath != nullptr )
      m_valid = m_pPath->m_valid;
  }
  if ( (unsigned __int8)bfx::Mover3DImpl::ReattachSurfer3D(this) == 0 )
    return;
  if ( m_valid )
  {
    v8 = bfx::Surfer3D::GetVolume(this: p_m_surfer);
    bfx::Mover3DImpl::RegeneratePath(this, pOldVolume: Volume, pNewVolume: v8);
  }
  if ( bfx::Surfer3D::GetVolume(this: p_m_surfer) == nullptr )
    return;
  if ( this->m_frozen )
  {
    m_pRepulsor = this->m_pRepulsor;
    if ( m_pRepulsor != nullptr )
    {
      m_y = this->m_surfer.m_pos.m_y;
      m_z = this->m_surfer.m_pos.m_z;
      v56.m_x = this->m_surfer.m_pos.m_x;
      v56.m_y = m_y;
      v56.m_z = m_z;
      bfx::Repulsor3DImpl::SetPos(this: m_pRepulsor, pos: &v56);
      v12 = this->m_pRepulsor;
      v12->m_vel.m_x = this->m_hoverData.m_vForwVel.m_x;
      v12->m_vel.m_y = this->m_hoverData.m_vForwVel.m_y;
      v12->m_vel.m_z = this->m_hoverData.m_vForwVel.m_z;
    }
    return;
  }
  bfx::Mover3DImpl::BaseSimulate(this, simTime);
  if ( this->m_hoverData.m_vOrientationKeeping.m_x != 0.0
    || this->m_hoverData.m_vOrientationKeeping.m_y != 0.0
    || (v14 = 1, this->m_hoverData.m_vOrientationKeeping.m_z != 0.0) )
  {
    v14 = 0;
  }
  if ( v14 == 0 )
  {
    v15 = (float)(this->m_hoverData.m_vOrientationKeeping.m_y + this->m_hoverData.m_vForwVel.m_y);
    v16 = (float)(this->m_hoverData.m_vOrientationKeeping.m_z + this->m_hoverData.m_vForwVel.m_z);
    this->m_hoverData.m_vForwVel.m_x = this->m_hoverData.m_vForwVel.m_x + this->m_hoverData.m_vOrientationKeeping.m_x;
    this->m_hoverData.m_vForwVel.m_y = v15;
    this->m_hoverData.m_vForwVel.m_z = v16;
  }
  if ( this->m_state != IDLE || (v17 = 1, this->m_hoverData.m_idleStateData.m_circlingDir == 0.0) )
    v17 = 0;
  if ( v17 != 0 )
    Scale = 0.0;
  else
    Scale = bfx::GetScale();
  if ( this->m_state != INITIAL_ROTATION || this->m_pTune->m_orienter.m_turnMode != 1 )
  {
    p_m_hoverData = &this->m_hoverData;
    p_m_orienter = &this->m_pTune->m_orienter;
    goto LABEL_29;
  }
  v19 = this->m_pPath;
  if ( v19 != nullptr && v19->m_valid )
  {
    v20 = this->m_surfer.m_pos.m_y;
    v21 = this->m_surfer.m_pos.m_z;
    m_x = this->m_surfer.m_pos.m_x;
    v54 = v20;
    v55 = v21;
    PathPos = (float *)bfx::Mover3DImpl::CalcNextPathPos(this: (bfx::Mover3DImpl *)v58, result: (bfx::Vec3 *)this);
    p_m_orienter = (bfx::Orienter3DTune *)(v23 + 60);
    p_m_hoverData = (bfx::Mover3DImpl::HoverData *)&m_x;
    v26 = (float)(PathPos[1] - v54);
    v27 = (float)(PathPos[2] - v55);
    m_x = *PathPos - m_x;
    v54 = v26;
    v55 = v27;
LABEL_29:
    bfx::Orienter3D::Simulate(
      this: &this->m_orienter,
      simTime,
      forwVel: v13,
      tune: (const bfx::Orienter3DTune *)p_m_hoverData,
      minVelToChangeHeading: Scale,
      a6: (int)p_m_orienter);
  }
  v28 = &this->m_hoverData;
  v29 = this->m_orienter.m_curRot.m_x;
  v30 = this->m_orienter.m_curRot.m_y;
  v31 = this->m_orienter.m_curRot.m_z;
  this->m_rot.m_w = this->m_orienter.m_curRot.m_w;
  this->m_rot.m_x = v29;
  this->m_rot.m_y = v30;
  this->m_rot.m_z = v31;
  bfx::Surfer3D::Move(this: p_m_surfer, vel: &this->m_hoverData.m_vForwVel, simTime);
  v32 = this->m_hoverData.m_vForwVel.m_x;
  if ( __fsqrts((float)((float)((float)(this->m_hoverData.m_vForwVel.m_y * this->m_hoverData.m_vForwVel.m_y)
                              + (float)(this->m_hoverData.m_vForwVel.m_z * this->m_hoverData.m_vForwVel.m_z))
                      + (float)(this->m_hoverData.m_vForwVel.m_x * this->m_hoverData.m_vForwVel.m_x))) > (float)(this->m_pTune->m_desSpeed * (float)1.5) )
  {
    _FP2 = (float)((float)__fsqrts((float)((float)((float)(this->m_hoverData.m_vForwVel.m_y
                                                         * this->m_hoverData.m_vForwVel.m_y)
                                                 + (float)(this->m_hoverData.m_vForwVel.m_z
                                                         * this->m_hoverData.m_vForwVel.m_z))
                                         + (float)(this->m_hoverData.m_vForwVel.m_x * this->m_hoverData.m_vForwVel.m_x)))
                 - 1.0842022e-19);
    __asm { fsel      f12, f2, f1, f31 }
    v35 = (float)((float)_FP12 * this->m_hoverData.m_vForwVel.m_z);
    this->m_hoverData.m_vForwVel.m_y = (float)(this->m_hoverData.m_vForwVel.m_y * (float)_FP12) * (float)1.5;
    v28->m_vForwVel.m_x = (float)((float)v32 * (float)_FP12) * (float)1.5;
    this->m_hoverData.m_vForwVel.m_z = (float)v35 * (float)1.5;
  }
  this->m_hoverData.m_vForwVelOld.m_x = v28->m_vForwVel.m_x;
  this->m_hoverData.m_vForwVelOld.m_y = this->m_hoverData.m_vForwVel.m_y;
  this->m_hoverData.m_vForwVelOld.m_z = this->m_hoverData.m_vForwVel.m_z;
  v36 = this->m_pRepulsor;
  if ( v36 != nullptr )
  {
    v37 = this->m_surfer.m_pos.m_y;
    v38 = this->m_surfer.m_pos.m_z;
    v57.m_x = this->m_surfer.m_pos.m_x;
    v57.m_y = v37;
    v57.m_z = v38;
    bfx::Repulsor3DImpl::SetPos(this: v36, pos: &v57);
    v39 = this->m_pRepulsor;
    v39->m_vel.m_x = v28->m_vForwVel.m_x;
    v39->m_vel.m_y = this->m_hoverData.m_vForwVel.m_y;
    v39->m_vel.m_z = this->m_hoverData.m_vForwVel.m_z;
  }
  m_state = this->m_state;
  if ( m_state == INITIAL_ROTATION )
  {
    if ( this->m_pTune->m_orienter.m_turnMode == 1 )
    {
      if ( this->m_orienter.m_angDiff != 0.0 )
        return;
    }
    else if ( (float)((float)(v28->m_vForwVel.m_z * v28->m_vForwVel.m_z)
                    + (float)((float)(v28->m_vForwVel.m_x * v28->m_vForwVel.m_x)
                            + (float)(v28->m_vForwVel.m_y * v28->m_vForwVel.m_y))) <= 0.0009765625 )
    {
      return;
    }
    this->m_state = GOTO_POS;
  }
  else if ( m_state == GOTO_POS )
  {
    bfx::Mover3DImpl::CalcNextPathPos(this: (bfx::Mover3DImpl *)v58, result: (bfx::Vec3 *)this);
    v41 = this->m_surfer.m_pos.m_y;
    p_m_curPathCC = &this->m_curPathCC;
    v43 = this->m_surfer.m_pos.m_z;
    m_x = this->m_surfer.m_pos.m_x;
    v44 = m_x;
    v54 = v41;
    v55 = v43;
    v45 = v59;
    v46 = v58[0];
    v47 = v58[1];
    this->m_orbitCenterPos.m_z = v59;
    this->m_orbitCenterPos.m_x = v46;
    this->m_orbitCenterPos.m_y = v47;
    v48 = (float)((float)v46 - (float)v44);
    v49 = (float)((float)v45 - v43);
    v50 = (float)((float)v47 - v54);
    v51 = __fsqrts((float)((float)(v28->m_vForwVel.m_z * v28->m_vForwVel.m_z)
                         + (float)((float)(v28->m_vForwVel.m_x * v28->m_vForwVel.m_x)
                                 + (float)(v28->m_vForwVel.m_y * v28->m_vForwVel.m_y))));
    if ( !this->m_finalApproach
      && (signed int)this->m_curPathCC.m_idx >= p_m_curPathCC->m_pPath->m_portalPoints.m_size
      && __fsqrts((float)((float)((float)v50 * (float)v50)
                        + (float)((float)((float)v48 * (float)v48) + (float)((float)v49 * (float)v49)))) <= (float)((float)((float)v51 * (float)v51) / (float)((float)(this->m_pTune->m_desSpeed / this->m_pTune->m_accTime) * (float)2.0)) )
    {
      this->m_finalApproach = true;
    }
    if ( !this->m_gotoPosSpec.m_stopAtGoal || !this->m_finalApproach )
    {
      if ( !bfx::Mover3DImpl::TestForReachedPathPoint(this) )
      {
        bfx::Mover3DImpl::RepathIfNeeded(this);
        return;
      }
      if ( (signed int)this->m_curPathCC.m_idx < p_m_curPathCC->m_pPath->m_portalPoints.m_size )
      {
        ++this->m_curPathCC.m_idx;
        return;
      }
      m_stopAtGoal = this->m_gotoPosSpec.m_stopAtGoal;
      this->m_reachedGoal = true;
      if ( !m_stopAtGoal )
      {
LABEL_38:
        bfx::Mover3DImpl::SwitchState(this, newState: IDLE);
        return;
      }
    }
    if ( this->m_state != DECEL_TO_STOP )
      this->m_state = DECEL_TO_STOP;
  }
  else if ( m_state == DECEL_TO_STOP
         && (float)((float)(v28->m_vForwVel.m_z * v28->m_vForwVel.m_z)
                  + (float)((float)(v28->m_vForwVel.m_x * v28->m_vForwVel.m_x)
                          + (float)(v28->m_vForwVel.m_y * v28->m_vForwVel.m_y))) <= 0.0009765625 )
  {
    goto LABEL_38;
  }
}


// ========================================================================
// ?GotoPos@Mover3D@bfx@@QAAXABVVector3@2@ABVGotoPosSpec3D@2@_N@Z
// EA  : 0x8326AE78
// RVA : 0x0126AE78
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __fastcall bfx::Mover3D::GotoPos(
        bfx::Mover3D *this,
        const bfx::Vector3 *goalPos,
        const bfx::GotoPosSpec3D *spec,
        bool forceUpdate)
{
  bfx::Mover3DImpl *v8; // r29
  bool v9; // zf
  bfx::Space *m_pSpace; // r25
  double m_y; // fp13
  double m_x; // fp12
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-70h]
  bfx::Vec3 v14; // [sp+58h] [-68h] BYREF
  bfx::Matrix v15; // [sp+68h] [-58h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  v9 = this != nullptr;
  v8 = (bfx::Mover3DImpl *)(this - 4);
  if ( !v9 )
    v8 = nullptr;
  m_pSpace = v8->m_pSpace;
  bfx::LogMover3DGotoPos(replayID: v8->m_replayID, goalPos, spec, forceUpdate);
  m_y = goalPos->m_y;
  m_x = goalPos->m_x;
  v14.m_z = goalPos->m_z;
  v14.m_x = m_x;
  v14.m_y = m_y;
  bfx::Matrix::operator*(this: &v15, result: (bfx::Vec3 *)&m_pSpace->m_matWorldToSpace, rhs: &v14);
  bfx::Mover3DImpl::GotoPos(this: v8, requestedGoalPos: (const bfx::Vec3 *)&v15, spec, forceUpdate);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$91107
// EA  : 0x8326AF34
// RVA : 0x0126AF34
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void _unwind_91107()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 192 + 80));
}


// ========================================================================
// ?Teleport@Mover3D@bfx@@QAAXABVVector3@2@ABVQuaternion@2@@Z
// EA  : 0x8326AF68
// RVA : 0x0126AF68
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __fastcall bfx::Mover3D::Teleport(bfx::Mover3D *this, const bfx::Vector3 *newPos, const bfx::Quaternion *newRot)
{
  bfx::Mover3DImpl *v6; // r28
  bool v7; // zf
  bfx::Space *m_pSpace; // r27
  double m_y; // fp13
  double m_x; // fp12
  double m_w; // fp11
  double v12; // fp9
  double v13; // fp8
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-90h]
  bfx::Vec3 v15; // [sp+58h] [-88h] BYREF
  bfx::Matrix v16; // [sp+68h] [-78h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  v7 = this != nullptr;
  v6 = (bfx::Mover3DImpl *)(this - 4);
  if ( !v7 )
    v6 = nullptr;
  m_pSpace = v6->m_pSpace;
  bfx::LogMover3DTeleport(replayID: v6->m_replayID, newPos, newRot);
  m_y = newRot->m_y;
  m_x = newRot->m_x;
  m_w = newRot->m_w;
  v16.m_data[9] = newRot->m_z;
  v16.m_data[8] = m_y;
  v16.m_data[6] = m_w;
  v16.m_data[7] = m_x;
  bfx::Quat::Normalize(this: (bfx::Quat *)&v16.m_data[6]);
  bfx::Quat::operator*(
    this: (bfx::Quat *)&v16.m_data[10],
    result: &m_pSpace->m_rotWorldToSpace,
    rhs: (const bfx::Quat *)&v16.m_data[6]);
  v12 = newPos->m_y;
  v13 = newPos->m_x;
  v15.m_z = newPos->m_z;
  v15.m_x = v13;
  v15.m_y = v12;
  bfx::Matrix::operator*(this: &v16, result: (bfx::Vec3 *)&m_pSpace->m_matWorldToSpace, rhs: &v15);
  bfx::Mover3DImpl::Teleport(this: v6, newPos: (const bfx::Vec3 *)&v16, newRot: (const bfx::Quat *)&v16.m_data[10]);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$91175
// EA  : 0x8326B050
// RVA : 0x0126B050
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void _unwind_91175()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 224 + 80));
}


// ========================================================================
// ?UpdateCircling@Mover3DImpl@bfx@@QAAXMABVVec3@2@M@Z
// EA  : 0x8326B080
// RVA : 0x0126B080
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __fastcall bfx::Mover3DImpl::UpdateCircling(
        bfx::Mover3DImpl *this,
        double simTime,
        const bfx::Vec3 *desiredCenter,
        double desiredRadius,
        const bfx::Vec3 *a5)
{
  double m_z; // fp0
  float m_x; // r10
  double v7; // fp9
  float v8; // r9
  double v9; // fp8
  double m_y; // fp4
  double v11; // fp10
  double v13; // fp13
  bool v15; // mr_fpscr50
  double v16; // fp12
  double v17; // fp11
  bfx::Mover3DImpl::HoverData *p_m_hoverData; // r27
  double v21; // fp14
  double v24; // fp1
  double v25; // fp2
  double v28; // fp0
  float v29; // r10
  double v30; // fp9
  float v31; // r11
  double v32; // fp8
  bfx::Vec3 *p_m_vUp; // r26
  double v34; // fp7
  double v35; // fp2
  double v36; // fp13
  double v37; // fp11
  bool v38; // r28
  double v39; // fp26
  float v40; // r10
  float v41; // r6
  double v42; // fp16
  double m_radius; // fp10
  float v44; // r4
  float v45; // r3
  float v46; // r10
  float v47; // r9
  double v48; // fp30
  float v49; // r10
  float v50; // r9
  double v51; // fp1
  float v52; // r10
  double v53; // fp19
  float v54; // r9
  double v55; // fp25
  double v56; // fp18
  double v57; // fp20
  double v58; // fp27
  float v59; // r11
  double v60; // fp23
  double v61; // fp22
  double v62; // fp24
  double v64; // fp13
  double v65; // fp12
  double v66; // fp9
  double v67; // fp8
  float v70; // r9
  float v71; // r11
  float v72; // r8
  float v73; // r7
  float v74; // r6
  double v77; // fp1
  float v78; // r9
  float v79; // r10
  double v80; // fp1
  double v81; // fp7
  double v85; // fp26
  double v86; // fp25
  double v87; // fp29
  double v90; // fp5
  float v91; // r8
  double v92; // fp4
  bfx::RepulsorImpl *m_pRepulsor; // r3
  float v94; // r10
  double v95; // fp0
  float v96; // r11
  double v97; // fp13
  double v98; // fp12
  float v99; // r9
  double v100; // fp11
  double v101; // fp10
  double v102; // fp9
  double v103; // fp31
  double v108; // fp31
  double v109; // fp30
  float *v110; // r3
  double v111; // fp10
  double v112; // fp9
  double v113; // fp6
  double v114; // fp4
  double v115; // fp3
  double v116; // fp2
  bfx::Vec3 v117; // [sp+58h] [-188h] BYREF
  bfx::Vec3 v118; // [sp+68h] [-178h] BYREF
  bfx::Orbit v119; // [sp+80h] [-160h] BYREF
  bfx::Vec3 v120; // [sp+A0h] [-140h] BYREF
  bfx::Array<bfx::SpaceComponent *> v121; // [sp+B0h] [-130h] BYREF
  int v122; // [sp+C0h] [-120h] BYREF
  float v123; // [sp+C4h] [-11Ch]
  float v124; // [sp+C8h] [-118h]
  bfx::Vec3 v125; // [sp+D0h] [-110h] BYREF
  float v126[44]; // [sp+E0h] [-100h] BYREF

  m_z = this->m_hoverData.m_vForwVel.m_z;
  m_x = this->m_surfer.m_pos.m_x;
  v7 = (float)(this->m_hoverData.m_vForwVel.m_z * this->m_hoverData.m_vForwVel.m_z);
  v8 = this->m_surfer.m_pos.m_z;
  v9 = this->m_hoverData.m_vForwVel.m_x;
  m_y = this->m_hoverData.m_vForwVel.m_y;
  v11 = (float)(this->m_hoverData.m_vForwVel.m_x * this->m_hoverData.m_vForwVel.m_x);
  v118.m_y = this->m_surfer.m_pos.m_y;
  v118.m_x = m_x;
  v118.m_z = v8;
  v13 = a5->m_y;
  v15 = this->m_hoverData.m_idleStateData.m_circlingDir == 0.0;
  v16 = a5->m_x;
  v17 = a5->m_z;
  v123 = 0.0;
  p_m_hoverData = &this->m_hoverData;
  v124 = 0.0;
  v21 = 0.0;
  _FP5 = (float)((float)__fsqrts((float)((float)((float)((float)m_y * (float)m_y) + (float)v7) + (float)v11))
               - (float)1.0842022e-19);
  __asm { fsel      f5, f5, f4, f31 }
  v24 = (float)((float)v9 * (float)_FP5);
  v25 = (float)((float)m_y * (float)_FP5);
  _FP4 = (float)((float)__fsqrts((float)((float)((float)((float)v17 - v8) * (float)((float)v17 - v8))
                                       + (float)((float)((float)((float)v16 - m_x) * (float)((float)v16 - m_x))
                                               + (float)((float)((float)v13 - v118.m_y) * (float)((float)v13 - v118.m_y)))))
               - (float)1.0842022e-19);
  __asm { fsel      f8, f4, f0, f31 }
  v28 = (float)((float)((float)v24 * (float)((float)((float)v16 - m_x) * (float)_FP8))
              + (float)((float)((float)((float)((float)v13 - v118.m_y) * (float)_FP8) * (float)v25)
                      + (float)((float)((float)((float)v17 - v8) * (float)_FP8) * (float)((float)m_z * (float)_FP5))));
  if ( !v15 || v28 <= 0.0 )
  {
    v29 = this->m_surfer.m_pos.m_z;
    v30 = this->m_hoverData.m_idleStateData.m_vUp.m_y;
    v31 = this->m_surfer.m_pos.m_x;
    v32 = this->m_hoverData.m_idleStateData.m_vUp.m_x;
    p_m_vUp = &this->m_hoverData.m_idleStateData.m_vUp;
    v34 = this->m_hoverData.m_idleStateData.m_vUp.m_z;
    v118.m_y = this->m_surfer.m_pos.m_y;
    v118.m_z = v29;
    v118.m_x = v31;
    v35 = (float)((float)v13 - v118.m_y);
    v36 = (float)((float)v17 - v29);
    v37 = (float)((float)((float)((float)v17 - v29) * (float)v34)
                + (float)((float)((float)((float)v16 - v31) * (float)v32) + (float)((float)v35 * (float)v30)));
    v38 = __fsqrts((float)((float)((float)((float)v36 - (float)((float)v34 * (float)v37))
                                 * (float)((float)v36 - (float)((float)v34 * (float)v37)))
                         + (float)((float)((float)((float)((float)v16 - v31) - (float)((float)v32 * (float)v37))
                                         * (float)((float)((float)v16 - v31) - (float)((float)v32 * (float)v37)))
                                 + (float)((float)((float)v35 - (float)((float)v30 * (float)v37))
                                         * (float)((float)v35 - (float)((float)v30 * (float)v37)))))) > (float)((float)desiredRadius + 0.0009765625);
    v39 = __fsqrts((float)((float)((float)(this->m_hoverData.m_vForwVel.m_y * this->m_hoverData.m_vForwVel.m_y)
                                 + (float)(this->m_hoverData.m_vForwVel.m_z * this->m_hoverData.m_vForwVel.m_z))
                         + (float)v11));
    bfx::Mover3DImpl::GetTangential(this: (bfx::Mover3DImpl *)&v117, result: (bfx::Vec3 *)this, desCenter: a5);
    v40 = this->m_surfer.m_pos.m_y;
    v41 = this->m_surfer.m_pos.m_z;
    v120.m_x = this->m_surfer.m_pos.m_x;
    v120.m_y = v40;
    v120.m_z = v41;
    v42 = (float)(this->m_pTune->m_desSpeed / this->m_pTune->m_accTime);
    bfx::Mover3DImpl::GetSmallestOrbit(
      this: (bfx::Mover3DImpl *)v126,
      result: (bfx::Orbit *)this,
      vel: &p_m_hoverData->m_vForwVel,
      maxAcc: v42,
      myPos: (const bfx::Vec3 *)LODWORD(v41),
      vTanj: &v120,
      vUp: &v117,
      a8: &this->m_hoverData.m_idleStateData.m_vUp.m_x);
    m_radius = desiredRadius;
    v119.m_rotationAxis.m_x = p_m_vUp->m_x;
    v119.m_radius = desiredRadius;
    v44 = a5->m_y;
    v45 = a5->m_z;
    v46 = this->m_hoverData.m_idleStateData.m_vUp.m_y;
    v47 = this->m_hoverData.m_idleStateData.m_vUp.m_z;
    v119.m_center.m_x = a5->m_x;
    v119.m_center.m_y = v44;
    v119.m_center.m_z = v45;
    v119.m_rotationAxis.m_y = v46;
    v119.m_rotationAxis.m_z = v47;
    if ( v38 )
    {
      v48 = v126[3];
    }
    else
    {
      v49 = this->m_surfer.m_pos.m_y;
      v50 = this->m_surfer.m_pos.m_z;
      v120.m_x = this->m_surfer.m_pos.m_x;
      v120.m_y = v49;
      v120.m_z = v50;
      v51 = bfx::CalcBestFitRadius(moverPos: &v120, vTanj: &v117, desOrbit: &v119);
      m_radius = v119.m_radius;
      v48 = v51;
    }
    v52 = this->m_surfer.m_pos.m_z;
    v53 = v117.m_z;
    v54 = this->m_surfer.m_pos.m_x;
    v55 = v117.m_x;
    this->m_hoverData.m_idleStateData.m_bestFitRadius = v48;
    v56 = v117.m_y;
    v57 = (float)((float)v55 * (float)v48);
    v58 = (float)(v117.m_y * (float)v48);
    v59 = this->m_surfer.m_pos.m_y;
    v117.m_z = v52;
    v117.m_x = v54;
    v60 = this->m_hoverData.m_idleStateData.m_vUp.m_y;
    v117.m_y = v59;
    v61 = this->m_hoverData.m_idleStateData.m_vUp.m_z;
    v62 = p_m_vUp->m_x;
    if ( !this->m_hoverData.m_debug.m_enable )
      this->m_hoverData.m_debug.m_enable = true;
    this->m_hoverData.m_debug.m_myOrbit.m_center.m_x = (float)((float)v55 * (float)v48) + v54;
    this->m_hoverData.m_debug.m_myOrbit.m_center.m_y = v59 + (float)v58;
    this->m_hoverData.m_debug.m_myOrbit.m_center.m_z = v52 + (float)((float)v53 * (float)v48);
    this->m_hoverData.m_debug.m_myOrbit.m_radius = v48;
    this->m_hoverData.m_debug.m_myOrbit.m_rotationAxis.m_x = v62;
    this->m_hoverData.m_debug.m_myOrbit.m_rotationAxis.m_y = v60;
    _FP29 = 0.0;
    this->m_hoverData.m_debug.m_myOrbit.m_rotationAxis.m_z = v61;
    v64 = v119.m_center.m_y;
    v65 = v119.m_center.m_z;
    this->m_hoverData.m_debug.m_desiredOrbit.m_center.m_x = v119.m_center.m_x;
    this->m_hoverData.m_debug.m_desiredOrbit.m_center.m_y = v64;
    this->m_hoverData.m_debug.m_desiredOrbit.m_center.m_z = v65;
    this->m_hoverData.m_debug.m_desiredOrbit.m_radius = m_radius;
    v66 = v119.m_rotationAxis.m_y;
    v67 = v119.m_rotationAxis.m_z;
    this->m_hoverData.m_debug.m_desiredOrbit.m_rotationAxis.m_x = v119.m_rotationAxis.m_x;
    this->m_hoverData.m_debug.m_desiredOrbit.m_rotationAxis.m_y = v66;
    this->m_hoverData.m_debug.m_desiredOrbit.m_rotationAxis.m_z = v67;
    _FP4 = (float)((float)v39 - (float)(this->m_pTune->m_idleTune.m_idleSpeedScale * this->m_pTune->m_desSpeed));
    __asm { fsel      f15, f4, f5, f26 }
    if ( !v38 )
      goto LABEL_12;
    v70 = p_m_hoverData->m_vForwVel.m_z;
    v71 = p_m_hoverData->m_vForwVel.m_y;
    v72 = this->m_surfer.m_pos.m_x;
    v73 = this->m_surfer.m_pos.m_y;
    v118.m_x = p_m_hoverData->m_vForwVel.m_x;
    v118.m_z = v70;
    v118.m_y = v71;
    v74 = this->m_surfer.m_pos.m_z;
    v125.m_x = v72;
    v125.m_y = v73;
    v125.m_z = v74;
    _FP6 = (float)((float)__fsqrts((float)((float)(v70 * v70)
                                         + (float)((float)(v118.m_x * v118.m_x) + (float)(v118.m_y * v118.m_y))))
                 - (float)1.0842022e-19);
    __asm { fsel      f4, f6, f5, f31 }
    v118.m_y = v71 * (float)_FP4;
    v118.m_x = v118.m_x * (float)_FP4;
    v118.m_z = v70 * (float)_FP4;
    v77 = bfx::CollideLineAndSphere(
            lineStart: &v125,
            normalizedLineDir: &v118,
            spherePos: &v119.m_center,
            radius: m_radius);
    if ( v77 == 3.4028235e38
      || v77 < 0.0
      || (v78 = this->m_surfer.m_pos.m_z,
          v79 = this->m_surfer.m_pos.m_x,
          v117.m_y = this->m_surfer.m_pos.m_y,
          v117.m_z = v78,
          v117.m_x = v79,
          v81 = (float)((float)((float)((float)((float)(v118.m_x * (float)v77) + v79) - v119.m_center.m_x)
                              * (float)((float)((float)(v118.m_x * (float)v77) + v79) - v119.m_center.m_x))
                      + (float)((float)((float)(v117.m_y + (float)(v118.m_y * (float)v77)) - v119.m_center.m_y)
                              * (float)((float)(v117.m_y + (float)(v118.m_y * (float)v77)) - v119.m_center.m_y))),
          v80 = (float)((float)(v78 + (float)(v118.m_z * (float)v77)) - v119.m_center.m_z),
          __fabs((float)((float)__fsqrts((float)((float)((float)v80 * (float)v80) + (float)v81)) - v119.m_radius)) > 0.0009765625) )
    {
LABEL_12:
      if ( v48 != 0.0 )
      {
        _FP11 = (float)((float)-v42 - (float)((float)((float)v39 / (float)v48) * (float)v39));
        _FP10 = (float)((float)v42 - (float)((float)((float)v39 / (float)v48) * (float)v39));
        __asm { fsel      f9, f11, f13, f12 }
        __asm { fsel      f29, f10, f8, f16 }
      }
      v85 = (float)((float)v55 * (float)_FP29);
      this->m_hoverData.m_debug.m_vCirclingTangential.m_x = (float)v55 * (float)_FP29;
      v86 = (float)((float)v53 * (float)_FP29);
      this->m_hoverData.m_debug.m_vCirclingTangential.m_z = (float)v53 * (float)_FP29;
      v87 = (float)((float)v56 * (float)_FP29);
      this->m_hoverData.m_debug.m_vCirclingTangential.m_y = v87;
      memset(&v121, 0, 12);
      _FP5 = (float)((float)__fsqrts((float)((float)((float)v86 * (float)v86)
                                           + (float)((float)((float)v85 * (float)v85) + (float)((float)v87 * (float)v87))))
                   - (float)1.0842022e-19);
      __asm { fsel      f3, f5, f4, f31 }
      this->m_hoverData.m_debug.m_vCirclingTangential.m_x = (float)_FP3 * (float)v85;
      this->m_hoverData.m_debug.m_vCirclingTangential.m_z = (float)_FP3 * (float)v86;
      this->m_hoverData.m_debug.m_vCirclingTangential.m_y = (float)_FP3 * (float)v87;
      this->m_hoverData.m_debug.m_vCirclingTangential.m_x = (float)((float)_FP3 * (float)v85) * (float)2.0;
      this->m_hoverData.m_debug.m_vCirclingTangential.m_z = (float)((float)_FP3 * (float)v86) * (float)2.0;
      this->m_hoverData.m_debug.m_vCirclingTangential.m_y = (float)((float)_FP3 * (float)v87) * (float)2.0;
      v117.m_y = this->m_surfer.m_pos.m_y;
      v90 = v117.m_y;
      v117.m_x = this->m_surfer.m_pos.m_x;
      v91 = this->m_surfer.m_pos.m_z;
      v92 = (float)((float)v57 + v117.m_x);
      this->m_hoverData.m_debug.m_myOrbit.m_radius = v48;
      this->m_hoverData.m_debug.m_myOrbit.m_center.m_x = v92;
      this->m_hoverData.m_debug.m_myOrbit.m_center.m_y = (float)v90 + (float)v58;
      v117.m_z = v91;
      this->m_hoverData.m_debug.m_myOrbit.m_center.m_z = v91 + (float)((float)v53 * (float)v48);
      this->m_hoverData.m_debug.m_myOrbit.m_rotationAxis.m_x = v62;
      this->m_hoverData.m_debug.m_myOrbit.m_rotationAxis.m_y = v60;
      this->m_hoverData.m_debug.m_myOrbit.m_rotationAxis.m_z = v61;
      v121.m_tag = bfx::MEM_BFXMOVER3D;
      m_pRepulsor = (bfx::RepulsorImpl *)this->m_pRepulsor;
      if ( m_pRepulsor != nullptr )
        bfx::Repulsor3DImpl::GetNearbyRepulsors(
          this: m_pRepulsor,
          nearbyRepulsors: &v121,
          filterBasedOnBlockageFlags: true);
      bfx::Mover3DImpl::AdjustOrbitforCrowd(this, nearbyMover3D: (bfx::Array<bfx::Repulsor3DImpl *> *)&v121);
      v121.m_size = 0;
      if ( v121.m_data != nullptr )
      {
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v121.m_data);
        v121.m_data = nullptr;
      }
      v94 = this->m_surfer.m_pos.m_x;
      v95 = this->m_hoverData.m_idleStateData.m_center.m_x;
      v96 = this->m_surfer.m_pos.m_z;
      v97 = this->m_hoverData.m_idleStateData.m_center.m_z;
      v98 = p_m_vUp->m_x;
      v121.m_cap = 0;
      v99 = this->m_surfer.m_pos.m_y;
      v100 = this->m_hoverData.m_idleStateData.m_center.m_y;
      v101 = this->m_hoverData.m_idleStateData.m_vUp.m_z;
      v117.m_x = v94;
      v102 = this->m_hoverData.m_idleStateData.m_vUp.m_y;
      v117.m_z = v96;
      v117.m_y = v99;
      v103 = (float)((float)((float)((float)v100 - v99) * (float)v102)
                   + (float)((float)((float)v101 * (float)((float)v97 - v96))
                           + (float)((float)v98 * (float)((float)v95 - v94))));
      if ( __fabs(v103) <= (float)(bfx::GetScale() * (float)0.1) )
      {
        bfx::Mover3DImpl::KeepEvenKeel(this, vDesiredUp: &this->m_hoverData.m_idleStateData.m_vUp);
        v109 = v124;
        v108 = v123;
      }
      else
      {
        _FP9 = (float)((float)-0.5 - (float)v103);
        _FP8 = (float)((float)0.5 - (float)v103);
        __asm { fsel      f7, f9, f13, f31 }
        __asm { fsel      f5, f8, f6, f0 }
        v21 = (float)(p_m_vUp->m_x * (float)_FP5);
        v108 = (float)(this->m_hoverData.m_idleStateData.m_vUp.m_y * (float)_FP5);
        v109 = (float)(this->m_hoverData.m_idleStateData.m_vUp.m_z * (float)_FP5);
      }
      v110 = (float *)bfx::Mover3DImpl::CalcMaxDecel(
                        this: (bfx::Mover3DImpl *)&v122,
                        result: (bfx::Vec3 *)this,
                        simTime,
                        desiredSpeed: _FP15);
      v111 = p_m_hoverData->m_vForwVel.m_y;
      v112 = p_m_hoverData->m_vForwVel.m_z;
      v113 = (float)(*v110 * (float)simTime);
      v114 = (float)(v110[1] * (float)simTime);
      v115 = (float)(v110[2] * (float)simTime);
      v116 = (float)(p_m_hoverData->m_vForwVel.m_x + (float)((float)v85 * (float)simTime));
      p_m_hoverData->m_vForwVel.m_x = p_m_hoverData->m_vForwVel.m_x + (float)((float)v85 * (float)simTime);
      p_m_hoverData->m_vForwVel.m_y = (float)v111 + (float)((float)v87 * (float)simTime);
      p_m_hoverData->m_vForwVel.m_z = (float)((float)v86 * (float)simTime) + (float)v112;
      p_m_hoverData->m_vForwVel.m_x = (float)v116 + (float)v21;
      p_m_hoverData->m_vForwVel.m_y = (float)((float)v111 + (float)((float)v87 * (float)simTime)) + (float)v108;
      p_m_hoverData->m_vForwVel.m_z = (float)v109 + (float)((float)((float)v86 * (float)simTime) + (float)v112);
      p_m_hoverData->m_vForwVel.m_x = (float)((float)v116 + (float)v21) + (float)v113;
      p_m_hoverData->m_vForwVel.m_y = (float)((float)((float)v111 + (float)((float)v87 * (float)simTime)) + (float)v108)
                                    + (float)v114;
      p_m_hoverData->m_vForwVel.m_z = (float)v115
                                    + (float)((float)v109 + (float)((float)((float)v86 * (float)simTime) + (float)v112));
    }
  }
}


// ========================================================================
// __unwind$91298
// EA  : 0x8326B840
// RVA : 0x0126B840
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void _unwind_91298()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 480 + 176));
}


// ========================================================================
// ?UpdateIdleState@Mover3DImpl@bfx@@QAAXM@Z
// EA  : 0x8326B868
// RVA : 0x0126B868
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __fastcall bfx::Mover3DImpl::UpdateIdleState(bfx::Mover3DImpl *this, double simTime, const bfx::Vec3 *a3)
{
  float m_y; // r8
  float m_z; // r10
  double m_x; // fp13
  double Scale; // fp1
  double v9; // fp13
  double v10; // fp11
  double v11; // fp9
  double v12; // fp0
  bfx::Vec3 v13; // [sp+50h] [-30h] BYREF

  this->m_hoverData.m_debug.m_vCirclingCenter.m_x = 0.0;
  this->m_hoverData.m_debug.m_vCirclingCenter.m_y = 0.0;
  this->m_hoverData.m_debug.m_vCirclingCenter.m_z = 0.0;
  this->m_hoverData.m_debug.m_vCirclingTangential.m_x = 0.0;
  this->m_hoverData.m_debug.m_vCirclingTangential.m_y = 0.0;
  this->m_hoverData.m_debug.m_vCirclingTangential.m_z = 0.0;
  if ( this->m_pTune->m_idleTune.m_circleWhileIdle )
  {
    m_y = this->m_hoverData.m_idleStateData.m_center.m_y;
    m_z = this->m_hoverData.m_idleStateData.m_center.m_z;
    v13.m_x = this->m_hoverData.m_idleStateData.m_center.m_x;
    m_x = v13.m_x;
    v13.m_y = m_y;
    v13.m_z = m_z;
    this->m_hoverData.m_debug.m_vCirclingCenter.m_z = m_z;
    this->m_hoverData.m_debug.m_vCirclingCenter.m_y = m_y;
    this->m_hoverData.m_debug.m_vCirclingCenter.m_x = m_x;
    bfx::Mover3DImpl::UpdateCircling(
      this,
      simTime,
      desiredCenter: a3,
      desiredRadius: this->m_hoverData.m_idleStateData.m_maxRadius,
      a5: &v13);
  }
  else
  {
    Scale = bfx::GetScale();
    v9 = this->m_hoverData.m_vForwVel.m_x;
    v10 = this->m_hoverData.m_vForwVel.m_z;
    v11 = (float)(this->m_hoverData.m_vForwVel.m_y * (float)0.5);
    this->m_hoverData.m_vForwVel.m_y = this->m_hoverData.m_vForwVel.m_y * (float)0.5;
    this->m_hoverData.m_vForwVel.m_x = (float)v9 * (float)0.5;
    this->m_hoverData.m_vForwVel.m_z = (float)v10 * (float)0.5;
    if ( (float)((float)((float)((float)v10 * (float)0.5) * (float)((float)v10 * (float)0.5))
               + (float)((float)((float)((float)v9 * (float)0.5) * (float)((float)v9 * (float)0.5))
                       + (float)((float)v11 * (float)v11))) < (double)(float)((float)((float)Scale * (float)0.1)
                                                                            * (float)((float)Scale * (float)0.1)) )
    {
      this->m_hoverData.m_vForwVel.m_x = 0.0;
      this->m_hoverData.m_vForwVel.m_y = 0.0;
      this->m_hoverData.m_vForwVel.m_z = 0.0;
    }
  }
  if ( this->m_hoverData.m_recentlyCrossedPaths > 0.0 )
  {
    v12 = (float)(this->m_hoverData.m_recentlyCrossedPaths - (float)simTime);
    this->m_hoverData.m_recentlyCrossedPaths = this->m_hoverData.m_recentlyCrossedPaths - (float)simTime;
    if ( v12 <= 0.0 )
      this->m_hoverData.m_recentlyCrossedPaths = 0.0;
  }
}


// ========================================================================
// ?CalcAcc@Mover3DImpl@bfx@@UAAXM@Z
// EA  : 0x8326B9A8
// RVA : 0x0126B9A8
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __fastcall bfx::Mover3DImpl::CalcAcc(bfx::Mover3DImpl *this, double simTime, const bfx::Vec3 *a3)
{
  bfx::Mover3DImpl::State m_state; // r11
  float m_x; // [sp+50h] [-20h]
  float m_y; // [sp+54h] [-1Ch]

  if ( !this->m_frozen && this->m_pPath != nullptr )
  {
    this->m_hoverData.m_vOrientationKeeping.m_x = 0.0;
    this->m_hoverData.m_vOrientationKeeping.m_y = 0.0;
    this->m_hoverData.m_vOrientationKeeping.m_z = 0.0;
    this->m_hoverData.m_failedToTurnEnough = false;
    this->m_hoverData.m_debug.m_vRepulsion.m_x = 0.0;
    this->m_hoverData.m_debug.m_vRepulsion.m_y = 0.0;
    this->m_hoverData.m_debug.m_vRepulsion.m_z = 0.0;
    this->m_hoverData.m_debug.m_vSteering.m_x = 0.0;
    this->m_hoverData.m_debug.m_vSteering.m_y = 0.0;
    this->m_hoverData.m_debug.m_vSteering.m_z = 0.0;
    this->m_hoverData.m_debug.m_vTargetAttraction.m_x = 0.0;
    this->m_hoverData.m_debug.m_vTargetAttraction.m_y = 0.0;
    this->m_hoverData.m_debug.m_vTargetAttraction.m_z = 0.0;
    this->m_hoverData.m_debug.m_vBraking.m_x = 0.0;
    this->m_hoverData.m_debug.m_vBraking.m_y = 0.0;
    this->m_hoverData.m_debug.m_vBraking.m_z = 0.0;
    this->m_hoverData.m_debug.m_vCollisionPos.m_x = 0.0;
    this->m_hoverData.m_debug.m_vCollisionPos.m_y = 0.0;
    this->m_hoverData.m_debug.m_vCollisionPos.m_z = 0.0;
    if ( this->m_hoverData.m_debug.m_enable )
      this->m_hoverData.m_debug.m_enable = false;
    m_x = this->m_surfer.m_pos.m_x;
    m_y = this->m_surfer.m_pos.m_y;
    this->m_hoverData.m_debug.m_vMyPos.m_z = this->m_surfer.m_pos.m_z;
    this->m_hoverData.m_debug.m_vMyPos.m_y = m_y;
    this->m_hoverData.m_debug.m_vMyPos.m_x = m_x;
    m_state = this->m_state;
    if ( (unsigned int)m_state <= DECEL_TO_STOP )
    {
      if ( m_state == INITIAL_ROTATION )
      {
        bfx::Mover3DImpl::UpdateInitialRotationState(this, simTime);
      }
      else if ( m_state == GOTO_POS )
      {
        bfx::Mover3DImpl::UpdateGotoPosState(this, simTime);
      }
      else if ( m_state != IDLE )
      {
        bfx::Mover3DImpl::UpdateDecelState(this, simTime);
      }
      else
      {
        bfx::Mover3DImpl::UpdateIdleState(this, simTime, a3);
      }
    }
  }
}


// ========================================================================
// ??0Mover3DImpl@bfx@@QAA@PAVSpace@1@ABVVec3@1@ABVQuat@1@PBUMover3DTune@1@I@Z
// EA  : 0x8326BB38
// RVA : 0x0126BB38
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

bfx::Mover3DImpl *__fastcall bfx::Mover3DImpl::Mover3DImpl(
        bfx::Mover3DImpl *this,
        bfx::Space *pSpace,
        const bfx::Vec3 *pos,
        bfx::Quat *rot,
        const bfx::Mover3DTune *pTune,
        unsigned int replayID)
{
  bfx::Mover3DTune *p_m_tune; // r25
  double m_w; // fp13
  double m_x; // fp12
  double m_y; // fp11
  double m_z; // fp10
  __int64 v17; // r10
  __int64 v18; // r8
  __int64 v19; // r6
  __int64 v20; // r4
  const bfx::Volume *v21; // r22
  double v22; // fp0
  double v23; // fp13
  double v24; // fp12
  bfx::Vec3 *ClosestPos; // r3
  double v26; // fp0
  double v27; // fp13
  double v28; // fp12
  int v30; // [sp+8h] [-D8h]
  int v31; // [sp+Ch] [-D4h]
  int v32; // [sp+10h] [-D0h]
  int v33; // [sp+14h] [-CCh]
  bfx::Path3DSpec v34; // [sp+50h] [-90h] BYREF
  void *p_m_orbitCenterPos; // [sp+54h] [-8Ch]
  bfx::Vec3 v36; // [sp+58h] [-88h] BYREF
  bfx::Volume v37[2]; // [sp+68h] [-78h] BYREF

  this->m_pSpace = pSpace;
  this->m_stranded = false;
  p_m_tune = &this->m_tune;
  this->__vftable = (bfx::Mover3DImpl_vtbl *)&bfx::Mover3DImpl::`vftable';
  memcpy(Dst: &this->m_tune, Src: pTune, Size: sizeof(this->m_tune));
  this->m_pTune = p_m_tune;
  v34.m_customGeoMatchFlags = (unsigned int)&this->m_surfer;
  this->m_debugColor = ColorWhite_7;
  this->m_debug = false;
  this->m_frozen = false;
  bfx::Surfer3D::Surfer3D(this: &this->m_surfer, pSpace);
  this->m_surfer.m_pMover = nullptr;
  this->m_surfer.__vftable = (bfx::MSurfer3D_vtbl *)&bfx::MSurfer3D::`vftable';
  m_w = rot->m_w;
  m_x = rot->m_x;
  m_y = rot->m_y;
  m_z = rot->m_z;
  this->m_orienter.m_timeSpentRolled = 0.0;
  this->m_orienter.m_angDiff = 0.0;
  this->m_orienter.m_curRot.m_w = m_w;
  this->m_orienter.m_curRot.m_x = m_x;
  this->m_orienter.m_curRot.m_y = m_y;
  this->m_orienter.m_curRot.m_z = m_z;
  this->m_orienter.m_angularVel.m_x = 0.0;
  this->m_orienter.m_angularVel.m_y = 0.0;
  this->m_orienter.m_angularVel.m_z = 0.0;
  p_m_orbitCenterPos = &this->m_orbitCenterPos;
  this->m_orienter.m_rollAngularVel.m_x = 0.0;
  this->m_orienter.m_rollAngularVel.m_y = 0.0;
  this->m_orienter.m_rollAngularVel.m_z = 0.0;
  this->m_pRepulsor = nullptr;
  this->m_pPath = nullptr;
  this->m_curPathCC.m_pPath = nullptr;
  this->m_curPathCC.m_idx = 0;
  this->m_refinementCountdownTimer = 0.0;
  this->m_gotoPosSpec.m_stopAtGoal = true;
  this->m_reachedGoal = false;
  this->m_finalApproach = false;
  this->m_orbitCenterPos.m_x = 0.0;
  this->m_orbitCenterPos.m_y = 0.0;
  this->m_orbitCenterPos.m_z = 0.0;
  bfx::Mover3DImpl::HoverData::HoverData(this: &this->m_hoverData, pSpace);
  this->m_steeringPriority = replayID;
  this->m_replayID = replayID;
  HIDWORD(v20) = bfx::GetPlanner3D(pSpace: this->m_pSpace);
  v21 = nullptr;
  if ( HIDWORD(v20) != 0
    && (v34.m_customGeoMatchFlags = pTune->m_customGeoMatchFlags,
        HIDWORD(v20) = bfx::Planner3D::GetClosestVolume(this: (bfx::Planner3D *)HIDWORD(v20), pos, pathSpec: &v34),
        v21 = (const bfx::Volume *)HIDWORD(v20),
        HIDWORD(v20) != 0) )
  {
    ClosestPos = bfx::Volume::GetClosestPos(this: v37, result: (bfx::Vec3 *)HIDWORD(v20), pos);
    v36.m_x = ClosestPos->m_x;
    v36.m_y = ClosestPos->m_y;
    v24 = ClosestPos->m_z;
  }
  else
  {
    HIDWORD(v20) = "Mover3D created before any volumetric NavGraphs usable by the mover were loaded\n";
    bfx::InternalWarning(fmt: v20, a2: v19, a3: v18, a4: v17, a5: v30, a6: v31, a7: v32, a8: v33);
    v22 = pos->m_x;
    v23 = pos->m_y;
    v24 = pos->m_z;
    this->m_stranded = true;
    v36.m_x = v22;
    v36.m_y = v23;
  }
  v36.m_z = v24;
  bfx::Surfer3D::SetPosAndVolume(this: &this->m_surfer, pos: &v36, pVolume: v21);
  this->m_surfer.m_pMover = this;
  this->m_rot.m_w = rot->m_w;
  this->m_rot.m_x = rot->m_x;
  p_m_orbitCenterPos = &this->m_orbitCenterPos;
  this->m_rot.m_y = rot->m_y;
  p_m_orbitCenterPos = &this->m_rot;
  this->m_rot.m_z = rot->m_z;
  v26 = v36.m_x;
  v27 = v36.m_y;
  p_m_orbitCenterPos = &this->m_lastGoalPosActedOn;
  v28 = v36.m_z;
  this->m_orbitCenterPos.m_x = v36.m_x;
  this->m_orbitCenterPos.m_y = v27;
  this->m_orbitCenterPos.m_z = v28;
  this->m_reachableGoalPos.m_x = v26;
  this->m_reachableGoalPos.m_y = v27;
  this->m_reachableGoalPos.m_z = v28;
  this->m_lastRequestedGoalPos.m_x = v26;
  this->m_lastRequestedGoalPos.m_y = v27;
  this->m_lastRequestedGoalPos.m_z = v28;
  this->m_lastGoalPosActedOn.m_x = v26;
  this->m_lastGoalPosActedOn.m_y = v27;
  this->m_lastGoalPosActedOn.m_z = v28;
  bfx::ApplyLimits_Mover3DTune(tune: p_m_tune);
  bfx::Quat::Apply(this: (bfx::Quat *)v37, result: rot, v: &FWD_VEC);
  this->m_state = IDLE;
  bfx::Mover3DImpl::EnableRepulsor(this, enable: true);
  return this;
}


// ========================================================================
// __unwind$92355
// EA  : 0x8326BDF0
// RVA : 0x0126BDF0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void _unwind_92355()
{
  int v0; // r12

  bfx::Mover3DBase::~Mover3DBase(this: *(bfx::Mover3DBase **)(v0 - 224 + 244));
}


// ========================================================================
// __unwind$92356
// EA  : 0x8326BE18
// RVA : 0x0126BE18
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void _unwind_92356()
{
  int v0; // r12

  bfx::MSurfer3D::~MSurfer3D(this: (bfx::MSurfer3D *)(*(_DWORD *)(v0 - 224 + 244) + 128));
}


// ========================================================================
// ??1Mover3DImpl@bfx@@UAA@XZ
// EA  : 0x8326BE50
// RVA : 0x0126BE50
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __fastcall bfx::Mover3DImpl::~Mover3DImpl(bfx::Mover3DImpl *this)
{
  bfx::Mover3DSpaceComponent *Mover3DSpaceComponent; // r3
  int v3; // r10
  int v4; // r9
  int v5; // r8
  int v6; // r7
  int v7; // r6
  int v8; // r5
  bfx::Path3D *m_pPath; // r29
  bfx::HandleProxy *m_pProxy; // r3
  int v11; // [sp+8h] [-78h]
  int v12; // [sp+Ch] [-74h]
  int v13; // [sp+10h] [-70h]
  int v14; // [sp+14h] [-6Ch]
  int v15; // [sp+18h] [-68h]
  bfx::Space *v16; // [sp+1Ch] [-64h]

  this->__vftable = (bfx::Mover3DImpl_vtbl *)&bfx::Mover3DImpl::`vftable';
  bfx::Mover3DImpl::EnableRepulsor(this, enable: false);
  Mover3DSpaceComponent = bfx::GetMover3DSpaceComponent(pSpace: this->m_pSpace);
  bfx::Mover3DSpaceComponent::RemoveMover(
    this: Mover3DSpaceComponent,
    pMover: (bfx::Space *)this,
    a3: v8,
    a4: v7,
    a5: v6,
    a6: v5,
    a7: v4,
    a8: v3,
    a9: v11,
    a10: v12,
    a11: v13,
    a12: v14,
    a13: v15,
    a14: v16);
  m_pPath = this->m_pPath;
  if ( m_pPath != nullptr )
  {
    bfx::Path3D::~Path3D(this: this->m_pPath);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pPath);
  }
  this->m_surfer.__vftable = (bfx::MSurfer3D_vtbl *)&bfx::Surfer3D::`vftable';
  m_pProxy = this->m_surfer.m_volume.m_pProxy;
  if ( m_pProxy != nullptr )
  {
    bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
    this->m_surfer.m_volume.m_pProxy = nullptr;
  }
  this->__vftable = (bfx::Mover3DImpl_vtbl *)&bfx::Mover3DBase::`vftable';
}


// ========================================================================
// __unwind$92496
// EA  : 0x8326BEF4
// RVA : 0x0126BEF4
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void _unwind_92496()
{
  int v0; // r12

  bfx::Mover3DBase::~Mover3DBase(this: *(bfx::Mover3DBase **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$92497
// EA  : 0x8326BF1C
// RVA : 0x0126BF1C
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void _unwind_92497()
{
  int v0; // r12

  bfx::MSurfer3D::~MSurfer3D(this: (bfx::MSurfer3D *)(*(_DWORD *)(v0 - 128 + 148) + 128));
}


// ========================================================================
// ?CreateMover3D@bfx@@YAPAVMover3D@1@AAVSpaceHandle@1@ABVVector3@1@ABVQuaternion@1@PBUMover3DTune@1@@Z
// EA  : 0x8326BF50
// RVA : 0x0126BF50
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

bfx::HandleProxy **__fastcall bfx::CreateMover3D(
        bfx::SpaceHandle *space,
        const bfx::Vector3 *_pos,
        const bfx::Quaternion *_rot,
        const bfx::Mover3DTune *pTune)
{
  bfx::Space *Volume; // r3
  bfx::Quat *v9; // r30
  double m_y; // fp13
  double m_x; // fp12
  bfx::InstanceComponent *v13; // r8
  unsigned int v14; // r27
  bfx::Mover3DImpl *v15; // r3
  bfx::Space *v16; // r28
  bfx::Mover3DSpaceComponent *Mover3DSpaceComponent; // r3
  int v18; // r10
  int v19; // r9
  int v20; // r8
  int v21; // r7
  int v22; // r6
  int v23; // r5
  bfx::HandleProxy **p_m_pProxy; // r30
  int v25; // [sp+8h] [-D8h]
  int v26; // [sp+Ch] [-D4h]
  int v27; // [sp+10h] [-D0h]
  int v28; // [sp+14h] [-CCh]
  int v29; // [sp+18h] [-C8h]
  bfx::Space *v30; // [sp+1Ch] [-C4h]
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-90h]
  bfx::Vec3 v32; // [sp+58h] [-88h] BYREF
  bfx::Matrix v33; // [sp+68h] [-78h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  Volume = bfx::GetVolume(spaceHandle: space);
  v9 = (bfx::Quat *)Volume;
  if ( Volume != nullptr )
  {
    m_y = _pos->m_y;
    m_x = _pos->m_x;
    v32.m_z = _pos->m_z;
    v32.m_x = m_x;
    v32.m_y = m_y;
    bfx::Matrix::operator*(this: &v33, result: (bfx::Vec3 *)&Volume->m_matWorldToSpace, rhs: &v32);
    bfx::Space::RotateToSpace(this: (bfx::Space *)&v33.m_data[6], result: v9, rotIn: _rot);
    v13 = bfx::g_pCurInstance->m_pComponentManager->m_components[5];
    v14 = (unsigned int)v13[1].__vftable;
    v13[1].__vftable = (bfx::InstanceComponent_vtbl *)(v14 + 1);
    v15 = (bfx::Mover3DImpl *)bfx::MemoryManager::Malloc(
                                this: bfx::g_pCurInstance->m_pMemoryManager,
                                size: 0x244u,
                                tag: bfx::MEM_BFXMOVER3D);
    if ( v15 != nullptr )
      v16 = (bfx::Space *)bfx::Mover3DImpl::Mover3DImpl(
                            this: v15,
                            pSpace: (bfx::Space *)v9,
                            pos: (const bfx::Vec3 *)&v33,
                            rot: (bfx::Quat *)&v33.m_data[6],
                            pTune,
                            replayID: v14);
    else
      v16 = nullptr;
    Mover3DSpaceComponent = bfx::GetMover3DSpaceComponent(pSpace: (bfx::Space *)v9);
    bfx::Mover3DSpaceComponent::AddMover(
      this: Mover3DSpaceComponent,
      pMover: v16,
      a3: v23,
      a4: v22,
      a5: v21,
      a6: v20,
      a7: v19,
      a8: v18,
      a9: v25,
      a10: v26,
      a11: v27,
      a12: v28,
      a13: v29,
      a14: v30);
    bfx::LogCreateMover3D(spaceHandle: space, replayID: v14, pos: _pos, rot: _rot, pTune);
    p_m_pProxy = &v16->m_pProxy;
    if ( v16 == nullptr )
      p_m_pProxy = nullptr;
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return p_m_pProxy;
  }
  else
  {
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return nullptr;
  }
}


// ========================================================================
// __unwind$92585
// EA  : 0x8326C0A8
// RVA : 0x0126C0A8
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void _unwind_92585()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 224 + 80));
}


// ========================================================================
// __unwind$92586
// EA  : 0x8326C0D0
// RVA : 0x0126C0D0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void _unwind_92586()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 224 + 84), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// bfx::`dynamic initializer for 'g_drawMover3DPathRestore''
// EA  : 0x83398598
// RVA : 0x01398598
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_drawMover3DPathRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_drawMover3DPathRestore);
  bfx::g_drawMover3DPathRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_drawMover3DPathRestore.m_targetBool = &bfx::g_drawMover3DPath;
  bfx::g_drawMover3DPathRestore.m_name = "draw_mover3D_path";
  bfx::g_drawMover3DPathRestore.m_defaultBool = bfx::g_drawMover3DPath;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_drawMover3DPathRestore__);
}


// ========================================================================
// bfx::`dynamic initializer for 'g_drawMover3DNextPathPosRestore''
// EA  : 0x83398610
// RVA : 0x01398610
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_drawMover3DNextPathPosRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_drawMover3DNextPathPosRestore);
  bfx::g_drawMover3DNextPathPosRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_drawMover3DNextPathPosRestore.m_targetBool = &bfx::g_drawMover3DNextPathPos;
  bfx::g_drawMover3DNextPathPosRestore.m_name = "draw_mover3D_next_path_pos";
  bfx::g_drawMover3DNextPathPosRestore.m_defaultBool = bfx::g_drawMover3DNextPathPos;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_drawMover3DNextPathPosRestore__);
}


// ========================================================================
// bfx::`dynamic initializer for 'g_drawMover3DMotionRestore''
// EA  : 0x83398688
// RVA : 0x01398688
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3d.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_drawMover3DMotionRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_drawMover3DMotionRestore);
  bfx::g_drawMover3DMotionRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_drawMover3DMotionRestore.m_targetBool = &bfx::g_drawMover3DMotion;
  bfx::g_drawMover3DMotionRestore.m_name = "draw_mover3D_motion";
  bfx::g_drawMover3DMotionRestore.m_defaultBool = bfx::g_drawMover3DMotion;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_drawMover3DMotionRestore__);
}

