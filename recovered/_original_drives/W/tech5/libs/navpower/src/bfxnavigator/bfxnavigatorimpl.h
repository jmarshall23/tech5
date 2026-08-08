
// ========================================================================
// ??0CornerDataInternal@bfx@@QAA@XZ
// EA  : 0x832D4EB0
// RVA : 0x012D4EB0
// PDB : w:\tech5\libs\navpower\src\bfxnavigator\bfxnavigatorimpl.h
// ========================================================================

bfx::CornerDataInternal *__fastcall bfx::CornerDataInternal::CornerDataInternal(bfx::CornerDataInternal *this)
{
  this->m_isGoal = false;
  this->m_cornerType = UNDEFINED_CORNER;
  this->m_indexOfCornerArea = -1;
  this->m_cornerPos.m_x = 0.0;
  this->m_linkType = 0;
  this->m_cornerPos.m_y = 0.0;
  this->m_cornerPos.m_z = 0.0;
  this->m_linkHandle.m_pProxy = nullptr;
  this->m_areaHandle.m_pProxy = nullptr;
  return this;
}

