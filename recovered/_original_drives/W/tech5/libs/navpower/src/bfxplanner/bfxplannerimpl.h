
// ========================================================================
// ??1MultiPath@bfx@@UAA@XZ
// EA  : 0x83247940
// RVA : 0x01247940
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerimpl.h
// ========================================================================

void __fastcall bfx::MultiPath::~MultiPath(bfx::MultiPath *this)
{
  bfx::Array<bfx::MultiPathGoalOutput> *p_m_goals; // r30
  bfx::MultiPathGoalOutput *m_data; // r4

  this->__vftable = (bfx::MultiPath_vtbl *)&bfx::MultiPath::`vftable';
  p_m_goals = &this->m_goals;
  bfx::Array<bfx::MultiPathGoalOutput>::shrink(this: &this->m_goals, size: 0);
  m_data = this->m_goals.m_data;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    p_m_goals->m_data = nullptr;
  }
  p_m_goals->m_cap = 0;
  bfx::HandleTargetBase::~HandleTargetBase(this);
}


// ========================================================================
// __unwind$109240
// EA  : 0x832479AC
// RVA : 0x012479AC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxplannerimpl.h
// ========================================================================

void _unwind_109240()
{
  int v0; // r12

  bfx::HandleTargetBase::~HandleTargetBase(this: *(bfx::HandleTargetBase **)(v0 - 128 + 148));
}

