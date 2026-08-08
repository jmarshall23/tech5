
// ========================================================================
// ?IsResourceTypeRegistered@ResourceManager@bfx@@QBA_NI@Z
// EA  : 0x8326C7C8
// RVA : 0x0126C7C8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxresources.h
// ========================================================================

BOOL __fastcall bfx::ResourceManager::IsResourceTypeRegistered(bfx::ResourceManager *this, unsigned int id)
{
  int m_size; // r7
  int v3; // r9
  bfx::ResourceManager::Registration *m_data; // r8
  int i; // r11

  m_size = this->m_registry.m_size;
  v3 = 0;
  if ( m_size <= 0 )
    return false;
  m_data = this->m_registry.m_data;
  for ( i = 0; m_data[i].m_id != id; ++i )
  {
    if ( ++v3 >= m_size )
      return false;
  }
  return &m_data[i] != nullptr;
}

