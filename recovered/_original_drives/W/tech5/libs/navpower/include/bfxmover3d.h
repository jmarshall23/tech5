
// ========================================================================
// ??0RepulsionPackage@bfx@@QAA@XZ
// EA  : 0x83263E98
// RVA : 0x01263E98
// PDB : w:\tech5\libs\navpower\include\bfxmover3d.h
// ========================================================================

bfx::RepulsionPackage *__fastcall bfx::RepulsionPackage::RepulsionPackage(bfx::RepulsionPackage *this)
{
  double Scale; // fp1
  double v3; // fp1

  Scale = bfx::GetScale();
  this->m_sphereData.m_radius = Scale;
  this->m_sphereData.m_outerCushion = (float)Scale * (float)0.2;
  this->m_sphereData.m_innerCushion = (float)Scale * (float)0.2;
  this->m_sphereForces.m_initialAcc = bfx::GetScale() * (float)2.0;
  this->m_sphereForces.m_outerCushionAcc = bfx::GetScale() * (float)6.0;
  v3 = bfx::GetScale();
  this->m_sphereForces.m_innerCushionAcc = (float)v3 * (float)20.0;
  this->m_blockageFlags = -1;
  this->m_bulk = 1.0;
  this->m_identityFlags = -1;
  return this;
}

