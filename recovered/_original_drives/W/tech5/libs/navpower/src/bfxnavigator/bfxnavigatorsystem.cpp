
// ========================================================================
// ?SetGlobalDebugFlag@bfx@@YAXW4NavigatorDebugFlag@1@_N@Z
// EA  : 0x83254FB0
// RVA : 0x01254FB0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void __fastcall bfx::SetGlobalDebugFlag(unsigned int flag, bool enable)
{
  bfx::InstanceComponent *v2; // r11

  v2 = bfx::g_pCurInstance->m_pComponentManager->m_components[3];
  if ( flag <= 3 )
  {
    if ( flag == 1 )
    {
      BYTE1(v2[12].dtr_InstanceComponent) = enable;
    }
    else if ( flag == 2 )
    {
      BYTE2(v2[12].dtr_InstanceComponent) = enable;
    }
    else if ( flag != 0 )
    {
      LOBYTE(v2[12].dtr_InstanceComponent) = enable;
    }
    else
    {
      HIBYTE(v2[12].dtr_InstanceComponent) = enable;
    }
  }
}


// ========================================================================
// ?Simulate@NavigatorSpaceComponent@bfx@@UAAXM@Z
// EA  : 0x83255010
// RVA : 0x01255010
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void __fastcall bfx::NavigatorSpaceComponent::Simulate(bfx::NavigatorSpaceComponent *this, double simTime)
{
  bfx::RepulsorCatalog::Simulate(this: this->m_pRepulsorCatalog, simTime);
}


// ========================================================================
// ?EnableConstraintSolver@bfx@@YAX_N@Z
// EA  : 0x83255020
// RVA : 0x01255020
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void __fastcall bfx::EnableConstraintSolver(bool enable)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogEnableConstraintSolver(enable);
  HIBYTE(bfx::g_pCurInstance->m_pComponentManager->m_components[3][11].__vftable) = enable;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$81544
// EA  : 0x83255084
// RVA : 0x01255084
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void _unwind_81544()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?Start@NavigatorInstance@bfx@@UAAXXZ
// EA  : 0x832550B0
// RVA : 0x012550B0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void __fastcall bfx::NavigatorInstance::Start(bfx::NavigatorInstance *this)
{
  bfx::CreateNavigatorReplayer();
  this->m_nextProberID = 0;
  this->m_nextNavigatorID = 0;
  this->m_nextRepulsorID = 0;
  this->m_nextLinkReservationID = 0;
  this->m_numNavigatorsInAllSpaces = 0;
  this->m_numRepulsorsInAllSpaces = 0;
  this->m_enableConstraintSolver = false;
}


// ========================================================================
// ?Draw@NavigatorInstance@bfx@@UAAXXZ
// EA  : 0x83255100
// RVA : 0x01255100
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall bfx::NavigatorInstance::Draw(bfx::NavigatorInstance *this, int a2, __int64 a3, __int64 a4)
{
  __int64 v5; // r10
  __int64 v6; // r4
  __int64 v7; // r10
  __int64 v8; // r8
  __int64 v9; // r4
  __int64 v10; // r6
  __int64 v11; // r8
  __int64 v12; // r4
  __int64 v13; // r10
  __int64 v14; // r6
  __int64 v15; // r6
  __int64 v16; // r4
  __int64 v17; // r10
  __int64 v18; // r8
  int v19; // [sp+8h] [-58h]
  int v20; // [sp+8h] [-58h]
  int v21; // [sp+8h] [-58h]
  int v22; // [sp+8h] [-58h]
  int v23; // [sp+Ch] [-54h]
  int v24; // [sp+Ch] [-54h]
  int v25; // [sp+Ch] [-54h]
  int v26; // [sp+Ch] [-54h]
  int v27; // [sp+10h] [-50h]
  int v28; // [sp+10h] [-50h]
  int v29; // [sp+10h] [-50h]
  int v30; // [sp+10h] [-50h]
  int v31; // [sp+14h] [-4Ch]
  int v32; // [sp+14h] [-4Ch]
  int v33; // [sp+14h] [-4Ch]
  int v34; // [sp+14h] [-4Ch]

  LODWORD(v5) = bfx::g_pCurInstance->m_pDebugOptions;
  if ( *(_BYTE *)v5 != 0 )
  {
    HIDWORD(v6) = "\n--- Navigator Module ---\n";
    HIDWORD(v5) = *(unsigned __int8 *)v5;
    bfx::DrawString(fmt: v6, a2: a3, a3: a4, a4: v5, a5: v19, a6: v23, a7: v27, a8: v31);
    HIDWORD(v7) = this->m_enableConstraintSolver;
    LODWORD(v7) = &unk_82410000;
    LODWORD(v8) = HIDWORD(v7) - 1;
    HIDWORD(v9) = "constraint solver = %d\n";
    LODWORD(v9) = HIDWORD(v7) != 0;
    bfx::DrawString(fmt: v9, a2: v10, a3: v8, a4: v7, a5: v20, a6: v24, a7: v28, a8: v32);
    HIDWORD(v11) = &unk_82410000;
    LODWORD(v12) = this->m_numNavigatorsInAllSpaces;
    HIDWORD(v12) = "num navigators = %d\n";
    bfx::DrawString(fmt: v12, a2: v14, a3: v11, a4: v13, a5: v21, a6: v25, a7: v29, a8: v33);
    LODWORD(v15) = &unk_82410000;
    LODWORD(v16) = this->m_numRepulsorsInAllSpaces;
    HIDWORD(v16) = "num repulsors = %d\n";
    bfx::DrawString(fmt: v16, a2: v15, a3: v18, a4: v17, a5: v22, a6: v26, a7: v30, a8: v34);
  }
}


// ========================================================================
// ?GetNavigatorSpaceComponent@bfx@@YAPAVNavigatorSpaceComponent@1@PAVSpace@1@@Z
// EA  : 0x83255188
// RVA : 0x01255188
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

bfx::NavigatorSpaceComponent *__fastcall bfx::GetNavigatorSpaceComponent(bfx::Space *pSpace)
{
  return *((bfx::NavigatorSpaceComponent **)pSpace->m_components.m_data + 3);
}


// ========================================================================
// ?EndOfFrame@NavigatorSpaceComponent@bfx@@UAAXM@Z
// EA  : 0x83255198
// RVA : 0x01255198
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void __fastcall bfx::NavigatorSpaceComponent::EndOfFrame(bfx::NavigatorSpaceComponent *this, double simTime)
{
  bfx::Array<bfx::NavigatorImpl *> *p_m_navigators; // r29
  int v5; // r31
  int m_size; // r11
  int v7; // r30

  if ( simTime != 0.0 && HIBYTE(bfx::g_pCurInstance->m_pComponentManager->m_components[3][11].__vftable) != 0 )
    bfx::ResolveMoverOverlapConstraints(theList: &this->m_repulsors);
  p_m_navigators = &this->m_navigators;
  m_size = this->m_navigators.m_size;
  v5 = 0;
  if ( m_size > 0 )
  {
    v7 = 0;
    do
    {
      bfx::NavigatorImpl::EndOfFrameUpdate(this: p_m_navigators->m_data[v7], simTime);
      ++v5;
      ++v7;
    }
    while ( v5 < p_m_navigators->m_size );
  }
}


// ========================================================================
// ?Draw@NavigatorSpaceComponent@bfx@@UAAXABVDrawCullData@2@@Z
// EA  : 0x83255230
// RVA : 0x01255230
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void __fastcall bfx::NavigatorSpaceComponent::Draw(
        bfx::NavigatorSpaceComponent *this,
        const bfx::DrawCullData *__formal)
{
  bfx::Array<bfx::NavigatorImpl *> *p_m_navigators; // r29
  int v4; // r31
  int m_size; // r11
  int v6; // r30

  p_m_navigators = &this->m_navigators;
  bfx::RepulsorCatalog::Draw(this: this->m_pRepulsorCatalog, pSpace: this->m_pSpace);
  m_size = this->m_navigators.m_size;
  v4 = 0;
  if ( m_size > 0 )
  {
    v6 = 0;
    do
    {
      bfx::NavigatorImpl::Draw(this: p_m_navigators->m_data[v6]);
      ++v4;
      ++v6;
    }
    while ( v4 < p_m_navigators->m_size );
  }
}


// ========================================================================
// ?AddNavigator@NavigatorSpaceComponent@bfx@@QAAXPAVNavigatorImpl@2@@Z
// EA  : 0x83255290
// RVA : 0x01255290
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void __fastcall bfx::NavigatorSpaceComponent::AddNavigator(
        bfx::NavigatorSpaceComponent *this,
        bfx::Space *pNavigator,
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
  a14 = pNavigator;
  bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)&this->m_navigators, val: &a14);
  ++bfx::g_pCurInstance->m_pComponentManager->m_components[3][9].__vftable;
}


// ========================================================================
// ?AddRepulsor@NavigatorSpaceComponent@bfx@@QAAXPAVRepulsorImpl@2@@Z
// EA  : 0x832552D8
// RVA : 0x012552D8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void __fastcall bfx::NavigatorSpaceComponent::AddRepulsor(
        bfx::NavigatorSpaceComponent *this,
        bfx::Space *pRepulsor,
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
  a14 = pRepulsor;
  bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)&this->m_repulsors, val: &a14);
  ++bfx::g_pCurInstance->m_pComponentManager->m_components[3][10].__vftable;
}


// ========================================================================
// ??1NavigatorInstance@bfx@@UAA@XZ
// EA  : 0x83255328
// RVA : 0x01255328
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void __fastcall bfx::NavigatorInstance::~NavigatorInstance(bfx::NavigatorInstance *this)
{
  bfx::NavigatorDebugOptions *m_pDebugOptions; // r4
  bfx::Pair<unsigned int,bfx::LinkReservation *> *m_data; // r4
  bfx::Pair<unsigned int,bfx::Repulsor *> *v4; // r4
  bfx::Pair<unsigned int,bfx::Navigator *> *v5; // r4
  bfx::NavigatorSpaceComponent **v6; // r4

  this->__vftable = (bfx::NavigatorInstance_vtbl *)&bfx::NavigatorInstance::`vftable';
  m_pDebugOptions = this->m_pDebugOptions;
  if ( m_pDebugOptions != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pDebugOptions);
    this->m_pDebugOptions = nullptr;
  }
  m_data = this->m_replayLinkReservations.m_array.m_data;
  this->m_replayLinkReservations.m_array.m_size = 0;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_replayLinkReservations.m_array.m_data = nullptr;
  }
  this->m_replayLinkReservations.m_array.m_cap = 0;
  v4 = this->m_replayRepulsors.m_array.m_data;
  this->m_replayRepulsors.m_array.m_size = 0;
  if ( v4 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v4);
    this->m_replayRepulsors.m_array.m_data = nullptr;
  }
  this->m_replayRepulsors.m_array.m_cap = 0;
  v5 = this->m_replayNavigators.m_array.m_data;
  this->m_replayNavigators.m_array.m_size = 0;
  if ( v5 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v5);
    this->m_replayNavigators.m_array.m_data = nullptr;
  }
  this->m_replayNavigators.m_array.m_cap = 0;
  v6 = this->m_navigatorSpaceComponents.m_data;
  this->m_navigatorSpaceComponents.m_size = 0;
  if ( v6 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v6);
    this->m_navigatorSpaceComponents.m_data = nullptr;
  }
  this->m_navigatorSpaceComponents.m_cap = 0;
  this->__vftable = (bfx::NavigatorInstance_vtbl *)&bfx::InstanceComponent::`vftable';
}


// ========================================================================
// __unwind$82296
// EA  : 0x83255418
// RVA : 0x01255418
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void _unwind_82296()
{
  int v0; // r12

  bfx::InstanceComponent::~InstanceComponent(this: *(bfx::InstanceComponent **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$82297
// EA  : 0x83255440
// RVA : 0x01255440
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void _unwind_82297()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 4));
}


// ========================================================================
// __unwind$82298
// EA  : 0x8325546C
// RVA : 0x0125546C
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void _unwind_82298()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 52));
}


// ========================================================================
// __unwind$82299
// EA  : 0x83255498
// RVA : 0x01255498
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void _unwind_82299()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 68));
}


// ========================================================================
// __unwind$82300
// EA  : 0x832554C4
// RVA : 0x012554C4
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void _unwind_82300()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 84));
}


// ========================================================================
// ??0NavigatorSpaceComponent@bfx@@QAA@PAVSpace@1@@Z
// EA  : 0x832554F8
// RVA : 0x012554F8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

bfx::NavigatorSpaceComponent *__fastcall bfx::NavigatorSpaceComponent::NavigatorSpaceComponent(
        bfx::NavigatorSpaceComponent *this,
        bfx::Space *pSpace)
{
  bfx::bfxMemTag v3; // r11
  bfx::Space *v4; // r3
  bfx::RepulsorCatalog *v5; // r3
  bfx::Space *p_m_repulsors; // [sp+50h] [-30h] BYREF

  this->m_pSpace = pSpace;
  this->__vftable = (bfx::NavigatorSpaceComponent_vtbl *)&bfx::NavigatorSpaceComponent::`vftable';
  this->m_navigators.m_tag = bfx::MEM_BFXNAVIGATOR;
  this->m_navigators.m_data = nullptr;
  this->m_navigators.m_size = 0;
  this->m_navigators.m_cap = 0;
  v3 = bfx::MEM_BFXNAVIGATOR;
  this->m_repulsors.m_data = nullptr;
  this->m_repulsors.m_size = 0;
  this->m_repulsors.m_cap = 0;
  p_m_repulsors = (bfx::Space *)&this->m_repulsors;
  this->m_repulsors.m_tag = v3;
  this->m_pRepulsorCatalog = nullptr;
  v4 = (bfx::Space *)bfx::MemoryManager::Malloc(
                       this: bfx::g_pCurInstance->m_pMemoryManager,
                       size: 8u,
                       tag: bfx::MEM_BFXNAVIGATOR);
  p_m_repulsors = v4;
  if ( v4 != nullptr )
    v5 = bfx::RepulsorCatalog::RepulsorCatalog(this: (bfx::RepulsorCatalog *)v4);
  else
    v5 = nullptr;
  this->m_pRepulsorCatalog = v5;
  p_m_repulsors = (bfx::Space *)this;
  bfx::Array<bfx::Portal *>::push_back(
    this: (bfx::Array<bfx::Space *> *)&bfx::g_pCurInstance->m_pComponentManager->m_components[3][1],
    val: &p_m_repulsors);
  return this;
}


// ========================================================================
// __unwind$82650
// EA  : 0x832555C0
// RVA : 0x012555C0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void _unwind_82650()
{
  int v0; // r12

  bfx::SpaceComponent::~SpaceComponent(this: *(bfx::SpaceComponent **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$82651
// EA  : 0x832555E8
// RVA : 0x012555E8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void _unwind_82651()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 8));
}


// ========================================================================
// __unwind$82652
// EA  : 0x83255614
// RVA : 0x01255614
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void _unwind_82652()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 24));
}


// ========================================================================
// __unwind$82653
// EA  : 0x83255640
// RVA : 0x01255640
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void _unwind_82653()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 128 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?RemoveNavigator@NavigatorSpaceComponent@bfx@@QAAXPAVNavigatorImpl@2@@Z
// EA  : 0x83255670
// RVA : 0x01255670
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void __fastcall bfx::NavigatorSpaceComponent::RemoveNavigator(
        bfx::NavigatorSpaceComponent *this,
        bfx::Space *pNavigator,
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
  a14 = pNavigator;
  bfx::Array<bfx::Path3D *>::remove(this: (bfx::Array<bfx::Space *> *)&this->m_navigators, val: &a14);
  --bfx::g_pCurInstance->m_pComponentManager->m_components[3][9].__vftable;
}


// ========================================================================
// ?RemoveRepulsor@NavigatorSpaceComponent@bfx@@QAAXPAVRepulsorImpl@2@@Z
// EA  : 0x832556B8
// RVA : 0x012556B8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void __fastcall bfx::NavigatorSpaceComponent::RemoveRepulsor(
        bfx::NavigatorSpaceComponent *this,
        bfx::Space *pRepulsor,
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
  a14 = pRepulsor;
  bfx::Array<bfx::Path3D *>::remove(this: (bfx::Array<bfx::Space *> *)&this->m_repulsors, val: &a14);
  --bfx::g_pCurInstance->m_pComponentManager->m_components[3][10].__vftable;
}


// ========================================================================
// ??0NavigatorInstance@bfx@@QAA@XZ
// EA  : 0x83255708
// RVA : 0x01255708
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

bfx::NavigatorInstance *__fastcall bfx::NavigatorInstance::NavigatorInstance(bfx::NavigatorInstance *this)
{
  bfx::bfxMemTag v2; // r11
  bfx::bfxMemTag v3; // r11
  bfx::bfxMemTag v4; // r11
  bfx::bfxMemTag v5; // r11
  bfx::NavigatorDebugOptions *v6; // r3
  bfx::NavigatorDebugOptions *v7; // r11

  this->__vftable = (bfx::NavigatorInstance_vtbl *)&bfx::NavigatorInstance::`vftable';
  v2 = bfx::MEM_BFXNAVIGATOR;
  this->m_navigatorSpaceComponents.m_data = nullptr;
  this->m_navigatorSpaceComponents.m_size = 0;
  this->m_navigatorSpaceComponents.m_cap = 0;
  this->m_navigatorSpaceComponents.m_tag = v2;
  this->m_nextProberID = 0;
  this->m_nextNavigatorID = 0;
  this->m_nextRepulsorID = 0;
  this->m_nextLinkReservationID = 0;
  this->m_numNavigatorsInAllSpaces = 0;
  this->m_numRepulsorsInAllSpaces = 0;
  this->m_enableConstraintSolver = false;
  this->m_pDebugOptions = nullptr;
  v3 = bfx::MEM_REPLAY;
  this->m_replayNavigators.m_array.m_data = nullptr;
  this->m_replayNavigators.m_array.m_size = 0;
  this->m_replayNavigators.m_array.m_cap = 0;
  this->m_replayNavigators.m_array.m_tag = v3;
  v4 = bfx::MEM_REPLAY;
  this->m_replayRepulsors.m_array.m_data = nullptr;
  this->m_replayRepulsors.m_array.m_size = 0;
  this->m_replayRepulsors.m_array.m_cap = 0;
  this->m_replayRepulsors.m_array.m_tag = v4;
  v5 = bfx::MEM_REPLAY;
  this->m_replayLinkReservations.m_array.m_data = nullptr;
  this->m_replayLinkReservations.m_array.m_size = 0;
  this->m_replayLinkReservations.m_array.m_cap = 0;
  this->m_replayLinkReservations.m_array.m_tag = v5;
  v6 = (bfx::NavigatorDebugOptions *)bfx::MemoryManager::Malloc(
                                       this: bfx::g_pCurInstance->m_pMemoryManager,
                                       size: 4u,
                                       tag: bfx::MEM_BFXSYSTEM);
  if ( v6 != nullptr )
  {
    v6->m_drawNavigators = false;
    v7 = v6;
    v6->m_drawNavigatorGoals = false;
    v6->m_drawNavigatorDebugNames = false;
    v6->m_drawRepulsors = false;
  }
  else
  {
    v7 = nullptr;
  }
  this->m_pDebugOptions = v7;
  return this;
}


// ========================================================================
// __unwind$82751
// EA  : 0x83255818
// RVA : 0x01255818
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void _unwind_82751()
{
  int v0; // r12

  bfx::InstanceComponent::~InstanceComponent(this: *(bfx::InstanceComponent **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$82752
// EA  : 0x83255840
// RVA : 0x01255840
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void _unwind_82752()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 4));
}


// ========================================================================
// __unwind$82753
// EA  : 0x8325586C
// RVA : 0x0125586C
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void _unwind_82753()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 52));
}


// ========================================================================
// __unwind$82754
// EA  : 0x83255898
// RVA : 0x01255898
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void _unwind_82754()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 68));
}


// ========================================================================
// __unwind$82755
// EA  : 0x832558C4
// RVA : 0x012558C4
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void _unwind_82755()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 84));
}


// ========================================================================
// ?SpaceInit@NavigatorInstance@bfx@@UAAXPAVSpace@2@@Z
// EA  : 0x83255958
// RVA : 0x01255958
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void __fastcall bfx::NavigatorInstance::SpaceInit(bfx::NavigatorInstance *this, bfx::Space *pSpace)
{
  bfx::NavigatorSpaceComponent *v3; // r3
  bfx::NavigatorSpaceComponent *v4; // r3

  v3 = (bfx::NavigatorSpaceComponent *)bfx::MemoryManager::Malloc(
                                         this: bfx::g_pCurInstance->m_pMemoryManager,
                                         size: 0x2Cu,
                                         tag: bfx::MEM_BFXNAVIGATOR);
  if ( v3 != nullptr )
    v4 = bfx::NavigatorSpaceComponent::NavigatorSpaceComponent(this: v3, pSpace);
  else
    v4 = nullptr;
  *((_DWORD *)pSpace->m_components.m_data + 3) = v4;
}


// ========================================================================
// __unwind$82847
// EA  : 0x832559CC
// RVA : 0x012559CC
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void _unwind_82847()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 112 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?RegisterNavigatorSystem@bfx@@YAXXZ
// EA  : 0x83255A00
// RVA : 0x01255A00
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void __fastcall bfx::RegisterNavigatorSystem(bfx *this)
{
  bfx::SystemInstance *v1; // r11
  bfx::NavigatorInstance *v2; // r3
  bfx::NavigatorInstance *v3; // r5
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  v1 = bfx::g_pCurInstance;
  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
  {
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    v1 = bfx::g_pCurInstance;
  }
  v2 = (bfx::NavigatorInstance *)bfx::MemoryManager::Malloc(
                                   this: v1->m_pMemoryManager,
                                   size: 0x64u,
                                   tag: bfx::MEM_BFXNAVIGATOR);
  if ( v2 != nullptr )
    v3 = bfx::NavigatorInstance::NavigatorInstance(this: v2);
  else
    v3 = nullptr;
  bfx::ComponentManager::RegisterComponent(
    this: bfx::g_pCurInstance->m_pComponentManager,
    id: COMPONENTID_SURFACE_NAVIGATOR,
    pComponent: v3);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$82884
// EA  : 0x83255A8C
// RVA : 0x01255A8C
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void _unwind_82884()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// __unwind$82885
// EA  : 0x83255AB4
// RVA : 0x01255AB4
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void _unwind_82885()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 128 + 84), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ??1NavigatorSpaceComponent@bfx@@UAA@XZ
// EA  : 0x83255AE8
// RVA : 0x01255AE8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void __fastcall bfx::NavigatorSpaceComponent::~NavigatorSpaceComponent(bfx::NavigatorSpaceComponent *this)
{
  int m_size; // r11
  bfx::RepulsorImpl **v3; // r10
  void (__fastcall ***v4)(_DWORD, int); // r3
  bfx::RepulsorCatalog *m_pRepulsorCatalog; // r30
  bfx::RepulsorImpl **m_data; // r4
  bfx::NavigatorImpl **v7; // r4
  bfx::Space *p_m_repulsors; // [sp+50h] [-30h] BYREF

  this->__vftable = (bfx::NavigatorSpaceComponent_vtbl *)&bfx::NavigatorSpaceComponent::`vftable';
  p_m_repulsors = (bfx::Space *)this;
  bfx::Array<bfx::Path3D *>::remove(
    this: (bfx::Array<bfx::Space *> *)&bfx::g_pCurInstance->m_pComponentManager->m_components[3][1],
    val: &p_m_repulsors);
  if ( this->m_repulsors.m_size != 0 )
  {
    p_m_repulsors = (bfx::Space *)&this->m_repulsors;
    do
    {
      m_size = this->m_repulsors.m_size;
      v3 = &this->m_repulsors.m_data[m_size];
      p_m_repulsors = (bfx::Space *)&this->m_repulsors;
      v4 = (void (__fastcall ***)(_DWORD, int))*(v3 - 1);
      this->m_repulsors.m_size = m_size - 1;
      if ( v4 != nullptr )
        (**v4)(a1: v4, a2: 1);
    }
    while ( this->m_repulsors.m_size != 0 );
  }
  m_pRepulsorCatalog = this->m_pRepulsorCatalog;
  if ( m_pRepulsorCatalog != nullptr )
  {
    bfx::Repulsor3DCatalog::~Repulsor3DCatalog(this: this->m_pRepulsorCatalog);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pRepulsorCatalog);
  }
  this->m_pRepulsorCatalog = nullptr;
  this->m_pSpace = nullptr;
  m_data = this->m_repulsors.m_data;
  this->m_repulsors.m_size = 0;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_repulsors.m_data = nullptr;
  }
  this->m_repulsors.m_cap = 0;
  v7 = this->m_navigators.m_data;
  this->m_navigators.m_size = 0;
  if ( v7 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v7);
    this->m_navigators.m_data = nullptr;
  }
  this->m_navigators.m_cap = 0;
  this->__vftable = (bfx::NavigatorSpaceComponent_vtbl *)&bfx::SpaceComponent::`vftable';
}


// ========================================================================
// __unwind$82939
// EA  : 0x83255C14
// RVA : 0x01255C14
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void _unwind_82939()
{
  int v0; // r12

  bfx::SpaceComponent::~SpaceComponent(this: *(bfx::SpaceComponent **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$82940
// EA  : 0x83255C3C
// RVA : 0x01255C3C
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void _unwind_82940()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 8));
}


// ========================================================================
// __unwind$82941
// EA  : 0x83255C68
// RVA : 0x01255C68
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

void _unwind_82941()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 24));
}


// ========================================================================
// bfx::`dynamic initializer for 'MEM_BFXNAVIGATOR''
// EA  : 0x83398290
// RVA : 0x01398290
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorsystem.cpp
// ========================================================================

bfx::bfxMemTag bfx::_dynamic_initializer_for__MEM_BFXNAVIGATOR__()
{
  bfx::bfxMemTag result; // r3

  result = bfx::RegisterMemTag(tagName: "bfxNavigator");
  bfx::MEM_BFXNAVIGATOR = result;
  return result;
}

