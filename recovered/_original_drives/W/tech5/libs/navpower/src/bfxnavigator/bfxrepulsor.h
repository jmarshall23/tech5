
// ========================================================================
// ??1RepulsorOwner@bfx@@UAA@XZ
// EA  : 0x83261EA8
// RVA : 0x01261EA8
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.h
// ========================================================================

void __fastcall bfx::RepulsorOwner::~RepulsorOwner(bfx::RepulsorOwner *this)
{
  this->__vftable = (bfx::RepulsorOwner_vtbl *)&bfx::RepulsorOwner::`vftable';
}


// ========================================================================
// ?AdvanceToNextRepulsorSatisfyingFilter@NearbyRepulsorCursor@bfx@@AAAXXZ
// EA  : 0x832629C0
// RVA : 0x012629C0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.h
// ========================================================================

void __fastcall bfx::NearbyRepulsorCursor::AdvanceToNextRepulsorSatisfyingFilter(bfx::NearbyRepulsorCursor *this)
{
  bfx::Array<bfx::AABB *> *m_pArray; // r9
  unsigned int m_blockageFlags; // r10
  int m_i; // r11
  int v4; // r11

  if ( this->m_filterBasedOnBlockageFlags )
  {
    m_pArray = this->m_overlapCursor.m_pArray;
    if ( this->m_overlapCursor.m_i < this->m_overlapCursor.m_pArray->m_size )
    {
      m_blockageFlags = this->m_blockageFlags;
      do
      {
        m_i = this->m_overlapCursor.m_i;
        if ( (*((_DWORD *)m_pArray->m_data[m_i]->m_pUserData + 16) & m_blockageFlags) != 0 )
          break;
        v4 = m_i + 1;
        this->m_overlapCursor.m_i = v4;
      }
      while ( v4 < this->m_overlapCursor.m_pArray->m_size );
    }
  }
}


// ========================================================================
// ??0NearbyRepulsorCursor@bfx@@QAA@PAVRepulsorImpl@1@_N@Z
// EA  : 0x83262A28
// RVA : 0x01262A28
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.h
// ========================================================================

bfx::NearbyRepulsorCursor *__fastcall bfx::NearbyRepulsorCursor::NearbyRepulsorCursor(
        bfx::NearbyRepulsorCursor *this,
        bfx::RepulsorImpl *pRepulsor,
        bool filterBasedOnBlockageFlags)
{
  bfx::AABB *m_pAABB; // r11

  m_pAABB = pRepulsor->m_pAABB;
  this->m_overlapCursor.m_i = 0;
  this->m_overlapCursor.m_pArray = &m_pAABB->m_overlaps;
  this->m_blockageFlags = pRepulsor->m_blockageFlags;
  this->m_filterBasedOnBlockageFlags = filterBasedOnBlockageFlags;
  bfx::NearbyRepulsorCursor::AdvanceToNextRepulsorSatisfyingFilter(this);
  return this;
}


// ========================================================================
// ?SetArea@RepulsorImpl@bfx@@QAAXPAVArea@2@@Z
// EA  : 0x832B9838
// RVA : 0x012B9838
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.h
// ========================================================================

void __fastcall bfx::RepulsorImpl::SetArea(bfx::RepulsorImpl *this, bfx::Area *pArea)
{
  const bfx::Handle<bfx::Area> *v3; // r3
  bfx::Handle<bfx::Area> v4[2]; // [sp+50h] [-20h] BYREF

  v3 = bfx::Handle<bfx::Area>::Handle<bfx::Area>(this: v4, pArea);
  bfx::Handle<bfx::Area>::operator=(this: &this->m_areaHandle, rhs: v3);
  bfx::Handle<bfx::Area>::Release(this: v4);
}


// ========================================================================
// __unwind$34165
// EA  : 0x832B9888
// RVA : 0x012B9888
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxrepulsor.h
// ========================================================================

void _unwind_34165()
{
  int v0; // r12

  bfx::Handle<bfx::Area>::~Handle<bfx::Area>(this: (bfx::AreaHandleImpl *)(v0 - 112 + 80));
}

