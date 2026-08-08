
// ========================================================================
// ?IntersectLineAndPlane@bfx@@YA_NABVVec3@1@AAV21@ABVPlane@1@AAM@Z
// EA  : 0x8329D140
// RVA : 0x0129D140
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxpath3d.cpp
// ========================================================================

int __fastcall bfx::IntersectLineAndPlane(const bfx::Vec3 *startPos, bfx::Vec3 *endPos, const bfx::Plane *P, float *t)
{
  double v4; // fp5
  double v5; // fp6
  double v6; // fp4
  double v7; // fp0
  double m_y; // fp10
  double m_z; // fp8

  v4 = (float)(endPos->m_y - startPos->m_y);
  v5 = (float)(endPos->m_x - startPos->m_x);
  v6 = (float)(endPos->m_z - startPos->m_z);
  if ( __fabs((float)((float)(P->m_normal.m_z * (float)(endPos->m_z - startPos->m_z))
                    + (float)((float)(P->m_normal.m_x * (float)(endPos->m_x - startPos->m_x))
                            + (float)(P->m_normal.m_y * (float)(endPos->m_y - startPos->m_y))))) <= 1.0842022e-19 )
    return 0;
  v7 = (float)((float)(P->m_d
                     - (float)((float)(P->m_normal.m_x * startPos->m_x)
                             + (float)((float)(P->m_normal.m_z * startPos->m_z)
                                     + (float)(P->m_normal.m_y * startPos->m_y))))
             / (float)((float)(P->m_normal.m_z * (float)(endPos->m_z - startPos->m_z))
                     + (float)((float)(P->m_normal.m_x * (float)(endPos->m_x - startPos->m_x))
                             + (float)(P->m_normal.m_y * (float)(endPos->m_y - startPos->m_y)))));
  if ( v7 < 0.0 || v7 > 1.0 )
    return 0;
  *t = (float)(P->m_d
             - (float)((float)(P->m_normal.m_x * startPos->m_x)
                     + (float)((float)(P->m_normal.m_z * startPos->m_z) + (float)(P->m_normal.m_y * startPos->m_y))))
     / (float)((float)(P->m_normal.m_z * (float)(endPos->m_z - startPos->m_z))
             + (float)((float)(P->m_normal.m_x * (float)(endPos->m_x - startPos->m_x))
                     + (float)(P->m_normal.m_y * (float)(endPos->m_y - startPos->m_y))));
  m_y = startPos->m_y;
  m_z = startPos->m_z;
  endPos->m_x = startPos->m_x + (float)((float)v5 * (float)v7);
  endPos->m_z = (float)m_z + (float)((float)v6 * (float)v7);
  endPos->m_y = (float)((float)v4 * (float)v7) + (float)m_y;
  return 1;
}


// ========================================================================
// ?GetClosestPosInPortalToLine@bfx@@YA?AVVec3@1@PBVPortal@1@ABV21@1AA_N@Z
// EA  : 0x8329D210
// RVA : 0x0129D210
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxpath3d.cpp
// ========================================================================

bfx::Vec3 *__fastcall bfx::GetClosestPosInPortalToLine(
        bfx::Vec3 *result,
        bfx::Plane *pPortal,
        const bfx::Vec3 *linePos1,
        const bfx::Vec3 *linePos2,
        bool *closestPosIsOnPortalPerimeterOut)
{
  double v10; // fp6
  double v11; // fp12
  bfx::PortalResource *m_y_low; // r10
  double v13; // fp31
  unsigned int m_numVerts; // r11
  float v15; // r4
  float v16; // r3
  double m_z; // fp12
  int v18; // r31
  double m_y; // fp13
  unsigned int v20; // r27
  double m_x; // fp0
  float *v22; // r11
  float v23; // r9
  float v24; // r8
  double v25; // fp0
  double v26; // fp13
  double v27; // fp4
  double v28; // fp3
  bfx::Vec3 *v29; // r3
  float v30; // r11
  float v31; // r10
  float v32; // r9
  bfx::Vec3 v33; // [sp+50h] [-C0h] BYREF
  bfx::Vec3 v34; // [sp+60h] [-B0h] BYREF
  bfx::Vec3 v35; // [sp+70h] [-A0h] BYREF
  float v36; // [sp+80h] [-90h]
  float v37; // [sp+84h] [-8Ch]
  float v38; // [sp+88h] [-88h]
  bfx::Vec3 v39; // [sp+90h] [-80h] BYREF
  bfx::Portal v40; // [sp+A0h] [-70h] BYREF

  bfx::Portal::GetPlane(this: &v40, result: pPortal);
  if ( (unsigned __int8)bfx::CollideLineAndPlane(
                          v0: linePos1,
                          v1: linePos2,
                          plane: (const bfx::Plane *)&v40,
                          intersectionPosOut: &v35) == 0 )
  {
    v10 = (float)(linePos1->m_z + linePos2->m_z);
    v11 = (float)((float)(linePos1->m_y + linePos2->m_y) * (float)0.5);
    v35.m_x = (float)(linePos1->m_x + linePos2->m_x) * (float)0.5;
    v35.m_y = v11;
    v35.m_z = (float)v10 * (float)0.5;
  }
  *closestPosIsOnPortalPerimeterOut = false;
  m_y_low = (bfx::PortalResource *)LODWORD(pPortal->m_normal.m_y);
  v13 = 3.4028235e38;
  v36 = 0.0;
  v37 = 0.0;
  v38 = 0.0;
  m_numVerts = m_y_low->m_numVerts;
  v15 = *((float *)&m_y_low->m_volIndex1 + 3 * m_numVerts);
  v16 = *((float *)&m_y_low->m_numVerts + 3 * m_numVerts);
  v34.m_x = *((float *)&m_y_low->m_volIndex0 + 3 * m_numVerts);
  v34.m_y = v15;
  v34.m_z = v16;
  if ( m_numVerts != 0 )
  {
    m_z = v34.m_z;
    v18 = 0;
    m_y = v34.m_y;
    v20 = m_numVerts;
    m_x = v34.m_x;
    do
    {
      v22 = (float *)(v18 + LODWORD(pPortal->m_normal.m_y));
      v23 = v22[5];
      v24 = v22[4];
      v33.m_x = v22[3];
      v33.m_z = v23;
      v33.m_y = v24;
      if ( (float)((float)((float)((float)((float)(v35.m_y - (float)m_y) * (float)(v23 - (float)m_z))
                                 - (float)((float)(v35.m_z - (float)m_z) * (float)(v24 - (float)m_y)))
                         * *(float *)&v40.m_pParentGraph)
                 + (float)((float)(v40.m_centroid.m_x
                                 * (float)((float)((float)(v24 - (float)m_y) * (float)(v35.m_x - (float)m_x))
                                         - (float)((float)(v35.m_y - (float)m_y) * (float)(v33.m_x - (float)m_x))))
                         + (float)(*(float *)&v40.m_pRes
                                 * (float)((float)((float)(v35.m_z - (float)m_z) * (float)(v33.m_x - (float)m_x))
                                         - (float)((float)(v23 - (float)m_z) * (float)(v35.m_x - (float)m_x)))))) > 0.0 )
      {
        bfx::GetClosestPtOnLineSegAToLineB(result: &v39, startA: &v34, endA: &v33, startB: linePos1, endB: linePos2);
        v25 = v39.m_y;
        v26 = v39.m_z;
        v27 = __fsqrts((float)((float)((float)(linePos2->m_x - v39.m_x) * (float)(linePos2->m_x - v39.m_x))
                             + (float)((float)((float)(linePos2->m_z - v39.m_z) * (float)(linePos2->m_z - v39.m_z))
                                     + (float)((float)(linePos2->m_y - v39.m_y) * (float)(linePos2->m_y - v39.m_y)))));
        v28 = __fsqrts((float)((float)((float)(v39.m_x - linePos1->m_x) * (float)(v39.m_x - linePos1->m_x))
                             + (float)((float)((float)(v39.m_z - linePos1->m_z) * (float)(v39.m_z - linePos1->m_z))
                                     + (float)((float)(v39.m_y - linePos1->m_y) * (float)(v39.m_y - linePos1->m_y)))));
        if ( (float)((float)v27 + (float)v28) < v13 )
        {
          v36 = v39.m_x;
          *closestPosIsOnPortalPerimeterOut = true;
          v37 = v25;
          v13 = (float)((float)v27 + (float)v28);
          v38 = v26;
        }
      }
      m_x = v33.m_x;
      --v20;
      m_y = v33.m_y;
      v18 += 12;
      m_z = v33.m_z;
      v34.m_x = v33.m_x;
      v34.m_y = v33.m_y;
      v34.m_z = v33.m_z;
    }
    while ( v20 != 0 );
  }
  v29 = result;
  if ( *closestPosIsOnPortalPerimeterOut )
  {
    v30 = v36;
    v31 = v37;
    v32 = v38;
  }
  else
  {
    v30 = v35.m_x;
    v31 = v35.m_y;
    v32 = v35.m_z;
  }
  result->m_z = v32;
  result->m_y = v31;
  result->m_x = v30;
  return v29;
}


// ========================================================================
// ?UpdatePortalPos@bfx@@YAXABVVec3@1@0AAUPath3DPoint@1@@Z
// EA  : 0x8329D4B8
// RVA : 0x0129D4B8
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxpath3d.cpp
// ========================================================================

void __fastcall bfx::UpdatePortalPos(const bfx::Vec3 *prevPos, const bfx::Vec3 *nextPos, bfx::Path3DPoint *portalPoint)
{
  bfx::Vec3 *m_pPortal; // r30
  double v5; // fp31
  double Scale; // fp1
  double v7; // fp0
  double v8; // fp13
  double v9; // fp12
  double m_z; // fp8
  float v11; // r10
  double v12; // fp10
  float m_x; // r9
  double v14; // fp7
  double m_y; // fp9
  double v16; // fp13
  double v17; // fp12
  double v18; // fp11
  double v19; // fp3
  double v20; // fp0
  double v21; // fp0
  bool v22; // [sp+50h] [-50h] BYREF
  bfx::Vec3 v23; // [sp+58h] [-48h] BYREF
  bfx::Portal v24; // [sp+68h] [-38h] BYREF

  m_pPortal = (bfx::Vec3 *)portalPoint->m_pPortal;
  bfx::GetClosestPosInPortalToLine(
    result: &v23,
    pPortal: (bfx::Plane *)portalPoint->m_pPortal,
    linePos1: prevPos,
    linePos2: nextPos,
    closestPosIsOnPortalPerimeterOut: &v22);
  v5 = 0.0;
  if ( !v22 )
  {
    bfx::Portal::GetClosestPosOnPortalPerimeter(this: &v24, result: m_pPortal, testPos: &v23);
    v5 = __fsqrts((float)((float)((float)(v23.m_x - *(float *)&v24.m_pParentGraph)
                                * (float)(v23.m_x - *(float *)&v24.m_pParentGraph))
                        + (float)((float)((float)(v23.m_z - v24.m_centroid.m_x) * (float)(v23.m_z - v24.m_centroid.m_x))
                                + (float)((float)(v23.m_y - *(float *)&v24.m_pRes)
                                        * (float)(v23.m_y - *(float *)&v24.m_pRes)))));
  }
  Scale = bfx::GetScale();
  if ( v5 < (float)((float)Scale * (float)0.0099999998) )
  {
    m_z = v23.m_z;
    v11 = m_pPortal->m_z;
    v12 = (float)((float)((float)Scale * (float)0.0099999998) - (float)v5);
    m_x = m_pPortal[1].m_x;
    v14 = v23.m_x;
    m_y = v23.m_y;
    v23.m_z = m_pPortal[1].m_y;
    v16 = (float)(m_x - v23.m_y);
    v17 = (float)(v23.m_z - (float)m_z);
    v18 = (float)(v11 - v23.m_x);
    v19 = (float)((float)((float)(v11 - v23.m_x) * (float)(v11 - v23.m_x))
                + (float)((float)((float)(v23.m_z - (float)m_z) * (float)(v23.m_z - (float)m_z))
                        + (float)((float)(m_x - v23.m_y) * (float)(m_x - v23.m_y))));
    v23.m_x = v11;
    v23.m_y = m_x;
    v20 = __fsqrts(v19);
    if ( v12 <= v20 )
    {
      if ( v12 < -v20 )
        v12 = -v20;
    }
    else
    {
      v12 = v20;
    }
    if ( v20 <= 1.0842022e-19 )
    {
      portalPoint->m_pos.m_x = v14;
      portalPoint->m_pos.m_y = m_y;
      portalPoint->m_pos.m_z = m_z;
    }
    else
    {
      v21 = (float)((float)v12 / (float)v20);
      portalPoint->m_pos.m_x = (float)((float)v18 * (float)v21) + (float)v14;
      portalPoint->m_pos.m_y = (float)((float)v16 * (float)v21) + (float)m_y;
      portalPoint->m_pos.m_z = (float)((float)v17 * (float)v21) + (float)m_z;
    }
    portalPoint->m_posIsOnPortalPerimeter = true;
  }
  else
  {
    v7 = v23.m_x;
    v8 = v23.m_y;
    v9 = v23.m_z;
    portalPoint->m_posIsOnPortalPerimeter = false;
    portalPoint->m_pos.m_x = v7;
    portalPoint->m_pos.m_y = v8;
    portalPoint->m_pos.m_z = v9;
  }
}


// ========================================================================
// ?MeasurePolylineLength@Path3D@bfx@@ABAMABVVec3@2@I@Z
// EA  : 0x8329D660
// RVA : 0x0129D660
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxpath3d.cpp
// ========================================================================

float __fastcall bfx::Path3D::MeasurePolylineLength(
        bfx::Path3D *this,
        const bfx::Vec3 *startPos,
        signed int nextPointIdx)
{
  int m_size; // r11
  double v4; // fp9
  double m_y; // fp13
  double m_z; // fp0
  double m_x; // fp12
  bfx::Path3DPoint *m_data; // r8
  int v9; // r11
  unsigned int v10; // r10
  float v11; // r5
  double v12; // fp4
  double v13; // fp3
  double v14; // fp10
  double v15; // fp7
  double v16; // fp5
  double v17; // fp1
  float v19; // [sp+4h] [-Ch]
  float v20; // [sp+8h] [-8h]

  m_size = this->m_portalPoints.m_size;
  v4 = 0.0;
  m_y = startPos->m_y;
  m_z = startPos->m_z;
  m_x = startPos->m_x;
  if ( nextPointIdx < m_size )
  {
    m_data = this->m_portalPoints.m_data;
    v9 = m_size - nextPointIdx;
    v10 = nextPointIdx;
    do
    {
      --v9;
      v11 = m_data[v10].m_pos.m_x;
      v19 = m_data[v10].m_pos.m_y;
      v20 = m_data[v10++].m_pos.m_z;
      v12 = (float)((float)((float)(v20 - (float)m_z) * (float)(v20 - (float)m_z))
                  + (float)((float)(v19 - (float)m_y) * (float)(v19 - (float)m_y)));
      m_z = v20;
      m_y = v19;
      v13 = (float)((float)((float)(v11 - (float)m_x) * (float)(v11 - (float)m_x)) + (float)v12);
      m_x = v11;
      v4 = (float)((float)__fsqrts(v13) + (float)v4);
    }
    while ( v9 != 0 );
  }
  v14 = (float)(this->m_finalPos.m_y - (float)m_y);
  v15 = (float)(this->m_finalPos.m_z - (float)m_z);
  v16 = (float)(this->m_finalPos.m_x - (float)m_x);
  v17 = (float)((float)__fsqrts((float)((float)((float)v16 * (float)v16)
                                      + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14))))
              + (float)v4);
  return *((float *)&v17 + 1);
}


// ========================================================================
// ?RefineNextPointOnce@Path3D@bfx@@QAAXABVVec3@2@I@Z
// EA  : 0x8329D740
// RVA : 0x0129D740
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxpath3d.cpp
// ========================================================================

void __fastcall bfx::Path3D::RefineNextPointOnce(bfx::Path3D *this, const bfx::Vec3 *startPos, signed int nextPointIdx)
{
  signed int v3; // r10
  bfx::Path3DPoint *v4; // r5
  bool v5; // zf
  bfx::Vec3 *p_m_pos; // r11
  float m_y; // r9
  float m_z; // r8
  bfx::Vec3 v9; // [sp+50h] [-20h] BYREF

  if ( nextPointIdx < this->m_portalPoints.m_size )
  {
    v3 = nextPointIdx;
    v5 = nextPointIdx != this->m_portalPoints.m_size - 1;
    v4 = &this->m_portalPoints.m_data[nextPointIdx];
    if ( v5 )
      p_m_pos = &this->m_portalPoints.m_data[v3 + 1].m_pos;
    else
      p_m_pos = &this->m_finalPos;
    m_y = p_m_pos->m_y;
    m_z = p_m_pos->m_z;
    v9.m_x = p_m_pos->m_x;
    v9.m_y = m_y;
    v9.m_z = m_z;
    bfx::UpdatePortalPos(prevPos: startPos, nextPos: &v9, portalPoint: v4);
  }
}


// ========================================================================
// ?RefineOnce@Path3D@bfx@@AAAMABVVec3@2@I@Z
// EA  : 0x8329D7C8
// RVA : 0x0129D7C8
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxpath3d.cpp
// ========================================================================

float __fastcall bfx::Path3D::RefineOnce(bfx::Path3D *this, const bfx::Vec3 *startPos, signed int nextPointIdx)
{
  float m_y; // r10
  float m_z; // r9
  int m_size; // r8
  signed int v9; // r28
  signed int v10; // r30
  bfx::Path3DPoint *v11; // r29
  bfx::Vec3 *p_m_finalPos; // r11
  float v13; // r9
  float v14; // r8
  int v15; // r7
  double v16; // fp1
  bfx::Vec3 v18; // [sp+50h] [-60h] BYREF
  bfx::Vec3 v19; // [sp+60h] [-50h] BYREF

  m_y = startPos->m_y;
  m_z = startPos->m_z;
  m_size = this->m_portalPoints.m_size;
  v9 = nextPointIdx;
  v18.m_x = startPos->m_x;
  v18.m_y = m_y;
  v18.m_z = m_z;
  if ( nextPointIdx < m_size )
  {
    v10 = nextPointIdx;
    do
    {
      v11 = &this->m_portalPoints.m_data[v10];
      if ( v9 == this->m_portalPoints.m_size - 1 )
        p_m_finalPos = &this->m_finalPos;
      else
        p_m_finalPos = &this->m_portalPoints.m_data[v10 + 1].m_pos;
      v13 = p_m_finalPos->m_y;
      v14 = p_m_finalPos->m_z;
      v19.m_x = p_m_finalPos->m_x;
      v19.m_y = v13;
      v19.m_z = v14;
      bfx::UpdatePortalPos(prevPos: &v18, nextPos: &v19, portalPoint: v11);
      v18.m_x = v11->m_pos.m_x;
      v15 = this->m_portalPoints.m_size;
      ++v9;
      v18.m_y = v11->m_pos.m_y;
      ++v10;
      v18.m_z = v11->m_pos.m_z;
    }
    while ( v9 < v15 );
  }
  v16 = bfx::Path3D::MeasurePolylineLength(this, startPos, nextPointIdx);
  return *((float *)&v16 + 1);
}


// ========================================================================
// ?Refine@Path3D@bfx@@QAAMABVVec3@2@I@Z
// EA  : 0x8329D8B0
// RVA : 0x0129D8B0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxpath3d.cpp
// ========================================================================

float __fastcall bfx::Path3D::Refine(bfx::Path3D *this, const bfx::Vec3 *startPos, signed int nextPointIdx)
{
  double v6; // fp1
  int i; // r27
  double v8; // fp30

  v6 = bfx::Path3D::MeasurePolylineLength(this, startPos, nextPointIdx);
  if ( v6 >= 1.0842022e-19 )
  {
    for ( i = 8; i != 0; --i )
    {
      v8 = v6;
      v6 = bfx::Path3D::RefineOnce(this, startPos, nextPointIdx);
      if ( (float)((float)1.0 - (float)((float)v6 / (float)v8)) < 0.0099999998 )
        break;
    }
  }
  else
  {
    v6 = 0.0;
  }
  return *((float *)&v6 + 1);
}


// ========================================================================
// ?DrawToEnd@Cursor@Path3D@bfx@@QBAXPAVSpace@3@ABVVec3@3@@Z
// EA  : 0x8329D950
// RVA : 0x0129D950
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxpath3d.cpp
// ========================================================================

void __fastcall bfx::Path3D::Cursor::DrawToEnd(bfx::Path3D::Cursor *this, bfx::Space *pSpace, const bfx::Vec3 *curPos)
{
  bfx::Path3D *m_pPath; // r11
  float m_y; // r7
  float m_z; // r6
  signed int m_size; // r9
  signed int m_idx; // r29
  double m_x; // fp29
  double v11; // fp30
  double v12; // fp31
  double v13; // fp26
  double v14; // fp27
  double v15; // fp28
  int v16; // r28
  float *v17; // r31
  float v18; // r9
  float v19; // r11
  float v20; // r10
  double Scale; // fp1
  const bfx::Color *v22; // r5
  float v23; // r7
  float v24; // r11
  float v25; // r8
  double v26; // fp1
  const bfx::Color *v27; // r5
  bfx::Path3D *v28; // r11
  bfx::Vec3 *p_m_finalPos; // r31
  double v30; // fp1
  const bfx::Color *v31; // r5
  bfx::Vec3 v32; // [sp+50h] [-110h] BYREF
  bfx::Vec3 v33; // [sp+60h] [-100h] BYREF
  bfx::Vec3 v34; // [sp+70h] [-F0h] BYREF
  float v35; // [sp+7Ch] [-E4h]
  float v36; // [sp+80h] [-E0h]
  float v37; // [sp+84h] [-DCh]
  bfx::Vec3 v38; // [sp+90h] [-D0h] BYREF
  float v39; // [sp+9Ch] [-C4h]
  float v40; // [sp+A0h] [-C0h]
  float v41; // [sp+A4h] [-BCh]
  bfx::Vec3 v42; // [sp+B0h] [-B0h] BYREF
  float v43; // [sp+BCh] [-A4h]
  float v44; // [sp+C0h] [-A0h]
  float v45; // [sp+C4h] [-9Ch]
  bfx::Vec3 v46; // [sp+D0h] [-90h] BYREF
  float v47; // [sp+DCh] [-84h]
  float v48; // [sp+E0h] [-80h]
  float v49; // [sp+E4h] [-7Ch]

  m_pPath = this->m_pPath;
  if ( this->m_pPath != nullptr )
  {
    m_y = curPos->m_y;
    m_z = curPos->m_z;
    m_size = m_pPath->m_portalPoints.m_size;
    m_idx = this->m_idx;
    v33.m_x = curPos->m_x;
    m_x = v33.m_x;
    v33.m_y = m_y;
    v11 = m_y;
    v33.m_z = m_z;
    v12 = m_z;
    v32.m_x = v33.m_x;
    v13 = v33.m_x;
    v32.m_y = m_y;
    v14 = m_y;
    v32.m_z = m_z;
    v15 = m_z;
    if ( m_idx < m_size )
    {
      v16 = m_idx;
      do
      {
        v17 = (float *)&m_pPath->m_portalPoints.m_data[v16];
        v18 = v17[6];
        v19 = v17[7];
        v20 = v17[5];
        v34.m_x = m_x;
        v34.m_y = v11;
        v34.m_z = v12;
        v32.m_y = v18;
        v32.m_z = v19;
        v32.m_x = v20;
        v37 = v19;
        v36 = v18;
        v35 = v20;
        bfx::DrawLineList(pSpace, pVerts: &v34, numVerts: 2, color: &ColorBlue_15);
        Scale = bfx::GetScale();
        bfx::DrawCross(pSpace, pos: &v32, radius: Scale, color: v22, a5: &ColorBlue_15);
        v23 = v17[1];
        v24 = v17[2];
        v25 = v17[3];
        v38.m_x = v13;
        v38.m_y = v14;
        v38.m_z = v15;
        v33.m_x = v23;
        v33.m_y = v24;
        v33.m_z = v25;
        v41 = v25;
        v40 = v24;
        v39 = v23;
        m_x = v32.m_x;
        v11 = v32.m_y;
        v12 = v32.m_z;
        bfx::DrawLineList(pSpace, pVerts: &v38, numVerts: 2, color: &ColorYellow_15);
        v26 = bfx::GetScale();
        bfx::DrawCross(pSpace, pos: &v33, radius: v26, color: v27, a5: &ColorYellow_15);
        m_pPath = this->m_pPath;
        ++m_idx;
        ++v16;
        v13 = v33.m_x;
        v14 = v33.m_y;
        v15 = v33.m_z;
      }
      while ( m_idx < this->m_pPath->m_portalPoints.m_size );
    }
    v42.m_x = m_x;
    v42.m_y = v11;
    v42.m_z = v12;
    v43 = m_pPath->m_finalPos.m_x;
    v44 = m_pPath->m_finalPos.m_y;
    v45 = m_pPath->m_finalPos.m_z;
    bfx::DrawLineList(pSpace, pVerts: &v42, numVerts: 2, color: &ColorBlue_15);
    v28 = this->m_pPath;
    v46.m_x = v13;
    v46.m_y = v14;
    v46.m_z = v15;
    v47 = v28->m_finalPos.m_x;
    v48 = v28->m_finalPos.m_y;
    v49 = v28->m_finalPos.m_z;
    bfx::DrawLineList(pSpace, pVerts: &v46, numVerts: 2, color: &ColorYellow_15);
    p_m_finalPos = &this->m_pPath->m_finalPos;
    v30 = bfx::GetScale();
    bfx::DrawCross(pSpace, pos: p_m_finalPos, radius: v30, color: v31, a5: &ColorYellow_15);
  }
}


// ========================================================================
// ??0Path3DDatabase@bfx@@QAA@XZ
// EA  : 0x8329DB90
// RVA : 0x0129DB90
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxpath3d.cpp
// ========================================================================

bfx::Path3DDatabase *__fastcall bfx::Path3DDatabase::Path3DDatabase(bfx::Path3DDatabase *this)
{
  bfx::bfxMemTag v1; // r10

  v1 = bfx::MEM_BFXPLANNER3D;
  this->m_paths.m_data = nullptr;
  this->m_paths.m_size = 0;
  this->m_paths.m_cap = 0;
  this->m_paths.m_tag = v1;
  return this;
}


// ========================================================================
// ?VolumeUserDataChanged@Path3DDatabase@bfx@@QAAXPBVVolume@2@@Z
// EA  : 0x8329DBB0
// RVA : 0x0129DBB0
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxpath3d.cpp
// ========================================================================

void __fastcall bfx::Path3DDatabase::VolumeUserDataChanged(bfx::Path3DDatabase *this, const bfx::Volume *pVolume)
{
  int v4; // r25
  int v5; // r27
  bfx::Path3D *v6; // r31
  int v7; // r29
  int v8; // r30

  v4 = 0;
  if ( this->m_paths.m_size > 0 )
  {
    v5 = 0;
    do
    {
      v6 = this->m_paths.m_data[v5];
      if ( (v6->m_pathSpec->m_customGeoMatchFlags & pVolume->m_userData) == 0 && v6->m_pFinalVolume != pVolume )
      {
        v7 = 0;
        if ( v6->m_portalPoints.m_size > 0 )
        {
          v8 = 0;
          while ( bfx::Portal::GetVolumeTo(
                    this: (bfx::Portal *)v6->m_portalPoints.m_data[v8].m_pPortal,
                    dir: v6->m_portalPoints.m_data[v8].m_dir) != pVolume )
          {
            ++v7;
            ++v8;
            if ( v7 >= v6->m_portalPoints.m_size )
              goto LABEL_11;
          }
          v6->m_valid = false;
        }
      }
LABEL_11:
      ++v4;
      ++v5;
    }
    while ( v4 < this->m_paths.m_size );
  }
}


// ========================================================================
// ??0Path3D@bfx@@QAA@PAVSpace@1@ABVPath3DSpec@1@ABV?$Array@UPath3DPoint@bfx@@@1@PBVVolume@1@ABVVec3@1@@Z
// EA  : 0x8329DDA8
// RVA : 0x0129DDA8
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxpath3d.cpp
// ========================================================================

bfx::Path3D *__fastcall bfx::Path3D::Path3D(
        bfx::Path3D *this,
        bfx::Space *pSpace,
        const bfx::Path3DSpec *pathSpec,
        const bfx::Array<bfx::Path3DPoint> *portalPoints,
        const bfx::Volume *pFinalVolume,
        const bfx::Vec3 *finalPos)
{
  float m_z; // r8
  bfx::Planner3D *Planner3D; // r3
  bfx::Path3D *v12; // [sp+50h] [-30h] BYREF

  this->m_pSpace = pSpace;
  this->m_pathSpec = pathSpec;
  bfx::Array<bfx::Path3DPoint>::Array<bfx::Path3DPoint>(this: &this->m_portalPoints, rhs: portalPoints);
  this->m_pFinalVolume = pFinalVolume;
  this->m_finalPos.m_x = finalPos->m_x;
  this->m_finalPos.m_y = finalPos->m_y;
  m_z = finalPos->m_z;
  this->m_valid = true;
  this->m_finalPos.m_z = m_z;
  Planner3D = bfx::GetPlanner3D(pSpace: this->m_pSpace);
  v12 = this;
  bfx::Array<bfx::Portal *>::push_back(
    this: (bfx::Array<bfx::Space *> *)Planner3D->m_pPath3DDatabase,
    val: (bfx::Space **)&v12);
  return this;
}


// ========================================================================
// __unwind$17553
// EA  : 0x8329DE24
// RVA : 0x0129DE24
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxpath3d.cpp
// ========================================================================

void _unwind_17553()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 8));
}


// ========================================================================
// ??0Path3D@bfx@@QAA@PAVSpace@1@ABVPath3DSpec@1@PBVVolume@1@ABVVec3@1@@Z
// EA  : 0x8329DE58
// RVA : 0x0129DE58
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxpath3d.cpp
// ========================================================================

bfx::Path3D *__fastcall bfx::Path3D::Path3D(
        bfx::Path3D *this,
        bfx::Space *pSpace,
        const bfx::Path3DSpec *pathSpec,
        const bfx::Volume *pFinalVolume,
        const bfx::Vec3 *finalPos)
{
  bfx::bfxMemTag v6; // r10
  float m_z; // r4
  bfx::Planner3D *Planner3D; // r3
  bfx::Space *p_m_portalPoints; // [sp+50h] [-20h] BYREF

  this->m_pSpace = pSpace;
  this->m_pathSpec = pathSpec;
  p_m_portalPoints = (bfx::Space *)&this->m_portalPoints;
  v6 = bfx::MEM_BFXPLANNER3D;
  this->m_portalPoints.m_data = nullptr;
  this->m_portalPoints.m_size = 0;
  this->m_portalPoints.m_cap = 0;
  this->m_portalPoints.m_tag = v6;
  this->m_pFinalVolume = pFinalVolume;
  this->m_finalPos.m_x = finalPos->m_x;
  this->m_finalPos.m_y = finalPos->m_y;
  m_z = finalPos->m_z;
  this->m_valid = true;
  this->m_finalPos.m_z = m_z;
  Planner3D = bfx::GetPlanner3D(pSpace: this->m_pSpace);
  p_m_portalPoints = (bfx::Space *)this;
  bfx::Array<bfx::Portal *>::push_back(
    this: (bfx::Array<bfx::Space *> *)Planner3D->m_pPath3DDatabase,
    val: &p_m_portalPoints);
  return this;
}


// ========================================================================
// __unwind$17577
// EA  : 0x8329DEFC
// RVA : 0x0129DEFC
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxpath3d.cpp
// ========================================================================

void _unwind_17577()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 112 + 132)
                                                                                             + 8));
}


// ========================================================================
// ??1Path3D@bfx@@QAA@XZ
// EA  : 0x8329DF30
// RVA : 0x0129DF30
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxpath3d.cpp
// ========================================================================

void __fastcall bfx::Path3D::~Path3D(bfx::Path3D *this)
{
  bfx::Planner3D *Planner3D; // r3
  char *m_data; // r4
  bfx::Path3D *v4; // [sp+50h] [-30h] BYREF

  Planner3D = bfx::GetPlanner3D(pSpace: this->m_pSpace);
  v4 = this;
  bfx::Array<bfx::Path3D *>::remove(
    this: (bfx::Array<bfx::Space *> *)Planner3D->m_pPath3DDatabase,
    val: (bfx::Space **)&v4);
  m_data = (char *)this->m_portalPoints.m_data;
  this->m_portalPoints.m_size = 0;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_portalPoints.m_data = nullptr;
  }
  this->m_portalPoints.m_cap = 0;
}


// ========================================================================
// __unwind$17611
// EA  : 0x8329DF94
// RVA : 0x0129DF94
// PDB : w:\tech5\libs\navpower\src\bfxplanner3d\bfxpath3d.cpp
// ========================================================================

void _unwind_17611()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 8));
}

