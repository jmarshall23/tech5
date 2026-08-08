
// ========================================================================
// ?SetGlobalDebugFlag@bfx@@YAXW4Mover3DDebugFlag@1@_N@Z
// EA  : 0x83258A40
// RVA : 0x01258A40
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dsystem.cpp
// ========================================================================

void __fastcall bfx::SetGlobalDebugFlag(unsigned int flag, bool enable)
{
  bfx::InstanceComponent_vtbl *v2; // r11

  v2 = bfx::g_pCurInstance->m_pComponentManager->m_components[5][3].__vftable;
  if ( flag != 0 )
  {
    if ( flag == 1 )
    {
      BYTE1(v2->dtr_InstanceComponent) = enable;
    }
    else if ( flag < 3 )
    {
      BYTE2(v2->dtr_InstanceComponent) = enable;
    }
  }
  else
  {
    HIBYTE(v2->dtr_InstanceComponent) = enable;
  }
}


// ========================================================================
// ??0Movement3DInstance@bfx@@QAA@XZ
// EA  : 0x83258A88
// RVA : 0x01258A88
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dsystem.cpp
// ========================================================================

bfx::Movement3DInstance *__fastcall bfx::Movement3DInstance::Movement3DInstance(bfx::Movement3DInstance *this)
{
  bfx::Mover3DDebugOptions *v2; // r3
  bfx::Mover3DDebugOptions *v3; // r11

  this->m_nextMoverID = 0;
  this->__vftable = (bfx::Movement3DInstance_vtbl *)&bfx::Movement3DInstance::`vftable';
  this->m_nextRepulsorID = 0;
  this->m_pDebugOptions = nullptr;
  this->m_pMover3DReplayManager = nullptr;
  v2 = (bfx::Mover3DDebugOptions *)bfx::MemoryManager::Malloc(
                                     this: bfx::g_pCurInstance->m_pMemoryManager,
                                     size: 3u,
                                     tag: bfx::MEM_BFXSYSTEM);
  if ( v2 != nullptr )
  {
    v2->m_drawMover3DShapes = false;
    v3 = v2;
    v2->m_drawMover3DGoals = false;
    v2->m_drawRepulsors3D = false;
  }
  else
  {
    v3 = nullptr;
  }
  this->m_pDebugOptions = v3;
  return this;
}


// ========================================================================
// __unwind$72206
// EA  : 0x83258B0C
// RVA : 0x01258B0C
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dsystem.cpp
// ========================================================================

void _unwind_72206()
{
  int v0; // r12

  bfx::InstanceComponent::~InstanceComponent(this: *(bfx::InstanceComponent **)(v0 - 112 + 132));
}


// ========================================================================
// ??1Movement3DInstance@bfx@@UAA@XZ
// EA  : 0x83258B40
// RVA : 0x01258B40
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dsystem.cpp
// ========================================================================

void __fastcall bfx::Movement3DInstance::~Movement3DInstance(bfx::Movement3DInstance *this)
{
  bfx::Mover3DDebugOptions *m_pDebugOptions; // r4

  this->__vftable = (bfx::Movement3DInstance_vtbl *)&bfx::Movement3DInstance::`vftable';
  m_pDebugOptions = this->m_pDebugOptions;
  if ( m_pDebugOptions != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pDebugOptions);
    this->m_pDebugOptions = nullptr;
  }
  this->__vftable = (bfx::Movement3DInstance_vtbl *)&bfx::InstanceComponent::`vftable';
}


// ========================================================================
// __unwind$72238
// EA  : 0x83258BB8
// RVA : 0x01258BB8
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dsystem.cpp
// ========================================================================

void _unwind_72238()
{
  int v0; // r12

  bfx::InstanceComponent::~InstanceComponent(this: *(bfx::InstanceComponent **)(v0 - 112 + 132));
}


// ========================================================================
// ?Start@Movement3DInstance@bfx@@UAAXXZ
// EA  : 0x83258BE0
// RVA : 0x01258BE0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dsystem.cpp
// ========================================================================

void __fastcall bfx::Movement3DInstance::Start(bfx::Movement3DInstance *this)
{
  this->m_pMover3DReplayManager = bfx::CreateMover3DReplayer(pReplayPlayer: bfx::g_pCurInstance->m_pReplayPlayer);
  this->m_nextRepulsorID = 0;
}


// ========================================================================
// ?Stop@Movement3DInstance@bfx@@UAAXXZ
// EA  : 0x83258C28
// RVA : 0x01258C28
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dsystem.cpp
// ========================================================================

void __fastcall bfx::Movement3DInstance::Stop(bfx::Movement3DInstance *this)
{
  bfx::DestroyMover3DReplayer(pPlannerReplayManager: (bfx::PlannerReplayManager *)this->m_pMover3DReplayManager);
  this->m_pMover3DReplayManager = nullptr;
}


// ========================================================================
// ?RegisterMover3DSystem@bfx@@YAXXZ
// EA  : 0x83258C68
// RVA : 0x01258C68
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dsystem.cpp
// ========================================================================

void __fastcall bfx::RegisterMover3DSystem(bfx *this)
{
  bfx::SystemInstance *v1; // r11
  bfx::Movement3DInstance *v2; // r3
  bfx::Movement3DInstance *v3; // r5
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  v1 = bfx::g_pCurInstance;
  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
  {
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    v1 = bfx::g_pCurInstance;
  }
  v2 = (bfx::Movement3DInstance *)bfx::MemoryManager::Malloc(
                                    this: v1->m_pMemoryManager,
                                    size: 0x14u,
                                    tag: bfx::MEM_BFXMOVER3D);
  if ( v2 != nullptr )
    v3 = bfx::Movement3DInstance::Movement3DInstance(this: v2);
  else
    v3 = nullptr;
  bfx::ComponentManager::RegisterComponent(
    this: bfx::g_pCurInstance->m_pComponentManager,
    id: COMPONENTID_VOLUME_MOVER,
    pComponent: v3);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$72276
// EA  : 0x83258CF4
// RVA : 0x01258CF4
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dsystem.cpp
// ========================================================================

void _unwind_72276()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// __unwind$72277
// EA  : 0x83258D1C
// RVA : 0x01258D1C
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dsystem.cpp
// ========================================================================

void _unwind_72277()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 128 + 84), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?GetMover3DSpaceComponent@bfx@@YAPAVMover3DSpaceComponent@1@PAVSpace@1@@Z
// EA  : 0x83258D48
// RVA : 0x01258D48
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dsystem.cpp
// ========================================================================

bfx::Mover3DSpaceComponent *__fastcall bfx::GetMover3DSpaceComponent(bfx::Space *pSpace)
{
  return *((bfx::Mover3DSpaceComponent **)pSpace->m_components.m_data + 5);
}


// ========================================================================
// ??0Mover3DSpaceComponent@bfx@@QAA@PAVSpace@1@@Z
// EA  : 0x83258DC0
// RVA : 0x01258DC0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dsystem.cpp
// ========================================================================

bfx::Mover3DSpaceComponent *__fastcall bfx::Mover3DSpaceComponent::Mover3DSpaceComponent(
        bfx::Mover3DSpaceComponent *this,
        bfx::Space *pSpace)
{
  bfx::Repulsor3DCatalog *v3; // r3
  bfx::Repulsor3DCatalog *v4; // r3

  this->m_pSpace = pSpace;
  this->__vftable = (bfx::Mover3DSpaceComponent_vtbl *)&bfx::Mover3DSpaceComponent::`vftable';
  this->m_movers.m_tag = bfx::MEM_BFXMOVER3D;
  this->m_movers.m_data = nullptr;
  this->m_movers.m_size = 0;
  this->m_movers.m_cap = 0;
  this->m_simTimePending = 0.0;
  v3 = (bfx::Repulsor3DCatalog *)bfx::MemoryManager::Malloc(
                                   this: bfx::g_pCurInstance->m_pMemoryManager,
                                   size: 8u,
                                   tag: bfx::MEM_BFXMOVER3D);
  if ( v3 != nullptr )
    v4 = bfx::Repulsor3DCatalog::Repulsor3DCatalog(this: v3);
  else
    v4 = nullptr;
  this->m_pRepulsorCatalog = v4;
  return this;
}


// ========================================================================
// __unwind$72496
// EA  : 0x83258E58
// RVA : 0x01258E58
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dsystem.cpp
// ========================================================================

void _unwind_72496()
{
  int v0; // r12

  bfx::SpaceComponent::~SpaceComponent(this: *(bfx::SpaceComponent **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$72497
// EA  : 0x83258E80
// RVA : 0x01258E80
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dsystem.cpp
// ========================================================================

void _unwind_72497()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 8));
}


// ========================================================================
// __unwind$72498
// EA  : 0x83258EAC
// RVA : 0x01258EAC
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dsystem.cpp
// ========================================================================

void _unwind_72498()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 128 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ??1Mover3DSpaceComponent@bfx@@UAA@XZ
// EA  : 0x83258EE0
// RVA : 0x01258EE0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dsystem.cpp
// ========================================================================

void __fastcall bfx::Mover3DSpaceComponent::~Mover3DSpaceComponent(bfx::Mover3DSpaceComponent *this)
{
  bfx::Array<bfx::Mover3DBase *> *p_m_movers; // r30
  int m_size; // r11
  bfx::Mover3DBase *v4; // r3
  bfx::Repulsor3DCatalog *m_pRepulsorCatalog; // r30
  bfx::Mover3DBase **m_data; // r4

  this->__vftable = (bfx::Mover3DSpaceComponent_vtbl *)&bfx::Mover3DSpaceComponent::`vftable';
  if ( this->m_movers.m_size != 0 )
  {
    p_m_movers = &this->m_movers;
    do
    {
      m_size = p_m_movers->m_size;
      v4 = p_m_movers->m_data[m_size - 1];
      p_m_movers->m_size = m_size - 1;
      if ( v4 != nullptr )
        ((void (__fastcall *)(bfx::Mover3DBase *, int))v4->dtr_Mover3DBase)(a1: v4, a2: 1);
    }
    while ( this->m_movers.m_size != 0 );
  }
  m_pRepulsorCatalog = this->m_pRepulsorCatalog;
  if ( m_pRepulsorCatalog != nullptr )
  {
    bfx::Repulsor3DCatalog::~Repulsor3DCatalog(this: (bfx::RepulsorCatalog *)this->m_pRepulsorCatalog);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pRepulsorCatalog);
  }
  this->m_pRepulsorCatalog = nullptr;
  this->m_pSpace = nullptr;
  m_data = this->m_movers.m_data;
  this->m_movers.m_size = 0;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_movers.m_data = nullptr;
  }
  this->m_movers.m_cap = 0;
  this->__vftable = (bfx::Mover3DSpaceComponent_vtbl *)&bfx::SpaceComponent::`vftable';
}


// ========================================================================
// __unwind$72547
// EA  : 0x83258FCC
// RVA : 0x01258FCC
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dsystem.cpp
// ========================================================================

void _unwind_72547()
{
  int v0; // r12

  bfx::SpaceComponent::~SpaceComponent(this: *(bfx::SpaceComponent **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$72548
// EA  : 0x83258FF4
// RVA : 0x01258FF4
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dsystem.cpp
// ========================================================================

void _unwind_72548()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 8));
}


// ========================================================================
// ?Simulate@Mover3DSpaceComponent@bfx@@UAAXM@Z
// EA  : 0x83259020
// RVA : 0x01259020
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dsystem.cpp
// ========================================================================

void __fastcall bfx::Mover3DSpaceComponent::Simulate(bfx::Mover3DSpaceComponent *this, double simTime)
{
  double v2; // fp13
  bfx::Array<bfx::Mover3DBase *> *p_m_movers; // r31
  int v6; // r30
  int v8; // r29
  int v9; // r29
  int v10; // r30
  double v11; // fp13

  v2 = (float)((float)simTime + this->m_simTimePending);
  this->m_simTimePending = (float)simTime + this->m_simTimePending;
  if ( v2 >= 0.016666668 )
  {
    p_m_movers = &this->m_movers;
    do
    {
      _FP13 = (float)(this->m_simTimePending - (float)0.050000001);
      v6 = 0;
      __asm { fsel      f31, f13, f30, f0 }
      if ( p_m_movers->m_size > 0 )
      {
        v8 = 0;
        do
        {
          p_m_movers->m_data[v8]->CalcAcc(this: p_m_movers->m_data[v8], a2: _FP31);
          ++v6;
          ++v8;
        }
        while ( v6 < p_m_movers->m_size );
      }
      v9 = 0;
      if ( p_m_movers->m_size > 0 )
      {
        v10 = 0;
        do
        {
          p_m_movers->m_data[v10]->UpdateState(this: p_m_movers->m_data[v10], a2: _FP31);
          ++v9;
          ++v10;
        }
        while ( v9 < p_m_movers->m_size );
      }
      v11 = (float)(this->m_simTimePending - (float)_FP31);
      this->m_simTimePending = this->m_simTimePending - (float)_FP31;
    }
    while ( v11 >= 0.016666668 );
  }
}


// ========================================================================
// ?Draw@Mover3DSpaceComponent@bfx@@UAAXABVDrawCullData@2@@Z
// EA  : 0x83259128
// RVA : 0x01259128
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dsystem.cpp
// ========================================================================

void __fastcall bfx::Mover3DSpaceComponent::Draw(bfx::Mover3DSpaceComponent *this, const bfx::DrawCullData *__formal)
{
  bfx::Array<bfx::Mover3DBase *> *p_m_movers; // r29
  int v4; // r31
  int v5; // r30

  p_m_movers = &this->m_movers;
  v4 = 0;
  if ( this->m_movers.m_size > 0 )
  {
    v5 = 0;
    do
    {
      p_m_movers->m_data[v5]->Draw(this: p_m_movers->m_data[v5]);
      ++v4;
      ++v5;
    }
    while ( v4 < p_m_movers->m_size );
  }
  if ( BYTE2(bfx::g_pCurInstance->m_pComponentManager->m_components[5][3].dtr_InstanceComponent) != 0 )
    bfx::Repulsor3DCatalog::Draw(this: this->m_pRepulsorCatalog, pSpace: this->m_pSpace);
}


// ========================================================================
// ?AddMover@Mover3DSpaceComponent@bfx@@QAAXPAVMover3DBase@2@@Z
// EA  : 0x832591B0
// RVA : 0x012591B0
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dsystem.cpp
// ========================================================================

void __fastcall bfx::Mover3DSpaceComponent::AddMover(
        bfx::Mover3DSpaceComponent *this,
        bfx::Space *pMover,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        bfx::Space *a14)
{
  a14 = pMover;
  bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)&this->m_movers, val: &a14);
}


// ========================================================================
// ?SpaceInit@Movement3DInstance@bfx@@UAAXPAVSpace@2@@Z
// EA  : 0x832591E8
// RVA : 0x012591E8
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dsystem.cpp
// ========================================================================

void __fastcall bfx::Movement3DInstance::SpaceInit(bfx::Movement3DInstance *this, bfx::Space *pSpace)
{
  bfx::Mover3DSpaceComponent *v3; // r3
  bfx::Mover3DSpaceComponent *v4; // r3

  v3 = (bfx::Mover3DSpaceComponent *)bfx::MemoryManager::Malloc(
                                       this: bfx::g_pCurInstance->m_pMemoryManager,
                                       size: 0x20u,
                                       tag: bfx::MEM_BFXMOVER3D);
  if ( v3 != nullptr )
    v4 = bfx::Mover3DSpaceComponent::Mover3DSpaceComponent(this: v3, pSpace);
  else
    v4 = nullptr;
  *((_DWORD *)pSpace->m_components.m_data + 5) = v4;
}


// ========================================================================
// __unwind$72734
// EA  : 0x8325925C
// RVA : 0x0125925C
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dsystem.cpp
// ========================================================================

void _unwind_72734()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 112 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?RemoveMover@Mover3DSpaceComponent@bfx@@QAAXPAVMover3DBase@2@@Z
// EA  : 0x832592E8
// RVA : 0x012592E8
// PDB : w:\tech5\libs\navpower\src\bfxmover3d\bfxmover3dsystem.cpp
// ========================================================================

void __fastcall bfx::Mover3DSpaceComponent::RemoveMover(
        bfx::Mover3DSpaceComponent *this,
        bfx::Space *pMover,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        bfx::Space *a14)
{
  a14 = pMover;
  bfx::Array<bfx::Path3D *>::remove(this: (bfx::Array<bfx::Space *> *)&this->m_movers, val: &a14);
}

