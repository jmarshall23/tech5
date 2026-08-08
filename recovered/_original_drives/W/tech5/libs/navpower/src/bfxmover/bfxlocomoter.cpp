
// ========================================================================
// ?MovedOntoArea@LocomoterImpl@bfx@@UAAXABVVec3@2@PAVArea@2@010@Z
// EA  : 0x832D9A20
// RVA : 0x012D9A20
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxlocomoter.cpp
// ========================================================================

void __fastcall bfx::LocomoterImpl::MovedOntoArea(
        bfx::LocomoterImpl *this,
        const bfx::Vec3 *oldPos,
        bfx::Vec3 *pOldArea,
        const bfx::Vec3 *newPos,
        bfx::Vec3 *pNewArea,
        const bfx::Vec3 *edgeVec)
{
  bfx::Vec3 *p_m_curMoveDir; // r27
  bfx::Area *v13; // r24
  bfx::Area *v14; // r3
  bfx::Vec3 *v15; // r3
  double m_x; // fp0
  double m_y; // fp13
  double m_z; // fp12
  double v19; // fp7
  bfx::Area *v22; // r24
  bfx::Area *v23; // r3
  bfx::Prober *m_pProber; // r3
  bfx::Area v25[2]; // [sp+50h] [-80h] BYREF

  p_m_curMoveDir = &this->m_curMoveDir;
  v13 = bfx::Area::CalcNormal(this: v25, result: pNewArea);
  v14 = bfx::Area::CalcNormal(this: (bfx::Area *)&v25[0].m_pos, result: pOldArea);
  v15 = bfx::RotateVecIntoNewArea(
          result: (bfx::Vec3 *)&v25[0].m_searchCost,
          vec: p_m_curMoveDir,
          edgeUnitVec: edgeVec,
          oldAreaNormal: (const bfx::Vec3 *)v14,
          newAreaNormal: (const bfx::Vec3 *)v13);
  m_x = v15->m_x;
  this->m_curMoveDir.m_x = v15->m_x;
  m_y = v15->m_y;
  this->m_curMoveDir.m_y = v15->m_y;
  m_z = v15->m_z;
  v19 = (float)((float)((float)m_y * (float)m_y) + (float)(v15->m_z * v15->m_z));
  this->m_curMoveDir.m_z = v15->m_z;
  _FP4 = (float)((float)__fsqrts((float)((float)((float)m_x * (float)m_x) + (float)v19)) - (float)1.0842022e-19);
  __asm { fsel      f2, f4, f3, f12 }
  this->m_curMoveDir.m_x = (float)m_x * (float)_FP2;
  this->m_curMoveDir.m_y = (float)m_y * (float)_FP2;
  this->m_curMoveDir.m_z = (float)m_z * (float)_FP2;
  if ( this->m_commonState->m_pTune->m_clientMotion )
  {
    v22 = bfx::Area::CalcNormal(this: (bfx::Area *)&v25[0].m_searchCost, result: pNewArea);
    v23 = bfx::Area::CalcNormal(this: (bfx::Area *)&v25[0].m_pos, result: pOldArea);
    this->m_clientSpecifiedVel = *bfx::RotateVecIntoNewArea(
                                    result: (bfx::Vec3 *)v25,
                                    vec: &this->m_clientSpecifiedVel,
                                    edgeUnitVec: edgeVec,
                                    oldAreaNormal: (const bfx::Vec3 *)v23,
                                    newAreaNormal: (const bfx::Vec3 *)v22);
  }
  bfx::Orienter::MovedOntoArea(this: &this->m_commonState->m_orienter, pOldArea, pNewArea, edgeVec);
  m_pProber = this->m_commonState->m_pProber;
  if ( m_pProber != nullptr )
    bfx::Prober::MovedOntoArea(
      this: m_pProber,
      oldPos,
      __formal: (bfx::Area *)pOldArea,
      newPos,
      a5: (bfx::Area *)pNewArea,
      a6: edgeVec);
}


// ========================================================================
// ?GetInitialConstraint@LocomoterImpl@bfx@@UAAXAAVInitialConstraint@2@@Z
// EA  : 0x832D9B98
// RVA : 0x012D9B98
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxlocomoter.cpp
// ========================================================================

void __fastcall bfx::LocomoterImpl::GetInitialConstraint(
        bfx::LocomoterImpl *this,
        bfx::InitialConstraint *initialConstraint)
{
  initialConstraint->m_constraintType = !this->m_midSpec.m_pushableByConstraintSolver
                                      ? CONSTRAINT_POINT
                                      : CONSTRAINT_NONE;
}


// ========================================================================
// ?SetMoveParams@LocomoterImpl@bfx@@UAAXABVVec3@2@MABVMIDSpec@2@@Z
// EA  : 0x832D9BB8
// RVA : 0x012D9BB8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxlocomoter.cpp
// ========================================================================

void __fastcall bfx::LocomoterImpl::SetMoveParams(
        bfx::LocomoterImpl *this,
        const bfx::Vec3 *dir,
        double speed,
        const bfx::MIDSpec *spec,
        bool *a5)
{
  bfx::AreaProxy *m_pProxy; // r11
  bfx::Vec3 *m_pArea; // r4
  double m_z; // fp8
  double m_x; // fp5
  double v13; // fp2
  double v14; // fp0
  double v15; // fp12
  double v16; // fp8
  double v17; // fp7
  double v18; // fp5
  double v19; // fp2
  bfx::Area v22; // [sp+50h] [-40h] BYREF

  m_pProxy = this->m_commonState->m_surfer.m_area.m_pProxy;
  if ( m_pProxy != nullptr )
    m_pArea = (bfx::Vec3 *)m_pProxy->m_pArea;
  else
    m_pArea = nullptr;
  bfx::Area::CalcNormal(this: &v22, result: m_pArea);
  m_z = dir->m_z;
  m_x = dir->m_x;
  v13 = (float)((float)((float)(dir->m_x * *(float *)&v22.m_pProxy)
                      + (float)((float)(dir->m_y * *(float *)&v22.m_dynAreaData.m_data)
                              + (float)(dir->m_z * *(float *)&v22.m_pFirstLink)))
              * *(float *)&v22.m_pProxy);
  v14 = (float)(*(float *)&v22.m_pFirstLink
              * (float)((float)(dir->m_x * *(float *)&v22.m_pProxy)
                      + (float)((float)(dir->m_y * *(float *)&v22.m_dynAreaData.m_data)
                              + (float)(dir->m_z * *(float *)&v22.m_pFirstLink))));
  v15 = (float)(dir->m_y
              - (float)(*(float *)&v22.m_dynAreaData.m_data
                      * (float)((float)(dir->m_x * *(float *)&v22.m_pProxy)
                              + (float)((float)(dir->m_y * *(float *)&v22.m_dynAreaData.m_data)
                                      + (float)(dir->m_z * *(float *)&v22.m_pFirstLink)))));
  this->m_curMoveDir.m_y = dir->m_y
                         - (float)(*(float *)&v22.m_dynAreaData.m_data
                                 * (float)((float)(dir->m_x * *(float *)&v22.m_pProxy)
                                         + (float)((float)(dir->m_y * *(float *)&v22.m_dynAreaData.m_data)
                                                 + (float)(dir->m_z * *(float *)&v22.m_pFirstLink))));
  this->m_curMoveDir.m_x = (float)m_x - (float)v13;
  v16 = (float)((float)m_z - (float)v14);
  this->m_curMoveDir.m_z = v16;
  v17 = (float)((float)m_x - (float)v13);
  v19 = (float)((float)((float)v16 * (float)v16)
              + (float)((float)((float)((float)m_x - (float)v13) * (float)((float)m_x - (float)v13))
                      + (float)((float)v15 * (float)v15)));
  v18 = v15;
  _FP0 = (float)((float)__fsqrts(v19) - (float)1.0842022e-19);
  __asm { fsel      f12, f0, f13, f9 }
  this->m_curMoveDir.m_x = (float)v17 * (float)_FP12;
  this->m_curMoveDir.m_y = (float)v18 * (float)_FP12;
  this->m_curMoveDir.m_z = (float)v16 * (float)_FP12;
  this->m_desMoveSpeed = speed;
  this->m_midSpec.m_stopWhenBlocked = *a5;
  this->m_midSpec.m_blockedIgnoresCushions = a5[1];
  this->m_midSpec.m_pushableByConstraintSolver = a5[2];
}


// ========================================================================
// ?GetDesiredVel@LocomoterImpl@bfx@@UBA?AVVec3@2@XZ
// EA  : 0x832D9CD0
// RVA : 0x012D9CD0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxlocomoter.cpp
// ========================================================================

bfx::LocomoterImpl *__fastcall bfx::LocomoterImpl::GetDesiredVel(bfx::LocomoterImpl *this, bfx::Vec3 *result)
{
  double v2; // fp9
  double v3; // fp8

  v2 = (float)(result[1].m_x * result[1].m_z);
  v3 = (float)(result[1].m_y * result[1].m_z);
  *(float *)&this->__vftable = result->m_z * result[1].m_z;
  *(float *)&this->m_commonState = v2;
  this->m_curMoveDir.m_x = v3;
  return this;
}


// ========================================================================
// ?ApplyClientMotion@LocomoterImpl@bfx@@UAAXABVVec3@2@@Z
// EA  : 0x832D9D00
// RVA : 0x012D9D00
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxlocomoter.cpp
// ========================================================================

void __fastcall bfx::LocomoterImpl::ApplyClientMotion(bfx::LocomoterImpl *this, const bfx::Vec3 *vel)
{
  bfx::MotionState *m_commonState; // r11
  bfx::Vec3 *p_m_clientSpecifiedVel; // r31
  bfx::Vec3 **m_pProxy; // r11
  bfx::Vec3 *v5; // r4
  double m_x; // fp9
  double m_z; // fp8
  double v8; // fp5
  double v9; // fp3
  float v10; // [sp+50h] [-20h] BYREF
  float v11; // [sp+54h] [-1Ch]
  float v12; // [sp+58h] [-18h]

  m_commonState = this->m_commonState;
  this->m_clientSpecifiedVel = *vel;
  p_m_clientSpecifiedVel = &this->m_clientSpecifiedVel;
  m_pProxy = (bfx::Vec3 **)m_commonState->m_surfer.m_area.m_pProxy;
  if ( m_pProxy != nullptr )
    v5 = *m_pProxy;
  else
    v5 = nullptr;
  if ( v5 != nullptr )
  {
    bfx::Area::CalcNormal(this: (bfx::Area *)&v10, result: v5);
    m_x = p_m_clientSpecifiedVel->m_x;
    m_z = p_m_clientSpecifiedVel->m_z;
    v8 = (float)((float)((float)(p_m_clientSpecifiedVel->m_z * v12)
                       + (float)((float)(p_m_clientSpecifiedVel->m_x * v10) + (float)(p_m_clientSpecifiedVel->m_y * v11)))
               * v10);
    v9 = (float)(v12
               * (float)((float)(p_m_clientSpecifiedVel->m_z * v12)
                       + (float)((float)(p_m_clientSpecifiedVel->m_x * v10) + (float)(p_m_clientSpecifiedVel->m_y * v11))));
    p_m_clientSpecifiedVel->m_y = p_m_clientSpecifiedVel->m_y
                                - (float)(v11
                                        * (float)((float)(p_m_clientSpecifiedVel->m_z * v12)
                                                + (float)((float)(p_m_clientSpecifiedVel->m_x * v10)
                                                        + (float)(p_m_clientSpecifiedVel->m_y * v11))));
    p_m_clientSpecifiedVel->m_x = (float)m_x - (float)v8;
    p_m_clientSpecifiedVel->m_z = (float)m_z - (float)v9;
  }
}


// ========================================================================
// ??0LocomoterImpl@bfx@@QAA@ABVMatrix@1@PAVArea@1@AAVMotionState@1@@Z
// EA  : 0x832D9DD0
// RVA : 0x012D9DD0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxlocomoter.cpp
// ========================================================================

bfx::LocomoterImpl *__fastcall bfx::LocomoterImpl::LocomoterImpl(
        bfx::LocomoterImpl *this,
        const bfx::Matrix *startMat,
        bfx::Vec3 *pStartArea,
        bfx::MotionState *commonState)
{
  double v7; // fp13
  bfx::MotionState *m_commonState; // r11
  double v9; // fp12
  double v10; // fp10
  bfx::MotionState *v11; // r10
  double v12; // fp9
  long double v13; // fp2
  bfx::MotionState *v14; // r11
  unsigned int m_planLayer; // r10
  bfx::NavLayer *v16; // r28
  const bfx::Vec3 *p_m_pos; // r29
  bfx::Orienter *LocalUpAxis; // r3
  bfx::Vec3 v20; // [sp+58h] [-58h] BYREF
  bfx::Vec3 v21; // [sp+68h] [-48h] BYREF
  int v22; // [sp+78h] [-38h] BYREF

  this->m_commonState = commonState;
  this->__vftable = (bfx::LocomoterImpl_vtbl *)&bfx::LocomoterImpl::`vftable';
  bfx::MIDSpec::MIDSpec(this: &this->m_midSpec);
  this->m_curMoveDir = bfx::ZERO_VEC;
  this->m_desMoveSpeed = 0.0;
  this->m_actualVel = bfx::ZERO_VEC;
  this->m_timeBlocked = 0.0;
  this->m_clientSpecifiedVel = bfx::ZERO_VEC;
  v7 = startMat->m_data[14];
  m_commonState = this->m_commonState;
  v9 = startMat->m_data[13];
  v20.m_x = startMat->m_data[12];
  v20.m_y = v9;
  v20.m_z = v7;
  bfx::Surfer::SetPosAndArea(this: &m_commonState->m_surfer, pos: &v20, pArea: pStartArea);
  v10 = startMat->m_data[13];
  v11 = this->m_commonState;
  v12 = startMat->m_data[12];
  v21.m_z = startMat->m_data[14];
  v21.m_x = v12;
  v21.m_y = v10;
  bfx::SmartPath::SetStartData(this: v11->m_pSmartPath, startPos: &v21, (bfx::Area *)pStartArea);
  bfx::Orienter::TeleportToArea(this: &this->m_commonState->m_orienter, pArea: pStartArea, a3: v13);
  bfx::Orienter::SetOrientation(this: &this->m_commonState->m_orienter, desiredRot: startMat);
  v14 = this->m_commonState;
  if ( v14->m_pProber != nullptr )
  {
    m_planLayer = v14->m_pTune->m_planLayer;
    if ( m_planLayer >= 0x20 )
      v16 = nullptr;
    else
      v16 = *(bfx::NavLayer **)(4 * (m_planLayer + 2) + *((_DWORD *)v14->m_pSpace->m_components.m_data + 1));
    p_m_pos = &v14->m_surfer.m_pos;
    LocalUpAxis = bfx::Orienter::GetLocalUpAxis(this: (bfx::Orienter *)&v22, result: (bfx::Vec3 *)&v14->m_orienter);
    bfx::Prober::TeleportToArea(
      this: this->m_commonState->m_pProber,
      pNavLayer: v16,
      surferPos: p_m_pos,
      localUpAxis: (const bfx::Vec3 *)LocalUpAxis);
  }
  return this;
}


// ========================================================================
// __unwind$25419
// EA  : 0x832D9F70
// RVA : 0x012D9F70
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxlocomoter.cpp
// ========================================================================

void _unwind_25419()
{
  int v0; // r12

  bfx::Idle::~Idle(this: *(bfx::Walker **)(v0 - 176 + 196));
}


// ========================================================================
// ?OrientInDirectionOfTravel@LocomoterImpl@bfx@@UAAXXZ
// EA  : 0x832D9F98
// RVA : 0x012D9F98
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxlocomoter.cpp
// ========================================================================

void __fastcall bfx::LocomoterImpl::OrientInDirectionOfTravel(bfx::LocomoterImpl *this)
{
  idThrowableFilter::InternalPostFilterItems(this: &this->m_commonState->m_orienter);
}


// ========================================================================
// ?OrientStrictlyInDirectionOfTravel@LocomoterImpl@bfx@@UAAXXZ
// EA  : 0x832D9FA8
// RVA : 0x012D9FA8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxlocomoter.cpp
// ========================================================================

void __fastcall bfx::LocomoterImpl::OrientStrictlyInDirectionOfTravel(bfx::LocomoterImpl *this)
{
  bfx::Orienter::FaceStrictlyInTravelDir(this: &this->m_commonState->m_orienter);
}


// ========================================================================
// ?OrientTowardsTargetPos@LocomoterImpl@bfx@@UAAXABVVec3@2@@Z
// EA  : 0x832D9FB8
// RVA : 0x012D9FB8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxlocomoter.cpp
// ========================================================================

void __fastcall bfx::LocomoterImpl::OrientTowardsTargetPos(bfx::LocomoterImpl *this, const bfx::Vec3 *targetPos)
{
  bfx::Orienter::FaceTarget(this: &this->m_commonState->m_orienter, targetPos);
}


// ========================================================================
// ?OrientInDirection@LocomoterImpl@bfx@@UAAXABVVec3@2@@Z
// EA  : 0x832D9FC8
// RVA : 0x012D9FC8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxlocomoter.cpp
// ========================================================================

void __fastcall bfx::LocomoterImpl::OrientInDirection(bfx::LocomoterImpl *this, const bfx::Vec3 *dir)
{
  bfx::Orienter::FaceInDir(this: &this->m_commonState->m_orienter, dir);
}


// ========================================================================
// ?GetPos@LocomoterImpl@bfx@@UBA?AVVec3@2@XZ
// EA  : 0x832D9FD8
// RVA : 0x012D9FD8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxlocomoter.cpp
// ========================================================================

bfx::LocomoterImpl *__fastcall bfx::LocomoterImpl::GetPos(bfx::LocomoterImpl *this, bfx::Vec3 *result)
{
  float m_y; // r11
  int v3; // r9
  bfx::Vec3 *v4; // r10
  double v5; // fp8
  double v6; // fp6
  _DWORD back_chain[4]; // [sp+0h] [-10h] BYREF

  m_y = result->m_y;
  v3 = *(_DWORD *)(LODWORD(m_y) + 336);
  if ( v3 != 0 )
  {
    v4 = (bfx::Vec3 *)back_chain;
    back_chain[2] = *(_DWORD *)(v3 + 24);
  }
  else
  {
    v4 = &bfx::ZERO_VEC;
  }
  v5 = (float)(*(float *)(LODWORD(m_y) + 24) + v4->m_y);
  v6 = (float)(*(float *)(LODWORD(m_y) + 28) + v4->m_z);
  *(float *)&this->__vftable = v4->m_x + *(float *)(LODWORD(m_y) + 20);
  *(float *)&this->m_commonState = v5;
  this->m_curMoveDir.m_x = v6;
  return this;
}


// ========================================================================
// ?GetMatrix@LocomoterImpl@bfx@@UBAXAAVMatrix@2@@Z
// EA  : 0x832DA048
// RVA : 0x012DA048
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxlocomoter.cpp
// ========================================================================

void __fastcall bfx::LocomoterImpl::GetMatrix(bfx::LocomoterImpl *this, bfx::Matrix *mat)
{
  const bfx::Vec3 *v4; // r3
  _BYTE v5[24]; // [sp+50h] [-30h] BYREF

  v4 = this->GetPos(this: v5, result: this);
  bfx::Orienter::CalcMat(this: &this->m_commonState->m_orienter, pos: v4, mat);
}


// ========================================================================
// ?OkToMoveOntoArea@LocomoterImpl@bfx@@UBA_NPAVArea@2@@Z
// EA  : 0x832DA0A8
// RVA : 0x012DA0A8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxlocomoter.cpp
// ========================================================================

int __fastcall bfx::LocomoterImpl::OkToMoveOntoArea(bfx::LocomoterImpl *this, bfx::Area *pArea)
{
  return bfx::OkToMoveOntoArea(pArea, pTune: this->m_commonState->m_pTune);
}


// ========================================================================
// ?IsBlockedByRepulsor@LocomoterImpl@bfx@@UBA_NXZ
// EA  : 0x832DA0B8
// RVA : 0x012DA0B8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxlocomoter.cpp
// ========================================================================

BOOL __fastcall bfx::LocomoterImpl::IsBlockedByRepulsor(bfx::LocomoterImpl *this)
{
  return this->m_timeBlocked > 0.0;
}


// ========================================================================
// ?IsTurningInPlace@LocomoterImpl@bfx@@UBA_NPAVTurningInPlaceData@2@@Z
// EA  : 0x832DA0E0
// RVA : 0x012DA0E0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxlocomoter.cpp
// ========================================================================

int __fastcall bfx::LocomoterImpl::IsTurningInPlace(bfx::LocomoterImpl *this, bfx::TurningInPlaceData *pDataOut)
{
  return bfx::MotionBase::IsTurningInPlaceHelper(
           this,
           pDataOut,
           commonState: this->m_commonState,
           curVel: &this->m_actualVel);
}


// ========================================================================
// ?IsBlocked@LocomoterImpl@bfx@@AAA_NXZ
// EA  : 0x832DA150
// RVA : 0x012DA150
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxlocomoter.cpp
// ========================================================================

int __fastcall bfx::LocomoterImpl::IsBlocked(bfx::LocomoterImpl *this)
{
  bfx::MotionState *m_commonState; // r10
  const bfx::MoverTune *m_pTune; // r8
  double m_x; // fp11
  double m_y; // fp7
  bfx::Vec3 *p_m_curMoveDir; // r11
  int v9; // r9
  float v10; // r6
  float m_z; // r5
  bfx::SpaceComponent **m_data; // r10
  double v13; // fp6
  double v14; // fp5
  double v15; // fp4
  float *v16; // r11
  float v17; // r5
  float v18; // r3
  double v19; // fp0
  double v20; // fp13
  float v22; // [sp+58h] [-58h] BYREF
  float v23; // [sp+5Ch] [-54h]
  float v24; // [sp+60h] [-50h]
  float v25[6]; // [sp+68h] [-48h] BYREF
  bfx::Array<bfx::SpaceComponent *> v26[3]; // [sp+80h] [-30h] BYREF

  m_commonState = this->m_commonState;
  if ( m_commonState->m_pRepulsor == nullptr )
    return 0;
  memset(v26, 0, 12);
  v26[0].m_tag = bfx::MEM_BFXMOVER;
  bfx::Repulsor3DImpl::GetNearbyRepulsors(
    this: m_commonState->m_pRepulsor,
    nearbyRepulsors: v26,
    filterBasedOnBlockageFlags: true);
  this->GetPos(this: (struct bfx::LocomoterImpl *)v25, result: (bfx::Vec3 *)this);
  m_pTune = this->m_commonState->m_pTune;
  if ( m_pTune->m_clientMotion )
  {
    m_x = this->m_clientSpecifiedVel.m_x;
    m_y = this->m_clientSpecifiedVel.m_y;
    p_m_curMoveDir = (bfx::Vec3 *)&v22;
    _FP3 = (float)((float)__fsqrts((float)((float)(this->m_clientSpecifiedVel.m_z * this->m_clientSpecifiedVel.m_z)
                                         + (float)((float)(this->m_clientSpecifiedVel.m_x
                                                         * this->m_clientSpecifiedVel.m_x)
                                                 + (float)(this->m_clientSpecifiedVel.m_y
                                                         * this->m_clientSpecifiedVel.m_y))))
                 - (float)1.0842022e-19);
    __asm { fsel      f1, f3, f2, f10 }
    v24 = this->m_clientSpecifiedVel.m_z * (float)_FP1;
    v23 = (float)m_y * (float)_FP1;
    v22 = (float)m_x * (float)_FP1;
  }
  else
  {
    p_m_curMoveDir = &this->m_curMoveDir;
  }
  v9 = 0;
  v10 = p_m_curMoveDir->m_y;
  m_z = p_m_curMoveDir->m_z;
  v22 = p_m_curMoveDir->m_x;
  v23 = v10;
  v24 = m_z;
  if ( v26[0].m_size <= 0 )
  {
LABEL_14:
    v26[0].m_size = 0;
    if ( v26[0].m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v26[0].m_data);
    return 0;
  }
  m_data = v26[0].m_data;
  v13 = v24;
  v14 = v23;
  v15 = v22;
  while ( 1 )
  {
    v16 = (float *)*m_data;
    v17 = *(float *)&(*m_data)[3].__vftable;
    v18 = *(float *)&(*m_data)[5].__vftable;
    v23 = *(float *)&(*m_data)[4].__vftable;
    v22 = v17;
    v24 = v18;
    if ( (float)((float)((float)((float)(v25[0] - v17) * (float)-1.0) * (float)v15)
               + (float)((float)((float)v14 * (float)((float)(v25[1] - v23) * (float)-1.0))
                       + (float)((float)v13 * (float)((float)(v25[2] - v18) * (float)-1.0)))) > 0.0 )
    {
      v19 = __fsqrts((float)((float)((float)(v25[2] - v24) * (float)(v25[2] - v24))
                           + (float)((float)((float)(v25[0] - v17) * (float)(v25[0] - v17))
                                   + (float)((float)(v25[1] - v23) * (float)(v25[1] - v23)))));
      v20 = this->m_midSpec.m_blockedIgnoresCushions
          ? (float)(m_pTune->m_radiusData.m_radius + v16[9])
          : (float)((float)((float)((float)((float)(v16[11] + v16[10]) + m_pTune->m_radiusData.m_innerCushion)
                                  + m_pTune->m_radiusData.m_outerCushion)
                          + m_pTune->m_radiusData.m_radius)
                  + v16[9]);
      if ( v19 > 0.0 && v19 < v20 )
        break;
    }
    ++v9;
    ++m_data;
    if ( v9 >= v26[0].m_size )
      goto LABEL_14;
  }
  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: v26);
  return 1;
}


// ========================================================================
// __unwind$25646
// EA  : 0x832DA398
// RVA : 0x012DA398
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxlocomoter.cpp
// ========================================================================

void _unwind_25646()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 176 + 128));
}


// ========================================================================
// ?CreateLocomoter@bfx@@YAPAVLocomoter@1@ABVMatrix@1@PAVArea@1@AAVMotionState@1@@Z
// EA  : 0x832DA3C8
// RVA : 0x012DA3C8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxlocomoter.cpp
// ========================================================================

bfx::LocomoterImpl *__fastcall bfx::CreateLocomoter(
        const bfx::Matrix *startMat,
        bfx::Vec3 *pStartArea,
        bfx::MotionState *commonState)
{
  bfx::LocomoterImpl *v6; // r3

  v6 = (bfx::LocomoterImpl *)bfx::MemoryManager::Malloc(
                               this: bfx::g_pCurInstance->m_pMemoryManager,
                               size: 0x38u,
                               tag: bfx::MEM_BFXMOVER);
  if ( v6 != nullptr )
    return bfx::LocomoterImpl::LocomoterImpl(this: v6, startMat, pStartArea, commonState);
  else
    return nullptr;
}


// ========================================================================
// __unwind$25810
// EA  : 0x832DA42C
// RVA : 0x012DA42C
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxlocomoter.cpp
// ========================================================================

void _unwind_25810()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(char **)(v0 - 128 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?Simulate@LocomoterImpl@bfx@@UAAXM@Z
// EA  : 0x832DA458
// RVA : 0x012DA458
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxlocomoter.cpp
// ========================================================================

void __fastcall bfx::LocomoterImpl::Simulate(bfx::LocomoterImpl *this, double simTime)
{
  bfx::MotionState *m_commonState; // r11
  float m_x; // r9
  float m_y; // r8
  float m_z; // r7
  BOOL m_stopWhenBlocked; // r6
  float v9; // r5
  float v10; // r4
  float v11; // r3
  bfx::MotionState *v12; // r11
  double v13; // fp12
  double v14; // fp11
  double v15; // fp9
  double v16; // fp4
  double v17; // fp1
  double v20; // fp0
  bfx::MotionState *v21; // r11
  double v22; // fp6
  double v23; // fp5
  double v24; // fp30
  double v25; // fp29
  double v26; // fp28
  double Scale; // fp1
  bfx::MotionState *v28; // r11
  long double v29; // fp4
  long double v30; // fp2
  const bfx::Vec3 *v31; // r6
  bfx::Vec3 v32; // [sp+50h] [-80h] BYREF
  float v33; // [sp+60h] [-70h]
  float v34; // [sp+64h] [-6Ch]
  float v35; // [sp+68h] [-68h]
  bfx::Vec3 v36; // [sp+70h] [-60h] BYREF
  bfx::Vec3 v37; // [sp+80h] [-50h] BYREF

  m_commonState = this->m_commonState;
  m_x = this->m_curMoveDir.m_x;
  m_y = this->m_curMoveDir.m_y;
  m_z = this->m_curMoveDir.m_z;
  m_stopWhenBlocked = this->m_midSpec.m_stopWhenBlocked;
  v9 = m_commonState->m_surfer.m_pos.m_x;
  v10 = m_commonState->m_surfer.m_pos.m_y;
  v11 = m_commonState->m_surfer.m_pos.m_z;
  v32.m_x = m_x;
  v32.m_y = m_y;
  v33 = v9;
  v34 = v10;
  v35 = v11;
  v32.m_z = m_z;
  if ( m_stopWhenBlocked && (unsigned __int8)bfx::LocomoterImpl::IsBlocked(this) != 0 )
  {
    this->m_timeBlocked = this->m_timeBlocked + (float)simTime;
  }
  else
  {
    v12 = this->m_commonState;
    if ( v12->m_pTune->m_clientMotion )
    {
      v13 = this->m_clientSpecifiedVel.m_x;
      v14 = this->m_clientSpecifiedVel.m_z;
      v15 = (float)(this->m_clientSpecifiedVel.m_y * this->m_clientSpecifiedVel.m_y);
      this->m_timeBlocked = 0;
      v16 = this->m_clientSpecifiedVel.m_z;
      v17 = (float)((float)__fsqrts((float)((float)((float)v14 * (float)v14)
                                          + (float)((float)((float)v13 * (float)v13) + (float)v15)))
                  * (float)simTime);
      _FP8 = (float)((float)__fsqrts((float)((float)(this->m_clientSpecifiedVel.m_x * this->m_clientSpecifiedVel.m_x)
                                           + (float)((float)(this->m_clientSpecifiedVel.m_y
                                                           * this->m_clientSpecifiedVel.m_y)
                                                   + (float)(this->m_clientSpecifiedVel.m_z
                                                           * this->m_clientSpecifiedVel.m_z))))
                   - (float)1.0842022e-19);
      __asm { fsel      f3, f8, f7, f0 }
      v20 = (float)((float)_FP3 * this->m_clientSpecifiedVel.m_y);
      v32.m_x = this->m_clientSpecifiedVel.m_x * (float)_FP3;
      v32.m_y = v20;
      v32.m_z = (float)v16 * (float)_FP3;
    }
    else
    {
      v17 = (float)(this->m_desMoveSpeed * (float)simTime);
      this->m_timeBlocked = 0;
    }
    bfx::Surfer::Move(this: &v12->m_surfer, origVel: &v32, time: v17);
  }
  bfx::SmartPath::SetStartData(
    this: this->m_commonState->m_pSmartPath,
    startPos: &this->m_commonState->m_surfer.m_pos,
    pStartArea: nullptr);
  v21 = this->m_commonState;
  v22 = (float)(v21->m_surfer.m_pos.m_y - v34);
  v23 = (float)(v21->m_surfer.m_pos.m_z - v35);
  this->m_actualVel.m_x = (float)((float)1.0 / (float)simTime) * (float)(v21->m_surfer.m_pos.m_x - v33);
  this->m_actualVel.m_y = (float)((float)1.0 / (float)simTime) * (float)v22;
  this->m_actualVel.m_z = (float)((float)1.0 / (float)simTime) * (float)v23;
  this->GetPos(this: (struct bfx::LocomoterImpl *)&v36, result: (bfx::Vec3 *)this);
  v24 = (float)(v32.m_x * (float)100.0);
  v25 = (float)(v32.m_y * (float)100.0);
  v26 = (float)(v32.m_z * (float)100.0);
  Scale = bfx::GetScale();
  v28 = this->m_commonState;
  *((double *)&v29 + 1) = (float)(v36.m_x + (float)((float)v24 * (float)Scale));
  v37.m_x = v36.m_x + (float)((float)v24 * (float)Scale);
  *(double *)&v29 = (float)(v36.m_y + (float)((float)v25 * (float)Scale));
  v37.m_y = v36.m_y + (float)((float)v25 * (float)Scale);
  *((double *)&v30 + 1) = (float)(v36.m_z + (float)((float)v26 * (float)Scale));
  v37.m_z = v36.m_z + (float)((float)v26 * (float)Scale);
  *(double *)&v30 = simTime;
  bfx::Orienter::Simulate(
    this: &v28->m_orienter,
    pos: &v36,
    vel: &this->m_actualVel,
    simTime: v30,
    nextCornerG: v31,
    bForceUseClientMotion: &v37,
    a7: v28->m_forceUseClientMotion,
    a8: v29);
  bfx::MotionState::SimulateProber(this: this->m_commonState, simTime);
}

