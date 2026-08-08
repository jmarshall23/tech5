
// ========================================================================
// ?IsIdle@IdleImpl@bfx@@UBA_NPAVIdleData@2@@Z
// EA  : 0x832D71F0
// RVA : 0x012D71F0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

int __fastcall bfx::IdleImpl::IsIdle(bfx::IdleImpl *this, bfx::IdleData *pDataOut)
{
  bfx::Matrix *v3; // r3
  float v4; // r8
  float v5; // r7
  char v7; // [sp+60h] [-20h] BYREF

  if ( pDataOut != nullptr )
  {
    v3 = bfx::Matrix::operator*(
           this: (bfx::Matrix *)&v7,
           result: (bfx::Vec3 *)&this->m_commonState->m_pSpace->m_matSpaceToWorld,
           rhs: &this->m_startPos);
    v4 = v3->m_data[0];
    v5 = v3->m_data[1];
    pDataOut->m_idlePos.m_z = v3->m_data[2];
    pDataOut->m_idlePos.m_y = v5;
    pDataOut->m_idlePos.m_x = v4;
  }
  return 1;
}


// ========================================================================
// ?OkToMoveOntoArea@IdleImpl@bfx@@UBA_NPAVArea@2@@Z
// EA  : 0x832D7270
// RVA : 0x012D7270
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

int __fastcall bfx::IdleImpl::OkToMoveOntoArea(bfx::IdleImpl *this, bfx::Area *pArea)
{
  bfx::Walker *m_pWalker; // r10

  m_pWalker = this->m_pWalker;
  if ( m_pWalker != nullptr )
    return ((bool (*)(void))m_pWalker->OkToMoveOntoArea)();
  else
    return bfx::OkToMoveOntoArea(pArea, pTune: this->m_commonState->m_pTune);
}


// ========================================================================
// ?MovedOntoArea@IdleImpl@bfx@@UAAXABVVec3@2@PAVArea@2@010@Z
// EA  : 0x832D72A8
// RVA : 0x012D72A8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

void __fastcall bfx::IdleImpl::MovedOntoArea(
        bfx::IdleImpl *this,
        const bfx::Vec3 *oldPos,
        bfx::Vec3 *pOldArea,
        const bfx::Vec3 *newPos,
        bfx::Vec3 *pNewArea,
        const bfx::Vec3 *edgeVec)
{
  bfx::Walker *m_pWalker; // r11
  bfx::Prober *m_pProber; // r3
  bfx::Area *v14; // r27
  bfx::Area *v15; // r3
  bfx::Area v16[2]; // [sp+50h] [-70h] BYREF

  m_pWalker = this->m_pWalker;
  if ( m_pWalker != nullptr )
  {
    ((void (*)(void))m_pWalker->MovedOntoArea)();
  }
  else
  {
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
    v14 = bfx::Area::CalcNormal(this: v16, result: pNewArea);
    v15 = bfx::Area::CalcNormal(this: (bfx::Area *)&v16[0].m_pos, result: pOldArea);
    this->m_vel = *bfx::RotateVecIntoNewArea(
                     result: (bfx::Vec3 *)&v16[0].m_searchCost,
                     vec: &this->m_vel,
                     edgeUnitVec: edgeVec,
                     oldAreaNormal: (const bfx::Vec3 *)v15,
                     newAreaNormal: (const bfx::Vec3 *)v14);
  }
}


// ========================================================================
// ?OnEdge@IdleImpl@bfx@@UAAXABVVec3@2@@Z
// EA  : 0x832D7390
// RVA : 0x012D7390
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

void __fastcall bfx::IdleImpl::OnEdge(bfx::IdleImpl *this, const bfx::Vec3 *outwardEdgeNormal)
{
  double m_z; // fp0
  double m_y; // fp13
  double v4; // fp3
  double v5; // fp2

  m_z = this->m_vel.m_z;
  m_y = this->m_vel.m_y;
  if ( (float)((float)((float)(this->m_vel.m_y * outwardEdgeNormal->m_y)
                     + (float)(this->m_vel.m_z * outwardEdgeNormal->m_z))
             + (float)(this->m_vel.m_x * outwardEdgeNormal->m_x)) > 0.0 )
  {
    v4 = (float)(outwardEdgeNormal->m_y
               * (float)((float)((float)(this->m_vel.m_y * outwardEdgeNormal->m_y)
                               + (float)(this->m_vel.m_z * outwardEdgeNormal->m_z))
                       + (float)(this->m_vel.m_x * outwardEdgeNormal->m_x)));
    v5 = (float)(outwardEdgeNormal->m_z
               * (float)((float)((float)(this->m_vel.m_y * outwardEdgeNormal->m_y)
                               + (float)(this->m_vel.m_z * outwardEdgeNormal->m_z))
                       + (float)(this->m_vel.m_x * outwardEdgeNormal->m_x)));
    this->m_vel.m_x = this->m_vel.m_x
                    - (float)(outwardEdgeNormal->m_x
                            * (float)((float)((float)(this->m_vel.m_y * outwardEdgeNormal->m_y)
                                            + (float)(this->m_vel.m_z * outwardEdgeNormal->m_z))
                                    + (float)(this->m_vel.m_x * outwardEdgeNormal->m_x)));
    this->m_vel.m_y = (float)m_y - (float)v4;
    this->m_vel.m_z = (float)m_z - (float)v5;
  }
}


// ========================================================================
// ?CalcMaxDecel@IdleImpl@bfx@@AAA?AVVec3@2@XZ
// EA  : 0x832D7408
// RVA : 0x012D7408
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

bfx::IdleImpl *__fastcall bfx::IdleImpl::CalcMaxDecel(bfx::IdleImpl *this, bfx::Vec3 *result)
{
  float m_y; // r8
  float m_z; // r7
  float m_x; // r9
  float v7; // r6
  bfx::IdleImpl::State v8; // r5

  if ( result[5].m_x > 0.1 || result[5].m_z < 1.0 )
  {
    m_x = result[1].m_x;
    _FP0 = (float)((float)__fsqrts((float)((float)(result[2].m_z * result[2].m_z)
                                         + (float)((float)(result[2].m_x * result[2].m_x)
                                                 + (float)(result[2].m_y * result[2].m_y))))
                 - 1.0842022e-19);
    __asm { fsel      f12, f0, f13, f12 }
    v7 = (float)(result[2].m_x * (float)_FP12) * (float)(*(float *)(LODWORD(m_x) + 28) * (float)-1.0);
    *(float *)&v8 = (float)(*(float *)(LODWORD(m_x) + 28) * (float)-1.0) * (float)(result[2].m_y * (float)_FP12);
    *(float *)&this->m_commonState = (float)(result[2].m_z * (float)_FP12)
                                   * (float)(*(float *)(LODWORD(m_x) + 28) * (float)-1.0);
    this->m_state = v8;
    *(float *)&this->__vftable = v7;
  }
  else
  {
    m_y = bfx::ZERO_VEC.m_y;
    m_z = bfx::ZERO_VEC.m_z;
    this->__vftable = (bfx::IdleImpl_vtbl *)LODWORD(bfx::ZERO_VEC.m_x);
    *(float *)&this->m_state = m_y;
    *(float *)&this->m_commonState = m_z;
  }
  return this;
}


// ========================================================================
// ?GetDesiredVel@IdleImpl@bfx@@UBA?AVVec3@2@XZ
// EA  : 0x832D74F0
// RVA : 0x012D74F0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

bfx::IdleImpl *__fastcall bfx::IdleImpl::GetDesiredVel(bfx::IdleImpl *this, bfx::Vec3 *result)
{
  float m_z; // r11
  bfx::IdleImpl *v3; // r31

  m_z = result[1].m_z;
  v3 = this;
  if ( m_z == 0.0 )
  {
    this->__vftable = (bfx::IdleImpl_vtbl *)LODWORD(result[2].m_x);
    this->m_state = LODWORD(result[2].m_y);
    this->m_commonState = (bfx::MotionState *)LODWORD(result[2].m_z);
  }
  else
  {
    (*(void (**)(void))(*(_DWORD *)LODWORD(m_z) + 56))();
    return v3;
  }
  return this;
}


// ========================================================================
// ?ApplyClientMotion@IdleImpl@bfx@@UAAXABVVec3@2@@Z
// EA  : 0x832D7568
// RVA : 0x012D7568
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

void __fastcall bfx::IdleImpl::ApplyClientMotion(bfx::IdleImpl *this, const bfx::Vec3 *vel)
{
  bfx::Walker *m_pWalker; // r11

  m_pWalker = this->m_pWalker;
  if ( m_pWalker != nullptr )
    ((void (*)(void))m_pWalker->ApplyClientMotion)();
  else
    this->m_clientSpecifiedVel = *vel;
}


// ========================================================================
// ?GetInitialConstraint@IdleImpl@bfx@@UAAXAAVInitialConstraint@2@@Z
// EA  : 0x832D75A8
// RVA : 0x012D75A8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

void __fastcall bfx::IdleImpl::GetInitialConstraint(bfx::IdleImpl *this, bfx::InitialConstraint *initialConstraint)
{
  bfx::Walker *m_pWalker; // r11

  m_pWalker = this->m_pWalker;
  if ( m_pWalker != nullptr )
  {
    ((void (*)(void))m_pWalker->GetInitialConstraint)();
  }
  else if ( this->m_pTune->m_idleTune.m_tetherDist > 0.0 )
  {
    initialConstraint->m_constraintType = CONSTRAINT_NONE;
  }
}


// ========================================================================
// ?UpdateOrienterAndProber@IdleImpl@bfx@@AAAXM@Z
// EA  : 0x832D75F0
// RVA : 0x012D75F0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

void __fastcall bfx::IdleImpl::UpdateOrienterAndProber(bfx::IdleImpl *this, double simTime)
{
  bfx::MotionState *m_commonState; // r11
  long double v5; // fp2
  long double v6; // fp4
  const bfx::Vec3 *v7; // r6
  bfx::Vec3 v8; // [sp+50h] [-80h] BYREF
  bfx::Vec3 v9; // [sp+60h] [-70h] BYREF
  float v10; // [sp+70h] [-60h] BYREF
  float v11; // [sp+74h] [-5Ch]
  float v12; // [sp+78h] [-58h]
  float v13; // [sp+A0h] [-30h]
  float v14; // [sp+A4h] [-2Ch]
  float v15; // [sp+A8h] [-28h]

  this->GetMatrix(this, a2: (bfx::Matrix *)&v10);
  m_commonState = this->m_commonState;
  v8.m_x = v13;
  v8.m_y = v14;
  v8.m_z = v15;
  *(double *)&v5 = simTime;
  *((double *)&v6 + 1) = (float)((float)(v10 * (float)100.0) + v13);
  v9.m_x = (float)(v10 * (float)100.0) + v13;
  *(double *)&v6 = (float)((float)(v11 * (float)100.0) + v14);
  v9.m_y = (float)(v11 * (float)100.0) + v14;
  *((double *)&v5 + 1) = (float)((float)(v12 * (float)100.0) + v15);
  v9.m_z = (float)(v12 * (float)100.0) + v15;
  bfx::Orienter::Simulate(
    this: &m_commonState->m_orienter,
    pos: &v8,
    vel: &this->m_vel,
    simTime: v5,
    nextCornerG: v7,
    bForceUseClientMotion: &v9,
    a7: m_commonState->m_forceUseClientMotion,
    a8: v6);
  bfx::MotionState::SimulateProber(this: this->m_commonState, simTime);
}


// ========================================================================
// ?IsTurningInPlace@IdleImpl@bfx@@UBA_NPAVTurningInPlaceData@2@@Z
// EA  : 0x832D76B8
// RVA : 0x012D76B8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

int __fastcall bfx::IdleImpl::IsTurningInPlace(bfx::IdleImpl *this, bfx::TurningInPlaceData *pDataOut)
{
  bfx::Walker *m_pWalker; // r11

  m_pWalker = this->m_pWalker;
  if ( m_pWalker != nullptr )
    return ((bool (*)(void))m_pWalker->IsTurningInPlace)();
  else
    return bfx::MotionBase::IsTurningInPlaceHelper(
             this,
             pDataOut,
             commonState: this->m_commonState,
             curVel: &this->m_vel);
}


// ========================================================================
// ?GotoPos@IdleImpl@bfx@@AAA_NABVVec3@2@@Z
// EA  : 0x832D76E8
// RVA : 0x012D76E8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

int __fastcall bfx::IdleImpl::GotoPos(bfx::IdleImpl *this, const bfx::Vec3 *requestedGoalPos)
{
  bfx::Walker *m_pWalker; // r3
  float v5; // [sp+50h] [-70h] BYREF
  float v6; // [sp+54h] [-6Ch]
  float v7; // [sp+58h] [-68h]
  bfx::GPSpec v8; // [sp+60h] [-60h] BYREF
  float v9[6]; // [sp+80h] [-40h] BYREF
  char v10; // [sp+98h] [-28h]
  float v11; // [sp+9Ch] [-24h]
  float v12; // [sp+A0h] [-20h]
  float v13; // [sp+A4h] [-1Ch]
  float v14; // [sp+A8h] [-18h]
  char v15; // [sp+ACh] [-14h]

  bfx::SmartPath::SetGoalData(this: this->m_commonState->m_pSmartPath, goalPos: requestedGoalPos, pGoalArea: nullptr);
  if ( !bfx::SmartPath::HasPath(this: this->m_commonState->m_pSmartPath) )
    return 0;
  bfx::SmartPath::GetSnappedGoalPos(this: (bfx::SmartPath *)&v5, result: this->m_commonState->m_pSmartPath);
  v9[2] = v7;
  v9[5] = v7;
  v10 = 0;
  v15 = 0;
  v11 = 0.0;
  v12 = 0.0;
  v13 = 0.0;
  v14 = 180.0;
  v9[0] = v5;
  v9[1] = v6;
  v9[3] = v5;
  v9[4] = v6;
  bfx::GPSpec::GPSpec(this: &v8);
  m_pWalker = this->m_pWalker;
  v8.m_allowedToStopDist = this->m_pTune->m_idleTune.m_tetherDist;
  m_pWalker->GotoPos(this: m_pWalker, a2: (const bfx::WalkerGoalData *)v9, a3: &v8, a4: false);
  return 1;
}


// ========================================================================
// ?Teleport@IdleImpl@bfx@@UAAXABVMatrix@2@ABVVec3@2@PAVArea@2@@Z
// EA  : 0x832D77E8
// RVA : 0x012D77E8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

void __fastcall bfx::IdleImpl::Teleport(
        bfx::IdleImpl *this,
        const bfx::Matrix *newMat,
        const bfx::Vec3 *newVel,
        bfx::Area *__formal)
{
  bfx::Walker *m_pWalker; // r3
  bfx::AreaHandlePath *m_pPath; // r3
  bfx::Vec3 *v9; // r3
  double v10; // fp0
  double v11; // fp13
  double v12; // fp12
  char v13; // [sp+50h] [-40h] BYREF

  if ( this->m_state != IDLE_AT_REST )
  {
    this->m_vel = bfx::ZERO_VEC;
    m_pWalker = this->m_pWalker;
    if ( m_pWalker != nullptr )
      ((void (__fastcall *)(bfx::Walker *, int))m_pWalker->dtr_MotionBase)(a1: m_pWalker, a2: 1);
    m_pPath = this->m_pPath;
    this->m_pWalker = nullptr;
    if ( m_pPath != nullptr )
      ((void (__fastcall *)(bfx::AreaHandlePath *, int))m_pPath->dtr_Path)(a1: m_pPath, a2: 1);
    this->m_pPath = nullptr;
    v9 = this->GetPos(this: &v13, result: this);
    this->m_atRestStartPos.m_x = v9->m_x;
    this->m_atRestStartPos.m_y = v9->m_y;
    this->m_atRestStartPos.m_z = v9->m_z;
    this->m_state = IDLE_AT_REST;
  }
  v10 = newMat->m_data[12];
  v11 = newMat->m_data[13];
  v12 = newMat->m_data[14];
  this->m_startPos.m_x = newMat->m_data[12];
  this->m_startPos.m_y = v11;
  this->m_startPos.m_z = v12;
  this->m_atRestStartPos.m_x = v10;
  this->m_atRestStartPos.m_y = v11;
  this->m_atRestStartPos.m_z = v12;
  this->m_vel.m_x = newVel->m_x;
  this->m_vel.m_y = newVel->m_y;
  this->m_vel.m_z = newVel->m_z;
}


// ========================================================================
// ?ShouldIgnoreDueToInitialOverlap@IdleImpl@bfx@@ABA_NPBVRepulsorImpl@2@M@Z
// EA  : 0x832D78F0
// RVA : 0x012D78F0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

int __fastcall bfx::IdleImpl::ShouldIgnoreDueToInitialOverlap(
        bfx::IdleImpl *this,
        const bfx::RepulsorImpl *pTheirRepulsor,
        double overlapDist)
{
  int m_size; // r6
  int v4; // r8
  bfx::RepulsorOverlap *m_data; // r7
  int i; // r10
  bfx::HandleProxy *m_pProxy; // r11
  const bfx::RepulsorImpl *v8; // r11

  m_size = this->m_initialOverlaps.m_size;
  v4 = 0;
  if ( m_size <= 0 )
    return 0;
  m_data = this->m_initialOverlaps.m_data;
  for ( i = 0; ; ++i )
  {
    m_pProxy = m_data[i].m_theirRepulsor.m_pProxy;
    v8 = m_pProxy != nullptr ? (const bfx::RepulsorImpl *)m_pProxy->m_pTarget : nullptr;
    if ( v8 != nullptr && v8 == pTheirRepulsor && overlapDist <= (float)(m_data[i].m_overlapDist * (float)1.01) )
      break;
    if ( ++v4 >= m_size )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?CalcRepulsionAcc@IdleImpl@bfx@@AAA?AVVec3@2@M@Z
// EA  : 0x832D7978
// RVA : 0x012D7978
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

bfx::IdleImpl *__fastcall bfx::IdleImpl::CalcRepulsionAcc(bfx::IdleImpl *this, bfx::IdleImpl *result, double simTime)
{
  float v3; // r10
  float v7; // r8
  float v8; // r7
  float v9; // r11
  char v10; // r22
  float *v11; // r28
  double v12; // fp21
  double v13; // fp22
  double v14; // fp23
  bfx::InstanceComponent_vtbl *v15; // r10
  double m_bulk; // fp19
  char *v17; // r26
  int v18; // r24
  char *m_data; // r27
  int v20; // r25
  const bfx::RepulsorImpl *v21; // r30
  const bfx::MoverTune *m_pTune; // r5
  double v23; // fp30
  double v24; // fp29
  double v25; // fp28
  double v26; // fp31
  double v27; // fp27
  int v28; // r5
  double v29; // fp1
  double v30; // fp1
  float v31; // r11
  double v32; // fp26
  double v33; // fp27
  double v34; // fp1
  float v35; // r11
  double v36; // fp11
  double v37; // fp10
  double v38; // fp7
  double v39; // fp11
  double v40; // fp1
  double v41; // fp11
  float v43; // [sp+58h] [-138h]
  float v44; // [sp+5Ch] [-134h]
  float v45; // [sp+60h] [-130h]
  float m_x; // [sp+68h] [-128h]
  float m_y; // [sp+6Ch] [-124h]
  float m_z; // [sp+70h] [-120h]
  float v49[6]; // [sp+88h] [-108h] BYREF
  bfx::Array<bfx::SpaceComponent *> v50; // [sp+A0h] [-F0h] BYREF

  v3 = *(float *)&result->m_commonState;
  if ( *(_DWORD *)(LODWORD(v3) + 96) != 0 )
  {
    memset(&v50, 0, 12);
    v50.m_tag = bfx::MEM_BFXMOVER;
    bfx::Repulsor3DImpl::GetNearbyRepulsors(
      this: *(bfx::RepulsorImpl **)(LODWORD(v3) + 96),
      nearbyRepulsors: &v50,
      filterBasedOnBlockageFlags: true);
    v9 = *(float *)&result->m_pTune;
    v10 = 0;
    v11 = (float *)(LODWORD(v9) + 216);
    v43 = 0.0;
    v12 = 0.0;
    v44 = 0.0;
    v13 = 0.0;
    v45 = 0.0;
    v14 = 0.0;
    v15 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][11].__vftable;
    m_bulk = result->m_commonState->m_pRepulsor->m_bulk;
    if ( v15 != nullptr )
      v17 = (char *)v15 + 192 * *(_DWORD *)(LODWORD(v9) + 32);
    else
      v17 = nullptr;
    result->GetPos(this: (struct bfx::IdleImpl *)v49, (bfx::Vec3 *)result);
    v18 = 0;
    m_data = (char *)v50.m_data;
    if ( v50.m_size > 0 )
    {
      v20 = 0;
      do
      {
        v21 = *(const bfx::RepulsorImpl **)&m_data[v20];
        m_pTune = result->m_pTune;
        m_x = v21->m_pos.m_x;
        m_z = v21->m_pos.m_z;
        m_y = v21->m_pos.m_y;
        v23 = (float)(v49[1] - m_y);
        v24 = (float)(v49[0] - m_x);
        v25 = (float)(v49[2] - m_z);
        v26 = __fsqrts((float)((float)((float)(v49[2] - m_z) * (float)(v49[2] - m_z))
                             + (float)((float)((float)(v49[0] - m_x) * (float)(v49[0] - m_x))
                                     + (float)((float)(v49[1] - m_y) * (float)(v49[1] - m_y)))));
        v27 = (float)((float)((float)((float)((float)(m_pTune->m_radiusData.m_innerCushion
                                                    + m_pTune->m_radiusData.m_outerCushion)
                                            + v21->m_radiusData.m_innerCushion)
                                    + v21->m_radiusData.m_outerCushion)
                            + m_pTune->m_radiusData.m_radius)
                    + v21->m_radiusData.m_radius);
        if ( v26 > 0.0
          && v26 < v27
          && (unsigned __int8)bfx::IdleImpl::ShouldIgnoreDueToInitialOverlap(
                                this: result,
                                pTheirRepulsor: v21,
                                overlapDist: (float)((float)((float)((float)((float)((float)(m_pTune->m_radiusData.m_innerCushion
                                                                              + m_pTune->m_radiusData.m_outerCushion)
                                                                      + v21->m_radiusData.m_innerCushion)
                                                              + v21->m_radiusData.m_outerCushion)
                                                      + m_pTune->m_radiusData.m_radius)
                                              + v21->m_radiusData.m_radius)
                                      - (float)v26)) == 0 )
        {
          v10 = 1;
          if ( v17 != nullptr )
            v11 = (float *)&v17[12 * v21->m_repulsorType];
          v30 = bfx::CalcRampAcc(dist: v29, startDist: 0.0, endDist: *(float *)(v28 + 12), maxAcc: v11[1]);
          v31 = *(float *)&result->m_pTune;
          v32 = v30;
          v33 = (float)((float)v27 - (float)(*(float *)(LODWORD(v31) + 12) + v21->m_radiusData.m_outerCushion));
          v34 = bfx::CalcRampAcc(
                  dist: (float)((float)v33 - (float)v26),
                  startDist: 0.0,
                  endDist: *(float *)(LODWORD(v31) + 16),
                  maxAcc: v11[2]);
          v35 = *(float *)&result->m_pTune;
          if ( v26 <= v33 )
          {
            v36 = v11[2];
            v37 = *(float *)(LODWORD(v35) + 16);
          }
          else
          {
            v36 = v11[1];
            v37 = *(float *)(LODWORD(v35) + 12);
          }
          v38 = __fsqrts((float)((float)v36 / (float)v37));
          v39 = 1.0;
          v40 = (float)((float)((float)((float)((float)((float)(v21->m_vel.m_z - result->m_vel.m_z)
                                                      * (float)((float)((float)1.0 / (float)v26) * (float)v25))
                                              + (float)((float)((float)(v21->m_vel.m_x - result->m_vel.m_x)
                                                              * (float)((float)((float)1.0 / (float)v26) * (float)v24))
                                                      + (float)((float)(v21->m_vel.m_y - result->m_vel.m_y)
                                                              * (float)((float)((float)1.0 / (float)v26) * (float)v23))))
                                      * (float)((float)v38 * (float)0.69999999))
                              + (float)v34)
                      + (float)v32);
          if ( v17 == nullptr )
            v39 = (float)(v21->m_bulk / (float)(v21->m_bulk + (float)m_bulk));
          v41 = (float)((float)v39 * (float)((float)v40 + *v11));
          m_data = (char *)v50.m_data;
          v12 = (float)((float)((float)((float)((float)((float)1.0 / (float)v26) * (float)v24) * (float)v41) + (float)v12)
                      * v21->m_repulsionMultiplier);
          v14 = (float)((float)((float)v14 + (float)((float)((float)((float)1.0 / (float)v26) * (float)v25) * (float)v41))
                      * v21->m_repulsionMultiplier);
          v13 = (float)((float)((float)v13 + (float)((float)((float)((float)1.0 / (float)v26) * (float)v23) * (float)v41))
                      * v21->m_repulsionMultiplier);
        }
        ++v18;
        v20 += 4;
      }
      while ( v18 < v50.m_size );
      v44 = v13;
      v45 = v14;
      v43 = v12;
    }
    if ( v10 != 0 )
      result->m_timeSincePushed = 0.0;
    else
      result->m_timeSincePushed = result->m_timeSincePushed + (float)simTime;
    *(float *)&this->__vftable = v43;
    *(float *)&this->m_state = v44;
    *(float *)&this->m_commonState = v45;
    v50.m_size = 0;
    if ( m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
  }
  else
  {
    v7 = bfx::ZERO_VEC.m_y;
    v8 = bfx::ZERO_VEC.m_z;
    this->__vftable = (bfx::IdleImpl_vtbl *)LODWORD(bfx::ZERO_VEC.m_x);
    *(float *)&this->m_state = v7;
    *(float *)&this->m_commonState = v8;
  }
  return this;
}


// ========================================================================
// __unwind$28569
// EA  : 0x832D7D3C
// RVA : 0x012D7D3C
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

void _unwind_28569()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 400 + 160));
}


// ========================================================================
// ?CalcLinearDecel@IdleImpl@bfx@@AAA?AVVec3@2@XZ
// EA  : 0x832D7D68
// RVA : 0x012D7D68
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

bfx::IdleImpl *__fastcall bfx::IdleImpl::CalcLinearDecel(bfx::IdleImpl *this, bfx::Vec3 *result)
{
  float m_z; // r9
  _DWORD *v3; // r8
  double v6; // fp9
  double v7; // fp8
  double v8; // fp7
  double v9; // fp0
  double v10; // fp10
  double v11; // fp0
  double v12; // fp12
  double v13; // fp10
  float m_y; // r8
  float v15; // r7

  m_z = result->m_z;
  v3 = *(_DWORD **)(LODWORD(m_z) + 364);
  _FP2 = (float)((float)__fsqrts((float)((float)((float)(result[2].m_y * result[2].m_y)
                                               + (float)(result[2].m_z * result[2].m_z))
                                       + (float)(result[2].m_x * result[2].m_x)))
               - (float)1.0842022e-19);
  __asm { fsel      f0, f2, f1, f13 }
  v6 = (float)(result[2].m_x * (float)_FP0);
  v7 = (float)((float)_FP0 * result[2].m_y);
  v8 = (float)(result[2].m_z * (float)_FP0);
  if ( v3 != nullptr && *v3 != 0 )
    v9 = *(float *)(LODWORD(m_z) + 368);
  else
    v9 = 1.0;
  v10 = (float)((float)((float)(**(float **)(LODWORD(m_z) + 4) * *(float *)(LODWORD(m_z) + 396))
                      * *(float *)(LODWORD(m_z) + 388))
              * (float)v9);
  if ( v10 <= 0.0 )
  {
    m_y = bfx::ZERO_VEC.m_y;
    v15 = bfx::ZERO_VEC.m_z;
    this->__vftable = (bfx::IdleImpl_vtbl *)LODWORD(bfx::ZERO_VEC.m_x);
    *(float *)&this->m_state = m_y;
    *(float *)&this->m_commonState = v15;
  }
  else
  {
    v11 = 0.1;
    v12 = __fsqrts((float)((float)((float)(result[2].m_y * result[2].m_y) + (float)(result[2].m_z * result[2].m_z))
                         + (float)(result[2].m_x * result[2].m_x)));
    if ( v12 > v10 )
      v11 = 1.0;
    if ( result[5].m_x > 0.1 )
      v11 = 1.0;
    if ( result[5].m_z < 1.0 )
      v11 = 1.0;
    v13 = (float)((float)((float)((float)v12 / (float)v10) * *(float *)(LODWORD(result[1].m_x) + 24)) * (float)v11);
    *(float *)&this->m_commonState = (float)v8 * (float)-v13;
    *(float *)&this->m_state = (float)-v13 * (float)v7;
    *(float *)&this->__vftable = (float)-v13 * (float)v6;
  }
  return this;
}


// ========================================================================
// ?UpdatePushable@IdleImpl@bfx@@AAAXM@Z
// EA  : 0x832D7ED8
// RVA : 0x012D7ED8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

void __fastcall bfx::IdleImpl::UpdatePushable(bfx::IdleImpl *this, double simTime)
{
  bfx::MotionState *m_commonState; // r11
  double m_x; // fp2
  bfx::Vec3 *p_m_vel; // r31
  double v7; // fp9
  double v8; // fp5
  double v9; // fp4
  float v10; // r9
  double m_y; // fp1
  double m_z; // fp0
  double v13; // fp10
  double v14; // fp8
  bfx::Vec3 *v15; // r4
  double v16; // fp13
  double v17; // fp12
  double v18; // fp0
  double v19; // fp4
  double v20; // fp3
  double v21; // fp2
  double v22; // fp10
  double v23; // fp10
  double v24; // fp11
  double v25; // fp12
  double v26; // fp0
  double v27; // fp9
  double v28; // fp7
  bfx::Vec3 *v29; // r3
  bfx::MotionState *v30; // r11
  double v31; // fp11
  double v32; // fp7
  float v33; // r5
  double v34; // fp5
  float v35; // r4
  double m_tetherDist; // fp4
  double m_followSpeedX; // fp9
  double v38; // fp0
  double v39; // fp13
  double v40; // fp12
  double v41; // fp11
  double v42; // fp7
  double v45; // fp10
  double v46; // fp13
  double v47; // fp12
  double v48; // fp0
  double v49; // fp5
  bfx::MotionState *v50; // r10
  bfx::HandleProxy *m_pProxy; // r9
  double v52; // fp13
  float *p_m_speed; // r11
  const bfx::MoverTune *m_pTune; // r9
  double v55; // fp0
  double v56; // fp13
  double v57; // fp11
  bfx::MotionState *v58; // r11
  bfx::Vec3 *p_m_clientSpecifiedVel; // r4
  float v60; // [sp+50h] [-50h] BYREF
  float v61; // [sp+54h] [-4Ch]
  float v62; // [sp+58h] [-48h]
  float v63; // [sp+60h] [-40h] BYREF
  float v64; // [sp+64h] [-3Ch]
  float v65; // [sp+68h] [-38h]

  bfx::IdleImpl::CalcRepulsionAcc(this: (bfx::IdleImpl *)&v63, result: this, simTime);
  m_commonState = this->m_commonState;
  m_x = this->m_vel.m_x;
  p_m_vel = &this->m_vel;
  v7 = (float)(m_commonState->m_externalForce.m_x + v63);
  v8 = (float)(m_commonState->m_externalForce.m_y + v64);
  v9 = (float)(m_commonState->m_externalForce.m_z + v65);
  v10 = m_commonState->m_followData.m_externalForce.m_x;
  m_y = this->m_vel.m_y;
  v61 = m_commonState->m_followData.m_externalForce.m_y;
  v60 = v10;
  m_z = this->m_vel.m_z;
  v62 = m_commonState->m_followData.m_externalForce.m_z;
  v13 = (float)((float)(v61 + (float)v8) * (float)simTime);
  v14 = (float)((float)(v62 + (float)v9) * (float)simTime);
  this->m_vel.m_x = (float)((float)(v10 + (float)v7) * (float)simTime) + (float)m_x;
  this->m_vel.m_y = (float)v13 + (float)m_y;
  this->m_vel.m_z = (float)v14 + (float)m_z;
  bfx::IdleImpl::CalcLinearDecel(this: (bfx::IdleImpl *)&v60, result: (bfx::Vec3 *)this);
  bfx::IdleImpl::CalcMaxDecel(this: (bfx::IdleImpl *)&v63, result: v15);
  v16 = (float)(v62 + v65);
  v17 = (float)(v63 + v60);
  v18 = (float)(v61 + v64);
  v19 = __fsqrts((float)((float)(this->m_vel.m_z * this->m_vel.m_z)
                       + (float)((float)(this->m_vel.m_x * this->m_vel.m_x) + (float)(this->m_vel.m_y * this->m_vel.m_y))));
  v20 = (float)((float)((float)(v62 + v65) * (float)(v62 + v65)) + (float)((float)(v61 + v64) * (float)(v61 + v64)));
  v62 = v62 + v65;
  v61 = v61 + v64;
  v21 = (float)((float)((float)(v63 + v60) * (float)(v63 + v60)) + (float)v20);
  v60 = v63 + v60;
  v22 = __fsqrts(v21);
  if ( v22 <= (float)((float)v19 / (float)simTime) )
  {
    v24 = v60;
    v25 = v61;
    v26 = v62;
  }
  else
  {
    v23 = (float)((float)((float)v19 / (float)simTime) / (float)v22);
    v24 = (float)((float)v23 * (float)v17);
    v25 = (float)((float)v18 * (float)v23);
    v26 = (float)((float)v16 * (float)v23);
  }
  v27 = this->m_vel.m_y;
  v28 = this->m_vel.m_z;
  p_m_vel->m_x = (float)((float)v24 * (float)simTime) + p_m_vel->m_x;
  this->m_vel.m_y = (float)((float)v25 * (float)simTime) + (float)v27;
  this->m_vel.m_z = (float)((float)v26 * (float)simTime) + (float)v28;
  v29 = this->GetPos(this: &v63, result: this);
  v30 = this->m_commonState;
  v31 = (float)(this->m_startPos.m_y - v29->m_y);
  v32 = (float)(this->m_startPos.m_z - v29->m_z);
  v33 = v30->m_surfer.m_areaNormal.m_x;
  v34 = (float)(this->m_startPos.m_x - v29->m_x);
  v35 = v30->m_surfer.m_areaNormal.m_y;
  m_tetherDist = this->m_pTune->m_idleTune.m_tetherDist;
  v62 = v30->m_surfer.m_areaNormal.m_z;
  v60 = v33;
  v61 = v35;
  m_followSpeedX = 1.0;
  v38 = (float)((float)v31
              - (float)(v35
                      * (float)((float)(v33 * (float)v34)
                              + (float)((float)(v62 * (float)v32) + (float)(v35 * (float)v31)))));
  v39 = (float)((float)v32
              - (float)(v62
                      * (float)((float)(v33 * (float)v34)
                              + (float)((float)(v62 * (float)v32) + (float)(v35 * (float)v31)))));
  v40 = (float)((float)v34
              - (float)((float)((float)(v33 * (float)v34)
                              + (float)((float)(v62 * (float)v32) + (float)(v35 * (float)v31)))
                      * v33));
  v41 = (float)((float)((float)v40 * (float)v40)
              + (float)((float)((float)v39 * (float)v39) + (float)((float)v38 * (float)v38)));
  if ( __fsqrts(v41) > m_tetherDist )
  {
    v42 = this->m_vel.m_y;
    _FP4 = (float)((float)__fsqrts(v41) - (float)1.0842022e-19);
    __asm { fsel      f2, f4, f3, f11 }
    v45 = (float)((float)v38 * (float)_FP2);
    v46 = (float)((float)v39 * (float)_FP2);
    v47 = (float)((float)v40 * (float)_FP2);
    v48 = (float)((float)((float)v47 * this->m_vel.m_x)
                + (float)((float)((float)v46 * this->m_vel.m_z)
                        + (float)((float)((float)v38 * (float)_FP2) * this->m_vel.m_y)));
    if ( v48 < 0.0 )
    {
      v49 = this->m_vel.m_z;
      p_m_vel->m_x = p_m_vel->m_x - (float)((float)v47 * (float)v48);
      this->m_vel.m_y = (float)v42 - (float)((float)v45 * (float)v48);
      this->m_vel.m_z = (float)v49 - (float)((float)v46 * (float)v48);
    }
  }
  v50 = this->m_commonState;
  m_pProxy = v50->m_followData.m_targetMover.m_pProxy;
  v52 = __fsqrts((float)((float)(p_m_vel->m_x * p_m_vel->m_x)
                       + (float)((float)(p_m_vel->m_y * p_m_vel->m_y) + (float)(p_m_vel->m_z * p_m_vel->m_z))));
  if ( m_pProxy != nullptr && m_pProxy->m_pTarget != nullptr )
    m_followSpeedX = v50->m_followData.m_followSpeedX;
  p_m_speed = &v50->m_pTune->m_speed;
  m_pTune = this->m_pTune;
  if ( v52 > (float)((float)((float)((float)(*p_m_speed * m_pTune->m_maxSpeedFraction)
                                   * v50->m_cautionData.m_internalSpeedX)
                           * v50->m_speedX)
                   * (float)m_followSpeedX)
    && v52 > 1.0842022e-19 )
  {
    v55 = (float)((float)((float)((float)((float)(*p_m_speed * m_pTune->m_maxSpeedFraction)
                                        * v50->m_cautionData.m_internalSpeedX)
                                * v50->m_speedX)
                        * (float)m_followSpeedX)
                / (float)v52);
    v57 = this->m_vel.m_z;
    v56 = this->m_vel.m_y;
    p_m_vel->m_x = (float)v55 * p_m_vel->m_x;
    this->m_vel.m_y = (float)v55 * (float)v56;
    this->m_vel.m_z = (float)v55 * (float)v57;
  }
  v58 = this->m_commonState;
  p_m_clientSpecifiedVel = &this->m_clientSpecifiedVel;
  if ( !v58->m_pTune->m_clientMotion )
    p_m_clientSpecifiedVel = &this->m_vel;
  bfx::Surfer::Move(this: &v58->m_surfer, origVel: p_m_clientSpecifiedVel, time: simTime);
  bfx::SmartPath::SetStartData(
    this: this->m_commonState->m_pSmartPath,
    startPos: &this->m_startPos,
    pStartArea: nullptr);
  bfx::IdleImpl::UpdateOrienterAndProber(this, simTime);
}


// ========================================================================
// ??0IdleImpl@bfx@@QAA@ABVMatrix@1@PAVArea@1@AAVMotionState@1@_N@Z
// EA  : 0x832D85D0
// RVA : 0x012D85D0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

bfx::IdleImpl *__fastcall bfx::IdleImpl::IdleImpl(
        bfx::IdleImpl *this,
        const bfx::Matrix *startMat,
        bfx::Vec3 *pStartArea,
        bfx::MotionState *commonState,
        bool preserveExactInputHeight)
{
  bfx::NavLayer *v9; // r28
  bfx::bfxMemTag v10; // r11
  bfx::MotionState *m_commonState; // r5
  bfx::Vec3 *p_m_startPos; // r29
  double v13; // fp13
  double v14; // fp11
  long double v15; // fp2
  bfx::MotionState *v16; // r11
  unsigned int m_planLayer; // r10
  bfx::Vec3 *p_m_orienter; // r4
  const bfx::Vec3 *p_m_pos; // r28
  bfx::Orienter *LocalUpAxis; // r3
  const bfx::Vec3 *v21; // r29
  bfx::Orienter *v22; // r3
  _BYTE v24[88]; // [sp+58h] [-58h] BYREF

  this->m_commonState = commonState;
  v9 = nullptr;
  this->m_refreshInitialOverlapsTimer = 0.0;
  this->__vftable = (bfx::IdleImpl_vtbl *)&bfx::IdleImpl::`vftable';
  this->m_calculatedInitialOverlaps = false;
  v10 = bfx::MEM_BFXMOVER;
  this->m_initialOverlaps.m_data = nullptr;
  this->m_initialOverlaps.m_size = 0;
  this->m_initialOverlaps.m_cap = 0;
  this->m_initialOverlaps.m_tag = v10;
  m_commonState = this->m_commonState;
  this->m_state = IDLE_AT_REST;
  p_m_startPos = &this->m_startPos;
  this->m_pTune = m_commonState->m_pTune;
  this->m_pPath = nullptr;
  this->m_pWalker = nullptr;
  this->m_vel = bfx::ZERO_VEC;
  v13 = startMat->m_data[12];
  v14 = startMat->m_data[14];
  this->m_startPos.m_y = startMat->m_data[13];
  this->m_startPos.m_z = v14;
  this->m_startPos.m_x = v13;
  this->m_atRestStartPos.m_x = v13;
  this->m_atRestStartPos.m_y = this->m_startPos.m_y;
  this->m_atRestStartPos.m_z = this->m_startPos.m_z;
  this->m_timeSincePushed = 3.4028235e38;
  this->m_timeSinceLastMoved = 0.0;
  this->m_timeSinceIdleStart = 0.0;
  this->m_clientSpecifiedVel = bfx::ZERO_VEC;
  bfx::Surfer::SetPosAndArea(this: &this->m_commonState->m_surfer, pos: &this->m_startPos, pArea: pStartArea);
  bfx::SmartPath::SetStartData(this: this->m_commonState->m_pSmartPath, startPos: p_m_startPos, (bfx::Area *)pStartArea);
  bfx::Orienter::TeleportToArea(this: &this->m_commonState->m_orienter, pArea: pStartArea, a3: v15);
  bfx::Orienter::SetOrientation(this: &this->m_commonState->m_orienter, desiredRot: startMat);
  v16 = this->m_commonState;
  if ( v16->m_pProber != nullptr )
  {
    m_planLayer = v16->m_pTune->m_planLayer;
    if ( m_planLayer < 0x20 )
      v9 = *(bfx::NavLayer **)(4 * (m_planLayer + 2) + *((_DWORD *)v16->m_pSpace->m_components.m_data + 1));
    p_m_orienter = (bfx::Vec3 *)&v16->m_orienter;
    if ( preserveExactInputHeight )
    {
      p_m_pos = &v16->m_surfer.m_pos;
      LocalUpAxis = bfx::Orienter::GetLocalUpAxis(this: (bfx::Orienter *)v24, result: p_m_orienter);
      bfx::Prober::SetHeight(
        this: this->m_commonState->m_pProber,
        actualPos: p_m_startPos,
        surferPos: p_m_pos,
        localUpAxis: (const bfx::Vec3 *)LocalUpAxis);
    }
    else
    {
      v21 = &v16->m_surfer.m_pos;
      v22 = bfx::Orienter::GetLocalUpAxis(this: (bfx::Orienter *)v24, result: p_m_orienter);
      bfx::Prober::TeleportToArea(
        this: this->m_commonState->m_pProber,
        pNavLayer: v9,
        surferPos: v21,
        localUpAxis: (const bfx::Vec3 *)v22);
    }
  }
  return this;
}


// ========================================================================
// __unwind$29899
// EA  : 0x832D87D8
// RVA : 0x012D87D8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

void _unwind_29899()
{
  int v0; // r12

  bfx::Idle::~Idle(this: *(bfx::Walker **)(v0 - 176 + 196));
}


// ========================================================================
// __unwind$29900
// EA  : 0x832D8800
// RVA : 0x012D8800
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

void _unwind_29900()
{
  int v0; // r12

  bfx::Array<bfx::LinkConnectionData>::~Array<bfx::LinkConnectionData>(this: (bfx::Array<bfx::LinkConnectionData> *)(*(_DWORD *)(v0 - 176 + 196) + 92));
}


// ========================================================================
// ?GetName@IdleImpl@bfx@@UAAPBDXZ
// EA  : 0x832D8830
// RVA : 0x012D8830
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

const char *__fastcall bfx::IdleImpl::GetName(bfx::IdleImpl *this)
{
  bfx::IdleImpl::State m_state; // r11

  m_state = this->m_state;
  if ( m_state == IDLE_BEING_PUSHED )
    return "Idle: pushed";
  if ( m_state == IDLE_GOING_HOME )
    return "Idle: goingHome";
  return "Idle: atRest";
}


// ========================================================================
// ?OrientInDirectionOfTravel@IdleImpl@bfx@@UAAXXZ
// EA  : 0x832D8868
// RVA : 0x012D8868
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

void __fastcall bfx::IdleImpl::OrientInDirectionOfTravel(bfx::IdleImpl *this)
{
  idThrowableFilter::InternalPostFilterItems(this: &this->m_commonState->m_orienter);
}


// ========================================================================
// ?OrientStrictlyInDirectionOfTravel@IdleImpl@bfx@@UAAXXZ
// EA  : 0x832D8878
// RVA : 0x012D8878
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

void __fastcall bfx::IdleImpl::OrientStrictlyInDirectionOfTravel(bfx::IdleImpl *this)
{
  bfx::Orienter::FaceStrictlyInTravelDir(this: &this->m_commonState->m_orienter);
}


// ========================================================================
// ?OrientTowardsTargetPos@IdleImpl@bfx@@UAAXABVVec3@2@@Z
// EA  : 0x832D8888
// RVA : 0x012D8888
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

void __fastcall bfx::IdleImpl::OrientTowardsTargetPos(bfx::IdleImpl *this, const bfx::Vec3 *targetPos)
{
  bfx::Orienter::FaceTarget(this: &this->m_commonState->m_orienter, targetPos);
}


// ========================================================================
// ?OrientInDirection@IdleImpl@bfx@@UAAXABVVec3@2@@Z
// EA  : 0x832D8898
// RVA : 0x012D8898
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

void __fastcall bfx::IdleImpl::OrientInDirection(bfx::IdleImpl *this, const bfx::Vec3 *dir)
{
  bfx::Orienter::FaceInDir(this: &this->m_commonState->m_orienter, dir);
}


// ========================================================================
// ?GetPos@IdleImpl@bfx@@UBA?AVVec3@2@XZ
// EA  : 0x832D88A8
// RVA : 0x012D88A8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

bfx::IdleImpl *__fastcall bfx::IdleImpl::GetPos(bfx::IdleImpl *this, bfx::Vec3 *result)
{
  float m_z; // r11
  int v3; // r9
  bfx::Vec3 *v4; // r10
  double v5; // fp8
  double v6; // fp6
  _DWORD back_chain[4]; // [sp+0h] [-10h] BYREF

  m_z = result->m_z;
  v3 = *(_DWORD *)(LODWORD(m_z) + 336);
  if ( v3 != 0 )
  {
    v4 = (bfx::Vec3 *)back_chain;
    back_chain[2] = *(_DWORD *)(v3 + 24);
  }
  else
  {
    v4 = &bfx::ZERO_VEC;
  }
  v5 = (float)(*(float *)(LODWORD(m_z) + 24) + v4->m_y);
  v6 = (float)(*(float *)(LODWORD(m_z) + 28) + v4->m_z);
  *(float *)&this->__vftable = v4->m_x + *(float *)(LODWORD(m_z) + 20);
  *(float *)&this->m_state = v5;
  *(float *)&this->m_commonState = v6;
  return this;
}


// ========================================================================
// ?GetMatrix@IdleImpl@bfx@@UBAXAAVMatrix@2@@Z
// EA  : 0x832D8918
// RVA : 0x012D8918
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

void __fastcall bfx::IdleImpl::GetMatrix(bfx::IdleImpl *this, bfx::Matrix *mat)
{
  const bfx::Vec3 *v4; // r3
  _BYTE v5[24]; // [sp+50h] [-30h] BYREF

  v4 = this->GetPos(this: v5, result: this);
  bfx::Orienter::CalcMat(this: &this->m_commonState->m_orienter, pos: v4, mat);
}


// ========================================================================
// ?UpdateSmartPath@IdleImpl@bfx@@UAAXABVVec3@2@PAVArea@2@@Z
// EA  : 0x832D8978
// RVA : 0x012D8978
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

void __fastcall bfx::IdleImpl::UpdateSmartPath(bfx::IdleImpl *this, const bfx::Vec3 *newPos, bfx::Area *pNewArea)
{
  bfx::SmartPath::SetStartData(this: this->m_commonState->m_pSmartPath, startPos: newPos, pStartArea: pNewArea);
}


// ========================================================================
// ??1IdleImpl@bfx@@UAA@XZ
// EA  : 0x832D8990
// RVA : 0x012D8990
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

void __fastcall bfx::IdleImpl::~IdleImpl(bfx::IdleImpl *this)
{
  bfx::Walker *m_pWalker; // r3
  bfx::AreaHandlePath *m_pPath; // r3
  char *m_data; // r4

  this->__vftable = (bfx::IdleImpl_vtbl *)&bfx::IdleImpl::`vftable';
  m_pWalker = this->m_pWalker;
  if ( m_pWalker != nullptr )
    ((void (__fastcall *)(bfx::Walker *, int))m_pWalker->dtr_MotionBase)(a1: m_pWalker, a2: 1);
  m_pPath = this->m_pPath;
  this->m_pWalker = nullptr;
  if ( m_pPath != nullptr )
    ((void (__fastcall *)(bfx::AreaHandlePath *, int))m_pPath->dtr_Path)(a1: m_pPath, a2: 1);
  this->m_pPath = nullptr;
  bfx::Array<bfx::LinkConnectionData>::shrink(
    this: (bfx::Array<bfx::LinkConnectionData> *)&this->m_initialOverlaps,
    size: 0);
  m_data = (char *)this->m_initialOverlaps.m_data;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_initialOverlaps.m_data = nullptr;
  }
  this->m_initialOverlaps.m_cap = 0;
  this->__vftable = (bfx::IdleImpl_vtbl *)&bfx::MotionBase::`vftable';
}


// ========================================================================
// __unwind$30105
// EA  : 0x832D8A48
// RVA : 0x012D8A48
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

void _unwind_30105()
{
  int v0; // r12

  bfx::Idle::~Idle(this: *(bfx::Walker **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$30106
// EA  : 0x832D8A70
// RVA : 0x012D8A70
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

void _unwind_30106()
{
  int v0; // r12

  bfx::Array<bfx::LinkConnectionData>::~Array<bfx::LinkConnectionData>(this: (bfx::Array<bfx::LinkConnectionData> *)(*(_DWORD *)(v0 - 128 + 148) + 92));
}


// ========================================================================
// ?CalcInitialOverlaps@IdleImpl@bfx@@AAAXXZ
// EA  : 0x832D8AA8
// RVA : 0x012D8AA8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

void __fastcall bfx::IdleImpl::CalcInitialOverlaps(bfx::IdleImpl *this)
{
  bfx::MotionState *m_commonState; // r10
  int v3; // r27
  bfx::RepulsorImpl *m_pRepulsor; // r11
  float m_y; // r7
  float m_z; // r6
  double v7; // fp29
  double m_overlapDist; // fp28
  int v9; // r29
  double v10; // fp27
  const bfx::MoverTune *m_pTune; // r11
  bfx::Space *v12; // r4
  double v13; // fp12
  double m_radius; // fp11
  double m_x; // fp10
  float v16; // r7
  double m_w; // fp9
  float v18; // r6
  double v19; // fp8
  double v20; // fp31
  bfx::RepulsorOverlap v21; // [sp+58h] [-98h] BYREF
  float v22; // [sp+60h] [-90h]
  float v23; // [sp+68h] [-88h]
  float v24; // [sp+6Ch] [-84h]
  float v25; // [sp+70h] [-80h]
  bfx::Array<bfx::SpaceComponent *> v26[4]; // [sp+80h] [-70h] BYREF

  m_commonState = this->m_commonState;
  if ( m_commonState->m_pRepulsor != nullptr )
  {
    memset(v26, 0, 12);
    v26[0].m_tag = bfx::MEM_BFXMOVER;
    bfx::Repulsor3DImpl::GetNearbyRepulsors(
      this: m_commonState->m_pRepulsor,
      nearbyRepulsors: v26,
      filterBasedOnBlockageFlags: true);
    v3 = 0;
    m_pRepulsor = this->m_commonState->m_pRepulsor;
    m_y = m_pRepulsor->m_pos.m_y;
    m_z = m_pRepulsor->m_pos.m_z;
    v21.m_theirRepulsor.m_pProxy = (bfx::HandleProxy *)LODWORD(m_pRepulsor->m_pos.m_x);
    v21.m_overlapDist = m_y;
    v22 = m_z;
    if ( v26[0].m_size > 0 )
    {
      v7 = v22;
      m_overlapDist = v21.m_overlapDist;
      v9 = 0;
      v10 = *(float *)&v21.m_theirRepulsor.m_pProxy;
      do
      {
        m_pTune = this->m_pTune;
        v12 = (bfx::Space *)v26[0].m_data[v9];
        v13 = (float)(m_pTune->m_radiusData.m_innerCushion + m_pTune->m_radiusData.m_outerCushion);
        m_radius = m_pTune->m_radiusData.m_radius;
        m_x = v12->m_rotWorldToSpace.m_x;
        v16 = v12->m_pos.m_z;
        m_w = v12->m_rotWorldToSpace.m_w;
        v18 = v12->m_pos.m_y;
        v19 = v12->m_rotSpaceToWorld.m_z;
        v23 = v12->m_pos.m_x;
        v25 = v16;
        v24 = v18;
        v20 = (float)((float)((float)((float)((float)((float)v13 + (float)m_x) + (float)m_w) + (float)m_radius)
                            + (float)v19)
                    - (float)__fsqrts((float)((float)((float)((float)v7 - v16) * (float)((float)v7 - v16))
                                            + (float)((float)((float)((float)v10 - v23) * (float)((float)v10 - v23))
                                                    + (float)((float)((float)m_overlapDist - v18)
                                                            * (float)((float)m_overlapDist - v18))))));
        if ( v20 > 0.0 )
        {
          bfx::Handle<bfx::LinkBase>::Handle<bfx::LinkBase>(this: (bfx::Handle<bfx::Space> *)&v21, pTarget: v12);
          v21.m_overlapDist = v20;
          bfx::Array<bfx::RepulsorOverlap>::push_back(this: &this->m_initialOverlaps, val: &v21);
          if ( v21.m_theirRepulsor.m_pProxy != nullptr )
          {
            bfx::HandleProxy::RemRefToHandleProxy(this: v21.m_theirRepulsor.m_pProxy);
            v21.m_theirRepulsor.m_pProxy = nullptr;
          }
        }
        ++v3;
        ++v9;
      }
      while ( v3 < v26[0].m_size );
    }
    v26[0].m_size = 0;
    if ( v26[0].m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v26[0].m_data);
  }
}


// ========================================================================
// __unwind$30141
// EA  : 0x832D8C44
// RVA : 0x012D8C44
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

void _unwind_30141()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 240 + 128));
}


// ========================================================================
// __unwind$30142
// EA  : 0x832D8C6C
// RVA : 0x012D8C6C
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

void _unwind_30142()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: (bfx::Handle<bfx::Space> *)(v0 - 240 + 88));
}


// ========================================================================
// ?CreateIdle@bfx@@YAPAVIdle@1@ABVMatrix@1@PAVArea@1@AAVMotionState@1@_N@Z
// EA  : 0x832D8CA0
// RVA : 0x012D8CA0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

bfx::IdleImpl *__fastcall bfx::CreateIdle(
        const bfx::Matrix *startMat,
        bfx::Vec3 *pStartArea,
        bfx::MotionState *commonState,
        bool preserveExactInputHeight)
{
  bfx::IdleImpl *v8; // r3

  v8 = (bfx::IdleImpl *)bfx::MemoryManager::Malloc(
                          this: bfx::g_pCurInstance->m_pMemoryManager,
                          size: 0x6Cu,
                          tag: bfx::MEM_BFXMOVER);
  if ( v8 != nullptr )
    return bfx::IdleImpl::IdleImpl(this: v8, startMat, pStartArea, commonState, preserveExactInputHeight);
  else
    return nullptr;
}


// ========================================================================
// __unwind$30302
// EA  : 0x832D8D0C
// RVA : 0x012D8D0C
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

void _unwind_30302()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(char **)(v0 - 144 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?RefreshInitialOverlaps@IdleImpl@bfx@@AAAXXZ
// EA  : 0x832D8DA0
// RVA : 0x012D8DA0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

void __fastcall bfx::IdleImpl::RefreshInitialOverlaps(bfx::IdleImpl *this)
{
  bfx::MotionState *m_commonState; // r10
  bfx::Array<bfx::RepulsorOverlap> *p_m_initialOverlaps; // r30
  char *m_data; // r4
  int v5; // r26
  bfx::RepulsorImpl *m_pRepulsor; // r11
  int v7; // r29
  bfx::RepulsorOverlap *v8; // r8
  float *m_pTarget; // r11
  char v10; // r7
  char *v11; // r10
  char *v12; // r9
  char v13; // r10
  const bfx::MoverTune *m_pTune; // r10
  double v15; // fp4
  double v16; // fp0
  float m_x; // [sp+58h] [-88h]
  float m_y; // [sp+5Ch] [-84h]
  float m_z; // [sp+60h] [-80h]
  bfx::Array<bfx::SpaceComponent *> v20; // [sp+70h] [-70h] BYREF

  m_commonState = this->m_commonState;
  if ( m_commonState->m_pRepulsor != nullptr )
  {
    memset(&v20, 0, 12);
    v20.m_tag = bfx::MEM_BFXMOVER;
    bfx::Repulsor3DImpl::GetNearbyRepulsors(
      this: m_commonState->m_pRepulsor,
      nearbyRepulsors: &v20,
      filterBasedOnBlockageFlags: true);
    p_m_initialOverlaps = &this->m_initialOverlaps;
    m_data = (char *)v20.m_data;
    v5 = 0;
    m_pRepulsor = this->m_commonState->m_pRepulsor;
    m_x = m_pRepulsor->m_pos.m_x;
    m_y = m_pRepulsor->m_pos.m_y;
    m_z = m_pRepulsor->m_pos.m_z;
    if ( this->m_initialOverlaps.m_size > 0 )
    {
      v7 = 0;
      do
      {
        v8 = &p_m_initialOverlaps->m_data[v7];
        if ( v8->m_theirRepulsor.m_pProxy != nullptr )
          m_pTarget = (float *)v8->m_theirRepulsor.m_pProxy->m_pTarget;
        else
          m_pTarget = nullptr;
        v10 = 0;
        if ( m_pTarget != nullptr )
        {
          v11 = m_data;
          v12 = &m_data[4 * v20.m_size];
          if ( m_data == v12 )
          {
LABEL_11:
            v13 = 0;
          }
          else
          {
            while ( *(float **)v11 != m_pTarget )
            {
              v11 += 4;
              if ( v11 == v12 )
                goto LABEL_11;
            }
            v13 = 1;
          }
          if ( v13 != 0 )
          {
            m_pTune = this->m_pTune;
            v15 = __fsqrts((float)((float)((float)(m_z - m_pTarget[5]) * (float)(m_z - m_pTarget[5]))
                                 + (float)((float)((float)(m_x - m_pTarget[3]) * (float)(m_x - m_pTarget[3]))
                                         + (float)((float)(m_y - m_pTarget[4]) * (float)(m_y - m_pTarget[4])))));
            v16 = (float)((float)((float)((float)((float)((float)(m_pTune->m_radiusData.m_innerCushion
                                                                + m_pTune->m_radiusData.m_outerCushion)
                                                        + m_pTarget[11])
                                                + m_pTarget[10])
                                        + m_pTune->m_radiusData.m_radius)
                                + m_pTarget[9])
                        - (float)v15);
            if ( v16 < v8->m_overlapDist )
            {
              v8->m_overlapDist = (float)((float)((float)((float)((float)(m_pTune->m_radiusData.m_innerCushion
                                                                        + m_pTune->m_radiusData.m_outerCushion)
                                                                + m_pTarget[11])
                                                        + m_pTarget[10])
                                                + m_pTune->m_radiusData.m_radius)
                                        + m_pTarget[9])
                                - (float)v15;
              m_data = (char *)v20.m_data;
            }
            if ( v16 > 0.0 )
              v10 = 1;
          }
        }
        if ( v10 != 0 )
        {
          ++v5;
          ++v7;
        }
        else
        {
          bfx::Array<bfx::RepulsorOverlap>::erase(this: &this->m_initialOverlaps, ptr: &p_m_initialOverlaps->m_data[v7]);
          m_data = (char *)v20.m_data;
        }
      }
      while ( v5 < this->m_initialOverlaps.m_size );
    }
    v20.m_size = 0;
    if ( m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
  }
}


// ========================================================================
// __unwind$30331
// EA  : 0x832D8FC4
// RVA : 0x012D8FC4
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

void _unwind_30331()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 224 + 112));
}


// ========================================================================
// ?Simulate@IdleImpl@bfx@@UAAXM@Z
// EA  : 0x832D8FF8
// RVA : 0x012D8FF8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

void __fastcall bfx::IdleImpl::Simulate(bfx::IdleImpl *this, double simTime)
{
  bfx::RepulsorImpl *m_pRepulsor; // r11
  bfx::RepulsorOwner *m_pOwner; // r10
  bfx::Mover *v6; // r27
  int v7; // r28
  int v8; // r29
  bfx::SpaceComponent *v9; // r10
  bfx::SpaceComponent_vtbl *v10; // r11
  bfx::Mover *v11; // r4
  bfx::IdleImpl::State m_state; // r11
  bfx::Vec3 *v13; // r3
  bfx::MotionState *m_commonState; // r10
  const bfx::MoverTune *m_pTune; // r11
  double v16; // fp8
  double v17; // fp6
  float m_x; // r8
  double v19; // fp10
  float m_y; // r7
  double m_innerCushion; // fp5
  double m_outerCushion; // fp4
  double v23; // fp2
  double v24; // fp1
  double v25; // fp0
  bfx::Walker *v26; // r3
  bfx::AreaHandlePath *v27; // r3
  bfx::WalkerImpl *v28; // r3
  bfx::Walker *m_pWalker; // r3
  bfx::AreaHandlePath *m_pPath; // r3
  bfx::Vec3 *v31; // r3
  bfx::Walker *v32; // r3
  bfx::AreaHandlePath *v33; // r3
  bfx::Vec3 *v34; // r3
  double v35; // fp13
  double v36; // fp10
  double v37; // fp9
  bfx::MotionState *v38; // r9
  bfx::HandleProxy *m_pProxy; // r10
  double v40; // fp12
  double m_followSpeedX; // fp13
  float v42; // [sp+58h] [-B8h] BYREF
  float v43; // [sp+5Ch] [-B4h]
  float m_z; // [sp+60h] [-B0h]
  bfx::Array<bfx::SpaceComponent *> v45; // [sp+70h] [-A0h] BYREF
  bfx::Matrix v46; // [sp+80h] [-90h] BYREF

  if ( this->m_pTune->m_idleTune.m_tetherDist == 0.0 )
  {
    bfx::IdleImpl::UpdateOrienterAndProber(this, simTime);
    return;
  }
  m_pRepulsor = this->m_commonState->m_pRepulsor;
  if ( m_pRepulsor != nullptr )
  {
    m_pOwner = m_pRepulsor->m_pOwner;
    if ( m_pOwner != nullptr && m_pOwner->m_creatorType == REPULSOR_CREATOR_MOVER )
      v6 = (bfx::Mover *)m_pRepulsor->m_pOwner->GetRepulsorOwner(this: m_pRepulsor->m_pOwner);
    else
      v6 = nullptr;
    memset(&v45, 0, 12);
    v45.m_tag = bfx::MEM_BFXMOVER;
    bfx::Repulsor3DImpl::GetNearbyRepulsors(
      this: this->m_commonState->m_pRepulsor,
      nearbyRepulsors: &v45,
      filterBasedOnBlockageFlags: true);
    v7 = 0;
    if ( v45.m_size > 0 )
    {
      v8 = 0;
      do
      {
        v9 = v45.m_data[v8];
        v10 = v9[21].__vftable;
        if ( v10 != nullptr && v10->Simulate == (void (__fastcall *)(bfx::SpaceComponent *, double))1 )
        {
          v11 = (bfx::Mover *)(*((int (__fastcall **)(bfx::SpaceComponent_vtbl *))v9[21].dtr_SpaceComponent + 1))(a1: v9[21].__vftable);
          if ( v11 != nullptr )
            bfx::UpdateMoverContact(pInputMoverA: v6, pInputMoverB: v11);
        }
        ++v7;
        ++v8;
      }
      while ( v7 < v45.m_size );
    }
    v45.m_size = 0;
    if ( v45.m_data != nullptr )
    {
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v45.m_data);
      v45.m_data = nullptr;
    }
    v45.m_cap = 0;
  }
  m_state = this->m_state;
  if ( m_state != IDLE_AT_REST )
  {
    if ( m_state == IDLE_BEING_PUSHED )
    {
      if ( this->m_timeSinceLastMoved > (double)this->m_pTune->m_idleTune.m_returnDelay )
      {
        this->GetMatrix(this, a2: &v46);
        v28 = bfx::CreateWalker(mat: &v46, commonState: this->m_commonState);
        this->m_pWalker = v28;
        v28->Initialize(this: v28, a2: &this->m_vel, a3: &v46);
        if ( (unsigned __int8)bfx::IdleImpl::GotoPos(this, requestedGoalPos: &this->m_startPos) != 0 )
          this->m_state = IDLE_GOING_HOME;
      }
    }
    else
    {
      if ( this->m_pWalker->DoneMoving(this: this->m_pWalker) && this->m_state != IDLE_AT_REST )
      {
        this->m_vel = bfx::ZERO_VEC;
        m_pWalker = this->m_pWalker;
        if ( m_pWalker != nullptr )
          ((void (__fastcall *)(bfx::Walker *, int))m_pWalker->dtr_MotionBase)(a1: m_pWalker, a2: 1);
        m_pPath = this->m_pPath;
        this->m_pWalker = nullptr;
        if ( m_pPath != nullptr )
          ((void (__fastcall *)(bfx::AreaHandlePath *, int))m_pPath->dtr_Path)(a1: m_pPath, a2: 1);
        this->m_pPath = nullptr;
        v31 = this->GetPos(this: &v42, result: this);
        this->m_atRestStartPos.m_x = v31->m_x;
        this->m_atRestStartPos.m_y = v31->m_y;
        this->m_atRestStartPos.m_z = v31->m_z;
        this->m_state = IDLE_AT_REST;
      }
      if ( (float)(bfx::GetTime() - this->m_commonState->m_contactTime) < 0.25 && this->m_state != IDLE_AT_REST )
      {
        this->m_vel = bfx::ZERO_VEC;
        v32 = this->m_pWalker;
        if ( v32 != nullptr )
          ((void (__fastcall *)(bfx::Walker *, int))v32->dtr_MotionBase)(a1: v32, a2: 1);
        v33 = this->m_pPath;
        this->m_pWalker = nullptr;
        if ( v33 != nullptr )
          ((void (__fastcall *)(bfx::AreaHandlePath *, int))v33->dtr_Path)(a1: v33, a2: 1);
        this->m_pPath = nullptr;
        v34 = this->GetPos(this: &v42, result: this);
        this->m_atRestStartPos.m_x = v34->m_x;
        this->m_atRestStartPos.m_y = v34->m_y;
        this->m_atRestStartPos.m_z = v34->m_z;
        this->m_state = IDLE_AT_REST;
      }
    }
  }
  else
  {
    v13 = this->GetPos(this: &v42, result: this);
    m_commonState = this->m_commonState;
    m_pTune = this->m_pTune;
    v16 = (float)(v13->m_z - this->m_atRestStartPos.m_z);
    v17 = (float)(v13->m_x - this->m_atRestStartPos.m_x);
    m_x = m_commonState->m_surfer.m_areaNormal.m_x;
    v19 = (float)(v13->m_y - this->m_atRestStartPos.m_y);
    m_y = m_commonState->m_surfer.m_areaNormal.m_y;
    m_innerCushion = m_pTune->m_radiusData.m_innerCushion;
    m_outerCushion = m_pTune->m_radiusData.m_outerCushion;
    m_z = m_commonState->m_surfer.m_areaNormal.m_z;
    v42 = m_x;
    v43 = m_y;
    v23 = (float)((float)v16
                - (float)(m_z
                        * (float)((float)(m_x * (float)v17)
                                + (float)((float)(m_z * (float)v16) + (float)(m_y * (float)v19)))));
    v24 = (float)((float)v17
                - (float)((float)((float)(m_x * (float)v17)
                                + (float)((float)(m_z * (float)v16) + (float)(m_y * (float)v19)))
                        * m_x));
    v25 = (float)((float)v19
                - (float)(v43
                        * (float)((float)(m_x * (float)v17)
                                + (float)((float)(m_z * (float)v16) + (float)(v43 * (float)v19)))));
    if ( __fsqrts((float)((float)((float)v25 * (float)v25)
                        + (float)((float)((float)v24 * (float)v24) + (float)((float)v23 * (float)v23)))) > (float)((float)((float)m_innerCushion + (float)m_outerCushion) + m_pTune->m_radiusData.m_radius)
      && this->m_state != IDLE_BEING_PUSHED )
    {
      this->m_vel = bfx::ZERO_VEC;
      v26 = this->m_pWalker;
      if ( v26 != nullptr )
        ((void (__fastcall *)(bfx::Walker *, int))v26->dtr_MotionBase)(a1: v26, a2: 1);
      v27 = this->m_pPath;
      this->m_pWalker = nullptr;
      if ( v27 != nullptr )
        ((void (__fastcall *)(bfx::AreaHandlePath *, int))v27->dtr_Path)(a1: v27, a2: 1);
      this->m_pPath = nullptr;
      this->m_state = IDLE_BEING_PUSHED;
    }
  }
  v35 = (float)(this->m_timeSinceIdleStart + (float)simTime);
  v36 = (float)(this->m_timeSinceLastMoved + (float)simTime);
  v37 = (float)(this->m_refreshInitialOverlapsTimer + (float)simTime);
  this->m_timeSinceIdleStart = this->m_timeSinceIdleStart + (float)simTime;
  this->m_timeSinceLastMoved = v36;
  this->m_refreshInitialOverlapsTimer = v37;
  if ( v35 > 1.0 && !this->m_calculatedInitialOverlaps )
  {
    bfx::IdleImpl::CalcInitialOverlaps(this);
    this->m_calculatedInitialOverlaps = true;
  }
  if ( this->m_refreshInitialOverlapsTimer > 2.0 )
  {
    bfx::IdleImpl::RefreshInitialOverlaps(this);
    this->m_refreshInitialOverlapsTimer = 0.0;
  }
  if ( this->m_state >= (unsigned int)IDLE_GOING_HOME )
  {
    this->m_pWalker->CalcAcc(this: this->m_pWalker, a2: simTime);
    this->m_pWalker->Simulate(this: this->m_pWalker, a2: simTime);
LABEL_56:
    this->m_timeSinceLastMoved = 0.0;
    return;
  }
  bfx::IdleImpl::UpdatePushable(this, simTime);
  v38 = this->m_commonState;
  m_pProxy = v38->m_followData.m_targetMover.m_pProxy;
  v40 = __fsqrts((float)((float)(this->m_vel.m_z * this->m_vel.m_z)
                       + (float)((float)(this->m_vel.m_x * this->m_vel.m_x) + (float)(this->m_vel.m_y * this->m_vel.m_y))));
  if ( m_pProxy != nullptr && m_pProxy->m_pTarget != nullptr )
    m_followSpeedX = v38->m_followData.m_followSpeedX;
  else
    m_followSpeedX = 1.0;
  if ( v40 > (float)((float)((float)((float)(v38->m_pTune->m_speed * v38->m_cautionData.m_internalSpeedX) * v38->m_speedX)
                           * (float)m_followSpeedX)
                   * (float)0.0099999998) )
    goto LABEL_56;
}


// ========================================================================
// __unwind$30516
// EA  : 0x832D95EC
// RVA : 0x012D95EC
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

void _unwind_30516()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 272 + 112));
}


// ========================================================================
// bfx::`dynamic initializer for 'g_drawIdleStateRestore''
// EA  : 0x833998D8
// RVA : 0x013998D8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxidle.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_drawIdleStateRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_drawIdleStateRestore);
  bfx::g_drawIdleStateRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_drawIdleStateRestore.m_targetBool = &bfx::g_drawIdleState;
  bfx::g_drawIdleStateRestore.m_name = "idle_state";
  bfx::g_drawIdleStateRestore.m_defaultBool = bfx::g_drawIdleState;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_drawIdleStateRestore__);
}

