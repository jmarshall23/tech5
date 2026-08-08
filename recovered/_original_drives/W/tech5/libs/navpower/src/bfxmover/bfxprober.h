
// ========================================================================
// ??3SimulateTask@bfx@@SAXPAXW4bfxMemHeap@1@@Z
// EA  : 0x832AE018
// RVA : 0x012AE018
// PDB : w:\tech5\libs\navpower\src\bfxmover\bfxprober.h
// ========================================================================

void __fastcall bfx::SimulateTask::operator delete(char *ptr, bfx::bfxMemHeap __formal)
{
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr);
}

