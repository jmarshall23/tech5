
// ========================================================================
// ?DrawBox@bfx@@YAXPBVSpace@1@ABVVec3@1@MABVColor@1@@Z
// EA  : 0x8323E218
// RVA : 0x0123E218
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.h
// ========================================================================

void __fastcall bfx::DrawBox(
        const bfx::Space *pSpace,
        const bfx::Vec3 *pos,
        double r,
        const bfx::Color *color,
        const bfx::Color *a5)
{
  double m_x; // fp0
  double m_y; // fp13
  bfx::Box v7; // [sp+60h] [-30h] BYREF
  bfx::Vec3 v8; // 0:^50.12

  m_x = pos->m_x;
  m_y = pos->m_y;
  v8.m_x = pos->m_x - (float)r;
  v8.m_y = pos->m_y - (float)r;
  v8.m_z = pos->m_z - (float)r;
  v7.m_min.m_z = pos->m_z + (float)r;
  v7.m_max.m_y = (float)m_y + (float)r;
  v7.m_max.m_x = (float)m_x + (float)r;
  v7.m_max.m_z = v7.m_min.m_z;
  v7.m_min = v8;
  bfx::DrawBox(pSpace, mat: &bfx::IDENTITY, boxLCoord: &v7, color: a5);
}


// ========================================================================
// ?DrawLine@bfx@@YAXPBVSpace@1@ABVVec3@1@1ABVColor@1@@Z
// EA  : 0x8323F2C0
// RVA : 0x0123F2C0
// PDB : w:\tech5\libs\navpower\src\bfxsystem\bfxrenderer.h
// ========================================================================

void __fastcall bfx::DrawLine(
        const bfx::Space *pSpace,
        const bfx::Vec3 *v0,
        const bfx::Vec3 *v1,
        const bfx::Color *color)
{
  double m_y; // fp13
  double m_z; // fp12
  double v6; // fp10
  double v7; // fp9
  bfx::Vec3 v8; // [sp+50h] [-20h] BYREF
  float m_x; // [sp+5Ch] [-14h]
  float v10; // [sp+60h] [-10h]
  float v11; // [sp+64h] [-Ch]

  m_y = v0->m_y;
  m_z = v0->m_z;
  v8.m_x = v0->m_x;
  v8.m_y = m_y;
  v6 = v1->m_y;
  v7 = v1->m_z;
  m_x = v1->m_x;
  v8.m_z = m_z;
  v10 = v6;
  v11 = v7;
  bfx::DrawLineList(pSpace, pVerts: &v8, numVerts: 2, color);
}

