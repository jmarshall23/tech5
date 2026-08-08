
// ========================================================================
// ??0LinkDat@bfx@@QAA@XZ
// EA  : 0x82DE7550
// RVA : 0x00DE7550
// PDB : w:\tech5\libs\navpower\include\bfxplanner.h
// ========================================================================

bfx::LinkDat *__fastcall bfx::LinkDat::LinkDat(bfx::LinkDat *this)
{
  __int64 v1; // r31

  LODWORD(v1) = 0;
  this->m_layerMask = -1;
  this->m_bidirectional = true;
  HIDWORD(v1) = this;
  this->m_type = JUMP_LINK;
  this->m_penaltyMult = 1.0;
  this->m_linkUsageFlags = -1;
  this->m_maxSnapDist = bfx::GetScale() * (float)4.0;
  *(float *)(HIDWORD(v1) + 24) = bfx::GetScale();
  *(_BYTE *)(HIDWORD(v1) + 32) = 0;
  *(_QWORD *)(HIDWORD(v1) + 40) = v1;
  *(float *)(HIDWORD(v1) + 28) = 0.0;
  *(_DWORD *)(HIDWORD(v1) + 48) = 0;
  return (bfx::LinkDat *)HIDWORD(v1);
}


// ========================================================================
// ??0ProbeResults@bfx@@QAA@XZ
// EA  : 0x82DEBE88
// RVA : 0x00DEBE88
// PDB : w:\tech5\libs\navpower\include\bfxplanner.h
// ========================================================================

bfx::ProbeResults *__fastcall bfx::ProbeResults::ProbeResults(bfx::ProbeResults *this)
{
  bfx::AreaHandle::AreaHandle(this: &this->m_endArea);
  this->m_collided = false;
  this->m_collideEdgeIndex = -1;
  this->m_generatePath = false;
  bfx::LinkReservationRCPtr::LinkReservationRCPtr(this: (bfx::SpaceHandle *)&this->m_path);
  return this;
}


// ========================================================================
// __unwind$491902
// EA  : 0x82DEBEE8
// RVA : 0x00DEBEE8
// PDB : w:\tech5\libs\navpower\include\bfxplanner.h
// ========================================================================

void _unwind_491902()
{
  int v0; // r12

  bfx::AreaHandle::~AreaHandle(this: (bfx::AreaHandle *)(*(_DWORD *)(v0 - 112 + 132) + 12));
}

