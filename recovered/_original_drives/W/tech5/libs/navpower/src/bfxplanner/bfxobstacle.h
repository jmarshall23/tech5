
// ========================================================================
// ?CalcBoundingSphere@BoxObstacle@bfx@@UAA?AVSphere@2@XZ
// EA  : 0x83288878
// RVA : 0x01288878
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.h
// ========================================================================

bfx::BoxObstacle *__fastcall bfx::BoxObstacle::CalcBoundingSphere(bfx::BoxObstacle *this, bfx::Sphere *result)
{
  double v3; // fp8
  double v4; // fp6
  double v5; // fp30
  double v6; // fp29
  double v7; // fp28
  bfx::Matrix *v8; // r3
  bfx::HandleProxy *v9; // r8
  bfx::Planner *v10; // r7
  bfx::Vec3 v12; // [sp+50h] [-50h] BYREF
  bfx::Matrix v13; // [sp+60h] [-40h] BYREF

  v3 = (float)(result[12].m_radius + result[13].m_pos.m_z);
  v4 = (float)(result[13].m_pos.m_x + result[13].m_radius);
  v5 = (float)(result[13].m_pos.m_y - result[12].m_pos.m_z);
  v6 = (float)(result[13].m_pos.m_z - result[12].m_radius);
  v7 = (float)(result[13].m_radius - result[13].m_pos.m_x);
  v12.m_x = (float)(result[12].m_pos.m_z + result[13].m_pos.m_y) * (float)0.5;
  v12.m_y = (float)v3 * (float)0.5;
  v12.m_z = (float)v4 * (float)0.5;
  v8 = bfx::Matrix::operator*(this: &v13, result: (bfx::Vec3 *)&result[4].m_pos.m_z, rhs: &v12);
  v9 = (bfx::HandleProxy *)LODWORD(v8->m_data[1]);
  v10 = (bfx::Planner *)LODWORD(v8->m_data[2]);
  this->__vftable = (bfx::BoxObstacle_vtbl *)LODWORD(v8->m_data[0]);
  this->m_pProxy = v9;
  this->m_pPlanner = v10;
  *(float *)&this->m_obID = (float)__fsqrts((float)((float)((float)v5 * (float)v5)
                                                  + (float)((float)((float)v7 * (float)v7)
                                                          + (float)((float)v6 * (float)v6))))
                          * (float)0.5;
  return this;
}


// ========================================================================
// ?GetClipPlanes@BoxObstacle@bfx@@UAAXAAPBVPlane@2@AAH@Z
// EA  : 0x83288948
// RVA : 0x01288948
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxobstacle.h
// ========================================================================

void __fastcall bfx::BoxObstacle::GetClipPlanes(
        bfx::BoxObstacle *this,
        bfx::Plane **pClipPlanesOut,
        int *numClipPlanesOut)
{
  *pClipPlanesOut = this->m_clipPlanes;
  *numClipPlanesOut = 6;
}

