
// ========================================================================
// ?GetRot@MoverImpl@bfx@@QBA?AVQuat@2@XZ
// EA  : 0x83261798
// RVA : 0x01261798
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.h
// ========================================================================

bfx::MoverImpl *__fastcall bfx::MoverImpl::GetRot(bfx::MoverImpl *this, bfx::Quat *result)
{
  bfx::Matrix v4; // [sp+50h] [-50h] BYREF

  (*(void (__fastcall **)(_DWORD, bfx::Matrix *))(*(_DWORD *)LODWORD(result[48].m_y) + 28))(
    a1: LODWORD(result[48].m_y),
    a2: &v4);
  bfx::Quat::Quat((bfx::Quat *)this, m: &v4);
  return this;
}


// ========================================================================
// ?IsFollowerMode@MotionState@bfx@@QBA_NXZ
// EA  : 0x832AEFC0
// RVA : 0x012AEFC0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.h
// ========================================================================

BOOL __fastcall bfx::MotionState::IsFollowerMode(bfx::MotionState *this)
{
  bfx::HandleProxy *m_pProxy; // r11
  bool v2; // r10

  m_pProxy = this->m_followData.m_targetMover.m_pProxy;
  v2 = m_pProxy != nullptr && m_pProxy->m_pTarget != nullptr;
  return v2 && m_pProxy != nullptr && m_pProxy->m_pTarget != nullptr;
}


// ========================================================================
// ??0FollowData@MotionState@bfx@@QAA@XZ
// EA  : 0x832B0B28
// RVA : 0x012B0B28
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.h
// ========================================================================

bfx::MotionState::FollowData *__fastcall bfx::MotionState::FollowData::FollowData(bfx::MotionState::FollowData *this)
{
  this->m_targetMover.m_pProxy = nullptr;
  bfx::MotionState::FollowData::Clear(this);
  return this;
}


// ========================================================================
// __unwind$91257
// EA  : 0x832B0B78
// RVA : 0x012B0B78
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.h
// ========================================================================

void _unwind_91257()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: (bfx::Handle<bfx::Space> *)(*(_DWORD *)(v0 - 112 + 132) + 24));
}


// ========================================================================
// ?GetPos@MotionState@bfx@@QBA?AVVec3@2@XZ
// EA  : 0x832B2828
// RVA : 0x012B2828
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.h
// ========================================================================

bfx::MotionState *__fastcall bfx::MotionState::GetPos(bfx::MotionState *this, bfx::Vec3 *result)
{
  float m_x; // r10
  bfx::Vec3 *v3; // r11
  double v4; // fp8
  double v5; // fp6
  _DWORD back_chain[4]; // [sp+0h] [-10h] BYREF

  m_x = result[28].m_x;
  if ( m_x == 0.0 )
  {
    v3 = &bfx::ZERO_VEC;
  }
  else
  {
    v3 = (bfx::Vec3 *)back_chain;
    back_chain[2] = *(_DWORD *)(LODWORD(m_x) + 24);
  }
  v4 = (float)(result[2].m_x + v3->m_y);
  v5 = (float)(result[2].m_y + v3->m_z);
  *(float *)&this->m_pSpace = result[1].m_z + v3->m_x;
  *(float *)&this->m_pTune = v4;
  *(float *)&this->m_replayID = v5;
  return this;
}


// ========================================================================
// ?GetDesiredVel@MotionBase@bfx@@UBA?AVVec3@2@XZ
// EA  : 0x832B5C08
// RVA : 0x012B5C08
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.h
// ========================================================================

bfx::MotionBase *__fastcall bfx::MotionBase::GetDesiredVel(bfx::MotionBase *this, bfx::Vec3 *result)
{
  float m_y; // r8
  float m_z; // r7

  m_y = bfx::ZERO_VEC.m_y;
  m_z = bfx::ZERO_VEC.m_z;
  this->__vftable = (bfx::MotionBase_vtbl *)LODWORD(bfx::ZERO_VEC.m_x);
  *((float *)this + 1) = m_y;
  *((float *)this + 2) = m_z;
  return this;
}


// ========================================================================
// ??0CommandData@bfx@@QAA@XZ
// EA  : 0x832B7090
// RVA : 0x012B7090
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.h
// ========================================================================

bfx::CommandData *__fastcall bfx::CommandData::CommandData(bfx::CommandData *this)
{
  float m_z; // r5

  this->m_command = NO_COMMAND;
  this->m_vec.m_x = bfx::ZERO_VEC.m_x;
  this->m_vec.m_y = bfx::ZERO_VEC.m_y;
  m_z = bfx::ZERO_VEC.m_z;
  this->m_moveInDirectionSpeed = 0.0;
  this->m_forceGotoPosUpdate = false;
  this->m_vec.m_z = m_z;
  bfx::GPSpec::GPSpec(this: &this->m_gpSpec);
  bfx::MIDSpec::MIDSpec(this: &this->m_midSpec);
  bfx::StpSpec::StpSpec(this: &this->m_stopSpec);
  bfx::FMSpec::FMSpec(this: &this->m_fmSpec);
  return this;
}


// ========================================================================
// ??1PathSharingHelper@bfx@@QAA@XZ
// EA  : 0x832BB160
// RVA : 0x012BB160
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.h
// ========================================================================

void __fastcall bfx::PathSharingHelper::~PathSharingHelper(bfx::PathSharingHelper *this)
{
  bfx::PathSharingHelper::ClearAll(this);
  if ( this->m_linkBase.m_pProxy != nullptr )
  {
    bfx::HandleProxy::RemRefToHandleProxy(this: this->m_linkBase.m_pProxy);
    this->m_linkBase.m_pProxy = nullptr;
  }
}


// ========================================================================
// __unwind$35891
// EA  : 0x832BB1B4
// RVA : 0x012BB1B4
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.h
// ========================================================================

void _unwind_35891()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: *(bfx::Handle<bfx::Space> **)(v0 - 112 + 132));
}


// ========================================================================
// ?GetRepulsorOwner@MoverImpl@bfx@@UAAPAXXZ
// EA  : 0x832BCBA8
// RVA : 0x012BCBA8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.h
// ========================================================================

char *__fastcall bfx::MoverImpl::GetRepulsorOwner(bfx::MoverImpl *this)
{
  return (char *)this - 8;
}


// ========================================================================
// ?IsPushedToSide@FollowData@MotionState@bfx@@QAA_NXZ
// EA  : 0x832CDA58
// RVA : 0x012CDA58
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoverimpl.h
// ========================================================================

int __fastcall bfx::MotionState::FollowData::IsPushedToSide(bfx::MotionState::FollowData *this)
{
  bfx::HandleProxy *m_pProxy; // r11
  double m_sidePushCountdown; // fp13
  int result; // r3

  m_pProxy = this->m_targetMover.m_pProxy;
  if ( m_pProxy == nullptr )
    return 0;
  if ( m_pProxy->m_pTarget == nullptr )
    return 0;
  if ( (float)((float)(this->m_externalForce.m_z * this->m_externalForce.m_z)
             + (float)((float)(this->m_externalForce.m_x * this->m_externalForce.m_x)
                     + (float)(this->m_externalForce.m_y * this->m_externalForce.m_y))) <= 0.0009765625 )
    return 0;
  m_sidePushCountdown = this->m_sidePushCountdown;
  result = 1;
  if ( m_sidePushCountdown <= 0.0 )
    return 0;
  return result;
}

