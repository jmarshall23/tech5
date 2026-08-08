
// ========================================================================
// ?GetNextFreeSlotIndex@NavLayer@bfx@@QAAHXZ
// EA  : 0x83272798
// RVA : 0x01272798
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

int __fastcall bfx::NavLayer::GetNextFreeSlotIndex(bfx::NavLayer *this)
{
  int m_endGraphIndex; // r9
  int v3; // r11
  bfx::NavGraph **i; // r10

  m_endGraphIndex = this->m_endGraphIndex;
  if ( this->m_numGraphs == m_endGraphIndex )
  {
    if ( m_endGraphIndex < 2048 )
      return this->m_endGraphIndex;
    return -1;
  }
  v3 = 0;
  if ( m_endGraphIndex <= 0 )
    return -1;
  for ( i = this->m_graphs; *i != nullptr; ++i )
  {
    if ( ++v3 >= m_endGraphIndex )
      return -1;
  }
  return v3;
}


// ========================================================================
// ?IncToNextValid@NavLayerCC@bfx@@AAAXXZ
// EA  : 0x832727F8
// RVA : 0x012727F8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::NavLayerCC::IncToNextValid(bfx::NavLayerCC *this)
{
  bfx::NavLayer *m_layer; // r10
  int v2; // r11
  int m_i; // r11
  int v4; // r11

  m_layer = this->m_layer;
  v2 = this->m_i + 1;
  this->m_i = v2;
  if ( v2 < m_layer->m_endGraphIndex )
  {
    do
    {
      m_i = this->m_i;
      if ( this->m_layer->m_graphs[m_i] != nullptr )
        break;
      v4 = m_i + 1;
      this->m_i = v4;
    }
    while ( v4 < this->m_layer->m_endGraphIndex );
  }
}


// ========================================================================
// ?CollideLineSegmentAndArea@bfx@@YA_NPAVArea@1@ABVVec3@1@1AAMAAPAV21@@Z
// EA  : 0x83272850
// RVA : 0x01272850
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

int __fastcall bfx::CollideLineSegmentAndArea(
        bfx::Vec3 *pArea,
        const bfx::Vec3 *start,
        const bfx::Vec3 *dir,
        float *collideDist,
        bfx::Vec3 **pCollideAreaOut)
{
  double m_z; // fp6
  double m_x; // fp5
  double m_y; // fp4
  double v13; // fp3
  double v14; // fp0
  double v15; // fp13
  char *m_x_low; // r10
  double v17; // fp12
  bfx::Area *m_z_low; // r9
  double v19; // fp11
  double v20; // fp0
  double v21; // fp31
  double Scale; // fp1
  bfx::Vec3 v24; // [sp+50h] [-60h] BYREF
  bfx::Area v25; // [sp+60h] [-50h] BYREF

  bfx::Area::CalcNormal(this: &v25, result: pArea);
  m_z = dir->m_z;
  m_x = dir->m_x;
  m_y = dir->m_y;
  v13 = *collideDist;
  v14 = (float)((float)((float)(dir->m_y * *(float *)&v25.m_dynAreaData.m_data)
                      + (float)((float)(dir->m_x * *(float *)&v25.m_pProxy)
                              + (float)(dir->m_z * *(float *)&v25.m_pFirstLink)))
              * *collideDist);
  if ( __fabs(v14) < 1.0842022e-19 )
    return 0;
  v15 = start->m_z;
  m_x_low = (char *)LODWORD(pArea[5].m_x);
  v17 = start->m_y;
  m_z_low = (bfx::Area *)LODWORD(pArea[5].m_z);
  v19 = start->m_x;
  v24.m_y = pArea[5].m_y;
  LODWORD(v24.m_x) = m_x_low;
  LODWORD(v24.m_z) = m_z_low;
  v20 = (float)((float)((float)((float)(*(float *)&m_x_low - (float)v19) * *(float *)&v25.m_pProxy)
                      + (float)((float)((float)(v24.m_y - (float)v17) * *(float *)&v25.m_dynAreaData.m_data)
                              + (float)((float)(*(float *)&m_z_low - (float)v15) * *(float *)&v25.m_pFirstLink)))
              / (float)v14);
  if ( v20 < 0.0 )
    return 0;
  if ( v20 > 1.0 )
    return 0;
  v21 = (float)((float)v13 * (float)v20);
  v24.m_x = (float)v19 + (float)((float)m_x * (float)((float)v13 * (float)v20));
  v24.m_y = (float)v17 + (float)((float)m_y * (float)((float)v13 * (float)v20));
  v24.m_z = (float)v15 + (float)((float)m_z * (float)((float)v13 * (float)v20));
  Scale = bfx::GetScale();
  if ( (unsigned __int8)bfx::IsPlanePosInsideArea(
                          pos: &v24,
                          (const bfx::Area *)pArea,
                          areaNormal: (const bfx::Vec3 *)&v25,
                          tolerance: (float)((float)Scale * (float)0.000099999997)) == 0 )
    return 0;
  *collideDist = v21;
  *pCollideAreaOut = pArea;
  return 1;
}


// ========================================================================
// ?EndianSwap@NavGraphHeader@bfx@@QAAXXZ
// EA  : 0x832729A8
// RVA : 0x012729A8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::NavGraphHeader::EndianSwap(bfx::NavGraphHeader *this)
{
  bfx::EndianSwapLong(val: &this->m_version);
  bfx::EndianSwapLong(val: &this->m_layer);
  bfx::EndianSwapLong(val: (unsigned int *)&this->m_areaBytes);
  bfx::EndianSwapLong(val: (unsigned int *)&this->m_totalBytes);
  bfx::EndianSwapFloat(val: &this->m_buildScale);
  bfx::EndianSwapFloat(val: &this->m_voxSize);
  bfx::EndianSwapFloat(val: &this->m_radius);
  bfx::EndianSwapFloat(val: &this->m_step);
  bfx::EndianSwapFloat(val: &this->m_height);
  bfx::EndianSwapBox(box: &this->m_bbox);
  bfx::EndianSwapLong(val: &this->m_buildUpAxis);
}


// ========================================================================
// ?EndianSwapNavGraphImage@bfx@@YAXPAD@Z
// EA  : 0x83272A28
// RVA : 0x01272A28
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::EndianSwapNavGraphImage(bfx::NavGraphHeader *pBinaryImage)
{
  bfx::Area *v2; // r31
  char *i; // r30

  v2 = (bfx::Area *)&pBinaryImage[1];
  bfx::NavGraphHeader::EndianSwap(this: pBinaryImage);
  for ( i = (char *)&pBinaryImage[1] + pBinaryImage->m_areaBytes;
        v2 < (bfx::Area *)i;
        v2 = (bfx::Area *)((char *)v2 + 24 * (v2->m_flags.m_flags1 & 0x7F) + 56) )
  {
    bfx::Area::EndianSwap(this: v2);
  }
  bfx::KDTreeData::EndianSwap(this: (bfx::KDTreeData *)v2);
}


// ========================================================================
// ?EndianSwap@NavSetHeader@bfx@@QAAXXZ
// EA  : 0x83272AA8
// RVA : 0x01272AA8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::NavSetHeader::EndianSwap(bfx::NavSetHeader *this)
{
  this->m_endianFlag = (this->m_endianFlag != 0) - 1;
  bfx::EndianSwapLong(val: &this->m_version);
  bfx::EndianSwapLong(val: (unsigned int *)&this->m_numGraphs);
}


// ========================================================================
// ?EndianSwapBinaryImage@bfx@@YAXPAD@Z
// EA  : 0x83272AF8
// RVA : 0x01272AF8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::EndianSwapBinaryImage(char *pInputBinaryImage)
{
  char *v2; // r29
  bfx::NavGraphHeader *v3; // r31
  int i; // r30

  *(_DWORD *)pInputBinaryImage = (*(_DWORD *)pInputBinaryImage != 0) - 1;
  v2 = pInputBinaryImage + 8;
  bfx::EndianSwapLong(val: (unsigned int *)pInputBinaryImage + 1);
  bfx::EndianSwapLong(val: (unsigned int *)pInputBinaryImage + 2);
  v3 = (bfx::NavGraphHeader *)(pInputBinaryImage + 12);
  for ( i = 0; i < *(_DWORD *)v2; v3 = (bfx::NavGraphHeader *)((char *)v3 + v3->m_totalBytes) )
  {
    bfx::EndianSwapNavGraphImage(pBinaryImage: v3);
    ++i;
  }
}


// ========================================================================
// ?AdvanceClockwiseAroundVertFanAtEdgeStart@bfx@@YA?AVEdgeCursor@1@ABV21@@Z
// EA  : 0x83272B70
// RVA : 0x01272B70
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

bfx::EdgeCursor *__fastcall bfx::AdvanceClockwiseAroundVertFanAtEdgeStart(
        bfx::EdgeCursor *result,
        const bfx::EdgeCursor *startEdge)
{
  bfx::Area *m_pArea; // r31
  bfx::EdgeCursor v5; // [sp+50h] [-30h] BYREF
  bfx::EdgeCursor v6; // [sp+58h] [-28h] BYREF

  m_pArea = startEdge->m_pArea;
  v5 = *startEdge;
  while ( 1 )
  {
    bfx::EdgeCursor::GetSibling(this: &v6, result: &v5);
    if ( v6.m_pArea == nullptr )
      break;
    v5.m_pArea = (bfx::Area *)v6.m_i;
    v5.m_i = v6.m_i + 1;
    v5.m_i = (((unsigned int)(v6.m_i + 1) - __PAIR64__(
                                              (unsigned int)(v6.m_i + 1) >> 31,
                                              *(_DWORD *)(v6.m_i + 40) & 0x7F)) >> 32)
           & (v6.m_i + 1);
    if ( (bfx::Area *)v6.m_i == m_pArea )
    {
      result->m_pArea = nullptr;
      result->m_i = -1;
      return result;
    }
  }
  *result = v5;
  return result;
}


// ========================================================================
// ?AdvanceCounterClockwiseAroundVertFanAtEdgeStart@bfx@@YA?AVEdgeCursor@1@ABV21@@Z
// EA  : 0x83272C28
// RVA : 0x01272C28
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

bfx::EdgeCursor *__fastcall bfx::AdvanceCounterClockwiseAroundVertFanAtEdgeStart(
        bfx::EdgeCursor *result,
        const bfx::EdgeCursor *startEdge)
{
  bfx::Area *m_pArea; // r31
  bfx::EdgeCursor v5; // [sp+50h] [-30h] BYREF
  bfx::EdgeCursor v6; // [sp+58h] [-28h] BYREF

  m_pArea = startEdge->m_pArea;
  v5 = *startEdge;
  while ( 1 )
  {
    if ( --v5.m_i < 0 )
      v5.m_i = (v5.m_pArea->m_flags.m_flags1 & 0x7F) - 1;
    bfx::EdgeCursor::GetSibling(this: &v6, result: &v5);
    if ( v6.m_pArea == nullptr )
      break;
    v5 = v6;
    if ( v6.m_pArea == m_pArea )
    {
      result->m_pArea = nullptr;
      result->m_i = -1;
      return result;
    }
  }
  *result = v5;
  return result;
}


// ========================================================================
// ?CalcAndSetEdgeTraversalCostsForArea@bfx@@YAXPAVArea@1@@Z
// EA  : 0x83272CD0
// RVA : 0x01272CD0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::CalcAndSetEdgeTraversalCostsForArea(bfx::Area *pArea)
{
  float m_y; // r10
  float m_z; // r9
  unsigned int v4; // r30
  double Scale; // fp1
  int m_i; // r11
  bfx::Area *m_pArea; // r9
  double v8; // fp26
  double v9; // fp29
  double v10; // fp28
  double v11; // fp27
  bfx::AreaProxy *v12; // r31
  __int64 v13; // r4
  float v14; // r8
  float v15; // r6
  int v16; // r11
  int v17; // r8
  char *v18; // r11
  char *v19; // r11
  bfx::EdgeCursor v20; // [sp+50h] [-90h] BYREF
  bfx::EdgeCursor v21[2]; // [sp+58h] [-88h] BYREF
  __int64 v22; // [sp+68h] [-78h]
  float v23; // [sp+70h] [-70h]
  unsigned __int64 v24; // [sp+78h] [-68h]
  float v25; // [sp+80h] [-60h]

  m_y = pArea->m_pos.m_y;
  m_z = pArea->m_pos.m_z;
  v4 = (pArea->m_flags.m_flags2 >> 20) & 0xF;
  *(float *)&v22 = pArea->m_pos.m_x;
  *((float *)&v22 + 1) = m_y;
  v23 = m_z;
  Scale = bfx::GetScale();
  m_i = 0;
  v20.m_pArea = pArea;
  m_pArea = pArea;
  v8 = Scale;
  v20.m_i = 0;
  if ( (pArea->m_flags.m_flags1 & 0x7F) != 0 )
  {
    v9 = v23;
    v10 = *((float *)&v22 + 1);
    v11 = *(float *)&v22;
    do
    {
      v12 = (&m_pArea[1].m_pProxy)[6 * m_i];
      if ( v12 != nullptr )
      {
        HIDWORD(v13) = bfx::EdgeCursor::GetSibling(this: v21, result: &v20);
        if ( v21[0].m_pArea != nullptr )
        {
          v14 = *(float *)&v12[2].m_refCount;
          v15 = *(float *)&v12[2].m_pArea;
          v16 = ((unsigned int)v12[5].m_refCount >> 20) & 0xF;
          v25 = *(float *)&v12[3].m_pArea;
          v24 = __PAIR64__(LODWORD(v15), LODWORD(v14));
          LODWORD(v13) = v16 + v4;
          v21[1] = (bfx::EdgeCursor)v13;
          v22 = (__int64)(float)((float)((float)((float)((float)__fsqrts((float)((float)((float)((float)v10 - v14)
                                                                                       * (float)((float)v10 - v14))
                                                                               + (float)((float)((float)((float)v9 - v25)
                                                                                               * (float)((float)v9 - v25))
                                                                                       + (float)((float)((float)v11 - v15)
                                                                                               * (float)((float)v11 - v15)))))
                                                       * (float)v13)
                                               * (float)(1000.0 / (float)v8))
                                       * (float)0.5)
                               + (float)1.0);
          v17 = v22;
          if ( v20.m_pArea != nullptr )
            v18 = (char *)&v20.m_pArea[1] + 24 * v20.m_i;
          else
            v18 = nullptr;
          *((_DWORD *)v18 + 5) = v22;
          if ( v21[0].m_pArea != nullptr )
            v19 = (char *)&v21[0].m_pArea[1] + 24 * v21[0].m_i;
          else
            v19 = nullptr;
          *((_DWORD *)v19 + 5) = v17;
        }
        m_pArea = v20.m_pArea;
        m_i = v20.m_i;
      }
      v20.m_i = ++m_i;
    }
    while ( m_i < (signed int)(m_pArea->m_flags.m_flags1 & 0x7F) );
  }
}


// ========================================================================
// ?AngleToPosOnSegBOk@bfx@@YA_NABVVec3@1@0ABVLineSeg@1@V21@@Z
// EA  : 0x83272E98
// RVA : 0x01272E98
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

BOOL __fastcall bfx::AngleToPosOnSegBOk(
        const bfx::Vec3 *edgeAUnitVec,
        const bfx::Vec3 *edgeAOutwardEdgeNormal,
        const bfx::LineSeg *segA,
        const bfx::Vec3 *posOnSegB)
{
  double v4; // fp8
  double v5; // fp6
  double v6; // fp5

  v4 = (float)((float)(*(float *)&posOnSegB - segA->m_v0.m_y)
             - (float)(edgeAUnitVec->m_y
                     * (float)((float)(edgeAUnitVec->m_y * (float)(*(float *)&posOnSegB - segA->m_v0.m_y))
                             + (float)((float)(edgeAUnitVec->m_z * (float)(*(float *)&posOnSegB - segA->m_v0.m_z))
                                     + (float)(edgeAUnitVec->m_x * (float)(*(float *)&segA - segA->m_v0.m_x))))));
  v5 = (float)((float)(*(float *)&posOnSegB - segA->m_v0.m_z)
             - (float)(edgeAUnitVec->m_z
                     * (float)((float)(edgeAUnitVec->m_y * (float)(*(float *)&posOnSegB - segA->m_v0.m_y))
                             + (float)((float)(edgeAUnitVec->m_z * (float)(*(float *)&posOnSegB - segA->m_v0.m_z))
                                     + (float)(edgeAUnitVec->m_x * (float)(*(float *)&segA - segA->m_v0.m_x))))));
  v6 = (float)((float)(*(float *)&segA - segA->m_v0.m_x)
             - (float)(edgeAUnitVec->m_x
                     * (float)((float)(edgeAUnitVec->m_y * (float)(*(float *)&posOnSegB - segA->m_v0.m_y))
                             + (float)((float)(edgeAUnitVec->m_z * (float)(*(float *)&posOnSegB - segA->m_v0.m_z))
                                     + (float)(edgeAUnitVec->m_x * (float)(*(float *)&segA - segA->m_v0.m_x))))));
  _FP2 = (float)((float)__fsqrts((float)((float)((float)v6 * (float)v6)
                                       + (float)((float)((float)v5 * (float)v5) + (float)((float)v4 * (float)v4))))
               - (float)1.0842022e-19);
  __asm { fsel      f0, f2, f1, f12 }
  return (float)((float)(edgeAOutwardEdgeNormal->m_x
                       * (float)((float)((float)(*(float *)&segA - segA->m_v0.m_x)
                                       - (float)(edgeAUnitVec->m_x
                                               * (float)((float)(edgeAUnitVec->m_y
                                                               * (float)(*(float *)&posOnSegB - segA->m_v0.m_y))
                                                       + (float)((float)(edgeAUnitVec->m_z
                                                                       * (float)(*(float *)&posOnSegB - segA->m_v0.m_z))
                                                               + (float)(edgeAUnitVec->m_x
                                                                       * (float)(*(float *)&segA - segA->m_v0.m_x))))))
                               * (float)_FP0))
               + (float)((float)(edgeAOutwardEdgeNormal->m_z
                               * (float)((float)((float)(*(float *)&posOnSegB - segA->m_v0.m_z)
                                               - (float)(edgeAUnitVec->m_z
                                                       * (float)((float)(edgeAUnitVec->m_y
                                                                       * (float)(*(float *)&posOnSegB - segA->m_v0.m_y))
                                                               + (float)((float)(edgeAUnitVec->m_z
                                                                               * (float)(*(float *)&posOnSegB
                                                                                       - segA->m_v0.m_z))
                                                                       + (float)(edgeAUnitVec->m_x
                                                                               * (float)(*(float *)&segA - segA->m_v0.m_x))))))
                                       * (float)_FP0))
                       + (float)(edgeAOutwardEdgeNormal->m_y
                               * (float)((float)((float)(*(float *)&posOnSegB - segA->m_v0.m_y)
                                               - (float)(edgeAUnitVec->m_y
                                                       * (float)((float)(edgeAUnitVec->m_y
                                                                       * (float)(*(float *)&posOnSegB - segA->m_v0.m_y))
                                                               + (float)((float)(edgeAUnitVec->m_z
                                                                               * (float)(*(float *)&posOnSegB
                                                                                       - segA->m_v0.m_z))
                                                                       + (float)(edgeAUnitVec->m_x
                                                                               * (float)(*(float *)&segA - segA->m_v0.m_x))))))
                                       * (float)_FP0)))) >= (double)ANGLE_BETWEEN_NORMALS_THRESHOLD;
}


// ========================================================================
// ?PortalSurfaceOrientationOk@bfx@@YA_NABVLineSeg@1@0ABVVec3@1@@Z
// EA  : 0x83272F68
// RVA : 0x01272F68
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

BOOL __fastcall bfx::PortalSurfaceOrientationOk(
        const bfx::LineSeg *segA,
        const bfx::LineSeg *segB,
        const bfx::Vec3 *areaANormal)
{
  double v3; // fp10
  double v4; // fp7
  double v5; // fp4
  double m_z; // fp3
  double m_x; // fp2
  double m_y; // fp1
  __int64 v10; // r6
  double v13; // fp11
  double v14; // fp5
  double v15; // fp4
  double v16; // fp3
  bfx::Vec3 v20; // [sp+50h] [-40h] BYREF
  bfx::Vec3 v21[2]; // [sp+60h] [-30h] BYREF

  v3 = (float)(segA->m_v1.m_y - segA->m_v0.m_y);
  v4 = (float)(segA->m_v1.m_x - segA->m_v0.m_x);
  v5 = (float)(segA->m_v1.m_z - segA->m_v0.m_z);
  m_z = areaANormal->m_z;
  m_x = areaANormal->m_x;
  m_y = areaANormal->m_y;
  v10 = *(_QWORD *)&segB->m_v0.m_x;
  _FP5 = (float)((float)__fsqrts((float)((float)((float)v5 * (float)v5)
                                       + (float)((float)((float)v4 * (float)v4) + (float)((float)v3 * (float)v3))))
               - (float)1.0842022e-19);
  __asm { fsel      f9, f5, f11, f12 }
  v13 = (float)((float)(segA->m_v1.m_x - segA->m_v0.m_x) * (float)_FP9);
  v21[0].m_x = (float)(segA->m_v1.m_x - segA->m_v0.m_x) * (float)_FP9;
  v21[0].m_y = (float)_FP9 * (float)v3;
  v21[0].m_z = (float)_FP9 * (float)v5;
  v14 = (float)((float)((float)m_x * v21[0].m_z) - (float)((float)m_z * (float)v13));
  v15 = (float)((float)((float)m_y * (float)v13) - (float)((float)m_x * v21[0].m_y));
  v16 = (float)((float)((float)m_z * v21[0].m_y) - (float)((float)m_y * v21[0].m_z));
  _FP9 = (float)((float)__fsqrts((float)((float)((float)v16 * (float)v16)
                                       + (float)((float)((float)v15 * (float)v15) + (float)((float)v14 * (float)v14))))
               - (float)1.0842022e-19);
  __asm { fsel      f7, f9, f8, f12 }
  v20.m_x = (float)v16 * (float)_FP7;
  v20.m_y = (float)v14 * (float)_FP7;
  v20.m_z = (float)((float)((float)m_y * (float)v13) - (float)((float)m_x * v21[0].m_y)) * (float)_FP7;
  return bfx::AngleToPosOnSegBOk(
           edgeAUnitVec: v21,
           edgeAOutwardEdgeNormal: &v20,
           segA: (const bfx::LineSeg *)HIDWORD(v10),
           posOnSegB: (const bfx::Vec3 *)v10)
      && bfx::AngleToPosOnSegBOk(
           edgeAUnitVec: v21,
           edgeAOutwardEdgeNormal: &v20,
           segA: (const bfx::LineSeg *)LODWORD(segB->m_v1.m_x),
           posOnSegB: (const bfx::Vec3 *)LODWORD(segB->m_v1.m_y));
}


// ========================================================================
// ?CompareOverlaps@bfx@@YAHPBX0@Z
// EA  : 0x832730C0
// RVA : 0x012730C0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

int __fastcall bfx::CompareOverlaps(float *a, float *b)
{
  double v2; // fp0
  double v3; // fp13
  int result; // r3

  v2 = a[4];
  v3 = b[4];
  if ( v2 < v3 )
    return 1;
  result = -1;
  if ( v2 <= v3 )
    return 0;
  return result;
}


// ========================================================================
// ??1SetBooleanOnExitOb@bfx@@QAA@XZ
// EA  : 0x832730F0
// RVA : 0x012730F0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::SetBooleanOnExitOb::~SetBooleanOnExitOb(bfx::SetBooleanOnExitOb *this)
{
  *this->m_variable = this->m_exitValue;
}


// ========================================================================
// ?DisconnectArea@bfx@@YAXPAVArea@1@@Z
// EA  : 0x83273100
// RVA : 0x01273100
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::DisconnectArea(bfx::Area *pArea)
{
  bfx::AreaProxy **v1; // r8
  bfx::AreaProxy **v2; // r11
  bfx::EdgeCursor v3; // [sp+50h] [-20h] BYREF
  bfx::EdgeCursor v4; // [sp+58h] [-18h] BYREF

  v3.m_pArea = pArea;
  v3.m_i = 0;
  if ( (pArea->m_flags.m_flags1 & 0x7F) != 0 )
  {
    do
    {
      bfx::EdgeCursor::GetSibling(this: &v4, result: &v3);
      if ( v3.m_pArea != nullptr )
        v1 = &(&v3.m_pArea[1].m_pProxy)[6 * v3.m_i];
      else
        v1 = nullptr;
      if ( v4.m_pArea != nullptr )
        v2 = &(&v4.m_pArea[1].m_pProxy)[6 * v4.m_i];
      else
        v2 = nullptr;
      *v1 = nullptr;
      if ( v2 != nullptr )
        *v2 = nullptr;
      ++v3.m_i;
    }
    while ( v3.m_i < (signed int)(v3.m_pArea->m_flags.m_flags1 & 0x7F) );
  }
}


// ========================================================================
// ?ApplyShapeDatOverride@NavGraph@bfx@@AAAXPBVShapeDat@2@@Z
// EA  : 0x832731D8
// RVA : 0x012731D8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall bfx::NavGraph::ApplyShapeDatOverride(
        bfx::NavGraph *this,
        const bfx::ShapeDat *pShapeDatOverride,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  double m_radius; // fp2
  double v8; // fp1
  double m_step; // fp2
  double v10; // fp1
  __int64 v11; // r4
  int v12; // [sp+8h] [-68h]
  int v13; // [sp+Ch] [-64h]
  int v14; // [sp+10h] [-60h]
  int v15; // [sp+14h] [-5Ch]

  if ( pShapeDatOverride != nullptr )
  {
    m_radius = pShapeDatOverride->m_radius;
    v8 = this->m_pHeader->m_radius;
    if ( m_radius != v8 )
    {
      HIDWORD(a3) = LODWORD(m_radius);
      bfx::InternalWarning(
        fmt: __SPAIR64__("Radius of %3.1f for new NavGraph differs from previous value of %3.1f.  Ignoring.\n", LODWORD(v8)),
        a2: a3,
        a3: a4,
        a4: a5,
        a5: v12,
        a6: v13,
        a7: v14,
        a8: v15);
    }
    m_step = pShapeDatOverride->m_step;
    v10 = this->m_pHeader->m_step;
    if ( m_step != v10 )
    {
      HIDWORD(a3) = LODWORD(m_step);
      bfx::InternalWarning(
        fmt: __SPAIR64__(
          "Step height of %3.1f for new NavGraph differs from previous value of %3.1f.  Ignoring.\n",
          LODWORD(v10)),
        a2: a3,
        a3: a4,
        a4: a5,
        a5: v12,
        a6: v13,
        a7: v14,
        a8: v15);
    }
    if ( pShapeDatOverride->m_height != this->m_pHeader->m_height )
    {
      HIDWORD(v11) = "Height of %3.1f for new NavGraph differs from previous value of %3.1f.  Ignoring.\n";
      *(double *)((char *)&a3 + 4) = pShapeDatOverride->m_height;
      bfx::InternalWarning(fmt: v11, a2: a3, a3: a4, a4: a5, a5: v12, a6: v13, a7: v14, a8: v15);
    }
    this->m_pHeader->m_radius = pShapeDatOverride->m_radius;
    this->m_pHeader->m_step = pShapeDatOverride->m_step;
    this->m_pHeader->m_height = pShapeDatOverride->m_height;
  }
}


// ========================================================================
// ?GetOffsetForArea@NavGraph@bfx@@QAAHPAVArea@2@@Z
// EA  : 0x832732C8
// RVA : 0x012732C8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

int __fastcall bfx::NavGraph::GetOffsetForArea(bfx::NavGraph *this, bfx::Area *pArea)
{
  return (char *)pArea - this->m_binaryImage;
}


// ========================================================================
// ?GetAreaFromOffset@NavGraph@bfx@@QAAPAVArea@2@H@Z
// EA  : 0x832732D8
// RVA : 0x012732D8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

bfx::Area *__fastcall bfx::NavGraph::GetAreaFromOffset(bfx::NavGraph *this, int offset)
{
  return (bfx::Area *)&this->m_binaryImage[offset];
}


// ========================================================================
// ?GenerateRandomColorForAreas@bfx@@YA?AVColor@1@I@Z
// EA  : 0x832732E8
// RVA : 0x012732E8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

bfx::Color *__fastcall bfx::GenerateRandomColorForAreas(bfx::Color *result, unsigned int seedNum)
{
  __int128 v2; // r8
  double v3; // fp5
  double v4; // fp3

  DWORD1(v2) = seedNum >> 30;
  LODWORD(v2) = (((seedNum >> 5) & 0x380 | ((seedNum >> 15) ^ seedNum) & 0xFFFFFC7F) >> 3) & 0x77;
  DWORD2(v2) = ((unsigned __int8)(((seedNum >> 9) ^ seedNum) >> 15) ^ (unsigned __int8)seedNum) & 7 ^ (seedNum >> 30);
  v3 = (double)*(__int64 *)((char *)&v2 + 4);
  v4 = (float)(__int64)v2;
  DWORD2(v2) = (((seedNum >> 12) ^ seedNum) >> 3) ^ seedNum;
  LODWORD(v2) = (WORD5(v2) & 0x1C0 ^ (seedNum >> 19) & 0x100) >> 6;
  result->m_a = 0.80000001;
  result->m_g = (float)((float)((float)v4 * (float)0.125) * (float)0.69999999) + (float)0.30000001;
  result->m_r = (float)((float)((float)v3 * (float)0.125) * (float)0.69999999) + (float)0.30000001;
  result->m_b = (float)((float)((float)(__int64)v2 * (float)0.125) * (float)0.69999999) + (float)0.30000001;
  return result;
}


// ========================================================================
// ?GetPlanner@NavLayer@bfx@@QAAPAVPlanner@2@XZ
// EA  : 0x83273450
// RVA : 0x01273450
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

bfx::Planner *__fastcall bfx::NavLayer::GetPlanner(bfx::NavLayer *this)
{
  return *((bfx::Planner **)this->m_pSpace->m_components.m_data + 1);
}


// ========================================================================
// ?InitDynCC@ActiveAreasInArrayCursor@bfx@@AAAXXZ
// EA  : 0x83273460
// RVA : 0x01273460
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::ActiveAreasInArrayCursor::InitDynCC(bfx::ActiveAreasInArrayCursor *this)
{
  int m_i; // r10
  bfx::Area *v2; // r11
  int *v3; // r10
  char *m_data; // r11
  int v5; // r10

  m_i = this->m_staticCC.m_i;
  if ( m_i < this->m_staticCC.m_pArray->m_size
    && (v2 = this->m_staticCC.m_pArray->m_data[m_i], (v3 = (int *)v2->m_dynAreaData.m_data) != nullptr)
    && *v3 > 0 )
  {
    m_data = v2->m_dynAreaData.m_data;
    if ( m_data != nullptr )
    {
      v5 = *(_DWORD *)m_data;
      this->m_dynCC.m_pCurDynArea = (bfx::Area *)(m_data + 20);
      this->m_dynCC.m_i = 0;
      this->m_dynCC.m_numDynAreas = v5;
    }
    else
    {
      this->m_dynCC.m_pCurDynArea = nullptr;
      this->m_dynCC.m_numDynAreas = 0;
      this->m_dynCC.m_i = 0;
    }
  }
  else
  {
    this->m_dynCC.m_i = 0;
    this->m_dynCC.m_pCurDynArea = nullptr;
    this->m_dynCC.m_numDynAreas = 0;
  }
}


// ========================================================================
// ??EActiveAreasInArrayCursor@bfx@@QAAXXZ
// EA  : 0x83273500
// RVA : 0x01273500
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::ActiveAreasInArrayCursor::operator++(bfx::ActiveAreasInArrayCursor *this)
{
  int m_i; // r11
  char *m_data; // r10
  bfx::Area *m_pCurDynArea; // r10
  unsigned int m_flags1; // r9

  m_i = this->m_staticCC.m_i;
  m_data = this->m_staticCC.m_pArray->m_data[m_i]->m_dynAreaData.m_data;
  if ( m_data != nullptr && *(_DWORD *)m_data != 0 )
  {
    m_pCurDynArea = this->m_dynCC.m_pCurDynArea;
    m_flags1 = m_pCurDynArea->m_flags.m_flags1;
    ++this->m_dynCC.m_i;
    this->m_dynCC.m_pCurDynArea = (bfx::Area *)((char *)m_pCurDynArea + 24 * (m_flags1 & 0x7F) + 72);
    if ( this->m_dynCC.m_i == this->m_dynCC.m_numDynAreas )
    {
      ++this->m_staticCC.m_i;
      bfx::ActiveAreasInArrayCursor::InitDynCC(this);
    }
  }
  else
  {
    this->m_staticCC.m_i = m_i + 1;
    bfx::ActiveAreasInArrayCursor::InitDynCC(this);
  }
}


// ========================================================================
// ?CollideLineSegmentAndPrim@AreaCollider@bfx@@QBA_NABVVec3@2@0IAAM@Z
// EA  : 0x83273590
// RVA : 0x01273590
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

int __fastcall bfx::AreaCollider::CollideLineSegmentAndPrim(
        bfx::AreaCollider *this,
        const bfx::Vec3 *start,
        const bfx::Vec3 *dir,
        unsigned int primOffset,
        float *collideDist)
{
  char *v9; // r3
  _DWORD *v10; // r11
  int v11; // r29
  bfx::Vec3 *v13; // r31
  int v14; // r30

  v9 = &this->m_pNavGraph->m_binaryImage[primOffset];
  v10 = *((_DWORD **)v9 + 1);
  if ( v10 == nullptr )
    return bfx::CollideLineSegmentAndArea(
             pArea: (bfx::Vec3 *)v9,
             start,
             dir,
             collideDist,
             pCollideAreaOut: (bfx::Vec3 **)this->m_pCollideAreaOut);
  v11 = *v10;
  if ( *v10 == 0 )
    return bfx::CollideLineSegmentAndArea(
             pArea: (bfx::Vec3 *)v9,
             start,
             dir,
             collideDist,
             pCollideAreaOut: (bfx::Vec3 **)this->m_pCollideAreaOut);
  v13 = (bfx::Vec3 *)(v10 + 5);
  v14 = 0;
  while ( (unsigned __int8)bfx::CollideLineSegmentAndArea(
                             pArea: v13,
                             start,
                             dir,
                             collideDist,
                             pCollideAreaOut: (bfx::Vec3 **)this->m_pCollideAreaOut) == 0 )
  {
    ++v14;
    v13 += 2 * (LODWORD(v13[3].m_y) & 0x7F) + 6;
    if ( v14 == v11 )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?ConnectToAdjAllocatedArea@bfx@@YAXAAVEdgeCursor@1@@Z
// EA  : 0x83273660
// RVA : 0x01273660
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::ConnectToAdjAllocatedArea(bfx::EdgeCursor *unconnectedSideEdge)
{
  bfx::Area *m_pArea; // r30
  bfx::Area *v3; // r9
  int m_i; // r7
  signed int v5; // r4
  int v6; // r10
  bfx::Area *v7; // r8
  bfx::DynAreaData *v8; // r31
  int v9; // r6
  char *v10; // r11
  unsigned int v11; // r4
  float v12; // r3
  bfx::EdgeCursor v13; // r6
  float v14; // r31
  int v15; // r4
  float v16; // r11
  char v17; // r11
  bfx::EdgeCursor v18; // [sp+50h] [-40h] BYREF
  float v19; // [sp+58h] [-38h]
  bfx::EdgeCursor v20; // [sp+60h] [-30h] BYREF
  float v21; // [sp+68h] [-28h]

  if ( (&unconnectedSideEdge->m_pArea[1].m_pProxy)[6 * unconnectedSideEdge->m_i] == nullptr )
  {
    m_pArea = unconnectedSideEdge->m_pArea;
    v18 = *unconnectedSideEdge;
    v18.m_i = (((unsigned int)(v18.m_i + 1)
              - __PAIR64__((unsigned int)(v18.m_i + 1) >> 31, v18.m_pArea->m_flags.m_flags1 & 0x7F)) >> 32)
            & (v18.m_i + 1);
    bfx::AdvanceClockwiseAroundVertFanAtEdgeStart(result: &v20, startEdge: &v18);
    v3 = v20.m_pArea;
    if ( v20.m_pArea != nullptr && v20.m_pArea != m_pArea && (v20.m_pArea->m_flags.m_flags1 & 0x80000000) != 0 )
    {
      m_i = v20.m_i;
      v5 = v20.m_pArea->m_flags.m_flags1 & 0x7F;
      v6 = unconnectedSideEdge->m_i;
      v7 = unconnectedSideEdge->m_pArea;
      v8 = &unconnectedSideEdge->m_pArea[1].m_dynAreaData + 6 * v6;
      v9 = __ROL4__(v20.m_i + 1, 1);
      v10 = (char *)v20.m_pArea + 24 * ((v20.m_i + 1) % v5);
      __twllei(v5, 0);
      v11 = v5 & ~(v9 - 1);
      v12 = *(float *)&v8[2].m_data;
      v13 = *(bfx::EdgeCursor *)&v8->m_data;
      __twlgei(v11, 0xFFFFFFFF);
      v14 = *((float *)v10 + 15);
      v15 = *((_DWORD *)v10 + 16);
      v16 = *((float *)v10 + 17);
      v18 = v13;
      *(float *)&v20.m_pArea = v14;
      v19 = v12;
      v20.m_i = v15;
      v21 = v16;
      if ( v14 != *(float *)&v13.m_pArea || *(float *)&v20.m_i != *(float *)&v18.m_i || (v17 = 1, v21 != v19) )
        v17 = 0;
      if ( v17 != 0 )
      {
        (&v7[1].m_pProxy)[6 * v6] = (bfx::AreaProxy *)v3;
        (&v3[1].m_pProxy)[6 * m_i] = (bfx::AreaProxy *)m_pArea;
      }
    }
  }
}


// ========================================================================
// ?CalcBBox@bfx@@YA?AVBox@1@ABVEdgeCursor@1@@Z
// EA  : 0x83273818
// RVA : 0x01273818
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

bfx::Box *__fastcall bfx::CalcBBox(bfx::Box *result, const bfx::EdgeCursor *edgeCursor)
{
  bfx::Area *m_pArea; // r11
  int m_i; // r10
  signed int v4; // r5
  float *v5; // r6
  unsigned int v6; // r9
  int v7; // r10
  float v8; // r8
  float v9; // r5
  float *v10; // r11
  float v11; // r4
  float v21; // [sp+0h] [-20h]
  float back_chain; // [sp+4h] [-1Ch]
  float v23; // [sp+8h] [-18h]
  float v24; // [sp+10h] [-10h]
  float v25; // [sp+14h] [-Ch]
  float v26; // [sp+18h] [-8h]

  m_pArea = edgeCursor->m_pArea;
  m_i = edgeCursor->m_i;
  v4 = edgeCursor->m_pArea->m_flags.m_flags1 & 0x7F;
  v5 = (float *)(&edgeCursor->m_pArea[1].m_dynAreaData + 6 * m_i);
  v6 = v4 & ~(__ROL4__(m_i + 1, 1) - 1);
  v8 = *((float *)&edgeCursor->m_pArea[1].m_pFirstLink + 6 * m_i);
  v7 = 24 * ((m_i + 1) % v4);
  __twllei(v4, 0);
  v9 = v5[2];
  v10 = (float *)((char *)m_pArea + v7);
  v11 = *v5;
  __twlgei(v6, 0xFFFFFFFF);
  _FP8 = (float)(v11 - v10[15]);
  _FP7 = (float)(v8 - v10[16]);
  _FP6 = (float)(v9 - v10[17]);
  __asm { fsel      f5, f8, f0, f13 }
  v21 = _FP5;
  __asm { fsel      f4, f8, f13, f0 }
  v24 = _FP4;
  result->m_max.m_x = v21;
  __asm { fsel      f3, f7, f12, f11 }
  back_chain = _FP3;
  __asm { fsel      f1, f6, f10, f9 }
  v23 = _FP1;
  __asm { fsel      f0, f7, f11, f12 }
  v25 = _FP0;
  __asm { fsel      f2, f6, f9, f10 }
  v26 = _FP2;
  result->m_min.m_x = v24;
  result->m_min.m_z = v26;
  result->m_min.m_y = v25;
  result->m_max.m_y = back_chain;
  result->m_max.m_z = v23;
  return result;
}


// ========================================================================
// ?CalcSphere@bfx@@YA?AVSphere@1@ABVEdgeCursor@1@@Z
// EA  : 0x83273930
// RVA : 0x01273930
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

bfx::Sphere *__fastcall bfx::CalcSphere(bfx::Sphere *result, const bfx::EdgeCursor *edgeCursor)
{
  bfx::Area *m_pArea; // r11
  int m_i; // r10
  signed int v4; // r4
  float *v5; // r9
  float v6; // r8
  float v7; // r7
  float *v8; // r11
  float v9; // r5
  float v10; // r9
  float v11; // [sp+0h] [-10h]
  float back_chain; // [sp+4h] [-Ch]

  m_pArea = edgeCursor->m_pArea;
  m_i = edgeCursor->m_i;
  v5 = (float *)((char *)edgeCursor->m_pArea + 24 * m_i);
  v4 = edgeCursor->m_pArea->m_flags.m_flags1 & 0x7F;
  v6 = v5[16];
  v7 = v5[15];
  v8 = (float *)((char *)m_pArea + 24 * ((m_i + 1) % v4));
  v9 = v5[17];
  __twllei(v4, 0);
  v10 = v8[17];
  __twlgei(v4 & ~(__ROL4__(m_i + 1, 1) - 1), 0xFFFFFFFF);
  back_chain = v8[16];
  v11 = v8[15];
  result->m_pos.m_y = (float)(v6 + back_chain) * (float)0.5;
  result->m_pos.m_x = (float)(v11 + v7) * (float)0.5;
  result->m_pos.m_z = (float)(v9 + v10) * (float)0.5;
  result->m_radius = __fsqrts((float)((float)((float)(v11 - v7) * (float)(v11 - v7))
                                    + (float)((float)((float)(v10 - v9) * (float)(v10 - v9))
                                            + (float)((float)(back_chain - v6) * (float)(back_chain - v6)))));
  return result;
}


// ========================================================================
// ?GetNavGraphUsingBinaryImage@Planner@bfx@@AAAPAVNavGraph@2@PBD@Z
// EA  : 0x83273A40
// RVA : 0x01273A40
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

bfx::NavGraph *__fastcall bfx::Planner::GetNavGraphUsingBinaryImage(bfx::Planner *this, const char *pBinaryImage)
{
  unsigned int v2; // r31
  bfx::NavLayer **m_layers; // r6
  int v4; // r5
  char *v5; // r4
  int m_i; // r11
  int m_endGraphIndex; // r9
  bfx::NavGraph *result; // r3
  bfx::NavGraph **v9; // r10
  bfx::NavLayerCC v10; // [sp+50h] [-20h] BYREF

  v2 = 0;
  m_layers = this->m_layers;
  v4 = -1;
  while ( 1 )
  {
    if ( *m_layers != nullptr )
    {
      v10.m_layer = *m_layers;
      v10.m_i = v4;
      bfx::NavLayerCC::IncToNextValid(this: &v10);
      m_i = v10.m_i;
      m_endGraphIndex = v10.m_layer->m_endGraphIndex;
      if ( v10.m_i < m_endGraphIndex )
        break;
    }
LABEL_10:
    ++v2;
    ++m_layers;
    if ( v2 >= 0x20 )
      return nullptr;
  }
  while ( 1 )
  {
    result = v10.m_layer->m_graphs[m_i];
    if ( v5 == result->m_binaryImage )
      return result;
    if ( ++m_i < m_endGraphIndex )
    {
      v9 = &v10.m_layer->m_graphs[m_i];
      do
      {
        if ( *v9 != nullptr )
          break;
        ++m_i;
        ++v9;
      }
      while ( m_i < m_endGraphIndex );
      if ( m_i < m_endGraphIndex )
        continue;
    }
    goto LABEL_10;
  }
}


// ========================================================================
// ?IncStaticCursor@ActiveAreasInSphereCursor@bfx@@AAAXXZ
// EA  : 0x83273B08
// RVA : 0x01273B08
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::ActiveAreasInSphereCursor::IncStaticCursor(bfx::ActiveAreasInSphereCursor *this)
{
  char *v2; // r11
  bfx::Array<bfx::Area *> *m_pArray; // r11
  int m_i; // r10
  int v5; // r11

  if ( this->m_staticAreaCursor.m_atEnd )
  {
    if ( this->m_allocatedAreasCC.m_i < this->m_allocatedAreasCC.m_pArray->m_size )
      ++this->m_allocatedAreasCC.m_i;
  }
  else
  {
    bfx::KDTree::PrimsInSphereCursor::TraverseToNextLeaf(this: &this->m_staticAreaCursor);
  }
  if ( this->m_staticAreaCursor.m_atEnd )
  {
    m_pArray = this->m_allocatedAreasCC.m_pArray;
    m_i = this->m_allocatedAreasCC.m_i;
    if ( m_i >= m_pArray->m_size )
      return;
    v2 = (char *)m_pArray->m_data[m_i];
  }
  else
  {
    v2 = &this->m_pNavGraph->m_binaryImage[**(_DWORD **)this->m_staticAreaCursor.m_pNextNode & 0x7FFFFFFF];
  }
  if ( v2 != nullptr )
  {
    v5 = *((_DWORD *)v2 + 1);
    if ( v5 != 0 && *(int *)v5 > 0 )
    {
      this->m_dynAreaCursor.m_numDynAreas = *(_DWORD *)v5;
      this->m_dynAreaCursor.m_pCurDynArea = (bfx::Area *)(v5 + 20);
      this->m_dynAreaCursor.m_i = 0;
    }
  }
}


// ========================================================================
// ?IncrementOnce@ActiveAreasInSphereCursor@bfx@@AAAXXZ
// EA  : 0x83273BF0
// RVA : 0x01273BF0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::ActiveAreasInSphereCursor::IncrementOnce(bfx::ActiveAreasInSphereCursor *this)
{
  char *v1; // r11
  bfx::Array<bfx::Area *> *m_pArray; // r11
  int m_i; // r10
  _DWORD *v4; // r11
  bfx::Area *m_pCurDynArea; // r10
  unsigned int m_flags1; // r9

  if ( this->m_staticAreaCursor.m_atEnd )
  {
    m_pArray = this->m_allocatedAreasCC.m_pArray;
    m_i = this->m_allocatedAreasCC.m_i;
    if ( m_i >= m_pArray->m_size )
      v1 = nullptr;
    else
      v1 = (char *)m_pArray->m_data[m_i];
  }
  else
  {
    v1 = &this->m_pNavGraph->m_binaryImage[**(_DWORD **)this->m_staticAreaCursor.m_pNextNode & 0x7FFFFFFF];
  }
  v4 = *((_DWORD **)v1 + 1);
  if ( v4 == nullptr
    || *v4 == 0
    || (m_pCurDynArea = this->m_dynAreaCursor.m_pCurDynArea,
        m_flags1 = m_pCurDynArea->m_flags.m_flags1,
        ++this->m_dynAreaCursor.m_i,
        this->m_dynAreaCursor.m_pCurDynArea = (bfx::Area *)((char *)m_pCurDynArea + 24 * (m_flags1 & 0x7F) + 72),
        this->m_dynAreaCursor.m_i == this->m_dynAreaCursor.m_numDynAreas) )
  {
    bfx::ActiveAreasInSphereCursor::IncStaticCursor(this);
  }
}


// ========================================================================
// ??DActiveAreasInSphereCursor@bfx@@QAAPAVArea@1@XZ
// EA  : 0x83273CB0
// RVA : 0x01273CB0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

bfx::Area *__fastcall bfx::ActiveAreasInSphereCursor::operator*(bfx::ActiveAreasInSphereCursor *this)
{
  char *v1; // r11
  bfx::Array<bfx::Area *> *m_pArray; // r11
  int m_i; // r10
  _DWORD *v4; // r10

  if ( this->m_staticAreaCursor.m_atEnd )
  {
    m_pArray = this->m_allocatedAreasCC.m_pArray;
    m_i = this->m_allocatedAreasCC.m_i;
    if ( m_i >= m_pArray->m_size )
      return nullptr;
    v1 = (char *)m_pArray->m_data[m_i];
  }
  else
  {
    v1 = &this->m_pNavGraph->m_binaryImage[**(_DWORD **)this->m_staticAreaCursor.m_pNextNode & 0x7FFFFFFF];
  }
  if ( v1 == nullptr )
    return nullptr;
  v4 = *((_DWORD **)v1 + 1);
  if ( v4 != nullptr && *v4 != 0 )
    return this->m_dynAreaCursor.m_pCurDynArea;
  else
    return (bfx::Area *)v1;
}


// ========================================================================
// ?RebuildBBox@NavGraph@bfx@@QAAXXZ
// EA  : 0x83273D38
// RVA : 0x01273D38
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::NavGraph::RebuildBBox(bfx::NavGraph *this)
{
  bfx::Box *p_m_bbox; // r30
  bfx::Array<bfx::Area *> *p_m_allocatedAreasOwned; // r28
  bfx::Vec3 *p_m_max; // r31
  int v4; // r29
  int v5; // r27
  double m_x; // fp11
  double v10; // fp10
  double m_y; // fp9
  bfx::Area v21; // [sp+50h] [-50h] BYREF

  p_m_bbox = &this->m_bbox;
  p_m_allocatedAreasOwned = &this->m_allocatedAreasOwned;
  p_m_max = &this->m_bbox.m_max;
  v4 = 0;
  this->m_bbox = this->m_pHeader->m_bbox;
  if ( this->m_allocatedAreasOwned.m_size > 0 )
  {
    v5 = 0;
    do
    {
      bfx::Area::CalcBBox(this: &v21, result: (bfx::Box *)p_m_allocatedAreasOwned->m_data[v5]);
      ++v4;
      ++v5;
      _FP6 = (float)(p_m_bbox->m_min.m_x - *(float *)&v21.m_pProxy);
      _FP4 = (float)(p_m_bbox->m_min.m_z - *(float *)&v21.m_pFirstLink);
      _FP3 = (float)(p_m_bbox->m_min.m_y - *(float *)&v21.m_dynAreaData.m_data);
      m_x = v21.m_pos.m_x;
      v10 = *(float *)&v21.m_pSearchParent;
      m_y = v21.m_pos.m_y;
      __asm { fsel      f2, f6, f0, f8 }
      p_m_bbox->m_min.m_x = _FP2;
      __asm { fsel      f1, f4, f13, f7 }
      p_m_bbox->m_min.m_z = _FP1;
      __asm { fsel      f0, f3, f12, f5 }
      p_m_bbox->m_min.m_y = _FP0;
      _FP6 = (float)(p_m_max->m_y - (float)m_x);
      _FP7 = (float)(p_m_max->m_x - (float)v10);
      _FP5 = (float)(p_m_max->m_z - (float)m_y);
      __asm { fsel      f4, f7, f8, f10 }
      p_m_max->m_x = _FP4;
      __asm { fsel      f3, f6, f13, f11 }
      p_m_max->m_y = _FP3;
      __asm { fsel      f2, f5, f12, f9 }
      p_m_max->m_z = _FP2;
    }
    while ( v4 < p_m_allocatedAreasOwned->m_size );
  }
}


// ========================================================================
// ?GetIndexOfAllocatedArea@NavGraph@bfx@@QAAHPAVArea@2@@Z
// EA  : 0x83273E40
// RVA : 0x01273E40
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

int __fastcall bfx::NavGraph::GetIndexOfAllocatedArea(bfx::NavGraph *this, bfx::Area *pAllocatedArea)
{
  int m_size; // r9
  int v3; // r10
  int i; // r11

  m_size = this->m_allocatedAreasOwned.m_size;
  v3 = 0;
  if ( m_size <= 0 )
    return 0;
  for ( i = 0; this->m_allocatedAreasOwned.m_data[i] != pAllocatedArea; ++i )
  {
    if ( ++v3 >= m_size )
      return 0;
  }
  return v3;
}


// ========================================================================
// ?GetIthAllocatedArea@NavGraph@bfx@@QAAPAVArea@2@H@Z
// EA  : 0x83273E88
// RVA : 0x01273E88
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

bfx::Area *__fastcall bfx::NavGraph::GetIthAllocatedArea(bfx::NavGraph *this, int index)
{
  if ( index < 0 || index >= this->m_allocatedAreasOwned.m_size )
    return nullptr;
  else
    return this->m_allocatedAreasOwned.m_data[index];
}


// ========================================================================
// ??0NavGraphSpatialOrganization@bfx@@QAA@XZ
// EA  : 0x83274380
// RVA : 0x01274380
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

bfx::NavGraphSpatialOrganization *__fastcall bfx::NavGraphSpatialOrganization::NavGraphSpatialOrganization(
        bfx::NavGraphSpatialOrganization *this)
{
  bfx::DynKDTree *v2; // r3
  bfx::DynKDTree *v3; // r3

  this->m_pNavLayer = nullptr;
  this->m_pNavLayerKDTree = nullptr;
  this->m_navGraphsNotInKDTree.m_tag = bfx::MEM_BFXPLANNER;
  this->m_navGraphsNotInKDTree.m_data = nullptr;
  this->m_navGraphsNotInKDTree.m_size = 0;
  this->m_navGraphsNotInKDTree.m_cap = 0;
  this->m_numNavGraphsNULLedOutInKDTree = 0;
  v2 = (bfx::DynKDTree *)bfx::MemoryManager::Malloc(
                           this: bfx::g_pCurInstance->m_pMemoryManager,
                           size: 0x1Cu,
                           tag: bfx::MEM_BFXPLANNER);
  if ( v2 != nullptr )
    v3 = bfx::DynKDTree::DynKDTree(this: v2);
  else
    v3 = nullptr;
  this->m_pNavLayerKDTree = v3;
  return this;
}


// ========================================================================
// __unwind$36924
// EA  : 0x83274408
// RVA : 0x01274408
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_36924()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 8));
}


// ========================================================================
// __unwind$36925
// EA  : 0x83274434
// RVA : 0x01274434
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_36925()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 128 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ??1NavGraphSpatialOrganization@bfx@@QAA@XZ
// EA  : 0x83274470
// RVA : 0x01274470
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::NavGraphSpatialOrganization::~NavGraphSpatialOrganization(bfx::NavGraphSpatialOrganization *this)
{
  char *m_pNavLayerKDTree; // r29
  char *m_data; // r4

  m_pNavLayerKDTree = (char *)this->m_pNavLayerKDTree;
  if ( m_pNavLayerKDTree != nullptr )
  {
    bfx::DynKDTree::~DynKDTree(this: this->m_pNavLayerKDTree);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pNavLayerKDTree);
  }
  this->m_pNavLayerKDTree = nullptr;
  m_data = (char *)this->m_navGraphsNotInKDTree.m_data;
  this->m_navGraphsNotInKDTree.m_size = 0;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_navGraphsNotInKDTree.m_data = nullptr;
  }
  this->m_navGraphsNotInKDTree.m_cap = 0;
}


// ========================================================================
// __unwind$36961
// EA  : 0x832744E4
// RVA : 0x012744E4
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_36961()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 8));
}


// ========================================================================
// ?RebuildNavLayerKDTree@NavGraphSpatialOrganization@bfx@@AAAXXZ
// EA  : 0x83274518
// RVA : 0x01274518
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::NavGraphSpatialOrganization::RebuildNavLayerKDTree(bfx::NavGraphSpatialOrganization *this)
{
  int m_numGraphs; // r4
  bfx::NavLayer *m_layer; // r28
  int m_i; // r29
  int v5; // r30
  double Scale; // fp1
  double v7; // fp12
  double v8; // fp11
  double v9; // fp10
  double v10; // fp7
  double v11; // fp6
  int v12; // ctr
  int *v13; // r10
  const bfx::bfxMemTag *p_m_tag; // r11
  int m_endGraphIndex; // r10
  bfx::NavGraph **v18; // r11
  char *m_pNavLayerKDTree; // r30
  bfx::NavLayer *v20; // r3
  bfx::DynKDTree *v21; // r3
  int v22; // r11
  int v23; // r10
  int m_areaExitIndex; // r8
  bfx::CornerFlavor m_cornerFlavor; // r7
  bfx::NavLayerCC v26; // [sp+50h] [-D0h] BYREF
  float v27; // [sp+58h] [-C8h]
  float v28; // [sp+5Ch] [-C4h]
  float v29; // [sp+60h] [-C0h]
  float v30; // [sp+68h] [-B8h]
  float v31; // [sp+6Ch] [-B4h]
  float v32; // [sp+70h] [-B0h]
  bfx::Array<bfx::SPCorner> v33; // [sp+80h] [-A0h] BYREF
  float v34; // [sp+90h] [-90h]
  float v35; // [sp+94h] [-8Ch]
  float v36; // [sp+98h] [-88h]
  float v37; // [sp+9Ch] [-84h]
  float v38; // [sp+A0h] [-80h]
  float v39; // [sp+A4h] [-7Ch]
  int v40; // [sp+ACh] [-74h] BYREF
  bfx::SPCorner v41; // [sp+B0h] [-70h] BYREF

  memset(&v33, 0, 12);
  v33.m_tag = bfx::MEM_BFXPLANNER;
  m_numGraphs = this->m_pNavLayer->m_numGraphs;
  if ( m_numGraphs > 0 )
    bfx::Array<bfx::GoalReachedData>::expand_cap(this: &v33, size: m_numGraphs);
  v26.m_layer = this->m_pNavLayer;
  v26.m_i = -1;
  bfx::NavLayerCC::IncToNextValid(this: &v26);
  m_layer = v26.m_layer;
  m_i = v26.m_i;
  if ( v26.m_i < v26.m_layer->m_endGraphIndex )
  {
    v41.m_cornerFlavor = LEFT_CORNER_FLAVOR;
    do
    {
      v5 = (int)m_layer->m_graphs[m_i];
      Scale = bfx::GetScale();
      v7 = *(float *)(v5 + 180);
      v8 = *(float *)(v5 + 172);
      v9 = *(float *)(v5 + 168);
      v10 = *(float *)(v5 + 176);
      v11 = *(float *)(v5 + 164);
      v12 = 6;
      v13 = &v40;
      p_m_tag = &v33.m_tag;
      _FP5 = (float)((float)((float)Scale * (float)2.0) - (float)(*(float *)(*(_DWORD *)(v5 + 16) + 20) * (float)5.0));
      __asm { fsel      f4, f5, f0, f8 }
      v29 = *(float *)(v5 + 184) + (float)_FP4;
      v26.m_layer = (bfx::NavLayer *)(v5 + 176);
      v28 = (float)v7 + (float)_FP4;
      v32 = (float)v8 - (float)_FP4;
      v31 = (float)v9 - (float)_FP4;
      v27 = (float)v10 + (float)_FP4;
      v30 = (float)v11 - (float)_FP4;
      v39 = v29;
      v34 = v30;
      v37 = v27;
      v38 = v28;
      v36 = v32;
      v35 = v31;
      do
      {
        *++v13 = *++p_m_tag;
        --v12;
      }
      while ( v12 != 0 );
      v41.m_areaExitIndex = v5;
      bfx::Array<bfx::SPCorner>::push_back(this: &v33, val: &v41);
      m_endGraphIndex = m_layer->m_endGraphIndex;
      if ( ++m_i >= m_endGraphIndex )
        break;
      v18 = &m_layer->m_graphs[m_i];
      do
      {
        if ( *v18 != nullptr )
          break;
        ++m_i;
        ++v18;
      }
      while ( m_i < m_endGraphIndex );
    }
    while ( m_i < m_endGraphIndex );
  }
  m_pNavLayerKDTree = (char *)this->m_pNavLayerKDTree;
  if ( m_pNavLayerKDTree != nullptr )
  {
    bfx::DynKDTree::~DynKDTree(this: this->m_pNavLayerKDTree);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pNavLayerKDTree);
  }
  v20 = (bfx::NavLayer *)bfx::MemoryManager::Malloc(
                           this: bfx::g_pCurInstance->m_pMemoryManager,
                           size: 0x1Cu,
                           tag: bfx::MEM_BFXPLANNER);
  v26.m_layer = v20;
  if ( v20 != nullptr )
    v21 = bfx::DynKDTree::DynKDTree(this: (bfx::DynKDTree *)v20);
  else
    v21 = nullptr;
  this->m_pNavLayerKDTree = v21;
  bfx::DynKDTree::BuildFromElems(this: v21, elems: (bfx::Array<bfx::KDBuildElem> *)&v33);
  v22 = 0;
  if ( v33.m_size > 0 )
  {
    v23 = 0;
    do
    {
      ++v22;
      m_areaExitIndex = v33.m_data[v23].m_areaExitIndex;
      m_cornerFlavor = v33.m_data[v23++].m_cornerFlavor;
      *(_DWORD *)(m_areaExitIndex + 188) = m_cornerFlavor;
    }
    while ( v22 < v33.m_size );
  }
  v33.m_size = 0;
  if ( v33.m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v33.m_data);
}


// ========================================================================
// __unwind$37018
// EA  : 0x83274790
// RVA : 0x01274790
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_37018()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 288 + 128));
}


// ========================================================================
// __unwind$37019
// EA  : 0x832747B8
// RVA : 0x012747B8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_37019()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 288 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?AddNavGraph@NavGraphSpatialOrganization@bfx@@QAAXPAVNavGraph@2@@Z
// EA  : 0x832747F0
// RVA : 0x012747F0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::NavGraphSpatialOrganization::AddNavGraph(
        bfx::NavGraphSpatialOrganization *this,
        bfx::Space *pNavGraph,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        bfx::Space *a14)
{
  int m_size; // r11

  m_size = this->m_navGraphsNotInKDTree.m_size;
  a14 = pNavGraph;
  if ( m_size >= 25 )
  {
    this->m_navGraphsNotInKDTree.m_size = 0;
    this->m_numNavGraphsNULLedOutInKDTree = 0;
    bfx::NavGraphSpatialOrganization::RebuildNavLayerKDTree(this);
  }
  else
  {
    bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)&this->m_navGraphsNotInKDTree, val: &a14);
  }
}


// ========================================================================
// ?GetBBox@NavGraphSpatialOrganization@bfx@@QBA?AVBox@2@XZ
// EA  : 0x83274848
// RVA : 0x01274848
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

bfx::NavGraphSpatialOrganization *__fastcall bfx::NavGraphSpatialOrganization::GetBBox(
        bfx::NavGraphSpatialOrganization *this,
        bfx::Box *result)
{
  float *p_m_size; // r30
  float m_y; // r4
  bfx::Box *BBox; // r3
  int v19; // r10
  int v20; // r9
  float *v21; // r11
  bfx::DynKDTree v35[2]; // [sp+50h] [-40h] BYREF

  p_m_size = (float *)&this->m_navGraphsNotInKDTree.m_size;
  this->m_pNavLayer = (bfx::NavLayer *)LODWORD(bfx::MAX_FLOAT_VEC.m_x);
  this->m_pNavLayerKDTree = (bfx::DynKDTree *)LODWORD(bfx::MAX_FLOAT_VEC.m_y);
  this->m_navGraphsNotInKDTree.m_data = (bfx::NavGraph **)LODWORD(bfx::MAX_FLOAT_VEC.m_z);
  *(bfx::Vec3 *)&this->m_navGraphsNotInKDTree.m_size = bfx::MIN_FLOAT_VEC;
  m_y = result->m_min.m_y;
  if ( *(_DWORD *)LODWORD(m_y) != 0 )
  {
    BBox = bfx::DynKDTree::GetBBox(this: v35, result: (bfx::Box *)LODWORD(m_y));
    _FP8 = (float)(*(float *)&this->m_pNavLayer - BBox->m_min.m_x);
    _FP9 = (float)(*(float *)&this->m_navGraphsNotInKDTree.m_data - BBox->m_min.m_z);
    _FP6 = (float)(*(float *)&this->m_pNavLayerKDTree - BBox->m_min.m_y);
    __asm { fsel      f4, f8, f10, f0 }
    *(float *)&this->m_pNavLayer = _FP4;
    __asm { fsel      f5, f9, f11, f13 }
    *(float *)&this->m_navGraphsNotInKDTree.m_data = _FP5;
    __asm { fsel      f3, f6, f7, f12 }
    *(float *)&this->m_pNavLayerKDTree = _FP3;
    _FP8 = (float)(p_m_size[1] - BBox->m_max.m_y);
    _FP10 = (float)(*p_m_size - BBox->m_max.m_x);
    _FP9 = (float)(p_m_size[2] - BBox->m_max.m_z);
    __asm { fsel      f5, f8, f1, f2 }
    p_m_size[1] = _FP5;
    __asm { fsel      f7, f10, f0, f11 }
    *p_m_size = _FP7;
    __asm { fsel      f6, f9, f13, f12 }
    p_m_size[2] = _FP6;
  }
  v19 = 0;
  if ( SLODWORD(result->m_max.m_x) > 0 )
  {
    v20 = 0;
    do
    {
      ++v19;
      v21 = *(float **)(LODWORD(result->m_min.m_z) + v20);
      v20 += 4;
      v21 += 41;
      _FP10 = (float)(*(float *)&this->m_pNavLayer - *v21);
      _FP7 = (float)(*(float *)&this->m_navGraphsNotInKDTree.m_data - v21[2]);
      _FP6 = (float)(*(float *)&this->m_pNavLayerKDTree - v21[1]);
      __asm { fsel      f5, f10, f11, f0 }
      *(float *)&this->m_pNavLayer = _FP5;
      __asm { fsel      f4, f7, f9, f13 }
      *(float *)&this->m_navGraphsNotInKDTree.m_data = _FP4;
      __asm { fsel      f3, f6, f8, f12 }
      *(float *)&this->m_pNavLayerKDTree = _FP3;
      _FP8 = (float)(p_m_size[1] - v21[4]);
      _FP10 = (float)(*p_m_size - v21[3]);
      _FP9 = (float)(p_m_size[2] - v21[5]);
      __asm { fsel      f5, f8, f2, f1 }
      p_m_size[1] = _FP5;
      __asm { fsel      f7, f10, f11, f0 }
      *p_m_size = _FP7;
      __asm { fsel      f6, f9, f12, f13 }
      p_m_size[2] = _FP6;
    }
    while ( v19 < SLODWORD(result->m_max.m_x) );
  }
  return this;
}


// ========================================================================
// ?AdvancedLinearCCToFirstNavGraphWithinConsiderationDistance@ClosestPrimsCursor@NavGraphSpatialOrganization@bfx@@AAAXXZ
// EA  : 0x832749F0
// RVA : 0x012749F0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::NavGraphSpatialOrganization::ClosestPrimsCursor::AdvancedLinearCCToFirstNavGraphWithinConsiderationDistance(
        bfx::NavGraphSpatialOrganization::ClosestPrimsCursor *this)
{
  bfx::Array<bfx::NavGraph *> *m_pArray; // r11
  int m_i; // r10
  bfx::Array<bfx::NavGraph *>::cursor *p_m_linearCC; // r31
  bfx::Vec3 *p_m_testPos; // r29
  int v6; // r10
  int v7; // r9

  m_pArray = this->m_linearCC.m_pArray;
  m_i = this->m_linearCC.m_i;
  p_m_linearCC = &this->m_linearCC;
  if ( m_i < m_pArray->m_size )
  {
    p_m_testPos = &this->m_testPos;
    v6 = m_i;
    do
    {
      if ( bfx::GetDistPtToBox(pos: p_m_testPos, box: &m_pArray->m_data[v6]->m_bbox) <= (double)this->m_considerationDist )
        break;
      ++p_m_linearCC->m_i;
      m_pArray = p_m_linearCC->m_pArray;
      v7 = p_m_linearCC->m_i;
      v6 = v7;
    }
    while ( v7 < p_m_linearCC->m_pArray->m_size );
  }
}


// ========================================================================
// ?InitDynCC@ActiveAreasCursor@bfx@@AAAXXZ
// EA  : 0x83274A70
// RVA : 0x01274A70
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::ActiveAreasCursor::InitDynCC(bfx::ActiveAreasCursor *this)
{
  char *m_pCur; // r11
  char *m_pEnd; // r9
  char v3; // r10
  char *v4; // r10
  int *v5; // r10
  int v6; // r11
  int v7; // r10

  m_pCur = this->m_staticCC.m_pCur;
  m_pEnd = this->m_staticCC.m_pEnd;
  if ( this->m_staticCC.m_pCur < m_pEnd || (v3 = 1, this->m_staticCC.m_cc.m_i < this->m_staticCC.m_cc.m_pArray->m_size) )
    v3 = 0;
  if ( v3 == 0 )
  {
    if ( m_pCur >= m_pEnd )
      v4 = (char *)this->m_staticCC.m_cc.m_pArray->m_data[this->m_staticCC.m_cc.m_i];
    else
      v4 = this->m_staticCC.m_pCur;
    v5 = *((int **)v4 + 1);
    if ( v5 != nullptr && *v5 > 0 )
    {
      if ( m_pCur >= m_pEnd )
        m_pCur = (char *)this->m_staticCC.m_cc.m_pArray->m_data[this->m_staticCC.m_cc.m_i];
      v6 = *((_DWORD *)m_pCur + 1);
      if ( v6 != 0 )
      {
        v7 = *(_DWORD *)v6;
        this->m_dynCC.m_pCurDynArea = (bfx::Area *)(v6 + 20);
        this->m_dynCC.m_i = 0;
        this->m_dynCC.m_numDynAreas = v7;
      }
      else
      {
        this->m_dynCC.m_pCurDynArea = nullptr;
        this->m_dynCC.m_numDynAreas = 0;
        this->m_dynCC.m_i = 0;
      }
    }
    else
    {
      this->m_dynCC.m_pCurDynArea = nullptr;
      this->m_dynCC.m_numDynAreas = 0;
      this->m_dynCC.m_i = 0;
    }
  }
}


// ========================================================================
// ?CollideLineSegmentAndNavGraph@NavGraph@bfx@@QAA_NABVVec3@2@0AAMAAPAVArea@2@@Z
// EA  : 0x83274B68
// RVA : 0x01274B68
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

int __fastcall bfx::NavGraph::CollideLineSegmentAndNavGraph(
        bfx::NavGraph *this,
        const bfx::Vec3 *startPos,
        const bfx::Vec3 *dir,
        float *collideDist,
        bfx::Area **pCollideAreaOut)
{
  int v10; // r3
  int v11; // r25
  bfx::Array<bfx::Area *> *m_pArray; // r28
  int m_i; // r29
  bfx::Area *m_pCurDynArea; // r30
  bfx::Area *v15; // r3
  char *m_data; // r11
  double m_z; // fp11
  float m_x; // r10
  double v19; // fp9
  float v20; // r9
  double m_y; // fp10
  double v22; // fp7
  double v23; // fp8
  double v24; // fp3
  double v25; // fp2
  double v26; // fp1
  char *v27; // r11
  bfx::AreaCollider v29; // [sp+50h] [-80h] BYREF
  float v30; // [sp+58h] [-78h]
  bfx::ActiveAreasInArrayCursor v31[5]; // [sp+60h] [-70h] BYREF

  v29.m_pNavGraph = this;
  v29.m_pCollideAreaOut = pCollideAreaOut;
  v10 = bfx::KDTree::CollideLineSegment<bfx::AreaCollider>(
          this: &this->m_kdtree,
          startWCoord: startPos,
          deltaWCoord: dir,
          primCollider: &v29,
          time: collideDist);
  v31[0].m_staticCC.m_i = 0;
  v11 = v10;
  v31[0].m_staticCC.m_pArray = &this->m_allocatedAreasOwned;
  v31[0].m_dynCC.m_pCurDynArea = nullptr;
  v31[0].m_dynCC.m_numDynAreas = 0;
  v31[0].m_dynCC.m_i = 0;
  bfx::ActiveAreasInArrayCursor::InitDynCC(this: v31);
  m_pArray = v31[0].m_staticCC.m_pArray;
  m_i = v31[0].m_staticCC.m_i;
  if ( v31[0].m_staticCC.m_i < v31[0].m_staticCC.m_pArray->m_size )
  {
    m_pCurDynArea = v31[0].m_dynCC.m_pCurDynArea;
    do
    {
      v15 = m_pArray->m_data[m_i];
      m_data = v15->m_dynAreaData.m_data;
      if ( m_data != nullptr && *(_DWORD *)m_data != 0 )
        v15 = m_pCurDynArea;
      m_z = startPos->m_z;
      m_x = v15->m_pos.m_x;
      v19 = dir->m_z;
      v20 = v15->m_pos.m_z;
      m_y = startPos->m_y;
      v22 = dir->m_y;
      v23 = startPos->m_x;
      v29.m_pCollideAreaOut = (bfx::Area **)LODWORD(v15->m_pos.m_y);
      *(float *)&v29.m_pNavGraph = m_x;
      v30 = v20;
      v24 = (float)(*(float *)&v29.m_pCollideAreaOut
                  - (float)((float)m_y
                          + (float)((float)v22
                                  * (float)((float)(dir->m_x * (float)(m_x - (float)v23))
                                          + (float)((float)((float)v22
                                                          * (float)(*(float *)&v29.m_pCollideAreaOut - (float)m_y))
                                                  + (float)((float)v19 * (float)(v20 - (float)m_z)))))));
      v25 = (float)(v20
                  - (float)((float)m_z
                          + (float)((float)v19
                                  * (float)((float)(dir->m_x * (float)(m_x - (float)v23))
                                          + (float)((float)((float)v22
                                                          * (float)(*(float *)&v29.m_pCollideAreaOut - (float)m_y))
                                                  + (float)((float)v19 * (float)(v20 - (float)m_z)))))));
      v26 = (float)(m_x
                  - (float)((float)v23
                          + (float)(dir->m_x
                                  * (float)((float)(dir->m_x * (float)(m_x - (float)v23))
                                          + (float)((float)((float)v22
                                                          * (float)(*(float *)&v29.m_pCollideAreaOut - (float)m_y))
                                                  + (float)((float)v19 * (float)(v20 - (float)m_z)))))));
      if ( (float)((float)((float)v26 * (float)v26)
                 + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))) <= (double)(float)(v15->m_radius * v15->m_radius) )
        v11 = (unsigned __int8)bfx::CollideLineSegmentAndArea(
                                 pArea: (bfx::Vec3 *)v15,
                                 start: startPos,
                                 dir,
                                 collideDist,
                                 (bfx::Vec3 **)pCollideAreaOut)
            | (unsigned __int8)v11;
      v27 = m_pArray->m_data[m_i]->m_dynAreaData.m_data;
      if ( v27 != nullptr && *(_DWORD *)v27 != 0 )
      {
        m_pCurDynArea = (bfx::Area *)((char *)m_pCurDynArea + 24 * (m_pCurDynArea->m_flags.m_flags1 & 0x7F) + 72);
        v31[0].m_dynCC.m_pCurDynArea = m_pCurDynArea;
        if ( ++v31[0].m_dynCC.m_i != v31[0].m_dynCC.m_numDynAreas )
          continue;
      }
      v31[0].m_staticCC.m_i = m_i + 1;
      bfx::ActiveAreasInArrayCursor::InitDynCC(this: v31);
      m_pArray = v31[0].m_staticCC.m_pArray;
      m_i = v31[0].m_staticCC.m_i;
      m_pCurDynArea = v31[0].m_dynCC.m_pCurDynArea;
    }
    while ( m_i < m_pArray->m_size );
  }
  return v11;
}


// ========================================================================
// ?CollideLineSegmentAndNavGraph@NavLayer@bfx@@QAA_NABVVec3@2@0AAMAAPAVArea@2@@Z
// EA  : 0x83274D60
// RVA : 0x01274D60
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

int __fastcall bfx::NavLayer::CollideLineSegmentAndNavGraph(
        bfx::NavLayer *this,
        const bfx::Vec3 *startPos,
        const bfx::Vec3 *dir,
        float *collideDist,
        bfx::Area **pCollideAreaOut)
{
  bfx::NavLayer *m_pNavLayer; // r11
  double v7; // fp8
  double m_z; // fp5
  int v12; // r27
  bfx::NavGraphSpatialOrganization *p_m_navGraphSpatialOrg; // r28
  double v14; // fp3
  bfx::NavGraph *v15; // r3
  char v16; // r3
  double v17; // fp8
  double v18; // fp5
  double v19; // fp4
  double v20; // fp3
  bfx::Vec3 v22; // [sp+50h] [-470h] BYREF
  bfx::DynKDTree::CollideLineSegmentCursor v23; // [sp+60h] [-460h] BYREF

  m_pNavLayer = this->m_navGraphSpatialOrg.m_pNavLayer;
  v7 = (float)(dir->m_z * *collideDist);
  m_z = startPos->m_z;
  v12 = 0;
  p_m_navGraphSpatialOrg = &this->m_navGraphSpatialOrg;
  v14 = (float)((float)(dir->m_y * *collideDist) + startPos->m_y);
  v22.m_x = startPos->m_x + (float)(dir->m_x * *collideDist);
  v22.m_y = v14;
  v22.m_z = (float)v7 + (float)m_z;
  if ( !m_pNavLayer->m_addRemoveNavGraphInProgress
    && (this->m_navGraphSpatialOrg.m_numNavGraphsNULLedOutInKDTree > 0
     || this->m_navGraphSpatialOrg.m_navGraphsNotInKDTree.m_size != 0) )
  {
    this->m_navGraphSpatialOrg.m_navGraphsNotInKDTree.m_size = 0;
    this->m_navGraphSpatialOrg.m_numNavGraphsNULLedOutInKDTree = 0;
    bfx::NavGraphSpatialOrganization::RebuildNavLayerKDTree(this: &this->m_navGraphSpatialOrg);
  }
  bfx::DynKDTree::CollideLineSegmentCursor::CollideLineSegmentCursor(
    this: &v23,
    startPos,
    endPos: &v22,
    pKDTree: p_m_navGraphSpatialOrg->m_pNavLayerKDTree);
  while ( !v23.m_atEnd )
  {
    v15 = (bfx::NavGraph *)bfx::DynKDTree::CollideLineSegmentCursor::operator*(this: &v23);
    v16 = bfx::NavGraph::CollideLineSegmentAndNavGraph(this: v15, startPos, dir, collideDist, pCollideAreaOut);
    v12 = (unsigned __int8)(v12 | v16);
    if ( v16 != 0 )
    {
      v17 = (float)(dir->m_z * *collideDist);
      v18 = startPos->m_z;
      v19 = (float)(startPos->m_x + (float)(dir->m_x * *collideDist));
      v20 = (float)((float)(dir->m_y * *collideDist) + startPos->m_y);
      v22.m_y = (float)(dir->m_y * *collideDist) + startPos->m_y;
      v22.m_x = v19;
      v22.m_z = (float)v17 + (float)v18;
      v23.m_endPos.m_x = v19;
      v23.m_endPos.m_y = v20;
      v23.m_endPos.m_z = v22.m_z;
    }
    bfx::DynKDTree::CollideLineSegmentCursor::TraverseToNextLeaf(this: &v23);
  }
  return v12;
}


// ========================================================================
// ?CollideLineSegmentAndNavGraph@Planner@bfx@@QAA_NABVVec3@2@0IAAMAAPAVArea@2@@Z
// EA  : 0x83274EC0
// RVA : 0x01274EC0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

int __fastcall bfx::Planner::CollideLineSegmentAndNavGraph(
        bfx::Planner *this,
        const bfx::Vec3 *startPos,
        const bfx::Vec3 *dir,
        unsigned int layerNum,
        float *collideDist,
        bfx::Area **pCollideAreaOut)
{
  bfx::NavLayer *v6; // r3

  if ( layerNum < 0x20 && (v6 = this->m_layers[layerNum]) != nullptr )
    return bfx::NavLayer::CollideLineSegmentAndNavGraph(this: v6, startPos, dir, collideDist, pCollideAreaOut);
  else
    return 0;
}


// ========================================================================
// ?GetStaticPortalAreasOverlappingBBoxes@NavGraph@bfx@@QAAXABV?$Array@VBox@bfx@@@2@AAV?$Array@PAVArea@bfx@@@2@@Z
// EA  : 0x83274EF8
// RVA : 0x01274EF8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::NavGraph::GetStaticPortalAreasOverlappingBBoxes(
        bfx::NavGraph *this,
        const bfx::Array<bfx::Box> *bboxes,
        bfx::Array<bfx::SpaceComponent *> *staticPortalAreasOut)
{
  bfx::Array<bfx::Area *> *p_m_staticPortalAreas; // r25
  int v6; // r24
  int v7; // r26
  int v8; // r30
  int m_size; // r10
  bfx::Area *v10; // r29
  float m_y; // r8
  float m_z; // r7
  double v13; // fp31
  int v14; // r31
  int m_cap; // r10
  int v16; // r11
  int v17; // r4
  bfx::Area **v18; // r11
  bool v19; // cr34
  bfx::Vec3 v20; // [sp+50h] [-60h] BYREF

  if ( bboxes->m_size != 0 )
  {
    p_m_staticPortalAreas = &this->m_staticPortalAreas;
    v6 = 0;
    if ( this->m_staticPortalAreas.m_size > 0 )
    {
      v7 = 0;
      do
      {
        v8 = 0;
        m_size = bboxes->m_size;
        v10 = p_m_staticPortalAreas->m_data[v7];
        m_y = v10->m_pos.m_y;
        m_z = v10->m_pos.m_z;
        v20.m_x = v10->m_pos.m_x;
        v20.m_y = m_y;
        v20.m_z = m_z;
        v13 = (float)(v10->m_radius * v10->m_radius);
        if ( m_size > 0 )
        {
          v14 = 0;
          while ( bfx::GetDistPtToBoxSq(pos: &v20, box: &bboxes->m_data[v14]) > v13 )
          {
            ++v8;
            ++v14;
            if ( v8 >= bboxes->m_size )
              goto LABEL_17;
          }
          m_cap = staticPortalAreasOut->m_cap;
          v16 = staticPortalAreasOut->m_size;
          if ( m_cap == v16 )
          {
            v17 = 2 * m_cap;
            if ( m_cap == 0 )
              v17 = 1;
            bfx::Array<bfx::Edge *>::expand_cap(this: staticPortalAreasOut, size: v17);
            v18 = (bfx::Area **)&staticPortalAreasOut->m_data[staticPortalAreasOut->m_size];
            v19 = v18 == nullptr;
          }
          else
          {
            v18 = (bfx::Area **)&staticPortalAreasOut->m_data[v16];
            v19 = v18 == nullptr;
          }
          if ( !v19 )
            *v18 = v10;
          ++staticPortalAreasOut->m_size;
        }
LABEL_17:
        ++v6;
        ++v7;
      }
      while ( v6 < p_m_staticPortalAreas->m_size );
    }
  }
}


// ========================================================================
// ?CreateAllocatedArea@bfx@@YAPAVArea@1@QBVVec3@1@HHIHII@Z
// EA  : 0x83275028
// RVA : 0x01275028
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

bfx::Area *__fastcall bfx::CreateAllocatedArea(
        const bfx::Vec3 *vertArray,
        int numVerts,
        unsigned int islandNumA,
        int planLayer,
        unsigned int graphIndex,
        unsigned int userData,
        unsigned int staticCostMult)
{
  int v8; // r30
  bfx::Area *result; // r3
  bfx::Area *v15; // r29
  double v16; // fp31
  int v17; // r5
  int v18; // r3
  unsigned int v19; // r9
  bfx::Area *v20; // r11
  const bfx::Vec3 *v21; // r10
  int v22; // [sp+8h] [-D8h]
  int v23; // [sp+Ch] [-D4h]
  int v24; // [sp+10h] [-D0h]
  int v25; // [sp+14h] [-CCh]
  int v26; // [sp+18h] [-C8h]
  int v27; // [sp+1Ch] [-C4h]
  int v28; // [sp+20h] [-C0h]
  int v29; // [sp+24h] [-BCh]
  int v30; // [sp+28h] [-B8h]
  int v31; // [sp+2Ch] [-B4h]
  int v32; // [sp+30h] [-B0h]
  int v33; // [sp+34h] [-ACh]
  int v34; // [sp+38h] [-A8h]
  int v35; // [sp+3Ch] [-A4h]
  int v36; // [sp+40h] [-A0h]
  int v37; // [sp+44h] [-9Ch]
  int v38; // [sp+48h] [-98h]
  int v39; // [sp+4Ch] [-94h]
  int v40; // [sp+50h] [-90h]
  int v41; // [sp+58h] [-88h]
  bfx::Vec3 v42[2]; // [sp+68h] [-78h] BYREF

  v8 = numVerts;
  if ( numVerts < 3 )
    return nullptr;
  v15 = (bfx::Area *)bfx::MemoryManager::Malloc(
                       this: bfx::g_pCurInstance->m_pMemoryManager,
                       size: 24 * numVerts + 56,
                       tag: bfx::MEM_BFXPLANNER);
  bfx::CalcCentroidOfConvexPolygon(result: v42, vertArray, numVerts: v8);
  v16 = bfx::CalcRadiusOfPolygon(vertArray, numVerts: v8, centerPos: v42);
  v18 = bfx::CalcBasisVert(vertArray, numVerts: v8);
  if ( v15 != nullptr )
    result = bfx::Area::Area(
               this: v15,
               pos: v42,
               radius: v16,
               numEdges: v17,
               full3D: v8,
               island: 0,
               layerIndex: islandNumA,
               graphIndex: planLayer,
               usageFlags: graphIndex,
               basisVert: v22,
               a11: v23,
               a12: v24,
               a13: v25,
               a14: v26,
               a15: v27,
               a16: v28,
               a17: v29,
               a18: v30,
               a19: v31,
               a20: v32,
               a21: v33,
               a22: v34,
               a23: v35,
               a24: v36,
               a25: v37,
               a26: v38,
               a27: v39,
               a28: v40,
               a29: userData,
               a30: v41,
               a31: v18);
  else
    result = nullptr;
  result->m_flags.m_flags1 |= 0x80000000;
  if ( staticCostMult <= 0xF )
  {
    v19 = 1;
    if ( staticCostMult != 0 )
      v19 = staticCostMult;
  }
  else
  {
    v19 = 15;
  }
  v20 = v15 + 1;
  result->m_flags.m_flags2 = (v19 << 20) & 0xF00000 | result->m_flags.m_flags2 & 0xFF0FFFFF;
  if ( v8 > 0 )
  {
    v21 = vertArray;
    do
    {
      if ( v20 != nullptr )
      {
        v20->m_pProxy = nullptr;
        v20->m_dynAreaData.m_data = (char *)LODWORD(v21->m_x);
        v20->m_pFirstLink = (bfx::HalfLink *)LODWORD(v21->m_y);
        v20->m_pSearchParent = (bfx::Area *)LODWORD(v21->m_z);
        v20->m_pos.m_y = 0.0;
        v20->m_pos.m_x = NAN;
      }
      --v8;
      v20 = (bfx::Area *)((char *)v20 + 24);
      ++v21;
    }
    while ( v8 != 0 );
  }
  return result;
}


// ========================================================================
// __unwind$38495
// EA  : 0x832751A8
// RVA : 0x012751A8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_38495()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 224 + 100));
}


// ========================================================================
// ?GetOtherNavGraphExpandedBBoxes@bfx@@YAXPAVNavGraph@1@ABV?$Array@PAVNavGraph@bfx@@@1@MAAV?$Array@VBox@bfx@@@1@@Z
// EA  : 0x832751D8
// RVA : 0x012751D8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::GetOtherNavGraphExpandedBBoxes(
        bfx::NavGraph *pExceptionNavGraph,
        const bfx::Array<bfx::NavGraph *> *nearbyNavGraphs,
        double maxPortalCreationDist,
        bfx::Array<bfx::Box> *bboxesOut,
        bfx::Array<bfx::BinaryHeap<bfx::OpenNode3D,float>::Node> *a5)
{
  int m_size; // r4
  int v10; // r29
  int v11; // r31
  bfx::NavGraph *v12; // r11
  float v13; // r9
  bfx::PortalDirection v14; // r8
  float v15; // r7
  float v16; // r6
  unsigned int v17; // r5
  bfx::BinaryHeap<bfx::OpenNode3D,float>::Node v18; // [sp+70h] [-50h] BYREF

  m_size = nearbyNavGraphs->m_size;
  if ( m_size > a5->m_cap )
    bfx::Array<bfx::PortalSubdivElem>::expand_cap(this: a5, size: m_size);
  v10 = 0;
  if ( nearbyNavGraphs->m_size > 0 )
  {
    v11 = 0;
    do
    {
      v12 = nearbyNavGraphs->m_data[v11];
      if ( v12 != pExceptionNavGraph )
      {
        v13 = v12->m_bbox.m_min.m_x - (float)maxPortalCreationDist;
        *(float *)&v14 = v12->m_bbox.m_min.m_y - (float)maxPortalCreationDist;
        v15 = v12->m_bbox.m_min.m_z - (float)maxPortalCreationDist;
        v16 = v12->m_bbox.m_max.m_x + (float)maxPortalCreationDist;
        *(float *)&v17 = v12->m_bbox.m_max.m_y + (float)maxPortalCreationDist;
        v18.m_priority = v12->m_bbox.m_max.m_z + (float)maxPortalCreationDist;
        v18.m_elem.m_parentIdx = v17;
        v18.m_elem.m_searchCost = v16;
        *(float *)&v18.m_elem.m_pPortal = v13;
        v18.m_elem.m_dir = v14;
        *(float *)&v18.m_elem.m_pointID = v15;
        bfx::Array<bfx::Box>::push_back(this: a5, val: &v18);
      }
      ++v10;
      ++v11;
    }
    while ( v10 < nearbyNavGraphs->m_size );
  }
}


// ========================================================================
// ?GenerateOverlapsForEdge@bfx@@YAXABVEdgeCursor@1@PBVDynKDTree@1@MAAV?$Array@VOverlapData@bfx@@@1@@Z
// EA  : 0x832752E0
// RVA : 0x012752E0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::GenerateOverlapsForEdge(
        const bfx::EdgeCursor *myEdgeCC,
        const bfx::DynKDTree *pTheirPortalEdgesKDTree,
        double maxPortalCreationDist,
        bfx::Array<bfx::OverlapData> *overlapDataOut,
        bfx::Array<bfx::ReplayPlayer::Registration> *a5)
{
  double Scale; // fp1
  double v10; // fp30
  double v11; // fp29
  double DefaultMinEdgeLength; // fp1
  double v13; // fp25
  bfx::Vec3 **v14; // r3
  bfx::Area *m_pArea; // r11
  int m_i; // r10
  bfx::Vec3 **v17; // r31
  signed int v18; // r3
  float *v19; // r7
  float v20; // r8
  float v21; // r6
  float *v22; // r11
  float v23; // r7
  float v24; // r10
  float v25; // r9
  float v26; // r11
  bfx::Vec3 *v27; // r10
  signed int v28; // r6
  int v29; // r26
  float *p_m_x; // r11
  float v31; // r9
  float m_y; // r8
  float v33; // r6
  float v34; // r10
  float v35; // r7
  float v36; // r11
  double v37; // fp26
  double v38; // fp31
  double v39; // fp0
  double v40; // fp13
  bfx::Area *v45; // r3
  bfx::Area *v46; // r3
  double DistBetweenLineSegs; // fp1
  bfx::EdgeCursor v48; // r11
  bfx::LineSeg v51; // [sp+50h] [-5A0h] BYREF
  bfx::LineSeg v52; // [sp+70h] [-580h] BYREF
  bfx::LineSeg v53; // [sp+90h] [-560h] BYREF
  bfx::Vec3 v54; // [sp+A8h] [-548h] BYREF
  bfx::Vec3 v55; // [sp+B8h] [-538h] BYREF
  bfx::Vec3 v56; // [sp+C8h] [-528h] BYREF
  bfx::Vec3 v57; // [sp+D8h] [-518h] BYREF
  bfx::LineSeg v58; // [sp+F0h] [-500h] BYREF
  bfx::Sphere v59; // [sp+110h] [-4E0h] BYREF
  bfx::ReplayPlayer::Registration v60; // [sp+120h] [-4D0h] BYREF
  bfx::Area v61[19]; // [sp+138h] [-4B8h] BYREF
  char v62; // [sp+574h] [-7Ch]

  Scale = bfx::GetScale();
  v10 = (float)((float)maxPortalCreationDist * (float)maxPortalCreationDist);
  v11 = (float)((float)((float)Scale * (float)0.0099999998) * (float)((float)Scale * (float)0.0099999998));
  DefaultMinEdgeLength = bfx::GetDefaultMinEdgeLength();
  v13 = (float)((float)DefaultMinEdgeLength * (float)DefaultMinEdgeLength);
  bfx::CalcSphere(result: &v59, edgeCursor: myEdgeCC);
  v59.m_radius = v59.m_radius + (float)maxPortalCreationDist;
  bfx::DynKDTree::PrimsInSphereCursor::PrimsInSphereCursor(
    this: (bfx::DynKDTree::PrimsInSphereCursor *)&v61[0].m_flags,
    sphere: &v59,
    pKDTree: pTheirPortalEdgesKDTree);
  while ( v62 == 0 )
  {
    v14 = (bfx::Vec3 **)bfx::DynKDTree::PrimsInSphereCursor::operator*(this: (bfx::DynKDTree::PrimsInSphereCursor *)&v61[0].m_flags);
    m_pArea = myEdgeCC->m_pArea;
    m_i = myEdgeCC->m_i;
    v17 = v14;
    v18 = myEdgeCC->m_pArea->m_flags.m_flags1 & 0x7F;
    v19 = (float *)(&myEdgeCC->m_pArea[1].m_dynAreaData + 6 * m_i);
    v20 = *v19;
    __twlgei(v18 & ~(__ROL4__(m_i + 1, 1) - 1), 0xFFFFFFFF);
    v21 = v19[1];
    v22 = (float *)((char *)m_pArea + 24 * ((m_i + 1) % v18));
    v23 = v19[2];
    __twllei(v18, 0);
    v24 = v22[15];
    v25 = v22[16];
    v26 = v22[17];
    v53.m_v0.m_x = v20;
    v53.m_v0.m_z = v23;
    v53.m_v1.m_x = v24;
    v53.m_v1.m_y = v25;
    v53.m_v0.m_y = v21;
    v53.m_v1.m_z = v26;
    v27 = v17[1];
    v28 = LODWORD((*v17)[3].m_y) & 0x7F;
    v29 = (int)&(*v17)[2 * (int)v27 + 5];
    p_m_x = &(*v17)[2 * (((int)&v27->m_x + 1) % v28)].m_x;
    v31 = *(float *)v29;
    m_y = (*v17)[2 * (int)v27 + 5].m_y;
    __twlgei(v28 & ~(__ROL4__((char *)&v27->m_x + 1, 1) - 1), 0xFFFFFFFF);
    __twllei(v28, 0);
    v33 = *(float *)(v29 + 8);
    v34 = p_m_x[15];
    v35 = p_m_x[16];
    v36 = p_m_x[17];
    v51.m_v0.m_x = v31;
    v51.m_v0.m_y = m_y;
    v51.m_v0.m_z = v33;
    v51.m_v1.m_x = v34;
    v51.m_v1.m_y = v35;
    v51.m_v1.m_z = v36;
    bfx::GetClosestPtOnLineSeg(result: &v55, seg: &v53, pos: &v51.m_v0);
    bfx::GetClosestPtOnLineSeg(result: &v57, seg: &v53, pos: &v51.m_v1);
    v52.m_v0 = v57;
    v52.m_v1 = v55;
    v37 = (float)((float)((float)(v55.m_x - v57.m_x) * (float)(v55.m_x - v57.m_x))
                + (float)((float)((float)(v55.m_z - v57.m_z) * (float)(v55.m_z - v57.m_z))
                        + (float)((float)(v55.m_y - v57.m_y) * (float)(v55.m_y - v57.m_y))));
    if ( v37 >= v11 )
    {
      bfx::GetClosestPtOnLineSeg(result: &v54, seg: &v51, pos: &v53.m_v0);
      bfx::GetClosestPtOnLineSeg(result: &v56, seg: &v51, pos: &v53.m_v1);
      v58.m_v0 = v56;
      v58.m_v1 = v54;
      v38 = (float)((float)((float)(v54.m_x - v56.m_x) * (float)(v54.m_x - v56.m_x))
                  + (float)((float)((float)(v54.m_z - v56.m_z) * (float)(v54.m_z - v56.m_z))
                          + (float)((float)(v54.m_y - v56.m_y) * (float)(v54.m_y - v56.m_y))));
      if ( v38 >= v11 )
      {
        v39 = (float)((float)((float)(v52.m_v0.m_x - v54.m_x) * (float)(v52.m_v0.m_x - v54.m_x))
                    + (float)((float)((float)(v52.m_v0.m_z - v54.m_z) * (float)(v52.m_v0.m_z - v54.m_z))
                            + (float)((float)(v52.m_v0.m_y - v54.m_y) * (float)(v52.m_v0.m_y - v54.m_y))));
        v40 = (float)((float)((float)(v52.m_v1.m_x - v56.m_x) * (float)(v52.m_v1.m_x - v56.m_x))
                    + (float)((float)((float)(v52.m_v1.m_z - v56.m_z) * (float)(v52.m_v1.m_z - v56.m_z))
                            + (float)((float)(v52.m_v1.m_y - v56.m_y) * (float)(v52.m_v1.m_y - v56.m_y))));
        if ( (v39 <= v10 || v40 <= v10) && v39 > v13 && v40 > v13 )
        {
          _FP2 = (float)((float)__fsqrts((float)((float)((float)(v51.m_v1.m_x - v51.m_v0.m_x)
                                                       * (float)(v51.m_v1.m_x - v51.m_v0.m_x))
                                               + (float)((float)((float)(v51.m_v1.m_z - v51.m_v0.m_z)
                                                               * (float)(v51.m_v1.m_z - v51.m_v0.m_z))
                                                       + (float)((float)(v51.m_v1.m_y - v51.m_v0.m_y)
                                                               * (float)(v51.m_v1.m_y - v51.m_v0.m_y)))))
                       - 1.0842022e-19);
          _FP0 = (float)((float)__fsqrts((float)((float)((float)(v53.m_v1.m_x - v53.m_v0.m_x)
                                                       * (float)(v53.m_v1.m_x - v53.m_v0.m_x))
                                               + (float)((float)((float)(v53.m_v1.m_z - v53.m_v0.m_z)
                                                               * (float)(v53.m_v1.m_z - v53.m_v0.m_z))
                                                       + (float)((float)(v53.m_v1.m_y - v53.m_v0.m_y)
                                                               * (float)(v53.m_v1.m_y - v53.m_v0.m_y)))))
                       - 1.0842022e-19);
          __asm
          {
            fsel      f10, f2, f1, f28
            fsel      f8, f0, f13, f28
          }
          if ( (float)((float)((float)((float)(v53.m_v1.m_x - v53.m_v0.m_x) * (float)_FP8)
                             * (float)((float)(v51.m_v1.m_x - v51.m_v0.m_x) * (float)_FP10))
                     + (float)((float)((float)((float)(v53.m_v1.m_z - v53.m_v0.m_z) * (float)_FP8)
                                     * (float)((float)(v51.m_v1.m_z - v51.m_v0.m_z) * (float)_FP10))
                             + (float)((float)((float)(v53.m_v1.m_y - v53.m_v0.m_y) * (float)_FP8)
                                     * (float)((float)(v51.m_v1.m_y - v51.m_v0.m_y) * (float)_FP10)))) < -MAX_PORTAL_CONNECTION_DIVERGENCE_ANGLE )
          {
            v45 = bfx::Area::CalcNormal(this: (bfx::Area *)&v61[0].m_pos, result: (bfx::Vec3 *)myEdgeCC->m_pArea);
            if ( bfx::PortalSurfaceOrientationOk(segA: &v52, segB: &v58, areaANormal: (const bfx::Vec3 *)v45) )
            {
              v46 = bfx::Area::CalcNormal(this: v61, result: *v17);
              if ( bfx::PortalSurfaceOrientationOk(segA: &v58, segB: &v52, areaANormal: (const bfx::Vec3 *)v46) )
              {
                DistBetweenLineSegs = bfx::GetDistBetweenLineSegs(
                                        startA: &v52.m_v0,
                                        endA: &v52.m_v1,
                                        startB: &v58.m_v0,
                                        endB: &v58.m_v1);
                v48 = *myEdgeCC;
                *(_QWORD *)&v60.m_clearCB = *(_QWORD *)v17;
                v48.m_pArea = (bfx::Area *)v60.m_getNameCB;
                *(bfx::EdgeCursor *)&v60.m_id = v48;
                _FP0 = (float)((float)__fsqrts(v37) - (float)__fsqrts(v38));
                __asm { fsel      f13, f0, f31, f26 }
                v60.m_priority = -(float)((float)((float)DistBetweenLineSegs * (float)0.5) - (float)_FP13);
                bfx::Array<bfx::ReplayPlayer::Registration>::push_back(this: a5, val: &v60);
              }
            }
          }
        }
      }
    }
    bfx::DynKDTree::PrimsInSphereCursor::TraverseToNextLeaf(this: (bfx::DynKDTree::PrimsInSphereCursor *)&v61[0].m_flags);
  }
}


// ========================================================================
// ?GenerateOverlapData@bfx@@YAXABV?$Array@VEdgeCursor@bfx@@@1@0MAAV?$Array@VOverlapData@bfx@@@1@@Z
// EA  : 0x83275798
// RVA : 0x01275798
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::GenerateOverlapData(
        const bfx::Array<bfx::EdgeCursor> *myPortalEdges,
        const bfx::Array<bfx::EdgeCursor> *theirPortalEdges,
        double maxPortalCreationDist,
        bfx::Array<bfx::OverlapData> *overlapDataOut,
        bfx::Array<bfx::ReplayPlayer::Registration> *a5)
{
  int m_size; // r4
  int v10; // r27
  int v11; // r28
  const bfx::EdgeCursor *v12; // r30
  bfx::Box *v13; // r3
  int *v14; // r10
  _DWORD *p_m_z; // r9
  int i; // ctr
  bfx::Array<bfx::OverlapData> *v17; // r5
  int v18; // r29
  int v19; // r30
  bfx::Array<bfx::SPCorner> v20; // [sp+50h] [-C0h] BYREF
  bfx::Box v21; // [sp+60h] [-B0h] BYREF
  bfx::DynKDTree v22; // [sp+80h] [-90h] BYREF
  int v23; // [sp+9Ch] [-74h] BYREF
  bfx::SPCorner v24; // [sp+A0h] [-70h] BYREF

  memset(&v20, 0, 12);
  v20.m_tag = bfx::MEM_BFXPLANNER;
  m_size = theirPortalEdges->m_size;
  if ( m_size > 0 )
    bfx::Array<bfx::GoalReachedData>::expand_cap(this: &v20, size: m_size);
  v10 = 0;
  if ( theirPortalEdges->m_size > 0 )
  {
    v11 = 0;
    v24.m_cornerFlavor = LEFT_CORNER_FLAVOR;
    do
    {
      v12 = &theirPortalEdges->m_data[v11];
      v13 = bfx::CalcBBox(result: &v21, edgeCursor: v12);
      v14 = &v23;
      p_m_z = (_DWORD *)&v13[-1].m_max.m_z;
      for ( i = 6; i != 0; --i )
        *++v14 = *++p_m_z;
      v24.m_areaExitIndex = (int)v12;
      bfx::Array<bfx::SPCorner>::push_back(this: &v20, val: &v24);
      ++v10;
      ++v11;
    }
    while ( v10 < theirPortalEdges->m_size );
  }
  bfx::DynKDTree::DynKDTree(this: &v22);
  bfx::DynKDTree::BuildFromElems(this: &v22, elems: (bfx::Array<bfx::KDBuildElem> *)&v20);
  if ( a5->m_cap < 100 )
    bfx::Array<bfx::OverlapData>::expand_cap(this: a5, size: 100);
  v18 = 0;
  if ( myPortalEdges->m_size > 0 )
  {
    v19 = 0;
    do
    {
      bfx::GenerateOverlapsForEdge(
        myEdgeCC: &myPortalEdges->m_data[v19],
        pTheirPortalEdgesKDTree: &v22,
        maxPortalCreationDist,
        overlapDataOut: v17,
        a5);
      ++v18;
      ++v19;
    }
    while ( v18 < myPortalEdges->m_size );
  }
  bfx::DynKDTree::~DynKDTree(this: &v22);
  v20.m_size = 0;
  if ( v20.m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v20.m_data);
}


// ========================================================================
// __unwind$39091
// EA  : 0x832758F8
// RVA : 0x012758F8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_39091()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 272 + 80));
}


// ========================================================================
// __unwind$39092
// EA  : 0x83275920
// RVA : 0x01275920
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_39092()
{
  int v0; // r12

  bfx::DynKDTree::~DynKDTree(this: (bfx::DynKDTree *)(v0 - 272 + 128));
}


// ========================================================================
// ?GetUnconnectedPortalEdges@bfx@@YAXAAV?$Array@PAVArea@bfx@@@1@AAV?$Array@VEdgeCursor@bfx@@@1@@Z
// EA  : 0x83275948
// RVA : 0x01275948
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::GetUnconnectedPortalEdges(
        bfx::Array<bfx::Area *> *staticPortalAreas,
        bfx::Array<bfx::ReplayLogListenerEntry> *portalEdgesOut)
{
  bfx::Array<bfx::Area *> *m_pArray; // r26
  int m_i; // r27
  bfx::Area *m_pCurDynArea; // r28
  bfx::ReplayListener *v6; // r11
  bfx::ReplayListener_vtbl *v7; // r10
  bfx::ReplayListener *v8; // r30
  bfx::ReplayListener_vtbl *v9; // r11
  int v10; // r31
  bfx::ReplayListener *v11; // r11
  int v12; // r10
  char *m_data; // r11
  bfx::ReplayLogListenerEntry v14; // [sp+50h] [-70h] BYREF
  bfx::ActiveAreasInArrayCursor v15[4]; // [sp+60h] [-60h] BYREF

  v15[0].m_staticCC.m_pArray = staticPortalAreas;
  v15[0].m_staticCC.m_i = 0;
  v15[0].m_dynCC.m_pCurDynArea = nullptr;
  v15[0].m_dynCC.m_numDynAreas = 0;
  v15[0].m_dynCC.m_i = 0;
  bfx::ActiveAreasInArrayCursor::InitDynCC(this: v15);
  m_pArray = v15[0].m_staticCC.m_pArray;
  m_i = v15[0].m_staticCC.m_i;
  if ( v15[0].m_staticCC.m_i < v15[0].m_staticCC.m_pArray->m_size )
  {
    m_pCurDynArea = v15[0].m_dynCC.m_pCurDynArea;
    do
    {
      v6 = (bfx::ReplayListener *)m_pArray->m_data[m_i];
      v7 = v6[1].__vftable;
      if ( v7 != nullptr && v7->dtr_ReplayListener != nullptr )
        v6 = (bfx::ReplayListener *)m_pCurDynArea;
      v8 = v6;
      v14.m_pListener = v6;
      v9 = v6[10].__vftable;
      v10 = 0;
      *(_DWORD *)&v14.m_clientOwned = 0;
      if ( ((unsigned __int8)v9 & 0x7F) != 0 )
      {
        do
        {
          v11 = &v8[6 * v10];
          if ( ((int)v11[18].__vftable & 0x6000) == 0x2000 && v11[14].__vftable == nullptr )
            bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(this: portalEdgesOut, val: &v14);
          ++v10;
          v12 = (int)v8[10].__vftable & 0x7F;
          *(_DWORD *)&v14.m_clientOwned = v10;
        }
        while ( v10 < v12 );
      }
      m_data = m_pArray->m_data[m_i]->m_dynAreaData.m_data;
      if ( m_data != nullptr && *(_DWORD *)m_data != 0 )
      {
        m_pCurDynArea = (bfx::Area *)((char *)m_pCurDynArea + 24 * (m_pCurDynArea->m_flags.m_flags1 & 0x7F) + 72);
        v15[0].m_dynCC.m_pCurDynArea = m_pCurDynArea;
        if ( ++v15[0].m_dynCC.m_i != v15[0].m_dynCC.m_numDynAreas )
          continue;
      }
      v15[0].m_staticCC.m_i = m_i + 1;
      bfx::ActiveAreasInArrayCursor::InitDynCC(this: v15);
      m_pArray = v15[0].m_staticCC.m_pArray;
      m_i = v15[0].m_staticCC.m_i;
      m_pCurDynArea = v15[0].m_dynCC.m_pCurDynArea;
    }
    while ( m_i < m_pArray->m_size );
  }
}


// ========================================================================
// ?GetStaticPortalEdges@bfx@@YAXAAV?$Array@PAVArea@bfx@@@1@AAV?$Array@VEdgeCursor@bfx@@@1@@Z
// EA  : 0x83275AB0
// RVA : 0x01275AB0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::GetStaticPortalEdges(
        bfx::Array<bfx::Area *> *staticPortalAreas,
        bfx::Array<bfx::ReplayLogListenerEntry> *staticPortalEdgesOut)
{
  int v4; // r27
  int v5; // r29
  bfx::Area **m_data; // r11
  int v7; // r31
  bfx::ReplayListener *v8; // r30
  bfx::ReplayListener_vtbl *v9; // r10
  int v10; // r10
  bfx::ReplayLogListenerEntry v11; // [sp+50h] [-40h] BYREF

  v4 = 0;
  if ( staticPortalAreas->m_size > 0 )
  {
    v5 = 0;
    do
    {
      m_data = staticPortalAreas->m_data;
      v7 = 0;
      *(_DWORD *)&v11.m_clientOwned = 0;
      v8 = (bfx::ReplayListener *)m_data[v5];
      v9 = v8[10].__vftable;
      v11.m_pListener = v8;
      if ( ((unsigned __int8)v9 & 0x7F) != 0 )
      {
        do
        {
          if ( ((int)v8[6 * v7 + 18].__vftable & 0x6000) == 0x2000 )
            bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(this: staticPortalEdgesOut, val: &v11);
          ++v7;
          v10 = (int)v8[10].__vftable & 0x7F;
          *(_DWORD *)&v11.m_clientOwned = v7;
        }
        while ( v7 < v10 );
      }
      ++v4;
      ++v5;
    }
    while ( v4 < staticPortalAreas->m_size );
  }
}


// ========================================================================
// ?BuildKDTreeForEdges@bfx@@YAPAVDynKDTree@1@ABV?$Array@VEdgeCursor@bfx@@@1@@Z
// EA  : 0x83275B68
// RVA : 0x01275B68
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

bfx::DynKDTree *__fastcall bfx::BuildKDTreeForEdges(const bfx::Array<bfx::EdgeCursor> *staticPortalEdges)
{
  int m_size; // r4
  int v3; // r27
  int v4; // r29
  const bfx::EdgeCursor *v5; // r30
  bfx::Box *v6; // r3
  int *v7; // r10
  _DWORD *p_m_z; // r9
  int i; // ctr
  bfx::DynKDTree *v10; // r3
  bfx::DynKDTree *v11; // r30
  bfx::Array<bfx::SPCorner> v13; // [sp+60h] [-90h] BYREF
  bfx::Box v14; // [sp+70h] [-80h] BYREF
  int v15; // [sp+8Ch] [-64h] BYREF
  bfx::SPCorner v16; // [sp+90h] [-60h] BYREF

  memset(&v13, 0, 12);
  v13.m_tag = bfx::MEM_BFXPLANNER;
  m_size = staticPortalEdges->m_size;
  if ( m_size > 0 )
    bfx::Array<bfx::GoalReachedData>::expand_cap(this: &v13, size: m_size);
  v3 = 0;
  if ( staticPortalEdges->m_size > 0 )
  {
    v4 = 0;
    v16.m_cornerFlavor = LEFT_CORNER_FLAVOR;
    do
    {
      v5 = &staticPortalEdges->m_data[v4];
      v6 = bfx::CalcBBox(result: &v14, edgeCursor: v5);
      v7 = &v15;
      p_m_z = (_DWORD *)&v6[-1].m_max.m_z;
      for ( i = 6; i != 0; --i )
        *++v7 = *++p_m_z;
      v16.m_areaExitIndex = (int)v5;
      bfx::Array<bfx::SPCorner>::push_back(this: &v13, val: &v16);
      ++v3;
      ++v4;
    }
    while ( v3 < staticPortalEdges->m_size );
  }
  v10 = (bfx::DynKDTree *)bfx::MemoryManager::Malloc(
                            this: bfx::g_pCurInstance->m_pMemoryManager,
                            size: 0x1Cu,
                            tag: bfx::MEM_BFXSYSTEM);
  if ( v10 != nullptr )
    v11 = bfx::DynKDTree::DynKDTree(this: v10);
  else
    v11 = nullptr;
  bfx::DynKDTree::BuildFromElems(this: v11, elems: (bfx::Array<bfx::KDBuildElem> *)&v13);
  v13.m_size = 0;
  if ( v13.m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v13.m_data);
  return v11;
}


// ========================================================================
// __unwind$39810
// EA  : 0x83275C84
// RVA : 0x01275C84
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_39810()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 240 + 96));
}


// ========================================================================
// __unwind$39811
// EA  : 0x83275CAC
// RVA : 0x01275CAC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_39811()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 240 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?InvalidatePortalIslands@bfx@@YAXPAVIslandGraph@1@AAV?$Array@PAVArea@bfx@@@1@@Z
// EA  : 0x83275CD8
// RVA : 0x01275CD8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::InvalidatePortalIslands(
        bfx::IslandGraph *pIslandGraph,
        bfx::Array<bfx::Area *> *staticPortalAreas)
{
  bfx::Array<bfx::Area *> *m_pArray; // r28
  int m_i; // r29
  bfx::Area *m_pCurDynArea; // r30
  bfx::Area *v6; // r11
  char *m_data; // r10
  char *v8; // r11
  bfx::ActiveAreasInArrayCursor v9[4]; // [sp+50h] [-50h] BYREF

  v9[0].m_staticCC.m_pArray = staticPortalAreas;
  v9[0].m_staticCC.m_i = 0;
  v9[0].m_dynCC.m_pCurDynArea = nullptr;
  v9[0].m_dynCC.m_numDynAreas = 0;
  v9[0].m_dynCC.m_i = 0;
  bfx::ActiveAreasInArrayCursor::InitDynCC(this: v9);
  m_pArray = v9[0].m_staticCC.m_pArray;
  m_i = v9[0].m_staticCC.m_i;
  if ( v9[0].m_staticCC.m_i < v9[0].m_staticCC.m_pArray->m_size )
  {
    m_pCurDynArea = v9[0].m_dynCC.m_pCurDynArea;
    do
    {
      v6 = m_pArray->m_data[m_i];
      m_data = v6->m_dynAreaData.m_data;
      if ( m_data != nullptr && *(_DWORD *)m_data != 0 )
        v6 = m_pCurDynArea;
      if ( (v6->m_flags.m_flags1 & 0xFFFF80) != 0xFFFF80 )
        bfx::IslandGraph::RemoveIsland(this: pIslandGraph, pStartArea: v6, pAreasTouchedOut: nullptr);
      v8 = m_pArray->m_data[m_i]->m_dynAreaData.m_data;
      if ( v8 != nullptr && *(_DWORD *)v8 != 0 )
      {
        m_pCurDynArea = (bfx::Area *)((char *)m_pCurDynArea + 24 * (m_pCurDynArea->m_flags.m_flags1 & 0x7F) + 72);
        v9[0].m_dynCC.m_pCurDynArea = m_pCurDynArea;
        if ( ++v9[0].m_dynCC.m_i != v9[0].m_dynCC.m_numDynAreas )
          continue;
      }
      v9[0].m_staticCC.m_i = m_i + 1;
      bfx::ActiveAreasInArrayCursor::InitDynCC(this: v9);
      m_pArray = v9[0].m_staticCC.m_pArray;
      m_i = v9[0].m_staticCC.m_i;
      m_pCurDynArea = v9[0].m_dynCC.m_pCurDynArea;
    }
    while ( m_i < m_pArray->m_size );
  }
}


// ========================================================================
// ?CreatePortalIslands@bfx@@YAXPAVIslandGraph@1@AAV?$Array@PAVArea@bfx@@@1@@Z
// EA  : 0x83275DF8
// RVA : 0x01275DF8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::CreatePortalIslands(bfx::IslandGraph *pIslandGraph, bfx::Array<bfx::Area *> *staticPortalAreas)
{
  bfx::Array<bfx::Area *> *m_pArray; // r28
  int m_i; // r29
  bfx::Area *m_pCurDynArea; // r30
  bfx::Area *v6; // r11
  char *m_data; // r10
  char *v8; // r11
  bfx::ActiveAreasInArrayCursor v9[4]; // [sp+50h] [-50h] BYREF

  v9[0].m_staticCC.m_pArray = staticPortalAreas;
  v9[0].m_staticCC.m_i = 0;
  v9[0].m_dynCC.m_pCurDynArea = nullptr;
  v9[0].m_dynCC.m_numDynAreas = 0;
  v9[0].m_dynCC.m_i = 0;
  bfx::ActiveAreasInArrayCursor::InitDynCC(this: v9);
  m_pArray = v9[0].m_staticCC.m_pArray;
  m_i = v9[0].m_staticCC.m_i;
  if ( v9[0].m_staticCC.m_i < v9[0].m_staticCC.m_pArray->m_size )
  {
    m_pCurDynArea = v9[0].m_dynCC.m_pCurDynArea;
    do
    {
      v6 = m_pArray->m_data[m_i];
      m_data = v6->m_dynAreaData.m_data;
      if ( m_data != nullptr && *(_DWORD *)m_data != 0 )
        v6 = m_pCurDynArea;
      if ( (v6->m_flags.m_flags1 & 0xFFFF80) == 0xFFFF80 )
        bfx::IslandGraph::FillSameValueSurfaceWithIslands(this: pIslandGraph, pStartArea: v6);
      v8 = m_pArray->m_data[m_i]->m_dynAreaData.m_data;
      if ( v8 != nullptr && *(_DWORD *)v8 != 0 )
      {
        m_pCurDynArea = (bfx::Area *)((char *)m_pCurDynArea + 24 * (m_pCurDynArea->m_flags.m_flags1 & 0x7F) + 72);
        v9[0].m_dynCC.m_pCurDynArea = m_pCurDynArea;
        if ( ++v9[0].m_dynCC.m_i != v9[0].m_dynCC.m_numDynAreas )
          continue;
      }
      v9[0].m_staticCC.m_i = m_i + 1;
      bfx::ActiveAreasInArrayCursor::InitDynCC(this: v9);
      m_pArray = v9[0].m_staticCC.m_pArray;
      m_i = v9[0].m_staticCC.m_i;
      m_pCurDynArea = v9[0].m_dynCC.m_pCurDynArea;
    }
    while ( m_i < m_pArray->m_size );
  }
}


// ========================================================================
// ??0PortalSubdivData@bfx@@QAA@AAVEdgeCursor@1@@Z
// EA  : 0x83275F18
// RVA : 0x01275F18
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

bfx::PortalSubdivData *__fastcall bfx::PortalSubdivData::PortalSubdivData(
        bfx::PortalSubdivData *this,
        bfx::EdgeCursor *portalEdge)
{
  bfx::Edge *v2; // r11
  int m_i; // r11
  signed int v4; // r31
  float *v5; // r5
  int v6; // r8
  float *v7; // r11
  float v8; // r4
  float v9; // r10
  float v10; // r7
  unsigned int v11; // r8
  float v12; // r5
  float v13; // r31
  float v14; // r11
  double v15; // fp0
  double v16; // fp13
  double v17; // fp12
  double v18; // fp11
  double v19; // fp11

  if ( portalEdge->m_pArea != nullptr )
    v2 = (bfx::Edge *)((char *)&portalEdge->m_pArea[1] + 24 * portalEdge->m_i);
  else
    v2 = nullptr;
  this->m_pPortalEdge = v2;
  m_i = portalEdge->m_i;
  v4 = portalEdge->m_pArea->m_flags.m_flags1 & 0x7F;
  v5 = (float *)(&portalEdge->m_pArea[1].m_dynAreaData + 6 * m_i);
  v6 = __ROL4__(m_i + 1, 1);
  v7 = (float *)((char *)portalEdge->m_pArea + 24 * ((m_i + 1) % v4));
  v8 = *v5;
  v9 = v5[1];
  v10 = v5[2];
  v11 = v4 & ~(v6 - 1);
  __twllei(v4, 0);
  v12 = v7[15];
  v13 = v7[16];
  __twlgei(v11, 0xFFFFFFFF);
  v14 = v7[17];
  this->m_edgeSeg.m_v0.m_x = v8;
  this->m_edgeSeg.m_v0.m_y = v9;
  this->m_edgeSeg.m_v0.m_z = v10;
  this->m_edgeSeg.m_v1.m_x = v12;
  this->m_edgeSeg.m_v1.m_y = v13;
  this->m_edgeSeg.m_v1.m_z = v14;
  this->m_subdivElems.m_tag = bfx::MEM_BFXPLANNER;
  this->m_subdivElems.m_data = nullptr;
  this->m_subdivElems.m_size = 0;
  this->m_subdivElems.m_cap = 0;
  v15 = (float)(this->m_edgeSeg.m_v1.m_y - this->m_edgeSeg.m_v0.m_y);
  v16 = (float)(this->m_edgeSeg.m_v1.m_z - this->m_edgeSeg.m_v0.m_z);
  v17 = (float)(this->m_edgeSeg.m_v1.m_x - this->m_edgeSeg.m_v0.m_x);
  v18 = __fsqrts((float)((float)((float)v17 * (float)v17)
                       + (float)((float)((float)v16 * (float)v16) + (float)((float)v15 * (float)v15))));
  this->m_edgeLen = v18;
  if ( v18 <= 1.0842022e-19 )
  {
    this->m_edgeUnitVec = bfx::ZERO_VEC;
  }
  else
  {
    v19 = (float)((float)1.0 / (float)v18);
    this->m_edgeUnitVec.m_x = (float)v19 * (float)v17;
    this->m_edgeUnitVec.m_y = (float)v19 * (float)v15;
    this->m_edgeUnitVec.m_z = (float)v19 * (float)v16;
  }
  return this;
}


// ========================================================================
// ?SubdivIfNeeded@PortalSubdivData@bfx@@QAAXABVVec3@2@MMW4PortalSubdivType@2@@Z
// EA  : 0x83276098
// RVA : 0x01276098
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::PortalSubdivData::SubdivIfNeeded(
        bfx::PortalSubdivData *this,
        const bfx::Vec3 *vertPos,
        double subdivThreshold,
        double maxPortalCreationDist,
        bfx::PortalSubdivType type,
        int a6,
        int a7)
{
  double v11; // fp31
  double DistSqPtToLineSeg; // fp1
  int m_size; // r8
  bfx::Array<bfx::PortalSubdivElem> *p_m_subdivElems; // r3
  int v15; // r9
  bfx::PortalSubdivElem *m_data; // r7
  int v17; // r11
  bfx::PortalSubdivElem *v18; // r10
  double m_x; // fp13
  double v20; // fp7
  double v21; // fp9
  double m_y; // fp6
  double v23; // fp12
  double m_z; // fp10
  bfx::BinaryHeap<bfx::OpenNode3D,float>::Node v27; // [sp+60h] [-60h] BYREF

  if ( this->m_edgeLen > 1.0842022e-19 )
  {
    v11 = (float)((float)((float)(vertPos->m_x - this->m_edgeSeg.m_v0.m_x) * this->m_edgeUnitVec.m_x)
                + (float)((float)(this->m_edgeUnitVec.m_z * (float)(vertPos->m_z - this->m_edgeSeg.m_v0.m_z))
                        + (float)(this->m_edgeUnitVec.m_y * (float)(vertPos->m_y - this->m_edgeSeg.m_v0.m_y))));
    if ( v11 > subdivThreshold && v11 < (float)(this->m_edgeLen - (float)subdivThreshold) )
    {
      DistSqPtToLineSeg = bfx::GetDistSqPtToLineSeg(pos: vertPos, seg: &this->m_edgeSeg);
      if ( DistSqPtToLineSeg <= (float)((float)maxPortalCreationDist * (float)maxPortalCreationDist) )
      {
        m_size = this->m_subdivElems.m_size;
        p_m_subdivElems = &this->m_subdivElems;
        v15 = 0;
        if ( m_size <= 0 )
        {
LABEL_9:
          m_x = this->m_edgeUnitVec.m_x;
          LODWORD(v27.m_priority) = a7;
          v20 = (float)(this->m_edgeUnitVec.m_y * (float)v11);
          v21 = this->m_edgeSeg.m_v0.m_x;
          m_y = this->m_edgeSeg.m_v0.m_y;
          v23 = (float)(this->m_edgeUnitVec.m_z * (float)v11);
          m_z = this->m_edgeSeg.m_v0.m_z;
          v27.m_elem.m_searchCost = v11;
          *(float *)&v27.m_elem.m_parentIdx = DistSqPtToLineSeg;
          *(float *)&v27.m_elem.m_pointID = (float)m_z + (float)v23;
          *(float *)&v27.m_elem.m_dir = (float)m_y + (float)v20;
          *(float *)&v27.m_elem.m_pPortal = (float)((float)v11 * (float)m_x) + (float)v21;
          bfx::Array<bfx::Box>::push_back(
            this: (bfx::Array<bfx::BinaryHeap<bfx::OpenNode3D,float>::Node> *)p_m_subdivElems,
            val: &v27);
        }
        else
        {
          m_data = p_m_subdivElems->m_data;
          v17 = 0;
          while ( 1 )
          {
            v18 = &m_data[v17];
            if ( __fabs((float)(m_data[v17].m_distFromEdgeStart - (float)v11)) <= subdivThreshold )
              break;
            ++v15;
            ++v17;
            if ( v15 >= m_size )
              goto LABEL_9;
          }
          if ( v18->m_type != a7 )
          {
            _FP13 = (float)(v18->m_distToNearbyEdgeSq - (float)DistSqPtToLineSeg);
            v18->m_type = PORTAL_SEGMENT_BOTH_START_AND_END;
            __asm { fsel      f12, f13, f1, f0 }
            v18->m_distToNearbyEdgeSq = _FP12;
          }
        }
      }
    }
  }
}


// ========================================================================
// ?AddSubdivElemsForNearbyEdges@PortalSubdivData@bfx@@QAAXMMPBVDynKDTree@2@@Z
// EA  : 0x83276240
// RVA : 0x01276240
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::PortalSubdivData::AddSubdivElemsForNearbyEdges(
        bfx::PortalSubdivData *this,
        double subdivThreshold,
        double maxPortalCreationDist,
        const bfx::DynKDTree *pAllStaticPortalEdgesKDTree,
        int a5,
        const bfx::DynKDTree *a6)
{
  double v7; // fp9
  double v10; // fp11
  double v11; // fp6
  _DWORD *v12; // r3
  double m_z; // fp12
  double m_y; // fp11
  double m_x; // fp10
  double v16; // fp13
  float *v17; // r11
  float v18; // r9
  float v19; // r8
  double v20; // fp9
  int v21; // r10
  int v22; // r7
  signed int v23; // r5
  int v24; // r6
  float *v25; // r11
  float v26; // r5
  float v27; // r4
  double v28; // fp9
  int v31; // r6
  bfx::PortalSubdivType v32; // r5
  unsigned int m_size; // r4
  bfx::Vec3 v34; // [sp+50h] [-490h] BYREF
  bfx::Vec3 v35; // [sp+60h] [-480h] BYREF
  bfx::Sphere v36; // [sp+70h] [-470h] BYREF
  bfx::DynKDTree::PrimsInSphereCursor v37; // [sp+80h] [-460h] BYREF

  v7 = (float)(this->m_edgeSeg.m_v0.m_x + this->m_edgeSeg.m_v1.m_x);
  v10 = (float)(this->m_edgeSeg.m_v1.m_z + this->m_edgeSeg.m_v0.m_z);
  v11 = (float)(this->m_edgeSeg.m_v1.m_y + this->m_edgeSeg.m_v0.m_y);
  v36.m_radius = this->m_edgeLen * (float)0.5;
  v34.m_x = (float)v7 * (float)0.5;
  v34.m_z = (float)v10 * (float)0.5;
  v34.m_y = (float)v11 * (float)0.5;
  v36.m_pos = v34;
  bfx::DynKDTree::PrimsInSphereCursor::PrimsInSphereCursor(this: &v37, sphere: &v36, pKDTree: a6);
  while ( !v37.m_atEnd )
  {
    v12 = bfx::DynKDTree::PrimsInSphereCursor::operator*(this: &v37);
    m_z = this->m_edgeUnitVec.m_z;
    m_y = this->m_edgeUnitVec.m_y;
    m_x = this->m_edgeUnitVec.m_x;
    v16 = COS_CONNECT_THRESHOLD;
    v17 = (float *)(24 * v12[1] + *v12);
    v18 = v17[16];
    v19 = v17[17];
    v35.m_x = v17[15];
    v20 = v35.m_x;
    v35.m_y = v18;
    v35.m_z = v19;
    v21 = *v12;
    v22 = v12[1] + 1;
    v23 = *(_DWORD *)(*v12 + 40) & 0x7F;
    v24 = 3 * (v22 % v23);
    __twllei(v23, 0);
    __twlgei(v23 & ~(__ROL4__(v22, 1) - 1), 0xFFFFFFFF);
    v25 = (float *)(24 * (v22 % v23) + v21);
    v26 = v25[16];
    v27 = v25[17];
    v34.m_x = v25[15];
    v34.m_y = v26;
    v34.m_z = v27;
    v28 = (float)(v34.m_x - (float)v20);
    _FP5 = (float)((float)__fsqrts((float)((float)((float)v28 * (float)v28)
                                         + (float)((float)((float)(v27 - v19) * (float)(v27 - v19))
                                                 + (float)((float)(v34.m_y - v18) * (float)(v34.m_y - v18)))))
                 - (float)1.0842022e-19);
    __asm { fsel      f1, f5, f3, f31 }
    if ( (float)((float)((float)m_x * (float)((float)v28 * (float)_FP1))
               + (float)((float)((float)m_y * (float)((float)(v26 - v18) * (float)_FP1))
                       + (float)((float)m_z * (float)((float)(v27 - v19) * (float)_FP1)))) < v16 )
    {
      bfx::PortalSubdivData::SubdivIfNeeded(
        this,
        vertPos: &v35,
        subdivThreshold,
        maxPortalCreationDist,
        type: SLODWORD(v26),
        a6: v24,
        a7: 1);
      bfx::PortalSubdivData::SubdivIfNeeded(
        this,
        vertPos: &v34,
        subdivThreshold,
        maxPortalCreationDist,
        type: v32,
        a6: v31,
        a7: 0);
    }
    bfx::DynKDTree::PrimsInSphereCursor::TraverseToNextLeaf(this: &v37);
  }
  m_size = this->m_subdivElems.m_size;
  if ( m_size != 0 )
    qsort(
      base: this->m_subdivElems.m_data,
      num: m_size,
      width: 0x18u,
      comp: (int (__fastcall *)(const void *, const void *))bfx::CompareSubdivElems);
}


// ========================================================================
// ?ApplyPortalSubdiv@DGraph@bfx@@QAAXABVPortalSubdivData@2@@Z
// EA  : 0x83276488
// RVA : 0x01276488
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::DGraph::ApplyPortalSubdiv(bfx::DGraph *this, const bfx::PortalSubdivData *portalSubdivData)
{
  bfx::DEdge *m_pHeadEdgeNode; // r30
  bfx::Edge *m_pSrcEdge; // r11
  bfx::Array<bfx::PortalSubdivElem> *p_m_subdivElems; // r28
  int v6; // r31
  int v7; // r29

  m_pHeadEdgeNode = (bfx::DEdge *)this->m_pHeadEdgeNode;
  if ( m_pHeadEdgeNode != nullptr )
  {
    while ( 1 )
    {
      m_pSrcEdge = m_pHeadEdgeNode->m_pSrcEdge;
      if ( m_pSrcEdge != nullptr && m_pSrcEdge == portalSubdivData->m_pPortalEdge )
        break;
      m_pHeadEdgeNode = (bfx::DEdge *)m_pHeadEdgeNode->m_pNextListNode;
      if ( m_pHeadEdgeNode == nullptr )
        return;
    }
    p_m_subdivElems = &portalSubdivData->m_subdivElems;
    v6 = 0;
    if ( portalSubdivData->m_subdivElems.m_size > 0 )
    {
      v7 = 0;
      do
      {
        bfx::DGraph::SplitEdgeAtPos(this, pEdge: m_pHeadEdgeNode, pos: &p_m_subdivElems->m_data[v7].m_subdivPos);
        ++v6;
        ++v7;
        m_pHeadEdgeNode = m_pHeadEdgeNode->m_pNext;
      }
      while ( v6 < p_m_subdivElems->m_size );
    }
  }
}


// ========================================================================
// ?MarkAllAllocatedAreasWithSearchIndex@NavGraph@bfx@@QAAXI@Z
// EA  : 0x83276580
// RVA : 0x01276580
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::NavGraph::MarkAllAllocatedAreasWithSearchIndex(bfx::NavGraph *this, __int16 searchIndex)
{
  int v2; // r10
  int v3; // r11
  bfx::Area *v4; // r6
  int v5; // r10
  int v6; // r11
  bfx::Area *v7; // r6

  v2 = 0;
  if ( this->m_allocatedAreasOwned.m_size > 0 )
  {
    v3 = 0;
    do
    {
      ++v2;
      v4 = this->m_allocatedAreasOwned.m_data[v3++];
      LOWORD(v4->m_flags.m_flags3) = searchIndex;
    }
    while ( v2 < this->m_allocatedAreasOwned.m_size );
  }
  v5 = 0;
  if ( this->m_allocatedAreasAdjNonOwned.m_size > 0 )
  {
    v6 = 0;
    do
    {
      ++v5;
      v7 = this->m_allocatedAreasAdjNonOwned.m_data[v6++];
      LOWORD(v7->m_flags.m_flags3) = searchIndex;
    }
    while ( v5 < this->m_allocatedAreasAdjNonOwned.m_size );
  }
}


// ========================================================================
// ?RemoveReferencesToAreasWithSpecifiedSearchIndex@bfx@@YAXIAAV?$Array@PAVArea@bfx@@@1@@Z
// EA  : 0x83276608
// RVA : 0x01276608
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::RemoveReferencesToAreasWithSpecifiedSearchIndex(
        unsigned int searchIndex,
        bfx::Array<bfx::Area *> *areas)
{
  int v2; // r29
  int m_size; // r4
  int i; // r28
  int m_flags3_low; // r10
  int v8; // r9
  int m_cap; // r8
  char *m_data; // r4
  bfx::Space *p_m_cap; // [sp+50h] [-50h] BYREF
  bfx::Array<bfx::SpaceComponent *> v12[4]; // [sp+60h] [-40h] BYREF

  v2 = 0;
  memset(v12, 0, 12);
  v12[0].m_tag = bfx::MEM_BFXPLANNER;
  m_size = areas->m_size;
  if ( m_size > 0 )
    bfx::Array<bfx::Edge *>::expand_cap(this: v12, size: m_size);
  for ( i = 0; i < areas->m_size; ++v2 )
  {
    m_flags3_low = LOWORD(areas->m_data[v2]->m_flags.m_flags3);
    p_m_cap = (bfx::Space *)areas->m_data[v2];
    if ( m_flags3_low != searchIndex )
      bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)v12, val: &p_m_cap);
    ++i;
  }
  v8 = v12[0].m_size;
  m_cap = v12[0].m_cap;
  m_data = (char *)areas->m_data;
  p_m_cap = (bfx::Space *)&areas->m_cap;
  areas->m_data = (bfx::Area **)v12[0].m_data;
  areas->m_size = v8;
  areas->m_cap = m_cap;
  if ( m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
}


// ========================================================================
// __unwind$40975
// EA  : 0x832766DC
// RVA : 0x012766DC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_40975()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 160 + 96));
}


// ========================================================================
// ??EActiveAreasInSphereCursor@bfx@@QAAXXZ
// EA  : 0x83276708
// RVA : 0x01276708
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::ActiveAreasInSphereCursor::operator++(bfx::ActiveAreasInSphereCursor *this)
{
  bfx::Area *v2; // r3

  bfx::ActiveAreasInSphereCursor::IncrementOnce(this);
  while ( (unsigned __int8)bfx::ActiveAreasInSphereCursor::AtEnd(this) == 0 )
  {
    v2 = bfx::ActiveAreasInSphereCursor::operator*(this);
    if ( __fsqrts((float)((float)((float)(v2->m_pos.m_x - this->m_sphere.m_pos.m_x)
                                * (float)(v2->m_pos.m_x - this->m_sphere.m_pos.m_x))
                        + (float)((float)((float)(v2->m_pos.m_z - this->m_sphere.m_pos.m_z)
                                        * (float)(v2->m_pos.m_z - this->m_sphere.m_pos.m_z))
                                + (float)((float)(v2->m_pos.m_y - this->m_sphere.m_pos.m_y)
                                        * (float)(v2->m_pos.m_y - this->m_sphere.m_pos.m_y))))) <= (float)(v2->m_radius + this->m_sphere.m_radius) )
      break;
    bfx::ActiveAreasInSphereCursor::IncrementOnce(this);
  }
}


// ========================================================================
// ?GetStaticAreasIntersectingVolume@NavGraph@bfx@@QAAXABV?$Array@VPlane@bfx@@@2@ABVSphere@2@AAV?$Array@PAVArea@bfx@@@2@@Z
// EA  : 0x832767D0
// RVA : 0x012767D0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::NavGraph::GetStaticAreasIntersectingVolume(
        bfx::NavGraph *this,
        const bfx::Array<bfx::Plane> *planes,
        const bfx::Sphere *boundingSphere,
        bfx::Array<bfx::Space *> *areasIntersectingSphere)
{
  bfx::Array<bfx::Area *> *p_m_allocatedAreasOwned; // r28
  int v9; // r26
  int v10; // r29
  bfx::Area *v11; // r31
  int m_cap; // r10
  int m_size; // r11
  int v14; // r4
  bfx::Area **v15; // r11
  bfx::Area *v16; // [sp+50h] [-470h] BYREF
  bfx::KDTree::PrimsInSphereCursor v17; // [sp+60h] [-460h] BYREF

  if ( bfx::GetDistPtToBox(pos: &boundingSphere->m_pos, box: &this->m_bbox) <= (double)boundingSphere->m_radius )
  {
    bfx::KDTree::PrimsInSphereCursor::PrimsInSphereCursor(this: &v17, sphere: boundingSphere, kdtree: &this->m_kdtree);
    while ( !v17.m_atEnd )
    {
      v16 = (bfx::Area *)&this->m_binaryImage[**(_DWORD **)v17.m_pNextNode & 0x7FFFFFFF];
      if ( (unsigned __int8)bfx::DoesAreaIntersectVolume(pArea: v16, planes, boundingSphere) != 0 )
        bfx::Array<bfx::Portal *>::push_back(this: areasIntersectingSphere, val: (bfx::Space *const *)&v16);
      bfx::KDTree::PrimsInSphereCursor::TraverseToNextLeaf(this: &v17);
    }
    p_m_allocatedAreasOwned = &this->m_allocatedAreasOwned;
    v9 = 0;
    if ( this->m_allocatedAreasOwned.m_size > 0 )
    {
      v10 = 0;
      do
      {
        v11 = p_m_allocatedAreasOwned->m_data[v10];
        if ( (unsigned __int8)bfx::DoesAreaIntersectVolume(pArea: v11, planes, boundingSphere) != 0 )
        {
          m_cap = areasIntersectingSphere->m_cap;
          m_size = areasIntersectingSphere->m_size;
          if ( m_cap == m_size )
          {
            v14 = 2 * m_cap;
            if ( m_cap == 0 )
              v14 = 1;
            bfx::Array<bfx::Edge *>::expand_cap(
              this: (bfx::Array<bfx::SpaceComponent *> *)areasIntersectingSphere,
              size: v14);
            m_size = areasIntersectingSphere->m_size;
          }
          v15 = (bfx::Area **)&areasIntersectingSphere->m_data[m_size];
          if ( v15 != nullptr )
            *v15 = v11;
          ++areasIntersectingSphere->m_size;
        }
        ++v9;
        ++v10;
      }
      while ( v9 < p_m_allocatedAreasOwned->m_size );
    }
  }
}


// ========================================================================
// ?ClearSearchIndexForAllAreas@NavGraph@bfx@@QAAXXZ
// EA  : 0x83276920
// RVA : 0x01276920
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::NavGraph::ClearSearchIndexForAllAreas(bfx::NavGraph *this)
{
  int v1; // r4
  char *m_pAreaBuf; // r5
  char *v3; // r31
  char v4; // r11
  bfx::Area *v5; // r11
  char *m_data; // r10
  _DWORD *v7; // r11
  int v8; // r7
  int i; // r10

  v1 = 0;
  m_pAreaBuf = this->m_pAreaBuf;
  v3 = &m_pAreaBuf[this->m_pHeader->m_areaBytes];
  while ( 1 )
  {
    if ( m_pAreaBuf < v3 || (v4 = 1, v1 < this->m_allocatedAreasOwned.m_size) )
      v4 = 0;
    if ( v4 != 0 )
      break;
    if ( m_pAreaBuf >= v3 )
      v5 = this->m_allocatedAreasOwned.m_data[v1];
    else
      v5 = (bfx::Area *)m_pAreaBuf;
    LOWORD(v5->m_flags.m_flags3) = 0;
    m_data = v5->m_dynAreaData.m_data;
    v7 = m_data + 20;
    if ( m_data != nullptr )
    {
      v8 = *(_DWORD *)m_data;
    }
    else
    {
      v7 = nullptr;
      v8 = 0;
    }
    for ( i = 0; i != v8; v7 += 6 * (v7[10] & 0x7F) + 18 )
    {
      *((_WORD *)v7 + 25) = 0;
      ++i;
    }
    if ( m_pAreaBuf >= v3 )
      ++v1;
    else
      m_pAreaBuf += 24 * (*((_DWORD *)m_pAreaBuf + 10) & 0x7F) + 56;
  }
}


// ========================================================================
// ?ClearSearchIndexForAllAreas@NavLayer@bfx@@QAAXXZ
// EA  : 0x83276A20
// RVA : 0x01276A20
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::NavLayer::ClearSearchIndexForAllAreas(bfx::NavLayer *this)
{
  bfx::NavLayer *m_layer; // r30
  int m_i; // r31
  int m_endGraphIndex; // r10
  bfx::NavGraph **v4; // r11
  bfx::NavLayerCC v5; // [sp+50h] [-20h] BYREF

  v5.m_layer = this;
  v5.m_i = -1;
  bfx::NavLayerCC::IncToNextValid(this: &v5);
  m_layer = v5.m_layer;
  m_i = v5.m_i;
  if ( v5.m_i < v5.m_layer->m_endGraphIndex )
  {
    do
    {
      bfx::NavGraph::ClearSearchIndexForAllAreas(this: m_layer->m_graphs[m_i]);
      m_endGraphIndex = m_layer->m_endGraphIndex;
      if ( ++m_i >= m_endGraphIndex )
        break;
      v4 = &m_layer->m_graphs[m_i];
      do
      {
        if ( *v4 != nullptr )
          break;
        ++m_i;
        ++v4;
      }
      while ( m_i < m_endGraphIndex );
    }
    while ( m_i < m_endGraphIndex );
  }
}


// ========================================================================
// ??1NavGraph@bfx@@QAA@XZ
// EA  : 0x83276AD0
// RVA : 0x01276AD0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::NavGraph::~NavGraph(bfx::NavGraph *this)
{
  int v2; // r26
  char *m_pAreaBuf; // r29
  char *v4; // r27
  char v5; // r11
  bfx::Area *v6; // r3
  char *m_data; // r4
  char *v8; // r4
  char *v9; // r4
  char *v10; // r4

  bfx::IslandGraph::RemoveIslandsForNavGraph(this: this->m_pNavLayer->m_pIslandGraph, pNavGraph: this);
  v2 = 0;
  m_pAreaBuf = this->m_pAreaBuf;
  v4 = &m_pAreaBuf[this->m_pHeader->m_areaBytes];
  while ( 1 )
  {
    if ( m_pAreaBuf < v4 || (v5 = 1, v2 < this->m_allocatedAreasOwned.m_size) )
      v5 = 0;
    if ( v5 != 0 )
      break;
    if ( m_pAreaBuf >= v4 )
      v6 = this->m_allocatedAreasOwned.m_data[v2];
    else
      v6 = (bfx::Area *)m_pAreaBuf;
    bfx::Area::~Area(this: v6);
    if ( m_pAreaBuf >= v4 )
      ++v2;
    else
      m_pAreaBuf += 24 * (*((_DWORD *)m_pAreaBuf + 10) & 0x7F) + 56;
  }
  this->m_binaryImage = nullptr;
  this->m_pAreaBuf = nullptr;
  m_data = (char *)this->m_staticPortalAreas.m_data;
  this->m_staticPortalAreas.m_size = 0;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_staticPortalAreas.m_data = nullptr;
  }
  this->m_staticPortalAreas.m_cap = 0;
  v8 = (char *)this->m_adjacentNavGraphs.m_data;
  this->m_adjacentNavGraphs.m_size = 0;
  if ( v8 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v8);
    this->m_adjacentNavGraphs.m_data = nullptr;
  }
  this->m_adjacentNavGraphs.m_cap = 0;
  v9 = (char *)this->m_allocatedAreasAdjNonOwned.m_data;
  this->m_allocatedAreasAdjNonOwned.m_size = 0;
  if ( v9 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v9);
    this->m_allocatedAreasAdjNonOwned.m_data = nullptr;
  }
  this->m_allocatedAreasAdjNonOwned.m_cap = 0;
  v10 = (char *)this->m_allocatedAreasOwned.m_data;
  this->m_allocatedAreasOwned.m_size = 0;
  if ( v10 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v10);
    this->m_allocatedAreasOwned.m_data = nullptr;
  }
  this->m_allocatedAreasOwned.m_cap = 0;
  bfx::KDTree::~KDTree(this: &this->m_kdtree);
}


// ========================================================================
// __unwind$41943
// EA  : 0x83276C34
// RVA : 0x01276C34
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_41943()
{
  int v0; // r12

  bfx::KDTree::~KDTree(this: (bfx::KDTree *)(*(_DWORD *)(v0 - 144 + 164) + 24));
}


// ========================================================================
// __unwind$41944
// EA  : 0x83276C60
// RVA : 0x01276C60
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_41944()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                             + 100));
}


// ========================================================================
// __unwind$41945
// EA  : 0x83276C8C
// RVA : 0x01276C8C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_41945()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                             + 116));
}


// ========================================================================
// __unwind$41946
// EA  : 0x83276CB8
// RVA : 0x01276CB8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_41946()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                             + 132));
}


// ========================================================================
// __unwind$41947
// EA  : 0x83276CE4
// RVA : 0x01276CE4
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_41947()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                             + 148));
}


// ========================================================================
// ?AddAllocatedArea@NavGraph@bfx@@QAAXPAVArea@2@@Z
// EA  : 0x83276D10
// RVA : 0x01276D10
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::NavGraph::AddAllocatedArea(
        bfx::NavGraph *this,
        bfx::Space *pArea,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        bfx::Space *a14)
{
  double m_y; // fp11
  double m_x; // fp10
  double v21; // fp9
  bfx::DynKDNode *m_pContainingKDLeaf; // r4
  bfx::Area var30; // [sp+50h] [-30h] BYREF

  a14 = pArea;
  bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)&this->m_allocatedAreasOwned, val: &a14);
  bfx::Area::CalcBBox(this: &var30, result: (bfx::Box *)pArea);
  _FP6 = (float)(this->m_bbox.m_min.m_z - *(float *)&var30.m_pFirstLink);
  _FP4 = (float)(this->m_bbox.m_min.m_y - *(float *)&var30.m_dynAreaData.m_data);
  _FP3 = (float)(this->m_bbox.m_min.m_x - *(float *)&var30.m_pProxy);
  m_y = var30.m_pos.m_y;
  m_x = var30.m_pos.m_x;
  v21 = *(float *)&var30.m_pSearchParent;
  __asm { fsel      f2, f6, f0, f8 }
  this->m_bbox.m_min.m_z = _FP2;
  __asm { fsel      f1, f4, f13, f7 }
  this->m_bbox.m_min.m_y = _FP1;
  __asm { fsel      f0, f3, f12, f5 }
  this->m_bbox.m_min.m_x = _FP0;
  _FP5 = (float)(this->m_bbox.m_max.m_x - (float)v21);
  _FP7 = (float)(this->m_bbox.m_max.m_y - (float)m_x);
  _FP6 = (float)(this->m_bbox.m_max.m_z - (float)m_y);
  __asm { fsel      f2, f5, f13, f9 }
  this->m_bbox.m_max.m_x = _FP2;
  __asm { fsel      f4, f7, f8, f10 }
  this->m_bbox.m_max.m_y = _FP4;
  __asm { fsel      f3, f6, f12, f11 }
  this->m_bbox.m_max.m_z = _FP3;
  m_pContainingKDLeaf = this->m_pContainingKDLeaf;
  if ( m_pContainingKDLeaf != nullptr )
    bfx::DynKDTree::UpdateTreeForNewLeafNodeBBox(
      this: this->m_pNavLayer->m_navGraphSpatialOrg.m_pNavLayerKDTree,
      pLeafNode: m_pContainingKDLeaf,
      newBBox: &this->m_bbox);
}


// ========================================================================
// ?RelocPtrs@NavGraph@bfx@@AAAXW4RelocDir@12@@Z
// EA  : 0x83276DF8
// RVA : 0x01276DF8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::NavGraph::RelocPtrs(bfx::NavGraph *this, bfx::NavGraph::RelocDir __formal)
{
  int v2; // r5
  char *m_binaryImage; // r6
  char *m_pAreaBuf; // r7
  char *v5; // r4
  char v6; // r11
  bfx::Area *v7; // r8
  int v8; // r9
  bfx::Area *v9; // r11

  v2 = 0;
  m_binaryImage = this->m_binaryImage;
  m_pAreaBuf = this->m_pAreaBuf;
  v5 = &m_pAreaBuf[this->m_pHeader->m_areaBytes];
  while ( 1 )
  {
    if ( m_pAreaBuf < v5 || (v6 = 1, v2 < this->m_allocatedAreasOwned.m_size) )
      v6 = 0;
    if ( v6 != 0 )
      break;
    if ( m_pAreaBuf >= v5 )
      v7 = this->m_allocatedAreasOwned.m_data[v2];
    else
      v7 = (bfx::Area *)m_pAreaBuf;
    v8 = 0;
    if ( (v7->m_flags.m_flags1 & 0x7F) != 0 )
    {
      v9 = v7 + 1;
      do
      {
        if ( v9->m_pProxy != nullptr )
          v9->m_pProxy = (bfx::AreaProxy *)((char *)v9->m_pProxy + (unsigned int)m_binaryImage);
        ++v8;
        v9 = (bfx::Area *)((char *)v9 + 24);
      }
      while ( v8 < (signed int)(v7->m_flags.m_flags1 & 0x7F) );
    }
    if ( m_pAreaBuf >= v5 )
      ++v2;
    else
      m_pAreaBuf += 24 * (*((_DWORD *)m_pAreaBuf + 10) & 0x7F) + 56;
  }
}


// ========================================================================
// ?GetStaticAreaForDynamicArea@NavGraph@bfx@@QAAPAVArea@2@PAV32@@Z
// EA  : 0x83276ED0
// RVA : 0x01276ED0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

bfx::Area *__fastcall bfx::NavGraph::GetStaticAreaForDynamicArea(bfx::NavGraph *this, bfx::Area *pDynArea)
{
  int v2; // r31
  char *m_pAreaBuf; // r6
  char *v4; // r30
  char v5; // r11
  bfx::Area *v6; // r5
  char *m_data; // r11
  bfx::Area *v8; // r10
  int v9; // r7
  int v10; // r9
  bfx::Area *result; // r3
  int m_size; // r30
  int v13; // r5
  bfx::Area **v14; // r31
  int i; // r6
  char *v16; // r11
  bfx::Area *v17; // r10
  int v18; // r7
  int v19; // r9

  v2 = 0;
  m_pAreaBuf = this->m_pAreaBuf;
  v4 = &m_pAreaBuf[this->m_pHeader->m_areaBytes];
  while ( 1 )
  {
    if ( m_pAreaBuf < v4 || (v5 = 1, v2 < this->m_allocatedAreasOwned.m_size) )
      v5 = 0;
    if ( v5 != 0 )
      break;
    if ( m_pAreaBuf >= v4 )
      v6 = this->m_allocatedAreasOwned.m_data[v2];
    else
      v6 = (bfx::Area *)m_pAreaBuf;
    m_data = v6->m_dynAreaData.m_data;
    v8 = (bfx::Area *)(m_data + 20);
    if ( m_data != nullptr )
    {
      v9 = *(_DWORD *)m_data;
    }
    else
    {
      v8 = nullptr;
      v9 = 0;
    }
    v10 = 0;
    if ( v9 != 0 )
    {
      while ( v8 != pDynArea )
      {
        ++v10;
        v8 = (bfx::Area *)((char *)v8 + 24 * (v8->m_flags.m_flags1 & 0x7F) + 72);
        if ( v10 == v9 )
          goto LABEL_16;
      }
      return v6;
    }
LABEL_16:
    if ( m_pAreaBuf >= v4 )
      ++v2;
    else
      m_pAreaBuf += 24 * (*((_DWORD *)m_pAreaBuf + 10) & 0x7F) + 56;
  }
  m_size = this->m_allocatedAreasOwned.m_size;
  v13 = 0;
  if ( m_size <= 0 )
    return nullptr;
  v14 = this->m_allocatedAreasOwned.m_data;
  for ( i = 0; ; ++i )
  {
    result = v14[i];
    v16 = result->m_dynAreaData.m_data;
    v17 = (bfx::Area *)(v16 + 20);
    if ( v16 != nullptr )
    {
      v18 = *(_DWORD *)v16;
    }
    else
    {
      v17 = nullptr;
      v18 = 0;
    }
    v19 = 0;
    if ( v18 != 0 )
      break;
LABEL_29:
    if ( ++v13 >= m_size )
      return nullptr;
  }
  while ( v17 != pDynArea )
  {
    ++v19;
    v17 = (bfx::Area *)((char *)v17 + 24 * (v17->m_flags.m_flags1 & 0x7F) + 72);
    if ( v19 == v18 )
      goto LABEL_29;
  }
  return result;
}


// ========================================================================
// ?DrawAreaInGraph@bfx@@YAXPBVSpace@1@PAVArea@1@@Z
// EA  : 0x83277070
// RVA : 0x01277070
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::DrawAreaInGraph(bfx::Space *pSpace, bfx::Vec3 *pArea, __int64 a3)
{
  unsigned __int8 *v5; // r16
  unsigned __int64 v6; // r8
  unsigned int v7; // r9
  float *p_m_a; // r10
  float *p_m_x; // r11
  float v10; // r7
  float v11; // r8
  double m_y; // fp12
  signed int v13; // r30
  int v14; // r31
  float *p_m_z; // r29
  bfx::Area *v16; // r23
  unsigned int v17; // r21
  bfx::AreaProxy *m_pProxy; // r10
  double v19; // fp13
  double v20; // fp12
  bfx::Vec3 *v21; // r4
  const bfx::Color *v22; // r6
  bfx::Vec3 *v23; // r11
  double v24; // fp10
  double v25; // fp9
  unsigned int m_z_low; // r11
  signed int m_x_low; // r11
  const bfx::Vec3 *v28; // r4
  const bfx::Vec3 *v29; // r5
  double v30; // fp13
  double v31; // fp12
  bfx::Vec3 *v32; // r11
  double v33; // fp10
  double v34; // fp9
  double v35; // fp13
  double v36; // fp12
  bfx::Vec3 *v37; // r11
  double v38; // fp10
  double v39; // fp9
  double v40; // fp13
  double v41; // fp12
  bfx::Vec3 *v42; // r11
  double v43; // fp10
  double m_z; // fp9
  unsigned int m_y_low; // r31
  bfx::Color *v46; // r11
  unsigned int v47; // r11
  bfx::AreaProxy *m_r_low; // r9
  int v49; // r10
  unsigned int v50; // r4
  bfx::Color *v51; // r3
  int v52; // r31
  int v53; // r30
  float v54; // r10
  float m_x; // r9
  double Scale; // fp1
  const bfx::Color *v57; // r5
  double v58; // fp31
  float *v59; // r3
  double v60; // fp9
  double v61; // fp7
  double v62; // fp6
  signed int v63; // r30
  signed int v64; // r11
  bfx::Area *v65; // r31
  float *v66; // r10
  float v67; // r8
  float v68; // r5
  float v69; // r4
  float v70; // r26
  float v71; // r24
  float v72; // r23
  unsigned int v73; // r22
  float *v74; // r11
  float v75; // r9
  float v76; // r8
  float v77; // r11
  float v78; // r9
  float v79; // r8
  float v80; // r11
  float v81; // r8
  float v82; // r10
  __int64 v83; // r6
  __int64 v84; // r10
  __int64 v85; // r6
  __int64 v86; // r10
  __int64 v87; // r10
  unsigned int v88; // r10
  unsigned int v89; // r11
  unsigned int v90; // r10
  __int64 v91; // r8
  _DWORD *v92; // r30
  int v93; // r11
  int v94; // r29
  int v95; // r31
  int Name; // r3
  bfx::Vec3 *v97; // r10
  unsigned __int8 *v98; // r11
  int v99; // r9
  unsigned __int8 *v100; // r11
  int m_x_high; // r9
  unsigned __int8 *v102; // r11
  int v103; // r9
  __int64 v104; // r10
  __int64 v105; // r8
  __int64 v106; // r6
  __int64 v107; // r6
  __int64 v108; // r10
  __int64 v109; // r10
  int v110; // [sp+8h] [-CA8h]
  int v111; // [sp+Ch] [-CA4h]
  int v112; // [sp+10h] [-CA0h]
  int v113; // [sp+14h] [-C9Ch]
  int v114; // [sp+18h] [-C98h]
  int v115; // [sp+1Ch] [-C94h]
  int v116; // [sp+20h] [-C90h]
  int v117; // [sp+24h] [-C8Ch]
  bfx::Vec3 v118; // [sp+50h] [-C60h] BYREF
  bfx::Area v119; // [sp+60h] [-C50h] BYREF
  float v120; // [sp+98h] [-C18h]
  bfx::Vec3 v121; // [sp+A0h] [-C10h] BYREF
  bfx::Vec3 v122; // [sp+B0h] [-C00h] BYREF
  bfx::Vec3 v123; // [sp+C0h] [-BF0h] BYREF
  bfx::Vec3 v124; // [sp+D0h] [-BE0h] BYREF
  bfx::Vec3 v125; // [sp+E0h] [-BD0h] BYREF
  bfx::Vec3 v126; // [sp+F0h] [-BC0h] BYREF
  bfx::Vec3 v127; // [sp+100h] [-BB0h] BYREF
  bfx::Vec3 v128; // [sp+110h] [-BA0h] BYREF
  bfx::Vec3 v129; // [sp+120h] [-B90h] BYREF
  float v130[8]; // [sp+130h] [-B80h] BYREF
  float v131[8]; // [sp+150h] [-B60h] BYREF
  bfx::Vec3 v132; // [sp+170h] [-B40h] BYREF
  float v133; // [sp+17Ch] [-B34h]
  float v134; // [sp+180h] [-B30h]
  float v135; // [sp+184h] [-B2Ch]
  float v136[8]; // [sp+190h] [-B20h] BYREF
  float v137[8]; // [sp+1B0h] [-B00h] BYREF
  bfx::Vec3 v138; // [sp+1D0h] [-AE0h] BYREF
  float v139; // [sp+1DCh] [-AD4h]
  float v140; // [sp+1E0h] [-AD0h]
  float v141; // [sp+1E4h] [-ACCh]
  bfx::Color v142; // [sp+1F0h] [-AC0h] BYREF
  bfx::Color v143; // [sp+200h] [-AB0h] BYREF
  bfx::Color v144; // [sp+210h] [-AA0h] BYREF
  bfx::Vec3 v145; // [sp+220h] [-A90h] BYREF
  char v146; // [sp+22Ch] [-A84h] BYREF
  _BYTE v147[1024]; // [sp+820h] [-490h] BYREF

  LODWORD(v6) = bfx::g_pCurInstance->m_pComponentManager->m_components[1];
  v5 = *(unsigned __int8 **)(v6 + 36);
  HIDWORD(v6) = *v5;
  if ( *v5 != 0 || v5[1] != 0 )
  {
    v7 = LODWORD(pArea[3].m_y) & 0x7F;
    if ( v7 != 0 )
    {
      p_m_a = &v144.m_a;
      p_m_x = &pArea[5].m_x;
      do
      {
        --v7;
        v10 = p_m_x[2];
        v11 = *p_m_x;
        v118.m_y = p_m_x[1];
        p_m_x += 6;
        m_y = v118.m_y;
        v118.m_z = v10;
        v118.m_x = v11;
        p_m_a[1] = v11;
        p_m_a[2] = m_y;
        p_m_a += 3;
        *p_m_a = v10;
      }
      while ( v7 != 0 );
    }
    v142 = ColorRed_9;
    if ( (_S1_2 & 1) == 0 )
    {
      _S1_2 |= 1u;
      colPermeable.m_r = 1.0;
      colPermeable.m_g = 0.60000002;
      colPermeable.m_b = 0.1;
      colPermeable.m_a = 1.0;
    }
    *(float *)&v6 = ColorYellow_9.m_r;
    LODWORD(v6) = &v143;
    LODWORD(a3) = LODWORD(ColorYellow_9.m_g);
    v143 = ColorYellow_9;
    if ( *v5 != 0 )
    {
      v13 = LODWORD(pArea[3].m_y) & 0x7F;
      if ( v13 != 0 )
      {
        v14 = 1;
        p_m_z = &v145.m_z;
        v16 = (bfx::Area *)&pArea[4].m_z;
        v17 = LODWORD(pArea[3].m_y) & 0x7F;
        while ( 1 )
        {
          m_pProxy = v16->m_pProxy;
          if ( (LODWORD(v16->m_pos.m_x) & 0x6000) == 0x2000 )
            break;
          if ( (LODWORD(pArea[3].m_y) & 0x20000000) != 0
            || m_pProxy != nullptr && ((int)m_pProxy[5].m_pArea & 0x20000000) != 0 )
          {
            v40 = *(p_m_z - 1);
            v41 = *p_m_z;
            v136[0] = *(p_m_z - 2);
            v136[1] = v40;
            v136[2] = v41;
            v21 = (bfx::Vec3 *)v136;
            v22 = &v142;
            v42 = &v145 + v14 % v13;
            v43 = v42->m_y;
            m_z = v42->m_z;
            v136[3] = v42->m_x;
            v136[4] = v43;
            v136[5] = m_z;
            goto LABEL_30;
          }
          m_z_low = LODWORD(pArea[3].m_z);
          if ( (m_z_low & 0xF0000) > 0x10000 || m_pProxy != nullptr && (HIWORD(m_pProxy[5].m_refCount) & 0xFu) > 1 )
          {
            v35 = *(p_m_z - 1);
            v36 = *p_m_z;
            v131[0] = *(p_m_z - 2);
            v131[1] = v35;
            v131[2] = v36;
            v21 = (bfx::Vec3 *)v131;
            v22 = &colPermeable;
            v37 = &v145 + v14 % v13;
            v38 = v37->m_y;
            v39 = v37->m_z;
            v131[3] = v37->m_x;
            v131[4] = v38;
            v131[5] = v39;
            goto LABEL_30;
          }
          if ( (m_z_low & 0xF00000) > 0x100000 )
            goto LABEL_27;
          if ( m_pProxy == nullptr )
            goto LABEL_24;
          if ( (m_pProxy[5].m_refCount & 0xF00000u) > 0x100000 )
          {
LABEL_27:
            v30 = *(p_m_z - 1);
            v31 = *p_m_z;
            v137[0] = *(p_m_z - 2);
            v137[1] = v30;
            v137[2] = v31;
            v21 = (bfx::Vec3 *)v137;
            v22 = &v143;
            v32 = &v145 + v14 % v13;
            v33 = v32->m_y;
            v34 = v32->m_z;
            v137[3] = v32->m_x;
            v137[4] = v33;
            v137[5] = v34;
            goto LABEL_30;
          }
          if ( (unsigned int)m_pProxy[6].m_pArea >> 31 == LODWORD(pArea[4].m_x) >> 31 )
          {
LABEL_24:
            m_x_low = LODWORD(pArea[4].m_x);
            __twllei(v13, 0);
            v28 = (const bfx::Vec3 *)(p_m_z - 2);
            __twlgei(v13 & ~(__ROL4__(v14, 1) - 1), 0xFFFFFFFF);
            v29 = &v145 + v14 % v13;
            if ( m_x_low >= 0 )
              bfx::DrawLine(pSpace, v0: v28, v1: v29, color: &ColorGreen_9);
            else
              bfx::DrawLine(pSpace, v0: v28, v1: v29, color: &ColorMagenta_9);
            goto LABEL_31;
          }
          __twllei(v13, 0);
          __twlgei(v13 & ~(__ROL4__(v14, 1) - 1), 0xFFFFFFFF);
          bfx::DrawLine(pSpace, v0: (const bfx::Vec3 *)(p_m_z - 2), v1: &v145 + v14 % v13, color: &ColorBlue_9);
LABEL_31:
          --v17;
          v16 = (bfx::Area *)((char *)v16 + 24);
          ++v14;
          p_m_z += 3;
          if ( v17 == 0 )
            goto LABEL_32;
        }
        v19 = *(p_m_z - 1);
        v20 = *p_m_z;
        v130[0] = *(p_m_z - 2);
        v130[1] = v19;
        v130[2] = v20;
        v21 = (bfx::Vec3 *)v130;
        v22 = &PORTAL_COLOR;
        v23 = &v145 + v14 % v13;
        v24 = v23->m_y;
        v25 = v23->m_z;
        v130[3] = v23->m_x;
        v130[4] = v24;
        v130[5] = v25;
LABEL_30:
        __twllei(v13, 0);
        __twlgei(v13 & ~(__ROL4__(v14, 1) - 1), 0xFFFFFFFF);
        bfx::DrawLineList(pSpace, pVerts: v21, numVerts: 2, color: v22);
        goto LABEL_31;
      }
    }
LABEL_32:
    if ( v5[1] != 0 )
    {
      m_y_low = LODWORD(pArea[3].m_y);
      v6 = __PAIR64__(LODWORD(ColorGreen_9.m_b), LODWORD(ColorGreen_9.m_g));
      LODWORD(a3) = LODWORD(ColorGreen_9.m_a);
      v119.m_pProxy = (bfx::AreaProxy *)LODWORD(ColorGreen_9.m_r);
      v119.m_dynAreaData.m_data = (char *)LODWORD(ColorGreen_9.m_g);
      v119.m_pFirstLink = (bfx::HalfLink *)LODWORD(ColorGreen_9.m_b);
      v119.m_pSearchParent = (bfx::Area *)LODWORD(ColorGreen_9.m_a);
      if ( (m_y_low & 0x20000000) != 0 )
      {
        v46 = &v142;
      }
      else
      {
        v47 = LODWORD(pArea[3].m_z);
        if ( (v47 & 0xF0000) > 0x10000 )
        {
          v6 = __PAIR64__(LODWORD(colPermeable.m_a), LODWORD(colPermeable.m_b));
          v119.m_pProxy = (bfx::AreaProxy *)LODWORD(colPermeable.m_r);
          v119.m_dynAreaData.m_data = (char *)LODWORD(colPermeable.m_g);
          v119.m_pFirstLink = (bfx::HalfLink *)LODWORD(colPermeable.m_b);
          v119.m_pSearchParent = (bfx::Area *)LODWORD(colPermeable.m_a);
          goto LABEL_42;
        }
        if ( pArea[4].m_x < 0.0 )
        {
          v6 = __PAIR64__(LODWORD(ColorMagenta_9.m_a), LODWORD(ColorMagenta_9.m_b));
          v119.m_pProxy = (bfx::AreaProxy *)LODWORD(ColorMagenta_9.m_r);
          v119.m_dynAreaData.m_data = (char *)LODWORD(ColorMagenta_9.m_g);
          v119.m_pFirstLink = (bfx::HalfLink *)LODWORD(ColorMagenta_9.m_b);
          v119.m_pSearchParent = (bfx::Area *)LODWORD(ColorMagenta_9.m_a);
          goto LABEL_42;
        }
        if ( (v47 & 0xF00000) <= 0x100000 )
        {
LABEL_42:
          v49 = v5[8];
          *(float *)&v119.m_pSearchParent = 0.25;
          if ( v49 != 0 )
          {
            v50 = LODWORD(pArea[3].m_x);
            if ( v50 != 0 )
            {
              v51 = bfx::GenerateRandomColorForAreas(result: &v144, seedNum: v50);
              v119.m_pProxy = (bfx::AreaProxy *)LODWORD(v51->m_r);
              v119.m_dynAreaData.m_data = (char *)LODWORD(v51->m_g);
              LODWORD(v6) = LODWORD(v51->m_b);
              v119.m_pFirstLink = (bfx::HalfLink *)v6;
              *(float *)&v6 = v51->m_a;
              v119.m_pSearchParent = (bfx::Area *)HIDWORD(v6);
            }
          }
          v52 = (m_y_low & 0x7F) - 2;
          if ( v52 > 0 )
          {
            HIDWORD(a3) = &v146;
            do
            {
              v53 = HIDWORD(a3) + 12;
              bfx::DrawSolidTri(
                (bfx::Vector3 *)pSpace,
                v0: &v145,
                v1: (const bfx::Vec3 *)HIDWORD(a3),
                v2: (const bfx::Vec3 *)(HIDWORD(a3) + 12),
                color: (const bfx::Color *)&v119);
              --v52;
              HIDWORD(a3) = v53;
            }
            while ( v52 != 0 );
          }
          goto LABEL_48;
        }
        v46 = &v143;
      }
      LODWORD(a3) = LODWORD(v46->m_a);
      *(float *)&v6 = v46->m_b;
      LODWORD(v6) = LODWORD(v46->m_g);
      m_r_low = (bfx::AreaProxy *)LODWORD(v46->m_r);
      v119.m_pFirstLink = (bfx::HalfLink *)HIDWORD(v6);
      v119.m_pSearchParent = (bfx::Area *)a3;
      v119.m_dynAreaData.m_data = (char *)v6;
      v119.m_pProxy = m_r_low;
      goto LABEL_42;
    }
  }
LABEL_48:
  if ( v5[3] != 0 )
  {
    v54 = pArea[1].m_z;
    m_x = pArea[2].m_x;
    v118.m_x = pArea[1].m_y;
    v118.m_y = v54;
    v118.m_z = m_x;
    Scale = bfx::GetScale();
    bfx::DrawCross(
      pSpace,
      pos: &v118,
      radius: (float)((float)Scale * (float)0.050000001),
      color: v57,
      a5: &ColorYellow_9);
    v58 = bfx::GetScale();
    v59 = (float *)bfx::Area::CalcNormal(this: &v119, result: pArea);
    v60 = (float)(*v59 * (float)v58);
    v61 = (float)(v59[1] * (float)v58);
    v62 = (float)(v59[2] * (float)v58);
    v138.m_x = v118.m_x;
    v138.m_y = v118.m_y;
    v138.m_z = v118.m_z;
    v139 = v118.m_x + (float)v60;
    v140 = v118.m_y + (float)v61;
    v141 = v118.m_z + (float)v62;
    bfx::DrawLineList(pSpace, pVerts: &v138, numVerts: 2, color: &ColorYellow_9);
  }
  if ( v5[2] != 0 )
  {
    v63 = 0;
    v64 = LODWORD(pArea[3].m_y) & 0x7F;
    if ( v64 != 0 )
    {
      v65 = (bfx::Area *)&pArea[4].m_z;
      do
      {
        v66 = (float *)v65->m_pProxy;
        if ( v65->m_pProxy != nullptr )
        {
          v67 = *(float *)&v65->m_dynAreaData.m_data;
          v68 = *(float *)&v65->m_pFirstLink;
          __twllei(v64, 0);
          v69 = *(float *)&v65->m_pSearchParent;
          v70 = pArea[1].m_y;
          v71 = pArea[1].m_z;
          v121.m_x = v67;
          v121.m_y = v68;
          v72 = pArea[2].m_x;
          v121.m_z = v69;
          v73 = v64 & ~(__ROL4__(v63 + 1, 1) - 1);
          v74 = &pArea[2 * ((v63 + 1) % v64)].m_x;
          __twlgei(v73, 0xFFFFFFFF);
          v75 = v74[16];
          v76 = v74[15];
          v77 = v74[17];
          v123.m_x = v76;
          v123.m_y = v75;
          v123.m_z = v77;
          v78 = v66[4];
          v79 = v66[5];
          v80 = v66[6];
          v125.m_x = v70;
          v125.m_y = v71;
          v125.m_z = v72;
          v122.m_x = v78;
          v122.m_y = v79;
          v122.m_z = v80;
          bfx::GetClosestPtOnLineSegAToLineB(result: &v127, startA: &v121, endA: &v123, startB: &v125, endB: &v122);
          v81 = pArea[1].m_z;
          v82 = pArea[2].m_x;
          v119.m_pProxy = (bfx::AreaProxy *)LODWORD(pArea[1].m_y);
          v133 = v127.m_x;
          *(float *)&v119.m_dynAreaData.m_data = v81;
          *(float *)&v119.m_pFirstLink = v82;
          v134 = v127.m_y;
          v135 = v127.m_z;
          v132.m_z = v82;
          v132.m_y = v81;
          v132.m_x = *(float *)&v119.m_pProxy;
          bfx::DrawLineList(pSpace, pVerts: &v132, numVerts: 2, color: &ColorWhite_9);
        }
        ++v63;
        v65 = (bfx::Area *)((char *)v65 + 24);
        v64 = LODWORD(pArea[3].m_y) & 0x7F;
      }
      while ( v63 < v64 );
    }
  }
  if ( bfx::g_drawPlannerIslands )
  {
    HIDWORD(v83) = "%d";
    LODWORD(v84) = LODWORD(pArea[1].m_z);
    *(float *)&v84 = pArea[2].m_x;
    LODWORD(v6) = LODWORD(pArea[3].m_y);
    v124.m_x = pArea[1].m_y;
    LODWORD(v83) = ((unsigned int)v6 >> 7) & 0x1FFFF;
    *(_QWORD *)&v124.m_y = __PAIR64__(v84, HIDWORD(v84));
    bfx::DrawString(
      (bfx::Vector3 *)pSpace,
      inputPos: &v124,
      fmt: v83,
      a4: v6,
      a5: v84,
      a6: v110,
      a7: v111,
      a8: v112,
      a9: v113,
      a10: v114,
      a11: v115,
      a12: v116,
      a13: v117);
  }
  if ( bfx::g_drawAreaUsageCount )
  {
    HIDWORD(v85) = "%d";
    LODWORD(v86) = LODWORD(pArea[1].m_z);
    *(float *)&v86 = pArea[2].m_x;
    LODWORD(v6) = LODWORD(pArea[4].m_y);
    LODWORD(v85) = v6 & 0x3FF;
    v129.m_x = pArea[1].m_y;
    *(_QWORD *)&v129.m_y = __PAIR64__(v86, HIDWORD(v86));
    bfx::DrawString(
      (bfx::Vector3 *)pSpace,
      inputPos: &v129,
      fmt: v85,
      a4: v6,
      a5: v86,
      a6: v110,
      a7: v111,
      a8: v112,
      a9: v113,
      a10: v114,
      a11: v115,
      a12: v116,
      a13: v117);
  }
  if ( v5[6] != 0 )
  {
    if ( (LODWORD(pArea[3].m_y) & 0x20000000) != 0 )
    {
      LODWORD(v87) = &off_822B0000;
      *(float *)&v87 = pArea[1].m_z;
      LODWORD(v6) = LODWORD(pArea[2].m_x);
      HIDWORD(a3) = "---";
      v126.m_x = pArea[1].m_y;
      v126.m_y = *(float *)&v87;
      LODWORD(v126.m_z) = v6;
      bfx::DrawString(
        (bfx::Vector3 *)pSpace,
        inputPos: &v126,
        fmt: a3,
        a4: v6,
        a5: v87,
        a6: v110,
        a7: v111,
        a8: v112,
        a9: v113,
        a10: v114,
        a11: v115,
        a12: v116,
        a13: v117);
    }
    else
    {
      v88 = LODWORD(pArea[3].m_z);
      v89 = (v88 >> 20) & 0xF;
      v90 = HIWORD(v88) & 0xF;
      if ( v90 > v89 )
        v89 = v90;
      LODWORD(v91) = LODWORD(pArea[1].m_z);
      *(float *)&v91 = pArea[2].m_x;
      v128.m_x = pArea[1].m_y;
      v128.m_z = *(float *)&v91;
      LODWORD(v128.m_y) = v91;
      bfx::DrawString(
        (bfx::Vector3 *)pSpace,
        inputPos: &v128,
        fmt: __SPAIR64__("%u", v89),
        a4: v91,
        a5: __SPAIR64__(&g_ThumbnailCaptureVS[702], LODWORD(v128.m_x)),
        a6: v110,
        a7: v111,
        a8: v112,
        a9: v113,
        a10: v114,
        a11: v115,
        a12: v116,
        a13: v117);
    }
  }
  if ( bfx::g_drawAreaObstacleLists && (LODWORD(pArea[3].m_y) & 0x40000000) != 0 )
  {
    v92 = (_DWORD *)&pArea[-2].m_z;
    if ( pArea != (bfx::Vec3 *)16 )
    {
      v93 = v92[1];
      if ( v93 != 0 )
      {
        v94 = 0;
        v147[0] = 0;
        if ( v93 > 0 )
        {
          v95 = 0;
          do
          {
            Name = idFile_MTP::GetName(pObstacle: *(bfx::ObstacleImpl **)(*v92 + v95));
            sprintf_0(string: (char *)&v145, format: "%d,", Name);
            v97 = &v145;
            v98 = v147;
            do
              v99 = *v98++;
            while ( v99 != 0 );
            v100 = v98 - 1;
            do
            {
              m_x_high = HIBYTE(v97->m_x);
              v97 = (bfx::Vec3 *)((char *)v97 + 1);
              *v100++ = m_x_high;
            }
            while ( m_x_high != 0 );
            ++v94;
            v95 += 4;
          }
          while ( v94 < v92[1] );
        }
        v102 = v147;
        do
          v103 = *v102++;
        while ( v103 != 0 );
        LODWORD(v104) = v147;
        *(float *)&v104 = pArea[1].m_y;
        HIDWORD(v105) = v102 - v147 - 1;
        LODWORD(v105) = LODWORD(pArea[1].m_z);
        v120 = pArea[2].m_x;
        HIDWORD(v106) = "%s";
        v119.m_flags.m_flags3 = HIDWORD(v104);
        v119.m_flags.m_flags4 = v105;
        LODWORD(v106) = v147;
        v147[HIDWORD(v105) - 1] = 0;
        bfx::DrawString(
          (bfx::Vector3 *)pSpace,
          inputPos: (const bfx::Vec3 *)&v119.m_flags.m_flags3,
          fmt: v106,
          a4: v105,
          a5: v104,
          a6: v110,
          a7: v111,
          a8: v112,
          a9: v113,
          a10: v114,
          a11: v115,
          a12: v116,
          a13: v117);
      }
    }
  }
  if ( v5[7] != 0 )
  {
    HIDWORD(v107) = "%x";
    LODWORD(v108) = LODWORD(pArea[1].m_z);
    *(float *)&v108 = pArea[2].m_x;
    LODWORD(v107) = LODWORD(pArea[3].m_x);
    v119.m_pos.m_x = pArea[1].m_y;
    v119.m_pos.m_z = *(float *)&v108;
    LODWORD(v119.m_pos.m_y) = v108;
    bfx::DrawString(
      (bfx::Vector3 *)pSpace,
      inputPos: &v119.m_pos,
      fmt: v107,
      a4: v6,
      a5: v108,
      a6: v110,
      a7: v111,
      a8: v112,
      a9: v113,
      a10: v114,
      a11: v115,
      a12: v116,
      a13: v117);
  }
  if ( bfx::g_drawAreaPtrs )
  {
    LODWORD(v109) = LODWORD(pArea[1].m_z);
    *(float *)&v109 = pArea[2].m_x;
    v119.m_searchCost = LODWORD(pArea[1].m_y);
    v119.m_flags.m_flags1 = HIDWORD(v109);
    v119.m_usageFlags = v109;
    bfx::DrawString(
      (bfx::Vector3 *)pSpace,
      inputPos: (const bfx::Vec3 *)&v119.m_searchCost,
      fmt: __SPAIR64__("%x", (unsigned int)pArea),
      a4: v6,
      a5: v109,
      a6: v110,
      a7: v111,
      a8: v112,
      a9: v113,
      a10: v114,
      a11: v115,
      a12: v116,
      a13: v117);
  }
}


// ========================================================================
// ??0NavLayer@bfx@@QAA@PAVSpace@1@H@Z
// EA  : 0x83277EA8
// RVA : 0x01277EA8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

bfx::NavLayer *__fastcall bfx::NavLayer::NavLayer(bfx::NavLayer *this, bfx::Space *pSpace, int layerIndex)
{
  unsigned __int64 v4; // r29
  bfx::IslandGraph *v5; // r3
  bfx::IslandGraph *v6; // r3
  int *p_m_endGraphIndex; // r11
  int i; // ctr

  this->m_pSpace = pSpace;
  LODWORD(v4) = 0;
  this->m_layerIndex = layerIndex;
  HIDWORD(v4) = &this->m_navGraphSpatialOrg;
  this->m_numGraphs = 0;
  this->m_endGraphIndex = 0;
  this->m_pXGraph = nullptr;
  bfx::NavGraphSpatialOrganization::NavGraphSpatialOrganization(this: &this->m_navGraphSpatialOrg);
  this->m_areaInvalidationTimestamp = v4;
  this->m_addRemoveNavGraphInProgress = false;
  this->m_shapeDat.m_radius = 0.0;
  this->m_shapeDat.m_step = 0.0;
  this->m_shapeDat.m_height = 0.0;
  v5 = (bfx::IslandGraph *)bfx::MemoryManager::Malloc(
                             this: bfx::g_pCurInstance->m_pMemoryManager,
                             size: 0x2Cu,
                             tag: bfx::MEM_ISLANDS);
  if ( v5 != nullptr )
    v6 = bfx::IslandGraph::IslandGraph(this: v5);
  else
    v6 = nullptr;
  this->m_pIslandGraph = v6;
  p_m_endGraphIndex = &this->m_endGraphIndex;
  for ( i = 2048; i != 0; --i )
    *++p_m_endGraphIndex = 0;
  this->m_pXGraph = bfx::CreateXGraph(pNavLayer: this);
  *(_DWORD *)HIDWORD(v4) = this;
  return this;
}


// ========================================================================
// __unwind$44375
// EA  : 0x83277F6C
// RVA : 0x01277F6C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_44375()
{
  int v0; // r12

  bfx::NavGraphSpatialOrganization::~NavGraphSpatialOrganization(this: (bfx::NavGraphSpatialOrganization *)(*(_DWORD *)(v0 - 128 + 148) + 8228));
}


// ========================================================================
// __unwind$44376
// EA  : 0x83277F98
// RVA : 0x01277F98
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_44376()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 128 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ??1NavLayer@bfx@@QAA@XZ
// EA  : 0x83277FD0
// RVA : 0x01277FD0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::NavLayer::~NavLayer(bfx::NavLayer *this)
{
  bfx::XGraph *m_pXGraph; // r3
  bfx::IslandGraph *m_pIslandGraph; // r29

  m_pXGraph = this->m_pXGraph;
  if ( m_pXGraph != nullptr )
    ((void (__fastcall *)(bfx::XGraph *, int))m_pXGraph->dtr_XGraph)(a1: m_pXGraph, a2: 1);
  m_pIslandGraph = this->m_pIslandGraph;
  this->m_pXGraph = nullptr;
  if ( m_pIslandGraph != nullptr )
  {
    bfx::IslandGraph::~IslandGraph(this: m_pIslandGraph);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)m_pIslandGraph);
  }
  this->m_pIslandGraph = nullptr;
  bfx::NavGraphSpatialOrganization::~NavGraphSpatialOrganization(this: &this->m_navGraphSpatialOrg);
}


// ========================================================================
// __unwind$44415
// EA  : 0x8327804C
// RVA : 0x0127804C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_44415()
{
  int v0; // r12

  bfx::NavGraphSpatialOrganization::~NavGraphSpatialOrganization(this: (bfx::NavGraphSpatialOrganization *)(*(_DWORD *)(v0 - 128 + 148) + 8228));
}


// ========================================================================
// ??EActiveAreasCursor@bfx@@QAAXXZ
// EA  : 0x832780D8
// RVA : 0x012780D8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::ActiveAreasCursor::operator++(bfx::ActiveAreasCursor *this)
{
  char *m_pCur; // r10
  char *m_pEnd; // r9
  char *v3; // r11
  _DWORD *v4; // r11
  bfx::Area *m_pCurDynArea; // r10
  unsigned int m_flags1; // r9

  m_pCur = this->m_staticCC.m_pCur;
  m_pEnd = this->m_staticCC.m_pEnd;
  if ( this->m_staticCC.m_pCur >= m_pEnd )
    v3 = (char *)this->m_staticCC.m_cc.m_pArray->m_data[this->m_staticCC.m_cc.m_i];
  else
    v3 = this->m_staticCC.m_pCur;
  v4 = *((_DWORD **)v3 + 1);
  if ( v4 == nullptr || *v4 == 0 )
  {
    if ( m_pCur >= m_pEnd )
      ++this->m_staticCC.m_cc.m_i;
    else
      this->m_staticCC.m_pCur = &m_pCur[24 * (*((_DWORD *)m_pCur + 10) & 0x7F) + 56];
LABEL_9:
    bfx::ActiveAreasCursor::InitDynCC(this);
    return;
  }
  m_pCurDynArea = this->m_dynCC.m_pCurDynArea;
  m_flags1 = m_pCurDynArea->m_flags.m_flags1;
  ++this->m_dynCC.m_i;
  this->m_dynCC.m_pCurDynArea = (bfx::Area *)((char *)m_pCurDynArea + 24 * (m_flags1 & 0x7F) + 72);
  if ( this->m_dynCC.m_i == this->m_dynCC.m_numDynAreas )
  {
    if ( this->m_staticCC.m_pCur >= this->m_staticCC.m_pEnd )
      ++this->m_staticCC.m_cc.m_i;
    else
      this->m_staticCC.m_pCur += 24 * (*((_DWORD *)this->m_staticCC.m_pCur + 10) & 0x7F) + 56;
    goto LABEL_9;
  }
}


// ========================================================================
// ?ConnectPortalEdges@bfx@@YA_NPAVNavGraph@1@AAVEdgeCursor@1@1@Z
// EA  : 0x832781F0
// RVA : 0x012781F0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

int __fastcall bfx::ConnectPortalEdges(
        bfx::NavGraph *pNewNavGraph,
        bfx::EdgeCursor *myPortalEdgeCC,
        bfx::EdgeCursor *theirPortalEdgeCC)
{
  bfx::Area *m_pArea; // r30
  int m_i; // r11
  bfx::NavLayer *m_pNavLayer; // r25
  int v9; // r10
  bfx::Area *v10; // r29
  int v11; // r5
  signed int v12; // r3
  float *v13; // r6
  int v14; // r9
  float *v15; // r11
  int v16; // r7
  bfx::DynAreaData *v17; // r31
  float v18; // r8
  float v19; // r10
  float v20; // r4
  float v21; // r4
  float v22; // r8
  signed int v23; // r10
  char *v24; // r11
  float v25; // r5
  float v26; // r4
  unsigned int m_graphIndex; // r7
  float v28; // r9
  float v29; // r10
  unsigned int m_flags2; // r5
  unsigned int v31; // r11
  bfx::Area *v32; // r31
  int v33; // r10
  int v34; // r9
  int v35; // r8
  int v36; // r7
  int v37; // r6
  int v38; // r5
  __int16 m_flags3_high; // r11
  bfx::NavGraph *v40; // r26
  bfx::NavGraph *v41; // r25
  int v42; // r10
  int v43; // r9
  int v44; // r8
  int v45; // r7
  int v46; // r6
  int v47; // r5
  int v48; // r10
  int v49; // r9
  int v50; // r8
  int v51; // r7
  int v52; // r6
  int v53; // r5
  bfx::Area *v54; // r9
  int v56; // [sp+8h] [-C8h]
  int v57; // [sp+8h] [-C8h]
  int v58; // [sp+8h] [-C8h]
  int v59; // [sp+Ch] [-C4h]
  int v60; // [sp+Ch] [-C4h]
  int v61; // [sp+Ch] [-C4h]
  int v62; // [sp+10h] [-C0h]
  int v63; // [sp+10h] [-C0h]
  int v64; // [sp+10h] [-C0h]
  int v65; // [sp+14h] [-BCh]
  int v66; // [sp+14h] [-BCh]
  int v67; // [sp+14h] [-BCh]
  int v68; // [sp+18h] [-B8h]
  int v69; // [sp+18h] [-B8h]
  int v70; // [sp+18h] [-B8h]
  bfx::Space *v71; // [sp+1Ch] [-B4h]
  bfx::Space *v72; // [sp+1Ch] [-B4h]
  bfx::Space *v73; // [sp+1Ch] [-B4h]
  bfx::EdgeCursor v74; // [sp+50h] [-80h] BYREF
  float v75; // [sp+58h] [-78h]
  bfx::Vec3 v76; // [sp+60h] [-70h] BYREF
  bfx::Area *v77; // [sp+6Ch] [-64h]
  float v78; // [sp+70h] [-60h]
  float v79; // [sp+74h] [-5Ch]
  bfx::Area *v80; // [sp+78h] [-58h]
  float v81; // [sp+7Ch] [-54h]
  float v82; // [sp+80h] [-50h]
  float v83; // [sp+84h] [-4Ch]
  int v84; // [sp+88h] [-48h]
  float v85; // [sp+8Ch] [-44h]

  m_pArea = myPortalEdgeCC->m_pArea;
  m_i = myPortalEdgeCC->m_i;
  m_pNavLayer = pNewNavGraph->m_pNavLayer;
  v9 = theirPortalEdgeCC->m_i;
  v10 = theirPortalEdgeCC->m_pArea;
  v12 = myPortalEdgeCC->m_pArea->m_flags.m_flags1 & 0x7F;
  v13 = (float *)(&myPortalEdgeCC->m_pArea[1].m_dynAreaData + 6 * m_i);
  v14 = __ROL4__(m_i + 1, 1);
  v15 = (float *)((char *)myPortalEdgeCC->m_pArea + 24 * ((m_i + 1) % v12));
  v16 = __ROL4__(v9 + 1, 1) - 1;
  v17 = &theirPortalEdgeCC->m_pArea[1].m_dynAreaData + 6 * v9;
  v11 = v9 + 1;
  v18 = v15[15];
  v19 = v15[16];
  __twllei(v12, 0);
  v20 = v15[17];
  __twlgei(v12 & ~(v14 - 1), 0xFFFFFFFF);
  *(float *)&v74.m_pArea = v18;
  *(float *)&v74.m_i = v19;
  v75 = v20;
  v76.m_z = v20;
  v76.m_y = v19;
  v76.m_x = v18;
  v21 = v13[2];
  v22 = v13[1];
  v74.m_pArea = *(bfx::Area **)v13;
  v75 = v21;
  *(float *)&v74.m_i = v22;
  v77 = v74.m_pArea;
  v78 = v22;
  v79 = v21;
  v23 = v10->m_flags.m_flags1 & 0x7F;
  __twllei(v23, 0);
  __twlgei(v23 & ~v16, 0xFFFFFFFF);
  v24 = (char *)v10 + 24 * (v11 % v23);
  v25 = *((float *)v24 + 16);
  v74.m_pArea = *((bfx::Area **)v24 + 15);
  v26 = *((float *)v24 + 17);
  v80 = v74.m_pArea;
  *(float *)&v74.m_i = v25;
  v75 = v26;
  v82 = v26;
  m_graphIndex = pNewNavGraph->m_graphIndex;
  v81 = v25;
  v28 = *(float *)&v17->m_data;
  v29 = *(float *)&v17[2].m_data;
  v74.m_i = (int)v17[1].m_data;
  *(float *)&v74.m_pArea = v28;
  v75 = v29;
  v85 = v29;
  v83 = v28;
  v84 = v74.m_i;
  m_flags2 = m_pArea->m_flags.m_flags2;
  v31 = (v10->m_flags.m_flags2 >> 20) & 0xF;
  if ( ((m_flags2 >> 20) & 0xF) < v31 )
    v31 = (m_flags2 >> 20) & 0xF;
  v32 = bfx::CreateAllocatedArea(
          vertArray: &v76,
          numVerts: 4,
          islandNumA: 0x1FFFFu,
          planLayer: m_pArea->m_flags.m_flags4 >> 27,
          graphIndex: m_graphIndex,
          userData: m_pArea->m_usageFlags,
          staticCostMult: v31);
  bfx::NavGraph::AddAllocatedArea(
    this: pNewNavGraph,
    pArea: (bfx::Space *)v32,
    a3: v38,
    a4: v37,
    a5: v36,
    a6: v35,
    a7: v34,
    a8: v33,
    a9: v56,
    a10: v59,
    a11: v62,
    a12: v65,
    a13: v68,
    a14: v71);
  m_flags3_high = HIWORD(v10->m_flags.m_flags3);
  v74.m_pArea = v32;
  v40 = m_pNavLayer->m_graphs[m_flags3_high & 0x7FF];
  v41 = m_pNavLayer->m_graphs[HIWORD(m_pArea->m_flags.m_flags3) & 0x7FF];
  bfx::Array<bfx::Portal *>::push_back(
    this: (bfx::Array<bfx::Space *> *)&v40->m_allocatedAreasAdjNonOwned,
    val: (bfx::Space *const *)&v74);
  bfx::NavGraph::AddAdjacentNavGraphRecord(
    this: v41,
    pNavGraph: v40,
    a3: v47,
    a4: v46,
    a5: v45,
    a6: v44,
    a7: v43,
    a8: v42,
    a9: v57,
    a10: v60,
    a11: v63,
    a12: v66,
    a13: v69,
    a14: v72);
  bfx::NavGraph::AddAdjacentNavGraphRecord(
    this: v40,
    pNavGraph: v41,
    a3: v53,
    a4: v52,
    a5: v51,
    a6: v50,
    a7: v49,
    a8: v48,
    a9: v58,
    a10: v61,
    a11: v64,
    a12: v67,
    a13: v70,
    a14: v73);
  v54 = myPortalEdgeCC->m_pArea;
  v74.m_pArea = v32;
  v74.m_i = 1;
  (&v54[1].m_pProxy)[6 * myPortalEdgeCC->m_i] = (bfx::AreaProxy *)v32;
  (&theirPortalEdgeCC->m_pArea[1].m_pProxy)[6 * theirPortalEdgeCC->m_i] = (bfx::AreaProxy *)v32;
  v32[1].m_pProxy = (bfx::AreaProxy *)m_pArea;
  v32[1].m_flags.m_flags3 = (unsigned int)v10;
  LODWORD(v32[1].m_pos.m_x) = LODWORD(v32[1].m_pos.m_x) & 0xFFFF9FFF | 0x2000;
  v32[2].m_pFirstLink = (bfx::HalfLink *)((int)v32[2].m_pFirstLink & 0xFFFF9FFF | 0x2000);
  bfx::ConnectToAdjAllocatedArea(unconnectedSideEdge: &v74);
  v74.m_pArea = (bfx::Area *)&v74;
  v74.m_i = 3;
  bfx::ConnectToAdjAllocatedArea(unconnectedSideEdge: &v74);
  if ( HIBYTE(bfx::g_pCurInstance->m_pComponentManager->m_components[1][5].__vftable) == 0 )
    bfx::CalcAndSetEdgeTraversalCostsForArea(pArea: v32);
  return 1;
}


// ========================================================================
// ?ConnectOverlappingPortalEdges@NavLayer@bfx@@AAAXPAVNavGraph@2@AAV?$Array@VOverlapData@bfx@@@2@@Z
// EA  : 0x832784E8
// RVA : 0x012784E8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::NavLayer::ConnectOverlappingPortalEdges(
        bfx::NavLayer *this,
        bfx::NavGraph *pNewNavGraph,
        bfx::Array<bfx::OverlapData> *overlapData)
{
  int v5; // r29
  int v6; // r31
  bfx::OverlapData *v7; // r4

  v5 = 0;
  if ( overlapData->m_size > 0 )
  {
    v6 = 0;
    do
    {
      v7 = &overlapData->m_data[v6];
      if ( (&v7->m_myPortalEdgeCC.m_pArea[1].m_pProxy)[6 * v7->m_myPortalEdgeCC.m_i] == nullptr
        && (&v7->m_theirPortalEdgeCC.m_pArea[1].m_pProxy)[6 * v7->m_theirPortalEdgeCC.m_i] == nullptr )
      {
        bfx::ConnectPortalEdges(
          pNewNavGraph,
          myPortalEdgeCC: &v7->m_myPortalEdgeCC,
          theirPortalEdgeCC: &v7->m_theirPortalEdgeCC);
      }
      ++v5;
      ++v6;
    }
    while ( v5 < overlapData->m_size );
  }
}


// ========================================================================
// ?GetLinksInPortalAreas@bfx@@YAXAAV?$Array@PAVArea@bfx@@@1@AAV?$Array@PAVLinkBase@bfx@@@1@@Z
// EA  : 0x83278588
// RVA : 0x01278588
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::GetLinksInPortalAreas(
        bfx::Array<bfx::Area *> *allocatedAreas,
        bfx::Array<bfx::SpaceComponent *> *linksOut)
{
  bfx::Array<bfx::Area *> *m_pArray; // r25
  int m_i; // r26
  bfx::Area *m_pCurDynArea; // r27
  bfx::Area *v6; // r11
  char *m_data; // r10
  bfx::HalfLink *i; // r29
  int m_size; // r8
  bfx::LinkBase **v10; // r11
  bfx::LinkBase *m_pLinkBase; // r30
  bfx::LinkBase **v12; // r7
  int m_cap; // r11
  int v14; // r4
  int v15; // r10
  char *v16; // r11
  bfx::ActiveAreasInArrayCursor v17[4]; // [sp+50h] [-60h] BYREF

  v17[0].m_staticCC.m_pArray = allocatedAreas;
  v17[0].m_staticCC.m_i = 0;
  v17[0].m_dynCC.m_pCurDynArea = nullptr;
  v17[0].m_dynCC.m_numDynAreas = 0;
  v17[0].m_dynCC.m_i = 0;
  bfx::ActiveAreasInArrayCursor::InitDynCC(this: v17);
  m_pArray = v17[0].m_staticCC.m_pArray;
  m_i = v17[0].m_staticCC.m_i;
  if ( v17[0].m_staticCC.m_i < v17[0].m_staticCC.m_pArray->m_size )
  {
    m_pCurDynArea = v17[0].m_dynCC.m_pCurDynArea;
    do
    {
      v6 = m_pArray->m_data[m_i];
      m_data = v6->m_dynAreaData.m_data;
      if ( m_data != nullptr && *(_DWORD *)m_data != 0 )
        v6 = m_pCurDynArea;
      for ( i = v6->m_pFirstLink; i != nullptr; i = i->m_pNext )
      {
        m_size = linksOut->m_size;
        v10 = (bfx::LinkBase **)linksOut->m_data;
        m_pLinkBase = i->m_pLinkBase;
        v12 = (bfx::LinkBase **)&linksOut->m_data[m_size];
        if ( (bfx::LinkBase **)linksOut->m_data == v12 )
        {
LABEL_10:
          m_cap = linksOut->m_cap;
          if ( m_cap == m_size )
          {
            v14 = 2 * m_cap;
            if ( m_cap == 0 )
              v14 = 1;
            bfx::Array<bfx::Edge *>::expand_cap(this: linksOut, size: v14);
            v15 = linksOut->m_size;
            if ( &linksOut->m_data[v15] != nullptr )
              linksOut->m_data[v15] = (bfx::SpaceComponent *)m_pLinkBase;
          }
          else if ( v12 != nullptr )
          {
            *v12 = m_pLinkBase;
          }
          ++linksOut->m_size;
        }
        else
        {
          while ( *v10 != m_pLinkBase )
          {
            if ( ++v10 == (bfx::LinkBase **)&linksOut->m_data[linksOut->m_size] )
              goto LABEL_10;
          }
        }
      }
      v16 = m_pArray->m_data[m_i]->m_dynAreaData.m_data;
      if ( v16 != nullptr && *(_DWORD *)v16 != 0 )
      {
        m_pCurDynArea = (bfx::Area *)((char *)m_pCurDynArea + 24 * (m_pCurDynArea->m_flags.m_flags1 & 0x7F) + 72);
        v17[0].m_dynCC.m_pCurDynArea = m_pCurDynArea;
        if ( ++v17[0].m_dynCC.m_i != v17[0].m_dynCC.m_numDynAreas )
          continue;
      }
      v17[0].m_staticCC.m_i = m_i + 1;
      bfx::ActiveAreasInArrayCursor::InitDynCC(this: v17);
      m_pArray = v17[0].m_staticCC.m_pArray;
      m_i = v17[0].m_staticCC.m_i;
      m_pCurDynArea = v17[0].m_dynCC.m_pCurDynArea;
    }
    while ( m_i < m_pArray->m_size );
  }
}


// ========================================================================
// ?ScootSubdivVertsOutwards@bfx@@YAXAAVPortalSubdivData@1@@Z
// EA  : 0x83278738
// RVA : 0x01278738
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::ScootSubdivVertsOutwards(bfx::PortalSubdivData *subdiv)
{
  bfx::PortalSubdivElem *m_data; // r4
  bfx::Array<bfx::PortalSubdivElem> *p_m_subdivElems; // r31
  double v4; // fp31
  double v5; // fp12
  double v6; // fp9
  double v7; // fp6
  int v8; // r11
  double v9; // fp12
  double v10; // fp9
  double v11; // fp6

  if ( subdiv->m_subdivElems.m_size != 0 )
  {
    m_data = subdiv->m_subdivElems.m_data;
    p_m_subdivElems = &subdiv->m_subdivElems;
    v4 = TAN_THRESHOLD_MULT;
    if ( m_data->m_type == PORTAL_SEGMENT_START )
    {
      v5 = (float)(m_data->m_subdivPos.m_y - subdiv->m_edgeSeg.m_v0.m_y);
      v6 = (float)(m_data->m_subdivPos.m_z - subdiv->m_edgeSeg.m_v0.m_z);
      v7 = (float)(m_data->m_subdivPos.m_x - subdiv->m_edgeSeg.m_v0.m_x);
      if ( (float)((float)((float)v7 * (float)v7)
                 + (float)((float)((float)v6 * (float)v6) + (float)((float)v5 * (float)v5))) < (double)(float)(m_data->m_distToNearbyEdgeSq * TAN_THRESHOLD_MULT) )
        bfx::Array<bfx::PortalSubdivElem>::erase(this: &subdiv->m_subdivElems, ptr: m_data);
    }
    v8 = (int)&p_m_subdivElems->m_data[p_m_subdivElems->m_size];
    if ( *(_DWORD *)(v8 - 4) == 1 )
    {
      v9 = (float)(*(float *)(v8 - 20) - subdiv->m_edgeSeg.m_v1.m_y);
      v10 = (float)(*(float *)(v8 - 16) - subdiv->m_edgeSeg.m_v1.m_z);
      v11 = (float)(*(float *)(v8 - 24) - subdiv->m_edgeSeg.m_v1.m_x);
      if ( (float)((float)((float)v11 * (float)v11)
                 + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))) < (double)(float)(*(float *)(v8 - 8) * (float)v4) )
        --p_m_subdivElems->m_size;
    }
  }
}


// ========================================================================
// ?ConnectPortalEdgesToAdjNavGraphs@NavLayer@bfx@@QAAXPAVNavGraph@2@ABV?$Array@VEdgeCursor@bfx@@@2@1M@Z
// EA  : 0x83278858
// RVA : 0x01278858
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::NavLayer::ConnectPortalEdgesToAdjNavGraphs(
        bfx::NavLayer *this,
        bfx::NavGraph *pNewNavGraph,
        bfx::Array<bfx::EdgeCursor> *myPortalEdges,
        const bfx::Array<bfx::EdgeCursor> *theirPortalEdges,
        double maxPortalCreationDist)
{
  bfx::Array<bfx::ReplayPlayer::Registration> v7[3]; // [sp+50h] [-30h] BYREF

  memset(v7, 0, 12);
  v7[0].m_tag = bfx::MEM_BFXPLANNER;
  bfx::GenerateOverlapData(
    myPortalEdges,
    theirPortalEdges,
    maxPortalCreationDist,
    overlapDataOut: (bfx::Array<bfx::OverlapData> *)myPortalEdges,
    a5: v7);
  if ( v7[0].m_size != 0 )
    qsort(
      base: v7[0].m_data,
      num: v7[0].m_size,
      width: 0x14u,
      comp: (int (__fastcall *)(const void *, const void *))bfx::CompareOverlaps);
  bfx::NavLayer::ConnectOverlappingPortalEdges(this, pNewNavGraph, overlapData: (bfx::Array<bfx::OverlapData> *)v7);
  if ( v7[0].m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v7[0].m_data);
}


// ========================================================================
// __unwind$45551
// EA  : 0x832788F0
// RVA : 0x012788F0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_45551()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 128 + 80));
}


// ========================================================================
// ?SubtractFirstArrayFromSecondArray@bfx@@YAXABV?$Array@PAVObstacleImpl@bfx@@@1@AAV21@@Z
// EA  : 0x83278918
// RVA : 0x01278918
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::SubtractFirstArrayFromSecondArray(
        const bfx::Array<bfx::ObstacleImpl *> *array1,
        bfx::Array<bfx::Space *> *array2)
{
  int v4; // r31
  int v5; // r30
  bfx::ObstacleImpl *v6; // [sp+50h] [-30h] BYREF

  v4 = 0;
  if ( array1->m_size > 0 )
  {
    v5 = 0;
    do
    {
      v6 = array1->m_data[v5];
      bfx::Array<bfx::Path3D *>::remove(this: array2, val: (bfx::Space *const *)&v6);
      ++v4;
      ++v5;
    }
    while ( v4 < array1->m_size );
  }
}


// ========================================================================
// ?GetLinksConnectingToNavGraph@NavGraph@bfx@@QAAXAAV?$Array@PAVLinkBase@bfx@@@2@@Z
// EA  : 0x83278978
// RVA : 0x01278978
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::NavGraph::GetLinksConnectingToNavGraph(
        bfx::NavGraph *this,
        bfx::Array<bfx::SpaceComponent *> *linksOut)
{
  bfx::NavGraphHeader *m_pHeader; // r9
  char *m_pAreaBuf; // r11
  int m_areaBytes; // r9
  bfx::Area *m_pCur; // r11
  char v7; // r10
  char *v8; // r10
  _DWORD *v9; // r10
  bfx::HalfLink *i; // r29
  int m_size; // r8
  bfx::LinkBase **m_data; // r11
  bfx::LinkBase *m_pLinkBase; // r30
  bfx::LinkBase **v14; // r7
  int m_cap; // r11
  int v16; // r4
  bfx::ActiveAreasCursor v17[2]; // [sp+50h] [-50h] BYREF

  m_pHeader = this->m_pHeader;
  m_pAreaBuf = this->m_pAreaBuf;
  v17[0].m_staticCC.m_areasAllocatedInNavGraph = &this->m_allocatedAreasOwned;
  v17[0].m_staticCC.m_cc.m_i = 0;
  v17[0].m_dynCC.m_pCurDynArea = nullptr;
  m_areaBytes = m_pHeader->m_areaBytes;
  v17[0].m_dynCC.m_numDynAreas = 0;
  v17[0].m_staticCC.m_pCur = m_pAreaBuf;
  v17[0].m_dynCC.m_i = 0;
  v17[0].m_staticCC.m_cc.m_pArray = &this->m_allocatedAreasOwned;
  v17[0].m_staticCC.m_pEnd = &m_pAreaBuf[m_areaBytes];
  bfx::ActiveAreasCursor::InitDynCC(this: v17);
  while ( 1 )
  {
    m_pCur = (bfx::Area *)v17[0].m_staticCC.m_pCur;
    if ( v17[0].m_staticCC.m_pCur < v17[0].m_staticCC.m_pEnd
      || (v7 = 1, v17[0].m_staticCC.m_cc.m_i < v17[0].m_staticCC.m_cc.m_pArray->m_size) )
    {
      v7 = 0;
    }
    if ( v7 != 0 )
      break;
    if ( v17[0].m_staticCC.m_pCur >= v17[0].m_staticCC.m_pEnd )
      v8 = (char *)v17[0].m_staticCC.m_cc.m_pArray->m_data[v17[0].m_staticCC.m_cc.m_i];
    else
      v8 = v17[0].m_staticCC.m_pCur;
    v9 = *((_DWORD **)v8 + 1);
    if ( v9 != nullptr && *v9 != 0 )
    {
      m_pCur = v17[0].m_dynCC.m_pCurDynArea;
    }
    else if ( v17[0].m_staticCC.m_pCur >= v17[0].m_staticCC.m_pEnd )
    {
      m_pCur = v17[0].m_staticCC.m_cc.m_pArray->m_data[v17[0].m_staticCC.m_cc.m_i];
    }
    for ( i = m_pCur->m_pFirstLink; i != nullptr; i = i->m_pNext )
    {
      m_size = linksOut->m_size;
      m_data = (bfx::LinkBase **)linksOut->m_data;
      m_pLinkBase = i->m_pLinkBase;
      v14 = (bfx::LinkBase **)&linksOut->m_data[m_size];
      if ( (bfx::LinkBase **)linksOut->m_data == v14 )
      {
LABEL_18:
        m_cap = linksOut->m_cap;
        if ( m_cap == m_size )
        {
          v16 = 2 * m_cap;
          if ( m_cap == 0 )
            v16 = 1;
          bfx::Array<bfx::Edge *>::expand_cap(this: linksOut, size: v16);
          if ( &linksOut->m_data[linksOut->m_size] != nullptr )
            linksOut->m_data[linksOut->m_size] = (bfx::SpaceComponent *)m_pLinkBase;
        }
        else if ( v14 != nullptr )
        {
          *v14 = m_pLinkBase;
        }
        ++linksOut->m_size;
      }
      else
      {
        while ( *m_data != m_pLinkBase )
        {
          if ( ++m_data == (bfx::LinkBase **)&linksOut->m_data[linksOut->m_size] )
            goto LABEL_18;
        }
      }
    }
    bfx::ActiveAreasCursor::operator++(this: v17);
  }
}


// ========================================================================
// ?RemoveLinks@bfx@@YAXAAV?$Array@PAVArea@bfx@@@1@PAVNavGraph@1@H@Z
// EA  : 0x83278B20
// RVA : 0x01278B20
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::RemoveLinks(
        bfx::Array<bfx::Area *> *allocatedAreasToRemove,
        bfx::NavGraph *pNavGraph,
        char layerIndex)
{
  bfx::Array<bfx::SpaceComponent *> v5[4]; // [sp+50h] [-40h] BYREF

  memset(v5, 0, 12);
  v5[0].m_tag = MEM_TEMP;
  bfx::GetLinksInPortalAreas(allocatedAreas: allocatedAreasToRemove, linksOut: v5);
  bfx::NavGraph::GetLinksConnectingToNavGraph(this: pNavGraph, linksOut: v5);
  bfx::RemoveLinksFromLayers(
    pPlanner: *((bfx::Planner **)pNavGraph->m_pNavLayer->m_pSpace->m_components.m_data + 1),
    links: (bfx::Array<bfx::LinkBase *> *)v5,
    layersToRemoveFrom: 1 << layerIndex);
  v5[0].m_size = 0;
  if ( v5[0].m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v5[0].m_data);
}


// ========================================================================
// __unwind$46259
// EA  : 0x83278BAC
// RVA : 0x01278BAC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_46259()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 144 + 80));
}


// ========================================================================
// ?RemoveAllocatedAreas@NavLayer@bfx@@AAAXAAV?$Array@PAVArea@bfx@@@2@@Z
// EA  : 0x83278BE0
// RVA : 0x01278BE0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::NavLayer::RemoveAllocatedAreas(bfx::NavLayer *this, bfx::Array<bfx::Area *> *allocatedAreas)
{
  bfx::Array<bfx::Area *> *m_pArray; // r27
  int m_i; // r28
  bfx::Area *m_pCurDynArea; // r29
  bfx::Area *v7; // r11
  char *m_data; // r10
  char *v9; // r11
  bfx::Array<bfx::Area *> *v10; // r27
  int v11; // r28
  bfx::Area *v12; // r29
  bfx::Area *v13; // r11
  char *v14; // r10
  char *v15; // r11
  bfx::Space *v16; // r9
  int v17; // r26
  char *v18; // r10
  bfx::Area *v19; // r10
  char *v20; // r11
  bfx::Area *v21; // r30
  int v22; // r28
  int v23; // r29
  int v24; // r27
  bfx::Area *v25; // r11
  char *v26; // r10
  bfx::Area **v27; // r9
  char *v28; // r11
  int *v29; // r10
  bfx::Area *v30; // r10
  char *v31; // r11
  int *v32; // r10
  bfx::Area *v33; // r10
  int v34; // r30
  int v35; // r29
  bfx::Area *v36; // r27
  bfx::Area **p_m_dynAreaData; // [sp+50h] [-90h] BYREF
  bfx::Array<bfx::Space *> v38; // [sp+60h] [-80h] BYREF
  bfx::ActiveAreasInArrayCursor v39[5]; // [sp+70h] [-70h] BYREF

  memset(&v38, 0, 12);
  v38.m_tag = MEM_TEMP;
  v39[0].m_staticCC.m_pArray = allocatedAreas;
  v39[0].m_staticCC.m_i = 0;
  v39[0].m_dynCC.m_pCurDynArea = nullptr;
  v39[0].m_dynCC.m_numDynAreas = 0;
  v39[0].m_dynCC.m_i = 0;
  bfx::ActiveAreasInArrayCursor::InitDynCC(this: v39);
  m_pArray = v39[0].m_staticCC.m_pArray;
  m_i = v39[0].m_staticCC.m_i;
  if ( v39[0].m_staticCC.m_i < v39[0].m_staticCC.m_pArray->m_size )
  {
    m_pCurDynArea = v39[0].m_dynCC.m_pCurDynArea;
    do
    {
      v7 = m_pArray->m_data[m_i];
      p_m_dynAreaData = (bfx::Area **)&v7->m_dynAreaData;
      m_data = v7->m_dynAreaData.m_data;
      if ( m_data != nullptr && *(_DWORD *)m_data != 0 )
        v7 = m_pCurDynArea;
      if ( (v7->m_flags.m_flags1 & 0xFFFF80) != 0xFFFF80 )
        bfx::IslandGraph::RemoveIsland(
          this: this->m_pIslandGraph,
          pStartArea: v7,
          pAreasTouchedOut: (bfx::Array<bfx::Area *> *)&v38);
      v9 = m_pArray->m_data[m_i]->m_dynAreaData.m_data;
      if ( v9 != nullptr && *(_DWORD *)v9 != 0 )
      {
        m_pCurDynArea = (bfx::Area *)((char *)m_pCurDynArea + 24 * (m_pCurDynArea->m_flags.m_flags1 & 0x7F) + 72);
        v39[0].m_dynCC.m_pCurDynArea = m_pCurDynArea;
        if ( ++v39[0].m_dynCC.m_i != v39[0].m_dynCC.m_numDynAreas )
          continue;
      }
      v39[0].m_staticCC.m_i = m_i + 1;
      bfx::ActiveAreasInArrayCursor::InitDynCC(this: v39);
      m_pArray = v39[0].m_staticCC.m_pArray;
      m_i = v39[0].m_staticCC.m_i;
      m_pCurDynArea = v39[0].m_dynCC.m_pCurDynArea;
    }
    while ( m_i < m_pArray->m_size );
  }
  v39[0].m_staticCC.m_pArray = allocatedAreas;
  v39[0].m_staticCC.m_i = 0;
  v39[0].m_dynCC.m_pCurDynArea = nullptr;
  v39[0].m_dynCC.m_numDynAreas = 0;
  v39[0].m_dynCC.m_i = 0;
  bfx::ActiveAreasInArrayCursor::InitDynCC(this: v39);
  v10 = v39[0].m_staticCC.m_pArray;
  v11 = v39[0].m_staticCC.m_i;
  if ( v39[0].m_staticCC.m_i < v39[0].m_staticCC.m_pArray->m_size )
  {
    v12 = v39[0].m_dynCC.m_pCurDynArea;
    do
    {
      v13 = v10->m_data[v11];
      p_m_dynAreaData = (bfx::Area **)&v13->m_dynAreaData;
      v14 = v13->m_dynAreaData.m_data;
      if ( v14 != nullptr && *(_DWORD *)v14 != 0 )
        v13 = v12;
      p_m_dynAreaData = (bfx::Area **)v13;
      bfx::Array<bfx::Path3D *>::remove(this: &v38, val: (bfx::Space *const *)&p_m_dynAreaData);
      v15 = v10->m_data[v11]->m_dynAreaData.m_data;
      if ( v15 != nullptr && *(_DWORD *)v15 != 0 )
      {
        v12 = (bfx::Area *)((char *)v12 + 24 * (v12->m_flags.m_flags1 & 0x7F) + 72);
        v39[0].m_dynCC.m_pCurDynArea = v12;
        if ( ++v39[0].m_dynCC.m_i != v39[0].m_dynCC.m_numDynAreas )
          continue;
      }
      v39[0].m_staticCC.m_i = v11 + 1;
      bfx::ActiveAreasInArrayCursor::InitDynCC(this: v39);
      v10 = v39[0].m_staticCC.m_pArray;
      v11 = v39[0].m_staticCC.m_i;
      v12 = v39[0].m_dynCC.m_pCurDynArea;
    }
    while ( v11 < v10->m_size );
  }
  v17 = 0;
  p_m_dynAreaData = (bfx::Area **)allocatedAreas->m_size;
  v16 = (bfx::Space *)p_m_dynAreaData;
  if ( (int)p_m_dynAreaData > 0 && (v18 = (*allocatedAreas->m_data)->m_dynAreaData.m_data) != nullptr && *(int *)v18 > 0 )
  {
    v19 = *allocatedAreas->m_data;
    p_m_dynAreaData = allocatedAreas->m_data;
    v20 = v19->m_dynAreaData.m_data;
    v21 = (bfx::Area *)(v20 + 20);
    if ( v20 != nullptr )
    {
      v22 = *(_DWORD *)v20;
      goto LABEL_31;
    }
    v21 = nullptr;
  }
  else
  {
    v21 = nullptr;
  }
  v22 = 0;
LABEL_31:
  v23 = 0;
  p_m_dynAreaData = (bfx::Area **)v16;
  if ( (int)v16 > 0 )
  {
    v24 = 0;
    while ( 1 )
    {
      v25 = allocatedAreas->m_data[v24];
      p_m_dynAreaData = (bfx::Area **)&v25->m_dynAreaData;
      v26 = v25->m_dynAreaData.m_data;
      if ( v26 != nullptr && *(_DWORD *)v26 != 0 )
        v25 = v21;
      bfx::DisconnectArea(pArea: v25);
      v27 = allocatedAreas->m_data;
      v28 = allocatedAreas->m_data[v24]->m_dynAreaData.m_data;
      if ( v28 == nullptr || *(_DWORD *)v28 == 0 )
        break;
      ++v23;
      v21 = (bfx::Area *)((char *)v21 + 24 * (v21->m_flags.m_flags1 & 0x7F) + 72);
      if ( v23 == v22 )
      {
        ++v17;
        ++v24;
        if ( v17 < allocatedAreas->m_size )
        {
          v32 = (int *)v27[v24]->m_dynAreaData.m_data;
          if ( v32 != nullptr && *v32 > 0 )
          {
            v33 = v27[v24];
            p_m_dynAreaData = &v27[v24];
            v31 = v33->m_dynAreaData.m_data;
            v21 = (bfx::Area *)(v31 + 20);
            if ( v31 == nullptr )
            {
              v21 = nullptr;
              goto LABEL_51;
            }
LABEL_43:
            v22 = *(_DWORD *)v31;
LABEL_52:
            v23 = 0;
            goto LABEL_53;
          }
        }
LABEL_50:
        v21 = nullptr;
LABEL_51:
        v22 = 0;
        goto LABEL_52;
      }
LABEL_53:
      if ( v17 >= allocatedAreas->m_size )
        goto LABEL_54;
    }
    ++v17;
    ++v24;
    if ( v17 < allocatedAreas->m_size )
    {
      v29 = (int *)v27[v24]->m_dynAreaData.m_data;
      if ( v29 != nullptr && *v29 > 0 )
      {
        v30 = v27[v24];
        p_m_dynAreaData = &v27[v24];
        v31 = v30->m_dynAreaData.m_data;
        v21 = (bfx::Area *)(v31 + 20);
        if ( v31 == nullptr )
        {
          v21 = nullptr;
          goto LABEL_51;
        }
        goto LABEL_43;
      }
    }
    goto LABEL_50;
  }
LABEL_54:
  v34 = 0;
  if ( allocatedAreas->m_size > 0 )
  {
    v35 = 0;
    do
    {
      v36 = allocatedAreas->m_data[v35];
      bfx::Area::~Area(this: v36);
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v36);
      ++v34;
      ++v35;
    }
    while ( v34 < allocatedAreas->m_size );
  }
  bfx::IslandGraph::CreateIslandsForAreas(this: this->m_pIslandGraph, areas: (const bfx::Array<bfx::Area *> *)&v38);
  v38.m_size = 0;
  if ( v38.m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v38.m_data);
}


// ========================================================================
// __unwind$46327
// EA  : 0x83279050
// RVA : 0x01279050
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_46327()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 224 + 96));
}


// ========================================================================
// ?RemoveNavGraph@NavLayer@bfx@@QAAXPAVNavGraph@2@@Z
// EA  : 0x83279080
// RVA : 0x01279080
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::NavLayer::RemoveNavGraph(bfx::NavLayer *this, bfx::NavGraph *pNavGraph)
{
  bool *p_m_addRemoveNavGraphInProgress; // r21
  unsigned int SearchIndex; // r27
  bfx::Array<bfx::NavGraph *> *p_m_adjacentNavGraphs; // r25
  int v7; // r29
  int v8; // r28
  bfx::NavGraph *v9; // r30
  int v10; // r11
  int m_size; // r4
  char **p_m_allocatedAreasOwned; // r26
  char *v13; // r29
  int v14; // r28
  bfx::SpaceComponent *v15; // r30
  int v16; // r4
  bfx::SpaceComponent **v17; // r10
  char **p_m_allocatedAreasAdjNonOwned; // r28
  int v19; // r4
  char *v20; // r29
  int v21; // r27
  bfx::SpaceComponent *v22; // r30
  int v23; // r4
  bfx::SpaceComponent **v24; // r10
  bfx::SpaceComponent **v25; // r10
  int v26; // r30
  int v27; // r29
  int v28; // r11
  int v29; // r11
  bfx::NavGraph **v30; // r10
  bfx::DynKDNode *m_pContainingKDLeaf; // r3
  bfx::XGraph *m_pXGraph; // r3
  unsigned __int64 m_areaInvalidationTimestamp; // r11
  bfx::SearchIndexOb v34; // [sp+50h] [-80h] BYREF
  bfx::Space *v35[3]; // [sp+54h] [-7Ch] BYREF
  bfx::Array<bfx::SpaceComponent *> v36[7]; // [sp+60h] [-70h] BYREF

  if ( pNavGraph != nullptr )
  {
    p_m_addRemoveNavGraphInProgress = &this->m_addRemoveNavGraphInProgress;
    v35[1] = (bfx::Space *)&this->m_addRemoveNavGraphInProgress;
    HIBYTE(v35[2]) = 0;
    this->m_addRemoveNavGraphInProgress = true;
    bfx::SearchIndexOb::SearchIndexOb(this: &v34);
    SearchIndex = bfx::SearchIndexOb::GetSearchIndex(this: &v34);
    bfx::NavGraph::MarkAllAllocatedAreasWithSearchIndex(this: pNavGraph, searchIndex: SearchIndex);
    p_m_adjacentNavGraphs = &pNavGraph->m_adjacentNavGraphs;
    v7 = 0;
    if ( pNavGraph->m_adjacentNavGraphs.m_size > 0 )
    {
      v35[0] = (bfx::Space *)pNavGraph;
      v8 = 0;
      do
      {
        v9 = p_m_adjacentNavGraphs->m_data[v8];
        bfx::RemoveReferencesToAreasWithSpecifiedSearchIndex(
          searchIndex: SearchIndex,
          areas: &v9->m_allocatedAreasOwned);
        bfx::RemoveReferencesToAreasWithSpecifiedSearchIndex(
          searchIndex: SearchIndex,
          areas: &v9->m_allocatedAreasAdjNonOwned);
        bfx::Array<bfx::Path3D *>::remove(this: (bfx::Array<bfx::Space *> *)&v9->m_adjacentNavGraphs, val: v35);
        ++v7;
        ++v8;
      }
      while ( v7 < pNavGraph->m_adjacentNavGraphs.m_size );
    }
    bfx::SearchIndexOb::~SearchIndexOb(this: &v34);
    v10 = 0;
    memset(v36, 0, 12);
    v36[0].m_tag = bfx::MEM_BFXPLANNER;
    m_size = pNavGraph->m_allocatedAreasOwned.m_size;
    p_m_allocatedAreasOwned = (char **)&pNavGraph->m_allocatedAreasOwned;
    if ( m_size > 0 )
    {
      bfx::Array<bfx::Edge *>::expand_cap(this: v36, size: m_size);
      v10 = v36[0].m_size;
    }
    v13 = *p_m_allocatedAreasOwned;
    v14 = (int)&(*p_m_allocatedAreasOwned)[4 * pNavGraph->m_allocatedAreasOwned.m_size];
    if ( *p_m_allocatedAreasOwned != (char *)v14 )
    {
      while ( v36[0].m_cap != v10 )
      {
        v17 = &v36[0].m_data[v10];
        if ( v17 != nullptr )
        {
          *v17 = *(bfx::SpaceComponent **)v13;
LABEL_15:
          v10 = v36[0].m_size;
        }
LABEL_16:
        v13 += 4;
        v36[0].m_size = ++v10;
        if ( v13 == (char *)v14 )
          goto LABEL_17;
      }
      v15 = *(bfx::SpaceComponent **)v13;
      v16 = 2 * v36[0].m_cap;
      if ( v36[0].m_cap == 0 )
        v16 = 1;
      bfx::Array<bfx::Edge *>::expand_cap(this: v36, size: v16);
      v10 = v36[0].m_size;
      if ( &v36[0].m_data[v36[0].m_size] == nullptr )
        goto LABEL_16;
      v36[0].m_data[v36[0].m_size] = v15;
      goto LABEL_15;
    }
LABEL_17:
    p_m_allocatedAreasAdjNonOwned = (char **)&pNavGraph->m_allocatedAreasAdjNonOwned;
    v19 = v10 + pNavGraph->m_allocatedAreasAdjNonOwned.m_size;
    if ( v19 > v36[0].m_cap )
    {
      bfx::Array<bfx::Edge *>::expand_cap(this: v36, size: v19);
      v10 = v36[0].m_size;
    }
    v20 = *p_m_allocatedAreasAdjNonOwned;
    v21 = (int)&(*p_m_allocatedAreasAdjNonOwned)[4 * pNavGraph->m_allocatedAreasAdjNonOwned.m_size];
    if ( *p_m_allocatedAreasAdjNonOwned != (char *)v21 )
    {
      while ( v36[0].m_cap != v10 )
      {
        v25 = &v36[0].m_data[v10];
        if ( v25 != nullptr )
        {
          *v25 = *(bfx::SpaceComponent **)v20;
LABEL_27:
          v10 = v36[0].m_size;
        }
LABEL_28:
        v20 += 4;
        v36[0].m_size = ++v10;
        if ( v20 == (char *)v21 )
          goto LABEL_29;
      }
      v22 = *(bfx::SpaceComponent **)v20;
      v23 = 2 * v36[0].m_cap;
      if ( v36[0].m_cap == 0 )
        v23 = 1;
      bfx::Array<bfx::Edge *>::expand_cap(this: v36, size: v23);
      v10 = v36[0].m_size;
      v24 = &v36[0].m_data[v36[0].m_size];
      if ( v24 == nullptr )
        goto LABEL_28;
      *v24 = v22;
      goto LABEL_27;
    }
LABEL_29:
    pNavGraph->m_allocatedAreasOwned.m_size = 0;
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: *p_m_allocatedAreasOwned);
    *p_m_allocatedAreasOwned = nullptr;
    pNavGraph->m_allocatedAreasOwned.m_cap = 0;
    pNavGraph->m_allocatedAreasAdjNonOwned.m_size = 0;
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: *p_m_allocatedAreasAdjNonOwned);
    *p_m_allocatedAreasAdjNonOwned = nullptr;
    pNavGraph->m_allocatedAreasAdjNonOwned.m_cap = 0;
    v26 = 0;
    if ( pNavGraph->m_adjacentNavGraphs.m_size > 0 )
    {
      v27 = 0;
      do
      {
        bfx::NavGraph::RebuildBBox(this: p_m_adjacentNavGraphs->m_data[v27]);
        ++v26;
        ++v27;
      }
      while ( v26 < pNavGraph->m_adjacentNavGraphs.m_size );
    }
    bfx::RemoveLinks(allocatedAreasToRemove: (bfx::Array<bfx::Area *> *)v36, pNavGraph, layerIndex: this->m_layerIndex);
    bfx::NavLayer::RemoveAllocatedAreas(this, allocatedAreas: (bfx::Array<bfx::Area *> *)v36);
    v28 = 4 * (pNavGraph->m_graphIndex + 8);
    if ( *(bfx::Space **)((char *)&this->m_pSpace + v28) != nullptr )
    {
      *(bfx::Space **)((char *)&this->m_pSpace + v28) = nullptr;
      v29 = this->m_endGraphIndex - 1;
      --this->m_numGraphs;
      if ( v29 < 0 )
      {
LABEL_37:
        this->m_endGraphIndex = 0;
      }
      else
      {
        v30 = &this->m_graphs[v29];
        while ( *v30 == nullptr )
        {
          --v29;
          --v30;
          if ( v29 < 0 )
            goto LABEL_37;
        }
        this->m_endGraphIndex = v29 + 1;
      }
    }
    m_pContainingKDLeaf = pNavGraph->m_pContainingKDLeaf;
    v35[0] = (bfx::Space *)pNavGraph;
    if ( m_pContainingKDLeaf != nullptr )
    {
      if ( this->m_navGraphSpatialOrg.m_numNavGraphsNULLedOutInKDTree >= 25 )
      {
        this->m_navGraphSpatialOrg.m_navGraphsNotInKDTree.m_size = 0;
        this->m_navGraphSpatialOrg.m_numNavGraphsNULLedOutInKDTree = 0;
        bfx::NavGraphSpatialOrganization::RebuildNavLayerKDTree(this: &this->m_navGraphSpatialOrg);
      }
      else
      {
        _jxr_rbitstream_syncbyte(pLeafNode: m_pContainingKDLeaf);
        pNavGraph->m_pContainingKDLeaf = nullptr;
        ++this->m_navGraphSpatialOrg.m_numNavGraphsNULLedOutInKDTree;
      }
    }
    else
    {
      bfx::Array<bfx::Path3D *>::remove(
        this: (bfx::Array<bfx::Space *> *)&this->m_navGraphSpatialOrg.m_navGraphsNotInKDTree,
        val: v35);
    }
    bfx::NavGraph::~NavGraph(this: pNavGraph);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)pNavGraph);
    m_pXGraph = this->m_pXGraph;
    if ( m_pXGraph != nullptr )
      m_pXGraph->MarkDirty(this: m_pXGraph);
    m_areaInvalidationTimestamp = this->m_areaInvalidationTimestamp;
    LODWORD(m_areaInvalidationTimestamp) = m_areaInvalidationTimestamp + 1;
    this->m_areaInvalidationTimestamp = m_areaInvalidationTimestamp;
    v36[0].m_size = 0;
    if ( v36[0].m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v36[0].m_data);
    *p_m_addRemoveNavGraphInProgress = false;
  }
}


// ========================================================================
// __unwind$47559
// EA  : 0x8327946C
// RVA : 0x0127946C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_47559()
{
  int v0; // r12

  bfx::SetBooleanOnExitOb::~SetBooleanOnExitOb(this: (bfx::SetBooleanOnExitOb *)(v0 - 208 + 88));
}


// ========================================================================
// __unwind$47560
// EA  : 0x83279494
// RVA : 0x01279494
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_47560()
{
  int v0; // r12

  bfx::SearchIndexOb::~SearchIndexOb(this: (bfx::SearchIndexOb *)(v0 - 208 + 80));
}


// ========================================================================
// __unwind$47561
// EA  : 0x832794BC
// RVA : 0x012794BC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_47561()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 208 + 96));
}


// ========================================================================
// ?RemoveNavGraphsUsingImage@Planner@bfx@@QAAXPBD@Z
// EA  : 0x832794E8
// RVA : 0x012794E8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall bfx::Planner::RemoveNavGraphsUsingImage(
        bfx::Planner *this,
        const char *pInputBinaryImage,
        __int64 a3,
        __int64 a4)
{
  unsigned int v4; // r11
  bfx::Planner *v5; // r3
  bfx::Planner *v6; // r27
  int v7; // r10
  const char *v8; // r29
  bool v9; // cr57
  unsigned __int8 v10; // r11
  __int64 v11; // r10
  const char *v12; // r31
  char v13; // r28
  int v14; // r30
  const char *NavGraphUsingBinaryImage; // r3
  bfx::NavGraph *v16; // r3
  const char *v17; // r3
  int v18; // [sp+8h] [-88h]
  int v19; // [sp+Ch] [-84h]
  int v20; // [sp+10h] [-80h]
  int v21; // [sp+14h] [-7Ch]
  unsigned int v22; // [sp+50h] [-40h] BYREF

  v4 = *((_DWORD *)pInputBinaryImage + 1);
  v6 = v5;
  v7 = *(unsigned __int8 *)pInputBinaryImage;
  v8 = pInputBinaryImage;
  v22 = v4;
  if ( v7 == 0 )
  {
    bfx::EndianSwapLong(val: &v22);
    v4 = v22;
  }
  v9 = v4 > 0x25;
  if ( v4 < 0x25 || (v10 = 1, v9) )
    v10 = 0;
  LODWORD(v11) = v10 - 1;
  HIDWORD(v11) = v10 != 0;
  if ( v10 != 0 )
  {
    v12 = v8 + 12;
    v13 = 0;
    v14 = 0;
    if ( *((int *)v8 + 2) > 0 )
    {
      do
      {
        NavGraphUsingBinaryImage = (const char *)bfx::Planner::GetNavGraphUsingBinaryImage(this: v6, pBinaryImage: v12);
        pInputBinaryImage = NavGraphUsingBinaryImage;
        if ( NavGraphUsingBinaryImage != nullptr )
          bfx::NavLayer::RemoveNavGraph(this: v16->m_pNavLayer, pNavGraph: v16);
        else
          v13 = 1;
        ++v14;
        LODWORD(v11) = *((_DWORD *)v8 + 2);
        v12 += *((_DWORD *)v12 + 3);
      }
      while ( v14 < (int)v11 );
    }
    if ( v13 != 0 )
    {
      v17 = "RemoveResource() called on a resource in a different space\n";
      bfx::InternalWarning(
        fmt: *(__int64 *)&pInputBinaryImage,
        a2: a3,
        a3: a4,
        a4: v11,
        a5: v18,
        a6: v19,
        a7: v20,
        a8: v21);
    }
  }
}


// ========================================================================
// ??0ActiveAreasInSphereCursor@bfx@@QAA@ABVSphere@1@PAVNavGraph@1@@Z
// EA  : 0x832795C0
// RVA : 0x012795C0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

bfx::ActiveAreasInSphereCursor *__fastcall bfx::ActiveAreasInSphereCursor::ActiveAreasInSphereCursor(
        bfx::ActiveAreasInSphereCursor *this,
        const bfx::Sphere *sphere,
        bfx::NavGraph *pNavGraph)
{
  bfx::Array<bfx::Area *>::cursor *p_m_allocatedAreasCC; // r11
  char *v6; // r11
  bfx::Array<bfx::Area *> *m_pArray; // r9
  int m_i; // r11
  int m_size; // r8
  int v10; // r11
  bfx::Area *v11; // r3
  float m_z; // r10
  float m_y; // r9
  bfx::ActiveAreasInSphereCursor *result; // r3
  double v15; // fp9
  float m_x; // [sp+50h] [-30h]

  this->m_sphere = *sphere;
  this->m_pNavGraph = pNavGraph;
  bfx::KDTree::PrimsInSphereCursor::PrimsInSphereCursor(
    this: &this->m_staticAreaCursor,
    sphere,
    kdtree: &pNavGraph->m_kdtree);
  this->m_allocatedAreasCC.m_i = 0;
  p_m_allocatedAreasCC = &this->m_allocatedAreasCC;
  this->m_allocatedAreasCC.m_pArray = &pNavGraph->m_allocatedAreasOwned;
  this->m_dynAreaCursor.m_pCurDynArea = nullptr;
  this->m_dynAreaCursor.m_numDynAreas = 0;
  this->m_dynAreaCursor.m_i = 0;
  if ( this->m_staticAreaCursor.m_atEnd )
  {
    m_pArray = p_m_allocatedAreasCC->m_pArray;
    m_size = p_m_allocatedAreasCC->m_pArray->m_size;
    m_i = this->m_allocatedAreasCC.m_i;
    if ( m_i >= m_size )
      return this;
    v6 = (char *)m_pArray->m_data[m_i];
  }
  else
  {
    v6 = &this->m_pNavGraph->m_binaryImage[**(_DWORD **)this->m_staticAreaCursor.m_pNextNode & 0x7FFFFFFF];
  }
  if ( v6 == nullptr )
    return this;
  v10 = *((_DWORD *)v6 + 1);
  if ( v10 != 0 && *(int *)v10 > 0 )
  {
    this->m_dynAreaCursor.m_numDynAreas = *(_DWORD *)v10;
    this->m_dynAreaCursor.m_i = 0;
    this->m_dynAreaCursor.m_pCurDynArea = (bfx::Area *)(v10 + 20);
  }
  v11 = bfx::ActiveAreasInSphereCursor::operator*(this);
  m_z = v11->m_pos.m_z;
  m_y = v11->m_pos.m_y;
  m_x = v11->m_pos.m_x;
  v15 = (float)(v11->m_radius + this->m_sphere.m_radius);
  result = this;
  if ( __fsqrts((float)((float)((float)(m_x - this->m_sphere.m_pos.m_x) * (float)(m_x - this->m_sphere.m_pos.m_x))
                      + (float)((float)((float)(m_z - this->m_sphere.m_pos.m_z) * (float)(m_z - this->m_sphere.m_pos.m_z))
                              + (float)((float)(m_y - this->m_sphere.m_pos.m_y) * (float)(m_y - this->m_sphere.m_pos.m_y))))) > v15 )
  {
    bfx::ActiveAreasInSphereCursor::operator++(this);
    return this;
  }
  return result;
}


// ========================================================================
// ?ModifiyEdgesForHighQualityPathing@NavGraph@bfx@@QAAX_N@Z
// EA  : 0x83279738
// RVA : 0x01279738
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::NavGraph::ModifiyEdgesForHighQualityPathing(bfx::NavGraph *this, bool highQualityPathingEnable)
{
  bfx::NavGraphHeader *m_pHeader; // r9
  char *m_pAreaBuf; // r11
  int m_areaBytes; // r9
  int v6; // r4
  bfx::Area *m_pCur; // r10
  char v8; // r11
  char *v9; // r11
  _DWORD *v10; // r11
  int v11; // r11
  _DWORD *p_m_flags4; // r9
  bfx::NavGraphHeader *v13; // r9
  char *v14; // r11
  int v15; // r9
  double v16; // fp1
  double v17; // fp11
  double v18; // fp9
  double v19; // fp10
  bfx::Area *m_pCurDynArea; // r10
  char v21; // r11
  char *v22; // r11
  _DWORD *v23; // r11
  int v24; // r9
  int v25; // r7
  unsigned int *v26; // r8
  unsigned int v27; // r11
  __int64 v28; // r6
  unsigned int v29; // r11
  float m_x; // [sp+60h] [-60h]
  float m_y; // [sp+64h] [-5Ch]
  float m_z; // [sp+68h] [-58h]
  bfx::ActiveAreasCursor v33; // [sp+80h] [-40h] BYREF

  if ( highQualityPathingEnable )
  {
    m_pHeader = this->m_pHeader;
    m_pAreaBuf = this->m_pAreaBuf;
    memset(&v33.m_staticCC.m_cc.m_i, 0, 16);
    v33.m_staticCC.m_areasAllocatedInNavGraph = &this->m_allocatedAreasOwned;
    m_areaBytes = m_pHeader->m_areaBytes;
    v33.m_staticCC.m_pCur = m_pAreaBuf;
    v33.m_staticCC.m_pEnd = &m_pAreaBuf[m_areaBytes];
    v33.m_staticCC.m_cc.m_pArray = &this->m_allocatedAreasOwned;
    bfx::ActiveAreasCursor::InitDynCC(this: &v33);
    v6 = 0xFFFFFF;
    while ( 1 )
    {
      m_pCur = (bfx::Area *)v33.m_staticCC.m_pCur;
      if ( v33.m_staticCC.m_pCur < v33.m_staticCC.m_pEnd
        || (v8 = 1, v33.m_staticCC.m_cc.m_i < v33.m_staticCC.m_cc.m_pArray->m_size) )
      {
        v8 = 0;
      }
      if ( v8 != 0 )
        break;
      if ( v33.m_staticCC.m_pCur >= v33.m_staticCC.m_pEnd )
        v9 = (char *)v33.m_staticCC.m_cc.m_pArray->m_data[v33.m_staticCC.m_cc.m_i];
      else
        v9 = v33.m_staticCC.m_pCur;
      v10 = *((_DWORD **)v9 + 1);
      if ( v10 != nullptr && *v10 != 0 )
      {
        m_pCur = v33.m_dynCC.m_pCurDynArea;
      }
      else if ( v33.m_staticCC.m_pCur >= v33.m_staticCC.m_pEnd )
      {
        m_pCur = v33.m_staticCC.m_cc.m_pArray->m_data[v33.m_staticCC.m_cc.m_i];
      }
      v11 = 0;
      if ( (m_pCur->m_flags.m_flags1 & 0x7F) != 0 )
      {
        p_m_flags4 = &m_pCur->m_flags.m_flags4;
        do
        {
          p_m_flags4 += 6;
          *p_m_flags4 = v6;
          ++v11;
        }
        while ( v11 < (signed int)(m_pCur->m_flags.m_flags1 & 0x7F) );
      }
      bfx::ActiveAreasCursor::operator++(this: &v33);
    }
  }
  else
  {
    bfx::GetScale();
    v13 = this->m_pHeader;
    v14 = this->m_pAreaBuf;
    memset(&v33.m_staticCC.m_cc.m_i, 0, 16);
    v33.m_staticCC.m_areasAllocatedInNavGraph = &this->m_allocatedAreasOwned;
    v15 = v13->m_areaBytes;
    v33.m_staticCC.m_pCur = v14;
    v33.m_staticCC.m_pEnd = &v14[v15];
    v33.m_staticCC.m_cc.m_pArray = &this->m_allocatedAreasOwned;
    bfx::ActiveAreasCursor::InitDynCC(this: &v33);
    v17 = 1000.0;
    v18 = 1.0;
    v19 = 0.5;
    while ( 1 )
    {
      m_pCurDynArea = (bfx::Area *)v33.m_staticCC.m_pCur;
      if ( v33.m_staticCC.m_pCur < v33.m_staticCC.m_pEnd
        || (v21 = 1, v33.m_staticCC.m_cc.m_i < v33.m_staticCC.m_cc.m_pArray->m_size) )
      {
        v21 = 0;
      }
      if ( v21 != 0 )
        break;
      if ( v33.m_staticCC.m_pCur >= v33.m_staticCC.m_pEnd )
        v22 = (char *)v33.m_staticCC.m_cc.m_pArray->m_data[v33.m_staticCC.m_cc.m_i];
      else
        v22 = v33.m_staticCC.m_pCur;
      v23 = *((_DWORD **)v22 + 1);
      if ( v23 != nullptr && *v23 != 0 )
      {
        m_pCurDynArea = v33.m_dynCC.m_pCurDynArea;
      }
      else if ( v33.m_staticCC.m_pCur >= v33.m_staticCC.m_pEnd )
      {
        m_pCurDynArea = v33.m_staticCC.m_cc.m_pArray->m_data[v33.m_staticCC.m_cc.m_i];
      }
      v24 = 0;
      m_x = m_pCurDynArea->m_pos.m_x;
      v25 = (m_pCurDynArea->m_flags.m_flags2 >> 20) & 0xF;
      m_y = m_pCurDynArea->m_pos.m_y;
      m_z = m_pCurDynArea->m_pos.m_z;
      if ( (m_pCurDynArea->m_flags.m_flags1 & 0x7F) != 0 )
      {
        v26 = &m_pCurDynArea->m_flags.m_flags4;
        do
        {
          v27 = v26[1];
          if ( v27 != 0 )
          {
            HIDWORD(v28) = *(_DWORD *)(v27 + 16);
            LODWORD(v28) = ((*(_DWORD *)(v27 + 44) >> 20) & 0xF) + v25;
            v29 = (__int64)(float)((float)((float)((float)((float)__fsqrts((float)((float)((float)(m_x - *(float *)&v28)
                                                                                         * (float)(m_x - *(float *)&v28))
                                                                                 + (float)((float)((float)(m_z - *(float *)(v27 + 24))
                                                                                                 * (float)(m_z - *(float *)(v27 + 24)))
                                                                                         + (float)((float)(m_y - *(float *)(v27 + 20))
                                                                                                 * (float)(m_y - *(float *)(v27 + 20))))))
                                                         * (float)v28)
                                                 * (float)((float)v17 / (float)v16))
                                         * (float)v19)
                                 + (float)v18);
          }
          else
          {
            v29 = 0;
          }
          v26 += 6;
          *v26 = v29;
          ++v24;
        }
        while ( v24 < (signed int)(m_pCurDynArea->m_flags.m_flags1 & 0x7F) );
      }
      bfx::ActiveAreasCursor::operator++(this: &v33);
    }
  }
}


// ========================================================================
// ?EnableHighQualityPathing@NavLayer@bfx@@QAAX_N@Z
// EA  : 0x83279A60
// RVA : 0x01279A60
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::NavLayer::EnableHighQualityPathing(bfx::NavLayer *this, bool enable)
{
  bfx::NavLayer *m_layer; // r30
  int m_i; // r31
  int m_endGraphIndex; // r10
  bfx::NavGraph **v7; // r11
  bfx::NavLayerCC v8; // [sp+50h] [-30h] BYREF

  v8.m_layer = this;
  v8.m_i = -1;
  bfx::NavLayerCC::IncToNextValid(this: &v8);
  m_layer = v8.m_layer;
  m_i = v8.m_i;
  if ( v8.m_i < v8.m_layer->m_endGraphIndex )
  {
    do
    {
      bfx::NavGraph::ModifiyEdgesForHighQualityPathing(this: m_layer->m_graphs[m_i], highQualityPathingEnable: enable);
      m_endGraphIndex = m_layer->m_endGraphIndex;
      if ( ++m_i >= m_endGraphIndex )
        break;
      v7 = &m_layer->m_graphs[m_i];
      do
      {
        if ( *v7 != nullptr )
          break;
        ++m_i;
        ++v7;
      }
      while ( m_i < m_endGraphIndex );
    }
    while ( m_i < m_endGraphIndex );
  }
  if ( enable )
    this->m_pXGraph->MarkDirty(this: this->m_pXGraph);
}


// ========================================================================
// ??0NavGraph@bfx@@QAA@PAVSpace@1@PAVNavLayer@1@PADHABVVec3@1@ABVQuat@1@HPBVShapeDat@1@@Z
// EA  : 0x83279B20
// RVA : 0x01279B20
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
bfx::NavGraph *__fastcall bfx::NavGraph::NavGraph(
        bfx::NavGraph *this,
        bfx::Space *pSpace,
        bfx::NavLayer *pNavLayer,
        char *pBinaryImage,
        int graphIndex,
        const bfx::Vec3 *posOffset,
        const bfx::Quat *rotOffset,
        int layerOffset,
        const bfx::ShapeDat *pShapeDatOverride,
        int a10,
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
        const bfx::ShapeDat *a28)
{
  char v29; // r27
  bfx::KDTree *p_m_kdtree; // r21
  bfx::Array<bfx::Area *> *p_m_allocatedAreasOwned; // r22
  bfx::bfxMemTag v37; // r11
  bfx::bfxMemTag v38; // r11
  bfx::bfxMemTag v39; // r11
  bfx::bfxMemTag v40; // r11
  bfx::Array<bfx::Area *> *p_m_staticPortalAreas; // r23
  char v42; // r11
  char v43; // r11
  bfx::NavGraphHeader *m_pHeader; // r29
  char v45; // r11
  char *m_pAreaBuf; // r29
  int v47; // r26
  char *v48; // r28
  char v49; // r11
  bfx::Area *v50; // r3
  char v51; // r11
  bfx::Area *v52; // r3
  int v53; // r26
  bfx::Box *p_m_bbox; // r11
  char *v55; // r28
  char *v56; // r25
  char v57; // r11
  int *v58; // r29
  int m_cap; // r10
  int m_size; // r11
  int v61; // r4
  bfx::Area **v62; // r11
  bool v63; // cr34
  bfx::NavGraphHeader *v64; // r29
  __int64 v65; // r8
  __int64 v66; // r6
  double m_buildScale; // fp31
  __int128 v68; // r5 OVERLAPPED
  __int64 v69; // r10
  __int64 v70; // r8
  __int64 v71; // r10
  bfx::NavGraphHeader *v72; // r11
  int v74; // [sp+8h] [-138h]
  int v75; // [sp+Ch] [-134h]
  int v76; // [sp+10h] [-130h]
  int v77; // [sp+14h] [-12Ch]
  bfx::Box v78; // [sp+60h] [-E0h] BYREF
  bfx::Matrix v79; // [sp+80h] [-C0h] BYREF

  this->m_pSpace = pSpace;
  v29 = 0;
  this->m_pNavLayer = pNavLayer;
  p_m_kdtree = &this->m_kdtree;
  this->m_kdtree.m_pKDTreeData = nullptr;
  this->m_kdtree.m_pRoot = nullptr;
  this->m_kdtree.m_freeDataInDtor = false;
  p_m_allocatedAreasOwned = &this->m_allocatedAreasOwned;
  memcpy(Dst: &this->m_kdtree.m_worldToLocal, Src: &bfx::IDENTITY, Size: sizeof(this->m_kdtree.m_worldToLocal));
  v37 = bfx::MEM_BFXPLANNER;
  this->m_allocatedAreasOwned.m_data = nullptr;
  this->m_allocatedAreasOwned.m_size = 0;
  this->m_allocatedAreasOwned.m_cap = 0;
  this->m_allocatedAreasOwned.m_tag = v37;
  v38 = bfx::MEM_BFXPLANNER;
  this->m_allocatedAreasAdjNonOwned.m_data = nullptr;
  this->m_allocatedAreasAdjNonOwned.m_size = 0;
  this->m_allocatedAreasAdjNonOwned.m_cap = 0;
  this->m_allocatedAreasAdjNonOwned.m_tag = v38;
  v39 = bfx::MEM_BFXPLANNER;
  this->m_adjacentNavGraphs.m_data = nullptr;
  this->m_adjacentNavGraphs.m_size = 0;
  this->m_adjacentNavGraphs.m_cap = 0;
  this->m_adjacentNavGraphs.m_tag = v39;
  v40 = bfx::MEM_BFXPLANNER;
  p_m_staticPortalAreas = &this->m_staticPortalAreas;
  this->m_staticPortalAreas.m_data = nullptr;
  this->m_staticPortalAreas.m_size = 0;
  this->m_staticPortalAreas.m_cap = 0;
  this->m_staticPortalAreas.m_tag = v40;
  this->m_binaryImage = pBinaryImage;
  this->m_graphIndex = graphIndex;
  this->m_pHeader = (bfx::NavGraphHeader *)pBinaryImage;
  this->m_pContainingKDLeaf = nullptr;
  this->m_initStatus = NAVGRAPH_FAILED;
  this->m_pAreaBuf = pBinaryImage + 316;
  bfx::NavGraph::RelocPtrs(this, __formal: RELOC_FORWARD);
  bfx::Matrix::Build(this: &v79, q: rotOffset, pos: posOffset);
  if ( posOffset->m_x != bfx::ZERO_VEC.m_x
    || posOffset->m_y != bfx::ZERO_VEC.m_y
    || (v42 = 1, posOffset->m_z != bfx::ZERO_VEC.m_z) )
  {
    v42 = 0;
  }
  if ( v42 == 0 )
    goto LABEL_12;
  if ( rotOffset->m_w != bfx::IDENTITY_QUAT.m_w
    || rotOffset->m_x != bfx::IDENTITY_QUAT.m_x
    || rotOffset->m_y != bfx::IDENTITY_QUAT.m_y
    || (v43 = 1, rotOffset->m_z != bfx::IDENTITY_QUAT.m_z) )
  {
    v43 = 0;
  }
  if ( v43 == 0 )
  {
LABEL_12:
    m_pHeader = this->m_pHeader;
    m_pHeader->m_bbox = *bfx::CalcRotTransBBox(result: &v78, boxIn: &m_pHeader->m_bbox, mat: &v79);
    if ( rotOffset->m_w != bfx::IDENTITY_QUAT.m_w
      || rotOffset->m_x != bfx::IDENTITY_QUAT.m_x
      || rotOffset->m_y != bfx::IDENTITY_QUAT.m_y
      || (v45 = 1, rotOffset->m_z != bfx::IDENTITY_QUAT.m_z) )
    {
      v45 = 0;
    }
    m_pAreaBuf = this->m_pAreaBuf;
    v47 = 0;
    v48 = &m_pAreaBuf[this->m_pHeader->m_areaBytes];
    if ( v45 != 0 )
    {
      while ( 1 )
      {
        if ( m_pAreaBuf < v48 || (v51 = 1, v47 < this->m_allocatedAreasOwned.m_size) )
          v51 = 0;
        if ( v51 != 0 )
          break;
        if ( m_pAreaBuf >= v48 )
          v52 = p_m_allocatedAreasOwned->m_data[v47];
        else
          v52 = (bfx::Area *)m_pAreaBuf;
        bfx::Area::Translate(this: v52, offset: posOffset);
        if ( m_pAreaBuf >= v48 )
          ++v47;
        else
          m_pAreaBuf += 24 * (*((_DWORD *)m_pAreaBuf + 10) & 0x7F) + 56;
      }
    }
    else
    {
      while ( 1 )
      {
        if ( m_pAreaBuf < v48 || (v49 = 1, v47 < this->m_allocatedAreasOwned.m_size) )
          v49 = 0;
        if ( v49 != 0 )
          break;
        if ( m_pAreaBuf >= v48 )
          v50 = p_m_allocatedAreasOwned->m_data[v47];
        else
          v50 = (bfx::Area *)m_pAreaBuf;
        bfx::Area::Translate(this: v50, mat: (bfx::Vec3 *)&v79);
        if ( m_pAreaBuf >= v48 )
          ++v47;
        else
          m_pAreaBuf += 24 * (*((_DWORD *)m_pAreaBuf + 10) & 0x7F) + 56;
      }
    }
  }
  v53 = 0;
  p_m_bbox = &this->m_pHeader->m_bbox;
  this->m_bbox.m_min.m_x = p_m_bbox->m_min.m_x;
  this->m_bbox.m_min.m_y = p_m_bbox->m_min.m_y;
  this->m_bbox.m_min.m_z = p_m_bbox->m_min.m_z;
  this->m_bbox.m_max.m_x = p_m_bbox->m_max.m_x;
  this->m_bbox.m_max.m_y = p_m_bbox->m_max.m_y;
  this->m_bbox.m_max.m_z = p_m_bbox->m_max.m_z;
  v55 = this->m_pAreaBuf;
  v56 = &v55[this->m_pHeader->m_areaBytes];
  while ( 1 )
  {
    if ( v55 < v56 || (v57 = 1, v53 < this->m_allocatedAreasOwned.m_size) )
      v57 = 0;
    if ( v57 != 0 )
      break;
    if ( v55 >= v56 )
      v58 = (int *)p_m_allocatedAreasOwned->m_data[v53];
    else
      v58 = (int *)v55;
    v58[12] = (graphIndex << 16) & 0x7FF0000 | v58[12] & 0xF800FFFF;
    if ( layerOffset != 0 )
      v58[13] = ((((unsigned int)v58[13] >> 27) + layerOffset) << 27) | v58[13] & 0x7FFFFFF;
    if ( v58[11] < 0 )
    {
      m_cap = this->m_staticPortalAreas.m_cap;
      m_size = this->m_staticPortalAreas.m_size;
      if ( m_cap == m_size )
      {
        v61 = 2 * m_cap;
        if ( m_cap == 0 )
          v61 = 1;
        bfx::Array<bfx::Edge *>::expand_cap(
          this: (bfx::Array<bfx::SpaceComponent *> *)&this->m_staticPortalAreas,
          size: v61);
        v62 = &p_m_staticPortalAreas->m_data[this->m_staticPortalAreas.m_size];
        v63 = v62 == nullptr;
      }
      else
      {
        v62 = &p_m_staticPortalAreas->m_data[m_size];
        v63 = v62 == nullptr;
      }
      if ( !v63 )
        *v62 = (bfx::Area *)v58;
      ++this->m_staticPortalAreas.m_size;
    }
    if ( v55 >= v56 )
      ++v53;
    else
      v55 += 24 * (*((_DWORD *)v55 + 10) & 0x7F) + 56;
  }
  v64 = this->m_pHeader;
  if ( v64->m_buildScale != bfx::GetScale() )
  {
    m_buildScale = this->m_pHeader->m_buildScale;
    bfx::GetScale();
    *((double *)&v68 + 1) = m_buildScale;
    LODWORD(v69) = &unk_82410000;
    DWORD1(v68) = "runtime scale of %f does not match build scale of %f.  Rebuilding selected NavGraph elements.\n";
    bfx::InternalWarning(
      fmt: *(__int64 *)((char *)&v68 + 4),
      a2: *(__int64 *)((char *)&v68 - 4),
      a3: v70,
      a4: v69,
      a5: v74,
      a6: v75,
      a7: v76,
      a8: v77);
    v29 = 1;
  }
  HIDWORD(v71) = bfx::g_pCurInstance->m_pComponentManager->m_components[1];
  if ( *(_BYTE *)(HIDWORD(v71) + 20) != 0 )
    v29 = 1;
  if ( v29 != 0 )
    bfx::NavGraph::ModifiyEdgesForHighQualityPathing(this, highQualityPathingEnable: *(_BYTE *)(HIDWORD(v71) + 20));
  v72 = this->m_pHeader;
  LODWORD(v71) = v72->m_layer + layerOffset;
  v72->m_layer = v71;
  bfx::NavGraph::ApplyShapeDatOverride(this, pShapeDatOverride: a28, a3: v66, a4: v65, a5: v71);
  bfx::KDTree::Init(
    this: p_m_kdtree,
    pKDTreeData: &this->m_pAreaBuf[this->m_pHeader->m_areaBytes],
    freeDataInDtor: false,
    localToWorld: &v79);
  this->m_initStatus = (_cntlzw(
                          bfx::IslandGraph::CreateIslandsForNavGraph(
                            this: this->m_pNavLayer->m_pIslandGraph,
                            pNavGraph: this))
                      & 0x20) != 0;
  return this;
}


// ========================================================================
// __unwind$48882
// EA  : 0x8327A0E8
// RVA : 0x0127A0E8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_48882()
{
  int v0; // r12

  bfx::KDTree::~KDTree(this: (bfx::KDTree *)(*(_DWORD *)(v0 - 320 + 340) + 24));
}


// ========================================================================
// __unwind$48883
// EA  : 0x8327A114
// RVA : 0x0127A114
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_48883()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 320 + 340)
                                                                                             + 100));
}


// ========================================================================
// __unwind$48884
// EA  : 0x8327A140
// RVA : 0x0127A140
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_48884()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 320 + 340)
                                                                                             + 116));
}


// ========================================================================
// __unwind$48885
// EA  : 0x8327A16C
// RVA : 0x0127A16C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_48885()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 320 + 340)
                                                                                             + 132));
}


// ========================================================================
// __unwind$48886
// EA  : 0x8327A198
// RVA : 0x0127A198
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_48886()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 320 + 340)
                                                                                             + 148));
}


// ========================================================================
// ?Draw@NavGraph@bfx@@QAAXABVDrawCullData@2@@Z
// EA  : 0x8327A1C8
// RVA : 0x0127A1C8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::NavGraph::Draw(bfx::NavGraph *this, const bfx::DrawCullData *drawCull)
{
  float m_x; // r11
  float m_y; // r10
  float m_z; // r9
  char v7; // r11
  bfx::Area *m_pCurDynArea; // r31
  char *m_data; // r11
  double m_radius; // fp1
  float v11; // r10
  float v12; // r9
  __int64 v13; // r6
  bfx::NavGraphHeader *m_pHeader; // r9
  char *m_pAreaBuf; // r11
  int m_areaBytes; // r9
  __int64 v17; // r6
  bfx::Vec3 *m_pCur; // r4
  char v19; // r11
  char *v20; // r11
  _DWORD *v21; // r11
  bfx::ActiveAreasCursor v22; // [sp+50h] [-4B0h] BYREF
  bfx::Vec3 v23; // [sp+70h] [-490h] BYREF
  bfx::Sphere v24; // [sp+80h] [-480h] BYREF
  bfx::ActiveAreasInSphereCursor v25; // [sp+90h] [-470h] BYREF

  if ( drawCull->m_useCulling )
  {
    m_x = drawCull->m_cameraPos.m_x;
    m_y = drawCull->m_cameraPos.m_y;
    v24.m_radius = drawCull->m_farClipDist;
    m_z = drawCull->m_cameraPos.m_z;
    v24.m_pos.m_x = m_x;
    v24.m_pos.m_y = m_y;
    v24.m_pos.m_z = m_z;
    bfx::ActiveAreasInSphereCursor::ActiveAreasInSphereCursor(this: &v25, sphere: &v24, pNavGraph: this);
    while ( 1 )
    {
      if ( !v25.m_staticAreaCursor.m_atEnd
        || (v7 = 1, v25.m_allocatedAreasCC.m_i < v25.m_allocatedAreasCC.m_pArray->m_size) )
      {
        v7 = 0;
      }
      if ( v7 != 0 )
        return;
      if ( v25.m_staticAreaCursor.m_atEnd )
      {
        if ( v25.m_allocatedAreasCC.m_i >= v25.m_allocatedAreasCC.m_pArray->m_size )
          goto LABEL_15;
        m_pCurDynArea = v25.m_allocatedAreasCC.m_pArray->m_data[v25.m_allocatedAreasCC.m_i];
      }
      else
      {
        m_pCurDynArea = (bfx::Area *)&v25.m_pNavGraph->m_binaryImage[**(_DWORD **)v25.m_staticAreaCursor.m_pNextNode
                                                                   & 0x7FFFFFFF];
      }
      if ( m_pCurDynArea == nullptr )
      {
LABEL_15:
        m_pCurDynArea = nullptr;
        goto LABEL_16;
      }
      m_data = m_pCurDynArea->m_dynAreaData.m_data;
      if ( m_data != nullptr && *(_DWORD *)m_data != 0 )
        m_pCurDynArea = v25.m_dynAreaCursor.m_pCurDynArea;
LABEL_16:
      m_radius = m_pCurDynArea->m_radius;
      v11 = m_pCurDynArea->m_pos.m_y;
      v12 = m_pCurDynArea->m_pos.m_z;
      v23.m_x = m_pCurDynArea->m_pos.m_x;
      v23.m_y = v11;
      v23.m_z = v12;
      if ( (unsigned __int8)bfx::DrawCullData::IsSphereCulled(this: drawCull, centerPos: &v23, radius: m_radius) == 0 )
        bfx::DrawAreaInGraph(pSpace: this->m_pSpace, pArea: (bfx::Vec3 *)m_pCurDynArea, a3: v13);
      bfx::ActiveAreasInSphereCursor::operator++(this: &v25);
    }
  }
  m_pHeader = this->m_pHeader;
  m_pAreaBuf = this->m_pAreaBuf;
  memset(&v22.m_staticCC.m_cc.m_i, 0, 16);
  v22.m_staticCC.m_areasAllocatedInNavGraph = &this->m_allocatedAreasOwned;
  m_areaBytes = m_pHeader->m_areaBytes;
  v22.m_staticCC.m_pCur = m_pAreaBuf;
  v22.m_staticCC.m_pEnd = &m_pAreaBuf[m_areaBytes];
  v22.m_staticCC.m_cc.m_pArray = &this->m_allocatedAreasOwned;
  bfx::ActiveAreasCursor::InitDynCC(this: &v22);
  while ( 1 )
  {
    m_pCur = (bfx::Vec3 *)v22.m_staticCC.m_pCur;
    if ( v22.m_staticCC.m_pCur < v22.m_staticCC.m_pEnd
      || (v19 = 1, v22.m_staticCC.m_cc.m_i < v22.m_staticCC.m_cc.m_pArray->m_size) )
    {
      v19 = 0;
    }
    if ( v19 != 0 )
      break;
    if ( v22.m_staticCC.m_pCur >= v22.m_staticCC.m_pEnd )
      v20 = (char *)v22.m_staticCC.m_cc.m_pArray->m_data[v22.m_staticCC.m_cc.m_i];
    else
      v20 = v22.m_staticCC.m_pCur;
    v21 = *((_DWORD **)v20 + 1);
    if ( v21 != nullptr && *v21 != 0 )
    {
      m_pCur = (bfx::Vec3 *)v22.m_dynCC.m_pCurDynArea;
LABEL_32:
      bfx::DrawAreaInGraph(pSpace: this->m_pSpace, pArea: m_pCur, a3: v17);
      bfx::ActiveAreasCursor::operator++(this: &v22);
    }
    else
    {
      if ( v22.m_staticCC.m_pCur < v22.m_staticCC.m_pEnd )
        goto LABEL_32;
      bfx::DrawAreaInGraph(
        pSpace: this->m_pSpace,
        pArea: (bfx::Vec3 *)v22.m_staticCC.m_cc.m_pArray->m_data[v22.m_staticCC.m_cc.m_i],
        a3: v17);
      bfx::ActiveAreasCursor::operator++(this: &v22);
    }
  }
}


// ========================================================================
// ??0?$ClosestAreasProcessor@VIncrementalIRT@bfx@@@bfx@@QAA@ABVIncrementalIRT@1@MH@Z
// EA  : 0x8327A400
// RVA : 0x0127A400
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

bfx::ClosestAreasProcessor<bfx::IncrementalIRT> *__fastcall bfx::ClosestAreasProcessor<bfx::IncrementalIRT>::ClosestAreasProcessor<bfx::IncrementalIRT>(
        bfx::ClosestAreasProcessor<bfx::IncrementalIRT> *this,
        const bfx::IncrementalIRT *areaChecker,
        double initialRadius,
        int N,
        int a5)
{
  this->m_areaChecker = areaChecker;
  bfx::SmallestN<bfx::Area *>::SmallestN<bfx::Area *>(
    this: (bfx::SmallestN<bfx::Volume *> *)&this->m_closestAreas,
    N: a5);
  this->m_pNavGraph = nullptr;
  _FP13 = (float)((float)initialRadius - (float)9.2233715e18);
  __asm { fsel      f12, f13, f0, f31 }
  this->m_considerationDist = _FP12;
  return this;
}


// ========================================================================
// ??0ClosestPrimsCursor@NavGraphSpatialOrganization@bfx@@QAA@ABVVec3@2@AAV12@M@Z
// EA  : 0x8327A8C0
// RVA : 0x0127A8C0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

bfx::NavGraphSpatialOrganization::ClosestPrimsCursor *__fastcall bfx::NavGraphSpatialOrganization::ClosestPrimsCursor::ClosestPrimsCursor(
        bfx::NavGraphSpatialOrganization::ClosestPrimsCursor *this,
        const bfx::Vec3 *testPos,
        bfx::NavGraphSpatialOrganization *spatialOrg,
        double considerationDist)
{
  BOOL m_atEnd; // r5
  float m_z; // r7

  if ( !spatialOrg->m_pNavLayer->m_addRemoveNavGraphInProgress
    && (spatialOrg->m_numNavGraphsNULLedOutInKDTree > 0 || spatialOrg->m_navGraphsNotInKDTree.m_size != 0) )
  {
    spatialOrg->m_navGraphsNotInKDTree.m_size = 0;
    spatialOrg->m_numNavGraphsNULLedOutInKDTree = 0;
    bfx::NavGraphSpatialOrganization::RebuildNavLayerKDTree(this: spatialOrg);
  }
  bfx::DynKDTree::ClosestPrimsCursor::ClosestPrimsCursor(
    this: &this->m_kdtreeCC,
    testPos,
    pKDTree: spatialOrg->m_pNavLayerKDTree,
    considerationDist);
  this->m_linearCC.m_i = 0;
  this->m_linearCC.m_pArray = &spatialOrg->m_navGraphsNotInKDTree;
  this->m_testPos.m_x = testPos->m_x;
  m_atEnd = this->m_kdtreeCC.m_atEnd;
  this->m_testPos.m_y = testPos->m_y;
  m_z = testPos->m_z;
  this->m_considerationDist = considerationDist;
  this->m_testPos.m_z = m_z;
  if ( m_atEnd )
    bfx::NavGraphSpatialOrganization::ClosestPrimsCursor::AdvancedLinearCCToFirstNavGraphWithinConsiderationDistance(this);
  return this;
}


// ========================================================================
// __unwind$50139
// EA  : 0x8327A990
// RVA : 0x0127A990
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_50139()
{
  int v0; // r12

  bfx::NavGraphSpatialOrganization::ClosestPrimsCursor::~ClosestPrimsCursor(this: *(bfx::NavGraphSpatialOrganization::ClosestPrimsCursor **)(v0 - 144 + 164));
}


// ========================================================================
// ?Draw@NavLayer@bfx@@QAAXABVDrawCullData@2@@Z
// EA  : 0x8327A9B8
// RVA : 0x0127A9B8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::NavLayer::Draw(bfx::NavLayer *this, const bfx::DrawCullData *drawCull)
{
  bfx::InstanceComponent_vtbl *v4; // r30
  bfx::IslandGraph *m_pIslandGraph; // r3
  bfx::IslandGraph *v6; // r3
  bfx::NavLayer *m_layer; // r11
  int i; // r10
  bfx::XGraph *m_pXGraph; // r11
  bfx::NavLayerCC v10[6]; // [sp+50h] [-30h] BYREF

  v4 = bfx::g_pCurInstance->m_pComponentManager->m_components[1][9].__vftable;
  if ( bfx::g_drawIslandGraph )
  {
    m_pIslandGraph = this->m_pIslandGraph;
    if ( m_pIslandGraph != nullptr )
      bfx::IslandGraph::Draw(this: m_pIslandGraph);
  }
  if ( bfx::g_drawIslandStats )
  {
    v6 = this->m_pIslandGraph;
    if ( v6 != nullptr )
      bfx::IslandGraph::DrawStats(this: v6);
  }
  if ( HIBYTE(v4->dtr_InstanceComponent) != 0 || BYTE1(v4->dtr_InstanceComponent) != 0 )
  {
    v10[0].m_layer = this;
    v10[0].m_i = -1;
    bfx::NavLayerCC::IncToNextValid(this: v10);
    m_layer = v10[0].m_layer;
    for ( i = v10[0].m_i; v10[0].m_i < v10[0].m_layer->m_endGraphIndex; i = v10[0].m_i )
    {
      bfx::NavGraph::Draw(this: m_layer->m_graphs[i], drawCull);
      bfx::NavLayerCC::IncToNextValid(this: v10);
      m_layer = v10[0].m_layer;
    }
  }
  if ( bfx::g_drawXGraph )
  {
    m_pXGraph = this->m_pXGraph;
    if ( m_pXGraph != nullptr )
      ((void (*)(void))m_pXGraph->Draw)();
  }
}


// ========================================================================
// ?SubdivideAllPortalEdgesInArea@bfx@@YAXPAVArea@1@PBVDynKDTree@1@MMAAV?$Array@VPortalSubdivData@bfx@@@1@@Z
// EA  : 0x8327AAD8
// RVA : 0x0127AAD8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::SubdivideAllPortalEdgesInArea(
        bfx::Area *pArea,
        const bfx::DynKDTree *pAllStaticPortalEdgesKDTree,
        double subdivThreshold,
        double maxPortalCreationDist,
        bfx::Array<bfx::PortalSubdivData> *subdivsOut,
        int a6,
        bfx::Array<bfx::PortalSubdivData> *a7)
{
  unsigned int v9; // r10
  int v13; // r30
  char *v14; // r11
  int v15; // r5
  const bfx::DynKDTree *v16; // r4
  signed int v17; // r10
  bfx::EdgeCursor v18; // [sp+50h] [-A0h] BYREF
  bfx::PortalSubdivData v19; // [sp+60h] [-90h] BYREF

  v9 = pArea->m_flags.m_flags1 & 0x7F;
  v18.m_pArea = pArea;
  v18.m_i = 0;
  v13 = 0;
  if ( v9 != 0 )
  {
    do
    {
      v14 = (char *)pArea + 24 * v13;
      if ( (*((_DWORD *)v14 + 18) & 0x6000) == 0x2000 && *((_DWORD *)v14 + 14) == 0 )
      {
        bfx::PortalSubdivData::PortalSubdivData(this: &v19, portalEdge: &v18);
        bfx::PortalSubdivData::AddSubdivElemsForNearbyEdges(
          this: &v19,
          subdivThreshold,
          maxPortalCreationDist,
          pAllStaticPortalEdgesKDTree: v16,
          a5: v15,
          a6: pAllStaticPortalEdgesKDTree);
        if ( v19.m_subdivElems.m_size != 0 )
          bfx::Array<bfx::PortalSubdivData>::push_back(this: a7, val: &v19);
        v19.m_subdivElems.m_size = 0;
        if ( v19.m_subdivElems.m_data != nullptr )
        {
          bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v19.m_subdivElems.m_data);
          v19.m_subdivElems.m_data = nullptr;
        }
        v19.m_subdivElems.m_cap = 0;
      }
      ++v13;
      v17 = pArea->m_flags.m_flags1 & 0x7F;
      v18.m_i = v13;
    }
    while ( v13 < v17 );
  }
}


// ========================================================================
// __unwind$50238
// EA  : 0x8327ABD8
// RVA : 0x0127ABD8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_50238()
{
  int v0; // r12

  bfx::PortalSubdivData::~PortalSubdivData(this: (bfx::PortalSubdivData *)(v0 - 240 + 96));
}


// ========================================================================
// ?CheckForQuadUnconnectedEdgeLoop@bfx@@YA_NABVEdgeCursor@1@AAV?$FArray@VEdgeCursor@bfx@@$03@1@@Z
// EA  : 0x8327AC00
// RVA : 0x0127AC00
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

BOOL __fastcall bfx::CheckForQuadUnconnectedEdgeLoop(
        const bfx::EdgeCursor *unconnectedAllocatedAreaEdge,
        bfx::FArray<bfx::EdgeCursor,4> *edgesTraversedOut)
{
  bfx::EdgeCursor v2; // r11
  int v4; // r28
  bfx::EdgeCursor *v5; // r11
  int v6; // r27
  bfx::EdgeCursor v7; // r26
  char **v8; // r31
  char **v9; // r11
  char *v10; // r30
  char v11; // r11
  int m_size; // r11
  bfx::EdgeCursor *v13; // r11
  char *v14; // r11
  int v16; // [sp+50h] [-90h] BYREF
  bfx::EdgeCursor v17; // [sp+58h] [-88h] BYREF
  bfx::EdgeCursor v18[2]; // [sp+60h] [-80h] BYREF
  _DWORD v19[4]; // [sp+70h] [-70h] BYREF
  int v20; // [sp+80h] [-60h]
  bfx::FArray<int,4> v21; // [sp+90h] [-50h] BYREF

  v2 = *unconnectedAllocatedAreaEdge;
  v2.m_pArea = (bfx::Area *)edgesTraversedOut->m_size;
  v21.m_size = 1;
  v4 = 1;
  v20 = 1;
  v17 = v2;
  v21.m_data[0] = HIWORD(v2.m_pArea->m_flags.m_flags3) & 0x7FF;
  v19[0] = (char *)v2.m_pArea + 24 * v2.m_i + 56;
  v5 = &edgesTraversedOut->m_data[(int)v2.m_pArea];
  if ( v5 != nullptr )
    *v5 = *unconnectedAllocatedAreaEdge;
  v6 = 0;
  ++edgesTraversedOut->m_size;
  do
  {
    v7 = *bfx::AdvanceCounterClockwiseAroundVertFanAtEdgeStart(result: v18, startEdge: &v17);
    v17 = v7;
    if ( v7.m_pArea == nullptr || (v17.m_pArea->m_flags.m_flags1 & 0x80000000) == 0 )
      return false;
    v8 = (char **)&v19[v4];
    v9 = (char **)v19;
    v10 = (char *)&v17.m_pArea[1] + 24 * v17.m_i;
    if ( v19 == v8 )
    {
LABEL_9:
      v11 = 0;
    }
    else
    {
      while ( *v9 != v10 )
      {
        if ( ++v9 == v8 )
          goto LABEL_9;
      }
      v11 = 1;
    }
    if ( v11 != 0 )
      return false;
    v16 = HIWORD(v17.m_pArea->m_flags.m_flags3) & 0x7FF;
    bfx::FArray<int,4>::add_unique(this: &v21, val: &v16);
    if ( v8 != nullptr )
    {
      *v8 = v10;
      v4 = v20;
    }
    ++v4;
    m_size = edgesTraversedOut->m_size;
    v20 = v4;
    v13 = &edgesTraversedOut->m_data[m_size];
    if ( v13 != nullptr )
      *v13 = v7;
    ++v6;
    ++edgesTraversedOut->m_size;
  }
  while ( v6 < 3 );
  v17 = *bfx::AdvanceCounterClockwiseAroundVertFanAtEdgeStart(result: v18, startEdge: &v17);
  if ( v17.m_pArea != nullptr )
    v14 = (char *)&v17.m_pArea[1] + 24 * v17.m_i;
  else
    v14 = nullptr;
  if ( v14 != (char *)v19[0] )
    return false;
  return (_cntlzw(v21.m_size - 3) & 0x20) != 0;
}


// ========================================================================
// ?CreateAllocatedAreaPairInNavGraphHole@bfx@@YAXPAVNavGraph@1@PAVEdgeCursor@1@H@Z
// EA  : 0x8327ADE8
// RVA : 0x0127ADE8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::CreateAllocatedAreaPairInNavGraphHole(
        bfx::NavGraph *pNewNavGraph,
        bfx::EdgeCursor *pEdgeCCArray,
        int numEdges)
{
  bfx::NavLayer *m_pNavLayer; // r29
  bfx::EdgeCursor *v6; // r30
  float *v7; // r31
  int i; // r28
  bfx::Area *m_pArea; // r11
  int v10; // r8
  signed int v11; // r5
  int v12; // r3
  float *v13; // r11
  bfx::NavGraph *v14; // r10
  float v15; // r4
  float v16; // r3
  float v17; // r11
  bfx::Area *v18; // r11
  unsigned int m_graphIndex; // r31
  unsigned int m_usageFlags; // r30
  unsigned int v21; // r28
  bfx::Area *v22; // r24
  bfx::Area *v23; // r23
  int v24; // r10
  int v25; // r9
  int v26; // r8
  int v27; // r7
  int v28; // r6
  int v29; // r5
  int v30; // r10
  int v31; // r9
  int v32; // r8
  int v33; // r7
  int v34; // r6
  int v35; // r5
  bfx::FArray<bfx::NavGraph *,4> *v36; // r21
  bfx::FArray<bfx::NavGraph *,4> *v37; // r30
  bfx::NavGraph *v38; // r29
  bfx::Array<bfx::SpaceComponent *> *p_m_allocatedAreasAdjNonOwned; // r31
  int m_cap; // r10
  int m_size; // r11
  int v42; // r4
  bfx::SpaceComponent **v43; // r11
  bool v44; // cr34
  int v45; // r11
  int v46; // r10
  int v47; // r4
  bfx::Area **v48; // r11
  int v49; // r11
  bfx::NavGraph **m_data; // r11
  bfx::NavGraph **v51; // r10
  bfx::NavGraph **v52; // r11
  bfx::NavGraph **v53; // r10
  bfx::FArray<bfx::NavGraph *,4> *v54; // r25
  bfx::FArray<bfx::NavGraph *,4> *v55; // r28
  bfx::NavGraph *v56; // r30
  int v57; // r8
  bfx::NavGraph **v58; // r11
  bfx::NavGraph **v59; // r7
  int v60; // r11
  int v61; // r4
  int v62; // r8
  bfx::NavGraph **v63; // r11
  bfx::NavGraph **v64; // r7
  int v65; // r11
  int v66; // r4
  int v67; // [sp+8h] [-178h]
  int v68; // [sp+8h] [-178h]
  int v69; // [sp+Ch] [-174h]
  int v70; // [sp+Ch] [-174h]
  int v71; // [sp+10h] [-170h]
  int v72; // [sp+10h] [-170h]
  int v73; // [sp+14h] [-16Ch]
  int v74; // [sp+14h] [-16Ch]
  int v75; // [sp+18h] [-168h]
  int v76; // [sp+18h] [-168h]
  bfx::Space *v77; // [sp+1Ch] [-164h]
  bfx::Space *v78; // [sp+1Ch] [-164h]
  __int64 v79; // [sp+50h] [-130h]
  __int64 j; // [sp+60h] [-120h] BYREF
  bfx::Space *v81; // [sp+68h] [-118h] BYREF
  bfx::FArray<bfx::NavGraph *,4> v82; // [sp+70h] [-110h] BYREF
  bfx::Vec3 v83; // [sp+90h] [-F0h] BYREF
  float v84; // [sp+9Ch] [-E4h]
  float v85; // [sp+A0h] [-E0h]
  float v86; // [sp+A4h] [-DCh]
  float v87; // [sp+A8h] [-D8h]
  float v88; // [sp+ACh] [-D4h]
  float v89; // [sp+B0h] [-D0h]
  bfx::Vec3 v90; // [sp+C0h] [-C0h] BYREF
  float v91; // [sp+CCh] [-B4h]
  float v92; // [sp+D0h] [-B0h]
  float v93; // [sp+D4h] [-ACh]
  float v94; // [sp+D8h] [-A8h]
  float v95; // [sp+DCh] [-A4h]
  float v96; // [sp+E0h] [-A0h]
  float v97; // [sp+F0h] [-90h]
  float v98; // [sp+F4h] [-8Ch]
  float v99[4]; // [sp+F8h] [-88h] BYREF
  float v100; // [sp+108h] [-78h]
  float v101; // [sp+10Ch] [-74h]
  float v102; // [sp+110h] [-70h]
  float v103; // [sp+114h] [-6Ch]
  float v104; // [sp+118h] [-68h]
  float v105; // [sp+11Ch] [-64h]

  if ( numEdges == 4 )
  {
    m_pNavLayer = pNewNavGraph->m_pNavLayer;
    v6 = pEdgeCCArray;
    v82.m_size = 0;
    v7 = v99;
    for ( i = 4; i != 0; --i )
    {
      m_pArea = v6->m_pArea;
      v10 = v6->m_i + 1;
      v11 = v6->m_pArea->m_flags.m_flags1 & 0x7F;
      v12 = (HIWORD(v6->m_pArea->m_flags.m_flags3) & 0x7FF) + 8;
      __twllei(v11, 0);
      v13 = (float *)((char *)m_pArea + 24 * (v10 % v11));
      __twlgei(v11 & ~(__ROL4__(v10, 1) - 1), 0xFFFFFFFF);
      v14 = *((bfx::NavGraph **)&m_pNavLayer->m_pSpace + v12);
      v15 = v13[17];
      v16 = v13[15];
      v17 = v13[16];
      HIDWORD(j) = v14;
      *v7 = v15;
      *(v7 - 2) = v16;
      *(v7 - 1) = v17;
      if ( v14 != pNewNavGraph )
        bfx::FArray<bfx::NavGraph *,4>::add_unique(this: &v82, val: (bfx::NavGraph **)&j);
      ++v6;
      v7 += 3;
    }
    v18 = pEdgeCCArray->m_pArea;
    v92 = v99[2];
    m_graphIndex = pNewNavGraph->m_graphIndex;
    v90.m_z = v99[0];
    v94 = v100;
    v90.m_x = v97;
    v90.m_y = v98;
    v91 = v99[1];
    v93 = v99[3];
    v95 = v101;
    v96 = v102;
    v83.m_x = v97;
    v83.m_y = v98;
    v83.m_z = v99[0];
    v84 = v100;
    v85 = v101;
    v86 = v102;
    v87 = v103;
    v88 = v104;
    v89 = v105;
    m_usageFlags = v18->m_usageFlags;
    v21 = (v18->m_flags.m_flags2 >> 20) & 0xF;
    v22 = bfx::CreateAllocatedArea(
            vertArray: &v90,
            numVerts: 3,
            islandNumA: 0x1FFFFu,
            planLayer: m_pNavLayer->m_layerIndex,
            graphIndex: m_graphIndex,
            userData: m_usageFlags,
            staticCostMult: v21);
    v23 = bfx::CreateAllocatedArea(
            vertArray: &v83,
            numVerts: 3,
            islandNumA: 0x1FFFFu,
            planLayer: m_pNavLayer->m_layerIndex,
            graphIndex: m_graphIndex,
            userData: m_usageFlags,
            staticCostMult: v21);
    bfx::NavGraph::AddAllocatedArea(
      this: pNewNavGraph,
      pArea: (bfx::Space *)v22,
      a3: v29,
      a4: v28,
      a5: v27,
      a6: v26,
      a7: v25,
      a8: v24,
      a9: v67,
      a10: v69,
      a11: v71,
      a12: v73,
      a13: v75,
      a14: v77);
    bfx::NavGraph::AddAllocatedArea(
      this: pNewNavGraph,
      pArea: (bfx::Space *)v23,
      a3: v35,
      a4: v34,
      a5: v33,
      a6: v32,
      a7: v31,
      a8: v30,
      a9: v68,
      a10: v70,
      a11: v72,
      a12: v74,
      a13: v76,
      a14: v78);
    v36 = (bfx::FArray<bfx::NavGraph *,4> *)((char *)&v82 + 4 * v82.m_size);
    v37 = &v82;
    LODWORD(v79) = v36;
    HIDWORD(v79) = &v82;
    if ( &v82 != v36 )
    {
      v81 = (bfx::Space *)pNewNavGraph;
      do
      {
        v38 = v37->m_data[0];
        p_m_allocatedAreasAdjNonOwned = (bfx::Array<bfx::SpaceComponent *> *)&v37->m_data[0]->m_allocatedAreasAdjNonOwned;
        m_cap = v37->m_data[0]->m_allocatedAreasAdjNonOwned.m_cap;
        m_size = v37->m_data[0]->m_allocatedAreasAdjNonOwned.m_size;
        if ( m_cap == m_size )
        {
          v42 = 2 * m_cap;
          if ( m_cap == 0 )
            v42 = 1;
          bfx::Array<bfx::Edge *>::expand_cap(
            this: (bfx::Array<bfx::SpaceComponent *> *)&v37->m_data[0]->m_allocatedAreasAdjNonOwned,
            size: v42);
          v43 = &p_m_allocatedAreasAdjNonOwned->m_data[p_m_allocatedAreasAdjNonOwned->m_size];
          v44 = v43 == nullptr;
        }
        else
        {
          v43 = &p_m_allocatedAreasAdjNonOwned->m_data[m_size];
          v44 = v43 == nullptr;
        }
        if ( !v44 )
          *v43 = (bfx::SpaceComponent *)v22;
        v45 = p_m_allocatedAreasAdjNonOwned->m_size + 1;
        p_m_allocatedAreasAdjNonOwned->m_size = v45;
        v46 = p_m_allocatedAreasAdjNonOwned->m_cap;
        if ( v46 == v45 )
        {
          v47 = 2 * v46;
          if ( v46 == 0 )
            v47 = 1;
          bfx::Array<bfx::Edge *>::expand_cap(this: p_m_allocatedAreasAdjNonOwned, size: v47);
          v45 = p_m_allocatedAreasAdjNonOwned->m_size;
        }
        v48 = (bfx::Area **)&p_m_allocatedAreasAdjNonOwned->m_data[v45];
        if ( v48 != nullptr )
          *v48 = v23;
        v49 = p_m_allocatedAreasAdjNonOwned->m_size;
        HIDWORD(j) = v38;
        p_m_allocatedAreasAdjNonOwned->m_size = v49 + 1;
        if ( v38 != pNewNavGraph )
        {
          m_data = pNewNavGraph->m_adjacentNavGraphs.m_data;
          v51 = &m_data[pNewNavGraph->m_adjacentNavGraphs.m_size];
          if ( m_data == v51 )
          {
LABEL_25:
            bfx::Array<bfx::Portal *>::push_back(
              this: (bfx::Array<bfx::Space *> *)&pNewNavGraph->m_adjacentNavGraphs,
              val: (bfx::Space *const *)&j);
          }
          else
          {
            while ( *m_data != v38 )
            {
              if ( ++m_data == v51 )
                goto LABEL_25;
            }
          }
          v52 = v38->m_adjacentNavGraphs.m_data;
          v53 = &v52[v38->m_adjacentNavGraphs.m_size];
          if ( v52 == v53 )
          {
LABEL_29:
            bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)&v38->m_adjacentNavGraphs, val: &v81);
          }
          else
          {
            while ( *v52 != pNewNavGraph )
            {
              if ( ++v52 == v53 )
                goto LABEL_29;
            }
          }
        }
        v54 = (bfx::FArray<bfx::NavGraph *,4> *)&v37->m_data[1];
        v55 = (bfx::FArray<bfx::NavGraph *,4> *)&v37->m_data[1];
        for ( j = v79; v55 != v36; v55 = (bfx::FArray<bfx::NavGraph *,4> *)((char *)v55 + 4) )
        {
          v56 = v55->m_data[0];
          if ( v55->m_data[0] != v38 )
          {
            v57 = v38->m_adjacentNavGraphs.m_size;
            v58 = v38->m_adjacentNavGraphs.m_data;
            v59 = &v58[v57];
            if ( v58 == v59 )
            {
LABEL_35:
              v60 = v38->m_adjacentNavGraphs.m_cap;
              if ( v60 == v57 )
              {
                v61 = 2 * v60;
                if ( v60 == 0 )
                  v61 = 1;
                bfx::Array<bfx::Edge *>::expand_cap(
                  this: (bfx::Array<bfx::SpaceComponent *> *)&v38->m_adjacentNavGraphs,
                  size: v61);
                if ( &v38->m_adjacentNavGraphs.m_data[v38->m_adjacentNavGraphs.m_size] != nullptr )
                  v38->m_adjacentNavGraphs.m_data[v38->m_adjacentNavGraphs.m_size] = v56;
              }
              else if ( v59 != nullptr )
              {
                *v59 = v56;
              }
              ++v38->m_adjacentNavGraphs.m_size;
            }
            else
            {
              while ( *v58 != v56 )
              {
                if ( ++v58 == &v38->m_adjacentNavGraphs.m_data[v38->m_adjacentNavGraphs.m_size] )
                  goto LABEL_35;
              }
            }
            v62 = v56->m_adjacentNavGraphs.m_size;
            v63 = v56->m_adjacentNavGraphs.m_data;
            v64 = &v63[v62];
            if ( v63 == v64 )
            {
LABEL_46:
              v65 = v56->m_adjacentNavGraphs.m_cap;
              if ( v65 == v62 )
              {
                v66 = 2 * v65;
                if ( v65 == 0 )
                  v66 = 1;
                bfx::Array<bfx::Edge *>::expand_cap(
                  this: (bfx::Array<bfx::SpaceComponent *> *)&v56->m_adjacentNavGraphs,
                  size: v66);
                if ( &v56->m_adjacentNavGraphs.m_data[v56->m_adjacentNavGraphs.m_size] != nullptr )
                  v56->m_adjacentNavGraphs.m_data[v56->m_adjacentNavGraphs.m_size] = v38;
              }
              else if ( v64 != nullptr )
              {
                *v64 = v38;
              }
              ++v56->m_adjacentNavGraphs.m_size;
            }
            else
            {
              while ( *v63 != v38 )
              {
                if ( ++v63 == &v56->m_adjacentNavGraphs.m_data[v56->m_adjacentNavGraphs.m_size] )
                  goto LABEL_46;
              }
            }
          }
        }
        v37 = v54;
        HIDWORD(v79) = v54;
      }
      while ( v54 != v36 );
    }
    (&pEdgeCCArray->m_pArea[1].m_pProxy)[6 * pEdgeCCArray->m_i] = (bfx::AreaProxy *)v22;
    (&pEdgeCCArray[1].m_pArea[1].m_pProxy)[6 * pEdgeCCArray[1].m_i] = (bfx::AreaProxy *)v22;
    (&pEdgeCCArray[2].m_pArea[1].m_pProxy)[6 * pEdgeCCArray[2].m_i] = (bfx::AreaProxy *)v23;
    (&pEdgeCCArray[3].m_pArea[1].m_pProxy)[6 * pEdgeCCArray[3].m_i] = (bfx::AreaProxy *)v23;
    v22[1].m_pProxy = (bfx::AreaProxy *)pEdgeCCArray->m_pArea;
    LODWORD(v22[1].m_pos.m_z) = pEdgeCCArray[1].m_pArea;
    LODWORD(v23[1].m_pos.m_z) = pEdgeCCArray[2].m_pArea;
    v23[1].m_flags.m_flags3 = (unsigned int)pEdgeCCArray[3].m_pArea;
    v22[1].m_flags.m_flags3 = (unsigned int)v23;
    v23[1].m_pProxy = (bfx::AreaProxy *)v22;
    if ( HIBYTE(bfx::g_pCurInstance->m_pComponentManager->m_components[1][5].__vftable) == 0 )
    {
      bfx::CalcAndSetEdgeTraversalCostsForArea(pArea: v22);
      bfx::CalcAndSetEdgeTraversalCostsForArea(pArea: v23);
    }
  }
}


// ========================================================================
// ?CreateCornerAllocatedAreas@bfx@@YAXPAVNavGraph@1@@Z
// EA  : 0x8327B370
// RVA : 0x0127B370
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::CreateCornerAllocatedAreas(bfx::NavGraph *pNewNavGraph)
{
  bfx::Array<bfx::Area *> *p_m_allocatedAreasOwned; // r26
  int v3; // r25
  int v4; // r27
  bfx::Area **m_data; // r11
  int v6; // r31
  bfx::Area *v7; // r30
  unsigned int m_flags1; // r10
  int v9; // r10
  bfx::EdgeCursor v10; // [sp+50h] [-80h] BYREF
  bfx::FArray<bfx::EdgeCursor,4> v11[3]; // [sp+60h] [-70h] BYREF

  p_m_allocatedAreasOwned = &pNewNavGraph->m_allocatedAreasOwned;
  v3 = 0;
  if ( pNewNavGraph->m_allocatedAreasOwned.m_size > 0 )
  {
    v4 = 0;
    do
    {
      m_data = p_m_allocatedAreasOwned->m_data;
      v6 = 0;
      v10.m_i = 0;
      v7 = m_data[v4];
      m_flags1 = v7->m_flags.m_flags1;
      v10.m_pArea = v7;
      if ( (m_flags1 & 0x7F) != 0 )
      {
        do
        {
          if ( (&v7[1].m_pProxy)[6 * v6] == nullptr )
          {
            v11[0].m_data[0].m_pArea = nullptr;
            v11[0].m_data[0].m_i = -1;
            v11[0].m_data[1].m_pArea = nullptr;
            v11[0].m_data[1].m_i = -1;
            v11[0].m_data[2].m_pArea = nullptr;
            v11[0].m_data[2].m_i = -1;
            v11[0].m_data[3].m_pArea = nullptr;
            v11[0].m_data[3].m_i = -1;
            v11[0].m_size = 0;
            if ( bfx::CheckForQuadUnconnectedEdgeLoop(unconnectedAllocatedAreaEdge: &v10, edgesTraversedOut: v11) )
              bfx::CreateAllocatedAreaPairInNavGraphHole(
                pNewNavGraph,
                pEdgeCCArray: v11[0].m_data,
                numEdges: v11[0].m_size);
          }
          ++v6;
          v9 = v7->m_flags.m_flags1 & 0x7F;
          v10.m_i = v6;
        }
        while ( v6 < v9 );
      }
      ++v3;
      ++v4;
    }
    while ( v3 < p_m_allocatedAreasOwned->m_size );
  }
}


// ========================================================================
// ?GetNavGraphsIntersectingBox@NavLayer@bfx@@QAAXABVBox@2@AAV?$Array@PAVNavGraph@bfx@@@2@@Z
// EA  : 0x8327B468
// RVA : 0x0127B468
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::NavLayer::GetNavGraphsIntersectingBox(
        bfx::NavLayer *this,
        const bfx::Box *box,
        bfx::Array<bfx::Space *> *navGraphsOut)
{
  bfx::NavGraphSpatialOrganization *p_m_navGraphSpatialOrg; // r29
  double m_x; // fp13
  bfx::NavLayer *m_layer; // r11
  int i; // r10
  double v10; // fp10
  double v11; // fp8
  double v12; // fp4
  double v13; // fp3
  double v14; // fp2
  char v15; // r11
  bfx::Space *v16; // r3
  double v17; // fp0
  char v18; // r11
  bfx::Space *v19[2]; // [sp+50h] [-B0h] BYREF
  bfx::NavLayerCC v20; // [sp+58h] [-A8h] BYREF
  bfx::Vec3 v21; // [sp+60h] [-A0h] BYREF
  bfx::NavGraphSpatialOrganization v22; // [sp+70h] [-90h] BYREF
  bfx::NavGraphSpatialOrganization::ClosestPrimsCursor v23; // [sp+90h] [-70h] BYREF

  if ( this->m_numGraphs != 0 )
  {
    p_m_navGraphSpatialOrg = &this->m_navGraphSpatialOrg;
    bfx::NavGraphSpatialOrganization::GetBBox(this: &v22, result: (bfx::Box *)&this->m_navGraphSpatialOrg);
    m_x = box->m_min.m_x;
    v19[0] = (bfx::Space *)LODWORD(box->m_min.m_x);
    if ( m_x >= *(float *)&v22.m_pNavLayer
      || box->m_min.m_y >= (double)*(float *)&v22.m_pNavLayerKDTree
      || box->m_min.m_z >= (double)*(float *)&v22.m_navGraphsNotInKDTree.m_data
      || box->m_max.m_x <= (double)*(float *)&v22.m_navGraphsNotInKDTree.m_size
      || box->m_max.m_y <= (double)*(float *)&v22.m_navGraphsNotInKDTree.m_cap
      || box->m_max.m_z <= (double)*(float *)&v22.m_navGraphsNotInKDTree.m_tag )
    {
      v10 = (float)(box->m_max.m_y - box->m_min.m_y);
      v11 = (float)(box->m_max.m_x - (float)m_x);
      v12 = (float)(box->m_max.m_z - box->m_min.m_z);
      v13 = (float)(box->m_max.m_y + box->m_min.m_y);
      v14 = (float)(box->m_max.m_z + box->m_min.m_z);
      v21.m_x = (float)(box->m_max.m_x + (float)m_x) * (float)0.5;
      v21.m_y = (float)v13 * (float)0.5;
      v21.m_z = (float)v14 * (float)0.5;
      bfx::NavGraphSpatialOrganization::ClosestPrimsCursor::ClosestPrimsCursor(
        this: &v23,
        testPos: &v21,
        spatialOrg: p_m_navGraphSpatialOrg,
        considerationDist: (float)((float)__fsqrts((float)((float)((float)v12 * (float)v12)
                                      + (float)((float)((float)v11 * (float)v11) + (float)((float)v10 * (float)v10))))
              * (float)0.5));
      while ( 1 )
      {
        if ( !v23.m_kdtreeCC.m_atEnd || (v15 = 1, v23.m_linearCC.m_i < v23.m_linearCC.m_pArray->m_size) )
          v15 = 0;
        if ( v15 != 0 )
          break;
        if ( v23.m_kdtreeCC.m_atEnd )
          v16 = (bfx::Space *)v23.m_linearCC.m_pArray->m_data[v23.m_linearCC.m_i];
        else
          v16 = (bfx::Space *)bfx::DynKDTree::ClosestPrimsCursor::operator*(this: &v23.m_kdtreeCC);
        v17 = box->m_max.m_x;
        v19[0] = v16;
        if ( v16->m_matWorldToSpace.m_data[10] > v17
          || v16->m_matWorldToSpace.m_data[11] > (double)box->m_max.m_y
          || v16->m_matWorldToSpace.m_data[12] > (double)box->m_max.m_z
          || v16->m_matWorldToSpace.m_data[13] < (double)box->m_min.m_x
          || v16->m_matWorldToSpace.m_data[14] < (double)box->m_min.m_y
          || (v18 = 0, v16->m_matWorldToSpace.m_data[15] < (double)box->m_min.m_z) )
        {
          v18 = 1;
        }
        if ( v18 == 0 )
          bfx::Array<bfx::Portal *>::push_back(this: navGraphsOut, val: v19);
        if ( v23.m_kdtreeCC.m_atEnd )
        {
          ++v23.m_linearCC.m_i;
          bfx::NavGraphSpatialOrganization::ClosestPrimsCursor::AdvancedLinearCCToFirstNavGraphWithinConsiderationDistance(this: &v23);
        }
        else
        {
          bfx::DynKDTree::ClosestPrimsCursor::TraverseToNextLeaf(this: &v23.m_kdtreeCC);
          if ( v23.m_kdtreeCC.m_atEnd )
            bfx::NavGraphSpatialOrganization::ClosestPrimsCursor::AdvancedLinearCCToFirstNavGraphWithinConsiderationDistance(this: &v23);
        }
      }
      v23.m_kdtreeCC.m_closestNodesList.m_data.m_size = 0;
      if ( v23.m_kdtreeCC.m_closestNodesList.m_data.m_data != nullptr )
        bfx::MemoryManager::Free(
          this: bfx::g_pCurInstance->m_pMemoryManager,
          ptr: (char *)v23.m_kdtreeCC.m_closestNodesList.m_data.m_data);
    }
    else
    {
      v20.m_layer = this;
      v20.m_i = -1;
      bfx::NavLayerCC::IncToNextValid(this: &v20);
      m_layer = v20.m_layer;
      for ( i = v20.m_i; v20.m_i < v20.m_layer->m_endGraphIndex; i = v20.m_i )
      {
        v19[0] = (bfx::Space *)m_layer->m_graphs[i];
        bfx::Array<bfx::Portal *>::push_back(this: navGraphsOut, val: v19);
        bfx::NavLayerCC::IncToNextValid(this: &v20);
        m_layer = v20.m_layer;
      }
    }
  }
}


// ========================================================================
// __unwind$51619
// EA  : 0x8327B720
// RVA : 0x0127B720
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_51619()
{
  int v0; // r12

  bfx::NavGraphSpatialOrganization::ClosestPrimsCursor::~ClosestPrimsCursor(this: (bfx::NavGraphSpatialOrganization::ClosestPrimsCursor *)(v0 - 256 + 144));
}


// ========================================================================
// ?ProcessArea@?$ClosestAreasProcessor@VPathSpec@bfx@@@bfx@@QAAXPAVArea@2@ABVVec3@2@@Z
// EA  : 0x8327B748
// RVA : 0x0127B748
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::ClosestAreasProcessor<bfx::PathSpec>::ProcessArea(
        bfx::ClosestAreasProcessor<bfx::PathSpec> *this,
        bfx::ReplayListener *pArea,
        const bfx::Vec3 *pos,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        bfx::ReplayListener *a14)
{
  float v14; // r10
  double m_y; // fp9
  float v16; // r9
  double m_z; // fp6
  double m_x; // fp3
  double v20; // fp12
  double v23; // fp1
  bfx::MetricOb<bfx::Area *> *m_pLargest; // r11
  double m_metric; // fp0
  bfx::Vec3 v28; // [sp+50h] [-30h] BYREF

  v14 = *(float *)&pArea[4].__vftable;
  m_y = pos->m_y;
  v16 = *(float *)&pArea[5].__vftable;
  m_z = pos->m_z;
  m_x = pos->m_x;
  v20 = (float)(*(float *)&pArea[7].__vftable + this->m_considerationDist);
  LODWORD(v28.m_z) = (bfx::ReplayListener)pArea[6].__vftable;
  v28.m_x = v14;
  v28.m_y = v16;
  a14 = pArea;
  if ( (float)((float)((float)((float)m_x - v14) * (float)((float)m_x - v14))
             + (float)((float)((float)((float)m_z - v28.m_z) * (float)((float)m_z - v28.m_z))
                     + (float)((float)((float)m_y - v16) * (float)((float)m_y - v16)))) <= (double)(float)((float)v20 * (float)v20)
    && (unsigned __int8)bfx::IsUsableArea((bfx::Area *)pArea, pathSpec: this->m_areaChecker) != 0 )
  {
    bfx::GetClosestPosInArea(result: &v28, (bfx::Vec3 *)pArea, pos, pEdgeIndexOut: nullptr);
    v23 = __fsqrts((float)((float)((float)(v28.m_x - pos->m_x) * (float)(v28.m_x - pos->m_x))
                         + (float)((float)((float)(v28.m_z - pos->m_z) * (float)(v28.m_z - pos->m_z))
                                 + (float)((float)(v28.m_y - pos->m_y) * (float)(v28.m_y - pos->m_y)))));
    if ( v23 <= this->m_considerationDist )
    {
      bfx::SmallestN<bfx::Area *>::Add(
        this: (bfx::SmallestN<bfx::Volume *> *)&this->m_closestAreas,
        data: &a14,
        metric: v23);
      if ( this->m_closestAreas.m_data.m_size == this->m_closestAreas.m_N )
      {
        m_pLargest = this->m_closestAreas.m_pLargest;
        if ( m_pLargest != nullptr )
          m_metric = m_pLargest->m_metric;
        else
          m_metric = bfx::SmallestN<bfx::XNode *>::GetLargest(this: (bfx::SmallestN<bfx::Volume *> *)&this->m_closestAreas)->m_metric;
        _FP12 = (float)(this->m_considerationDist - (float)m_metric);
        __asm { fsel      f11, f12, f0, f13 }
        this->m_considerationDist = _FP11;
      }
    }
  }
}


// ========================================================================
// ?ProcessArea@?$ClosestAreasProcessor@VIncrementalIRT@bfx@@@bfx@@QAAXPAVArea@2@ABVVec3@2@@Z
// EA  : 0x8327B888
// RVA : 0x0127B888
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::ClosestAreasProcessor<bfx::IncrementalIRT>::ProcessArea(
        bfx::ClosestAreasProcessor<bfx::IncrementalIRT> *this,
        bfx::ReplayListener *pArea,
        const bfx::Vec3 *pos,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        bfx::ReplayListener *a14)
{
  float v14; // r10
  double m_y; // fp9
  float v16; // r9
  double m_z; // fp6
  double m_x; // fp3
  double v20; // fp12
  double v23; // fp1
  bfx::MetricOb<bfx::Area *> *m_pLargest; // r11
  double m_metric; // fp0
  bfx::Vec3 v28; // [sp+50h] [-30h] BYREF

  v14 = *(float *)&pArea[4].__vftable;
  m_y = pos->m_y;
  v16 = *(float *)&pArea[5].__vftable;
  m_z = pos->m_z;
  m_x = pos->m_x;
  v20 = (float)(*(float *)&pArea[7].__vftable + this->m_considerationDist);
  LODWORD(v28.m_z) = (bfx::ReplayListener)pArea[6].__vftable;
  v28.m_x = v14;
  v28.m_y = v16;
  a14 = pArea;
  if ( (float)((float)((float)((float)m_x - v14) * (float)((float)m_x - v14))
             + (float)((float)((float)((float)m_z - v28.m_z) * (float)((float)m_z - v28.m_z))
                     + (float)((float)((float)m_y - v16) * (float)((float)m_y - v16)))) <= (double)(float)((float)v20 * (float)v20)
    && bfx::IncrementalIRT::IsReachable(
         this: this->m_areaChecker,
         islandNum: ((unsigned int)pArea[10].__vftable >> 7) & 0x1FFFF) )
  {
    bfx::GetClosestPosInArea(result: &v28, (bfx::Vec3 *)pArea, pos, pEdgeIndexOut: nullptr);
    v23 = __fsqrts((float)((float)((float)(v28.m_x - pos->m_x) * (float)(v28.m_x - pos->m_x))
                         + (float)((float)((float)(v28.m_z - pos->m_z) * (float)(v28.m_z - pos->m_z))
                                 + (float)((float)(v28.m_y - pos->m_y) * (float)(v28.m_y - pos->m_y)))));
    if ( v23 <= this->m_considerationDist )
    {
      bfx::SmallestN<bfx::Area *>::Add(
        this: (bfx::SmallestN<bfx::Volume *> *)&this->m_closestAreas,
        data: &a14,
        metric: v23);
      if ( this->m_closestAreas.m_data.m_size == this->m_closestAreas.m_N )
      {
        m_pLargest = this->m_closestAreas.m_pLargest;
        if ( m_pLargest != nullptr )
          m_metric = m_pLargest->m_metric;
        else
          m_metric = bfx::SmallestN<bfx::XNode *>::GetLargest(this: (bfx::SmallestN<bfx::Volume *> *)&this->m_closestAreas)->m_metric;
        _FP12 = (float)(this->m_considerationDist - (float)m_metric);
        __asm { fsel      f11, f12, f0, f13 }
        this->m_considerationDist = _FP11;
      }
    }
  }
}


// ========================================================================
// ?ProcessPrim@?$ClosestAreasProcessor@VPathSpec@bfx@@@bfx@@QAAXIABVVec3@2@@Z
// EA  : 0x8327B9D0
// RVA : 0x0127B9D0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::ClosestAreasProcessor<bfx::PathSpec>::ProcessPrim(
        bfx::ClosestAreasProcessor<bfx::PathSpec> *this,
        unsigned int primOffset,
        const bfx::Vec3 *pos,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  bfx::ReplayListener *v10; // r4
  bfx::ReplayListener_vtbl *v11; // r11
  void (__fastcall *dtr_ReplayListener)(bfx::ReplayListener *); // r28
  bfx::ReplayListener *p_WriteAttrib_3; // r31
  void (__fastcall *v14)(bfx::ReplayListener *); // r30
  int v15; // [sp+8h] [-78h]
  int v16; // [sp+Ch] [-74h]
  int v17; // [sp+10h] [-70h]
  int v18; // [sp+14h] [-6Ch]
  int v19; // [sp+18h] [-68h]
  bfx::ReplayListener *v20; // [sp+1Ch] [-64h]

  v10 = (bfx::ReplayListener *)&this->m_pNavGraph->m_binaryImage[primOffset];
  v11 = v10[1].__vftable;
  if ( v11 != nullptr && (dtr_ReplayListener = v11->dtr_ReplayListener, v11->dtr_ReplayListener != nullptr) )
  {
    p_WriteAttrib_3 = (bfx::ReplayListener *)&v11->WriteAttrib_3;
    v14 = nullptr;
    do
    {
      bfx::ClosestAreasProcessor<bfx::PathSpec>::ProcessArea(
        this,
        pArea: p_WriteAttrib_3,
        pos,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9: v15,
        a10: v16,
        a11: v17,
        a12: v18,
        a13: v19,
        a14: v20);
      v14 = (void (__fastcall *)(bfx::ReplayListener *))((char *)v14 + 1);
      a8 = 3 * (((int)p_WriteAttrib_3[10].__vftable & 0x7F) + 3);
      p_WriteAttrib_3 += 6 * ((int)p_WriteAttrib_3[10].__vftable & 0x7F) + 18;
    }
    while ( v14 != dtr_ReplayListener );
  }
  else
  {
    bfx::ClosestAreasProcessor<bfx::PathSpec>::ProcessArea(
      this,
      pArea: v10,
      pos,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9: v15,
      a10: v16,
      a11: v17,
      a12: v18,
      a13: v19,
      a14: v20);
  }
}


// ========================================================================
// ?ProcessPrim@?$ClosestAreasProcessor@VIncrementalIRT@bfx@@@bfx@@QAAXIABVVec3@2@@Z
// EA  : 0x8327BA70
// RVA : 0x0127BA70
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::ClosestAreasProcessor<bfx::IncrementalIRT>::ProcessPrim(
        bfx::ClosestAreasProcessor<bfx::IncrementalIRT> *this,
        unsigned int primOffset,
        const bfx::Vec3 *pos,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  bfx::ReplayListener *v10; // r4
  bfx::ReplayListener_vtbl *v11; // r11
  void (__fastcall *dtr_ReplayListener)(bfx::ReplayListener *); // r28
  bfx::ReplayListener *p_WriteAttrib_3; // r31
  void (__fastcall *v14)(bfx::ReplayListener *); // r30
  int v15; // [sp+8h] [-78h]
  int v16; // [sp+Ch] [-74h]
  int v17; // [sp+10h] [-70h]
  int v18; // [sp+14h] [-6Ch]
  int v19; // [sp+18h] [-68h]
  bfx::ReplayListener *v20; // [sp+1Ch] [-64h]

  v10 = (bfx::ReplayListener *)&this->m_pNavGraph->m_binaryImage[primOffset];
  v11 = v10[1].__vftable;
  if ( v11 != nullptr && (dtr_ReplayListener = v11->dtr_ReplayListener, v11->dtr_ReplayListener != nullptr) )
  {
    p_WriteAttrib_3 = (bfx::ReplayListener *)&v11->WriteAttrib_3;
    v14 = nullptr;
    do
    {
      bfx::ClosestAreasProcessor<bfx::IncrementalIRT>::ProcessArea(
        this,
        pArea: p_WriteAttrib_3,
        pos,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9: v15,
        a10: v16,
        a11: v17,
        a12: v18,
        a13: v19,
        a14: v20);
      v14 = (void (__fastcall *)(bfx::ReplayListener *))((char *)v14 + 1);
      a8 = 3 * (((int)p_WriteAttrib_3[10].__vftable & 0x7F) + 3);
      p_WriteAttrib_3 += 6 * ((int)p_WriteAttrib_3[10].__vftable & 0x7F) + 18;
    }
    while ( v14 != dtr_ReplayListener );
  }
  else
  {
    bfx::ClosestAreasProcessor<bfx::IncrementalIRT>::ProcessArea(
      this,
      pArea: v10,
      pos,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9: v15,
      a10: v16,
      a11: v17,
      a12: v18,
      a13: v19,
      a14: v20);
  }
}


// ========================================================================
// ?CheckBoxFit@NavLayer@bfx@@QAA_NABVVec3@2@ABVQuat@2@ABVBoxExtents@2@ABVPathSpec@2@@Z
// EA  : 0x8327BB18
// RVA : 0x0127BB18
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

int __fastcall bfx::NavLayer::CheckBoxFit(
        bfx::NavLayer *this,
        const bfx::Vec3 *pos,
        const bfx::Quat *rot,
        const bfx::BoxExtents *extents,
        const bfx::PathSpec *pathSpec)
{
  double m_height; // fp11
  double m_length; // fp13
  double v10; // fp30
  double v11; // fp29
  double v12; // fp31
  int v13; // r24
  float m_y; // r8
  float m_z; // r7
  __int64 v16; // r22
  bfx::Space **m_data; // r23
  char v18; // r11
  bfx::Area *m_pCurDynArea; // r27
  char *v20; // r11
  signed int v21; // r28
  signed int v22; // r29
  float *v23; // r30
  bfx::Area *v24; // r3
  float *v25; // r11
  float v26; // r10
  float v27; // r8
  float v28; // r11
  float v29; // r10
  bfx::Vec3 v31; // [sp+50h] [-5F0h] BYREF
  bfx::Array<bfx::Space *> v32; // [sp+60h] [-5E0h] BYREF
  bfx::Vec3 v33; // [sp+70h] [-5D0h] BYREF
  bfx::Box v34; // [sp+80h] [-5C0h] BYREF
  bfx::Sphere v35; // [sp+A0h] [-5A0h] BYREF
  bfx::DynAreaData *p_m_dynAreaData; // [sp+B0h] [-590h]
  bfx::Box v37; // [sp+C0h] [-580h] BYREF
  bfx::Matrix v38; // [sp+E0h] [-560h] BYREF
  bfx::Plane v39[6]; // [sp+120h] [-520h] BYREF
  bfx::ActiveAreasInSphereCursor v40; // [sp+180h] [-4C0h] BYREF

  m_height = extents->m_height;
  m_length = extents->m_length;
  v10 = (float)(extents->m_width * (float)0.5);
  v11 = (float)(extents->m_height * (float)0.5);
  v12 = (float)(extents->m_length * (float)0.5);
  v31.m_y = extents->m_width * (float)0.5;
  v34.m_max.m_z = (float)m_height * (float)0.5;
  v31.m_z = -v11;
  v31.m_x = -v12;
  v34.m_max.m_x = (float)m_length * (float)0.5;
  v34.m_max.m_y = v31.m_y;
  v31.m_y = -v10;
  v34.m_min = v31;
  bfx::Matrix::Build(this: &v38, q: rot, pos);
  bfx::CalcRotTransBBox(result: &v37, boxIn: &v34, mat: &v38);
  memset(&v32, 0, 12);
  v32.m_tag = bfx::MEM_BFXPLANNER;
  bfx::NavLayer::GetNavGraphsIntersectingBox(this, box: &v37, navGraphsOut: &v32);
  bfx::BuildClipPlanesForRotatedBox(boxLCoord: &v34, mat: (bfx::Vec3 *)&v38, pClipPlanesOut: v39);
  v13 = 0;
  m_y = pos->m_y;
  m_z = pos->m_z;
  v16 = *(_QWORD *)&v32.m_data;
  v35.m_pos.m_x = pos->m_x;
  v35.m_pos.m_y = m_y;
  v35.m_pos.m_z = m_z;
  v35.m_radius = __fsqrts((float)((float)((float)v11 * (float)v11)
                                + (float)((float)((float)v12 * (float)v12) + (float)((float)v10 * (float)v10))));
  if ( v32.m_size > 0 )
  {
    m_data = v32.m_data;
LABEL_3:
    bfx::ActiveAreasInSphereCursor::ActiveAreasInSphereCursor(
      this: &v40,
      sphere: &v35,
      pNavGraph: (bfx::NavGraph *)*m_data);
    while ( 1 )
    {
      if ( !v40.m_staticAreaCursor.m_atEnd
        || (v18 = 1, v40.m_allocatedAreasCC.m_i < v40.m_allocatedAreasCC.m_pArray->m_size) )
      {
        v18 = 0;
      }
      if ( v18 != 0 )
      {
        ++v13;
        ++m_data;
        if ( v13 < (int)v16 )
          goto LABEL_3;
        break;
      }
      if ( v40.m_staticAreaCursor.m_atEnd )
      {
        if ( v40.m_allocatedAreasCC.m_i >= v40.m_allocatedAreasCC.m_pArray->m_size )
          goto LABEL_16;
        m_pCurDynArea = v40.m_allocatedAreasCC.m_pArray->m_data[v40.m_allocatedAreasCC.m_i];
      }
      else
      {
        m_pCurDynArea = (bfx::Area *)&v40.m_pNavGraph->m_binaryImage[**(_DWORD **)v40.m_staticAreaCursor.m_pNextNode
                                                                   & 0x7FFFFFFF];
      }
      if ( m_pCurDynArea == nullptr )
      {
LABEL_16:
        m_pCurDynArea = nullptr;
        goto LABEL_17;
      }
      v20 = m_pCurDynArea->m_dynAreaData.m_data;
      p_m_dynAreaData = &m_pCurDynArea->m_dynAreaData;
      if ( v20 != nullptr && *(_DWORD *)v20 != 0 )
        m_pCurDynArea = v40.m_dynAreaCursor.m_pCurDynArea;
LABEL_17:
      v21 = 0;
      v22 = m_pCurDynArea->m_flags.m_flags1 & 0x7F;
      if ( v22 != 0 )
      {
        v23 = (float *)&m_pCurDynArea[1].m_dynAreaData;
        while ( 1 )
        {
          v24 = *((bfx::Area **)v23 - 1);
          if ( v24 == nullptr || (unsigned __int8)bfx::IsUsableArea(pArea: v24, pathSpec) == 0 )
          {
            __twlgei(v22 & ~(__ROL4__(v21 + 1, 1) - 1), 0xFFFFFFFF);
            v25 = (float *)((char *)m_pCurDynArea + 24 * ((v21 + 1) % v22));
            v26 = v25[16];
            __twllei(v22, 0);
            v27 = v25[17];
            v31.m_x = v25[15];
            v31.m_y = v26;
            v31.m_z = v27;
            v28 = v23[1];
            v29 = v23[2];
            v33.m_x = *v23;
            v33.m_y = v28;
            v33.m_z = v29;
            if ( (unsigned __int8)bfx::LineSegIntersectsClippingVolume(
                                    posA: &v33,
                                    posB: &v31,
                                    pClipPlanes: v39,
                                    numPlanes: 6,
                                    planeIndexToIgnore: -1) != 0 )
              break;
          }
          ++v21;
          v23 += 6;
          v22 = m_pCurDynArea->m_flags.m_flags1 & 0x7F;
          if ( v21 >= v22 )
            goto LABEL_23;
        }
        if ( HIDWORD(v16) != 0 )
          bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)HIDWORD(v16));
        return 0;
      }
LABEL_23:
      bfx::ActiveAreasInSphereCursor::operator++(this: &v40);
    }
  }
  if ( HIDWORD(v16) != 0 )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)HIDWORD(v16));
  return 1;
}


// ========================================================================
// __unwind$52436
// EA  : 0x8327BE5C
// RVA : 0x0127BE5C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_52436()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 1600 + 96));
}


// ========================================================================
// ?CheckTriangleFit@NavLayer@bfx@@QAA_NABVTri@2@MABVPathSpec@2@@Z
// EA  : 0x8327BE90
// RVA : 0x0127BE90
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

int __fastcall bfx::NavLayer::CheckTriangleFit(
        bfx::NavLayer *this,
        const bfx::Tri *tri,
        double height,
        const bfx::PathSpec *pathSpec,
        _DWORD *a5)
{
  double m_z; // fp11
  double m_x; // fp10
  double v7; // fp7
  double v8; // fp8
  double v9; // fp6
  double v10; // fp4
  double m_y; // fp5
  double v12; // fp2
  double v13; // fp9
  double v14; // fp29
  double v15; // fp28
  double v16; // fp27
  double v17; // fp3
  double v18; // fp26
  double v21; // fp25
  double v22; // fp24
  double v23; // fp1
  double v24; // fp2
  double v25; // fp7
  double v26; // fp6
  double v29; // fp29
  double v30; // fp28
  double v31; // fp25
  double v32; // fp7
  double v33; // fp6
  double v34; // fp3
  double v35; // fp2
  double v36; // fp1
  double v37; // fp24
  double v38; // fp23
  double v39; // fp21
  double v40; // fp20
  double v41; // fp22
  double v42; // fp4
  double v43; // fp27
  double v45; // fp6
  double v46; // fp5
  double v51; // fp30
  double v52; // fp31
  double v53; // fp8
  double v60; // fp1
  double v122; // fp8
  double v123; // fp6
  double v124; // fp7
  double v125; // fp1
  double v126; // fp2
  double v127; // fp4
  double v128; // fp5
  double v129; // fp3
  double v130; // fp13
  double v131; // fp19
  double v132; // fp29
  double v133; // fp26
  double v134; // fp6
  double v135; // fp23
  double v136; // fp24
  double v137; // fp22
  double v138; // fp21
  double v139; // fp18
  double v140; // fp5
  double v141; // fp20
  double v142; // fp2
  double v144; // fp27
  __int64 v145; // r23
  int v146; // r25
  double v152; // fp7
  double v153; // fp10
  bfx::Space **m_data; // r24
  char v155; // r11
  char *v156; // r11
  _DWORD *v157; // r10
  bfx::Area *m_pCurDynArea; // r28
  signed int v159; // r29
  signed int v160; // r9
  float *p_m_dynAreaData; // r30
  int v162; // r8
  int v163; // r10
  int v164; // r11
  bool v165; // r11
  char v166; // r11
  bool v167; // zf
  char v168; // r11
  char v169; // r11
  float *v170; // r11
  float v171; // r9
  float v172; // r8
  float v173; // r10
  float v174; // r9
  bfx::Box v176; // [sp+50h] [-620h] BYREF
  float v177; // [sp+68h] [-608h]
  float v178; // [sp+6Ch] [-604h]
  float v179; // [sp+70h] [-600h]
  double v180; // [sp+78h] [-5F8h]
  float v181; // [sp+80h] [-5F0h]
  float v182; // [sp+84h] [-5ECh]
  float v183; // [sp+88h] [-5E8h]
  float v184; // [sp+8Ch] [-5E4h]
  float v185; // [sp+90h] [-5E0h]
  float v186; // [sp+94h] [-5DCh]
  float v187; // [sp+98h] [-5D8h]
  double v188; // [sp+A0h] [-5D0h]
  float v189; // [sp+A8h] [-5C8h]
  bfx::Array<bfx::Space *> v190; // [sp+B0h] [-5C0h] BYREF
  bfx::Vec3 v191; // [sp+C0h] [-5B0h] BYREF
  bfx::Vec3 v192; // [sp+D0h] [-5A0h] BYREF
  bfx::Sphere v193; // [sp+E0h] [-590h] BYREF
  bfx::Plane v194; // [sp+F0h] [-580h] BYREF
  float v195; // [sp+100h] [-570h]
  float v196; // [sp+104h] [-56Ch]
  float v197; // [sp+108h] [-568h]
  float v198; // [sp+10Ch] [-564h]
  float v199; // [sp+110h] [-560h]
  float v200; // [sp+114h] [-55Ch]
  float v201; // [sp+118h] [-558h]
  float v202; // [sp+11Ch] [-554h]
  float v203; // [sp+120h] [-550h]
  float v204; // [sp+124h] [-54Ch]
  float v205; // [sp+128h] [-548h]
  float v206; // [sp+12Ch] [-544h]
  float v207; // [sp+130h] [-540h]
  float v208; // [sp+134h] [-53Ch]
  float v209; // [sp+138h] [-538h]
  float v210; // [sp+13Ch] [-534h]
  bfx::ActiveAreasInSphereCursor v211; // [sp+140h] [-530h] BYREF

  m_z = tri->m_v2.m_z;
  m_x = tri->m_v0.m_x;
  v7 = (float)(tri->m_v2.m_z - tri->m_v0.m_z);
  v8 = tri->m_v1.m_x;
  v9 = (float)(tri->m_v1.m_x - tri->m_v0.m_x);
  v10 = tri->m_v1.m_z;
  m_y = tri->m_v2.m_y;
  v12 = (float)(tri->m_v1.m_z - tri->m_v0.m_z);
  v13 = tri->m_v2.m_x;
  v14 = (float)(tri->m_v2.m_y - tri->m_v0.m_y);
  v15 = (float)(tri->m_v2.m_x - tri->m_v0.m_x);
  v16 = tri->m_v1.m_y;
  v17 = (float)(tri->m_v1.m_y - tri->m_v0.m_y);
  v18 = tri->m_v0.m_y;
  v21 = (float)((float)(tri->m_v1.m_x - tri->m_v0.m_x) * (float)(tri->m_v2.m_z - tri->m_v0.m_z));
  v22 = (float)((float)(tri->m_v1.m_z - tri->m_v0.m_z) * (float)(tri->m_v2.m_y - tri->m_v0.m_y));
  v177 = 0.5;
  v23 = (float)((float)height * (float)0.5);
  v176.m_min.m_y = bfx::MAX_FLOAT_VEC.m_y;
  v24 = (float)((float)((float)v12 * (float)v15) - (float)v21);
  v25 = (float)((float)((float)v17 * (float)v7) - (float)v22);
  v26 = (float)((float)((float)v9 * (float)v14) - (float)((float)v17 * (float)v15));
  _FP13 = (float)((float)__fsqrts((float)((float)((float)v26 * (float)v26)
                                        + (float)((float)((float)v25 * (float)v25) + (float)((float)v24 * (float)v24))))
                - (float)1.0842022e-19);
  __asm { fsel      f13, f13, f3, f30 }
  v29 = (float)((float)v24 * (float)_FP13);
  v30 = (float)((float)v26 * (float)_FP13);
  v31 = (float)((float)v25 * (float)_FP13);
  v33 = (float)((float)((float)v26 * (float)_FP13) * (float)v23);
  v34 = (float)((float)((float)v25 * (float)_FP13) * (float)v23);
  v32 = (float)((float)((float)v24 * (float)_FP13) * (float)v23);
  v35 = (float)((float)v18 + (float)((float)((float)v24 * (float)_FP13) * (float)v23));
  v36 = (float)(tri->m_v0.m_z + (float)v33);
  v37 = (float)((float)v10 + (float)v33);
  v38 = (float)((float)v16 + (float)v32);
  v39 = (float)((float)m_z + (float)v33);
  v40 = (float)((float)m_y + (float)v32);
  v41 = (float)(tri->m_v0.m_z - (float)v33);
  v42 = (float)((float)v10 - (float)v33);
  _FP19 = (float)(bfx::MAX_FLOAT_VEC.m_y - (float)v35);
  v46 = (float)((float)m_y - (float)v32);
  __asm { fsel      f0, f19, f2, f0 }
  _FP19 = (float)(bfx::MAX_FLOAT_VEC.m_z - (float)(tri->m_v0.m_z + (float)v33));
  v45 = (float)((float)m_z - (float)v33);
  _FP16 = (float)(bfx::MIN_FLOAT_VEC.m_y - (float)v35);
  v179 = v29;
  _FP18 = (float)(bfx::MIN_FLOAT_VEC.m_z - (float)v36);
  v189 = v35;
  v188 = 0.0;
  v51 = (float)((float)v8 + (float)v34);
  v180 = 1.0;
  v52 = (float)((float)v13 + (float)v34);
  v185 = v36;
  v53 = (float)((float)v8 - (float)v34);
  _FP29 = (float)(bfx::MAX_FLOAT_VEC.m_x - (float)((float)m_x + (float)v34));
  v183 = (float)m_x + (float)v34;
  _FP17 = (float)(bfx::MIN_FLOAT_VEC.m_x - v183);
  __asm { fsel      f12, f19, f1, f12 }
  _FP19 = (float)((float)_FP0 - (float)((float)v16 + (float)v32));
  v43 = (float)((float)v16 - (float)v32);
  v182 = (float)m_x - (float)v34;
  __asm { fsel      f11, f16, f11, f2 }
  v178 = (float)v18 - (float)v32;
  __asm { fsel      f2, f18, f15, f1 }
  v187 = v41;
  v60 = (float)((float)v13 - (float)v34);
  memset(&v190, 0, 12);
  __asm
  {
    fsel      f13, f29, f7, f13
    fsel      f9, f17, f14, f7
  }
  v190.m_tag = bfx::MEM_BFXPLANNER;
  _FP7 = (float)((float)_FP12 - (float)v37);
  __asm { fsel      f3, f19, f23, f0 }
  _FP0 = (float)((float)_FP11 - (float)v38);
  _FP29 = (float)((float)_FP2 - (float)v37);
  _FP19 = (float)((float)_FP13 - (float)v51);
  _FP18 = (float)((float)_FP9 - (float)v51);
  __asm { fsel      f12, f7, f24, f12 }
  _FP7 = (float)((float)_FP3 - (float)v40);
  __asm
  {
    fsel      f0, f0, f11, f23
    fsel      f11, f29, f2, f24
    fsel      f2, f19, f30, f13
    fsel      f13, f18, f9, f30
  }
  _FP9 = (float)((float)_FP12 - (float)v39);
  __asm { fsel      f7, f7, f20, f3 }
  _FP3 = (float)((float)_FP0 - (float)v40);
  _FP29 = (float)((float)_FP11 - (float)v39);
  _FP24 = (float)((float)_FP2 - (float)v52);
  _FP23 = (float)((float)_FP13 - (float)v52);
  __asm { fsel      f12, f9, f21, f12 }
  _FP9 = (float)((float)_FP7 - v178);
  __asm
  {
    fsel      f3, f3, f0, f20
    fsel      f0, f29, f11, f21
    fsel      f11, f24, f31, f2
    fsel      f2, f23, f13, f31
  }
  _FP13 = (float)((float)_FP12 - (float)v41);
  __asm { fsel      f9, f9, f26, f7 }
  _FP7 = (float)((float)_FP3 - v178);
  _FP29 = (float)((float)_FP0 - (float)v41);
  _FP24 = (float)((float)_FP11 - v182);
  _FP23 = (float)((float)_FP2 - v182);
  __asm { fsel      f13, f13, f22, f12 }
  _FP12 = (float)((float)_FP9 - (float)v43);
  __asm
  {
    fsel      f7, f7, f3, f26
    fsel      f3, f29, f0, f22
    fsel      f0, f24, f10, f11
    fsel      f11, f23, f2, f10
  }
  _FP10 = (float)((float)_FP13 - (float)v42);
  __asm { fsel      f9, f12, f27, f9 }
  _FP2 = (float)((float)_FP7 - (float)v43);
  _FP12 = (float)((float)_FP3 - (float)v42);
  _FP29 = (float)((float)_FP0 - (float)v53);
  _FP26 = (float)((float)_FP11 - (float)v53);
  __asm
  {
    fsel      f10, f10, f4, f13
    fsel      f7, f2, f7, f27
    fsel      f4, f12, f3, f4
  }
  _FP13 = (float)((float)_FP9 - (float)v46);
  __asm
  {
    fsel      f3, f29, f8, f0
    fsel      f2, f26, f11, f8
  }
  _FP0 = (float)((float)_FP10 - (float)v45);
  _FP12 = (float)((float)_FP7 - (float)v46);
  _FP11 = (float)((float)_FP4 - (float)v45);
  __asm { fsel      f13, f13, f5, f9 }
  v176.m_min.m_y = _FP13;
  _FP9 = (float)((float)_FP3 - (float)v60);
  _FP8 = (float)((float)_FP2 - (float)v60);
  __asm { fsel      f0, f0, f6, f10 }
  v176.m_min.m_z = _FP0;
  __asm { fsel      f13, f12, f7, f5 }
  v176.m_max.m_y = _FP13;
  __asm { fsel      f12, f11, f4, f6 }
  v176.m_max.m_z = _FP12;
  __asm { fsel      f11, f9, f1, f3 }
  v176.m_min.m_x = _FP11;
  __asm { fsel      f10, f8, f2, f1 }
  v176.m_max.m_x = _FP10;
  bfx::NavLayer::GetNavGraphsIntersectingBox(this, box: &v176, navGraphsOut: &v190);
  v122 = tri->m_v0.m_z;
  v123 = (float)(tri->m_v1.m_z - tri->m_v0.m_z);
  v124 = tri->m_v2.m_z;
  v125 = tri->m_v1.m_x;
  v126 = (float)(tri->m_v0.m_z - tri->m_v2.m_z);
  v127 = tri->m_v1.m_y;
  v128 = (float)(tri->m_v2.m_z - tri->m_v1.m_z);
  v129 = tri->m_v0.m_y;
  v130 = (float)(tri->m_v1.m_y - tri->m_v0.m_y);
  v131 = v179;
  v181 = tri->m_v1.m_z;
  v132 = tri->m_v0.m_x;
  v133 = tri->m_v2.m_x;
  v135 = (float)((float)((float)((float)v125 - tri->m_v0.m_x) * (float)v30) - (float)((float)v123 * (float)v31));
  v134 = (float)((float)((float)v123 * v179) - (float)((float)v130 * (float)v30));
  v136 = (float)((float)((float)(tri->m_v0.m_x - tri->m_v2.m_x) * (float)v30) - (float)((float)v126 * (float)v31));
  v137 = (float)((float)((float)(tri->m_v2.m_x - (float)v125) * (float)v30) - (float)((float)v128 * (float)v31));
  v138 = (float)((float)((float)v130 * (float)v31) - (float)((float)((float)v125 - tri->m_v0.m_x) * v179));
  v139 = (float)((float)((float)((float)v129 - tri->m_v2.m_y) * (float)v31)
               - (float)((float)(tri->m_v0.m_x - tri->m_v2.m_x) * v179));
  v140 = (float)((float)((float)v128 * v179) - (float)((float)(tri->m_v2.m_y - (float)v127) * (float)v30));
  v141 = (float)((float)((float)(tri->m_v2.m_y - (float)v127) * (float)v31)
               - (float)((float)(tri->m_v2.m_x - (float)v125) * v179));
  v142 = (float)((float)((float)v126 * v179) - (float)((float)((float)v129 - tri->m_v2.m_y) * (float)v30));
  _FP12 = (float)((float)__fsqrts((float)((float)((float)v138 * (float)v138)
                                        + (float)((float)((float)v134 * (float)v134) + (float)((float)v135 * (float)v135))))
                - 1.0842022e-19);
  v179 = tri->m_v2.m_y;
  v144 = v178;
  v145 = *(_QWORD *)&v190.m_data;
  v178 = v139;
  *(float *)&v180 = v124;
  v146 = 0;
  v186 = v125;
  *(float *)&v188 = v133;
  v184 = v132;
  v207 = v31;
  v208 = v131;
  v209 = v30;
  __asm { fsel      f16, f12, f11, f30 }
  _FP9 = (float)((float)__fsqrts((float)((float)((float)v141 * (float)v141)
                                       + (float)((float)((float)v140 * (float)v140) + (float)((float)v137 * (float)v137))))
               - (float)1.0842022e-19);
  _FP15 = (float)((float)__fsqrts((float)((float)((float)v139 * (float)v139)
                                        + (float)((float)((float)v142 * (float)v142) + (float)((float)v136 * (float)v136))))
                - (float)1.0842022e-19);
  v194.m_normal.m_z = (float)v138 * (float)_FP16;
  v194.m_normal.m_y = (float)v135 * (float)_FP16;
  __asm { fsel      f17, f9, f17, f30 }
  __asm { fsel      f31, f15, f31, f30 }
  v194.m_normal.m_x = (float)v134 * (float)_FP16;
  v203 = -v31;
  v196 = (float)v137 * (float)_FP17;
  v200 = (float)v136 * (float)_FP31;
  v152 = (float)(v176.m_max.m_z - v176.m_min.m_z);
  v176.m_min.m_z = (float)(v176.m_min.m_z + v176.m_max.m_z) * v177;
  v153 = (float)((float)((float)(v176.m_max.m_x - v176.m_min.m_x) * (float)(v176.m_max.m_x - v176.m_min.m_x))
               + (float)((float)(v176.m_max.m_y - v176.m_min.m_y) * (float)(v176.m_max.m_y - v176.m_min.m_y)));
  v176.m_min.m_x = (float)(v176.m_max.m_x + v176.m_min.m_x) * v177;
  v176.m_min.m_y = (float)(v176.m_min.m_y + v176.m_max.m_y) * v177;
  v199 = (float)v142 * (float)_FP31;
  v195 = (float)v140 * (float)_FP17;
  v197 = (float)v141 * (float)_FP17;
  v201 = v178 * (float)_FP31;
  v204 = -v131;
  v205 = -v30;
  v194.m_d = (float)(v184 * v194.m_normal.m_x)
           + (float)((float)((float)v129 * v194.m_normal.m_y) + (float)((float)v122 * v194.m_normal.m_z));
  v193.m_pos = v176.m_min;
  v198 = (float)(v181 * v197) + (float)((float)(v186 * v195) + (float)((float)v127 * v196));
  v210 = (float)(v187 * (float)v30) + (float)((float)(v182 * (float)v31) + (float)((float)v144 * (float)v131));
  v206 = (float)(v205 * v185) + (float)((float)(v203 * v183) + (float)(v204 * v189));
  v202 = (float)(*(float *)&v180 * v201) + (float)((float)(*(float *)&v188 * v199) + (float)(v179 * v200));
  v193.m_radius = (float)__fsqrts((float)((float)((float)v152 * (float)v152) + (float)v153)) * v177;
  if ( v190.m_size > 0 )
  {
    m_data = v190.m_data;
LABEL_3:
    bfx::ActiveAreasInSphereCursor::ActiveAreasInSphereCursor(
      this: &v211,
      sphere: &v193,
      pNavGraph: (bfx::NavGraph *)*m_data);
    while ( 1 )
    {
      if ( !v211.m_staticAreaCursor.m_atEnd
        || (v155 = 1, v211.m_allocatedAreasCC.m_i < v211.m_allocatedAreasCC.m_pArray->m_size) )
      {
        v155 = 0;
      }
      if ( v155 != 0 )
      {
        ++v146;
        ++m_data;
        if ( v146 < (int)v145 )
          goto LABEL_3;
        break;
      }
      if ( v211.m_staticAreaCursor.m_atEnd )
      {
        if ( v211.m_allocatedAreasCC.m_i >= v211.m_allocatedAreasCC.m_pArray->m_size )
          goto LABEL_17;
        v156 = (char *)v211.m_allocatedAreasCC.m_pArray->m_data[v211.m_allocatedAreasCC.m_i];
      }
      else
      {
        v156 = &v211.m_pNavGraph->m_binaryImage[**(_DWORD **)v211.m_staticAreaCursor.m_pNextNode & 0x7FFFFFFF];
      }
      if ( v156 == nullptr )
      {
LABEL_17:
        m_pCurDynArea = nullptr;
        goto LABEL_18;
      }
      v157 = *((_DWORD **)v156 + 1);
      HIDWORD(v180) = v156 + 4;
      if ( v157 != nullptr && *v157 != 0 )
        m_pCurDynArea = v211.m_dynAreaCursor.m_pCurDynArea;
      else
        m_pCurDynArea = (bfx::Area *)v156;
LABEL_18:
      v159 = 0;
      v160 = m_pCurDynArea->m_flags.m_flags1 & 0x7F;
      if ( v160 != 0 )
      {
        p_m_dynAreaData = (float *)&m_pCurDynArea[1].m_dynAreaData;
        while ( 1 )
        {
          v162 = *((_DWORD *)p_m_dynAreaData - 1);
          if ( v162 == 0 )
            goto LABEL_47;
          v163 = a5[1];
          if ( (*(_DWORD *)(v162 + 40) & 0x20000000) == 0
            || ((v164 = (unsigned __int16)(*(_WORD *)(v162 + 46) & v163), *a5 != 0)
              ? (v165 = (_cntlzw(v163 - v164) & 0x20) != 0)
              : (v165 = v164 != 0),
                v167 = v165,
                v166 = 1,
                !v167) )
          {
            v166 = 0;
          }
          if ( v166 != 0 )
            goto LABEL_32;
          HIDWORD(v180) = *(_DWORD *)(v162 + 36);
          if ( HIDWORD(v180) == 0 || (v168 = 1, (a5[2] & HIDWORD(v180)) != 0) )
            v168 = 0;
          v167 = v168 == 0;
          v169 = 1;
          if ( !v167 )
LABEL_32:
            v169 = 0;
          if ( v169 == 0 )
          {
LABEL_47:
            __twllei(v160, 0);
            __twlgei(v160 & ~(__ROL4__(v159 + 1, 1) - 1), 0xFFFFFFFF);
            v170 = (float *)((char *)m_pCurDynArea + 24 * ((v159 + 1) % v160));
            v171 = v170[16];
            v172 = v170[17];
            v191.m_x = v170[15];
            v191.m_y = v171;
            v191.m_z = v172;
            v173 = p_m_dynAreaData[1];
            v174 = p_m_dynAreaData[2];
            v192.m_x = *p_m_dynAreaData;
            v192.m_y = v173;
            v192.m_z = v174;
            if ( (unsigned __int8)bfx::LineSegIntersectsClippingVolume(
                                    posA: &v192,
                                    posB: &v191,
                                    pClipPlanes: &v194,
                                    numPlanes: 5,
                                    planeIndexToIgnore: -1) != 0 )
              break;
          }
          ++v159;
          p_m_dynAreaData += 6;
          v160 = m_pCurDynArea->m_flags.m_flags1 & 0x7F;
          if ( v159 >= v160 )
            goto LABEL_36;
        }
        if ( HIDWORD(v145) != 0 )
          bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)HIDWORD(v145));
        return 0;
      }
LABEL_36:
      bfx::ActiveAreasInSphereCursor::operator++(this: &v211);
    }
  }
  if ( HIDWORD(v145) != 0 )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)HIDWORD(v145));
  return 1;
}


// ========================================================================
// __unwind$52868
// EA  : 0x8327C6E8
// RVA : 0x0127C6E8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_52868()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 1648 + 176));
}


// ========================================================================
// ?GetNavGraphsWithinPortalCreationDist@NavLayer@bfx@@QAAXPAVNavGraph@2@MAAV?$Array@PAVNavGraph@bfx@@@2@@Z
// EA  : 0x8327C710
// RVA : 0x0127C710
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::NavLayer::GetNavGraphsWithinPortalCreationDist(
        bfx::NavLayer *this,
        bfx::NavGraph *pNavGraph,
        double maxPortalCreationDist,
        bfx::Array<bfx::NavGraph *> *nearbyNavGraphsOut,
        bfx::Array<bfx::Space *> *a5)
{
  double v5; // fp10
  double v6; // fp8
  double v7; // fp6
  double v8; // fp3
  bfx::Box v9; // [sp+60h] [-30h] BYREF
  bfx::Vec3 v10; // 0:^50.12

  v5 = (float)(pNavGraph->m_bbox.m_min.m_x - (float)maxPortalCreationDist);
  v6 = (float)(pNavGraph->m_bbox.m_min.m_y - (float)maxPortalCreationDist);
  v7 = (float)(pNavGraph->m_bbox.m_min.m_z - (float)maxPortalCreationDist);
  v8 = (float)(pNavGraph->m_bbox.m_max.m_y + (float)maxPortalCreationDist);
  v9.m_min.m_x = pNavGraph->m_bbox.m_max.m_x + (float)maxPortalCreationDist;
  v9.m_min.m_y = v8;
  v10.m_x = v5;
  v10.m_y = v6;
  v10.m_z = v7;
  v9.m_min.m_z = pNavGraph->m_bbox.m_max.m_z + (float)maxPortalCreationDist;
  v9.m_max = v9.m_min;
  v9.m_min = v10;
  bfx::NavLayer::GetNavGraphsIntersectingBox(this, box: &v9, navGraphsOut: a5);
}


// ========================================================================
// ?SubdivideAllActivePortalEdgesInStaticArea@bfx@@YAXPAVArea@1@PBVDynKDTree@1@MM@Z
// EA  : 0x8327C7C8
// RVA : 0x0127C7C8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::SubdivideAllActivePortalEdgesInStaticArea(
        bfx::Space *pStaticArea,
        const bfx::DynKDTree *pAllStaticPortalEdgesKDTree,
        double subdivThreshold,
        double maxPortalCreationDist,
        bfx::Array<bfx::PortalSubdivData> *a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        bfx::Space *a14)
{
  char *m_pProxy; // r10
  bfx::DynAreaData *p_m_pProxy; // r11
  bfx::Area *v20; // r30
  int v21; // r28
  int v22; // r29
  int m_size; // r11
  int v24; // r28
  int v25; // r29
  bfx::PortalSubdivData *v26; // r30
  signed int v27; // r27
  int v28; // r30
  int v29; // r29
  bfx::PortalSubdivData *v30; // r28
  bfx::Array<bfx::PortalSubdivData> v31; // [sp+60h] [-B0h] BYREF
  bfx::Array<bfx::Space *> v32; // [sp+70h] [-A0h] BYREF
  bfx::DGraph v33; // [sp+80h] [-90h] BYREF

  a14 = pStaticArea;
  memset(&v31, 0, 12);
  v31.m_tag = bfx::MEM_BFXPLANNER;
  m_pProxy = (char *)pStaticArea->m_pProxy;
  p_m_pProxy = (bfx::DynAreaData *)&pStaticArea->m_pProxy;
  if ( m_pProxy != nullptr && *(_DWORD *)m_pProxy != 0 )
  {
    v20 = (bfx::Area *)(p_m_pProxy->m_data + 20);
    if ( p_m_pProxy->m_data != nullptr )
    {
      v21 = *(_DWORD *)p_m_pProxy->m_data;
    }
    else
    {
      v20 = nullptr;
      v21 = 0;
    }
    v22 = 0;
    if ( v21 == 0 )
      goto LABEL_25;
    do
    {
      bfx::SubdivideAllPortalEdgesInArea(
        pArea: v20,
        pAllStaticPortalEdgesKDTree,
        subdivThreshold,
        maxPortalCreationDist,
        subdivsOut: a5,
        a6,
        a7: &v31);
      ++v22;
      v20 = (bfx::Area *)((char *)v20 + 24 * (v20->m_flags.m_flags1 & 0x7F) + 72);
    }
    while ( v22 != v21 );
  }
  else
  {
    bfx::SubdivideAllPortalEdgesInArea(
      pArea: (bfx::Area *)pStaticArea,
      pAllStaticPortalEdgesKDTree,
      subdivThreshold,
      maxPortalCreationDist,
      subdivsOut: a5,
      a6,
      a7: &v31);
  }
  m_size = v31.m_size;
  if ( v31.m_size != 0 )
  {
    v24 = 0;
    if ( v31.m_size > 0 )
    {
      v25 = 0;
      do
      {
        v26 = &v31.m_data[v25];
        bfx::ScootSubdivVertsOutwards(subdiv: &v31.m_data[v25]);
        if ( v26->m_subdivElems.m_size != 0 )
        {
          ++v24;
          ++v25;
        }
        else
        {
          bfx::Array<bfx::PortalSubdivData>::erase(this: &v31, ptr: &v31.m_data[v25]);
        }
        m_size = v31.m_size;
      }
      while ( v24 < v31.m_size );
    }
    if ( m_size != 0 )
    {
      v27 = LODWORD(pStaticArea->m_rotWorldToSpace.m_w) & 0x7F;
      memset(&v32, 0, 12);
      v32.m_tag = bfx::MEM_BFXPLANNER;
      bfx::Array<bfx::Portal *>::push_back(this: &v32, val: &a14);
      bfx::DGraph::DGraph(this: &v33);
      bfx::DGraph::BuildGraphFromAreas(this: &v33, staticAreas: (const bfx::Array<bfx::Area *> *)&v32);
      v28 = 0;
      if ( v31.m_size > 0 )
      {
        v29 = 0;
        do
        {
          v30 = &v31.m_data[v29];
          bfx::DGraph::ApplyPortalSubdiv(this: &v33, portalSubdivData: &v31.m_data[v29]);
          ++v28;
          v27 += v30->m_subdivElems.m_size;
          ++v29;
        }
        while ( v28 < v31.m_size );
      }
      bfx::DGraph::BuildFaces(this: &v33);
      if ( v27 <= 127 )
      {
        bfx::DGraph::FinalizeFaces(this: &v33, pObstacle: nullptr, addingObstacle: true);
        bfx::DGraph::WriteGraphToAreas(this: &v33, staticAreas: (const bfx::Array<bfx::Area *> *)&v32);
      }
      bfx::DGraph::~DGraph(this: &v33);
      v32.m_size = 0;
      if ( v32.m_data != nullptr )
      {
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v32.m_data);
        v32.m_data = nullptr;
      }
      v32.m_cap = 0;
    }
  }
LABEL_25:
  bfx::Array<bfx::PortalSubdivData>::shrink(this: &v31, size: 0);
  if ( v31.m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v31.m_data);
}


// ========================================================================
// __unwind$54149
// EA  : 0x8327CA40
// RVA : 0x0127CA40
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_54149()
{
  int v0; // r12

  bfx::Array<bfx::PortalSubdivData>::~Array<bfx::PortalSubdivData>(this: (bfx::Array<bfx::PortalSubdivData> *)(v0 - 272 + 96));
}


// ========================================================================
// __unwind$54150
// EA  : 0x8327CA68
// RVA : 0x0127CA68
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_54150()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 272 + 112));
}


// ========================================================================
// __unwind$54151
// EA  : 0x8327CA90
// RVA : 0x0127CA90
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_54151()
{
  int v0; // r12

  bfx::DGraph::~DGraph(this: (bfx::DGraph *)(v0 - 272 + 128));
}


// ========================================================================
// ?SubdividePortalEdges@bfx@@YAXAAV?$Array@PAVArea@bfx@@@1@0MM@Z
// EA  : 0x8327CAC0
// RVA : 0x0127CAC0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::SubdividePortalEdges(
        bfx::Array<bfx::Area *> *myStaticPortalAreas,
        bfx::Array<bfx::Area *> *theirStaticPortalAreas,
        double subdivThreshold,
        double maxPortalCreationDist)
{
  int v5; // r30
  int v8; // r9
  int v9; // r8
  int v10; // r7
  int v11; // r6
  bfx::Array<bfx::PortalSubdivData> *v12; // r5
  bfx::DynKDTree *v13; // r3
  int m_size; // r10
  bfx::DynKDTree *v15; // r27
  int v16; // r29
  int v17; // [sp+8h] [-98h]
  int v18; // [sp+Ch] [-94h]
  int v19; // [sp+10h] [-90h]
  bfx::Space *v20; // [sp+14h] [-8Ch]
  bfx::Array<bfx::ReplayLogListenerEntry> v21; // [sp+50h] [-50h] BYREF

  v5 = 0;
  memset(&v21, 0, 12);
  v21.m_tag = bfx::MEM_BFXPLANNER;
  bfx::GetUnconnectedPortalEdges(staticPortalAreas: theirStaticPortalAreas, portalEdgesOut: &v21);
  v13 = bfx::BuildKDTreeForEdges(staticPortalEdges: (const bfx::Array<bfx::EdgeCursor> *)&v21);
  m_size = myStaticPortalAreas->m_size;
  v15 = v13;
  if ( m_size > 0 )
  {
    v16 = 0;
    do
    {
      bfx::SubdivideAllActivePortalEdgesInStaticArea(
        pStaticArea: (bfx::Space *)myStaticPortalAreas->m_data[v16],
        pAllStaticPortalEdgesKDTree: v15,
        subdivThreshold,
        maxPortalCreationDist,
        a5: v12,
        a6: v11,
        a7: v10,
        a8: v9,
        a9: v8,
        a10: m_size,
        a11: v17,
        a12: v18,
        a13: v19,
        a14: v20);
      m_size = myStaticPortalAreas->m_size;
      ++v5;
      ++v16;
    }
    while ( v5 < m_size );
  }
  if ( v15 != nullptr )
  {
    bfx::DynKDTree::~DynKDTree(this: v15);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v15);
  }
  if ( v21.m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v21.m_data);
}


// ========================================================================
// __unwind$54390
// EA  : 0x8327CBA0
// RVA : 0x0127CBA0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_54390()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 160 + 80));
}


// ========================================================================
// ?ConnectPortalsAndApplyObstacles@bfx@@YAXPAVNavGraph@1@@Z
// EA  : 0x8327CBD0
// RVA : 0x0127CBD0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::ConnectPortalsAndApplyObstacles(bfx::Space *pNavGraph)
{
  double Scale; // fp1
  bfx::NavLayer *m_pProxy; // r27
  double v4; // fp12
  bfx::SpaceComponent **m_data; // r7
  bfx::Planner *v6; // r23
  bfx::ObstacleCatalog *m_pObstacleCatalog; // r22
  bfx::Array<bfx::NavGraph *> *v10; // r5
  double v11; // fp2
  double v12; // fp0
  double v13; // fp13
  double v14; // fp11
  bfx::Array<bfx::Box> *v15; // r5
  bfx::bfxMemTag v16; // r11
  char *v17; // r20
  bfx::Space **v18; // r26
  int i; // r25
  double v20; // fp30
  bfx::Array<bfx::ObstacleImpl *> *v21; // r26
  const bfx::DynKDTree *v22; // r5
  char *v23; // r21
  int m_layerIndex; // r9
  unsigned int v25; // r24
  bfx::IslandGraph *m_pIslandGraph; // r26
  double v27; // fp30
  bfx::Array<bfx::ReplayLogListenerEntry> v28; // [sp+50h] [-140h] BYREF
  bfx::Array<bfx::SpaceComponent *> v29; // [sp+60h] [-130h] BYREF
  bfx::Array<bfx::SpaceComponent *> v30; // [sp+70h] [-120h] BYREF
  bfx::Array<bfx::ReplayLogListenerEntry> v31; // [sp+80h] [-110h] BYREF
  bfx::Array<bfx::SpaceComponent *> v32; // [sp+90h] [-100h] BYREF
  bfx::Array<bfx::Space *> v33; // [sp+A0h] [-F0h] BYREF
  bfx::Array<bfx::ObstacleImpl *> v34; // [sp+B0h] [-E0h] BYREF
  bfx::BinaryHeap<bfx::OpenNode3D,float>::Node v35; // [sp+C0h] [-D0h] BYREF
  bfx::Array<bfx::Space *> v36; // [sp+E0h] [-B0h] BYREF
  bfx::Array<bfx::BinaryHeap<bfx::OpenNode3D,float>::Node> v37; // [sp+F0h] [-A0h] BYREF
  bfx::Array<bfx::ReplayLogListenerEntry> v38; // [sp+100h] [-90h] BYREF
  bfx::Vec3 *v39; // [sp+110h] [-80h]

  Scale = bfx::GetScale();
  m_pProxy = (bfx::NavLayer *)pNavGraph->m_pProxy;
  v4 = *(float *)(LODWORD(pNavGraph->m_pos.m_y) + 20);
  memset(&v36, 0, 12);
  m_data = m_pProxy->m_pSpace->m_components.m_data;
  v36.m_tag = bfx::MEM_BFXPLANNER;
  v6 = (bfx::Planner *)m_data[1];
  _FP9 = (float)((float)((float)Scale * (float)2.0) - (float)((float)v4 * (float)5.0));
  m_pObstacleCatalog = v6->m_pObstacleCatalog;
  __asm { fsel      f31, f9, f11, f10 }
  bfx::NavLayer::GetNavGraphsWithinPortalCreationDist(
    this: m_pProxy,
    (bfx::NavGraph *)pNavGraph,
    maxPortalCreationDist: _FP31,
    nearbyNavGraphsOut: v10,
    a5: &v36);
  v11 = (float)(pNavGraph->m_matWorldToSpace.m_data[12] - (float)_FP31);
  v12 = (float)(pNavGraph->m_matWorldToSpace.m_data[11] - (float)_FP31);
  v13 = (float)(pNavGraph->m_matWorldToSpace.m_data[13] + (float)_FP31);
  v14 = (float)(pNavGraph->m_matWorldToSpace.m_data[10] - (float)_FP31);
  *(float *)&v31.m_size = pNavGraph->m_matWorldToSpace.m_data[14] + (float)_FP31;
  *(float *)&v28.m_cap = v11;
  *(float *)&v28.m_size = v12;
  *(float *)&v31.m_data = v13;
  *(float *)&v28.m_data = v14;
  *(float *)&v31.m_cap = pNavGraph->m_matWorldToSpace.m_data[15] + (float)_FP31;
  memset(&v37, 0, 12);
  v39 = (bfx::Vec3 *)&pNavGraph->m_matWorldToSpace.m_data[13];
  *(_QWORD *)&v35.m_elem.m_parentIdx = *(_QWORD *)&v31.m_size;
  v35.m_elem.m_pPortal = (const bfx::Portal *)v28.m_data;
  LODWORD(v35.m_elem.m_searchCost) = v31.m_data;
  *(_QWORD *)&v35.m_elem.m_dir = *(_QWORD *)&v28.m_size;
  v37.m_tag = bfx::MEM_BFXPLANNER;
  bfx::Array<bfx::Box>::push_back(this: &v37, val: &v35);
  memset(&v35, 0, 12);
  LODWORD(v35.m_elem.m_searchCost) = bfx::MEM_BFXPLANNER;
  bfx::GetOtherNavGraphExpandedBBoxes(
    pExceptionNavGraph: (bfx::NavGraph *)pNavGraph,
    nearbyNavGraphs: (const bfx::Array<bfx::NavGraph *> *)&v36,
    maxPortalCreationDist: _FP31,
    bboxesOut: v15,
    a5: (bfx::Array<bfx::BinaryHeap<bfx::OpenNode3D,float>::Node> *)&v35);
  memset(&v29, 0, 12);
  v29.m_tag = bfx::MEM_BFXPLANNER;
  bfx::NavGraph::GetStaticPortalAreasOverlappingBBoxes(
    this: (bfx::NavGraph *)pNavGraph,
    bboxes: (const bfx::Array<bfx::Box> *)&v35,
    staticPortalAreasOut: &v29);
  v16 = bfx::MEM_BFXPLANNER;
  memset(&v30, 0, 12);
  v30.m_tag = bfx::MEM_BFXPLANNER;
  v17 = (char *)v36.m_data;
  if ( v36.m_size > 0 )
  {
    v18 = v36.m_data;
    for ( i = v36.m_size; i != 0; --i )
    {
      if ( *v18 != pNavGraph )
        bfx::NavGraph::GetStaticPortalAreasOverlappingBBoxes(
          this: (bfx::NavGraph *)*v18,
          bboxes: (const bfx::Array<bfx::Box> *)&v37,
          staticPortalAreasOut: &v30);
      ++v18;
    }
    v16 = bfx::MEM_BFXPLANNER;
  }
  v28.m_tag = v16;
  memset(&v28, 0, 12);
  bfx::GetStaticPortalEdges(staticPortalAreas: (bfx::Array<bfx::Area *> *)&v29, staticPortalEdgesOut: &v28);
  bfx::GetStaticPortalEdges(staticPortalAreas: (bfx::Array<bfx::Area *> *)&v30, staticPortalEdgesOut: &v28);
  memset(&v34, 0, 12);
  v34.m_tag = bfx::MEM_BFXPLANNER;
  if ( v28.m_size != 0 )
  {
    v20 = *(float *)&pNavGraph->m_pProxy[1].m_pTarget;
    v21 = (bfx::Array<bfx::ObstacleImpl *> *)bfx::BuildKDTreeForEdges(staticPortalEdges: (const bfx::Array<bfx::EdgeCursor> *)&v28);
    bfx::GetObstaclesIntersectingPortalEdges(
      pObstacleCatalog: m_pObstacleCatalog,
      layerNum: m_pProxy->m_layerIndex,
      layerRadius: v20,
      pAllStaticPortalEdgesKDTree: v22,
      obstacles: v21);
    bfx::ApplyObstaclesToLayer(
      pPlanner: v6,
      obstacles: &v34,
      pNavLayer: m_pProxy,
      spec: UNAPPLY_OBSTACLE,
      pExceptionNavGraph: (bfx::NavGraph *)pNavGraph);
    if ( v21 != nullptr )
    {
      bfx::DynKDTree::~DynKDTree(this: (bfx::DynKDTree *)v21);
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v21);
    }
    v28.m_size = 0;
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v28.m_data);
    v23 = nullptr;
    v28.m_cap = 0;
    v28.m_data = nullptr;
    if ( v29.m_size != 0 && v30.m_size != 0 )
    {
      m_layerIndex = m_pProxy->m_layerIndex;
      memset(&v32, 0, 12);
      v25 = 1 << m_layerIndex;
      v32.m_tag = bfx::MEM_BFXPLANNER;
      bfx::GetLinksInPortalAreas(allocatedAreas: (bfx::Array<bfx::Area *> *)&v29, linksOut: &v32);
      bfx::GetLinksInPortalAreas(allocatedAreas: (bfx::Array<bfx::Area *> *)&v30, linksOut: &v32);
      bfx::RemoveLinksFromLayers(pPlanner: v6, links: (bfx::Array<bfx::LinkBase *> *)&v32, layersToRemoveFrom: v25);
      m_pIslandGraph = m_pProxy->m_pIslandGraph;
      bfx::InvalidatePortalIslands(pIslandGraph: m_pIslandGraph, staticPortalAreas: (bfx::Array<bfx::Area *> *)&v29);
      bfx::InvalidatePortalIslands(pIslandGraph: m_pIslandGraph, staticPortalAreas: (bfx::Array<bfx::Area *> *)&v30);
      v27 = (float)(bfx::GetScale() * (float)0.1);
      bfx::SubdividePortalEdges(
        myStaticPortalAreas: (bfx::Array<bfx::Area *> *)&v29,
        theirStaticPortalAreas: (bfx::Array<bfx::Area *> *)&v30,
        subdivThreshold: v27,
        maxPortalCreationDist: _FP31);
      bfx::SubdividePortalEdges(
        myStaticPortalAreas: (bfx::Array<bfx::Area *> *)&v30,
        theirStaticPortalAreas: (bfx::Array<bfx::Area *> *)&v29,
        subdivThreshold: v27,
        maxPortalCreationDist: _FP31);
      memset(&v38, 0, 12);
      v38.m_tag = bfx::MEM_BFXPLANNER;
      v31.m_tag = bfx::MEM_BFXPLANNER;
      memset(&v31, 0, 12);
      bfx::GetUnconnectedPortalEdges(staticPortalAreas: (bfx::Array<bfx::Area *> *)&v29, portalEdgesOut: &v38);
      bfx::GetUnconnectedPortalEdges(staticPortalAreas: (bfx::Array<bfx::Area *> *)&v30, portalEdgesOut: &v31);
      bfx::NavLayer::ConnectPortalEdgesToAdjNavGraphs(
        this: m_pProxy,
        pNewNavGraph: (bfx::NavGraph *)pNavGraph,
        myPortalEdges: (bfx::Array<bfx::EdgeCursor> *)&v38,
        theirPortalEdges: (const bfx::Array<bfx::EdgeCursor> *)&v31,
        maxPortalCreationDist: _FP31);
      if ( BYTE1(bfx::g_pCurInstance->m_pComponentManager->m_components[1][13].__vftable) != 0 )
        bfx::CreateCornerAllocatedAreas(pNewNavGraph: (bfx::NavGraph *)pNavGraph);
      bfx::RemoveUneededDynamicAreas(staticAreas: (const bfx::Array<bfx::Area *> *)&v29);
      bfx::RemoveUneededDynamicAreas(staticAreas: (const bfx::Array<bfx::Area *> *)&v30);
      bfx::CreatePortalIslands(pIslandGraph: m_pIslandGraph, staticPortalAreas: (bfx::Array<bfx::Area *> *)&v29);
      bfx::CreatePortalIslands(pIslandGraph: m_pIslandGraph, staticPortalAreas: (bfx::Array<bfx::Area *> *)&v30);
      bfx::ApplyLinksToLayers(pPlanner: v6, links: (bfx::Array<bfx::LinkBase *> *)&v32, layerApplicationMask: v25);
      if ( v31.m_data != nullptr )
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v31.m_data);
      if ( v38.m_data != nullptr )
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v38.m_data);
      v32.m_size = 0;
      if ( v32.m_data != nullptr )
      {
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v32.m_data);
        v32.m_data = nullptr;
      }
      v32.m_cap = 0;
    }
  }
  else
  {
    v23 = (char *)v28.m_data;
  }
  memset(&v33, 0, 12);
  v33.m_tag = bfx::MEM_BFXPLANNER;
  bfx::GetObstaclesIntersectingNavGraph(
    pObstacleCatalog: m_pObstacleCatalog,
    (bfx::NavGraph *)pNavGraph,
    obstacles: (bfx::Array<bfx::ObstacleImpl *> *)&v33);
  bfx::SubtractFirstArrayFromSecondArray(array1: &v34, array2: &v33);
  bfx::ApplyObstaclesToLayer(
    pPlanner: v6,
    obstacles: (bfx::Array<bfx::ObstacleImpl *> *)&v33,
    pNavLayer: m_pProxy,
    spec: UNAPPLY_OBSTACLE,
    pExceptionNavGraph: (bfx::NavGraph *)pNavGraph);
  bfx::ApplyObstaclesToLayer(
    pPlanner: v6,
    obstacles: &v34,
    pNavLayer: m_pProxy,
    spec: APPLY_OBSTACLE,
    pExceptionNavGraph: nullptr);
  bfx::ApplyObstaclesToLayer(
    pPlanner: v6,
    obstacles: (bfx::Array<bfx::ObstacleImpl *> *)&v33,
    pNavLayer: m_pProxy,
    spec: APPLY_OBSTACLE,
    pExceptionNavGraph: nullptr);
  v33.m_size = 0;
  if ( v33.m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v33.m_data);
    v33.m_data = nullptr;
  }
  v33.m_cap = 0;
  v34.m_size = 0;
  if ( v34.m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v34.m_data);
    v34.m_data = nullptr;
  }
  v34.m_cap = 0;
  if ( v23 != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v23);
  v30.m_size = 0;
  if ( v30.m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v30.m_data);
    v30.m_data = nullptr;
  }
  v30.m_cap = 0;
  v29.m_size = 0;
  if ( v29.m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v29.m_data);
    v29.m_data = nullptr;
  }
  v29.m_cap = 0;
  if ( v35.m_elem.m_pPortal != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v35.m_elem.m_pPortal);
  if ( v37.m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v37.m_data);
  if ( v17 != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v17);
}


// ========================================================================
// __unwind$54469
// EA  : 0x8327D1A4
// RVA : 0x0127D1A4
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_54469()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 400 + 224));
}


// ========================================================================
// __unwind$54470
// EA  : 0x8327D1CC
// RVA : 0x0127D1CC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_54470()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 400 + 240));
}


// ========================================================================
// __unwind$54471
// EA  : 0x8327D1F4
// RVA : 0x0127D1F4
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_54471()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 400 + 192));
}


// ========================================================================
// __unwind$54472
// EA  : 0x8327D21C
// RVA : 0x0127D21C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_54472()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 400 + 96));
}


// ========================================================================
// __unwind$54473
// EA  : 0x8327D244
// RVA : 0x0127D244
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_54473()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 400 + 112));
}


// ========================================================================
// __unwind$54474
// EA  : 0x8327D26C
// RVA : 0x0127D26C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_54474()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 400 + 80));
}


// ========================================================================
// __unwind$54475
// EA  : 0x8327D294
// RVA : 0x0127D294
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_54475()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 400 + 176));
}


// ========================================================================
// __unwind$54476
// EA  : 0x8327D2BC
// RVA : 0x0127D2BC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_54476()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 400 + 144));
}


// ========================================================================
// __unwind$54477
// EA  : 0x8327D2E4
// RVA : 0x0127D2E4
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_54477()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 400 + 256));
}


// ========================================================================
// __unwind$54478
// EA  : 0x8327D30C
// RVA : 0x0127D30C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_54478()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 400 + 128));
}


// ========================================================================
// __unwind$54479
// EA  : 0x8327D334
// RVA : 0x0127D334
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_54479()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 400 + 160));
}


// ========================================================================
// ?AddNavGraph@NavLayer@bfx@@QAA_NPADABVResourceOffset@2@@Z
// EA  : 0x8327D368
// RVA : 0x0127D368
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

int __fastcall bfx::NavLayer::AddNavGraph(
        bfx::NavLayer *this,
        char *pNavGraphImageStart,
        const bfx::ResourceOffset *offset)
{
  bool *p_m_addRemoveNavGraphInProgress; // r22
  int NextFreeSlotIndex; // r28
  __int64 v8; // r10
  __int64 v9; // r8
  __int64 v10; // r6
  bfx::ShapeDat *p_m_shapeDat; // r26
  bfx::NavGraph *v12; // r27
  float v13; // r8
  int v14; // r7
  int v15; // r6
  int v16; // r5
  double m_y; // fp13
  double m_x; // fp12
  bfx::Vec3 *p_m_matWorldToSpace; // r4
  bfx::Quaternion *p_m_rotationOffset; // r5
  int m_layerOffset; // r29
  bfx::Space *v22; // r3
  bfx::NavGraph *v23; // r29
  bfx::NavGraphInitStatus m_initStatus; // r27
  int m_endGraphIndex; // r10
  float v26; // r10
  float v27; // r9
  float *p_m_version; // r11
  bfx::XGraph *m_pXGraph; // r3
  unsigned __int64 m_areaInvalidationTimestamp; // r11
  int result; // r3
  __int64 v32; // r10
  __int64 v33; // r8
  __int64 v34; // r6
  __int64 v35; // r4
  __int64 v36; // r4
  const bfx::ShapeDat *v37; // [sp+8h] [-108h]
  int v38; // [sp+Ch] [-104h]
  int v39; // [sp+10h] [-100h]
  int v40; // [sp+14h] [-FCh]
  int v41; // [sp+18h] [-F8h]
  bfx::Space *v42; // [sp+1Ch] [-F4h]
  int v43; // [sp+20h] [-F0h]
  int v44; // [sp+24h] [-ECh]
  int v45; // [sp+28h] [-E8h]
  int v46; // [sp+2Ch] [-E4h]
  int v47; // [sp+30h] [-E0h]
  int v48; // [sp+34h] [-DCh]
  int v49; // [sp+38h] [-D8h]
  int v50; // [sp+3Ch] [-D4h]
  int v51; // [sp+40h] [-D0h]
  int v52; // [sp+44h] [-CCh]
  int v53; // [sp+48h] [-C8h]
  int v54; // [sp+4Ch] [-C4h]
  int v55; // [sp+50h] [-C0h]
  bfx::Vec3 v56; // [sp+80h] [-90h] BYREF
  bfx::Matrix v57[2]; // [sp+90h] [-80h] BYREF

  p_m_addRemoveNavGraphInProgress = &this->m_addRemoveNavGraphInProgress;
  this->m_addRemoveNavGraphInProgress = true;
  NextFreeSlotIndex = bfx::NavLayer::GetNextFreeSlotIndex(this);
  if ( NextFreeSlotIndex < 0 )
  {
    LODWORD(v36) = this->m_layerIndex;
    HIDWORD(v10) = 2048;
    HIDWORD(v36) = "Layer %d is full (max %d graphs per layer). AddNavGraph aborted.\n";
    bfx::InternalWarning(fmt: v36, a2: v10, a3: v9, a4: v8, a5: (int)v37, a6: v38, a7: v39, a8: v40);
LABEL_20:
    result = 0;
    goto LABEL_21;
  }
  p_m_shapeDat = nullptr;
  if ( this->m_numGraphs >= 1 )
    p_m_shapeDat = &this->m_shapeDat;
  v12 = (bfx::NavGraph *)bfx::MemoryManager::Malloc(
                           this: bfx::g_pCurInstance->m_pMemoryManager,
                           size: 0xC4u,
                           tag: bfx::MEM_BFXPLANNER);
  if ( v12 != nullptr )
  {
    m_y = offset->m_positionOffset.m_y;
    m_x = offset->m_positionOffset.m_x;
    p_m_matWorldToSpace = (bfx::Vec3 *)&this->m_pSpace->m_matWorldToSpace;
    v56.m_z = offset->m_positionOffset.m_z;
    v56.m_x = m_x;
    v56.m_y = m_y;
    bfx::Matrix::operator*(this: v57, result: p_m_matWorldToSpace, rhs: &v56);
    p_m_rotationOffset = &offset->m_rotationOffset;
    m_layerOffset = offset->m_layerOffset;
    v22 = bfx::Space::RotateToSpace(
            this: (bfx::Space *)&v57[0].m_data[4],
            result: (bfx::Quat *)this->m_pSpace,
            rotIn: p_m_rotationOffset);
    v23 = bfx::NavGraph::NavGraph(
            this: v12,
            pSpace: this->m_pSpace,
            pNavLayer: this,
            pBinaryImage: pNavGraphImageStart,
            graphIndex: NextFreeSlotIndex,
            posOffset: (const bfx::Vec3 *)v57,
            rotOffset: (const bfx::Quat *)v22,
            layerOffset: m_layerOffset,
            pShapeDatOverride: v37,
            a10: v38,
            a11: v39,
            a12: v40,
            a13: v41,
            a14: (int)v42,
            a15: v43,
            a16: v44,
            a17: v45,
            a18: v46,
            a19: v47,
            a20: v48,
            a21: v49,
            a22: v50,
            a23: v51,
            a24: v52,
            a25: v53,
            a26: v54,
            a27: v55,
            a28: p_m_shapeDat);
  }
  else
  {
    v23 = nullptr;
  }
  m_initStatus = v23->m_initStatus;
  if ( m_initStatus != NAVGRAPH_INIT_OK )
  {
    bfx::NavGraph::~NavGraph(this: v23);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v23);
    if ( m_initStatus == NAVGRAPH_FAILED_DUE_TO_INSUFFICIENT_ISLANDS )
    {
      LODWORD(v35) = this->m_layerIndex;
      HIDWORD(v35) = "Failed to create NavGraph on layer %d due to insufficient islands.\n";
    }
    else
    {
      HIDWORD(v35) = "Failed to create NavGraph. AddNavGraph aborted.\n";
    }
    bfx::InternalWarning(fmt: v35, a2: v34, a3: v33, a4: v32, a5: (int)v37, a6: v38, a7: v39, a8: v40);
    goto LABEL_20;
  }
  m_endGraphIndex = this->m_endGraphIndex;
  ++this->m_numGraphs;
  if ( NextFreeSlotIndex >= m_endGraphIndex )
    this->m_endGraphIndex = NextFreeSlotIndex + 1;
  LODWORD(v26) = 4 * (NextFreeSlotIndex + 8);
  *(bfx::Space **)((char *)&this->m_pSpace + LODWORD(v26)) = (bfx::Space *)v23;
  v27 = *(float *)&this->m_numGraphs;
  if ( LODWORD(v27) == 1 )
  {
    p_m_version = (float *)&v23->m_pHeader->m_version;
    v27 = p_m_version[6];
    v13 = p_m_version[7];
    v26 = p_m_version[8];
    this->m_shapeDat.m_height = v26;
    this->m_shapeDat.m_step = v13;
    this->m_shapeDat.m_radius = v27;
  }
  bfx::NavGraphSpatialOrganization::AddNavGraph(
    this: &this->m_navGraphSpatialOrg,
    pNavGraph: (bfx::Space *)v23,
    a3: v16,
    a4: v15,
    a5: v14,
    a6: SLODWORD(v13),
    a7: SLODWORD(v27),
    a8: SLODWORD(v26),
    a9: (int)v37,
    a10: v38,
    a11: v39,
    a12: v40,
    a13: v41,
    a14: v42);
  m_pXGraph = this->m_pXGraph;
  if ( m_pXGraph != nullptr )
    m_pXGraph->MarkDirty(this: m_pXGraph);
  bfx::ConnectPortalsAndApplyObstacles(pNavGraph: (bfx::Space *)v23);
  m_areaInvalidationTimestamp = this->m_areaInvalidationTimestamp;
  LODWORD(m_areaInvalidationTimestamp) = m_areaInvalidationTimestamp + 1;
  this->m_areaInvalidationTimestamp = m_areaInvalidationTimestamp;
  result = 1;
LABEL_21:
  *p_m_addRemoveNavGraphInProgress = false;
  return result;
}


// ========================================================================
// __unwind$55016
// EA  : 0x8327D584
// RVA : 0x0127D584
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_55016()
{
  int v0; // r12

  bfx::SetBooleanOnExitOb::~SetBooleanOnExitOb(this: (bfx::SetBooleanOnExitOb *)(v0 - 272 + 104));
}


// ========================================================================
// __unwind$55017
// EA  : 0x8327D5AC
// RVA : 0x0127D5AC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_55017()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 272 + 96), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?AddNavGraphsFromImage@Planner@bfx@@QAAIPADABVResourceOffset@2@@Z
// EA  : 0x8327D5E0
// RVA : 0x0127D5E0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
unsigned int __fastcall bfx::Planner::AddNavGraphsFromImage(
        bfx::Planner *this,
        char *pInputBinaryImage,
        __int64 offset,
        __int64 a4)
{
  unsigned int v4; // r11
  bfx::Planner *v5; // r3
  bfx::Planner *v6; // r27
  int v7; // r10
  const bfx::ResourceOffset *v9; // r21
  bool v10; // cr57
  unsigned __int8 v11; // r11
  __int64 v12; // r10
  const char *v13; // r3
  unsigned int v15; // r22
  char *v16; // r28
  int i; // r26
  int v18; // r11
  int v19; // r30
  int v20; // r29
  bfx::NavLayer *v21; // r3
  bfx::NavLayer *v22; // r3
  __int64 v23; // r4
  int v24; // [sp+8h] [-C8h]
  int v25; // [sp+Ch] [-C4h]
  int v26; // [sp+10h] [-C0h]
  int v27; // [sp+14h] [-BCh]
  unsigned int v28; // [sp+50h] [-80h] BYREF

  v4 = *((_DWORD *)pInputBinaryImage + 1);
  v6 = v5;
  v7 = (unsigned __int8)*pInputBinaryImage;
  v9 = (const bfx::ResourceOffset *)HIDWORD(offset);
  v28 = v4;
  if ( v7 == 0 )
  {
    bfx::EndianSwapLong(val: &v28);
    v4 = v28;
  }
  v10 = v4 > 0x25;
  if ( v4 < 0x25 || (v11 = 1, v10) )
    v11 = 0;
  HIDWORD(v12) = v11 != 0;
  if ( v11 != 0 )
  {
    if ( *pInputBinaryImage == 0 )
      bfx::EndianSwapBinaryImage(pInputBinaryImage);
    v15 = 0;
    v16 = pInputBinaryImage + 12;
    for ( i = 0; i < *((_DWORD *)pInputBinaryImage + 2); v16 += *((_DWORD *)v16 + 3) )
    {
      v18 = *((_DWORD *)v16 + 1);
      LODWORD(v12) = v9->m_layerOffset;
      v19 = v18 + v12;
      if ( (unsigned int)(v18 + v12) >= 0x20 )
      {
        HIDWORD(v23) = "attempt to add layer with layerIndex=%d, which is outside the allowed 0-31 range\n";
        LODWORD(v23) = v18 + v12;
        bfx::InternalWarning(fmt: v23, a2: offset, a3: a4, a4: v12, a5: v24, a6: v25, a7: v26, a8: v27);
      }
      else
      {
        v20 = 4 * (v19 + 2);
        v21 = *(bfx::NavLayer **)((char *)&v6->__vftable + v20);
        if ( v21 == nullptr )
        {
          v22 = (bfx::NavLayer *)bfx::MemoryManager::Malloc(
                                   this: bfx::g_pCurInstance->m_pMemoryManager,
                                   size: 0x2050u,
                                   tag: bfx::MEM_BFXPLANNER);
          v28 = (unsigned int)v22;
          if ( v22 != nullptr )
            v21 = bfx::NavLayer::NavLayer(this: v22, pSpace: v6->m_pSpace, layerIndex: v19);
          else
            v21 = nullptr;
          *(bfx::Planner_vtbl **)((char *)&v6->__vftable + v20) = (bfx::Planner_vtbl *)v21;
        }
        if ( (unsigned __int8)bfx::NavLayer::AddNavGraph(this: v21, pNavGraphImageStart: v16, offset: v9) != 0 )
          v15 |= 1 << v19;
      }
      ++i;
    }
    bfx::ApplyLinksToLayers(pPlanner: v6, links: &v6->m_links, layerApplicationMask: v15);
    idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)v6);
    return v16 - pInputBinaryImage;
  }
  else
  {
    v13 = "NavGraph version is out of date. AddResource aborted.\n";
    bfx::InternalWarning(
      fmt: *(__int64 *)&pInputBinaryImage,
      a2: offset,
      a3: a4,
      a4: (unsigned int)v11 - 1,
      a5: v24,
      a6: v25,
      a7: v26,
      a8: v27);
    return 0;
  }
}


// ========================================================================
// __unwind$55118
// EA  : 0x8327D768
// RVA : 0x0127D768
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_55118()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 208 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?GetClosestAreas@NavGraph@bfx@@QAAXABVVec3@2@AAV?$ClosestAreasProcessor@VPathSpec@bfx@@@2@@Z
// EA  : 0x8327DA08
// RVA : 0x0127DA08
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::NavGraph::GetClosestAreas(
        bfx::NavGraph *this,
        const bfx::Vec3 *pos,
        bfx::ClosestAreasProcessor<bfx::PathSpec> *closestAreasProcessor)
{
  int m_numDynAreas; // r8
  int v6; // r7
  int v7; // r6
  bfx::Array<bfx::Area *> *m_pArray; // r29
  int m_i; // r28
  int m_size; // r9
  bfx::Area *m_pCurDynArea; // r30
  bfx::ReplayListener *v12; // r11
  bfx::ReplayListener_vtbl *v13; // r10
  char *m_data; // r11
  int v15; // r11
  int v16; // [sp+8h] [-98h]
  int v17; // [sp+Ch] [-94h]
  int v18; // [sp+10h] [-90h]
  int v19; // [sp+14h] [-8Ch]
  int v20; // [sp+18h] [-88h]
  bfx::ReplayListener *v21; // [sp+1Ch] [-84h]
  bfx::ActiveAreasInArrayCursor v22[4]; // [sp+50h] [-50h] BYREF

  v22[0].m_staticCC.m_i = 0;
  v22[0].m_staticCC.m_pArray = &this->m_allocatedAreasOwned;
  bfx::KDTree::ProcessClosestPrims<bfx::ClosestAreasProcessor<bfx::PathSpec>>(
    this: &this->m_kdtree,
    posWCoord: pos,
    primProcessor: closestAreasProcessor);
  v22[0].m_dynCC.m_pCurDynArea = nullptr;
  v22[0].m_dynCC.m_numDynAreas = 0;
  v22[0].m_dynCC.m_i = 0;
  bfx::ActiveAreasInArrayCursor::InitDynCC(this: v22);
  m_pArray = v22[0].m_staticCC.m_pArray;
  m_i = v22[0].m_staticCC.m_i;
  m_size = v22[0].m_staticCC.m_pArray->m_size;
  if ( v22[0].m_staticCC.m_i < m_size )
  {
    m_pCurDynArea = v22[0].m_dynCC.m_pCurDynArea;
    do
    {
      v12 = (bfx::ReplayListener *)m_pArray->m_data[m_i];
      v13 = v12[1].__vftable;
      if ( v13 != nullptr )
      {
        v13 = (bfx::ReplayListener_vtbl *)v13->dtr_ReplayListener;
        if ( v13 != nullptr )
          v12 = (bfx::ReplayListener *)m_pCurDynArea;
      }
      bfx::ClosestAreasProcessor<bfx::PathSpec>::ProcessArea(
        this: closestAreasProcessor,
        pArea: v12,
        pos,
        a4: v7,
        a5: v6,
        a6: m_numDynAreas,
        a7: m_size,
        a8: (int)v13,
        a9: v16,
        a10: v17,
        a11: v18,
        a12: v19,
        a13: v20,
        a14: v21);
      m_data = m_pArray->m_data[m_i]->m_dynAreaData.m_data;
      if ( m_data != nullptr && *(_DWORD *)m_data != 0 )
      {
        m_numDynAreas = v22[0].m_dynCC.m_numDynAreas;
        m_size = v22[0].m_dynCC.m_i + 1;
        v15 = (m_pCurDynArea->m_flags.m_flags1 & 0x7F) + 3;
        v6 = 3 * v15;
        m_pCurDynArea = (bfx::Area *)((char *)m_pCurDynArea + 24 * v15);
        v22[0].m_dynCC.m_pCurDynArea = m_pCurDynArea;
        if ( ++v22[0].m_dynCC.m_i != v22[0].m_dynCC.m_numDynAreas )
          continue;
      }
      v22[0].m_staticCC.m_i = m_i + 1;
      bfx::ActiveAreasInArrayCursor::InitDynCC(this: v22);
      m_pArray = v22[0].m_staticCC.m_pArray;
      m_i = v22[0].m_staticCC.m_i;
      m_pCurDynArea = v22[0].m_dynCC.m_pCurDynArea;
    }
    while ( m_i < m_pArray->m_size );
  }
}


// ========================================================================
// ?GetClosestReachableAreas@NavGraph@bfx@@QAAXABVVec3@2@AAV?$ClosestAreasProcessor@VIncrementalIRT@bfx@@@2@@Z
// EA  : 0x8327DB28
// RVA : 0x0127DB28
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::NavGraph::GetClosestReachableAreas(
        bfx::NavGraph *this,
        const bfx::Vec3 *pos,
        bfx::ClosestAreasProcessor<bfx::IncrementalIRT> *closestAreasProcessor)
{
  int m_numDynAreas; // r8
  int v6; // r7
  int v7; // r6
  bfx::Array<bfx::Area *> *m_pArray; // r29
  int m_i; // r28
  int m_size; // r9
  bfx::Area *m_pCurDynArea; // r30
  bfx::ReplayListener *v12; // r11
  bfx::ReplayListener_vtbl *v13; // r10
  char *m_data; // r11
  int v15; // r11
  int v16; // [sp+8h] [-98h]
  int v17; // [sp+Ch] [-94h]
  int v18; // [sp+10h] [-90h]
  int v19; // [sp+14h] [-8Ch]
  int v20; // [sp+18h] [-88h]
  bfx::ReplayListener *v21; // [sp+1Ch] [-84h]
  bfx::ActiveAreasInArrayCursor v22[4]; // [sp+50h] [-50h] BYREF

  v22[0].m_staticCC.m_i = 0;
  v22[0].m_staticCC.m_pArray = &this->m_allocatedAreasOwned;
  bfx::KDTree::ProcessClosestPrims<bfx::ClosestAreasProcessor<bfx::IncrementalIRT>>(
    this: &this->m_kdtree,
    posWCoord: pos,
    primProcessor: closestAreasProcessor);
  v22[0].m_dynCC.m_pCurDynArea = nullptr;
  v22[0].m_dynCC.m_numDynAreas = 0;
  v22[0].m_dynCC.m_i = 0;
  bfx::ActiveAreasInArrayCursor::InitDynCC(this: v22);
  m_pArray = v22[0].m_staticCC.m_pArray;
  m_i = v22[0].m_staticCC.m_i;
  m_size = v22[0].m_staticCC.m_pArray->m_size;
  if ( v22[0].m_staticCC.m_i < m_size )
  {
    m_pCurDynArea = v22[0].m_dynCC.m_pCurDynArea;
    do
    {
      v12 = (bfx::ReplayListener *)m_pArray->m_data[m_i];
      v13 = v12[1].__vftable;
      if ( v13 != nullptr )
      {
        v13 = (bfx::ReplayListener_vtbl *)v13->dtr_ReplayListener;
        if ( v13 != nullptr )
          v12 = (bfx::ReplayListener *)m_pCurDynArea;
      }
      bfx::ClosestAreasProcessor<bfx::IncrementalIRT>::ProcessArea(
        this: closestAreasProcessor,
        pArea: v12,
        pos,
        a4: v7,
        a5: v6,
        a6: m_numDynAreas,
        a7: m_size,
        a8: (int)v13,
        a9: v16,
        a10: v17,
        a11: v18,
        a12: v19,
        a13: v20,
        a14: v21);
      m_data = m_pArray->m_data[m_i]->m_dynAreaData.m_data;
      if ( m_data != nullptr && *(_DWORD *)m_data != 0 )
      {
        m_numDynAreas = v22[0].m_dynCC.m_numDynAreas;
        m_size = v22[0].m_dynCC.m_i + 1;
        v15 = (m_pCurDynArea->m_flags.m_flags1 & 0x7F) + 3;
        v6 = 3 * v15;
        m_pCurDynArea = (bfx::Area *)((char *)m_pCurDynArea + 24 * v15);
        v22[0].m_dynCC.m_pCurDynArea = m_pCurDynArea;
        if ( ++v22[0].m_dynCC.m_i != v22[0].m_dynCC.m_numDynAreas )
          continue;
      }
      v22[0].m_staticCC.m_i = m_i + 1;
      bfx::ActiveAreasInArrayCursor::InitDynCC(this: v22);
      m_pArray = v22[0].m_staticCC.m_pArray;
      m_i = v22[0].m_staticCC.m_i;
      m_pCurDynArea = v22[0].m_dynCC.m_pCurDynArea;
    }
    while ( m_i < m_pArray->m_size );
  }
}


// ========================================================================
// ?GetClosestAreas@NavLayer@bfx@@QAAXABVVec3@2@ABVPathSpec@2@MHAAV?$Array@PAVArea@bfx@@@2@@Z
// EA  : 0x8327DC50
// RVA : 0x0127DC50
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::NavLayer::GetClosestAreas(
        bfx::NavLayer *this,
        const bfx::Vec3 *pos,
        const bfx::PathSpec *pathSpec,
        double radius,
        int maxNumAreas,
        bfx::Array<bfx::Area *> *areasOut,
        bfx::Array<bfx::Volume *> *a7)
{
  char v13; // r11
  bfx::NavGraph *v14; // r3
  bfx::ClosestAreasProcessor<bfx::PathSpec> v15; // [sp+50h] [-B0h] BYREF
  bfx::NavGraphSpatialOrganization::ClosestPrimsCursor v16; // [sp+80h] [-80h] BYREF

  v15.m_areaChecker = pathSpec;
  bfx::SmallestN<bfx::Area *>::SmallestN<bfx::Area *>(
    this: (bfx::SmallestN<bfx::Volume *> *)&v15.m_closestAreas,
    N: (int)areasOut);
  v15.m_pNavGraph = nullptr;
  _FP13 = (float)((float)radius - (float)9.2233715e18);
  __asm { fsel      f12, f13, f0, f31 }
  v15.m_considerationDist = _FP12;
  bfx::NavGraphSpatialOrganization::ClosestPrimsCursor::ClosestPrimsCursor(
    this: &v16,
    testPos: pos,
    spatialOrg: &this->m_navGraphSpatialOrg,
    considerationDist: radius);
  while ( 1 )
  {
    if ( !v16.m_kdtreeCC.m_atEnd || (v13 = 1, v16.m_linearCC.m_i < v16.m_linearCC.m_pArray->m_size) )
      v13 = 0;
    if ( v13 != 0 )
      break;
    if ( v16.m_kdtreeCC.m_atEnd )
      v14 = v16.m_linearCC.m_pArray->m_data[v16.m_linearCC.m_i];
    else
      v14 = (bfx::NavGraph *)bfx::DynKDTree::ClosestPrimsCursor::operator*(this: &v16.m_kdtreeCC);
    v15.m_pNavGraph = v14;
    bfx::NavGraph::GetClosestAreas(this: v14, pos, closestAreasProcessor: &v15);
    v16.m_considerationDist = v15.m_considerationDist;
    v16.m_kdtreeCC.m_considerationDist = v15.m_considerationDist;
    if ( v16.m_kdtreeCC.m_atEnd )
    {
      ++v16.m_linearCC.m_i;
      bfx::NavGraphSpatialOrganization::ClosestPrimsCursor::AdvancedLinearCCToFirstNavGraphWithinConsiderationDistance(this: &v16);
    }
    else
    {
      bfx::DynKDTree::ClosestPrimsCursor::TraverseToNextLeaf(this: &v16.m_kdtreeCC);
      if ( v16.m_kdtreeCC.m_atEnd )
        bfx::NavGraphSpatialOrganization::ClosestPrimsCursor::AdvancedLinearCCToFirstNavGraphWithinConsiderationDistance(this: &v16);
    }
  }
  v16.m_kdtreeCC.m_closestNodesList.m_data.m_size = 0;
  if ( v16.m_kdtreeCC.m_closestNodesList.m_data.m_data != nullptr )
  {
    bfx::MemoryManager::Free(
      this: bfx::g_pCurInstance->m_pMemoryManager,
      ptr: (char *)v16.m_kdtreeCC.m_closestNodesList.m_data.m_data);
    v16.m_kdtreeCC.m_closestNodesList.m_data.m_data = nullptr;
  }
  v16.m_kdtreeCC.m_closestNodesList.m_data.m_cap = 0;
  bfx::SmallestN<bfx::Area *>::GetData(this: (bfx::SmallestN<bfx::Volume *> *)&v15.m_closestAreas, dataOut: a7);
  v15.m_closestAreas.m_data.m_size = 0;
  if ( v15.m_closestAreas.m_data.m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v15.m_closestAreas.m_data.m_data);
}


// ========================================================================
// __unwind$55729
// EA  : 0x8327DDC4
// RVA : 0x0127DDC4
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_55729()
{
  int v0; // r12

  bfx::ClosestAreasProcessor<bfx::IncrementalIRT>::~ClosestAreasProcessor<bfx::IncrementalIRT>(this: (bfx::ClosestVolumesProcessor<bfx::Path3DSpec> *)(v0 - 256 + 80));
}


// ========================================================================
// __unwind$55730
// EA  : 0x8327DDEC
// RVA : 0x0127DDEC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_55730()
{
  int v0; // r12

  bfx::NavGraphSpatialOrganization::ClosestPrimsCursor::~ClosestPrimsCursor(this: (bfx::NavGraphSpatialOrganization::ClosestPrimsCursor *)(v0 - 256 + 128));
}


// ========================================================================
// ?GetClosestReachableAreas@NavLayer@bfx@@QAAXABVVec3@2@PAVArea@2@ABVPathSpec@2@MHAAV?$Array@PAVArea@bfx@@@2@@Z
// EA  : 0x8327DE20
// RVA : 0x0127DE20
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall bfx::NavLayer::GetClosestReachableAreas(
        bfx::NavLayer *this,
        bfx::IslandGraph *pos,
        __int64 pathSpec,
        double radius,
        __int64 areasOut,
        __int64 a6)
{
  const bfx::Vec3 *v6; // r27
  int v7; // r3
  int v8; // r30
  int v10; // r29
  bfx::Array<bfx::Volume *> *v11; // r26
  const char *v12; // r3
  int v13; // r5
  char v14; // r11
  bfx::NavGraph *v15; // r3
  int v16; // [sp+8h] [-108h]
  int v17; // [sp+Ch] [-104h]
  int v18; // [sp+10h] [-100h]
  int v19; // [sp+14h] [-FCh]
  bfx::IncrementalIRT v20; // [sp+50h] [-C0h] BYREF
  bfx::ClosestAreasProcessor<bfx::IncrementalIRT> v21; // [sp+60h] [-B0h] BYREF
  bfx::NavGraphSpatialOrganization::ClosestPrimsCursor v22; // [sp+90h] [-80h] BYREF

  v6 = (const bfx::Vec3 *)pos;
  pos = *(bfx::IslandGraph **)(v7 + 20);
  v8 = v7;
  v10 = areasOut;
  v11 = (bfx::Array<bfx::Volume *> *)HIDWORD(a6);
  if ( pos != nullptr )
  {
    HIDWORD(pathSpec) = (*(_DWORD *)(HIDWORD(pathSpec) + 40) >> 7) & 0x1FFFF;
    LODWORD(a6) = 0x1FFFF;
    if ( SHIDWORD(pathSpec) < 0x1FFFF )
    {
      bfx::IncrementalIRT::IncrementalIRT(
        this: &v20,
        pIslandGraph: pos,
        startingIslandNum: SHIDWORD(pathSpec),
        (const bfx::PathSpec *)pathSpec);
      bfx::ClosestAreasProcessor<bfx::IncrementalIRT>::ClosestAreasProcessor<bfx::IncrementalIRT>(
        this: &v21,
        areaChecker: &v20,
        initialRadius: radius,
        N: v13,
        a5: v10);
      bfx::NavGraphSpatialOrganization::ClosestPrimsCursor::ClosestPrimsCursor(
        this: &v22,
        testPos: v6,
        spatialOrg: (bfx::NavGraphSpatialOrganization *)(v8 + 8228),
        considerationDist: radius);
      while ( 1 )
      {
        if ( !v22.m_kdtreeCC.m_atEnd || (v14 = 1, v22.m_linearCC.m_i < v22.m_linearCC.m_pArray->m_size) )
          v14 = 0;
        if ( v14 != 0 )
          break;
        if ( v22.m_kdtreeCC.m_atEnd )
          v15 = v22.m_linearCC.m_pArray->m_data[v22.m_linearCC.m_i];
        else
          v15 = (bfx::NavGraph *)bfx::DynKDTree::ClosestPrimsCursor::operator*(this: &v22.m_kdtreeCC);
        v21.m_pNavGraph = v15;
        bfx::NavGraph::GetClosestReachableAreas(this: v15, pos: v6, closestAreasProcessor: &v21);
        v22.m_considerationDist = v21.m_considerationDist;
        v22.m_kdtreeCC.m_considerationDist = v21.m_considerationDist;
        if ( v22.m_kdtreeCC.m_atEnd )
        {
          ++v22.m_linearCC.m_i;
          bfx::NavGraphSpatialOrganization::ClosestPrimsCursor::AdvancedLinearCCToFirstNavGraphWithinConsiderationDistance(this: &v22);
        }
        else
        {
          bfx::DynKDTree::ClosestPrimsCursor::TraverseToNextLeaf(this: &v22.m_kdtreeCC);
          if ( v22.m_kdtreeCC.m_atEnd )
            bfx::NavGraphSpatialOrganization::ClosestPrimsCursor::AdvancedLinearCCToFirstNavGraphWithinConsiderationDistance(this: &v22);
        }
      }
      v22.m_kdtreeCC.m_closestNodesList.m_data.m_size = 0;
      if ( v22.m_kdtreeCC.m_closestNodesList.m_data.m_data != nullptr )
      {
        bfx::MemoryManager::Free(
          this: bfx::g_pCurInstance->m_pMemoryManager,
          ptr: (char *)v22.m_kdtreeCC.m_closestNodesList.m_data.m_data);
        v22.m_kdtreeCC.m_closestNodesList.m_data.m_data = nullptr;
      }
      v22.m_kdtreeCC.m_closestNodesList.m_data.m_cap = 0;
      bfx::SmallestN<bfx::Area *>::GetData(this: (bfx::SmallestN<bfx::Volume *> *)&v21.m_closestAreas, dataOut: v11);
      v21.m_closestAreas.m_data.m_size = 0;
      if ( v21.m_closestAreas.m_data.m_data != nullptr )
      {
        bfx::MemoryManager::Free(
          this: bfx::g_pCurInstance->m_pMemoryManager,
          ptr: (char *)v21.m_closestAreas.m_data.m_data);
        v21.m_closestAreas.m_data.m_data = nullptr;
      }
      v21.m_closestAreas.m_data.m_cap = 0;
      bfx::IncrementalIRT::~IncrementalIRT(this: &v20);
    }
    else
    {
      v12 = "Unexpected error in GetClosestReachableAreas(). Please report.\n";
      bfx::InternalWarning(
        fmt: *(__int64 *)&pos,
        a2: pathSpec,
        a3: areasOut,
        a4: a6,
        a5: v16,
        a6: v17,
        a7: v18,
        a8: v19);
    }
  }
}


// ========================================================================
// __unwind$55976
// EA  : 0x8327DFEC
// RVA : 0x0127DFEC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_55976()
{
  int v0; // r12

  bfx::IncrementalIRT::~IncrementalIRT(this: (bfx::IncrementalIRT *)(v0 - 272 + 80));
}


// ========================================================================
// __unwind$55977
// EA  : 0x8327E014
// RVA : 0x0127E014
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_55977()
{
  int v0; // r12

  bfx::ClosestAreasProcessor<bfx::IncrementalIRT>::~ClosestAreasProcessor<bfx::IncrementalIRT>(this: (bfx::ClosestVolumesProcessor<bfx::Path3DSpec> *)(v0 - 272 + 96));
}


// ========================================================================
// __unwind$55978
// EA  : 0x8327E03C
// RVA : 0x0127E03C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_55978()
{
  int v0; // r12

  bfx::NavGraphSpatialOrganization::ClosestPrimsCursor::~ClosestPrimsCursor(this: (bfx::NavGraphSpatialOrganization::ClosestPrimsCursor *)(v0 - 272 + 144));
}


// ========================================================================
// ?GetClosestReachableArea@NavLayer@bfx@@QAAPAVArea@2@ABVVec3@2@PAV32@ABVPathSpec@2@@Z
// EA  : 0x8327E070
// RVA : 0x0127E070
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

bfx::Area *__fastcall bfx::NavLayer::GetClosestReachableArea(
        bfx::NavLayer *this,
        bfx::IslandGraph *pos,
        __int64 pathSpec,
        __int64 a4)
{
  int v4; // r30
  __int64 v5; // r10
  char *v7; // [sp+50h] [-30h] BYREF
  int v8; // [sp+54h] [-2Ch]
  int v9; // [sp+58h] [-28h]
  bfx::bfxMemTag v10; // [sp+5Ch] [-24h]

  v4 = 0;
  v7 = nullptr;
  v8 = 0;
  v9 = 0;
  v10 = bfx::MEM_BFXPLANNER;
  LODWORD(v5) = &unk_82410000;
  HIDWORD(v5) = &v7;
  LODWORD(a4) = 1;
  bfx::NavLayer::GetClosestReachableAreas(this, pos, pathSpec, radius: 3.4028235e38, areasOut: a4, a6: v5);
  if ( v8 != 0 )
    v4 = *(_DWORD *)v7;
  if ( v7 != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v7);
  return (bfx::Area *)v4;
}


// ========================================================================
// __unwind$56238
// EA  : 0x8327E100
// RVA : 0x0127E100
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_56238()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 128 + 80));
}


// ========================================================================
// ?GetClosestReachableArea@Planner@bfx@@QAAPAVArea@2@ABVVec3@2@PAV32@ABVPathSpec@2@@Z
// EA  : 0x8327E128
// RVA : 0x0127E128
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

bfx::Area *__fastcall bfx::Planner::GetClosestReachableArea(
        bfx::Planner *this,
        bfx::IslandGraph *pos,
        __int64 pathSpec,
        __int64 a4)
{
  bfx::NavLayer *v4; // r3

  if ( HIDWORD(pathSpec) != 0 && (v4 = this->m_layers[*(_DWORD *)(HIDWORD(pathSpec) + 52) >> 27]) != nullptr )
    return bfx::NavLayer::GetClosestReachableArea(this: v4, pos, pathSpec, a4);
  else
    return nullptr;
}


// ========================================================================
// ?GetClosestAreas@Planner@bfx@@QAAXABVVec3@2@IABVPathSpec@2@MHAAV?$Array@PAVArea@bfx@@@2@@Z
// EA  : 0x8327E160
// RVA : 0x0127E160
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::Planner::GetClosestAreas(
        bfx::Planner *this,
        const bfx::Vec3 *pos,
        unsigned int layerNum,
        const bfx::PathSpec *pathSpec,
        double radius,
        int maxNumAreas,
        bfx::Array<bfx::Area *> *areasOut,
        bfx::Array<bfx::Volume *> *a8)
{
  bfx::NavLayer *v8; // r3

  if ( layerNum < 0x20 )
  {
    v8 = this->m_layers[layerNum];
    if ( v8 != nullptr )
      bfx::NavLayer::GetClosestAreas(this: v8, pos, pathSpec, radius, maxNumAreas: (int)pathSpec, areasOut, a7: a8);
  }
}


// ========================================================================
// ?GetClosestReachableAreas@Planner@bfx@@QAAXABVVec3@2@PAVArea@2@ABVPathSpec@2@MHAAV?$Array@PAVArea@bfx@@@2@@Z
// EA  : 0x8327E198
// RVA : 0x0127E198
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::Planner::GetClosestReachableAreas(
        bfx::Planner *this,
        bfx::IslandGraph *pos,
        __int64 pathSpec,
        double radius,
        __int64 areasOut,
        __int64 a6)
{
  bfx::NavLayer *v6; // r3

  LODWORD(a6) = 4 * ((*(_DWORD *)(HIDWORD(pathSpec) + 52) >> 27) + 2);
  v6 = *(bfx::NavLayer **)((char *)&this->__vftable + a6);
  if ( v6 != nullptr )
    bfx::NavLayer::GetClosestReachableAreas(this: v6, pos, pathSpec, radius, areasOut, a6);
}


// ========================================================================
// ?GetClosestArea@NavLayer@bfx@@QAAPAVArea@2@ABVVec3@2@ABVPathSpec@2@M@Z
// EA  : 0x8327E1D0
// RVA : 0x0127E1D0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

bfx::Volume *__fastcall bfx::NavLayer::GetClosestArea(
        bfx::NavLayer *this,
        const bfx::Vec3 *pos,
        const bfx::PathSpec *pathSpec,
        double radius,
        int a5)
{
  bfx::Volume *v5; // r30
  bfx::Array<bfx::Volume *> v7; // [sp+50h] [-30h] BYREF

  v5 = nullptr;
  memset(&v7, 0, 12);
  v7.m_tag = bfx::MEM_BFXPLANNER;
  bfx::NavLayer::GetClosestAreas(
    this,
    pos,
    pathSpec,
    radius,
    maxNumAreas: a5,
    areasOut: (bfx::Array<bfx::Area *> *)1,
    a7: &v7);
  if ( v7.m_size != 0 )
    v5 = *v7.m_data;
  if ( v7.m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v7.m_data);
  return v5;
}


// ========================================================================
// __unwind$56310
// EA  : 0x8327E258
// RVA : 0x0127E258
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void _unwind_56310()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 128 + 80));
}


// ========================================================================
// ?GetClosestArea@Planner@bfx@@QAAPAVArea@2@ABVVec3@2@IABVPathSpec@2@@Z
// EA  : 0x8327E280
// RVA : 0x0127E280
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

bfx::Volume *__fastcall bfx::Planner::GetClosestArea(
        bfx::Planner *this,
        const bfx::Vec3 *pos,
        unsigned int layerNum,
        const bfx::PathSpec *pathSpec)
{
  bfx::NavLayer *v4; // r3

  if ( layerNum < 0x20 && (v4 = this->m_layers[layerNum]) != nullptr )
    return bfx::NavLayer::GetClosestArea(this: v4, pos, pathSpec, radius: 3.4028235e38, a5: (int)pathSpec);
  else
    return nullptr;
}


// ========================================================================
// bfx::`dynamic initializer for 'g_drawPlannerIslandsRestore''
// EA  : 0x83398928
// RVA : 0x01398928
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_drawPlannerIslandsRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_drawPlannerIslandsRestore);
  bfx::g_drawPlannerIslandsRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_drawPlannerIslandsRestore.m_targetBool = &bfx::g_drawPlannerIslands;
  bfx::g_drawPlannerIslandsRestore.m_name = "planner_islands";
  bfx::g_drawPlannerIslandsRestore.m_defaultBool = bfx::g_drawPlannerIslands;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_drawPlannerIslandsRestore__);
}


// ========================================================================
// bfx::`dynamic initializer for 'g_drawAreaUsageCountRestore''
// EA  : 0x833989A0
// RVA : 0x013989A0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_drawAreaUsageCountRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_drawAreaUsageCountRestore);
  bfx::g_drawAreaUsageCountRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_drawAreaUsageCountRestore.m_targetBool = &bfx::g_drawAreaUsageCount;
  bfx::g_drawAreaUsageCountRestore.m_name = "planner_refcount";
  bfx::g_drawAreaUsageCountRestore.m_defaultBool = bfx::g_drawAreaUsageCount;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_drawAreaUsageCountRestore__);
}


// ========================================================================
// bfx::`dynamic initializer for 'g_drawAreaObstacleListsRestore''
// EA  : 0x83398A18
// RVA : 0x01398A18
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_drawAreaObstacleListsRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_drawAreaObstacleListsRestore);
  bfx::g_drawAreaObstacleListsRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_drawAreaObstacleListsRestore.m_targetBool = &bfx::g_drawAreaObstacleLists;
  bfx::g_drawAreaObstacleListsRestore.m_name = "area_obstacle_lists";
  bfx::g_drawAreaObstacleListsRestore.m_defaultBool = bfx::g_drawAreaObstacleLists;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_drawAreaObstacleListsRestore__);
}


// ========================================================================
// bfx::`dynamic initializer for 'g_drawAreaPtrsRestore''
// EA  : 0x83398A90
// RVA : 0x01398A90
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_drawAreaPtrsRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_drawAreaPtrsRestore);
  bfx::g_drawAreaPtrsRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_drawAreaPtrsRestore.m_targetBool = &bfx::g_drawAreaPtrs;
  bfx::g_drawAreaPtrsRestore.m_name = "area_ptrs";
  bfx::g_drawAreaPtrsRestore.m_defaultBool = bfx::g_drawAreaPtrs;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_drawAreaPtrsRestore__);
}


// ========================================================================
// bfx::`dynamic initializer for 'g_drawIslandGraphRestore''
// EA  : 0x83398B08
// RVA : 0x01398B08
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_drawIslandGraphRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_drawIslandGraphRestore);
  bfx::g_drawIslandGraphRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_drawIslandGraphRestore.m_targetBool = &bfx::g_drawIslandGraph;
  bfx::g_drawIslandGraphRestore.m_name = "island_graph";
  bfx::g_drawIslandGraphRestore.m_defaultBool = bfx::g_drawIslandGraph;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_drawIslandGraphRestore__);
}


// ========================================================================
// bfx::`dynamic initializer for 'g_drawIslandStatsRestore''
// EA  : 0x83398B80
// RVA : 0x01398B80
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_drawIslandStatsRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_drawIslandStatsRestore);
  bfx::g_drawIslandStatsRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_drawIslandStatsRestore.m_targetBool = &bfx::g_drawIslandStats;
  bfx::g_drawIslandStatsRestore.m_name = "island_stats";
  bfx::g_drawIslandStatsRestore.m_defaultBool = bfx::g_drawIslandStats;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_drawIslandStatsRestore__);
}


// ========================================================================
// bfx::`dynamic initializer for 'g_drawXGraphRestore''
// EA  : 0x83398BF8
// RVA : 0x01398BF8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __noreturn bfx::_dynamic_initializer_for__g_drawXGraphRestore__()
{
  bfx::Setting::Setting(this: &bfx::g_drawXGraphRestore);
  bfx::g_drawXGraphRestore.__vftable = (bfx::BoolSetting_vtbl *)&bfx::BoolSetting::`vftable';
  bfx::g_drawXGraphRestore.m_targetBool = &bfx::g_drawXGraph;
  bfx::g_drawXGraphRestore.m_name = "xgraph";
  bfx::g_drawXGraphRestore.m_defaultBool = bfx::g_drawXGraph;
  atexit(func: (void (__fastcall *)())bfx::_dynamic_atexit_destructor_for__g_drawXGraphRestore__);
}


// ========================================================================
// bfx::`dynamic initializer for 'ANGLE_BETWEEN_NORMALS_THRESHOLD''
// EA  : 0x83398C70
// RVA : 0x01398C70
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::_dynamic_initializer_for__ANGLE_BETWEEN_NORMALS_THRESHOLD__(long double a1)
{
  *(_QWORD *)&a1 = 0x3FFEB7C175555556LL;
  ANGLE_BETWEEN_NORMALS_THRESHOLD = cos(x: a1);
}


// ========================================================================
// bfx::`dynamic initializer for 'MAX_PORTAL_CONNECTION_DIVERGENCE_ANGLE''
// EA  : 0x83398CA8
// RVA : 0x01398CA8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::_dynamic_initializer_for__MAX_PORTAL_CONNECTION_DIVERGENCE_ANGLE__(long double a1)
{
  *(_QWORD *)&a1 = 0x3FE921FB60000000LL;
  MAX_PORTAL_CONNECTION_DIVERGENCE_ANGLE = cos(x: a1);
}


// ========================================================================
// bfx::`dynamic initializer for 'COS_CONNECT_THRESHOLD''
// EA  : 0x83398CE0
// RVA : 0x01398CE0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::_dynamic_initializer_for__COS_CONNECT_THRESHOLD__(long double a1)
{
  *(_QWORD *)&a1 = 0x3FF4F1A6D0000000LL;
  COS_CONNECT_THRESHOLD = (float)cos(x: a1) * (float)-1.0;
}


// ========================================================================
// bfx::`dynamic initializer for 'TAN_THRESHOLD_MULT''
// EA  : 0x83398D20
// RVA : 0x01398D20
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxnavgraph.cpp
// ========================================================================

void __fastcall bfx::_dynamic_initializer_for__TAN_THRESHOLD_MULT__(long double a1)
{
  *(_QWORD *)&a1 = 0x3FF38C354AAAAAABLL;
  TAN_THRESHOLD_MULT = tan(x: a1);
}

