
// ========================================================================
// ??1BinaryImageIn@bfx@@QAA@XZ
// EA  : 0x8326C820
// RVA : 0x0126C820
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxbinaryimagein.h
// ========================================================================

void __fastcall bfx::BinaryImageIn::~BinaryImageIn(bfx::BinaryImageIn *this)
{
  const bfx::ResourceSectionHeader **m_data; // r4

  m_data = this->m_sectionStack.m_data;
  this->m_sectionStack.m_size = 0;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_sectionStack.m_data = nullptr;
  }
  this->m_sectionStack.m_cap = 0;
}

