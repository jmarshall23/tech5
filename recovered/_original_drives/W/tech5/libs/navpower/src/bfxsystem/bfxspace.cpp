
// ========================================================================
// ?GetSpaceID@bfx@@YAIPBVSpace@1@@Z
// EA  : 0x8324F090
// RVA : 0x0124F090
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

unsigned int __fastcall bfx::GetSpaceID(const bfx::Space *pSpace)
{
  if ( pSpace != nullptr )
    return pSpace->m_spaceID;
  else
    return -1;
}


// ========================================================================
// ?SetPos@Space@bfx@@QAAXABVVec3@2@@Z
// EA  : 0x8324F0A8
// RVA : 0x0124F0A8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

void __fastcall bfx::Space::SetPos(bfx::Space *this, const bfx::Vec3 *pos)
{
  bfx::Matrix *p_m_matSpaceToWorld; // r30
  bfx::Matrix v4; // [sp+50h] [-60h] BYREF

  this->m_pos = *pos;
  p_m_matSpaceToWorld = &this->m_matSpaceToWorld;
  bfx::Matrix::Build(this: &this->m_matSpaceToWorld, q: &this->m_rotSpaceToWorld, pos: &this->m_pos);
  v4 = *p_m_matSpaceToWorld;
  bfx::Matrix::OrthoInvert(this: &v4);
  this->m_matWorldToSpace = v4;
}


// ========================================================================
// ?SetRot@Space@bfx@@QAAXABVQuat@2@@Z
// EA  : 0x8324F130
// RVA : 0x0124F130
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

void __fastcall bfx::Space::SetRot(bfx::Space *this, const bfx::Quat *rot)
{
  bfx::Matrix *p_m_matSpaceToWorld; // r30
  bfx::Quat v4; // [sp+50h] [-70h] BYREF
  bfx::Matrix v5; // [sp+60h] [-60h] BYREF

  this->m_rotSpaceToWorld = *rot;
  p_m_matSpaceToWorld = &this->m_matSpaceToWorld;
  bfx::Matrix::Build(this: &this->m_matSpaceToWorld, q: &this->m_rotSpaceToWorld, pos: &this->m_pos);
  v5 = *p_m_matSpaceToWorld;
  bfx::Matrix::OrthoInvert(this: &v5);
  this->m_matWorldToSpace = v5;
  this->m_rotWorldToSpace = *bfx::Quat::Quat(this: &v4, m: &this->m_matWorldToSpace);
}


// ========================================================================
// ??0SpaceCursor@bfx@@QAA@XZ
// EA  : 0x8324F288
// RVA : 0x0124F288
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

bfx::SpaceCursor *__fastcall bfx::SpaceCursor::SpaceCursor(bfx::SpaceCursor *this)
{
  bfx::SpaceManager *m_pSpaceManager; // r9

  m_pSpaceManager = bfx::g_pCurInstance->m_pSpaceManager;
  this->m_cc.m_i = 0;
  this->m_cc.m_pArray = &m_pSpaceManager->m_spaces;
  return this;
}


// ========================================================================
// ?GetVolume@bfx@@YAPAVVolume@1@ABVVolumeHandle@1@@Z
// EA  : 0x8324F2A8
// RVA : 0x0124F2A8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

bfx::Space *__fastcall bfx::GetVolume(bfx::SpaceHandle *spaceHandle)
{
  if ( spaceHandle->m_pProxy != nullptr )
    return *(bfx::Space **)spaceHandle->m_pProxy;
  else
    return nullptr;
}


// ========================================================================
// ??8SpaceHandle@bfx@@QBA_NABV01@@Z
// EA  : 0x8324F2C8
// RVA : 0x0124F2C8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

BOOL __fastcall bfx::SpaceHandle::operator==(bfx::SpaceHandle *this, const bfx::SpaceHandle *rhs)
{
  bfx::APICriticalSection *m_pGlobalCS; // r30
  int v5; // r10
  int v6; // r11
  BOOL v7; // r31

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &bfx::g_pCurInstance->m_pGlobalCS->m_criticalSection);
  if ( this->m_pProxy != nullptr )
    v5 = *(_DWORD *)this->m_pProxy;
  else
    v5 = 0;
  if ( rhs->m_pProxy != nullptr )
    v6 = *(_DWORD *)rhs->m_pProxy;
  else
    v6 = 0;
  v7 = (_cntlzw(v6 - v5) & 0x20) != 0;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return v7;
}


// ========================================================================
// ?GetPos@SpaceHandle@bfx@@QBA?AVVector3@2@XZ
// EA  : 0x8324F350
// RVA : 0x0124F350
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

bfx::SpaceHandle *__fastcall bfx::SpaceHandle::GetPos(bfx::SpaceHandle *this, bfx::Vector3 *result)
{
  bfx::APICriticalSection *m_pGlobalCS; // r30
  int v5; // r11
  float m_y; // r8
  float m_z; // r7
  float v9; // [sp+50h] [-30h]
  float v10; // [sp+54h] [-2Ch]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &bfx::g_pCurInstance->m_pGlobalCS->m_criticalSection);
  if ( LODWORD(result->m_x) != 0 )
    v5 = *(_DWORD *)LODWORD(result->m_x);
  else
    v5 = 0;
  if ( v5 != 0 )
  {
    v9 = *(float *)(v5 + 12);
    v10 = *(float *)(v5 + 16);
    *(this + 2) = *(bfx::SpaceHandle *)(v5 + 20);
    *((float *)this + 1) = v10;
    *(float *)&this->m_pProxy = v9;
  }
  else
  {
    m_y = ZERO_VECTOR_10.m_y;
    m_z = ZERO_VECTOR_10.m_z;
    this->m_pProxy = (void *)LODWORD(ZERO_VECTOR_10.m_x);
    *((float *)this + 1) = m_y;
    *((float *)this + 2) = m_z;
  }
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return this;
}


// ========================================================================
// ?SetPos@SpaceHandle@bfx@@QAAXABVVector3@2@@Z
// EA  : 0x8324F418
// RVA : 0x0124F418
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

void __fastcall bfx::SpaceHandle::SetPos(bfx::SpaceHandle *this, const bfx::Vector3 *pos)
{
  bfx::Space *v4; // r3
  double m_y; // fp13
  double m_x; // fp12
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-40h]
  bfx::Vec3 v8; // [sp+58h] [-38h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogSpaceHandleSetPos(spaceHandle: this, pos);
  if ( this->m_pProxy != nullptr )
    v4 = *(bfx::Space **)this->m_pProxy;
  else
    v4 = nullptr;
  if ( v4 != nullptr )
  {
    m_y = pos->m_y;
    m_x = pos->m_x;
    v8.m_z = pos->m_z;
    v8.m_x = m_x;
    v8.m_y = m_y;
    bfx::Space::SetPos(this: v4, pos: &v8);
  }
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$73799
// EA  : 0x8324F4B8
// RVA : 0x0124F4B8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

void _unwind_73799()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 144 + 80));
}


// ========================================================================
// ?GetRot@SpaceHandle@bfx@@QBA?AVQuaternion@2@XZ
// EA  : 0x8324F4E8
// RVA : 0x0124F4E8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

bfx::SpaceHandle *__fastcall bfx::SpaceHandle::GetRot(bfx::SpaceHandle *this, bfx::Quaternion *result)
{
  int v4; // r11
  double v5; // fp13
  double v6; // fp12
  double v7; // fp11
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-60h]
  bfx::Vector3 v10; // [sp+58h] [-58h] BYREF
  bfx::Vector3 v11; // [sp+68h] [-48h] BYREF
  bfx::Vector3 v12; // [sp+78h] [-38h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  if ( LODWORD(result->m_w) != 0 )
    v4 = *(_DWORD *)LODWORD(result->m_w);
  else
    v4 = 0;
  if ( v4 != 0 )
  {
    v5 = *(float *)(v4 + 28);
    v6 = *(float *)(v4 + 32);
    v7 = *(float *)(v4 + 36);
    this->m_pProxy = *(void **)(v4 + 24);
    *((float *)this + 1) = v5;
    *((float *)this + 2) = v6;
    *((float *)this + 3) = v7;
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return this;
  }
  else
  {
    v10.m_x = 0.0;
    v10.m_y = 0.0;
    v10.m_z = 1.0;
    v11.m_x = 0.0;
    v11.m_y = 1.0;
    v11.m_z = 0.0;
    v12.m_x = 1.0;
    v12.m_y = 0.0;
    v12.m_z = 0.0;
    bfx::Quaternion::Quaternion((bfx::Quaternion *)this, forwAxisIn: &v12, leftAxisIn: &v11, upAxisIn: &v10);
    if ( m_pGlobalCS != nullptr )
      RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    return this;
  }
}


// ========================================================================
// __unwind$73866
// EA  : 0x8324F5E8
// RVA : 0x0124F5E8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

void _unwind_73866()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 176 + 80));
}


// ========================================================================
// ?SetRot@SpaceHandle@bfx@@QAAXABVQuaternion@2@@Z
// EA  : 0x8324F618
// RVA : 0x0124F618
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

void __fastcall bfx::SpaceHandle::SetRot(bfx::SpaceHandle *this, const bfx::Quaternion *rot)
{
  bfx::Space *v4; // r29
  double m_y; // fp13
  double m_x; // fp12
  double m_w; // fp11
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-50h]
  bfx::Quat v9[4]; // [sp+60h] [-40h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogSpaceHandleSetRot(spaceHandle: this, rot);
  if ( this->m_pProxy != nullptr )
    v4 = *(bfx::Space **)this->m_pProxy;
  else
    v4 = nullptr;
  if ( v4 != nullptr )
  {
    m_y = rot->m_y;
    m_x = rot->m_x;
    m_w = rot->m_w;
    v9[0].m_z = rot->m_z;
    v9[0].m_y = m_y;
    v9[0].m_w = m_w;
    v9[0].m_x = m_x;
    bfx::Quat::Normalize(this: v9);
    bfx::Space::SetRot(this: v4, rot: v9);
  }
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$73992
// EA  : 0x8324F6CC
// RVA : 0x0124F6CC
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

void _unwind_73992()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 160 + 80));
}


// ========================================================================
// ?GetSpaceID@bfx@@YAIABVSpaceHandle@1@@Z
// EA  : 0x8324F7E8
// RVA : 0x0124F7E8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

unsigned int __fastcall bfx::GetSpaceID(const bfx::SpaceHandle *space)
{
  int v1; // r11

  if ( space->m_pProxy != nullptr )
    v1 = *(_DWORD *)space->m_pProxy;
  else
    v1 = 0;
  if ( v1 != 0 )
    return *(_DWORD *)(v1 + 8);
  else
    return -1;
}


// ========================================================================
// ??0Space@bfx@@AAA@I@Z
// EA  : 0x8324F820
// RVA : 0x0124F820
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

bfx::Space *__fastcall bfx::Space::Space(bfx::Space *this, unsigned int spaceID)
{
  bfx::Array<bfx::SpaceComponent *> *p_m_components; // r29
  bfx::bfxMemTag v4; // r11

  this->m_pProxy = nullptr;
  this->m_spaceID = spaceID;
  this->__vftable = (bfx::Space_vtbl *)&bfx::Space::`vftable';
  this->m_pos.m_x = 0.0;
  this->m_pos.m_y = 0.0;
  this->m_pos.m_z = 0.0;
  this->m_rotSpaceToWorld = bfx::IDENTITY_QUAT;
  this->m_rotWorldToSpace = bfx::IDENTITY_QUAT;
  this->m_userData = 0;
  memcpy(Dst: &this->m_matSpaceToWorld, Src: &bfx::IDENTITY, Size: sizeof(this->m_matSpaceToWorld));
  memcpy(Dst: &this->m_matWorldToSpace, Src: &bfx::IDENTITY, Size: sizeof(this->m_matWorldToSpace));
  p_m_components = &this->m_components;
  v4 = bfx::MEM_BFXSYSTEM;
  this->m_components.m_data = nullptr;
  this->m_components.m_size = 0;
  this->m_components.m_cap = 0;
  this->m_components.m_tag = v4;
  if ( this->m_components.m_cap < 8 )
    bfx::Array<bfx::Edge *>::expand_cap(this: &this->m_components, size: 8);
  this->m_components.m_size = 8;
  *p_m_components->m_data = nullptr;
  *((_DWORD *)p_m_components->m_data + 1) = 0;
  *((_DWORD *)p_m_components->m_data + 2) = 0;
  *((_DWORD *)p_m_components->m_data + 3) = 0;
  *((_DWORD *)p_m_components->m_data + 4) = 0;
  *((_DWORD *)p_m_components->m_data + 5) = 0;
  *((_DWORD *)p_m_components->m_data + 6) = 0;
  *((_DWORD *)p_m_components->m_data + 7) = 0;
  bfx::ComponentManager::ComponentsInitSpace(this: bfx::g_pCurInstance->m_pComponentManager, pSpace: this);
  return this;
}


// ========================================================================
// __unwind$74478_0
// EA  : 0x8324F9A8
// RVA : 0x0124F9A8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

void _unwind_74478_0()
{
  int v0; // r12

  bfx::HandleTargetBase::~HandleTargetBase(this: *(bfx::HandleTargetBase **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$74479_0
// EA  : 0x8324F9D0
// RVA : 0x0124F9D0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

void _unwind_74479_0()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 188));
}


// ========================================================================
// ??1Space@bfx@@EAA@XZ
// EA  : 0x8324FA08
// RVA : 0x0124FA08
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

void __fastcall bfx::Space::~Space(bfx::Space *this)
{
  int i; // r29
  bfx::SpaceComponent *v3; // r3
  bfx::SpaceComponent **m_data; // r4

  this->__vftable = (bfx::Space_vtbl *)&bfx::Space::`vftable';
  for ( i = 7; i >= 0; --i )
  {
    v3 = this->m_components.m_data[i];
    if ( v3 != nullptr )
    {
      ((void (__fastcall *)(bfx::SpaceComponent *, int))v3->dtr_SpaceComponent)(a1: v3, a2: 1);
      this->m_components.m_data[i] = nullptr;
    }
  }
  m_data = this->m_components.m_data;
  this->m_components.m_size = 0;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_components.m_data = nullptr;
  }
  this->m_components.m_cap = 0;
  bfx::HandleTargetBase::~HandleTargetBase(this);
}


// ========================================================================
// __unwind$74577
// EA  : 0x8324FAA0
// RVA : 0x0124FAA0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

void _unwind_74577()
{
  int v0; // r12

  bfx::HandleTargetBase::~HandleTargetBase(this: *(bfx::HandleTargetBase **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$74578
// EA  : 0x8324FAC8
// RVA : 0x0124FAC8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

void _unwind_74578()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 188));
}


// ========================================================================
// ?Simulate@Space@bfx@@QAAXM@Z
// EA  : 0x8324FAF8
// RVA : 0x0124FAF8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

void __fastcall bfx::Space::Simulate(bfx::Space *this, double simTime)
{
  bfx::Array<bfx::SpaceComponent *> *p_m_components; // r30
  int v4; // r29
  int v5; // r31
  bfx::SpaceComponent *v6; // r3

  p_m_components = &this->m_components;
  v4 = 0;
  if ( this->m_components.m_size > 0 )
  {
    v5 = 0;
    do
    {
      v6 = p_m_components->m_data[v5];
      if ( v6 != nullptr )
        v6->Simulate(this: v6, a2: simTime);
      ++v4;
      ++v5;
    }
    while ( v4 < p_m_components->m_size );
  }
}


// ========================================================================
// ?EndOfFrame@Space@bfx@@QAAXM@Z
// EA  : 0x8324FB68
// RVA : 0x0124FB68
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

void __fastcall bfx::Space::EndOfFrame(bfx::Space *this, double simTime)
{
  bfx::Array<bfx::SpaceComponent *> *p_m_components; // r30
  int v4; // r29
  int v5; // r31
  bfx::SpaceComponent *v6; // r3

  p_m_components = &this->m_components;
  v4 = 0;
  if ( this->m_components.m_size > 0 )
  {
    v5 = 0;
    do
    {
      v6 = p_m_components->m_data[v5];
      if ( v6 != nullptr )
        v6->EndOfFrame(this: v6, a2: simTime);
      ++v4;
      ++v5;
    }
    while ( v4 < p_m_components->m_size );
  }
}


// ========================================================================
// ?Draw@Space@bfx@@QAAXPBVDrawCullParams@2@@Z
// EA  : 0x8324FBD8
// RVA : 0x0124FBD8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

void __fastcall bfx::Space::Draw(bfx::Space *this, const bfx::DrawCullParams *pDrawCullParams)
{
  int v2; // r29
  const bfx::DrawCullParams *v4; // r5
  int v5; // r31
  bfx::SpaceComponent *v6; // r3
  bfx::DrawCullData v7; // [sp+50h] [-70h] BYREF

  v2 = 0;
  v4 = pDrawCullParams;
  v7.m_useCulling = false;
  if ( pDrawCullParams != nullptr )
    bfx::DrawCullData::Build(this: &v7, pSpace: this, drawCullParams: pDrawCullParams);
  if ( this->m_components.m_size > 0 )
  {
    v5 = 0;
    do
    {
      v6 = this->m_components.m_data[v5];
      if ( v6 != nullptr )
        ((void (__fastcall *)(bfx::SpaceComponent *, bfx::DrawCullData *, const bfx::DrawCullParams *))v6->Draw)(
          a1: v6,
          a2: &v7,
          a3: v4);
      ++v2;
      ++v5;
    }
    while ( v2 < this->m_components.m_size );
  }
  if ( bfx::g_pCurInstance->m_pDebugOptions->m_drawSpaceAxes )
    bfx::DrawAxesWithArrows(pSpace: (bfx::Vector3 *)this, pos: &bfx::ZERO_VEC);
}


// ========================================================================
// ?Simulate@SpaceManager@bfx@@QAAXM@Z
// EA  : 0x8324FC88
// RVA : 0x0124FC88
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

void __fastcall bfx::SpaceManager::Simulate(bfx::SpaceManager *this, double simTime)
{
  int v4; // r30
  int v5; // r31
  bfx::Space *v6; // r28

  if ( !this->m_disableGlobalSpaceSimulation )
  {
    v4 = 0;
    if ( this->m_spaces.m_size > 0 )
    {
      v5 = 0;
      do
      {
        v6 = this->m_spaces.m_data[v5];
        bfx::Space::Simulate(this: v6, simTime);
        bfx::Space::EndOfFrame(this: v6, simTime);
        ++v4;
        ++v5;
      }
      while ( v4 < this->m_spaces.m_size );
    }
  }
}


// ========================================================================
// ?Draw@SpaceManager@bfx@@QAAXPBVDrawCullParams@2@@Z
// EA  : 0x8324FD00
// RVA : 0x0124FD00
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

void __fastcall bfx::SpaceManager::Draw(bfx::SpaceManager *this, const bfx::DrawCullParams *pDrawCullParams)
{
  int v4; // r30
  int v5; // r31

  if ( !this->m_disableGlobalSpaceDrawing )
  {
    v4 = 0;
    if ( this->m_spaces.m_size > 0 )
    {
      v5 = 0;
      do
      {
        bfx::Space::Draw(this: this->m_spaces.m_data[v5], pDrawCullParams);
        ++v4;
        ++v5;
      }
      while ( v4 < this->m_spaces.m_size );
    }
  }
}


// ========================================================================
// ?CreateSpace@SpaceManager@bfx@@QAAPAVSpace@2@I@Z
// EA  : 0x8324FD68
// RVA : 0x0124FD68
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

bfx::Space *__fastcall bfx::SpaceManager::CreateSpace(bfx::SpaceManager *this, unsigned int spaceID)
{
  bfx::Space *v4; // r3
  bfx::Space *v5; // r30
  bfx::Space *v7; // [sp+50h] [-30h] BYREF

  v4 = (bfx::Space *)bfx::MemoryManager::Malloc(
                       this: bfx::g_pCurInstance->m_pMemoryManager,
                       size: 0xCCu,
                       tag: bfx::MEM_BFXSYSTEM);
  v7 = v4;
  if ( v4 != nullptr )
    v5 = bfx::Space::Space(this: v4, spaceID);
  else
    v5 = nullptr;
  v7 = v5;
  bfx::Array<bfx::Portal *>::push_back(this: &this->m_spaces, val: &v7);
  return v5;
}


// ========================================================================
// __unwind$75051
// EA  : 0x8324FDD8
// RVA : 0x0124FDD8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

void _unwind_75051()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 128 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?DestroySpace@bfx@@YAXAAVSpaceHandle@1@@Z
// EA  : 0x8324FE70
// RVA : 0x0124FE70
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

void __fastcall bfx::DestroySpace(bfx::SpaceHandle *spaceHandle)
{
  _RTL_CRITICAL_SECTION *p_m_criticalSection; // r29
  bfx::Space *m_pProxy; // r11
  bfx::Space *v4; // r30
  bfx::Space *v5; // [sp+50h] [-30h] BYREF
  bfx::APICriticalSection *m_pGlobalCS; // [sp+54h] [-2Ch]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  p_m_criticalSection = &m_pGlobalCS->m_criticalSection;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  m_pProxy = (bfx::Space *)spaceHandle->m_pProxy;
  if ( spaceHandle->m_pProxy != nullptr )
  {
    v4 = (bfx::Space *)m_pProxy->__vftable;
    v5 = m_pProxy;
  }
  else
  {
    v4 = nullptr;
  }
  if ( v4 != nullptr )
  {
    bfx::LogDestroySpace(spaceID: v4->m_spaceID);
    v5 = v4;
    bfx::Array<bfx::Path3D *>::remove(this: &bfx::g_pCurInstance->m_pSpaceManager->m_spaces, val: &v5);
    ((void (__fastcall *)(bfx::Space *, int))v4->dtr_HandleTargetBase)(a1: v4, a2: 1);
    if ( p_m_criticalSection == nullptr )
      return;
  }
  else if ( m_pGlobalCS == nullptr )
  {
    return;
  }
  RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
}


// ========================================================================
// __unwind$75178
// EA  : 0x8324FF28
// RVA : 0x0124FF28
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

void _unwind_75178()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 84));
}


// ========================================================================
// ?DisableDefaultSpace@SpaceManager@bfx@@QAAXXZ
// EA  : 0x8324FF90
// RVA : 0x0124FF90
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

void __fastcall bfx::SpaceManager::DisableDefaultSpace(bfx::SpaceManager *this)
{
  bfx::Space *v2; // r30
  bfx::Space *m_pDefaultSpace; // [sp+50h] [-20h] BYREF

  bfx::VolumeHandle::Release(this: &this->m_defaultSpaceHandle);
  m_pDefaultSpace = this->m_pDefaultSpace;
  v2 = m_pDefaultSpace;
  if ( m_pDefaultSpace != nullptr )
  {
    bfx::Array<bfx::Path3D *>::remove(this: &this->m_spaces, val: &m_pDefaultSpace);
    ((void (__fastcall *)(bfx::Space *, int))v2->dtr_HandleTargetBase)(a1: v2, a2: 1);
  }
  this->m_pDefaultSpace = nullptr;
  this->m_isDefaultSpaceDisabled = true;
}


// ========================================================================
// ??0SpaceHandleImpl@bfx@@QAA@PAVSpace@1@@Z
// EA  : 0x83250018
// RVA : 0x01250018
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

bfx::SpaceHandleImpl *__fastcall bfx::SpaceHandleImpl::SpaceHandleImpl(bfx::SpaceHandleImpl *this, bfx::Space *pSpace)
{
  if ( this != nullptr )
  {
    this->m_pProxy = nullptr;
    bfx::Handle<bfx::LinkBase>::Handle<bfx::LinkBase>((bfx::Handle<bfx::Space> *)this, pTarget: pSpace);
  }
  return this;
}


// ========================================================================
// __unwind$75501
// EA  : 0x83250078
// RVA : 0x01250078
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

void _unwind_75501()
{
  int v0; // r12

  bfx::LinkReservationRCPtr::~LinkReservationRCPtr(this: *(bfx::SpaceHandle **)(v0 - 112 + 132));
}


// ========================================================================
// __unwind$75502
// EA  : 0x832500A0
// RVA : 0x012500A0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

void _unwind_75502()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 112 + 80));
}


// ========================================================================
// ?CreateSpaceHandle@bfx@@YA?AVSpaceHandle@1@PAVSpace@1@@Z
// EA  : 0x832500D8
// RVA : 0x012500D8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

bfx::SpaceHandle *__fastcall bfx::CreateSpaceHandle(bfx::SpaceHandle *result, bfx::Space *pSpace)
{
  bfx::SpaceHandleImpl *v3; // r3
  bfx::SpaceHandle v5; // [sp+50h] [-20h] BYREF
  int v6; // [sp+54h] [-1Ch]

  v6 = 0;
  v3 = bfx::SpaceHandleImpl::SpaceHandleImpl(this: (bfx::SpaceHandleImpl *)&v5, pSpace);
  bfx::MultiPathRCPtr::MultiPathRCPtr(this: result, rhs: v3);
  v6 = 1;
  bfx::LinkReservationRCPtr::~LinkReservationRCPtr(this: &v5);
  return result;
}


// ========================================================================
// __unwind$75551
// EA  : 0x83250140
// RVA : 0x01250140
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

void _unwind_75551()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 112;
  if ( (*(_DWORD *)(v0 - 112 + 84) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 84) &= ~1u;
    bfx::LinkReservationRCPtr::~LinkReservationRCPtr(this: *(bfx::SpaceHandle **)(v1 + 132));
  }
}


// ========================================================================
// ?CreateSpace@bfx@@YA?AVSpaceHandle@1@XZ
// EA  : 0x83250190
// RVA : 0x01250190
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

bfx::SpaceHandle *__fastcall bfx::CreateSpace(bfx::SpaceHandle *result)
{
  bfx::SystemInstance *v2; // r11
  bfx::SpaceManager *m_pSpaceManager; // r11
  unsigned int m_nextSpaceID; // r30
  bfx::Space *Space; // r3
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-40h]

  v2 = bfx::g_pCurInstance;
  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
  {
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    v2 = bfx::g_pCurInstance;
  }
  m_pSpaceManager = v2->m_pSpaceManager;
  m_nextSpaceID = m_pSpaceManager->m_nextSpaceID;
  m_pSpaceManager->m_nextSpaceID = m_nextSpaceID + 1;
  bfx::LogCreateSpace(spaceID: m_nextSpaceID);
  Space = bfx::SpaceManager::CreateSpace(this: bfx::g_pCurInstance->m_pSpaceManager, spaceID: m_nextSpaceID);
  bfx::CreateSpaceHandle(result, pSpace: Space);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return result;
}


// ========================================================================
// __unwind$75573
// EA  : 0x83250224
// RVA : 0x01250224
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

void _unwind_75573()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 144 + 80));
}


// ========================================================================
// ??0SpaceManager@bfx@@QAA@XZ
// EA  : 0x83250258
// RVA : 0x01250258
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

bfx::SpaceManager *__fastcall bfx::SpaceManager::SpaceManager(bfx::SpaceManager *this)
{
  bfx::bfxMemTag v2; // r10
  bfx::SpaceHandle *p_m_defaultSpaceHandle; // r29
  void *m_nextSpaceID; // r4
  bfx::Space *Space; // r3
  const bfx::Handle<bfx::Space> *SpaceHandle; // r3
  bfx::SpaceHandle v8[12]; // [sp+50h] [-30h] BYREF

  v2 = bfx::MEM_BFXSYSTEM;
  this->m_spaces.m_data = nullptr;
  this->m_spaces.m_size = 0;
  this->m_spaces.m_cap = 0;
  this->m_spaces.m_tag = v2;
  p_m_defaultSpaceHandle = &this->m_defaultSpaceHandle;
  this->m_disableGlobalSpaceSimulation = false;
  this->m_disableGlobalSpaceDrawing = false;
  this->m_nextSpaceID = 0;
  this->m_pDefaultSpace = nullptr;
  if ( this != (bfx::SpaceManager *)-28 )
    p_m_defaultSpaceHandle->m_pProxy = nullptr;
  this->m_isDefaultSpaceDisabled = false;
  if ( this != (bfx::SpaceManager *)-36 )
    this->m_invalidSpaceHandle.m_pProxy = nullptr;
  m_nextSpaceID = (void *)this->m_nextSpaceID;
  this->m_nextSpaceID = (unsigned int)m_nextSpaceID + 1;
  v8[0].m_pProxy = m_nextSpaceID;
  Space = bfx::SpaceManager::CreateSpace(this, spaceID: (unsigned int)m_nextSpaceID);
  this->m_pDefaultSpace = Space;
  SpaceHandle = (const bfx::Handle<bfx::Space> *)bfx::CreateSpaceHandle(result: v8, pSpace: Space);
  bfx::ObstacleHandle::operator=(this: p_m_defaultSpaceHandle, rhs: SpaceHandle);
  bfx::LinkReservationRCPtr::~LinkReservationRCPtr(this: v8);
  return this;
}


// ========================================================================
// __unwind$75626
// EA  : 0x83250308
// RVA : 0x01250308
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

void _unwind_75626()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: *(bfx::Array<bfx::SpaceComponent *> **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$75627
// EA  : 0x83250330
// RVA : 0x01250330
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

void _unwind_75627()
{
  int v0; // r12

  bfx::LinkReservationRCPtr::~LinkReservationRCPtr(this: (bfx::SpaceHandle *)(*(_DWORD *)(v0 - 128 + 148) + 28));
}


// ========================================================================
// __unwind$75628
// EA  : 0x8325035C
// RVA : 0x0125035C
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

void _unwind_75628()
{
  int v0; // r12

  bfx::LinkReservationRCPtr::~LinkReservationRCPtr(this: (bfx::SpaceHandle *)(*(_DWORD *)(v0 - 128 + 148) + 36));
}


// ========================================================================
// __unwind$75629
// EA  : 0x83250388
// RVA : 0x01250388
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxspace.cpp
// ========================================================================

void _unwind_75629()
{
  int v0; // r12

  bfx::LinkReservationRCPtr::~LinkReservationRCPtr(this: (bfx::SpaceHandle *)(v0 - 128 + 80));
}

