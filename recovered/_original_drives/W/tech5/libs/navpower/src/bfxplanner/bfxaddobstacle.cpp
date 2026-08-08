
// ========================================================================
// ?DGraph_CollideLineAndPlane@bfx@@YA?AVVec3@1@ABV21@0ABVPlane@1@@Z
// EA  : 0x832C4060
// RVA : 0x012C4060
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

bfx::Vec3 *__fastcall bfx::DGraph_CollideLineAndPlane(
        bfx::Vec3 *result,
        const bfx::Vec3 *v0,
        const bfx::Vec3 *v1,
        const bfx::Plane *plane)
{
  float m_y; // r10
  float m_z; // r9
  double v6; // fp5
  double v7; // fp4
  double v8; // fp12
  double v9; // fp11

  if ( (float)((float)((float)(v1->m_z * plane->m_normal.m_z)
                     + (float)((float)(v1->m_x * plane->m_normal.m_x) + (float)(v1->m_y * plane->m_normal.m_y)))
             - (float)((float)(plane->m_normal.m_z * v0->m_z)
                     + (float)((float)(plane->m_normal.m_x * v0->m_x) + (float)(plane->m_normal.m_y * v0->m_y)))) == 0.0 )
  {
    m_y = v0->m_y;
    m_z = v0->m_z;
    result->m_x = v0->m_x;
    result->m_y = m_y;
    result->m_z = m_z;
  }
  else
  {
    v6 = v0->m_y;
    v7 = v0->m_z;
    v8 = (float)((float)(v1->m_y - v0->m_y)
               * (float)((float)(plane->m_d
                               - (float)((float)(plane->m_normal.m_z * v0->m_z)
                                       + (float)((float)(plane->m_normal.m_x * v0->m_x)
                                               + (float)(plane->m_normal.m_y * v0->m_y))))
                       / (float)((float)((float)(v1->m_z * plane->m_normal.m_z)
                                       + (float)((float)(v1->m_x * plane->m_normal.m_x)
                                               + (float)(v1->m_y * plane->m_normal.m_y)))
                               - (float)((float)(plane->m_normal.m_z * v0->m_z)
                                       + (float)((float)(plane->m_normal.m_x * v0->m_x)
                                               + (float)(plane->m_normal.m_y * v0->m_y))))));
    v9 = (float)((float)(v1->m_z - v0->m_z)
               * (float)((float)(plane->m_d
                               - (float)((float)(plane->m_normal.m_z * v0->m_z)
                                       + (float)((float)(plane->m_normal.m_x * v0->m_x)
                                               + (float)(plane->m_normal.m_y * v0->m_y))))
                       / (float)((float)((float)(v1->m_z * plane->m_normal.m_z)
                                       + (float)((float)(v1->m_x * plane->m_normal.m_x)
                                               + (float)(v1->m_y * plane->m_normal.m_y)))
                               - (float)((float)(plane->m_normal.m_z * v0->m_z)
                                       + (float)((float)(plane->m_normal.m_x * v0->m_x)
                                               + (float)(plane->m_normal.m_y * v0->m_y))))));
    result->m_x = v0->m_x
                + (float)((float)(v1->m_x - v0->m_x)
                        * (float)((float)(plane->m_d
                                        - (float)((float)(plane->m_normal.m_z * v0->m_z)
                                                + (float)((float)(plane->m_normal.m_x * v0->m_x)
                                                        + (float)(plane->m_normal.m_y * v0->m_y))))
                                / (float)((float)((float)(v1->m_z * plane->m_normal.m_z)
                                                + (float)((float)(v1->m_x * plane->m_normal.m_x)
                                                        + (float)(v1->m_y * plane->m_normal.m_y)))
                                        - (float)((float)(plane->m_normal.m_z * v0->m_z)
                                                + (float)((float)(plane->m_normal.m_x * v0->m_x)
                                                        + (float)(plane->m_normal.m_y * v0->m_y))))));
    result->m_y = (float)v6 + (float)v8;
    result->m_z = (float)v7 + (float)v9;
  }
  return result;
}


// ========================================================================
// ?CopyRelevantEdgeData@bfx@@YAXPAVDEdge@1@0@Z
// EA  : 0x832C4118
// RVA : 0x012C4118
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void __fastcall bfx::CopyRelevantEdgeData(bfx::DEdge *pEdgeA, bfx::DEdge *pEdgeB)
{
  int v2; // r10
  unsigned int v3; // r6
  unsigned int v4; // r11
  unsigned int v5; // r9
  unsigned int v6; // r7
  unsigned int v7; // r11

  v2 = *((_DWORD *)pEdgeB + 18);
  pEdgeB->m_inputEdgeType = pEdgeA->m_inputEdgeType;
  pEdgeB->m_pInitialObstacles = pEdgeA->m_pInitialObstacles;
  v3 = v2 & 0xFFFFF | *((_DWORD *)pEdgeA + 18) & 0xFFF00000;
  *((_DWORD *)pEdgeB + 18) = v3;
  v4 = *((_DWORD *)pEdgeA + 18) & 0x80000 | v3 & 0xFFF7FFFF;
  *((_DWORD *)pEdgeB + 18) = v4;
  v5 = *((_DWORD *)pEdgeA + 18) & 0x78000 | v4 & 0xFFF87FFF;
  *((_DWORD *)pEdgeB + 18) = v5;
  v6 = *((_DWORD *)pEdgeA + 18) & 0x800 | v5 & 0xFFFFF7FF;
  *((_DWORD *)pEdgeB + 18) = v6;
  *((_DWORD *)pEdgeB + 18) = *((_DWORD *)pEdgeA + 18) & 0x4000 | v6 & 0xFFFFBFFF;
  pEdgeB->m_pSrcStaticArea = pEdgeA->m_pSrcStaticArea;
  pEdgeB->m_srcStaticAreaNormal = pEdgeA->m_srcStaticAreaNormal;
  v7 = *((_DWORD *)pEdgeA + 18) & 0x200 | *((_DWORD *)pEdgeB + 18) & 0xFFFFFDFF;
  *((_DWORD *)pEdgeB + 18) = v7;
  *((_DWORD *)pEdgeB + 18) = *((_DWORD *)pEdgeA + 18) & 0x400 | v7 & 0xFFFFFBFF;
  pEdgeB->m_inwardsEdgeCursor = pEdgeA->m_inwardsEdgeCursor;
}


// ========================================================================
// ?SplitEdgeAtPos@DGraph@bfx@@AAAXPAVDEdge@2@ABVVec3@2@@Z
// EA  : 0x832C41D0
// RVA : 0x012C41D0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void __fastcall bfx::DGraph::SplitEdgeAtPos(bfx::DGraph *this, bfx::DEdge *pEdge, const bfx::Vec3 *pos)
{
  bfx::DEdge *m_pTwin; // r30
  bfx::DEdge *Edge; // r29
  bfx::DEdge *v8; // r31
  bfx::DVert *Vert; // r3
  bfx::DVert *v10; // r27
  bfx::DEdge *m_pNext; // r10
  bfx::DVert *m_pStartVert; // r11

  idPhysics_StaticMulti::UpdateTime((bfx::BinaryReplayLogOut *)this);
  m_pTwin = pEdge->m_pTwin;
  Edge = bfx::DGraph::CreateEdge(this);
  v8 = bfx::DGraph::CreateEdge(this);
  Vert = bfx::DGraph::CreateVert(this, pos, pIncidentEdge: m_pTwin);
  v10 = Vert;
  if ( (*((_DWORD *)pEdge + 18) & 0x4000) != 0 )
    *((_DWORD *)Vert + 6) |= 0x10000000u;
  m_pNext = pEdge->m_pNext;
  Edge->m_pPrev = pEdge;
  Edge->m_pTwin = v8;
  Edge->m_pStartVert = Vert;
  Edge->m_pFace = nullptr;
  Edge->m_pNext = m_pNext;
  v8->m_pNext = m_pTwin;
  v8->m_pPrev = m_pTwin->m_pPrev;
  v8->m_pTwin = Edge;
  v8->m_pStartVert = m_pTwin->m_pStartVert;
  v8->m_pFace = nullptr;
  bfx::CopyRelevantEdgeData(pEdgeA: pEdge, pEdgeB: Edge);
  bfx::CopyRelevantEdgeData(pEdgeA: m_pTwin, pEdgeB: v8);
  pEdge->m_pNext->m_pPrev = Edge;
  pEdge->m_pNext = Edge;
  m_pTwin->m_pPrev->m_pNext = v8;
  m_pTwin->m_pPrev = v8;
  m_pTwin->m_pStartVert = v10;
  m_pStartVert = v8->m_pStartVert;
  if ( m_pStartVert->m_pIncidentEdge == m_pTwin )
    m_pStartVert->m_pIncidentEdge = v8;
  idPhysics_StaticMulti::UpdateTime((bfx::BinaryReplayLogOut *)this);
}


// ========================================================================
// ?GetExitEdge@bfx@@YAPAVDEdge@1@PAV21@@Z
// EA  : 0x832C42C8
// RVA : 0x012C42C8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

bfx::DEdge *__fastcall bfx::GetExitEdge(bfx::DEdge *pStartEdge)
{
  bfx::DEdge *v1; // r11

  v1 = pStartEdge;
  while ( (*((_DWORD *)v1->m_pStartVert + 6) & 0x20000000) == 0
       || (*((_DWORD *)v1->m_pNext->m_pStartVert + 6) & 0x20000000) != 0 )
  {
    v1 = v1->m_pNext;
    if ( v1 == pStartEdge )
      return nullptr;
  }
  return v1;
}


// ========================================================================
// ?GetAdjVertFurthestFromPlane@bfx@@YAPAVDVert@1@PAV21@ABVPlane@1@@Z
// EA  : 0x832C4318
// RVA : 0x012C4318
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

bfx::DVert *__fastcall bfx::GetAdjVertFurthestFromPlane(bfx::DVert *pVert, const bfx::Plane *plane)
{
  bfx::DVert *result; // r3
  bfx::DEdge *m_pIncidentEdge; // r10
  BOOL v4; // r9
  double v5; // fp13
  bool v6; // r11
  bfx::DEdge *v7; // r7
  double v8; // fp0

  m_pIncidentEdge = pVert->m_pIncidentEdge;
  v4 = (_cntlzw((unsigned int)m_pIncidentEdge) & 0x20) != 0;
  v5 = 0.0;
  v6 = true;
  v7 = m_pIncidentEdge;
  for ( result = nullptr; !v4; v6 = (_cntlzw(v6) & 0x20) != 0 )
  {
    if ( v6 )
    {
      v8 = __fabs((float)((float)((float)(plane->m_normal.m_x * m_pIncidentEdge->m_pTwin->m_pStartVert->m_pos.m_x)
                                + (float)((float)(m_pIncidentEdge->m_pTwin->m_pStartVert->m_pos.m_z * plane->m_normal.m_z)
                                        + (float)(m_pIncidentEdge->m_pTwin->m_pStartVert->m_pos.m_y * plane->m_normal.m_y)))
                        - plane->m_d));
      if ( v8 >= v5 )
      {
        v5 = v8;
        result = m_pIncidentEdge->m_pTwin->m_pStartVert;
      }
      m_pIncidentEdge = m_pIncidentEdge->m_pTwin;
    }
    else
    {
      m_pIncidentEdge = m_pIncidentEdge->m_pNext;
    }
    if ( m_pIncidentEdge == v7 )
      LOBYTE(v4) = 1;
  }
  return result;
}


// ========================================================================
// ?ConnectsToNewEdge@bfx@@YA_NPAVDVert@1@@Z
// EA  : 0x832C43D0
// RVA : 0x012C43D0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

int __fastcall bfx::ConnectsToNewEdge(bfx::DVert *pVert)
{
  bfx::DEdge *m_pIncidentEdge; // r10
  bool v2; // r11
  char v3; // r9

  m_pIncidentEdge = pVert->m_pIncidentEdge;
  if ( m_pIncidentEdge == nullptr )
    return 0;
  v2 = true;
  v3 = 0;
  while ( (*((_DWORD *)m_pIncidentEdge + 18) & 0x200) == 0 )
  {
    if ( v2 )
      m_pIncidentEdge = m_pIncidentEdge->m_pTwin;
    else
      m_pIncidentEdge = m_pIncidentEdge->m_pNext;
    if ( m_pIncidentEdge == pVert->m_pIncidentEdge )
      v3 = 1;
    v2 = (_cntlzw(v2) & 0x20) != 0;
    if ( v3 != 0 )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?GetLengthOfShortestEdge@DGraph@bfx@@AAAM_N@Z
// EA  : 0x832C4440
// RVA : 0x012C4440
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

float __fastcall bfx::DGraph::GetLengthOfShortestEdge(bfx::DGraph *this, bool onlyCheckImmediatelyOutsideObstacle)
{
  bfx::ListNode *m_pHeadEdgeNode; // r9
  float *m_pNextListNode; // r11
  float *v5; // r10
  double v6; // fp9
  double v7; // fp7
  double v8; // fp5
  double v10; // fp1

  m_pHeadEdgeNode = this->m_pHeadEdgeNode;
  for ( _FP0 = 3.4028235e38; m_pHeadEdgeNode != nullptr; m_pHeadEdgeNode = m_pHeadEdgeNode->m_pNextListNode )
  {
    if ( !onlyCheckImmediatelyOutsideObstacle
      || ((int)m_pHeadEdgeNode[1].m_pPrevListNode[1].m_pNextListNode[3].m_pNextListNode
        ^ (int)m_pHeadEdgeNode[1].m_pNextListNode[3].m_pNextListNode) < 0 )
    {
      m_pNextListNode = (float *)m_pHeadEdgeNode[1].m_pNextListNode;
      v5 = (float *)m_pHeadEdgeNode[1].m_pPrevListNode[1].m_pNextListNode;
      v6 = (float)(v5[4] - m_pNextListNode[4]);
      v7 = (float)(v5[2] - m_pNextListNode[2]);
      v8 = (float)(v5[3] - m_pNextListNode[3]);
      _FP1 = (float)((float)_FP0
                   - (float)((float)((float)v8 * (float)v8)
                           + (float)((float)((float)v7 * (float)v7) + (float)((float)v6 * (float)v6))));
      __asm { fsel      f0, f1, f2, f0 }
    }
  }
  v10 = __fsqrts(_FP0);
  return *((float *)&v10 + 1);
}


// ========================================================================
// ?SpliceBetweenExitAndEnterPoints@DGraph@bfx@@AAAPAVDEdge@2@PAV32@0ABVVec3@2@1HHAA_N2AAV?$Array@PAVDVert@bfx@@@2@@Z
// EA  : 0x832C45A8
// RVA : 0x012C45A8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

bfx::DEdge *__fastcall bfx::DGraph::SpliceBetweenExitAndEnterPoints(
        bfx::DGraph *this,
        bfx::DEdge *pExitEdge,
        bfx::DEdge *pEnterEdge,
        const bfx::Vec3 *exitPos,
        const bfx::Vec3 *enterPos,
        int planeIndex,
        int obID,
        bool *exitAlreadySplit,
        bool *enterAlreadySplit,
        bfx::Array<bfx::DVert *> *newVerts,
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
        _BYTE *a28,
        int a29,
        bfx::Array<bfx::Space *> *a30)
{
  bfx::DEdge *v31; // r30
  int v37; // r10
  double m_x; // fp0
  bfx::DEdge *v39; // r10
  bfx::DEdge *v41; // [sp+50h] [-60h] BYREF
  bfx::DEdge *v42; // [sp+54h] [-5Ch] BYREF

  v31 = pExitEdge;
  if ( !*exitAlreadySplit )
  {
    bfx::DGraph::SplitEdgeAtPos(this, pEdge: pExitEdge, pos: exitPos);
    v31 = v31->m_pNext;
    bfx::Array<bfx::Portal *>::push_back(this: a30, val: (bfx::Space **)&v31->m_pStartVert);
    *exitAlreadySplit = true;
  }
  if ( *a28 == 0 )
  {
    bfx::DGraph::SplitEdgeAtPos(this, pEdge: pEnterEdge, pos: enterPos);
    pEnterEdge = pEnterEdge->m_pNext;
    bfx::Array<bfx::Portal *>::push_back(this: a30, val: (bfx::Space **)&pEnterEdge->m_pStartVert);
    *a28 = 1;
  }
  bfx::DGraph::SpliceBetweenEdges(this, pEdgeA: v31, pEdgeB: pEnterEdge, pNewEdgeToA: &v42, pNewEdgeToB: &v41);
  v37 = (planeIndex << 15) & 0x78000;
  *((_DWORD *)v42 + 18) |= 0x80000u;
  *((_DWORD *)v41 + 18) |= 0x80000u;
  *((_DWORD *)v42 + 18) = *((_DWORD *)v42 + 18) & 0xFFF87FFF | v37;
  *((_DWORD *)v41 + 18) = *((_DWORD *)v41 + 18) & 0xFFF87FFF | v37;
  m_x = pEnterEdge->m_srcStaticAreaNormal.m_x;
  v42->m_pSrcStaticArea = pEnterEdge->m_pSrcStaticArea;
  v41->m_pSrcStaticArea = v31->m_pSrcStaticArea;
  v39 = v42;
  v42->m_srcStaticAreaNormal.m_x = m_x;
  v39->m_srcStaticAreaNormal.m_y = pEnterEdge->m_srcStaticAreaNormal.m_y;
  v39->m_srcStaticAreaNormal.m_z = pEnterEdge->m_srcStaticAreaNormal.m_z;
  v41->m_srcStaticAreaNormal = v31->m_srcStaticAreaNormal;
  v42->m_pInitialObstacles = pEnterEdge->m_pInitialObstacles;
  v41->m_pInitialObstacles = v31->m_pInitialObstacles;
  *((_DWORD *)v41 + 18) = (obID << 20) | *((_DWORD *)v41 + 18) & 0xFFFFF;
  idPhysics_StaticMulti::UpdateTime((bfx::BinaryReplayLogOut *)this);
  return v41;
}


// ========================================================================
// ?ClipEdgeLoops@DGraph@bfx@@AAAXABV?$Array@VClipRecord@bfx@@@2@HHAAV?$Array@PAVDVert@bfx@@@2@@Z
// EA  : 0x832C4730
// RVA : 0x012C4730
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void __fastcall bfx::DGraph::ClipEdgeLoops(
        bfx::DGraph *this,
        const bfx::Array<bfx::ClipRecord> *clipRecords,
        int planeIndex,
        int obID,
        bfx::Array<bfx::Space *> *newVerts)
{
  int v10; // r31
  int v11; // r30
  bfx::ClipRecord *v12; // r11
  bfx::EDat *m_pExit; // r6
  bfx::DEdge *m_pTwin; // r4
  bfx::EDat *m_pEnter; // r10
  bfx::DEdge *m_pEdge; // r5
  bool *v17; // [sp+8h] [-98h]
  bfx::Array<bfx::DVert *> *v18; // [sp+Ch] [-94h]
  int v19; // [sp+10h] [-90h]
  int v20; // [sp+14h] [-8Ch]
  int v21; // [sp+18h] [-88h]
  int v22; // [sp+1Ch] [-84h]
  int v23; // [sp+20h] [-80h]
  int v24; // [sp+24h] [-7Ch]
  int v25; // [sp+28h] [-78h]
  int v26; // [sp+2Ch] [-74h]
  int v27; // [sp+30h] [-70h]
  int v28; // [sp+34h] [-6Ch]
  int v29; // [sp+38h] [-68h]
  int v30; // [sp+3Ch] [-64h]
  int v31; // [sp+40h] [-60h]
  int v32; // [sp+44h] [-5Ch]
  int v33; // [sp+48h] [-58h]
  int v34; // [sp+4Ch] [-54h]
  int v35; // [sp+50h] [-50h]
  int v36; // [sp+58h] [-48h]

  v10 = 0;
  if ( clipRecords->m_size > 0 )
  {
    v11 = 0;
    do
    {
      v12 = &clipRecords->m_data[v11];
      m_pExit = v12->m_pExit;
      if ( v12->m_pExit->m_type != EDAT_EXIT )
        m_pTwin = m_pExit->m_pEdge->m_pTwin;
      else
        m_pTwin = m_pExit->m_pEdge;
      m_pEnter = v12->m_pEnter;
      if ( m_pEnter->m_type == EDAT_ENTER )
        m_pEdge = m_pEnter->m_pEdge;
      else
        m_pEdge = m_pEnter->m_pEdge->m_pTwin;
      bfx::DGraph::SpliceBetweenExitAndEnterPoints(
        this,
        pExitEdge: m_pTwin,
        pEnterEdge: m_pEdge,
        exitPos: &m_pExit->m_pos,
        enterPos: &v12->m_pEnter->m_pos,
        planeIndex,
        obID,
        exitAlreadySplit: &m_pExit->m_alreadySplit,
        enterAlreadySplit: v17,
        newVerts: v18,
        a11: v19,
        a12: v20,
        a13: v21,
        a14: v22,
        a15: v23,
        a16: v24,
        a17: v25,
        a18: v26,
        a19: v27,
        a20: v28,
        a21: v29,
        a22: v30,
        a23: v31,
        a24: v32,
        a25: v33,
        a26: v34,
        a27: v35,
        a28: &v12->m_pEnter->m_alreadySplit,
        a29: v36,
        a30: newVerts);
      idPhysics_StaticMulti::UpdateTime((bfx::BinaryReplayLogOut *)this);
      ++v10;
      ++v11;
    }
    while ( v10 < clipRecords->m_size );
  }
}


// ========================================================================
// ?AddClipRecordsForEdgeLoop@bfx@@YAXPAVDEdge@1@ABV?$FArray@VPlane@bfx@@$0M@@1@HPAVPool@1@AAV?$Array@PAVEDat@bfx@@@1@AAV?$Array@VClipRecord@bfx@@@1@@Z
// EA  : 0x832C4800
// RVA : 0x012C4800
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void __fastcall bfx::AddClipRecordsForEdgeLoop(
        bfx::DEdge *pStartEdge,
        const bfx::FArray<bfx::Plane,12> *clipPlanes,
        int planeIndex,
        bfx::Pool *pEDatPool,
        bfx::Array<bfx::Space *> *edgeMap,
        bfx::Array<bfx::ReplayLogListenerEntry> *clipRecords)
{
  const bfx::Plane *v9; // r25
  bfx::DEdge *ExitEdge; // r3
  bfx::DEdge *v11; // r23
  bfx::Pool::Node *v12; // r31
  int m_size; // r7
  int v14; // r9
  bfx::EDat **m_data; // r8
  int v16; // r11
  bfx::Pool::Node *Node; // r3
  float m_x; // r11
  bfx::Space *v19; // r30
  float m_y; // r10
  float m_z; // r9
  bfx::ReplayListener *v22; // r29
  bfx::Pool::Node *m_pNext; // r11
  bfx::Pool::Node *v24; // r30
  int v25; // r7
  int v26; // r9
  int v27; // r11
  bfx::EDat *v28; // r10
  bfx::Pool::Node *v29; // r3
  float v30; // r11
  bfx::Space *v31; // r31
  float v32; // r10
  float v33; // r9
  bfx::Pool::Node *v34; // r11
  bfx::Space *v35[2]; // [sp+50h] [-90h] BYREF
  bfx::ReplayLogListenerEntry v36; // [sp+58h] [-88h] BYREF
  bfx::Vec3 v37; // [sp+60h] [-80h] BYREF
  bfx::Vec3 v38; // [sp+70h] [-70h] BYREF

  v9 = &clipPlanes->m_data[planeIndex];
  ExitEdge = bfx::GetExitEdge(pStartEdge);
  v11 = ExitEdge;
  if ( ExitEdge != nullptr )
  {
    v12 = (bfx::Pool::Node *)ExitEdge;
    do
    {
      if ( ((int)v12[18].m_pNext & 0x40) != 0 && (m_size = edgeMap->m_size, v14 = 0, m_size > 0) )
      {
        m_data = (bfx::EDat **)edgeMap->m_data;
        v16 = 0;
        while ( (bfx::Pool::Node *)m_data[v16]->m_pEdge->m_pTwin != v12 )
        {
          ++v14;
          ++v16;
          if ( v14 >= m_size )
            goto LABEL_8;
        }
        v22 = (bfx::ReplayListener *)m_data[v16];
      }
      else
      {
LABEL_8:
        bfx::DGraph_CollideLineAndPlane(
          result: &v37,
          v0: (const bfx::Vec3 *)&v12[2].m_pNext[2],
          v1: (const bfx::Vec3 *)&v12[5].m_pNext[2].m_pNext[2],
          plane: v9);
        Node = bfx::Pool::GetNode(this: pEDatPool);
        if ( Node != nullptr )
        {
          m_x = v37.m_x;
          v19 = (bfx::Space *)Node;
          m_y = v37.m_y;
          m_z = v37.m_z;
          Node->m_pNext = v12;
          Node[1].m_pNext = nullptr;
          HIBYTE(Node[5].m_pNext) = 0;
          *(float *)&Node[2].m_pNext = m_x;
          *(float *)&Node[3].m_pNext = m_y;
          *(float *)&Node[4].m_pNext = m_z;
        }
        else
        {
          v19 = nullptr;
        }
        v35[0] = v19;
        bfx::Array<bfx::Portal *>::push_back(this: edgeMap, val: v35);
        m_pNext = v12[3].m_pNext;
        v22 = (bfx::ReplayListener *)v19;
        v12[18].m_pNext = (bfx::Pool::Node *)((int)v12[18].m_pNext | 0x40);
        m_pNext[18].m_pNext = (bfx::Pool::Node *)((int)m_pNext[18].m_pNext | 0x40);
      }
      v24 = v12[5].m_pNext;
      if ( v24 == v12 )
      {
LABEL_17:
        v24 = nullptr;
      }
      else
      {
        while ( ((int)v24[2].m_pNext[6].m_pNext & 0x20000000) != 0
             || ((int)v24[5].m_pNext[2].m_pNext[6].m_pNext & 0x20000000) == 0 )
        {
          v24 = v24[5].m_pNext;
          if ( v24 == v12 )
            goto LABEL_17;
        }
      }
      if ( ((int)v24[18].m_pNext & 0x40) != 0 && (v25 = edgeMap->m_size, v26 = 0, v25 > 0) )
      {
        v27 = 0;
        while ( 1 )
        {
          v28 = (bfx::EDat *)edgeMap->m_data[v27];
          if ( (bfx::Pool::Node *)v28->m_pEdge->m_pTwin == v24 )
            break;
          ++v26;
          ++v27;
          if ( v26 >= v25 )
            goto LABEL_23;
        }
      }
      else
      {
LABEL_23:
        bfx::DGraph_CollideLineAndPlane(
          result: &v38,
          v0: (const bfx::Vec3 *)&v24[2].m_pNext[2],
          v1: (const bfx::Vec3 *)&v24[5].m_pNext[2].m_pNext[2],
          plane: v9);
        v29 = bfx::Pool::GetNode(this: pEDatPool);
        if ( v29 != nullptr )
        {
          v30 = v38.m_x;
          v31 = (bfx::Space *)v29;
          v32 = v38.m_y;
          v33 = v38.m_z;
          v29->m_pNext = v24;
          v29[1].m_pNext = (bfx::Pool::Node *)1;
          HIBYTE(v29[5].m_pNext) = 0;
          *(float *)&v29[2].m_pNext = v30;
          *(float *)&v29[3].m_pNext = v32;
          *(float *)&v29[4].m_pNext = v33;
        }
        else
        {
          v31 = nullptr;
        }
        v35[0] = v31;
        bfx::Array<bfx::Portal *>::push_back(this: edgeMap, val: v35);
        v34 = v24[3].m_pNext;
        v28 = (bfx::EDat *)v31;
        v24[18].m_pNext = (bfx::Pool::Node *)((int)v24[18].m_pNext | 0x40);
        v34[18].m_pNext = (bfx::Pool::Node *)((int)v34[18].m_pNext | 0x40);
      }
      v36.m_pListener = v22;
      *(_DWORD *)&v36.m_clientOwned = v28;
      bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(this: clipRecords, val: &v36);
      v12 = v24;
      while ( ((int)v12[2].m_pNext[6].m_pNext & 0x20000000) == 0
           || ((int)v12[5].m_pNext[2].m_pNext[6].m_pNext & 0x20000000) != 0 )
      {
        v12 = v12[5].m_pNext;
        if ( v12 == v24 )
        {
          v12 = nullptr;
          break;
        }
      }
    }
    while ( v12 != (bfx::Pool::Node *)v11 );
  }
}


// ========================================================================
// ?CollectClipRecords@bfx@@YAXPAVListNode@1@ABV?$FArray@VPlane@bfx@@$0M@@1@HPAVPool@1@AAV?$Array@PAVEDat@bfx@@@1@AAV?$Array@VClipRecord@bfx@@@1@@Z
// EA  : 0x832C4AA8
// RVA : 0x012C4AA8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void __fastcall bfx::CollectClipRecords(
        bfx::ListNode *pHeadEdgeNode,
        const bfx::FArray<bfx::Plane,12> *clipPlanes,
        int planeIndex,
        bfx::Pool *pEDatPool,
        bfx::Array<bfx::Space *> *edgeMap,
        bfx::Array<bfx::ReplayLogListenerEntry> *clipRecords)
{
  bfx::ListNode *i; // r11
  bfx::ListNode *j; // r31
  bfx::ListNode *m_pNextListNode; // r11
  bfx::ListNode *m_pPrevListNode; // r11

  for ( i = pHeadEdgeNode; i != nullptr; i = i->m_pNextListNode )
    i[9].m_pNextListNode = (bfx::ListNode *)((int)i[9].m_pNextListNode & 0xFFFFFEBF);
  for ( j = pHeadEdgeNode; j != nullptr; j = j->m_pNextListNode )
  {
    m_pNextListNode = j[9].m_pNextListNode;
    if ( ((unsigned __int16)m_pNextListNode & 0x100) == 0 && ((unsigned __int16)m_pNextListNode & 0x800) == 0 )
    {
      bfx::AddClipRecordsForEdgeLoop(
        pStartEdge: (bfx::DEdge *)j,
        clipPlanes,
        planeIndex,
        pEDatPool,
        edgeMap,
        clipRecords);
      m_pPrevListNode = j;
      do
      {
        m_pPrevListNode[9].m_pNextListNode = (bfx::ListNode *)((int)m_pPrevListNode[9].m_pNextListNode | 0x100);
        m_pPrevListNode = m_pPrevListNode[2].m_pPrevListNode;
      }
      while ( m_pPrevListNode != j );
    }
  }
}


// ========================================================================
// ?ClipGraphAgainstPlane@DGraph@bfx@@AAA_NABV?$FArray@VPlane@bfx@@$0M@@2@HHPAVPool@2@@Z
// EA  : 0x832C4B70
// RVA : 0x012C4B70
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

int __fastcall bfx::DGraph::ClipGraphAgainstPlane(
        bfx::DGraph *this,
        const bfx::FArray<bfx::Plane,12> *clipPlanes,
        int planeIndex,
        int obID,
        bfx::Pool *pEDatPool)
{
  bfx::ListNode *m_pHeadVertNode; // r11
  int i; // r21
  int v12; // r9
  unsigned int v13; // r10
  char *m_data; // r22
  int m_size; // r25
  bfx::Space **v16; // r26
  double v17; // fp28
  bfx::Space *v18; // r30
  int v19; // r29
  bool v20; // r9
  float m_z; // r11
  char v22; // r10
  bool v23; // r8
  unsigned int v24; // r10
  int v25; // r10
  int v26; // r5
  float *p_m_y; // r6
  double v28; // fp31
  double v29; // fp0
  double v30; // fp30
  double v31; // fp2
  double v32; // fp29
  bfx::DVert *AdjVertFurthestFromPlane; // r3
  double v34; // fp1
  char *v35; // r29
  int v36; // ctr
  bfx::Pool::Node **v37; // r10
  bfx::Pool::Node *v38; // r11
  bfx::Array<bfx::Space *> v40; // [sp+60h] [-D0h] BYREF
  bfx::Array<bfx::Space *> v41; // [sp+70h] [-C0h] BYREF
  bfx::Array<bfx::ReplayLogListenerEntry> v42[5]; // [sp+80h] [-B0h] BYREF

  m_pHeadVertNode = this->m_pHeadVertNode;
  for ( i = 1; m_pHeadVertNode != nullptr; m_pHeadVertNode = m_pHeadVertNode->m_pNextListNode )
  {
    v12 = (float)((float)(clipPlanes->m_data[planeIndex].m_normal.m_x * *(float *)&m_pHeadVertNode[1].m_pNextListNode)
                + (float)((float)(*(float *)&m_pHeadVertNode[2].m_pNextListNode
                                * clipPlanes->m_data[planeIndex].m_normal.m_z)
                        + (float)(*(float *)&m_pHeadVertNode[1].m_pPrevListNode
                                * clipPlanes->m_data[planeIndex].m_normal.m_y))) >= (double)clipPlanes->m_data[planeIndex].m_d;
    v13 = (v12 << 29) & 0x20000000 | (int)m_pHeadVertNode[3].m_pNextListNode & 0xDFFFFFFF;
    m_pHeadVertNode[3].m_pNextListNode = (bfx::ListNode *)v13;
    if ( ((v12 << 29) & 0x20000000) == 0 )
      m_pHeadVertNode[3].m_pNextListNode = (bfx::ListNode *)(v13 | 0x80000000);
  }
  memset(&v41, 0, 12);
  v41.m_tag = bfx::MEM_BFXPLANNER;
  v42[0].m_tag = bfx::MEM_BFXPLANNER;
  memset(v42, 0, 12);
  bfx::CollectClipRecords(
    pHeadEdgeNode: this->m_pHeadEdgeNode,
    clipPlanes,
    planeIndex,
    pEDatPool,
    edgeMap: &v41,
    clipRecords: v42);
  memset(&v40, 0, 12);
  v40.m_tag = bfx::MEM_BFXPLANNER;
  bfx::DGraph::ClipEdgeLoops(
    this,
    clipRecords: (const bfx::Array<bfx::ClipRecord> *)v42,
    planeIndex,
    obID,
    newVerts: &v40);
  m_data = (char *)v40.m_data;
  if ( v40.m_size > 0 )
  {
    m_size = v40.m_size;
    v16 = v40.m_data;
    v17 = MIN_SAFE_FLOAT_FRACTION;
    do
    {
      v18 = *v16;
      v19 = -1;
      v20 = true;
      m_z = (*v16)->m_pos.m_z;
      v22 = _cntlzw(LODWORD(m_z));
      v23 = (v22 & 0x20) != 0;
      if ( (v22 & 0x20) == 0 )
      {
        while ( 1 )
        {
          v24 = *(_DWORD *)(LODWORD(m_z) + 72);
          if ( (v24 & 0x80000) != 0 )
          {
            v25 = (v24 >> 15) & 0xF;
            if ( v25 != planeIndex )
              break;
          }
          if ( v20 )
            m_z = *(float *)(LODWORD(m_z) + 12);
          else
            m_z = *(float *)(LODWORD(m_z) + 20);
          if ( LODWORD(m_z) == LODWORD((*v16)->m_pos.m_z) )
            v23 = true;
          v20 = (_cntlzw(v20) & 0x20) != 0;
          if ( v23 )
            goto LABEL_18;
        }
        v19 = v25;
      }
LABEL_18:
      v26 = 0;
      if ( planeIndex > 0 )
      {
        p_m_y = &clipPlanes->m_data[0].m_normal.m_y;
        do
        {
          if ( v26 != v19 )
          {
            v28 = p_m_y[1];
            v29 = __fabs(p_m_y[2]);
            v30 = *(p_m_y - 1);
            v31 = (float)((float)((float)(*(float *)&v18->m_spaceID * *(p_m_y - 1))
                                + (float)((float)(v18->m_pos.m_y * p_m_y[1]) + (float)(v18->m_pos.m_x * *p_m_y)))
                        - p_m_y[2]);
            if ( v29 > 1.0842022e-19 )
            {
              v32 = (float)((float)1.0 / (float)v29);
              if ( __fabs((float)((float)((float)1.0 / (float)v29)
                                * (float)((float)((float)(*(float *)&v18->m_spaceID * *(p_m_y - 1))
                                                + (float)((float)(v18->m_pos.m_y * p_m_y[1])
                                                        + (float)(v18->m_pos.m_x * *p_m_y)))
                                        - p_m_y[2]))) <= v17 )
              {
                AdjVertFurthestFromPlane = bfx::GetAdjVertFurthestFromPlane(
                                             pVert: (bfx::DVert *)v18,
                                             plane: (const bfx::Plane *)(p_m_y - 1));
                if ( AdjVertFurthestFromPlane != nullptr )
                  v31 = (float)((float)((float)(AdjVertFurthestFromPlane->m_pos.m_x * (float)v30)
                                      + (float)((float)(AdjVertFurthestFromPlane->m_pos.m_z * (float)v28)
                                              + (float)(AdjVertFurthestFromPlane->m_pos.m_y * (float)v34)))
                              - p_m_y[2]);
                if ( __fabs((float)((float)v32 * (float)v31)) <= v17 )
                  i = 0;
              }
            }
            if ( v31 < 0.0 )
              LODWORD(v18->m_rotSpaceToWorld.m_w) |= 0x80000000;
          }
          ++v26;
          p_m_y += 4;
        }
        while ( v26 < planeIndex );
      }
      --m_size;
      ++v16;
    }
    while ( m_size != 0 );
  }
  v35 = (char *)v41.m_data;
  if ( v41.m_size > 0 )
  {
    v36 = v41.m_size;
    v37 = (bfx::Pool::Node **)(v41.m_data - 1);
    do
    {
      v38 = *++v37;
      v38->m_pNext = pEDatPool->m_data.m_pUnused;
      pEDatPool->m_data.m_pUnused = v38;
      --v36;
    }
    while ( v36 != 0 );
  }
  if ( m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
  if ( v42[0].m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v42[0].m_data);
  if ( v35 != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v35);
  return i;
}


// ========================================================================
// __unwind$19067
// EA  : 0x832C4EE0
// RVA : 0x012C4EE0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void _unwind_19067()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 304 + 112));
}


// ========================================================================
// __unwind$19068
// EA  : 0x832C4F08
// RVA : 0x012C4F08
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void _unwind_19068()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 304 + 128));
}


// ========================================================================
// __unwind$19069
// EA  : 0x832C4F30
// RVA : 0x012C4F30
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void _unwind_19069()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 304 + 96));
}


// ========================================================================
// ?ClipGraphAgainstObstacle@DGraph@bfx@@AAA_NABV?$FArray@VPlane@bfx@@$0M@@2@HM@Z
// EA  : 0x832C4F60
// RVA : 0x012C4F60
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

int __fastcall bfx::DGraph::ClipGraphAgainstObstacle(
        bfx::DGraph *this,
        const bfx::FArray<bfx::Plane,12> *origClipPlanes,
        int obID,
        double expandRadius)
{
  float *v8; // r10
  float *v9; // r11
  int v10; // r30
  bfx::Pool v12; // [sp+50h] [-120h] BYREF
  _OWORD v13[13]; // [sp+70h] [-100h] BYREF

  bfx::Pool::Pool(this: &v12, nodeSize: 0x18u, numNodes: 0x64u, tag: bfx::MEM_BFXPLANNER);
  bfx::FArray<bfx::Plane,12>::FArray<bfx::Plane,12>(this: (bfx::FArray<bfx::Plane,12> *)v13, rhs: origClipPlanes);
  v8 = (float *)&v13[HIDWORD(v13[12])];
  if ( v13 != (_OWORD *)v8 )
  {
    v9 = (float *)v13 + 3;
    do
    {
      *v9 = *v9 - (float)expandRadius;
      v9 += 4;
    }
    while ( v9 - 3 != v8 );
  }
  v10 = 0;
  if ( SHIDWORD(v13[12]) <= 0 )
  {
LABEL_7:
    bfx::Pool::~Pool(this: &v12);
    return 1;
  }
  else
  {
    while ( (unsigned __int8)bfx::DGraph::ClipGraphAgainstPlane(
                               this,
                               clipPlanes: (const bfx::FArray<bfx::Plane,12> *)v13,
                               planeIndex: v10,
                               obID,
                               pEDatPool: &v12) != 0 )
    {
      if ( ++v10 >= SHIDWORD(v13[12]) )
        goto LABEL_7;
    }
    bfx::Pool::~Pool(this: &v12);
    return 0;
  }
}


// ========================================================================
// __unwind$19297
// EA  : 0x832C5050
// RVA : 0x012C5050
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void _unwind_19297()
{
  int v0; // r12

  bfx::Pool::~Pool(this: (bfx::Pool *)(v0 - 368 + 80));
}


// ========================================================================
// ?SearchToOriginalGraph@bfx@@YAPAVDEdge@1@PAV21@W4EdgeSearchMode@1@@Z
// EA  : 0x832C5080
// RVA : 0x012C5080
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

bfx::DEdge *__fastcall bfx::SearchToOriginalGraph(
        bfx::Space *pStartEdge,
        bfx::EdgeSearchMode mode,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        bfx::Space *a12)
{
  float v14; // r25
  int m_size; // r11
  int v16; // r28
  bfx::Space *v17; // r29
  float m_w; // r30
  int v19; // r11
  char *m_data; // r4
  bfx::Space **v22; // r10
  int i; // ctr
  char *v24; // r4
  bfx::Space **v25; // r10
  int j; // ctr
  bfx::Space *v27[4]; // [sp+50h] [-70h] BYREF
  bfx::Array<bfx::Space *> v28; // [sp+60h] [-60h] BYREF
  bfx::Array<bfx::Space *> v29[5]; // [sp+70h] [-50h] BYREF

  a12 = pStartEdge;
  memset(&v28, 0, 12);
  v14 = 0.0;
  v28.m_tag = bfx::MEM_BFXPLANNER;
  v29[0].m_tag = bfx::MEM_BFXPLANNER;
  memset(v29, 0, 12);
  bfx::Array<bfx::Portal *>::push_back(this: &v28, val: &a12);
  LODWORD(pStartEdge->m_matSpaceToWorld.m_data[3]) |= 0x80u;
  bfx::Array<bfx::Portal *>::push_back(this: v29, val: &a12);
  m_size = v28.m_size;
  if ( v28.m_size != 0 )
  {
    while ( 2 )
    {
      v28.m_size = m_size - 1;
      v16 = 0;
      v17 = v28.m_data[m_size - 1];
      do
      {
        if ( v16 != 0 )
        {
          if ( v16 == 1 )
            m_w = v17->m_rotSpaceToWorld.m_w;
          else
            m_w = v17->m_pos.m_x;
        }
        else
        {
          m_w = v17->m_pos.m_z;
        }
        v19 = *(_DWORD *)(LODWORD(m_w) + 72);
        v27[0] = (bfx::Space *)LODWORD(m_w);
        if ( (v19 & 0x200) != 0 )
        {
          if ( (v19 & 0x80) == 0 && ((v19 & 0x20) == 0 || mode == EDGE_SEARCH_MODE_2) )
          {
            *(_DWORD *)(LODWORD(m_w) + 72) |= 0x80u;
            bfx::Array<bfx::Portal *>::push_back(this: v29, val: v27);
            bfx::Array<bfx::Portal *>::push_back(this: &v28, val: v27);
          }
        }
        else
        {
          if ( mode != EDGE_SEARCH_MODE_1 )
          {
            m_data = (char *)v29[0].m_data;
            if ( v29[0].m_size > 0 )
            {
              v22 = v29[0].m_data - 1;
              for ( i = v29[0].m_size; i != 0; --i )
                LODWORD((*++v22)->m_matSpaceToWorld.m_data[3]) &= ~0x80u;
            }
            if ( m_data != nullptr )
              bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
            if ( v28.m_data != nullptr )
              bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v28.m_data);
            return (bfx::DEdge *)LODWORD(m_w);
          }
          v14 = m_w;
        }
        ++v16;
      }
      while ( v16 <= 2 );
      m_size = v28.m_size;
      if ( v28.m_size != 0 )
        continue;
      break;
    }
  }
  if ( mode != EDGE_SEARCH_MODE_1 )
  {
    v24 = (char *)v29[0].m_data;
    if ( v29[0].m_size > 0 )
    {
      v25 = v29[0].m_data - 1;
      for ( j = v29[0].m_size; j != 0; --j )
        LODWORD((*++v25)->m_matSpaceToWorld.m_data[3]) &= ~0x80u;
    }
    if ( v24 != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v24);
    if ( v28.m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v28.m_data);
    return nullptr;
  }
  else
  {
    if ( v29[0].m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v29[0].m_data);
    if ( v28.m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v28.m_data);
    return (bfx::DEdge *)LODWORD(v14);
  }
}


// ========================================================================
// __unwind$19384
// EA  : 0x832C52CC
// RVA : 0x012C52CC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void _unwind_19384()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 192 + 96));
}


// ========================================================================
// __unwind$19385
// EA  : 0x832C52F4
// RVA : 0x012C52F4
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void _unwind_19385()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 192 + 112));
}


// ========================================================================
// ?FindFutureHoles@bfx@@YAXABV?$Array@PAVDEdge@bfx@@@1@AAV?$Array@VHoleRecord@bfx@@@1@@Z
// EA  : 0x832C5328
// RVA : 0x012C5328
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void __fastcall bfx::FindFutureHoles(
        const bfx::Array<bfx::DEdge *> *newEdgesToKeep,
        bfx::Array<bfx::ReplayLogListenerEntry> *holesCreated,
        unsigned int a3,
        int a4,
        bfx::DEdge *a5,
        bfx::DEdge **a6)
{
  char *m_data; // r27
  int m_size; // r9
  bfx::ReplayListener *m_pListener; // r11
  int v11; // r28
  int v12; // r29
  bfx::ReplayListener *v13; // r3
  bfx::ReplayListener_vtbl *v14; // r11
  int v15; // r10
  int v16; // r11
  bfx::Space **v17; // r29
  int i; // r28
  bfx::Space *v19; // r30
  bfx::ReplayListener *v20; // r3
  int v21; // [sp+8h] [-A8h]
  int v22; // [sp+Ch] [-A4h]
  int v23; // [sp+10h] [-A0h]
  bfx::Space *v24; // [sp+14h] [-9Ch]
  bfx::ReplayLogListenerEntry v25[2]; // [sp+50h] [-60h] BYREF
  bfx::Array<bfx::Space *> v26; // [sp+60h] [-50h] BYREF

  m_data = nullptr;
  m_size = 0;
  memset(&v26, 0, 12);
  v26.m_tag = bfx::MEM_BFXPLANNER;
  v11 = 0;
  v25[0].m_pListener = (bfx::ReplayListener *)newEdgesToKeep->m_size;
  m_pListener = v25[0].m_pListener;
  if ( (int)v25[0].m_pListener > 0 )
  {
    v12 = 0;
    do
    {
      v13 = (bfx::ReplayListener *)newEdgesToKeep->m_data[v12];
      v14 = v13[18].__vftable;
      v25[0].m_pListener = v13;
      if ( ((unsigned __int8)v14 & 0x80) == 0
        && ((unsigned int)v14 & 0xFFF00000) == 0
        && bfx::SearchToOriginalGraph(
             pStartEdge: (bfx::Space *)v13,
             mode: EDGE_SEARCH_MODE_1,
             a3,
             a4,
             (int)a5,
             (int)a6,
             a7: m_size,
             a8: 0,
             a9: v21,
             a10: v22,
             a11: v23,
             a12: v24) == nullptr )
      {
        bfx::Array<bfx::Portal *>::push_back(this: &v26, val: (bfx::Space **)v25);
      }
      ++v11;
      ++v12;
      v25[0].m_pListener = (bfx::ReplayListener *)newEdgesToKeep->m_size;
      m_pListener = v25[0].m_pListener;
    }
    while ( v11 < (int)v25[0].m_pListener );
    m_size = v26.m_size;
    m_data = (char *)v26.m_data;
  }
  v15 = 0;
  v25[0].m_pListener = m_pListener;
  if ( (int)m_pListener > 0 )
  {
    v16 = 0;
    do
    {
      a6 = newEdgesToKeep->m_data;
      ++v15;
      a5 = newEdgesToKeep->m_data[v16++];
      a4 = *((_DWORD *)a5 + 18);
      a3 = a4 & 0xFFFFFF7F;
      *((_DWORD *)a5 + 18) = a4 & 0xFFFFFF7F;
    }
    while ( v15 < newEdgesToKeep->m_size );
  }
  if ( m_size > 0 )
  {
    v17 = (bfx::Space **)m_data;
    for ( i = m_size; i != 0; --i )
    {
      v19 = *v17;
      v20 = (bfx::ReplayListener *)bfx::SearchToOriginalGraph(
                                     pStartEdge: *v17,
                                     mode: EDGE_SEARCH_MODE_2,
                                     a3,
                                     a4,
                                     (int)a5,
                                     (int)a6,
                                     a7: m_size,
                                     a8: v15,
                                     a9: v21,
                                     a10: v22,
                                     a11: v23,
                                     a12: v24);
      if ( v20 != nullptr )
      {
        v25[0].m_pListener = v20;
        *(_DWORD *)&v25[0].m_clientOwned = v19;
        bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(this: holesCreated, val: v25);
      }
      ++v17;
    }
  }
  if ( m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
}


// ========================================================================
// __unwind$19645
// EA  : 0x832C5488
// RVA : 0x012C5488
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void _unwind_19645()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 176 + 96));
}


// ========================================================================
// ?RemoveNewEdgesAndVertsOutsideObstacle@DGraph@bfx@@AAAXAAV?$Array@VHoleRecord@bfx@@@2@@Z
// EA  : 0x832C54B8
// RVA : 0x012C54B8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void __fastcall bfx::DGraph::RemoveNewEdgesAndVertsOutsideObstacle(
        bfx::DGraph *this,
        bfx::Array<bfx::ReplayLogListenerEntry> *holesCreated)
{
  bfx::DEdge **v4; // r8
  bfx::DEdge *v5; // r7
  int v6; // r6
  unsigned int v7; // r5
  bfx::ListNode *i; // r30
  bfx::ListNode *m_pNextListNode; // r11
  bfx::Array<bfx::SpaceComponent *> *v10; // r3
  bfx::bfxMemTag v11; // r11
  int m_size; // r30
  char *m_data; // r23
  bfx::DEdge **v14; // r29
  int v15; // r5
  bfx::ListNode *m_pHeadVertNode; // r30
  char *j; // r27
  int v18; // r4
  int v19; // r4
  bool v20; // zf
  bfx::DVert **v21; // r29
  int k; // r28
  bfx::DVert *v23; // r30
  bfx::DEdge *m_pIncidentEdge; // r3
  bfx::ListNode *v25; // [sp+50h] [-A0h] BYREF
  bfx::Array<bfx::SpaceComponent *> v26; // [sp+60h] [-90h] BYREF
  bfx::Array<bfx::DFace *> v27; // [sp+70h] [-80h] BYREF
  bfx::Array<bfx::SpaceComponent *> v28; // [sp+80h] [-70h] BYREF
  bfx::Array<bfx::SpaceComponent *> v29[6]; // [sp+90h] [-60h] BYREF

  memset(&v28, 0, 12);
  v28.m_tag = bfx::MEM_BFXPLANNER;
  bfx::Array<bfx::Edge *>::expand_cap(this: &v28, size: 20);
  memset(v29, 0, 12);
  v29[0].m_tag = bfx::MEM_BFXPLANNER;
  bfx::Array<bfx::Edge *>::expand_cap(this: v29, size: 20);
  for ( i = this->m_pHeadEdgeNode; i != nullptr; i = i->m_pNextListNode )
  {
    m_pNextListNode = i[9].m_pNextListNode;
    v25 = i;
    if ( ((unsigned __int16)m_pNextListNode & 0x200) != 0 && ((unsigned __int8)m_pNextListNode & 0x20) == 0 )
    {
      if ( (int)i[1].m_pNextListNode[3].m_pNextListNode < 0
        || (int)i[1].m_pPrevListNode[1].m_pNextListNode[3].m_pNextListNode < 0 )
      {
        v10 = &v28;
        i[9].m_pNextListNode = (bfx::ListNode *)((int)i[9].m_pNextListNode | 0x20);
        i[1].m_pPrevListNode[9].m_pNextListNode = (bfx::ListNode *)((int)i[1].m_pPrevListNode[9].m_pNextListNode | 0x20);
      }
      else
      {
        v10 = v29;
      }
      bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)v10, val: (bfx::Space **)&v25);
    }
  }
  bfx::FindFutureHoles(
    newEdgesToKeep: (const bfx::Array<bfx::DEdge *> *)v29,
    holesCreated,
    a3: v7,
    a4: v6,
    a5: v5,
    a6: v4);
  v11 = bfx::MEM_BFXPLANNER;
  memset(&v27, 0, 12);
  v27.m_tag = bfx::MEM_BFXPLANNER;
  m_data = (char *)v28.m_data;
  m_size = v28.m_size;
  if ( v28.m_size > 0 )
  {
    v14 = (bfx::DEdge **)(v28.m_data - 1);
    do
    {
      bfx::DGraph::DeleteEdgePair(this, pEdge: *++v14, facesDeleted: &v27);
      --m_size;
    }
    while ( m_size != 0 );
    v11 = bfx::MEM_BFXPLANNER;
  }
  v26.m_tag = v11;
  memset(&v26, 0, 12);
  bfx::Array<bfx::Edge *>::expand_cap(this: &v26, size: 20);
  v15 = v26.m_size;
  m_pHeadVertNode = this->m_pHeadVertNode;
  for ( j = (char *)v26.m_data; m_pHeadVertNode != nullptr; m_pHeadVertNode = m_pHeadVertNode->m_pNextListNode )
  {
    if ( ((int)m_pHeadVertNode[3].m_pNextListNode & 0x40000000) != 0
      && (unsigned __int8)bfx::ConnectsToNewEdge(pVert: (bfx::DVert *)m_pHeadVertNode) == 0 )
    {
      if ( v18 == v15 )
      {
        v20 = v18 != 0;
        v19 = 2 * v18;
        if ( !v20 )
          v19 = 1;
        bfx::Array<bfx::Edge *>::expand_cap(this: &v26, size: v19);
        v15 = v26.m_size;
        j = (char *)v26.m_data;
      }
      if ( &j[4 * v15] != nullptr )
        *(_DWORD *)&j[4 * v15] = m_pHeadVertNode;
      v26.m_size = ++v15;
    }
  }
  if ( v15 > 0 )
  {
    v21 = (bfx::DVert **)j;
    for ( k = v15; k != 0; --k )
    {
      v23 = *v21;
      m_pIncidentEdge = (*v21)->m_pIncidentEdge;
      if ( m_pIncidentEdge != nullptr )
      {
        bfx::UpdateHoleRecordsForEdgeDeletion(
          pEdgeBeingDeleted: m_pIncidentEdge,
          (bfx::Array<bfx::HoleRecord> *)holesCreated);
        bfx::UpdateHoleRecordsForEdgeDeletion(
          pEdgeBeingDeleted: v23->m_pIncidentEdge->m_pTwin,
          (bfx::Array<bfx::HoleRecord> *)holesCreated);
        bfx::DGraph::RemoveVertAndEdgePair(this, pDeleteMeVert: v23, pIncidentEdge: v23->m_pIncidentEdge);
      }
      else
      {
        bfx::DGraph::DestroyVert(this, pVert: *v21);
      }
      ++v21;
    }
  }
  if ( j != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: j);
  v27.m_size = 0;
  if ( v27.m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v27.m_data);
    v27.m_data = nullptr;
  }
  v27.m_cap = 0;
  if ( v29[0].m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v29[0].m_data);
  if ( m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
}


// ========================================================================
// __unwind$19784
// EA  : 0x832C5780
// RVA : 0x012C5780
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void _unwind_19784()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 240 + 128));
}


// ========================================================================
// __unwind$19785
// EA  : 0x832C57A8
// RVA : 0x012C57A8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void _unwind_19785()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 240 + 144));
}


// ========================================================================
// __unwind$19786
// EA  : 0x832C57D0
// RVA : 0x012C57D0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void _unwind_19786()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 240 + 112));
}


// ========================================================================
// __unwind$19787
// EA  : 0x832C57F8
// RVA : 0x012C57F8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void _unwind_19787()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 240 + 96));
}


// ========================================================================
// ?UpdateHoleRecordsForEdgeDeletion2@bfx@@YAXPAVDEdge@1@AAV?$Array@VHoleRecord@bfx@@@1@@Z
// EA  : 0x832C5820
// RVA : 0x012C5820
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void __fastcall bfx::UpdateHoleRecordsForEdgeDeletion2(
        bfx::DEdge *pEdgeBeingDeleted,
        bfx::Array<bfx::HoleRecord> *holesCreated)
{
  int v2; // r7
  int v3; // r8
  bfx::HoleRecord *v4; // r9
  bfx::DEdge *m_pNext; // r11
  bfx::DEdge *v6; // r11

  v2 = 0;
  if ( holesCreated->m_size > 0 )
  {
    v3 = 0;
    do
    {
      v4 = &holesCreated->m_data[v3];
      if ( v4->m_pEdgeA == pEdgeBeingDeleted )
      {
        m_pNext = pEdgeBeingDeleted->m_pNext;
        while ( (*((_DWORD *)m_pNext + 18) & 8) != 0 )
        {
          m_pNext = m_pNext->m_pTwin->m_pNext;
          if ( m_pNext == pEdgeBeingDeleted->m_pNext )
          {
            m_pNext = nullptr;
            break;
          }
        }
        v4->m_pEdgeA = m_pNext;
      }
      if ( v4->m_pEdgeB == pEdgeBeingDeleted )
      {
        v6 = pEdgeBeingDeleted->m_pNext;
        while ( (*((_DWORD *)v6 + 18) & 8) != 0 )
        {
          v6 = v6->m_pTwin->m_pNext;
          if ( v6 == pEdgeBeingDeleted->m_pNext )
          {
            v6 = nullptr;
            break;
          }
        }
        v4->m_pEdgeB = v6;
      }
      ++v2;
      ++v3;
    }
    while ( v2 < holesCreated->m_size );
  }
}


// ========================================================================
// ?ProcessPartitionClipVert@DGraph@bfx@@AAAXPAVDVert@2@AAV?$Array@VHoleRecord@bfx@@@2@@Z
// EA  : 0x832C58D8
// RVA : 0x012C58D8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void __fastcall bfx::DGraph::ProcessPartitionClipVert(
        bfx::DGraph *this,
        bfx::DVert *pVert,
        bfx::Array<bfx::HoleRecord> *holesCreated)
{
  bfx::DEdge *m_pIncidentEdge; // r10
  bfx::DEdge *v7; // r4
  bfx::DEdge *v8; // r27
  bfx::DEdge *m_pNext; // r11
  bfx::Array<bfx::HoleRecord> *v10; // r4
  bfx::Array<bfx::DFace *> v11[5]; // [sp+50h] [-50h] BYREF

  m_pIncidentEdge = pVert->m_pIncidentEdge;
  v8 = nullptr;
  m_pNext = m_pIncidentEdge;
  v7 = nullptr;
  do
  {
    if ( (*((_DWORD *)m_pNext + 18) & 0x4000) != 0 )
    {
      if ( v7 != nullptr )
        v8 = m_pNext;
      else
        v7 = m_pNext;
    }
    m_pNext = m_pNext->m_pTwin->m_pNext;
  }
  while ( m_pNext != m_pIncidentEdge );
  memset(v11, 0, 12);
  v11[0].m_tag = bfx::MEM_BFXPLANNER;
  if ( v7 != nullptr )
    bfx::DGraph::DeleteEdgePair(this, pEdge: v7, facesDeleted: v11);
  if ( v8 != nullptr )
    bfx::DGraph::DeleteEdgePair(this, pEdge: v8, facesDeleted: v11);
  bfx::UpdateHoleRecordsForEdgeDeletion2(pEdgeBeingDeleted: pVert->m_pIncidentEdge, holesCreated);
  bfx::UpdateHoleRecordsForEdgeDeletion2(pEdgeBeingDeleted: pVert->m_pIncidentEdge->m_pTwin, holesCreated: v10);
  bfx::DGraph::RemoveVertAndEdgePair(this, pDeleteMeVert: pVert, pIncidentEdge: pVert->m_pIncidentEdge);
  idPhysics_StaticMulti::UpdateTime(this: (bfx::BinaryReplayLogOut *)holesCreated);
  idPhysics_StaticMulti::UpdateTime((bfx::BinaryReplayLogOut *)this);
  v11[0].m_size = 0;
  if ( v11[0].m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v11[0].m_data);
}


// ========================================================================
// __unwind$20095
// EA  : 0x832C59E0
// RVA : 0x012C59E0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void _unwind_20095()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 160 + 80));
}


// ========================================================================
// ?GetObsoletePartitionEdges@DGraph@bfx@@AAAXAAV?$Array@PAVDEdge@bfx@@@2@@Z
// EA  : 0x832C5A08
// RVA : 0x012C5A08
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void __fastcall bfx::DGraph::GetObsoletePartitionEdges(
        bfx::DGraph *this,
        bfx::Array<bfx::SpaceComponent *> *obsoletePartitionEdges)
{
  bfx::ListNode *i; // r30
  int m_cap; // r10
  int m_size; // r11
  int v6; // r4
  bfx::DEdge **v7; // r11

  for ( i = this->m_pHeadEdgeNode; i != nullptr; i = i->m_pNextListNode )
  {
    if ( ((int)i[9].m_pNextListNode & 0x4000) != 0
      && (((int)i[1].m_pNextListNode[3].m_pNextListNode & 0x10000000) != 0
       || ((int)i[1].m_pPrevListNode[1].m_pNextListNode[3].m_pNextListNode & 0x10000000) != 0) )
    {
      m_cap = obsoletePartitionEdges->m_cap;
      m_size = obsoletePartitionEdges->m_size;
      if ( m_cap == m_size )
      {
        v6 = 2 * m_cap;
        if ( m_cap == 0 )
          v6 = 1;
        bfx::Array<bfx::Edge *>::expand_cap(this: obsoletePartitionEdges, size: v6);
        m_size = obsoletePartitionEdges->m_size;
      }
      v7 = (bfx::DEdge **)&obsoletePartitionEdges->m_data[m_size];
      if ( v7 != nullptr )
        *v7 = (bfx::DEdge *)i;
      ++obsoletePartitionEdges->m_size;
    }
  }
}


// ========================================================================
// ?FillIsland@bfx@@YAXPAVDVert@1@H@Z
// EA  : 0x832C5AE0
// RVA : 0x012C5AE0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void __fastcall bfx::FillIsland(
        bfx::Space *pStartVert,
        int islandNum,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        bfx::Space *a12)
{
  int v13; // r26
  int m_size; // r11
  bfx::Space **v15; // r8
  bool v16; // r9
  char v17; // r6
  float m_z; // r30
  bool v19; // r29
  float v20; // r27
  unsigned int v21; // r28
  int v22; // r11
  __int16 v23; // r10
  bfx::Space *v24; // [sp+50h] [-60h] BYREF
  bfx::Array<bfx::Space *> v25[5]; // [sp+60h] [-50h] BYREF

  a12 = pStartVert;
  memset(v25, 0, 12);
  v25[0].m_tag = bfx::MEM_BFXPLANNER;
  v13 = (islandNum << 16) & 0x3FF0000;
  bfx::Array<bfx::Portal *>::push_back(this: v25, val: &a12);
  m_size = v25[0].m_size;
  LODWORD(pStartVert->m_rotSpaceToWorld.m_w) = LODWORD(pStartVert->m_rotSpaceToWorld.m_w) & 0xFC00FFFF | v13;
  while ( m_size != 0 )
  {
    v15 = &v25[0].m_data[m_size--];
    v25[0].m_size = m_size;
    v16 = true;
    v17 = _cntlzw(LODWORD((*(v15 - 1))->m_pos.m_z));
    m_z = (*(v15 - 1))->m_pos.m_z;
    v19 = (v17 & 0x20) != 0;
    v20 = m_z;
    if ( (v17 & 0x20) == 0 )
    {
      do
      {
        v21 = v16;
        if ( !v16 )
          goto LABEL_9;
        if ( (*(_DWORD *)(LODWORD(m_z) + 72) & 8) == 0 )
        {
          v22 = *(_DWORD *)(*(_DWORD *)(LODWORD(m_z) + 12) + 8);
          v23 = *(_WORD *)(v22 + 24);
          v24 = (bfx::Space *)v22;
          if ( (v23 & 0x3FF) == 0x3FF )
          {
            *(_DWORD *)(v22 + 24) = *(_DWORD *)(v22 + 24) & 0xFC00FFFF | v13;
            bfx::Array<bfx::Portal *>::push_back(this: v25, val: &v24);
          }
        }
        if ( v21 != 0 )
          m_z = *(float *)(LODWORD(m_z) + 12);
        else
LABEL_9:
          m_z = *(float *)(LODWORD(m_z) + 20);
        if ( LODWORD(m_z) == LODWORD(v20) )
          v19 = true;
        v16 = (_cntlzw(v21) & 0x20) != 0;
      }
      while ( !v19 );
      m_size = v25[0].m_size;
    }
  }
  if ( v25[0].m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v25[0].m_data);
}


// ========================================================================
// __unwind$20190
// EA  : 0x832C5C34
// RVA : 0x012C5C34
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void _unwind_20190()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 176 + 96));
}


// ========================================================================
// ?LabelIslands@DGraph@bfx@@AAAXAAV?$Array@PAVDEdge@bfx@@@2@@Z
// EA  : 0x832C5C60
// RVA : 0x012C5C60
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void __fastcall bfx::DGraph::LabelIslands(
        bfx::DGraph *this,
        bfx::Array<bfx::DEdge *> *islandSeparatorEdges,
        int m_size,
        int a4,
        int a5,
        bfx::DEdge *a6,
        bfx::DEdge **m_data)
{
  bfx::ListNode *i; // r11
  int v8; // r10
  int v9; // r11
  bfx::ListNode *m_pHeadVertNode; // r31
  int j; // r30
  int v12; // [sp+8h] [-68h]
  int v13; // [sp+Ch] [-64h]
  int v14; // [sp+10h] [-60h]
  bfx::Space *v15; // [sp+14h] [-5Ch]

  for ( i = this->m_pHeadVertNode; i != nullptr; i = i->m_pNextListNode )
  {
    m_data = (bfx::DEdge **)((int)i[3].m_pNextListNode | 0x3FF0000);
    i[3].m_pNextListNode = (bfx::ListNode *)m_data;
  }
  v8 = 0;
  if ( islandSeparatorEdges->m_size > 0 )
  {
    v9 = 0;
    do
    {
      m_data = islandSeparatorEdges->m_data;
      ++v8;
      a6 = islandSeparatorEdges->m_data[v9++];
      a5 = *((_DWORD *)a6 + 18);
      a4 = a5 | 8;
      *((_DWORD *)a6 + 18) = a5 | 8;
      m_size = islandSeparatorEdges->m_size;
    }
    while ( v8 < m_size );
  }
  m_pHeadVertNode = this->m_pHeadVertNode;
  for ( j = 0; m_pHeadVertNode != nullptr; m_pHeadVertNode = m_pHeadVertNode->m_pNextListNode )
  {
    if ( (HIWORD(m_pHeadVertNode[3].m_pNextListNode) & 0x3FF) == 0x3FF )
      bfx::FillIsland(
        pStartVert: (bfx::Space *)m_pHeadVertNode,
        islandNum: j++,
        a3: m_size,
        a4,
        a5,
        (int)a6,
        a7: (int)m_data,
        a8: 1023,
        a9: v12,
        a10: v13,
        a11: v14,
        a12: v15);
  }
}


// ========================================================================
// ?Find@bfx@@YA_NAAV?$Array@VIslandConnectionRecord@bfx@@@1@HH@Z
// EA  : 0x832C5D28
// RVA : 0x012C5D28
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

int __fastcall bfx::Find(bfx::Array<bfx::IslandConnectionRecord> *islandConnections, int islandA, int islandB)
{
  int v3; // r11
  int m_size; // r7
  int v5; // r9
  bfx::IslandConnectionRecord *m_data; // r8
  int i; // r11

  if ( islandA > islandB )
  {
    v3 = islandA;
    islandA = islandB;
    islandB = v3;
  }
  m_size = islandConnections->m_size;
  v5 = 0;
  if ( m_size <= 0 )
    return 0;
  m_data = islandConnections->m_data;
  for ( i = 0; m_data[i].m_islandA != islandA || m_data[i].m_islandB != islandB; ++i )
  {
    if ( ++v5 >= m_size )
      return 0;
  }
  return 1;
}


// ========================================================================
// ?RecordIslandConnections@DGraph@bfx@@AAAXABV?$Array@PAVDEdge@bfx@@@2@AAV?$Array@VIslandConnectionRecord@bfx@@@2@@Z
// EA  : 0x832C5D90
// RVA : 0x012C5D90
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void __fastcall bfx::DGraph::RecordIslandConnections(
        bfx::DGraph *this,
        const bfx::Array<bfx::DEdge *> *islandSeparatorEdges,
        bfx::Array<bfx::ResourceManager::Registration> *islandConnections)
{
  int v5; // r25
  int v6; // r27
  bfx::DEdge *v7; // r31
  bfx::DEdge *m_pTwin; // r28
  __int16 v9; // r8
  bool (__fastcall *v10)(bfx::Space *, unsigned int, bfx::BinaryImageIn *, const bfx::ResourceOffset *); // r30
  __int16 v11; // r7
  bool (__fastcall *v12)(bfx::Space *, unsigned int, bfx::BinaryImageIn *, const bfx::ResourceOffset *); // r29
  bfx::DEdge *m_pNext; // r11
  void (__fastcall *v14)(bfx::Space *, unsigned int, bfx::BinaryImageIn *); // r10
  bfx::DEdge *v15; // r11
  bfx::ResourceManager::Registration v16; // [sp+50h] [-60h] BYREF

  v5 = 0;
  if ( islandSeparatorEdges->m_size > 0 )
  {
    v6 = 0;
    do
    {
      v7 = islandSeparatorEdges->m_data[v6];
      m_pTwin = v7->m_pTwin;
      v9 = *((_WORD *)v7->m_pStartVert + 12);
      v10 = (bool (__fastcall *)(bfx::Space *, unsigned int, bfx::BinaryImageIn *, const bfx::ResourceOffset *))(v9 & 0x3FF);
      v11 = *((_WORD *)m_pTwin->m_pStartVert + 12);
      v12 = (bool (__fastcall *)(bfx::Space *, unsigned int, bfx::BinaryImageIn *, const bfx::ResourceOffset *))(v11 & 0x3FF);
      if ( v10 != v12
        && (unsigned __int8)bfx::Find(
                              (bfx::Array<bfx::IslandConnectionRecord> *)islandConnections,
                              islandA: v9 & 0x3FF,
                              islandB: v11 & 0x3FF) == 0 )
      {
        m_pNext = v7;
        while ( (*((_DWORD *)m_pNext + 18) & 8) != 0 )
        {
          m_pNext = m_pNext->m_pTwin->m_pNext;
          if ( m_pNext == v7 )
          {
            v14 = nullptr;
            goto LABEL_9;
          }
        }
        v14 = (void (__fastcall *)(bfx::Space *, unsigned int, bfx::BinaryImageIn *))m_pNext;
LABEL_9:
        v15 = m_pTwin;
        while ( (*((_DWORD *)v15 + 18) & 8) != 0 )
        {
          v15 = v15->m_pTwin->m_pNext;
          if ( v15 == m_pTwin )
          {
            v15 = nullptr;
            break;
          }
        }
        v16.m_id = (unsigned int)v10;
        v16.m_initCB = v12;
        v16.m_termCB = v14;
        v16.m_isUpToDateCB = (bool (__fastcall *)(bool, const char *))v15;
        if ( (int)v10 > (int)v12 )
        {
          v16.m_id = (unsigned int)v12;
          v16.m_initCB = v10;
          v16.m_termCB = (void (__fastcall *)(bfx::Space *, unsigned int, bfx::BinaryImageIn *))v15;
          v16.m_isUpToDateCB = (bool (__fastcall *)(bool, const char *))v14;
        }
        bfx::Array<bfx::Plane>::push_back(this: islandConnections, val: &v16);
      }
      ++v5;
      ++v6;
    }
    while ( v5 < islandSeparatorEdges->m_size );
  }
}


// ========================================================================
// ?RemoveObsoletePartitionEdges@DGraph@bfx@@AAAXAAV?$Array@VHoleRecord@bfx@@@2@@Z
// EA  : 0x832C5EB0
// RVA : 0x012C5EB0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void __fastcall bfx::DGraph::RemoveObsoletePartitionEdges(
        bfx::DGraph *this,
        bfx::Array<bfx::ReplayLogListenerEntry> *holesCreated)
{
  int m_cap; // r30
  bfx::DEdge **v5; // r9
  bfx::DEdge *v6; // r8
  int v7; // r7
  int v8; // r6
  int v9; // r5
  int m_size; // r28
  char *m_data; // r25
  void (__fastcall **p_m_termCB)(bfx::Space *, unsigned int, bfx::BinaryImageIn *); // r29
  int v13; // r11
  char *v14; // r28
  int v15; // r10
  bfx::ListNode *i; // r29
  int v17; // r4
  bfx::DVert **v18; // r29
  int j; // r30
  bfx::Array<bfx::SpaceComponent *> v20; // [sp+50h] [-70h] BYREF
  bfx::Array<bfx::SpaceComponent *> v21; // [sp+60h] [-60h] BYREF
  bfx::Array<bfx::ResourceManager::Registration> v22; // [sp+70h] [-50h] BYREF

  m_cap = 0;
  memset(&v21, 0, 12);
  v21.m_tag = MEM_TEMP;
  bfx::DGraph::GetObsoletePartitionEdges(this, obsoletePartitionEdges: &v21);
  bfx::DGraph::LabelIslands(
    this,
    islandSeparatorEdges: (bfx::Array<bfx::DEdge *> *)&v21,
    m_size: v9,
    a4: v8,
    a5: v7,
    a6: v6,
    m_data: v5);
  memset(&v22, 0, 12);
  v22.m_tag = MEM_TEMP;
  bfx::DGraph::RecordIslandConnections(
    this,
    islandSeparatorEdges: (const bfx::Array<bfx::DEdge *> *)&v21,
    islandConnections: &v22);
  m_data = (char *)v22.m_data;
  m_size = v22.m_size;
  if ( v22.m_size > 0 )
  {
    p_m_termCB = &v22.m_data[-1].m_termCB;
    do
    {
      v13 = (int)p_m_termCB[5];
      p_m_termCB += 4;
      v20.m_data = (bfx::SpaceComponent **)*p_m_termCB;
      v20.m_size = v13;
      bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(
        this: holesCreated,
        val: (const bfx::ReplayLogListenerEntry *)&v20);
      --m_size;
    }
    while ( m_size != 0 );
  }
  memset(&v20, 0, 12);
  v14 = nullptr;
  v15 = 0;
  v20.m_tag = bfx::MEM_BFXPLANNER;
  for ( i = this->m_pHeadVertNode; i != nullptr; i = i->m_pNextListNode )
  {
    if ( ((int)i[3].m_pNextListNode & 0x10000000) != 0 )
    {
      if ( m_cap == v15 )
      {
        if ( m_cap != 0 )
          v17 = 2 * m_cap;
        else
          v17 = 1;
        bfx::Array<bfx::Edge *>::expand_cap(this: &v20, size: v17);
        v15 = v20.m_size;
        v14 = (char *)v20.m_data;
        m_cap = v20.m_cap;
      }
      if ( &v14[4 * v15] != nullptr )
        *(_DWORD *)&v14[4 * v15] = i;
      v20.m_size = ++v15;
    }
  }
  if ( v15 > 0 )
  {
    v18 = (bfx::DVert **)(v14 - 4);
    for ( j = v15; j != 0; --j )
      bfx::DGraph::ProcessPartitionClipVert(this, pVert: *++v18, (bfx::Array<bfx::HoleRecord> *)holesCreated);
  }
  idPhysics_StaticMulti::UpdateTime((bfx::BinaryReplayLogOut *)this);
  if ( v14 != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v14);
  if ( m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
  if ( v21.m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v21.m_data);
}


// ========================================================================
// __unwind$20443
// EA  : 0x832C6064
// RVA : 0x012C6064
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void _unwind_20443()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 192 + 96));
}


// ========================================================================
// __unwind$20444_0
// EA  : 0x832C608C
// RVA : 0x012C608C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void _unwind_20444_0()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 192 + 112));
}


// ========================================================================
// __unwind$20445
// EA  : 0x832C60B4
// RVA : 0x012C60B4
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void _unwind_20445()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 192 + 80));
}


// ========================================================================
// ?CoreAddObstacle@DGraph@bfx@@AAA?AW4DResult@2@ABVCoreAddObstacleData@2@@Z
// EA  : 0x832C60E8
// RVA : 0x012C60E8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

int __fastcall bfx::DGraph::CoreAddObstacle(bfx::DGraph *this, const bfx::CoreAddObstacleData *coreAddObstacleData)
{
  double m_minEdgeLength; // fp31
  double v5; // fp31
  bfx::DResult v7; // r29
  bfx::Array<bfx::SpaceComponent *> v8; // [sp+50h] [-60h] BYREF
  bfx::Array<bfx::SpaceComponent *> v9; // [sp+60h] [-50h] BYREF

  if ( (unsigned __int8)bfx::DGraph::ClipGraphAgainstObstacle(
                          this,
                          origClipPlanes: &coreAddObstacleData->m_clipPlanes,
                          obID: coreAddObstacleData->m_obID,
                          expandRadius: coreAddObstacleData->m_expandRadius) == 0 )
    return 1;
  m_minEdgeLength = coreAddObstacleData->m_minEdgeLength;
  if ( bfx::DGraph::GetLengthOfShortestEdge(this, onlyCheckImmediatelyOutsideObstacle: true) < m_minEdgeLength )
    return 1;
  memset(&v8, 0, 12);
  v8.m_tag = bfx::MEM_BFXPLANNER;
  bfx::DGraph::RemoveNewEdgesAndVertsOutsideObstacle(this, holesCreated: (bfx::Array<bfx::ReplayLogListenerEntry> *)&v8);
  v5 = coreAddObstacleData->m_minEdgeLength;
  if ( bfx::DGraph::GetLengthOfShortestEdge(this, onlyCheckImmediatelyOutsideObstacle: false) < v5 )
  {
    bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: &v8);
    return 1;
  }
  memset(&v9, 0, 12);
  v9.m_tag = bfx::MEM_BFXPLANNER;
  bfx::DGraph::MergeHoles(
    this,
    holesCreated: (const bfx::Array<bfx::HoleRecord> *)&v8,
    diagonalsAdded: (bfx::Array<bfx::DEdge *> *)&v9);
  bfx::Array<bfx::HoleRecord>::clear(this: (bfx::Array<bfx::QueuedTri> *)&v8);
  bfx::DGraph::RemoveObsoletePartitionEdges(this, holesCreated: (bfx::Array<bfx::ReplayLogListenerEntry> *)&v8);
  bfx::DGraph::MergeHoles(
    this,
    holesCreated: (const bfx::Array<bfx::HoleRecord> *)&v8,
    diagonalsAdded: (bfx::Array<bfx::DEdge *> *)&v9);
  bfx::DGraph::BuildFaces(this);
  v7 = bfx::DGraph::Partition(this, diagonalsAdded: (bfx::Array<bfx::DEdge *> *)&v9);
  if ( v7 != SUCCESS )
  {
    bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: &v9);
    bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: &v8);
    return v7;
  }
  else
  {
    idPhysics_StaticMulti::UpdateTime((bfx::BinaryReplayLogOut *)this);
    bfx::DGraph::RemoveAllInnessentialDiagonals(this, diagonalsAdded: (const bfx::Array<bfx::DEdge *> *)&v9);
    bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: &v9);
    bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: &v8);
    return 0;
  }
}


// ========================================================================
// __unwind$20648
// EA  : 0x832C623C
// RVA : 0x012C623C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void _unwind_20648()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 176 + 80));
}


// ========================================================================
// __unwind$20649
// EA  : 0x832C6264
// RVA : 0x012C6264
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxaddobstacle.cpp
// ========================================================================

void _unwind_20649()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 176 + 96));
}

