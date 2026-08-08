
// ========================================================================
// ?Teleport@PuppetImpl@bfx@@UAAXABVMatrix@2@ABVVec3@2@PAVArea@2@@Z
// EA  : 0x832D9618
// RVA : 0x012D9618
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxpuppet.cpp
// ========================================================================

void __fastcall bfx::PuppetImpl::Teleport(
        bfx::PuppetImpl *this,
        const bfx::Matrix *newMat,
        const bfx::Vec3 *__formal,
        bfx::Area *a4)
{
  double v5; // fp13
  double v6; // fp12
  bfx::Quat *v7; // r3
  bfx::Quat v8; // [sp+50h] [-20h] BYREF

  v5 = newMat->m_data[13];
  v6 = newMat->m_data[14];
  this->m_pos.m_x = newMat->m_data[12];
  this->m_pos.m_y = v5;
  this->m_pos.m_z = v6;
  bfx::Quat::Quat(this: &v8, m: newMat);
  this->m_rot = *v7;
}


// ========================================================================
// ?GetInitialConstraint@PuppetImpl@bfx@@UAAXAAVInitialConstraint@2@@Z
// EA  : 0x832D9680
// RVA : 0x012D9680
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxpuppet.cpp
// ========================================================================

void __fastcall bfx::PuppetImpl::GetInitialConstraint(bfx::PuppetImpl *this, bfx::InitialConstraint *initialConstraint)
{
  initialConstraint->m_constraintType = this->m_commonState->m_pTune->m_puppetTune.m_repulsionConstraintMode == NOT_PUSHABLE
                                      ? CONSTRAINT_POINT
                                      : CONSTRAINT_NONE;
}


// ========================================================================
// ?RepulsionPush@PuppetImpl@bfx@@UAAXABVVec3@2@M@Z
// EA  : 0x832D96A8
// RVA : 0x012D96A8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxpuppet.cpp
// ========================================================================

void __fastcall bfx::PuppetImpl::RepulsionPush(bfx::PuppetImpl *this, const bfx::Vec3 *velocity, double time)
{
  bfx::PuppetTune::RepulsionConstraintMode m_repulsionConstraintMode; // r11
  double v5; // fp31
  double v6; // fp30
  double v7; // fp29
  bfx::UpAxis UpAxis; // r3
  bfx::Vec3 *UpVec; // r3
  double m_x; // fp0
  double m_y; // fp13
  double m_z; // fp12
  char v13; // r11
  double v14; // fp7
  double v15; // fp6
  double v16; // fp10
  double v17; // fp9
  bfx::Vec3 v18[2]; // [sp+50h] [-40h] BYREF

  m_repulsionConstraintMode = this->m_commonState->m_pTune->m_puppetTune.m_repulsionConstraintMode;
  if ( m_repulsionConstraintMode != NOT_PUSHABLE )
  {
    v5 = (float)(velocity->m_x * (float)time);
    v6 = (float)(velocity->m_y * (float)time);
    v7 = (float)(velocity->m_z * (float)time);
    if ( m_repulsionConstraintMode == PUSHABLE_WITHIN_GLOBAL_HORIZONTAL_PLANE )
    {
      UpAxis = bfx::GetUpAxis();
      UpVec = bfx::GetUpVec(result: v18, upAxis: UpAxis);
      m_x = UpVec->m_x;
      m_y = UpVec->m_y;
      m_z = UpVec->m_z;
    }
    else
    {
      m_x = this->m_lastAreaNormal.m_x;
      m_y = this->m_lastAreaNormal.m_y;
      m_z = this->m_lastAreaNormal.m_z;
    }
    if ( m_x != 0.0 || m_y != 0.0 || (v13 = 1, m_z != 0.0) )
      v13 = 0;
    if ( v13 == 0 )
    {
      v14 = (float)((float)m_y
                  * (float)((float)((float)v5 * (float)m_x)
                          + (float)((float)((float)m_z * (float)v7) + (float)((float)m_y * (float)v6))));
      v15 = (float)((float)m_z
                  * (float)((float)((float)v5 * (float)m_x)
                          + (float)((float)((float)m_z * (float)v7) + (float)((float)m_y * (float)v6))));
      v5 = (float)((float)v5
                 - (float)((float)((float)((float)v5 * (float)m_x)
                                 + (float)((float)((float)m_z * (float)v7) + (float)((float)m_y * (float)v6)))
                         * (float)m_x));
      v6 = (float)((float)v6 - (float)v14);
      v7 = (float)((float)v7 - (float)v15);
    }
    v16 = (float)(this->m_pos.m_y + (float)v6);
    v17 = (float)(this->m_pos.m_z + (float)v7);
    this->m_pos.m_x = (float)v5 + this->m_pos.m_x;
    this->m_pos.m_y = v16;
    this->m_pos.m_z = v17;
  }
}


// ========================================================================
// ??0PuppetImpl@bfx@@QAA@ABVMatrix@1@AAVMotionState@1@@Z
// EA  : 0x832D97E0
// RVA : 0x012D97E0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxpuppet.cpp
// ========================================================================

bfx::PuppetImpl *__fastcall bfx::PuppetImpl::PuppetImpl(
        bfx::PuppetImpl *this,
        const bfx::Matrix *startMat,
        bfx::MotionState *commonState)
{
  double v4; // fp0
  double v5; // fp13
  double v6; // fp12
  const bfx::MoverTune *m_pTune; // r8
  bfx::MotionState *m_commonState; // r11
  bfx::Quat *v9; // r3
  double m_y; // fp13
  double m_z; // fp12
  bfx::Vec3 v13; // [sp+58h] [-48h] BYREF
  bfx::Quat v14; // [sp+70h] [-30h] BYREF

  this->m_commonState = commonState;
  v4 = startMat->m_data[12];
  v5 = startMat->m_data[14];
  v6 = startMat->m_data[13];
  this->__vftable = (bfx::PuppetImpl_vtbl *)&bfx::PuppetImpl::`vftable';
  m_pTune = commonState->m_pTune;
  this->m_pos.m_y = v6;
  this->m_pos.m_z = v5;
  this->m_pTune = m_pTune;
  this->m_pos.m_x = v4;
  bfx::Quat::Quat(this: &v14, m: startMat);
  m_commonState = this->m_commonState;
  this->m_rot = *v9;
  if ( (unsigned __int8)bfx::Surfer::GetAreaNormal(this: &m_commonState->m_surfer, normalOut: &v13) != 0 )
  {
    m_y = v13.m_y;
    m_z = v13.m_z;
    this->m_lastAreaNormal.m_x = v13.m_x;
    this->m_lastAreaNormal.m_y = m_y;
    this->m_lastAreaNormal.m_z = m_z;
  }
  else
  {
    this->m_lastAreaNormal.m_x = 0.0;
    this->m_lastAreaNormal.m_y = 0.0;
    this->m_lastAreaNormal.m_z = 0.0;
  }
  return this;
}


// ========================================================================
// __unwind$23726
// EA  : 0x832D98E4
// RVA : 0x012D98E4
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxpuppet.cpp
// ========================================================================

void _unwind_23726()
{
  int v0; // r12

  bfx::Idle::~Idle(this: *(bfx::Walker **)(v0 - 160 + 180));
}


// ========================================================================
// ?GetPos@PuppetImpl@bfx@@UBA?AVVec3@2@XZ
// EA  : 0x832D9910
// RVA : 0x012D9910
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxpuppet.cpp
// ========================================================================

bfx::PuppetImpl *__fastcall bfx::PuppetImpl::GetPos(bfx::PuppetImpl *this, bfx::Vec3 *result)
{
  float m_y; // r10
  float m_z; // r9

  m_y = result[1].m_y;
  m_z = result[1].m_z;
  this->__vftable = (bfx::PuppetImpl_vtbl *)LODWORD(result[1].m_x);
  *(float *)&this->m_commonState = m_y;
  *(float *)&this->m_pTune = m_z;
  return this;
}


// ========================================================================
// ?GetMatrix@PuppetImpl@bfx@@UBAXAAVMatrix@2@@Z
// EA  : 0x832D9930
// RVA : 0x012D9930
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxpuppet.cpp
// ========================================================================

void __fastcall bfx::PuppetImpl::GetMatrix(bfx::PuppetImpl *this, bfx::Matrix *mat)
{
  bfx::Matrix::Build(this: mat, q: &this->m_rot, pos: &this->m_pos);
}


// ========================================================================
// ?SetPos@PuppetImpl@bfx@@UAAXABVVec3@2@@Z
// EA  : 0x832D9948
// RVA : 0x012D9948
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxpuppet.cpp
// ========================================================================

void __fastcall bfx::PuppetImpl::SetPos(bfx::PuppetImpl *this, const bfx::Vec3 *pos)
{
  this->m_pos = *pos;
}


// ========================================================================
// ?SetRot@PuppetImpl@bfx@@UAAXABVQuat@2@@Z
// EA  : 0x832D9968
// RVA : 0x012D9968
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxpuppet.cpp
// ========================================================================

void __fastcall bfx::PuppetImpl::SetRot(bfx::PuppetImpl *this, const bfx::Quat *rot)
{
  this->m_rot = *rot;
}


// ========================================================================
// ?CreatePuppet@bfx@@YAPAVPuppet@1@ABVMatrix@1@AAVMotionState@1@@Z
// EA  : 0x832D9998
// RVA : 0x012D9998
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxpuppet.cpp
// ========================================================================

bfx::PuppetImpl *__fastcall bfx::CreatePuppet(const bfx::Matrix *startMat, bfx::MotionState *commonState)
{
  bfx::PuppetImpl *v4; // r3

  v4 = (bfx::PuppetImpl *)bfx::MemoryManager::Malloc(
                            this: bfx::g_pCurInstance->m_pMemoryManager,
                            size: 0x34u,
                            tag: bfx::MEM_BFXMOVER);
  if ( v4 != nullptr )
    return bfx::PuppetImpl::PuppetImpl(this: v4, startMat, commonState);
  else
    return nullptr;
}


// ========================================================================
// __unwind$23845
// EA  : 0x832D99F4
// RVA : 0x012D99F4
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxpuppet.cpp
// ========================================================================

void _unwind_23845()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(char **)(v0 - 128 + 80), __formal: MEMHEAP_DEFAULT);
}

