
// ========================================================================
// ?Start@SystemInstance@bfx@@QAAXXZ
// EA  : 0x8326D608
// RVA : 0x0126D608
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxinstance.cpp
// ========================================================================

void __fastcall bfx::SystemInstance::Start(bfx::SystemInstance *this)
{
  bfx::SpaceManager *v2; // r3

  v2 = (bfx::SpaceManager *)bfx::MemoryManager::Malloc(
                              this: bfx::g_pCurInstance->m_pMemoryManager,
                              size: 0x28u,
                              tag: bfx::MEM_BFXSYSTEM);
  if ( v2 != nullptr )
    this->m_pSpaceManager = bfx::SpaceManager::SpaceManager(this: v2);
  else
    this->m_pSpaceManager = nullptr;
}


// ========================================================================
// __unwind$74286
// EA  : 0x8326D678
// RVA : 0x0126D678
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxinstance.cpp
// ========================================================================

void _unwind_74286()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 112 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?GetCachedSize@MapWarning@idreports@@UBAHXZ
// EA  : 0x8326D6A8
// RVA : 0x0126D6A8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxinstance.cpp
// ========================================================================

bfx::AdditionalSystemInstanceData *__fastcall idreports::MapWarning::GetCachedSize(bfx::SystemInstance *this)
{
  return this->m_pAdditionalData;
}


// ========================================================================
// ?GetHorizontalReferenceVec@SystemInstance@bfx@@QAAABVVec3@2@XZ
// EA  : 0x8326D6B0
// RVA : 0x0126D6B0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxinstance.cpp
// ========================================================================

const bfx::Vec3 *__fastcall bfx::SystemInstance::GetHorizontalReferenceVec(bfx::SystemInstance *this)
{
  return &this->m_pAdditionalData->m_horizontalReferenceVec;
}


// ========================================================================
// ?GetDefaultSpaceHandle@SystemInstance@bfx@@QAAAAVSpaceHandle@2@XZ
// EA  : 0x8326D6C0
// RVA : 0x0126D6C0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxinstance.cpp
// ========================================================================

bfx::SpaceHandle *__fastcall bfx::SystemInstance::GetDefaultSpaceHandle(bfx::SystemInstance *this)
{
  return &this->m_pSpaceManager->m_defaultSpaceHandle;
}


// ========================================================================
// ?GetInvalidSpaceHandle@SystemInstance@bfx@@QAAAAVSpaceHandle@2@XZ
// EA  : 0x8326D6D0
// RVA : 0x0126D6D0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxinstance.cpp
// ========================================================================

bfx::SpaceHandle *__fastcall bfx::SystemInstance::GetInvalidSpaceHandle(bfx::SystemInstance *this)
{
  return &this->m_pSpaceManager->m_invalidSpaceHandle;
}

