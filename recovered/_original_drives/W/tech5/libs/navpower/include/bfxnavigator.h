
// ========================================================================
// ??0CornerData@bfx@@QAA@XZ
// EA  : 0x82DEBF20
// RVA : 0x00DEBF20
// PDB : w:\tech5\libs\navpower\include\bfxnavigator.h
// ========================================================================

bfx::CornerData *__fastcall bfx::CornerData::CornerData(bfx::CornerData *this)
{
  this->m_pos.m_x = 0.0;
  this->m_isGoal = false;
  this->m_pos.m_y = 0.0;
  this->m_linkType = 0;
  this->m_pos.m_z = 0.0;
  bfx::LinkReservationRCPtr::LinkReservationRCPtr(this: (bfx::SpaceHandle *)&this->m_linkHandle);
  bfx::AreaHandle::AreaHandle(this: &this->m_areaHandle);
  this->m_isLinkBackwards = false;
  return this;
}


// ========================================================================
// __unwind$491933_0
// EA  : 0x82DEBF78
// RVA : 0x00DEBF78
// PDB : w:\tech5\libs\navpower\include\bfxnavigator.h
// ========================================================================

void _unwind_491933_0()
{
  int v0; // r12

  bfx::ObstacleHandle::~ObstacleHandle(this: (bfx::PolylinePath3DRCPtr *)(*(_DWORD *)(v0 - 112 + 132) + 20));
}


// ========================================================================
// ??0PosAlongPathResults@bfx@@QAA@XZ
// EA  : 0x82DEBFB0
// RVA : 0x00DEBFB0
// PDB : w:\tech5\libs\navpower\include\bfxnavigator.h
// ========================================================================

bfx::PosAlongPathResults *__fastcall bfx::PosAlongPathResults::PosAlongPathResults(bfx::PosAlongPathResults *this)
{
  this->m_pos.m_x = 0.0;
  this->m_posType = POS_ON_SURFACE;
  this->m_pos.m_y = 0.0;
  this->m_pos.m_z = 0.0;
  bfx::AreaHandle::AreaHandle(this: &this->m_area);
  this->m_backwardsLink = false;
  bfx::LinkReservationRCPtr::LinkReservationRCPtr(this: (bfx::SpaceHandle *)&this->m_link);
  this->m_pathDistToPos = 0.0;
  this->m_directionOfApproach.m_x = 0.0;
  this->m_directionOfApproach.m_y = 0.0;
  this->m_directionOfApproach.m_z = 0.0;
  return this;
}


// ========================================================================
// __unwind$491957
// EA  : 0x82DEC024
// RVA : 0x00DEC024
// PDB : w:\tech5\libs\navpower\include\bfxnavigator.h
// ========================================================================

void _unwind_491957()
{
  int v0; // r12

  bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)(*(_DWORD *)(v0 - 128 + 148) + 16));
}

