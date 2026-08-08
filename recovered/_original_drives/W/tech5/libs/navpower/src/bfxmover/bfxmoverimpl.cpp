
// ========================================================================
// ?TurnToEnd@MoverImpl@bfx@@QAAXPBVVec3@2@@Z
// EA  : 0x832B7118
// RVA : 0x012B7118
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::TurnToEnd(bfx::MoverImpl *this, const bfx::Vec3 *pForwardVec)
{
  bfx::Walker *m_pWalker; // r11

  m_pWalker = this->m_behavior.m_pWalker;
  if ( m_pWalker != nullptr )
    ((void (*)(void))m_pWalker->TurnToEnd)();
}


// ========================================================================
// ?OkToMoveOntoArea@MoverImpl@bfx@@QBA_NPAVArea@2@@Z
// EA  : 0x832B7150
// RVA : 0x012B7150
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

BOOL __fastcall bfx::MoverImpl::OkToMoveOntoArea(bfx::MoverImpl *this, bfx::Area *pArea)
{
  return this->m_behavior.m_pCurMotion->OkToMoveOntoArea(this: this->m_behavior.m_pCurMotion, a2: pArea);
}


// ========================================================================
// ?MovedOntoArea@MoverImpl@bfx@@QAAXABVVec3@2@PAVArea@2@010@Z
// EA  : 0x832B7168
// RVA : 0x012B7168
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::MovedOntoArea(
        bfx::MoverImpl *this,
        const bfx::Vec3 *oldPos,
        bfx::Area *pOldArea,
        const bfx::Vec3 *newPos,
        bfx::Area *pNewArea,
        const bfx::Vec3 *edgeVec)
{
  this->m_behavior.m_pCurMotion->MovedOntoArea(
    this: this->m_behavior.m_pCurMotion,
    a2: oldPos,
    a3: pOldArea,
    a4: newPos,
    a5: pNewArea,
    a6: edgeVec);
}


// ========================================================================
// ?OnEdge@MoverImpl@bfx@@QAAXABVVec3@2@@Z
// EA  : 0x832B7180
// RVA : 0x012B7180
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::OnEdge(bfx::MoverImpl *this, const bfx::Vec3 *outwardEdgeNormal)
{
  this->m_behavior.m_pCurMotion->OnEdge(this: this->m_behavior.m_pCurMotion, a2: outwardEdgeNormal);
}


// ========================================================================
// ?PushingIntoCorner@MoverImpl@bfx@@QAAXABVVec3@2@0@Z
// EA  : 0x832B7198
// RVA : 0x012B7198
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::PushingIntoCorner(bfx::MoverImpl *this, const bfx::Vec3 *edge1, const bfx::Vec3 *edge2)
{
  this->m_behavior.m_pCurMotion->PushingIntoCorner(this: this->m_behavior.m_pCurMotion, a2: edge1, a3: edge2);
}


// ========================================================================
// ?SetDebugName@MoverImpl@bfx@@QAAXPBD@Z
// EA  : 0x832B71B8
// RVA : 0x012B71B8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::SetDebugName(bfx::MoverImpl *this, const char *name)
{
  bfx::String v3[2]; // [sp+50h] [-20h] BYREF

  bfx::String::String(this: v3, data: name);
  bfx::String::operator=(this: &this->m_debugName, rhs: v3);
  if ( v3[0].m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v3[0].m_data);
}


// ========================================================================
// __unwind$31324
// EA  : 0x832B721C
// RVA : 0x012B721C
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void _unwind_31324()
{
  int v0; // r12

  bfx::String::~String(this: (bfx::String *)(v0 - 112 + 80));
}


// ========================================================================
// ?IgnoreGotoPosDueToSimilarParams@MoverImpl@bfx@@AAA_NABVVec3@2@0ABVGPSpec@2@M@Z
// EA  : 0x832B7248
// RVA : 0x012B7248
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall bfx::MoverImpl::IgnoreGotoPosDueToSimilarParams(
        bfx::MoverImpl *this,
        const bfx::Vec3 *oldGoalPos,
        const bfx::Vec3 *newGoalPos,
        const bfx::GPSpec *newGotoPosSpec,
        double ignoreThresholdDist)
{
  double v6; // fp12
  double v7; // fp9
  double v8; // fp6
  bfx::MoverImpl::State m_state; // r11
  double v10; // fp12
  double v12; // fp9
  double v13; // fp6
  long double v15; // fp2
  int result; // r3
  double v17; // fp12
  double v18; // fp9
  double v19; // fp12
  double v20; // fp9
  double v21; // fp6
  float v22; // [sp+50h] [-20h] BYREF
  float v23; // [sp+54h] [-1Ch]
  float v24; // [sp+58h] [-18h]

  if ( newGotoPosSpec->m_desiredStopDist > 0.0 )
  {
    v6 = (float)(newGoalPos->m_y - this->m_commonState.m_surfer.m_pos.m_y);
    v7 = (float)(newGoalPos->m_z - this->m_commonState.m_surfer.m_pos.m_z);
    v8 = (float)(newGoalPos->m_x - this->m_commonState.m_surfer.m_pos.m_x);
    if ( (float)((float)((float)v8 * (float)v8)
               + (float)((float)((float)v7 * (float)v7) + (float)((float)v6 * (float)v6))) <= (double)(float)(newGotoPosSpec->m_desiredStopDist * newGotoPosSpec->m_desiredStopDist) )
      return 1;
  }
  m_state = this->m_behavior.m_state;
  if ( m_state != PATH_WALKING && m_state != JUMPING )
  {
    v10 = (float)(newGoalPos->m_y - this->m_commonState.m_surfer.m_pos.m_y);
    _FP4 = (float)((float)ignoreThresholdDist - newGotoPosSpec->m_allowedToStopDist);
    v12 = (float)(newGoalPos->m_z - this->m_commonState.m_surfer.m_pos.m_z);
    v13 = (float)(newGoalPos->m_x - this->m_commonState.m_surfer.m_pos.m_x);
    __asm { fsel      f2, f4, f5, f1 }
    if ( __fsqrts((float)((float)((float)v13 * (float)v13)
                        + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10)))) < _FP2 )
    {
      if ( !newGotoPosSpec->m_orientAtGoalEnable )
        return 1;
      *(double *)&v15 = (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10));
      bfx::Orienter::GetForward(
        this: (bfx::Orienter *)&v22,
        result: (bfx::Vec3 *)&this->m_commonState.m_orienter,
        a3: v15);
      if ( __fsqrts((float)((float)((float)(newGotoPosSpec->m_orientAtGoalDir.m_x - v22)
                                  * (float)(newGotoPosSpec->m_orientAtGoalDir.m_x - v22))
                          + (float)((float)((float)(newGotoPosSpec->m_orientAtGoalDir.m_z - v24)
                                          * (float)(newGotoPosSpec->m_orientAtGoalDir.m_z - v24))
                                  + (float)((float)(newGotoPosSpec->m_orientAtGoalDir.m_y - v23)
                                          * (float)(newGotoPosSpec->m_orientAtGoalDir.m_y - v23))))) < 0.050000001 )
        return 1;
    }
    return 0;
  }
  v17 = (float)(oldGoalPos->m_y - newGoalPos->m_y);
  v18 = (float)(oldGoalPos->m_z - newGoalPos->m_z);
  if ( __fsqrts((float)((float)((float)(oldGoalPos->m_x - newGoalPos->m_x) * (float)(oldGoalPos->m_x - newGoalPos->m_x))
                      + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)))) >= ignoreThresholdDist )
    return 0;
  if ( !newGotoPosSpec->m_orientAtGoalEnable )
    return 1;
  v19 = (float)(newGotoPosSpec->m_orientAtGoalDir.m_y - this->m_lastGoalDirActedOn.m_y);
  v20 = (float)(newGotoPosSpec->m_orientAtGoalDir.m_z - this->m_lastGoalDirActedOn.m_z);
  v21 = (float)(newGotoPosSpec->m_orientAtGoalDir.m_x - this->m_lastGoalDirActedOn.m_x);
  result = 1;
  if ( __fsqrts((float)((float)((float)v21 * (float)v21)
                      + (float)((float)((float)v20 * (float)v20) + (float)((float)v19 * (float)v19)))) >= 0.050000001 )
    return 0;
  return result;
}


// ========================================================================
// ?ForcePathUpdateDueToSpecChange@MoverImpl@bfx@@AAA_NABVGPSpec@2@0@Z
// EA  : 0x832B7428
// RVA : 0x012B7428
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

int __fastcall bfx::MoverImpl::ForcePathUpdateDueToSpecChange(
        bfx::MoverImpl *this,
        const bfx::GPSpec *oldSpec,
        const bfx::GPSpec *newSpec)
{
  if ( this->m_behavior.m_state == PATH_WALKING )
  {
    if ( oldSpec->m_allowedToStopDist != newSpec->m_allowedToStopDist
      || oldSpec->m_desiredStopDist != newSpec->m_desiredStopDist
      || oldSpec->m_stopAtGoal != newSpec->m_stopAtGoal
      || oldSpec->m_pushThroughCrowdAtGoal != newSpec->m_pushThroughCrowdAtGoal
      || oldSpec->m_orientAtGoalEnable != newSpec->m_orientAtGoalEnable )
    {
      return 1;
    }
  }
  else if ( newSpec->m_allowedToStopDist < (double)oldSpec->m_allowedToStopDist
         || newSpec->m_desiredStopDist < (double)oldSpec->m_desiredStopDist )
  {
    return 1;
  }
  return 0;
}


// ========================================================================
// ?SetFollowMover@CommandData@bfx@@QAAXABVFMSpec@2@@Z
// EA  : 0x832B74B8
// RVA : 0x012B74B8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::CommandData::SetFollowMover(bfx::CommandData *this, const bfx::FMSpec *spec)
{
  this->m_command = FOLLOW_COMMAND;
  this->m_fmSpec = *spec;
}


// ========================================================================
// ??0MoverSaveRestoreState@bfx@@QAA@XZ
// EA  : 0x832B74E0
// RVA : 0x012B74E0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

bfx::MoverSaveRestoreState *__fastcall bfx::MoverSaveRestoreState::MoverSaveRestoreState(
        bfx::MoverSaveRestoreState *this)
{
  bfx::CommandData::CommandData(this: &this->m_lastMovementCommand);
  this->m_orientCmd.m_mode = ORIENT_IN_TRAVEL_DIR;
  this->m_orientCmd.m_vec = bfx::ZERO_VEC;
  this->m_frozen = false;
  this->m_frozenTranslation = false;
  this->m_inPuppetMode = false;
  return this;
}


// ========================================================================
// ?CSMove@MoverImpl@bfx@@SAXPAXABVVec3@2@M@Z
// EA  : 0x832B7548
// RVA : 0x012B7548
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::CSMove(char *pObject, const bfx::Vec3 *vel, double time)
{
  _DWORD *v4; // r11

  if ( pObject != nullptr )
  {
    if ( *((_DWORD *)pObject + 188) == 4 )
    {
      (*(void (__fastcall **)(_DWORD, const bfx::Vec3 *, double))(**((_DWORD **)pObject + 193) + 92))(
        a1: *((_DWORD *)pObject + 193),
        a2: vel,
        a3: time);
    }
    else
    {
      v4 = *((_DWORD **)pObject + 84);
      if ( v4 != nullptr && *v4 != 0 )
      {
        bfx::Surfer::Move(this: (bfx::Surfer *)(pObject + 320), origVel: vel, time);
        bfx::SmartPath::SetStartData(
          this: *((bfx::SmartPath **)pObject + 101),
          startPos: (const bfx::Vec3 *)pObject + 27,
          pStartArea: nullptr);
      }
    }
  }
}


// ========================================================================
// ?CSGetPos@MoverImpl@bfx@@SA?BVVec3@2@PAX@Z
// EA  : 0x832B75E0
// RVA : 0x012B75E0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

const bfx::Vec3 *__fastcall bfx::MoverImpl::CSGetPos(bfx::Vec3 *result, bfx::Vec3 *pObject)
{
  float m_z; // r11
  bfx::Vec3 *m_y_low; // r11

  if ( pObject != nullptr )
  {
    m_z = pObject[62].m_z;
    if ( LODWORD(m_z) == 3 )
    {
      m_y_low = (bfx::Vec3 *)LODWORD(pObject[33].m_y);
      if ( m_y_low != nullptr )
      {
        *result = m_y_low[1];
        return result;
      }
    }
    else if ( LODWORD(m_z) == 4 )
    {
      (*(void (__fastcall **)(bfx::Vec3 *))(*(_DWORD *)LODWORD(pObject[64].m_y) + 24))(a1: result);
      return result;
    }
    *result = pObject[27];
    return result;
  }
  *result = bfx::ZERO_VEC;
  return result;
}


// ========================================================================
// ?RecordDeferredCommand@MoverImpl@bfx@@AAA_NXZ
// EA  : 0x832B7770
// RVA : 0x012B7770
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

int __fastcall bfx::MoverImpl::RecordDeferredCommand(bfx::MoverImpl *this)
{
  bfx::MoverImpl::State m_state; // r11
  int result; // r3

  m_state = this->m_behavior.m_state;
  if ( m_state == JUMPING )
    this->m_applyCommandOnJumpEnd = true;
  if ( m_state == PUPPET )
    this->m_applyCommandOnPuppetDisable = true;
  if ( m_state == JUMPING )
    return 1;
  result = 0;
  if ( m_state == PUPPET )
    return 1;
  return result;
}


// ========================================================================
// ?IsBlockedByRepulsor@MoverImpl@bfx@@QBA_NXZ
// EA  : 0x832B77B0
// RVA : 0x012B77B0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

BOOL __fastcall bfx::MoverImpl::IsBlockedByRepulsor(bfx::MoverImpl *this)
{
  bfx::Locomoter *m_pLocomoter; // r11

  m_pLocomoter = this->m_behavior.m_pLocomoter;
  if ( m_pLocomoter != nullptr )
    return ((bool (*)(void))m_pLocomoter->IsBlockedByRepulsor)();
  else
    return this->m_commonState.m_blockedMonitor.m_blockedTimer > 2.0;
}


// ========================================================================
// ?Freeze@MoverImpl@bfx@@QAAX_N@Z
// EA  : 0x832B77F8
// RVA : 0x012B77F8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::Freeze(bfx::MoverImpl *this, bool freeze)
{
  *((_BYTE *)this + 872) = (freeze << 6) & 0x40 | *((_BYTE *)this + 872) & 0xBF;
}


// ========================================================================
// ?SetPuppetPos@MoverImpl@bfx@@QAAXABVVec3@2@@Z
// EA  : 0x832B7810
// RVA : 0x012B7810
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall bfx::MoverImpl::SetPuppetPos(
        bfx::MoverImpl *this,
        const bfx::Vec3 *pos,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9)
{
  int v9; // r3
  int v10; // r3
  const char *v11; // r3

  if ( *(_DWORD *)(v9 + 752) == 4 )
  {
    (*(void (__fastcall **)(_DWORD, const bfx::Vec3 *))(**(_DWORD **)(v10 + 772) + 84))(
      a1: *(_DWORD *)(v10 + 772),
      a2: pos);
  }
  else
  {
    v11 = "SetPuppetPos() ignored (called while not in puppet mode)\n";
    bfx::InternalWarning(fmt: *(__int64 *)&pos, a2: a3, a3: a4, a4: a5, a5: a6, a6: a7, a7: a8, a8: a9);
  }
}


// ========================================================================
// ?SetPuppetRot@MoverImpl@bfx@@QAAXABVQuat@2@@Z
// EA  : 0x832B7840
// RVA : 0x012B7840
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall bfx::MoverImpl::SetPuppetRot(
        bfx::MoverImpl *this,
        const bfx::Quat *rot,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8,
        int a9)
{
  int v9; // r3
  int v10; // r3
  const char *v11; // r3

  if ( *(_DWORD *)(v9 + 752) == 4 )
  {
    (*(void (__fastcall **)(_DWORD, const bfx::Quat *))(**(_DWORD **)(v10 + 772) + 88))(
      a1: *(_DWORD *)(v10 + 772),
      a2: rot);
  }
  else
  {
    v11 = "SetPuppetRot() ignored (called while not in puppet mode)\n";
    bfx::InternalWarning(fmt: *(__int64 *)&rot, a2: a3, a3: a4, a4: a5, a5: a6, a6: a7, a7: a8, a8: a9);
  }
}


// ========================================================================
// ?SetCustomLinkPos@MoverImpl@bfx@@QAAXABVVec3@2@@Z
// EA  : 0x832B7870
// RVA : 0x012B7870
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall bfx::MoverImpl::SetCustomLinkPos(
        bfx::MoverImpl *this,
        const bfx::Vec3 *pos,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  int v5; // r3
  int v6; // r31
  int v8; // r3
  const char *v9; // r3
  int v10; // [sp+8h] [-68h]
  int v11; // [sp+Ch] [-64h]
  int v12; // [sp+10h] [-60h]
  int v13; // [sp+14h] [-5Ch]

  v6 = v5;
  if ( *(_DWORD *)(v5 + 752) == 3
    && (HIDWORD(a5) = (*(unsigned __int8 (__fastcall **)(_DWORD))(**(_DWORD **)(v8 + 764) + 112))(a1: *(_DWORD *)(v8 + 764)),
        HIDWORD(a5) != 0) )
  {
    (*(void (__fastcall **)(_DWORD, const bfx::Vec3 *))(**(_DWORD **)(v6 + 764) + 100))(
      a1: *(_DWORD *)(v6 + 764),
      a2: pos);
  }
  else
  {
    v9 = "SetCustomLinkPos() ignored (called while not in custom link mode)\n";
    bfx::InternalWarning(fmt: *(__int64 *)&pos, a2: a3, a3: a4, a4: a5, a5: v10, a6: v11, a7: v12, a8: v13);
  }
}


// ========================================================================
// ?SetCustomLinkRot@MoverImpl@bfx@@QAAXABVQuat@2@@Z
// EA  : 0x832B78F8
// RVA : 0x012B78F8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall bfx::MoverImpl::SetCustomLinkRot(
        bfx::MoverImpl *this,
        const bfx::Quat *rot,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  int v5; // r3
  int v6; // r31
  int v8; // r3
  const char *v9; // r3
  int v10; // [sp+8h] [-68h]
  int v11; // [sp+Ch] [-64h]
  int v12; // [sp+10h] [-60h]
  int v13; // [sp+14h] [-5Ch]

  v6 = v5;
  if ( *(_DWORD *)(v5 + 752) == 3
    && (HIDWORD(a5) = (*(unsigned __int8 (__fastcall **)(_DWORD))(**(_DWORD **)(v8 + 764) + 112))(a1: *(_DWORD *)(v8 + 764)),
        HIDWORD(a5) != 0) )
  {
    (*(void (__fastcall **)(_DWORD, const bfx::Quat *))(**(_DWORD **)(v6 + 764) + 104))(
      a1: *(_DWORD *)(v6 + 764),
      a2: rot);
  }
  else
  {
    v9 = "SetCustomLinkRot() ignored (called while not in custom link mode)\n";
    bfx::InternalWarning(fmt: *(__int64 *)&rot, a2: a3, a3: a4, a4: a5, a5: v10, a6: v11, a7: v12, a8: v13);
  }
}


// ========================================================================
// ?SwapToDefaultJump@MoverImpl@bfx@@QAAXPBM@Z
// EA  : 0x832B7980
// RVA : 0x012B7980
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall bfx::MoverImpl::SwapToDefaultJump(
        bfx::MoverImpl *this,
        float *pInitialSpeed,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  int v5; // r3
  int v6; // r31
  int v8; // r3
  double Scale; // fp1
  __int64 v10; // r10
  __int64 v11; // r8
  int v12; // r5
  int v13; // r4
  const char *v14; // r3
  int v15; // r3
  const char *v16; // r3
  int v17; // [sp+8h] [-68h]
  int v18; // [sp+Ch] [-64h]
  int v19; // [sp+10h] [-60h]
  int v20; // [sp+14h] [-5Ch]
  float v21[2]; // [sp+50h] [-20h] BYREF

  v6 = v5;
  if ( *(_DWORD *)(v5 + 752) == 3
    && (HIDWORD(a5) = (*(unsigned __int8 (__fastcall **)(_DWORD))(**(_DWORD **)(v8 + 764) + 112))(a1: *(_DWORD *)(v8 + 764)),
        HIDWORD(a5) != 0) )
  {
    if ( pInitialSpeed != nullptr )
    {
      v21[0] = *pInitialSpeed;
      Scale = bfx::GetScale();
      LODWORD(v10) = &dword_82420000;
      HIDWORD(v10) = &dword_82420000;
      v21[0] = bfx::LimitWarn(
                 val: v21[0],
                 min: (float)((float)Scale * (float)0.1),
                 max: 3.4028235e38,
                 name: v14,
                 a5: v13,
                 a6: v12,
                 a7: (unsigned int)"Mover::SwapToDefaultJump() pInitialSpeed",
                 a8: v11,
                 a9: v10);
      (*(void (__fastcall **)(_DWORD, float *))(**(_DWORD **)(v6 + 764) + 116))(a1: *(_DWORD *)(v6 + 764), a2: v21);
    }
    else
    {
      v15 = *(_DWORD *)(v6 + 764);
      if ( *(_BYTE *)(*(_DWORD *)(v6 + 308) + 148) != 0 )
      {
        v21[0] = __fsqrts((float)((float)(*(float *)(v6 + 1060) * *(float *)(v6 + 1060))
                                + (float)((float)(*(float *)(v6 + 1052) * *(float *)(v6 + 1052))
                                        + (float)(*(float *)(v6 + 1056) * *(float *)(v6 + 1056)))));
        (*(void (__fastcall **)(int, float *))(*(_DWORD *)v15 + 116))(a1: v15, a2: v21);
      }
      else
      {
        (*(void (__fastcall **)(int, _DWORD))(*(_DWORD *)v15 + 116))(a1: v15, a2: 0);
      }
    }
  }
  else
  {
    v16 = "SwapToDefaultJump() ignored (called while not in custom link mode)\n";
    bfx::InternalWarning(fmt: *(__int64 *)&pInitialSpeed, a2: a3, a3: a4, a4: a5, a5: v17, a6: v18, a7: v19, a8: v20);
  }
}


// ========================================================================
// ?FreezeTranslation@MoverImpl@bfx@@QAAX_N@Z
// EA  : 0x832B7AA8
// RVA : 0x012B7AA8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::FreezeTranslation(bfx::MoverImpl *this, bool freeze)
{
  *((_BYTE *)this + 872) = (32 * freeze) & 0x20 | *((_BYTE *)this + 872) & 0xDF;
}


// ========================================================================
// ?IsTurningInPlace@MoverImpl@bfx@@QBA_NPAVTurningInPlaceData@2@@Z
// EA  : 0x832B7AC0
// RVA : 0x012B7AC0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

BOOL __fastcall bfx::MoverImpl::IsTurningInPlace(bfx::MoverImpl *this, bfx::TurningInPlaceData *pDataOut)
{
  bfx::MotionBase *m_pCurMotion; // r11

  if ( pDataOut != nullptr )
  {
    pDataOut->m_degreesToTarget = 0.0;
    pDataOut->m_turnTime = 0.0;
    pDataOut->m_desiredDirectionVec = ZERO_VECTOR_57;
  }
  m_pCurMotion = this->m_behavior.m_pCurMotion;
  return m_pCurMotion != nullptr && ((bool (*)(void))m_pCurMotion->IsTurningInPlace)();
}


// ========================================================================
// ?IsPuppet@MoverImpl@bfx@@QBA_NXZ
// EA  : 0x832B7B20
// RVA : 0x012B7B20
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

BOOL __fastcall bfx::MoverImpl::IsPuppet(bfx::MoverImpl *this)
{
  return (_cntlzw(this->m_behavior.m_state - 4) & 0x20) != 0;
}


// ========================================================================
// ?GetLinkDirection@bfx@@YA?AVVec3@1@ABV21@PAVHalfLink@1@@Z
// EA  : 0x832B7B38
// RVA : 0x012B7B38
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

bfx::Vec3 *__fastcall bfx::GetLinkDirection(bfx::Vec3 *result, const bfx::Vec3 *myPos, bfx::HalfLink *pLink)
{
  char *v3; // r10
  bfx::HandleProxy **p_m_pProxy; // r11
  int i; // ctr
  double v8; // fp9
  double v9; // fp6
  bfx::Vec3 v13; // [sp+50h] [-50h] BYREF
  bfx::Vec3 v14; // [sp+60h] [-40h] BYREF
  char v15; // [sp+6Ch] [-34h] BYREF
  bfx::LineSeg v16; // [sp+70h] [-30h] BYREF

  v3 = &v15;
  p_m_pProxy = &pLink->m_pProxy;
  for ( i = 6; i != 0; --i )
  {
    ++p_m_pProxy;
    v3 += 4;
    *(_DWORD *)v3 = *p_m_pProxy;
  }
  bfx::GetClosestPtOnLineSeg(result: &v13, seg: &v16, pos: myPos);
  bfx::GetLinkOutputPos(result: &v14, pLink, posOnLinkStart: &v13);
  v8 = (float)(v14.m_y - v13.m_y);
  v9 = (float)(v14.m_z - v13.m_z);
  _FP8 = (float)((float)__fsqrts((float)((float)((float)(v14.m_x - v13.m_x) * (float)(v14.m_x - v13.m_x))
                                       + (float)((float)((float)(v14.m_z - v13.m_z) * (float)(v14.m_z - v13.m_z))
                                               + (float)((float)(v14.m_y - v13.m_y) * (float)(v14.m_y - v13.m_y)))))
               - (float)1.0842022e-19);
  __asm { fsel      f5, f8, f7, f12 }
  result->m_x = (float)(v14.m_x - v13.m_x) * (float)_FP5;
  result->m_y = (float)v8 * (float)_FP5;
  result->m_z = (float)v9 * (float)_FP5;
  return result;
}


// ========================================================================
// ?UpdateVel@MoverImpl@bfx@@AAAXM@Z
// EA  : 0x832B7C20
// RVA : 0x012B7C20
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::UpdateVel(bfx::MoverImpl *this, double simTime)
{
  double v4; // fp10
  double v5; // fp9
  double v6; // fp8
  double v7; // fp13
  double v8; // fp12
  bfx::Vec3 *v9; // r10
  float v10; // [sp+50h] [-30h] BYREF
  float v11; // [sp+54h] [-2Ch]
  float v12; // [sp+58h] [-28h]

  ((void (__fastcall *)(float *))this->m_behavior.m_pCurMotion->GetPos)(a1: &v10);
  v4 = v10;
  v5 = v11;
  v6 = v12;
  v7 = (float)(v11 - this->m_prevPos.m_y);
  v8 = (float)(v12 - this->m_prevPos.m_z);
  if ( simTime <= 1.0842022e-19 )
  {
    v9 = &bfx::ZERO_VEC;
  }
  else
  {
    v9 = (bfx::Vec3 *)&v10;
    v10 = (float)((float)1.0 / (float)simTime) * (float)(v10 - this->m_prevPos.m_x);
    v11 = (float)((float)1.0 / (float)simTime) * (float)v7;
    v12 = (float)((float)1.0 / (float)simTime) * (float)v8;
  }
  this->m_vel.m_x = v9->m_x;
  this->m_vel.m_y = v9->m_y;
  this->m_vel.m_z = v9->m_z;
  this->m_prevPos.m_x = v4;
  this->m_prevPos.m_y = v5;
  this->m_prevPos.m_z = v6;
}


// ========================================================================
// ?GetInitialConstraint@MoverImpl@bfx@@QAAXAAVInitialConstraint@2@@Z
// EA  : 0x832B7D00
// RVA : 0x012B7D00
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::GetInitialConstraint(bfx::MoverImpl *this, bfx::InitialConstraint *initialConstraint)
{
  bfx::MotionBase *m_pCurMotion; // r11

  initialConstraint->m_constraintType = CONSTRAINT_POINT;
  if ( !this->m_stranded && (*((_BYTE *)this + 872) & 0x40) == 0 && (*((_BYTE *)this + 872) & 0x20) == 0 )
  {
    m_pCurMotion = this->m_behavior.m_pCurMotion;
    if ( m_pCurMotion != nullptr )
      ((void (*)(void))m_pCurMotion->GetInitialConstraint)();
  }
}


// ========================================================================
// ?EndOfFrameUpdate@MoverImpl@bfx@@UAAXM@Z
// EA  : 0x832B7D58
// RVA : 0x012B7D58
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::EndOfFrameUpdate(bfx::MoverImpl *this, double simTimeIn)
{
  bfx::RepulsorImpl *m_pRepulsor; // r11
  double v4; // fp31
  bfx::MotionBase *m_pCurMotion; // r11
  bfx::RepulsorImpl *v7; // r30
  bfx::Vec3 v8; // [sp+50h] [-30h] BYREF

  if ( simTimeIn != 0.0 )
  {
    m_pRepulsor = this->m_commonState.m_pRepulsor;
    v4 = (float)(this->m_commonState.m_slowTime * (float)simTimeIn);
    if ( m_pRepulsor != nullptr && m_pRepulsor->m_posModifiedBySolver )
    {
      m_pCurMotion = this->m_behavior.m_pCurMotion;
      if ( m_pCurMotion != nullptr )
        ((void (*)(void))m_pCurMotion->EndOfFrameUpdate)();
      v7 = this->m_commonState.m_pRepulsor;
      if ( v7 != nullptr )
      {
        ((void (__fastcall *)(bfx::Vec3 *))this->m_behavior.m_pCurMotion->GetPos)(a1: &v8);
        bfx::RepulsorImpl::SetPos(this: v7, pos: &v8);
      }
    }
    bfx::MoverImpl::UpdateVel(this, simTime: v4);
    bfx::MoverImpl::CalculateFollowMoverPositions(this, simTime: v4);
  }
}


// ========================================================================
// ?GetRepulsorNormal@MoverImpl@bfx@@UAA_NAAVVec3@2@@Z
// EA  : 0x832B7E38
// RVA : 0x012B7E38
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

BOOL __fastcall bfx::MoverImpl::GetRepulsorNormal(bfx::MoverImpl *this, bfx::Vec3 *normalOut)
{
  return this->m_commonState.m_randPrev != 4
      && bfx::Surfer::GetAreaNormal(this: (bfx::Surfer *)&this->m_commonState.m_replayID, normalOut);
}


// ========================================================================
// ?ApplyLimits_GotoPosSpec@MoverImpl@bfx@@AAAXAAVGPSpec@2@@Z
// EA  : 0x832B7E58
// RVA : 0x012B7E58
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::ApplyLimits_GotoPosSpec(
        bfx::MoverImpl *this,
        bfx::GPSpec *spec,
        int a3,
        int a4,
        __int64 a5,
        __int64 a6)
{
  bfx::MoverImpl *v6; // r30
  __int64 v8; // r10
  __int64 v9; // r8
  int v10; // r5
  int v11; // r4
  const char *v12; // r3
  bfx::GPSpec v13; // [sp+50h] [-50h] BYREF

  v6 = this;
  if ( spec->m_allowedToStopDist < 0.0 )
  {
    this = (bfx::MoverImpl *)bfx::GPSpec::GPSpec(this: &v13);
    spec->m_allowedToStopDist = *(float *)&this->bfx::HandleTargetBase::__vftable;
  }
  spec->m_desiredStopDist = bfx::LimitWarn(
                              val: spec->m_desiredStopDist,
                              min: 0.0,
                              max: 3.4028235e38,
                              name: (const char *)this,
                              a5: (int)spec,
                              a6: a3,
                              a7: (unsigned int)"m_desiredStopDist",
                              a8: a5,
                              a9: a6);
  LODWORD(v8) = &unk_82150000;
  HIDWORD(v8) = v6->m_pTune;
  LODWORD(v9) = &unk_82340000;
  spec->m_allowedToStopDist = bfx::LimitWarn(
                                val: spec->m_allowedToStopDist,
                                min: (float)(*(float *)(HIDWORD(v8) + 8) * (float)0.25),
                                max: 3.4028235e38,
                                name: v12,
                                a5: v11,
                                a6: v10,
                                a7: (unsigned int)"m_allowedToStopDist",
                                a8: v9,
                                a9: v8);
}


// ========================================================================
// ?Initialize@MoverBehavior@MoverImpl@bfx@@QAAXABVVec3@3@ABVQuat@3@PAVArea@3@AAVMotionState@3@_N@Z
// EA  : 0x832B7EF0
// RVA : 0x012B7EF0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::MoverBehavior::Initialize(
        bfx::MoverImpl::MoverBehavior *this,
        const bfx::Vec3 *pos,
        const bfx::Quat *rot,
        bfx::Area *pStartArea,
        bfx::MotionState *commonState,
        bool preserveExactInputHeight)
{
  bfx::Idle *v10; // r3
  bfx::Matrix v11; // [sp+50h] [-70h] BYREF

  bfx::Matrix::Build(this: &v11, q: rot, pos);
  v10 = bfx::CreateIdle(startMat: &v11, pStartArea, commonState, preserveExactInputHeight);
  this->m_pIdle = v10;
  this->m_pCurMotion = v10;
  this->m_state = 0;
}


// ========================================================================
// ?SwitchState@MoverBehavior@MoverImpl@bfx@@QAAXW4State@23@ABVMatrix@3@PAVArea@3@AAVMotionState@3@@Z
// EA  : 0x832B7F50
// RVA : 0x012B7F50
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::MoverBehavior::SwitchState(
        bfx::MoverImpl::MoverBehavior *this,
        bfx::MoverImpl::State newState,
        const bfx::Matrix *startMat,
        bfx::Area *pStartArea,
        bfx::MotionState *commonState)
{
  bfx::MotionBase *m_pCurMotion; // r3
  bfx::Puppet *Puppet; // r3
  bfx::Walker *Walker; // r3
  bfx::Locomoter *Locomoter; // r3
  bfx::JumperImpl *Jumper; // r3

  m_pCurMotion = this->m_pCurMotion;
  if ( m_pCurMotion != nullptr )
    ((void (__fastcall *)(bfx::MotionBase *, int))m_pCurMotion->dtr_MotionBase)(a1: m_pCurMotion, a2: 1);
  this->m_state = newState;
  this->m_pCurMotion = nullptr;
  this->m_pWalker = nullptr;
  this->m_pLocomoter = nullptr;
  this->m_pJumper = nullptr;
  this->m_pIdle = nullptr;
  this->m_pPuppet = nullptr;
  if ( (unsigned int)newState <= PUPPET )
  {
    switch ( newState )
    {
      case PATH_WALKING:
        Walker = bfx::CreateWalker(mat: startMat, commonState);
        this->m_pWalker = Walker;
        this->m_pCurMotion = Walker;
        break;
      case LOCOMOTING:
        Locomoter = bfx::CreateLocomoter(startMat, pStartArea, commonState);
        this->m_pLocomoter = Locomoter;
        this->m_pCurMotion = Locomoter;
        break;
      case JUMPING:
        Jumper = bfx::CreateJumper(startMat, commonState);
        this->m_pJumper = Jumper;
        this->m_pCurMotion = Jumper;
        break;
      default:
        if ( newState != 0 )
        {
          Puppet = bfx::CreatePuppet(startMat, commonState);
          this->m_pPuppet = Puppet;
        }
        else
        {
          Puppet = (bfx::Puppet *)bfx::CreateIdle(startMat, pStartArea, commonState, preserveExactInputHeight: false);
          this->m_pIdle = (bfx::Idle *)Puppet;
        }
        this->m_pCurMotion = Puppet;
        break;
    }
  }
}


// ========================================================================
// ?DrawMoverGoals@MotionState@bfx@@QBA_NXZ
// EA  : 0x832B8068
// RVA : 0x012B8068
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

int __fastcall bfx::MotionState::DrawMoverGoals(bfx::MotionState *this)
{
  unsigned __int8 v1; // r11

  if ( BYTE1(bfx::g_pCurInstance->m_pComponentManager->m_components[4][8].dtr_InstanceComponent) != 0 )
    return 1;
  v1 = 0;
  if ( (this->m_debugFlags & 1) != 0 )
    return 1;
  return v1;
}


// ========================================================================
// ?DrawMoverGoalsReached@MotionState@bfx@@QBA_NXZ
// EA  : 0x832B80A8
// RVA : 0x012B80A8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

int __fastcall bfx::MotionState::DrawMoverGoalsReached(bfx::MotionState *this)
{
  unsigned __int8 v1; // r11

  if ( BYTE2(bfx::g_pCurInstance->m_pComponentManager->m_components[4][8].dtr_InstanceComponent) != 0 )
    return 1;
  v1 = 0;
  if ( (this->m_debugFlags & 2) != 0 )
    return 1;
  return v1;
}


// ========================================================================
// ?ReattachSurfer@MoverImpl@bfx@@QAA_NXZ
// EA  : 0x832B80E8
// RVA : 0x012B80E8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

int __fastcall bfx::MoverImpl::ReattachSurfer(bfx::MoverImpl *this)
{
  bfx::AreaProxy *m_pProxy; // r11
  char v3; // r29
  bfx::MotionBase *m_pCurMotion; // r4
  __int64 v5; // r10
  __int64 v6; // r8
  __int64 v7; // r6
  bfx::Vec3 *ClosestArea; // r3
  bfx::Area *v9; // r30
  long double v10; // fp2
  unsigned int m_planLayer; // r11
  bfx::NavLayer *v12; // r30
  bfx::Orienter *LocalUpAxis; // r3
  double v14; // fp13
  double v15; // fp12
  __int64 v16; // r4
  int v18; // [sp+8h] [-E8h]
  int v19; // [sp+Ch] [-E4h]
  int v20; // [sp+10h] [-E0h]
  int v21; // [sp+14h] [-DCh]
  bfx::Vec3 v22; // [sp+50h] [-A0h] BYREF
  bfx::Vec3 v23; // [sp+60h] [-90h] BYREF
  float v24[4]; // [sp+70h] [-80h] BYREF
  char v25; // [sp+80h] [-70h] BYREF
  bfx::PathSpec v26; // [sp+90h] [-60h] BYREF

  if ( !this->m_stranded )
  {
    m_pProxy = this->m_commonState.m_surfer.m_area.m_pProxy;
    if ( m_pProxy != nullptr && m_pProxy->m_pArea != nullptr )
      return 1;
  }
  bfx::BuildMoverPathSpec(result: &v26, pTune: this->m_pTune);
  v3 = 0;
  m_pCurMotion = this->m_behavior.m_pCurMotion;
  v26.m_obstacleBlockageFlags = 0;
  ((void (__fastcall *)(bfx::Vec3 *))m_pCurMotion->GetPos)(a1: &v22);
  ClosestArea = (bfx::Vec3 *)bfx::Planner::GetClosestArea(
                               this: *((bfx::Planner **)this->m_pSpace->m_components.m_data + 1),
                               pos: &v22,
                               layerNum: this->m_pTune->m_planLayer,
                               pathSpec: &v26);
  v9 = (bfx::Area *)ClosestArea;
  if ( ClosestArea != nullptr )
  {
    bfx::GetClosestPosInArea(result: &v23, pArea: ClosestArea, pos: &v22, pEdgeIndexOut: nullptr);
    if ( __fsqrts((float)((float)((float)(v23.m_x - v22.m_x) * (float)(v23.m_x - v22.m_x))
                        + (float)((float)((float)(v23.m_z - v22.m_z) * (float)(v23.m_z - v22.m_z))
                                + (float)((float)(v23.m_y - v22.m_y) * (float)(v23.m_y - v22.m_y))))) < (float)(bfx::GetScale() * (float)10.0) )
    {
      bfx::Surfer::SetPosAndArea(this: &this->m_commonState.m_surfer, pos: &v23, pArea: v9);
      bfx::SmartPath::SetStartData(this: this->m_commonState.m_pSmartPath, startPos: &v23, pStartArea: v9);
      bfx::Orienter::TeleportToArea(this: &this->m_commonState.m_orienter, pArea: (bfx::Vec3 *)v9, a3: v10);
      if ( this->m_commonState.m_pProber != nullptr )
      {
        m_planLayer = this->m_commonState.m_pTune->m_planLayer;
        if ( m_planLayer >= 0x20 )
          v12 = nullptr;
        else
          v12 = *(bfx::NavLayer **)(*((_DWORD *)this->m_pSpace->m_components.m_data + 1) + 4 * (m_planLayer + 2));
        LocalUpAxis = bfx::Orienter::GetLocalUpAxis(
                        this: (bfx::Orienter *)&v25,
                        result: (bfx::Vec3 *)&this->m_commonState.m_orienter);
        bfx::Prober::TeleportToArea(
          this: this->m_commonState.m_pProber,
          pNavLayer: v12,
          surferPos: &this->m_commonState.m_surfer.m_pos,
          localUpAxis: (const bfx::Vec3 *)LocalUpAxis);
      }
      this->m_stranded = false;
      v3 = 1;
      ((void (__fastcall *)(float *))this->m_behavior.m_pCurMotion->GetPos)(a1: v24);
      v14 = v24[1];
      v15 = v24[2];
      this->m_prevPos.m_x = v24[0];
      this->m_prevPos.m_y = v14;
      this->m_prevPos.m_z = v15;
    }
  }
  if ( v3 != 0 )
    return 1;
  if ( !this->m_stranded )
  {
    LODWORD(v5) = &dword_82420000;
    HIDWORD(v16) = "NavGraph in layer %d was removed while a mover was still using it\n";
    LODWORD(v16) = this->m_pTune->m_planLayer;
    bfx::InternalWarning(fmt: v16, a2: v7, a3: v6, a4: v5, a5: v18, a6: v19, a7: v20, a8: v21);
  }
  this->m_stranded = true;
  return 0;
}


// ========================================================================
// ?CSGetInitialConstraint@MoverImpl@bfx@@SAXPAXAAVInitialConstraint@2@@Z
// EA  : 0x832B8308
// RVA : 0x012B8308
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::CSGetInitialConstraint(bfx::MoverImpl *pObject, bfx::InitialConstraint *ic)
{
  bfx::AreaProxy *m_pProxy; // r11

  ic->m_constraintType = CONSTRAINT_POINT;
  if ( pObject != nullptr
    && (pObject->m_behavior.m_state == PUPPET
     || (m_pProxy = pObject->m_commonState.m_surfer.m_area.m_pProxy) != nullptr && m_pProxy->m_pArea != nullptr) )
  {
    bfx::MoverImpl::GetInitialConstraint(this: pObject, initialConstraint: ic);
  }
}


// ========================================================================
// ?SaveMoverState@MoverImpl@bfx@@QBAXAAVMoverSaveRestoreState@2@@Z
// EA  : 0x832B8348
// RVA : 0x012B8348
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::SaveMoverState(
        bfx::MoverImpl *this,
        bfx::MoverSaveRestoreState *moverSaveRestoreStateOut)
{
  bfx::CommandData::operator=(
    this: &moverSaveRestoreStateOut->m_lastMovementCommand,
    __that: &this->m_lastMovementCommand);
  moverSaveRestoreStateOut->m_orientCmd = this->m_commonState.m_orientCmd;
  moverSaveRestoreStateOut->m_frozen = (*((_BYTE *)this + 872) & 0x40) != 0;
  moverSaveRestoreStateOut->m_frozenTranslation = (*((_BYTE *)this + 872) & 0x20) != 0;
  moverSaveRestoreStateOut->m_inPuppetMode = (_cntlzw(this->m_behavior.m_state - 4) & 0x20) != 0;
}


// ========================================================================
// ?GotoPosAsync@MoverImpl@bfx@@QAAXABVVec3@2@ABVGPSpec@2@_N@Z
// EA  : 0x832B83E0
// RVA : 0x012B83E0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::GotoPosAsync(
        bfx::MoverImpl *this,
        const bfx::Vec3 *inputGoalPos,
        const bfx::GPSpec *origSpec,
        bool forceUpdate)
{
  double Scale; // fp1
  float *v9; // r10
  bool *p_m_tinyStep; // r11
  int v11; // ctr
  bool v12; // r10
  bool v13; // r8
  bool v14; // r7
  bool v15; // r6
  double v16; // fp12
  double v17; // fp11
  double v18; // fp10
  double v19; // fp9
  double v20; // fp8
  double v21; // fp7
  float m_x; // [sp+54h] [-5Ch]
  float m_y; // [sp+58h] [-58h]
  float v24[3]; // [sp+5Ch] [-54h] BYREF
  bool v25; // [sp+68h] [-48h]
  bool v26; // [sp+69h] [-47h]
  bool v27; // [sp+6Ah] [-46h]
  float v28; // [sp+6Ch] [-44h]
  float v29; // [sp+70h] [-40h]
  float v30; // [sp+74h] [-3Ch]
  bool v31; // [sp+78h] [-38h]

  if ( forceUpdate
    || (Scale = bfx::GetScale(),
        (unsigned __int8)bfx::MoverImpl::IgnoreGotoPosDueToSimilarParams(
                           this,
                           oldGoalPos: &this->m_lastGoalPosActedOn,
                           newGoalPos: inputGoalPos,
                           newGotoPosSpec: origSpec,
                           ignoreThresholdDist: (float)((float)Scale * (float)0.1)) == 0) )
  {
    v9 = v24;
    p_m_tinyStep = &origSpec[-1].m_tinyStep;
    m_x = inputGoalPos->m_x;
    v11 = 7;
    m_y = inputGoalPos->m_y;
    v24[0] = inputGoalPos->m_z;
    do
    {
      p_m_tinyStep += 4;
      *++v9 = *(float *)p_m_tinyStep;
      --v11;
    }
    while ( v11 != 0 );
    v12 = v25;
    v13 = v26;
    v14 = v27;
    v15 = v31;
    v16 = v24[0];
    this->m_asyncGotoPosData.m_isValid = true;
    this->m_asyncGotoPosData.m_goalPos.m_x = m_x;
    this->m_asyncGotoPosData.m_goalPos.m_y = m_y;
    this->m_asyncGotoPosData.m_goalPos.m_z = v16;
    this->m_asyncGotoPosData.m_spec.m_stopAtGoal = v12;
    v17 = v24[1];
    this->m_asyncGotoPosData.m_spec.m_pushThroughCrowdAtGoal = v13;
    v18 = v24[2];
    this->m_asyncGotoPosData.m_spec.m_orientAtGoalEnable = v14;
    v19 = v28;
    v20 = v29;
    v21 = v30;
    this->m_asyncGotoPosData.m_spec.m_allowedToStopDist = v17;
    this->m_asyncGotoPosData.m_spec.m_desiredStopDist = v18;
    this->m_asyncGotoPosData.m_spec.m_orientAtGoalDir.m_x = v19;
    this->m_asyncGotoPosData.m_spec.m_orientAtGoalDir.m_y = v20;
    this->m_asyncGotoPosData.m_spec.m_orientAtGoalDir.m_z = v21;
    this->m_asyncGotoPosData.m_spec.m_tinyStep = v15;
    this->m_asyncGotoPosData.m_forceUpdate = forceUpdate;
  }
}


// ========================================================================
// ?CurPathSectionValid@MoverImpl@bfx@@AAA_NXZ
// EA  : 0x832B84E8
// RVA : 0x012B84E8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

int __fastcall bfx::MoverImpl::CurPathSectionValid(bfx::MoverImpl *this)
{
  bfx::HandleProxy *m_pProxy; // r11
  bfx::HandleTargetBase *v4; // r11
  char m_pProxy_high; // r11
  char v6; // r11
  bool v7; // zf
  unsigned int m_pathDataTimestamp; // r11
  int v10[4]; // [sp+50h] [-20h] BYREF

  if ( !bfx::SmartPath::HasPath(this: this->m_commonState.m_pSmartPath) )
    return 0;
  if ( bfx::SmartPath::GetNextLink(this: this->m_commonState.m_pSmartPath) != nullptr )
  {
    m_pProxy = this->m_curGoalLink.m_pProxy;
    if ( m_pProxy == nullptr || m_pProxy->m_pTarget == nullptr )
      return 0;
    v4 = m_pProxy != nullptr ? m_pProxy->m_pTarget : nullptr;
    m_pProxy_high = HIBYTE(v4[5].m_pProxy);
    if ( (m_pProxy_high & 0x80) == 0 || (m_pProxy_high & 0x40) != 0 || (v7 = (m_pProxy_high & 0x20) == 0, v6 = 1, !v7) )
      v6 = 0;
    if ( v6 == 0 )
      return 0;
  }
  bfx::SmartPath::GetPathAreas(this: this->m_commonState.m_pSmartPath, numAreasInFirstSurfaceSectionOut: v10);
  m_pathDataTimestamp = this->m_commonState.m_pSmartPath->m_pathDataTimestamp;
  if ( m_pathDataTimestamp > this->m_commonState.m_smartPathTimeStamp )
  {
    this->m_commonState.m_smartPathTimeStamp = m_pathDataTimestamp;
    return 0;
  }
  return 1;
}


// ========================================================================
// ?GetClosestReachablePos@MoverImpl@bfx@@QAA?AVVec3@2@ABV32@@Z
// EA  : 0x832B85F8
// RVA : 0x012B85F8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

bfx::MoverImpl *__fastcall bfx::MoverImpl::GetClosestReachablePos(
        bfx::MoverImpl *this,
        bfx::MoverImpl *result,
        bfx::Vec3 *goalPos)
{
  float v6; // r11
  unsigned int v7; // r28
  bfx::Planner *v8; // r26
  bfx::PathSpec *v9; // r3
  __int64 v10; // r8
  bfx::Vec3 *ClosestReachableArea; // r4
  float m_y; // r10
  float m_z; // r9
  bfx::FTimerOb v15; // [sp+50h] [-80h] BYREF
  bfx::Vec3 *p_m_area; // [sp+54h] [-7Ch]
  bfx::Vec3 v17; // [sp+58h] [-78h] BYREF
  bfx::PathSpec v18[3]; // [sp+70h] [-60h] BYREF

  bfx::FTimerOb::FTimerOb(this: &v15, timerEntry: &bfx::closestPosTimer);
  bfx::MoverImpl::ReattachSurfer(this: result);
  if ( !result->m_stranded
    && ((v6 = *(float *)&result->m_commonState.m_surfer.m_area.m_pProxy,
         p_m_area = (bfx::Vec3 *)&result->m_commonState.m_surfer.m_area,
         v6 == 0.0)
      ? (bfx::Vec3 *)(v7 = 0)
      : (v7 = *(_DWORD *)LODWORD(v6), p_m_area = (bfx::Vec3 *)LODWORD(v6)),
        v7 != 0
     && (v8 = *((bfx::Planner **)result->m_pSpace->m_components.m_data + 1),
         v9 = bfx::BuildMoverPathSpec(result: v18, pTune: result->m_pTune),
         (ClosestReachableArea = (bfx::Vec3 *)bfx::Planner::GetClosestReachableArea(
                                                this: v8,
                                                pos: (bfx::IslandGraph *)goalPos,
                                                pathSpec: __SPAIR64__(v7, (unsigned int)v9),
                                                a4: v10)) != nullptr)) )
  {
    bfx::GetClosestPosInArea(result: &v17, pArea: ClosestReachableArea, pos: goalPos, pEdgeIndexOut: nullptr);
    m_y = v17.m_y;
    m_z = v17.m_z;
    this->bfx::HandleTargetBase::__vftable = (bfx::MoverImpl_vtbl *)LODWORD(v17.m_x);
    *(float *)&this->m_pProxy = m_y;
    *(float *)&this->bfx::RepulsorOwner::__vftable = m_z;
  }
  else
  {
    ((void (__fastcall *)(bfx::MoverImpl *))result->m_behavior.m_pCurMotion->GetPos)(a1: this);
  }
  if ( v15.m_pFTimer != nullptr )
    bfx::FTimer::Stop(this: v15.m_pFTimer);
  return this;
}


// ========================================================================
// __unwind$32608_0
// EA  : 0x832B8734
// RVA : 0x012B8734
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void _unwind_32608_0()
{
  int v0; // r12

  bfx::FTimerOb::~FTimerOb(this: (bfx::FTimerOb *)(v0 - 208 + 80));
}


// ========================================================================
// ?GetClosestReachablePos@MoverImpl@bfx@@QAA?AVVec3@2@ABV32@PAVArea@2@@Z
// EA  : 0x832B8768
// RVA : 0x012B8768
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

bfx::MoverImpl *__fastcall bfx::MoverImpl::GetClosestReachablePos(
        bfx::MoverImpl *this,
        bfx::Vec3 *result,
        bfx::IslandGraph *goalPos,
        bfx::Area *pStartArea)
{
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  __int64 v11; // r4
  bfx::Planner *v12; // r26
  bfx::PathSpec *v13; // r3
  __int64 v14; // r8
  bfx::Vec3 *ClosestReachableArea; // r4
  float m_y; // r10
  float m_z; // r9
  int v19; // [sp+8h] [-C8h]
  int v20; // [sp+Ch] [-C4h]
  int v21; // [sp+10h] [-C0h]
  int v22; // [sp+14h] [-BCh]
  bfx::FTimerOb v23; // [sp+50h] [-80h] BYREF
  bfx::Vec3 v24; // [sp+58h] [-78h] BYREF
  bfx::PathSpec v25[3]; // [sp+70h] [-60h] BYREF

  bfx::FTimerOb::FTimerOb(this: &v23, timerEntry: &bfx::closestPosTimer);
  if ( pStartArea != nullptr )
  {
    v12 = *(bfx::Planner **)(*(_DWORD *)(LODWORD(result[1].m_y) + 188) + 4);
    v13 = bfx::BuildMoverPathSpec(result: v25, pTune: (const bfx::MoverTune *)LODWORD(result[62].m_y));
    ClosestReachableArea = (bfx::Vec3 *)bfx::Planner::GetClosestReachableArea(
                                          this: v12,
                                          pos: goalPos,
                                          pathSpec: __SPAIR64__((unsigned int)pStartArea, (unsigned int)v13),
                                          a4: v14);
    if ( ClosestReachableArea != nullptr )
    {
      bfx::GetClosestPosInArea(
        result: &v24,
        pArea: ClosestReachableArea,
        pos: (const bfx::Vec3 *)goalPos,
        pEdgeIndexOut: nullptr);
      m_y = v24.m_y;
      m_z = v24.m_z;
      this->bfx::HandleTargetBase::__vftable = (bfx::MoverImpl_vtbl *)LODWORD(v24.m_x);
      *(float *)&this->m_pProxy = m_y;
      *(float *)&this->bfx::RepulsorOwner::__vftable = m_z;
    }
    else
    {
      (*(void (__fastcall **)(bfx::MoverImpl *))(*(_DWORD *)LODWORD(result[64].m_z) + 24))(a1: this);
    }
  }
  else
  {
    HIDWORD(v11) = "Mover::GetClosestReachablePos called with invalid AreaHandle\n";
    bfx::InternalWarning(fmt: v11, a2: v10, a3: v9, a4: v8, a5: v19, a6: v20, a7: v21, a8: v22);
    (*(void (__fastcall **)(bfx::MoverImpl *))(*(_DWORD *)LODWORD(result[64].m_z) + 24))(a1: this);
  }
  if ( v23.m_pFTimer != nullptr )
    bfx::FTimer::Stop(this: v23.m_pFTimer);
  return this;
}


// ========================================================================
// __unwind$32714
// EA  : 0x832B8860
// RVA : 0x012B8860
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void _unwind_32714()
{
  int v0; // r12

  bfx::FTimerOb::~FTimerOb(this: (bfx::FTimerOb *)(v0 - 208 + 80));
}


// ========================================================================
// ?FillLinkUsageData@bfx@@YAXPAVSpace@1@ABVJumpClientData@1@AAVLinkUsageData@1@@Z
// EA  : 0x832B8888
// RVA : 0x012B8888
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::FillLinkUsageData(
        bfx::AreaProxy *pSpace,
        const bfx::JumpClientData *jumpClientData,
        bfx::Handle<bfx::LinkBase> *data)
{
  bfx::LinkBase *m_pTarget; // r29
  bfx::Matrix *v7; // r3
  bfx::HandleProxy *v8; // r9
  bfx::HandleProxy *v9; // r8
  bfx::Matrix *v10; // r3
  bfx::HandleProxy *v11; // r7
  bfx::HandleProxy *v12; // r6
  bfx::AreaProxy *m_pProxy; // r11
  bfx::Area *m_pArea; // r5
  bfx::AreaProxy *v15; // r11
  bfx::Matrix v16; // [sp+60h] [-50h] BYREF

  if ( jumpClientData->m_link.m_pProxy != nullptr )
    m_pTarget = (bfx::LinkBase *)jumpClientData->m_link.m_pProxy->m_pTarget;
  else
    m_pTarget = nullptr;
  bfx::SetLinkHandle(apiLinkHandle: data, pLink: m_pTarget);
  data[1].m_pProxy = (bfx::HandleProxy *)m_pTarget;
  v7 = bfx::Matrix::operator*(this: &v16, result: (bfx::Vec3 *)&pSpace[7].m_refCount, rhs: &jumpClientData->m_startPos);
  v8 = (bfx::HandleProxy *)LODWORD(v7->m_data[0]);
  v9 = (bfx::HandleProxy *)LODWORD(v7->m_data[1]);
  data[4].m_pProxy = (bfx::HandleProxy *)LODWORD(v7->m_data[2]);
  data[3].m_pProxy = v9;
  data[2].m_pProxy = v8;
  v10 = bfx::Matrix::operator*(
          this: (bfx::Matrix *)&v16.m_data[4],
          result: (bfx::Vec3 *)&pSpace[7].m_refCount,
          rhs: &jumpClientData->m_endPos);
  v11 = (bfx::HandleProxy *)LODWORD(v10->m_data[1]);
  v12 = (bfx::HandleProxy *)LODWORD(v10->m_data[2]);
  data[5].m_pProxy = (bfx::HandleProxy *)LODWORD(v10->m_data[0]);
  data[6].m_pProxy = v11;
  data[7].m_pProxy = v12;
  m_pProxy = jumpClientData->m_startArea.m_pProxy;
  if ( m_pProxy != nullptr )
    m_pArea = m_pProxy->m_pArea;
  else
    m_pArea = nullptr;
  bfx::SetAreaHandle(apiAreaHandle: (bfx::Handle<bfx::Area> *)&data[8], pSpace, pArea: m_pArea);
  v15 = jumpClientData->m_endArea.m_pProxy;
  if ( v15 != nullptr )
    bfx::SetAreaHandle(apiAreaHandle: (bfx::Handle<bfx::Area> *)&data[10], pSpace, pArea: v15->m_pArea);
  else
    bfx::SetAreaHandle(apiAreaHandle: (bfx::Handle<bfx::Area> *)&data[10], pSpace, pArea: nullptr);
}


// ========================================================================
// ?IsWaitingAtLink@MoverImpl@bfx@@QBA_NPAVLinkUsageData@2@@Z
// EA  : 0x832B89B0
// RVA : 0x012B89B0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

int __fastcall bfx::MoverImpl::IsWaitingAtLink(bfx::MoverImpl *this, bfx::Handle<bfx::LinkBase> *pDataOut)
{
  bfx::Jumper *m_pJumper; // r11

  if ( this->m_stranded )
    return 0;
  m_pJumper = this->m_behavior.m_pJumper;
  if ( m_pJumper == nullptr || ((unsigned __int8 (*)(void))m_pJumper->IsFrozenAtStart)() == 0 )
    return 0;
  if ( pDataOut != nullptr )
  {
    bfx::FillLinkUsageData(
      pSpace: (bfx::AreaProxy *)this->m_pSpace,
      jumpClientData: &this->m_jumpClientData,
      data: pDataOut);
    HIBYTE(pDataOut[12].m_pProxy) = this->m_behavior.m_pJumper->IsCustomLinkMode(this: this->m_behavior.m_pJumper);
  }
  return 1;
}


// ========================================================================
// ?LocomotingToIdle@MoverImpl@bfx@@AAAXXZ
// EA  : 0x832B8A58
// RVA : 0x012B8A58
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::LocomotingToIdle(bfx::MoverImpl *this)
{
  bfx::AreaProxy *m_pProxy; // r11
  bfx::Area *m_pArea; // r28
  bfx::MoverImpl::MoverBehavior *p_m_behavior; // r31
  bfx::MotionState *p_m_commonState; // r29
  bfx::MotionBase *m_pCurMotion; // r3
  bfx::Idle *v7; // r3
  bfx::Matrix v8; // [sp+50h] [-70h] BYREF

  bfx::Orienter::CalcMat(this: &this->m_commonState.m_orienter, pos: &this->m_commonState.m_surfer.m_pos, mat: &v8);
  m_pProxy = this->m_commonState.m_surfer.m_area.m_pProxy;
  if ( m_pProxy != nullptr )
    m_pArea = m_pProxy->m_pArea;
  else
    m_pArea = nullptr;
  p_m_behavior = &this->m_behavior;
  m_pCurMotion = this->m_behavior.m_pCurMotion;
  p_m_commonState = &this->m_commonState;
  if ( m_pCurMotion != nullptr )
    ((void (__fastcall *)(bfx::MotionBase *, int))m_pCurMotion->dtr_MotionBase)(a1: m_pCurMotion, a2: 1);
  p_m_behavior->m_pCurMotion = nullptr;
  p_m_behavior->m_pWalker = nullptr;
  p_m_behavior->m_pLocomoter = nullptr;
  p_m_behavior->m_pJumper = nullptr;
  p_m_behavior->m_pIdle = nullptr;
  p_m_behavior->m_pPuppet = nullptr;
  p_m_behavior->m_state = 0;
  v7 = bfx::CreateIdle(
         startMat: &v8,
         pStartArea: m_pArea,
         commonState: p_m_commonState,
         preserveExactInputHeight: false);
  p_m_behavior->m_pIdle = v7;
  p_m_behavior->m_pCurMotion = v7;
}


// ========================================================================
// ?CloseEnoughToJump@MoverImpl@bfx@@AAA?AW4JumpRecommendation@12@XZ
// EA  : 0x832B8B00
// RVA : 0x012B8B00
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

bfx::MoverImpl::JumpRecommendation __fastcall bfx::MoverImpl::CloseEnoughToJump(bfx::MoverImpl *this)
{
  bfx::HandleProxy *m_pProxy; // r11
  bfx::HandleTargetBase *v3; // r30
  bfx::MoverImpl::JumpRecommendation result; // r3
  float m_y; // r10
  float m_z; // r9
  double DistPtToLineSeg; // fp1
  bfx::Vec3 v8; // [sp+50h] [-30h] BYREF

  if ( this->m_lastMovementCommand.m_command == STOP_COMMAND || this->m_behavior.m_state != PATH_WALKING )
    return DONT_JUMP;
  m_pProxy = this->m_curGoalLink.m_pProxy;
  v3 = m_pProxy != nullptr ? m_pProxy->m_pTarget : nullptr;
  if ( v3 == nullptr )
    return DONT_JUMP;
  if ( this->m_behavior.m_pWalker->ReachedGoal(this: this->m_behavior.m_pWalker) )
    return JUMP_NOW_AT_LINK_START;
  if ( !this->m_behavior.m_pWalker->IsGoalInView(this: this->m_behavior.m_pWalker) )
    return DONT_JUMP;
  m_y = this->m_commonState.m_surfer.m_pos.m_y;
  m_z = this->m_commonState.m_surfer.m_pos.m_z;
  v8.m_x = this->m_commonState.m_surfer.m_pos.m_x;
  v8.m_y = m_y;
  v8.m_z = m_z;
  DistPtToLineSeg = bfx::GetDistPtToLineSeg(
                      pos: &v8,
                      start: (const bfx::Vec3 *)&v3[1],
                      end: (const bfx::Vec3 *)&v3[2].m_pProxy);
  result = WITHIN_MUST_USE;
  if ( DistPtToLineSeg > *((float *)&v3[6].m_pProxy[7] + 1) )
    return DONT_JUMP;
  return result;
}


// ========================================================================
// ?ShouldJumpNow@MoverImpl@bfx@@AAA?AW4JumpRecommendation@12@XZ
// EA  : 0x832B8BF0
// RVA : 0x012B8BF0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

int __fastcall bfx::MoverImpl::ShouldJumpNow(bfx::MoverImpl *this)
{
  bfx::MoverImpl::JumpRecommendation v2; // r3
  bfx::HandleProxy *m_pProxy; // r11
  bfx::HalfLink *m_pTarget; // r5
  bfx::AreaProxy *v6; // r11
  bfx::Vec3 *m_pArea; // r31
  long double v8; // fp2
  double v9; // fp12
  double v10; // fp11
  double v11; // fp10
  double v14; // fp30
  double v15; // fp29
  double v16; // fp28
  float *Forward; // r3
  long double v22; // fp2
  bfx::Vec3 v23; // [sp+50h] [-60h] BYREF
  bfx::Area v24; // [sp+60h] [-50h] BYREF

  v2 = bfx::MoverImpl::CloseEnoughToJump(this);
  if ( v2 == JUMP_NOW_AT_LINK_START )
    return ((_cntlzw((unsigned __int8)bfx::IsLinkFull(halfLink: &this->m_curGoalLink)) & 0x20) != 0) + 1;
  if ( v2 != WITHIN_MUST_USE )
    return 0;
  m_pProxy = this->m_curGoalLink.m_pProxy;
  if ( m_pProxy != nullptr )
    m_pTarget = (bfx::HalfLink *)m_pProxy->m_pTarget;
  else
    m_pTarget = nullptr;
  v6 = this->m_commonState.m_surfer.m_area.m_pProxy;
  if ( v6 != nullptr )
    m_pArea = (bfx::Vec3 *)v6->m_pArea;
  else
    m_pArea = nullptr;
  if ( m_pArea == nullptr )
    return 3;
  bfx::GetLinkDirection(result: &v23, myPos: &this->m_commonState.m_surfer.m_pos, pLink: m_pTarget);
  bfx::Area::CalcNormal(this: &v24, result: m_pArea);
  if ( (float)((float)((float)(*(float *)&v24.m_pProxy * v23.m_x) + (float)(v23.m_z * *(float *)&v24.m_pFirstLink))
             + (float)(v23.m_y * *(float *)&v24.m_dynAreaData.m_data)) > 0.94 )
    return 3;
  *((double *)&v8 + 1) = (float)((float)((float)((float)(*(float *)&v24.m_pProxy * v23.m_x)
                                               + (float)(v23.m_z * *(float *)&v24.m_pFirstLink))
                                       + (float)(v23.m_y * *(float *)&v24.m_dynAreaData.m_data))
                               * *(float *)&v24.m_pFirstLink);
  *(double *)&v8 = (float)((float)((float)((float)(*(float *)&v24.m_pProxy * v23.m_x)
                                         + (float)(v23.m_z * *(float *)&v24.m_pFirstLink))
                                 + (float)(v23.m_y * *(float *)&v24.m_dynAreaData.m_data))
                         * *(float *)&v24.m_pProxy);
  v10 = (float)(v23.m_z
              - (float)((float)((float)((float)(*(float *)&v24.m_pProxy * v23.m_x)
                                      + (float)(v23.m_z * *(float *)&v24.m_pFirstLink))
                              + (float)(v23.m_y * *(float *)&v24.m_dynAreaData.m_data))
                      * *(float *)&v24.m_pFirstLink));
  v11 = (float)(v23.m_x
              - (float)((float)((float)((float)(*(float *)&v24.m_pProxy * v23.m_x)
                                      + (float)(v23.m_z * *(float *)&v24.m_pFirstLink))
                              + (float)(v23.m_y * *(float *)&v24.m_dynAreaData.m_data))
                      * *(float *)&v24.m_pProxy));
  v9 = (float)(v23.m_y
             - (float)(*(float *)&v24.m_dynAreaData.m_data
                     * (float)((float)((float)(*(float *)&v24.m_pProxy * v23.m_x)
                                     + (float)(v23.m_z * *(float *)&v24.m_pFirstLink))
                             + (float)(v23.m_y * *(float *)&v24.m_dynAreaData.m_data))));
  _FP5 = (float)((float)__fsqrts((float)((float)((float)v11 * (float)v11)
                                       + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))))
               - (float)1.0842022e-19);
  __asm { fsel      f3, f5, f4, f13 }
  v14 = (float)((float)(v23.m_x
                      - (float)((float)((float)((float)(*(float *)&v24.m_pProxy * v23.m_x)
                                              + (float)(v23.m_z * *(float *)&v24.m_pFirstLink))
                                      + (float)(v23.m_y * *(float *)&v24.m_dynAreaData.m_data))
                              * *(float *)&v24.m_pProxy))
              * (float)_FP3);
  v15 = (float)((float)(v23.m_y
                      - (float)(*(float *)&v24.m_dynAreaData.m_data
                              * (float)((float)((float)(*(float *)&v24.m_pProxy * v23.m_x)
                                              + (float)(v23.m_z * *(float *)&v24.m_pFirstLink))
                                      + (float)(v23.m_y * *(float *)&v24.m_dynAreaData.m_data))))
              * (float)_FP3);
  v16 = (float)((float)(v23.m_z
                      - (float)((float)((float)((float)(*(float *)&v24.m_pProxy * v23.m_x)
                                              + (float)(v23.m_z * *(float *)&v24.m_pFirstLink))
                                      + (float)(v23.m_y * *(float *)&v24.m_dynAreaData.m_data))
                              * *(float *)&v24.m_pFirstLink))
              * (float)_FP3);
  Forward = (float *)bfx::Orienter::GetForward(
                       this: (bfx::Orienter *)&v24,
                       result: (bfx::Vec3 *)&this->m_commonState.m_orienter,
                       a3: v8);
  *((double *)&_FP2 + 1) = Forward[1];
  _FP8 = (float)((float)-1.0
               - (float)((float)(*Forward * (float)v14)
                       + (float)((float)(Forward[2] * (float)v16) + (float)(Forward[1] * (float)v15))));
  _FP7 = (float)((float)1.0
               - (float)((float)(*Forward * (float)v14)
                       + (float)((float)(Forward[2] * (float)v16) + (float)(Forward[1] * (float)v15))));
  __asm { fsel      f6, f8, f13, f9 }
  __asm { fsel      f1, f7, f5, f31# x }
  v22 = acos(x: _FP2);
  if ( (float)*(double *)&v22 > (double)(float)(this->m_tune.m_jumperTune.m_turnBeforeJumpAngle * (float)0.017453292) )
    return 4;
  else
    return 3;
}


// ========================================================================
// ??1MoverBehavior@MoverImpl@bfx@@QAA@XZ
// EA  : 0x832B8DE0
// RVA : 0x012B8DE0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::MoverBehavior::~MoverBehavior(bfx::MoverImpl::MoverBehavior *this)
{
  bfx::MotionBase *m_pCurMotion; // r3

  m_pCurMotion = this->m_pCurMotion;
  if ( m_pCurMotion != nullptr )
    ((void (__fastcall *)(bfx::MotionBase *, int))m_pCurMotion->dtr_MotionBase)(a1: m_pCurMotion, a2: 1);
  this->m_pCurMotion = nullptr;
  this->m_pWalker = nullptr;
  this->m_pLocomoter = nullptr;
  this->m_pJumper = nullptr;
  this->m_pIdle = nullptr;
  this->m_pPuppet = nullptr;
  this->m_state = 0;
}


// ========================================================================
// ?OrientInDirectionOfTravel@MoverImpl@bfx@@QAAXXZ
// EA  : 0x832B8F08
// RVA : 0x012B8F08
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::OrientInDirectionOfTravel(bfx::MoverImpl *this)
{
  float m_x; // r7
  float m_z; // r5
  float m_y; // r6

  if ( (unsigned __int8)bfx::MoverImpl::ReattachSurfer(this) != 0
    && this->m_commonState.m_orientCmd.m_mode != ORIENT_IN_TRAVEL_DIR )
  {
    m_x = bfx::ZERO_VEC.m_x;
    m_z = bfx::ZERO_VEC.m_z;
    m_y = bfx::ZERO_VEC.m_y;
    this->m_commonState.m_orientCmd.m_mode = ORIENT_IN_TRAVEL_DIR;
    this->m_commonState.m_orientCmd.m_vec.m_x = m_x;
    this->m_commonState.m_orientCmd.m_vec.m_y = m_y;
    this->m_commonState.m_orientCmd.m_vec.m_z = m_z;
    this->m_behavior.m_pCurMotion->OrientInDirectionOfTravel(this: this->m_behavior.m_pCurMotion);
  }
}


// ========================================================================
// ?OrientStrictlyInDirectionOfTravel@MoverImpl@bfx@@QAAXXZ
// EA  : 0x832B8FA8
// RVA : 0x012B8FA8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::OrientStrictlyInDirectionOfTravel(bfx::MoverImpl *this)
{
  float m_x; // r7
  float m_z; // r5
  float m_y; // r6

  if ( (unsigned __int8)bfx::MoverImpl::ReattachSurfer(this) != 0
    && this->m_commonState.m_orientCmd.m_mode != ORIENT_STRICTLY_IN_TRAVEL_DIR )
  {
    m_x = bfx::ZERO_VEC.m_x;
    m_z = bfx::ZERO_VEC.m_z;
    m_y = bfx::ZERO_VEC.m_y;
    this->m_commonState.m_orientCmd.m_mode = ORIENT_STRICTLY_IN_TRAVEL_DIR;
    this->m_commonState.m_orientCmd.m_vec.m_x = m_x;
    this->m_commonState.m_orientCmd.m_vec.m_y = m_y;
    this->m_commonState.m_orientCmd.m_vec.m_z = m_z;
    this->m_behavior.m_pCurMotion->OrientStrictlyInDirectionOfTravel(this: this->m_behavior.m_pCurMotion);
  }
}


// ========================================================================
// ?OrientTowardsTargetPos@MoverImpl@bfx@@QAAXABVVec3@2@@Z
// EA  : 0x832B9048
// RVA : 0x012B9048
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::OrientTowardsTargetPos(bfx::MoverImpl *this, const bfx::Vec3 *targetPos)
{
  float m_x; // r8
  float m_y; // r7
  float m_z; // r10

  if ( (unsigned __int8)bfx::MoverImpl::ReattachSurfer(this) != 0 )
  {
    m_x = targetPos->m_x;
    m_y = targetPos->m_y;
    m_z = targetPos->m_z;
    this->m_commonState.m_orientCmd.m_mode = ORIENT_TARGET;
    this->m_commonState.m_orientCmd.m_vec.m_z = m_z;
    this->m_commonState.m_orientCmd.m_vec.m_y = m_y;
    this->m_commonState.m_orientCmd.m_vec.m_x = m_x;
    this->m_behavior.m_pCurMotion->OrientTowardsTargetPos(this: this->m_behavior.m_pCurMotion, a2: targetPos);
  }
}


// ========================================================================
// ?OrientInDirection@MoverImpl@bfx@@QAAXABVVec3@2@@Z
// EA  : 0x832B90E0
// RVA : 0x012B90E0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::OrientInDirection(bfx::MoverImpl *this, const bfx::Vec3 *dir)
{
  float m_x; // r8
  float m_y; // r7
  float m_z; // r10

  if ( (unsigned __int8)bfx::MoverImpl::ReattachSurfer(this) != 0 )
  {
    m_x = dir->m_x;
    m_y = dir->m_y;
    m_z = dir->m_z;
    this->m_commonState.m_orientCmd.m_mode = ORIENT_IN_DIR;
    this->m_commonState.m_orientCmd.m_vec.m_z = m_z;
    this->m_commonState.m_orientCmd.m_vec.m_y = m_y;
    this->m_commonState.m_orientCmd.m_vec.m_x = m_x;
    this->m_behavior.m_pCurMotion->OrientInDirection(this: this->m_behavior.m_pCurMotion, a2: dir);
  }
}


// ========================================================================
// ?StopCommand@MoverImpl@bfx@@AAAXABVCommandData@2@@Z
// EA  : 0x832B9178
// RVA : 0x012B9178
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::StopCommand(bfx::MoverImpl *this, const bfx::CommandData *commandData)
{
  bfx::MoverImpl::State m_state; // r11
  bfx::StpSpec m_stopSpec; // [sp+50h] [-20h] BYREF

  m_stopSpec = commandData->m_stopSpec;
  if ( (unsigned __int8)bfx::MoverImpl::ReattachSurfer(this) != 0 )
  {
    m_state = this->m_behavior.m_state;
    if ( m_state == PATH_WALKING )
    {
      this->m_behavior.m_pWalker->Stop(this: this->m_behavior.m_pWalker, a2: &m_stopSpec);
    }
    else if ( m_state == LOCOMOTING )
    {
      bfx::MoverImpl::LocomotingToIdle(this);
    }
  }
}


// ========================================================================
// ?Stop@MoverImpl@bfx@@QAAXABVStopSpec@2@@Z
// EA  : 0x832B9200
// RVA : 0x012B9200
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::Stop(bfx::MoverImpl *this, const bfx::StopSpec *spec)
{
  char v2; // r9
  bfx::MoverImpl::State m_state; // r10

  v2 = 1;
  this->m_lastMovementCommand.m_command = STOP_COMMAND;
  this->m_lastMovementCommand.m_stopSpec.m_stopImmediately = spec->m_stopImmediately;
  this->m_lastMovementCommand.m_stopSpec.m_cancelPendingTurn = true;
  m_state = this->m_behavior.m_state;
  this->m_asyncGotoPosData.m_isValid = false;
  if ( m_state == JUMPING )
    this->m_applyCommandOnJumpEnd = true;
  if ( m_state == PUPPET )
    this->m_applyCommandOnPuppetDisable = true;
  if ( m_state != JUMPING && m_state != PUPPET )
    v2 = 0;
  if ( v2 == 0 )
  {
    bfx::MoverImpl::StopCommand(this, commandData: &this->m_lastMovementCommand);
    bfx::MoverImpl::ClearFollowMode(this);
    *((_BYTE *)this + 872) &= ~0x10u;
  }
}


// ========================================================================
// ?CalculateCornersArray@MoverImpl@bfx@@QAA_NAAV?$Array@VSmartPathCorner@bfx@@@2@H@Z
// EA  : 0x832B92B0
// RVA : 0x012B92B0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

int __fastcall bfx::MoverImpl::CalculateCornersArray(
        bfx::MoverImpl *this,
        bfx::Array<bfx::SmartPathCorner> *cornersOut,
        int maxNumCorners)
{
  bfx::MoverImpl::State m_state; // r10
  const bfx::Array<bfx::SmartPathCorner> *v6; // r4
  bfx::HalfLink **m_pProxy; // r11
  bfx::CalcCornersSpec v9; // [sp+50h] [-30h] BYREF

  m_state = this->m_behavior.m_state;
  v9.m_maxNumCorners = maxNumCorners;
  v9.m_addCornersAtEveryAreaBoundary = false;
  v9.m_maxPathDist = 3.4028235e38;
  v9.m_addCornerAtStartingPosition = m_state == JUMPING;
  v6 = bfx::SmartPath::CalcNextNCorners(this: this->m_commonState.m_pSmartPath, calcCornersSpec: &v9);
  if ( v6 != nullptr )
  {
    bfx::Array<bfx::SmartPathCorner>::operator=(this: cornersOut, rhs: v6);
    if ( this->m_behavior.m_state == JUMPING )
    {
      cornersOut->m_data->m_linkType = SMART_PATH_CORNER_LINK_END;
      m_pProxy = (bfx::HalfLink **)this->m_curGoalLink.m_pProxy;
      if ( m_pProxy != nullptr )
      {
        cornersOut->m_data->m_pHalfLink = *m_pProxy;
        return 1;
      }
      cornersOut->m_data->m_pHalfLink = nullptr;
    }
    return 1;
  }
  else
  {
    cornersOut->m_size = 0;
    return 0;
  }
}


// ========================================================================
// ?UpdateBlockageCheck@MoverImpl@bfx@@AAAXM@Z
// EA  : 0x832B9378
// RVA : 0x012B9378
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::UpdateBlockageCheck(bfx::MoverImpl *this, double simTime)
{
  bfx::Walker *m_pWalker; // r3
  bfx::HandleProxy *m_pProxy; // r9
  double m_followSpeedX; // fp0
  bfx::Vec3 v7[2]; // [sp+50h] [-30h] BYREF

  m_pWalker = this->m_behavior.m_pWalker;
  if ( m_pWalker == nullptr || m_pWalker->DoneMoving(this: m_pWalker) )
  {
    this->m_commonState.m_blockedMonitor.m_blockedTimer = 0.0;
  }
  else
  {
    ((void (__fastcall *)(bfx::Vec3 *))this->m_behavior.m_pCurMotion->GetPos)(a1: v7);
    m_pProxy = this->m_commonState.m_followData.m_targetMover.m_pProxy;
    if ( m_pProxy != nullptr && m_pProxy->m_pTarget != nullptr )
      m_followSpeedX = this->m_commonState.m_followData.m_followSpeedX;
    else
      m_followSpeedX = 1.0;
    bfx::BlockedMonitor::Update(
      this: &this->m_commonState.m_blockedMonitor,
      pos: v7,
      desiredSpeed: (float)((float)((float)(this->m_commonState.m_pTune->m_speed * this->m_commonState.m_cautionData.m_internalSpeedX)
                    * this->m_commonState.m_speedX)
            * (float)m_followSpeedX),
      radius: this->m_pTune->m_radiusData.m_radius,
      simTime);
  }
}


// ========================================================================
// ?ReachedGoal@MoverImpl@bfx@@QBA_NXZ
// EA  : 0x832B9460
// RVA : 0x012B9460
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

int __fastcall bfx::MoverImpl::ReachedGoal(bfx::MoverImpl *this)
{
  int v2; // r29
  bfx::MoverImpl::State m_state; // r11
  bfx::Area *SnappedStartArea; // r30
  bool v6; // r3
  unsigned __int8 v7; // r11
  char v8; // r11
  bfx::Command m_command; // r30
  float m_y; // r10
  _DWORD v11[4]; // [sp+50h] [-50h] BYREF
  bfx::SPCorner v12; // [sp+60h] [-40h] BYREF

  v2 = 0;
  if ( !this->m_stranded )
  {
    if ( this->m_asyncGotoPosData.m_isValid )
      return 0;
    m_state = this->m_behavior.m_state;
    if ( m_state != 0 )
    {
      if ( m_state == PATH_WALKING )
      {
        SnappedStartArea = bfx::SmartPath::GetSnappedStartArea(this: this->m_commonState.m_pSmartPath);
        if ( SnappedStartArea != bfx::SmartPath::GetSnappedGoalArea(this: this->m_commonState.m_pSmartPath)
          || (v6 = this->m_behavior.m_pWalker->ReachedGoal(this: this->m_behavior.m_pWalker), v7 = 1, !v6) )
        {
          v7 = 0;
        }
        v2 = v7;
      }
    }
    else
    {
      v2 = 1;
    }
  }
  if ( (unsigned __int8)v2 != this->m_prevReachedGoal )
  {
    if ( BYTE2(bfx::g_pCurInstance->m_pComponentManager->m_components[4][8].dtr_InstanceComponent) != 0
      || (v8 = 0, (this->m_commonState.m_debugFlags & 2) != 0) )
    {
      v8 = 1;
    }
    if ( v8 != 0 && (_BYTE)v2 != 0 )
    {
      m_command = this->m_lastMovementCommand.m_command;
      ((void (__fastcall *)(_DWORD *))this->m_behavior.m_pCurMotion->GetPos)(a1: v11);
      m_y = this->m_goalPos.m_y;
      v12.m_posU.m_x = this->m_goalPos.m_x;
      HIBYTE(v12.m_areaExitIndex) = (_cntlzw(m_command - 2) & 0x20) != 0;
      *(float *)&v12.m_cornerFlavor = 0.0;
      LODWORD(v12.m_pos.m_x) = v11[0];
      v12.m_posU.m_y = m_y;
      v12.m_posU.m_z = this->m_goalPos.m_z;
      LODWORD(v12.m_pos.m_y) = v11[1];
      LODWORD(v12.m_pos.m_z) = v11[2];
      bfx::Array<bfx::SPCorner>::push_back(this: (bfx::Array<bfx::SPCorner> *)&this->m_goalsReached, val: &v12);
    }
  }
  this->m_prevReachedGoal = v2;
  return v2;
}


// ========================================================================
// ?CalcAcc@MoverImpl@bfx@@UAAXM@Z
// EA  : 0x832B95E0
// RVA : 0x012B95E0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::CalcAcc(bfx::MoverImpl *this, double simTimeIn)
{
  double v3; // fp30
  bfx::MoverImpl ***p_m_targetMover; // r10
  bfx::HandleProxy *m_pProxy; // r11
  bfx::MoverImpl *v7; // r11
  float m_radius; // r8
  float m_arcSpread; // r7
  bfx::MoverImpl **v10; // r11
  bool v11; // cr58
  bool v12; // r11
  bfx::MoverImpl *v13; // r5
  _DWORD v14[4]; // [sp+50h] [-30h] BYREF

  v3 = (float)(this->m_commonState.m_slowTime * (float)simTimeIn);
  if ( (unsigned __int8)bfx::MoverImpl::ReattachSurfer(this) != 0 )
  {
    p_m_targetMover = (bfx::MoverImpl ***)&this->m_commonState.m_followData.m_targetMover;
    m_pProxy = this->m_commonState.m_followData.m_targetMover.m_pProxy;
    if ( m_pProxy != nullptr && m_pProxy->m_pTarget != nullptr )
    {
      v7 = *p_m_targetMover != nullptr ? **p_m_targetMover : nullptr;
      if ( v7 != nullptr )
      {
        m_radius = this->m_lastMovementCommand.m_fmSpec.m_radius;
        m_arcSpread = this->m_lastMovementCommand.m_fmSpec.m_arcSpread;
        v10 = *p_m_targetMover;
        v11 = *p_m_targetMover == nullptr;
        v14[0] = this->m_lastMovementCommand.m_fmSpec.m_formation;
        *(float *)&v14[1] = m_radius;
        *(float *)&v14[2] = m_arcSpread;
        v12 = !v11 && *v10 != nullptr;
        if ( v12 && *p_m_targetMover != nullptr )
          v13 = **p_m_targetMover;
        else
          v13 = nullptr;
        bfx::FollowMover_AdjustDynamics(
          commonState: (bfx::Vec3 *)&this->m_commonState,
          newGoalPos: &this->m_lastGoalPosActedOn,
          pTargetMover: v13,
          myVel: &this->m_vel,
          timerLerp: 0.0,
          spec: (bfx::FMSpec *)LODWORD(m_arcSpread),
          a7: (int)v14);
      }
    }
    if ( this->m_behavior.m_state == PATH_WALKING && v3 != 0.0 )
      this->m_behavior.m_pWalker->CalcAcc(this: this->m_behavior.m_pWalker, a2: v3);
    if ( this->m_pLeaderDatabase != nullptr )
      this->m_pLeaderDatabase->m_leaderIsCloseToGoal = bfx::MoverImpl::LeaderIsNearGoal(this);
  }
}


// ========================================================================
// ?AnimateMoverDebugDraw@MoverImpl@bfx@@AAAXM@Z
// EA  : 0x832B9748
// RVA : 0x012B9748
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::AnimateMoverDebugDraw(bfx::MoverImpl *this, double simTime)
{
  char v2; // r11
  int v3; // r10
  int v4; // r9
  bfx::GoalReachedData *v5; // r11

  if ( BYTE2(bfx::g_pCurInstance->m_pComponentManager->m_components[4][8].dtr_InstanceComponent) != 0
    || (v2 = 0, (this->m_commonState.m_debugFlags & 2) != 0) )
  {
    v2 = 1;
  }
  if ( v2 != 0 )
  {
    v3 = 0;
    if ( this->m_goalsReached.m_size > 0 )
    {
      v4 = 0;
      do
      {
        ++v3;
        v5 = &this->m_goalsReached.m_data[v4++];
        v5->m_age = v5->m_age + (float)simTime;
      }
      while ( v3 < this->m_goalsReached.m_size );
    }
  }
}


// ========================================================================
// ?UpdateMoverDebugDraw@MoverImpl@bfx@@AAAXXZ
// EA  : 0x832B97D0
// RVA : 0x012B97D0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::UpdateMoverDebugDraw(bfx::MoverImpl *this)
{
  bfx::Vec3 v2; // [sp+50h] [-20h] BYREF

  if ( this->m_pTrail != nullptr )
  {
    ((void (__fastcall *)(bfx::Vec3 *))this->m_behavior.m_pCurMotion->GetPos)(a1: &v2);
    bfx::Trail::AddPos(this: this->m_pTrail, pt: &v2);
  }
  bfx::MoverImpl::ReachedGoal(this);
}


// ========================================================================
// ?EnableRepulsor@MoverImpl@bfx@@QAAX_N@Z
// EA  : 0x832B98B8
// RVA : 0x012B98B8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::EnableRepulsor(bfx::MoverImpl *this, bool enable)
{
  double Scale; // fp1
  const bfx::MoverTune *m_pTune; // r10
  double v5; // fp31
  bfx::RepulsorImpl *v6; // r28
  const bfx::MoverTune *v7; // r29
  bfx::RepulsorOwner *m_repulsorIdentityFlags; // r24
  unsigned int m_repulsorBlockageFlags; // r23
  const bfx::Vec3 *v10; // r3
  unsigned int v11; // r8
  bfx::RepulsorImpl *v12; // r3
  const bfx::MoverTune *v13; // r11
  bfx::AreaProxy *m_pProxy; // r11
  bfx::Area *m_pArea; // r4
  bfx::RepulsorImpl *m_pRepulsor; // r11
  bfx::RepulsorImpl *v17; // r3
  int v18; // [sp+8h] [-D8h]
  int v19; // [sp+Ch] [-D4h]
  int v20; // [sp+10h] [-D0h]
  int v21; // [sp+14h] [-CCh]
  int v22; // [sp+18h] [-C8h]
  int v23; // [sp+1Ch] [-C4h]
  int v24; // [sp+20h] [-C0h]
  int v25; // [sp+24h] [-BCh]
  int v26; // [sp+28h] [-B8h]
  int v27; // [sp+2Ch] [-B4h]
  int v28; // [sp+30h] [-B0h]
  int v29; // [sp+34h] [-ACh]
  int v30; // [sp+38h] [-A8h]
  int v31; // [sp+3Ch] [-A4h]
  int v32; // [sp+40h] [-A0h]
  int v33; // [sp+44h] [-9Ch]
  int v34; // [sp+48h] [-98h]
  int v35; // [sp+4Ch] [-94h]
  int v36; // [sp+50h] [-90h]
  _DWORD v37[6]; // [sp+70h] [-70h] BYREF

  if ( enable )
  {
    if ( this->m_commonState.m_pRepulsor == nullptr )
    {
      Scale = bfx::GetScale();
      m_pTune = this->m_commonState.m_pTune;
      v5 = (float)((float)Scale * (float)10.0);
      if ( (float)(m_pTune->m_radiusData.m_radius * (float)10.0) > v5 )
        v5 = (float)(m_pTune->m_radiusData.m_radius * (float)10.0);
      v6 = (bfx::RepulsorImpl *)bfx::MemoryManager::Malloc(
                                  this: bfx::g_pCurInstance->m_pMemoryManager,
                                  size: 0x74u,
                                  tag: bfx::MEM_BFXNAVIGATOR);
      if ( v6 != nullptr )
      {
        v7 = this->m_pTune;
        m_repulsorIdentityFlags = (bfx::RepulsorOwner *)v7->m_repulsorIdentityFlags;
        m_repulsorBlockageFlags = v7->m_repulsorBlockageFlags;
        v10 = (const bfx::Vec3 *)((int (__fastcall *)(_DWORD *))this->m_behavior.m_pCurMotion->GetPos)(a1: v37);
        v12 = bfx::RepulsorImpl::RepulsorImpl(
                this: v6,
                pSpace: this->m_pSpace,
                pos: v10,
                vel: &this->m_vel,
                radiusData: &v7->m_radiusData,
                detectRadius: v5,
                blockageFlags: v11,
                repulsorIdentityFlags: m_repulsorBlockageFlags,
                pOwner: m_repulsorIdentityFlags,
                a10: v18,
                a11: v19,
                a12: v20,
                a13: v21,
                a14: v22,
                a15: v23,
                a16: v24,
                a17: v25,
                a18: v26,
                a19: v27,
                a20: v28,
                a21: v29,
                a22: v30,
                a23: v31,
                a24: v32,
                a25: v33,
                a26: v34,
                a27: v35,
                a28: v36,
                a29: &this->bfx::RepulsorOwner);
      }
      else
      {
        v12 = nullptr;
      }
      v13 = this->m_pTune;
      this->m_commonState.m_pRepulsor = v12;
      v12->m_bulk = v13->m_bulk;
      this->m_commonState.m_pRepulsor->m_repulsorType = this->m_pTune->m_repulsorType;
      m_pProxy = this->m_commonState.m_surfer.m_area.m_pProxy;
      if ( m_pProxy != nullptr )
        m_pArea = m_pProxy->m_pArea;
      else
        m_pArea = nullptr;
      bfx::RepulsorImpl::SetArea(this: this->m_commonState.m_pRepulsor, pArea: m_pArea);
      m_pRepulsor = this->m_commonState.m_pRepulsor;
      v37[3] = this;
      v37[0] = bfx::MoverImpl::CSGetInitialConstraint;
      v37[1] = bfx::MoverImpl::CSMove;
      v37[2] = bfx::MoverImpl::CSGetPos;
      m_pRepulsor->m_solverData.m_pObject = this;
      m_pRepulsor->m_solverData.m_pGetPosFunc = (const bfx::Vec3 *(__fastcall *)(const bfx::Vec3 *, void *))bfx::MoverImpl::CSGetPos;
      m_pRepulsor->m_solverData.m_pMoveFunc = (void (__fastcall *)(void *, const bfx::Vec3 *, float))bfx::MoverImpl::CSMove;
      m_pRepulsor->m_solverData.m_pGetInitialConstraintFunc = (void (__fastcall *)(void *, bfx::InitialConstraint *))bfx::MoverImpl::CSGetInitialConstraint;
      return;
    }
    if ( enable )
      return;
  }
  v17 = this->m_commonState.m_pRepulsor;
  if ( v17 != nullptr )
  {
    ((void (__fastcall *)(bfx::RepulsorImpl *, int))v17->dtr_HandleTargetBase)(a1: v17, a2: 1);
    this->m_commonState.m_pRepulsor = nullptr;
  }
}


// ========================================================================
// __unwind$34196
// EA  : 0x832B9A84
// RVA : 0x012B9A84
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void _unwind_34196()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(char **)(v0 - 224 + 96), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?AddLink@PathSharingHelper@bfx@@QAAXPAVLinkBase@2@@Z
// EA  : 0x832B9AB0
// RVA : 0x012B9AB0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::PathSharingHelper::AddLink(bfx::PathSharingHelper *this, bfx::LinkBase *pLinkBase)
{
  bfx::HandleProxy *m_pProxy; // r11
  bfx::HandleTargetBase *m_pTarget; // r11
  bfx::HandleTargetBase_vtbl *v7; // r11
  int dtr_HandleTargetBase; // r10

  if ( pLinkBase != nullptr )
  {
    m_pProxy = this->m_linkBase.m_pProxy;
    if ( this->m_linkBase.m_pProxy != nullptr && m_pProxy->m_pTarget != nullptr )
    {
      if ( m_pProxy != nullptr )
        m_pTarget = m_pProxy->m_pTarget;
      else
        m_pTarget = nullptr;
      v7 = m_pTarget[12].__vftable;
      if ( v7 != nullptr )
      {
        dtr_HandleTargetBase = (int)v7[1].dtr_HandleTargetBase;
        if ( dtr_HandleTargetBase > 0 )
          v7[1].dtr_HandleTargetBase = (void (__fastcall *)(bfx::HandleTargetBase *))(dtr_HandleTargetBase - 1);
      }
    }
    bfx::AllocateLinkFlowForLinkIfNeeded(pLinkBase);
    bfx::Handle<bfx::MoverImpl>::operator=(this: &this->m_linkBase, pTarget: pLinkBase);
    ++pLinkBase->m_pLinkFlow->m_intentionCount;
  }
}


// ========================================================================
// ?ClearAll@PathSharingHelper@bfx@@QAAXXZ
// EA  : 0x832B9B70
// RVA : 0x012B9B70
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::PathSharingHelper::ClearAll(bfx::PathSharingHelper *this)
{
  bfx::HandleProxy *m_pProxy; // r11
  bfx::HandleTargetBase *v4; // r11
  bfx::HandleTargetBase_vtbl *v5; // r11
  int dtr_HandleTargetBase; // r10
  bfx::HandleProxy *v7; // r3

  m_pProxy = this->m_linkBase.m_pProxy;
  if ( this->m_linkBase.m_pProxy != nullptr && m_pProxy->m_pTarget != nullptr )
  {
    v4 = m_pProxy != nullptr ? m_pProxy->m_pTarget : nullptr;
    v5 = v4[12].__vftable;
    if ( v5 != nullptr )
    {
      dtr_HandleTargetBase = (int)v5[1].dtr_HandleTargetBase;
      if ( dtr_HandleTargetBase > 0 )
        v5[1].dtr_HandleTargetBase = (void (__fastcall *)(bfx::HandleTargetBase *))(dtr_HandleTargetBase - 1);
    }
  }
  v7 = this->m_linkBase.m_pProxy;
  if ( this->m_linkBase.m_pProxy != nullptr )
  {
    bfx::HandleProxy::RemRefToHandleProxy(this: v7);
    this->m_linkBase.m_pProxy = nullptr;
  }
}


// ========================================================================
// ?WalkerGotoPos@MoverImpl@bfx@@AAAXABVGPSpec@2@_N@Z
// EA  : 0x832B9C10
// RVA : 0x012B9C10
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::WalkerGotoPos(bfx::MoverImpl *this, const bfx::GPSpec *spec, BOOL forceUpdate)
{
  bfx::HalfLink *NextLink; // r3
  bfx::HalfLink *v7; // r31
  float m_x; // r7
  float m_y; // r6
  char *v10; // r10
  bool *p_m_tinyStep; // r11
  int i; // ctr
  char *v13; // r10
  bfx::HandleProxy **p_m_pProxy; // r11
  int j; // ctr
  char *v16; // r10
  bfx::HandleProxy **v17; // r11
  int k; // ctr
  double v19; // fp7
  double v22; // fp31
  double v23; // fp30
  double v24; // fp29
  double v25; // fp8
  double v26; // fp7
  double v27; // fp6
  double v28; // fp4
  double v29; // fp9
  double v30; // fp8
  double v31; // fp7
  double v34; // fp27
  const bfx::Array<bfx::Area *> *PathAreas; // r3
  bfx::AreaProxy *m_pProxy; // r11
  bfx::Area *m_pArea; // r11
  double v38; // fp0
  double v39; // fp13
  double v40; // fp12
  const bfx::MoverTune *m_pTune; // r11
  double m_turnBeforeJumpAngle; // fp0
  BOOL m_stopAtGoal; // r11
  double v44; // fp0
  double v45; // fp13
  double v46; // fp12
  char v47; // [sp+4Ch] [-174h] BYREF
  float v48; // [sp+50h] [-170h]
  float v49; // [sp+54h] [-16Ch]
  float v50; // [sp+58h] [-168h]
  float v51; // [sp+5Ch] [-164h]
  float v52; // [sp+60h] [-160h]
  float m_z; // [sp+64h] [-15Ch]
  bfx::LineSeg v54; // [sp+70h] [-150h] BYREF
  bfx::Vec3 v55[2]; // [sp+88h] [-138h] BYREF
  float v56; // [sp+A0h] [-120h] BYREF
  float v57; // [sp+A4h] [-11Ch]
  float v58; // [sp+A8h] [-118h]
  float v59; // [sp+ACh] [-114h]
  float v60; // [sp+B0h] [-110h]
  float v61; // [sp+B4h] [-10Ch]
  char v62; // [sp+B8h] [-108h]
  float v63; // [sp+BCh] [-104h]
  float v64; // [sp+C0h] [-100h]
  float v65; // [sp+C4h] [-FCh]
  float v66; // [sp+C8h] [-F8h]
  bool m_tinyStep; // [sp+CCh] [-F4h]
  int v68; // [sp+D0h] [-F0h] BYREF
  bfx::Vec3 v69; // [sp+D8h] [-E8h] BYREF
  char v70; // [sp+ECh] [-D4h] BYREF
  float v71; // [sp+F0h] [-D0h]
  float v72; // [sp+F4h] [-CCh]
  float v73; // [sp+F8h] [-C8h]
  char v74; // [sp+10Ch] [-B4h] BYREF
  float m_mayUseDist; // [sp+110h] [-B0h] BYREF
  float v76; // [sp+114h] [-ACh]
  bool m_stopToUseLink; // [sp+118h] [-A8h]
  char v78; // [sp+119h] [-A7h]
  bfx::PathSpec v79[2]; // [sp+130h] [-90h] BYREF

  bfx::BuildMoverPathSpec(result: v79, pTune: this->m_pTune);
  ((void (__fastcall *)(bfx::Vec3 *))this->m_behavior.m_pCurMotion->GetPos)(a1: v55);
  NextLink = bfx::SmartPath::GetNextLink(this: this->m_commonState.m_pSmartPath);
  v7 = NextLink;
  if ( NextLink != nullptr )
  {
    v54.m_v0.m_x = NextLink->m_startSeg.m_v0.m_x;
    v54.m_v0.m_y = NextLink->m_startSeg.m_v0.m_y;
    v54.m_v0.m_z = NextLink->m_startSeg.m_v0.m_z;
    v54.m_v1.m_x = NextLink->m_startSeg.m_v1.m_x;
    v54.m_v1.m_y = NextLink->m_startSeg.m_v1.m_y;
    v54.m_v1.m_z = NextLink->m_startSeg.m_v1.m_z;
  }
  else
  {
    m_x = this->m_goalPos.m_x;
    m_y = this->m_goalPos.m_y;
    m_z = this->m_goalPos.m_z;
    v50 = m_z;
    v48 = m_x;
    v52 = m_y;
    v51 = m_x;
    v49 = m_y;
    v54.m_v0.m_y = m_y;
    v54.m_v0.m_x = m_x;
    v54.m_v0.m_z = m_z;
    v54.m_v1.m_x = m_x;
    v54.m_v1.m_y = m_y;
    v54.m_v1.m_z = m_z;
  }
  v10 = &v74;
  p_m_tinyStep = &spec[-1].m_tinyStep;
  for ( i = 7; i != 0; --i )
  {
    p_m_tinyStep += 4;
    v10 += 4;
    *(_DWORD *)v10 = *(_DWORD *)p_m_tinyStep;
  }
  bfx::PathSharingHelper::ClearAll(this: &this->m_pathSharingHelper);
  bfx::Handle<bfx::MoverImpl>::operator=(
    this: (bfx::Handle<bfx::LinkBase> *)&this->m_curGoalLink,
    pTarget: (bfx::LinkBase *)v7);
  if ( v7 != nullptr )
  {
    bfx::PathSharingHelper::AddLink(this: &this->m_pathSharingHelper, pLinkBase: v7->m_pLinkBase);
    v76 = 0.0;
    m_stopToUseLink = v7->m_pLinkBase->m_linkDat.m_stopToUseLink;
    v78 = 1;
    m_mayUseDist = v7->m_pLinkBase->m_linkDat.m_mayUseDist;
  }
  m_tinyStep = spec->m_tinyStep;
  v62 = 0;
  v63 = 0.0;
  v64 = 0.0;
  v65 = 0.0;
  v66 = 180.0;
  v56 = v54.m_v0.m_x;
  v57 = v54.m_v0.m_y;
  v58 = v54.m_v0.m_z;
  v59 = v54.m_v1.m_x;
  v60 = v54.m_v1.m_y;
  v61 = v54.m_v1.m_z;
  if ( v7 != nullptr )
  {
    v76 = 0.0;
    v13 = &v47;
    p_m_pProxy = &v7->m_pProxy;
    for ( j = 6; j != 0; --j )
    {
      ++p_m_pProxy;
      v13 += 4;
      *(_DWORD *)v13 = *p_m_pProxy;
    }
    v16 = &v70;
    v17 = &v7->m_pTwin->m_pProxy;
    for ( k = 6; k != 0; --k )
    {
      ++v17;
      v16 += 4;
      *(_DWORD *)v16 = *v17;
    }
    v19 = __fsqrts((float)((float)((float)(v51 - v48) * (float)(v51 - v48))
                         + (float)((float)((float)(m_z - v50) * (float)(m_z - v50))
                                 + (float)((float)(v52 - v49) * (float)(v52 - v49)))));
    if ( v19 >= 1.0842022e-19 )
    {
      v25 = (float)((float)(1.0 / (float)v19) * (float)(v52 - v49));
      v27 = (float)((float)(1.0 / (float)v19) * (float)(v51 - v48));
      v28 = (float)((float)((float)(1.0 / (float)v19) * (float)(v52 - v49)) * (float)(v72 - v49));
      v26 = (float)((float)(1.0 / (float)v19) * (float)(m_z - v50));
      v30 = (float)((float)(v72 - v49)
                  - (float)((float)v25
                          * (float)((float)((float)v27 * (float)(v71 - v48))
                                  + (float)((float)((float)v26 * (float)(v73 - v50)) + (float)v28))));
      v29 = (float)((float)v27
                  * (float)((float)((float)v27 * (float)(v71 - v48))
                          + (float)((float)((float)v26 * (float)(v73 - v50)) + (float)v28)));
      v31 = (float)((float)(v73 - v50)
                  - (float)((float)v26
                          * (float)((float)((float)v27 * (float)(v71 - v48))
                                  + (float)((float)((float)v26 * (float)(v73 - v50)) + (float)v28))));
      _FP1 = (float)((float)__fsqrts((float)((float)((float)((float)(v71 - v48) - (float)v29)
                                                   * (float)((float)(v71 - v48) - (float)v29))
                                           + (float)((float)((float)v31 * (float)v31) + (float)((float)v30 * (float)v30))))
                   - (float)1.0842022e-19);
      __asm { fsel      f12, f1, f0, f28 }
      v22 = (float)((float)((float)(v71 - v48) - (float)v29) * (float)_FP12);
      v23 = (float)((float)v30 * (float)_FP12);
      v24 = (float)((float)v31 * (float)_FP12);
    }
    else
    {
      _FP1 = (float)((float)__fsqrts((float)((float)((float)(v71 - v48) * (float)(v71 - v48))
                                           + (float)((float)((float)(v73 - v50) * (float)(v73 - v50))
                                                   + (float)((float)(v72 - v49) * (float)(v72 - v49)))))
                   - (float)1.0842022e-19);
      __asm { fsel      f13, f1, f0, f28 }
      v22 = (float)((float)(v71 - v48) * (float)_FP13);
      v23 = (float)((float)(v72 - v49) * (float)_FP13);
      v24 = (float)((float)(v73 - v50) * (float)_FP13);
    }
    bfx::GetClosestPtOnLineSeg(result: &v69, seg: &v54, pos: v55);
    if ( __fsqrts((float)((float)((float)(v69.m_x - v55[0].m_x) * (float)(v69.m_x - v55[0].m_x))
                        + (float)((float)((float)(v69.m_z - v55[0].m_z) * (float)(v69.m_z - v55[0].m_z))
                                + (float)((float)(v69.m_y - v55[0].m_y) * (float)(v69.m_y - v55[0].m_y))))) < v7->m_pLinkBase->m_linkDat.m_mayUseDist )
    {
      v34 = (float)((float)((float)(v69.m_x - v55[0].m_x) * (float)v22)
                  + (float)((float)((float)(v69.m_z - v55[0].m_z) * (float)v24)
                          + (float)((float)(v69.m_y - v55[0].m_y) * (float)v23)));
      PathAreas = bfx::SmartPath::GetPathAreas(
                    this: this->m_commonState.m_pSmartPath,
                    numAreasInFirstSurfaceSectionOut: &v68);
      m_pProxy = this->m_commonState.m_surfer.m_area.m_pProxy;
      if ( m_pProxy != nullptr )
        m_pArea = m_pProxy->m_pArea;
      else
        m_pArea = nullptr;
      if ( v34 < 0.0 && PathAreas->m_data[v68 - 1] == m_pArea )
      {
        v38 = this->m_commonState.m_surfer.m_pos.m_x;
        m_tinyStep = true;
        v39 = this->m_commonState.m_surfer.m_pos.m_y;
        v40 = this->m_commonState.m_surfer.m_pos.m_z;
        v55[0].m_y = this->m_commonState.m_surfer.m_pos.m_y;
        v55[0].m_x = v38;
        v55[0].m_z = v40;
        v56 = v38;
        v57 = v39;
        v58 = v40;
        v59 = v38;
        v60 = v39;
        v61 = v40;
      }
    }
    v65 = v24;
    v62 = 1;
    v63 = v22;
    m_pTune = this->m_pTune;
    v64 = v23;
    m_turnBeforeJumpAngle = m_pTune->m_jumperTune.m_turnBeforeJumpAngle;
    goto LABEL_28;
  }
  if ( spec->m_orientAtGoalEnable )
  {
    m_stopAtGoal = spec->m_stopAtGoal;
    v44 = spec->m_orientAtGoalDir.m_x;
    v45 = spec->m_orientAtGoalDir.m_y;
    v62 = 1;
    v46 = spec->m_orientAtGoalDir.m_z;
    v63 = v44;
    v64 = v45;
    v65 = v46;
    if ( m_stopAtGoal )
      m_turnBeforeJumpAngle = 5.0;
    else
      m_turnBeforeJumpAngle = 45.0;
LABEL_28:
    v66 = m_turnBeforeJumpAngle;
  }
  this->m_behavior.m_pWalker->GotoPos(
    this: this->m_behavior.m_pWalker,
    a2: (const bfx::WalkerGoalData *)&v56,
    a3: (const bfx::GPSpec *)&m_mayUseDist,
    a4: forceUpdate);
  *((_BYTE *)this + 872) &= ~0x10u;
}


// ========================================================================
// ?GotoPosInternal@MoverImpl@bfx@@AAAXABVVec3@2@ABVGPSpec@2@_N@Z
// EA  : 0x832BA0B0
// RVA : 0x012BA0B0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::GotoPosInternal(
        bfx::MoverImpl *this,
        bfx::IslandGraph *requestedGoalPos,
        const bfx::GPSpec *origSpec,
        BOOL forceUpdate)
{
  bfx::MoverImpl::MoverBehavior *p_m_behavior; // r28
  __int64 v9; // r8
  int v10; // r6
  int v11; // r5
  __int64 v12; // r10
  bool *p_m_tinyStep; // r11
  int i; // ctr
  double v15; // fp1
  __int64 v16; // r8
  bfx::AreaProxy *m_pProxy; // r11
  __int64 v18; // r6
  bfx::Vec3 *ClosestReachableArea; // r3
  bfx::Area *v20; // r30
  double v21; // fp1
  __int64 v22; // r8
  bfx::AreaProxy *v23; // r11
  __int64 v24; // r6
  bfx::Vec3 *v25; // r3
  bfx::Vec3 *ClosestPosInArea; // r3
  float m_y; // r9
  float m_z; // r11
  double v29; // fp28
  double v30; // fp30
  double v31; // fp29
  double Scale; // fp1
  bool v33; // r29
  bfx::MotionBase *m_pCurMotion; // r3
  bfx::Walker *v35; // r3
  double v36; // fp13
  double v37; // fp12
  BOOL m_orientAtGoalEnable; // r10
  bfx::Vec3 *p_m_orientAtGoalDir; // r11
  bfx::Vec3 v40; // [sp+50h] [-110h] BYREF
  bfx::Vec3 v41; // [sp+60h] [-100h] BYREF
  char v42; // [sp+6Ch] [-F4h] BYREF
  bfx::GPSpec v43; // [sp+70h] [-F0h] BYREF
  bfx::PathSpec v44; // [sp+90h] [-D0h] BYREF
  bfx::Matrix v45; // [sp+B0h] [-B0h] BYREF

  p_m_behavior = &this->m_behavior;
  if ( this->m_behavior.m_state != JUMPING && (unsigned __int8)bfx::MoverImpl::ReattachSurfer(this) != 0 )
  {
    LODWORD(v12) = &v42;
    p_m_tinyStep = &origSpec[-1].m_tinyStep;
    for ( i = 7; i != 0; --i )
    {
      p_m_tinyStep += 4;
      HIDWORD(v12) = *(_DWORD *)p_m_tinyStep;
      LODWORD(v12) = v12 + 4;
      *(_DWORD *)v12 = *(_DWORD *)p_m_tinyStep;
    }
    bfx::MoverImpl::ApplyLimits_GotoPosSpec(this, spec: &v43, a3: v11, a4: v10, a5: v9, a6: v12);
    if ( p_m_behavior->m_state == LOCOMOTING )
      forceUpdate = true;
    if ( forceUpdate
      || (v15 = bfx::GetScale(),
          (unsigned __int8)bfx::MoverImpl::IgnoreGotoPosDueToSimilarParams(
                             this,
                             oldGoalPos: &this->m_lastGoalPosActedOn,
                             newGoalPos: (const bfx::Vec3 *)requestedGoalPos,
                             newGotoPosSpec: &v43,
                             ignoreThresholdDist: (float)((float)v15 * (float)0.1)) == 0) )
    {
      bfx::BuildMoverPathSpec(result: &v44, pTune: this->m_pTune);
      m_pProxy = this->m_commonState.m_surfer.m_area.m_pProxy;
      HIDWORD(v18) = m_pProxy != nullptr ? m_pProxy->m_pArea : nullptr;
      if ( HIDWORD(v18) != 0 )
      {
        LODWORD(v18) = &v44;
        ClosestReachableArea = (bfx::Vec3 *)bfx::Planner::GetClosestReachableArea(
                                              this: *((bfx::Planner **)this->m_pSpace->m_components.m_data + 1),
                                              pos: requestedGoalPos,
                                              pathSpec: v18,
                                              a4: v16);
        v20 = (bfx::Area *)ClosestReachableArea;
        if ( ClosestReachableArea != nullptr )
        {
          bfx::GetClosestPosInArea(
            result: &v40,
            pArea: ClosestReachableArea,
            pos: (const bfx::Vec3 *)requestedGoalPos,
            pEdgeIndexOut: nullptr);
          if ( forceUpdate
            || (v21 = bfx::GetScale(),
                (unsigned __int8)bfx::MoverImpl::IgnoreGotoPosDueToSimilarParams(
                                   this,
                                   oldGoalPos: &this->m_goalPos,
                                   newGoalPos: &v40,
                                   newGotoPosSpec: &v43,
                                   ignoreThresholdDist: (float)((float)v21 * (float)0.25)) == 0) )
          {
            if ( this->m_autoObData.m_obstacle.m_pProxy != nullptr )
            {
              bfx::AutoObData::ClearObstacle(this: &this->m_autoObData);
              bfx::MoverImpl::ReattachSurfer(this);
              v23 = this->m_commonState.m_surfer.m_area.m_pProxy;
              if ( v23 != nullptr )
                HIDWORD(v24) = v23->m_pArea;
              else
                HIDWORD(v24) = 0;
              if ( HIDWORD(v24) == 0 )
                return;
              LODWORD(v24) = &v44;
              v25 = (bfx::Vec3 *)bfx::Planner::GetClosestReachableArea(
                                   this: *((bfx::Planner **)this->m_pSpace->m_components.m_data + 1),
                                   pos: requestedGoalPos,
                                   pathSpec: v24,
                                   a4: v22);
              v20 = (bfx::Area *)v25;
              if ( v25 == nullptr )
                return;
              ClosestPosInArea = bfx::GetClosestPosInArea(
                                   result: &v41,
                                   pArea: v25,
                                   pos: (const bfx::Vec3 *)requestedGoalPos,
                                   pEdgeIndexOut: nullptr);
              v40.m_x = ClosestPosInArea->m_x;
              v40.m_y = ClosestPosInArea->m_y;
              v40.m_z = ClosestPosInArea->m_z;
            }
            bfx::SmartPath::SetGoalData(
              this: this->m_commonState.m_pSmartPath,
              goalPos: (const bfx::Vec3 *)requestedGoalPos,
              pGoalArea: v20);
            m_y = this->m_commonState.m_surfer.m_pos.m_y;
            m_z = this->m_commonState.m_surfer.m_pos.m_z;
            v41.m_x = this->m_commonState.m_surfer.m_pos.m_x;
            v41.m_y = m_y;
            v41.m_z = m_z;
            v29 = (float)(m_z - v40.m_z);
            v30 = (float)(m_y - v40.m_y);
            v31 = (float)(v41.m_x - v40.m_x);
            Scale = bfx::GetScale();
            v33 = (float)((float)((float)v31 * (float)v31)
                        + (float)((float)((float)v29 * (float)v29) + (float)((float)v30 * (float)v30))) < (double)(float)((float)((float)Scale * (float)0.1) * (float)((float)Scale * (float)0.1));
            if ( p_m_behavior->m_state == 0 || p_m_behavior->m_state == LOCOMOTING )
            {
              this->m_behavior.m_pCurMotion->GetMatrix(this: this->m_behavior.m_pCurMotion, a2: &v45);
              m_pCurMotion = p_m_behavior->m_pCurMotion;
              if ( m_pCurMotion != nullptr )
                ((void (__fastcall *)(bfx::MotionBase *, int))m_pCurMotion->dtr_MotionBase)(a1: m_pCurMotion, a2: 1);
              p_m_behavior->m_pCurMotion = nullptr;
              p_m_behavior->m_pWalker = nullptr;
              p_m_behavior->m_pLocomoter = nullptr;
              p_m_behavior->m_pJumper = nullptr;
              p_m_behavior->m_pIdle = nullptr;
              p_m_behavior->m_pPuppet = nullptr;
              p_m_behavior->m_state = PATH_WALKING;
              v35 = bfx::CreateWalker(mat: &v45, commonState: &this->m_commonState);
              p_m_behavior->m_pWalker = v35;
              p_m_behavior->m_pCurMotion = v35;
              this->m_behavior.m_pWalker->Initialize(this: this->m_behavior.m_pWalker, a2: &this->m_vel, a3: &v45);
            }
            v43.m_tinyStep = v33;
            v36 = v40.m_y;
            v37 = v40.m_z;
            this->m_goalPos.m_x = v40.m_x;
            this->m_goalPos.m_y = v36;
            this->m_goalPos.m_z = v37;
            bfx::MoverImpl::WalkerGotoPos(this, spec: &v43, forceUpdate);
            this->m_lastGoalPosActedOn.m_x = *(float *)&requestedGoalPos->m_numIslandsInUse;
            m_orientAtGoalEnable = v43.m_orientAtGoalEnable;
            this->m_lastGoalPosActedOn.m_y = *(float *)&requestedGoalPos->m_availableIslandNumbers.m_pPool;
            this->m_lastGoalPosActedOn.m_z = *(float *)&requestedGoalPos->m_availableIslandNumbers.m_poolAutoPtr.m_data;
            if ( m_orientAtGoalEnable )
              p_m_orientAtGoalDir = &v43.m_orientAtGoalDir;
            else
              p_m_orientAtGoalDir = &bfx::ZERO_VEC;
            this->m_lastGoalDirActedOn.m_x = p_m_orientAtGoalDir->m_x;
            this->m_lastGoalDirActedOn.m_y = p_m_orientAtGoalDir->m_y;
            this->m_lastGoalDirActedOn.m_z = p_m_orientAtGoalDir->m_z;
            p_m_behavior->m_state = PATH_WALKING;
            *((_BYTE *)this + 872) &= ~0x10u;
          }
        }
      }
    }
  }
}


// ========================================================================
// ?GotoPosCommand@MoverImpl@bfx@@AAAXABVCommandData@2@_N@Z
// EA  : 0x832BA450
// RVA : 0x012BA450
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::GotoPosCommand(
        bfx::MoverImpl *this,
        const bfx::CommandData *commandData,
        BOOL forceUpdate)
{
  char *v3; // r10
  BOOL v5; // r6
  bfx::Vec3 *p_m_vec; // r30
  bool *p_m_forceGotoPosUpdate; // r11
  int i; // ctr
  bool m_stopAtGoal; // r10
  bool m_pushThroughCrowdAtGoal; // r9
  bool m_orientAtGoalEnable; // r8
  bool m_tinyStep; // r7
  double m_allowedToStopDist; // fp0
  double m_desiredStopDist; // fp13
  double m_y; // fp11
  double m_z; // fp10
  char v17; // [sp+4Ch] [-44h] BYREF
  bfx::GPSpec v18; // [sp+50h] [-40h] BYREF

  v3 = &v17;
  v5 = forceUpdate;
  p_m_vec = &commandData->m_vec;
  p_m_forceGotoPosUpdate = &commandData->m_forceGotoPosUpdate;
  for ( i = 7; i != 0; --i )
  {
    p_m_forceGotoPosUpdate += 4;
    v3 += 4;
    *(_DWORD *)v3 = *(_DWORD *)p_m_forceGotoPosUpdate;
  }
  if ( (*((_BYTE *)this + 872) & 0x80) != 0
    && (unsigned __int8)bfx::MoverImpl::ForcePathUpdateDueToSpecChange(
                          this,
                          oldSpec: &this->m_gotoPosSpec,
                          newSpec: &v18) != 0 )
  {
    v5 = true;
  }
  bfx::MoverImpl::GotoPosInternal(this, requestedGoalPos: (bfx::IslandGraph *)p_m_vec, origSpec: &v18, forceUpdate: v5);
  this->m_lastRequestedGoalPos.m_x = p_m_vec->m_x;
  m_stopAtGoal = v18.m_stopAtGoal;
  m_pushThroughCrowdAtGoal = v18.m_pushThroughCrowdAtGoal;
  this->m_lastRequestedGoalPos.m_y = p_m_vec->m_y;
  m_orientAtGoalEnable = v18.m_orientAtGoalEnable;
  m_tinyStep = v18.m_tinyStep;
  this->m_lastRequestedGoalPos.m_z = p_m_vec->m_z;
  this->m_gotoPosSpec.m_stopAtGoal = m_stopAtGoal;
  m_allowedToStopDist = v18.m_allowedToStopDist;
  this->m_gotoPosSpec.m_pushThroughCrowdAtGoal = m_pushThroughCrowdAtGoal;
  m_desiredStopDist = v18.m_desiredStopDist;
  this->m_gotoPosSpec.m_orientAtGoalEnable = m_orientAtGoalEnable;
  this->m_gotoPosSpec.m_allowedToStopDist = m_allowedToStopDist;
  this->m_gotoPosSpec.m_desiredStopDist = m_desiredStopDist;
  m_y = v18.m_orientAtGoalDir.m_y;
  m_z = v18.m_orientAtGoalDir.m_z;
  this->m_gotoPosSpec.m_orientAtGoalDir.m_x = v18.m_orientAtGoalDir.m_x;
  this->m_gotoPosSpec.m_orientAtGoalDir.m_y = m_y;
  this->m_gotoPosSpec.m_orientAtGoalDir.m_z = m_z;
  this->m_gotoPosSpec.m_tinyStep = m_tinyStep;
  *((_BYTE *)this + 872) = *((_BYTE *)this + 872) & 0x5F | 0x80;
}


// ========================================================================
// ?GotoPos@MoverImpl@bfx@@QAAXABVVec3@2@ABVGPSpec@2@_N@Z
// EA  : 0x832BA568
// RVA : 0x012BA568
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::GotoPos(
        bfx::MoverImpl *this,
        const bfx::Vec3 *inputGoalPos,
        const bfx::GPSpec *origSpec,
        bool forceUpdate)
{
  __int64 v8; // r10
  __int64 v9; // r8
  int v10; // r6
  const char *v11; // r5
  char v12; // r10
  bfx::CommandData *p_m_lastMovementCommand; // r4
  double m_y; // fp13
  double m_z; // fp12
  bfx::MoverImpl::State m_state; // r11
  bfx::FTimerOb v17; // [sp+50h] [-50h] BYREF
  bfx::Vec3 *p_m_vec; // [sp+54h] [-4Ch]
  bfx::Vec3 v19; // [sp+58h] [-48h] BYREF

  bfx::FTimerOb::FTimerOb(this: &v17, timerEntry: &bfx::gotoposTimer);
  LODWORD(v8) = &dword_82420000;
  HIDWORD(v8) = &dword_82420000;
  LODWORD(v9) = &dword_82420000;
  HIDWORD(v9) = "Mover::GotoPos goalPos";
  bfx::LimitWarn(
    result: &v19,
    vec: inputGoalPos,
    min: -1.8446743e19,
    max: 1.8446743e19,
    name: v11,
    a6: v10,
    a7: v9,
    a8: v8);
  v12 = 1;
  p_m_lastMovementCommand = &this->m_lastMovementCommand;
  if ( this->m_lastMovementCommand.m_command == STOP_COMMAND )
    forceUpdate = true;
  p_m_lastMovementCommand->m_command = GOTOPOS_COMMAND;
  m_y = v19.m_y;
  m_z = v19.m_z;
  this->m_lastMovementCommand.m_vec.m_x = v19.m_x;
  this->m_lastMovementCommand.m_vec.m_y = m_y;
  p_m_vec = &this->m_lastMovementCommand.m_vec;
  this->m_lastMovementCommand.m_vec.m_z = m_z;
  this->m_lastMovementCommand.m_forceGotoPosUpdate = forceUpdate;
  this->m_lastMovementCommand.m_gpSpec.m_allowedToStopDist = origSpec->m_allowedToStopDist;
  this->m_lastMovementCommand.m_gpSpec.m_desiredStopDist = origSpec->m_desiredStopDist;
  p_m_vec = &this->m_lastMovementCommand.m_gpSpec.m_orientAtGoalDir;
  this->m_lastMovementCommand.m_gpSpec.m_stopAtGoal = origSpec->m_stopAtGoal;
  this->m_lastMovementCommand.m_gpSpec.m_pushThroughCrowdAtGoal = origSpec->m_pushThroughCrowdAtGoal;
  this->m_lastMovementCommand.m_gpSpec.m_orientAtGoalEnable = origSpec->m_orientAtGoalEnable;
  this->m_lastMovementCommand.m_gpSpec.m_orientAtGoalDir.m_x = origSpec->m_orientAtGoalDir.m_x;
  this->m_lastMovementCommand.m_gpSpec.m_orientAtGoalDir.m_y = origSpec->m_orientAtGoalDir.m_y;
  this->m_lastMovementCommand.m_gpSpec.m_orientAtGoalDir.m_z = origSpec->m_orientAtGoalDir.m_z;
  this->m_lastMovementCommand.m_gpSpec.m_tinyStep = origSpec->m_tinyStep;
  m_state = this->m_behavior.m_state;
  this->m_asyncGotoPosData.m_isValid = false;
  if ( m_state == JUMPING )
    this->m_applyCommandOnJumpEnd = true;
  if ( m_state == PUPPET )
    this->m_applyCommandOnPuppetDisable = true;
  if ( m_state != JUMPING && m_state != PUPPET )
    v12 = 0;
  if ( v12 == 0 )
  {
    bfx::MoverImpl::GotoPosCommand(
      this,
      commandData: p_m_lastMovementCommand,
      forceUpdate: this->m_lastMovementCommand.m_forceGotoPosUpdate);
    bfx::MoverImpl::ClearFollowMode(this);
    *((_BYTE *)this + 872) &= ~0x10u;
  }
  if ( v17.m_pFTimer != nullptr )
    bfx::FTimer::Stop(this: v17.m_pFTimer);
}


// ========================================================================
// __unwind$35001
// EA  : 0x832BA6DC
// RVA : 0x012BA6DC
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void _unwind_35001()
{
  int v0; // r12

  bfx::FTimerOb::~FTimerOb(this: (bfx::FTimerOb *)(v0 - 160 + 80));
}


// ========================================================================
// ?MoveInDirectionCommand@MoverImpl@bfx@@AAAXABVCommandData@2@@Z
// EA  : 0x832BA708
// RVA : 0x012BA708
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::MoveInDirectionCommand(bfx::MoverImpl *this, const bfx::CommandData *commandData)
{
  double m_moveInDirectionSpeed; // fp31
  bfx::MoverImpl::State m_state; // r11
  bfx::AreaProxy *m_pProxy; // r11
  bfx::Area *m_pArea; // r27
  bfx::MotionBase *m_pCurMotion; // r3
  bfx::Locomoter *v8; // r3
  bfx::Matrix v9; // [sp+60h] [-80h] BYREF

  m_moveInDirectionSpeed = commandData->m_moveInDirectionSpeed;
  if ( (unsigned __int8)bfx::MoverImpl::ReattachSurfer(this) != 0 )
  {
    m_state = this->m_behavior.m_state;
    if ( (unsigned int)m_state < LOCOMOTING )
    {
      this->m_behavior.m_pCurMotion->GetMatrix(this: this->m_behavior.m_pCurMotion, a2: &v9);
      m_pProxy = this->m_commonState.m_surfer.m_area.m_pProxy;
      if ( m_pProxy != nullptr )
        m_pArea = m_pProxy->m_pArea;
      else
        m_pArea = nullptr;
      m_pCurMotion = this->m_behavior.m_pCurMotion;
      if ( m_pCurMotion != nullptr )
        ((void (__fastcall *)(bfx::MotionBase *, int))m_pCurMotion->dtr_MotionBase)(a1: m_pCurMotion, a2: 1);
      this->m_behavior.m_pCurMotion = nullptr;
      this->m_behavior.m_pWalker = nullptr;
      this->m_behavior.m_pLocomoter = nullptr;
      this->m_behavior.m_pJumper = nullptr;
      this->m_behavior.m_pIdle = nullptr;
      this->m_behavior.m_pPuppet = nullptr;
      this->m_behavior.m_state = LOCOMOTING;
      v8 = bfx::CreateLocomoter(startMat: &v9, pStartArea: m_pArea, commonState: &this->m_commonState);
      this->m_behavior.m_pLocomoter = v8;
      this->m_behavior.m_pCurMotion = v8;
      bfx::PathSharingHelper::ClearAll(this: &this->m_pathSharingHelper);
      ((void (__fastcall *)(double))this->m_behavior.m_pLocomoter->SetMoveParams)(a1: m_moveInDirectionSpeed);
    }
    else if ( m_state == LOCOMOTING )
    {
      ((void (__fastcall *)(double))this->m_behavior.m_pLocomoter->SetMoveParams)(a1: m_moveInDirectionSpeed);
    }
  }
}


// ========================================================================
// ?MoveInDirection@MoverImpl@bfx@@QAAXABVVec3@2@MABVMoveInDirectionSpec@2@@Z
// EA  : 0x832BA850
// RVA : 0x012BA850
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::MoveInDirection(
        bfx::MoverImpl *this,
        const bfx::Vec3 *dir,
        double speed,
        const bfx::MoveInDirectionSpec *spec,
        bfx::MIDSpec *a5)
{
  bfx::CommandData *p_m_lastMovementCommand; // r31
  bfx::MoverImpl::State m_state; // r11
  char v8; // r11
  bool v9; // zf
  bfx::MIDSpec v10[2]; // [sp+50h] [-20h] BYREF

  this->m_lastMovementCommand.m_command = LOCOMOTE_COMMAND;
  p_m_lastMovementCommand = &this->m_lastMovementCommand;
  this->m_lastMovementCommand.m_vec = *dir;
  this->m_lastMovementCommand.m_moveInDirectionSpeed = speed;
  this->m_lastMovementCommand.m_midSpec = *bfx::MIDSpec::MIDSpec(this: v10, inputSpec: a5);
  m_state = this->m_behavior.m_state;
  this->m_asyncGotoPosData.m_isValid = false;
  if ( m_state == JUMPING )
    this->m_applyCommandOnJumpEnd = true;
  if ( m_state == PUPPET )
    this->m_applyCommandOnPuppetDisable = true;
  if ( m_state == JUMPING || (v9 = m_state != PUPPET, v8 = 0, !v9) )
    v8 = 1;
  if ( v8 == 0 )
  {
    bfx::MoverImpl::MoveInDirectionCommand(this, commandData: p_m_lastMovementCommand);
    bfx::MoverImpl::ClearFollowMode(this);
    *((_BYTE *)this + 872) &= ~0x10u;
  }
}


// ========================================================================
// ?SwitchToPuppetMode@MoverImpl@bfx@@AAAXXZ
// EA  : 0x832BA940
// RVA : 0x012BA940
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::SwitchToPuppetMode(bfx::MoverImpl *this)
{
  bfx::MoverImpl::State m_state; // r11
  bfx::MotionBase *m_pCurMotion; // r3
  bfx::Puppet *v4; // r3
  bfx::RepulsorImpl *m_pRepulsor; // r11
  bfx::Matrix v6; // [sp+50h] [-70h] BYREF

  this->m_behavior.m_pCurMotion->GetMatrix(this: this->m_behavior.m_pCurMotion, a2: &v6);
  m_state = this->m_behavior.m_state;
  this->m_prePuppetModeState = m_state;
  if ( (m_state == PATH_WALKING || m_state == JUMPING) && this->m_lastMovementCommand.m_command == STOP_COMMAND )
    this->m_prePuppetModeState = 0;
  this->m_stranded = false;
  m_pCurMotion = this->m_behavior.m_pCurMotion;
  if ( m_pCurMotion != nullptr )
    ((void (__fastcall *)(bfx::MotionBase *, int))m_pCurMotion->dtr_MotionBase)(a1: m_pCurMotion, a2: 1);
  this->m_behavior.m_pCurMotion = nullptr;
  this->m_behavior.m_pWalker = nullptr;
  this->m_behavior.m_pLocomoter = nullptr;
  this->m_behavior.m_pJumper = nullptr;
  this->m_behavior.m_pIdle = nullptr;
  this->m_behavior.m_pPuppet = nullptr;
  this->m_behavior.m_state = PUPPET;
  v4 = bfx::CreatePuppet(startMat: &v6, commonState: &this->m_commonState);
  this->m_behavior.m_pPuppet = v4;
  this->m_behavior.m_pCurMotion = v4;
  bfx::PathSharingHelper::ClearAll(this: &this->m_pathSharingHelper);
  m_pRepulsor = this->m_commonState.m_pRepulsor;
  if ( m_pRepulsor != nullptr )
  {
    m_pRepulsor->m_bulk = 3.4028235e38;
    bfx::RepulsorImpl::SetArea(this: this->m_commonState.m_pRepulsor, pArea: nullptr);
  }
}


// ========================================================================
// ?JumpingToLocomoting@MoverImpl@bfx@@AAAXXZ
// EA  : 0x832BAA30
// RVA : 0x012BAA30
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::JumpingToLocomoting(bfx::MoverImpl *this)
{
  bfx::SmartPath *m_pSmartPath; // r3
  bfx::Vec3 *SnappedStartArea; // r28
  bfx::Vec3 *ClosestPosInArea; // r3
  bfx::MotionBase *m_pCurMotion; // r3
  bfx::Locomoter *v6; // r3
  bfx::HandleProxy *m_pProxy; // r3
  bfx::Vec3 v8; // [sp+58h] [-B8h] BYREF
  bfx::Vec3 v9[2]; // [sp+68h] [-A8h] BYREF
  bfx::PathSpec v10; // [sp+80h] [-90h] BYREF
  bfx::Matrix v11; // [sp+A0h] [-70h] BYREF

  this->m_behavior.m_pJumper->GetMatrix(this: this->m_behavior.m_pJumper, a2: &v11);
  m_pSmartPath = this->m_commonState.m_pSmartPath;
  v8.m_x = v11.m_data[12];
  v8.m_y = v11.m_data[13];
  v8.m_z = v11.m_data[14];
  SnappedStartArea = (bfx::Vec3 *)bfx::SmartPath::GetSnappedStartArea(this: m_pSmartPath);
  if ( SnappedStartArea == nullptr )
  {
    bfx::BuildMoverPathSpec(result: &v10, pTune: this->m_pTune);
    v10.m_obstacleBlockageFlags = 0;
    SnappedStartArea = (bfx::Vec3 *)bfx::Planner::GetClosestArea(
                                      this: *((bfx::Planner **)this->m_pSpace->m_components.m_data + 1),
                                      pos: &v8,
                                      layerNum: this->m_pTune->m_planLayer,
                                      pathSpec: &v10);
    ClosestPosInArea = bfx::GetClosestPosInArea(result: v9, pArea: SnappedStartArea, pos: &v8, pEdgeIndexOut: nullptr);
    v8.m_x = ClosestPosInArea->m_x;
    v8.m_y = ClosestPosInArea->m_y;
    v8.m_z = ClosestPosInArea->m_z;
    *(bfx::Vec3 *)&v11.m_data[12] = v8;
  }
  m_pCurMotion = this->m_behavior.m_pCurMotion;
  if ( m_pCurMotion != nullptr )
    ((void (__fastcall *)(bfx::MotionBase *, int))m_pCurMotion->dtr_MotionBase)(a1: m_pCurMotion, a2: 1);
  this->m_behavior.m_pCurMotion = nullptr;
  this->m_behavior.m_pWalker = nullptr;
  this->m_behavior.m_pLocomoter = nullptr;
  this->m_behavior.m_pJumper = nullptr;
  this->m_behavior.m_pIdle = nullptr;
  this->m_behavior.m_pPuppet = nullptr;
  this->m_behavior.m_state = LOCOMOTING;
  v6 = bfx::CreateLocomoter(
         startMat: &v11,
         pStartArea: (bfx::Area *)SnappedStartArea,
         commonState: &this->m_commonState);
  this->m_behavior.m_pLocomoter = v6;
  this->m_behavior.m_pCurMotion = v6;
  ((void (__fastcall *)(bfx::Locomoter *, bfx::Vec3 *, double))this->m_behavior.m_pLocomoter->SetMoveParams)(
    a1: this->m_behavior.m_pLocomoter,
    a2: &this->m_lastMovementCommand.m_vec,
    a3: this->m_lastMovementCommand.m_moveInDirectionSpeed);
  bfx::PathSharingHelper::ClearAll(this: &this->m_pathSharingHelper);
  m_pProxy = this->m_curGoalLink.m_pProxy;
  if ( m_pProxy != nullptr )
  {
    bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
    this->m_curGoalLink.m_pProxy = nullptr;
  }
}


// ========================================================================
// ?JumpingToIdle@MoverImpl@bfx@@AAAXXZ
// EA  : 0x832BABB8
// RVA : 0x012BABB8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::JumpingToIdle(bfx::MoverImpl *this)
{
  bfx::Area *SnappedStartArea; // r28
  bfx::MotionBase *m_pCurMotion; // r3
  bfx::Idle *v4; // r3
  bfx::HandleProxy *m_pProxy; // r3
  bfx::Matrix v6; // [sp+50h] [-70h] BYREF

  this->m_behavior.m_pJumper->GetMatrix(this: this->m_behavior.m_pJumper, a2: &v6);
  SnappedStartArea = bfx::SmartPath::GetSnappedStartArea(this: this->m_commonState.m_pSmartPath);
  m_pCurMotion = this->m_behavior.m_pCurMotion;
  if ( m_pCurMotion != nullptr )
    ((void (__fastcall *)(bfx::MotionBase *, int))m_pCurMotion->dtr_MotionBase)(a1: m_pCurMotion, a2: 1);
  this->m_behavior.m_pCurMotion = nullptr;
  this->m_behavior.m_pWalker = nullptr;
  this->m_behavior.m_pLocomoter = nullptr;
  this->m_behavior.m_pJumper = nullptr;
  this->m_behavior.m_pIdle = nullptr;
  this->m_behavior.m_pPuppet = nullptr;
  this->m_behavior.m_state = 0;
  v4 = bfx::CreateIdle(
         startMat: &v6,
         pStartArea: SnappedStartArea,
         commonState: &this->m_commonState,
         preserveExactInputHeight: false);
  this->m_behavior.m_pIdle = v4;
  this->m_behavior.m_pCurMotion = v4;
  bfx::PathSharingHelper::ClearAll(this: &this->m_pathSharingHelper);
  m_pProxy = this->m_curGoalLink.m_pProxy;
  if ( m_pProxy != nullptr )
  {
    bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
    this->m_curGoalLink.m_pProxy = nullptr;
  }
}


// ========================================================================
// ?WalkingToJumping@MoverImpl@bfx@@AAAX_N@Z
// EA  : 0x832BAC80
// RVA : 0x012BAC80
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::WalkingToJumping(bfx::MoverImpl *this, BOOL startJumpFrozen)
{
  bfx::HandleProxy *m_pProxy; // r11
  bfx::HalfLink *m_pTarget; // r26
  const bfx::Array<bfx::Area *> *PathAreas; // r3
  bfx::Vec3 **v7; // r11
  bfx::Area *v8; // r25
  bfx::Vec3 *v9; // r28
  const bfx::MoverTune *m_pTune; // r11
  BOOL v11; // r24
  unsigned int m_planLayer; // r11
  bfx::NavLayer *v13; // r29
  double v14; // fp12
  double v15; // fp13
  double v16; // fp0
  double v17; // fp7
  double v18; // fp5
  double v19; // fp6
  double m_radius; // fp13
  double v23; // fp12
  double m_x; // fp11
  double m_y; // fp10
  double m_z; // fp9
  const bfx::Handle<bfx::Area> *v27; // r3
  const bfx::Handle<bfx::Area> *v28; // r3
  bfx::MotionBase *m_pCurMotion; // r3
  bfx::JumperImpl *v30; // r3
  bool Ground; // r3
  bfx::Vec3 v32; // [sp+50h] [-160h] BYREF
  bfx::Area v33; // [sp+60h] [-150h] BYREF
  float v34; // [sp+98h] [-118h]
  bfx::Vec3 v35; // [sp+A0h] [-110h] BYREF
  bfx::Vec3 v36; // [sp+B0h] [-100h] BYREF
  bfx::Matrix v37; // [sp+C0h] [-F0h] BYREF
  bfx::Vec3 v38; // [sp+100h] [-B0h] BYREF
  bfx::Matrix v39; // [sp+110h] [-A0h] BYREF

  m_pProxy = this->m_curGoalLink.m_pProxy;
  LODWORD(v33.m_pos.m_x) = &this->m_curGoalLink;
  if ( m_pProxy != nullptr )
  {
    m_pTarget = (bfx::HalfLink *)m_pProxy->m_pTarget;
    LODWORD(v33.m_pos.m_x) = m_pProxy;
  }
  else
  {
    m_pTarget = nullptr;
  }
  PathAreas = bfx::SmartPath::GetPathAreas(
                this: this->m_commonState.m_pSmartPath,
                numAreasInFirstSurfaceSectionOut: (int *)&v33.m_flags);
  v7 = (bfx::Vec3 **)&PathAreas->m_data[v33.m_flags.m_flags1];
  v8 = (bfx::Area *)*(v7 - 1);
  v9 = *v7;
  this->m_behavior.m_pWalker->GetMatrix(this: this->m_behavior.m_pWalker, a2: &v37);
  m_pTune = this->m_pTune;
  v33.m_pos.m_z = v37.m_data[12];
  v33.m_radius = v37.m_data[13];
  *(float *)&v33.m_searchCost = v37.m_data[14];
  bfx::ComputeFinalJumpPosition(
    result: &v32,
    pLink: m_pTarget,
    jumperStartPos: (const bfx::Vec3 *)&v33.m_pos.m_z,
    allowPileupAtLinkExit: m_pTune->m_jumperTune.m_onlyJumpToEndPoint);
  this->m_commonState.m_orienter.m_headingVel = 0.0;
  v11 = true;
  v32 = *bfx::GetClosestPosInArea(result: &v38, pArea: v9, pos: &v32, pEdgeIndexOut: nullptr);
  bfx::Area::CalcNormal(this: &v33, result: v9);
  m_planLayer = this->m_commonState.m_pTune->m_planLayer;
  if ( m_planLayer >= 0x20 )
    v13 = nullptr;
  else
    v13 = *(bfx::NavLayer **)(4 * (m_planLayer + 2) + *((_DWORD *)this->m_pSpace->m_components.m_data + 1));
  if ( this->m_commonState.m_pProber == nullptr )
    goto LABEL_11;
  if ( bfx::AreBatchProbeRequestsEnabled() && (unsigned __int8)bfx::IsColliderSet() == 0 )
  {
    v11 = true;
LABEL_11:
    v14 = *(float *)&v33.m_pProxy;
    v15 = *(float *)&v33.m_dynAreaData.m_data;
    v16 = *(float *)&v33.m_pFirstLink;
    goto LABEL_12;
  }
  Ground = bfx::Prober::ProbeToFindGround(
             this: this->m_commonState.m_pProber,
             pNavLayer: v13,
             surferPos: &v32,
             localUpAxis: (const bfx::Vec3 *)&v33,
             heightOut: (float *)&v33.m_pSearchParent);
  v16 = *(float *)&v33.m_pFirstLink;
  v15 = *(float *)&v33.m_dynAreaData.m_data;
  v14 = *(float *)&v33.m_pProxy;
  if ( Ground )
  {
    v11 = false;
    v32.m_z = v32.m_z + (float)(*(float *)&v33.m_pFirstLink * *(float *)&v33.m_pSearchParent);
    v32.m_y = v32.m_y + (float)(*(float *)&v33.m_dynAreaData.m_data * *(float *)&v33.m_pSearchParent);
    v32.m_x = (float)(*(float *)&v33.m_pProxy * *(float *)&v33.m_pSearchParent) + v32.m_x;
  }
LABEL_12:
  LODWORD(v36.m_z) = v33.m_pFirstLink;
  LODWORD(v36.m_x) = v33.m_pProxy;
  LODWORD(v36.m_y) = v33.m_dynAreaData.m_data;
  v17 = (float)((float)((float)v16 * (float)(v32.m_x - v33.m_pos.m_z))
              - (float)((float)(v32.m_z - *(float *)&v33.m_searchCost) * (float)v14));
  v18 = (float)((float)((float)(v32.m_y - v33.m_radius) * (float)v14)
              - (float)((float)v15 * (float)(v32.m_x - v33.m_pos.m_z)));
  v19 = (float)((float)((float)v15 * (float)(v32.m_z - *(float *)&v33.m_searchCost))
              - (float)((float)v16 * (float)(v32.m_y - v33.m_radius)));
  _FP11 = (float)((float)__fsqrts((float)((float)((float)v18 * (float)v18)
                                        + (float)((float)((float)v19 * (float)v19) + (float)((float)v17 * (float)v17))))
                - (float)1.0842022e-19);
  __asm { fsel      f9, f11, f10, f31 }
  *(float *)&v33.m_flags.m_flags4 = (float)((float)((float)v16 * (float)(v32.m_x - v33.m_pos.m_z))
                                          - (float)((float)(v32.m_z - *(float *)&v33.m_searchCost) * (float)v14))
                                  * (float)_FP9;
  v34 = (float)((float)((float)(v32.m_y - v33.m_radius) * (float)v14)
              - (float)((float)v15 * (float)(v32.m_x - v33.m_pos.m_z)))
      * (float)_FP9;
  *(float *)&v33.m_flags.m_flags3 = (float)((float)((float)v15 * (float)(v32.m_z - *(float *)&v33.m_searchCost))
                                          - (float)((float)v16 * (float)(v32.m_y - v33.m_radius)))
                                  * (float)_FP9;
  v35.m_z = (float)((float)v15 * *(float *)&v33.m_flags.m_flags3)
          - (float)(*(float *)&v33.m_flags.m_flags4 * (float)v14);
  v35.m_x = (float)((float)v16 * *(float *)&v33.m_flags.m_flags4) - (float)((float)v15 * v34);
  v35.m_y = (float)(v34 * (float)v14) - (float)((float)v16 * *(float *)&v33.m_flags.m_flags3);
  bfx::Matrix::Build(this: &v39, xAxis: &v35, yAxis: (const bfx::Vec3 *)&v33.m_flags.m_flags3, zAxis: &v36, trans: &v32);
  bfx::Handle<bfx::MoverImpl>::operator=(this: &this->m_jumpClientData.m_link, pTarget: m_pTarget->m_pLinkBase);
  m_radius = v33.m_radius;
  v23 = *(float *)&v33.m_searchCost;
  m_x = v32.m_x;
  m_y = v32.m_y;
  m_z = v32.m_z;
  this->m_jumpClientData.m_startPos.m_x = v33.m_pos.m_z;
  v33.m_pSearchParent = (bfx::Area *)&this->m_jumpClientData.m_endPos;
  this->m_jumpClientData.m_startPos.m_y = m_radius;
  this->m_jumpClientData.m_startPos.m_z = v23;
  this->m_jumpClientData.m_endPos.m_x = m_x;
  this->m_jumpClientData.m_endPos.m_y = m_y;
  this->m_jumpClientData.m_endPos.m_z = m_z;
  v27 = bfx::Handle<bfx::Area>::Handle<bfx::Area>(this: (bfx::Handle<bfx::Area> *)&v33.m_usageFlags, pArea: v8);
  bfx::Handle<bfx::Area>::operator=(this: &this->m_jumpClientData.m_startArea, rhs: v27);
  bfx::Handle<bfx::Area>::Release(this: (bfx::Handle<bfx::Area> *)&v33.m_usageFlags);
  v28 = bfx::Handle<bfx::Area>::Handle<bfx::Area>(this: (bfx::Handle<bfx::Area> *)&v33.m_pos, pArea: (bfx::Area *)v9);
  bfx::Handle<bfx::Area>::operator=(this: &this->m_jumpClientData.m_endArea, rhs: v28);
  bfx::Handle<bfx::Area>::Release(this: (bfx::Handle<bfx::Area> *)&v33.m_pos);
  m_pCurMotion = this->m_behavior.m_pCurMotion;
  if ( m_pCurMotion != nullptr )
    ((void (__fastcall *)(bfx::MotionBase *, int))m_pCurMotion->dtr_MotionBase)(a1: m_pCurMotion, a2: 1);
  this->m_behavior.m_pCurMotion = nullptr;
  this->m_behavior.m_pWalker = nullptr;
  this->m_behavior.m_pLocomoter = nullptr;
  this->m_behavior.m_pJumper = nullptr;
  this->m_behavior.m_pIdle = nullptr;
  this->m_behavior.m_pPuppet = nullptr;
  this->m_behavior.m_state = JUMPING;
  v30 = bfx::CreateJumper(startMat: &v37, commonState: &this->m_commonState);
  this->m_behavior.m_pJumper = v30;
  this->m_behavior.m_pCurMotion = v30;
  this->m_behavior.m_pJumper->Initialize(
    this: this->m_behavior.m_pJumper,
    a2: &v37,
    a3: &v39,
    a4: startJumpFrozen,
    a5: m_pTarget->m_pLinkBase,
    a6: (bfx::Area *)v9,
    a7: nullptr,
    a8: v11);
  this->m_applyCommandOnJumpEnd = false;
}


// ========================================================================
// __unwind$35469
// EA  : 0x832BB058
// RVA : 0x012BB058
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void _unwind_35469()
{
  int v0; // r12

  bfx::Handle<bfx::Area>::~Handle<bfx::Area>(this: (bfx::AreaHandleImpl *)(v0 - 432 + 132));
}


// ========================================================================
// __unwind$35470
// EA  : 0x832BB080
// RVA : 0x012BB080
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void _unwind_35470()
{
  int v0; // r12

  bfx::Handle<bfx::Area>::~Handle<bfx::Area>(this: (bfx::AreaHandleImpl *)(v0 - 432 + 112));
}


// ========================================================================
// ?MovingToIdle@MoverImpl@bfx@@AAAXXZ
// EA  : 0x832BB0A8
// RVA : 0x012BB0A8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::MovingToIdle(bfx::MoverImpl *this)
{
  bfx::AreaProxy *m_pProxy; // r11
  bfx::Area *m_pArea; // r27
  bfx::MotionBase *m_pCurMotion; // r3
  bfx::Idle *v5; // r3
  bfx::Matrix v6; // [sp+50h] [-70h] BYREF

  bfx::Orienter::CalcMat(this: &this->m_commonState.m_orienter, pos: &this->m_commonState.m_surfer.m_pos, mat: &v6);
  m_pProxy = this->m_commonState.m_surfer.m_area.m_pProxy;
  if ( m_pProxy != nullptr )
    m_pArea = m_pProxy->m_pArea;
  else
    m_pArea = nullptr;
  m_pCurMotion = this->m_behavior.m_pCurMotion;
  if ( m_pCurMotion != nullptr )
    ((void (__fastcall *)(bfx::MotionBase *, int))m_pCurMotion->dtr_MotionBase)(a1: m_pCurMotion, a2: 1);
  this->m_behavior.m_pCurMotion = nullptr;
  this->m_behavior.m_pWalker = nullptr;
  this->m_behavior.m_pLocomoter = nullptr;
  this->m_behavior.m_pJumper = nullptr;
  this->m_behavior.m_pIdle = nullptr;
  this->m_behavior.m_pPuppet = nullptr;
  this->m_behavior.m_state = 0;
  v5 = bfx::CreateIdle(
         startMat: &v6,
         pStartArea: m_pArea,
         commonState: &this->m_commonState,
         preserveExactInputHeight: false);
  this->m_behavior.m_pIdle = v5;
  this->m_behavior.m_pCurMotion = v5;
  bfx::PathSharingHelper::ClearAll(this: &this->m_pathSharingHelper);
}


// ========================================================================
// ?TeleportInternal@MoverImpl@bfx@@QAAXABVMatrix@2@PAVArea@2@ABVVec3@2@_N3@Z
// EA  : 0x832BB2A8
// RVA : 0x012BB2A8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::TeleportInternal(
        bfx::MoverImpl *this,
        const bfx::Matrix *desiredMat,
        bfx::Area *pNewArea,
        const bfx::Vec3 *newVel,
        bool allowTeleportInsideObstacles,
        bool preserveExactInputHeight)
{
  bfx::Area *m_pArea; // r27
  bfx::AreaProxy *m_pProxy; // r11
  double v13; // fp13
  double v14; // fp12
  bfx::Space *m_pSpace; // r5
  float m_y; // r10
  float m_z; // r9
  bfx::Prober *m_pProber; // r8
  const bfx::MoverTune *m_pTune; // r5
  unsigned int m_planLayer; // r11
  bfx::NavLayer *v21; // r29
  long double v22; // fp2
  double v23; // fp0
  double v24; // fp13
  double v25; // fp12
  bfx::MoverImpl::State m_state; // r11
  bfx::MoverImpl::MoverBehavior *p_m_behavior; // r29
  bfx::Command m_command; // r11
  bfx::MotionBase *m_pCurMotion; // r3
  bfx::Walker *v30; // r3
  __int64 v31; // r10
  __int64 v32; // r8
  float m_arcSpread; // r6
  bfx::MoverImpl **v34; // r11
  __int64 v35; // r6
  __int64 v36; // r6
  bfx::Walker *v37; // r3
  double v38; // fp13
  double v39; // fp12
  bfx::Handle<bfx::Area> v40[2]; // [sp+50h] [-120h] BYREF
  bfx::Vec3 v41; // [sp+58h] [-118h] BYREF
  bfx::Vec3 v42; // [sp+68h] [-108h] BYREF
  bfx::Vec3 v43; // [sp+78h] [-F8h] BYREF
  float v44[4]; // [sp+88h] [-E8h] BYREF
  _DWORD v45[4]; // [sp+98h] [-D8h] BYREF
  bfx::Vec3 v46[2]; // [sp+A8h] [-C8h] BYREF
  bfx::Matrix v47; // [sp+C0h] [-B0h] BYREF
  bfx::PathSpec v48; // [sp+100h] [-70h] BYREF

  m_pArea = pNewArea;
  if ( this->m_pTune->m_autoObTune.m_autoCreateObstacle )
  {
    bfx::Handle<bfx::Area>::Handle<bfx::Area>(this: v40, pArea: pNewArea);
    bfx::AutoObData::ClearObstacle(this: &this->m_autoObData);
    m_pProxy = v40[0].m_pProxy;
    this->m_autoObData.m_timer = 0.0;
    if ( m_pProxy != nullptr )
      m_pArea = m_pProxy->m_pArea;
    else
      m_pArea = nullptr;
    bfx::Handle<bfx::Area>::Release(this: v40);
  }
  v13 = desiredMat->m_data[13];
  v14 = desiredMat->m_data[14];
  v41.m_x = desiredMat->m_data[12];
  v41.m_y = v13;
  v41.m_z = v14;
  if ( m_pArea != nullptr
    || (bfx::BuildMoverPathSpec(result: &v48, pTune: this->m_pTune),
        m_pSpace = this->m_pSpace,
        v48.m_obstacleBlockageFlags &= allowTeleportInsideObstacles - 1,
        (m_pArea = (bfx::Area *)bfx::Planner::GetClosestArea(
                                  this: *((bfx::Planner **)m_pSpace->m_components.m_data + 1),
                                  pos: &v41,
                                  layerNum: this->m_pTune->m_planLayer,
                                  pathSpec: &v48)) != nullptr) )
  {
    bfx::Surfer::SetPosAndArea(this: &this->m_commonState.m_surfer, pos: &v41, pArea: m_pArea);
    bfx::SmartPath::SetStartData(this: this->m_commonState.m_pSmartPath, startPos: &v41, pStartArea: m_pArea);
    m_y = this->m_commonState.m_surfer.m_pos.m_y;
    m_z = this->m_commonState.m_surfer.m_pos.m_z;
    m_pProber = this->m_commonState.m_pProber;
    v42.m_x = this->m_commonState.m_surfer.m_pos.m_x;
    v42.m_y = m_y;
    v42.m_z = m_z;
    if ( m_pProber != nullptr )
    {
      m_pTune = this->m_commonState.m_pTune;
      m_planLayer = m_pTune->m_planLayer;
      if ( m_planLayer >= 0x20 )
        v21 = nullptr;
      else
        v21 = *(bfx::NavLayer **)(*((_DWORD *)this->m_pSpace->m_components.m_data + 1) + 4 * (m_planLayer + 2));
      bfx::GetUpAxisForStandingOnArea(result: v46, pArea: (bfx::Vec3 *)m_pArea, pTune: m_pTune);
      if ( (unsigned __int8)bfx::IsColliderSet() == 0 && bfx::AreBatchProbeRequestsEnabled() && preserveExactInputHeight )
        bfx::Prober::SetHeight(this: this->m_commonState.m_pProber, actualPos: &v41, surferPos: &v42, localUpAxis: v46);
      else
        bfx::Prober::TeleportToArea(
          this: this->m_commonState.m_pProber,
          pNavLayer: v21,
          surferPos: &v42,
          localUpAxis: v46);
    }
    v47 = *desiredMat;
    v22 = ((long double (__fastcall *)(float *))this->m_behavior.m_pCurMotion->GetPos)(a1: v44);
    v23 = v44[0];
    this->m_commonState.m_orienter.m_slerping = false;
    v24 = v44[1];
    v25 = v44[2];
    this->m_commonState.m_orienter.m_slerpTimer = 0.0;
    v47.m_data[12] = v23;
    v47.m_data[13] = v24;
    v47.m_data[14] = v25;
    bfx::Orienter::TeleportToArea(this: &this->m_commonState.m_orienter, pArea: (bfx::Vec3 *)m_pArea, a3: v22);
    bfx::Orienter::SetOrientation(this: &this->m_commonState.m_orienter, desiredRot: &v47);
    m_state = this->m_behavior.m_state;
    p_m_behavior = &this->m_behavior;
    if ( m_state == JUMPING || m_state == PATH_WALKING )
    {
      m_command = this->m_lastMovementCommand.m_command;
      if ( m_command == STOP_COMMAND )
      {
        bfx::MoverImpl::MovingToIdle(this);
      }
      else
      {
        m_pCurMotion = this->m_behavior.m_pCurMotion;
        if ( m_command == FOLLOW_COMMAND )
        {
          if ( m_pCurMotion != nullptr )
            ((void (__fastcall *)(bfx::MotionBase *, int))m_pCurMotion->dtr_MotionBase)(a1: m_pCurMotion, a2: 1);
          this->m_behavior.m_pCurMotion = nullptr;
          this->m_behavior.m_pWalker = nullptr;
          this->m_behavior.m_pLocomoter = nullptr;
          this->m_behavior.m_pJumper = nullptr;
          this->m_behavior.m_pIdle = nullptr;
          this->m_behavior.m_pPuppet = nullptr;
          p_m_behavior->m_state = PATH_WALKING;
          v30 = bfx::CreateWalker(mat: &v47, commonState: &this->m_commonState);
          this->m_behavior.m_pCurMotion = v30;
          this->m_behavior.m_pWalker = v30;
          this->m_behavior.m_pWalker->Initialize(this: this->m_behavior.m_pWalker, a2: newVel, a3: &v47);
          LODWORD(v32) = this->m_lastMovementCommand.m_fmSpec.m_formation;
          *(float *)&v32 = this->m_lastMovementCommand.m_fmSpec.m_radius;
          m_arcSpread = this->m_lastMovementCommand.m_fmSpec.m_arcSpread;
          v34 = (bfx::MoverImpl **)this->m_commonState.m_followData.m_targetMover.m_pProxy;
          v45[1] = HIDWORD(v32);
          v45[0] = v32;
          *(float *)&v45[2] = m_arcSpread;
          if ( v34 != nullptr )
          {
            HIDWORD(v31) = (char *)*v34 - 1;
            LOBYTE(v31) = *v34 != nullptr;
          }
          else
          {
            LOBYTE(v31) = 0;
          }
          LODWORD(v31) = (unsigned __int8)v31;
          if ( (_BYTE)v31 != 0 && v34 != nullptr )
          {
            LODWORD(v35) = 1;
            HIDWORD(v35) = v45;
            bfx::MoverImpl::FollowMoverInternal(this, pTargetMover: *v34, forceUpdate: v35, a4: v32, a5: v31);
          }
          else
          {
            LODWORD(v36) = 1;
            HIDWORD(v36) = v45;
            bfx::MoverImpl::FollowMoverInternal(this, pTargetMover: nullptr, forceUpdate: v36, a4: v32, a5: v31);
          }
          goto LABEL_36;
        }
        if ( m_pCurMotion != nullptr )
          ((void (__fastcall *)(bfx::MotionBase *, int))m_pCurMotion->dtr_MotionBase)(a1: m_pCurMotion, a2: 1);
        this->m_behavior.m_pCurMotion = nullptr;
        this->m_behavior.m_pWalker = nullptr;
        this->m_behavior.m_pLocomoter = nullptr;
        this->m_behavior.m_pJumper = nullptr;
        this->m_behavior.m_pIdle = nullptr;
        this->m_behavior.m_pPuppet = nullptr;
        p_m_behavior->m_state = PATH_WALKING;
        v37 = bfx::CreateWalker(mat: &v47, commonState: &this->m_commonState);
        this->m_behavior.m_pWalker = v37;
        this->m_behavior.m_pCurMotion = v37;
        this->m_behavior.m_pWalker->Initialize(this: this->m_behavior.m_pWalker, a2: newVel, a3: &v47);
        bfx::MoverImpl::GotoPosInternal(
          this,
          requestedGoalPos: (bfx::IslandGraph *)&this->m_goalPos,
          origSpec: &this->m_gotoPosSpec,
          forceUpdate: true);
      }
      bfx::MoverImpl::ClearFollowMode(this);
    }
    else
    {
      this->m_behavior.m_pCurMotion->Teleport(this: this->m_behavior.m_pCurMotion, a2: &v47, a3: newVel, a4: m_pArea);
    }
LABEL_36:
    ((void (__fastcall *)(bfx::Vec3 *))this->m_behavior.m_pCurMotion->GetPos)(a1: &v43);
    v38 = v43.m_y;
    v39 = v43.m_z;
    this->m_prevPos.m_x = v43.m_x;
    v40[0].m_pProxy = (bfx::AreaProxy *)&this->m_prevPos;
    this->m_prevPos.m_y = v38;
    this->m_prevPos.m_z = v39;
    bfx::BlockedMonitor::Teleport(this: &this->m_commonState.m_blockedMonitor, pos: &v43);
    *((_BYTE *)this + 872) &= ~0x10u;
  }
}


// ========================================================================
// __unwind$35998
// EA  : 0x832BB70C
// RVA : 0x012BB70C
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void _unwind_35998()
{
  int v0; // r12

  bfx::Handle<bfx::Area>::~Handle<bfx::Area>(this: (bfx::AreaHandleImpl *)(v0 - 368 + 80));
}


// ========================================================================
// ?Teleport@MoverImpl@bfx@@QAAXABVVec3@2@ABVQuat@2@0PAVArea@2@@Z
// EA  : 0x832BB740
// RVA : 0x012BB740
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::Teleport(
        bfx::MoverImpl *this,
        const bfx::Vec3 *newPos,
        const bfx::Quat *newRot,
        const bfx::Vec3 *newVel,
        bfx::Area *pArea)
{
  double m_y; // fp13
  double v11; // fp13
  bfx::FTimerOb v12; // [sp+50h] [-90h] BYREF
  bfx::Vec3 *p_m_vel; // [sp+54h] [-8Ch]
  bfx::Matrix v14[2]; // [sp+60h] [-80h] BYREF

  bfx::FTimerOb::FTimerOb(this: &v12, timerEntry: &bfx::teleportTimer);
  this->m_vel.m_x = newVel->m_x;
  m_y = newVel->m_y;
  p_m_vel = &this->m_vel;
  this->m_vel.m_y = m_y;
  this->m_vel.m_z = newVel->m_z;
  if ( this->m_behavior.m_state == PUPPET )
  {
    this->m_behavior.m_pPuppet->SetPos(this: this->m_behavior.m_pPuppet, a2: newPos);
    this->m_behavior.m_pPuppet->SetRot(this: this->m_behavior.m_pPuppet, a2: newRot);
    this->m_prevPos.m_x = newPos->m_x;
    v11 = newPos->m_y;
    p_m_vel = &this->m_prevPos;
    this->m_prevPos.m_y = v11;
    this->m_prevPos.m_z = newPos->m_z;
  }
  else
  {
    bfx::Matrix::Build(this: v14, q: newRot, pos: newPos);
    bfx::MoverImpl::TeleportInternal(
      this,
      desiredMat: v14,
      pNewArea: pArea,
      newVel,
      allowTeleportInsideObstacles: false,
      preserveExactInputHeight: BYTE1(bfx::g_pCurInstance->m_pComponentManager->m_components[4][10].__vftable) == 0);
  }
  if ( v12.m_pFTimer != nullptr )
    bfx::FTimer::Stop(this: v12.m_pFTimer);
}


// ========================================================================
// __unwind$36246
// EA  : 0x832BB858
// RVA : 0x012BB858
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void _unwind_36246()
{
  int v0; // r12

  bfx::FTimerOb::~FTimerOb(this: (bfx::FTimerOb *)(v0 - 224 + 80));
}


// ========================================================================
// ?PuppetToIdle@MoverImpl@bfx@@AAAXXZ
// EA  : 0x832BB880
// RVA : 0x012BB880
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::PuppetToIdle(bfx::MoverImpl *this)
{
  const bfx::MoverTune *m_pTune; // r9
  bfx::Space *m_pSpace; // r7
  BOOL m_exitPuppetInObstacles; // r5
  bfx::Vec3 *ClosestArea; // r3
  bfx::Area *v6; // r31
  const bfx::MoverTune *v7; // r11
  bfx::AreaProxy *m_pProxy; // r11
  bfx::Area *m_pArea; // r27
  bfx::MotionBase *m_pCurMotion; // r3
  bfx::Idle *v11; // r3
  bfx::RepulsorImpl *m_pRepulsor; // r11
  bfx::AreaProxy *v13; // r11
  bfx::Vec3 v14; // [sp+50h] [-F0h] BYREF
  bfx::Vec3 v15; // [sp+60h] [-E0h] BYREF
  bfx::PathSpec v16; // [sp+70h] [-D0h] BYREF
  bfx::Matrix v17; // [sp+90h] [-B0h] BYREF
  bfx::Matrix v18; // [sp+D0h] [-70h] BYREF

  this->m_behavior.m_pCurMotion->GetMatrix(this: this->m_behavior.m_pCurMotion, a2: &v17);
  bfx::BuildMoverPathSpec(result: &v16, pTune: this->m_pTune);
  m_pTune = this->m_pTune;
  m_pSpace = this->m_pSpace;
  m_exitPuppetInObstacles = m_pTune->m_puppetTune.m_exitPuppetInObstacles;
  v14.m_x = v17.m_data[12];
  v14.m_y = v17.m_data[13];
  v14.m_z = v17.m_data[14];
  v16.m_obstacleBlockageFlags &= m_exitPuppetInObstacles - 1;
  ClosestArea = (bfx::Vec3 *)bfx::Planner::GetClosestArea(
                               this: *((bfx::Planner **)m_pSpace->m_components.m_data + 1),
                               pos: &v14,
                               layerNum: m_pTune->m_planLayer,
                               pathSpec: &v16);
  v6 = (bfx::Area *)ClosestArea;
  if ( ClosestArea != nullptr )
  {
    bfx::GetClosestPosInArea(result: &v15, pArea: ClosestArea, pos: &v14, pEdgeIndexOut: nullptr);
    v7 = this->m_pTune;
    v17.m_data[12] = v15.m_x;
    v17.m_data[13] = v15.m_y;
    v17.m_data[14] = v15.m_z;
    bfx::MoverImpl::TeleportInternal(
      this,
      desiredMat: &v17,
      pNewArea: v6,
      newVel: &this->m_vel,
      allowTeleportInsideObstacles: v7->m_puppetTune.m_exitPuppetInObstacles,
      preserveExactInputHeight: false);
    bfx::MoverImpl::ReattachSurfer(this);
  }
  this->m_behavior.m_pCurMotion->GetMatrix(this: this->m_behavior.m_pCurMotion, a2: &v18);
  m_pProxy = this->m_commonState.m_surfer.m_area.m_pProxy;
  if ( m_pProxy != nullptr )
    m_pArea = m_pProxy->m_pArea;
  else
    m_pArea = nullptr;
  m_pCurMotion = this->m_behavior.m_pCurMotion;
  if ( m_pCurMotion != nullptr )
    ((void (__fastcall *)(bfx::MotionBase *, int))m_pCurMotion->dtr_MotionBase)(a1: m_pCurMotion, a2: 1);
  this->m_behavior.m_pCurMotion = nullptr;
  this->m_behavior.m_pWalker = nullptr;
  this->m_behavior.m_pLocomoter = nullptr;
  this->m_behavior.m_pJumper = nullptr;
  this->m_behavior.m_pIdle = nullptr;
  this->m_behavior.m_pPuppet = nullptr;
  this->m_behavior.m_state = 0;
  v11 = bfx::CreateIdle(
          startMat: &v18,
          pStartArea: m_pArea,
          commonState: &this->m_commonState,
          preserveExactInputHeight: false);
  this->m_behavior.m_pIdle = v11;
  this->m_behavior.m_pCurMotion = v11;
  m_pRepulsor = this->m_commonState.m_pRepulsor;
  if ( m_pRepulsor != nullptr )
  {
    m_pRepulsor->m_bulk = this->m_pTune->m_bulk;
    v13 = this->m_commonState.m_surfer.m_area.m_pProxy;
    if ( v13 != nullptr )
      bfx::RepulsorImpl::SetArea(this: this->m_commonState.m_pRepulsor, pArea: v13->m_pArea);
    else
      bfx::RepulsorImpl::SetArea(this: this->m_commonState.m_pRepulsor, pArea: nullptr);
  }
}


// ========================================================================
// ?JumpingToWalking@MoverImpl@bfx@@AAAXXZ
// EA  : 0x832BBA48
// RVA : 0x012BBA48
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::JumpingToWalking(bfx::MoverImpl *this)
{
  bfx::HandleProxy *m_pProxy; // r9
  double m_followSpeedX; // fp12
  bfx::SmartPath *m_pSmartPath; // r3
  bfx::Area *SnappedStartArea; // r3
  char *v10; // r10
  bool *p_m_forceGotoPosUpdate; // r11
  int i; // ctr
  bfx::Vec3 v13; // [sp+50h] [-80h] BYREF
  char v14; // [sp+5Ch] [-74h] BYREF
  bfx::GPSpec v15; // [sp+60h] [-70h] BYREF
  bfx::Matrix v16; // [sp+80h] [-50h] BYREF

  this->m_behavior.m_pJumper->GetMatrix(this: this->m_behavior.m_pJumper, a2: &v16);
  m_pProxy = this->m_commonState.m_followData.m_targetMover.m_pProxy;
  if ( m_pProxy != nullptr && m_pProxy->m_pTarget != nullptr )
    m_followSpeedX = this->m_commonState.m_followData.m_followSpeedX;
  else
    m_followSpeedX = 1.0;
  _FP7 = -(float)((float)(v16.m_data[0] * this->m_vel.m_x)
                + (float)((float)(this->m_vel.m_y * v16.m_data[1]) + (float)(this->m_vel.m_z * v16.m_data[2])));
  m_pSmartPath = this->m_commonState.m_pSmartPath;
  __asm { fsel      f4, f7, f13, f0 }
  _FP0 = (float)((float)((float)((float)(this->m_commonState.m_pTune->m_speed
                                       * this->m_commonState.m_cautionData.m_internalSpeedX)
                               * this->m_commonState.m_speedX)
                       * (float)m_followSpeedX)
               - (float)((float)(v16.m_data[0] * this->m_vel.m_x)
                       + (float)((float)(this->m_vel.m_y * v16.m_data[1]) + (float)(this->m_vel.m_z * v16.m_data[2]))));
  __asm { fsel      f13, f0, f2, f1 }
  v13.m_x = (float)_FP13 * v16.m_data[0];
  v13.m_y = v16.m_data[1] * (float)_FP13;
  v13.m_z = v16.m_data[2] * (float)_FP13;
  SnappedStartArea = bfx::SmartPath::GetSnappedStartArea(this: m_pSmartPath);
  bfx::MoverImpl::TeleportInternal(
    this,
    desiredMat: &v16,
    pNewArea: SnappedStartArea,
    newVel: &v13,
    allowTeleportInsideObstacles: true,
    preserveExactInputHeight: false);
  if ( this->m_applyCommandOnJumpEnd && this->m_lastMovementCommand.m_command == GOTOPOS_COMMAND )
  {
    v10 = &v14;
    p_m_forceGotoPosUpdate = &this->m_lastMovementCommand.m_forceGotoPosUpdate;
    for ( i = 7; i != 0; --i )
    {
      p_m_forceGotoPosUpdate += 4;
      v10 += 4;
      *(_DWORD *)v10 = *(_DWORD *)p_m_forceGotoPosUpdate;
    }
    bfx::MoverImpl::GotoPosInternal(
      this,
      requestedGoalPos: (bfx::IslandGraph *)&this->m_lastMovementCommand.m_vec,
      origSpec: &v15,
      forceUpdate: true);
  }
}


// ========================================================================
// ?AfterJumping@MoverImpl@bfx@@AAAXXZ
// EA  : 0x832BBB98
// RVA : 0x012BBB98
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::AfterJumping(bfx::MoverImpl *this)
{
  bfx::Command m_command; // r11

  if ( !this->m_applyCommandOnJumpEnd || (m_command = this->m_lastMovementCommand.m_command) == GOTOPOS_COMMAND )
  {
    bfx::MoverImpl::JumpingToWalking(this);
  }
  else if ( m_command == STOP_COMMAND )
  {
    bfx::MoverImpl::JumpingToIdle(this);
  }
  else if ( m_command == LOCOMOTE_COMMAND )
  {
    bfx::MoverImpl::JumpingToLocomoting(this);
  }
  this->m_applyCommandOnJumpEnd = false;
}


// ========================================================================
// ?UpdateAutoOb@MoverImpl@bfx@@AAAXM@Z
// EA  : 0x832BBC18
// RVA : 0x012BBC18
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::UpdateAutoOb(bfx::MoverImpl *this, double simTime)
{
  const bfx::MoverTune *m_pTune; // r11
  char v5; // r28
  double v8; // fp13
  double v9; // fp12
  double v10; // fp30
  double v11; // fp13
  double m_moverLoggingTime; // fp12
  bfx::MotionBase *m_pCurMotion; // r4
  double v14; // fp13
  double v15; // fp12
  bfx::Idle *m_pIdle; // r3
  bool v17; // r3
  const bfx::MoverTune *v18; // r11
  double v19; // fp13
  double m_delay; // fp0
  bfx::Space *m_pSpace; // r3
  const bfx::MoverTune *v22; // r11
  int v23; // r9
  unsigned int m_planLayer; // r10
  double v25; // fp0
  int v26; // r10
  double m_radius; // fp13
  bfx::Handle<bfx::ObstacleImpl> *MoverSpaceComponent; // r28
  const bfx::MoverTune *v29; // r29
  bfx::MoverImpl *Rot; // r3
  const bfx::Handle<bfx::Space> *v31; // r3
  bfx::MoverSpaceComponent v32; // [sp+50h] [-D0h] BYREF
  float v33[4]; // [sp+88h] [-98h] BYREF
  bfx::Vec3 v34; // [sp+98h] [-88h] BYREF
  bfx::Vec3 v35[2]; // [sp+A8h] [-78h] BYREF
  int v36; // [sp+C0h] [-60h] BYREF

  m_pTune = this->m_pTune;
  if ( m_pTune->m_autoObTune.m_autoCreateObstacle )
  {
    v5 = 0;
    _FP13 = (float)(m_pTune->m_autoObTune.m_delay - (float)0.25);
    __asm { fsel      f29, f13, f0, f31 }
    if ( this->m_behavior.m_state == PUPPET )
    {
      if ( this->m_autoObData.m_inPuppetModeLastUpdate )
      {
        v10 = (float)((float)(bfx::GetScale() * (float)0.2) * (float)_FP29);
        ((void (__fastcall *)(float *))this->m_behavior.m_pCurMotion->GetPos)(a1: &v32.m_frameSimTime);
        if ( (float)((float)((float)(*(float *)&v32.m_pMoverSubsetData - this->m_autoObData.m_puppetStartPos.m_z)
                           * (float)(*(float *)&v32.m_pMoverSubsetData - this->m_autoObData.m_puppetStartPos.m_z))
                   + (float)((float)((float)(v32.m_frameSimTime - this->m_autoObData.m_puppetStartPos.m_x)
                                   * (float)(v32.m_frameSimTime - this->m_autoObData.m_puppetStartPos.m_x))
                           + (float)((float)(v32.m_simTimePending - this->m_autoObData.m_puppetStartPos.m_y)
                                   * (float)(v32.m_simTimePending - this->m_autoObData.m_puppetStartPos.m_y)))) >= (double)(float)((float)v10 * (float)v10) )
        {
          ((void (__fastcall *)(bfx::AutoPtr<bfx::Pool> *))this->m_behavior.m_pCurMotion->GetPos)(a1: &v32.m_obstacleRequests.m_poolAutoPtr);
          v11 = *(float *)&v32.m_obstacleRequests.m_pEnd;
          m_moverLoggingTime = v32.m_moverLoggingTime;
          this->m_autoObData.m_puppetStartPos.m_x = *(float *)&v32.m_obstacleRequests.m_poolAutoPtr.m_data;
          this->m_autoObData.m_puppetStartPos.m_y = v11;
          this->m_autoObData.m_puppetStartPos.m_z = m_moverLoggingTime;
        }
        else
        {
          v5 = 1;
        }
      }
      else
      {
        ((void (__fastcall *)(bfx::Array<bfx::MoverImpl *> *))this->m_behavior.m_pCurMotion->GetPos)(a1: &v32.m_movers);
        v8 = *(float *)&v32.m_movers.m_size;
        v9 = *(float *)&v32.m_movers.m_cap;
        this->m_autoObData.m_puppetStartPos.m_x = *(float *)&v32.m_movers.m_data;
        this->m_autoObData.m_puppetStartPos.m_y = v8;
        this->m_autoObData.m_puppetStartPos.m_z = v9;
        this->m_autoObData.m_inPuppetModeLastUpdate = true;
      }
    }
    else
    {
      m_pCurMotion = this->m_behavior.m_pCurMotion;
      this->m_autoObData.m_inPuppetModeLastUpdate = false;
      ((void (__fastcall *)(float *))m_pCurMotion->GetPos)(a1: v33);
      v14 = v33[1];
      v15 = v33[2];
      this->m_autoObData.m_puppetStartPos.m_x = v33[0];
      this->m_autoObData.m_puppetStartPos.m_y = v14;
      this->m_autoObData.m_puppetStartPos.m_z = v15;
    }
    if ( (*((_BYTE *)this + 872) & 0x40) != 0
      || (*((_BYTE *)this + 872) & 0x20) != 0
      || (this->m_stranded || (m_pIdle = this->m_behavior.m_pIdle) == nullptr
        ? (v17 = false)
        : (v17 = m_pIdle->IsIdle(this: m_pIdle, a2: nullptr)),
          v17
       && ((v18 = this->m_pTune)->m_idleTune.m_tetherDist < (double)(float)(v18->m_radiusData.m_radius * (float)0.25)
        || v18->m_speed == 0.0)
       || v5 != 0) )
    {
      v19 = (float)(this->m_autoObData.m_timer + (float)simTime);
      this->m_autoObData.m_timer = this->m_autoObData.m_timer + (float)simTime;
      if ( v5 != 0 )
        m_delay = _FP29;
      else
        m_delay = this->m_pTune->m_autoObTune.m_delay;
      if ( v19 >= m_delay && this->m_autoObData.m_pSpace == nullptr )
      {
        m_pSpace = this->m_pSpace;
        v22 = this->m_pTune;
        v23 = *((_DWORD *)m_pSpace->m_components.m_data + 1);
        this->m_autoObData.m_pSpace = m_pSpace;
        m_planLayer = v22->m_planLayer;
        v25 = (float)(v22->m_radiusData.m_radius * (float)3.0);
        if ( m_planLayer < 0x20 )
        {
          v26 = *(_DWORD *)(4 * (m_planLayer + 2) + v23);
          if ( v26 != 0 )
            v25 = *(float *)(v26 + 16);
        }
        m_radius = v22->m_radiusData.m_radius;
        v34.m_x = v22->m_radiusData.m_radius * (float)2.0;
        v34.m_z = v25;
        v34.m_y = (float)m_radius * (float)2.0;
        *(float *)&v32.m_pSpace = v34.m_y;
        MoverSpaceComponent = (bfx::Handle<bfx::ObstacleImpl> *)bfx::GetMoverSpaceComponent(pSpace: m_pSpace);
        ((void (__fastcall *)(bfx::Vec3 *))this->m_behavior.m_pCurMotion->GetPos)(a1: v35);
        v29 = this->m_pTune;
        Rot = bfx::MoverImpl::GetRot(this: (bfx::MoverImpl *)&v36, result: (bfx::Quat *)this);
        v31 = (const bfx::Handle<bfx::Space> *)bfx::MoverSpaceComponent::RequestCreateObstacle(
                                                 this: &v32,
                                                 result: MoverSpaceComponent,
                                                 pos: v35,
                                                 rot: (const bfx::Quat *)Rot,
                                                 boxDimensions: &v34,
                                                 obstacleDat: &v29->m_autoObTune.m_obstacleDat);
        bfx::Handle<bfx::LinkReservation>::operator=(
          this: (bfx::Handle<bfx::Space> *)&this->m_autoObData.m_obstacle,
          rhs: v31);
        if ( v32.__vftable != nullptr )
          bfx::HandleProxy::RemRefToHandleProxy(this: (bfx::HandleProxy *)v32.__vftable);
      }
    }
    else
    {
      if ( this->m_autoObData.m_obstacle.m_pProxy != nullptr )
        bfx::AutoObData::ClearObstacle(this: &this->m_autoObData);
      this->m_autoObData.m_timer = 0.0;
    }
  }
}


// ========================================================================
// __unwind$36557
// EA  : 0x832BBF60
// RVA : 0x012BBF60
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void _unwind_36557()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: (bfx::Handle<bfx::Space> *)(v0 - 288 + 80));
}


// ========================================================================
// ?UpdateState@MoverImpl@bfx@@UAAXM@Z
// EA  : 0x832BBF88
// RVA : 0x012BBF88
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::UpdateState(bfx::MoverImpl *this, double simTimeIn)
{
  double v3; // fp31
  bfx::MoverImpl *v4; // r3
  double v5; // fp1
  bfx::Area *m_pArea; // r30
  bfx::MoverImpl::State m_state; // r11
  char m_forceUseClientMotion; // r8
  long double v9; // fp2
  long double v10; // fp4
  __int64 v11; // r10
  __int64 v12; // r8
  bfx::HandleProxy *m_pProxy; // r11
  bfx::HandleTargetBase *m_pTarget; // r11
  bool v15; // r11
  bfx::MoverImpl *v16; // r4
  __int64 v17; // r6
  bfx::FollowerLeaderDatabase *m_pLeaderDatabase; // r3
  __int64 v19; // r10
  __int64 v20; // r8
  bfx::MoverImpl::State v21; // r11
  bfx::HandleProxy *v22; // r11
  bfx::HandleTargetBase *v23; // r11
  bool v24; // r11
  bfx::MoverImpl *v25; // r4
  __int64 v26; // r6
  bfx::HalfLink *NextLink; // r29
  int ShouldJumpNow; // r3
  int v29; // r29
  bfx::HandleProxy *v30; // r11
  bfx::HandleTargetBase *v31; // r11
  bfx::AreaProxy *v32; // r11
  bfx::RepulsorImpl *m_pRepulsor; // r3
  bfx::RepulsorImpl *v34; // r11
  bfx::MoverImpl *Rot; // r3
  const bfx::Vec3 *v36; // r3
  bfx::RepulsorImpl *v37; // r11
  bfx::StpSpec v38[4]; // [sp+50h] [-70h] BYREF
  bfx::Vec3 v39[2]; // [sp+58h] [-68h] BYREF
  bfx::Vec3 v40; // [sp+70h] [-50h] BYREF
  bfx::Vec3 v41[2]; // [sp+80h] [-40h] BYREF

  v3 = (float)(this->m_commonState.m_slowTime * (float)simTimeIn);
  bfx::MoverImpl::AnimateMoverDebugDraw(this, simTime: v3);
  bfx::MoverImpl::UpdateAutoOb(this: v4, simTime: v5);
  m_pArea = nullptr;
  if ( this->m_asyncGotoPosData.m_isValid )
  {
    bfx::MoverImpl::GotoPos(
      this,
      inputGoalPos: &this->m_asyncGotoPosData.m_goalPos,
      origSpec: &this->m_asyncGotoPosData.m_spec,
      forceUpdate: this->m_asyncGotoPosData.m_forceUpdate);
    this->m_asyncGotoPosData.m_isValid = false;
  }
  if ( (*((_BYTE *)this + 872) & 0x40) == 0 && this->m_behavior.m_state != PUPPET )
  {
    if ( (unsigned __int8)bfx::MoverImpl::ReattachSurfer(this) == 0 )
      return;
    m_state = this->m_behavior.m_state;
    if ( (*((_BYTE *)this + 872) & 0x20) != 0 )
    {
      if ( m_state != JUMPING )
      {
        ((void (__fastcall *)(bfx::Vec3 *))this->m_behavior.m_pCurMotion->GetPos)(a1: v39);
        m_forceUseClientMotion = this->m_commonState.m_forceUseClientMotion;
        *(double *)&v9 = v3;
        v40 = v39[0];
        bfx::Orienter::Simulate(
          this: &this->m_commonState.m_orienter,
          pos: v39,
          vel: &this->m_vel,
          simTime: v9,
          nextCornerG: (const bfx::Vec3 *)LODWORD(v39[0].m_y),
          bForceUseClientMotion: &v40,
          a7: m_forceUseClientMotion,
          a8: v10);
      }
      return;
    }
    if ( m_state == PATH_WALKING && (unsigned __int8)bfx::MoverImpl::CurPathSectionValid(this) == 0 )
    {
      if ( bfx::MotionState::IsFollowerMode(this: &this->m_commonState) )
      {
        LODWORD(v11) = &this->m_commonState.m_followData.m_targetMover;
        m_pProxy = this->m_commonState.m_followData.m_targetMover.m_pProxy;
        if ( m_pProxy != nullptr )
        {
          m_pTarget = m_pProxy->m_pTarget;
          HIDWORD(v11) = (char *)m_pTarget - 1;
          v15 = m_pTarget != nullptr;
        }
        else
        {
          v15 = false;
        }
        if ( v15 && *(_DWORD *)v11 != 0 )
          v16 = **(bfx::MoverImpl ***)v11;
        else
          v16 = nullptr;
        LODWORD(v17) = 0;
        HIDWORD(v17) = &v16->m_pLeaderDatabase->m_spec;
        bfx::MoverImpl::FollowMoverInternal(this, pTargetMover: v16, forceUpdate: v17, a4: v12, a5: v11);
      }
      else
      {
        bfx::MoverImpl::GotoPosInternal(
          this,
          requestedGoalPos: (bfx::IslandGraph *)&this->m_lastRequestedGoalPos,
          origSpec: &this->m_gotoPosSpec,
          forceUpdate: true);
      }
    }
    m_pLeaderDatabase = this->m_pLeaderDatabase;
    if ( m_pLeaderDatabase != nullptr )
      idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)m_pLeaderDatabase);
    this->m_behavior.m_pCurMotion->Simulate(this: this->m_behavior.m_pCurMotion, a2: v3);
    HIDWORD(v19) = bfx::MotionState::IsFollowerMode(this: &this->m_commonState);
    v21 = this->m_behavior.m_state;
    if ( HIDWORD(v19) != 0 )
    {
      if ( v21 != JUMPING )
      {
        LODWORD(v19) = &this->m_commonState.m_followData.m_targetMover;
        v22 = this->m_commonState.m_followData.m_targetMover.m_pProxy;
        if ( v22 != nullptr )
        {
          v23 = v22->m_pTarget;
          HIDWORD(v19) = (char *)v23 - 1;
          v24 = v23 != nullptr;
        }
        else
        {
          v24 = false;
        }
        if ( v24 && *(_DWORD *)v19 != 0 )
          v25 = **(bfx::MoverImpl ***)v19;
        else
          v25 = nullptr;
        LODWORD(v26) = 0;
        HIDWORD(v26) = &v25->m_pLeaderDatabase->m_spec;
        bfx::MoverImpl::FollowMoverInternal(this, pTargetMover: v25, forceUpdate: v26, a4: v20, a5: v19);
        goto LABEL_54;
      }
LABEL_52:
      if ( this->m_behavior.m_pJumper->ReachedGoal(this: this->m_behavior.m_pJumper) )
        bfx::MoverImpl::AfterJumping(this);
      goto LABEL_54;
    }
    if ( v21 != PATH_WALKING )
    {
      if ( v21 == JUMPING )
        goto LABEL_52;
LABEL_54:
      bfx::MotionState::FollowData::Update(this: &this->m_commonState.m_followData, simTime: v3);
      bfx::MoverImpl::UpdateBlockageCheck(this, simTime: v3);
      ((void (__fastcall *)(bfx::Vec3 *))this->m_behavior.m_pCurMotion->GetPos)(a1: v41);
      v32 = this->m_commonState.m_surfer.m_area.m_pProxy;
      if ( v32 != nullptr )
        m_pArea = v32->m_pArea;
      m_pRepulsor = this->m_commonState.m_pRepulsor;
      if ( m_pRepulsor != nullptr )
      {
        bfx::RepulsorImpl::SetPos(this: m_pRepulsor, pos: v41);
        v34 = this->m_commonState.m_pRepulsor;
        v34->m_vel.m_x = this->m_vel.m_x;
        v34->m_vel.m_y = this->m_vel.m_y;
        v34->m_vel.m_z = this->m_vel.m_z;
        bfx::RepulsorImpl::SetArea(this: this->m_commonState.m_pRepulsor, pArea: m_pArea);
      }
      this->m_behavior.m_pCurMotion->UpdateSmartPath(this: this->m_behavior.m_pCurMotion, a2: v41, a3: m_pArea);
      Rot = bfx::MoverImpl::GetRot(this: (bfx::MoverImpl *)&v40, result: (bfx::Quat *)this);
      *(bfx::HandleTargetBase *)&this->m_cachedRot.m_w = Rot->bfx::HandleTargetBase;
      *(bfx::RepulsorOwner *)&this->m_cachedRot.m_y = Rot->bfx::RepulsorOwner;
      bfx::MoverImpl::UpdateMoverDebugDraw(this);
      return;
    }
    NextLink = bfx::SmartPath::GetNextLink(this: this->m_commonState.m_pSmartPath);
    if ( this->m_lastMovementCommand.m_command == STOP_COMMAND
      && this->m_behavior.m_pWalker->DoneMoving(this: this->m_behavior.m_pWalker) )
    {
LABEL_36:
      bfx::MoverImpl::MovingToIdle(this);
      goto LABEL_54;
    }
    if ( NextLink == nullptr )
    {
      if ( !this->m_behavior.m_pWalker->DoneMoving(this: this->m_behavior.m_pWalker) )
        goto LABEL_54;
      goto LABEL_36;
    }
    ShouldJumpNow = bfx::MoverImpl::ShouldJumpNow(this);
    v29 = ShouldJumpNow;
    if ( (*((_BYTE *)this + 872) & 0x10) != 0 )
    {
      if ( this->m_behavior.m_pWalker->ReachedGoal(this: this->m_behavior.m_pWalker) )
      {
        *((_BYTE *)this + 872) &= ~0x10u;
        goto LABEL_47;
      }
    }
    else
    {
      if ( ShouldJumpNow == 4 )
      {
        *((_BYTE *)this + 872) |= 0x10u;
        bfx::StpSpec::StpSpec(this: v38);
        v38[0].m_stopImmediately = false;
        v38[0].m_cancelPendingTurn = false;
        this->m_behavior.m_pWalker->Stop(this: this->m_behavior.m_pWalker, a2: v38);
        goto LABEL_54;
      }
      if ( ShouldJumpNow == 3 )
      {
LABEL_47:
        v30 = this->m_curGoalLink.m_pProxy;
        if ( v30 != nullptr )
          v31 = v30->m_pTarget;
        else
          v31 = nullptr;
        bfx::MoverImpl::WalkingToJumping(
          this,
          startJumpFrozen: (_cntlzw(*((_DWORD *)&v31[6].m_pProxy[4] + 1) - 1) & 0x20) != 0);
        goto LABEL_54;
      }
    }
    if ( v29 != 2 )
      goto LABEL_54;
    goto LABEL_47;
  }
  if ( this->m_commonState.m_pRepulsor != nullptr )
  {
    v36 = (const bfx::Vec3 *)((int (__fastcall *)(bfx::Vec3 *))this->m_behavior.m_pCurMotion->GetPos)(a1: &v40);
    bfx::RepulsorImpl::SetPos(this: this->m_commonState.m_pRepulsor, pos: v36);
    v37 = this->m_commonState.m_pRepulsor;
    v37->m_vel.m_x = this->m_vel.m_x;
    v37->m_vel.m_y = this->m_vel.m_y;
    v37->m_vel.m_z = this->m_vel.m_z;
  }
}


// ========================================================================
// ??0MoverImpl@bfx@@QAA@PAVSpace@1@ABVVec3@1@ABVQuat@1@PBUMoverTune@1@II@Z
// EA  : 0x832BC498
// RVA : 0x012BC498
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

bfx::MoverImpl *__fastcall bfx::MoverImpl::MoverImpl(
        bfx::MoverImpl *this,
        bfx::Space *pSpace,
        const bfx::Vec3 *initialClientProvidedPos,
        const bfx::Quat *rot,
        const bfx::MoverTune *pInputTune,
        unsigned int flockID,
        unsigned int replayID)
{
  bfx::MoverTune *p_m_tune; // r26
  bfx::bfxMemTag v15; // r11
  bfx::Space *m_pSpace; // r5
  bfx::Planner *v17; // r21
  const bfx::PathSpec *v18; // r3
  __int64 v19; // r10
  __int64 v20; // r8
  __int64 v21; // r6
  bfx::Vec3 *ClosestArea; // r3
  bfx::Area *v23; // r21
  bfx::Vec3 *ClosestPosInArea; // r3
  double m_z; // fp12
  __int64 v26; // r4
  double m_x; // fp0
  double m_y; // fp13
  unsigned int m_replayID; // r11
  __int64 v30; // r8
  int v31; // r6
  int v32; // r5
  int v33; // r4
  bfx::PathSpec *v34; // r3
  bfx::SmartPath *m_pSmartPath; // r3
  char v36; // r11
  bfx::Idle *Idle; // r3
  double v38; // fp0
  double v39; // fp13
  double v40; // fp12
  double v41; // fp13
  double v42; // fp12
  bfx::MoverSpaceComponent *MoverSpaceComponent; // r3
  int v44; // r10
  int v45; // r9
  int v46; // r8
  int v47; // r7
  int v48; // r6
  int v49; // r5
  int v51; // [sp+8h] [-188h]
  int v52; // [sp+Ch] [-184h]
  int v53; // [sp+10h] [-180h]
  int v54; // [sp+14h] [-17Ch]
  int v55; // [sp+18h] [-178h]
  bfx::Space *v56; // [sp+1Ch] [-174h]
  bfx::RepulsorOwner *v57; // [sp+54h] [-13Ch] BYREF
  bfx::Vec3 v58; // [sp+58h] [-138h] BYREF
  float v59[4]; // [sp+68h] [-128h] BYREF
  bfx::Vec3 v60[2]; // [sp+78h] [-118h] BYREF
  bfx::PathSpec v61; // [sp+90h] [-100h] BYREF
  bfx::PathSpec v62; // [sp+B0h] [-E0h] BYREF
  bfx::Matrix v63[3]; // [sp+D0h] [-C0h] BYREF

  this->m_pProxy = nullptr;
  this->m_creatorType = REPULSOR_CREATOR_MOVER;
  v57 = &this->bfx::RepulsorOwner;
  this->bfx::RepulsorOwner::__vftable = (bfx::RepulsorOwner_vtbl *)&bfx::RepulsorOwner::`vftable';
  this->m_pSpace = pSpace;
  this->m_stranded = false;
  this->bfx::HandleTargetBase::__vftable = (bfx::MoverImpl_vtbl *)&bfx::MoverImpl::`vftable'{for `bfx::HandleTargetBase'};
  p_m_tune = &this->m_tune;
  this->bfx::RepulsorOwner::__vftable = (bfx::RepulsorOwner_vtbl *)&bfx::MoverImpl::`vftable'{for `bfx::RepulsorOwner'};
  memcpy(Dst: &this->m_tune, Src: pInputTune, Size: sizeof(this->m_tune));
  bfx::MotionState::MotionState(this: &this->m_commonState, pSpace, pTune: p_m_tune, replayID);
  this->m_behavior.m_state = 0;
  this->m_behavior.m_pWalker = nullptr;
  this->m_behavior.m_pLocomoter = nullptr;
  this->m_behavior.m_pJumper = nullptr;
  this->m_behavior.m_pIdle = nullptr;
  this->m_behavior.m_pPuppet = nullptr;
  this->m_behavior.m_pCurMotion = nullptr;
  this->m_debugName.m_data = nullptr;
  this->m_curGoalLink.m_pProxy = nullptr;
  this->m_pathSharingHelper.m_linkBase.m_pProxy = nullptr;
  bfx::GPSpec::GPSpec(this: &this->m_gotoPosSpec);
  this->m_asyncGotoPosData.m_isValid = false;
  this->m_asyncGotoPosData.m_goalPos = bfx::ZERO_VEC;
  bfx::GPSpec::GPSpec(this: &this->m_asyncGotoPosData.m_spec);
  this->m_asyncGotoPosData.m_forceUpdate = false;
  bfx::CommandData::CommandData(this: &this->m_lastMovementCommand);
  this->m_jumpClientData.m_link.m_pProxy = nullptr;
  this->m_jumpClientData.m_startArea.m_pProxy = nullptr;
  this->m_jumpClientData.m_endArea.m_pProxy = nullptr;
  v15 = bfx::MEM_BFXMOVER;
  this->m_goalsReached.m_data = nullptr;
  this->m_goalsReached.m_size = 0;
  this->m_goalsReached.m_cap = 0;
  this->m_goalsReached.m_tag = v15;
  this->m_clientMotionDebugData.m_desiredVel = bfx::ZERO_VEC;
  this->m_clientMotionDebugData.m_clientVel = bfx::ZERO_VEC;
  this->m_autoObData.m_timer = 0.0;
  this->m_autoObData.m_obstacle.m_pProxy = nullptr;
  this->m_autoObData.m_puppetStartPos.m_x = 0.0;
  this->m_autoObData.m_puppetStartPos.m_y = 0.0;
  this->m_autoObData.m_puppetStartPos.m_z = 0.0;
  this->m_autoObData.m_inPuppetModeLastUpdate = false;
  this->m_autoObData.m_pSpace = nullptr;
  m_pSpace = this->m_pSpace;
  this->m_pLeaderDatabase = nullptr;
  v17 = *((bfx::Planner **)m_pSpace->m_components.m_data + 1);
  v18 = bfx::BuildMoverPathSpec(result: &v61, pTune: pInputTune);
  ClosestArea = (bfx::Vec3 *)bfx::Planner::GetClosestArea(
                               this: v17,
                               pos: initialClientProvidedPos,
                               layerNum: pInputTune->m_planLayer,
                               pathSpec: v18);
  v23 = (bfx::Area *)ClosestArea;
  if ( ClosestArea != nullptr )
  {
    ClosestPosInArea = bfx::GetClosestPosInArea(
                         result: v60,
                         pArea: ClosestArea,
                         pos: initialClientProvidedPos,
                         pEdgeIndexOut: nullptr);
    v58.m_x = ClosestPosInArea->m_x;
    v58.m_y = ClosestPosInArea->m_y;
    m_z = ClosestPosInArea->m_z;
  }
  else
  {
    LODWORD(v26) = pInputTune->m_planLayer;
    HIDWORD(v26) = "Mover created on layer %d before any NavGraphs were loaded for that layer\n";
    bfx::InternalWarning(fmt: v26, a2: v21, a3: v20, a4: v19, a5: v51, a6: v52, a7: v53, a8: v54);
    m_x = initialClientProvidedPos->m_x;
    m_y = initialClientProvidedPos->m_y;
    m_z = initialClientProvidedPos->m_z;
    this->m_stranded = true;
    v58.m_x = m_x;
    v58.m_y = m_y;
  }
  v58.m_z = m_z;
  this->m_commonState.m_surfer.m_pMoverImpl = this;
  bfx::Surfer::SetPosAndArea(this: &this->m_commonState.m_surfer, pos: &v58, pArea: v23);
  bfx::SmartPath::SetStartData(this: this->m_commonState.m_pSmartPath, startPos: &v58, pStartArea: v23);
  m_replayID = this->m_commonState.m_replayID;
  this->m_commonState.m_flockID = flockID;
  this->m_commonState.m_randPrev = m_replayID;
  bfx::ApplyLimits_MoverTune(tune: p_m_tune, a2: v33, a3: v32, a4: v31, a5: v30);
  this->m_pTune = p_m_tune;
  this->m_pPath = nullptr;
  v34 = bfx::BuildMoverPathSpec(result: &v62, pTune: p_m_tune);
  bfx::SmartPath::SetPathSpec(this: this->m_commonState.m_pSmartPath, pathSpec: v34);
  HIWORD(v57) = 256;
  m_pSmartPath = this->m_commonState.m_pSmartPath;
  HIBYTE(v57) = this->m_pTune->m_pathOptions.m_performInitialNavProbe;
  bfx::SmartPath::SetPathCreationOptions(this: m_pSmartPath, options: (const bfx::PathCreationOptions *)&v57);
  bfx::SmartPath::SetNavLayer(this: this->m_commonState.m_pSmartPath, layer: this->m_pTune->m_planLayer);
  this->m_goalPos = bfx::ZERO_VEC;
  this->m_lastRequestedGoalPos = bfx::ZERO_VEC;
  this->m_lastGoalPosActedOn = bfx::ZERO_VEC;
  this->m_lastGoalDirActedOn = bfx::ZERO_VEC;
  this->m_applyCommandOnPuppetDisable = false;
  v36 = *((_BYTE *)this + 872);
  this->m_applyCommandOnJumpEnd = false;
  this->m_prePuppetModeState = 0;
  *((_BYTE *)this + 872) = v36 & 0xF;
  this->m_prevPos = bfx::ZERO_VEC;
  this->m_vel = bfx::ZERO_VEC;
  this->m_overrideColor = ColorBlack_20;
  this->m_cachedRot.m_w = rot->m_w;
  this->m_cachedRot.m_x = rot->m_x;
  this->m_cachedRot.m_y = rot->m_y;
  this->m_cachedRot.m_z = rot->m_z;
  this->m_pTrail = nullptr;
  this->m_prevReachedGoal = false;
  if ( (unsigned __int8)bfx::IsColliderSet() != 0
    || !bfx::AreBatchProbeRequestsEnabled()
    || BYTE1(bfx::g_pCurInstance->m_pComponentManager->m_components[4][10].__vftable) != 0 )
  {
    bfx::Matrix::Build(this: v63, q: rot, pos: &v58);
    Idle = bfx::CreateIdle(
             startMat: v63,
             pStartArea: v23,
             commonState: &this->m_commonState,
             preserveExactInputHeight: false);
    this->m_behavior.m_state = 0;
    this->m_behavior.m_pIdle = Idle;
    this->m_behavior.m_pCurMotion = Idle;
  }
  else
  {
    bfx::MoverImpl::MoverBehavior::Initialize(
      this: &this->m_behavior,
      pos: initialClientProvidedPos,
      rot,
      pStartArea: v23,
      commonState: &this->m_commonState,
      preserveExactInputHeight: true);
  }
  v38 = v58.m_x;
  v39 = v58.m_y;
  v40 = v58.m_z;
  this->m_goalPos.m_x = v58.m_x;
  this->m_goalPos.m_y = v39;
  this->m_goalPos.m_z = v40;
  this->m_lastRequestedGoalPos.m_x = v38;
  this->m_lastRequestedGoalPos.m_y = v39;
  this->m_lastRequestedGoalPos.m_z = v40;
  this->m_lastGoalPosActedOn.m_z = v40;
  this->m_lastGoalPosActedOn.m_x = v38;
  this->m_lastGoalPosActedOn.m_y = v39;
  ((void (__fastcall *)(float *))this->m_behavior.m_pCurMotion->GetPos)(a1: v59);
  v41 = v59[1];
  v42 = v59[2];
  this->m_prevPos.m_x = v59[0];
  this->m_prevPos.m_y = v41;
  this->m_prevPos.m_z = v42;
  bfx::MoverImpl::EnableRepulsor(this, enable: true);
  MoverSpaceComponent = bfx::GetMoverSpaceComponent(pSpace);
  bfx::MoverSpaceComponent::AddMover(
    this: MoverSpaceComponent,
    pMover: (bfx::Space *)this,
    a3: v49,
    a4: v48,
    a5: v47,
    a6: v46,
    a7: v45,
    a8: v44,
    a9: v51,
    a10: v52,
    a11: v53,
    a12: v54,
    a13: v55,
    a14: v56);
  return this;
}


// ========================================================================
// __unwind$36936
// EA  : 0x832BC9F4
// RVA : 0x012BC9F4
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void _unwind_36936()
{
  int v0; // r12

  bfx::HandleTargetBase::~HandleTargetBase(this: *(bfx::HandleTargetBase **)(v0 - 400 + 420));
}


// ========================================================================
// __unwind$36937
// EA  : 0x832BCA1C
// RVA : 0x012BCA1C
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void _unwind_36937()
{
  int v0; // r12

  bfx::RepulsorOwner::~RepulsorOwner(this: (bfx::RepulsorOwner *)(*(_DWORD *)(v0 - 400 + 420) + 8));
}


// ========================================================================
// __unwind$36938
// EA  : 0x832BCA48
// RVA : 0x012BCA48
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void _unwind_36938()
{
  int v0; // r12

  bfx::MotionState::~MotionState(this: (bfx::MotionState *)(*(_DWORD *)(v0 - 400 + 420) + 304));
}


// ========================================================================
// __unwind$36939
// EA  : 0x832BCA74
// RVA : 0x012BCA74
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void _unwind_36939()
{
  int v0; // r12

  bfx::MoverImpl::MoverBehavior::~MoverBehavior(this: (bfx::MoverImpl::MoverBehavior *)(*(_DWORD *)(v0 - 400 + 420) + 752));
}


// ========================================================================
// __unwind$36940
// EA  : 0x832BCAA0
// RVA : 0x012BCAA0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void _unwind_36940()
{
  int v0; // r12

  bfx::String::~String(this: (bfx::String *)(*(_DWORD *)(v0 - 400 + 420) + 780));
}


// ========================================================================
// __unwind$36941
// EA  : 0x832BCACC
// RVA : 0x012BCACC
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void _unwind_36941()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: (bfx::Handle<bfx::Space> *)(*(_DWORD *)(v0 - 400 + 420) + 788));
}


// ========================================================================
// __unwind$36942
// EA  : 0x832BCAF8
// RVA : 0x012BCAF8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void _unwind_36942()
{
  int v0; // r12

  bfx::PathSharingHelper::~PathSharingHelper(this: (bfx::PathSharingHelper *)(*(_DWORD *)(v0 - 400 + 420) + 792));
}


// ========================================================================
// __unwind$36943
// EA  : 0x832BCB24
// RVA : 0x012BCB24
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void _unwind_36943()
{
  int v0; // r12

  bfx::JumpClientData::~JumpClientData(this: (bfx::JumpClientData *)(*(_DWORD *)(v0 - 400 + 420) + 1004));
}


// ========================================================================
// __unwind$36944
// EA  : 0x832BCB50
// RVA : 0x012BCB50
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void _unwind_36944()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 400 + 420)
                                                                                             + 1104));
}


// ========================================================================
// __unwind$36945
// EA  : 0x832BCB7C
// RVA : 0x012BCB7C
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void _unwind_36945()
{
  int v0; // r12

  bfx::AutoObData::~AutoObData(this: (bfx::AutoObData *)(*(_DWORD *)(v0 - 400 + 420) + 1144));
}


// ========================================================================
// ?SetTune@MoverImpl@bfx@@QAAXPBUMoverTune@2@@Z
// EA  : 0x832BCBC0
// RVA : 0x012BCBC0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall bfx::MoverImpl::SetTune(bfx::MoverImpl *this, const bfx::MoverTune *pTune)
{
  const bfx::MoverTune *m_pTune; // r11
  bfx::MoverTune *p_m_tune; // r29
  unsigned int m_planLayer; // r28
  bool m_autoCreateObstacle; // r27
  __int64 v8; // r8
  int v9; // r6
  int v10; // r5
  int v11; // r4
  bfx::RepulsorImpl *m_pRepulsor; // r11
  const bfx::MoverTune *v13; // r10
  bfx::Area *ClosestArea; // r29
  __int64 v15; // r10
  __int64 v16; // r8
  __int64 v17; // r6
  __int64 v18; // r4
  const bfx::MoverTune *v19; // r29
  unsigned __int64 v20; // r6 OVERLAPPED
  bfx::Prober *v21; // r3
  bfx::Prober *v22; // r3
  char *m_pProber; // r29
  bfx::Prober *v24; // r11
  bfx::PathSpec *v25; // r3
  int v26; // [sp+8h] [-108h]
  int v27; // [sp+Ch] [-104h]
  int v28; // [sp+10h] [-100h]
  int v29; // [sp+14h] [-FCh]
  bfx::Vec3 v30[2]; // [sp+58h] [-B8h] BYREF
  bfx::PathSpec v31; // [sp+70h] [-A0h] BYREF
  bfx::Matrix v32[2]; // [sp+90h] [-80h] BYREF

  m_pTune = this->m_pTune;
  p_m_tune = &this->m_tune;
  m_planLayer = m_pTune->m_planLayer;
  m_autoCreateObstacle = m_pTune->m_autoObTune.m_autoCreateObstacle;
  memcpy(Dst: &this->m_tune, Src: pTune, Size: sizeof(this->m_tune));
  bfx::ApplyLimits_MoverTune(tune: p_m_tune, a2: v11, a3: v10, a4: v9, a5: v8);
  m_pRepulsor = this->m_commonState.m_pRepulsor;
  if ( m_pRepulsor != nullptr )
  {
    v13 = this->m_pTune;
    m_pRepulsor->m_radiusData.m_radius = v13->m_radiusData.m_radius;
    m_pRepulsor->m_radiusData.m_outerCushion = v13->m_radiusData.m_outerCushion;
    m_pRepulsor->m_radiusData.m_innerCushion = v13->m_radiusData.m_innerCushion;
    this->m_commonState.m_pRepulsor->m_bulk = this->m_pTune->m_bulk;
    this->m_commonState.m_pRepulsor->m_repulsorType = this->m_pTune->m_repulsorType;
    this->m_commonState.m_pRepulsor->m_blockageFlags = this->m_pTune->m_repulsorBlockageFlags;
    this->m_commonState.m_pRepulsor->m_repulsorIdentityFlags = this->m_pTune->m_repulsorIdentityFlags;
  }
  if ( this->m_pTune->m_planLayer != m_planLayer && this->m_behavior.m_state != PUPPET )
  {
    ((void (__fastcall *)(bfx::Vec3 *))this->m_behavior.m_pCurMotion->GetPos)(a1: v30);
    bfx::BuildMoverPathSpec(result: &v31, pTune: this->m_pTune);
    ClosestArea = (bfx::Area *)bfx::Planner::GetClosestArea(
                                 this: *((bfx::Planner **)this->m_pSpace->m_components.m_data + 1),
                                 pos: v30,
                                 layerNum: this->m_pTune->m_planLayer,
                                 pathSpec: &v31);
    if ( ClosestArea != nullptr )
    {
      this->m_behavior.m_pCurMotion->GetMatrix(this: this->m_behavior.m_pCurMotion, a2: v32);
      bfx::MoverImpl::TeleportInternal(
        this,
        desiredMat: v32,
        pNewArea: ClosestArea,
        newVel: &this->m_vel,
        allowTeleportInsideObstacles: false,
        preserveExactInputHeight: false);
    }
    else
    {
      LODWORD(v15) = &dword_82420000;
      HIDWORD(v18) = "Mover switched to empty layer %u";
      LODWORD(v18) = this->m_pTune->m_planLayer;
      bfx::InternalWarning(fmt: v18, a2: v17, a3: v16, a4: v15, a5: v26, a6: v27, a7: v28, a8: v29);
      bfx::Surfer::SetPosAndArea(this: &this->m_commonState.m_surfer, pos: v30, pArea: nullptr);
      bfx::SmartPath::SetStartData(this: this->m_commonState.m_pSmartPath, startPos: v30, pStartArea: nullptr);
      this->m_stranded = true;
    }
    bfx::SmartPath::SetNavLayer(this: this->m_commonState.m_pSmartPath, layer: this->m_pTune->m_planLayer);
  }
  if ( !this->m_pTune->m_autoObTune.m_autoCreateObstacle && m_autoCreateObstacle )
    bfx::AutoObData::ClearObstacle(this: &this->m_autoObData);
  if ( !this->m_pTune->m_proberTune.m_probeForGround || this->m_commonState.m_pProber != nullptr )
  {
    if ( !this->m_pTune->m_proberTune.m_probeForGround )
    {
      m_pProber = (char *)this->m_commonState.m_pProber;
      if ( m_pProber != nullptr )
      {
        bfx::Prober::~Prober(this: this->m_commonState.m_pProber);
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pProber);
        this->m_commonState.m_pProber = nullptr;
      }
    }
  }
  else
  {
    v19 = this->m_commonState.m_pTune;
    v21 = (bfx::Prober *)bfx::MemoryManager::Malloc(
                           this: bfx::g_pCurInstance->m_pMemoryManager,
                           size: 0x30u,
                           tag: bfx::MEM_BFXMOVER);
    if ( v21 != nullptr )
    {
      *(unsigned __int64 *)((char *)&v20 + 4) = v19->m_proberTune.m_probeUserData;
      v22 = bfx::Prober::Prober(this: v21, probeInterval: v19->m_proberTune.m_probeInterval, probeUserData: v20);
    }
    else
    {
      v22 = nullptr;
    }
    this->m_commonState.m_pProber = v22;
  }
  v24 = this->m_commonState.m_pProber;
  if ( v24 != nullptr )
    v24->m_probeInterval = pTune->m_proberTune.m_probeInterval;
  v25 = bfx::BuildMoverPathSpec(result: &v31, pTune: this->m_pTune);
  bfx::SmartPath::SetPathSpec(this: this->m_commonState.m_pSmartPath, pathSpec: v25);
  bfx::SmartPath::SetPathCreationOptions(this: this->m_commonState.m_pSmartPath, options: &this->m_pTune->m_pathOptions);
  bfx::SmartPath::SetNavLayer(this: this->m_commonState.m_pSmartPath, layer: this->m_pTune->m_planLayer);
}


// ========================================================================
// __unwind$37255
// EA  : 0x832BCE70
// RVA : 0x012BCE70
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void _unwind_37255()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(char **)(v0 - 272 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?EnablePuppetMode@MoverImpl@bfx@@QAAX_N@Z
// EA  : 0x832BCEA0
// RVA : 0x012BCEA0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::EnablePuppetMode(bfx::MoverImpl *this, bool enable)
{
  bfx::MoverImpl::State m_state; // r10
  bfx::Command m_command; // r11
  bfx::CommandData *p_m_lastMovementCommand; // r4
  bfx::MoverImpl::State m_prePuppetModeState; // r11

  if ( enable )
  {
    m_state = this->m_behavior.m_state;
    this->m_asyncGotoPosData.m_isValid = false;
    if ( m_state != PUPPET )
    {
      bfx::MoverImpl::SwitchToPuppetMode(this);
      *((_BYTE *)this + 872) &= ~0x10u;
      goto LABEL_18;
    }
    if ( enable )
      return;
  }
  if ( this->m_behavior.m_state != PUPPET )
    return;
  bfx::MoverImpl::PuppetToIdle(this);
  if ( this->m_applyCommandOnPuppetDisable )
  {
    m_command = this->m_lastMovementCommand.m_command;
    p_m_lastMovementCommand = &this->m_lastMovementCommand;
    switch ( m_command )
    {
      case GOTOPOS_COMMAND:
        bfx::MoverImpl::GotoPosCommand(this, commandData: p_m_lastMovementCommand, forceUpdate: true);
        bfx::MoverImpl::ClearFollowMode(this);
        break;
      case STOP_COMMAND:
        bfx::MoverImpl::StopCommand(this, commandData: p_m_lastMovementCommand);
        bfx::MoverImpl::ClearFollowMode(this);
        break;
      case LOCOMOTE_COMMAND:
        bfx::MoverImpl::MoveInDirectionCommand(this, commandData: p_m_lastMovementCommand);
        bfx::MoverImpl::ClearFollowMode(this);
        break;
      default:
        break;
    }
  }
  else
  {
    m_prePuppetModeState = this->m_prePuppetModeState;
    if ( m_prePuppetModeState == PATH_WALKING || m_prePuppetModeState == JUMPING )
    {
      bfx::MoverImpl::GotoPosCommand(this, commandData: &this->m_lastMovementCommand, forceUpdate: true);
    }
    else if ( m_prePuppetModeState == LOCOMOTING )
    {
      bfx::MoverImpl::MoveInDirectionCommand(this, commandData: &this->m_lastMovementCommand);
    }
  }
LABEL_18:
  this->m_applyCommandOnPuppetDisable = false;
}


// ========================================================================
// ?EnableCustomLinkMode@MoverImpl@bfx@@QAA_N_N@Z
// EA  : 0x832BCFD0
// RVA : 0x012BCFD0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
int __fastcall bfx::MoverImpl::EnableCustomLinkMode(bfx::MoverImpl *this, int enable, __int64 a3, __int64 a4)
{
  int v4; // r31
  int v5; // r3
  int v6; // r30
  int v7; // r3
  int v8; // r11
  int v9; // r3
  __int64 v10; // r10
  double v11; // fp30
  double v12; // fp31
  _DWORD *v13; // r11
  int *v15; // r11
  int **v16; // r29
  int v17; // r11
  int v18; // r11
  int v19; // r11
  bool v20; // r11
  unsigned __int8 v21; // r11
  int v22; // r31
  const char *v23; // r3
  const char *v25; // r3
  int v26; // [sp+8h] [-B8h]
  int v27; // [sp+Ch] [-B4h]
  int v28; // [sp+10h] [-B0h]
  int v29; // [sp+14h] [-ACh]
  bfx::Vec3 v30; // [sp+50h] [-70h] BYREF
  float v31; // [sp+60h] [-60h] BYREF
  float v32; // [sp+64h] [-5Ch]
  float v33; // [sp+68h] [-58h]
  bfx::Vec3 v34[2]; // [sp+70h] [-50h] BYREF

  v4 = (unsigned __int8)enable;
  v6 = v5;
  if ( (_BYTE)enable == 0 )
    goto LABEL_40;
  v8 = *(_DWORD *)(v7 + 752);
  *(_BYTE *)(v7 + 876) = 0;
  if ( v8 == 3
    && (*(unsigned __int8 (__fastcall **)(_DWORD))(**(_DWORD **)(v9 + 764) + 112))(a1: *(_DWORD *)(v9 + 764)) != 0 )
  {
    if ( v4 != 0 )
      return 1;
LABEL_40:
    if ( *(_DWORD *)(v6 + 752) == 3
      && (*(unsigned __int8 (__fastcall **)(_DWORD))(**(_DWORD **)(v6 + 764) + 112))(a1: *(_DWORD *)(v6 + 764)) != 0 )
    {
      bfx::MoverImpl::AfterJumping(this: (bfx::MoverImpl *)v6);
    }
    return 1;
  }
  HIDWORD(v10) = 0x82000000;
  v11 = 3.4028235e38;
  v12 = 0.0;
  if ( *(_DWORD *)(v6 + 752) == 1 )
  {
    v13 = *(_DWORD **)(v6 + 788);
    if ( v13 == nullptr || *v13 == 0 )
      bfx::MoverImpl::GotoPosInternal(
        this: (bfx::MoverImpl *)v6,
        requestedGoalPos: (bfx::IslandGraph *)(v6 + 808),
        origSpec: (const bfx::GPSpec *)(v6 + 844),
        forceUpdate: true);
  }
  v15 = *(int **)(v6 + 788);
  v16 = (int **)(v6 + 788);
  if ( v15 != nullptr )
  {
    HIDWORD(v10) = *v15 - 1;
    LOBYTE(v10) = *v15 != 0;
  }
  else
  {
    LOBYTE(v10) = 0;
  }
  if ( (_BYTE)v10 != 0 )
  {
    if ( v15 != nullptr )
      v17 = *v15;
    else
      v17 = 0;
    v12 = *(float *)(*(_DWORD *)(v17 + 52) + 56);
    (*(void (__fastcall **)(bfx::Vec3 *))(**(_DWORD **)(v6 + 776) + 24))(a1: v34);
    if ( *v16 != nullptr )
      v18 = **v16;
    else
      v18 = 0;
    bfx::GetClosestPtOnLineSeg(result: &v30, seg: (const bfx::LineSeg *)(v18 + 8), pos: v34);
    (*(void (__fastcall **)(float *))(**(_DWORD **)(v6 + 776) + 24))(a1: &v31);
    v11 = (float)((float)((float)(v30.m_x - v31) * (float)(v30.m_x - v31))
                + (float)((float)((float)(v30.m_z - v33) * (float)(v30.m_z - v33))
                        + (float)((float)(v30.m_y - v32) * (float)(v30.m_y - v32))));
  }
  LODWORD(v10) = *(_DWORD *)(v6 + 752);
  if ( (_DWORD)v10 != 1
    || (*v16 == nullptr ? (v20 = false) : (v19 = **v16, HIDWORD(v10) = v19 - 1, v20 = v19 != 0),
        !v20 || (v21 = 1, v11 >= (float)((float)v12 * (float)v12))) )
  {
    v21 = 0;
  }
  v22 = v21;
  if ( v21 != 0 )
  {
    if ( (_DWORD)v10 != 3 && (unsigned __int8)bfx::IsLinkFull(halfLink: (bfx::Handle<bfx::HalfLink> *)(v6 + 788)) != 0 )
      return 0;
  }
  else if ( (_DWORD)v10 != 3 )
  {
    if ( (_DWORD)v10 != 1 )
    {
      v23 = "EnableCustomLinkMode(true) ignored (called while not walking)\n";
      bfx::InternalWarning(fmt: *(__int64 *)&enable, a2: a3, a3: a4, a4: v10, a5: v26, a6: v27, a7: v28, a8: v29);
      return 0;
    }
    v25 = "EnableCustomLinkMode(true) ignored (too far from link)\n";
    bfx::InternalWarning(fmt: *(__int64 *)&enable, a2: a3, a3: a4, a4: v10, a5: v26, a6: v27, a7: v28, a8: v29);
    return 0;
  }
  if ( v22 != 0 )
    bfx::MoverImpl::WalkingToJumping(this: (bfx::MoverImpl *)v6, startJumpFrozen: true);
  (*(void (__fastcall **)(_DWORD, int))(**(_DWORD **)(v6 + 764) + 108))(a1: *(_DWORD *)(v6 + 764), a2: 1);
  *(_BYTE *)(v6 + 996) = 0;
  return 1;
}


// ========================================================================
// ?RestoreFromMoverState@MoverImpl@bfx@@QAAXABVMoverSaveRestoreState@2@@Z
// EA  : 0x832BD2B8
// RVA : 0x012BD2B8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::RestoreFromMoverState(
        bfx::MoverImpl *this,
        const bfx::MoverSaveRestoreState *moverSaveRestoreState)
{
  bfx::Command m_command; // r11
  bfx::Vec3 *p_m_vec; // r4
  bfx::OrientMode m_mode; // r11

  m_command = moverSaveRestoreState->m_lastMovementCommand.m_command;
  if ( moverSaveRestoreState->m_lastMovementCommand.m_command == GOTOPOS_COMMAND )
  {
    bfx::MoverImpl::GotoPosCommand(
      this,
      commandData: &moverSaveRestoreState->m_lastMovementCommand,
      forceUpdate: moverSaveRestoreState->m_lastMovementCommand.m_forceGotoPosUpdate);
  }
  else if ( m_command == STOP_COMMAND )
  {
    bfx::MoverImpl::StopCommand(this, commandData: &moverSaveRestoreState->m_lastMovementCommand);
  }
  else
  {
    if ( m_command != LOCOMOTE_COMMAND )
      goto LABEL_8;
    bfx::MoverImpl::MoveInDirectionCommand(this, commandData: &moverSaveRestoreState->m_lastMovementCommand);
  }
  bfx::MoverImpl::ClearFollowMode(this);
LABEL_8:
  p_m_vec = &moverSaveRestoreState->m_orientCmd.m_vec;
  this->m_commonState.m_orientCmd.m_mode = moverSaveRestoreState->m_orientCmd.m_mode;
  this->m_commonState.m_orientCmd.m_vec.m_x = moverSaveRestoreState->m_orientCmd.m_vec.m_x;
  this->m_commonState.m_orientCmd.m_vec.m_y = moverSaveRestoreState->m_orientCmd.m_vec.m_y;
  this->m_commonState.m_orientCmd.m_vec.m_z = moverSaveRestoreState->m_orientCmd.m_vec.m_z;
  m_mode = moverSaveRestoreState->m_orientCmd.m_mode;
  if ( m_mode != ORIENT_IN_TRAVEL_DIR )
  {
    switch ( m_mode )
    {
      case ORIENT_STRICTLY_IN_TRAVEL_DIR:
        bfx::MoverImpl::OrientStrictlyInDirectionOfTravel(this);
        break;
      case ORIENT_TARGET:
        bfx::MoverImpl::OrientTowardsTargetPos(this, targetPos: p_m_vec);
        break;
      case ORIENT_IN_DIR:
        bfx::MoverImpl::OrientInDirection(this, dir: p_m_vec);
        break;
      default:
        break;
    }
  }
  else
  {
    bfx::MoverImpl::OrientInDirectionOfTravel(this);
  }
  if ( moverSaveRestoreState->m_frozen )
    *((_BYTE *)this + 872) |= 0x40u;
  if ( moverSaveRestoreState->m_frozenTranslation )
    *((_BYTE *)this + 872) |= 0x20u;
  if ( moverSaveRestoreState->m_inPuppetMode )
    bfx::MoverImpl::EnablePuppetMode(this, enable: true);
}


// ========================================================================
// ??1MoverImpl@bfx@@UAA@XZ
// EA  : 0x832BD4A8
// RVA : 0x012BD4A8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __fastcall bfx::MoverImpl::~MoverImpl(bfx::MoverImpl *this)
{
  bfx::MotionBase *m_pCurMotion; // r3
  bfx::MoverImpl::MoverBehavior *p_m_behavior; // r28
  char *m_pLeaderDatabase; // r27
  bfx::AreaHandlePath *m_pPath; // r3
  bfx::MoverSpaceComponent *MoverSpaceComponent; // r3
  int v7; // r10
  int v8; // r9
  int v9; // r8
  int v10; // r7
  int v11; // r6
  int v12; // r5
  char *m_data; // r4
  bfx::HandleProxy *m_pProxy; // r3
  char *v15; // r4
  bfx::MotionBase *v16; // r3
  int v17; // [sp+8h] [-88h]
  int v18; // [sp+Ch] [-84h]
  int v19; // [sp+10h] [-80h]
  int v20; // [sp+14h] [-7Ch]
  int v21; // [sp+18h] [-78h]
  bfx::Space *v22; // [sp+1Ch] [-74h]

  this->bfx::HandleTargetBase::__vftable = (bfx::MoverImpl_vtbl *)&bfx::MoverImpl::`vftable'{for `bfx::HandleTargetBase'};
  this->bfx::RepulsorOwner::__vftable = (bfx::RepulsorOwner_vtbl *)&bfx::MoverImpl::`vftable'{for `bfx::RepulsorOwner'};
  bfx::MoverImpl::EnableRepulsor(this, enable: false);
  m_pCurMotion = this->m_behavior.m_pCurMotion;
  p_m_behavior = &this->m_behavior;
  if ( m_pCurMotion != nullptr )
    ((void (__fastcall *)(bfx::MotionBase *, int))m_pCurMotion->dtr_MotionBase)(a1: m_pCurMotion, a2: 1);
  this->m_behavior.m_pCurMotion = nullptr;
  this->m_behavior.m_pWalker = nullptr;
  this->m_behavior.m_pLocomoter = nullptr;
  this->m_behavior.m_pJumper = nullptr;
  this->m_behavior.m_pIdle = nullptr;
  this->m_behavior.m_pPuppet = nullptr;
  p_m_behavior->m_state = 0;
  m_pLeaderDatabase = (char *)this->m_pLeaderDatabase;
  if ( m_pLeaderDatabase != nullptr )
  {
    bfx::FollowerLeaderDatabase::~FollowerLeaderDatabase(this: this->m_pLeaderDatabase);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pLeaderDatabase);
  }
  this->m_pLeaderDatabase = nullptr;
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)this->m_pTrail);
  m_pPath = this->m_pPath;
  this->m_pTrail = nullptr;
  if ( m_pPath != nullptr )
    ((void (__fastcall *)(bfx::AreaHandlePath *, int))m_pPath->dtr_Path)(a1: m_pPath, a2: 1);
  this->m_pPath = nullptr;
  MoverSpaceComponent = bfx::GetMoverSpaceComponent(pSpace: this->m_pSpace);
  bfx::MoverSpaceComponent::RemoveMover(
    this: MoverSpaceComponent,
    pMover: (bfx::Space *)this,
    a3: v12,
    a4: v11,
    a5: v10,
    a6: v9,
    a7: v8,
    a8: v7,
    a9: v17,
    a10: v18,
    a11: v19,
    a12: v20,
    a13: v21,
    a14: v22);
  bfx::AutoObData::~AutoObData(this: &this->m_autoObData);
  m_data = (char *)this->m_goalsReached.m_data;
  this->m_goalsReached.m_size = 0;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_goalsReached.m_data = nullptr;
  }
  this->m_goalsReached.m_cap = 0;
  bfx::JumpClientData::~JumpClientData(this: &this->m_jumpClientData);
  bfx::PathSharingHelper::~PathSharingHelper(this: &this->m_pathSharingHelper);
  m_pProxy = this->m_curGoalLink.m_pProxy;
  if ( m_pProxy != nullptr )
  {
    bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
    this->m_curGoalLink.m_pProxy = nullptr;
  }
  v15 = this->m_debugName.m_data;
  if ( v15 != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v15);
  v16 = this->m_behavior.m_pCurMotion;
  if ( v16 != nullptr )
    ((void (__fastcall *)(bfx::MotionBase *, int))v16->dtr_MotionBase)(a1: v16, a2: 1);
  this->m_behavior.m_pCurMotion = nullptr;
  this->m_behavior.m_pWalker = nullptr;
  this->m_behavior.m_pLocomoter = nullptr;
  this->m_behavior.m_pJumper = nullptr;
  this->m_behavior.m_pIdle = nullptr;
  this->m_behavior.m_pPuppet = nullptr;
  p_m_behavior->m_state = 0;
  bfx::MotionState::~MotionState(this: &this->m_commonState);
  this->bfx::RepulsorOwner::__vftable = (bfx::RepulsorOwner_vtbl *)&bfx::RepulsorOwner::`vftable';
  bfx::HandleTargetBase::~HandleTargetBase(this);
}


// ========================================================================
// __unwind$37655
// EA  : 0x832BD66C
// RVA : 0x012BD66C
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void _unwind_37655()
{
  int v0; // r12

  bfx::HandleTargetBase::~HandleTargetBase(this: *(bfx::HandleTargetBase **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$37656
// EA  : 0x832BD694
// RVA : 0x012BD694
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void _unwind_37656()
{
  int v0; // r12

  bfx::RepulsorOwner::~RepulsorOwner(this: (bfx::RepulsorOwner *)(*(_DWORD *)(v0 - 144 + 164) + 8));
}


// ========================================================================
// __unwind$37657
// EA  : 0x832BD6C0
// RVA : 0x012BD6C0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void _unwind_37657()
{
  int v0; // r12

  bfx::MotionState::~MotionState(this: (bfx::MotionState *)(*(_DWORD *)(v0 - 144 + 164) + 304));
}


// ========================================================================
// __unwind$37658
// EA  : 0x832BD6EC
// RVA : 0x012BD6EC
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void _unwind_37658()
{
  int v0; // r12

  bfx::MoverImpl::MoverBehavior::~MoverBehavior(this: (bfx::MoverImpl::MoverBehavior *)(*(_DWORD *)(v0 - 144 + 164) + 752));
}


// ========================================================================
// __unwind$37659
// EA  : 0x832BD718
// RVA : 0x012BD718
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void _unwind_37659()
{
  int v0; // r12

  bfx::String::~String(this: (bfx::String *)(*(_DWORD *)(v0 - 144 + 164) + 780));
}


// ========================================================================
// __unwind$37660
// EA  : 0x832BD744
// RVA : 0x012BD744
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void _unwind_37660()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: (bfx::Handle<bfx::Space> *)(*(_DWORD *)(v0 - 144 + 164) + 788));
}


// ========================================================================
// __unwind$37661
// EA  : 0x832BD770
// RVA : 0x012BD770
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void _unwind_37661()
{
  int v0; // r12

  bfx::PathSharingHelper::~PathSharingHelper(this: (bfx::PathSharingHelper *)(*(_DWORD *)(v0 - 144 + 164) + 792));
}


// ========================================================================
// __unwind$37662
// EA  : 0x832BD79C
// RVA : 0x012BD79C
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void _unwind_37662()
{
  int v0; // r12

  bfx::JumpClientData::~JumpClientData(this: (bfx::JumpClientData *)(*(_DWORD *)(v0 - 144 + 164) + 1004));
}


// ========================================================================
// __unwind$37663
// EA  : 0x832BD7C8
// RVA : 0x012BD7C8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void _unwind_37663()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                             + 1104));
}


// ========================================================================
// __unwind$37664
// EA  : 0x832BD7F4
// RVA : 0x012BD7F4
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void _unwind_37664()
{
  int v0; // r12

  bfx::AutoObData::~AutoObData(this: (bfx::AutoObData *)(*(_DWORD *)(v0 - 144 + 164) + 1144));
}


// ========================================================================
// bfx::`dynamic initializer for 'gotoposTimer''
// EA  : 0x833993C8
// RVA : 0x013993C8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__gotoposTimer__()
{
  int v0; // r9

  v0 = bfx::g_nextFTimerEntryID;
  bfx::gotoposTimer.m_pNext = bfx::g_pFTimerEntryHead;
  bfx::gotoposTimer.m_timerID = bfx::g_nextFTimerEntryID;
  if ( bfx::g_pFTimerEntryHead != nullptr )
  {
    bfx::g_pFTimerEntryHead->m_pPrev = &bfx::gotoposTimer;
    v0 = bfx::g_nextFTimerEntryID;
  }
  bfx::g_pFTimerEntryHead = &bfx::gotoposTimer;
  bfx::g_nextFTimerEntryID = v0 + 1;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__gotoposTimer__);
}


// ========================================================================
// bfx::`dynamic initializer for 'teleportTimer''
// EA  : 0x83399410
// RVA : 0x01399410
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__teleportTimer__()
{
  int v0; // r9

  v0 = bfx::g_nextFTimerEntryID;
  bfx::teleportTimer.m_pNext = bfx::g_pFTimerEntryHead;
  bfx::teleportTimer.m_timerID = bfx::g_nextFTimerEntryID;
  if ( bfx::g_pFTimerEntryHead != nullptr )
  {
    bfx::g_pFTimerEntryHead->m_pPrev = &bfx::teleportTimer;
    v0 = bfx::g_nextFTimerEntryID;
  }
  bfx::g_pFTimerEntryHead = &bfx::teleportTimer;
  bfx::g_nextFTimerEntryID = v0 + 1;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__teleportTimer__);
}


// ========================================================================
// bfx::`dynamic initializer for 'closestPosTimer''
// EA  : 0x83399458
// RVA : 0x01399458
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__closestPosTimer__()
{
  int v0; // r9

  v0 = bfx::g_nextFTimerEntryID;
  bfx::closestPosTimer.m_pNext = bfx::g_pFTimerEntryHead;
  bfx::closestPosTimer.m_timerID = bfx::g_nextFTimerEntryID;
  if ( bfx::g_pFTimerEntryHead != nullptr )
  {
    bfx::g_pFTimerEntryHead->m_pPrev = &bfx::closestPosTimer;
    v0 = bfx::g_nextFTimerEntryID;
  }
  bfx::g_pFTimerEntryHead = &bfx::closestPosTimer;
  bfx::g_nextFTimerEntryID = v0 + 1;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__closestPosTimer__);
}

