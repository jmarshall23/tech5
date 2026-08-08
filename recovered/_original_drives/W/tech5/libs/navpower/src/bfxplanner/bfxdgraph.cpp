
// ========================================================================
// ?CreateVert@DGraph@bfx@@AAAPAVDVert@2@ABVVec3@2@PAVDEdge@2@@Z
// EA  : 0x832C9C18
// RVA : 0x012C9C18
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraph.cpp
// ========================================================================

bfx::DVert *__fastcall bfx::DGraph::CreateVert(bfx::DGraph *this, const bfx::Vec3 *pos, bfx::DEdge *pIncidentEdge)
{
  bfx::DVert *result; // r3
  int v7; // r10

  result = (bfx::DVert *)bfx::Pool::GetNode(this: this->m_pVertPool);
  if ( result != nullptr )
  {
    v7 = *((_DWORD *)result + 6);
    result->m_pNextListNode = nullptr;
    result->m_pPrevListNode = nullptr;
    result->m_pos.m_x = pos->m_x;
    result->m_pos.m_y = pos->m_y;
    result->m_pos.m_z = pos->m_z;
    result->m_pIncidentEdge = pIncidentEdge;
    *((_DWORD *)result + 6) = v7 & 0x2000FFFF | 0x43FF0000;
  }
  else
  {
    result = nullptr;
  }
  if ( this->m_pHeadVertNode != nullptr )
  {
    result->m_pNextListNode = this->m_pHeadVertNode;
    this->m_pHeadVertNode->m_pPrevListNode = result;
  }
  this->m_pHeadVertNode = result;
  return result;
}


// ========================================================================
// ?CreateEdge@DGraph@bfx@@AAAPAVDEdge@2@XZ
// EA  : 0x832C9CA8
// RVA : 0x012C9CA8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraph.cpp
// ========================================================================

bfx::DEdge *__fastcall bfx::DGraph::CreateEdge(bfx::DGraph *this)
{
  bfx::DEdge *result; // r3
  int v3; // r7
  bfx::ListNode *m_pHeadEdgeNode; // r11

  result = (bfx::DEdge *)bfx::Pool::GetNode(this: this->m_pEdgePool);
  if ( result != nullptr )
  {
    result->m_pNextListNode = nullptr;
    result->m_pPrevListNode = nullptr;
    result->m_pStartVert = nullptr;
    result->m_pTwin = nullptr;
    result->m_pFace = nullptr;
    result->m_pNext = nullptr;
    result->m_pPrev = nullptr;
    result->m_pSrcStaticArea = nullptr;
    result->m_srcStaticAreaNormal.m_x = 0.0;
    result->m_srcStaticAreaNormal.m_y = 0.0;
    result->m_srcStaticAreaNormal.m_z = 0.0;
    result->m_pSrcEdge = nullptr;
    result->m_inwardsEdgeCursor.m_pArea = nullptr;
    result->m_inwardsEdgeCursor.m_i = -1;
    v3 = *((_DWORD *)result + 18) & 7 | 0x200;
    result->m_pInputArea = nullptr;
    result->m_inputEdgeType = EDGE_NORMAL;
    result->m_pOutputEdge = nullptr;
    result->m_pInitialObstacles = nullptr;
    *((_DWORD *)result + 18) = v3;
  }
  else
  {
    result = nullptr;
  }
  m_pHeadEdgeNode = this->m_pHeadEdgeNode;
  if ( m_pHeadEdgeNode != nullptr )
  {
    result->m_pNextListNode = m_pHeadEdgeNode;
    this->m_pHeadEdgeNode->m_pPrevListNode = result;
  }
  this->m_pHeadEdgeNode = result;
  return result;
}


// ========================================================================
// ?SetFacePtrForEdgeLoop@bfx@@YAXPAVDEdge@1@PAVDFace@1@@Z
// EA  : 0x832C9D70
// RVA : 0x012C9D70
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraph.cpp
// ========================================================================

void __fastcall bfx::SetFacePtrForEdgeLoop(bfx::DEdge *pEdge, bfx::DFace *pFace)
{
  bfx::DEdge *v2; // r11

  v2 = pEdge;
  do
  {
    v2->m_pFace = pFace;
    v2 = v2->m_pNext;
  }
  while ( v2 != pEdge );
}


// ========================================================================
// ?GetClosestEdgesBetweenPolylines@bfx@@YAXPAVDEdge@1@0AAPAV21@1@Z
// EA  : 0x832C9D88
// RVA : 0x012C9D88
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraph.cpp
// ========================================================================

void __fastcall bfx::GetClosestEdgesBetweenPolylines(
        bfx::DEdge *pStartEdgeA,
        bfx::DEdge *pStartEdgeB,
        bfx::DEdge **pClosestEdgeA,
        bfx::DEdge **pClosestEdgeB)
{
  bfx::DEdge *v4; // r8
  double v5; // fp13
  bfx::DEdge *v6; // r9
  float *m_pStartVert; // r11
  float *v8; // r10
  double v9; // fp11
  double v10; // fp8
  double v11; // fp5

  v4 = pStartEdgeA;
  v5 = 3.4028235e38;
  do
  {
    v6 = pStartEdgeB;
    do
    {
      m_pStartVert = (float *)v6->m_pStartVert;
      v8 = (float *)v4->m_pStartVert;
      v9 = (float)(v8[3] - m_pStartVert[3]);
      v10 = (float)(v8[2] - m_pStartVert[2]);
      v11 = (float)(v8[4] - m_pStartVert[4]);
      if ( (float)((float)((float)v11 * (float)v11)
                 + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9))) < v5 )
      {
        *pClosestEdgeA = v4;
        v5 = (float)((float)((float)v11 * (float)v11)
                   + (float)((float)((float)v10 * (float)v10) + (float)((float)v9 * (float)v9)));
        *pClosestEdgeB = v6;
      }
      v6 = v6->m_pNext;
    }
    while ( v6 != pStartEdgeB );
    v4 = v4->m_pNext;
  }
  while ( v4 != pStartEdgeA );
}


// ========================================================================
// ?DestroyVert@DGraph@bfx@@AAAXPAVDVert@2@@Z
// EA  : 0x832C9E00
// RVA : 0x012C9E00
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraph.cpp
// ========================================================================

void __fastcall bfx::DGraph::DestroyVert(bfx::DGraph *this, bfx::Pool::Node *pVert)
{
  bfx::ListNode *m_pNext; // r11
  bfx::Pool *m_pVertPool; // r9

  if ( (bfx::Pool::Node *)this->m_pHeadVertNode == pVert )
    this->m_pHeadVertNode = (bfx::ListNode *)pVert->m_pNext;
  m_pNext = (bfx::ListNode *)pVert[1].m_pNext;
  if ( m_pNext != nullptr )
    m_pNext->m_pNextListNode = (bfx::ListNode *)pVert->m_pNext;
  if ( pVert->m_pNext != nullptr )
    pVert->m_pNext[1].m_pNext = pVert[1].m_pNext;
  pVert[6].m_pNext = (bfx::Pool::Node *)((int)pVert[6].m_pNext | 0x4000000);
  m_pVertPool = this->m_pVertPool;
  pVert->m_pNext = m_pVertPool->m_data.m_pUnused;
  m_pVertPool->m_data.m_pUnused = pVert;
}


// ========================================================================
// ?DestroyEdge@DGraph@bfx@@AAAXPAVDEdge@2@@Z
// EA  : 0x832C9E60
// RVA : 0x012C9E60
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraph.cpp
// ========================================================================

void __fastcall bfx::DGraph::DestroyEdge(bfx::DGraph *this, bfx::Pool::Node *pEdge)
{
  bfx::ListNode *m_pNext; // r11
  bfx::Pool *m_pEdgePool; // r9

  if ( (bfx::Pool::Node *)this->m_pHeadEdgeNode == pEdge )
    this->m_pHeadEdgeNode = (bfx::ListNode *)pEdge->m_pNext;
  m_pNext = (bfx::ListNode *)pEdge[1].m_pNext;
  if ( m_pNext != nullptr )
    m_pNext->m_pNextListNode = (bfx::ListNode *)pEdge->m_pNext;
  if ( pEdge->m_pNext != nullptr )
    pEdge->m_pNext[1].m_pNext = pEdge[1].m_pNext;
  pEdge[18].m_pNext = (bfx::Pool::Node *)((int)pEdge[18].m_pNext | 0x10);
  m_pEdgePool = this->m_pEdgePool;
  pEdge->m_pNext = m_pEdgePool->m_data.m_pUnused;
  m_pEdgePool->m_data.m_pUnused = pEdge;
}


// ========================================================================
// ?RemoveVertAndEdgePair@DGraph@bfx@@AAAXPAVDVert@2@PAVDEdge@2@@Z
// EA  : 0x832C9EC0
// RVA : 0x012C9EC0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraph.cpp
// ========================================================================

void __fastcall bfx::DGraph::RemoveVertAndEdgePair(
        bfx::DGraph *this,
        bfx::Pool::Node *pDeleteMeVert,
        bfx::DEdge *pIncidentEdge)
{
  bfx::DFace *m_pFace; // r10
  bfx::ListNode *m_pTwin; // r11
  bfx::ListNode *m_pNextListNode; // r10
  bfx::DVert *v6; // r9
  bfx::DEdge *m_pNext; // r10
  bfx::DEdge *v8; // r8
  bfx::ListNode *m_pPrevListNode; // r10
  bfx::ListNode *v10; // r10
  bfx::Pool *m_pEdgePool; // r8
  bfx::ListNode *v12; // r10
  bfx::Pool *v13; // r8
  bfx::ListNode *v14; // r11
  bfx::Pool *m_pVertPool; // r9

  m_pFace = pIncidentEdge->m_pFace;
  m_pTwin = pIncidentEdge->m_pTwin;
  if ( m_pFace != nullptr && m_pFace->m_pOuterEdge == pIncidentEdge )
    m_pFace->m_pOuterEdge = pIncidentEdge->m_pNext;
  m_pNextListNode = m_pTwin[2].m_pNextListNode;
  if ( m_pNextListNode != nullptr && m_pNextListNode[1].m_pNextListNode == m_pTwin )
    m_pNextListNode[1].m_pNextListNode = m_pTwin[2].m_pPrevListNode;
  v6 = (bfx::DVert *)m_pTwin[1].m_pNextListNode;
  m_pNext = (bfx::DEdge *)pDeleteMeVert[5].m_pNext;
  do
  {
    v8 = m_pNext->m_pTwin;
    m_pNext->m_pStartVert = v6;
    m_pNext = v8->m_pNext;
  }
  while ( m_pNext != (bfx::DEdge *)pDeleteMeVert[5].m_pNext );
  if ( v6->m_pIncidentEdge == m_pTwin )
  {
    m_pPrevListNode = m_pTwin[3].m_pNextListNode[1].m_pPrevListNode;
    if ( m_pPrevListNode == m_pTwin )
      v6->m_pIncidentEdge = pIncidentEdge == m_pTwin[2].m_pPrevListNode
                          ? nullptr
                          : (bfx::DEdge *)m_pTwin[2].m_pPrevListNode;
    else
      v6->m_pIncidentEdge = (bfx::DEdge *)m_pPrevListNode;
  }
  pIncidentEdge->m_pPrev->m_pNext = pIncidentEdge->m_pNext;
  pIncidentEdge->m_pNext->m_pPrev = pIncidentEdge->m_pPrev;
  m_pTwin[3].m_pNextListNode[2].m_pPrevListNode = m_pTwin[2].m_pPrevListNode;
  m_pTwin[2].m_pPrevListNode[3].m_pNextListNode = m_pTwin[3].m_pNextListNode;
  if ( this->m_pHeadEdgeNode == pIncidentEdge )
    this->m_pHeadEdgeNode = pIncidentEdge->m_pNextListNode;
  v10 = pIncidentEdge->m_pPrevListNode;
  if ( v10 != nullptr )
    v10->m_pNextListNode = pIncidentEdge->m_pNextListNode;
  if ( pIncidentEdge->m_pNextListNode != nullptr )
    pIncidentEdge->m_pNextListNode->m_pPrevListNode = pIncidentEdge->m_pPrevListNode;
  *((_DWORD *)pIncidentEdge + 18) |= 0x10u;
  m_pEdgePool = this->m_pEdgePool;
  pIncidentEdge->m_pNextListNode = (bfx::ListNode *)m_pEdgePool->m_data.m_pUnused;
  m_pEdgePool->m_data.m_pUnused = (bfx::Pool::Node *)pIncidentEdge;
  if ( this->m_pHeadEdgeNode == m_pTwin )
    this->m_pHeadEdgeNode = m_pTwin->m_pNextListNode;
  v12 = m_pTwin->m_pPrevListNode;
  if ( v12 != nullptr )
    v12->m_pNextListNode = m_pTwin->m_pNextListNode;
  if ( m_pTwin->m_pNextListNode != nullptr )
    m_pTwin->m_pNextListNode->m_pPrevListNode = m_pTwin->m_pPrevListNode;
  m_pTwin[9].m_pNextListNode = (bfx::ListNode *)((int)m_pTwin[9].m_pNextListNode | 0x10);
  v13 = this->m_pEdgePool;
  m_pTwin->m_pNextListNode = (bfx::ListNode *)v13->m_data.m_pUnused;
  v13->m_data.m_pUnused = (bfx::Pool::Node *)m_pTwin;
  if ( (bfx::Pool::Node *)this->m_pHeadVertNode == pDeleteMeVert )
    this->m_pHeadVertNode = (bfx::ListNode *)pDeleteMeVert->m_pNext;
  v14 = (bfx::ListNode *)pDeleteMeVert[1].m_pNext;
  if ( v14 != nullptr )
    v14->m_pNextListNode = (bfx::ListNode *)pDeleteMeVert->m_pNext;
  if ( pDeleteMeVert->m_pNext != nullptr )
    pDeleteMeVert->m_pNext[1].m_pNext = pDeleteMeVert[1].m_pNext;
  pDeleteMeVert[6].m_pNext = (bfx::Pool::Node *)((int)pDeleteMeVert[6].m_pNext | 0x4000000);
  m_pVertPool = this->m_pVertPool;
  pDeleteMeVert->m_pNext = m_pVertPool->m_data.m_pUnused;
  m_pVertPool->m_data.m_pUnused = pDeleteMeVert;
}


// ========================================================================
// ??0DGraph@bfx@@QAA@XZ
// EA  : 0x832CA0A8
// RVA : 0x012CA0A8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraph.cpp
// ========================================================================

bfx::DGraph *__fastcall bfx::DGraph::DGraph(bfx::DGraph *this)
{
  bfx::bfxMemTag v2; // r11
  bfx::Pool *v3; // r3
  bfx::Pool *v4; // r3
  bfx::Pool *v5; // r3
  bfx::Pool *v6; // r3
  bfx::Pool *v7; // r3
  bfx::Pool *v8; // r3

  this->m_pHeadVertNode = nullptr;
  this->m_pHeadEdgeNode = nullptr;
  this->m_pHeadFaceNode = nullptr;
  v2 = bfx::MEM_BFXPLANNER;
  this->m_edgeMap.m_data = nullptr;
  this->m_edgeMap.m_size = 0;
  this->m_edgeMap.m_cap = 0;
  this->m_edgeMap.m_tag = v2;
  bfx::Array<bfx::IslandConnection>::expand_cap(this: (bfx::Array<bfx::EndPt> *)&this->m_edgeMap, size: 20);
  v3 = (bfx::Pool *)bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size: 0x18u, tag: 0);
  if ( v3 != nullptr )
    v4 = bfx::Pool::Pool(this: v3, nodeSize: 0x1Cu, numNodes: 0x4Bu, tag: bfx::MEM_BFXPLANNER);
  else
    v4 = nullptr;
  this->m_pVertPool = v4;
  v5 = (bfx::Pool *)bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size: 0x18u, tag: 0);
  if ( v5 != nullptr )
    v6 = bfx::Pool::Pool(this: v5, nodeSize: 0x4Cu, numNodes: 0xC8u, tag: bfx::MEM_BFXPLANNER);
  else
    v6 = nullptr;
  this->m_pEdgePool = v6;
  v7 = (bfx::Pool *)bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size: 0x18u, tag: 0);
  if ( v7 != nullptr )
    v8 = bfx::Pool::Pool(this: v7, nodeSize: 0x38u, numNodes: 0x32u, tag: bfx::MEM_BFXPLANNER);
  else
    v8 = nullptr;
  this->m_pFacePool = v8;
  return this;
}


// ========================================================================
// __unwind$18128_0
// EA  : 0x832CA1C8
// RVA : 0x012CA1C8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraph.cpp
// ========================================================================

void _unwind_18128_0()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                             + 24));
}


// ========================================================================
// __unwind$18129_0
// EA  : 0x832CA1F4
// RVA : 0x012CA1F4
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraph.cpp
// ========================================================================

void _unwind_18129_0()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(char **)(v0 - 144 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// __unwind$18130_0
// EA  : 0x832CA220
// RVA : 0x012CA220
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraph.cpp
// ========================================================================

void _unwind_18130_0()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(char **)(v0 - 144 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// __unwind$18131
// EA  : 0x832CA24C
// RVA : 0x012CA24C
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraph.cpp
// ========================================================================

void _unwind_18131()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(char **)(v0 - 144 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ?CreateFace@DGraph@bfx@@AAAPAVDFace@2@PAVDEdge@2@@Z
// EA  : 0x832CA278
// RVA : 0x012CA278
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraph.cpp
// ========================================================================

bfx::DFace *__fastcall bfx::DGraph::CreateFace(bfx::DGraph *this, bfx::DEdge *pOuterEdge)
{
  bfx::DFace *result; // r3
  bfx::bfxMemTag v5; // r10
  bfx::ListNode *m_pHeadFaceNode; // r11

  result = (bfx::DFace *)bfx::Pool::GetNode(this: this->m_pFacePool);
  if ( result != nullptr )
  {
    result->m_pOuterEdge = pOuterEdge;
    result->m_pNextListNode = nullptr;
    result->m_pPrevListNode = nullptr;
    result->m_pSrcStaticArea = nullptr;
    result->m_srcStaticAreaNormal.m_x = 0.0;
    result->m_srcStaticAreaNormal.m_y = 0.0;
    result->m_srcStaticAreaNormal.m_z = 0.0;
    result->m_pOutputArea = nullptr;
    result->m_pInitialObstacles = nullptr;
    v5 = bfx::MEM_BFXPLANNER;
    result->m_finalObstacles.m_data = nullptr;
    result->m_finalObstacles.m_size = 0;
    result->m_finalObstacles.m_cap = 0;
    result->m_finalObstacles.m_tag = v5;
    *((_DWORD *)result + 13) &= 0x3FFFFFFFu;
  }
  else
  {
    result = nullptr;
  }
  m_pHeadFaceNode = this->m_pHeadFaceNode;
  if ( m_pHeadFaceNode != nullptr )
  {
    result->m_pNextListNode = m_pHeadFaceNode;
    this->m_pHeadFaceNode->m_pPrevListNode = result;
  }
  this->m_pHeadFaceNode = result;
  return result;
}


// ========================================================================
// ?UpdateHoleRecordsForEdgeDeletion@bfx@@YAXPAVDEdge@1@AAV?$Array@VHoleRecord@bfx@@@1@@Z
// EA  : 0x832CA338
// RVA : 0x012CA338
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraph.cpp
// ========================================================================

void __fastcall bfx::UpdateHoleRecordsForEdgeDeletion(
        bfx::DEdge *pEdgeBeingDeleted,
        bfx::Array<bfx::HoleRecord> *holesCreated)
{
  int v2; // r9
  int v3; // r10
  bfx::HoleRecord *v4; // r11

  v2 = 0;
  if ( holesCreated->m_size > 0 )
  {
    v3 = 0;
    do
    {
      v4 = &holesCreated->m_data[v3];
      if ( v4->m_pEdgeA == pEdgeBeingDeleted )
        v4->m_pEdgeA = pEdgeBeingDeleted->m_pNext;
      if ( v4->m_pEdgeB == pEdgeBeingDeleted )
        v4->m_pEdgeB = pEdgeBeingDeleted->m_pNext;
      ++v2;
      ++v3;
    }
    while ( v2 < holesCreated->m_size );
  }
}


// ========================================================================
// ?MergeHoles@DGraph@bfx@@AAAXABV?$Array@VHoleRecord@bfx@@@2@AAV?$Array@PAVDEdge@bfx@@@2@@Z
// EA  : 0x832CA398
// RVA : 0x012CA398
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraph.cpp
// ========================================================================

void __fastcall bfx::DGraph::MergeHoles(
        bfx::DGraph *this,
        const bfx::Array<bfx::HoleRecord> *holesCreated,
        bfx::Array<bfx::Space *> *diagonalsAdded)
{
  int v6; // r30
  int v7; // r29
  bfx::HoleRecord *v8; // r11
  bfx::DEdge *m_pEdgeA; // r24
  bfx::DEdge *m_pEdgeB; // r31
  double m_x; // fp0
  bfx::Space *v12; // r10
  bfx::Space *v13; // [sp+50h] [-60h] BYREF
  bfx::DEdge *v14; // [sp+54h] [-5Ch] BYREF
  bfx::DEdge *v15; // [sp+58h] [-58h] BYREF
  bfx::DEdge *v16; // [sp+5Ch] [-54h] BYREF

  v6 = 0;
  if ( holesCreated->m_size > 0 )
  {
    v7 = 0;
    do
    {
      v8 = &holesCreated->m_data[v7];
      v16 = nullptr;
      v15 = nullptr;
      m_pEdgeA = v8->m_pEdgeA;
      m_pEdgeB = v8->m_pEdgeB;
      bfx::GetClosestEdgesBetweenPolylines(
        pStartEdgeA: v8->m_pEdgeA,
        pStartEdgeB: m_pEdgeB,
        pClosestEdgeA: &v16,
        pClosestEdgeB: &v15);
      bfx::DGraph::SpliceBetweenEdges(
        this,
        pEdgeA: v16,
        pEdgeB: v15,
        pNewEdgeToA: (bfx::DEdge **)&v13,
        pNewEdgeToB: &v14);
      LODWORD(v13->m_matSpaceToWorld.m_data[3]) |= 0x4000u;
      *((_DWORD *)v14 + 18) |= 0x4000u;
      m_x = m_pEdgeB->m_srcStaticAreaNormal.m_x;
      LODWORD(v13->m_pos.m_y) = m_pEdgeA->m_pFace;
      v14->m_pFace = m_pEdgeA->m_pFace;
      LODWORD(v13->m_rotSpaceToWorld.m_x) = m_pEdgeB->m_pSrcStaticArea;
      v14->m_pSrcStaticArea = m_pEdgeB->m_pSrcStaticArea;
      v12 = v13;
      v13->m_rotSpaceToWorld.m_y = m_x;
      v12->m_rotSpaceToWorld.m_z = m_pEdgeB->m_srcStaticAreaNormal.m_y;
      v12->m_rotWorldToSpace.m_w = m_pEdgeB->m_srcStaticAreaNormal.m_z;
      v14->m_srcStaticAreaNormal = m_pEdgeB->m_srcStaticAreaNormal;
      bfx::Array<bfx::Portal *>::push_back(this: diagonalsAdded, val: &v13);
      ++v6;
      ++v7;
    }
    while ( v6 < holesCreated->m_size );
  }
}


// ========================================================================
// ?BuildFaces@DGraph@bfx@@QAAXXZ
// EA  : 0x832CA4C8
// RVA : 0x012CA4C8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraph.cpp
// ========================================================================

void __fastcall bfx::DGraph::BuildFaces(bfx::DGraph *this)
{
  bfx::ListNode *i; // r31
  bfx::DFace *Face; // r3
  bfx::ListNode *m_pPrevListNode; // r11
  bfx::ListNode *v5; // r11
  bfx::Area *v6; // r10
  bfx::Array<bfx::ObstacleImpl *> *v7; // r9
  bfx::ListNode *v8; // r11
  double v9; // fp0

  for ( i = this->m_pHeadEdgeNode; i != nullptr; i = i->m_pNextListNode )
  {
    if ( ((int)i[9].m_pNextListNode & 0x800) == 0 && i[2].m_pNextListNode == nullptr )
    {
      Face = bfx::DGraph::CreateFace(this, pOuterEdge: (bfx::DEdge *)i);
      m_pPrevListNode = i;
      do
      {
        m_pPrevListNode[2].m_pNextListNode = Face;
        m_pPrevListNode = m_pPrevListNode[2].m_pPrevListNode;
      }
      while ( m_pPrevListNode != i );
      v5 = i;
      while ( 1 )
      {
        v6 = (bfx::Area *)v5[3].m_pPrevListNode;
        if ( v6 != nullptr )
          break;
        v5 = v5[2].m_pPrevListNode;
        if ( v5 == i )
        {
          Face->m_srcStaticAreaNormal.m_x = 0.0;
          Face->m_pSrcStaticArea = nullptr;
          Face->m_srcStaticAreaNormal.m_y = 0.0;
          Face->m_srcStaticAreaNormal.m_z = 0.0;
          goto LABEL_10;
        }
      }
      v9 = *(float *)&v5[4].m_pNextListNode;
      Face->m_pSrcStaticArea = v6;
      Face->m_srcStaticAreaNormal.m_x = v9;
      Face->m_srcStaticAreaNormal.m_y = *(float *)&v5[4].m_pPrevListNode;
      Face->m_srcStaticAreaNormal.m_z = *(float *)&v5[5].m_pNextListNode;
LABEL_10:
      v7 = nullptr;
      v8 = i;
      while ( v8[8].m_pPrevListNode == nullptr )
      {
        v8 = v8[2].m_pPrevListNode;
        if ( v8 == i )
          goto LABEL_16;
      }
      v7 = (bfx::Array<bfx::ObstacleImpl *> *)v8[8].m_pPrevListNode;
LABEL_16:
      Face->m_pInitialObstacles = v7;
    }
  }
}


// ========================================================================
// ?DestroyFace@DGraph@bfx@@AAAXPAVDFace@2@@Z
// EA  : 0x832CA5C0
// RVA : 0x012CA5C0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraph.cpp
// ========================================================================

void __fastcall bfx::DGraph::DestroyFace(bfx::DGraph *this, bfx::Pool::Node *pFace)
{
  bfx::ListNode *m_pNext; // r11
  char *v5; // r4
  bfx::Pool *m_pFacePool; // r11

  if ( (bfx::Pool::Node *)this->m_pHeadFaceNode == pFace )
    this->m_pHeadFaceNode = (bfx::ListNode *)pFace->m_pNext;
  m_pNext = (bfx::ListNode *)pFace[1].m_pNext;
  if ( m_pNext != nullptr )
    m_pNext->m_pNextListNode = (bfx::ListNode *)pFace->m_pNext;
  if ( pFace->m_pNext != nullptr )
    pFace->m_pNext[1].m_pNext = pFace[1].m_pNext;
  pFace[13].m_pNext = (bfx::Pool::Node *)((int)pFace[13].m_pNext | 0x40000000);
  v5 = (char *)pFace[9].m_pNext;
  pFace[10].m_pNext = nullptr;
  if ( v5 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v5);
    pFace[9].m_pNext = nullptr;
  }
  pFace[11].m_pNext = nullptr;
  m_pFacePool = this->m_pFacePool;
  pFace->m_pNext = m_pFacePool->m_data.m_pUnused;
  m_pFacePool->m_data.m_pUnused = pFace;
}


// ========================================================================
// ?UnlinkEdgePair@DGraph@bfx@@AAAXPAVDEdge@2@AAV?$Array@PAVDFace@bfx@@@2@@Z
// EA  : 0x832CA660
// RVA : 0x012CA660
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraph.cpp
// ========================================================================

void __fastcall bfx::DGraph::UnlinkEdgePair(
        bfx::DGraph *this,
        bfx::DEdge *pEdge,
        bfx::Array<bfx::Space *> *facesDeleted)
{
  bfx::DVert *m_pStartVert; // r11
  bfx::DEdge *m_pTwin; // r29
  bfx::DVert *v7; // r11
  bfx::DFace *m_pFace; // r9
  bfx::DFace *v9; // r10
  bfx::ListNode *m_pHeadEdgeNode; // r11
  bfx::Space *v11; // r30
  bfx::DFace *v12; // r9
  bfx::DEdge *v13; // r11
  bfx::DFace *v14; // r10
  bfx::DEdge *v15; // r11
  bfx::DFace *v16; // r10
  bfx::DEdge *m_pOuterEdge; // r11
  bfx::DEdge *m_pPrev; // r11
  bfx::Space *i; // [sp+50h] [-30h] BYREF

  m_pStartVert = pEdge->m_pStartVert;
  m_pTwin = pEdge->m_pTwin;
  if ( m_pStartVert->m_pIncidentEdge == pEdge )
    m_pStartVert->m_pIncidentEdge = pEdge == pEdge->m_pPrev->m_pTwin ? nullptr : pEdge->m_pPrev->m_pTwin;
  v7 = m_pTwin->m_pStartVert;
  if ( v7->m_pIncidentEdge == m_pTwin )
    v7->m_pIncidentEdge = m_pTwin == m_pTwin->m_pPrev->m_pTwin ? nullptr : m_pTwin->m_pPrev->m_pTwin;
  m_pFace = pEdge->m_pFace;
  if ( m_pFace != nullptr )
  {
    v9 = m_pTwin->m_pFace;
    if ( v9 != nullptr && m_pFace != v9 )
    {
      m_pHeadEdgeNode = this->m_pHeadEdgeNode;
      v11 = (bfx::Space *)m_pTwin->m_pFace;
      for ( i = v11; m_pHeadEdgeNode != nullptr; m_pHeadEdgeNode = m_pHeadEdgeNode->m_pNextListNode )
      {
        if ( (bfx::Space *)m_pHeadEdgeNode[2].m_pNextListNode == v11 )
          m_pHeadEdgeNode[2].m_pNextListNode = m_pFace;
      }
      bfx::Array<bfx::Portal *>::push_back(this: facesDeleted, val: &i);
      bfx::DGraph::DestroyFace(this, pFace: (bfx::Pool::Node *)v11);
    }
  }
  v12 = pEdge->m_pFace;
  if ( v12 == nullptr || m_pTwin->m_pFace != nullptr )
  {
    v14 = m_pTwin->m_pFace;
    if ( v14 != nullptr && v12 == nullptr )
    {
      v15 = pEdge;
      do
      {
        v15->m_pFace = v14;
        v15 = v15->m_pNext;
      }
      while ( v15 != pEdge );
    }
  }
  else
  {
    v13 = m_pTwin;
    do
    {
      v13->m_pFace = v12;
      v13 = v13->m_pNext;
    }
    while ( v13 != m_pTwin );
  }
  v16 = pEdge->m_pFace;
  if ( v16 != nullptr )
  {
    m_pOuterEdge = v16->m_pOuterEdge;
    if ( m_pOuterEdge != nullptr )
    {
      if ( m_pOuterEdge == pEdge )
      {
        m_pPrev = pEdge->m_pPrev;
        if ( m_pPrev == m_pTwin )
          m_pPrev = pEdge->m_pNext;
LABEL_30:
        v16->m_pOuterEdge = m_pPrev;
        goto LABEL_31;
      }
      if ( m_pOuterEdge == m_pTwin )
      {
        m_pPrev = m_pTwin->m_pPrev;
        if ( m_pPrev == pEdge )
          m_pPrev = m_pTwin->m_pNext;
        goto LABEL_30;
      }
    }
  }
LABEL_31:
  pEdge->m_pPrev->m_pNext = pEdge->m_pTwin->m_pNext;
  pEdge->m_pNext->m_pPrev = pEdge->m_pTwin->m_pPrev;
  pEdge->m_pTwin->m_pPrev->m_pNext = pEdge->m_pNext;
  pEdge->m_pTwin->m_pNext->m_pPrev = pEdge->m_pPrev;
}


// ========================================================================
// ?DeleteEdgePair@DGraph@bfx@@AAAXPAVDEdge@2@AAV?$Array@PAVDFace@bfx@@@2@@Z
// EA  : 0x832CA830
// RVA : 0x012CA830
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraph.cpp
// ========================================================================

void __fastcall bfx::DGraph::DeleteEdgePair(
        bfx::DGraph *this,
        bfx::DEdge *pEdge,
        bfx::Array<bfx::Space *> *facesDeleted)
{
  bfx::ListNode *m_pTwin; // r30
  bfx::ListNode *m_pPrevListNode; // r11
  bfx::Pool *m_pEdgePool; // r9
  bfx::ListNode *v8; // r11
  bfx::Pool *v9; // r9

  m_pTwin = pEdge->m_pTwin;
  bfx::DGraph::UnlinkEdgePair(this, pEdge, facesDeleted);
  if ( this->m_pHeadEdgeNode == pEdge )
    this->m_pHeadEdgeNode = pEdge->m_pNextListNode;
  m_pPrevListNode = pEdge->m_pPrevListNode;
  if ( m_pPrevListNode != nullptr )
    m_pPrevListNode->m_pNextListNode = pEdge->m_pNextListNode;
  if ( pEdge->m_pNextListNode != nullptr )
    pEdge->m_pNextListNode->m_pPrevListNode = pEdge->m_pPrevListNode;
  *((_DWORD *)pEdge + 18) |= 0x10u;
  m_pEdgePool = this->m_pEdgePool;
  pEdge->m_pNextListNode = (bfx::ListNode *)m_pEdgePool->m_data.m_pUnused;
  m_pEdgePool->m_data.m_pUnused = (bfx::Pool::Node *)pEdge;
  if ( this->m_pHeadEdgeNode == m_pTwin )
    this->m_pHeadEdgeNode = m_pTwin->m_pNextListNode;
  v8 = m_pTwin->m_pPrevListNode;
  if ( v8 != nullptr )
    v8->m_pNextListNode = m_pTwin->m_pNextListNode;
  if ( m_pTwin->m_pNextListNode != nullptr )
    m_pTwin->m_pNextListNode->m_pPrevListNode = m_pTwin->m_pPrevListNode;
  m_pTwin[9].m_pNextListNode = (bfx::ListNode *)((int)m_pTwin[9].m_pNextListNode | 0x10);
  v9 = this->m_pEdgePool;
  m_pTwin->m_pNextListNode = (bfx::ListNode *)v9->m_data.m_pUnused;
  v9->m_data.m_pUnused = (bfx::Pool::Node *)m_pTwin;
}


// ========================================================================
// ??1DGraph@bfx@@QAA@XZ
// EA  : 0x832CA910
// RVA : 0x012CA910
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraph.cpp
// ========================================================================

void __fastcall bfx::DGraph::~DGraph(bfx::DGraph *this)
{
  bfx::ListNode *m_pHeadVertNode; // r11
  bfx::ListNode *m_pPrevListNode; // r10
  bfx::Pool *m_pVertPool; // r8
  char *v5; // r29
  bfx::ListNode *m_pHeadEdgeNode; // r11
  bfx::ListNode *v7; // r10
  bfx::Pool *m_pEdgePool; // r8
  char *v9; // r29
  char *m_pFacePool; // r29
  char *m_data; // r4

  for ( ; this->m_pHeadVertNode != nullptr; m_pVertPool->m_data.m_pUnused = (bfx::Pool::Node *)m_pHeadVertNode )
  {
    m_pHeadVertNode = this->m_pHeadVertNode;
    this->m_pHeadVertNode = this->m_pHeadVertNode->m_pNextListNode;
    m_pPrevListNode = m_pHeadVertNode->m_pPrevListNode;
    if ( m_pPrevListNode != nullptr )
      m_pPrevListNode->m_pNextListNode = m_pHeadVertNode->m_pNextListNode;
    if ( m_pHeadVertNode->m_pNextListNode != nullptr )
      m_pHeadVertNode->m_pNextListNode->m_pPrevListNode = m_pHeadVertNode->m_pPrevListNode;
    m_pHeadVertNode[3].m_pNextListNode = (bfx::ListNode *)((int)m_pHeadVertNode[3].m_pNextListNode | 0x4000000);
    m_pVertPool = this->m_pVertPool;
    m_pHeadVertNode->m_pNextListNode = (bfx::ListNode *)m_pVertPool->m_data.m_pUnused;
  }
  v5 = (char *)this->m_pVertPool;
  if ( v5 != nullptr )
  {
    bfx::Pool::~Pool(this: this->m_pVertPool);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v5);
  }
  for ( ; this->m_pHeadEdgeNode != nullptr; m_pEdgePool->m_data.m_pUnused = (bfx::Pool::Node *)m_pHeadEdgeNode )
  {
    m_pHeadEdgeNode = this->m_pHeadEdgeNode;
    this->m_pHeadEdgeNode = m_pHeadEdgeNode->m_pNextListNode;
    v7 = m_pHeadEdgeNode->m_pPrevListNode;
    if ( v7 != nullptr )
      v7->m_pNextListNode = m_pHeadEdgeNode->m_pNextListNode;
    if ( m_pHeadEdgeNode->m_pNextListNode != nullptr )
      m_pHeadEdgeNode->m_pNextListNode->m_pPrevListNode = m_pHeadEdgeNode->m_pPrevListNode;
    m_pHeadEdgeNode[9].m_pNextListNode = (bfx::ListNode *)((int)m_pHeadEdgeNode[9].m_pNextListNode | 0x10);
    m_pEdgePool = this->m_pEdgePool;
    m_pHeadEdgeNode->m_pNextListNode = (bfx::ListNode *)m_pEdgePool->m_data.m_pUnused;
  }
  v9 = (char *)this->m_pEdgePool;
  if ( v9 != nullptr )
  {
    bfx::Pool::~Pool(this: this->m_pEdgePool);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v9);
  }
  while ( this->m_pHeadFaceNode != nullptr )
    bfx::DGraph::DestroyFace(this, pFace: (bfx::Pool::Node *)this->m_pHeadFaceNode);
  m_pFacePool = (char *)this->m_pFacePool;
  if ( m_pFacePool != nullptr )
  {
    bfx::Pool::~Pool(this: this->m_pFacePool);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_pFacePool);
  }
  m_data = (char *)this->m_edgeMap.m_data;
  this->m_edgeMap.m_size = 0;
  if ( m_data != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    this->m_edgeMap.m_data = nullptr;
  }
  this->m_edgeMap.m_cap = 0;
}


// ========================================================================
// __unwind$18757
// EA  : 0x832CAAC8
// RVA : 0x012CAAC8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxdgraph.cpp
// ========================================================================

void _unwind_18757()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 128 + 148)
                                                                                             + 24));
}

