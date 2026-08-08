
// ========================================================================
// ?Reserve@FastArrayOfRepRecs@bfx@@QAAXH@Z
// EA  : 0x832CB720
// RVA : 0x012CB720
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::FastArrayOfRepRecs::Reserve(bfx::FastArrayOfRepRecs *this, int count)
{
  if ( count > this->m_cap )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_pRecs);
    this->m_pRecs = (bfx::RepRec *)bfx::MemoryManager::Malloc(
                                     this: bfx::g_pCurInstance->m_pMemoryManager,
                                     size: 48 * count,
                                     tag: bfx::MEM_BFXMOVER);
    this->m_cap = count;
  }
}


// ========================================================================
// ??0WalkerForces@bfx@@QAA@ABVMatrix@1@ABVVec3@1@11111111@Z
// EA  : 0x832CB788
// RVA : 0x012CB788
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

bfx::WalkerForces *__fastcall bfx::WalkerForces::WalkerForces(
        bfx::WalkerForces *this,
        bfx::Vec3 *matU2G,
        const bfx::Vec3 *crowdSteerAccU,
        const bfx::Vec3 *crowdRepulseAccU,
        const bfx::Vec3 *crowdSlideAccU,
        const bfx::Vec3 *flockAccU,
        const bfx::Vec3 *pathAccU,
        const bfx::Vec3 *circularApproachAcc,
        const bfx::Vec3 *goalDecelU,
        const bfx::Vec3 *maxDecelU,
        const bfx::Vec3 *xforceAccU,
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
        const bfx::Vec3 *a28,
        int a29,
        const bfx::Vec3 *a30,
        int a31,
        const bfx::Vec3 *a32)
{
  bfx::Matrix::Rot((bfx::Matrix *)this, result: matU2G, rhs: crowdSteerAccU);
  bfx::Matrix::Rot(this: (bfx::Matrix *)&this->m_crowdRepulseAcc, result: matU2G, rhs: crowdRepulseAccU);
  bfx::Matrix::Rot(this: (bfx::Matrix *)&this->m_crowdSlideAcc, result: matU2G, rhs: crowdSlideAccU);
  bfx::Matrix::Rot(this: (bfx::Matrix *)&this->m_flockAcc, result: matU2G, rhs: flockAccU);
  bfx::Matrix::Rot(this: (bfx::Matrix *)&this->m_pathAcc, result: matU2G, rhs: pathAccU);
  bfx::Matrix::Rot(this: (bfx::Matrix *)&this->m_circularApproachAcc, result: matU2G, rhs: circularApproachAcc);
  bfx::Matrix::Rot(this: (bfx::Matrix *)&this->m_goalDecel, result: matU2G, rhs: a28);
  bfx::Matrix::Rot(this: (bfx::Matrix *)&this->m_maxDecel, result: matU2G, rhs: a30);
  bfx::Matrix::Rot(this: (bfx::Matrix *)&this->m_xforceAcc, result: matU2G, rhs: a32);
  return this;
}


// ========================================================================
// ?GetCurU2G@WalkerImpl@bfx@@ABAABVMatrix@2@XZ
// EA  : 0x832CB840
// RVA : 0x012CB840
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

const bfx::Matrix *__fastcall bfx::WalkerImpl::GetCurU2G(bfx::WalkerImpl *this)
{
  bfx::UPath *m_pUPath; // r11

  m_pUPath = this->m_pUPath;
  if ( m_pUPath != nullptr )
    return &m_pUPath->m_u2g[m_pUPath->m_curIdx];
  else
    return &bfx::IDENTITY;
}


// ========================================================================
// ?GetUPos@WalkerImpl@bfx@@ABA?AVVec3@2@XZ
// EA  : 0x832CB870
// RVA : 0x012CB870
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

bfx::WalkerImpl *__fastcall bfx::WalkerImpl::GetUPos(bfx::WalkerImpl *this, bfx::Vec3 *result)
{
  float m_y; // r11
  bfx::Vec3 *v4; // r31
  const bfx::Vec3 *v5; // r3
  bfx::Matrix *v6; // r3
  bfx::MotionState *v8; // r9
  float v9; // r8
  _BYTE v10[16]; // [sp+50h] [-50h] BYREF
  bfx::Matrix v11; // [sp+60h] [-40h] BYREF

  m_y = result[6].m_y;
  if ( m_y == 0.0 )
  {
    v6 = (bfx::Matrix *)(*(int (__fastcall **)(float *))(LODWORD(result->m_x) + 24))(a1: &v11.m_data[4]);
  }
  else
  {
    v4 = (bfx::Vec3 *)((*(_DWORD *)(LODWORD(m_y) + 4968) << 6) + LODWORD(m_y) + 4008);
    v5 = (const bfx::Vec3 *)(*(int (__fastcall **)(_BYTE *))(LODWORD(result->m_x) + 24))(a1: v10);
    v6 = bfx::Matrix::operator*(this: &v11, result: v4, rhs: v5);
  }
  v8 = (bfx::MotionState *)LODWORD(v6->m_data[1]);
  v9 = v6->m_data[2];
  this->__vftable = (bfx::WalkerImpl_vtbl *)LODWORD(v6->m_data[0]);
  this->m_commonState = v8;
  this->m_pos3D.m_x = v9;
  return this;
}


// ========================================================================
// ?GetUVel@WalkerImpl@bfx@@ABA?AVVec3@2@XZ
// EA  : 0x832CB918
// RVA : 0x012CB918
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

bfx::WalkerImpl *__fastcall bfx::WalkerImpl::GetUVel(bfx::WalkerImpl *this, bfx::Vec3 *result)
{
  float m_y; // r11
  bfx::Matrix *p_m_z; // r11
  bfx::MotionState *v6; // r9
  float v7; // r8
  char v8; // [sp+50h] [-20h] BYREF

  m_y = result[6].m_y;
  if ( m_y == 0.0 )
    p_m_z = (bfx::Matrix *)&result[1].m_z;
  else
    p_m_z = bfx::Matrix::Rot(
              this: (bfx::Matrix *)&v8,
              result: (bfx::Vec3 *)((*(_DWORD *)(LODWORD(m_y) + 4968) << 6) + LODWORD(m_y) + 4008),
              rhs: (bfx::Vec3 *)((char *)result + 20));
  v6 = (bfx::MotionState *)LODWORD(p_m_z->m_data[1]);
  v7 = p_m_z->m_data[2];
  this->__vftable = (bfx::WalkerImpl_vtbl *)LODWORD(p_m_z->m_data[0]);
  this->m_commonState = v6;
  this->m_pos3D.m_x = v7;
  return this;
}


// ========================================================================
// ?GetSurferUPos@WalkerImpl@bfx@@ABA?AVVec3@2@XZ
// EA  : 0x832CB990
// RVA : 0x012CB990
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

bfx::WalkerImpl *__fastcall bfx::WalkerImpl::GetSurferUPos(bfx::WalkerImpl *this, bfx::Vec3 *result)
{
  float m_y; // r11
  bfx::Matrix *v4; // r11
  bfx::MotionState *v6; // r9
  float v7; // r8
  char v8; // [sp+50h] [-20h] BYREF

  m_y = result[6].m_y;
  if ( m_y == 0.0 )
    v4 = (bfx::Matrix *)(LODWORD(result->m_y) + 20);
  else
    v4 = bfx::Matrix::operator*(
           this: (bfx::Matrix *)&v8,
           result: (bfx::Vec3 *)((*(_DWORD *)(LODWORD(m_y) + 4968) << 6) + LODWORD(m_y) + 4008),
           rhs: (const bfx::Vec3 *)(LODWORD(result->m_y) + 20));
  v6 = (bfx::MotionState *)LODWORD(v4->m_data[1]);
  v7 = v4->m_data[2];
  this->__vftable = (bfx::WalkerImpl_vtbl *)LODWORD(v4->m_data[0]);
  this->m_commonState = v6;
  this->m_pos3D.m_x = v7;
  return this;
}


// ========================================================================
// ?UseTurnInPlace@WalkerImpl@bfx@@AAA_NXZ
// EA  : 0x832CBA10
// RVA : 0x012CBA10
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

BOOL __fastcall bfx::WalkerImpl::UseTurnInPlace(bfx::WalkerImpl *this)
{
  bfx::MotionState *m_commonState; // r11

  if ( this->m_disableUTurnMode )
    return true;
  m_commonState = this->m_commonState;
  return !m_commonState->m_pTune->m_turnInPlace.m_enableUTurn
      || m_commonState->m_orientCmd.m_mode > (unsigned int)ORIENT_STRICTLY_IN_TRAVEL_DIR;
}


// ========================================================================
// ?GetInitialConstraint@WalkerImpl@bfx@@EAAXAAVInitialConstraint@2@@Z
// EA  : 0x832CBA68
// RVA : 0x012CBA68
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::WalkerImpl::GetInitialConstraint(bfx::WalkerImpl *this, bfx::InitialConstraint *initialConstraint)
{
  bfx::WalkerImpl::State m_state; // r11

  m_state = this->m_state;
  if ( m_state == PATH_MOVE || m_state == 3 )
    initialConstraint->m_constraintType = CONSTRAINT_NONE;
}


// ========================================================================
// ?PerformRoundedCornering@WalkerImpl@bfx@@AAA_NXZ
// EA  : 0x832CBA88
// RVA : 0x012CBA88
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

int __fastcall bfx::WalkerImpl::PerformRoundedCornering(bfx::WalkerImpl *this)
{
  unsigned __int8 v1; // r11

  if ( !this->m_commonState->m_pTune->m_goalTune.m_useCircularApproach )
    return 0;
  if ( this->m_gotoPosSpec.m_stopAtGoal )
    return 0;
  if ( !this->m_gotoPosSpec.m_orientAtGoalEnable )
    return 0;
  v1 = 1;
  if ( this->m_orbitDisable )
    return 0;
  return v1;
}


// ========================================================================
// bfx::IsVectorBetweenEdges
// EA  : 0x832CBAD0
// RVA : 0x012CBAD0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

int __fastcall bfx::IsVectorBetweenEdges(
        const bfx::Vec3 *vForw,
        const bfx::Vec3 *edge1,
        const bfx::Vec3 *edge2,
        float *a4)
{
  float v4; // r2
  double v5; // fp13
  double v6; // fp12
  int result; // r3

  v5 = *(float *)&vForw;
  v6 = *(float *)&vForw;
  if ( (float)((float)(*(float *)&vForw * edge2->m_z)
             + (float)((float)(edge2->m_y * *(float *)&vForw) + (float)(edge2->m_x * v4))) <= 0.0 )
    return 0;
  if ( (float)((float)(*a4 * v4) + (float)((float)(a4[1] * *(float *)&vForw) + (float)(a4[2] * *(float *)&vForw))) <= 0.0 )
    return 0;
  result = 1;
  if ( (float)((float)((float)((float)(*a4 * (float)v6) - (float)(a4[2] * v4))
                     * (float)((float)(edge2->m_z * v4) - (float)(edge2->m_x * (float)v6)))
             + (float)((float)((float)((float)(a4[2] * (float)v5) - (float)(a4[1] * (float)v6))
                             * (float)((float)(edge2->m_y * (float)v6) - (float)(edge2->m_z * (float)v5)))
                     + (float)((float)((float)(a4[1] * v4) - (float)(*a4 * (float)v5))
                             * (float)((float)(edge2->m_x * (float)v5) - (float)(edge2->m_y * v4))))) < 0.0 )
    return 0;
  return result;
}


// ========================================================================
// ?PushingIntoCorner@WalkerImpl@bfx@@UAAXABVVec3@2@0@Z
// EA  : 0x832CBBA0
// RVA : 0x012CBBA0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::WalkerImpl::PushingIntoCorner(
        bfx::WalkerImpl *this,
        const bfx::Vec3 *edge1,
        const bfx::Vec3 *edge2,
        long double a4)
{
  char v7; // r11
  bfx::MotionState *m_commonState; // r10
  bfx::Orienter::State m_state; // r11
  char v10; // r11
  bool v11; // zf
  __int64 v12; // [sp+50h] [-40h] BYREF
  int v13; // [sp+58h] [-38h]

  if ( this->m_vel.m_x != 0.0 || this->m_vel.m_y != 0.0 || (v7 = 1, this->m_vel.m_z != 0.0) )
    v7 = 0;
  if ( v7 == 0
    && (unsigned __int8)bfx::IsVectorBetweenEdges(
                          vForw: (const bfx::Vec3 *)LODWORD(this->m_vel.m_y),
                          edge1: (const bfx::Vec3 *)__ROL4__(LODWORD(this->m_vel.m_z), 32),
                          edge2: edge1,
                          a4: &edge2->m_x) == 0 )
  {
    this->m_vel.m_x = 0.0;
    this->m_vel.m_y = 0.0;
    this->m_vel.m_z = 0.0;
  }
  m_commonState = this->m_commonState;
  m_state = m_commonState->m_orienter.m_state;
  if ( m_state == FACE_TARGET || (v11 = m_state != FACE_IN_DIR, v10 = 0, !v11) )
    v10 = 1;
  if ( this->m_state == PATH_MOVE && v10 == 0 )
  {
    bfx::Orienter::GetForward(this: (bfx::Orienter *)&v12, result: (bfx::Vec3 *)&m_commonState->m_orienter, a3: a4);
    if ( (unsigned __int8)bfx::IsVectorBetweenEdges(
                            vForw: (const bfx::Vec3 *)v12,
                            edge1: (const bfx::Vec3 *)__ROL4__(v13, 32),
                            edge2: edge1,
                            a4: &edge2->m_x) == 0 )
      this->StopAndTurnInPlaceWhenStuck(this);
  }
}


// ========================================================================
// ?SwitchState@WalkerImpl@bfx@@AAAXW4State@12@@Z
// EA  : 0x832CBCB8
// RVA : 0x012CBCB8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::WalkerImpl::SwitchState(bfx::WalkerImpl *this, bfx::WalkerImpl::State newState)
{
  bfx::MotionState *m_commonState; // r10
  unsigned int m_mode; // r11
  bfx::UPath *m_pUPath; // r11
  bfx::Vec3 *v7; // r4
  bfx::Orienter *p_m_orienter; // r3
  const bfx::Vec3 *v9; // r3
  double m_x; // fp0
  double m_y; // fp13
  double m_z; // fp12
  bfx::MotionState *v13; // r11
  bfx::WalkerImpl::State m_state; // r11
  bfx::Vec3 v15; // [sp+50h] [-90h] BYREF
  bfx::Matrix v16; // [sp+60h] [-80h] BYREF

  m_commonState = this->m_commonState;
  m_mode = m_commonState->m_orientCmd.m_mode;
  if ( m_mode <= 1 )
  {
    switch ( newState )
    {
      case 1:
        m_pUPath = this->m_pUPath;
        if ( m_pUPath != nullptr )
          v7 = (bfx::Vec3 *)&m_pUPath->m_u2g[m_pUPath->m_curIdx];
        else
          v7 = (bfx::Vec3 *)&bfx::IDENTITY;
        bfx::Matrix::operator*(this: &v16, result: v7, rhs: &this->m_targetPosU);
        bfx::Orienter::FaceTarget(this: &this->m_commonState->m_orienter, targetPos: (const bfx::Vec3 *)&v16);
        this->m_vel.m_x = 0.0;
        this->m_vel.m_y = 0.0;
        this->m_vel.m_z = 0.0;
        break;
      case 2:
        p_m_orienter = &m_commonState->m_orienter;
        if ( m_mode != 0 )
          bfx::Orienter::FaceStrictlyInTravelDir(this: p_m_orienter);
        else
          idThrowableFilter::InternalPostFilterItems(this: p_m_orienter);
        break;
      case 3:
        if ( (unsigned __int8)bfx::WalkerImpl::PerformRoundedCornering(this) != 0 )
        {
          m_x = this->m_goalData.m_goalDir.m_x;
          m_y = this->m_goalData.m_goalDir.m_y;
          m_z = this->m_goalData.m_goalDir.m_z;
        }
        else
        {
          v9 = this->GetPos(this: &v16, result: this);
          bfx::Orienter::CalcMat(this: &this->m_commonState->m_orienter, pos: v9, mat: (bfx::Matrix *)&v16.m_data[4]);
          m_x = v16.m_data[4];
          m_y = v16.m_data[5];
          m_z = v16.m_data[6];
        }
        v15.m_z = m_z;
        v13 = this->m_commonState;
        v15.m_y = m_y;
        v15.m_x = m_x;
        bfx::Orienter::FaceInDir(this: &v13->m_orienter, dir: &v15);
        break;
      default:
        break;
    }
  }
  if ( this->m_state == 4 )
  {
    this->m_onFinalRotationAction.m_restartGotoPos = false;
    this->m_onFinalRotationAction.m_changeOrientMode = false;
  }
  if ( newState == 4 )
  {
    bfx::Orienter::FaceInDir(this: &this->m_commonState->m_orienter, dir: &this->m_goalData.m_goalDir);
  }
  else if ( newState == PATH_MOVE )
  {
    m_state = this->m_state;
    this->m_startupAccelTimer = 0.0;
    this->m_disableUTurnMode = false;
    this->m_useStartupAccel = true;
    if ( m_state != PATH_MOVE && m_state != 3 )
    {
      this->m_distMoved = 0.0;
      this->m_firstFrameOfMovement = true;
    }
  }
  this->m_orbitDirection = 0.0;
  this->m_orbitSpeed = 0.0;
  this->m_orbitMinDist = -1.0;
  this->m_orbitCenter.m_x = 0.0;
  this->m_orbitCenter.m_y = 0.0;
  this->m_orbitCenter.m_z = 0.0;
  this->m_orbitDisable = false;
  this->m_orbitRadius = 0.0;
  this->m_state = newState;
  this->m_orbitGoalDirection = 0.0;
  this->m_orbitPrevMinDist = -1.0;
}


// ========================================================================
// ?UpdateBlockageState@WalkerImpl@bfx@@AAAXABVFastArrayOfRepRecs@2@@Z
// EA  : 0x832CBE98
// RVA : 0x012CBE98
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::WalkerImpl::UpdateBlockageState(bfx::WalkerImpl *this, const bfx::FastArrayOfRepRecs *repRecs)
{
  bfx::MotionState *m_commonState; // r7
  int m_size; // r8
  double v6; // fp11
  bfx::RepRec *m_pRecs; // r10
  double v8; // fp9
  char v9; // r6
  int v10; // r9
  double v11; // fp10
  double v12; // fp8
  double v13; // fp7
  float *p_m_outerCushion; // r11
  float m_x; // r4
  float m_z; // r3
  float v17; // [sp+50h] [-30h] BYREF
  float m_y; // [sp+54h] [-2Ch]
  float v19; // [sp+58h] [-28h]

  if ( this->m_commonState->m_blockedMonitor.m_blockedTimer > 2.0 )
  {
    bfx::WalkerImpl::GetUPos(this: (bfx::WalkerImpl *)&v17, result: (bfx::Vec3 *)this);
    m_commonState = this->m_commonState;
    m_size = repRecs->m_size;
    v6 = v17;
    m_pRecs = repRecs->m_pRecs;
    v8 = m_y;
    v9 = 0;
    v10 = 0;
    v11 = (float)(this->m_targetPosU.m_x - v17);
    v12 = (float)(this->m_targetPosU.m_y - m_y);
    v13 = (float)((float)(m_commonState->m_pTune->m_radiusData.m_innerCushion
                        + m_commonState->m_pTune->m_radiusData.m_outerCushion)
                + m_commonState->m_pTune->m_radiusData.m_radius);
    if ( m_size > 0 )
    {
      p_m_outerCushion = &m_pRecs->m_radiusDat.m_outerCushion;
      while ( 1 )
      {
        m_x = m_pRecs->m_pos.m_x;
        m_z = m_pRecs->m_pos.m_z;
        m_y = m_pRecs->m_pos.m_y;
        v17 = m_x;
        v19 = m_z;
        if ( (float)((float)((float)(m_y - (float)v8) * (float)v12) + (float)((float)(m_x - (float)v6) * (float)v11)) > 0.0
          && __fsqrts((float)((float)((float)(m_y - (float)v8) * (float)(m_y - (float)v8))
                            + (float)((float)(m_x - (float)v6) * (float)(m_x - (float)v6)))) < (float)((float)((float)v13 * (float)0.5) + (float)((float)((float)(*p_m_outerCushion + *(p_m_outerCushion - 1)) + p_m_outerCushion[1]) + (float)v13)) )
        {
          break;
        }
        ++v10;
        ++m_pRecs;
        p_m_outerCushion += 12;
        if ( v10 >= m_size )
          goto LABEL_9;
      }
      v9 = 1;
    }
LABEL_9:
    if ( v9 == 0 )
      m_commonState->m_blockedMonitor.m_blockedTimer = 0.0;
  }
}


// ========================================================================
// ?GetOrbitTangentToMe@bfx@@YAMABVVec3@1@0MPAVArea@1@@Z
// EA  : 0x832CBFF8
// RVA : 0x012CBFF8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

float __fastcall bfx::GetOrbitTangentToMe(
        const bfx::Vec3 *uMyPos,
        const bfx::Vec3 *sideVec,
        double desiredRadius,
        bfx::Area *pUGoalArea,
        bfx::Vec3 *a5)
{
  double v5; // fp10
  double m_x; // fp9
  double m_z; // fp8
  double v8; // fp31
  double m_y; // fp7
  int v15; // r10
  int v16; // r9
  int v17; // r8
  const bfx::PathSpec *v18; // r5
  double v19; // fp7
  double v20; // fp2
  double v21; // fp9
  double v22; // fp6
  double v23; // fp4
  double v24; // fp1
  int v26; // [sp+8h] [-C8h]
  int v27; // [sp+Ch] [-C4h]
  int v28; // [sp+10h] [-C0h]
  bfx::NavProbeDisplayData *v29; // [sp+14h] [-BCh]
  bfx::Vec3 v30; // [sp+50h] [-80h] BYREF
  bfx::Vec3 v31; // [sp+60h] [-70h] BYREF
  float v32; // [sp+70h] [-60h] BYREF
  float v33; // [sp+74h] [-5Ch]
  float v34; // [sp+78h] [-58h]
  bfx::Array<bfx::PathSeg> v35; // [sp+80h] [-50h] BYREF
  char v36; // [sp+90h] [-40h]
  int v37; // [sp+94h] [-3Ch]
  float v38; // [sp+98h] [-38h]

  v5 = (float)(sideVec->m_y * sideVec->m_y);
  m_x = sideVec->m_x;
  m_z = sideVec->m_z;
  v8 = desiredRadius;
  m_y = sideVec->m_y;
  v35.m_tag = MEM_DEFAULT;
  v36 = 0;
  v38 = 0.0;
  v37 = -1;
  _FP2 = (float)((float)__fsqrts((float)((float)((float)m_z * (float)m_z)
                                       + (float)((float)((float)m_x * (float)m_x) + (float)v5)))
               - (float)1.0842022e-19);
  __asm { fsel      f12, f2, f13, f0 }
  v31.m_x = (float)m_x * (float)_FP12;
  v31.m_y = (float)_FP12 * (float)m_y;
  v31.m_z = (float)_FP12 * (float)m_z;
  bfx::RayCastThroughAreas(
    pStartArea: a5,
    origStartPos: uMyPos,
    dir: &v31,
    dist: (float)((float)desiredRadius * (float)2.0),
    pathSpec: (const bfx::PathSpec *)0xFFFFFFFF,
    rayCastData: &bfx::g_defaultPathSpec,
    pPathOut: &v35,
    a8: nullptr);
  if ( v36 != 0 )
  {
    v8 = (float)(v38 * (float)0.5);
    v19 = uMyPos->m_z;
    v20 = (float)(uMyPos->m_y + (float)(v31.m_y * (float)(v38 * (float)0.5)));
    v30.m_x = uMyPos->m_x + (float)(v31.m_x * (float)(v38 * (float)0.5));
    v30.m_y = v20;
    v30.m_z = (float)v19 + (float)(v31.m_z * (float)(v38 * (float)0.5));
  }
  else
  {
    v21 = (float)((float)v8 * sideVec->m_z);
    v22 = uMyPos->m_z;
    v23 = (float)(uMyPos->m_y + (float)((float)v8 * sideVec->m_y));
    v30.m_x = uMyPos->m_x + (float)(sideVec->m_x * (float)v8);
    v30.m_y = v23;
    v30.m_z = (float)v22 + (float)v21;
  }
  if ( (unsigned __int8)bfx::CheckCircleFit_Internal(
                          pStartArea: (bfx::NavProbeDisplayData *)a5,
                          startPos: &v30,
                          maxSearchDist: v8,
                          pathSpec: v18,
                          closestPerimeterPosOut: &bfx::g_defaultPathSpec,
                          a6: &v32,
                          a7: v17,
                          a8: v16,
                          a9: v15,
                          a10: v26,
                          a11: v27,
                          a12: v28,
                          a13: v29) != 0 )
    v24 = v8;
  else
    v24 = __fsqrts((float)((float)((float)(v32 - v30.m_x) * (float)(v32 - v30.m_x))
                         + (float)((float)((float)(v34 - v30.m_z) * (float)(v34 - v30.m_z))
                                 + (float)((float)(v33 - v30.m_y) * (float)(v33 - v30.m_y)))));
  return *((float *)&v24 + 1);
}


// ========================================================================
// ?ShouldExitGoalApproach@WalkerImpl@bfx@@AAA_NABVVec3@2@0_N@Z
// EA  : 0x832CC1D0
// RVA : 0x012CC1D0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

BOOL __fastcall bfx::WalkerImpl::ShouldExitGoalApproach(
        bfx::WalkerImpl *this,
        const bfx::Vec3 *ugoalPos,
        const bfx::Vec3 *ugoalApproachPos,
        bool performRoundedCornering)
{
  double v8; // fp30
  double v9; // fp29
  double v10; // fp28
  long double v11; // fp2
  double v16; // fp26
  const bfx::MoverTune *m_pTune; // r10
  double v19; // fp5
  long double v20; // fp2
  double v21; // fp0
  double v22; // fp8
  double v23; // fp10
  float v26; // [sp+50h] [-70h] BYREF
  float v27; // [sp+54h] [-6Ch]
  float v28; // [sp+58h] [-68h]

  bfx::WalkerImpl::GetSurferUPos(this: (bfx::WalkerImpl *)&v26, result: (bfx::Vec3 *)this);
  v8 = (float)(ugoalApproachPos->m_y - v27);
  v9 = (float)(ugoalApproachPos->m_z - v28);
  v10 = (float)(ugoalApproachPos->m_x - v26);
  *((double *)&v11 + 1) = (float)(ugoalPos->m_x - v26);
  _FP10 = (float)((float)__fsqrts((float)((float)((float)(ugoalPos->m_x - v26) * (float)(ugoalPos->m_x - v26))
                                        + (float)((float)((float)(ugoalPos->m_z - v28) * (float)(ugoalPos->m_z - v28))
                                                + (float)((float)(ugoalPos->m_y - v27) * (float)(ugoalPos->m_y - v27)))))
                - (float)1.0842022e-19);
  _FP7 = (float)((float)__fsqrts((float)((float)((float)(ugoalApproachPos->m_x - v26)
                                               * (float)(ugoalApproachPos->m_x - v26))
                                       + (float)((float)((float)(ugoalApproachPos->m_z - v28)
                                                       * (float)(ugoalApproachPos->m_z - v28))
                                               + (float)((float)(ugoalApproachPos->m_y - v27)
                                                       * (float)(ugoalApproachPos->m_y - v27)))))
               - (float)1.0842022e-19);
  __asm
  {
    fsel      f4, f10, f9, f31
    fsel      f3, f7, f6, f31
  }
  v16 = (float)((float)((float)((float)_FP3 * (float)(ugoalApproachPos->m_x - v26))
                      * (float)((float)(ugoalPos->m_x - v26) * (float)_FP4))
              + (float)((float)((float)((float)(ugoalApproachPos->m_z - v28) * (float)_FP3)
                              * (float)((float)(ugoalPos->m_z - v28) * (float)_FP4))
                      + (float)((float)((float)(ugoalApproachPos->m_y - v27) * (float)_FP3)
                              * (float)((float)(ugoalPos->m_y - v27) * (float)_FP4))));
  if ( performRoundedCornering )
  {
    m_pTune = this->m_commonState->m_pTune;
    if ( m_pTune->m_goalTune.m_preferredTurningRadius >= (double)m_pTune->m_radiusData.m_radius
      && this->m_orbitRadius < (double)(float)(m_pTune->m_radiusData.m_radius * (float)0.5) )
    {
      return true;
    }
    v19 = (float)(this->m_orbitRadius * (float)0.89999998);
    *((double *)&v11 + 1) = (float)((float)((float)(v28 - this->m_orbitCenter.m_z)
                                          * (float)(v28 - this->m_orbitCenter.m_z))
                                  + (float)((float)(v27 - this->m_orbitCenter.m_y)
                                          * (float)(v27 - this->m_orbitCenter.m_y)));
    if ( (float)((float)((float)(v26 - this->m_orbitCenter.m_x) * (float)(v26 - this->m_orbitCenter.m_x))
               + (float)((float)((float)(v28 - this->m_orbitCenter.m_z) * (float)(v28 - this->m_orbitCenter.m_z))
                       + (float)((float)(v27 - this->m_orbitCenter.m_y) * (float)(v27 - this->m_orbitCenter.m_y)))) < (double)(float)((float)v19 * (float)v19) )
      return true;
  }
  *(_QWORD *)&v11 = 0x3FF38C354AAAAAABLL;
  v20 = cos(x: v11);
  if ( v16 < (float)*(double *)&v20 && (!performRoundedCornering || this->m_orbitDirection != 0.0) )
    return true;
  v21 = (float)(ugoalPos->m_y - ugoalApproachPos->m_y);
  v22 = (float)(ugoalPos->m_z - ugoalApproachPos->m_z);
  v23 = __fsqrts((float)((float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21))
                       + (float)((float)(ugoalPos->m_x - ugoalApproachPos->m_x)
                               * (float)(ugoalPos->m_x - ugoalApproachPos->m_x))));
  if ( performRoundedCornering )
    return v23 < (float)(this->m_commonState->m_pTune->m_radiusData.m_radius * (float)0.1);
  _FP5 = (float)((float)__fsqrts((float)((float)((float)-v21 * (float)-v21)
                                       + (float)((float)(ugoalPos->m_x - ugoalApproachPos->m_x)
                                               * (float)(ugoalPos->m_x - ugoalApproachPos->m_x))))
               - 1.0842022e-19);
  __asm { fsel      f3, f5, f4, f31 }
  return __fabs((float)((float)((float)((float)_FP3 * (float)-v21) * (float)v10)
                      + (float)((float)((float)((float)_FP3 * (float)0.0) * (float)v9)
                              + (float)((float)((float)_FP3 * (float)(ugoalPos->m_x - ugoalApproachPos->m_x)) * (float)v8)))) < (float)((float)v23 * (float)0.25)
      || v23 < (float)(this->m_commonState->m_pTune->m_radiusData.m_radius * (float)0.1);
}


// ========================================================================
// ?UpdateUnwrappedPathIfNeeded@WalkerImpl@bfx@@AAAX_N@Z
// EA  : 0x832CC438
// RVA : 0x012CC438
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::WalkerImpl::UpdateUnwrappedPathIfNeeded(bfx::WalkerImpl *this, bool bForce)
{
  const bfx::Array<bfx::Area *> *PathAreas; // r27
  unsigned int m_pathDataTimestamp; // r26
  bfx::UPath *v6; // r29
  bfx::UPath *m_pUPath; // r29
  bfx::UPath *v8; // r3
  bfx::UPath *v9; // r3
  int v10[16]; // [sp+50h] [-40h] BYREF

  PathAreas = bfx::SmartPath::GetPathAreas(
                this: this->m_commonState->m_pSmartPath,
                numAreasInFirstSurfaceSectionOut: v10);
  m_pathDataTimestamp = this->m_commonState->m_pSmartPath->m_pathDataTimestamp;
  if ( PathAreas != nullptr )
  {
    if ( bForce || m_pathDataTimestamp > this->m_smartPathTimeStampForUnwrappedPath )
    {
      m_pUPath = this->m_pUPath;
      if ( m_pUPath != nullptr )
      {
        bfx::UPath::~UPath(this: this->m_pUPath);
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pUPath->m_pBuf);
      }
      v8 = (bfx::UPath *)bfx::MemoryManager::Malloc(
                           this: bfx::g_pCurInstance->m_pMemoryManager,
                           size: 0x1374u,
                           tag: bfx::MEM_UPATH);
      v10[1] = (int)v8;
      if ( v8 != nullptr )
        v9 = bfx::UPath::UPath(this: v8, areas: PathAreas, startIndex: 0, endIndex: v10[0] - 1);
      else
        v9 = nullptr;
      this->m_pUPath = v9;
      this->m_smartPathTimeStampForUnwrappedPath = m_pathDataTimestamp;
    }
  }
  else
  {
    v6 = this->m_pUPath;
    if ( v6 != nullptr )
    {
      bfx::UPath::~UPath(this: this->m_pUPath);
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v6->m_pBuf);
    }
    this->m_pUPath = nullptr;
    this->m_smartPathTimeStampForUnwrappedPath = 0;
  }
}


// ========================================================================
// __unwind$32754
// EA  : 0x832CC540
// RVA : 0x012CC540
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void _unwind_32754()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(char **)(v0 - 144 + 84), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?GetAccForIntercept@WalkerImpl@bfx@@AAA?AVVec3@2@AAVIntercept@2@@Z
// EA  : 0x832CC570
// RVA : 0x012CC570
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

bfx::WalkerImpl *__fastcall bfx::WalkerImpl::GetAccForIntercept(
        bfx::WalkerImpl *this,
        bfx::Vec3 *result,
        bfx::Intercept *intercept)
{
  const bfx::RepRec *m_pTarget; // r31
  double m_xTime; // fp30
  int v7; // r8
  double v8; // fp21
  float *UPos; // r3
  double m_x; // fp29
  double m_y; // fp28
  double v12; // fp27
  double v13; // fp24
  float *UVel; // r3
  double v15; // fp0
  double v16; // fp7
  double v17; // fp10
  double v18; // fp9
  double v19; // fp12
  double v20; // fp13
  double v21; // fp8
  double v22; // fp4
  double v23; // fp5
  double v24; // fp6
  double v25; // fp22
  double v26; // fp23
  double v27; // fp12
  double v28; // fp25
  double v29; // fp24
  double v30; // fp27
  double v31; // fp12
  double v32; // fp12
  double v33; // fp30
  double v34; // fp5
  double v35; // fp12
  double v36; // fp8
  double v37; // fp7
  double v38; // fp12
  double v39; // fp12
  double v40; // fp0
  double v41; // fp13
  double v42; // fp12
  double v43; // fp0
  bfx::Vec2 *v44; // r3
  double v45; // fp0
  int m_steeringDecision; // r11
  double v47; // fp0
  const bfx::RepulsorImpl *m_pRep; // r10
  double v49; // fp13
  int v51; // r9
  double v52; // fp9
  bfx::Vec2 v53; // [sp+50h] [-A0h] BYREF
  bfx::Vec2 v54[2]; // [sp+58h] [-98h] BYREF
  char v55; // [sp+68h] [-88h] BYREF

  m_pTarget = intercept->m_pTarget;
  m_xTime = intercept->m_xTime;
  v7 = *(_DWORD *)(LODWORD(result->m_y) + 4);
  v53.m_x = 0.0;
  v53.m_y = 0.0;
  v8 = (float)(*(float *)(v7 + 44) * (float)3.0);
  UPos = (float *)bfx::WalkerImpl::GetUPos(this: (bfx::WalkerImpl *)v54, result);
  m_x = m_pTarget->m_pos.m_x;
  m_y = m_pTarget->m_pos.m_y;
  v12 = *UPos;
  v13 = UPos[1];
  UVel = (float *)bfx::WalkerImpl::GetUVel(this: (bfx::WalkerImpl *)&v55, result);
  v15 = *UVel;
  v16 = (float)(*UVel * *UVel);
  v17 = m_pTarget->m_vel.m_x;
  v18 = m_pTarget->m_vel.m_y;
  v19 = (float)(m_pTarget->m_vel.m_x * (float)m_xTime);
  v20 = UVel[1];
  v21 = (float)(m_pTarget->m_vel.m_y * (float)m_xTime);
  v22 = (float)(UVel[1] * (float)m_xTime);
  v23 = (float)(*UVel * (float)m_xTime);
  v54[0].m_x = m_pTarget->m_vel.m_x;
  v54[0].m_y = v18;
  v24 = (float)((float)((float)v20 * (float)v20) + (float)v16);
  v25 = (float)((float)v22 + (float)v13);
  v26 = (float)((float)v23 + (float)v12);
  v28 = (float)((float)((float)v19 + (float)m_x) - (float)v12);
  v27 = __fsqrts(v24);
  v29 = (float)((float)((float)v21 + (float)m_y) - (float)v13);
  if ( v27 >= 1.0842022e-19 )
  {
    v32 = (float)((float)1.0 / (float)v27);
    v30 = (float)((float)v32 * (float)v15);
    v31 = (float)((float)v32 * (float)v20);
  }
  else
  {
    v30 = 0.0;
    v31 = 0.0;
  }
  v33 = -v31;
  v34 = (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17));
  v35 = __fsqrts(v34);
  if ( v35 >= 1.0842022e-19 )
  {
    v38 = (float)((float)1.0 / (float)v35);
    v36 = (float)((float)v38 * (float)v17);
    v37 = (float)((float)v38 * (float)v18);
  }
  else
  {
    v36 = 0.0;
    v37 = 0.0;
  }
  v39 = __fsqrts(v24);
  if ( v39 >= 1.0842022e-19 )
  {
    v42 = (float)((float)1.0 / (float)v39);
    v40 = (float)((float)v42 * (float)v15);
    v41 = (float)((float)v42 * (float)v20);
  }
  else
  {
    v40 = 0.0;
    v41 = 0.0;
  }
  v43 = (float)((float)((float)v41 * (float)v37) + (float)((float)v40 * (float)v36));
  if ( v43 < -0.69999999 || __fsqrts(v34) == 0.0 )
  {
    if ( __fabs((float)((float)((float)((float)v29 * (float)v30) + (float)((float)v33 * (float)v28))
                      / (float)((float)(m_pTarget->m_radiusDat.m_innerCushion + m_pTarget->m_radiusDat.m_outerCushion)
                              + m_pTarget->m_radiusDat.m_radius))) >= 0.1
      || (m_steeringDecision = m_pTarget->m_pRep->m_steeringDecision) == 0 )
    {
      m_steeringDecision = 2;
      if ( (float)((float)((float)v29 * (float)v30) + (float)((float)v33 * (float)v28)) <= 0.0 )
        m_steeringDecision = 1;
    }
    *(_DWORD *)(*(_DWORD *)(LODWORD(result->m_y) + 96) + 108) = m_steeringDecision;
    if ( m_steeringDecision == 1 )
      v47 = 1.0;
    else
      v47 = -1.0;
    v54[0].m_y = (float)((float)v30 * (float)v47) * (float)v8;
    v54[0].m_x = (float)((float)v33 * (float)v47) * (float)v8;
    goto LABEL_29;
  }
  if ( v43 > 0.69999999 )
  {
    v44 = bfx::Vec2::UnitVec(this: &v53, result: v54);
    if ( (float)((float)((float)v29 * (float)v30) + (float)((float)v33 * (float)v28)) > (double)(float)((float)((float)((float)v25 - (float)m_y) * v44->m_x) + (float)((float)((float)v26 - (float)m_x) * (float)-v44->m_y)) )
    {
      v45 = -1.0;
LABEL_16:
      v54[0].m_x = (float)((float)v33 * (float)v45) * (float)v8;
      v54[0].m_y = (float)((float)v30 * (float)v45) * (float)v8;
LABEL_29:
      v53 = v54[0];
      goto LABEL_30;
    }
LABEL_15:
    v45 = 1.0;
    goto LABEL_16;
  }
  if ( *(float *)(*(_DWORD *)(LODWORD(result->m_y) + 4) + 20) < (double)m_pTarget->m_pRep->m_bulk
    || __fsqrts(v24) <= __fsqrts(v34) )
  {
    if ( (float)((float)((float)v18 * (float)v30) + (float)((float)v33 * (float)v17)) > 0.0 )
    {
      v45 = -1.0;
      goto LABEL_16;
    }
    goto LABEL_15;
  }
LABEL_30:
  m_pRep = m_pTarget->m_pRep;
  v49 = v53.m_y;
  v51 = *(_DWORD *)(LODWORD(result->m_y) + 4);
  v52 = (float)(m_pRep->m_bulk / (float)(*(float *)(v51 + 20) + m_pRep->m_bulk));
  *(float *)&this->__vftable = v53.m_x * (float)(m_pRep->m_bulk / (float)(*(float *)(v51 + 20) + m_pRep->m_bulk));
  *(float *)&this->m_commonState = (float)v49 * (float)v52;
  this->m_pos3D.m_x = (float)v52 * (float)0.0;
  return this;
}


// ========================================================================
// ?CalcCrowdSteerAcc@WalkerImpl@bfx@@AAA?AVVec3@2@ABVFastArrayOfRepRecs@2@@Z
// EA  : 0x832CC880
// RVA : 0x012CC880
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

bfx::WalkerImpl *__fastcall bfx::WalkerImpl::CalcCrowdSteerAcc(
        bfx::WalkerImpl *this,
        bfx::Vec3 *result,
        const bfx::FastArrayOfRepRecs *repRecs)
{
  int v4; // r27
  double m_xTime; // fp25
  float *UPos; // r3
  float *UVel; // r3
  bfx::RepRec *m_pRecs; // r29
  double v11; // fp27
  double v12; // fp26
  double v13; // fp22
  float *p_m_innerCushion; // r31
  double m_x; // fp13
  double v16; // fp12
  double v17; // fp11
  double v18; // fp10
  double v19; // fp8
  double v20; // fp2
  double v21; // fp6
  double v22; // fp9
  float *v23; // r11
  double v24; // fp13
  double v25; // fp0
  double v26; // fp13
  double v27; // fp31
  double v28; // fp1
  double v29; // fp1
  double v30; // fp0
  bfx::Vec2 v32; // [sp+50h] [-E0h] BYREF
  bfx::Intercept v33; // [sp+58h] [-D8h] BYREF
  bfx::Vec2 v34; // [sp+60h] [-D0h] BYREF
  bfx::Vec2 v35; // [sp+68h] [-C8h] BYREF
  bfx::Intercept v36; // [sp+70h] [-C0h] BYREF
  char v37; // [sp+80h] [-B0h] BYREF

  v4 = 0;
  v33.m_pTarget = nullptr;
  m_xTime = 3.4028235e38;
  UPos = (float *)bfx::WalkerImpl::GetUPos(this: (bfx::WalkerImpl *)&v36, result);
  v32.m_x = *UPos;
  v32.m_y = UPos[1];
  UVel = (float *)bfx::WalkerImpl::GetUVel(this: (bfx::WalkerImpl *)&v37, result);
  m_pRecs = repRecs->m_pRecs;
  v11 = *UVel;
  v12 = UVel[1];
  v13 = (float)((float)((float)(v32.m_y - result[5].m_z) * (float)(v32.m_y - result[5].m_z))
              + (float)((float)(v32.m_x - result[5].m_y) * (float)(v32.m_x - result[5].m_y)));
  if ( repRecs->m_size <= 0 )
    goto LABEL_17;
  p_m_innerCushion = &m_pRecs->m_radiusDat.m_innerCushion;
  do
  {
    m_x = m_pRecs->m_pos.m_x;
    v34.m_x = m_pRecs->m_pos.m_x;
    v16 = *(p_m_innerCushion - 7);
    v34.m_y = *(p_m_innerCushion - 7);
    v17 = (float)(*(p_m_innerCushion - 5) - (float)v11);
    v18 = (float)(*(p_m_innerCushion - 4) - (float)v12);
    v19 = (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17));
    if ( v19 > 0.0 )
    {
      v20 = (float)((float)v16 - result[5].m_z);
      v21 = (float)((float)((float)v20 * (float)v20)
                  + (float)((float)((float)m_x - result[5].m_y) * (float)((float)m_x - result[5].m_y)));
      if ( result[12].m_y <= (double)(float)((float)(*p_m_innerCushion + *(p_m_innerCushion - 1))
                                           + *(p_m_innerCushion - 2))
        || (v22 = (float)(result[12].m_y
                        - (float)((float)(*p_m_innerCushion + *(p_m_innerCushion - 1)) + *(p_m_innerCushion - 2))),
            v21 >= (float)((float)v22 * (float)v22)) )
      {
        v23 = *(float **)(LODWORD(result->m_y) + 4);
        v24 = (float)((float)((float)(v32.m_y - (float)v16) * (float)(v32.m_y - (float)v16))
                    + (float)((float)(v32.m_x - (float)m_x) * (float)(v32.m_x - (float)m_x)));
        v25 = (float)((float)((float)(v23[4] + v23[3]) + v23[2])
                    + (float)((float)(*p_m_innerCushion + *(p_m_innerCushion - 1)) + *(p_m_innerCushion - 2)));
        if ( v24 >= (float)((float)v25 * (float)v25)
          && v24 <= v13
          && v21 > (float)((float)(*(p_m_innerCushion - 2) * (float)0.5) * (float)(*(p_m_innerCushion - 2) * (float)0.5)) )
        {
          v26 = __fsqrts(v19);
          v27 = (float)((float)1.0 / (float)v26);
          v28 = (float)((float)((float)((float)(v23[4] + v23[3]) + v23[2])
                              + (float)((float)(*p_m_innerCushion + *(p_m_innerCushion - 1)) + *(p_m_innerCushion - 2)))
                      * (float)0.99000001);
          v35.m_x = (float)((float)1.0 / (float)v26) * (float)(*(p_m_innerCushion - 5) - (float)v11);
          v35.m_y = (float)((float)1.0 / (float)v26) * (float)v18;
          v29 = bfx::CollideLineAndCircle(lineStart: &v34, normalizedLineDir: &v35, circlePos: &v32, radius: v28);
          if ( v29 < 3.4028235e38 )
          {
            v30 = (float)((float)v27 * (float)v29);
            if ( v30 >= 0.0 && v30 < 3.0 && v30 < m_xTime )
            {
              v36.m_pTarget = m_pRecs;
              v36.m_xTime = (float)v27 * (float)v29;
              m_xTime = v36.m_xTime;
              v33 = v36;
            }
          }
        }
      }
    }
    ++v4;
    ++m_pRecs;
    p_m_innerCushion += 12;
  }
  while ( v4 < repRecs->m_size );
  if ( v33.m_pTarget != nullptr )
  {
    bfx::WalkerImpl::GetAccForIntercept(this, result, intercept: &v33);
    return this;
  }
  else
  {
LABEL_17:
    *(bfx::Vec3 *)&this->__vftable = bfx::ZERO_VEC;
    return this;
  }
}


// ========================================================================
// ?CalcMaxDecel@WalkerImpl@bfx@@AAA?AVVec3@2@M@Z
// EA  : 0x832CCAF8
// RVA : 0x012CCAF8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

bfx::WalkerImpl *__fastcall bfx::WalkerImpl::CalcMaxDecel(bfx::WalkerImpl *this, bfx::Vec3 *result, double simTime)
{
  double v6; // fp2
  double v7; // fp3
  double v8; // fp31
  double v9; // fp30
  double v10; // fp29
  double v11; // fp1
  float m_y; // r8
  float m_z; // r7
  float v15; // [sp+50h] [-40h] BYREF
  float v16; // [sp+54h] [-3Ch]
  float v17; // [sp+58h] [-38h]

  bfx::WalkerImpl::GetUVel(this: (bfx::WalkerImpl *)&v15, result);
  v6 = __fsqrts((float)((float)(v15 * v15) + (float)((float)(v16 * v16) + (float)(v17 * v17))));
  if ( v6 <= 1.0842022e-19 )
  {
    m_y = bfx::ZERO_VEC.m_y;
    m_z = bfx::ZERO_VEC.m_z;
    this->__vftable = (bfx::WalkerImpl_vtbl *)LODWORD(bfx::ZERO_VEC.m_x);
    *(float *)&this->m_commonState = m_y;
    this->m_pos3D.m_x = m_z;
  }
  else
  {
    v7 = simTime;
    v8 = (float)((float)((float)1.0 / (float)v6) * v15);
    v9 = (float)((float)((float)1.0 / (float)v6) * v16);
    v10 = (float)((float)((float)1.0 / (float)v6) * v17);
    v11 = bfx::LimitDecelToPreventOvershoot(
            decel: *(float *)(*(_DWORD *)(LODWORD(result->m_y) + 4) + 28),
            speed: v6,
            simTime: v7);
    v15 = (float)v8 * (float)-v11;
    v16 = (float)v9 * (float)-v11;
    v17 = (float)v10 * (float)-v11;
    this->m_pos3D.m_x = v17;
    *(float *)&this->m_commonState = (float)v9 * (float)-v11;
    *(float *)&this->__vftable = (float)v8 * (float)-v11;
  }
  return this;
}


// ========================================================================
// ?SlowForCrowds@WalkerImpl@bfx@@AAAXABVFastArrayOfRepRecs@2@@Z
// EA  : 0x832CCC08
// RVA : 0x012CCC08
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::WalkerImpl::SlowForCrowds(bfx::WalkerImpl *this, const bfx::FastArrayOfRepRecs *repRecs)
{
  const bfx::MoverTune *m_pTune; // r22
  int v5; // r21
  long double v6; // fp2
  bfx::UPath *m_pUPath; // r11
  bfx::Vec3 *v8; // r31
  int v9; // r27
  bfx::RepRec *m_pRecs; // r29
  double v11; // fp6
  double v12; // fp26
  double m_z; // fp30
  double m_y; // fp29
  double m_x; // fp28
  float v16; // r26
  float v17; // r25
  float *p_m_z; // r31
  float v19; // r24
  double v20; // fp31
  float *UVel; // r3
  float *v22; // r3
  float *v23; // r3
  double v24; // fp8
  double v25; // fp6
  double v26; // fp9
  double DistPtToLineSeg; // fp1
  bfx::MotionState *m_commonState; // r9
  bfx::Vec3 v29; // [sp+50h] [-120h] BYREF
  bfx::Matrix v30; // [sp+60h] [-110h] BYREF
  char v31; // [sp+A0h] [-D0h] BYREF
  bfx::LineSeg v32; // [sp+B0h] [-C0h] BYREF

  m_pTune = this->m_commonState->m_pTune;
  if ( repRecs->m_size != 0 && m_pTune->m_cautionTune.m_speedX != 1.0 )
  {
    v5 = 0;
    bfx::WalkerImpl::GetUPos(this: (bfx::WalkerImpl *)&v29, result: (bfx::Vec3 *)this);
    m_pUPath = this->m_pUPath;
    v8 = (bfx::Vec3 *)(m_pUPath != nullptr ? &m_pUPath->m_g2u[m_pUPath->m_curIdx] : &bfx::IDENTITY);
    bfx::Orienter::GetForward(
      this: (bfx::Orienter *)&v30.m_data[4],
      result: (bfx::Vec3 *)&this->m_commonState->m_orienter,
      a3: v6);
    bfx::Matrix::Rot(this: &v30, result: v8, rhs: (const bfx::Vec3 *)&v30.m_data[4]);
    v9 = 0;
    m_pRecs = repRecs->m_pRecs;
    v11 = __fsqrts((float)((float)(this->m_vel.m_z * this->m_vel.m_z)
                         + (float)((float)(this->m_vel.m_x * this->m_vel.m_x)
                                 + (float)(this->m_vel.m_y * this->m_vel.m_y))));
    v12 = (float)((float)((float)((float)v11 / m_pTune->m_startStopAcc) * (float)v11) * (float)0.5);
    if ( repRecs->m_size > 0 )
    {
      m_z = v29.m_z;
      m_y = v29.m_y;
      m_x = v29.m_x;
      v16 = v29.m_z;
      v17 = v29.m_y;
      p_m_z = &m_pRecs->m_vel.m_z;
      v19 = v29.m_x;
      do
      {
        if ( (float)((float)((float)(m_pRecs->m_pos.m_x - (float)m_x) * v30.m_data[0])
                   + (float)((float)(v30.m_data[2] * (float)(*(p_m_z - 3) - (float)m_z))
                           + (float)(v30.m_data[1] * (float)(*(p_m_z - 4) - (float)m_y)))) > 0.0 )
        {
          v20 = 1.0;
          UVel = (float *)bfx::WalkerImpl::GetUVel(this: (bfx::WalkerImpl *)&v30.m_data[8], result: (bfx::Vec3 *)this);
          if ( (float)((float)(UVel[2] * UVel[2]) + (float)((float)(*UVel * *UVel) + (float)(UVel[1] * UVel[1]))) > (double)(float)((float)v12 * (float)v12) )
          {
            v22 = (float *)bfx::WalkerImpl::GetUVel(this: (bfx::WalkerImpl *)&v30.m_data[12], result: (bfx::Vec3 *)this);
            v20 = (float)((float)v12
                        / (float)__fsqrts((float)((float)(v22[2] * v22[2])
                                                + (float)((float)(*v22 * *v22) + (float)(v22[1] * v22[1])))));
          }
          v23 = (float *)bfx::WalkerImpl::GetUVel(this: (bfx::WalkerImpl *)&v31, result: (bfx::Vec3 *)this);
          v24 = (float)(*v23 - *(p_m_z - 2));
          v25 = (float)(v23[1] - *(p_m_z - 1));
          v26 = (float)(v23[2] - *p_m_z);
          v32.m_v0.m_x = v19;
          v32.m_v0.m_y = v17;
          v32.m_v0.m_z = v16;
          v29.m_x = (float)((float)v24 * (float)v20) + (float)m_x;
          v29.m_y = (float)((float)v25 * (float)v20) + (float)m_y;
          v29.m_z = (float)((float)v26 * (float)v20) + (float)m_z;
          v32.m_v1 = v29;
          DistPtToLineSeg = bfx::GetDistPtToLineSeg(pos: &m_pRecs->m_pos, seg: &v32);
          if ( DistPtToLineSeg != 3.4028235e38
            && DistPtToLineSeg < (float)((float)(m_pTune->m_radiusData.m_radius + p_m_z[1]) * (float)2.0) )
          {
            ++v5;
          }
        }
        ++v9;
        ++m_pRecs;
        p_m_z += 12;
      }
      while ( v9 < repRecs->m_size );
      if ( v5 != 0 )
      {
        this->m_commonState->m_cautionData.m_internalSpeedX = m_pTune->m_cautionTune.m_speedX;
        m_commonState = this->m_commonState;
        this->m_debugData.m_slowedForCrowds = true;
        m_commonState->m_cautionData.m_radius = v12;
      }
    }
  }
}


// ========================================================================
// ?DrawTurningRadius@WalkerImpl@bfx@@ABAXXZ
// EA  : 0x832CCEB0
// RVA : 0x012CCEB0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::WalkerImpl::DrawTurningRadius(bfx::WalkerImpl *this)
{
  double v2; // fp6
  double v3; // fp31
  const bfx::Color *v4; // r5
  const bfx::Color *v5; // r5
  bfx::Vec3 v6; // [sp+50h] [-110h] BYREF
  bfx::Vec3 v7; // [sp+60h] [-100h] BYREF
  bfx::Matrix v8; // [sp+70h] [-F0h] BYREF
  bfx::Matrix v9; // [sp+B0h] [-B0h] BYREF
  bfx::Matrix v10; // [sp+F0h] [-70h] BYREF

  v2 = __fsqrts((float)((float)(this->m_vel.m_z * this->m_vel.m_z)
                      + (float)((float)(this->m_vel.m_x * this->m_vel.m_x) + (float)(this->m_vel.m_y * this->m_vel.m_y))));
  v3 = (float)((float)((float)v2 * (float)v2) / (float)(this->m_commonState->m_pTune->m_pathAcc * (float)3.0));
  this->GetMatrix(this, a2: &v8);
  v9 = v8;
  v6.m_y = v3;
  v6.m_x = (float)v3 * (float)0.0;
  v6.m_z = v6.m_x;
  bfx::Matrix::PreTrans(this: &v9, offset: &v6);
  v10 = v8;
  v7.m_x = (float)v3 * (float)0.0;
  v7.m_z = v7.m_x;
  v7.m_y = (float)v3 * (float)-1.0;
  bfx::Matrix::PreTrans(this: &v10, offset: &v7);
  bfx::DrawCircle(
    pSpace: this->m_commonState->m_pSpace,
    mat: (bfx::Vec3 *)&v9,
    radius: v3,
    color: v4,
    a5: &ColorOrange_28);
  bfx::DrawCircle(
    pSpace: this->m_commonState->m_pSpace,
    mat: (bfx::Vec3 *)&v10,
    radius: v3,
    color: v5,
    a5: &ColorOrange_28);
}


// ========================================================================
// ?NeedToTurnToSatisfyGoalDir@WalkerImpl@bfx@@AAA_NXZ
// EA  : 0x832CCFE0
// RVA : 0x012CCFE0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

int __fastcall bfx::WalkerImpl::NeedToTurnToSatisfyGoalDir(bfx::WalkerImpl *this)
{
  double v2; // fp1
  int result; // r3

  if ( !this->m_goalData.m_applyGoalDir )
    return 0;
  v2 = bfx::Orienter::CalcHeadingErrorFromDir(
         this: &this->m_commonState->m_orienter,
         desiredFacingVec: &this->m_goalData.m_goalDir);
  result = 1;
  if ( __fabs(v2) <= (float)(this->m_goalData.m_finalTurnInPlaceAngleThreshold * (float)0.017453292) )
    return 0;
  return result;
}


// ========================================================================
// ?CalcGoalDecel@WalkerImpl@bfx@@AAA?AVVec3@2@_NM@Z
// EA  : 0x832CD048
// RVA : 0x012CD048
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

bfx::WalkerImpl *__fastcall bfx::WalkerImpl::CalcGoalDecel(
        bfx::WalkerImpl *this,
        bfx::WalkerImpl *result,
        bool targetPosIsGoal,
        double simTime)
{
  int m_dirty; // r11
  char v7; // r8
  float v8; // r9
  bfx::Vec3 *p_m_isGoal; // r10
  float v10; // r11
  const bfx::MoverTune *m_pTune; // r29
  bfx::Matrix *v12; // r3
  double v13; // fp24
  double v14; // fp21
  double v15; // fp26
  double v16; // fp20
  double m_x; // fp14
  double v18; // fp25
  double v19; // fp9
  bfx::Vec3 *p_m_gotoPosSpec; // r11
  double v21; // fp10
  float v22; // ctr
  double v23; // fp11
  double v24; // fp0
  double v25; // fp8
  double v26; // fp13
  double v27; // fp3
  float v28; // r11
  bfx::Matrix *v29; // r3
  float v30; // r8
  float v31; // r7
  double v32; // fp12
  double v33; // fp31
  double v34; // fp15
  double v35; // fp19
  double v36; // fp18
  double v37; // fp17
  double v38; // fp30
  double v39; // fp29
  double v40; // fp28
  double v41; // fp23
  double v42; // fp22
  double v43; // fp21
  double v44; // fp26
  double v49; // fp1
  double v50; // fp6
  double v51; // fp5
  double v52; // fp4
  double v55; // fp11
  double v56; // fp0
  double v57; // fp13
  double v58; // fp12
  float v62; // r7
  float v63; // r8
  float v64; // [sp+50h] [-E0h]
  float v65; // [sp+5Ch] [-D4h]
  float m_y; // [sp+5Ch] [-D4h]
  float v67; // [sp+60h] [-D0h]
  float m_z; // [sp+60h] [-D0h]
  bfx::Matrix v69[2]; // [sp+68h] [-C8h] BYREF
  float v70; // [sp+15Ch] [+2Ch]

  m_dirty = result->m_cornerCacheU.m_dirty;
  v70 = simTime;
  v7 = 0;
  if ( !result->m_cornerCacheU.m_dirty )
  {
    v8 = *(float *)&result->m_cornerCacheU.m_numCornersInCache;
    if ( SLODWORD(v8) > 0 )
    {
      p_m_isGoal = (bfx::Vec3 *)&result->m_cornerCacheU.m_corners[0].m_isGoal;
      while ( HIBYTE(p_m_isGoal->m_x) == 0 )
      {
        ++m_dirty;
        p_m_isGoal += 3;
        if ( m_dirty >= SLODWORD(v8) )
          goto LABEL_8;
      }
      v7 = 1;
    }
  }
LABEL_8:
  if ( !targetPosIsGoal && v7 == 0 )
    goto LABEL_34;
  v10 = *(float *)&result->m_pUPath;
  m_pTune = result->m_commonState->m_pTune;
  v12 = v10 == 0.0
      ? (bfx::Matrix *)&result->m_vel
      : bfx::Matrix::Rot(
          this: v69,
          result: (bfx::Vec3 *)((*(_DWORD *)(LODWORD(v10) + 4968) << 6) + LODWORD(v10) + 4008),
          rhs: &result->m_vel);
  v65 = v12->m_data[1];
  v13 = v65;
  v14 = v12->m_data[0];
  v67 = v12->m_data[2];
  v15 = v67;
  v16 = (float)((float)(v12->m_data[0] * v12->m_data[0]) + (float)((float)(v65 * v65) + (float)(v67 * v67)));
  if ( v16 < 1.1754944e-38 )
    goto LABEL_34;
  m_x = result->m_targetPosU.m_x;
  m_y = result->m_targetPosU.m_y;
  m_z = result->m_targetPosU.m_z;
  v18 = 0.0;
  if ( !result->m_cornerCacheU.m_dirty )
  {
    bfx::WalkerImpl::GetSurferUPos(this: (bfx::WalkerImpl *)v69, (bfx::Vec3 *)result);
    if ( result->m_cornerCacheU.m_numCornersInCache > 0 )
    {
      v19 = v69[0].m_data[2];
      p_m_gotoPosSpec = (bfx::Vec3 *)&result->m_gotoPosSpec;
      v21 = v69[0].m_data[1];
      v22 = *(float *)&result->m_cornerCacheU.m_numCornersInCache;
      v23 = v69[0].m_data[0];
      do
      {
        v24 = p_m_gotoPosSpec[2].m_z;
        v25 = (float)(p_m_gotoPosSpec[2].m_z - (float)v21);
        v26 = p_m_gotoPosSpec[2].m_y;
        p_m_gotoPosSpec += 3;
        m_z = p_m_gotoPosSpec->m_x;
        m_y = v24;
        v21 = v24;
        m_x = v26;
        v27 = (float)((float)((float)((float)v26 - (float)v23) * (float)((float)v26 - (float)v23))
                    + (float)((float)((float)(m_z - (float)v19) * (float)(m_z - (float)v19))
                            + (float)((float)v25 * (float)v25)));
        v19 = m_z;
        v23 = v26;
        v18 = (float)((float)__fsqrts(v27) + (float)v18);
        --LODWORD(v22);
      }
      while ( v22 != 0.0 );
    }
  }
  v28 = *(float *)&result->m_pUPath;
  v29 = v28 == 0.0
      ? (bfx::Matrix *)&result->m_commonState->m_surfer.m_pos
      : bfx::Matrix::operator*(
          this: v69,
          result: (bfx::Vec3 *)((*(_DWORD *)(LODWORD(v28) + 4968) << 6) + LODWORD(v28) + 4008),
          rhs: &result->m_commonState->m_surfer.m_pos);
  v30 = v29->m_data[1];
  v31 = v29->m_data[2];
  v32 = (float)(m_pTune->m_pathAcc * (float)3.0);
  v69[0].m_data[0] = v29->m_data[0];
  v69[0].m_data[1] = v30;
  v69[0].m_data[2] = v31;
  v33 = (float)((float)v16 / (float)v32);
  if ( v18 > (float)((float)((float)v16 / (float)v32) * (float)4.0) )
    goto LABEL_34;
  v34 = __fsqrts(v16);
  v35 = v69[0].m_data[1];
  v36 = v69[0].m_data[2];
  v37 = v69[0].m_data[0];
  v38 = (float)(m_y - v69[0].m_data[1]);
  v39 = (float)(m_z - v69[0].m_data[2]);
  v40 = (float)((float)m_x - v69[0].m_data[0]);
  v42 = (float)((float)((float)1.0 / (float)v34) * (float)v15);
  v43 = (float)((float)((float)1.0 / (float)v34) * (float)v14);
  v44 = (float)((float)((float)((float)m_x - v69[0].m_data[0]) * (float)v43)
              + (float)((float)((float)(m_z - v69[0].m_data[2]) * (float)((float)((float)1.0 / (float)v34) * (float)v15))
                      + (float)((float)(m_y - v69[0].m_data[1]) * (float)((float)((float)1.0 / (float)v34) * (float)v13))));
  if ( v44 > 1.0842022e-19 )
  {
    v64 = 0.0;
    if ( v18 < (float)((float)v16 / (float)((float)(m_pTune->m_startStopAcc * (float)0.80000001) * 2.0))
      && (result->m_gotoPosSpec.m_stopAtGoal
       || (unsigned __int8)bfx::WalkerImpl::NeedToTurnToSatisfyGoalDir(this: result) != 0) )
    {
      _FP10 = -(float)((float)((float)v16 / (float)v18) * (float)0.5);
      _FP9 = (float)(m_pTune->m_startStopAcc - (float)((float)((float)v16 / (float)v18) * (float)0.5));
      __asm { fsel      f8, f10, f0, f11 }
      __asm { fsel      f1, f9, f7, f12# decel }
      v64 = bfx::LimitDecelToPreventOvershoot(decel: _FP1, speed: v34, simTime: v70);
    }
    v49 = 0.0;
    v50 = (float)((float)((float)v43 * UNWRAP_UP_VEC_2.m_z) - (float)((float)v42 * UNWRAP_UP_VEC_2.m_x));
    v51 = (float)((float)((float)((float)((float)1.0 / (float)v34) * (float)v13) * UNWRAP_UP_VEC_2.m_x)
                - (float)((float)v43 * UNWRAP_UP_VEC_2.m_y));
    v52 = (float)((float)((float)v42 * UNWRAP_UP_VEC_2.m_y)
                - (float)((float)((float)((float)1.0 / (float)v34) * (float)v13) * UNWRAP_UP_VEC_2.m_z));
    _FP12 = (float)((float)__fsqrts((float)((float)((float)v52 * (float)v52)
                                          + (float)((float)((float)v51 * (float)v51) + (float)((float)v50 * (float)v50))))
                  - 1.0842022e-19);
    __asm { fsel      f9, f12, f11, f16 }
    v41 = (float)((float)((float)1.0 / (float)v34) * (float)v13);
    v55 = (float)((float)((float)v40
                        * (float)((float)((float)((float)v42 * UNWRAP_UP_VEC_2.m_y)
                                        - (float)((float)v41 * UNWRAP_UP_VEC_2.m_z))
                                * (float)_FP9))
                + (float)((float)((float)v39
                                * (float)((float)((float)((float)v41 * UNWRAP_UP_VEC_2.m_x)
                                                - (float)((float)v43 * UNWRAP_UP_VEC_2.m_y))
                                        * (float)_FP9))
                        + (float)((float)v38
                                * (float)((float)((float)((float)v43 * UNWRAP_UP_VEC_2.m_z)
                                                - (float)((float)v42 * UNWRAP_UP_VEC_2.m_x))
                                        * (float)_FP9))));
    if ( __fabs(v55) >= (float)((float)v44 * (float)0.5) )
    {
      if ( v55 <= 0.0 )
      {
        v56 = (float)((float)v37
                    - (float)((float)((float)((float)((float)v42 * UNWRAP_UP_VEC_2.m_y)
                                            - (float)((float)((float)((float)1.0 / (float)v34) * (float)v13)
                                                    * UNWRAP_UP_VEC_2.m_z))
                                    * (float)_FP9)
                            * (float)v33));
        v57 = (float)((float)v35
                    - (float)((float)((float)((float)((float)v43 * UNWRAP_UP_VEC_2.m_z)
                                            - (float)((float)v42 * UNWRAP_UP_VEC_2.m_x))
                                    * (float)_FP9)
                            * (float)v33));
        v58 = (float)((float)v36
                    - (float)((float)((float)((float)((float)((float)((float)1.0 / (float)v34) * (float)v13)
                                                    * UNWRAP_UP_VEC_2.m_x)
                                            - (float)((float)v43 * UNWRAP_UP_VEC_2.m_y))
                                    * (float)_FP9)
                            * (float)v33));
      }
      else
      {
        v56 = (float)((float)((float)((float)((float)((float)v42 * UNWRAP_UP_VEC_2.m_y)
                                            - (float)((float)((float)((float)1.0 / (float)v34) * (float)v13)
                                                    * UNWRAP_UP_VEC_2.m_z))
                                    * (float)_FP9)
                            * (float)v33)
                    + (float)v37);
        v57 = (float)((float)((float)((float)((float)((float)v43 * UNWRAP_UP_VEC_2.m_z)
                                            - (float)((float)v42 * UNWRAP_UP_VEC_2.m_x))
                                    * (float)_FP9)
                            * (float)v33)
                    + (float)v35);
        v58 = (float)((float)((float)((float)((float)((float)((float)((float)1.0 / (float)v34) * (float)v13)
                                                    * UNWRAP_UP_VEC_2.m_x)
                                            - (float)((float)v43 * UNWRAP_UP_VEC_2.m_y))
                                    * (float)_FP9)
                            * (float)v33)
                    + (float)v36);
      }
      if ( (float)((float)((float)((float)v56 - (float)m_x) * (float)((float)v56 - (float)m_x))
                 + (float)((float)((float)((float)v58 - m_z) * (float)((float)v58 - m_z))
                         + (float)((float)((float)v57 - m_y) * (float)((float)v57 - m_y)))) < (double)(float)((float)v33 * (float)v33) )
        v49 = bfx::LimitDecelToPreventOvershoot(decel: m_pTune->m_startStopAcc, speed: v34, simTime: v70);
    }
    _FP13 = (float)(v64 - (float)v49);
    __asm { fsel      f12, f13, f0, f1 }
    *(float *)&this->__vftable = (float)v43 * (float)-_FP12;
    *(float *)&this->m_commonState = (float)((float)((float)1.0 / (float)v34) * (float)v13) * (float)-_FP12;
    this->m_pos3D.m_x = (float)v42 * (float)-_FP12;
    return this;
  }
  else
  {
LABEL_34:
    v62 = bfx::ZERO_VEC.m_z;
    v63 = bfx::ZERO_VEC.m_y;
    this->__vftable = (bfx::WalkerImpl_vtbl *)LODWORD(bfx::ZERO_VEC.m_x);
    this->m_pos3D.m_x = v62;
    *(float *)&this->m_commonState = v63;
    return this;
  }
}


// ========================================================================
// ?EndOfFrameUpdate@WalkerImpl@bfx@@EAAXXZ
// EA  : 0x832CD490
// RVA : 0x012CD490
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::WalkerImpl::EndOfFrameUpdate(bfx::WalkerImpl *this)
{
  bfx::MotionState *m_commonState; // r9
  bfx::Prober *m_pProber; // r10
  bfx::Vec3 *v3; // r11
  double v4; // fp8
  double v5; // fp6
  _DWORD back_chain[4]; // [sp+0h] [-10h] BYREF

  m_commonState = this->m_commonState;
  m_pProber = m_commonState->m_pProber;
  if ( m_pProber != nullptr )
  {
    v3 = (bfx::Vec3 *)back_chain;
    back_chain[2] = LODWORD(m_pProber->m_pos3DOffset.m_z);
  }
  else
  {
    v3 = &bfx::ZERO_VEC;
  }
  v4 = (float)(m_commonState->m_surfer.m_pos.m_y + v3->m_y);
  v5 = (float)(m_commonState->m_surfer.m_pos.m_z + v3->m_z);
  this->m_pos3D.m_x = m_commonState->m_surfer.m_pos.m_x + v3->m_x;
  this->m_pos3D.m_y = v4;
  this->m_pos3D.m_z = v5;
}


// ========================================================================
// ?CalcDistToImpendingCollision@bfx@@YAMABVVec3@1@0MABVFastArrayOfRepRecs@1@@Z
// EA  : 0x832CD500
// RVA : 0x012CD500
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

float __fastcall bfx::CalcDistToImpendingCollision(
        const bfx::Vec3 *upos,
        const bfx::Vec3 *uvel,
        double moverRadius,
        const bfx::FastArrayOfRepRecs *repRecs,
        int a5)
{
  float *v6; // r29
  double v8; // fp23
  int v10; // r28
  double v12; // fp19
  double v14; // fp31
  double v15; // fp29
  double v16; // fp30
  double v17; // fp20
  float *v18; // r31
  float v19; // r10
  float v20; // r9
  double v21; // fp28
  double v22; // fp27
  double v23; // fp26
  double v24; // fp12
  double v25; // fp11
  double m_y; // fp9
  double v27; // fp1
  double v28; // fp4
  double v29; // fp3
  double v30; // fp2
  double v33; // fp1
  bfx::Vec2 v35; // [sp+50h] [-D0h] BYREF
  bfx::Vec2 v36; // [sp+58h] [-C8h] BYREF
  bfx::Vec2 v37; // [sp+60h] [-C0h] BYREF
  float v38; // [sp+68h] [-B8h]
  float v39; // [sp+6Ch] [-B4h]
  float v40; // [sp+70h] [-B0h]

  v6 = *(float **)a5;
  v8 = 3.4028235e38;
  v10 = 0;
  _FP3 = (float)((float)__fsqrts((float)((float)((float)(uvel->m_y * uvel->m_y) + (float)(uvel->m_z * uvel->m_z))
                                       + (float)(uvel->m_x * uvel->m_x)))
               - (float)1.0842022e-19);
  v12 = __fsqrts((float)((float)((float)(uvel->m_y * uvel->m_y) + (float)(uvel->m_z * uvel->m_z))
                       + (float)(uvel->m_x * uvel->m_x)));
  __asm { fsel      f13, f3, f0, f24 }
  v14 = (float)(uvel->m_x * (float)_FP13);
  v15 = (float)((float)_FP13 * uvel->m_z);
  v16 = (float)((float)_FP13 * uvel->m_y);
  v17 = (float)((float)((float)((float)_FP13 * uvel->m_y) * upos->m_y)
              + (float)((float)(upos->m_z * (float)((float)_FP13 * uvel->m_z))
                      + (float)(upos->m_x * (float)(uvel->m_x * (float)_FP13))));
  if ( *(int *)(a5 + 4) > 0 )
  {
    v18 = v6 + 7;
    do
    {
      v19 = *v6;
      v20 = v6[2];
      v39 = v6[1];
      v21 = v39;
      v38 = v19;
      v22 = v19;
      v40 = v20;
      v23 = v20;
      if ( (float)((float)((float)v14 * v19) + (float)((float)(v39 * (float)v16) + (float)(v20 * (float)v15))) > v17 )
      {
        v24 = (float)(*v18 + v18[1]);
        v25 = *(v18 - 1);
        m_y = upos->m_y;
        v35.m_x = upos->m_x;
        v36.m_x = v19;
        v35.m_y = m_y;
        v36.m_y = v39;
        v37.m_x = v14;
        v37.m_y = v16;
        v27 = bfx::CollideLineAndCircle(
                lineStart: &v35,
                normalizedLineDir: &v37,
                circlePos: &v36,
                radius: (float)((float)((float)v24 + (float)v25) + (float)moverRadius));
        if ( v27 < v8 )
        {
          if ( __fsqrts((float)((float)(*(v18 - 2) * *(v18 - 2))
                              + (float)((float)(*(v18 - 4) * *(v18 - 4)) + (float)(*(v18 - 3) * *(v18 - 3))))) < (float)((float)v12 * (float)0.25) )
            goto LABEL_7;
          v28 = (float)((float)v21 - (float)((float)((float)v16 * (float)v27) + upos->m_y));
          v29 = (float)((float)v23 - (float)(upos->m_z + (float)((float)v15 * (float)v27)));
          v30 = (float)((float)v22 - (float)(upos->m_x + (float)((float)v14 * (float)v27)));
          _FP9 = (float)((float)__fsqrts((float)((float)((float)v30 * (float)v30)
                                               + (float)((float)((float)v29 * (float)v29)
                                                       + (float)((float)v28 * (float)v28))))
                       - 1.0842022e-19);
          __asm { fsel      f7, f9, f8, f24 }
          if ( (float)((float)((float)((float)((float)v22 - (float)(upos->m_x + (float)((float)v14 * (float)v27)))
                                     * (float)_FP7)
                             * (float)v14)
                     + (float)((float)((float)((float)((float)v23 - (float)(upos->m_z + (float)((float)v15 * (float)v27)))
                                             * (float)_FP7)
                                     * (float)v15)
                             + (float)((float)((float)((float)v21 - (float)((float)((float)v16 * (float)v27) + upos->m_y))
                                             * (float)_FP7)
                                     * (float)v16))) > 0.69999999 )
LABEL_7:
            v8 = v27;
        }
      }
      ++v10;
      v6 += 12;
      v18 += 12;
    }
    while ( v10 < *(_DWORD *)(a5 + 4) );
  }
  v33 = v8;
  return *((float *)&v33 + 1);
}


// ========================================================================
// ?CheckForProximityDecel@WalkerImpl@bfx@@AAA_N_NABVFastArrayOfRepRecs@2@@Z
// EA  : 0x832CD728
// RVA : 0x012CD728
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

int __fastcall bfx::WalkerImpl::CheckForProximityDecel(
        bfx::WalkerImpl *this,
        bool targetPosIsGoal,
        const bfx::FastArrayOfRepRecs *repRecs)
{
  const bfx::MoverTune *m_pTune; // r9
  double v6; // fp31
  const bfx::FastArrayOfRepRecs *v7; // r5
  double v8; // fp1
  int result; // r3
  bfx::Vec3 v10; // [sp+50h] [-50h] BYREF
  bfx::Vec3 v11[2]; // [sp+60h] [-40h] BYREF

  if ( !targetPosIsGoal )
    return 0;
  if ( this->m_gotoPosSpec.m_pushThroughCrowdAtGoal )
    return 0;
  bfx::WalkerImpl::GetSurferUPos(this: (bfx::WalkerImpl *)&v10, result: (bfx::Vec3 *)this);
  if ( __fsqrts((float)((float)((float)(this->m_targetPosU.m_x - v10.m_x) * (float)(this->m_targetPosU.m_x - v10.m_x))
                      + (float)((float)((float)(this->m_targetPosU.m_z - v10.m_z)
                                      * (float)(this->m_targetPosU.m_z - v10.m_z))
                              + (float)((float)(this->m_targetPosU.m_y - v10.m_y)
                                      * (float)(this->m_targetPosU.m_y - v10.m_y))))) >= this->m_gotoPosSpec.m_allowedToStopDist )
    return 0;
  bfx::WalkerImpl::GetUVel(this: (bfx::WalkerImpl *)v11, result: (bfx::Vec3 *)this);
  m_pTune = this->m_commonState->m_pTune;
  v6 = (float)((float)((float)(v11[0].m_x * v11[0].m_x)
                     + (float)((float)(v11[0].m_y * v11[0].m_y) + (float)(v11[0].m_z * v11[0].m_z)))
             / (float)(m_pTune->m_startStopAcc * (float)2.0));
  v8 = bfx::CalcDistToImpendingCollision(
         upos: &v10,
         uvel: v11,
         moverRadius: (float)((float)(m_pTune->m_radiusData.m_innerCushion + m_pTune->m_radiusData.m_outerCushion)
               + m_pTune->m_radiusData.m_radius),
         repRecs: v7,
         a5: (int)repRecs);
  result = 1;
  if ( v8 >= v6 )
    return 0;
  return result;
}


// ========================================================================
// ?EnactDelayedOrientationMode@bfx@@YAXAAVDelayedAction@1@AAVOrienter@1@@Z
// EA  : 0x832CD828
// RVA : 0x012CD828
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::EnactDelayedOrientationMode(bfx::DelayedAction *action, bfx::Orienter *orienter)
{
  bfx::OrientMode m_orientMode; // r11
  bfx::Vec3 *p_m_vec; // r4

  if ( action->m_changeOrientMode )
  {
    m_orientMode = action->m_orientMode;
    p_m_vec = &action->m_vec;
    if ( m_orientMode != ORIENT_IN_TRAVEL_DIR )
    {
      switch ( m_orientMode )
      {
        case ORIENT_STRICTLY_IN_TRAVEL_DIR:
          bfx::Orienter::FaceStrictlyInTravelDir(this: orienter);
          break;
        case ORIENT_TARGET:
          bfx::Orienter::FaceTarget(this: orienter, targetPos: p_m_vec);
          break;
        case ORIENT_IN_DIR:
          bfx::Orienter::FaceInDir(this: orienter, dir: p_m_vec);
          break;
        default:
          break;
      }
    }
    else
    {
      idThrowableFilter::InternalPostFilterItems(this: orienter);
    }
  }
  action->m_changeOrientMode = false;
}


// ========================================================================
// ?GetDesiredVel@WalkerImpl@bfx@@UBA?AVVec3@2@XZ
// EA  : 0x832CD8B0
// RVA : 0x012CD8B0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

bfx::WalkerImpl *__fastcall bfx::WalkerImpl::GetDesiredVel(bfx::WalkerImpl *this, bfx::Vec3 *result)
{
  float m_x; // r10
  float m_y; // r9

  m_x = result[2].m_x;
  m_y = result[2].m_y;
  this->__vftable = (bfx::WalkerImpl_vtbl *)LODWORD(result[1].m_z);
  *(float *)&this->m_commonState = m_x;
  this->m_pos3D.m_x = m_y;
  return this;
}


// ========================================================================
// ?ApplyClientMotion@WalkerImpl@bfx@@UAAXABVVec3@2@@Z
// EA  : 0x832CD8D0
// RVA : 0x012CD8D0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::WalkerImpl::ApplyClientMotion(bfx::WalkerImpl *this, const bfx::Vec3 *vel)
{
  bfx::Vec3 *p_m_clientSpecifiedVel; // r31
  bfx::MotionState *m_commonState; // r11
  bfx::AreaProxy *m_pProxy; // r10
  double m_x; // fp10
  double m_z; // fp8
  double v8; // fp5
  double v9; // fp3
  bfx::MotionState *v10; // r11
  double v11; // fp0
  double m_y; // fp10
  double v13; // fp8
  double v14; // fp7
  int v15; // r11
  float *v16; // r11
  int v17; // r11
  float v18; // [sp+50h] [-30h] BYREF
  float v19; // [sp+54h] [-2Ch]
  float v20; // [sp+58h] [-28h]

  this->m_clientSpecifiedVel = *vel;
  p_m_clientSpecifiedVel = &this->m_clientSpecifiedVel;
  m_commonState = this->m_commonState;
  m_pProxy = m_commonState->m_surfer.m_area.m_pProxy;
  if ( m_pProxy != nullptr && m_pProxy->m_pArea != nullptr )
  {
    m_x = p_m_clientSpecifiedVel->m_x;
    m_z = this->m_clientSpecifiedVel.m_z;
    v8 = (float)(m_commonState->m_surfer.m_areaNormal.m_x
               * (float)((float)(this->m_clientSpecifiedVel.m_z * m_commonState->m_surfer.m_areaNormal.m_z)
                       + (float)((float)(this->m_clientSpecifiedVel.m_x * m_commonState->m_surfer.m_areaNormal.m_x)
                               + (float)(this->m_clientSpecifiedVel.m_y * m_commonState->m_surfer.m_areaNormal.m_y))));
    v9 = (float)(m_commonState->m_surfer.m_areaNormal.m_z
               * (float)((float)(this->m_clientSpecifiedVel.m_z * m_commonState->m_surfer.m_areaNormal.m_z)
                       + (float)((float)(this->m_clientSpecifiedVel.m_x * m_commonState->m_surfer.m_areaNormal.m_x)
                               + (float)(this->m_clientSpecifiedVel.m_y * m_commonState->m_surfer.m_areaNormal.m_y))));
    p_m_clientSpecifiedVel->m_y = p_m_clientSpecifiedVel->m_y
                                - (float)(m_commonState->m_surfer.m_areaNormal.m_y
                                        * (float)((float)(p_m_clientSpecifiedVel->m_z
                                                        * m_commonState->m_surfer.m_areaNormal.m_z)
                                                + (float)((float)(p_m_clientSpecifiedVel->m_x
                                                                * m_commonState->m_surfer.m_areaNormal.m_x)
                                                        + (float)(p_m_clientSpecifiedVel->m_y
                                                                * m_commonState->m_surfer.m_areaNormal.m_y))));
    p_m_clientSpecifiedVel->m_x = (float)m_x - (float)v8;
    this->m_clientSpecifiedVel.m_z = (float)m_z - (float)v9;
    v10 = this->m_commonState;
    if ( v10->m_surfer.m_state == 1 )
    {
      bfx::Surfer::CalcEdgeNormal(this: (bfx::Surfer *)&v18, result: (bfx::Vec3 *)&v10->m_surfer);
      v11 = p_m_clientSpecifiedVel->m_z;
      m_y = p_m_clientSpecifiedVel->m_y;
      if ( (float)((float)((float)(p_m_clientSpecifiedVel->m_x * v18) + (float)(p_m_clientSpecifiedVel->m_z * v20))
                 + (float)(p_m_clientSpecifiedVel->m_y * v19)) > 0.0 )
      {
        v13 = (float)(v19
                    * (float)((float)((float)(p_m_clientSpecifiedVel->m_x * v18)
                                    + (float)(p_m_clientSpecifiedVel->m_z * v20))
                            + (float)(p_m_clientSpecifiedVel->m_y * v19)));
        v14 = (float)(v20
                    * (float)((float)((float)(p_m_clientSpecifiedVel->m_x * v18)
                                    + (float)(p_m_clientSpecifiedVel->m_z * v20))
                            + (float)(p_m_clientSpecifiedVel->m_y * v19)));
        p_m_clientSpecifiedVel->m_x = p_m_clientSpecifiedVel->m_x
                                    - (float)((float)((float)((float)(p_m_clientSpecifiedVel->m_x * v18)
                                                            + (float)(p_m_clientSpecifiedVel->m_z * v20))
                                                    + (float)(p_m_clientSpecifiedVel->m_y * v19))
                                            * v18);
        p_m_clientSpecifiedVel->m_y = (float)m_y - (float)v13;
        p_m_clientSpecifiedVel->m_z = (float)v11 - (float)v14;
      }
    }
  }
  v15 = this->m_nextClientVelIndex + 29;
  this->m_clientAvgVelIsDirty = true;
  v16 = (float *)((char *)this + 12 * v15);
  *v16 = p_m_clientSpecifiedVel->m_x;
  v16[1] = p_m_clientSpecifiedVel->m_y;
  v16[2] = p_m_clientSpecifiedVel->m_z;
  v17 = this->m_nextClientVelIndex + 1;
  this->m_nextClientVelIndex = v17;
  if ( v17 >= 2 )
    this->m_nextClientVelIndex = 0;
}


// ========================================================================
// ?GetName@WalkerImpl@bfx@@UAAPBDXZ
// EA  : 0x832CDAB8
// RVA : 0x012CDAB8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

const char *__fastcall bfx::WalkerImpl::GetName(bfx::WalkerImpl *this)
{
  bfx::WalkerImpl::State m_state; // r11

  m_state = this->m_state;
  switch ( m_state )
  {
    case 0:
      return "Walker: done_moving";
    case 1:
      return "Walker: initial_rotation";
    case 2:
      return "Walker: path_move";
    case 3:
      return "Walker: decel_to_stop";
    case 4:
      return "Walker: final_rotation";
    default:
      break;
  }
  return "Walker: none";
}


// ========================================================================
// ?OkToMoveOntoArea@WalkerImpl@bfx@@UBA_NPAVArea@2@@Z
// EA  : 0x832CDB30
// RVA : 0x012CDB30
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

BOOL __fastcall bfx::WalkerImpl::OkToMoveOntoArea(bfx::WalkerImpl *this, bfx::Area *pArea)
{
  const bfx::Array<bfx::Area *> *PathAreas; // r3
  const bfx::Array<bfx::Area *> *v5; // r29
  bfx::UPath *m_pUPath; // r11
  BOOL result; // r3
  const bfx::MoverTune *m_pTune; // r4
  bfx::Area *v9; // r29
  bfx::MotionState *m_commonState; // r3
  __int64 v11; // r6
  unsigned int v12; // r8
  bool IsAreaReachableFromArea; // zf
  int v14; // [sp+50h] [-50h] BYREF
  bfx::PathCC m_curCC; // [sp+58h] [-48h]
  bfx::PathSpec v16[2]; // [sp+60h] [-40h] BYREF

  PathAreas = bfx::SmartPath::GetPathAreas(
                this: this->m_commonState->m_pSmartPath,
                numAreasInFirstSurfaceSectionOut: &v14);
  v5 = PathAreas;
  if ( PathAreas == nullptr )
    return false;
  if ( v14 > 1 && PathAreas->m_data[1] == pArea )
  {
    m_pUPath = this->m_pUPath;
    if ( m_pUPath == nullptr )
      return true;
    m_curCC = m_pUPath->m_curCC;
    return m_curCC.m_i + 1 < m_curCC.m_pPath->m_areas.m_size;
  }
  m_pTune = this->m_commonState->m_pTune;
  if ( !m_pTune->m_allowDetour )
    return false;
  if ( (unsigned __int8)bfx::OkToMoveOntoArea(pArea, pTune: m_pTune) == 0 )
    return false;
  v9 = v5->m_data[v14 - 1];
  bfx::BuildMoverPathSpec(result: v16, pTune: this->m_commonState->m_pTune);
  m_commonState = this->m_commonState;
  LODWORD(v11) = v16;
  v16[0].m_linkUsageFlags = 0;
  HIDWORD(v11) = v9;
  IsAreaReachableFromArea = bfx::Planner::IsAreaReachableFromArea(
                              this: *((bfx::Planner **)m_commonState->m_pSpace->m_components.m_data + 1),
                              pAreaA: pArea,
                              pathSpec: v11,
                              a4: v12);
  result = true;
  if ( !IsAreaReachableFromArea )
    return false;
  return result;
}


// ========================================================================
// ?StopAndTurnInPlaceWhenStuck@WalkerImpl@bfx@@UAAXXZ
// EA  : 0x832CDC48
// RVA : 0x012CDC48
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::WalkerImpl::StopAndTurnInPlaceWhenStuck(bfx::WalkerImpl *this)
{
  bfx::MotionState *m_commonState; // r10
  const bfx::Vec3 *v3; // r3
  double m_x; // fp0
  double m_y; // fp13
  double m_z; // fp12
  bfx::MotionState *v7; // r11
  bfx::Vec3 v8; // [sp+50h] [-80h] BYREF
  _BYTE v9[16]; // [sp+60h] [-70h] BYREF
  bfx::Matrix v10; // [sp+70h] [-60h] BYREF

  m_commonState = this->m_commonState;
  this->m_disableUTurnMode = true;
  this->m_onStopAction.m_restartGotoPos = true;
  this->m_onStopAction.m_changeOrientMode = false;
  if ( m_commonState->m_orientCmd.m_mode <= (unsigned int)ORIENT_STRICTLY_IN_TRAVEL_DIR )
  {
    if ( (unsigned __int8)bfx::WalkerImpl::PerformRoundedCornering(this) != 0 )
    {
      m_x = this->m_goalData.m_goalDir.m_x;
      m_y = this->m_goalData.m_goalDir.m_y;
      m_z = this->m_goalData.m_goalDir.m_z;
    }
    else
    {
      v3 = this->GetPos(this: v9, result: this);
      bfx::Orienter::CalcMat(this: &this->m_commonState->m_orienter, pos: v3, mat: &v10);
      m_x = v10.m_data[0];
      m_y = v10.m_data[1];
      m_z = v10.m_data[2];
    }
    v8.m_z = m_z;
    v7 = this->m_commonState;
    v8.m_y = m_y;
    v8.m_x = m_x;
    bfx::Orienter::FaceInDir(this: &v7->m_orienter, dir: &v8);
  }
  if ( this->m_state == 4 )
  {
    this->m_onFinalRotationAction.m_restartGotoPos = false;
    this->m_onFinalRotationAction.m_changeOrientMode = false;
  }
  this->m_orbitDirection = 0.0;
  this->m_orbitSpeed = 0.0;
  this->m_orbitMinDist = -1.0;
  this->m_orbitCenter.m_x = 0.0;
  this->m_orbitCenter.m_y = 0.0;
  this->m_orbitCenter.m_z = 0.0;
  this->m_orbitDisable = false;
  this->m_orbitRadius = 0.0;
  this->m_state = 3;
  this->m_orbitGoalDirection = 0.0;
  this->m_orbitPrevMinDist = -1.0;
}


// ========================================================================
// ?OnEdge@WalkerImpl@bfx@@UAAXABVVec3@2@@Z
// EA  : 0x832CDD70
// RVA : 0x012CDD70
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::WalkerImpl::OnEdge(bfx::WalkerImpl *this, const bfx::Vec3 *outwardEdgeNormal)
{
  double m_z; // fp0
  double m_y; // fp13
  double v5; // fp3
  double v6; // fp2
  double v7; // fp1

  m_z = this->m_vel.m_z;
  m_y = this->m_vel.m_y;
  if ( (float)((float)((float)(this->m_vel.m_y * outwardEdgeNormal->m_y)
                     + (float)(this->m_vel.m_z * outwardEdgeNormal->m_z))
             + (float)(this->m_vel.m_x * outwardEdgeNormal->m_x)) > 0.0 )
  {
    v5 = (float)(outwardEdgeNormal->m_y
               * (float)((float)((float)(this->m_vel.m_y * outwardEdgeNormal->m_y)
                               + (float)(this->m_vel.m_z * outwardEdgeNormal->m_z))
                       + (float)(this->m_vel.m_x * outwardEdgeNormal->m_x)));
    v6 = (float)(outwardEdgeNormal->m_z
               * (float)((float)((float)(this->m_vel.m_y * outwardEdgeNormal->m_y)
                               + (float)(this->m_vel.m_z * outwardEdgeNormal->m_z))
                       + (float)(this->m_vel.m_x * outwardEdgeNormal->m_x)));
    v7 = (float)(this->m_vel.m_x
               - (float)(outwardEdgeNormal->m_x
                       * (float)((float)((float)(this->m_vel.m_y * outwardEdgeNormal->m_y)
                                       + (float)(this->m_vel.m_z * outwardEdgeNormal->m_z))
                               + (float)(this->m_vel.m_x * outwardEdgeNormal->m_x))));
    this->m_vel.m_x = this->m_vel.m_x
                    - (float)(outwardEdgeNormal->m_x
                            * (float)((float)((float)(this->m_vel.m_y * outwardEdgeNormal->m_y)
                                            + (float)(this->m_vel.m_z * outwardEdgeNormal->m_z))
                                    + (float)(this->m_vel.m_x * outwardEdgeNormal->m_x)));
    this->m_vel.m_y = (float)m_y - (float)v5;
    this->m_vel.m_z = (float)m_z - (float)v6;
    if ( this->m_commonState->m_pTune->m_turnInPlace.m_enableUTurn
      && __fsqrts((float)((float)((float)v7 * (float)v7)
                        + (float)((float)(this->m_vel.m_y * this->m_vel.m_y)
                                + (float)((float)((float)m_z - (float)v6) * (float)((float)m_z - (float)v6))))) < (float)(bfx::GetScale() * (float)0.001)
      && this->m_state == PATH_MOVE )
    {
      bfx::WalkerImpl::UpdateUnwrappedPathIfNeeded(this, bForce: false);
      this->StopAndTurnInPlaceWhenStuck(this);
    }
  }
}


// ========================================================================
// ?Stop@WalkerImpl@bfx@@UAAXABVStpSpec@2@@Z
// EA  : 0x832CDE88
// RVA : 0x012CDE88
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::WalkerImpl::Stop(bfx::WalkerImpl *this, const bfx::StpSpec *spec)
{
  bfx::WalkerImpl::State m_state; // r11
  double v5; // fp31
  const bfx::Vec3 *v6; // r3
  double m_x; // fp0
  double m_y; // fp13
  double m_z; // fp12
  bfx::MotionState *v10; // r11
  bfx::WalkerImpl::State v11; // r11
  const bfx::Vec3 *v12; // r3
  double v13; // fp0
  double v14; // fp13
  double v15; // fp12
  bfx::MotionState *v16; // r11
  const bfx::Vec3 *v17; // r3
  bfx::MotionState *m_commonState; // r11
  bfx::Vec3 v19; // [sp+50h] [-140h] BYREF
  bfx::Vec3 v20; // [sp+60h] [-130h] BYREF
  bfx::Vec3 v21; // [sp+70h] [-120h] BYREF
  _BYTE v22[16]; // [sp+80h] [-110h] BYREF
  bfx::Matrix v23; // [sp+90h] [-100h] BYREF
  bfx::Matrix v24; // [sp+D0h] [-C0h] BYREF
  bfx::Matrix v25; // [sp+110h] [-80h] BYREF

  bfx::WalkerImpl::UpdateUnwrappedPathIfNeeded(this, bForce: false);
  if ( spec->m_stopImmediately )
  {
    this->m_reachedGoal = true;
    v5 = 0.0;
    this->m_vel.m_x = 0.0;
    this->m_vel.m_y = 0.0;
    this->m_vel.m_z = 0.0;
    v17 = this->GetPos(this: v22, result: this);
    bfx::Orienter::CalcMat(this: &this->m_commonState->m_orienter, pos: v17, mat: &v25);
    m_commonState = this->m_commonState;
    v21.m_x = v25.m_data[0];
    v21.m_y = v25.m_data[1];
    v21.m_z = v25.m_data[2];
    bfx::Orienter::FaceInDir(this: &m_commonState->m_orienter, dir: &v21);
    if ( this->m_state == 4 )
    {
      this->m_onFinalRotationAction.m_restartGotoPos = false;
      this->m_onFinalRotationAction.m_changeOrientMode = false;
    }
    this->m_orbitDirection = 0.0;
    this->m_orbitSpeed = 0.0;
    this->m_orbitMinDist = -1.0;
    this->m_orbitCenter.m_x = 0.0;
    this->m_orbitCenter.m_y = 0.0;
    this->m_orbitCenter.m_z = 0.0;
    this->m_state = DONE_MOVING;
    this->m_orbitPrevMinDist = -1.0;
    goto LABEL_25;
  }
  m_state = this->m_state;
  v5 = 0.0;
  if ( m_state == 1 || m_state == PATH_MOVE )
  {
    if ( this->m_commonState->m_orientCmd.m_mode <= (unsigned int)ORIENT_STRICTLY_IN_TRAVEL_DIR )
    {
      if ( (unsigned __int8)bfx::WalkerImpl::PerformRoundedCornering(this) != 0 )
      {
        m_x = this->m_goalData.m_goalDir.m_x;
        m_y = this->m_goalData.m_goalDir.m_y;
        m_z = this->m_goalData.m_goalDir.m_z;
      }
      else
      {
        v6 = this->GetPos(this: v22, result: this);
        bfx::Orienter::CalcMat(this: &this->m_commonState->m_orienter, pos: v6, mat: &v24);
        m_x = v24.m_data[0];
        m_y = v24.m_data[1];
        m_z = v24.m_data[2];
      }
      v20.m_z = m_z;
      v10 = this->m_commonState;
      v20.m_y = m_y;
      v20.m_x = m_x;
      bfx::Orienter::FaceInDir(this: &v10->m_orienter, dir: &v20);
    }
    if ( this->m_state == 4 )
    {
      this->m_onFinalRotationAction.m_restartGotoPos = false;
      this->m_onFinalRotationAction.m_changeOrientMode = false;
    }
    this->m_orbitDirection = 0.0;
    this->m_orbitSpeed = 0.0;
    this->m_orbitMinDist = -1.0;
    this->m_orbitCenter.m_x = 0.0;
    this->m_orbitCenter.m_y = 0.0;
    this->m_orbitCenter.m_z = 0.0;
    this->m_orbitDisable = false;
    this->m_orbitRadius = 0.0;
    this->m_state = 3;
    this->m_orbitGoalDirection = 0.0;
    this->m_orbitPrevMinDist = -1.0;
  }
  if ( spec->m_cancelPendingTurn )
  {
    v11 = this->m_state;
    this->m_doPreGoalApproach = false;
    this->m_goalData.m_applyGoalDir = false;
    if ( v11 == 4 )
    {
      if ( this->m_commonState->m_orientCmd.m_mode <= (unsigned int)ORIENT_STRICTLY_IN_TRAVEL_DIR )
      {
        if ( (unsigned __int8)bfx::WalkerImpl::PerformRoundedCornering(this) != 0 )
        {
          v13 = this->m_goalData.m_goalDir.m_x;
          v14 = this->m_goalData.m_goalDir.m_y;
          v15 = this->m_goalData.m_goalDir.m_z;
        }
        else
        {
          v12 = this->GetPos(this: v22, result: this);
          bfx::Orienter::CalcMat(this: &this->m_commonState->m_orienter, pos: v12, mat: &v23);
          v13 = v23.m_data[0];
          v14 = v23.m_data[1];
          v15 = v23.m_data[2];
        }
        v19.m_z = v15;
        v16 = this->m_commonState;
        v19.m_y = v14;
        v19.m_x = v13;
        bfx::Orienter::FaceInDir(this: &v16->m_orienter, dir: &v19);
      }
      if ( this->m_state == 4 )
      {
        this->m_onFinalRotationAction.m_restartGotoPos = false;
        this->m_onFinalRotationAction.m_changeOrientMode = false;
      }
      this->m_orbitDirection = 0.0;
      this->m_orbitSpeed = 0.0;
      this->m_orbitMinDist = -1.0;
      this->m_orbitCenter.m_x = 0.0;
      this->m_orbitCenter.m_y = 0.0;
      this->m_orbitCenter.m_z = 0.0;
      this->m_state = 3;
      this->m_orbitPrevMinDist = -1.0;
LABEL_25:
      this->m_orbitGoalDirection = v5;
      this->m_orbitDisable = false;
      this->m_orbitRadius = v5;
    }
  }
}


// ========================================================================
// ?CalcGoalURot@WalkerImpl@bfx@@AAA?AVMatrix@2@XZ
// EA  : 0x832CE168
// RVA : 0x012CE168
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

bfx::WalkerImpl *__fastcall bfx::WalkerImpl::CalcGoalURot(bfx::WalkerImpl *this, bfx::Matrix *result)
{
  float v4; // r30
  int v5; // r28
  double v6; // fp9
  double v9; // fp1
  double v10; // fp1
  double v11; // fp10
  double v12; // fp9
  double v15; // fp8
  double v16; // fp7
  double v17; // fp3
  double v18; // fp1
  double v19; // fp2
  bfx::Matrix v23; // [sp+50h] [-C0h] BYREF
  bfx::Matrix v24; // [sp+90h] [-80h] BYREF

  bfx::Orienter::CalcMat(this: (bfx::Orienter *)(LODWORD(result->m_data[1]) + 128), pos: &bfx::ZERO_VEC, mat: &v24);
  v4 = result[1].m_data[3];
  v5 = *(_DWORD *)(LODWORD(v4) + 3008);
  bfx::Area::CalcNormal(
    this: (bfx::Area *)&v23.m_data[4],
    result: *(bfx::Vec3 **)(*(_DWORD *)(LODWORD(v4) + 3004) + 4 * (v5 - 1)));
  v6 = result[2].m_data[1];
  _FP5 = (float)((float)__fsqrts((float)((float)(result[2].m_data[1] * result[2].m_data[1])
                                       + (float)((float)(result[1].m_data[15] * result[1].m_data[15])
                                               + (float)(result[2].m_data[0] * result[2].m_data[0]))))
               - (float)1.0842022e-19);
  __asm { fsel      f3, f5, f4, f30 }
  v9 = (float)(result[2].m_data[0] * (float)_FP3);
  v23.m_data[8] = result[1].m_data[15] * (float)_FP3;
  v23.m_data[9] = v9;
  v23.m_data[10] = (float)v6 * (float)_FP3;
  bfx::Matrix::Rot(
    this: &v23,
    result: (bfx::Vec3 *)((v5 << 6) + LODWORD(v4) + 3944),
    rhs: (const bfx::Vec3 *)&v23.m_data[8]);
  v10 = (float)(v23.m_data[1]
              - (float)(v23.m_data[5]
                      * (float)((float)(v23.m_data[4] * v23.m_data[0])
                              + (float)((float)(v23.m_data[6] * v23.m_data[2]) + (float)(v23.m_data[5] * v23.m_data[1])))));
  v11 = (float)(v23.m_data[2]
              - (float)(v23.m_data[6]
                      * (float)((float)(v23.m_data[4] * v23.m_data[0])
                              + (float)((float)(v23.m_data[6] * v23.m_data[2]) + (float)(v23.m_data[5] * v23.m_data[1])))));
  v12 = (float)(v23.m_data[0]
              - (float)((float)((float)(v23.m_data[4] * v23.m_data[0])
                              + (float)((float)(v23.m_data[6] * v23.m_data[2]) + (float)(v23.m_data[5] * v23.m_data[1])))
                      * v23.m_data[4]));
  _FP4 = (float)((float)__fsqrts((float)((float)((float)v12 * (float)v12)
                                       + (float)((float)((float)v11 * (float)v11) + (float)((float)v10 * (float)v10))))
               - 1.0842022e-19);
  __asm { fsel      f2, f4, f3, f30 }
  v15 = (float)((float)(v23.m_data[2]
                      - (float)(v23.m_data[6]
                              * (float)((float)(v23.m_data[4] * v23.m_data[0])
                                      + (float)((float)(v23.m_data[6] * v23.m_data[2])
                                              + (float)(v23.m_data[5] * v23.m_data[1])))))
              * (float)_FP2);
  v16 = (float)((float)(v23.m_data[1]
                      - (float)(v23.m_data[5]
                              * (float)((float)(v23.m_data[4] * v23.m_data[0])
                                      + (float)((float)(v23.m_data[6] * v23.m_data[2])
                                              + (float)(v23.m_data[5] * v23.m_data[1])))))
              * (float)_FP2);
  v23.m_data[0] = (float)(v23.m_data[0]
                        - (float)((float)((float)(v23.m_data[4] * v23.m_data[0])
                                        + (float)((float)(v23.m_data[6] * v23.m_data[2])
                                                + (float)(v23.m_data[5] * v23.m_data[1])))
                                * v23.m_data[4]))
                * (float)_FP2;
  v17 = (float)((float)(v23.m_data[6] * v23.m_data[0]) - (float)((float)v15 * v23.m_data[4]));
  v23.m_data[2] = v15;
  v18 = (float)((float)((float)v15 * v23.m_data[5]) - (float)((float)v16 * v23.m_data[6]));
  v23.m_data[1] = v16;
  v19 = (float)((float)((float)v16 * v23.m_data[4]) - (float)(v23.m_data[5] * v23.m_data[0]));
  _FP9 = (float)((float)__fsqrts((float)((float)((float)v18 * (float)v18)
                                       + (float)((float)((float)v19 * (float)v19) + (float)((float)v17 * (float)v17))))
               - (float)1.0842022e-19);
  __asm { fsel      f7, f9, f8, f30 }
  v23.m_data[12] = (float)v18 * (float)_FP7;
  v23.m_data[13] = (float)((float)(v23.m_data[6] * v23.m_data[0]) - (float)((float)v15 * v23.m_data[4])) * (float)_FP7;
  v23.m_data[14] = (float)v19 * (float)_FP7;
  bfx::Matrix::Build(
    (bfx::Matrix *)this,
    xAxis: (const bfx::Vec3 *)&v23,
    yAxis: (const bfx::Vec3 *)&v23.m_data[12],
    zAxis: (const bfx::Vec3 *)&v23.m_data[4],
    trans: (const bfx::Vec3 *)&result->m_data[12]);
  return this;
}


// ========================================================================
// ?CalculateOrbits@WalkerImpl@bfx@@AAAXABVVec3@2@AAUOrbit@2@1@Z
// EA  : 0x832CE328
// RVA : 0x012CE328
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::WalkerImpl::CalculateOrbits(
        bfx::WalkerImpl *this,
        const bfx::Vec3 *ugoalPos,
        bfx::Orbit *orbitLeft,
        bfx::Orbit *orbitRight)
{
  bfx::Area *m_pTune; // r5
  double m_x; // fp1
  double v10; // fp31
  bfx::Vec3 *v11; // r27
  double v12; // fp30
  double v13; // fp29
  double OrbitTangentToMe; // fp1
  double m_y; // fp11
  double m_z; // fp9
  double v17; // fp13
  double v18; // fp8
  double v19; // fp7
  double v20; // fp6
  bfx::Area *v21; // r5
  double v22; // fp1
  double v23; // fp10
  double v24; // fp8
  double v25; // fp7
  double v26; // fp6
  double v27; // fp5
  bfx::Vec3 v28; // [sp+50h] [-A0h] BYREF
  char v29; // [sp+60h] [-90h] BYREF
  float v30; // [sp+70h] [-80h]
  float v31; // [sp+74h] [-7Ch]
  float v32; // [sp+78h] [-78h]
  float v33; // [sp+80h] [-70h]
  float v34; // [sp+84h] [-6Ch]
  float v35; // [sp+88h] [-68h]

  bfx::WalkerImpl::CalcGoalURot(this: (bfx::WalkerImpl *)&v29, result: (bfx::Matrix *)this);
  m_pTune = (bfx::Area *)this->m_commonState->m_pTune;
  m_x = m_pTune[3].m_pos.m_x;
  v10 = v30;
  v11 = (bfx::Vec3 *)this->m_pUPath->m_unwrappedPath.m_areas.m_data[this->m_pUPath->m_unwrappedPath.m_areas.m_size - 1];
  v12 = v31;
  v13 = v32;
  v28.m_x = v30;
  v28.m_y = v31;
  v28.m_z = v32;
  OrbitTangentToMe = bfx::GetOrbitTangentToMe(
                       uMyPos: ugoalPos,
                       sideVec: &v28,
                       desiredRadius: m_x,
                       pUGoalArea: m_pTune,
                       a5: v11);
  orbitLeft->m_radius = OrbitTangentToMe;
  m_y = ugoalPos->m_y;
  m_z = ugoalPos->m_z;
  v17 = ugoalPos->m_x;
  v28.m_x = -v10;
  v18 = v33;
  v19 = v34;
  v20 = v35;
  v28.m_y = -v12;
  v28.m_z = -v13;
  orbitLeft->m_center.m_x = (float)v17 + (float)((float)OrbitTangentToMe * (float)v10);
  orbitLeft->m_center.m_y = (float)m_y + (float)((float)v12 * (float)OrbitTangentToMe);
  orbitLeft->m_center.m_z = (float)m_z + (float)((float)v13 * (float)OrbitTangentToMe);
  orbitLeft->m_rotationAxis.m_x = v18;
  orbitLeft->m_rotationAxis.m_y = v19;
  orbitLeft->m_rotationAxis.m_z = v20;
  v22 = bfx::GetOrbitTangentToMe(
          uMyPos: ugoalPos,
          sideVec: &v28,
          desiredRadius: this->m_commonState->m_pTune->m_goalTune.m_preferredTurningRadius,
          pUGoalArea: v21,
          a5: v11);
  orbitRight->m_radius = v22;
  v23 = ugoalPos->m_y;
  v24 = ugoalPos->m_z;
  v25 = v33;
  v26 = v34;
  v27 = v35;
  orbitRight->m_center.m_x = ugoalPos->m_x - (float)((float)v22 * (float)v10);
  orbitRight->m_center.m_z = (float)v24 - (float)((float)v13 * (float)v22);
  orbitRight->m_center.m_y = (float)v23 - (float)((float)v12 * (float)v22);
  orbitRight->m_rotationAxis.m_x = v25;
  orbitRight->m_rotationAxis.m_y = v26;
  orbitRight->m_rotationAxis.m_z = v27;
}


// ========================================================================
// ?CalcGoalApproachPos@WalkerImpl@bfx@@AAA?AVVec3@2@ABV32@@Z
// EA  : 0x832CE488
// RVA : 0x012CE488
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

bfx::WalkerImpl *__fastcall bfx::WalkerImpl::CalcGoalApproachPos(
        bfx::WalkerImpl *this,
        bfx::Matrix *result,
        const bfx::Vec3 *ugoalPos)
{
  char v6; // r28
  int v7; // r11
  char v8; // r10
  double v9; // fp30
  double v10; // fp25
  double v11; // fp24
  double v12; // fp1
  double v13; // fp11
  bfx::Orbit *v14; // r11
  double m_radius; // fp29
  double v16; // fp26
  double m_y; // fp27
  double m_x; // fp28
  bfx::WalkerImpl *SurferUPos; // r3
  double v21; // fp24
  double v22; // fp23
  double v23; // fp25
  double v24; // fp9
  long double v28; // fp2
  double v29; // fp22
  const bfx::Quat *v30; // r3
  const bfx::Quat *v31; // r3
  double v32; // fp6
  double v33; // fp4
  double v34; // fp5
  bfx::Matrix *v37; // r3
  double v38; // fp23
  double v39; // fp25
  double v40; // fp24
  bfx::Matrix *v41; // r3
  double v42; // fp11
  double v43; // fp13
  double v44; // fp0
  double v45; // fp13
  double v46; // fp5
  double v47; // fp4
  double v48; // fp3
  double v49; // fp2
  double v54; // fp12
  double v55; // fp8
  bfx::WalkerImpl *v56; // r3
  bool v57; // mr_fpscr48
  double v58; // fp7
  double v59; // fp5
  double v60; // fp4
  double v61; // fp3
  double v62; // fp12
  double v63; // fp10
  double v64; // fp3
  double v65; // fp30
  double v66; // fp29
  bfx::Vec3 *v67; // r4
  double v72; // fp2
  bfx::Vec3 *v75; // r3
  double v76; // fp0
  double m_z; // fp12
  bfx::Matrix v78; // [sp+50h] [-2B0h] BYREF
  bfx::Vec3 v79; // [sp+90h] [-270h] BYREF
  bfx::Orbit v80; // [sp+A0h] [-260h] BYREF
  bfx::Vec3 v81; // [sp+C0h] [-240h] BYREF
  bfx::Vec3 v82; // [sp+D0h] [-230h] BYREF
  bfx::Vec3 v83; // [sp+E0h] [-220h] BYREF
  bfx::Vec3 v84; // [sp+F0h] [-210h] BYREF
  bfx::Vec3 v85; // [sp+100h] [-200h] BYREF
  bfx::Vec3 v86; // [sp+110h] [-1F0h] BYREF
  float v87; // [sp+120h] [-1E0h] BYREF
  float v88; // [sp+124h] [-1DCh]
  float v89; // [sp+128h] [-1D8h]
  float v90; // [sp+140h] [-1C0h]
  float v91; // [sp+144h] [-1BCh]
  float v92; // [sp+148h] [-1B8h]
  bfx::Array<bfx::PathSeg> v93; // [sp+160h] [-1A0h] BYREF
  char v94; // [sp+170h] [-190h]
  int v95; // [sp+174h] [-18Ch]
  float v96; // [sp+178h] [-188h]
  bfx::Matrix v97; // [sp+180h] [-180h] BYREF
  bfx::Matrix v98; // [sp+1C0h] [-140h] BYREF
  bfx::Matrix v99; // [sp+200h] [-100h] BYREF
  bfx::Matrix v100[2]; // [sp+240h] [-C0h] BYREF

  v6 = 0;
  v7 = *(_DWORD *)(LODWORD(result->m_data[1]) + 4);
  if ( *(_BYTE *)(v7 + 180) == 0
    || HIBYTE(result[2].m_data[6]) != 0
    || BYTE2(result[2].m_data[6]) == 0
    || (v8 = 1, HIBYTE(result[8].m_data[11]) != 0) )
  {
    v8 = 0;
  }
  if ( v8 == 0 )
  {
    v64 = result[2].m_data[1];
    v65 = (float)(*(float *)(v7 + 8) * (float)6.0);
    v66 = (float)((float)(*(float *)v7 * *(float *)v7) / (float)(*(float *)(v7 + 44) * (float)3.0));
    v67 = (bfx::Vec3 *)((*(_DWORD *)(LODWORD(result[1].m_data[3]) + 3008) << 6) + LODWORD(result[1].m_data[3]) + 3944);
    _FP11 = (float)(*(float *)(v7 + 8)
                  - (float)((float)(*(float *)v7 * *(float *)v7) / (float)(*(float *)(v7 + 44) * (float)3.0)));
    _FP8 = (float)((float)__fsqrts((float)((float)(result[2].m_data[1] * result[2].m_data[1])
                                         + (float)((float)(result[1].m_data[15] * result[1].m_data[15])
                                                 + (float)(result[2].m_data[0] * result[2].m_data[0]))))
                 - (float)1.0842022e-19);
    __asm
    {
      fsel      f28, f11, f1, f29
      fsel      f6, f8, f7, f31
    }
    v72 = (float)(result[2].m_data[0] * (float)_FP6);
    v84.m_x = result[1].m_data[15] * (float)_FP6;
    v84.m_y = v72;
    v84.m_z = (float)v64 * (float)_FP6;
    bfx::Matrix::Rot(this: &v78, result: v67, rhs: &v84);
    _FP0 = (float)((float)v65 - (float)v66);
    __asm { fsel      f1, f0, f13, f30# dist }
    v75 = *(bfx::Vec3 **)(4 * (*(_DWORD *)(LODWORD(result[1].m_data[3]) + 3008) - 1)
                        + *(_DWORD *)(LODWORD(result[1].m_data[3]) + 3004));
    v96 = 0.0;
    v81.m_x = -v78.m_data[0];
    v93.m_tag = MEM_DEFAULT;
    v81.m_y = -v78.m_data[1];
    v94 = 0;
    v81.m_z = -v78.m_data[2];
    v95 = -1;
    bfx::RayCastThroughAreas(
      pStartArea: v75,
      origStartPos: ugoalPos,
      dir: &v81,
      dist: _FP1,
      pathSpec: (const bfx::PathSpec *)0xFFFFFFFF,
      rayCastData: &bfx::g_defaultPathSpec,
      pPathOut: &v93,
      a8: nullptr);
    v76 = (float)(v78.m_data[2] * v96);
    m_z = ugoalPos->m_z;
    v42 = (float)(ugoalPos->m_x - (float)(v78.m_data[0] * v96));
    *(float *)&this->m_commonState = ugoalPos->m_y - (float)(v78.m_data[1] * v96);
    this->m_pos3D.m_x = (float)m_z - (float)v76;
    goto LABEL_26;
  }
  bfx::WalkerImpl::CalcGoalURot(this: (bfx::WalkerImpl *)&v87, result);
  bfx::WalkerImpl::GetSurferUPos(this: (bfx::WalkerImpl *)&v78.m_data[4], (bfx::Vec3 *)result);
  v9 = v78.m_data[4];
  v10 = v78.m_data[5];
  v11 = v78.m_data[6];
  v12 = -(float)(ugoalPos->m_y - v78.m_data[5]);
  v13 = -(float)(ugoalPos->m_z - v78.m_data[6]);
  if ( (float)((float)(v90 * (float)((float)(v88 * (float)v13) - (float)(v89 * (float)v12)))
             + (float)((float)((float)((float)(v89 * (float)-(float)(ugoalPos->m_x - v78.m_data[4]))
                                     - (float)((float)v13 * v87))
                             * v91)
                     + (float)((float)((float)((float)v12 * v87)
                                     - (float)(v88 * (float)-(float)(ugoalPos->m_x - v78.m_data[4])))
                             * v92))) > 0.0 )
    v6 = 1;
  v78.m_data[8] = 0.0;
  v78.m_data[9] = 0.0;
  v78.m_data[10] = 0.0;
  v78.m_data[11] = 0.0;
  v78.m_data[12] = 0.0;
  v78.m_data[13] = 0.0;
  v78.m_data[14] = 0.0;
  v80.m_center.m_x = 0.0;
  v80.m_center.m_y = 0.0;
  v80.m_center.m_z = 0.0;
  v80.m_radius = 0.0;
  v80.m_rotationAxis.m_x = 0.0;
  v80.m_rotationAxis.m_y = 0.0;
  v80.m_rotationAxis.m_z = 0.0;
  bfx::WalkerImpl::CalculateOrbits(
    this: (bfx::WalkerImpl *)result,
    ugoalPos,
    orbitLeft: (bfx::Orbit *)&v78.m_data[8],
    orbitRight: &v80);
  if ( result[8].m_data[2] == 0.0 )
  {
    v14 = (bfx::Orbit *)&v78.m_data[8];
    if ( v6 == 0 )
LABEL_13:
      v14 = &v80;
  }
  else
  {
    v14 = (bfx::Orbit *)&v78.m_data[8];
    if ( result[8].m_data[9] <= 0.0 )
      goto LABEL_13;
  }
  m_radius = v14->m_radius;
  v16 = v14->m_center.m_z;
  m_y = v14->m_center.m_y;
  m_x = v14->m_center.m_x;
  SurferUPos = bfx::WalkerImpl::GetSurferUPos(this: (bfx::WalkerImpl *)&v78.m_data[4], (bfx::Vec3 *)result);
  bfx::Orienter::CalcMat(
    this: (bfx::Orienter *)(LODWORD(result->m_data[1]) + 128),
    pos: (const bfx::Vec3 *)SurferUPos,
    mat: &v97);
  v97 = *bfx::Matrix::operator*(
           this: v100,
           result: (bfx::Matrix *)((*(_DWORD *)(LODWORD(result[1].m_data[3]) + 4968) << 6) + LODWORD(result[1].m_data[3]) + 4008),
           rhs: &v97);
  v21 = (float)((float)v16 - (float)v11);
  v22 = (float)((float)m_x - (float)v9);
  v23 = (float)((float)m_y - (float)v10);
  v24 = __fsqrts((float)((float)((float)v23 * (float)v23)
                       + (float)((float)((float)((float)m_x - (float)v9) * (float)((float)m_x - (float)v9))
                               + (float)((float)v21 * (float)v21))));
  _FP7 = (float)((float)-1.0 - (float)((float)m_radius / (float)v24));
  _FP6 = (float)((float)1.0 - (float)((float)m_radius / (float)v24));
  __asm { fsel      f5, f7, f13, f8 }
  __asm { fsel      f1, f6, f4, f30# x }
  v28 = acos(x: _FP2);
  v29 = (float)*(double *)&v28;
  v82.m_x = -v90;
  v82.m_y = -v91;
  v82.m_z = -v92;
  v30 = bfx::Quat::Quat(this: (bfx::Quat *)&v78.m_data[8], axis: &v82, angle: v29);
  v83.m_x = 0.0;
  v83.m_y = 0.0;
  v83.m_z = 0.0;
  bfx::Matrix::Build(this: &v98, q: v30, pos: &v83);
  v85.m_x = -v90;
  v85.m_y = -v91;
  v85.m_z = -v92;
  v31 = bfx::Quat::Quat(this: (bfx::Quat *)&v78.m_data[8], axis: &v85, angle: -v29);
  v86.m_x = 0.0;
  v86.m_y = 0.0;
  v86.m_z = 0.0;
  bfx::Matrix::Build(this: &v99, q: v31, pos: &v86);
  v32 = (float)((float)-v23
              - (float)(v91
                      * (float)((float)(v90 * (float)-v22)
                              + (float)((float)((float)-v23 * v91) + (float)((float)-v21 * v92)))));
  v33 = (float)((float)-v22
              - (float)(v90
                      * (float)((float)(v90 * (float)-v22)
                              + (float)((float)((float)-v23 * v91) + (float)((float)-v21 * v92)))));
  v34 = (float)((float)-v21
              - (float)(v92
                      * (float)((float)(v90 * (float)-v22)
                              + (float)((float)((float)-v23 * v91) + (float)((float)-v21 * v92)))));
  _FP13 = (float)((float)__fsqrts((float)((float)((float)v33 * (float)v33)
                                        + (float)((float)((float)v34 * (float)v34) + (float)((float)v32 * (float)v32))))
                - (float)1.0842022e-19);
  __asm { fsel      f11, f13, f12, f31 }
  v79.m_x = (float)((float)((float)-v22
                          - (float)(v90
                                  * (float)((float)(v90 * (float)-v22)
                                          + (float)((float)((float)-v23 * v91) + (float)((float)-v21 * v92)))))
                  * (float)_FP11)
          * (float)m_radius;
  v79.m_y = (float)((float)((float)-v23
                          - (float)(v91
                                  * (float)((float)(v90 * (float)-v22)
                                          + (float)((float)((float)-v23 * v91) + (float)((float)-v21 * v92)))))
                  * (float)_FP11)
          * (float)m_radius;
  v79.m_z = (float)((float)((float)-v21
                          - (float)(v92
                                  * (float)((float)(v90 * (float)-v22)
                                          + (float)((float)((float)-v23 * v91) + (float)((float)-v21 * v92)))))
                  * (float)_FP11)
          * (float)m_radius;
  v37 = bfx::Matrix::Rot(this: (bfx::Matrix *)&v78.m_data[4], result: (bfx::Vec3 *)&v98, rhs: &v79);
  v38 = (float)(v37->m_data[0] + (float)m_x);
  v39 = (float)(v37->m_data[1] + (float)m_y);
  v40 = (float)(v37->m_data[2] + (float)v16);
  v41 = bfx::Matrix::Rot(this: (bfx::Matrix *)&v78.m_data[8], result: (bfx::Vec3 *)&v99, rhs: &v79);
  v42 = (float)(v41->m_data[0] + (float)m_x);
  v43 = v41->m_data[2];
  v44 = (float)(v41->m_data[1] + (float)m_y);
  result[9].m_data[11] = v38;
  v45 = (float)((float)v43 + (float)v16);
  result[9].m_data[12] = v39;
  result[9].m_data[13] = v40;
  result[9].m_data[14] = v42;
  result[9].m_data[15] = v44;
  result[10].m_data[0] = v45;
  result[8].m_data[5] = m_x;
  result[8].m_data[6] = m_y;
  result[8].m_data[7] = v16;
  result[8].m_data[8] = m_radius;
  v46 = (float)((float)v39 - ugoalPos->m_y);
  v47 = (float)((float)v44 - ugoalPos->m_y);
  v48 = (float)((float)v40 - ugoalPos->m_z);
  v49 = (float)((float)v45 - ugoalPos->m_z);
  _FP26 = (float)((float)__fsqrts((float)((float)((float)((float)v38 - ugoalPos->m_x)
                                                * (float)((float)v38 - ugoalPos->m_x))
                                        + (float)((float)((float)v48 * (float)v48) + (float)((float)v46 * (float)v46))))
                - 1.0842022e-19);
  _FP12 = (float)((float)__fsqrts((float)((float)((float)((float)v42 - ugoalPos->m_x)
                                                * (float)((float)v42 - ugoalPos->m_x))
                                        + (float)((float)((float)v49 * (float)v49) + (float)((float)v47 * (float)v47))))
                - 1.0842022e-19);
  __asm
  {
    fsel      f1, f26, f1, f31
    fsel      f12, f12, f30, f31
  }
  v55 = (float)((float)((float)((float)((float)v45 - ugoalPos->m_z) * (float)_FP12) * v89)
              + (float)((float)((float)((float)((float)v42 - ugoalPos->m_x) * (float)_FP12) * v87)
                      + (float)((float)((float)((float)v44 - ugoalPos->m_y) * (float)_FP12) * v88)));
  v54 = (float)((float)((float)((float)((float)v40 - ugoalPos->m_z) * (float)_FP1) * v89)
              + (float)((float)((float)((float)((float)v38 - ugoalPos->m_x) * (float)_FP1) * v87)
                      + (float)((float)((float)((float)v39 - ugoalPos->m_y) * (float)_FP1) * v88)));
  if ( v54 < 0.0 && v55 > 0.0 )
  {
    *(float *)&this->__vftable = v38;
    *(float *)&this->m_commonState = v39;
    this->m_pos3D.m_x = v40;
    return this;
  }
  if ( v55 >= 0.0 || v54 <= 0.0 )
  {
    v57 = v54 < 0.0;
    v58 = (float)((float)v39 - ugoalPos->m_y);
    v59 = (float)((float)v44 - ugoalPos->m_y);
    v56 = this;
    v60 = (float)((float)v40 - ugoalPos->m_z);
    v61 = (float)((float)v45 - ugoalPos->m_z);
    v63 = (float)((float)((float)((float)v42 - ugoalPos->m_x) * (float)((float)v42 - ugoalPos->m_x))
                + (float)((float)((float)v61 * (float)v61) + (float)((float)v59 * (float)v59)));
    v62 = (float)((float)((float)((float)v38 - ugoalPos->m_x) * (float)((float)v38 - ugoalPos->m_x))
                + (float)((float)((float)v60 * (float)v60) + (float)((float)v58 * (float)v58)));
    if ( v57 )
    {
      if ( v62 <= v63 )
      {
LABEL_22:
        *(float *)&this->__vftable = v38;
        *(float *)&this->m_commonState = v39;
        this->m_pos3D.m_x = v40;
        return v56;
      }
    }
    else if ( v62 > v63 )
    {
      goto LABEL_22;
    }
    *(float *)&this->__vftable = v42;
    *(float *)&this->m_commonState = v44;
    this->m_pos3D.m_x = v45;
    return v56;
  }
  *(float *)&this->m_commonState = v44;
  this->m_pos3D.m_x = v45;
LABEL_26:
  *(float *)&this->__vftable = v42;
  return this;
}


// ========================================================================
// ?CalcFlockAcc@WalkerImpl@bfx@@AAA?AVVec3@2@ABVFastArrayOfRepRecs@2@@Z
// EA  : 0x832CEB60
// RVA : 0x012CEB60
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

bfx::WalkerImpl *__fastcall bfx::WalkerImpl::CalcFlockAcc(
        bfx::WalkerImpl *this,
        bfx::Vec3 *result,
        const bfx::FastArrayOfRepRecs *repRecs)
{
  float m_y; // r11
  int v7; // r25
  double v8; // fp26
  bfx::InstanceComponent_vtbl *v9; // r24
  double v10; // fp30
  int v11; // r28
  double v12; // fp29
  int v13; // r29
  double v14; // fp28
  bfx::RepRec *m_pRecs; // r31
  double m_z; // fp24
  double v17; // fp23
  double m_x; // fp22
  __int64 v19; // r11
  double v20; // fp13
  double v21; // fp12
  double v22; // fp0
  const bfx::RepulsorImpl *m_pRep; // r11
  float v28; // r8
  float v29; // r7
  int (__fastcall *v30)(_BYTE *, bfx::Vec3 *); // r6
  const bfx::Vec3 *v31; // r3
  float v33; // r8
  float v34; // r7
  bfx::Vec3 v35; // [sp+50h] [-C0h] BYREF
  _BYTE v36[96]; // [sp+60h] [-B0h] BYREF

  m_y = result->m_y;
  if ( *(_DWORD *)(LODWORD(m_y) + 108) == 0 )
    goto LABEL_14;
  if ( repRecs->m_size == 0 )
    goto LABEL_14;
  v7 = *(_DWORD *)(LODWORD(m_y) + 4);
  v8 = *(float *)(v7 + 40);
  v9 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][8].__vftable;
  if ( v8 <= 0.0 )
    goto LABEL_14;
  bfx::WalkerImpl::GetUPos(this: (bfx::WalkerImpl *)&v35, result);
  v10 = 0.0;
  v11 = 0;
  v12 = 0.0;
  v13 = 0;
  v14 = 0.0;
  m_pRecs = repRecs->m_pRecs;
  if ( repRecs->m_size <= 0 )
    goto LABEL_14;
  m_z = v35.m_z;
  v17 = v35.m_y;
  m_x = v35.m_x;
  do
  {
    HIDWORD(v19) = m_pRecs->m_flockID;
    if ( HIDWORD(v19) == *(_DWORD *)(LODWORD(result->m_y) + 108) )
    {
      v20 = (float)(m_pRecs->m_pos.m_y - (float)v17);
      v21 = (float)(m_pRecs->m_pos.m_z - (float)m_z);
      v22 = __fsqrts((float)((float)((float)(m_pRecs->m_pos.m_x - (float)m_x) * (float)(m_pRecs->m_pos.m_x - (float)m_x))
                           + (float)((float)((float)v21 * (float)v21) + (float)((float)v20 * (float)v20))));
      if ( v22 > 0.0 && v22 < v8 )
      {
        ++v11;
        _FP8 = -(float)((float)v22 / (float)v8);
        _FP7 = (float)((float)1.0 - (float)((float)v22 / (float)v8));
        __asm { fsel      f6, f8, f27, f10 }
        __asm { fsel      f4, f7, f5, f31 }
        v10 = (float)((float)((float)(m_pRecs->m_pos.m_x - (float)m_x)
                            * (float)((float)((float)_FP4 * *(float *)(v7 + 36)) / (float)v22))
                    + (float)v10);
        v12 = (float)((float)((float)(m_pRecs->m_pos.m_y - (float)v17)
                            * (float)((float)((float)_FP4 * *(float *)(v7 + 36)) / (float)v22))
                    + (float)v12);
        v14 = (float)((float)((float)(m_pRecs->m_pos.m_z - (float)m_z)
                            * (float)((float)((float)_FP4 * *(float *)(v7 + 36)) / (float)v22))
                    + (float)v14);
        if ( BYTE1(v9->Start) != 0 )
        {
          m_pRep = m_pRecs->m_pRep;
          v28 = m_pRep->m_pos.m_y;
          v29 = m_pRep->m_pos.m_z;
          v30 = *(int (__fastcall **)(_BYTE *, bfx::Vec3 *))(LODWORD(result->m_x) + 24);
          v35.m_x = m_pRep->m_pos.m_x;
          v35.m_y = v28;
          v35.m_z = v29;
          v31 = (const bfx::Vec3 *)v30(a1: v36, a2: result);
          bfx::DrawLine(pSpace: *(const bfx::Space **)LODWORD(result->m_y), v0: v31, v1: &v35, color: &ColorYellow_28);
        }
      }
    }
    ++v13;
    ++m_pRecs;
  }
  while ( v13 < repRecs->m_size );
  if ( v11 > 0 )
  {
    LODWORD(v19) = v11;
    *(_QWORD *)&v35.m_x = v19;
    *(float *)&this->__vftable = (float)((float)1.0 / (float)v19) * (float)v10;
    *(float *)&this->m_commonState = (float)((float)1.0 / (float)v19) * (float)v12;
    this->m_pos3D.m_x = (float)((float)1.0 / (float)v19) * (float)v14;
    return this;
  }
  else
  {
LABEL_14:
    v33 = bfx::ZERO_VEC.m_y;
    v34 = bfx::ZERO_VEC.m_z;
    this->__vftable = (bfx::WalkerImpl_vtbl *)LODWORD(bfx::ZERO_VEC.m_x);
    *(float *)&this->m_commonState = v33;
    this->m_pos3D.m_x = v34;
    return this;
  }
}


// ========================================================================
// ?RayCastThroughPathAndToBumpers@bfx@@YA_NABVVec3@1@0ABVPathCC@1@AAVEdgeCursor@1@AAM3@Z
// EA  : 0x832CED90
// RVA : 0x012CED90
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

int __fastcall bfx::RayCastThroughPathAndToBumpers(
        const bfx::Vec3 *start,
        const bfx::Vec3 *origDelta,
        const bfx::PathCC *pathStart,
        bfx::EdgeCursor *collideEdgeCursor,
        float *distToCollide,
        float *distToBumpers)
{
  double m_z; // fp11
  double v13; // fp0
  float m_x; // r6
  double v15; // fp10
  double m_y; // fp9
  double v17; // fp13
  float v18; // r5
  double v19; // fp8
  float v20; // r26
  char v21; // r22
  bfx::PathCC v22; // r11
  int v23; // r30
  int v24; // r29
  bfx::Vec3 *v25; // r28
  float v26; // r20
  int v27; // r28
  bfx::AreaProxy *v28; // r27
  int m_i; // r11
  bfx::Area *v30; // r10
  signed int v31; // r6
  float *v32; // r8
  int v33; // r9
  float v34; // r5
  float *v35; // r11
  float v36; // r3
  double v37; // fp0
  float v38; // r8
  float v39; // r7
  float v40; // r6
  double v41; // fp27
  double Scale; // fp1
  double v43; // fp13
  double v44; // fp0
  double v45; // fp12
  float *v46; // r11
  float v47; // r4
  float v49; // r3
  float v50; // r11
  bfx::Area *m_pArea; // r10
  int v53; // r9
  signed int v54; // r7
  char *v55; // r11
  float v56; // r10
  float v57; // r8
  double v58; // fp10
  double v59; // fp6
  double v60; // fp9
  bfx::Area *v61; // r10
  int v62; // r11
  bfx::Vec3 *v63; // r4
  double v64; // fp0
  double v65; // fp9
  signed int v66; // r6
  float *v67; // r5
  float *v68; // r11
  float v69; // r9
  unsigned int v70; // r8
  float v71; // r7
  float v72; // r6
  float v73; // r5
  double v74; // fp7
  float v75; // r10
  float v76; // r9
  bfx::Area *v79; // r3
  bfx::Vec3 *v80; // r3
  bfx::Vec3 *v81; // r27
  double v82; // fp0
  bfx::Vec3 v84; // [sp+50h] [-170h] BYREF
  bfx::Vec3 v85; // [sp+60h] [-160h] BYREF
  bfx::Vec3 v86; // [sp+70h] [-150h] BYREF
  bfx::Area v87; // [sp+80h] [-140h] BYREF
  float v88; // [sp+B8h] [-108h]
  float v89; // [sp+C0h] [-100h]
  float v90; // [sp+C4h] [-FCh]
  float v91; // [sp+C8h] [-F8h]
  float v92; // [sp+D0h] [-F0h]
  float v93; // [sp+D4h] [-ECh]
  float v94; // [sp+D8h] [-E8h]
  float v95; // [sp+E0h] [-E0h]
  float v96; // [sp+E4h] [-DCh]
  float v97; // [sp+E8h] [-D8h]
  bfx::Vec3 v98; // [sp+F0h] [-D0h] BYREF
  bfx::Area v99; // [sp+100h] [-C0h] BYREF

  bfx::Area::CalcNormal(this: &v87, result: (bfx::Vec3 *)pathStart->m_pPath->m_areas.m_data[pathStart->m_i]);
  m_z = origDelta->m_z;
  v13 = *(float *)&v87.m_pFirstLink;
  m_x = start->m_x;
  v15 = (float)(origDelta->m_z * *(float *)&v87.m_pFirstLink);
  m_y = origDelta->m_y;
  v17 = *(float *)&v87.m_dynAreaData.m_data;
  v18 = start->m_y;
  v19 = origDelta->m_x;
  v86.m_z = start->m_z;
  *distToCollide = 0.0;
  *(bfx::PathCC *)&v84.m_x = *pathStart;
  v86.m_y = v18;
  v86.m_x = m_x;
  v20 = v84.m_x;
  v21 = 1;
  v22 = *pathStart;
  v23 = 4 * (int)pathStart->m_pPath;
  *(bfx::PathCC *)&v87.m_pos.m_x = v22;
  v24 = v22.m_i + 1;
  v84.m_x = (float)v19
          - (float)((float)((float)((float)v19 * *(float *)&v87.m_pProxy)
                          + (float)((float)((float)m_y * (float)v17) + (float)v15))
                  * *(float *)&v87.m_pProxy);
  v84.m_y = (float)m_y
          - (float)((float)v17
                  * (float)((float)((float)v19 * *(float *)&v87.m_pProxy)
                          + (float)((float)((float)m_y * (float)v17) + (float)v15)));
  v84.m_z = (float)m_z
          - (float)((float)v13
                  * (float)((float)((float)v19 * *(float *)&v87.m_pProxy)
                          + (float)((float)((float)m_y * (float)v17) + (float)v15)));
  v25 = *(bfx::Vec3 **)(v23 + *(_DWORD *)(LODWORD(v20) + 4));
  bfx::Area::CalcNormal(this: &v87, result: v25);
  if ( (unsigned __int8)bfx::MoveThroughArea(
                          origLineStart: &v86,
                          origLineDelta: &v84,
                          pArea: (bfx::Area *)v25,
                          areaNormal: (const bfx::Vec3 *)&v87,
                          endPos: &v85,
                          exitEdgeCursor: collideEdgeCursor) != 0 )
  {
    v26 = v87.m_pos.m_x;
    v27 = 4 * v24;
    while ( 1 )
    {
      v28 = v24 < *(_DWORD *)(LODWORD(v26) + 8) ? *(bfx::AreaProxy **)(*(_DWORD *)(LODWORD(v26) + 4) + v27) : nullptr;
      if ( v21 != 0
        && (v21 = 0, v28 != nullptr)
        && (m_i = collideEdgeCursor->m_i,
            v30 = collideEdgeCursor->m_pArea,
            (&collideEdgeCursor->m_pArea[1].m_pProxy)[6 * m_i] == v28) )
      {
        v31 = v30->m_flags.m_flags1 & 0x7F;
        v32 = (float *)((char *)v30 + 24 * m_i);
        __twllei(v31, 0);
        v33 = __ROL4__(m_i + 1, 1);
        v34 = v32[15];
        v35 = (float *)((char *)v30 + 24 * ((m_i + 1) % v31));
        v36 = v32[16];
        v87.m_pos.m_z = v32[17];
        v37 = v87.m_pos.m_z;
        v87.m_pos.m_x = v34;
        v38 = v35[17];
        __twlgei(v31 & ~(v33 - 1), 0xFFFFFFFF);
        v39 = v35[15];
        v40 = v35[16];
        v87.m_pos.m_y = v36;
        v91 = v38;
        v89 = v39;
        v90 = v40;
        v41 = (float)((float)__fsqrts((float)((float)((float)(v39 - v34) * (float)(v39 - v34))
                                            + (float)((float)((float)(v38 - (float)v37) * (float)(v38 - (float)v37))
                                                    + (float)((float)(v40 - v36) * (float)(v40 - v36)))))
                    * (float)0.25);
        Scale = bfx::GetScale();
        v43 = v85.m_y;
        v44 = v85.m_z;
        v45 = v85.m_x;
        v46 = (float *)((char *)collideEdgeCursor->m_pArea + 24 * collideEdgeCursor->m_i);
        v47 = v46[17];
        _FP11 = (float)((float)((float)Scale * (float)0.2) - (float)v41);
        v49 = v46[15];
        v50 = v46[16];
        v88 = v47;
        *(float *)&v87.m_flags.m_flags3 = v49;
        *(float *)&v87.m_flags.m_flags4 = v50;
        __asm { fsel      f11, f11, f27, f1 }
        if ( __fsqrts((float)((float)((float)(v85.m_x - v49) * (float)(v85.m_x - v49))
                            + (float)((float)((float)(v85.m_z - v47) * (float)(v85.m_z - v47))
                                    + (float)((float)(v85.m_y - v50) * (float)(v85.m_y - v50))))) < _FP11 )
          *distToBumpers = __fsqrts((float)((float)((float)(v85.m_x - start->m_x) * (float)(v85.m_x - start->m_x))
                                          + (float)((float)((float)(v85.m_z - start->m_z) * (float)(v85.m_z - start->m_z))
                                                  + (float)((float)(v85.m_y - start->m_y) * (float)(v85.m_y - start->m_y)))));
        m_pArea = collideEdgeCursor->m_pArea;
        v53 = collideEdgeCursor->m_i + 1;
        v54 = collideEdgeCursor->m_pArea->m_flags.m_flags1 & 0x7F;
        __twllei(v54, 0);
        __twlgei(v54 & ~(__ROL4__(v53, 1) - 1), 0xFFFFFFFF);
        v55 = (char *)m_pArea + 24 * (v53 % v54);
        v56 = *((float *)v55 + 16);
        v57 = *((float *)v55 + 17);
        v87.m_searchCost = *((_DWORD *)v55 + 15);
        *(float *)&v87.m_usageFlags = v56;
        *(float *)&v87.m_flags.m_flags1 = v57;
        if ( __fsqrts((float)((float)((float)((float)v43 - v56) * (float)((float)v43 - v56))
                            + (float)((float)((float)((float)v45 - *(float *)&v87.m_searchCost)
                                            * (float)((float)v45 - *(float *)&v87.m_searchCost))
                                    + (float)((float)((float)v44 - v57) * (float)((float)v44 - v57))))) < _FP11 )
        {
          v58 = (float)((float)v44 - start->m_z);
          v59 = (float)((float)v43 - start->m_y);
          *distToBumpers = __fsqrts((float)((float)((float)v59 * (float)v59)
                                          + (float)((float)((float)((float)v45 - start->m_x)
                                                          * (float)((float)v45 - start->m_x))
                                                  + (float)((float)v58 * (float)v58))));
        }
      }
      else
      {
        v44 = v85.m_z;
        v43 = v85.m_y;
        v45 = v85.m_x;
      }
      v60 = __fsqrts((float)((float)((float)((float)v43 - v86.m_y) * (float)((float)v43 - v86.m_y))
                           + (float)((float)((float)((float)v45 - v86.m_x) * (float)((float)v45 - v86.m_x))
                                   + (float)((float)((float)v44 - v86.m_z) * (float)((float)v44 - v86.m_z)))));
      *distToCollide = *distToCollide + (float)v60;
      v61 = collideEdgeCursor->m_pArea;
      v62 = collideEdgeCursor->m_i;
      v63 = (bfx::Vec3 *)(&collideEdgeCursor->m_pArea[1].m_pProxy)[6 * v62];
      if ( v63 == nullptr || v63 != (bfx::Vec3 *)v28 )
        return 1;
      v64 = __fsqrts((float)((float)(v84.m_x * v84.m_x)
                           + (float)((float)(v84.m_z * v84.m_z) + (float)(v84.m_y * v84.m_y))));
      if ( v64 > 1.0842022e-19 )
      {
        v65 = (float)((float)v64 - (float)v60);
        v84.m_x = (float)((float)v65 / (float)v64) * v84.m_x;
        v84.m_y = v84.m_y * (float)((float)v65 / (float)v64);
        v84.m_z = v84.m_z * (float)((float)v65 / (float)v64);
      }
      v66 = v61->m_flags.m_flags1 & 0x7F;
      v67 = (float *)(&v61[1].m_dynAreaData + 6 * v62);
      v69 = *v67;
      v70 = v66 & ~(__ROL4__(v62 + 1, 1) - 1);
      v71 = *((float *)&v61[1].m_pFirstLink + 6 * v62);
      v68 = (float *)((char *)v61 + 24 * ((v62 + 1) % v66));
      __twllei(v66, 0);
      v72 = v67[2];
      v73 = v68[15];
      __twlgei(v70, 0xFFFFFFFF);
      v92 = v69;
      v74 = v69;
      v75 = v68[16];
      v76 = v68[17];
      v94 = v72;
      v95 = v73;
      v93 = v71;
      v96 = v75;
      v97 = v76;
      _FP0 = (float)((float)__fsqrts((float)((float)((float)(v75 - v71) * (float)(v75 - v71))
                                           + (float)((float)((float)(v73 - (float)v74) * (float)(v73 - (float)v74))
                                                   + (float)((float)(v76 - v72) * (float)(v76 - v72)))))
                   - (float)1.0842022e-19);
      __asm { fsel      f12, f0, f13, f29 }
      v98.m_x = (float)(v73 - (float)v74) * (float)_FP12;
      v98.m_y = (float)(v75 - v71) * (float)_FP12;
      v98.m_z = (float)(v76 - v72) * (float)_FP12;
      v79 = bfx::Area::CalcNormal(this: &v99, result: v63);
      v80 = bfx::RotateVecIntoNewArea(
              result: &v99.m_pos,
              vec: &v84,
              edgeUnitVec: &v98,
              oldAreaNormal: (const bfx::Vec3 *)&v87,
              newAreaNormal: (const bfx::Vec3 *)v79);
      v23 += 4;
      ++v24;
      v27 += 4;
      v84.m_x = v80->m_x;
      v84.m_y = v80->m_y;
      v84.m_z = v80->m_z;
      v86.m_x = v85.m_x;
      v86.m_y = v85.m_y;
      v86.m_z = v85.m_z;
      v81 = *(bfx::Vec3 **)(*(_DWORD *)(LODWORD(v20) + 4) + v23);
      bfx::Area::CalcNormal(this: &v87, result: v81);
      if ( (unsigned __int8)bfx::MoveThroughArea(
                              origLineStart: &v86,
                              origLineDelta: &v84,
                              pArea: (bfx::Area *)v81,
                              areaNormal: (const bfx::Vec3 *)&v87,
                              endPos: &v85,
                              exitEdgeCursor: collideEdgeCursor) == 0 )
        goto LABEL_19;
    }
  }
  else
  {
LABEL_19:
    v82 = (float)((float)(origDelta->m_z * origDelta->m_z)
                + (float)((float)(origDelta->m_x * origDelta->m_x) + (float)(origDelta->m_y * origDelta->m_y)));
    if ( v82 <= COERCE_FLOAT(0x200000) )
      *distToCollide = 0.0;
    else
      *distToCollide = __fsqrts(v82);
    return 0;
  }
}


// ========================================================================
// ?CalcCircularApproachAcc@WalkerImpl@bfx@@AAA?AVVec3@2@XZ
// EA  : 0x832CF3E0
// RVA : 0x012CF3E0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

bfx::WalkerImpl *__fastcall bfx::WalkerImpl::CalcCircularApproachAcc(bfx::WalkerImpl *this, bfx::Vec3 *result)
{
  int v4; // r7
  float m_y; // r5
  double v6; // fp19
  float m_z; // r4
  double v8; // fp18
  double v9; // fp17
  int v10; // r3
  double v11; // fp31
  float *UVel; // r3
  double v13; // fp22
  double v14; // fp21
  double v15; // fp27
  double v16; // fp25
  double v17; // fp24
  double v18; // fp23
  bfx::Matrix *v19; // r30
  double v20; // fp26
  double v21; // fp20
  BOOL v22; // r29
  double v23; // fp11
  double v24; // fp10
  double v25; // fp9
  double v26; // fp7
  double v27; // fp29
  double v28; // fp28
  double v29; // fp27
  double v30; // fp0
  double v31; // fp11
  bfx::WalkerImpl *SurferUPos; // r3
  double v33; // fp3
  double v34; // fp1
  double v35; // fp12
  double v36; // fp6
  double v37; // fp9
  double v38; // fp5
  double v39; // fp29
  double v40; // fp28
  double Scale; // fp27
  double v42; // fp1
  double v43; // fp0
  double v44; // fp11
  double v46; // fp0
  double v51; // fp1
  double v52; // fp13
  float v53; // r10
  double v54; // fp11
  double v55; // fp9
  bool v58; // r11
  double v59; // fp0
  double v60; // fp0
  float *v61; // r10
  double v63; // fp0
  double v67; // fp11
  double v68; // fp9
  double v69; // fp10
  double v72; // fp27
  double v73; // fp28
  double v76; // fp3
  double v77; // fp5
  double v78; // fp4
  double v79; // fp6
  double v80; // fp8
  double v81; // fp7
  double v82; // fp10
  double v83; // fp9
  double v84; // fp11
  char v85; // r11
  double v86; // fp13
  double v87; // fp10
  double v88; // fp13
  double v93; // fp13
  double v94; // fp11
  double v95; // fp9
  char v96; // r11
  float v97; // [sp+50h] [-1C0h]
  float v98; // [sp+54h] [-1BCh]
  float m_x; // [sp+58h] [-1B8h]
  float v100; // [sp+60h] [-1B0h] BYREF
  float v101; // [sp+64h] [-1ACh]
  float v102; // [sp+68h] [-1A8h]
  float v103; // [sp+70h] [-1A0h] BYREF
  float v104; // [sp+74h] [-19Ch]
  float v105; // [sp+78h] [-198h]
  float v106; // [sp+80h] [-190h]
  float v107; // [sp+84h] [-18Ch]
  float v108; // [sp+88h] [-188h]
  float v109; // [sp+90h] [-180h]
  float v110; // [sp+94h] [-17Ch]
  float v111; // [sp+98h] [-178h]
  _BYTE v112[16]; // [sp+B0h] [-160h] BYREF
  bfx::Matrix v113; // [sp+C0h] [-150h] BYREF
  bfx::Matrix v114[3]; // [sp+100h] [-110h] BYREF

  v4 = *(_DWORD *)(LODWORD(result->m_y) + 4);
  m_y = bfx::ZERO_VEC.m_y;
  v6 = 0.0;
  m_z = bfx::ZERO_VEC.m_z;
  v8 = 0.0;
  v9 = 0.0;
  v10 = *(unsigned __int8 *)(v4 + 180);
  this->__vftable = (bfx::WalkerImpl_vtbl *)LODWORD(bfx::ZERO_VEC.m_x);
  *(float *)&this->m_commonState = m_y;
  this->m_pos3D.m_x = m_z;
  if ( v10 == 0 || BYTE2(result[12].m_z) == 0 && result[43].m_y == 0.0 )
    return this;
  v11 = result[45].m_y;
  if ( v11 <= 1.0842022e-19 )
    return this;
  bfx::WalkerImpl::GetSurferUPos(this: (bfx::WalkerImpl *)&v100, result);
  UVel = (float *)bfx::WalkerImpl::GetUVel(this: (bfx::WalkerImpl *)v112, result);
  v13 = v100;
  v14 = v101;
  v98 = result[5].m_z;
  v97 = result[5].m_y;
  v15 = (float)(v97 - v100);
  v16 = (float)(v98 - v101);
  v17 = *UVel;
  v18 = UVel[1];
  m_x = result[6].m_x;
  v19 = (bfx::Matrix *)((*(_DWORD *)(LODWORD(result[6].m_y) + 3008) << 6) + LODWORD(result[6].m_y) + 3944);
  v20 = __fsqrts((float)((float)((float)(v98 - v101) * (float)(v98 - v101))
                       + (float)((float)(v97 - v100) * (float)(v97 - v100))));
  bfx::WalkerImpl::CalcGoalURot(this: (bfx::WalkerImpl *)&v103, (bfx::Matrix *)result);
  v21 = v102;
  v22 = (float)((float)((float)((float)((float)-v16 * v103) - (float)(v104 * (float)-v15)) * v111)
              + (float)((float)(v109 * (float)((float)(v104 * (float)-(float)(m_x - v102)) - (float)(v105 * (float)-v16)))
                      + (float)((float)((float)(v105 * (float)-v15) - (float)((float)-(float)(m_x - v102) * v103)) * v110))) > 0.0;
  if ( (float)((float)((float)((float)((float)-v16 * v103) - (float)(v104 * (float)-v15)) * v111)
             + (float)((float)(v109 * (float)((float)(v104 * (float)-(float)(m_x - v102)) - (float)(v105 * (float)-v16)))
                     + (float)((float)((float)(v105 * (float)-v15) - (float)((float)-(float)(m_x - v102) * v103)) * v110))) <= 0.0 )
  {
    v23 = -v106;
    v24 = -v107;
    v25 = -v108;
  }
  else
  {
    v23 = v106;
    v24 = v107;
    v25 = v108;
  }
  v26 = result[43].m_y;
  if ( v26 == 0.0 )
  {
    v27 = (float)((float)((float)v23 * (float)v11) + v97);
    v28 = (float)((float)((float)v24 * (float)v11) + v98);
    v29 = (float)((float)((float)v25 * (float)v11) + m_x);
  }
  else
  {
    v27 = (float)((float)((float)(v106 * (float)v11) * result[45].m_z) + v97);
    v28 = (float)((float)((float)(v107 * (float)v11) * result[45].m_z) + v98);
    v29 = (float)((float)((float)(v108 * (float)v11) * result[45].m_z) + m_x);
  }
  v30 = (float)((float)((float)((float)v28 - (float)v14) * (float)((float)v28 - (float)v14))
              + (float)((float)((float)((float)v27 - (float)v13) * (float)((float)v27 - (float)v13))
                      + (float)((float)((float)v29 - v102) * (float)((float)v29 - v102))));
  if ( v26 == 0.0 )
  {
    v31 = (float)(*(float *)(*(_DWORD *)(LODWORD(result->m_y) + 4) + 184) * (float)1.1);
    if ( v30 > (float)((float)v31 * (float)v31) )
      return this;
  }
  else
  {
    v44 = (float)(result[45].m_y * (float)1.5);
    if ( v30 > (float)((float)v44 * (float)v44) )
    {
LABEL_16:
      result[43].m_y = 0.0;
      result[43].m_z = 0.0;
      result[44].m_x = -1.0;
      result[44].m_y = 0.0;
      result[44].m_z = 0.0;
      result[45].m_x = 0.0;
      HIBYTE(result[46].m_y) = 0;
      result[45].m_y = 0.0;
      result[45].m_z = 0.0;
      result[46].m_x = -1.0;
      return this;
    }
  }
  SurferUPos = bfx::WalkerImpl::GetSurferUPos(this: (bfx::WalkerImpl *)v112, result);
  bfx::Orienter::CalcMat(
    this: (bfx::Orienter *)(LODWORD(result->m_y) + 128),
    pos: (const bfx::Vec3 *)SurferUPos,
    mat: &v113);
  v113 = *bfx::Matrix::operator*(this: v114, result: v19, rhs: &v113);
  v33 = (float)((float)v29 - (float)((float)(v113.m_data[6] * (float)v11) + (float)v21));
  v34 = (float)((float)v28 - (float)((float)(v113.m_data[5] * (float)v11) + (float)v14));
  v35 = (float)((float)v29 - (float)((float)((float)(v113.m_data[6] * (float)v11) * (float)-1.0) + (float)v21));
  v36 = (float)((float)v27 - (float)((float)(v113.m_data[4] * (float)v11) + (float)v13));
  v37 = (float)((float)v28 - (float)((float)((float)(v113.m_data[5] * (float)v11) * (float)-1.0) + (float)v14));
  v38 = (float)((float)v27 - (float)((float)((float)(v113.m_data[4] * (float)v11) * (float)-1.0) + (float)v13));
  v39 = (float)((float)((float)v34 * (float)v34)
              + (float)((float)((float)v36 * (float)v36) + (float)((float)v33 * (float)v33)));
  v40 = (float)((float)((float)v37 * (float)v37)
              + (float)((float)((float)v38 * (float)v38) + (float)((float)v35 * (float)v35)));
  if ( result[43].m_y == 0.0 )
  {
    Scale = bfx::GetScale();
    v42 = bfx::GetScale();
    v43 = 0.2;
  }
  else
  {
    Scale = bfx::GetScale();
    v42 = bfx::GetScale();
    v43 = 0.30000001;
  }
  v46 = (float)((float)((float)Scale * (float)v42) * (float)v43);
  _FP13 = (float)((float)v39 - (float)v40);
  __asm { fsel      f27, f13, f28, f29 }
  if ( v39 <= v46 || v40 <= v46 )
  {
    v51 = bfx::GetScale();
    v52 = (float)(result[4].m_z - (float)v21);
    v53 = result->m_y;
    v54 = (float)(result[4].m_x - (float)v13);
    v55 = (float)(result[4].m_y - (float)v14);
    _FP3 = (float)((float)(*(float *)(*(_DWORD *)(LODWORD(v53) + 4) + 184) * (float)0.029999999)
                 - (float)((float)v51 * (float)0.029999999));
    __asm { fsel      f1, f3, f5, f8 }
    v58 = __fsqrts((float)((float)((float)v55 * (float)v55)
                         + (float)((float)((float)v54 * (float)v54) + (float)((float)v52 * (float)v52)))) < _FP1;
    if ( result[43].m_y == 0.0 && v58 )
    {
      if ( v39 > v40 )
        result[43].m_y = -1.0;
      else
        result[43].m_y = 1.0;
      result[43].m_z = __fsqrts((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)));
      if ( v22 )
        v59 = 1.0;
      else
        v59 = -1.0;
      result[45].m_z = v59;
    }
    v60 = result[43].m_y;
    result[46].m_x = _FP27;
    if ( v60 == 0.0 )
      return this;
    v61 = *(float **)(LODWORD(v53) + 4);
    _FP2 = (float)((float)(result[43].m_z * result[43].m_z) / (float)v11);
    v63 = (float)((float)((float)(*v61 * 2.0) * (float)(*v61 * 2.0)) / result[45].m_y);
    if ( __fabs(_FP2) > v63 )
    {
      _FP12 = (float)((float)((float)((float)(*v61 * 2.0) * (float)(*v61 * 2.0)) / result[45].m_y)
                    - (float)((float)(result[43].m_z * result[43].m_z) / (float)v11));
      _FP11 = (float)((float)-v63 - (float)((float)(result[43].m_z * result[43].m_z) / (float)v11));
      __asm { fsel      f10, f11, f13, f2 }
      __asm { fsel      f2, f12, f9, f0 }
    }
    v67 = (float)(result[45].m_x - (float)v21);
    v68 = (float)(result[44].m_z - (float)v14);
    v69 = (float)(result[44].m_y - (float)v13);
    _FP3 = (float)((float)__fsqrts((float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)))
                 - 1.0842022e-19);
    __asm { fsel      f3, f3, f5, f30 }
    v72 = (float)((float)_FP3 * (float)0.0);
    v73 = (float)((float)v18 * (float)_FP3);
    _FP0 = (float)((float)__fsqrts((float)((float)((float)v68 * (float)v68)
                                         + (float)((float)((float)v69 * (float)v69) + (float)((float)v67 * (float)v67))))
                 - 1.0842022e-19);
    __asm { fsel      f14, f0, f5, f30 }
    v77 = (float)((float)((float)((float)_FP3 * (float)0.0) * v110) - (float)((float)((float)v18 * (float)_FP3) * v111));
    v78 = (float)((float)(v111 * (float)((float)_FP3 * (float)v17)) - (float)((float)((float)_FP3 * (float)0.0) * v109));
    v79 = (float)((float)((float)((float)(v111 * (float)((float)_FP3 * (float)v17))
                                - (float)((float)((float)_FP3 * (float)0.0) * v109))
                        * (float)((float)(result[44].m_z - (float)v14) * (float)_FP14))
                + (float)((float)((float)((float)((float)((float)_FP3 * (float)0.0) * v110)
                                        - (float)((float)((float)v18 * (float)_FP3) * v111))
                                * (float)((float)_FP14 * (float)(result[44].m_y - (float)v13)))
                        + (float)((float)((float)((float)((float)v18 * (float)_FP3) * v109)
                                        - (float)(v110 * (float)((float)_FP3 * (float)v17)))
                                * (float)((float)(result[45].m_x - (float)v21) * (float)_FP14))));
    v76 = (float)((float)((float)((float)v18 * (float)_FP3) * v109) - (float)(v110 * (float)((float)_FP3 * (float)v17)));
    if ( v79 < 0.0 )
    {
      v77 = (float)((float)((float)((float)v72 * v110) - (float)((float)v73 * v111)) * (float)-1.0);
      v78 = (float)((float)v78 * (float)-1.0);
      v76 = (float)((float)v76 * (float)-1.0);
    }
    v80 = (float)(result[45].m_x - (float)v21);
    v81 = (float)(result[44].m_y - (float)v13);
    v82 = (float)(result[45].m_y * (float)0.99000001);
    v83 = __fsqrts((float)((float)((float)v68 * (float)v68)
                         + (float)((float)((float)v81 * (float)v81) + (float)((float)v80 * (float)v80))));
    if ( v83 >= v82 && v83 <= (float)(result[45].m_y * (float)1.01) )
      goto LABEL_49;
    v84 = (float)((float)((float)((float)(result[45].m_x - (float)v21) * (float)_FP14) * (float)0.0)
                + (float)((float)((float)((float)_FP14 * (float)(result[44].m_y - (float)v13)) * (float)v17)
                        + (float)((float)((float)(result[44].m_z - (float)v14) * (float)_FP14) * (float)v18)));
    if ( v83 >= v82 )
    {
      v85 = 1;
      if ( v84 > 0.0 )
        goto LABEL_45;
    }
    else if ( v84 <= 0.0 )
    {
      v85 = 1;
LABEL_45:
      if ( v85 != 0 )
        v86 = 1.0;
      else
        v86 = -1.0;
      v8 = (float)((float)((float)((float)((float)(result[44].m_z - (float)v14) * (float)_FP14)
                                 * (float)((float)((float)((float)(result[45].m_x - (float)v21) * (float)_FP14)
                                                 * (float)0.0)
                                         + (float)((float)((float)((float)_FP14 * (float)(result[44].m_y - (float)v13))
                                                         * (float)v17)
                                                 + (float)((float)((float)(result[44].m_z - (float)v14) * (float)_FP14)
                                                         * (float)v18))))
                         * (float)((float)v86 * bfx::g_walkerOrbitFeedbackK2))
                 + (float)((float)-(float)((float)(result[44].m_z - (float)v14) * (float)_FP14)
                         * (float)((float)(result[45].m_y - (float)v83) * bfx::g_walkerOrbitFeedbackK1)));
      v6 = (float)((float)((float)((float)((float)_FP14 * (float)(result[44].m_y - (float)v13))
                                 * (float)((float)((float)((float)(result[45].m_x - (float)v21) * (float)_FP14)
                                                 * (float)0.0)
                                         + (float)((float)((float)((float)_FP14 * (float)(result[44].m_y - (float)v13))
                                                         * (float)v17)
                                                 + (float)((float)((float)(result[44].m_z - (float)v14) * (float)_FP14)
                                                         * (float)v18))))
                         * (float)((float)v86 * bfx::g_walkerOrbitFeedbackK2))
                 + (float)((float)-(float)((float)_FP14 * (float)(result[44].m_y - (float)v13))
                         * (float)((float)(result[45].m_y - (float)v83) * bfx::g_walkerOrbitFeedbackK1)));
      v9 = (float)((float)((float)((float)((float)(result[45].m_x - (float)v21) * (float)_FP14)
                                 * (float)((float)((float)((float)(result[45].m_x - (float)v21) * (float)_FP14)
                                                 * (float)0.0)
                                         + (float)((float)((float)((float)_FP14 * (float)(result[44].m_y - (float)v13))
                                                         * (float)v17)
                                                 + (float)((float)((float)(result[44].m_z - (float)v14) * (float)_FP14)
                                                         * (float)v18))))
                         * (float)((float)v86 * bfx::g_walkerOrbitFeedbackK2))
                 + (float)((float)-(float)((float)(result[45].m_x - (float)v21) * (float)_FP14)
                         * (float)((float)(result[45].m_y - (float)v83) * bfx::g_walkerOrbitFeedbackK1)));
LABEL_49:
      v87 = __fabs((float)((float)v83 - result[45].m_y));
      v88 = (float)-(float)((float)(v61[46] * (float)0.1) - (float)v87);
      if ( v88 > 0.0 )
      {
        _FP10 = (float)((float)-1.0
                      - (float)((float)(v61[2] - (float)-(float)((float)(v61[46] * (float)0.1) - (float)v87)) / v61[2]));
        _FP9 = (float)((float)1.0 - (float)((float)(v61[2] - (float)v88) / v61[2]));
        __asm { fsel      f8, f10, f13, f11 }
        __asm { fsel      f6, f9, f7, f26 }
        _FP2 = (float)((float)__fabs(_FP6) * (float)_FP2);
      }
      v93 = *(float *)&this->__vftable;
      v94 = *(float *)&this->m_commonState;
      v95 = this->m_pos3D.m_x;
      result[53].m_z = v77;
      result[54].m_x = v78;
      result[54].m_y = v76;
      result[54].m_z = (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)) / (float)_FP2;
      result[55].m_x = v13;
      result[55].m_y = v14;
      result[55].m_z = v21;
      *(float *)&this->__vftable = (float)((float)v77 * (float)_FP2) + (float)v93;
      *(float *)&this->m_commonState = (float)((float)v78 * (float)_FP2) + (float)v94;
      this->m_pos3D.m_x = (float)((float)v76 * (float)_FP2) + (float)v95;
      if ( v6 != 0.0 || v8 != 0.0 || (v96 = 1, v9 != 0.0) )
        v96 = 0;
      if ( v96 == 0 )
      {
        *(float *)&this->__vftable = (float)((float)((float)v77 * (float)_FP2) + (float)v93) + (float)v6;
        *(float *)&this->m_commonState = (float)((float)((float)v78 * (float)_FP2) + (float)v94) + (float)v8;
        this->m_pos3D.m_x = (float)((float)((float)v76 * (float)_FP2) + (float)v95) + (float)v9;
      }
      return this;
    }
    v85 = 0;
    goto LABEL_45;
  }
  if ( result[43].m_y == 0.0 )
  {
    result[46].m_x = _FP27;
    return this;
  }
  _FP8 = (float)((float)(*(float *)(*(_DWORD *)(LODWORD(result->m_y) + 4) + 184) * (float)0.1)
               - (float)(bfx::GetScale() * (float)0.1));
  __asm { fsel      f7, f8, f10, f12 }
  if ( __fabs((float)((float)v20 - result[45].m_y)) > _FP7 )
    goto LABEL_16;
  return this;
}


// ========================================================================
// ?GetObservedVel@WalkerImpl@bfx@@ABA?AVVec3@2@XZ
// EA  : 0x832CFBE8
// RVA : 0x012CFBE8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

bfx::WalkerImpl *__fastcall bfx::WalkerImpl::GetObservedVel(bfx::WalkerImpl *this, bfx::Vec3 *result)
{
  double v2; // fp7
  double v3; // fp6
  float m_y; // r10
  float m_z; // r9
  float m_x; // r10
  float v7; // r9

  if ( *(_BYTE *)(*(_DWORD *)(LODWORD(result->m_y) + 4) + 248) != 0 )
  {
    if ( HIBYTE(result[28].m_z) != 0 )
    {
      v2 = (float)(result[30].m_y + result[29].m_y);
      v3 = (float)(result[30].m_z + result[29].m_z);
      result[31].m_x = (float)(result[30].m_x + result[29].m_x) * (float)0.5;
      result[31].m_y = (float)v2 * (float)0.5;
      result[31].m_z = (float)v3 * (float)0.5;
      HIBYTE(result[28].m_z) = 0;
    }
    m_y = result[31].m_y;
    m_z = result[31].m_z;
    this->__vftable = (bfx::WalkerImpl_vtbl *)LODWORD(result[31].m_x);
    *(float *)&this->m_commonState = m_y;
    this->m_pos3D.m_x = m_z;
  }
  else
  {
    m_x = result[2].m_x;
    v7 = result[2].m_y;
    this->__vftable = (bfx::WalkerImpl_vtbl *)LODWORD(result[1].m_z);
    *(float *)&this->m_commonState = m_x;
    this->m_pos3D.m_x = v7;
  }
  return this;
}


// ========================================================================
// ?GetObservedUVel@WalkerImpl@bfx@@ABA?AVVec3@2@XZ
// EA  : 0x832CFC90
// RVA : 0x012CFC90
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

bfx::WalkerImpl *__fastcall bfx::WalkerImpl::GetObservedUVel(bfx::WalkerImpl *this, bfx::Vec3 *result)
{
  int v3; // r4
  bfx::Vec3 v5; // [sp+50h] [-20h] BYREF

  bfx::WalkerImpl::GetObservedVel(this: (bfx::WalkerImpl *)&v5, result);
  bfx::Matrix::Rot(
    (bfx::Matrix *)this,
    result: (bfx::Vec3 *)((*(_DWORD *)(*(_DWORD *)(v3 + 76) + 4968) << 6) + *(_DWORD *)(v3 + 76) + 4008),
    rhs: &v5);
  return this;
}


// ========================================================================
// ?UpdateHeading@WalkerImpl@bfx@@AAAXM@Z
// EA  : 0x832CFCE8
// RVA : 0x012CFCE8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::WalkerImpl::UpdateHeading(bfx::WalkerImpl *this, double simTime)
{
  bfx::UPath *m_pUPath; // r11
  bfx::Vec3 *v4; // r4
  bfx::WalkerImpl *ObservedVel; // r3
  char v6; // r8
  const bfx::Vec3 *v7; // r7
  const bfx::Vec3 *v8; // r6
  long double v9; // fp4
  long double v10; // fp2
  bfx::WalkerImpl::State m_state; // r11
  bfx::WalkerImpl *v12; // r3
  const bfx::Vec3 *v13; // r8
  const bfx::Vec3 *v14; // r6
  long double v15; // fp4
  long double v16; // fp2
  bfx::MotionState *m_commonState; // r11
  float m_y; // r9
  float m_z; // r8
  double Scale; // fp1
  double v21; // fp4
  double v22; // fp2
  bfx::WalkerImpl *v23; // r3
  const bfx::Vec3 *v24; // r6
  long double v25; // fp4
  long double v26; // fp2
  bfx::WalkerImpl::State v27; // r9
  bfx::Vec3 v28; // [sp+50h] [-60h] BYREF
  float v29; // [sp+60h] [-50h]
  float v30; // [sp+64h] [-4Ch]
  float v31; // [sp+68h] [-48h]
  bfx::Matrix v32; // [sp+70h] [-40h] BYREF

  m_pUPath = this->m_pUPath;
  if ( m_pUPath != nullptr )
    v4 = (bfx::Vec3 *)&m_pUPath->m_u2g[m_pUPath->m_curIdx];
  else
    v4 = (bfx::Vec3 *)&bfx::IDENTITY;
  bfx::Matrix::operator*(this: &v32, result: v4, rhs: &this->m_targetPosU);
  ObservedVel = bfx::WalkerImpl::GetObservedVel(this: (bfx::WalkerImpl *)&v32.m_data[4], result: (bfx::Vec3 *)this);
  bfx::Orienter::Simulate(
    this: &this->m_commonState->m_orienter,
    pos: v8,
    vel: (const bfx::Vec3 *)ObservedVel,
    simTime: v10,
    nextCornerG: v8,
    bForceUseClientMotion: v7,
    a7: v6,
    a8: v9);
  m_state = this->m_state;
  if ( m_state == 1 )
  {
    v12 = bfx::WalkerImpl::GetObservedVel(this: (bfx::WalkerImpl *)&v32.m_data[4], result: (bfx::Vec3 *)this);
    if ( __fabs(
           bfx::Orienter::CalcHeadingError(
             this: &this->m_commonState->m_orienter,
             pos: v13,
             vel: (const bfx::Vec3 *)v12,
             nextCornerG: v14,
             a5: v16,
             a6: v15)) < 0.087266468 )
      bfx::WalkerImpl::SwitchState(this, newState: PATH_MOVE);
    this->m_commonState->m_blockedMonitor.m_blockedTimer = 0.0;
  }
  else if ( m_state == 4 )
  {
    m_commonState = this->m_commonState;
    m_y = m_commonState->m_surfer.m_pos.m_y;
    m_z = m_commonState->m_surfer.m_pos.m_z;
    v28.m_x = m_commonState->m_surfer.m_pos.m_x;
    v28.m_y = m_y;
    v28.m_z = m_z;
    Scale = bfx::GetScale();
    v21 = (float)(this->m_goalData.m_goalDir.m_z * (float)((float)Scale * (float)10.0));
    v22 = (float)(v28.m_y + (float)(this->m_goalData.m_goalDir.m_y * (float)((float)Scale * (float)10.0)));
    v29 = (float)(this->m_goalData.m_goalDir.m_x * (float)((float)Scale * (float)10.0)) + v28.m_x;
    v30 = v22;
    v31 = v28.m_z + (float)v21;
    v23 = bfx::WalkerImpl::GetObservedVel(this: (bfx::WalkerImpl *)&v32.m_data[4], result: (bfx::Vec3 *)this);
    if ( __fabs(
           bfx::Orienter::CalcHeadingError(
             this: &this->m_commonState->m_orienter,
             pos: &v28,
             vel: (const bfx::Vec3 *)v23,
             nextCornerG: v24,
             a5: v26,
             a6: v25)) < 0.087266468 )
    {
      bfx::EnactDelayedOrientationMode(
        action: &this->m_onFinalRotationAction,
        orienter: &this->m_commonState->m_orienter);
      v27 = this->m_state;
      this->m_reachedGoal = true;
      if ( v27 == 4 )
      {
        this->m_onFinalRotationAction.m_restartGotoPos = false;
        this->m_onFinalRotationAction.m_changeOrientMode = false;
      }
      this->m_orbitDirection = 0.0;
      this->m_orbitSpeed = 0.0;
      this->m_orbitMinDist = -1.0;
      this->m_orbitCenter.m_x = 0.0;
      this->m_orbitCenter.m_y = 0.0;
      this->m_orbitCenter.m_z = 0.0;
      this->m_orbitDisable = false;
      this->m_orbitRadius = 0.0;
      this->m_state = DONE_MOVING;
      this->m_orbitGoalDirection = 0.0;
      this->m_orbitPrevMinDist = -1.0;
    }
    this->m_commonState->m_blockedMonitor.m_blockedTimer = 0.0;
  }
}


// ========================================================================
// ?DrawRVODebugData@bfx@@YAXABURVODebugDrawInfo@1@ABVMotionState@1@@Z
// EA  : 0x832CFF18
// RVA : 0x012CFF18
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::DrawRVODebugData(const bfx::RVODebugDrawInfo *rvoDebugData, const bfx::MotionState *commonState)
{
  __int64 v4; // r10
  __int64 v5; // r8
  char v6; // r11
  bfx::Vec3 *p_m_velocityCircleCenter; // r29
  __int64 v8; // r6
  double m_velocityCircleRadius; // fp31
  bfx::Orienter *LocalUpAxis; // r3
  const bfx::Color *v11; // r6
  double m_y; // fp13
  double m_z; // fp12
  double m_x; // fp11
  double v15; // fp10
  bfx::Space *m_pSpace; // r3
  double v17; // fp9
  double v18; // fp7
  double v19; // fp6
  double v20; // fp5
  double v21; // fp4
  bfx::Space *v22; // r3
  double v23; // fp3
  bool *m_isValidVelCircPt; // r27
  int v25; // r28
  float *p_m_z; // r31
  double v27; // fp13
  double v28; // fp12
  double v29; // fp11
  bfx::Space *v30; // r3
  double v31; // fp10
  double v32; // fp9
  int v33; // [sp+8h] [-F8h]
  int v34; // [sp+Ch] [-F4h]
  int v35; // [sp+10h] [-F0h]
  int v36; // [sp+14h] [-ECh]
  int v37; // [sp+18h] [-E8h]
  int v38; // [sp+1Ch] [-E4h]
  int v39; // [sp+20h] [-E0h]
  int v40; // [sp+24h] [-DCh]
  char v41; // [sp+50h] [-B0h] BYREF
  bfx::Color v42; // [sp+60h] [-A0h] BYREF
  bfx::Vec3 v43; // [sp+70h] [-90h] BYREF
  float v44; // [sp+7Ch] [-84h]
  float v45; // [sp+80h] [-80h]
  float v46; // [sp+84h] [-7Ch]
  bfx::Vec3 v47; // [sp+90h] [-70h] BYREF
  float v48; // [sp+9Ch] [-64h]
  float v49; // [sp+A0h] [-60h]
  float v50; // [sp+A4h] [-5Ch]
  bfx::Vec3 v51; // [sp+B0h] [-50h] BYREF
  float v52; // [sp+BCh] [-44h]
  float v53; // [sp+C0h] [-40h]
  float v54; // [sp+C4h] [-3Ch]

  bfx::GenerateRandomColor(result: &v42, seedNum: rvoDebugData->m_yourID);
  if ( v42.m_r != ColorBlack_28.m_r
    || v42.m_g != ColorBlack_28.m_g
    || v42.m_b != ColorBlack_28.m_b
    || (v6 = 1, v42.m_a != ColorBlack_28.m_a) )
  {
    v6 = 0;
  }
  if ( v6 != 0 )
  {
    LODWORD(v4) = &v42;
    HIDWORD(v4) = &ColorGray_28;
    LODWORD(v5) = LODWORD(ColorGray_28.m_r);
    v42 = ColorGray_28;
  }
  HIDWORD(v5) = rvoDebugData->m_numWedges;
  p_m_velocityCircleCenter = &rvoDebugData->m_velocityCircleCenter;
  LODWORD(v8) = rvoDebugData->m_yourID;
  HIDWORD(v8) = "yourID=%d #wedges=%d";
  bfx::DrawString(
    pSpace: (bfx::Vector3 *)commonState->m_pSpace,
    inputPos: &rvoDebugData->m_velocityCircleCenter,
    fmt: v8,
    a4: v5,
    a5: v4,
    a6: v33,
    a7: v34,
    a8: v35,
    a9: v36,
    a10: v37,
    a11: v38,
    a12: v39,
    a13: v40);
  if ( !rvoDebugData->m_overlapped )
  {
    m_velocityCircleRadius = rvoDebugData->m_velocityCircleRadius;
    LocalUpAxis = bfx::Orienter::GetLocalUpAxis(
                    this: (bfx::Orienter *)&v41,
                    result: (bfx::Vec3 *)&commonState->m_orienter);
    bfx::DrawCircle(
      pSpace: commonState->m_pSpace,
      pos: &rvoDebugData->m_velocityCircleCenter,
      N: (const bfx::Vec3 *)LocalUpAxis,
      radius: m_velocityCircleRadius,
      color: v11,
      a6: &v42);
    m_y = rvoDebugData->m_startPos1.m_y;
    m_z = rvoDebugData->m_startPos1.m_z;
    m_x = rvoDebugData->m_myPos.m_x;
    v15 = rvoDebugData->m_myPos.m_y;
    m_pSpace = commonState->m_pSpace;
    v17 = rvoDebugData->m_myPos.m_z;
    v43.m_x = rvoDebugData->m_startPos1.m_x;
    v43.m_y = m_y;
    v43.m_z = m_z;
    v44 = m_x;
    v45 = v15;
    v46 = v17;
    bfx::DrawLineList(pSpace: m_pSpace, pVerts: &v43, numVerts: 2, color: &v42);
    v18 = rvoDebugData->m_startPos2.m_y;
    v19 = rvoDebugData->m_startPos2.m_z;
    v20 = rvoDebugData->m_myPos.m_x;
    v21 = rvoDebugData->m_myPos.m_y;
    v22 = commonState->m_pSpace;
    v23 = rvoDebugData->m_myPos.m_z;
    v47.m_x = rvoDebugData->m_startPos2.m_x;
    v47.m_y = v18;
    v47.m_z = v19;
    v48 = v20;
    v49 = v21;
    v50 = v23;
    bfx::DrawLineList(pSpace: v22, pVerts: &v47, numVerts: 2, color: &v42);
    m_isValidVelCircPt = rvoDebugData->m_isValidVelCircPt;
    v25 = 0;
    p_m_z = &rvoDebugData->m_velCircPt[0].m_z;
    do
    {
      if ( m_isValidVelCircPt[v25] )
      {
        v27 = p_m_velocityCircleCenter->m_y;
        v28 = p_m_velocityCircleCenter->m_z;
        v29 = *(p_m_z - 2);
        v30 = commonState->m_pSpace;
        v31 = *(p_m_z - 1);
        v32 = *p_m_z;
        v51.m_x = p_m_velocityCircleCenter->m_x;
        v51.m_y = v27;
        v51.m_z = v28;
        v52 = v29;
        v53 = v31;
        v54 = v32;
        bfx::DrawLineList(pSpace: v30, pVerts: &v51, numVerts: 2, color: &v42);
      }
      ++v25;
      p_m_z += 3;
    }
    while ( v25 < 4 );
  }
}


// ========================================================================
// ?DrawHedgehogDebugData@bfx@@YAXABUHedgehogDebugDrawInfo@1@ABVMotionState@1@PBVMatrix@1@@Z
// EA  : 0x832D0120
// RVA : 0x012D0120
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::DrawHedgehogDebugData(
        const bfx::HedgehogDebugDrawInfo *debugData,
        const bfx::MotionState *commonState,
        bfx::Vec3 *pAdjustMat)
{
  float m_y; // r8
  float m_z; // r6
  float m_x; // r5
  float v9; // r4
  float v10; // r11
  float v11; // r26
  float v12; // r25
  float v13; // r24
  bfx::Matrix *v14; // r3
  bfx::Matrix *v15; // r3
  bfx::Matrix *v16; // r3
  double Scale; // fp1
  double m_sphereRadius; // fp31
  bfx::Orienter *LocalUpAxis; // r3
  const bfx::Color *v20; // r6
  bfx::Space *m_pSpace; // r3
  bfx::Vec3 v22; // [sp+50h] [-D0h] BYREF
  bfx::Vec3 v23; // [sp+60h] [-C0h] BYREF
  bfx::Vec3 v24; // [sp+70h] [-B0h] BYREF
  bfx::Matrix v25; // [sp+80h] [-A0h] BYREF
  float v26; // [sp+C0h] [-60h]
  float v27; // [sp+C4h] [-5Ch]

  m_y = debugData->m_sphereCenter.m_y;
  m_z = debugData->m_sphereCenter.m_z;
  v9 = debugData->m_probeStart.m_y;
  v10 = debugData->m_probeStart.m_z;
  m_x = debugData->m_probeStart.m_x;
  v11 = debugData->m_probeNormalizedDir.m_x;
  v12 = debugData->m_probeNormalizedDir.m_y;
  v13 = debugData->m_probeNormalizedDir.m_z;
  v24.m_x = debugData->m_sphereCenter.m_x;
  *(bfx::Color *)&v25.m_data[8] = ColorWhite_28;
  v24.m_y = m_y;
  v24.m_z = m_z;
  v23.m_x = m_x;
  v23.m_y = v9;
  v23.m_z = v10;
  v22.m_x = v11;
  v22.m_y = v12;
  v22.m_z = v13;
  if ( pAdjustMat != nullptr )
  {
    v14 = bfx::Matrix::operator*(this: &v25, result: pAdjustMat, rhs: &v23);
    v23.m_x = v14->m_data[0];
    v23.m_y = v14->m_data[1];
    v23.m_z = v14->m_data[2];
    v15 = bfx::Matrix::operator*(this: (bfx::Matrix *)&v25.m_data[4], result: pAdjustMat, rhs: &v24);
    v24.m_x = v15->m_data[0];
    v24.m_y = v15->m_data[1];
    v24.m_z = v15->m_data[2];
    v16 = bfx::Matrix::Rot(this: &v25, result: pAdjustMat, rhs: &v22);
    v22.m_x = v16->m_data[0];
    v22.m_y = v16->m_data[1];
    v22.m_z = v16->m_data[2];
  }
  Scale = bfx::GetScale();
  m_sphereRadius = debugData->m_sphereRadius;
  v22.m_x = (float)((float)Scale * (float)5.0) * v22.m_x;
  v22.m_y = v22.m_y * (float)((float)Scale * (float)5.0);
  v22.m_z = v22.m_z * (float)((float)Scale * (float)5.0);
  LocalUpAxis = bfx::Orienter::GetLocalUpAxis(
                  this: (bfx::Orienter *)&v25.m_data[4],
                  result: (bfx::Vec3 *)&commonState->m_orienter);
  bfx::DrawCircle(
    pSpace: commonState->m_pSpace,
    pos: &v24,
    N: (const bfx::Vec3 *)LocalUpAxis,
    radius: m_sphereRadius,
    color: v20,
    a6: (const bfx::Color *)&v25.m_data[8]);
  if ( debugData->m_spineHit )
  {
    m_pSpace = commonState->m_pSpace;
    v25.m_data[12] = v23.m_x;
    v25.m_data[13] = v23.m_y;
    v25.m_data[14] = v23.m_z;
    v25.m_data[15] = v22.m_x + v23.m_x;
    v26 = v22.m_y + v23.m_y;
    v27 = v22.m_z + v23.m_z;
    bfx::DrawLineList(
      pSpace: m_pSpace,
      pVerts: (bfx::Vec3 *)&v25.m_data[12],
      numVerts: 2,
      color: (const bfx::Color *)&v25.m_data[8]);
  }
  bfx::DrawAxes(pSpace: commonState->m_pSpace, pos: &v23);
}


// ========================================================================
// ?DrawRVOWedges@bfx@@YAXABV?$Array@VRVOWedge@bfx@@@1@ABVMatrix@1@PAVSpace@1@@Z
// EA  : 0x832D0308
// RVA : 0x012D0308
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::DrawRVOWedges(const bfx::Array<bfx::RVOWedge> *rvoWedges, bfx::Vec3 *mat, bfx::Vector3 *pSpace)
{
  int v6; // r31
  int v7; // r30
  bfx::RVOWedge *m_data; // r11
  float *p_m_leftAngle; // r11
  double v10; // fp27
  double v11; // fp26
  double v12; // fp3
  long double v13; // fp2
  int v14; // r6
  const bfx::Color *v15; // r5
  const bfx::Matrix *v16; // r4
  bfx::Color v17; // [sp+50h] [-70h] BYREF

  v6 = 0;
  if ( rvoWedges->m_size > 0 )
  {
    v7 = 0;
    do
    {
      v17.m_r = 1.0;
      m_data = rvoWedges->m_data;
      v17.m_g = 0.0;
      v17.m_b = 0.0;
      p_m_leftAngle = &m_data[v7].m_leftAngle;
      v17.m_a = 0.5;
      v10 = p_m_leftAngle[1];
      v11 = *p_m_leftAngle;
      v12 = (float)(bfx::GetScale() * (float)5.0);
      *((double *)&v13 + 1) = v10;
      *(double *)&v13 = v11;
      bfx::DrawArc(a1: pSpace, endAngleInRadians: v13, radius: v12, mat: v16, drawCol: v15, a6: v14, a7: mat, a8: &v17);
      ++v6;
      ++v7;
    }
    while ( v6 < rvoWedges->m_size );
  }
}


// ========================================================================
// ?GetBoundingBox@SavedPositions@bfx@@QAA_NAAVBox@2@@Z
// EA  : 0x832D03C0
// RVA : 0x012D03C0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

int __fastcall bfx::SavedPositions::GetBoundingBox(bfx::SavedPositions *this, bfx::Box *bboxOut)
{
  bfx::Vec3 *p_m_max; // r6
  int result; // r3
  int m_numUsed; // r11
  int v6; // r9
  float *p_m_x; // r11

  p_m_max = &bboxOut->m_max;
  bboxOut->m_min.m_x = 0.0;
  bboxOut->m_min.m_y = 0.0;
  bboxOut->m_min.m_z = 0.0;
  bboxOut->m_max.m_x = 0.0;
  bboxOut->m_max.m_y = 0.0;
  bboxOut->m_max.m_z = 0.0;
  m_numUsed = this->m_numUsed;
  result = 0;
  if ( m_numUsed >= 10 )
  {
    result = 1;
    v6 = 0;
    do
    {
      p_m_x = &this->m_positions[(this->m_latestIdx - v6 + 10) % 10].m_x;
      if ( v6 != 0 )
      {
        _FP9 = (float)(bboxOut->m_min.m_y - p_m_x[1]);
        _FP7 = (float)(bboxOut->m_min.m_z - p_m_x[2]);
        _FP6 = (float)(bboxOut->m_min.m_x - *p_m_x);
        __asm { fsel      f5, f9, f13, f11 }
        bboxOut->m_min.m_y = _FP5;
        __asm { fsel      f4, f7, f12, f10 }
        bboxOut->m_min.m_z = _FP4;
        __asm { fsel      f3, f6, f0, f8 }
        bboxOut->m_min.m_x = _FP3;
        _FP9 = (float)(p_m_max->m_x - *p_m_x);
        _FP10 = (float)(bboxOut->m_max.m_z - p_m_x[2]);
        _FP8 = (float)(bboxOut->m_max.m_y - p_m_x[1]);
        __asm { fsel      f7, f10, f11, f12 }
        bboxOut->m_max.m_z = _FP7;
        __asm { fsel      f6, f9, f0, f1 }
        p_m_max->m_x = _FP6;
        __asm { fsel      f5, f8, f2, f13 }
        bboxOut->m_max.m_y = _FP5;
      }
      else
      {
        bboxOut->m_min.m_x = *p_m_x;
        bboxOut->m_min.m_y = p_m_x[1];
        bboxOut->m_min.m_z = p_m_x[2];
        p_m_max->m_x = *p_m_x;
        bboxOut->m_max.m_y = p_m_x[1];
        bboxOut->m_max.m_z = p_m_x[2];
      }
      ++v6;
    }
    while ( v6 < this->m_numUsed );
  }
  return result;
}


// ========================================================================
// ?AddPosition@SavedPositions@bfx@@QAAXABVVec3@2@@Z
// EA  : 0x832D0510
// RVA : 0x012D0510
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::SavedPositions::AddPosition(bfx::SavedPositions *this, const bfx::Vec3 *newPos)
{
  int v2; // r11
  int v3; // r11

  v2 = (this->m_latestIdx + 1) % 10;
  this->m_latestIdx = v2;
  this->m_positions[v2] = *newPos;
  v3 = this->m_numUsed + 1;
  this->m_numUsed = v3;
  if ( v3 > 10 )
    v3 = 10;
  this->m_numUsed = v3;
}


// ========================================================================
// ?GetDesSpeed@WalkerImpl@bfx@@AAAMXZ
// EA  : 0x832D0590
// RVA : 0x012D0590
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

float __fastcall bfx::WalkerImpl::GetDesSpeed(bfx::WalkerImpl *this)
{
  bfx::MotionState *m_commonState; // r10
  bfx::HandleProxy *m_pProxy; // r9
  double m_followSpeedX; // fp0
  double v4; // fp1

  m_commonState = this->m_commonState;
  m_pProxy = m_commonState->m_followData.m_targetMover.m_pProxy;
  if ( m_pProxy != nullptr && m_pProxy->m_pTarget != nullptr )
    m_followSpeedX = m_commonState->m_followData.m_followSpeedX;
  else
    m_followSpeedX = 1.0;
  v4 = (float)((float)((float)(m_commonState->m_pTune->m_speed * m_commonState->m_cautionData.m_internalSpeedX)
                     * m_commonState->m_speedX)
             * (float)m_followSpeedX);
  return *((float *)&v4 + 1);
}


// ========================================================================
// ?Initialize@WalkerImpl@bfx@@UAAXABVVec3@2@ABVMatrix@2@@Z
// EA  : 0x832D05E0
// RVA : 0x012D05E0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::WalkerImpl::Initialize(bfx::WalkerImpl *this, const bfx::Vec3 *vel, const bfx::Matrix *startMat)
{
  bfx::Vec3 *p_m_vel; // r28
  bfx::MotionState *m_commonState; // r11
  unsigned int m_planLayer; // r10
  bfx::NavLayer *v7; // r27
  const bfx::Vec3 *p_m_pos; // r26
  bfx::Orienter *LocalUpAxis; // r3
  bfx::MotionState *v10; // r10
  bfx::Prober *m_pProber; // r9
  bfx::Vec3 *v12; // r11
  float m_y; // r7
  float m_z; // r6
  double v15; // fp8
  double v16; // fp6
  bfx::UPath *m_pUPath; // r30
  bfx::OrientMode v18; // r10
  bfx::OrientMode v19; // r9
  double v20; // fp0
  double v21; // fp13
  double v22; // fp12
  double v23; // fp11
  double v24; // fp10
  double v25; // fp9
  bfx::MotionState *v26; // r11
  bfx::DelayedAction *p_m_onFinalRotationAction; // r30
  float v28; // r5
  float v29; // r8
  float v30; // r3
  double v31; // fp3
  double v32; // fp0
  const bfx::Vec3 *v33; // r3
  double v34; // fp0
  double v35; // fp13
  double v36; // fp12
  bfx::MotionState *v37; // r11
  bfx::Vec3 v38; // [sp+50h] [-B0h] BYREF
  float m_x; // [sp+60h] [-A0h] BYREF
  float v40; // [sp+64h] [-9Ch]
  float v41; // [sp+68h] [-98h]
  float v42; // [sp+6Ch] [-94h]
  float v43; // [sp+70h] [-90h]
  float v44; // [sp+74h] [-8Ch]
  bfx::Matrix v45; // [sp+80h] [-80h] BYREF

  this->m_vel = *vel;
  p_m_vel = &this->m_vel;
  bfx::Orienter::SetOrientation(this: &this->m_commonState->m_orienter, desiredRot: startMat);
  this->m_pos3D = this->m_commonState->m_surfer.m_pos;
  if ( __fsqrts((float)((float)(this->m_vel.m_z * this->m_vel.m_z)
                      + (float)((float)(this->m_vel.m_x * this->m_vel.m_x) + (float)(this->m_vel.m_y * this->m_vel.m_y)))) <= (float)(this->m_commonState->m_pTune->m_startStopAcc * (float)0.033333335) )
  {
    p_m_vel->m_x = 0.0;
    p_m_vel->m_y = 0.0;
    p_m_vel->m_z = 0.0;
  }
  m_commonState = this->m_commonState;
  if ( m_commonState->m_pProber != nullptr )
  {
    m_planLayer = m_commonState->m_pTune->m_planLayer;
    if ( m_planLayer >= 0x20 )
      v7 = nullptr;
    else
      v7 = *(bfx::NavLayer **)(4 * (m_planLayer + 2) + *((_DWORD *)m_commonState->m_pSpace->m_components.m_data + 1));
    p_m_pos = &m_commonState->m_surfer.m_pos;
    LocalUpAxis = bfx::Orienter::GetLocalUpAxis(
                    this: (bfx::Orienter *)&m_x,
                    result: (bfx::Vec3 *)&m_commonState->m_orienter);
    bfx::Prober::TeleportToArea(
      this: this->m_commonState->m_pProber,
      pNavLayer: v7,
      surferPos: p_m_pos,
      localUpAxis: (const bfx::Vec3 *)LocalUpAxis);
  }
  v10 = this->m_commonState;
  m_pProber = v10->m_pProber;
  if ( m_pProber != nullptr )
  {
    v12 = (bfx::Vec3 *)&m_x;
    m_y = m_pProber->m_pos3DOffset.m_y;
    m_z = m_pProber->m_pos3DOffset.m_z;
    m_x = m_pProber->m_pos3DOffset.m_x;
    v40 = m_y;
    v41 = m_z;
  }
  else
  {
    v12 = &bfx::ZERO_VEC;
  }
  v15 = (float)(v10->m_surfer.m_pos.m_y + v12->m_y);
  v16 = (float)(v10->m_surfer.m_pos.m_z + v12->m_z);
  this->m_pos3D.m_x = v12->m_x + v10->m_surfer.m_pos.m_x;
  this->m_pos3D.m_y = v15;
  this->m_pos3D.m_z = v16;
  m_pUPath = this->m_pUPath;
  if ( m_pUPath != nullptr )
  {
    bfx::UPath::~UPath(this: this->m_pUPath);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pUPath->m_pBuf);
  }
  this->m_pUPath = nullptr;
  this->m_recentShortcutCornerAreas.m_size = 0;
  bfx::MemoryManager::Free(
    this: bfx::g_pCurInstance->m_pMemoryManager,
    ptr: (char *)this->m_recentShortcutCornerAreas.m_data);
  v18 = LODWORD(v40);
  v19 = LODWORD(v40);
  v20 = v41;
  this->m_recentShortcutCornerAreas.m_data = nullptr;
  v21 = v42;
  this->m_recentShortcutCornerAreas.m_cap = 0;
  v22 = v43;
  this->m_onStopAction.m_restartGotoPos = false;
  v23 = v41;
  this->m_onStopAction.m_orientMode = v18;
  v24 = v42;
  this->m_onStopAction.m_changeOrientMode = false;
  this->m_onStopAction.m_vec.m_y = v21;
  this->m_onStopAction.m_vec.m_z = v22;
  this->m_onStopAction.m_vec.m_x = v20;
  this->m_onFinalRotationAction.m_restartGotoPos = false;
  this->m_onFinalRotationAction.m_changeOrientMode = false;
  v25 = v43;
  this->m_onFinalRotationAction.m_orientMode = v19;
  this->m_onFinalRotationAction.m_vec.m_x = v23;
  this->m_onFinalRotationAction.m_vec.m_y = v24;
  this->m_onFinalRotationAction.m_vec.m_z = v25;
  v26 = this->m_commonState;
  p_m_onFinalRotationAction = &this->m_onFinalRotationAction;
  v28 = v26->m_surfer.m_pos.m_z;
  v29 = v26->m_surfer.m_pos.m_y;
  m_x = v26->m_surfer.m_pos.m_x;
  v30 = m_x;
  v31 = m_x;
  v41 = v28;
  v42 = m_x;
  v43 = v29;
  v44 = v28;
  v40 = v29;
  this->m_goalData.m_goalSeg.m_v0.m_y = v29;
  this->m_goalData.m_goalSeg.m_v0.m_x = v31;
  this->m_goalData.m_goalSeg.m_v0.m_z = v28;
  this->m_goalData.m_goalSeg.m_v1.m_x = v30;
  this->m_goalData.m_goalSeg.m_v1.m_y = v29;
  this->m_goalData.m_goalSeg.m_v1.m_z = v28;
  if ( __fsqrts((float)((float)(p_m_vel->m_x * p_m_vel->m_x)
                      + (float)((float)(p_m_vel->m_y * p_m_vel->m_y) + (float)(p_m_vel->m_z * p_m_vel->m_z)))) == 0.0 )
  {
    if ( this->m_state == 4 )
    {
      p_m_onFinalRotationAction->m_restartGotoPos = false;
      this->m_onFinalRotationAction.m_changeOrientMode = false;
    }
    this->m_orbitDirection = 0.0;
    this->m_orbitSpeed = 0.0;
    v32 = -1.0;
    this->m_orbitMinDist = -1.0;
    this->m_orbitCenter.m_x = 0.0;
    this->m_orbitCenter.m_y = 0.0;
    this->m_orbitCenter.m_z = 0.0;
    this->m_state = DONE_MOVING;
  }
  else
  {
    if ( this->m_commonState->m_orientCmd.m_mode <= (unsigned int)ORIENT_STRICTLY_IN_TRAVEL_DIR )
    {
      if ( (unsigned __int8)bfx::WalkerImpl::PerformRoundedCornering(this) != 0 )
      {
        v34 = this->m_goalData.m_goalDir.m_x;
        v35 = this->m_goalData.m_goalDir.m_y;
        v36 = this->m_goalData.m_goalDir.m_z;
      }
      else
      {
        v33 = this->GetPos(this: &m_x, result: this);
        bfx::Orienter::CalcMat(this: &this->m_commonState->m_orienter, pos: v33, mat: &v45);
        v34 = v45.m_data[0];
        v35 = v45.m_data[1];
        v36 = v45.m_data[2];
      }
      v38.m_z = v36;
      v37 = this->m_commonState;
      v38.m_y = v35;
      v38.m_x = v34;
      bfx::Orienter::FaceInDir(this: &v37->m_orienter, dir: &v38);
    }
    if ( this->m_state == 4 )
    {
      p_m_onFinalRotationAction->m_restartGotoPos = false;
      this->m_onFinalRotationAction.m_changeOrientMode = false;
    }
    this->m_orbitDirection = 0.0;
    this->m_orbitSpeed = 0.0;
    v32 = -1.0;
    this->m_orbitMinDist = -1.0;
    this->m_orbitCenter.m_x = 0.0;
    this->m_orbitCenter.m_y = 0.0;
    this->m_orbitCenter.m_z = 0.0;
    this->m_state = 3;
  }
  this->m_orbitPrevMinDist = v32;
  this->m_orbitDisable = false;
  this->m_orbitGoalDirection = 0.0;
  this->m_orbitRadius = 0.0;
}


// ========================================================================
// ?TurnToEnd@WalkerImpl@bfx@@UAAXPBVVec3@2@@Z
// EA  : 0x832D09D0
// RVA : 0x012D09D0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::WalkerImpl::TurnToEnd(bfx::WalkerImpl *this, const bfx::Vec3 *pForwardVec)
{
  double m_y; // fp13
  double m_z; // fp12
  bfx::UPath *m_pUPath; // r11
  bfx::Vec3 *v7; // r4
  bfx::WalkerImpl *ObservedVel; // r30
  const bfx::Vec3 *v9; // r3
  long double v10; // fp4
  long double v11; // fp2
  float *DesiredFacingVec; // r3
  bfx::WalkerImpl::State m_state; // r11
  bfx::WalkerImpl::State v14; // r9
  bfx::Vec3 v15; // [sp+50h] [-70h] BYREF
  bfx::Matrix v16; // [sp+60h] [-60h] BYREF

  bfx::WalkerImpl::UpdateUnwrappedPathIfNeeded(this, bForce: false);
  if ( this->IsTurningInPlace(this, a2: nullptr) )
  {
    if ( pForwardVec != nullptr )
    {
      m_y = pForwardVec->m_y;
      m_z = pForwardVec->m_z;
      v15.m_x = pForwardVec->m_x;
      v15.m_y = m_y;
    }
    else
    {
      m_pUPath = this->m_pUPath;
      if ( m_pUPath != nullptr )
        v7 = (bfx::Vec3 *)&m_pUPath->m_u2g[m_pUPath->m_curIdx];
      else
        v7 = (bfx::Vec3 *)&bfx::IDENTITY;
      bfx::Matrix::operator*(this: &v16, result: v7, rhs: &this->m_targetPosU);
      ObservedVel = bfx::WalkerImpl::GetObservedVel(this: (bfx::WalkerImpl *)&v16.m_data[4], result: (bfx::Vec3 *)this);
      v9 = (const bfx::Vec3 *)((int (__fastcall *)(float *))this->GetPos)(a1: &v16.m_data[8]);
      DesiredFacingVec = (float *)bfx::Orienter::GetDesiredFacingVec(
                                    this: (bfx::Orienter *)&v16.m_data[12],
                                    result: (bfx::Vec3 *)&this->m_commonState->m_orienter,
                                    pos: v9,
                                    vel: (const bfx::Vec3 *)ObservedVel,
                                    nextCornerG: (const bfx::Vec3 *)&v16,
                                    a6: v11,
                                    a7: v10);
      v15.m_x = *DesiredFacingVec;
      v15.m_y = DesiredFacingVec[1];
      m_z = DesiredFacingVec[2];
    }
    v15.m_z = m_z;
    bfx::Orienter::SetOrientation(this: &this->m_commonState->m_orienter, forwardVecIn: &v15);
    m_state = this->m_state;
    if ( m_state == 1 )
    {
      bfx::WalkerImpl::SwitchState(this, newState: PATH_MOVE);
    }
    else if ( m_state == 4 )
    {
      bfx::EnactDelayedOrientationMode(
        action: &this->m_onFinalRotationAction,
        orienter: &this->m_commonState->m_orienter);
      v14 = this->m_state;
      this->m_reachedGoal = true;
      if ( v14 == 4 )
      {
        this->m_onFinalRotationAction.m_restartGotoPos = false;
        this->m_onFinalRotationAction.m_changeOrientMode = false;
      }
      this->m_orbitDirection = 0.0;
      this->m_orbitSpeed = 0.0;
      this->m_orbitMinDist = -1.0;
      this->m_orbitCenter.m_x = 0.0;
      this->m_orbitCenter.m_y = 0.0;
      this->m_orbitCenter.m_z = 0.0;
      this->m_orbitDisable = false;
      this->m_orbitRadius = 0.0;
      this->m_state = DONE_MOVING;
      this->m_orbitGoalDirection = 0.0;
      this->m_orbitPrevMinDist = -1.0;
    }
  }
}


// ========================================================================
// ?NewDirRequiresTurnInPlace@WalkerImpl@bfx@@AAA_NABVVec3@2@@Z
// EA  : 0x832D0B80
// RVA : 0x012D0B80
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

int __fastcall bfx::WalkerImpl::NewDirRequiresTurnInPlace(bfx::WalkerImpl *this, const bfx::Vec3 *dir, long double a3)
{
  bfx::MotionState *m_commonState; // r11
  bfx::HandleProxy *m_pProxy; // r9
  const bfx::MoverTune *m_pTune; // r31
  double v7; // fp12
  double m_followSpeedX; // fp13
  float *Forward; // r3
  long double v13; // fp2
  int result; // r3
  char v15; // [sp+50h] [-30h] BYREF

  if ( this->m_state != PATH_MOVE )
    return 0;
  m_commonState = this->m_commonState;
  m_pProxy = m_commonState->m_followData.m_targetMover.m_pProxy;
  m_pTune = m_commonState->m_pTune;
  v7 = __fsqrts((float)((float)(this->m_vel.m_z * this->m_vel.m_z)
                      + (float)((float)(this->m_vel.m_x * this->m_vel.m_x) + (float)(this->m_vel.m_y * this->m_vel.m_y))));
  if ( m_pProxy != nullptr && m_pProxy->m_pTarget != nullptr )
    m_followSpeedX = m_commonState->m_followData.m_followSpeedX;
  else
    m_followSpeedX = 1.0;
  if ( v7 <= (float)((float)((float)((float)(m_commonState->m_pTune->m_speed
                                           * m_commonState->m_cautionData.m_internalSpeedX)
                                   * m_commonState->m_speedX)
                           * (float)m_followSpeedX)
                   * (float)0.1) )
    return 0;
  Forward = (float *)bfx::Orienter::GetForward(
                       this: (bfx::Orienter *)&v15,
                       result: (bfx::Vec3 *)&this->m_commonState->m_orienter,
                       a3);
  _FP4 = (float)((float)-1.0
               - (float)((float)(*Forward * dir->m_x)
                       + (float)((float)(Forward[2] * dir->m_z) + (float)(Forward[1] * dir->m_y))));
  _FP3 = (float)((float)1.0
               - (float)((float)(*Forward * dir->m_x)
                       + (float)((float)(Forward[2] * dir->m_z) + (float)(Forward[1] * dir->m_y))));
  __asm { fsel      f2, f4, f13, f5# x }
  __asm { fsel      f1, f3, f1, f31# x }
  v13 = acos(x: _FP2);
  result = 1;
  if ( (float)*(double *)&v13 <= (double)(float)(m_pTune->m_turnInPlace.m_whenMovingAngle * (float)0.017453292) )
    return 0;
  return result;
}


// ========================================================================
// ?OrientInDirectionOfTravel@WalkerImpl@bfx@@UAAXXZ
// EA  : 0x832D0CC8
// RVA : 0x012D0CC8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::WalkerImpl::OrientInDirectionOfTravel(bfx::WalkerImpl *this)
{
  bfx::UPath *m_pUPath; // r11
  bfx::Vec3 *v3; // r30
  bfx::Vec3 *v4; // r29
  bfx::Matrix *v5; // r3
  double v6; // fp10
  double v7; // fp8
  double v8; // fp6
  bfx::MotionState *m_commonState; // r10
  const bfx::Vec3 *v12; // r3
  double m_x; // fp0
  double m_y; // fp13
  double m_z; // fp12
  bfx::MotionState *v16; // r11
  bfx::Vec3 v17; // [sp+50h] [-B0h] BYREF
  bfx::Vec3 v18; // [sp+60h] [-A0h] BYREF
  _BYTE v19[16]; // [sp+70h] [-90h] BYREF
  bfx::Matrix v20; // [sp+80h] [-80h] BYREF

  if ( this->m_state == 4 )
  {
    *(_WORD *)&this->m_onFinalRotationAction.m_restartGotoPos = 1;
    this->m_onFinalRotationAction.m_orientMode = ORIENT_IN_TRAVEL_DIR;
  }
  else
  {
    m_pUPath = this->m_pUPath;
    if ( m_pUPath != nullptr )
      v3 = (bfx::Vec3 *)&m_pUPath->m_u2g[m_pUPath->m_curIdx];
    else
      v3 = (bfx::Vec3 *)&bfx::IDENTITY;
    v4 = this->GetPos(this: v19, result: this);
    v5 = bfx::Matrix::operator*(this: &v20, result: v3, rhs: &this->m_targetPosU);
    v6 = (float)(v5->m_data[1] - v4->m_y);
    v7 = (float)(v5->m_data[0] - v4->m_x);
    v8 = (float)(v5->m_data[2] - v4->m_z);
    *((double *)&_FP2 + 1) = __fsqrts((float)((float)((float)v8 * (float)v8)
                                            + (float)((float)((float)(v5->m_data[0] - v4->m_x)
                                                            * (float)(v5->m_data[0] - v4->m_x))
                                                    + (float)((float)v6 * (float)v6))));
    *(double *)&_FP2 = (float)((float)*((double *)&_FP2 + 1) - (float)1.0842022e-19);
    __asm { fsel      f13, f1, f0, f31 }
    v18.m_y = (float)_FP13 * (float)(v5->m_data[1] - v4->m_y);
    v18.m_x = (float)_FP13 * (float)v7;
    v18.m_z = (float)_FP13 * (float)v8;
    if ( (unsigned __int8)bfx::WalkerImpl::NewDirRequiresTurnInPlace(this, dir: &v18, a3: _FP2) != 0 )
    {
      m_commonState = this->m_commonState;
      this->m_onStopAction.m_restartGotoPos = true;
      this->m_onStopAction.m_changeOrientMode = true;
      this->m_onStopAction.m_orientMode = ORIENT_IN_TRAVEL_DIR;
      if ( m_commonState->m_orientCmd.m_mode <= (unsigned int)ORIENT_STRICTLY_IN_TRAVEL_DIR )
      {
        if ( (unsigned __int8)bfx::WalkerImpl::PerformRoundedCornering(this) != 0 )
        {
          m_x = this->m_goalData.m_goalDir.m_x;
          m_y = this->m_goalData.m_goalDir.m_y;
          m_z = this->m_goalData.m_goalDir.m_z;
        }
        else
        {
          v12 = this->GetPos(this: &v20, result: this);
          bfx::Orienter::CalcMat(this: &this->m_commonState->m_orienter, pos: v12, mat: (bfx::Matrix *)&v20.m_data[4]);
          m_x = v20.m_data[4];
          m_y = v20.m_data[5];
          m_z = v20.m_data[6];
        }
        v17.m_z = m_z;
        v16 = this->m_commonState;
        v17.m_y = m_y;
        v17.m_x = m_x;
        bfx::Orienter::FaceInDir(this: &v16->m_orienter, dir: &v17);
      }
      if ( this->m_state == 4 )
      {
        this->m_onFinalRotationAction.m_restartGotoPos = false;
        this->m_onFinalRotationAction.m_changeOrientMode = false;
      }
      this->m_orbitDirection = 0.0;
      this->m_orbitSpeed = 0.0;
      this->m_orbitMinDist = -1.0;
      this->m_orbitCenter.m_x = 0.0;
      this->m_orbitCenter.m_y = 0.0;
      this->m_orbitCenter.m_z = 0.0;
      this->m_orbitDisable = false;
      this->m_orbitRadius = 0.0;
      this->m_state = 3;
      this->m_orbitGoalDirection = 0.0;
      this->m_orbitPrevMinDist = -1.0;
    }
    else
    {
      idThrowableFilter::InternalPostFilterItems(this: &this->m_commonState->m_orienter);
    }
  }
}


// ========================================================================
// ?OrientStrictlyInDirectionOfTravel@WalkerImpl@bfx@@UAAXXZ
// EA  : 0x832D0F00
// RVA : 0x012D0F00
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::WalkerImpl::OrientStrictlyInDirectionOfTravel(bfx::WalkerImpl *this)
{
  bfx::UPath *m_pUPath; // r11
  bfx::Vec3 *v3; // r30
  bfx::Vec3 *v4; // r29
  bfx::Matrix *v5; // r3
  double v6; // fp10
  double v7; // fp8
  double v8; // fp6
  bfx::MotionState *m_commonState; // r10
  const bfx::Vec3 *v12; // r3
  double m_x; // fp0
  double m_y; // fp13
  double m_z; // fp12
  bfx::MotionState *v16; // r11
  bfx::Vec3 v17; // [sp+50h] [-B0h] BYREF
  bfx::Vec3 v18; // [sp+60h] [-A0h] BYREF
  _BYTE v19[16]; // [sp+70h] [-90h] BYREF
  bfx::Matrix v20; // [sp+80h] [-80h] BYREF

  if ( this->m_state == 4 )
  {
    this->m_onFinalRotationAction.m_changeOrientMode = true;
    this->m_onFinalRotationAction.m_restartGotoPos = false;
    this->m_onFinalRotationAction.m_orientMode = ORIENT_STRICTLY_IN_TRAVEL_DIR;
  }
  else
  {
    m_pUPath = this->m_pUPath;
    if ( m_pUPath != nullptr )
      v3 = (bfx::Vec3 *)&m_pUPath->m_u2g[m_pUPath->m_curIdx];
    else
      v3 = (bfx::Vec3 *)&bfx::IDENTITY;
    v4 = this->GetPos(this: v19, result: this);
    v5 = bfx::Matrix::operator*(this: &v20, result: v3, rhs: &this->m_targetPosU);
    v6 = (float)(v5->m_data[1] - v4->m_y);
    v7 = (float)(v5->m_data[0] - v4->m_x);
    v8 = (float)(v5->m_data[2] - v4->m_z);
    *((double *)&_FP2 + 1) = __fsqrts((float)((float)((float)v8 * (float)v8)
                                            + (float)((float)((float)(v5->m_data[0] - v4->m_x)
                                                            * (float)(v5->m_data[0] - v4->m_x))
                                                    + (float)((float)v6 * (float)v6))));
    *(double *)&_FP2 = (float)((float)*((double *)&_FP2 + 1) - (float)1.0842022e-19);
    __asm { fsel      f13, f1, f0, f31 }
    v18.m_y = (float)_FP13 * (float)(v5->m_data[1] - v4->m_y);
    v18.m_x = (float)_FP13 * (float)v7;
    v18.m_z = (float)_FP13 * (float)v8;
    if ( (unsigned __int8)bfx::WalkerImpl::NewDirRequiresTurnInPlace(this, dir: &v18, a3: _FP2) != 0 )
    {
      m_commonState = this->m_commonState;
      this->m_onStopAction.m_restartGotoPos = true;
      this->m_onStopAction.m_changeOrientMode = true;
      this->m_onStopAction.m_orientMode = ORIENT_STRICTLY_IN_TRAVEL_DIR;
      if ( m_commonState->m_orientCmd.m_mode <= (unsigned int)ORIENT_STRICTLY_IN_TRAVEL_DIR )
      {
        if ( (unsigned __int8)bfx::WalkerImpl::PerformRoundedCornering(this) != 0 )
        {
          m_x = this->m_goalData.m_goalDir.m_x;
          m_y = this->m_goalData.m_goalDir.m_y;
          m_z = this->m_goalData.m_goalDir.m_z;
        }
        else
        {
          v12 = this->GetPos(this: &v20, result: this);
          bfx::Orienter::CalcMat(this: &this->m_commonState->m_orienter, pos: v12, mat: (bfx::Matrix *)&v20.m_data[4]);
          m_x = v20.m_data[4];
          m_y = v20.m_data[5];
          m_z = v20.m_data[6];
        }
        v17.m_z = m_z;
        v16 = this->m_commonState;
        v17.m_y = m_y;
        v17.m_x = m_x;
        bfx::Orienter::FaceInDir(this: &v16->m_orienter, dir: &v17);
      }
      if ( this->m_state == 4 )
      {
        this->m_onFinalRotationAction.m_restartGotoPos = false;
        this->m_onFinalRotationAction.m_changeOrientMode = false;
      }
      this->m_orbitDirection = 0.0;
      this->m_orbitSpeed = 0.0;
      this->m_orbitMinDist = -1.0;
      this->m_orbitCenter.m_x = 0.0;
      this->m_orbitCenter.m_y = 0.0;
      this->m_orbitCenter.m_z = 0.0;
      this->m_orbitDisable = false;
      this->m_orbitRadius = 0.0;
      this->m_state = 3;
      this->m_orbitGoalDirection = 0.0;
      this->m_orbitPrevMinDist = -1.0;
    }
    else
    {
      bfx::Orienter::FaceStrictlyInTravelDir(this: &this->m_commonState->m_orienter);
    }
  }
}


// ========================================================================
// ?OrientTowardsTargetPos@WalkerImpl@bfx@@UAAXABVVec3@2@@Z
// EA  : 0x832D1138
// RVA : 0x012D1138
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::WalkerImpl::OrientTowardsTargetPos(bfx::WalkerImpl *this, const bfx::Vec3 *targetPos)
{
  bfx::Vec3 *v4; // r3
  double v5; // fp8
  double v6; // fp6
  const bfx::Vec3 *v9; // r3
  double m_x; // fp0
  double m_y; // fp13
  double m_z; // fp12
  bfx::MotionState *m_commonState; // r11
  bfx::Vec3 v14; // [sp+50h] [-90h] BYREF
  bfx::Vec3 v15; // [sp+60h] [-80h] BYREF
  _BYTE v16[16]; // [sp+70h] [-70h] BYREF
  bfx::Matrix v17; // [sp+80h] [-60h] BYREF

  if ( this->m_state == 4 )
  {
    *(_WORD *)&this->m_onFinalRotationAction.m_restartGotoPos = 1;
    this->m_onFinalRotationAction.m_orientMode = ORIENT_TARGET;
    this->m_onFinalRotationAction.m_vec = *targetPos;
  }
  else
  {
    v4 = this->GetPos(this: v16, result: this);
    v5 = (float)(targetPos->m_y - v4->m_y);
    v6 = (float)(targetPos->m_z - v4->m_z);
    *((double *)&_FP2 + 1) = __fsqrts((float)((float)((float)v6 * (float)v6)
                                            + (float)((float)((float)v5 * (float)v5)
                                                    + (float)((float)(targetPos->m_x - v4->m_x)
                                                            * (float)(targetPos->m_x - v4->m_x)))));
    *(double *)&_FP2 = (float)((float)*((double *)&_FP2 + 1) - (float)1.0842022e-19);
    __asm { fsel      f13, f1, f0, f31 }
    v15.m_x = (float)_FP13 * (float)(targetPos->m_x - v4->m_x);
    v15.m_y = (float)v5 * (float)_FP13;
    v15.m_z = (float)_FP13 * (float)v6;
    if ( (unsigned __int8)bfx::WalkerImpl::NewDirRequiresTurnInPlace(this, dir: &v15, a3: _FP2) != 0 )
    {
      this->m_onStopAction.m_changeOrientMode = true;
      this->m_onStopAction.m_restartGotoPos = true;
      this->m_onStopAction.m_orientMode = ORIENT_TARGET;
      this->m_onStopAction.m_vec.m_x = targetPos->m_x;
      this->m_onStopAction.m_vec.m_y = targetPos->m_y;
      this->m_onStopAction.m_vec.m_z = targetPos->m_z;
      if ( this->m_state != 3 )
      {
        if ( this->m_commonState->m_orientCmd.m_mode <= (unsigned int)ORIENT_STRICTLY_IN_TRAVEL_DIR )
        {
          if ( (unsigned __int8)bfx::WalkerImpl::PerformRoundedCornering(this) != 0 )
          {
            m_x = this->m_goalData.m_goalDir.m_x;
            m_y = this->m_goalData.m_goalDir.m_y;
            m_z = this->m_goalData.m_goalDir.m_z;
          }
          else
          {
            v9 = this->GetPos(this: v16, result: this);
            bfx::Orienter::CalcMat(this: &this->m_commonState->m_orienter, pos: v9, mat: &v17);
            m_x = v17.m_data[0];
            m_y = v17.m_data[1];
            m_z = v17.m_data[2];
          }
          v14.m_z = m_z;
          m_commonState = this->m_commonState;
          v14.m_y = m_y;
          v14.m_x = m_x;
          bfx::Orienter::FaceInDir(this: &m_commonState->m_orienter, dir: &v14);
        }
        if ( this->m_state == 4 )
        {
          this->m_onFinalRotationAction.m_restartGotoPos = false;
          this->m_onFinalRotationAction.m_changeOrientMode = false;
        }
        this->m_orbitDirection = 0.0;
        this->m_orbitSpeed = 0.0;
        this->m_orbitMinDist = -1.0;
        this->m_orbitCenter.m_x = 0.0;
        this->m_orbitCenter.m_y = 0.0;
        this->m_orbitCenter.m_z = 0.0;
        this->m_orbitDisable = false;
        this->m_orbitRadius = 0.0;
        this->m_state = 3;
        this->m_orbitGoalDirection = 0.0;
        this->m_orbitPrevMinDist = -1.0;
      }
    }
    else
    {
      bfx::Orienter::FaceTarget(this: &this->m_commonState->m_orienter, targetPos);
    }
  }
}


// ========================================================================
// ?OrientInDirection@WalkerImpl@bfx@@UAAXABVVec3@2@@Z
// EA  : 0x832D1388
// RVA : 0x012D1388
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::WalkerImpl::OrientInDirection(bfx::WalkerImpl *this, const bfx::Vec3 *dir, long double a3)
{
  const bfx::Vec3 *v5; // r3
  double m_x; // fp0
  double m_y; // fp13
  double m_z; // fp12
  bfx::MotionState *m_commonState; // r11
  bfx::Vec3 v10; // [sp+50h] [-80h] BYREF
  _BYTE v11[16]; // [sp+60h] [-70h] BYREF
  bfx::Matrix v12; // [sp+70h] [-60h] BYREF

  if ( this->m_state == 4 )
  {
    *(_WORD *)&this->m_onFinalRotationAction.m_restartGotoPos = 1;
    this->m_onFinalRotationAction.m_orientMode = ORIENT_IN_DIR;
    this->m_onFinalRotationAction.m_vec = *dir;
  }
  else if ( (unsigned __int8)bfx::WalkerImpl::NewDirRequiresTurnInPlace(this, dir, a3) != 0 )
  {
    this->m_onStopAction.m_restartGotoPos = true;
    this->m_onStopAction.m_orientMode = ORIENT_IN_DIR;
    this->m_onStopAction.m_changeOrientMode = true;
    this->m_onStopAction.m_vec.m_x = dir->m_x;
    this->m_onStopAction.m_vec.m_y = dir->m_y;
    this->m_onStopAction.m_vec.m_z = dir->m_z;
    if ( this->m_state != 3 )
    {
      if ( this->m_commonState->m_orientCmd.m_mode <= (unsigned int)ORIENT_STRICTLY_IN_TRAVEL_DIR )
      {
        if ( (unsigned __int8)bfx::WalkerImpl::PerformRoundedCornering(this) != 0 )
        {
          m_x = this->m_goalData.m_goalDir.m_x;
          m_y = this->m_goalData.m_goalDir.m_y;
          m_z = this->m_goalData.m_goalDir.m_z;
        }
        else
        {
          v5 = this->GetPos(this: v11, result: this);
          bfx::Orienter::CalcMat(this: &this->m_commonState->m_orienter, pos: v5, mat: &v12);
          m_x = v12.m_data[0];
          m_y = v12.m_data[1];
          m_z = v12.m_data[2];
        }
        v10.m_z = m_z;
        m_commonState = this->m_commonState;
        v10.m_y = m_y;
        v10.m_x = m_x;
        bfx::Orienter::FaceInDir(this: &m_commonState->m_orienter, dir: &v10);
      }
      if ( this->m_state == 4 )
      {
        this->m_onFinalRotationAction.m_restartGotoPos = false;
        this->m_onFinalRotationAction.m_changeOrientMode = false;
      }
      this->m_orbitDirection = 0.0;
      this->m_orbitSpeed = 0.0;
      this->m_orbitMinDist = -1.0;
      this->m_orbitCenter.m_x = 0.0;
      this->m_orbitCenter.m_y = 0.0;
      this->m_orbitCenter.m_z = 0.0;
      this->m_orbitDisable = false;
      this->m_orbitRadius = 0.0;
      this->m_state = 3;
      this->m_orbitGoalDirection = 0.0;
      this->m_orbitPrevMinDist = -1.0;
    }
  }
  else
  {
    bfx::Orienter::FaceInDir(this: &this->m_commonState->m_orienter, dir);
  }
}


// ========================================================================
// ?IsTurningInPlace@WalkerImpl@bfx@@UBA_NPAVTurningInPlaceData@2@@Z
// EA  : 0x832D1538
// RVA : 0x012D1538
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

int __fastcall bfx::WalkerImpl::IsTurningInPlace(bfx::WalkerImpl *this, bfx::TurningInPlaceData *pDataOut)
{
  bfx::UPath *m_pUPath; // r11
  bfx::MotionState *m_commonState; // r10
  bfx::WalkerImpl::State m_state; // r9
  const bfx::MoverTune *m_pTune; // r29
  bfx::WalkerImpl *ObservedVel; // r3
  const bfx::Vec3 *v9; // r8
  const bfx::Vec3 *v10; // r6
  long double v11; // fp4
  long double v12; // fp2
  double v13; // fp1
  double v14; // fp11
  double v15; // fp10
  double v16; // fp9
  bfx::MotionState *v17; // r6
  double v18; // fp11
  double v19; // fp10
  double v20; // fp7
  bfx::Space *v23; // r3
  float m_y; // r9
  float m_z; // r8
  double Scale; // fp1
  double v28; // fp4
  double v29; // fp2
  bfx::WalkerImpl *v30; // r3
  const bfx::Vec3 *v31; // r6
  long double v32; // fp4
  long double v33; // fp2
  double v34; // fp1
  double v35; // fp10
  double v36; // fp7
  double m_x; // fp6
  double v38; // fp5
  double v39; // fp3
  bfx::Vector3 **v41; // r6
  bfx::Space *v43; // r3
  bfx::Vec3 v44; // [sp+50h] [-80h] BYREF
  float v45; // [sp+60h] [-70h]
  float v46; // [sp+64h] [-6Ch]
  float v47; // [sp+68h] [-68h]
  bfx::Matrix v48; // [sp+70h] [-60h] BYREF

  m_pUPath = this->m_pUPath;
  if ( m_pUPath == nullptr )
    return 0;
  m_commonState = this->m_commonState;
  m_state = this->m_state;
  m_pTune = m_commonState->m_pTune;
  if ( m_state == 1 )
  {
    bfx::Matrix::operator*(
      this: &v48,
      result: (bfx::Vec3 *)&m_pUPath->m_u2g[m_pUPath->m_curIdx],
      rhs: &this->m_targetPosU);
    ObservedVel = bfx::WalkerImpl::GetObservedVel(this: (bfx::WalkerImpl *)&v48.m_data[12], result: (bfx::Vec3 *)this);
    v13 = bfx::Orienter::CalcHeadingError(
            this: &this->m_commonState->m_orienter,
            pos: v9,
            vel: (const bfx::Vec3 *)ObservedVel,
            nextCornerG: v10,
            a5: v12,
            a6: v11);
    if ( pDataOut != nullptr )
    {
      v14 = v48.m_data[1];
      v15 = v48.m_data[2];
      v16 = v48.m_data[0];
      pDataOut->m_degreesToTarget = (float)v13 * (float)-57.295776;
      pDataOut->m_turnTime = __fabs((float)((float)v13 / (float)(m_pTune->m_turnInPlace.m_speed * (float)0.017453292)));
      v17 = this->m_commonState;
      v18 = (float)((float)v14 - v17->m_surfer.m_pos.m_y);
      v19 = (float)((float)v15 - v17->m_surfer.m_pos.m_z);
      v20 = (float)((float)v16 - v17->m_surfer.m_pos.m_x);
      _FP3 = (float)((float)__fsqrts((float)((float)((float)v20 * (float)v20)
                                           + (float)((float)((float)v19 * (float)v19) + (float)((float)v18 * (float)v18))))
                   - (float)1.0842022e-19);
      __asm { fsel      f1, f3, f2, f12 }
      v48.m_data[4] = (float)((float)v16 - v17->m_surfer.m_pos.m_x) * (float)_FP1;
      v48.m_data[5] = (float)v18 * (float)_FP1;
      v48.m_data[6] = (float)v19 * (float)_FP1;
      v23 = bfx::Space::RotateToWorld(
              this: (bfx::Space *)&v48.m_data[12],
              result: (bfx::Vector3 *)v17->m_pSpace,
              vecIn: (const bfx::Vec3 *)&v48.m_data[4]);
      *(bfx::HandleTargetBase *)&pDataOut->m_desiredDirectionVec.m_x = v23->bfx::HandleTargetBase;
      LODWORD(pDataOut->m_desiredDirectionVec.m_z) = v23->m_spaceID;
    }
    return 1;
  }
  if ( m_state != 4 )
    return 0;
  m_y = m_commonState->m_surfer.m_pos.m_y;
  m_z = m_commonState->m_surfer.m_pos.m_z;
  v44.m_x = m_commonState->m_surfer.m_pos.m_x;
  v44.m_y = m_y;
  v44.m_z = m_z;
  Scale = bfx::GetScale();
  v28 = (float)(this->m_goalData.m_goalDir.m_z * (float)((float)Scale * (float)10.0));
  v29 = (float)(v44.m_y + (float)(this->m_goalData.m_goalDir.m_y * (float)((float)Scale * (float)10.0)));
  v45 = (float)((float)((float)Scale * (float)10.0) * this->m_goalData.m_goalDir.m_x) + v44.m_x;
  v46 = v29;
  v47 = v44.m_z + (float)v28;
  v30 = bfx::WalkerImpl::GetObservedVel(this: (bfx::WalkerImpl *)&v48.m_data[12], result: (bfx::Vec3 *)this);
  v34 = bfx::Orienter::CalcHeadingError(
          this: &this->m_commonState->m_orienter,
          pos: &v44,
          vel: (const bfx::Vec3 *)v30,
          nextCornerG: v31,
          a5: v33,
          a6: v32);
  if ( pDataOut == nullptr )
    return 1;
  v35 = (float)(v46 - v44.m_y);
  v36 = (float)(v47 - v44.m_z);
  m_x = v44.m_x;
  v38 = v45;
  pDataOut->m_degreesToTarget = (float)v34 * (float)-57.295776;
  v39 = (float)((float)v34 / (float)(m_pTune->m_turnInPlace.m_speed * (float)0.017453292));
  _FP1 = (float)((float)__fsqrts((float)((float)((float)((float)v38 - (float)m_x) * (float)((float)v38 - (float)m_x))
                                       + (float)((float)((float)v36 * (float)v36) + (float)((float)v35 * (float)v35))))
               - (float)1.0842022e-19);
  pDataOut->m_turnTime = __fabs(v39);
  v41 = (bfx::Vector3 **)this->m_commonState;
  __asm { fsel      f12, f1, f0, f11 }
  v48.m_data[8] = (float)((float)v38 - (float)m_x) * (float)_FP12;
  v48.m_data[9] = (float)v35 * (float)_FP12;
  v48.m_data[10] = (float)v36 * (float)_FP12;
  v43 = bfx::Space::RotateToWorld(
          this: (bfx::Space *)&v48.m_data[12],
          result: *v41,
          vecIn: (const bfx::Vec3 *)&v48.m_data[8]);
  *(bfx::HandleTargetBase *)&pDataOut->m_desiredDirectionVec.m_x = v43->bfx::HandleTargetBase;
  LODWORD(pDataOut->m_desiredDirectionVec.m_z) = v43->m_spaceID;
  return 1;
}


// ========================================================================
// ?CalcCrowdRepulseAcc@WalkerImpl@bfx@@AAA?AVVec3@2@ABVFastArrayOfRepRecs@2@_NAAV32@@Z
// EA  : 0x832D1808
// RVA : 0x012D1808
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

bfx::WalkerImpl *__fastcall bfx::WalkerImpl::CalcCrowdRepulseAcc(
        bfx::WalkerImpl *this,
        bfx::Vec3 *result,
        const bfx::FastArrayOfRepRecs *repRecs,
        bool computeSlideAcc,
        bfx::Vec3 *slideAcc)
{
  float m_y; // r11
  int v9; // r26
  _DWORD *v10; // r11
  int v14; // r11
  float *v15; // r28
  bfx::InstanceComponent_vtbl *v16; // r10
  char *v17; // r24
  int v18; // r25
  bfx::RepRec *m_pRecs; // r29
  float *p_m_z; // r31
  float v21; // r10
  float m_x; // r9
  double v23; // fp12
  float m_z; // r8
  double v25; // fp9
  float *v26; // r11
  double v27; // fp14
  double v28; // fp16
  double v29; // fp15
  double v30; // fp0
  double v31; // fp30
  double v32; // fp31
  double v33; // fp29
  double v34; // fp30
  double v35; // fp1
  bool v36; // mr_fpscr49
  double v37; // fp31
  double v38; // fp28
  double v39; // fp30
  double v40; // fp0
  double v41; // fp13
  double v42; // fp24
  double v43; // fp27
  double v44; // fp23
  double v45; // fp26
  double v46; // fp22
  double v47; // fp25
  double v48; // fp0
  double v49; // fp13
  double v50; // fp29
  int v51; // r11
  double v52; // fp11
  double v53; // fp6
  double v54; // fp5
  double v55; // fp20
  double v56; // fp19
  double v57; // fp18
  double v58; // fp11
  double v59; // fp0
  double v60; // fp13
  double v61; // fp12
  double v62; // fp6
  double v65; // fp0
  double v66; // fp12
  double v67; // fp11
  double v68; // fp9
  double v69; // fp7
  float v71; // [sp+50h] [-160h]
  float v72; // [sp+54h] [-15Ch]
  float v73; // [sp+58h] [-158h]
  float v74; // [sp+60h] [-150h]
  float v75; // [sp+68h] [-148h]
  bfx::Matrix v76[3]; // [sp+70h] [-140h] BYREF

  m_y = result->m_y;
  v9 = *(_DWORD *)(LODWORD(m_y) + 4);
  v10 = *(_DWORD **)(LODWORD(m_y) + 364);
  *(float *)&this->__vftable = 0.0;
  *(float *)&this->m_commonState = 0.0;
  v73 = 0.0;
  this->m_pos3D.m_x = 0.0;
  v71 = *(float *)(v9 + 20);
  if ( v10 != nullptr && *v10 != 0 )
  {
    v14 = v10 != nullptr ? *v10 : 0;
    if ( v14 != 0 )
      v71 = *(float *)(LODWORD(result->m_y) + 348) * *(float *)(v9 + 20);
  }
  v15 = (float *)(v9 + 216);
  v16 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][11].__vftable;
  if ( v16 != nullptr )
    v17 = (char *)v16 + 192 * *(_DWORD *)(v9 + 32);
  else
    v17 = nullptr;
  bfx::WalkerImpl::GetObservedVel(this: (bfx::WalkerImpl *)&v76[0].m_data[12], result);
  bfx::Matrix::Rot(
    this: v76,
    result: (bfx::Vec3 *)((*(_DWORD *)(LODWORD(result[6].m_y) + 4968) << 6) + LODWORD(result[6].m_y) + 4008),
    rhs: (const bfx::Vec3 *)&v76[0].m_data[12]);
  v18 = 0;
  m_pRecs = repRecs->m_pRecs;
  v74 = __fsqrts((float)((float)(v76[0].m_data[0] * v76[0].m_data[0])
                       + (float)((float)(v76[0].m_data[2] * v76[0].m_data[2])
                               + (float)(v76[0].m_data[1] * v76[0].m_data[1]))));
  if ( repRecs->m_size > 0 )
  {
    p_m_z = &m_pRecs->m_vel.m_z;
    v75 = -1.0;
    v72 = 0.69999999;
    do
    {
      bfx::WalkerImpl::GetUPos(this: (bfx::WalkerImpl *)&v76[0].m_data[8], result);
      v21 = result->m_y;
      m_x = m_pRecs->m_pos.m_x;
      v23 = (float)(p_m_z[3] + p_m_z[1]);
      m_z = m_pRecs->m_pos.m_z;
      v25 = p_m_z[2];
      v76[0].m_data[5] = m_pRecs->m_pos.m_y;
      v76[0].m_data[4] = m_x;
      v76[0].m_data[6] = m_z;
      v26 = *(float **)(LODWORD(v21) + 4);
      v27 = v76[0].m_data[8];
      v28 = (float)(v76[0].m_data[8] - m_x);
      v29 = (float)(v76[0].m_data[9] - v76[0].m_data[5]);
      v30 = (float)((float)((float)(v76[0].m_data[9] - v76[0].m_data[5]) * (float)(v76[0].m_data[9] - v76[0].m_data[5]))
                  + (float)((float)(v76[0].m_data[8] - m_x) * (float)(v76[0].m_data[8] - m_x)));
      v31 = (float)((float)((float)((float)((float)v23 + v26[4]) + v26[3]) + v26[2]) + (float)v25);
      if ( v30 > 0.0 && v30 < (float)((float)v31 * (float)v31) )
      {
        v32 = __fsqrts(v30);
        if ( v17 != nullptr )
          v15 = (float *)&v17[12 * *((_DWORD *)p_m_z + 6)];
        v33 = bfx::CalcRampAcc(
                dist: (float)((float)((float)((float)((float)((float)v23 + v26[4]) + v26[3]) + v26[2]) + (float)v25)
                      - (float)v32),
                startDist: 0.0,
                endDist: *(float *)(v9 + 12),
                maxAcc: v15[1]);
        v34 = (float)((float)v31 - (float)(*(float *)(v9 + 12) + p_m_z[2]));
        v35 = bfx::CalcRampAcc(
                dist: (float)((float)v34 - (float)v32),
                startDist: 0.0,
                endDist: *(float *)(v9 + 16),
                maxAcc: v15[2]);
        v36 = v32 > v34;
        v38 = (float)((float)((float)1.0 / (float)v32) * (float)v29);
        v39 = (float)((float)((float)1.0 / (float)v32) * (float)0.0);
        v37 = (float)((float)((float)1.0 / (float)v32) * (float)v28);
        if ( v36 )
        {
          v40 = v15[1];
          v41 = *(float *)(v9 + 12);
        }
        else
        {
          v40 = v15[2];
          v41 = *(float *)(v9 + 16);
        }
        v42 = *(p_m_z - 1);
        v43 = v76[0].m_data[1];
        v44 = *p_m_z;
        v45 = v76[0].m_data[2];
        v46 = *(p_m_z - 2);
        v47 = v76[0].m_data[0];
        v49 = (float)((float)((float)((float)((float)((float)__fsqrts((float)((float)v40 / (float)v41)) * v72)
                                            * (float)((float)((float)(*(p_m_z - 2) - v76[0].m_data[0]) * (float)v37)
                                                    + (float)((float)((float)(*p_m_z - v76[0].m_data[2]) * (float)v39)
                                                            + (float)((float)(*(p_m_z - 1) - v76[0].m_data[1])
                                                                    * (float)v38))))
                                    + *v15)
                            + (float)v35)
                    + (float)v33);
        v48 = 1.0;
        if ( v17 == nullptr )
          v48 = (float)(*(float *)(*((_DWORD *)p_m_z + 4) + 48) / (float)(*(float *)(*((_DWORD *)p_m_z + 4) + 48) + v71));
        v50 = (float)((float)v48 * (float)v49);
        v51 = *((_DWORD *)p_m_z + 4);
        v52 = *(float *)(v51 + 56);
        v53 = (float)(*(float *)&this->m_commonState + (float)((float)v38 * (float)((float)v48 * (float)v49)));
        v54 = (float)((float)((float)v39 * (float)((float)v48 * (float)v49)) + this->m_pos3D.m_x);
        v55 = (float)((float)(*(float *)&this->__vftable + (float)((float)v37 * (float)((float)v48 * (float)v49)))
                    * *(float *)(v51 + 56));
        *(float *)&this->__vftable = (float)(*(float *)&this->__vftable
                                           + (float)((float)v37 * (float)((float)v48 * (float)v49)))
                                   * *(float *)(v51 + 56);
        v56 = (float)((float)v53 * (float)v52);
        *(float *)&this->m_commonState = (float)v53 * (float)v52;
        v57 = (float)((float)v54 * (float)v52);
        this->m_pos3D.m_x = (float)v54 * (float)v52;
        if ( computeSlideAcc && v50 > v73 )
        {
          v58 = (float)(bfx::WalkerImpl::GetDesSpeed(this: (bfx::WalkerImpl *)result) * (float)0.5);
          if ( v74 <= v58 )
          {
            v62 = (float)(result[4].m_x - (float)v27);
            _FP1 = (float)((float)__fsqrts((float)((float)((float)v62 * (float)v62)
                                                 + (float)((float)((float)(result[4].m_z - v76[0].m_data[10])
                                                                 * (float)(result[4].m_z - v76[0].m_data[10]))
                                                         + (float)((float)(result[4].m_y - v76[0].m_data[9])
                                                                 * (float)(result[4].m_y - v76[0].m_data[9])))))
                         - 1.0842022e-19);
            __asm { fsel      f10, f1, f0, f21 }
            v60 = (float)((float)(result[4].m_y - v76[0].m_data[9]) * (float)_FP10);
            v59 = (float)((float)_FP10 * (float)(result[4].m_x - (float)v27));
            v61 = (float)((float)(result[4].m_z - v76[0].m_data[10]) * (float)_FP10);
          }
          else if ( v74 == 0.0 )
          {
            v59 = bfx::ZERO_VEC.m_x;
            v60 = bfx::ZERO_VEC.m_y;
            v61 = bfx::ZERO_VEC.m_z;
          }
          else
          {
            v76[0].m_data[13] = (float)((float)1.0 / v74) * (float)v43;
            v76[0].m_data[12] = (float)((float)1.0 / v74) * (float)v47;
            v76[0].m_data[14] = (float)((float)1.0 / v74) * (float)v45;
            v59 = v76[0].m_data[12];
            v61 = v76[0].m_data[14];
            v60 = v76[0].m_data[13];
          }
          if ( (float)((float)((float)v37 * (float)v59)
                     + (float)((float)((float)v61 * (float)v39) + (float)((float)v60 * (float)v38))) < (double)(float)-0.30000001
            && (float)((float)((float)v44 * (float)v61)
                     + (float)((float)((float)v46 * (float)v59) + (float)((float)v42 * (float)v60))) < v58 )
          {
            v66 = v37;
            v67 = v39;
            v68 = (float)((float)((float)v60 * (float)v28) - (float)((float)v29 * (float)v59));
            v65 = -v38;
            if ( v68 < 0.0 )
            {
              v65 = (float)((float)v65 * v75);
              v66 = (float)((float)v37 * v75);
              v67 = (float)((float)v39 * v75);
            }
            v73 = v50;
            v69 = __fsqrts((float)((float)((float)v56 * (float)v56)
                                 + (float)((float)((float)v55 * (float)v55) + (float)((float)v57 * (float)v57))));
            slideAcc->m_x = (float)((float)v69 * v72) * (float)v65;
            slideAcc->m_y = (float)v66 * (float)((float)v69 * v72);
            slideAcc->m_z = (float)v67 * (float)((float)v69 * v72);
          }
        }
      }
      ++v18;
      ++m_pRecs;
      p_m_z += 12;
    }
    while ( v18 < repRecs->m_size );
  }
  return this;
}


// ========================================================================
// ?CalcRVOAcc@WalkerImpl@bfx@@AAA?AVVec3@2@XZ
// EA  : 0x832D1CE8
// RVA : 0x012D1CE8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

bfx::WalkerImpl *__fastcall bfx::WalkerImpl::CalcRVOAcc(bfx::WalkerImpl *this, bfx::Vec3 *result, long double a3)
{
  float m_x; // r10
  float m_z; // r9
  double v7; // fp30
  double v8; // fp10
  double v9; // fp11
  float *v10; // r8
  float *v11; // r10
  double i; // fp0
  double v13; // fp12
  double v14; // fp13
  char v15; // r11
  double v16; // fp13
  char v17; // r11
  double v18; // fp0
  double v19; // fp13
  double v20; // fp12
  char v21; // r11
  double v22; // fp13
  char v23; // r11
  double v24; // fp0
  float m_y; // r9
  int v26; // r8
  double v27; // fp0
  double v28; // fp13
  double v29; // fp12
  double v30; // fp11
  float v32; // [sp+58h] [-38h] BYREF
  float v33; // [sp+5Ch] [-34h]
  float v34; // [sp+60h] [-30h]

  m_x = result[47].m_x;
  *(float *)&this->__vftable = 0.0;
  *(float *)&this->m_commonState = 0.0;
  this->m_pos3D.m_x = 0.0;
  if ( m_x != 0.0 )
  {
    m_z = result[46].m_z;
    v7 = 0.0;
    v8 = 0.0;
    v9 = 0.0;
    v10 = (float *)(8 * LODWORD(m_x) + LODWORD(m_z));
    v11 = (float *)LODWORD(m_z);
    for ( i = -3.4028235e38; v11 != v10; v11 += 2 )
    {
      v13 = v11[1];
      v14 = (float)(v11[1] - (float)i);
      v32 = v11[1];
      v33 = i;
      if ( v14 >= 0.52359879 )
      {
        if ( v11 == (float *)LODWORD(m_z) )
        {
          v11 = (float *)LODWORD(v32);
          v9 = v33;
        }
        else
        {
          if ( v13 < 0.0 || (v15 = 1, i > 0.0) )
            v15 = 0;
          if ( v15 != 0 )
          {
            i = 0.0;
          }
          else if ( i <= 0.0 )
          {
            i = v13;
          }
          v16 = __fabs(i);
          if ( v8 < 0.0 || (v17 = 1, v9 > 0.0) )
            v17 = 0;
          if ( v17 != 0 )
          {
            v18 = 0.0;
          }
          else if ( v9 <= 0.0 )
          {
            v18 = v8;
          }
          else
          {
            v18 = v9;
          }
          if ( v16 >= __fabs(v18) )
            goto LABEL_24;
          v11 = (float *)LODWORD(v32);
          v9 = (float)(v33 + (float)0.2617994);
        }
        v8 = (float)((float)v13 - (float)0.2617994);
      }
LABEL_24:
      i = *v11;
    }
    v32 = 3.4028235e38;
    v33 = i;
    if ( i > 0.0 )
      v19 = i;
    else
      v19 = 0.0;
    v20 = __fabs(v19);
    if ( v8 < 0.0 || (v21 = 1, v9 > 0.0) )
      v21 = 0;
    if ( v21 != 0 )
    {
      v22 = 0.0;
    }
    else if ( v9 <= 0.0 )
    {
      v22 = v8;
    }
    else
    {
      v22 = v9;
    }
    if ( v20 < __fabs(v22) )
    {
      v9 = (float)((float)i + (float)0.2617994);
      v8 = v32;
    }
    if ( v8 < 0.0 || (v23 = 1, v9 > 0.0) )
      v23 = 0;
    if ( v23 == 0 )
    {
      v24 = v9 <= 0.0 ? v8 : v9;
      if ( v24 != 0.0 )
        v7 = v24;
    }
    bfx::Orienter::GetForward(this: (bfx::Orienter *)&v32, result: (bfx::Vec3 *)(LODWORD(result->m_y) + 128), a3);
    m_y = result->m_y;
    v26 = *(_DWORD *)(LODWORD(m_y) + 4);
    v27 = (float)(*(float *)(v26 + 44) * (float)3.0);
    v28 = (float)((float)(*(float *)(LODWORD(m_y) + 196) * v32) - (float)(v34 * *(float *)(LODWORD(m_y) + 188)));
    v29 = (float)((float)(v33 * *(float *)(LODWORD(m_y) + 188)) - (float)(*(float *)(LODWORD(m_y) + 192) * v32));
    v30 = (float)((float)(v34 * *(float *)(LODWORD(m_y) + 192)) - (float)(v33 * *(float *)(LODWORD(m_y) + 196)));
    if ( __fabs(v7) > 0.087266468 )
    {
      if ( v7 <= 0.0 )
        v27 = -v27;
      this->m_pos3D.m_x = (float)((float)(v33 * *(float *)(LODWORD(m_y) + 188))
                                - (float)(*(float *)(LODWORD(m_y) + 192) * v32))
                        * (float)v27;
      *(float *)&this->m_commonState = (float)v28 * (float)v27;
      *(float *)&this->__vftable = (float)v30 * (float)v27;
    }
    else
    {
      *(float *)&this->__vftable = (float)((float)(v34 * *(float *)(LODWORD(m_y) + 192))
                                         - (float)(v33 * *(float *)(LODWORD(m_y) + 196)))
                                 * (float)((float)((float)v7 * (float)11.459156)
                                         * (float)(*(float *)(v26 + 44) * (float)3.0));
      *(float *)&this->m_commonState = (float)v28 * (float)((float)((float)v7 * (float)11.459156) * (float)v27);
      this->m_pos3D.m_x = (float)v29 * (float)((float)((float)v7 * (float)11.459156) * (float)v27);
    }
  }
  return this;
}


// ========================================================================
// ?CalcPathAcc@WalkerImpl@bfx@@AAA?AVVec3@2@_N00M@Z
// EA  : 0x832D2070
// RVA : 0x012D2070
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

bfx::WalkerImpl *__fastcall bfx::WalkerImpl::CalcPathAcc(
        bfx::WalkerImpl *this,
        bfx::Vec3 *result,
        bool targetPosIsGoal,
        bool deceleratingTowardsGoal,
        bool proximityDecel,
        double simTime)
{
  float *v9; // r25
  float *UVel; // r3
  double v15; // fp23
  double v16; // fp22
  double v17; // fp10
  double v19; // fp11
  const bfx::PathCC *v20; // r5
  double v25; // fp29
  double v26; // fp28
  double v27; // fp27
  int v28; // r29
  double m_heading; // fp26
  float m_y; // r11
  bfx::Vec3 *v31; // r4
  bfx::Matrix *v34; // r3
  double v36; // fp0
  float *SurferUPos; // r3
  bfx::Vec3 *v41; // r26
  double v42; // fp29
  double v43; // fp28
  double Scale; // fp1
  double v45; // fp10
  double v53; // fp23
  double v54; // fp20
  double v55; // fp24
  double v56; // fp17
  double v57; // fp16
  double v59; // fp15
  long double v63; // fp2
  double v64; // fp22
  float v73; // r11
  double m_headingVel; // fp19
  double v75; // fp21
  int v76; // r10
  double v77; // fp13
  double v78; // fp10
  double v79; // fp8
  double v82; // fp28
  float v83; // r11
  const bfx::Array<bfx::SmartPathCorner> *NCorners; // r3
  float v85; // r9
  float v86; // r3
  float m_x; // r6
  float m_z; // r11
  float *v89; // r3
  double v90; // fp29
  double v94; // fp4
  double v95; // fp3
  long double v101; // fp2
  float v102; // r11
  int v103; // r10
  float v104; // r9
  _DWORD *v105; // r10
  double v106; // fp0
  int m_x_high; // r10
  double v108; // fp27
  bool v109; // r11
  float *v110; // r3
  double v111; // fp9
  double v112; // fp7
  double v117; // fp4
  double v118; // fp3
  double v119; // fp2
  double v120; // fp9
  double v121; // fp0
  double v122; // fp1
  bfx::Vec3 *v123; // r3
  double v124; // fp0
  double v125; // fp13
  double v126; // fp12
  double v127; // fp13
  double v134; // fp0
  double v135; // fp24
  double v136; // fp25
  double v137; // fp23
  double v138; // fp13
  double v139; // fp0
  double v140; // fp0
  double v141; // fp26
  double v142; // fp11
  double v143; // fp13
  double v144; // fp28
  double v145; // fp29
  bfx::Vec3 *v149; // r3
  double v150; // fp31
  double v151; // fp30
  double v152; // fp29
  float v153; // r11
  bfx::Vec3 *v154; // r31
  bfx::Vec3 *v155; // r3
  bfx::Vec3 *v156; // r3
  bfx::Vec3 v158; // [sp+50h] [-1B0h] BYREF
  __int64 v159; // [sp+60h] [-1A0h]
  float v160; // [sp+68h] [-198h]
  float v161; // [sp+6Ch] [-194h]
  bfx::Orienter v162; // [sp+70h] [-190h] BYREF
  float v163; // [sp+23Ch] [+3Ch]

  v163 = simTime;
  v9 = *(float **)(LODWORD(result->m_y) + 4);
  v161 = 1.0;
  _FP18 = 1.0;
  _FP19 = 1.0;
  UVel = (float *)bfx::WalkerImpl::GetUVel(this: (bfx::WalkerImpl *)&v162, result);
  v15 = *UVel;
  v16 = UVel[1];
  *(float *)&v159 = *UVel;
  *((float *)&v159 + 1) = v16;
  bfx::WalkerImpl::GetSurferUPos(this: (bfx::WalkerImpl *)&v158, result);
  v17 = v9[11];
  *(float *)&v162.m_accelMode = 2.0;
  v162.m_heading = 3.4028235e38;
  _FP14 = 3.4028235e38;
  v162.m_clientSpecifiedRotSpeed = 3.4028235e38;
  v162.m_headingVel = (float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15);
  v19 = (float)(v9[7] * (float)2.0);
  v162.m_headingFrameMatrix.m_data[12] = NAN;
  v162.m_headingFrameMatrix.m_data[11] = 0.0;
  v20 = (const bfx::PathCC *)(LODWORD(result[6].m_y) + 4972);
  _FP6 = (float)((float)__fsqrts(v162.m_headingVel) - (float)1.0842022e-19);
  _FP4 = (float)((float)(v162.m_headingVel / (float)v17) - (float)(v162.m_headingVel / (float)v19));
  __asm
  {
    fsel      f3, f6, f5, f30
    fsel      f2, f4, f8, f7
  }
  v25 = (float)((float)((float)v15 * (float)_FP3) * (float)_FP2);
  *(float *)&v162.m_pSpace = (float)((float)v15 * (float)_FP3) * (float)_FP2;
  v26 = (float)((float)((float)v16 * (float)_FP3) * (float)_FP2);
  *(float *)&v162.m_pTune = (float)((float)v16 * (float)_FP3) * (float)_FP2;
  v27 = (float)((float)((float)_FP3 * (float)0.0) * (float)_FP2);
  *(float *)&v162.m_state = (float)((float)_FP3 * (float)0.0) * (float)_FP2;
  v28 = (unsigned __int8)bfx::RayCastThroughPathAndToBumpers(
                           start: &v158,
                           origDelta: (const bfx::Vec3 *)&v162,
                           pathStart: v20,
                           collideEdgeCursor: (bfx::EdgeCursor *)&v162.m_headingFrameMatrix.m_data[11],
                           distToCollide: &v162.m_heading,
                           distToBumpers: &v162.m_clientSpecifiedRotSpeed);
  m_heading = v162.m_heading;
  if ( v28 != 0 )
  {
    m_y = result[6].m_y;
    result[51].m_y = v162.m_heading;
    if ( m_y == 0.0 )
      v31 = (bfx::Vec3 *)&bfx::IDENTITY;
    else
      v31 = (bfx::Vec3 *)((*(_DWORD *)(LODWORD(m_y) + 4968) << 6) + LODWORD(m_y) + 3048);
    _FP6 = (float)((float)__fsqrts((float)((float)((float)v26 * (float)v26)
                                         + (float)((float)((float)v25 * (float)v25) + (float)((float)v27 * (float)v27))))
                 - 1.0842022e-19);
    __asm { fsel      f4, f6, f5, f30 }
    v162.m_slerpStartRot.m_x = v158.m_x + (float)((float)((float)_FP4 * (float)v25) * (float)m_heading);
    v162.m_slerpStartRot.m_y = v158.m_y + (float)((float)((float)v26 * (float)_FP4) * (float)m_heading);
    v162.m_slerpStartRot.m_z = v158.m_z + (float)((float)((float)v27 * (float)_FP4) * (float)m_heading);
    v34 = bfx::Matrix::Rot(this: (bfx::Matrix *)&v162, result: v31, rhs: (const bfx::Vec3 *)&v162.m_slerpStartRot.m_x);
    result[50].m_y = v34->m_data[0];
    result[50].m_z = v34->m_data[1];
    result[51].m_x = v34->m_data[2];
  }
  if ( v28 != 0 || v162.m_clientSpecifiedRotSpeed < 3.4028235e38 )
  {
    _FP12 = (float)((float)m_heading - v162.m_clientSpecifiedRotSpeed);
    __asm { fsel      f14, f12, f0, f26 }
    v36 = __fsqrts((float)((float)((float)v26 * (float)v26)
                         + (float)((float)((float)v25 * (float)v25) + (float)((float)v27 * (float)v27))));
    if ( v36 == 0.0 )
    {
      _FP18 = 10.0;
    }
    else if ( v36 > 1.0842022e-19 )
    {
      _FP8 = (float)((float)1.0
                   - (float)((float)((float)((float)((float)v36 - (float)_FP14) / (float)v36) * (float)9.0) + (float)1.0));
      _FP7 = (float)((float)10.0
                   - (float)((float)((float)((float)((float)v36 - (float)_FP14) / (float)v36) * (float)9.0) + (float)1.0));
      __asm { fsel      f6, f8, f21, f9 }
      __asm { fsel      f18, f7, f5, f13 }
    }
  }
  SurferUPos = (float *)bfx::WalkerImpl::GetSurferUPos(this: (bfx::WalkerImpl *)&v162, result);
  v41 = result + 4;
  v42 = (float)(result[4].m_x - *SurferUPos);
  v43 = (float)(result[4].m_y - SurferUPos[1]);
  if ( targetPosIsGoal )
  {
    Scale = bfx::GetScale();
    v45 = __fsqrts((float)((float)((float)v43 * (float)v43) + (float)((float)v42 * (float)v42)));
    _FP6 = (float)((float)1.0
                 - (float)((float)((float)((float)((float)((float)Scale * (float)5.0) - (float)v45)
                                         / (float)((float)Scale * (float)5.0))
                                 * (float)2.0)
                         + (float)1.0));
    _FP5 = (float)((float)3.0
                 - (float)((float)((float)((float)((float)((float)Scale * (float)5.0) - (float)v45)
                                         / (float)((float)Scale * (float)5.0))
                                 * (float)2.0)
                         + (float)1.0));
    __asm { fsel      f4, f6, f21, f7 }
    __asm { fsel      f19, f5, f3, f0 }
  }
  _FP7 = (float)((float)__fsqrts((float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15)))
               - 1.0842022e-19);
  _FP8 = (float)((float)__fsqrts((float)((float)((float)v43 * (float)v43) + (float)((float)v42 * (float)v42)))
               - 1.0842022e-19);
  __asm
  {
    fsel      f3, f7, f5, f30
    fsel      f4, f8, f6, f30
  }
  v53 = (float)((float)_FP3 * (float)v15);
  v54 = (float)((float)_FP4 * (float)v42);
  *(float *)&v162.m_state = (float)_FP4 * (float)0.0;
  v55 = (float)((float)v43 * (float)_FP4);
  v56 = (float)((float)v16 * (float)_FP3);
  v57 = (float)((float)_FP3 * (float)0.0);
  *((double *)&_FP2 + 1) = (float)((float)v53 * (float)((float)_FP4 * (float)v42));
  v59 = (float)((float)((float)_FP3 * (float)0.0) * *(float *)&v162.m_state);
  _FP13 = (float)((float)-1.0
                - (float)((float)((float)((float)((float)v16 * (float)_FP3) * (float)((float)v43 * (float)_FP4))
                                + (float)((float)v53 * (float)((float)_FP4 * (float)v42)))
                        + (float)((float)((float)_FP3 * (float)0.0) * *(float *)&v162.m_state)));
  _FP12 = (float)((float)1.0
                - (float)((float)((float)((float)((float)v16 * (float)_FP3) * (float)((float)v43 * (float)_FP4))
                                + (float)((float)v53 * (float)((float)_FP4 * (float)v42)))
                        + (float)((float)((float)_FP3 * (float)0.0) * *(float *)&v162.m_state)));
  __asm { fsel      f11, f13, f25, f0 }
  __asm { fsel      f1, f12, f10, f31# x }
  v63 = acos(x: _FP2);
  v64 = (float)*(double *)&v63;
  if ( v64 <= 0.17453294 )
  {
    _FP29 = v161;
  }
  else
  {
    _FP11 = (float)((float)1.0
                  - (float)((float)((float)((float)*(double *)&v63 - (float)0.17453294) * (float)4.583662) + (float)1.0));
    _FP10 = (float)((float)5.0
                  - (float)((float)((float)((float)*(double *)&v63 - (float)0.17453294) * (float)4.583662) + (float)1.0));
    __asm { fsel      f9, f11, f21, f12 }
    __asm { fsel      f29, f10, f8, f27 }
    v161 = _FP29;
  }
  _FP0 = (float)((float)_FP18 - (float)_FP19);
  *(float *)&this->__vftable = 0.0;
  *(float *)&this->m_commonState = 0.0;
  this->m_pos3D.m_x = 0.0;
  __asm { fsel      f13, f0, f18, f19 }
  _FP12 = (float)((float)_FP13 - (float)_FP29);
  __asm { fsel      f13, f12, f13, f29 }
  if ( proximityDecel )
    _FP13 = 1.0;
  v73 = result->m_y;
  m_headingVel = v162.m_headingVel;
  v75 = (float)(v9[11] * (float)_FP13);
  v76 = *(_DWORD *)(LODWORD(v73) + 4);
  if ( *(float *)(v76 + 48) >= 1.0 )
    goto LABEL_37;
  v77 = __fsqrts(m_headingVel);
  v78 = 1.0842022e-19;
  v79 = 3.4028235e38;
  _FP9 = (float)(v9[6] - v9[11]);
  __asm { fsel      f0, f9, f0, f11 }
  if ( _FP0 <= 1.0842022e-19 )
    v82 = 3.4028235e38;
  else
    v82 = (float)((float)((float)v77 / (float)_FP0) * (float)v77);
  if ( *(float *)(LODWORD(v73) + 396) == 1.0 && v28 != 0 && v75 > 1.0842022e-19 && v82 > _FP14 )
  {
    *(float *)(LODWORD(v73) + 396) = *(float *)(v76 + 48);
    *(float *)(LODWORD(result->m_y) + 400) = _FP14;
  }
  if ( v82 > 0.0 )
  {
    v83 = result->m_y;
    if ( *(float *)(LODWORD(v83) + 396) == 1.0 )
    {
      HIWORD(v162.m_headingFrameMatrix.m_data[3]) = 0;
      LODWORD(v162.m_headingFrameMatrix.m_data[1]) = 1;
      v162.m_headingFrameMatrix.m_data[2] = (float)v82 * (float)1.1;
      NCorners = bfx::SmartPath::CalcNextNCorners(
                   this: *(bfx::SmartPath **)(LODWORD(v83) + 100),
                   calcCornersSpec: (bfx::CalcCornersSpec *)&v162.m_headingFrameMatrix.m_data[1]);
      if ( NCorners != nullptr && NCorners->m_size != 0 )
      {
        v85 = result->m_y;
        m_x = NCorners->m_data->m_pos.m_x;
        m_z = NCorners->m_data->m_pos.m_z;
        v86 = NCorners->m_data->m_pos.m_y;
        v162.m_headingFrameMatrix.m_data[9] = (float)v82 * *(float *)&v162.m_accelMode;
        v162.m_dir.m_x = 0.0;
        HIBYTE(v162.m_headingFrameMatrix.m_data[10]) = 0;
        *(bfx::Vec3 *)&v162.m_headingFrameMatrix.m_data[13] = bfx::ZERO_VEC;
        *(bfx::Vec3 *)&v162.m_dir.m_y = bfx::ZERO_VEC;
        memset(&v162.m_targetPos, 0, sizeof(v162.m_targetPos));
        v158.m_y = v86;
        v158.m_x = m_x;
        v158.m_z = m_z;
        if ( (unsigned __int8)bfx::SmartPath::GetPosAlongPath(
                                this: *(bfx::SmartPath **)(LODWORD(v85) + 100),
                                spec: (const bfx::PosAlongPathSpecInternal *)&v162.m_headingFrameMatrix.m_data[9],
                                dataOut: (bfx::PosAlongPathDataInternal *)&v162.m_headingFrameMatrix.m_data[13]) != 0 )
        {
          v89 = (float *)(*(int (__fastcall **)(float *, bfx::Vec3 *))(LODWORD(result->m_x) + 24))(
                           a1: &v162.m_headingFrameMatrix.m_data[5],
                           a2: result);
          v90 = (float)((float)((float)(v158.m_y - v89[1]) * (float)(v158.m_y - v89[1]))
                      + (float)((float)((float)(v158.m_x - *v89) * (float)(v158.m_x - *v89))
                              + (float)((float)(v158.m_z - v89[2]) * (float)(v158.m_z - v89[2]))));
          if ( v90 < (float)((float)v82 * (float)v82) )
          {
            _FP4 = (float)((float)__fsqrts(v90) - 1.0842022e-19);
            __asm { fsel      f1, f4, f3, f30 }
            _FP6 = (float)((float)__fsqrts((float)((float)((float)(v162.m_headingFrameMatrix.m_data[14] - v158.m_y)
                                                         * (float)(v162.m_headingFrameMatrix.m_data[14] - v158.m_y))
                                                 + (float)((float)((float)(v162.m_headingFrameMatrix.m_data[13]
                                                                         - v158.m_x)
                                                                 * (float)(v162.m_headingFrameMatrix.m_data[13]
                                                                         - v158.m_x))
                                                         + (float)((float)(v162.m_headingFrameMatrix.m_data[15]
                                                                         - v158.m_z)
                                                                 * (float)(v162.m_headingFrameMatrix.m_data[15]
                                                                         - v158.m_z)))))
                         - 1.0842022e-19);
            v94 = (float)((float)(v158.m_z - v89[2]) * (float)_FP1);
            v95 = (float)((float)_FP1 * (float)(v158.m_x - *v89));
            *((double *)&_FP2 + 1) = (float)((float)(v158.m_y - v89[1]) * (float)_FP1);
            __asm { fsel      f1, f6, f5, f30 }
            _FP6 = (float)((float)-1.0
                         - (float)((float)((float)((float)(v162.m_headingFrameMatrix.m_data[14] - v158.m_y) * (float)_FP1)
                                         * (float)*((double *)&_FP2 + 1))
                                 + (float)((float)((float)((float)_FP1
                                                         * (float)(v162.m_headingFrameMatrix.m_data[13] - v158.m_x))
                                                 * (float)v95)
                                         + (float)((float)((float)(v162.m_headingFrameMatrix.m_data[15] - v158.m_z)
                                                         * (float)_FP1)
                                                 * (float)v94))));
            _FP5 = (float)((float)1.0
                         - (float)((float)((float)((float)(v162.m_headingFrameMatrix.m_data[14] - v158.m_y) * (float)_FP1)
                                         * (float)*((double *)&_FP2 + 1))
                                 + (float)((float)((float)((float)_FP1
                                                         * (float)(v162.m_headingFrameMatrix.m_data[13] - v158.m_x))
                                                 * (float)v95)
                                         + (float)((float)((float)(v162.m_headingFrameMatrix.m_data[15] - v158.m_z)
                                                         * (float)_FP1)
                                                 * (float)v94))));
            __asm { fsel      f4, f6, f25, f7 }
            __asm { fsel      f1, f5, f3, f31# x }
            v101 = acos(x: _FP2);
            v102 = result->m_y;
            v103 = *(_DWORD *)(LODWORD(v102) + 4);
            if ( (float)((float)*(double *)&v101 * (float)57.295776) >= (double)*(float *)(v103 + 52) )
            {
              *(float *)(LODWORD(v102) + 396) = *(float *)(v103 + 48);
              *(float *)(LODWORD(result->m_y) + 400) = __fsqrts(v90);
            }
          }
          _FP29 = v161;
        }
      }
LABEL_37:
      v78 = 1.0842022e-19;
      v79 = 3.4028235e38;
    }
  }
  v104 = result->m_y;
  v105 = *(_DWORD **)(LODWORD(v104) + 364);
  if ( v105 != nullptr && *v105 != 0 )
    v106 = *(float *)(LODWORD(v104) + 368);
  else
    v106 = 1.0;
  m_x_high = HIBYTE(result[28].m_x);
  v108 = (float)((float)((float)(**(float **)(LODWORD(v104) + 4) * *(float *)(LODWORD(v104) + 396))
                       * *(float *)(LODWORD(v104) + 388))
               * (float)v106);
  v109 = HIBYTE(result[28].m_x) != 0
      || *(_BYTE *)(*(_DWORD *)(LODWORD(v104) + 4) + 212) == 0
      || *(_DWORD *)(LODWORD(v104) + 112) > 1u;
  if ( v109
    && (v64 >= 2.0943952
     || __fsqrts(m_headingVel) <= (float)((float)((float)((float)(**(float **)(LODWORD(v104) + 4)
                                                                * *(float *)(LODWORD(v104) + 396))
                                                        * *(float *)(LODWORD(v104) + 388))
                                                * (float)v106)
                                        * (float)0.0099999998)) )
  {
    v110 = (float *)bfx::WalkerImpl::GetSurferUPos(
                      this: (bfx::WalkerImpl *)&v162.m_headingFrameMatrix.m_data[5],
                      result);
    v111 = (float)(result[4].m_y - v110[1]);
    v112 = (float)(result[4].m_z - v110[2]);
    _FP2 = (float)(v9[6] - v9[11]);
    __asm { fsel      f8, f2, f3, f4 }
    _FP2 = (float)((float)__fsqrts((float)((float)((float)(v41->m_x - *v110) * (float)(v41->m_x - *v110))
                                         + (float)((float)((float)v112 * (float)v112)
                                                 + (float)((float)v111 * (float)v111))))
                 - 1.0842022e-19);
    __asm { fsel      f13, f2, f0, f30 }
    v117 = (float)((float)_FP8 * (float)((float)_FP13 * (float)(v41->m_x - *v110)));
    v118 = (float)((float)((float)(result[4].m_y - v110[1]) * (float)_FP13) * (float)_FP8);
    v119 = (float)((float)((float)_FP13 * (float)(v41->m_x - *v110)) * (float)v108);
    v120 = (float)((float)((float)(result[4].m_y - v110[1]) * (float)_FP13) * (float)v108);
    v121 = (float)((float)((float)(result[4].m_z - v110[2]) * (float)_FP13) * (float)v108);
    v158.m_z = (float)((float)((float)(result[4].m_z - v110[2]) * (float)_FP13) * (float)_FP8) * (float)_FP29;
    v158.m_x = (float)v117 * (float)_FP29;
    v158.m_y = (float)v118 * (float)_FP29;
    if ( v163 <= 1.0842022e-19 )
      v122 = 3.4028235e38;
    else
      v122 = (float)((float)__fsqrts((float)((float)((float)((float)v119 - *(float *)&v159)
                                                   * (float)((float)v119 - *(float *)&v159))
                                           + (float)((float)((float)v121 * (float)v121)
                                                   + (float)((float)((float)v120 - *((float *)&v159 + 1))
                                                           * (float)((float)v120 - *((float *)&v159 + 1))))))
                   / v163);
    v123 = bfx::LimitMag(vec: *(__int64 *)&v158.m_x, limit: v122);
    v124 = v123->m_x;
    v125 = v123->m_y;
    v126 = v123->m_z;
  }
  else
  {
    v127 = -v55;
    _FP6 = -(float)((float)v64 * (float)11.459156);
    _FP5 = (float)((float)1.0 - (float)((float)v64 * (float)11.459156));
    __asm { fsel      f3, f6, f0, f11 }
    *((double *)&_FP2 + 1) = (float)((float)((float)((float)v55 * (float)v53) + (float)((float)-v56 * (float)v54))
                                   + (float)v59);
    *(double *)&_FP2 = (float)_FP3;
    __asm
    {
      fsel      f0, f2, f31, f26
      fsel      f11, f5, f1, f31
    }
    v134 = (float)((float)((float)_FP11 * (float)_FP0) * (float)v75);
    v135 = (float)((float)v53 * (float)v134);
    v158.m_y = (float)v53 * (float)v134;
    v136 = (float)((float)-v56 * (float)v134);
    v158.m_x = (float)-v56 * (float)v134;
    v137 = (float)((float)v57 * (float)v134);
    v158.m_z = (float)v57 * (float)v134;
    if ( v163 <= v78 )
      v138 = v79;
    else
      v138 = (float)((float)__fabs((float)((float)(*(float *)&v162.m_state * (float)0.0)
                                         + (float)((float)(*((float *)&v159 + 1) * (float)v54)
                                                 + (float)((float)v127 * *(float *)&v159))))
                   / v163);
    v139 = __fabs(v134);
    if ( v139 > v138 && v139 > v78 )
    {
      v140 = (float)((float)v138 / (float)v139);
      v136 = (float)((float)v136 * (float)v140);
      v158.m_x = v136;
      v135 = (float)((float)v135 * (float)v140);
      v158.m_y = v135;
      v137 = (float)((float)v137 * (float)v140);
      v158.m_z = v137;
    }
    v141 = __fsqrts(m_headingVel);
    if ( BYTE1(result[26].m_y) != 0 )
      v142 = v9[7];
    else
      v142 = v9[6];
    if ( *(float *)(LODWORD(v104) + 396) != 1.0 )
    {
      *((double *)&_FP2 + 1) = (float)(*(float *)(LODWORD(v104) + 388) * *v9);
      *(double *)&_FP2 = *(float *)(LODWORD(v104) + 400);
      v143 = __fsqrts((float)((float)(result[2].m_y * result[2].m_y)
                            + (float)((float)(result[1].m_z * result[1].m_z) + (float)(result[2].m_x * result[2].m_x))));
      if ( (float)(*(float *)(LODWORD(v104) + 400)
                 / (float)((float)((float)((float)(*(float *)(LODWORD(v104) + 388) * *v9)
                                         * *(float *)(LODWORD(v104) + 396))
                                 + (float)v143)
                         * (float)0.5)) > v78 )
        v142 = __fabs((float)((float)((float)((float)(*(float *)(LODWORD(v104) + 388) * *v9)
                                            * *(float *)(LODWORD(v104) + 396))
                                    - (float)v143)
                            / (float)(*(float *)(LODWORD(v104) + 400)
                                    / (float)((float)((float)((float)(*(float *)(LODWORD(v104) + 388) * *v9)
                                                            * *(float *)(LODWORD(v104) + 396))
                                                    + (float)v143)
                                            * (float)0.5))));
    }
    result[50].m_x = v142;
    if ( v108 <= 0.0 )
      v144 = 0.0;
    else
      v144 = (float)((float)v142 / (float)v108);
    if ( deceleratingTowardsGoal || proximityDecel )
      v144 = 0.0;
    if ( v163 <= v78 )
      v145 = v79;
    else
      v145 = (float)((float)__fabs((float)((float)v108 - (float)v141)) / v163);
    if ( m_x_high != 0 || *(_BYTE *)(*(_DWORD *)(LODWORD(v104) + 4) + 212) == 0 || *(_DWORD *)(LODWORD(v104) + 112) > 1u )
    {
      _FP11 = (float)((float)__fsqrts(m_headingVel) - (float)v78);
      __asm { fsel      f8, f11, f10, f30 }
      *(float *)&v159 = (float)((float)_FP8 * *(float *)&v159)
                      * (float)((float)((float)v108 - (float)v141) * (float)v144);
      *((float *)&v159 + 1) = (float)(*((float *)&v159 + 1) * (float)_FP8)
                            * (float)((float)((float)v108 - (float)v141) * (float)v144);
      v160 = (float)((float)_FP8 * (float)0.0) * (float)((float)((float)v108 - (float)v141) * (float)v144);
      v149 = bfx::LimitMag(vec: v159, limit: v145);
      v150 = v149->m_x;
      v151 = v149->m_y;
      v152 = v149->m_z;
    }
    else
    {
      v153 = result[6].m_y;
      if ( v153 == 0.0 )
        v154 = (bfx::Vec3 *)&bfx::IDENTITY;
      else
        v154 = (bfx::Vec3 *)((*(_DWORD *)(LODWORD(v153) + 4968) << 6) + LODWORD(v153) + 4008);
      bfx::Orienter::GetForward(this: &v162, result: (bfx::Vec3 *)(LODWORD(v104) + 128), a3: _FP2);
      bfx::Matrix::Rot(this: (bfx::Matrix *)&v162.m_slerpDuration, result: v154, rhs: (const bfx::Vec3 *)&v162);
      *(float *)&v159 = v162.m_slerpDuration * (float)((float)((float)v108 - (float)v141) * (float)v144);
      *((float *)&v159 + 1) = *(float *)&v162.m_slerping * (float)((float)((float)v108 - (float)v141) * (float)v144);
      v160 = v162.m_curRot.m_data[0] * (float)((float)((float)v108 - (float)v141) * (float)v144);
      v155 = bfx::LimitMag(vec: v159, limit: v145);
      v150 = v155->m_x;
      v151 = v155->m_y;
      v152 = v155->m_z;
      v156 = bfx::LimitMag(
               vec: *(__int64 *)&v158.m_x,
               limit: (float)((float)m_headingVel / (float)(v9[2] * *(float *)&v162.m_accelMode)));
      v136 = v156->m_x;
      v135 = v156->m_y;
      v137 = v156->m_z;
    }
    v124 = (float)((float)v150 + (float)v136);
    v125 = (float)((float)v151 + (float)v135);
    v126 = (float)((float)v152 + (float)v137);
  }
  this->m_pos3D.m_x = v126;
  *(float *)&this->m_commonState = v125;
  *(float *)&this->__vftable = v124;
  return this;
}


// ========================================================================
// ?CheckForGoalApproach@WalkerImpl@bfx@@AAAX_N0@Z
// EA  : 0x832D2BF0
// RVA : 0x012D2BF0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::WalkerImpl::CheckForGoalApproach(bfx::WalkerImpl *this, bool targetPosIsGoal, bool proximityDecel)
{
  long double v6; // fp2
  double v7; // fp30
  double v8; // fp27
  double v9; // fp29
  double v10; // fp26
  double v11; // fp28
  double v12; // fp25
  double v13; // fp24
  double v14; // fp13
  double v15; // fp11
  double v16; // fp9
  double v17; // fp7
  double v18; // fp12
  const bfx::Vec3 *v19; // r3
  double m_x; // fp0
  double m_y; // fp13
  double m_z; // fp12
  bfx::MotionState *m_commonState; // r11
  double m_orbitMinDist; // fp0
  char v25; // r28
  bfx::Vec3 *p_m_goalDir; // r30
  double v29; // fp29
  double v30; // fp28
  double v31; // fp27
  float *Forward; // r3
  long double v37; // fp2
  double v38; // fp29
  char v39; // r10
  char v48; // r28
  double v49; // fp30
  double Scale; // fp1
  char v51; // r11
  char v52; // r29
  bool v53; // r30
  const bfx::Vec3 *v54; // r3
  double v55; // fp0
  double v56; // fp13
  double v57; // fp12
  bfx::MotionState *v58; // r11
  bfx::Orienter v59; // [sp+50h] [-190h] BYREF

  if ( this->m_state == PATH_MOVE && !this->m_firstFrameOfMovement )
  {
    bfx::WalkerImpl::GetSurferUPos(this: (bfx::WalkerImpl *)&v59, result: (bfx::Vec3 *)this);
    v7 = *(float *)&v59.m_state;
    v8 = (float)(this->m_targetPosU.m_z - *(float *)&v59.m_state);
    v9 = *(float *)&v59.m_pSpace;
    v10 = (float)(this->m_targetPosU.m_x - *(float *)&v59.m_pSpace);
    v11 = *(float *)&v59.m_pTune;
    v12 = (float)(this->m_targetPosU.m_y - *(float *)&v59.m_pTune);
    v13 = __fsqrts((float)((float)((float)(this->m_targetPosU.m_y - *(float *)&v59.m_pTune)
                                 * (float)(this->m_targetPosU.m_y - *(float *)&v59.m_pTune))
                         + (float)((float)((float)(this->m_targetPosU.m_x - *(float *)&v59.m_pSpace)
                                         * (float)(this->m_targetPosU.m_x - *(float *)&v59.m_pSpace))
                                 + (float)((float)(this->m_targetPosU.m_z - *(float *)&v59.m_state)
                                         * (float)(this->m_targetPosU.m_z - *(float *)&v59.m_state)))));
    if ( this->m_gotoPosSpec.m_desiredStopDist > 0.0 && this->m_goalIsInSight )
    {
      bfx::WalkerImpl::GetUVel(this: (bfx::WalkerImpl *)&v59, result: (bfx::Vec3 *)this);
      v14 = this->m_gotoPosSpec.m_stopAtGoal
          ? (float)((float)((float)((float)(*(float *)&v59.m_state * *(float *)&v59.m_state)
                                  + (float)((float)(*(float *)&v59.m_pSpace * *(float *)&v59.m_pSpace)
                                          + (float)(*(float *)&v59.m_pTune * *(float *)&v59.m_pTune)))
                          / (float)(this->m_commonState->m_pTune->m_startStopAcc * 2.0))
                  + this->m_gotoPosSpec.m_desiredStopDist)
          : this->m_gotoPosSpec.m_desiredStopDist;
      v15 = (float)(this->m_trueTargetPosU.m_z - (float)v7);
      v16 = (float)(this->m_trueTargetPosU.m_x - (float)v9);
      v17 = (float)(this->m_trueTargetPosU.m_y - (float)v11);
      v18 = __fsqrts((float)((float)((float)v17 * (float)v17)
                           + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))));
      if ( v18 <= v14 )
      {
        if ( v18 <= this->m_gotoPosSpec.m_desiredStopDist
          && !this->m_gotoPosSpec.m_stopAtGoal
          && (unsigned __int8)bfx::WalkerImpl::NeedToTurnToSatisfyGoalDir(this) == 0 )
        {
          this->m_reachedGoal = true;
        }
        if ( this->m_commonState->m_orientCmd.m_mode <= (unsigned int)ORIENT_STRICTLY_IN_TRAVEL_DIR )
        {
          if ( (unsigned __int8)bfx::WalkerImpl::PerformRoundedCornering(this) != 0 )
          {
            m_x = this->m_goalData.m_goalDir.m_x;
            m_y = this->m_goalData.m_goalDir.m_y;
            m_z = this->m_goalData.m_goalDir.m_z;
          }
          else
          {
            v19 = this->GetPos(this: &v59, result: this);
            bfx::Orienter::CalcMat(
              this: &this->m_commonState->m_orienter,
              pos: v19,
              mat: (bfx::Matrix *)&v59.m_headingFrameMatrix.m_data[9]);
            m_x = v59.m_headingFrameMatrix.m_data[9];
            m_y = v59.m_headingFrameMatrix.m_data[10];
            m_z = v59.m_headingFrameMatrix.m_data[11];
          }
          v59.m_clientSpecifiedRotSpeed = m_z;
          m_commonState = this->m_commonState;
          *(float *)&v59.m_accelMode = m_y;
          v59.m_headingVel = m_x;
          bfx::Orienter::FaceInDir(this: &m_commonState->m_orienter, dir: (const bfx::Vec3 *)&v59.m_headingVel);
        }
        if ( this->m_state == 4 )
        {
          this->m_onFinalRotationAction.m_restartGotoPos = false;
          this->m_onFinalRotationAction.m_changeOrientMode = false;
        }
        this->m_orbitDirection = 0.0;
        this->m_orbitSpeed = 0.0;
        this->m_orbitMinDist = -1.0;
        this->m_orbitCenter.m_x = 0.0;
        this->m_orbitCenter.m_y = 0.0;
        this->m_orbitCenter.m_z = 0.0;
        this->m_orbitDisable = false;
        this->m_orbitRadius = 0.0;
        this->m_state = 3;
        this->m_orbitGoalDirection = 0.0;
        this->m_orbitPrevMinDist = -1.0;
      }
    }
    if ( targetPosIsGoal )
    {
      if ( this->m_orbitDirection == 0.0 )
      {
        if ( v13 < this->m_gotoPosSpec.m_allowedToStopDist )
        {
          bfx::WalkerImpl::GetObservedUVel(
            this: (bfx::WalkerImpl *)&v59.m_headingFrameMatrix.m_data[5],
            result: (bfx::Vec3 *)this);
          v48 = 0;
          v49 = __fsqrts((float)((float)(v59.m_headingFrameMatrix.m_data[5] * v59.m_headingFrameMatrix.m_data[5])
                               + (float)((float)(v59.m_headingFrameMatrix.m_data[6] * v59.m_headingFrameMatrix.m_data[6])
                                       + (float)(v59.m_headingFrameMatrix.m_data[7] * v59.m_headingFrameMatrix.m_data[7]))));
          if ( v49 < (float)(bfx::WalkerImpl::GetDesSpeed(this) * (float)0.001)
            || (Scale = bfx::GetScale(), v51 = 0, v49 < (float)((float)Scale * (float)0.0000099999997)) )
          {
            v51 = 1;
          }
          v52 = v51;
          v53 = v49 < (float)(bfx::WalkerImpl::GetDesSpeed(this) * (float)0.1);
          if ( (float)((float)(v59.m_headingFrameMatrix.m_data[6] * (float)v12)
                     + (float)((float)(v59.m_headingFrameMatrix.m_data[5] * (float)v10)
                             + (float)(v59.m_headingFrameMatrix.m_data[7] * (float)v8))) <= 0.0
            && this->m_distMoved > (double)(float)(bfx::GetScale() * (float)0.1)
            || v52 != 0 && v13 < (float)(bfx::GetScale() * (float)0.0099999998)
            || proximityDecel && v53 )
          {
            v48 = 1;
          }
          if ( v48 != 0 )
          {
            if ( !this->m_gotoPosSpec.m_stopAtGoal
              && (unsigned __int8)bfx::WalkerImpl::NeedToTurnToSatisfyGoalDir(this) == 0 )
            {
              this->m_reachedGoal = true;
            }
            if ( this->m_commonState->m_orientCmd.m_mode <= (unsigned int)ORIENT_STRICTLY_IN_TRAVEL_DIR )
            {
              if ( (unsigned __int8)bfx::WalkerImpl::PerformRoundedCornering(this) != 0 )
              {
                v55 = this->m_goalData.m_goalDir.m_x;
                v56 = this->m_goalData.m_goalDir.m_y;
                v57 = this->m_goalData.m_goalDir.m_z;
              }
              else
              {
                v54 = this->GetPos(this: &v59, result: this);
                bfx::Orienter::CalcMat(
                  this: &this->m_commonState->m_orienter,
                  pos: v54,
                  mat: (bfx::Matrix *)&v59.m_curRot.m_data[12]);
                v55 = v59.m_curRot.m_data[12];
                v56 = v59.m_curRot.m_data[13];
                v57 = v59.m_curRot.m_data[14];
              }
              v59.m_headingFrameMatrix.m_data[3] = v57;
              v58 = this->m_commonState;
              v59.m_headingFrameMatrix.m_data[2] = v56;
              v59.m_headingFrameMatrix.m_data[1] = v55;
              bfx::Orienter::FaceInDir(
                this: &v58->m_orienter,
                dir: (const bfx::Vec3 *)&v59.m_headingFrameMatrix.m_data[1]);
            }
            if ( this->m_state == 4 )
            {
              this->m_onFinalRotationAction.m_restartGotoPos = false;
              this->m_onFinalRotationAction.m_changeOrientMode = false;
            }
            this->m_orbitDirection = 0.0;
            this->m_orbitSpeed = 0.0;
            this->m_orbitMinDist = -1.0;
            this->m_orbitCenter.m_x = 0.0;
            this->m_orbitCenter.m_y = 0.0;
            this->m_orbitCenter.m_z = 0.0;
            this->m_state = 3;
            goto LABEL_64;
          }
        }
      }
      else
      {
        m_orbitMinDist = this->m_orbitMinDist;
        v25 = 0;
        if ( m_orbitMinDist > 0.0
          && m_orbitMinDist <= this->m_gotoPosSpec.m_allowedToStopDist
          && v13 > (float)(this->m_orbitMinDist * (float)1.25) )
        {
          goto LABEL_38;
        }
        if ( v13 < this->m_gotoPosSpec.m_allowedToStopDist )
        {
          p_m_goalDir = &this->m_goalData.m_goalDir;
          _FP5 = (float)((float)__fsqrts((float)((float)(this->m_goalData.m_goalDir.m_x * this->m_goalData.m_goalDir.m_x)
                                               + (float)((float)(this->m_goalData.m_goalDir.m_y
                                                               * this->m_goalData.m_goalDir.m_y)
                                                       + (float)(this->m_goalData.m_goalDir.m_z
                                                               * this->m_goalData.m_goalDir.m_z))))
                       - 1.0842022e-19);
          __asm { fsel      f3, f5, f4, f31 }
          v29 = (float)(this->m_goalData.m_goalDir.m_x * (float)_FP3);
          v30 = (float)((float)_FP3 * this->m_goalData.m_goalDir.m_y);
          v31 = (float)(this->m_goalData.m_goalDir.m_z * (float)_FP3);
          Forward = (float *)bfx::Orienter::GetForward(
                               this: &v59,
                               result: (bfx::Vec3 *)&this->m_commonState->m_orienter,
                               a3: v6);
          *((double *)&_FP2 + 1) = Forward[1];
          _FP9 = (float)((float)-1.0
                       - (float)((float)(*Forward * (float)v29)
                               + (float)((float)(Forward[2] * (float)v31) + (float)(Forward[1] * (float)v30))));
          _FP8 = (float)((float)1.0
                       - (float)((float)(*Forward * (float)v29)
                               + (float)((float)(Forward[2] * (float)v31) + (float)(Forward[1] * (float)v30))));
          __asm { fsel      f7, f9, f0, f10 }
          __asm { fsel      f1, f8, f6, f30# x }
          v37 = acos(x: _FP2);
          v38 = (float)*(double *)&v37;
          bfx::Orienter::CalcMat(
            this: &this->m_commonState->m_orienter,
            pos: &bfx::ZERO_VEC,
            mat: (bfx::Matrix *)&v59.m_slerpStartRot.m_z);
          v39 = 0;
          if ( this->m_orbitMinDist < (double)(float)(this->m_gotoPosSpec.m_allowedToStopDist * (float)0.25) )
          {
            _FP0 = this->m_commonState->m_orienter.m_headingVel;
            if ( _FP0 > 0.0 )
              goto LABEL_67;
            __asm { fsel      f0, f0, f31, f23 }
            if ( _FP0 > 0.0 )
            {
LABEL_67:
              _FP1 = (float)((float)__fsqrts((float)((float)(p_m_goalDir->m_x * p_m_goalDir->m_x)
                                                   + (float)((float)(p_m_goalDir->m_y * p_m_goalDir->m_y)
                                                           + (float)(p_m_goalDir->m_z * p_m_goalDir->m_z))))
                           - 1.0842022e-19);
              __asm { fsel      f9, f1, f0, f31 }
              if ( (float)((float)((float)(this->m_goalData.m_goalDir.m_z * (float)_FP9) * v59.m_curRot.m_data[2])
                         + (float)((float)(v59.m_curRot.m_data[0] * (float)(this->m_goalData.m_goalDir.m_x * (float)_FP9))
                                 + (float)((float)((float)_FP9 * this->m_goalData.m_goalDir.m_y) * v59.m_curRot.m_data[1]))) < 0.0 )
                goto LABEL_34;
            }
            _FP0 = this->m_commonState->m_orienter.m_headingVel;
            if ( _FP0 <= 0.0 )
            {
              __asm { fsel      f0, f0, f31, f23 }
              if ( _FP0 < 0.0 )
              {
                _FP1 = (float)((float)__fsqrts((float)((float)(p_m_goalDir->m_z * p_m_goalDir->m_z)
                                                     + (float)((float)(p_m_goalDir->m_x * p_m_goalDir->m_x)
                                                             + (float)(p_m_goalDir->m_y * p_m_goalDir->m_y))))
                             - 1.0842022e-19);
                __asm { fsel      f13, f1, f0, f31 }
                if ( (float)((float)(v59.m_curRot.m_data[0] * (float)(this->m_goalData.m_goalDir.m_x * (float)_FP13))
                           + (float)((float)((float)((float)_FP13 * this->m_goalData.m_goalDir.m_y)
                                           * v59.m_curRot.m_data[1])
                                   + (float)((float)(this->m_goalData.m_goalDir.m_z * (float)_FP13)
                                           * v59.m_curRot.m_data[2]))) > 0.0 )
LABEL_34:
                  v39 = 1;
              }
            }
          }
          if ( v38 < 0.017453292 || v38 < 0.087266468 && v39 != 0 )
LABEL_38:
            v25 = 1;
        }
        if ( v25 != 0 )
        {
          this->m_orbitDirection = 0.0;
          this->m_reachedGoal = true;
          this->m_orbitSpeed = 0.0;
          this->m_orbitMinDist = -1.0;
          this->m_orbitCenter.m_x = 0.0;
          this->m_orbitCenter.m_y = 0.0;
          this->m_orbitCenter.m_z = 0.0;
LABEL_64:
          this->m_orbitPrevMinDist = -1.0;
          this->m_orbitDisable = false;
          this->m_orbitGoalDirection = 0.0;
          this->m_orbitRadius = 0.0;
        }
      }
    }
  }
}


// ========================================================================
// ?GetRepRecs@WalkerImpl@bfx@@AAAXAAVFastArrayOfRepRecs@2@@Z
// EA  : 0x832D32B8
// RVA : 0x012D32B8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::WalkerImpl::GetRepRecs(bfx::WalkerImpl *this, bfx::FastArrayOfRepRecs *repRecs)
{
  bfx::MotionState *m_commonState; // r11
  bool m_ignoreUpsideDownMovers; // r19
  bfx::UPath *m_pUPath; // r20
  int m_size; // r22
  bfx::MotionState *v8; // r4
  bfx::RepulsorImpl *m_pRepulsor; // r9
  float *p_m_speed; // r11
  bfx::AABB *m_pAABB; // r10
  double v12; // fp12
  double v13; // fp11
  bfx::RepRec *m_pRecs; // r30
  double v15; // fp30
  bfx::Array<bfx::AABB *> *m_pArray; // r11
  int m_i; // r21
  _DWORD *p_m_radius; // r28
  int v19; // r10
  const bfx::RepulsorImpl *m_pUserData; // r31
  bfx::Area **p_m_pArea; // r11
  bfx::Area *v22; // r27
  bfx::RepulsorOwner *m_pOwner; // r11
  char v24; // r29
  bfx::RepulsorOwner *v25; // r11
  unsigned int v26; // r25
  int v27; // r11
  int v28; // r10
  int v29; // r10
  float m_x; // r7
  float m_y; // r8
  int m_repulsorType; // r27
  bfx::UPath *v33; // r11
  bfx::Vec3 *v34; // r29
  float m_z; // r10
  float v36; // r11
  bfx::Matrix *v37; // r18
  bfx::Matrix *v38; // r3
  float v39; // r8
  float v40; // r10
  bfx::UPath *v41; // r11
  int m_curIdx; // r7
  bfx::Vec3 *v43; // r29
  char v44; // r27
  bfx::RepulsorOwner *v45; // r11
  char v46; // r3
  bfx::MotionState *v47; // r11
  float v48; // r9
  float v49; // r10
  float v50; // r10
  float v51; // r9
  int v52; // r27
  float v53; // r7
  float v54; // r6
  bfx::Matrix *v55; // r18
  bfx::Matrix *v56; // r3
  bfx::NearbyRepulsorCursor v57; // [sp+50h] [-180h] BYREF
  float v58; // [sp+60h] [-170h]
  float v59; // [sp+64h] [-16Ch]
  float v60; // [sp+68h] [-168h]
  float v61; // [sp+70h] [-160h]
  float v62; // [sp+74h] [-15Ch]
  float v63; // [sp+78h] [-158h]
  bfx::Vec3 v64; // [sp+80h] [-150h] BYREF
  float v65; // [sp+90h] [-140h]
  float v66; // [sp+94h] [-13Ch]
  float v67; // [sp+98h] [-138h]
  bfx::Vec3 v68; // [sp+A0h] [-130h] BYREF
  bfx::Vec3 v69; // [sp+B0h] [-120h] BYREF
  bfx::Vec3 v70; // [sp+C0h] [-110h] BYREF
  bfx::Vec3 v71; // [sp+D0h] [-100h] BYREF
  float v72[4]; // [sp+E0h] [-F0h] BYREF
  bfx::Matrix v73; // [sp+F0h] [-E0h] BYREF
  bfx::Matrix v74; // [sp+130h] [-A0h] BYREF

  m_commonState = this->m_commonState;
  if ( m_commonState->m_pRepulsor != nullptr )
  {
    m_ignoreUpsideDownMovers = m_commonState->m_pTune->m_ignoreUpsideDownMovers;
    bfx::FastArrayOfRepRecs::Reserve(this: repRecs, count: m_commonState->m_pRepulsor->m_pAABB->m_overlaps.m_size);
    repRecs->m_size = 0;
    m_pUPath = this->m_pUPath;
    m_size = m_pUPath->m_origPath.m_areas.m_size;
    this->GetPos(this: (struct bfx::WalkerImpl *)v72, result: (bfx::Vec3 *)this);
    v8 = this->m_commonState;
    v57.m_overlapCursor.m_i = 0;
    v57.m_filterBasedOnBlockageFlags = true;
    m_pRepulsor = v8->m_pRepulsor;
    p_m_speed = &v8->m_pTune->m_speed;
    m_pAABB = m_pRepulsor->m_pAABB;
    v12 = (float)(p_m_speed[4] + p_m_speed[3]);
    v13 = p_m_speed[2];
    v57.m_blockageFlags = m_pRepulsor->m_blockageFlags;
    v57.m_overlapCursor.m_pArray = &m_pAABB->m_overlaps;
    m_pRecs = repRecs->m_pRecs;
    v15 = (float)((float)v12 + (float)v13);
    bfx::NearbyRepulsorCursor::AdvanceToNextRepulsorSatisfyingFilter(this: &v57);
    m_pArray = v57.m_overlapCursor.m_pArray;
    m_i = v57.m_overlapCursor.m_i;
    if ( v57.m_overlapCursor.m_i < v57.m_overlapCursor.m_pArray->m_size )
    {
      p_m_radius = (_DWORD *)&m_pRecs->m_radiusDat.m_radius;
      v19 = v57.m_overlapCursor.m_i;
      do
      {
        m_pUserData = (const bfx::RepulsorImpl *)m_pArray->m_data[v19]->m_pUserData;
        p_m_pArea = &m_pUserData->m_areaHandle.m_pProxy->m_pArea;
        if ( p_m_pArea != nullptr )
          v22 = *p_m_pArea;
        else
          v22 = nullptr;
        m_pOwner = m_pUserData->m_pOwner;
        v24 = 0;
        if ( m_pOwner != nullptr
          && m_pOwner->m_creatorType == REPULSOR_CREATOR_MOVER
          && m_pUserData->m_pOwner->GetRepulsorOwner(this: m_pUserData->m_pOwner) != nullptr )
        {
          v25 = m_pUserData->m_pOwner;
          if ( v25 != nullptr && v25->m_creatorType == REPULSOR_CREATOR_MOVER )
            v26 = *((_DWORD *)m_pUserData->m_pOwner->GetRepulsorOwner(this: m_pUserData->m_pOwner) + 103);
          else
            v26 = MEMORY[0x19C];
        }
        else
        {
          v26 = 0;
        }
        if ( v22 != nullptr )
        {
          v27 = 0;
          if ( m_size > 0 )
          {
            v28 = 0;
            while ( v22 != m_pUPath->m_origPath.m_areas.m_data[v28] )
            {
              ++v27;
              ++v28;
              if ( v27 >= m_size )
                goto LABEL_22;
            }
            v29 = v27 << 6;
            m_x = m_pUserData->m_vel.m_x;
            m_y = m_pUserData->m_vel.m_y;
            m_repulsorType = m_pUserData->m_repulsorType;
            v33 = this->m_pUPath;
            v68.m_z = m_pUserData->m_vel.m_z;
            v68.m_x = m_x;
            v68.m_y = m_y;
            v34 = (bfx::Vec3 *)((char *)v33->m_g2u + v29);
            m_z = m_pUserData->m_pos.m_z;
            v36 = m_pUserData->m_pos.m_y;
            v71.m_x = m_pUserData->m_pos.m_x;
            v71.m_y = v36;
            v71.m_z = m_z;
            v37 = bfx::Matrix::Rot(this: &v73, result: v34, rhs: &v68);
            v38 = bfx::Matrix::operator*(this: &v74, result: v34, rhs: &v71);
            m_pRecs->m_pos.m_x = v38->m_data[0];
            v24 = 1;
            m_pRecs->m_pos.m_y = v38->m_data[1];
            m_pRecs->m_pos.m_z = v38->m_data[2];
            m_pRecs->m_vel.m_x = v37->m_data[0];
            m_pRecs->m_vel.m_y = v37->m_data[1];
            m_pRecs->m_vel.m_z = v37->m_data[2];
            *p_m_radius = LODWORD(m_pUserData->m_radiusData.m_radius);
            p_m_radius[1] = LODWORD(m_pUserData->m_radiusData.m_outerCushion);
            p_m_radius[2] = LODWORD(m_pUserData->m_radiusData.m_innerCushion);
            p_m_radius += 12;
            m_pRecs->m_pRep = m_pUserData;
            m_pRecs->m_flockID = v26;
            m_pRecs->m_repulsorType = m_repulsorType;
            ++m_pRecs;
            ++repRecs->m_size;
          }
        }
LABEL_22:
        if ( v24 == 0 )
        {
          v39 = m_pUserData->m_pos.m_z;
          v40 = m_pUserData->m_pos.m_x;
          v41 = this->m_pUPath;
          v62 = m_pUserData->m_pos.m_y;
          v63 = v39;
          v61 = v40;
          m_curIdx = v41->m_curIdx;
          v69.m_x = v72[0] - v40;
          v69.m_y = v72[1] - v62;
          v69.m_z = v72[2] - v39;
          v43 = (bfx::Vec3 *)&v41->m_g2u[m_curIdx];
          if ( __fabs(bfx::Matrix::Rot(this: (bfx::Matrix *)&v73.m_data[12], result: v43, rhs: &v69)->m_data[2]) < (float)((float)((float)(m_pUserData->m_radiusData.m_innerCushion + m_pUserData->m_radiusData.m_outerCushion) + m_pUserData->m_radiusData.m_radius) + (float)v15) )
          {
            v44 = 0;
            if ( m_ignoreUpsideDownMovers )
            {
              v45 = m_pUserData->m_pOwner;
              if ( v45 != nullptr )
                v46 = ((int (*)(void))v45->GetRepulsorNormal)();
              else
                v46 = 0;
              if ( v46 != 0 )
              {
                v47 = this->m_commonState;
                v48 = v47->m_surfer.m_areaNormal.m_x;
                v49 = v47->m_surfer.m_areaNormal.m_z;
                v59 = v47->m_surfer.m_areaNormal.m_y;
                v58 = v48;
                v60 = v49;
                if ( (float)((float)(v65 * v48) + (float)((float)(v59 * v66) + (float)(v49 * v67))) < -0.70700002 )
                  v44 = 1;
              }
            }
            if ( v44 == 0 )
            {
              v50 = m_pUserData->m_vel.m_y;
              v51 = m_pUserData->m_vel.m_z;
              v52 = m_pUserData->m_repulsorType;
              v64.m_x = m_pUserData->m_vel.m_x;
              v64.m_y = v50;
              v64.m_z = v51;
              v53 = m_pUserData->m_pos.m_x;
              v54 = m_pUserData->m_pos.m_z;
              v70.m_y = m_pUserData->m_pos.m_y;
              v70.m_x = v53;
              v70.m_z = v54;
              v55 = bfx::Matrix::Rot(this: (bfx::Matrix *)&v73.m_data[4], result: v43, rhs: &v64);
              v56 = bfx::Matrix::operator*(this: (bfx::Matrix *)&v73.m_data[8], result: v43, rhs: &v70);
              m_pRecs->m_pos.m_x = v56->m_data[0];
              m_pRecs->m_pos.m_y = v56->m_data[1];
              m_pRecs->m_pos.m_z = v56->m_data[2];
              m_pRecs->m_vel.m_x = v55->m_data[0];
              m_pRecs->m_vel.m_y = v55->m_data[1];
              m_pRecs->m_vel.m_z = v55->m_data[2];
              *p_m_radius = LODWORD(m_pUserData->m_radiusData.m_radius);
              p_m_radius[1] = LODWORD(m_pUserData->m_radiusData.m_outerCushion);
              p_m_radius[2] = LODWORD(m_pUserData->m_radiusData.m_innerCushion);
              p_m_radius += 12;
              m_pRecs->m_pRep = m_pUserData;
              m_pRecs->m_flockID = v26;
              m_pRecs->m_repulsorType = v52;
              ++m_pRecs;
              ++repRecs->m_size;
            }
          }
        }
        v57.m_overlapCursor.m_i = m_i + 1;
        bfx::NearbyRepulsorCursor::AdvanceToNextRepulsorSatisfyingFilter(this: &v57);
        m_pArray = v57.m_overlapCursor.m_pArray;
        m_i = v57.m_overlapCursor.m_i;
        v19 = v57.m_overlapCursor.m_i;
      }
      while ( v57.m_overlapCursor.m_i < v57.m_overlapCursor.m_pArray->m_size );
    }
  }
}


// ========================================================================
// ?Simulate@WalkerImpl@bfx@@UAAXM@Z
// EA  : 0x832D3788
// RVA : 0x012D3788
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::WalkerImpl::Simulate(bfx::WalkerImpl *this, double simTime)
{
  float *SurferUPos; // r3
  double v5; // fp31
  double v6; // fp29
  double v7; // fp28
  double m_orbitMinDist; // fp0
  double v9; // fp2
  double v10; // fp1
  double v11; // fp13
  double v12; // fp13
  bfx::MotionState *m_commonState; // r9
  bfx::Vec3 *p_m_vel; // r30
  float m_y; // r8
  float m_z; // r7
  bfx::Vec3 *(__fastcall *GetPos)(struct bfx::WalkerImpl *, bfx::Vec3 *); // r6
  const bfx::MoverTune *m_pTune; // r29
  double v19; // fp10
  double v20; // fp9
  double v21; // fp7
  double v22; // fp6
  bfx::AreaProxy *m_pProxy; // r11
  bfx::Vec3 *m_pArea; // r4
  double v25; // fp11
  double v26; // fp9
  double v27; // fp4
  double v28; // fp3
  double v29; // fp2
  bfx::MotionState *v30; // r11
  double v31; // fp12
  float *p_m_speed; // r10
  double v33; // fp13
  double v34; // fp12
  double v35; // fp10
  bfx::MotionState::FollowData *p_m_followData; // r11
  bfx::HandleProxy *v37; // r10
  char v38; // r11
  bfx::MotionState *v39; // r11
  bool v40; // r29
  bfx::MotionState *v41; // r10
  bfx::HandleProxy *v42; // r9
  double v43; // fp31
  double m_followSpeedX; // fp0
  char v45; // r3
  bfx::WalkerImpl::State m_state; // r11
  double v47; // fp0
  bfx::WalkerImpl::State v48; // r11
  bfx::MotionState *v49; // r11
  const bfx::Vec3 *p_m_clientSpecifiedVel; // r4
  double v51; // fp6
  double v52; // fp4
  bfx::MotionState *v53; // r11
  const bfx::Vec3 *v54; // r3
  double v55; // fp31
  bfx::MotionState *v56; // r9
  bfx::Prober *m_pProber; // r11
  bfx::Vec3 *v58; // r10
  char *m_y_low; // r7
  bfx::HalfLink *m_z_low; // r6
  double v61; // fp8
  double v62; // fp6
  bfx::Vec3 *v63; // r3
  BOOL m_clientAvgVelIsDirty; // r9
  double v65; // fp7
  double v66; // fp6
  bfx::RepulsorImpl *m_pRepulsor; // r11
  double v68; // fp0
  bfx::Area v69; // [sp+50h] [-120h] BYREF
  float v70; // [sp+88h] [-E8h]
  float v71; // [sp+90h] [-E0h] BYREF
  float v72; // [sp+94h] [-DCh]
  float v73; // [sp+98h] [-D8h]
  bfx::Box v74; // [sp+A0h] [-D0h] BYREF
  char v75; // [sp+C0h] [-B0h] BYREF
  float v76; // [sp+E0h] [-90h]
  float v77; // [sp+E4h] [-8Ch]
  float v78; // [sp+E8h] [-88h]

  bfx::WalkerImpl::UpdateUnwrappedPathIfNeeded(this, bForce: false);
  if ( this->m_orbitDirection != 0.0 )
  {
    SurferUPos = (float *)bfx::WalkerImpl::GetSurferUPos(this: (bfx::WalkerImpl *)&v69, result: (bfx::Vec3 *)this);
    v5 = (float)(this->m_trueTargetPosU.m_x - *SurferUPos);
    v6 = (float)(this->m_trueTargetPosU.m_y - SurferUPos[1]);
    v7 = (float)(this->m_trueTargetPosU.m_z - SurferUPos[2]);
    bfx::WalkerImpl::CalcGoalURot(this: (bfx::WalkerImpl *)&v75, result: (bfx::Matrix *)this);
    m_orbitMinDist = this->m_orbitMinDist;
    v9 = (float)((float)v6
               - (float)(v77
                       * (float)((float)(v77 * (float)v6) + (float)((float)(v76 * (float)v5) + (float)(v78 * (float)v7)))));
    v10 = (float)((float)v7
                - (float)(v78
                        * (float)((float)(v77 * (float)v6) + (float)((float)(v76 * (float)v5) + (float)(v78 * (float)v7)))));
    v11 = (float)((float)v5
                - (float)(v76
                        * (float)((float)(v77 * (float)v6) + (float)((float)(v76 * (float)v5) + (float)(v78 * (float)v7)))));
    v12 = __fsqrts((float)((float)((float)v11 * (float)v11)
                         + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))));
    if ( m_orbitMinDist < 0.0 || v12 < m_orbitMinDist )
      this->m_orbitMinDist = v12;
  }
  m_commonState = this->m_commonState;
  p_m_vel = &this->m_vel;
  m_y = this->m_vel.m_y;
  m_z = this->m_vel.m_z;
  GetPos = this->GetPos;
  v69.m_pos.m_x = this->m_vel.m_x;
  m_pTune = m_commonState->m_pTune;
  v69.m_pos.m_y = m_y;
  v69.m_pos.m_z = m_z;
  GetPos(this: (struct bfx::WalkerImpl *)&v71, result: (bfx::Vec3 *)this);
  v19 = (float)(this->m_acc.m_y * (float)simTime);
  v20 = (float)(this->m_acc.m_z * (float)simTime);
  v21 = this->m_vel.m_y;
  v22 = this->m_vel.m_z;
  this->m_vel.m_x = (float)(this->m_acc.m_x * (float)simTime) + this->m_vel.m_x;
  this->m_vel.m_y = (float)v19 + (float)v21;
  this->m_vel.m_z = (float)v20 + (float)v22;
  m_pProxy = this->m_commonState->m_surfer.m_area.m_pProxy;
  if ( m_pProxy != nullptr )
    m_pArea = (bfx::Vec3 *)m_pProxy->m_pArea;
  else
    m_pArea = nullptr;
  bfx::Area::CalcNormal(this: &v69, result: m_pArea);
  v25 = this->m_vel.m_z;
  v26 = this->m_vel.m_y;
  v27 = (float)(*(float *)&v69.m_dynAreaData.m_data
              * (float)((float)(*(float *)&v69.m_pProxy * this->m_vel.m_x)
                      + (float)((float)(*(float *)&v69.m_dynAreaData.m_data * this->m_vel.m_y)
                              + (float)(*(float *)&v69.m_pFirstLink * this->m_vel.m_z))));
  v28 = (float)(*(float *)&v69.m_pFirstLink
              * (float)((float)(*(float *)&v69.m_pProxy * this->m_vel.m_x)
                      + (float)((float)(*(float *)&v69.m_dynAreaData.m_data * this->m_vel.m_y)
                              + (float)(*(float *)&v69.m_pFirstLink * this->m_vel.m_z))));
  v29 = (float)(this->m_vel.m_x
              - (float)((float)((float)(*(float *)&v69.m_pProxy * this->m_vel.m_x)
                              + (float)((float)(*(float *)&v69.m_dynAreaData.m_data * this->m_vel.m_y)
                                      + (float)(*(float *)&v69.m_pFirstLink * this->m_vel.m_z)))
                      * *(float *)&v69.m_pProxy));
  this->m_vel.m_x = this->m_vel.m_x
                  - (float)((float)((float)(*(float *)&v69.m_pProxy * this->m_vel.m_x)
                                  + (float)((float)(*(float *)&v69.m_dynAreaData.m_data * this->m_vel.m_y)
                                          + (float)(*(float *)&v69.m_pFirstLink * this->m_vel.m_z)))
                          * *(float *)&v69.m_pProxy);
  this->m_vel.m_y = (float)v26 - (float)v27;
  this->m_vel.m_z = (float)v25 - (float)v28;
  v30 = this->m_commonState;
  v31 = (float)((float)((float)v29 * (float)v29)
              + (float)((float)((float)((float)v26 - (float)v27) * (float)((float)v26 - (float)v27))
                      + (float)((float)((float)v25 - (float)v28) * (float)((float)v25 - (float)v28))));
  p_m_speed = &v30->m_pTune->m_speed;
  v33 = (float)((float)(*p_m_speed * v30->m_speedX) * m_pTune->m_maxSpeedFraction);
  if ( v31 > (float)((float)v33 * (float)v33) && v31 > 0.0 )
  {
    v34 = __fsqrts(v31);
    v35 = this->m_vel.m_z;
    p_m_vel->m_x = (float)((float)((float)(*p_m_speed * v30->m_speedX) * m_pTune->m_maxSpeedFraction) / (float)v34)
                 * (float)v29;
    this->m_vel.m_y = (float)((float)v33 / (float)v34) * (float)((float)v26 - (float)v27);
    this->m_vel.m_z = (float)((float)v33 / (float)v34) * (float)v35;
  }
  v37 = this->m_commonState->m_followData.m_targetMover.m_pProxy;
  if ( v37 == nullptr
    || v37->m_pTarget == nullptr
    || (float)((float)((p_m_followData = &this->m_commonState->m_followData)->m_externalForce.m_z
                     * p_m_followData->m_externalForce.m_z)
             + (float)((float)(p_m_followData->m_externalForce.m_x * p_m_followData->m_externalForce.m_x)
                     + (float)(p_m_followData->m_externalForce.m_y * p_m_followData->m_externalForce.m_y))) <= 0.0009765625
    || (v38 = 1, this->m_commonState->m_followData.m_sidePushCountdown <= 0.0) )
  {
    v38 = 0;
  }
  if ( v38 != 0 && this->m_state != PATH_MOVE )
    bfx::WalkerImpl::SwitchState(this, newState: PATH_MOVE);
  if ( this->m_state == 3 )
  {
    bfx::WalkerImpl::GetObservedVel(this: (bfx::WalkerImpl *)&v69, result: (bfx::Vec3 *)this);
    v39 = this->m_commonState;
    v40 = false;
    if ( v39->m_pTune->m_clientMotion
      && v39->m_surfer.m_state == 1
      && (unsigned __int8)bfx::SavedPositions::GetBoundingBox(this: &this->m_savedPositions, bboxOut: &v74) != 0 )
    {
      v40 = (float)((float)__fsqrts((float)((float)((float)(v74.m_max.m_y - v74.m_min.m_y)
                                                  * (float)(v74.m_max.m_y - v74.m_min.m_y))
                                          + (float)((float)((float)(v74.m_max.m_x - v74.m_min.m_x)
                                                          * (float)(v74.m_max.m_x - v74.m_min.m_x))
                                                  + (float)((float)(v74.m_max.m_z - v74.m_min.m_z)
                                                          * (float)(v74.m_max.m_z - v74.m_min.m_z)))))
                  * (float)0.5) < (double)(float)(this->m_commonState->m_pTune->m_radiusData.m_radius
                                                * (float)0.050000001);
    }
    v41 = this->m_commonState;
    v42 = v41->m_followData.m_targetMover.m_pProxy;
    v43 = __fsqrts((float)((float)(*(float *)&v69.m_pFirstLink * *(float *)&v69.m_pFirstLink)
                         + (float)((float)(*(float *)&v69.m_pProxy * *(float *)&v69.m_pProxy)
                                 + (float)(*(float *)&v69.m_dynAreaData.m_data * *(float *)&v69.m_dynAreaData.m_data))));
    if ( v42 != nullptr && v42->m_pTarget != nullptr )
      m_followSpeedX = v41->m_followData.m_followSpeedX;
    else
      m_followSpeedX = 1.0;
    if ( v43 < (float)((float)((float)((float)(v41->m_pTune->m_speed * v41->m_cautionData.m_internalSpeedX)
                                     * v41->m_speedX)
                             * (float)m_followSpeedX)
                     * (float)0.050000001)
      || v43 <= (float)(bfx::GetScale() * (float)0.0000099999997)
      || v40 )
    {
      bfx::EnactDelayedOrientationMode(action: &this->m_onStopAction, orienter: &this->m_commonState->m_orienter);
      if ( this->m_onStopAction.m_restartGotoPos )
      {
        this->m_onStopAction.m_restartGotoPos = false;
        if ( bfx::WalkerImpl::UseTurnInPlace(this) )
          bfx::WalkerImpl::SwitchState(this, newState: (bfx::WalkerImpl::State)1);
        else
          bfx::WalkerImpl::SwitchState(this, newState: PATH_MOVE);
      }
      else
      {
        v45 = bfx::WalkerImpl::NeedToTurnToSatisfyGoalDir(this);
        m_state = this->m_state;
        if ( v45 != 0 )
        {
          if ( m_state == 4 )
          {
            this->m_onFinalRotationAction.m_restartGotoPos = false;
            this->m_onFinalRotationAction.m_changeOrientMode = false;
          }
          bfx::Orienter::FaceInDir(this: &this->m_commonState->m_orienter, dir: &this->m_goalData.m_goalDir);
          this->m_orbitDirection = 0.0;
          this->m_orbitSpeed = 0.0;
          v47 = -1.0;
          this->m_orbitMinDist = -1.0;
          this->m_orbitCenter.m_x = 0.0;
          this->m_orbitCenter.m_y = 0.0;
          this->m_orbitCenter.m_z = 0.0;
          this->m_state = 4;
        }
        else
        {
          this->m_reachedGoal = true;
          if ( m_state == 4 )
          {
            this->m_onFinalRotationAction.m_restartGotoPos = false;
            this->m_onFinalRotationAction.m_changeOrientMode = false;
          }
          this->m_orbitDirection = 0.0;
          this->m_orbitSpeed = 0.0;
          v47 = -1.0;
          this->m_orbitMinDist = -1.0;
          this->m_orbitCenter.m_x = 0.0;
          this->m_orbitCenter.m_y = 0.0;
          this->m_orbitCenter.m_z = 0.0;
          this->m_state = DONE_MOVING;
        }
        this->m_orbitPrevMinDist = v47;
        this->m_orbitDisable = false;
        this->m_orbitGoalDirection = 0.0;
        this->m_orbitRadius = 0.0;
      }
    }
  }
  bfx::WalkerImpl::CheckForGoalApproach(this, targetPosIsGoal: this->m_targetIsGoal, proximityDecel: false);
  v48 = this->m_state;
  if ( v48 == PATH_MOVE || v48 == 3 )
  {
    v49 = this->m_commonState;
    if ( v49->m_pTune->m_clientMotion )
    {
      p_m_clientSpecifiedVel = &this->m_clientSpecifiedVel;
    }
    else
    {
      p_m_clientSpecifiedVel = (const bfx::Vec3 *)&v69.m_flags.m_flags3;
      v51 = (float)(v69.m_pos.m_z + this->m_vel.m_z);
      v52 = (float)((float)(v69.m_pos.m_y + this->m_vel.m_y) * (float)0.5);
      *(float *)&v69.m_flags.m_flags3 = (float)(v69.m_pos.m_x + p_m_vel->m_x) * (float)0.5;
      *(float *)&v69.m_flags.m_flags4 = v52;
      v70 = (float)v51 * (float)0.5;
    }
    bfx::Surfer::Move(this: &v49->m_surfer, origVel: p_m_clientSpecifiedVel, time: simTime);
  }
  if ( this->m_state == 1 )
  {
    v53 = this->m_commonState;
    if ( v53->m_pTune->m_clientMotion && v53->m_clientMotionSkidTurnAllowed )
      bfx::Surfer::Move(this: &v53->m_surfer, origVel: &this->m_clientSpecifiedVel, time: simTime);
  }
  v54 = this->GetPos(this: &v69, result: this);
  bfx::SavedPositions::AddPosition(this: &this->m_savedPositions, newPos: v54);
  bfx::WalkerImpl::CheckForGoalApproach(this, targetPosIsGoal: this->m_targetIsGoal, proximityDecel: false);
  if ( this->m_state == PATH_MOVE )
  {
    if ( this->m_useStartupAccel )
    {
      v55 = (float)(this->m_startupAccelTimer + (float)simTime);
      this->m_startupAccelTimer = this->m_startupAccelTimer + (float)simTime;
      if ( __fsqrts((float)((float)(p_m_vel->m_x * p_m_vel->m_x)
                          + (float)((float)(this->m_vel.m_y * this->m_vel.m_y)
                                  + (float)(this->m_vel.m_z * this->m_vel.m_z)))) > (float)(bfx::WalkerImpl::GetDesSpeed(this)
                                                                                          * (float)0.80000001) )
        this->m_useStartupAccel = false;
      if ( v55 > 3.0 )
        this->m_useStartupAccel = false;
    }
    if ( this->m_firstFrameOfMovement )
      this->m_firstFrameOfMovement = false;
  }
  bfx::MotionState::SimulateProber(this: this->m_commonState, simTime);
  this->m_cornerCacheU.m_dirty = true;
  bfx::WalkerImpl::UpdateHeading(this, simTime);
  v56 = this->m_commonState;
  m_pProber = v56->m_pProber;
  if ( m_pProber != nullptr )
  {
    v58 = (bfx::Vec3 *)&v69;
    m_y_low = (char *)LODWORD(m_pProber->m_pos3DOffset.m_y);
    m_z_low = (bfx::HalfLink *)LODWORD(m_pProber->m_pos3DOffset.m_z);
    v69.m_pProxy = (bfx::AreaProxy *)LODWORD(m_pProber->m_pos3DOffset.m_x);
    v69.m_dynAreaData.m_data = m_y_low;
    v69.m_pFirstLink = m_z_low;
  }
  else
  {
    v58 = &bfx::ZERO_VEC;
  }
  v61 = (float)(v56->m_surfer.m_pos.m_x + v58->m_x);
  v62 = (float)(v56->m_surfer.m_pos.m_z + v58->m_z);
  this->m_pos3D.m_y = v56->m_surfer.m_pos.m_y + v58->m_y;
  this->m_pos3D.m_x = v61;
  this->m_pos3D.m_z = v62;
  v63 = this->GetPos(this: &v69.m_pos, result: this);
  m_clientAvgVelIsDirty = this->m_clientAvgVelIsDirty;
  this->m_distMoved = (float)__fsqrts((float)((float)((float)(v63->m_x - v71) * (float)(v63->m_x - v71))
                                            + (float)((float)((float)(v63->m_z - v73) * (float)(v63->m_z - v73))
                                                    + (float)((float)(v63->m_y - v72) * (float)(v63->m_y - v72)))))
                    + this->m_distMoved;
  if ( m_clientAvgVelIsDirty )
  {
    v65 = (float)(this->m_clientVelArray[1].m_y + this->m_clientVelArray[0].m_y);
    v66 = (float)(this->m_clientVelArray[1].m_z + this->m_clientVelArray[0].m_z);
    this->m_avgClientVel.m_x = (float)(this->m_clientVelArray[0].m_x + this->m_clientVelArray[1].m_x) * (float)0.5;
    this->m_avgClientVel.m_y = (float)v65 * (float)0.5;
    this->m_avgClientVel.m_z = (float)v66 * (float)0.5;
    this->m_clientAvgVelIsDirty = false;
  }
  m_pRepulsor = this->m_commonState->m_pRepulsor;
  if ( m_pRepulsor != nullptr )
    m_pRepulsor->m_steeringDecision = STEERING_DECISION_NONE_YET_THIS_FRAME;
  if ( simTime != 0.0 && this->m_cornersCountdown > 0.0 )
  {
    v68 = (float)(this->m_cornersCountdown - (float)simTime);
    this->m_cornersCountdown = this->m_cornersCountdown - (float)simTime;
    if ( v68 <= 0.0 )
    {
      BYTE1(v69.m_flags.m_flags1) = 0;
      this->m_cornersCountdown = 0.5;
      v69.m_searchCost = 1;
      *(float *)&v69.m_usageFlags = 3.4028235e38;
      HIBYTE(v69.m_flags.m_flags1) = 0;
      bfx::SmartPath::CalcNextNCorners(
        this: this->m_commonState->m_pSmartPath,
        calcCornersSpec: (bfx::CalcCornersSpec *)&v69.m_searchCost);
    }
  }
}


// ========================================================================
// ?Draw@WalkerImpl@bfx@@UBAXXZ
// EA  : 0x832D3FA8
// RVA : 0x012D3FA8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::WalkerImpl::Draw(bfx::WalkerImpl *this)
{
  bfx::UPath *m_pUPath; // r11
  bfx::Vec3 *v3; // r4
  bfx::Vec3 *v4; // r8
  bfx::Space *m_pSpace; // r3
  bfx::MotionState *m_commonState; // r9
  const bfx::Space *v7; // r29
  double v8; // fp31
  const bfx::Color *v9; // r5
  long double v10; // fp2
  bfx::UPath *v11; // r11
  bfx::Vec3 *v12; // r29
  bfx::MotionState *v13; // r10
  float *p_m_speed; // r11
  const bfx::Space *v15; // r3
  double v16; // fp4
  double v17; // fp2
  double v18; // fp1
  double v20; // fp4
  bfx::MotionState *v22; // r11
  bfx::WalkerForces *m_pDebugForces; // r10
  double m_x; // fp0
  float v25; // r7
  double m_y; // fp13
  float v27; // r9
  double m_z; // fp12
  const bfx::Space *v29; // r3
  double m_clientSpecifiedRotSpeed; // fp29
  double v31; // fp31
  double v32; // fp30
  bfx::WalkerForces *v33; // r11
  bfx::MotionState *v34; // r3
  double v35; // fp4
  double v36; // fp3
  bfx::WalkerForces *v37; // r11
  bfx::MotionState *v38; // r10
  double v39; // fp12
  double v40; // fp11
  const bfx::Space *v41; // r3
  bfx::WalkerForces *v42; // r11
  bfx::MotionState *v43; // r8
  double v44; // fp6
  double v45; // fp5
  const bfx::Space *v46; // r3
  bfx::WalkerForces *v47; // r11
  bfx::Space *v48; // r3
  double v49; // fp0
  double v50; // fp13
  bfx::WalkerForces *v51; // r11
  bfx::MotionState *v52; // r9
  double v53; // fp8
  double v54; // fp7
  const bfx::Space *v55; // r3
  bfx::WalkerForces *v56; // r11
  bfx::MotionState *v57; // r8
  double v58; // fp2
  double v59; // fp1
  const bfx::Space *v60; // r3
  bfx::WalkerForces *v61; // r11
  bfx::MotionState *v62; // r7
  double v63; // fp10
  double v64; // fp9
  const bfx::Space *v65; // r3
  bfx::WalkerForces *v66; // r11
  bfx::MotionState *v67; // r3
  double v68; // fp4
  double v69; // fp3
  bfx::MotionState *v70; // r11
  long double v71; // fp2
  bfx::Vec3 *p_m_orienter; // r4
  float *LocalUpAxis; // r3
  double v76; // fp4
  double v77; // fp3
  double v78; // fp12
  double v79; // fp11
  int m_size; // r11
  bfx::HedgehogSpine *m_data; // r30
  bfx::HedgehogSpine::Type m_type; // r11
  const bfx::Color *v83; // r6
  double v84; // fp0
  double v85; // fp13
  double v86; // fp12
  bfx::Space *v87; // r3
  bfx::MotionState *v88; // r11
  bfx::RepulsorImpl *m_pRepulsor; // r11
  bfx::AABB *m_pAABB; // r10
  float v91; // r8
  float v92; // r11
  float v93; // r27
  int v94; // r10
  int v95; // r30
  int v96; // r11
  int v97; // r11
  int v98; // r3
  bfx::RVODebugDrawInfo *v99; // r11
  int v100; // r10
  bfx::RVODebugDrawInfo *v101; // r30
  int v102; // r28
  bfx::Vec3 *CurU2G; // r3
  bfx::UPath *v104; // r11
  bfx::Matrix *v105; // r4
  bfx::HedgehogDebugDrawInfo *v106; // r30
  bfx::UPath *v107; // r11
  bfx::Vec3 *v108; // r29
  double radius; // fp30
  bfx::MotionState *v110; // r11
  double v111; // fp6
  double v112; // fp9
  double v113; // fp5
  const bfx::Space *v114; // r30
  const bfx::Color *v115; // r5
  double Scale; // fp1
  bfx::Space *v117; // r28
  double v118; // fp30
  const bfx::Color *v119; // r5
  double v120; // fp30
  double v121; // fp29
  double v122; // fp26
  double v123; // fp1
  double v124; // fp8
  double v125; // fp3
  bfx::Matrix *v126; // r30
  double v127; // fp1
  double v128; // fp6
  bfx::Vector3 **v129; // r8
  double v130; // fp4
  double v131; // fp0
  char v132; // r11
  bfx::Vec3 *v133; // r7
  double v134; // fp0
  double v135; // fp13
  double v136; // fp12
  bfx::Space *v137; // r3
  char v138; // r11
  bfx::Vec3 *v139; // r7
  double v140; // fp0
  double v141; // fp13
  double v142; // fp12
  bfx::Space *v143; // r3
  bfx::Vec3 *p_m_orbitCenter; // r30
  char v145; // r11
  double m_orbitRadius; // fp31
  bfx::Space *v147; // r31
  const bfx::Color *v148; // r5
  bfx::Orienter v149; // [sp+50h] [-330h] BYREF
  bfx::Vec3 v150; // [sp+120h] [-260h] BYREF
  bfx::Vec3 v151; // [sp+130h] [-250h] BYREF
  float v152; // [sp+13Ch] [-244h]
  float v153; // [sp+140h] [-240h]
  float v154; // [sp+144h] [-23Ch]
  bfx::Vec3 v155; // [sp+150h] [-230h] BYREF
  float v156; // [sp+15Ch] [-224h]
  float v157; // [sp+160h] [-220h]
  float v158; // [sp+164h] [-21Ch]
  bfx::Vec3 v159; // [sp+170h] [-210h] BYREF
  float v160; // [sp+17Ch] [-204h]
  float v161; // [sp+180h] [-200h]
  float v162; // [sp+184h] [-1FCh]
  bfx::Vec3 v163; // [sp+190h] [-1F0h] BYREF
  float v164; // [sp+19Ch] [-1E4h]
  float v165; // [sp+1A0h] [-1E0h]
  float v166; // [sp+1A4h] [-1DCh]
  bfx::Vec3 v167; // [sp+1B0h] [-1D0h] BYREF
  float v168; // [sp+1BCh] [-1C4h]
  float v169; // [sp+1C0h] [-1C0h]
  float v170; // [sp+1C4h] [-1BCh]
  bfx::Matrix v171; // [sp+1D0h] [-1B0h] BYREF
  bfx::Matrix v172; // [sp+210h] [-170h] BYREF
  char v173[32]; // [sp+250h] [-130h] BYREF
  float v174; // [sp+270h] [-110h]
  float v175; // [sp+274h] [-10Ch]
  float v176; // [sp+278h] [-108h]
  bfx::RVODebugDrawInfo v177; // [sp+290h] [-F0h] BYREF

  if ( bfx::g_drawMoverTargetPos )
  {
    m_pUPath = this->m_pUPath;
    if ( m_pUPath != nullptr )
      v3 = (bfx::Vec3 *)&m_pUPath->m_u2g[m_pUPath->m_curIdx];
    else
      v3 = (bfx::Vec3 *)&bfx::IDENTITY;
    bfx::Matrix::operator*(this: (bfx::Matrix *)&v149.m_curRot.m_data[8], result: v3, rhs: &this->m_targetPosU);
    v4 = this->GetPos(this: &v149, result: this);
    m_pSpace = this->m_commonState->m_pSpace;
    v163.m_x = v4->m_x;
    v163.m_y = v4->m_y;
    v163.m_z = v4->m_z;
    v164 = v149.m_curRot.m_data[8];
    v165 = v149.m_curRot.m_data[9];
    v166 = v149.m_curRot.m_data[10];
    bfx::DrawLineList(pSpace: m_pSpace, pVerts: &v163, numVerts: 2, color: &ColorYellow_28);
  }
  if ( (this->m_commonState->m_debugFlags & 0x100000) != 0 )
    bfx::WalkerImpl::DrawTurningRadius(this);
  if ( (this->m_commonState->m_debugFlags & 0x10000) != 0 )
  {
    bfx::WalkerImpl::GetSurferUPos(this: (bfx::WalkerImpl *)&v149.m_dir.m_z, result: (bfx::Vec3 *)this);
    bfx::DrawPath(
      pSpace: this->m_commonState->m_pSpace,
      pPath: &this->m_pUPath->m_unwrappedPath,
      color: &ColorYellow_28);
    m_commonState = this->m_commonState;
    v7 = m_commonState->m_pSpace;
    v8 = (float)((float)(m_commonState->m_pTune->m_radiusData.m_innerCushion
                       + m_commonState->m_pTune->m_radiusData.m_outerCushion)
               + m_commonState->m_pTune->m_radiusData.m_radius);
    v171 = bfx::IDENTITY;
    bfx::Matrix::Trans(this: &v171, offset: (const bfx::Vec3 *)&v149.m_dir.m_z);
    bfx::DrawCircle(pSpace: v7, mat: (bfx::Vec3 *)&v171, radius: v8, color: v9, a5: &ColorWhite_28);
    v11 = this->m_pUPath;
    if ( v11 != nullptr )
      v12 = (bfx::Vec3 *)&v11->m_g2u[v11->m_curIdx];
    else
      v12 = (bfx::Vec3 *)&bfx::IDENTITY;
    bfx::Orienter::GetForward(this: &v149, result: (bfx::Vec3 *)&this->m_commonState->m_orienter, a3: v10);
    bfx::Matrix::Rot(this: &v149.m_curRot, result: v12, rhs: (const bfx::Vec3 *)&v149);
    v13 = this->m_commonState;
    p_m_speed = &v13->m_pTune->m_speed;
    v15 = v13->m_pSpace;
    v16 = p_m_speed[4];
    v17 = p_m_speed[3];
    v18 = p_m_speed[2];
    v151.m_x = v149.m_dir.m_z;
    v151.m_y = v149.m_slerpStartRot.m_w;
    v151.m_z = v149.m_slerpStartRot.m_x;
    _FP8 = (float)((float)__fsqrts((float)((float)(v149.m_curRot.m_data[0] * v149.m_curRot.m_data[0])
                                         + (float)((float)(v149.m_curRot.m_data[1] * v149.m_curRot.m_data[1])
                                                 + (float)(v149.m_curRot.m_data[2] * v149.m_curRot.m_data[2]))))
                 - (float)1.0842022e-19);
    v20 = (float)((float)((float)v16 + (float)v17) + (float)v18);
    __asm { fsel      f5, f8, f7, f28 }
    v152 = (float)((float)(v149.m_curRot.m_data[0] * (float)_FP5) * (float)v20) + v149.m_dir.m_z;
    v154 = v149.m_slerpStartRot.m_x + (float)((float)(v149.m_curRot.m_data[2] * (float)_FP5) * (float)v20);
    v153 = v149.m_slerpStartRot.m_w + (float)((float)(v149.m_curRot.m_data[1] * (float)_FP5) * (float)v20);
    bfx::DrawLineList(pSpace: v15, pVerts: &v151, numVerts: 2, color: &ColorWhite_28);
  }
  v22 = this->m_commonState;
  if ( (v22->m_debugFlags & 0x20000) != 0 )
  {
    m_pDebugForces = this->m_pDebugForces;
    if ( m_pDebugForces != nullptr )
    {
      m_x = m_pDebugForces->m_crowdSteerAcc.m_x;
      v25 = v22->m_surfer.m_pos.m_x;
      m_y = m_pDebugForces->m_crowdSteerAcc.m_y;
      v27 = v22->m_surfer.m_pos.m_y;
      m_z = m_pDebugForces->m_crowdSteerAcc.m_z;
      v29 = v22->m_pSpace;
      v149.m_clientSpecifiedRotSpeed = v22->m_surfer.m_pos.m_z;
      m_clientSpecifiedRotSpeed = v149.m_clientSpecifiedRotSpeed;
      v149.m_headingVel = v25;
      v31 = v25;
      *(float *)&v149.m_accelMode = v27;
      v32 = v27;
      *(float *)&v149.m_pTune = (float)m_y + v27;
      *(float *)&v149.m_pSpace = v25 + (float)m_x;
      *(float *)&v149.m_state = (float)m_z + v149.m_clientSpecifiedRotSpeed;
      bfx::DrawLine(
        pSpace: v29,
        v0: (const bfx::Vec3 *)&v149.m_headingVel,
        v1: (const bfx::Vec3 *)&v149,
        color: &ColorYellow_28);
      v33 = this->m_pDebugForces;
      v34 = this->m_commonState;
      v35 = (float)(v33->m_crowdRepulseAcc.m_y + (float)v32);
      v36 = (float)(v33->m_crowdRepulseAcc.m_z + (float)m_clientSpecifiedRotSpeed);
      *(float *)&v149.m_pSpace = v33->m_crowdRepulseAcc.m_x + (float)v31;
      *(float *)&v149.m_pTune = v35;
      *(float *)&v149.m_state = v36;
      bfx::DrawLine(
        pSpace: v34->m_pSpace,
        v0: (const bfx::Vec3 *)&v149.m_headingVel,
        v1: (const bfx::Vec3 *)&v149,
        color: &ColorMagenta_28);
      v37 = this->m_pDebugForces;
      v38 = this->m_commonState;
      v39 = (float)(v37->m_crowdSlideAcc.m_y + (float)v32);
      v40 = (float)(v37->m_crowdSlideAcc.m_z + (float)m_clientSpecifiedRotSpeed);
      *(float *)&v149.m_pSpace = v37->m_crowdSlideAcc.m_x + (float)v31;
      *(float *)&v149.m_pTune = v39;
      v41 = v38->m_pSpace;
      *(float *)&v149.m_state = v40;
      bfx::DrawLine(
        pSpace: v41,
        v0: (const bfx::Vec3 *)&v149.m_headingVel,
        v1: (const bfx::Vec3 *)&v149,
        color: &ColorGreen_28);
      v42 = this->m_pDebugForces;
      v43 = this->m_commonState;
      v44 = (float)(v42->m_flockAcc.m_y + (float)v32);
      v45 = (float)(v42->m_flockAcc.m_z + (float)m_clientSpecifiedRotSpeed);
      *(float *)&v149.m_pSpace = (float)v31 + v42->m_flockAcc.m_x;
      *(float *)&v149.m_pTune = v44;
      v46 = v43->m_pSpace;
      *(float *)&v149.m_state = v45;
      bfx::DrawLine(
        pSpace: v46,
        v0: (const bfx::Vec3 *)&v149.m_headingVel,
        v1: (const bfx::Vec3 *)&v149,
        color: &ColorOrange_28);
      v47 = this->m_pDebugForces;
      v48 = this->m_commonState->m_pSpace;
      v49 = (float)(v47->m_pathAcc.m_y + (float)v32);
      v50 = (float)(v47->m_pathAcc.m_z + (float)m_clientSpecifiedRotSpeed);
      *(float *)&v149.m_pSpace = v47->m_pathAcc.m_x + (float)v31;
      *(float *)&v149.m_pTune = v49;
      *(float *)&v149.m_state = v50;
      bfx::DrawLine(
        pSpace: v48,
        v0: (const bfx::Vec3 *)&v149.m_headingVel,
        v1: (const bfx::Vec3 *)&v149,
        color: &ColorBlue_28);
      v51 = this->m_pDebugForces;
      v52 = this->m_commonState;
      v53 = (float)(v51->m_circularApproachAcc.m_y + (float)v32);
      v54 = (float)(v51->m_circularApproachAcc.m_z + (float)m_clientSpecifiedRotSpeed);
      *(float *)&v149.m_pSpace = v51->m_circularApproachAcc.m_x + (float)v31;
      *(float *)&v149.m_pTune = v53;
      v55 = v52->m_pSpace;
      *(float *)&v149.m_state = v54;
      bfx::DrawLine(
        pSpace: v55,
        v0: (const bfx::Vec3 *)&v149.m_headingVel,
        v1: (const bfx::Vec3 *)&v149,
        color: &ColorCyan_28);
      v56 = this->m_pDebugForces;
      v57 = this->m_commonState;
      v58 = (float)(v56->m_goalDecel.m_y + (float)v32);
      v59 = (float)(v56->m_goalDecel.m_z + (float)m_clientSpecifiedRotSpeed);
      *(float *)&v149.m_pSpace = (float)v31 + v56->m_goalDecel.m_x;
      *(float *)&v149.m_pTune = v58;
      v60 = v57->m_pSpace;
      *(float *)&v149.m_state = v59;
      bfx::DrawLine(
        pSpace: v60,
        v0: (const bfx::Vec3 *)&v149.m_headingVel,
        v1: (const bfx::Vec3 *)&v149,
        color: &ColorRed_28);
      v61 = this->m_pDebugForces;
      v62 = this->m_commonState;
      v63 = (float)(v61->m_maxDecel.m_y + (float)v32);
      v64 = (float)(v61->m_maxDecel.m_z + (float)m_clientSpecifiedRotSpeed);
      *(float *)&v149.m_pSpace = v61->m_maxDecel.m_x + (float)v31;
      *(float *)&v149.m_pTune = v63;
      v65 = v62->m_pSpace;
      *(float *)&v149.m_state = v64;
      bfx::DrawLine(
        pSpace: v65,
        v0: (const bfx::Vec3 *)&v149.m_headingVel,
        v1: (const bfx::Vec3 *)&v149,
        color: &ColorWhite_28);
      v66 = this->m_pDebugForces;
      v67 = this->m_commonState;
      v68 = (float)(v66->m_xforceAcc.m_y + (float)v32);
      v69 = (float)(v66->m_xforceAcc.m_z + (float)m_clientSpecifiedRotSpeed);
      *(float *)&v149.m_pSpace = (float)v31 + v66->m_xforceAcc.m_x;
      *(float *)&v149.m_pTune = v68;
      *(float *)&v149.m_state = v69;
      bfx::DrawLine(
        pSpace: v67->m_pSpace,
        v0: (const bfx::Vec3 *)&v149.m_headingVel,
        v1: (const bfx::Vec3 *)&v149,
        color: &ColorGray_28);
    }
  }
  v70 = this->m_commonState;
  if ( (v70->m_debugFlags & 0x40000) != 0 && this->m_rvoWedges.m_size != 0 )
  {
    bfx::Orienter::GetLocalUpAxis(
      this: (bfx::Orienter *)&v149.m_headingFrameMatrix.m_data[13],
      result: (bfx::Vec3 *)&v70->m_orienter);
    bfx::Orienter::GetForward(
      this: (bfx::Orienter *)&v149.m_headingFrameMatrix.m_data[1],
      result: (bfx::Vec3 *)&this->m_commonState->m_orienter,
      a3: v71);
    p_m_orienter = (bfx::Vec3 *)&this->m_commonState->m_orienter;
    _FP11 = (float)((float)__fsqrts((float)((float)((float)((float)(v149.m_headingFrameMatrix.m_data[3]
                                                                  * v149.m_headingFrameMatrix.m_data[14])
                                                          - (float)(v149.m_headingFrameMatrix.m_data[15]
                                                                  * v149.m_headingFrameMatrix.m_data[2]))
                                                  * (float)((float)(v149.m_headingFrameMatrix.m_data[3]
                                                                  * v149.m_headingFrameMatrix.m_data[14])
                                                          - (float)(v149.m_headingFrameMatrix.m_data[15]
                                                                  * v149.m_headingFrameMatrix.m_data[2])))
                                          + (float)((float)((float)((float)(v149.m_headingFrameMatrix.m_data[2]
                                                                          * v149.m_headingFrameMatrix.m_data[13])
                                                                  - (float)(v149.m_headingFrameMatrix.m_data[14]
                                                                          * v149.m_headingFrameMatrix.m_data[1]))
                                                          * (float)((float)(v149.m_headingFrameMatrix.m_data[2]
                                                                          * v149.m_headingFrameMatrix.m_data[13])
                                                                  - (float)(v149.m_headingFrameMatrix.m_data[14]
                                                                          * v149.m_headingFrameMatrix.m_data[1])))
                                                  + (float)((float)((float)(v149.m_headingFrameMatrix.m_data[15]
                                                                          * v149.m_headingFrameMatrix.m_data[1])
                                                                  - (float)(v149.m_headingFrameMatrix.m_data[3]
                                                                          * v149.m_headingFrameMatrix.m_data[13]))
                                                          * (float)((float)(v149.m_headingFrameMatrix.m_data[15]
                                                                          * v149.m_headingFrameMatrix.m_data[1])
                                                                  - (float)(v149.m_headingFrameMatrix.m_data[3]
                                                                          * v149.m_headingFrameMatrix.m_data[13]))))))
                  - 1.0842022e-19);
    __asm { fsel      f9, f11, f10, f28 }
    v150.m_x = (float)((float)(v149.m_headingFrameMatrix.m_data[3] * v149.m_headingFrameMatrix.m_data[14])
                     - (float)(v149.m_headingFrameMatrix.m_data[15] * v149.m_headingFrameMatrix.m_data[2]))
             * (float)_FP9;
    v150.m_y = (float)((float)(v149.m_headingFrameMatrix.m_data[15] * v149.m_headingFrameMatrix.m_data[1])
                     - (float)(v149.m_headingFrameMatrix.m_data[3] * v149.m_headingFrameMatrix.m_data[13]))
             * (float)_FP9;
    v150.m_z = (float)((float)(v149.m_headingFrameMatrix.m_data[2] * v149.m_headingFrameMatrix.m_data[13])
                     - (float)(v149.m_headingFrameMatrix.m_data[14] * v149.m_headingFrameMatrix.m_data[1]))
             * (float)_FP9;
    LocalUpAxis = (float *)bfx::Orienter::GetLocalUpAxis(this: &v149, result: p_m_orienter);
    v76 = this->m_pos3D.m_y;
    v77 = this->m_pos3D.m_z;
    v78 = (float)(LocalUpAxis[1] * (float)0.75);
    v79 = (float)(LocalUpAxis[2] * (float)0.75);
    v149.m_curRot.m_data[4] = (float)(*LocalUpAxis * (float)0.75) + this->m_pos3D.m_x;
    v149.m_curRot.m_data[5] = (float)v76 + (float)v78;
    v149.m_curRot.m_data[6] = (float)v77 + (float)v79;
    bfx::Matrix::Build(
      this: &v172,
      xAxis: (const bfx::Vec3 *)&v149.m_headingFrameMatrix.m_data[1],
      yAxis: &v150,
      zAxis: (const bfx::Vec3 *)&v149.m_headingFrameMatrix.m_data[13],
      trans: (const bfx::Vec3 *)&v149.m_curRot.m_data[4]);
    this->GetPos(this: (struct bfx::WalkerImpl *)&v149.m_headingFrameMatrix.m_data[5], result: (bfx::Vec3 *)this);
    bfx::DrawRVOWedges(
      rvoWedges: &this->m_rvoWedges,
      mat: (bfx::Vec3 *)&v172,
      pSpace: (bfx::Vector3 *)this->m_commonState->m_pSpace);
    m_size = this->m_hedgehog.m_size;
    v149.m_headingFrameMatrix.m_data[1] = v149.m_headingFrameMatrix.m_data[1] * (float)3.0;
    m_data = this->m_hedgehog.m_data;
    v149.m_headingFrameMatrix.m_data[2] = v149.m_headingFrameMatrix.m_data[2] * (float)3.0;
    v149.m_headingFrameMatrix.m_data[3] = v149.m_headingFrameMatrix.m_data[3] * (float)3.0;
    if ( m_data != &m_data[m_size] )
    {
      do
      {
        bfx::Quat::Quat(
          this: (bfx::Quat *)&v149,
          axis: (const bfx::Vec3 *)&v149.m_headingFrameMatrix.m_data[13],
          angle: m_data->m_angle);
        bfx::Quat::Apply(
          this: (bfx::Quat *)&v149.m_headingVel,
          result: (bfx::Quat *)&v149,
          v: (const bfx::Vec3 *)&v149.m_headingFrameMatrix.m_data[1]);
        m_type = m_data->m_type;
        v83 = &ColorRed_28;
        v84 = (float)(v172.m_data[12] + v149.m_headingVel);
        v85 = (float)(*(float *)&v149.m_accelMode + v172.m_data[13]);
        v86 = (float)(v149.m_clientSpecifiedRotSpeed + v172.m_data[14]);
        v149.m_headingVel = v172.m_data[12] + v149.m_headingVel;
        *(float *)&v149.m_accelMode = *(float *)&v149.m_accelMode + v172.m_data[13];
        v149.m_clientSpecifiedRotSpeed = v149.m_clientSpecifiedRotSpeed + v172.m_data[14];
        if ( m_type != BLOCKED )
          v83 = &ColorGreen_28;
        v87 = this->m_commonState->m_pSpace;
        v167.m_x = v172.m_data[12];
        v167.m_y = v172.m_data[13];
        v167.m_z = v172.m_data[14];
        v168 = v84;
        v169 = v85;
        v170 = v86;
        bfx::DrawLineList(pSpace: v87, pVerts: &v167, numVerts: 2, color: v83);
        ++m_data;
      }
      while ( m_data != &this->m_hedgehog.m_data[this->m_hedgehog.m_size] );
    }
  }
  v88 = this->m_commonState;
  if ( (v88->m_debugFlags & 0x80000) != 0 && this->m_rvoDebugData.m_size != 0 )
  {
    m_pRepulsor = v88->m_pRepulsor;
    if ( m_pRepulsor == nullptr )
      return;
    m_pAABB = m_pRepulsor->m_pAABB;
    v91 = *(float *)&m_pRepulsor->m_blockageFlags;
    v149.m_headingFrameMatrix.m_data[6] = 0.0;
    HIBYTE(v149.m_headingFrameMatrix.m_data[8]) = 1;
    LODWORD(v149.m_headingFrameMatrix.m_data[5]) = &m_pAABB->m_overlaps;
    v149.m_headingFrameMatrix.m_data[7] = v91;
    bfx::NearbyRepulsorCursor::AdvanceToNextRepulsorSatisfyingFilter(this: (bfx::NearbyRepulsorCursor *)&v149.m_headingFrameMatrix.m_data[5]);
    v92 = v149.m_headingFrameMatrix.m_data[5];
    v93 = v149.m_headingFrameMatrix.m_data[6];
    if ( SLODWORD(v149.m_headingFrameMatrix.m_data[6]) < *(_DWORD *)(LODWORD(v149.m_headingFrameMatrix.m_data[5]) + 4) )
    {
      v94 = 4 * LODWORD(v149.m_headingFrameMatrix.m_data[6]);
      do
      {
        v95 = *(_DWORD *)(*(_DWORD *)(v94 + *(_DWORD *)LODWORD(v92)) + 40);
        v96 = *(_DWORD *)(v95 + 84);
        if ( v96 != 0
          && *(_DWORD *)(v96 + 4) == 1
          && (*(int (__fastcall **)(_DWORD))(**(_DWORD **)(v95 + 84) + 4))(a1: *(_DWORD *)(v95 + 84)) != 0 )
        {
          v97 = *(_DWORD *)(v95 + 84);
          if ( v97 != 0 && *(_DWORD *)(v97 + 4) == 1 )
            v98 = (*(int (__fastcall **)(_DWORD))(**(_DWORD **)(v95 + 84) + 4))(a1: *(_DWORD *)(v95 + 84));
          else
            v98 = 0;
          if ( *(_BYTE *)(v98 + 316) != 0 )
          {
            v99 = this->m_rvoDebugData.m_data;
            v100 = this->m_rvoDebugData.m_size;
            v101 = v99;
            if ( v99 != &v99[v100] )
            {
              v102 = *(_DWORD *)(v98 + 312);
              while ( 1 )
              {
                v177 = *v101;
                if ( v102 == v177.m_yourID )
                  break;
                if ( ++v101 == &v99[v100] )
                  goto LABEL_41;
              }
              CurU2G = (bfx::Vec3 *)bfx::WalkerImpl::GetCurU2G(this);
              bfx::RVODebugDrawInfo::ApplyMatrixToAllPositions(this: &v177, mat: CurU2G);
              bfx::DrawRVODebugData(rvoDebugData: &v177, commonState: this->m_commonState);
            }
          }
        }
LABEL_41:
        LODWORD(v149.m_headingFrameMatrix.m_data[6]) = LODWORD(v93) + 1;
        bfx::NearbyRepulsorCursor::AdvanceToNextRepulsorSatisfyingFilter(this: (bfx::NearbyRepulsorCursor *)&v149.m_headingFrameMatrix.m_data[5]);
        v92 = v149.m_headingFrameMatrix.m_data[5];
        v93 = v149.m_headingFrameMatrix.m_data[6];
        v94 = 4 * LODWORD(v149.m_headingFrameMatrix.m_data[6]);
      }
      while ( SLODWORD(v149.m_headingFrameMatrix.m_data[6]) < *(_DWORD *)(LODWORD(v149.m_headingFrameMatrix.m_data[5])
                                                                        + 4) );
    }
    v104 = this->m_pUPath;
    if ( v104 != nullptr )
      v105 = &v104->m_u2g[v104->m_curIdx];
    else
      v105 = &bfx::IDENTITY;
    v171 = *v105;
    v106 = this->m_hedgehogDebugArray.m_data;
    if ( v106 != &v106[this->m_hedgehogDebugArray.m_size] )
    {
      do
        bfx::DrawHedgehogDebugData(debugData: v106++, commonState: this->m_commonState, pAdjustMat: (bfx::Vec3 *)&v171);
      while ( v106 != &this->m_hedgehogDebugArray.m_data[this->m_hedgehogDebugArray.m_size] );
    }
  }
  if ( bfx::g_drawWalkerOrbit )
  {
    v107 = this->m_pUPath;
    if ( v107 != nullptr )
      v108 = (bfx::Vec3 *)&v107->m_g2u[v107->m_curIdx];
    else
      v108 = (bfx::Vec3 *)&bfx::IDENTITY;
    if ( this->m_debugData.m_actualOrbit.radius != 0.0 )
    {
      radius = this->m_debugData.m_actualOrbit.radius;
      v110 = this->m_commonState;
      v111 = this->m_debugData.m_actualOrbit.vOldPos.m_y;
      v112 = (float)(this->m_debugData.m_actualOrbit.vSide.m_y * this->m_debugData.m_actualOrbit.radius);
      v113 = (float)(this->m_debugData.m_actualOrbit.vOldPos.m_z
                   + (float)(this->m_debugData.m_actualOrbit.vSide.m_z * this->m_debugData.m_actualOrbit.radius));
      v149.m_curRot.m_data[12] = (float)(this->m_debugData.m_actualOrbit.vSide.m_x
                                       * this->m_debugData.m_actualOrbit.radius)
                               + this->m_debugData.m_actualOrbit.vOldPos.m_x;
      v149.m_curRot.m_data[14] = v113;
      v149.m_curRot.m_data[13] = (float)v111 + (float)v112;
      v114 = v110->m_pSpace;
      v171 = bfx::IDENTITY;
      bfx::Matrix::Trans(this: &v171, offset: (const bfx::Vec3 *)&v149.m_curRot.m_data[12]);
      bfx::DrawCircle(pSpace: v114, mat: (bfx::Vec3 *)&v171, radius, color: v115, a5: &ColorPurple_28);
    }
    Scale = bfx::GetScale();
    v117 = this->m_commonState->m_pSpace;
    v118 = (float)((float)Scale * (float)0.1);
    v171 = bfx::IDENTITY;
    bfx::Matrix::Trans(this: &v171, offset: &this->m_targetPosU);
    bfx::DrawCircle(pSpace: v117, mat: (bfx::Vec3 *)&v171, radius: v118, color: v119, a5: &ColorRed_28);
    if ( this->m_gotoPosSpec.m_orientAtGoalEnable )
    {
      this->GetMatrix(this, a2: (bfx::Matrix *)v173);
      v120 = (float)(v174 * (float)0.050000001);
      v121 = (float)(v175 * (float)0.050000001);
      v122 = (float)(v176 * (float)0.050000001);
      v123 = bfx::GetScale();
      v124 = this->m_targetPosU.m_z;
      v125 = (float)(this->m_targetPosU.m_y + (float)((float)v121 * (float)v123));
      v149.m_headingFrameMatrix.m_data[9] = (float)((float)v120 * (float)v123) + this->m_targetPosU.m_x;
      v149.m_headingFrameMatrix.m_data[10] = v125;
      v149.m_headingFrameMatrix.m_data[11] = (float)v124 + (float)((float)v122 * (float)v123);
      v126 = bfx::Matrix::Rot(
               this: (bfx::Matrix *)&v149.m_headingFrameMatrix.m_data[5],
               result: v108,
               rhs: &this->m_goalData.m_goalDir);
      v127 = bfx::GetScale();
      v128 = (float)(v126->m_data[2] * (float)v127);
      v129 = (bfx::Vector3 **)this->m_commonState;
      v130 = (float)((float)(v126->m_data[1] * (float)v127) + v149.m_headingFrameMatrix.m_data[10]);
      v149.m_slerpStartRot.m_z = (float)(v126->m_data[0] * (float)v127) + v149.m_headingFrameMatrix.m_data[9];
      v149.m_slerpTimer = v130;
      v149.m_slerpDuration = (float)v128 + v149.m_headingFrameMatrix.m_data[11];
      bfx::DrawArrow(
        pSpace: *v129,
        startPos: (const bfx::Vec3 *)&v149.m_headingFrameMatrix.m_data[9],
        endPos: (const bfx::Vec3 *)&v149.m_slerpStartRot.m_z,
        color: &ColorYellow_28);
    }
    v131 = this->m_debugData.m_pos1.m_x;
    v149.m_targetPos.m_y = 0.0;
    v149.m_targetPos.m_z = 0.75;
    v149.m_dir.m_x = 0.0;
    v149.m_dir.m_y = 1.0;
    if ( v131 != 0.0 || this->m_debugData.m_pos1.m_y != 0.0 || (v132 = 1, this->m_debugData.m_pos1.m_z != 0.0) )
      v132 = 0;
    if ( v132 == 0 )
    {
      bfx::DrawAxes(pSpace: this->m_commonState->m_pSpace, pos: &this->m_debugData.m_pos1);
      v133 = this->GetPos(this: &v149.m_headingFrameMatrix.m_data[5], result: this);
      v134 = this->m_debugData.m_pos1.m_x;
      v135 = this->m_debugData.m_pos1.m_y;
      v136 = this->m_debugData.m_pos1.m_z;
      v137 = this->m_commonState->m_pSpace;
      v159.m_x = v133->m_x;
      v159.m_y = v133->m_y;
      v159.m_z = v133->m_z;
      v160 = v134;
      v161 = v135;
      v162 = v136;
      bfx::DrawLineList(pSpace: v137, pVerts: &v159, numVerts: 2, color: (const bfx::Color *)&v149.m_targetPos.m_y);
    }
    if ( this->m_debugData.m_pos2.m_x != 0.0
      || this->m_debugData.m_pos2.m_y != 0.0
      || (v138 = 1, this->m_debugData.m_pos2.m_z != 0.0) )
    {
      v138 = 0;
    }
    if ( v138 == 0 )
    {
      bfx::DrawAxes(pSpace: this->m_commonState->m_pSpace, pos: &this->m_debugData.m_pos2);
      v139 = this->GetPos(this: &v149.m_headingFrameMatrix.m_data[5], result: this);
      v140 = this->m_debugData.m_pos2.m_x;
      v141 = this->m_debugData.m_pos2.m_y;
      v142 = this->m_debugData.m_pos2.m_z;
      v143 = this->m_commonState->m_pSpace;
      v155.m_x = v139->m_x;
      v155.m_y = v139->m_y;
      v155.m_z = v139->m_z;
      v156 = v140;
      v157 = v141;
      v158 = v142;
      bfx::DrawLineList(pSpace: v143, pVerts: &v155, numVerts: 2, color: (const bfx::Color *)&v149.m_targetPos.m_y);
    }
    p_m_orbitCenter = &this->m_orbitCenter;
    if ( this->m_orbitCenter.m_x != 0.0 || this->m_orbitCenter.m_y != 0.0 || (v145 = 1, this->m_orbitCenter.m_z != 0.0) )
      v145 = 0;
    if ( v145 == 0 )
    {
      m_orbitRadius = this->m_orbitRadius;
      v147 = this->m_commonState->m_pSpace;
      v171 = bfx::IDENTITY;
      bfx::Matrix::Trans(this: &v171, offset: p_m_orbitCenter);
      bfx::DrawCircle(
        pSpace: v147,
        mat: (bfx::Vec3 *)&v171,
        radius: m_orbitRadius,
        color: v148,
        a5: (const bfx::Color *)&v149.m_targetPos.m_y);
    }
  }
}


// ========================================================================
// ?UpdateCachedCorners@CornerDataCache@bfx@@QAAHHPAVUPath@2@ABVLineSeg@2@ABVVec3@2@@Z
// EA  : 0x832D4CE0
// RVA : 0x012D4CE0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

int __fastcall bfx::CornerDataCache::UpdateCachedCorners(
        bfx::CornerDataCache *this,
        bfx::SurfaceCornerData *desiredNumCorners,
        bfx::UPath *pUPath,
        const bfx::LineSeg *goalSeg,
        bfx::Vec3 *upos)
{
  double Scale; // fp1
  bfx::Vec3 *v12; // r31
  double v13; // fp31
  bfx::Matrix *v14; // r25
  bfx::Matrix *v15; // r3
  float v16; // r5
  float v17; // r4
  float v18; // r3
  int m_size; // r10
  bfx::SurfaceCornerData *v20; // r8
  bfx::Vec3 *v21; // r5
  float v22; // r30
  float v23; // r28
  float v24; // r27
  int NextNCorners; // r3
  int v26; // r28
  float *p_m_z; // r31
  float *v28; // r30
  int i; // r27
  int v30; // r11
  int v31; // r10
  double v32; // fp13
  double v33; // fp12
  bfx::HandleProxy *v34; // r3
  bfx::PathCC v35; // [sp+50h] [-C0h] BYREF
  bfx::Matrix v36; // [sp+58h] [-B8h] BYREF
  float v37[2]; // [sp+A0h] [-70h] BYREF
  float v38[8]; // [sp+A8h] [-68h] BYREF

  if ( !this->m_dirty )
    return this->m_numCornersInCache;
  Scale = bfx::GetScale();
  v12 = (bfx::Vec3 *)&pUPath->m_u2g[pUPath->m_unwrappedPath.m_areas.m_size + 14];
  v13 = (float)((float)Scale * (float)0.1);
  v14 = bfx::Matrix::operator*(this: &v36, result: v12, rhs: &goalSeg->m_v1);
  v15 = bfx::Matrix::operator*(this: (bfx::Matrix *)&v36.m_data[4], result: v12, rhs: &goalSeg->m_v0);
  v16 = v15->m_data[0];
  v17 = v15->m_data[1];
  v18 = v15->m_data[2];
  m_size = pUPath->m_unwrappedPath.m_areas.m_size;
  v36.m_data[10] = v16;
  v36.m_data[11] = v17;
  v20 = desiredNumCorners;
  v36.m_data[12] = v18;
  v21 = upos;
  v22 = v14->m_data[0];
  v23 = v14->m_data[1];
  v24 = v14->m_data[2];
  v37[0] = 0.0;
  v37[1] = 0.0;
  LODWORD(v38[1]) = 4;
  v38[0] = 0.0;
  v38[2] = NAN;
  v38[3] = 0.0;
  LODWORD(v38[6]) = 4;
  v38[4] = 0.0;
  v38[7] = NAN;
  v38[5] = 0.0;
  v35.m_pPath = &pUPath->m_unwrappedPath;
  v35.m_i = m_size - 1;
  v36.m_data[13] = v22;
  v36.m_data[14] = v23;
  v36.m_data[15] = v24;
  NextNCorners = bfx::GetNextNCorners(
                   initialCC: &pUPath->m_curCC,
                   goalCC: &v35,
                   initialPos: v21,
                   goalSeg: (const bfx::LineSeg *)&v36.m_data[10],
                   maxShrinkDist: v13,
                   maxNumCorners: -1,
                   pCornersOutArray: v20,
                   a8: (int)v37);
  v26 = NextNCorners;
  this->m_numCornersInCache = NextNCorners;
  if ( NextNCorners > 0 )
  {
    p_m_z = &this->m_corners[0].m_cornerPos.m_z;
    v28 = v38;
    for ( i = NextNCorners; i != 0; --i )
    {
      v30 = *((_DWORD *)v28 + 1);
      v31 = *((_DWORD *)v28 + 2);
      v32 = *(v28 - 1);
      v33 = *v28;
      *(p_m_z - 2) = *(v28 - 2);
      p_m_z[4] = 0.0;
      *(p_m_z - 1) = v32;
      *p_m_z = v33;
      *((_DWORD *)p_m_z + 1) = v30;
      *((_DWORD *)p_m_z + 2) = v31;
      *((_BYTE *)p_m_z + 12) = (_cntlzw(v30 - 2) & 0x20) != 0;
      v34 = *((bfx::HandleProxy **)p_m_z + 5);
      if ( v34 != nullptr )
      {
        bfx::HandleProxy::RemRefToHandleProxy(this: v34);
        p_m_z[5] = 0.0;
      }
      bfx::Handle<bfx::Area>::operator=(
        this: (bfx::Handle<bfx::Area> *)p_m_z + 6,
        pArea: pUPath->m_origPath.m_areas.m_data[*((_DWORD *)p_m_z + 2)]);
      v28 += 5;
      p_m_z += 9;
    }
  }
  this->m_dirty = false;
  return v26;
}


// ========================================================================
// ??1WalkerImpl@bfx@@UAA@XZ
// EA  : 0x832D4FA0
// RVA : 0x012D4FA0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::WalkerImpl::~WalkerImpl(bfx::WalkerImpl *this)
{
  bfx::RepulsorImpl *m_pRepulsor; // r11
  bfx::MotionState *m_commonState; // r11
  const bfx::Vec3 *p_m_vec; // r4
  bfx::Orienter *p_m_orienter; // r3
  bfx::OrientMode m_mode; // r11
  bfx::UPath *m_pUPath; // r27
  bfx::Array<bfx::Area *> *p_m_recentShortcutCornerAreas; // r27
  char *m_data; // r4
  char *v10; // r4
  char *v11; // r4
  char *v12; // r4
  char *v13; // r4

  this->__vftable = (bfx::WalkerImpl_vtbl *)&bfx::WalkerImpl::`vftable';
  m_pRepulsor = this->m_commonState->m_pRepulsor;
  if ( m_pRepulsor != nullptr )
    m_pRepulsor->m_steeringDecision = STEERING_DECISION_NONE_YET_THIS_FRAME;
  m_commonState = this->m_commonState;
  p_m_vec = &m_commonState->m_orientCmd.m_vec;
  p_m_orienter = &m_commonState->m_orienter;
  m_mode = m_commonState->m_orientCmd.m_mode;
  if ( m_mode != ORIENT_IN_TRAVEL_DIR )
  {
    switch ( m_mode )
    {
      case ORIENT_STRICTLY_IN_TRAVEL_DIR:
        bfx::Orienter::FaceStrictlyInTravelDir(this: p_m_orienter);
        break;
      case ORIENT_TARGET:
        bfx::Orienter::FaceTarget(this: p_m_orienter, targetPos: p_m_vec);
        break;
      case ORIENT_IN_DIR:
        bfx::Orienter::FaceInDir(this: p_m_orienter, dir: p_m_vec);
        break;
      default:
        break;
    }
  }
  else
  {
    idThrowableFilter::InternalPostFilterItems(this: p_m_orienter);
  }
  m_pUPath = this->m_pUPath;
  if ( m_pUPath != nullptr )
  {
    bfx::UPath::~UPath(this: this->m_pUPath);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pUPath->m_pBuf);
  }
  this->m_pUPath = nullptr;
  p_m_recentShortcutCornerAreas = &this->m_recentShortcutCornerAreas;
  this->m_recentShortcutCornerAreas.m_size = 0;
  bfx::MemoryManager::Free(
    this: bfx::g_pCurInstance->m_pMemoryManager,
    ptr: (char *)this->m_recentShortcutCornerAreas.m_data);
  this->m_recentShortcutCornerAreas.m_data = nullptr;
  this->m_recentShortcutCornerAreas.m_cap = 0;
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_pDebugForces);
  this->m_pDebugForces = nullptr;
  m_data = (char *)this->m_hedgehogDebugArray.m_data;
  this->m_hedgehogDebugArray.m_size = 0;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_hedgehogDebugArray.m_data = nullptr;
  }
  this->m_hedgehogDebugArray.m_cap = 0;
  v10 = (char *)this->m_rvoDebugData.m_data;
  this->m_rvoDebugData.m_size = 0;
  if ( v10 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v10);
    this->m_rvoDebugData.m_data = nullptr;
  }
  this->m_rvoDebugData.m_cap = 0;
  v11 = (char *)this->m_hedgehog.m_data;
  this->m_hedgehog.m_size = 0;
  if ( v11 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v11);
    this->m_hedgehog.m_data = nullptr;
  }
  this->m_hedgehog.m_cap = 0;
  v12 = (char *)this->m_rvoWedges.m_data;
  this->m_rvoWedges.m_size = 0;
  if ( v12 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v12);
    this->m_rvoWedges.m_data = nullptr;
  }
  this->m_rvoWedges.m_cap = 0;
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_repRecs.m_pRecs);
  `eh vector destructor iterator'(
    ptr: &this->m_cornerCacheU,
    size: 0x24u,
    count: 2,
    pDtor: (void (__fastcall *)(void *))bfx::CornerDataInternal::~CornerDataInternal);
  v13 = (char *)p_m_recentShortcutCornerAreas->m_data;
  this->m_recentShortcutCornerAreas.m_size = 0;
  if ( v13 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v13);
    p_m_recentShortcutCornerAreas->m_data = nullptr;
  }
  this->m_recentShortcutCornerAreas.m_cap = 0;
  this->__vftable = (bfx::WalkerImpl_vtbl *)&bfx::MotionBase::`vftable';
}


// ========================================================================
// __unwind$46404
// EA  : 0x832D5180
// RVA : 0x012D5180
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void _unwind_46404()
{
  int v0; // r12

  bfx::Idle::~Idle(this: *(bfx::Walker **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$46405
// EA  : 0x832D51A8
// RVA : 0x012D51A8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void _unwind_46405()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                             + 80));
}


// ========================================================================
// __unwind$46406
// EA  : 0x832D51D4
// RVA : 0x012D51D4
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void _unwind_46406()
{
  int v0; // r12

  bfx::CornerDataCache::~CornerDataCache(this: (bfx::CornerDataCache *)(*(_DWORD *)(v0 - 144 + 164) + 172));
}


// ========================================================================
// __unwind$46407
// EA  : 0x832D5200
// RVA : 0x012D5200
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void _unwind_46407()
{
  int v0; // r12

  bfx::RepulsorsForRVO::~RepulsorsForRVO(this: (bfx::RepulsorsForRVO *)(*(_DWORD *)(v0 - 144 + 164) + 252));
}


// ========================================================================
// __unwind$46408
// EA  : 0x832D522C
// RVA : 0x012D522C
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void _unwind_46408()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                             + 560));
}


// ========================================================================
// __unwind$46409
// EA  : 0x832D5258
// RVA : 0x012D5258
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void _unwind_46409()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                             + 576));
}


// ========================================================================
// __unwind$46410
// EA  : 0x832D5284
// RVA : 0x012D5284
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void _unwind_46410()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                             + 672));
}


// ========================================================================
// __unwind$46411
// EA  : 0x832D52B0
// RVA : 0x012D52B0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void _unwind_46411()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                             + 688));
}


// ========================================================================
// ?GetPos@WalkerImpl@bfx@@UBA?AVVec3@2@XZ
// EA  : 0x832D52E0
// RVA : 0x012D52E0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

bfx::WalkerImpl *__fastcall bfx::WalkerImpl::GetPos(bfx::WalkerImpl *this, bfx::Vec3 *result)
{
  float m_x; // r10
  float m_y; // r9

  m_x = result[1].m_x;
  m_y = result[1].m_y;
  this->__vftable = (bfx::WalkerImpl_vtbl *)LODWORD(result->m_z);
  *(float *)&this->m_commonState = m_x;
  this->m_pos3D.m_x = m_y;
  return this;
}


// ========================================================================
// ?GetMatrix@WalkerImpl@bfx@@UBAXAAVMatrix@2@@Z
// EA  : 0x832D5300
// RVA : 0x012D5300
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::WalkerImpl::GetMatrix(bfx::WalkerImpl *this, bfx::Matrix *mat)
{
  bfx::Orienter::CalcMat(this: &this->m_commonState->m_orienter, pos: &this->m_pos3D, mat);
}


// ========================================================================
// ?ReachedGoal@WalkerImpl@bfx@@UBA_NXZ
// EA  : 0x832D5318
// RVA : 0x012D5318
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

BOOL __fastcall bfx::WalkerImpl::ReachedGoal(bfx::WalkerImpl *this)
{
  return this->m_reachedGoal;
}


// ========================================================================
// ?DoneMoving@WalkerImpl@bfx@@UBA_NXZ
// EA  : 0x832D5320
// RVA : 0x012D5320
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

BOOL __fastcall bfx::WalkerImpl::DoneMoving(bfx::WalkerImpl *this)
{
  return (_cntlzw(this->m_state) & 0x20) != 0;
}


// ========================================================================
// ?GetFlockID@WalkerImpl@bfx@@UBAIXZ
// EA  : 0x832D5330
// RVA : 0x012D5330
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

unsigned int __fastcall bfx::WalkerImpl::GetFlockID(bfx::WalkerImpl *this)
{
  return this->m_commonState->m_flockID;
}


// ========================================================================
// ?GetRepulsorType@WalkerImpl@bfx@@UBAHXZ
// EA  : 0x832D5340
// RVA : 0x012D5340
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

int __fastcall bfx::WalkerImpl::GetRepulsorType(bfx::WalkerImpl *this)
{
  return this->m_commonState->m_pTune->m_repulsorType;
}


// ========================================================================
// ?IsGoalInView@WalkerImpl@bfx@@UBA_NXZ
// EA  : 0x832D5350
// RVA : 0x012D5350
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

BOOL __fastcall bfx::WalkerImpl::IsGoalInView(bfx::WalkerImpl *this)
{
  return this->m_goalIsInSight;
}


// ========================================================================
// ?UpdateSmartPath@WalkerImpl@bfx@@UAAXABVVec3@2@PAVArea@2@@Z
// EA  : 0x832D5358
// RVA : 0x012D5358
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::WalkerImpl::UpdateSmartPath(bfx::WalkerImpl *this, const bfx::Vec3 *newPos, bfx::Area *pNewArea)
{
  bfx::SmartPath::SetStartData(this: this->m_commonState->m_pSmartPath, startPos: newPos, pStartArea: pNewArea);
}


// ========================================================================
// ?CalcTargetPos@WalkerImpl@bfx@@AAA_NPAVVec3@2@0PA_N@Z
// EA  : 0x832D5368
// RVA : 0x012D5368
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

int __fastcall bfx::WalkerImpl::CalcTargetPos(
        bfx::WalkerImpl *this,
        bfx::Vec3 *intermediateTargetPos,
        bfx::Vec3 *trueTargetPos,
        bool *pNextCornerIsGoalOutput)
{
  bfx::CornerDataCache *p_m_cornerCacheU; // r29
  bfx::Vec3 *SurferUPos; // r3
  float m_x; // r8
  float m_y; // r10
  bool m_isGoal; // r11
  double m_z; // fp12
  double v14; // fp13
  double v16; // fp12
  char v17; // r11
  float v18; // r10
  float v19; // r9
  double v20; // fp30
  double v21; // fp29
  double v22; // fp28
  bool v23; // r30
  bfx::Orbit *v24; // r11
  char *v25; // r10
  _DWORD *p_m_z; // r11
  int i; // ctr
  double v28; // fp3
  double v29; // fp12
  double v30; // fp4
  double v31; // fp7
  double v32; // fp9
  double v33; // fp6
  double v34; // fp5
  double v35; // fp29
  double v36; // fp27
  double v37; // fp24
  double v38; // fp25
  double v39; // fp13
  double v40; // fp28
  double v41; // fp12
  double v42; // fp9
  char v43; // r11
  char v44; // r11
  float v45; // [sp+50h] [-140h] BYREF
  float v46; // [sp+54h] [-13Ch]
  float v47; // [sp+58h] [-138h]
  bfx::Vec3 v48; // [sp+60h] [-130h] BYREF
  bfx::Vec3 v49; // [sp+70h] [-120h] BYREF
  bfx::Orbit v50; // [sp+80h] [-110h] BYREF
  bfx::Orbit v51; // [sp+A0h] [-F0h] BYREF
  char v52; // [sp+BCh] [-D4h] BYREF
  float v53; // [sp+C0h] [-D0h]
  float v54; // [sp+C4h] [-CCh]
  float v55; // [sp+C8h] [-C8h]
  float v56; // [sp+CCh] [-C4h]
  float v57; // [sp+E0h] [-B0h] BYREF
  float v58; // [sp+E4h] [-ACh]
  float v59; // [sp+E8h] [-A8h]
  float v60; // [sp+100h] [-90h]
  float v61; // [sp+104h] [-8Ch]
  float v62; // [sp+108h] [-88h]

  p_m_cornerCacheU = &this->m_cornerCacheU;
  SurferUPos = (bfx::Vec3 *)bfx::WalkerImpl::GetSurferUPos(this: (bfx::WalkerImpl *)&v45, result: (bfx::Vec3 *)this);
  bfx::CornerDataCache::UpdateCachedCorners(
    this: p_m_cornerCacheU,
    desiredNumCorners: (bfx::SurfaceCornerData *)2,
    pUPath: this->m_pUPath,
    goalSeg: &this->m_goalData.m_goalSeg,
    upos: SurferUPos);
  m_x = this->m_cornerCacheU.m_corners[0].m_cornerPos.m_x;
  m_y = this->m_cornerCacheU.m_corners[0].m_cornerPos.m_y;
  m_isGoal = this->m_cornerCacheU.m_corners[0].m_isGoal;
  v48.m_z = this->m_cornerCacheU.m_corners[0].m_cornerPos.m_z;
  m_z = v48.m_z;
  v48.m_x = m_x;
  v48.m_y = m_y;
  intermediateTargetPos->m_y = m_y;
  intermediateTargetPos->m_x = m_x;
  intermediateTargetPos->m_z = m_z;
  if ( trueTargetPos != nullptr )
  {
    trueTargetPos->m_x = m_x;
    trueTargetPos->m_y = m_y;
    trueTargetPos->m_z = m_z;
  }
  if ( pNextCornerIsGoalOutput != nullptr )
    *pNextCornerIsGoalOutput = m_isGoal;
  if ( m_isGoal && this->m_doPreGoalApproach )
  {
    bfx::WalkerImpl::CalcGoalApproachPos(this: (bfx::WalkerImpl *)&v45, result: (bfx::Matrix *)this, ugoalPos: &v48);
    v14 = v46;
    v16 = v47;
    intermediateTargetPos->m_x = v45;
    intermediateTargetPos->m_y = v14;
    intermediateTargetPos->m_z = v16;
    return 1;
  }
  else
  {
    if ( !this->m_doPreGoalApproach )
      return 0;
    if ( !this->m_commonState->m_pTune->m_goalTune.m_useCircularApproach
      || this->m_gotoPosSpec.m_stopAtGoal
      || !this->m_gotoPosSpec.m_orientAtGoalEnable
      || (v17 = 1, this->m_orbitDisable) )
    {
      v17 = 0;
    }
    if ( v17 == 0 || this->m_cornerCacheU.m_numCornersInCache != 2 || !this->m_cornerCacheU.m_corners[1].m_isGoal )
      return 0;
    v18 = this->m_cornerCacheU.m_corners[1].m_cornerPos.m_y;
    v19 = this->m_cornerCacheU.m_corners[1].m_cornerPos.m_z;
    v49.m_x = this->m_cornerCacheU.m_corners[1].m_cornerPos.m_x;
    v49.m_y = v18;
    v49.m_z = v19;
    bfx::WalkerImpl::CalcGoalURot(this: (bfx::WalkerImpl *)&v57, result: (bfx::Matrix *)this);
    bfx::WalkerImpl::GetSurferUPos(this: (bfx::WalkerImpl *)&v45, result: (bfx::Vec3 *)this);
    v20 = v45;
    v21 = v46;
    v22 = v47;
    v23 = (float)((float)(v60
                        * (float)((float)(v58 * (float)-(float)(v49.m_z - v47))
                                - (float)(v59 * (float)-(float)(v49.m_y - v46))))
                + (float)((float)((float)((float)(v59 * (float)-(float)(v49.m_x - v45))
                                        - (float)((float)-(float)(v49.m_z - v47) * v57))
                                * v61)
                        + (float)((float)((float)((float)-(float)(v49.m_y - v46) * v57)
                                        - (float)(v58 * (float)-(float)(v49.m_x - v45)))
                                * v62))) > 0.0;
    v50.m_center.m_x = 0.0;
    v50.m_center.m_y = 0.0;
    v50.m_center.m_z = 0.0;
    v50.m_radius = 0.0;
    v50.m_rotationAxis.m_x = 0.0;
    v50.m_rotationAxis.m_y = 0.0;
    v50.m_rotationAxis.m_z = 0.0;
    v51.m_center.m_x = 0.0;
    v51.m_center.m_y = 0.0;
    v51.m_center.m_z = 0.0;
    v51.m_radius = 0.0;
    v51.m_rotationAxis.m_x = 0.0;
    v51.m_rotationAxis.m_y = 0.0;
    v51.m_rotationAxis.m_z = 0.0;
    bfx::WalkerImpl::CalculateOrbits(this, ugoalPos: &v49, orbitLeft: &v50, orbitRight: &v51);
    v24 = &v50;
    if ( !v23 )
      v24 = &v51;
    v25 = &v52;
    p_m_z = (_DWORD *)&v24[-1].m_rotationAxis.m_z;
    for ( i = 7; i != 0; --i )
    {
      ++p_m_z;
      v25 += 4;
      *(_DWORD *)v25 = *p_m_z;
    }
    if ( (float)((float)((float)(v48.m_x - v53) * (float)(v48.m_x - v53))
               + (float)((float)((float)(v48.m_z - v55) * (float)(v48.m_z - v55))
                       + (float)((float)(v48.m_y - v54) * (float)(v48.m_y - v54)))) >= (double)(float)(v56 * v56) )
      return 0;
    bfx::WalkerImpl::CalcGoalApproachPos(this: (bfx::WalkerImpl *)&v45, result: (bfx::Matrix *)this, ugoalPos: &v49);
    v28 = (float)(v48.m_z - (float)v22);
    v29 = (float)(v49.m_y - (float)v21);
    v30 = (float)(v48.m_y - (float)v21);
    v31 = v46;
    v32 = (float)(v46 - (float)v21);
    v33 = v47;
    v34 = (float)(v47 - (float)v22);
    v36 = (float)((float)(v48.m_y - (float)v21) * (float)(v49.m_x - (float)v20));
    v37 = (float)((float)(v48.m_y - (float)v21) * (float)(v45 - (float)v20));
    v35 = (float)((float)(v48.m_z - (float)v22) * (float)(v49.m_y - (float)v21));
    v38 = (float)((float)(v47 - (float)v22) * (float)(v48.m_x - (float)v20));
    v39 = (float)(v49.m_z - (float)v22);
    v40 = (float)((float)(v48.m_z - (float)v22) * (float)v32);
    v41 = (float)((float)((float)v29 * (float)(v48.m_x - (float)v20)) - (float)v36);
    v42 = (float)((float)((float)v32 * (float)(v48.m_x - (float)v20)) - (float)v37);
    if ( (float)((float)((float)v30 * (float)v39) - (float)v35) != 0.0
      || (float)((float)((float)v28 * (float)(v49.m_x - (float)v20))
               - (float)((float)v39 * (float)(v48.m_x - (float)v20))) != 0.0
      || (v43 = 1, v41 != 0.0) )
    {
      v43 = 0;
    }
    if ( v43 != 0 )
      return 0;
    if ( (float)((float)((float)v30 * (float)v34) - (float)v40) != 0.0
      || (float)((float)((float)v28 * (float)(v45 - (float)v20)) - (float)v38) != 0.0
      || (v44 = 1, v42 != 0.0) )
    {
      v44 = 0;
    }
    if ( v44 == 0
      && (float)((float)((float)((float)((float)v30 * (float)v34) - (float)v40)
                       * (float)((float)((float)v30 * (float)v39) - (float)v35))
               + (float)((float)((float)v42 * (float)v41)
                       + (float)((float)((float)((float)v28 * (float)(v45 - (float)v20)) - (float)v38)
                               * (float)((float)((float)v28 * (float)(v49.m_x - (float)v20))
                                       - (float)((float)v39 * (float)(v48.m_x - (float)v20)))))) < 0.0 )
    {
      intermediateTargetPos->m_x = v45;
      intermediateTargetPos->m_y = v31;
      intermediateTargetPos->m_z = v33;
      return 1;
    }
    else
    {
      return 0;
    }
  }
}


// ========================================================================
// ?UpdateTargetPos@WalkerImpl@bfx@@AAAXXZ
// EA  : 0x832D5770
// RVA : 0x012D5770
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::WalkerImpl::UpdateTargetPos(bfx::WalkerImpl *this)
{
  int v2; // r29
  bool v3; // r11
  char v4; // r11
  char v5; // r3
  double m_z; // fp0
  double m_y; // fp13
  bool v8; // r11
  double m_x; // fp12
  double v10; // fp11
  double v11; // fp10
  double v12; // fp9
  double Scale; // fp1
  const bfx::Color *v14; // r5
  double v15; // fp1
  const bfx::Color *v16; // r5
  bool v17[8]; // [sp+50h] [-50h] BYREF
  bfx::Vec3 v18; // [sp+58h] [-48h] BYREF
  bfx::Vec3 v19; // [sp+68h] [-38h] BYREF

  v2 = (unsigned __int8)bfx::WalkerImpl::CalcTargetPos(
                          this,
                          intermediateTargetPos: &v19,
                          trueTargetPos: &v18,
                          pNextCornerIsGoalOutput: v17);
  if ( v2 != 0 )
  {
    if ( !this->m_commonState->m_pTune->m_goalTune.m_useCircularApproach
      || this->m_gotoPosSpec.m_stopAtGoal
      || !this->m_gotoPosSpec.m_orientAtGoalEnable
      || (v3 = true, this->m_orbitDisable) )
    {
      v3 = false;
    }
    if ( bfx::WalkerImpl::ShouldExitGoalApproach(
           this,
           ugoalPos: &v18,
           ugoalApproachPos: &v19,
           performRoundedCornering: v3) )
    {
      if ( !this->m_commonState->m_pTune->m_goalTune.m_useCircularApproach
        || this->m_gotoPosSpec.m_stopAtGoal
        || !this->m_gotoPosSpec.m_orientAtGoalEnable
        || (v4 = 1, this->m_orbitDisable) )
      {
        v4 = 0;
      }
      if ( v4 == 0
        || (this->m_orbitDisable = true,
            bfx::WalkerImpl::CalcTargetPos(
              this,
              intermediateTargetPos: &v19,
              trueTargetPos: &v18,
              pNextCornerIsGoalOutput: v17),
            v5 = bfx::WalkerImpl::PerformRoundedCornering(this),
            bfx::WalkerImpl::ShouldExitGoalApproach(
              this,
              ugoalPos: &v18,
              ugoalApproachPos: &v19,
              performRoundedCornering: v5)) )
      {
        this->m_doPreGoalApproach = false;
      }
    }
  }
  m_z = v18.m_z;
  m_y = v18.m_y;
  v8 = v17[0];
  m_x = v18.m_x;
  if ( this->m_doPreGoalApproach )
  {
    v10 = v19.m_x;
    this->m_targetIsGoal = false;
    v11 = v19.m_y;
    v12 = v19.m_z;
    this->m_targetPosU.m_x = v10;
    this->m_targetPosU.m_y = v11;
    this->m_targetPosU.m_z = v12;
  }
  else
  {
    this->m_targetIsGoal = v17[0];
    this->m_targetPosU.m_x = m_x;
    this->m_targetPosU.m_y = m_y;
    this->m_targetPosU.m_z = m_z;
  }
  this->m_goalIsInSight = v8;
  this->m_trueTargetPosU.m_x = m_x;
  this->m_trueTargetPosU.m_y = m_y;
  this->m_trueTargetPosU.m_z = m_z;
  if ( bfx::g_drawMoverGoalApproach )
  {
    Scale = bfx::GetScale();
    bfx::DrawBox(
      pSpace: this->m_commonState->m_pSpace,
      pos: &v18,
      r: (float)((float)Scale * (float)0.050000001),
      color: v14,
      a5: &ColorYellow_28);
    if ( v2 != 0 && this->m_doPreGoalApproach )
    {
      v15 = bfx::GetScale();
      bfx::DrawBox(
        pSpace: this->m_commonState->m_pSpace,
        pos: &v19,
        r: (float)((float)v15 * (float)0.050000001),
        color: v16,
        a5: &ColorRed_28);
    }
  }
}


// ========================================================================
// ?CalcAcc@WalkerImpl@bfx@@UAAXM@Z
// EA  : 0x832D5978
// RVA : 0x012D5978
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::WalkerImpl::CalcAcc(bfx::WalkerImpl *this, double simTime)
{
  bfx::FastArrayOfRepRecs *p_m_repRecs; // r26
  long double v5; // fp2
  bfx::UPath *m_pUPath; // r11
  bfx::Vec3 *v7; // r30
  bfx::Orienter *Forward; // r3
  bfx::RepRec *m_pRecs; // r30
  int v10; // r27
  int v11; // r28
  float *p_m_pRep; // r30
  int v13; // r11
  int v14; // r11
  int v15; // r9
  float *v16; // r11
  int v17; // r4
  int m_size; // r3
  double Scale; // fp1
  bfx::MotionState *m_commonState; // r9
  const bfx::MoverTune *m_pTune; // r30
  float v22; // r27
  float *UVel; // r22
  float *UPos; // r3
  bfx::MotionState *v25; // r8
  float m_outerCushion; // r6
  float m_innerCushion; // r5
  double m_origDetectRadius; // fp29
  double v29; // fp1
  bfx::Array<bfx::RVOWedge> *v30; // r7
  bfx::RepulsorsForRVO *v31; // r6
  __int64 v32; // r10
  __int64 v33; // r8
  __int64 v34; // r6
  __int64 v35; // r4
  unsigned __int8 v36; // r3
  long double v37; // fp2
  bfx::MotionState *v38; // r11
  bfx::MotionState::FollowData *p_m_followData; // r11
  bool v40; // r25
  bfx::HandleProxy *m_pProxy; // r10
  char v42; // r10
  float m_y; // r8
  float m_z; // r9
  bfx::WalkerImpl::State m_state; // r11
  int v46; // r28
  bfx::WalkerImpl *v47; // r3
  float *v48; // r3
  float *v49; // r3
  double v50; // fp0
  double v51; // fp13
  double v52; // fp27
  double v53; // fp29
  double v54; // fp26
  float *v55; // r3
  char v56; // r11
  float *v57; // r3
  double v58; // fp0
  bool v59; // mr_fpscr50
  double v60; // fp13
  double v61; // fp0
  unsigned __int8 v62; // r11
  bool v63; // r30
  float *v64; // r3
  float *v65; // r3
  bfx::MotionState *v66; // r11
  double v67; // fp9
  double v68; // fp7
  bfx::MotionState *v69; // r11
  float *v74; // r3
  float *v75; // r3
  float *v76; // r3
  bfx::WalkerImpl::State v77; // r11
  float *v78; // r3
  bfx::MotionState::FollowData *v79; // r3
  double v80; // fp0
  double v81; // fp13
  bfx::MotionState::FollowData *v82; // r11
  bfx::HandleProxy *v83; // r10
  char v84; // r11
  double m_x; // fp9
  double v86; // fp27
  double v87; // fp3
  double v88; // fp2
  bfx::Matrix *v89; // r3
  char *m_pDebugForces; // r4
  bfx::WalkerForces *v91; // r3
  bfx::WalkerForces *v92; // r3
  const bfx::Vec3 *v93; // [sp+8h] [-218h]
  const bfx::Vec3 *v94; // [sp+Ch] [-214h]
  const bfx::Vec3 *v95; // [sp+10h] [-210h]
  int v96; // [sp+14h] [-20Ch]
  int v97; // [sp+18h] [-208h]
  int v98; // [sp+1Ch] [-204h]
  int v99; // [sp+20h] [-200h]
  int v100; // [sp+24h] [-1FCh]
  int v101; // [sp+28h] [-1F8h]
  int v102; // [sp+2Ch] [-1F4h]
  int v103; // [sp+30h] [-1F0h]
  int v104; // [sp+34h] [-1ECh]
  int v105; // [sp+38h] [-1E8h]
  int v106; // [sp+3Ch] [-1E4h]
  int v107; // [sp+40h] [-1E0h]
  int v108; // [sp+44h] [-1DCh]
  int v109; // [sp+48h] [-1D8h]
  int v110; // [sp+4Ch] [-1D4h]
  int v111; // [sp+50h] [-1D0h]
  int v112; // [sp+58h] [-1C8h]
  int v113; // [sp+60h] [-1C0h]
  bfx::Vec3 v114; // [sp+78h] [-1A8h] BYREF
  bfx::Vec3 v115; // [sp+88h] [-198h] BYREF
  bfx::Vec3 v116; // [sp+98h] [-188h] BYREF
  bfx::Vec3 v117; // [sp+A8h] [-178h] BYREF
  bfx::Vec3 v118; // [sp+B8h] [-168h] BYREF
  bfx::Matrix v119; // [sp+C8h] [-158h] BYREF
  bfx::Array<bfx::RVODebugDrawInfo> v120; // [sp+108h] [-118h] BYREF
  bfx::Vec3 v121; // [sp+118h] [-108h] BYREF
  bfx::Orienter v122; // [sp+128h] [-F8h] BYREF

  if ( simTime != 0.0 )
  {
    bfx::WalkerImpl::UpdateUnwrappedPathIfNeeded(this, bForce: false);
    if ( this->m_pUPath != nullptr )
    {
      this->m_commonState->m_cautionData.m_internalSpeedX = 1.0;
      memset(Dst: &this->m_debugData, Val: 0, Size: sizeof(this->m_debugData));
      p_m_repRecs = &this->m_repRecs;
      bfx::WalkerImpl::GetRepRecs(this, repRecs: &this->m_repRecs);
      bfx::WalkerImpl::UpdateTargetPos(this);
      bfx::WalkerImpl::UpdateBlockageState(this, repRecs: &this->m_repRecs);
      if ( bfx::g_enableRVO )
      {
        bfx::Array<bfx::HoleRecord>::clear(this: (bfx::Array<bfx::QueuedTri> *)&this->m_hedgehog);
        m_pUPath = this->m_pUPath;
        if ( m_pUPath != nullptr )
          v7 = (bfx::Vec3 *)&m_pUPath->m_g2u[m_pUPath->m_curIdx];
        else
          v7 = (bfx::Vec3 *)&bfx::IDENTITY;
        Forward = bfx::Orienter::GetForward(this: &v122, result: (bfx::Vec3 *)&this->m_commonState->m_orienter, a3: v5);
        bfx::Matrix::Rot(
          this: (bfx::Matrix *)&v122.m_headingFrameMatrix.m_data[15],
          result: v7,
          rhs: (const bfx::Vec3 *)Forward);
        memset(&v120, 0, 12);
        m_pRecs = p_m_repRecs->m_pRecs;
        bfx::RepulsorsForRVO::Reserve(this: (bfx::RepulsorsForRVO *)&v120, count: this->m_repRecs.m_size);
        v10 = 0;
        if ( this->m_repRecs.m_size > 0 )
        {
          v11 = 0;
          p_m_pRep = (float *)&m_pRecs->m_pRep;
          do
          {
            v13 = *(_DWORD *)(*(_DWORD *)p_m_pRep + 84);
            if ( v13 != 0
              && *(_DWORD *)(v13 + 4) == 1
              && (*(int (__fastcall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)p_m_pRep + 84) + 4))(a1: *(_DWORD *)(*(_DWORD *)p_m_pRep + 84)) != 0 )
            {
              v14 = *(_DWORD *)(*(_DWORD *)p_m_pRep + 84);
              if ( v14 != 0 && *(_DWORD *)(v14 + 4) == 1 )
                v15 = *(_DWORD *)((*(int (__fastcall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)p_m_pRep + 84) + 4))(a1: *(_DWORD *)(*(_DWORD *)p_m_pRep + 84))
                                + 312);
              else
                v15 = MEMORY[0x138];
            }
            else
            {
              v15 = *(_DWORD *)(*(_DWORD *)p_m_pRep + 112);
            }
            v16 = (float *)((char *)&v120.m_data->m_yourID + v11);
            ++v10;
            *v16 = *(p_m_pRep - 9);
            v11 += 40;
            v16[1] = *(p_m_pRep - 8);
            v16[2] = *(p_m_pRep - 7);
            v16[3] = *(p_m_pRep - 6);
            v16[4] = *(p_m_pRep - 5);
            v16[5] = *(p_m_pRep - 4);
            v16[6] = *(p_m_pRep - 3);
            v16[7] = *(p_m_pRep - 2);
            v17 = *((_DWORD *)p_m_pRep - 1);
            p_m_pRep += 12;
            *((_DWORD *)v16 + 8) = v17;
            *((_DWORD *)v16 + 9) = v15;
            m_size = this->m_repRecs.m_size;
            ++v120.m_size;
          }
          while ( v10 < m_size );
        }
        Scale = bfx::GetScale();
        v122.m_headingVel = 0.0;
        *(float *)&v122.m_accelMode = 0.0;
        m_commonState = this->m_commonState;
        v122.m_clientSpecifiedRotSpeed = 1.0;
        v122.m_headingFrameMatrix.m_data[9] = (float)Scale * (float)0.25;
        v122.m_headingFrameMatrix.m_data[10] = v122.m_headingFrameMatrix.m_data[9] * (float)0.2;
        v122.m_headingFrameMatrix.m_data[11] = v122.m_headingFrameMatrix.m_data[10];
        m_pTune = m_commonState->m_pTune;
        v22 = *(float *)&m_commonState->m_replayID;
        UVel = (float *)bfx::WalkerImpl::GetUVel(this: (bfx::WalkerImpl *)&v122, result: (bfx::Vec3 *)this);
        UPos = (float *)bfx::WalkerImpl::GetUPos(this: (bfx::WalkerImpl *)&v119, result: (bfx::Vec3 *)this);
        v122.m_headingFrameMatrix.m_data[3] = *UPos;
        v25 = this->m_commonState;
        v122.m_headingFrameMatrix.m_data[4] = UPos[1];
        v122.m_headingFrameMatrix.m_data[5] = UPos[2];
        v122.m_headingFrameMatrix.m_data[6] = *UVel;
        v122.m_headingFrameMatrix.m_data[7] = UVel[1];
        v122.m_headingFrameMatrix.m_data[8] = UVel[2];
        m_outerCushion = m_pTune->m_radiusData.m_outerCushion;
        m_innerCushion = m_pTune->m_radiusData.m_innerCushion;
        v122.m_headingFrameMatrix.m_data[9] = m_pTune->m_radiusData.m_radius;
        v122.m_headingFrameMatrix.m_data[12] = v22;
        v122.m_headingFrameMatrix.m_data[10] = m_outerCushion;
        v122.m_headingFrameMatrix.m_data[11] = m_innerCushion;
        m_origDetectRadius = v25->m_pRepulsor->m_origDetectRadius;
        v29 = bfx::GetScale();
        bfx::CalcRVOs(
          pMyRVORec: (bfx::RVOEntityRecord *)&v122.m_headingFrameMatrix.m_data[3],
          myNorm: (const bfx::Vec3 *)&v122.m_headingVel,
          myForward: (const bfx::Vec3 *)&v122.m_headingFrameMatrix.m_data[15],
          radiusLimit: m_origDetectRadius,
          heightLimit: (float)((float)v29 * (float)3.0),
          repRecs: v31,
          wedges: v30,
          pRVODebugData: &v120,
          a9: (bfx::Array<bfx::ReplayLogListenerEntry> *)&this->m_rvoWedges,
          a10: (int)&this->m_rvoDebugData);
        if ( bfx::g_performRVOHedgehogTest && this->m_state != 3 )
        {
          v122.m_headingFrameMatrix.m_data[13] = v122.m_headingFrameMatrix.m_data[15];
          v122.m_headingFrameMatrix.m_data[14] = v122.m_targetPos.m_x;
          if ( bfx::FindHedgehogRVOMismatch(
                 pMyRepRec: (bfx::RVOEntityRecord *)&v122.m_headingFrameMatrix.m_data[3],
                 myUpVec: (const bfx::Vec3 *)&v122.m_headingVel,
                 myHeading: (bfx::Vec2 *)&v122.m_headingFrameMatrix.m_data[13],
                 repRecs: (const bfx::RepulsorsForRVO *)&v120,
                 wedges: &this->m_rvoWedges,
                 hedgehog: (bfx::Array<bfx::ReplayLogListenerEntry> *)&this->m_hedgehog,
                 hedgehogDebugArray: (bfx::Array<bfx::QueuedTri> *)&this->m_hedgehogDebugArray) )
          {
            LODWORD(v32) = &dword_82420000;
            HIDWORD(v35) = "Error: RVO-hedgehog mismatch when calculating RVOs for mover ID=%d\n";
            LODWORD(v35) = this->m_commonState->m_replayID;
            bfx::Print(fmt: v35, a2: v34, a3: v33, a4: v32, a5: (int)v93, a6: (int)v94, a7: (int)v95, a8: v96);
          }
        }
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v120.m_data);
      }
      v36 = bfx::WalkerImpl::CheckForProximityDecel(
              this,
              targetPosIsGoal: this->m_targetIsGoal,
              repRecs: &this->m_repRecs);
      v115.m_x = 0.0;
      v115.m_y = 0.0;
      v38 = this->m_commonState;
      v115.m_z = 0.0;
      v119.m_data[8] = 0.0;
      p_m_followData = &v38->m_followData;
      v119.m_data[9] = 0.0;
      v40 = v36;
      v119.m_data[10] = 0.0;
      v118.m_x = 0.0;
      v118.m_y = 0.0;
      v121.m_y = 0.0;
      v121.m_z = 0.0;
      v116.m_x = 0.0;
      v116.m_y = 0.0;
      v116.m_z = 0.0;
      v119.m_data[13] = 0.0;
      v119.m_data[14] = 0.0;
      v114.m_x = 0.0;
      v114.m_y = 0.0;
      v114.m_z = 0.0;
      v118.m_z = 0.0;
      v117.m_x = 0.0;
      v117.m_y = 0.0;
      v117.m_z = 0.0;
      v121.m_x = 0.0;
      v119.m_data[4] = 0.0;
      v119.m_data[5] = 0.0;
      v119.m_data[6] = 0.0;
      v119.m_data[12] = 0.0;
      m_pProxy = p_m_followData->m_targetMover.m_pProxy;
      if ( m_pProxy == nullptr
        || m_pProxy->m_pTarget == nullptr
        || (float)((float)(p_m_followData->m_externalForce.m_z * p_m_followData->m_externalForce.m_z)
                 + (float)((float)(p_m_followData->m_externalForce.m_x * p_m_followData->m_externalForce.m_x)
                         + (float)(p_m_followData->m_externalForce.m_y * p_m_followData->m_externalForce.m_y))) <= 0.0009765625
        || (v42 = 1, p_m_followData->m_sidePushCountdown <= 0.0) )
      {
        v42 = 0;
      }
      if ( v42 != 0 )
      {
        m_y = p_m_followData->m_externalForce.m_y;
        m_z = p_m_followData->m_externalForce.m_z;
        v122.m_pSpace = (bfx::Space *)LODWORD(p_m_followData->m_externalForce.m_x);
        *(float *)&v122.m_pTune = m_y;
        *(float *)&v122.m_state = m_z;
        v114.m_y = m_y;
        v114.m_x = *(float *)&v122.m_pSpace;
        v114.m_z = m_z;
      }
      m_state = this->m_state;
      if ( m_state == PATH_MOVE )
      {
        v46 = v36;
        if ( v36 == 0 )
        {
          if ( bfx::g_useRVOSteering )
            v47 = bfx::WalkerImpl::CalcRVOAcc(this: (bfx::WalkerImpl *)&v119, result: (bfx::Vec3 *)this, a3: v37);
          else
            v47 = bfx::WalkerImpl::CalcCrowdSteerAcc(
                    this: (bfx::WalkerImpl *)&v119,
                    result: (bfx::Vec3 *)this,
                    repRecs: &this->m_repRecs);
          v115 = *(bfx::Vec3 *)&v47->__vftable;
          v48 = (float *)bfx::WalkerImpl::CalcFlockAcc(
                           this: (bfx::WalkerImpl *)&v119,
                           result: (bfx::Vec3 *)this,
                           repRecs: &this->m_repRecs);
          v117.m_x = *v48;
          v117.m_y = v48[1];
          v117.m_z = v48[2];
        }
        bfx::WalkerImpl::SlowForCrowds(this, repRecs: &this->m_repRecs);
        v49 = (float *)bfx::WalkerImpl::CalcCrowdRepulseAcc(
                         this: (bfx::WalkerImpl *)&v119,
                         result: (bfx::Vec3 *)this,
                         repRecs: &this->m_repRecs,
                         computeSlideAcc: true,
                         slideAcc: &v118);
        v50 = *v49;
        v119.m_data[8] = *v49;
        v51 = v49[1];
        v119.m_data[9] = v49[1];
        v52 = (float)((float)((float)v51 * (float)v51)
                    + (float)((float)((float)v50 * (float)v50) + (float)(v49[2] * v49[2])));
        v119.m_data[10] = v49[2];
        v53 = bfx::GetScale();
        if ( v52 >= (float)((float)((float)v53 * bfx::GetScale()) * (float)0.0099999998)
          || (v54 = bfx::GetScale(),
              (float)((float)(v115.m_y * v115.m_y) + (float)((float)(v115.m_x * v115.m_x) + (float)(v115.m_z * v115.m_z))) >= (double)(float)((float)((float)v54 * bfx::GetScale()) * (float)0.0099999998)) )
        {
          this->m_orbitDirection = 0.0;
          this->m_orbitSpeed = 0.0;
          this->m_orbitMinDist = -1.0;
          this->m_orbitCenter.m_x = 0.0;
          this->m_orbitCenter.m_y = 0.0;
          this->m_orbitCenter.m_z = 0.0;
          this->m_orbitDisable = false;
          this->m_orbitRadius = 0.0;
          this->m_orbitGoalDirection = 0.0;
          this->m_orbitPrevMinDist = -1.0;
        }
        else
        {
          v55 = (float *)bfx::WalkerImpl::CalcCircularApproachAcc(
                           this: (bfx::WalkerImpl *)&v119,
                           result: (bfx::Vec3 *)this);
          v119.m_data[4] = *v55;
          v119.m_data[5] = v55[1];
          v119.m_data[6] = v55[2];
        }
        if ( v119.m_data[4] != 0.0 || v119.m_data[5] != 0.0 || (v56 = 1, v119.m_data[6] != 0.0) )
          v56 = 0;
        if ( v56 != 0 )
        {
          v57 = (float *)bfx::WalkerImpl::CalcGoalDecel(
                           this: (bfx::WalkerImpl *)&v119,
                           result: this,
                           targetPosIsGoal: this->m_targetIsGoal,
                           simTime);
          v58 = *v57;
          v121.m_x = *v57;
          v59 = v58 == 0.0;
          v60 = v57[1];
          v121.m_y = v57[1];
          v61 = v57[2];
          v121.m_z = v57[2];
          if ( !v59 || v60 != 0.0 || (v62 = 1, v61 != 0.0) )
            v62 = 0;
          v63 = (_cntlzw(v62) & 0x20) != 0;
          if ( (unsigned __int8)bfx::MotionState::FollowData::IsPushedToSide(this: &this->m_commonState->m_followData) == 0 )
          {
            v64 = (float *)bfx::WalkerImpl::CalcPathAcc(
                             this: (bfx::WalkerImpl *)&v119,
                             result: (bfx::Vec3 *)this,
                             targetPosIsGoal: this->m_targetIsGoal,
                             deceleratingTowardsGoal: v63,
                             proximityDecel: v40,
                             simTime);
            v116.m_x = *v64;
            v116.m_y = v64[1];
            v116.m_z = v64[2];
          }
        }
        if ( v46 != 0 )
        {
          v65 = (float *)bfx::WalkerImpl::CalcMaxDecel(
                           this: (bfx::WalkerImpl *)&v119,
                           result: (bfx::Vec3 *)this,
                           simTime);
          v119.m_data[12] = *v65;
          v119.m_data[13] = v65[1];
          v119.m_data[14] = v65[2];
        }
        v66 = this->m_commonState;
        v67 = (float)(v66->m_externalForce.m_z + v114.m_z);
        v68 = (float)(v66->m_externalForce.m_y + v114.m_y);
        v114.m_x = v66->m_externalForce.m_x + v114.m_x;
        v114.m_z = v67;
        v114.m_y = v68;
        if ( (unsigned __int8)bfx::MotionState::FollowData::IsMillingAround(this: &v66->m_followData) != 0 )
        {
          v69 = this->m_commonState;
          _FP8 = -(float)(v69->m_followData.m_millAroundCountdown * (float)0.66666669);
          _FP7 = (float)((float)1.0 - (float)(v69->m_followData.m_millAroundCountdown * (float)0.66666669));
          __asm { fsel      f6, f8, f0, f9 }
          __asm { fsel      f4, f7, f5, f30 }
          v116.m_x = (float)((float)1.0 - (float)_FP4) * v116.m_x;
          v116.m_y = v116.m_y * (float)((float)1.0 - (float)_FP4);
          v116.m_z = v116.m_z * (float)((float)1.0 - (float)_FP4);
        }
      }
      else if ( m_state == 3 )
      {
        if ( v36 == 0 )
        {
          v74 = (float *)bfx::WalkerImpl::CalcCrowdSteerAcc(
                           this: (bfx::WalkerImpl *)&v119,
                           result: (bfx::Vec3 *)this,
                           repRecs: &this->m_repRecs);
          v115.m_x = *v74;
          v115.m_y = v74[1];
          v115.m_z = v74[2];
          v75 = (float *)bfx::WalkerImpl::CalcFlockAcc(
                           this: (bfx::WalkerImpl *)&v122,
                           result: (bfx::Vec3 *)this,
                           repRecs: &this->m_repRecs);
          v117.m_x = *v75;
          v117.m_y = v75[1];
          v117.m_z = v75[2];
        }
        v76 = (float *)bfx::WalkerImpl::CalcCrowdRepulseAcc(
                         this: (bfx::WalkerImpl *)&v119,
                         result: (bfx::Vec3 *)this,
                         repRecs: &this->m_repRecs,
                         computeSlideAcc: false,
                         slideAcc: &v118);
        v119.m_data[8] = *v76;
        v77 = this->m_state;
        v119.m_data[9] = v76[1];
        v119.m_data[10] = v76[2];
        if ( v77 == 3 )
        {
          v78 = (float *)bfx::WalkerImpl::CalcMaxDecel(
                           this: (bfx::WalkerImpl *)&v119,
                           result: (bfx::Vec3 *)this,
                           simTime);
          v119.m_data[12] = *v78;
          v119.m_data[13] = v78[1];
          v119.m_data[14] = v78[2];
        }
        if ( (unsigned __int8)bfx::MotionState::FollowData::IsMillingAround(this: &this->m_commonState->m_followData) != 0 )
        {
          v79 = bfx::MotionState::FollowData::CalcMillingAroundForce(
                  this: (bfx::MotionState::FollowData *)&v119,
                  result: (bfx::Vec3 *)&this->m_commonState->m_followData);
          v80 = (float)(v79->m_bulkScale + v114.m_z);
          v81 = (float)(v79->m_sidePushCountdown + v114.m_y);
          v114.m_x = v79->m_millAroundCountdown + v114.m_x;
          v114.m_z = v80;
          v114.m_y = v81;
        }
      }
      if ( v40 )
      {
        v118.m_x = 0.0;
        v118.m_y = 0.0;
        v118.m_z = 0.0;
      }
      if ( this->m_useStartupAccel )
      {
        v117.m_x = 0.0;
        v117.m_y = 0.0;
        v117.m_z = 0.0;
      }
      v83 = this->m_commonState->m_followData.m_targetMover.m_pProxy;
      if ( v83 == nullptr
        || v83->m_pTarget == nullptr
        || (float)((float)((v82 = &this->m_commonState->m_followData)->m_externalForce.m_z * v82->m_externalForce.m_z)
                 + (float)((float)(v82->m_externalForce.m_x * v82->m_externalForce.m_x)
                         + (float)(v82->m_externalForce.m_y * v82->m_externalForce.m_y))) <= 0.0009765625
        || (v84 = 1, this->m_commonState->m_followData.m_sidePushCountdown <= 0.0) )
      {
        v84 = 0;
      }
      if ( v84 != 0 )
      {
        v118.m_x = 0.0;
        v118.m_y = 0.0;
        v118.m_z = 0.0;
      }
      m_x = v114.m_x;
      v86 = v114.m_z;
      v87 = (float)((float)((float)((float)((float)((float)((float)(v119.m_data[8] + v115.m_x) + v118.m_x) + v117.m_x)
                                          + v116.m_x)
                                  + v119.m_data[4])
                          + v121.m_x)
                  + v119.m_data[12]);
      v88 = (float)(v119.m_data[14]
                  + (float)(v121.m_z
                          + (float)(v119.m_data[6]
                                  + (float)(v116.m_z
                                          + (float)(v117.m_z + (float)(v118.m_z + (float)(v119.m_data[10] + v115.m_z)))))));
      this->m_acc.m_y = v114.m_y
                      + (float)(v119.m_data[13]
                              + (float)(v121.m_y
                                      + (float)(v119.m_data[5]
                                              + (float)(v116.m_y
                                                      + (float)(v117.m_y
                                                              + (float)(v118.m_y + (float)(v119.m_data[9] + v115.m_y)))))));
      this->m_acc.m_x = (float)v87 + (float)m_x;
      this->m_acc.m_z = (float)v86 + (float)v88;
      v89 = bfx::Matrix::Rot(
              this: &v119,
              result: (bfx::Vec3 *)&this->m_pUPath->m_u2g[this->m_pUPath->m_curIdx],
              rhs: &this->m_acc);
      this->m_acc.m_x = v89->m_data[0];
      this->m_acc.m_y = v89->m_data[1];
      this->m_acc.m_z = v89->m_data[2];
      if ( (this->m_commonState->m_debugFlags & 0x20000) != 0 )
      {
        m_pDebugForces = (char *)this->m_pDebugForces;
        if ( m_pDebugForces != nullptr )
          bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pDebugForces);
        v91 = (bfx::WalkerForces *)bfx::MemoryManager::Malloc(
                                     this: bfx::g_pCurInstance->m_pMemoryManager,
                                     size: 0x6Cu,
                                     tag: bfx::MEM_BFXMOVER);
        if ( v91 != nullptr )
          v92 = bfx::WalkerForces::WalkerForces(
                  this: v91,
                  matU2G: (bfx::Vec3 *)&this->m_pUPath->m_u2g[this->m_pUPath->m_curIdx],
                  crowdSteerAccU: &v115,
                  crowdRepulseAccU: (const bfx::Vec3 *)&v119.m_data[8],
                  crowdSlideAccU: &v118,
                  flockAccU: &v117,
                  pathAccU: &v116,
                  circularApproachAcc: (const bfx::Vec3 *)&v119.m_data[4],
                  goalDecelU: v93,
                  maxDecelU: v94,
                  xforceAccU: v95,
                  a12: v96,
                  a13: v97,
                  a14: v98,
                  a15: v99,
                  a16: v100,
                  a17: v101,
                  a18: v102,
                  a19: v103,
                  a20: v104,
                  a21: v105,
                  a22: v106,
                  a23: v107,
                  a24: v108,
                  a25: v109,
                  a26: v110,
                  a27: v111,
                  a28: &v121,
                  a29: v112,
                  a30: (const bfx::Vec3 *)&v119.m_data[12],
                  a31: v113,
                  a32: &v114);
        else
          v92 = nullptr;
        this->m_pDebugForces = v92;
      }
      bfx::WalkerImpl::CheckForGoalApproach(this, targetPosIsGoal: this->m_targetIsGoal, proximityDecel: v40);
      if ( p_m_repRecs->m_pRecs != nullptr )
      {
        memset(Dst: p_m_repRecs->m_pRecs, Val: 0, Size: 48 * this->m_repRecs.m_cap);
        this->m_repRecs.m_size = 0;
      }
    }
  }
}


// ========================================================================
// __unwind$46961
// EA  : 0x832D6558
// RVA : 0x012D6558
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void _unwind_46961()
{
  int v0; // r12

  bfx::RepulsorsForRVO::~RepulsorsForRVO(this: (bfx::RepulsorsForRVO *)(v0 - 544 + 264));
}


// ========================================================================
// __unwind$46962
// EA  : 0x832D6580
// RVA : 0x012D6580
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void _unwind_46962()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(char **)(v0 - 544 + 112), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ??0WalkerImpl@bfx@@QAA@ABVMatrix@1@AAVMotionState@1@@Z
// EA  : 0x832D65B8
// RVA : 0x012D65B8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

bfx::WalkerImpl *__fastcall bfx::WalkerImpl::WalkerImpl(
        bfx::WalkerImpl *this,
        const bfx::Matrix *mat,
        bfx::MotionState *commonState)
{
  bfx::bfxMemTag v5; // r11
  bfx::bfxMemTag v6; // r11
  bfx::bfxMemTag v7; // r11
  bfx::bfxMemTag v8; // r11
  double v9; // fp0
  double v10; // fp13
  double v11; // fp12
  bfx::MotionState *m_commonState; // r4
  bfx::RepulsorImpl *m_pRepulsor; // r10

  this->m_commonState = commonState;
  this->__vftable = (bfx::WalkerImpl_vtbl *)&bfx::WalkerImpl::`vftable';
  v5 = bfx::MEM_BFXMOVER;
  this->m_recentShortcutCornerAreas.m_data = nullptr;
  this->m_recentShortcutCornerAreas.m_size = 0;
  this->m_recentShortcutCornerAreas.m_cap = 0;
  this->m_recentShortcutCornerAreas.m_tag = v5;
  this->m_goalData.m_goalSeg.m_v0.m_x = 0.0;
  this->m_goalData.m_goalSeg.m_v0.m_y = 0.0;
  this->m_goalData.m_goalSeg.m_v0.m_z = 0.0;
  this->m_goalData.m_goalSeg.m_v1.m_x = 0.0;
  this->m_goalData.m_goalSeg.m_v1.m_y = 0.0;
  this->m_goalData.m_goalSeg.m_v1.m_z = 0.0;
  this->m_goalData.m_applyGoalDir = false;
  this->m_goalData.m_goalDir.m_x = 0.0;
  this->m_goalData.m_goalDir.m_y = 0.0;
  this->m_goalData.m_goalDir.m_z = 0.0;
  this->m_goalData.m_tinyStep = false;
  this->m_goalData.m_finalTurnInPlaceAngleThreshold = 180.0;
  bfx::GPSpec::GPSpec(this: &this->m_gotoPosSpec);
  `eh vector constructor iterator'(
    ptr: &this->m_cornerCacheU,
    size: 0x24u,
    count: 2,
    pCtor: (void (__fastcall *)(void *))bfx::CornerDataInternal::CornerDataInternal,
    pDtor: (void (__fastcall *)(void *))bfx::CornerDataInternal::~CornerDataInternal);
  this->m_cornerCacheU.m_numCornersInCache = 0;
  this->m_cornerCacheU.m_dirty = true;
  this->m_repRecs.m_pRecs = nullptr;
  this->m_repRecs.m_size = 0;
  this->m_repRecs.m_cap = 0;
  this->m_onStopAction.m_restartGotoPos = false;
  this->m_onStopAction.m_changeOrientMode = false;
  this->m_onFinalRotationAction.m_restartGotoPos = false;
  this->m_onFinalRotationAction.m_changeOrientMode = false;
  memset(Dst: &this->m_savedPositions, Val: 0, Size: 0x78u);
  this->m_savedPositions.m_numUsed = 0;
  this->m_savedPositions.m_latestIdx = -1;
  v6 = bfx::MEM_BFXMOVER;
  this->m_rvoWedges.m_data = nullptr;
  this->m_rvoWedges.m_size = 0;
  this->m_rvoWedges.m_cap = 0;
  this->m_rvoWedges.m_tag = v6;
  v7 = bfx::MEM_BFXMOVER;
  this->m_hedgehog.m_data = nullptr;
  this->m_hedgehog.m_size = 0;
  this->m_hedgehog.m_cap = 0;
  this->m_hedgehog.m_tag = v7;
  memset(Dst: &this->m_debugData, Val: 0, Size: sizeof(this->m_debugData));
  v8 = bfx::MEM_BFXMOVER;
  this->m_rvoDebugData.m_data = nullptr;
  this->m_rvoDebugData.m_size = 0;
  this->m_rvoDebugData.m_cap = 0;
  this->m_rvoDebugData.m_tag = v8;
  this->m_hedgehogDebugArray.m_tag = bfx::MEM_BFXMOVER;
  this->m_hedgehogDebugArray.m_data = nullptr;
  this->m_hedgehogDebugArray.m_size = 0;
  this->m_hedgehogDebugArray.m_cap = 0;
  v9 = mat->m_data[12];
  v10 = mat->m_data[14];
  v11 = mat->m_data[13];
  this->m_pos3D.m_y = mat->m_data[13];
  this->m_pos3D.m_z = v10;
  this->m_pos3D.m_x = v9;
  this->m_trueTargetPosU.m_x = v9;
  this->m_trueTargetPosU.m_y = v11;
  this->m_trueTargetPosU.m_z = v10;
  this->m_acc = bfx::ZERO_VEC;
  this->m_targetIsGoal = false;
  this->m_targetPosU = bfx::ZERO_VEC;
  this->m_goalIsInSight = false;
  this->m_trueTargetPosU = bfx::ZERO_VEC;
  this->m_pUPath = nullptr;
  this->m_startupAccelTimer = 0.0;
  this->m_smartPathTimeStampForUnwrappedPath = 0;
  this->m_reachedGoal = false;
  this->m_firstFrameOfMovement = true;
  this->m_useStartupAccel = false;
  this->m_doPreGoalApproach = false;
  this->m_clientSpecifiedVel = bfx::ZERO_VEC;
  m_commonState = this->m_commonState;
  this->m_disableUTurnMode = false;
  m_pRepulsor = m_commonState->m_pRepulsor;
  if ( m_pRepulsor != nullptr )
    m_pRepulsor->m_steeringDecision = STEERING_DECISION_NONE_YET_THIS_FRAME;
  this->m_clientAvgVelIsDirty = false;
  this->m_nextClientVelIndex = 0;
  this->m_clientVelArray[0] = bfx::ZERO_VEC;
  this->m_clientVelArray[1] = bfx::ZERO_VEC;
  this->m_avgClientVel = bfx::ZERO_VEC;
  this->m_distMoved = 0.0;
  this->m_cornersCountdown = 0.5;
  this->m_orbitDirection = 0.0;
  this->m_orbitSpeed = 0.0;
  this->m_orbitMinDist = -1.0;
  this->m_orbitCenter.m_x = 0.0;
  this->m_orbitCenter.m_y = 0.0;
  this->m_orbitCenter.m_z = 0.0;
  this->m_orbitDisable = false;
  this->m_orbitRadius = 0.0;
  this->m_pDebugForces = nullptr;
  this->m_orbitGoalDirection = 0.0;
  this->m_orbitPrevMinDist = -1.0;
  return this;
}


// ========================================================================
// __unwind$47527
// EA  : 0x832D6920
// RVA : 0x012D6920
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void _unwind_47527()
{
  int v0; // r12

  bfx::Idle::~Idle(this: *(bfx::Walker **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$47528
// EA  : 0x832D6948
// RVA : 0x012D6948
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void _unwind_47528()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 160 + 180)
                                                                                             + 80));
}


// ========================================================================
// ?MovedOntoArea@WalkerImpl@bfx@@UAAXABVVec3@2@PAVArea@2@010@Z
// EA  : 0x832D69D8
// RVA : 0x012D69D8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::WalkerImpl::MovedOntoArea(
        bfx::WalkerImpl *this,
        const bfx::Vec3 *oldPos,
        bfx::Area *pOldArea,
        const bfx::Vec3 *newPos,
        bfx::Area *pNewArea,
        const bfx::Vec3 *edgeVec)
{
  bfx::Prober *m_pProber; // r3
  bfx::Area *v12; // r27
  bfx::Area *v13; // r3
  bfx::MotionState *m_commonState; // r11
  bfx::Prober *v15; // r10
  bfx::Vec3 *v16; // r9
  char *m_y_low; // r7
  bfx::HalfLink *m_z_low; // r6
  double v19; // fp8
  double v20; // fp6
  int v21; // [sp+50h] [-70h] BYREF
  bfx::Area v22; // [sp+58h] [-68h] BYREF

  m_pProber = this->m_commonState->m_pProber;
  if ( m_pProber != nullptr )
    bfx::Prober::MovedOntoArea(this: m_pProber, oldPos, __formal: pOldArea, newPos, a5: pNewArea, a6: edgeVec);
  bfx::SmartPath::SetStartData(this: this->m_commonState->m_pSmartPath, startPos: newPos, pStartArea: pNewArea);
  bfx::SmartPath::GetPathAreas(this: this->m_commonState->m_pSmartPath, numAreasInFirstSurfaceSectionOut: &v21);
  bfx::WalkerImpl::UpdateUnwrappedPathIfNeeded(this, bForce: true);
  this->m_cornerCacheU.m_dirty = true;
  bfx::WalkerImpl::CalcTargetPos(
    this,
    intermediateTargetPos: &this->m_targetPosU,
    trueTargetPos: &this->m_trueTargetPosU,
    pNextCornerIsGoalOutput: nullptr);
  bfx::Orienter::MovedOntoArea(
    this: &this->m_commonState->m_orienter,
    (bfx::Vec3 *)pOldArea,
    (bfx::Vec3 *)pNewArea,
    edgeVec);
  v12 = bfx::Area::CalcNormal(this: &v22, result: (bfx::Vec3 *)pNewArea);
  v13 = bfx::Area::CalcNormal(this: (bfx::Area *)&v22.m_pos, result: (bfx::Vec3 *)pOldArea);
  this->m_vel = *bfx::RotateVecIntoNewArea(
                   result: (bfx::Vec3 *)&v22.m_searchCost,
                   vec: &this->m_vel,
                   edgeUnitVec: edgeVec,
                   oldAreaNormal: (const bfx::Vec3 *)v13,
                   newAreaNormal: (const bfx::Vec3 *)v12);
  m_commonState = this->m_commonState;
  v15 = m_commonState->m_pProber;
  if ( v15 != nullptr )
  {
    v16 = (bfx::Vec3 *)&v22;
    m_y_low = (char *)LODWORD(v15->m_pos3DOffset.m_y);
    m_z_low = (bfx::HalfLink *)LODWORD(v15->m_pos3DOffset.m_z);
    v22.m_pProxy = (bfx::AreaProxy *)LODWORD(v15->m_pos3DOffset.m_x);
    v22.m_dynAreaData.m_data = m_y_low;
    v22.m_pFirstLink = m_z_low;
  }
  else
  {
    v16 = &bfx::ZERO_VEC;
  }
  v19 = (float)(m_commonState->m_surfer.m_pos.m_y + v16->m_y);
  v20 = (float)(m_commonState->m_surfer.m_pos.m_z + v16->m_z);
  this->m_pos3D.m_x = v16->m_x + m_commonState->m_surfer.m_pos.m_x;
  this->m_pos3D.m_y = v19;
  this->m_pos3D.m_z = v20;
}


// ========================================================================
// ?GotoPos@WalkerImpl@bfx@@UAAXABVWalkerGoalData@2@ABVGPSpec@2@_N@Z
// EA  : 0x832D6B38
// RVA : 0x012D6B38
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __fastcall bfx::WalkerImpl::GotoPos(
        bfx::WalkerImpl *this,
        const bfx::WalkerGoalData *intermediateGoalData,
        const bfx::GPSpec *spec,
        bool forceUpdate)
{
  bfx::MotionState *m_commonState; // r10
  const bfx::MoverTune *m_pTune; // r22
  const bfx::Array<bfx::Area *> *PathAreas; // r3
  bfx::Vec3 *v10; // r27
  bfx::UPath *m_pUPath; // r27
  bool v12; // r11
  bfx::UPath *v13; // r11
  bfx::Vec3 *v14; // r4
  const bfx::Vec3 *v15; // r3
  double v16; // fp29
  bfx::MotionState *v17; // r8
  bfx::HandleProxy *m_pProxy; // r10
  char v19; // r11
  long double v20; // fp2
  double m_y; // fp13
  double m_z; // fp12
  float *Forward; // r3
  bfx::WalkerImpl::State m_state; // r11
  int v25; // r8
  const bfx::Vec3 *v26; // r3
  double m_x; // fp0
  double v28; // fp13
  double v29; // fp12
  bfx::MotionState *v30; // r11
  bfx::WalkerImpl::State v31; // r4
  bfx::Vec3 v32; // [sp+58h] [-148h] BYREF
  bfx::Vec3 v33; // [sp+68h] [-138h] BYREF
  bfx::Vec3 v34; // [sp+78h] [-128h] BYREF
  int v35; // [sp+84h] [-11Ch] BYREF
  bfx::CalcCornersSpec v36; // [sp+88h] [-118h] BYREF
  bfx::Orienter v37; // [sp+98h] [-108h] BYREF

  m_commonState = this->m_commonState;
  m_pTune = m_commonState->m_pTune;
  v36.m_addCornersAtEveryAreaBoundary = false;
  v36.m_addCornerAtStartingPosition = false;
  v36.m_maxPathDist = 3.4028235e38;
  v36.m_maxNumCorners = 1;
  this->m_cornersCountdown = 0.5;
  bfx::SmartPath::CalcNextNCorners(this: m_commonState->m_pSmartPath, calcCornersSpec: &v36);
  PathAreas = bfx::SmartPath::GetPathAreas(
                this: this->m_commonState->m_pSmartPath,
                numAreasInFirstSurfaceSectionOut: &v35);
  v10 = (bfx::Vec3 *)PathAreas->m_data[v35 - 1];
  this->m_goalData = *intermediateGoalData;
  this->m_goalData.m_goalSeg.m_v0 = *bfx::GetClosestPosInArea(
                                       result: &v34,
                                       pArea: v10,
                                       pos: &this->m_goalData.m_goalSeg.m_v0,
                                       pEdgeIndexOut: nullptr);
  this->m_goalData.m_goalSeg.m_v1 = *bfx::GetClosestPosInArea(
                                       result: (bfx::Vec3 *)&v37,
                                       pArea: v10,
                                       pos: &this->m_goalData.m_goalSeg.m_v1,
                                       pEdgeIndexOut: nullptr);
  this->m_gotoPosSpec = *spec;
  m_pUPath = this->m_pUPath;
  this->m_cornerCacheU.m_dirty = true;
  if ( m_pUPath != nullptr )
  {
    bfx::UPath::~UPath(this: m_pUPath);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pUPath->m_pBuf);
  }
  this->m_pUPath = nullptr;
  this->m_recentShortcutCornerAreas.m_size = 0;
  bfx::MemoryManager::Free(
    this: bfx::g_pCurInstance->m_pMemoryManager,
    ptr: (char *)this->m_recentShortcutCornerAreas.m_data);
  this->m_recentShortcutCornerAreas.m_data = nullptr;
  this->m_recentShortcutCornerAreas.m_cap = 0;
  this->GetPos(this: (struct bfx::WalkerImpl *)&v37.m_headingFrameMatrix.m_data[5], result: (bfx::Vec3 *)this);
  bfx::WalkerImpl::UpdateUnwrappedPathIfNeeded(this, bForce: true);
  if ( !intermediateGoalData->m_applyGoalDir || (v12 = true, spec->m_stopAtGoal) )
    v12 = false;
  this->m_doPreGoalApproach = v12;
  bfx::WalkerImpl::UpdateTargetPos(this);
  v13 = this->m_pUPath;
  if ( v13 != nullptr )
    v14 = (bfx::Vec3 *)&v13->m_u2g[v13->m_curIdx];
  else
    v14 = (bfx::Vec3 *)&bfx::IDENTITY;
  bfx::Matrix::operator*(this: (bfx::Matrix *)&v37.m_headingVel, result: v14, rhs: &this->m_targetPosU);
  v15 = this->GetPos(this: &v37, result: this);
  bfx::GetDesiredFacingVec(
    result: (bfx::Vec3 *)&v37.m_headingFrameMatrix.m_data[1],
    orientCmd: &this->m_commonState->m_orientCmd,
    pos: v15,
    nextCornerG: (const bfx::Vec3 *)&v37.m_headingVel);
  v16 = bfx::Orienter::CalcHeadingErrorFromDir(
          this: &this->m_commonState->m_orienter,
          desiredFacingVec: (const bfx::Vec3 *)&v37.m_headingFrameMatrix.m_data[1]);
  memset(&v34, 0, sizeof(v34));
  bfx::WalkerImpl::GetRepRecs(this, repRecs: (bfx::FastArrayOfRepRecs *)&v34);
  bfx::WalkerImpl::UpdateBlockageState(this, repRecs: (const bfx::FastArrayOfRepRecs *)&v34);
  v17 = this->m_commonState;
  m_pProxy = v17->m_followData.m_targetMover.m_pProxy;
  if ( m_pProxy == nullptr
    || m_pProxy->m_pTarget == nullptr
    || (float)((float)(v17->m_followData.m_externalForce.m_z * v17->m_followData.m_externalForce.m_z)
             + (float)((float)(v17->m_followData.m_externalForce.m_x * v17->m_followData.m_externalForce.m_x)
                     + (float)(v17->m_followData.m_externalForce.m_y * v17->m_followData.m_externalForce.m_y))) <= 0.0009765625
    || (v19 = 1, v17->m_followData.m_sidePushCountdown <= 0.0) )
  {
    v19 = 0;
  }
  if ( v19 != 0 )
  {
    if ( this->m_state != PATH_MOVE )
    {
LABEL_38:
      v31 = PATH_MOVE;
LABEL_39:
      bfx::WalkerImpl::SwitchState(this, newState: v31);
    }
  }
  else if ( intermediateGoalData->m_tinyStep )
  {
    bfx::WalkerImpl::SwitchState(this, newState: PATH_MOVE);
    if ( spec->m_orientAtGoalEnable )
    {
      m_y = spec->m_orientAtGoalDir.m_y;
      m_z = spec->m_orientAtGoalDir.m_z;
      v32.m_x = spec->m_orientAtGoalDir.m_x;
      v32.m_y = m_y;
    }
    else
    {
      Forward = (float *)bfx::Orienter::GetForward(
                           this: &v37,
                           result: (bfx::Vec3 *)&this->m_commonState->m_orienter,
                           a3: v20);
      v32.m_x = *Forward;
      v32.m_y = Forward[1];
      m_z = Forward[2];
    }
    v32.m_z = m_z;
    bfx::Orienter::FaceInDir(this: &this->m_commonState->m_orienter, dir: &v32);
  }
  else
  {
    m_state = this->m_state;
    if ( (unsigned int)m_state < PATH_MOVE || m_state == 4 )
    {
      if ( bfx::WalkerImpl::UseTurnInPlace(this) )
      {
        v31 = 1;
        if ( __fabs(v16) > (float)(m_pTune->m_turnInPlace.m_whenStoppedAngle * (float)0.017453292) )
          goto LABEL_39;
      }
      goto LABEL_38;
    }
    if ( m_state == PATH_MOVE || m_state == 3 )
    {
      if ( !bfx::WalkerImpl::UseTurnInPlace(this)
        || __fabs(v16) <= (float)(m_pTune->m_turnInPlace.m_whenMovingAngle * (float)0.017453292) )
      {
        goto LABEL_38;
      }
      this->m_onStopAction.m_restartGotoPos = true;
      if ( *(_DWORD *)(v25 + 112) <= 1u )
      {
        if ( (unsigned __int8)bfx::WalkerImpl::PerformRoundedCornering(this) != 0 )
        {
          m_x = this->m_goalData.m_goalDir.m_x;
          v28 = this->m_goalData.m_goalDir.m_y;
          v29 = this->m_goalData.m_goalDir.m_z;
        }
        else
        {
          v26 = this->GetPos(this: &v37, result: this);
          bfx::Orienter::CalcMat(
            this: &this->m_commonState->m_orienter,
            pos: v26,
            mat: (bfx::Matrix *)&v37.m_headingFrameMatrix.m_data[11]);
          m_x = v37.m_headingFrameMatrix.m_data[11];
          v28 = v37.m_headingFrameMatrix.m_data[12];
          v29 = v37.m_headingFrameMatrix.m_data[13];
        }
        v33.m_z = v29;
        v30 = this->m_commonState;
        v33.m_y = v28;
        v33.m_x = m_x;
        bfx::Orienter::FaceInDir(this: &v30->m_orienter, dir: &v33);
      }
      if ( this->m_state == 4 )
      {
        this->m_onFinalRotationAction.m_restartGotoPos = false;
        this->m_onFinalRotationAction.m_changeOrientMode = false;
      }
      this->m_orbitDirection = 0.0;
      this->m_orbitSpeed = 0.0;
      this->m_orbitMinDist = -1.0;
      this->m_orbitCenter.m_x = 0.0;
      this->m_orbitCenter.m_y = 0.0;
      this->m_orbitCenter.m_z = 0.0;
      this->m_orbitDisable = false;
      this->m_orbitRadius = 0.0;
      this->m_state = 3;
      this->m_orbitGoalDirection = 0.0;
      this->m_orbitPrevMinDist = -1.0;
    }
  }
  this->m_orbitDirection = 0.0;
  this->m_orbitSpeed = 0.0;
  this->m_orbitMinDist = -1.0;
  this->m_orbitCenter.m_x = 0.0;
  this->m_orbitCenter.m_y = 0.0;
  this->m_orbitCenter.m_z = 0.0;
  this->m_orbitDisable = false;
  this->m_orbitRadius = 0.0;
  this->m_reachedGoal = false;
  this->m_orbitGoalDirection = 0.0;
  this->m_orbitPrevMinDist = -1.0;
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)LODWORD(v34.m_x));
}


// ========================================================================
// __unwind$47918
// EA  : 0x832D7124
// RVA : 0x012D7124
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void _unwind_47918()
{
  int v0; // r12

  bfx::RepulsorsForRVO::~RepulsorsForRVO(this: (bfx::RepulsorsForRVO *)(v0 - 416 + 120));
}


// ========================================================================
// ?CreateWalker@bfx@@YAPAVWalker@1@ABVMatrix@1@AAVMotionState@1@@Z
// EA  : 0x832D7158
// RVA : 0x012D7158
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

bfx::WalkerImpl *__fastcall bfx::CreateWalker(const bfx::Matrix *mat, bfx::MotionState *commonState)
{
  bfx::WalkerImpl *v4; // r3

  v4 = (bfx::WalkerImpl *)bfx::MemoryManager::Malloc(
                            this: bfx::g_pCurInstance->m_pMemoryManager,
                            size: 0x2C0u,
                            tag: bfx::MEM_BFXMOVER);
  if ( v4 != nullptr )
    return bfx::WalkerImpl::WalkerImpl(this: v4, mat, commonState);
  else
    return nullptr;
}


// ========================================================================
// __unwind$48228
// EA  : 0x832D71B4
// RVA : 0x012D71B4
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void _unwind_48228()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(char **)(v0 - 128 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// bfx::`dynamic initializer for 'g_drawMoverTargetPosRestore''
// EA  : 0x83399518
// RVA : 0x01399518
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_drawMoverTargetPosRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_drawMoverTargetPosRestore);
  bfx::g_drawMoverTargetPosRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_drawMoverTargetPosRestore.m_targetBool = &bfx::g_drawMoverTargetPos;
  bfx::g_drawMoverTargetPosRestore.m_name = "mover_target_pos";
  bfx::g_drawMoverTargetPosRestore.m_defaultBool = bfx::g_drawMoverTargetPos;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_drawMoverTargetPosRestore__);
}


// ========================================================================
// bfx::`dynamic initializer for 'g_drawMoverDetourRestore''
// EA  : 0x83399590
// RVA : 0x01399590
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_drawMoverDetourRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_drawMoverDetourRestore);
  bfx::g_drawMoverDetourRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_drawMoverDetourRestore.m_targetBool = &bfx::g_drawMoverDetour;
  bfx::g_drawMoverDetourRestore.m_name = "mover_detour";
  bfx::g_drawMoverDetourRestore.m_defaultBool = bfx::g_drawMoverDetour;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_drawMoverDetourRestore__);
}


// ========================================================================
// bfx::`dynamic initializer for 'g_drawMoverGoalApproachRestore''
// EA  : 0x83399608
// RVA : 0x01399608
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_drawMoverGoalApproachRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_drawMoverGoalApproachRestore);
  bfx::g_drawMoverGoalApproachRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_drawMoverGoalApproachRestore.m_targetBool = &bfx::g_drawMoverGoalApproach;
  bfx::g_drawMoverGoalApproachRestore.m_name = "goal_approach";
  bfx::g_drawMoverGoalApproachRestore.m_defaultBool = bfx::g_drawMoverGoalApproach;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_drawMoverGoalApproachRestore__);
}


// ========================================================================
// bfx::`dynamic initializer for 'g_drawWalkerSpeedsRestore''
// EA  : 0x83399680
// RVA : 0x01399680
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_drawWalkerSpeedsRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_drawWalkerSpeedsRestore);
  bfx::g_drawWalkerSpeedsRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_drawWalkerSpeedsRestore.m_targetBool = &bfx::g_drawWalkerSpeeds;
  bfx::g_drawWalkerSpeedsRestore.m_name = "draw_walker_speeds";
  bfx::g_drawWalkerSpeedsRestore.m_defaultBool = bfx::g_drawWalkerSpeeds;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_drawWalkerSpeedsRestore__);
}


// ========================================================================
// bfx::`dynamic initializer for 'g_drawWalkerOrbitRestore''
// EA  : 0x833996F8
// RVA : 0x013996F8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_drawWalkerOrbitRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_drawWalkerOrbitRestore);
  bfx::g_drawWalkerOrbitRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_drawWalkerOrbitRestore.m_targetBool = &bfx::g_drawWalkerOrbit;
  bfx::g_drawWalkerOrbitRestore.m_name = "draw_walker_orbit";
  bfx::g_drawWalkerOrbitRestore.m_defaultBool = bfx::g_drawWalkerOrbit;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_drawWalkerOrbitRestore__);
}


// ========================================================================
// bfx::`dynamic initializer for 'g_enableRVORestore''
// EA  : 0x83399770
// RVA : 0x01399770
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_enableRVORestore__()
{
  bfx::Setting::Setting(this: &bfx::g_enableRVORestore);
  bfx::g_enableRVORestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_enableRVORestore.m_targetBool = &bfx::g_enableRVO;
  bfx::g_enableRVORestore.m_name = "enable_rvo_calculations";
  bfx::g_enableRVORestore.m_defaultBool = bfx::g_enableRVO;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_enableRVORestore__);
}


// ========================================================================
// bfx::`dynamic initializer for 'g_useRVOSteeringRestore''
// EA  : 0x833997E8
// RVA : 0x013997E8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_useRVOSteeringRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_useRVOSteeringRestore);
  bfx::g_useRVOSteeringRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_useRVOSteeringRestore.m_targetBool = &bfx::g_useRVOSteering;
  bfx::g_useRVOSteeringRestore.m_name = "use_rvo_steering";
  bfx::g_useRVOSteeringRestore.m_defaultBool = bfx::g_useRVOSteering;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_useRVOSteeringRestore__);
}


// ========================================================================
// bfx::`dynamic initializer for 'g_performRVOHedgehogTestRestore''
// EA  : 0x83399860
// RVA : 0x01399860
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxwalker.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_performRVOHedgehogTestRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_performRVOHedgehogTestRestore);
  bfx::g_performRVOHedgehogTestRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_performRVOHedgehogTestRestore.m_targetBool = &bfx::g_performRVOHedgehogTest;
  bfx::g_performRVOHedgehogTestRestore.m_name = "perform_rvo_hedgehog_test";
  bfx::g_performRVOHedgehogTestRestore.m_defaultBool = bfx::g_performRVOHedgehogTest;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_performRVOHedgehogTestRestore__);
}

