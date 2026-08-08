
// ========================================================================
// ??1Surfer@bfx@@UAA@XZ
// EA  : 0x83263890
// RVA : 0x01263890
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxsurfer.h
// ========================================================================

void __fastcall bfx::Surfer::~Surfer(bfx::Surfer *this)
{
  bfx::Edge **m_data; // r4
  bfx::Area **v3; // r4

  this->__vftable = (bfx::Surfer_vtbl *)&bfx::Surfer::`vftable';
  m_data = this->m_edgesTraversed.m_data;
  this->m_edgesTraversed.m_size = 0;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_edgesTraversed.m_data = nullptr;
  }
  this->m_edgesTraversed.m_cap = 0;
  v3 = this->m_areasTraversed.m_data;
  this->m_areasTraversed.m_size = 0;
  if ( v3 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v3);
    this->m_areasTraversed.m_data = nullptr;
  }
  this->m_areasTraversed.m_cap = 0;
  bfx::Handle<bfx::Area>::Release(this: &this->m_area);
}


// ========================================================================
// __unwind$87213
// EA  : 0x83263914
// RVA : 0x01263914
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxsurfer.h
// ========================================================================

void _unwind_87213()
{
  int v0; // r12

  bfx::Handle<bfx::Area>::~Handle<bfx::Area>(this: (bfx::AreaHandleImpl *)(*(_DWORD *)(v0 - 128 + 148) + 16));
}


// ========================================================================
// __unwind$87214
// EA  : 0x83263940
// RVA : 0x01263940
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxsurfer.h
// ========================================================================

void _unwind_87214()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 44));
}

