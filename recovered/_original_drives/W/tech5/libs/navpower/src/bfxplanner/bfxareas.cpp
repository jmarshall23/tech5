
// ========================================================================
// ?IncAreaUsageCount@AreaFlags@bfx@@QAAXXZ
// EA  : 0x8326FAA8
// RVA : 0x0126FAA8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

void __fastcall bfx::AreaFlags::IncAreaUsageCount(bfx::AreaFlags *this)
{
  this->m_flags4 = this->m_flags4 & 0xFFFFFC00 | ((unsigned __int16)this->m_flags4 + 1) & 0x3FF;
}


// ========================================================================
// ?DecAreaUsageCount@AreaFlags@bfx@@QAAXXZ
// EA  : 0x8326FAC0
// RVA : 0x0126FAC0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

void __fastcall bfx::AreaFlags::DecAreaUsageCount(bfx::AreaFlags *this)
{
  this->m_flags4 = this->m_flags4 & 0xFFFFFC00 | ((unsigned __int16)this->m_flags4 - 1) & 0x3FF;
}


// ========================================================================
// ?GetSharedEdgeCC@bfx@@YA?AVEdgeCursor@1@PAVArea@1@0@Z
// EA  : 0x8326FAD8
// RVA : 0x0126FAD8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

bfx::EdgeCursor *__fastcall bfx::GetSharedEdgeCC(bfx::EdgeCursor *result, bfx::Area *pArea0, bfx::Area *pArea1)
{
  signed int v3; // r11
  signed int v4; // r9
  bfx::Area **v5; // r10
  bfx::EdgeCursor back_chain; // [sp+0h] [-10h]

  back_chain.m_pArea = pArea0;
  v4 = pArea0->m_flags.m_flags1 & 0x7F;
  if ( v4 != 0 )
  {
    v5 = (bfx::Area **)&pArea0[1];
    while ( *v5 != pArea1 )
    {
      ++v3;
      v5 += 6;
      if ( v3 >= v4 )
        goto LABEL_5;
    }
    back_chain.m_i = v3;
    *result = back_chain;
  }
  else
  {
LABEL_5:
    result->m_pArea = nullptr;
    result->m_i = -1;
  }
  return result;
}


// ========================================================================
// ?GetSharedEdgeIdx@bfx@@YAHPAVArea@1@0@Z
// EA  : 0x8326FB40
// RVA : 0x0126FB40
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

int __fastcall bfx::GetSharedEdgeIdx(bfx::Area *pArea0, bfx::Area *pArea1)
{
  int v2; // r9
  signed int v3; // r11
  signed int v4; // r8
  bfx::Area **i; // r10

  v2 = 0;
  v3 = 0;
  v4 = pArea0->m_flags.m_flags1 & 0x7F;
  if ( v4 == 0 )
    return -1;
  for ( i = (bfx::Area **)&pArea0[1]; *i != pArea1; i += 6 )
  {
    ++v3;
    ++v2;
    if ( v3 >= v4 )
      return -1;
  }
  return v2;
}


// ========================================================================
// ?GetSibling@EdgeCursor@bfx@@QAA?AV12@XZ
// EA  : 0x8326FB90
// RVA : 0x0126FB90
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

bfx::EdgeCursor *__fastcall bfx::EdgeCursor::GetSibling(bfx::EdgeCursor *this, bfx::EdgeCursor *result)
{
  bfx::AreaProxy *v2; // r11
  int v3; // r10
  int v4; // r9
  bfx::Area **p_m_pArea; // r11
  bfx::EdgeCursor back_chain; // [sp+0h] [-10h]

  v2 = (&result->m_pArea[1].m_pProxy)[6 * result->m_i];
  if ( v2 != nullptr && (v3 = 0, (v4 = (int)v2[5].m_pArea & 0x7F) != 0) )
  {
    p_m_pArea = &v2[7].m_pArea;
    while ( *p_m_pArea != result->m_pArea )
    {
      ++v3;
      p_m_pArea += 6;
      if ( v3 >= v4 )
        goto LABEL_6;
    }
    back_chain.m_i = v3;
    back_chain.m_pArea = (bfx::Area *)(&result->m_pArea[1].m_pProxy)[6 * result->m_i];
    *this = back_chain;
  }
  else
  {
LABEL_6:
    this->m_i = -1;
    this->m_pArea = nullptr;
  }
  return this;
}


// ========================================================================
// ?RemoveLink@Area@bfx@@QAAXPAVHalfLink@2@@Z
// EA  : 0x8326FC18
// RVA : 0x0126FC18
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

void __fastcall bfx::Area::RemoveLink(bfx::Area *this, bfx::HalfLink *pLinkToRemove)
{
  bfx::HalfLink *m_pFirstLink; // r10
  bfx::HalfLink *m_pNext; // r11

  m_pFirstLink = this->m_pFirstLink;
  if ( m_pFirstLink != nullptr && pLinkToRemove != nullptr )
  {
    m_pNext = m_pFirstLink->m_pNext;
    if ( m_pFirstLink == pLinkToRemove )
    {
      this->m_pFirstLink = m_pNext;
    }
    else if ( m_pNext != nullptr )
    {
      while ( m_pNext != pLinkToRemove )
      {
        m_pFirstLink = m_pNext;
        m_pNext = m_pNext->m_pNext;
        if ( m_pNext == nullptr )
          return;
      }
      m_pFirstLink->m_pNext = m_pNext->m_pNext;
    }
  }
}


// ========================================================================
// ?Translate@Area@bfx@@QAAXABVVec3@2@@Z
// EA  : 0x8326FC70
// RVA : 0x0126FC70
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

void __fastcall bfx::Area::Translate(bfx::Area *this, const bfx::Vec3 *offset)
{
  signed int v2; // r10
  double v3; // fp7
  double v4; // fp6
  unsigned int v5; // r9
  float *v6; // r11
  double m_y; // fp13
  double m_z; // fp12
  double v9; // fp11
  double v10; // fp10
  double v11; // fp4
  double v12; // fp3
  double v13; // fp9
  double v14; // fp8
  double v15; // fp4
  double v16; // fp0
  double v17; // fp13
  double v18; // fp9
  unsigned int v19; // r9
  float *v20; // r11
  double v21; // fp13
  double v22; // fp12
  double v23; // fp11
  float back_chain; // [sp+4h] [-Ch]
  float back_chaina; // [sp+4h] [-Ch]
  float back_chainb; // [sp+4h] [-Ch]
  float back_chainc; // [sp+4h] [-Ch]
  float v28; // [sp+8h] [-8h]

  v2 = 0;
  v3 = (float)(this->m_pos.m_y + offset->m_y);
  v4 = (float)(this->m_pos.m_z + offset->m_z);
  this->m_pos.m_x = offset->m_x + this->m_pos.m_x;
  this->m_pos.m_y = v3;
  this->m_pos.m_z = v4;
  v5 = this->m_flags.m_flags1 & 0x7F;
  if ( v5 >= 4 )
  {
    v6 = (float *)((char *)this + 68);
    do
    {
      m_y = offset->m_y;
      m_z = offset->m_z;
      v2 += 4;
      v9 = *(v6 - 1);
      v10 = *v6;
      *(v6 - 2) = offset->m_x + *(v6 - 2);
      *(v6 - 1) = (float)m_y + (float)v9;
      *v6 = (float)v10 + (float)m_z;
      v11 = offset->m_y;
      v12 = offset->m_z;
      back_chain = v6[5];
      v28 = v6[6];
      v6[4] = offset->m_x + v6[4];
      v6[5] = (float)v11 + back_chain;
      v6[6] = v28 + (float)v12;
      v13 = offset->m_y;
      v14 = offset->m_z;
      back_chaina = v6[11];
      v15 = v6[12];
      v6[10] = offset->m_x + v6[10];
      v6[11] = (float)v13 + back_chaina;
      v6[12] = (float)v15 + (float)v14;
      v16 = offset->m_y;
      v17 = offset->m_z;
      back_chainb = v6[17];
      v18 = v6[18];
      v6[16] = offset->m_x + v6[16];
      v6[17] = (float)v16 + back_chainb;
      v6[18] = (float)v18 + (float)v17;
      v6 += 24;
    }
    while ( v2 < (int)(v5 - 3) );
  }
  if ( v2 < (int)v5 )
  {
    v19 = v5 - v2;
    v20 = (float *)((char *)this + 24 * v2 + 60);
    do
    {
      v21 = offset->m_y;
      v22 = offset->m_z;
      --v19;
      back_chainc = v20[1];
      v23 = v20[2];
      *v20 = offset->m_x + *v20;
      v20[2] = (float)v23 + (float)v22;
      v20[1] = (float)v21 + back_chainc;
      v20 += 6;
    }
    while ( v19 != 0 );
  }
}


// ========================================================================
// ?Translate@Area@bfx@@QAAXABVMatrix@2@@Z
// EA  : 0x8326FE68
// RVA : 0x0126FE68
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

void __fastcall bfx::Area::Translate(bfx::Area *this, bfx::Vec3 *mat)
{
  bfx::Matrix *v4; // r3
  unsigned int v5; // r30
  float *v6; // r31
  float v7; // r10
  float v8; // r9
  bfx::Matrix *v9; // r3
  bfx::Vec3 v10; // [sp+50h] [-40h] BYREF
  _BYTE v11[48]; // [sp+60h] [-30h] BYREF

  v4 = bfx::Matrix::operator*(this: (bfx::Matrix *)v11, result: mat, rhs: &this->m_pos);
  this->m_pos.m_x = v4->m_data[0];
  this->m_pos.m_y = v4->m_data[1];
  this->m_pos.m_z = v4->m_data[2];
  v5 = this->m_flags.m_flags1 & 0x7F;
  if ( v5 != 0 )
  {
    v6 = (float *)((char *)this + 60);
    do
    {
      v7 = v6[1];
      v8 = v6[2];
      v10.m_x = *v6;
      v10.m_y = v7;
      v10.m_z = v8;
      v9 = bfx::Matrix::operator*(this: (bfx::Matrix *)v11, result: mat, rhs: &v10);
      *v6 = v9->m_data[0];
      --v5;
      v6[1] = v9->m_data[1];
      v6[2] = v9->m_data[2];
      v6 += 6;
    }
    while ( v5 != 0 );
  }
}


// ========================================================================
// ?GetNumPortalEdgesInArea@bfx@@YAHPBVArea@1@@Z
// EA  : 0x8326FF08
// RVA : 0x0126FF08
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

int __fastcall bfx::GetNumPortalEdgesInArea(const bfx::Area *pArea)
{
  int result; // r3
  signed int v3; // r11
  const bfx::Area *v4; // r10
  signed int i; // ctr

  v3 = pArea->m_flags.m_flags1 & 0x7F;
  result = 0;
  if ( v3 > 0 )
  {
    v4 = (const bfx::Area *)((char *)pArea + 72);
    for ( i = v3; i != 0; --i )
    {
      if ( ((int)v4->m_pProxy & 0x6000) == 0x2000 )
        ++result;
      v4 = (const bfx::Area *)((char *)v4 + 24);
    }
  }
  return result;
}


// ========================================================================
// ?GetNumConnectedPortalEdgesInArea@bfx@@YAHPBVArea@1@@Z
// EA  : 0x8326FF48
// RVA : 0x0126FF48
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

int __fastcall bfx::GetNumConnectedPortalEdgesInArea(const bfx::Area *pArea)
{
  int result; // r3
  signed int v3; // r11
  const bfx::Area *v4; // r10
  signed int i; // ctr

  v3 = pArea->m_flags.m_flags1 & 0x7F;
  result = 0;
  if ( v3 > 0 )
  {
    v4 = pArea + 1;
    for ( i = v3; i != 0; --i )
    {
      if ( (LODWORD(v4->m_pos.m_x) & 0x6000) == 0x2000 && v4->m_pProxy != nullptr )
        ++result;
      v4 = (const bfx::Area *)((char *)v4 + 24);
    }
  }
  return result;
}


// ========================================================================
// ?GetDefaultMinEdgeLength@bfx@@YAMXZ
// EA  : 0x8326FF98
// RVA : 0x0126FF98
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

float __fastcall bfx::GetDefaultMinEdgeLength()
{
  double v0; // fp1

  v0 = (float)(bfx::GetScale() * (float)0.000099999997);
  return *((float *)&v0 + 1);
}


// ========================================================================
// ?GetMinEdgeLengthBasedOnDistanceFromOrigin@bfx@@YAMM@Z
// EA  : 0x8326FFC8
// RVA : 0x0126FFC8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

float __fastcall bfx::GetMinEdgeLengthBasedOnDistanceFromOrigin(double distFromOrigin)
{
  double v1; // fp1

  v1 = (float)((float)distFromOrigin * (float)0.000000298);
  return *((float *)&v1 + 1);
}


// ========================================================================
// ?RotateVecIntoNewArea@bfx@@YA?AVVec3@1@ABV21@000@Z
// EA  : 0x8326FFD8
// RVA : 0x0126FFD8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

bfx::Vec3 *__fastcall bfx::RotateVecIntoNewArea(
        bfx::Vec3 *result,
        const bfx::Vec3 *vec,
        const bfx::Vec3 *edgeUnitVec,
        const bfx::Vec3 *oldAreaNormal,
        const bfx::Vec3 *newAreaNormal)
{
  double v5; // fp5
  double v6; // fp1
  double v7; // fp11
  double v8; // fp10

  v5 = (float)(edgeUnitVec->m_y
             * (float)((float)(edgeUnitVec->m_z * vec->m_z)
                     + (float)((float)(edgeUnitVec->m_x * vec->m_x) + (float)(edgeUnitVec->m_y * vec->m_y))));
  v6 = (float)(edgeUnitVec->m_z
             * (float)((float)(edgeUnitVec->m_z * vec->m_z)
                     + (float)((float)(edgeUnitVec->m_x * vec->m_x) + (float)(edgeUnitVec->m_y * vec->m_y))));
  v7 = (float)((float)((float)(newAreaNormal->m_x * edgeUnitVec->m_z) - (float)(newAreaNormal->m_z * edgeUnitVec->m_x))
             * (float)((float)(vec->m_y
                             * (float)((float)(oldAreaNormal->m_x * edgeUnitVec->m_z)
                                     - (float)(oldAreaNormal->m_z * edgeUnitVec->m_x)))
                     + (float)((float)(vec->m_x
                                     * (float)((float)(oldAreaNormal->m_z * edgeUnitVec->m_y)
                                             - (float)(oldAreaNormal->m_y * edgeUnitVec->m_z)))
                             + (float)(vec->m_z
                                     * (float)((float)(oldAreaNormal->m_y * edgeUnitVec->m_x)
                                             - (float)(oldAreaNormal->m_x * edgeUnitVec->m_y))))));
  v8 = (float)((float)((float)(newAreaNormal->m_y * edgeUnitVec->m_x) - (float)(newAreaNormal->m_x * edgeUnitVec->m_y))
             * (float)((float)(vec->m_y
                             * (float)((float)(oldAreaNormal->m_x * edgeUnitVec->m_z)
                                     - (float)(oldAreaNormal->m_z * edgeUnitVec->m_x)))
                     + (float)((float)(vec->m_x
                                     * (float)((float)(oldAreaNormal->m_z * edgeUnitVec->m_y)
                                             - (float)(oldAreaNormal->m_y * edgeUnitVec->m_z)))
                             + (float)(vec->m_z
                                     * (float)((float)(oldAreaNormal->m_y * edgeUnitVec->m_x)
                                             - (float)(oldAreaNormal->m_x * edgeUnitVec->m_y))))));
  result->m_x = (float)((float)((float)(newAreaNormal->m_z * edgeUnitVec->m_y)
                              - (float)(newAreaNormal->m_y * edgeUnitVec->m_z))
                      * (float)((float)(vec->m_y
                                      * (float)((float)(oldAreaNormal->m_x * edgeUnitVec->m_z)
                                              - (float)(oldAreaNormal->m_z * edgeUnitVec->m_x)))
                              + (float)((float)(vec->m_x
                                              * (float)((float)(oldAreaNormal->m_z * edgeUnitVec->m_y)
                                                      - (float)(oldAreaNormal->m_y * edgeUnitVec->m_z)))
                                      + (float)(vec->m_z
                                              * (float)((float)(oldAreaNormal->m_y * edgeUnitVec->m_x)
                                                      - (float)(oldAreaNormal->m_x * edgeUnitVec->m_y))))))
              + (float)(edgeUnitVec->m_x
                      * (float)((float)(edgeUnitVec->m_z * vec->m_z)
                              + (float)((float)(edgeUnitVec->m_x * vec->m_x) + (float)(edgeUnitVec->m_y * vec->m_y))));
  result->m_y = (float)v7 + (float)v5;
  result->m_z = (float)v8 + (float)v6;
  return result;
}


// ========================================================================
// ?GetClosestPosInArea@bfx@@YA?AVVec3@1@PBVArea@1@ABV21@PAH@Z
// EA  : 0x832700A8
// RVA : 0x012700A8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

bfx::Vec3 *__fastcall bfx::GetClosestPosInArea(
        bfx::Vec3 *result,
        bfx::Vec3 *pArea,
        const bfx::Vec3 *pos,
        int *pEdgeIndexOut)
{
  char v8; // r6
  signed int v9; // r11
  int v10; // r7
  double v11; // fp25
  int v12; // r10
  float *p_m_x; // r9
  double v14; // fp28
  double v15; // fp27
  double v16; // fp26
  double v17; // fp8
  double v18; // fp7
  double v19; // fp6
  double v20; // fp31
  float *v21; // r8
  double m_y; // fp30
  double v23; // fp29
  float v25; // r4
  float v26; // r3
  double v27; // fp5
  double v28; // fp4
  double v29; // fp0
  int v30; // r7
  int v31; // r4
  double m_z; // fp12
  double m_x; // fp10
  double v34; // fp6
  double v36; // fp4
  int v37; // r9
  float v38; // [sp+50h] [-90h]
  bfx::Area v39; // [sp+60h] [-80h] BYREF

  bfx::Area::CalcNormal(this: &v39, result: pArea);
  v8 = 1;
  v9 = LODWORD(pArea[3].m_y) & 0x7F;
  v10 = -1;
  v11 = 3.4028235e38;
  v12 = 0;
  p_m_x = &pArea[2 * v9].m_x;
  v14 = *(float *)&v39.m_pFirstLink;
  v15 = *(float *)&v39.m_dynAreaData.m_data;
  v16 = *(float *)&v39.m_pProxy;
  v17 = p_m_x[11];
  v18 = p_m_x[10];
  v19 = p_m_x[9];
  if ( v9 == 0 )
  {
LABEL_12:
    if ( v8 != 0 )
    {
      m_z = pos->m_z;
      m_x = pos->m_x;
      v34 = (float)((float)((float)(pos->m_x - (float)v19) * (float)v16)
                  + (float)((float)((float)(pos->m_z - (float)v17) * (float)v14)
                          + (float)((float)(pos->m_y - (float)v18) * (float)v15)));
      result->m_y = pos->m_y - (float)((float)v15 * (float)v34);
      result->m_x = (float)m_x - (float)((float)v16 * (float)v34);
      result->m_z = (float)m_z - (float)((float)v14 * (float)v34);
    }
    if ( pEdgeIndexOut != nullptr )
      *pEdgeIndexOut = v10;
    return result;
  }
  v20 = pos->m_x;
  v21 = &pArea[5].m_x;
  m_y = pos->m_y;
  v23 = pos->m_z;
  _R9 = (char *)&pArea[6].m_z;
  while ( 1 )
  {
    v25 = v21[1];
    v26 = v21[2];
    v38 = *v21;
    __asm { dcbt      0, r9 }
    v27 = *v21;
    v28 = v25;
    if ( (float)((float)((float)((float)v20 - (float)v19)
                       * (float)((float)((float)v14 * (float)(v25 - (float)v18))
                               - (float)((float)v15 * (float)(v26 - (float)v17))))
               + (float)((float)((float)((float)v23 - (float)v17)
                               * (float)((float)((float)v15 * (float)(v38 - (float)v19))
                                       - (float)((float)(v25 - (float)v18) * (float)v16)))
                       + (float)((float)((float)m_y - (float)v18)
                               * (float)((float)((float)(v26 - (float)v17) * (float)v16)
                                       - (float)((float)v14 * (float)(v38 - (float)v19)))))) <= 0.0 )
      goto LABEL_11;
    v8 = 0;
    if ( (float)((float)((float)((float)v20 - (float)v19) * (float)(v38 - (float)v19))
               + (float)((float)((float)((float)v23 - (float)v17) * (float)(v26 - (float)v17))
                       + (float)((float)((float)m_y - (float)v18) * (float)(v25 - (float)v18)))) < 0.0 )
    {
      v29 = (float)((float)((float)((float)v20 - (float)v19) * (float)((float)v20 - (float)v19))
                  + (float)((float)((float)((float)v23 - (float)v17) * (float)((float)v23 - (float)v17))
                          + (float)((float)((float)m_y - (float)v18) * (float)((float)m_y - (float)v18))));
      if ( v29 < v11 )
      {
        result->m_x = v19;
        result->m_y = v18;
        __twllei(v9, 0);
        v30 = v12 + v9 - 1;
        result->m_z = v17;
        v31 = __ROL4__(v30, 1) - 1;
        v10 = v30 % v9;
        __twlgei(v9 & ~v31, 0xFFFFFFFF);
LABEL_10:
        v11 = v29;
        goto LABEL_11;
      }
      goto LABEL_11;
    }
    if ( (float)((float)((float)((float)v20 - v38) * (float)(v38 - (float)v19))
               + (float)((float)((float)((float)v23 - v26) * (float)(v26 - (float)v17))
                       + (float)((float)((float)m_y - v25) * (float)(v25 - (float)v18)))) <= 0.0 )
      break;
    v29 = (float)((float)((float)((float)v20 - v38) * (float)((float)v20 - v38))
                + (float)((float)((float)((float)v23 - v26) * (float)((float)v23 - v26))
                        + (float)((float)((float)m_y - v25) * (float)((float)m_y - v25))));
    if ( v29 < v11 )
    {
      result->m_x = v38;
      v10 = v12;
      result->m_y = v25;
      result->m_z = v26;
      goto LABEL_10;
    }
LABEL_11:
    ++v12;
    v19 = v27;
    v21 += 6;
    v18 = v28;
    v17 = v26;
    _R9 = (char *)(v21 + 5);
    if ( v12 >= v9 )
      goto LABEL_12;
  }
  v36 = __fsqrts((float)((float)((float)(v38 - (float)v19) * (float)(v38 - (float)v19))
                       + (float)((float)((float)(v26 - (float)v17) * (float)(v26 - (float)v17))
                               + (float)((float)(v25 - (float)v18) * (float)(v25 - (float)v18)))));
  result->m_x = (float)((float)((float)((float)1.0 / (float)v36) * (float)(v38 - (float)v19))
                      * (float)((float)((float)1.0 / (float)v36)
                              * (float)((float)((float)((float)v20 - (float)v19) * (float)(v38 - (float)v19))
                                      + (float)((float)((float)((float)v23 - (float)v17) * (float)(v26 - (float)v17))
                                              + (float)((float)((float)m_y - (float)v18) * (float)(v25 - (float)v18))))))
              + (float)v19;
  result->m_y = (float)((float)((float)((float)1.0 / (float)v36) * (float)(v25 - (float)v18))
                      * (float)((float)((float)1.0 / (float)v36)
                              * (float)((float)((float)((float)v20 - (float)v19) * (float)(v38 - (float)v19))
                                      + (float)((float)((float)((float)v23 - (float)v17) * (float)(v26 - (float)v17))
                                              + (float)((float)((float)m_y - (float)v18) * (float)(v25 - (float)v18))))))
              + (float)v18;
  result->m_z = (float)((float)((float)((float)1.0 / (float)v36) * (float)(v26 - (float)v17))
                      * (float)((float)((float)1.0 / (float)v36)
                              * (float)((float)((float)((float)v20 - (float)v19) * (float)(v38 - (float)v19))
                                      + (float)((float)((float)((float)v23 - (float)v17) * (float)(v26 - (float)v17))
                                              + (float)((float)((float)m_y - (float)v18) * (float)(v25 - (float)v18))))))
              + (float)v17;
  if ( pEdgeIndexOut == nullptr )
    return result;
  __twllei(v9, 0);
  v37 = v12 + v9 - 1;
  *pEdgeIndexOut = v37 % v9;
  __twlgei(v9 & ~(__ROL4__(v37, 1) - 1), 0xFFFFFFFF);
  return result;
}


// ========================================================================
// ?IsPlanePosInsideArea@bfx@@YA_NABVVec3@1@PBVArea@1@0M@Z
// EA  : 0x83270398
// RVA : 0x01270398
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

int __fastcall bfx::IsPlanePosInsideArea(
        const bfx::Vec3 *pos,
        const bfx::Area *pArea,
        const bfx::Vec3 *areaNormal,
        double tolerance)
{
  signed int v4; // r9
  signed int v5; // r10
  float *v6; // r11
  float *p_m_dynAreaData; // r11
  double v9; // fp12
  double v10; // fp13
  double v11; // fp0
  double v12; // fp29
  double v13; // fp28
  double v14; // fp0
  double v15; // fp13
  double v16; // fp12
  double v17; // fp11
  double v18; // fp11
  float v20; // [sp+0h] [-50h]
  float v21; // [sp+0h] [-50h]
  float v22; // [sp+4h] [-4Ch]
  float v23; // [sp+4h] [-4Ch]
  float v24; // [sp+8h] [-48h]
  float v25; // [sp+8h] [-48h]

  v4 = 0;
  v5 = pArea->m_flags.m_flags1 & 0x7F;
  v6 = (float *)((char *)pArea + 24 * v5);
  v20 = v6[9];
  v22 = v6[10];
  v24 = v6[11];
  if ( v5 == 0 )
    return 1;
  p_m_dynAreaData = (float *)&pArea[1].m_dynAreaData;
  _R8 = (char *)&pArea[1].m_pos.m_z;
  v9 = v24;
  v10 = v22;
  v11 = v20;
  while ( 1 )
  {
    v21 = *p_m_dynAreaData;
    v23 = p_m_dynAreaData[1];
    __asm { dcbt      0, r8 }
    v25 = p_m_dynAreaData[2];
    v12 = (float)(pos->m_x - (float)v11);
    v13 = (float)(v23 - (float)v10);
    v17 = (float)((float)((float)(pos->m_z - (float)v9)
                        * (float)((float)(areaNormal->m_x * (float)(v23 - (float)v10))
                                - (float)(areaNormal->m_y * (float)(v21 - (float)v11))))
                + (float)((float)(pos->m_y - (float)v10)
                        * (float)((float)(areaNormal->m_z * (float)(v21 - (float)v11))
                                - (float)(areaNormal->m_x * (float)(v25 - (float)v9)))));
    v15 = (float)((float)(areaNormal->m_x * (float)(v23 - (float)v10))
                - (float)(areaNormal->m_y * (float)(*p_m_dynAreaData - (float)v11)));
    v14 = (float)((float)(areaNormal->m_z * (float)(*p_m_dynAreaData - (float)v11))
                - (float)(areaNormal->m_x * (float)(v25 - (float)v9)));
    v16 = (float)((float)(areaNormal->m_y * (float)(v25 - (float)v9)) - (float)(areaNormal->m_z * (float)v13));
    v18 = (float)((float)((float)v12 * (float)v16) + (float)v17);
    if ( v18 < 0.0
      && v18 < -(float)((float)__fsqrts((float)((float)((float)v16 * (float)v16)
                                              + (float)((float)((float)v15 * (float)v15)
                                                      + (float)((float)v14 * (float)v14))))
                      * (float)tolerance) )
    {
      break;
    }
    ++v4;
    v11 = v21;
    p_m_dynAreaData += 6;
    v10 = v23;
    v9 = v25;
    _R8 = (char *)(p_m_dynAreaData + 5);
    if ( v4 >= v5 )
      return 1;
  }
  return 0;
}


// ========================================================================
// ?GetFanitude@bfx@@YAXPAVArea@1@HHAA_N1@Z
// EA  : 0x832704F8
// RVA : 0x012704F8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

void __fastcall bfx::GetFanitude(bfx::Area *pCurArea, int entryIndex, int exitIndex, bool *leftFan, bool *rightFan)
{
  signed int v5; // r11
  int v6; // r5

  v5 = pCurArea->m_flags.m_flags1 & 0x7F;
  v6 = v5 - exitIndex + entryIndex;
  __twllei(v5, 0);
  *leftFan = (_cntlzw(v6 % v5 - 1) & 0x20) != 0;
  __twlgei(v5 & ~(__ROL4__(v6, 1) - 1), 0xFFFFFFFF);
  *rightFan = (_cntlzw(v5 - 1 - v6 % v5) & 0x20) != 0;
}


// ========================================================================
// ??1Area@bfx@@QAA@XZ
// EA  : 0x83270550
// RVA : 0x01270550
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

void __fastcall bfx::Area::~Area(bfx::Area *this)
{
  if ( this->m_pProxy != nullptr )
    this->m_pProxy->m_pArea = nullptr;
  bfx::DynAreaData::Clear(this: &this->m_dynAreaData);
}


// ========================================================================
// ?CalcBasisVert@Area@bfx@@QBAHXZ
// EA  : 0x83270570
// RVA : 0x01270570
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

int __fastcall bfx::Area::CalcBasisVert(bfx::Area *this)
{
  signed int v1; // r10
  unsigned int v2; // r4
  float *v3; // r11
  float *v4; // r9
  float v5; // r30
  float v6; // r29
  float v7; // r28
  float v8; // r27
  float v9; // r26
  double v10; // fp0
  float v11; // r6
  float v12; // r5
  float v13; // r7
  double v14; // fp12
  float v15; // r30
  float v16; // r31
  float *p_m_z; // r9
  float *v18; // r11
  unsigned int v19; // r10
  float v20; // r7
  float v22; // [sp+54h] [-63Ch]
  char v23; // [sp+5Ch] [-634h] BYREF
  bfx::Vec3 v24[132]; // [sp+60h] [-630h] BYREF

  v1 = 0;
  v2 = this->m_flags.m_flags1 & 0x7F;
  if ( v2 >= 4 )
  {
    v3 = (float *)&v23;
    v4 = (float *)((char *)this + 84);
    do
    {
      v5 = *(v4 - 4);
      v1 += 4;
      v6 = *v4;
      v7 = v4[2];
      v8 = v4[1];
      v9 = v4[6];
      v10 = *(v4 - 5);
      v11 = v4[7];
      v3[1] = *(v4 - 6);
      v12 = v4[8];
      v3[2] = v10;
      v13 = v4[12];
      v14 = v5;
      v15 = v4[13];
      v3[3] = v14;
      v16 = v4[14];
      v4 += 24;
      v3[4] = v6;
      v3[5] = v8;
      v3[6] = v7;
      v3[7] = v9;
      v3[8] = v11;
      v3[9] = v12;
      v3[10] = v13;
      v3[11] = v15;
      v3 += 12;
      *v3 = v16;
    }
    while ( v1 < (int)(v2 - 3) );
  }
  if ( v1 < (int)v2 )
  {
    p_m_z = &v24[v1 - 1].m_z;
    v18 = (float *)((char *)this + 24 * v1 + 60);
    v19 = v2 - v1;
    do
    {
      --v19;
      v20 = v18[2];
      v22 = v18[1];
      p_m_z[1] = *v18;
      v18 += 6;
      p_m_z[2] = v22;
      p_m_z += 3;
      *p_m_z = v20;
    }
    while ( v19 != 0 );
  }
  return bfx::CalcBasisVert(vertArray: v24, numVerts: v2);
}


// ========================================================================
// ?CalcBBox@Area@bfx@@QAA?AVBox@2@XZ
// EA  : 0x832706F8
// RVA : 0x012706F8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

bfx::Area *__fastcall bfx::Area::CalcBBox(bfx::Area *this, bfx::Box *result)
{
  bfx::Area **p_m_pSearchParent; // r11
  int v3; // r9
  float *p_m_x; // r10
  float v5; // r6
  float v6; // r8
  float back_chain; // [sp+8h] [-8h]

  p_m_pSearchParent = &this->m_pSearchParent;
  v3 = 0;
  *(float *)&this->m_pProxy = 3.4028235e38;
  *(float *)&this->m_dynAreaData.m_data = 3.4028235e38;
  *(float *)&this->m_pFirstLink = 3.4028235e38;
  *(float *)&this->m_pSearchParent = -3.4028235e38;
  this->m_pos.m_x = -3.4028235e38;
  this->m_pos.m_y = -3.4028235e38;
  if ( (LODWORD(result[1].m_max.m_y) & 0x7F) != 0 )
  {
    p_m_x = &result[2].m_max.m_x;
    do
    {
      v5 = *p_m_x;
      v6 = p_m_x[1];
      ++v3;
      back_chain = p_m_x[2];
      _FP7 = (float)(*(float *)&this->m_dynAreaData.m_data - v6);
      _FP8 = (float)(*(float *)&this->m_pProxy - *p_m_x);
      p_m_x += 6;
      _FP6 = (float)(*(float *)&this->m_pFirstLink - back_chain);
      __asm { fsel      f4, f7, f13, f10 }
      *(float *)&this->m_dynAreaData.m_data = _FP4;
      __asm { fsel      f5, f8, f0, f9 }
      *(float *)&this->m_pProxy = _FP5;
      __asm { fsel      f3, f6, f12, f11 }
      *(float *)&this->m_pFirstLink = _FP3;
      _FP8 = (float)(*(float *)p_m_pSearchParent - v5);
      _FP10 = (float)(this->m_pos.m_x - v6);
      _FP9 = (float)(this->m_pos.m_y - back_chain);
      __asm { fsel      f5, f8, f2, f0 }
      *(float *)p_m_pSearchParent = _FP5;
      __asm { fsel      f7, f10, f11, f13 }
      this->m_pos.m_x = _FP7;
      __asm { fsel      f6, f9, f1, f12 }
      this->m_pos.m_y = _FP6;
    }
    while ( v3 < (LODWORD(result[1].m_max.m_y) & 0x7F) );
  }
  return this;
}


// ========================================================================
// ?DoesAreaIntersectVolume@bfx@@YA_NPAVArea@1@ABV?$Array@VPlane@bfx@@@1@ABVSphere@1@@Z
// EA  : 0x832707E0
// RVA : 0x012707E0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

int __fastcall bfx::DoesAreaIntersectVolume(
        bfx::Area *pArea,
        const bfx::Array<bfx::Plane> *planes,
        const bfx::Sphere *boundingSphere)
{
  unsigned int v3; // r8
  unsigned int v4; // r9
  float *v5; // r10
  float *p_m_dynAreaData; // r11
  float v7; // r7
  int result; // r3
  bool v9; // zf
  float v10; // [sp+50h] [-610h]
  float v11; // [sp+58h] [-608h]
  char v12; // [sp+5Ch] [-604h] BYREF
  bfx::Vec3 v13[127]; // [sp+60h] [-600h] BYREF

  if ( (float)((float)((float)(boundingSphere->m_pos.m_x - pArea->m_pos.m_x)
                     * (float)(boundingSphere->m_pos.m_x - pArea->m_pos.m_x))
             + (float)((float)((float)(boundingSphere->m_pos.m_y - pArea->m_pos.m_y)
                             * (float)(boundingSphere->m_pos.m_y - pArea->m_pos.m_y))
                     + (float)((float)(boundingSphere->m_pos.m_z - pArea->m_pos.m_z)
                             * (float)(boundingSphere->m_pos.m_z - pArea->m_pos.m_z)))) > (double)(float)((float)(pArea->m_radius + boundingSphere->m_radius) * (float)(pArea->m_radius + boundingSphere->m_radius)) )
    return 0;
  v3 = 0;
  v4 = pArea->m_flags.m_flags1 & 0x7F;
  if ( v4 != 0 )
  {
    v5 = (float *)&v12;
    p_m_dynAreaData = (float *)&pArea[1].m_dynAreaData;
    v3 = pArea->m_flags.m_flags1 & 0x7F;
    do
    {
      --v4;
      v7 = p_m_dynAreaData[1];
      v11 = p_m_dynAreaData[2];
      v10 = *p_m_dynAreaData;
      p_m_dynAreaData += 6;
      v5[2] = v7;
      v5[1] = v10;
      v5 += 3;
      *v5 = v11;
    }
    while ( v4 != 0 );
  }
  v9 = (unsigned __int8)bfx::DoesPolygonIntersectVolume(vertArray: v13, numVerts: v3, planes) != 0;
  result = 1;
  if ( !v9 )
    return 0;
  return result;
}


// ========================================================================
// ?GetClosestPosOnAreaEdge@bfx@@YAXPAVArea@1@ABVVec3@1@AAV31@AAVEdgeCursor@1@@Z
// EA  : 0x832709A0
// RVA : 0x012709A0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

void __fastcall bfx::GetClosestPosOnAreaEdge(
        bfx::Area *pArea,
        const bfx::Vec3 *pos,
        bfx::Vec3 *closestPos,
        bfx::EdgeCursor *closestEdgeCursor)
{
  bfx::Area *v4; // r11
  signed int v5; // r9
  double v6; // fp9
  bfx::Area *v7; // r10
  double m_y; // fp11
  double m_z; // fp6
  double m_x; // fp5
  float *v11; // r7
  int v12; // r8
  float *v13; // r11
  float v14; // r30
  float v15; // r8
  unsigned int v16; // r9
  float v17; // r7
  float v18; // r31
  float v19; // r9
  double v24; // fp0
  double v25; // fp13
  double v26; // fp12
  double v27; // fp1
  bfx::EdgeCursor v28; // [sp+0h] [-50h]
  float v29; // [sp+18h] [-38h]

  v28.m_pArea = pArea;
  v5 = pArea->m_flags.m_flags1 & 0x7F;
  v6 = 3.4028235e38;
  if ( v5 != 0 )
  {
    do
    {
      v7 = (bfx::Area *)((char *)&v4->m_pProxy + 1);
      m_y = pos->m_y;
      m_z = pos->m_z;
      m_x = pos->m_x;
      v11 = (float *)(&pArea[1].m_dynAreaData + 6 * (_DWORD)v4);
      v12 = __ROL4__((char *)&v4->m_pProxy + 1, 1);
      __twllei(v5, 0);
      v14 = *((float *)&pArea[1].m_pSearchParent + 6 * (_DWORD)v4);
      v13 = (float *)((char *)pArea + 24 * (((int)&v4->m_pProxy + 1) % v5));
      v16 = v5 & ~(v12 - 1);
      v15 = *v11;
      v17 = v11[1];
      v18 = v13[16];
      __twlgei(v16, 0xFFFFFFFF);
      v19 = v13[17];
      v29 = v13[15];
      _FP1 = (float)((float)((float)((float)((float)m_x - v15) * (float)(v29 - v15))
                           + (float)((float)((float)((float)m_z - v14) * (float)(v19 - v14))
                                   + (float)((float)((float)m_y - v17) * (float)(v18 - v17))))
                   / (float)((float)((float)((float)(v29 - v15) * (float)(v29 - v15))
                                   + (float)((float)((float)(v19 - v14) * (float)(v19 - v14))
                                           + (float)((float)(v18 - v17) * (float)(v18 - v17))))
                           + (float)1.0842022e-19));
      __asm { fsel      f1, f1, f1, f7 }
      _FP31 = (float)((float)_FP1 - (float)1.0);
      __asm { fsel      f1, f31, f10, f1 }
      v24 = (float)((float)((float)(v18 - v17) * (float)_FP1) + v17);
      v25 = (float)((float)((float)(v19 - v14) * (float)_FP1) + v14);
      v26 = (float)((float)((float)(v29 - v15) * (float)_FP1) + v15);
      v27 = (float)((float)((float)((float)(v18 - v17) * (float)_FP1) + v17) - (float)m_y);
      if ( (float)((float)((float)((float)v26 - (float)m_x) * (float)((float)v26 - (float)m_x))
                 + (float)((float)((float)((float)v25 - (float)m_z) * (float)((float)v25 - (float)m_z))
                         + (float)((float)v27 * (float)v27))) < v6 )
      {
        v7 = pArea;
        closestPos->m_x = v26;
        closestPos->m_y = v24;
        v6 = (float)((float)((float)((float)v26 - (float)m_x) * (float)((float)v26 - (float)m_x))
                   + (float)((float)((float)((float)v25 - (float)m_z) * (float)((float)v25 - (float)m_z))
                           + (float)((float)v27 * (float)v27)));
        closestPos->m_z = v25;
        *closestEdgeCursor = v28;
      }
      v4 = v7;
      v28.m_i = (int)v7;
      v5 = pArea->m_flags.m_flags1 & 0x7F;
    }
    while ( (int)v7 < v5 );
  }
}


// ========================================================================
// ?IsAdjEdgeBetter@bfx@@YA_NABVVec3@1@00ABVEdgeCursor@1@MM@Z
// EA  : 0x83270B58
// RVA : 0x01270B58
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

int __fastcall bfx::IsAdjEdgeBetter(
        const bfx::Vec3 *lineStart,
        const bfx::Vec3 *lineDelta,
        const bfx::Vec3 *N,
        const bfx::EdgeCursor *adjEdge,
        double curInwardsDot,
        double curDist)
{
  bfx::Area *m_pArea; // r11
  double m_x; // fp11
  int m_i; // r10
  double m_y; // fp10
  double m_z; // fp9
  double v12; // fp8
  double v13; // fp7
  double v14; // fp6
  signed int v15; // r6
  float *v17; // r9
  float v18; // r4
  float *v19; // r11
  float v20; // r3
  double v21; // fp4
  float v22; // r8
  float v23; // r7
  float v24; // r6
  double v25; // fp4
  double v26; // fp2
  double v27; // fp5
  double v28; // fp3
  int result; // r3
  bfx::Vec3 v32; // [sp+50h] [-60h] BYREF
  bfx::Vec3 v33; // [sp+60h] [-50h] BYREF
  bfx::Vec3 v34; // [sp+70h] [-40h] BYREF

  m_pArea = adjEdge->m_pArea;
  m_x = N->m_x;
  m_i = adjEdge->m_i;
  m_y = N->m_y;
  m_z = N->m_z;
  v12 = lineDelta->m_y;
  v13 = lineDelta->m_z;
  v14 = lineDelta->m_x;
  v17 = (float *)((char *)adjEdge->m_pArea + 24 * m_i);
  v15 = adjEdge->m_pArea->m_flags.m_flags1 & 0x7F;
  v18 = v17[15];
  v19 = (float *)((char *)m_pArea + 24 * ((m_i + 1) % v15));
  v20 = v17[17];
  v33.m_y = v17[16];
  v33.m_x = v18;
  v21 = v33.m_y;
  __twllei(v15, 0);
  v22 = v19[15];
  v23 = v19[16];
  __twlgei(v15 & ~(__ROL4__(m_i + 1, 1) - 1), 0xFFFFFFFF);
  v24 = v19[17];
  v33.m_z = v20;
  v32.m_x = v22;
  v32.m_y = v23;
  v32.m_z = v24;
  v25 = (float)(v23 - (float)v21);
  v26 = (float)((float)((float)m_z * (float)(v22 - v18)) - (float)((float)m_x * (float)(v24 - v20)));
  v27 = (float)((float)((float)m_x * (float)v25) - (float)((float)m_y * (float)(v22 - v18)));
  v28 = (float)((float)((float)m_y * (float)(v24 - v20)) - (float)((float)m_z * (float)v25));
  _FP4 = (float)((float)__fsqrts((float)((float)((float)v28 * (float)v28)
                                       + (float)((float)((float)v27 * (float)v27) + (float)((float)v26 * (float)v26))))
               - (float)1.0842022e-19);
  __asm { fsel      f13, f4, f0, f12 }
  if ( (float)((float)((float)v14 * (float)((float)v28 * (float)_FP13))
             + (float)((float)((float)v13 * (float)((float)v27 * (float)_FP13))
                     + (float)((float)v12
                             * (float)((float)((float)((float)m_z * (float)(v22 - v18))
                                             - (float)((float)m_x * (float)(v24 - v20)))
                                     * (float)_FP13)))) >= curInwardsDot )
    return 0;
  bfx::GetClosestPtOnLineSeg(result: &v34, start: &v33, end: &v32, pos: lineStart);
  result = 1;
  if ( __fsqrts((float)((float)((float)(v34.m_x - lineStart->m_x) * (float)(v34.m_x - lineStart->m_x))
                      + (float)((float)((float)(v34.m_z - lineStart->m_z) * (float)(v34.m_z - lineStart->m_z))
                              + (float)((float)(v34.m_y - lineStart->m_y) * (float)(v34.m_y - lineStart->m_y))))) > (float)((float)curDist + (float)0.000001) )
    return 0;
  return result;
}


// ========================================================================
// ?CheckForBetterAdjacentEdge@bfx@@YAXABVVec3@1@000AAVEdgeCursor@1@@Z
// EA  : 0x83270D38
// RVA : 0x01270D38
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

void __fastcall bfx::CheckForBetterAdjacentEdge(
        const bfx::Vec3 *lineStart,
        const bfx::Vec3 *lineDelta,
        const bfx::Vec3 *N,
        const bfx::Vec3 *endPos,
        bfx::Vec3 *exitEdgeCursor)
{
  double m_z; // fp11
  double m_y; // fp10
  double m_x; // fp9
  double v13; // fp0
  double v14; // fp12
  double v15; // fp13
  bfx::EdgeCursor v16; // r11
  double v17; // fp2
  double v18; // fp4
  double v19; // fp3
  int m_y_low; // r7
  double v22; // fp5
  double v24; // fp31
  double v25; // fp30
  bfx::EdgeCursor v26; // [sp+50h] [-50h] BYREF
  float v27; // [sp+58h] [-48h]

  bfx::EdgeCursor::GetEdgeVec(this: &v26, result: exitEdgeCursor);
  m_z = lineDelta->m_z;
  m_y = lineDelta->m_y;
  m_x = lineDelta->m_x;
  v13 = (float)((float)(N->m_x * *(float *)&v26.m_i) - (float)(N->m_y * *(float *)&v26.m_pArea));
  v14 = (float)((float)(N->m_y * v27) - (float)(N->m_z * *(float *)&v26.m_i));
  v15 = (float)((float)(N->m_z * *(float *)&v26.m_pArea) - (float)(N->m_x * v27));
  if ( (float)((float)(lineDelta->m_x * (float)((float)(N->m_y * v27) - (float)(N->m_z * *(float *)&v26.m_i)))
             + (float)((float)(lineDelta->m_y * (float)((float)(N->m_z * *(float *)&v26.m_pArea) - (float)(N->m_x * v27)))
                     + (float)(lineDelta->m_z
                             * (float)((float)(N->m_x * *(float *)&v26.m_i) - (float)(N->m_y * *(float *)&v26.m_pArea))))) >= 0.0 )
  {
    v16 = *(bfx::EdgeCursor *)&exitEdgeCursor->m_x;
    v17 = (float)(endPos->m_y - lineStart->m_y);
    v16.m_pArea = (bfx::Area *)&unk_82410000;
    v18 = (float)(endPos->m_z - lineStart->m_z);
    v19 = endPos->m_x;
    m_y_low = LODWORD(exitEdgeCursor->m_y);
    v26 = v16;
    _FP7 = (float)((float)__fsqrts((float)((float)((float)v14 * (float)v14)
                                         + (float)((float)((float)v13 * (float)v13) + (float)((float)v15 * (float)v15))))
                 - (float)1.0842022e-19);
    v22 = (float)((float)((float)((float)v19 - lineStart->m_x) * (float)((float)v19 - lineStart->m_x))
                + (float)((float)((float)v18 * (float)v18) + (float)((float)v17 * (float)v17)));
    v26.m_i = (((unsigned int)(m_y_low + 1) - __PAIR64__((unsigned int)(m_y_low + 1) >> 31, 16)) >> 32) & (m_y_low + 1);
    __asm { fsel      f4, f7, f6, f8 }
    v24 = __fsqrts(v22);
    v25 = (float)((float)((float)m_x * (float)((float)v14 * (float)_FP4))
                + (float)((float)((float)m_y * (float)((float)v15 * (float)_FP4))
                        + (float)((float)m_z * (float)((float)v13 * (float)_FP4))));
    if ( (unsigned __int8)bfx::IsAdjEdgeBetter(lineStart, lineDelta, N, adjEdge: &v26, curInwardsDot: v25, curDist: v24) != 0 )
      goto LABEL_6;
    v26 = *(bfx::EdgeCursor *)&exitEdgeCursor->m_x;
    if ( --v26.m_i < 0 )
      v26.m_i = (v26.m_pArea->m_flags.m_flags1 & 0x7F) - 1;
    if ( (unsigned __int8)bfx::IsAdjEdgeBetter(lineStart, lineDelta, N, adjEdge: &v26, curInwardsDot: v25, curDist: v24) != 0 )
LABEL_6:
      *(bfx::EdgeCursor *)&exitEdgeCursor->m_x = v26;
  }
}


// ========================================================================
// ?MoveThroughArea@bfx@@YA_NABVVec3@1@0PAVArea@1@0AAV21@AAVEdgeCursor@1@@Z
// EA  : 0x83270F08
// RVA : 0x01270F08
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

int __fastcall bfx::MoveThroughArea(
        const bfx::Vec3 *origLineStart,
        const bfx::Vec3 *origLineDelta,
        bfx::Area *pArea,
        const bfx::Vec3 *areaNormal,
        bfx::Vec3 *endPos,
        bfx::EdgeCursor *exitEdgeCursor)
{
  float m_z; // r9
  double m_y; // fp13
  float m_x; // r7
  double v11; // fp11
  float v12; // r8
  double v13; // fp12
  double v14; // fp30
  double v15; // fp29
  float v16; // r6
  double v17; // fp9
  double v18; // fp5
  double v20; // fp10
  double v22; // fp31
  double v23; // fp2
  double v24; // fp1
  double v25; // fp8
  double v26; // fp28
  double v27; // fp27
  double v28; // fp26
  double v29; // fp25
  double v30; // fp24
  double v31; // fp23
  double v32; // fp21
  double v33; // fp20
  double v34; // fp19
  char v35; // r11
  char v36; // r11
  double v37; // fp22
  double v38; // fp18
  bool v39; // r29
  bool v40; // r30
  double Scale; // fp1
  bfx::Area *v42; // r8
  signed int v43; // r11
  int v44; // r6
  double v45; // fp6
  int v46; // r5
  bfx::Area *v47; // r10
  float *v48; // r11
  float v49; // r4
  float v50; // r3
  double v51; // fp13
  bool v52; // r11
  bool v53; // r9
  float *v54; // r11
  float v55; // r7
  float v56; // r4
  double v57; // fp1
  double v58; // fp13
  double v59; // fp12
  double v60; // fp0
  bfx::EdgeCursor v62; // [sp+50h] [-100h]
  float v63; // [sp+54h] [-FCh]
  bfx::Vec3 v64; // [sp+60h] [-F0h] BYREF
  float v65; // [sp+70h] [-E0h]
  float v66; // [sp+74h] [-DCh]
  float v67; // [sp+78h] [-D8h]
  float v68; // [sp+80h] [-D0h]
  float v69; // [sp+84h] [-CCh]
  float v70; // [sp+88h] [-C8h]
  bfx::Vec3 v71; // [sp+90h] [-C0h] BYREF

  m_z = pArea->m_pos.m_z;
  m_y = origLineDelta->m_y;
  m_x = pArea->m_pos.m_x;
  v11 = origLineStart->m_y;
  v12 = areaNormal->m_z;
  v13 = origLineDelta->m_x;
  v63 = pArea->m_pos.m_y;
  v64.m_x = areaNormal->m_x;
  v14 = v64.m_x;
  v64.m_z = v12;
  v15 = v12;
  v16 = areaNormal->m_y;
  v17 = origLineStart->m_z;
  v18 = origLineStart->m_x;
  v20 = origLineDelta->m_z;
  v22 = v16;
  v23 = (float)(v16
              * (float)((float)(origLineDelta->m_z * v12)
                      + (float)((float)((float)v13 * v64.m_x) + (float)((float)m_y * v16))));
  v24 = (float)(v12
              * (float)((float)(origLineDelta->m_z * v12)
                      + (float)((float)((float)v13 * v64.m_x) + (float)((float)m_y * v16))));
  v25 = (float)((float)((float)(origLineStart->m_x - m_x) * v64.m_x)
              + (float)((float)(v12 * (float)(origLineStart->m_z - m_z)) + (float)(v16 * (float)((float)v11 - v63))));
  v26 = (float)((float)v13
              - (float)((float)((float)(origLineDelta->m_z * v12)
                              + (float)((float)((float)v13 * v64.m_x) + (float)((float)m_y * v16)))
                      * v64.m_x));
  v71.m_x = (float)v13
          - (float)((float)((float)(origLineDelta->m_z * v12)
                          + (float)((float)((float)v13 * v64.m_x) + (float)((float)m_y * v16)))
                  * v64.m_x);
  v64.m_y = v16;
  v27 = (float)((float)m_y - (float)v23);
  v71.m_y = (float)m_y - (float)v23;
  v28 = (float)((float)v20 - (float)v24);
  v71.m_z = (float)v20 - (float)v24;
  v29 = (float)((float)v18 - (float)((float)v25 * v64.m_x));
  v30 = (float)((float)v11 - (float)(v16 * (float)v25));
  v31 = (float)((float)v17 - (float)(v12 * (float)v25));
  v32 = (float)((float)(v71.m_y * v64.m_x) - (float)(v16 * (float)v26));
  v33 = (float)((float)(v71.m_z * v16) - (float)(v71.m_y * v12));
  v34 = (float)((float)(v12 * (float)v26) - (float)(v71.m_z * v64.m_x));
  if ( v26 != 0.0 || v27 != 0.0 || (v35 = 1, v28 != 0.0) )
    v35 = 0;
  if ( v35 == 0 )
  {
    if ( v33 != 0.0 || v34 != 0.0 || (v36 = 1, v32 != 0.0) )
      v36 = 0;
    if ( v36 == 0 )
    {
      v37 = 3.4028235e38;
      v38 = (float)((float)((float)((float)(v71.m_z * v16) - (float)(v71.m_y * v12))
                          * (float)((float)v18 - (float)((float)v25 * v64.m_x)))
                  + (float)((float)((float)((float)((float)((float)m_y - (float)v23) * v64.m_x)
                                          - (float)(v16 * (float)v26))
                                  * (float)((float)v17 - (float)(v12 * (float)v25)))
                          + (float)((float)((float)(v12 * (float)v26) - (float)(v71.m_z * v64.m_x))
                                  * (float)((float)v11 - (float)(v16 * (float)v25)))));
      v39 = (float)((float)((float)((float)(v71.m_z * v16) - (float)(v71.m_y * v12))
                          * *(float *)&pArea[1].m_dynAreaData.m_data)
                  + (float)((float)(*(float *)&pArea[1].m_pSearchParent
                                  * (float)((float)((float)((float)m_y - (float)v23) * v64.m_x)
                                          - (float)(v16 * (float)v26)))
                          + (float)(*(float *)&pArea[1].m_pFirstLink
                                  * (float)((float)(v12 * (float)v26) - (float)(v71.m_z * v64.m_x))))) < v38;
      v40 = v39;
      Scale = bfx::GetScale();
      v42 = nullptr;
      v62.m_pArea = pArea;
      v43 = pArea->m_flags.m_flags1 & 0x7F;
      v62.m_i = 0;
      v44 = 0;
      v45 = (float)((float)Scale * (float)0.0099999998);
      if ( v43 != 0 )
      {
        v46 = v43 - 1;
        do
        {
          v47 = (bfx::Area *)((char *)&v42->m_pProxy + 1);
          __twllei(v43, 0);
          __twlgei(v43 & ~(__ROL4__((char *)&v42->m_pProxy + 1, 1) - 1), 0xFFFFFFFF);
          v48 = (float *)((char *)pArea + 24 * (((int)&v42->m_pProxy + 1) % v43));
          v49 = v48[16];
          v50 = v48[17];
          v65 = v48[15];
          v66 = v49;
          v51 = v49;
          v67 = v50;
          if ( v44 == v46 )
            v52 = v39;
          else
            v52 = (float)((float)(v65 * (float)v33) + (float)((float)(v50 * (float)v32) + (float)(v49 * (float)v34))) < v38;
          v53 = v52;
          if ( v40 && !v52 )
          {
            v54 = (float *)((char *)pArea + 24 * (_DWORD)v42);
            v55 = v54[16];
            v56 = v54[17];
            v68 = v54[15];
            v69 = v55;
            v70 = v56;
            v57 = (float)((float)((float)v51 - v55) * (float)v15);
            v59 = (float)((float)((float)(v50 - v56) * (float)v22) - (float)((float)((float)v51 - v55) * (float)v15));
            v58 = (float)((float)((float)((float)v51 - v55) * (float)v14) - (float)((float)v22 * (float)(v65 - v68)));
            if ( (float)((float)((float)((float)((float)(v50 - v56) * (float)v22) - (float)v57) * (float)v26)
                       + (float)((float)((float)v58 * (float)v28)
                               + (float)((float)((float)((float)v15 * (float)(v65 - v68))
                                               - (float)((float)(v50 - v56) * (float)v14))
                                       * (float)v27))) < -1.0842022e-19 )
            {
              v60 = (float)((float)((float)((float)(v68 - (float)v29) * (float)v59)
                                  + (float)((float)((float)(v56 - (float)v31) * (float)v58)
                                          + (float)((float)(v55 - (float)v30)
                                                  * (float)((float)((float)v15 * (float)(v65 - v68))
                                                          - (float)((float)(v50 - v56) * (float)v14)))))
                          / (float)((float)((float)((float)((float)(v50 - v56) * (float)v22) - (float)v57) * (float)v26)
                                  + (float)((float)((float)v58 * (float)v28)
                                          + (float)((float)((float)((float)v15 * (float)(v65 - v68))
                                                          - (float)((float)(v50 - v56) * (float)v14))
                                                  * (float)v27))));
              if ( v60 > -v45 && v60 < v37 )
              {
                v47 = pArea;
                v37 = (float)((float)((float)((float)(v68 - (float)v29) * (float)v59)
                                    + (float)((float)((float)(v56 - (float)v31) * (float)v58)
                                            + (float)((float)(v55 - (float)v30)
                                                    * (float)((float)((float)v15 * (float)(v65 - v68))
                                                            - (float)((float)(v50 - v56) * (float)v14)))))
                            / (float)((float)((float)((float)((float)(v50 - v56) * (float)v22) - (float)v57) * (float)v26)
                                    + (float)((float)((float)v58 * (float)v28)
                                            + (float)((float)((float)((float)v15 * (float)(v65 - v68))
                                                            - (float)((float)(v50 - v56) * (float)v14))
                                                    * (float)v27))));
                endPos->m_x = (float)((float)v26
                                    * (float)((float)((float)((float)(v68 - (float)v29) * (float)v59)
                                                    + (float)((float)((float)(v56 - (float)v31) * (float)v58)
                                                            + (float)((float)(v55 - (float)v30)
                                                                    * (float)((float)((float)v15 * (float)(v65 - v68))
                                                                            - (float)((float)(v50 - v56) * (float)v14)))))
                                            / (float)((float)((float)((float)((float)(v50 - v56) * (float)v22)
                                                                    - (float)v57)
                                                            * (float)v26)
                                                    + (float)((float)((float)v58 * (float)v28)
                                                            + (float)((float)((float)((float)v15 * (float)(v65 - v68))
                                                                            - (float)((float)(v50 - v56) * (float)v14))
                                                                    * (float)v27)))))
                            + (float)v29;
                endPos->m_y = (float)((float)v27 * (float)v60) + (float)v30;
                endPos->m_z = (float)((float)v28 * (float)v60) + (float)v31;
                *exitEdgeCursor = v62;
              }
            }
          }
          v42 = v47;
          v40 = v53;
          v62.m_i = (int)v47;
          v43 = pArea->m_flags.m_flags1 & 0x7F;
          ++v44;
        }
        while ( (int)v47 < v43 );
        if ( v37 <= 1.0 )
          return 1;
        if ( v37 < 3.4028235e38 )
        {
          endPos->m_x = (float)v26 + (float)v29;
          endPos->m_y = (float)v27 + (float)v30;
          endPos->m_z = (float)v28 + (float)v31;
          return 0;
        }
      }
      bfx::GetClosestPosOnAreaEdge(pArea, pos: origLineStart, closestPos: endPos, closestEdgeCursor: exitEdgeCursor);
      if ( exitEdgeCursor->m_pArea != nullptr )
      {
        bfx::CheckForBetterAdjacentEdge(
          lineStart: origLineStart,
          lineDelta: &v71,
          N: &v64,
          endPos,
          (bfx::Vec3 *)exitEdgeCursor);
        return 1;
      }
    }
  }
  endPos->m_z = v31;
  endPos->m_y = v30;
  endPos->m_x = v29;
  return 0;
}


// ========================================================================
// ?Draw@Area@bfx@@QBAXPBVSpace@2@ABVColor@2@@Z
// EA  : 0x83271340
// RVA : 0x01271340
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

void __fastcall bfx::Area::Draw(bfx::Area *this, bfx::Space *pSpace, const bfx::Color *color)
{
  float m_g; // r8
  float m_b; // r6
  signed int v8; // r30
  signed int v9; // r11
  bfx::InstanceComponent_vtbl *v10; // r25
  float *v11; // r31
  float *p_m_a; // r29
  float v13; // r10
  float v14; // r8
  float *v15; // r11
  double v16; // fp30
  double v17; // fp29
  float v18; // r9
  float v19; // r8
  float v20; // r10
  unsigned int m_flags1; // r7
  int v22; // r31
  const bfx::Vec3 *v23; // r5
  const bfx::Vec3 *v24; // r30
  float v25; // [sp+60h] [-690h]
  float v26; // [sp+64h] [-68Ch]
  float v27; // [sp+68h] [-688h]
  bfx::Vec3 v28; // [sp+70h] [-680h] BYREF
  float v29; // [sp+7Ch] [-674h]
  float v30; // [sp+80h] [-670h]
  float v31; // [sp+84h] [-66Ch]
  bfx::Color v32; // [sp+90h] [-660h] BYREF
  bfx::Vec3 v33; // [sp+A0h] [-650h] BYREF
  char v34; // [sp+ACh] [-644h] BYREF

  m_g = color->m_g;
  m_b = color->m_b;
  v8 = 0;
  v9 = this->m_flags.m_flags1 & 0x7F;
  v10 = bfx::g_pCurInstance->m_pComponentManager->m_components[1][9].__vftable;
  v32.m_r = color->m_r;
  v32.m_g = m_g;
  v32.m_b = m_b;
  v32.m_a = 0.25;
  if ( v9 != 0 )
  {
    v11 = (float *)((char *)this + 60);
    p_m_a = &v32.m_a;
    do
    {
      ++v8;
      v13 = v11[1];
      v14 = v11[2];
      __twllei(v9, 0);
      v26 = v13;
      v27 = v14;
      v25 = *v11;
      __twlgei(v9 & ~(__ROL4__(v8, 1) - 1), 0xFFFFFFFF);
      v15 = (float *)((char *)this + 24 * (v8 % v9));
      v16 = v13;
      v17 = v14;
      v18 = v15[15];
      v19 = v15[16];
      v20 = v15[17];
      v28.m_x = v25;
      v28.m_y = v26;
      v28.m_z = v27;
      v31 = v20;
      v30 = v19;
      v29 = v18;
      bfx::DrawLineList(pSpace, pVerts: &v28, numVerts: 2, color);
      m_flags1 = this->m_flags.m_flags1;
      p_m_a[1] = v25;
      v11 += 6;
      v9 = m_flags1 & 0x7F;
      p_m_a[2] = v16;
      p_m_a += 3;
      *p_m_a = v17;
    }
    while ( v8 < v9 );
  }
  if ( BYTE1(v10->dtr_InstanceComponent) != 0 )
  {
    v22 = v9 - 2;
    if ( v9 - 2 > 0 )
    {
      v23 = (const bfx::Vec3 *)&v34;
      do
      {
        v24 = v23 + 1;
        bfx::DrawSolidTri((bfx::Vector3 *)pSpace, v0: &v33, v1: v23, v2: v23 + 1, color: &v32);
        --v22;
        v23 = v24;
      }
      while ( v22 != 0 );
    }
  }
}


// ========================================================================
// ?BuildDynAreaData@Area@bfx@@QAAXABV?$Array@PAVDFace@bfx@@@2@@Z
// EA  : 0x832714E8
// RVA : 0x012714E8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

void __fastcall bfx::Area::BuildDynAreaData(bfx::Area *this, const bfx::Array<bfx::DFace *> *faces)
{
  signed int v4; // r11
  unsigned int *p_m_searchCost; // r10

  if ( this->m_pProxy != nullptr )
    this->m_pProxy->m_pArea = nullptr;
  bfx::DynAreaData::Clear(this: &this->m_dynAreaData);
  this->m_pProxy = nullptr;
  v4 = 0;
  if ( (this->m_flags.m_flags1 & 0x7F) != 0 )
  {
    p_m_searchCost = &this->m_searchCost;
    do
    {
      p_m_searchCost += 6;
      *p_m_searchCost = 0;
      ++v4;
    }
    while ( v4 < (signed int)(this->m_flags.m_flags1 & 0x7F) );
  }
  bfx::DynAreaData::Set(this: &this->m_dynAreaData, pStaticArea: this, faces);
}


// ========================================================================
// ?DoesEdgeIntersectVolume@bfx@@YA_NABVEdgeCursor@1@ABV?$Array@VPlane@bfx@@@1@ABVSphere@1@@Z
// EA  : 0x83271568
// RVA : 0x01271568
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

BOOL __fastcall bfx::DoesEdgeIntersectVolume(
        const bfx::EdgeCursor *edge,
        const bfx::Array<bfx::Plane> *planes,
        const bfx::Sphere *boundingSphere)
{
  bfx::Area *m_pArea; // r10
  int m_i; // r11
  signed int v6; // r6
  float *v7; // r7
  unsigned int v8; // r9
  int v9; // r11
  float v10; // r8
  float v11; // r6
  float *v12; // r11
  float v13; // r9
  float v15; // r7
  float v16; // r10
  float v17; // r11
  bfx::Vec3 v19; // [sp+50h] [-70h] BYREF
  bfx::LineSeg v20; // [sp+60h] [-60h] BYREF
  bfx::Vec3 v21; // [sp+80h] [-40h] BYREF
  float m_x; // [sp+8Ch] [-34h]
  float m_y; // [sp+90h] [-30h]
  float m_z; // [sp+94h] [-2Ch]

  m_pArea = edge->m_pArea;
  m_i = edge->m_i;
  v6 = edge->m_pArea->m_flags.m_flags1 & 0x7F;
  v7 = (float *)(&edge->m_pArea[1].m_dynAreaData + 6 * m_i);
  v8 = v6 & ~(__ROL4__(m_i + 1, 1) - 1);
  v9 = 24 * ((m_i + 1) % v6);
  v10 = *v7;
  __twllei(v6, 0);
  v11 = v7[1];
  v12 = (float *)((char *)m_pArea + v9);
  __twlgei(v8, 0xFFFFFFFF);
  v13 = v7[2];
  v15 = v12[15];
  v16 = v12[16];
  v17 = v12[17];
  v20.m_v0.m_x = v10;
  v20.m_v0.m_y = v11;
  v20.m_v0.m_z = v13;
  v20.m_v1.m_x = v15;
  v20.m_v1.m_y = v16;
  v20.m_v1.m_z = v17;
  bfx::GetClosestPtOnLineSeg(result: &v19, seg: &v20, pos: &boundingSphere->m_pos);
  if ( (float)((float)((float)(v19.m_x - boundingSphere->m_pos.m_x) * (float)(v19.m_x - boundingSphere->m_pos.m_x))
             + (float)((float)((float)(v19.m_z - boundingSphere->m_pos.m_z)
                             * (float)(v19.m_z - boundingSphere->m_pos.m_z))
                     + (float)((float)(v19.m_y - boundingSphere->m_pos.m_y)
                             * (float)(v19.m_y - boundingSphere->m_pos.m_y)))) > (double)(float)(boundingSphere->m_radius
                                                                                               * boundingSphere->m_radius) )
    return false;
  v21.m_x = v20.m_v0.m_x;
  v21.m_y = v20.m_v0.m_y;
  v21.m_z = v20.m_v0.m_z;
  m_x = v20.m_v1.m_x;
  m_y = v20.m_v1.m_y;
  m_z = v20.m_v1.m_z;
  return (unsigned __int8)bfx::DoesPolygonIntersectVolume(vertArray: &v21, numVerts: 2, planes) != 0;
}


// ========================================================================
// ?EndianSwap@Area@bfx@@QAAXXZ
// EA  : 0x83271798
// RVA : 0x01271798
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

void __fastcall bfx::Area::EndianSwap(bfx::Area *this)
{
  bfx::AreaFlags *p_m_flags; // r30
  int v3; // r29
  unsigned int *v4; // r31
  unsigned int v5; // [sp+50h] [-30h]

  bfx::EndianSwapVec3(vec: &this->m_pos);
  bfx::EndianSwapFloat(val: &this->m_radius);
  bfx::EndianSwapLong(val: &this->m_searchCost);
  bfx::EndianSwapLong(val: &this->m_usageFlags);
  p_m_flags = &this->m_flags;
  bfx::EndianSwapLong(val: &this->m_flags.m_flags1);
  bfx::EndianSwapLong(val: &this->m_flags.m_flags2);
  bfx::EndianSwapLong(val: &this->m_flags.m_flags3);
  bfx::EndianSwapLong(val: &this->m_flags.m_flags4);
  v3 = 0;
  if ( (this->m_flags.m_flags1 & 0x7F) != 0 )
  {
    v4 = (unsigned int *)((char *)this + 72);
    do
    {
      BYTE1(v5) = BYTE2(*(v4 - 4));
      HIBYTE(v5) = *(v4 - 4);
      LOBYTE(v5) = HIBYTE(*(v4 - 4));
      BYTE2(v5) = BYTE1(*(v4 - 4));
      *(v4 - 4) = v5;
      bfx::EndianSwapVec3(vec: (bfx::Vec3 *)v4 - 1);
      bfx::EndianSwapLong(val: v4);
      bfx::EndianSwapLong(val: v4 + 1);
      ++v3;
      v4 += 6;
    }
    while ( v3 < (signed int)(p_m_flags->m_flags1 & 0x7F) );
  }
}


// ========================================================================
// ??0Area@bfx@@QAA@ABVVec3@1@MH_NHIHIH@Z
// EA  : 0x83271870
// RVA : 0x01271870
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

bfx::Area *__fastcall bfx::Area::Area(
        bfx::Area *this,
        const bfx::Vec3 *pos,
        double radius,
        int numEdges,
        bool full3D,
        char island,
        unsigned int layerIndex,
        int graphIndex,
        unsigned int usageFlags,
        int basisVert,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        unsigned int a29,
        int a30,
        int a31)
{
  unsigned int v31; // r10
  bool v32; // cr58
  float m_z; // r7

  this->m_pProxy = nullptr;
  this->m_dynAreaData.m_data = nullptr;
  this->m_pFirstLink = nullptr;
  v31 = (usageFlags << 16) & 0x7FF0000;
  this->m_pos.m_x = pos->m_x;
  v32 = island == 0;
  this->m_pos.m_y = pos->m_y;
  m_z = pos->m_z;
  this->m_radius = radius;
  this->m_pos.m_z = m_z;
  this->m_searchCost = -1;
  this->m_usageFlags = a29;
  this->m_flags.m_flags2 = 0;
  this->m_flags.m_flags1 = (layerIndex << 7) & 0xFFFF80 | full3D & 0x7F;
  this->m_flags.m_flags4 = graphIndex << 27;
  this->m_flags.m_flags3 = v31;
  if ( !v32 )
    v31 |= 0x80000000;
  this->m_flags.m_flags3 = v31;
  this->m_flags.m_flags2 = (a31 << 24) & 0x7F000000 | 0x110000;
  return this;
}


// ========================================================================
// ?RayCastThroughAreas@bfx@@YAXPAVArea@1@ABVVec3@1@1MABVPathSpec@1@AAVRayCastData@1@PAV?$Array@VPathSeg@bfx@@@1@@Z
// EA  : 0x83271910
// RVA : 0x01271910
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

void __fastcall bfx::RayCastThroughAreas(
        bfx::Vec3 *pStartArea,
        const bfx::Vec3 *origStartPos,
        const bfx::Vec3 *dir,
        double dist,
        const bfx::PathSpec *pathSpec,
        const bfx::PathSpec *rayCastData,
        bfx::Array<bfx::PathSeg> *pPathOut,
        bfx::Array<bfx::Path3DPoint> *a8)
{
  double m_z; // fp10
  double v15; // fp0
  double m_x; // fp8
  double v17; // fp13
  double m_y; // fp7
  double v19; // fp12
  bfx::Vec3 *v20; // r26
  double v21; // fp22
  double v22; // fp25
  double v23; // fp6
  double v24; // fp21
  bfx::Vec3 *v25; // r21
  double v26; // fp1
  double v27; // fp0
  double v28; // fp13
  double v31; // fp31
  double v32; // fp30
  double v33; // fp29
  char v34; // r31
  double v35; // fp27
  int m_i; // r28
  double v37; // fp26
  double v38; // fp25
  bfx::Area *m_pArea; // r29
  char *v40; // r31
  double v41; // fp8
  double v42; // fp28
  bfx::Vec3 *v43; // r30
  double v44; // fp0
  signed int v45; // r7
  float v46; // r6
  float v47; // r5
  double v48; // fp31
  double v49; // fp30
  double v50; // fp29
  float *v51; // r11
  float v52; // r6
  float v53; // r5
  double v56; // fp28
  double v57; // fp27
  double v58; // fp26
  double v59; // fp0
  double v60; // fp12
  double v61; // fp9
  double v62; // fp8
  double v63; // fp13
  double v64; // fp12
  double v65; // fp11
  double v66; // fp10
  bfx::EdgeCursor v67; // [sp+50h] [-170h] BYREF
  bfx::Vec3 v68; // [sp+58h] [-168h] BYREF
  bfx::Vec3 v69; // [sp+68h] [-158h] BYREF
  bfx::Vec3 v70; // [sp+78h] [-148h] BYREF
  float v71; // [sp+88h] [-138h]
  float v72; // [sp+8Ch] [-134h]
  float v73; // [sp+90h] [-130h]
  bfx::Vec3 v74; // [sp+98h] [-128h] BYREF
  bfx::Area v75; // [sp+A8h] [-118h] BYREF
  bfx::Vec3 v76; // [sp+E0h] [-E0h]
  bfx::Vec3 *v77; // [sp+ECh] [-D4h]
  int v78; // [sp+F0h] [-D0h]

  bfx::GetClosestPosInArea(result: &v74, pArea: pStartArea, pos: origStartPos, pEdgeIndexOut: nullptr);
  bfx::Area::CalcNormal(this: &v75, result: pStartArea);
  m_z = dir->m_z;
  v15 = *(float *)&v75.m_pFirstLink;
  m_x = dir->m_x;
  v17 = *(float *)&v75.m_pProxy;
  m_y = dir->m_y;
  v19 = *(float *)&v75.m_dynAreaData.m_data;
  v20 = pStartArea;
  v21 = v74.m_x;
  v22 = v74.m_y;
  v23 = (float)((float)(dir->m_x * *(float *)&v75.m_pProxy) + (float)(dir->m_z * *(float *)&v75.m_pFirstLink));
  v68 = v74;
  v24 = v74.m_z;
  v25 = nullptr;
  *(float *)&pPathOut[1].m_cap = 0.0;
  v26 = (float)((float)m_y - (float)((float)v19 * (float)((float)((float)m_y * (float)v19) + (float)v23)));
  v27 = (float)((float)m_z - (float)((float)v15 * (float)((float)((float)m_y * (float)v19) + (float)v23)));
  v28 = (float)((float)m_x - (float)((float)((float)((float)m_y * (float)v19) + (float)v23) * (float)v17));
  _FP7 = (float)((float)__fsqrts((float)((float)((float)v28 * (float)v28)
                                       + (float)((float)((float)v27 * (float)v27) + (float)((float)v26 * (float)v26))))
               - (float)1.0842022e-19);
  __asm { fsel      f5, f7, f6, f24 }
  v31 = (float)((float)((float)v28 * (float)_FP5) * (float)dist);
  v32 = (float)((float)((float)v26 * (float)_FP5) * (float)dist);
  v33 = (float)((float)((float)v27 * (float)_FP5) * (float)dist);
  while ( 1 )
  {
    v69.m_x = v31;
    v69.m_y = v32;
    v69.m_z = v33;
    bfx::Area::CalcNormal(this: &v75, result: v20);
    v67.m_pArea = nullptr;
    v67.m_i = -1;
    v34 = bfx::MoveThroughArea(
            origLineStart: &v68,
            origLineDelta: &v69,
            pArea: (bfx::Area *)v20,
            areaNormal: (const bfx::Vec3 *)&v75,
            endPos: &v70,
            exitEdgeCursor: &v67);
    if ( a8 != nullptr )
    {
      v75.m_flags.m_flags1 = 0;
      v76 = v70;
      *(bfx::Vec3 *)&v75.m_flags.m_flags2 = v68;
      v77 = v20;
      v78 = 0;
      bfx::Array<bfx::Path3DPoint>::push_back(this: a8, val: (const bfx::Path3DPoint *)&v75.m_flags);
    }
    if ( v34 == 0 )
      break;
    v35 = v70.m_y;
    m_i = v67.m_i;
    v37 = v70.m_z;
    m_pArea = v67.m_pArea;
    v40 = (char *)v67.m_pArea + 24 * v67.m_i;
    v41 = (float)((float)((float)(v70.m_x - (float)v21) * (float)(v70.m_x - (float)v21))
                + (float)((float)((float)(v70.m_z - (float)v24) * (float)(v70.m_z - (float)v24))
                        + (float)((float)(v70.m_y - (float)v22) * (float)(v70.m_y - (float)v22))));
    v38 = v70.m_x;
    v42 = __fsqrts(v41);
    *(float *)&pPathOut[1].m_cap = *(float *)&pPathOut[1].m_cap + (float)v42;
    v43 = *((bfx::Vec3 **)v40 + 14);
    if ( v43 == nullptr
      || (unsigned __int8)bfx::IsUsableArea(pArea: *((bfx::Area **)v40 + 14), pathSpec: rayCastData) == 0
      || v43 == v25 )
    {
      *(float *)&pPathOut->m_data = v38;
      *(float *)&pPathOut->m_size = v35;
      pPathOut[1].m_size = m_i;
      *(float *)&pPathOut->m_cap = v37;
      HIBYTE(pPathOut[1].m_data) = 1;
      pPathOut->m_tag = (const bfx::bfxMemTag)v20;
      return;
    }
    v68.m_x = v38;
    v25 = v20;
    v21 = v38;
    v68.m_y = v35;
    v22 = v35;
    v68.m_z = v37;
    v24 = v37;
    v20 = v43;
    v44 = __fsqrts((float)((float)((float)v31 * (float)v31)
                         + (float)((float)((float)v33 * (float)v33) + (float)((float)v32 * (float)v32))));
    if ( v42 >= v44 )
    {
      v31 = bfx::ZERO_VEC.m_x;
      v32 = bfx::ZERO_VEC.m_y;
      v33 = bfx::ZERO_VEC.m_z;
    }
    else
    {
      v45 = m_pArea->m_flags.m_flags1 & 0x7F;
      v46 = *((float *)v40 + 15);
      v47 = *((float *)v40 + 16);
      v73 = *((float *)v40 + 17);
      v71 = v46;
      v72 = v47;
      __twllei(v45, 0);
      v48 = (float)((float)((float)((float)v44 - (float)v42) / (float)v44) * (float)v31);
      v49 = (float)((float)v32 * (float)((float)((float)v44 - (float)v42) / (float)v44));
      v50 = (float)((float)v33 * (float)((float)((float)v44 - (float)v42) / (float)v44));
      v51 = (float *)((char *)m_pArea + 24 * ((m_i + 1) % v45));
      __twlgei(v45 & ~(__ROL4__(m_i + 1, 1) - 1), 0xFFFFFFFF);
      v52 = v51[15];
      v53 = v51[16];
      v74.m_z = v51[17];
      v74.m_x = v52;
      v74.m_y = v53;
      _FP10 = (float)((float)__fsqrts((float)((float)((float)(v52 - v71) * (float)(v52 - v71))
                                            + (float)((float)((float)(v74.m_z - v73) * (float)(v74.m_z - v73))
                                                    + (float)((float)(v53 - v72) * (float)(v53 - v72)))))
                    - (float)1.0842022e-19);
      __asm { fsel      f8, f10, f9, f24 }
      v56 = (float)((float)(v52 - v71) * (float)_FP8);
      v57 = (float)((float)(v53 - v72) * (float)_FP8);
      v58 = (float)((float)(v74.m_z - v73) * (float)_FP8);
      bfx::Area::CalcNormal(this: (bfx::Area *)&v75.m_pos, result: v43);
      v59 = (float)((float)v57
                  * (float)((float)((float)v56 * (float)v48)
                          + (float)((float)((float)v58 * (float)v50) + (float)((float)v57 * (float)v49))));
      v60 = (float)((float)v58
                  * (float)((float)((float)v56 * (float)v48)
                          + (float)((float)((float)v58 * (float)v50) + (float)((float)v57 * (float)v49))));
      v61 = (float)((float)((float)((float)v58 * v75.m_pos.m_x) - (float)(v75.m_pos.m_z * (float)v56))
                  * (float)((float)((float)((float)(*(float *)&v75.m_pFirstLink * (float)v57)
                                          - (float)(*(float *)&v75.m_dynAreaData.m_data * (float)v58))
                                  * (float)v48)
                          + (float)((float)((float)((float)(*(float *)&v75.m_dynAreaData.m_data * (float)v56)
                                                  - (float)((float)v57 * *(float *)&v75.m_pProxy))
                                          * (float)v50)
                                  + (float)((float)((float)((float)v58 * *(float *)&v75.m_pProxy)
                                                  - (float)(*(float *)&v75.m_pFirstLink * (float)v56))
                                          * (float)v49))));
      v62 = (float)((float)((float)(v75.m_pos.m_y * (float)v56) - (float)((float)v57 * v75.m_pos.m_x))
                  * (float)((float)((float)((float)(*(float *)&v75.m_pFirstLink * (float)v57)
                                          - (float)(*(float *)&v75.m_dynAreaData.m_data * (float)v58))
                                  * (float)v48)
                          + (float)((float)((float)((float)(*(float *)&v75.m_dynAreaData.m_data * (float)v56)
                                                  - (float)((float)v57 * *(float *)&v75.m_pProxy))
                                          * (float)v50)
                                  + (float)((float)((float)((float)v58 * *(float *)&v75.m_pProxy)
                                                  - (float)(*(float *)&v75.m_pFirstLink * (float)v56))
                                          * (float)v49))));
      v31 = (float)((float)((float)((float)(v75.m_pos.m_z * (float)v57) - (float)(v75.m_pos.m_y * (float)v58))
                          * (float)((float)((float)((float)(*(float *)&v75.m_pFirstLink * (float)v57)
                                                  - (float)(*(float *)&v75.m_dynAreaData.m_data * (float)v58))
                                          * (float)v48)
                                  + (float)((float)((float)((float)(*(float *)&v75.m_dynAreaData.m_data * (float)v56)
                                                          - (float)((float)v57 * *(float *)&v75.m_pProxy))
                                                  * (float)v50)
                                          + (float)((float)((float)((float)v58 * *(float *)&v75.m_pProxy)
                                                          - (float)(*(float *)&v75.m_pFirstLink * (float)v56))
                                                  * (float)v49))))
                  + (float)((float)((float)((float)v56 * (float)v48)
                                  + (float)((float)((float)v58 * (float)v50) + (float)((float)v57 * (float)v49)))
                          * (float)v56));
      v32 = (float)((float)v61 + (float)v59);
      v33 = (float)((float)v62 + (float)v60);
    }
  }
  v63 = *(float *)&pPathOut[1].m_cap;
  v64 = v70.m_x;
  HIBYTE(pPathOut[1].m_data) = 0;
  v65 = v70.m_y;
  pPathOut[1].m_size = -1;
  v66 = v70.m_z;
  pPathOut->m_tag = (const bfx::bfxMemTag)v20;
  *(float *)&pPathOut->m_data = v64;
  *(float *)&pPathOut->m_size = v65;
  *(float *)&pPathOut->m_cap = v66;
  *(float *)&pPathOut[1].m_cap = (float)__fsqrts((float)((float)((float)v31 * (float)v31)
                                                       + (float)((float)((float)v33 * (float)v33)
                                                               + (float)((float)v32 * (float)v32))))
                               + (float)v63;
}


// ========================================================================
// ?IsValid@AreaHandlePath@bfx@@UBA_NXZ
// EA  : 0x83271D68
// RVA : 0x01271D68
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

int __fastcall bfx::AreaHandlePath::IsValid(bfx::AreaHandlePath *this)
{
  int m_size; // r7
  int v2; // r9
  int i; // r10
  bfx::AreaProxy *m_pProxy; // r11
  char v5; // r11
  bool v6; // zf

  m_size = this->m_areaHandles.m_size;
  v2 = 0;
  if ( m_size <= 0 )
    return 1;
  for ( i = 0; ; ++i )
  {
    m_pProxy = this->m_areaHandles.m_data[i].m_pProxy;
    if ( m_pProxy == nullptr || (v6 = m_pProxy->m_pArea != nullptr, v5 = 1, !v6) )
      v5 = 0;
    if ( v5 == 0 )
      break;
    if ( ++v2 >= m_size )
      return 1;
  }
  return 0;
}


// ========================================================================
// ?CheckCircleFit_Internal@bfx@@YA_NPAVArea@1@ABVVec3@1@MABVPathSpec@1@AAV31@@Z
// EA  : 0x83271DD8
// RVA : 0x01271DD8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

int __fastcall bfx::CheckCircleFit_Internal(
        bfx::NavProbeDisplayData *pStartArea,
        const bfx::Vec3 *startPos,
        double maxSearchDist,
        const bfx::PathSpec *pathSpec,
        const bfx::PathSpec *closestPerimeterPosOut,
        float *a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        bfx::NavProbeDisplayData *a13)
{
  unsigned int SearchIndex; // r22
  int v19; // r23
  bfx::List<bfx::NavProbeDisplayData *>::Node *m_pNext; // r9
  bfx::List<bfx::NavProbeDisplayData *>::Node **p_m_pNext; // r11
  double v24; // fp26
  bfx::AreaFlags *v25; // r9
  signed int v26; // r30
  bfx::List<bfx::NavProbeDisplayData *>::Node *m_pPrev; // r8
  bfx::List<bfx::NavProbeDisplayData *>::Node *v28; // r7
  bfx::NavProbeDisplayData *m_val; // r27
  bfx::Pool::Node **p_m_pUnused; // r10
  signed int v31; // r11
  bool *p_m_collided; // r29
  double m_y; // fp11
  double m_x; // fp10
  double m_z; // fp9
  float *v36; // r11
  float v37; // r10
  float v38; // r8
  double v43; // fp30
  double v44; // fp31
  double v45; // fp29
  double v46; // fp0
  double v47; // fp13
  double v48; // fp12
  double v49; // fp28
  bfx::AreaFlags *v50; // r26
  bfx::SearchIndexOb v52; // [sp+50h] [-E0h] BYREF
  bfx::AreaFlags *v53; // [sp+54h] [-DCh] BYREF
  bfx::List<bfx::NavProbeDisplayData *> v54; // [sp+58h] [-D8h] BYREF
  float v55; // [sp+68h] [-C8h]
  float v56; // [sp+6Ch] [-C4h]
  float v57; // [sp+70h] [-C0h]
  float v58; // [sp+78h] [-B8h]
  float v59; // [sp+7Ch] [-B4h]
  float v60; // [sp+80h] [-B0h]

  a13 = pStartArea;
  if ( pStartArea == nullptr
    || (unsigned __int8)bfx::IsUsableArea(pArea: (bfx::Area *)pStartArea, pathSpec: closestPerimeterPosOut) == 0 )
  {
    return 0;
  }
  bfx::SearchIndexOb::SearchIndexOb(this: &v52);
  SearchIndex = bfx::SearchIndexOb::GetSearchIndex(this: &v52);
  bfx::List<bfx::Area *>::List<bfx::Area *>(
    this: (bfx::List<bfx::Island3D *> *)&v54,
    numNodesPerPoolBlock: 0x64u,
    memTag: MEM_TEMP);
  bfx::List<bfx::Area *>::push_back(this: &v54, val: &a13);
  LOWORD(pStartArea[2].m_pts.m_cap) = SearchIndex;
  v19 = 1;
  m_pNext = v54.m_pEnd->m_pNext;
  v53 = (bfx::AreaFlags *)&pStartArea[2];
  p_m_pNext = &v54.m_pEnd->m_pNext;
  _FP13 = (float)((float)maxSearchDist - (float)1.8446743e19);
  __asm { fsel      f12, f13, f0, f31 }
  v24 = (float)((float)_FP12 * (float)_FP12);
  if ( m_pNext != v54.m_pEnd )
  {
    do
    {
      v26 = 0;
      m_pPrev = (*p_m_pNext)->m_pPrev;
      v28 = (*p_m_pNext)->m_pNext;
      m_val = (*p_m_pNext)->m_val;
      v53 = (bfx::AreaFlags *)*p_m_pNext;
      v25 = v53;
      m_pPrev->m_pNext = v28;
      *(_DWORD *)(v25->m_flags2 + 8) = v25->m_flags3;
      p_m_pUnused = &v54.m_pPool->m_data.m_pUnused;
      v25->m_flags1 = (unsigned int)v54.m_pPool->m_data.m_pUnused;
      *p_m_pUnused = (bfx::Pool::Node *)v25;
      v31 = (int)m_val[2].m_pts.m_data & 0x7F;
      if ( v31 != 0 )
      {
        p_m_collided = &m_val[2].m_collided;
        do
        {
          ++v26;
          v56 = *((float *)p_m_collided + 2);
          __twllei(v31, 0);
          v55 = *((float *)p_m_collided + 1);
          v57 = *((float *)p_m_collided + 3);
          m_y = startPos->m_y;
          m_x = startPos->m_x;
          m_z = startPos->m_z;
          __twlgei(v31 & ~(__ROL4__(v26, 1) - 1), 0xFFFFFFFF);
          v36 = (float *)((char *)m_val + 24 * (v26 % v31));
          v37 = v36[17];
          v38 = v36[16];
          v58 = v36[15];
          v60 = v37;
          v59 = v38;
          _FP8 = (float)((float)((float)((float)((float)m_z - v57) * (float)(v37 - v57))
                               + (float)((float)((float)((float)m_x - v55) * (float)(v58 - v55))
                                       + (float)((float)((float)m_y - v56) * (float)(v38 - v56))))
                       / (float)((float)((float)((float)(v37 - v57) * (float)(v37 - v57))
                                       + (float)((float)((float)(v58 - v55) * (float)(v58 - v55))
                                               + (float)((float)(v38 - v56) * (float)(v38 - v56))))
                               + (float)1.0842022e-19));
          __asm { fsel      f7, f8, f8, f25 }
          _FP6 = (float)((float)_FP7 - (float)1.0);
          __asm { fsel      f5, f6, f27, f7 }
          v43 = (float)((float)((float)(v38 - v56) * (float)_FP5) + v56);
          v44 = (float)((float)((float)(v58 - v55) * (float)_FP5) + v55);
          v45 = (float)((float)((float)(v37 - v57) * (float)_FP5) + v57);
          v46 = (float)((float)((float)((float)(v38 - v56) * (float)_FP5) + v56) - (float)m_y);
          v47 = (float)((float)((float)((float)(v58 - v55) * (float)_FP5) + v55) - (float)m_x);
          v48 = (float)((float)((float)((float)(v37 - v57) * (float)_FP5) + v57) - (float)m_z);
          v49 = (float)((float)((float)v48 * (float)v48)
                      + (float)((float)((float)v47 * (float)v47) + (float)((float)v46 * (float)v46)));
          if ( v49 < v24 )
          {
            v50 = *(bfx::AreaFlags **)p_m_collided;
            v53 = *(bfx::AreaFlags **)p_m_collided;
            if ( v53 != nullptr
              && (unsigned __int8)bfx::IsUsableArea(pArea: (bfx::Area *)v50, pathSpec: closestPerimeterPosOut) != 0 )
            {
              if ( LOWORD(v50[3].m_flags1) != SearchIndex )
              {
                bfx::List<bfx::Area *>::push_back(this: &v54, val: (bfx::NavProbeDisplayData **)&v53);
                LOWORD(v50[3].m_flags1) = SearchIndex;
                v53 = (bfx::AreaFlags *)((char *)v50 + 40);
              }
            }
            else
            {
              *a6 = v44;
              v24 = v49;
              a6[1] = v43;
              v19 = 0;
              a6[2] = v45;
            }
          }
          p_m_collided += 24;
          v31 = (int)m_val[2].m_pts.m_data & 0x7F;
        }
        while ( v26 < v31 );
      }
      p_m_pNext = &v54.m_pEnd->m_pNext;
    }
    while ( v54.m_pEnd->m_pNext != v54.m_pEnd );
  }
  bfx::List<bfx::Area *>::~List<bfx::Area *>(this: (bfx::List<bfx::Island3D *> *)&v54);
  bfx::SearchIndexOb::~SearchIndexOb(this: &v52);
  return v19;
}


// ========================================================================
// __unwind$27054
// EA  : 0x832720BC
// RVA : 0x012720BC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

void _unwind_27054()
{
  int v0; // r12

  bfx::SearchIndexOb::~SearchIndexOb(this: (bfx::SearchIndexOb *)(v0 - 304 + 80));
}


// ========================================================================
// __unwind$27055
// EA  : 0x832720E4
// RVA : 0x012720E4
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

void _unwind_27055()
{
  int v0; // r12

  bfx::List<bfx::Area *>::~List<bfx::Area *>(this: (bfx::List<bfx::Island3D *> *)(v0 - 304 + 88));
}


// ========================================================================
// ??0AreaHandlePath@bfx@@QAA@ABV?$Array@PAVArea@bfx@@@1@@Z
// EA  : 0x83272408
// RVA : 0x01272408
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

bfx::AreaHandlePath *__fastcall bfx::AreaHandlePath::AreaHandlePath(
        bfx::AreaHandlePath *this,
        const bfx::Array<bfx::Area *> *areas)
{
  bfx::bfxMemTag v4; // r11
  int m_size; // r4
  int v6; // r26
  int v7; // r28
  const bfx::Handle<bfx::Area> *v8; // r3
  bfx::AreaProxy *m_pProxy; // r11
  char *v10; // r4
  int v11; // r8
  bfx::Area *m_pArea; // r11
  bfx::Handle<bfx::Area> v14; // [sp+50h] [-50h] BYREF
  bfx::Array<bfx::Handle<bfx::Area> > *p_m_areaHandles; // [sp+54h] [-4Ch]

  bfx::Path::Path(this, areas);
  this->__vftable = (bfx::AreaHandlePath_vtbl *)&bfx::AreaHandlePath::`vftable';
  v4 = bfx::MEM_BFXPLANNER;
  p_m_areaHandles = &this->m_areaHandles;
  this->m_areaHandles.m_data = nullptr;
  this->m_areaHandles.m_size = 0;
  this->m_areaHandles.m_cap = 0;
  this->m_areaHandles.m_tag = v4;
  m_size = areas->m_size;
  if ( m_size > 0 )
    bfx::Array<bfx::Handle<bfx::Area>>::expand_cap(this: &this->m_areaHandles, size: m_size);
  v6 = 0;
  if ( areas->m_size > 0 )
  {
    v7 = 0;
    do
    {
      v8 = bfx::Handle<bfx::Area>::Handle<bfx::Area>(this: &v14, pArea: areas->m_data[v7]);
      bfx::Array<bfx::Handle<bfx::Area>>::push_back(this: &this->m_areaHandles, val: v8);
      m_pProxy = v14.m_pProxy;
      if ( v14.m_pProxy != nullptr )
      {
        v10 = (char *)v14.m_pProxy;
        v11 = v14.m_pProxy->m_refCount - 1;
        v14.m_pProxy->m_refCount = v11;
        if ( v11 == 0 )
        {
          m_pArea = m_pProxy->m_pArea;
          if ( m_pArea != nullptr )
          {
            m_pArea->m_pProxy = nullptr;
            p_m_areaHandles = (bfx::Array<bfx::Handle<bfx::Area> > *)m_pArea;
            *(_DWORD *)v10 = 0;
          }
          bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v10);
        }
        v14.m_pProxy = nullptr;
      }
      ++v6;
      ++v7;
    }
    while ( v6 < areas->m_size );
  }
  return this;
}


// ========================================================================
// __unwind$27740
// EA  : 0x8327251C
// RVA : 0x0127251C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

void _unwind_27740()
{
  int v0; // r12

  bfx::Path::~Path(this: *(bfx::Path **)(v0 - 160 + 180));
}


// ========================================================================
// __unwind$27741
// EA  : 0x83272544
// RVA : 0x01272544
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

void _unwind_27741()
{
  int v0; // r12

  bfx::Array<bfx::Handle<bfx::Area>>::~Array<bfx::Handle<bfx::Area>>(this: (bfx::Array<bfx::Handle<bfx::Area> > *)(*(_DWORD *)(v0 - 160 + 180) + 24));
}


// ========================================================================
// __unwind$27742
// EA  : 0x83272570
// RVA : 0x01272570
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxareas.cpp
// ========================================================================

void _unwind_27742()
{
  int v0; // r12

  bfx::Handle<bfx::Area>::~Handle<bfx::Area>(this: (bfx::AreaHandleImpl *)(v0 - 160 + 80));
}

