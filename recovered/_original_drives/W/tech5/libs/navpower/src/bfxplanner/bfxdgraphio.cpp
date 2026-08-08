
// ========================================================================
// ?IsInsideObstacleJustAdded@DFace@bfx@@QBA_NXZ
// EA  : 0x832C1D28
// RVA : 0x012C1D28
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraphio.cpp
// ========================================================================

int __fastcall bfx::DFace::IsInsideObstacleJustAdded(bfx::DFace *this)
{
  bfx::DEdge *m_pOuterEdge; // r11

  m_pOuterEdge = this->m_pOuterEdge;
  while ( *((int *)m_pOuterEdge->m_pStartVert + 6) >= 0 )
  {
    m_pOuterEdge = m_pOuterEdge->m_pNext;
    if ( m_pOuterEdge == this->m_pOuterEdge )
      return 1;
  }
  return 0;
}


// ========================================================================
// ?ConnectUpOutputEdges@bfx@@YAXPAVListNode@1@@Z
// EA  : 0x832C1D60
// RVA : 0x012C1D60
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraphio.cpp
// ========================================================================

void __fastcall bfx::ConnectUpOutputEdges(bfx::ListNode *pHeadEdgeNode)
{
  double Scale; // fp1
  __int64 v3; // r11
  bool i; // r4
  _DWORD *v5; // r9
  int v6; // r11
  int v7; // r6
  int v8; // r5
  double v9; // fp9
  int v10; // r9
  __int64 v11; // r9
  int v12; // r11
  _DWORD *v13; // r7
  int v14; // r11
  double v15; // fp2
  double v16; // fp10
  int v17; // r6
  float v18; // [sp+8Ch] [-34h]

  Scale = bfx::GetScale();
  HIDWORD(v3) = pHeadEdgeNode;
  for ( i = (_cntlzw(HIBYTE(bfx::g_pCurInstance->m_pComponentManager->m_components[1][5].__vftable)) & 0x20) != 0;
        HIDWORD(v3) != 0;
        HIDWORD(v3) = *(_DWORD *)HIDWORD(v3) )
  {
    v5 = *(_DWORD **)(HIDWORD(v3) + 64);
    if ( v5 != nullptr )
    {
      v6 = *(_DWORD *)(*(_DWORD *)(HIDWORD(v3) + 12) + 16);
      if ( v6 != 0 )
      {
        *v5 = *(_DWORD *)(v6 + 28);
        if ( i )
        {
          v7 = *(_DWORD *)(*(_DWORD *)(HIDWORD(v3) + 16) + 28);
          v8 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(HIDWORD(v3) + 12) + 16) + 28);
          v9 = (float)(*(float *)(v7 + 16) - *(float *)(v8 + 16));
          LODWORD(v3) = ((*(_DWORD *)(v8 + 44) >> 20) & 0xF) + ((*(_DWORD *)(v7 + 44) >> 20) & 0xF);
          v10 = (__int64)(float)((float)((float)((float)((float)__fsqrts((float)((float)((float)v9 * (float)v9)
                                                                               + (float)((float)((float)(*(float *)(v7 + 24) - *(float *)(v8 + 24))
                                                                                               * (float)(*(float *)(v7 + 24) - *(float *)(v8 + 24)))
                                                                                       + (float)((float)(*(float *)(v7 + 20) - *(float *)(v8 + 20))
                                                                                               * (float)(*(float *)(v7 + 20) - *(float *)(v8 + 20))))))
                                                       * (float)v3)
                                               * (float)((float)1000.0 / (float)Scale))
                                       * (float)0.5)
                               + (float)1.0);
          *(_DWORD *)(*(_DWORD *)(HIDWORD(v3) + 64) + 20) = v10;
          *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(HIDWORD(v3) + 12) + 64) + 20) = v10;
        }
      }
    }
    LODWORD(v11) = *(_DWORD *)(HIDWORD(v3) + 48);
    if ( (_DWORD)v11 != 0 )
    {
      HIDWORD(v11) = 24 * *(_DWORD *)(HIDWORD(v3) + 52) + v11 + 56;
      v12 = *(_DWORD *)(HIDWORD(v3) + 12);
      v13 = *(_DWORD **)(v12 + 64);
      v14 = *(_DWORD *)(*(_DWORD *)(v12 + 16) + 28);
      *(_DWORD *)HIDWORD(v11) = v14;
      *v13 = v11;
      if ( i )
      {
        v18 = *(float *)(v11 + 20);
        v15 = (float)(*(float *)(v14 + 24) - *(float *)(v11 + 24));
        v16 = (float)(*(float *)(v14 + 16) - *(float *)(v11 + 16));
        LODWORD(v11) = ((*(_DWORD *)(v11 + 44) >> 20) & 0xF) + ((*(_DWORD *)(v14 + 44) >> 20) & 0xF);
        v17 = (__int64)(float)((float)((float)((float)((float)__fsqrts((float)((float)((float)v16 * (float)v16)
                                                                             + (float)((float)((float)v15 * (float)v15)
                                                                                     + (float)((float)(*(float *)(v14 + 20) - v18)
                                                                                             * (float)(*(float *)(v14 + 20) - v18)))))
                                                     * (float)v11)
                                             * (float)((float)1000.0 / (float)Scale))
                                     * (float)0.5)
                             + (float)1.0);
        *(_DWORD *)(HIDWORD(v11) + 20) = v17;
        v13[5] = v17;
      }
    }
  }
}


// ========================================================================
// ?SplitConvexFaceIfNeededToEnforceMaxEdgeCount@DGraph@bfx@@AAAPAVDFace@2@PAV32@@Z
// EA  : 0x832C1FF0
// RVA : 0x012C1FF0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraphio.cpp
// ========================================================================

bfx::DFace *__fastcall bfx::DGraph::SplitConvexFaceIfNeededToEnforceMaxEdgeCount(bfx::DGraph *this, bfx::DFace *pFace)
{
  bfx::DEdge *m_pOuterEdge; // r4
  int v3; // r11
  bfx::DEdge *v4; // r10
  int v5; // r10
  bfx::DEdge *v6; // r11
  int v7; // r9
  bfx::DFace *result; // r3
  bfx::DEdge *v9; // [sp+50h] [-10h] BYREF
  bfx::DEdge *v10; // [sp+54h] [-Ch] BYREF

  m_pOuterEdge = pFace->m_pOuterEdge;
  v3 = 0;
  v4 = m_pOuterEdge;
  do
  {
    v4 = v4->m_pNext;
    ++v3;
  }
  while ( v4 != m_pOuterEdge );
  if ( v3 <= 127 )
    return nullptr;
  v5 = 0;
  v7 = v3 / 2;
  v6 = m_pOuterEdge;
  while ( v5 < v7 )
  {
    v6 = v6->m_pNext;
    ++v5;
    if ( v6 == m_pOuterEdge )
    {
      v6 = nullptr;
      break;
    }
  }
  result = bfx::DGraph::SplitFace(this, pEdgeA: m_pOuterEdge, pEdgeB: v6, pNewEdgeToA: &v10, pNewEdgeToB: &v9);
  if ( result == nullptr )
    return nullptr;
  return result;
}


// ========================================================================
// ?RemoveObstacle@DGraph@bfx@@QAA?AW4DResult@2@H@Z
// EA  : 0x832C2078
// RVA : 0x012C2078
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraphio.cpp
// ========================================================================

bfx::DResult __fastcall bfx::DGraph::RemoveObstacle(bfx::DGraph *this, int obID)
{
  bfx::CoreRemoveObstacleData v3; // [sp+50h] [-10h] BYREF

  v3.m_obID = obID;
  return bfx::DGraph::CoreRemoveObstacle(this, coreRemoveObstacleData: &v3);
}


// ========================================================================
// ??0CoreAddObstacleData@bfx@@QAA@PAVObstacleImpl@1@M@Z
// EA  : 0x832C20A0
// RVA : 0x012C20A0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraphio.cpp
// ========================================================================

bfx::CoreAddObstacleData *__fastcall bfx::CoreAddObstacleData::CoreAddObstacleData(
        bfx::CoreAddObstacleData *this,
        bfx::Sphere *pObstacle,
        double expandRadius)
{
  bfx::FArray<bfx::Plane,12> *p_m_clipPlanes; // r31
  double DefaultMinEdgeLength; // fp30
  double MinEdgeLengthBasedOnDistanceFromOrigin; // fp1
  int v11; // r8
  int v12; // r9
  _DWORD *v13; // r10
  _DWORD *p_m_x; // r11
  bool v15; // cr56
  int v17; // [sp+50h] [-50h] BYREF
  _DWORD v18[3]; // [sp+54h] [-4Ch] BYREF
  float v19; // [sp+60h] [-40h] BYREF
  float v20; // [sp+64h] [-3Ch]
  float v21; // [sp+68h] [-38h]

  this->m_clipPlanes.m_size = 0;
  p_m_clipPlanes = &this->m_clipPlanes;
  this->m_obID = LODWORD(pObstacle->m_radius);
  DefaultMinEdgeLength = bfx::GetDefaultMinEdgeLength();
  (*(void (__fastcall **)(float *, bfx::Sphere *))(LODWORD(pObstacle->m_pos.m_x) + 4))(a1: &v19, a2: pObstacle);
  MinEdgeLengthBasedOnDistanceFromOrigin = bfx::GetMinEdgeLengthBasedOnDistanceFromOrigin(distFromOrigin: __fsqrts((float)((float)(v19 * v19) + (float)((float)(v20 * v20) + (float)(v21 * v21)))));
  this->m_expandRadius = expandRadius;
  _FP9 = (float)((float)DefaultMinEdgeLength - (float)MinEdgeLengthBasedOnDistanceFromOrigin);
  __asm { fsel      f8, f9, f30, f1 }
  this->m_minEdgeLength = _FP8;
  (*(void (__fastcall **)(bfx::Sphere *, _DWORD *, int *))(LODWORD(pObstacle->m_pos.m_x) + 20))(
    a1: pObstacle,
    a2: v18,
    a3: &v17);
  v11 = 0;
  if ( v17 > 0 )
  {
    v12 = 0;
    do
    {
      v13 = (_DWORD *)(v12 + v18[0]);
      p_m_x = (_DWORD *)&p_m_clipPlanes->m_data[p_m_clipPlanes->m_size].m_normal.m_x;
      if ( p_m_x != nullptr )
      {
        *p_m_x = *v13;
        p_m_x[1] = v13[1];
        p_m_x[2] = v13[2];
        p_m_x[3] = v13[3];
      }
      ++v11;
      v12 += 16;
      v15 = v11 < v17;
      ++p_m_clipPlanes->m_size;
    }
    while ( v15 );
  }
  return this;
}


// ========================================================================
// ?CalcCentroidAndRadiusAndBasisVert@DFace@bfx@@QAAXAAVVec3@2@AAMAAH@Z
// EA  : 0x832C21C0
// RVA : 0x012C21C0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraphio.cpp
// ========================================================================

void __fastcall bfx::DFace::CalcCentroidAndRadiusAndBasisVert(
        bfx::DFace *this,
        bfx::Vec3 *centroidOut,
        float *radiusOut,
        int *basisVertOut)
{
  bfx::DEdge *m_pOuterEdge; // r8
  float *v5; // r10
  int v9; // r31
  bfx::DEdge *v10; // r11
  float *m_pStartVert; // r9
  bfx::Vec3 v12; // [sp+50h] [-630h] BYREF
  char v13; // [sp+5Ch] [-624h] BYREF
  bfx::Vec3 v14[130]; // [sp+60h] [-620h] BYREF

  m_pOuterEdge = this->m_pOuterEdge;
  v5 = (float *)&v13;
  v9 = 0;
  v10 = m_pOuterEdge;
  do
  {
    m_pStartVert = (float *)v10->m_pStartVert;
    ++v9;
    v10 = v10->m_pNext;
    v5[1] = m_pStartVert[2];
    v5[2] = m_pStartVert[3];
    v5 += 3;
    *v5 = m_pStartVert[4];
  }
  while ( v10 != m_pOuterEdge );
  *centroidOut = *bfx::CalcCentroidOfConvexPolygon(result: &v12, vertArray: v14, numVerts: v9);
  *radiusOut = bfx::CalcRadiusOfPolygon(vertArray: v14, numVerts: v9, centerPos: centroidOut);
  *basisVertOut = bfx::CalcBasisVert(vertArray: v14, numVerts: v9);
}


// ========================================================================
// ?AddTwinsForExternalEdges@DGraph@bfx@@AAAXAAV?$Array@PAVDEdge@bfx@@@2@@Z
// EA  : 0x832C2270
// RVA : 0x012C2270
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraphio.cpp
// ========================================================================

void __fastcall bfx::DGraph::AddTwinsForExternalEdges(bfx::DGraph *this, bfx::Array<bfx::SpaceComponent *> *edges)
{
  bfx::ListNode *i; // r26
  bfx::ListNode *m_pNextListNode; // r27
  bfx::ListNode *v6; // r30
  bfx::ListNode *j; // r11
  bfx::DEdge *v8; // r28
  bfx::DEdge *Edge; // r3
  int m_cap; // r10
  int m_size; // r11
  bfx::DEdge *v12; // r31
  int v13; // r4
  bfx::DEdge **v14; // r11
  bool v15; // cr34
  bfx::Area *v16; // r4
  bfx::ListNode *m_pPrevListNode; // r10
  bfx::ListNode *k; // r11
  bfx::ListNode *v19; // r11
  bfx::ListNode *v20; // r10
  bfx::ListNode v21; // [sp+50h] [-50h] BYREF

  for ( i = this->m_pHeadEdgeNode; i != nullptr; i = i->m_pNextListNode )
  {
    if ( i[1].m_pPrevListNode == nullptr )
    {
      m_pNextListNode = i[3].m_pNextListNode;
      v6 = i;
      for ( j = m_pNextListNode[1].m_pPrevListNode; j != nullptr; j = m_pNextListNode[1].m_pPrevListNode )
        m_pNextListNode = j[3].m_pNextListNode;
      v8 = nullptr;
      while ( 1 )
      {
        Edge = bfx::DGraph::CreateEdge(this);
        m_cap = edges->m_cap;
        m_size = edges->m_size;
        v12 = Edge;
        if ( m_cap == m_size )
        {
          v13 = 2 * m_cap;
          if ( m_cap == 0 )
            v13 = 1;
          bfx::Array<bfx::Edge *>::expand_cap(this: edges, size: v13);
          v14 = (bfx::DEdge **)&edges->m_data[edges->m_size];
          v15 = v14 == nullptr;
        }
        else
        {
          v14 = (bfx::DEdge **)&edges->m_data[m_size];
          v15 = v14 == nullptr;
        }
        if ( !v15 )
          *v14 = v12;
        ++edges->m_size;
        v12->m_pStartVert = (bfx::DVert *)v6[2].m_pPrevListNode[1].m_pNextListNode;
        v12->m_pTwin = (bfx::DEdge *)v6;
        v6[1].m_pPrevListNode = v12;
        v12->m_pNext = v8;
        if ( v8 != nullptr )
          v8->m_pPrev = v12;
        v12->m_pSrcStaticArea = nullptr;
        v12->m_inputEdgeType = (bfx::EdgeType)v6[7].m_pPrevListNode;
        *((_DWORD *)v12 + 18) = (int)v6[9].m_pNextListNode & 0x400 | *((_DWORD *)v12 + 18) & 0xFF1FF | 0x800;
        v16 = (bfx::Area *)v6[5].m_pPrevListNode->m_pNextListNode;
        if ( v16 != nullptr )
        {
          bfx::GetSharedEdgeCC(result: (bfx::EdgeCursor *)&v21, pArea0: v16, pArea1: (bfx::Area *)v6[7].m_pNextListNode);
          v6[1].m_pPrevListNode[6] = v21;
        }
        if ( v6 == m_pNextListNode )
          break;
        m_pPrevListNode = v6[2].m_pPrevListNode;
        v8 = v12;
        for ( k = m_pPrevListNode[1].m_pPrevListNode; k != nullptr; k = m_pPrevListNode[1].m_pPrevListNode )
          m_pPrevListNode = k[2].m_pPrevListNode;
        v6 = m_pPrevListNode;
      }
      v19 = i[1].m_pPrevListNode;
      v20 = m_pNextListNode[1].m_pPrevListNode;
      v19[2].m_pPrevListNode = v20;
      v20[3].m_pNextListNode = v19;
    }
  }
}


// ========================================================================
// ?AddEdgesForArea@DGraph@bfx@@AAAXPAVArea@2@0ABVVec3@2@PAV?$Array@PAVObstacleImpl@bfx@@@2@HAAV?$Array@PAVDEdge@bfx@@@2@AAV?$Array@PAVEdge@bfx@@@2@@Z
// EA  : 0x832C2400
// RVA : 0x012C2400
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraphio.cpp
// ========================================================================

void __fastcall bfx::DGraph::AddEdgesForArea(
        bfx::DGraph *this,
        bfx::Area *pArea,
        bfx::Area *pStaticArea,
        const bfx::Vec3 *staticAreaNormal,
        bfx::Array<bfx::ObstacleImpl *> *pObstacles,
        int curSearchIndex,
        bfx::Array<bfx::Space *> *edges,
        bfx::Array<bfx::Space *> *edgesModified)
{
  int v8; // r11
  int m_size; // r21
  bfx::Area *m_pArea; // r9
  char *v19; // r30
  bfx::Space *v20; // r31
  int v21; // r19
  double m_y; // fp13
  int v23; // r4
  int v24; // r10
  int v25; // r11
  int v26; // r11
  bfx::DEdge *v27; // r8
  int v28; // r11
  signed int v29; // r10
  int v30; // r9
  unsigned int v31; // ctr
  bfx::DEdge **m_data; // r6
  bfx::DEdge *v33; // r3
  bfx::DEdge *v34; // r7
  bfx::DEdge *Edge; // [sp+50h] [-90h] BYREF
  bfx::Space *v36; // [sp+54h] [-8Ch] BYREF
  bfx::EdgeCursor v37; // [sp+58h] [-88h] BYREF
  bfx::EdgeCursor v38; // [sp+60h] [-80h] BYREF

  v8 = 0;
  v37.m_pArea = pArea;
  v37.m_i = 0;
  m_size = edges->m_size;
  m_pArea = pArea;
  if ( (pArea->m_flags.m_flags1 & 0x7F) != 0 )
  {
    do
    {
      v19 = (char *)m_pArea + 24 * v8;
      v36 = (bfx::Space *)(v19 + 56);
      Edge = bfx::DGraph::CreateEdge(this);
      v20 = (bfx::Space *)Edge;
      v21 = edges->m_size;
      bfx::Array<bfx::Portal *>::push_back(this: edges, val: (bfx::Space **)&Edge);
      *((_DWORD *)v19 + 18) = *((unsigned __int16 *)v19 + 37) | (v21 << 16);
      bfx::Array<bfx::Portal *>::push_back(this: edgesModified, val: &v36);
      v20->m_rotSpaceToWorld.m_y = staticAreaNormal->m_x;
      LODWORD(v20->m_rotSpaceToWorld.m_x) = pStaticArea;
      m_y = staticAreaNormal->m_y;
      LODWORD(v20->m_rotWorldToSpace.m_x) = v19 + 56;
      v20->m_rotSpaceToWorld.m_z = m_y;
      v20->m_userData = (unsigned int)pArea;
      v20->m_rotWorldToSpace.m_w = staticAreaNormal->m_z;
      LODWORD(v20->m_matSpaceToWorld.m_data[0]) = (*((_DWORD *)v19 + 18) >> 13) & 3;
      LODWORD(v20->m_matSpaceToWorld.m_data[2]) = pObstacles;
      v23 = (*((_DWORD *)v19 + 18) << 20) | LODWORD(v20->m_matSpaceToWorld.m_data[3]) & 0xFFFFF;
      LODWORD(v20->m_matSpaceToWorld.m_data[3]) = v23;
      v24 = (unsigned __int8)(*((_DWORD *)v19 + 18) >> 12);
      LODWORD(v20->m_matSpaceToWorld.m_data[3]) = (v24 << 14) & 0x4000 | v23 & 0xFFFFBFFF;
      LODWORD(v20->m_matSpaceToWorld.m_data[3]) = ((unsigned __int8)(*((_DWORD *)v19 + 18) >> 15) << 10) & 0x400
                                                | (v24 << 14) & 0x4000
                                                | v23 & 0xFFFFB9FF;
      v25 = *((_DWORD *)v19 + 14);
      if ( v25 != 0 && (unsigned __int16)*(_DWORD *)(v25 + 48) == curSearchIndex )
      {
        bfx::EdgeCursor::GetSibling(this: &v38, result: &v37);
        if ( v38.m_pArea != nullptr )
        {
          v26 = *((unsigned __int16 *)&v38.m_pArea[1].m_pos.m_x + 12 * v38.m_i);
          if ( v26 != 0xFFFF )
          {
            v27 = (bfx::DEdge *)edges->m_data[v26];
            v27->m_pTwin = (bfx::DEdge *)v20;
            LODWORD(v20->m_pos.m_x) = v27;
          }
        }
      }
      m_pArea = v37.m_pArea;
      v8 = v37.m_i + 1;
      v37.m_i = v8;
    }
    while ( v8 < (signed int)(v37.m_pArea->m_flags.m_flags1 & 0x7F) );
  }
  v28 = 0;
  v29 = pArea->m_flags.m_flags1 & 0x7F;
  if ( v29 != 0 )
  {
    v30 = m_size;
    v31 = pArea->m_flags.m_flags1 & 0x7F;
    do
    {
      ++v28;
      m_data = (bfx::DEdge **)edges->m_data;
      __twllei(v29, 0);
      v33 = m_data[v30];
      __twlgei(v29 & ~(__ROL4__(v28, 1) - 1), 0xFFFFFFFF);
      ++v30;
      v34 = *(&m_data[v28 % v29] + m_size);
      v33->m_pNext = v34;
      v34->m_pPrev = v33;
      --v31;
    }
    while ( v31 != 0 );
  }
  LOWORD(pArea->m_flags.m_flags3) = curSearchIndex;
}


// ========================================================================
// ?BuildGraphFromAreas@DGraph@bfx@@QAAXABV?$Array@PAVArea@bfx@@@2@@Z
// EA  : 0x832C2618
// RVA : 0x012C2618
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraphio.cpp
// ========================================================================

void __fastcall bfx::DGraph::BuildGraphFromAreas(bfx::DGraph *this, const bfx::Array<bfx::Area *> *staticAreas)
{
  int SearchIndex; // r26
  int v5; // r21
  int v6; // r22
  bfx::Area *v7; // r28
  char *m_data; // r11
  int v9; // r27
  bfx::Area *v10; // r30
  int v11; // r29
  bfx::Array<bfx::ObstacleImpl *> *p_m_flags; // r7
  float m_z; // r26
  char *m_flags1; // r27
  float v15; // r29
  float m_radius; // r28
  float *v17; // r11
  bfx::DEdge *v18; // r30
  float v19; // r9
  float v20; // r8
  bfx::DVert *v21; // r3
  bfx::DEdge *m_pNext; // r11
  bfx::DEdge *m_pTwin; // r10
  bfx::SearchIndexOb v24[2]; // [sp+50h] [-B0h] BYREF
  bfx::Vec3 v25; // [sp+58h] [-A8h] BYREF
  bfx::Area v26[2]; // [sp+68h] [-98h] BYREF

  bfx::SearchIndexOb::SearchIndexOb(this: v24);
  SearchIndex = bfx::SearchIndexOb::GetSearchIndex(this: v24);
  v26[0].m_flags.m_flags1 = 0;
  v26[0].m_flags.m_flags2 = 0;
  v26[0].m_flags.m_flags3 = 0;
  v26[0].m_flags.m_flags4 = bfx::MEM_BFXPLANNER;
  bfx::Array<bfx::Edge *>::expand_cap(this: (bfx::Array<bfx::SpaceComponent *> *)&v26[0].m_flags, size: 100);
  v26[0].m_pos.m_z = 0.0;
  v26[0].m_radius = 0.0;
  v26[0].m_searchCost = 0;
  v26[0].m_usageFlags = bfx::MEM_BFXPLANNER;
  bfx::Array<bfx::Edge *>::expand_cap(this: (bfx::Array<bfx::SpaceComponent *> *)&v26[0].m_pos.m_z, size: 20);
  v5 = 0;
  if ( staticAreas->m_size > 0 )
  {
    v6 = 0;
    do
    {
      v7 = staticAreas->m_data[v6];
      bfx::Area::CalcNormal(this: v26, result: (bfx::Vec3 *)v7);
      m_data = v7->m_dynAreaData.m_data;
      if ( m_data != nullptr && (v9 = *(_DWORD *)m_data, *(_DWORD *)m_data != 0) )
      {
        v10 = (bfx::Area *)(m_data + 20);
        v11 = 0;
        do
        {
          p_m_flags = (bfx::Array<bfx::ObstacleImpl *> *)&v10[-1].m_flags;
          if ( (v10->m_flags.m_flags1 & 0x40000000) == 0 )
            p_m_flags = nullptr;
          bfx::DGraph::AddEdgesForArea(
            this,
            pArea: v10,
            pStaticArea: v7,
            staticAreaNormal: (const bfx::Vec3 *)v26,
            pObstacles: p_m_flags,
            curSearchIndex: SearchIndex,
            edges: (bfx::Array<bfx::Space *> *)&v26[0].m_flags,
            edgesModified: (bfx::Array<bfx::Space *> *)&v26[0].m_pos.m_z);
          ++v11;
          v10 = (bfx::Area *)((char *)v10 + 24 * (v10->m_flags.m_flags1 & 0x7F) + 72);
        }
        while ( v11 != v9 );
      }
      else
      {
        bfx::DGraph::AddEdgesForArea(
          this,
          pArea: v7,
          pStaticArea: v7,
          staticAreaNormal: (const bfx::Vec3 *)v26,
          pObstacles: nullptr,
          curSearchIndex: SearchIndex,
          edges: (bfx::Array<bfx::Space *> *)&v26[0].m_flags,
          edgesModified: (bfx::Array<bfx::Space *> *)&v26[0].m_pos.m_z);
      }
      ++v5;
      ++v6;
    }
    while ( v5 < staticAreas->m_size );
  }
  bfx::DGraph::AddTwinsForExternalEdges(this, edges: (bfx::Array<bfx::SpaceComponent *> *)&v26[0].m_flags);
  m_z = v26[0].m_pos.m_z;
  m_flags1 = (char *)v26[0].m_flags.m_flags1;
  if ( SLODWORD(v26[0].m_radius) > 0 )
  {
    v15 = v26[0].m_pos.m_z;
    m_radius = v26[0].m_radius;
    do
    {
      v17 = *(float **)LODWORD(v15);
      v18 = *(bfx::DEdge **)&m_flags1[__ROL4__(*(unsigned __int16 *)(*(_DWORD *)LODWORD(v15) + 16), 2)];
      *(_DWORD *)(*(_DWORD *)LODWORD(v15) + 16) |= 0xFFFF0000;
      if ( v18->m_pStartVert == nullptr )
      {
        v19 = v17[2];
        v20 = v17[3];
        v25.m_x = v17[1];
        v25.m_y = v19;
        v25.m_z = v20;
        v21 = bfx::DGraph::CreateVert(this, pos: &v25, pIncidentEdge: v18);
        m_pNext = v18;
        *((_DWORD *)v21 + 6) &= ~0x40000000u;
        do
        {
          m_pTwin = m_pNext->m_pTwin;
          m_pNext->m_pStartVert = v21;
          m_pNext = m_pTwin->m_pNext;
        }
        while ( m_pNext != v18 );
      }
      --LODWORD(m_radius);
      LODWORD(v15) += 4;
    }
    while ( m_radius != 0.0 );
  }
  idPhysics_StaticMulti::UpdateTime((bfx::BinaryReplayLogOut *)this);
  if ( m_z != 0.0 )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)LODWORD(m_z));
  if ( m_flags1 != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_flags1);
  bfx::SearchIndexOb::~SearchIndexOb(this: v24);
}


// ========================================================================
// __unwind$20751
// EA  : 0x832C286C
// RVA : 0x012C286C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraphio.cpp
// ========================================================================

void _unwind_20751()
{
  int v0; // r12

  bfx::SearchIndexOb::~SearchIndexOb(this: (bfx::SearchIndexOb *)(v0 - 256 + 80));
}


// ========================================================================
// __unwind$20752
// EA  : 0x832C2894
// RVA : 0x012C2894
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraphio.cpp
// ========================================================================

void _unwind_20752()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 256 + 144));
}


// ========================================================================
// __unwind$20753_0
// EA  : 0x832C28BC
// RVA : 0x012C28BC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraphio.cpp
// ========================================================================

void _unwind_20753_0()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 256 + 128));
}


// ========================================================================
// ?GetFacesForStaticArea@DGraph@bfx@@AAAXPAVArea@2@AAV?$Array@PAVDFace@bfx@@@2@@Z
// EA  : 0x832C28E8
// RVA : 0x012C28E8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraphio.cpp
// ========================================================================

void __fastcall bfx::DGraph::GetFacesForStaticArea(
        bfx::DGraph *this,
        bfx::Area *pStaticArea,
        bfx::Array<bfx::SpaceComponent *> *faces)
{
  bfx::ListNode *i; // r30
  int m_cap; // r10
  int m_size; // r11
  int v8; // r4
  bfx::DFace **v9; // r11

  for ( i = this->m_pHeadFaceNode; i != nullptr; i = i->m_pNextListNode )
  {
    if ( (bfx::Area *)i[1].m_pPrevListNode == pStaticArea )
    {
      m_cap = faces->m_cap;
      m_size = faces->m_size;
      if ( m_cap == m_size )
      {
        v8 = 2 * m_cap;
        if ( m_cap == 0 )
          v8 = 1;
        bfx::Array<bfx::Edge *>::expand_cap(this: faces, size: v8);
        m_size = faces->m_size;
      }
      v9 = (bfx::DFace **)&faces->m_data[m_size];
      if ( v9 != nullptr )
        *v9 = (bfx::DFace *)i;
      ++faces->m_size;
    }
  }
}


// ========================================================================
// ?GetCostMultAndBlockageFlagsFromObstacleList@bfx@@YAXABV?$Array@PAVObstacleImpl@bfx@@@1@AAI1@Z
// EA  : 0x832C2978
// RVA : 0x012C2978
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraphio.cpp
// ========================================================================

void __fastcall bfx::GetCostMultAndBlockageFlagsFromObstacleList(
        const bfx::Array<bfx::ObstacleImpl *> *obstacles,
        unsigned int *costMultFromStaticGraphOut,
        unsigned int *obBlockageFlagsFromNavGraph)
{
  int v3; // r7
  int v4; // r11
  unsigned int v5; // r9
  bfx::ObstacleImpl *v6; // r10
  double m_penaltyMult; // fp0

  v3 = 0;
  *costMultFromStaticGraphOut = 1;
  *obBlockageFlagsFromNavGraph = 0;
  if ( obstacles->m_size > 0 )
  {
    v4 = 0;
    do
    {
      v5 = *costMultFromStaticGraphOut;
      v6 = obstacles->m_data[v4];
      m_penaltyMult = v6->m_obstacleDat.m_penaltyMult;
      if ( *costMultFromStaticGraphOut <= (unsigned int)(__int64)m_penaltyMult )
        v5 = (__int64)m_penaltyMult;
      *costMultFromStaticGraphOut = v5;
      ++v3;
      ++v4;
      *obBlockageFlagsFromNavGraph |= v6->m_obstacleDat.m_obstacleBlockageFlags;
    }
    while ( v3 < obstacles->m_size );
  }
}


// ========================================================================
// ?BuildDynAreaData@bfx@@YAPADPAVArea@1@ABV?$Array@PAVDFace@bfx@@@1@@Z
// EA  : 0x832C29F8
// RVA : 0x012C29F8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraphio.cpp
// ========================================================================

char *__fastcall bfx::BuildDynAreaData(bfx::Area *pStaticArea, const bfx::Array<bfx::DFace *> *faces)
{
  int m_size; // r30
  unsigned int v5; // r4
  bfx::DFace **m_data; // r7
  int v7; // r8
  int i; // ctr
  int v9; // r10
  bfx::DEdge *m_pOuterEdge; // r11
  int *v11; // r3
  int *v12; // r19
  bfx::Area *v13; // r11
  unsigned int v14; // r22
  unsigned int v15; // r21
  int v16; // r24
  int j; // r18
  bfx::DFace *v18; // r28
  bfx::bfxMemTag v19; // r10
  bfx::Array<bfx::ObstacleImpl *> *v20; // r30
  bfx::ObstacleImpl **v21; // r9
  bfx::ObstacleImpl **v22; // r8
  bfx::Area *p_m_pos; // r26
  char v24; // r29
  int v25; // r3
  int m_cap; // r10
  bfx::DEdge *v27; // r10
  bfx::DEdge *v28; // r11
  bfx::Area *v29; // r27
  bfx::AreaFlags *p_m_flags; // r29
  int v31; // r10
  int v32; // r11
  unsigned int v33; // r10
  unsigned int v34; // r11
  unsigned int m_flags1; // r11
  bfx::DEdge *v36; // r10
  bfx::DVert *m_pStartVert; // r9
  bfx::EdgeType m_inputEdgeType; // r6
  bfx::Area *v39; // r8
  unsigned int v40; // r5
  unsigned int v41; // r7
  bfx::Area *m_z_low; // r5
  float m_x; // r9
  unsigned int v44; // r7
  float v45; // r9
  unsigned int v46; // r7
  int v48; // [sp+8h] [-108h]
  int v49; // [sp+Ch] [-104h]
  int v50; // [sp+10h] [-100h]
  int v51; // [sp+14h] [-FCh]
  int v52; // [sp+18h] [-F8h]
  int v53; // [sp+1Ch] [-F4h]
  int v54; // [sp+20h] [-F0h]
  int v55; // [sp+24h] [-ECh]
  int v56; // [sp+28h] [-E8h]
  int v57; // [sp+2Ch] [-E4h]
  int v58; // [sp+30h] [-E0h]
  int v59; // [sp+34h] [-DCh]
  int v60; // [sp+38h] [-D8h]
  int v61; // [sp+3Ch] [-D4h]
  int v62; // [sp+40h] [-D0h]
  int v63; // [sp+44h] [-CCh]
  int v64; // [sp+48h] [-C8h]
  int v65; // [sp+4Ch] [-C4h]
  int v66; // [sp+50h] [-C0h]
  int v67; // [sp+58h] [-B8h]
  int v68; // [sp+60h] [-B0h] BYREF
  float v69; // [sp+64h] [-ACh] BYREF
  unsigned int v70; // [sp+68h] [-A8h] BYREF
  unsigned int v71[2]; // [sp+6Ch] [-A4h] BYREF
  void *p_m_size; // [sp+74h] [-9Ch]
  bfx::Vec3 v73[12]; // [sp+78h] [-98h] BYREF

  m_size = faces->m_size;
  v5 = 4;
  if ( m_size > 0 )
  {
    m_data = faces->m_data;
    v7 = 0;
    for ( i = m_size; i != 0; --i )
    {
      v9 = 0;
      m_pOuterEdge = m_data[v7]->m_pOuterEdge;
      do
      {
        m_pOuterEdge = m_pOuterEdge->m_pNext;
        ++v9;
      }
      while ( m_pOuterEdge != m_data[v7]->m_pOuterEdge );
      ++v7;
      v5 += 24 * (v9 + 3);
    }
  }
  v11 = (int *)bfx::MemoryManager::Malloc(
                 this: bfx::g_pCurInstance->m_pMemoryManager,
                 size: v5,
                 tag: bfx::MEM_DYNAMIC_AREAS);
  *v11 = m_size;
  v12 = v11;
  v13 = (bfx::Area *)(v11 + 1);
  v14 = pStaticArea->m_flags.m_flags3 >> 31;
  v15 = (pStaticArea->m_flags.m_flags2 >> 20) & 0xF;
  if ( m_size > 0 )
  {
    v16 = 0;
    for ( j = m_size; j != 0; --j )
    {
      v18 = faces->m_data[v16];
      if ( v13 != nullptr )
      {
        v19 = bfx::MEM_BFXPLANNER;
        v20 = (bfx::Array<bfx::ObstacleImpl *> *)v13;
        v13->m_pProxy = nullptr;
        v13->m_dynAreaData.m_data = nullptr;
        v13->m_pFirstLink = nullptr;
        v13->m_pSearchParent = (bfx::Area *)v19;
      }
      else
      {
        v20 = nullptr;
      }
      v21 = v18->m_finalObstacles.m_data;
      v22 = v20->m_data;
      p_m_pos = (bfx::Area *)&v13->m_pos;
      v71[1] = (unsigned int)&v13->m_pos;
      p_m_size = &v18->m_finalObstacles.m_size;
      v20->m_data = v21;
      v18->m_finalObstacles.m_data = v22;
      v24 = 0;
      v25 = v20->m_size;
      v20->m_size = v18->m_finalObstacles.m_size;
      v18->m_finalObstacles.m_size = v25;
      m_cap = v20->m_cap;
      v20->m_cap = v18->m_finalObstacles.m_cap;
      p_m_size = &v20->m_size;
      v18->m_finalObstacles.m_cap = m_cap;
      v27 = v18->m_pOuterEdge;
      v28 = v27;
      p_m_size = &v20->m_cap;
      do
      {
        v28 = v28->m_pNext;
        ++v24;
      }
      while ( v28 != v27 );
      bfx::DFace::CalcCentroidAndRadiusAndBasisVert(this: v18, centroidOut: v73, radiusOut: &v69, basisVertOut: &v68);
      p_m_size = p_m_pos;
      if ( p_m_pos != nullptr )
        v29 = bfx::Area::Area(
                this: p_m_pos,
                pos: v73,
                radius: v69,
                numEdges: v68,
                full3D: v24,
                island: v14,
                layerIndex: 0x1FFFFu,
                graphIndex: pStaticArea->m_flags.m_flags4 >> 27,
                usageFlags: HIWORD(pStaticArea->m_flags.m_flags3) & 0x7FF,
                basisVert: v48,
                a11: v49,
                a12: v50,
                a13: v51,
                a14: v52,
                a15: v53,
                a16: v54,
                a17: v55,
                a18: v56,
                a19: v57,
                a20: v58,
                a21: v59,
                a22: v60,
                a23: v61,
                a24: v62,
                a25: v63,
                a26: v64,
                a27: v65,
                a28: v66,
                a29: pStaticArea->m_usageFlags,
                a30: v67,
                a31: v68);
      else
        v29 = nullptr;
      p_m_flags = &v29->m_flags;
      v31 = v29->m_flags.m_flags1 | 0x40000000;
      p_m_size = &v29->m_flags;
      v29->m_flags.m_flags1 = v31;
      v32 = 1;
      if ( v15 != 0 )
        v32 = v15;
      v29->m_flags.m_flags2 = (v32 << 20) & 0xF00000 | v29->m_flags.m_flags2 & 0xFF0FFFFF;
      bfx::GetCostMultAndBlockageFlagsFromObstacleList(
        obstacles: v20,
        costMultFromStaticGraphOut: &v70,
        obBlockageFlagsFromNavGraph: v71);
      v33 = v70;
      if ( v70 <= 0xF )
      {
        v34 = 1;
        if ( v70 != 0 )
          v34 = v70;
      }
      else
      {
        v34 = 15;
      }
      v29->m_flags.m_flags2 = (v34 << 16) & 0xF0000 | v29->m_flags.m_flags2 & 0xFFF0FFFF;
      if ( v33 >= 0xF )
      {
        m_flags1 = p_m_flags->m_flags1;
        p_m_size = &v29->m_flags;
        p_m_flags->m_flags1 = m_flags1 | 0x20000000;
      }
      v13 = p_m_pos + 1;
      LOWORD(v29->m_flags.m_flags2) = v71[0];
      v36 = v18->m_pOuterEdge;
      v18->m_pOutputArea = v29;
      do
      {
        if ( v13 != nullptr )
        {
          m_pStartVert = v36->m_pStartVert;
          m_inputEdgeType = v36->m_inputEdgeType;
          v39 = v13;
          v40 = *((_DWORD *)v36 + 18);
          v13->m_pProxy = nullptr;
          v13->m_dynAreaData.m_data = (char *)LODWORD(m_pStartVert->m_pos.m_x);
          v41 = (m_inputEdgeType << 13) & 0x6000 | 0xFFFF0000 | (v40 >> 20);
          v13->m_pFirstLink = (bfx::HalfLink *)LODWORD(m_pStartVert->m_pos.m_y);
          m_z_low = (bfx::Area *)LODWORD(m_pStartVert->m_pos.m_z);
          v13->m_pos.m_y = 0.0;
          LODWORD(v13->m_pos.m_x) = v41;
          v13->m_pSearchParent = m_z_low;
        }
        else
        {
          v39 = nullptr;
        }
        v36->m_pOutputEdge = (bfx::Edge *)v39;
        m_x = v39->m_pos.m_x;
        v44 = LODWORD(m_x) | 0x1000;
        if ( (*((_DWORD *)v36 + 18) & 0x4000) == 0 )
          v44 = LODWORD(m_x) & 0xFFFFEFFF;
        LODWORD(v39->m_pos.m_x) = v44;
        v45 = v39->m_pos.m_x;
        v46 = LODWORD(v45) | 0x8000;
        if ( (*((_DWORD *)v36 + 18) & 0x400) == 0 )
          v46 = LODWORD(v45) & 0xFFFF7FFF;
        LODWORD(v39->m_pos.m_x) = v46;
        v13 = (bfx::Area *)((char *)v13 + 24);
        v36 = v36->m_pNext;
      }
      while ( v36 != v18->m_pOuterEdge );
      ++v16;
    }
  }
  return (char *)v12;
}


// ========================================================================
// __unwind$21133
// EA  : 0x832C2D38
// RVA : 0x012C2D38
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraphio.cpp
// ========================================================================

void _unwind_21133()
{
  int v0; // r12

  idPhysics_StaticMulti::UpdateTime(this: *(bfx::BinaryReplayLogOut **)(v0 - 272 + 116));
}


// ========================================================================
// ?EnforceMaxEdgeCount@DGraph@bfx@@AAAXXZ
// EA  : 0x832C2D70
// RVA : 0x012C2D70
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraphio.cpp
// ========================================================================

void __fastcall bfx::DGraph::EnforceMaxEdgeCount(bfx::DGraph *this)
{
  char *m_data; // r29
  bfx::Space *m_pHeadFaceNode; // r30
  int m_size; // r30
  int m_cap; // r27
  char *v6; // r11
  bfx::DFace *v7; // r28
  bfx::DFace *v8; // r26
  int v9; // r4
  int v10; // r10
  int v11; // r4
  bfx::Space *v12; // [sp+50h] [-60h] BYREF
  bfx::DFace *v13; // [sp+54h] [-5Ch] BYREF
  bfx::Array<bfx::SpaceComponent *> v14[5]; // [sp+60h] [-50h] BYREF

  m_data = nullptr;
  memset(v14, 0, 12);
  v14[0].m_tag = bfx::MEM_BFXPLANNER;
  m_pHeadFaceNode = (bfx::Space *)this->m_pHeadFaceNode;
  if ( m_pHeadFaceNode != nullptr )
  {
    do
    {
      v12 = m_pHeadFaceNode;
      v13 = bfx::DGraph::SplitConvexFaceIfNeededToEnforceMaxEdgeCount(this, pFace: (bfx::DFace *)m_pHeadFaceNode);
      if ( v13 != nullptr )
      {
        bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)v14, val: &v12);
        bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)v14, val: (bfx::Space **)&v13);
      }
      m_pHeadFaceNode = (bfx::Space *)m_pHeadFaceNode->__vftable;
    }
    while ( m_pHeadFaceNode != nullptr );
    m_size = v14[0].m_size;
    m_data = (char *)v14[0].m_data;
    if ( v14[0].m_size != 0 )
    {
      m_cap = v14[0].m_cap;
      do
      {
        v6 = &m_data[4 * m_size--];
        v14[0].m_size = m_size;
        v7 = *((bfx::DFace **)v6 - 1);
        v8 = bfx::DGraph::SplitConvexFaceIfNeededToEnforceMaxEdgeCount(this, pFace: v7);
        if ( v8 != nullptr )
        {
          if ( m_cap == m_size )
          {
            v9 = 2 * m_cap;
            if ( m_cap == 0 )
              v9 = 1;
            bfx::Array<bfx::Edge *>::expand_cap(this: v14, size: v9);
            m_size = v14[0].m_size;
            m_data = (char *)v14[0].m_data;
            m_cap = v14[0].m_cap;
          }
          if ( &m_data[4 * m_size] != nullptr )
            *(_DWORD *)&m_data[4 * m_size] = v7;
          v10 = m_size + 1;
          v14[0].m_size = m_size + 1;
          if ( m_cap == m_size + 1 )
          {
            v11 = 2 * m_cap;
            if ( m_cap == 0 )
              v11 = 1;
            bfx::Array<bfx::Edge *>::expand_cap(this: v14, size: v11);
            v10 = v14[0].m_size;
            m_data = (char *)v14[0].m_data;
            m_cap = v14[0].m_cap;
          }
          if ( &m_data[4 * v10] != nullptr )
            *(_DWORD *)&m_data[4 * v10] = v8;
          m_size = v10 + 1;
        }
      }
      while ( m_size != 0 );
    }
  }
  if ( m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
}


// ========================================================================
// __unwind$21442
// EA  : 0x832C2EDC
// RVA : 0x012C2EDC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraphio.cpp
// ========================================================================

void _unwind_21442()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 176 + 96));
}


// ========================================================================
// ?WriteGraphToAreas@DGraph@bfx@@QAAXABV?$Array@PAVArea@bfx@@@2@@Z
// EA  : 0x832C2F10
// RVA : 0x012C2F10
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraphio.cpp
// ========================================================================

void __fastcall bfx::DGraph::WriteGraphToAreas(bfx::DGraph *this, const bfx::Array<bfx::Area *> *staticAreas)
{
  int v4; // r27
  int v5; // r30
  bfx::Area *v6; // r25
  bfx::Array<bfx::SpaceComponent *> v7[5]; // [sp+50h] [-50h] BYREF

  bfx::DGraph::EnforceMaxEdgeCount(this);
  memset(v7, 0, 12);
  v7[0].m_tag = bfx::MEM_BFXPLANNER;
  bfx::Array<bfx::Edge *>::expand_cap(this: v7, size: 16);
  v4 = 0;
  if ( staticAreas->m_size > 0 )
  {
    v5 = 0;
    do
    {
      v6 = staticAreas->m_data[v5];
      bfx::DGraph::GetFacesForStaticArea(this, pStaticArea: v6, faces: v7);
      bfx::Area::BuildDynAreaData(this: v6, faces: (const bfx::Array<bfx::DFace *> *)v7);
      if ( v7[0].m_size >= 0 )
      {
        v7[0].m_size &= __CFADD__(-v7[0].m_size, v7[0].m_size ^ 0x80000000) - 1;
      }
      else
      {
        if ( v7[0].m_cap < 0 )
          bfx::Array<bfx::Edge *>::expand_cap(this: v7, size: 0);
        v7[0].m_size = 0;
      }
      ++v4;
      ++v5;
    }
    while ( v4 < staticAreas->m_size );
  }
  bfx::ConnectUpOutputEdges(pHeadEdgeNode: this->m_pHeadEdgeNode);
  v7[0].m_size = 0;
  if ( v7[0].m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v7[0].m_data);
}


// ========================================================================
// __unwind$21582
// EA  : 0x832C3014
// RVA : 0x012C3014
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraphio.cpp
// ========================================================================

void _unwind_21582()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 160 + 80));
}


// ========================================================================
// ?AddObstacle@DGraph@bfx@@QAA?AW4DResult@2@PAVObstacleImpl@2@M@Z
// EA  : 0x832C3040
// RVA : 0x012C3040
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraphio.cpp
// ========================================================================

bfx::DResult __fastcall bfx::DGraph::AddObstacle(bfx::DGraph *this, bfx::Sphere *pObstacle, double expandRadius)
{
  bfx::CoreAddObstacleData v5; // [sp+50h] [-E0h] BYREF

  bfx::CoreAddObstacleData::CoreAddObstacleData(this: &v5, pObstacle, expandRadius);
  return bfx::DGraph::CoreAddObstacle(this, coreAddObstacleData: &v5);
}


// ========================================================================
// ?Clear@DynAreaData@bfx@@QAAXXZ
// EA  : 0x832C3080
// RVA : 0x012C3080
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraphio.cpp
// ========================================================================

void __fastcall bfx::DynAreaData::Clear(bfx::DynAreaData *this)
{
  char *m_data; // r11
  int v3; // r27
  bfx::Area *v4; // r31
  int i; // r28
  bfx::AreaFlags *p_m_flags; // r30
  char *m_flags1; // r4

  m_data = this->m_data;
  if ( this->m_data != nullptr )
  {
    v3 = *(_DWORD *)m_data;
    v4 = (bfx::Area *)(m_data + 20);
    for ( i = 0; i != v3; v4 = (bfx::Area *)((char *)v4 + 24 * (v4->m_flags.m_flags1 & 0x7F) + 72) )
    {
      p_m_flags = &v4[-1].m_flags;
      if ( (v4->m_flags.m_flags1 & 0x40000000) == 0 )
        p_m_flags = nullptr;
      bfx::Area::~Area(this: v4);
      m_flags1 = (char *)p_m_flags->m_flags1;
      p_m_flags->m_flags2 = 0;
      if ( m_flags1 != nullptr )
      {
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_flags1);
        p_m_flags->m_flags1 = 0;
      }
      p_m_flags->m_flags3 = 0;
      ++i;
    }
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: this->m_data);
    this->m_data = nullptr;
  }
}


// ========================================================================
// ?Set@DynAreaData@bfx@@QAAXPAVArea@2@ABV?$Array@PAVDFace@bfx@@@2@@Z
// EA  : 0x832C3140
// RVA : 0x012C3140
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraphio.cpp
// ========================================================================

void __fastcall bfx::DynAreaData::Set(
        bfx::DynAreaData *this,
        bfx::Area *pStaticArea,
        const bfx::Array<bfx::DFace *> *faces)
{
  char *v4; // r30

  v4 = bfx::BuildDynAreaData(pStaticArea, faces);
  bfx::DynAreaData::Clear(this);
  this->m_data = v4;
}

