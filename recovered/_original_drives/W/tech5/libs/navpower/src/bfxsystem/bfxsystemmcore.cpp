
// ========================================================================
// ?SystemMCoreDeleteTaskForProxy@bfx@@YAXPAVHandleProxy@1@@Z
// EA  : 0x8325EE70
// RVA : 0x0125EE70
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystemmcore.cpp
// ========================================================================

void __fastcall bfx::SystemMCoreDeleteTaskForProxy(bfx::HandleProxy *pProxy)
{
  bfx::g_pCurInstance->m_pSystemMCore->DeleteTaskForProxy(this: bfx::g_pCurInstance->m_pSystemMCore, a2: pProxy);
}


// ========================================================================
// ?EnableAsyncSimulation@bfx@@YAX_N@Z
// EA  : 0x8325EE98
// RVA : 0x0125EE98
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystemmcore.cpp
// ========================================================================

void __fastcall bfx::EnableAsyncSimulation(BOOL enable)
{
  bfx::APICriticalSection *m_pGlobalCS; // [sp+50h] [-30h]

  m_pGlobalCS = bfx::g_pCurInstance->m_pGlobalCS;
  if ( m_pGlobalCS != nullptr )
    RtlEnterCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
  bfx::LogEnableAsyncSimulation(enable);
  bfx::g_pCurInstance->m_pSystemMCore->EnableAsync(this: bfx::g_pCurInstance->m_pSystemMCore, a2: enable);
  if ( m_pGlobalCS != nullptr )
    RtlLeaveCriticalSection(CriticalSection: &m_pGlobalCS->m_criticalSection);
}


// ========================================================================
// __unwind$69144
// EA  : 0x8325EF08
// RVA : 0x0125EF08
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxsystemmcore.cpp
// ========================================================================

void _unwind_69144()
{
  int v0; // r12

  bfx::CriticalSectionOb::~CriticalSectionOb(this: (bfx::CriticalSectionOb *)(v0 - 128 + 80));
}

