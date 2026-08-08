
// ========================================================================
// ?StrictlyOnRight@bfx@@YA_NABVVec3@1@000@Z
// EA  : 0x832DA6B8
// RVA : 0x012DA6B8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpartition.h
// ========================================================================

BOOL __fastcall bfx::StrictlyOnRight(
        const bfx::Vec3 *lineStart,
        const bfx::Vec3 *lineEnd,
        const bfx::Vec3 *testPos,
        const bfx::Vec3 *N)
{
  return (float)((float)(N->m_x
                       * (float)((float)((float)(testPos->m_y - lineStart->m_y) * (float)(lineEnd->m_z - lineStart->m_z))
                               - (float)((float)(testPos->m_z - lineStart->m_z) * (float)(lineEnd->m_y - lineStart->m_y))))
               + (float)((float)(N->m_z
                               * (float)((float)((float)(testPos->m_x - lineStart->m_x)
                                               * (float)(lineEnd->m_y - lineStart->m_y))
                                       - (float)((float)(lineEnd->m_x - lineStart->m_x)
                                               * (float)(testPos->m_y - lineStart->m_y))))
                       + (float)(N->m_y
                               * (float)((float)((float)(lineEnd->m_x - lineStart->m_x)
                                               * (float)(testPos->m_z - lineStart->m_z))
                                       - (float)((float)(testPos->m_x - lineStart->m_x)
                                               * (float)(lineEnd->m_z - lineStart->m_z)))))) > 0.0;
}


// ========================================================================
// ?OnRight@bfx@@YA_NABVVec3@1@000@Z
// EA  : 0x832DA740
// RVA : 0x012DA740
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpartition.h
// ========================================================================

BOOL __fastcall bfx::OnRight(
        const bfx::Vec3 *lineStart,
        const bfx::Vec3 *lineEnd,
        const bfx::Vec3 *testPos,
        const bfx::Vec3 *N)
{
  return (float)((float)(N->m_x
                       * (float)((float)((float)(testPos->m_y - lineStart->m_y) * (float)(lineEnd->m_z - lineStart->m_z))
                               - (float)((float)(testPos->m_z - lineStart->m_z) * (float)(lineEnd->m_y - lineStart->m_y))))
               + (float)((float)(N->m_z
                               * (float)((float)((float)(testPos->m_x - lineStart->m_x)
                                               * (float)(lineEnd->m_y - lineStart->m_y))
                                       - (float)((float)(lineEnd->m_x - lineStart->m_x)
                                               * (float)(testPos->m_y - lineStart->m_y))))
                       + (float)(N->m_y
                               * (float)((float)((float)(lineEnd->m_x - lineStart->m_x)
                                               * (float)(testPos->m_z - lineStart->m_z))
                                       - (float)((float)(testPos->m_x - lineStart->m_x)
                                               * (float)(lineEnd->m_z - lineStart->m_z)))))) >= 0.0;
}


// ========================================================================
// ?IntersectLineSegs@bfx@@YA_NABVVec3@1@0000@Z
// EA  : 0x832DA7C8
// RVA : 0x012DA7C8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxpartition.h
// ========================================================================

int __fastcall bfx::IntersectLineSegs(
        const bfx::Vec3 *a,
        const bfx::Vec3 *b,
        const bfx::Vec3 *c,
        const bfx::Vec3 *d,
        const bfx::Vec3 *N)
{
  BOOL v10; // r26
  BOOL v11; // r30
  bool v12; // r3
  unsigned __int8 v13; // r11

  v10 = bfx::StrictlyOnRight(lineStart: a, lineEnd: b, testPos: c, N);
  if ( ((_cntlzw(v10) & 0x20) != 0) == ((_cntlzw(bfx::StrictlyOnRight(lineStart: a, lineEnd: b, testPos: d, N)) & 0x20) != 0) )
    return 0;
  v11 = bfx::StrictlyOnRight(lineStart: c, lineEnd: d, testPos: a, N);
  v12 = bfx::StrictlyOnRight(lineStart: c, lineEnd: d, testPos: b, N);
  v13 = 1;
  if ( ((_cntlzw(v11) & 0x20) != 0) == ((_cntlzw(v12) & 0x20) != 0) )
    return 0;
  return v13;
}

