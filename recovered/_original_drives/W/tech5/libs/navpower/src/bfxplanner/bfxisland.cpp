
// ========================================================================
// ??0IslandsTouchedArray@bfx@@QAA@XZ
// EA  : 0x8327E2B8
// RVA : 0x0127E2B8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

bfx::IslandsTouchedArray *__fastcall bfx::IslandsTouchedArray::IslandsTouchedArray(bfx::IslandsTouchedArray *this)
{
  _DWORD *v1; // r11
  int i; // ctr

  v1 = (_DWORD *)this - 1;
  for ( i = 32; i != 0; --i )
    *++v1 = 0;
  return this;
}


// ========================================================================
// ??0IslandSearcher@bfx@@QAA@PAVIsland@1@IABVPathSpec@1@@Z
// EA  : 0x8327E2D8
// RVA : 0x0127E2D8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

bfx::IslandSearcher *__fastcall bfx::IslandSearcher::IslandSearcher(
        bfx::IslandSearcher *this,
        bfx::Island *pStartIsland,
        unsigned int curIslandSearchIndex,
        const bfx::PathSpec *pathSpec)
{
  bfx::Island **v7; // r3

  this->m_islandIndexForSearch = curIslandSearchIndex;
  this->m_pathSpec = pathSpec;
  this->m_queueCapacity = 100;
  v7 = (bfx::Island **)bfx::MemoryManager::Malloc(
                         this: bfx::g_pCurInstance->m_pMemoryManager,
                         size: 0x190u,
                         tag: bfx::MEM_BFXPLANNER);
  this->m_pTail = v7;
  this->m_searchQueue = v7;
  this->m_pHead = v7;
  *v7 = pStartIsland;
  ++this->m_pTail;
  pStartIsland->m_searchIndex = curIslandSearchIndex;
  return this;
}


// ========================================================================
// ??0IncrementalIRT@bfx@@QAA@PAVIslandGraph@1@HABVPathSpec@1@@Z
// EA  : 0x8327E350
// RVA : 0x0127E350
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

bfx::IncrementalIRT *__fastcall bfx::IncrementalIRT::IncrementalIRT(
        bfx::IncrementalIRT *this,
        bfx::IslandGraph *pIslandGraph,
        int startingIslandNum,
        const bfx::PathSpec *pathSpec)
{
  bfx::IncrementalIRT *v4; // r30
  unsigned int v6; // r11
  char v7; // r11
  bfx::Island *v8; // r29
  bfx::IslandSearcher *v9; // r3
  bfx::IslandSearcher *v10; // r3

  v4 = this;
  this->m_islands = &pIslandGraph->m_islandArray.m_islands;
  v6 = pIslandGraph->m_curIslandSearchIndex + 1;
  pIslandGraph->m_curIslandSearchIndex = v6;
  this->m_islandIndexForIncrementalIRT = v6;
  if ( startingIslandNum < 0 || (v7 = 1, startingIslandNum >= 0x1FFFF) )
    v7 = 0;
  if ( v7 != 0 )
  {
    v8 = this->m_islands->m_data[startingIslandNum];
    v9 = (bfx::IslandSearcher *)bfx::MemoryManager::Malloc(
                                  this: bfx::g_pCurInstance->m_pMemoryManager,
                                  size: 0x18u,
                                  tag: bfx::MEM_BFXPLANNER);
    if ( v9 != nullptr )
      v10 = bfx::IslandSearcher::IslandSearcher(
              this: v9,
              pStartIsland: v8,
              curIslandSearchIndex: v4->m_islandIndexForIncrementalIRT,
              pathSpec);
    else
      v10 = nullptr;
    v4->m_pIslandSearcher = v10;
    return v4;
  }
  else
  {
    this->m_pIslandSearcher = nullptr;
  }
  return this;
}


// ========================================================================
// __unwind$22439
// EA  : 0x8327E418
// RVA : 0x0127E418
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

void _unwind_22439()
{
  int v0; // r12

  bfx::SimulateTask::operator delete(ptr: *(void **)(v0 - 128 + 80), __formal: MEMHEAP_DEFAULT);
}


// ========================================================================
// ??1IncrementalIRT@bfx@@QAA@XZ
// EA  : 0x8327E448
// RVA : 0x0127E448
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

void __fastcall bfx::IncrementalIRT::~IncrementalIRT(bfx::IncrementalIRT *this)
{
  bfx::IslandSearcher *m_pIslandSearcher; // r31

  m_pIslandSearcher = this->m_pIslandSearcher;
  if ( m_pIslandSearcher != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)m_pIslandSearcher->m_searchQueue);
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)m_pIslandSearcher);
  }
  this->m_pIslandSearcher = nullptr;
}


// ========================================================================
// ?AddConnectionPairIfNeeded@Island@bfx@@QAAAAVIslandConnection@2@PAV12@@Z
// EA  : 0x8327E498
// RVA : 0x0127E498
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

bfx::EndPt *__fastcall bfx::Island::AddConnectionPairIfNeeded(bfx::Island *this, bfx::Island *pAdjIsland)
{
  int m_size; // r8
  bfx::Array<bfx::EndPt> *p_m_connections; // r31
  int v6; // r10
  bfx::EndPt *m_data; // r9
  int v8; // r11
  bfx::EndPt *result; // r3
  bfx::EndPt v10[5]; // [sp+50h] [-40h] BYREF

  m_size = this->m_connections.m_size;
  p_m_connections = (bfx::Array<bfx::EndPt> *)&this->m_connections;
  v6 = 0;
  if ( m_size <= 0 )
  {
LABEL_5:
    LODWORD(v10[0].m_val) = pAdjIsland;
    HIBYTE(v10[0].m_pAABB) = 0;
    v10[0].m_type = MIN_X_ENDPT;
    bfx::Array<bfx::FollowerBuddyData>::push_back(this: p_m_connections, val: v10);
    LODWORD(v10[0].m_val) = this;
    HIBYTE(v10[0].m_pAABB) = 0;
    v10[0].m_type = MIN_X_ENDPT;
    bfx::Array<bfx::FollowerBuddyData>::push_back(this: (bfx::Array<bfx::EndPt> *)&pAdjIsland->m_connections, val: v10);
    return &p_m_connections->m_data[p_m_connections->m_size - 1];
  }
  else
  {
    m_data = p_m_connections->m_data;
    v8 = 0;
    while ( 1 )
    {
      result = &m_data[v8];
      if ( (bfx::Island *)LODWORD(m_data[v8].m_val) == pAdjIsland )
        break;
      ++v6;
      ++v8;
      if ( v6 >= m_size )
        goto LABEL_5;
    }
  }
  return result;
}


// ========================================================================
// ?GetIsland@IslandArray@bfx@@QAAPAVIsland@2@H@Z
// EA  : 0x8327E540
// RVA : 0x0127E540
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

bfx::Island *__fastcall bfx::IslandArray::GetIsland(bfx::IslandArray *this, int islandNum)
{
  char v4; // r11
  bfx::Island *result; // r3
  int v6; // r3
  bfx::IslandGraph *m_pIslandGraph; // r11
  bfx::Island *v8; // r10
  bfx::Space *v9; // [sp+50h] [-40h] BYREF

  if ( islandNum < 0 || (v4 = 1, islandNum >= 0x1FFFF) )
    v4 = 0;
  if ( v4 == 0 )
    return nullptr;
  if ( this->m_islands.m_size <= islandNum )
  {
    v9 = nullptr;
    do
      bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)&this->m_islands, val: &v9);
    while ( this->m_islands.m_size <= islandNum );
  }
  result = this->m_islands.m_data[islandNum];
  if ( result == nullptr )
  {
    v6 = bfx::MemoryManager::Malloc(this: bfx::g_pCurInstance->m_pMemoryManager, size: 0x28u, tag: bfx::MEM_ISLANDS);
    if ( v6 != 0 )
    {
      m_pIslandGraph = this->m_pIslandGraph;
      *(_DWORD *)(v6 + 8) = islandNum;
      v8 = (bfx::Island *)v6;
      *(_BYTE *)(v6 + 12) = 0;
      *(_DWORD *)(v6 + 20) = 0;
      *(_DWORD *)(v6 + 16) = 0xFFFF;
      *(_DWORD *)v6 = m_pIslandGraph;
      *(_DWORD *)(v6 + 36) = bfx::MEM_ISLANDS;
      *(_DWORD *)(v6 + 24) = 0;
      *(_DWORD *)(v6 + 28) = 0;
      *(_DWORD *)(v6 + 32) = 0;
      *(_DWORD *)(v6 + 4) = *(_DWORD *)(*(_DWORD *)v6 + 40);
    }
    else
    {
      v8 = nullptr;
    }
    this->m_islands.m_data[islandNum] = v8;
    return this->m_islands.m_data[islandNum];
  }
  return result;
}


// ========================================================================
// ?UpdateForHalfLinkEnabled@IslandGraph@bfx@@AAAXPAVHalfLink@2@@Z
// EA  : 0x8327E658
// RVA : 0x0127E658
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

void __fastcall bfx::IslandGraph::UpdateForHalfLinkEnabled(bfx::IslandGraph *this, bfx::HalfLink *pLink)
{
  char v3; // r11
  bfx::IslandArray *p_m_islandArray; // r31
  bfx::Island *Island; // r29
  bfx::Island *v6; // r4
  unsigned int m_linkUsageFlags; // r31
  bfx::EndPt *v8; // r3

  if ( (*((_BYTE *)pLink + 44) & 0x80) == 0
    || (*((_BYTE *)pLink + 44) & 0x40) != 0
    || (v3 = 1, (*((_BYTE *)pLink + 44) & 0x20) != 0) )
  {
    v3 = 0;
  }
  if ( v3 != 0 )
  {
    p_m_islandArray = &this->m_islandArray;
    Island = bfx::IslandArray::GetIsland(
               this: &this->m_islandArray,
               islandNum: (pLink->m_pArea->m_flags.m_flags1 >> 7) & 0x1FFFF);
    v6 = bfx::IslandArray::GetIsland(
           this: p_m_islandArray,
           islandNum: (pLink->m_pTwin->m_pArea->m_flags.m_flags1 >> 7) & 0x1FFFF);
    if ( Island != v6 )
    {
      m_linkUsageFlags = pLink->m_pLinkBase->m_linkDat.m_linkUsageFlags;
      v8 = bfx::Island::AddConnectionPairIfNeeded(this: Island, pAdjIsland: v6);
      v8->m_type |= m_linkUsageFlags;
    }
  }
}


// ========================================================================
// ?UpdateForLinkEnabled@IslandGraph@bfx@@QAAXPAVHalfLink@2@@Z
// EA  : 0x8327E708
// RVA : 0x0127E708
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

void __fastcall bfx::IslandGraph::UpdateForLinkEnabled(bfx::IslandGraph *this, bfx::HalfLink *pLink)
{
  bfx::IslandGraph::UpdateForHalfLinkEnabled(this, pLink);
  bfx::IslandGraph::UpdateForHalfLinkEnabled(this, pLink: pLink->m_pTwin);
}


// ========================================================================
// ?RemoveUnneededConnections@Island@bfx@@QAAXXZ
// EA  : 0x8327E750
// RVA : 0x0127E750
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

void __fastcall bfx::Island::RemoveUnneededConnections(bfx::Island *this)
{
  bfx::Array<bfx::IslandConnection> *p_m_connections; // r29
  int v3; // r25
  int v4; // r28
  char v5; // r7
  bfx::IslandConnection *v6; // r11
  int v7; // r10
  bfx::Island *m_pAdjIsland; // r11
  int v9; // r30
  bfx::Array<bfx::IslandConnection> *v10; // r31
  bfx::IslandConnection *m_data; // r9
  int v12; // r11
  char v13; // r11
  bool v14; // zf
  bfx::IslandConnection *v15; // r3
  unsigned int v16; // r11
  unsigned int v17; // r3
  unsigned int v18; // r11

  p_m_connections = &this->m_connections;
  v3 = 0;
  if ( this->m_connections.m_size > 0 )
  {
    v4 = 0;
    do
    {
      v5 = 0;
      v6 = &p_m_connections->m_data[v4];
      if ( v6->m_surfaceConnected || (LOBYTE(v7) = 0, v6->m_linkUsageFlags != 0) )
        LOBYTE(v7) = 1;
      v7 = (unsigned __int8)v7;
      if ( (_BYTE)v7 == 0 )
      {
        m_pAdjIsland = v6->m_pAdjIsland;
        v9 = 0;
        v10 = &m_pAdjIsland->m_connections;
        if ( m_pAdjIsland->m_connections.m_size > 0 )
        {
          m_data = v10->m_data;
          while ( 1 )
          {
            v12 = (int)m_data + v7;
            if ( *(bfx::Island **)((char *)&m_data->m_pAdjIsland + v7) == this )
            {
              if ( *(_BYTE *)(v12 + 4) != 0 || (v14 = *(_DWORD *)(v12 + 8) == 0, v13 = 0, !v14) )
                v13 = 1;
              if ( v13 == 0 )
                break;
            }
            ++v9;
            v7 += 12;
            if ( v9 >= v10->m_size )
              goto LABEL_21;
          }
          v15 = &p_m_connections->m_data[v4];
          v16 = (unsigned int)&p_m_connections->m_data[p_m_connections->m_size - 1];
          if ( (unsigned int)v15 < v16 )
            blkmov(a1: v15, a2: &v15[1], a3: 12 * ((v16 - (unsigned int)v15 - 1) / 0xC + 1));
          --p_m_connections->m_size;
          v17 = (unsigned int)&v10->m_data[v9];
          v18 = (unsigned int)&v10->m_data[v10->m_size - 1];
          if ( v17 < v18 )
            blkmov(a1: v17, a2: v17 + 12, a3: 12 * ((v18 - v17 - 1) / 0xC + 1));
          v5 = 1;
          --v10->m_size;
        }
      }
LABEL_21:
      if ( v5 == 0 )
      {
        ++v3;
        ++v4;
      }
    }
    while ( v3 < p_m_connections->m_size );
  }
}


// ========================================================================
// ?RefreshLinkDataForIsland@IslandGraph@bfx@@AAAXPAVIsland@2@PAVArea@2@@Z
// EA  : 0x8327E918
// RVA : 0x0127E918
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

void __fastcall bfx::IslandGraph::RefreshLinkDataForIsland(
        bfx::IslandGraph *this,
        bfx::Island *pIsland,
        bfx::Space *pAreaInIsland,
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
        int a14,
        int a15,
        bfx::Space *a16)
{
  int m_size; // r10
  int v20; // r11
  int v21; // r10
  bfx::IslandConnection *v22; // r8
  unsigned int m_w_low; // r11
  int v24; // r22
  unsigned int SearchIndex; // r3
  int v26; // r27
  __int16 v27; // r21
  char *m_data; // r26
  unsigned int v29; // r20
  int m_cap; // r24
  char *v31; // r11
  _DWORD *v32; // r25
  int i; // r30
  char v34; // r11
  int v35; // r11
  int v36; // r11
  int v37; // r4
  bfx::Island *Island; // r4
  bfx::EndPt *v39; // r3
  int v40; // r28
  int *v41; // r29
  int v42; // r30
  int v43; // r4
  bfx::SearchIndexOb v44[4]; // [sp+50h] [-A0h] BYREF
  bfx::Array<bfx::SpaceComponent *> v45[9]; // [sp+60h] [-90h] BYREF

  m_size = pIsland->m_connections.m_size;
  a16 = pAreaInIsland;
  v20 = 0;
  if ( m_size > 0 )
  {
    v21 = 0;
    do
    {
      ++v20;
      v22 = &pIsland->m_connections.m_data[v21++];
      v22->m_linkUsageFlags = 0;
    }
    while ( v20 < pIsland->m_connections.m_size );
  }
  m_w_low = LODWORD(pAreaInIsland->m_rotWorldToSpace.m_w);
  memset(v45, 0, 12);
  v24 = (m_w_low >> 7) & 0x1FFFF;
  v45[0].m_tag = MEM_TEMP;
  bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)v45, val: &a16);
  bfx::SearchIndexOb::SearchIndexOb(this: v44);
  SearchIndex = bfx::SearchIndexOb::GetSearchIndex(this: v44);
  v26 = v45[0].m_size;
  v27 = SearchIndex;
  m_data = (char *)v45[0].m_data;
  v29 = SearchIndex;
  v44[1].m_pPlannerInstance = (bfx::PlannerInstance *)&pAreaInIsland->m_rotWorldToSpace;
  LOWORD(pAreaInIsland->m_rotWorldToSpace.m_y) = SearchIndex;
  if ( v26 != 0 )
  {
    m_cap = v45[0].m_cap;
    do
    {
      v31 = &m_data[4 * v26--];
      v45[0].m_size = v26;
      v32 = *((_DWORD **)v31 - 1);
      for ( i = v32[2]; i != 0; i = *(_DWORD *)(i + 40) )
      {
        if ( (*(_BYTE *)(i + 44) & 0x80) == 0
          || (*(_BYTE *)(i + 44) & 0x40) != 0
          || (v34 = 1, (*(_BYTE *)(i + 44) & 0x20) != 0) )
        {
          v34 = 0;
        }
        if ( v34 != 0 )
        {
          v35 = *(_DWORD *)(i + 36);
          v36 = v35 != 0 ? *(_DWORD *)(v35 + 32) : 0;
          v37 = (*(_DWORD *)(v36 + 40) >> 7) & 0x1FFFF;
          if ( v37 != v24 )
          {
            Island = bfx::IslandArray::GetIsland(this: &this->m_islandArray, islandNum: v37);
            if ( Island != nullptr )
            {
              v39 = bfx::Island::AddConnectionPairIfNeeded(this: pIsland, pAdjIsland: Island);
              v39->m_type |= *(_DWORD *)(*(_DWORD *)(i + 52) + 44);
            }
          }
        }
      }
      v40 = 0;
      if ( (v32[10] & 0x7F) != 0 )
      {
        v41 = v32 + 14;
        do
        {
          v42 = *v41;
          if ( *v41 != 0 && *(unsigned __int16 *)(v42 + 50) != v29 && ((*(_DWORD *)(v42 + 40) >> 7) & 0x1FFFF) == v24 )
          {
            if ( m_cap == v26 )
            {
              v43 = 2 * m_cap;
              if ( m_cap == 0 )
                v43 = 1;
              bfx::Array<bfx::Edge *>::expand_cap(this: v45, size: v43);
              v26 = v45[0].m_size;
              m_data = (char *)v45[0].m_data;
              m_cap = v45[0].m_cap;
            }
            if ( &m_data[4 * v26] != nullptr )
              *(_DWORD *)&m_data[4 * v26] = v42;
            ++v26;
            *(_WORD *)(v42 + 50) = v27;
            v45[0].m_size = v26;
          }
          ++v40;
          v41 += 6;
        }
        while ( v40 < (v32[10] & 0x7F) );
      }
    }
    while ( v26 != 0 );
  }
  bfx::Island::RemoveUnneededConnections(this: pIsland);
  bfx::SearchIndexOb::~SearchIndexOb(this: v44);
  if ( m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
}


// ========================================================================
// __unwind$23441
// EA  : 0x8327EB70
// RVA : 0x0127EB70
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

void _unwind_23441()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 240 + 96));
}


// ========================================================================
// __unwind$23442
// EA  : 0x8327EB98
// RVA : 0x0127EB98
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

void _unwind_23442()
{
  int v0; // r12

  bfx::SearchIndexOb::~SearchIndexOb(this: (bfx::SearchIndexOb *)(v0 - 240 + 80));
}


// ========================================================================
// ?RemoveAllForwardAndReverseConnections@Island@bfx@@QAAXXZ
// EA  : 0x8327EBC0
// RVA : 0x0127EBC0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

void __fastcall bfx::Island::RemoveAllForwardAndReverseConnections(bfx::Island *this)
{
  bfx::Array<bfx::IslandConnection> *p_m_connections; // r30
  int v3; // r11
  bfx::Island *m_pAdjIsland; // r10
  bfx::Array<bfx::IslandConnection> *v5; // r31
  int m_size; // r10
  bfx::IslandConnection *m_data; // r6
  int v8; // r9
  unsigned int v9; // r3
  unsigned int v10; // r11

  if ( this->m_connections.m_size != 0 )
  {
    p_m_connections = &this->m_connections;
    do
    {
      v3 = 0;
      m_pAdjIsland = p_m_connections->m_data[p_m_connections->m_size - 1].m_pAdjIsland;
      v5 = &m_pAdjIsland->m_connections;
      m_size = m_pAdjIsland->m_connections.m_size;
      if ( m_size > 0 )
      {
        m_data = v5->m_data;
        v8 = 0;
        while ( m_data[v8].m_pAdjIsland != this )
        {
          ++v3;
          ++v8;
          if ( v3 >= v5->m_size )
            goto LABEL_11;
        }
        v9 = (unsigned int)&v5->m_data[v3];
        v10 = (unsigned int)&m_data[m_size - 1];
        if ( v9 < v10 )
          blkmov(a1: v9, a2: v9 + 12, a3: 12 * ((v10 - v9 - 1) / 0xC + 1));
        --v5->m_size;
      }
LABEL_11:
      --p_m_connections->m_size;
    }
    while ( this->m_connections.m_size != 0 );
  }
}


// ========================================================================
// ?SearchToIsland@IncrementalIRT@bfx@@ABAXH@Z
// EA  : 0x8327ECC0
// RVA : 0x0127ECC0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

void __fastcall bfx::IncrementalIRT::SearchToIsland(bfx::IncrementalIRT *this, int islandNum)
{
  bfx::IslandSearcher *m_pIslandSearcher; // r31
  bfx::Island *i; // r23
  bfx::Island **m_pHead; // r11
  int v6; // r25
  bfx::Island **v7; // r10
  bfx::Island *v8; // r11
  bfx::Array<bfx::IslandConnection> *p_m_connections; // r28
  int v10; // r27
  bfx::IslandConnection *v11; // r7
  bfx::Island *m_pAdjIsland; // r11
  const bfx::PathSpec *m_pathSpec; // r10
  unsigned int m_obstacleBlockageFlags; // r8
  unsigned int v15; // r9
  unsigned int m_areaUsageFlags; // r9
  unsigned int m_islandIndexForSearch; // r9
  unsigned int m_queueCapacity; // r11
  unsigned int v20; // r30
  void *v21; // r22
  char *m_searchQueue; // r4
  int v23; // r30
  bfx::Island **v24; // r9
  bfx::Island **m_pTail; // r10

  m_pIslandSearcher = this->m_pIslandSearcher;
  if ( m_pIslandSearcher != nullptr )
  {
    for ( i = this->m_islands->m_data[islandNum];
          m_pIslandSearcher->m_pHead != m_pIslandSearcher->m_pTail;
          m_pIslandSearcher = this->m_pIslandSearcher )
    {
      m_pHead = m_pIslandSearcher->m_pHead;
      if ( *m_pHead == i )
        break;
      v6 = 0;
      v7 = m_pHead + 1;
      v8 = *m_pHead;
      m_pIslandSearcher->m_pHead = v7;
      p_m_connections = &v8->m_connections;
      if ( v8->m_connections.m_size > 0 )
      {
        v10 = 0;
        do
        {
          v11 = &p_m_connections->m_data[v10];
          m_pAdjIsland = v11->m_pAdjIsland;
          if ( v11->m_pAdjIsland->m_searchIndex != m_pIslandSearcher->m_islandIndexForSearch )
          {
            m_pathSpec = m_pIslandSearcher->m_pathSpec;
            m_obstacleBlockageFlags = m_pAdjIsland->m_obstacleBlockageFlags;
            v15 = m_pathSpec->m_obstacleBlockageFlags;
            if ( !(m_pathSpec->m_obstacleMode != BLOCKED_IF_ANY_MATCH
                 ? (_cntlzw(v15 - (v15 & m_obstacleBlockageFlags)) & 0x20) != 0
                 : (v15 & m_obstacleBlockageFlags) != 0) )
            {
              m_areaUsageFlags = m_pAdjIsland->m_areaUsageFlags;
              if ( (m_areaUsageFlags == 0 || (m_pathSpec->m_areaUsageFlags & m_areaUsageFlags) != 0)
                && (v11->m_surfaceConnected || (m_pathSpec->m_linkUsageFlags & v11->m_linkUsageFlags) != 0) )
              {
                *m_pIslandSearcher->m_pTail = m_pAdjIsland;
                m_islandIndexForSearch = m_pIslandSearcher->m_islandIndexForSearch;
                ++m_pIslandSearcher->m_pTail;
                m_pAdjIsland->m_searchIndex = m_islandIndexForSearch;
                m_queueCapacity = m_pIslandSearcher->m_queueCapacity;
                v20 = m_pIslandSearcher->m_pTail - m_pIslandSearcher->m_searchQueue;
                if ( v20 >= m_queueCapacity )
                {
                  m_pIslandSearcher->m_queueCapacity = 2 * m_queueCapacity;
                  v21 = (void *)bfx::MemoryManager::Malloc(
                                  this: bfx::g_pCurInstance->m_pMemoryManager,
                                  size: 8 * m_queueCapacity,
                                  tag: bfx::MEM_BFXPLANNER);
                  memcpy(Dst: v21, Src: m_pIslandSearcher->m_searchQueue, Size: 4 * v20);
                  m_searchQueue = (char *)m_pIslandSearcher->m_searchQueue;
                  v23 = ((_BYTE *)v21 - m_searchQueue) >> 2;
                  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_searchQueue);
                  v24 = m_pIslandSearcher->m_pHead;
                  m_pTail = m_pIslandSearcher->m_pTail;
                  m_pIslandSearcher->m_searchQueue = (bfx::Island **)v21;
                  m_pIslandSearcher->m_pHead = &v24[v23];
                  m_pIslandSearcher->m_pTail = &m_pTail[v23];
                }
              }
            }
          }
          ++v6;
          ++v10;
        }
        while ( v6 < p_m_connections->m_size );
      }
    }
  }
}


// ========================================================================
// ?IsReachable@IncrementalIRT@bfx@@QBA_NH@Z
// EA  : 0x8327EEA8
// RVA : 0x0127EEA8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

BOOL __fastcall bfx::IncrementalIRT::IsReachable(bfx::IncrementalIRT *this, int islandNum)
{
  bfx::IslandSearcher *m_pIslandSearcher; // r11
  int v4; // r30

  m_pIslandSearcher = this->m_pIslandSearcher;
  if ( m_pIslandSearcher == nullptr || islandNum == 0x1FFFF )
    return false;
  v4 = islandNum;
  if ( this->m_islands->m_data[islandNum]->m_searchIndex == this->m_islandIndexForIncrementalIRT )
    return true;
  if ( m_pIslandSearcher->m_pHead == m_pIslandSearcher->m_pTail )
    return false;
  bfx::IncrementalIRT::SearchToIsland(this, islandNum);
  return (_cntlzw(this->m_islandIndexForIncrementalIRT - this->m_islands->m_data[v4]->m_searchIndex) & 0x20) != 0;
}


// ========================================================================
// ?IsIslandReachableFromIsland@IslandGraph@bfx@@QAA_NHHABVPathSpec@2@@Z
// EA  : 0x8327EF60
// RVA : 0x0127EF60
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

int __fastcall bfx::IslandGraph::IsIslandReachableFromIsland(
        bfx::IslandGraph *this,
        int startIsland,
        int goalIsland,
        const bfx::PathSpec *pathSpec)
{
  bfx::IslandArray *p_m_islandArray; // r31
  unsigned int v7; // r24
  bfx::Island *Island; // r29
  bfx::Island *v9; // r17
  unsigned int v10; // r27
  bfx::Island **v11; // r3
  char *v12; // r28
  char *v13; // r30
  bfx::Island **v14; // r26
  bfx::Island *v15; // r9
  unsigned int m_obstacleBlockageFlags; // r11
  unsigned int v17; // r10
  bool v18; // r18
  bfx::Array<bfx::IslandConnection> *p_m_connections; // r21
  int v20; // r19
  int v21; // r22
  bfx::IslandConnection *v22; // r8
  bfx::Island *m_pAdjIsland; // r11
  unsigned int v24; // r9
  unsigned int v25; // r10
  bool v26; // r10
  unsigned int m_areaUsageFlags; // r10
  unsigned int v28; // r29
  void *v29; // r31
  int v30; // r30

  if ( startIsland == goalIsland )
    return 1;
  p_m_islandArray = &this->m_islandArray;
  v7 = this->m_curIslandSearchIndex + 1;
  this->m_curIslandSearchIndex = v7;
  Island = bfx::IslandArray::GetIsland(this: &this->m_islandArray, islandNum: startIsland);
  v9 = bfx::IslandArray::GetIsland(this: p_m_islandArray, islandNum: goalIsland);
  v10 = 100;
  v11 = (bfx::Island **)bfx::MemoryManager::Malloc(
                          this: bfx::g_pCurInstance->m_pMemoryManager,
                          size: 0x190u,
                          tag: bfx::MEM_BFXPLANNER);
  v12 = (char *)(v11 + 1);
  *v11 = Island;
  v13 = (char *)v11;
  Island->m_searchIndex = v7;
  v14 = v11;
  do
  {
    v15 = *v14;
    m_obstacleBlockageFlags = pathSpec->m_obstacleBlockageFlags;
    v17 = (*v14++)->m_obstacleBlockageFlags;
    if ( pathSpec->m_obstacleMode != BLOCKED_IF_ANY_MATCH )
      v18 = (_cntlzw(m_obstacleBlockageFlags - (m_obstacleBlockageFlags & v17)) & 0x20) != 0;
    else
      v18 = (m_obstacleBlockageFlags & v17) != 0;
    p_m_connections = &v15->m_connections;
    v20 = 0;
    if ( v15->m_connections.m_size > 0 )
    {
      v21 = 0;
      do
      {
        v22 = &p_m_connections->m_data[v21];
        m_pAdjIsland = v22->m_pAdjIsland;
        if ( v22->m_pAdjIsland->m_searchIndex != v7 )
        {
          v24 = m_pAdjIsland->m_obstacleBlockageFlags;
          v25 = pathSpec->m_obstacleBlockageFlags;
          v26 = pathSpec->m_obstacleMode != BLOCKED_IF_ANY_MATCH
              ? (_cntlzw(v25 - (v25 & v24)) & 0x20) != 0
              : (v25 & v24) != 0;
          if ( !v26 || v18 )
          {
            m_areaUsageFlags = m_pAdjIsland->m_areaUsageFlags;
            if ( (m_areaUsageFlags == 0 || (pathSpec->m_areaUsageFlags & m_areaUsageFlags) != 0)
              && (v22->m_surfaceConnected || (v22->m_linkUsageFlags & pathSpec->m_linkUsageFlags) != 0) )
            {
              if ( m_pAdjIsland == v9 )
              {
                bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v13);
                return 1;
              }
              *(_DWORD *)v12 = m_pAdjIsland;
              v12 += 4;
              m_pAdjIsland->m_searchIndex = v7;
              v28 = (v12 - v13) >> 2;
              if ( v28 >= v10 )
              {
                v10 *= 2;
                v29 = (void *)bfx::MemoryManager::Malloc(
                                this: bfx::g_pCurInstance->m_pMemoryManager,
                                size: 4 * v10,
                                tag: bfx::MEM_BFXPLANNER);
                memcpy(Dst: v29, Src: v13, Size: 4 * v28);
                bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v13);
                v30 = ((_BYTE *)v29 - v13) >> 2;
                v14 += v30;
                v12 += 4 * v30;
                v13 = (char *)v29;
              }
            }
          }
        }
        ++v20;
        ++v21;
      }
      while ( v20 < p_m_connections->m_size );
    }
  }
  while ( v14 != (bfx::Island **)v12 );
  bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v13);
  return 0;
}


// ========================================================================
// ?IslandFloodFill@bfx@@YAXPAVIsland@1@IAAV?$Array@PAVIsland@bfx@@@1@@Z
// EA  : 0x8327F1B0
// RVA : 0x0127F1B0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

void __fastcall bfx::IslandFloodFill(
        bfx::Space *pStartIsland,
        unsigned int curIslandSearchIndex,
        bfx::Array<bfx::Space *> *closedList,
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
  int m_size; // r29
  char *m_data; // r27
  int m_cap; // r23
  char *v17; // r11
  int v18; // r30
  _DWORD *v19; // r28
  int v20; // r25
  int v21; // r26
  int v22; // r30
  int v23; // r4
  bfx::Space *v24; // [sp+50h] [-80h] BYREF
  bfx::Array<bfx::SpaceComponent *> v25[7]; // [sp+60h] [-70h] BYREF

  a12 = pStartIsland;
  memset(v25, 0, 12);
  v25[0].m_tag = MEM_TEMP;
  bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)v25, val: &a12);
  m_size = v25[0].m_size;
  m_data = (char *)v25[0].m_data;
  if ( v25[0].m_size != 0 )
  {
    m_cap = v25[0].m_cap;
    do
    {
      v17 = &m_data[4 * m_size--];
      v25[0].m_size = m_size;
      v18 = *((_DWORD *)v17 - 1);
      v24 = (bfx::Space *)v18;
      *(_DWORD *)(v18 + 4) = curIslandSearchIndex;
      bfx::Array<bfx::Portal *>::push_back(this: closedList, val: &v24);
      v19 = (_DWORD *)(v18 + 24);
      v20 = 0;
      if ( *(int *)(v18 + 28) > 0 )
      {
        v21 = 0;
        do
        {
          v22 = *(_DWORD *)(*v19 + v21);
          if ( *(_DWORD *)(v22 + 4) != curIslandSearchIndex )
          {
            if ( m_cap == m_size )
            {
              v23 = 2 * m_cap;
              if ( m_cap == 0 )
                v23 = 1;
              bfx::Array<bfx::Edge *>::expand_cap(this: v25, size: v23);
              m_size = v25[0].m_size;
              m_data = (char *)v25[0].m_data;
              m_cap = v25[0].m_cap;
            }
            if ( &m_data[4 * m_size] != nullptr )
              *(_DWORD *)&m_data[4 * m_size] = v22;
            v25[0].m_size = ++m_size;
          }
          ++v20;
          v21 += 12;
        }
        while ( v20 < v19[1] );
      }
    }
    while ( m_size != 0 );
  }
  if ( m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
}


// ========================================================================
// __unwind$24040
// EA  : 0x8327F2DC
// RVA : 0x0127F2DC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

void _unwind_24040()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 208 + 96));
}


// ========================================================================
// ?DrawStats@IslandGraph@bfx@@QAAXXZ
// EA  : 0x8327F310
// RVA : 0x0127F310
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall bfx::IslandGraph::DrawStats(bfx::IslandGraph *this, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v6; // r4
  __int64 v7; // r8
  __int64 v8; // r6
  __int64 v9; // r4
  int v10; // r30
  const bfx::bfxMemTag *p_m_tag; // r11
  __int64 v12; // r10
  int v13; // ctr
  unsigned int v14; // r27
  char *m_data; // r28
  int m_size; // r25
  int v17; // r26
  unsigned int v18; // r11
  __int64 v19; // r10
  __int64 v20; // r8
  __int64 v21; // r6
  __int64 v22; // r4
  int v23; // [sp+8h] [-C8h]
  int v24; // [sp+8h] [-C8h]
  int v25; // [sp+8h] [-C8h]
  int v26; // [sp+Ch] [-C4h]
  int v27; // [sp+Ch] [-C4h]
  int v28; // [sp+Ch] [-C4h]
  int v29; // [sp+10h] [-C0h]
  int v30; // [sp+10h] [-C0h]
  int v31; // [sp+10h] [-C0h]
  int v32; // [sp+14h] [-BCh]
  bfx::Space *v33; // [sp+14h] [-BCh]
  int v34; // [sp+14h] [-BCh]
  bfx::Array<bfx::Space *> v35; // [sp+50h] [-80h] BYREF
  _DWORD v36[28]; // [sp+60h] [-70h] BYREF

  HIDWORD(v6) = "Island Group Size Histogram\n\n";
  bfx::DrawString(fmt: v6, a2: a3, a3: a4, a4: a5, a5: v23, a6: v26, a7: v29, a8: v32);
  v10 = 0;
  p_m_tag = &v35.m_tag;
  HIDWORD(v12) = 0;
  v13 = 10;
  v14 = this->m_curIslandSearchIndex + 1;
  this->m_curIslandSearchIndex = v14;
  do
  {
    *++p_m_tag = MEM_DEFAULT;
    --v13;
  }
  while ( v13 != 0 );
  m_data = nullptr;
  v35.m_tag = MEM_TEMP;
  memset(&v35, 0, 12);
  LODWORD(v12) = this->m_largestIslandNumberEverUsed;
  m_size = 0;
  v17 = 0;
  if ( (int)v12 >= 0 )
  {
    do
    {
      HIDWORD(v9) = bfx::IslandArray::GetIsland(this: &this->m_islandArray, islandNum: v17);
      if ( *(_BYTE *)(HIDWORD(v9) + 12) != 0 && *(_DWORD *)(HIDWORD(v9) + 4) != v14 )
      {
        v35.m_size = 0;
        bfx::IslandFloodFill(
          pStartIsland: (bfx::Space *)HIDWORD(v9),
          curIslandSearchIndex: v14,
          closedList: &v35,
          a4: v8,
          a5: SHIDWORD(v7),
          a6: v7,
          a7: SHIDWORD(v12),
          a8: v12,
          a9: v24,
          a10: v27,
          a11: v30,
          a12: v33);
        if ( m_size <= v35.m_size )
          m_size = v35.m_size;
        if ( v35.m_size / 5 <= 9 )
          v18 = (((unsigned int)(v35.m_size / 5) >> 31) - 1) & (v35.m_size / 5);
        else
          v18 = 9;
        LODWORD(v12) = 4 * v18;
        HIDWORD(v12) = v36[v18] + 1;
        v36[v18] = HIDWORD(v12);
      }
      ++v17;
    }
    while ( v17 <= this->m_largestIslandNumberEverUsed );
    m_data = (char *)v35.m_data;
  }
  HIDWORD(v9) = "group size        num groups\n";
  bfx::DrawString(fmt: v9, a2: v8, a3: v7, a4: v12, a5: v24, a6: v27, a7: v30, a8: (int)v33);
  do
  {
    HIDWORD(v21) = 5 * v10 + 4;
    if ( v10 == 9 && SHIDWORD(v21) <= m_size )
      HIDWORD(v21) = m_size;
    LODWORD(v19) = v36;
    HIDWORD(v22) = "%3d -%3d          %3d\n";
    LODWORD(v21) = v36[v10];
    LODWORD(v22) = 5 * v10;
    bfx::DrawString(fmt: v22, a2: v21, a3: v20, a4: v19, a5: v25, a6: v28, a7: v31, a8: v34);
    ++v10;
  }
  while ( v10 < 10 );
  if ( m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
}


// ========================================================================
// __unwind$24238
// EA  : 0x8327F490
// RVA : 0x0127F490
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

void _unwind_24238()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 208 + 80));
}


// ========================================================================
// ?Draw@IslandGraph@bfx@@QAAXXZ
// EA  : 0x8327F4B8
// RVA : 0x0127F4B8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

// local variable allocation has failed, the output may be wrong!
void __fastcall bfx::IslandGraph::Draw(bfx::IslandGraph *this, int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v6; // r4
  __int64 v7; // r10
  __int64 v8; // r4
  __int64 v9; // r8
  __int64 v10; // r6
  int i; // r23
  bfx::Island *Island; // r3
  bfx::Island *v13; // r30
  char *v14; // r31
  __int64 v15; // r10
  __int64 v16; // r8
  __int64 v17; // r6
  int v18; // r3
  bfx::Array<bfx::IslandConnection> *p_m_connections; // r27
  char v20; // r11
  int v21; // r28
  int v22; // r30
  bfx::IslandConnection *m_data; // r29
  int v24; // r3
  int v25; // r3
  __int64 v26; // r4
  int v27; // [sp+8h] [-4B8h]
  int v28; // [sp+8h] [-4B8h]
  int v29; // [sp+8h] [-4B8h]
  int v30; // [sp+Ch] [-4B4h]
  int v31; // [sp+Ch] [-4B4h]
  int v32; // [sp+Ch] [-4B4h]
  int v33; // [sp+10h] [-4B0h]
  int v34; // [sp+10h] [-4B0h]
  int v35; // [sp+10h] [-4B0h]
  int v36; // [sp+14h] [-4ACh]
  int v37; // [sp+14h] [-4ACh]
  int v38; // [sp+14h] [-4ACh]
  char v39[1136]; // [sp+50h] [-470h] BYREF

  HIDWORD(v6) = "Island Adjacencies\n";
  bfx::DrawString(fmt: v6, a2: a3, a3: a4, a4: a5, a5: v27, a6: v30, a7: v33, a8: v36);
  LODWORD(v7) = &unk_82410000;
  HIDWORD(v8) = "island -> adjacent islands\n";
  bfx::DrawString(fmt: v8, a2: v10, a3: v9, a4: v7, a5: v28, a6: v31, a7: v34, a8: v37);
  for ( i = 0; i <= this->m_largestIslandNumberEverUsed; ++i )
  {
    Island = bfx::IslandArray::GetIsland(this: &this->m_islandArray, islandNum: i);
    v13 = Island;
    if ( Island->m_inUse )
    {
      v14 = v39;
      v18 = sprintf_0(string: v39, format: "%d -> ", Island->m_islandNum);
      if ( v18 > 0 )
        v14 = &v39[v18];
      LODWORD(v15) = v13->m_connections.m_size;
      p_m_connections = &v13->m_connections;
      v20 = 1;
      v21 = 0;
      if ( (int)v15 > 0 )
      {
        v22 = 0;
        do
        {
          m_data = p_m_connections->m_data;
          if ( v20 == 0 )
          {
            v24 = sprintf_0(string: v14, format: ",");
            if ( v24 > 0 )
              v14 += v24;
          }
          v25 = sprintf_0(string: v14, format: "%d", m_data[v22].m_pAdjIsland->m_islandNum);
          if ( v25 > 0 )
            v14 += v25;
          LODWORD(v15) = p_m_connections->m_size;
          ++v21;
          v20 = 0;
          ++v22;
        }
        while ( v21 < (int)v15 );
      }
      HIDWORD(v26) = "%s\n";
      LODWORD(v26) = v39;
      bfx::DrawString(fmt: v26, a2: v17, a3: v16, a4: v15, a5: v29, a6: v32, a7: v35, a8: v38);
    }
  }
}


// ========================================================================
// ?GetUnusedIslandNum@IslandGraph@bfx@@AAAHXZ
// EA  : 0x8327F5F8
// RVA : 0x0127F5F8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

int __fastcall bfx::IslandGraph::GetUnusedIslandNum(bfx::IslandGraph *this)
{
  bfx::List<int> *p_m_availableIslandNumbers; // r10
  bfx::List<int>::Node *m_pNext; // r7
  int result; // r3
  bfx::Pool *m_pPool; // r6
  int m_numIslandsInUse; // r9

  p_m_availableIslandNumbers = &this->m_availableIslandNumbers;
  if ( this->m_availableIslandNumbers.m_pEnd->m_pNext == this->m_availableIslandNumbers.m_pEnd )
  {
    result = 0x1FFFF;
    if ( this->m_largestIslandNumberEverUsed != 131070 )
    {
      m_numIslandsInUse = this->m_numIslandsInUse;
      result = this->m_largestIslandNumberEverUsed + 1;
      this->m_largestIslandNumberEverUsed = result;
      this->m_numIslandsInUse = m_numIslandsInUse + 1;
    }
  }
  else
  {
    m_pNext = this->m_availableIslandNumbers.m_pEnd->m_pNext;
    result = m_pNext->m_val;
    m_pNext->m_pPrev->m_pNext = m_pNext->m_pNext;
    m_pNext->m_pNext->m_pPrev = m_pNext->m_pPrev;
    m_pPool = p_m_availableIslandNumbers->m_pPool;
    m_pNext->m_val = (int)p_m_availableIslandNumbers->m_pPool->m_data.m_pUnused;
    m_pPool->m_data.m_pUnused = (bfx::Pool::Node *)m_pNext;
    ++this->m_numIslandsInUse;
  }
  return result;
}


// ========================================================================
// ?GetArrayMapForLayer@IslandsTouchedArray@bfx@@QAAAAV?$ArrayMap@PAVArea@bfx@@@2@H@Z
// EA  : 0x8327F798
// RVA : 0x0127F798
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

bfx::ArrayMap<bfx::Area *> *__fastcall bfx::IslandsTouchedArray::GetArrayMapForLayer(
        bfx::IslandsTouchedArray *this,
        int layerNum)
{
  int v2; // r30
  bfx::ArrayMap<bfx::Area *> *v4; // r3
  bfx::ArrayMap<bfx::Area *> *v5; // r11

  v2 = layerNum;
  if ( this->m_pIslandsTouched[layerNum] == nullptr )
  {
    v4 = (bfx::ArrayMap<bfx::Area *> *)bfx::MemoryManager::Malloc(
                                         this: bfx::g_pCurInstance->m_pMemoryManager,
                                         size: 0x10u,
                                         tag: 2);
    v5 = nullptr;
    if ( v4 != nullptr )
    {
      v4->m_array.m_data = nullptr;
      v4->m_array.m_size = 0;
      v4->m_array.m_cap = 0;
      v5 = v4;
      v4->m_array.m_tag = MEM_TEMP;
    }
    this->m_pIslandsTouched[v2] = v5;
  }
  return this->m_pIslandsTouched[v2];
}


// ========================================================================
// ??1IslandArray@bfx@@QAA@XZ
// EA  : 0x8327F828
// RVA : 0x0127F828
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

void __fastcall bfx::IslandArray::~IslandArray(bfx::IslandArray *this)
{
  bfx::Array<bfx::Island *> *p_m_islands; // r28
  int v2; // r25
  int v3; // r27
  bfx::Island *v4; // r30
  char *m_data; // r4
  char *v6; // r4

  p_m_islands = &this->m_islands;
  v2 = 0;
  if ( this->m_islands.m_size > 0 )
  {
    v3 = 0;
    do
    {
      v4 = p_m_islands->m_data[v3];
      if ( v4 != nullptr )
      {
        m_data = (char *)v4->m_connections.m_data;
        v4->m_connections.m_size = 0;
        if ( m_data != nullptr )
        {
          bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
          v4->m_connections.m_data = nullptr;
        }
        v4->m_connections.m_cap = 0;
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v4);
      }
      ++v2;
      p_m_islands->m_data[v3++] = nullptr;
    }
    while ( v2 < p_m_islands->m_size );
  }
  v6 = (char *)p_m_islands->m_data;
  p_m_islands->m_size = 0;
  if ( v6 != nullptr )
  {
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: v6);
    p_m_islands->m_data = nullptr;
  }
  p_m_islands->m_cap = 0;
}


// ========================================================================
// __unwind$24816
// EA  : 0x8327F8E8
// RVA : 0x0127F8E8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

void _unwind_24816()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(*(_DWORD *)(v0 - 144 + 164)
                                                                                             + 4));
}


// ========================================================================
// ??0IslandGraph@bfx@@QAA@XZ
// EA  : 0x8327F918
// RVA : 0x0127F918
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

bfx::IslandGraph *__fastcall bfx::IslandGraph::IslandGraph(bfx::IslandGraph *this)
{
  bfx::bfxMemTag v3; // r11

  this->m_numIslandsInUse = 0;
  bfx::List<bfx::Area *>::List<bfx::Area *>(
    this: (bfx::List<bfx::Island3D *> *)&this->m_availableIslandNumbers,
    numNodesPerPoolBlock: 0x64u,
    memTag: bfx::MEM_BFXPLANNER);
  this->m_largestIslandNumberEverUsed = -1;
  this->m_islandArray.m_pIslandGraph = nullptr;
  v3 = bfx::MEM_BFXPLANNER;
  this->m_islandArray.m_islands.m_data = nullptr;
  this->m_islandArray.m_islands.m_size = 0;
  this->m_islandArray.m_islands.m_cap = 0;
  this->m_islandArray.m_islands.m_tag = v3;
  this->m_curIslandSearchIndex = 0;
  this->m_islandArray.m_pIslandGraph = this;
  return this;
}


// ========================================================================
// ??1IslandGraph@bfx@@QAA@XZ
// EA  : 0x8327F988
// RVA : 0x0127F988
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

void __fastcall bfx::IslandGraph::~IslandGraph(bfx::IslandGraph *this)
{
  bfx::IslandArray::~IslandArray(this: &this->m_islandArray);
  bfx::List<bfx::Area *>::~List<bfx::Area *>(this: (bfx::List<bfx::Island3D *> *)&this->m_availableIslandNumbers);
}


// ========================================================================
// __unwind$24963
// EA  : 0x8327F9D0
// RVA : 0x0127F9D0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

void _unwind_24963()
{
  int v0; // r12

  bfx::List<bfx::Area *>::~List<bfx::Area *>(this: (bfx::List<bfx::Island3D *> *)(*(_DWORD *)(v0 - 112 + 132) + 4));
}


// ========================================================================
// ?RefreshLinkData@IslandGraph@bfx@@QAAXAAV?$ArrayMap@PAVArea@bfx@@@2@@Z
// EA  : 0x8327FA00
// RVA : 0x0127FA00
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

void __fastcall bfx::IslandGraph::RefreshLinkData(bfx::IslandGraph *this, bfx::ArrayMap<bfx::Area *> *islandsTouched)
{
  int v4; // r28
  bfx::IslandArray *p_m_islandArray; // r29
  int v6; // r31
  __int64 v7; // r8
  __int64 v8; // r4
  __int64 v9; // r10
  __int64 v10; // r6
  int v11; // [sp+8h] [-88h]
  int v12; // [sp+Ch] [-84h]
  int v13; // [sp+10h] [-80h]
  int v14; // [sp+14h] [-7Ch]
  int v15; // [sp+18h] [-78h]
  int v16; // [sp+1Ch] [-74h]
  int v17; // [sp+20h] [-70h]
  bfx::Space *v18; // [sp+24h] [-6Ch]

  v4 = 0;
  if ( islandsTouched->m_array.m_size > 0 )
  {
    p_m_islandArray = &this->m_islandArray;
    v6 = 0;
    do
    {
      LODWORD(v8) = bfx::IslandArray::GetIsland(
                      this: p_m_islandArray,
                      islandNum: islandsTouched->m_array.m_data[v6].m_first);
      LODWORD(v9) = &islandsTouched->m_array.m_data[v6];
      HIDWORD(v10) = *(_DWORD *)(v9 + 4);
      if ( (_DWORD)v8 != 0 && HIDWORD(v10) != 0 )
      {
        bfx::IslandGraph::RefreshLinkDataForIsland(
          this,
          pIsland: (bfx::Island *)v8,
          pAreaInIsland: (bfx::Space *)HIDWORD(v10),
          a4: v10,
          a5: SHIDWORD(v7),
          a6: v7,
          a7: SHIDWORD(v9),
          a8: v9,
          a9: v11,
          a10: v12,
          a11: v13,
          a12: v14,
          a13: v15,
          a14: v16,
          a15: v17,
          a16: v18);
      }
      else
      {
        HIDWORD(v8) = "Unexpected error in RefreshLinkData(). Please report.\n";
        bfx::InternalWarning(fmt: v8, a2: v10, a3: v7, a4: v9, a5: v11, a6: v12, a7: v13, a8: v14);
      }
      ++v4;
      ++v6;
    }
    while ( v4 < islandsTouched->m_array.m_size );
  }
}


// ========================================================================
// ?CreateIsland@IslandGraph@bfx@@AAA_NPAVArea@2@PAV?$Array@PAVArea@bfx@@@2@@Z
// EA  : 0x8327FAA0
// RVA : 0x0127FAA0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

int __fastcall bfx::IslandGraph::CreateIsland(
        bfx::IslandGraph *this,
        bfx::NavProbeDisplayData *pStartArea,
        bfx::Array<bfx::Space *> *pOutsideLimitsAreas,
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
        bfx::NavProbeDisplayData *a14)
{
  __int64 v17; // r10
  __int64 v18; // r8
  __int64 v19; // r6
  int UnusedIslandNum; // r3
  int v21; // r17
  __int64 v22; // r4
  bfx::List<int>::Node *m_pEnd; // r9
  bfx::Pool *m_pPool; // r3
  bfx::Pool::Node *m_pNext; // r30
  bfx::Pool::Node *Node; // r3
  bfx::Island *Island; // r3
  bfx::Island *v29; // r22
  bfx::AreaFlags *v30; // r30
  int v31; // r15
  int v32; // r16
  int v33; // r21
  unsigned int v34; // r7
  bfx::List<bfx::NavProbeDisplayData *>::Node **i; // r11
  bfx::NavProbeDisplayData *v36; // r9
  bfx::List<bfx::NavProbeDisplayData *>::Node *m_pPrev; // r8
  bfx::List<bfx::NavProbeDisplayData *>::Node *v38; // r7
  bfx::NavProbeDisplayData *m_val; // r27
  bfx::Pool::Node **p_m_pUnused; // r10
  bfx::Vec3 *m_data; // r11
  int m_size; // r25
  int v43; // r24
  int v44; // r26
  bfx::NavProbeDisplayData **p_m_collided; // r28
  bfx::NavProbeDisplayData *v46; // r11
  bfx::Vec3 *v47; // r10
  bfx::NavProbeDisplayData *v48; // r29
  int v49; // r30
  int v50; // r10
  int v51; // r11
  unsigned int v52; // r9
  bfx::Island *v53; // r29
  bfx::HalfLink *j; // r30
  bfx::HalfLink *m_pTwin; // r11
  bfx::Area *m_pArea; // r11
  int v57; // [sp+8h] [-F8h]
  int v58; // [sp+Ch] [-F4h]
  int v59; // [sp+10h] [-F0h]
  int v60; // [sp+14h] [-ECh]
  bfx::NavProbeDisplayData *v61[2]; // [sp+50h] [-B0h] BYREF
  bfx::List<bfx::NavProbeDisplayData *> v62[14]; // [sp+58h] [-A8h] BYREF

  a14 = pStartArea;
  UnusedIslandNum = bfx::IslandGraph::GetUnusedIslandNum(this);
  v21 = UnusedIslandNum;
  if ( UnusedIslandNum == 0x1FFFF )
  {
    LODWORD(v22) = 0x1FFFF;
    HIDWORD(v22) = "ran out of available islands (limit = %d)\n";
    bfx::InternalWarning(fmt: v22, a2: v19, a3: v18, a4: v17, a5: v57, a6: v58, a7: v59, a8: v60);
    m_pEnd = this->m_availableIslandNumbers.m_pEnd;
    m_pPool = this->m_availableIslandNumbers.m_pPool;
    v61[0] = (bfx::NavProbeDisplayData *)&this->m_availableIslandNumbers;
    m_pNext = (bfx::Pool::Node *)m_pEnd->m_pNext;
    Node = bfx::Pool::GetNode(this: m_pPool);
    if ( Node != nullptr )
      Node->m_pNext = (bfx::Pool::Node *)0x1FFFF;
    Node[1].m_pNext = m_pNext;
    Node[2].m_pNext = m_pNext[2].m_pNext;
    m_pNext[2].m_pNext[1].m_pNext = Node;
    m_pNext[2].m_pNext = Node;
    --this->m_numIslandsInUse;
    return 0;
  }
  else
  {
    Island = bfx::IslandArray::GetIsland(this: &this->m_islandArray, islandNum: UnusedIslandNum);
    Island->m_obstacleBlockageFlags = 0;
    v29 = Island;
    Island->m_inUse = true;
    v30 = (bfx::AreaFlags *)&pStartArea[2];
    if ( ((int)pStartArea[2].m_pts.m_data & 0x20000000) != 0 )
      Island->m_obstacleBlockageFlags = LOWORD(pStartArea[2].m_pts.m_size);
    Island->m_areaUsageFlags = *(_DWORD *)&pStartArea[1].m_collided;
    v31 = HIWORD(pStartArea[2].m_pts.m_cap) & 0x7FF;
    bfx::List<bfx::Area *>::List<bfx::Area *>(
      this: (bfx::List<bfx::Island3D *> *)v62,
      numNodesPerPoolBlock: 0x64u,
      memTag: MEM_TEMP);
    bfx::List<bfx::Area *>::push_back(this: v62, val: &a14);
    v32 = (v21 << 7) & 0xFFFF80;
    v33 = 0x1FFFF;
    v34 = v30->m_flags1 & 0xFF00007F | v32;
    v61[0] = pStartArea + 2;
    v30->m_flags1 = v34;
    for ( i = &v62[0].m_pEnd->m_pNext; v62[0].m_pEnd->m_pNext != v62[0].m_pEnd; i = &v62[0].m_pEnd->m_pNext )
    {
      m_pPrev = (*i)->m_pPrev;
      v38 = (*i)->m_pNext;
      m_val = (*i)->m_val;
      v61[0] = (bfx::NavProbeDisplayData *)*i;
      v36 = v61[0];
      m_pPrev->m_pNext = v38;
      *(_DWORD *)(v36->m_pts.m_size + 8) = v36->m_pts.m_cap;
      p_m_pUnused = &v62[0].m_pPool->m_data.m_pUnused;
      v36->m_pts.m_data = (bfx::Vec3 *)v62[0].m_pPool->m_data.m_pUnused;
      *p_m_pUnused = (bfx::Pool::Node *)v36;
      m_data = m_val[2].m_pts.m_data;
      if ( ((unsigned int)m_data & 0x20000000) != 0 )
        m_size = (unsigned __int16)m_val[2].m_pts.m_size;
      else
        m_size = 0;
      v43 = *(_DWORD *)&m_val[1].m_collided;
      v44 = 0;
      if ( ((unsigned __int8)m_data & 0x7F) != 0 )
      {
        p_m_collided = (bfx::NavProbeDisplayData **)&m_val[2].m_collided;
        do
        {
          v46 = *p_m_collided;
          v61[0] = *p_m_collided;
          if ( v61[0] != nullptr )
          {
            v47 = v46[2].m_pts.m_data;
            v48 = v46 + 2;
            v49 = ((unsigned int)v47 >> 7) & 0x1FFFF;
            if ( v49 == 0x1FFFF )
            {
              if ( (HIWORD(v46[2].m_pts.m_cap) & 0x7FF) == v31 )
              {
                v50 = ((unsigned int)v47 & 0x20000000) != 0 ? (unsigned __int16)v46[2].m_pts.m_size : 0;
                v51 = *(_DWORD *)&v46[1].m_collided;
                if ( m_size == v50 && v43 == v51 )
                {
                  if ( ((unsigned int)p_m_collided[4] & 0x8000) != 0 )
                  {
                    if ( pOutsideLimitsAreas != nullptr )
                      bfx::Array<bfx::Portal *>::push_back(this: pOutsideLimitsAreas, val: (bfx::Space *const *)v61);
                  }
                  else
                  {
                    bfx::List<bfx::Area *>::push_back(this: v62, val: v61);
                    v52 = (int)v48->m_pts.m_data & 0xFF00007F | v32;
                    v61[0] = v48;
                    v48->m_pts.m_data = (bfx::Vec3 *)v52;
                  }
                }
              }
            }
            else if ( v49 != v21 && v49 != v33 )
            {
              v53 = bfx::IslandArray::GetIsland(
                      this: &this->m_islandArray,
                      islandNum: ((unsigned int)v47 >> 7) & 0x1FFFF);
              HIBYTE(bfx::Island::AddConnectionPairIfNeeded(this: v29, pAdjIsland: v53)->m_pAABB) = 1;
              v33 = v49;
              HIBYTE(bfx::Island::AddConnectionPairIfNeeded(this: v53, pAdjIsland: v29)->m_pAABB) = 1;
            }
          }
          ++v44;
          p_m_collided += 6;
        }
        while ( v44 < ((int)m_val[2].m_pts.m_data & 0x7F) );
      }
      for ( j = (bfx::HalfLink *)m_val->m_pts.m_cap; j != nullptr; j = j->m_pNext )
      {
        m_pTwin = j->m_pTwin;
        if ( m_pTwin != nullptr )
          m_pArea = m_pTwin->m_pArea;
        else
          m_pArea = nullptr;
        if ( ((m_pArea->m_flags.m_flags1 >> 7) & 0x1FFFF) != 0x1FFFF )
        {
          bfx::IslandGraph::UpdateForHalfLinkEnabled(this, pLink: j);
          bfx::IslandGraph::UpdateForHalfLinkEnabled(this, pLink: j->m_pTwin);
        }
      }
    }
    bfx::List<bfx::Area *>::~List<bfx::Area *>(this: (bfx::List<bfx::Island3D *> *)v62);
    return 1;
  }
}


// ========================================================================
// __unwind$25057
// EA  : 0x8327FDDC
// RVA : 0x0127FDDC
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

void _unwind_25057()
{
  int v0; // r12

  bfx::List<bfx::Area *>::~List<bfx::Area *>(this: (bfx::List<bfx::Island3D *> *)(v0 - 256 + 88));
}


// ========================================================================
// ?RemoveIsland@IslandGraph@bfx@@QAAXPAVArea@2@PAV?$Array@PAVArea@bfx@@@2@@Z
// EA  : 0x8327FE10
// RVA : 0x0127FE10
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

void __fastcall bfx::IslandGraph::RemoveIsland(
        bfx::IslandGraph *this,
        bfx::Space *pStartArea,
        bfx::Array<bfx::Space *> *pAreasTouchedOut,
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
  unsigned int m_w_low; // r11
  bfx::Space *p_m_rotWorldToSpace; // r29
  int v17; // r26
  __int64 v19; // r10
  __int64 v20; // r8
  __int64 v21; // r6
  __int64 v22; // r4
  bfx::Island *v23; // r27
  bfx::List<int>::Node *m_pNext; // r28
  bfx::Pool *m_pPool; // r3
  bfx::Pool::Node *Node; // r3
  int v27; // r23
  bfx::Space_vtbl *v28; // r4
  int m_size; // r11
  bfx::SpaceComponent **v30; // r8
  int v31; // r29
  int v32; // r27
  bfx::Space **v33; // r28
  bfx::Space *v34; // r11
  bfx::Space *v35; // r30
  bfx::Space_vtbl *v36; // r11
  int v37; // [sp+8h] [-B8h]
  int v38; // [sp+Ch] [-B4h]
  int v39; // [sp+10h] [-B0h]
  int v40; // [sp+14h] [-ACh]
  bfx::Space *v41[4]; // [sp+50h] [-70h] BYREF
  bfx::Array<bfx::SpaceComponent *> v42[6]; // [sp+60h] [-60h] BYREF

  m_w_low = LODWORD(pStartArea->m_rotWorldToSpace.m_w);
  a14 = pStartArea;
  p_m_rotWorldToSpace = (bfx::Space *)&pStartArea->m_rotWorldToSpace;
  v17 = (m_w_low >> 7) & 0x1FFFF;
  HIDWORD(v22) = bfx::IslandArray::GetIsland(this: &this->m_islandArray, islandNum: v17);
  v23 = (bfx::Island *)HIDWORD(v22);
  if ( HIDWORD(v22) != 0 )
  {
    *(_DWORD *)(HIDWORD(v22) + 20) = 0;
    *(_DWORD *)(HIDWORD(v22) + 16) = 0xFFFF;
    *(_BYTE *)(HIDWORD(v22) + 12) = 0;
    m_pNext = this->m_availableIslandNumbers.m_pEnd->m_pNext;
    m_pPool = this->m_availableIslandNumbers.m_pPool;
    v41[0] = (bfx::Space *)&this->m_availableIslandNumbers;
    Node = bfx::Pool::GetNode(this: m_pPool);
    if ( Node != nullptr )
      Node->m_pNext = (bfx::Pool::Node *)v17;
    Node[1].m_pNext = (bfx::Pool::Node *)m_pNext;
    Node[2].m_pNext = (bfx::Pool::Node *)m_pNext->m_pPrev;
    m_pNext->m_pPrev->m_pNext = (bfx::List<int>::Node *)Node;
    m_pNext->m_pPrev = (bfx::List<int>::Node *)Node;
    --this->m_numIslandsInUse;
    bfx::Island::RemoveAllForwardAndReverseConnections(this: v23);
    v27 = ((unsigned int)p_m_rotWorldToSpace->__vftable >> 7) & 0x1FFFF;
    memset(v42, 0, 12);
    v42[0].m_tag = MEM_TEMP;
    bfx::Array<bfx::Edge *>::expand_cap(this: v42, size: 100);
    bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)v42, val: &a14);
    v28 = p_m_rotWorldToSpace->__vftable;
    v41[0] = p_m_rotWorldToSpace;
    p_m_rotWorldToSpace->__vftable = (bfx::Space_vtbl *)((unsigned int)v28 | 0xFFFF80);
    if ( pAreasTouchedOut != nullptr )
      bfx::Array<bfx::Portal *>::push_back(this: pAreasTouchedOut, val: &a14);
    m_size = v42[0].m_size;
    while ( m_size != 0 )
    {
      v30 = &v42[0].m_data[m_size--];
      v42[0].m_size = m_size;
      v31 = 0;
      v32 = (int)*(v30 - 1);
      if ( (*(_DWORD *)(v32 + 40) & 0x7F) != 0 )
      {
        v33 = (bfx::Space **)(v32 + 56);
        do
        {
          v34 = *v33;
          v41[0] = *v33;
          if ( v41[0] != nullptr )
          {
            v35 = (bfx::Space *)&v34->m_rotWorldToSpace;
            if ( ((LODWORD(v34->m_rotWorldToSpace.m_w) >> 7) & 0x1FFFF) == v27 )
            {
              bfx::Array<bfx::Portal *>::push_back(this: (bfx::Array<bfx::Space *> *)v42, val: v41);
              v36 = v35->__vftable;
              v41[1] = v35;
              v35->__vftable = (bfx::Space_vtbl *)((unsigned int)v36 | 0xFFFF80);
              if ( pAreasTouchedOut != nullptr )
                bfx::Array<bfx::Portal *>::push_back(this: pAreasTouchedOut, val: v41);
            }
          }
          ++v31;
          v33 += 6;
        }
        while ( v31 < (*(_DWORD *)(v32 + 40) & 0x7F) );
        m_size = v42[0].m_size;
      }
    }
    if ( v42[0].m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v42[0].m_data);
  }
  else
  {
    HIDWORD(v22) = "Unexpected error in RemoveIsland(). Please report.\n";
    bfx::InternalWarning(fmt: v22, a2: v21, a3: v20, a4: v19, a5: v37, a6: v38, a7: v39, a8: v40);
  }
}


// ========================================================================
// __unwind$25358
// EA  : 0x83280004
// RVA : 0x01280004
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

void _unwind_25358()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 192 + 96));
}


// ========================================================================
// ?CreateIslandsForNavGraph@IslandGraph@bfx@@QAA_NPAVNavGraph@2@@Z
// EA  : 0x83280030
// RVA : 0x01280030
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

int __fastcall bfx::IslandGraph::CreateIslandsForNavGraph(
        bfx::IslandGraph *this,
        bfx::NavGraph *pNavGraph,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7)
{
  int v9; // r29
  char *m_pAreaBuf; // r31
  char *v11; // r28
  char v12; // r11
  bfx::NavProbeDisplayData *v13; // r4
  int v15; // [sp+8h] [-88h]
  int v16; // [sp+Ch] [-84h]
  int v17; // [sp+10h] [-80h]
  int v18; // [sp+14h] [-7Ch]
  int v19; // [sp+18h] [-78h]
  bfx::NavProbeDisplayData *v20; // [sp+1Ch] [-74h]

  v9 = 0;
  m_pAreaBuf = pNavGraph->m_pAreaBuf;
  v11 = &m_pAreaBuf[pNavGraph->m_pHeader->m_areaBytes];
  while ( 1 )
  {
    if ( m_pAreaBuf < v11 || (v12 = 1, v9 < pNavGraph->m_allocatedAreasOwned.m_size) )
      v12 = 0;
    if ( v12 != 0 )
      break;
    if ( m_pAreaBuf >= v11 )
      v13 = (bfx::NavProbeDisplayData *)pNavGraph->m_allocatedAreasOwned.m_data[v9];
    else
      v13 = (bfx::NavProbeDisplayData *)m_pAreaBuf;
    if ( ((int)v13[2].m_pts.m_data & 0xFFFF80) == 0xFFFF80
      && (unsigned __int8)bfx::IslandGraph::CreateIsland(
                            this,
                            pStartArea: v13,
                            pOutsideLimitsAreas: nullptr,
                            a4,
                            a5,
                            a6,
                            a7,
                            a8: 16777088,
                            a9: v15,
                            a10: v16,
                            a11: v17,
                            a12: v18,
                            a13: v19,
                            a14: v20) == 0 )
    {
      return 0;
    }
    if ( m_pAreaBuf >= v11 )
      ++v9;
    else
      m_pAreaBuf += 24 * (*((_DWORD *)m_pAreaBuf + 10) & 0x7F) + 56;
  }
  return 1;
}


// ========================================================================
// ?RemoveIslandsForNavGraph@IslandGraph@bfx@@QAAXPAVNavGraph@2@@Z
// EA  : 0x83280118
// RVA : 0x01280118
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

void __fastcall bfx::IslandGraph::RemoveIslandsForNavGraph(bfx::IslandGraph *this, bfx::NavGraph *pNavGraph)
{
  bfx::NavGraphHeader *m_pHeader; // r9
  int m_areaBytes; // r9
  int v5; // r7
  int v6; // r6
  bfx::Area *m_pCur; // r4
  char v8; // r11
  char *v9; // r11
  _DWORD *v10; // r11
  int v11; // r10
  int v12; // [sp+8h] [-88h]
  int v13; // [sp+Ch] [-84h]
  int v14; // [sp+10h] [-80h]
  int v15; // [sp+14h] [-7Ch]
  int v16; // [sp+18h] [-78h]
  bfx::Space *v17; // [sp+1Ch] [-74h]
  bfx::ActiveAreasCursor v18[2]; // [sp+50h] [-40h] BYREF

  m_pHeader = pNavGraph->m_pHeader;
  v18[0].m_staticCC.m_pCur = pNavGraph->m_pAreaBuf;
  m_areaBytes = m_pHeader->m_areaBytes;
  v18[0].m_staticCC.m_areasAllocatedInNavGraph = &pNavGraph->m_allocatedAreasOwned;
  v18[0].m_staticCC.m_cc.m_i = 0;
  v18[0].m_dynCC.m_pCurDynArea = nullptr;
  v18[0].m_dynCC.m_numDynAreas = 0;
  v18[0].m_staticCC.m_pEnd = &v18[0].m_staticCC.m_pCur[m_areaBytes];
  v18[0].m_dynCC.m_i = 0;
  v18[0].m_staticCC.m_cc.m_pArray = &pNavGraph->m_allocatedAreasOwned;
  bfx::ActiveAreasCursor::InitDynCC(this: v18);
  while ( 1 )
  {
    m_pCur = (bfx::Area *)v18[0].m_staticCC.m_pCur;
    if ( v18[0].m_staticCC.m_pCur < v18[0].m_staticCC.m_pEnd
      || (v8 = 1, v18[0].m_staticCC.m_cc.m_i < v18[0].m_staticCC.m_cc.m_pArray->m_size) )
    {
      v8 = 0;
    }
    if ( v8 != 0 )
      break;
    if ( v18[0].m_staticCC.m_pCur >= v18[0].m_staticCC.m_pEnd )
    {
      v5 = 4 * v18[0].m_staticCC.m_cc.m_i;
      v9 = (char *)v18[0].m_staticCC.m_cc.m_pArray->m_data[v18[0].m_staticCC.m_cc.m_i];
    }
    else
    {
      v9 = v18[0].m_staticCC.m_pCur;
    }
    v10 = *((_DWORD **)v9 + 1);
    if ( v10 != nullptr && *v10 != 0 )
    {
      m_pCur = v18[0].m_dynCC.m_pCurDynArea;
    }
    else if ( v18[0].m_staticCC.m_pCur >= v18[0].m_staticCC.m_pEnd )
    {
      m_pCur = v18[0].m_staticCC.m_cc.m_pArray->m_data[v18[0].m_staticCC.m_cc.m_i];
    }
    v11 = m_pCur->m_flags.m_flags1 & 0xFFFF80;
    if ( v11 != 16777088 )
      bfx::IslandGraph::RemoveIsland(
        this,
        pStartArea: (bfx::Space *)m_pCur,
        pAreasTouchedOut: nullptr,
        a4: v6,
        a5: v5,
        a6: (int)v18[0].m_staticCC.m_pEnd,
        a7: (int)v18[0].m_staticCC.m_cc.m_pArray,
        a8: v11,
        a9: v12,
        a10: v13,
        a11: v14,
        a12: v15,
        a13: v16,
        a14: v17);
    bfx::ActiveAreasCursor::operator++(this: v18);
  }
}


// ========================================================================
// ?InvalidateIslandsForAreas@IslandGraph@bfx@@QAAXABV?$Array@PAVArea@bfx@@@2@@Z
// EA  : 0x83280228
// RVA : 0x01280228
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

void __fastcall bfx::IslandGraph::InvalidateIslandsForAreas(
        bfx::IslandGraph *this,
        const bfx::Array<bfx::Area *> *areas,
        int a3,
        int a4,
        int a5,
        int a6)
{
  int v8; // r29
  int v9; // r31
  bfx::Area *v10; // r4
  int m_flags1; // r10
  int v12; // [sp+8h] [-78h]
  int v13; // [sp+Ch] [-74h]
  int v14; // [sp+10h] [-70h]
  int v15; // [sp+14h] [-6Ch]
  int v16; // [sp+18h] [-68h]
  bfx::Space *v17; // [sp+1Ch] [-64h]

  v8 = 0;
  if ( areas->m_size > 0 )
  {
    v9 = 0;
    do
    {
      v10 = areas->m_data[v9];
      m_flags1 = v10->m_flags.m_flags1;
      if ( (m_flags1 & 0xFFFF80) != 0xFFFF80 )
        bfx::IslandGraph::RemoveIsland(
          this,
          pStartArea: (bfx::Space *)v10,
          pAreasTouchedOut: nullptr,
          a4,
          a5,
          a6,
          a7: m_flags1 & 0xFFFF80,
          a8: m_flags1,
          a9: v12,
          a10: v13,
          a11: v14,
          a12: v15,
          a13: v16,
          a14: v17);
      ++v8;
      ++v9;
    }
    while ( v8 < areas->m_size );
  }
}


// ========================================================================
// ?FillSameValueSurfaceWithIslands@IslandGraph@bfx@@QAAXPAVArea@2@@Z
// EA  : 0x832802A0
// RVA : 0x012802A0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

void __fastcall bfx::IslandGraph::FillSameValueSurfaceWithIslands(
        bfx::IslandGraph *this,
        bfx::Space *pStartArea,
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
  int v16; // r10
  bfx::Space **v17; // r8
  bfx::NavProbeDisplayData *v18; // r4
  int m_data; // r7
  int v20; // [sp+8h] [-78h]
  int v21; // [sp+Ch] [-74h]
  int v22; // [sp+10h] [-70h]
  int v23; // [sp+14h] [-6Ch]
  int v24; // [sp+18h] [-68h]
  bfx::NavProbeDisplayData *v25; // [sp+1Ch] [-64h]
  bfx::Array<bfx::Space *> v26[3]; // [sp+50h] [-30h] BYREF

  a14 = pStartArea;
  memset(v26, 0, 12);
  v26[0].m_tag = MEM_TEMP;
  bfx::Array<bfx::Portal *>::push_back(this: v26, val: &a14);
  m_size = v26[0].m_size;
  while ( m_size != 0 )
  {
    v16 = 4 * m_size;
    v17 = &v26[0].m_data[m_size--];
    v26[0].m_size = m_size;
    v18 = (bfx::NavProbeDisplayData *)*(v17 - 1);
    m_data = (int)v18[2].m_pts.m_data;
    if ( (m_data & 0xFFFF80) == 0xFFFF80 )
    {
      bfx::IslandGraph::CreateIsland(
        this,
        pStartArea: v18,
        pOutsideLimitsAreas: v26,
        a4: 16777088,
        a5: m_data,
        a6: (int)v17,
        a7: (int)v26[0].m_data,
        a8: v16,
        a9: v20,
        a10: v21,
        a11: v22,
        a12: v23,
        a13: v24,
        a14: v25);
      m_size = v26[0].m_size;
    }
  }
  if ( v26[0].m_data != nullptr )
    bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v26[0].m_data);
}


// ========================================================================
// __unwind$25853
// EA  : 0x83280354
// RVA : 0x01280354
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

void _unwind_25853()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 128 + 80));
}


// ========================================================================
// ?CreateIslandsForAreas@IslandGraph@bfx@@QAAXABV?$Array@PAVArea@bfx@@@2@@Z
// EA  : 0x83280380
// RVA : 0x01280380
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

void __fastcall bfx::IslandGraph::CreateIslandsForAreas(
        bfx::IslandGraph *this,
        const bfx::Array<bfx::Area *> *areas,
        int a3,
        int a4,
        int a5,
        int a6)
{
  int v8; // r29
  int v9; // r31
  bfx::Area *v10; // r4
  int m_flags1; // r10
  int v12; // [sp+8h] [-78h]
  int v13; // [sp+Ch] [-74h]
  int v14; // [sp+10h] [-70h]
  int v15; // [sp+14h] [-6Ch]
  int v16; // [sp+18h] [-68h]
  bfx::Space *v17; // [sp+1Ch] [-64h]

  v8 = 0;
  if ( areas->m_size > 0 )
  {
    v9 = 0;
    do
    {
      v10 = areas->m_data[v9];
      m_flags1 = v10->m_flags.m_flags1;
      if ( (m_flags1 & 0xFFFF80) == 0xFFFF80 )
        bfx::IslandGraph::FillSameValueSurfaceWithIslands(
          this,
          pStartArea: (bfx::Space *)v10,
          a3,
          a4,
          a5,
          a6,
          a7: 16777088,
          a8: m_flags1,
          a9: v12,
          a10: v13,
          a11: v14,
          a12: v15,
          a13: v16,
          a14: v17);
      ++v8;
      ++v9;
    }
    while ( v8 < areas->m_size );
  }
}


// ========================================================================
// ?RefreshIslandsTouched@bfx@@YAXPAVPlanner@1@AAVIslandsTouchedArray@1@@Z
// EA  : 0x832803F0
// RVA : 0x012803F0
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

void __fastcall bfx::RefreshIslandsTouched(bfx::Planner *pPlanner, bfx::IslandsTouchedArray *islandsTouchedArray)
{
  unsigned int v2; // r31
  bfx::IslandsTouchedArray *v4; // r28
  bfx::NavLayer **m_layers; // r29
  bfx::NavLayer *v6; // r30
  char v7; // r11
  bfx::ArrayMap<bfx::Area *> *ArrayMapForLayer; // r3

  v2 = 0;
  v4 = islandsTouchedArray;
  m_layers = pPlanner->m_layers;
  do
  {
    v6 = *m_layers;
    if ( *m_layers != nullptr )
    {
      if ( v4->m_pIslandsTouched[0] == nullptr || (v7 = 0, v4->m_pIslandsTouched[0]->m_array.m_size == 0) )
        v7 = 1;
      if ( v7 == 0 )
      {
        ArrayMapForLayer = bfx::IslandsTouchedArray::GetArrayMapForLayer(this: islandsTouchedArray, layerNum: v2);
        bfx::IslandGraph::RefreshLinkData(this: v6->m_pIslandGraph, islandsTouched: ArrayMapForLayer);
      }
    }
    ++v2;
    ++m_layers;
    v4 = (bfx::IslandsTouchedArray *)((char *)v4 + 4);
  }
  while ( v2 < 0x20 );
}


// ========================================================================
// ??1IslandsTouchedArray@bfx@@QAA@XZ
// EA  : 0x83280480
// RVA : 0x01280480
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

void __fastcall bfx::IslandsTouchedArray::~IslandsTouchedArray(bfx::IslandsTouchedArray *this)
{
  int i; // r27
  bfx::ArrayMap<bfx::Area *> *v3; // r31
  char *m_data; // r4

  for ( i = 32; i != 0; --i )
  {
    v3 = this->m_pIslandsTouched[0];
    if ( this->m_pIslandsTouched[0] != nullptr )
    {
      m_data = (char *)v3->m_array.m_data;
      v3->m_array.m_size = 0;
      if ( m_data != nullptr )
      {
        bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: m_data);
        v3->m_array.m_data = nullptr;
      }
      v3->m_array.m_cap = 0;
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v3);
      this->m_pIslandsTouched[0] = nullptr;
    }
    this = (bfx::IslandsTouchedArray *)((char *)this + 4);
  }
}


// ========================================================================
// ?UpdateForLinkDisabledOrModified@IslandGraph@bfx@@QAAXPAVHalfLink@2@@Z
// EA  : 0x83280500
// RVA : 0x01280500
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

void __fastcall bfx::IslandGraph::UpdateForLinkDisabledOrModified(bfx::IslandGraph *this, bfx::HalfLink *pLink)
{
  bfx::HalfLink *m_pTwin; // r10
  bfx::VolumeGraph *m_pArea; // r5
  bfx::VolumeGraph *v5; // r29
  unsigned int v6; // r4
  unsigned int v7; // r30
  bfx::ArrayMap<bfx::Area *> v8[4]; // [sp+50h] [-40h] BYREF

  m_pTwin = pLink->m_pTwin;
  m_pArea = (bfx::VolumeGraph *)pLink->m_pArea;
  if ( m_pTwin != nullptr )
    v5 = (bfx::VolumeGraph *)m_pTwin->m_pArea;
  else
    v5 = nullptr;
  v6 = ((unsigned int)m_pArea->m_graphPortals.m_cap >> 7) & 0x1FFFF;
  v7 = ((unsigned int)v5->m_graphPortals.m_cap >> 7) & 0x1FFFF;
  if ( v6 != v7 )
  {
    memset(v8, 0, 12);
    v8[0].m_array.m_tag = MEM_TEMP;
    bfx::ArrayMap<bfx::Repulsor3D *>::add(this: (bfx::ArrayMap<bfx::VolumeGraph *> *)v8, key: v6, val: m_pArea);
    bfx::ArrayMap<bfx::Repulsor3D *>::add(this: (bfx::ArrayMap<bfx::VolumeGraph *> *)v8, key: v7, val: v5);
    bfx::IslandGraph::RefreshLinkData(this, islandsTouched: v8);
    if ( v8[0].m_array.m_data != nullptr )
      bfx::MemoryManager::Free(this: bfx::g_pCurInstance->m_pMemoryManager, ptr: (char *)v8[0].m_array.m_data);
  }
}


// ========================================================================
// __unwind$26060
// EA  : 0x832805A8
// RVA : 0x012805A8
// PDB : w:\tech5\libs\navpower\src\bfxplanner\bfxisland.cpp
// ========================================================================

void _unwind_26060()
{
  int v0; // r12

  bfx::Array<bfx::Volume *>::~Array<bfx::Volume *>(this: (bfx::Array<bfx::SpaceComponent *> *)(v0 - 144 + 80));
}

