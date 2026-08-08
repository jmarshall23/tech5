
// ========================================================================
// ??1Renderer@bfx@@UAA@XZ
// EA  : 0x82DE7540
// RVA : 0x00DE7540
// PDB : w:\tech5\libs\navpower\include\bfxsystem.h
// ========================================================================

void __fastcall bfx::Renderer::~Renderer(bfx::Renderer *this)
{
  this->__vftable = (bfx::Renderer_vtbl *)&bfx::Renderer::`vftable';
}


// ========================================================================
// ??0ResourceOffset@bfx@@QAA@XZ
// EA  : 0x82DEE220
// RVA : 0x00DEE220
// PDB : w:\tech5\libs\navpower\include\bfxsystem.h
// ========================================================================

bfx::ResourceOffset *__fastcall bfx::ResourceOffset::ResourceOffset(bfx::ResourceOffset *this)
{
  bfx::Vector3 v3; // [sp+50h] [-40h] BYREF
  bfx::Vector3 v4; // [sp+60h] [-30h] BYREF
  bfx::Vector3 v5; // [sp+70h] [-20h] BYREF

  this->m_positionOffset.m_x = 0.0;
  this->m_positionOffset.m_y = 0.0;
  this->m_positionOffset.m_z = 0.0;
  v3.m_x = 0.0;
  v3.m_y = 0.0;
  v3.m_z = 1.0;
  v4.m_x = 0.0;
  v4.m_y = 1.0;
  v4.m_z = 0.0;
  v5.m_x = 1.0;
  v5.m_y = 0.0;
  v5.m_z = 0.0;
  bfx::Quaternion::Quaternion(this: &this->m_rotationOffset, forwAxisIn: &v5, leftAxisIn: &v4, upAxisIn: &v3);
  this->m_layerOffset = 0;
  return this;
}

