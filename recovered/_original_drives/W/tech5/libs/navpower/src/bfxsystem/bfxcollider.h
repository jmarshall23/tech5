
// ========================================================================
// ?GetClosestPtOnLineSeg@bfx@@YA?AVVec3@1@ABV21@00@Z
// EA  : 0x83255CF8
// RVA : 0x01255CF8
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxcollider.h
// ========================================================================

bfx::Vec3 *__fastcall bfx::GetClosestPtOnLineSeg(
        bfx::Vec3 *result,
        const bfx::Vec3 *start,
        const bfx::Vec3 *end,
        const bfx::Vec3 *pos)
{
  double v4; // fp11
  double m_y; // fp5
  double v6; // fp2
  double m_z; // fp4
  double v12; // fp13
  double v13; // fp0

  v4 = (float)(end->m_z - start->m_z);
  m_y = start->m_y;
  v6 = (float)(end->m_y - start->m_y);
  m_z = start->m_z;
  _FP9 = (float)((float)((float)((float)(pos->m_y - start->m_y) * (float)(end->m_y - start->m_y))
                       + (float)((float)((float)(pos->m_x - start->m_x) * (float)(end->m_x - start->m_x))
                               + (float)((float)(pos->m_z - start->m_z) * (float)(end->m_z - start->m_z))))
               / (float)((float)((float)((float)v6 * (float)v6)
                               + (float)((float)((float)(end->m_x - start->m_x) * (float)(end->m_x - start->m_x))
                                       + (float)((float)v4 * (float)v4)))
                       + (float)1.0842022e-19));
  __asm { fsel      f8, f9, f9, f12 }
  _FP6 = (float)((float)_FP8 - (float)1.0);
  __asm { fsel      f3, f6, f0, f8 }
  v12 = (float)((float)(end->m_z - start->m_z) * (float)_FP3);
  v13 = (float)((float)(end->m_y - start->m_y) * (float)_FP3);
  result->m_x = start->m_x + (float)((float)(end->m_x - start->m_x) * (float)_FP3);
  result->m_z = (float)m_z + (float)v12;
  result->m_y = (float)v13 + (float)m_y;
  return result;
}

