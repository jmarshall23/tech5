
// ========================================================================
// ?CheckForHoleCreation@bfx@@YA_NPAVDEdge@1@AAPAV21@1@Z
// EA  : 0x832DB8A8
// RVA : 0x012DB8A8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxremoveobstacle.cpp
// ========================================================================

int __fastcall bfx::CheckForHoleCreation(bfx::DEdge *pEdge, bfx::DEdge **pEdgeAOut, bfx::DEdge **pEdgeBOut)
{
  bfx::DEdge *m_pTwin; // r10
  bfx::DEdge *v4; // r11
  char v5; // r9
  bfx::DEdge *v6; // r11

  m_pTwin = pEdge->m_pTwin;
  if ( pEdge->m_pNext == m_pTwin || pEdge->m_pPrev == m_pTwin )
    return 0;
  v4 = pEdge;
  v5 = 0;
  *pEdgeAOut = nullptr;
  while ( v4 != m_pTwin )
  {
    if ( (*((_DWORD *)v4 + 18) & 0x20) == 0 )
      *pEdgeAOut = v4;
    v4 = v4->m_pNext;
    if ( v4 == pEdge )
      goto LABEL_10;
  }
  v5 = 1;
LABEL_10:
  *pEdgeBOut = nullptr;
  if ( v5 == 0 || *pEdgeAOut == nullptr )
    return 0;
  v6 = m_pTwin;
  while ( (*((_DWORD *)v6 + 18) & 0x20) != 0 )
  {
    v6 = v6->m_pNext;
    if ( v6 == pEdge )
      return 0;
  }
  *pEdgeBOut = v6;
  return 1;
}


// ========================================================================
// ?CollectDataOnObstacleVert@bfx@@YAXPAVDVert@1@HAAV?$Array@PAVDEdge@bfx@@@1@1AAV?$Array@PAVDVert@bfx@@@1@AAV?$Array@PAVDFace@bfx@@@1@@Z
// EA  : 0x832DB958
// RVA : 0x012DB958
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxremoveobstacle.cpp
// ========================================================================

void __fastcall bfx::CollectDataOnObstacleVert(
        bfx::Space *pVert,
        int obID,
        bfx::Array<bfx::DEdge *> *obstacleEdges,
        bfx::Array<bfx::DEdge *> *partitionEdges,
        bfx::Array<bfx::Space *> *obstacleVerts,
        bfx::Array<bfx::Space *> *obstacleFaces,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        bfx::Space *a12)
{
  float m_w; // r11
  bfx::DEdge *m_z_low; // r31
  unsigned int v19; // r11
  bfx::Array<bfx::DEdge *> *v20; // r3
  bfx::DEdge *v21; // r11
  char v22; // r10
  bfx::DEdge *v23; // r31
  bool v24; // r29
  bool v25; // r30
  bfx::DEdge *v26; // r28
  bfx::DFace *m_pFace; // r11
  bfx::Space **p_m_pFace; // r4
  bfx::DEdge *v29; // [sp+50h] [-40h] BYREF

  m_w = pVert->m_rotSpaceToWorld.m_w;
  a12 = pVert;
  if ( (LODWORD(m_w) & 0x8000000) != 0 )
    return;
  bfx::Array<bfx::Portal *>::push_back(this: obstacleVerts, val: &a12);
  LODWORD(pVert->m_rotSpaceToWorld.m_w) |= 0x8000000u;
  m_z_low = (bfx::DEdge *)LODWORD(pVert->m_pos.m_z);
  v29 = m_z_low;
  do
  {
    v19 = *((_DWORD *)m_z_low + 18);
    if ( (v19 & 0x100) == 0 )
    {
      if ( v19 >> 20 == obID || *((_DWORD *)m_z_low->m_pTwin + 18) >> 20 == obID )
      {
        v20 = obstacleEdges;
        goto LABEL_9;
      }
      if ( (v19 & 0x4000) != 0 )
      {
        v20 = partitionEdges;
LABEL_9:
        bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)v20, val: (bfx::Space **)&v29);
      }
      *((_DWORD *)m_z_low + 18) |= 0x100u;
      *((_DWORD *)m_z_low->m_pTwin + 18) |= 0x100u;
    }
    v21 = (bfx::DEdge *)LODWORD(pVert->m_pos.m_z);
    m_z_low = m_z_low->m_pTwin->m_pNext;
    v29 = m_z_low;
  }
  while ( m_z_low != v21 );
  v22 = _cntlzw((unsigned int)v21);
  v23 = v21;
  v24 = (v22 & 0x20) != 0;
  v25 = true;
  v26 = v21;
  if ( (v22 & 0x20) == 0 )
  {
    do
    {
      m_pFace = v23->m_pFace;
      p_m_pFace = (bfx::Space **)&v23->m_pFace;
      if ( m_pFace != nullptr && *((int *)m_pFace + 13) >= 0 )
      {
        LODWORD((*p_m_pFace)->m_rotWorldToSpace.m_z) |= 0x80000000;
        bfx::Array<bfx::Portal *>::push_back(this: obstacleFaces, val: p_m_pFace);
      }
      if ( v25 )
        v23 = v23->m_pTwin;
      else
        v23 = v23->m_pNext;
      if ( v23 == v26 )
        v24 = true;
      v25 = (_cntlzw(v25) & 0x20) != 0;
    }
    while ( !v24 );
  }
}


// ========================================================================
// ?RemoveEdges@DGraph@bfx@@AAAXABV?$Array@PAVDEdge@bfx@@@2@AAV?$Array@PAVDFace@bfx@@@2@AAV?$Array@VHoleRecord@bfx@@@2@@Z
// EA  : 0x832DBAC8
// RVA : 0x012DBAC8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxremoveobstacle.cpp
// ========================================================================

void __fastcall bfx::DGraph::RemoveEdges(
        bfx::DGraph *this,
        const bfx::Array<bfx::DEdge *> *edges,
        bfx::Array<bfx::Space *> *facesDeleted,
        bfx::Array<bfx::ReplayLogListenerEntry> *holesCreated)
{
  int v8; // r30
  int v9; // r31
  bfx::DEdge **m_data; // r11
  bfx::DEdge *v11; // r28
  bfx::ReplayLogListenerEntry v12; // [sp+50h] [-60h] BYREF
  bfx::ReplayLogListenerEntry v13; // [sp+58h] [-58h] BYREF

  v8 = 0;
  if ( edges->m_size > 0 )
  {
    v9 = 0;
    do
    {
      v12.m_pListener = nullptr;
      m_data = edges->m_data;
      *(_DWORD *)&v12.m_clientOwned = 0;
      v11 = m_data[v9];
      if ( (unsigned __int8)bfx::CheckForHoleCreation(
                              pEdge: v11,
                              pEdgeAOut: (bfx::DEdge **)&v12,
                              pEdgeBOut: (bfx::DEdge **)&v12.m_clientOwned) != 0 )
      {
        v13 = v12;
        bfx::Array<bfx::Pair<unsigned int,bfx::VolumeGraph *>>::push_back(this: holesCreated, val: &v13);
      }
      bfx::DGraph::DeleteEdgePair(this, pEdge: v11, facesDeleted);
      ++v8;
      ++v9;
    }
    while ( v8 < edges->m_size );
  }
}


// ========================================================================
// ?RecombineSubdividedEdges@DGraph@bfx@@AAAXABV?$Array@PAVDVert@bfx@@@2@AAV?$Array@VHoleRecord@bfx@@@2@@Z
// EA  : 0x832DBB70
// RVA : 0x012DBB70
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxremoveobstacle.cpp
// ========================================================================

void __fastcall bfx::DGraph::RecombineSubdividedEdges(
        bfx::DGraph *this,
        const bfx::Array<bfx::DVert *> *remainingVertsOnObstacle,
        bfx::Array<bfx::HoleRecord> *holesCreated)
{
  int v6; // r27
  int v7; // r29
  bfx::DVert *v8; // r30
  bfx::DEdge *m_pIncidentEdge; // r31

  v6 = 0;
  if ( remainingVertsOnObstacle->m_size > 0 )
  {
    v7 = 0;
    do
    {
      v8 = remainingVertsOnObstacle->m_data[v7];
      m_pIncidentEdge = v8->m_pIncidentEdge;
      if ( m_pIncidentEdge != m_pIncidentEdge->m_pNext->m_pNext->m_pNext
        && m_pIncidentEdge->m_pTwin != m_pIncidentEdge->m_pTwin->m_pNext->m_pNext->m_pNext )
      {
        bfx::UpdateHoleRecordsForEdgeDeletion(pEdgeBeingDeleted: v8->m_pIncidentEdge, holesCreated);
        bfx::UpdateHoleRecordsForEdgeDeletion(pEdgeBeingDeleted: m_pIncidentEdge->m_pTwin, holesCreated);
        bfx::DGraph::RemoveVertAndEdgePair(this, pDeleteMeVert: (bfx::Pool::Node *)v8, pIncidentEdge: m_pIncidentEdge);
      }
      ++v6;
      ++v7;
    }
    while ( v6 < remainingVertsOnObstacle->m_size );
  }
}


// ========================================================================
// ?FixFacesForEdgeRemoval@DGraph@bfx@@AAAXAAV?$Array@PAVDFace@bfx@@@2@@Z
// EA  : 0x832DBC20
// RVA : 0x012DBC20
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxremoveobstacle.cpp
// ========================================================================

void __fastcall bfx::DGraph::FixFacesForEdgeRemoval(bfx::DGraph *this, bfx::Array<bfx::SpaceComponent *> *facesDeleted)
{
  bfx::Space *m_pHeadFaceNode; // r29
  __int64 v5; // kr00_8
  unsigned int m_spaceID; // r11
  bfx::Pool::Node **v7; // r28
  int i; // r27
  bfx::Pool::Node *v9; // r29
  int m_cap; // r10
  int m_size; // r11
  int v12; // r4
  bfx::DFace **v13; // r11
  bool v14; // cr34
  bfx::Space *v15; // [sp+50h] [-60h] BYREF
  bfx::Array<bfx::Space *> v16; // [sp+60h] [-50h] BYREF

  memset(&v16, 0, 12);
  v16.m_tag = bfx::MEM_BFXPLANNER;
  m_pHeadFaceNode = (bfx::Space *)this->m_pHeadFaceNode;
  v5 = 0;
  if ( m_pHeadFaceNode != nullptr )
  {
    do
    {
      m_spaceID = m_pHeadFaceNode->m_spaceID;
      v15 = m_pHeadFaceNode;
      while ( (*(_DWORD *)(m_spaceID + 72) & 0x20) != 0 )
      {
        m_spaceID = *(_DWORD *)(m_spaceID + 20);
        if ( m_spaceID == m_pHeadFaceNode->m_spaceID )
          goto LABEL_7;
      }
      m_pHeadFaceNode->m_spaceID = m_spaceID;
LABEL_7:
      if ( (*(_DWORD *)(m_pHeadFaceNode->m_spaceID + 72) & 0x20) != 0 )
        bfx::Array<bfx::Portal *>::push_back(this: &v16, val: &v15);
      m_pHeadFaceNode = (bfx::Space *)m_pHeadFaceNode->__vftable;
    }
    while ( m_pHeadFaceNode != nullptr );
    v5 = *(_QWORD *)&v16.m_data;
  }
  if ( (int)v5 > 0 )
  {
    v7 = (bfx::Pool::Node **)HIDWORD(v5);
    for ( i = v5; i != 0; --i )
    {
      v9 = *v7;
      bfx::SetFacePtrForEdgeLoop(pEdge: (bfx::DEdge *)(*v7)[2].m_pNext, pFace: nullptr);
      m_cap = facesDeleted->m_cap;
      m_size = facesDeleted->m_size;
      if ( m_cap == m_size )
      {
        v12 = 2 * m_cap;
        if ( m_cap == 0 )
          v12 = 1;
        bfx::Array<bfx::Edge *>::expand_cap(this: facesDeleted, size: v12);
        v13 = (bfx::DFace **)&facesDeleted->m_data[facesDeleted->m_size];
        v14 = v13 == nullptr;
      }
      else
      {
        v13 = (bfx::DFace **)&facesDeleted->m_data[m_size];
        v14 = v13 == nullptr;
      }
      if ( !v14 )
        *v13 = (bfx::DFace *)v9;
      ++facesDeleted->m_size;
      bfx::DGraph::DestroyFace(this, pFace: v9);
      ++v7;
    }
  }
  if ( HIDWORD(v5) != 0 )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)HIDWORD(v5));
}


// ========================================================================
// __unwind$16939
// EA  : 0x832DBD80
// RVA : 0x012DBD80
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxremoveobstacle.cpp
// ========================================================================

void _unwind_16939()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 176 + 96));
}


// ========================================================================
// ?CoreRemoveObstacle@DGraph@bfx@@AAA?AW4DResult@2@ABVCoreRemoveObstacleData@2@@Z
// EA  : 0x832DBDB0
// RVA : 0x012DBDB0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxremoveobstacle.cpp
// ========================================================================

int __fastcall bfx::DGraph::CoreRemoveObstacle(
        bfx::DGraph *this,
        const bfx::CoreRemoveObstacleData *coreRemoveObstacleData)
{
  int m_obID; // r29
  int v4; // r9
  int m_size; // r10
  bfx::bfxMemTag v6; // r11
  int v7; // r8
  char *m_data; // r19
  int v9; // r28
  char *v10; // r20
  int v11; // r22
  bfx::ListNode *m_pHeadEdgeNode; // r30
  int v13; // r10
  int v14; // r10
  int v15; // r9
  int v16; // ctr
  bfx::DEdge **v17; // r9
  bfx::DEdge *m_pTwin; // r10
  int v19; // ctr
  bfx::DEdge **v20; // r9
  bfx::DEdge *v21; // r10
  bfx::SpaceComponent **v22; // r26
  int v23; // r30
  int m_cap; // r25
  bfx::Pool::Node **v25; // r24
  bfx::Pool::Node *v26; // r29
  int v27; // r4
  int v28; // r7
  char *v29; // r25
  int v30; // r26
  int v31; // r9
  char *v32; // r29
  bfx::SpaceComponent **v33; // r11
  bfx::SpaceComponent *v34; // r30
  bfx::SpaceComponent **v35; // r10
  char v36; // r11
  int v37; // r4
  int v38; // r29
  char *v39; // r30
  bfx::Space *v40; // r4
  float v41; // r9
  float v42; // r8
  int v43; // r28
  int v45; // [sp+8h] [-158h]
  int v46; // [sp+8h] [-158h]
  int v47; // [sp+Ch] [-154h]
  int v48; // [sp+Ch] [-154h]
  int v49; // [sp+10h] [-150h]
  int v50; // [sp+10h] [-150h]
  bfx::Space *v51; // [sp+14h] [-14Ch]
  bfx::Space *v52; // [sp+14h] [-14Ch]
  int v53; // [sp+18h] [-148h]
  bfx::Space *v54; // [sp+1Ch] [-144h]
  bfx::Array<bfx::SpaceComponent *> v55; // [sp+50h] [-110h] BYREF
  bfx::Array<bfx::ReplayLogListenerEntry> v56; // [sp+60h] [-100h] BYREF
  bfx::Array<bfx::Space *> v57; // [sp+70h] [-F0h] BYREF
  bfx::Array<bfx::SpaceComponent *> v58; // [sp+80h] [-E0h] BYREF
  bfx::Array<bfx::DEdge *> v59; // [sp+90h] [-D0h] BYREF
  bfx::Array<bfx::SpaceComponent *> v60; // [sp+A0h] [-C0h] BYREF
  bfx::Array<bfx::DEdge *> v61; // [sp+B0h] [-B0h] BYREF
  bfx::Array<bfx::Space *> v62; // [sp+C0h] [-A0h] BYREF
  bfx::Array<bfx::Space *> v63; // [sp+D0h] [-90h] BYREF
  bfx::Vec3 v64; // [sp+E0h] [-80h] BYREF
  bfx::SpaceComponent **v65; // [sp+ECh] [-74h]

  m_obID = coreRemoveObstacleData->m_obID;
  bfx::DGraph::BuildFaces(this);
  memset(&v61, 0, 12);
  m_size = 0;
  v6 = bfx::MEM_BFXPLANNER;
  v61.m_tag = bfx::MEM_BFXPLANNER;
  v7 = 0;
  memset(&v59, 0, 12);
  v59.m_tag = bfx::MEM_BFXPLANNER;
  m_data = nullptr;
  v9 = 0;
  v63.m_tag = bfx::MEM_BFXPLANNER;
  memset(&v63, 0, 12);
  v10 = nullptr;
  v11 = 0;
  v62.m_tag = bfx::MEM_BFXPLANNER;
  memset(&v62, 0, 12);
  m_pHeadEdgeNode = this->m_pHeadEdgeNode;
  if ( m_pHeadEdgeNode != nullptr )
  {
    do
    {
      v13 = (unsigned int)m_pHeadEdgeNode[9].m_pNextListNode >> 20;
      if ( v13 == m_obID )
      {
        bfx::CollectDataOnObstacleVert(
          pVert: (bfx::Space *)m_pHeadEdgeNode[1].m_pNextListNode,
          obID: m_obID,
          obstacleEdges: &v61,
          partitionEdges: &v59,
          obstacleVerts: &v63,
          obstacleFaces: &v62,
          a7: v4,
          a8: v13,
          a9: v45,
          a10: v47,
          a11: v49,
          a12: v51);
        bfx::CollectDataOnObstacleVert(
          pVert: (bfx::Space *)m_pHeadEdgeNode[1].m_pPrevListNode[1].m_pNextListNode,
          obID: m_obID,
          obstacleEdges: &v61,
          partitionEdges: &v59,
          obstacleVerts: &v63,
          obstacleFaces: &v62,
          a7: v15,
          a8: v14,
          a9: v46,
          a10: v48,
          a11: v50,
          a12: v52);
      }
      m_pHeadEdgeNode = m_pHeadEdgeNode->m_pNextListNode;
    }
    while ( m_pHeadEdgeNode != nullptr );
    m_size = v61.m_size;
    v7 = v59.m_size;
    m_data = (char *)v63.m_data;
    v9 = v63.m_size;
    v10 = (char *)v62.m_data;
    v11 = v62.m_size;
    v6 = bfx::MEM_BFXPLANNER;
  }
  if ( m_size > 0 )
  {
    v16 = m_size;
    v17 = v61.m_data - 1;
    do
    {
      m_pTwin = (*++v17)->m_pTwin;
      *((_DWORD *)*v17 + 18) |= 0x20u;
      *((_DWORD *)m_pTwin + 18) |= 0x20u;
      --v16;
    }
    while ( v16 != 0 );
    v6 = bfx::MEM_BFXPLANNER;
  }
  if ( v7 > 0 )
  {
    v19 = v7;
    v20 = v59.m_data - 1;
    do
    {
      v21 = (*++v20)->m_pTwin;
      *((_DWORD *)*v20 + 18) |= 0x20u;
      *((_DWORD *)v21 + 18) |= 0x20u;
      --v19;
    }
    while ( v19 != 0 );
    v6 = bfx::MEM_BFXPLANNER;
  }
  v55.m_tag = v6;
  memset(&v55, 0, 12);
  bfx::DGraph::FixFacesForEdgeRemoval(this, facesDeleted: &v55);
  memset(&v56, 0, 12);
  v56.m_tag = bfx::MEM_BFXPLANNER;
  bfx::DGraph::RemoveEdges(this, edges: &v61, facesDeleted: (bfx::Array<bfx::Space *> *)&v55, holesCreated: &v56);
  bfx::DGraph::RemoveEdges(this, edges: &v59, facesDeleted: (bfx::Array<bfx::Space *> *)&v55, holesCreated: &v56);
  v22 = nullptr;
  memset(&v58, 0, 12);
  v23 = 0;
  m_cap = 0;
  v58.m_tag = bfx::MEM_BFXPLANNER;
  if ( v9 > 0 )
  {
    v25 = (bfx::Pool::Node **)m_data;
    do
    {
      v26 = *v25;
      if ( (*v25)[5].m_pNext != nullptr )
      {
        if ( m_cap == v23 )
        {
          v27 = 2 * m_cap;
          if ( m_cap == 0 )
            v27 = 1;
          bfx::Array<bfx::Edge *>::expand_cap(this: &v58, size: v27);
          v23 = v58.m_size;
          v22 = v58.m_data;
          m_cap = v58.m_cap;
        }
        if ( &v22[v23] != nullptr )
          v22[v23] = (bfx::SpaceComponent *)v26;
        v58.m_size = ++v23;
      }
      else
      {
        bfx::DGraph::DestroyVert(this, pVert: *v25);
      }
      --v9;
      ++v25;
    }
    while ( v9 != 0 );
  }
  bfx::DGraph::RecombineSubdividedEdges(
    this,
    remainingVertsOnObstacle: (const bfx::Array<bfx::DVert *> *)&v58,
    holesCreated: (bfx::Array<bfx::HoleRecord> *)&v56);
  memset(&v57, 0, 12);
  v57.m_tag = bfx::MEM_BFXPLANNER;
  bfx::DGraph::MergeHoles(this, holesCreated: (const bfx::Array<bfx::HoleRecord> *)&v56, diagonalsAdded: &v57);
  v29 = nullptr;
  memset(&v60, 0, 12);
  v30 = 0;
  v31 = 0;
  v60.m_tag = bfx::MEM_BFXPLANNER;
  if ( v11 > 0 )
  {
    v32 = v10;
    do
    {
      v33 = v55.m_data;
      v34 = *(bfx::SpaceComponent **)v32;
      v35 = &v55.m_data[v55.m_size];
      v65 = v35;
      if ( v55.m_data == v35 )
      {
LABEL_31:
        v36 = 0;
      }
      else
      {
        while ( *v33 != v34 )
        {
          if ( ++v33 == v35 )
            goto LABEL_31;
        }
        v36 = 1;
      }
      if ( v36 == 0 )
      {
        if ( v31 == v30 )
        {
          if ( v31 != 0 )
            v37 = 2 * v31;
          else
            v37 = 1;
          bfx::Array<bfx::Edge *>::expand_cap(this: &v60, size: v37);
          v31 = v60.m_cap;
          v30 = v60.m_size;
          v29 = (char *)v60.m_data;
        }
        if ( &v29[4 * v30] != nullptr )
          *(_DWORD *)&v29[4 * v30] = v34;
        v60.m_size = ++v30;
      }
      --v11;
      v32 += 4;
    }
    while ( v11 != 0 );
  }
  v38 = 0;
  if ( v30 <= 0 )
  {
LABEL_47:
    bfx::DGraph::RemoveAllInnessentialDiagonals(this, diagonalsAdded: (const bfx::Array<bfx::DEdge *> *)&v57);
    idPhysics_StaticMulti::UpdateTime((bfx::BinaryReplayLogOut *)this);
    idPhysics_StaticMulti::UpdateTime((bfx::BinaryReplayLogOut *)this);
    if ( v29 != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v29);
    v57.m_size = 0;
    if ( v57.m_data != nullptr )
    {
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v57.m_data);
      v57.m_data = nullptr;
    }
    v57.m_cap = 0;
    if ( v58.m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v58.m_data);
    v56.m_size = 0;
    if ( v56.m_data != nullptr )
    {
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v56.m_data);
      v56.m_data = nullptr;
    }
    v56.m_cap = 0;
    v55.m_size = 0;
    if ( v55.m_data != nullptr )
    {
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v55.m_data);
      v55.m_data = nullptr;
    }
    v55.m_cap = 0;
    if ( v10 != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v10);
    if ( m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    if ( v59.m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v59.m_data);
    if ( v61.m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v61.m_data);
    return 0;
  }
  else
  {
    v39 = v29;
    while ( 1 )
    {
      v40 = *(bfx::Space **)v39;
      v41 = *(float *)(*(_DWORD *)v39 + 20);
      v42 = *(float *)(*(_DWORD *)v39 + 24);
      v64.m_x = *(float *)(*(_DWORD *)v39 + 16);
      v64.m_y = v41;
      v64.m_z = v42;
      v43 = bfx::DGraph::PartitionFace(
              this,
              pInitialFace: v40,
              N: &v64,
              diagonalsAdded: &v57,
              a5: v28,
              a6: SLODWORD(v42),
              a7: SLODWORD(v41),
              a8: SLODWORD(v64.m_x),
              a9: v45,
              a10: v47,
              a11: v49,
              a12: (int)v51,
              a13: v53,
              a14: v54);
      if ( v43 != 0 )
        break;
      ++v38;
      v39 += 4;
      if ( v38 >= v30 )
        goto LABEL_47;
    }
    if ( v29 != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v29);
    v57.m_size = 0;
    if ( v57.m_data != nullptr )
    {
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v57.m_data);
      v57.m_data = nullptr;
    }
    v57.m_cap = 0;
    if ( v58.m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v58.m_data);
    v56.m_size = 0;
    if ( v56.m_data != nullptr )
    {
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v56.m_data);
      v56.m_data = nullptr;
    }
    v56.m_cap = 0;
    v55.m_size = 0;
    if ( v55.m_data != nullptr )
    {
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v55.m_data);
      v55.m_data = nullptr;
    }
    v55.m_cap = 0;
    if ( v10 != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v10);
    if ( m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
    if ( v59.m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v59.m_data);
    if ( v61.m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v61.m_data);
    return v43;
  }
}


// ========================================================================
// __unwind$17091
// EA  : 0x832DC3B0
// RVA : 0x012DC3B0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxremoveobstacle.cpp
// ========================================================================

void _unwind_17091()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 352 + 176));
}


// ========================================================================
// __unwind$17092
// EA  : 0x832DC3D8
// RVA : 0x012DC3D8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxremoveobstacle.cpp
// ========================================================================

void _unwind_17092()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 352 + 144));
}


// ========================================================================
// __unwind$17093
// EA  : 0x832DC400
// RVA : 0x012DC400
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxremoveobstacle.cpp
// ========================================================================

void _unwind_17093()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 352 + 208));
}


// ========================================================================
// __unwind$17094
// EA  : 0x832DC428
// RVA : 0x012DC428
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxremoveobstacle.cpp
// ========================================================================

void _unwind_17094()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 352 + 192));
}


// ========================================================================
// __unwind$17095
// EA  : 0x832DC450
// RVA : 0x012DC450
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxremoveobstacle.cpp
// ========================================================================

void _unwind_17095()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 352 + 80));
}


// ========================================================================
// __unwind$17096
// EA  : 0x832DC478
// RVA : 0x012DC478
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxremoveobstacle.cpp
// ========================================================================

void _unwind_17096()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 352 + 96));
}


// ========================================================================
// __unwind$17097
// EA  : 0x832DC4A0
// RVA : 0x012DC4A0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxremoveobstacle.cpp
// ========================================================================

void _unwind_17097()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 352 + 128));
}


// ========================================================================
// __unwind$17098
// EA  : 0x832DC4C8
// RVA : 0x012DC4C8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxremoveobstacle.cpp
// ========================================================================

void _unwind_17098()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 352 + 112));
}


// ========================================================================
// __unwind$17099
// EA  : 0x832DC4F0
// RVA : 0x012DC4F0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxremoveobstacle.cpp
// ========================================================================

void _unwind_17099()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 352 + 160));
}

