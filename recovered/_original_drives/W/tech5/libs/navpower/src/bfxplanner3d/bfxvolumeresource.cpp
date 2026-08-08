
// ========================================================================
// bfx::IntersectPlanes
// EA  : 0x8329DFC0
// RVA : 0x0129DFC0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

int __fastcall bfx::IntersectPlanes(const bfx::Plane *P1, const bfx::Plane *P2, const bfx::Plane *P3, bfx::Vec3 *P)
{
  double v4; // fp10
  double v6; // fp13
  double v7; // fp5
  double v8; // fp3
  double v9; // fp2

  if ( __fabs((float)((float)(P1->m_normal.m_x
                            * (float)((float)(P3->m_normal.m_z * P2->m_normal.m_y)
                                    - (float)(P3->m_normal.m_y * P2->m_normal.m_z)))
                    + (float)((float)(P1->m_normal.m_y
                                    * (float)((float)(P3->m_normal.m_x * P2->m_normal.m_z)
                                            - (float)(P2->m_normal.m_x * P3->m_normal.m_z)))
                            + (float)(P1->m_normal.m_z
                                    * (float)((float)(P2->m_normal.m_x * P3->m_normal.m_y)
                                            - (float)(P3->m_normal.m_x * P2->m_normal.m_y)))))) <= 1.0842022e-19 )
    return 0;
  v4 = (float)((float)1.0
             / (float)((float)(P1->m_normal.m_x
                             * (float)((float)(P3->m_normal.m_z * P2->m_normal.m_y)
                                     - (float)(P3->m_normal.m_y * P2->m_normal.m_z)))
                     + (float)((float)(P1->m_normal.m_y
                                     * (float)((float)(P3->m_normal.m_x * P2->m_normal.m_z)
                                             - (float)(P2->m_normal.m_x * P3->m_normal.m_z)))
                             + (float)(P1->m_normal.m_z
                                     * (float)((float)(P2->m_normal.m_x * P3->m_normal.m_y)
                                             - (float)(P3->m_normal.m_x * P2->m_normal.m_y))))));
  v6 = (float)((float)((float)(P2->m_normal.m_y * P1->m_normal.m_x) - (float)(P1->m_normal.m_y * P2->m_normal.m_x))
             * P3->m_d);
  v8 = (float)((float)((float)((float)(P2->m_normal.m_x * P3->m_normal.m_y)
                             - (float)(P3->m_normal.m_x * P2->m_normal.m_y))
                     * P1->m_d)
             + (float)((float)((float)(P1->m_normal.m_y * P3->m_normal.m_x)
                             - (float)(P3->m_normal.m_y * P1->m_normal.m_x))
                     * P2->m_d));
  v9 = (float)((float)(P1->m_d
                     * (float)((float)(P3->m_normal.m_z * P2->m_normal.m_y)
                             - (float)(P3->m_normal.m_y * P2->m_normal.m_z)))
             + (float)((float)((float)(P3->m_normal.m_y * P1->m_normal.m_z)
                             - (float)(P3->m_normal.m_z * P1->m_normal.m_y))
                     * P2->m_d));
  v7 = (float)((float)((float)(P2->m_normal.m_z * P1->m_normal.m_y) - (float)(P2->m_normal.m_y * P1->m_normal.m_z))
             * P3->m_d);
  P->m_y = (float)((float)1.0
                 / (float)((float)(P1->m_normal.m_x
                                 * (float)((float)(P3->m_normal.m_z * P2->m_normal.m_y)
                                         - (float)(P3->m_normal.m_y * P2->m_normal.m_z)))
                         + (float)((float)(P1->m_normal.m_y
                                         * (float)((float)(P3->m_normal.m_x * P2->m_normal.m_z)
                                                 - (float)(P2->m_normal.m_x * P3->m_normal.m_z)))
                                 + (float)(P1->m_normal.m_z
                                         * (float)((float)(P2->m_normal.m_x * P3->m_normal.m_y)
                                                 - (float)(P3->m_normal.m_x * P2->m_normal.m_y))))))
         * (float)((float)((float)(P1->m_d
                                 * (float)((float)(P3->m_normal.m_x * P2->m_normal.m_z)
                                         - (float)(P2->m_normal.m_x * P3->m_normal.m_z)))
                         + (float)((float)((float)(P3->m_normal.m_z * P1->m_normal.m_x)
                                         - (float)(P1->m_normal.m_z * P3->m_normal.m_x))
                                 * P2->m_d))
                 + (float)((float)((float)(P1->m_normal.m_z * P2->m_normal.m_x)
                                 - (float)(P2->m_normal.m_z * P1->m_normal.m_x))
                         * P3->m_d));
  P->m_z = (float)v4 * (float)((float)v8 + (float)v6);
  P->m_x = (float)v4 * (float)((float)v9 + (float)v7);
  return 1;
}


// ========================================================================
// bfx::CalcCentroid
// EA  : 0x8329E110
// RVA : 0x0129E110
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

bfx::Vec3 *__fastcall bfx::CalcCentroid(bfx::Vec3 *result, const bfx::Vec3 *pPts, unsigned int numPts)
{
  const bfx::Vec3 *v3; // r10
  double v4; // fp13
  double v5; // fp11
  double v6; // fp10
  double v7; // fp12
  float *p_m_z; // r11
  double v9; // fp9
  unsigned int v10; // ctr

  v3 = &pPts[numPts];
  v4 = 0.0;
  v5 = 0.0;
  v6 = 0.0;
  v7 = 0.0;
  if ( pPts < v3 )
  {
    if ( (int)(12 * numPts + 11) / 12 >= 4 )
    {
      p_m_z = &pPts[-1].m_z;
      do
      {
        v9 = (float)(p_m_z[9] + (float)(p_m_z[6] + (float)(p_m_z[3] + (float)v6)));
        v4 = (float)(p_m_z[10] + (float)(p_m_z[7] + (float)(p_m_z[4] + (float)(pPts->m_x + (float)v4))));
        pPts += 4;
        v7 = (float)((float)((float)((float)((float)v7 + (float)1.0) + (float)1.0) + (float)1.0) + (float)1.0);
        v5 = (float)(p_m_z[11] + (float)(p_m_z[8] + (float)(p_m_z[5] + (float)(p_m_z[2] + (float)v5))));
        p_m_z += 12;
        v6 = (float)(*p_m_z + (float)v9);
      }
      while ( (int)pPts < (int)&v3[-3] );
    }
    if ( pPts < v3 )
    {
      v10 = ((char *)v3 - (char *)pPts - 1) / 0xCu + 1;
      do
      {
        v7 = (float)((float)v7 + (float)1.0);
        v4 = (float)(pPts->m_x + (float)v4);
        v5 = (float)(pPts->m_y + (float)v5);
        v6 = (float)(pPts->m_z + (float)v6);
        ++pPts;
        --v10;
      }
      while ( v10 != 0 );
    }
  }
  result->m_y = (float)((float)1.0 / (float)v7) * (float)v5;
  result->m_x = (float)((float)1.0 / (float)v7) * (float)v4;
  result->m_z = (float)((float)1.0 / (float)v7) * (float)v6;
  return result;
}


// ========================================================================
// ?GetSpace@Volume@bfx@@QAAPAVSpace@2@XZ
// EA  : 0x8329E240
// RVA : 0x0129E240
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

bfx::Space *__fastcall bfx::Volume::GetSpace(bfx::Volume *this)
{
  return this->m_pParentGraph->m_pSpace;
}


// ========================================================================
// bfx::PointInSpace
// EA  : 0x8329E250
// RVA : 0x0129E250
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

int __fastcall bfx::PointInSpace(const bfx::Vec3 *p, const bfx::Plane *planes, unsigned int numPlanes)
{
  const bfx::Plane *v3; // r10
  float *p_m_y; // r11
  double v5; // fp2

  v3 = &planes[numPlanes];
  if ( planes >= v3 )
    return 1;
  p_m_y = &planes->m_normal.m_y;
  while ( 1 )
  {
    v5 = (float)((float)((float)((float)(p->m_x * *(p_m_y - 1)) + (float)(p_m_y[1] * p->m_z)) + (float)(*p_m_y * p->m_y))
               - p_m_y[2]);
    p_m_y += 4;
    if ( v5 > 0.0009765625 )
      break;
    if ( p_m_y - 1 >= (float *)v3 )
      return 1;
  }
  return 0;
}


// ========================================================================
// ?Translate@Volume@bfx@@QAAXABVVec3@2@@Z
// EA  : 0x8329E2C8
// RVA : 0x0129E2C8
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void __fastcall bfx::Volume::Translate(bfx::Volume *this, const bfx::Vec3 *deltaPos)
{
  unsigned int v2; // r10
  double v3; // fp7
  double v4; // fp6
  bfx::VolumeResource *m_pRes; // r8
  int v6; // r9

  v2 = 0;
  v3 = (float)(this->m_centroid.m_y + deltaPos->m_y);
  v4 = (float)(this->m_centroid.m_z + deltaPos->m_z);
  this->m_centroid.m_x = this->m_centroid.m_x + deltaPos->m_x;
  this->m_centroid.m_y = v3;
  this->m_centroid.m_z = v4;
  m_pRes = this->m_pRes;
  if ( m_pRes->m_numPlanes != 0 )
  {
    v6 = 0;
    do
    {
      ++v2;
      m_pRes->m_planes[v6].m_d = (float)((float)(m_pRes->m_planes[v6].m_normal.m_x * deltaPos->m_x)
                                       + (float)((float)(m_pRes->m_planes[v6].m_normal.m_y * deltaPos->m_y)
                                               + (float)(m_pRes->m_planes[v6].m_normal.m_z * deltaPos->m_z)))
                               + m_pRes->m_planes[v6].m_d;
      ++v6;
    }
    while ( v2 < m_pRes->m_numPlanes );
  }
}


// ========================================================================
// ?GetPlaneThroughPoints@bfx@@YA_NABVVec3@1@00AAVPlane@1@@Z
// EA  : 0x8329E368
// RVA : 0x0129E368
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

int __fastcall bfx::GetPlaneThroughPoints(const bfx::Vec3 *p0, const bfx::Vec3 *p1, const bfx::Vec3 *p2, bfx::Plane *P)
{
  double v4; // fp0
  double v5; // fp13
  double v6; // fp12
  char v7; // r10

  v4 = (float)((float)((float)(p2->m_z - p0->m_z) * (float)(p1->m_y - p0->m_y))
             - (float)((float)(p2->m_y - p0->m_y) * (float)(p1->m_z - p0->m_z)));
  v5 = (float)((float)((float)(p2->m_x - p0->m_x) * (float)(p1->m_z - p0->m_z))
             - (float)((float)(p2->m_z - p0->m_z) * (float)(p1->m_x - p0->m_x)));
  v6 = (float)((float)((float)(p2->m_y - p0->m_y) * (float)(p1->m_x - p0->m_x))
             - (float)((float)(p2->m_x - p0->m_x) * (float)(p1->m_y - p0->m_y)));
  if ( v4 != 0.0 || v5 != 0.0 || (v7 = 1, v6 != 0.0) )
    v7 = 0;
  if ( v7 != 0 )
    return 0;
  _FP4 = (float)((float)__fsqrts((float)((float)((float)v4 * (float)v4)
                                       + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5))))
               - (float)1.0842022e-19);
  __asm { fsel      f2, f4, f3, f11 }
  P->m_normal.m_x = (float)((float)((float)(p2->m_z - p0->m_z) * (float)(p1->m_y - p0->m_y))
                          - (float)((float)(p2->m_y - p0->m_y) * (float)(p1->m_z - p0->m_z)))
                  * (float)_FP2;
  P->m_normal.m_y = (float)v5 * (float)_FP2;
  P->m_normal.m_z = (float)v6 * (float)_FP2;
  P->m_d = (float)((float)((float)v5 * (float)_FP2) * p0->m_y)
         + (float)((float)(p0->m_z * (float)((float)v6 * (float)_FP2))
                 + (float)(p0->m_x * (float)((float)v4 * (float)_FP2)));
  return 1;
}


// ========================================================================
// ?GetPlane@Portal@bfx@@QBA?AVPlane@2@XZ
// EA  : 0x8329E468
// RVA : 0x0129E468
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

bfx::Plane *__fastcall bfx::Portal::GetPlane(bfx::Portal *this, bfx::Plane *result)
{
  int v2; // r6

  bfx::GetPlaneThroughPoints(
    p0: (const bfx::Vec3 *)(LODWORD(result->m_normal.m_y) + 12),
    p1: (const bfx::Vec3 *)(LODWORD(result->m_normal.m_y) + 24),
    p2: (const bfx::Vec3 *)(LODWORD(result->m_normal.m_y) + 36),
    P: (bfx::Plane *)this);
  return (bfx::Plane *)v2;
}


// ========================================================================
// ?GetOtherVolume@Portal@bfx@@QBAPBVVolume@2@ABV32@@Z
// EA  : 0x8329E4A8
// RVA : 0x0129E4A8
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

const bfx::Volume *__fastcall bfx::Portal::GetOtherVolume(bfx::Portal *this, const bfx::Volume *vol)
{
  bfx::Volume *m_pVolume0; // r11

  m_pVolume0 = this->m_pVolume0;
  if ( vol == m_pVolume0 )
    return this->m_pVolume1;
  else
    return this->m_pVolume1 != vol ? nullptr : m_pVolume0;
}


// ========================================================================
// ?GetVolumeFrom@Portal@bfx@@QBAPBVVolume@2@W4PortalDirection@2@@Z
// EA  : 0x8329E4D8
// RVA : 0x0129E4D8
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

const bfx::Volume *__fastcall bfx::Portal::GetVolumeFrom(bfx::Portal *this, bfx::PortalDirection dir)
{
  if ( dir != PORTAL_DIR_FORWARD )
    return this->m_pVolume1;
  else
    return this->m_pVolume0;
}


// ========================================================================
// ?GetVolumeTo@Portal@bfx@@QBAPBVVolume@2@W4PortalDirection@2@@Z
// EA  : 0x8329E4F0
// RVA : 0x0129E4F0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

const bfx::Volume *__fastcall bfx::Portal::GetVolumeTo(bfx::Portal *this, bfx::PortalDirection dir)
{
  if ( dir != PORTAL_DIR_FORWARD )
    return this->m_pVolume0;
  else
    return this->m_pVolume1;
}


// ========================================================================
// ?IsFacePointInPortal@Portal@bfx@@QBA_NABVVec3@2@M@Z
// EA  : 0x8329E508
// RVA : 0x0129E508
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

int __fastcall bfx::Portal::IsFacePointInPortal(bfx::Portal *this, const bfx::Vec3 *P, double tol)
{
  double v3; // fp31
  int v4; // r8
  float *v5; // r7
  int v6; // r10
  unsigned int v7; // r6
  unsigned int v8; // r11
  int v9; // r8
  double v10; // fp8
  int v11; // r10
  double v12; // fp7
  double v13; // fp6
  double v14; // fp12
  double v15; // fp13
  double v16; // fp0
  float v17; // r5
  float v18; // r7
  double v19; // fp1
  double v20; // fp0
  double v21; // fp27
  double v22; // fp12
  double v23; // fp13
  float v25; // [sp+50h] [-60h]
  float v26; // [sp+50h] [-60h]
  float v27; // [sp+54h] [-5Ch]
  float v28; // [sp+58h] [-58h]
  bfx::Plane v29; // [sp+60h] [-50h] BYREF

  v3 = (float)((float)tol * (float)tol);
  bfx::GetPlaneThroughPoints(
    p0: this->m_pRes->m_verts,
    p1: &this->m_pRes->m_verts[1],
    p2: &this->m_pRes->m_verts[2],
    P: &v29);
  v6 = *(_DWORD *)(v4 + 4);
  v7 = 0;
  v8 = *(_DWORD *)(v6 + 8);
  v25 = *(float *)(12 * v8 + v6);
  v27 = *(float *)(12 * v8 + v6 + 4);
  v28 = *(float *)(12 * v8 + v6 + 8);
  if ( v8 == 0 )
    return 1;
  v9 = *(_DWORD *)(v4 + 4);
  v10 = *v5;
  v11 = 0;
  v12 = v5[1];
  v13 = v5[2];
  v14 = v28;
  v15 = v27;
  v16 = v25;
  while ( 1 )
  {
    v17 = *(float *)(v11 + v9 + 16);
    v18 = *(float *)(v11 + v9 + 20);
    v26 = *(float *)(v11 + v9 + 12);
    v19 = (float)(v26 - (float)v16);
    v20 = (float)((float)((float)(v18 - (float)v14) * (float)((float)v10 - v26))
                - (float)((float)((float)v13 - v18) * (float)(v26 - (float)v16)));
    v21 = (float)((float)((float)(v18 - (float)v14) * (float)(v18 - (float)v14))
                + (float)((float)(v17 - (float)v15) * (float)(v17 - (float)v15)));
    v22 = (float)((float)((float)((float)v13 - v18) * (float)(v17 - (float)v15))
                - (float)((float)((float)v12 - v17) * (float)(v18 - (float)v14)));
    v23 = (float)((float)((float)((float)v12 - v17) * (float)v19)
                - (float)((float)(v17 - (float)v15) * (float)((float)v10 - v26)));
    if ( (float)((float)((float)v22 * (float)v22)
               + (float)((float)((float)v23 * (float)v23) + (float)((float)v20 * (float)v20))) > (double)(float)((float)((float)((float)v19 * (float)v19) + (float)v21) * (float)v3)
      && (float)((float)((float)v22 * v29.m_normal.m_x)
               + (float)((float)(v29.m_normal.m_z * (float)v23) + (float)(v29.m_normal.m_y * (float)v20))) < 0.0 )
    {
      break;
    }
    ++v7;
    v16 = v26;
    v15 = v17;
    v11 += 12;
    v14 = v18;
    if ( v7 >= v8 )
      return 1;
  }
  return 0;
}


// ========================================================================
// ?GetClosestPosOnPolyline@bfx@@YA?AVVec3@1@ABV21@QBV21@I@Z
// EA  : 0x8329E680
// RVA : 0x0129E680
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

bfx::Vec3 *__fastcall bfx::GetClosestPosOnPolyline(
        bfx::Vec3 *result,
        const bfx::Vec3 *testPos,
        const bfx::Vec3 *polygon,
        unsigned int numVerts)
{
  const bfx::Vec3 *v4; // r11
  double v5; // fp3
  float m_x; // r8
  float m_y; // r7
  float m_z; // r11
  double v9; // fp9
  double v10; // fp8
  double v11; // fp7
  double v12; // fp12
  double v13; // fp13
  double v14; // fp0
  float v15; // r10
  float v16; // r9
  double v21; // fp13
  double v22; // fp12
  double v23; // fp0
  double v24; // fp11
  float v25; // [sp+8h] [-58h]

  v4 = &polygon[numVerts];
  v5 = 3.4028235e38;
  m_x = v4[-1].m_x;
  m_y = v4[-1].m_y;
  m_z = v4[-1].m_z;
  result->m_x = m_x;
  result->m_y = m_y;
  result->m_z = m_z;
  if ( numVerts != 0 )
  {
    v9 = testPos->m_x;
    v10 = testPos->m_y;
    v11 = testPos->m_z;
    v12 = m_z;
    v13 = m_y;
    v14 = m_x;
    do
    {
      v15 = polygon->m_x;
      v16 = polygon->m_y;
      v25 = polygon->m_z;
      _FP11 = (float)((float)((float)((float)((float)v9 - (float)v14) * (float)(v15 - (float)v14))
                            + (float)((float)((float)((float)v11 - (float)v12) * (float)(v25 - (float)v12))
                                    + (float)((float)((float)v10 - (float)v13) * (float)(v16 - (float)v13))))
                    / (float)((float)((float)((float)(v15 - (float)v14) * (float)(v15 - (float)v14))
                                    + (float)((float)((float)(v25 - (float)v12) * (float)(v25 - (float)v12))
                                            + (float)((float)(v16 - (float)v13) * (float)(v16 - (float)v13))))
                            + (float)1.0842022e-19));
      __asm { fsel      f11, f11, f11, f1 }
      _FP31 = (float)((float)_FP11 - (float)1.0);
      __asm { fsel      f11, f31, f10, f11 }
      v21 = (float)((float)((float)(v16 - (float)v13) * (float)_FP11) + (float)v13);
      v22 = (float)((float)((float)(v25 - (float)v12) * (float)_FP11) + (float)v12);
      v23 = (float)((float)((float)(polygon->m_x - (float)v14) * (float)_FP11) + (float)v14);
      v24 = __fsqrts((float)((float)((float)((float)v23 - (float)v9) * (float)((float)v23 - (float)v9))
                           + (float)((float)((float)((float)v22 - (float)v11) * (float)((float)v22 - (float)v11))
                                   + (float)((float)((float)v21 - (float)v10) * (float)((float)v21 - (float)v10)))));
      if ( v24 < v5 )
      {
        result->m_x = v23;
        v5 = v24;
        result->m_y = v21;
        result->m_z = v22;
      }
      --numVerts;
      v14 = v15;
      v13 = v16;
      ++polygon;
      v12 = v25;
    }
    while ( numVerts != 0 );
  }
  return result;
}


// ========================================================================
// ?GetClosestPosOnPortalPerimeter@Portal@bfx@@QBA?AVVec3@2@ABV32@@Z
// EA  : 0x8329E808
// RVA : 0x0129E808
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

bfx::Vec3 *__fastcall bfx::Portal::GetClosestPosOnPortalPerimeter(
        bfx::Portal *this,
        bfx::Vec3 *result,
        const bfx::Vec3 *testPos)
{
  return bfx::GetClosestPosOnPolyline(
           result: (bfx::Vec3 *)this,
           testPos,
           polygon: (const bfx::Vec3 *)(LODWORD(result->m_y) + 12),
           numVerts: *(_DWORD *)(LODWORD(result->m_y) + 8));
}


// ========================================================================
// ?Translate@Portal@bfx@@QAAXABVVec3@2@@Z
// EA  : 0x8329E848
// RVA : 0x0129E848
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void __fastcall bfx::Portal::Translate(bfx::Portal *this, const bfx::Vec3 *deltaPos)
{
  unsigned int v2; // r10
  double v3; // fp7
  double v4; // fp6
  bfx::PortalResource *m_pRes; // r11
  int v6; // r9
  float *v7; // r11
  double v8; // fp8
  double v9; // fp6

  v2 = 0;
  v3 = (float)(this->m_centroid.m_y + deltaPos->m_y);
  v4 = (float)(this->m_centroid.m_z + deltaPos->m_z);
  this->m_centroid.m_x = this->m_centroid.m_x + deltaPos->m_x;
  this->m_centroid.m_y = v3;
  this->m_centroid.m_z = v4;
  m_pRes = this->m_pRes;
  if ( m_pRes->m_numVerts != 0 )
  {
    v6 = 0;
    do
    {
      v7 = (float *)((char *)&m_pRes->m_volIndex0 + v6);
      ++v2;
      v6 += 12;
      v8 = (float)(v7[5] + deltaPos->m_z);
      v9 = (float)(v7[3] + deltaPos->m_x);
      v7[4] = v7[4] + deltaPos->m_y;
      v7[5] = v8;
      v7[3] = v9;
      m_pRes = this->m_pRes;
    }
    while ( v2 < m_pRes->m_numVerts );
  }
}


// ========================================================================
// ??$Fix@UVolumeResource@bfx@@@bfx@@YAPAUVolumeResource@0@AAVBinaryImageIn@0@@Z
// EA  : 0x8329E8E8
// RVA : 0x0129E8E8
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

bfx::VolumeResource *__fastcall bfx::Fix<bfx::VolumeResource>(bfx::BinaryImageIn *imageIn)
{
  char *m_pRead; // r28
  char *v3; // r30
  char *v4; // r27
  int v5; // r29
  int i; // r30

  m_pRead = imageIn->m_pRead;
  bfx::BinaryImageIn::FixLong(this: imageIn);
  v3 = imageIn->m_pRead;
  bfx::BinaryImageIn::FixLong(this: imageIn);
  v4 = imageIn->m_pRead;
  v5 = *(_DWORD *)v3;
  bfx::BinaryImageIn::FixLong(this: imageIn);
  for ( i = *(_DWORD *)v4; v5 != 0; --v5 )
  {
    bfx::BinaryImageIn::FixLong(this: imageIn);
    bfx::BinaryImageIn::FixLong(this: imageIn);
    bfx::BinaryImageIn::FixLong(this: imageIn);
    bfx::BinaryImageIn::FixLong(this: imageIn);
  }
  for ( ; i != 0; --i )
  {
    bfx::BinaryImageIn::FixLong(this: imageIn);
    bfx::BinaryImageIn::FixLong(this: imageIn);
  }
  return (bfx::VolumeResource *)m_pRead;
}


// ========================================================================
// ??$Fix@UVolumeGraphResource@bfx@@@bfx@@YAPAUVolumeGraphResource@0@AAVBinaryImageIn@0@@Z
// EA  : 0x8329E980
// RVA : 0x0129E980
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

bfx::VolumeGraphResource *__fastcall bfx::Fix<bfx::VolumeGraphResource>(bfx::BinaryImageIn *imageIn)
{
  char *m_pRead; // r30

  m_pRead = imageIn->m_pRead;
  bfx::BinaryImageIn::FixLong(this: imageIn);
  bfx::BinaryImageIn::FixLong(this: imageIn);
  bfx::BinaryImageIn::FixLong(this: imageIn);
  bfx::BinaryImageIn::FixLong(this: imageIn);
  bfx::BinaryImageIn::FixLong(this: imageIn);
  bfx::BinaryImageIn::FixLong(this: imageIn);
  bfx::BinaryImageIn::FixLong(this: imageIn);
  bfx::BinaryImageIn::FixLong(this: imageIn);
  return (bfx::VolumeGraphResource *)m_pRead;
}


// ========================================================================
// ?CalcRadius@bfx@@YAMABVVec3@1@ABV?$Array@VVec3@bfx@@@1@@Z
// EA  : 0x8329EA98
// RVA : 0x0129EA98
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

float __fastcall bfx::CalcRadius(const bfx::Vec3 *centroid, const bfx::Array<bfx::Vec3> *verts)
{
  bfx::Vec3 *m_data; // r9
  int v4; // r11
  int m_size; // ctr
  double v6; // fp9
  double v7; // fp7
  double v8; // fp5
  double v10; // fp1

  _FP0 = 0.0;
  if ( verts->m_size > 0 )
  {
    m_data = verts->m_data;
    v4 = 0;
    m_size = verts->m_size;
    do
    {
      v6 = (float)(m_data[v4].m_x - centroid->m_x);
      v7 = (float)(m_data[v4].m_z - centroid->m_z);
      v8 = (float)(m_data[v4++].m_y - centroid->m_y);
      _FP1 = (float)((float)((float)((float)v8 * (float)v8)
                           + (float)((float)((float)v6 * (float)v6) + (float)((float)v7 * (float)v7)))
                   - (float)_FP0);
      __asm { fsel      f0, f1, f2, f0 }
      --m_size;
    }
    while ( m_size != 0 );
  }
  v10 = __fsqrts(_FP0);
  return *((float *)&v10 + 1);
}


// ========================================================================
// ?Draw@Portal@bfx@@QBAXABVColor@2@@Z
// EA  : 0x8329EB08
// RVA : 0x0129EB08
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void __fastcall bfx::Portal::Draw(bfx::Portal *this, const bfx::Color *color)
{
  unsigned int v4; // r11
  int v5; // r29
  bfx::PortalResource *m_pRes; // r10
  unsigned int v7; // r31
  unsigned int m_numVerts; // r7
  bfx::Space *m_pSpace; // r3
  float *p_m_x; // r11
  bfx::Vec3 v11; // [sp+50h] [-40h] BYREF
  float v12; // [sp+5Ch] [-34h]
  float v13; // [sp+60h] [-30h]
  float v14; // [sp+64h] [-2Ch]

  v4 = 0;
  if ( this->m_pRes->m_numVerts != 0 )
  {
    v5 = 0;
    do
    {
      m_pRes = this->m_pRes;
      v7 = v4 + 1;
      m_numVerts = m_pRes->m_numVerts;
      m_pSpace = this->m_pParentGraph->m_pSpace;
      v11.m_x = m_pRes->m_verts[v5].m_x;
      __twllei(m_numVerts, 0);
      v11.m_y = m_pRes->m_verts[v5].m_y;
      v11.m_z = m_pRes->m_verts[v5].m_z;
      p_m_x = &m_pRes->m_verts[(v4 + 1) % m_numVerts].m_x;
      v12 = *p_m_x;
      v13 = p_m_x[1];
      v14 = p_m_x[2];
      bfx::DrawLineList(pSpace: m_pSpace, pVerts: &v11, numVerts: 2, color);
      v4 = v7;
      ++v5;
    }
    while ( v7 < this->m_pRes->m_numVerts );
  }
}


// ========================================================================
// bfx::ExtractVertices
// EA  : 0x8329EC78
// RVA : 0x0129EC78
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void __fastcall bfx::ExtractVertices(const bfx::VolumeResource *pVol, bfx::Array<bfx::EndPt> *vertsOut)
{
  unsigned int m_numPlanes; // r9
  unsigned int v5; // r24
  bfx::Plane *m_planes; // r26
  unsigned int v7; // r25
  unsigned int v8; // r28
  const bfx::Plane *v9; // r29
  unsigned int v10; // r30
  const bfx::Plane *v11; // r31
  unsigned int v12; // r9
  char v13; // r8
  unsigned int v14; // r10
  double v15; // fp11
  float *p_m_z; // r11
  bfx::Vec3 v17[2]; // [sp+50h] [-70h] BYREF

  m_numPlanes = pVol->m_numPlanes;
  if ( m_numPlanes != 0 )
  {
    v5 = 1;
    m_planes = pVol->m_planes;
    do
    {
      v7 = v5;
      if ( v5 < m_numPlanes )
      {
        v8 = v5 + 1;
        v9 = m_planes + 1;
        do
        {
          v10 = v8;
          if ( v8 < m_numPlanes )
          {
            v11 = v9 + 1;
            do
            {
              if ( (unsigned __int8)bfx::IntersectPlanes(P1: m_planes, P2: v9, P3: v11, P: v17) != 0 )
              {
                v13 = 1;
                v14 = 0;
                v15 = (float)((float)__fsqrts((float)((float)(v17[0].m_x * v17[0].m_x)
                                                    + (float)((float)(v17[0].m_y * v17[0].m_y)
                                                            + (float)(v17[0].m_z * v17[0].m_z))))
                            * (float)0.0000059600002);
                if ( v12 != 0 )
                {
                  p_m_z = &pVol->m_planes[0].m_normal.m_z;
                  while ( (float)((float)((float)(*(p_m_z - 1) * v17[0].m_y)
                                        + (float)((float)(*(p_m_z - 2) * v17[0].m_x) + (float)(*p_m_z * v17[0].m_z)))
                                - p_m_z[1]) <= v15 )
                  {
                    ++v14;
                    p_m_z += 4;
                    if ( v14 >= v12 )
                      goto LABEL_14;
                  }
                  v13 = 0;
                }
LABEL_14:
                if ( v13 != 0 )
                  bfx::Array<bfx::FollowerBuddyData>::push_back(this: vertsOut, val: (const bfx::EndPt *)v17);
              }
              m_numPlanes = pVol->m_numPlanes;
              ++v10;
              ++v11;
            }
            while ( v10 < m_numPlanes );
          }
          ++v7;
          ++v8;
          ++v9;
        }
        while ( v7 < m_numPlanes );
      }
      ++v5;
      ++m_planes;
    }
    while ( v5 - 1 < m_numPlanes );
  }
}


// ========================================================================
// ??0Volume@bfx@@QAA@PAVVolumeGraph@1@PAUVolumeResource@1@I@Z
// EA  : 0x8329EDD0
// RVA : 0x0129EDD0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

bfx::Volume *__fastcall bfx::Volume::Volume(
        bfx::Volume *this,
        bfx::VolumeGraph *pParentGraph,
        bfx::VolumeResource *pRes,
        unsigned int volumeIndex)
{
  bfx::bfxMemTag v5; // r10
  __int64 v6; // r10
  __int64 v7; // r8
  __int64 v8; // r4
  __int64 v9; // r6
  char *m_data; // r29
  int v12; // [sp+8h] [-98h]
  int v13; // [sp+Ch] [-94h]
  int v14; // [sp+10h] [-90h]
  int v15; // [sp+14h] [-8Ch]
  bfx::Vec3 v16[2]; // [sp+58h] [-48h] BYREF
  bfx::Array<bfx::EndPt> v17[3]; // [sp+70h] [-30h] BYREF

  this->m_pProxy = nullptr;
  this->m_pParentGraph = pParentGraph;
  this->m_volumeIndex = volumeIndex;
  this->m_pRes = pRes;
  this->m_islandID = 1023;
  this->__vftable = (bfx::Volume_vtbl *)&bfx::Volume::`vftable';
  this->m_radius = 0.0;
  this->m_userData = pRes->m_userData;
  v5 = bfx::MEM_BFXPLANNER3D;
  this->m_portals.m_data = nullptr;
  this->m_portals.m_size = 0;
  this->m_portals.m_cap = 0;
  this->m_portals.m_tag = v5;
  memset(v17, 0, 12);
  v17[0].m_tag = MEM_TEMP;
  bfx::ExtractVertices(pVol: this->m_pRes, vertsOut: v17);
  HIDWORD(v9) = v17[0].m_size;
  m_data = (char *)v17[0].m_data;
  if ( v17[0].m_size >= 4 )
  {
    this->m_centroid = *bfx::CalcCentroid(result: v16, pPts: (const bfx::Vec3 *)v17[0].m_data, numPts: v17[0].m_size);
    this->m_radius = bfx::CalcRadius(centroid: &this->m_centroid, verts: (const bfx::Array<bfx::Vec3> *)v17);
  }
  else
  {
    HIDWORD(v8) = "Cannot create planner volume";
    bfx::InternalWarning(fmt: v8, a2: v9, a3: v7, a4: v6, a5: v12, a6: v13, a7: v14, a8: v15);
  }
  if ( m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
  return this;
}


// ========================================================================
// __unwind$21596
// EA  : 0x8329EEEC
// RVA : 0x0129EEEC
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void _unwind_21596()
{
  int v0; // r12

  bfx::HandleTargetBase::~HandleTargetBase(this: *(bfx::HandleTargetBase **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$21597
// EA  : 0x8329EF14
// RVA : 0x0129EF14
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void _unwind_21597()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 160 + 180)
                                                                                             + 44));
}


// ========================================================================
// __unwind$21598
// EA  : 0x8329EF40
// RVA : 0x0129EF40
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void _unwind_21598()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 160 + 112));
}


// ========================================================================
// ??1Volume@bfx@@UAA@XZ
// EA  : 0x8329EF70
// RVA : 0x0129EF70
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void __fastcall bfx::Volume::~Volume(bfx::Volume *this)
{
  char *m_data; // r4

  this->__vftable = (bfx::Volume_vtbl *)&bfx::Volume::`vftable';
  m_data = (char *)this->m_portals.m_data;
  this->m_portals.m_size = 0;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_portals.m_data = nullptr;
  }
  this->m_portals.m_cap = 0;
  bfx::HandleTargetBase::~HandleTargetBase(this);
}


// ========================================================================
// __unwind$21679
// EA  : 0x8329EFD0
// RVA : 0x0129EFD0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void _unwind_21679()
{
  int v0; // r12

  bfx::HandleTargetBase::~HandleTargetBase(this: *(bfx::HandleTargetBase **)(v0 - 112 + 132));
}


// ========================================================================
// ?InitPortalsFromResourceIndices@Volume@bfx@@QAAXXZ
// EA  : 0x8329EFF8
// RVA : 0x0129EFF8
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void __fastcall bfx::Volume::InitPortalsFromResourceIndices(bfx::Volume *this)
{
  bfx::VolumeResource *m_pRes; // r11
  unsigned int v3; // r29
  unsigned int m_numPortals; // r9
  int v5; // r11
  bfx::Array<bfx::ReplayLogListenerEntry> *p_m_portals; // r27
  _DWORD *v7; // r31
  int v8; // r10
  bfx::Portal **m_data; // r7
  bfx::ReplayLogListenerEntry v10; // [sp+50h] [-40h] BYREF

  m_pRes = this->m_pRes;
  v3 = 0;
  m_numPortals = m_pRes->m_numPortals;
  v5 = (int)&m_pRes->m_planes[m_pRes->m_numPlanes];
  if ( m_numPortals != 0 )
  {
    p_m_portals = (bfx::Array<bfx::ReplayLogListenerEntry> *)&this->m_portals;
    v7 = (_DWORD *)(v5 - 8);
    do
    {
      v8 = v7[2];
      m_data = this->m_pParentGraph->m_graphPortals.m_data;
      *(_DWORD *)&v10.m_clientOwned = v7[3];
      v10.m_pListener = (bfx::ReplayListener *)m_data[v8];
      bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(this: p_m_portals, val: &v10);
      v7 += 2;
      *v7 = -1;
      ++v3;
    }
    while ( v3 < this->m_pRes->m_numPortals );
  }
}


// ========================================================================
// ?RemovePortalRecord@Volume@bfx@@QAAXPAVPortal@2@@Z
// EA  : 0x8329F088
// RVA : 0x0129F088
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void __fastcall bfx::Volume::RemovePortalRecord(bfx::Volume *this, bfx::Portal *pPortal)
{
  int m_size; // r9
  bfx::Array<bfx::PortalRecord> *p_m_portals; // r31
  int v4; // r11
  bfx::PortalRecord *m_data; // r7
  int i; // r10
  unsigned int v7; // r3
  unsigned int v8; // r11

  m_size = this->m_portals.m_size;
  p_m_portals = &this->m_portals;
  v4 = 0;
  if ( m_size > 0 )
  {
    m_data = p_m_portals->m_data;
    for ( i = 0; m_data[i].m_pPortal != pPortal; ++i )
    {
      if ( ++v4 >= this->m_portals.m_size )
        return;
    }
    v7 = (unsigned int)&p_m_portals->m_data[v4];
    v8 = (unsigned int)&m_data[m_size - 1];
    if ( v7 < v8 )
      blkmov(a1: v7, a2: v7 + 8, a3: 8 * (((v8 - v7 - 1) >> 3) + 1));
    --p_m_portals->m_size;
  }
}


// ========================================================================
// ?SetUserData@Volume@bfx@@QAAXI@Z
// EA  : 0x8329F150
// RVA : 0x0129F150
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void __fastcall bfx::Volume::SetUserData(bfx::Volume *this, unsigned int userData)
{
  bfx::Island3DGraph *m_pIslandGraph; // r26
  int v5; // r9
  int v6; // r8
  int v7; // r7
  int v8; // r6
  int v9; // r8
  int v10; // r7
  int v11; // r6
  int m_size; // r9
  int v13; // r27
  int v14; // r28
  bfx::Portal *m_pPortal; // r11
  int m_pVolume0; // r10
  int m_pVolume1; // r4
  bfx::Planner3D *Planner3D; // r3
  int v19; // r9
  int v20; // r8
  int v21; // r7
  int v22; // r6
  int v23; // r5
  int v24; // r29
  char *m_data; // r4
  int v26; // r30
  int v27; // r11
  int v28; // [sp+8h] [-A8h]
  int v29; // [sp+8h] [-A8h]
  int v30; // [sp+Ch] [-A4h]
  int v31; // [sp+Ch] [-A4h]
  int v32; // [sp+10h] [-A0h]
  int v33; // [sp+10h] [-A0h]
  int v34; // [sp+14h] [-9Ch]
  int v35; // [sp+14h] [-9Ch]
  int v36; // [sp+18h] [-98h]
  int v37; // [sp+18h] [-98h]
  bfx::Space *v38; // [sp+1Ch] [-94h]
  bfx::Space *v39; // [sp+1Ch] [-94h]
  bfx::Array<bfx::Space *> v40[6]; // [sp+50h] [-60h] BYREF

  if ( this->m_userData != userData )
  {
    m_pIslandGraph = bfx::GetPlanner3D(pSpace: this->m_pParentGraph->m_pSpace)->m_pIslandGraph;
    memset(v40, 0, 12);
    v40[0].m_tag = bfx::MEM_BFXPLANNER3D;
    bfx::Island3DGraph::RemoveIsland(
      this: m_pIslandGraph,
      pStartVolume: (bfx::Space *)this,
      pVolumesTouchedOut: v40,
      a4: v8,
      a5: v7,
      a6: v6,
      a7: v5,
      a8: (int)&_IMPORT_DESCRIPTOR_xam_xex_20500_0_1861,
      a9: v28,
      a10: v30,
      a11: v32,
      a12: v34,
      a13: v36,
      a14: v38);
    m_size = this->m_portals.m_size;
    v13 = 0;
    if ( m_size > 0 )
    {
      v14 = 0;
      do
      {
        m_pPortal = this->m_portals.m_data[v14].m_pPortal;
        m_pVolume0 = (int)m_pPortal->m_pVolume0;
        if ( this == (bfx::Volume *)m_pVolume0 )
        {
          m_pVolume1 = (int)m_pPortal->m_pVolume1;
        }
        else
        {
          m_size = (char *)m_pPortal->m_pVolume1 - (char *)this;
          v9 = m_size - 1;
          v11 = (m_pPortal->m_pVolume1 != this) - 1;
          m_pVolume1 = v11 & m_pVolume0;
        }
        if ( *(_DWORD *)(m_pVolume1 + 36) != 1023 )
          bfx::Island3DGraph::RemoveIsland(
            this: m_pIslandGraph,
            pStartVolume: (bfx::Space *)m_pVolume1,
            pVolumesTouchedOut: v40,
            a4: v11,
            a5: v10,
            a6: v9,
            a7: m_size,
            a8: m_pVolume0,
            a9: v29,
            a10: v31,
            a11: v33,
            a12: v35,
            a13: v37,
            a14: v39);
        ++v13;
        ++v14;
      }
      while ( v13 < this->m_portals.m_size );
    }
    this->m_userData = userData;
    Planner3D = bfx::GetPlanner3D(pSpace: this->m_pParentGraph->m_pSpace);
    bfx::Path3DDatabase::VolumeUserDataChanged(this: Planner3D->m_pPath3DDatabase, pVolume: this);
    v24 = 0;
    m_data = (char *)v40[0].m_data;
    if ( v40[0].m_size > 0 )
    {
      v26 = 0;
      do
      {
        v27 = *(_DWORD *)&m_data[v26];
        if ( *(_DWORD *)(v27 + 36) == 1023 )
        {
          bfx::Island3DGraph::CreateIsland(
            this: m_pIslandGraph,
            pStartVolume: (bfx::Space *)v27,
            a3: v23,
            a4: v22,
            a5: v21,
            a6: v20,
            a7: v19,
            a8: 1023,
            a9: v29,
            a10: v31,
            a11: v33,
            a12: v35,
            a13: v37,
            a14: v39);
          m_data = (char *)v40[0].m_data;
        }
        ++v24;
        v26 += 4;
      }
      while ( v24 < v40[0].m_size );
    }
    v40[0].m_size = 0;
    if ( m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
  }
}


// ========================================================================
// __unwind$21803
// EA  : 0x8329F2B0
// RVA : 0x0129F2B0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void _unwind_21803()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 176 + 80));
}


// ========================================================================
// ?GetClosestPos@Volume@bfx@@QBA?AVVec3@2@ABV32@@Z
// EA  : 0x8329F2E0
// RVA : 0x0129F2E0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

bfx::Volume *__fastcall bfx::Volume::GetClosestPos(bfx::Volume *this, bfx::Vec3 *result, const bfx::Vec3 *pos)
{
  unsigned int v3; // r28
  char *m_data; // r21
  int v8; // r22
  unsigned int v9; // r9
  int v10; // r10
  int v11; // r8
  char *v12; // r11
  float *v13; // r7
  float *v14; // r7
  int v15; // r10
  int v16; // r8
  unsigned int v17; // ctr
  float *v18; // r11
  unsigned int v19; // r10
  char *v20; // r8
  int v21; // r5
  unsigned int v22; // r6
  double v23; // fp0
  unsigned int v24; // r11
  float *v25; // r9
  float *v26; // r9
  unsigned int v27; // ctr
  char *v28; // r11
  bool v29; // cr56
  __int64 v30; // r7
  bfx::ResourceManager::Registration *v31; // r24
  unsigned int v32; // r7
  float m_x; // r8
  char *v34; // r10
  float *p_m_isUpToDateCB; // r11
  float *v36; // r9
  float *v37; // r9
  float *v38; // r9
  float *v39; // r9
  float v40; // r8
  float *v41; // r11
  char *v42; // r9
  unsigned int v43; // ctr
  float *v44; // r10
  float m_y; // r10
  float m_z; // r9
  const bfx::Plane *v47; // r26
  float *v48; // r23
  float v49; // r7
  double v50; // fp11
  float m_d; // r8
  double v52; // fp10
  float v53; // r9
  double v54; // fp9
  double v55; // fp27
  double v56; // fp9
  double v57; // fp26
  double v58; // fp8
  double v59; // fp25
  double v60; // fp31
  double v61; // fp30
  double v62; // fp1
  double v63; // fp31
  double v64; // fp24
  double v65; // fp23
  double v66; // fp22
  float *p_m_termCB; // r8
  double v68; // fp5
  double v69; // fp4
  double v70; // fp3
  double v73; // fp0
  int v74; // r8
  int v75; // r7
  double v76; // fp30
  double v77; // fp29
  double v78; // fp28
  double v79; // fp1
  unsigned int v80; // r27
  const bfx::Plane *v81; // r7
  unsigned int i; // r25
  const bfx::Plane *v83; // r8
  unsigned int v84; // r29
  const bfx::Plane *v85; // r8
  double v86; // fp30
  double v87; // fp29
  double v88; // fp28
  double v89; // fp1
  float v91; // [sp+50h] [-150h]
  bfx::Vec3 v92; // [sp+60h] [-140h] BYREF
  bfx::Vec3 v93; // [sp+70h] [-130h] BYREF
  bfx::Array<bfx::ResourceManager::Registration> v94; // [sp+80h] [-120h] BYREF
  bfx::Array<bfx::ReplayLogListenerEntry> v95; // [sp+90h] [-110h] BYREF
  float v96; // [sp+A0h] [-100h]
  float v97; // [sp+A4h] [-FCh]
  float v98; // [sp+A8h] [-F8h]
  float v99; // [sp+ACh] [-F4h]
  bfx::Plane v100; // [sp+B0h] [-F0h] BYREF

  v3 = 0;
  m_data = nullptr;
  v8 = *(_DWORD *)(LODWORD(result[1].m_x) + 4);
  memset(&v95, 0, 12);
  v95.m_tag = bfx::MEM_BFXPLANNER3D;
  if ( v8 <= 0 )
  {
    if ( v8 >= 0 )
      goto LABEL_5;
  }
  else
  {
    bfx::Array<bfx::NavWedge>::expand_cap(this: &v95, size: v8);
    m_data = (char *)v95.m_data;
  }
  v95.m_size = v8;
LABEL_5:
  v9 = 0;
  if ( v8 >= 4 )
  {
    v10 = 0;
    v11 = 2;
    v12 = m_data - 4;
    do
    {
      *((float *)v12 + 1) = (float)((float)(*(float *)(v10 + LODWORD(result[1].m_x) + 12) * pos->m_x)
                                  + (float)((float)(*(float *)(v10 + LODWORD(result[1].m_x) + 20) * pos->m_z)
                                          + (float)(*(float *)(v10 + LODWORD(result[1].m_x) + 16) * pos->m_y)))
                          - *(float *)(v10 + LODWORD(result[1].m_x) + 24);
      *((_DWORD *)v12 + 2) = v9;
      v9 += 4;
      *((float *)v12 + 3) = (float)((float)(*(float *)(v10 + LODWORD(result[1].m_x) + 28) * pos->m_x)
                                  + (float)((float)(*(float *)(v10 + LODWORD(result[1].m_x) + 36) * pos->m_z)
                                          + (float)(*(float *)(v10 + LODWORD(result[1].m_x) + 32) * pos->m_y)))
                          - *(float *)(v10 + LODWORD(result[1].m_x) + 40);
      *((_DWORD *)v12 + 4) = v11 - 1;
      v13 = (float *)(v10 + LODWORD(result[1].m_x));
      *((float *)v12 + 5) = (float)((float)(v13[11] * pos->m_x)
                                  + (float)((float)(v13[13] * pos->m_z) + (float)(v13[12] * pos->m_y)))
                          - v13[14];
      *((_DWORD *)v12 + 6) = v11;
      v14 = (float *)(v10 + LODWORD(result[1].m_x));
      v10 += 64;
      *((float *)v12 + 7) = (float)((float)(v14[15] * pos->m_x)
                                  + (float)((float)(v14[17] * pos->m_z) + (float)(v14[16] * pos->m_y)))
                          - v14[18];
      v12 += 32;
      *(_DWORD *)v12 = v11 + 1;
      v11 += 4;
    }
    while ( v9 < v8 - 3 );
  }
  if ( v9 < v8 )
  {
    v15 = 16 * v9;
    v16 = (int)&m_data[8 * v9 - 4];
    v17 = v8 - v9;
    do
    {
      v18 = (float *)(v15 + LODWORD(result[1].m_x));
      v15 += 16;
      *(float *)(v16 + 4) = (float)((float)(v18[3] * pos->m_x)
                                  + (float)((float)(v18[5] * pos->m_z) + (float)(v18[4] * pos->m_y)))
                          - v18[6];
      v16 += 8;
      *(_DWORD *)v16 = v9++;
      --v17;
    }
    while ( v17 != 0 );
  }
  v19 = 0;
  if ( v8 != 0 )
  {
    v20 = m_data;
    v21 = v8 - 1;
    do
    {
      v22 = v19 + 1;
      v23 = *(float *)v20;
      v24 = v19 + 1;
      if ( v19 + 1 < v8 )
      {
        if ( v21 >= 4 )
        {
          v25 = (float *)(v20 + 24);
          do
          {
            if ( *(v25 - 4) < v23 )
            {
              v23 = *(v25 - 4);
              v19 = v24;
            }
            if ( *(v25 - 2) < v23 )
            {
              v23 = *(v25 - 2);
              v19 = v24 + 1;
            }
            if ( *v25 < v23 )
            {
              v23 = *v25;
              v19 = v24 + 2;
            }
            if ( v25[2] < v23 )
            {
              v23 = v25[2];
              v19 = v24 + 3;
            }
            v24 += 4;
            v25 += 8;
          }
          while ( v24 < v8 - 3 );
        }
        if ( v24 < v8 )
        {
          v26 = (float *)&m_data[8 * v24];
          v27 = v8 - v24;
          do
          {
            if ( *v26 < v23 )
            {
              v23 = *v26;
              v19 = v24;
            }
            ++v24;
            v26 += 2;
            --v27;
          }
          while ( v27 != 0 );
        }
      }
      v28 = &m_data[8 * v19];
      v19 = v22;
      v29 = v22 < v8;
      --v21;
      v30 = *(_QWORD *)v28;
      *(_DWORD *)v28 = *(_DWORD *)v20;
      HIDWORD(v30) = *((_DWORD *)v20 + 1);
      *((_DWORD *)v28 + 1) = HIDWORD(v30);
      *(_QWORD *)v20 = v30;
      v20 += 8;
    }
    while ( v29 );
  }
  v31 = nullptr;
  memset(&v94, 0, 12);
  v94.m_tag = bfx::MEM_BFXPLANNER3D;
  if ( v8 > 0 )
  {
    bfx::Array<bfx::ClosedNode3D>::expand_cap(this: &v94, size: v8);
    v31 = v94.m_data;
  }
  v32 = 0;
  if ( v8 >= 4 )
  {
    m_x = result[1].m_x;
    v34 = m_data - 4;
    p_m_isUpToDateCB = (float *)&v31[-1].m_isUpToDateCB;
    do
    {
      v32 += 4;
      v36 = (float *)(16 * *((_DWORD *)v34 + 2) + LODWORD(m_x));
      p_m_isUpToDateCB[1] = v36[3];
      p_m_isUpToDateCB[2] = v36[4];
      p_m_isUpToDateCB[3] = v36[5];
      p_m_isUpToDateCB[4] = v36[6];
      v37 = (float *)(16 * *((_DWORD *)v34 + 4) + LODWORD(m_x));
      p_m_isUpToDateCB[5] = v37[3];
      p_m_isUpToDateCB[6] = v37[4];
      p_m_isUpToDateCB[7] = v37[5];
      p_m_isUpToDateCB[8] = v37[6];
      v38 = (float *)(16 * *((_DWORD *)v34 + 6) + LODWORD(m_x));
      p_m_isUpToDateCB[9] = v38[3];
      p_m_isUpToDateCB[10] = v38[4];
      p_m_isUpToDateCB[11] = v38[5];
      p_m_isUpToDateCB[12] = v38[6];
      v34 += 32;
      v39 = (float *)(16 * *(_DWORD *)v34 + LODWORD(m_x));
      p_m_isUpToDateCB[13] = v39[3];
      p_m_isUpToDateCB[14] = v39[4];
      p_m_isUpToDateCB[15] = v39[5];
      p_m_isUpToDateCB += 16;
      *p_m_isUpToDateCB = v39[6];
    }
    while ( v32 < v8 - 3 );
  }
  if ( v32 < v8 )
  {
    v40 = result[1].m_x;
    v41 = (float *)&v31[v32 - 1].m_isUpToDateCB;
    v42 = &m_data[8 * v32 - 4];
    v43 = v8 - v32;
    do
    {
      v42 += 8;
      v44 = (float *)(16 * *(_DWORD *)v42 + LODWORD(v40));
      v41[1] = v44[3];
      v41[2] = v44[4];
      v41[3] = v44[5];
      v41 += 4;
      *v41 = v44[6];
      --v43;
    }
    while ( v43 != 0 );
  }
  m_y = pos->m_y;
  m_z = pos->m_z;
  this->__vftable = (bfx::Volume_vtbl *)LODWORD(pos->m_x);
  *(float *)&this->m_pProxy = m_y;
  *(float *)&this->m_pParentGraph = m_z;
  if ( v8 != 0 )
  {
    v47 = (const bfx::Plane *)v31;
    v48 = (float *)m_data;
    do
    {
      v49 = v47->m_normal.m_x;
      v50 = *(float *)&this->m_pParentGraph;
      m_d = v47->m_d;
      v52 = *(float *)&this->__vftable;
      v53 = v47->m_normal.m_z;
      v54 = *(float *)&this->m_pProxy;
      v97 = v47->m_normal.m_y;
      v96 = v49;
      v99 = m_d;
      v98 = v53;
      if ( (float)((float)((float)((float)v54 * v97) + (float)((float)((float)v52 * v49) + (float)((float)v50 * v53)))
                 - m_d) > 0.0 )
      {
        v55 = pos->m_z;
        v56 = (float)(v97 * *v48);
        v57 = pos->m_y;
        v58 = (float)(v96 * *v48);
        v59 = pos->m_x;
        v60 = (float)(pos->m_y - (float)(v97 * *v48));
        *(float *)&v94.m_cap = pos->m_z - (float)(v98 * *v48);
        *(float *)&v94.m_size = (float)v57 - (float)v56;
        v61 = (float)((float)v59 - (float)v58);
        *(float *)&v94.m_data = (float)v59 - (float)v58;
        if ( (unsigned __int8)bfx::PointInSpace(
                                p: (const bfx::Vec3 *)&v94,
                                planes: (const bfx::Plane *)v31,
                                numPlanes: v3) != 0 )
        {
          *(float *)&this->__vftable = v61;
          *(float *)&this->m_pProxy = v60;
          *(float *)&this->m_pParentGraph = v62;
        }
        else
        {
          v63 = 3.4028235e38;
          v64 = 0.0;
          v65 = 0.0;
          v66 = 0.0;
          if ( v3 != 0 )
          {
            p_m_termCB = (float *)&v31->m_termCB;
            do
            {
              v68 = (float)((float)(v47->m_normal.m_x * *p_m_termCB) - (float)(v47->m_normal.m_z * *(p_m_termCB - 2)));
              v69 = (float)((float)(v47->m_normal.m_z * *(p_m_termCB - 1)) - (float)(v47->m_normal.m_y * *p_m_termCB));
              v70 = (float)((float)(v47->m_normal.m_y * *(p_m_termCB - 2))
                          - (float)(v47->m_normal.m_x * *(p_m_termCB - 1)));
              _FP12 = (float)((float)__fsqrts((float)((float)((float)v70 * (float)v70)
                                                    + (float)((float)((float)v69 * (float)v69)
                                                            + (float)((float)v68 * (float)v68))))
                            - (float)1.0842022e-19);
              __asm { fsel      f10, f12, f11, f21 }
              v73 = (float)((float)((float)(v47->m_normal.m_z * *(p_m_termCB - 1))
                                  - (float)(v47->m_normal.m_y * *p_m_termCB))
                          * (float)_FP10);
              v91 = (float)((float)(v47->m_normal.m_z * *(p_m_termCB - 1)) - (float)(v47->m_normal.m_y * *p_m_termCB))
                  * (float)_FP10;
              v100.m_normal.m_y = (float)((float)(v47->m_normal.m_x * *p_m_termCB)
                                        - (float)(v47->m_normal.m_z * *(p_m_termCB - 2)))
                                * (float)_FP10;
              v100.m_normal.m_x = v91;
              v100.m_normal.m_z = (float)v70 * (float)_FP10;
              v100.m_d = (float)((float)v55 * v100.m_normal.m_z)
                       + (float)((float)((float)v59 * (float)v73)
                               + (float)((float)v57 * (float)((float)v68 * (float)_FP10)));
              if ( (unsigned __int8)bfx::IntersectPlanes(
                                      P1: v47,
                                      P2: (const bfx::Plane *)(p_m_termCB - 2),
                                      P3: &v100,
                                      P: &v92) != 0 )
              {
                v76 = v92.m_y;
                v77 = v92.m_x;
                v78 = v92.m_z;
                if ( (float)((float)((float)(v92.m_z - (float)v55) * (float)(v92.m_z - (float)v55))
                           + (float)((float)((float)(v92.m_x - (float)v59) * (float)(v92.m_x - (float)v59))
                                   + (float)((float)(v92.m_y - (float)v57) * (float)(v92.m_y - (float)v57)))) < v63
                  && (unsigned __int8)bfx::PointInSpace(p: &v92, planes: (const bfx::Plane *)v31, numPlanes: v3) != 0 )
                {
                  v63 = v79;
                  v64 = v77;
                  v65 = v76;
                  v66 = v78;
                }
              }
              p_m_termCB = (float *)(v74 + 16);
            }
            while ( v75 != 1 );
            v80 = 1;
            v81 = (const bfx::Plane *)v31;
            for ( i = v3; i != 0; --i )
            {
              if ( v80 < v3 )
              {
                v83 = v81 + 1;
                v84 = v3 - v80;
                do
                {
                  if ( (unsigned __int8)bfx::IntersectPlanes(P1: v47, P2: v81, P3: v83, P: &v93) != 0 )
                  {
                    v86 = v93.m_y;
                    v87 = v93.m_x;
                    v88 = v93.m_z;
                    if ( (float)((float)((float)(v93.m_z - (float)v55) * (float)(v93.m_z - (float)v55))
                               + (float)((float)((float)(v93.m_x - (float)v59) * (float)(v93.m_x - (float)v59))
                                       + (float)((float)(v93.m_y - (float)v57) * (float)(v93.m_y - (float)v57)))) < v63
                      && (unsigned __int8)bfx::PointInSpace(p: &v93, planes: (const bfx::Plane *)v31, numPlanes: v3) != 0 )
                    {
                      v63 = v89;
                      v64 = v87;
                      v65 = v86;
                      v66 = v88;
                    }
                  }
                  --v84;
                  v83 = v85 + 1;
                }
                while ( v84 != 0 );
              }
              ++v80;
              ++v81;
            }
            if ( v63 < 3.4028235e38 )
            {
              *(float *)&this->__vftable = v64;
              *(float *)&this->m_pProxy = v65;
              *(float *)&this->m_pParentGraph = v66;
            }
          }
        }
      }
      ++v3;
      v48 += 2;
      ++v47;
    }
    while ( v3 < v8 );
  }
  if ( v31 != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v31);
  if ( m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
  return this;
}


// ========================================================================
// __unwind$21997
// EA  : 0x8329FA9C
// RVA : 0x0129FA9C
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void _unwind_21997()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 416 + 144));
}


// ========================================================================
// __unwind$21998
// EA  : 0x8329FAC4
// RVA : 0x0129FAC4
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void _unwind_21998()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 416 + 128));
}


// ========================================================================
// ?CalcVertsForFace@Volume@bfx@@QAAXIAAV?$Array@VVec3@bfx@@@2@@Z
// EA  : 0x8329FAF0
// RVA : 0x0129FAF0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void __fastcall bfx::Volume::CalcVertsForFace(
        bfx::Volume *this,
        unsigned int faceIndex,
        bfx::Array<bfx::EndPt> *vertsOut)
{
  bfx::VolumeResource *m_pRes; // r11
  unsigned int v7; // r26
  int v8; // r25
  double m_minS; // fp0
  char v10; // r30
  unsigned int v11; // r29
  bfx::VolumeResource *v12; // r5
  int v13; // r28
  float *v14; // r11
  float v15; // r9
  float v16; // r8
  float v17; // r10
  bfx::EndPt v18; // [sp+60h] [-C0h] BYREF
  bfx::Plane v19; // [sp+70h] [-B0h] BYREF
  bfx::Line v20; // [sp+80h] [-A0h] BYREF
  bfx::LineSegParameterized v21; // [sp+A0h] [-80h] BYREF

  m_pRes = this->m_pRes;
  v7 = 0;
  if ( m_pRes->m_numPlanes != 0 )
  {
    v8 = 0;
    do
    {
      if ( v7 != faceIndex
        && bfx::IntersectTwoPlanes(
             plane1: &this->m_pRes->m_planes[faceIndex],
             plane2: &this->m_pRes->m_planes[v8],
             lineOut: &v20) )
      {
        m_minS = -3.4028235e38;
        v21.m_minS = -3.4028235e38;
        v21.m_maxS = 3.4028235e38;
        v10 = 1;
        v11 = 0;
        v12 = this->m_pRes;
        v21.m_pos.m_x = v20.m_pos.m_x;
        v21.m_pos.m_y = v20.m_pos.m_y;
        v21.m_pos.m_z = v20.m_pos.m_z;
        v21.m_dir = v20.m_dir;
        if ( v12->m_numPlanes != 0 )
        {
          v13 = 0;
          do
          {
            if ( v11 != faceIndex && v11 != v7 )
            {
              v14 = (float *)((char *)&this->m_pRes->m_userData + v13);
              v15 = v14[3] * (float)-1.0;
              v16 = v14[4] * (float)-1.0;
              v17 = v14[5] * (float)-1.0;
              v19.m_d = v14[6] * (float)-1.0;
              v19.m_normal.m_z = v17;
              v19.m_normal.m_y = v16;
              v19.m_normal.m_x = v15;
              v10 &= bfx::ClipLineSegParameterizedAgainstPlane(plane: &v19, seg: &v21);
              if ( v10 == 0 )
                break;
            }
            ++v11;
            v13 += 16;
          }
          while ( v11 < this->m_pRes->m_numPlanes );
          m_minS = v21.m_minS;
        }
        if ( v10 != 0 && (float)(v21.m_maxS - (float)m_minS) > 1.0842022e-19 )
        {
          v18.m_val = v21.m_pos.m_x + (float)(v21.m_dir.m_x * (float)m_minS);
          *(float *)&v18.m_pAABB = v21.m_pos.m_y + (float)(v21.m_dir.m_y * (float)m_minS);
          *(float *)&v18.m_type = v21.m_pos.m_z + (float)(v21.m_dir.m_z * (float)m_minS);
          bfx::Array<bfx::FollowerBuddyData>::push_back(this: vertsOut, val: &v18);
        }
      }
      m_pRes = this->m_pRes;
      ++v7;
      ++v8;
    }
    while ( v7 < m_pRes->m_numPlanes );
  }
  bfx::SortFaceVertsCCW(facePlane: &m_pRes->m_planes[faceIndex], faceVerts: (bfx::Array<bfx::Vec3> *)vertsOut);
}


// ========================================================================
// ?ProbeFrom@Volume@bfx@@QBA_NABVVec3@2@AAV32@AAIAAPBVPortal@2@HH@Z
// EA  : 0x8329FD08
// RVA : 0x0129FD08
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

int __fastcall bfx::Volume::ProbeFrom(
        bfx::Volume *this,
        const bfx::Vec3 *startPos,
        bfx::Vec3 *endPos,
        unsigned int *hitPlaneIndex,
        const bfx::Portal **pHitPortal,
        int ignorePlaneIndex0,
        int ignorePlaneIndex1)
{
  double v14; // fp30
  double v15; // fp29
  double v16; // fp28
  double Scale; // fp1
  bfx::VolumeResource *m_pRes; // r10
  float m_y; // r6
  float m_z; // r4
  unsigned int m_numPlanes; // r11
  double v22; // fp31
  double v23; // fp26
  double v24; // fp25
  unsigned int v25; // r29
  double m_x; // fp24
  double v27; // fp23
  unsigned int v28; // r26
  int v29; // r27
  double v30; // fp13
  double v31; // fp11
  double v32; // fp10
  float v33; // r10
  float v34; // r9
  int v35; // r30
  int m_size; // r27
  bfx::PortalRecord *m_data; // r28
  int i; // r31
  bfx::Portal **p_m_pPortal; // r11
  const bfx::Portal *v40; // r29
  float v42[2]; // [sp+50h] [-F0h] BYREF
  bfx::Vec3 v43; // [sp+58h] [-E8h] BYREF
  bfx::Vec3 v44; // [sp+68h] [-D8h] BYREF
  bfx::Plane v45; // [sp+80h] [-C0h] BYREF

  v14 = (float)(endPos->m_x - startPos->m_x);
  v15 = (float)(endPos->m_y - startPos->m_y);
  v16 = (float)(endPos->m_z - startPos->m_z);
  Scale = bfx::GetScale();
  m_pRes = this->m_pRes;
  m_y = endPos->m_y;
  m_z = endPos->m_z;
  m_numPlanes = m_pRes->m_numPlanes;
  v43.m_x = endPos->m_x;
  v22 = 3.4028235e38;
  v43.m_y = m_y;
  v43.m_z = m_z;
  v23 = m_z;
  v24 = m_y;
  v25 = 0;
  m_x = v43.m_x;
  v27 = (float)((float)Scale * (float)0.000099999997);
  v28 = m_numPlanes;
  if ( m_numPlanes != 0 )
  {
    v29 = 0;
    do
    {
      if ( v25 != ignorePlaneIndex0 && v25 != ignorePlaneIndex1 )
      {
        v30 = startPos->m_x;
        v31 = startPos->m_z;
        v32 = startPos->m_y;
        v45 = m_pRes->m_planes[v29];
        if ( (float)((float)((float)(v45.m_normal.m_y * (float)v32)
                           + (float)((float)((float)v31 * v45.m_normal.m_z) + (float)((float)v30 * v45.m_normal.m_x)))
                   - v45.m_d) < v27
          && (float)((float)(v45.m_normal.m_x * (float)v14)
                   + (float)((float)(v45.m_normal.m_z * (float)v16) + (float)(v45.m_normal.m_y * (float)v15))) > 0.0 )
        {
          v33 = endPos->m_y;
          v34 = endPos->m_z;
          v44.m_x = endPos->m_x;
          v44.m_y = v33;
          v44.m_z = v34;
          if ( (unsigned __int8)bfx::IntersectLineAndPlane(startPos, endPos: &v44, P: &v45, t: v42) != 0 && v42[0] < v22 )
          {
            m_x = v44.m_x;
            v22 = v42[0];
            v24 = v44.m_y;
            v28 = v25;
            v23 = v44.m_z;
          }
        }
      }
      m_pRes = this->m_pRes;
      ++v25;
      ++v29;
      m_numPlanes = m_pRes->m_numPlanes;
    }
    while ( v25 < m_numPlanes );
    v43.m_z = v23;
    v43.m_y = v24;
    v43.m_x = m_x;
  }
  if ( v28 >= m_numPlanes )
  {
    *hitPlaneIndex = -1;
    *pHitPortal = nullptr;
    return 0;
  }
  else
  {
    endPos->m_y = v24;
    v35 = 0;
    endPos->m_z = v23;
    endPos->m_x = m_x;
    *hitPlaneIndex = v28;
    *pHitPortal = nullptr;
    m_size = this->m_portals.m_size;
    if ( m_size > 0 )
    {
      m_data = this->m_portals.m_data;
      for ( i = 0; ; ++i )
      {
        p_m_pPortal = &m_data[i].m_pPortal;
        if ( m_data[i].m_planeIndex == v28 )
        {
          v40 = *p_m_pPortal;
          if ( (unsigned __int8)bfx::Portal::IsFacePointInPortal(this: *p_m_pPortal, P: &v43, tol: 0.0) != 0 )
            break;
        }
        if ( ++v35 >= m_size )
          return 1;
      }
      *pHitPortal = v40;
    }
    return 1;
  }
}


// ========================================================================
// ??0VolumeGraph@bfx@@QAA@PAVSpace@1@AAVBinaryImageIn@1@I@Z
// EA  : 0x8329FF88
// RVA : 0x0129FF88
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

bfx::VolumeGraph *__fastcall bfx::VolumeGraph::VolumeGraph(
        bfx::VolumeGraph *this,
        bfx::Space *pSpace,
        bfx::BinaryImageIn *imageIn,
        unsigned int replayID)
{
  bfx::Array<bfx::SpaceComponent *> *p_m_graphVolumes; // r25
  bfx::bfxMemTag v7; // r11
  bfx::bfxMemTag v8; // r11
  bfx::Array<bfx::SpaceComponent *> *p_m_graphPortals; // r26
  bfx::bfxMemTag v10; // r11
  bfx::VolumeGraphResource *v11; // r3
  int m_numVolumes; // r4
  unsigned int i; // r28
  bfx::VolumeResource *v14; // r29
  bfx::Space *v15; // r3
  bfx::Space *v16; // r3
  signed int m_numPortals; // r4
  unsigned int j; // r20
  char *m_pRead; // r29
  char *v20; // r28
  int k; // r28
  bfx::SpaceComponent *v22; // r28
  bfx::SpaceComponent *v23; // r27
  bfx::VolumeGraph **v24; // r3
  bfx::Vec3 *v25; // r3
  int v26; // r7
  bfx::SpaceComponent *v27; // r28
  int m_cap; // r10
  int m_size; // r11
  int v30; // r4
  bfx::SpaceComponent **v31; // r11
  bool v32; // cr34
  int v33; // r28
  int v34; // r29
  bfx::Array<bfx::PortalResource *> *p_m_dynamicPortalResources; // [sp+50h] [-90h] BYREF
  bfx::Vec3 v37[11]; // [sp+58h] [-88h] BYREF

  this->m_pSpace = pSpace;
  this->m_pBinaryImage = imageIn->m_pImage;
  p_m_graphVolumes = (bfx::Array<bfx::SpaceComponent *> *)&this->m_graphVolumes;
  this->m_pResourceImage = imageIn->m_pRead;
  v7 = bfx::MEM_BFXPLANNER3D;
  this->m_graphVolumes.m_data = nullptr;
  this->m_graphVolumes.m_size = 0;
  this->m_graphVolumes.m_cap = 0;
  this->m_graphVolumes.m_tag = v7;
  v8 = bfx::MEM_BFXPLANNER3D;
  p_m_graphPortals = (bfx::Array<bfx::SpaceComponent *> *)&this->m_graphPortals;
  this->m_graphPortals.m_data = nullptr;
  this->m_graphPortals.m_size = 0;
  this->m_graphPortals.m_cap = 0;
  this->m_graphPortals.m_tag = v8;
  v10 = bfx::MEM_BFXPLANNER3D;
  this->m_dynamicPortalResources.m_data = nullptr;
  this->m_dynamicPortalResources.m_size = 0;
  this->m_dynamicPortalResources.m_cap = 0;
  p_m_dynamicPortalResources = &this->m_dynamicPortalResources;
  this->m_dynamicPortalResources.m_tag = v10;
  this->m_replayID = replayID;
  v11 = bfx::Fix<bfx::VolumeGraphResource>(imageIn);
  this->m_pHdr = v11;
  m_numVolumes = v11->m_numVolumes;
  if ( m_numVolumes > this->m_graphVolumes.m_cap )
    bfx::Array<bfx::Edge *>::expand_cap(this: p_m_graphVolumes, size: m_numVolumes);
  for ( i = 0; i < this->m_pHdr->m_numVolumes; ++i )
  {
    v14 = bfx::Fix<bfx::VolumeResource>(imageIn);
    v15 = (bfx::Space *)bfx::MemoryManager::Malloc(
                          this: bfx::g_pCurInstance->m_pMemoryManager,
                          size: 0x3Cu,
                          tag: bfx::MEM_BFXPLANNER3D);
    p_m_dynamicPortalResources = (bfx::Array<bfx::PortalResource *> *)v15;
    if ( v15 != nullptr )
      v16 = (bfx::Space *)bfx::Volume::Volume(this: (bfx::Volume *)v15, pParentGraph: this, pRes: v14, volumeIndex: i);
    else
      v16 = nullptr;
    p_m_dynamicPortalResources = (bfx::Array<bfx::PortalResource *> *)v16;
    bfx::Array<bfx::Portal *>::push_back(
      this: (bfx::Array<bfx::Space *> *)p_m_graphVolumes,
      val: (bfx::Space **)&p_m_dynamicPortalResources);
  }
  m_numPortals = this->m_pHdr->m_numPortals;
  if ( m_numPortals > p_m_graphPortals->m_cap )
    bfx::Array<bfx::Edge *>::expand_cap(this: p_m_graphPortals, size: m_numPortals);
  for ( j = 0; j < this->m_pHdr->m_numPortals; *((_DWORD *)m_pRead + 1) = -1 )
  {
    m_pRead = imageIn->m_pRead;
    bfx::BinaryImageIn::FixLong(this: imageIn);
    bfx::BinaryImageIn::FixLong(this: imageIn);
    v20 = imageIn->m_pRead;
    bfx::BinaryImageIn::FixLong(this: imageIn);
    for ( k = *(_DWORD *)v20; k != 0; --k )
    {
      bfx::BinaryImageIn::FixLong(this: imageIn);
      bfx::BinaryImageIn::FixLong(this: imageIn);
      bfx::BinaryImageIn::FixLong(this: imageIn);
    }
    v22 = p_m_graphVolumes->m_data[*(_DWORD *)m_pRead];
    v23 = p_m_graphVolumes->m_data[*((_DWORD *)m_pRead + 1)];
    v24 = (bfx::VolumeGraph **)bfx::MemoryManager::Malloc(
                                 this: bfx::g_pCurInstance->m_pMemoryManager,
                                 size: 0x1Cu,
                                 tag: bfx::MEM_BFXPLANNER3D);
    if ( v24 != nullptr )
    {
      v24[5] = (bfx::VolumeGraph *)v22;
      v24[1] = (bfx::VolumeGraph *)m_pRead;
      *v24 = this;
      v24[6] = (bfx::VolumeGraph *)v23;
      v25 = bfx::CalcCentroid(result: v37, pPts: (const bfx::Vec3 *)m_pRead + 1, numPts: *((_DWORD *)m_pRead + 2));
      *(float *)(v26 + 8) = v25->m_x;
      v27 = (bfx::SpaceComponent *)v26;
      p_m_dynamicPortalResources = (bfx::Array<bfx::PortalResource *> *)(v26 + 8);
      *(float *)(v26 + 12) = v25->m_y;
      *(float *)(v26 + 16) = v25->m_z;
    }
    else
    {
      v27 = nullptr;
    }
    m_cap = p_m_graphPortals->m_cap;
    m_size = p_m_graphPortals->m_size;
    if ( m_cap == m_size )
    {
      v30 = 2 * m_cap;
      if ( m_cap == 0 )
        v30 = 1;
      bfx::Array<bfx::Edge *>::expand_cap(this: p_m_graphPortals, size: v30);
      v31 = &p_m_graphPortals->m_data[p_m_graphPortals->m_size];
      v32 = v31 == nullptr;
    }
    else
    {
      v31 = &p_m_graphPortals->m_data[m_size];
      v32 = v31 == nullptr;
    }
    if ( !v32 )
      *v31 = v27;
    ++j;
    ++p_m_graphPortals->m_size;
    *(_DWORD *)m_pRead = -1;
  }
  v33 = 0;
  if ( p_m_graphVolumes->m_size > 0 )
  {
    v34 = 0;
    do
    {
      bfx::Volume::InitPortalsFromResourceIndices(this: (bfx::Volume *)p_m_graphVolumes->m_data[v34]);
      ++v33;
      ++v34;
    }
    while ( v33 < p_m_graphVolumes->m_size );
  }
  return this;
}


// ========================================================================
// __unwind$22630
// EA  : 0x832A0280
// RVA : 0x012A0280
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void _unwind_22630()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 224 + 244)
                                                                                             + 16));
}


// ========================================================================
// __unwind$22631
// EA  : 0x832A02AC
// RVA : 0x012A02AC
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void _unwind_22631()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 224 + 244)
                                                                                             + 32));
}


// ========================================================================
// __unwind$22632
// EA  : 0x832A02D8
// RVA : 0x012A02D8
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void _unwind_22632()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 224 + 244)
                                                                                             + 48));
}


// ========================================================================
// __unwind$22633
// EA  : 0x832A0304
// RVA : 0x012A0304
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void _unwind_22633()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 224 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?CreatePortalBetweenTwoVolumes@VolumeGraph@bfx@@QAAXPAVVolume@2@0IIABV?$Array@VVec3@bfx@@@2@@Z
// EA  : 0x832A0330
// RVA : 0x012A0330
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void __fastcall bfx::VolumeGraph::CreatePortalBetweenTwoVolumes(
        bfx::VolumeGraph *this,
        bfx::VolumeGraph *pVolume0,
        bfx::VolumeGraph *pVolume1,
        unsigned int faceIndexOnVolume0,
        unsigned int faceIndexOnVolume1,
        const bfx::Array<bfx::Vec3> *portalVerts)
{
  _DWORD *v12; // r3
  _DWORD *v13; // r30
  int v14; // r10
  float *v15; // r11
  float *v16; // r9
  bfx::VolumeGraph **v17; // r3
  bfx::Vec3 *v18; // r3
  float v19; // r7
  float v20; // r31
  bfx::Vec3 v21[8]; // [sp+50h] [-60h] BYREF

  v12 = (_DWORD *)bfx::MemoryManager::Malloc(
                    this: bfx::g_pCurInstance->m_pMemoryManager,
                    size: 12 * (portalVerts->m_size + 1),
                    tag: bfx::MEM_BFXPLANNER3D);
  LODWORD(v21[0].m_x) = v12;
  v13 = v12;
  *v12 = -1;
  v14 = 0;
  v12[1] = -1;
  v12[2] = portalVerts->m_size;
  if ( portalVerts->m_size > 0 )
  {
    v15 = (float *)(v12 + 5);
    do
    {
      ++v14;
      v16 = (float *)((char *)v15 + (unsigned int)portalVerts->m_data - (_DWORD)v12 - 20);
      *(v15 - 2) = *v16;
      *(v15 - 1) = v16[1];
      *v15 = v16[2];
      v15 += 3;
    }
    while ( v14 < portalVerts->m_size );
  }
  bfx::Array<bfx::Portal *>::push_back(
    this: (bfx::Array<bfx::Space *> *)&this->m_dynamicPortalResources,
    val: (bfx::Space **)v21);
  v17 = (bfx::VolumeGraph **)bfx::MemoryManager::Malloc(
                               this: bfx::g_pCurInstance->m_pMemoryManager,
                               size: 0x1Cu,
                               tag: bfx::MEM_BFXPLANNER3D);
  if ( v17 != nullptr )
  {
    v17[5] = pVolume0;
    *v17 = this;
    v17[1] = (bfx::VolumeGraph *)v13;
    v17[6] = pVolume1;
    v18 = bfx::CalcCentroid(result: v21, pPts: (const bfx::Vec3 *)v13 + 1, numPts: v13[2]);
    *(bfx::Vec3 *)(LODWORD(v19) + 8) = *v18;
    v20 = v19;
  }
  else
  {
    v20 = 0.0;
  }
  v21[0].m_x = v20;
  bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)&this->m_graphPortals, val: (bfx::Space **)v21);
  v21[0].m_x = v20;
  LODWORD(v21[0].m_y) = faceIndexOnVolume0;
  bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(
    this: (bfx::Array<bfx::ReplayLogListenerEntry> *)&pVolume0->m_graphPortals.m_tag,
    val: (const bfx::ReplayLogListenerEntry *)v21);
  v21[0].m_x = v20;
  LODWORD(v21[0].m_y) = faceIndexOnVolume1;
  bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(
    this: (bfx::Array<bfx::ReplayLogListenerEntry> *)&pVolume1->m_graphPortals.m_tag,
    val: (const bfx::ReplayLogListenerEntry *)v21);
}


// ========================================================================
// ?DeleteAllocatedPortalAndResource@VolumeGraph@bfx@@QAA_NPAVPortal@2@@Z
// EA  : 0x832A04A0
// RVA : 0x012A04A0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

int __fastcall bfx::VolumeGraph::DeleteAllocatedPortalAndResource(bfx::VolumeGraph *this, bfx::Portal *pInputPortal)
{
  bfx::Array<bfx::PortalResource *> *p_m_dynamicPortalResources; // r31
  int v5; // r30
  int v6; // r11
  bfx::PortalResource *m_pRes; // r9
  char *v8; // r4
  unsigned int v9; // r3
  unsigned int v10; // r11
  bfx::Array<bfx::Portal *> *p_m_graphPortals; // r31
  int v12; // r30
  int i; // r11
  bfx::Portal *v14; // r4
  unsigned int v16; // r3
  bfx::Portal **v17; // r11

  p_m_dynamicPortalResources = &this->m_dynamicPortalResources;
  v5 = 0;
  if ( this->m_dynamicPortalResources.m_size > 0 )
  {
    v6 = 0;
    m_pRes = pInputPortal->m_pRes;
    while ( 1 )
    {
      v8 = (char *)p_m_dynamicPortalResources->m_data[v6];
      if ( v8 == (char *)m_pRes )
        break;
      ++v5;
      ++v6;
      if ( v5 >= this->m_dynamicPortalResources.m_size )
        goto LABEL_9;
    }
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v8);
    v9 = (unsigned int)&p_m_dynamicPortalResources->m_data[v5];
    v10 = (unsigned int)&p_m_dynamicPortalResources->m_data[p_m_dynamicPortalResources->m_size - 1];
    if ( v9 < v10 )
      blkmov(a1: v9, a2: v9 + 4, a3: 4 * (((v10 - v9 - 1) >> 2) + 1));
    --p_m_dynamicPortalResources->m_size;
  }
LABEL_9:
  p_m_graphPortals = &this->m_graphPortals;
  v12 = 0;
  if ( this->m_graphPortals.m_size <= 0 )
    return 0;
  for ( i = 0; ; ++i )
  {
    v14 = p_m_graphPortals->m_data[i];
    if ( v14 == pInputPortal )
      break;
    if ( ++v12 >= this->m_graphPortals.m_size )
      return 0;
  }
  if ( v14 != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v14);
  v16 = (unsigned int)&p_m_graphPortals->m_data[v12];
  v17 = &this->m_graphPortals.m_data[this->m_graphPortals.m_size - 1];
  if ( v16 < (unsigned int)v17 )
    blkmov(a1: v16, a2: v16 + 4, a3: 4 * ((((unsigned int)v17 - v16 - 1) >> 2) + 1));
  --this->m_graphPortals.m_size;
  return 1;
}


// ========================================================================
// ?CreateIslandsForVolumeGraph@VolumeGraph@bfx@@QAAXXZ
// EA  : 0x832A0610
// RVA : 0x012A0610
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void __fastcall bfx::VolumeGraph::CreateIslandsForVolumeGraph(bfx::VolumeGraph *this)
{
  bfx::Island3DGraph *m_pIslandGraph; // r28
  int v3; // r9
  int v4; // r8
  int v5; // r7
  int v6; // r6
  int v7; // r5
  bfx::Array<bfx::Volume *> *p_m_graphVolumes; // r30
  int v9; // r29
  int v10; // r31
  bfx::Volume *v11; // r4
  int v12; // [sp+8h] [-78h]
  int v13; // [sp+Ch] [-74h]
  int v14; // [sp+10h] [-70h]
  int v15; // [sp+14h] [-6Ch]
  int v16; // [sp+18h] [-68h]
  bfx::Space *v17; // [sp+1Ch] [-64h]

  p_m_graphVolumes = &this->m_graphVolumes;
  m_pIslandGraph = bfx::GetPlanner3D(pSpace: this->m_pSpace)->m_pIslandGraph;
  v9 = 0;
  if ( this->m_graphVolumes.m_size > 0 )
  {
    v10 = 0;
    do
    {
      v11 = p_m_graphVolumes->m_data[v10];
      if ( v11->m_islandID == 1023
        && (unsigned __int8)bfx::Island3DGraph::CreateIsland(
                              this: m_pIslandGraph,
                              pStartVolume: (bfx::Space *)v11,
                              a3: v7,
                              a4: v6,
                              a5: v5,
                              a6: v4,
                              a7: v3,
                              a8: 1023,
                              a9: v12,
                              a10: v13,
                              a11: v14,
                              a12: v15,
                              a13: v16,
                              a14: v17) == 0 )
      {
        break;
      }
      ++v9;
      ++v10;
    }
    while ( v9 < p_m_graphVolumes->m_size );
  }
}


// ========================================================================
// ?DrawVolumes@VolumeGraph@bfx@@QBAXXZ
// EA  : 0x832A0688
// RVA : 0x012A0688
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void __fastcall bfx::VolumeGraph::DrawVolumes(bfx::VolumeGraph *this)
{
  bfx::Array<bfx::Volume *> *p_m_graphVolumes; // r29
  int v2; // r31
  int v3; // r30
  const bfx::Color *v4; // r7
  bfx::Volume *v5; // r10

  p_m_graphVolumes = &this->m_graphVolumes;
  v2 = 0;
  if ( this->m_graphVolumes.m_size > 0 )
  {
    v3 = 0;
    do
    {
      v4 = &ColorGray_16;
      v5 = p_m_graphVolumes->m_data[v3];
      if ( v5->m_userData != 0 )
        v4 = &ColorGreen_16;
      bfx::DrawConvexVolume(
        pSpace: v5->m_pParentGraph->m_pSpace,
        pPlanes: v5->m_pRes->m_planes,
        numPlanes: v5->m_pRes->m_numPlanes,
        normalsSpec: OUTWARD_PLANE_NORMALS,
        color: v4);
      ++v2;
      ++v3;
    }
    while ( v2 < p_m_graphVolumes->m_size );
  }
}


// ========================================================================
// ?DrawPortals@VolumeGraph@bfx@@QBAXXZ
// EA  : 0x832A0710
// RVA : 0x012A0710
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void __fastcall bfx::VolumeGraph::DrawPortals(bfx::VolumeGraph *this)
{
  bfx::Array<bfx::Portal *> *p_m_graphPortals; // r29
  int v2; // r30
  int v3; // r31
  const bfx::Color *v4; // r4
  bfx::Portal *v5; // r3

  p_m_graphPortals = &this->m_graphPortals;
  v2 = 0;
  if ( this->m_graphPortals.m_size > 0 )
  {
    v3 = 0;
    do
    {
      v4 = &PORTAL3D_COLOR;
      v5 = p_m_graphPortals->m_data[v3];
      if ( v5->m_pVolume1->m_pParentGraph == v5->m_pVolume0->m_pParentGraph )
        v4 = &ColorMagenta_16;
      bfx::Portal::Draw(this: v5, color: v4);
      ++v2;
      ++v3;
    }
    while ( v2 < p_m_graphPortals->m_size );
  }
}


// ========================================================================
// ?DrawConnectivity@VolumeGraph@bfx@@QBAXXZ
// EA  : 0x832A0790
// RVA : 0x012A0790
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void __fastcall bfx::VolumeGraph::DrawConnectivity(bfx::VolumeGraph *this)
{
  bfx::Array<bfx::Portal *> *p_m_graphPortals; // r26
  int v3; // r25
  int v4; // r28
  bfx::Portal *v5; // r10
  float m_y; // r8
  float m_z; // r7
  bfx::Volume *m_pVolume0; // r11
  bfx::Volume *m_pVolume1; // r10
  float v10; // r8
  float v11; // r7
  float v12; // r5
  float v13; // r4
  double Scale; // fp1
  const bfx::Color *v15; // r5
  double v16; // fp1
  const bfx::Color *v17; // r5
  double v18; // fp1
  const bfx::Color *v19; // r5
  bfx::Space *m_pSpace; // r3
  bfx::Space *v21; // r3
  bfx::Vec3 v22; // [sp+50h] [-B0h] BYREF
  bfx::Vec3 v23; // [sp+60h] [-A0h] BYREF
  bfx::Vec3 v24; // [sp+70h] [-90h] BYREF
  bfx::Vec3 v25; // [sp+80h] [-80h] BYREF
  float m_x; // [sp+8Ch] [-74h]
  float v27; // [sp+90h] [-70h]
  float v28; // [sp+94h] [-6Ch]
  bfx::Vec3 v29; // [sp+A0h] [-60h] BYREF
  float v30; // [sp+ACh] [-54h]
  float v31; // [sp+B0h] [-50h]
  float v32; // [sp+B4h] [-4Ch]

  p_m_graphPortals = &this->m_graphPortals;
  v3 = 0;
  if ( this->m_graphPortals.m_size > 0 )
  {
    v4 = 0;
    do
    {
      v5 = p_m_graphPortals->m_data[v4];
      m_y = v5->m_centroid.m_y;
      m_z = v5->m_centroid.m_z;
      v22.m_x = v5->m_centroid.m_x;
      v22.m_y = m_y;
      v22.m_z = m_z;
      m_pVolume0 = v5->m_pVolume0;
      m_pVolume1 = v5->m_pVolume1;
      if ( m_pVolume0->m_userData != 0 && m_pVolume1->m_userData != 0 )
      {
        v10 = m_pVolume0->m_centroid.m_y;
        v11 = m_pVolume0->m_centroid.m_z;
        v23.m_x = m_pVolume0->m_centroid.m_x;
        v23.m_y = v10;
        v23.m_z = v11;
        v12 = m_pVolume1->m_centroid.m_y;
        v13 = m_pVolume1->m_centroid.m_z;
        v24.m_x = m_pVolume1->m_centroid.m_x;
        v24.m_y = v12;
        v24.m_z = v13;
        Scale = bfx::GetScale();
        bfx::DrawCross(pSpace: this->m_pSpace, pos: &v22, radius: Scale, color: v15, a5: &ColorMagenta_16);
        v16 = bfx::GetScale();
        bfx::DrawCross(pSpace: this->m_pSpace, pos: &v23, radius: v16, color: v17, a5: &ColorGreen_16);
        v18 = bfx::GetScale();
        bfx::DrawCross(pSpace: this->m_pSpace, pos: &v24, radius: v18, color: v19, a5: &ColorGreen_16);
        m_pSpace = this->m_pSpace;
        v25.m_x = v22.m_x;
        v25.m_y = v22.m_y;
        v25.m_z = v22.m_z;
        m_x = v23.m_x;
        v27 = v23.m_y;
        v28 = v23.m_z;
        bfx::DrawLineList(pSpace: m_pSpace, pVerts: &v25, numVerts: 2, color: &ColorWhite_16);
        v21 = this->m_pSpace;
        v29.m_x = v22.m_x;
        v29.m_y = v22.m_y;
        v29.m_z = v22.m_z;
        v30 = v24.m_x;
        v31 = v24.m_y;
        v32 = v24.m_z;
        bfx::DrawLineList(pSpace: v21, pVerts: &v29, numVerts: 2, color: &ColorWhite_16);
      }
      ++v3;
      ++v4;
    }
    while ( v3 < p_m_graphPortals->m_size );
  }
}


// ========================================================================
// ?DrawIslands@VolumeGraph@bfx@@QBAXXZ
// EA  : 0x832A0920
// RVA : 0x012A0920
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void __fastcall bfx::VolumeGraph::DrawIslands(bfx::VolumeGraph *this, int a2, int a3, int a4, __int64 a5, __int64 a6)
{
  bfx::Array<bfx::Volume *> *p_m_graphVolumes; // r29
  int v8; // r31
  int v9; // r30
  __int64 v10; // r6
  bfx::Volume *v11; // r11
  int v12; // [sp+8h] [-78h]
  int v13; // [sp+Ch] [-74h]
  int v14; // [sp+10h] [-70h]
  int v15; // [sp+14h] [-6Ch]
  int v16; // [sp+18h] [-68h]
  int v17; // [sp+1Ch] [-64h]
  int v18; // [sp+20h] [-60h]
  int v19; // [sp+24h] [-5Ch]

  p_m_graphVolumes = &this->m_graphVolumes;
  v8 = 0;
  if ( this->m_graphVolumes.m_size > 0 )
  {
    v9 = 0;
    do
    {
      HIDWORD(v10) = "%d";
      v11 = p_m_graphVolumes->m_data[v9];
      LODWORD(v10) = v11->m_islandID;
      bfx::DrawString(
        pSpace: (bfx::Vector3 *)this->m_pSpace,
        inputPos: &v11->m_centroid,
        fmt: v10,
        a4: a5,
        a5: a6,
        a6: v12,
        a7: v13,
        a8: v14,
        a9: v15,
        a10: v16,
        a11: v17,
        a12: v18,
        a13: v19);
      LODWORD(a6) = p_m_graphVolumes->m_size;
      ++v8;
      ++v9;
    }
    while ( v8 < (int)a6 );
  }
}


// ========================================================================
// ?DrawUserData@VolumeGraph@bfx@@QBAXXZ
// EA  : 0x832A0988
// RVA : 0x012A0988
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void __fastcall bfx::VolumeGraph::DrawUserData(bfx::VolumeGraph *this, int a2, int a3, int a4, __int64 a5, __int64 a6)
{
  bfx::Array<bfx::Volume *> *p_m_graphVolumes; // r29
  int v8; // r31
  int v9; // r30
  __int64 v10; // r6
  bfx::Volume *v11; // r11
  int v12; // [sp+8h] [-78h]
  int v13; // [sp+Ch] [-74h]
  int v14; // [sp+10h] [-70h]
  int v15; // [sp+14h] [-6Ch]
  int v16; // [sp+18h] [-68h]
  int v17; // [sp+1Ch] [-64h]
  int v18; // [sp+20h] [-60h]
  int v19; // [sp+24h] [-5Ch]

  p_m_graphVolumes = &this->m_graphVolumes;
  v8 = 0;
  if ( this->m_graphVolumes.m_size > 0 )
  {
    v9 = 0;
    do
    {
      HIDWORD(v10) = "%08X";
      v11 = p_m_graphVolumes->m_data[v9];
      LODWORD(v10) = v11->m_userData;
      bfx::DrawString(
        pSpace: (bfx::Vector3 *)this->m_pSpace,
        inputPos: &v11->m_centroid,
        fmt: v10,
        a4: a5,
        a5: a6,
        a6: v12,
        a7: v13,
        a8: v14,
        a9: v15,
        a10: v16,
        a11: v17,
        a12: v18,
        a13: v19);
      LODWORD(a6) = p_m_graphVolumes->m_size;
      ++v8;
      ++v9;
    }
    while ( v8 < (int)a6 );
  }
}


// ========================================================================
// ?Translate@VolumeGraph@bfx@@QAAXABVVec3@2@@Z
// EA  : 0x832A09F0
// RVA : 0x012A09F0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void __fastcall bfx::VolumeGraph::Translate(bfx::VolumeGraph *this, const bfx::Vec3 *deltaPos)
{
  bfx::VolumeGraphResource *m_pHdr; // r11
  bfx::Array<bfx::Volume *> *p_m_graphVolumes; // r5
  double v5; // fp7
  double v6; // fp6
  bfx::Vec3 *p_m_max; // r11
  double m_y; // fp4
  double v9; // fp2
  double v10; // fp13
  int v11; // r31
  int v12; // r6
  bfx::Array<bfx::Portal *> *p_m_graphPortals; // r5
  int v14; // r6
  int v15; // r7
  int v16; // r6

  m_pHdr = this->m_pHdr;
  p_m_graphVolumes = &this->m_graphVolumes;
  v5 = (float)(deltaPos->m_y + m_pHdr->m_bbox.m_min.m_y);
  v6 = (float)(m_pHdr->m_bbox.m_min.m_z + deltaPos->m_z);
  m_pHdr->m_bbox.m_min.m_x = deltaPos->m_x + m_pHdr->m_bbox.m_min.m_x;
  m_pHdr->m_bbox.m_min.m_y = v5;
  m_pHdr->m_bbox.m_min.m_z = v6;
  p_m_max = &this->m_pHdr->m_bbox.m_max;
  m_y = deltaPos->m_y;
  v9 = this->m_pHdr->m_bbox.m_max.m_y;
  v10 = (float)(this->m_pHdr->m_bbox.m_max.m_z + deltaPos->m_z);
  p_m_max->m_x = p_m_max->m_x + deltaPos->m_x;
  p_m_max->m_y = (float)m_y + (float)v9;
  p_m_max->m_z = v10;
  if ( this->m_graphVolumes.m_size > 0 )
  {
    v11 = 0;
    do
      bfx::Volume::Translate(this: p_m_graphVolumes->m_data[v11++], deltaPos);
    while ( v12 + 1 < p_m_graphVolumes->m_size );
  }
  p_m_graphPortals = &this->m_graphPortals;
  if ( this->m_graphPortals.m_size > 0 )
  {
    v14 = 0;
    do
    {
      bfx::Portal::Translate(this: *(bfx::Portal **)((char *)p_m_graphPortals->m_data + v14), deltaPos);
      v14 = v16 + 4;
    }
    while ( v15 + 1 < p_m_graphPortals->m_size );
  }
}


// ========================================================================
// ?GetPortalsBetweenGraphs@Volume@bfx@@QAAXAAV?$Array@PAVPortal@bfx@@@2@@Z
// EA  : 0x832A0B60
// RVA : 0x012A0B60
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void __fastcall bfx::Volume::GetPortalsBetweenGraphs(bfx::Volume *this, bfx::Array<bfx::Space *> *portalsOut)
{
  bfx::Array<bfx::PortalRecord> *p_m_portals; // r29
  int v4; // r28
  int v5; // r30
  bfx::Portal *m_pPortal; // r9
  bfx::Volume *m_pVolume1; // r10
  bfx::Volume *m_pVolume0; // r8
  bfx::Portal **m_data; // r11
  bfx::Portal **v10; // r10
  bfx::Portal *v11; // [sp+50h] [-30h] BYREF

  p_m_portals = &this->m_portals;
  v4 = 0;
  if ( this->m_portals.m_size > 0 )
  {
    v5 = 0;
    do
    {
      m_pPortal = p_m_portals->m_data[v5].m_pPortal;
      m_pVolume1 = m_pPortal->m_pVolume1;
      m_pVolume0 = m_pPortal->m_pVolume0;
      v11 = m_pPortal;
      if ( m_pVolume1 != m_pVolume0 )
      {
        m_data = (bfx::Portal **)portalsOut->m_data;
        v10 = (bfx::Portal **)&portalsOut->m_data[portalsOut->m_size];
        if ( (bfx::Portal **)portalsOut->m_data == v10 )
        {
LABEL_7:
          bfx::Array<bfx::Portal *>::push_back(this: portalsOut, val: (bfx::Space **)&v11);
        }
        else
        {
          while ( *m_data != m_pPortal )
          {
            if ( ++m_data == v10 )
              goto LABEL_7;
          }
        }
      }
      ++v4;
      ++v5;
    }
    while ( v4 < p_m_portals->m_size );
  }
}


// ========================================================================
// ??1VolumeGraph@bfx@@QAA@XZ
// EA  : 0x832A0C08
// RVA : 0x012A0C08
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void __fastcall bfx::VolumeGraph::~VolumeGraph(bfx::VolumeGraph *this)
{
  bfx::Island3DGraph *m_pIslandGraph; // r28
  int v3; // r9
  int v4; // r8
  int v5; // r7
  int v6; // r6
  char **p_m_graphVolumes; // r27
  int v8; // r29
  int v9; // r30
  int v10; // r4
  int v11; // r10
  char *m_data; // r23
  int m_size; // r10
  int v14; // r30
  int v15; // r29
  bfx::Portal **v16; // r29
  int i; // r28
  bfx::Portal *v18; // r30
  char **p_m_graphPortals; // r24
  int v20; // r29
  int v21; // r30
  char *v22; // r4
  int v23; // r29
  int v24; // r30
  void (__fastcall ***v25)(_DWORD, int); // r3
  char **p_m_dynamicPortalResources; // r30
  int v27; // r29
  int v28; // r28
  char *v29; // r4
  char *v30; // r4
  char *v31; // r4
  int v32; // [sp+8h] [-C8h]
  int v33; // [sp+Ch] [-C4h]
  int v34; // [sp+10h] [-C0h]
  int v35; // [sp+14h] [-BCh]
  int v36; // [sp+18h] [-B8h]
  bfx::Space *v37; // [sp+1Ch] [-B4h]
  bfx::Array<bfx::Space *> v38; // [sp+60h] [-70h] BYREF

  p_m_graphVolumes = (char **)&this->m_graphVolumes;
  m_pIslandGraph = bfx::GetPlanner3D(pSpace: this->m_pSpace)->m_pIslandGraph;
  v8 = 0;
  if ( this->m_graphVolumes.m_size > 0 )
  {
    v9 = 0;
    do
    {
      v10 = *(_DWORD *)&(*p_m_graphVolumes)[v9];
      v11 = *(_DWORD *)(v10 + 36);
      if ( v11 != 1023 )
        bfx::Island3DGraph::RemoveIsland(
          this: m_pIslandGraph,
          pStartVolume: (bfx::Space *)v10,
          pVolumesTouchedOut: nullptr,
          a4: v6,
          a5: v5,
          a6: v4,
          a7: v3,
          a8: v11,
          a9: v32,
          a10: v33,
          a11: v34,
          a12: v35,
          a13: v36,
          a14: v37);
      ++v8;
      v9 += 4;
    }
    while ( v8 < this->m_graphVolumes.m_size );
  }
  m_data = nullptr;
  memset(&v38, 0, 12);
  m_size = 0;
  v38.m_tag = bfx::MEM_BFXPLANNER3D;
  v14 = 0;
  if ( this->m_graphVolumes.m_size > 0 )
  {
    v15 = 0;
    do
    {
      bfx::Volume::GetPortalsBetweenGraphs(this: *(bfx::Volume **)&(*p_m_graphVolumes)[v15], portalsOut: &v38);
      ++v14;
      v15 += 4;
    }
    while ( v14 < this->m_graphVolumes.m_size );
    m_size = v38.m_size;
    m_data = (char *)v38.m_data;
  }
  if ( m_size > 0 )
  {
    v16 = (bfx::Portal **)m_data;
    for ( i = m_size; i != 0; --i )
    {
      v18 = *v16;
      bfx::Volume::RemovePortalRecord(this: (*v16)->m_pVolume0, pPortal: *v16);
      bfx::Volume::RemovePortalRecord(this: v18->m_pVolume1, pPortal: v18);
      if ( (unsigned __int8)bfx::VolumeGraph::DeleteAllocatedPortalAndResource(
                              this: v18->m_pVolume0->m_pParentGraph,
                              pInputPortal: v18) == 0 )
        bfx::VolumeGraph::DeleteAllocatedPortalAndResource(this: v18->m_pVolume1->m_pParentGraph, pInputPortal: v18);
      ++v16;
    }
  }
  p_m_graphPortals = (char **)&this->m_graphPortals;
  v20 = 0;
  if ( this->m_graphPortals.m_size > 0 )
  {
    v21 = 0;
    do
    {
      v22 = *(char **)&(*p_m_graphPortals)[v21];
      if ( v22 != nullptr )
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v22);
      ++v20;
      v21 += 4;
    }
    while ( v20 < this->m_graphPortals.m_size );
  }
  this->m_graphPortals.m_size = 0;
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: *p_m_graphPortals);
  *p_m_graphPortals = nullptr;
  this->m_graphPortals.m_cap = 0;
  v23 = 0;
  if ( this->m_graphVolumes.m_size > 0 )
  {
    v24 = 0;
    do
    {
      v25 = *(void (__fastcall ****)(_DWORD, int))&(*p_m_graphVolumes)[v24];
      if ( v25 != nullptr )
        (**v25)(a1: v25, a2: 1);
      ++v23;
      v24 += 4;
    }
    while ( v23 < this->m_graphVolumes.m_size );
  }
  this->m_graphVolumes.m_size = 0;
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: *p_m_graphVolumes);
  *p_m_graphVolumes = nullptr;
  p_m_dynamicPortalResources = (char **)&this->m_dynamicPortalResources;
  this->m_graphVolumes.m_cap = 0;
  v27 = 0;
  if ( this->m_dynamicPortalResources.m_size > 0 )
  {
    v28 = 0;
    do
    {
      bfx::MemoryManager::Free(
        this: bfx::g_pCurInstance->m_pMemoryManager,
        ptr: *(char **)&(*p_m_dynamicPortalResources)[v28]);
      ++v27;
      v28 += 4;
    }
    while ( v27 < this->m_dynamicPortalResources.m_size );
  }
  this->m_dynamicPortalResources.m_size = 0;
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: *p_m_dynamicPortalResources);
  *p_m_dynamicPortalResources = nullptr;
  this->m_dynamicPortalResources.m_cap = 0;
  if ( m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
  v29 = *p_m_dynamicPortalResources;
  this->m_dynamicPortalResources.m_size = 0;
  if ( v29 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v29);
    *p_m_dynamicPortalResources = nullptr;
  }
  this->m_dynamicPortalResources.m_cap = 0;
  v30 = *p_m_graphPortals;
  this->m_graphPortals.m_size = 0;
  if ( v30 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v30);
    *p_m_graphPortals = nullptr;
  }
  this->m_graphPortals.m_cap = 0;
  v31 = *p_m_graphVolumes;
  this->m_graphVolumes.m_size = 0;
  if ( v31 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v31);
    *p_m_graphVolumes = nullptr;
  }
  this->m_graphVolumes.m_cap = 0;
}


// ========================================================================
// __unwind$23696
// EA  : 0x832A0F04
// RVA : 0x012A0F04
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void _unwind_23696()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 208 + 228)
                                                                                             + 16));
}


// ========================================================================
// __unwind$23697
// EA  : 0x832A0F30
// RVA : 0x012A0F30
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void _unwind_23697()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 208 + 228)
                                                                                             + 32));
}


// ========================================================================
// __unwind$23698
// EA  : 0x832A0F5C
// RVA : 0x012A0F5C
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void _unwind_23698()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 208 + 228)
                                                                                             + 48));
}


// ========================================================================
// __unwind$23699
// EA  : 0x832A0F88
// RVA : 0x012A0F88
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxvolumeresource.cpp
// ========================================================================

void _unwind_23699()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 208 + 96));
}

