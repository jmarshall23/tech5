
// ========================================================================
// ?EnableDistributedSteeringUpdates@bfx@@YAX_N@Z
// EA  : 0x83259320
// RVA : 0x01259320
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void __fastcall bfx::EnableDistributedSteeringUpdates(bool enable)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogEnableDistributedSteeringUpdates(enable);
  HIBYTE(bfx::g_pCurInstance->m_pComponentManager->m_components[4][10].__vftable) = enable;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$87253
// EA  : 0x83259384
// RVA : 0x01259384
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void _unwind_87253()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?SetGlobalDebugFlag@bfx@@YAXW4MoverDebugFlag@1@_N@Z
// EA  : 0x832593B0
// RVA : 0x012593B0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void __fastcall bfx::SetGlobalDebugFlag(unsigned int flag, bool enable)
{
  bfx::InstanceComponent_vtbl *v3; // r30
  __int64 v4; // r10
  __int64 v5; // r8
  __int64 v6; // r6
  __int64 v7; // r4
  int v8; // [sp+8h] [-68h]
  int v9; // [sp+Ch] [-64h]
  int v10; // [sp+10h] [-60h]
  int v11; // [sp+14h] [-5Ch]

  v3 = bfx::g_pCurInstance->m_pComponentManager->m_components[4][8].__vftable;
  if ( flag <= 8 )
  {
    switch ( flag )
    {
      case 1u:
        BYTE1(v3->dtr_InstanceComponent) = enable;
        break;
      case 2u:
        BYTE2(v3->dtr_InstanceComponent) = enable;
        break;
      case 3u:
        LOBYTE(v3->dtr_InstanceComponent) = enable;
        break;
      case 4u:
        HIBYTE(v3->Start) = enable;
        break;
      case 5u:
        BYTE1(v3->Start) = enable;
        break;
      case 6u:
        BYTE2(v3->Start) = enable;
        break;
      case 7u:
        if ( enable
          && (bfx::ReplayRecorder::IsOn(this: bfx::g_pCurInstance->m_pReplayRecorder)
           || (LODWORD(v4) = bfx::g_pCurInstance->m_pReplayPlayer->m_pParser, (_DWORD)v4 != 0)) )
        {
          HIDWORD(v7) = "BFX_DRAW_CUR_PATH_SECTION cannot be set during replay recording or playback.\n";
          bfx::InternalWarning(fmt: v7, a2: v6, a3: v5, a4: v4, a5: v8, a6: v9, a7: v10, a8: v11);
        }
        else
        {
          LOBYTE(v3->Start) = enable;
        }
        break;
      default:
        if ( flag != 0 )
          HIBYTE(v3->Draw) = enable;
        else
          HIBYTE(v3->dtr_InstanceComponent) = enable;
        break;
    }
  }
}


// ========================================================================
// ?Start@MovementInstance@bfx@@UAAXXZ
// EA  : 0x832594B8
// RVA : 0x012594B8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void __fastcall bfx::MovementInstance::Start(bfx::MovementInstance *this)
{
  this->m_pMoverReplayManager = bfx::CreateMoverReplayer(pReplayPlayer: bfx::g_pCurInstance->m_pReplayPlayer);
  this->m_nextMoverID = 0;
  this->m_nextProberID = 0;
  this->m_numMoversInAllSpaces = 0;
  this->m_enableDistributedSteeringUpdates = false;
  this->m_forceSnapToNavgraphForCreateAndTeleport = false;
  this->m_pRepulsionAccelerationTuneMatrix = nullptr;
}


// ========================================================================
// ?Stop@MovementInstance@bfx@@UAAXXZ
// EA  : 0x83259510
// RVA : 0x01259510
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void __fastcall bfx::MovementInstance::Stop(bfx::MovementInstance *this)
{
  bfx::DestroyMover3DReplayer(pPlannerReplayManager: (bfx::PlannerReplayManager *)this->m_pMoverReplayManager);
  this->m_pMoverReplayManager = nullptr;
}


// ========================================================================
// ?Draw@MovementInstance@bfx@@UAAXXZ
// EA  : 0x83259548
// RVA : 0x01259548
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall bfx::MovementInstance::Draw(bfx::MovementInstance *this, int a2, __int64 a3, __int64 a4)
{
  __int64 v5; // r10
  __int64 v6; // r4
  __int64 v7; // r10
  __int64 v8; // r4
  __int64 v9; // r8
  __int64 v10; // r6
  int v11; // [sp+8h] [-58h]
  int v12; // [sp+8h] [-58h]
  int v13; // [sp+Ch] [-54h]
  int v14; // [sp+Ch] [-54h]
  int v15; // [sp+10h] [-50h]
  int v16; // [sp+10h] [-50h]
  int v17; // [sp+14h] [-4Ch]
  int v18; // [sp+14h] [-4Ch]

  LODWORD(v5) = bfx::g_pCurInstance->m_pDebugOptions;
  if ( *(_BYTE *)v5 != 0 )
  {
    HIDWORD(v6) = "\n--- Mover Module ---\n";
    HIDWORD(v5) = *(unsigned __int8 *)v5;
    bfx::DrawString(fmt: v6, a2: a3, a3: a4, a4: v5, a5: v11, a6: v13, a7: v15, a8: v17);
    LODWORD(v7) = &unk_82410000;
    LODWORD(v8) = this->m_numMoversInAllSpaces;
    HIDWORD(v8) = "num movers = %d\n";
    bfx::DrawString(fmt: v8, a2: v10, a3: v9, a4: v7, a5: v12, a6: v14, a7: v16, a8: v18);
  }
}


// ========================================================================
// ??0MoverSubset@bfx@@QAA@XZ
// EA  : 0x832595A8
// RVA : 0x012595A8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

bfx::MoverSubset *__fastcall bfx::MoverSubset::MoverSubset(bfx::MoverSubset *this)
{
  bfx::bfxMemTag v1; // r10

  v1 = bfx::MEM_BFXMOVER;
  this->m_moverSubset.m_data = nullptr;
  this->m_accumulatedSimTime = 0.0;
  this->m_moverSubset.m_size = 0;
  this->m_moverSubset.m_cap = 0;
  this->m_moverSubset.m_tag = v1;
  return this;
}


// ========================================================================
// ?ProcessMoverReplayPosRecords@MoverSpaceComponent@bfx@@QAAXABV?$Array@VMoverReplayPosRecord@bfx@@@2@@Z
// EA  : 0x832595D8
// RVA : 0x012595D8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void __fastcall bfx::MoverSpaceComponent::ProcessMoverReplayPosRecords(
        bfx::MoverSpaceComponent *this,
        const bfx::Array<bfx::MoverReplayPosRecord> *records)
{
  int v4; // r27
  bfx::Array<bfx::MoverImpl *> *p_m_movers; // r29
  int v7; // r30
  int v8; // r9
  int m_size; // r8
  bfx::MoverReplayPosRecord *v10; // r31
  int v11; // r11
  bfx::MoverImpl *v12; // r10
  float v14; // [sp+50h] [-50h] BYREF
  float v15; // [sp+54h] [-4Ch]
  float v16; // [sp+58h] [-48h]

  v4 = 0;
  _FP31 = 0.0;
  if ( records->m_size > 0 )
  {
    p_m_movers = &this->m_movers;
    v7 = 0;
    do
    {
      v8 = 0;
      m_size = p_m_movers->m_size;
      v10 = &records->m_data[v7];
      if ( m_size > 0 )
      {
        v11 = 0;
        while ( 1 )
        {
          v12 = p_m_movers->m_data[v11];
          if ( v12->m_commonState.m_replayID == records->m_data[v7].m_replayID )
            break;
          ++v8;
          ++v11;
          if ( v8 >= m_size )
            goto LABEL_9;
        }
        ((void (__fastcall *)(float *))v12->m_behavior.m_pCurMotion->GetPos)(a1: &v14);
        _FP1 = (float)((float)_FP31
                     - (float)__fsqrts((float)((float)((float)(v14 - v10->m_pos.m_x) * (float)(v14 - v10->m_pos.m_x))
                                             + (float)((float)((float)(v16 - v10->m_pos.m_z)
                                                             * (float)(v16 - v10->m_pos.m_z))
                                                     + (float)((float)(v15 - v10->m_pos.m_y)
                                                             * (float)(v15 - v10->m_pos.m_y))))));
        __asm { fsel      f31, f1, f31, f2 }
      }
LABEL_9:
      ++v4;
      ++v7;
    }
    while ( v4 < records->m_size );
  }
  this->m_replayDivergenceDist = _FP31;
}


// ========================================================================
// ?LogMoverReplayPosRecords@MoverSpaceComponent@bfx@@AAAXM@Z
// EA  : 0x832596D8
// RVA : 0x012596D8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void __fastcall bfx::MoverSpaceComponent::LogMoverReplayPosRecords(bfx::MoverSpaceComponent *this, double simTime)
{
  double v4; // fp13
  int v5; // r30
  int v6; // r29
  bfx::MoverImpl *v7; // r24
  bfx::SystemInstance *v8; // r11
  _DWORD v9[4]; // [sp+50h] [-80h] BYREF
  bfx::Array<bfx::ResourceManager::Registration> v10; // [sp+60h] [-70h] BYREF
  bfx::ResourceManager::Registration v11; // [sp+70h] [-60h] BYREF

  if ( (bfx::ReplayRecorder::IsOn(this: bfx::g_pCurInstance->m_pReplayRecorder)
     || bfx::g_pCurInstance->m_pReplayPlayer->m_pParser != nullptr)
    && this->m_movers.m_size != 0 )
  {
    v4 = (float)((float)simTime + this->m_moverLoggingTime);
    this->m_moverLoggingTime = (float)simTime + this->m_moverLoggingTime;
    if ( v4 >= 1.0 )
    {
      v10.m_data = nullptr;
      v10.m_size = 0;
      this->m_moverLoggingTime = 0.0;
      v10.m_cap = 0;
      v10.m_tag = bfx::MEM_BFXMOVER;
      v5 = 0;
      if ( this->m_movers.m_size > 0 )
      {
        v6 = 0;
        do
        {
          v7 = this->m_movers.m_data[v6];
          ((void (__fastcall *)(_DWORD *))v7->m_behavior.m_pCurMotion->GetPos)(a1: v9);
          v11.m_id = v7->m_commonState.m_replayID;
          v11.m_initCB = (bool (__fastcall *)(bfx::Space *, unsigned int, bfx::BinaryImageIn *, const bfx::ResourceOffset *))v9[0];
          v11.m_termCB = (void (__fastcall *)(bfx::Space *, unsigned int, bfx::BinaryImageIn *))v9[1];
          v11.m_isUpToDateCB = (bool (__fastcall *)(bool, const char *))v9[2];
          bfx::Array<bfx::Plane>::push_back(this: &v10, val: &v11);
          ++v5;
          ++v6;
        }
        while ( v5 < this->m_movers.m_size );
      }
      if ( bfx::ReplayRecorder::IsOn(this: bfx::g_pCurInstance->m_pReplayRecorder) )
        bfx::LogMoverReplayPosRecords(
          pSpace: this->m_pSpace,
          records: (const bfx::Array<bfx::MoverReplayPosRecord> *)&v10);
      v8 = bfx::g_pCurInstance;
      if ( bfx::g_pCurInstance->m_pReplayPlayer->m_pParser != nullptr )
      {
        bfx::ProcessLogMoverReplayPosRecordsEvent();
        v8 = bfx::g_pCurInstance;
      }
      v10.m_size = 0;
      if ( v10.m_data != nullptr )
        bfx::MemoryManager::Free(this: v8->m_pMemoryManager, ptr: v10.m_data);
    }
  }
}


// ========================================================================
// __unwind$88122
// EA  : 0x83259850
// RVA : 0x01259850
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void _unwind_88122()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 208 + 96));
}


// ========================================================================
// ?Draw@MoverSpaceComponent@bfx@@UAAXABVDrawCullData@2@@Z
// EA  : 0x83259878
// RVA : 0x01259878
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void __fastcall bfx::MoverSpaceComponent::Draw(
        bfx::MoverSpaceComponent *this,
        const bfx::DrawCullData *drawCull,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  bfx::Array<bfx::MoverImpl *> *p_m_movers; // r29
  int v8; // r31
  int v9; // r30
  double m_replayDivergenceDist; // fp1
  int v11; // [sp+8h] [-78h]
  int v12; // [sp+Ch] [-74h]
  int v13; // [sp+10h] [-70h]
  int v14; // [sp+14h] [-6Ch]

  p_m_movers = &this->m_movers;
  v8 = 0;
  if ( this->m_movers.m_size > 0 )
  {
    v9 = 0;
    do
    {
      bfx::MoverImpl::Draw(this: p_m_movers->m_data[v9], drawCull);
      ++v8;
      ++v9;
    }
    while ( v8 < p_m_movers->m_size );
  }
  LODWORD(a5) = bfx::g_warnOnReplayDivergence;
  if ( bfx::g_warnOnReplayDivergence )
  {
    m_replayDivergenceDist = this->m_replayDivergenceDist;
    if ( m_replayDivergenceDist > 0.0 )
      bfx::DrawString(
        fmt: __SPAIR64__("replay divergence = %f\n", LODWORD(m_replayDivergenceDist)),
        a2: a3,
        a3: a4,
        a4: a5,
        a5: v11,
        a6: v12,
        a7: v13,
        a8: v14);
  }
}


// ========================================================================
// ?AddMover@MoverSpaceComponent@bfx@@QAAXPAVMoverImpl@2@@Z
// EA  : 0x83259908
// RVA : 0x01259908
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void __fastcall bfx::MoverSpaceComponent::AddMover(
        bfx::MoverSpaceComponent *this,
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
  bfx::MoverSubsetData *m_pMoverSubsetData; // r11
  bfx::Array<bfx::Space *> *m_moverSubsets; // r3
  bfx::Space *v18; // [sp+50h] [-20h] BYREF

  a14 = pMover;
  bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)&this->m_movers, val: &a14);
  m_pMoverSubsetData = this->m_pMoverSubsetData;
  v18 = pMover;
  m_moverSubsets = (bfx::Array<bfx::Space *> *)m_pMoverSubsetData->m_moverSubsets;
  if ( m_pMoverSubsetData->m_moverSubsets[0].m_moverSubset.m_size > m_pMoverSubsetData->m_moverSubsets[1].m_moverSubset.m_size )
    m_moverSubsets = (bfx::Array<bfx::Space *> *)&m_pMoverSubsetData->m_moverSubsets[1];
  bfx::Array<bfx::Portal *>::push_back(this: m_moverSubsets, val: &v18);
  ++bfx::g_pCurInstance->m_pComponentManager->m_components[4][9].__vftable;
}


// ========================================================================
// ?Colorize@MoverSpaceComponent@bfx@@QAAXXZ
// EA  : 0x83259990
// RVA : 0x01259990
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void __fastcall bfx::MoverSpaceComponent::Colorize(bfx::MoverSpaceComponent *this)
{
  bfx::Array<bfx::MoverImpl *> *p_m_movers; // r29
  int v2; // r31
  int v3; // r30
  bfx::MoverImpl *v4; // r28
  bfx::Color v5; // [sp+50h] [-40h] BYREF

  p_m_movers = &this->m_movers;
  v2 = 0;
  if ( this->m_movers.m_size > 0 )
  {
    v3 = 0;
    do
    {
      v4 = p_m_movers->m_data[v3];
      ++v2;
      ++v3;
      v4->m_overrideColor = *bfx::GenerateRandomColor(result: &v5, seedNum: v4->m_commonState.m_replayID);
    }
    while ( v2 < p_m_movers->m_size );
  }
}


// ========================================================================
// ??0MovementInstance@bfx@@QAA@XZ
// EA  : 0x83259A10
// RVA : 0x01259A10
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

bfx::MovementInstance *__fastcall bfx::MovementInstance::MovementInstance(bfx::MovementInstance *this)
{
  bfx::bfxMemTag v2; // r11
  bfx::MoverDebugOptions *v3; // r3
  bfx::MoverDebugOptions *v4; // r11

  this->__vftable = (bfx::MovementInstance_vtbl *)&bfx::MovementInstance::`vftable';
  v2 = bfx::MEM_BFXMOVER;
  this->m_moverSpaceComponents.m_data = nullptr;
  this->m_moverSpaceComponents.m_size = 0;
  this->m_moverSpaceComponents.m_cap = 0;
  this->m_moverSpaceComponents.m_tag = v2;
  this->m_nextMoverID = 0;
  this->m_nextProberID = 0;
  this->m_pMoverReplayManager = nullptr;
  this->m_numMoversInAllSpaces = 0;
  this->m_enableDistributedSteeringUpdates = false;
  this->m_forceSnapToNavgraphForCreateAndTeleport = false;
  this->m_pRepulsionAccelerationTuneMatrix = nullptr;
  v3 = (bfx::MoverDebugOptions *)bfx::MemoryManager::Malloc(
                                   this: bfx::g_pCurInstance->m_pMemoryManager,
                                   size: 9u,
                                   tag: bfx::MEM_BFXSYSTEM);
  if ( v3 != nullptr )
  {
    v3->m_drawMoverCylinders = false;
    v4 = v3;
    v3->m_drawMoverGoals = false;
    v3->m_drawMoverGoalsReached = false;
    v3->m_drawMoverDebugNames = false;
    v3->m_drawMoverState = false;
    v3->m_drawMoverAttractions = false;
    v3->m_drawClientMotion = false;
    v3->m_drawCurPathSection = false;
    v3->m_drawFollowerGoals = false;
  }
  else
  {
    v4 = nullptr;
  }
  this->m_pDebugOptions = v4;
  return this;
}


// ========================================================================
// __unwind$88338
// EA  : 0x83259AD8
// RVA : 0x01259AD8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void _unwind_88338()
{
  int v0; // r12

  bfx::InstanceComponent::~InstanceComponent(this: *(bfx::InstanceComponent **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$88339
// EA  : 0x83259B00
// RVA : 0x01259B00
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void _unwind_88339()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 4));
}


// ========================================================================
// ??1MovementInstance@bfx@@UAA@XZ
// EA  : 0x83259B38
// RVA : 0x01259B38
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void __fastcall bfx::MovementInstance::~MovementInstance(bfx::MovementInstance *this)
{
  bfx::MoverDebugOptions *m_pDebugOptions; // r4
  bfx::MoverSpaceComponent **m_data; // r4

  this->__vftable = (bfx::MovementInstance_vtbl *)&bfx::MovementInstance::`vftable';
  m_pDebugOptions = this->m_pDebugOptions;
  if ( m_pDebugOptions != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pDebugOptions);
    this->m_pDebugOptions = nullptr;
  }
  m_data = this->m_moverSpaceComponents.m_data;
  this->m_moverSpaceComponents.m_size = 0;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_moverSpaceComponents.m_data = nullptr;
  }
  this->m_moverSpaceComponents.m_cap = 0;
  this->__vftable = (bfx::MovementInstance_vtbl *)&bfx::InstanceComponent::`vftable';
}


// ========================================================================
// __unwind$88378
// EA  : 0x83259BBC
// RVA : 0x01259BBC
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void _unwind_88378()
{
  int v0; // r12

  bfx::InstanceComponent::~InstanceComponent(this: *(bfx::InstanceComponent **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$88379
// EA  : 0x83259BE4
// RVA : 0x01259BE4
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void _unwind_88379()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 4));
}


// ========================================================================
// ?RegisterMoverSystem@bfx@@YAXXZ
// EA  : 0x83259C18
// RVA : 0x01259C18
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void __fastcall bfx::RegisterMoverSystem(bfx *this)
{
  bfx::SystemInstance *v1; // r11
  bfx::MovementInstance *v2; // r3
  bfx::MovementInstance *v3; // r5
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  v1 = bfx::g_pCurInstance;
  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
  {
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    v1 = bfx::g_pCurInstance;
  }
  v2 = (bfx::MovementInstance *)bfx::MemoryManager::Malloc(
                                  this: v1->m_pMemoryManager,
                                  size: 0x30u,
                                  tag: bfx::MEM_BFXMOVER);
  if ( v2 != nullptr )
    v3 = bfx::MovementInstance::MovementInstance(this: v2);
  else
    v3 = nullptr;
  bfx::ComponentManager::RegisterComponent(
    this: bfx::g_pCurInstance->m_pComponentManager,
    id: COMPONENTID_SURFACE_MOVER,
    pComponent: v3);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$88518
// EA  : 0x83259CA4
// RVA : 0x01259CA4
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void _unwind_88518()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// __unwind$88519
// EA  : 0x83259CCC
// RVA : 0x01259CCC
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void _unwind_88519()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 128 + 84), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ??0MoverSpaceComponent@bfx@@QAA@PAVSpace@1@@Z
// EA  : 0x83259D00
// RVA : 0x01259D00
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

bfx::MoverSpaceComponent *__fastcall bfx::MoverSpaceComponent::MoverSpaceComponent(
        bfx::MoverSpaceComponent *this,
        bfx::Space *pSpace)
{
  bfx::MoverSubsetData *v3; // r29
  bfx::Space *v4; // r3
  bfx::Space *v5; // r28
  bfx::Space *p_m_movers; // [sp+50h] [-40h] BYREF

  this->m_pSpace = pSpace;
  v3 = nullptr;
  this->__vftable = (bfx::MoverSpaceComponent_vtbl *)&bfx::MoverSpaceComponent::`vftable';
  this->m_movers.m_tag = bfx::MEM_BFXMOVER;
  this->m_movers.m_data = nullptr;
  p_m_movers = (bfx::Space *)&this->m_movers;
  this->m_movers.m_size = 0;
  this->m_movers.m_cap = 0;
  this->m_pMoverSubsetData = nullptr;
  this->m_frameSimTime = 0.0;
  this->m_simTimePending = 0.0;
  bfx::List<bfx::MoverSpaceComponent::ObstacleRequestData>::List<bfx::MoverSpaceComponent::ObstacleRequestData>(
    this: (bfx::List<bfx::SolverPair> *)&this->m_obstacleRequests,
    numNodesPerPoolBlock: 0x19u,
    memTag: bfx::MEM_BFXMOVER);
  this->m_moverLoggingTime = 0.0;
  this->m_replayDivergenceDist = 0.0;
  v4 = (bfx::Space *)bfx::MemoryManager::Malloc(
                       this: bfx::g_pCurInstance->m_pMemoryManager,
                       size: 0x2Cu,
                       tag: bfx::MEM_BFXMOVER);
  v5 = v4;
  p_m_movers = v4;
  if ( v4 != nullptr )
  {
    v4->__vftable = nullptr;
    `eh vector constructor iterator'(
      ptr: &v4->m_pProxy,
      size: 0x14u,
      count: 2,
      pCtor: (void (__fastcall *)(void *))bfx::MoverSubset::MoverSubset,
      pDtor: (void (__fastcall *)(void *))bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>);
    v3 = (bfx::MoverSubsetData *)v5;
  }
  this->m_pMoverSubsetData = v3;
  p_m_movers = (bfx::Space *)this;
  bfx::Array<bfx::Portal *>::push_back(
    this: (bfx::Array<bfx::Space *> *)&bfx::g_pCurInstance->m_pComponentManager->m_components[4][1],
    val: &p_m_movers);
  return this;
}


// ========================================================================
// __unwind$88829
// EA  : 0x83259DFC
// RVA : 0x01259DFC
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void _unwind_88829()
{
  int v0; // r12

  bfx::SpaceComponent::~SpaceComponent(this: *(bfx::SpaceComponent **)(v0 - 144 + 164));
}


// ========================================================================
// __unwind$88830
// EA  : 0x83259E24
// RVA : 0x01259E24
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void _unwind_88830()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                             + 8));
}


// ========================================================================
// __unwind$88831
// EA  : 0x83259E50
// RVA : 0x01259E50
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void _unwind_88831()
{
  int v0; // r12

  bfx::List<bfx::MoverSpaceComponent::ObstacleRequestData>::~List<bfx::MoverSpaceComponent::ObstacleRequestData>(this: (bfx::List<bfx::SolverPair> *)(*(_DWORD *)(v0 - 144 + 164) + 36));
}


// ========================================================================
// __unwind$88832
// EA  : 0x83259E7C
// RVA : 0x01259E7C
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void _unwind_88832()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 144 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?TraditionalSimulate@MoverSpaceComponent@bfx@@AAAXM@Z
// EA  : 0x83259EA8
// RVA : 0x01259EA8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void __fastcall bfx::MoverSpaceComponent::TraditionalSimulate(bfx::MoverSpaceComponent *this, double simTime)
{
  int v4; // r31
  int v5; // r30
  double v6; // fp13
  bfx::Array<bfx::MoverImpl *> *p_m_movers; // r31
  int v9; // r30
  int v11; // r29
  int v12; // r29
  int v13; // r30
  double v14; // fp13

  if ( bfx::g_colorizeMovers )
    bfx::MoverSpaceComponent::Colorize(this);
  if ( simTime == 0.0 )
  {
    v4 = 0;
    if ( this->m_movers.m_size > 0 )
    {
      v5 = 0;
      do
      {
        this->m_movers.m_data[v5]->CalcAcc(this: this->m_movers.m_data[v5], a2: simTime);
        ++v4;
        ++v5;
      }
      while ( v4 < this->m_movers.m_size );
    }
  }
  v6 = (float)(this->m_simTimePending + (float)simTime);
  this->m_simTimePending = this->m_simTimePending + (float)simTime;
  if ( v6 >= 0.00333 )
  {
    p_m_movers = &this->m_movers;
    do
    {
      _FP13 = (float)(this->m_simTimePending - (float)0.050000001);
      v9 = 0;
      __asm { fsel      f31, f13, f30, f0 }
      if ( this->m_movers.m_size > 0 )
      {
        v11 = 0;
        do
        {
          p_m_movers->m_data[v11]->CalcAcc(this: p_m_movers->m_data[v11], a2: _FP31);
          ++v9;
          ++v11;
        }
        while ( v9 < this->m_movers.m_size );
      }
      v12 = 0;
      if ( this->m_movers.m_size > 0 )
      {
        v13 = 0;
        do
        {
          p_m_movers->m_data[v13]->UpdateState(this: p_m_movers->m_data[v13], a2: _FP31);
          ++v12;
          ++v13;
        }
        while ( v12 < this->m_movers.m_size );
      }
      v14 = (float)(this->m_simTimePending - (float)_FP31);
      this->m_simTimePending = this->m_simTimePending - (float)_FP31;
    }
    while ( v14 >= 0.00333 );
  }
}


// ========================================================================
// ?DistributedSteeringSimulate@MoverSpaceComponent@bfx@@AAAXM@Z
// EA  : 0x8325A020
// RVA : 0x0125A020
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void __fastcall bfx::MoverSpaceComponent::DistributedSteeringSimulate(bfx::MoverSpaceComponent *this, double simTime)
{
  int v4; // r31
  int v5; // r30
  bfx::MoverSubsetData *m_pMoverSubsetData; // r11
  double v7; // fp9
  bfx::MoverSubsetData *v8; // r28
  int v9; // r25
  bfx::MoverSubset *v10; // r27
  double v11; // fp0
  int v13; // r30
  int v15; // r31
  int v17; // r31
  int v19; // r30
  bfx::MoverSubsetData *v20; // r11
  int v21; // r10

  if ( this->m_movers.m_size != 0 )
  {
    if ( bfx::g_colorizeMovers )
      bfx::MoverSpaceComponent::Colorize(this);
    if ( simTime == 0.0 )
    {
      v4 = 0;
      if ( this->m_movers.m_size > 0 )
      {
        v5 = 0;
        do
        {
          this->m_movers.m_data[v5]->CalcAcc(this: this->m_movers.m_data[v5], a2: simTime);
          ++v4;
          ++v5;
        }
        while ( v4 < this->m_movers.m_size );
      }
    }
    m_pMoverSubsetData = this->m_pMoverSubsetData;
    this->m_simTimePending = this->m_simTimePending + (float)simTime;
    v7 = (float)((float)simTime + m_pMoverSubsetData->m_moverSubsets[1].m_accumulatedSimTime);
    m_pMoverSubsetData->m_moverSubsets[0].m_accumulatedSimTime = (float)simTime
                                                               + m_pMoverSubsetData->m_moverSubsets[0].m_accumulatedSimTime;
    m_pMoverSubsetData->m_moverSubsets[1].m_accumulatedSimTime = v7;
    if ( this->m_simTimePending >= 0.00333 )
    {
      v8 = this->m_pMoverSubsetData;
      v9 = 20 * (v8->m_curSubsetIndex + 1);
      v10 = &v8->m_moverSubsets[v8->m_curSubsetIndex];
      while ( 1 )
      {
        v11 = *(float *)((char *)&v8->m_curSubsetIndex + v9);
        if ( v11 >= 0.00333 )
          goto LABEL_13;
        if ( this->m_simTimePending < 0.00333 )
        {
          v20 = this->m_pMoverSubsetData;
          v21 = v20->m_curSubsetIndex + 1;
          v20->m_curSubsetIndex = v21;
          if ( v21 >= 2 )
            v20->m_curSubsetIndex = 0;
          return;
        }
        if ( v11 >= 0.00333 )
        {
LABEL_13:
          _FP13 = (float)(*(float *)((char *)&v8->m_curSubsetIndex + v9) - (float)0.050000001);
          v13 = 0;
          __asm { fsel      f31, f13, f30, f0 }
          if ( v10->m_moverSubset.m_size > 0 )
          {
            v15 = 0;
            do
            {
              v10->m_moverSubset.m_data[v15]->CalcAcc(this: v10->m_moverSubset.m_data[v15], a2: _FP31);
              ++v13;
              ++v15;
            }
            while ( v13 < v10->m_moverSubset.m_size );
          }
          *(float *)((char *)&v8->m_curSubsetIndex + v9) = *(float *)((char *)&v8->m_curSubsetIndex + v9) - (float)_FP31;
        }
        if ( this->m_simTimePending >= 0.00333 )
        {
          _FP13 = (float)(this->m_simTimePending - (float)0.050000001);
          v17 = 0;
          __asm { fsel      f31, f13, f30, f0 }
          if ( this->m_movers.m_size > 0 )
          {
            v19 = 0;
            do
            {
              this->m_movers.m_data[v19]->UpdateState(this: this->m_movers.m_data[v19], a2: _FP31);
              ++v17;
              ++v19;
            }
            while ( v17 < this->m_movers.m_size );
          }
          this->m_simTimePending = this->m_simTimePending - (float)_FP31;
        }
      }
    }
  }
}


// ========================================================================
// ?Simulate@MoverSpaceComponent@bfx@@UAAXM@Z
// EA  : 0x8325A248
// RVA : 0x0125A248
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void __fastcall bfx::MoverSpaceComponent::Simulate(bfx::MoverSpaceComponent *this, double simTime)
{
  this->m_frameSimTime = simTime;
  if ( HIBYTE(bfx::g_pCurInstance->m_pComponentManager->m_components[4][10].__vftable) != 0 )
    bfx::MoverSpaceComponent::DistributedSteeringSimulate(this, simTime);
  else
    bfx::MoverSpaceComponent::TraditionalSimulate(this, simTime);
}


// ========================================================================
// ?RemoveMover@MoverSpaceComponent@bfx@@QAAXPAVMoverImpl@2@@Z
// EA  : 0x8325A270
// RVA : 0x0125A270
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void __fastcall bfx::MoverSpaceComponent::RemoveMover(
        bfx::MoverSpaceComponent *this,
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
  bfx::MoverSubsetData *m_pMoverSubsetData; // r31
  bfx::Space *v16[2]; // [sp+50h] [-20h] BYREF

  a14 = pMover;
  v16[0] = pMover;
  bfx::Array<bfx::Path3D *>::remove(this: (bfx::Array<bfx::Space *> *)&this->m_movers, val: &a14);
  m_pMoverSubsetData = this->m_pMoverSubsetData;
  bfx::Array<bfx::Path3D *>::remove(this: (bfx::Array<bfx::Space *> *)m_pMoverSubsetData->m_moverSubsets, val: v16);
  bfx::Array<bfx::Path3D *>::remove(this: (bfx::Array<bfx::Space *> *)&m_pMoverSubsetData->m_moverSubsets[1], val: v16);
  --bfx::g_pCurInstance->m_pComponentManager->m_components[4][9].__vftable;
}


// ========================================================================
// ?SpaceInit@MovementInstance@bfx@@UAAXPAVSpace@2@@Z
// EA  : 0x8325A358
// RVA : 0x0125A358
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void __fastcall bfx::MovementInstance::SpaceInit(bfx::MovementInstance *this, bfx::Space *pSpace)
{
  bfx::MoverSpaceComponent *v3; // r3
  bfx::MoverSpaceComponent *v4; // r3

  v3 = (bfx::MoverSpaceComponent *)bfx::MemoryManager::Malloc(
                                     this: bfx::g_pCurInstance->m_pMemoryManager,
                                     size: 0x38u,
                                     tag: bfx::MEM_BFXMOVER);
  if ( v3 != nullptr )
    v4 = bfx::MoverSpaceComponent::MoverSpaceComponent(this: v3, pSpace);
  else
    v4 = nullptr;
  *((_DWORD *)pSpace->m_components.m_data + 4) = v4;
}


// ========================================================================
// __unwind$89160
// EA  : 0x8325A3CC
// RVA : 0x0125A3CC
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void _unwind_89160()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 112 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ??1MoverSpaceComponent@bfx@@UAA@XZ
// EA  : 0x8325A440
// RVA : 0x0125A440
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void __fastcall bfx::MoverSpaceComponent::~MoverSpaceComponent(bfx::MoverSpaceComponent *this)
{
  int m_size; // r11
  bfx::MoverImpl **v3; // r10
  void (__fastcall ***v4)(_DWORD, int); // r3
  bfx::MoverSubsetData *m_pMoverSubsetData; // r30
  bfx::MoverImpl **m_data; // r4
  bfx::Space *p_m_movers; // [sp+50h] [-30h] BYREF

  this->__vftable = (bfx::MoverSpaceComponent_vtbl *)&bfx::MoverSpaceComponent::`vftable';
  p_m_movers = (bfx::Space *)this;
  bfx::Array<bfx::Path3D *>::remove(
    this: (bfx::Array<bfx::Space *> *)&bfx::g_pCurInstance->m_pComponentManager->m_components[4][1],
    val: &p_m_movers);
  if ( this->m_movers.m_size != 0 )
  {
    p_m_movers = (bfx::Space *)&this->m_movers;
    do
    {
      m_size = this->m_movers.m_size;
      v3 = &this->m_movers.m_data[m_size];
      p_m_movers = (bfx::Space *)&this->m_movers;
      v4 = (void (__fastcall ***)(_DWORD, int))*(v3 - 1);
      this->m_movers.m_size = m_size - 1;
      if ( v4 != nullptr )
        (**v4)(a1: v4, a2: 1);
    }
    while ( this->m_movers.m_size != 0 );
  }
  m_pMoverSubsetData = this->m_pMoverSubsetData;
  if ( m_pMoverSubsetData != nullptr )
  {
    `eh vector destructor iterator'(
      ptr: m_pMoverSubsetData->m_moverSubsets,
      size: 0x14u,
      count: 2,
      pDtor: (void (__fastcall *)(void *))bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pMoverSubsetData);
  }
  this->m_pMoverSubsetData = nullptr;
  this->m_pSpace = nullptr;
  bfx::List<bfx::MoverSpaceComponent::ObstacleRequestData>::~List<bfx::MoverSpaceComponent::ObstacleRequestData>(this: (bfx::List<bfx::SolverPair> *)&this->m_obstacleRequests);
  m_data = this->m_movers.m_data;
  this->m_movers.m_size = 0;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_movers.m_data = nullptr;
  }
  this->m_movers.m_cap = 0;
  this->__vftable = (bfx::MoverSpaceComponent_vtbl *)&bfx::SpaceComponent::`vftable';
}


// ========================================================================
// __unwind$89272
// EA  : 0x8325A560
// RVA : 0x0125A560
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void _unwind_89272()
{
  int v0; // r12

  bfx::SpaceComponent::~SpaceComponent(this: *(bfx::SpaceComponent **)(v0 - 128 + 148));
}


// ========================================================================
// __unwind$89273
// EA  : 0x8325A588
// RVA : 0x0125A588
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void _unwind_89273()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 8));
}


// ========================================================================
// __unwind$89274
// EA  : 0x8325A5B4
// RVA : 0x0125A5B4
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void _unwind_89274()
{
  int v0; // r12

  bfx::List<bfx::MoverSpaceComponent::ObstacleRequestData>::~List<bfx::MoverSpaceComponent::ObstacleRequestData>(this: (bfx::List<bfx::SolverPair> *)(*(_DWORD *)(v0 - 128 + 148) + 36));
}


// ========================================================================
// ?RequestCreateObstacle@MoverSpaceComponent@bfx@@QAA?AV?$Handle@VObstacleImpl@bfx@@@2@ABVVec3@2@ABVQuat@2@0ABVObstacleDat@2@@Z
// EA  : 0x8325A6E0
// RVA : 0x0125A6E0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

bfx::Handle<bfx::ObstacleImpl> *__fastcall bfx::MoverSpaceComponent::RequestCreateObstacle(
        bfx::MoverSpaceComponent *this,
        bfx::Handle<bfx::ObstacleImpl> *result,
        const bfx::Vec3 *pos,
        const bfx::Quat *rot,
        const bfx::Vec3 *boxDimensions,
        const bfx::ObstacleDat *obstacleDat)
{
  __int128 v7; // r10
  unsigned __int64 v8; // r27
  double m_y; // fp13
  double m_z; // fp12
  double m_w; // fp11
  double m_x; // fp10
  double v13; // fp9
  double v14; // fp8
  double v15; // fp7
  double v16; // fp6
  double v17; // fp5
  bfx::MemoryManager *m_pMemoryManager; // r3
  bfx::HandleProxy *v19; // r3
  char v20; // r11
  bfx::HandleProxy *v21; // r27
  bfx::HandleProxy *m_pProxy; // r3
  bfx::HandleProxy *v23; // r29
  bfx::Pool::Node *Node; // r3
  bfx::Pool::Node *v25; // r30
  bfx::HandleProxy *v26; // r28
  bfx::Handle<bfx::Space> v28; // [sp+50h] [-A0h] BYREF
  int v29; // [sp+54h] [-9Ch]
  bfx::Handle<bfx::ObstacleImpl> *v30; // [sp+58h] [-98h]
  bfx::MoverSpaceComponent::ObstacleRequestData v31; // [sp+60h] [-90h] BYREF

  v29 = 0;
  v31.m_obstacle.m_pProxy = nullptr;
  *((_QWORD *)&v7 + 1) = *(_QWORD *)&obstacleDat->m_layerMask;
  *(_QWORD *)((char *)&v7 + 4) = *(_QWORD *)&obstacleDat->m_obstacleBlockageFlags;
  v8 = *(_QWORD *)(DWORD1(v7) + 16);
  *(_QWORD *)&v7 = *(_QWORD *)(DWORD1(v7) + 24);
  m_y = pos->m_y;
  m_z = pos->m_z;
  m_w = rot->m_w;
  m_x = rot->m_x;
  v13 = rot->m_y;
  v14 = rot->m_z;
  v15 = *(float *)HIDWORD(v7);
  v16 = *(float *)(HIDWORD(v7) + 4);
  v17 = *(float *)(HIDWORD(v7) + 8);
  v31.m_pos.m_x = pos->m_x;
  v31.m_pos.m_y = m_y;
  v31.m_pos.m_z = m_z;
  m_pMemoryManager = bfx::g_pCurInstance->m_pMemoryManager;
  v31.m_rot.m_w = m_w;
  v31.m_rot.m_x = m_x;
  v31.m_rot.m_y = v13;
  v31.m_rot.m_z = v14;
  v31.m_boxDimensions.m_x = v15;
  v31.m_boxDimensions.m_y = v16;
  v31.m_boxDimensions.m_z = v17;
  *(_QWORD *)&v31.m_obstacleDat.m_layerMask = v7;
  *(_QWORD *)&v31.m_obstacleDat.m_obstacleBlockageFlags = *(_QWORD *)((char *)&v7 + 4);
  v31.m_obstacleDat.m_userData = v8;
  *(_QWORD *)&v31.m_obstacleDat.m_obstacleName = *(_QWORD *)&v7;
  v19 = (bfx::HandleProxy *)bfx::MemoryManager::Malloc(this: m_pMemoryManager, size: 8u, tag: bfx::MEM_BFXSYSTEM);
  if ( v19 != nullptr )
  {
    v20 = *((_BYTE *)v19 + 7);
    v21 = v19;
    v19->m_pTarget = nullptr;
    *((_DWORD *)v19 + 1) = v20 & 3;
  }
  else
  {
    v21 = nullptr;
  }
  v28.m_pProxy = v21;
  if ( v21 != nullptr )
    *((_DWORD *)v21 + 1) = (unsigned __int8)*((_DWORD *)v21 + 1)
                         | ((*((_DWORD *)v21 + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
  bfx::Handle<bfx::LinkReservation>::operator=(this: (bfx::Handle<bfx::Space> *)&v31.m_obstacle, rhs: &v28);
  m_pProxy = result[9].m_pProxy;
  v30 = result + 9;
  v23 = result[11].m_pProxy;
  Node = bfx::Pool::GetNode(this: (bfx::Pool *)m_pProxy);
  v25 = Node;
  if ( Node != nullptr )
    bfx::MoverSpaceComponent::ObstacleRequestData::ObstacleRequestData(
      this: (bfx::MoverSpaceComponent::ObstacleRequestData *)Node,
      __that: &v31);
  v25[20].m_pNext = (bfx::Pool::Node *)v23;
  v25[21].m_pNext = *((bfx::Pool::Node **)&v23[10] + 1);
  v26 = v31.m_obstacle.m_pProxy;
  *(_DWORD *)(*((_DWORD *)&v23[10] + 1) + 80) = v25;
  *((_DWORD *)&v23[10] + 1) = v25;
  *(_DWORD *)HIDWORD(v8) = v26;
  if ( v26 != nullptr )
    *((_DWORD *)v26 + 1) = (unsigned __int8)*((_DWORD *)v26 + 1)
                         | ((*((_DWORD *)v26 + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
  v29 = 1;
  if ( v21 != nullptr )
    bfx::HandleProxy::RemRefToHandleProxy(this: v21);
  if ( v26 != nullptr )
    bfx::HandleProxy::RemRefToHandleProxy(this: v26);
  return (bfx::Handle<bfx::ObstacleImpl> *)HIDWORD(v8);
}


// ========================================================================
// __unwind$89559
// EA  : 0x8325A880
// RVA : 0x0125A880
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void _unwind_89559()
{
  int v0; // r12

  bfx::MoverSpaceComponent::ObstacleRequestData::~ObstacleRequestData(this: (bfx::MoverSpaceComponent::ObstacleRequestData *)(v0 - 240 + 96));
}


// ========================================================================
// __unwind$89561
// EA  : 0x8325A8A8
// RVA : 0x0125A8A8
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void _unwind_89561()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: (bfx::Handle<bfx::Space> *)(v0 - 240 + 80));
}


// ========================================================================
// __unwind$89562
// EA  : 0x8325A8D0
// RVA : 0x0125A8D0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void _unwind_89562()
{
  int v0; // r12
  int v1; // r31

  v1 = v0 - 240;
  if ( (*(_DWORD *)(v0 - 240 + 84) & 1) != 0 )
  {
    *(_DWORD *)(v1 + 84) &= ~1u;
    bfx::LinkConnectionData::~LinkConnectionData(this: *(bfx::Handle<bfx::Space> **)(v1 + 260));
  }
}


// ========================================================================
// ?UpdateAutoObstacles@MoverSpaceComponent@bfx@@AAAXM@Z
// EA  : 0x8325A920
// RVA : 0x0125A920
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void __fastcall bfx::MoverSpaceComponent::UpdateAutoObstacles(bfx::MoverSpaceComponent *this, double simTime)
{
  bfx::List<bfx::MoverSpaceComponent::ObstacleRequestData> *p_m_obstacleRequests; // r29
  bfx::List<bfx::MoverSpaceComponent::ObstacleRequestData>::Node *m_pNext; // r11
  float m_y; // r7
  float m_z; // r6
  float v7; // r4
  float v8; // r3
  bfx::HandleProxy *m_pProxy; // r11
  bfx::Pool::Node **v10; // r30
  bfx::HandleProxy *v11; // r3
  bfx::Pool *m_pPool; // r7
  bfx::ObstacleImpl *v13; // r3
  bfx::Vec3 v14; // [sp+60h] [-80h] BYREF
  bfx::Quat m_rot; // [sp+6Ch] [-74h] BYREF
  bfx::Vec3 v16; // [sp+7Ch] [-64h] BYREF
  bfx::ObstacleDat m_obstacleDat; // [sp+88h] [-58h] BYREF
  bfx::HandleProxy *v18; // [sp+A8h] [-38h]

  if ( simTime != 0.0 )
  {
    p_m_obstacleRequests = &this->m_obstacleRequests;
    if ( this->m_obstacleRequests.m_pEnd->m_pNext != this->m_obstacleRequests.m_pEnd )
    {
      while ( 1 )
      {
        m_pNext = this->m_obstacleRequests.m_pEnd->m_pNext;
        m_y = m_pNext->m_val.m_pos.m_y;
        m_z = m_pNext->m_val.m_pos.m_z;
        v14.m_x = m_pNext->m_val.m_pos.m_x;
        v14.m_y = m_y;
        v14.m_z = m_z;
        m_rot = m_pNext->m_val.m_rot;
        v7 = m_pNext->m_val.m_boxDimensions.m_y;
        v8 = m_pNext->m_val.m_boxDimensions.m_z;
        v16.m_x = m_pNext->m_val.m_boxDimensions.m_x;
        v16.m_y = v7;
        v16.m_z = v8;
        m_obstacleDat = m_pNext->m_val.m_obstacleDat;
        m_pProxy = m_pNext->m_val.m_obstacle.m_pProxy;
        v18 = m_pProxy;
        if ( m_pProxy != nullptr )
          *((_DWORD *)m_pProxy + 1) = (unsigned __int8)*((_DWORD *)m_pProxy + 1)
                                    | ((*((_DWORD *)m_pProxy + 1) & 0xFFFFFF00) + 256) & 0xFFFFFF00;
        v10 = (bfx::Pool::Node **)p_m_obstacleRequests->m_pEnd->m_pNext;
        v11 = (bfx::HandleProxy *)v10[18];
        if ( v11 != nullptr )
        {
          bfx::HandleProxy::RemRefToHandleProxy(this: v11);
          v10[18] = nullptr;
        }
        v10[21][20].m_pNext = v10[20];
        v10[20][21].m_pNext = v10[21];
        m_pPool = p_m_obstacleRequests->m_pPool;
        *v10 = p_m_obstacleRequests->m_pPool->m_data.m_pUnused;
        m_pPool->m_data.m_pUnused = (bfx::Pool::Node *)v10;
        if ( v18 != nullptr )
          break;
        if ( p_m_obstacleRequests->m_pEnd->m_pNext == p_m_obstacleRequests->m_pEnd )
          return;
      }
      v13 = bfx::Planner::CreateObstacle(
              this: *((bfx::Planner **)this->m_pSpace->m_components.m_data + 1),
              originalPos: &v14,
              rot: &m_rot,
              boxDimensions: &v16,
              origObstacleDat: &m_obstacleDat,
              replayID: 0);
      bfx::HandleProxy::ConnectToTarget(this: v18, pTarget: v13);
      if ( v18 != nullptr )
        bfx::HandleProxy::RemRefToHandleProxy(this: v18);
    }
  }
}


// ========================================================================
// __unwind$89763
// EA  : 0x8325AAB4
// RVA : 0x0125AAB4
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void _unwind_89763()
{
  int v0; // r12

  bfx::MoverSpaceComponent::ObstacleRequestData::~ObstacleRequestData(this: (bfx::MoverSpaceComponent::ObstacleRequestData *)(v0 - 224 + 96));
}


// ========================================================================
// ?EndOfFrame@MoverSpaceComponent@bfx@@UAAXM@Z
// EA  : 0x8325AAE0
// RVA : 0x0125AAE0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void __fastcall bfx::MoverSpaceComponent::EndOfFrame(bfx::MoverSpaceComponent *this, double simTime)
{
  bfx::Array<bfx::MoverImpl *> *p_m_movers; // r29
  int v5; // r31
  int v6; // r30

  p_m_movers = &this->m_movers;
  v5 = 0;
  if ( this->m_movers.m_size > 0 )
  {
    v6 = 0;
    do
    {
      p_m_movers->m_data[v6]->EndOfFrameUpdate(this: p_m_movers->m_data[v6], a2: simTime);
      ++v5;
      ++v6;
    }
    while ( v5 < p_m_movers->m_size );
  }
  bfx::MoverSpaceComponent::UpdateAutoObstacles(this, simTime);
  bfx::MoverSpaceComponent::LogMoverReplayPosRecords(this, simTime);
}


// ========================================================================
// ?CancelObstacleCreationRequest@MoverSpaceComponent@bfx@@QAAXV?$Handle@VObstacleImpl@bfx@@@2@@Z
// EA  : 0x8325AB70
// RVA : 0x0125AB70
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void __fastcall bfx::MoverSpaceComponent::CancelObstacleCreationRequest(
        bfx::MoverSpaceComponent *this,
        bfx::Handle<bfx::ObstacleImpl> *hObstacle)
{
  bfx::List<bfx::MoverSpaceComponent::ObstacleRequestData>::Node *m_pEnd; // r11
  bfx::List<bfx::MoverSpaceComponent::ObstacleRequestData>::Node *m_pNext; // r30
  bfx::HandleProxy *m_pProxy; // r3
  bfx::Pool *m_pPool; // r7

  m_pEnd = this->m_obstacleRequests.m_pEnd;
  m_pNext = m_pEnd->m_pNext;
  if ( m_pNext == m_pEnd )
  {
LABEL_4:
    if ( hObstacle->m_pProxy != nullptr )
    {
      bfx::HandleProxy::RemRefToHandleProxy(this: hObstacle->m_pProxy);
      hObstacle->m_pProxy = nullptr;
    }
  }
  else
  {
    while ( m_pNext->m_val.m_obstacle.m_pProxy != hObstacle->m_pProxy )
    {
      m_pNext = m_pNext->m_pNext;
      if ( m_pNext == m_pEnd )
        goto LABEL_4;
    }
    m_pProxy = m_pNext->m_val.m_obstacle.m_pProxy;
    if ( m_pProxy != nullptr )
    {
      bfx::HandleProxy::RemRefToHandleProxy(this: m_pProxy);
      m_pNext->m_val.m_obstacle.m_pProxy = nullptr;
    }
    m_pNext->m_pPrev->m_pNext = m_pNext->m_pNext;
    m_pNext->m_pNext->m_pPrev = m_pNext->m_pPrev;
    m_pPool = this->m_obstacleRequests.m_pPool;
    LODWORD(m_pNext->m_val.m_pos.m_x) = m_pPool->m_data.m_pUnused;
    m_pPool->m_data.m_pUnused = (bfx::Pool::Node *)m_pNext;
    if ( hObstacle->m_pProxy != nullptr )
    {
      bfx::HandleProxy::RemRefToHandleProxy(this: hObstacle->m_pProxy);
      hObstacle->m_pProxy = nullptr;
    }
  }
}


// ========================================================================
// __unwind$90037
// EA  : 0x8325AC38
// RVA : 0x0125AC38
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void _unwind_90037()
{
  int v0; // r12

  bfx::LinkConnectionData::~LinkConnectionData(this: *(bfx::Handle<bfx::Space> **)(v0 - 144 + 172));
}


// ========================================================================
// bfx::`dynamic initializer for 'g_colorizeMoversRestore''
// EA  : 0x833982C0
// RVA : 0x013982C0
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxmoversystem.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_colorizeMoversRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_colorizeMoversRestore);
  bfx::g_colorizeMoversRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_colorizeMoversRestore.m_targetBool = &bfx::g_colorizeMovers;
  bfx::g_colorizeMoversRestore.m_name = "colorize_all_movers";
  bfx::g_colorizeMoversRestore.m_defaultBool = bfx::g_colorizeMovers;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_colorizeMoversRestore__);
}

