
// ========================================================================
// ??0CreateObstacleTask@bfx@@QAA@PAVHandleProxy@1@AAVSpaceHandle@1@ABVVector3@1@ABVQuaternion@1@2ABVObstacleDat@1@@Z
// EA  : 0x8324CC20
// RVA : 0x0124CC20
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannermcore.cpp
// ========================================================================

bfx::CreateObstacleTask *__fastcall bfx::CreateObstacleTask::CreateObstacleTask(
        bfx::CreateObstacleTask *this,
        bfx::HandleProxy *pProxy,
        bfx::SpaceHandle *spaceHandle,
        const bfx::Vector3 *pos,
        const bfx::Quaternion *rot,
        const bfx::Vector3 *boxDimensions,
        const bfx::ObstacleDat *obstacleDat)
{
  bfx::Vector3 *v13; // r10
  float *v14; // r11
  int v15; // ctr

  bfx::Task::Task(this, pProxy);
  this->__vftable = (bfx::CreateObstacleTask_vtbl *)&bfx::CreateObstacleTask::`vftable';
  bfx::MultiPathRCPtr::MultiPathRCPtr(this: &this->m_spaceHandle, rhs: spaceHandle);
  v13 = &this->m_boxDimensions + 1;
  v14 = (float *)(&obstacleDat[-1].m_obstacleName + 1);
  v15 = 8;
  this->m_pos = *pos;
  this->m_rot = *rot;
  this->m_boxDimensions = *boxDimensions;
  do
  {
    ++v14;
    v13 = (bfx::Vector3 *)((char *)v13 + 4);
    v13->m_x = *v14;
    --v15;
  }
  while ( v15 != 0 );
  return this;
}


// ========================================================================
// __unwind$76048
// EA  : 0x8324CCE0
// RVA : 0x0124CCE0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannermcore.cpp
// ========================================================================

void _unwind_76048()
{
  int v0; // r12

  bfx::Task::~Task(this: *(bfx::Task **)(v0 - 144 + 164));
}


// ========================================================================
// ?Process@CreateObstacleTask@bfx@@UAAXXZ
// EA  : 0x8324CD88
// RVA : 0x0124CD88
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannermcore.cpp
// ========================================================================

void __fastcall bfx::CreateObstacleTask::Process(bfx::CreateObstacleTask *this)
{
  double m_y; // fp13
  double m_x; // fp12
  bfx::ObstacleImpl *v4; // r3
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-40h]
  bfx::BoxExtents v6; // [sp+58h] [-38h] BYREF

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  m_y = this->m_boxDimensions.m_y;
  m_x = this->m_boxDimensions.m_x;
  v6.m_height = this->m_boxDimensions.m_z;
  v6.m_length = m_x;
  v6.m_width = m_y;
  v4 = bfx::CreateObstacleInternal(
         spaceHandle: &this->m_spaceHandle,
         pos: &this->m_pos,
         rot: &this->m_rot,
         boxExtents: &v6,
         obstacleDat: &this->m_obstacleDat);
  bfx::HandleProxy::ConnectToTarget(this: this->m_pProxy, pTarget: v4);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$76089
// EA  : 0x8324CE14
// RVA : 0x0124CE14
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannermcore.cpp
// ========================================================================

void _unwind_76089()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 144 + 80));
}


// ========================================================================
// ?DestroyObstacle@bfx@@YAXAAVObstacleHandle@1@@Z
// EA  : 0x8324CEA8
// RVA : 0x0124CEA8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannermcore.cpp
// ========================================================================

void __fastcall bfx::DestroyObstacle(bfx::ObstacleHandle *obstacleHandle)
{
  bfx::SystemInstance *v2; // r11
  bfx::ObstacleImpl **m_pProxy; // r30
  int v4; // r10
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  v2 = bfx::g_pCurInstance;
  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
  {
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    v2 = bfx::g_pCurInstance;
  }
  m_pProxy = (bfx::ObstacleImpl **)obstacleHandle->m_pProxy;
  if ( obstacleHandle->m_pProxy != nullptr )
  {
    v4 = (int)((_DWORD)m_pProxy[1] << 24) >> 28;
    if ( v4 == 2 )
    {
      bfx::DestroyObstacleInternal(pObstacle: *m_pProxy);
    }
    else if ( v4 == 1 )
    {
      v2->m_pSystemMCore->DeleteTaskForProxy(this: v2->m_pSystemMCore, a2: (bfx::HandleProxy *)obstacleHandle->m_pProxy);
      if ( m_pProxy != nullptr )
        m_pProxy[1] = (bfx::ObstacleImpl *)((unsigned int)m_pProxy[1] & 0xFFFFFF0F | 0x40);
    }
  }
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$76829
// EA  : 0x8324CF60
// RVA : 0x0124CF60
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannermcore.cpp
// ========================================================================

void _unwind_76829()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ??0MultiPathRCPtr@bfx@@QAA@ABV01@@Z
// EA  : 0x8324CF88
// RVA : 0x0124CF88
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannermcore.cpp
// ========================================================================

bfx::SpaceHandle *__fastcall bfx::MultiPathRCPtr::MultiPathRCPtr(bfx::SpaceHandle *this, const bfx::SpaceHandle *rhs)
{
  bfx::APICriticalSection *m_pGlobalCS; // r30
  _DWORD *m_pProxy; // r11
  bool v6; // cr58

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &bfx::g_pCurInstance->m_pGlobalCS->m_criticalSection);
  if ( this != nullptr )
  {
    m_pProxy = rhs->m_pProxy;
    v6 = rhs->m_pProxy == nullptr;
    this->m_pProxy = rhs->m_pProxy;
    if ( !v6 )
      m_pProxy[1] = (unsigned __int8)m_pProxy[1] | ((m_pProxy[1] & 0xFFFFFF00) + 256) & 0xFFFFFF00;
  }
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return this;
}


// ========================================================================
// ??4ObstacleHandle@bfx@@QAAAAV01@ABV01@@Z
// EA  : 0x8324D008
// RVA : 0x0124D008
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannermcore.cpp
// ========================================================================

bfx::SpaceHandle *__fastcall bfx::ObstacleHandle::operator=(bfx::SpaceHandle *this, const bfx::Handle<bfx::Space> *rhs)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::Handle<bfx::LinkReservation>::operator=((bfx::Handle<bfx::Space> *)this, rhs);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return this;
}


// ========================================================================
// __unwind$75093
// EA  : 0x8324D068
// RVA : 0x0124D068
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannermcore.cpp
// ========================================================================

void _unwind_75093()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ??0VolumeHandleImpl@bfx@@QAA@PAVVolume@1@@Z
// EA  : 0x8324D098
// RVA : 0x0124D098
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannermcore.cpp
// ========================================================================

bfx::VolumeHandleImpl *__fastcall bfx::VolumeHandleImpl::VolumeHandleImpl(
        bfx::VolumeHandleImpl *this,
        bfx::Space *pVolume)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  if ( this != nullptr )
    this->m_pProxy = nullptr;
  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  if ( this != nullptr )
    bfx::Handle<bfx::LinkBase>::Handle<bfx::LinkBase>((bfx::Handle<bfx::Space> *)this, pTarget: pVolume);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  return this;
}


// ========================================================================
// __unwind$85975
// EA  : 0x8324D11C
// RVA : 0x0124D11C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannermcore.cpp
// ========================================================================

void _unwind_85975()
{
  int v0; // r12

  bfx::ObstacleHandle::~ObstacleHandle(this: *(bfx::PolylinePath3DRCPtr **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$85976
// EA  : 0x8324D144
// RVA : 0x0124D144
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannermcore.cpp
// ========================================================================

void _unwind_85976()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// __unwind$85977
// EA  : 0x8324D16C
// RVA : 0x0124D16C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannermcore.cpp
// ========================================================================

void _unwind_85977()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 128 + 84));
}


// ========================================================================
// ?CreateObstacleAsync@bfx@@YA?AVObstacleHandle@1@AAVSpaceHandle@1@ABVVector3@1@ABVQuaternion@1@ABVBoxExtents@1@ABVObstacleDat@1@@Z
// EA  : 0x8324D1A8
// RVA : 0x0124D1A8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannermcore.cpp
// ========================================================================

bfx::SpaceHandle *__fastcall bfx::CreateObstacleAsync(
        bfx::SpaceHandle *result,
        bfx::SpaceHandle *space,
        const bfx::Vector3 *pos,
        const bfx::Quaternion *rot,
        const bfx::BoxExtents *boxExtents,
        const bfx::ObstacleDat *obstacleDat)
{
  bfx::SystemInstance *v9; // r11
  _RTL_CRITICAL_SECTION *p_m_criticalSection; // r22
  bfx::MemoryManager *m_pMemoryManager; // r3
  bool v15; // zf
  bfx::HandleProxy *v16; // r3
  char v17; // r11
  bfx::HandleProxy *v18; // r29
  double m_height; // fp0
  double m_width; // fp13
  bfx::MemoryManager *v21; // r3
  bfx::CreateObstacleTask *v22; // r3
  bfx::CreateObstacleTask *v23; // r4
  bfx::HandleProxy *v24; // r3
  bfx::HandleProxy *v25; // r3
  char v26; // r11
  bfx::HandleProxy *v27; // r30
  bfx::ObstacleImpl *ObstacleInternal; // r3
  bfx::HandleProxy *m_pProxy; // r3
  bfx::SpaceHandle v31; // [sp+50h] [-80h] BYREF
  bfx::APICriticalSection *m_pGlobalCS; // [sp+54h] [-7Ch]
  bfx::CreateObstacleTask *v33; // [sp+58h] [-78h]
  bfx::Vector3 v34; // [sp+60h] [-70h] BYREF

  v31.m_pProxy = nullptr;
  v9 = bfx::g_pCurInstance;
  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  p_m_criticalSection = &m_pGlobalCS->m_criticalSection;
  if ( m_pGlobalCS != nullptr )
  {
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    v9 = bfx::g_pCurInstance;
  }
  v15 = !v9->m_pSystemMCore->IsAsyncEnabled(this: v9->m_pSystemMCore);
  m_pMemoryManager = bfx::g_pCurInstance->m_pMemoryManager;
  if ( v15 )
  {
    v25 = (bfx::HandleProxy *)bfx::MemoryManager::Malloc(this: m_pMemoryManager, size: 8u, tag: bfx::MEM_BFXSYSTEM);
    if ( v25 != nullptr )
    {
      v26 = *((_BYTE *)v25 + 7);
      v27 = v25;
      v25->m_pTarget = nullptr;
      *((_DWORD *)v25 + 1) = v26 & 3;
    }
    else
    {
      v27 = nullptr;
    }
    ObstacleInternal = bfx::CreateObstacleInternal(spaceHandle: space, pos, rot, boxExtents, obstacleDat);
    bfx::HandleProxy::ConnectToTarget(this: v27, pTarget: ObstacleInternal);
    v31.m_pProxy = v27;
    if ( v27 != nullptr )
      *((_DWORD *)v27 + 1) = (unsigned __int8)*((_DWORD *)v27 + 1)
                           | ((*((_DWORD *)v27 + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
    bfx::MultiPathRCPtr::MultiPathRCPtr(this: result, rhs: &v31);
    m_pProxy = (bfx::HandleProxy *)v31.m_pProxy;
    v31.m_pProxy = (void *)1;
    if ( m_pProxy != nullptr )
      bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
  }
  else
  {
    v16 = (bfx::HandleProxy *)bfx::MemoryManager::Malloc(this: m_pMemoryManager, size: 8u, tag: bfx::MEM_BFXSYSTEM);
    if ( v16 != nullptr )
    {
      v17 = *((_BYTE *)v16 + 7);
      v18 = v16;
      v16->m_pTarget = nullptr;
      *((_DWORD *)v16 + 1) = v17 & 3;
    }
    else
    {
      v18 = nullptr;
    }
    m_height = boxExtents->m_height;
    m_width = boxExtents->m_width;
    v34.m_x = boxExtents->m_length;
    v34.m_y = m_width;
    v21 = bfx::g_pCurInstance->m_pMemoryManager;
    v34.m_z = m_height;
    v22 = (bfx::CreateObstacleTask *)bfx::MemoryManager::Malloc(this: v21, size: 0x58u, tag: bfx::MEM_BFXPLANNER);
    v33 = v22;
    if ( v22 != nullptr )
      v23 = bfx::CreateObstacleTask::CreateObstacleTask(
              this: v22,
              pProxy: v18,
              spaceHandle: space,
              pos,
              rot,
              boxDimensions: &v34,
              obstacleDat);
    else
      v23 = nullptr;
    bfx::g_pCurInstance->m_pSystemMCore->AddTask(this: bfx::g_pCurInstance->m_pSystemMCore, a2: v23);
    v31.m_pProxy = v18;
    if ( v18 != nullptr )
      *((_DWORD *)v18 + 1) = (unsigned __int8)*((_DWORD *)v18 + 1)
                           | ((*((_DWORD *)v18 + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
    bfx::MultiPathRCPtr::MultiPathRCPtr(this: result, rhs: &v31);
    v24 = (bfx::HandleProxy *)v31.m_pProxy;
    v31.m_pProxy = (void *)1;
    if ( v24 != nullptr )
      bfx::HandleProxy::RemRefToHandleProxy(this: v24);
  }
  if ( p_m_criticalSection != nullptr )
    RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
  return result;
}


// ========================================================================
// __unwind$78321
// EA  : 0x8324D3CC
// RVA : 0x0124D3CC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannermcore.cpp
// ========================================================================

void _unwind_78321()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 208 + 84));
}


// ========================================================================
// __unwind$78323
// EA  : 0x8324D3F4
// RVA : 0x0124D3F4
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannermcore.cpp
// ========================================================================

void _unwind_78323()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 208 + 88), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// __unwind$78325
// EA  : 0x8324D420
// RVA : 0x0124D420
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannermcore.cpp
// ========================================================================

void _unwind_78325()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 208;
  if ( (*(_DWORD *)(v0 - 208 + 80) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 80) &= ~1u;
    bfx::ObstacleHandle::~ObstacleHandle(this: *(bfx::PolylinePath3DRCPtr **)(v1 + 228));
  }
}


// ========================================================================
// ?CreateVolumeHandle@bfx@@YA?AVVolumeHandle@1@PAVVolume@1@@Z
// EA  : 0x8324D470
// RVA : 0x0124D470
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannermcore.cpp
// ========================================================================

bfx::SpaceHandle *__fastcall bfx::CreateVolumeHandle(bfx::SpaceHandle *result, bfx::Space *pVolume)
{
  bfx::VolumeHandleImpl *v3; // r3
  bfx::PolylinePath3DRCPtr v5; // [sp+50h] [-20h] BYREF
  int v6; // [sp+54h] [-1Ch]

  v6 = 0;
  v3 = bfx::VolumeHandleImpl::VolumeHandleImpl(this: (bfx::VolumeHandleImpl *)&v5, pVolume);
  bfx::MultiPathRCPtr::MultiPathRCPtr(this: result, rhs: (const bfx::SpaceHandle *)v3);
  v6 = 1;
  bfx::ObstacleHandle::~ObstacleHandle(this: &v5);
  return result;
}


// ========================================================================
// __unwind$87188
// EA  : 0x8324D4D8
// RVA : 0x0124D4D8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannermcore.cpp
// ========================================================================

void _unwind_87188()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 112;
  if ( (*(_DWORD *)(v0 - 112 + 84) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 84) &= ~1u;
    bfx::ObstacleHandle::~ObstacleHandle(this: *(bfx::PolylinePath3DRCPtr **)(v1 + 132));
  }
}

