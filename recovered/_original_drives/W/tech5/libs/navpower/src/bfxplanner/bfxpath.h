
// ========================================================================
// ??1Path@bfx@@UAA@XZ
// EA  : 0x832716B8
// RVA : 0x012716B8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpath.h
// ========================================================================

void __fastcall bfx::Path::~Path(bfx::Path *this)
{
  char *m_data; // r4

  this->__vftable = (bfx::Path_vtbl *)&bfx::Path::`vftable';
  m_data = (char *)this->m_areas.m_data;
  this->m_areas.m_size = 0;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_areas.m_data = nullptr;
  }
  this->m_areas.m_cap = 0;
}


// ========================================================================
// ?GetUnderlyingArea@AreaHandlePath@bfx@@UBAPAVArea@2@H@Z
// EA  : 0x83272598
// RVA : 0x01272598
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpath.h
// ========================================================================

bfx::Area *__fastcall bfx::AreaHandlePath::GetUnderlyingArea(bfx::AreaHandlePath *this, int i)
{
  bfx::AreaProxy *m_pProxy; // r11

  m_pProxy = this->m_areaHandles.m_data[i].m_pProxy;
  if ( m_pProxy != nullptr )
    return m_pProxy->m_pArea;
  else
    return nullptr;
}


// ========================================================================
// ??1AreaHandlePath@bfx@@UAA@XZ
// EA  : 0x832725C8
// RVA : 0x012725C8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpath.h
// ========================================================================

void __fastcall bfx::AreaHandlePath::~AreaHandlePath(bfx::AreaHandlePath *this)
{
  bfx::Array<bfx::Handle<bfx::Area> > *p_m_areaHandles; // r28
  char *m_data; // r4
  char *v4; // r4

  this->__vftable = (bfx::AreaHandlePath_vtbl *)&bfx::AreaHandlePath::`vftable';
  p_m_areaHandles = &this->m_areaHandles;
  bfx::Array<bfx::Handle<bfx::Area>>::shrink(this: &this->m_areaHandles, size: 0);
  m_data = (char *)this->m_areaHandles.m_data;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    p_m_areaHandles->m_data = nullptr;
  }
  p_m_areaHandles->m_cap = 0;
  this->__vftable = (bfx::AreaHandlePath_vtbl *)&bfx::Path::`vftable';
  v4 = (char *)this->m_areas.m_data;
  this->m_areas.m_size = 0;
  if ( v4 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v4);
    this->m_areas.m_data = nullptr;
  }
  this->m_areas.m_cap = 0;
}


// ========================================================================
// __unwind$27933
// EA  : 0x8327265C
// RVA : 0x0127265C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpath.h
// ========================================================================

void _unwind_27933()
{
  int v0; // r12

  bfx::Path::~Path(this: *(bfx::Path **)(v0 - 128 + 148));
}


// ========================================================================
// ??9PathCC@bfx@@QBA_NABV01@@Z
// EA  : 0x832924A0
// RVA : 0x012924A0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpath.h
// ========================================================================

int __fastcall bfx::PathCC::operator!=(bfx::PathCC *this, const bfx::PathCC *rhs)
{
  unsigned __int8 v2; // r11

  if ( this->m_pPath != rhs->m_pPath )
    return 1;
  v2 = 0;
  if ( this->m_i != rhs->m_i )
    return 1;
  return v2;
}


// ========================================================================
// ?NextArea@PathCC@bfx@@QBAPAVArea@2@XZ
// EA  : 0x83292748
// RVA : 0x01292748
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpath.h
// ========================================================================

bfx::Area *__fastcall bfx::PathCC::NextArea(bfx::PathCC *this)
{
  int m_i; // r10

  m_i = this->m_i;
  if ( m_i + 1 >= this->m_pPath->m_areas.m_size )
    return nullptr;
  else
    return this->m_pPath->m_areas.m_data[m_i + 1];
}

