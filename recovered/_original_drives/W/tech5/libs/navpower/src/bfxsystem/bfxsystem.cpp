
// ========================================================================
// ??0Quaternion@bfx@@QAA@ABVVector3@1@00@Z
// EA  : 0x8324BE88
// RVA : 0x0124BE88
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

bfx::Quaternion *__fastcall bfx::Quaternion::Quaternion(
        bfx::Quaternion *this,
        const bfx::Vector3 *forwAxisIn,
        const bfx::Vector3 *leftAxisIn,
        const bfx::Vector3 *upAxisIn)
{
  double m_y; // fp10
  double v5; // fp8
  double m_z; // fp5
  double v7; // fp4
  double m_x; // fp2
  double v14; // fp11
  double v15; // fp6
  double v16; // fp5
  double v17; // fp4
  double v18; // fp3
  double v19; // fp2
  double v20; // fp1
  double v21; // fp7
  double v22; // fp5
  double v23; // fp4
  double v26; // fp3
  double v27; // fp2
  double v30; // fp0
  double v32; // fp13
  double v33; // fp12
  bfx::Vec3 v34; // [sp+50h] [-90h] BYREF
  bfx::Vec3 v35; // [sp+60h] [-80h] BYREF
  bfx::Vec3 v36; // [sp+70h] [-70h] BYREF
  bfx::Quat v37; // [sp+80h] [-60h] BYREF
  bfx::Matrix v38; // [sp+90h] [-50h] BYREF

  m_y = forwAxisIn->m_y;
  v5 = leftAxisIn->m_y;
  m_z = forwAxisIn->m_z;
  v7 = leftAxisIn->m_z;
  m_x = leftAxisIn->m_x;
  _FP11 = (float)((float)__fsqrts((float)((float)(forwAxisIn->m_x * forwAxisIn->m_x)
                                        + (float)((float)(forwAxisIn->m_z * forwAxisIn->m_z)
                                                + (float)(forwAxisIn->m_y * forwAxisIn->m_y))))
                - (float)1.0842022e-19);
  _FP7 = (float)((float)__fsqrts((float)((float)(leftAxisIn->m_x * leftAxisIn->m_x)
                                       + (float)((float)(leftAxisIn->m_z * leftAxisIn->m_z)
                                               + (float)(leftAxisIn->m_y * leftAxisIn->m_y))))
               - (float)1.0842022e-19);
  __asm
  {
    fsel      f1, f11, f9, f12
    fsel      f7, f7, f6, f12
  }
  v14 = (float)((float)_FP1 * forwAxisIn->m_x);
  v34.m_x = (float)_FP1 * forwAxisIn->m_x;
  v34.m_z = (float)m_z * (float)_FP1;
  v15 = (float)((float)v7 * (float)_FP7);
  v34.m_y = (float)m_y * (float)_FP1;
  v16 = (float)((float)_FP7 * (float)m_x);
  v18 = (float)((float)((float)v7 * (float)_FP7) * (float)v14);
  v17 = (float)((float)v5 * (float)_FP7);
  v19 = (float)(v34.m_y * (float)((float)_FP7 * (float)m_x));
  v20 = (float)((float)((float)v5 * (float)_FP7) * v34.m_z);
  v21 = (float)((float)(v34.m_z * (float)v16) - (float)v18);
  v22 = (float)((float)((float)v17 * (float)v14) - (float)v19);
  v23 = (float)((float)((float)v15 * v34.m_y) - (float)v20);
  _FP6 = (float)((float)__fsqrts((float)((float)((float)v23 * (float)v23)
                                       + (float)((float)((float)v22 * (float)v22) + (float)((float)v21 * (float)v21))))
               - (float)1.0842022e-19);
  __asm { fsel      f2, f6, f3, f12 }
  v35.m_x = (float)v23 * (float)_FP2;
  v35.m_z = (float)v22 * (float)_FP2;
  v35.m_y = (float)v21 * (float)_FP2;
  v26 = (float)((float)(v35.m_z * (float)v14) - (float)(v34.m_z * v35.m_x));
  v27 = (float)((float)(v35.m_x * v34.m_y) - (float)(v35.m_y * (float)v14));
  _FP7 = (float)((float)__fsqrts((float)((float)((float)((float)(v35.m_y * v34.m_z) - (float)(v35.m_z * v34.m_y))
                                               * (float)((float)(v35.m_y * v34.m_z) - (float)(v35.m_z * v34.m_y)))
                                       + (float)((float)((float)v27 * (float)v27) + (float)((float)v26 * (float)v26))))
               - (float)1.0842022e-19);
  __asm { fsel      f5, f7, f6, f12 }
  v36.m_x = (float)((float)(v35.m_y * v34.m_z) - (float)(v35.m_z * v34.m_y)) * (float)_FP5;
  v36.m_y = (float)((float)(v35.m_z * (float)v14) - (float)(v34.m_z * v35.m_x)) * (float)_FP5;
  v36.m_z = (float)((float)(v35.m_x * v34.m_y) - (float)(v35.m_y * (float)v14)) * (float)_FP5;
  bfx::Matrix::Build(this: &v38, xAxis: &v34, yAxis: &v36, zAxis: &v35, trans: &bfx::ZERO_VEC);
  bfx::Quat::Quat(this: &v37, m: &v38);
  v30 = v37.m_x;
  v32 = v37.m_y;
  v33 = v37.m_z;
  this->m_w = v37.m_w;
  this->m_x = v30;
  this->m_y = v32;
  this->m_z = v33;
  return this;
}


// ========================================================================
// ?SetCollider@bfx@@YAXPAVCollider@1@@Z
// EA  : 0x8324C020
// RVA : 0x0124C020
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

void __fastcall bfx::SetCollider(bfx::Collider *pCollider)
{
  bfx::SystemInstance *v2; // r11
  bfx::APICriticalSection *m_pGlobalCS; // r31

  v2 = bfx::g_pCurInstance;
  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
  {
    RtlEnterCriticalSection(CriticalSection: &bfx::g_pCurInstance->m_pGlobalCS->m_criticalSection);
    v2 = bfx::g_pCurInstance;
  }
  v2->m_pColliderManager->m_pCollider = pCollider;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// ?SetGlobalDebugFlag@bfx@@YAXW4SystemDebugFlag@1@_N@Z
// EA  : 0x8324C070
// RVA : 0x0124C070
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

void __fastcall bfx::SetGlobalDebugFlag(unsigned int flag, bool enable)
{
  if ( flag != 0 )
  {
    if ( flag == 1 )
    {
      bfx::g_pCurInstance->m_pDebugOptions->m_drawMemory = enable;
    }
    else if ( flag < 3 )
    {
      bfx::g_pCurInstance->m_pDebugOptions->m_drawTimings = enable;
    }
  }
  else
  {
    bfx::g_pCurInstance->m_pDebugOptions->m_drawStats = enable;
  }
}


// ========================================================================
// ?SetGlobalDebugFlag@bfx@@YAXW4SystemSpaceDebugFlag@1@_N@Z
// EA  : 0x8324C0C0
// RVA : 0x0124C0C0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

void __fastcall bfx::SetGlobalDebugFlag(bfx::SystemSpaceDebugFlag flag, bool enable)
{
  if ( flag == BFX_DRAW_SPACE_AXES )
    bfx::g_pCurInstance->m_pDebugOptions->m_drawSpaceAxes = enable;
}


// ========================================================================
// ?DrawMemStats@bfx@@YAXXZ
// EA  : 0x8324C0E0
// RVA : 0x0124C0E0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

void __fastcall bfx::DrawMemStats(bfx *this)
{
  __int64 v1; // r21
  __int64 v2; // r10
  __int64 v3; // r8
  __int64 v4; // r6
  __int64 v5; // r4
  __int64 v6; // r10
  __int64 v7; // r6
  __int64 v8; // r8
  unsigned int TagStats; // r31
  __int64 v10; // r10
  __int64 v11; // r8
  __int64 v12; // r6
  __int64 v13; // r4
  __int64 v14; // r10
  int v15; // r30
  unsigned int v16; // r26
  int v17; // r29
  unsigned int v18; // r22
  int v19; // r27
  unsigned int v20; // r31
  int v21; // r25
  int v22; // r28
  int v23; // r23
  const bfx::MemoryManager::TagInfo *v24; // r11
  __int64 v25; // r8
  __int64 v26; // r10
  __int64 v27; // r4
  __int64 v28; // r6
  __int64 v29; // r4
  int v30; // [sp+8h] [-E8h]
  int v31; // [sp+8h] [-E8h]
  int v32; // [sp+8h] [-E8h]
  int v33; // [sp+8h] [-E8h]
  int v34; // [sp+Ch] [-E4h]
  int v35; // [sp+Ch] [-E4h]
  int v36; // [sp+Ch] [-E4h]
  int v37; // [sp+Ch] [-E4h]
  int v38; // [sp+10h] [-E0h]
  int v39; // [sp+10h] [-E0h]
  int v40; // [sp+10h] [-E0h]
  int v41; // [sp+10h] [-E0h]
  int v42; // [sp+14h] [-DCh]
  int v43; // [sp+14h] [-DCh]
  int v44; // [sp+14h] [-DCh]
  int v45; // [sp+14h] [-DCh]
  unsigned int v46; // [sp+50h] [-A0h] BYREF
  unsigned int v47; // [sp+54h] [-9Ch] BYREF
  const bfx::MemoryManager::TagInfo *v48; // [sp+58h] [-98h] BYREF
  const char *const *v49; // [sp+5Ch] [-94h] BYREF
  unsigned int v50[4]; // [sp+60h] [-90h] BYREF
  __int64 v51; // [sp+70h] [-80h]
  __int64 v52; // [sp+78h] [-78h]
  __int64 v53; // [sp+80h] [-70h]

  if ( bfx::MemoryManager::GetStats(
         this: bfx::g_pCurInstance->m_pMemoryManager,
         allocatedBytes: &v46,
         freeBytes: v50,
         totalBytes: &v47) )
  {
    HIDWORD(v5) = "--- Memory Usage Data ---\n";
    bfx::DrawString(fmt: v5, a2: v4, a3: v3, a4: v2, a5: v30, a6: v34, a7: v38, a8: v42);
    LODWORD(v6) = &unk_82410000;
    HIDWORD(v7) = v46;
    bfx::DrawString(
      fmt: __SPAIR64__("memory: total = %u, allocated = %u\n", v47),
      a2: v7,
      a3: v8,
      a4: v6,
      a5: v31,
      a6: v35,
      a7: v39,
      a8: v43);
    TagStats = bfx::MemoryManager::GetTagStats(
                 this: bfx::g_pCurInstance->m_pMemoryManager,
                 tagLabels: &v49,
                 tagInfo: &v48);
    if ( TagStats != 0 )
    {
      LODWORD(v1) = 0;
      LODWORD(v10) = byte_821B0000;
      HIDWORD(v13) = "\n";
      v51 = v1;
      v52 = v1;
      v53 = v1;
      bfx::DrawString(fmt: v13, a2: v12, a3: v11, a4: v10, a5: v32, a6: v36, a7: v40, a8: v44);
      v15 = HIDWORD(v52);
      v16 = HIDWORD(v51);
      v17 = v53;
      v18 = TagStats;
      v19 = HIDWORD(v53);
      v20 = v52;
      v21 = 0;
      v22 = v51;
      v23 = 0;
      do
      {
        v24 = &v48[v23];
        LODWORD(v25) = v48[v23].m_bytesAllocPeak;
        if ( (_DWORD)v25 != 0 )
        {
          v17 += v25;
          v22 += v24->m_countTotal;
          v26 = *(_QWORD *)&v24->m_bytesUsed;
          v16 += v24->m_countActive;
          v20 += v26;
          v15 += HIDWORD(v26);
          v19 += v24->m_bytesUsedPeak;
          if ( (_DWORD)v26 != 0 )
          {
            HIDWORD(v26) = v26 - HIDWORD(v26);
            __twllei(v26, 0);
            HIDWORD(v25) = 100 * HIDWORD(v26) / (unsigned int)v26;
          }
          else
          {
            HIDWORD(v25) = 0;
          }
          LODWORD(v26) = v49;
          HIDWORD(v27) = " %-12s:  ct=%5u   alloc=%9u   dbg=%2u%%   pk=%9u\n";
          LODWORD(v28) = v24->m_bytesAlloc;
          *((const char **)&v27 + 1) = v49[v21];
          HIDWORD(v28) = v24->m_countActive;
          bfx::DrawString(fmt: v27, a2: v28, a3: v25, a4: v26, a5: v33, a6: v37, a7: v41, a8: v45);
        }
        --v18;
        ++v23;
        ++v21;
      }
      while ( v18 != 0 );
      if ( v20 != 0 )
      {
        __twllei(v20, 0);
        HIDWORD(v25) = 100 * (v20 - v15) / v20;
      }
      else
      {
        HIDWORD(v25) = 0;
      }
      LODWORD(v14) = &unk_82410000;
      LODWORD(v29) = "ALL";
      HIDWORD(v29) = " %12s:  ct=%5u   alloc=%9u   dbg=%2u%%\n";
      bfx::DrawString(fmt: v29, a2: __SPAIR64__(v16, v20), a3: v25, a4: v14, a5: v33, a6: v37, a7: v41, a8: v45);
    }
  }
  else
  {
    HIDWORD(v5) = "Memory statistics not available when using custom allocator\n";
    bfx::DrawString(fmt: v5, a2: v4, a3: v3, a4: v2, a5: v30, a6: v34, a7: v38, a8: v42);
  }
}


// ========================================================================
// ?SetWarningLog@bfx@@YAXPAVLogDevice@1@@Z
// EA  : 0x8324C290
// RVA : 0x0124C290
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

void __fastcall bfx::SetWarningLog(bfx::LogDevice *pLogDevice)
{
  bfx::SystemInstance *v2; // r11
  bfx::APICriticalSection *m_pGlobalCS; // r31

  v2 = bfx::g_pCurInstance;
  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
  {
    RtlEnterCriticalSection(CriticalSection: &bfx::g_pCurInstance->m_pGlobalCS->m_criticalSection);
    v2 = bfx::g_pCurInstance;
  }
  v2->m_pWarningLog = pLogDevice;
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// ?StartReplayRecording@bfx@@YA_NPAVLogDevice@1@_N1@Z
// EA  : 0x8324C2E0
// RVA : 0x0124C2E0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

BOOL __fastcall bfx::StartReplayRecording(bfx::LogDevice *pReplayLog, bool binaryOut, bool omitMoverLogging)
{
  return bfx::g_pCurInstance->m_pReplayRecorder != nullptr
      && !bfx::ReplayRecorder::IsOn(this: bfx::g_pCurInstance->m_pReplayRecorder)
      && bfx::ReplayRecorder::Start(
           this: bfx::g_pCurInstance->m_pReplayRecorder,
           pLogDevice: pReplayLog,
           binaryOut,
           omitMoverLogging);
}


// ========================================================================
// ?StopReplayRecording@bfx@@YA_NXZ
// EA  : 0x8324C350
// RVA : 0x0124C350
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

int __fastcall bfx::StopReplayRecording()
{
  if ( bfx::g_pCurInstance->m_pReplayRecorder == nullptr
    || !bfx::ReplayRecorder::IsOn(this: bfx::g_pCurInstance->m_pReplayRecorder) )
  {
    return 0;
  }
  bfx::ReplayRecorder::Stop(this: bfx::g_pCurInstance->m_pReplayRecorder);
  return 1;
}


// ========================================================================
// ?SystemStart@bfx@@YAXXZ
// EA  : 0x8324C3D0
// RVA : 0x0124C3D0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

void __fastcall bfx::SystemStart(bfx *this)
{
  bfx::SystemInstance *v1; // r3
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  v1 = bfx::g_pCurInstance;
  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
  {
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    v1 = bfx::g_pCurInstance;
  }
  bfx::SystemInstance::Start(this: v1);
  bfx::ComponentManager::StartComponents(this: bfx::g_pCurInstance->m_pComponentManager);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$76094
// EA  : 0x8324C42C
// RVA : 0x0124C42C
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

void _unwind_76094()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?SystemStart@bfx@@YAXAAVReplaySpec@1@@Z
// EA  : 0x8324C460
// RVA : 0x0124C460
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

void __fastcall bfx::SystemStart(bfx::ReplaySpec *replaySpec)
{
  bfx::SystemInstance *v2; // r3
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  v2 = bfx::g_pCurInstance;
  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
  {
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    v2 = bfx::g_pCurInstance;
  }
  bfx::SystemInstance::Start(this: v2);
  bfx::ComponentManager::StartComponents(this: bfx::g_pCurInstance->m_pComponentManager);
  if ( replaySpec->m_pLog != nullptr )
    bfx::StartReplayRecording(
      pReplayLog: replaySpec->m_pLog,
      binaryOut: replaySpec->m_binaryOut,
      omitMoverLogging: replaySpec->m_omitMoverLogging);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$76134
// EA  : 0x8324C4D8
// RVA : 0x0124C4D8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

void _unwind_76134()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?DisableDefaultSpace@bfx@@YAXXZ
// EA  : 0x8324C500
// RVA : 0x0124C500
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

void __fastcall bfx::DisableDefaultSpace(bfx *this)
{
  bfx::SpaceManager::DisableDefaultSpace(this: bfx::g_pCurInstance->m_pSpaceManager);
}


// ========================================================================
// ?OutOfMemoryCrash@bfx@@YAXXZ
// EA  : 0x8324C510
// RVA : 0x0124C510
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

void __fastcall bfx::OutOfMemoryCrash(__int64 this, __int64 a2, __int64 a3, __int64 a4)
{
  int v4; // [sp+8h] [-58h]
  int v5; // [sp+Ch] [-54h]
  int v6; // [sp+10h] [-50h]
  int v7; // [sp+14h] [-4Ch]

  HIDWORD(this) = "System ran out of available heap memory and will crash\n";
  bfx::InternalWarning(fmt: this, a2, a3, a4, a5: v4, a6: v5, a7: v6, a8: v7);
  __trap();
  MEMORY[0] = 0;
}


// ========================================================================
// ?GetTime@bfx@@YAMXZ
// EA  : 0x8324C548
// RVA : 0x0124C548
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

float __fastcall bfx::GetTime()
{
  double m_time; // fp1

  m_time = bfx::g_pCurInstance->m_time;
  return *((float *)&m_time + 1);
}


// ========================================================================
// ?CreateSimulateTask@bfx@@YAPAVTask@1@M@Z
// EA  : 0x8324C560
// RVA : 0x0124C560
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

bfx::Task *__fastcall bfx::CreateSimulateTask(double simTime)
{
  bfx::HandleProxy *v2; // r3
  bfx::HandleProxy *v3; // r28
  int v4; // r9
  bfx::Task *v5; // r3
  bfx::Task *v6; // r30

  v2 = (bfx::HandleProxy *)bfx::MemoryManager::Malloc(
                             this: bfx::g_pCurInstance->m_pMemoryManager,
                             size: 8u,
                             tag: bfx::MEM_BFXSYSTEM);
  if ( v2 != nullptr )
  {
    v3 = v2;
    v4 = *((_BYTE *)v2 + 7) & 3;
    v2->m_pTarget = nullptr;
    *((_DWORD *)v2 + 1) = v4;
  }
  else
  {
    v3 = nullptr;
  }
  v5 = (bfx::Task *)bfx::MemoryManager::Malloc(
                      this: bfx::g_pCurInstance->m_pMemoryManager,
                      size: 0xCu,
                      tag: bfx::MEM_BFXSYSTEM);
  v6 = v5;
  if ( v5 == nullptr )
    return nullptr;
  bfx::Task::Task(this: v5, pProxy: v3);
  *(float *)&v6[1].__vftable = simTime;
  v6->__vftable = (bfx::Task_vtbl *)&bfx::SimulateTask::`vftable';
  return v6;
}


// ========================================================================
// __unwind$76209
// EA  : 0x8324C610
// RVA : 0x0124C610
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

void _unwind_76209()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 144 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?SystemStop@bfx@@YAXXZ
// EA  : 0x8324C648
// RVA : 0x0124C648
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

void __fastcall bfx::SystemStop(__int64 this, __int64 a2, __int64 a3)
{
  bfx::SystemInstance *v3; // r11
  __int64 v4; // r10
  bfx *v5; // r3
  bfx::SpaceHandle *DefaultSpaceHandle; // r3
  int v7; // [sp+8h] [-78h]
  int v8; // [sp+Ch] [-74h]
  int v9; // [sp+10h] [-70h]
  int v10; // [sp+14h] [-6Ch]
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  v3 = bfx::g_pCurInstance;
  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
  {
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
    v3 = bfx::g_pCurInstance;
  }
  LODWORD(v4) = v3->m_pComponentManager;
  HIDWORD(v4) = *(_DWORD *)(v4 + 32);
  if ( HIDWORD(v4) == 1 )
  {
    v3->m_pSystemMCore->ProcessAllTasks(this: v3->m_pSystemMCore);
    v5 = (bfx *)bfx::StopReplayRecording();
    bfx::StopReplayPlayback(this: v5);
    bfx::ComponentManager::StopComponents(this: bfx::g_pCurInstance->m_pComponentManager);
    DefaultSpaceHandle = bfx::SystemInstance::GetDefaultSpaceHandle(this: bfx::g_pCurInstance);
    bfx::VolumeHandle::Release(this: DefaultSpaceHandle);
  }
  else
  {
    HIDWORD(this) = "SystemStop() called without the system running. Ignoring.\n";
    bfx::InternalWarning(fmt: this, a2, a3, a4: v4, a5: v7, a6: v8, a7: v9, a8: v10);
  }
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$76238
// EA  : 0x8324C6E8
// RVA : 0x0124C6E8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

void _unwind_76238()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?SetCurrentInstance@bfx@@YAXPAVInstance@1@@Z
// EA  : 0x8324C710
// RVA : 0x0124C710
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

void __fastcall bfx::SetCurrentInstance(bfx::SystemInstance *pInstance)
{
  bfx::g_pCurInstance = pInstance;
}


// ========================================================================
// ?CoreSystemSimulate@bfx@@YAXM@Z
// EA  : 0x8324C788
// RVA : 0x0124C788
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

void __fastcall bfx::CoreSystemSimulate(double simTime)
{
  _RTL_CRITICAL_SECTION *p_m_criticalSection; // r29
  bfx::SpaceManager *m_pSpaceManager; // r3
  bfx::FTimerOb v4; // [sp+50h] [-30h] BYREF
  bfx::APICriticalSection *m_pGlobalCS; // [sp+54h] [-2Ch]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  p_m_criticalSection = &m_pGlobalCS->m_criticalSection;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogCoreSystemSimulate(simTime);
  bfx::FTimerOb::FTimerOb(this: &v4, timerEntry: &bfx::systemSimulateTimer);
  m_pSpaceManager = bfx::g_pCurInstance->m_pSpaceManager;
  bfx::g_pCurInstance->m_time = (float)simTime + bfx::g_pCurInstance->m_time;
  bfx::SpaceManager::Simulate(this: m_pSpaceManager, simTime);
  if ( v4.m_pFTimer != nullptr )
    bfx::FTimer::Stop(this: v4.m_pFTimer);
  if ( p_m_criticalSection != nullptr )
    RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
}


// ========================================================================
// __unwind$76526
// EA  : 0x8324C820
// RVA : 0x0124C820
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

void _unwind_76526()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 84));
}


// ========================================================================
// __unwind$76527
// EA  : 0x8324C848
// RVA : 0x0124C848
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

void _unwind_76527()
{
  int v0; // r12

  bfx::FTimerOb::~FTimerOb(this: (bfx::FTimerOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?SystemSimulate@bfx@@YAXM@Z
// EA  : 0x8324C878
// RVA : 0x0124C878
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

void __fastcall bfx::SystemSimulate(double simTime)
{
  bfx::Task *SimulateTask; // r3
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogSystemSimulate(simTime);
  if ( bfx::g_pCurInstance->m_pSystemMCore->IsAsyncEnabled(this: bfx::g_pCurInstance->m_pSystemMCore) )
  {
    SimulateTask = bfx::CreateSimulateTask(simTime);
    bfx::g_pCurInstance->m_pSystemMCore->AddTask(this: bfx::g_pCurInstance->m_pSystemMCore, a2: SimulateTask);
  }
  else
  {
    bfx::CoreSystemSimulate(simTime);
  }
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::g_pCurInstance->m_pSystemMCore->ProcessAllTasks(this: bfx::g_pCurInstance->m_pSystemMCore);
  bfx::g_pCurInstance->m_pSystemMCore->CallSimDoneCallback(this: bfx::g_pCurInstance->m_pSystemMCore);
}


// ========================================================================
// __unwind$76574
// EA  : 0x8324C954
// RVA : 0x0124C954
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

void _unwind_76574()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}


// ========================================================================
// ?Process@SimulateTask@bfx@@UAAXXZ
// EA  : 0x8324CA08
// RVA : 0x0124CA08
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

void __fastcall bfx::SimulateTask::Process(bfx::SimulateTask *this)
{
  bfx::CoreSystemSimulate(simTime: this->m_simTime);
}


// ========================================================================
// ?Draw@DefaultWarningLog@bfx@@QAAXXZ
// EA  : 0x8324CA10
// RVA : 0x0124CA10
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

void __fastcall bfx::DefaultWarningLog::Draw(bfx::DefaultWarningLog *this, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  bfx::Array<bfx::TextLine> *p_m_lines; // r31
  bfx::Array<bfx::TextLine> *v7; // r29
  int v8; // r31
  int v9; // r30
  __int64 v10; // r4
  int v11; // [sp+8h] [-78h]
  int v12; // [sp+Ch] [-74h]
  int v13; // [sp+10h] [-70h]
  int v14; // [sp+14h] [-6Ch]

  if ( this->m_lines.m_size != 0 )
  {
    p_m_lines = &this->m_lines;
    do
    {
      if ( bfx::g_pCurInstance->m_time <= (double)(float)(p_m_lines->m_data->m_startTime + (float)5.0) )
        break;
      bfx::Array<bfx::TextLine>::erase(this: p_m_lines, ptr: p_m_lines->m_data);
    }
    while ( this->m_lines.m_size != 0 );
  }
  v7 = &this->m_lines;
  v8 = 0;
  if ( this->m_lines.m_size > 0 )
  {
    v9 = 0;
    do
    {
      HIDWORD(v10) = "NavPower Warning: %s";
      LODWORD(v10) = v7->m_data[v9].m_text.m_data;
      bfx::DrawString(fmt: v10, a2: a3, a3: a4, a4: a5, a5: v11, a6: v12, a7: v13, a8: v14);
      LODWORD(a5) = v7->m_size;
      ++v8;
      ++v9;
    }
    while ( v8 < (int)a5 );
  }
}


// ========================================================================
// ?SystemDraw@bfx@@YAXPBVDrawCullParams@1@@Z
// EA  : 0x8324CAC8
// RVA : 0x0124CAC8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

void __fastcall bfx::SystemDraw(const bfx::DrawCullParams *pDrawCullParams)
{
  _RTL_CRITICAL_SECTION *p_m_criticalSection; // r28
  bfx *v3; // r3
  __int64 v4; // r8
  __int64 v5; // r6
  int v6; // r4
  bfx *v7; // r3
  bfx::SystemInstance *v8; // r11
  __int64 v9; // r10
  bfx *v10; // r3
  bfx *v11; // r3
  bfx::FTimerOb v12; // [sp+50h] [-30h] BYREF
  bfx::APICriticalSection *m_pGlobalCS; // [sp+54h] [-2Ch]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  p_m_criticalSection = &m_pGlobalCS->m_criticalSection;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogSystemDraw(pDrawCullParams);
  v3 = (bfx *)bfx::FTimerOb::FTimerOb(this: &v12, timerEntry: &bfx::systemDrawTimer);
  bfx::BeginScene(this: v3);
  v8 = bfx::g_pCurInstance;
  LODWORD(v9) = bfx::g_pCurInstance->m_pDefaultWarningLog;
  if ( (_DWORD)v9 != 0 )
  {
    HIDWORD(v9) = bfx::g_pCurInstance->m_pWarningLog;
    if ( HIDWORD(v9) == (_DWORD)v9 )
    {
      bfx::DefaultWarningLog::Draw(this: bfx::g_pCurInstance->m_pDefaultWarningLog, a2: v6, a3: v5, a4: v4, a5: v9);
      v8 = bfx::g_pCurInstance;
    }
  }
  if ( v8->m_pDebugOptions->m_drawMemory )
  {
    bfx::DrawMemStats(this: v7);
    v8 = bfx::g_pCurInstance;
  }
  bfx::ComponentManager::DrawComponents(this: v8->m_pComponentManager);
  bfx::SpaceManager::Draw(this: bfx::g_pCurInstance->m_pSpaceManager, pDrawCullParams);
  if ( bfx::g_pCurInstance->m_pDebugOptions->m_drawTimings )
    v10 = (bfx *)((int (__fastcall *)(bfx::TimerManager *))bfx::g_pCurInstance->m_pTimerManager->DrawFrameTimers)(a1: bfx::g_pCurInstance->m_pTimerManager);
  bfx::DrawCachedPrims(this: v10);
  bfx::EndScene(this: v11);
  if ( v12.m_pFTimer != nullptr )
    bfx::FTimer::Stop(this: v12.m_pFTimer);
  if ( p_m_criticalSection != nullptr )
    RtlLeaveCriticalSection(CriticalSection: p_m_criticalSection);
}


// ========================================================================
// __unwind$76969
// EA  : 0x8324CBC8
// RVA : 0x0124CBC8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

void _unwind_76969()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 84));
}


// ========================================================================
// __unwind$76970
// EA  : 0x8324CBF0
// RVA : 0x0124CBF0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

void _unwind_76970()
{
  int v0; // r12

  bfx::FTimerOb::~FTimerOb(this: (bfx::FTimerOb *)(v0 - 128 + 80));
}


// ========================================================================
// bfx::`dynamic initializer for 'systemDrawTimer''
// EA  : 0x83398098
// RVA : 0x01398098
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__systemDrawTimer__()
{
  int v0; // r9

  v0 = bfx::g_nextFTimerEntryID;
  bfx::systemDrawTimer.m_pNext = bfx::g_pFTimerEntryHead;
  bfx::systemDrawTimer.m_timerID = bfx::g_nextFTimerEntryID;
  if ( bfx::g_pFTimerEntryHead != nullptr )
  {
    bfx::g_pFTimerEntryHead->m_pPrev = &bfx::systemDrawTimer;
    v0 = bfx::g_nextFTimerEntryID;
  }
  bfx::g_pFTimerEntryHead = &bfx::systemDrawTimer;
  bfx::g_nextFTimerEntryID = v0 + 1;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__systemDrawTimer__);
}


// ========================================================================
// bfx::`dynamic initializer for 'systemSimulateTimer''
// EA  : 0x833980E0
// RVA : 0x013980E0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystem.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__systemSimulateTimer__()
{
  int v0; // r9

  v0 = bfx::g_nextFTimerEntryID;
  bfx::systemSimulateTimer.m_pNext = bfx::g_pFTimerEntryHead;
  bfx::systemSimulateTimer.m_timerID = bfx::g_nextFTimerEntryID;
  if ( bfx::g_pFTimerEntryHead != nullptr )
  {
    bfx::g_pFTimerEntryHead->m_pPrev = &bfx::systemSimulateTimer;
    v0 = bfx::g_nextFTimerEntryID;
  }
  bfx::g_pFTimerEntryHead = &bfx::systemSimulateTimer;
  bfx::g_nextFTimerEntryID = v0 + 1;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__systemSimulateTimer__);
}

